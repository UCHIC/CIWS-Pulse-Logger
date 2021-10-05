
#include "memory.h"

memory::memory(){
  pos = 0;
}

void memory::writeToSD(){
  //power_spi_enable(); // SPI
  SD.begin();
  //(const char *)fileName
  dataFile = SD.open("test4.txt", FILE_WRITE);
  if (!dataFile){
    Serial.println("Failed to open");
  }
  for(int a = 0; a < pos; a++){
    Serial.println(Buffer[a]);
    dataFile.println(Buffer[a]);
  }
  dataFile.close();
  //power_spi_disable(); // SPI
  pos = 0;
//  pinMode(10, INPUT);
//  pinMode(11, INPUT);
//  pinMode(12, INPUT);
//  pinMode(13, INPUT);
//  digitalWrite(10, LOW);
//  digitalWrite(11, LOW);
//  digitalWrite(12, LOW);
//  digitalWrite(13, LOW);
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

void memory::FileNameToEEPROM(){
  EEPROM.write(0, (int)fileName[25]);
  EEPROM.write(1, (int)fileName[26]);
  EEPROM.write(2, (int)fileName[27]);
  EEPROM.write(3, (int)fileName[28]);
  
  EEPROM.write(4, (int)fileName[0]);
  EEPROM.write(5, (int)fileName[1]);
  EEPROM.write(6, (int)fileName[2]);
  EEPROM.write(7, (int)fileName[3]);
}
