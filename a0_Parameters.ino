
// ***Functional options***
//#define THINGER
//#define BUCKET
//#define AKOUT
//#define UDPOUT
//#define BATTERY_MONITORING
#define GRAB_WEATHER
#define SOUNDSOURCE_UDP   //_ANAIN _URL _UDP
//#define DFLDjsonURL "http://api.dfld.de/noise/dfld.de/004/027"  //"http://api.dfld.de/noise/dfld.de/001/161"  //Frankfurt Offenbach 1


#define HOST_NAME   "DFLD20_04_CLI"         // "ESP_LP" "ESP_HP" "ESP_DEV" "ESP_NOISE" "GM1358" "DFLD20_04_CLI"
#define wifiMaxTries 30
#define wifiRepeatInterval 360

#define UDP_PORT   4211
#define UDP_TARGET "192.168.188.75"  //

#define THINGER_USERNAME    "Dachschaden1"     // "rin6763o" "rin67631" "Dachschaden1"
#define THINGER_CREDENTIALS "K%InK3?W3fBw"  // "Idd1YZtZ9Hv9" "regnihT" "K%InK3?W3fBw"

// ***Time zones***
#define NTP_SERVER "de.pool.ntp.org"
#define MYTZ TZ_Europe_Paris
#define TZ   1                              // (utc+) TZ in hours

// ***Weather Credentials***
String OPEN_WEATHER_MAP_APP_ID =      "208085abb5a3859d1e32341d6e1f9079";
String OPEN_WEATHER_MAP_LOCATION_ID = "2928810";
String OPEN_WEATHER_MAP_LANGUAGE =    "de";
boolean IS_METRIC =                   true;

// ***Acoustical parameters***
#define Ao94 1024  // 747  for AK with offset and 2,5v  1050 for linear 0..1V
#define Ao47 530   // 458  for AK with offset and 2,5v  550 for linear 0..1V

#define  EVENT_THRESHOLD_LEVEL 52       // Begin of Exceedance level
#define  MEASUREMENT_THRESHOLD_LEVEL 48 // Begin of measurement level
#define  MIN_EXCEEDANCE_TIME 15         // Minimum duration of an event
#define  MAX_EXCEEDANCE_TIME 60         // Maximum duration of an event
#define  LISTENING_TIME 50              // mimimum time between events


// ***Electrical parameters***
//#define DEVICES_FOUND INA.begin(3, 40000) //3A Max, 40mOhm Shunt
#define SHUNT    40000   // 16666 = 0,1 Ohm +// 0,02Ohm  or 40000
#define AMPERE   3        // 10 or 5
#define SERIAL_SPEED 9600  //9600  115200 230400
#define MIN_VOLT  9.6      // 11.8  9.6
#define MAX_VOLT 12.8     // 14.2  12.8
#define MIN_AMP  -0.8
#define MAX_AMP  +0.8
#define MIN_WATT -1
#define MAX_WATT +8
