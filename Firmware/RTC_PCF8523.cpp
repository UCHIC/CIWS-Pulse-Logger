#include "RTC_PCF8523.h"


void RTC::init(){
  RTC_WRITE(Control_1, 0b00010010);
  RTC_WRITE(Control_2, 0b00000000);
  RTC_WRITE(Control_3, 0b11100000);
  RTC_WRITE(Tmr_CLKOUT_ctrl, 0b00111000);
  RTC_WRITE(Hour_alarm, 0b00000000);
}

void RTC::stopAlarm(){
  Wire.beginTransmission(DEV_ADDR);
  Wire.write(Control_2);
  Wire.write(0b0000000);
  Wire.endTransmission();
}

void RTC::RTC_WRITE(uint8_t reg, uint8_t value){
  Wire.beginTransmission(DEV_ADDR);
  Wire.write(reg);
  Wire.write(value);
  Wire.endTransmission();
  return;
}

uint8_t RTC::RTC_READ(uint8_t reg){
  Wire.beginTransmission(DEV_ADDR);
  Wire.write(reg);
  Wire.endTransmission();
  Wire.requestFrom(DEV_ADDR, 1);
  return Wire.read();
}

void RTC::RTCToFileName(char* fileName){
  uint8_t seconds  = RTC_READ(Seconds);
  uint8_t minutes  = RTC_READ(Minutes);
  uint8_t hours    = RTC_READ(Hours);
  uint8_t days     = RTC_READ(Days);
  uint8_t months   = RTC_READ(Months);
  uint8_t years    = RTC_READ(Years);
  
  fileName[7] = (char)(years >> 4);
  fileName[8] = (char)(years & 0x0F);
  fileName[10] = (char)(months >> 4);
  fileName[11] = (char)(months & 0x0F);
  fileName[13] = (char)(days >> 4);
  fileName[14] = (char)(days & 0x0F);
  fileName[16] = (char)(hours >> 4);
  fileName[17] = (char)(hours & 0x0F);
  fileName[19] = (char)(minutes >> 4);
  fileName[20] = (char)(minutes & 0x0F);
  fileName[22] = (char)(seconds >> 4);
  fileName[23] = (char)(seconds & 0x0F);
}
