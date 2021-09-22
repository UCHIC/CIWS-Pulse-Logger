class timer{
  private:
  unsigned long timekeeper;
  unsigned long last;
  unsigned long next;
  unsigned long temp;
  public:
  timer();
  void restartTimer();
  unsigned long pulseDiff(uint16_t timerReg);
  void incrementKeeper();
  bool pulseInLastSecond();
};
