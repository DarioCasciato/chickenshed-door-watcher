// =============================================================================
// Chickenshed-Door-Watcher | Notification Handler
// =============================================================================

#include "notificationHandler.h"

namespace
{
    const char* ifttt_key = ""; // TODO: Add IFTTT key
    const char* notClosed = ""; // TODO: Add webhook URL for notClosed notification
    const char* notOpened = ""; // TODO: Add webhook URL for notOpened notification
}

void Notification::send(Event event)
{
    HTTPClient http;
    WiFiClient client;
    const char* request = ""; // TODO: implement concatenating with ifttt_key and event

    switch (event)
    {
    case Event::NotClosed:
        request = notClosed;
        break;

    case Event::NotOpened:
        request = notOpened;
        break;

    default:
        return;
    }

    http.begin(client, request);
    int32_t httpResponseCode = http.POST("");

    // Check the response code
    if (httpResponseCode == HTTP_CODE_OK)
    {
        Serial.print("Notification sent: ");
        Serial.println(request);
    } else
    {
        Serial.print("Error sending notification. Response code: ");
        Serial.println(httpResponseCode);
    }

    // Close the connection
    http.end();
}
