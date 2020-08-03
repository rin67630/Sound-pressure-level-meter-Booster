// *** libraries***
#include <Wire.h> // Libs for INA 226
#include <INA.h>  // Zanshin INA Library
#include <ArduinoJson.h> // Libs for Webscraping
#include <TridentTD_OpenWeather.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <ESP8266WiFi.h>  // default from Espressif
#include <ESP8266HTTPClient.h>
#include <TZ.h>           // default from Espressif
#include <Base64.h>
#if defined(THINGER)
#include <ThingerESP8266.h>
#endif

// ESP8266 Lolin (see definitions for other boards in Parked code)
#define SCL 5  // GPIO for I2C (Wire) System Clock
#define SDA 4  // GPIO for I2C (Wire) System Data
#define RST 0  // GPIO0
#define RELAY 27

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
byte inbyte;
byte displayPage;
byte displaySubPage;
byte serialPage;
byte serialPageMem;
byte wirelessPage;
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
float delta_current;
float delta_voltage;
float ina_shunt;
float ina_power;
float internal_resistance = 0;
float percent_charged = 100;
float voltageAt4h ;
float voltageDelta ;
float currentInt = 0;
int  nCurrent;
int   ind = 0;
float mAhBat[30];

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
float outdoor_wind_speed;
float outdoor_wind_direction;
float outdoor_noise;
String weather_summary;
String sunrise;
String sunset;

// Sound level
int   A0Raw;
long  A0Inst;
float A0dBAvg;
struct sound {
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
char soundPayload64[2*sizeof(sound)];  //  Array of characters as image of the structure for UDP xmit/rcv

float A0dB60;
float A0dB6S;

byte  A0dBArray[3610];  // one hour of A0dBAK values
float A0dBSum6S;
float A0dBSumExp60min;
float A0dBSumExp1min;
float A0dBLeq1min;
float A0dBMin1min;
float A0dBMax1min;
byte  nA0dB6S;
byte  corrdB;
int   A094;
int   A047;
boolean sendNoise;
boolean writeNoiseBucket;
float leq[30];         // 0..23=hour, 25=current, 26=Lequ 24h, 27= LeqDay, 28=LeqNight, 29=Lden

// Mumber above threshold

float maxLevelNAT;
byte  listeningTimer;
byte  minExceedingTimer;
byte  maxExceedingTimer;

unsigned int  aboveThreshDuration;
float aboveThreshLEq;
unsigned int  less10dBDuration;
float less10dBLEq;
float peakValue;
char state;
String peakTime;
float  EVENT[MAX_EXCEEDANCE_TIME];     // flashback record of an event
byte   NAT[30];        // Number Above Treshold 0..23=hour 25=current event 26=Nat24h
//byte   TAT[30];         // Time Above Treshold   0..23=hour 25=current event 26=TAT24h

//Sound level from URL
//#define DFLDjsonURL "http://api.dfld.de/noise/dfld.de/001/161"  //Frankfurt Offenbach 1
#define DFLDjsonURL "http://api.dfld.de/noise/dfld.de/004/027"
String JSONpayload;
byte wifiConnectCounter;

//*** Buffers ***
static char charbuff[80];    //Char buffer for many functions
