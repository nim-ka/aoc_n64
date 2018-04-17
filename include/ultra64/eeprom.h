#ifndef _ULTRA64_EEPROM_H_
#define _ULTRA64_EEPROM_H_

/* Functions */

s32 osEepromLongRead(OSMesgQueue *mq, u8 address, u8 *buffer, int nbytes);
s32 osEepromLongWrite(OSMesgQueue *mq, u8 address, u8 *buffer, int nbytes);

#endif
