// TrashTracker.ino
//#include <Arduino.h>
#include "handlers/ButtonHandler.h" 
#include "handlers/RFIDHandler.h"
#include "handlers/WiFiHandler.h" 
#include "handlers/LCDHandler.h" 
#include "handlers/SheetsHandler.h"
#include "handlers/RGBLedHandler.h"

void setup() {
    Serial.begin(115200);
    setupRGBLed();
    setRGB(255, 0, 0);
    setupLCD("System Setup...");
    setupButtons();
    setupWiFi("RatNation");
    //setupEduroam("eduroam");
    setupRFID();
    fadeRGB(255, 0, 0, 50, 0, 0, 500);
    printLCD("System Ready",0 ,0 ,true);

}

void loop() {
    setRGB(0, 50, 0); 
    int button = checkButtons();
    updateLCD(button);
    
    //String scannedUID = checkRFID();
    
    String scannedUID = checkRFID();
    if (!scannedUID.isEmpty()) {
        setRGB(0, 0, 50); 
        printLCD("Hello!", 5, 0, true);
        String name = sendUIDtoGoogleSheets(scannedUID);
        printLCD(name);
        printLCD("   1  2  3  4   ", 0, 1);
    }




    
    
}
