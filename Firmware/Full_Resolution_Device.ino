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
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.begin(115200);
  memory.EEPROMToFileName();
  RTC.init();
  RTC.RTCToFileName(memory.fileName);
  digitalWrite(LED_BUILTIN, LOW);
  ///Setup Site Number
  Serial.print(F("Is "));
  Serial.print(memory.fileName[0]);
  Serial.print(memory.fileName[1]);
  Serial.print(memory.fileName[2]);
  Serial.print(memory.fileName[3]);
  Serial.println(F(" the correct site? y/n"));
  while (!Serial.available()){}
  if (Serial.read() == 'n')
  {
    Serial.println("Input four digit site number.");
    for(int a = 0; a<4; a++)
    {
      while (!Serial.available()){}
      char temp = Serial.read();
      memory.fileName[a] = temp;
      Serial.println(temp);
    }
  }

  ///Setup device ID
  if(memory.fileName[25] == 255)
  {
    Serial.println(F("What is the device ID?"));
    for(int a = 0; a<4; a++)
    {
      while (!Serial.available()){}
      char temp = Serial.read();
      memory.fileName[a+25] = temp;
      Serial.println(temp);
    }
  }

  ///Setup date and time
  Serial.print(F("Is "));
  for (int b = 5; b<24; b++){
    Serial.print(memory.fileName[b]);
  }
  Serial.println(F(" the correct date and time? y/n"));
  while (!Serial.available()){}
  if (Serial.read() == 'n'){
    int pos[13]= {7, 8, 10, 11, 13, 14, 16, 17, 19, 20, 22, 23};
    for(int a = 0; a<12; a++)
    {
      memory.fileName[pos[a]] = '-';
    }
    Serial.println(F("Input date and time."));
    for (int b = 5; b<23; b++){
      Serial.print(memory.fileName[b]);
    }
    Serial.println(memory.fileName[23]);
    for(int a = 0; a<12; a++)
    {
      while (!Serial.available()){}
      char temp = Serial.read();
      memory.fileName[pos[a]] = temp;
      for (int b = 5; b<23; b++){
        Serial.print(memory.fileName[b]);
      }
      Serial.println(memory.fileName[23]);
    }
  }


  memory.FileNameToEEPROM();
  RTC.fileNameToRTC(memory.fileName);
  
  ///Class initialize
  RTC.init();
  MAG.init();
  memory.init();

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
  attachInterrupt(digitalPinToInterrupt(2), MAG_INT, RISING);
  attachInterrupt(digitalPinToInterrupt(3), RTC_INT, FALLING);

  ///Global Variable Definitions
  newDay = false;
  incrementTimer = false;
  newPulse = 0;

  MAG.setThreshold();

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
  if (newDay){
    Serial.println("newDay");
    newDay = false;
    memory.writeToSD();
    RTC.RTCToFileName(memory.fileName);
    RTC.stopAlarm();
  }
  
  if (newPulse){
    Serial.println("newPulse");
    if(MAG.HZ != 560){
      MAG.HZto560();
    }
    if(memory.addToBuffer(timer.pulseDiff(newPulse))){
      memory.writeToSD();
    }
    newPulse = 0;
  }

  if (incrementTimer){
    incrementTimer = false;
    timer.incrementKeeper();
    if(MAG.HZ != .625 && !timer.pulseInLastSecond()){ //Check MAG.HZ first to not waste time evaluating pulse in last second
      MAG.HZto0625();
    }
  }

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
