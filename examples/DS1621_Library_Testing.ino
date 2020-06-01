#include <DS1621.h>

//Default address with no pins grounded
#define DS1621_ADDRESS  0x48

DS1621 tempSensor = DS1621(DS1621_ADDRESS);

void setup() {
  Serial.begin(115200);
  tempSensor.begin();
}

void loop() {
  Serial.print("Temperature (Deg. F): ");
  Serial.println(tempSensor.getTempF()/10);
  Serial.print("Temperature (Deg. C): ");
  Serial.println(tempSensor.getTempC()/10);
  delay(1000);
}
