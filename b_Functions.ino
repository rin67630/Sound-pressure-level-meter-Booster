// Macro for Timing
#define runEvery(t) for (static uint16_t _lasttime;\
                         (uint16_t)((uint16_t)millis() - _lasttime) >= (t);\
                         _lasttime += (t))

// Instantiate classes
WiFiUDP    UDP;
#if defined(BATTERY_SOURCE_IS_INA)
INA_Class  INA;
#endif
WiFiClient WifiClient;
HTTPClient http;

#if defined (THINGER)
ThingerESP8266 thing(THINGER_USERNAME, THINGER_DEVICE, THINGER_CREDENTIALS);
#endif

// Functions

// WiFi Managemement
void getWiFi()              // From Memory , Using Defaults, or using SmartConfig
{
  int retry = 0;
  WiFi.mode(WIFI_STA);      // configure WiFi in Station Mode
  wifi_station_set_hostname(HOST_NAME);
  wifi_station_set_auto_connect(true);
  delay(wifiRepeatInterval);
  Console3.println("Attempt to connect to WiFi network from EEPROM");
  WiFi.begin();
  delay(wifiRepeatInterval);
  while (WiFi.status() != WL_CONNECTED)
  {
    Console3.print(".");
    digitalWrite(STDLED, not digitalRead(STDLED));
    delay(wifiRepeatInterval) ;
    if (retry++ >= wifiMaxTries) break;
  }

  if (WiFi.status() != WL_CONNECTED)
  {
    Console3.println("\nConnection timeout expired! Start with default");
    retry = 0;
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    delay(wifiRepeatInterval * 2 );
    while (WiFi.status() != WL_CONNECTED)
    {
      Console3.print(".");
      digitalWrite(STDLED, not digitalRead(STDLED));
      delay(wifiRepeatInterval);
      if (retry++ >= wifiMaxTries) break;
    }
  }
  if (WiFi.status() != WL_CONNECTED)
  {
    Console3.println("Connection timeout expired! Start SmartConfig…");
    retry = 0;
    WiFi.beginSmartConfig();
    digitalWrite(STDLED, false);
    while (WiFi.status() != WL_CONNECTED)
    {
      Console3.print(".");
      digitalWrite(STDLED, not digitalRead(STDLED));
      delay(wifiRepeatInterval * 4);
      if (retry++ >= wifiMaxTries) break;
      if (WiFi.smartConfigDone())
      {
        Console3.println("SmartConfig success!");
        break; // exit from loop
      }
    }
  }

  if (WiFi.status() != WL_CONNECTED)
  {
    Console3.println("Connection timeout expired! Running without Network");
    WiFi.mode(WIFI_OFF);
  } else {
    ip = WiFi.localIP();
    Console3.println("Connection succeeded");
    WiFi.printDiag(Console3);

    // show the IP address assigned to our device
    Console3.println(WiFi.localIP());
    digitalWrite(STDLED, true);
  }
} // End Void GetWiFi

void disConnect()
{
  //  WiFi.disconnect(); //temporarily disconnect WiFi as it's no longer needed
  WiFi.mode(WIFI_OFF);
  // WiFi.forceSleepBegin();  can it save power?
  // WiFi.forceSleepWake();
}

void myIP()
{
  sprintf(charbuff, "IP= %03d.%03d.%03d.%03d", ip[0], ip[1], ip[2], ip[3]);
}

// Time management
void getNTP()
{
  if (WiFi.status() == WL_CONNECTED)
  {
    configTime(MYTZ, NTP_SERVER);
    now = 1577833200000;   //01 Jan 2020 12:00
  }
  now = time(nullptr);
  Epoch = now;
}

void getEpoch()
{
  now = time(nullptr);
  Epoch = now;
}

void getTimeData()
{
  timeinfo  = localtime(&now);  // cf: https://www.cplusplus.com/reference/ctime/localtime/
  Second    = timeinfo->tm_sec;
  Minute    = timeinfo->tm_min;
  Hour      = timeinfo->tm_hour;
  Weekday   = timeinfo->tm_wday + 1 ;
  Day       = timeinfo->tm_mday;
  Month     = timeinfo->tm_mon + 1;
  Year      = timeinfo->tm_year + 1900; //returns years since 1900

  strftime (DayName , 12, "%A", timeinfo); //cf: https://www.cplusplus.com/reference/ctime/strftime/
  strftime (MonthName, 12, "%B", timeinfo);
  strftime (Time, 10, "%T", timeinfo);
  strftime (Date, 12, "%d/%m/%Y", timeinfo);
}
