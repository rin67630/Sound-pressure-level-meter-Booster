#define HOST_NAME "GITHUB"

// ***Functional Configuration***
#define WEATHER_SOURCE_URL  //_URL _NONE              Change end accordingly
#define BATTERY_SOURCE_UDP   //_INA _UDP _NONE         Change end accordingly
#define SOUND_SOURCE_ANAIN    //_ANAIN _URL _UDP _NONE  Change end accordingly

#define THINGER            //(Comment out, if no thinger used)
#define WRITE_BUCKETS      //(Comment out, if this is the second device for Thinger)

#define Console0 Serial      // Port for user inputs  
#define Console1 Serial      // Port for user output
#define Console2 Serial1     // Port for midnight report e.g. on thermal printer
#define Console3 Serial      // Port for boot messages
#define Console4 Serial      // Port for AK-Outputs
#define SERIAL_SPEED            9600 //9600  115200 230400

#define PUBLISH_REPORT      // Issue events&midnight reports to UDP Port + 1, comment out else
//#define PUBLISH_DFLD        // Issue DFLD byte to UDP Port, comment out else
//#define PUBLISH_BATTERY       // If this is the battery master, comment out else
//#define PUBLISH_SOUND       // If this is the sound master, comment out else
#define UDP_TARGET "192.168.188.43"  // RasPi 3a Bare
#define UDP_PORT   4210

//  ***Credentials***
#define SMARTCONFIG  // (WiFi Credentials over GogglePlay/Apple App SmartConfig)
// alternatively to Smartconfig App, you can comment out Smartconfig 
// and enter your credentials to initalize for a new WiFi
//#define WIFI_SSID          "SSID"
//#define WIFI_PASS          "Password"
#define wifiMaxTries         30
#define wifiRepeatInterval   100

#define OPEN_WEATHER_MAP_APP_ID      "208085abb5a3859d1e32341d6e1f9079"
#define OPEN_WEATHER_MAP_LOCATION_ID "2928810"
#define OPEN_WEATHER_MAP_LANGUAGE    "de"
#define OPEN_WEATHER_MAP_UNITS       "metric"

#define DFLD_REGION  "004"
#define DFLD_STATION "020"

#define THINGER_USERNAME    "User"     
#define THINGER_CREDENTIALS "Credential"  
#define THINGER_DEVICE      "Device"

// ***Time zones***
#define NTP_SERVER "de.pool.ntp.org"
#define MYTZ TZ_Europe_Paris
#define TZ   1                              // (utc+) TZ in hours

// ***Acoustical parameters***
#define Ao94 1050   // 747  for AK with offset and 2,5v  1050 for linear 0..1V
#define Ao47 550   //  461  for AK with offset and 2,5v  550 for linear 0..1V

#define  WIND_LIMIT                  10 // upper limit to record NATs
#define  UPPER_LIMIT_DB              78 // upper limit of plots
#define  LOWER_LIMIT_DB              31 // lower limit of plots
#define  EVENT_THRESHOLD_LEVEL       57 // Begin of Exceedance level
#define  MEASUREMENT_THRESHOLD_LEVEL 55 // Begin of measurement level
#define  MIN_EXCEEDANCE_TIME         10 // Minimum duration of an event
#define  MAX_EXCEEDANCE_TIME         60 // Maximum duration of an event
#define  LISTENING_TIME              50 // mimimum time between events

// ***Electrical parameters***
#define SHUNT    40000    // 16666 = 0,1 Ohm +// 0,02Ohm  or 40000
#define AMPERE   5        // 10 or 5
#define SERIAL_SPEED 9600 //9600  115200 230400
#define MIN_VOLT 11.8     // 11.8 for Lead Battery,  9.6 for 3x18360 Lithium
#define MAX_VOLT 14.2     // 14.2 for Lead Battery, 12.8 for 3x18360 Lithium
#define MIN_AMP  -0.8
#define MAX_AMP  +0.8
#define MIN_WATT -1
#define MAX_WATT +20
