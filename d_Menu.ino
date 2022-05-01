void menuRun()
{
  if (Console0.available())   inbyte = Console0.read(); //Serial input available
  if (inbyte >= 31 & (inbyte < 128)) stopAK = true;
  switch (inbyte)
  {
    //====(Handshake with DFLD Zelle Gateway)======
    case 0:
      break;
    case 1: //Switch to mode 1
      delay(10);
      Console0.write (inbyte) ;     inbyte = 0 ; stopAK = false;
      break;
    case 2: //Switch to mode 2
      delay(10);
      Console0.write (inbyte) ;     inbyte = 0 ; stopAK = false;
      break;
    case 27: //Serial query
      delay(10);
      Console0.write (inbyte) ;     inbyte = 0 ;  stopAK = true;
      break;
    case 11: //Query of operation mode
      delay(10);
      Console0.write (1) ;     inbyte = 0 ;  stopAK = false;
      break;

    //====(Serial Menu)======
    case '0': //Display mode 0
      displayPage = 0;
      Console1.println ("Off");
      break;
    case '1': //Display mode 1
      displayPage = 1;
      Console1.println ("D=1");
      break;
    case '2': //Display mode 2
      displayPage = 2;
      Console1.println ("D=2");
      break;
    case '3': //Display mode 3
      displayPage = 3;
      Console1.println ("D=3");
      break;
    case '?': //List parameters
      Console1.printf("Par.List \n @94= %d @47= %d DAC= %d Corr= %d \nDPage: %d DSPage: %d SPage: %d\n", A094, A047, A0Raw, corrdB, displayPage, displaySubPage, serialPage);
      break;
    case 'Z':  //Reset
      Console1.println ("\nwill reset in 10s...");
      delay(10000);
      ESP.restart();
      break;
    case 'C': //Apply 94dB Calibration
      Console1.print ("\nCal94=");
      corrdB = 0;
      A094 = A0Raw;
      Console1.println (A094);
      break;
    case 'c': //Apply 47dB Calibration
      Console1.print ("Cal47=");
      corrdB = 0;
      A047 = A0Raw;
      Console1.println (A047);
      break;
    case 'U': //Uncalbrated apply 94&47dB Defaults from Program
    case 'u':
      A094 = Ao94;
      A047 = Ao47;
      Console1.println ("\nUncal");
      break;
    case '+': //Increase Offset
      corrdB ++;
      Console1.print ("+1dB=");
      Console1.println (corrdB);
      break;
    case '-': //Reduce Offset
      corrdB --;
      Console1.print ("-1dB=");
      Console1.println (corrdB);
      break;
    case 'A': //serialPage AK
      serialPage = 'A';
      Console1.println ("\nSer=AK");
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
    case 'R': //Daily Report
      serialPage = 'R';
      break;
    case 'P': //Periodical Reports
      serialPage = 'P';
      break;
    case 'p': //no more Periodical Reports
      serialPage = 0;
      break;

    case 'L': //serialPage Leq one shot
      serialPage = 'L';
      Console1.print ("\nLeq :");
      break;
    case 'N': //serialPage NAT List one shot
      serialPage = 'N';
      Console1.print ("\nNAT :");
      break;
    case 'T':  //Trace Report
      serialPage = 'T';
      Console1.print ("\nTrace Report :");
      break;
   case 'B':  //Battery Report one shot
      serialPage = 'B';
      Console1.println ("\nBattery History :");
      break;
   case 'b':  //Battery Report one shot
      serialPage = 'b';
      Console1.println ("\nBattery Status :");
      break;
   case 'W':  //Weather Report one shot
      serialPage = 'W';
      Console1.println ("\nWeather report :");
      break;
    case '~':
      WiFi.printDiag(Serial);
     Console1.printf("\nmac address: %s , \nHostname: %s\n", WiFi.macAddress().c_str(), WiFi.hostname().c_str());
     Console1.print("\nIP address: "); Console1.println(WiFi.localIP());         
      break;
  } //end switch (inbyte)

  inbyte = 0 ;
}
