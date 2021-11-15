#include <avr/sleep.h>
#include "MAG_LIS3MDL.h"
#include "RTC_PCF8523.h"
#include "timer.h"
#include "memory.h"

volatile bool newDay;
volatile bool incrementTimer;
volatile uint16_t newPulse;

memory memory;
timer timer;
RTC RTC;
MAG MAG;

void setup() {
  Serial.begin(115200);
  memory.EEPROMToFileName();
  RTC.init();
  RTC.RTCToFileName(memory.fileName);
  
  ///Setup Site Number
  while (!Serial.available()){}
  Serial.read();
  Serial.print(F("Is "));
  Serial.print(memory.site[0]);
  Serial.print(memory.site[1]);
  Serial.print(memory.site[2]);
  Serial.println(F(" the correct site? y/n"));
  while (!Serial.available()){}
  if (Serial.read() == 'n')
  {
    Serial.println("Input three digit site number.");
    for(int a = 0; a<3; a++)
    {
      while (!Serial.available()){}
      char temp = Serial.read();
      memory.site[a] = temp;
      Serial.println(temp);
    }
  }

  ///Setup device ID
  if(memory.id[3] != 99)
  {
    Serial.println(F("What is the three digit device ID?"));
    for(int a = 0; a<3; a++)
    {
      while (!Serial.available()){}
      char temp = Serial.read();
      memory.id[a] = temp;
      Serial.println(temp);
    }
    memory.id[3] = 99;
  }

  ///Setup date and time
  Serial.print(F("Is "));
  for (int b = 0; b<19; b++){
    Serial.print(memory.fileName[b]);
  }
  Serial.println(F(" the correct date and time? y/n"));
  while (!Serial.available()){}
  if (Serial.read() == 'n'){
    int pos[13]= {2, 3, 5, 6, 8, 9, 11, 12, 14, 15, 17, 18};
    for(int a = 0; a<12; a++)
    {
      memory.fileName[pos[a]] = '-';
    }
    Serial.println(F("Input date and time."));
    for (int b = 0; b<18; b++){
      Serial.print(memory.fileName[b]);
    }
    Serial.println(memory.fileName[18]);
    for(int c = 0; c<12; c++)
    {
      while (!Serial.available()){}
      char temp = Serial.read();
      memory.fileName[pos[c]] = temp;
      for (int d = 0; d<18; d++){
        Serial.print(memory.fileName[d]);
      }
      Serial.println(memory.fileName[18]);
    }
    RTC.fileNameToRTC(memory.fileName);
  }


  memory.FileNameToEEPROM();
  
  ///Class initialize
  RTC.init();
  MAG.init();
  memory.init();

  MAG.setThreshold();

  ///Pin Configuration
//  DDRD  |=  0b00010000; //input/output
//  DDRD  &=  0b11110001;
//  PORTD =   0b00000000;//high or low
//  PORTD =   0b00000000;
  pinMode(2, INPUT);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT);
  pinMode(5, OUTPUT); //Is asleep
  digitalWrite(5, HIGH);
  attachInterrupt(digitalPinToInterrupt(2), MAG_INT, CHANGE);
  attachInterrupt(digitalPinToInterrupt(3), RTC_INT, FALLING);

  ///Global Variable Definitions
  newDay = false;
  incrementTimer = false;
  newPulse = 0;


  ///Power use minimization
  //power_timer0_enable();// Timer 0
  //power_timer1_enable();// Timer 1
  //power_timer2_enable();//
  //use less power
  ADCSRA = 0; //disable ADC
  power_adc_disable(); // ADC converter
  //power_spi_disable(); // SPI
  //power_usart0_disable();// Serial (USART)
  power_timer0_disable();// Timer 0
  //power_timer1_disable();// Timer 1
  power_timer2_disable();// Timer 2
  //power_twi_disable(); // TWI (I2C)
  noInterrupts ();           // timed sequence follows
  // turn off brown-out enable in software
  MCUCR = bit (BODS) | bit (BODSE);  // turn on brown-out enable select
  MCUCR = bit (BODS);        // this must be done within 4 clock cycles of above
  interrupts ();

  timer.restartTimer();
}

void loop() {
  //digitalWrite(5, HIGH);
  if (newDay){
    Serial.println("newDay");
    newDay = false;
    memory.writeToSD();
    RTC.RTCToFileName(memory.fileName);
    RTC.stopAlarm();
    timer.restartTimer();
  }
  
  if (newPulse){
    Serial.println("newPulse");
    //if(MAG.HZ != 560){
    //  MAG.HZto560();
    //}
    digitalWrite(5, HIGH);
    MAG.changeThreshold();
    digitalWrite(5, LOW);
    if(digitalRead(2) && memory.addToBuffer(timer.pulseDiff(newPulse))){
      memory.writeToSD();
    }
    newPulse = 0;
  }

  if (incrementTimer){
    incrementTimer = false;
    timer.incrementKeeper();
//    if(MAG.HZ != .625 && !timer.pulseInLastSecond()){ //Check MAG.HZ first to not waste time evaluating pulse in last second
//      MAG.HZto0625();
//    }
  }
  //digitalWrite(5, LOW);
  if (!newPulse && !newDay && !incrementTimer){
    //digitalWrite(5, LOW);
    set_sleep_mode (SLEEP_MODE_IDLE);  
    sleep_enable();
    sleep_cpu();
    noInterrupts ();           // timed sequence follows
    // turn off brown-out enable in software
    MCUCR = bit (BODS) | bit (BODSE);  // turn on brown-out enable select
    MCUCR = bit (BODS);        // this must be done within 4 clock cycles of above
    interrupts ();

    //digitalWrite(5, HIGH);
  }
}

void MAG_INT(){
  //digitalWrite(5, LOW);
  newPulse = TCNT1;
  //digitalWrite(5, HIGH);
}

void RTC_INT(){
  newDay = true;
}

ISR(TIMER1_COMPA_vect){
  incrementTimer = true;
}
