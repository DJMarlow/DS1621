#include <DS1621.h>

//Default address with no pins grounded
#define DS1621_ADDRESS  0x4F

DS1621 tempSensor = DS1621(DS1621_ADDRESS);

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.print("Temperature (Deg. F): ");
  Serial.println(tempSensor.getTempF());
  delay(1000);
  Serial.print("Temperature (Deg. C): ");
  Serial.println(tempSensor.getTempC());
  delay(1000);
}
