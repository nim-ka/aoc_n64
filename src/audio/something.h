#ifndef _AUDIO_SOMETHING_H_
#define _AUDIO_SOMETHING_H_
#include <types.h>
#include "playback.h"
#include "dac.h"

#define aSetLoadBuffer(pkt, f, g, i, o, s) \
    aSetBuffer(pkt, f, g, i, o);           \
    aLoadBuffer(pkt, s);

#define ALIGN(val, amnt) (((val) + (1 << amnt) - 1) & ~((1 << amnt) - 1))
#define FIX(a) (u16 *)((u8 *)(a) + 0x80000000U)
#define aSetLoadBufferPair(pkt, c, off)                                                 \
    aSetLoadBuffer(pkt++, 0, c + 0x740, 0, 320 - c, FIX(&D_802211B0.unk14.unk00[off])); \
    aSetLoadBuffer(pkt++, 0, c + 0x880, 0, 320 - c, FIX(&D_802211B0.unk14.unk04[off]));

extern s8 D_802212A2;
extern s8 D_80226D7E;

extern f32 D_803332E4[128];
extern f32 D_803334E4[128];
extern f32 D_803336E4[128];
extern f32 D_803338E4[128];
extern f32 D_80333AE4[128];
extern f32 D_80333CE4[128];

extern s32 D_80226D70;
extern u8 D_802218D0[];
extern s32 D_80331D40;
extern s16 D_802212A0;
extern s8 D_80226D7F;

struct struct_3CD4_arg0
{
    u32 unk00;
    u32 unk04;
    u64 unk08;
};

void func_80313920(s32, u32);
s32 func_80313BB0(u16 arg0, u16 arg1, s32 arg2);
u64 *func_80313E54(u16 *, s32, u64 *, u32);
u64 *func_80314480(u16 *, s32, u64 *);
void func_8031D384(s32);
u64 *func_80314F08(u64 *, struct Struct_func_80318870 *, s32);
u64 *func_80315030(u64 *arg0, struct Struct_func_80318870 *arg1, s32 arg2, u16 arg3, s32 arg4, u32 arg5);
u64 *func_80315094(u64 *arg0, struct Struct_func_80318870 *arg1, s32 arg2, u16 arg3, s32 arg4, u16 *arg5);
u64 *func_80314FD4(u64 *arg0, struct Struct_func_80318870 *arg1, s32 arg2, u16 arg3, u16 arg4, u32 arg5);
u64 *func_803155F4(u64 *arg0, struct Struct_func_80318870 *arg1, s32 arg2, s32 arg3, s32 arg4);
#endif
