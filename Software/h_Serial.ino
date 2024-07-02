void serialRun() {
  yield();
  // === Output to DFLD
  digitalWrite(LED_BUILTIN, false);
#if defined(TERM_IS_TELNET)  // Then the output for DFLD will always be sent to Serial
  Serial.write(sound.A0dBAK);
#else
  if (serialPage == 'A') Serial.write(sound.A0dBAK);
#endif
  digitalWrite(LED_BUILTIN, true);

  // === Daily report
  if (SecondOfDay == 86398)  // 2 seconds before end of day
  {
    sprintf(charbuff, " \nDaily Report for \n%s, %02d %s %04d ", DayName, Day, MonthName, Year);
    Console1.print(charbuff);
    // Print NAT , Leq , Battery statistics
    Console1.print("\nHour| Leq  |  NAT  |  BatV  |  PanV  |\n");
    for (byte n = 0; n < 30; n++) {
      if (n == 24) {
        Console1.printf("Extras cf. Man.\n");
      } else {
        Console1.printf("%02u  | %04.1f |  %03u  | %05.2f | %05.2f |\n", n, leq[n], NAT[n], payload.BatV, payload.PanV);
      }
    }
    // Print dB Class statistics
    Console1.print("\ndB | +60  | +70  | +80  | +90  |\n");
    for (byte n = 0; n < 10; n++) {
      Console1.printf("%1u  |%02u  |  %02u  |  %02u  |  %02u  |\n", n, maxLevelClass[n], maxLevelClass[n + 10], maxLevelClass[n + 20], maxLevelClass[n + 30]);
    }

    Console1.print("\nEvt|PKTime  |PKdB|Leq4|t10|Leq3|\n");
  }

  // === Event reported
  if (TrigEvent) {
    Console1.printf(" %02u|", NAT[Hour]);
    Console1.print(peakTime);
    Console1.printf("|%4.1f|%4.1f|%03u|%4.1f|\n", eventPeak, less10dBLEq, less10dBDuration, aboveThreshLEq);
    //TrigEvent = false;
  }

  // **** Menu defined outputs
  switch (serialPage) {
    //case 'A': //serialPage AK  // output already programmed above
    //  break;
    // ***  Periodical compound Reports  ***
    case 'P':
      if (DayExpiring && serialDay) {
        sprintf(charbuff, " \nDaily Report for \n%s, %02d %s %04d ", DayName, Day, MonthName, Year);
        Console1.print(charbuff);
        LEQ_Matrix();
        Console1.print("\nEvt|PKTime  |PKdB|Leq4|t10|Leq3|\n");
      }

      if (HourExpiring && serialHur) {
        Console1.printf("A0dBLEQ:%4.1f WindSpeed:%4.1f Direction:%i\n", leq[25], wind_speed, wind_direction);
      }

#ifndef BATTERY_SOURCE_IS_NONE
      if (MinuteExpiring && serialMin) {
        Console1.printf("Bat_Volt:1%6.3f Bat_Watt:%6.3f Bat_Level:%4.1f \n", payload.BatV - 10, payload.BatW, payload.BatPoC / 10);
      }
#endif

      if (serialNAT && TrigEvent) {
        Console1.print("\nEvt|PKTime  |PKdB|Leq4|t10|Leq3|\n");
        Console1.printf("%02i ", NAT[Hour]);
        Console1.print(peakTime);
        Console1.printf("|%4.1f|%4.1f|%02u |%4.1f|\n", eventPeak, less10dBLEq, less10dBDuration, aboveThreshLEq);
      }
      if (serialSec)
        Console1.printf("Leq(h-1):%4.1f Imp:%4.1f  Bgr:%4.1f Slow:%4.1f\n", leq[25], sound.A0dBImpulse, sound.A0dBBgr, sound.A0dBSlow);
      break;

     case 'J':  // Job Duration Report for debuggging
      Console1.printf("\nGracePause: %03i\nJob Durations(mS) Current - Max\nSche:%03i - %03i \nFast:%03i - %03i\nSlow:%03i - %03i\nStat:%03i - %03i\nDisp:%03i - %03i\nSeri:%03i - %03i\nWifi:%03i - %03i\n",
                      GracePause, RunMillis[1] - RunMillis[0], RunMillis[14], RunMillis[3] - RunMillis[2], RunMillis[15], RunMillis[5] - RunMillis[4], RunMillis[16], RunMillis[7] - RunMillis[6], RunMillis[17],
                      RunMillis[9] - RunMillis[8], RunMillis[18], RunMillis[11] - RunMillis[10], RunMillis[19], RunMillis[13] - RunMillis[12], RunMillis[20]);
      break;

    // ***  One shot reports  ***
    case 'R':  // Daily report
      LEQ_Matrix();
      Console1.print("\n");      
      NAT_Matrix();
      serialPage = 0;
      break;

    case 'L':  // Lequ / Hour matrix
      LEQ_Matrix();
      Console1.print("\n\n");
      serialPage = 0;
      break;

    case 'N':  // NAT / Hour matrix
      NAT_Matrix();
      Console1.print("\n\n");
      serialPage = 0;
      break;

    case 'W':  //Weather Report
      Console1.printf("Temp: %4.1f Hum: %4.1f Press: %4.0f WindSpeed: %4.1f Direction: %u Weather: ", temperature, humidity, pressure, wind_speed, wind_direction);
      Console1.println(weather_summary);
      serialPage = 0;
      break;

    case 'T':  //Trace Noise settings
      Console1.printf("A0dB=%4.1f ADC=%u @47=%u @94=%u A0dBAK= %u Hex= %X State= %c \n", sound.A0dBSlow, A0Raw, A047, A094, sound.A0dBAK, sound.A0dBAK, OFD_state);
      break;

    case 'V':  //Noise Values
        Console1.printf("Leq(h-1):%4.1f Imp:%4.1f  Bgr:%4.1f Slow:%4.1f\n", leq[25], sound.A0dBImpulse, sound.A0dBBgr, sound.A0dBSlow);
      break;

    case 'B':  //Battery Report
      Console1.printf("BatV:%4.1f BatI:%5.2f BatW:%5.1f PanV:%4.1f PoC:%4.1f \n", payload.BatV, payload.BatI, payload.BatW, payload.PanV, payload.BatPoC);
      //batteryReport();
      //Console1.println("");
      serialPage = 0;
      break;

  }  // end switch (serialPage)
}
