#include <Wire.h>
void setup() {
  // put your setup code here, to run once:
  Wire.begin(8); // The arduino joins the i2c bus with the adress of 8
  Wire.onReceive(receiveEvent); /* register a receive Event */
  Wire.onRequest(requestEvent); /* register a request Event */
  Serial.begin(9600); /* Here we start a serial for debugging processes */
}
void loop() {
  // put your main code here, to run repeatedly:
  delay(100);
}
// The function below executes whenever data is received from master
void receiveEvent(int howMany)
{
  while(0 < Wire.available())
  {
    char c = Wire.read();
    Serial.print(c);
  }
  Serial.println();
}
// The function below executes whenever data is requested from master.
void requestEvent()
{
  // The Arduino write this string to the nodeMCU
  Wire.write("Hello NodeMCU");
}
