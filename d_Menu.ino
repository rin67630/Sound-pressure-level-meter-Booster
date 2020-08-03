void menuRun()
{
  // Serial.print("Me");
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
      Serial.println ("Off");
      break;
    case '1': //Display mode 1
      displayPage = 1;
      Serial.println ("D=1");
      break;
    case '2': //Display mode 2
      displayPage = 2;
      Serial.println ("D=2");
      break;
    case '3': //Display mode 3
      displayPage = 3;
      Serial.println ("D=3");
      break;
    case '?': //List parameters
      Serial.printf("Par.List \n @94= %d @47= %d DAC= %d Corr= %d \nDPage: %d DSPage: %d SPage: %d\n", A094, A047, A0Raw, corrdB, displayPage, displaySubPage, serialPage);
      break;
      break;
    case 'Z':  //Reset
      Serial.println ("\nwill reset in 10s...");
      delay(10000);
      ESP.restart();
      break;
    case 'C': //Apply 94dB Calibration
      Serial.print ("\nCal94=");
      corrdB = 0;
      A094 = A0Raw;
      Serial.println (A094);
      break;
    case 'c': //Apply 47dB Calibration
      Serial.print ("Cal47=");
      corrdB = 0;
      A047 = A0Raw;
      Serial.println (A047);
      break;
    case 'U': //Apply 94&47dB Defaults
    case 'u':
      A094 = Ao94;
      A047 = Ao47;
      Serial.println ("\nUncal");
      break;
    case '+': //Increase Offset
      corrdB ++;
      Serial.print ("+1dB=");
      Serial.println (corrdB);
      break;
    case '-': //Reduce Offset
      corrdB --;
      Serial.print ("-1dB=");
      Serial.println (corrdB);
      break;
    case 'A': //serialPage AK
      serialPage = 'A';
      Serial.println ("\nSer=AK");
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
    case 'N': //NAT Report
      serialNAT = true;
      break;
    case 'n': //No NAT Report
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
      Serial.print ("\nLeq");
      break;
    case 'W':  //Weather Report
      serialPage = 'W';
      Serial.println ("\nWeather Report");
      break;
   case 'B':  //Battery Report one shot
      serialPage = 'B';
      Serial.println ("\nBattery History");
      break;
    case '~':
      WiFi.printDiag(Serial);
     Serial.printf("\nmac address: %s , \nHostname: %s\n", WiFi.macAddress().c_str(), WiFi.hostname().c_str());
     Serial.print("\nIP address: "); Serial.println(WiFi.localIP());         
      break;
/*
    default:
      serialPage = inbyte;     
      break;
*/
  } //end switch (inbyte)

  inbyte = 0 ;
  /*
    #if defined(THINGER)
    thing["displayPage"] << inputValue(displayPage);
    thing["serialPage"] << inputValue(serialPage);
    #endif
  */
}
