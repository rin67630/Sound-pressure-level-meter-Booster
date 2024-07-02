void statsRun()
{
  // === (Reset dB Class statistics and NAT Values

  if (NewDay)
  {
    if (Day == 1)                         // reset monthly dB Histogram
    {
      for  (byte n = 0; n < 40; n++)
      {
        maxLevelClassMonth[n] = 0;
      }
    }
    for  (byte n = 0; n < 40; n++)
    {
      maxLevelClassMonth[n] += maxLevelClass[n];
      maxLevelClass[n] = 0;
    }
  }
  if (NewHour) NAT[Hour] = 0;

  // === Process Weather
#if defined WEATHER_SOURCE_IS_OWM
  if (wind_speed > WIND_LIMIT) OFD_state ='o';     // forcing idle if wind too strong.
#endif

  // === Process DIN/IEC Overflight detection/evaluation
  if (sound.A0dBSlow > EVENT_THRESHOLD_LEVEL && OFD_state != 'o') //
  {
    if (sound.A0dBSlow > peakValue)
    {
      peakValue = sound.A0dBSlow;
      peakTime = Time;                           // ToDo: should substract ~120 seconds 
      
    }
  }
  if (minExceedingTimer > 0) minExceedingTimer--;    // Timers are working reversed.
  if (maxExceedingTimer > 0) maxExceedingTimer--;
  if (listeningTimer > 0) listeningTimer--;

  Event[maxExceedingTimer] = sound.A0dBSlow;        //Recording flashback (in reverse order, but it does not matter)

  // === (Handling of Overflight Detection states
  byte n;              //Looping index
  switch (OFD_state)
  {
    case 'o':  // Idle state Waiting for exceeding Threshold
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
          Event[n] = 0; // clear flashback record
        }
        OFD_state ='a';
      }
      break;
    case 'a':   //Init Event threshold, start timers
      if (sound.A0dBSlow < MEASUREMENT_THRESHOLD_LEVEL) OFD_state ='o';    // return to idle
      if (sound.A0dBSlow > EVENT_THRESHOLD_LEVEL)
      {
        // start timers
        minExceedingTimer = MIN_EXCEEDANCE_TIME;
        maxExceedingTimer = MAX_EXCEEDANCE_TIME;
        OFD_state ='b';
      }
      break;
    case 'b':    // Qualifying Duration above Threshold
      Event[maxExceedingTimer] = sound.A0dBSlow;                        //Recording first second
      if (sound.A0dBSlow < EVENT_THRESHOLD_LEVEL)                       // Event finished
      {
        if (not minExceedingTimer && maxExceedingTimer)                 //(longer than min and less than max time)
        {
          if (peakValue >= NAT_THRESHOLD_LEVEL) NAT[Hour]++;            // we have an event qualifying for NAT recording
          OFD_state ='c';
        }
        if ( minExceedingTimer || not maxExceedingTimer)                //(less than min or longer than max time)
        {
          OFD_state ='o';                                                  // event does not qualify, retuning to idle
        }
      }
      break;
    case 'c':   // Wait for MAX_EXCEEDANCE_TIME to expire
      if (not maxExceedingTimer)                                       // after MAX_EXCEEDANCE_TIME expired
      {
        //       listeningTimer = LISTENING_TIME;
        OFD_state ='d';
      }
      break;
    case 'd':   // Retrospective analysis according to Lmax-10dB
      eventPeak = 0;                                                // determining the max-10 Leq reference.
      for  ( n = 0; n < MAX_EXCEEDANCE_TIME; n++)
      {
        eventPeak = max(Event[n], eventPeak);                        //scan flashback for max
      }

                   // Event evaluation according to eventPeak level (peak - 10dB)
      soundEnergy = 0;
      eventDuration = 0;
      for  (n = 0; n < MAX_EXCEEDANCE_TIME; n++)
      {
        if (Event[n] >= (eventPeak - 10))
        { //rescan flashback to integrate 10dBdown LEq
          soundEnergy +=  pow(10, Event[n] / 10);                     // integration of delogarithmed soundEnergy
          eventDuration++;
        }
      }
      less10dBLEint   += soundEnergy;                                 //integration of the soundEnergy for the whole day
      less10dBDuration = eventDuration;
      less10dBLE       = 10 * log10(soundEnergy);                     //Single event  sound  exposure  level measured from Lmax-10dB
      less10dBLEq      = 10 * log10(soundEnergy / eventDuration);     //Equivalent noise for the duration measured from Lmax-10dB

      // Event evaluation according to EVENT_THRESHOLD_LEVEL
      soundEnergy = 0;
      eventDuration = 0;
      for  (byte n = 0; n < MAX_EXCEEDANCE_TIME; n++)
      {
        if (Event[n] >= EVENT_THRESHOLD_LEVEL)
        { //rescan flashback to integrate aboveThreshLEq
          soundEnergy +=  pow(10, Event[n] / 10);                     // integration of delogarithmed soundEnergy
          eventDuration++;
        }
      }
      aboveThreshLEint   += soundEnergy;                              //integration of the soundEnergy for the whole day
      aboveThreshDuration = eventDuration;
      aboveThreshLE       = 10 * log10(soundEnergy);                  //Single  event  sound  exposure  level measured from EVENT_THRESHOLD_LEVEL
      aboveThreshLEq      = 10 * log10(soundEnergy / eventDuration);  //Equivalent noise for the duration measured from EVENT_THRESHOLD_LEVEL

      // Event classsification by dB class
      maxLevelClass[constrain (int (eventPeak - 60), 0, 34)] ++;
      TrigEvent = true;
      thingerNAT = true;
      listeningTimer = LISTENING_TIME;
      OFD_state ='e';
      break;
    case 'e':    // Waiting for listening time before returning to idle
      if (not listeningTimer) OFD_state ='o';                              // after MAX_EXCEEDANCE_TIME OFD_state ='o';
      break;
    default:   // catch evtl. wrong states
      OFD_state ='o';
  } // end Switch

  if (thingerNAT)
  {
    A0dBtrend = eventPeak;                                          // Show the peak of even recorded
  } else {
    A0dBtrend = (3 * sound.A0dBBgr + sound.A0dBSlow) / 4;                // show a little noise above background (not math correct)
  }


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
  if (SecondOfDay == 86394)  // 6 seconds before end of day, cheating a bit to distribute computing power before midnight
  {
    leq[27] = 0;                                                       // 27=LequDaylight 6:00 - 22:00
    for  (byte n = 6; n < 22; n++)
    {
      leq[27] +=  pow(10, leq[n] / 10);                                //Delogarithmed daytime
    }
    leq[27] = 10 * log10( leq[27] / 16);                               //Leq Daytime
  }
  if (SecondOfDay == 86395)  // 5 seconds before end of day
  {
    leq[23] = 10 * log10(A0dBSumExp60min / 59);                     // pre-computing Leq 23h
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
    leq[31] = 10 * log10 (aboveThreshLEint / 86395);                // 31=Leq24h, only events over Threshold
    aboveThreshLEint = 0;  // reset integration
    leq[32] = 10 * log10 (less10dBLEint    / 86395);                // 32=Leq24h, only events by Max-10dB method
    less10dBLEint    = 0;  // reset integration
  }
  if (SecondOfDay == 86396)  // 4 seconds before end of day
  {
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
  } //
}
