#include "WiFiHandler.h"
#include "user_credentials.h"

int counter = 0;

void setupWiFi(const char* ssid) {
    WiFi.disconnect(true); //disconnect form wifi to set new wifi connection
    WiFi.begin(ssid, password);
    Serial.print("Connecting to network: ");
    Serial.println(ssid);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nWiFi Connected!");
}

void setupEduroam(const char* ssid) {

  Serial.print("Connecting to network: ");
  Serial.println(ssid);

  WiFi.disconnect(true); //disconnect form wifi to set new wifi connection
  delay(1000);
  WiFi.mode(WIFI_STA);  //init wifi mode


  // Set the username and password for WPA2-Enterprise
  esp_eap_client_set_identity((uint8_t *)eap_identity, strlen(eap_identity));  //provide identity
  esp_eap_client_set_username((uint8_t *)eap_username, strlen(eap_username));  //provide username
  esp_eap_client_set_password((uint8_t *)eap_password, strlen(eap_password));  //provide password
  esp_wifi_sta_enterprise_enable(); // Enable WPA2-Enterprise mode

  // Set the CA Certificate
  //esp_eap_client_set_ca_cert((uint8_t *)ca_cert, strlen(ca_cert));

  // Start WiFi connection
  WiFi.begin(ssid);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
    counter++;
    if (counter >= 30) {  //after 30 seconds timeout - reset board
      ESP.restart();
    }
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address set: ");
  Serial.println(WiFi.localIP());  //print LAN IP
}