void setup()
{
  delay(3000); // Wait for serial monitor to be started
  // Serial initialisation
  Serial.begin (SERIAL_SPEED); // On USB port
  //Serial1.begin(SERIAL_SPEED); // On GPIO2 / D4

#if defined(BATTERY_SOURCE_IS_INA) | defined(WEATHER_SOURCE_IS_BME680)
  Wire.begin(SDA, SCL);
#endif

#if defined(WEATHER_SOURCE_IS_BME680)
  bme.setTemperatureOversampling(BME680_OS_8X);
  bme.setHumidityOversampling(BME680_OS_2X);
  bme.setPressureOversampling(BME680_OS_4X);
#endif

  Console3.printf("\n\n\nESP-Karajan at work,\nSerial @ %u Baud\n", SERIAL_SPEED);

  pinMode(STDLED, OUTPUT);
  /*
    // Witty Color LEDs
    pinMode(REDLED, OUTPUT);
    pinMode(GRNLED, OUTPUT);
    pinMode(BLULED, OUTPUT);
  */
  // Networking and Time
  getWiFi();
  ArduinoOTA.setHostname(HOST_NAME);

  //WiFi.printDiag(Serial);
  Console3.printf("MAC address: %s , \nHostname: %s", WiFi.macAddress().c_str(), WiFi.hostname().c_str());
  digitalWrite(STDLED, true);

  getNTP();
  delay(3000);

  getEpoch();            // writes the Epoch (Numbers of seconds till 1.1.1970...
  Console3.println("\nGot Epoch");
  getTimeData();         // breaks down the Epoch into discrete values.
  sprintf(charbuff, "Now is %02d:%02d:%02d, Date is %s, %02d %s %04d", Hour, Minute, Second, DayName, Day, MonthName, Year);
  Console3.println(charbuff);

#if defined (USE_OTA)
  // Over the Air Framework
  ArduinoOTA.onStart([]() {
    String type;
    if (ArduinoOTA.getCommand() == U_FLASH) {
      type = "sketch";
    } else { // U_FS
      type = "filesystem";
    }
    // NOTE: if updating FS this would be the place to unmount FS using FS.end()
    Console3.println("Start updating " + type);
  });
  ArduinoOTA.onEnd([]() {
    Console3.println("\nEnd");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Console3.printf("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Console3.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) {
      Console3.println("Auth Failed");
    } else if (error == OTA_BEGIN_ERROR) {
      Console3.println("Begin Failed");
    } else if (error == OTA_CONNECT_ERROR) {
      Console3.println("Connect Failed");
    } else if (error == OTA_RECEIVE_ERROR) {
      Console3.println("Receive Failed");
    } else if (error == OTA_END_ERROR) {
      Console3.println("End Failed");
    }
  });
#endif

#if defined (TELNET)
  TelnetStream.begin();
  Console3.println("Console available on Telnet");
#endif

#if defined (USE_UDP)
  // Begin listening to UDP port
  UDP.begin(UDP_PORT);
  Console3.printf("Sending on UDP ports %u and ff.", UDP_PORT);
#endif

#if defined (BATTERY_SOURCE_IS_INA)
  // INA 226 Battery Sensor
  devicesFound = INA.begin( AMPERE , SHUNT); // Define max Ampere and Shunt value
  INA.setBusConversion(8500);            // Maximum conversion time 8.244ms
  INA.setShuntConversion(8500);          // Maximum conversion time 8.244ms
  INA.setAveraging(100);                 // Average each reading n-times
  INA.setMode(INA_MODE_CONTINUOUS_BOTH); // Bus/shunt measured continuously
  INA.alertOnBusOverVoltage(true, 14300); // Trigger alert if over 13,8V on bus

  ina_voltage = INA.getBusMilliVolts(0);
  ina_current = INA.getBusMicroAmps(0);
  battery.voltage = ina_voltage / 1000;
  battery.current = ina_current / 1000000;
#else
  battery.voltage = (MAX_VOLT + MIN_VOLT) / 2;
  battery.current = 0;
#endif

  // IOT initialisation
#if defined (THINGER)
  // definition of structures for transmission
  // digital pin control example (i.e. turning on/off a light, a relay, configuring a parameter, etc)
  // resource output example (i.e. reading a sensor value) https://docs.thinger.io/coding#define-output-resources
  //https://docs.thinger.io/coding#read-multiple-data

  thing["control"] << [](pson & in) {
    displayPage    = in["displayPage"];
    displaySubPage = in["displaySubPage"];
    serialPage     = in["serialPage"];
  };

  thing["noise"] >> [](pson & out)
  {
    out["min"]       = sound.A0dBMin;
    out["slow"]      = sound.A0dBSlow;
    out["backgr"]    = sound.A0dBBgr;
    out["max"]       = sound.A0dBMax;
    out["fast"]      = sound.A0dBFast;
    out["impulse"]   = sound.A0dBImpulse;
    out["limit"]     = UPPER_LIMIT_DB;
  };

  thing["energy"] >> [](pson & out)
  {
    out["voltage"]         = battery.voltage;
    out["panel"]           = battery.panel;
    out["current"]         = battery.current;
    out["power"]           = battery.power;
    out["int_resistance"]  = battery.ohm;
    out["percent_charged"] = percent_charged;
  };

  thing["DAY"] >> [](pson & out)
  {
    out["Device"] = HOST_NAME;
    out["L0-24h"] = leq[26];
    out["Lnight"] = leq[28];     
    out["L00h"] = leq[0];
    out["L01h"] = leq[1];
    out["L02h"] = leq[2];
    out["L03h"] = leq[3];
    out["L04h"] = leq[4];
    out["L05h"] = leq[5];
    out["L06h"] = leq[6];
    out["L07h"] = leq[7];
    out["L08h"] = leq[8];
    out["L09h"] = leq[9];
    out["L10h"] = leq[10];
    out["L11h"] = leq[11];
    out["L12h"] = leq[12];
    out["L13h"] = leq[13];
    out["L14h"] = leq[14];
    out["L15h"] = leq[15];
    out["L16h"] = leq[16];
    out["L17h"] = leq[17];
    out["L18h"] = leq[18];
    out["L19h"] = leq[19];
    out["L20h"] = leq[20];
    out["L21h"] = leq[21];
    out["L22h"] = leq[22];
    out["L23h"] = leq[23];
    out["N0-24h"] = NAT[26];
    out["Nnight"] = NAT[28];    
    out["N00h"] = NAT[0];
    out["N01h"] = NAT[1];
    out["N02h"] = NAT[2];
    out["N03h"] = NAT[3];
    out["N04h"] = NAT[4];
    out["N05h"] = NAT[5];
    out["N06h"] = NAT[6];
    out["N07h"] = NAT[7];
    out["N08h"] = NAT[8];
    out["N09h"] = NAT[9];
    out["N10h"] = NAT[10];
    out["N11h"] = NAT[11];
    out["N12h"] = NAT[12];
    out["N13h"] = NAT[13];
    out["N14h"] = NAT[14];
    out["N15h"] = NAT[15];
    out["N16h"] = NAT[16];
    out["N17h"] = NAT[17];
    out["N18h"] = NAT[18];
    out["N19h"] = NAT[19];
    out["N20h"] = NAT[20];
    out["N21h"] = NAT[21];
    out["N22h"] = NAT[22];
    out["N23h"] = NAT[23];
#ifndef BATTERY_SOURCE_IS_NONE
    out["BAhDay"] = AhBat[26];
    out["BV@0h"]  = voltageAt0H;
    out["BVDiff"] = voltageDelta;
    out["B00h"] = AhBat[0];
    out["B01h"] = AhBat[1];
    out["B02h"] = AhBat[2];
    out["B03h"] = AhBat[3];
    out["B04h"] = AhBat[4];
    out["B05h"] = AhBat[5];
    out["B06h"] = AhBat[6];
    out["B07h"] = AhBat[7];
    out["B08h"] = AhBat[8];
    out["B09h"] = AhBat[9];
    out["B10h"] = AhBat[10];
    out["B11h"] = AhBat[11];
    out["B12h"] = AhBat[12];
    out["B13h"] = AhBat[13];
    out["B14h"] = AhBat[14];
    out["B15h"] = AhBat[15];
    out["B16h"] = AhBat[16];
    out["B17h"] = AhBat[17];
    out["B18h"] = AhBat[18];
    out["B19h"] = AhBat[19];
    out["B20h"] = AhBat[20];
    out["B21h"] = AhBat[21];
    out["B22h"] = AhBat[22];
    out["B23h"] = AhBat[23];
#endif
  };

  thing["HOUR"] >> [](pson & out)
  {
    out["temperature"] = temperature;
    out["humidity"]    = humidity;
    out["pressure"]    = pressure;
    out["wind"]        = wind_speed;
    out["direction"]   = wind_direction;
    out["summary"]     = weather_summary;

#ifndef BATTERY_SOURCE_IS_NONE
    out["voltage"]         = battery.voltage;
    out["current"]         = battery.current;
    out["power"]           = battery.power;
    out["percent_charged"] = percent_charged;
#endif
  };

  thing[BUCKET_MIN] >> [](pson & out)
  {
    out["min"]     = A0dBMin1min;
    out["LEq"]     = A0dBLeq1min;
    out["LEtr"]    = A0dBtrend;    
    out["max"]     = A0dBMax1min;
    out["backgr"]  = sound.A0dBBgr;
#ifndef BATTERY_SOURCE_IS_NONE
    out["voltage"]         = battery.voltage;
    out["panel"]           = battery.panel;
    out["current"]         = battery.current;
    out["power"]           = battery.power;
    out["percent_charged"] = percent_charged;
#endif
  };

  thing[BUCKET_EVENT] >> [](pson & out)
  {
    out["peakTime"]         = peakTime;
    out["eventPeak"]        = peakValue;
    out["aboveThreshLe"]    = aboveThreshLE;
    out["aboveThreshLeq"]   = aboveThreshLEq;
    out["aboveThreshDuration"] = aboveThreshDuration;
    out["less10dBLe"]       = less10dBLE;
    out["less10dBLeq"]      = less10dBLEq;
    out["less10dBDuration"] = less10dBDuration;
    out["NAT"]              = NAT[Hour];
  };

  //Communication with Thinger.io
  thing.handle();
  delay(1000); // Wait for contact to happen.
  // Retrieve Persistance values

  pson persistance;
  thing.get_property("persistance", persistance);
#if (defined BATTERY_SOURCE_IS_INA) || (defined BATTERY_SOURCE_IS_UDP)
  currentInt          = persistance["currentInt"];
  nCurrent            = persistance["nCurrent"];
  AhBat[25]           = persistance["Ah/hour"];
  AhBat[26]           = persistance["Ah/yesterday"];
  voltageDelta        = persistance["voltageDelta"];
  voltageAt0H          = persistance["voltageAt0H"];
  battery.ohm = persistance["resistance"];
#endif
  leq[25]             = persistance["A0dBLEQ"];
  A0dBSumExp60min     = persistance["A0dBSumExp"];
  aboveThreshLEint    = persistance["aboveThreshLEint"];
  less10dBLEint       = persistance["less10dBLEint"];
  sound.A0dBBgr       = persistance["A0dBBgr"];
  corrdB              = persistance["corrdB"];
  A094                = persistance["A094"];
  A047                = persistance["A047"];

  temperature = persistance["temperature"];
  humidity            = persistance["humidity"];
  pressure    = persistance["pressure"];
  wind_speed  = persistance["wind"];
  wind_direction = persistance["direction"];

  pson lequ;
  thing.get_property("lequ", lequ);  // 0..23=hour, 25=current, 26=Lequ 24h, 27= LeqDay, 28=LeqNight, 29=Lden
  leq[0]  = lequ["00h"];
  leq[1]  = lequ["01h"];
  leq[2]  = lequ["02h"];
  leq[3]  = lequ["03h"];
  leq[4]  = lequ["04h"];
  leq[5]  = lequ["05h"];
  leq[6]  = lequ["06h"];
  leq[7]  = lequ["09h"];
  leq[8]  = lequ["08h"];
  leq[9]  = lequ["09h"];
  leq[10] = lequ["10h"];
  leq[11] = lequ["11h"];
  leq[12] = lequ["12h"];
  leq[13] = lequ["13h"];
  leq[14] = lequ["14h"];
  leq[15] = lequ["15h"];
  leq[16] = lequ["16h"];
  leq[17] = lequ["17h"];
  leq[18] = lequ["18h"];
  leq[19] = lequ["19h"];
  leq[20] = lequ["20h"];
  leq[21] = lequ["21h"];
  leq[22] = lequ["22h"];
  leq[23] = lequ["23h"];
  leq[25] = lequ["Leq"];
  leq[26] = lequ["Day"];
  leq[27] = lequ["Daytime"];
  leq[28] = lequ["Nighttime"];
  leq[29] = lequ["Lden"];
  leq[30] = lequ["L22-24h"];
  leq[31] = lequ["EvOT"];
  leq[32] = lequ["EV10"];

  pson NATu;
  thing.get_property("NATu", NATu);  // 0..23=hour, 25=current, 26=NATu 24h, 27= NATDay, 28=NATNight, 29=NAT22-24
  NAT[0]  = NATu["00h"];
  NAT[1]  = NATu["01h"];
  NAT[2]  = NATu["02h"];
  NAT[3]  = NATu["03h"];
  NAT[4]  = NATu["04h"];
  NAT[5]  = NATu["05h"];
  NAT[6]  = NATu["06h"];
  NAT[7]  = NATu["09h"];
  NAT[8]  = NATu["08h"];
  NAT[9]  = NATu["09h"];
  NAT[10] = NATu["10h"];
  NAT[11] = NATu["11h"];
  NAT[12] = NATu["12h"];
  NAT[13] = NATu["13h"];
  NAT[14] = NATu["14h"];
  NAT[15] = NATu["15h"];
  NAT[16] = NATu["16h"];
  NAT[17] = NATu["17h"];
  NAT[18] = NATu["18h"];
  NAT[19] = NATu["19h"];
  NAT[20] = NATu["20h"];
  NAT[21] = NATu["21h"];
  NAT[22] = NATu["22h"];
  NAT[23] = NATu["23h"];
  NAT[25] = NATu["NAT"];
  NAT[26] = NATu["Day"];
  NAT[27] = NATu["Daytime"];
  NAT[28] = NATu["Nighttime"];
  NAT[29] = NATu["NAT22-24"];

  pson BATmAh;
  thing.get_property("BAT", BATmAh);  // 0..23=hour, 25=current, 26=BATmAh 24h, 27= AhBatDay, 28=AhBatNight, 29=AhBat22-24
  AhBat[0]  = BATmAh["00h"];
  AhBat[1]  = BATmAh["01h"];
  AhBat[2]  = BATmAh["02h"];
  AhBat[3]  = BATmAh["03h"];
  AhBat[4]  = BATmAh["04h"];
  AhBat[5]  = BATmAh["05h"];
  AhBat[6]  = BATmAh["06h"];
  AhBat[7]  = BATmAh["09h"];
  AhBat[8]  = BATmAh["08h"];
  AhBat[9]  = BATmAh["09h"];
  AhBat[10] = BATmAh["10h"];
  AhBat[11] = BATmAh["11h"];
  AhBat[12] = BATmAh["12h"];
  AhBat[13] = BATmAh["13h"];
  AhBat[14] = BATmAh["14h"];
  AhBat[15] = BATmAh["15h"];
  AhBat[16] = BATmAh["16h"];
  AhBat[17] = BATmAh["17h"];
  AhBat[18] = BATmAh["18h"];
  AhBat[19] = BATmAh["19h"];
  AhBat[20] = BATmAh["20h"];
  AhBat[21] = BATmAh["21h"];
  AhBat[22] = BATmAh["22h"];
  AhBat[23] = BATmAh["23h"];
  AhBat[25] = BATmAh["LastHour"];
  AhBat[26] = BATmAh["Yesterday"];
  AhBat[27] = BATmAh["Today"];

#endif  //end if defined THINGER

  // Initialisations.
  if (A094 == 0) A094 = Ao94; // uninitialized or no Thinger
  if (A047 == 0) A047 = Ao47; // uninitialized or no Thinger

  state = 'o';                // event detection idle
  serialPage = 'A';           // Always start with AK Modulbus
  if (sound.A0dBBgr < LOWER_LIMIT_DB) sound.A0dBBgr = LOWER_LIMIT_DB;    // default background and minimum level
  //  digitalWrite(STDLED, true);

#if defined (OFFLINE)
  Console3.println(F("Going off-line "));
  WiFi.mode(WIFI_OFF);
  Console3.println (F("Sketch is now running offline with own time"));
#endif

  ArduinoOTA.begin();
  Console3.println("\nOTA-Ready\n\n\n\n");
  Console2.print("\nNAT|PKTime  |PKdB|Leq4|t10|Leq3|\n");
}
//end Setup
