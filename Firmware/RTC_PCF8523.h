/*********************************************************************\
 * File:      RTC_PCF8523.h
 * Date:      04/17/2019
 * Authors:   Joshua Tracy and Daniel Henshaw
 * Hardware:  Pololu LIS3MDL 3-Axis magnetometer 
 *********************************************************************/

#ifndef RTCPCF8523_H
#define RTCPCF8523_H

#include <avr/power.h>
#include <Wire.h>
#include "Arduino.h"

/*RTC TWI/I2C Address: 0x68*/
#define DEV_ADDR  0x68

/*Hexadecimal Addresses of the RTC Registers*/
#define Control_1        0x00
#define Control_2        0x01
#define Control_3        0x02
#define Seconds          0x03
#define Minutes          0x04
#define Hours            0x05
#define Days             0x06
#define Weekdays         0x07
#define Months           0x08
#define Years            0x09
#define Minute_alarm     0x0A
#define Hour_alarm       0x0B
#define Day_alarm        0x0C
#define Weekday_alarm    0x0D
#define Offset           0x0E
#define Tmr_CLKOUT_ctrl  0x0F
#define Tmr_A_freq_ctrl  0x10
#define Tmr_A_reg        0x11
#define Tmr_B_freq_ctrl  0x12
#define Tmr_B_reg        0x13

/*Date_t stores all date/time information*/
class RTC{
  public:
  void init();
  void stopAlarm();
  void RTC_WRITE(uint8_t reg, uint8_t value);
  uint8_t RTC_READ(uint8_t reg);
  void RTCToDateTime(char* fileName);
  void DateTimeToRTC(char* fileName);
};

#endif
