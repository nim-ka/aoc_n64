#ifndef _AUDIO_INTERFACE_1_H
#define _AUDIO_INTERFACE_1_H

#include "types.h"

struct Struct80225DD8
{
    u8 pad0;
    u8 unk1;
    u8 unk2;
    u8 pad1[2];
    u8 unk5;
    u8 pad3[0x3a];
    s32 unk40;
}; // unknown size, at least 0x80 I think?, maybe 0xc0.  0x74 get set to &D_80332AB4 at one point, which is array of 6 s16

struct Struct80222A18;

// extern ? D_80222DD8;
// extern ? D_80225E98;
extern struct Struct80225DD8 D_80225DD8;
// extern ? D_80332AA4;
// extern ? D_80332AB4;
// extern ? D_802245D8;
// extern ? D_80224648;
// extern ? D_80332884;
// extern ? D_80332A84;
// extern ? D_80332A94;
// extern ? D_80222AA8;

// extern ? func_8031A810(?);
// extern ? func_8031A920(?);
// extern ? func_8031AA10(?);
// extern ? func_8031AA4C(?);
// extern ? func_8031AAD0(?);
// extern ? func_8031AB3C(?);
// extern ? func_8031AB84(?);
// extern ? func_8031ACB0(?);
// extern ? func_8031AD80(?);
extern void func_8031AE24(struct Struct80222A18* arg0);
// extern ? func_8031AEF4(?);
// extern ? func_8031AF34(?);
// extern ? func_8031AF74(?);
// extern ? func_8031B01C(?);
// extern ? func_8031B030(?);
// extern ? func_8031B060(?);
// extern ? func_8031B0A4(?);
// extern ? func_8031BEB0(?);
// extern ? SetInstrument(?);
// extern ? func_8031C0C4(?);
// extern ? func_8031C104(?);
// extern ? func_8031CAD4(?);
extern void func_8031D384(s32 arg0);
extern void func_8031D42C(u32 arg0);
extern void func_8031D4B8(void);

#endif /* _AUDIO_INTERFACE_1_H */
