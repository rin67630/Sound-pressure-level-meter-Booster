#define HOST_NAME "GITHUB"

// ***Functional Configuration***
#define WEATHER_SOURCE_IS_URL   //_URL _NONE              Change end accordingly
#define BATTERY_SOURCE_IS_NONE  //_INA _UDP _NONE         Change end accordingly
#define SOUND_SOURCE_IS_URL     //_A0 _URL _UDP _NONE     Change end accordingly
#define PANEL_VOLTAGE_IS_A0    //_A0 _NONE 

#define THINGER            //(Comment out, if no thinger used)
#define WRITE_BUCKETS      //(Comment out, if this is the second device for Thinger)

#define Console0 Serial      // Port for user inputs  
#define Console1 Serial      // Port for user output
#define Console2 Serial1     // Port for midnight report e.g. on thermal printer
#define Console3 Serial      // Port for boot messages
#define Console4 Serial      // Port for AK-Outputs
#define SERIAL_SPEED           115200 //9600  115200 230400

#define PUBLISH_REPORT      // Issue events&midnight reports to UDP Port + 1, comment out else
//#define PUBLISH_DFLD        // Issue DFLD byte to UDP Port, comment out else
//#define PUBLISH_BATTERY     // If this is the battery master, comment out else
//#define PUBLISH_SOUND       // If this is the sound master, comment out else
#define UDP_TARGET "192.168.xxx.xxx"  // Enter a target system for UDP publications
#define UDP_PORT   4210      // Enter a target port for UDP (that port +1 will be used for midnight reports)

//  ***Credentials***
#define SMARTCONFIG  // (WiFi Credentials over GogglePlay/Apple App SmartConfig)
// alternatively to Smartconfig App, you can comment out Smartconfig 
// and enter your credentials to initalize for a new WiFi
//#define WIFI_SSID          "SSID"
//#define WIFI_PASS          "Password"
#define wifiMaxTries         30
#define wifiRepeatInterval   30

#define OPEN_WEATHER_MAP_APP_ID      "208085abb5a3859d1e32341d6e1f9079"
#define OPEN_WEATHER_MAP_LOCATION_ID "2928810"
#define OPEN_WEATHER_MAP_LANGUAGE    "de"
#define OPEN_WEATHER_MAP_UNITS       "metric"

#define DFLD_REGION  "001"
#define DFLD_STATION "001"

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
#define  MAX_EXCEEDANCE_TIME         50 // Maximum duration of an event
#define  LISTENING_TIME              30 // mimimum time between events

// ***Electrical parameters***
//#define DEVICES_FOUND INA.begin(10, 8000) //10A Max, 8milliOhm Shunt 
#define SHUNT    90000     // Shunt resitor value in microOhm (scaled x 10)
#define AMPERE   1        // 10 or 1 (scaled x 10)
#define MIN_VOLT 11.0      // 11.0   9.6
#define MAX_VOLT 14.4      // 14.4  12.8
#define MIN_AMP  -6
#define MAX_AMP  +6
#define MIN_WATT -40
#define MAX_WATT -40
#define PANEL_MAX 23500 // mV panel voltage
