#include <Wire.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin(D1, D2);
}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(8);
  Wire.write("Hello Arduino"); /* sends hello string */
  Wire.endTransmission();

  Wire.requestFrom(8, 13);
  while(Wire.available())
  {
    char c = Wire.read();
    Serial.print(c);
  }
  Serial.println();
  delay(1000);
}
