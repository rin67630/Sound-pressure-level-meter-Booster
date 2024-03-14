# SPL-Booster: the Swiss-Army-Knife-for-Sound-Pressure-Level Meters
The solution for grassroots communities impacted by noise to visualize your annoyance level: 
Pimp a cheap GM1380 Sound Pressure Meter (or another one) with professional networked features...

There is a large choice of sound pressure level meters on the market, from pretty cheap to awfully expensive ones.
The cheap ones have frequently a sufficient accuracy for many purposes (albeit not being suitable for a legal enforcement). 

Most of them have however either no, or extremely primitive reporting abilities.

The purpose of this development is to provide networking and reporting abilities as close to IEC 61672-1:2013 specifications as possible to (preferably) an extremely cheap sound pressure level meter GM1358, by adding a ESP8266 WiFi microcontroller to it. Other SPL meters can be used as well, albeit requiring more components and soldering.

(Remark: Currently the GM1358 Sound pressure level meter is hard to source. You may use an alternative: the gravity sound pressure sensor. 
e.g. to be procured from Mouser https://www.mouser.de/ProductDetail/DFRobot/SEN0232?qs=r5DSvlrkXmJSkxvy12pSNQ%3D%3D. )

In the first variant sound pressure level meter + WiFi adapter + Online Dashboard the total value of the bill of material will be below 30€ !

With the GM1358, the ESP8266 microcontroller will be small enough to fit into its original case and the requested soldering will be limited to three wires.
With appropriate skills, you can do the job in less than 10 minutes.

Your modified GM1358 will then provide USB and WiFi connectivity and be programmable to do the coolest things that only high-end devices will provide:

Evaluate the noise level according to following time response standards (simultaneously):
-	Fast     (125mS)
-	Slow     (attack 1S low pass filter, decay linear 4,3dB/Sec)
-	Impulse  (attack no filter,          decay linear 2,9dB/Sec)
-	Real peak value by the minute (not the maximum of readings)
- Background level (low pass filter 2000s, ignoring events above threshold)


For each event:
- time of the peak
- duration above a fixed threshold
- duration above the criterium "max-10dB"
- Leq for the event according to a fixed threshold
- Leq for the event according to the criterium "max-10dB"
- LE for the event according to a fixed threshold
- LE for the event according to the criterium "max-10dB"

![image](https://user-images.githubusercontent.com/14197155/127849033-777ff7cd-66ec-44c8-b6fa-3488e27fa861.png)
 
Statistics according to residential aircraft noise standards:

Timed metrics
-	Leq 1 minute
-	Leq for each hour of the day
-	Leq for 24h
-	Leq daytime 06:00 to 22:00
-	Leq nighttime 22:00 to 6:00
-	Leq 22:00 to 24:00
-	Lden

Event related metrics:
-	NAT for each hour of the day
-	NAT for 24h
-	NAT daytime 06:00 to 22:00
-	NAT nighttime 22:00 to 6:00
-	NAT 22:00 to 24:00

Additionally the program can grab weather information from openweathermap.org and provide the corresponding meteorological conditions.

![image](https://user-images.githubusercontent.com/14197155/127849258-713dad08-c1ca-47cf-92c1-a6851341be9e.png)


With a little more hardware and a separate casing, you may also build the system with the ability to be solar powered including a solar power monitor to report all information about the battery condition and the power fed by the solar panel.
You will then operate the system without electrical connection to your computer, using the Cloud service Thinger.io (free for 2 devices and 4 dashboards...)

You can also build a split system with the SPL meter (+ the solar power circuitry) being located outside gathering and transmitting the sound (and battery)  values over WiFi/ UDP (Long Range LoRa is planned)  to  another bare ESP8266 located inside that will provide the statistics over USB.

Please look at the PDF manual for an extensive description of all features and reports: the list is quite impressive!

Last but not least, and back to the historical roots of the whole concept, the system is able to transmit over USB a single byte per second according to a proprietary "AK-Modulbus protocol" to a feeder program running e.g on a Raspberry Pi forwarding hourly reports to  the European aircraft noise network . http://www.eans.net/EANSindex.php  
This network is providing a very long time lobby-independent storage of aircraft noise information managed by residentials, totaling about 700 privately and communal operated noise stations throughout Europa.

http://www.dfld.de/Mess/Messwerte.php?R=004&S=008&D=02.08.2021&ZT=06
