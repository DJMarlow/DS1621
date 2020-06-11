#include <DS1621.h>

//Pass pin grounded argument (A0, A1, A2)
//If grounded, assign 1 to argument, else 0
DS1621 tempSensor = DS1621(0,0,0);

void setup() {
  Serial.begin(115200);
  tempSensor.begin();
}

void loop() {
  tempSensor.startConvert();
  while (tempSensor.finishedConvert());
  Serial.print("Temperature (Deg. F): ");
  Serial.println(tempSensor.getTempF());
  delay(1000);
  Serial.print("Temperature (Deg. C): ");
  Serial.println(tempSensor.getTempC());
  delay(1000);
}
