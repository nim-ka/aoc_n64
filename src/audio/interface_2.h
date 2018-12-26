#ifndef _AUDIO_INTERFACE_2_H
#define _AUDIO_INTERFACE_2_H

#include "types.h"

struct Struct80333F00
{
    u8 filler0[0xA0];
    OSViMode viMode;
#if VERSION_US
    u8 filler[0x410];
    OSViMode unk500;
#endif
};

// probably the same as Struct80225DD8
struct Struct80222A18_2C
{
    u8 pad0b : 3;
    u8 unk0b10 : 1;
    u8 pad[0x1B];
    f32 unk1C;
};

// Same as Struct_func_80318870?
struct Struct80222A18
{
    u8 unk0b80 : 1;
    u8 unk0b40 : 1;
    u8 unk0b20 : 1;
    u8 unk1;
    u8 unk2;
    u8 pad1[11];
    u16 unkE;
    u8 pad2[0x8];
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    u8 pad3[0x8];
    struct Struct80222A18_2C *unk2C[1]; // unknown size
    u8 pad4[0x110];
}; // size = 0x140

extern s32 D_80331D40;
extern f32 D_803320E0[6];
extern struct Struct80333F00 D_80333F00;

extern struct Struct80222A18 D_80222A18[3];

extern u64 D_801FF200[]; // ucode yield data ptr
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
