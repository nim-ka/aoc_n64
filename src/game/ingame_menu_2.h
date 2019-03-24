#ifndef INGAME_MENU_2_H
#define INGAME_MENU_2_H

#include <ultra64.h>
#include "types.h"

struct struct802DCEE0 {
    s8 unk00;
    //s8 filler01;
    s16 unk02;
    s32 unk04;
    s32 unk08;
    s32 unk0C;
    s32 unk10[2];
    s32 unk18;
    s32 unk1C;
    s8 filler20[56 - 0x20];
};

extern s8 D_80330640;
extern UNUSED s32 D_80330644;
extern Vtx_t D_80330648[3];
extern struct struct802DE838 D_80330678;
extern struct struct802DE838 D_80330680;
extern struct struct802DE838 D_80330688;

extern struct struct802DCEE0 *D_80360090;
extern Vec3i D_80360098;
extern s16 D_803600A4;
extern s16 D_803600A6;

extern void *func_802DECB8(int, Vec3s, Vec3s, Vec3s);
void func_802DD204(Vec3s sp30, Vec3s sp34, s16 *sp38, s16 *sp3C, s16 *sp40);
void func_802DE01C(Vec3s a0, Vec3s a1, Vec3s a2, s16 a3, s16 sp48);

#endif // INGAME_MENU_2_H
