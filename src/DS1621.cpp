#include "DS1621.h"

#define StartConvert 0xEE
#define StopConvert 0x22
#define GetTemperature 0xAA

DS1621::DS1621(int address) {
  _address = address;
}

int DS1621::getTempC() {
  Wire.begin();
  Wire.beginTransmission(_address);
  Wire.write(StartConvert);
  Wire.endTransmission();
  Wire.beginTransmission(_address);
  Wire.write(StopConvert);
  Wire.endTransmission();
  Wire.beginTransmission(_address);
  Wire.write(GetTemperature);
  Wire.endTransmission(false);
  Wire.requestFrom(_address, 2);
  int t = Wire.read();
  
  return t;  
}

int DS1621::getTempF() {
  Wire.begin();
  Wire.beginTransmission(_address);
  Wire.write(StartConvert);
  Wire.endTransmission();
  Wire.beginTransmission(_address);
  Wire.write(StopConvert);
  Wire.endTransmission();
  Wire.beginTransmission(_address);
  Wire.write(GetTemperature);
  Wire.endTransmission(false);
  Wire.requestFrom(_address, 2);
  int t = Wire.read();
  int tF = (t * 9/5) + 32;
  
  return tF;  
}
