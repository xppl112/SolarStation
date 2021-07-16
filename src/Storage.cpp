#include "Storage.h"

Storage::Storage(){}

Settings Storage::getSettings(){
    Settings settings;
    eeprom_read_block((void*)&settings, 0, sizeof(settings));

    if(settings._integrityControlKey != SETTINGS_INTEGRITY_CONTROL_KEY_VALUE){
        return DEFAULT_SETTINGS;
    }

    return settings;
}

void Storage::updateSettings(Settings settings){
    eeprom_write_block((void*)&settings, 0, sizeof(settings));
}

unsigned long Storage::getRestartsCount(unsigned long integrityControlKey){
    if(integrityControlKey != SETTINGS_INTEGRITY_CONTROL_KEY_VALUE){
        return 0;
    }

    unsigned long count;
    eeprom_read_block((void*)&count, (const void*)RESTARTS_COUNT_OFFSET, sizeof(count));
    return count;
}

void Storage::incrementRestartsCount(){
    auto count = getRestartsCount();
    count++;
    eeprom_write_block((void*)&count, (void*)RESTARTS_COUNT_OFFSET, sizeof(count));
}