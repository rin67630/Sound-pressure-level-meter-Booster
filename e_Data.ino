void data125mSRun()
{
  // === ( Getting noise level from A0 ) ===
#if defined (SOUND_SOURCE_IS_A0)
  // Performing 3 reads to get a reliable reading.
  A0Raw = analogRead(A0); // 1st read  0...1V = 0 ..1023
  delay(3);
  A0Raw += analogRead(A0); // 2nd read
  delay(3);
  A0Raw += analogRead(A0); // 3rd read
  A0Raw = A0Raw / 3;

  // Compute linear function: 47dB (difference between 47 and 94dB) / difference between the 2 calibration results
  A0Inst = map(A0Raw, A047, A094, 4700, 9400);
  A0dBAvg   = float(A0Inst) / 100 + corrdB;
  sound.A0dBFast = sound.A0dBFast + (A0dBAvg - sound.A0dBFast) / 2;
  sound.A0dBMin  = min(sound.A0dBFast, sound.A0dBMin);
  sound.A0dBMax  = max(sound.A0dBFast, sound.A0dBMax);
  A0dBMin1min = min(sound.A0dBFast, A0dBMin1min);
  A0dBMax1min = max(sound.A0dBFast, A0dBMax1min);

  // === (Slow (attack t=1s, decay 2,9dB/s)
  if ( sound.A0dBFast > sound.A0dBSlow)                      //A0 in dB with impulse response
  {
    sound.A0dBSlow += (sound.A0dBFast - sound.A0dBSlow) / 8; // Low Pass filter 1s
  }
  else
  {
    sound.A0dBSlow = sound.A0dBSlow - 0.3625;                //Linear decay 2,9db /sec
  }
  // Impulse (attack t=0,35s, decay 4,3dB/s)
  if ( A0dBAvg > sound.A0dBImpulse)                          //A0 in dB with impulse response
  {
    sound.A0dBImpulse = A0dBAvg;                             //No filter, the response of the SPL is slower
  }
  else
  {
    sound.A0dBImpulse = sound.A0dBImpulse - 0.5375 ;         //Linear decay 4,3db /sec
  }
  sound.A0dBImpulse = max(sound.A0dBImpulse, sound.A0dBSlow);
#else
  yield();
#endif //defined (SOUND_SOURCE_IS_A0)
}

void data1SRun()
{
  yield();




  // === (Fetching Noise level from URL with reduced resolution
#if defined (SOUND_SOURCE_IS_URL) || defined (SOUND_SOURCE_IS_FOO)  // must be a JSON from DFLD.de or FOO server.
  HTTPClient http;

#if defined (SOUND_SOURCE_IS_URL)
  http.begin(WifiClient, DFLD_URL);      //Specify request destination
#endif
#if defined (SOUND_SOURCE_IS_FOO)
  http.begin(WifiClient, FOO_URL);      //Specify request destination
#endif

  int httpCode1 = http.GET();            //Send the request
  if (httpCode1 == HTTP_CODE_OK)                                                     //Check the returning code
  {
    JSONpayload = http.getString();                                                  //Get the request response payload
    // it should be like: {"generator":"DFLD_LIVE","version":"0.9","time":1587592375,"access-control":"ignoredWrongPWD","027":32.0}
#if defined (SOUND_SOURCE_IS_URL)
    JSONpayload = JSONpayload.substring(100, 104);                                   // taking only the dB value from DFLD JSON
#endif
    http.end();   //Close connection
  }

  sound.A0dBFast = JSONpayload.toFloat();

  if (sound.A0dBFast < (sound.A0dBBgr - 5)) sound.A0dBFast = sound.A0dBBgr + random(-1, 1);   //masquerade shutdowns

  sound.A0dBMin = min(sound.A0dBFast, sound.A0dBMin);
  sound.A0dBMax = max(sound.A0dBFast, sound.A0dBMax);
  sound.A0dBSlow = sound.A0dBFast;    //Kein Low Pass filter 6 sec

  // =================== getting dB values from another station instead of impulse

#if defined (SOUND_SOURCE_IS_FOO)
  http.begin(WifiClient, DFLD_URL);      //Specify request destination
  httpCode1 = http.GET();            //Send the request
  if (httpCode1 == HTTP_CODE_OK)                                                     //Check the returning code
  {
    JSONpayload = http.getString();                                                  //Get the request response payload
    // it should be like: {"generator":"DFLD_LIVE","version":"0.9","time":1587592375,"access-control":"ignoredWrongPWD","027":32.0}
    JSONpayload = JSONpayload.substring(100, 104);                                   // taking only the dB value from DFLD JSON
    http.end();   //Close connection
  }
  sound.A0dBImpulse = JSONpayload.toFloat();
#else  //defined (SOUND_SOURCE_IS_URL)
  if ( sound.A0dBFast > sound.A0dBImpulse)           //A0 in dB with impulse response
  {
    sound.A0dBImpulse = sound.A0dBFast;              //No filter
  }
  else
  {
    sound.A0dBImpulse = sound.A0dBImpulse - 4.3 ; //Linear decay 4,3db /sec
  }
#endif //defined (SOUND_SOURCE_IS_FOO /)

#endif  //defined (SOUND_SOURCE_IS_URL) || defined (SOUND_SOURCE_IS_FOO)

  // ====================================================

#if defined (SOUND_SOURCE_IS_UDP) || defined (BATTERY_SOURCE_IS_UDP)   // === (Getting Sound / Battery values from another ESP over UDP

  // I use a quick and dirty method called 'type punning' copying the memory block of a structure into an array of chars,
  // transmitting this array, and copying back the memory block of the array into the same structure on the other side.
  // I dont use any header info, only the difference of size permits to assign the received packets to sound or battery.
  // it is quick and damn efficient, but NOT portable and YOU must take care to have the same structures on both systems
  // and different sizes for Battery and Sound...

  int packetSize = UDP.parsePacket();
  // if (packetSize) Console3.printf("Packet size: %u, Sound size: %u , Battery size; %u \n", packetSize, sizeof(sound), sizeof(battery));
  // if (packetSize) digitalWrite(STDLED, false);    // Blink built-in LED on received packets
  if (packetSize == sizeof(sound))
  {
    UDP.read(soundPayload, UDP_TX_PACKET_MAX_SIZE);
    memcpy(&sound, soundPayload, sizeof(sound));
    // Console1.printf("Min:%2.1f Max:%2.1f Imp:%2.1f  Bgr:%2.1f Slow:%2.1f\n", sound.A0dBMin, sound.A0dBMax, sound.A0dBImpulse, sound.A0dBBgr, sound.A0dBSlow);
    //     Console1.print("s");
  }
  if (packetSize == sizeof(battery))
  {
    UDP.read(batteryPayload, UDP_TX_PACKET_MAX_SIZE);
    memcpy(&battery, batteryPayload, sizeof(battery));
    // Console1.printf("Ah: %2.1f, Volt: %2.1f, Amp: %2.1f, Watt: %2.1f, %%Batt: %2.1f\n", AhBat, battery.voltage , battery.current , battery.power , percent_charged);
    delay(3);    // let built-in LED blink slightly stronger on battery packet
  }
  //digitalWrite(STDLED, true);
#endif //defined (SOUND_SOURCE_IS_UDP) || defined (BATTERY_SOURCE_IS_UDP)

  //=== (DFLD Formatting (AK Modulbus format)
  sound.A0dBAK = 50 + int(2 * sound.A0dBFast);                  // Reduction to 1 Byte 50...250
  //A0dBArray[60 * Minute + Second] = sound.A0dBAK;
  //sound.A0dBImpulse = max(sound.A0dBImpulse, sound.A0dBSlow);

  // === (Computing Background noise level with a low pass filter ignoring events
  if ( sound.A0dBFast < EVENT_THRESHOLD_LEVEL)
  {
    sound.A0dBBgr += (sound.A0dBSlow - sound.A0dBBgr) / 2000;  // Low Pass filter 2000s
  }

  // === (Noise averaging & 60s Max-Min
  A0dBSum6S += sound.A0dBSlow;  // Noise simple Averaging 6 Seconds
  nA0dB6S++;
  A0dB6S =  A0dBSum6S / nA0dB6S;
  A0dBMin1min = min(sound.A0dBSlow, A0dBMin1min);
  A0dBMax1min = max(sound.A0dBImpulse, A0dBMax1min);


  // === (Getting Weather from OpenWeatherMap every 15 minutes
#if defined WEATHER_SOURCE_IS_URL
  if (Minute % 15 == 1 && Second == 32)                    // call every 15 minutes
  {
    HTTPClient http;
    http.begin(WifiClient, OPEN_WEATHER_MAP_URL);
    int httpCode2 = http.GET();
    if (httpCode2 == HTTP_CODE_OK)
    {
      JSONpayload = http.getString();
      DynamicJsonDocument doc(1024);
      auto error = deserializeJson(doc, JSONpayload.c_str());
      if ( not error)
      {
        temperature          = doc["main"]["temp"];
        pressure             = doc["main"]["pressure"];
        humidity             = doc["main"]["humidity"];
        wind_speed           = doc["wind"]["speed"];
        wind_direction       = doc["wind"]["deg"];
        cloudiness           = doc["clouds"]["all"];  // % Clouds
        const char* w        = doc["weather"][0]["description"]; weather_summary = w;
        sunrise              = doc["sys"]["sunrise"];
        sunset               = doc["sys"]["sunset"];
      }
    }
    http.end();
  }
#endif  //defined WEATHER_SOURCE_IS_URL
#if defined(WEATHER_SOURCE_IS_BME680)
  temperature = bme.temperature;
  pressure = bme.pressure;
  humidity = bme.humidity;
#endif


  // === ( Getting panel voltage from A0 ) ===
#if defined (PANEL_VOLTAGE_IS_A0)
  // Performing 3 reads to get a reliable reading.
  A0Raw = analogRead(A0); // 1st read  0...1V = 0 ..1023
  delay(3);
  A0Raw += analogRead(A0); // 2nd read
  delay(3);
  A0Raw += analogRead(A0); // 3rd read
  A0Raw = A0Raw / 3;
  battery.panel += (float(map(A0Raw, 0, 1023, 0, PANEL_MAX)) / 1000 - battery.panel) / 10; // Volt Smoothed 10seconds
#endif  //defined (PANEL_VOLTAGE_IS_A0)

  //=== ( Measure Battery
#if defined BATTERY_SOURCE_IS_INA
  // Battery measurements from INA226
  float v = ina_voltage;
  float w = ina_current;
  ina_voltage   = INA.getBusMilliVolts(0);
  ina_shunt     = INA.getShuntMicroVolts(0);
  ina_current   = INA.getBusMicroAmps(0);
  ina_power     = INA.getBusMicroWatts(0);
  delta_voltage = ina_voltage - v;          // mV
  delta_current = (ina_current - w) / 1000;  // mA

  voltage += (ina_voltage / 1000   - voltage) / 10; // Volt Smoothed 10seconds
#ifdef SHUNT_REVERSED
  current += (ina_current / -1000000 - current) / 10; // Ampere Smoothed 10seconds, set divisor negative to reverse current if required
#else
  current += (ina_current / 1000000 - current) / 10; // Ampere Smoothed 10seconds, set divisor negative to reverse current if required
#endif
  battery.voltage = voltage;
  battery.current = current;
  battery.power = voltage * current;

  if (Hour < 4)   //Internal resistance evaluated during night, when no solar influence is expected. A load that generates sometimes peaks >50mA is requested for entropy.
  {
    // Evaluate battery internal resistance (r = dv / di) if deltaCurrent > 50mA.
    if (fabs(delta_current) > 50) battery.ohm = fabs(delta_voltage / delta_current);
  }
#endif //defined (PANEL_VOLTAGE_IS_INA)

#if defined BATTERY_SOURCE_IS_INA || defined BATTERY_SOURCE_IS_UDP
  // continuing either with values from above, or from UDP transmission
  if (NewMinute)
  {
    // Evaluate battery charge
    float d = 0;
    if (battery.current >= 0.3)
    {
      d = 500;   // mV
    }
    else if (battery.current <= 0.3)
    {
      d = -500;   // mV
    }
    percent_charged = map(battery.voltage * 1000, MIN_VOLT * 1000 + d, MAX_VOLT * 1000 + d - 800, 0, 100);
    percent_charged = constrain( percent_charged, 0, 100);
  }// end if new minute

  //=== ( Daily Battery voltage comparison just before midnight
  if (SecondOfDay == 86000) voltageAt0H  = battery.voltage;               // taking the voltage at 23:55 to evaluate if the battery gained/lost during the previous day.
  if (SecondOfDay == 85899) voltageDelta = battery.voltage - voltageAt0H; // set ranges at 33:53:59

  //=== ( Battery Stat integration
  currentInt += battery.current;
  nCurrent ++;

  if (HourExpiring)
  {
    AhBat[Hour] = currentInt / nCurrent;
    nCurrent = 0;
    currentInt = 0;
    AhBat[25] = AhBat[Hour];   //last hour
    AhBat[27] = 0;              // today (0h->current hour)
    for  (byte n = 0; n < Hour; n++)
    {
      AhBat[27] = AhBat[27] + AhBat[n];
    }
  } // end hour expiring

  if (DayExpiring)
  {
    AhBat[26] = AhBat[27];
  }
#endif // defined BATTERY_SOURCE_IS_INA || defined BATTERY_SOURCE_IS_UDP

} // end of 1S run
