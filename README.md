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
- `SPI` (for ESP32 <-> RFID reader communication)
- `WiFi` (for internet connectivity)
- `esp_eap_client`(for wpa2 enterprise authentication)
- `HTTPClient` (for sending data to Google Sheets)
- `LiquidCrystal_I2C` (for LCD display)


### 3️⃣ Configure User Credentials
Create a **`user_redentials.h`** file and add your network credentials:
```cpp
#ifndef USER_CREDENTIALS_H
#define USER_CREDENTALS_H

const char *eap_username = "YOUR_USERNAME"; //wpa2 enterprise username
const char *eap_identity = "YOUR_IDENTITY"; //wpa2 enterprise identity
const char *eap_password = "YOUR_PASSWORD"; //wpa2 enterprise password
const char* password = "YOUR_PASSWORD";     //wpa3 personal password
const char* googleScriptURL = "https://script.google.com/macros/s/URL/exec";

#endif
```

### 4️⃣ Deploy Google Apps Script
1. Open **Google Sheets** and create a new spreadsheet.
2. Rename the first sheet to **`Sheet1`**.
3. Click **Extensions -> Apps Script**.
4. Delete any default content and **paste the Google Apps Script**.
5. Click the **Save** icon.
6. Click **Deploy -> New Deployment**.
7. Under **Select Type**, choose **Web app**.
8. Set **Who has access** to **Anyone**.
9. Click **Deploy**, then **Authorize** the script when prompted.
10. Copy the **Web App URL** and replace it in `UserCredentials.h` for ESP32 to send data.

### 5️⃣ Upload Code to ESP32
- Open the project in **Arduino IDE**.
- Select **ESP32 Dev Module** in `Tools -> Board`.
- Upload `main.ino` to the ESP32.

## 📜 File Structure
```
/TrashTracker
│── main.ino
│── /handlers
│   │── ButtonHandler.h/.cpp
│   │── RFIDHandler.h/.cpp
│   │── WiFiHandler.h/.cpp
│   │── LCDHandler.h/.cpp
│   │── SheetsHandler.h/.cpp
│   │── RGBLedHandler.h/.cpp
│── /config
│   │── user_credentials.h (Ignored in .gitignore)
│   │── ca_cert.h
│── README.md
│── .gitignore
```

## 📝 Google Apps Script (GoogleScript.gs)
This script handles requests from the ESP32 to log RFID data into Google Sheets.
```javascript
function doGet(e) {
  var sheet = SpreadsheetApp.getActiveSpreadsheet().getSheetByName("Sheet1");  
  var uid = e.parameter.uid;
  var data = sheet.getDataRange().getValues();

  for (var i = 1; i < data.length; i++) {
    if (data[i][0] == uid) {
      if (data[i][1] !== "") {
        return ContentService.createTextOutput(data[i][1]);  // Return the associated name
      } else {
        return ContentService.createTextOutput("Unknown/Unassigned"); // UID exists but no name assigned
      }
    }
  }

  // If UID does not exist, add it to the sheet and return a message
  sheet.appendRow([uid, ""]);
  return ContentService.createTextOutput("New Tag - Added");
}
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
