#include <ultra64.h>

#include "sm64.h"
#include "playback.h"
#include "dac.h"

// rodata

#ifdef VERSION_JP
extern f64 D_80337C38;
extern f64 D_80337C40;
extern f64 D_80337C48;
extern f64 D_80337C50;
#else
extern f32 D_U_80338E18;
extern f32 D_U_80338E1C;
extern f32 D_U_80338E20;
extern f32 D_U_80338E24;
#endif

void func_80318870(struct Struct_func_80318870 *arg0)
{
    if (arg0->unk2C->unk14 == 0)
    {
        func_8031A564(&arg0->unk54, arg0->unk2C->unk50->unk7C, &arg0->unk8);
    }
    else
    {
        func_8031A564(&arg0->unk54, arg0->unk2C->unk18, &arg0->unk8);
    }
    arg0->unk55 = 1;
    func_803159C0(arg0);
    func_80315D94(arg0);
}

void func_803188E8(u32 arg0)
{
    func_80315DE0(arg0);
}

#ifdef VERSION_JP
GLOBAL_ASM(
glabel func_80318908
/* 0D3908 80318908 27BDFFA0 */  addiu $sp, $sp, -0x60
/* 0D390C 8031890C 3C028022 */  lui   $v0, %hi(D_80226D70) # $v0, 0x8022
/* 0D3910 80318910 8C426D70 */  lw    $v0, %lo(D_80226D70)($v0)
/* 0D3914 80318914 AFBF0044 */  sw    $ra, 0x44($sp)
/* 0D3918 80318918 AFB40040 */  sw    $s4, 0x40($sp)
/* 0D391C 8031891C AFB3003C */  sw    $s3, 0x3c($sp)
/* 0D3920 80318920 AFB20038 */  sw    $s2, 0x38($sp)
/* 0D3924 80318924 AFB10034 */  sw    $s1, 0x34($sp)
/* 0D3928 80318928 AFB00030 */  sw    $s0, 0x30($sp)
/* 0D392C 8031892C F7B80028 */  sdc1  $f24, 0x28($sp)
/* 0D3930 80318930 F7B60020 */  sdc1  $f22, 0x20($sp)
/* 0D3934 80318934 184000ED */  blez  $v0, .L80318CEC
/* 0D3938 80318938 F7B40018 */   sdc1  $f20, 0x18($sp)
/* 0D393C 8031893C 3C018033 */  lui   $at, %hi(D_80337C20)
/* 0D3940 80318940 C4387C20 */  lwc1  $f24, %lo(D_80337C20)($at)
/* 0D3944 80318944 3C018033 */  lui   $at, %hi(D_80337C28)
/* 0D3948 80318948 3C118022 */  lui   $s1, %hi(D_80225EA8) # $s1, 0x8022
/* 0D394C 8031894C 26315EA8 */  addiu $s1, %lo(D_80225EA8) # addiu $s1, $s1, 0x5ea8
/* 0D3950 80318950 D4367C28 */  ldc1  $f22, %lo(D_80337C28)($at)
/* 0D3954 80318954 00009025 */  move  $s2, $zero
/* 0D3958 80318958 2414FFFF */  li    $s4, -1
/* 0D395C 8031895C 24130001 */  li    $s3, 1
.L80318960:
/* 0D3960 80318960 3C0E8022 */  lui   $t6, %hi(D_80222A10) # $t6, 0x8022
/* 0D3964 80318964 8DCE2A10 */  lw    $t6, %lo(D_80222A10)($t6)
/* 0D3968 80318968 024E8021 */  addu  $s0, $s2, $t6
/* 0D396C 8031896C 92030004 */  lbu   $v1, 4($s0)
/* 0D3970 80318970 506000D8 */  beql  $v1, $zero, .L80318CD4
/* 0D3974 80318974 00021880 */   sll   $v1, $v0, 2
/* 0D3978 80318978 52630006 */  beql  $s3, $v1, .L80318994
/* 0D397C 8031897C 86080008 */   lh    $t0, 8($s0)
/* 0D3980 80318980 8E0F0000 */  lw    $t7, ($s0)
/* 0D3984 80318984 000FC8C0 */  sll   $t9, $t7, 3
/* 0D3988 80318988 07230076 */  bgezl $t9, .L80318B64
/* 0D398C 8031898C 92080055 */   lbu   $t0, 0x55($s0)
/* 0D3990 80318990 86080008 */  lh    $t0, 8($s0)
.L80318994:
/* 0D3994 80318994 51000006 */  beql  $t0, $zero, .L803189B0
/* 0D3998 80318998 8E0C0030 */   lw    $t4, 0x30($s0)
/* 0D399C 8031899C 8E090000 */  lw    $t1, ($s0)
/* 0D39A0 803189A0 000958C0 */  sll   $t3, $t1, 3
/* 0D39A4 803189A4 05610088 */  bgez  $t3, .L80318BC8
/* 0D39A8 803189A8 00000000 */   nop   
/* 0D39AC 803189AC 8E0C0030 */  lw    $t4, 0x30($s0)
.L803189B0:
/* 0D39B0 803189B0 128C0054 */  beq   $s4, $t4, .L80318B04
/* 0D39B4 803189B4 00000000 */   nop   
/* 0D39B8 803189B8 0C0C623A */  jal   func_803188E8
/* 0D39BC 803189BC 02002025 */   move  $a0, $s0
/* 0D39C0 803189C0 8E050030 */  lw    $a1, 0x30($s0)
/* 0D39C4 803189C4 8CAD0050 */  lw    $t5, 0x50($a1)
/* 0D39C8 803189C8 11A00036 */  beqz  $t5, .L80318AA4
/* 0D39CC 803189CC 00000000 */   nop   
/* 0D39D0 803189D0 0C0C6598 */  jal   func_80319660
/* 0D39D4 803189D4 02002025 */   move  $a0, $s0
/* 0D39D8 803189D8 1453001E */  bne   $v0, $s3, .L80318A54
/* 0D39DC 803189DC 00000000 */   nop   
/* 0D39E0 803189E0 0C0C623A */  jal   func_803188E8
/* 0D39E4 803189E4 02002025 */   move  $a0, $s0
/* 0D39E8 803189E8 8E0200A4 */  lw    $v0, 0xa4($s0)
/* 0D39EC 803189EC 260500A4 */  addiu $a1, $s0, 0xa4
/* 0D39F0 803189F0 10400009 */  beqz  $v0, .L80318A18
/* 0D39F4 803189F4 00000000 */   nop   
/* 0D39F8 803189F8 8CAE0004 */  lw    $t6, 4($a1)
/* 0D39FC 803189FC 8CAF0000 */  lw    $t7, ($a1)
/* 0D3A00 80318A00 ADEE0004 */  sw    $t6, 4($t7)
/* 0D3A04 80318A04 8CB80000 */  lw    $t8, ($a1)
/* 0D3A08 80318A08 8CB90004 */  lw    $t9, 4($a1)
/* 0D3A0C 80318A0C AF380000 */  sw    $t8, ($t9)
/* 0D3A10 80318A10 ACA00000 */  sw    $zero, ($a1)
/* 0D3A14 80318A14 8E0200A4 */  lw    $v0, 0xa4($s0)
.L80318A18:
/* 0D3A18 80318A18 1440006B */  bnez  $v0, .L80318BC8
/* 0D3A1C 80318A1C 260500A4 */   addiu $a1, $s0, 0xa4
/* 0D3A20 80318A20 ACB10000 */  sw    $s1, ($a1)
/* 0D3A24 80318A24 8E280004 */  lw    $t0, 4($s1)
/* 0D3A28 80318A28 3C018022 */  lui   $at, %hi(D_80225EAC) # $at, 0x8022
/* 0D3A2C 80318A2C ACA80004 */  sw    $t0, 4($a1)
/* 0D3A30 80318A30 8E290004 */  lw    $t1, 4($s1)
/* 0D3A34 80318A34 AD250000 */  sw    $a1, ($t1)
/* 0D3A38 80318A38 AC255EAC */  sw    $a1, %lo(D_80225EAC)($at)
/* 0D3A3C 80318A3C 8E2A0008 */  lw    $t2, 8($s1)
/* 0D3A40 80318A40 8E2C000C */  lw    $t4, 0xc($s1)
/* 0D3A44 80318A44 254B0001 */  addiu $t3, $t2, 1
/* 0D3A48 80318A48 AE2B0008 */  sw    $t3, 8($s1)
/* 0D3A4C 80318A4C 1000005E */  b     .L80318BC8
/* 0D3A50 80318A50 ACAC000C */   sw    $t4, 0xc($a1)
.L80318A54:
/* 0D3A54 80318A54 0C0C691E */  jal   func_8031A478
/* 0D3A58 80318A58 02002025 */   move  $a0, $s0
/* 0D3A5C 80318A5C 8E0D00A4 */  lw    $t5, 0xa4($s0)
/* 0D3A60 80318A60 260500A4 */  addiu $a1, $s0, 0xa4
/* 0D3A64 80318A64 55A00004 */  bnezl $t5, .L80318A78
/* 0D3A68 80318A68 8CAE0004 */   lw    $t6, 4($a1)
/* 0D3A6C 80318A6C 10000008 */  b     .L80318A90
/* 0D3A70 80318A70 260500A4 */   addiu $a1, $s0, 0xa4
/* 0D3A74 80318A74 8CAE0004 */  lw    $t6, 4($a1)
.L80318A78:
/* 0D3A78 80318A78 8CAF0000 */  lw    $t7, ($a1)
/* 0D3A7C 80318A7C ADEE0004 */  sw    $t6, 4($t7)
/* 0D3A80 80318A80 8CB80000 */  lw    $t8, ($a1)
/* 0D3A84 80318A84 8CB90004 */  lw    $t9, 4($a1)
/* 0D3A88 80318A88 AF380000 */  sw    $t8, ($t9)
/* 0D3A8C 80318A8C ACA00000 */  sw    $zero, ($a1)
.L80318A90:
/* 0D3A90 80318A90 8E0400B0 */  lw    $a0, 0xb0($s0)
/* 0D3A94 80318A94 0C0C6BBD */  jal   func_8031AEF4
/* 0D3A98 80318A98 24840030 */   addiu $a0, $a0, 0x30
/* 0D3A9C 80318A9C 1000004A */  b     .L80318BC8
/* 0D3AA0 80318AA0 AE140030 */   sw    $s4, 0x30($s0)
.L80318AA4:
/* 0D3AA4 80318AA4 0C0C623A */  jal   func_803188E8
/* 0D3AA8 80318AA8 02002025 */   move  $a0, $s0
/* 0D3AAC 80318AAC 8E0800A4 */  lw    $t0, 0xa4($s0)
/* 0D3AB0 80318AB0 260500A4 */  addiu $a1, $s0, 0xa4
/* 0D3AB4 80318AB4 55000004 */  bnezl $t0, .L80318AC8
/* 0D3AB8 80318AB8 8CA90004 */   lw    $t1, 4($a1)
/* 0D3ABC 80318ABC 10000008 */  b     .L80318AE0
/* 0D3AC0 80318AC0 260500A4 */   addiu $a1, $s0, 0xa4
/* 0D3AC4 80318AC4 8CA90004 */  lw    $t1, 4($a1)
.L80318AC8:
/* 0D3AC8 80318AC8 8CAA0000 */  lw    $t2, ($a1)
/* 0D3ACC 80318ACC AD490004 */  sw    $t1, 4($t2)
/* 0D3AD0 80318AD0 8CAB0000 */  lw    $t3, ($a1)
/* 0D3AD4 80318AD4 8CAC0004 */  lw    $t4, 4($a1)
/* 0D3AD8 80318AD8 AD8B0000 */  sw    $t3, ($t4)
/* 0D3ADC 80318ADC ACA00000 */  sw    $zero, ($a1)
.L80318AE0:
/* 0D3AE0 80318AE0 0C0C6BBD */  jal   func_8031AEF4
/* 0D3AE4 80318AE4 8E0400B0 */   lw    $a0, 0xb0($s0)
/* 0D3AE8 80318AE8 AE140030 */  sw    $s4, 0x30($s0)
/* 0D3AEC 80318AEC 3C028022 */  lui   $v0, %hi(D_80226D70) # $v0, 0x8022
/* 0D3AF0 80318AF0 8C426D70 */  lw    $v0, %lo(D_80226D70)($v0)
/* 0D3AF4 80318AF4 00021880 */  sll   $v1, $v0, 2
/* 0D3AF8 80318AF8 00621823 */  subu  $v1, $v1, $v0
/* 0D3AFC 80318AFC 10000077 */  b     .L80318CDC
/* 0D3B00 80318B00 00031980 */   sll   $v1, $v1, 6
.L80318B04:
/* 0D3B04 80318B04 0C0C623A */  jal   func_803188E8
/* 0D3B08 80318B08 02002025 */   move  $a0, $s0
/* 0D3B0C 80318B0C 8E0D00A4 */  lw    $t5, 0xa4($s0)
/* 0D3B10 80318B10 260500A4 */  addiu $a1, $s0, 0xa4
/* 0D3B14 80318B14 55A00004 */  bnezl $t5, .L80318B28
/* 0D3B18 80318B18 8CAE0004 */   lw    $t6, 4($a1)
/* 0D3B1C 80318B1C 10000008 */  b     .L80318B40
/* 0D3B20 80318B20 260500A4 */   addiu $a1, $s0, 0xa4
/* 0D3B24 80318B24 8CAE0004 */  lw    $t6, 4($a1)
.L80318B28:
/* 0D3B28 80318B28 8CAF0000 */  lw    $t7, ($a1)
/* 0D3B2C 80318B2C ADEE0004 */  sw    $t6, 4($t7)
/* 0D3B30 80318B30 8CB80000 */  lw    $t8, ($a1)
/* 0D3B34 80318B34 8CB90004 */  lw    $t9, 4($a1)
/* 0D3B38 80318B38 AF380000 */  sw    $t8, ($t9)
/* 0D3B3C 80318B3C ACA00000 */  sw    $zero, ($a1)
.L80318B40:
/* 0D3B40 80318B40 0C0C6BBD */  jal   func_8031AEF4
/* 0D3B44 80318B44 8E0400B0 */   lw    $a0, 0xb0($s0)
/* 0D3B48 80318B48 3C028022 */  lui   $v0, %hi(D_80226D70) # $v0, 0x8022
/* 0D3B4C 80318B4C 8C426D70 */  lw    $v0, %lo(D_80226D70)($v0)
/* 0D3B50 80318B50 00021880 */  sll   $v1, $v0, 2
/* 0D3B54 80318B54 00621823 */  subu  $v1, $v1, $v0
/* 0D3B58 80318B58 10000060 */  b     .L80318CDC
/* 0D3B5C 80318B5C 00031980 */   sll   $v1, $v1, 6
/* 0D3B60 80318B60 92080055 */  lbu   $t0, 0x55($s0)
.L80318B64:
/* 0D3B64 80318B64 15000018 */  bnez  $t0, .L80318BC8
/* 0D3B68 80318B68 00000000 */   nop   
/* 0D3B6C 80318B6C 0C0C623A */  jal   func_803188E8
/* 0D3B70 80318B70 02002025 */   move  $a0, $s0
/* 0D3B74 80318B74 8E0900A4 */  lw    $t1, 0xa4($s0)
/* 0D3B78 80318B78 260500A4 */  addiu $a1, $s0, 0xa4
/* 0D3B7C 80318B7C 55200004 */  bnezl $t1, .L80318B90
/* 0D3B80 80318B80 8CAA0004 */   lw    $t2, 4($a1)
/* 0D3B84 80318B84 10000008 */  b     .L80318BA8
/* 0D3B88 80318B88 260500A4 */   addiu $a1, $s0, 0xa4
/* 0D3B8C 80318B8C 8CAA0004 */  lw    $t2, 4($a1)
.L80318B90:
/* 0D3B90 80318B90 8CAB0000 */  lw    $t3, ($a1)
/* 0D3B94 80318B94 AD6A0004 */  sw    $t2, 4($t3)
/* 0D3B98 80318B98 8CAC0000 */  lw    $t4, ($a1)
/* 0D3B9C 80318B9C 8CAD0004 */  lw    $t5, 4($a1)
/* 0D3BA0 80318BA0 ADAC0000 */  sw    $t4, ($t5)
/* 0D3BA4 80318BA4 ACA00000 */  sw    $zero, ($a1)
.L80318BA8:
/* 0D3BA8 80318BA8 0C0C6BBD */  jal   func_8031AEF4
/* 0D3BAC 80318BAC 8E0400B0 */   lw    $a0, 0xb0($s0)
/* 0D3BB0 80318BB0 3C028022 */  lui   $v0, %hi(D_80226D70) # $v0, 0x8022
/* 0D3BB4 80318BB4 8C426D70 */  lw    $v0, %lo(D_80226D70)($v0)
/* 0D3BB8 80318BB8 00021880 */  sll   $v1, $v0, 2
/* 0D3BBC 80318BBC 00621823 */  subu  $v1, $v1, $v0
/* 0D3BC0 80318BC0 10000046 */  b     .L80318CDC
/* 0D3BC4 80318BC4 00031980 */   sll   $v1, $v1, 6
.L80318BC8:
/* 0D3BC8 80318BC8 0C0C6961 */  jal   func_8031A584
/* 0D3BCC 80318BCC 26040054 */   addiu $a0, $s0, 0x54
/* 0D3BD0 80318BD0 0C0C6906 */  jal   func_8031A418
/* 0D3BD4 80318BD4 02002025 */   move  $a0, $s0
/* 0D3BD8 80318BD8 920E0004 */  lbu   $t6, 4($s0)
/* 0D3BDC 80318BDC 26020044 */  addiu $v0, $s0, 0x44
/* 0D3BE0 80318BE0 566E0007 */  bnel  $s3, $t6, .L80318C00
/* 0D3BE4 80318BE4 8E02002C */   lw    $v0, 0x2c($s0)
/* 0D3BE8 80318BE8 C4400004 */  lwc1  $f0, 4($v0)
/* 0D3BEC 80318BEC C4540008 */  lwc1  $f20, 8($v0)
/* 0D3BF0 80318BF0 C44C000C */  lwc1  $f12, 0xc($v0)
/* 0D3BF4 80318BF4 10000007 */  b     .L80318C14
/* 0D3BF8 80318BF8 90470000 */   lbu   $a3, ($v0)
/* 0D3BFC 80318BFC 8E02002C */  lw    $v0, 0x2c($s0)
.L80318C00:
/* 0D3C00 80318C00 8C4F0050 */  lw    $t7, 0x50($v0)
/* 0D3C04 80318C04 C4400034 */  lwc1  $f0, 0x34($v0)
/* 0D3C08 80318C08 C454002C */  lwc1  $f20, 0x2c($v0)
/* 0D3C0C 80318C0C C44C0030 */  lwc1  $f12, 0x30($v0)
/* 0D3C10 80318C10 91E70003 */  lbu   $a3, 3($t7)
.L80318C14:
/* 0D3C14 80318C14 C606001C */  lwc1  $f6, 0x1c($s0)
/* 0D3C18 80318C18 C6080018 */  lwc1  $f8, 0x18($s0)
/* 0D3C1C 80318C1C 86180008 */  lh    $t8, 8($s0)
/* 0D3C20 80318C20 3C028022 */  lui   $v0, %hi(D_80226D64) 
/* 0D3C24 80318C24 46083282 */  mul.s $f10, $f6, $f8
/* 0D3C28 80318C28 8C426D64 */  lw    $v0, %lo(D_80226D64)($v0)
/* 0D3C2C 80318C2C 44982000 */  mtc1  $t8, $f4
/* 0D3C30 80318C30 24017D06 */  li    $at, 32006
/* 0D3C34 80318C34 468020A0 */  cvt.s.w $f2, $f4
/* 0D3C38 80318C38 460A0002 */  mul.s $f0, $f0, $f10
/* 0D3C3C 80318C3C 50410009 */  beql  $v0, $at, .L80318C64
/* 0D3C40 80318C40 4618003C */   c.lt.s $f0, $f24
/* 0D3C44 80318C44 44829000 */  mtc1  $v0, $f18
/* 0D3C48 80318C48 46000421 */  cvt.d.s $f16, $f0
/* 0D3C4C 80318C4C 46809120 */  cvt.s.w $f4, $f18
/* 0D3C50 80318C50 460021A1 */  cvt.d.s $f6, $f4
/* 0D3C54 80318C54 4626B203 */  div.d $f8, $f22, $f6
/* 0D3C58 80318C58 46288282 */  mul.d $f10, $f16, $f8
/* 0D3C5C 80318C5C 46205020 */  cvt.s.d $f0, $f10
/* 0D3C60 80318C60 4618003C */  c.lt.s $f0, $f24
.L80318C64:
/* 0D3C64 80318C64 3C018033 */  lui   $at, %hi(D_80337C30)
/* 0D3C68 80318C68 45010002 */  bc1t  .L80318C74
/* 0D3C6C 80318C6C 00000000 */   nop   
/* 0D3C70 80318C70 4600C006 */  mov.s $f0, $f24
.L80318C74:
/* 0D3C74 80318C74 C4327C30 */  lwc1  $f18, %lo(D_80337C30)($at)
/* 0D3C78 80318C78 44050000 */  mfc1  $a1, $f0
/* 0D3C7C 80318C7C 02002025 */  move  $a0, $s0
/* 0D3C80 80318C80 46121082 */  mul.s $f2, $f2, $f18
/* 0D3C84 80318C84 A3A70057 */  sb    $a3, 0x57($sp)
/* 0D3C88 80318C88 E7AC004C */  swc1  $f12, 0x4c($sp)
/* 0D3C8C 80318C8C 4602A102 */  mul.s $f4, $f20, $f2
/* 0D3C90 80318C90 00000000 */  nop   
/* 0D3C94 80318C94 46022502 */  mul.s $f20, $f4, $f2
/* 0D3C98 80318C98 0C0C5762 */  jal   func_80315D88
/* 0D3C9C 80318C9C 00000000 */   nop   
/* 0D3CA0 80318CA0 C7AC004C */  lwc1  $f12, 0x4c($sp)
/* 0D3CA4 80318CA4 4405A000 */  mfc1  $a1, $f20
/* 0D3CA8 80318CA8 93A70057 */  lbu   $a3, 0x57($sp)
/* 0D3CAC 80318CAC 44066000 */  mfc1  $a2, $f12
/* 0D3CB0 80318CB0 0C0C567B */  jal   func_803159EC
/* 0D3CB4 80318CB4 02002025 */   move  $a0, $s0
/* 0D3CB8 80318CB8 3C028022 */  lui   $v0, %hi(D_80226D70) # $v0, 0x8022
/* 0D3CBC 80318CBC 8C426D70 */  lw    $v0, %lo(D_80226D70)($v0)
/* 0D3CC0 80318CC0 00021880 */  sll   $v1, $v0, 2
/* 0D3CC4 80318CC4 00621823 */  subu  $v1, $v1, $v0
/* 0D3CC8 80318CC8 10000004 */  b     .L80318CDC
/* 0D3CCC 80318CCC 00031980 */   sll   $v1, $v1, 6
/* 0D3CD0 80318CD0 00021880 */  sll   $v1, $v0, 2
.L80318CD4:
/* 0D3CD4 80318CD4 00621823 */  subu  $v1, $v1, $v0
/* 0D3CD8 80318CD8 00031980 */  sll   $v1, $v1, 6
.L80318CDC:
/* 0D3CDC 80318CDC 265200C0 */  addiu $s2, $s2, 0xc0
/* 0D3CE0 80318CE0 0243082A */  slt   $at, $s2, $v1
/* 0D3CE4 80318CE4 1420FF1E */  bnez  $at, .L80318960
/* 0D3CE8 80318CE8 00000000 */   nop   
.L80318CEC:
/* 0D3CEC 80318CEC 8FBF0044 */  lw    $ra, 0x44($sp)
/* 0D3CF0 80318CF0 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0D3CF4 80318CF4 D7B60020 */  ldc1  $f22, 0x20($sp)
/* 0D3CF8 80318CF8 D7B80028 */  ldc1  $f24, 0x28($sp)
/* 0D3CFC 80318CFC 8FB00030 */  lw    $s0, 0x30($sp)
/* 0D3D00 80318D00 8FB10034 */  lw    $s1, 0x34($sp)
/* 0D3D04 80318D04 8FB20038 */  lw    $s2, 0x38($sp)
/* 0D3D08 80318D08 8FB3003C */  lw    $s3, 0x3c($sp)
/* 0D3D0C 80318D0C 8FB40040 */  lw    $s4, 0x40($sp)
/* 0D3D10 80318D10 03E00008 */  jr    $ra
/* 0D3D14 80318D14 27BD0060 */   addiu $sp, $sp, 0x60
)
#else
GLOBAL_ASM(
glabel func_80318908
/* 0D49B8 803199B8 27BDFFA8 */  addiu $sp, $sp, -0x58
/* 0D49BC 803199BC 3C028022 */  lui   $v0, %hi(D_80226D70) # $v0, 0x8022
/* 0D49C0 803199C0 8C426B70 */  lw    $v0, %lo(D_80226D70)($v0)
/* 0D49C4 803199C4 AFBF003C */  sw    $ra, 0x3c($sp)
/* 0D49C8 803199C8 AFB40038 */  sw    $s4, 0x38($sp)
/* 0D49CC 803199CC AFB30034 */  sw    $s3, 0x34($sp)
/* 0D49D0 803199D0 AFB20030 */  sw    $s2, 0x30($sp)
/* 0D49D4 803199D4 AFB1002C */  sw    $s1, 0x2c($sp)
/* 0D49D8 803199D8 AFB00028 */  sw    $s0, 0x28($sp)
/* 0D49DC 803199DC F7B60020 */  sdc1  $f22, 0x20($sp)
/* 0D49E0 803199E0 184000EB */  blez  $v0, .L80319D90
/* 0D49E4 803199E4 F7B40018 */   sdc1  $f20, 0x18($sp)
/* 0D49E8 803199E8 3C018034 */  lui   $at, %hi(D_U_80338E10) # $at, 0x8034
/* 0D49EC 803199EC 3C118022 */  lui   $s1, %hi(D_80225EA8) # $s1, 0x8022
/* 0D49F0 803199F0 26315CA8 */  addiu $s1, %lo(D_80225EA8) # addiu $s1, $s1, 0x5ca8
/* 0D49F4 803199F4 C4368E10 */  lwc1  $f22, %lo(D_U_80338E10)($at)
/* 0D49F8 803199F8 00009025 */  move  $s2, $zero
/* 0D49FC 803199FC 2414FFFF */  li    $s4, -1
/* 0D4A00 80319A00 24130001 */  li    $s3, 1
.L80319A04:
/* 0D4A04 80319A04 3C0E8022 */  lui   $t6, %hi(D_80222A10) # $t6, 0x8022
/* 0D4A08 80319A08 8DCE2610 */  lw    $t6, %lo(D_80222A10)($t6)
/* 0D4A0C 80319A0C 024E8021 */  addu  $s0, $s2, $t6
/* 0D4A10 80319A10 92030004 */  lbu   $v1, 4($s0)
/* 0D4A14 80319A14 506000D8 */  beql  $v1, $zero, .L80319D78
/* 0D4A18 80319A18 00021880 */   sll   $v1, $v0, 2
/* 0D4A1C 80319A1C 52630006 */  beql  $s3, $v1, .L80319A38
/* 0D4A20 80319A20 86080008 */   lh    $t0, 8($s0)
/* 0D4A24 80319A24 8E0F0000 */  lw    $t7, ($s0)
/* 0D4A28 80319A28 000FC8C0 */  sll   $t9, $t7, 3
/* 0D4A2C 80319A2C 07230076 */  bgezl $t9, .L80319C08
/* 0D4A30 80319A30 92080055 */   lbu   $t0, 0x55($s0)
/* 0D4A34 80319A34 86080008 */  lh    $t0, 8($s0)
.L80319A38:
/* 0D4A38 80319A38 51000006 */  beql  $t0, $zero, .L80319A54
/* 0D4A3C 80319A3C 8E0C0030 */   lw    $t4, 0x30($s0)
/* 0D4A40 80319A40 8E090000 */  lw    $t1, ($s0)
/* 0D4A44 80319A44 000958C0 */  sll   $t3, $t1, 3
/* 0D4A48 80319A48 05610088 */  bgez  $t3, .L80319C6C
/* 0D4A4C 80319A4C 00000000 */   nop   
/* 0D4A50 80319A50 8E0C0030 */  lw    $t4, 0x30($s0)
.L80319A54:
/* 0D4A54 80319A54 128C0054 */  beq   $s4, $t4, .L80319BA8
/* 0D4A58 80319A58 00000000 */   nop   
/* 0D4A5C 80319A5C 0C0C6666 */  jal   func_803188E8
/* 0D4A60 80319A60 02002025 */   move  $a0, $s0
/* 0D4A64 80319A64 8E050030 */  lw    $a1, 0x30($s0)
/* 0D4A68 80319A68 8CAD0050 */  lw    $t5, 0x50($a1)
/* 0D4A6C 80319A6C 11A00036 */  beqz  $t5, .L80319B48
/* 0D4A70 80319A70 00000000 */   nop   
/* 0D4A74 80319A74 0C0C69B3 */  jal   func_80319660
/* 0D4A78 80319A78 02002025 */   move  $a0, $s0
/* 0D4A7C 80319A7C 1453001E */  bne   $v0, $s3, .L80319AF8
/* 0D4A80 80319A80 00000000 */   nop   
/* 0D4A84 80319A84 0C0C6666 */  jal   func_803188E8
/* 0D4A88 80319A88 02002025 */   move  $a0, $s0
/* 0D4A8C 80319A8C 8E0200A4 */  lw    $v0, 0xa4($s0)
/* 0D4A90 80319A90 260500A4 */  addiu $a1, $s0, 0xa4
/* 0D4A94 80319A94 10400009 */  beqz  $v0, .L80319ABC
/* 0D4A98 80319A98 00000000 */   nop   
/* 0D4A9C 80319A9C 8CAE0004 */  lw    $t6, 4($a1)
/* 0D4AA0 80319AA0 8CAF0000 */  lw    $t7, ($a1)
/* 0D4AA4 80319AA4 ADEE0004 */  sw    $t6, 4($t7)
/* 0D4AA8 80319AA8 8CB80000 */  lw    $t8, ($a1)
/* 0D4AAC 80319AAC 8CB90004 */  lw    $t9, 4($a1)
/* 0D4AB0 80319AB0 AF380000 */  sw    $t8, ($t9)
/* 0D4AB4 80319AB4 ACA00000 */  sw    $zero, ($a1)
/* 0D4AB8 80319AB8 8E0200A4 */  lw    $v0, 0xa4($s0)
.L80319ABC:
/* 0D4ABC 80319ABC 1440006B */  bnez  $v0, .L80319C6C
/* 0D4AC0 80319AC0 260500A4 */   addiu $a1, $s0, 0xa4
/* 0D4AC4 80319AC4 ACB10000 */  sw    $s1, ($a1)
/* 0D4AC8 80319AC8 8E280004 */  lw    $t0, 4($s1)
/* 0D4ACC 80319ACC 3C018022 */  lui   $at, %hi(D_80225EAC) # $at, 0x8022
/* 0D4AD0 80319AD0 ACA80004 */  sw    $t0, 4($a1)
/* 0D4AD4 80319AD4 8E290004 */  lw    $t1, 4($s1)
/* 0D4AD8 80319AD8 AD250000 */  sw    $a1, ($t1)
/* 0D4ADC 80319ADC AC255CAC */  sw    $a1, %lo(D_80225EAC)($at)
/* 0D4AE0 80319AE0 8E2A0008 */  lw    $t2, 8($s1)
/* 0D4AE4 80319AE4 8E2C000C */  lw    $t4, 0xc($s1)
/* 0D4AE8 80319AE8 254B0001 */  addiu $t3, $t2, 1
/* 0D4AEC 80319AEC AE2B0008 */  sw    $t3, 8($s1)
/* 0D4AF0 80319AF0 1000005E */  b     .L80319C6C
/* 0D4AF4 80319AF4 ACAC000C */   sw    $t4, 0xc($a1)
.L80319AF8:
/* 0D4AF8 80319AF8 0C0C6D28 */  jal   func_8031A478
/* 0D4AFC 80319AFC 02002025 */   move  $a0, $s0
/* 0D4B00 80319B00 8E0D00A4 */  lw    $t5, 0xa4($s0)
/* 0D4B04 80319B04 260500A4 */  addiu $a1, $s0, 0xa4
/* 0D4B08 80319B08 55A00004 */  bnezl $t5, .L80319B1C
/* 0D4B0C 80319B0C 8CAE0004 */   lw    $t6, 4($a1)
/* 0D4B10 80319B10 10000008 */  b     .L80319B34
/* 0D4B14 80319B14 260500A4 */   addiu $a1, $s0, 0xa4
/* 0D4B18 80319B18 8CAE0004 */  lw    $t6, 4($a1)
.L80319B1C:
/* 0D4B1C 80319B1C 8CAF0000 */  lw    $t7, ($a1)
/* 0D4B20 80319B20 ADEE0004 */  sw    $t6, 4($t7)
/* 0D4B24 80319B24 8CB80000 */  lw    $t8, ($a1)
/* 0D4B28 80319B28 8CB90004 */  lw    $t9, 4($a1)
/* 0D4B2C 80319B2C AF380000 */  sw    $t8, ($t9)
/* 0D4B30 80319B30 ACA00000 */  sw    $zero, ($a1)
.L80319B34:
/* 0D4B34 80319B34 8E0400B0 */  lw    $a0, 0xb0($s0)
/* 0D4B38 80319B38 0C0C6FC5 */  jal   func_8031AEF4
/* 0D4B3C 80319B3C 24840030 */   addiu $a0, $a0, 0x30
/* 0D4B40 80319B40 1000004A */  b     .L80319C6C
/* 0D4B44 80319B44 AE140030 */   sw    $s4, 0x30($s0)
.L80319B48:
/* 0D4B48 80319B48 0C0C6666 */  jal   func_803188E8
/* 0D4B4C 80319B4C 02002025 */   move  $a0, $s0
/* 0D4B50 80319B50 8E0800A4 */  lw    $t0, 0xa4($s0)
/* 0D4B54 80319B54 260500A4 */  addiu $a1, $s0, 0xa4
/* 0D4B58 80319B58 55000004 */  bnezl $t0, .L80319B6C
/* 0D4B5C 80319B5C 8CA90004 */   lw    $t1, 4($a1)
/* 0D4B60 80319B60 10000008 */  b     .L80319B84
/* 0D4B64 80319B64 260500A4 */   addiu $a1, $s0, 0xa4
/* 0D4B68 80319B68 8CA90004 */  lw    $t1, 4($a1)
.L80319B6C:
/* 0D4B6C 80319B6C 8CAA0000 */  lw    $t2, ($a1)
/* 0D4B70 80319B70 AD490004 */  sw    $t1, 4($t2)
/* 0D4B74 80319B74 8CAB0000 */  lw    $t3, ($a1)
/* 0D4B78 80319B78 8CAC0004 */  lw    $t4, 4($a1)
/* 0D4B7C 80319B7C AD8B0000 */  sw    $t3, ($t4)
/* 0D4B80 80319B80 ACA00000 */  sw    $zero, ($a1)
.L80319B84:
/* 0D4B84 80319B84 0C0C6FC5 */  jal   func_8031AEF4
/* 0D4B88 80319B88 8E0400B0 */   lw    $a0, 0xb0($s0)
/* 0D4B8C 80319B8C AE140030 */  sw    $s4, 0x30($s0)
/* 0D4B90 80319B90 3C028022 */  lui   $v0, %hi(D_80226D70) # $v0, 0x8022
/* 0D4B94 80319B94 8C426B70 */  lw    $v0, %lo(D_80226D70)($v0)
/* 0D4B98 80319B98 00021880 */  sll   $v1, $v0, 2
/* 0D4B9C 80319B9C 00621823 */  subu  $v1, $v1, $v0
/* 0D4BA0 80319BA0 10000077 */  b     .L80319D80
/* 0D4BA4 80319BA4 00031980 */   sll   $v1, $v1, 6
.L80319BA8:
/* 0D4BA8 80319BA8 0C0C6666 */  jal   func_803188E8
/* 0D4BAC 80319BAC 02002025 */   move  $a0, $s0
/* 0D4BB0 80319BB0 8E0D00A4 */  lw    $t5, 0xa4($s0)
/* 0D4BB4 80319BB4 260500A4 */  addiu $a1, $s0, 0xa4
/* 0D4BB8 80319BB8 55A00004 */  bnezl $t5, .L80319BCC
/* 0D4BBC 80319BBC 8CAE0004 */   lw    $t6, 4($a1)
/* 0D4BC0 80319BC0 10000008 */  b     .L80319BE4
/* 0D4BC4 80319BC4 260500A4 */   addiu $a1, $s0, 0xa4
/* 0D4BC8 80319BC8 8CAE0004 */  lw    $t6, 4($a1)
.L80319BCC:
/* 0D4BCC 80319BCC 8CAF0000 */  lw    $t7, ($a1)
/* 0D4BD0 80319BD0 ADEE0004 */  sw    $t6, 4($t7)
/* 0D4BD4 80319BD4 8CB80000 */  lw    $t8, ($a1)
/* 0D4BD8 80319BD8 8CB90004 */  lw    $t9, 4($a1)
/* 0D4BDC 80319BDC AF380000 */  sw    $t8, ($t9)
/* 0D4BE0 80319BE0 ACA00000 */  sw    $zero, ($a1)
.L80319BE4:
/* 0D4BE4 80319BE4 0C0C6FC5 */  jal   func_8031AEF4
/* 0D4BE8 80319BE8 8E0400B0 */   lw    $a0, 0xb0($s0)
/* 0D4BEC 80319BEC 3C028022 */  lui   $v0, %hi(D_80226D70) # $v0, 0x8022
/* 0D4BF0 80319BF0 8C426B70 */  lw    $v0, %lo(D_80226D70)($v0)
/* 0D4BF4 80319BF4 00021880 */  sll   $v1, $v0, 2
/* 0D4BF8 80319BF8 00621823 */  subu  $v1, $v1, $v0
/* 0D4BFC 80319BFC 10000060 */  b     .L80319D80
/* 0D4C00 80319C00 00031980 */   sll   $v1, $v1, 6
/* 0D4C04 80319C04 92080055 */  lbu   $t0, 0x55($s0)
.L80319C08:
/* 0D4C08 80319C08 15000018 */  bnez  $t0, .L80319C6C
/* 0D4C0C 80319C0C 00000000 */   nop   
/* 0D4C10 80319C10 0C0C6666 */  jal   func_803188E8
/* 0D4C14 80319C14 02002025 */   move  $a0, $s0
/* 0D4C18 80319C18 8E0900A4 */  lw    $t1, 0xa4($s0)
/* 0D4C1C 80319C1C 260500A4 */  addiu $a1, $s0, 0xa4
/* 0D4C20 80319C20 55200004 */  bnezl $t1, .L80319C34
/* 0D4C24 80319C24 8CAA0004 */   lw    $t2, 4($a1)
/* 0D4C28 80319C28 10000008 */  b     .L80319C4C
/* 0D4C2C 80319C2C 260500A4 */   addiu $a1, $s0, 0xa4
/* 0D4C30 80319C30 8CAA0004 */  lw    $t2, 4($a1)
.L80319C34:
/* 0D4C34 80319C34 8CAB0000 */  lw    $t3, ($a1)
/* 0D4C38 80319C38 AD6A0004 */  sw    $t2, 4($t3)
/* 0D4C3C 80319C3C 8CAC0000 */  lw    $t4, ($a1)
/* 0D4C40 80319C40 8CAD0004 */  lw    $t5, 4($a1)
/* 0D4C44 80319C44 ADAC0000 */  sw    $t4, ($t5)
/* 0D4C48 80319C48 ACA00000 */  sw    $zero, ($a1)
.L80319C4C:
/* 0D4C4C 80319C4C 0C0C6FC5 */  jal   func_8031AEF4
/* 0D4C50 80319C50 8E0400B0 */   lw    $a0, 0xb0($s0)
/* 0D4C54 80319C54 3C028022 */  lui   $v0, %hi(D_80226D70) # $v0, 0x8022
/* 0D4C58 80319C58 8C426B70 */  lw    $v0, %lo(D_80226D70)($v0)
/* 0D4C5C 80319C5C 00021880 */  sll   $v1, $v0, 2
/* 0D4C60 80319C60 00621823 */  subu  $v1, $v1, $v0
/* 0D4C64 80319C64 10000046 */  b     .L80319D80
/* 0D4C68 80319C68 00031980 */   sll   $v1, $v1, 6
.L80319C6C:
/* 0D4C6C 80319C6C 0C0C6D6B */  jal   func_8031A584
/* 0D4C70 80319C70 26040054 */   addiu $a0, $s0, 0x54
/* 0D4C74 80319C74 0C0C6D10 */  jal   func_8031A418
/* 0D4C78 80319C78 02002025 */   move  $a0, $s0
/* 0D4C7C 80319C7C 920E0004 */  lbu   $t6, 4($s0)
/* 0D4C80 80319C80 26020044 */  addiu $v0, $s0, 0x44
/* 0D4C84 80319C84 566E0007 */  bnel  $s3, $t6, .L80319CA4
/* 0D4C88 80319C88 8E02002C */   lw    $v0, 0x2c($s0)
/* 0D4C8C 80319C8C C4400004 */  lwc1  $f0, 4($v0)
/* 0D4C90 80319C90 C4540008 */  lwc1  $f20, 8($v0)
/* 0D4C94 80319C94 C44C000C */  lwc1  $f12, 0xc($v0)
/* 0D4C98 80319C98 10000007 */  b     .L80319CB8
/* 0D4C9C 80319C9C 90470000 */   lbu   $a3, ($v0)
/* 0D4CA0 80319CA0 8E02002C */  lw    $v0, 0x2c($s0)
.L80319CA4:
/* 0D4CA4 80319CA4 8C4F0050 */  lw    $t7, 0x50($v0)
/* 0D4CA8 80319CA8 C4400034 */  lwc1  $f0, 0x34($v0)
/* 0D4CAC 80319CAC C454002C */  lwc1  $f20, 0x2c($v0)
/* 0D4CB0 80319CB0 C44C0030 */  lwc1  $f12, 0x30($v0)
/* 0D4CB4 80319CB4 91E70003 */  lbu   $a3, 3($t7)
.L80319CB8:
/* 0D4CB8 80319CB8 C606001C */  lwc1  $f6, 0x1c($s0)
/* 0D4CBC 80319CBC C6080018 */  lwc1  $f8, 0x18($s0)
/* 0D4CC0 80319CC0 86180008 */  lh    $t8, 8($s0)
/* 0D4CC4 80319CC4 3C028022 */  lui   $v0, %hi(D_80226D64) # $v0, 0x8022
/* 0D4CC8 80319CC8 46083282 */  mul.s $f10, $f6, $f8
/* 0D4CCC 80319CCC 8C426B64 */  lw    $v0, %lo(D_80226D64)($v0)
/* 0D4CD0 80319CD0 44982000 */  mtc1  $t8, $f4
/* 0D4CD4 80319CD4 24017D06 */  li    $at, 32006
/* 0D4CD8 80319CD8 468020A0 */  cvt.s.w $f2, $f4
/* 0D4CDC 80319CDC 460A0002 */  mul.s $f0, $f0, $f10
/* 0D4CE0 80319CE0 50410009 */  beql  $v0, $at, .L80319D08
/* 0D4CE4 80319CE4 4616003C */   c.lt.s $f0, $f22
/* 0D4CE8 80319CE8 44829000 */  mtc1  $v0, $f18
/* 0D4CEC 80319CEC 3C0146FA */  li    $at, 0x46FA0000 # 32000.000000
/* 0D4CF0 80319CF0 44818000 */  mtc1  $at, $f16
/* 0D4CF4 80319CF4 46809120 */  cvt.s.w $f4, $f18
/* 0D4CF8 80319CF8 46048183 */  div.s $f6, $f16, $f4
/* 0D4CFC 80319CFC 46060002 */  mul.s $f0, $f0, $f6
/* 0D4D00 80319D00 00000000 */  nop   
/* 0D4D04 80319D04 4616003C */  c.lt.s $f0, $f22
.L80319D08:
/* 0D4D08 80319D08 3C018034 */  lui   $at, %hi(D_U_80338E14) # $at, 0x8034
/* 0D4D0C 80319D0C 45010002 */  bc1t  .L80319D18
/* 0D4D10 80319D10 00000000 */   nop   
/* 0D4D14 80319D14 4600B006 */  mov.s $f0, $f22
.L80319D18:
/* 0D4D18 80319D18 C4288E14 */  lwc1  $f8, %lo(D_U_80338E14)($at)
/* 0D4D1C 80319D1C 44050000 */  mfc1  $a1, $f0
/* 0D4D20 80319D20 02002025 */  move  $a0, $s0
/* 0D4D24 80319D24 46081082 */  mul.s $f2, $f2, $f8
/* 0D4D28 80319D28 A3A7004F */  sb    $a3, 0x4f($sp)
/* 0D4D2C 80319D2C E7AC0044 */  swc1  $f12, 0x44($sp)
/* 0D4D30 80319D30 4602A282 */  mul.s $f10, $f20, $f2
/* 0D4D34 80319D34 00000000 */  nop   
/* 0D4D38 80319D38 46025502 */  mul.s $f20, $f10, $f2
/* 0D4D3C 80319D3C 0C0C5B6A */  jal   func_80315D88
/* 0D4D40 80319D40 00000000 */   nop   
/* 0D4D44 80319D44 C7AC0044 */  lwc1  $f12, 0x44($sp)
/* 0D4D48 80319D48 4405A000 */  mfc1  $a1, $f20
/* 0D4D4C 80319D4C 93A7004F */  lbu   $a3, 0x4f($sp)
/* 0D4D50 80319D50 44066000 */  mfc1  $a2, $f12
/* 0D4D54 80319D54 0C0C5ABD */  jal   func_803159EC
/* 0D4D58 80319D58 02002025 */   move  $a0, $s0
/* 0D4D5C 80319D5C 3C028022 */  lui   $v0, %hi(D_80226D70) # $v0, 0x8022
/* 0D4D60 80319D60 8C426B70 */  lw    $v0, %lo(D_80226D70)($v0)
/* 0D4D64 80319D64 00021880 */  sll   $v1, $v0, 2
/* 0D4D68 80319D68 00621823 */  subu  $v1, $v1, $v0
/* 0D4D6C 80319D6C 10000004 */  b     .L80319D80
/* 0D4D70 80319D70 00031980 */   sll   $v1, $v1, 6
/* 0D4D74 80319D74 00021880 */  sll   $v1, $v0, 2
.L80319D78:
/* 0D4D78 80319D78 00621823 */  subu  $v1, $v1, $v0
/* 0D4D7C 80319D7C 00031980 */  sll   $v1, $v1, 6
.L80319D80:
/* 0D4D80 80319D80 265200C0 */  addiu $s2, $s2, 0xc0
/* 0D4D84 80319D84 0243082A */  slt   $at, $s2, $v1
/* 0D4D88 80319D88 1420FF1E */  bnez  $at, .L80319A04
/* 0D4D8C 80319D8C 00000000 */   nop   
.L80319D90:
/* 0D4D90 80319D90 8FBF003C */  lw    $ra, 0x3c($sp)
/* 0D4D94 80319D94 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0D4D98 80319D98 D7B60020 */  ldc1  $f22, 0x20($sp)
/* 0D4D9C 80319D9C 8FB00028 */  lw    $s0, 0x28($sp)
/* 0D4DA0 80319DA0 8FB1002C */  lw    $s1, 0x2c($sp)
/* 0D4DA4 80319DA4 8FB20030 */  lw    $s2, 0x30($sp)
/* 0D4DA8 80319DA8 8FB30034 */  lw    $s3, 0x34($sp)
/* 0D4DAC 80319DAC 8FB40038 */  lw    $s4, 0x38($sp)
/* 0D4DB0 80319DB0 03E00008 */  jr    $ra
/* 0D4DB4 80319DB4 27BD0058 */   addiu $sp, $sp, 0x58
)
#endif

void func_80318D18(struct SubStruct_func_80318870 *arg0, s32 arg1)
{
    struct Struct_func_80318870 *unk44;
    struct SubStruct_func_80318870_2 *sub;

    if (arg0 == MINUS_ONE || arg0->unk44 == NULL)
    {
        return;
    }

    unk44 = arg0->unk44;
    sub = &unk44->unk44;

    if (arg0->unk50 != 0 && arg0->unk50->unk1 == 0)
    {
        arg0->unk44 = NULL;
    }

    if (arg0 == unk44->unk30)
    {
        unk44->unk30 = MINUS_ONE;
    }

    if (arg0 != unk44->unk2C)
    {
        return;
    }

    arg0->unk1 = 0;
    if (unk44->unk55 != 6)
    {
        sub->unk4 = arg0->unk34;
        sub->unk8 = arg0->unk2C;
        sub->unkC = arg0->unk30;
        if (arg0->unk50 != NULL)
        {
            sub->unk0 = arg0->unk50->unk3;
        }
        unk44->unk4 = 1;
        unk44->unk28 = unk44->unk2C;
        unk44->unk2C = MINUS_ONE;
        if (arg1 == 7)
        {
            unk44->unk62 = 0x8000 / D_80226D7E;
            unk44->unk54 |= 0x10;
        }
        else
        {
            unk44->unk54 |= 0x20;
            if (arg0->unk14 == 0)
            {
                unk44->unk62 = arg0->unk50->unk78 * 0x18;
            }
            else
            {
                unk44->unk62 = arg0->unk14 * 0x18;
            }
            unk44->unk60 = (unk44->unk5A * arg0->unk50->unk7A) / 0x10000;
        }
    }

    if (arg1 == 6)
    {
        func_803195A4(&unk44->unkA4);
        func_80319564(&unk44->unkA4.unkC[1], &unk44->unkA4);
    }
}

void func_80318EC4(struct SubStruct_func_80318870 *arg0)
{
    func_80318D18(arg0, 6);
}

void func_80318EE4(struct SubStruct_func_80318870 *arg0)
{
    func_80318D18(arg0, 7);
}

void func_80318F04(struct Struct_func_80318F04 *arg0, struct Struct2_func_80318F04 *arg1)
{
    s32 i;
    s32 j;
    s32 pos;
    s32 stepSize;
    s32 offset;
    u8 lim;
    u8 origUnk5 = arg0->unk5;

#ifdef VERSION_JP
    if (arg1->unk20 < 1.0)
    {
        arg0->unk5 = 64;
        arg1->unk20 *= D_80337C38;
        stepSize = 1;
    }
    else if (arg1->unk20 < 2.0)
    {
        arg0->unk5 = 32;
        arg1->unk20 *= D_80337C40;
        stepSize = 2;
    }
    else if (arg1->unk20 < 4.0)
    {
        arg0->unk5 = 16;
        arg1->unk20 *= D_80337C48;
        stepSize = 4;
    }
    else
    {
        arg0->unk5 = 8;
        arg1->unk20 *= D_80337C50;
        stepSize = 8;
    }
#else
    if (arg1->unk20 < 1.0f)
    {
        arg0->unk5 = 64;
        arg1->unk20 *= D_U_80338E18;
        stepSize = 1;
    }
    else if (arg1->unk20 < 2.0f)
    {
        arg0->unk5 = 32;
        arg1->unk20 *= D_U_80338E1C;
        stepSize = 2;
    }
    else if (arg1->unk20 < 4.0f)
    {
        arg0->unk5 = 16;
        arg1->unk20 *= D_U_80338E20;
        stepSize = 4;
    }
    else
    {
        arg0->unk5 = 8;
        arg1->unk20 *= D_U_80338E24;
        stepSize = 8;
    }
#endif

    if (arg0->unk5 == origUnk5 && arg1->unk50->unk18 == arg0->unk6)
    {
        return;
    }

    arg0->unk6 = (u8) arg1->unk50->unk18;
    for (i = -1, pos = 0; pos < 0x40; pos += stepSize)
    {
        i++;
        arg0->unk34->unk110[i] = D_80332CC0[arg1->unk50->unk18 - 0x80][pos];
    }

    for (offset = arg0->unk5; offset < 0x40; offset += arg0->unk5)
    {
        lim = (u8) arg0->unk5;
        if (offset < 0 || offset > 0)
        {
            for (j = 0; j < lim; j++)
            {
                arg0->unk34->unk110[offset + j] = arg0->unk34->unk110[j];
            }
        }
        else
        {
            for (j = 0; j < lim; j++)
            {
                arg0->unk34->unk110[offset + j] = arg0->unk34->unk110[j];
            }
        }
    }

    osWritebackDCache(arg0->unk34->unk110, 0x80);
}

void func_80319164(struct Struct_func_80318F04 *arg0, struct Struct2_func_80318F04 *arg1)
{
    s32 unk5 = arg0->unk5;
    func_80318F04(arg0, arg1);
    if (unk5 != 0)
    {
        arg0->unk14 *= arg0->unk5 / unk5;
    }
    else
    {
        arg0->unk14 = 0;
    }
}

void func_803191E8(struct PlaybackListItem *head)
{
    head->prev = head;
    head->next = head;
    head->u.count = 0;
}

void func_803191F8(struct PlaybackListItem *headList)
{
    func_803191E8(&headList[0]);
    func_803191E8(&headList[1]);
    func_803191E8(&headList[2]);
    func_803191E8(&headList[3]);
    headList[0].unkC = headList;
    headList[1].unkC = headList;
    headList[2].unkC = headList;
    headList[3].unkC = headList;
}

void func_80319248(void)
{
    s32 i;

    func_803191F8(D_80225EA8);
    for (i = 0; i < D_80226D70; i++)
    {
        D_80222A10[i].unkA4.u.value = &D_80222A10[i];
        D_80222A10[i].unkA4.prev = NULL;
        func_8031AEF4(&D_80225EA8[0], &D_80222A10[i].unkA4);
    }
}

void func_803192FC(struct PlaybackListItem *headList)
{
    struct PlaybackListItem *s0;
    struct PlaybackListItem *s2;
    s32 i;
    struct PlaybackListItem *s3;
    s32 j;

    for (i = 0; i < 4; i++)
    {
        switch (i)
        {
        case 0:
            s2 = &headList[0];
            s3 = &D_80225EA8[0];
            break;

        case 1:
            s2 = &headList[1];
            s3 = &D_80225EA8[1];
            break;

        case 2:
            s2 = &headList[2];
            s3 = &D_80225EA8[2];
            break;

        case 3:
            s2 = &headList[3];
            s3 = &D_80225EA8[3];
            break;
        }

        j = 0;
        do
        {
            s0 = s2->next;
            if (s0 == s2)
                break;
            func_803195A4(s0);
            func_8031AEF4(s3, s0);
            j++;
        } while (j <= D_80226D70);
    }
}

void func_80319428(struct PlaybackListItem *headList, s32 count)
{
    s32 i;
    s32 j;
    struct Struct_func_80318870 *ret;
    struct PlaybackListItem *s1;
    struct PlaybackListItem *s2;

    func_803192FC(headList);

    for (i = 0, j = 0; j < count; i++)
    {
        if (i == 4)
            return;

        switch (i)
        {
        case 0:
            s1 = &D_80225EA8[0];
            s2 = &headList[0];
            break;

        case 1:
            s1 = &D_80225EA8[1];
            s2 = &headList[1];
            break;

        case 2:
            s1 = &D_80225EA8[2];
            s2 = &headList[2];
            break;

        case 3:
            s1 = &D_80225EA8[3];
            s2 = &headList[3];
            break;
        }

        while (j < count)
        {
            ret = func_8031AF34(s1);
            if (ret == 0)
                break;
            func_8031AEF4(s2, &ret->unkA4);
            j++;
        }
    }
}

void func_80319564(struct PlaybackListItem *head, struct PlaybackListItem *item)
{
    // add 'item' to the front of the list given by 'head', if it's not in any list
    if (item->prev == 0)
    {
        item->prev = head;
        item->next = head->next;
        head->next->prev = item;
        head->next = item;
        head->u.count++;
        item->unkC = head->unkC;
    }
}

void func_803195A4(struct PlaybackListItem *item)
{
    // remove 'item' from the list it's in, if any
    if (item->prev != 0)
    {
        item->prev->next = item->next;
        item->next->prev = item->prev;
        item->prev = NULL;
    }
}

struct Struct_func_80318870 *func_803195D0(struct PlaybackListItem *head, s32 arg1)
{
    struct PlaybackListItem *cur = head->next;
    struct PlaybackListItem *best;

    if (cur == head)
    {
        return NULL;
    }

    best = cur;
    for (; cur != head; cur = cur->next)
    {
        if (best->u.value->unk4 >= cur->u.value->unk4)
        {
            best = cur;
        }
    }

    if (arg1 < best->u.value->unk4)
    {
        return NULL;
    }

    func_803195A4(best);
    return best->u.value;
}

GLOBAL_ASM(
glabel func_80319660
/* 0D4660 80319660 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0D4664 80319664 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0D4668 80319668 240EFFFF */  li    $t6, -1
/* 0D466C 8031966C AC8E0028 */  sw    $t6, 0x28($a0)
/* 0D4670 80319670 AC85002C */  sw    $a1, 0x2c($a0)
/* 0D4674 80319674 8CAF0050 */  lw    $t7, 0x50($a1)
/* 0D4678 80319678 3C088022 */  lui   $t0, %hi(D_802218D0)
/* 0D467C 8031967C 91F80004 */  lbu   $t8, 4($t7)
/* 0D4680 80319680 A0980004 */  sb    $t8, 4($a0)
/* 0D4684 80319684 8CB90050 */  lw    $t9, 0x50($a1)
/* 0D4688 80319688 93220005 */  lbu   $v0, 5($t9)
/* 0D468C 8031968C 01024021 */  addu  $t0, $t0, $v0
/* 0D4690 80319690 910818D0 */  lbu   $t0, %lo(D_802218D0)($t0)
/* 0D4694 80319694 29090002 */  slti  $t1, $t0, 2
/* 0D4698 80319698 51200004 */  beql  $t1, $zero, .L803196AC
/* 0D469C 8031969C A0820007 */   sb    $v0, 7($a0)
/* 0D46A0 803196A0 1000001D */  b     .L80319718
/* 0D46A4 803196A4 24020001 */   li    $v0, 1
/* 0D46A8 803196A8 A0820007 */  sb    $v0, 7($a0)
.L803196AC:
/* 0D46AC 803196AC 8CAA0050 */  lw    $t2, 0x50($a1)
/* 0D46B0 803196B0 908F0000 */  lbu   $t7, ($a0)
/* 0D46B4 803196B4 24090003 */  li    $t1, 3
/* 0D46B8 803196B8 8D4B0000 */  lw    $t3, ($t2)
/* 0D46BC 803196BC 31F8FFFE */  andi  $t8, $t7, 0xfffe
/* 0D46C0 803196C0 000B6140 */  sll   $t4, $t3, 5
/* 0D46C4 803196C4 000C6FC2 */  srl   $t5, $t4, 0x1f
/* 0D46C8 803196C8 31AE0001 */  andi  $t6, $t5, 1
/* 0D46CC 803196CC 01D8C825 */  or    $t9, $t6, $t8
/* 0D46D0 803196D0 A0990000 */  sb    $t9, ($a0)
/* 0D46D4 803196D4 8CA8004C */  lw    $t0, 0x4c($a1)
/* 0D46D8 803196D8 AC880024 */  sw    $t0, 0x24($a0)
/* 0D46DC 803196DC 8CAA0050 */  lw    $t2, 0x50($a1)
/* 0D46E0 803196E0 A0A90001 */  sb    $t1, 1($a1)
/* 0D46E4 803196E4 ACA40044 */  sw    $a0, 0x44($a1)
/* 0D46E8 803196E8 AD440034 */  sw    $a0, 0x34($t2)
/* 0D46EC 803196EC 8CAB0050 */  lw    $t3, 0x50($a1)
/* 0D46F0 803196F0 AD650038 */  sw    $a1, 0x38($t3)
/* 0D46F4 803196F4 8C8C0024 */  lw    $t4, 0x24($a0)
/* 0D46F8 803196F8 15800004 */  bnez  $t4, .L8031970C
/* 0D46FC 803196FC 00000000 */   nop   
/* 0D4700 80319700 0C0C63C1 */  jal   func_80318F04
/* 0D4704 80319704 AFA40018 */   sw    $a0, 0x18($sp)
/* 0D4708 80319708 8FA40018 */  lw    $a0, 0x18($sp)
.L8031970C:
/* 0D470C 8031970C 0C0C621C */  jal   func_80318870
/* 0D4710 80319710 00000000 */   nop   
/* 0D4714 80319714 00001025 */  move  $v0, $zero
.L80319718:
/* 0D4718 80319718 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0D471C 8031971C 27BD0018 */  addiu $sp, $sp, 0x18
/* 0D4720 80319720 03E00008 */  jr    $ra
/* 0D4724 80319724 00000000 */   nop   
)

void func_80319728(struct Struct_func_80318870 *arg0, struct SubStruct_func_80318870 *arg1)
{
    func_80318EE4(arg0->unk2C);
    arg0->unk30 = arg1;
}

void func_8031975C(struct Struct_func_80318870 *arg0, struct SubStruct_func_80318870 *arg1)
{
    arg0->unk30 = arg1;
    arg0->unk4 = 1;
    arg0->unk62 = 0x8000 / D_80226D7E;
    arg0->unk54 |= 0x10;
}

struct Struct_func_80318870 *func_803197B4(struct PlaybackListItem *headList, struct SubStruct_func_80318870 *arg1)
{
    struct Struct_func_80318870 *a2 = func_8031AF34(&headList[0]);
    if (a2 != NULL)
    {
        if (func_80319660(a2, arg1) == 1)
        {
            func_80319564(&D_80225EA8[0], &a2->unkA4);
            return NULL;
        }

        func_80319564(&headList[3], &a2->unkA4);
    }
    return a2;
}

struct Struct_func_80318870 *func_80319830(struct PlaybackListItem *headList, struct SubStruct_func_80318870 *arg1)
{
    struct Struct_func_80318870 *a2 = func_8031AF34(&headList[1]);
    if (a2 != NULL)
    {
        func_8031975C(a2, arg1);
        func_8031AEF4(&headList[2], &a2->unkA4);
    }
    return a2;
}

struct Struct_func_80318870 *func_80319884(struct PlaybackListItem *headList, struct SubStruct_func_80318870 *arg1)
{
    struct Struct_func_80318870 *a2 = func_803195D0(&headList[3], arg1->unk50->unk4);
    if (a2 != 0)
    {
        func_80319728(a2, arg1);
        func_8031AEF4(&headList[2], &a2->unkA4);
    }
    return a2;
}

struct Struct_func_80318870 *func_803198E0(struct SubStruct_func_80318870 *arg0)
{
    struct Struct_func_80318870 *ret;
    u32 mask = arg0->unk50->unk1;

    if (mask & 1)
    {
        ret = arg0->unk44;
        if (ret != NULL && ret->unk28 == arg0)
        {
            func_8031975C(ret, arg0);
            func_803195A4(&ret->unkA4);
            func_8031AEF4(&D_80225EA8[2], &ret->unkA4);
            return ret;
        }
    }

    if (mask & 2)
    {
        if (!(ret = func_803197B4(arg0->unk50->unk80, arg0)) &&
            !(ret = func_80319830(arg0->unk50->unk80, arg0)) &&
            !(ret = func_80319884(arg0->unk50->unk80, arg0)))
        {
            arg0->unk1 = 0;
            return 0;
        }
        return ret;
    }

    if (mask & 4)
    {
        if (!(ret = func_803197B4(arg0->unk50->unk80, arg0)) &&
            !(ret = func_803197B4(arg0->unk50->unk40->unk90, arg0)) &&
            !(ret = func_80319830(arg0->unk50->unk80, arg0)) &&
            !(ret = func_80319830(arg0->unk50->unk40->unk90, arg0)) &&
            !(ret = func_80319884(arg0->unk50->unk80, arg0)) &&
            !(ret = func_80319884(arg0->unk50->unk40->unk90, arg0)))
        {
            arg0->unk1 = 0;
            return 0;
        }
        return ret;
    }

    if (mask & 8)
    {
        if (!(ret = func_803197B4(D_80225EA8, arg0)) &&
            !(ret = func_80319830(D_80225EA8, arg0)) &&
            !(ret = func_80319884(D_80225EA8, arg0)))
        {
            arg0->unk1 = 0;
            return 0;
        }
        return ret;
    }

    if (!(ret = func_803197B4(arg0->unk50->unk80, arg0)) &&
        !(ret = func_803197B4(arg0->unk50->unk40->unk90, arg0)) &&
        !(ret = func_803197B4(D_80225EA8, arg0)) &&
        !(ret = func_80319830(arg0->unk50->unk80, arg0)) &&
        !(ret = func_80319830(arg0->unk50->unk40->unk90, arg0)) &&
        !(ret = func_80319830(D_80225EA8, arg0)) &&
        !(ret = func_80319884(arg0->unk50->unk80, arg0)) &&
        !(ret = func_80319884(arg0->unk50->unk40->unk90, arg0)) &&
        !(ret = func_80319884(D_80225EA8, arg0)))
    {
        arg0->unk1 = 0;
        return 0;
    }
    return ret;
}

void func_80319BC8(void)
{
    struct Struct_func_80318870 *s0;
    struct PlaybackListItem *item;
    s32 i;
    s32 cond;

    for (i = 0; i < D_80226D70; i++)
    {
        s0 = &D_80222A10[i];
        if (s0->unk2C != MINUS_ONE)
        {
            cond = FALSE;
            if (!s0->unk2C->unk0 && s0->unk4 >= 2)
            {
                cond = TRUE;
            }
            else
            {
                item = &s0->unk2C->unk70;
                if (s0->unk2C->unk50 == NULL)
                {
                    func_8031AEF4(&D_80225E98, item);
                    func_8031AA10(s0->unk2C);
                    s0->unk4 = 1;
                }
                else if (s0->unk2C->unk50->unk40 == 0)
                {
                    func_8031AAD0(s0->unk2C->unk50);
                    s0->unk4 = 1;
                }
                else if (s0->unk2C->unk50->unk40->unk0b20)
                {
                    if (s0->unk2C->unk50->unk2 & 0xc0)
                    {
                        cond = TRUE;
                    }
                }
                else
                {
                    cond = FALSE;
                }
            }

            if (cond)
            {
                func_80318EE4(s0->unk2C);
                func_803195A4(&s0->unkA4);
                func_80319564(s0->unkA4.unkC, &s0->unkA4);
                s0->unk4 = 1;
            }
        }
    }
}

void func_80319D40(void)
{
    struct Struct_func_80318870 *temp;
    s32 i;

    for (i = 0; i < D_80226D70; i++)
    {
        temp = &D_80222A10[i];
        temp->unk0b80 = 0;
        temp->unk0b4 = 0;
        temp->unk0b2 = 0;
        temp->unk0b1 = 0;
        temp->unk4 = 0;
        temp->unk2C = MINUS_ONE;
        temp->unk30 = MINUS_ONE;
        temp->unk28 = MINUS_ONE;
        temp->unk40 = 0;
        temp->unk1 = 0;
        temp->unk5 = 0;
        temp->unk6 = 0;
        temp->unk3C = 0;
        temp->unk3E = 0;
        temp->unk38 = 0.0f;
        temp->unk41 = 0x3f;
        temp->unk44.unk8 = 0.0f;
        temp->unk8 = 0;
        temp->unk55 = 0;
        temp->unk54 = 0;
        temp->unk90 = 0;
        temp->unk78 = 0.0f;
        temp->unk7C = 0.0f;
        temp->unk34 = soundAlloc(D_802212C8, 0x190);
    }
}
