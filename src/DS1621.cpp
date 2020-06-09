#include "DS1621.h"

DS1621::DS1621(int address) {
  _address = address;
}

void DS1621::begin() {
  Wire.begin();
  Wire.beginTransmission(_address);
  Wire.write(0xAC);
  Wire.write(0x02);
  Wire.beginTransmission(_address);
  Wire.write(0xEE);
  Wire.endTransmission();
}

int16_t DS1621::getTempC() {
  Wire.beginTransmission(_address);
  Wire.write(0xAA);
  Wire.endTransmission(false);
  Wire.requestFrom(_address, 2);
  uint8_t t = Wire.read();
  
  return t;  
}

int16_t DS1621::getTempF() {
  Wire.beginTransmission(_address);
  Wire.write(0xAA);
  Wire.endTransmission(false);
  Wire.requestFrom(_address, 2);
  uint8_t t = Wire.read();
  int16_t tF = t * 9/5 + 320;
  
  return tF;  
}
