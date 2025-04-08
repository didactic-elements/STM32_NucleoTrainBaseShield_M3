#if 0   // preprocessor switch 0 = don't compile, 1 = compile 
#include <Arduino.h>
//#include <LiquidCrystal_PCF8574.h> 
#define BOARD_LED D13 // grüne LED auf dem Board

void setup(){   // Einmalige Ausführung => Initialisierungen...
    pinMode(BOARD_LED, OUTPUT);  // Pin als Ausgang schalten
}

void loop(){
    digitalWrite(BOARD_LED, HIGH);// High ausgeben
    delay(200);                   // warte 200ms
    digitalWrite(BOARD_LED, LOW); // Low ausgeben
    delay(200);                   // warte 200ms
} 
#endif