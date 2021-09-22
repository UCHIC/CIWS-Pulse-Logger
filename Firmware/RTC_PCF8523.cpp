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
  
  fileName[7] = (years >> 4) + 48;
  fileName[8] = (years & 0x0F) + 48;
  fileName[10] = (months >> 4) + 48;
  fileName[11] = (months & 0x0F) + 48;
  fileName[13] = (days >> 4) + 48;
  fileName[14] = (days & 0x0F) + 48;
  fileName[16] = (hours >> 4) + 48;
  fileName[17] = (hours & 0x0F) + 48;
  fileName[19] = (minutes >> 4) + 48;
  fileName[20] = (minutes & 0x0F) + 48;
  fileName[22] = (seconds >> 4) + 48;
  fileName[23] = (seconds & 0x0F) + 48;
}

void RTC::fileNameToRTC(char* fileName){
  uint8_t years = ((fileName[8] - 48) & 0x0F) | ((fileName[7] - 48) << 4);
  uint8_t months = ((fileName[11] - 48) & 0x0F) | ((fileName[10] - 48) << 4);
  uint8_t days = ((fileName[14] - 48) & 0x0F) | ((fileName[13] - 48) << 4);
  uint8_t hours = ((fileName[17] - 48) & 0x0F) | ((fileName[16] - 48) << 4);
  uint8_t minutes = ((fileName[20] - 48) & 0x0F) | ((fileName[19] - 48) << 4);
  uint8_t seconds = ((fileName[23] - 48) & 0x0F) | ((fileName[22] - 48) << 4);

  RTC_WRITE(Seconds, seconds);
  RTC_WRITE(Minutes, minutes);
  RTC_WRITE(Hours, hours);
  RTC_WRITE(Days, days);
  RTC_WRITE(Months, months);
  RTC_WRITE(Years, years);
}
