#ifndef LCDHANDLER_H
#define LCDHANDLER_H

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

void setupLCD(String text, uint8_t x = 0, uint8_t y = 0);
void updateLCD(uint8_t button);
void printLCD(String text, uint8_t x = 0, uint8_t y = 0, bool clearScreen = false);

#endif
