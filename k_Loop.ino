void loop()
{
  // run when idle.
  ArduinoOTA.handle();
  menuRun();
  yield();              //Yield for WiFi

  runEvery(125)         //125mS cf Every Macro in Functions
  {
    getEpoch();         // writes the Epoch (Numbers of seconds till 1.1.1970...
    getTimeData();      // get Second, Minute...Year.

    data125mSRun();
    delay(50);          // set as high as possible to save energy but low enough to get the tasks done.

    slice += 1;
    if (slice > 8) slice = 1;
    switch (slice)      // The tasks will run every second, but at at 125mS steps
    {
      case 1:   
        SecondOfDay = Second + 60 * Minute + 3600 * Hour;  // 0 .. 84600
        if (Second == 0 )         // Starting a new Minute..
        {
          NewMinute = true;
          if (Minute == 0)        // Starting a new hour..
          {
            NewHour = true;
            NAT[Hour] = 0;    
            //  TAT[Hour] = 0;
            if (Hour == 0)        // Starting a  new day..
            {
              NewDay = true;
            }
          }
        }
        if (Second == 59 )        // Finishing the Minute..
        {
          MinuteExpiring = true;
          if (Minute == 59)       // Finishing the hour..
          {
            HourExpiring = true;
            if (Hour == 59)       // Finishing the day..
            {
              DayExpiring = true;
            }
          }
        }
        break;
      case 2:
        data1SRun();
        break;
      case 3:
        displayRun();
        break;
      case 5:
        serialRun();
        break;
      case 7:
        wirelessRun();
        break;
      case 8:          // Reinitializations
        if (Second % 10 == 5) // every 6 seconds
        {
          sound.A0dBMin  = 90;
          sound.A0dBMax  = 0;
          nA0dB6S  = 0;
          A0dBSum6S  = 0;
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
        trigNAT = false;
        break;
    } // end Switch slice

  } // end Every 125mS


}
//end loop
