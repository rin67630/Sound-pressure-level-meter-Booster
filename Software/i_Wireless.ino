
void wirelessRun() {
  if (WiFi.status() != WL_CONNECTED)  // Try reconnect
  {
    WiFi.disconnect();
    WiFi.reconnect();
  }
// === (Getting Sound / Battery values from another ESP over UDP
// I use a quick and dirty method called 'type punning' copying the memory block of a structure into an array of chars,
// transmitting this array, and copying back the memory block of the array into the same structure on the other side.
// I dont use any header info, only the difference of size permits to assign the received packets to sound or battery.
// it is quick and damn efficient, but NOT portable and YOU must take care to have the same structures on both systems
// and different sizes for Battery and Sound...
#ifdef SOUND_SOURCE_IS_UDP
  int packetSize = UDP.parsePacket();
  // if (packetSize) Console1.printf("Packet size: %u, Sound size: %u , Battery size; %u \n", packetSize, sizeof(sound), sizeof(payload));
  // if (packetSize) digitalWrite(LED_BUILTIN, false);    // Blink built-in LED on received packets
  if (packetSize == sizeof(sound)) {
    digitalWrite(LED_BUILTIN, false);
    UDP.read(UDPSoundPayload, UDP_TX_PACKET_MAX_SIZE);
    memcpy(&sound, UDPSoundPayload, sizeof(sound));
    //Console1.print(".");
    digitalWrite(LED_BUILTIN, true);
  }
#endif

#ifdef BATTERY_SOURCE_IS_UDP
  int packetSize = UDP.parsePacket();
  if (packetSize == sizeof(payload)) {
    UDP.read(UDPBatPayload, UDP_TX_PACKET_MAX_SIZE);
    memcpy(&payload, UDPBatPayload, sizeof(payload));
    //Console1.print("+");
  }
#endif


#if defined(COM_IS_DAILY)  // Send reports to another computer, read with NetCat Bash command nc -u -l [UDP_PORT +100] [file]
  if ((SecondOfDay == 86398) || TrigEvent || (GracePause > 0)) {
    UDP.beginPacket(UDP_TARGET, COM_UDP_PORT + 100);
    if (SecondOfDay == 86398)  // Two seconds before end of day.
    {
      sprintf(charbuff, " \nDaily Report for day before \n%s, %02d %s %04d ", DayName, Day, MonthName, Year);
      UDP.print(charbuff);

      UDP.print("\nHour| Leq  |  NAT  |  Ah    |\n");
      for (byte n = 0; n < 30; n++) {
        if (n == 24) {
          UDP.print("Extras cf. Man.\n");
        } else {
          UDP.printf("%02u  | %04.1f |  %03u  | %+06.3f |\n", n, leq[n], NAT[n], BatAh[n]);
        }
      }
      // Print dB Class statistics
      UDP.print("\ndB Class statistics\ndB | +60  | +70  | +80  | +90  |\n");
      for (byte n = 0; n < 10; n++) {
        UDP.printf("%1i  |  %02i  |  %02i  |  %02i  |  %02i  |\n", n, maxLevelClass[n], maxLevelClass[n + 10], maxLevelClass[n + 20], maxLevelClass[n + 30]);
      }
      UDP.print("\nNAT|PKTime  |PKdB|Le4 |Leq4|t10|Le3 |Leq3|tAT|\n");
    }
    if (TrigEvent) {
      UDP.printf(" %02u|", NAT[Hour]);
      UDP.print(peakTime);
      UDP.printf("|%4.1f|%4.1f|%4.1f|%03u|%4.1f|%4.1f|%03u|\n", eventPeak, less10dBLE, less10dBLEq, less10dBDuration, aboveThreshLE, aboveThreshLEq, aboveThreshDuration);
    }

    if (GracePause) {
      UDP.printf("GracePause@%02u:%02u %02u\n", Hour, Minute, GracePause);
    }
    UDP.endPacket();
  }
#endif

  yield();

  if (SecondOfDay == 9000)  //Somewehere around 02:30 resync time
  {
    getNTP();
    GracePause = 64;  // make a 8 Seconds pause from Thinger since NTP may take some time
  }

#if defined(DASHBRD_IS_THINGER)

#if defined STREAM_DATA
  if (GracePause == 0) thing.stream("noise");
#endif
/*
  thing.set_state_listener([&](ThingerClient::THINGER_STATE state) {
    switch (state) {
      case ThingerClient::NETWORK_CONNECT_ERROR:
      case ThingerClient::SOCKET_CONNECTION_ERROR:
      case ThingerClient::SOCKET_DISCONNECTED:
      case ThingerClient::SOCKET_ERROR:
      case ThingerClient::SOCKET_TIMEOUT:
        Console1.print("\n Network Error ! \n");
        GracePause = 64;
        break;
      default:
        break;
    }
  });
*/ 


#if defined(WRITE_BUCKETS)
  if (TrigEvent) {
    thing.write_bucket(BUCKET_EVENT, BUCKET_EVENT);
    TrigEvent = false;
  }
  if (NewDay) thing.write_bucket("DAY", "DAY");
  if (HourExpiring) thing.write_bucket("HOUR", "HOUR");
  if (MinuteExpiring) {
    thing.write_bucket(BUCKET_MIN, BUCKET_MIN);
    thingerNAT = false;
  }
#endif


  if (NewMinute && (Minute % 6 == 2))  //every 6 minutes update persistance data
  {
    //Persistance
    pson persistance;
    persistance["A0dBSumExp"] = A0dBSumExp60min;
    persistance["aboveThreshLEint"] = aboveThreshLEint;
    persistance["less10dBLEint"] = less10dBLEint;
    persistance["A0dBBgr"] = sound.A0dBBgr;
    persistance["corrdB"] = corrdB;
    persistance["A094"] = A094;
    persistance["A047"] = A047;

    persistance["temperature"] = temperature;
    persistance["humidity"] = humidity;
    persistance["pressure"] = pressure;
    persistance["wind"] = wind_speed;
    persistance["direction"] = wind_direction;
    persistance["summary"] = weather_summary;
    persistance["last_update"] = SecondOfDay;
    thing.set_property("persistance", persistance, true);
  }
  if ((NewMinute && Minute % 6 == 3))  //every 6 minutes update persistance data
  {
    pson lequ;  // 0..23=hour, 25=current, 26=lequ 24h, 27= leqDay, 28=leqNight, 29=Lden
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
    lequ["EvOT"] = leq[31];
    lequ["EV10"] = leq[32];
    thing.set_property("lequ", lequ);
  }
  if (NewMinute && (Minute % 6 == 4))  //every 6 minutes update persistance data
  {
    pson NATu;  // 0..23=hour, 25=current, 26=NATu 24h, 27= NATDay, 28=NATNight, 29=22-24
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
    NATu["NAT"] = NAT[25];  //25=current event 26=Nat24h 27= Daytime 28= Nighttime 29= 22h-24h
    NATu["Day"] = NAT[26];
    NATu["Daytime"] = NAT[27];
    NATu["Nighttime"] = NAT[28];
    NATu["NAT22-24"] = NAT[29];
    thing.set_property("NATu", NATu);
  }

#endif  // defined Thinger
}


// WiFi.forceSleepBegin();
// WiFi.forceSleepWake();
