void serialRun()
{
  yield();
  //Trace noise on second serial port
  if (DayExpiring)
  {
    sprintf(charbuff, " \nDaily Report for \n%s, %02d %s %04d ", DayName , Day , MonthName, Year);
    Console2.print(charbuff);

    Console2.print("\nHour| Leq  |  NAT  |  Ah    |\n");
    for  (byte n = 0; n < 30; n++)
    {
      if (n == 24)
      {
        Console2.printf("Extra ""hours"" cf. Man.\n");
      }
      else
      {
        Console2.printf("%02u  | %02.1f |  %03u  | %+02.3f |\n", n, leq[n], NAT[n], AhBat[n]);
      }
    }
    Console2.print("\nNAT|PKTime  |PKdB|Leq4|t10|Leq3|\n");
  }
  if (trigNAT)
  {
    Console2.printf(" %02u|", NAT[Hour]);  Console2.print(peakTime);  Console2.printf("|%2.1f|%2.1f|%03u|%2.1f|\n", peakValue , less10dBLEq , less10dBDuration,  aboveThreshLEq);
  }
  switch (serialPage)
  {
    case 'A': //serialPage AK
      Console4.write(sound.A0dBAK);
      break;
    // ***  Periodical compound Reports  ***
    case 'P':
      if (DayExpiring  && serialDay)
      {
        sprintf(charbuff, " \nDaily Report for \n%s, %02d %s %04d ", DayName , Day , MonthName, Year);
        Console1.print(charbuff);

        Console1.print("\nHour| Leq  |  NAT |  Ah    |\n");
        for  (byte n = 0; n < 30; n++)
        {
          if (n == 24)
          {
            Console1.printf("Extra ""hours"" cf. Man.\n");
          }
          else
          {
            Console1.printf("%02u  | %02.1f |  %02u  | %+02.3f |\n", n, leq[n], NAT[n], AhBat[n]);
          }
        }
        Console1.print("\nNAT|PKTime  |PKdB|Leq4|t10|\n");
      }
      if (HourExpiring && serialHur)
      {
        Console1.printf("BatAhBat:%1.3f A0dBLEQ:%2.1f WindSpeed:%2.1f Direction:%3.0f\n", AhBat, leq[25] , wind_speed , wind_direction);
      }
      #ifndef BATTERY_SOURCE_IS_NONE
      if (MinuteExpiring && serialMin)
      {
        Console1.printf("Bat_Volt:1%2.3f Bat_Watt:%2.3f Bat_Level:%2.1f \n", battery.voltage - 10, battery.power, percent_charged / 10);
      }
      #endif
      if (serialNAT && trigNAT)
      {
        // Console1.print(peakTime);  Console1.printf(" NAT:%u PKdB:%2.1f ATdB: %2.1f ATsec:%u PK-10dB: %2.1f PK-10sec: %u \n" , NAT[Hour], peakValue , aboveThreshLEq , aboveThreshDuration, less10dBLEq , less10dBDuration);
        Console1.print("\nNAT|PKTime  |PKdB|Leq4|t10|Leq3|\n");  
        Console1.printf("% 02u|", NAT[Hour]);  Console1.print(peakTime);  Console1.printf("|%2.1f|%2.1f|%02u |%2.1f|\n", peakValue , less10dBLEq , less10dBDuration,  aboveThreshLEq);
      }
      if (serialSec)
        Console1.printf("Leq(h-1):%2.1f Imp:%2.1f  Bgr:%2.1f Slow:%2.1f\n", leq[25], sound.A0dBImpulse, sound.A0dBBgr, sound.A0dBSlow);
      break;

    // ***  One shot reports  ***
    case 'R': // Daily report
      sprintf(charbuff, " \nDaily Report for \n%s, %02d %s %04d ", DayName , Day , MonthName, Year);
      Console1.print(charbuff);

      Console1.print("\nHour| Leq  |  NAT |  Ah    |\n");
      for  (byte n = 0; n < 30; n++)
      {
        if (n == 24)
        {
          Console1.printf("Extra ""hours"" cf. Man.\n");
        }
        else
        {
          Console1.printf("%02u  | %02.1f |  %02u  | %+02.3f |\n", n, leq[n], NAT[n], AhBat[n]);
        }
      }
      serialPage = 0;
      break;

    case 'L': // Lequ / Hour matrix
      sprintf(charbuff, " for %s, %02d %s %04d ", DayName , Day , MonthName, Year);
      Console1.print(charbuff);
      Console1.print("\n Hour   |");
      for  (byte n = 0; n < 12; n++)
      {
        Console1.printf("  %02u  |", n);
      }
      Console1.print  ("\n Leq dB |");
      for  (byte n = 0; n < 12; n++)
      {
        Console1.printf(" %02.1f |", leq[n]);
      }
      Console1.print("\n Hour   |");
      for  (byte n = 12; n < 24; n++)
      {
        Console1.printf("  %02u  |", n);
      }
      Console1.print  ("\n Leq dB |");
      for  (byte n = 12; n < 24; n++)
      {
        Console1.printf(" %02.1f |", leq[n]);
      }
      Console1.print("\n\n");
      serialPage = 0;
      break;

    case 'N': // NAT / Hour matrix
      sprintf(charbuff, " for %s, %02d %s %04d ", DayName , Day , MonthName, Year);
      Console1.print(charbuff);
      Console1.print("\n Hour   |");
      for  (byte n = 0; n < 12; n++)
      {
        Console1.printf("  %02u  |", n);
      }
      Console1.print  ("\n NAT    |");
      for  (byte n = 0; n < 12; n++)
      {
        Console1.printf("  %02u  |", NAT[n]);
      }
      Console1.print("\n Hour   |");
      for  (byte n = 12; n < 24; n++)
      {
        Console1.printf("  %02u  |", n);
      }
      Console1.print  ("\n NAT    |");
      for  (byte n = 12; n < 24; n++)
      {
        Console1.printf("  %02u  |", NAT[n]);
      }
      Console1.print("\n\n");
      serialPage = 0;
      break;

    case 'W': //Weather Report
      Console1.printf("Temp: %2.1f Hum: %2.1f Press: %4.0f WindSpeed: %2.1f Direction: %u Weather: ", outdoor_temperature, outdoor_humidity, outdoor_pressure, wind_speed, wind_direction);
      Console1.println(weather_summary);
      serialPage = 0;
      break;

    case 'T': //Trace
      Console1.printf("A0dB=%2.1f ADC=%u @47=%u @94=%u A0dBAK= %u Hex= %X State= %c\n", sound.A0dBSlow , A0Raw, A047, A094, sound.A0dBAK, sound.A0dBAK, state);
      break;

    case 'B':  //Battery Report
      Console1.print  ("\n Hour   |");
      for  (byte n = 0; n < 12; n++)
      {
        Console1.printf("   %02u   |", n);
      }
      Console1.print  ("\n Bat Ah |");
      for  (byte n = 0; n < 12; n++)
      {
        Console1.printf(" %+02.3f |", AhBat[n]);
      }
      Console1.print  ("\n Hour   |");
      for  (byte n = 12; n < 24; n++)
      {
        Console1.printf("   %02u   |", n);
      }
      Console1.print  ("\n Bat Ah |");
      for  (byte n = 12; n < 24; n++)
      {
        Console1.printf(" %+02.3f |", AhBat[n]);
      }
      Console1.println("");
      serialPage = 0;
      break;
    case 'b':
      Console1.printf("Ah: %+2.3f, Volt: %2.3f, Amp: %2.3f, Watt: %2.3f, %%Batt: %2.1f IntRes: %1.3f\n", AhBat[27], battery.voltage , battery.current , battery.power , percent_charged, internal_resistance);
      serialPage = 0;
      break;
  }  // end switch (serialPage)

}
