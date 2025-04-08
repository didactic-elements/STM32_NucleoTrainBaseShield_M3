#if 0
#include <Arduino.h>
#include <LiquidCrystal_PCF8574.h> 

LiquidCrystal_PCF8574 lcd(0x27);  // set the LCD address to 0x27 

void setup() {
  Wire.setSCL(PB8);  // set I2C Clock Line 
  Wire.setSDA(PB9);  // set I2C Data Line 
  lcd.begin(16, 2);  // initialize the lcd for a 16 chars and 2 line display
}

void loop() {
    lcd.setBacklight(255);
    lcd.home();
    lcd.clear();
    lcd.print("Hello......");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("*** first line.");
    lcd.setCursor(0, 1);
    lcd.print("*** second line.");
    delay(400);
    lcd.scrollDisplayLeft();
    lcd.scrollDisplayLeft();
    lcd.scrollDisplayLeft();
    lcd.setBacklight(0);
}  

#endif