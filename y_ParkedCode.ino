/*


https://github.com/mcxiaoke/ESPDateTime


void setup() {
  delay(1000);
  Serial.begin(115200);
  setupWiFi();
  setupDateTime();
  Serial.println(DateTime.now());
  Serial.println(DateTime.getTime());
  Serial.println(DateTime.utcTime());
  Serial.println("--------------------");
  Serial.println(DateTime.toString());
  Serial.println(DateTime.toISOString());
  Serial.println(DateTime.toUTCString());
  Serial.println("--------------------");
  Serial.println(DateTime.format(DateFormatter::COMPAT));
  Serial.println(DateTime.format(DateFormatter::DATE_ONLY));
  Serial.println(DateTime.format(DateFormatter::TIME_ONLY));
  Serial.println("--------------------");
  DateTimeParts p = DateTime.getParts();
  Serial.printf("%04d/%02d/%02d %02d:%02d:%02d %ld %+05d\n", p.getYear(),
                p.getMonth(), p.getMonthDay(), p.getHours(), p.getMinutes(),
                p.getSeconds(), p.getTime(), p.getTimeZone());
  Serial.println("--------------------");
  time_t t = DateTime.now();
  Serial.println(DateFormatter::format("%Y/%m/%d %H:%M:%S", t));
  Serial.println(DateFormatter::format("%x - %I:%M %p", t));
  Serial.println(DateFormatter::format("Now it's %F %I:%M%p.", t));
}

void loop() {
  if (millis() - ms > 5000) {
    ms = millis();
    Serial.println("--------------------");
    if (!DateTime.isTimeValid()) {
      Serial.println("Failed to get time from server, retry.");
      DateTime.begin();
    } else {
      Serial.printf("Up     Time:   %lu seconds\n", millis() / 1000);
      Serial.printf("Local  Time:   %ld\n", DateTime.now());
      Serial.printf("Local  Time:   %s\n", DateTime.toString().c_str());
      Serial.printf("UTC    Time:   %ld\n", DateTime.utcTime());
      Serial.printf("UTC    Time:   %s\n",
                    DateTime.formatUTC(DateFormatter::SIMPLE).c_str());
    }
  }
}
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


Test for thermal printer
Default code PageStandard Europe
12:31:00 - 45.2 46.7 49.7 51.3 
  
Leq(h-1):47.3 Max:42.5  Min:40.5 
A0dBSlow:41.4
PKTm: 16:33:07 NAT:5 PKdB:64.2 
ATdB   : 61.2 ATsec    : 55 
PK-10dB: 61.1 PK-10sec : 28
*/
