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
#else
  yield();
#endif
}

void data1SRun()
{
  yield();

  // === (Getting Weather from OpenWeatherMap every 5 minutes
#if defined WEATHER_SOURCE_IS_URL
  if (Minute % 5 == 1 && Second == 32)                    // call every 5 minutes
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
        outdoor_temperature  = doc["main"]["temp"];
        outdoor_pressure     = doc["main"]["pressure"];
        outdoor_humidity     = doc["main"]["humidity"];
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
#endif

  // === (Fetching Noise level from URL with reduced resolution
#if defined (SOUND_SOURCE_IS_URL)   // must be a JSON from DFLD.de
  HTTPClient http;
  http.begin(WifiClient, DFLD_URL);             //Specify request destination
  int httpCode1 = http.GET();       //Send the request
  if (httpCode1 == HTTP_CODE_OK)    //Check the returning code
  {
    JSONpayload = http.getString();          //Get the request response payload
    // it should be like: {"generator":"DFLD_LIVE","version":"0.9","time":1587592375,"access-control":"ignoredWrongPWD","027":32.0}
    JSONpayload = JSONpayload.substring(100, 104); // taking only the dB value
    sound.A0dBFast = JSONpayload.toFloat();
    sound.A0dBMin = min(sound.A0dBFast, sound.A0dBMin);
    sound.A0dBMax = max(sound.A0dBFast, sound.A0dBMax);
    sound.A0dBSlow += (sound.A0dBFast - sound.A0dBSlow) / 6; // Low Pass filter 6 sec
    if ( sound.A0dBFast > sound.A0dBImpulse)           //A0 in dB with impulse response
    {
      sound.A0dBImpulse = sound.A0dBFast;              //No filter
    }
    else
    {
      sound.A0dBImpulse = sound.A0dBImpulse - 4.3 ; //Linear decay 4,3db /sec
    }
  }
  http.end();   //Close connection
#endif

  // === (Getting Sound / Battery values from another ESP over UDP
#if defined (SOUND_SOURCE_IS_UDP) || defined (BATTERY_SOURCE_IS_UDP)

  // I use a quick and dirty method called 'type punning' copying the memory block of a structure into an array of chars,
  // transmitting this array, and copying back the memory block of the array into the same structure on the other side.
  // I dont use any header info, only the difference of size permits to assign the received packets to sound or battery.
  // it is quick and damn efficient, but NOT portable and YOU must take care to have the same structures on both systems
  // and different sizes for Battery and Sound...

  int packetSize = UDP.parsePacket();
  // if (packetSize) Console3.printf("Packet size: %u, Sound size: %u , Battery size; %u \n", packetSize, sizeof(sound), sizeof(battery));
  //  if (packetSize) digitalWrite(STDLED, false);    // Blink built-in LED on received packets
  if (packetSize == sizeof(sound))
  {
    UDP.read(soundPayload, UDP_TX_PACKET_MAX_SIZE);
    memcpy(&sound, soundPayload, sizeof(sound));
    // Console1.printf("Min:%2.1f Max:%2.1f Imp:%2.1f  Bgr:%2.1f Slow:%2.1f\n", sound.A0dBMin, sound.A0dBMax, sound.A0dBImpulse, sound.A0dBBgr, sound.A0dBSlow);
    //     Console1.print("s");
  }
  if (packetSize == sizeof(battery))
  {
    float m = battery.voltage;
    float n = battery.current;
    UDP.read(batteryPayload, UDP_TX_PACKET_MAX_SIZE);
    memcpy(&battery, batteryPayload, sizeof(battery));
    delta_voltage = battery.voltage - m;
    delta_current = battery.current - n;
    // Console1.printf("Ah: %2.1f, Volt: %2.1f, Amp: %2.1f, Watt: %2.1f, %%Batt: %2.1f\n", AhBat, battery.voltage , battery.current , battery.power , percent_charged);
    delay(3);    // let built-in LED blink slightly stronger on battery packet
  }
  //digitalWrite(STDLED, true);
#endif

  //=== (DFLD Formatting (AK Modulbus format)
  sound.A0dBAK = 50 + int(2 * sound.A0dBFast);                  // Reduction to 1 Byte 50...250
  A0dBArray[60 * Minute + Second] = sound.A0dBAK;
  sound.A0dBImpulse = max(sound.A0dBImpulse, sound.A0dBSlow);

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


  // === (Process NAT statistics
  if (wind_speed > WIND_LIMIT) state = 'o';     // forcing idle if wind too strong.
  if (sound.A0dBSlow > EVENT_THRESHOLD_LEVEL && state != 'o') //
  {
    if (sound.A0dBSlow > peakValue)
    {
      peakValue = sound.A0dBSlow;
      peakTime = Time;
    }
  }
  if (minExceedingTimer > 0) minExceedingTimer--;  // timers countdown to 0
  if (maxExceedingTimer > 0) maxExceedingTimer--;
  if (listeningTimer > 0) listeningTimer--;

  EVENT[maxExceedingTimer] = sound.A0dBSlow;   //Recording flashback (in reverse order, but it does not matter)

  // === (Handling of states
  float reference;     //Reference dB level
  byte n;              //Looping index
  float soundEnergy;   // delogarithmed soundEnergy
  byte eventDuration;  // counter for EventDuration
  switch (state)
  {
    case 'o':  // Idle state
      minExceedingTimer = 0;
      maxExceedingTimer = 0;
      listeningTimer = 0;
      aboveThreshDuration = 0;
      less10dBDuration = 0;
      peakValue = 0;
      if (sound.A0dBSlow >= MEASUREMENT_THRESHOLD_LEVEL)
      {
        for  (n = 0; n < MAX_EXCEEDANCE_TIME; n++)
        {
          EVENT[n] = 0; // clear flashback record
        }
        state = 'a';
      }
      break;
    case 'a':
      if (sound.A0dBSlow < MEASUREMENT_THRESHOLD_LEVEL) state = 'o';    // return to idle
      if (sound.A0dBSlow > EVENT_THRESHOLD_LEVEL)
      {
        minExceedingTimer = MIN_EXCEEDANCE_TIME;
        maxExceedingTimer = MAX_EXCEEDANCE_TIME;
        state = 'b';
      }

      break;
    case 'b':
      if (sound.A0dBSlow < EVENT_THRESHOLD_LEVEL)
      {
        if (not minExceedingTimer && maxExceedingTimer)                 //(longer than min and less than max time)
        {
          NAT[Hour]++;                                                  // we have an event qualifying
          state = 'c';
        }
        if ( minExceedingTimer || not maxExceedingTimer)                //(less than min or longer than max time)
        {
          state = 'o';                                                  // event does not qualify, retuning to idle
        }
      }
      break;
    case 'c':                                                          // wait for MAX_EXCEEDANCE_TIME to expire
      if (not maxExceedingTimer)                                       // after MAX_EXCEEDANCE_TIME expired
      {
        //       listeningTimer = LISTENING_TIME;
        state = 'd';
      }
      break;
    case 'd':                                                         // Event evaluation according to Lmax-10dB
      reference = 0;                                                // determining the max-10 Leq reference.
      for  ( n = 0; n <= MAX_EXCEEDANCE_TIME; n++)
      {
        reference = max(EVENT[n], reference);                        //scan flashback for max
      }
      reference = reference - 10;

      soundEnergy = 0;
      eventDuration = 0;
      for  (n = 0; n < MAX_EXCEEDANCE_TIME; n++)
      {
        if (EVENT[n] >= reference)
        { //rescan flashback to integrate 10dBdown LEq
          soundEnergy +=  pow(10, EVENT[n] / 10);                     // integration of delogarithmed soundEnergy
          eventDuration++;
        }
      }
      less10dBLEint   += soundEnergy;                                 //integration of the soundEnergy for the whole day
      less10dBDuration = eventDuration;
      less10dBLE       = 10 * log10(soundEnergy);                     //Single event  sound  exposure  level measured from Lmax-10dB
      less10dBLEq      = 10 * log10(soundEnergy / eventDuration);     //Equivalent noise for the duration measured from Lmax-10dB

      // Event evaluation according to EVENT_THRESHOLD_LEVEL
      reference = EVENT_THRESHOLD_LEVEL;
      soundEnergy = 0;
      eventDuration = 0;
      for  (byte n = 0; n < MAX_EXCEEDANCE_TIME; n++)
      {
        if (EVENT[n] >= reference)
        { //rescan flashback to integrate aboveThreshLEq
          soundEnergy +=  pow(10, EVENT[n] / 10);                     // integration of delogarithmed soundEnergy
          eventDuration++;
        }
      }
      aboveThreshLEint   += soundEnergy;                              //integration of the soundEnergy for the whole day
      aboveThreshDuration = eventDuration;
      aboveThreshLE       = 10 * log10(soundEnergy);                  //Single  event  sound  exposure  level measured from EVENT_THRESHOLD_LEVEL
      aboveThreshLEq      = 10 * log10(soundEnergy / eventDuration);  //Equivalent noise for the duration measured from EVENT_THRESHOLD_LEVEL
      trigNAT = true;
      listeningTimer = LISTENING_TIME;
      state = 'e';
      break;
    case 'e':                                                           // waiting for listening time before reurning to idle
      if (not listeningTimer) state = 'o';                              // after MAX_EXCEEDANCE_TIME state = 'o';
      break;
    default:   // catch evtl. wrong states
      state = 'o';
  } // end Switch

  // === (Process Noise Lequ integration
  A0dBSumExp1min  =  A0dBSumExp1min  + pow(10, sound.A0dBSlow / 10);    // 1.Computation of Lequ Sum of Exp...
  if (MinuteExpiring)
  {
    // Noise Lequ Minute result
    A0dBLeq1min = 10 * log10(A0dBSumExp1min / 60);                      // 2.Computation of Lequ Log of Sum of Exp
    if  (A0dBLeq1min < LOWER_LIMIT_DB)  A0dBLeq1min = LOWER_LIMIT_DB;   // Catch errors at LOWER_LIMIT_DB
    A0dBSumExp60min  =  A0dBSumExp60min  + pow(10, A0dBLeq1min / 10);   // 1.Computation of Lequ Sum of Exp...
  }

  if (HourExpiring)
  {
    // Noise Lequ Hourly results
    leq[Hour] = 10 * log10(A0dBSumExp60min / 60);                       // 2.Computation of Lequ Log of Sum of Exp
    A0dBSumExp60min  =  0;
    leq[25] = leq[Hour];
  }

  //=== ( Noise Lequ Daily results (25=Leq last hour, 26=Leq 24H, 27=Daytime, 28=Nighttime, 29=Lden, 30=Leq)
  if (DayExpiring)
  {
    leq[27] = 0;                                                       // 27=LequDaylight 6:00 - 22:00
    for  (byte n = 6; n < 22; n++)
    {
      leq[27] +=  pow(10, leq[n] / 10);                                //Delogarithmed daytime
    }
    leq[27] = 10 * log10( leq[27] / 16);                               //Leq Daytime

    leq[28] = 0;
    leq[28] = pow(10, leq[22] / 10) + pow(10, leq[23] / 10) ;         // Delogarithmed 22:00-23:00

    leq[30] = 10 * log10( leq[28] / 2);                               // Leq 22:00-23:00 (en passant)
    for  (byte n = 0; n < 6; n++)                                     // continuing with the next 6 hours...
    {
      leq[28] +=  pow(10, leq[n] / 10);                               // adding the delogarithmed morning hours
    }
    leq[28] = 10 * log10( leq[28] / 8);                               //Leq nighttime

    leq[29] = 2 * pow(10, leq[27] / 10) + pow(10, ((leq[28] + 10) / 10)); //Delogarithmed 2 * daytime + (nightime +10dB)
    leq[29] = 10 * log10( leq[29] / 3);                              // 29=Lden

    leq[26] = 2 * pow(10, leq[27] / 10) + pow(10, (leq[28] / 10));   //Delogarithmed 2 * daytime + nightime)
    leq[26] = 10 * log10(leq[26] / 3);                               // 26=Leq24h
    leq[31] = 10 * log10 (aboveThreshLEint / 864000);                // 31=Leq24h, only events over Threshold
    aboveThreshLEint = 0;  // reset integration
    leq[32] = 10 * log10 (less10dBLEint    / 864000);                // 32=Leq24h, only events by Max-10dB method
    less10dBLEint    = 0;  // reset integration

    //=== ( NAT 0...23= hourly NAT , 25=current event 26=Nat24h 27= Daytime 28= Nighttime 29= 22h-24h
    NAT[27] = 0;                                                    // 27=NATuDaylight 6:00 - 22:00
    for  (byte n = 6; n < 22; n++)
    {
      NAT[27] = NAT[27] + NAT[n];
    }
    NAT[28] = NAT[22] + NAT[23] ;                                   // 28=NATuNight 22:00 - 06:00
    for  (byte n = 0; n < 6; n++)                                   // adding the 6 hours 0:00..6:00
    {
      NAT[28] = NAT[28] + NAT[n];
    }
    NAT[26] = NAT[27] + NAT[28];                                    // 26=NAT24h = NAT Night + NAT DAY
    NAT[29] = (NAT[22] + NAT[23]);                                  // 29 =L22-24h
  } // end if day expiring

  //=== ( Measure Battery
#if defined BATTERY_SOURCE_IS_INA
  // Battery measurements from INA226
  ina_voltage   = INA.getBusMilliVolts(0);
  ina_shunt     = INA.getShuntMicroVolts(0);
  ina_current   = INA.getBusMicroAmps(0) ;
  ina_power     = INA.getBusMicroWatts(0);
  voltage += (ina_voltage / 1000 - voltage) / 10;                  // Low Pass filter 2min
  current += (ina_current / 1000000 - current) / 10;               // Set divisor negative to reverse current if required
  if (NewMinute)
  {
    float m = battery.voltage;
    float n = battery.current;
    battery.voltage = voltage;
    battery.current = current;
    battery.power = voltage * current;
    delta_voltage = battery.voltage - m;
    delta_current = battery.current - n;
  }// end if new minute
#endif

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
    if (battery.voltage < (MAX_VOLT - 1) &&  battery.voltage > (MIN_VOLT + 0.3))
    {
      // Evaluate battery internal resistance (r = dv / di) if inside regular limits and smooth it.
      if (fabs(delta_current) > 0.05) internal_resistance = fabs(delta_voltage / delta_current);
    }
  }// end if new minute


  //=== ( Daily Battery voltage comparison just before midnight
  if (SecondOfDay == 86000) voltageAt2355h  = battery.voltage;               // taking the voltage at 23:55 to evaluate if the battery gained/lost during the previous day.
  if (SecondOfDay == 85899) voltageDelta = battery.voltage - voltageAt2355h; // set ranges at 33:53:59

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

} // end of 1S run
