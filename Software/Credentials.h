//  ***Credentials***
//
#define WIFI_SSID           "Public SSID"         //default SSID
#define WIFI_PASS           "Secret Password"     //default Password
#define UDP_TARGET          "192.168.?.?"         // Destination IP for your own Raspberry Pi
#define HOST_NAME            "Thinger_Device"     // Must match Thinger device name
//#define HOST_NAME            WiFi.getHostname() // This variant uses the ESP-ABCDEF (Mac Address) name for Thinger)
#define THINGER_USERNAME     "Thinger_User"       // Must match Thinger user name
#define UDP_TARGET           "192.168.001.001"    // Destination IP for Raspberry Pi (enter real local IP)
#define UDP_PORT             4321                 // Port to send data, next port to send reports 
#define THINGER_CREDENTIALS  "Thinger Credentials"// Must match Thinger device credentials (Not user password)
#define DFLD_REGION         "???"                 // Airport region at DFLD
#define DFLD_STATION        "???"                 // Station number at DFLD
#define Ao94                 747                    // 747  (AK Modulbus)  747 Gravity  952 GM1358(without voltage reducer)
#define Ao47                 461                    // 461  (AK Modulbus)  373 Gravity  475 GM1358(without voltage reducer)
  // ***Event parameters***
#define  WIND_LIMIT                  15 // upper limit of Wind speed to record NATs
#define  UPPER_LIMIT_DB              88 // upper limit of Thinger plots
#define  LOWER_LIMIT_DB              31 // lower limit of Thinger plots
#define  EVENT_THRESHOLD_LEVEL       58 // Begin of Exceedance level
#define  NAT_THRESHOLD_LEVEL         58 // Begin of Exceedance level
#define  MEASUREMENT_THRESHOLD_LEVEL 55 // Begin of measurement level
#define  MIN_EXCEEDANCE_TIME         20 // Minimum duration of an event
#define  MAX_EXCEEDANCE_TIME         80 // Maximum duration of an event
#define  LISTENING_TIME              20 // mimimum time between events

// ***Time zones***
#define NTP_SERVER "de.pool.ntp.org"
#define MYTZ TZ_Europe_Paris
#define TZ   1                // (utc+) TZ in hours

// ***Weather server***
#define OPEN_WEATHER_MAP_APP_ID      "7f02173c19eed016c4797f4ca4251fcc"
#define OPEN_WEATHER_MAP_LOCATION_ID "2876401"      // Lohausen
#define OPEN_WEATHER_MAP_LANGUAGE    "de"
#define OPEN_WEATHER_MAP_UNITS       "metric"
