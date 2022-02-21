#include <avr/power.h>
#include <Arduino.h>
#include <SD.h>
#include <SPI.h>
#include <EEPROM.h>

#define bufferSize 1

class memory{
  private:
  unsigned long Buffer[bufferSize];
  int pos;
  File dataFile;
  public:
  char DateTime[20] = {'2','0','?','?','/','?','?','/','?','?','T','?','?',':','?','?',':','?','?','\0'};
  char site[4] = {'?','?','?','\0'};
  char id[4] = {'?','?','?','?'};  
  memory();
  void writeToSD();
  void initSD();
  void putHeader();
  bool addToBuffer(unsigned long milli);
  void EEPROMToMemory();
  void MemoryToEEPROM();
};
