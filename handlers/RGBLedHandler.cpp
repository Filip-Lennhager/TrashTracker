#include "handlers/RGBLedHandler.h"


void setupRGBLed() {
    // Configure PWM channels
    ledcAttachChannel(RED_PIN, 5000, 8, 0);   // Red on Channel 0
    ledcAttachChannel(GREEN_PIN, 5000, 8, 1); // Green on Channel 1
    ledcAttachChannel(BLUE_PIN, 5000, 8, 2);  // Blue on Channel 2
}

void setRGB(int red, int green, int blue) {
    ledcWriteChannel(0, red);   // Red channel (no inversion)
    ledcWriteChannel(1, green); // Green channel (no inversion)
    ledcWriteChannel(2, blue);  // Blue channel (no inversion)
}

void fadeRGB(int red_start, int red_end, int green_start, int green_end, int blue_start, int blue_end, int duration) {
    ledcFade(RED_PIN, red_start, red_end, duration);
    ledcFade(GREEN_PIN, green_start, green_end, duration);
    ledcFade(BLUE_PIN, blue_start, blue_end, duration);
}
