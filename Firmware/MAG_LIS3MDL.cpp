#include "MAG_LIS3MDL.h"
#include <Arduino.h>

MAG::MAG()
{
  
  
}   // End of function mag_init()

void MAG::init(){
  Wire.begin();

  // Store the configuration value for Control register 1 into buffer
  #ifdef Hz560
    MAG_WRITE(CTRL_REG1, 0x32);
    MAG_WRITE(CTRL_REG2, 0x00);
    MAG_WRITE(CTRL_REG3, 0x00);
    MAG_WRITE(CTRL_REG4, 0x04);
    MAG_WRITE(CTRL_REG5, 0x80);
    MAG_WRITE(INT_CFG, 0b01001001);
    HZ = 560;
  #endif
  #ifdef Hz300
    MAG_WRITE(CTRL_REG1, 0x52);
    MAG_WRITE(CTRL_REG2, 0x00);
    MAG_WRITE(CTRL_REG3, 0x00);
    MAG_WRITE(CTRL_REG4, 0x08);
    MAG_WRITE(CTRL_REG5, 0x80);
    MAG_WRITE(INT_CFG, 0b01001001);
    HZ = 300;
  #endif
  #ifdef Hz155
    MAG_WRITE(CTRL_REG1, 0x72);
    MAG_WRITE(CTRL_REG2, 0x00);
    MAG_WRITE(CTRL_REG3, 0x00);
    MAG_WRITE(CTRL_REG4, 0x0C);
    MAG_WRITE(CTRL_REG5, 0x80);
    MAG_WRITE(INT_CFG, 0b01001001);
    HZ = 155;
  #endif
  #ifdef Hz0.625
    MAG_WRITE(CTRL_REG1, 0b00000000);
    MAG_WRITE(CTRL_REG2, 0b00000000);
    MAG_WRITE(CTRL_REG3, 0b00000000);
    MAG_WRITE(CTRL_REG4, 0b00000000);
    MAG_WRITE(CTRL_REG5, 0b00000000);
    MAG_WRITE(INT_CFG,   0b01001001);
    HZ = .625;
  #endif
}

void MAG::HZto560(){ // need to only incude instructions that are necisary
  MAG_WRITE(CTRL_REG1, 0x32);
  MAG_WRITE(CTRL_REG2, 0x00);
  MAG_WRITE(CTRL_REG3, 0x00);
  MAG_WRITE(CTRL_REG4, 0x04);
  MAG_WRITE(CTRL_REG5, 0x80);
  MAG_WRITE(INT_CFG, 0b01001001);
  HZ = 560;
}

void MAG::HZto0625(){ // need to only incude instructions that are necisary
  Serial.println("Setting to 0.065 HZ");
  MAG_WRITE(CTRL_REG1, 0b00000000);
  MAG_WRITE(CTRL_REG2, 0b00000000);
  MAG_WRITE(CTRL_REG3, 0b00000000);
  MAG_WRITE(CTRL_REG4, 0b00000000);
  MAG_WRITE(CTRL_REG5, 0b00000000);
  MAG_WRITE(INT_CFG,   0b01001001);
  HZ = .625;
}

void MAG::setThreshold(){
  while(!digitalRead(4)){}
  int16_t temp = read_Y();
  int16_t highest = temp;
  int16_t lowest = temp;
  while(digitalRead(4)){}
  for (int a = 0; a < 1000; a++){
    while(!digitalRead(4)){}
    temp = read_Y();
    Serial.println(temp);
    if (temp > highest){
      highest = temp;
    }
    if (temp < lowest){
      lowest = temp;
    }
    while(digitalRead(4)){}
  }
  highthres = ((highest - lowest) * .7) + lowest;
  lowthres = ((highest - lowest) * .3) + lowest;
  //highthres = ((highest + lowest)/2);
  //lowthres = ((highest + lowest)/2);
  //Serial.print("High Threshold:");
  //Serial.println(highthres);
  //Serial.print("Low Threshold:");
  //Serial.println(lowthres);
  MAG_WRITE(INT_THS_L, (highthres & 0b11111111));
  MAG_WRITE(INT_THS_H, (highthres >> 8));
  //Serial.println("Finished Threshold Set");
}

void MAG::changeThreshold(){
  if (!digitalRead(2)){
    MAG_WRITE(INT_THS_H, (lowthres >> 8) & 0b01111111);
    MAG_WRITE(INT_THS_L, (lowthres & 0b11111111));
  }
  else {
    //digitalWrite(5, HIGH);
    MAG_WRITE(INT_THS_H, (highthres >> 8) & 0b01111111);
    MAG_WRITE(INT_THS_L, (highthres & 0b11111111));
    //digitalWrite(5, LOW);
  }
}


int16_t MAG::read_Y()
{
  uint8_t high = MAG_READ(OUT_Y_H);
  uint8_t low = MAG_READ(OUT_Y_L);
  return (high << 8 | low);
}

void MAG::MAG_WRITE(uint8_t reg, uint8_t value){
  Wire.beginTransmission(MAG_ADDR);
  Wire.write(reg);
  Wire.write(value);
  Wire.endTransmission();
  return;
}

uint8_t MAG::MAG_READ(uint8_t reg){
  Wire.beginTransmission(MAG_ADDR);
  Wire.write(reg);
  Wire.endTransmission();
  Wire.requestFrom(MAG_ADDR, 1);
  return Wire.read();
}
