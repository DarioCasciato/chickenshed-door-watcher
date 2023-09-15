// =============================================================================
// Template-Project | Hardware
// =============================================================================

#include <Arduino.h>
#include "hardware.h"
#include "gpioHandler.h"

namespace Hardware
{
    // create EdgeDetection for reedDoor
    bool reedDoorState = false;
    EdgeDetection reedDoor(&reedDoorState);


    void init()
    {
        pinMode((uint8_t)Port::reedDoor, INPUT);
    }

    void updateHardware()
    {
        reedDoorState = GPIO::getPort(Port::reedDoor);
    }
} // namespace Hardware