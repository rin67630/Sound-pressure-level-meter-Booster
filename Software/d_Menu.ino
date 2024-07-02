void menuRun() 
{

  if (Console1.available()) serialReceived = Console1.read();  //Serial/Telnet input available
  if (Serial.available())   serialReceived = Serial.read();
  if ((serialReceived >= 31) & (serialReceived < 128)) stopAK = true;

  switch (serialReceived) {
    //====(Handshake with DFLD Zelle Gateway)======
    case 0:
      break;
    case 1:  //Switch to mode 1
      delay(10);
      Serial.write(serialReceived);
      serialReceived = 0;
      stopAK = false;
      break;
    case 2:  //Switch to mode 2
      delay(10);
      Serial.write(serialReceived);
      serialReceived = 0;
      stopAK = false;
      break;
    case 27:  //Serial query
      delay(10);
      Serial.write(serialReceived);
      serialReceived = 0;
      stopAK = true;
      break;
    case 11:  //Query of operation mode
      delay(10);
      Serial.write(1);
      serialReceived = 0;
      stopAK = false;
      break;

    //====(Serial Menu)======
    case '0':  // Display Off
    case '1':  // BatV&BatI + LodOn
    case '2':  // PanelV    + Setpoint
    case '3':  // BatV      + Setpoint
    case '4':  // BatI      + Setpoint
    case '5':  // All values+ OpMode
    case '6':
      Console1.print("Switch display to ");
      Console1.write(serialReceived);
      Console1.println();
      displayPage = serialReceived;
    case '?':  //List parameters
      Console1.printf("Par.List \n @94= %d @47= %d DAC= %d Corr= %d \nDPage: %d SPage: %d\n", A094, A047, A0Raw, corrdB, displayPage, serialPage);
      break;
    case 'X':  // forgetWiFI and Reset ESP
      Console1.printf("\nforgetting WiFI! \n");
      ESP.eraseConfig();
      //intentionally no break here: it goes further with 'Z' !
    case 'Z':  //Reset
      Console1.printf("\nReset! \n");
#if defined(TERM_IS_TELNET)
      Console1.stop();
#endif
      delay(100);
      ESP.restart();
      break;
    case 'C':  //Apply 94dB Calibration
      Console1.print("\nCal94=");
      corrdB = 0;
      A094 = A0Raw;
      Console1.println(A094);
      break;
    case 'c':  //Apply 47dB Calibration
      Console1.print("Cal47=");
      corrdB = 0;
      A047 = A0Raw;
      Console1.println(A047);
      break;
    case 'U':  //Apply 94&47dB Defaults
    case 'u':
      A094 = Ao94;
      A047 = Ao47;
      Console1.println("\nUncal");
      break;
    case '+':  //Increase Offset
      corrdB++;
      Console1.print("+1dB=");
      Console1.println(corrdB);
      break;
    case '-':  //Reduce Offset
      corrdB--;
      Console1.print("-1dB=");
      Console1.println(corrdB);
      break;
    case 'A':  //serialPage AK
      serialPage = 'A';
      Console1.println("\nSer=AK");
      break;
    case 'J':  //Debug Report
      Console1.printf("\nJob mS\n");
      serialPage = 'J';
      break;
    case 'j':  //Reset Job Maxes
      Console1.printf("\nReset Job mS\n");
      for (int i = 14; i < 21; i++) RunMillis[i] = 0;  // Reset job timing stats
      break;

    // ***Options for periodical Reports**
    case 'D':  //Day Report
      serialDay = true;
      break;
    case 'd':  //no Day Report
      serialDay = false;
      break;
    case 'H':  //Hour Report
      serialHur = true;
      break;
    case 'h':  //No Hour Report
      serialHur = false;
      break;
    case 'M':  //Minute Report
      serialMin = true;
      break;
    case 'm':  //no Minute Report
      serialMin = false;
      break;
    case 'S':  //Second Report
      serialSec = true;
      break;
    case 's':  //No Second Report
      serialSec = false;
      break;
    case 'E':  //Events
      serialNAT = true;
      break;
    case 'e':  //No Events
      serialNAT = false;
      break;

    // ***On/Off for periodical Reports**
    case 'P':  //Periodical Reports
      serialPage = 'P';
      break;
    case 'p':  //no more Periodical Reports
      serialPage = 0;
      break;
    case 'R':  //Daily Report
      serialPage = 'R';
      sprintf(charbuff, " \nReport for %02d / %02d / %04d:", Day, Month, Year);
      Console1.println(charbuff);
      break;
    case 'L':  //serialPage Leq one shot
     serialPage = 'L';
      Console1.println("\nLeq  / Hour matrix:");
      break;
    case 'N':  //serialPage NAT List one shot
      serialPage = 'N';
      Console1.println("\nNAT / Hour matrix:");
      break;
    case 'T':  //Trace Report
      serialPage = 'T';
      Console1.println("\nTrace :");
      break;
    case 'B':  //Battery Report one shot
      serialPage = 'B';
      Console1.println("\nBattery :");
      break;
    case 'V':  // Equivalent to "ESP" Single shot
      serialPage = 'V';
      Console1.println("\nValues Report:");
      break;
    case 'W':  //Weather Report one shot
      serialPage = 'W';
      Console1.println("\nWeather :");
      break;
    case '#':                               //Debug report
      Console1.printf("A0: %i BatV:%05.2fV BatI:%05.3fA BatPoC:%4.1f%% IOhm:%5.4fR UDP:%4i\n", analogRead(A0), payload.BatV, payload.BatI, payload.BatPoC, payload.IOhm , sizeof(payload));
      break;
    case ' ':  //Wait for input, clear Serial page and Display page
      Console1.printf("\nWaiting for input\n");
      serialPage = serialReceived;
      displayPage = serialReceived;
      break;
#if defined(TERM_IS_TELNET)
    case 'Q':  // Logoff from telnet
      TelnetStream.println("bye bye");
      Console1.flush();
      TelnetStream.stop();
      break;
#endif
    case '~':
      WiFi.printDiag(Serial);
      Console1.printf("\nmac address: %s , \nHostname: %s\n", WiFi.macAddress().c_str(), WiFi.hostname().c_str());
      Console1.print("IP address: ");
      Console1.print(WiFi.localIP());
      Console1.print(", dBLevel:");
      Console1.println(WiFi.RSSI());
      break;
  }  //end switch ( serialReceived)

  serialReceived = 0;
}
