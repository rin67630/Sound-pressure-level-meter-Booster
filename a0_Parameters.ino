#define HOST_NAME "GITHUB"

// ***Functional Configuration***
#define WEATHER_SOURCE_URL  //_URL _NONE (UDP planned)
#define BATTERY_SOURCE_INA  //_INA _UDP _NONE
#define SOUND_SOURCE_ANAIN    //_ANAIN _URL _UDP _NONE
//#define DFLDjsonURL  //"http://api.dfld.de/noise/dfld.de/001/161"  //e.g Frankfurt Offenbach 1

#define THINGER              // http://thinger.io
#define WRITE_BUCKETS        //(Comment out, if second device @ Thinger)

#define Console0 Serial      // Port for user inputs
#define Console1 Serial      // Port for user output
#define Console2 Serial1     // Port for midnight&event report (e.g. thermo printer)
#define Console3 Serial      // Port for boot messages
#define Console4 Serial      // Port emulating https://www.ak-modul-bus.de/cgi-bin/iboshop.cgi?showd10!0,0,DBAO
#define SERIAL_SPEED 9600 //9600  115200 230400

#define PUBLISH_REPORT        // Issue events&midnight reports to UDP Port + 1
#define PUBLISH_DFLD          // Issue DFLD byte to UDP Port
//#define PUBLISH_BATTERY     //If this is the battery master, comment out else
//#define PUBLISH_SOUND       //If this is the sound master, comment out else
#define UDP_TARGET "192.168.188.46"  // Firholz-04-27
#define UDP_PORT   4211

//  ***Credentials***
#define SMARTCONFIG  // (WiFi Credentials over GogglePlay/Apple App SmartConfig)
// alternatively to Smartconfig App, you can comment out Smartconfig and enter your credentials
//#define WIFI_SSID "Enter Your SSID"
//#define WIFI_PASS "Enter Yout Password"
#define wifiMaxTries 30
#define wifiRepeatInterval 1000

String OPEN_WEATHER_MAP_APP_ID =      "Openwaethermaps ID";
String OPEN_WEATHER_MAP_LOCATION_ID = "Openwaethermaps location ID";
String OPEN_WEATHER_MAP_LANGUAGE =    "de";
boolean IS_METRIC =                   true;

#define THINGER_USERNAME    "Thinger User Name"     
#define THINGER_CREDENTIALS "Thinger credential"  
#define THINGER_DEVICE HOST_NAME // Device name if <> Host Name.

// ***Time zones***
#define NTP_SERVER "de.pool.ntp.org"
#define MYTZ TZ_Europe_Paris
#define TZ   1                              // (utc+) TZ in hours

// ***Acoustical parameters***
#define Ao94 747   // 747  for AK with offset and 2,5v  1050 for linear 0..1V
#define Ao47 458   // 458  for AK with offset and 2,5v  550 for linear 0..1V

#define  UPPER_LIMIT_DB              78 // Just defines the upper/lower limit of plots
#define  LOWER_LIMIT_DB              31
#define  EVENT_THRESHOLD_LEVEL       55 // Begin of Exceedance level
#define  MEASUREMENT_THRESHOLD_LEVEL 52 // Begin of measurement level
#define  MIN_EXCEEDANCE_TIME         15 // Minimum duration of an event
#define  MAX_EXCEEDANCE_TIME         60 // Maximum duration of an event
#define  LISTENING_TIME              50 // mimimum time between events

// ***Electrical parameters***
//#define DEVICES_FOUND INA.begin(3, 40000) //3A Max, 40mOhm Shunt
#define SHUNT    40000    // 16666 = 0,1 Ohm +// 0,02Ohm  or 40000
#define AMPERE   3        // 10 or 5
#define MIN_VOLT 11.8     // 11.8  9.6
#define MAX_VOLT 14.2     // 14.2  12.8
#define MIN_AMP  -6
#define MAX_AMP  +6
#define MIN_WATT -40
#define MAX_WATT -40
