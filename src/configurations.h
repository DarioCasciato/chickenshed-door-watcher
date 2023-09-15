// =============================================================================
// Template-Project | Configurations
// =============================================================================

#ifndef _TEMPLATE_PROJECT_CONFIGURATIONS_
#define _TEMPLATE_PROJECT_CONFIGURATIONS_

#include <stdint.h>

const uint32_t fetchInterval = 300000;  // 5 minutes

// values get defined from analytical data from analyzer
const uint32_t meanDeviation = 0; // TODO tbd
const uint16_t timeTolerance = 0; // TODO tbd

// -----------------------------------------------------------------------------

inline const char* api_datetime = "http://worldtimeapi.org/api/timezone/Europe/Zurich";
inline const char* api_suntime = "http://api.openweathermap.org/data/2.5/weather?q=Zurich&appid=";
inline const char* api_key = "OPENWEATHERMAP_API_KEY";

// -----------------------------------------------------------------------------

#endif // _TEMPLATE_PROJECT_CONFIGURATIONS_