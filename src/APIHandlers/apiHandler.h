// =============================================================================
// Chickenshed-Door-Watcher | API Handler
// =============================================================================

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

namespace APIHandler
{
    /// @brief Sends a GET request to the API.
    ///
    /// @return The current unix time.
    uint32_t getUnixTime();

    /// @brief Sends a GET request to the API.
    ///
    /// @return The todays sunrise time.
    uint32_t getSunsetTime();

    /// @brief Sends a GET request to the API.
    ///
    /// @return The todays sunset time.
    uint32_t getSunriseTime();
}