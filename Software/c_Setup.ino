void setup() {
  // Initialize Serial Victron
  //#if defined(TERM_IS_SOFTSER)
  //#if defined(D7_IS_VICTRON) || defined (D7_IS_DROK)
  //  SoftwareSerial SwSerial(1, 3);  // SoftwareSerial goes to the regular Serial ports
  //#else
  //  SoftwareSerial SwSerial(13, 15);  // SoftwareSerial goes to D7,D8
  //#endif
  //#endif

  // Serial initialisation
  Serial.begin(SERIAL_SPEED);  // On USB port
  Serial.setRxBufferSize(1024);
  // Serial.setDebugOutput(true);
  Serial.flush();

  delay(300);  // Wait for serial monitor to be started
  Serial.print("\n\n\nCompiled from: ");
  Serial.println(__FILE__);
  Serial.print("on ");
  Serial.print(__DATE__);
  Serial.print(" at ");
  Serial.println(__TIME__);
  Serial.printf("\n\n\nESP-Karajan at work,\nSerial @ %u Baud\n", SERIAL_SPEED);

  //Initialize I2C
  Wire.begin(SDA, SCL);

#ifdef RST
  pinMode(16, OUTPUT);
  digitalWrite(16, LOW);
  delay(10);
  digitalWrite(16, HIGH);
#endif

#if not defined(SCREEN_IS_NONE)
  //Initialize OLED Screens
  display.init();
  //  display.clear();
  display.setColor(WHITE);
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_10);
#ifdef SCREEN_IS_REVERSED
  display.flipScreenVertically();
#endif

  display.drawString(0, 0, "Device Name: ");
  display.drawString(64, 0, DEVICE_NAME);
  display.drawString(0, 12, "Try connect ");
  display.display();
#endif

  pinMode(LED_BUILTIN, OUTPUT);  // Onboard LED

  getWiFi();
  digitalWrite(LED_BUILTIN, false);

#if not defined(SCREEN_IS_NONE)
  buffShortIP();
  display.drawString(0, 24, charbuff);
  display.drawString(0, 36, "Connected");
  display.display();
  delay(2000);
#endif

  ArduinoOTA.setHostname(DEVICE_NAME);

  //WiFi.printDiag(Serial);
  Serial.printf("MAC: %s, Device: %s, IP: ", WiFi.macAddress().c_str(), DEVICE_NAME);
  Serial.println(WiFi.localIP());

  digitalWrite(LED_BUILTIN, true);

  getNTP();
  delay(NTP_DELAY);
  getEpoch();  // writes the Epoch (Numbers of seconds till 1.1.1970...
  Serial.print("Got Epoch, ");
  getTimeData();  // breaks down the Epoch into discrete values.
  buffTimeData();
  Serial.println(charbuff);

#if not defined(SCREEN_IS_NONE)
  display.drawString(0, 48, charbuff);
  display.display();
#endif

  initOTA();
  //  ArduinoOTA.setHostname(DEVICE_NAME);
  Serial.print("Start OTA, ");
  ArduinoOTA.begin();
  delay(500);



#if defined(TERM_IS_TELNET)
  TelnetStream.begin();
  Serial.println("Menu Ready on Telnet");
#endif

#ifndef UDP_IS_NONE
  UDP.begin(ESP_UDP_PORT);
  Serial.printf("Start UDP: %u\n", ESP_UDP_PORT);
#endif

#if defined(WEATHER_SOURCE_IS_BME680)
  bme.setTemperatureOversampling(BME680_OS_8X);
  bme.setHumidityOversampling(BME680_OS_2X);
  bme.setPressureOversampling(BME680_OS_4X);
#endif

  // IOT initialisation
#if defined(DASHBRD_IS_THINGER)

  thing.set_state_listener([&](ThingerClient::THINGER_STATE state) {
    switch (OFD_state) {
      case ThingerClient::THINGER_AUTHENTICATED:
        Serial.print("\nThinger Auth OK");
        break;
      case ThingerClient::THINGER_AUTH_FAILED:
        Serial.print("\n***Thinger Auth Fail***");
        break;
      case ThingerClient::NETWORK_CONNECT_ERROR:
      case ThingerClient::SOCKET_CONNECTION_ERROR:
      case ThingerClient::SOCKET_DISCONNECTED:
      case ThingerClient::SOCKET_ERROR:
      case ThingerClient::SOCKET_TIMEOUT:
        Console1.print("\n Network Error ! \n");
        GracePause = 64;
      default:
      break;
    }
  });

  // *** Thinger configuration ***
  // definition of structures for transmission
  // digital pin control example (i.e. turning on/off a light, a relay, configuring a parameter, etc)
  // resource output example (i.e. reading a sensor value) https://docs.thinger.io/coding#define-output-resources
  // https://docs.thinger.io/coding#read-multiple-data
  // it is a bit confusing, but Thinger code placed in setup will be executed when required by the payload.

  thing["menu"] << [](pson& in) {
    displayPage = in["displayPage"];
    serialPage = in["serialPage"];
    wirelessPage = in["wirelessPage"];
  };

  thing["noise"] >> [](pson& out) {
    out["min"] = sound.A0dBMin;
    out["slow"] = sound.A0dBSlow;
    out["backgr"] = sound.A0dBBgr;
    out["max"] = sound.A0dBMax;
    out["fast"] = sound.A0dBFast;
    out["impulse"] = sound.A0dBImpulse;
    out["limit"] = UPPER_LIMIT_DB;
    out["OFD_state"] = String(OFD_state);
  };

  thing["energy"] >> [](pson& out) {
    out["voltage"]       = payload.BatV;
    out["panel"]         = payload.PanV;
    out["current"]       = payload.BatI;
    out["power"]         = payload.BatW;
    out["int_resistance"] = payload.IOhm * 1000;
    out["percent_charg"] = payload.BatPoC;
  };

  thing["DAY"] >> [](pson& out) {
    out["Device"] = DEVICE_NAME;
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
  };

  thing["HOUR"] >> [](pson& out) {
    out["temperature"] = temperature;
    out["humidity"] = humidity;
    out["pressure"] = pressure;
    out["wind"] = wind_speed;
    out["direction"] = wind_direction;
    out["summary"] = weather_summary;

    out["BatV"] = payload.BatV;
    out["BatI"] = payload.BatI;
    out["BatW"] = payload.BatW;
    out["PanV"] = payload.PanV;
    out["Bat%"] = payload.BatPoC;
  };

  thing[BUCKET_MIN] >> [](pson& out) {
    out["min"] = A0dBMin1min;
    out["LEq"] = A0dBLeq1min;
    out["LEtr"] = A0dBtrend;
    out["max"] = A0dBMax1min;
    out["backgr"] = sound.A0dBBgr;

    out["BatI"] = payload.BatI;
    out["BatV"] = payload.BatV;
    out["BatW"] = payload.BatW;
    out["PanV"] = payload.PanV;
    out["Bat%"] = payload.BatPoC;
  };

  thing[BUCKET_EVENT] >> [](pson& out) {
    out["peakTime"] = peakTime;
    out["eventPeak"] = peakValue;
    out["aboveThreshLe"] = aboveThreshLE;
    out["aboveThreshLeq"] = aboveThreshLEq;
    out["aboveThreshDuration"] = aboveThreshDuration;
    out["less10dBLe"] = less10dBLE;
    out["less10dBLeq"] = less10dBLEq;
    out["less10dBDuration"] = less10dBDuration;
    out["NAT"] = NAT[Hour];
  };

  //Communication with Thinger.io
  thing.handle();
  delay(1000);  // Wait for contact to happen.
  // Retrieve Persistance values

  pson persistance;
  thing.get_property("persistance", persistance);
  temperature = persistance["temperature"];
  humidity = persistance["humidity"];
  pressure = persistance["pressure"];
  wind_speed = persistance["wind"];
  wind_direction = persistance["direction"];

  leq[25] = persistance["A0dBLEQ"];
  A0dBSumExp60min = persistance["A0dBSumExp"];
  aboveThreshLEint = persistance["aboveThreshLEint"];
  less10dBLEint = persistance["less10dBLEint"];
  sound.A0dBBgr = persistance["A0dBBgr"];
  corrdB = persistance["corrdB"];
  A094 = persistance["A094"];
  A047 = persistance["A047"];

  pson whoami;                      //Setting IP and Version reminder property on thinger
  whoami["IP"] = WiFi.macAddress().c_str();
  whoami["Soft"] = __FILE__;
  whoami["Date"] = __DATE__;
  whoami["Time"] = __TIME__;
  thing.set_property("whoami", whoami, true);

  pson config;
  config["windLimit"] = WIND_LIMIT;
  config["UpperDB"] = UPPER_LIMIT_DB;
  config["LowerDB"] = LOWER_LIMIT_DB;
  config["EventTreshold"] = EVENT_THRESHOLD_LEVEL;
  config["NATTreshold"] = NAT_THRESHOLD_LEVEL;
  config["MeasTreshold"] = MEASUREMENT_THRESHOLD_LEVEL;
  config["MinExcTime"] = MIN_EXCEEDANCE_TIME;
  config["MaxExcTime"] = MAX_EXCEEDANCE_TIME;
  config["ListenTime"] = LISTENING_TIME;
  thing.set_property("config", config, true);


  pson lequ;
  thing.get_property("lequ", lequ);  // 0..23=hour, 25=current, 26=Lequ 24h, 27= LeqDay, 28=LeqNight, 29=Lden
  leq[0] = lequ["00h"];
  leq[1] = lequ["01h"];
  leq[2] = lequ["02h"];
  leq[3] = lequ["03h"];
  leq[4] = lequ["04h"];
  leq[5] = lequ["05h"];
  leq[6] = lequ["06h"];
  leq[7] = lequ["09h"];
  leq[8] = lequ["08h"];
  leq[9] = lequ["09h"];
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
  NAT[0] = NATu["00h"];
  NAT[1] = NATu["01h"];
  NAT[2] = NATu["02h"];
  NAT[3] = NATu["03h"];
  NAT[4] = NATu["04h"];
  NAT[5] = NATu["05h"];
  NAT[6] = NATu["06h"];
  NAT[7] = NATu["09h"];
  NAT[8] = NATu["08h"];
  NAT[9] = NATu["09h"];
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

#endif  // defined (DASHBRD_IS_THINGER)

  // Initialisations.
  if (A094 == 0) A094 = Ao94;  // uninitialized or no Thinger
  if (A047 == 0) A047 = Ao47;  // uninitialized or no Thinger

  OFD_state = 'o';  // event detection idle
  // *** Defaults to start with ***
  wirelessPage = ' ';
  serialPage = 'A';  // Always start with AK Modulbus
  displayPage = '1';


  if (sound.A0dBBgr < LOWER_LIMIT_DB) sound.A0dBBgr = LOWER_LIMIT_DB;  // default background and minimum level
  //  digitalWrite(LED_BUILTIN, true);
  Serial.flush();

  Serial.print("\nNAT|PKTime  |PKdB|Leq4|t10|Leq3|\n");
}
//end Setup
