// =============================================================================
// Chickenshed-Door-Watcher | State
// =============================================================================

#include "state.h"
#include "hardware.h"
#include "configurations.h"
#include "Timer.h"
#include "Flash/FlashStructure.h"
#include "APIHandlers/apiHandler.h"
#include "NotificationHandler/notificationHandler.h"

namespace
{
    Timer fetchTimer;

    uint32_t timestamp = 0;
    uint32_t sunTimestamp = 0;

    uint32_t predictedTimestamp = 0;

    enum DoorStates { door_open, door_closed };
    DoorStates doorState;
}

/// @brief Fetch the current time, sunrise/sunset time and predicted time based on the door state
///
/// @param state The current state of the door
void fetchTimes(DoorStates doorState);

//------------------------------------------------------------------------------

namespace State
{
    States state = States::st_init;

    void stateDriver()
    {
        switch (State::state)
        {
        case State::st_init: stateInit(); break;
        case State::st_app: stateApp(); break;

        default:    // catch invalid state (implement safety backup)
        goto exception;
            break;
        }

        return;

        exception:
            for(;;) { delay(500); }
    }


// ---------- State implementations ----------

    // State: Init
    void stateInit()
    {
        // Start timer
        fetchTimer.start();

        // decide state based on reed switch
        if(Hardware::reedDoor.getActState())
            doorState = door_closed;
        else
            doorState = door_open;

        // Fetch times
        fetchTimes(doorState);

        state = States::st_app;
    }


    // State: App
    void stateApp()
    {
        if(fetchTimer.elapsed(fetchInterval))
        {
            fetchTimer.start();
            fetchTimes(doorState);  // Fetch times

            // Check if the door should have transitioned by now
            if(timestamp > predictedTimestamp + timeTolerance)
            {
                if(doorState == door_open)
                {
                    //! Send notification
                    Notification::send(Notification::Event::NotOpened);
                    doorState = door_closed;
                }
                else
                {
                    //! Send notification
                    Notification::send(Notification::Event::NotClosed);
                    doorState = door_open;
                }
            }
        }

        // Check if the door has transitioned
        if(doorState == door_open && Hardware::reedDoor.getEdgePos())
        {
            doorState = door_closed;
            fetchTimes(doorState);  // Fetch times
        }
        else if(doorState == door_closed && Hardware::reedDoor.getEdgeNeg())
        {
            doorState = door_open;
            fetchTimes(doorState);  // Fetch times
        }
    }
} // namespace State

//------------------------------------------------------------------------------

// Other Functions

void fetchTimes(DoorStates doorState)
{
    timestamp = APIHandler::getUnixTime();  // Fetch the current Unix timestamp

    // Fetch the sunrise or sunset time based on the door state
    if(doorState == door_open)
        sunTimestamp = APIHandler::getSunsetTime();
    else
        sunTimestamp = APIHandler::getSunriseTime();

    // Calculate the predicted time for the door to open or close
    predictedTimestamp = sunTimestamp + meanDeviation;

    return;
}
