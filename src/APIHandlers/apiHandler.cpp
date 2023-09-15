// =============================================================================
// Template-Project | Main
// =============================================================================

#include "apiHandler.h"
#include "configurations.h"
#include <ArduinoJson.h>

// returs the current unix time. uses api_datetime from configurations.h
// parses the response from the API and returns the unix time
uint32_t APIHandler::getUnixTime()
{
    WiFiClient client;
    HTTPClient http;

    http.begin(client, api_datetime);
    int httpCode = http.GET();

    if (httpCode > 0)
    {
        String payload = http.getString();
        http.end();  // Close the connection as soon as you get the payload

        DynamicJsonDocument doc(1024);  // Create a DynamicJsonDocument with a suitable capacity
        DeserializationError error = deserializeJson(doc, payload);  // Parse the JSON payload

        if (error)  // Check for parsing errors
        {
            Serial.println("Failed to parse JSON");
            return 0;
        }

        uint32_t unixTime = doc["unixtime"];  // Extract the Unix time
        return unixTime;
    }
    else
    {
        Serial.println("Error on HTTP request");
        http.end();
        return 0;
    }
}

uint32_t APIHandler::getSunsetTime()
{
    uint32_t sunsetTime = 0;
    if (WiFi.status() == WL_CONNECTED)
    {
        WiFiClient client;
        HTTPClient http;
        http.begin(client, String(api_suntime) + String(api_key));
        int httpCode = http.GET();

        if (httpCode > 0)
        {
            String payload = http.getString();
            http.end();  // Close the connection

            DynamicJsonDocument doc(2048);  // Create a DynamicJsonDocument
            DeserializationError error = deserializeJson(doc, payload);

            if (error)
            {
                Serial.println("Failed to parse JSON");
                return 0;
            }

            sunsetTime = doc["sys"]["sunset"];  // Extract sunset time
        }
    }
    return sunsetTime;
}


uint32_t APIHandler::getSunriseTime()
{
    uint32_t sunriseTime = 0;
    if (WiFi.status() == WL_CONNECTED)
    {
        WiFiClient client;
        HTTPClient http;
        http.begin(client, String(api_suntime) + String(api_key));
        int httpCode = http.GET();

        if (httpCode > 0)
        {
            String payload = http.getString();
            http.end();  // Close the connection

            DynamicJsonDocument doc(2048);  // Create a DynamicJsonDocument
            DeserializationError error = deserializeJson(doc, payload);

            if (error)
            {
                Serial.println("Failed to parse JSON");
                return 0;
            }

            sunriseTime = doc["sys"]["sunrise"];  // Extract sunrise time
        }
    }
    return sunriseTime;
}
