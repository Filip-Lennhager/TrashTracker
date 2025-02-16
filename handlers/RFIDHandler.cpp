#include "handlers/RFIDHandler.h"

#define SS_PIN 5
#define RST_PIN 4

MFRC522 rfid(SS_PIN, RST_PIN);

void setupRFID() {
    SPI.begin();
    rfid.PCD_Init();
}

String checkRFID() {
    if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) return "";

    String uid = "";
    for (byte i = 0; i < rfid.uid.size; i++) {
        uid += String(rfid.uid.uidByte[i], HEX);
    }

    Serial.print("RFID Tag Detected: ");
    Serial.println(uid);

    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
    
    return uid;
}
