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
  char fileName[19] = {'2','0','?','?','/','?','?','/','?','?','T','?','?',':','?','?',':','?','?'};
  char site[3] = {'?','?','?'};
  char id[4] = {'?','?','?','?'};  
  memory();
  void writeToSD();
  void initSD();
  void putHeader();
  bool addToBuffer(unsigned long milli);
  void EEPROMToFileName();
  void FileNameToEEPROM();
};
