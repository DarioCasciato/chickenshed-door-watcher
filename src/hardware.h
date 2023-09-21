// =============================================================================
// Chickenshed-Door-Watcher | Hardware
// =============================================================================

#ifndef _CHICKENSHED_DOOR_WATCHER_HARDWARE_
#define _CHICKENSHED_DOOR_WATCHER_HARDWARE_

#include "configurations.h"
#include "gpio.h"
#include "EdgeDetection.h"


namespace Hardware
{
    // Port definitions
    enum class Port : uint8_t
    {
        reedDoor = (uint8_t) GPIO::Port::D6
    };


    // extern variable for reedDoor state
    extern bool reedDoorState;

    //extern EdgeDetection for reedDoor
    extern EdgeDetection reedDoor;


    /// @brief Initializes hardware
    void init();

    /// @brief Fetches hardware values
    void updateHardware();
} // namespace Hardware


#endif // _CHICKENSHED_DOOR_WATCHER_HARDWARE_