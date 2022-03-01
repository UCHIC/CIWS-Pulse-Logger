#include <avr/sleep.h>
#include "MAG_LIS3MDL.h"
#include "RTC_PCF8523.h"
#include "timer.h"
#include "memory.h"

volatile bool newDay;                                               //declare inturrupt flag variable for RTC interrupt
volatile bool incrementTimer;                                       //declare inturrupt flag variable for timer1 interrupt
volatile uint16_t newPulse;                                         //declare inturrupt variable for MAG inturrupt

memory memory;                                                      //instantiate memory class
timer timer;                                                        //instantiate timer class
RTC RTC;                                                            //instantiate RTC class
MAG MAG;                                                            //instantiate MAG class

void setup() {
  Serial.begin(115200);                                             //start serial communication for user communication
  Serial.println("Started!");
  memory.EEPROMToMemory();                                          //read site and id from eeprom and store in class variables
  Serial.println("St");
  RTC.init();                                                       //initialize RTC
  Serial.println("ar");
  RTC.RTCToDateTime(memory.DateTime);                               //read RTC date/time and store in memory class variable
  Serial.println("te");
  timer.restartTimer();                                             //zero out timer class counter
  Serial.println("d!");
  
  ///Setup Site Number
  while (!Serial.available()){}                                     //wait until user sends data
  Serial.read();                                                    //read byte and throw away
  Serial.print(F("Is "));                                           //print first part of sentence
  Serial.print(memory.site);                                        //print site
  Serial.println(F(" the correct site? y/n"));                      //print last part of sentence
  while (!Serial.available()){}                                     //wait until user sends data
  if (Serial.read() == 'n')                                         //if data is 'n' then site is incorrect and needs to be set
  {
    Serial.println("Input three digit site number.");                 //print instructions for setting sit
    for(int a = 0; a<3; a++)                                          //for each digit in site
    {
      while (!Serial.available()){}                                     //wait until user sends data
      char temp = Serial.read();                                        //store user data in temp
      memory.site[a] = temp;                                            //store temp in site array
      Serial.println(temp);                                             //print temp
    }
  }

  ///Setup device ID
  if(memory.id[3] != 99)                                            //check if id needs to be set
  {
    Serial.println(F("What is the three digit device ID?"));          //send instructions for setting id
    for(int a = 0; a<3; a++)                                          //for each digit in site
    {
      while (!Serial.available()){}                                     //wait until user sends data
      char temp = Serial.read();                                        //store user data in temp
      memory.id[a] = temp;                                              //store temp in id array
      Serial.println(temp);                                             //print temp
    }
    memory.id[3] = 99;                                                //set so id isnt set again
  }

  ///Setup date and time
  Serial.print(F("Is "));                                           //print first part of sentence
  Serial.print(memory.DateTime);                                    //print DateTime
  Serial.println(F(" the correct date and time? y/n"));             //print last part of sentence
  while (!Serial.available()){}                                     //wait for user input
  if (Serial.read() == 'n'){                                        //if input is 'n' then date and time are incorrect and need to be set
    int pos[13]= {2, 3, 5, 6, 8, 9, 11, 12, 14, 15, 17, 18};          //declare array of import positions in DateTime array
    for(int a = 0; a<12; a++)                                         //for each position in pos
    {
      memory.DateTime[pos[a]] = '-';                                    //set each position in pos to '-'
    }
    Serial.println(F("Input date and time."));                        //send directions
    Serial.println(memory.DateTime);                                  //print DateTime
    for(int c = 0; c<12; c++)                                         //for each position in pos
    {
      while (!Serial.available()){}                                     //wait until data available                                       
      memory.DateTime[pos[c]] = Serial.read();                          //write data to DateTime
      Serial.println(memory.DateTime);                                  //print updated DateTime
    }
    RTC.DateTimeToRTC(memory.DateTime);                               //write new DateTime to RTC
    timer.restartTimer();                                             //zero out timer class counter
  }

  memory.MemoryToEEPROM();                                          //write class variables to eeprom

  ///Pin Configuration
  pinMode(2, INPUT);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT);
  
  ///Class initialize
  RTC.init();                                                       //initialize RTC class
  MAG.init();                                                       //initialize MAG class
  memory.initSD();                                                  //initialize SD card

  RTC.stopAlarm();
  MAG.setThreshold();

  ///Global Variable Definitions
  newDay = false;
  incrementTimer = false;
  newPulse = 0;
  ///Inturrupt Configuration
  attachInterrupt(digitalPinToInterrupt(2), MAG_INT, CHANGE);
  attachInterrupt(digitalPinToInterrupt(3), RTC_INT, FALLING);
  ///Power use minimization
  ADCSRA = 0; //disable ADC
  power_adc_disable(); // ADC converter
  power_timer0_disable();// Timer 0
  //power_timer1_disable();// Timer 1
  power_timer2_disable();// Timer 2
  noInterrupts ();           // timed sequence follows
  // turn off brown-out enable in software
  MCUCR = bit (BODS) | bit (BODSE);  // turn on brown-out enable select
  MCUCR = bit (BODS);        // this must be done within 4 clock cycles of above
  interrupts ();
}

void loop() {
  if (newDay){
    Serial.println("newDay");
    newDay = false;
    memory.writeToSD();
    RTC.RTCToDateTime(memory.DateTime);
    RTC.stopAlarm();
    timer.restartTimer();
    memory.initSD();
  }
  
  if (newPulse){
    Serial.println("in newpulse");
    MAG.changeThreshold();
    if(digitalRead(2) && memory.addToBuffer(timer.pulseDiff(newPulse))){
      memory.writeToSD();
    }
    newPulse = 0;
  }

  if (incrementTimer){
    incrementTimer = false;
    timer.incrementKeeper();
//    digitalWrite(A3, !digitalRead(A3));
//    if(MAG.HZ != .625 && !timer.pulseInLastSecond()){ //Check MAG.HZ first to not waste time evaluating pulse in last second
//      MAG.HZto0625();
//    }
  }
  
  if (!newPulse && !newDay && !incrementTimer){
    set_sleep_mode (SLEEP_MODE_IDLE);  
    sleep_enable();
    sleep_cpu();
    noInterrupts ();           // timed sequence follows
    // turn off brown-out enable in software
    MCUCR = bit (BODS) | bit (BODSE);  // turn on brown-out enable select
    MCUCR = bit (BODS);        // this must be done within 4 clock cycles of above
    interrupts ();
  }
}

void MAG_INT(){
  newPulse = TCNT1;
}

void RTC_INT(){
  Serial.println("newday Int");
  newDay = true;
}

ISR(TIMER1_COMPA_vect){
  incrementTimer = true;
}
