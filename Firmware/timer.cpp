#include "timer.h"
#include <Arduino.h>

timer::timer(){
  timekeeper = 0;
  last = 0;
}

void timer::restartTimer(){
  /// TIMER 1 for interrupt frequency 0.125 Hz:
  cli(); // stop interrupts
  TCCR1A = 0; // set entire TCCR1A register to 0
  TCCR1B = 0; // same for TCCR1B
  TCNT1  = 0; // initialize counter value to 0
  // set compare match register for 0.125 Hz increments
  OCR1A = 62499; // = 8000000 / (1024 * 0.125) - 1 (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS12, CS11 and CS10 bits for 1024 prescaler
  TCCR1B |= (1 << CS12) | (0 << CS11) | (1 << CS10);
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);
  sei(); // allow interrupts
}

unsigned long timer::pulseDiff(uint16_t timerReg){
  next = (timekeeper + (timerReg / 7.8125));
  temp = next - last;
  last = next;
  return temp;
}

void timer::incrementKeeper(){
  timekeeper += 8000;
}

bool timer::pulseInLastSecond(){
  return last + 1000 > timekeeper;
}
