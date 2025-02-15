
#ifndef BUTTONHANDLER_H
#define BUTTONHANDLER_H

#include <Arduino.h>

#define BUTTON1 13
#define BUTTON2 14
#define BUTTON3 27
#define BUTTON4 33

void setupButtons();
uint8_t checkButtons();

#endif
