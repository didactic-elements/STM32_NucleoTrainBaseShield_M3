#if 0   // preprocessor switch 0 = don't compile, 1 = compile 
#include <Arduino.h>
uint32_t counter = 0;

void setup(){   // Einmalige Ausführung => Initialisierungen...
    Serial.begin(112500); // Baudrate 
}

void loop(){
  Serial.print("Count:"); 
  counter++;   
  Serial.print(counter); 
  Serial.print("\r\n");  
} 
#endif