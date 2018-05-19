#ifndef _HUD_H
#define _HUD_H

#include "types.h"

/* Types and Structures */
struct Struct803306D0
{
    u8 (*beh)[];
    s16   unk4;
    s16   unk6;
};

struct Struct802E19DC
{
    /*00*/ u8  unk00;
    /*01*/ u8  unk01;
    /*02*/ u8  unk02;
    /*03*/ u8  unk03;
    /*04*/ u8 (*beh)[];
};

/*.bss*/
extern struct Object D_8035FB18;

/* Functions */
extern s16  func_802E1190(s16);
extern void func_802E1224(u32, u8 (*)[], s16, s16, s16, s16, s16);
extern void func_802E12CC(u32, u8 (*)[], s16, s16, s16, s16, s16);
extern void func_802E1374(u32, u8 (*)[], s16, s16, s16, s16, s16, s16);
extern void Unknown802E142C(u8 (*)[], s16[]);
extern void func_802E1504(s16, s16 *);
extern void func_802E1780(s16, s16 *);
extern void func_802E19DC(s16, s16 **);

#endif /* _HUD_H */
