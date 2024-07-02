void data1SRun() {
  yield();

  // === (Fetching Noise level from URL with reduced resolution
#if defined(SOUND_SOURCE_IS_URL) || defined(SOUND_SOURCE_IS_FOO)  // must be a JSON from DFLD.de or FOO server.
  HTTPClient http;

#if defined(SOUND_SOURCE_IS_URL)
  http.begin(wifiClient, DFLD_URL);  //Specify request destination
#endif
#if defined(SOUND_SOURCE_IS_FOO)
  http.begin(wifiClient, FOO_URL);  //Specify request destination
#endif

  int httpCode1 = http.GET();     //Send the request
  if (httpCode1 == HTTP_CODE_OK)  //Check the returning code
  {
    JSONpayload = http.getString();  //Get the request response payload
                                     // it should be like: {"generator":"DFLD_LIVE","version":"0.9","time":1587592375,"access-control":"ignoredWrongPWD","027":32.0}
#if defined(SOUND_SOURCE_IS_URL)
    JSONpayload = JSONpayload.substring(100, 104);  // taking only the dB value from DFLD JSON
#endif
    http.end();  //Close connection
  }

  sound.A0dBFast = JSONpayload.toFloat();

  if (sound.A0dBFast < (sound.A0dBBgr - 5)) sound.A0dBFast = sound.A0dBBgr + random(-1, 1);  //masquerade shutdowns

  sound.A0dBMin = min(sound.A0dBFast, sound.A0dBMin);
  sound.A0dBMax = max(sound.A0dBFast, sound.A0dBMax);
  sound.A0dBSlow = sound.A0dBFast;  //Kein Low Pass filter 6 sec

  // =================== getting dB values from another station instead of impulse

#if defined(SOUND_SOURCE_IS_FOO)
  http.begin(wifiClient, DFLD_URL);  //Specify request destination
  httpCode1 = http.GET();            //Send the request
  if (httpCode1 == HTTP_CODE_OK)     //Check the returning code
  {
    JSONpayload = http.getString();  //Get the request response payload
    // it should be like: {"generator":"DFLD_LIVE","version":"0.9","time":1587592375,"access-control":"ignoredWrongPWD","027":32.0}
    JSONpayload = JSONpayload.substring(100, 104);  // taking only the dB value from DFLD JSON
    http.end();                                     //Close connection
  }
  sound.A0dBImpulse = JSONpayload.toFloat();
#else   //defined (SOUND_SOURCE_IS_URL)
  if (sound.A0dBFast > sound.A0dBImpulse)  //A0 in dB with impulse response
  {
    sound.A0dBImpulse = sound.A0dBFast;  //No filter
  } else {
    sound.A0dBImpulse = sound.A0dBImpulse - 4.3;  //Linear decay 4,3db /sec
  }
#endif  //defined (SOUND_SOURCE_IS_FOO /)

#endif  //defined (SOUND_SOURCE_IS_URL) || defined (SOUND_SOURCE_IS_FOO)

// Geeting sound over UDP moved to Wireless

  //=== (DFLD Formatting (AK Modulbus format)
  sound.A0dBAK = 50 + int(2 * sound.A0dBFast);  // Reduction to 1 Byte 50...250
  //A0dBArray[60 * Minute + Second] = sound.A0dBAK;
  //sound.A0dBImpulse = max(sound.A0dBImpulse, sound.A0dBSlow);

  // === (Computing Background noise level with a low pass filter ignoring events
  if (sound.A0dBFast < EVENT_THRESHOLD_LEVEL) {
    sound.A0dBBgr += (sound.A0dBSlow - sound.A0dBBgr) / 2000;  // Low Pass filter 2000s
  }

  // === (Noise averaging & 60s Max-Min
  A0dBSum6S += sound.A0dBSlow;  // Noise simple Averaging 6 Seconds
  nA0dB6S++;
  A0dB6S = A0dBSum6S / nA0dB6S;
  A0dBMin1min = min(sound.A0dBSlow, A0dBMin1min);
  A0dBMax1min = max(sound.A0dBImpulse, A0dBMax1min);


  // === (Getting Weather from OpenWeatherMap every 15 minutes
#if defined WEATHER_SOURCE_IS_OWM
  if (Minute % 15 == 1 && Second == 32)  // call every 15 minutes
  {
    http.begin(wifiClient, OPEN_WEATHER_MAP_URL);
    int httpCode2 = http.GET();
    if (httpCode2 == HTTP_CODE_OK) {
      JSONpayload = http.getString();
      JsonDocument doc;
      auto error = deserializeJson(doc, JSONpayload.c_str());
      if (not error) {
        temperature = doc["main"]["temp"];
        pressure = doc["main"]["pressure"];
        humidity = doc["main"]["humidity"];
        wind_speed = doc["wind"]["speed"];
        wind_direction = doc["wind"]["deg"];
        cloudiness = doc["clouds"]["all"];  // % Clouds
        const char* w = doc["weather"][0]["description"];
        weather_summary = w;
        sunrise = doc["sys"]["sunrise"];
        sunset = doc["sys"]["sunset"];
      }
    }
    http.end();
  }
#endif  //defined WEATHER_SOURCE_IS_OWM
#if defined(WEATHER_SOURCE_IS_BME680)
  temperature = bme.temperature;
  pressure = bme.pressure;
  humidity = bme.humidity;
#endif



}  // end of 1S run
