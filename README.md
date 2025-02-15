# Trash Tracker Project

## 📌 Overview
Trash Tracker is an **ESP32-based system** that tracks office chores such as **emptying trash, brewing coffee, and handling the washing machine**. The system uses an **RFID scanner, an LCD display, an RGB LED, and button inputs** to log and display user interactions, while also sending the data to Google Sheets for tracking purposes.

## 🛠️ Features
- **RFID Tracking**: Users scan an RFID tag to log their activity.
- **Google Sheets Integration**: Data is sent to a Google Sheets document for record-keeping.
- **LCD Display**: Displays user information and task progress.
- **RGB LED Indicator**: Provides visual feedback for system status.
- **Button Inputs**: Allow users to manually select tasks for tracking.

## 🔧 Hardware Components
- **ESP32 Dev Module**
- **RFID RC522 Module**
- **LCD 16x2 Display (I2C)**
- **RGB LED (Common Anode)**
- **Four Input Buttons**

## 🚀 Installation & Setup
### 1️⃣ Clone the Repository
```sh
git clone https://github.com/Filip-Lennhager/TrashTracker.git
cd TrashTracker
```

### 2️⃣ Install Required Libraries
Ensure you have the following Arduino libraries installed:
- `MFRC522` (for RFID communication)
- `WiFi` (for internet connectivity)
- `HTTPClient` (for sending data to Google Sheets)
- `LiquidCrystal_I2C` (for LCD display)

### 3️⃣ Configure WiFi Credentials
Create a **`WiFiCredentials.h`** file and add your network credentials:
```cpp
#ifndef USER_CREDENTIALS_H
#define USER_CREDENTALS_H

const char *eap_username = "YOUR_USERNAME"; //wpa2 enterprise username
const char *eap_identity = "YOUR_IDENTITY"; //wpa2 enterprise identity
const char *eap_password = "YOUR_PASSWORD"; //wpa2 enterprise password
const char* password = "YOUR_PASSWORD";     //wpa3 personal password

#endif
```

### 4️⃣ Upload Code to ESP32
- Open the project in **Arduino IDE**.
- Select **ESP32 Dev Module** in `Tools -> Board`.
- Upload `main.ino` to the ESP32.

## 📜 File Structure
```
/TrashTracker
│── main.ino
│── ButtonHandler.h/.cpp
│── RFIDHandler.h/.cpp
│── WiFiHandler.h/.cpp
│── LCDHandler.h/.cpp
│── SheetsHandler.h/.cpp
│── RGBLedHandler.h/.cpp
│── user_credentials.h (Ignored in .gitignore)
│── README.md
│── .gitignore
```

## 🎯 Usage
1. **Scan RFID** to log activity.
2. **Check LCD Display** for status updates.
3. **Use buttons** to manually select tasks.
4. **Monitor Google Sheets** for recorded data.

## 🚀 Future Improvements
- **CAD model of casing** 
- **Slackbot Script** send notifications in slack
- **Power Supply** battery or cable? 

---
🚀 **Happy Tracking!** 🚀
