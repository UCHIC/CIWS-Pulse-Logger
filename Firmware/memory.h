#include <avr/power.h>
#include <Arduino.h>
#include <SD.h>
#include <SPI.h>
#include <EEPROM.h>
#include "date_t.h"

#define bufferSize 10

class memory{
  private:
  unsigned long Buffer[bufferSize];
  int pos;
  File dataFile;
  public:
  char fileName[29] = {'?','?','?','?','-','2','0','?','?','/','?','?','/','?','?','T','?','?',':','?','?',':','?','?','-','?','?','?','?'};
  memory();
  void writeToSD();
  void init();
  bool addToBuffer(unsigned long milli);
  void EEPROMToFileName();
  void writeToEEPROM(int pos, uint8_t value);
};
