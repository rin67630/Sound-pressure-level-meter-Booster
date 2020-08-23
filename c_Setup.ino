void setup()
{
  delay(3000); // Wait for serial monitor to be started
  // Serial initialisation
  Serial.begin (SERIAL_SPEED); // On USB port
  Serial1.begin(SERIAL_SPEED); // On GPIO2 / D4
  Wire.begin(SDA, SCL);
  Console3.printf("\n\n\nESP-Karajan at work,\nHello Serial! @ %u Baud\n", SERIAL_SPEED);

  EEPROM.begin(512);
  if (!SPIFFS.begin()) 
{
  Console3.println("Failed to mount file system");
  return;
}
  pinMode(RELAY , OUTPUT);
//  pinMode(STDLED, OUTPUT);
  // Witty Color LEDs
  /*
  pinMode(REDLED, OUTPUT);
  pinMode(GRNLED, OUTPUT);
  pinMode(BLULED, OUTPUT); 
  */   
 
   // Networking and Time
  getWiFi();
  ArduinoOTA.setHostname(HOST_NAME);

  //WiFi.printDiag(Serial);
  Console3.printf("MAC address: %s , \nHostname: %s \nIP address::", WiFi.macAddress().c_str(), WiFi.hostname().c_str());
  Console3.println(WiFi.localIP());
  getNTP();
  delay(3000);

  getEpoch();            // writes the Epoch (Numbers of seconds till 1.1.1970...
  getTimeData();         // breaks down the Epoch into discrete values.
  sprintf(charbuff, "Now is %02d:%02d:%02d. The Epoch is: %10lu\r\nDate is %s, %02d %s %04d" , Hour , Minute, Second, Epoch,DayName , Day , MonthName, Year);
  Console3.println(charbuff);

  //  delay(3000);
  getEpoch();            // writes the Epoch (Numbers of seconds till 1.1.1970...
  getTimeData();         // breaks down the Epoch into discrete values.
  //  Console3.print(F("\nNow, 3 seconds later it is "));   Console3.println( Time );

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

  // Begin listening to UDP port
  UDP.begin(UDP_PORT);
  Console3.print("Communicating on UDP port: ");
  Console3.print(UDP_PORT);

  // Weather
  myPlace.setLocation( 51.3683, 6.9293 );
  myPlace.setUnit("metric");

#if defined BATTERY_SOURCE_INA
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
#else
  battery.voltage = (MAX_VOLT + MIN_VOLT) / 2;
  battery.current = 0;
#endif

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
    out["limit"]     = UPPER_LIMIT_DB;
  };

  thing["energy"] >> [](pson & out)
  {
    out["voltage"]           = battery.voltage;
    out["current"]           = battery.current;
    out["power"]             = battery.power;
    out["interal_resitance"] = internal_resistance;
    out["percent_charged"]   = percent_charged;
  };

  thing["DAY"] >> [](pson & out)
  {
    out["AhBat[26]"] = AhBat[26];
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
#if (defined BATTERY_SOURCE_INA) || (defined BATTERY_SOURCE_UDP)
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
    out["backgr"]  = sound.A0dBBgr;

#if (defined BATTERY_SOURCE_INA) || (defined BATTERY_SOURCE_UDP)
    out["voltage"] = battery.voltage;
    out["power"]   = battery.power;
    out["voltage"]     = battery.voltage;    
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
#if (defined BATTERY_SOURCE_INA) || (defined BATTERY_SOURCE_UDP)
  thing.get_property("persistance", persistance);
  currentInt          = persistance["currentInt"];
  nCurrent            = persistance["nCurrent"];;
  AhBat[27]           = persistance["Ah/hour"];
  AhBat[26]           = persistance["Ah/yesterday"];
  voltageDelta        = persistance["voltageDelta"];
  voltageAt4h         = persistance["voltageAt4h"];
  internal_resistance = persistance["resistance"];
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
  leq[30] = lequ["L22-24h"];

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

#else // no Thinger

  // to be done: Persistance over Structure and memcpy.
  //EEPROM.get(addr,data);
  //EEPROM.put(addr,data);
  //EEPROM.commit();

#endif  //THINGER

  // Initialisations.
  if (A094 == 0) A094 = Ao94; // uninitialized or no Thinger
  if (A047 == 0) A047 = Ao47; // uninitialized or no Thinger

  state = 'e';
  serialPage = 'A';           // default reporting page
  if (sound.A0dBBgr < LOWER_LIMIT_DB) sound.A0dBBgr = LOWER_LIMIT_DB;
  sound.A0dBMin = LOWER_LIMIT_DB;     // default background and minimum level
//  digitalWrite(STDLED, true);
  
#if defined (OFFLINE)
  Console3.println(F("Going off-line "));
  disConnect();
  Console3.println (F("Sketch is now running offline with own time"));
#endif

  ArduinoOTA.begin();
  Console3.println("\nOTA-Ready");
  Console2.print("\nNAT|PKTime  |PKdB|Leq4|t10|Leq3|\n");
}
//end Setup
