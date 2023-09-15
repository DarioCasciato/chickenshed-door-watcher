// =============================================================================
// Template-Project | State
// =============================================================================

#ifndef _TEMPLATE_PROJECT_STATE_
#define _TEMPLATE_PROJECT_STATE_

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

#endif // _TEMPLATE_PROJECT_STATE_