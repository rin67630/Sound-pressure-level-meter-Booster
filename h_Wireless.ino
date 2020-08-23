void wirelessRun()
{
  yield();
#if defined (PUBLISH_DFLD)
  UDP.beginPacket(UDP_TARGET, UDP_PORT);
  UDP.write(sound.A0dBAK);
  UDP.endPacket();
#endif

#if defined (PUBLISH_REPORT)  // Read with NetCat Bash command nc -u -l [UDP_PORT +1]
  if (DayExpiring || trigNAT)
  {
    UDP.beginPacket(UDP_TARGET, UDP_PORT + 1);
    if (DayExpiring)
    {
      sprintf(charbuff, " \nDaily Report for \n%s, %02d %s %04d ", DayName , Day , MonthName, Year);
      UDP.print(charbuff);

      UDP.print("\nHour| Leq  |  NAT  |  Ah    |\n");
      for  (byte n = 0; n < 30; n++)
      {
        if (n == 24)
        {
          UDP.print("Extra ""hours"" cf. Man.\n");
        }
        else
        {
          UDP.printf("%02u  | %02.1f |  %03u  | %+02.3f |\n", n, leq[n], NAT[n], AhBat[n]);
        }
      }
      UDP.print("\nNAT|PKTime  |PKdB|Leq4|t10|Leq3|tAT|\n");
    }
    if (trigNAT)
    {
      UDP.printf(" %02u|", NAT[Hour]);  UDP.print(peakTime);  UDP.printf("|%2.1f|%2.1f|%02u |%2.1f|%02u |\n", peakValue , less10dBLEq , less10dBDuration,  aboveThreshLEq , aboveThreshDuration);
    }
    UDP.endPacket();
  }
#endif

  if (NewMinute)
  {
#if defined (PUBLISH_BATTERY)
    memcpy(batteryPayload, &battery, sizeof(battery));
    UDP.beginPacket(UDP_TARGET, UDP_PORT);
    UDP.write(batteryPayload, sizeof(battery));
    UDP.endPacket();
#else
    yield();
#endif
  } else {

#if defined (PUBLISH_SOUND)
    memcpy(soundPayload, &sound, sizeof(sound));
    UDP.beginPacket(UDP_TARGET, UDP_PORT);
    UDP.write(soundPayload, sizeof(sound));
    UDP.endPacket();
#else
    yield();
#endif
  }

#if defined (THINGER)
  yield();
  thing.handle();
#if (defined (SOUND_SOURCE_URL) || defined (SOUND_SOURCE_ANAIN))
  thing.stream("noise");
  thing.stream("energy");
#endif

#if defined (WRITE_BUCKETS)
  if (trigNAT)   thing.write_bucket("EVENT", "EVENT");
  if (NewDay)    thing.write_bucket("DAY", "DAY");
  if (NewHour)   thing.write_bucket("HOUR", "HOUR");
  if (NewMinute) thing.write_bucket("MIN", "MIN");
#endif

  if (Minute % 6 == 3)           //every 10 minutes update persistance data
  {
    //Persistance
    pson persistance;
#if (defined BATTERY_SOURCE_INA) || (defined BATTERY_SOURCE_UDP)
    persistance["currentInt"]    = currentInt ;
    persistance["nCurrent"]      = nCurrent;
    persistance["Ah/hour"]       = AhBat[27];
    persistance["Ah/yesterday"]  = AhBat[26];
    persistance["voltageDelta"]  = voltageDelta;
    persistance["voltageAt4h"]   = voltageAt4h;
    persistance["resistance"]    = internal_resistance;
#endif
    persistance["A0dBSumExp"]    = A0dBSumExp60min;
    persistance["A0dBBgr"]       = sound.A0dBBgr;
    persistance["corrdB"]        = corrdB;
    persistance["A094"]          = A094;
    persistance["A047"]          = A047;

    persistance["temperature"]   = outdoor_temperature;
    persistance["humidity"]      = outdoor_humidity;
    persistance["pressure"]      = outdoor_pressure;
    persistance["wind"]          = outdoor_wind_speed;
    persistance["direction"]     = outdoor_wind_direction;
    persistance["summary"]       = weather_summary;
    persistance["last_update"]   = SecondOfDay;
    thing.set_property("persistance", persistance, true);

    pson lequ;// 0..23=hour, 25=current, 26=lequ 24h, 27= leqDay, 28=leqNight, 29=Lden
    lequ["00h"] = leq[0];
    lequ["01h"] = leq[1];
    lequ["02h"] = leq[2];
    lequ["03h"] = leq[3];
    lequ["04h"] = leq[4];
    lequ["05h"] = leq[5];
    lequ["06h"] = leq[6];
    lequ["07h"] = leq[7];
    lequ["08h"] = leq[8];
    lequ["09h"] = leq[9];
    lequ["10h"] = leq[10];
    lequ["11h"] = leq[11];
    lequ["12h"] = leq[12];
    lequ["13h"] = leq[13];
    lequ["14h"] = leq[14];
    lequ["15h"] = leq[15];
    lequ["16h"] = leq[16];
    lequ["17h"] = leq[17];
    lequ["18h"] = leq[18];
    lequ["19h"] = leq[19];
    lequ["20h"] = leq[20];
    lequ["21h"] = leq[21];
    lequ["22h"] = leq[22];
    lequ["23h"] = leq[23];
    lequ["Leq"] = leq[25];
    lequ["Day"] = leq[26];
    lequ["Daytime"] = leq[27];
    lequ["Nighttime"] = leq[28];
    lequ["Lden"] = leq[29];
    lequ["L22-24h"] = leq[30];
    thing.set_property("lequ", lequ);

    pson NATu;// 0..23=hour, 25=current, 26=NATu 24h, 27= NATDay, 28=NATNight, 29=22-24
    NATu["00h"] = NAT[0];
    NATu["01h"] = NAT[1];
    NATu["02h"] = NAT[2];
    NATu["03h"] = NAT[3];
    NATu["04h"] = NAT[4];
    NATu["05h"] = NAT[5];
    NATu["06h"] = NAT[6];
    NATu["07h"] = NAT[7];
    NATu["08h"] = NAT[8];
    NATu["09h"] = NAT[9];
    NATu["10h"] = NAT[10];
    NATu["11h"] = NAT[11];
    NATu["12h"] = NAT[12];
    NATu["13h"] = NAT[13];
    NATu["14h"] = NAT[14];
    NATu["15h"] = NAT[15];
    NATu["16h"] = NAT[16];
    NATu["17h"] = NAT[17];
    NATu["18h"] = NAT[18];
    NATu["19h"] = NAT[19];
    NATu["20h"] = NAT[20];
    NATu["21h"] = NAT[21];
    NATu["22h"] = NAT[22];
    NATu["23h"] = NAT[23];
    NATu["NAT"] = NAT[25];     //25=current event 26=Nat24h 27= Daytime 28= Nighttime 29= 22h-24h
    NATu["Day"] = NAT[26];
    NATu["Daytime"] = NAT[27];
    NATu["Nighttime"] = NAT[28];
    NATu["NAT22-24"] = NAT[29];
    thing.set_property("NATu", NATu);

    pson BATmAh;// 0..23=hour, 25=current, 26=BATmAh 24h, 27= AhBatDay, 28=AhBatNight, 29=22-24
    BATmAh["00h"] = AhBat[0];
    BATmAh["01h"] = AhBat[1];
    BATmAh["02h"] = AhBat[2];
    BATmAh["03h"] = AhBat[3];
    BATmAh["04h"] = AhBat[4];
    BATmAh["05h"] = AhBat[5];
    BATmAh["06h"] = AhBat[6];
    BATmAh["07h"] = AhBat[7];
    BATmAh["08h"] = AhBat[8];
    BATmAh["09h"] = AhBat[9];
    BATmAh["10h"] = AhBat[10];
    BATmAh["11h"] = AhBat[11];
    BATmAh["12h"] = AhBat[12];
    BATmAh["13h"] = AhBat[13];
    BATmAh["14h"] = AhBat[14];
    BATmAh["15h"] = AhBat[15];
    BATmAh["16h"] = AhBat[16];
    BATmAh["17h"] = AhBat[17];
    BATmAh["18h"] = AhBat[18];
    BATmAh["19h"] = AhBat[19];
    BATmAh["20h"] = AhBat[20];
    BATmAh["21h"] = AhBat[21];
    BATmAh["22h"] = AhBat[22];
    BATmAh["23h"] = AhBat[23];
    BATmAh["LastHour"] = AhBat[25];
    BATmAh["Yesterday"] = AhBat[26];
    BATmAh["Today"] = AhBat[27];
    thing.set_property("BAT", BATmAh);
  }
#endif // defined Thinger
}
