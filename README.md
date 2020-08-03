# Swiss-Army-Knife-for-GM1380-Sound-Pressure-Meter
Pimp your cheap GM1380 Sound Pressure Meter with professional features...

There is a large choice of sound pressure level meters on the market, from pretty cheap to awfully expensive ones.
The cheap ones have frequently a sufficient accuracy for many purposes (albeit not being suitable for a legal enforcement). 

Most of them have however either no, or extremely bad reporting abilities.

The purpose of this development is to provide networking and reporting abilities as close to 
IEC 61672-1:2013 specifications as possible to an extremely cheap sound pressure level meter 
GM1358, by adding a ESP8266 WiFi microcontroller to it.

In the first variant sound pressure level meter + WiFi adapter + Online Dashboard the total value of the bill of material will be below 30€ !

The ESP8266 microcontroller will be small enough to fit into the original case of the GM1358 and the requested soldiering will be limited to three wires.
With soldiering skills, you can do the job in less than 10 minutes.

Your modified GM1358 will then provide USB and WiFi connectivity and be programmable to do the coolest things that only high-end devices will provide:

Evaluate the noise level according to following time response standards (simultaneously):
-	Fast
-	Slow 
-	Impulse
-	Real peak value by the minute (not the maximum of readings)
Statistics according to residential aircraft noise standards:

(steady noise equivalents)
-	Leq 1 minute
-	Leq for each hour of the day
-	Leq for 24h
-	Leq daytime 06:00 to 22:00
-	Leq nighttime 22:00 to 6:00
-	Leq 22:00 to 24:00
-	Lden

(number above threshold)
-	NAT for each hour of the day
-	NAT for 24h
-	NAT daytime 06:00 to 22:00
-	NAT nighttime 22:00 to 6:00
-	NAT 22:00 to 24:00
Additionally the program can grab weather information from openweathermap.org and provide the corresponding meteorological conditions.

With a little more hardware and a separate casing, you may also build the system with the ability to be solar powered including a solar power monitor to report all information about the battery condition and the power fed by the solar panel.
You will then operate the system without electrical connection to your computer, using the Cloud service Thinger.io.

You can also build a split system with the SPL meter (+ the solar power circuitry) being located outside gathering and transmitting the sound (and battery)  values over WiFi/ UDP (Long Range LoRa is planned)  to  another bare ESP8266 located inside that will provide the statistics over USB.

Last but not least, and back to the historical roots of the whole concept, the system is able to transmit over USB a single byte per second according to a proprietary "AK-Modulbus protocol" to a feeder program running e.g on a Raspberry Pi forwarding hourly reports to  the European aircraft noise network . http://www.eans.net/EANSindex.php  
This network is providing a very long time lobby-independent storage of aircraft noise information managed by residentials, totaling about 700 privately and communal operated noise stations throughout Europa.


