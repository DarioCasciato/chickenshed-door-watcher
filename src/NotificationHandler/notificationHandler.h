// =============================================================================
// Chickenshed-Door-Watcher | Notification Handler
// =============================================================================

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

namespace Notification
{
    enum class Event : uint8_t
    {
        NotClosed,
        NotOpened
    };

    /// @brief Triggers a IFTTT webhook.¨
    ///
    /// @param Event The event name.
    void send(Event event);
}