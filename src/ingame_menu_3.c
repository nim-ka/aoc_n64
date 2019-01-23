#include <ultra64.h>

#include "sm64.h"
#include "display.h"
#include "memory.h"
#include "ingame_menu_2.h"
#include "ingame_menu.h"
#include "surface_collision.h"
#include "math_util.h"
#include "behavior_script.h"
#include "audio/interface_2.h"
#include "obj_behaviors.h"
extern struct MemoryPool *D_8033A124;
s16 D_803600B0[10];
Gfx *D_803600C4;
s32 D_803600C8;
s32 D_803600CC;

UNUSED s32 D_80330690 = 0;
UNUSED s32 D_80330694 = 0;
Vtx_t D_80330698[3] = 
{
    {
        {0, 0, 0},
        0,
        {1544, 964},
        {0xFF, 0xFF, 0xFF, 0xFF}
    },
    {
        {0, 0, 0},
        0,
        {522, -568},
        {0xFF, 0xFF, 0xFF, 0xFF}
    },
    {
        {0, 0, 0},
        0,
        {-498, 964},
        {0xFF, 0xFF, 0xFF, 0xFF}
    },
};

extern void *flower_bubbles_textures_ptr_0B002008;
extern void *lava_bubble_ptr_0B006020;
extern void *bubble_ptr_0B006848;
extern void *tiny_bubble_dl_0B006AB0;
extern void *tiny_bubble_dl_0B006D38;
extern void *tiny_bubble_dl_0B006D68;

s32 func_802DEE40(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 sp4 = (D_80360090 + a0)->unk04;
    s32 sp0 = (D_80360090 + a0)->unk0C;

    if (sqr(sp4 - a1) + sqr(sp0 - a2) > sqr(a3)) 
        return 0;
    
    return 1;
}

s32 func_802DEEF0() {
    s32 sp1C = RandomFloat() * 2000.0f - 1000.0f;
    if (sp1C < 0 )
        sp1C -= 1000;
    else
        sp1C += 1000;

    return sp1C;
}

void func_802DEF70(Vec3s sp30) {
    s32 sp2C;
    f32 *sp28;
    s32 sp24 = gGlobalTimer;
    UNUSED s16 sp22, sp20, sp1E;

    sp22 = sp30[0];
    sp20 = sp30[1];
    sp1E = sp30[2];

    for (sp2C = 0; sp2C < D_803600CC; sp2C++) {
        (D_80360090 + sp2C)->unk00 = func_802DEE40(sp2C, sp22, sp1E, 3000);
        if ((D_80360090 + sp2C)->unk00 == 0)  {
            (D_80360090 + sp2C)->unk04 = func_802DEEF0() + sp22;
            (D_80360090 + sp2C)->unk0C = func_802DEEF0() + sp1E;
            (D_80360090 + sp2C)->unk08 = func_803814B8((D_80360090 + sp2C)->unk04, 10000.0f, (D_80360090 + sp2C)->unk0C, &sp28);
            (D_80360090 + sp2C)->unk00 = 1;
            (D_80360090 + sp2C)->unk02 = RandomFloat() * 5.0f;
        } else if ((sp24 & 0x03) == 0) {
            (D_80360090 + sp2C)->unk02 += 1;
            if ((D_80360090 + sp2C)->unk02 > 5)
                (D_80360090 + sp2C)->unk02 = 0;
        }
    }
}

void func_802DF210(s32 sp28, Vec3s sp2C) {
    struct Surface *sp24;
    s16 sp22;
    s16 sp20, sp1E, sp1C;

    sp20 = sp2C[0];
    sp1E = sp2C[1];
    sp1C = sp2C[2];

    (D_80360090 + sp28)->unk04 = RandomFloat() * 6000.0f - 3000.0f + sp20;
    (D_80360090 + sp28)->unk0C = RandomFloat() * 6000.0f - 3000.0f + sp1C;
    
    if ((D_80360090 + sp28)->unk04 > 8000) 
        (D_80360090 + sp28)->unk04 = 16000 - (D_80360090 + sp28)->unk04;
    if ((D_80360090 + sp28)->unk04 < -8000) 
        (D_80360090 + sp28)->unk04 = -16000 - (D_80360090 + sp28)->unk04;

    if ((D_80360090 + sp28)->unk0C > 8000) 
        (D_80360090 + sp28)->unk0C = 16000 - (D_80360090 + sp28)->unk0C;
    if ((D_80360090 + sp28)->unk0C < -8000) 
        (D_80360090 + sp28)->unk0C = -16000 - (D_80360090 + sp28)->unk0C;

    sp22 = find_floor((D_80360090 + sp28)->unk04, sp1E + 500, (D_80360090 + sp28)->unk0C, &sp24);
    if (sp24 == NULL) {
        (D_80360090 + sp28)->unk08 = -10000;
        return;
    }
    
    if (sp24->type == SURFACE_LAVA) {
        (D_80360090 + sp28)->unk08 = sp22;
    }
    else {
        (D_80360090 + sp28)->unk08 = -10000;
    }
}

void func_802DF57C(Vec3s sp28) {
    s32 sp24;
    s32 sp20 = gGlobalTimer;
    s8 sp1F;
    UNUSED s16 sp1C, sp1A, sp18;

    sp1C = sp28[0];
    sp1A = sp28[1];
    sp18 = sp28[2];

    for (sp24 = 0; sp24 < D_803600CC; sp24++) {
        if ((D_80360090 + sp24)->unk00 == 0) {
            func_802DF210(sp24, sp28);
            (D_80360090 + sp24)->unk00 = 1;
        } 
        else if ((sp20 & 0x01) == 0) {
            (D_80360090 + sp24)->unk02 += 1;
            if ((D_80360090 + sp24)->unk02 > 8) {
                (D_80360090 + sp24)->unk00 = 0;
                (D_80360090 + sp24)->unk02 = 0;
            }
        }
    }

    if ((sp1F = (s32)(RandomFloat() * 16.0f)) == 8)
        SetSound(0x300D0081, D_803320E0);
}

void func_802DF74C(s32 *a0, s32 *a1, s32 *a2) {
    s32 sp24 = *a0 - D_803600B0[4];
    s32 sp20 = *a1 - D_803600B0[5];
    s32 sp1C = *a2 - D_803600B0[6];
    f32 sp18 = coss(D_803600B0[8]);
    f32 sp14 = sins(D_803600B0[8]);
    f32 sp10 = coss(-D_803600B0[9]);
    f32 spC = sins(-D_803600B0[9]);

    f32 sp8 = sp24 * sp10 - spC * sp18 * sp20 - sp14 * spC * sp1C;
    f32 sp4 = sp24 * spC  + sp18 * sp10 * sp20 - sp14 * sp10 * sp1C;
    f32 sp0 = sp20 * sp14 + sp18 * sp1C;

    *a0 = D_803600B0[4] + (s32)sp8;
    *a1 = D_803600B0[5] + (s32)sp4;
    *a2 = D_803600B0[6] + (s32)sp0;
}

s32 func_802DF998(s32 a0) {
    s32 UNUSED sp4;

    if ((D_80360090 + a0)->unk1C < D_803600B0[5] - 100)
        return 0;

    if ((D_80360090 + a0)->unk14 < 10)
        return 0;

    return 1;
}

#ifdef NON_MATCHING
/*
 * This is by far one of the most strangest -g functions ever known to matching
 * decompilation, especially for an unoptimized function. To begin with, part of
 * the problem is that while the C below generates close assembly, its register
 * allocation and add orders do not match. However, as far as we know, all attempts
 * to correct it have failed to get it any closer with defined behavior or reasonable
 * permutations of this.
 *
 * The two lines are to blame:
 *
 * (D_80360090 + sp1C)->unk04 = (sp1C + D_80360090)->unk14 ...
 * (D_80360090 + sp1C)->unk04 = (sp1C + D_80360090)->unk14 ...
 *
 * For whatever reason, the original asm order does f10 + f18 where as the generated always
 * seems to prefer f18 + f10. Correcting this causes worse issues, and also making it into
 * a subtraction instead of addition although functionally different does correct the registers,
 * but is the incorrect functionality. It was also thought the strange pointer access was
 * part of the problem, but attempts to use ptr[id] are way worse.
 *
 * There are several hypothesises:
 *
 * 1] This is the correct C, but other undefined factors such as extern after static
 *    declaration are causing the change in assembly or file line length or symbol count.
 * 2] This is the incorrect C, we may have been missing the right permutation, but with
 *    9 people having attempted this for many hours on end, this is increasingly unlikely.
 * 3] The emulator for the IRIX compiler is producing incorrect floating register emits in
 *    these edge cases.
 * 4] An extension of the second reason, it could be that otherwise illegal C and/or undefined
 *    behavior is actually accepted by the compiler and is causing the behavioral oddity.
 * 5] Missing compiler flag edge case such as -framepointer (although unlikely).
 */
void func_802DFA24(void) {
    s32 sp1C;

    for (sp1C = 0; sp1C < D_803600CC; sp1C++) {
        (D_80360090 + sp1C)->unk00 = func_802DF998(sp1C);
        if ((D_80360090 + sp1C)->unk00 == 0) {
            (D_80360090 + sp1C)->unk14 = RandomFloat() * 1000.0f;
            (D_80360090 + sp1C)->unk10 = RandomFloat() * 65536.0f;
            (D_80360090 + sp1C)->unk04 = (sp1C + D_80360090)->unk14 * sins((D_80360090 + sp1C)->unk10) + D_803600B0[1];
            (D_80360090 + sp1C)->unk0C = (sp1C + D_80360090)->unk14 * coss((D_80360090 + sp1C)->unk10) + D_803600B0[3];
            (D_80360090 + sp1C)->unk1C = D_803600B0[2] + (RandomFloat() * 100.0f - 50.0f);
            (D_80360090 + sp1C)->unk08 = (sp1C + D_80360090)->unk1C;
            (D_80360090 + sp1C)->unk18 = 0;
            (D_80360090 + sp1C)->unk00 = 1;

            func_802DF74C(&(D_80360090 + sp1C)->unk04, &(D_80360090 + sp1C)->unk08, &(D_80360090 + sp1C)->unk0C);
        }
        else {
            (D_80360090 + sp1C)->unk14 -= 0x28; 
            (D_80360090 + sp1C)->unk10 += (s16) (3000 - (D_80360090 + sp1C)->unk14 * 2) + 0x400;
            (D_80360090 + sp1C)->unk04 = (sp1C + D_80360090)->unk14 * sins((D_80360090 + sp1C)->unk10) + D_803600B0[1];
            (D_80360090 + sp1C)->unk0C = (sp1C + D_80360090)->unk14 * coss((D_80360090 + sp1C)->unk10) + D_803600B0[3];
            (D_80360090 + sp1C)->unk1C -= -((s16)(D_80360090 + sp1C)->unk14 / 100) + 0x28;
            (D_80360090 + sp1C)->unk08 = (sp1C + D_80360090)->unk1C;

            func_802DF74C(&(D_80360090 + sp1C)->unk04, &(D_80360090 + sp1C)->unk08, &(D_80360090 + sp1C)->unk0C);
        }
    }
}

#else
void func_802DFA24(void);

GLOBAL_ASM(
glabel func_802DFA24
/* 09AA24 802DFA24 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 09AA28 802DFA28 AFBF0014 */  sw    $ra, 0x14($sp)
/* 09AA2C 802DFA2C 3C0E8036 */  lui   $t6, %hi(D_803600CC) # $t6, 0x8036
/* 09AA30 802DFA30 8DCE00CC */  lw    $t6, %lo(D_803600CC)($t6)
/* 09AA34 802DFA34 AFA0001C */  sw    $zero, 0x1c($sp)
/* 09AA38 802DFA38 19C00130 */  blez  $t6, .L802DFEFC
/* 09AA3C 802DFA3C 00000000 */   nop   
.L802DFA40:
/* 09AA40 802DFA40 0C0B7E66 */  jal   func_802DF998
/* 09AA44 802DFA44 8FA4001C */   lw    $a0, 0x1c($sp)
/* 09AA48 802DFA48 8FB8001C */  lw    $t8, 0x1c($sp)
/* 09AA4C 802DFA4C 3C0F8036 */  lui   $t7, %hi(D_80360090) # $t7, 0x8036
/* 09AA50 802DFA50 8DEF0090 */  lw    $t7, %lo(D_80360090)($t7)
/* 09AA54 802DFA54 0018C8C0 */  sll   $t9, $t8, 3
/* 09AA58 802DFA58 0338C823 */  subu  $t9, $t9, $t8
/* 09AA5C 802DFA5C 0019C8C0 */  sll   $t9, $t9, 3
/* 09AA60 802DFA60 01F94021 */  addu  $t0, $t7, $t9
/* 09AA64 802DFA64 A1020000 */  sb    $v0, ($t0)
/* 09AA68 802DFA68 8FA9001C */  lw    $t1, 0x1c($sp)
/* 09AA6C 802DFA6C 3C0B8036 */  lui   $t3, %hi(D_80360090) # $t3, 0x8036
/* 09AA70 802DFA70 8D6B0090 */  lw    $t3, %lo(D_80360090)($t3)
/* 09AA74 802DFA74 000950C0 */  sll   $t2, $t1, 3
/* 09AA78 802DFA78 01495023 */  subu  $t2, $t2, $t1
/* 09AA7C 802DFA7C 000A50C0 */  sll   $t2, $t2, 3
/* 09AA80 802DFA80 014B6021 */  addu  $t4, $t2, $t3
/* 09AA84 802DFA84 818D0000 */  lb    $t5, ($t4)
/* 09AA88 802DFA88 15A0009A */  bnez  $t5, .L802DFCF4
/* 09AA8C 802DFA8C 00000000 */   nop   
/* 09AA90 802DFA90 0C0E0F2D */  jal   RandomFloat
/* 09AA94 802DFA94 00000000 */   nop   
/* 09AA98 802DFA98 3C01447A */  li    $at, 0x447A0000 # 1000.000000
/* 09AA9C 802DFA9C 44812000 */  mtc1  $at, $f4
/* 09AAA0 802DFAA0 8FB9001C */  lw    $t9, 0x1c($sp)
/* 09AAA4 802DFAA4 3C0F8036 */  lui   $t7, %hi(D_80360090) # $t7, 0x8036
/* 09AAA8 802DFAA8 46040182 */  mul.s $f6, $f0, $f4
/* 09AAAC 802DFAAC 8DEF0090 */  lw    $t7, %lo(D_80360090)($t7)
/* 09AAB0 802DFAB0 001940C0 */  sll   $t0, $t9, 3
/* 09AAB4 802DFAB4 01194023 */  subu  $t0, $t0, $t9
/* 09AAB8 802DFAB8 000840C0 */  sll   $t0, $t0, 3
/* 09AABC 802DFABC 01E84821 */  addu  $t1, $t7, $t0
/* 09AAC0 802DFAC0 4600320D */  trunc.w.s $f8, $f6
/* 09AAC4 802DFAC4 44184000 */  mfc1  $t8, $f8
/* 09AAC8 802DFAC8 00000000 */  nop   
/* 09AACC 802DFACC AD380014 */  sw    $t8, 0x14($t1)
/* 09AAD0 802DFAD0 0C0E0F2D */  jal   RandomFloat
/* 09AAD4 802DFAD4 00000000 */   nop   
/* 09AAD8 802DFAD8 3C014780 */  li    $at, 0x47800000 # 65536.000000
/* 09AADC 802DFADC 44815000 */  mtc1  $at, $f10
/* 09AAE0 802DFAE0 8FAD001C */  lw    $t5, 0x1c($sp)
/* 09AAE4 802DFAE4 3C0C8036 */  lui   $t4, %hi(D_80360090) # $t4, 0x8036
/* 09AAE8 802DFAE8 460A0402 */  mul.s $f16, $f0, $f10
/* 09AAEC 802DFAEC 8D8C0090 */  lw    $t4, %lo(D_80360090)($t4)
/* 09AAF0 802DFAF0 000D70C0 */  sll   $t6, $t5, 3
/* 09AAF4 802DFAF4 01CD7023 */  subu  $t6, $t6, $t5
/* 09AAF8 802DFAF8 000E70C0 */  sll   $t6, $t6, 3
/* 09AAFC 802DFAFC 018EC821 */  addu  $t9, $t4, $t6
/* 09AB00 802DFB00 4600848D */  trunc.w.s $f18, $f16
/* 09AB04 802DFB04 440B9000 */  mfc1  $t3, $f18
/* 09AB08 802DFB08 00000000 */  nop   
/* 09AB0C 802DFB0C AF2B0010 */  sw    $t3, 0x10($t9)
/* 09AB10 802DFB10 8FAF001C */  lw    $t7, 0x1c($sp)
/* 09AB14 802DFB14 3C188036 */  lui   $t8, %hi(D_80360090) # $t8, 0x8036
/* 09AB18 802DFB18 8F180090 */  lw    $t8, %lo(D_80360090)($t8)
/* 09AB1C 802DFB1C 000F40C0 */  sll   $t0, $t7, 3
/* 09AB20 802DFB20 010F4023 */  subu  $t0, $t0, $t7
/* 09AB24 802DFB24 000840C0 */  sll   $t0, $t0, 3
/* 09AB28 802DFB28 01184821 */  addu  $t1, $t0, $t8
/* 09AB2C 802DFB2C 8D2A0014 */  lw    $t2, 0x14($t1)
/* 09AB30 802DFB30 03086821 */  addu  $t5, $t8, $t0
/* 09AB34 802DFB34 95AC0012 */  lhu   $t4, 0x12($t5)
/* 09AB38 802DFB38 448A2000 */  mtc1  $t2, $f4
/* 09AB3C 802DFB3C 3C198036 */  lui   $t9, %hi(D_803600B0) # $t9, 0x8036
/* 09AB40 802DFB40 273900B0 */  addiu $t9, %lo(D_803600B0) # addiu $t9, $t9, 0xb0
/* 09AB44 802DFB44 468021A0 */  cvt.s.w $f6, $f4
/* 09AB48 802DFB48 000C7103 */  sra   $t6, $t4, 4
/* 09AB4C 802DFB4C 872F0002 */  lh    $t7, 2($t9)
/* 09AB50 802DFB50 000E5880 */  sll   $t3, $t6, 2
/* 09AB54 802DFB54 3C018038 */  lui    $at, %hi(gSineTable)
/* 09AB58 802DFB58 002B0821 */  addu  $at, $at, $t3
/* 09AB5C 802DFB5C C4286000 */  lwc1  $f8, %lo(gSineTable)($at)
/* 09AB60 802DFB60 448F8000 */  mtc1  $t7, $f16
/* 09AB64 802DFB64 46083282 */  mul.s $f10, $f6, $f8
/* 09AB68 802DFB68 468084A0 */  cvt.s.w $f18, $f16
/* 09AB6C 802DFB6C 46125100 */  add.s $f4, $f10, $f18
/* 09AB70 802DFB70 4600218D */  trunc.w.s $f6, $f4
/* 09AB74 802DFB74 440A3000 */  mfc1  $t2, $f6
/* 09AB78 802DFB78 00000000 */  nop   
/* 09AB7C 802DFB7C ADAA0004 */  sw    $t2, 4($t5)
/* 09AB80 802DFB80 8FB8001C */  lw    $t8, 0x1c($sp)
/* 09AB84 802DFB84 3C0C8036 */  lui   $t4, %hi(D_80360090) # $t4, 0x8036
/* 09AB88 802DFB88 8D8C0090 */  lw    $t4, %lo(D_80360090)($t4)
/* 09AB8C 802DFB8C 001840C0 */  sll   $t0, $t8, 3
/* 09AB90 802DFB90 01184023 */  subu  $t0, $t0, $t8
/* 09AB94 802DFB94 000840C0 */  sll   $t0, $t0, 3
/* 09AB98 802DFB98 010C7021 */  addu  $t6, $t0, $t4
/* 09AB9C 802DFB9C 8DCB0014 */  lw    $t3, 0x14($t6)
/* 09ABA0 802DFBA0 0188C821 */  addu  $t9, $t4, $t0
/* 09ABA4 802DFBA4 972F0012 */  lhu   $t7, 0x12($t9)
/* 09ABA8 802DFBA8 448B4000 */  mtc1  $t3, $f8
/* 09ABAC 802DFBAC 3C0D8036 */  lui   $t5, %hi(D_803600B0) # $t5, 0x8036
/* 09ABB0 802DFBB0 25AD00B0 */  addiu $t5, %lo(D_803600B0) # addiu $t5, $t5, 0xb0
/* 09ABB4 802DFBB4 46804420 */  cvt.s.w $f16, $f8
/* 09ABB8 802DFBB8 000F4903 */  sra   $t1, $t7, 4
/* 09ABBC 802DFBBC 85B80006 */  lh    $t8, 6($t5)
/* 09ABC0 802DFBC0 00095080 */  sll   $t2, $t1, 2
/* 09ABC4 802DFBC4 3C018038 */  lui    $at, %hi(gCosineTable)
/* 09ABC8 802DFBC8 002A0821 */  addu  $at, $at, $t2
/* 09ABCC 802DFBCC C42A7000 */  lwc1  $f10, %lo(gCosineTable)($at)
/* 09ABD0 802DFBD0 44982000 */  mtc1  $t8, $f4
/* 09ABD4 802DFBD4 460A8482 */  mul.s $f18, $f16, $f10
/* 09ABD8 802DFBD8 468021A0 */  cvt.s.w $f6, $f4
/* 09ABDC 802DFBDC 46069200 */  add.s $f8, $f18, $f6
/* 09ABE0 802DFBE0 4600440D */  trunc.w.s $f16, $f8
/* 09ABE4 802DFBE4 440B8000 */  mfc1  $t3, $f16
/* 09ABE8 802DFBE8 00000000 */  nop   
/* 09ABEC 802DFBEC AF2B000C */  sw    $t3, 0xc($t9)
/* 09ABF0 802DFBF0 0C0E0F2D */  jal   RandomFloat
/* 09ABF4 802DFBF4 00000000 */   nop   
/* 09ABF8 802DFBF8 3C0142C8 */  li    $at, 0x42C80000 # 100.000000
/* 09ABFC 802DFBFC 44815000 */  mtc1  $at, $f10
/* 09AC00 802DFC00 3C0C8036 */  lui    $t4, %hi(D_803600B0) 
/* 09AC04 802DFC04 258C00B0 */  addiu $t4, %lo(D_803600B0) # addiu $t4, $t4, 0xb0
/* 09AC08 802DFC08 85880004 */  lh    $t0, 4($t4)
/* 09AC0C 802DFC0C 460A0102 */  mul.s $f4, $f0, $f10
/* 09AC10 802DFC10 3C014248 */  li    $at, 0x42480000 # 50.000000
/* 09AC14 802DFC14 44884000 */  mtc1  $t0, $f8
/* 09AC18 802DFC18 44819000 */  mtc1  $at, $f18
/* 09AC1C 802DFC1C 8FAD001C */  lw    $t5, 0x1c($sp)
/* 09AC20 802DFC20 3C0A8036 */  lui   $t2, %hi(D_80360090) # $t2, 0x8036
/* 09AC24 802DFC24 46804420 */  cvt.s.w $f16, $f8
/* 09AC28 802DFC28 8D4A0090 */  lw    $t2, %lo(D_80360090)($t2)
/* 09AC2C 802DFC2C 000DC0C0 */  sll   $t8, $t5, 3
/* 09AC30 802DFC30 030DC023 */  subu  $t8, $t8, $t5
/* 09AC34 802DFC34 0018C0C0 */  sll   $t8, $t8, 3
/* 09AC38 802DFC38 46122181 */  sub.s $f6, $f4, $f18
/* 09AC3C 802DFC3C 01587021 */  addu  $t6, $t2, $t8
/* 09AC40 802DFC40 46103280 */  add.s $f10, $f6, $f16
/* 09AC44 802DFC44 4600510D */  trunc.w.s $f4, $f10
/* 09AC48 802DFC48 44092000 */  mfc1  $t1, $f4
/* 09AC4C 802DFC4C 00000000 */  nop   
/* 09AC50 802DFC50 ADC9001C */  sw    $t1, 0x1c($t6)
/* 09AC54 802DFC54 8FAB001C */  lw    $t3, 0x1c($sp)
/* 09AC58 802DFC58 3C0C8036 */  lui   $t4, %hi(D_80360090) # $t4, 0x8036
/* 09AC5C 802DFC5C 8D8C0090 */  lw    $t4, %lo(D_80360090)($t4)
/* 09AC60 802DFC60 000BC8C0 */  sll   $t9, $t3, 3
/* 09AC64 802DFC64 032BC823 */  subu  $t9, $t9, $t3
/* 09AC68 802DFC68 0019C8C0 */  sll   $t9, $t9, 3
/* 09AC6C 802DFC6C 032C4021 */  addu  $t0, $t9, $t4
/* 09AC70 802DFC70 8D0F001C */  lw    $t7, 0x1c($t0)
/* 09AC74 802DFC74 01996821 */  addu  $t5, $t4, $t9
/* 09AC78 802DFC78 ADAF0008 */  sw    $t7, 8($t5)
/* 09AC7C 802DFC7C 8FB8001C */  lw    $t8, 0x1c($sp)
/* 09AC80 802DFC80 3C0A8036 */  lui   $t2, %hi(D_80360090) # $t2, 0x8036
/* 09AC84 802DFC84 8D4A0090 */  lw    $t2, %lo(D_80360090)($t2)
/* 09AC88 802DFC88 001848C0 */  sll   $t1, $t8, 3
/* 09AC8C 802DFC8C 01384823 */  subu  $t1, $t1, $t8
/* 09AC90 802DFC90 000948C0 */  sll   $t1, $t1, 3
/* 09AC94 802DFC94 01497021 */  addu  $t6, $t2, $t1
/* 09AC98 802DFC98 ADC00018 */  sw    $zero, 0x18($t6)
/* 09AC9C 802DFC9C 8FAC001C */  lw    $t4, 0x1c($sp)
/* 09ACA0 802DFCA0 3C088036 */  lui   $t0, %hi(D_80360090) # $t0, 0x8036
/* 09ACA4 802DFCA4 8D080090 */  lw    $t0, %lo(D_80360090)($t0)
/* 09ACA8 802DFCA8 000CC8C0 */  sll   $t9, $t4, 3
/* 09ACAC 802DFCAC 032CC823 */  subu  $t9, $t9, $t4
/* 09ACB0 802DFCB0 0019C8C0 */  sll   $t9, $t9, 3
/* 09ACB4 802DFCB4 240B0001 */  li    $t3, 1
/* 09ACB8 802DFCB8 01197821 */  addu  $t7, $t0, $t9
/* 09ACBC 802DFCBC A1EB0000 */  sb    $t3, ($t7)
/* 09ACC0 802DFCC0 8FAD001C */  lw    $t5, 0x1c($sp)
/* 09ACC4 802DFCC4 3C0A8036 */  lui   $t2, %hi(D_80360090) # $t2, 0x8036
/* 09ACC8 802DFCC8 8D4A0090 */  lw    $t2, %lo(D_80360090)($t2)
/* 09ACCC 802DFCCC 000DC0C0 */  sll   $t8, $t5, 3
/* 09ACD0 802DFCD0 030DC023 */  subu  $t8, $t8, $t5
/* 09ACD4 802DFCD4 0018C0C0 */  sll   $t8, $t8, 3
/* 09ACD8 802DFCD8 030A4821 */  addu  $t1, $t8, $t2
/* 09ACDC 802DFCDC 25240004 */  addiu $a0, $t1, 4
/* 09ACE0 802DFCE0 25250008 */  addiu $a1, $t1, 8
/* 09ACE4 802DFCE4 0C0B7DD3 */  jal   func_802DF74C
/* 09ACE8 802DFCE8 2526000C */   addiu $a2, $t1, 0xc
/* 09ACEC 802DFCEC 1000007B */  b     .L802DFEDC
/* 09ACF0 802DFCF0 00000000 */   nop   
.L802DFCF4:
/* 09ACF4 802DFCF4 8FAE001C */  lw    $t6, 0x1c($sp)
/* 09ACF8 802DFCF8 3C088036 */  lui   $t0, %hi(D_80360090) # $t0, 0x8036
/* 09ACFC 802DFCFC 8D080090 */  lw    $t0, %lo(D_80360090)($t0)
/* 09AD00 802DFD00 000E60C0 */  sll   $t4, $t6, 3
/* 09AD04 802DFD04 018E6023 */  subu  $t4, $t4, $t6
/* 09AD08 802DFD08 000C60C0 */  sll   $t4, $t4, 3
/* 09AD0C 802DFD0C 0188C821 */  addu  $t9, $t4, $t0
/* 09AD10 802DFD10 8F2B0014 */  lw    $t3, 0x14($t9)
/* 09AD14 802DFD14 256FFFD8 */  addiu $t7, $t3, -0x28
/* 09AD18 802DFD18 AF2F0014 */  sw    $t7, 0x14($t9)
/* 09AD1C 802DFD1C 8FAD001C */  lw    $t5, 0x1c($sp)
/* 09AD20 802DFD20 3C0A8036 */  lui   $t2, %hi(D_80360090) # $t2, 0x8036
/* 09AD24 802DFD24 8D4A0090 */  lw    $t2, %lo(D_80360090)($t2)
/* 09AD28 802DFD28 000DC0C0 */  sll   $t8, $t5, 3
/* 09AD2C 802DFD2C 030DC023 */  subu  $t8, $t8, $t5
/* 09AD30 802DFD30 0018C0C0 */  sll   $t8, $t8, 3
/* 09AD34 802DFD34 01586021 */  addu  $t4, $t2, $t8
/* 09AD38 802DFD38 8D880014 */  lw    $t0, 0x14($t4)
/* 09AD3C 802DFD3C 240F0BB8 */  li    $t7, 3000
/* 09AD40 802DFD40 030A4821 */  addu  $t1, $t8, $t2
/* 09AD44 802DFD44 00085840 */  sll   $t3, $t0, 1
/* 09AD48 802DFD48 8D2E0010 */  lw    $t6, 0x10($t1)
/* 09AD4C 802DFD4C 01EBC823 */  subu  $t9, $t7, $t3
/* 09AD50 802DFD50 00196C00 */  sll   $t5, $t9, 0x10
/* 09AD54 802DFD54 000D5403 */  sra   $t2, $t5, 0x10
/* 09AD58 802DFD58 01CAC021 */  addu  $t8, $t6, $t2
/* 09AD5C 802DFD5C 270C0400 */  addiu $t4, $t8, 0x400
/* 09AD60 802DFD60 AD2C0010 */  sw    $t4, 0x10($t1)
/* 09AD64 802DFD64 8FA8001C */  lw    $t0, 0x1c($sp)
/* 09AD68 802DFD68 3C0B8036 */  lui   $t3, %hi(D_80360090) # $t3, 0x8036
/* 09AD6C 802DFD6C 8D6B0090 */  lw    $t3, %lo(D_80360090)($t3)
/* 09AD70 802DFD70 000878C0 */  sll   $t7, $t0, 3
/* 09AD74 802DFD74 01E87823 */  subu  $t7, $t7, $t0
/* 09AD78 802DFD78 000F78C0 */  sll   $t7, $t7, 3
/* 09AD7C 802DFD7C 01EBC821 */  addu  $t9, $t7, $t3
/* 09AD80 802DFD80 8F2D0014 */  lw    $t5, 0x14($t9)
/* 09AD84 802DFD84 016F7021 */  addu  $t6, $t3, $t7
/* 09AD88 802DFD88 95CA0012 */  lhu   $t2, 0x12($t6)
/* 09AD8C 802DFD8C 448D9000 */  mtc1  $t5, $f18
/* 09AD90 802DFD90 3C098036 */  lui   $t1, %hi(D_803600B0) # $t1, 0x8036
/* 09AD94 802DFD94 252900B0 */  addiu $t1, %lo(D_803600B0) # addiu $t1, $t1, 0xb0
/* 09AD98 802DFD98 46809220 */  cvt.s.w $f8, $f18
/* 09AD9C 802DFD9C 000AC103 */  sra   $t8, $t2, 4
/* 09ADA0 802DFDA0 85280002 */  lh    $t0, 2($t1)
/* 09ADA4 802DFDA4 00186080 */  sll   $t4, $t8, 2
/* 09ADA8 802DFDA8 3C018038 */  lui    $at, %hi(gSineTable)
/* 09ADAC 802DFDAC 002C0821 */  addu  $at, $at, $t4
/* 09ADB0 802DFDB0 C4266000 */  lwc1  $f6, %lo(gSineTable)($at)
/* 09ADB4 802DFDB4 44885000 */  mtc1  $t0, $f10
/* 09ADB8 802DFDB8 46064402 */  mul.s $f16, $f8, $f6
/* 09ADBC 802DFDBC 46805120 */  cvt.s.w $f4, $f10
/* 09ADC0 802DFDC0 46048480 */  add.s $f18, $f16, $f4
/* 09ADC4 802DFDC4 4600920D */  trunc.w.s $f8, $f18
/* 09ADC8 802DFDC8 440D4000 */  mfc1  $t5, $f8
/* 09ADCC 802DFDCC 00000000 */  nop   
/* 09ADD0 802DFDD0 ADCD0004 */  sw    $t5, 4($t6)
/* 09ADD4 802DFDD4 8FAB001C */  lw    $t3, 0x1c($sp)
/* 09ADD8 802DFDD8 3C0A8036 */  lui   $t2, %hi(D_80360090) # $t2, 0x8036
/* 09ADDC 802DFDDC 8D4A0090 */  lw    $t2, %lo(D_80360090)($t2)
/* 09ADE0 802DFDE0 000B78C0 */  sll   $t7, $t3, 3
/* 09ADE4 802DFDE4 01EB7823 */  subu  $t7, $t7, $t3
/* 09ADE8 802DFDE8 000F78C0 */  sll   $t7, $t7, 3
/* 09ADEC 802DFDEC 01EAC021 */  addu  $t8, $t7, $t2
/* 09ADF0 802DFDF0 8F0C0014 */  lw    $t4, 0x14($t8)
/* 09ADF4 802DFDF4 014F4821 */  addu  $t1, $t2, $t7
/* 09ADF8 802DFDF8 95280012 */  lhu   $t0, 0x12($t1)
/* 09ADFC 802DFDFC 448C3000 */  mtc1  $t4, $f6
/* 09AE00 802DFE00 3C0E8036 */  lui   $t6, %hi(D_803600B0) # $t6, 0x8036
/* 09AE04 802DFE04 25CE00B0 */  addiu $t6, %lo(D_803600B0) # addiu $t6, $t6, 0xb0
/* 09AE08 802DFE08 468032A0 */  cvt.s.w $f10, $f6
/* 09AE0C 802DFE0C 0008C903 */  sra   $t9, $t0, 4
/* 09AE10 802DFE10 85CB0006 */  lh    $t3, 6($t6)
/* 09AE14 802DFE14 00196880 */  sll   $t5, $t9, 2
/* 09AE18 802DFE18 3C018038 */  lui    $at, %hi(gCosineTable)
/* 09AE1C 802DFE1C 002D0821 */  addu  $at, $at, $t5
/* 09AE20 802DFE20 C4307000 */  lwc1  $f16, %lo(gCosineTable)($at)
/* 09AE24 802DFE24 448B9000 */  mtc1  $t3, $f18
/* 09AE28 802DFE28 46105102 */  mul.s $f4, $f10, $f16
/* 09AE2C 802DFE2C 46809220 */  cvt.s.w $f8, $f18
/* 09AE30 802DFE30 46082180 */  add.s $f6, $f4, $f8
/* 09AE34 802DFE34 4600328D */  trunc.w.s $f10, $f6
/* 09AE38 802DFE38 440C5000 */  mfc1  $t4, $f10
/* 09AE3C 802DFE3C 00000000 */  nop   
/* 09AE40 802DFE40 AD2C000C */  sw    $t4, 0xc($t1)
/* 09AE44 802DFE44 8FAA001C */  lw    $t2, 0x1c($sp)
/* 09AE48 802DFE48 3C088036 */  lui   $t0, %hi(D_80360090) # $t0, 0x8036
/* 09AE4C 802DFE4C 8D080090 */  lw    $t0, %lo(D_80360090)($t0)
/* 09AE50 802DFE50 000A78C0 */  sll   $t7, $t2, 3
/* 09AE54 802DFE54 01EA7823 */  subu  $t7, $t7, $t2
/* 09AE58 802DFE58 000F78C0 */  sll   $t7, $t7, 3
/* 09AE5C 802DFE5C 010F7021 */  addu  $t6, $t0, $t7
/* 09AE60 802DFE60 85CB0016 */  lh    $t3, 0x16($t6)
/* 09AE64 802DFE64 24010064 */  li    $at, 100
/* 09AE68 802DFE68 01E8C821 */  addu  $t9, $t7, $t0
/* 09AE6C 802DFE6C 0161001A */  div   $zero, $t3, $at
/* 09AE70 802DFE70 8F2D001C */  lw    $t5, 0x1c($t9)
/* 09AE74 802DFE74 0000C012 */  mflo  $t8
/* 09AE78 802DFE78 00186023 */  negu  $t4, $t8
/* 09AE7C 802DFE7C 01AC4823 */  subu  $t1, $t5, $t4
/* 09AE80 802DFE80 252AFFD8 */  addiu $t2, $t1, -0x28
/* 09AE84 802DFE84 AF2A001C */  sw    $t2, 0x1c($t9)
/* 09AE88 802DFE88 8FA8001C */  lw    $t0, 0x1c($sp)
/* 09AE8C 802DFE8C 3C0E8036 */  lui   $t6, %hi(D_80360090) # $t6, 0x8036
/* 09AE90 802DFE90 8DCE0090 */  lw    $t6, %lo(D_80360090)($t6)
/* 09AE94 802DFE94 000878C0 */  sll   $t7, $t0, 3
/* 09AE98 802DFE98 01E87823 */  subu  $t7, $t7, $t0
/* 09AE9C 802DFE9C 000F78C0 */  sll   $t7, $t7, 3
/* 09AEA0 802DFEA0 01EE5821 */  addu  $t3, $t7, $t6
/* 09AEA4 802DFEA4 8D78001C */  lw    $t8, 0x1c($t3)
/* 09AEA8 802DFEA8 01CF6821 */  addu  $t5, $t6, $t7
/* 09AEAC 802DFEAC ADB80008 */  sw    $t8, 8($t5)
/* 09AEB0 802DFEB0 8FAC001C */  lw    $t4, 0x1c($sp)
/* 09AEB4 802DFEB4 3C0A8036 */  lui   $t2, %hi(D_80360090) # $t2, 0x8036
/* 09AEB8 802DFEB8 8D4A0090 */  lw    $t2, %lo(D_80360090)($t2)
/* 09AEBC 802DFEBC 000C48C0 */  sll   $t1, $t4, 3
/* 09AEC0 802DFEC0 012C4823 */  subu  $t1, $t1, $t4
/* 09AEC4 802DFEC4 000948C0 */  sll   $t1, $t1, 3
/* 09AEC8 802DFEC8 012AC821 */  addu  $t9, $t1, $t2
/* 09AECC 802DFECC 27240004 */  addiu $a0, $t9, 4
/* 09AED0 802DFED0 27250008 */  addiu $a1, $t9, 8
/* 09AED4 802DFED4 0C0B7DD3 */  jal   func_802DF74C
/* 09AED8 802DFED8 2726000C */   addiu $a2, $t9, 0xc
.L802DFEDC:
/* 09AEDC 802DFEDC 8FA8001C */  lw    $t0, 0x1c($sp)
/* 09AEE0 802DFEE0 3C0E8036 */  lui   $t6, %hi(D_803600CC) # $t6, 0x8036
/* 09AEE4 802DFEE4 8DCE00CC */  lw    $t6, %lo(D_803600CC)($t6)
/* 09AEE8 802DFEE8 250B0001 */  addiu $t3, $t0, 1
/* 09AEEC 802DFEEC AFAB001C */  sw    $t3, 0x1c($sp)
/* 09AEF0 802DFEF0 016E082A */  slt   $at, $t3, $t6
/* 09AEF4 802DFEF4 1420FED2 */  bnez  $at, .L802DFA40
/* 09AEF8 802DFEF8 00000000 */   nop   
.L802DFEFC:
/* 09AEFC 802DFEFC 10000001 */  b     .L802DFF04
/* 09AF00 802DFF00 00000000 */   nop   
.L802DFF04:
/* 09AF04 802DFF04 8FBF0014 */  lw    $ra, 0x14($sp)
/* 09AF08 802DFF08 27BD0020 */  addiu $sp, $sp, 0x20
/* 09AF0C 802DFF0C 03E00008 */  jr    $ra
/* 09AF10 802DFF10 00000000 */   nop   
)
#endif

s32 func_802DFF14(s32 sp20) {
    UNUSED s32 unk;

    if (!func_802DEE40(sp20, D_803600B0[1], D_803600B0[3], 1000) 
        || D_803600B0[2] + 1500 < (D_80360090 + sp20)->unk08) 
        return 0;

    return 1;
}

#ifdef NON_MATCHING
/* See note for func_802DFA24 */
void func_802DFFA8(void) {
    s32 sp1C;

    for (sp1C = 0; sp1C < D_803600CC; sp1C++) {
        (D_80360090 + sp1C)->unk00 = func_802DFF14(sp1C);
        if ((D_80360090 + sp1C)->unk00 == 0) {
            (D_80360090 + sp1C)->unk14 = RandomFloat() * 300.0f;
            (D_80360090 + sp1C)->unk10 = RandomU16();
            (D_80360090 + sp1C)->unk04 = (sp1C + D_80360090)->unk14 * sins((D_80360090 + sp1C)->unk10) + D_803600B0[1];
            (D_80360090 + sp1C)->unk0C = (sp1C + D_80360090)->unk14 * coss((D_80360090 + sp1C)->unk10) + D_803600B0[3];
            (D_80360090 + sp1C)->unk08 = D_803600B0[2] + (RandomFloat() * 400.0f - 200.0f);
        }
        else {
            (D_80360090 + sp1C)->unk14 += 10; 
            (D_80360090 + sp1C)->unk04 += sins((D_80360090 + sp1C)->unk10) * 10.0f;
            (D_80360090 + sp1C)->unk0C += coss((D_80360090 + sp1C)->unk10) * 10.0f;
            (D_80360090 + sp1C)->unk08 -= ((D_80360090 + sp1C)->unk14 / 30) - 50;
        }
    }
}

#else
void func_802DFFA8(void);

GLOBAL_ASM(
glabel func_802DFFA8
/* 09AFA8 802DFFA8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 09AFAC 802DFFAC AFBF0014 */  sw    $ra, 0x14($sp)
/* 09AFB0 802DFFB0 3C0E8036 */  lui   $t6, %hi(D_803600CC) # $t6, 0x8036
/* 09AFB4 802DFFB4 8DCE00CC */  lw    $t6, %lo(D_803600CC)($t6)
/* 09AFB8 802DFFB8 AFA0001C */  sw    $zero, 0x1c($sp)
/* 09AFBC 802DFFBC 19C000D4 */  blez  $t6, .L802E0310
/* 09AFC0 802DFFC0 00000000 */   nop   
.L802DFFC4:
/* 09AFC4 802DFFC4 0C0B7FC5 */  jal   func_802DFF14
/* 09AFC8 802DFFC8 8FA4001C */   lw    $a0, 0x1c($sp)
/* 09AFCC 802DFFCC 8FB8001C */  lw    $t8, 0x1c($sp)
/* 09AFD0 802DFFD0 3C0F8036 */  lui   $t7, %hi(D_80360090) # $t7, 0x8036
/* 09AFD4 802DFFD4 8DEF0090 */  lw    $t7, %lo(D_80360090)($t7)
/* 09AFD8 802DFFD8 0018C8C0 */  sll   $t9, $t8, 3
/* 09AFDC 802DFFDC 0338C823 */  subu  $t9, $t9, $t8
/* 09AFE0 802DFFE0 0019C8C0 */  sll   $t9, $t9, 3
/* 09AFE4 802DFFE4 01F94021 */  addu  $t0, $t7, $t9
/* 09AFE8 802DFFE8 A1020000 */  sb    $v0, ($t0)
/* 09AFEC 802DFFEC 8FA9001C */  lw    $t1, 0x1c($sp)
/* 09AFF0 802DFFF0 3C0B8036 */  lui   $t3, %hi(D_80360090) # $t3, 0x8036
/* 09AFF4 802DFFF4 8D6B0090 */  lw    $t3, %lo(D_80360090)($t3)
/* 09AFF8 802DFFF8 000950C0 */  sll   $t2, $t1, 3
/* 09AFFC 802DFFFC 01495023 */  subu  $t2, $t2, $t1
/* 09B000 802E0000 000A50C0 */  sll   $t2, $t2, 3
/* 09B004 802E0004 014B6021 */  addu  $t4, $t2, $t3
/* 09B008 802E0008 818D0000 */  lb    $t5, ($t4)
/* 09B00C 802E000C 15A0006C */  bnez  $t5, .L802E01C0
/* 09B010 802E0010 00000000 */   nop   
/* 09B014 802E0014 0C0E0F2D */  jal   RandomFloat
/* 09B018 802E0018 00000000 */   nop   
/* 09B01C 802E001C 3C014396 */  li    $at, 0x43960000 # 300.000000
/* 09B020 802E0020 44812000 */  mtc1  $at, $f4
/* 09B024 802E0024 8FB9001C */  lw    $t9, 0x1c($sp)
/* 09B028 802E0028 3C0F8036 */  lui   $t7, %hi(D_80360090) # $t7, 0x8036
/* 09B02C 802E002C 46040182 */  mul.s $f6, $f0, $f4
/* 09B030 802E0030 8DEF0090 */  lw    $t7, %lo(D_80360090)($t7)
/* 09B034 802E0034 001940C0 */  sll   $t0, $t9, 3
/* 09B038 802E0038 01194023 */  subu  $t0, $t0, $t9
/* 09B03C 802E003C 000840C0 */  sll   $t0, $t0, 3
/* 09B040 802E0040 01E84821 */  addu  $t1, $t7, $t0
/* 09B044 802E0044 4600320D */  trunc.w.s $f8, $f6
/* 09B048 802E0048 44184000 */  mfc1  $t8, $f8
/* 09B04C 802E004C 00000000 */  nop   
/* 09B050 802E0050 AD380014 */  sw    $t8, 0x14($t1)
/* 09B054 802E0054 0C0E0EEC */  jal   RandomU16
/* 09B058 802E0058 00000000 */   nop   
/* 09B05C 802E005C 8FAB001C */  lw    $t3, 0x1c($sp)
/* 09B060 802E0060 3C0A8036 */  lui   $t2, %hi(D_80360090) # $t2, 0x8036
/* 09B064 802E0064 8D4A0090 */  lw    $t2, %lo(D_80360090)($t2)
/* 09B068 802E0068 000B60C0 */  sll   $t4, $t3, 3
/* 09B06C 802E006C 018B6023 */  subu  $t4, $t4, $t3
/* 09B070 802E0070 000C60C0 */  sll   $t4, $t4, 3
/* 09B074 802E0074 014C6821 */  addu  $t5, $t2, $t4
/* 09B078 802E0078 ADA20010 */  sw    $v0, 0x10($t5)
/* 09B07C 802E007C 8FAE001C */  lw    $t6, 0x1c($sp)
/* 09B080 802E0080 3C0F8036 */  lui   $t7, %hi(D_80360090) # $t7, 0x8036
/* 09B084 802E0084 8DEF0090 */  lw    $t7, %lo(D_80360090)($t7)
/* 09B088 802E0088 000EC8C0 */  sll   $t9, $t6, 3
/* 09B08C 802E008C 032EC823 */  subu  $t9, $t9, $t6
/* 09B090 802E0090 0019C8C0 */  sll   $t9, $t9, 3
/* 09B094 802E0094 032F4021 */  addu  $t0, $t9, $t7
/* 09B098 802E0098 8D180014 */  lw    $t8, 0x14($t0)
/* 09B09C 802E009C 01F94821 */  addu  $t1, $t7, $t9
/* 09B0A0 802E00A0 952B0012 */  lhu   $t3, 0x12($t1)
/* 09B0A4 802E00A4 44985000 */  mtc1  $t8, $f10
/* 09B0A8 802E00A8 3C0D8036 */  lui   $t5, %hi(D_803600B0) # $t5, 0x8036
/* 09B0AC 802E00AC 25AD00B0 */  addiu $t5, %lo(D_803600B0) # addiu $t5, $t5, 0xb0
/* 09B0B0 802E00B0 46805420 */  cvt.s.w $f16, $f10
/* 09B0B4 802E00B4 000B5103 */  sra   $t2, $t3, 4
/* 09B0B8 802E00B8 85AE0002 */  lh    $t6, 2($t5)
/* 09B0BC 802E00BC 000A6080 */  sll   $t4, $t2, 2
/* 09B0C0 802E00C0 3C018038 */  lui    $at, %hi(gSineTable)
/* 09B0C4 802E00C4 002C0821 */  addu  $at, $at, $t4
/* 09B0C8 802E00C8 C4326000 */  lwc1  $f18, %lo(gSineTable)($at)
/* 09B0CC 802E00CC 448E3000 */  mtc1  $t6, $f6
/* 09B0D0 802E00D0 46128102 */  mul.s $f4, $f16, $f18
/* 09B0D4 802E00D4 46803220 */  cvt.s.w $f8, $f6
/* 09B0D8 802E00D8 46082280 */  add.s $f10, $f4, $f8
/* 09B0DC 802E00DC 4600540D */  trunc.w.s $f16, $f10
/* 09B0E0 802E00E0 44188000 */  mfc1  $t8, $f16
/* 09B0E4 802E00E4 00000000 */  nop   
/* 09B0E8 802E00E8 AD380004 */  sw    $t8, 4($t1)
/* 09B0EC 802E00EC 8FAF001C */  lw    $t7, 0x1c($sp)
/* 09B0F0 802E00F0 3C0B8036 */  lui   $t3, %hi(D_80360090) # $t3, 0x8036
/* 09B0F4 802E00F4 8D6B0090 */  lw    $t3, %lo(D_80360090)($t3)
/* 09B0F8 802E00F8 000FC8C0 */  sll   $t9, $t7, 3
/* 09B0FC 802E00FC 032FC823 */  subu  $t9, $t9, $t7
/* 09B100 802E0100 0019C8C0 */  sll   $t9, $t9, 3
/* 09B104 802E0104 032B5021 */  addu  $t2, $t9, $t3
/* 09B108 802E0108 8D4C0014 */  lw    $t4, 0x14($t2)
/* 09B10C 802E010C 01796821 */  addu  $t5, $t3, $t9
/* 09B110 802E0110 95AE0012 */  lhu   $t6, 0x12($t5)
/* 09B114 802E0114 448C9000 */  mtc1  $t4, $f18
/* 09B118 802E0118 3C098036 */  lui   $t1, %hi(D_803600B0) # $t1, 0x8036
/* 09B11C 802E011C 252900B0 */  addiu $t1, %lo(D_803600B0) # addiu $t1, $t1, 0xb0
/* 09B120 802E0120 468091A0 */  cvt.s.w $f6, $f18
/* 09B124 802E0124 000E4103 */  sra   $t0, $t6, 4
/* 09B128 802E0128 852F0006 */  lh    $t7, 6($t1)
/* 09B12C 802E012C 0008C080 */  sll   $t8, $t0, 2
/* 09B130 802E0130 3C018038 */  lui    $at, %hi(gCosineTable)
/* 09B134 802E0134 00380821 */  addu  $at, $at, $t8
/* 09B138 802E0138 C4247000 */  lwc1  $f4, %lo(gCosineTable)($at)
/* 09B13C 802E013C 448F5000 */  mtc1  $t7, $f10
/* 09B140 802E0140 46043202 */  mul.s $f8, $f6, $f4
/* 09B144 802E0144 46805420 */  cvt.s.w $f16, $f10
/* 09B148 802E0148 46104480 */  add.s $f18, $f8, $f16
/* 09B14C 802E014C 4600918D */  trunc.w.s $f6, $f18
/* 09B150 802E0150 440C3000 */  mfc1  $t4, $f6
/* 09B154 802E0154 00000000 */  nop   
/* 09B158 802E0158 ADAC000C */  sw    $t4, 0xc($t5)
/* 09B15C 802E015C 0C0E0F2D */  jal   RandomFloat
/* 09B160 802E0160 00000000 */   nop   
/* 09B164 802E0164 3C0143C8 */  li    $at, 0x43C80000 # 400.000000
/* 09B168 802E0168 44812000 */  mtc1  $at, $f4
/* 09B16C 802E016C 3C0B8036 */  lui    $t3, %hi(D_803600B0) 
/* 09B170 802E0170 256B00B0 */  addiu $t3, %lo(D_803600B0) # addiu $t3, $t3, 0xb0
/* 09B174 802E0174 85790004 */  lh    $t9, 4($t3)
/* 09B178 802E0178 46040282 */  mul.s $f10, $f0, $f4
/* 09B17C 802E017C 3C014348 */  li    $at, 0x43480000 # 200.000000
/* 09B180 802E0180 44999000 */  mtc1  $t9, $f18
/* 09B184 802E0184 44814000 */  mtc1  $at, $f8
/* 09B188 802E0188 8FA9001C */  lw    $t1, 0x1c($sp)
/* 09B18C 802E018C 3C188036 */  lui   $t8, %hi(D_80360090) # $t8, 0x8036
/* 09B190 802E0190 468091A0 */  cvt.s.w $f6, $f18
/* 09B194 802E0194 8F180090 */  lw    $t8, %lo(D_80360090)($t8)
/* 09B198 802E0198 000978C0 */  sll   $t7, $t1, 3
/* 09B19C 802E019C 01E97823 */  subu  $t7, $t7, $t1
/* 09B1A0 802E01A0 000F78C0 */  sll   $t7, $t7, 3
/* 09B1A4 802E01A4 46085401 */  sub.s $f16, $f10, $f8
/* 09B1A8 802E01A8 030F5021 */  addu  $t2, $t8, $t7
/* 09B1AC 802E01AC 46068100 */  add.s $f4, $f16, $f6
/* 09B1B0 802E01B0 4600228D */  trunc.w.s $f10, $f4
/* 09B1B4 802E01B4 44085000 */  mfc1  $t0, $f10
/* 09B1B8 802E01B8 1000004D */  b     .L802E02F0
/* 09B1BC 802E01BC AD480008 */   sw    $t0, 8($t2)
.L802E01C0:
/* 09B1C0 802E01C0 8FAC001C */  lw    $t4, 0x1c($sp)
/* 09B1C4 802E01C4 3C0B8036 */  lui   $t3, %hi(D_80360090) # $t3, 0x8036
/* 09B1C8 802E01C8 8D6B0090 */  lw    $t3, %lo(D_80360090)($t3)
/* 09B1CC 802E01CC 000C68C0 */  sll   $t5, $t4, 3
/* 09B1D0 802E01D0 01AC6823 */  subu  $t5, $t5, $t4
/* 09B1D4 802E01D4 000D68C0 */  sll   $t5, $t5, 3
/* 09B1D8 802E01D8 01ABC821 */  addu  $t9, $t5, $t3
/* 09B1DC 802E01DC 8F2E0014 */  lw    $t6, 0x14($t9)
/* 09B1E0 802E01E0 25C9000A */  addiu $t1, $t6, 0xa
/* 09B1E4 802E01E4 AF290014 */  sw    $t1, 0x14($t9)
/* 09B1E8 802E01E8 8FB8001C */  lw    $t8, 0x1c($sp)
/* 09B1EC 802E01EC 3C088036 */  lui   $t0, %hi(D_80360090) # $t0, 0x8036
/* 09B1F0 802E01F0 8D080090 */  lw    $t0, %lo(D_80360090)($t0)
/* 09B1F4 802E01F4 001878C0 */  sll   $t7, $t8, 3
/* 09B1F8 802E01F8 01F87823 */  subu  $t7, $t7, $t8
/* 09B1FC 802E01FC 000F78C0 */  sll   $t7, $t7, 3
/* 09B200 802E0200 010F6821 */  addu  $t5, $t0, $t7
/* 09B204 802E0204 95AB0012 */  lhu   $t3, 0x12($t5)
/* 09B208 802E0208 3C018038 */  lui   $at, %hi(gSineTable)
/* 09B20C 802E020C 01E85021 */  addu  $t2, $t7, $t0
/* 09B210 802E0210 000B7103 */  sra   $t6, $t3, 4
/* 09B214 802E0214 000E4880 */  sll   $t1, $t6, 2
/* 09B218 802E0218 00290821 */  addu  $at, $at, $t1
/* 09B21C 802E021C C4306000 */  lwc1  $f16, %lo(gSineTable)($at)
/* 09B220 802E0220 8D4C0004 */  lw    $t4, 4($t2)
/* 09B224 802E0224 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 09B228 802E0228 44813000 */  mtc1  $at, $f6
/* 09B22C 802E022C 448C4000 */  mtc1  $t4, $f8
/* 09B230 802E0230 46068102 */  mul.s $f4, $f16, $f6
/* 09B234 802E0234 468044A0 */  cvt.s.w $f18, $f8
/* 09B238 802E0238 46049280 */  add.s $f10, $f18, $f4
/* 09B23C 802E023C 4600520D */  trunc.w.s $f8, $f10
/* 09B240 802E0240 44184000 */  mfc1  $t8, $f8
/* 09B244 802E0244 00000000 */  nop   
/* 09B248 802E0248 AD580004 */  sw    $t8, 4($t2)
/* 09B24C 802E024C 8FAC001C */  lw    $t4, 0x1c($sp)
/* 09B250 802E0250 3C0F8036 */  lui   $t7, %hi(D_80360090) # $t7, 0x8036
/* 09B254 802E0254 8DEF0090 */  lw    $t7, %lo(D_80360090)($t7)
/* 09B258 802E0258 000C40C0 */  sll   $t0, $t4, 3
/* 09B25C 802E025C 010C4023 */  subu  $t0, $t0, $t4
/* 09B260 802E0260 000840C0 */  sll   $t0, $t0, 3
/* 09B264 802E0264 01E87021 */  addu  $t6, $t7, $t0
/* 09B268 802E0268 95C90012 */  lhu   $t1, 0x12($t6)
/* 09B26C 802E026C 3C018038 */  lui   $at, %hi(gCosineTable)
/* 09B270 802E0270 010F6821 */  addu  $t5, $t0, $t7
/* 09B274 802E0274 0009C903 */  sra   $t9, $t1, 4
/* 09B278 802E0278 0019C080 */  sll   $t8, $t9, 2
/* 09B27C 802E027C 00380821 */  addu  $at, $at, $t8
/* 09B280 802E0280 C4327000 */  lwc1  $f18, %lo(gCosineTable)($at)
/* 09B284 802E0284 8DAB000C */  lw    $t3, 0xc($t5)
/* 09B288 802E0288 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 09B28C 802E028C 44812000 */  mtc1  $at, $f4
/* 09B290 802E0290 448B8000 */  mtc1  $t3, $f16
/* 09B294 802E0294 46049282 */  mul.s $f10, $f18, $f4
/* 09B298 802E0298 468081A0 */  cvt.s.w $f6, $f16
/* 09B29C 802E029C 460A3200 */  add.s $f8, $f6, $f10
/* 09B2A0 802E02A0 4600440D */  trunc.w.s $f16, $f8
/* 09B2A4 802E02A4 440C8000 */  mfc1  $t4, $f16
/* 09B2A8 802E02A8 00000000 */  nop   
/* 09B2AC 802E02AC ADAC000C */  sw    $t4, 0xc($t5)
/* 09B2B0 802E02B0 8FAB001C */  lw    $t3, 0x1c($sp)
/* 09B2B4 802E02B4 3C088036 */  lui   $t0, %hi(D_80360090) # $t0, 0x8036
/* 09B2B8 802E02B8 8D080090 */  lw    $t0, %lo(D_80360090)($t0)
/* 09B2BC 802E02BC 000B78C0 */  sll   $t7, $t3, 3
/* 09B2C0 802E02C0 01EB7823 */  subu  $t7, $t7, $t3
/* 09B2C4 802E02C4 000F78C0 */  sll   $t7, $t7, 3
/* 09B2C8 802E02C8 010FC821 */  addu  $t9, $t0, $t7
/* 09B2CC 802E02CC 8F380014 */  lw    $t8, 0x14($t9)
/* 09B2D0 802E02D0 2401001E */  li    $at, 30
/* 09B2D4 802E02D4 01E87021 */  addu  $t6, $t7, $t0
/* 09B2D8 802E02D8 0301001A */  div   $zero, $t8, $at
/* 09B2DC 802E02DC 8DC90008 */  lw    $t1, 8($t6)
/* 09B2E0 802E02E0 00005012 */  mflo  $t2
/* 09B2E4 802E02E4 012A6023 */  subu  $t4, $t1, $t2
/* 09B2E8 802E02E8 258D0032 */  addiu $t5, $t4, 0x32
/* 09B2EC 802E02EC ADCD0008 */  sw    $t5, 8($t6)
.L802E02F0:
/* 09B2F0 802E02F0 8FAB001C */  lw    $t3, 0x1c($sp)
/* 09B2F4 802E02F4 3C0F8036 */  lui   $t7, %hi(D_803600CC) # $t7, 0x8036
/* 09B2F8 802E02F8 8DEF00CC */  lw    $t7, %lo(D_803600CC)($t7)
/* 09B2FC 802E02FC 25680001 */  addiu $t0, $t3, 1
/* 09B300 802E0300 AFA8001C */  sw    $t0, 0x1c($sp)
/* 09B304 802E0304 010F082A */  slt   $at, $t0, $t7
/* 09B308 802E0308 1420FF2E */  bnez  $at, .L802DFFC4
/* 09B30C 802E030C 00000000 */   nop   
.L802E0310:
/* 09B310 802E0310 10000001 */  b     .L802E0318
/* 09B314 802E0314 00000000 */   nop   
.L802E0318:
/* 09B318 802E0318 8FBF0014 */  lw    $ra, 0x14($sp)
/* 09B31C 802E031C 27BD0020 */  addiu $sp, $sp, 0x20
/* 09B320 802E0320 03E00008 */  jr    $ra
/* 09B324 802E0324 00000000 */   nop
)
#endif

s32 func_802E0328(s32 sp20) {
    s32 sp1C;

    switch (sp20) {
        case 0: 
            return 0;

        case 11:
            D_803600C8 = 30;
            D_803600CC = 30;
            break;

        case 12:
            D_803600C8 = 15;
            D_803600CC = 15;
            break;

        case 13:
            D_803600C8 = 60;
            break;

        case 14:
            D_803600C8 = 60;
            break;
    }

    D_80360090 = (struct struct802DCEE0 *)mem_pool_alloc(D_8033A124, D_803600C8 * sizeof(struct struct802DCEE0));
    if (!D_80360090)
        return 0;

    bzero(D_80360090, D_803600C8 * sizeof(struct struct802DCEE0));
    bzero(D_803600B0, sizeof(D_803600B0));

    if (sp20 == 12) {
        if (0) { }
        
        for (sp1C = 0; sp1C < D_803600C8; sp1C++) {
            (D_80360090 + sp1C)->unk02 = RandomFloat() * 7.0f; 
        }


        if (0) { }
            }

    D_80330640 = sp20;
    return 1;
}

void func_802E0504(s32 sp28, Vec3s sp2C, Vec3s sp30, Vec3s sp34, Vec3s sp38) {
    switch(sp28) {
        case 11:
            func_802DEF70(sp2C);
            sp30[0] = 50;
            sp30[1] = 0;
            sp30[2] = 0;
            sp34[0] = 0;
            sp34[1] = 75;
            sp34[2] = 0;
            sp38[0] = -50;
            sp38[1] = 0;
            sp38[2] = 0;
            break;

        case 12:
            func_802DF57C(sp2C);
            sp30[0] = 100;
            sp30[1] = 0;
            sp30[2] = 0;
            sp34[0] = 0;
            sp34[1] = 150;
            sp34[2] = 0;
            sp38[0] = -100;
            sp38[1] = 0;
            sp38[2] = 0;
            break;

        case 13:
            func_802DFA24();
            sp30[0] = 40;
            sp30[1] = 0;
            sp30[2] = 0;
            sp34[0] = 0;
            sp34[1] = 60;
            sp34[2] = 0;
            sp38[0] = -40;
            sp38[1] = 0;
            sp38[2] = 0;
            break;

        case 14:
            func_802DFFA8();
            sp30[0] = 40;
            sp30[1] = 0;
            sp30[2] = 0;
            sp34[0] = 0;
            sp34[1] = 60;
            sp34[2] = 0;
            sp38[0] = -40;
            sp38[1] = 0;
            sp38[2] = 0;
            break;
    }
}

void func_802E0708(Gfx *sp28, s32 sp2C, Vec3s sp30, Vec3s sp34, Vec3s sp38, Vtx *sp3C) {
    s32 sp24 = 0;
    Vtx *sp20 = (Vtx *)alloc_display_list(15 * sizeof(Vtx));

    if (sp20 == NULL)
        return;

    for (sp24 = 0; sp24 < 15; sp24 += 3) {
        sp20[sp24] = sp3C[0];
        sp20[sp24].v.ob[0] = sp30[0] + (D_80360090 + (sp2C + sp24 / 3))->unk04;
        sp20[sp24].v.ob[1] = sp30[1] + (D_80360090 + (sp2C + sp24 / 3))->unk08;
        sp20[sp24].v.ob[2] = sp30[2] + (D_80360090 + (sp2C + sp24 / 3))->unk0C;

        sp20[sp24 + 1] = sp3C[1];
        sp20[sp24 + 1].v.ob[0] = sp34[0] + (D_80360090 + (sp2C + sp24 / 3))->unk04;
        sp20[sp24 + 1].v.ob[1] = sp34[1] + (D_80360090 + (sp2C + sp24 / 3))->unk08;
        sp20[sp24 + 1].v.ob[2] = sp34[2] + (D_80360090 + (sp2C + sp24 / 3))->unk0C;
        
        sp20[sp24 + 2] = sp3C[2];
        sp20[sp24 + 2].v.ob[0] = sp38[0] + (D_80360090 + (sp2C + sp24 / 3))->unk04;
        sp20[sp24 + 2].v.ob[1] = sp38[1] + (D_80360090 + (sp2C + sp24 / 3))->unk08;
        sp20[sp24 + 2].v.ob[2] = sp38[2] + (D_80360090 + (sp2C + sp24 / 3))->unk0C;
    }

    gSPVertex(sp28, VIRTUAL_TO_PHYSICAL(sp20), 15, 0);
}

void func_802E0B10(s32 sp38, s16 sp3E) {
    void **sp34;
    s16 sp32 = (D_80360090 + sp3E)->unk02;

    switch(sp38) {
        case 11:
            sp34 = (void **)segmented_to_virtual(&flower_bubbles_textures_ptr_0B002008);
            sp32 = (D_80360090 + sp3E)->unk02;
            break;

        case 12:
            sp34 = (void **)segmented_to_virtual(&lava_bubble_ptr_0B006020);
            sp32 = (D_80360090 + sp3E)->unk02;
            break;

        case 13:
        case 14:
            sp34 = (void **)segmented_to_virtual(&bubble_ptr_0B006848);
            sp32 = 0;
            break;
    }

    gDPSetTextureImage(D_803600C4++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, *(sp34 + sp32));
    gSPDisplayList(D_803600C4++, &tiny_bubble_dl_0B006D68);
}

Gfx *func_802E0CA8(s32 sp68, UNUSED Vec3s sp6C, Vec3s sp70, Vec3s sp74) {
    s32 sp64;
    s16 sp62, sp60, sp5E;
    UNUSED s16 sp5C;
    UNUSED s16 sp5A;
    s16 sp58;
    UNUSED s32 sp54;
    UNUSED s16 sp52;
    s16 sp50;
    UNUSED s32 sp4C;
    UNUSED s16 sp4A;
    s16 sp48;
    Gfx *sp44;
    
    sp44 = (Gfx *)alloc_display_list(((D_803600CC / 5) * 10 + D_803600CC + 3) * sizeof(Gfx));
    if (sp44 == NULL)
        return NULL;

    D_803600C4 = sp44;

    func_802DD204(sp74, sp70, &sp62, &sp60, &sp5E);
    func_802E0504(sp68, sp74, &sp58, &sp50, &sp48);
    func_802DE01C(&sp58, &sp50, &sp48, sp60, sp5E);

    gSPDisplayList(D_803600C4++, &tiny_bubble_dl_0B006D38);

    for (sp64 = 0; sp64 < D_803600CC; sp64 += 5) {
        gDPPipeSync(D_803600C4++);
        func_802E0B10(sp68, sp64);
        func_802E0708(D_803600C4++, sp64, &sp58, &sp50, &sp48, (Vtx *)D_80330698);
        gSP1Triangle(D_803600C4++, 0, 1, 2, 0);
        gSP1Triangle(D_803600C4++, 3, 4, 5, 0);
        gSP1Triangle(D_803600C4++, 6, 7, 8, 0);
        gSP1Triangle(D_803600C4++, 9, 10, 11, 0);
        gSP1Triangle(D_803600C4++, 12, 13, 14, 0);
    }

    gSPDisplayList(D_803600C4++, &tiny_bubble_dl_0B006AB0);
    gSPEndDisplayList(D_803600C4++);

    return sp44;
}

void func_802E0FC8(s32 a0) {
    switch (a0) {
        case 13:
            D_803600CC = D_803600B0[7];
            break;
        case 14:
            D_803600CC = D_803600B0[7];
            break;
    }
}

Gfx *func_802E1038(s32 sp28, Vec3s sp2C, Vec3s sp30, Vec3s sp34) {
    Gfx *sp24;

    if (D_80330640 == 0 && !func_802E0328(sp28))
        return NULL;

    func_802E0FC8(sp28);

    if (D_803600CC == 0)
        return NULL;

    switch (sp28) {
        case 11:
            sp24 = func_802E0CA8(11, sp2C, sp34, sp30);
            break;

        case 12:
            sp24 = func_802E0CA8(12, sp2C, sp34, sp30);
            break;

        case 13:
            sp24 = func_802E0CA8(13, sp2C, sp34, sp30);
            break;

        case 14:
            sp24 = func_802E0CA8(14, sp2C, sp34, sp30);
            break;

        default: 
            return NULL;
    }

    return sp24;
}
