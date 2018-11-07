#ifndef _AUDIO_DMA_H
#define _AUDIO_DMA_H

#include "types.h"

// extern ? D_80221198;
// extern ? D_802211A0;
// extern ? D_80225F00;
// extern ? D_80226000;
extern OSMesgQueue D_80226500;
extern OSIoMesg D_80226520;
struct Unk16 {
    u8 pad1[13];
    u8 unkD;
    u8 unkE;
    u8 pad2;
};
extern struct Unk16 D_80226538[96];
extern u32 D_80226B3C;
extern u32 D_80226B40;
extern u8 D_80226B48[256];
extern u8 D_80226C48[256];
// extern u8 D_80226D48;
// extern u8 D_80226D49;
extern u8 D_80226D4A;
extern u8 D_80226D4B;
// extern ? D_80226D4C;
// extern ? D_80226D50;
// extern ? D_80226D54;
// extern ? D_80226D58;
extern u16 D_80226D5C;
// extern ? D_80226D60;
// extern ? D_80226D68;
// extern ? D_80226D88;
// extern ? D_80226D8C;
// extern ? D_80226D9C;
// extern ? D_80226DA0;
// extern ? D_80226EC0;
// extern ? D_80226E58;
// extern ? D_80226E98;
// extern ? D_80226E52;
// extern ? D_80226518;
// extern ? D_80332190;
// extern ? D_80333EE8;
// extern ? D_80333EF0;
// extern ? D_00745F80;
// extern ? D_00579140;
// extern ? D_00590200;

void BlockDmaCopy(u32 devAddr, void *vAddr, u32 nbytes);
void func_80317034(u32 devAddr, void *vAddr, u32 nbytes, OSMesgQueue *queue, OSIoMesg *mesg);
void func_803170A0(u32 *devAddr, u8 **vAddr, s32 *size, OSMesgQueue *queue, OSIoMesg *mesg);
void func_8031715C(void);
// extern ? func_80317270(?);
// extern ? func_8031758C(?);
// extern ? func_8031784C(?);
// extern ? func_80317A88(?);
// extern ? func_80317BE4(?);
extern s32 func_80317D1C(s32 arg0, s32 arg1);
// extern ? func_80317DC8(?);
// extern ? func_80317F04(?);
extern s32 func_8031804C(s32 arg0, void *arg1);
void func_80318178(u32 arg0, u8 arg1);
void func_80318280(s32 arg0, s32 arg1, s32 arg2);
extern void func_803182E0(s32 arg0, s32 arg1, s32 arg2);
extern void InitAudioSystem(void);

#endif /* _AUDIO_DMA_H */
