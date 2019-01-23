#ifndef _AUDIO_INTERFACE_2_H
#define _AUDIO_INTERFACE_2_H

#include "types.h"


// probably the same as Struct80225DD8
struct Struct80222A18_2C
{
    u8 pad0b : 3;
    u8 unk0b10 : 1;
    u8 pad[0x1B];
    f32 unk1C;
};

struct Struct80222A18
{
    /*0x000*/ u8 unk0b80 : 1;
    /*0x000*/ u8 unk0b40 : 1;
    /*0x000*/ u8 unk0b20 : 1;
    /*0x000*/ u8 unk0b10 : 1;
    /*0x000*/ u8 unk0b8 : 1;
    /*0x001*/ u8 unk1;
    /*0x002*/ u8 unk2;
    /*     */ u8 pad0[2];
    /*0x005*/ u8 unk5;
    /*0x006*/ u8 unk6;
    /*0x007*/ u8 unk7;
    /*0x008*/ u8 unk8;
    /*0x009*/ u8 unk9;
    /*     */ u8 pad1[4];
    /*0x00E*/ u16 unkE;
    /*     */ u8 pad2[2];
    /*0x012*/ u16 unk12;
    /*0x014*/ void *unk14;
    /*0x018*/ f32 unk18;
    /*0x01C*/ f32 unk1C;
    /*0x020*/ f32 unk20;
    /*     */ u8 pad3[0x8];
    /*0x02C*/ struct Struct80222A18_2C *unk2C[16];
    /*0x06C*/ void *unk6C;
    /*     */ u8 pad4[0x84 - 0x70];
    /*0x084*/ u8 unk84;
    /*     */ u8 pad5[0xD0 - 0x85];
    /*0x0D0*/ OSMesgQueue mesgQueue1;
    /*0x0E8*/ OSMesg mesg1;
    /*0x0EC*/ OSIoMesg ioMesg1;
    /*0x100*/ OSMesgQueue mesgQueue2;
    /*0x118*/ OSMesg mesg2;
    /*0x11C*/ OSIoMesg ioMesg2;
    /*0x130*/ u8 *currentMemAddr;
    /*0x134*/ void *mem;
    /*0x138*/ u32 currentDevAddr;
    /*0x13C*/ s32 size;
}; // size = 0x140

extern s32 D_80331D40;
extern f32 D_803320E0[6];

extern struct Struct80222A18 D_80222A18[3];

extern u64 gAudioSPTaskYieldBuffer[]; // ucode yield data ptr; only used in JP
extern u64 D_8032B800[]; // ucode
extern u64 D_80338750[]; // gfx ucode data
extern u64 D_80338F50[]; // ucode data
extern u64 audio_data_end[]; // end of ucode data

// from audio_something, updates ucode data
extern u64 *func_80313CD4(u64 *arg0, s32 *arg1, u16 *arg2, s32 arg3);

struct SPTask *func_8031D924(void);
void SetSound(int arg0, f32 *arg1);
void func_8031EED0(void);
void func_8031F7CC(u8 arg0, u16 arg1);
void func_8031F810(u8 arg0, u8 arg1, u16 arg2);
void func_8031FFB4(u8 arg0, u16 arg1, u8 arg2);
void func_80320040(u8 arg0, u16 arg1);
void func_80320248(u8 arg0);
void func_803202A0(void);
void func_803205E8(u32 arg0, f32 *arg1);
void func_803206F8(f32 *arg0);
void func_80320890(void);
void func_803208C0(u8 arg0, u16 arg1);
void func_80320980(u8 arg0, u16 arg1);
void func_80320A4C(u8 arg0, u8 arg1);
void func_80320A68(u8 dialogId);
extern void func_80320AE8(int, int, int);
void func_80320CE8(u16 arg0);
void func_80320E20(u16 arg0, u16 arg1);
void func_80320E74(void);
u16 func_80320E98(void);
void func_80320F84(u8 arg0, u8 arg1, u8 arg2, u16 arg3);
void func_80321080(u16 arg0);
void func_803210D4(u16 arg0);
void func_803211B0(void);
void func_803211EC(void);
void func_80321228(void);
void func_80321264(void);
void func_803212A0(u8 arg0);
void func_803212F0(void);
void func_8032132C(void);
void func_80321368(u8 arg0);
void func_80321434(u16 arg0);

#endif /* _AUDIO_INTERFACE_2_H */
