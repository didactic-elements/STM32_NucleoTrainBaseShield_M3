#if 0   // preprocessor switch 0 = don't compile, 1 = compile 
#include <Arduino.h>
uint32_t zeit = 0; 
void setup(){   // Einmalige Ausführung => Initialisierungen...
    Serial.begin(112500);  // Ändern
}

void loop(){
  Serial.print("Zeit:"); 
  zeit = millis();   
  Serial.print(zeit/1000.0);
  Serial.print("\r\n");  
} 
#endif