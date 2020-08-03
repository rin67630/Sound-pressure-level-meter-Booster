void wirelessRun()
{
  yield();
  //  Serial.print("Wi");

#if defined (UDPOUT)
  memcpy(soundPayload, &sound, sizeof(sound));
  UDP.beginPacket(UDP_TARGET, UDP_PORT);
  UDP.write(soundPayload, sizeof(sound));
  UDP.endPacket();
  if (newMinute)
  {
    memcpy(batteryPayload, &battery, sizeof(battery));
    UDP.beginPacket(UDP_TARGET, UDP_PORT);
    UDP.write(batteryPayload, sizeof(battery));
    UDP.endPacket();
  }
#endif

#if defined (THINGER)
  yield();
  thing.handle();

#if (defined (SOUNDSOURCE_URL) || defined (SOUNDSOURCE_ANAIN))
  thing.stream("noise");
#endif

  // pushing the signals at limits to set plot ranges and stats until Thinger manages fixed ranges.
  if (SecondOfDay == 14400) // set low range at 04:00
  {
    battery.voltage = MIN_VOLT;
    battery.current = MIN_AMP;
    battery.power   = MIN_WATT;
    sound.A0dBSlow = 30;
    thing.stream("noise");
  }
  if (SecondOfDay == 14460) // set high range at 04:01
  {
    battery.voltage = MAX_VOLT;
    battery.current = MAX_AMP;
    battery.power   = MAX_WATT;
    sound.A0dBSlow = 94;
    thing.stream("noise");
  }
  if (SecondOfDay == 14520) // set regular value back at 04:02
  {
    battery.voltage = ina_voltage / 1000;
    battery.current = ina_current / -1000000;
    sound.A0dBSlow = sound.A0dBFast;
    thing.stream("noise");
  }

#if defined (BUCKET)
  if (trigNAT)   thing.write_bucket("EVENT", "EVENT");
  if (NewDay)    thing.write_bucket("DAY", "DAY");
  if (NewHour)   thing.write_bucket("HOUR", "HOUR");
  if (NewMinute) thing.write_bucket("MIN", "MIN");
#endif

  if (Minute % 6 == 3)           //every 10 minutes update persistance data
  {
    //Persistance
    pson persistance;
#if defined BATTERY_MONITORING
    persistance["currentInt"]    = currentInt ;
    persistance["nCurrent"]      = nCurrent;
    persistance["Ah/hour"]       = mAhBat[27];
    persistance["Ah/yesterday"]  = mAhBat[26];
    persistance["voltageDelta"]  = voltageDelta;
    persistance["voltageAt4h"]   = voltageAt4h;
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
    lequ["04h"] = lequ[4];
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
    NATu["NAT"] = NAT[25];
    NATu["Day"] = NAT[26];
    NATu["Daytime"] = NAT[27];
    NATu["Nighttime"] = NAT[28];
    NATu["NAT22-24"] = NAT[29];
    thing.set_property("NATu", NATu);

    pson BATmAh;// 0..23=hour, 25=current, 26=BATmAh 24h, 27= mAhBatDay, 28=mAhBatNight, 29=22-24
    BATmAh["00h"] = mAhBat[0];
    BATmAh["01h"] = mAhBat[1];
    BATmAh["02h"] = mAhBat[2];
    BATmAh["03h"] = mAhBat[3];
    BATmAh["04h"] = mAhBat[4];
    BATmAh["05h"] = mAhBat[5];
    BATmAh["06h"] = mAhBat[6];
    BATmAh["07h"] = mAhBat[7];
    BATmAh["08h"] = mAhBat[8];
    BATmAh["09h"] = mAhBat[9];
    BATmAh["10h"] = mAhBat[10];
    BATmAh["11h"] = mAhBat[11];
    BATmAh["12h"] = mAhBat[12];
    BATmAh["13h"] = mAhBat[13];
    BATmAh["14h"] = mAhBat[14];
    BATmAh["15h"] = mAhBat[15];
    BATmAh["16h"] = mAhBat[16];
    BATmAh["17h"] = mAhBat[17];
    BATmAh["18h"] = mAhBat[18];
    BATmAh["19h"] = mAhBat[19];
    BATmAh["20h"] = mAhBat[20];
    BATmAh["21h"] = mAhBat[21];
    BATmAh["22h"] = mAhBat[22];
    BATmAh["23h"] = mAhBat[23];
    BATmAh["LastHour"] = mAhBat[25];
    BATmAh["Yesterday"] = mAhBat[26];
    BATmAh["Today"] = mAhBat[27];

    thing.set_property("BAT", BATmAh);
  }
#endif
}
