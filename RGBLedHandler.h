#ifndef RGBLEDHANDLER_H
#define RGBLEDHANDLER_H

#include <Arduino.h>

// Define RGB LED pins
#define RED_PIN 0
#define GREEN_PIN 2
#define BLUE_PIN 15

void setupRGBLed();
void setRGB(int red, int green, int blue);
void fadeRGB(int red_start, int red_end, int green_start, int green_end, int blue_start, int blue_end, int duration);

#endif
