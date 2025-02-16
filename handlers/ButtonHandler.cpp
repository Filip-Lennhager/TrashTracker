#include "handlers/ButtonHandler.h"

volatile unsigned long lastPress1 = 0;
volatile unsigned long lastPress2 = 0;
volatile unsigned long lastPress3 = 0;
volatile unsigned long lastPress4 = 0;
const unsigned long debounceDelay = 1000; // 200ms debounce

volatile bool button1Pressed = false;
volatile bool button2Pressed = false;
volatile bool button3Pressed = false;
volatile bool button4Pressed = false;

void IRAM_ATTR handleButton1() {
  if (millis() - lastPress1 > debounceDelay) {
    lastPress1 = millis();
    button1Pressed = true;
  }
}

void IRAM_ATTR handleButton2() {
  if (millis() - lastPress2 > debounceDelay) {
    lastPress2 = millis();
    button2Pressed = true;
  }
}

void IRAM_ATTR handleButton3() {
  if (millis() - lastPress3 > debounceDelay) {
    lastPress3 = millis();
    button3Pressed = true;
  }
}

void IRAM_ATTR handleButton4() {
  if (millis() - lastPress4 > debounceDelay) {
    lastPress4 = millis();
    button4Pressed = true;
  }
}

void setupButtons() {
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
  pinMode(BUTTON3, INPUT_PULLUP);
  pinMode(BUTTON4, INPUT_PULLUP);

  attachInterrupt(BUTTON1, handleButton1, FALLING);
  attachInterrupt(BUTTON2, handleButton2, FALLING);
  attachInterrupt(BUTTON3, handleButton3, FALLING);
  attachInterrupt(BUTTON4, handleButton4, FALLING);
}

uint8_t checkButtons() {
  if (button1Pressed) {
    Serial.println("Button 1 Pressed!");
    button1Pressed = false;
    return 1;
  }
  if (button2Pressed) {
    Serial.println("Button 2 Pressed!");
    button2Pressed = false;
    return 2;
  }
  if (button3Pressed) {
    Serial.println("Button 3 Pressed!");
    button3Pressed = false;
    return 3;
  }
  if (button4Pressed) {
    Serial.println("Button 4 Pressed!");
    button4Pressed = false;
    return 4;
  }
  return 0;
}
