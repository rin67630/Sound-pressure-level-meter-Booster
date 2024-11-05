#Pre-compiled binaries for standard situations

This is the folder for ready compiled binaries in several standard versions.  
The binaries must be patched to the user's credentials using the provided PythonPatcher.py script.  
The PythonPatcher is another porject of mine here: https://github.com/rin67630/ESP_Binary_patcher.  
Once patched, the script can upload the patched binary to your blank ESP8266 device, which will then automatically know the WiFi credentials and the credentials to a cloud service (here thinger.io).  
Get your devie up and running including cloud dashboards at a breeze!  

The files provided are:

## Precompiled binary demo 
(Requires only a blank ESP8266 to deliver live data).  

      ESP_SwissArmyKnife_RevO6_2024.ino.bin
## Python script to patch that file with your credentials. 
       PythonPatcherTE.py
## Standard scripts from Espressif to flash devices
      espota.py
      esptool.py
## Templates for dashboards at thinger.io
      z_Thinger.Min.h
      z_Thinger.Sec.h
      z_Thinger_Stats.h

Download all files to a directory of your computer 
