
#include "memory.h"

memory::memory(){
  pos = 0;
}

void memory::writeToSD(){
  //power_spi_enable(); // SPI
  if (!dataFile){
    Serial.println("Failed to open");
  }
  for(int a = 0; a < pos; a++){
    dataFile.println(Buffer[a]);
  }
  dataFile.flush();
  //power_spi_disable(); // SPI
  pos = 0;
}

void memory::initSD(){
  if (dataFile){
    dataFile.close();
  }
  SD.begin();
  char f[13] = {site[0],site[1],site[2],'_',DateTime[5],DateTime[6],DateTime[8],DateTime[9],'.','c','s','v','\0'};
  dataFile = SD.open(f, FILE_WRITE);
  dataFile.print("Date: ");
  dataFile.println(DateTime);
  dataFile.print("Site: ");
  dataFile.println(site);
  dataFile.print("ID: ");
  dataFile.println(id[0]+id[1]+id[2]);
}

bool memory::addToBuffer(unsigned long milli){
  Serial.println(milli);
  Buffer[pos] = milli;
  pos++;
  return pos == bufferSize;
}

void memory::EEPROMToMemory(){
  site[0] = (char)EEPROM.read(0);
  site[1] = (char)EEPROM.read(1);
  site[2] = (char)EEPROM.read(2);

  id[0] = (char)EEPROM.read(3);
  id[1] = (char)EEPROM.read(4);
  id[2] = (char)EEPROM.read(5);
  id[3] = (char)EEPROM.read(6);
}

void memory::MemoryToEEPROM(){
  EEPROM.write(0, (int)site[0]);
  EEPROM.write(1, (int)site[1]);
  EEPROM.write(2, (int)site[2]);
  
  EEPROM.write(3, (int)id[0]);
  EEPROM.write(4, (int)id[1]);
  EEPROM.write(5, (int)id[2]);
  EEPROM.write(6, (int)id[3]);
}
