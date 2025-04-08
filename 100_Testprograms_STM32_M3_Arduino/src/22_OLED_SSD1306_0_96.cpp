#if 0
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "I2CScanner.h"
I2CScanner scanner;


// I²C-Bus 2 for SSD1306, LCD
TwoWire I2C_2(PB9, PB8);  // SDA, SCL - Standard !
// ------------------- oled SSD1306 --------------------- 
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define SCREEN_ADDRESS 0x3C
#define OLED_RESET     -1
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &I2C_2, OLED_RESET);

void initSSD1306_I2C_Display() {
    // I2C für OLED
    I2C_2.begin();
    Serial.print("probing for SSD1306 I2C on address (");
    char hexString[10];
    sprintf(hexString, "0x%X", SCREEN_ADDRESS);
    Serial.print(hexString);
    Serial.print(")...");
    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    if (!oled.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
    {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;)
            ; // Don't proceed, loop forever
    }
    Serial.println();
    
    oled.display();
    delay(1000); // Pause for 1 seconds
    oled.clearDisplay();
    oled.setTextSize(1);
    oled.setTextColor(WHITE);
    oled.setCursor(0, 1);
    I2C_2.end();
}


void test_SSD1306() {

    // ---  I2C for OLED, LDC --------
    I2C_2.begin();
    // Display static text
    oled.setCursor(0, 0);
    oled.setTextSize(1);
    oled.println("-> switch on");
    oled.println("   PullUp-PB6,PB7");
    oled.println("-> switch on");
    oled.println("   LM75B");
    oled.println("temperature from");
    oled.println("onboard sensor LM75:");
    oled.setTextSize(2);
    float cTemperature = 22.45;
    oled.print(cTemperature,1);
    oled.print(" \xf8"); // °
    oled.println("C");
    oled.setTextSize(1);
    oled.println("");
    oled.display();
    delay(750);
    oled.clearDisplay();
    I2C_2.end();
}

// ***************** Arduino Framework Setup ****************
void setup() {
       // ------------ I2C scan ---------- 
    Serial.begin(9600);
	while (!Serial) {};
	scanner.Init();
    scanner.Scan();

    // ------ OLED display and onboard LM75B-------------
    initSSD1306_I2C_Display();
    test_SSD1306();
}

void loop()
{

}


#endif