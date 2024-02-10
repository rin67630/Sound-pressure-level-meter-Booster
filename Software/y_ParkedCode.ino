/*
OpenSky Network ADS-B
https://opensky-network.org/apidoc/rest.html#all-state-vectors
https://opensky-network.org/api/states/all?lamin=51.37&lomin=6.91&lamax=51.39&lomax=6.98
Index   Property  Type  Description
0   icao24  string  Unique ICAO 24-bit address of the transponder in hex string representation.
1   callsign  string  Callsign of the vehicle (8 chars). Can be null if no callsign has been received.
2   origin_country  string  Country name inferred from the ICAO 24-bit address.
3   time_position   int   Unix timestamp (seconds) for the last position update. Can be null if no position report was received by OpenSky within the past 15s.
4   last_contact  int   Unix timestamp (seconds) for the last update in general. This field is updated for any new, valid message received from the transponder.
5   longitude   float   WGS-84 longitude in decimal degrees. Can be null.
6   latitude  float   WGS-84 latitude in decimal degrees. Can be null.
7   baro_altitude   float   Barometric altitude in meters. Can be null.
8   on_ground   boolean   Boolean value which indicates if the position was retrieved from a surface position report.
9   velocity  float   Velocity over ground in m/s. Can be null.
10  true_track  float   True track in decimal degrees clockwise from north (north=0°). Can be null.
11  vertical_rate   float   Vertical rate in m/s. A positive value indicates that the airplane is climbing, a negative value indicates that it descends. Can be null.
12  sensors   int[]   IDs of the receivers which contributed to this state vector. Is null if no filtering for sensor was used in the request.
13  geo_altitude  float   Geometric altitude in meters. Can be null.
14  squawk  string  The transponder code aka Squawk. Can be null.
15  spi   boolean   Whether flight status indicates special purpose indicator.
16  position_source   int   Origin of this state’s position: 0 = ADS-B, 1 = ASTERIX, 2 = MLA

states  
0 
0 "4b1804"
1 "SWR208N "
2 "Switzerland"
3 1598550458
4 1598550459
5 8.5395
6 47.4796
7 419.1
8 false
9 77.9
10  137.14
11  -4.23
12  null
13  495.3
14  "1000"
15  false
16  0

ESP8266 Cut WiFi Functionality to save power

   1)  Include a minimum of the below before setup(void)

// ------------------begin ESP8266'centric----------------------------------
#define FREQUENCY    160                  // valid 80, 160
//
#include "ESP8266WiFi.h"
extern "C" {
#include "user_interface.h"
}
// ------------------end ESP8266'centric------------------------------------

    2) Include a minimum of the below in setup(void)

// ------------------begin ESP8266'centric----------------------------------
WiFi.forceSleepBegin();                  // turn off ESP8266 RF
delay(1);                                // give RF section time to shutdown
system_update_cpu_freq(FREQUENCY);
// ------------------end ESP8266'centric------------------------------------

    3) Include a minimum of the below in loop(void)

// ------------------begin ESP8266'centric----------------------------------
// pat the watchdog timer
wdt_reset();
// ------------------end ESP8266'centric------------------------------------

================

IR Receiver

//#include <IRremoteESP8266.h>
//#include <IRrecv.h>
//#include <IRutils.h>
#define kRecvPin 15 //Pin for IR Receiver

//IR code definitions for RTL-SDR ADS-B Stick
// With long:
//unsigned long keys[] = {0xFF48B7, 0xFF906F, 0xFFB847, 0xFFF807, 0xFFB04F, 0xFF9867, 0xFFD827, 0xFF8877, 0xFFA857, 0xFFE817, 0xFFA05F, 0xFF40BF, 0xFF6897, 0xFFB24D, 0xFF2AD5, 0xFF32CD, 0xFF30CF, 0xFF38C7, 0xFF02FD, 0xFF50AF, 0xFF7887, 0xFFFFFFFF};
// Without long:
unsigned long keys[] = {0xFF48B7, 0xFF906F, 0xFFB847, 0xFFF807, 0xFFB04F, 0xFF9867, 0xFFD827, 0xFF8877, 0xFFA857, 0xFFE817, 0xFFA05F, 0xFF40BF, 0xFF6897, 0xFFB24D, 0xFF2AD5, 0xFF32CD, 0xFF30CF, 0xFF38C7, 0xFF02FD, 0xFF50AF, 0xFF7887};
// decode Key              0         1          2        3         4         5         6          7         8         9        ch+       ch-       Red       Green     Src       Recd     TimS      Recl      Full      Vol-     Vol+       Long
// decode to               0         1          2        3         4         5         6          7         8         9        10        11        12        13        14        15       16        17         18        19       20         21
byte keyNumber;


OLED Display

//#include <SSD1306Wire.h>



================

Cayenne

void loop() {
   Cayenne.loop();
}

// Default function for sending sensor data at intervals to Cayenne.
// You can also use functions for specific channels, e.g CAYENNE_OUT(1) for sending channel 1 data.
CAYENNE_OUT_DEFAULT()
{
   // Write data to Cayenne here. This example just sends the current uptime in milliseconds on virtual channel 0.
   Cayenne.virtualWrite(0, millis());
   // Some examples of other functions you can use to send data.
   //Cayenne.celsiusWrite(1, 22.0);
   //Cayenne.luxWrite(2, 700);
   //Cayenne.virtualWrite(3, 50, TYPE_PROXIMITY, UNIT_CENTIMETER);
}

// Default function for processing actuator commands from the Cayenne Dashboard.
// You can also use functions for specific channels, e.g CAYENNE_IN(1) for channel 1 commands.
CAYENNE_IN_DEFAULT()
{
   CAYENNE_LOG("Channel %u, value %s", request.channel, getValue.asString());
   //Process message here. If there is an error set an error message using getValue.setError(), e.g getValue.setError("Error message");
}

Thinger
https://docs.thinger.io/coding
*/
