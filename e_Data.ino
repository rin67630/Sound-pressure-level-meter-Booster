void data125mSRun()
{
  //  Serial.print("'");
#if defined (SOUNDSOURCE_ANAIN)
  // === ( Short Leq from A0 ) ===
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
  
// Slow (attack t=1s, decay 2,9dB/s)
  if ( sound.A0dBFast > sound.A0dBSlow)              //A0 in dB with impulse response
  {
    sound.A0dBSlow += (sound.A0dBFast - sound.A0dBSlow) / 8; // Low Pass filter 1s
  }
  else
  {
    sound.A0dBSlow = sound.A0dBSlow - 0.3625;        //Linear decay 2,9db /sec
  }
// Impulse (attack t=0,35s, decay 4,3dB/s)
  if ( A0dBAvg > sound.A0dBImpulse)           //A0 in dB with impulse response
  {
    sound.A0dBImpulse = A0dBAvg;              //No filter, the response of the SPL is slower
  }
  else
  {
    sound.A0dBImpulse = sound.A0dBImpulse - 0.5375 ; //Linear decay 4,3db /sec
  }
  sound.A0dBImpulse = max(sound.A0dBImpulse,sound.A0dBSlow);

// Background 
  if ( sound.A0dBFast < EVENT_THRESHOLD_LEVEL)  //Low pass filter ignoring events
  {
    sound.A0dBBgr += (sound.A0dBFast - sound.A0dBBgr) /16000;   // Low Pass filter 2000s
  }
  
#else
  yield();
#endif
}

void data1SRun()
{
  yield();
  //  Serial.print("Da");

  // Fetching Noise level from URL
#if defined (SOUNDSOURCE_URL)   // must be a JSON from DFLD.de
  HTTPClient http;              //Declare an object of class HTTPClient
  http.begin(DFLDjsonURL);      //Specify request destination
  int httpCode = http.GET();    //Send the request
  if (httpCode > 0)             //Check the returning code
  {
    JSONpayload = http.getString();          //Get the request response payload
    // it should be: {"generator":"DFLD_LIVE","version":"0.9","time":1587592375,"access-control":"ignoredWrongPWD","027":32.0}
    JSONpayload = JSONpayload.substring(100, 104);

    sound.A0dBFast = JSONpayload.toFloat();
    A0Inst = 100 * sound.A0dBFast;
    sound.A0dBMin = min(sound.A0dBFast, sound.A0dBMin);
    sound.A0dBMax = max(sound.A0dBFast, sound.A0dBMax);
    A0dBMin1min = min(sound.A0dBFast, A0dBMin1min);
    A0dBMax1min = max(sound.A0dBFast, A0dBMax1min);
    sound.A0dBSlow += (sound.A0dBFast - sound.A0dBSlow) / 6; // Low Pass filter 6 sec
  }
  http.end();   //Close connection
#endif

#if defined (SOUNDSOURCE_UDP)

int packetSize = UDP.parsePacket();
if (packetSize)
{
 UDP.read(soundPayload, UDP_TX_PACKET_MAX_SIZE);
}
if (packetSize == sizeof(sound))
{
// Serial.print(" soundPayload: ");
// Serial.println(soundPayload);
 memcpy(&sound, soundPayload, sizeof(sound)); 
}
if (packetSize == sizeof(battery))
{
// Serial.print(" batteryPayload: ");
// Serial.println(batteryPayload);
 memcpy(&battery, batteryPayload, sizeof(battery)); 
}

#endif

  //DFLD Formatting (AK Modulbus format)
  sound.A0dBAK = 50 + int(2 * sound.A0dBFast);                  // Reduction to 1 Byte 50...250
  A0dBArray[60 * Minute + Second] = sound.A0dBAK;

  // Noise averaging
  A0dBSum6S += sound.A0dBSlow;  // Noise simple Averaging 6 Seconds
  nA0dB6S++;
  A0dB6S =  A0dBSum6S / nA0dB6S;

  if ( sound.A0dBFast > sound.A0dBImpulse)           //A0 in dB with impulse response
  {
    sound.A0dBImpulse = sound.A0dBImpulse + (A0dB6S - sound.A0dBImpulse) / 4;
  }
  else
  {
    sound.A0dBImpulse = sound.A0dBImpulse + (A0dB6S - sound.A0dBImpulse) / 150;
  }
  // Noise Lequ integration
  A0dBSumExp60min =  A0dBSumExp60min + pow(10, sound.A0dBFast / 10);    // 1.Computation of Lequ Sum of Exp...
  A0dBSumExp1min  =  A0dBSumExp1min  + pow(10, sound.A0dBFast / 10);    // 1.Computation of Lequ Sum of Exp...

  //===============================================

  // Process NAT statistics
  if (sound.A0dBSlow > EVENT_THRESHOLD_LEVEL && state != 'e') //
  {
    if (sound.A0dBSlow > peakValue)
    {
      peakValue = sound.A0dBSlow;
      peakTime = Time;
    }
  }

  // Handling of timers (countdown to 0)

  if (minExceedingTimer > 0) minExceedingTimer--;
  if (maxExceedingTimer > 0) maxExceedingTimer--;
  if (listeningTimer > 0) listeningTimer--;

  // Recording flashback (in reverse order, but it does not matter)
  EVENT[maxExceedingTimer] = sound.A0dBSlow;   //

  // Handling of states
  switch (state)
  {
    case 'e':  // Idle state
      minExceedingTimer = 0;
      maxExceedingTimer = 0;
      listeningTimer = 0;
      aboveThreshDuration = 0;
      peakValue = 0;

      if (sound.A0dBSlow > MEASUREMENT_THRESHOLD_LEVEL)
      {
        state = 'a';
        for  (byte n = 0; n < MAX_EXCEEDANCE_TIME; n++)
        {
          EVENT[n] = 0; // clear flashback record
        }
      }
      break;
    case 'a':
      if (sound.A0dBSlow < MEASUREMENT_THRESHOLD_LEVEL) state = 'e';
      if (sound.A0dBSlow > EVENT_THRESHOLD_LEVEL)
      {
        state = 'b';
        minExceedingTimer = MIN_EXCEEDANCE_TIME;
        maxExceedingTimer = MAX_EXCEEDANCE_TIME;
      }
      break;
    case 'b':
      if (sound.A0dBSlow < MEASUREMENT_THRESHOLD_LEVEL)
      {
        if (not minExceedingTimer && maxExceedingTimer) //(longer than min, less than max time)
        {
          listeningTimer = LISTENING_TIME;
          NAT[Hour]++;     // dont't need to wait longer we have an event to record
          state = 'c';
        }
        if ( minExceedingTimer || not maxExceedingTimer) //(less than min, longer than max time)
        {
          listeningTimer = LISTENING_TIME;
          state = 'e';
        }
      }
      break;
    case 'c':   // just wait for MAX_EXCEEDANCE_TIME to expire
      if (not maxExceedingTimer)
      {
        state = 'd';
      }
      break;
    case 'd':
      if (not listeningTimer) // just wait for MAX_EXCEEDANCE_TIME to expire
      {
        float m = 0;    // determining the max-10 Leq.
        float l = 0;    // delogarithmed sound energy
        byte k = 0;     // counter for Less10dBDuration
        for  (byte n = 0; n < MAX_EXCEEDANCE_TIME; n++)
        {
          m = max(EVENT[n], m); //scan flashback for max
        }
        m = m - 10; //substract 10dB  //peakValue - 10dB
        for  (byte n = 0; n < MAX_EXCEEDANCE_TIME; n++)
        {
          if (EVENT[n] >= m)
          {
            //rescan flashback to integrate 10dBdown LEq
            l =  l + pow(10, EVENT[n] / 10);   // integration of delogarithmed sound energy
            k++;
          }
        }
        less10dBLEq = 10 * log10(l / k);
        less10dBDuration = k;

        m = EVENT_THRESHOLD_LEVEL;
        for  (byte n = 0; n < MAX_EXCEEDANCE_TIME; n++)
        {
          if (EVENT[n] >= m)
          {
            //rescan flashback to integrate aboveThreshLEq
            l =  l + pow(10, EVENT[n] / 10);   // integration of delogarithmed sound energy
            k++;
          }
        }
        aboveThreshLEq = 10 * log10(l / k);
        aboveThreshDuration = k;
        trigNAT = true;
        state = 'e';
      }
      break;
    default:   // catch evtl. wrong states
      state = 'e';
  } // end Switch

  if (MinuteExpiring)
  {
    // Noise Lequ Hourly result
    A0dBLeq1min = 10 * log10(A0dBSumExp1min / 60);   // 2.Computation of Lequ Log of Sum of Exp
  }

  if (HourExpiring)
  {
    // Noise Lequ Hourly result
    leq[Hour] = 10 * log10(A0dBSumExp60min / 3600);   // 2.Computation of Lequ Log of Sum of Exp
    leq[25] = leq[Hour];

    // Noise Lequ Daily results
    if (DayExpiring)
    {
      leq[27] = 0;                              // 27=LequDaylight 6:00 - 22:00
      for  (byte n = 6; n < 22; n++)
      {
        leq[27] = leq[27] + leq[n];
      }
      leq[27] = leq[27] / 16;
      leq[28] = leq[22] + leq[23] ;              // 28=LequNight 22:00 - 06:00
      for  (byte n = 0; n < 6; n++)
      {
        leq[28] = leq[28] + leq[n];
      }
      leq[28] = leq[28] / 8;
      leq[29] = (2 * leq[27] + leq[28] + 10) / 3; // 29=Lden

      leq[26] = (2 * leq[27] + leq[28]) / 3;        // 26=Leq24h
    }
  }
  // end of just before new hour


#if defined BATTERY_MONITORING
  //===============================================

  // Battery measurements from INA226
  delta_voltage = INA.getBusMilliVolts(0) - ina_voltage;
  ina_voltage = INA.getBusMilliVolts(0);
  ina_shunt   = INA.getShuntMicroVolts(0);
  delta_current = INA.getBusMicroAmps(0)  - ina_current;
  ina_current = INA.getBusMicroAmps(0);
  ina_power   = INA.getBusMicroWatts(0);

  battery.voltage += (ina_voltage / 1000 - battery.voltage) / 50;      // Low Pass filter 50 sec
  percent_charged = map(battery.voltage * 100, MIN_VOLT * 100, MAX_VOLT * 100, 0, 100);
  battery.current += (ina_current / -1000000 - battery.current) / 50;  // -"-
  battery.power = battery.voltage * battery.current;

  // Evaluate internal resistance of the battery
  if (fabs(delta_current) > 10000 && ina_voltage < 13800 && ina_voltage > 12000) internal_resistance = fabs(delta_voltage * 1000 / delta_current);
  if (SecondOfDay == 14400) voltageAt4h = battery.voltage;   // taking the voltage at 04:00 to evaluate if the battery gained/lost during the previous day.
  // Daily Battery voltage comparison
  if (SecondOfDay == 14399) // set ranges at 003:59:59
  {
    voltageDelta = battery.voltage - voltageAt4h;
    voltageAt4h = battery.voltage;
  }

  // Battery Stat integration
  currentInt = currentInt + battery.current;
  nCurrent ++;

  if (HourExpiring)
  {
    mAhBat[Hour] = currentInt / nCurrent;
    nCurrent = 0;
    mAhBat[25] = mAhBat[Hour];   //last hour
    mAhBat[27] = 0;              // today (0h->current hour)
    for  (byte n = 0; n < Hour; n++)
    {
      mAhBat[27] = mAhBat[27] + mAhBat[n];
    }
  }

  if (DayExpiring)
  {
    mAhBat[26] = mAhBat[27];
  }

#else  // No Battery Monitoring
  battery.voltage = 0;
  battery.current = 0;
  battery.power = 0;
  delta_voltage = 0;
  delta_current = 0;
#endif

#if defined GRAB_WEATHER
  // Getting Weather from OpenWeatherMap every 5 minutes
  if (Minute % 5 == 1 && Second == 32)   // call every 5 minutes
  { //check here: https://github.com/TridentTD/TridentTD_OpenWeather/blob/master/examples/WeatherNow/WeatherNow.ino
    myPlace.weatherNow();
    outdoor_temperature = myPlace.readTemperature();
    outdoor_humidity = myPlace.readHumidity();
    outdoor_pressure = myPlace.readPressure();
    outdoor_wind_speed = myPlace.readWindSpeed();
    outdoor_wind_direction = myPlace.readWindDeg();
    weather_summary =  myPlace.readWeather();
    sunrise = myPlace.readSunrise(TZ);
    sunset = myPlace.readSunset(TZ);
  }
#endif
}
// end of 1S run
