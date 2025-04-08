#if 0
#include <Arduino.h>
#include <Wire.h>
#include <U8g2lib.h>
#include "I2CScanner.h"
I2CScanner scanner;
// Funktionsdeklaration vor der Verwendung
void drawDisplay(int count);
void scanI2C();

// Display-Konstruktor für SH1106 128x64, I2C-Kommunikation
// Das "F" im Konstruktor bedeutet "Full Buffer Mode" für flüssigere Darstellung
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void setup() {
  Serial.begin(115200);
  while (!Serial) {
    ; // Warten bis die Serielle Schnittstelle bereit ist
  }
  
  // I2C-Pins konfigurieren
  Wire.setSCL(PB8);
  Wire.setSDA(PB9);
  Wire.begin();
  
  // I2C-Scanner ausführen, um die Adresse zu finden
  scanI2C();
  
  // Display initialisieren
  u8g2.begin();
  Serial.println("SH1106 OLED Display initialisiert");
  
  // Display-Einstellungen
  u8g2.setFontDirection(0);
  u8g2.setFontPosTop();
  u8g2.setDrawColor(1);
  u8g2.setFontMode(1);
  
  // Standard-Font setzen
  u8g2.setFont(u8g2_font_6x10_tf);
}

void loop() {
  static unsigned long lastUpdate = 0;
  static int counter = 0;
  
  // Alle 1000ms aktualisieren
  if (millis() - lastUpdate >= 1000) {
    counter++;
    lastUpdate = millis();
    
    // Display mit neuen Daten zeichnen
    drawDisplay(counter);
  }
}

void drawDisplay(int count) {
  // Display-Puffer löschen
  u8g2.clearBuffer();
  
  // Überschrift
  u8g2.setFont(u8g2_font_7x13B_tf);
  u8g2.drawStr(0, 0, "STM32L152RE");
  u8g2.drawStr(0, 14, "SH1106 OLED Test");
  
  // Linie
  u8g2.drawHLine(0, 28, u8g2.getDisplayWidth());
  
  // Zähler
  u8g2.setFont(u8g2_font_9x18B_tf);
  char countBuf[20];
  sprintf(countBuf, "Zahl: %d", count);
  u8g2.drawStr(0, 32, countBuf);
  
  // Laufzeit
  u8g2.setFont(u8g2_font_6x10_tf);
  char timeBuf[20];
  sprintf(timeBuf, "Laufzeit: %lu s", millis() / 1000);
  u8g2.drawStr(0, 52, timeBuf);
  
  // Demo-Grafiken
  // Rechteck
  u8g2.drawFrame(90, 30, 30, 15);
  // Gefülltes Rechteck
  u8g2.drawBox(95, 35, 20, 5);
  // Kreis
  u8g2.drawCircle(110, 45, 8);
  
  // Display-Puffer senden
  u8g2.sendBuffer();
}

// I2C-Scanner zur Adressfindung
void scanI2C() {
  byte error, address;
  int deviceCount = 0;
  
  Serial.println("Scanne I2C-Bus...");
  for(address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    
    if (error == 0) {
      Serial.print("I2C-Gerät gefunden an Adresse 0x");
      if (address < 16) Serial.print("0");
      Serial.println(address, HEX);
      deviceCount++;
    }
  }
  
  if (deviceCount == 0) {
    Serial.println("Keine I2C-Geräte gefunden");
  } else {
    Serial.print(deviceCount);
    Serial.println(" I2C-Gerät(e) gefunden");
  }
}

#endif