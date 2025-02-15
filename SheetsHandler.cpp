#include "SheetsHandler.h"

const char* googleScriptURL = "https://script.google.com/macros/s/AKfycbwzxqe9i9t5cZl9r9IuzIpv2xSGZqXzugG0pafwTum0T16QrS08m7EHsHoOe3qLxMar/exec";

String sendUIDtoGoogleSheets(String uid) {
    if (WiFi.status() != WL_CONNECTED) {
        Serial.println("WiFi Disconnected");
        return "";
    }

    HTTPClient http;
    String url = String(googleScriptURL) + "?uid=" + uid;

    Serial.println("Sending UID to Google Sheets...");
    http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS);
    http.begin(url);
    int httpResponseCode = http.GET();

    if (httpResponseCode > 0) {
        Serial.print("Google Sheets Response: ");
        String response = http.getString();
        Serial.println(response);
        http.end();
        return response;
    } else {
        Serial.print("HTTP Error: ");
        Serial.println(httpResponseCode);
    }

    http.end();
    return "";
}
