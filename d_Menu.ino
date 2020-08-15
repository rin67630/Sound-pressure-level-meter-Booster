void menuRun()
{
  if (Serial.available())   inbyte = Serial.read(); //Serial input available
  if (inbyte >= 31 & (inbyte < 128)) stopAK = true;
  switch (inbyte)
  {
    //====(Handshake with DFLD Zelle Gateway)======
    case 0:
      break;
    case 1: //Switch to mode 1
      delay(10);
      Serial.write (inbyte) ;     inbyte = 0 ; stopAK = false;
      break;
    case 2: //Switch to mode 2
      delay(10);
      Serial.write (inbyte) ;     inbyte = 0 ; stopAK = false;
      break;
    case 27: //Serial query
      delay(10);
      Serial.write (inbyte) ;     inbyte = 0 ;  stopAK = true;
      break;
    case 11: //Query of operation mode
      delay(10);
      Serial.write (1) ;     inbyte = 0 ;  stopAK = false;
      break;

    //====(Serial Menu)======
    case '0': //Display mode 0
      displayPage = 0;
      ConOut.println ("Off");
      break;
    case '1': //Display mode 1
      displayPage = 1;
      ConOut.println ("D=1");
      break;
    case '2': //Display mode 2
      displayPage = 2;
      ConOut.println ("D=2");
      break;
    case '3': //Display mode 3
      displayPage = 3;
      ConOut.println ("D=3");
      break;
    case '?': //List parameters
      ConOut.printf("Par.List \n\r @94= %d @47= %d DAC= %d Corr= %d \n\rDPage: %d DSPage: %d SPage: %d\n\r", A094, A047, A0Raw, corrdB, displayPage, displaySubPage, serialPage);
      break;
    case 'Z':  //Reset
      ConOut.println ("\n\rwill reset in 10s...");
      delay(10000);
      ESP.restart();
      break;
    case 'C': //Apply 94dB Calibration
      ConOut.print ("\n\rCal94=");
      corrdB = 0;
      A094 = A0Raw;
      ConOut.println (A094);
      break;
    case 'c': //Apply 47dB Calibration
      ConOut.print ("Cal47=");
      corrdB = 0;
      A047 = A0Raw;
      ConOut.println (A047);
      break;
    case 'U': //Apply 94&47dB Defaults
    case 'u':
      A094 = Ao94;
      A047 = Ao47;
      ConOut.println ("\n\rUncal");
      break;
    case '+': //Increase Offset
      corrdB ++;
      ConOut.print ("+1dB=");
      ConOut.println (corrdB);
      break;
    case '-': //Reduce Offset
      corrdB --;
      ConOut.print ("-1dB=");
      ConOut.println (corrdB);
      break;
    case 'A': //serialPage AK
      serialPage = 'A';
      ConOut.println ("\n\rSer=AK");
      break;

    // ***Options for periodical Reports**
    case 'D': //Day Report
      serialDay = true;
      break;
    case 'd': //no Day Report
      serialDay = false;
      break;
    case 'H': //Hour Report
      serialHur = true;
      break;
    case 'h': //No Hour Report
      serialHur = false;
      break;
    case 'M': //Minute Report
      serialMin = true;
      break;
    case 'm': //no Minute Report
      serialMin = false;
      break;
    case 'S': //Second Report
      serialSec = true;
      break;
    case 's': //No Second Report
      serialSec = false;
      break;
    case 'E': //Events
      serialNAT = true;
      break;
    case 'e': //No Events
      serialNAT = false;
      break;

    // ***On/Off for periodical Reports**
    case 'P': //Periodical Reports
      serialPage = 'P';
      break;
    case 'p': //no more Periodical Reports
      serialPage = 0;
      break;

    case 'L': //serialPage Leq one shot
      serialPage = 'L';
      ConOut.print ("\n\rLeq :");
      break;
    case 'N': //serialPage NAT List one shot
      serialPage = 'N';
      ConOut.print ("\n\rNAT :");
      break;
    case 'T':  //Trace Report
      serialPage = 'T';
      ConOut.print ("\n\rTrace Report :");
      break;
   case 'B':  //Battery Report one shot
      serialPage = 'B';
      ConOut.println ("\n\rBattery History :");
      break;
   case 'b':  //Battery Report one shot
      serialPage = 'b';
      ConOut.println ("\n\rBattery Status :");
      break;
    case '~':
      WiFi.printDiag(Serial);
     ConOut.printf("\n\rmac address: %s , \n\rHostname: %s\n\r", WiFi.macAddress().c_str(), WiFi.hostname().c_str());
     ConOut.print("\n\rIP address: "); ConOut.println(WiFi.localIP());         
      break;
  } //end switch (inbyte)

  inbyte = 0 ;
}
