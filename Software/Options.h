// ***Functional Configuration***
#define WEATHER_SOURCE_IS_URL   //_URL _NONE _BME680            Change end accordingly
#define BATTERY_SOURCE_IS_NONE  //_INA _UDP _NONE              Change end accordingly
#define SOUND_SOURCE_IS_A0      //_A0 _URL _UDP _NONE _FOO     Change end accordingly
#define DISPLAY_IS_NONE         // _NONE _OLED64x48  _OLED128x64
#define PANEL_VOLTAGE_IS_NONE   //_A0 _NONE 

//   === Thinger dashboard communication
#define THINGER               //Comment out, if no Thinger used
#define GRACE_PAUSE           //Suspend Thinger processing for a grace pause, if the remote server takes too long to react, in order to keep being reactive on menues
#define WRITE_BUCKETS         //Comment out, if this is the second device for Thinger
//#define STREAM_DATA           //Stream data to Thinger (instead of letting Thinger fetch the data when viewed)

//   === Telnet communication
#define TELNET                //Menu and reports over Telnet, comment out to run over Serial only
#define wifiMaxTries        20
#define wifiRepeatInterval  1000
#define USE_OTA               // Activate Over The Air configuration

//   === Serial communication
#define SERIAL_SPEED            9600     //9600  115200 230400
#if defined (TELNET)
//*** Aliases for serial communication***
#define Console0 TelnetStream  // Port for user inputs
#define Console1 TelnetStream  // Port for user outputs 
#define Console2 TelnetStream  // Port for midnight report e.g. on thermal printer
#define Console3 Serial        // Port for boot messages
#define Console4 Serial        // Port for AK-Outputs
#else
#define Console0 Serial        // Port for user inputs
#define Console1 Serial        // Port for user outputs 
#define Console2 Serial        // Port for midnight report
#define Console3 Serial        // Port for boot messages
#define Console4 Serial        // Port for AK-Outputs
#endif

//   === UDP communication
//#define PUBLISH_REPORT      // Issue events&midnight reports to UDP Port + 100, comment out else
//#define PUBLISH_DFLD        // Issue DFLD byte via UDP Port to another Swiss Army receiver, comment out else
//#define PUBLISH_BATTERY     // Issue Battery information via UDP Port to another Swiss Army receiver, comment out else
//#define PUBLISH_SOUND       // Issue Sound Levels via UDP Port to another Swiss Army receiver, comment out else


// ***Electrical parameters*** to be used if an INA226 monitors the battery parameters.
//#define DEVICES_FOUND INA.begin(10, 25000) //10A Max, 25milliOhm Shunt
#define SHUNT    25000     // Shunt resistor value in microOhm
#define AMPERE   10        // 10 or 1
#define MIN_VOLT 11.0      // 11.0   9.6
#define MAX_VOLT 14.4      // 14.4  12.8
#define MIN_AMP  -6
#define MAX_AMP  +6
#define MIN_WATT -40
#define MAX_WATT -40
