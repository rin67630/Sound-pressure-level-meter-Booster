void serialRun()
{
  yield();
  switch (serialPage)
  {
    case 'A': //serialPage AK
      Serial.write(sound.A0dBAK);
      break;
    // ***  Periodical compound Reports  ***
    case 'P':
      if (DayExpiring  && serialDay)
      {
        ConOut.printf("BatmAhBat:%3.1f A0dBLEQ:%2.1f WindSpeed:%u Direction:%u\n", AhBat, leq[25] , outdoor_wind_speed , outdoor_wind_direction);
      }
      if (HourExpiring && serialHur)
      {
        ConOut.printf("BatAhBat:%1.3f A0dBLEQ:%2.1f WindSpeed:%u Direction:%u\n", AhBat, leq[25] , outdoor_wind_speed , outdoor_wind_direction);
      }
      if (MinuteExpiring && serialMin)
      {
        ConOut.printf("Bat_Volt-10:%2.3f Bat_Watt:%2.3f Bat_Level:%2.3f \n", battery.voltage - 10, battery.power, percent_charged / 10);
      }
      if (serialNAT && trigNAT)
      {
        ConOut.print("PKTm: ");
        ConOut.print(peakTime);
        ConOut.printf(" PKdB:%2.1f ATdB: %2.1f ATsec:%u PK-10dB: %2.1f PK-10sec: %u NAT:%u\n" , peakValue , aboveThreshLEq , aboveThreshDuration, less10dBLEq , less10dBDuration , NAT[Hour]);
      }
      if (serialSec)
        ConOut.printf("Leq(h-1):%2.1f Imp:%2.1f  Bgr:%2.1f Slow:%2.1f\n", leq[25], sound.A0dBImpulse, sound.A0dBBgr, sound.A0dBSlow);
      break;

    // ***  One shot reports  ***
    case 'L': // Lequ / Hour matrix
      sprintf(charbuff, " for %s, %02d %s %04d ", DayName , Day , MonthName, Year);
      ConOut.print(charbuff);
      ConOut.print("\n Hour   |");
      for  (byte n = 0; n < 12; n++)
      {
        ConOut.printf("  %02u  |", n);
      }
      ConOut.print  ("\n Leq dB |");
      for  (byte n = 0; n < 12; n++)
      {
        ConOut.printf(" %02.1f |", leq[n]);
      }
      ConOut.print("\n Hour   |");
      for  (byte n = 12; n < 24; n++)
      {
        ConOut.printf("  %02u  |", n);
      }
      ConOut.print  ("\n Leq dB |");
      for  (byte n = 12; n < 24; n++)
      {
        ConOut.printf(" %02.1f |", leq[n]);
      }
      ConOut.print("\n\n");
      serialPage = 0;
      break;

    case 'N': // NAT / Hour matrix
      sprintf(charbuff, " for %s, %02d %s %04d ", DayName , Day , MonthName, Year);
      ConOut.print(charbuff);
      ConOut.print("\n Hour   |");
      for  (byte n = 0; n < 12; n++)
      {
        ConOut.printf("  %02u  |", n);
      }
      ConOut.print  ("\n NAT    |");
      for  (byte n = 0; n < 12; n++)
      {
        ConOut.printf("  %02u  |", NAT[n]);
      }
      ConOut.print("\n Hour   |");
      for  (byte n = 12; n < 24; n++)
      {
        ConOut.printf("  %02u  |", n);
      }
      ConOut.print  ("\n NAT    |");
      for  (byte n = 12; n < 24; n++)
      {
        ConOut.printf("  %02u  |", NAT[n]);
      }
      ConOut.print("\n\n");
      serialPage = 0;
      break;

    case 'W': //Weather Report
      ConOut.printf("Temp: %2.1f Hum: %u Press: %u @94=%u WindSpeed: %2.1f Direction: %u\n", outdoor_temperature, outdoor_humidity, outdoor_pressure, outdoor_wind_speed, outdoor_wind_direction);
      serialPage = 0;
      break;

    case 'T': //Trace noise
      ConOut.printf("A0dB=%2.1f ADC=%u @47=%u @94=%u A0dBAK= %u Hex= %X\n", sound.A0dBSlow , A0Raw, A047, A094, sound.A0dBAK, sound.A0dBAK);
      serialPage = 0;
      break;

    case 'B':  //Battery Report
      ConOut.print  ("\n Hour   |");
      for  (byte n = 0; n < 12; n++)
      {
        ConOut.printf("   %02u   |", n);
      }
      ConOut.print  ("\n Bat Ah |");
      for  (byte n = 0; n < 12; n++)
      {
        ConOut.printf(" %+02.3f |", AhBat[n]);
      }
      ConOut.print  ("\n Hour   |");
      for  (byte n = 12; n < 24; n++)
      {
        ConOut.printf("   %02u   |", n);
      }
      ConOut.print  ("\n Bat Ah |");
      for  (byte n = 12; n < 24; n++)
      {
        ConOut.printf(" %+02.3f |", AhBat[n]);
      }
      ConOut.println("");
      serialPage = 0;
      break;
    case 'b':
      ConOut.printf("Ah: %+2.3f, Volt: %2.3f, Amp: %2.3f, Watt: %2.3f, %%Batt: %2.1f IntRes: %1.3f\n", AhBat[27], battery.voltage , battery.current , battery.power , percent_charged, internal_resistance);
      serialPage = 0;
      break;
  }
}
