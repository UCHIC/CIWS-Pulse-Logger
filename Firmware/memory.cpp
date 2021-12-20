
#include "memory.h"

memory::memory(){
  pos = 0;
}

void memory::writeToSD(){
  //digitalWrite(5, HIGH);
  //power_spi_enable(); // SPI
  //(const char *)fileName
  //digitalWrite(5, LOW);
  if (!dataFile){
    Serial.println("Failed to open");
  }
  for(int a = 0; a < pos; a++){
    Serial.println(Buffer[a]);
    Serial.print("Number of bytes written: ");
    Serial.println(dataFile.println(Buffer[a]), DEC);
  }
  dataFile.flush();
  //power_spi_disable(); // SPI
  pos = 0;
  //digitalWrite(5, LOW);
//  pinMode(10, INPUT);
//  pinMode(11, INPUT);
//  pinMode(12, INPUT);
//  pinMode(13, INPUT);
//  digitalWrite(10, LOW);
//  digitalWrite(11, LOW);
//  digitalWrite(12, LOW);
//  digitalWrite(13, LOW);
}

void memory::initSD(){
  if (dataFile){
    dataFile.close();
  }
  SD.begin();
  char f[13] = {site[0],site[1],site[2],'_',fileName[5],fileName[6],fileName[8],fileName[9],'.','t','x','t','\0'};
//  char test[9];
//  String str = "file.txt";
//  str.toCharArray(test, 9);
//  Serial.print("char array: ");
//  Serial.println(test);
//  if (test == f){
//    Serial.println("They are equal");
//  }
//  Serial.print("Null Char: ");
//  Serial.println(test[8]);
  dataFile = SD.open(f, FILE_WRITE); //should at some point open the file associated with the date and site
}

void memory::putHeader(){
  dataFile.println(fileName);
  dataFile.println(site);
  dataFile.println(id[0]+id[1]+id[2]);
}

bool memory::addToBuffer(unsigned long milli){
  Buffer[pos] = milli;
  pos++;
  return pos == bufferSize;
}

void memory::EEPROMToFileName(){
  site[0] = (char)EEPROM.read(0);
  site[1] = (char)EEPROM.read(1);
  site[2] = (char)EEPROM.read(2);

  id[0] = (char)EEPROM.read(3);
  id[1] = (char)EEPROM.read(4);
  id[2] = (char)EEPROM.read(5);
  id[3] = (char)EEPROM.read(6);
}

void memory::FileNameToEEPROM(){
  EEPROM.write(0, (int)site[0]);
  EEPROM.write(1, (int)site[1]);
  EEPROM.write(2, (int)site[2]);
  
  EEPROM.write(3, (int)id[0]);
  EEPROM.write(4, (int)id[1]);
  EEPROM.write(5, (int)id[2]);
  EEPROM.write(6, (int)id[3]);
}
