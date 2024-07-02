// *** Personalization ***
#include "Credentials.h"
#include "Config.h"
// *** libraries***  (including with <> takes by priority global files, including with "" takes local files).
#include <Wire.h>
#include <ArduinoOTA.h>
#include "time.h"  // built-in
#include "TZ.h"
//#include <FS.h>
#include <EEPROM.h>
//#include "InterpolationLib.h"

#if defined(ARDUINO_ARCH_ESP8266)
#include <ESP8266WiFi.h>   // default from Espressif
#include <ESP8266HTTPClient.h>
#endif

#include <ArduinoJson.h>   // Libs for Webscraping

#if defined(WEATHER_SOURCE_IS_BME680)
#include <Adafruit_Sensor.h>
#include "Adafruit_BME680.h"
#define SEALEVELPRESSURE_HPA (1013.25)
Adafruit_BME680 bme;
#endif

#if defined(TERM_IS_TELNET)
#include <TelnetStream.h>     // from Arduino Library (Juraj Andrassy).
#endif

#if defined(DASHBRD_IS_THINGER)
#include <ThingerESP8266.h>
#endif

#if defined(BATTERY_SOURCE_IS_INA)
#include <INA.h>           // Zanshin INA Library
#endif

#ifdef SCREEN_IS_64x48
#include <SSD1306.h>                              // from https://github.com/ThingPulse/esp8266-oled-ssd1306/
SSD1306 display(0x3c, SDA, SCL, GEOMETRY_64_48);  // WEMOS OLED 64*48 shield
#endif

#ifdef SCREEN_IS_128x64
#include <SSD1306.h>                               // from https://github.com/ThingPulse/esp8266-oled-ssd1306/
SSD1306 display(0x3c, SDA, SCL, GEOMETRY_128_64);  //OLED 128*64 soldered
#endif

// ESP8266 Lolin / D1 /Witty (see definitions for other boards in Parked code)
#define SCL        5    // D1 GPIO05 for I2C (Wire) System Clock
#define SDA        4    // D2 GPIO04 for I2C (Wire) System Data
#define RST        0    // GPIO00
#define PUSHBUTTON D2   // GPIO04
//#define LED_BUILTIN     D4   // GPIO02 (& Console1 TX)
#define REDLED     D8   // GPIO15
#define GRNLED     D6   // GPIO12
#define BLULED     D7   // GPIO13

// Adjust A0 range to sound pressure meter used
#ifdef SP_METER_IS_GM1358
  #define Ao94                 1001                    // Input linear 0..1V  (A0 direct on ESP module)
  #define Ao47                 500                     // Input linear 0..1V
#endif

#ifdef SP_METER_IS_AK_MODULBUS
  #define Ao94                 747                    // Input  0..3V         (A0 over integrated divider from boards' input)
  #define Ao47                 461                    // Input with offset 0..3V
#endif

#ifdef SP_METER_IS_GRAVITY
  #define Ao94                 615                    // Input  0..3V         (A0 over integrated divider from boards' input)
  #define Ao47                 307                    // Input linear 0..3V
#endif

#ifdef SP_METER_IS_NONE
  #define Ao94                 1                      //  Dummy, no input required
  #define Ao47                 1                      //  Dummy, no input required
#endif

#if defined (TERM_IS_TELNET)
//*** Aliases for serial communication***
#define Console0 TelnetStream  // Port for user inputs
#define Console1 TelnetStream  // Port for user outputs 
#else
#define Console0 Serial        // Port for user inputs
#define Console1 Serial        // Port for user outputs 
#endif

// Concatenate URLs
#define OPEN_WEATHER_MAP_URL  "http://api.openweathermap.org/data/2.5/weather?id=" OPEN_WEATHER_MAP_LOCATION_ID "&appid=" OPEN_WEATHER_MAP_APP_ID "&units=" OPEN_WEATHER_MAP_UNITS "&lang="  OPEN_WEATHER_MAP_LANGUAGE
//#define OPEN_WEATHER_MAP_URL   "http://api.openweathermap.org/data/2.5/weather?id=2928810&appid=208085abb5a3859d1e32341d6e1f9079&lang=de&units=metric"
#define DFLD_URL "http://api.dfld.de/noise/dfld.de/" DFLD_REGION "/" DFLD_STATION



//***Variables for Time***
tm*        timeinfo;                 //localtime returns a pointer to a tm struct static int Second;
time_t     Epoch;
time_t     now;
byte       Second;
long       SecondOfDay;
byte       Minute;
byte       Hour;
byte       Day;
byte       Month;
unsigned int Year;
byte       Weekday;
unsigned int RunMillis[28];  // keep trace of consumed time
long      MillisMem;
long      thingHandleTime;
unsigned int GracePause = 0;

char      DayName[16];
char      MonthName[16];
char      Time[16];
char      Date[16];

byte    slice;
boolean Each6S;
boolean NewMinute;
boolean MinuteExpiring;
boolean NewHour;
boolean HourExpiring;
boolean NewDay;
boolean DayExpiring;

// ***Variables for Menu***
byte    serialReceived;
byte    displayPage;
byte    serialPage;
byte    serialPageMem;
byte    wirelessPage;
boolean stopAK;          //Preventing outpot to DFLD While serlan handshaking
boolean serialDay;
boolean serialHur;
boolean serialMin;
boolean serialSec;
boolean serialNAT;
boolean thingerNAT;
boolean TrigEvent;

static IPAddress ip;
static IPAddress remip;

struct payload    //***Battery Power Supply Values from another ESP running Victron/SmartShunt***
{
  float BatV;     // V   Battery voltage, V
  float BatV1;    // V   Battery voltage, V  (Double or half Voltage)
  float BatI;     // I   Battery current, A
  float BatW;     // W BatV*BatI

  float PanV;     // VPV Panel voltage,   V
  float PanI;     // PanW/PanV
  float PanW;     // PPV Panel power,     W
  float LodI;     // IL  Load Current     A
  float LodW;     //  BatI*BatV
  float IOhm;     //  dV / dI
  float BatPoC;   // Percent of charge
  int   ChSt;       // CS  Charge state (not POC), 0 to 9
  int   Err;        // ERR Error code, 0 to 119
  boolean LodOn;  // LOAD ON Load output state, ON/OFF
} payload;
unsigned char UDPBatPayload[sizeof(payload)]; //  Array of characters as image of the structure for UDP xmit/rcv (Sizeof = 56 bytes).

// Sound level   
int     A0Raw;
long    A0Inst;
float   A0dBAvg;

struct  sound   //***Sound Level Values grouped in a structure to be received from/transmitted to another ESP ***
{
  float A0dBFast;
  float A0dBMin;
  float A0dBBgr;
  float A0dBMax;
  float A0dBSlow;
  float A0dBImpulse;
  byte  A0dBAK;
  char  fResponse = 'A';
  char  tResponse = 'S';
} sound;
char UDPSoundPayload[sizeof(sound)];  //  Array of characters as image of the structure for UDP xmit/rcv

//Weather
float   temperature;
float   humidity;
float   pressure;
float   wind_speed;
int     wind_direction;
int     cloudiness;
String  weather_summary;
long    sunrise;
long    sunset;

float   A0dB60;
float   A0dB6S;
float   A0dBSum6S;
float   A0dBSumExp60min;
float   A0dBSumExp1min;
float   A0dBLeq1min;
float   A0dBMin1min;
float   A0dBMax1min;
float   A0dBtrend  ;         //Graphical max when event recorded
byte    nA0dB6S;
int     corrdB;
int     A094;
int     A047;
float   leq[33];         // 0..23=hour, 25=current, 26=0..24h, 27= Daytime, 28=Nighttime, 29=Lden, 30 =L22-24h ,31=Leq Events over Thresh, 32=Leq Events by max-10dB
byte    NAT[33];         // Number Above Treshold 0..23=hour 25=current event 26=0..24h 27= Daytime 28= Nighttime,
float   maxLevelNAT;     // Number above threshold
byte    listeningTimer;
byte    minExceedingTimer;
byte    maxExceedingTimer;


// Max Level Classes
unsigned int maxLevelClass[41];       // statistic of max overflights by dB Class ([0]=60dB, [39]=99dB)
unsigned int maxLevelClassYear[41];
unsigned int maxLevelClassMonth[41];  //

// Above Threshholds
unsigned int  aboveThreshDuration;
float   aboveThreshLEq;       //Equivalent sound exposure  level above threshold
float   aboveThreshLE;        //Single  event (1s) sound  exposure  level above threshold
float   aboveThreshLEint;     //Single  event sound  exposure integration level above threshold

unsigned int  less10dBDuration;
float   less10dBLEq;          //Equivalent sound  exposure  level measured from Lmax-10dB
float   less10dBLE;           //Single  event  (1s) sound  exposure  level measured from Lmax-10dB
float   less10dBLEint;        //Single  event  integration  level measured from Lmax-10dB

// Event analysis
float   eventPeak;         //peak of qualifying event (according to retrospective analysis)
float   soundEnergy;       // delogarithmed soundEnergy
byte    eventDuration;     // counter for EventDuration
float   peakValue;         // peak of current signal
char    OFD_state;         // OverFleightDetection State
String  peakTime;
float   Event[MAX_EXCEEDANCE_TIME + 2];     // flashback record of an event
float   Eventoverflow;


//Data from URL
String  JSONpayload;
byte    wifiConnectCounter;

//*** Buffers ***
static char charbuff[120];    //Char buffer for many functions
