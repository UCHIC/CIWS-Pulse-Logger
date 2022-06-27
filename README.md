# CIWS-Pulse-Logger

This repository contains hardware and software designs for the Pulse-Datalogger, a device that can be used to collect high resolution water use data on magnetically-driven residential water meters. The datalogger is designed to read magnetic field information from a magnetometer sensor attached to a magnetically-driven, positive-displacement water meter. 

Firmware: The Firmware folder contains code written for the datalogger.

Hardware: The Hardware folder contains hardware design information for off-the-shelf components as well as a 
manufacturable PCB.

## Operation
The device is made up of an ATMEGA328P microcontroller chip and three peripherial systems. These are an RTC(Real Time Clock), Magnetometer, and SD Card. The magnetometer reads magnetic data from the water meter and inturrupts the microcontroller when a threshold is passed. The RTC minimizes time drift by inturrupting the micronctoller at the start of every day. On this inturrupt it resets its time-keeping values to sync it with the RTC time. The SD Card stores water pulse data.

## Setup
Strap the device to the meter and connect the device to a computer via USB-Serial connector. Send a character to start communication. Answer the questions asked by the device with a `y` or `n` and fill in any requested information. Immediatly after answering those two questions the device will start to measure magnetic data to set the threshold for the magnetometer. Water must be turned on in the house to properly configure the thresholds. If you miss the calibration time restart the device and try again. After calibration the device automatically begins recording water data to the SD Card. To collect water data hit the restatrt button on the device and collect the SD Card. Water data is organised into different files for each day of data recorded. Each file contains a file header with the site ID, device ID, and date and time of data collection started. After the header each pulse is stored on a new line and is represented as an integer value. The interger value represents the milliseconds since the last pulse. 

## Cyberinfrastructure for Intelligent Water Supply (CIWS) 

CIWS is a project funded by the U.S. National Science Foundation to develop cyberinfrastructure for smart water metering and high resolution water-use data collection. We are developing systems for high resolution residential water consumption data collection, processing and analysis.

## Sponsors and Credits
[![NSF-1552444](https://img.shields.io/badge/NSF-1552444-blue.svg)](https://nsf.gov/awardsearch/showAward?AWD_ID=1552444)

This work was supported by National Science Foundation Grant [CBET 1552444](https://www.nsf.gov/awardsearch/showAward?AWD_ID=1552444). Any opinions, findings, and conclusions or recommendations expressed in this material are those of the author(s) and do not necessarily reflect the views of the National Science Foundation.
