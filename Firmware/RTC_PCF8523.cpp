#include "RTC_PCF8523.h"


void RTC::init(){
  RTC_WRITE(Control_1, 0b00000010);
  RTC_WRITE(Control_2, 0b00000000);
  RTC_WRITE(Control_3, 0b10100000);
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

  //Serial.println("Entered RTCToFileName");
  uint8_t seconds  = RTC_READ(Seconds);
  uint8_t minutes  = RTC_READ(Minutes);
  uint8_t hours    = RTC_READ(Hours);
  uint8_t days     = RTC_READ(Days);
  uint8_t months   = RTC_READ(Months);
  uint8_t years    = RTC_READ(Years);

//  Serial.print("Seconds:");
//  Serial.println(seconds, BIN);
//  Serial.print("Minutes:");
//  Serial.println(minutes, BIN);
//  Serial.print("Hours:");
//  Serial.println(hours, BIN);
//  Serial.print("Days:");
//  Serial.println(days, BIN);
//  Serial.print("Months:");
//  Serial.println(months, BIN);
//  Serial.print("Years:");
//  Serial.println(years, BIN);
  
  fileName[2] = ((years >> 4) & 0x0F) + 48;
  fileName[3] = (years & 0x0F) + 48;
  fileName[5] = ((months >> 4) & 0x01) + 48;
  fileName[6] = (months & 0x0F) + 48;
  fileName[8] = ((days >> 4) & 0x03) + 48;
  fileName[9] = (days & 0x0F) + 48;
  fileName[11] = ((hours >> 4) & 0x03) + 48;
  fileName[12] = (hours & 0x0F) + 48;
  fileName[14] = ((minutes >> 4) & 0x07) + 48;
  fileName[15] = (minutes & 0x0F) + 48;
  fileName[17] = ((seconds >> 4) & 0x07) + 48;
  fileName[18] = (seconds & 0x0F) + 48;

//  Serial.print("filename[7]:");
//  Serial.println((fileName[7]));
//  Serial.print("filename[8]:");
//  Serial.println((fileName[8]));
//  Serial.print("filename[7]:");
//  Serial.println((fileName[7]), DEC);
//  Serial.print("filename[8]:");
//  Serial.println((fileName[8]), DEC);
//  Serial.print("filename[7]-48:");
//  Serial.println((fileName[7] - 48), DEC);
//  Serial.print("filename[8]-48:");
//  Serial.println((fileName[8] - 48), DEC);
//  Serial.print("Year high:");
//  Serial.println((fileName[8] - 48) & 0x0F, BIN);
//  Serial.print("Year low:");
//  Serial.println((fileName[7] - 48) << 4, BIN);
//  Serial.print("Year:");
//  Serial.println(years, BIN);
//  Serial.println("Exited RTCToFileName");
}

void RTC::fileNameToRTC(char* fileName){
//  Serial.println("Entered fileNameToRTC");
  uint8_t years = ((fileName[3] - 48) & 0x0F) | ((fileName[2] - 48) << 4);
  uint8_t months = ((fileName[6] - 48) & 0x0F) | ((fileName[5] - 48) << 4);
  uint8_t days = ((fileName[9] - 48) & 0x0F) | ((fileName[8] - 48) << 4);
  uint8_t hours = ((fileName[12] - 48) & 0x0F) | ((fileName[11] - 48) << 4);
  uint8_t minutes = ((fileName[15] - 48) & 0x0F) | ((fileName[14] - 48) << 4);
  uint8_t seconds = ((fileName[18] - 48) & 0x0F) | ((fileName[17] - 48) << 4);

//  Serial.print("filename[7]:");
//  Serial.println((fileName[7]));
//  Serial.print("filename[8]:");
//  Serial.println((fileName[8]));
//  Serial.print("filename[7]:");
//  Serial.println((fileName[7]), DEC);
//  Serial.print("filename[8]:");
//  Serial.println((fileName[8]), DEC);
//  Serial.print("filename[7]-48:");
//  Serial.println((fileName[7] - 48), DEC);
//  Serial.print("filename[8]-48:");
//  Serial.println((fileName[8] - 48), DEC);
//  Serial.print("Year high:");
//  Serial.println((fileName[8] - 48) & 0x0F, BIN);
//  Serial.print("Year low:");
//  Serial.println((fileName[7] - 48) << 4, BIN);
//  Serial.print("Year:");
//  Serial.println(years, BIN);
  
//  Serial.print("Seconds:");
//  Serial.println(seconds, BIN);
//  Serial.print("Minutes:");
//  Serial.println(minutes, BIN);
//  Serial.print("Hours:");
//  Serial.println(hours, BIN);
//  Serial.print("Days:");
//  Serial.println(days, BIN);
//  Serial.print("Months:");
//  Serial.println(months, BIN);
//  Serial.print("Years:");
//  Serial.println(years, BIN);

  RTC_WRITE(Seconds, seconds);
  RTC_WRITE(Minutes, minutes);
  RTC_WRITE(Hours, hours);
  RTC_WRITE(Days, days);
  RTC_WRITE(Months, months);
  RTC_WRITE(Years, years);
//  Serial.println("Exited fileNameToRTC");
}
