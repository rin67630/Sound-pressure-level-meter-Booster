void loop()
{
  // run when idle.
  yield();                          //Yield for WiFi
  runEvery(125)                     //125mS cf Every Macro in Functions
  {
    getEpoch();                     // writes the Epoch (Numbers of seconds till 1.1.1970...
    getTimeData();                  // get Second, Minute...Year.

    MillisMem = millis();           // Launch Menu and Thinger handler
    RunMillis[0] = 0;
    menuRun();
#if defined (THINGER)
#if defined (GRACE_PAUSE)           // Prevent locking if Thinger does not answer
    if (GracePause > 0) GracePause--;
    MillisMem2 = millis();
    if (GracePause == 0) thing.handle();                 // do not call permanently Thinger if it takes too long to respond.
    if (millis() - MillisMem2 > 500) GracePause = 16;  // if the Thinger call took longer than 500ms, make 2s pause before retrying
#else
    thing.handle();
#endif
#endif
    RunMillis[1] = RunMillis[2] =  millis() - MillisMem;
    // Launch Fast data processing
    RunMillis[2] =  millis() - MillisMem;

    data125mSRun();

    RunMillis[3] =  millis() - MillisMem;

    slice ++;                       //Launch jobs by the second in slices
    if (slice > 8) slice = 1;
    switch (slice)                  // These tasks will run every second, but at slices of 125mS
    {
      case 1:                       // Starting the timing flags
        SecondOfDay = Second + 60 * Minute + 3600 * Hour;  // 0 .. 86400
        if (Second == 0 )         // Starting a new Minute..
        {
          NewMinute = true;
          if (Minute == 0)        // Starting a new hour..
          {
            NewHour = true;
            NAT[Hour] = 0;
            if (Hour == 0)        // Starting a  new day..
            {
              NewDay = true;
            }
          }
        }
        if (Second == 59 ) 
        {
          MinuteExpiring = true;
          if (Minute == 59)       // Finishing the hour..
          {
            HourExpiring = true;
            if (Hour == 23)       // Finishing the day..
            {
              DayExpiring = true;
            }
          }
        }
        break;
      case 2:                       // Starting the data acquisition processing every second
        RunMillis[4] =  millis() - MillisMem;
        data1SRun();
        RunMillis[5] =  millis() - MillisMem;
        break;
      case 3:                       // Starting the statistics processing every second
        RunMillis[6] =  millis() - MillisMem;
        statsRun();
        RunMillis[7] =  millis() - MillisMem;
        break;
      case 4:                       // Starting the OTA Handler every second
        RunMillis[8] =  millis() - MillisMem;
#if defined (USE_OTA)
        ArduinoOTA.handle();
#endif
        displayRun();               // Starting the display updates every second
        RunMillis[9] =  millis() - MillisMem;
        break;
      case 5:                       // Starting the serial outputs every second
        RunMillis[10] =  millis() - MillisMem;
        serialRun();
        RunMillis[11] =  millis() - MillisMem;
        break;
      case 7:                       // Starting the wireless communication every second
        RunMillis[12] =  millis() - MillisMem;
        if (WiFi.status() == WL_CONNECTED) wirelessRun();
        RunMillis[13] =  millis() - MillisMem;
        break;
      case 8:                     // Reinitializations and Timing report
        RunMillis[14] = max( RunMillis[14], RunMillis[1] - RunMillis[0]);   // Max Millis Menu and Thinger handler
        RunMillis[15] = max( RunMillis[15], RunMillis[3] - RunMillis[2]);   // Max Millis 125mS Data
        RunMillis[16] = max( RunMillis[16], RunMillis[5] - RunMillis[4]);   // Max Millis 1S Data
        RunMillis[17] = max( RunMillis[17], RunMillis[7] - RunMillis[6]);   // Max Millis Stats
        RunMillis[18] = max( RunMillis[18], RunMillis[9] - RunMillis[8]);   // Max Millis Display
        RunMillis[19] = max( RunMillis[19], RunMillis[11] - RunMillis[10]); // Max Millis Serial
        RunMillis[20] = max( RunMillis[20], RunMillis[13] - RunMillis[12]); // Max Millis WiFi
        if (Second % 10 == 5) // every 6 seconds
        {
          sound.A0dBMin  = 90;
          sound.A0dBMax = nA0dB6S = A0dBSum6S = 0;
        }
        if (MinuteExpiring)
        {
          A0dBMin1min = 90;
          A0dBMax1min = A0dBSumExp1min = 0;
          if (HourExpiring)
          {
            //Hourly
           if (DayExpiring)
            {
              //Daily
            }
          }
        }
        NewMinute = false;
        MinuteExpiring = false;
        NewHour = false;
        HourExpiring = false;
        NewDay = false;
        DayExpiring = false;
        trigEvent = false;
        break;
    } // end Switch slice
  } // end Every 125mS
}
//end loop
