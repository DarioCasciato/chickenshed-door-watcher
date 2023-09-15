// =============================================================================
// Utils | FlashStorage
// =============================================================================

#ifndef UTILS_FLASH_STRUCTURE_
#define UTILS_FLASH_STRUCTURE_

#include <stdint.h>

namespace Flash
{
    struct Structure
    {
        uint8_t      failedOpen[0x400]; // 1024 bytes
        uint8_t     failedClose[0x400]; // 1024 bytes
    };
} // namespace Flash

struct failEntry
{
    uint32_t    timestamp;
    uint32_t    sunTimestamp;
    uint32_t    expected;
};


#endif // UTILS_FLASH_STRUCTURE_