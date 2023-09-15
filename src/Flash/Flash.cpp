// =============================================================================
// Utils | FlashStorage
// =============================================================================

#include "Flash.h"
#include "Logging.h"

#define MAGIC_NUMBER 0x3661

namespace Flash
{
    // add flash memory definition here
    // example: FlashStorage testMemory(sizeof(Flash::Structure::memory1), sizeof(DataType), MAGICNUMBER);
    FlashStorage failedOpen(sizeof(Flash::Structure::failedOpen), sizeof(failEntry), MAGIC_NUMBER);
    FlashStorage failedClose(sizeof(Flash::Structure::failedClose), sizeof(failEntry), MAGIC_NUMBER);


    // Add initializers here
    void initStorage()
    {
        failedOpen.init();
        failedClose.init();
    }

    void clear()
    {
        failedOpen.clear();
        failedClose.clear();
    }

    void init()
    {
    #ifdef ESP8266
        EEPROM.begin(sizeof(Flash::Structure));
    #else
        EEPROM.begin();
    #endif

        initStorage();

        Logging::log("Flash memory initialized\n");
    }

} // namespace Flash