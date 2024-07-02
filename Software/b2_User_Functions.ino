// Place here your user functions


void LEQ_Matrix() {
  Console1.print("\n Hour   |");
  for (byte n = 0; n < 12; n++) {
    Console1.printf("  %02u  |", n);
  }
  Console1.print("\n Leq dB |");
  for (byte n = 0; n < 12; n++) {
    Console1.printf(" %04.1f |", leq[n]);
  }
  Console1.print("\n Hour   |");
  for (byte n = 12; n < 24; n++) {
    Console1.printf("  %02u  |", n);
  }
  Console1.print("\n Leq dB |");
  for (byte n = 12; n < 24; n++) {
    Console1.printf(" %04.1f |", leq[n]);
  }
}

void NAT_Matrix() {
  Console1.print("\n Hour   |");
  for (byte n = 0; n < 12; n++) {
    Console1.printf("  %02u  |", n);
  }
  Console1.print("\n NAT    |");
  for (byte n = 0; n < 12; n++) {
    Console1.printf("  %02u  |", NAT[n]);
  }
  Console1.print("\n Hour   |");
  for (byte n = 12; n < 24; n++) {
    Console1.printf("  %02u  |", n);
  }
  Console1.print("\n NAT    |");
  for (byte n = 12; n < 24; n++) {
    Console1.printf("  %02u  |", NAT[n]);
  }
  // Print dB Class statistics
  Console1.print("\n\ndB Class statistics\ndB | +60  | +70  | +80  | +90  |\n");
  for (byte n = 0; n < 10; n++) {
    Console1.printf("%1i  |  %02i  |  %02i  |  %02i  |  %02i  |\n", n, maxLevelClass[n], maxLevelClass[n + 10], maxLevelClass[n + 20], maxLevelClass[n + 30]);
  }
}