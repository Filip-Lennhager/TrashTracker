#include "LCDHandler.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setupLCD(String text, uint8_t x, uint8_t y) {
    lcd.init();
    lcd.backlight();
    lcd.setCursor(x, y);
    lcd.print(text);
}

void updateLCD(uint8_t button) {
    lcd.setCursor(0, 1);
    if(button!=0){
      lcd.print(button);
    }
}

void printLCD(String text, uint8_t x, uint8_t y, bool clearScreen) {
    if (clearScreen) {
        lcd.clear();
    }
    lcd.setCursor(x, y);
    if (!text.isEmpty()) {
        lcd.print(text);
    }
}


