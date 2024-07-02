/* Target Hardware: ESP8266-12E / Wemos D1 / Lolin 8266
 * N.B. Compile sketch with following board settings:  LolinWEMOSD1 (Clone)    
 *  
 * cf: https://github.com/rin67630/Sound-pressure-level-meter-Booster
 * 
 * The solution for grassroots communities impacted by noise to visualize your annoyance level: 
 * Pimp a low-cost GM1380 Sound Pressure Meter (or another one) with professional networked features...
 * Integrating-averaging functionalities forming an overall set of data 
 * intending to be as close to IEC 61672-1:2013 specifications as possible:
 * Calibration / Linearization @ 94dB and 47dB
 * NAT and event categorization a to DIN 45643
 * Woldwide Internet Access over Thinger.io : https://docs.thinger.io/coding
 * 
 * License: gnu general public license from Free Software Foundation, Inc.
 * NO WARRANTY THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE IS WITH YOU

 ***  Usage of the menu via Telnet  ***
Type telnet (the respecive module's IP Aaddress) on your Linux / MacOS terminal. 
On Windows, use PuTTY or WSL, the Windows implemantation of Telnet is broken.

*** The legal stuff ***
This software is open-source under creative common license CC BY-SA
It is given in the hope to be useful, but I am NOT RESPONSIBLE IN ANY WAY OF DAMAGES WAHTSOEVER 
occuring from the use of my software.
Be careful, high currents, DC voltages over 24V, Batteries can cause damages to property and/or health, even kill you !

*** Credits ***

Libraries:
Thanks to the respective owners of all libraries used:
-ESP8266 and ESP32 OLED driver for SSD1306 displays by ThingPulse, Fabrice Weinberg
-MobaTools by MicroBahner from which I took the Motobuttons.h lib
-Arduinojson by Benoit Blanchon <blog.benoitblanchon.fr>
-ThingerCore32 and Thinger.io by Alvaro Luis Bustamante
-TelnetStream by Juraj Andrassy
-INA2xx by Arnd Zanshin
-SSD1306 by Adafruit
-InterpolationLib by Luis Llamas

The other libraries are the standard libs from Arduino, Espressif, Adafruit...
 */
