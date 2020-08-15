#define HOST_NAME "GITHUB"

// ***Functional Configuration***
#define WEATHER_SOURCE_URL  //_URL _NONE (UDP planned)
#define BATTERY_SOURCE_UDP  //_INA _UDP _NONE
#define SOUND_SOURCE_UDP    //_ANAIN _URL _UDP _NONE
//#define DFLDjsonURL "http://api.dfld.de/noise/dfld.de/004/027"  //"http://api.dfld.de/noise/dfld.de/001/161"  //Frankfurt Offenbach 1

#define THINGER
#define WRITE_BUCKETS        //(Comment out, if second device @ Thinger)

#define ConOut Serial         // change to Serial1 to report on second UART on D2
//#define PUBLISH_DFLD        //If this is the DFLD master, comment out else
//#define PUBLISH_BATTERY     //If this is the battery master, comment out else
//#define PUBLISH_SOUND       //If this is the sound master, comment out else
#define UDP_TARGET "192.168.xxx.xxx"  // Client address for Sound or Battery if defined
#define UDP_PORT   4211

//  ***Credentials***
#define SMARTCONFIG  // (WiFi Credentials over GogglePlay/Apple App SmartConfig)
// alternatively to Smartconfig App, you can comment out Smartconfig and enter your credentials
//#define WIFI_SSID "Enter Your SSID"
//#define WIFI_PASS "Enter Yout Password"
#define wifiMaxTries 30
#define wifiRepeatInterval 1000

String OPEN_WEATHER_MAP_APP_ID =      "Application ID";
String OPEN_WEATHER_MAP_LOCATION_ID = "Location Id";
String OPEN_WEATHER_MAP_LANGUAGE =    "de";
boolean IS_METRIC =                   true;

#define THINGER_USERNAME    "Username" 
#define THINGER_CREDENTIALS "Credentials" 

// ***Time zones***
#define NTP_SERVER "de.pool.ntp.org"
#define MYTZ TZ_Europe_Paris
#define TZ   1                              // (utc+) TZ in hours

// ***Acoustical parameters***
#define Ao94 1024  // 747  for AK module with offset and 2,5v | 1050 for linear 0..1V
#define Ao47 530   // 458  for AK module with offset and 2,5v |  550 for linear 0..1V

#define  UPPER_LIMIT_DB              78 // Just defines the upper/lower limit of plots
#define  LOWER_LIMIT_DB              31
#define  EVENT_THRESHOLD_LEVEL       52 // Begin of Exceedance level
#define  MEASUREMENT_THRESHOLD_LEVEL 48 // Begin of measurement level
#define  MIN_EXCEEDANCE_TIME         15 // Minimum duration of an event
#define  MAX_EXCEEDANCE_TIME         60 // Maximum duration of an event
#define  LISTENING_TIME              50 // mimimum time between events

// ***Electrical parameters***
//#define DEVICES_FOUND INA.begin(3, 40000) //3A Max, 40mOhm Shunt
#define SHUNT    40000    // 16666 = 0,1 Ohm +// 0,02Ohm  or 40000
#define AMPERE   3        // 10 or 5
#define SERIAL_SPEED 9600 //9600  115200 230400
#define MIN_VOLT  9.6     // 11.8  9.6
#define MAX_VOLT 12.8     // 14.2  12.8
#define MIN_AMP  -0.8
#define MAX_AMP  +0.8
#define MIN_WATT -1
#define MAX_WATT +8
