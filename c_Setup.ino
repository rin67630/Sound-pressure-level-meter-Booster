void setup()
{
  delay(3000); // Wait for serial monitor to be started
  // Serial initialisation
  Serial.begin(SERIAL_SPEED);
  Wire.begin(SDA, SCL);
  Serial.print("\n\n\n");
  Serial.print(F("Here is ESP-Karajan at work,\nHello Serial! @"));
  Serial.println(SERIAL_SPEED);
  slice = 1;

  pinMode(RELAY, OUTPUT);

  // Networking and Time
  getWiFi();
  ArduinoOTA.setHostname(HOST_NAME);

  //WiFi.printDiag(Serial);
  Serial.printf("MAC address: %s , \nHostname: %s", WiFi.macAddress().c_str(), WiFi.hostname().c_str());
  Serial.print("\nIP address: "); Serial.println(WiFi.localIP());
  getNTP();
  delay(3000);

  getEpoch();            // writes the Epoch (Numbers of seconds till 1.1.1970...
  getTimeData();         // breaks down the Epoch into discrete values.

  sprintf(charbuff, "Now is %02d:%02d:%02d. The Epoch is: %10lu" , Hour , Minute, Second, Epoch);
  Serial.println(charbuff);
  sprintf(charbuff, "Date is %s, %02d %s %04d ", DayName , Day , MonthName, Year);
  Serial.println(charbuff);

  //  delay(3000);
  getEpoch();            // writes the Epoch (Numbers of seconds till 1.1.1970...
  getTimeData();         // breaks down the Epoch into discrete values.
  //  Serial.print(F("\nNow, 3 seconds later it is "));   Serial.println( Time );

  // Over the Air Framework
  ArduinoOTA.onStart([]() {
    String type;
    if (ArduinoOTA.getCommand() == U_FLASH) {
      type = "sketch";
    } else { // U_FS
      type = "filesystem";
    }
    // NOTE: if updating FS this would be the place to unmount FS using FS.end()
    Serial.println("Start updating " + type);
  });
  ArduinoOTA.onEnd([]() {
    Serial.println("\nEnd");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) {
      Serial.println("Auth Failed");
    } else if (error == OTA_BEGIN_ERROR) {
      Serial.println("Begin Failed");
    } else if (error == OTA_CONNECT_ERROR) {
      Serial.println("Connect Failed");
    } else if (error == OTA_RECEIVE_ERROR) {
      Serial.println("Receive Failed");
    } else if (error == OTA_END_ERROR) {
      Serial.println("End Failed");
    }
  });

  // Begin listening to UDP port
  UDP.begin(UDP_PORT);
  Serial.print("\nCommunicating on UDP port ");
  Serial.print(UDP_PORT);

  // Weather
  myPlace.setLocation( 51.3683, 6.9293 );
  myPlace.setUnit("metric");

  // INA 226 Battery Sensor
  devicesFound = INA.begin( AMPERE , SHUNT); // Define max Ampere and Shunt value
  INA.setBusConversion(8500);            // Maximum conversion time 8.244ms
  INA.setShuntConversion(8500);          // Maximum conversion time 8.244ms
  INA.setAveraging(100);                 // Average each reading n-times
  INA.setMode(INA_MODE_CONTINUOUS_BOTH); // Bus/shunt measured continuously
  INA.AlertOnBusOverVoltage(true, 13900); // Trigger alert if over 13,8V on bus

  ina_voltage = INA.getBusMilliVolts(0);
  ina_current = INA.getBusMicroAmps(0);
  battery.voltage = ina_voltage / 1000;
  battery.current = ina_current / 1000000;
  battery.current = battery.current * -1;  // if shunt wired reversed.

  // Wireless initialisation
#if defined (THINGER)
  // definition of structures for transmission
  // digital pin control example (i.e. turning on/off a light, a relay, configuring a parameter, etc)
  thing["Relay"] << digitalPin(RELAY);
  //thing["Relay"] << invertedDigitalPin(RELAY);

  // resource output example (i.e. reading a sensor value) https://docs.thinger.io/coding#define-output-resources
  //https://docs.thinger.io/coding#read-multiple-data

  thing["noise"] >> [](pson & out)
  {
    out["min"]       = sound.A0dBMin;
    out["noise"]     = sound.A0dBSlow;
    out["backgr"]    = sound.A0dBBgr;
    out["max"]       = sound.A0dBMax;
    out["fast"]      = sound.A0dBFast;
    out["impulse"]   = sound.A0dBImpulse;
  };

  thing["DAY"] >> [](pson & out)
  {
    out["mAhBat[26]"] = mAhBat[26];
    out["voltageAt4h"] = voltageAt4h;
    out["voltageDelta"] = voltageDelta;
  };

  thing["HOUR"] >> [](pson & out)
  {
    out["temperature"] = outdoor_temperature;
    out["humidity"]    = outdoor_humidity;
    out["pressure"]    = outdoor_pressure;
    out["wind"]        = outdoor_wind_speed;
    out["direction"]   = outdoor_wind_direction;
    out["summary"]     = weather_summary;
#if defined BATTERY_MONITORING
    out["current"]     = battery.current;
    out["voltage"]     = battery.voltage;
    out["resistance"]  = internal_resistance;
    out["percent"]     = percent_charged;
#endif
  };

  thing["MIN"] >> [](pson & out)
  {
    out["min"]     = A0dBMin1min;
    out["LEq"]     = A0dBLeq1min;
    out["max"]     = A0dBMax1min;

#if defined BATTERY_MONITORING
    out["voltage"] = battery.voltage;
    out["power"]   = battery.power;
#endif
  };

  thing["EVENT"] >> [](pson & out)
  {
    out["peakTime"] = peakTime;
    out["peakValue"] = peakValue;
    out["aboveThreshLeq"] =  aboveThreshLEq;
    out["aboveThreshDuration"] = aboveThreshDuration;
    out["less10dBLeq"] =  less10dBLEq;
    out["less10dBDuration"] = less10dBDuration;
    out["NAT"] = NAT[Hour];
  };


  //Communication with Thinger.io
  thing.handle();
  delay(1000); // Wait for contact to happen.
  // Retrieve Persistance values

  pson persistance;
#if defined BATTERY_MONITORING
  thing.get_property("persistance", persistance);
  currentInt          = persistance["currentInt"];
  nCurrent            = persistance["nCurrent"];;
  mAhBat[27]          = persistance["Ah/hour"];
  mAhBat[26]          = persistance["Ah/yesterday"];
  voltageDelta        = persistance["voltageDelta"];
  voltageAt4h         = persistance["voltageAt4h"];
#endif
  leq[25]             = persistance["A0dBLEQ"];
  A0dBSumExp60min     = persistance["A0dBSumExp"];
  sound.A0dBBgr       = persistance["A0dBBgr"];
  corrdB              = persistance["corrdB"];
  A094                = persistance["A094"];
  A047                = persistance["A047"];

  outdoor_temperature = persistance["temperature"];
  outdoor_humidity    = persistance["humidity"];
  outdoor_pressure    = persistance["pressure"];
  outdoor_wind_speed  = persistance["wind"];
  outdoor_wind_direction = persistance["direction"];
  // weather_summary     = persistance["summary"];  //ambiguous overload for 'operator=' (operand types are 'String' and 'protoson::pson')

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
  thing.get_property("BAT", BATmAh);  // 0..23=hour, 25=current, 26=BATmAh 24h, 27= mAhBatDay, 28=mAhBatNight, 29=mAhBat22-24
  mAhBat[0]  = BATmAh["00h"];
  mAhBat[1]  = BATmAh["01h"];
  mAhBat[2]  = BATmAh["02h"];
  mAhBat[3]  = BATmAh["03h"];
  mAhBat[4]  = BATmAh["04h"];
  mAhBat[5]  = BATmAh["05h"];
  mAhBat[6]  = BATmAh["06h"];
  mAhBat[7]  = BATmAh["09h"];
  mAhBat[8]  = BATmAh["08h"];
  mAhBat[9]  = BATmAh["09h"];
  mAhBat[10] = BATmAh["10h"];
  mAhBat[11] = BATmAh["11h"];
  mAhBat[12] = BATmAh["12h"];
  mAhBat[13] = BATmAh["13h"];
  mAhBat[14] = BATmAh["14h"];
  mAhBat[15] = BATmAh["15h"];
  mAhBat[16] = BATmAh["16h"];
  mAhBat[17] = BATmAh["17h"];
  mAhBat[18] = BATmAh["18h"];
  mAhBat[19] = BATmAh["19h"];
  mAhBat[20] = BATmAh["20h"];
  mAhBat[21] = BATmAh["21h"];
  mAhBat[22] = BATmAh["22h"];
  mAhBat[23] = BATmAh["23h"];
  mAhBat[25] = BATmAh["LastHour"];
  mAhBat[26] = BATmAh["Yesterday"];
  mAhBat[27] = BATmAh["Today"];

#endif  //THINGER

// Initialisations.
  A094 = Ao94;
  A047 = Ao47;
  state = 'e';
  serialPage = '0';           // default reporting page
  sound.A0dBBgr = sound.A0dBMin = 40;     // default background and minimum level

  
#if defined (OFFLINE)
  Serial.println(F("Going off-line "));
  disConnect();
  Serial.println (F("Sketch is now running offline with own time"));
#endif

  ArduinoOTA.begin();
  Serial.println("\nOTA-Ready");
}
//end Setup