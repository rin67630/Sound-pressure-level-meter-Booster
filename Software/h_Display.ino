void displayRun()
{
  yield();

#ifdef DISPLAY_IS_OLED64x48
  display.clear();
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_10);
  display.drawString(0, 0,  "Host =" + String() + HOST_NAME);
  sprintf(charbuff, "IP= %03d.%03d", ip[2], ip[3]); display.drawString(0, 12, charbuff);
  display.drawString(0, 24, "Slow =" + String(sound.A0dBSlow)   + "dB");
  display.drawString(0, 36, "Comp =" + String(sound.A0dBImpulse)   + "dB");
  display.display();
#endif
#ifdef DISPLAY_IS_OLED128x64
  display.clear();
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_10);
  // Draw Information matrix
  if (high_power_buck_value)
  {
    display.drawString(0, 0, "H");
  }
  else
  {
    display.drawString(0, 0, "L");
  }
  display.drawString(10, 0,  "|  Panel");
  display.drawString(50, 0,  "| Battery");
  display.drawString(90, 0,  "| Output");
  display.drawString(0, 12, "V ");
  sprintf(charbuff, "| %2.2f", battery.panel); display.drawString(10, 12, charbuff);
  sprintf(charbuff, "| %2.2f", battery.voltage); display.drawString(50, 12, charbuff);
  //sprintf(charbuff, "| %2.2f", battery.Vaux); display.drawString(90, 12, charbuff);
  display.drawString(0, 24, "A ");
  //sprintf(charbuff, "| %1.3f", battery.Ipan); display.drawString(10, 24, charbuff);
  sprintf(charbuff, "| %1.3f", battery.current); display.drawString(50, 24, charbuff);
  //sprintf(charbuff, "| %1.3f", battery.Iaux); display.drawString(90, 24, charbuff);
  display.drawString(0, 36, "W ");
  //sprintf(charbuff, "| %2.2f", battery.Wpan); display.drawString(10, 36, charbuff);
  sprintf(charbuff, "| %2.2f", battery.power); display.drawString(50, 36, charbuff);
  //sprintf(charbuff, "| %2.2f", battery.Waux); display.drawString(90, 36, charbuff);

  buffTimeData();
  display.drawString(0, 50, charbuff);
  if (dashboard.Win > 0.03)
  {
    //sprintf(charbuff, "Eff:%2.1f%%", battery.efficiency);
    display.drawString(75, 50, charbuff);
  }
  display.fillRect(0, 63, Second * 2, 1); //display seconds progress bar
  display.display();

#endif
}
