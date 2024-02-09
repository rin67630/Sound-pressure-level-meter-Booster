#define THINGER_DEVICE HOST_NAME

// *** Personalization ***
#include "Credentials.h"
#include "Options.h"

// *** libraries***  (including with <> takes by priority global files, including with "" takes local files).

#include <ArduinoJson.h>   // Libs for Webscraping
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <ESP8266WiFi.h>   // default from Espressif
#include <ESP8266HTTPClient.h>
#include <TZ.h>            // default from Espressif
//#include <FS.h>
//#include <EEPROM.h>

#if defined(WEATHER_SOURCE_IS_BME680)
#include <Adafruit_Sensor.h>
#include "Adafruit_BME680.h"
#define SEALEVELPRESSURE_HPA (1013.25)
Adafruit_BME680 bme;
#endif

#if defined(TELNET)
#include <TelnetStream.h>     // from Arduino Library (Juraj Andrassy).
#endif

#if defined(THINGER)
#include <ThingerESP8266.h>
#endif

#if defined(BATTERY_SOURCE_IS_INA)
#include <Wire.h>          // Libs for I2C
#include <INA.h>           // Zanshin INA Library
#endif

#ifndef DISPLAY_IS_NONE
#include "SSD1306Wire.h"  // from https://github.com/ThingPulse/esp8266-oled-ssd1306/
#endif
#ifdef DISPLAY_IS_OLED64x48
SSD1306Wire display(0x3c, SDA, SCL, GEOMETRY_64_48 ); // WEMOS OLED 64*48 shield
#endif
#ifdef DISPLAY_IS_OLED128x64
SSD1306Wire display(0x3c, SDA, SCL);                  //OLED 128*64 soldered
#endif



// ESP8266 Lolin / D1 /Witty (see definitions for other boards in Parked code)
#define SCL 5           // D1 GPIO05 for I2C (Wire) System Clock
#define SDA 4           // D2 GPIO04 for I2C (Wire) System Data
#define RST 0           // GPIO00
#define PUSHBUTTON D2   // GPIO04
// analogWrite(MPPT,[0..255])
#define STDLED     D4   // GPIO02 (& Console2 TX)
#define REDLED     D8   // GPIO15
#define GRNLED     D6   // GPIO12
#define BLULED     D7   // GPIO13

// Concatenate URLs
#define OPEN_WEATHER_MAP_URL  "http://api.openweathermap.org/data/2.5/weather?id=" OPEN_WEATHER_MAP_LOCATION_ID "&appid=" OPEN_WEATHER_MAP_APP_ID "&units=" OPEN_WEATHER_MAP_UNITS "&lang="  OPEN_WEATHER_MAP_LANGUAGE
//#define OPEN_WEATHER_MAP_URL   "http://api.openweathermap.org/data/2.5/weather?id=2928810&appid=208085abb5a3859d1e32341d6e1f9079&lang=de&units=metric"
#define DFLD_URL "http://api.dfld.de/noise/dfld.de/" DFLD_REGION "/" DFLD_STATION

//***Variables for Time***
tm*        timeinfo;                 //localtime returns a pointer to a tm struct static int Second;
time_t     Epoch;
time_t     now;
byte Second;
long SecondOfDay;
long MillisMem;
long MillisMem2;
byte Minute;
byte Hour;
byte Day;
byte Month;
unsigned int Year;
byte Weekday;
unsigned int RunMillis[28];  // keep trace of consumed time
unsigned int GracePause = 0;
char DayName[16];
char MonthName[16];
char Time[16];
char Date[16];

byte    slice;
boolean Each6S;
boolean NewMinute;
boolean MinuteExpiring;
boolean NewHour;
boolean HourExpiring;
boolean NewDay;
boolean DayExpiring;

// ***Variables for Menu***
byte    inbyte;
byte    displayPage;
byte    displaySubPage;
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
boolean trigEvent;

static IPAddress ip;
static IPAddress remip;

//***Payload Variables***
// INA226
byte devicesFound =      0; ///< Number of INAs found
float ina_current;
float ina_voltage;
float current ;
float voltage ;
float delta_current;
float delta_voltage;
float ina_shunt;
float ina_power;
float percent_charged = 50;
float voltageAt0H ;
float voltageDelta ;
float currentInt = 0;
int   nCurrent;
float AhBat[33];


struct battery {
  float current ;
  float voltage ;
  float power = 0;
  float ohm   = 0;
  float panel ;
} battery;
char batteryPayload[sizeof(battery)];  //  Array of characters as image of the structure for UDP xmit/rcv


//Weather
float temperature;
float humidity;
float pressure;
float wind_speed;
int   wind_direction;
int   cloudiness;
String weather_summary;
long  sunrise;
long  sunset;

// Sound level
int     A0Raw;
long    A0Inst;
float   A0dBAvg;
struct  sound {
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
char soundPayload[sizeof(sound)];  //  Array of characters as image of the structure for UDP xmit/rcv

float   A0dB60;
float   A0dB6S;
//byte    A0dBArray[3610];  // one hour of A0dBAK values
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

// Number above threshold
float   maxLevelNAT;
byte    listeningTimer;
byte    minExceedingTimer;
byte    maxExceedingTimer;


// Max Level Classes
unsigned int maxLevelClass[41];       // statistic of max overflights by dB Class ([0]=60dB, [39]=99dB)
unsigned int maxLevelClassy[41];
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
char    state;
String  peakTime;
float   Event[MAX_EXCEEDANCE_TIME + 1];     // flashback record of an event
float   Eventoverflow;
byte    NAT[33];        // Number Above Treshold 0..23=hour 25=current event 26=0..24h 27= Daytime 28= Nighttime,
byte    NATy[33]; 

//Sound level from URL
String  JSONpayload;
byte    wifiConnectCounter;

//*** Buffers ***
static char charbuff[120];    //Char buffer for many functions
