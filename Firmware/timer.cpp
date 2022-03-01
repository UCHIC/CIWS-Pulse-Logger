#include "timer.h"
#include <Arduino.h>

timer::timer(){
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
  timekeeper = 0;
  last = 0;
  sei(); // allow interrupts
}

unsigned long timer::pulseDiff(uint16_t timerReg){
  next = (timekeeper + (timerReg / 7.8125));
//  Serial.print("Last:");
//  Serial.println(last);
//  Serial.print("Next:");
//  Serial.println(next);
//  Serial.print("Temp:");
//  Serial.println(temp);
//  Serial.print("Timekeeper:");
//  Serial.println(timekeeper);
  temp = next - last;
  last = next;
//  Serial.print("Last:");
//  Serial.println(last);
//  Serial.print("Next:");
//  Serial.println(next);
//  Serial.print("Temp:");
//  Serial.println(temp);
//  Serial.print("Timekeeper:");
//  Serial.println(timekeeper);
  return temp;
}

void timer::incrementKeeper(){
  timekeeper += 8000;
}

bool timer::pulseInLastSecond(){
  return last + 1000 > timekeeper;
}
