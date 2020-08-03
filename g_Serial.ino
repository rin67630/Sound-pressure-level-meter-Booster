void serialRun()
{
  yield();
  switch (serialPage)
  {
    case 'A': //serialPage AK
#if defined (AKOUT)
      Serial.write(sound.A0dBAK);
#endif
#if defined (UDPOUT)
      // Send UDP packet
      UDP.beginPacket(UDP_TARGET, UDP_PORT);
//      UDP.write(sound.A0dBAK);
      UDP.write(soundPayload);
      UDP.endPacket();
#endif
      break;
    // ***  Periodical compound Reports  ***
    case 'P':   
      if (DayExpiring  && serialDay)
      {
        Serial.printf("BatmmAhBat:%3.1f A0dBLEQ:%2.1f WindSpeed:%u Direction:%u\n", mAhBat, leq[25] , outdoor_wind_speed , outdoor_wind_direction);
      }
      if (HourExpiring && serialHur)
      {
        Serial.printf("BatmAhBat:%1.3f A0dBLEQ:%2.1f WindSpeed:%u Direction:%u\n", mAhBat, leq[25] , outdoor_wind_speed , outdoor_wind_direction);
      }
      if (MinuteExpiring && serialMin)
      {
        Serial.printf("BatV:%2.1f BatW:%2.1f Bat%%:%u\n", battery.voltage, battery.power, percent_charged);
      }
      if (serialNAT && trigNAT)
      {
      Serial.print("PKTm: ");
      Serial.print(peakTime);
      Serial.printf(" PKdB:%2.1f ATdB: %2.1f ATsec:%u PK-10dB: %2.1f PK-10sec: %u NAT:%u\n" , peakValue , aboveThreshLEq , aboveThreshDuration, less10dBLEq , less10dBDuration , NAT[Hour]); 
      }      
      if (serialSec)
      Serial.printf("Leq(h-1):%2.1f Imp:%2.1f  Bgr:%2.1f Slow:%2.1f\n", leq[25], sound.A0dBImpulse, sound.A0dBBgr, sound.A0dBSlow);
      break;

    // ***  One shot reports  ***
    case 'L': // Lequ / Hour matrix
      sprintf(charbuff, " for %s, %02d %s %04d ", DayName , Day , MonthName, Year);
      Serial.print(charbuff);
      Serial.print("\n Hour   |");
      for  (byte n = 0; n < 12; n++)
      {
        Serial.printf("  %02u  |", n);
      }
      Serial.print  ("\n Leq dB |");
      for  (byte n = 0; n < 12; n++)
      {
        Serial.printf(" %02.1f |", leq[n]);
      }
      Serial.print("\n Hour   |");
      for  (byte n = 12; n < 24; n++)
      {
        Serial.printf("  %02u  |", n);
      }
      Serial.print  ("\n Leq dB |");
      for  (byte n = 12; n < 24; n++)
      {
        Serial.printf(" %02.1f |", leq[n]);
      }
      Serial.print("\n\n");
      serialPage = 0;
      break;
      
    case 'W': //Weather Report
      Serial.printf("Temp: %2.1f Hum: %u Press: %u @94=%u WindSpeed: %2.1f Direction: %u\n", outdoor_temperature, outdoor_humidity, outdoor_pressure, outdoor_wind_speed, outdoor_wind_direction);
      serialPage = 0;
      break;
       
    case 'T': //Trace noise
      Serial.printf("A0dB=%2.1f ADC=%u @47=%u @94=%u A0dBAK= %u Hex= %X\n", sound.A0dBSlow , A0Raw, A047, A094, sound.A0dBAK, sound.A0dBAK);
      serialPage = 0;
      break;
            
    case 'B':  //Battery Report
      Serial.print  ("\n Hour   |");
      for  (byte n = 0; n < 12; n++)
      {
        Serial.printf("  %02u   |", n);
      }
      Serial.print  ("\n BatmAh |");
            for  (byte n = 0; n < 12; n++)
      {
        Serial.printf(" %01.3f |", mAhBat[n]);
      }
      Serial.print  ("\n Hour   |");
            for  (byte n = 13; n < 24; n++)
      {
      Serial.printf("  %02u   |", n);
      }
      Serial.print  ("\n BatmAh |");
            for  (byte n = 13; n < 24; n++)
      {
        Serial.printf(" %01.3f |", mAhBat[n]);
      }
      Serial.println();
      serialPage = 0;
      break;
    case 'b':
      Serial.printf("Ah: %2.1f, Volt: %2.1f, Amp: %2.1f, Watt: %2.1f, %%Batt: %2.1f\n", mAhBat, battery.voltage , battery.current , battery.power , percent_charged);
      serialPage = 0;
      break;
  }
}
