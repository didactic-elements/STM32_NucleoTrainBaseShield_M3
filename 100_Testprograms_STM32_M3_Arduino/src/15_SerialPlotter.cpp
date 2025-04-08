#if 0   // preprocessor switch 0 = don't compile, 1 = compile 
#include <Arduino.h>
//In VS Code, press CTRL + SHIFT + P
//A serial port can only be accessed by one process at a time. You cannot monitor a port and upload a 
//program to the Arduino simultaneously. Ensure no other process is using the port if the plotter can't 
//connect. Similarly, if you're having trouble uploading to the Arduino, make sure the serial plotter 
//isn't monitoring the port. If you create multiple plots with specific variable selections, 
//they need to be recreated when starting a new session.
//
void setup() {
  Serial.begin(112500);
}

float angle = 0;
void loop() {
  Serial.print(">");

  Serial.print("var1:");
  Serial.print(cos(angle));
  Serial.print(",");

  Serial.print("var2:");
  Serial.print(cos(angle + PI / 2) * 0.1);
  Serial.print(",");

  Serial.print("var3:");
  Serial.print(cos(angle + PI / 4) * 1.2 + 2);
  Serial.println(); // Writes \r\n

  Serial.println("This is totally ignored");
  delay(100);

  angle += PI / 10;
}
#endif