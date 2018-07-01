#ifndef _DEBUG_MEMORY_H
#define _DEBUG_MEMORY_H

#include "types.h"

/****** Structs ******/
/** 
 * This seems to be a large struct from debug_memory. A big global state struct for the head code?
 * A lot of referenced addresses after the base address seem to be members, 
 * but I have no idea where the struct ends... Have to check every usage of base addr
 */
struct GdMem801B9920 {
    /* 0x00 */ s32 unk00;       // D_801B9920
    /* 0x04 */ u8  pad04[0x18-0x4];
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ void* unk28;     // D_801B9948; null-checked ptr; symbol not deref-ed in extant code?
    /* 0x2C */ void* unk2C;     // D_801B994C; null-checked ptr; symbol not deref-ed in extant code?
    /* 0x30 */ void* unk30;     // D_801B9950; null-checked ptr; symbol not deref-ed in extant code?
    /* 0x34 */ u8  pad34[0x38-0x34];
    /* 0x38 */ void* unk38;
    /* 0x3C */ u8  pad3C[0x48-0x3C];
    /* 0x48 */ void* unk48;     // D_801B9968; null-checked ptr; symbol not deref-ed in extant code?
    /* 0x4C */ u8  pad4c[0x54-0x4C];
    /* 0x54 */ void* unk54;     // D_801B9974; null-checked ptr; symbol not deref-ed in extant code?
    /* 0x58 */ u8  pad58[0x88-0x58];
    /* 0x88 */ f32 unk88;       // D_801B99A8
    /* 0x8C */ u8  pad8c[0xA0-0x8C];
    /* 0xA0 */ f32 unkA0;       // D_801B99C0
    /* 0xA4 */ u8  padA4[0xAC-0xA4];
    /* 0xAC */ f32 unkAC;       // D_801B99CC
    /* 0xB0 */ u8  padB0[0xB8-0xB0];
    /* 0xB8 */ s32 unkB8;       // D_801B99D8
    /* 0xBC */ s32 unkBC;       // D_801B99DC
    /* 0xC0 */ s32 unkC0;
    /* 0xC4 */ s32 unkC4;
    /* 0xC8 */ u8  padC8[0xD0-0xC8];
    /* 0xD0 */ s32 unkD0;       // D_801B99F0
    /* 0xD4 */ s32 unkD4;       // D_801B99F4
    /* 0xD8 */ u32 unkD8;       // D_801B99F8
    /* 0xDC */ s32 unkDC;       // D_801B99FC
    /* 0xE0 */ u8  padE0[0xE8-0xE0];
    /* 0xE8 */ s32 unkE8;       // D_801B9A08
    /* 0xEC */ u8  padEC[0xF0-0xEC];
    /* 0xF0 */ struct GdMem801B9A18* unkF0; // D_801B9A10
    /* 0xF4 */ u8  padF4[0xF8-0xF4];
};
//TODO: check stack storage + derefs of base addr symbol
//TODO: Fix all uses of D_* symbols

struct GdMem801B9A18 {
    /* 0x00 */ u8  pad00[0x38-0x00];
    /* 0x38 */ void* unk38; //maybe a pointer
    /* 0x3C */ u8  pad3C[0xF8-0x3C];
}; /* sizeof >= 0xF8 */

/****** rodata ******/ 
extern s32 D_801A8050; // compile time bool?

/****** bss ******/ 
extern struct GdMem801B9920 D_801B9920;
extern struct GdMem801B9A18 D_801B9A18;

#endif /* _DEBUG_MEMORY_H */
