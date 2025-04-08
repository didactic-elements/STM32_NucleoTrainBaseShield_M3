#if 0   // preprocessor switch 0 = don't compile, 1 = compile 
#include <Arduino.h>
#define BOARD_LED PA5 // grüne LED auf dem Board

void setup(){   // Einmalige Ausführung => Initialisierungen...
    pinMode(BOARD_LED, OUTPUT);  // Pin als Ausgang schalten
}

void loop(){
    digitalWrite(PA5, 1);// High ausgeben
    delay(200);                   // warte 200ms
    digitalWrite(PA5, 0); // Low ausgeben
    delay(200);                   // warte 200ms
} 
#endif