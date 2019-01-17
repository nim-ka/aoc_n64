#ifndef _GD_MAIN_H
#define _GD_MAIN_H

#include <ultra64.h>
#include "types.h"

// In various files of the Goddard subsystem, there are miscellaneous
// unused rodata strings. These can be generated via a printf call that
// is stubbed out, but not via define printf(...), as IDO 5.3 C 
// preprocessor did not support va_arg defines. Goddard, however, did
// use gd_printf, which is distinct from this type of stubbed call, as
// gd_printf actually is called. This could be because gd_printf could
// forward to printf (currently unclear whether it might or might not,
// gd_printf is awaiting decompilation), which would indicate goddard was
// in the middle of moving these calls to the wrapper function. The unmoved
// calls result in the unused rodata strings.
#ifdef __GNUC__
#define printf(...)                                       \
    _Pragma ("GCC diagnostic push")                       \
    _Pragma ("GCC diagnostic ignored \"-Wunused-value\"") \
    (__VA_ARGS__);                                        \
    _Pragma ("GCC diagnostic pop")
#else
#define printf
#endif

// structs
struct GdControl { // D_801B9920
    /* 0x00 */ s32 unk00;
    /* 0x04 */ u8  pad04[4];
    /* 0x08 */ s32 unk08; // Dpad-left (mask)
    /* 0x0C */ s32 unk0C; // Dpad-right (mask)
    /* 0x10 */ s32 unk10; // Dpad-up (mask)
    /* 0x10 */ s32 unk14; // Dpad-down (mask)
    /* 0x18 */ s32 unk18; // bool C-left
    /* 0x1C */ s32 unk1C; // bool C-rigth
    /* 0x20 */ s32 unk20; // bool C-up
    /* 0x24 */ s32 unk24; // bool C-down
    /* 0x28 */ void * unk28;     // null-checked ptr; symbol not deref-ed in extant code?
    /* 0x2C */ void * unk2C;     // some sort of old texture ptr?; symbol not deref-ed in extant code?
    /* 0x30 */ void * unk30;     // null-checked ptr; symbol not deref-ed in extant code?
    /* 0x34 */ s32 unk34; // bool A button
    /* 0x38 */ s32 unk38; // bool B button
    /* 0x3C */ u8  pad3C[0x44-0x3C];
    /* 0x44 */ s32 unk44; // bool L trigger pressed
    /* 0x48 */ s32 unk48; // bool R trigger pressed
    /* 0x4C */ s32 unk4C;
    /* 0x50 */ s32 unk50;
    /* 0x54 */ s32 unk54; // toggle bit? start pressed?
    /* 0x58 */ u8  pad58[0x7C-0x58];
    /* 0x7C */ f32 unk7C; // stick X (-80.0f <-> 80.0f) (this frame)
    /* 0x80 */ f32 unk80; // stick Y (this frame)
    /* 0x84 */ u8  pad84[4];
    /* 0x88 */ f32 unk88;
    /* 0x8C */ u8  pad8c[0xA0-0x8C];
    /* 0xA0 */ f32 unkA0;
    /* 0xA4 */ u8  padA4[0xAC-0xA4];
    /* 0xAC */ f32 unkAC;
    /* 0xB0 */ u8  padB0[0xB8-0xB0];
    /* 0xB8 */ s32 unkB8;
    /* 0xBC */ s32 unkBC;
    /* 0xC0 */ s32 unkC0; // stick X delta (1f)
    /* 0xC4 */ s32 unkC4; // stick Y delta
    /* 0xC8 */ s32 unkC8; // stick X
    /* 0xCC */ s32 unkCC; // stick Y
    /* 0xD0 */ s32 unkD0; // cursor x position?
    /* 0xD4 */ s32 unkD4; // cursor y position?
    /* 0xD8 */ /* hand/cursor state bitfield? */
                u8 unkD8b80 : 1;  // bool hand closed
                u8 unkD8b40 : 1;
                u8 unkD8b20 : 1;
                u8 unkD8b10 : 1;
                u8 unkD8b08 : 1;
                u8 unkD8b04 : 1;
                u8 unkD8b02 : 1;
    /* 0xDC */ u32 unkDC;
    /* 0xE0 */ u8  padE0[0xE8-0xE0];
    /* 0xE8 */ u32 unkE8;
    /* 0xEC */ u8  padEC[0xF0-0xEC];
    /* 0xF0 */ struct GdControl * unkF0; // previous frame data
};

// data
extern s32 D_801A8050;
extern f32 D_801A8058;
extern s32 D_801A805C;

// bss
extern struct GdControl D_801B9920;
extern struct GdControl D_801B9A18;

#endif /* _GD_MAIN_H */
