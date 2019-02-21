#include <ultra64.h>
#include "something.h"
#include "playback.h"
#include "dma.h"
#include <unused.h>
#include "data.h"

#ifdef VERSION_JP
#define US_FLOAT(x) x
#else
#define US_FLOAT(x) x##f
#endif

#ifdef __GNUC__
#define GLOBAL_ASM(...)
#endif

#define FIX2(a, b) ((u32)a + (0x80000000 | b))

#ifdef NON_MATCHING
u64 *func_80314480(u16 *arg0, s32 arg1, u64 *arg2)
{
    s32 sp174;
    struct Struct_func_80318870 *s7;
    struct SubStruct_func_80318870_3 *sp164;
    u32 *sp160;
    u32 *sp15c;
    s32 t2; //150
    s32 t3; //14c
    s32 sp148; //audio flags?
    UNUSED u8 pad8[0x148 - 0x130 - 4];
    s32 sp130;
    UNUSED u8 pad7[0xc];
    s32 sp120;
    u32 t5; //108, definitely unsigned
    //UNUSED u8 pad6[4];
    s32 sp110;
    s32 t4; //10c
    //UNUSED u8 pad5[0x10c - 0xe8 - 4];
    s32 spe8;
    s32 spe4;
    u32 fp; //probably unsigned
    s32 t0;
    u32 a0;
    s32 spd8;
    s16 spd6;
    //UNUSED u8 pad3[0xd6 - 0x5c - 4];
    //s32 sp6c; pointer
    //struct
    //{
    u16 sp5c; 
    //u16 pad;
    s32 sp58;
    //} sp58;
    //s32 sp58;
    s32 sp54;
    s32 s6;
    s32 s2;
    s32 sp48;
    UNUSED u8 pad[16];

    UNUSED u8 pada[0x8];
    //s32 sp6c = 0; //incremented by 0xc0, ptr?
    s32 s0;
    //s32 s1;
    s32 s3;
    s32 s5;
    //s32 v0;
    u32 v1;
    u8 a3;
    void *v0_2;

    f32 f12;

    //u64 *arg2;

    //s4 is arg2

    //.ifdef VERSION_JP
    //  addiu $sp, $sp, -0x178
    //  lui   $t6, %hi(D_80226D70) # $t6, 0x8022
    //  lw    $t6, %lo(D_80226D70)($t6)
    //  sw    $s4, 0x30($sp)
    //  move  $s4, $a2
    //  sw    $ra, 0x44($sp)
    //  sw    $fp, 0x40($sp)
    //  sw    $s7, 0x3c($sp)
    //  sw    $s6, 0x38($sp)
    //  sw    $s5, 0x34($sp)
    //  sw    $s3, 0x2c($sp)
    //  sw    $s2, 0x28($sp)
    //  sw    $s1, 0x24($sp)
    //  sw    $s0, 0x20($sp)
    //  sw    $a0, arg0
    //  sw    $a1, arg1
    //  sw    $zero, 0x174($sp)
    //;
    //  blez  $t6, .L80314E64
    //   sw    $zero, 0x15c($sp)

    for (sp174 = 0, sp15c = 0; sp174 < D_80226D70; sp174++)
    {
        //  sw    $zero, 0x6c($sp)
        //  lui   $ra, 0x8000
        //.L803144D4:
        //  lui   $t8, %hi(D_80222A10) # $t8, 0x8022
        //  lw    $t8, %lo(D_80222A10)($t8)
        //  lw    $t7, 0x6c($sp)
        //  lui   $t9, %hi(D_802218D0)
        //  lui   $at, 0x100
        //  addu  $s7, $t7, $t8
        s7 = &D_80222A10[sp174];
        //  lbu   $v0, 7($s7)
        //  lw    $t8, 0x174($sp)
        //  addu  $t9, $t9, $v0
        //  lbu   $t9, %lo(D_802218D0)($t9)
        //  slti  $t6, $t9, 2
        //  beqz  $t6, .L8031451C
        //   sll   $t7, $v0, 8
        if ((D_802218D0[s7->unk7] < 2) != 0)
        {
            //  addu  $t9, $t7, $t8
            //  addu  $t6, $t9, $at
            //  lui    $at, %hi(D_80331D40)
            //  b     .L80314E3C
            //   sw    $t6, %lo(D_80331D40)($at)
            D_80331D40 = (s7->unk7 << 8) + sp174 + 0x1000000;
            continue;
        }
        //.L8031451C:
        //  lw    $t7, ($s7)
        //  srl   $t8, $t7, 0x1f
        //  beql  $t8, $zero, .L80314E40
        //   lw    $t6, 0x174($sp)
        if (s7->unk0b80 == 0)
            continue;

        //  lw    $t9, arg1
        //  sw    $zero, 0x148($sp)
        sp148 = 0;
        //  li    $at, 1
        //  sll   $t6, $t9, 1
        //  sw    $t6, 0x48($sp)
        sp48 = arg1 * 2;
        //  lw    $t7, ($s7)
        //  mtc1  $zero, $f4
        //  li    $t6, 1
        //  sll   $t8, $t7, 1
        //  srl   $t9, $t8, 0x1f
        //  bne   $t9, $at, .L80314568
        //   move  $a0, $s4
        if (s7->unk0b40 == 1)
        {
            //  sw    $t6, 0x148($sp)
            //  sw    $zero, 0x14($s7)
            //  sh    $zero, 0x20($s7)
            sp148 = 1;
            s7->unk14 = 0;
            s7->unk20 = 0;
        }
        //.L80314568:
        //  lwc1  $f2, 0x38($s7)
        //  li    $at, 0x40000000 # 2.000000
        //  mtc1  $at, $f5
        //  cvt.d.s $f0, $f2
        //  lui   $at, %hi(D_80337BC0)
        //  c.lt.d $f0, $f4
        //  move  $a1, $s7
        //  bc1f  .L803145C0
        //   nop

        if (s7->unk38 < US_FLOAT(2.0))
        {
            //  lui   $at, %hi(D_80337BB0)
            //  ldc1  $f6, %lo(D_80337BB0)($at)
            //  li    $t7, 1
            //  sw    $t7, 0xe8($sp)
            spe8 = 1;
            //  c.lt.d $f6, $f0
            //  lui    $at, %hi(D_80337BB8)
            //  bc1f  .L803145B8
            //   nop
            //s7->unk38 = MAX(s7->unk38, US_FLOAT(1.99996));
            if (s7->unk38 > US_FLOAT(1.99996))
            {
                //  lwc1  $f8, %lo(D_80337BB8)($at)
                //  swc1  $f8, 0x38($s7)
                s7->unk38 = US_FLOAT(1.99996);
                //  lwc1  $f2, 0x38($s7)
            }
            //.L803145B8:
            //  b     .L80314604
            //   mov.s $f12, $f2
            f12 = s7->unk38;
        }
        else
        {
            //.L803145C0:
            //  ldc1  $f10, %lo(D_80337BC0)($at)
            //  li    $t8, 2
            //  mtc1  $zero, $f4
            //  c.le.d $f10, $f0
            //  sw    $t8, 0xe8($sp)
            spe8 = 2;
            //  lui   $at, %hi(D_80337BC8)
            //  bc1fl .L803145F4
            //   lui   $at, 0x3fe0
            //s7->unk38 = MIN(s7->unk38, US_FLOAT(3.99993));
            if (s7->unk38 >= US_FLOAT(3.99993))
            {
                //  lwc1  $f16, %lo(D_80337BC8)($at)
                //  swc1  $f16, 0x38($s7)
                s7->unk38 = US_FLOAT(3.99993);
                //  lwc1  $f18, 0x38($s7)
                //  cvt.d.s $f0, $f18
                //  li    $at, 0x3FE00000 # 1.750000
            }
            //.L803145F4:
            //  mtc1  $at, $f5
            //  nop
            //  mul.d $f6, $f0, $f4
            //  cvt.s.d $f12, $f6
            f12 = s7->unk38 * US_FLOAT(.5);
        }
        //.L80314604:
        //  li    $at, 0x47000000 # 32768.000000
        //  mtc1  $at, $f8
        //  lw    $t8, arg1
        //  mul.s $f10, $f12, $f8
        //  trunc.w.s $f16, $f10
        //  mfc1  $t6, $f16
        //  nop
        //  andi  $t7, $t6, 0xffff
        //  multu $t7, $t8
        //  sw    $t7, 0x5c($sp)

        sp5c = (s16)(f12 * 32768.0f);
        //  lhu   $t7, 0x20($s7)
        //  lw    $v0, 0x24($s7)
        //  mflo  $t9
        //  sll   $t6, $t9, 1
        //  addu  $v1, $t7, $t6
        //  bnez  $v0, .L8031467C
        //   sh    $v1, 0x20($s7)
        v1 = (s7->unk20) + ((sp5c * arg1) * 2);
        s7->unk20 = v1;

        if (s7->unk24 == 0)
        {
            //u32 s0;
            //s0 = v1 >> 0x10;
            //  srl   $s0, $v1, 0x10
            //  move  $a2, $s0
            //  jal   func_80314F08
            //   sw    $zero, 0x148($sp)
            sp148 = 0;
            arg2 = func_80314F08(arg2, s7, v1 >> 0x10);
            //  lw    $t1, 0x14($s7)
            //  move  $s4, $v0
            //  sll   $t9, $t1, 1
            //  addiu $t7, $t9, 0x180
            //  sh    $t7, 0xd6($sp)
            spd6 = (s7->unk14 << 1) + 0x180;
            //  addu  $t6, $t1, $s0
            //  sw    $t6, 0x14($s7)
            s7->unk14 = s7->unk14 + (v1 >> 0x10);
            //  b     .L80314D5C
            break;

            //   lw    $a1, ($s7)
        }
        else
        {
            //.L8031467C:
            //  lw    $a2, ($v0)
            //  srl   $v0, $v1, 0x10
            sp58 = v1 >> 0x10;
            //  lw    $t8, 8($a2)
            //  sw    $t8, 0x160($sp)
            sp160 = s7->unk24->unk00.unk08;
            //  lw    $t7, 4($t8)
            //  lw    $t8, 0xe8($sp)
            //  sw    $t7, 0x110($sp)
            sp110 = s7->unk24->unk00.unk04;
            //  lw    $t6, 4($a2)
            //  sw    $zero, 0xd8($sp)
            //  sw    $zero, 0xe4($sp)
            spd8 = 0;
            //  blez  $t8, .L80314D54
            //   sw    $t6, 0x120($sp)

            //these are probably constant expressions?
            for (spe4 = 0; spe4 < spe8; spe4++)
            //  xori  $t9, $t8, 1
            //  sltiu $t9, $t9, 1
            //  sw    $t9, 0x54($sp)
            //  sw    $v0, 0x58($sp)
            //  sw    $a2, 0x164($sp)
            //  lw    $a2, 0x164($sp)
            {
                sp54 = (spe8 == 1);
                sp164 = s7->unk24;

                //.L803146C4:
                //  lw    $t7, 0x54($sp)
                //  lw    $v0, 0x58($sp)
                //  lw    $a0, 0xc($a2)
                //  move  $fp, $zero
                fp = 0;
                //  move  $s5, $zero
                s5 = 0;
                //  beqz  $t7, .L803146E8
                //   addiu $a1, $a0, 8
                if (sp54 != 0)
                {
                    //  b     .L80314710
                    //   move  $t5, $v0
                    t5 = sp58;
                }
                //.L803146E8:
                //  andi  $t6, $v0, 1
                //  beqz  $t6, .L8031470C
                //   sw    $a2, 0x164($sp)
                else if (sp58 & 1)
                {
                    //  lw    $t9, 0xe4($sp)
                    //  li    $at, -2
                    //  and   $t8, $v0, $at
                    //  sll   $t7, $t9, 1
                    //  b     .L80314710
                    //   addu  $t5, $t8, $t7
                    t5 = (sp58 & ~1) + (spe4 << 1);
                }
                else
                {
                    //.L8031470C:
                    //  move  $t5, $v0
                    t5 = sp58;
                }
                //.L80314710:
                //  lw    $t6, 0x15c($sp)
                //  sw    $v0, 0x58($sp)
                //  beq   $t6, $a1, .L80314764
                //   nop
                if ((u32)sp15c != (u32)&sp164->unk0c[2])
                {
                    //  sw    $a1, 0x15c($sp)
                    sp15c = &sp164->unk0c[2];
                    //  lw    $t8, ($a0)
                    //  lw    $t9, 4($a0)
                    //  lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
                    //  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
                    //  multu $t9, $t8
                    //  move  $v0, $s4
                    //  addiu $s4, $s4, 8
                    //  mflo  $v1
                    //v1 = ;
                    //  sll   $t7, $v1, 4
                    //  and   $t6, $t7, $at
                    //  lui   $at, 0xb00
                    //  or    $t9, $t6, $at
                    //  sw    $t9, ($v0)
                    //  lw    $t8, 0x15c($sp)
                    //  addu  $t7, $t8, $ra
                    //  sw    $t7, 4($v0)
                    aLoadADPCM(arg2++, (sp164->unk0c[0] * sp164->unk0c[1]) << 4, FIX(sp15c));
                }
                //.L80314764:
                //  beqz  $t5, .L80314B6C
                //   lw    $v0, 0x58($sp)
                //  sw    $v0, 0x58($sp)
                //  lw    $t1, 0x14($s7)
                while (t5 > fp)
                {
                    u32 v1;
                    s32 s0;
                    //.L80314774:
                    //  lw    $t6, 0x110($sp)
                    //  subu  $a0, $t5, $fp
                    a0 = t5 - fp;
                    //  andi  $s2, $t1, 0xf
                    s2 = s7->unk14 & 0xf;
                    //  move  $t2, $zero
                    t2 = 0;
                    //  move  $t3, $zero
                    t3 = 0;
                    //  move  $t4, $a0
                    t4 = a0;
                    v1 = sp110 - s7->unk14;
                    //  bnez  $s2, .L803147A8
                    //   subu  $v1, $t6, $t1

                    if (s2 == 0 && s7->unk0b20)
                    {
                        //  lw    $t9, ($s7)
                        //  sll   $t7, $t9, 2
                        //  bltzl $t7, .L803147AC
                        //   li    $t6, 16
                        //  li    $s2, 16
                        s2 = 16;
                    }
                    //.L803147A8:
                    //  li    $t6, 16

                    //.L803147AC:
                    //  subu  $a1, $t6, $s2
                    //  slt   $at, $a0, $v1
                    //  beqz  $at, .L803147E8
                    //   move  $s6, $a1
                    s6 = 16 - s2;
                    if (a0 < v1)
                    {
                        //  subu  $v0, $a0, $a1
                        //v0 = a0 - (16 - s2) + 0xf;
                        //  addiu $v0, $v0, 0xf
                        //  bgez  $v0, .L803147D4
                        //   sra   $t9, $v0, 4
                        //  addiu $at, $v0, 0xf
                        //  sra   $t9, $at, 4
                        //.L803147D4:
                        //  sll   $s0, $t9, 4
                        //  addu  $t8, $a1, $s0
                        //  move  $t0, $t9
                        s0 = ((a0 - (16 - s2) + 0xf) / (16)) * 16;
                        t0 = ((a0 - (16 - s2) + 0xf) / (16));
                        //  b     .L80314834
                        //   subu  $s3, $t8, $a0
                        s3 = (16 - s2) + s0 - a0;
                    }
                    else
                    {
                        //.L803147E8:
                        //  addu  $v0, $v1, $s2
                        //v0 = v1 + s2;
                        //  addiu $s0, $v0, -0x10
                        s0 = v1 + s2 - 0x10;
                        s3 = 0;
                        if (s0 < 0)
                        {
                            //  bgtz  $s0, .L80314800
                            //   move  $s3, $zero
                            //  move  $s0, $zero
                            //  move  $s6, $v1
                            s0 = 0;
                            s6 = v1;
                        }
                        //.L80314800:
                        //  lw    $t6, 0x160($sp)
                        //  addiu $t0, $s0, 0xf

                        //  bgez  $t0, .L80314818
                        //   sra   $t7, $t0, 4
                        //  addiu $at, $t0, 0xf
                        //  sra   $t7, $at, 4
                        //.L80314818:
                        //  lw    $t9, 8($t6)
                        //  move  $t0, $t7
                        t0 = (s0 + 0xf) / (1 << 4);
                        //  beql  $t9, $zero, .L80314834
                        //   li    $t2, 1
                        //  b     .L80314834
                        //   li    $t3, 1
                        //  li    $t2, 1
                        t2 = 1;
                        t3 = 1;
                    }
                    //.L80314834:
                    //  beqz  $t0, .L803148F8
                    //   li    $v1, 9
                    //v1 = 9;
                    if (t0 != 0)
                    {
                        //  subu  $v0, $t1, $s2
                        //  addiu $v0, $v0, 0x10
                        //  bgez  $v0, .L80314854
                        //   sra   $t8, $v0, 4
                        //  addiu $at, $v0, 0xf
                        //  sra   $t8, $at, 4
                        //.L80314854:
                        //  multu $t8, $v1
                        //  lw    $t6, 0x120($sp)
                        //  lw    $a2, 0x148($sp)
                        //  addiu $a3, $s7, 3

                        //  sw    $t2, 0x150($sp)
                        //  sw    $t3, 0x14c($sp)
                        //  sw    $t4, 0x10c($sp)
                        //  sw    $t5, 0x118($sp)

                        //  mflo  $t7
                        //  addu  $a0, $t7, $t6
                        //  nop
                        //  multu $t0, $v1
                        //  mflo  $s1
                        //s1 = t0 * 9;
                        //  move  $a1, $s1
                        //  jal   func_80317270
                        //   nop
                        v0_2 = func_80317270(((s7->unk14 - s2 + 0x10) / (16)) * 9 + sp120, t0 * 9, sp148, &(s7->unk3));
                        a3 = (u32)v0_2 & 0xf;
                        //  andi  $a3, $v0, 0xf
                        //  move  $a0, $s4
                        //  lui   $t9, (0x080003F0 >> 16) # lui $t9, 0x800
                        //  lw    $t2, 0x150($sp)
                        //  lw    $t3, 0x14c($sp)
                        //  lw    $t4, 0x10c($sp)
                        //  lw    $t5, 0x118($sp)
                        //  ori   $t9, (0x080003F0 & 0xFFFF) # ori $t9, $t9, 0x3f0
                        //  addu  $t8, $s1, $a3
                        //  andi  $t7, $t8, 0xffff
                        //  sw    $t9, ($a0)
                        //  addiu $s4, $s4, 8
                        //  lui   $ra, 0x8000
                        //  sw    $t7, 4($a0)
                        aSetLoadBuffer(arg2++, 0, 0x3f0, 0, t0 * 9 + a3, FIX((u32)v0_2 - a3));
                        //aLoadBuffer(arg2++, FIX((u32)v0_2 - a3));
                        //  move  $a1, $s4
                        //  subu  $t9, $v0, $a3
                        //  addu  $t8, $t9, $ra
                        //  lui   $t6, 0x400
                        //  sw    $t6, ($a1)
                        //  sw    $t8, 4($a1)
                        //aLoadBuffer(arg2++, FIX((u32)v0_2 - a3));
                        //  lw    $a2, ($s7)
                        //  addiu $s4, $s4, 8
                        //  sll   $t7, $a2, 2
                        //  b     .L8031490C
                        //   srl   $a2, $t7, 0x1f
                    }
                    else
                    {
                        //.L803148F8:
                        //  lw    $a2, ($s7)
                        //  move  $s0, $zero
                        //  move  $a3, $zero
                        s0 = 0;
                        a3 = 0;
                        //  sll   $t9, $a2, 2
                        //  srl   $a2, $t9, 0x1f
                    }
                    //.L8031490C:
                    //  beqz  $a2, .L8031494C
                    //   move  $v0, $s4
                    if (s7->unk0b20 != 0)
                    {
                        //  lui   $t7, 0xf00
                        //  sw    $t7, ($v0)
                        //  lw    $t6, 0x164($sp)
                        //  lui   $at, (0x80000010 >> 16) # lui $at, 0x8000
                        //  ori   $at, (0x80000010 & 0xFFFF) # ori $at, $at, 0x10
                        //  lw    $t9, 8($t6)
                        //  li    $t7, 2
                        //  addiu $s4, $s4, 8
                        //  addu  $t8, $t9, $at
                        //  sw    $t8, 4($v0)
                        aSetLoop(arg2++, FIX(sp164->unk08[0x10]));
                        //  sw    $t7, 0x148($sp)
                        sp148 = 2;//loop, out or left?
                        //  lbu   $t6, ($s7)
                        //  andi  $t9, $t6, 0xffdf
                        //  sb    $t9, ($s7)
                        s7->unk0b20 = 0;
                    }
                    //.L8031494C:
                    //  bnez  $fp, .L803149BC
                    //   move  $v0, $s4
                    if (fp == 0)
                    {
                        //  addiu $t8, $a3, 0x3f0
                        //  andi  $t7, $t8, 0xffff
                        //  lui   $at, 0x800
                        //  or    $t6, $t7, $at
                        //  sll   $a2, $s0, 1
                        //  andi  $t9, $a2, 0xffff
                        //  lui   $at, 0x180
                        //  move  $v0, $s4
                        //  or    $t8, $t9, $at
                        //  sw    $t8, 4($v0)
                        //  sw    $t6, ($v0)
                        aSetBuffer(arg2++, 0, a3 + 0x3f0, 0x180, s0 << 1);
                        //  lw    $t7, 0x148($sp)
                        //  addiu $s4, $s4, 8
                        //  lui   $at, 0x100
                        //  andi  $t6, $t7, 0xff
                        //  sll   $t9, $t6, 0x10
                        //  or    $t8, $t9, $at
                        //  move  $v1, $s4
                        //  sw    $t8, ($v1)
                        //  lw    $t7, 0x34($s7)
                        //  sll   $t9, $s2, 1
                        //  addiu $s4, $s4, 8
                        //  addu  $t6, $t7, $ra
                        //  sw    $t6, 4($v1)
                        aADPCMdec(arg2++, sp148, FIX(s7->unk34->unk00));
                        //  b     .L80314A74
                        //   sw    $t9, 0x130($sp)
                        sp130 = s2 << 1;
                    }
                    else
                    {
                        //.L803149BC:
                        //  addiu $t8, $a3, 0x3f0
                        //  andi  $t7, $t8, 0xffff
                        //  lui   $at, 0x800
                        //  or    $t6, $t7, $at
                        //  li    $at, -32
                        //  addiu $v1, $s5, 0x1f
                        //  and   $t9, $v1, $at
                        //  addiu $t7, $t9, 0x180
                        //  move  $v1, $t9
                        //  sw    $t6, ($v0)
                        //  sll   $a2, $s0, 1
                        //  andi  $t9, $a2, 0xffff
                        //  sll   $t6, $t7, 0x10
                        //  or    $t8, $t6, $t9
                        //  sw    $t8, 4($v0)
                        aSetBuffer(arg2++, 0, 0x3f0, ALIGN(s5, 5), s0 << 1); //(s5+0x1f)&~0x1f
                        //  lw    $t7, 0x148($sp)
                        //  addiu $s4, $s4, 8
                        //  lui   $at, 0x100
                        //  andi  $t6, $t7, 0xff
                        //  sll   $t9, $t6, 0x10
                        //  or    $t8, $t9, $at
                        //  move  $a0, $s4
                        //  sw    $t8, ($a0)
                        //  lw    $t7, 0x34($s7)
                        //  sll   $t9, $s2, 1
                        //  addu  $t8, $v1, $t9
                        //  addu  $t6, $t7, $ra
                        //  lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
                        //  sw    $t6, 4($a0)
                        aADPCMdec(arg2++, sp148, FIX(s7->unk34->unk00));
                        //  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
                        //  addiu $t7, $t8, 0x180
                        //  and   $t6, $t7, $at
                        //  addiu $s4, $s4, 8
                        //  lui   $at, 0xa00
                        //  or    $t9, $t6, $at
                        //  move  $a1, $s4
                        //  sw    $t9, ($a1)
                        //  addu  $t9, $s0, $s6
                        //  addiu $t7, $s5, 0x180
                        //  sll   $t6, $t7, 0x10
                        //  subu  $t8, $t9, $s3
                        //  sll   $t7, $t8, 1
                        //  andi  $t9, $t7, 0xffff
                        //  or    $t8, $t6, $t9
                        //  sw    $t8, 4($a1)
                        aDMEMMove(arg2++, ALIGN(s5, 5) + (s2 << 1) + 0x180, s5 + 0x180, (s0 + s6 + s3) << 1);
                        //  addiu $s4, $s4, 8
                    }
                    //.L80314A74:
                    //  lw    $t9, 0x148($sp)
                    //  addu  $t7, $fp, $s0
                    //  addu  $t6, $t7, $s6
                    //  li    $at, 1
                    //  beq   $t9, $at, .L80314AA8
                    //   subu  $fp, $t6, $s3
                    fp = fp + s0 + s6 - s3;
                    //  xori  $v0, $t9, 2
                    //  addu  $t8, $s0, $s6
                    //  subu  $v1, $t8, $s3
                    //  beqz  $v0, .L80314AB8
                    //   sw    $zero, 0x148($sp)
                    //  b     .L80314AC4
                    //   sll   $t6, $v1, 1
                    switch (sp148)
                    {
                    case 1: //init
                        //.L80314AA8:
                        //  sw    $zero, 0x130($sp)
                        //  addu  $s5, $s5, $a2
                        //  b     .L80314AE0
                        //   sw    $zero, 0x148($sp)
                        sp130 = 0;
                        s5 += s0 << 1;
                        sp148 = 0;
                        break;
                    case 2: //loop, out, left?
                        sp148 = 0;
                        //#define v1_2 (s0 + s6 - s3)
                        //.L80314AB8:
                        //  sll   $t7, $v1, 1
                        //  b     .L80314AE0
                        //   addu  $s5, $s5, $t7
                        s5 += (s0 + s6 - s3) << 1;
                        break;
                    default:
                        sp148 = 0;
                        //v1 = s0 + s6 - s3;
                        //.L80314AC4:
                        //  beql  $s5, $zero, .L80314AD8
                        //   addu  $s5, $v1, $s2
                        if (s5 != 0)
                        {
                            //  b     .L80314AE0
                            //   addu  $s5, $s5, $t6
                            s5 = (s0 + s6 - s3) + s2 + ((s0 + s6 - s3) << 1);
                            //  addu  $s5, $v1, $s2
                        }
                        else
                        {
                            //.L80314AD8:
                            //  sll   $t9, $s5, 1
                            //  move  $s5, $t9
                            s5 = (s0 + s6 - s3) + s2 + 1;
                        }
                        break;
                    }
                    //#undef v1_2
                    //.L80314AE0:
                    //  beqz  $t2, .L80314B34
                    //   lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
                    if (t2)
                    {
                        //  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
                        //  addiu $t8, $s5, 0x180
                        //  and   $t7, $t8, $at
                        //  lui   $at, 0x200
                        //  move  $v0, $s4
                        //  subu  $t9, $t5, $fp
                        //  sll   $t8, $t9, 1
                        //  or    $t6, $t7, $at
                        //  sw    $t6, ($v0)
                        //  sw    $t8, 4($v0)
                        aClearBuffer(arg2++, s5 + 0x180, (t5 - fp) << 1);
                        //  lbu   $t6, ($s7)
                        //  addiu $s4, $s4, 8
                        //  sw    $zero, 0x14($s7)
                        s7->unk14 = 0;
                        //  ori   $t9, $t6, 0x10
                        //  sb    $t9, ($s7)
                        s7->unk0b10 = 1;
                        //  lbu   $t8, ($s7)
                        //  andi  $t7, $t8, 0xff7f
                        //  b     .L80314B6C
                        //   sb    $t7, ($s7)
                        s7->unk0b80 = 0;
                        break; //?
                    }
                    //.L80314B34:
                    //  beql  $t3, $zero, .L80314B5C
                    //   lw    $t9, 0x14($s7)
                    if (!t3)
                    {
                        //  lbu   $t9, ($s7)
                        //  ori   $t8, $t9, 0x20
                        //  sb    $t8, ($s7)
                        s7->unk0b20 = 1;
                        //  lw    $t7, 0x160($sp)
                        //  lw    $t6, ($t7)
                        //  b     .L80314B64
                        //   sw    $t6, 0x14($s7)
                        s7->unk14 = *sp160;
                        //  lw    $t9, 0x14($s7)
                    }
                    else
                    {
                        //.L80314B5C:
                        //  addu  $t8, $t9, $t4
                        //  sw    $t8, 0x14($s7)
                        s7->unk14 += t4;
                    }
                    //.L80314B64:
                    //  bnel  $fp, $t5, .L80314774
                    //   lw    $t1, 0x14($s7)
                }
                //.L80314B6C:
                //  lw    $t7, 0x54($sp)
                //  lw    $t6, 0xe8($sp)
                //  li    $at, 2
                //  bnez  $t7, .L80314B9C
                //   lw    $t8, 0x130($sp)
                if (sp54 == 0 || spe8 == 2)
                {
                    //  beq   $t6, $at, .L80314BB8
                    //   lw    $t9, 0xe4($sp)
                    //  lw    $a1, ($s7)
                    //  sll   $a2, $a1, 3
                    //  srl   $t9, $a2, 0x1f
                    //  b     .L80314D30
                    //   move  $a2, $t9
                    //.L80314B9C:
                    //  addiu $t7, $t8, 0x180
                    //  sh    $t7, 0xd6($sp)
                    spd6 = sp130 + 0x180;
                    //  lw    $a1, ($s7)
                    //  sll   $a2, $a1, 3
                    //  srl   $t6, $a2, 0x1f
                    //  b     .L80314D30
                    //   move  $a2, $t6
                }
                else
                {
                    //.L80314BB8:
                    //  beqz  $t9, .L80314BE0
                    //   move  $v0, $s4
                    if (spe4 != 0 && spe4 != 1)
                    {
                        //  li    $at, 1
                        //  beq   $t9, $at, .L80314C98
                        //   move  $v0, $s4
                        //  lw    $a1, ($s7)
                        //  sll   $a2, $a1, 3
                        //  srl   $t8, $a2, 0x1f
                        //  b     .L80314D30
                        //   move  $a2, $t8
                        //.L80314BE0:
                        //  lw    $t7, 0x130($sp)
                        //  lui   $at, 0x800
                        //  addiu $v1, $t5, 4
                        //  addiu $t6, $t7, 0x180
                        //  andi  $t9, $t6, 0xffff
                        //  or    $t8, $t9, $at
                        //  lui   $at, 0x20
                        //  andi  $t7, $v1, 0xffff
                        //  or    $t6, $t7, $at
                        //  addiu $s4, $s4, 8
                        //  lui   $t9, (0x0501FF60 >> 16) # lui $t9, 0x501
                        //  sw    $t6, 4($v0)
                        //  sw    $t8, ($v0)
                        aSetBuffer(arg2++, 0, sp130 + 0x180, 0x20, t5 + 4);
                        //  ori   $t9, (0x0501FF60 & 0xFFFF) # ori $t9, $t9, 0xff60
                        //  move  $a0, $s4
                        //  sw    $t9, ($a0)
                        //  lw    $t8, 0x34($s7)
                        //  lui   $at, (0x800000F0 >> 16) # lui $at, 0x8000
                        //  ori   $at, (0x800000F0 & 0xFFFF) # ori $at, $at, 0xf0
                        //  addu  $t7, $t8, $at
                        //  sw    $t7, 4($a0)
                        aResample(arg2++, 0x1, 0xff60, FIX(s7->unk34->unkf0));
                        //  li    $t6, 36
                        //  sw    $v1, 0xd8($sp)
                        spd8 = t5 + 4;
                        //  sh    $t6, 0xd6($sp)
                        spd6 = 36;
                        //  lw    $a1, ($s7)
                        //  addiu $s4, $s4, 8
                        //  move  $v0, $s4
                        //  sll   $a2, $a1, 3
                        //  srl   $t9, $a2, 0x1f
                        //  beqz  $t9, .L80314D30
                        //   move  $a2, $t9
                        if (s7->unk0b20 != 0)
                        {
                            //  lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
                            //  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
                            //  addiu $t8, $t5, 0x24
                            //  and   $t7, $t8, $at
                            //  lui   $at, 0x200
                            //  or    $t6, $t7, $at
                            //  addiu $t9, $t5, 0x10
                            //  sw    $t9, 4($v0)
                            //  sw    $t6, ($v0)
                            aClearBuffer(arg2++, t5 + 0x24, t5 + 0x10);
                            //  lw    $a1, ($s7)
                            //  addiu $s4, $s4, 8
                            //  sll   $a2, $a1, 3
                            //  srl   $t8, $a2, 0x1f
                            //  b     .L80314D30
                            //   move  $a2, $t8
                        }
                    }
                    else
                    {
                        //.L80314C98:
                        //  lw    $t7, 0x130($sp)
                        //  lui   $at, 0x800
                        //  addiu $s4, $s4, 8
                        //  addiu $t6, $t7, 0x180
                        //  andi  $t9, $t6, 0xffff
                        //  or    $t8, $t9, $at
                        //  addiu $t7, $t5, 8
                        //  andi  $t6, $t7, 0xffff
                        //  sw    $t8, ($v0)
                        //  lui   $at, 0x160
                        //  or    $t9, $t6, $at
                        //  lui   $t8, (0x0501FF60 >> 16) # lui $t8, 0x501
                        //  sw    $t9, 4($v0)
                        aSetBuffer(arg2++, 0, sp130 + 0x180, 0x160, t5 + 8);
                        //  ori   $t8, (0x0501FF60 & 0xFFFF) # ori $t8, $t8, 0xff60
                        //  move  $v1, $s4
                        //  sw    $t8, ($v1)
                        //  lw    $t7, 0x34($s7)
                        //  lui   $at, (0x800000F0 >> 16) # lui $at, 0x8000
                        //  ori   $at, (0x800000F0 & 0xFFFF) # ori $at, $at, 0xf0
                        //  addiu $s4, $s4, 8
                        //  lui   $t9, (0x0A000164 >> 16) # lui $t9, 0xa00
                        //  addu  $t6, $t7, $at
                        //  sw    $t6, 4($v1)
                        aResample(arg2++, 0x1, 0xff60, FIX(s7->unk34->unkf0));
                        //  ori   $t9, (0x0A000164 & 0xFFFF) # ori $t9, $t9, 0x164
                        //  move  $a0, $s4
                        //  sw    $t9, ($a0)
                        //  lw    $t8, 0xd8($sp)
                        //  addiu $s4, $s4, 8
                        //  addiu $t6, $t8, 0x20
                        //  addiu $t8, $t5, 4
                        //  andi  $t7, $t8, 0xffff
                        //  sll   $t9, $t6, 0x10
                        //  or    $t6, $t9, $t7
                        //  sw    $t6, 4($a0)
                        aDMEMMove(arg2++, 0x164, spd8 + 0x20, t5 + 4);
                        //  lw    $a1, ($s7)
                        //  sll   $a2, $a1, 3
                        //  srl   $t8, $a2, 0x1f
                        //  move  $a2, $t8
                    }
                }
                //.L80314D30:
                //  beqz  $a2, .L80314D40
                //   lw    $v0, 0xe4($sp)
                if (s7->unk0b10 != 0)
                    break;
            }
            //  b     .L80314D5C
            //   sw    $zero, 0x148($sp)
            //.L80314D40:
            //  lw    $t9, 0xe8($sp)
            //  addiu $v0, $v0, 1
            //  sw    $v0, 0xe4($sp)
            //  bnel  $v0, $t9, .L803146C4
            //   lw    $a2, 0x164($sp)

            sp148 = 0;
            //.L80314D54:
            //  sw    $zero, 0x148($sp)
            //  lw    $a1, ($s7)
        }
        //.L80314D5C:
        //  sll   $t7, $a1, 1
        //  srl   $t6, $t7, 0x1f
        //  li    $at, 1
        //  bne   $t6, $at, .L80314D84
        //   move  $a0, $s4
        if (s7->unk0b40 == 1)
        {
            //  li    $t8, 1
            //  sw    $t8, 0x148($sp)
            sp148 = 1;
            //  lbu   $t9, ($s7)
            //  andi  $t7, $t9, 0xffbf
            //  sb    $t7, ($s7)
            s7->unk0b40 = 0;
        }
        //.L80314D84:
        //  lw    $s1, 0x48($sp)
        //  lhu   $t6, 0xd6($sp)
        //  lw    $t8, 0x148($sp)
        //  move  $a1, $s7
        //  lhu   $a3, 0x5e($sp)
        //  move  $a2, $s1
        //  sw    $t6, 0x10($sp)
        //  jal   func_80314FD4
        //   sw    $t8, 0x14($sp)
        //(u64 *arg0, struct Struct_func_80318870 *arg1, s32 arg2, u16 arg3, u16 arg4, u32 arg5)
        arg2 = func_80314FD4(arg2, s7, sp48, sp5c, spd6, sp148);
        //  lhu   $t9, 0xc($s7)
        //  move  $s4, $v0
        //  move  $a0, $s4
        //  bnez  $t9, .L80314DC8
        //   move  $a1, $s7

        //  lhu   $t7, 0x10($s7)
        //  beql  $t7, $zero, .L80314DD4
        //   lhu   $t6, 0xe($s7)
        if (s7->unkC == 0 || s7->unk10 == 0)
        {
            //.L80314DC8:
            //  b     .L80314DF4
            //   li    $s0, 1
            s0 = 1;
            //  lhu   $t6, 0xe($s7)
        }
        else if (s7->unkE == 0)
        {

            //.L80314DD4:
            //  bnez  $t6, .L80314DEC
            //   nop
            //  lhu   $t8, 0x12($s7)
            //  move  $s0, $zero
            s0 = 0;
            //  beqz  $t8, .L80314DF4
            //   nop
            //.L80314DEC:
            //  b     .L80314DF4
            //   li    $s0, 2
        }
        else if (s7->unk12 == 0)
        {
            s0 = 2;
        }

        //.L80314DF4:
        //  lw    $t9, 0x148($sp)
        //  lw    $a2, arg1
        //  move  $a3, $zero
        //  sw    $s0, 0x10($sp)
        //  jal   func_80315030
        //   sw    $t9, 0x14($sp)
        arg2 = func_80315030(arg2, s7, arg1, 0, s0, sp148);
        //  lbu   $t7, 1($s7)
        //  lui   $ra, 0x8000
        //  move  $s4, $v0
        //  beqz  $t7, .L80314E3C
        //   move  $a0, $v0
        if (s7->unk1)
        {
            //  move  $a1, $s7
            //  move  $a2, $s1
            //  lw    $a3, 0x148($sp)
            //  jal   func_803155F4
            //   sw    $s0, 0x10($sp)
            arg2 = func_803155F4(arg2, s7, sp48, sp148, s0);
            //  lui   $ra, 0x8000
            //  move  $s4, $v0
        }

        //.L80314E3C:
        //  lw    $t6, 0x174($sp)
        //.L80314E40:
        //  lw    $t9, 0x6c($sp)
        //  addiu $t8, $t6, 1
        //  lui   $t6, %hi(D_80226D70) # $t6, 0x8022
        //  lw    $t6, %lo(D_80226D70)($t6)
        //  addiu $t7, $t9, 0xc0
        //  sw    $t7, 0x6c($sp)
        //  slt   $at, $t8, $t6
        //  bnez  $at, .L803144D4
        //   sw    $t8, 0x174($sp)
    }

    //.L80314E64:
    //  lui   $t0, 0x800
    //  move  $a0, $s4
    //  sw    $t0, ($a0)
    //  lw    $v1, arg1
    //  addiu $s4, $s4, 8
    //  move  $a1, $s4
    //  sll   $t9, $v1, 1
    //  andi  $t7, $t9, 0xffff
    //  sw    $t7, 4($a0)
    aSetBuffer(arg2++, 0, 0, 0, arg1 << 1);
    //  addiu $s4, $s4, 8
    //  lui   $t8, 0xd00
    //  lui   $t6, (0x04C00600 >> 16) # lui $t6, 0x4c0
    //  ori   $t6, (0x04C00600 & 0xFFFF) # ori $t6, $t6, 0x600
    //  sw    $t8, ($a1)
    //  move  $a2, $s4
    //  sw    $t6, 4($a1)
    aInterleave(arg2++, 0x4c0, 0x600);
    //  sll   $t9, $t9, 1
    //  andi  $t7, $t9, 0xffff
    //  addiu $s4, $s4, 8
    //  sw    $t7, 4($a2)
    //  sw    $t0, ($a2)
    aSetBuffer(arg2++, 0, 0, 0, arg1 << 2);
    //  move  $a3, $s4
    //  lui   $t8, 0x600
    //  sw    $t8, ($a3)
    //  lw    $t6, arg0
    //  lui   $ra, 0x8000
    //  addiu $v0, $s4, 8
    //  addu  $t9, $t6, $ra
    //  sw    $t9, 4($a3)
    aSaveBuffer(arg2++, FIX(arg0));
    //  lw    $ra, 0x44($sp)
    //  lw    $fp, 0x40($sp)
    //  lw    $s7, 0x3c($sp)
    //  lw    $s6, 0x38($sp)
    //  lw    $s5, 0x34($sp)
    //  lw    $s4, 0x30($sp)
    //  lw    $s3, 0x2c($sp)
    //  lw    $s2, 0x28($sp)
    //  lw    $s1, 0x24($sp)
    //  lw    $s0, 0x20($sp)
    //  jr    $ra
    //   addiu $sp, $sp, 0x178
    *arg2++ = 0;
    *arg2++ = 0;
    *arg2++ = 0;
    *arg2++ = 0;
    *arg2++ = 0;
    *arg2++ = 0;
    *arg2++ = 0;
    *arg2++ = 0;
    *arg2++ = 0;
    *arg2++ = 0;
    *arg2++ = 0;
    *arg2++ = 0;
    *arg2++ = 0;
    *arg2++ = 0;
    *arg2++ = 0;
    *arg2++ = 0;
    //*arg2++ = 0;
    //*arg2++ = 0;
    //*((u32 *)arg2++) = 0;
    return arg2;
    //.else
    //  addiu $sp, $sp, -0x170
    //  lui   $t6, %hi(D_80226D70) # $t6, 0x8022
    //  lw    $t6, %lo(D_80226D70)($t6)
    //  sw    $s4, 0x30($sp)
    //  move  $s4, $a2
    //  sw    $ra, 0x44($sp)
    //  sw    $fp, 0x40($sp)
    //  sw    $s7, 0x3c($sp)
    //  sw    $s6, 0x38($sp)
    //  sw    $s5, 0x34($sp)
    //  sw    $s3, 0x2c($sp)
    //  sw    $s2, 0x28($sp)
    //  sw    $s1, 0x24($sp)
    //  sw    $s0, 0x20($sp)
    //  sw    $a0, 0x170($sp)
    //  sw    $a1, 0x174($sp)
    //  sw    $zero, 0x16c($sp)
    //  blez  $t6, .L_US_80315F6C
    //   sw    $zero, 0x154($sp)
    //  sw    $zero, 0x64($sp)
    //.L_US_803155E0:
    //  lui   $t8, %hi(D_80222A10) # $t8, 0x8022
    //  lw    $t8, %lo(D_80222A10)($t8)
    //  lw    $t7, 0x64($sp)
    //  addu  $s7, $t7, $t8
    //  lw    $t9, ($s7)
    //  srl   $t6, $t9, 0x1f
    //  beql  $t6, $zero, .L_US_8031563C
    //   lw    $t9, ($s7)
    //  lbu   $v0, 7($s7)
    //  lui   $t7, %hi(D_802218D0)
    //  lw    $t6, 0x16c($sp)
    //  addu  $t7, $t7, $v0
    //  lbu   $t7, %lo(D_802218D0)($t7)
    //  lui   $at, 0x100
    //  slti  $t8, $t7, 2
    //  beqz  $t8, .L_US_80315638
    //   sll   $t9, $v0, 8
    //  addu  $t7, $t9, $t6
    //  addu  $t8, $t7, $at
    //  lui   $at, %hi(D_80331D40) # $at, 0x8033
    //  b     .L_US_80315F44
    //   sw    $t8, %lo(D_80331D40)($at)
    //.L_US_80315638:
    //  lw    $t9, ($s7)
    //.L_US_8031563C:
    //  srl   $t6, $t9, 0x1f
    //  beql  $t6, $zero, .L_US_80315F48
    //   lw    $t9, 0x16c($sp)
    //  lw    $t7, 0x174($sp)
    //  sw    $zero, 0x140($sp)
    //  li    $at, 1
    //  sll   $t8, $t7, 1
    //  sw    $t8, 0x48($sp)
    //  lw    $t9, ($s7)
    //  li    $t8, 1
    //  move  $a0, $s4
    //  sll   $t6, $t9, 1
    //  srl   $t7, $t6, 0x1f
    //  bne   $t7, $at, .L_US_80315684
    //   move  $a1, $s7
    //  sw    $t8, 0x140($sp)
    //  sw    $zero, 0x14($s7)
    //  sh    $zero, 0x20($s7)
    //.L_US_80315684:
    //  li    $at, 0x40000000 # 2.000000
    //  mtc1  $at, $f4
    //  lwc1  $f0, 0x38($s7)
    //  lui   $at, %hi(D_80337BB8)
    //  c.lt.s $f0, $f4
    //  nop
    //  bc1f  .L_US_803156D8
    //   nop
    //  lui   $at, %hi(D_80337BB0) # $at, 0x8034
    //  lwc1  $f6, %lo(D_80337BB0)($at)
    //  li    $t9, 1
    //  sw    $t9, 0xe0($sp)
    //  c.lt.s $f6, $f0
    //  lui   $at, %hi(D_80337BB0 + 0x4) # $at, 0x8034
    //  bc1f  .L_US_803156D0
    //   nop
    //  lwc1  $f8, %lo(D_80337BB0 + 0x4)($at)
    //  swc1  $f8, 0x38($s7)
    //  lwc1  $f0, 0x38($s7)
    //.L_US_803156D0:
    //  b     .L_US_80315714
    //   mov.s $f2, $f0
    //.L_US_803156D8:
    //  lwc1  $f10, %lo(D_80337BB8)($at)
    //  li    $t6, 2
    //  sw    $t6, 0xe0($sp)
    //  c.le.s $f10, $f0
    //  lui   $at, %hi(D_80337BB8)
    //  bc1fl .L_US_80315704
    //   lui   $at, 0x3f00 # $at, 0x3f00
    //  lwc1  $f16, %lo(D_80337BB8 + 0x4)($at)
    //  swc1  $f16, 0x38($s7)
    //  lwc1  $f0, 0x38($s7)
    //  li    $at, 0x3F000000 # 0.500000
    //.L_US_80315704:
    //  mtc1  $at, $f18
    //  nop
    //  mul.s $f2, $f0, $f18
    //  nop
    //.L_US_80315714:
    //  li    $at, 0x47000000 # 32768.000000
    //  mtc1  $at, $f4
    //  lw    $t6, 0x174($sp)
    //  mul.s $f6, $f2, $f4
    //  trunc.w.s $f8, $f6
    //  mfc1  $t8, $f8
    //  nop
    //  andi  $t9, $t8, 0xffff
    //  multu $t9, $t6
    //  sw    $t9, 0x5c($sp)
    //  lhu   $t9, 0x20($s7)
    //  lw    $v0, 0x24($s7)
    //  mflo  $t7
    //  sll   $t8, $t7, 1
    //  addu  $v1, $t9, $t8
    //  bnez  $v0, .L_US_8031578C
    //   sh    $v1, 0x20($s7)
    //  srl   $s0, $v1, 0x10
    //  move  $a2, $s0
    //  jal   func_80314F08
    //   sw    $zero, 0x140($sp)
    //  lw    $t1, 0x14($s7)
    //  move  $s4, $v0
    //  sll   $t7, $t1, 1
    //  addiu $t9, $t7, 0x180
    //  sh    $t9, 0xce($sp)
    //  addu  $t8, $t1, $s0
    //  sw    $t8, 0x14($s7)
    //  b     .L_US_80315E6C
    //   lw    $a1, ($s7)
    //.L_US_8031578C:
    //  lw    $t6, ($v0)
    //  srl   $v0, $v1, 0x10
    //  sw    $t6, 0x15c($sp)
    //  lw    $ra, 8($t6)
    //  lw    $t9, 4($ra)
    //  sw    $t9, 0x108($sp)
    //  lw    $t8, 4($t6)
    //  lw    $t6, 0xe0($sp)
    //  sw    $zero, 0xd0($sp)
    //  sw    $zero, 0xdc($sp)
    //  blez  $t6, .L_US_80315E64
    //   sw    $t8, 0x118($sp)
    //  xori  $t9, $t6, 1
    //  sltiu $t9, $t9, 1
    //  sw    $t9, 0x54($sp)
    //  sw    $v0, 0x58($sp)
    //  lw    $t7, 0x15c($sp)
    //.L_US_803157D0:
    //  lw    $t8, 0x54($sp)
    //  lw    $v0, 0x58($sp)
    //  lw    $a0, 0xc($t7)
    //  move  $fp, $zero
    //  move  $s5, $zero
    //  beqz  $t8, .L_US_803157F4
    //   addiu $a1, $a0, 8
    //  b     .L_US_80315818
    //   move  $t5, $v0
    //.L_US_803157F4:
    //  andi  $t6, $v0, 1
    //  beqz  $t6, .L_US_80315818
    //   move  $t5, $v0
    //  lw    $t7, 0xdc($sp)
    //  li    $at, -2
    //  and   $t9, $v0, $at
    //  sll   $t8, $t7, 1
    //  b     .L_US_80315818
    //   addu  $t5, $t9, $t8
    //.L_US_80315818:
    //  lw    $t6, 0x154($sp)
    //  sw    $v0, 0x58($sp)
    //  beq   $t6, $a1, .L_US_80315870
    //   nop
    //  sw    $a1, 0x154($sp)
    //  lw    $t9, ($a0)
    //  lw    $t7, 4($a0)
    //  lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
    //  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
    //  multu $t7, $t9
    //  move  $v0, $s4
    //  addiu $s4, $s4, 8
    //  mflo  $v1
    //  sll   $t8, $v1, 4
    //  and   $t6, $t8, $at
    //  lui   $at, 0xb00
    //  or    $t7, $t6, $at
    //  sw    $t7, ($v0)
    //  lw    $t9, 0x154($sp)
    //  lui   $at, 0x8000
    //  addu  $t8, $t9, $at
    //  sw    $t8, 4($v0)
    //.L_US_80315870:
    //  beqz  $t5, .L_US_80315C7C
    //   lw    $v0, 0x58($sp)
    //  sw    $v0, 0x58($sp)
    //  lw    $t1, 0x14($s7)
    //.L_US_80315880:
    //  lw    $t6, 0x108($sp)
    //  subu  $a0, $t5, $fp
    //  andi  $s2, $t1, 0xf
    //  move  $t2, $zero
    //  move  $t3, $zero
    //  move  $t4, $a0
    //  bnez  $s2, .L_US_803158B4
    //   subu  $v1, $t6, $t1
    //  lw    $t7, ($s7)
    //  sll   $t8, $t7, 2
    //  bltzl $t8, .L_US_803158B8
    //   li    $t6, 16
    //  li    $s2, 16
    //.L_US_803158B4:
    //  li    $t6, 16
    //.L_US_803158B8:
    //  subu  $a1, $t6, $s2
    //  slt   $at, $a0, $v1
    //  beqz  $at, .L_US_803158F4
    //   move  $s6, $a1
    //  subu  $v0, $a0, $a1
    //  addiu $v0, $v0, 0xf
    //  bgez  $v0, .L_US_803158E0
    //   sra   $t7, $v0, 4
    //  addiu $at, $v0, 0xf
    //  sra   $t7, $at, 4
    //.L_US_803158E0:
    //  sll   $s0, $t7, 4
    //  addu  $t9, $a1, $s0
    //  move  $t0, $t7
    //  b     .L_US_80315938
    //   subu  $s3, $t9, $a0
    //.L_US_803158F4:
    //  addu  $v0, $v1, $s2
    //  addiu $s0, $v0, -0x10
    //  bgtz  $s0, .L_US_8031590C
    //   move  $s3, $zero
    //  move  $s0, $zero
    //  move  $s6, $v1
    //.L_US_8031590C:
    //  addiu $t0, $s0, 0xf
    //  lw    $t6, 8($ra)
    //  bgez  $t0, .L_US_80315924
    //   sra   $t8, $t0, 4
    //  addiu $at, $t0, 0xf
    //  sra   $t8, $at, 4
    //.L_US_80315924:
    //  beqz  $t6, .L_US_80315934
    //   move  $t0, $t8
    //  b     .L_US_80315938
    //   li    $t3, 1
    //.L_US_80315934:
    //  li    $t2, 1
    //.L_US_80315938:
    //  beqz  $t0, .L_US_80315A04
    //   li    $v1, 9
    //  subu  $v0, $t1, $s2
    //  addiu $v0, $v0, 0x10
    //  bgez  $v0, .L_US_80315958
    //   sra   $t7, $v0, 4
    //  addiu $at, $v0, 0xf
    //  sra   $t7, $at, 4
    //.L_US_80315958:
    //  multu $t7, $v1
    //  lw    $t8, 0x118($sp)
    //  sw    $ra, 0x158($sp)
    //  lw    $a2, 0x140($sp)
    //  addiu $a3, $s7, 3
    //  sw    $t2, 0x148($sp)
    //  sw    $t3, 0x144($sp)
    //  sw    $t4, 0x104($sp)
    //  sw    $t5, 0x110($sp)
    //  mflo  $t9
    //  addu  $a0, $t9, $t8
    //  nop
    //  multu $t0, $v1
    //  mflo  $s1
    //  move  $a1, $s1
    //  jal   func_80317270
    //   nop
    //  andi  $a3, $v0, 0xf
    //  move  $a0, $s4
    //  lui   $t6, (0x080003F0 >> 16) # lui $t6, 0x800
    //  lw    $t2, 0x148($sp)
    //  lw    $t3, 0x144($sp)
    //  lw    $t4, 0x104($sp)
    //  lw    $t5, 0x110($sp)
    //  lw    $ra, 0x158($sp)
    //  ori   $t6, (0x080003F0 & 0xFFFF) # ori $t6, $t6, 0x3f0
    //  addu  $t7, $s1, $a3
    //  andi  $t9, $t7, 0xffff
    //  sw    $t6, ($a0)
    //  addiu $s4, $s4, 8
    //  sw    $t9, 4($a0)
    //  move  $a1, $s4
    //  subu  $t6, $v0, $a3
    //  lui   $at, 0x8000
    //  addu  $t7, $t6, $at
    //  lui   $t8, 0x400
    //  sw    $t8, ($a1)
    //  sw    $t7, 4($a1)
    //  lw    $a2, ($s7)
    //  addiu $s4, $s4, 8
    //  sll   $t9, $a2, 2
    //  b     .L_US_80315A18
    //   srl   $a2, $t9, 0x1f
    //.L_US_80315A04:
    //  lw    $a2, ($s7)
    //  move  $s0, $zero
    //  move  $a3, $zero
    //  sll   $t6, $a2, 2
    //  srl   $a2, $t6, 0x1f
    //.L_US_80315A18:
    //  beqz  $a2, .L_US_80315A58
    //   move  $v0, $s4
    //  lui   $t9, 0xf00
    //  sw    $t9, ($v0)
    //  lw    $t8, 0x15c($sp)
    //  lui   $at, (0x80000010 >> 16) # lui $at, 0x8000
    //  ori   $at, (0x80000010 & 0xFFFF) # ori $at, $at, 0x10
    //  lw    $t6, 8($t8)
    //  li    $t9, 2
    //  addiu $s4, $s4, 8
    //  addu  $t7, $t6, $at
    //  sw    $t7, 4($v0)
    //  sw    $t9, 0x140($sp)
    //  lbu   $t8, ($s7)
    //  andi  $t6, $t8, 0xffdf
    //  sb    $t6, ($s7)
    //.L_US_80315A58:
    //  bnez  $fp, .L_US_80315ACC
    //   move  $v0, $s4
    //  addiu $t7, $a3, 0x3f0
    //  andi  $t9, $t7, 0xffff
    //  lui   $at, 0x800
    //  or    $t8, $t9, $at
    //  sll   $a2, $s0, 1
    //  andi  $t6, $a2, 0xffff
    //  lui   $at, 0x180
    //  move  $v0, $s4
    //  or    $t7, $t6, $at
    //  sw    $t7, 4($v0)
    //  sw    $t8, ($v0)
    //  lw    $t9, 0x140($sp)
    //  addiu $s4, $s4, 8
    //  lui   $at, 0x100
    //  andi  $t8, $t9, 0xff
    //  sll   $t6, $t8, 0x10
    //  or    $t7, $t6, $at
    //  move  $v1, $s4
    //  sw    $t7, ($v1)
    //  lw    $t9, 0x34($s7)
    //  lui   $at, 0x8000
    //  sll   $t6, $s2, 1
    //  addu  $t8, $t9, $at
    //  sw    $t8, 4($v1)
    //  addiu $s4, $s4, 8
    //  b     .L_US_80315B88
    //   sw    $t6, 0x128($sp)
    //.L_US_80315ACC:
    //  addiu $t7, $a3, 0x3f0
    //  andi  $t9, $t7, 0xffff
    //  lui   $at, 0x800
    //  or    $t8, $t9, $at
    //  li    $at, -32
    //  addiu $v1, $s5, 0x1f
    //  and   $t6, $v1, $at
    //  addiu $t9, $t6, 0x180
    //  move  $v1, $t6
    //  sw    $t8, ($v0)
    //  sll   $a2, $s0, 1
    //  andi  $t6, $a2, 0xffff
    //  sll   $t8, $t9, 0x10
    //  or    $t7, $t8, $t6
    //  sw    $t7, 4($v0)
    //  lw    $t9, 0x140($sp)
    //  addiu $s4, $s4, 8
    //  lui   $at, 0x100
    //  andi  $t8, $t9, 0xff
    //  sll   $t6, $t8, 0x10
    //  or    $t7, $t6, $at
    //  move  $a0, $s4
    //  sw    $t7, ($a0)
    //  lw    $t9, 0x34($s7)
    //  lui   $at, 0x8000
    //  sll   $t6, $s2, 1
    //  addu  $t8, $t9, $at
    //  lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
    //  addu  $t7, $v1, $t6
    //  sw    $t8, 4($a0)
    //  addiu $t9, $t7, 0x180
    //  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
    //  and   $t8, $t9, $at
    //  addiu $s4, $s4, 8
    //  lui   $at, 0xa00
    //  or    $t6, $t8, $at
    //  move  $a1, $s4
    //  sw    $t6, ($a1)
    //  addu  $t6, $s0, $s6
    //  addiu $t9, $s5, 0x180
    //  sll   $t8, $t9, 0x10
    //  subu  $t7, $t6, $s3
    //  sll   $t9, $t7, 1
    //  andi  $t6, $t9, 0xffff
    //  or    $t7, $t8, $t6
    //  sw    $t7, 4($a1)
    //  addiu $s4, $s4, 8
    //.L_US_80315B88:
    //  lw    $t6, 0x140($sp)
    //  addu  $t9, $fp, $s0
    //  addu  $t8, $t9, $s6
    //  li    $at, 1
    //  beq   $t6, $at, .L_US_80315BBC
    //   subu  $fp, $t8, $s3
    //  xori  $v0, $t6, 2
    //  addu  $t7, $s0, $s6
    //  subu  $v1, $t7, $s3
    //  beqz  $v0, .L_US_80315BCC
    //   sw    $zero, 0x140($sp)
    //  b     .L_US_80315BD8
    //   sll   $t8, $v1, 1
    //.L_US_80315BBC:
    //  sw    $zero, 0x128($sp)
    //  addu  $s5, $s5, $a2
    //  b     .L_US_80315BF4
    //   sw    $zero, 0x140($sp)
    //.L_US_80315BCC:
    //  sll   $t9, $v1, 1
    //  b     .L_US_80315BF4
    //   addu  $s5, $s5, $t9
    //.L_US_80315BD8:
    //  beql  $s5, $zero, .L_US_80315BEC
    //   addu  $s5, $v1, $s2
    //  b     .L_US_80315BF4
    //   addu  $s5, $s5, $t8
    //  addu  $s5, $v1, $s2
    //.L_US_80315BEC:
    //  sll   $t6, $s5, 1
    //  move  $s5, $t6
    //.L_US_80315BF4:
    //  beqz  $t2, .L_US_80315C48
    //   lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
    //  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
    //  addiu $t7, $s5, 0x180
    //  and   $t9, $t7, $at
    //  lui   $at, 0x200
    //  move  $v0, $s4
    //  subu  $t6, $t5, $fp
    //  sll   $t7, $t6, 1
    //  or    $t8, $t9, $at
    //  sw    $t8, ($v0)
    //  sw    $t7, 4($v0)
    //  lbu   $t8, ($s7)
    //  addiu $s4, $s4, 8
    //  sw    $zero, 0x14($s7)
    //  ori   $t6, $t8, 0x10
    //  sb    $t6, ($s7)
    //  lbu   $t7, ($s7)
    //  andi  $t9, $t7, 0xff7f
    //  b     .L_US_80315C7C
    //   sb    $t9, ($s7)
    //.L_US_80315C48:
    //  beql  $t3, $zero, .L_US_80315C6C
    //   lw    $t8, 0x14($s7)
    //  lbu   $t6, ($s7)
    //  ori   $t7, $t6, 0x20
    //  sb    $t7, ($s7)
    //  lw    $t9, ($ra)
    //  b     .L_US_80315C74
    //   sw    $t9, 0x14($s7)
    //  lw    $t8, 0x14($s7)
    //.L_US_80315C6C:
    //  addu  $t6, $t8, $t4
    //  sw    $t6, 0x14($s7)
    //.L_US_80315C74:
    //  bnel  $fp, $t5, .L_US_80315880
    //   lw    $t1, 0x14($s7)
    //.L_US_80315C7C:
    //  lw    $t7, 0x54($sp)
    //  lw    $t9, 0xe0($sp)
    //  li    $at, 2
    //  bnez  $t7, .L_US_80315CAC
    //   lw    $t6, 0x128($sp)
    //  beq   $t9, $at, .L_US_80315CC8
    //   lw    $t8, 0xdc($sp)
    //  lw    $a1, ($s7)
    //  sll   $a2, $a1, 3
    //  srl   $t8, $a2, 0x1f
    //  b     .L_US_80315E40
    //   move  $a2, $t8
    //.L_US_80315CAC:
    //  addiu $t7, $t6, 0x180
    //  sh    $t7, 0xce($sp)
    //  lw    $a1, ($s7)
    //  sll   $a2, $a1, 3
    //  srl   $t9, $a2, 0x1f
    //  b     .L_US_80315E40
    //   move  $a2, $t9
    //.L_US_80315CC8:
    //  beqz  $t8, .L_US_80315CF0
    //   move  $v0, $s4
    //  li    $at, 1
    //  beq   $t8, $at, .L_US_80315DA8
    //   move  $v0, $s4
    //  lw    $a1, ($s7)
    //  sll   $a2, $a1, 3
    //  srl   $t6, $a2, 0x1f
    //  b     .L_US_80315E40
    //   move  $a2, $t6
    //.L_US_80315CF0:
    //  lw    $t7, 0x128($sp)
    //  lui   $at, 0x800
    //  addiu $v1, $t5, 4
    //  addiu $t9, $t7, 0x180
    //  andi  $t8, $t9, 0xffff
    //  or    $t6, $t8, $at
    //  lui   $at, 0x20
    //  andi  $t7, $v1, 0xffff
    //  or    $t9, $t7, $at
    //  addiu $s4, $s4, 8
    //  lui   $t8, (0x0501FF60 >> 16) # lui $t8, 0x501
    //  sw    $t9, 4($v0)
    //  sw    $t6, ($v0)
    //  ori   $t8, (0x0501FF60 & 0xFFFF) # ori $t8, $t8, 0xff60
    //  move  $a0, $s4
    //  sw    $t8, ($a0)
    //  lw    $t6, 0x34($s7)
    //  lui   $at, (0x800000F0 >> 16) # lui $at, 0x8000
    //  ori   $at, (0x800000F0 & 0xFFFF) # ori $at, $at, 0xf0
    //  addu  $t7, $t6, $at
    //  sw    $t7, 4($a0)
    //  li    $t9, 36
    //  sw    $v1, 0xd0($sp)
    //  sh    $t9, 0xce($sp)
    //  lw    $a1, ($s7)
    //  addiu $s4, $s4, 8
    //  move  $v0, $s4
    //  sll   $a2, $a1, 3
    //  srl   $t8, $a2, 0x1f
    //  beqz  $t8, .L_US_80315E40
    //   move  $a2, $t8
    //  lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
    //  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
    //  addiu $t6, $t5, 0x24
    //  and   $t7, $t6, $at
    //  lui   $at, 0x200
    //  or    $t9, $t7, $at
    //  addiu $t8, $t5, 0x10
    //  sw    $t8, 4($v0)
    //  sw    $t9, ($v0)
    //  lw    $a1, ($s7)
    //  addiu $s4, $s4, 8
    //  sll   $a2, $a1, 3
    //  srl   $t6, $a2, 0x1f
    //  b     .L_US_80315E40
    //   move  $a2, $t6
    //.L_US_80315DA8:
    //  lw    $t7, 0x128($sp)
    //  lui   $at, 0x800
    //  addiu $s4, $s4, 8
    //  addiu $t9, $t7, 0x180
    //  andi  $t8, $t9, 0xffff
    //  or    $t6, $t8, $at
    //  addiu $t7, $t5, 8
    //  andi  $t9, $t7, 0xffff
    //  sw    $t6, ($v0)
    //  lui   $at, 0x160
    //  or    $t8, $t9, $at
    //  lui   $t6, (0x0501FF60 >> 16) # lui $t6, 0x501
    //  sw    $t8, 4($v0)
    //  ori   $t6, (0x0501FF60 & 0xFFFF) # ori $t6, $t6, 0xff60
    //  move  $v1, $s4
    //  sw    $t6, ($v1)
    //  lw    $t7, 0x34($s7)
    //  lui   $at, (0x800000F0 >> 16) # lui $at, 0x8000
    //  ori   $at, (0x800000F0 & 0xFFFF) # ori $at, $at, 0xf0
    //  addiu $s4, $s4, 8
    //  lui   $t8, (0x0A000164 >> 16) # lui $t8, 0xa00
    //  addu  $t9, $t7, $at
    //  sw    $t9, 4($v1)
    //  ori   $t8, (0x0A000164 & 0xFFFF) # ori $t8, $t8, 0x164
    //  move  $a0, $s4
    //  sw    $t8, ($a0)
    //  lw    $t6, 0xd0($sp)
    //  addiu $s4, $s4, 8
    //  addiu $t9, $t6, 0x20
    //  addiu $t6, $t5, 4
    //  andi  $t7, $t6, 0xffff
    //  sll   $t8, $t9, 0x10
    //  or    $t9, $t8, $t7
    //  sw    $t9, 4($a0)
    //  lw    $a1, ($s7)
    //  sll   $a2, $a1, 3
    //  srl   $t6, $a2, 0x1f
    //  move  $a2, $t6
    //.L_US_80315E40:
    //  beqz  $a2, .L_US_80315E50
    //   lw    $v0, 0xdc($sp)
    //  b     .L_US_80315E6C
    //   sw    $zero, 0x140($sp)
    //.L_US_80315E50:
    //  lw    $t8, 0xe0($sp)
    //  addiu $v0, $v0, 1
    //  sw    $v0, 0xdc($sp)
    //  bnel  $v0, $t8, .L_US_803157D0
    //   lw    $t7, 0x15c($sp)
    //.L_US_80315E64:
    //  sw    $zero, 0x140($sp)
    //  lw    $a1, ($s7)
    //.L_US_80315E6C:
    //  sll   $t7, $a1, 1
    //  srl   $t9, $t7, 0x1f
    //  li    $at, 1
    //  bne   $t9, $at, .L_US_80315E94
    //   move  $a0, $s4
    //  li    $t6, 1
    //  sw    $t6, 0x140($sp)
    //  lbu   $t8, ($s7)
    //  andi  $t7, $t8, 0xffbf
    //  sb    $t7, ($s7)
    //.L_US_80315E94:
    //  lw    $s1, 0x48($sp)
    //  lhu   $t9, 0xce($sp)
    //  lw    $t6, 0x140($sp)
    //  move  $a1, $s7
    //  lhu   $a3, 0x5e($sp)
    //  move  $a2, $s1
    //  sw    $t9, 0x10($sp)
    //  jal   func_80314FD4
    //   sw    $t6, 0x14($sp)
    //  lhu   $t8, 0xc($s7)
    //  move  $s4, $v0
    //  move  $a0, $s4
    //  bnez  $t8, .L_US_80315ED8
    //   move  $a1, $s7
    //  lhu   $t7, 0x10($s7)
    //  beql  $t7, $zero, .L_US_80315EE4
    //   lhu   $t9, 0xe($s7)
    //.L_US_80315ED8:
    //  b     .L_US_80315F04
    //   li    $s0, 1
    //  lhu   $t9, 0xe($s7)
    //.L_US_80315EE4:
    //  bnez  $t9, .L_US_80315EFC
    //   nop
    //  lhu   $t6, 0x12($s7)
    //  move  $s0, $zero
    //  beqz  $t6, .L_US_80315F04
    //   nop
    //.L_US_80315EFC:
    //  b     .L_US_80315F04
    //   li    $s0, 2
    //.L_US_80315F04:
    //  lw    $t8, 0x140($sp)
    //  lw    $a2, 0x174($sp)
    //  move  $a3, $zero
    //  sw    $s0, 0x10($sp)
    //  jal   func_80315030
    //   sw    $t8, 0x14($sp)
    //  lbu   $t7, 1($s7)
    //  move  $s4, $v0
    //  move  $a0, $v0
    //  beqz  $t7, .L_US_80315F44
    //   move  $a1, $s7
    //  move  $a2, $s1
    //  lw    $a3, 0x140($sp)
    //  jal   func_803155F4
    //   sw    $s0, 0x10($sp)
    //  move  $s4, $v0
    //.L_US_80315F44:
    //  lw    $t9, 0x16c($sp)
    //.L_US_80315F48:
    //  lw    $t8, 0x64($sp)
    //  addiu $t6, $t9, 1
    //  lui   $t9, %hi(D_80226D70) # $t9, 0x8022
    //  lw    $t9, %lo(D_80226D70)($t9)
    //  addiu $t7, $t8, 0xc0
    //  sw    $t7, 0x64($sp)
    //  slt   $at, $t6, $t9
    //  bnez  $at, .L_US_803155E0
    //   sw    $t6, 0x16c($sp)
    //.L_US_80315F6C:
    //  lui   $t0, 0x800
    //  move  $a0, $s4
    //  sw    $t0, ($a0)
    //  lw    $v1, 0x174($sp)
    //  addiu $s4, $s4, 8
    //  move  $a1, $s4
    //  sll   $t8, $v1, 1
    //  andi  $t7, $t8, 0xffff
    //  sw    $t7, 4($a0)
    //  addiu $s4, $s4, 8
    //  lui   $t6, 0xd00
    //  lui   $t9, (0x04C00600 >> 16) # lui $t9, 0x4c0
    //  ori   $t9, (0x04C00600 & 0xFFFF) # ori $t9, $t9, 0x600
    //  sw    $t6, ($a1)
    //  move  $a2, $s4
    //  sw    $t9, 4($a1)
    //  sll   $t8, $t8, 1
    //  andi  $t7, $t8, 0xffff
    //  addiu $s4, $s4, 8
    //  sw    $t7, 4($a2)
    //  sw    $t0, ($a2)
    //  move  $a3, $s4
    //  lui   $t6, 0x600
    //  sw    $t6, ($a3)
    //  lw    $t9, 0x170($sp)
    //  lui   $at, 0x8000
    //  addiu $v0, $s4, 8
    //  addu  $t8, $t9, $at
    //  sw    $t8, 4($a3)
    //  lw    $ra, 0x44($sp)
    //  lw    $fp, 0x40($sp)
    //  lw    $s7, 0x3c($sp)
    //  lw    $s6, 0x38($sp)
    //  lw    $s5, 0x34($sp)
    //  lw    $s4, 0x30($sp)
    //  lw    $s3, 0x2c($sp)
    //  lw    $s2, 0x28($sp)
    //  lw    $s1, 0x24($sp)
    //  lw    $s0, 0x20($sp)
    //  jr    $ra
    //   addiu $sp, $sp, 0x170
    //.endif
}

#else

#ifdef VERSION_JP
// clang-format off
GLOBAL_ASM(
.late_rodata
glabel D_80337BB0
    .word 0x3FFFFFD6, 0x0E94EE39
glabel D_80337BB8
    .word 0x3FFFFEB0, 0 
glabel D_80337BC0
    .word 0x400FFFDB, 0x4CC25072
glabel D_80337BC8
    .word 0x407FFEDA, 0

.text
glabel func_80314480
/* 0CF480 80314480 27BDFE88 */  addiu $sp, $sp, -0x178
/* 0CF484 80314484 3C0E8022 */  lui   $t6, %hi(D_80226D70) # $t6, 0x8022
/* 0CF488 80314488 8DCE6D70 */  lw    $t6, %lo(D_80226D70)($t6)
/* 0CF48C 8031448C AFB40030 */  sw    $s4, 0x30($sp)
/* 0CF490 80314490 00C0A025 */  move  $s4, $a2
/* 0CF494 80314494 AFBF0044 */  sw    $ra, 0x44($sp)
/* 0CF498 80314498 AFBE0040 */  sw    $fp, 0x40($sp)
/* 0CF49C 8031449C AFB7003C */  sw    $s7, 0x3c($sp)
/* 0CF4A0 803144A0 AFB60038 */  sw    $s6, 0x38($sp)
/* 0CF4A4 803144A4 AFB50034 */  sw    $s5, 0x34($sp)
/* 0CF4A8 803144A8 AFB3002C */  sw    $s3, 0x2c($sp)
/* 0CF4AC 803144AC AFB20028 */  sw    $s2, 0x28($sp)
/* 0CF4B0 803144B0 AFB10024 */  sw    $s1, 0x24($sp)
/* 0CF4B4 803144B4 AFB00020 */  sw    $s0, 0x20($sp)
/* 0CF4B8 803144B8 AFA40178 */  sw    $a0, 0x178($sp)
/* 0CF4BC 803144BC AFA5017C */  sw    $a1, 0x17c($sp)
/* 0CF4C0 803144C0 AFA00174 */  sw    $zero, 0x174($sp)
/* 0CF4C4 803144C4 19C00267 */  blez  $t6, .L80314E64
/* 0CF4C8 803144C8 AFA0015C */   sw    $zero, 0x15c($sp)
/* 0CF4CC 803144CC AFA0006C */  sw    $zero, 0x6c($sp)
/* 0CF4D0 803144D0 3C1F8000 */  lui   $ra, 0x8000
.L803144D4:
/* 0CF4D4 803144D4 3C188022 */  lui   $t8, %hi(D_80222A10) # $t8, 0x8022
/* 0CF4D8 803144D8 8F182A10 */  lw    $t8, %lo(D_80222A10)($t8)
/* 0CF4DC 803144DC 8FAF006C */  lw    $t7, 0x6c($sp)
/* 0CF4E0 803144E0 3C198022 */  lui   $t9, %hi(D_802218D0)
/* 0CF4E4 803144E4 3C010100 */  lui   $at, 0x100
/* 0CF4E8 803144E8 01F8B821 */  addu  $s7, $t7, $t8
/* 0CF4EC 803144EC 92E20007 */  lbu   $v0, 7($s7)
/* 0CF4F0 803144F0 8FB80174 */  lw    $t8, 0x174($sp)
/* 0CF4F4 803144F4 0322C821 */  addu  $t9, $t9, $v0
/* 0CF4F8 803144F8 933918D0 */  lbu   $t9, %lo(D_802218D0)($t9)
/* 0CF4FC 803144FC 2B2E0002 */  slti  $t6, $t9, 2
/* 0CF500 80314500 11C00006 */  beqz  $t6, .L8031451C
/* 0CF504 80314504 00027A00 */   sll   $t7, $v0, 8
/* 0CF508 80314508 01F8C821 */  addu  $t9, $t7, $t8
/* 0CF50C 8031450C 03217021 */  addu  $t6, $t9, $at
/* 0CF510 80314510 3C018033 */  lui    $at, %hi(D_80331D40)
/* 0CF514 80314514 10000249 */  b     .L80314E3C
/* 0CF518 80314518 AC2E1D40 */   sw    $t6, %lo(D_80331D40)($at)
.L8031451C:
/* 0CF51C 8031451C 8EEF0000 */  lw    $t7, ($s7)
/* 0CF520 80314520 000FC7C2 */  srl   $t8, $t7, 0x1f
/* 0CF524 80314524 53000246 */  beql  $t8, $zero, .L80314E40
/* 0CF528 80314528 8FAE0174 */   lw    $t6, 0x174($sp)
/* 0CF52C 8031452C 8FB9017C */  lw    $t9, 0x17c($sp)
/* 0CF530 80314530 AFA00148 */  sw    $zero, 0x148($sp)
/* 0CF534 80314534 24010001 */  li    $at, 1
/* 0CF538 80314538 00197040 */  sll   $t6, $t9, 1
/* 0CF53C 8031453C AFAE0048 */  sw    $t6, 0x48($sp)
/* 0CF540 80314540 8EEF0000 */  lw    $t7, ($s7)
/* 0CF544 80314544 44802000 */  mtc1  $zero, $f4
/* 0CF548 80314548 240E0001 */  li    $t6, 1
/* 0CF54C 8031454C 000FC040 */  sll   $t8, $t7, 1
/* 0CF550 80314550 0018CFC2 */  srl   $t9, $t8, 0x1f
/* 0CF554 80314554 17210004 */  bne   $t9, $at, .L80314568
/* 0CF558 80314558 02802025 */   move  $a0, $s4
/* 0CF55C 8031455C AFAE0148 */  sw    $t6, 0x148($sp)
/* 0CF560 80314560 AEE00014 */  sw    $zero, 0x14($s7)
/* 0CF564 80314564 A6E00020 */  sh    $zero, 0x20($s7)
.L80314568:
/* 0CF568 80314568 C6E20038 */  lwc1  $f2, 0x38($s7)
/* 0CF56C 8031456C 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0CF570 80314570 44812800 */  mtc1  $at, $f5
/* 0CF574 80314574 46001021 */  cvt.d.s $f0, $f2
/* 0CF578 80314578 3C018033 */  lui   $at, %hi(D_80337BC0)
/* 0CF57C 8031457C 4624003C */  c.lt.d $f0, $f4
/* 0CF580 80314580 02E02825 */  move  $a1, $s7
/* 0CF584 80314584 4500000E */  bc1f  .L803145C0
/* 0CF588 80314588 00000000 */   nop   
/* 0CF58C 8031458C 3C018033 */  lui   $at, %hi(D_80337BB0)
/* 0CF590 80314590 D4267BB0 */  ldc1  $f6, %lo(D_80337BB0)($at)
/* 0CF594 80314594 240F0001 */  li    $t7, 1
/* 0CF598 80314598 AFAF00E8 */  sw    $t7, 0xe8($sp)
/* 0CF59C 8031459C 4620303C */  c.lt.d $f6, $f0
/* 0CF5A0 803145A0 3C018033 */  lui    $at, %hi(D_80337BB8)
/* 0CF5A4 803145A4 45000004 */  bc1f  .L803145B8
/* 0CF5A8 803145A8 00000000 */   nop   
/* 0CF5AC 803145AC C4287BB8 */  lwc1  $f8, %lo(D_80337BB8)($at)
/* 0CF5B0 803145B0 E6E80038 */  swc1  $f8, 0x38($s7)
/* 0CF5B4 803145B4 C6E20038 */  lwc1  $f2, 0x38($s7)
.L803145B8:
/* 0CF5B8 803145B8 10000012 */  b     .L80314604
/* 0CF5BC 803145BC 46001306 */   mov.s $f12, $f2
.L803145C0:
/* 0CF5C0 803145C0 D42A7BC0 */  ldc1  $f10, %lo(D_80337BC0)($at)
/* 0CF5C4 803145C4 24180002 */  li    $t8, 2
/* 0CF5C8 803145C8 44802000 */  mtc1  $zero, $f4
/* 0CF5CC 803145CC 4620503E */  c.le.d $f10, $f0
/* 0CF5D0 803145D0 AFB800E8 */  sw    $t8, 0xe8($sp)
/* 0CF5D4 803145D4 3C018033 */  lui   $at, %hi(D_80337BC8)
/* 0CF5D8 803145D8 45020006 */  bc1fl .L803145F4
/* 0CF5DC 803145DC 3C013FE0 */   lui   $at, 0x3fe0
/* 0CF5E0 803145E0 C4307BC8 */  lwc1  $f16, %lo(D_80337BC8)($at)
/* 0CF5E4 803145E4 E6F00038 */  swc1  $f16, 0x38($s7)
/* 0CF5E8 803145E8 C6F20038 */  lwc1  $f18, 0x38($s7)
/* 0CF5EC 803145EC 46009021 */  cvt.d.s $f0, $f18
/* 0CF5F0 803145F0 3C013FE0 */  li    $at, 0x3FE00000 # 1.750000
.L803145F4:
/* 0CF5F4 803145F4 44812800 */  mtc1  $at, $f5
/* 0CF5F8 803145F8 00000000 */  nop   
/* 0CF5FC 803145FC 46240182 */  mul.d $f6, $f0, $f4
/* 0CF600 80314600 46203320 */  cvt.s.d $f12, $f6
.L80314604:
/* 0CF604 80314604 3C014700 */  li    $at, 0x47000000 # 32768.000000
/* 0CF608 80314608 44814000 */  mtc1  $at, $f8
/* 0CF60C 8031460C 8FB8017C */  lw    $t8, 0x17c($sp)
/* 0CF610 80314610 46086282 */  mul.s $f10, $f12, $f8
/* 0CF614 80314614 4600540D */  trunc.w.s $f16, $f10
/* 0CF618 80314618 440E8000 */  mfc1  $t6, $f16
/* 0CF61C 8031461C 00000000 */  nop   
/* 0CF620 80314620 31CFFFFF */  andi  $t7, $t6, 0xffff
/* 0CF624 80314624 01F80019 */  multu $t7, $t8
/* 0CF628 80314628 AFAF005C */  sw    $t7, 0x5c($sp)
/* 0CF62C 8031462C 96EF0020 */  lhu   $t7, 0x20($s7)
/* 0CF630 80314630 8EE20024 */  lw    $v0, 0x24($s7)
/* 0CF634 80314634 0000C812 */  mflo  $t9
/* 0CF638 80314638 00197040 */  sll   $t6, $t9, 1
/* 0CF63C 8031463C 01EE1821 */  addu  $v1, $t7, $t6
/* 0CF640 80314640 1440000E */  bnez  $v0, .L8031467C
/* 0CF644 80314644 A6E30020 */   sh    $v1, 0x20($s7)
/* 0CF648 80314648 00038402 */  srl   $s0, $v1, 0x10
/* 0CF64C 8031464C 02003025 */  move  $a2, $s0
/* 0CF650 80314650 0C0C53C2 */  jal   func_80314F08
/* 0CF654 80314654 AFA00148 */   sw    $zero, 0x148($sp)
/* 0CF658 80314658 8EE90014 */  lw    $t1, 0x14($s7)
/* 0CF65C 8031465C 0040A025 */  move  $s4, $v0
/* 0CF660 80314660 0009C840 */  sll   $t9, $t1, 1
/* 0CF664 80314664 272F0180 */  addiu $t7, $t9, 0x180
/* 0CF668 80314668 A7AF00D6 */  sh    $t7, 0xd6($sp)
/* 0CF66C 8031466C 01307021 */  addu  $t6, $t1, $s0
/* 0CF670 80314670 AEEE0014 */  sw    $t6, 0x14($s7)
/* 0CF674 80314674 100001B9 */  b     .L80314D5C
/* 0CF678 80314678 8EE50000 */   lw    $a1, ($s7)
.L8031467C:
/* 0CF67C 8031467C 8C460000 */  lw    $a2, ($v0)
/* 0CF680 80314680 00031402 */  srl   $v0, $v1, 0x10
/* 0CF684 80314684 8CD80008 */  lw    $t8, 8($a2)
/* 0CF688 80314688 AFB80160 */  sw    $t8, 0x160($sp)
/* 0CF68C 8031468C 8F0F0004 */  lw    $t7, 4($t8)
/* 0CF690 80314690 8FB800E8 */  lw    $t8, 0xe8($sp)
/* 0CF694 80314694 AFAF0110 */  sw    $t7, 0x110($sp)
/* 0CF698 80314698 8CCE0004 */  lw    $t6, 4($a2)
/* 0CF69C 8031469C AFA000D8 */  sw    $zero, 0xd8($sp)
/* 0CF6A0 803146A0 AFA000E4 */  sw    $zero, 0xe4($sp)
/* 0CF6A4 803146A4 1B0001AB */  blez  $t8, .L80314D54
/* 0CF6A8 803146A8 AFAE0120 */   sw    $t6, 0x120($sp)
/* 0CF6AC 803146AC 3B190001 */  xori  $t9, $t8, 1
/* 0CF6B0 803146B0 2F390001 */  sltiu $t9, $t9, 1
/* 0CF6B4 803146B4 AFB90054 */  sw    $t9, 0x54($sp)
/* 0CF6B8 803146B8 AFA20058 */  sw    $v0, 0x58($sp)
/* 0CF6BC 803146BC AFA60164 */  sw    $a2, 0x164($sp)
/* 0CF6C0 803146C0 8FA60164 */  lw    $a2, 0x164($sp)
.L803146C4:
/* 0CF6C4 803146C4 8FAF0054 */  lw    $t7, 0x54($sp)
/* 0CF6C8 803146C8 8FA20058 */  lw    $v0, 0x58($sp)
/* 0CF6CC 803146CC 8CC4000C */  lw    $a0, 0xc($a2)
/* 0CF6D0 803146D0 0000F025 */  move  $fp, $zero
/* 0CF6D4 803146D4 0000A825 */  move  $s5, $zero
/* 0CF6D8 803146D8 11E00003 */  beqz  $t7, .L803146E8
/* 0CF6DC 803146DC 24850008 */   addiu $a1, $a0, 8
/* 0CF6E0 803146E0 1000000B */  b     .L80314710
/* 0CF6E4 803146E4 00406825 */   move  $t5, $v0
.L803146E8:
/* 0CF6E8 803146E8 304E0001 */  andi  $t6, $v0, 1
/* 0CF6EC 803146EC 11C00007 */  beqz  $t6, .L8031470C
/* 0CF6F0 803146F0 AFA60164 */   sw    $a2, 0x164($sp)
/* 0CF6F4 803146F4 8FB900E4 */  lw    $t9, 0xe4($sp)
/* 0CF6F8 803146F8 2401FFFE */  li    $at, -2
/* 0CF6FC 803146FC 0041C024 */  and   $t8, $v0, $at
/* 0CF700 80314700 00197840 */  sll   $t7, $t9, 1
/* 0CF704 80314704 10000002 */  b     .L80314710
/* 0CF708 80314708 030F6821 */   addu  $t5, $t8, $t7
.L8031470C:
/* 0CF70C 8031470C 00406825 */  move  $t5, $v0
.L80314710:
/* 0CF710 80314710 8FAE015C */  lw    $t6, 0x15c($sp)
/* 0CF714 80314714 AFA20058 */  sw    $v0, 0x58($sp)
/* 0CF718 80314718 11C50012 */  beq   $t6, $a1, .L80314764
/* 0CF71C 8031471C 00000000 */   nop   
/* 0CF720 80314720 AFA5015C */  sw    $a1, 0x15c($sp)
/* 0CF724 80314724 8C980000 */  lw    $t8, ($a0)
/* 0CF728 80314728 8C990004 */  lw    $t9, 4($a0)
/* 0CF72C 8031472C 3C0100FF */  lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
/* 0CF730 80314730 3421FFFF */  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
/* 0CF734 80314734 03380019 */  multu $t9, $t8
/* 0CF738 80314738 02801025 */  move  $v0, $s4
/* 0CF73C 8031473C 26940008 */  addiu $s4, $s4, 8
/* 0CF740 80314740 00001812 */  mflo  $v1
/* 0CF744 80314744 00037900 */  sll   $t7, $v1, 4
/* 0CF748 80314748 01E17024 */  and   $t6, $t7, $at
/* 0CF74C 8031474C 3C010B00 */  lui   $at, 0xb00
/* 0CF750 80314750 01C1C825 */  or    $t9, $t6, $at
/* 0CF754 80314754 AC590000 */  sw    $t9, ($v0)
/* 0CF758 80314758 8FB8015C */  lw    $t8, 0x15c($sp)
/* 0CF75C 8031475C 031F7821 */  addu  $t7, $t8, $ra
/* 0CF760 80314760 AC4F0004 */  sw    $t7, 4($v0)
.L80314764:
/* 0CF764 80314764 11A00101 */  beqz  $t5, .L80314B6C
/* 0CF768 80314768 8FA20058 */   lw    $v0, 0x58($sp)
/* 0CF76C 8031476C AFA20058 */  sw    $v0, 0x58($sp)
/* 0CF770 80314770 8EE90014 */  lw    $t1, 0x14($s7)
.L80314774:
/* 0CF774 80314774 8FAE0110 */  lw    $t6, 0x110($sp)
/* 0CF778 80314778 01BE2023 */  subu  $a0, $t5, $fp
/* 0CF77C 8031477C 3132000F */  andi  $s2, $t1, 0xf
/* 0CF780 80314780 00005025 */  move  $t2, $zero
/* 0CF784 80314784 00005825 */  move  $t3, $zero
/* 0CF788 80314788 00806025 */  move  $t4, $a0
/* 0CF78C 8031478C 16400006 */  bnez  $s2, .L803147A8
/* 0CF790 80314790 01C91823 */   subu  $v1, $t6, $t1
/* 0CF794 80314794 8EF90000 */  lw    $t9, ($s7)
/* 0CF798 80314798 00197880 */  sll   $t7, $t9, 2
/* 0CF79C 8031479C 05E20003 */  bltzl $t7, .L803147AC
/* 0CF7A0 803147A0 240E0010 */   li    $t6, 16
/* 0CF7A4 803147A4 24120010 */  li    $s2, 16
.L803147A8:
/* 0CF7A8 803147A8 240E0010 */  li    $t6, 16
.L803147AC:
/* 0CF7AC 803147AC 01D22823 */  subu  $a1, $t6, $s2
/* 0CF7B0 803147B0 0083082A */  slt   $at, $a0, $v1
/* 0CF7B4 803147B4 1020000C */  beqz  $at, .L803147E8
/* 0CF7B8 803147B8 00A0B025 */   move  $s6, $a1
/* 0CF7BC 803147BC 00851023 */  subu  $v0, $a0, $a1
/* 0CF7C0 803147C0 2442000F */  addiu $v0, $v0, 0xf
/* 0CF7C4 803147C4 04410003 */  bgez  $v0, .L803147D4
/* 0CF7C8 803147C8 0002C903 */   sra   $t9, $v0, 4
/* 0CF7CC 803147CC 2441000F */  addiu $at, $v0, 0xf
/* 0CF7D0 803147D0 0001C903 */  sra   $t9, $at, 4
.L803147D4:
/* 0CF7D4 803147D4 00198100 */  sll   $s0, $t9, 4
/* 0CF7D8 803147D8 00B0C021 */  addu  $t8, $a1, $s0
/* 0CF7DC 803147DC 03204025 */  move  $t0, $t9
/* 0CF7E0 803147E0 10000014 */  b     .L80314834
/* 0CF7E4 803147E4 03049823 */   subu  $s3, $t8, $a0
.L803147E8:
/* 0CF7E8 803147E8 00721021 */  addu  $v0, $v1, $s2
/* 0CF7EC 803147EC 2450FFF0 */  addiu $s0, $v0, -0x10
/* 0CF7F0 803147F0 1E000003 */  bgtz  $s0, .L80314800
/* 0CF7F4 803147F4 00009825 */   move  $s3, $zero
/* 0CF7F8 803147F8 00008025 */  move  $s0, $zero
/* 0CF7FC 803147FC 0060B025 */  move  $s6, $v1
.L80314800:
/* 0CF800 80314800 8FAE0160 */  lw    $t6, 0x160($sp)
/* 0CF804 80314804 2608000F */  addiu $t0, $s0, 0xf
/* 0CF808 80314808 05010003 */  bgez  $t0, .L80314818
/* 0CF80C 8031480C 00087903 */   sra   $t7, $t0, 4
/* 0CF810 80314810 2501000F */  addiu $at, $t0, 0xf
/* 0CF814 80314814 00017903 */  sra   $t7, $at, 4
.L80314818:
/* 0CF818 80314818 8DD90008 */  lw    $t9, 8($t6)
/* 0CF81C 8031481C 01E04025 */  move  $t0, $t7
/* 0CF820 80314820 53200004 */  beql  $t9, $zero, .L80314834
/* 0CF824 80314824 240A0001 */   li    $t2, 1
/* 0CF828 80314828 10000002 */  b     .L80314834
/* 0CF82C 8031482C 240B0001 */   li    $t3, 1
/* 0CF830 80314830 240A0001 */  li    $t2, 1
.L80314834:
/* 0CF834 80314834 11000030 */  beqz  $t0, .L803148F8
/* 0CF838 80314838 24030009 */   li    $v1, 9
/* 0CF83C 8031483C 01321023 */  subu  $v0, $t1, $s2
/* 0CF840 80314840 24420010 */  addiu $v0, $v0, 0x10
/* 0CF844 80314844 04410003 */  bgez  $v0, .L80314854
/* 0CF848 80314848 0002C103 */   sra   $t8, $v0, 4
/* 0CF84C 8031484C 2441000F */  addiu $at, $v0, 0xf
/* 0CF850 80314850 0001C103 */  sra   $t8, $at, 4
.L80314854:
/* 0CF854 80314854 03030019 */  multu $t8, $v1
/* 0CF858 80314858 8FAE0120 */  lw    $t6, 0x120($sp)
/* 0CF85C 8031485C 8FA60148 */  lw    $a2, 0x148($sp)
/* 0CF860 80314860 26E70003 */  addiu $a3, $s7, 3
/* 0CF864 80314864 AFAA0150 */  sw    $t2, 0x150($sp)
/* 0CF868 80314868 AFAB014C */  sw    $t3, 0x14c($sp)
/* 0CF86C 8031486C AFAC010C */  sw    $t4, 0x10c($sp)
/* 0CF870 80314870 AFAD0118 */  sw    $t5, 0x118($sp)
/* 0CF874 80314874 00007812 */  mflo  $t7
/* 0CF878 80314878 01EE2021 */  addu  $a0, $t7, $t6
/* 0CF87C 8031487C 00000000 */  nop   
/* 0CF880 80314880 01030019 */  multu $t0, $v1
/* 0CF884 80314884 00008812 */  mflo  $s1
/* 0CF888 80314888 02202825 */  move  $a1, $s1
/* 0CF88C 8031488C 0C0C5C9C */  jal   func_80317270
/* 0CF890 80314890 00000000 */   nop   
/* 0CF894 80314894 3047000F */  andi  $a3, $v0, 0xf
/* 0CF898 80314898 02802025 */  move  $a0, $s4
/* 0CF89C 8031489C 3C190800 */  lui   $t9, (0x080003F0 >> 16) # lui $t9, 0x800
/* 0CF8A0 803148A0 8FAA0150 */  lw    $t2, 0x150($sp)
/* 0CF8A4 803148A4 8FAB014C */  lw    $t3, 0x14c($sp)
/* 0CF8A8 803148A8 8FAC010C */  lw    $t4, 0x10c($sp)
/* 0CF8AC 803148AC 8FAD0118 */  lw    $t5, 0x118($sp)
/* 0CF8B0 803148B0 373903F0 */  ori   $t9, (0x080003F0 & 0xFFFF) # ori $t9, $t9, 0x3f0
/* 0CF8B4 803148B4 0227C021 */  addu  $t8, $s1, $a3
/* 0CF8B8 803148B8 330FFFFF */  andi  $t7, $t8, 0xffff
/* 0CF8BC 803148BC AC990000 */  sw    $t9, ($a0)
/* 0CF8C0 803148C0 26940008 */  addiu $s4, $s4, 8
/* 0CF8C4 803148C4 3C1F8000 */  lui   $ra, 0x8000
/* 0CF8C8 803148C8 AC8F0004 */  sw    $t7, 4($a0)
/* 0CF8CC 803148CC 02802825 */  move  $a1, $s4
/* 0CF8D0 803148D0 0047C823 */  subu  $t9, $v0, $a3
/* 0CF8D4 803148D4 033FC021 */  addu  $t8, $t9, $ra
/* 0CF8D8 803148D8 3C0E0400 */  lui   $t6, 0x400
/* 0CF8DC 803148DC ACAE0000 */  sw    $t6, ($a1)
/* 0CF8E0 803148E0 ACB80004 */  sw    $t8, 4($a1)
/* 0CF8E4 803148E4 8EE60000 */  lw    $a2, ($s7)
/* 0CF8E8 803148E8 26940008 */  addiu $s4, $s4, 8
/* 0CF8EC 803148EC 00067880 */  sll   $t7, $a2, 2
/* 0CF8F0 803148F0 10000006 */  b     .L8031490C
/* 0CF8F4 803148F4 000F37C2 */   srl   $a2, $t7, 0x1f
.L803148F8:
/* 0CF8F8 803148F8 8EE60000 */  lw    $a2, ($s7)
/* 0CF8FC 803148FC 00008025 */  move  $s0, $zero
/* 0CF900 80314900 00003825 */  move  $a3, $zero
/* 0CF904 80314904 0006C880 */  sll   $t9, $a2, 2
/* 0CF908 80314908 001937C2 */  srl   $a2, $t9, 0x1f
.L8031490C:
/* 0CF90C 8031490C 10C0000F */  beqz  $a2, .L8031494C
/* 0CF910 80314910 02801025 */   move  $v0, $s4
/* 0CF914 80314914 3C0F0F00 */  lui   $t7, 0xf00
/* 0CF918 80314918 AC4F0000 */  sw    $t7, ($v0)
/* 0CF91C 8031491C 8FAE0164 */  lw    $t6, 0x164($sp)
/* 0CF920 80314920 3C018000 */  lui   $at, (0x80000010 >> 16) # lui $at, 0x8000
/* 0CF924 80314924 34210010 */  ori   $at, (0x80000010 & 0xFFFF) # ori $at, $at, 0x10
/* 0CF928 80314928 8DD90008 */  lw    $t9, 8($t6)
/* 0CF92C 8031492C 240F0002 */  li    $t7, 2
/* 0CF930 80314930 26940008 */  addiu $s4, $s4, 8
/* 0CF934 80314934 0321C021 */  addu  $t8, $t9, $at
/* 0CF938 80314938 AC580004 */  sw    $t8, 4($v0)
/* 0CF93C 8031493C AFAF0148 */  sw    $t7, 0x148($sp)
/* 0CF940 80314940 92EE0000 */  lbu   $t6, ($s7)
/* 0CF944 80314944 31D9FFDF */  andi  $t9, $t6, 0xffdf
/* 0CF948 80314948 A2F90000 */  sb    $t9, ($s7)
.L8031494C:
/* 0CF94C 8031494C 17C0001B */  bnez  $fp, .L803149BC
/* 0CF950 80314950 02801025 */   move  $v0, $s4
/* 0CF954 80314954 24F803F0 */  addiu $t8, $a3, 0x3f0
/* 0CF958 80314958 330FFFFF */  andi  $t7, $t8, 0xffff
/* 0CF95C 8031495C 3C010800 */  lui   $at, 0x800
/* 0CF960 80314960 01E17025 */  or    $t6, $t7, $at
/* 0CF964 80314964 00103040 */  sll   $a2, $s0, 1
/* 0CF968 80314968 30D9FFFF */  andi  $t9, $a2, 0xffff
/* 0CF96C 8031496C 3C010180 */  lui   $at, 0x180
/* 0CF970 80314970 02801025 */  move  $v0, $s4
/* 0CF974 80314974 0321C025 */  or    $t8, $t9, $at
/* 0CF978 80314978 AC580004 */  sw    $t8, 4($v0)
/* 0CF97C 8031497C AC4E0000 */  sw    $t6, ($v0)
/* 0CF980 80314980 8FAF0148 */  lw    $t7, 0x148($sp)
/* 0CF984 80314984 26940008 */  addiu $s4, $s4, 8
/* 0CF988 80314988 3C010100 */  lui   $at, 0x100
/* 0CF98C 8031498C 31EE00FF */  andi  $t6, $t7, 0xff
/* 0CF990 80314990 000ECC00 */  sll   $t9, $t6, 0x10
/* 0CF994 80314994 0321C025 */  or    $t8, $t9, $at
/* 0CF998 80314998 02801825 */  move  $v1, $s4
/* 0CF99C 8031499C AC780000 */  sw    $t8, ($v1)
/* 0CF9A0 803149A0 8EEF0034 */  lw    $t7, 0x34($s7)
/* 0CF9A4 803149A4 0012C840 */  sll   $t9, $s2, 1
/* 0CF9A8 803149A8 26940008 */  addiu $s4, $s4, 8
/* 0CF9AC 803149AC 01FF7021 */  addu  $t6, $t7, $ra
/* 0CF9B0 803149B0 AC6E0004 */  sw    $t6, 4($v1)
/* 0CF9B4 803149B4 1000002F */  b     .L80314A74
/* 0CF9B8 803149B8 AFB90130 */   sw    $t9, 0x130($sp)
.L803149BC:
/* 0CF9BC 803149BC 24F803F0 */  addiu $t8, $a3, 0x3f0
/* 0CF9C0 803149C0 330FFFFF */  andi  $t7, $t8, 0xffff
/* 0CF9C4 803149C4 3C010800 */  lui   $at, 0x800
/* 0CF9C8 803149C8 01E17025 */  or    $t6, $t7, $at
/* 0CF9CC 803149CC 2401FFE0 */  li    $at, -32
/* 0CF9D0 803149D0 26A3001F */  addiu $v1, $s5, 0x1f
/* 0CF9D4 803149D4 0061C824 */  and   $t9, $v1, $at
/* 0CF9D8 803149D8 272F0180 */  addiu $t7, $t9, 0x180
/* 0CF9DC 803149DC 03201825 */  move  $v1, $t9
/* 0CF9E0 803149E0 AC4E0000 */  sw    $t6, ($v0)
/* 0CF9E4 803149E4 00103040 */  sll   $a2, $s0, 1
/* 0CF9E8 803149E8 30D9FFFF */  andi  $t9, $a2, 0xffff
/* 0CF9EC 803149EC 000F7400 */  sll   $t6, $t7, 0x10
/* 0CF9F0 803149F0 01D9C025 */  or    $t8, $t6, $t9
/* 0CF9F4 803149F4 AC580004 */  sw    $t8, 4($v0)
/* 0CF9F8 803149F8 8FAF0148 */  lw    $t7, 0x148($sp)
/* 0CF9FC 803149FC 26940008 */  addiu $s4, $s4, 8
/* 0CFA00 80314A00 3C010100 */  lui   $at, 0x100
/* 0CFA04 80314A04 31EE00FF */  andi  $t6, $t7, 0xff
/* 0CFA08 80314A08 000ECC00 */  sll   $t9, $t6, 0x10
/* 0CFA0C 80314A0C 0321C025 */  or    $t8, $t9, $at
/* 0CFA10 80314A10 02802025 */  move  $a0, $s4
/* 0CFA14 80314A14 AC980000 */  sw    $t8, ($a0)
/* 0CFA18 80314A18 8EEF0034 */  lw    $t7, 0x34($s7)
/* 0CFA1C 80314A1C 0012C840 */  sll   $t9, $s2, 1
/* 0CFA20 80314A20 0079C021 */  addu  $t8, $v1, $t9
/* 0CFA24 80314A24 01FF7021 */  addu  $t6, $t7, $ra
/* 0CFA28 80314A28 3C0100FF */  lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
/* 0CFA2C 80314A2C AC8E0004 */  sw    $t6, 4($a0)
/* 0CFA30 80314A30 3421FFFF */  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
/* 0CFA34 80314A34 270F0180 */  addiu $t7, $t8, 0x180
/* 0CFA38 80314A38 01E17024 */  and   $t6, $t7, $at
/* 0CFA3C 80314A3C 26940008 */  addiu $s4, $s4, 8
/* 0CFA40 80314A40 3C010A00 */  lui   $at, 0xa00
/* 0CFA44 80314A44 01C1C825 */  or    $t9, $t6, $at
/* 0CFA48 80314A48 02802825 */  move  $a1, $s4
/* 0CFA4C 80314A4C ACB90000 */  sw    $t9, ($a1)
/* 0CFA50 80314A50 0216C821 */  addu  $t9, $s0, $s6
/* 0CFA54 80314A54 26AF0180 */  addiu $t7, $s5, 0x180
/* 0CFA58 80314A58 000F7400 */  sll   $t6, $t7, 0x10
/* 0CFA5C 80314A5C 0333C023 */  subu  $t8, $t9, $s3
/* 0CFA60 80314A60 00187840 */  sll   $t7, $t8, 1
/* 0CFA64 80314A64 31F9FFFF */  andi  $t9, $t7, 0xffff
/* 0CFA68 80314A68 01D9C025 */  or    $t8, $t6, $t9
/* 0CFA6C 80314A6C ACB80004 */  sw    $t8, 4($a1)
/* 0CFA70 80314A70 26940008 */  addiu $s4, $s4, 8
.L80314A74:
/* 0CFA74 80314A74 8FB90148 */  lw    $t9, 0x148($sp)
/* 0CFA78 80314A78 03D07821 */  addu  $t7, $fp, $s0
/* 0CFA7C 80314A7C 01F67021 */  addu  $t6, $t7, $s6
/* 0CFA80 80314A80 24010001 */  li    $at, 1
/* 0CFA84 80314A84 13210008 */  beq   $t9, $at, .L80314AA8
/* 0CFA88 80314A88 01D3F023 */   subu  $fp, $t6, $s3
/* 0CFA8C 80314A8C 3B220002 */  xori  $v0, $t9, 2
/* 0CFA90 80314A90 0216C021 */  addu  $t8, $s0, $s6
/* 0CFA94 80314A94 03131823 */  subu  $v1, $t8, $s3
/* 0CFA98 80314A98 10400007 */  beqz  $v0, .L80314AB8
/* 0CFA9C 80314A9C AFA00148 */   sw    $zero, 0x148($sp)
/* 0CFAA0 80314AA0 10000008 */  b     .L80314AC4
/* 0CFAA4 80314AA4 00037040 */   sll   $t6, $v1, 1
.L80314AA8:
/* 0CFAA8 80314AA8 AFA00130 */  sw    $zero, 0x130($sp)
/* 0CFAAC 80314AAC 02A6A821 */  addu  $s5, $s5, $a2
/* 0CFAB0 80314AB0 1000000B */  b     .L80314AE0
/* 0CFAB4 80314AB4 AFA00148 */   sw    $zero, 0x148($sp)
.L80314AB8:
/* 0CFAB8 80314AB8 00037840 */  sll   $t7, $v1, 1
/* 0CFABC 80314ABC 10000008 */  b     .L80314AE0
/* 0CFAC0 80314AC0 02AFA821 */   addu  $s5, $s5, $t7
.L80314AC4:
/* 0CFAC4 80314AC4 52A00004 */  beql  $s5, $zero, .L80314AD8
/* 0CFAC8 80314AC8 0072A821 */   addu  $s5, $v1, $s2
/* 0CFACC 80314ACC 10000004 */  b     .L80314AE0
/* 0CFAD0 80314AD0 02AEA821 */   addu  $s5, $s5, $t6
/* 0CFAD4 80314AD4 0072A821 */  addu  $s5, $v1, $s2
.L80314AD8:
/* 0CFAD8 80314AD8 0015C840 */  sll   $t9, $s5, 1
/* 0CFADC 80314ADC 0320A825 */  move  $s5, $t9
.L80314AE0:
/* 0CFAE0 80314AE0 11400014 */  beqz  $t2, .L80314B34
/* 0CFAE4 80314AE4 3C0100FF */   lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
/* 0CFAE8 80314AE8 3421FFFF */  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
/* 0CFAEC 80314AEC 26B80180 */  addiu $t8, $s5, 0x180
/* 0CFAF0 80314AF0 03017824 */  and   $t7, $t8, $at
/* 0CFAF4 80314AF4 3C010200 */  lui   $at, 0x200
/* 0CFAF8 80314AF8 02801025 */  move  $v0, $s4
/* 0CFAFC 80314AFC 01BEC823 */  subu  $t9, $t5, $fp
/* 0CFB00 80314B00 0019C040 */  sll   $t8, $t9, 1
/* 0CFB04 80314B04 01E17025 */  or    $t6, $t7, $at
/* 0CFB08 80314B08 AC4E0000 */  sw    $t6, ($v0)
/* 0CFB0C 80314B0C AC580004 */  sw    $t8, 4($v0)
/* 0CFB10 80314B10 92EE0000 */  lbu   $t6, ($s7)
/* 0CFB14 80314B14 26940008 */  addiu $s4, $s4, 8
/* 0CFB18 80314B18 AEE00014 */  sw    $zero, 0x14($s7)
/* 0CFB1C 80314B1C 35D90010 */  ori   $t9, $t6, 0x10
/* 0CFB20 80314B20 A2F90000 */  sb    $t9, ($s7)
/* 0CFB24 80314B24 92F80000 */  lbu   $t8, ($s7)
/* 0CFB28 80314B28 330FFF7F */  andi  $t7, $t8, 0xff7f
/* 0CFB2C 80314B2C 1000000F */  b     .L80314B6C
/* 0CFB30 80314B30 A2EF0000 */   sb    $t7, ($s7)
.L80314B34:
/* 0CFB34 80314B34 51600009 */  beql  $t3, $zero, .L80314B5C
/* 0CFB38 80314B38 8EF90014 */   lw    $t9, 0x14($s7)
/* 0CFB3C 80314B3C 92F90000 */  lbu   $t9, ($s7)
/* 0CFB40 80314B40 37380020 */  ori   $t8, $t9, 0x20
/* 0CFB44 80314B44 A2F80000 */  sb    $t8, ($s7)
/* 0CFB48 80314B48 8FAF0160 */  lw    $t7, 0x160($sp)
/* 0CFB4C 80314B4C 8DEE0000 */  lw    $t6, ($t7)
/* 0CFB50 80314B50 10000004 */  b     .L80314B64
/* 0CFB54 80314B54 AEEE0014 */   sw    $t6, 0x14($s7)
/* 0CFB58 80314B58 8EF90014 */  lw    $t9, 0x14($s7)
.L80314B5C:
/* 0CFB5C 80314B5C 032CC021 */  addu  $t8, $t9, $t4
/* 0CFB60 80314B60 AEF80014 */  sw    $t8, 0x14($s7)
.L80314B64:
/* 0CFB64 80314B64 57CDFF03 */  bnel  $fp, $t5, .L80314774
/* 0CFB68 80314B68 8EE90014 */   lw    $t1, 0x14($s7)
.L80314B6C:
/* 0CFB6C 80314B6C 8FAF0054 */  lw    $t7, 0x54($sp)
/* 0CFB70 80314B70 8FAE00E8 */  lw    $t6, 0xe8($sp)
/* 0CFB74 80314B74 24010002 */  li    $at, 2
/* 0CFB78 80314B78 15E00008 */  bnez  $t7, .L80314B9C
/* 0CFB7C 80314B7C 8FB80130 */   lw    $t8, 0x130($sp)
/* 0CFB80 80314B80 11C1000D */  beq   $t6, $at, .L80314BB8
/* 0CFB84 80314B84 8FB900E4 */   lw    $t9, 0xe4($sp)
/* 0CFB88 80314B88 8EE50000 */  lw    $a1, ($s7)
/* 0CFB8C 80314B8C 000530C0 */  sll   $a2, $a1, 3
/* 0CFB90 80314B90 0006CFC2 */  srl   $t9, $a2, 0x1f
/* 0CFB94 80314B94 10000066 */  b     .L80314D30
/* 0CFB98 80314B98 03203025 */   move  $a2, $t9
.L80314B9C:
/* 0CFB9C 80314B9C 270F0180 */  addiu $t7, $t8, 0x180
/* 0CFBA0 80314BA0 A7AF00D6 */  sh    $t7, 0xd6($sp)
/* 0CFBA4 80314BA4 8EE50000 */  lw    $a1, ($s7)
/* 0CFBA8 80314BA8 000530C0 */  sll   $a2, $a1, 3
/* 0CFBAC 80314BAC 000677C2 */  srl   $t6, $a2, 0x1f
/* 0CFBB0 80314BB0 1000005F */  b     .L80314D30
/* 0CFBB4 80314BB4 01C03025 */   move  $a2, $t6
.L80314BB8:
/* 0CFBB8 80314BB8 13200009 */  beqz  $t9, .L80314BE0
/* 0CFBBC 80314BBC 02801025 */   move  $v0, $s4
/* 0CFBC0 80314BC0 24010001 */  li    $at, 1
/* 0CFBC4 80314BC4 13210034 */  beq   $t9, $at, .L80314C98
/* 0CFBC8 80314BC8 02801025 */   move  $v0, $s4
/* 0CFBCC 80314BCC 8EE50000 */  lw    $a1, ($s7)
/* 0CFBD0 80314BD0 000530C0 */  sll   $a2, $a1, 3
/* 0CFBD4 80314BD4 0006C7C2 */  srl   $t8, $a2, 0x1f
/* 0CFBD8 80314BD8 10000055 */  b     .L80314D30
/* 0CFBDC 80314BDC 03003025 */   move  $a2, $t8
.L80314BE0:
/* 0CFBE0 80314BE0 8FAF0130 */  lw    $t7, 0x130($sp)
/* 0CFBE4 80314BE4 3C010800 */  lui   $at, 0x800
/* 0CFBE8 80314BE8 25A30004 */  addiu $v1, $t5, 4
/* 0CFBEC 80314BEC 25EE0180 */  addiu $t6, $t7, 0x180
/* 0CFBF0 80314BF0 31D9FFFF */  andi  $t9, $t6, 0xffff
/* 0CFBF4 80314BF4 0321C025 */  or    $t8, $t9, $at
/* 0CFBF8 80314BF8 3C010020 */  lui   $at, 0x20
/* 0CFBFC 80314BFC 306FFFFF */  andi  $t7, $v1, 0xffff
/* 0CFC00 80314C00 01E17025 */  or    $t6, $t7, $at
/* 0CFC04 80314C04 26940008 */  addiu $s4, $s4, 8
/* 0CFC08 80314C08 3C190501 */  lui   $t9, (0x0501FF60 >> 16) # lui $t9, 0x501
/* 0CFC0C 80314C0C AC4E0004 */  sw    $t6, 4($v0)
/* 0CFC10 80314C10 AC580000 */  sw    $t8, ($v0)
/* 0CFC14 80314C14 3739FF60 */  ori   $t9, (0x0501FF60 & 0xFFFF) # ori $t9, $t9, 0xff60
/* 0CFC18 80314C18 02802025 */  move  $a0, $s4
/* 0CFC1C 80314C1C AC990000 */  sw    $t9, ($a0)
/* 0CFC20 80314C20 8EF80034 */  lw    $t8, 0x34($s7)
/* 0CFC24 80314C24 3C018000 */  lui   $at, (0x800000F0 >> 16) # lui $at, 0x8000
/* 0CFC28 80314C28 342100F0 */  ori   $at, (0x800000F0 & 0xFFFF) # ori $at, $at, 0xf0
/* 0CFC2C 80314C2C 03017821 */  addu  $t7, $t8, $at
/* 0CFC30 80314C30 AC8F0004 */  sw    $t7, 4($a0)
/* 0CFC34 80314C34 240E0024 */  li    $t6, 36
/* 0CFC38 80314C38 AFA300D8 */  sw    $v1, 0xd8($sp)
/* 0CFC3C 80314C3C A7AE00D6 */  sh    $t6, 0xd6($sp)
/* 0CFC40 80314C40 8EE50000 */  lw    $a1, ($s7)
/* 0CFC44 80314C44 26940008 */  addiu $s4, $s4, 8
/* 0CFC48 80314C48 02801025 */  move  $v0, $s4
/* 0CFC4C 80314C4C 000530C0 */  sll   $a2, $a1, 3
/* 0CFC50 80314C50 0006CFC2 */  srl   $t9, $a2, 0x1f
/* 0CFC54 80314C54 13200036 */  beqz  $t9, .L80314D30
/* 0CFC58 80314C58 03203025 */   move  $a2, $t9
/* 0CFC5C 80314C5C 3C0100FF */  lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
/* 0CFC60 80314C60 3421FFFF */  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
/* 0CFC64 80314C64 25B80024 */  addiu $t8, $t5, 0x24
/* 0CFC68 80314C68 03017824 */  and   $t7, $t8, $at
/* 0CFC6C 80314C6C 3C010200 */  lui   $at, 0x200
/* 0CFC70 80314C70 01E17025 */  or    $t6, $t7, $at
/* 0CFC74 80314C74 25B90010 */  addiu $t9, $t5, 0x10
/* 0CFC78 80314C78 AC590004 */  sw    $t9, 4($v0)
/* 0CFC7C 80314C7C AC4E0000 */  sw    $t6, ($v0)
/* 0CFC80 80314C80 8EE50000 */  lw    $a1, ($s7)
/* 0CFC84 80314C84 26940008 */  addiu $s4, $s4, 8
/* 0CFC88 80314C88 000530C0 */  sll   $a2, $a1, 3
/* 0CFC8C 80314C8C 0006C7C2 */  srl   $t8, $a2, 0x1f
/* 0CFC90 80314C90 10000027 */  b     .L80314D30
/* 0CFC94 80314C94 03003025 */   move  $a2, $t8
.L80314C98:
/* 0CFC98 80314C98 8FAF0130 */  lw    $t7, 0x130($sp)
/* 0CFC9C 80314C9C 3C010800 */  lui   $at, 0x800
/* 0CFCA0 80314CA0 26940008 */  addiu $s4, $s4, 8
/* 0CFCA4 80314CA4 25EE0180 */  addiu $t6, $t7, 0x180
/* 0CFCA8 80314CA8 31D9FFFF */  andi  $t9, $t6, 0xffff
/* 0CFCAC 80314CAC 0321C025 */  or    $t8, $t9, $at
/* 0CFCB0 80314CB0 25AF0008 */  addiu $t7, $t5, 8
/* 0CFCB4 80314CB4 31EEFFFF */  andi  $t6, $t7, 0xffff
/* 0CFCB8 80314CB8 AC580000 */  sw    $t8, ($v0)
/* 0CFCBC 80314CBC 3C010160 */  lui   $at, 0x160
/* 0CFCC0 80314CC0 01C1C825 */  or    $t9, $t6, $at
/* 0CFCC4 80314CC4 3C180501 */  lui   $t8, (0x0501FF60 >> 16) # lui $t8, 0x501
/* 0CFCC8 80314CC8 AC590004 */  sw    $t9, 4($v0)
/* 0CFCCC 80314CCC 3718FF60 */  ori   $t8, (0x0501FF60 & 0xFFFF) # ori $t8, $t8, 0xff60
/* 0CFCD0 80314CD0 02801825 */  move  $v1, $s4
/* 0CFCD4 80314CD4 AC780000 */  sw    $t8, ($v1)
/* 0CFCD8 80314CD8 8EEF0034 */  lw    $t7, 0x34($s7)
/* 0CFCDC 80314CDC 3C018000 */  lui   $at, (0x800000F0 >> 16) # lui $at, 0x8000
/* 0CFCE0 80314CE0 342100F0 */  ori   $at, (0x800000F0 & 0xFFFF) # ori $at, $at, 0xf0
/* 0CFCE4 80314CE4 26940008 */  addiu $s4, $s4, 8
/* 0CFCE8 80314CE8 3C190A00 */  lui   $t9, (0x0A000164 >> 16) # lui $t9, 0xa00
/* 0CFCEC 80314CEC 01E17021 */  addu  $t6, $t7, $at
/* 0CFCF0 80314CF0 AC6E0004 */  sw    $t6, 4($v1)
/* 0CFCF4 80314CF4 37390164 */  ori   $t9, (0x0A000164 & 0xFFFF) # ori $t9, $t9, 0x164
/* 0CFCF8 80314CF8 02802025 */  move  $a0, $s4
/* 0CFCFC 80314CFC AC990000 */  sw    $t9, ($a0)
/* 0CFD00 80314D00 8FB800D8 */  lw    $t8, 0xd8($sp)
/* 0CFD04 80314D04 26940008 */  addiu $s4, $s4, 8
/* 0CFD08 80314D08 270E0020 */  addiu $t6, $t8, 0x20
/* 0CFD0C 80314D0C 25B80004 */  addiu $t8, $t5, 4
/* 0CFD10 80314D10 330FFFFF */  andi  $t7, $t8, 0xffff
/* 0CFD14 80314D14 000ECC00 */  sll   $t9, $t6, 0x10
/* 0CFD18 80314D18 032F7025 */  or    $t6, $t9, $t7
/* 0CFD1C 80314D1C AC8E0004 */  sw    $t6, 4($a0)
/* 0CFD20 80314D20 8EE50000 */  lw    $a1, ($s7)
/* 0CFD24 80314D24 000530C0 */  sll   $a2, $a1, 3
/* 0CFD28 80314D28 0006C7C2 */  srl   $t8, $a2, 0x1f
/* 0CFD2C 80314D2C 03003025 */  move  $a2, $t8
.L80314D30:
/* 0CFD30 80314D30 10C00003 */  beqz  $a2, .L80314D40
/* 0CFD34 80314D34 8FA200E4 */   lw    $v0, 0xe4($sp)
/* 0CFD38 80314D38 10000008 */  b     .L80314D5C
/* 0CFD3C 80314D3C AFA00148 */   sw    $zero, 0x148($sp)
.L80314D40:
/* 0CFD40 80314D40 8FB900E8 */  lw    $t9, 0xe8($sp)
/* 0CFD44 80314D44 24420001 */  addiu $v0, $v0, 1
/* 0CFD48 80314D48 AFA200E4 */  sw    $v0, 0xe4($sp)
/* 0CFD4C 80314D4C 5459FE5D */  bnel  $v0, $t9, .L803146C4
/* 0CFD50 80314D50 8FA60164 */   lw    $a2, 0x164($sp)
.L80314D54:
/* 0CFD54 80314D54 AFA00148 */  sw    $zero, 0x148($sp)
/* 0CFD58 80314D58 8EE50000 */  lw    $a1, ($s7)
.L80314D5C:
/* 0CFD5C 80314D5C 00057840 */  sll   $t7, $a1, 1
/* 0CFD60 80314D60 000F77C2 */  srl   $t6, $t7, 0x1f
/* 0CFD64 80314D64 24010001 */  li    $at, 1
/* 0CFD68 80314D68 15C10006 */  bne   $t6, $at, .L80314D84
/* 0CFD6C 80314D6C 02802025 */   move  $a0, $s4
/* 0CFD70 80314D70 24180001 */  li    $t8, 1
/* 0CFD74 80314D74 AFB80148 */  sw    $t8, 0x148($sp)
/* 0CFD78 80314D78 92F90000 */  lbu   $t9, ($s7)
/* 0CFD7C 80314D7C 332FFFBF */  andi  $t7, $t9, 0xffbf
/* 0CFD80 80314D80 A2EF0000 */  sb    $t7, ($s7)
.L80314D84:
/* 0CFD84 80314D84 8FB10048 */  lw    $s1, 0x48($sp)
/* 0CFD88 80314D88 97AE00D6 */  lhu   $t6, 0xd6($sp)
/* 0CFD8C 80314D8C 8FB80148 */  lw    $t8, 0x148($sp)
/* 0CFD90 80314D90 02E02825 */  move  $a1, $s7
/* 0CFD94 80314D94 97A7005E */  lhu   $a3, 0x5e($sp)
/* 0CFD98 80314D98 02203025 */  move  $a2, $s1
/* 0CFD9C 80314D9C AFAE0010 */  sw    $t6, 0x10($sp)
/* 0CFDA0 80314DA0 0C0C53F5 */  jal   func_80314FD4
/* 0CFDA4 80314DA4 AFB80014 */   sw    $t8, 0x14($sp)
/* 0CFDA8 80314DA8 96F9000C */  lhu   $t9, 0xc($s7)
/* 0CFDAC 80314DAC 0040A025 */  move  $s4, $v0
/* 0CFDB0 80314DB0 02802025 */  move  $a0, $s4
/* 0CFDB4 80314DB4 17200004 */  bnez  $t9, .L80314DC8
/* 0CFDB8 80314DB8 02E02825 */   move  $a1, $s7
/* 0CFDBC 80314DBC 96EF0010 */  lhu   $t7, 0x10($s7)
/* 0CFDC0 80314DC0 51E00004 */  beql  $t7, $zero, .L80314DD4
/* 0CFDC4 80314DC4 96EE000E */   lhu   $t6, 0xe($s7)
.L80314DC8:
/* 0CFDC8 80314DC8 1000000A */  b     .L80314DF4
/* 0CFDCC 80314DCC 24100001 */   li    $s0, 1
/* 0CFDD0 80314DD0 96EE000E */  lhu   $t6, 0xe($s7)
.L80314DD4:
/* 0CFDD4 80314DD4 15C00005 */  bnez  $t6, .L80314DEC
/* 0CFDD8 80314DD8 00000000 */   nop   
/* 0CFDDC 80314DDC 96F80012 */  lhu   $t8, 0x12($s7)
/* 0CFDE0 80314DE0 00008025 */  move  $s0, $zero
/* 0CFDE4 80314DE4 13000003 */  beqz  $t8, .L80314DF4
/* 0CFDE8 80314DE8 00000000 */   nop   
.L80314DEC:
/* 0CFDEC 80314DEC 10000001 */  b     .L80314DF4
/* 0CFDF0 80314DF0 24100002 */   li    $s0, 2
.L80314DF4:
/* 0CFDF4 80314DF4 8FB90148 */  lw    $t9, 0x148($sp)
/* 0CFDF8 80314DF8 8FA6017C */  lw    $a2, 0x17c($sp)
/* 0CFDFC 80314DFC 00003825 */  move  $a3, $zero
/* 0CFE00 80314E00 AFB00010 */  sw    $s0, 0x10($sp)
/* 0CFE04 80314E04 0C0C540C */  jal   func_80315030
/* 0CFE08 80314E08 AFB90014 */   sw    $t9, 0x14($sp)
/* 0CFE0C 80314E0C 92EF0001 */  lbu   $t7, 1($s7)
/* 0CFE10 80314E10 3C1F8000 */  lui   $ra, 0x8000
/* 0CFE14 80314E14 0040A025 */  move  $s4, $v0
/* 0CFE18 80314E18 11E00008 */  beqz  $t7, .L80314E3C
/* 0CFE1C 80314E1C 00402025 */   move  $a0, $v0
/* 0CFE20 80314E20 02E02825 */  move  $a1, $s7
/* 0CFE24 80314E24 02203025 */  move  $a2, $s1
/* 0CFE28 80314E28 8FA70148 */  lw    $a3, 0x148($sp)
/* 0CFE2C 80314E2C 0C0C557D */  jal   func_803155F4
/* 0CFE30 80314E30 AFB00010 */   sw    $s0, 0x10($sp)
/* 0CFE34 80314E34 3C1F8000 */  lui   $ra, 0x8000
/* 0CFE38 80314E38 0040A025 */  move  $s4, $v0
.L80314E3C:
/* 0CFE3C 80314E3C 8FAE0174 */  lw    $t6, 0x174($sp)
.L80314E40:
/* 0CFE40 80314E40 8FB9006C */  lw    $t9, 0x6c($sp)
/* 0CFE44 80314E44 25D80001 */  addiu $t8, $t6, 1
/* 0CFE48 80314E48 3C0E8022 */  lui   $t6, %hi(D_80226D70) # $t6, 0x8022
/* 0CFE4C 80314E4C 8DCE6D70 */  lw    $t6, %lo(D_80226D70)($t6)
/* 0CFE50 80314E50 272F00C0 */  addiu $t7, $t9, 0xc0
/* 0CFE54 80314E54 AFAF006C */  sw    $t7, 0x6c($sp)
/* 0CFE58 80314E58 030E082A */  slt   $at, $t8, $t6
/* 0CFE5C 80314E5C 1420FD9D */  bnez  $at, .L803144D4
/* 0CFE60 80314E60 AFB80174 */   sw    $t8, 0x174($sp)
.L80314E64:
/* 0CFE64 80314E64 3C080800 */  lui   $t0, 0x800
/* 0CFE68 80314E68 02802025 */  move  $a0, $s4
/* 0CFE6C 80314E6C AC880000 */  sw    $t0, ($a0)
/* 0CFE70 80314E70 8FA3017C */  lw    $v1, 0x17c($sp)
/* 0CFE74 80314E74 26940008 */  addiu $s4, $s4, 8
/* 0CFE78 80314E78 02802825 */  move  $a1, $s4
/* 0CFE7C 80314E7C 0003C840 */  sll   $t9, $v1, 1
/* 0CFE80 80314E80 332FFFFF */  andi  $t7, $t9, 0xffff
/* 0CFE84 80314E84 AC8F0004 */  sw    $t7, 4($a0)
/* 0CFE88 80314E88 26940008 */  addiu $s4, $s4, 8
/* 0CFE8C 80314E8C 3C180D00 */  lui   $t8, 0xd00
/* 0CFE90 80314E90 3C0E04C0 */  lui   $t6, (0x04C00600 >> 16) # lui $t6, 0x4c0
/* 0CFE94 80314E94 35CE0600 */  ori   $t6, (0x04C00600 & 0xFFFF) # ori $t6, $t6, 0x600
/* 0CFE98 80314E98 ACB80000 */  sw    $t8, ($a1)
/* 0CFE9C 80314E9C 02803025 */  move  $a2, $s4
/* 0CFEA0 80314EA0 ACAE0004 */  sw    $t6, 4($a1)
/* 0CFEA4 80314EA4 0019C840 */  sll   $t9, $t9, 1
/* 0CFEA8 80314EA8 332FFFFF */  andi  $t7, $t9, 0xffff
/* 0CFEAC 80314EAC 26940008 */  addiu $s4, $s4, 8
/* 0CFEB0 80314EB0 ACCF0004 */  sw    $t7, 4($a2)
/* 0CFEB4 80314EB4 ACC80000 */  sw    $t0, ($a2)
/* 0CFEB8 80314EB8 02803825 */  move  $a3, $s4
/* 0CFEBC 80314EBC 3C180600 */  lui   $t8, 0x600
/* 0CFEC0 80314EC0 ACF80000 */  sw    $t8, ($a3)
/* 0CFEC4 80314EC4 8FAE0178 */  lw    $t6, 0x178($sp)
/* 0CFEC8 80314EC8 3C1F8000 */  lui   $ra, 0x8000
/* 0CFECC 80314ECC 26820008 */  addiu $v0, $s4, 8
/* 0CFED0 80314ED0 01DFC821 */  addu  $t9, $t6, $ra
/* 0CFED4 80314ED4 ACF90004 */  sw    $t9, 4($a3)
/* 0CFED8 80314ED8 8FBF0044 */  lw    $ra, 0x44($sp)
/* 0CFEDC 80314EDC 8FBE0040 */  lw    $fp, 0x40($sp)
/* 0CFEE0 80314EE0 8FB7003C */  lw    $s7, 0x3c($sp)
/* 0CFEE4 80314EE4 8FB60038 */  lw    $s6, 0x38($sp)
/* 0CFEE8 80314EE8 8FB50034 */  lw    $s5, 0x34($sp)
/* 0CFEEC 80314EEC 8FB40030 */  lw    $s4, 0x30($sp)
/* 0CFEF0 80314EF0 8FB3002C */  lw    $s3, 0x2c($sp)
/* 0CFEF4 80314EF4 8FB20028 */  lw    $s2, 0x28($sp)
/* 0CFEF8 80314EF8 8FB10024 */  lw    $s1, 0x24($sp)
/* 0CFEFC 80314EFC 8FB00020 */  lw    $s0, 0x20($sp)
/* 0CFF00 80314F00 03E00008 */  jr    $ra
/* 0CFF04 80314F04 27BD0178 */   addiu $sp, $sp, 0x178
)
#else
GLOBAL_ASM(

.late_rodata
glabel D_80337BB0
    .word 0x3FFFFEB0, 0x3FFFFEB0 
glabel D_80337BB8
    .word 0x407FFEDA, 0x407FFEDA 
.text

glabel func_80314480

/* 0D0590 80315590 27BDFE90 */  addiu $sp, $sp, -0x170
/* 0D0594 80315594 3C0E8022 */  lui   $t6, %hi(D_80226D70) # $t6, 0x8022
/* 0D0598 80315598 8DCE6B70 */  lw    $t6, %lo(D_80226D70)($t6)
/* 0D059C 8031559C AFB40030 */  sw    $s4, 0x30($sp)
/* 0D05A0 803155A0 00C0A025 */  move  $s4, $a2
/* 0D05A4 803155A4 AFBF0044 */  sw    $ra, 0x44($sp)
/* 0D05A8 803155A8 AFBE0040 */  sw    $fp, 0x40($sp)
/* 0D05AC 803155AC AFB7003C */  sw    $s7, 0x3c($sp)
/* 0D05B0 803155B0 AFB60038 */  sw    $s6, 0x38($sp)
/* 0D05B4 803155B4 AFB50034 */  sw    $s5, 0x34($sp)
/* 0D05B8 803155B8 AFB3002C */  sw    $s3, 0x2c($sp)
/* 0D05BC 803155BC AFB20028 */  sw    $s2, 0x28($sp)
/* 0D05C0 803155C0 AFB10024 */  sw    $s1, 0x24($sp)
/* 0D05C4 803155C4 AFB00020 */  sw    $s0, 0x20($sp)
/* 0D05C8 803155C8 AFA40170 */  sw    $a0, 0x170($sp)
/* 0D05CC 803155CC AFA50174 */  sw    $a1, 0x174($sp)
/* 0D05D0 803155D0 AFA0016C */  sw    $zero, 0x16c($sp)
/* 0D05D4 803155D4 19C00265 */  blez  $t6, .L_US_80315F6C
/* 0D05D8 803155D8 AFA00154 */   sw    $zero, 0x154($sp)
/* 0D05DC 803155DC AFA00064 */  sw    $zero, 0x64($sp)
.L_US_803155E0:
/* 0D05E0 803155E0 3C188022 */  lui   $t8, %hi(D_80222A10) # $t8, 0x8022
/* 0D05E4 803155E4 8F182610 */  lw    $t8, %lo(D_80222A10)($t8)
/* 0D05E8 803155E8 8FAF0064 */  lw    $t7, 0x64($sp)
/* 0D05EC 803155EC 01F8B821 */  addu  $s7, $t7, $t8
/* 0D05F0 803155F0 8EF90000 */  lw    $t9, ($s7)
/* 0D05F4 803155F4 001977C2 */  srl   $t6, $t9, 0x1f
/* 0D05F8 803155F8 51C00010 */  beql  $t6, $zero, .L_US_8031563C
/* 0D05FC 803155FC 8EF90000 */   lw    $t9, ($s7)
/* 0D0600 80315600 92E20007 */  lbu   $v0, 7($s7)
/* 0D0604 80315604 3C0F8022 */  lui   $t7, %hi(D_802218D0)
/* 0D0608 80315608 8FAE016C */  lw    $t6, 0x16c($sp)
/* 0D060C 8031560C 01E27821 */  addu  $t7, $t7, $v0
/* 0D0610 80315610 91EF14D0 */  lbu   $t7, %lo(D_802218D0)($t7)
/* 0D0614 80315614 3C010100 */  lui   $at, 0x100
/* 0D0618 80315618 29F80002 */  slti  $t8, $t7, 2
/* 0D061C 8031561C 13000006 */  beqz  $t8, .L_US_80315638
/* 0D0620 80315620 0002CA00 */   sll   $t9, $v0, 8
/* 0D0624 80315624 032E7821 */  addu  $t7, $t9, $t6
/* 0D0628 80315628 01E1C021 */  addu  $t8, $t7, $at
/* 0D062C 8031562C 3C018033 */  lui   $at, %hi(D_80331D40) # $at, 0x8033
/* 0D0630 80315630 10000244 */  b     .L_US_80315F44
/* 0D0634 80315634 AC382E50 */   sw    $t8, %lo(D_80331D40)($at)
.L_US_80315638:
/* 0D0638 80315638 8EF90000 */  lw    $t9, ($s7)
.L_US_8031563C:
/* 0D063C 8031563C 001977C2 */  srl   $t6, $t9, 0x1f
/* 0D0640 80315640 51C00241 */  beql  $t6, $zero, .L_US_80315F48
/* 0D0644 80315644 8FB9016C */   lw    $t9, 0x16c($sp)
/* 0D0648 80315648 8FAF0174 */  lw    $t7, 0x174($sp)
/* 0D064C 8031564C AFA00140 */  sw    $zero, 0x140($sp)
/* 0D0650 80315650 24010001 */  li    $at, 1
/* 0D0654 80315654 000FC040 */  sll   $t8, $t7, 1
/* 0D0658 80315658 AFB80048 */  sw    $t8, 0x48($sp)
/* 0D065C 8031565C 8EF90000 */  lw    $t9, ($s7)
/* 0D0660 80315660 24180001 */  li    $t8, 1
/* 0D0664 80315664 02802025 */  move  $a0, $s4
/* 0D0668 80315668 00197040 */  sll   $t6, $t9, 1
/* 0D066C 8031566C 000E7FC2 */  srl   $t7, $t6, 0x1f
/* 0D0670 80315670 15E10004 */  bne   $t7, $at, .L_US_80315684
/* 0D0674 80315674 02E02825 */   move  $a1, $s7
/* 0D0678 80315678 AFB80140 */  sw    $t8, 0x140($sp)
/* 0D067C 8031567C AEE00014 */  sw    $zero, 0x14($s7)
/* 0D0680 80315680 A6E00020 */  sh    $zero, 0x20($s7)
.L_US_80315684:
/* 0D0684 80315684 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0D0688 80315688 44812000 */  mtc1  $at, $f4
/* 0D068C 8031568C C6E00038 */  lwc1  $f0, 0x38($s7)
/* 0D0690 80315690 3C018034 */  lui   $at, %hi(D_80337BB8)
/* 0D0694 80315694 4604003C */  c.lt.s $f0, $f4
/* 0D0698 80315698 00000000 */  nop   
/* 0D069C 8031569C 4500000E */  bc1f  .L_US_803156D8
/* 0D06A0 803156A0 00000000 */   nop   
/* 0D06A4 803156A4 3C018034 */  lui   $at, %hi(D_80337BB0) # $at, 0x8034
/* 0D06A8 803156A8 C4268DA0 */  lwc1  $f6, %lo(D_80337BB0)($at)
/* 0D06AC 803156AC 24190001 */  li    $t9, 1
/* 0D06B0 803156B0 AFB900E0 */  sw    $t9, 0xe0($sp)
/* 0D06B4 803156B4 4600303C */  c.lt.s $f6, $f0
/* 0D06B8 803156B8 3C018034 */  lui   $at, %hi(D_80337BB0 + 0x4) # $at, 0x8034
/* 0D06BC 803156BC 45000004 */  bc1f  .L_US_803156D0
/* 0D06C0 803156C0 00000000 */   nop   
/* 0D06C4 803156C4 C4288DA4 */  lwc1  $f8, %lo(D_80337BB0 + 0x4)($at)
/* 0D06C8 803156C8 E6E80038 */  swc1  $f8, 0x38($s7)
/* 0D06CC 803156CC C6E00038 */  lwc1  $f0, 0x38($s7)
.L_US_803156D0:
/* 0D06D0 803156D0 10000010 */  b     .L_US_80315714
/* 0D06D4 803156D4 46000086 */   mov.s $f2, $f0
.L_US_803156D8:
/* 0D06D8 803156D8 C42A8DA8 */  lwc1  $f10, %lo(D_80337BB8)($at)
/* 0D06DC 803156DC 240E0002 */  li    $t6, 2
/* 0D06E0 803156E0 AFAE00E0 */  sw    $t6, 0xe0($sp)
/* 0D06E4 803156E4 4600503E */  c.le.s $f10, $f0
/* 0D06E8 803156E8 3C018034 */  lui   $at, %hi(D_80337BB8)
/* 0D06EC 803156EC 45020005 */  bc1fl .L_US_80315704
/* 0D06F0 803156F0 3C013F00 */   lui   $at, 0x3f00 # $at, 0x3f00
/* 0D06F4 803156F4 C4308DAC */  lwc1  $f16, %lo(D_80337BB8 + 0x4)($at)
/* 0D06F8 803156F8 E6F00038 */  swc1  $f16, 0x38($s7)
/* 0D06FC 803156FC C6E00038 */  lwc1  $f0, 0x38($s7)
/* 0D0700 80315700 3C013F00 */  li    $at, 0x3F000000 # 0.500000
.L_US_80315704:
/* 0D0704 80315704 44819000 */  mtc1  $at, $f18
/* 0D0708 80315708 00000000 */  nop   
/* 0D070C 8031570C 46120082 */  mul.s $f2, $f0, $f18
/* 0D0710 80315710 00000000 */  nop   
.L_US_80315714:
/* 0D0714 80315714 3C014700 */  li    $at, 0x47000000 # 32768.000000
/* 0D0718 80315718 44812000 */  mtc1  $at, $f4
/* 0D071C 8031571C 8FAE0174 */  lw    $t6, 0x174($sp)
/* 0D0720 80315720 46041182 */  mul.s $f6, $f2, $f4
/* 0D0724 80315724 4600320D */  trunc.w.s $f8, $f6
/* 0D0728 80315728 44184000 */  mfc1  $t8, $f8
/* 0D072C 8031572C 00000000 */  nop   
/* 0D0730 80315730 3319FFFF */  andi  $t9, $t8, 0xffff
/* 0D0734 80315734 032E0019 */  multu $t9, $t6
/* 0D0738 80315738 AFB9005C */  sw    $t9, 0x5c($sp)
/* 0D073C 8031573C 96F90020 */  lhu   $t9, 0x20($s7)
/* 0D0740 80315740 8EE20024 */  lw    $v0, 0x24($s7)
/* 0D0744 80315744 00007812 */  mflo  $t7
/* 0D0748 80315748 000FC040 */  sll   $t8, $t7, 1
/* 0D074C 8031574C 03381821 */  addu  $v1, $t9, $t8
/* 0D0750 80315750 1440000E */  bnez  $v0, .L_US_8031578C
/* 0D0754 80315754 A6E30020 */   sh    $v1, 0x20($s7)
/* 0D0758 80315758 00038402 */  srl   $s0, $v1, 0x10
/* 0D075C 8031575C 02003025 */  move  $a2, $s0
/* 0D0760 80315760 0C0C5804 */  jal   func_80314F08
/* 0D0764 80315764 AFA00140 */   sw    $zero, 0x140($sp)
/* 0D0768 80315768 8EE90014 */  lw    $t1, 0x14($s7)
/* 0D076C 8031576C 0040A025 */  move  $s4, $v0
/* 0D0770 80315770 00097840 */  sll   $t7, $t1, 1
/* 0D0774 80315774 25F90180 */  addiu $t9, $t7, 0x180
/* 0D0778 80315778 A7B900CE */  sh    $t9, 0xce($sp)
/* 0D077C 8031577C 0130C021 */  addu  $t8, $t1, $s0
/* 0D0780 80315780 AEF80014 */  sw    $t8, 0x14($s7)
/* 0D0784 80315784 100001B9 */  b     .L_US_80315E6C
/* 0D0788 80315788 8EE50000 */   lw    $a1, ($s7)
.L_US_8031578C:
/* 0D078C 8031578C 8C4E0000 */  lw    $t6, ($v0)
/* 0D0790 80315790 00031402 */  srl   $v0, $v1, 0x10
/* 0D0794 80315794 AFAE015C */  sw    $t6, 0x15c($sp)
/* 0D0798 80315798 8DDF0008 */  lw    $ra, 8($t6)
/* 0D079C 8031579C 8FF90004 */  lw    $t9, 4($ra)
/* 0D07A0 803157A0 AFB90108 */  sw    $t9, 0x108($sp)
/* 0D07A4 803157A4 8DD80004 */  lw    $t8, 4($t6)
/* 0D07A8 803157A8 8FAE00E0 */  lw    $t6, 0xe0($sp)
/* 0D07AC 803157AC AFA000D0 */  sw    $zero, 0xd0($sp)
/* 0D07B0 803157B0 AFA000DC */  sw    $zero, 0xdc($sp)
/* 0D07B4 803157B4 19C001AB */  blez  $t6, .L_US_80315E64
/* 0D07B8 803157B8 AFB80118 */   sw    $t8, 0x118($sp)
/* 0D07BC 803157BC 39D90001 */  xori  $t9, $t6, 1
/* 0D07C0 803157C0 2F390001 */  sltiu $t9, $t9, 1
/* 0D07C4 803157C4 AFB90054 */  sw    $t9, 0x54($sp)
/* 0D07C8 803157C8 AFA20058 */  sw    $v0, 0x58($sp)
/* 0D07CC 803157CC 8FAF015C */  lw    $t7, 0x15c($sp)
.L_US_803157D0:
/* 0D07D0 803157D0 8FB80054 */  lw    $t8, 0x54($sp)
/* 0D07D4 803157D4 8FA20058 */  lw    $v0, 0x58($sp)
/* 0D07D8 803157D8 8DE4000C */  lw    $a0, 0xc($t7)
/* 0D07DC 803157DC 0000F025 */  move  $fp, $zero
/* 0D07E0 803157E0 0000A825 */  move  $s5, $zero
/* 0D07E4 803157E4 13000003 */  beqz  $t8, .L_US_803157F4
/* 0D07E8 803157E8 24850008 */   addiu $a1, $a0, 8
/* 0D07EC 803157EC 1000000A */  b     .L_US_80315818
/* 0D07F0 803157F0 00406825 */   move  $t5, $v0
.L_US_803157F4:
/* 0D07F4 803157F4 304E0001 */  andi  $t6, $v0, 1
/* 0D07F8 803157F8 11C00007 */  beqz  $t6, .L_US_80315818
/* 0D07FC 803157FC 00406825 */   move  $t5, $v0
/* 0D0800 80315800 8FAF00DC */  lw    $t7, 0xdc($sp)
/* 0D0804 80315804 2401FFFE */  li    $at, -2
/* 0D0808 80315808 0041C824 */  and   $t9, $v0, $at
/* 0D080C 8031580C 000FC040 */  sll   $t8, $t7, 1
/* 0D0810 80315810 10000001 */  b     .L_US_80315818
/* 0D0814 80315814 03386821 */   addu  $t5, $t9, $t8
.L_US_80315818:
/* 0D0818 80315818 8FAE0154 */  lw    $t6, 0x154($sp)
/* 0D081C 8031581C AFA20058 */  sw    $v0, 0x58($sp)
/* 0D0820 80315820 11C50013 */  beq   $t6, $a1, .L_US_80315870
/* 0D0824 80315824 00000000 */   nop   
/* 0D0828 80315828 AFA50154 */  sw    $a1, 0x154($sp)
/* 0D082C 8031582C 8C990000 */  lw    $t9, ($a0)
/* 0D0830 80315830 8C8F0004 */  lw    $t7, 4($a0)
/* 0D0834 80315834 3C0100FF */  lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
/* 0D0838 80315838 3421FFFF */  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
/* 0D083C 8031583C 01F90019 */  multu $t7, $t9
/* 0D0840 80315840 02801025 */  move  $v0, $s4
/* 0D0844 80315844 26940008 */  addiu $s4, $s4, 8
/* 0D0848 80315848 00001812 */  mflo  $v1
/* 0D084C 8031584C 0003C100 */  sll   $t8, $v1, 4
/* 0D0850 80315850 03017024 */  and   $t6, $t8, $at
/* 0D0854 80315854 3C010B00 */  lui   $at, 0xb00
/* 0D0858 80315858 01C17825 */  or    $t7, $t6, $at
/* 0D085C 8031585C AC4F0000 */  sw    $t7, ($v0)
/* 0D0860 80315860 8FB90154 */  lw    $t9, 0x154($sp)
/* 0D0864 80315864 3C018000 */  lui   $at, 0x8000
/* 0D0868 80315868 0321C021 */  addu  $t8, $t9, $at
/* 0D086C 8031586C AC580004 */  sw    $t8, 4($v0)
.L_US_80315870:
/* 0D0870 80315870 11A00102 */  beqz  $t5, .L_US_80315C7C
/* 0D0874 80315874 8FA20058 */   lw    $v0, 0x58($sp)
/* 0D0878 80315878 AFA20058 */  sw    $v0, 0x58($sp)
/* 0D087C 8031587C 8EE90014 */  lw    $t1, 0x14($s7)
.L_US_80315880:
/* 0D0880 80315880 8FAE0108 */  lw    $t6, 0x108($sp)
/* 0D0884 80315884 01BE2023 */  subu  $a0, $t5, $fp
/* 0D0888 80315888 3132000F */  andi  $s2, $t1, 0xf
/* 0D088C 8031588C 00005025 */  move  $t2, $zero
/* 0D0890 80315890 00005825 */  move  $t3, $zero
/* 0D0894 80315894 00806025 */  move  $t4, $a0
/* 0D0898 80315898 16400006 */  bnez  $s2, .L_US_803158B4
/* 0D089C 8031589C 01C91823 */   subu  $v1, $t6, $t1
/* 0D08A0 803158A0 8EEF0000 */  lw    $t7, ($s7)
/* 0D08A4 803158A4 000FC080 */  sll   $t8, $t7, 2
/* 0D08A8 803158A8 07020003 */  bltzl $t8, .L_US_803158B8
/* 0D08AC 803158AC 240E0010 */   li    $t6, 16
/* 0D08B0 803158B0 24120010 */  li    $s2, 16
.L_US_803158B4:
/* 0D08B4 803158B4 240E0010 */  li    $t6, 16
.L_US_803158B8:
/* 0D08B8 803158B8 01D22823 */  subu  $a1, $t6, $s2
/* 0D08BC 803158BC 0083082A */  slt   $at, $a0, $v1
/* 0D08C0 803158C0 1020000C */  beqz  $at, .L_US_803158F4
/* 0D08C4 803158C4 00A0B025 */   move  $s6, $a1
/* 0D08C8 803158C8 00851023 */  subu  $v0, $a0, $a1
/* 0D08CC 803158CC 2442000F */  addiu $v0, $v0, 0xf
/* 0D08D0 803158D0 04410003 */  bgez  $v0, .L_US_803158E0
/* 0D08D4 803158D4 00027903 */   sra   $t7, $v0, 4
/* 0D08D8 803158D8 2441000F */  addiu $at, $v0, 0xf
/* 0D08DC 803158DC 00017903 */  sra   $t7, $at, 4
.L_US_803158E0:
/* 0D08E0 803158E0 000F8100 */  sll   $s0, $t7, 4
/* 0D08E4 803158E4 00B0C821 */  addu  $t9, $a1, $s0
/* 0D08E8 803158E8 01E04025 */  move  $t0, $t7
/* 0D08EC 803158EC 10000012 */  b     .L_US_80315938
/* 0D08F0 803158F0 03249823 */   subu  $s3, $t9, $a0
.L_US_803158F4:
/* 0D08F4 803158F4 00721021 */  addu  $v0, $v1, $s2
/* 0D08F8 803158F8 2450FFF0 */  addiu $s0, $v0, -0x10
/* 0D08FC 803158FC 1E000003 */  bgtz  $s0, .L_US_8031590C
/* 0D0900 80315900 00009825 */   move  $s3, $zero
/* 0D0904 80315904 00008025 */  move  $s0, $zero
/* 0D0908 80315908 0060B025 */  move  $s6, $v1
.L_US_8031590C:
/* 0D090C 8031590C 2608000F */  addiu $t0, $s0, 0xf
/* 0D0910 80315910 8FEE0008 */  lw    $t6, 8($ra)
/* 0D0914 80315914 05010003 */  bgez  $t0, .L_US_80315924
/* 0D0918 80315918 0008C103 */   sra   $t8, $t0, 4
/* 0D091C 8031591C 2501000F */  addiu $at, $t0, 0xf
/* 0D0920 80315920 0001C103 */  sra   $t8, $at, 4
.L_US_80315924:
/* 0D0924 80315924 11C00003 */  beqz  $t6, .L_US_80315934
/* 0D0928 80315928 03004025 */   move  $t0, $t8
/* 0D092C 8031592C 10000002 */  b     .L_US_80315938
/* 0D0930 80315930 240B0001 */   li    $t3, 1
.L_US_80315934:
/* 0D0934 80315934 240A0001 */  li    $t2, 1
.L_US_80315938:
/* 0D0938 80315938 11000032 */  beqz  $t0, .L_US_80315A04
/* 0D093C 8031593C 24030009 */   li    $v1, 9
/* 0D0940 80315940 01321023 */  subu  $v0, $t1, $s2
/* 0D0944 80315944 24420010 */  addiu $v0, $v0, 0x10
/* 0D0948 80315948 04410003 */  bgez  $v0, .L_US_80315958
/* 0D094C 8031594C 00027903 */   sra   $t7, $v0, 4
/* 0D0950 80315950 2441000F */  addiu $at, $v0, 0xf
/* 0D0954 80315954 00017903 */  sra   $t7, $at, 4
.L_US_80315958:
/* 0D0958 80315958 01E30019 */  multu $t7, $v1
/* 0D095C 8031595C 8FB80118 */  lw    $t8, 0x118($sp)
/* 0D0960 80315960 AFBF0158 */  sw    $ra, 0x158($sp)
/* 0D0964 80315964 8FA60140 */  lw    $a2, 0x140($sp)
/* 0D0968 80315968 26E70003 */  addiu $a3, $s7, 3
/* 0D096C 8031596C AFAA0148 */  sw    $t2, 0x148($sp)
/* 0D0970 80315970 AFAB0144 */  sw    $t3, 0x144($sp)
/* 0D0974 80315974 AFAC0104 */  sw    $t4, 0x104($sp)
/* 0D0978 80315978 AFAD0110 */  sw    $t5, 0x110($sp)
/* 0D097C 8031597C 0000C812 */  mflo  $t9
/* 0D0980 80315980 03382021 */  addu  $a0, $t9, $t8
/* 0D0984 80315984 00000000 */  nop   
/* 0D0988 80315988 01030019 */  multu $t0, $v1
/* 0D098C 8031598C 00008812 */  mflo  $s1
/* 0D0990 80315990 02202825 */  move  $a1, $s1
/* 0D0994 80315994 0C0C60C0 */  jal   func_80317270
/* 0D0998 80315998 00000000 */   nop   
/* 0D099C 8031599C 3047000F */  andi  $a3, $v0, 0xf
/* 0D09A0 803159A0 02802025 */  move  $a0, $s4
/* 0D09A4 803159A4 3C0E0800 */  lui   $t6, (0x080003F0 >> 16) # lui $t6, 0x800
/* 0D09A8 803159A8 8FAA0148 */  lw    $t2, 0x148($sp)
/* 0D09AC 803159AC 8FAB0144 */  lw    $t3, 0x144($sp)
/* 0D09B0 803159B0 8FAC0104 */  lw    $t4, 0x104($sp)
/* 0D09B4 803159B4 8FAD0110 */  lw    $t5, 0x110($sp)
/* 0D09B8 803159B8 8FBF0158 */  lw    $ra, 0x158($sp)
/* 0D09BC 803159BC 35CE03F0 */  ori   $t6, (0x080003F0 & 0xFFFF) # ori $t6, $t6, 0x3f0
/* 0D09C0 803159C0 02277821 */  addu  $t7, $s1, $a3
/* 0D09C4 803159C4 31F9FFFF */  andi  $t9, $t7, 0xffff
/* 0D09C8 803159C8 AC8E0000 */  sw    $t6, ($a0)
/* 0D09CC 803159CC 26940008 */  addiu $s4, $s4, 8
/* 0D09D0 803159D0 AC990004 */  sw    $t9, 4($a0)
/* 0D09D4 803159D4 02802825 */  move  $a1, $s4
/* 0D09D8 803159D8 00477023 */  subu  $t6, $v0, $a3
/* 0D09DC 803159DC 3C018000 */  lui   $at, 0x8000
/* 0D09E0 803159E0 01C17821 */  addu  $t7, $t6, $at
/* 0D09E4 803159E4 3C180400 */  lui   $t8, 0x400
/* 0D09E8 803159E8 ACB80000 */  sw    $t8, ($a1)
/* 0D09EC 803159EC ACAF0004 */  sw    $t7, 4($a1)
/* 0D09F0 803159F0 8EE60000 */  lw    $a2, ($s7)
/* 0D09F4 803159F4 26940008 */  addiu $s4, $s4, 8
/* 0D09F8 803159F8 0006C880 */  sll   $t9, $a2, 2
/* 0D09FC 803159FC 10000006 */  b     .L_US_80315A18
/* 0D0A00 80315A00 001937C2 */   srl   $a2, $t9, 0x1f
.L_US_80315A04:
/* 0D0A04 80315A04 8EE60000 */  lw    $a2, ($s7)
/* 0D0A08 80315A08 00008025 */  move  $s0, $zero
/* 0D0A0C 80315A0C 00003825 */  move  $a3, $zero
/* 0D0A10 80315A10 00067080 */  sll   $t6, $a2, 2
/* 0D0A14 80315A14 000E37C2 */  srl   $a2, $t6, 0x1f
.L_US_80315A18:
/* 0D0A18 80315A18 10C0000F */  beqz  $a2, .L_US_80315A58
/* 0D0A1C 80315A1C 02801025 */   move  $v0, $s4
/* 0D0A20 80315A20 3C190F00 */  lui   $t9, 0xf00
/* 0D0A24 80315A24 AC590000 */  sw    $t9, ($v0)
/* 0D0A28 80315A28 8FB8015C */  lw    $t8, 0x15c($sp)
/* 0D0A2C 80315A2C 3C018000 */  lui   $at, (0x80000010 >> 16) # lui $at, 0x8000
/* 0D0A30 80315A30 34210010 */  ori   $at, (0x80000010 & 0xFFFF) # ori $at, $at, 0x10
/* 0D0A34 80315A34 8F0E0008 */  lw    $t6, 8($t8)
/* 0D0A38 80315A38 24190002 */  li    $t9, 2
/* 0D0A3C 80315A3C 26940008 */  addiu $s4, $s4, 8
/* 0D0A40 80315A40 01C17821 */  addu  $t7, $t6, $at
/* 0D0A44 80315A44 AC4F0004 */  sw    $t7, 4($v0)
/* 0D0A48 80315A48 AFB90140 */  sw    $t9, 0x140($sp)
/* 0D0A4C 80315A4C 92F80000 */  lbu   $t8, ($s7)
/* 0D0A50 80315A50 330EFFDF */  andi  $t6, $t8, 0xffdf
/* 0D0A54 80315A54 A2EE0000 */  sb    $t6, ($s7)
.L_US_80315A58:
/* 0D0A58 80315A58 17C0001C */  bnez  $fp, .L_US_80315ACC
/* 0D0A5C 80315A5C 02801025 */   move  $v0, $s4
/* 0D0A60 80315A60 24EF03F0 */  addiu $t7, $a3, 0x3f0
/* 0D0A64 80315A64 31F9FFFF */  andi  $t9, $t7, 0xffff
/* 0D0A68 80315A68 3C010800 */  lui   $at, 0x800
/* 0D0A6C 80315A6C 0321C025 */  or    $t8, $t9, $at
/* 0D0A70 80315A70 00103040 */  sll   $a2, $s0, 1
/* 0D0A74 80315A74 30CEFFFF */  andi  $t6, $a2, 0xffff
/* 0D0A78 80315A78 3C010180 */  lui   $at, 0x180
/* 0D0A7C 80315A7C 02801025 */  move  $v0, $s4
/* 0D0A80 80315A80 01C17825 */  or    $t7, $t6, $at
/* 0D0A84 80315A84 AC4F0004 */  sw    $t7, 4($v0)
/* 0D0A88 80315A88 AC580000 */  sw    $t8, ($v0)
/* 0D0A8C 80315A8C 8FB90140 */  lw    $t9, 0x140($sp)
/* 0D0A90 80315A90 26940008 */  addiu $s4, $s4, 8
/* 0D0A94 80315A94 3C010100 */  lui   $at, 0x100
/* 0D0A98 80315A98 333800FF */  andi  $t8, $t9, 0xff
/* 0D0A9C 80315A9C 00187400 */  sll   $t6, $t8, 0x10
/* 0D0AA0 80315AA0 01C17825 */  or    $t7, $t6, $at
/* 0D0AA4 80315AA4 02801825 */  move  $v1, $s4
/* 0D0AA8 80315AA8 AC6F0000 */  sw    $t7, ($v1)
/* 0D0AAC 80315AAC 8EF90034 */  lw    $t9, 0x34($s7)
/* 0D0AB0 80315AB0 3C018000 */  lui   $at, 0x8000
/* 0D0AB4 80315AB4 00127040 */  sll   $t6, $s2, 1
/* 0D0AB8 80315AB8 0321C021 */  addu  $t8, $t9, $at
/* 0D0ABC 80315ABC AC780004 */  sw    $t8, 4($v1)
/* 0D0AC0 80315AC0 26940008 */  addiu $s4, $s4, 8
/* 0D0AC4 80315AC4 10000030 */  b     .L_US_80315B88
/* 0D0AC8 80315AC8 AFAE0128 */   sw    $t6, 0x128($sp)
.L_US_80315ACC:
/* 0D0ACC 80315ACC 24EF03F0 */  addiu $t7, $a3, 0x3f0
/* 0D0AD0 80315AD0 31F9FFFF */  andi  $t9, $t7, 0xffff
/* 0D0AD4 80315AD4 3C010800 */  lui   $at, 0x800
/* 0D0AD8 80315AD8 0321C025 */  or    $t8, $t9, $at
/* 0D0ADC 80315ADC 2401FFE0 */  li    $at, -32
/* 0D0AE0 80315AE0 26A3001F */  addiu $v1, $s5, 0x1f
/* 0D0AE4 80315AE4 00617024 */  and   $t6, $v1, $at
/* 0D0AE8 80315AE8 25D90180 */  addiu $t9, $t6, 0x180
/* 0D0AEC 80315AEC 01C01825 */  move  $v1, $t6
/* 0D0AF0 80315AF0 AC580000 */  sw    $t8, ($v0)
/* 0D0AF4 80315AF4 00103040 */  sll   $a2, $s0, 1
/* 0D0AF8 80315AF8 30CEFFFF */  andi  $t6, $a2, 0xffff
/* 0D0AFC 80315AFC 0019C400 */  sll   $t8, $t9, 0x10
/* 0D0B00 80315B00 030E7825 */  or    $t7, $t8, $t6
/* 0D0B04 80315B04 AC4F0004 */  sw    $t7, 4($v0)
/* 0D0B08 80315B08 8FB90140 */  lw    $t9, 0x140($sp)
/* 0D0B0C 80315B0C 26940008 */  addiu $s4, $s4, 8
/* 0D0B10 80315B10 3C010100 */  lui   $at, 0x100
/* 0D0B14 80315B14 333800FF */  andi  $t8, $t9, 0xff
/* 0D0B18 80315B18 00187400 */  sll   $t6, $t8, 0x10
/* 0D0B1C 80315B1C 01C17825 */  or    $t7, $t6, $at
/* 0D0B20 80315B20 02802025 */  move  $a0, $s4
/* 0D0B24 80315B24 AC8F0000 */  sw    $t7, ($a0)
/* 0D0B28 80315B28 8EF90034 */  lw    $t9, 0x34($s7)
/* 0D0B2C 80315B2C 3C018000 */  lui   $at, 0x8000
/* 0D0B30 80315B30 00127040 */  sll   $t6, $s2, 1
/* 0D0B34 80315B34 0321C021 */  addu  $t8, $t9, $at
/* 0D0B38 80315B38 3C0100FF */  lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
/* 0D0B3C 80315B3C 006E7821 */  addu  $t7, $v1, $t6
/* 0D0B40 80315B40 AC980004 */  sw    $t8, 4($a0)
/* 0D0B44 80315B44 25F90180 */  addiu $t9, $t7, 0x180
/* 0D0B48 80315B48 3421FFFF */  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
/* 0D0B4C 80315B4C 0321C024 */  and   $t8, $t9, $at
/* 0D0B50 80315B50 26940008 */  addiu $s4, $s4, 8
/* 0D0B54 80315B54 3C010A00 */  lui   $at, 0xa00
/* 0D0B58 80315B58 03017025 */  or    $t6, $t8, $at
/* 0D0B5C 80315B5C 02802825 */  move  $a1, $s4
/* 0D0B60 80315B60 ACAE0000 */  sw    $t6, ($a1)
/* 0D0B64 80315B64 02167021 */  addu  $t6, $s0, $s6
/* 0D0B68 80315B68 26B90180 */  addiu $t9, $s5, 0x180
/* 0D0B6C 80315B6C 0019C400 */  sll   $t8, $t9, 0x10
/* 0D0B70 80315B70 01D37823 */  subu  $t7, $t6, $s3
/* 0D0B74 80315B74 000FC840 */  sll   $t9, $t7, 1
/* 0D0B78 80315B78 332EFFFF */  andi  $t6, $t9, 0xffff
/* 0D0B7C 80315B7C 030E7825 */  or    $t7, $t8, $t6
/* 0D0B80 80315B80 ACAF0004 */  sw    $t7, 4($a1)
/* 0D0B84 80315B84 26940008 */  addiu $s4, $s4, 8
.L_US_80315B88:
/* 0D0B88 80315B88 8FAE0140 */  lw    $t6, 0x140($sp)
/* 0D0B8C 80315B8C 03D0C821 */  addu  $t9, $fp, $s0
/* 0D0B90 80315B90 0336C021 */  addu  $t8, $t9, $s6
/* 0D0B94 80315B94 24010001 */  li    $at, 1
/* 0D0B98 80315B98 11C10008 */  beq   $t6, $at, .L_US_80315BBC
/* 0D0B9C 80315B9C 0313F023 */   subu  $fp, $t8, $s3
/* 0D0BA0 80315BA0 39C20002 */  xori  $v0, $t6, 2
/* 0D0BA4 80315BA4 02167821 */  addu  $t7, $s0, $s6
/* 0D0BA8 80315BA8 01F31823 */  subu  $v1, $t7, $s3
/* 0D0BAC 80315BAC 10400007 */  beqz  $v0, .L_US_80315BCC
/* 0D0BB0 80315BB0 AFA00140 */   sw    $zero, 0x140($sp)
/* 0D0BB4 80315BB4 10000008 */  b     .L_US_80315BD8
/* 0D0BB8 80315BB8 0003C040 */   sll   $t8, $v1, 1
.L_US_80315BBC:
/* 0D0BBC 80315BBC AFA00128 */  sw    $zero, 0x128($sp)
/* 0D0BC0 80315BC0 02A6A821 */  addu  $s5, $s5, $a2
/* 0D0BC4 80315BC4 1000000B */  b     .L_US_80315BF4
/* 0D0BC8 80315BC8 AFA00140 */   sw    $zero, 0x140($sp)
.L_US_80315BCC:
/* 0D0BCC 80315BCC 0003C840 */  sll   $t9, $v1, 1
/* 0D0BD0 80315BD0 10000008 */  b     .L_US_80315BF4
/* 0D0BD4 80315BD4 02B9A821 */   addu  $s5, $s5, $t9
.L_US_80315BD8:
/* 0D0BD8 80315BD8 52A00004 */  beql  $s5, $zero, .L_US_80315BEC
/* 0D0BDC 80315BDC 0072A821 */   addu  $s5, $v1, $s2
/* 0D0BE0 80315BE0 10000004 */  b     .L_US_80315BF4
/* 0D0BE4 80315BE4 02B8A821 */   addu  $s5, $s5, $t8
/* 0D0BE8 80315BE8 0072A821 */  addu  $s5, $v1, $s2
.L_US_80315BEC:
/* 0D0BEC 80315BEC 00157040 */  sll   $t6, $s5, 1
/* 0D0BF0 80315BF0 01C0A825 */  move  $s5, $t6
.L_US_80315BF4:
/* 0D0BF4 80315BF4 11400014 */  beqz  $t2, .L_US_80315C48
/* 0D0BF8 80315BF8 3C0100FF */   lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
/* 0D0BFC 80315BFC 3421FFFF */  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
/* 0D0C00 80315C00 26AF0180 */  addiu $t7, $s5, 0x180
/* 0D0C04 80315C04 01E1C824 */  and   $t9, $t7, $at
/* 0D0C08 80315C08 3C010200 */  lui   $at, 0x200
/* 0D0C0C 80315C0C 02801025 */  move  $v0, $s4
/* 0D0C10 80315C10 01BE7023 */  subu  $t6, $t5, $fp
/* 0D0C14 80315C14 000E7840 */  sll   $t7, $t6, 1
/* 0D0C18 80315C18 0321C025 */  or    $t8, $t9, $at
/* 0D0C1C 80315C1C AC580000 */  sw    $t8, ($v0)
/* 0D0C20 80315C20 AC4F0004 */  sw    $t7, 4($v0)
/* 0D0C24 80315C24 92F80000 */  lbu   $t8, ($s7)
/* 0D0C28 80315C28 26940008 */  addiu $s4, $s4, 8
/* 0D0C2C 80315C2C AEE00014 */  sw    $zero, 0x14($s7)
/* 0D0C30 80315C30 370E0010 */  ori   $t6, $t8, 0x10
/* 0D0C34 80315C34 A2EE0000 */  sb    $t6, ($s7)
/* 0D0C38 80315C38 92EF0000 */  lbu   $t7, ($s7)
/* 0D0C3C 80315C3C 31F9FF7F */  andi  $t9, $t7, 0xff7f
/* 0D0C40 80315C40 1000000E */  b     .L_US_80315C7C
/* 0D0C44 80315C44 A2F90000 */   sb    $t9, ($s7)
.L_US_80315C48:
/* 0D0C48 80315C48 51600008 */  beql  $t3, $zero, .L_US_80315C6C
/* 0D0C4C 80315C4C 8EF80014 */   lw    $t8, 0x14($s7)
/* 0D0C50 80315C50 92EE0000 */  lbu   $t6, ($s7)
/* 0D0C54 80315C54 35CF0020 */  ori   $t7, $t6, 0x20
/* 0D0C58 80315C58 A2EF0000 */  sb    $t7, ($s7)
/* 0D0C5C 80315C5C 8FF90000 */  lw    $t9, ($ra)
/* 0D0C60 80315C60 10000004 */  b     .L_US_80315C74
/* 0D0C64 80315C64 AEF90014 */   sw    $t9, 0x14($s7)
/* 0D0C68 80315C68 8EF80014 */  lw    $t8, 0x14($s7)
.L_US_80315C6C:
/* 0D0C6C 80315C6C 030C7021 */  addu  $t6, $t8, $t4
/* 0D0C70 80315C70 AEEE0014 */  sw    $t6, 0x14($s7)
.L_US_80315C74:
/* 0D0C74 80315C74 57CDFF02 */  bnel  $fp, $t5, .L_US_80315880
/* 0D0C78 80315C78 8EE90014 */   lw    $t1, 0x14($s7)
.L_US_80315C7C:
/* 0D0C7C 80315C7C 8FAF0054 */  lw    $t7, 0x54($sp)
/* 0D0C80 80315C80 8FB900E0 */  lw    $t9, 0xe0($sp)
/* 0D0C84 80315C84 24010002 */  li    $at, 2
/* 0D0C88 80315C88 15E00008 */  bnez  $t7, .L_US_80315CAC
/* 0D0C8C 80315C8C 8FAE0128 */   lw    $t6, 0x128($sp)
/* 0D0C90 80315C90 1321000D */  beq   $t9, $at, .L_US_80315CC8
/* 0D0C94 80315C94 8FB800DC */   lw    $t8, 0xdc($sp)
/* 0D0C98 80315C98 8EE50000 */  lw    $a1, ($s7)
/* 0D0C9C 80315C9C 000530C0 */  sll   $a2, $a1, 3
/* 0D0CA0 80315CA0 0006C7C2 */  srl   $t8, $a2, 0x1f
/* 0D0CA4 80315CA4 10000066 */  b     .L_US_80315E40
/* 0D0CA8 80315CA8 03003025 */   move  $a2, $t8
.L_US_80315CAC:
/* 0D0CAC 80315CAC 25CF0180 */  addiu $t7, $t6, 0x180
/* 0D0CB0 80315CB0 A7AF00CE */  sh    $t7, 0xce($sp)
/* 0D0CB4 80315CB4 8EE50000 */  lw    $a1, ($s7)
/* 0D0CB8 80315CB8 000530C0 */  sll   $a2, $a1, 3
/* 0D0CBC 80315CBC 0006CFC2 */  srl   $t9, $a2, 0x1f
/* 0D0CC0 80315CC0 1000005F */  b     .L_US_80315E40
/* 0D0CC4 80315CC4 03203025 */   move  $a2, $t9
.L_US_80315CC8:
/* 0D0CC8 80315CC8 13000009 */  beqz  $t8, .L_US_80315CF0
/* 0D0CCC 80315CCC 02801025 */   move  $v0, $s4
/* 0D0CD0 80315CD0 24010001 */  li    $at, 1
/* 0D0CD4 80315CD4 13010034 */  beq   $t8, $at, .L_US_80315DA8
/* 0D0CD8 80315CD8 02801025 */   move  $v0, $s4
/* 0D0CDC 80315CDC 8EE50000 */  lw    $a1, ($s7)
/* 0D0CE0 80315CE0 000530C0 */  sll   $a2, $a1, 3
/* 0D0CE4 80315CE4 000677C2 */  srl   $t6, $a2, 0x1f
/* 0D0CE8 80315CE8 10000055 */  b     .L_US_80315E40
/* 0D0CEC 80315CEC 01C03025 */   move  $a2, $t6
.L_US_80315CF0:
/* 0D0CF0 80315CF0 8FAF0128 */  lw    $t7, 0x128($sp)
/* 0D0CF4 80315CF4 3C010800 */  lui   $at, 0x800
/* 0D0CF8 80315CF8 25A30004 */  addiu $v1, $t5, 4
/* 0D0CFC 80315CFC 25F90180 */  addiu $t9, $t7, 0x180
/* 0D0D00 80315D00 3338FFFF */  andi  $t8, $t9, 0xffff
/* 0D0D04 80315D04 03017025 */  or    $t6, $t8, $at
/* 0D0D08 80315D08 3C010020 */  lui   $at, 0x20
/* 0D0D0C 80315D0C 306FFFFF */  andi  $t7, $v1, 0xffff
/* 0D0D10 80315D10 01E1C825 */  or    $t9, $t7, $at
/* 0D0D14 80315D14 26940008 */  addiu $s4, $s4, 8
/* 0D0D18 80315D18 3C180501 */  lui   $t8, (0x0501FF60 >> 16) # lui $t8, 0x501
/* 0D0D1C 80315D1C AC590004 */  sw    $t9, 4($v0)
/* 0D0D20 80315D20 AC4E0000 */  sw    $t6, ($v0)
/* 0D0D24 80315D24 3718FF60 */  ori   $t8, (0x0501FF60 & 0xFFFF) # ori $t8, $t8, 0xff60
/* 0D0D28 80315D28 02802025 */  move  $a0, $s4
/* 0D0D2C 80315D2C AC980000 */  sw    $t8, ($a0)
/* 0D0D30 80315D30 8EEE0034 */  lw    $t6, 0x34($s7)
/* 0D0D34 80315D34 3C018000 */  lui   $at, (0x800000F0 >> 16) # lui $at, 0x8000
/* 0D0D38 80315D38 342100F0 */  ori   $at, (0x800000F0 & 0xFFFF) # ori $at, $at, 0xf0
/* 0D0D3C 80315D3C 01C17821 */  addu  $t7, $t6, $at
/* 0D0D40 80315D40 AC8F0004 */  sw    $t7, 4($a0)
/* 0D0D44 80315D44 24190024 */  li    $t9, 36
/* 0D0D48 80315D48 AFA300D0 */  sw    $v1, 0xd0($sp)
/* 0D0D4C 80315D4C A7B900CE */  sh    $t9, 0xce($sp)
/* 0D0D50 80315D50 8EE50000 */  lw    $a1, ($s7)
/* 0D0D54 80315D54 26940008 */  addiu $s4, $s4, 8
/* 0D0D58 80315D58 02801025 */  move  $v0, $s4
/* 0D0D5C 80315D5C 000530C0 */  sll   $a2, $a1, 3
/* 0D0D60 80315D60 0006C7C2 */  srl   $t8, $a2, 0x1f
/* 0D0D64 80315D64 13000036 */  beqz  $t8, .L_US_80315E40
/* 0D0D68 80315D68 03003025 */   move  $a2, $t8
/* 0D0D6C 80315D6C 3C0100FF */  lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
/* 0D0D70 80315D70 3421FFFF */  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
/* 0D0D74 80315D74 25AE0024 */  addiu $t6, $t5, 0x24
/* 0D0D78 80315D78 01C17824 */  and   $t7, $t6, $at
/* 0D0D7C 80315D7C 3C010200 */  lui   $at, 0x200
/* 0D0D80 80315D80 01E1C825 */  or    $t9, $t7, $at
/* 0D0D84 80315D84 25B80010 */  addiu $t8, $t5, 0x10
/* 0D0D88 80315D88 AC580004 */  sw    $t8, 4($v0)
/* 0D0D8C 80315D8C AC590000 */  sw    $t9, ($v0)
/* 0D0D90 80315D90 8EE50000 */  lw    $a1, ($s7)
/* 0D0D94 80315D94 26940008 */  addiu $s4, $s4, 8
/* 0D0D98 80315D98 000530C0 */  sll   $a2, $a1, 3
/* 0D0D9C 80315D9C 000677C2 */  srl   $t6, $a2, 0x1f
/* 0D0DA0 80315DA0 10000027 */  b     .L_US_80315E40
/* 0D0DA4 80315DA4 01C03025 */   move  $a2, $t6
.L_US_80315DA8:
/* 0D0DA8 80315DA8 8FAF0128 */  lw    $t7, 0x128($sp)
/* 0D0DAC 80315DAC 3C010800 */  lui   $at, 0x800
/* 0D0DB0 80315DB0 26940008 */  addiu $s4, $s4, 8
/* 0D0DB4 80315DB4 25F90180 */  addiu $t9, $t7, 0x180
/* 0D0DB8 80315DB8 3338FFFF */  andi  $t8, $t9, 0xffff
/* 0D0DBC 80315DBC 03017025 */  or    $t6, $t8, $at
/* 0D0DC0 80315DC0 25AF0008 */  addiu $t7, $t5, 8
/* 0D0DC4 80315DC4 31F9FFFF */  andi  $t9, $t7, 0xffff
/* 0D0DC8 80315DC8 AC4E0000 */  sw    $t6, ($v0)
/* 0D0DCC 80315DCC 3C010160 */  lui   $at, 0x160
/* 0D0DD0 80315DD0 0321C025 */  or    $t8, $t9, $at
/* 0D0DD4 80315DD4 3C0E0501 */  lui   $t6, (0x0501FF60 >> 16) # lui $t6, 0x501
/* 0D0DD8 80315DD8 AC580004 */  sw    $t8, 4($v0)
/* 0D0DDC 80315DDC 35CEFF60 */  ori   $t6, (0x0501FF60 & 0xFFFF) # ori $t6, $t6, 0xff60
/* 0D0DE0 80315DE0 02801825 */  move  $v1, $s4
/* 0D0DE4 80315DE4 AC6E0000 */  sw    $t6, ($v1)
/* 0D0DE8 80315DE8 8EEF0034 */  lw    $t7, 0x34($s7)
/* 0D0DEC 80315DEC 3C018000 */  lui   $at, (0x800000F0 >> 16) # lui $at, 0x8000
/* 0D0DF0 80315DF0 342100F0 */  ori   $at, (0x800000F0 & 0xFFFF) # ori $at, $at, 0xf0
/* 0D0DF4 80315DF4 26940008 */  addiu $s4, $s4, 8
/* 0D0DF8 80315DF8 3C180A00 */  lui   $t8, (0x0A000164 >> 16) # lui $t8, 0xa00
/* 0D0DFC 80315DFC 01E1C821 */  addu  $t9, $t7, $at
/* 0D0E00 80315E00 AC790004 */  sw    $t9, 4($v1)
/* 0D0E04 80315E04 37180164 */  ori   $t8, (0x0A000164 & 0xFFFF) # ori $t8, $t8, 0x164
/* 0D0E08 80315E08 02802025 */  move  $a0, $s4
/* 0D0E0C 80315E0C AC980000 */  sw    $t8, ($a0)
/* 0D0E10 80315E10 8FAE00D0 */  lw    $t6, 0xd0($sp)
/* 0D0E14 80315E14 26940008 */  addiu $s4, $s4, 8
/* 0D0E18 80315E18 25D90020 */  addiu $t9, $t6, 0x20
/* 0D0E1C 80315E1C 25AE0004 */  addiu $t6, $t5, 4
/* 0D0E20 80315E20 31CFFFFF */  andi  $t7, $t6, 0xffff
/* 0D0E24 80315E24 0019C400 */  sll   $t8, $t9, 0x10
/* 0D0E28 80315E28 030FC825 */  or    $t9, $t8, $t7
/* 0D0E2C 80315E2C AC990004 */  sw    $t9, 4($a0)
/* 0D0E30 80315E30 8EE50000 */  lw    $a1, ($s7)
/* 0D0E34 80315E34 000530C0 */  sll   $a2, $a1, 3
/* 0D0E38 80315E38 000677C2 */  srl   $t6, $a2, 0x1f
/* 0D0E3C 80315E3C 01C03025 */  move  $a2, $t6
.L_US_80315E40:
/* 0D0E40 80315E40 10C00003 */  beqz  $a2, .L_US_80315E50
/* 0D0E44 80315E44 8FA200DC */   lw    $v0, 0xdc($sp)
/* 0D0E48 80315E48 10000008 */  b     .L_US_80315E6C
/* 0D0E4C 80315E4C AFA00140 */   sw    $zero, 0x140($sp)
.L_US_80315E50:
/* 0D0E50 80315E50 8FB800E0 */  lw    $t8, 0xe0($sp)
/* 0D0E54 80315E54 24420001 */  addiu $v0, $v0, 1
/* 0D0E58 80315E58 AFA200DC */  sw    $v0, 0xdc($sp)
/* 0D0E5C 80315E5C 5458FE5C */  bnel  $v0, $t8, .L_US_803157D0
/* 0D0E60 80315E60 8FAF015C */   lw    $t7, 0x15c($sp)
.L_US_80315E64:
/* 0D0E64 80315E64 AFA00140 */  sw    $zero, 0x140($sp)
/* 0D0E68 80315E68 8EE50000 */  lw    $a1, ($s7)
.L_US_80315E6C:
/* 0D0E6C 80315E6C 00057840 */  sll   $t7, $a1, 1
/* 0D0E70 80315E70 000FCFC2 */  srl   $t9, $t7, 0x1f
/* 0D0E74 80315E74 24010001 */  li    $at, 1
/* 0D0E78 80315E78 17210006 */  bne   $t9, $at, .L_US_80315E94
/* 0D0E7C 80315E7C 02802025 */   move  $a0, $s4
/* 0D0E80 80315E80 240E0001 */  li    $t6, 1
/* 0D0E84 80315E84 AFAE0140 */  sw    $t6, 0x140($sp)
/* 0D0E88 80315E88 92F80000 */  lbu   $t8, ($s7)
/* 0D0E8C 80315E8C 330FFFBF */  andi  $t7, $t8, 0xffbf
/* 0D0E90 80315E90 A2EF0000 */  sb    $t7, ($s7)
.L_US_80315E94:
/* 0D0E94 80315E94 8FB10048 */  lw    $s1, 0x48($sp)
/* 0D0E98 80315E98 97B900CE */  lhu   $t9, 0xce($sp)
/* 0D0E9C 80315E9C 8FAE0140 */  lw    $t6, 0x140($sp)
/* 0D0EA0 80315EA0 02E02825 */  move  $a1, $s7
/* 0D0EA4 80315EA4 97A7005E */  lhu   $a3, 0x5e($sp)
/* 0D0EA8 80315EA8 02203025 */  move  $a2, $s1
/* 0D0EAC 80315EAC AFB90010 */  sw    $t9, 0x10($sp)
/* 0D0EB0 80315EB0 0C0C5837 */  jal   func_80314FD4
/* 0D0EB4 80315EB4 AFAE0014 */   sw    $t6, 0x14($sp)
/* 0D0EB8 80315EB8 96F8000C */  lhu   $t8, 0xc($s7)
/* 0D0EBC 80315EBC 0040A025 */  move  $s4, $v0
/* 0D0EC0 80315EC0 02802025 */  move  $a0, $s4
/* 0D0EC4 80315EC4 17000004 */  bnez  $t8, .L_US_80315ED8
/* 0D0EC8 80315EC8 02E02825 */   move  $a1, $s7
/* 0D0ECC 80315ECC 96EF0010 */  lhu   $t7, 0x10($s7)
/* 0D0ED0 80315ED0 51E00004 */  beql  $t7, $zero, .L_US_80315EE4
/* 0D0ED4 80315ED4 96F9000E */   lhu   $t9, 0xe($s7)
.L_US_80315ED8:
/* 0D0ED8 80315ED8 1000000A */  b     .L_US_80315F04
/* 0D0EDC 80315EDC 24100001 */   li    $s0, 1
/* 0D0EE0 80315EE0 96F9000E */  lhu   $t9, 0xe($s7)
.L_US_80315EE4:
/* 0D0EE4 80315EE4 17200005 */  bnez  $t9, .L_US_80315EFC
/* 0D0EE8 80315EE8 00000000 */   nop   
/* 0D0EEC 80315EEC 96EE0012 */  lhu   $t6, 0x12($s7)
/* 0D0EF0 80315EF0 00008025 */  move  $s0, $zero
/* 0D0EF4 80315EF4 11C00003 */  beqz  $t6, .L_US_80315F04
/* 0D0EF8 80315EF8 00000000 */   nop   
.L_US_80315EFC:
/* 0D0EFC 80315EFC 10000001 */  b     .L_US_80315F04
/* 0D0F00 80315F00 24100002 */   li    $s0, 2
.L_US_80315F04:
/* 0D0F04 80315F04 8FB80140 */  lw    $t8, 0x140($sp)
/* 0D0F08 80315F08 8FA60174 */  lw    $a2, 0x174($sp)
/* 0D0F0C 80315F0C 00003825 */  move  $a3, $zero
/* 0D0F10 80315F10 AFB00010 */  sw    $s0, 0x10($sp)
/* 0D0F14 80315F14 0C0C584E */  jal   func_80315030
/* 0D0F18 80315F18 AFB80014 */   sw    $t8, 0x14($sp)
/* 0D0F1C 80315F1C 92EF0001 */  lbu   $t7, 1($s7)
/* 0D0F20 80315F20 0040A025 */  move  $s4, $v0
/* 0D0F24 80315F24 00402025 */  move  $a0, $v0
/* 0D0F28 80315F28 11E00006 */  beqz  $t7, .L_US_80315F44
/* 0D0F2C 80315F2C 02E02825 */   move  $a1, $s7
/* 0D0F30 80315F30 02203025 */  move  $a2, $s1
/* 0D0F34 80315F34 8FA70140 */  lw    $a3, 0x140($sp)
/* 0D0F38 80315F38 0C0C59BF */  jal   func_803155F4
/* 0D0F3C 80315F3C AFB00010 */   sw    $s0, 0x10($sp)
/* 0D0F40 80315F40 0040A025 */  move  $s4, $v0
.L_US_80315F44:
/* 0D0F44 80315F44 8FB9016C */  lw    $t9, 0x16c($sp)
.L_US_80315F48:
/* 0D0F48 80315F48 8FB80064 */  lw    $t8, 0x64($sp)
/* 0D0F4C 80315F4C 272E0001 */  addiu $t6, $t9, 1
/* 0D0F50 80315F50 3C198022 */  lui   $t9, %hi(D_80226D70) # $t9, 0x8022
/* 0D0F54 80315F54 8F396B70 */  lw    $t9, %lo(D_80226D70)($t9)
/* 0D0F58 80315F58 270F00C0 */  addiu $t7, $t8, 0xc0
/* 0D0F5C 80315F5C AFAF0064 */  sw    $t7, 0x64($sp)
/* 0D0F60 80315F60 01D9082A */  slt   $at, $t6, $t9
/* 0D0F64 80315F64 1420FD9E */  bnez  $at, .L_US_803155E0
/* 0D0F68 80315F68 AFAE016C */   sw    $t6, 0x16c($sp)
.L_US_80315F6C:
/* 0D0F6C 80315F6C 3C080800 */  lui   $t0, 0x800
/* 0D0F70 80315F70 02802025 */  move  $a0, $s4
/* 0D0F74 80315F74 AC880000 */  sw    $t0, ($a0)
/* 0D0F78 80315F78 8FA30174 */  lw    $v1, 0x174($sp)
/* 0D0F7C 80315F7C 26940008 */  addiu $s4, $s4, 8
/* 0D0F80 80315F80 02802825 */  move  $a1, $s4
/* 0D0F84 80315F84 0003C040 */  sll   $t8, $v1, 1
/* 0D0F88 80315F88 330FFFFF */  andi  $t7, $t8, 0xffff
/* 0D0F8C 80315F8C AC8F0004 */  sw    $t7, 4($a0)
/* 0D0F90 80315F90 26940008 */  addiu $s4, $s4, 8
/* 0D0F94 80315F94 3C0E0D00 */  lui   $t6, 0xd00
/* 0D0F98 80315F98 3C1904C0 */  lui   $t9, (0x04C00600 >> 16) # lui $t9, 0x4c0
/* 0D0F9C 80315F9C 37390600 */  ori   $t9, (0x04C00600 & 0xFFFF) # ori $t9, $t9, 0x600
/* 0D0FA0 80315FA0 ACAE0000 */  sw    $t6, ($a1)
/* 0D0FA4 80315FA4 02803025 */  move  $a2, $s4
/* 0D0FA8 80315FA8 ACB90004 */  sw    $t9, 4($a1)
/* 0D0FAC 80315FAC 0018C040 */  sll   $t8, $t8, 1
/* 0D0FB0 80315FB0 330FFFFF */  andi  $t7, $t8, 0xffff
/* 0D0FB4 80315FB4 26940008 */  addiu $s4, $s4, 8
/* 0D0FB8 80315FB8 ACCF0004 */  sw    $t7, 4($a2)
/* 0D0FBC 80315FBC ACC80000 */  sw    $t0, ($a2)
/* 0D0FC0 80315FC0 02803825 */  move  $a3, $s4
/* 0D0FC4 80315FC4 3C0E0600 */  lui   $t6, 0x600
/* 0D0FC8 80315FC8 ACEE0000 */  sw    $t6, ($a3)
/* 0D0FCC 80315FCC 8FB90170 */  lw    $t9, 0x170($sp)
/* 0D0FD0 80315FD0 3C018000 */  lui   $at, 0x8000
/* 0D0FD4 80315FD4 26820008 */  addiu $v0, $s4, 8
/* 0D0FD8 80315FD8 0321C021 */  addu  $t8, $t9, $at
/* 0D0FDC 80315FDC ACF80004 */  sw    $t8, 4($a3)
/* 0D0FE0 80315FE0 8FBF0044 */  lw    $ra, 0x44($sp)
/* 0D0FE4 80315FE4 8FBE0040 */  lw    $fp, 0x40($sp)
/* 0D0FE8 80315FE8 8FB7003C */  lw    $s7, 0x3c($sp)
/* 0D0FEC 80315FEC 8FB60038 */  lw    $s6, 0x38($sp)
/* 0D0FF0 80315FF0 8FB50034 */  lw    $s5, 0x34($sp)
/* 0D0FF4 80315FF4 8FB40030 */  lw    $s4, 0x30($sp)
/* 0D0FF8 80315FF8 8FB3002C */  lw    $s3, 0x2c($sp)
/* 0D0FFC 80315FFC 8FB20028 */  lw    $s2, 0x28($sp)
/* 0D1000 80316000 8FB10024 */  lw    $s1, 0x24($sp)
/* 0D1004 80316004 8FB00020 */  lw    $s0, 0x20($sp)
/* 0D1008 80316008 03E00008 */  jr    $ra
/* 0D100C 8031600C 27BD0170 */   addiu $sp, $sp, 0x170
)
// clang-format on
#endif

#endif

u64 *func_80314F08(u64 *arg0, struct Struct_func_80318870 *arg1, s32 arg2)
{
    s32 a3;
    s32 i;
    //                fl, dmemin, dmemout, count
    aSetBuffer(arg0++, 0, 0x180, 0, sizeof(arg1->unk34->unk110)); //interesting that it's 128...
    aLoadBuffer(arg0++, FIX(arg1->unk34->unk110));
    arg1->unk14 = (arg1->unk5 - 1) & arg1->unk14;
    a3 = 64 - arg1->unk14;
    if (a3 < arg2)
    {
        for (i = 0; i <= (arg2 - a3 + 0x3f) / (1 << 6) - 1; i++)
        {
            //                dmemin dmemout       count
            aDMEMMove(arg0++, 0x180, 512 + i * sizeof(arg1->unk34->unk110), sizeof(arg1->unk34->unk110))
        }
    }
    return arg0;
}

u64 *func_80314FD4(u64 *arg0, struct Struct_func_80318870 *arg1, s32 arg2, u16 arg3, u16 arg4, u32 arg5)
{
    aSetBuffer(arg0++, 0, arg4, 0, arg2);
    aResample(arg0++, arg5, arg3, FIX(arg1->unk34->unk20));
    return arg0;
}
u64 *func_80315030(u64 *arg0, struct Struct_func_80318870 *arg1, u32 arg2, u16 arg3, s32 arg4, UNUSED u32 arg5)
{
    UNUSED u8 pad[16];
    u16 sp20[4];
    sp20[0] = arg1->unk9C;
    sp20[1] = arg1->unk9E;
    sp20[2] = arg1->unk3C;
    sp20[3] = arg1->unk3E;
    arg1->unk9C = sp20[2];
    arg1->unk9E = sp20[3];
    return func_80315094(arg0, arg1, arg2, arg3, arg4, sp20);
}

u64 *func_80315094(u64 *audio_cmd, struct Struct_func_80318870 *arg1, u32 arg2, u16 arg3, s32 arg4, u16 *arg5)
{
    UNUSED u8 pad[3];
    u8 t1;
    UNUSED u8 pad2[8];
    s32 spac, v0;
    if (arg1->unk1)
    {
        aClearBuffer(audio_cmd++, 0x200, 320);

        switch (arg4)
        {
        case 1:
            aSetBuffer(audio_cmd++, 0, arg3, 0x200, arg2 * 2);
            aSetBuffer(audio_cmd++, 8, 0x600, 0x740, 0x880);
            break;
        case 2:
            aSetBuffer(audio_cmd++, 0, arg3, 0x4c0, arg2 * 2);
            aSetBuffer(audio_cmd++, 8, 0x200, 0x740, 0x880);
            break;
        default:
            aSetBuffer(audio_cmd++, 0, arg3, 0x4c0, arg2 * 2);
            aSetBuffer(audio_cmd++, 8, 0x600, 0x740, 0x880);
            break;
        }
    }
    else
    {
        if (arg1->unk0b4)
        {
            aClearBuffer(audio_cmd++, 0x200, 640);
            aSetBuffer(audio_cmd++, 0, arg3, 0x200, arg2 * 2);
            aSetBuffer(audio_cmd++, 8, 0x600, 0x340, 0x880);
        }
        else if (arg1->unk0b2)
        {
            aClearBuffer(audio_cmd++, 0x200, 640);
            aSetBuffer(audio_cmd++, 0, arg3, 0x4c0, arg2 * 2);
            aSetBuffer(audio_cmd++, 8, 0x200, 0x740, 0x340);
        }
        else
        {
            aSetBuffer(audio_cmd++, 0, arg3, 0x4c0, arg2 * 2);
            aSetBuffer(audio_cmd++, 8, 0x600, 0x740, 0x880);
        }
    }

    if (arg5[2] == arg5[0] && arg5[3] == arg5[1] && !arg1->unk0b8)
    {
        t1 = 0;
    }
    else
    {
        t1 = 1;
        spac = func_80313BB0(arg5[0], arg5[2], arg2);
        v0 = func_80313BB0(arg5[1], arg5[3], arg2);

        //some weird stuff is going on here.  the 4th param to these macros
        //is always zero.  I modified the macro to ignore it and just store the last
        //parameter.  however the last setVolume suggests it's still there
        //but func_80313BB0 definitely returns a s32 and spac/v0 are never &'d...
        //arg5 is volume, so spac and v0 must be rate?
        //
        aSetVolume(audio_cmd++, 6, arg5[0], 0, 0);
        aSetVolume(audio_cmd++, 4, arg5[1], 0, 0);
        aSetVolume(audio_cmd++, 2, arg5[2], 0, spac);
        aSetVolume(audio_cmd++, 0, arg5[3], 0, v0);
        aSetVolume(audio_cmd++, 8, D_802212A0, 0, arg1->unkA0 & 0xffff);
    }
    if (D_802211B0.unk1 && arg1->unk40)
    {
        aEnvMixer(audio_cmd++, t1 | 8, FIX(arg1->unk34->unk40));
        if (arg1->unk0b4)
        {
            aSetBuffer(audio_cmd++, 0, 0, 0, arg2 * 2);
            aMix(audio_cmd++, 0, 0x8000, 0x200, 0x4c0);
            aMix(audio_cmd++, 0, 0x8000, 0x340, 0x740);
        }
        else if (arg1->unk0b2)
        {
            aSetBuffer(audio_cmd++, 0, 0, 0, arg2 * 2);
            aMix(audio_cmd++, 0, 0x8000, 0x200, 0x600);
            aMix(audio_cmd++, 0, 0x8000, 0x340, 0x880);
        }
    }
    else
    {
        aEnvMixer(audio_cmd++, t1, FIX(arg1->unk34->unk40));
        if (arg1->unk0b4)
        {
            aSetBuffer(audio_cmd++, 0, 0, 0, arg2 * 2);
            aMix(audio_cmd++, 0, 0x8000, 0x200, 0x4c0);
        }
        else if (arg1->unk0b2)
        {
            aSetBuffer(audio_cmd++, 0, 0, 0, arg2 * 2);
            aMix(audio_cmd++, 0, 0x8000, 0x200, 0x600);
        }
    }
    return audio_cmd;
}

#ifdef NON_MATCHING
u64 *func_803155F4(u64 *arg0, struct Struct_func_80318870 *arg1, u32 arg2, s32 arg3, s32 arg4)
{
    //a0 0x50
    //a1 0x54
    //a2 0x58
    //a3 0x5c
    //a4 0x60
    u32 t0;
    u16 a3;
    //u32 v1;
    u32 a2;
    u16 t2;
    s32 t3;
    register u32 v1;
    //  addiu $sp, $sp, -0x50
    //  lw    $t6, 0x60($sp)
    //  sw    $s0, 4($sp)
    //  li    $v0, 1

    //  move  $s0, $a2

    //  beq   $t6, $v0, .L80315624
    //   sw    $a3, 0x5c($sp)
    switch (arg4)
    {
    //  li    $at, 2
    //  beq   $t6, $at, .L8031563C
    //   li    $t0, 1536
    //  b     .L803159B4
    //   move  $v0, $a0
    case 1:
        //.L80315624:
        //  lhu   $a2, 0xc($a1)
        //  lhu   $a3, 0x10($a1)
        //  li    $t0, 1216
        //  sh    $zero, 0x12($a1)
        //  b     .L80315658
        //   sh    $a2, 0x10($a1)
        t0 = 0x4c0;
        arg1->unk12 = 0;
        a2 = arg1->unkC;
        a3 = arg1->unk10;
        arg1->unk10 = a2;
        break;
    case 2:
        t0 = 0x600;
        arg1->unk10 = 0;
        a2 = arg1->unkE;
        a3 = arg1->unk12;
        arg1->unk12 = a2;
        //.L8031563C:
        //  lhu   $a2, 0xe($a1)
        //  lhu   $a3, 0x12($a1)
        //  sh    $zero, 0x10($a1)
        //  b     .L80315658
        //   sh    $a2, 0x12($a1)

        break;
    default:
        return arg0;
        //  b     .L803159B4
        //   move  $v0, $a0
    }
    //.L80315658:
    //  lw    $t7, 0x5c($sp)
    //  move  $v1, $a0
    //  lui   $t9, 0xa00
    //  beq   $t7, $v0, .L803158F0
    //   lui   $t6, 0x200
    if (arg3 != 1) //A_INIT?
    {
        //s32 v1;
        //  bnez  $a3, .L80315784
        //   move  $v1, $a3
        v1 = a3;
        //#define v1 a3
        if (a3 == 0)
        {

            //  move  $t2, $a0
            //  lui   $v0, (0x0A000200 >> 16) # lui $v0, 0xa00
            //  addiu $a0, $a0, 8
            //  li    $t8, 8
            //  ori   $v0, (0x0A000200 & 0xFFFF) # ori $v0, $v0, 0x200
            //  sw    $t8, 4($t2)
            //  move  $t3, $a0
            //  lui   $t9, (0x02000008 >> 16) # lui $t9, 0x200
            //  sw    $v0, ($t2)
            aDMEMMove(arg0++, 0x200, 0, 8);
            //  ori   $t9, (0x02000008 & 0xFFFF) # ori $t9, $t9, 8
            //  addiu $a0, $a0, 8
            //  sw    $t9, ($t3)
            //  li    $t6, 8
            //  move  $t4, $a0
            //  sw    $t6, 4($t3)

            aClearBuffer(arg0++, 8, 8);

            //  addiu $a0, $a0, 8
            //  lui   $t7, (0x00100010 >> 16) # lui $t7, 0x10
            //  ori   $t7, (0x00100010 & 0xFFFF) # ori $t7, $t7, 0x10
            //  move  $t5, $a0
            //  sw    $t7, 4($t4)
            //  sw    $v0, ($t4)
            aDMEMMove(arg0++, 0x200, 0x10, 0x10);
            //  li    $t9, 32
            //  lui   $t8, 0x800
            //  sw    $t8, ($t5)
            //  sw    $t9, 4($t5)
            aSetBuffer(arg0++, 0, 0, 0, 32);
            //  addiu $a0, $a0, 8
            //  sw    $a0, 8($sp)
            //  lw    $t7, 8($sp)
            //  lui   $t6, 0x600
            //  lui   $t1, (0x80000090 >> 16) # lui $t1, 0x8000
            //  sw    $t6, ($t7)
            //  lw    $t8, 0x34($a1)
            //  ori   $t1, (0x80000090 & 0xFFFF) # ori $t1, $t1, 0x90
            //  addiu $a0, $a0, 8
            //  addu  $t9, $t8, $t1
            //  addu  $t8, $a2, $s0
            //  sw    $t9, 4($t7)
            aSaveBuffer(arg0++, FIX(arg1->unk34->unk90));
//  subu  $t3, $t8, $v1
//  sll   $t9, $s0, 0xf
//  addiu $t7, $t3, 8
//  div   $zero, $t9, $t7
//  move  $t2, $a0
//  lui   $t6, (0x08000208 >> 16) # lui $t6, 0x800
//  mflo  $t8
//  ori   $t6, (0x08000208 & 0xFFFF) # ori $t6, $t6, 0x208
//  addiu $a0, $a0, 8
//  andi  $v0, $t3, 0xffff
//  sw    $v0, 4($t2)
//  sw    $t6, ($t2)
//t3 = a2 + arg2 - v1;
#define t3 (a2 + arg2 - v1)
            aSetBuffer(arg0++, 0, 0x208, 0, t3);
            //  move  $t4, $a0
            //  addiu $a0, $a0, 8
            //  bnez  $t7, .L8031574C
            //   nop
            //  break 7
            //.L8031574C:
            //  li    $at, -1
            //  bne   $t7, $at, .L80315764
            //   lui   $at, 0x8000
            //  bne   $t9, $at, .L80315764
            //   nop
            //  break 6
            //.L80315764:
            //  lui   $at, 0x500
            //  andi  $t9, $t8, 0xffff
            //  or    $t7, $t9, $at
            //  sw    $t7, ($t4)
            //  lw    $t6, 0x34($a1)
            //  addu  $t8, $t6, $t1
            //  b     .L80315860
            //   sw    $t8, 4($t4)
            aResample(arg0++, 0, (s32)(arg2 << 0xf) / (s32)(t3 + 8), FIX(arg1->unk34->unk90));
        }
        else
        {
            //.L80315784:
            //  bnez  $a2, .L803157D8
            //   move  $v0, $a2
            if (a2 == 0)
            {
                //  subu  $t7, $s0, $v1
                //  addiu $t6, $t7, -4
                //  sll   $t9, $s0, 0xf
                //  div   $zero, $t9, $t6
                //  mflo  $t2
                //  andi  $t8, $t2, 0xffff
                //  bnez  $t6, .L803157B0
                //   nop
                //  break 7
                //.L803157B0:
                //  li    $at, -1
                //  bne   $t6, $at, .L803157C8
                //   lui   $at, 0x8000
                //  bne   $t9, $at, .L803157C8
                //   nop
                //  break 6
                //.L803157C8:
                //  addu  $t7, $v0, $s0
                //  subu  $t3, $t7, $v1
                //  b     .L80315818
                //   move  $t2, $t8

                //t3 = a2 + arg2 - v1;

                t2 = (s32)(arg2 << 0xf) / (s32)(arg2 - v1 - 4);
            }
            else
            {
                //.L803157D8:
                //  addu  $t9, $s0, $v0
                //  subu  $t3, $t9, $v1

                //  sll   $t6, $s0, 0xf
                //  div   $zero, $t6, $t3
                //  mflo  $t2
                //  andi  $t8, $t2, 0xffff
                //  move  $t2, $t8
                t2 = (s32)(arg2 << 0xf) / (s32)(t3);
                //  bnez  $t3, .L80315800
                //   nop
                //  break 7
                //.L80315800:
                //  li    $at, -1
                //  bne   $t3, $at, .L80315818
                //   lui   $at, 0x8000
                //  bne   $t6, $at, .L80315818
                //   nop
                //  break 6
            }
            //.L80315818:
            //  move  $t4, $a0
            //  lui   $t7, (0x08000200 >> 16) # lui $t7, 0x800
            //  ori   $t7, (0x08000200 & 0xFFFF) # ori $t7, $t7, 0x200
            //  addiu $a0, $a0, 8
            //  andi  $v0, $t3, 0xffff
            //  andi  $t9, $t2, 0xffff
            //  lui   $at, 0x500
            //  sw    $v0, 4($t4)
            //  sw    $t7, ($t4)
            aSetBuffer(arg0++, 0, 0x200, 0, t3);
            //  or    $t6, $t9, $at
            //  move  $t5, $a0
            //  sw    $t6, ($t5)
            //  lw    $t8, 0x34($a1)
            //  lui   $t1, (0x80000090 >> 16) # $t1, 0x8000
            //  ori   $t1, (0x80000090 & 0xFFFF) # ori $t1, $t1, 0x90
            //  addu  $t7, $t8, $t1
            //  sw    $t7, 4($t5)
            aResample(arg0++, 0, t2, FIX(arg1->unk34->unk90));
            //  addiu $a0, $a0, 8
        }
        //.L80315860:
        //  beqz  $v1, .L803158D0
        //   lui   $t8, 0xa00
        if (v1 > 0)
        {
            //  move  $t1, $a0
            //  lui   $t9, (0x08000200 >> 16) # lui $t9, 0x800
            //  ori   $t9, (0x08000200 & 0xFFFF) # ori $t9, $t9, 0x200
            //  addiu $a0, $a0, 8
            //  andi  $t6, $a3, 0xffff
            //  sw    $t6, 4($t1)
            //  sw    $t9, ($t1)
            aSetBuffer(arg0++, 0, 0x200, 0, a3);
            //  move  $t2, $a0
            //  lui   $t8, 0x400
            //  sw    $t8, ($t2)
            //  lw    $t7, 0x34($a1)
            //  lui   $at, (0x800000B0 >> 16) # lui $at, 0x8000
            //  ori   $at, (0x800000B0 & 0xFFFF) # ori $at, $at, 0xb0
            //  addu  $t9, $t7, $at
            //  sw    $t9, 4($t2)
            aLoadBuffer(arg0++, FIX(arg1->unk34->unkb0));
            //  addiu $a0, $a0, 8
            //  move  $t3, $a0
            //  addiu $t7, $v1, 0x200
            //  lui   $t6, (0x0A000200 >> 16) # lui $t6, 0xa00
            //  sw    $t6, ($t3)
            //  sll   $t9, $t7, 0x10
            //  or    $t6, $t9, $v0
            //  sw    $t6, 4($t3)
            aDMEMMove(arg0++, 0, v1 + 0x200, t3); 
            //  addiu $a0, $a0, 8
            //  b     .L80315938
            //   andi  $a3, $s0, 0xffff
            //a3 = arg2;
        }
        else
        {
            //.L803158D0:
            //  move  $v1, $a0
            //  lui   $at, 0x200
            //  or    $t7, $v0, $at
            //  sw    $t7, 4($v1)
            //  sw    $t8, ($v1)
            aDMEMMove(arg0++, 0, 0x200, t3);
            //  addiu $a0, $a0, 8
            //  b     .L80315938
            //   andi  $a3, $s0, 0xffff
        }
    }
    else
    {
        //.L803158F0:
        //  lui   $v0, (0x0A000200 >> 16) # $v0, 0xa00
        //  addiu $a0, $a0, 8
        //  ori   $v0, (0x0A000200 & 0xFFFF) # ori $v0, $v0, 0x200
        //  andi  $a3, $s0, 0xffff
        //  move  $t1, $a0
        //  sw    $a3, 4($v1)
        //  sw    $v0, ($v1)
        aDMEMMove(arg0++, 0x200, 0, arg2);
        //  addiu $t8, $a2, 0x200
        //  sll   $t7, $t8, 0x10
        //  sw    $t9, ($t1)
        //  addiu $a0, $a0, 8
        //  or    $t9, $t7, $a3
        //  move  $t2, $a0
        //  sw    $t9, 4($t1)
        aDMEMMove(arg0++, 0, a2 + 0x200, arg2);
        //  ori   $t6, (0x0A000200 & 0xFFFF) # ori $t6, $t6, 0x200
        //  sw    $t6, ($t2)
        //  sw    $a2, 4($t2)
        aClearBuffer(arg0++, 0x200, a2);
        //  addiu $a0, $a0, 8
    }
    //.L80315938:
    //  beqz  $a2, .L80315984
    //   move  $v0, $a0
    if (a2)
    {
        //  lui   $t8, 0x800
        //  sw    $t8, ($v0)
        //  addiu $t9, $s0, 0x200
        //  sll   $t6, $t9, 0x10
        //  andi  $t8, $a2, 0xffff
        //  or    $t7, $t6, $t8
        //  addiu $a0, $a0, 8
        //  sw    $t7, 4($v0)
        aSetBuffer(arg0++, 0, 0, arg2 + 0x200, a2);
        //  move  $v1, $a0
        //  lui   $t9, 0x600
        //  sw    $t9, ($v1)
        //  lw    $t6, 0x34($a1)
        //  lui   $at, (0x800000B0 >> 16) # lui $at, 0x8000
        //  ori   $at, (0x800000B0 & 0xFFFF) # ori $at, $at, 0xb0
        //  addu  $t8, $t6, $at
        //  sw    $t8, 4($v1)
        aSaveBuffer(arg0++, FIX(arg1->unk34->unkb0));
        //  addiu $a0, $a0, 8
    }
    //.L80315984:
    //  addiu $a1, $a0, 8
    //  lui   $t7, 0x800
    //  sw    $t7, ($a0)
    //  sw    $a3, 4($a0)
    aSetBuffer(arg0++, 0, 0, 0, arg2);
    //  lui   $t9, (0x0C007FFF >> 16) # lui $t9, 0xc00
    //  andi  $t6, $t0, 0xffff
    //  lui   $at, 0x200
    //  or    $t8, $t6, $at
    //  ori   $t9, (0x0C007FFF & 0xFFFF) # ori $t9, $t9, 0x7fff
    //  sw    $t9, ($a1)
    //  sw    $t8, 4($a1)
    aMix(arg0++, 0, 0x7fff, 0x200, t0);

    //  addiu $v0, $a1, 8
    //.L803159B4:
    //  lw    $s0, 4($sp)
    //  jr    $ra
    //   addiu $sp, $sp, 0x50
    *(u32 *)arg0++ = 0;
    *(u32 *)arg0++ = 0;
    return arg0;
}
#else

// clang-format off
GLOBAL_ASM(

glabel func_803155F4
/* 0D05F4 803155F4 27BDFFB0 */  addiu $sp, $sp, -0x50
/* 0D05F8 803155F8 8FAE0060 */  lw    $t6, 0x60($sp)
/* 0D05FC 803155FC AFB00004 */  sw    $s0, 4($sp)
/* 0D0600 80315600 24020001 */  li    $v0, 1
/* 0D0604 80315604 00C08025 */  move  $s0, $a2
/* 0D0608 80315608 11C20006 */  beq   $t6, $v0, .L80315624
/* 0D060C 8031560C AFA7005C */   sw    $a3, 0x5c($sp)
/* 0D0610 80315610 24010002 */  li    $at, 2
/* 0D0614 80315614 11C10009 */  beq   $t6, $at, .L8031563C
/* 0D0618 80315618 24080600 */   li    $t0, 1536
/* 0D061C 8031561C 100000E5 */  b     .L803159B4
/* 0D0620 80315620 00801025 */   move  $v0, $a0
.L80315624:
/* 0D0624 80315624 94A6000C */  lhu   $a2, 0xc($a1)
/* 0D0628 80315628 94A70010 */  lhu   $a3, 0x10($a1)
/* 0D062C 8031562C 240804C0 */  li    $t0, 1216
/* 0D0630 80315630 A4A00012 */  sh    $zero, 0x12($a1)
/* 0D0634 80315634 10000008 */  b     .L80315658
/* 0D0638 80315638 A4A60010 */   sh    $a2, 0x10($a1)
.L8031563C:
/* 0D063C 8031563C 94A6000E */  lhu   $a2, 0xe($a1)
/* 0D0640 80315640 94A70012 */  lhu   $a3, 0x12($a1)
/* 0D0644 80315644 A4A00010 */  sh    $zero, 0x10($a1)
/* 0D0648 80315648 10000003 */  b     .L80315658
/* 0D064C 8031564C A4A60012 */   sh    $a2, 0x12($a1)
/* 0D0650 80315650 100000D8 */  b     .L803159B4
/* 0D0654 80315654 00801025 */   move  $v0, $a0
.L80315658:
/* 0D0658 80315658 8FAF005C */  lw    $t7, 0x5c($sp)
/* 0D065C 8031565C 00801825 */  move  $v1, $a0
/* 0D0660 80315660 3C190A00 */  lui   $t9, 0xa00
/* 0D0664 80315664 11E200A2 */  beq   $t7, $v0, .L803158F0
/* 0D0668 80315668 3C0E0200 */   lui   $t6, 0x200
/* 0D066C 8031566C 14E00045 */  bnez  $a3, .L80315784
/* 0D0670 80315670 00E01825 */   move  $v1, $a3
/* 0D0674 80315674 00805025 */  move  $t2, $a0
/* 0D0678 80315678 3C020A00 */  lui   $v0, (0x0A000200 >> 16) # lui $v0, 0xa00
/* 0D067C 8031567C 24840008 */  addiu $a0, $a0, 8
/* 0D0680 80315680 24180008 */  li    $t8, 8
/* 0D0684 80315684 34420200 */  ori   $v0, (0x0A000200 & 0xFFFF) # ori $v0, $v0, 0x200
/* 0D0688 80315688 AD580004 */  sw    $t8, 4($t2)
/* 0D068C 8031568C 00805825 */  move  $t3, $a0
/* 0D0690 80315690 3C190200 */  lui   $t9, (0x02000008 >> 16) # lui $t9, 0x200
/* 0D0694 80315694 AD420000 */  sw    $v0, ($t2)
/* 0D0698 80315698 37390008 */  ori   $t9, (0x02000008 & 0xFFFF) # ori $t9, $t9, 8
/* 0D069C 8031569C 24840008 */  addiu $a0, $a0, 8
/* 0D06A0 803156A0 AD790000 */  sw    $t9, ($t3)
/* 0D06A4 803156A4 240E0008 */  li    $t6, 8
/* 0D06A8 803156A8 00806025 */  move  $t4, $a0
/* 0D06AC 803156AC AD6E0004 */  sw    $t6, 4($t3)
/* 0D06B0 803156B0 24840008 */  addiu $a0, $a0, 8
/* 0D06B4 803156B4 3C0F0010 */  lui   $t7, (0x00100010 >> 16) # lui $t7, 0x10
/* 0D06B8 803156B8 35EF0010 */  ori   $t7, (0x00100010 & 0xFFFF) # ori $t7, $t7, 0x10
/* 0D06BC 803156BC 00806825 */  move  $t5, $a0
/* 0D06C0 803156C0 AD8F0004 */  sw    $t7, 4($t4)
/* 0D06C4 803156C4 AD820000 */  sw    $v0, ($t4)
/* 0D06C8 803156C8 24190020 */  li    $t9, 32
/* 0D06CC 803156CC 3C180800 */  lui   $t8, 0x800
/* 0D06D0 803156D0 ADB80000 */  sw    $t8, ($t5)
/* 0D06D4 803156D4 ADB90004 */  sw    $t9, 4($t5)
/* 0D06D8 803156D8 24840008 */  addiu $a0, $a0, 8
/* 0D06DC 803156DC AFA40008 */  sw    $a0, 8($sp)
/* 0D06E0 803156E0 8FAF0008 */  lw    $t7, 8($sp)
/* 0D06E4 803156E4 3C0E0600 */  lui   $t6, 0x600
/* 0D06E8 803156E8 3C098000 */  lui   $t1, (0x80000090 >> 16) # lui $t1, 0x8000
/* 0D06EC 803156EC ADEE0000 */  sw    $t6, ($t7)
/* 0D06F0 803156F0 8CB80034 */  lw    $t8, 0x34($a1)
/* 0D06F4 803156F4 35290090 */  ori   $t1, (0x80000090 & 0xFFFF) # ori $t1, $t1, 0x90
/* 0D06F8 803156F8 24840008 */  addiu $a0, $a0, 8
/* 0D06FC 803156FC 0309C821 */  addu  $t9, $t8, $t1
/* 0D0700 80315700 00D0C021 */  addu  $t8, $a2, $s0
/* 0D0704 80315704 ADF90004 */  sw    $t9, 4($t7)
/* 0D0708 80315708 03035823 */  subu  $t3, $t8, $v1
/* 0D070C 8031570C 0010CBC0 */  sll   $t9, $s0, 0xf
/* 0D0710 80315710 256F0008 */  addiu $t7, $t3, 8
/* 0D0714 80315714 032F001A */  div   $zero, $t9, $t7
/* 0D0718 80315718 00805025 */  move  $t2, $a0
/* 0D071C 8031571C 3C0E0800 */  lui   $t6, (0x08000208 >> 16) # lui $t6, 0x800
/* 0D0720 80315720 0000C012 */  mflo  $t8
/* 0D0724 80315724 35CE0208 */  ori   $t6, (0x08000208 & 0xFFFF) # ori $t6, $t6, 0x208
/* 0D0728 80315728 24840008 */  addiu $a0, $a0, 8
/* 0D072C 8031572C 3162FFFF */  andi  $v0, $t3, 0xffff
/* 0D0730 80315730 AD420004 */  sw    $v0, 4($t2)
/* 0D0734 80315734 AD4E0000 */  sw    $t6, ($t2)
/* 0D0738 80315738 00806025 */  move  $t4, $a0
/* 0D073C 8031573C 24840008 */  addiu $a0, $a0, 8
/* 0D0740 80315740 15E00002 */  bnez  $t7, .L8031574C
/* 0D0744 80315744 00000000 */   nop   
/* 0D0748 80315748 0007000D */  break 7
.L8031574C:
/* 0D074C 8031574C 2401FFFF */  li    $at, -1
/* 0D0750 80315750 15E10004 */  bne   $t7, $at, .L80315764
/* 0D0754 80315754 3C018000 */   lui   $at, 0x8000
/* 0D0758 80315758 17210002 */  bne   $t9, $at, .L80315764
/* 0D075C 8031575C 00000000 */   nop   
/* 0D0760 80315760 0006000D */  break 6
.L80315764:
/* 0D0764 80315764 3C010500 */  lui   $at, 0x500
/* 0D0768 80315768 3319FFFF */  andi  $t9, $t8, 0xffff
/* 0D076C 8031576C 03217825 */  or    $t7, $t9, $at
/* 0D0770 80315770 AD8F0000 */  sw    $t7, ($t4)
/* 0D0774 80315774 8CAE0034 */  lw    $t6, 0x34($a1)
/* 0D0778 80315778 01C9C021 */  addu  $t8, $t6, $t1
/* 0D077C 8031577C 10000038 */  b     .L80315860
/* 0D0780 80315780 AD980004 */   sw    $t8, 4($t4)
.L80315784:
/* 0D0784 80315784 14C00014 */  bnez  $a2, .L803157D8
/* 0D0788 80315788 00C01025 */   move  $v0, $a2
/* 0D078C 8031578C 02037823 */  subu  $t7, $s0, $v1
/* 0D0790 80315790 25EEFFFC */  addiu $t6, $t7, -4
/* 0D0794 80315794 0010CBC0 */  sll   $t9, $s0, 0xf
/* 0D0798 80315798 032E001A */  div   $zero, $t9, $t6
/* 0D079C 8031579C 00005012 */  mflo  $t2
/* 0D07A0 803157A0 3158FFFF */  andi  $t8, $t2, 0xffff
/* 0D07A4 803157A4 15C00002 */  bnez  $t6, .L803157B0
/* 0D07A8 803157A8 00000000 */   nop   
/* 0D07AC 803157AC 0007000D */  break 7
.L803157B0:
/* 0D07B0 803157B0 2401FFFF */  li    $at, -1
/* 0D07B4 803157B4 15C10004 */  bne   $t6, $at, .L803157C8
/* 0D07B8 803157B8 3C018000 */   lui   $at, 0x8000
/* 0D07BC 803157BC 17210002 */  bne   $t9, $at, .L803157C8
/* 0D07C0 803157C0 00000000 */   nop   
/* 0D07C4 803157C4 0006000D */  break 6
.L803157C8:
/* 0D07C8 803157C8 00507821 */  addu  $t7, $v0, $s0
/* 0D07CC 803157CC 01E35823 */  subu  $t3, $t7, $v1
/* 0D07D0 803157D0 10000011 */  b     .L80315818
/* 0D07D4 803157D4 03005025 */   move  $t2, $t8
.L803157D8:
/* 0D07D8 803157D8 0202C821 */  addu  $t9, $s0, $v0
/* 0D07DC 803157DC 03235823 */  subu  $t3, $t9, $v1
/* 0D07E0 803157E0 001073C0 */  sll   $t6, $s0, 0xf
/* 0D07E4 803157E4 01CB001A */  div   $zero, $t6, $t3
/* 0D07E8 803157E8 00005012 */  mflo  $t2
/* 0D07EC 803157EC 3158FFFF */  andi  $t8, $t2, 0xffff
/* 0D07F0 803157F0 03005025 */  move  $t2, $t8
/* 0D07F4 803157F4 15600002 */  bnez  $t3, .L80315800
/* 0D07F8 803157F8 00000000 */   nop   
/* 0D07FC 803157FC 0007000D */  break 7
.L80315800:
/* 0D0800 80315800 2401FFFF */  li    $at, -1
/* 0D0804 80315804 15610004 */  bne   $t3, $at, .L80315818
/* 0D0808 80315808 3C018000 */   lui   $at, 0x8000
/* 0D080C 8031580C 15C10002 */  bne   $t6, $at, .L80315818
/* 0D0810 80315810 00000000 */   nop   
/* 0D0814 80315814 0006000D */  break 6
.L80315818:
/* 0D0818 80315818 00806025 */  move  $t4, $a0
/* 0D081C 8031581C 3C0F0800 */  lui   $t7, (0x08000200 >> 16) # lui $t7, 0x800
/* 0D0820 80315820 35EF0200 */  ori   $t7, (0x08000200 & 0xFFFF) # ori $t7, $t7, 0x200
/* 0D0824 80315824 24840008 */  addiu $a0, $a0, 8
/* 0D0828 80315828 3162FFFF */  andi  $v0, $t3, 0xffff
/* 0D082C 8031582C 3159FFFF */  andi  $t9, $t2, 0xffff
/* 0D0830 80315830 3C010500 */  lui   $at, 0x500
/* 0D0834 80315834 AD820004 */  sw    $v0, 4($t4)
/* 0D0838 80315838 AD8F0000 */  sw    $t7, ($t4)
/* 0D083C 8031583C 03217025 */  or    $t6, $t9, $at
/* 0D0840 80315840 00806825 */  move  $t5, $a0
/* 0D0844 80315844 ADAE0000 */  sw    $t6, ($t5)
/* 0D0848 80315848 8CB80034 */  lw    $t8, 0x34($a1)
/* 0D084C 8031584C 3C098000 */  lui   $t1, (0x80000090 >> 16) # $t1, 0x8000
/* 0D0850 80315850 35290090 */  ori   $t1, (0x80000090 & 0xFFFF) # ori $t1, $t1, 0x90
/* 0D0854 80315854 03097821 */  addu  $t7, $t8, $t1
/* 0D0858 80315858 ADAF0004 */  sw    $t7, 4($t5)
/* 0D085C 8031585C 24840008 */  addiu $a0, $a0, 8
.L80315860:
/* 0D0860 80315860 1060001B */  beqz  $v1, .L803158D0
/* 0D0864 80315864 3C180A00 */   lui   $t8, 0xa00
/* 0D0868 80315868 00804825 */  move  $t1, $a0
/* 0D086C 8031586C 3C190800 */  lui   $t9, (0x08000200 >> 16) # lui $t9, 0x800
/* 0D0870 80315870 37390200 */  ori   $t9, (0x08000200 & 0xFFFF) # ori $t9, $t9, 0x200
/* 0D0874 80315874 24840008 */  addiu $a0, $a0, 8
/* 0D0878 80315878 30EEFFFF */  andi  $t6, $a3, 0xffff
/* 0D087C 8031587C AD2E0004 */  sw    $t6, 4($t1)
/* 0D0880 80315880 AD390000 */  sw    $t9, ($t1)
/* 0D0884 80315884 00805025 */  move  $t2, $a0
/* 0D0888 80315888 3C180400 */  lui   $t8, 0x400
/* 0D088C 8031588C AD580000 */  sw    $t8, ($t2)
/* 0D0890 80315890 8CAF0034 */  lw    $t7, 0x34($a1)
/* 0D0894 80315894 3C018000 */  lui   $at, (0x800000B0 >> 16) # lui $at, 0x8000
/* 0D0898 80315898 342100B0 */  ori   $at, (0x800000B0 & 0xFFFF) # ori $at, $at, 0xb0
/* 0D089C 8031589C 01E1C821 */  addu  $t9, $t7, $at
/* 0D08A0 803158A0 AD590004 */  sw    $t9, 4($t2)
/* 0D08A4 803158A4 24840008 */  addiu $a0, $a0, 8
/* 0D08A8 803158A8 00805825 */  move  $t3, $a0
/* 0D08AC 803158AC 246F0200 */  addiu $t7, $v1, 0x200
/* 0D08B0 803158B0 3C0E0A00 */  lui   $t6, (0x0A000200 >> 16) # lui $t6, 0xa00
/* 0D08B4 803158B4 AD6E0000 */  sw    $t6, ($t3)
/* 0D08B8 803158B8 000FCC00 */  sll   $t9, $t7, 0x10
/* 0D08BC 803158BC 03227025 */  or    $t6, $t9, $v0
/* 0D08C0 803158C0 AD6E0004 */  sw    $t6, 4($t3)
/* 0D08C4 803158C4 24840008 */  addiu $a0, $a0, 8
/* 0D08C8 803158C8 1000001B */  b     .L80315938
/* 0D08CC 803158CC 3207FFFF */   andi  $a3, $s0, 0xffff
.L803158D0:
/* 0D08D0 803158D0 00801825 */  move  $v1, $a0
/* 0D08D4 803158D4 3C010200 */  lui   $at, 0x200
/* 0D08D8 803158D8 00417825 */  or    $t7, $v0, $at
/* 0D08DC 803158DC AC6F0004 */  sw    $t7, 4($v1)
/* 0D08E0 803158E0 AC780000 */  sw    $t8, ($v1)
/* 0D08E4 803158E4 24840008 */  addiu $a0, $a0, 8
/* 0D08E8 803158E8 10000013 */  b     .L80315938
/* 0D08EC 803158EC 3207FFFF */   andi  $a3, $s0, 0xffff
.L803158F0:
/* 0D08F0 803158F0 3C020A00 */  lui   $v0, (0x0A000200 >> 16) # $v0, 0xa00
/* 0D08F4 803158F4 24840008 */  addiu $a0, $a0, 8
/* 0D08F8 803158F8 34420200 */  ori   $v0, (0x0A000200 & 0xFFFF) # ori $v0, $v0, 0x200
/* 0D08FC 803158FC 3207FFFF */  andi  $a3, $s0, 0xffff
/* 0D0900 80315900 00804825 */  move  $t1, $a0
/* 0D0904 80315904 AC670004 */  sw    $a3, 4($v1)
/* 0D0908 80315908 AC620000 */  sw    $v0, ($v1)
/* 0D090C 8031590C 24D80200 */  addiu $t8, $a2, 0x200
/* 0D0910 80315910 00187C00 */  sll   $t7, $t8, 0x10
/* 0D0914 80315914 AD390000 */  sw    $t9, ($t1)
/* 0D0918 80315918 24840008 */  addiu $a0, $a0, 8
/* 0D091C 8031591C 01E7C825 */  or    $t9, $t7, $a3
/* 0D0920 80315920 00805025 */  move  $t2, $a0
/* 0D0924 80315924 AD390004 */  sw    $t9, 4($t1)
/* 0D0928 80315928 35CE0200 */  ori   $t6, (0x0A000200 & 0xFFFF) # ori $t6, $t6, 0x200
/* 0D092C 8031592C AD4E0000 */  sw    $t6, ($t2)
/* 0D0930 80315930 AD460004 */  sw    $a2, 4($t2)
/* 0D0934 80315934 24840008 */  addiu $a0, $a0, 8
.L80315938:
/* 0D0938 80315938 10C00012 */  beqz  $a2, .L80315984
/* 0D093C 8031593C 00801025 */   move  $v0, $a0
/* 0D0940 80315940 3C180800 */  lui   $t8, 0x800
/* 0D0944 80315944 AC580000 */  sw    $t8, ($v0)
/* 0D0948 80315948 26190200 */  addiu $t9, $s0, 0x200
/* 0D094C 8031594C 00197400 */  sll   $t6, $t9, 0x10
/* 0D0950 80315950 30D8FFFF */  andi  $t8, $a2, 0xffff
/* 0D0954 80315954 01D87825 */  or    $t7, $t6, $t8
/* 0D0958 80315958 24840008 */  addiu $a0, $a0, 8
/* 0D095C 8031595C AC4F0004 */  sw    $t7, 4($v0)
/* 0D0960 80315960 00801825 */  move  $v1, $a0
/* 0D0964 80315964 3C190600 */  lui   $t9, 0x600
/* 0D0968 80315968 AC790000 */  sw    $t9, ($v1)
/* 0D096C 8031596C 8CAE0034 */  lw    $t6, 0x34($a1)
/* 0D0970 80315970 3C018000 */  lui   $at, (0x800000B0 >> 16) # lui $at, 0x8000
/* 0D0974 80315974 342100B0 */  ori   $at, (0x800000B0 & 0xFFFF) # ori $at, $at, 0xb0
/* 0D0978 80315978 01C1C021 */  addu  $t8, $t6, $at
/* 0D097C 8031597C AC780004 */  sw    $t8, 4($v1)
/* 0D0980 80315980 24840008 */  addiu $a0, $a0, 8
.L80315984:
/* 0D0984 80315984 24850008 */  addiu $a1, $a0, 8
/* 0D0988 80315988 3C0F0800 */  lui   $t7, 0x800
/* 0D098C 8031598C AC8F0000 */  sw    $t7, ($a0)
/* 0D0990 80315990 AC870004 */  sw    $a3, 4($a0)
/* 0D0994 80315994 3C190C00 */  lui   $t9, (0x0C007FFF >> 16) # lui $t9, 0xc00
/* 0D0998 80315998 310EFFFF */  andi  $t6, $t0, 0xffff
/* 0D099C 8031599C 3C010200 */  lui   $at, 0x200
/* 0D09A0 803159A0 01C1C025 */  or    $t8, $t6, $at
/* 0D09A4 803159A4 37397FFF */  ori   $t9, (0x0C007FFF & 0xFFFF) # ori $t9, $t9, 0x7fff
/* 0D09A8 803159A8 ACB90000 */  sw    $t9, ($a1)
/* 0D09AC 803159AC ACB80004 */  sw    $t8, 4($a1)
/* 0D09B0 803159B0 24A20008 */  addiu $v0, $a1, 8
.L803159B4:
/* 0D09B4 803159B4 8FB00004 */  lw    $s0, 4($sp)
/* 0D09B8 803159B8 03E00008 */  jr    $ra
/* 0D09BC 803159BC 27BD0050 */   addiu $sp, $sp, 0x50
)
// clang-format on

#endif

void func_803159C0(struct Struct_func_80318870 *arg0)
{
    arg0->unk3C = 0;
    arg0->unk3E = 0;
    arg0->unk40 = 0;
    arg0->unkA0 = 0;
    arg0->unkA2 = 0;
    arg0->unk9C = 1;
    arg0->unk9E = 1;
    arg0->unk38 = 0.0f;
}

void func_803159EC(struct Struct_func_80318870 *arg0, f32 arg1, f32 arg2, u8 arg3)
{
    s32 v0;
    f32 f0;
    f32 f2;
#ifdef VERSION_JP
    v0 = MIN((s32)(arg2 * 127.5), 127);
#endif
    if (arg0->unk0b1 && D_80226D7F == 1)
    {
        s8 a1;
        a1 = MIN((s8)(arg2 * 10.0f), 9);
        arg0->unkE = D_80332CD0[a1];
        arg0->unkC = D_80332CD0[9 - a1];
        arg0->unk0b4 = 0;
        arg0->unk0b2 = 0;
        arg0->unk1 = 1;
#ifdef VERSION_US
        v0 = (s32)(arg2 * 127.5f) & 127;
#endif
        f0 = D_80332CE4[v0];
        f2 = D_80332CE4[127 - v0];
    }
    else if (arg0->unk0b1 && D_80226D7F == 0)
    {
        u8 v1 = 0;
        u8 a1 = 0;
        arg0->unkE = 0;
        arg0->unkC = 0;
        arg0->unk1 = 0;
#ifdef VERSION_US
        v0 = (s32)(arg2 * 127.5f) & 127;
#endif
        f0 = D_80332EE4[v0];
        f2 = D_80332EE4[127 - v0];
        if (v0 < 0x20)
        {
            v1 = 1;
        }
        else if (v0 > 0x60)
        {
            a1 = 1;
        }
        arg0->unk0b4 = a1;
        arg0->unk0b2 = v1;
    }
    else if (D_80226D7F == 3)
    {
        f0 = .707f;
        f2 = .707f;
    }
    else
    {
#ifdef VERSION_US
        v0 = (s32)(arg2 * 127.5f) & 127;
#endif
        f0 = D_803330E4[v0];
        f2 = D_803330E4[127 - v0];
    }

    arg1 = MAX(arg1, 0);
#ifdef VERSION_JP
    arg0->unk3C = ((u16)(arg1 * f0)) & -0x8100;
    arg0->unk3E = ((u16)(arg1 * f2)) & -0x8100;
#else
    arg0->unk3C = (u16)((s32)(arg1 * f0)) & -0x8100;
    arg0->unk3E = (u16)((s32)(arg1 * f2)) & -0x8100;
#endif
    if (arg0->unk3C == 0)
    {
        arg0->unk3C++;
    }
    if (arg0->unk3E == 0)
    {
        arg0->unk3E++;
    }
    if (arg0->unk40 != arg3)
    {
        arg0->unk40 = arg3;
        arg0->unkA0 = arg3 << 8;
        arg0->unk0b8 = 1;
        return;
    }
    if (arg0->unk0b40)
    {
        arg0->unk0b8 = 1;
        return;
    }
    arg0->unk0b8 = 0;
    return;
}

void func_80315D88(struct Struct_func_80318870 *arg0, f32 arg1)
{
    arg0->unk38 = arg1;
}

//init something?
void func_80315D94(struct Struct_func_80318870 *arg0)
{
    arg0->unk1 = 0;
    arg0->unkE = 0;
    arg0->unk0b80 = 1;
    arg0->unk0b40 = 1;
    arg0->unk0b20 = 0;
    arg0->unk0b10 = 0;
    arg0->unk0b4 = 0;
    arg0->unk0b2 = 0;
    arg0->unkC = 0;
    arg0->unk10 = 0;
    arg0->unk12 = 0;
}
void func_80315DE0(struct Struct_func_80318870 *arg0)
{
    if (arg0->unk0b40 == 1)
    {
        arg0->unk0b40 = 0;
    }
    else
    {
        func_803159EC(arg0, 0, .5, 0);
    }
    arg0->unk4 = 0;
    arg0->unk0b80 = 0;
    arg0->unk0b10 = 0;
    arg0->unk2C = MINUS_ONE; //I don't like this...
    arg0->unk28 = MINUS_ONE; //okay apparently this is in playback.c too
}
