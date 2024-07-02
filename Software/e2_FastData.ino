void data125mSRun() {
  // === ( Getting noise level from A0 ) ===
#if defined(SOUND_SOURCE_IS_A0)
  // Performing 3 reads to get a reliable reading.
  A0Raw = analogRead(A0);  // 1st read  0...1V = 0 ..1023
  delay(3);
  A0Raw += analogRead(A0);  // 2nd read
  delay(3);
  A0Raw += analogRead(A0);  // 3rd read
  A0Raw = A0Raw / 3;

  // Compute linear function: 47dB (difference between 47 and 94dB) / difference between the 2 calibration results
  A0Inst = map(A0Raw, A047, A094, 4700, 9400);
  A0dBAvg = float(A0Inst) / 100 + corrdB;
  sound.A0dBFast = sound.A0dBFast + (A0dBAvg - sound.A0dBFast) / 2;
  sound.A0dBMin = min(sound.A0dBFast, sound.A0dBMin);
  sound.A0dBMax = max(sound.A0dBFast, sound.A0dBMax);
  A0dBMin1min = min(sound.A0dBFast, A0dBMin1min);
  A0dBMax1min = max(sound.A0dBFast, A0dBMax1min);

  // === (Slow (attack t=1s, decay 2,9dB/s)
  if (sound.A0dBFast > sound.A0dBSlow)  //A0 in dB with impulse response
  {
    sound.A0dBSlow += (sound.A0dBFast - sound.A0dBSlow) / 8;  // Low Pass filter 1s
  } else {
    sound.A0dBSlow = sound.A0dBSlow - 0.3625;  //Linear decay 2,9db /sec
  }
  // Impulse (attack t=0,35s, decay 4,3dB/s)
  if (A0dBAvg > sound.A0dBImpulse)  //A0 in dB with impulse response
  {
    sound.A0dBImpulse = A0dBAvg;  //No filter, the response of the SPL is slower
  } else {
    sound.A0dBImpulse = sound.A0dBImpulse - 0.5375;  //Linear decay 4,3db /sec
  }
  sound.A0dBImpulse = max(sound.A0dBImpulse, sound.A0dBSlow);
#else
  yield();
#endif  //defined (SOUND_SOURCE_IS_A0)
#if defined(DASHBRD_IS_THINGER)
#if defined(GRACE_PAUSE)  // Prevent locking if Thinger does not answer
  if (GracePause > 0) GracePause--;
  thingHandleTime = millis();
  if (GracePause == 0) thing.handle();                    // do not call permanently Thinger if it takes too long to respond.
  if (millis() - thingHandleTime > 500) GracePause = 16;  // if the Thinger call took longer than 500ms, make 2s pause before retrying
#else
  thing.handle();
#endif
#endif
}
