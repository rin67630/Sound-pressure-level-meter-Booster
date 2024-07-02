//----------------------- HARDWARE OPTIONS ---------------------------------
#define SCREEN_IS_NONE   // _NONE , _64x48 , _128x64; 
#define SCREEN_IS_REVERSED // _IS_NORMAL, _IS_REVERSED To turn the display 180° if required
#define BRIGHTNESS 128     // PWM value for default brightness with TTGO 0=totally dark;255=totally shiny

//----------------------- SOFTWARE OPTIONS ---------------------------------
#define DASHBRD_IS_THINGER    // _NONE , _THINGER          // (Internet Dashboard)
#define GRACE_PAUSE           //Suspend Thinger processing for a grace pause, if the remote server takes too long to react, in order to keep being reactive on menues
#define WRITE_BUCKETS         //Comment out, if this is the second device for Thinger
//#define STREAM_DATA         //Stream data to Thinger (instead of letting Thinger fetch the data when viewed)
#define TERM_IS_TELNET        // _TELNET, _SERIAL  defines where do Menus and Reports occur: _SERIAL and D7_IS_VICTRON are mutually exclusive )
#define UDP_IS_NONE        // _NONE , _SEND , _RECEIVE // (UDP Inter-ESP Communication)
#define ESP_UDP_ADDR         "192.168.188.57"                 // (IP of the receiving ESP having BATTERY_SOURCE_IS_UDP) 
#define ESP_UDP_PORT         4200  // (Port used to send/receive Values to other ESP)
#define COM_IS_NONE          // _NONE , _HOURLY , _DAILY          // Periodical reports to computer 
#define COM_UDP_ADDR         "192.168.188.96"              // (IP of the receiving computer for night reports) 
#define COM_UDP_PORT         4230                          // (Port used to send/receive Values to other computer) 
//#define DEVICE_NAME        "SAK"                // Name of the device used as Hostname and at Thinger.io 
//#define DEVICE_NAME        WiFi.getHostname()          // Device name is automatic from MAC-Address

//----------------------- MEASUREMENT AND I/O OPTIONS---------------------------------
#define WEATHER_SOURCE_IS_OWM    //_URL _NONE _BME680             Change end accordingly
#define BATTERY_SOURCE_IS_NONE   // _UDP _NONE                    Change end accordingly
#define SOUND_SOURCE_IS_FOO       //_A0 _URL _UDP _NONE _FOO       Change end accordingly
// #define SP_METER_IS_GRAVITY   // _AK_MODULBUS, GM1358, _Gravity Defined in Credentials

//   === Telnet communication
#define WIFI_REPEAT          500      //mS for retries and LED blinking during WiFi initialization
#define WIFI_MAXTRIES        30
#define WIFI_POWER           21.5  // from 0.5 to 21.5 full power (more current draw)
#define NTP_DELAY            6000
#define GRACE_PAUSE                //Suspend Network processing for a grace pause, if the remote server takes too long to react, in order to keep being reactive on menues

//   === Serial communication
#define SERIAL_SPEED            9600     //9600  115200 230400
