// =============================================================================
// Chickenshed-Door-Watcher | State
// =============================================================================

#ifndef _CHICKENSHED_DOOR_WATCHER_STATE_
#define _CHICKENSHED_DOOR_WATCHER_STATE_

#include "hardware.h"

namespace State
{
    enum States : uint8_t
    {
        st_init,
        st_app
    };

    /// @brief State driver function
    void stateDriver();

    /// @brief Handler for the Idle state
    void stateInit();

    /// @brief Handler for the Open state
    void stateApp();
} // namespace State

#endif // _CHICKENSHED_DOOR_WATCHER_STATE_