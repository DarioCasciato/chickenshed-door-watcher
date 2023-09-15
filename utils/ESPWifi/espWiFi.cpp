// =============================================================================
// Chickenshed-Door-Watcher | Main
// =============================================================================

#ifdef ESP8266

#include "espWiFi.h"

namespace
{
    inline const char* ssid = "SSID-HERE";
    inline const char* password = "PASSWORD-HERE";
}


void Wifi::establish()
{
    WiFi.hostname("NodeMCU | Chickenshed-Door-Watcher");
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }

    Serial.println("Connected to WiFi!");
}

#endif