#ifndef WIFIHANDLER_H
#define WIFIHANDLER_H

#include <WiFi.h>
#include "esp_eap_client.h"
//#include "ca_cert.h"  // CA certificate file
//#include "user_credentials.h" // User credentials file

void setupWiFi(const char* ssid);
void setupEduroam(const char* ssid);

#endif

