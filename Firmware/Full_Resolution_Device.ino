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
  ///User interface
  memory.EEPROMToFileName();
  Serial.begin(115200);
  while (!Serial){}
  Serial.print(memory.fileName[0]);
  Serial.print(memory.fileName[1]);
  Serial.print(memory.fileName[2]);
  Serial.println(memory.fileName[3]);
  Serial.println(F("Is this the correct site?"));

  if(memory.fileName[4] == 255){ // set device id
    
  }

  RTC.RTCToFileName(memory.fileName);
  
  ///Class setup
  RTC.init();
  MAG.init();
  memory.init();

  ///Pin Configuration
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
  power_usart0_disable();// Serial (USART)
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
    //enable sd mosphet
    //power_spi_enable(); // SPI
    memory.writeToSD();
    //disable sd mosphet
    //power_spi_disable(); // SPI
    //power_twi_enable(); // TWI (I2C)
    RTC.RTCToFileName(memory.fileName);
    RTC.stopAlarm();
    //power_twi_disable(); // TWI (I2C)
  }
  
  if (newPulse){
    Serial.println("newPulse");
    if(MAG.HZ != 560){
      MAG.HZto560();
    }
    //digitalWrite(5, LOW);
    if(memory.addToBuffer(timer.pulseDiff(newPulse))){
      //enable sd mosphet
      //power_spi_enable(); // SPI
      Serial.println("writeToSD");
      memory.writeToSD();
      //disable sd mosphet
      //power_spi_disable(); // SPI
    }
    //digitalWrite(5, HIGH);
    newPulse = 0;
  }

  if (incrementTimer){
    Serial.println("Timer Incremented");
    incrementTimer = false;
    timer.incrementKeeper();
    if(MAG.HZ != .625 && !timer.pulseInLastSecond()){ //Check MAG.HZ first to not waste time evaluating pulse in last second
      MAG.HZto0625();
    }
  }

  if (!newPulse && !newDay && !incrementTimer){
    digitalWrite(5, LOW);
    noInterrupts ();           // timed sequence follows
    // turn off brown-out enable in software
    MCUCR = bit (BODS) | bit (BODSE);  // turn on brown-out enable select
    MCUCR = bit (BODS);        // this must be done within 4 clock cycles of above
    interrupts ();
    set_sleep_mode (SLEEP_MODE_IDLE);  
    sleep_enable();
    sleep_cpu ();
    digitalWrite(5, HIGH);
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
