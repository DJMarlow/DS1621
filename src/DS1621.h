/*
    Arduino library for DS1621

    Reference Datasheet: https://datasheets.maximintegrated.com/en/ds/DS1621.pdf

    Author: DJMarlow - https://github.com/DJMarlow
    Date: 2020-5-28
*/

#ifndef DS1621_H
#define DS1621_H

#include <Arduino.h>
#include <Wire.h>

class DS1621 {
public:

  DS1621(int address);

  void begin();
  int getTempC();
  int getTempF();

private:
  //I2C address
  int _address;
};

#endif
