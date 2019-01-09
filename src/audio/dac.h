#ifndef _AUDIO_DAC_H
#define _AUDIO_DAC_H

#include "types.h"
#include "dma.h"

// extern ? D_802212A2;
// extern ? D_802211B0;
extern s8 D_80226D7E;
extern s32 D_80226D70;
// extern ? D_802212A0;
// extern ? D_802211B1;
// extern ? D_0A000004;
extern u8 D_80226D7F;
// extern ? D_803330E0;
// extern ? D_80332F5C;
extern u8 D_802218D0[];
extern u8 D_80221910[];
// extern ? D_80221A10;
// extern ? D_80225EA8;
// extern ? D_80222A18;
// extern ? D_80222DD8;
extern u8 D_802212B8[]; // sound alloc pool
extern u8 D_801CE000[];
extern s32 D_80333EEC;
// extern ? D_802212A8;
extern u8 D_802212C8[]; // sound alloc pool
// extern ? D_802212F8;
// extern ? D_80221308;
// extern ? D_80221318;
// extern ? D_8022132C;
// extern ? D_802214FC;
// extern ? D_802216CC;
extern u32 D_80221328[]; // unknown type, some kind of memory arena?
extern u32 D_802214F8[]; // same type
// extern ? D_802216C8;
// extern ? D_802214C0;
// extern ? D_80221690;
// extern ? D_80221860;
// extern ? D_802214BC;
// extern ? D_8022168C;
// extern ? D_8022185C;
extern volatile s32 D_80226D84; // counter of some sort
extern u32 D_80226B38;
extern s32 D_80226D64;
extern u32 D_80226D74;
// extern ? D_802212A3;
// extern ? D_80333EE4;
// extern ? D_80226D6C;
extern s32 D_80226D78;
// extern ? D_80221898;
// extern ? D_80226D7C;
// extern ? D_802212B0;
// extern ? D_802218A8;
// extern ? D_802218B0;
// extern ? D_802218C0;
extern u64 *D_80226D90[2];
extern u64 *D_80226D98; // audio ucode data

// extern ? func_80315E60(?);
// extern ? func_80315EA4(?);
// extern ? func_80315F94(?);
extern void *soundAlloc(u8 *pool, u32 size);
// extern ? func_80316094(?);
// extern ? func_803160B4(?);
// extern ? func_803160C8(?);
// extern ? Unknown803160F8(?);
extern s32 func_80316108(s32 arg0);
// extern ? func_80316164(?);
// extern ? func_803161E0(?);
// extern ? func_8031625C(?);
// extern ? func_80316318(?);
// extern ? func_803163DC(?);
extern void *func_803163DC(void *arg0, s32 arg1, s32 alloc, s32 arg3, s32 arg4);
extern void *func_8031680C(void *arg0, s32 arg1, s32 arg2);
// extern ? func_803168CC(?);
// extern ? func_803168F4(?);
extern void func_80316928(struct Struct80332190 *arg0);

#endif /* _AUDIO_DAC_H */
