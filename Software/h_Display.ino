void displayRun()
{
  yield();

#ifdef SCREEN_IS_64x48
  display.clear();
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  
  display.drawString(0, 0,  "Host =" + String() + DEVICE_NAME);
  sprintf(charbuff, "IP= %03d.%03d", ip[2], ip[3]); display.drawString(0, 12, charbuff);
  display.drawString(0, 24, "Slow =" + String(sound.A0dBSlow)   + "dB");
  display.drawString(0, 36, "Comp =" + String(sound.A0dBImpulse)   + "dB");
  display.display();
#endif
#ifdef SCREEN_IS_128x64
  display.clear();
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_10);
  // Draw Information matrix
  /*
  struct  sound {
  float A0dBFast;
  float A0dBMin;
  float A0dBBgr;
  float A0dBMax;
  float A0dBSlow;
  float A0dBImpulse;
  byte  A0dBAK;
  char  fResponse = 'A';
  char  tResponse = 'S';
} sound;
   */
  display.drawString(10, 0,  "  Slow   ");
  display.drawString(50, 0,  "| Impuls");
  display.drawString(90, 0,  "| Backgr");
  display.drawString(0, 12, "A0");
  sprintf(charbuff, "  %5.2f", sound.A0dBSlow); display.drawString(10, 12, charbuff);
  sprintf(charbuff, "| %5.2f", sound.A0dBImpulse); display.drawString(50, 12, charbuff);
  sprintf(charbuff, "| %5.2f", sound.A0dBBgr); display.drawString(90, 12, charbuff);
  display.setFont(ArialMT_Plain_24);  // _10, _16, _24
  sprintf(charbuff, "%5.2f db(A)", sound.A0dBSlow); display.drawString(0, 24, charbuff);
  display.setFont(ArialMT_Plain_10);   // _10, _16, _24
  buffTimeData();
  display.drawString(0, 50, charbuff);
  display.fillRect(0, 63, Second * 2, 1); //display seconds progress bar
  display.display();
#endif
}
