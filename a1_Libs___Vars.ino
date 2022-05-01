// *** libraries***
#include <Wire.h>          // Libs for I2C
#if defined (BATTERY_SOURCE_IS_INA)
#include <INA.h> // Zanshin INA Library
#endif
#include <ArduinoJson.h>   // Libs for Webscraping
#if defined (UDP)
#include <WiFiUdp.h>
#endif
#if defined (OTA)
#include <ArduinoOTA.h>
#endif
#include <ESP8266WiFi.h>   // default from Espressif
#include <ESP8266HTTPClient.h>
#include <TZ.h>            // default from Espressif
#include <FS.h>
#if defined (THINGER)
#include <ThingerESP8266.h>
//#include <ThingerConsole.h>
#endif
//#include <EEPROM.h>

// ESP8266 Lolin / D1 /Witty (see definitions for other boards in Parked code)
#define SCL 5           // D1 GPIO05 for I2C (Wire) System Clock
#define SDA 4           // D2 GPIO04 for I2C (Wire) System Data
#define RST 0           // GPIO0
#define PUSHBUTTON D2   // GPIO04
#define RELAY      D1   // GPIO05
#define STDLED     D4   // GPIO02 (& Console2 TX)
#define REDLED     D8   // GPIO15
#define GRNLED     D6   // GPIO12
#define BLULED     D7   // GPIO13

// Concatenate URLs
#define OPEN_WEATHER_MAP_URL  "http://api.openweathermap.org/data/2.5/weather?id=" OPEN_WEATHER_MAP_LOCATION_ID "&appid=" OPEN_WEATHER_MAP_APP_ID "&units=" OPEN_WEATHER_MAP_UNITS "&lang="  OPEN_WEATHER_MAP_LANGUAGE
//#define OPEN_WEATHER_MAP_URL   "http://api.openweathermap.org/data/2.5/weather?id=2928810&appid=208085abb5a3859d1e32341d6e1f9079&lang=de&units=metric"
#define DFLD_URL "http://api.dfld.de/noise/dfld.de/" DFLD_REGION "/" DFLD_STATION 
//#define DFLD_URL "http://api.dfld.de/noise/dfld.de/004/020"

//***Variables for Time***
tm*        timeinfo;                 //localtime returns a pointer to a tm struct static int Second;
time_t     Epoch;
time_t     now;
byte Second;
long SecondOfDay;
byte Minute;
byte Hour;
byte Day;
byte Month;
unsigned int Year;
byte Weekday;
char DayName[12];
char MonthName[12];
char Time[10];
char Date[12];
byte slice;
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
boolean stopAK;
boolean serialDay;
boolean serialHur;
boolean serialMin;
boolean serialSec;
boolean serialNAT;
boolean trigNAT;

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
float internal_resistance = 0;
float percent_charged = 50;
float voltageAt2355h ;
float voltageDelta ;
float currentInt = 0;
int   nCurrent;
float AhBat[31];

struct battery {
float current ;
float voltage ;
float power = 0;
} battery;
char batteryPayload[sizeof(battery)];  //  Array of characters as image of the structure for UDP xmit/rcv

//Weather
float outdoor_temperature;
float outdoor_humidity;
float outdoor_pressure;
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
}sound;
char soundPayload[sizeof(sound)];  //  Array of characters as image of the structure for UDP xmit/rcv
float   A0dB60;
float   A0dB6S;
byte    A0dBArray[3610];  // one hour of A0dBAK values
float   A0dBSum6S;
float   A0dBSumExp60min;
float   A0dBSumExp1min;
float   A0dBLeq1min;
float   A0dBMin1min;
float   A0dBMax1min;

byte    nA0dB6S;
int     corrdB;
int     A094;
int     A047;
float   leq[33];         // 0..23=hour, 25=current, 26=Lequ 24h, 27= LeqDay, 28=LeqNight, 29=Lden, 30 =L22-24h ,31=Leq Events over Thresh, 32=Leq Events by max-10dB

// Number above threshold
float   maxLevelNAT;
byte    listeningTimer;
byte    minExceedingTimer;
byte    maxExceedingTimer;

unsigned int  aboveThreshDuration;
float   aboveThreshLEq;       //Equivalent sound exposure  level above threshold
float   aboveThreshLE;        //Single  event (1s) sound  exposure  level above threshold
float   aboveThreshLEint;     //Single  event sound  exposure integration level above threshold

unsigned int  less10dBDuration;
float   less10dBLEq;          //Equivalent sound  exposure  level measured from Lmax-10dB
float   less10dBLE;           //Single  event  (1s) sound  exposure  level measured from Lmax-10dB
float   less10dBLEint;        //Single  event  integration  level measured from Lmax-10dB

float   peakValue;
char    state;
String  peakTime;
float   EVENT[MAX_EXCEEDANCE_TIME];     // flashback record of an event
byte    NAT[31];        // Number Above Treshold 0..23=hour 25=current event 26=Nat24h 27= Daytime 28= Nighttime, 


//Sound level from URL
String  JSONpayload;
byte    wifiConnectCounter;

//*** Buffers ***
static char charbuff[80];    //Char buffer for many functions
