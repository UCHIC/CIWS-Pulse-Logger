
#include "memory.h"

memory::memory(){
  pos = 0;
}

void memory::writeToSD(){
  //power_spi_enable(); // SPI
  //SD.begin();
  dataFile = SD.open((const char *)fileName, FILE_WRITE);
  for(int a = 0; a < pos; a++){
    Serial.println(Buffer[a]);
    dataFile.println(Buffer[a]);
  }
  dataFile.close();
  //power_spi_disable(); // SPI
  pos = 0;
}

void memory::init(){
  SD.begin();
}

bool memory::addToBuffer(unsigned long milli){
  Buffer[pos] = milli;
  pos++;
  return pos == bufferSize;
}

void memory::EEPROMToFileName(){
  fileName[25] = (char)EEPROM.read(0);
  fileName[26] = (char)EEPROM.read(1);
  fileName[27] = (char)EEPROM.read(2);
  fileName[28] = (char)EEPROM.read(3);

  fileName[0] = (char)EEPROM.read(4);
  fileName[1] = (char)EEPROM.read(5);
  fileName[2] = (char)EEPROM.read(6);
  fileName[3] = (char)EEPROM.read(7);
}

void memory::writeToEEPROM(int pos, uint8_t value){
  EEPROM.write(pos, value);
}
