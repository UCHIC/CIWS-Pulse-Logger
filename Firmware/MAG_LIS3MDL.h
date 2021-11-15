#ifndef MAGNETOMETER_H
#define MAGNETOMETER_H

#include <avr/power.h>
#include <Wire.h>

/*********************************************************************\
 * 
 * Library for interfacing with the Pololu LIS3MDL magnetometer.
 * 
 * Functions:       Short description:
 *    mag_init      Initialize magnetomter 
 *    read_mag      Read Data from magnetometer
 *    mag_transfer  Read/write data between magnetometer and ATmega328P
 *    
\*********************************************************************/

/*========= MACROS =========*/

//#define Hz560
//#define Hz300
#define Hz155
//#define Hz0.625

/* Device Address */
#define MAG_ADDR 0x1E
//#define DEV_ADDR 0xF


/* Output Data Indices */
#define MAG_X 0
#define MAG_Y 1
#define MAG_Z 2

/* Registers */
#define WHO_AM_I 0x0F

#define CTRL_REG1 0x20
#define CTRL_REG2 0x21
#define CTRL_REG3 0x22
#define CTRL_REG4 0x23
#define CTRL_REG5 0x24

#define STATUS_REG 0x27

#define OUT_X_L 0x28
#define OUT_X_H 0x29
#define OUT_Y_L 0x2A
#define OUT_Y_H 0x2B
#define OUT_Z_L 0x2C
#define OUT_Z_H 0x2D

#define TEMP_OUT_L 0x2E
#define TEMP_OUT_H 0x2F

#define INT_CFG 0x30
#define INT_SRC 0x31

#define INT_THS_L 0x32
#define INT_THS_H 0x33

class MAG{
  public:
  float HZ = 0;
  int16_t highthres;
  int16_t lowthres;
  MAG();              // replaces the original magnetometerInit() function
  void init();
  int read_Y();
  void MAG_WRITE(uint8_t reg, uint8_t value);
  uint8_t MAG_READ(uint8_t reg);
  void setThreshold();
  void changeThreshold();
  void HZto0625();
  void HZto560();
  unsigned long throttleHZ(unsigned long milli);
};

#endif
