#include <ultra64.h>

#include "sm64.h"
#include "dac.h"
#include "data.h"
#include "dma.h"
#include "playback.h"
#include "something.h"
#include "interface_1.h"
#include "interface_2.h"

#define ALIGN16(val) (((val) + 0xF) & ~0xF)

struct Struct803161E0
{
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
}; // size = 0x10

struct U32Pair
{
    u32 first;
    u32 second;
}; // size = 0x8

extern struct SoundAllocPool D_802212A8;
extern struct SoundAllocPool D_802212F8;
extern struct SoundAllocPool D_80221308;
extern struct SoundAllocPool D_80221318;

extern struct SoundMultiPool D_802216C8;

extern s32 D_80226D6C;

extern struct Struct803161E0 D_80221898;
extern struct U32Pair D_802218A8;
extern struct Struct803161E0 D_802218B0;
extern struct Struct803161E0 D_802218C0;

void func_80315E60(void)
{
    int i;

    for (i = 0; i < 64; i++)
    {
        D_802218D0[i] = 0;
    }

    for (i = 0; i < 256; i++)
    {
        D_80221910[i] = 0;
    }
}


void func_80315EA4(int arg0)
{
    int i;

    for (i = 0; i < D_80226D70; i++)
    {
        struct Struct_func_80318870 *s0 = &D_80222A10[i];

        if (s0->unk7 == arg0)
        {
            if (s0->unk4 > 1)
            {
                s0->unk2C->unk0b80 = 0;
                s0->unk2C->unk0b40 = 1;
            }
            func_80315DE0(s0);
            func_803195A4(&s0->unkA4);
            func_8031AEF4(&D_80225EA8[0], &s0->unkA4);
        }
    }
}


void func_80315F94(int arg0)
{
    int i;

    for (i = 0; i < 3; i++)
    {
        if (D_80222A18[i].unk0b80 && D_80222A18[i].unk5 == arg0)
            func_8031AE24(D_80222A18 + i);
    }
}

#ifdef NON_MATCHING
void *soundAlloc(struct SoundAllocPool *pool, u32 size)
{
    // Has a bunch of register swaps: v1 -> a2/a0, a1 -> v1, a2 -> a1
    s32 last; // a2
    s32 i; // a3
    u8 *ret; // a1, v0
    s32 aligned; // t6

    ret = pool->unk4;
    aligned = ALIGN16(size);
    if (pool->unk4 + aligned <= pool->unk8 + pool->unk0)
    {
        pool->unk4 += aligned;
        last = pool->unk4 - ret - 1;
        for (i = 0; i <= last; i++)
        {
            ret[i] = 0;
        }
    }
    else
    {
        return NULL;
    }

    return ret;
}
#else
GLOBAL_ASM(
glabel soundAlloc
/* 0D1020 80316020 8C820004 */  lw    $v0, 4($a0)
/* 0D1024 80316024 8C8F0008 */  lw    $t7, 8($a0)
/* 0D1028 80316028 8C980000 */  lw    $t8, ($a0)
/* 0D102C 8031602C 24A3000F */  addiu $v1, $a1, 0xf
/* 0D1030 80316030 2401FFF0 */  li    $at, -16
/* 0D1034 80316034 00617024 */  and   $t6, $v1, $at
/* 0D1038 80316038 004E4021 */  addu  $t0, $v0, $t6
/* 0D103C 8031603C 01F8C821 */  addu  $t9, $t7, $t8
/* 0D1040 80316040 0328082B */  sltu  $at, $t9, $t0
/* 0D1044 80316044 1420000E */  bnez  $at, .L80316080
/* 0D1048 80316048 00402825 */   move  $a1, $v0
/* 0D104C 8031604C 004E4821 */  addu  $t1, $v0, $t6
/* 0D1050 80316050 01223023 */  subu  $a2, $t1, $v0
/* 0D1054 80316054 24C6FFFF */  addiu $a2, $a2, -1
/* 0D1058 80316058 AC890004 */  sw    $t1, 4($a0)
/* 0D105C 8031605C 04C0000A */  bltz  $a2, .L80316088
/* 0D1060 80316060 00003825 */   move  $a3, $zero
/* 0D1064 80316064 24C30001 */  addiu $v1, $a2, 1
.L80316068:
/* 0D1068 80316068 24E70001 */  addiu $a3, $a3, 1
/* 0D106C 8031606C 24420001 */  addiu $v0, $v0, 1
/* 0D1070 80316070 1467FFFD */  bne   $v1, $a3, .L80316068
/* 0D1074 80316074 A040FFFF */   sb    $zero, -1($v0)
/* 0D1078 80316078 10000004 */  b     .L8031608C
/* 0D107C 8031607C 00A01025 */   move  $v0, $a1
.L80316080:
/* 0D1080 80316080 03E00008 */  jr    $ra
/* 0D1084 80316084 00001025 */   move  $v0, $zero
.L80316088:
/* 0D1088 80316088 00A01025 */  move  $v0, $a1
.L8031608C:
/* 0D108C 8031608C 03E00008 */  jr    $ra
/* 0D1090 80316090 00000000 */   nop   
)
#endif

void func_80316094(struct SoundAllocPool *arg0, void *arg1, u32 arg2)
{
    arg0->unk4 = arg0->unk0 = (u8 *)(((u32) arg1 + 0xf) & -0x10);
    arg0->unk8 = arg2;
    arg0->unkC = 0;
}

void func_803160B4(struct SoundPoolHolder *arg0)
{
    arg0->pool.unkC = 0;
    arg0->unk0 = 0;
    arg0->pool.unk4 = arg0->pool.unk0;
}

void func_803160C8(struct SoundPoolHolder2 *arg0)
{
    arg0->pool.unkC = 0;
    arg0->unk0 = 0;
    arg0->arr[1].unk0 = arg0->pool.unk8 + arg0->pool.unk0;
    arg0->arr[0].unk8 = -1;
    arg0->arr[1].unk8 = -1;
    arg0->pool.unk4 = arg0->pool.unk0;
    arg0->arr[0].unk0 = arg0->pool.unk0;
}

void unused_803160F8(struct SoundAllocPool *arg0)
{
    arg0->unkC = 0;
    arg0->unk4 = arg0->unk0;
}

void func_80316108(s32 arg0)
{
    func_80316094(&D_802212B8, gAudioHeap, arg0);
    func_80316094(&D_802212A8, gAudioHeap + arg0, D_80333EEC - arg0);
}

void func_80316164(struct Struct803161E0 *a)
{
    D_802212A8.unk4 = D_802212A8.unk0;
    func_80316094(&D_802212C8, soundAlloc(&D_802212A8, a->unk0), a->unk0);
    func_80316094(&D_802212F8, soundAlloc(&D_802212A8, a->unkC), a->unkC);
}

void func_803161E0(struct U32Pair *a)
{
    D_802212F8.unk4 = D_802212F8.unk0;
    func_80316094(&D_80221308, soundAlloc(&D_802212F8, a->first), a->first);
    func_80316094(&D_80221318, soundAlloc(&D_802212F8, a->second), a->second);
}

void func_8031625C(struct Struct803161E0 *a)
{
    D_80221308.unk4 = D_80221308.unk0;
    func_80316094(&D_80221328.first.pool, soundAlloc(&D_80221308, a->unk0), a->unk0);
    func_80316094(&D_802214F8.first.pool, soundAlloc(&D_80221308, a->unk4), a->unk4);
    func_80316094(&D_802216C8.first.pool, soundAlloc(&D_80221308, a->unk8), a->unk8);
    func_803160B4(&D_80221328.first);
    func_803160B4(&D_802214F8.first);
    func_803160B4(&D_802216C8.first);
}

void func_80316318(struct Struct803161E0 *a)
{
    D_80221318.unk4 = D_80221318.unk0;
    func_80316094(&D_80221328.second.pool, soundAlloc(&D_80221318, a->unk0), a->unk0);
    func_80316094(&D_802214F8.second.pool, soundAlloc(&D_80221318, a->unk4), a->unk4);
    func_80316094(&D_802216C8.second.pool, soundAlloc(&D_80221318, a->unk8), a->unk8);
    func_803160C8(&D_80221328.second);
    func_803160C8(&D_802214F8.second);
    func_803160C8(&D_802216C8.second);
}

static void unused_803163D4()
{
}

#ifdef NON_MATCHING
void *func_803163DC(struct SoundMultiPool *arg0, s32 count, s32 size, s32 arg3, s32 arg4)
{
    // arg3 = 0, 1 or 2?
    // arg4 = some int?

    u8 *table; // sp5C
    u8 index; // sp5B
    struct SoundAllocPool *pool;
    void *ret;
    u32 firstVal;
    u32 secondVal;
    u32 both3;
    u32 first3, second3;
    u32 first0, second0;
    u32 firstN1, secondN1;
    UNUSED s32 temp;
    struct SoundPoolHolder2 *v1; // sp30
    struct SoundPoolHolder *first = &arg0->first;

    if (arg3 == 0)
    {
        v1 = &arg0->second;
        if (arg0 == &D_80221328)
        {
            table = D_80221910;
            index = 0;
        }
        else if (arg0 == &D_802214F8)
        {
            table = D_802218D0;
            index = 1;
        }

        firstVal = (v1->arr[0].unk8 == -1 ? 0 : table[v1->arr[0].unk8]); // a3, a2
        secondVal = (v1->arr[1].unk8 == -1 ? 0 : table[v1->arr[1].unk8]); // a1
        first0 = (firstVal == 0);
        first3 = (firstVal == 3); // t0
        firstN1 = (firstVal != 1);
        second0 = (secondVal == 0);
        second3 = (secondVal == 3);
        secondN1 = (secondVal != 1);
        both3 = (first3 && second3); // a0

        if (first0)
        {
            v1->unk0 = 0;
        }
        else if (second0)
        {
            v1->unk0 = 1;
        }
        else if (both3)
        {
            // either is fine, maybe?
        }
        else if (first3)
        {
            v1->unk0 = 0;
        }
        else if (second3)
        {
            v1->unk0 = 1;
        }
        else if (firstN1)
        {
            v1->unk0 = 0;
        }
        else if (secondN1)
        {
            v1->unk0 = 1;
        }
        else
        {
            return NULL;
        }

        if (v1->arr[v1->unk0].unk8 != -1)
        {
            table[v1->arr[v1->unk0].unk8] = 0;
            if (index == 1)
            {
                func_80315EA4(v1->arr[v1->unk0].unk8);
            }
        }

        pool = &arg0->second.pool; // a1
        switch (v1->unk0)
        {
        case 0:
            v1->arr[0].unk0 = pool->unk0;
            v1->arr[0].unk8 = arg4;
            v1->arr[0].unk4 = size;

            pool->unk4 = pool->unk0 + size;

            if (v1->arr[1].unk0 < pool->unk4)
            {
                table[v1->arr[1].unk8] = 0;

                switch (index)
                {
                case 0:
                    func_80315F94(v1->arr[1].unk8);
                    break;
                case 1:
                    func_80315EA4(v1->arr[1].unk8);
                    break;
                }

                v1->arr[1].unk8 = -1;
                v1->arr[1].unk0 = pool->unk8 + pool->unk0;
            }

            ret = v1->arr[0].unk0;
            break;

        case 1:
            v1->arr[1].unk0 = pool->unk8 + pool->unk0 - size - 0x10;
            v1->arr[1].unk8 = arg4;
            v1->arr[1].unk4 = size;

            if (v1->arr[1].unk0 < pool->unk4)
            {
                table[v1->arr[0].unk8] = 0;

                switch (index)
                {
                case 0:
                    func_80315F94(v1->arr[0].unk8);
                    break;
                case 1:
                    func_80315EA4(v1->arr[0].unk8);
                    break;
                }

                v1->arr[0].unk8 = -1;
                pool->unk4 = pool->unk0;
            }

            ret = v1->arr[1].unk0;
            break;

        default:
            return NULL;
        }

        v1->unk0 ^= 1;
        return ret;
    }

    arg0->arr[first->unk0].unk0 = soundAlloc(&first->pool, count * size);

    if (arg0->arr[first->unk0].unk0 == 0)
    {
        if (arg3 != 1)
        {
            if (arg3 == 2)
            {
                // Prevent tail call optimization.
                ret = func_803163DC(arg0, count, size, 0, arg4);
                return ret;
            }
        }
        else
        {
            return NULL;
        }
    }

    arg0->arr[first->unk0].unk8 = arg4;
    arg0->arr[first->unk0].unk4 = size;
    first->unk0++; return arg0->arr[first->unk0 - 1].unk0;
}

#else
GLOBAL_ASM(
glabel func_803163DC
/* 0D13DC 803163DC 27BDFF88 */  addiu $sp, $sp, -0x78
/* 0D13E0 803163E0 AFB00020 */  sw    $s0, 0x20($sp)
/* 0D13E4 803163E4 00808025 */  move  $s0, $a0
/* 0D13E8 803163E8 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0D13EC 803163EC AFA5007C */  sw    $a1, 0x7c($sp)
/* 0D13F0 803163F0 14E000CC */  bnez  $a3, .L80316724
/* 0D13F4 803163F4 AFA60080 */   sw    $a2, 0x80($sp)
/* 0D13F8 803163F8 3C0E8022 */  lui   $t6, %hi(D_80221328) # $t6, 0x8022
/* 0D13FC 803163FC 25CE1328 */  addiu $t6, %lo(D_80221328) # addiu $t6, $t6, 0x1328
/* 0D1400 80316400 148E0006 */  bne   $a0, $t6, .L8031641C
/* 0D1404 80316404 26030194 */   addiu $v1, $s0, 0x194
/* 0D1408 80316408 3C0A8022 */  lui   $t2, %hi(D_80221910) # $t2, 0x8022
/* 0D140C 8031640C 254A1910 */  addiu $t2, %lo(D_80221910) # addiu $t2, $t2, 0x1910
/* 0D1410 80316410 AFAA005C */  sw    $t2, 0x5c($sp)
/* 0D1414 80316414 10000009 */  b     .L8031643C
/* 0D1418 80316418 A3A0005B */   sb    $zero, 0x5b($sp)
.L8031641C:
/* 0D141C 8031641C 3C0F8022 */  lui   $t7, %hi(D_802214F8) # $t7, 0x8022
/* 0D1420 80316420 25EF14F8 */  addiu $t7, %lo(D_802214F8) # addiu $t7, $t7, 0x14f8
/* 0D1424 80316424 160F0005 */  bne   $s0, $t7, .L8031643C
/* 0D1428 80316428 3C0A8022 */   lui   $t2, %hi(D_802218D0) # $t2, 0x8022
/* 0D142C 8031642C 254A18D0 */  addiu $t2, %lo(D_802218D0) # addiu $t2, $t2, 0x18d0
/* 0D1430 80316430 240C0001 */  li    $t4, 1
/* 0D1434 80316434 A3AC005B */  sb    $t4, 0x5b($sp)
/* 0D1438 80316438 AFAA005C */  sw    $t2, 0x5c($sp)
.L8031643C:
/* 0D143C 8031643C 8C62001C */  lw    $v0, 0x1c($v1)
/* 0D1440 80316440 240BFFFF */  li    $t3, -1
/* 0D1444 80316444 8FAA005C */  lw    $t2, 0x5c($sp)
/* 0D1448 80316448 15620003 */  bne   $t3, $v0, .L80316458
/* 0D144C 8031644C 93AC005B */   lbu   $t4, 0x5b($sp)
/* 0D1450 80316450 10000003 */  b     .L80316460
/* 0D1454 80316454 00003825 */   move  $a3, $zero
.L80316458:
/* 0D1458 80316458 004AC021 */  addu  $t8, $v0, $t2
/* 0D145C 8031645C 93070000 */  lbu   $a3, ($t8)
.L80316460:
/* 0D1460 80316460 8C620028 */  lw    $v0, 0x28($v1)
/* 0D1464 80316464 24090003 */  li    $t1, 3
/* 0D1468 80316468 01274026 */  xor   $t0, $t1, $a3
/* 0D146C 8031646C 15620003 */  bne   $t3, $v0, .L8031647C
/* 0D1470 80316470 2D080001 */   sltiu $t0, $t0, 1
/* 0D1474 80316474 10000003 */  b     .L80316484
/* 0D1478 80316478 00002825 */   move  $a1, $zero
.L8031647C:
/* 0D147C 8031647C 004AC821 */  addu  $t9, $v0, $t2
/* 0D1480 80316480 93250000 */  lbu   $a1, ($t9)
.L80316484:
/* 0D1484 80316484 0008202B */  sltu  $a0, $zero, $t0
/* 0D1488 80316488 10800005 */  beqz  $a0, .L803164A0
/* 0D148C 8031648C 00E03025 */   move  $a2, $a3
/* 0D1490 80316490 01252026 */  xor   $a0, $t1, $a1
/* 0D1494 80316494 2C840001 */  sltiu $a0, $a0, 1
/* 0D1498 80316498 0004682B */  sltu  $t5, $zero, $a0
/* 0D149C 8031649C 01A02025 */  move  $a0, $t5
.L803164A0:
/* 0D14A0 803164A0 2CCE0001 */  sltiu $t6, $a2, 1
/* 0D14A4 803164A4 11C00004 */  beqz  $t6, .L803164B8
/* 0D14A8 803164A8 2CAF0001 */   sltiu $t7, $a1, 1
/* 0D14AC 803164AC AC600000 */  sw    $zero, ($v1)
/* 0D14B0 803164B0 10000020 */  b     .L80316534
/* 0D14B4 803164B4 24080001 */   li    $t0, 1
.L803164B8:
/* 0D14B8 803164B8 11E00005 */  beqz  $t7, .L803164D0
/* 0D14BC 803164BC 00A01025 */   move  $v0, $a1
/* 0D14C0 803164C0 24180001 */  li    $t8, 1
/* 0D14C4 803164C4 AC780000 */  sw    $t8, ($v1)
/* 0D14C8 803164C8 1000001A */  b     .L80316534
/* 0D14CC 803164CC 24080001 */   li    $t0, 1
.L803164D0:
/* 0D14D0 803164D0 10800003 */  beqz  $a0, .L803164E0
/* 0D14D4 803164D4 00000000 */   nop   
/* 0D14D8 803164D8 10000016 */  b     .L80316534
/* 0D14DC 803164DC 24080001 */   li    $t0, 1
.L803164E0:
/* 0D14E0 803164E0 11000004 */  beqz  $t0, .L803164F4
/* 0D14E4 803164E4 00000000 */   nop   
/* 0D14E8 803164E8 AC600000 */  sw    $zero, ($v1)
/* 0D14EC 803164EC 10000011 */  b     .L80316534
/* 0D14F0 803164F0 24080001 */   li    $t0, 1
.L803164F4:
/* 0D14F4 803164F4 15220005 */  bne   $t1, $v0, .L8031650C
/* 0D14F8 803164F8 24080001 */   li    $t0, 1
/* 0D14FC 803164FC 240D0001 */  li    $t5, 1
/* 0D1500 80316500 AC6D0000 */  sw    $t5, ($v1)
/* 0D1504 80316504 1000000B */  b     .L80316534
/* 0D1508 80316508 24080001 */   li    $t0, 1
.L8031650C:
/* 0D150C 8031650C 11060003 */  beq   $t0, $a2, .L8031651C
/* 0D1510 80316510 00000000 */   nop   
/* 0D1514 80316514 10000007 */  b     .L80316534
/* 0D1518 80316518 AC600000 */   sw    $zero, ($v1)
.L8031651C:
/* 0D151C 8031651C 11020003 */  beq   $t0, $v0, .L8031652C
/* 0D1520 80316520 24180001 */   li    $t8, 1
/* 0D1524 80316524 10000003 */  b     .L80316534
/* 0D1528 80316528 AC780000 */   sw    $t8, ($v1)
.L8031652C:
/* 0D152C 8031652C 100000B2 */  b     .L803167F8
/* 0D1530 80316530 00001025 */   move  $v0, $zero
.L80316534:
/* 0D1534 80316534 8C790000 */  lw    $t9, ($v1)
/* 0D1538 80316538 2405000C */  li    $a1, 12
/* 0D153C 8031653C 03250019 */  multu $t9, $a1
/* 0D1540 80316540 00006812 */  mflo  $t5
/* 0D1544 80316544 006D7021 */  addu  $t6, $v1, $t5
/* 0D1548 80316548 8DC2001C */  lw    $v0, 0x1c($t6)
/* 0D154C 8031654C 11620010 */  beq   $t3, $v0, .L80316590
/* 0D1550 80316550 01427821 */   addu  $t7, $t2, $v0
/* 0D1554 80316554 150C000E */  bne   $t0, $t4, .L80316590
/* 0D1558 80316558 A1E00000 */   sb    $zero, ($t7)
/* 0D155C 8031655C 8C780000 */  lw    $t8, ($v1)
/* 0D1560 80316560 03050019 */  multu $t8, $a1
/* 0D1564 80316564 0000C812 */  mflo  $t9
/* 0D1568 80316568 00796821 */  addu  $t5, $v1, $t9
/* 0D156C 8031656C 8DA4001C */  lw    $a0, 0x1c($t5)
/* 0D1570 80316570 A3AC005B */  sb    $t4, 0x5b($sp)
/* 0D1574 80316574 AFAA005C */  sw    $t2, 0x5c($sp)
/* 0D1578 80316578 0C0C57A9 */  jal   func_80315EA4
/* 0D157C 8031657C AFA30030 */   sw    $v1, 0x30($sp)
/* 0D1580 80316580 8FA30030 */  lw    $v1, 0x30($sp)
/* 0D1584 80316584 24080001 */  li    $t0, 1
/* 0D1588 80316588 8FAA005C */  lw    $t2, 0x5c($sp)
/* 0D158C 8031658C 93AC005B */  lbu   $t4, 0x5b($sp)
.L80316590:
/* 0D1590 80316590 8C640000 */  lw    $a0, ($v1)
/* 0D1594 80316594 24010001 */  li    $at, 1
/* 0D1598 80316598 26050198 */  addiu $a1, $s0, 0x198
/* 0D159C 8031659C 50800006 */  beql  $a0, $zero, .L803165B8
/* 0D15A0 803165A0 8CAE0000 */   lw    $t6, ($a1)
/* 0D15A4 803165A4 10810032 */  beq   $a0, $at, .L80316670
/* 0D15A8 803165A8 26050198 */   addiu $a1, $s0, 0x198
/* 0D15AC 803165AC 10000092 */  b     .L803167F8
/* 0D15B0 803165B0 00001025 */   move  $v0, $zero
/* 0D15B4 803165B4 8CAE0000 */  lw    $t6, ($a1)
.L803165B8:
/* 0D15B8 803165B8 AC6E0014 */  sw    $t6, 0x14($v1)
/* 0D15BC 803165BC 8FAF0088 */  lw    $t7, 0x88($sp)
/* 0D15C0 803165C0 AC6F001C */  sw    $t7, 0x1c($v1)
/* 0D15C4 803165C4 8FB80080 */  lw    $t8, 0x80($sp)
/* 0D15C8 803165C8 AC780018 */  sw    $t8, 0x18($v1)
/* 0D15CC 803165CC 8FAD0080 */  lw    $t5, 0x80($sp)
/* 0D15D0 803165D0 8CB90000 */  lw    $t9, ($a1)
/* 0D15D4 803165D4 032D1021 */  addu  $v0, $t9, $t5
/* 0D15D8 803165D8 ACA20004 */  sw    $v0, 4($a1)
/* 0D15DC 803165DC 8C6E0020 */  lw    $t6, 0x20($v1)
/* 0D15E0 803165E0 01C2082B */  sltu  $at, $t6, $v0
/* 0D15E4 803165E4 5020001D */  beql  $at, $zero, .L8031665C
/* 0D15E8 803165E8 8C640014 */   lw    $a0, 0x14($v1)
/* 0D15EC 803165EC 8C6F0028 */  lw    $t7, 0x28($v1)
/* 0D15F0 803165F0 014FC021 */  addu  $t8, $t2, $t7
/* 0D15F4 803165F4 11800005 */  beqz  $t4, .L8031660C
/* 0D15F8 803165F8 A3000000 */   sb    $zero, ($t8)
/* 0D15FC 803165FC 5188000B */  beql  $t4, $t0, .L8031662C
/* 0D1600 80316600 8C640028 */   lw    $a0, 0x28($v1)
/* 0D1604 80316604 1000000F */  b     .L80316644
/* 0D1608 80316608 2419FFFF */   li    $t9, -1
.L8031660C:
/* 0D160C 8031660C 8C640028 */  lw    $a0, 0x28($v1)
/* 0D1610 80316610 AFA5002C */  sw    $a1, 0x2c($sp)
/* 0D1614 80316614 0C0C57E5 */  jal   func_80315F94
/* 0D1618 80316618 AFA30030 */   sw    $v1, 0x30($sp)
/* 0D161C 8031661C 8FA30030 */  lw    $v1, 0x30($sp)
/* 0D1620 80316620 10000007 */  b     .L80316640
/* 0D1624 80316624 8FA5002C */   lw    $a1, 0x2c($sp)
/* 0D1628 80316628 8C640028 */  lw    $a0, 0x28($v1)
.L8031662C:
/* 0D162C 8031662C AFA5002C */  sw    $a1, 0x2c($sp)
/* 0D1630 80316630 0C0C57A9 */  jal   func_80315EA4
/* 0D1634 80316634 AFA30030 */   sw    $v1, 0x30($sp)
/* 0D1638 80316638 8FA30030 */  lw    $v1, 0x30($sp)
/* 0D163C 8031663C 8FA5002C */  lw    $a1, 0x2c($sp)
.L80316640:
/* 0D1640 80316640 2419FFFF */  li    $t9, -1
.L80316644:
/* 0D1644 80316644 AC790028 */  sw    $t9, 0x28($v1)
/* 0D1648 80316648 8CAE0000 */  lw    $t6, ($a1)
/* 0D164C 8031664C 8CAD0008 */  lw    $t5, 8($a1)
/* 0D1650 80316650 01AE7821 */  addu  $t7, $t5, $t6
/* 0D1654 80316654 AC6F0020 */  sw    $t7, 0x20($v1)
/* 0D1658 80316658 8C640014 */  lw    $a0, 0x14($v1)
.L8031665C:
/* 0D165C 8031665C 8C780000 */  lw    $t8, ($v1)
/* 0D1660 80316660 00801025 */  move  $v0, $a0
/* 0D1664 80316664 3B190001 */  xori  $t9, $t8, 1
/* 0D1668 80316668 10000063 */  b     .L803167F8
/* 0D166C 8031666C AC790000 */   sw    $t9, ($v1)
.L80316670:
/* 0D1670 80316670 8CAD0008 */  lw    $t5, 8($a1)
/* 0D1674 80316674 8CAE0000 */  lw    $t6, ($a1)
/* 0D1678 80316678 8FB80080 */  lw    $t8, 0x80($sp)
/* 0D167C 8031667C 01AE7821 */  addu  $t7, $t5, $t6
/* 0D1680 80316680 01F8C823 */  subu  $t9, $t7, $t8
/* 0D1684 80316684 2722FFF0 */  addiu $v0, $t9, -0x10
/* 0D1688 80316688 AC620020 */  sw    $v0, 0x20($v1)
/* 0D168C 8031668C 8FAE0088 */  lw    $t6, 0x88($sp)
/* 0D1690 80316690 AC6E0028 */  sw    $t6, 0x28($v1)
/* 0D1694 80316694 8FAF0080 */  lw    $t7, 0x80($sp)
/* 0D1698 80316698 AC6F0024 */  sw    $t7, 0x24($v1)
/* 0D169C 8031669C 8CB80004 */  lw    $t8, 4($a1)
/* 0D16A0 803166A0 0058082B */  sltu  $at, $v0, $t8
/* 0D16A4 803166A4 1020001B */  beqz  $at, .L80316714
/* 0D16A8 803166A8 00000000 */   nop   
/* 0D16AC 803166AC 8C79001C */  lw    $t9, 0x1c($v1)
/* 0D16B0 803166B0 01596821 */  addu  $t5, $t2, $t9
/* 0D16B4 803166B4 11800005 */  beqz  $t4, .L803166CC
/* 0D16B8 803166B8 A1A00000 */   sb    $zero, ($t5)
/* 0D16BC 803166BC 5188000B */  beql  $t4, $t0, .L803166EC
/* 0D16C0 803166C0 8C64001C */   lw    $a0, 0x1c($v1)
/* 0D16C4 803166C4 1000000F */  b     .L80316704
/* 0D16C8 803166C8 240EFFFF */   li    $t6, -1
.L803166CC:
/* 0D16CC 803166CC 8C64001C */  lw    $a0, 0x1c($v1)
/* 0D16D0 803166D0 AFA5002C */  sw    $a1, 0x2c($sp)
/* 0D16D4 803166D4 0C0C57E5 */  jal   func_80315F94
/* 0D16D8 803166D8 AFA30030 */   sw    $v1, 0x30($sp)
/* 0D16DC 803166DC 8FA30030 */  lw    $v1, 0x30($sp)
/* 0D16E0 803166E0 10000007 */  b     .L80316700
/* 0D16E4 803166E4 8FA5002C */   lw    $a1, 0x2c($sp)
/* 0D16E8 803166E8 8C64001C */  lw    $a0, 0x1c($v1)
.L803166EC:
/* 0D16EC 803166EC AFA5002C */  sw    $a1, 0x2c($sp)
/* 0D16F0 803166F0 0C0C57A9 */  jal   func_80315EA4
/* 0D16F4 803166F4 AFA30030 */   sw    $v1, 0x30($sp)
/* 0D16F8 803166F8 8FA30030 */  lw    $v1, 0x30($sp)
/* 0D16FC 803166FC 8FA5002C */  lw    $a1, 0x2c($sp)
.L80316700:
/* 0D1700 80316700 240EFFFF */  li    $t6, -1
.L80316704:
/* 0D1704 80316704 AC6E001C */  sw    $t6, 0x1c($v1)
/* 0D1708 80316708 8CAF0000 */  lw    $t7, ($a1)
/* 0D170C 8031670C ACAF0004 */  sw    $t7, 4($a1)
/* 0D1710 80316710 8C620020 */  lw    $v0, 0x20($v1)
.L80316714:
/* 0D1714 80316714 1000FFD1 */  b     .L8031665C
/* 0D1718 80316718 00402025 */   move  $a0, $v0
/* 0D171C 8031671C 10000036 */  b     .L803167F8
/* 0D1720 80316720 00001025 */   move  $v0, $zero
.L80316724:
/* 0D1724 80316724 8FB8007C */  lw    $t8, 0x7c($sp)
/* 0D1728 80316728 8FB90080 */  lw    $t9, 0x80($sp)
/* 0D172C 8031672C 26040004 */  addiu $a0, $s0, 4
/* 0D1730 80316730 AFA70084 */  sw    $a3, 0x84($sp)
/* 0D1734 80316734 03190019 */  multu $t8, $t9
/* 0D1738 80316738 00002812 */  mflo  $a1
/* 0D173C 8031673C 0C0C5808 */  jal   soundAlloc
/* 0D1740 80316740 00000000 */   nop   
/* 0D1744 80316744 8E0D0000 */  lw    $t5, ($s0)
/* 0D1748 80316748 2405000C */  li    $a1, 12
/* 0D174C 8031674C 8FA70084 */  lw    $a3, 0x84($sp)
/* 0D1750 80316750 01A50019 */  multu $t5, $a1
/* 0D1754 80316754 24080001 */  li    $t0, 1
/* 0D1758 80316758 00007012 */  mflo  $t6
/* 0D175C 8031675C 020E7821 */  addu  $t7, $s0, $t6
/* 0D1760 80316760 ADE20014 */  sw    $v0, 0x14($t7)
/* 0D1764 80316764 8E180000 */  lw    $t8, ($s0)
/* 0D1768 80316768 8FAF0088 */  lw    $t7, 0x88($sp)
/* 0D176C 8031676C 03050019 */  multu $t8, $a1
/* 0D1770 80316770 0000C812 */  mflo  $t9
/* 0D1774 80316774 02191821 */  addu  $v1, $s0, $t9
/* 0D1778 80316778 8C6D0014 */  lw    $t5, 0x14($v1)
/* 0D177C 8031677C 55A00010 */  bnezl $t5, .L803167C0
/* 0D1780 80316780 AC6F001C */   sw    $t7, 0x1c($v1)
/* 0D1784 80316784 10E8000B */  beq   $a3, $t0, .L803167B4
/* 0D1788 80316788 24010002 */   li    $at, 2
/* 0D178C 8031678C 14E1000B */  bne   $a3, $at, .L803167BC
/* 0D1790 80316790 02002025 */   move  $a0, $s0
/* 0D1794 80316794 8FAE0088 */  lw    $t6, 0x88($sp)
/* 0D1798 80316798 8FA5007C */  lw    $a1, 0x7c($sp)
/* 0D179C 8031679C 8FA60080 */  lw    $a2, 0x80($sp)
/* 0D17A0 803167A0 00003825 */  move  $a3, $zero
/* 0D17A4 803167A4 0C0C58F7 */  jal   func_803163DC
/* 0D17A8 803167A8 AFAE0010 */   sw    $t6, 0x10($sp)
/* 0D17AC 803167AC 10000013 */  b     .L803167FC
/* 0D17B0 803167B0 8FBF0024 */   lw    $ra, 0x24($sp)
.L803167B4:
/* 0D17B4 803167B4 10000010 */  b     .L803167F8
/* 0D17B8 803167B8 00001025 */   move  $v0, $zero
.L803167BC:
/* 0D17BC 803167BC AC6F001C */  sw    $t7, 0x1c($v1)
.L803167C0:
/* 0D17C0 803167C0 8E190000 */  lw    $t9, ($s0)
/* 0D17C4 803167C4 8FB80080 */  lw    $t8, 0x80($sp)
/* 0D17C8 803167C8 03250019 */  multu $t9, $a1
/* 0D17CC 803167CC 00006812 */  mflo  $t5
/* 0D17D0 803167D0 020D7021 */  addu  $t6, $s0, $t5
/* 0D17D4 803167D4 ADD80018 */  sw    $t8, 0x18($t6)
/* 0D17D8 803167D8 8E0F0000 */  lw    $t7, ($s0)
/* 0D17DC 803167DC 25F90001 */  addiu $t9, $t7, 1
/* 0D17E0 803167E0 0019C080 */  sll   $t8, $t9, 2
/* 0D17E4 803167E4 0319C023 */  subu  $t8, $t8, $t9
/* 0D17E8 803167E8 0018C080 */  sll   $t8, $t8, 2
/* 0D17EC 803167EC 02187021 */  addu  $t6, $s0, $t8
/* 0D17F0 803167F0 AE190000 */  sw    $t9, ($s0)
/* 0D17F4 803167F4 8DC20008 */  lw    $v0, 8($t6)
.L803167F8:
/* 0D17F8 803167F8 8FBF0024 */  lw    $ra, 0x24($sp)
.L803167FC:
/* 0D17FC 803167FC 8FB00020 */  lw    $s0, 0x20($sp)
/* 0D1800 80316800 27BD0078 */  addiu $sp, $sp, 0x78
/* 0D1804 80316804 03E00008 */  jr    $ra
/* 0D1808 80316808 00000000 */   nop   
)
#endif

void *func_8031680C(struct SoundMultiPool *arg0, s32 arg1, s32 arg2)
{
    u32 i;
    void *ret;
    struct SoundPoolHolder2 *second = &arg0->second;

    if (arg1 == 0)
    {
        if (second->arr[0].unk8 == arg2)
        {
            second->unk0 = 1;
            return second->arr[0].unk0;
        }
        else if (second->arr[1].unk8 == arg2)
        {
            second->unk0 = 0;
            return second->arr[1].unk0;
        }
        return NULL;
    }
    else
    {
        struct SoundPoolHolder *first = &arg0->first;
        for (i = 0; i < first->unk0; i++)
        {
            if (arg2 == arg0->arr[i].unk8)
            {
                return arg0->arr[i].unk0;
            }
        }

        if (arg1 == 2)
        {
            // Prevent tail call optimization by using a temporary.
            // (Did they compile with -Wo,-notail?)
            ret = func_8031680C(arg0, 0, arg2);
            return ret;
        }
        return NULL;
    }
}

void func_803168CC(void)
{
    D_802211B0.unk4 -= D_802211B0.unk4 / 4;
}

void func_803168F4(s32 frames)
{
    // Sleep for a number of frames.
    D_80226D80 = 0;
    while (D_80226D80 < frames) { /* spin */ }
}

#ifdef NON_MATCHING

void func_80316928(struct Struct80332190 *arg0)
{
    // Wrong regalloc, and a lui which is too far up.
    s32 sp2C;
    s16 *mem;
    s32 i; // s0
    s32 j;
    s32 k;
    s32 sum1;
    s32 sum2;
    s32 sum3;
    s32 sum4;
    s32 s1;
    s8 temp8;
    s32 size;
    UNUSED s32 temp;

    if (D_80333EF4 != 0)
    {
        func_803168CC();
        for (i = 0; i < D_80226D70; i++)
        {
            if (D_80222A10[i].unk0b80 && D_80222A10[i].unk54.unk01)
            {
                D_80222A10[i].unk54.unk0E = 0x8000 / D_80226D7E;
                D_80222A10[i].unk54.unk00 |= 0x10;
            }
        }

        s1 = 0;
        for (;;)
        {
            func_803168F4(1);
            s1++;
            if (s1 > 8 * 30)
            {
                // Break after 8 seconds
                break;
            }

            for (i = 0; i < D_80226D70; i++)
            {
                if (D_80222A10[i].unk0b80)
                    break;
            }

            if (i == D_80226D70)
            {
                // All zero, break early
                break;
            }
        }

        func_803168CC();
        func_803168F4(3);
        D_80333EF4 = 0x19710515;
        func_803168F4(3);

        s1 = D_80226D84;
        while (s1 > 0)
        {
            for (i = 0; i < D_80226D84; i++)
            {
                if (osRecvMesg(&D_80225EE8, NULL, OS_MESG_NOBLOCK) == 0)
                    s1--;
            }
        }
        D_80226D84 = 0;

        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 0x500; k++)
            {
                D_80226E40[j][k] = 0;
            }
        }
    }

    D_80226B38 = 0;
    sp2C = arg0->size;
    D_80226D64 = osAiSetFrequency(arg0->frequency);
    D_80226D70 = arg0->unk4;
    size = D_80226D64 / 60;
    D_80226D74 = ALIGN16(size);
    D_802212A2 = arg0->unk5;

    switch (D_802212A2)
    {
    case 1:
        D_802212A3 = 0;
        break;
    case 2:
        D_802212A3 = 1;
        break;
    case 4:
        D_802212A3 = 2;
        break;
    case 8:
        D_802212A3 = 3;
        break;
    case 16:
        D_802212A3 = 4;
        break;
    default:
        D_802212A3 = 0;
    }

    D_802212A2 = arg0->unk5;
    D_802212A0 = arg0->unkA;
    D_80226D78 = D_80226D74 - 0x10;
    temp8 = D_80226D74 / 160 + 1;
    D_80226D7E = temp8;
#ifdef VERSION_JP
    D_80226D7C = temp8 * 3600 / D_80333EE4;
#else
    D_80226D7C = (u32) (temp8 * 2880000.0f / D_80333EE4 / 16.713f);
#endif
    D_80226D6C = D_80226D70 * 20 * temp8 + 320;
    sum1 = arg0->unk10 + arg0->unkC;
    sum2 = arg0->unk18 + arg0->unk14;
    sum3 = sum1 + sum2;
    // (the address of D_802212A8.unk8 is lui'd too far up)
    sum4 = D_802212A8.unk8 - sum3 - 0x100;
    D_80221898.unk0 = sum4;
    D_80221898.unkC = sum3;
    func_80316164(&D_80221898);
    D_802218A8.first = sum1;
    D_802218A8.second = sum2;
    func_803161E0(&D_802218A8);
    D_802218B0.unk0 = arg0->unkC;
    D_802218B0.unk4 = arg0->unk10;
    D_802218B0.unk8 = 0;
    func_8031625C(&D_802218B0);
    D_802218C0.unk0 = arg0->unk14;
    D_802218C0.unk4 = arg0->unk18;
    D_802218C0.unk8 = 0;
    func_80316318(&D_802218C0);
    func_80315E60();

    for (j = 0; j < 2; j++)
    {
        D_80226D90[j] = soundAlloc(&D_802212C8, D_80226D6C * 8);
    }

    D_80222A10 = soundAlloc(&D_802212C8,
            D_80226D70 * sizeof(struct Struct_func_80318870));
    func_80319D40();
    func_80319248();

    if (sp2C == 0)
    {
        D_802211B0.unk1 = 0;
    }
    else
    {
        D_802211B0.unk1 = 8;
        D_802211B0.unk14.unk00 = soundAlloc(&D_802212C8, sp2C * 2);
        D_802211B0.unk14.unk04 = soundAlloc(&D_802212C8, sp2C * 2);
        D_802211B0.unk8 = 0;
        D_802211B0.unkC = 0;
        D_802211B0.unk3 = 0;
        D_802211B0.unk10 = sp2C;
        D_802211B0.unk4 = arg0->unk8;
        D_802211B0.unk2 = 2;
        if (D_802212A2 != 1)
        {
            D_802211B0.unk0 = 1;
            D_802211B0.unk6 = 0x8000 / D_802212A2;
            D_802211B0.unk1C = soundAlloc(&D_802212C8, 32);
            D_802211B0.unk20 = soundAlloc(&D_802212C8, 32);
            D_802211B0.unk24 = soundAlloc(&D_802212C8, 32);
            D_802211B0.unk28 = soundAlloc(&D_802212C8, 32);
            for (i = 0; i < D_80226D7E; i++)
            {
                mem = soundAlloc(&D_802212C8, 0x280);
                D_802211B0.unk2C[0][i].unk4 = mem;
                D_802211B0.unk2C[0][i].unk8 = mem + 0xA0;
                mem = soundAlloc(&D_802212C8, 0x280);
                D_802211B0.unk2C[1][i].unk4 = mem;
                D_802211B0.unk2C[1][i].unk8 = mem + 0xA0;
            }
        }
    }

    func_8031758C(D_80226D70);
    osWritebackDCacheAll();
    if (D_80333EF4 != 0)
    {
        D_80333EF4 = 0x76557364;
    }
}

#elif defined(VERSION_JP)
GLOBAL_ASM(
.late_rodata
glabel jtbl_80337BE0
    .word L80316BD0
    .word L80316BDC
    .word L80316C1C
    .word L80316BEC
    .word L80316C1C
    .word L80316C1C
    .word L80316C1C
    .word L80316BFC
    .word L80316C1C
    .word L80316C1C
    .word L80316C1C
    .word L80316C1C
    .word L80316C1C
    .word L80316C1C
    .word L80316C1C
    .word L80316C0C

.text
glabel func_80316928
/* 0D1928 80316928 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0D192C 8031692C 3C0E8033 */  lui   $t6, %hi(D_80333EF4) # $t6, 0x8033
/* 0D1930 80316930 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0D1934 80316934 AFB30020 */  sw    $s3, 0x20($sp)
/* 0D1938 80316938 AFB2001C */  sw    $s2, 0x1c($sp)
/* 0D193C 8031693C AFB10018 */  sw    $s1, 0x18($sp)
/* 0D1940 80316940 AFB00014 */  sw    $s0, 0x14($sp)
/* 0D1944 80316944 AFA40038 */  sw    $a0, 0x38($sp)
/* 0D1948 80316948 25CE3EF4 */  addiu $t6, %lo(D_80333EF4) # addiu $t6, $t6, 0x3ef4
/* 0D194C 8031694C 8DCF0000 */  lw    $t7, ($t6)
/* 0D1950 80316950 51E0007A */  beql  $t7, $zero, .L80316B3C
/* 0D1954 80316954 8FB80038 */   lw    $t8, 0x38($sp)
/* 0D1958 80316958 0C0C5A33 */  jal   func_803168CC
/* 0D195C 8031695C 00000000 */   nop   
/* 0D1960 80316960 3C038022 */  lui   $v1, %hi(D_80226D70) # $v1, 0x8022
/* 0D1964 80316964 8C636D70 */  lw    $v1, %lo(D_80226D70)($v1)
/* 0D1968 80316968 00008025 */  move  $s0, $zero
/* 0D196C 8031696C 00002025 */  move  $a0, $zero
/* 0D1970 80316970 18600027 */  blez  $v1, .L80316A10
/* 0D1974 80316974 00008825 */   move  $s1, $zero
/* 0D1978 80316978 3C068022 */  lui   $a2, %hi(D_80226D7E) # $a2, 0x8022
/* 0D197C 8031697C 3C058022 */  lui   $a1, %hi(D_80222A10) # $a1, 0x8022
/* 0D1980 80316980 24A52A10 */  addiu $a1, %lo(D_80222A10) # addiu $a1, $a1, 0x2a10
/* 0D1984 80316984 24C66D7E */  addiu $a2, %lo(D_80226D7E) # addiu $a2, $a2, 0x6d7e
.L80316988:
/* 0D1988 80316988 8CB80000 */  lw    $t8, ($a1)
/* 0D198C 8031698C 26100001 */  addiu $s0, $s0, 1
/* 0D1990 80316990 03041021 */  addu  $v0, $t8, $a0
/* 0D1994 80316994 8C590000 */  lw    $t9, ($v0)
/* 0D1998 80316998 001967C2 */  srl   $t4, $t9, 0x1f
/* 0D199C 8031699C 5180001A */  beql  $t4, $zero, .L80316A08
/* 0D19A0 803169A0 0203082A */   slt   $at, $s0, $v1
/* 0D19A4 803169A4 904D0055 */  lbu   $t5, 0x55($v0)
/* 0D19A8 803169A8 51A00017 */  beql  $t5, $zero, .L80316A08
/* 0D19AC 803169AC 0203082A */   slt   $at, $s0, $v1
/* 0D19B0 803169B0 80CE0000 */  lb    $t6, ($a2)
/* 0D19B4 803169B4 340F8000 */  li    $t7, 32768
/* 0D19B8 803169B8 3C038022 */  lui   $v1, %hi(D_80226D70) # $v1, 0x8022
/* 0D19BC 803169BC 01EE001A */  div   $zero, $t7, $t6
/* 0D19C0 803169C0 0000C012 */  mflo  $t8
/* 0D19C4 803169C4 A4580062 */  sh    $t8, 0x62($v0)
/* 0D19C8 803169C8 8CB90000 */  lw    $t9, ($a1)
/* 0D19CC 803169CC 15C00002 */  bnez  $t6, .L803169D8
/* 0D19D0 803169D0 00000000 */   nop   
/* 0D19D4 803169D4 0007000D */  break 7
.L803169D8:
/* 0D19D8 803169D8 2401FFFF */  li    $at, -1
/* 0D19DC 803169DC 15C10004 */  bne   $t6, $at, .L803169F0
/* 0D19E0 803169E0 3C018000 */   lui   $at, 0x8000
/* 0D19E4 803169E4 15E10002 */  bne   $t7, $at, .L803169F0
/* 0D19E8 803169E8 00000000 */   nop   
/* 0D19EC 803169EC 0006000D */  break 6
.L803169F0:
/* 0D19F0 803169F0 03241021 */  addu  $v0, $t9, $a0
/* 0D19F4 803169F4 904C0054 */  lbu   $t4, 0x54($v0)
/* 0D19F8 803169F8 358D0010 */  ori   $t5, $t4, 0x10
/* 0D19FC 803169FC A04D0054 */  sb    $t5, 0x54($v0)
/* 0D1A00 80316A00 8C636D70 */  lw    $v1, %lo(D_80226D70)($v1)
/* 0D1A04 80316A04 0203082A */  slt   $at, $s0, $v1
.L80316A08:
/* 0D1A08 80316A08 1420FFDF */  bnez  $at, .L80316988
/* 0D1A0C 80316A0C 248400C0 */   addiu $a0, $a0, 0xc0
.L80316A10:
/* 0D1A10 80316A10 0C0C5A3D */  jal   func_803168F4
/* 0D1A14 80316A14 24040001 */   li    $a0, 1
/* 0D1A18 80316A18 26310001 */  addiu $s1, $s1, 1
/* 0D1A1C 80316A1C 2A2100F1 */  slti  $at, $s1, 0xf1
/* 0D1A20 80316A20 10200013 */  beqz  $at, .L80316A70
/* 0D1A24 80316A24 3C038022 */   lui   $v1, %hi(D_80226D70) # $v1, 0x8022
/* 0D1A28 80316A28 8C636D70 */  lw    $v1, %lo(D_80226D70)($v1)
/* 0D1A2C 80316A2C 00008025 */  move  $s0, $zero
/* 0D1A30 80316A30 3C028022 */  lui   $v0, %hi(D_80222A10) # $v0, 0x8022
/* 0D1A34 80316A34 1860000A */  blez  $v1, .L80316A60
/* 0D1A38 80316A38 00000000 */   nop   
/* 0D1A3C 80316A3C 8C422A10 */  lw    $v0, %lo(D_80222A10)($v0)
.L80316A40:
/* 0D1A40 80316A40 8C4F0000 */  lw    $t7, ($v0)
/* 0D1A44 80316A44 000F77C2 */  srl   $t6, $t7, 0x1f
/* 0D1A48 80316A48 15C00005 */  bnez  $t6, .L80316A60
/* 0D1A4C 80316A4C 00000000 */   nop   
/* 0D1A50 80316A50 26100001 */  addiu $s0, $s0, 1
/* 0D1A54 80316A54 0203082A */  slt   $at, $s0, $v1
/* 0D1A58 80316A58 1420FFF9 */  bnez  $at, .L80316A40
/* 0D1A5C 80316A5C 244200C0 */   addiu $v0, $v0, 0xc0
.L80316A60:
/* 0D1A60 80316A60 12030003 */  beq   $s0, $v1, .L80316A70
/* 0D1A64 80316A64 00000000 */   nop   
/* 0D1A68 80316A68 1000FFE9 */  b     .L80316A10
/* 0D1A6C 80316A6C 00000000 */   nop   
.L80316A70:
/* 0D1A70 80316A70 0C0C5A33 */  jal   func_803168CC
/* 0D1A74 80316A74 00000000 */   nop   
/* 0D1A78 80316A78 0C0C5A3D */  jal   func_803168F4
/* 0D1A7C 80316A7C 24040003 */   li    $a0, 3
/* 0D1A80 80316A80 3C181971 */  lui   $t8, (0x19710515 >> 16) # lui $t8, 0x1971
/* 0D1A84 80316A84 3C198033 */  lui   $t9, %hi(D_80333EF4) # $t9, 0x8033
/* 0D1A88 80316A88 27393EF4 */  addiu $t9, %lo(D_80333EF4) # addiu $t9, $t9, 0x3ef4
/* 0D1A8C 80316A8C 37180515 */  ori   $t8, (0x19710515 & 0xFFFF) # ori $t8, $t8, 0x515
/* 0D1A90 80316A90 AF380000 */  sw    $t8, ($t9)
/* 0D1A94 80316A94 0C0C5A3D */  jal   func_803168F4
/* 0D1A98 80316A98 24040003 */   li    $a0, 3
/* 0D1A9C 80316A9C 3C138022 */  lui   $s3, %hi(D_80226D84) # $s3, 0x8022
/* 0D1AA0 80316AA0 26736D84 */  addiu $s3, %lo(D_80226D84) # addiu $s3, $s3, 0x6d84
/* 0D1AA4 80316AA4 8E710000 */  lw    $s1, ($s3)
/* 0D1AA8 80316AA8 1A200014 */  blez  $s1, .L80316AFC
/* 0D1AAC 80316AAC 00000000 */   nop   
/* 0D1AB0 80316AB0 3C128022 */  lui   $s2, %hi(D_80225EE8) # $s2, 0x8022
/* 0D1AB4 80316AB4 26525EE8 */  addiu $s2, %lo(D_80225EE8) # addiu $s2, $s2, 0x5ee8
/* 0D1AB8 80316AB8 8E6C0000 */  lw    $t4, ($s3)
.L80316ABC:
/* 0D1ABC 80316ABC 00008025 */  move  $s0, $zero
/* 0D1AC0 80316AC0 1980000C */  blez  $t4, .L80316AF4
/* 0D1AC4 80316AC4 02402025 */   move  $a0, $s2
.L80316AC8:
/* 0D1AC8 80316AC8 00002825 */  move  $a1, $zero
/* 0D1ACC 80316ACC 0C0C8634 */  jal   osRecvMesg
/* 0D1AD0 80316AD0 00003025 */   move  $a2, $zero
/* 0D1AD4 80316AD4 54400003 */  bnezl $v0, .L80316AE4
/* 0D1AD8 80316AD8 8E6D0000 */   lw    $t5, ($s3)
/* 0D1ADC 80316ADC 2631FFFF */  addiu $s1, $s1, -1
/* 0D1AE0 80316AE0 8E6D0000 */  lw    $t5, ($s3)
.L80316AE4:
/* 0D1AE4 80316AE4 26100001 */  addiu $s0, $s0, 1
/* 0D1AE8 80316AE8 020D082A */  slt   $at, $s0, $t5
/* 0D1AEC 80316AEC 5420FFF6 */  bnezl $at, .L80316AC8
/* 0D1AF0 80316AF0 02402025 */   move  $a0, $s2
.L80316AF4:
/* 0D1AF4 80316AF4 5E20FFF1 */  bgtzl $s1, .L80316ABC
/* 0D1AF8 80316AF8 8E6C0000 */   lw    $t4, ($s3)
.L80316AFC:
/* 0D1AFC 80316AFC 3C038022 */  lui   $v1, %hi(D_80226E40) # $v1, 0x8022
/* 0D1B00 80316B00 3C068022 */  lui   $a2, %hi(D_80226E40 + 0xC) # $a2, 0x8022
/* 0D1B04 80316B04 AE600000 */  sw    $zero, ($s3)
/* 0D1B08 80316B08 24C66E4C */  addiu $a2, %lo(D_80226E40 + 0xC) # addiu $a2, $a2, 0x6e4c
/* 0D1B0C 80316B0C 24636E40 */  addiu $v1, %lo(D_80226E40) # addiu $v1, $v1, 0x6e40
/* 0D1B10 80316B10 24040A00 */  li    $a0, 2560
/* 0D1B14 80316B14 00001025 */  move  $v0, $zero
.L80316B18:
/* 0D1B18 80316B18 8C6F0000 */  lw    $t7, ($v1)
/* 0D1B1C 80316B1C 01E27021 */  addu  $t6, $t7, $v0
/* 0D1B20 80316B20 24420002 */  addiu $v0, $v0, 2
/* 0D1B24 80316B24 1444FFFC */  bne   $v0, $a0, .L80316B18
/* 0D1B28 80316B28 A5C00000 */   sh    $zero, ($t6)
/* 0D1B2C 80316B2C 24630004 */  addiu $v1, $v1, 4
/* 0D1B30 80316B30 5466FFF9 */  bnel  $v1, $a2, .L80316B18
/* 0D1B34 80316B34 00001025 */   move  $v0, $zero
/* 0D1B38 80316B38 8FB80038 */  lw    $t8, 0x38($sp)
.L80316B3C:
/* 0D1B3C 80316B3C 3C018022 */  lui   $at, %hi(D_80226B38) # $at, 0x8022
/* 0D1B40 80316B40 AC206B38 */  sw    $zero, %lo(D_80226B38)($at)
/* 0D1B44 80316B44 97190006 */  lhu   $t9, 6($t8)
/* 0D1B48 80316B48 AFB9002C */  sw    $t9, 0x2c($sp)
/* 0D1B4C 80316B4C 0C0C9290 */  jal   osAiSetFrequency
/* 0D1B50 80316B50 8F040000 */   lw    $a0, ($t8)
/* 0D1B54 80316B54 2401003C */  li    $at, 60
/* 0D1B58 80316B58 0041001A */  div   $zero, $v0, $at
/* 0D1B5C 80316B5C 8FA80038 */  lw    $t0, 0x38($sp)
/* 0D1B60 80316B60 3C038022 */  lui   $v1, %hi(D_80226D64) # $v1, 0x8022
/* 0D1B64 80316B64 24636D64 */  addiu $v1, %lo(D_80226D64) # addiu $v1, $v1, 0x6d64
/* 0D1B68 80316B68 AC620000 */  sw    $v0, ($v1)
/* 0D1B6C 80316B6C 910C0004 */  lbu   $t4, 4($t0)
/* 0D1B70 80316B70 00007812 */  mflo  $t7
/* 0D1B74 80316B74 3C0A8022 */  lui   $t2, %hi(D_80226D74) # $t2, 0x8022
/* 0D1B78 80316B78 3C0B8022 */  lui   $t3, %hi(D_80226D70) # $t3, 0x8022
/* 0D1B7C 80316B7C 25EE000F */  addiu $t6, $t7, 0xf
/* 0D1B80 80316B80 2401FFF0 */  li    $at, -16
/* 0D1B84 80316B84 256B6D70 */  addiu $t3, %lo(D_80226D70) # addiu $t3, $t3, 0x6d70
/* 0D1B88 80316B88 254A6D74 */  addiu $t2, %lo(D_80226D74) # addiu $t2, $t2, 0x6d74
/* 0D1B8C 80316B8C 01C1C824 */  and   $t9, $t6, $at
/* 0D1B90 80316B90 AD590000 */  sw    $t9, ($t2)
/* 0D1B94 80316B94 AD6C0000 */  sw    $t4, ($t3)
/* 0D1B98 80316B98 91180005 */  lbu   $t8, 5($t0)
/* 0D1B9C 80316B9C 3C098022 */  lui   $t1, %hi(D_802212A2) # $t1, 0x8022
/* 0D1BA0 80316BA0 252912A2 */  addiu $t1, %lo(D_802212A2) # addiu $t1, $t1, 0x12a2
/* 0D1BA4 80316BA4 A1380000 */  sb    $t8, ($t1)
/* 0D1BA8 80316BA8 812C0000 */  lb    $t4, ($t1)
/* 0D1BAC 80316BAC 258DFFFF */  addiu $t5, $t4, -1
/* 0D1BB0 80316BB0 2DA10010 */  sltiu $at, $t5, 0x10
/* 0D1BB4 80316BB4 10200019 */  beqz  $at, .L80316C1C
/* 0D1BB8 80316BB8 000D6880 */   sll   $t5, $t5, 2
/* 0D1BBC 80316BBC 3C018033 */  lui   $at, %hi(jtbl_80337BE0)
/* 0D1BC0 80316BC0 002D0821 */  addu  $at, $at, $t5
/* 0D1BC4 80316BC4 8C2D7BE0 */  lw    $t5, %lo(jtbl_80337BE0)($at)
/* 0D1BC8 80316BC8 01A00008 */  jr    $t5
/* 0D1BCC 80316BCC 00000000 */   nop   
glabel L80316BD0
/* 0D1BD0 80316BD0 3C018022 */  lui   $at, %hi(D_802212A3) # $at, 0x8022
/* 0D1BD4 80316BD4 10000013 */  b     .L80316C24
/* 0D1BD8 80316BD8 A02012A3 */   sb    $zero, %lo(D_802212A3)($at)
glabel L80316BDC
/* 0D1BDC 80316BDC 240F0001 */  li    $t7, 1
/* 0D1BE0 80316BE0 3C018022 */  lui   $at, %hi(D_802212A3) # $at, 0x8022
/* 0D1BE4 80316BE4 1000000F */  b     .L80316C24
/* 0D1BE8 80316BE8 A02F12A3 */   sb    $t7, %lo(D_802212A3)($at)
glabel L80316BEC
/* 0D1BEC 80316BEC 240E0002 */  li    $t6, 2
/* 0D1BF0 80316BF0 3C018022 */  lui   $at, %hi(D_802212A3) # $at, 0x8022
/* 0D1BF4 80316BF4 1000000B */  b     .L80316C24
/* 0D1BF8 80316BF8 A02E12A3 */   sb    $t6, %lo(D_802212A3)($at)
glabel L80316BFC
/* 0D1BFC 80316BFC 24190003 */  li    $t9, 3
/* 0D1C00 80316C00 3C018022 */  lui   $at, %hi(D_802212A3) # $at, 0x8022
/* 0D1C04 80316C04 10000007 */  b     .L80316C24
/* 0D1C08 80316C08 A03912A3 */   sb    $t9, %lo(D_802212A3)($at)
glabel L80316C0C
/* 0D1C0C 80316C0C 24180004 */  li    $t8, 4
/* 0D1C10 80316C10 3C018022 */  lui   $at, %hi(D_802212A3) # $at, 0x8022
/* 0D1C14 80316C14 10000003 */  b     .L80316C24
/* 0D1C18 80316C18 A03812A3 */   sb    $t8, %lo(D_802212A3)($at)
.L80316C1C:
glabel L80316C1C
/* 0D1C1C 80316C1C 3C018022 */  lui   $at, %hi(D_802212A3) # $at, 0x8022
/* 0D1C20 80316C20 A02012A3 */  sb    $zero, %lo(D_802212A3)($at)
.L80316C24:
/* 0D1C24 80316C24 910C0005 */  lbu   $t4, 5($t0)
/* 0D1C28 80316C28 3C018022 */  lui   $at, %hi(D_802212A0) # $at, 0x8022
/* 0D1C2C 80316C2C 3C188033 */  lui   $t8, %hi(D_80333EE4) # $t8, 0x8033
/* 0D1C30 80316C30 A12C0000 */  sb    $t4, ($t1)
/* 0D1C34 80316C34 950D000A */  lhu   $t5, 0xa($t0)
/* 0D1C38 80316C38 87183EE4 */  lh    $t8, %lo(D_80333EE4)($t8)
/* 0D1C3C 80316C3C 3C138022 */  lui   $s3, %hi(D_80226D6C) # $s3, 0x8022
/* 0D1C40 80316C40 A42D12A0 */  sh    $t5, %lo(D_802212A0)($at)
/* 0D1C44 80316C44 8D420000 */  lw    $v0, ($t2)
/* 0D1C48 80316C48 3C018022 */  lui   $at, %hi(D_80226D78) # $at, 0x8022
/* 0D1C4C 80316C4C 26736D6C */  addiu $s3, %lo(D_80226D6C) # addiu $s3, $s3, 0x6d6c
/* 0D1C50 80316C50 244FFFF0 */  addiu $t7, $v0, -0x10
/* 0D1C54 80316C54 AC2F6D78 */  sw    $t7, %lo(D_80226D78)($at)
/* 0D1C58 80316C58 240100A0 */  li    $at, 160
/* 0D1C5C 80316C5C 0041001A */  div   $zero, $v0, $at
/* 0D1C60 80316C60 00001812 */  mflo  $v1
/* 0D1C64 80316C64 24630001 */  addiu $v1, $v1, 1
/* 0D1C68 80316C68 00032E00 */  sll   $a1, $v1, 0x18
/* 0D1C6C 80316C6C 00057603 */  sra   $t6, $a1, 0x18
/* 0D1C70 80316C70 000EC8C0 */  sll   $t9, $t6, 3
/* 0D1C74 80316C74 032EC823 */  subu  $t9, $t9, $t6
/* 0D1C78 80316C78 0019C940 */  sll   $t9, $t9, 5
/* 0D1C7C 80316C7C 032EC821 */  addu  $t9, $t9, $t6
/* 0D1C80 80316C80 0019C900 */  sll   $t9, $t9, 4
/* 0D1C84 80316C84 0338001A */  div   $zero, $t9, $t8
/* 0D1C88 80316C88 3C018022 */  lui   $at, %hi(D_80226D7E) # $at, 0x8022
/* 0D1C8C 80316C8C A0236D7E */  sb    $v1, %lo(D_80226D7E)($at)
/* 0D1C90 80316C90 00006012 */  mflo  $t4
/* 0D1C94 80316C94 01C02825 */  move  $a1, $t6
/* 0D1C98 80316C98 3C048022 */  lui   $a0, %hi(D_80221898) # $a0, 0x8022
/* 0D1C9C 80316C9C 24841898 */  addiu $a0, %lo(D_80221898) # addiu $a0, $a0, 0x1898
/* 0D1CA0 80316CA0 17000002 */  bnez  $t8, .L80316CAC
/* 0D1CA4 80316CA4 00000000 */   nop   
/* 0D1CA8 80316CA8 0007000D */  break 7
.L80316CAC:
/* 0D1CAC 80316CAC 2401FFFF */  li    $at, -1
/* 0D1CB0 80316CB0 17010004 */  bne   $t8, $at, .L80316CC4
/* 0D1CB4 80316CB4 3C018000 */   lui   $at, 0x8000
/* 0D1CB8 80316CB8 17210002 */  bne   $t9, $at, .L80316CC4
/* 0D1CBC 80316CBC 00000000 */   nop   
/* 0D1CC0 80316CC0 0006000D */  break 6
.L80316CC4:
/* 0D1CC4 80316CC4 3C018022 */  lui   $at, %hi(D_80226D7C) # $at, 0x8022
/* 0D1CC8 80316CC8 A42C6D7C */  sh    $t4, %lo(D_80226D7C)($at)
/* 0D1CCC 80316CCC 8D6D0000 */  lw    $t5, ($t3)
/* 0D1CD0 80316CD0 000D7880 */  sll   $t7, $t5, 2
/* 0D1CD4 80316CD4 01ED7821 */  addu  $t7, $t7, $t5
/* 0D1CD8 80316CD8 000F7880 */  sll   $t7, $t7, 2
/* 0D1CDC 80316CDC 01E50019 */  multu $t7, $a1
/* 0D1CE0 80316CE0 00007012 */  mflo  $t6
/* 0D1CE4 80316CE4 25D90140 */  addiu $t9, $t6, 0x140
/* 0D1CE8 80316CE8 AE790000 */  sw    $t9, ($s3)
/* 0D1CEC 80316CEC 8D0C000C */  lw    $t4, 0xc($t0)
/* 0D1CF0 80316CF0 8D180010 */  lw    $t8, 0x10($t0)
/* 0D1CF4 80316CF4 8D0F0014 */  lw    $t7, 0x14($t0)
/* 0D1CF8 80316CF8 8D0D0018 */  lw    $t5, 0x18($t0)
/* 0D1CFC 80316CFC 3C0E8022 */  lui   $t6, %hi(D_802212A8 + 8) # $t6, 0x8022
/* 0D1D00 80316D00 8DCE12B0 */  lw    $t6, %lo(D_802212A8 + 8)($t6)
/* 0D1D04 80316D04 030C8021 */  addu  $s0, $t8, $t4
/* 0D1D08 80316D08 01AF8821 */  addu  $s1, $t5, $t7
/* 0D1D0C 80316D0C 02113021 */  addu  $a2, $s0, $s1
/* 0D1D10 80316D10 01C63823 */  subu  $a3, $t6, $a2
/* 0D1D14 80316D14 24E7FF00 */  addiu $a3, $a3, -0x100
/* 0D1D18 80316D18 AC870000 */  sw    $a3, ($a0)
/* 0D1D1C 80316D1C 0C0C5859 */  jal   func_80316164
/* 0D1D20 80316D20 AC86000C */   sw    $a2, 0xc($a0)
/* 0D1D24 80316D24 3C048022 */  lui   $a0, %hi(D_802218A8) # $a0, 0x8022
/* 0D1D28 80316D28 248418A8 */  addiu $a0, %lo(D_802218A8) # addiu $a0, $a0, 0x18a8
/* 0D1D2C 80316D2C AC900000 */  sw    $s0, ($a0)
/* 0D1D30 80316D30 0C0C5878 */  jal   func_803161E0
/* 0D1D34 80316D34 AC910004 */   sw    $s1, 4($a0)
/* 0D1D38 80316D38 8FA20038 */  lw    $v0, 0x38($sp)
/* 0D1D3C 80316D3C 3C048022 */  lui   $a0, %hi(D_802218B0) # $a0, 0x8022
/* 0D1D40 80316D40 248418B0 */  addiu $a0, %lo(D_802218B0) # addiu $a0, $a0, 0x18b0
/* 0D1D44 80316D44 8C59000C */  lw    $t9, 0xc($v0)
/* 0D1D48 80316D48 AC990000 */  sw    $t9, ($a0)
/* 0D1D4C 80316D4C 8C580010 */  lw    $t8, 0x10($v0)
/* 0D1D50 80316D50 AC800008 */  sw    $zero, 8($a0)
/* 0D1D54 80316D54 0C0C5897 */  jal   func_8031625C
/* 0D1D58 80316D58 AC980004 */   sw    $t8, 4($a0)
/* 0D1D5C 80316D5C 8FAC0038 */  lw    $t4, 0x38($sp)
/* 0D1D60 80316D60 8FAF0038 */  lw    $t7, 0x38($sp)
/* 0D1D64 80316D64 3C048022 */  lui   $a0, %hi(D_802218C0) # $a0, 0x8022
/* 0D1D68 80316D68 8D8D0014 */  lw    $t5, 0x14($t4)
/* 0D1D6C 80316D6C 248418C0 */  addiu $a0, %lo(D_802218C0) # addiu $a0, $a0, 0x18c0
/* 0D1D70 80316D70 AC8D0000 */  sw    $t5, ($a0)
/* 0D1D74 80316D74 8DEE0018 */  lw    $t6, 0x18($t7)
/* 0D1D78 80316D78 AC800008 */  sw    $zero, 8($a0)
/* 0D1D7C 80316D7C 0C0C58C6 */  jal   func_80316318
/* 0D1D80 80316D80 AC8E0004 */   sw    $t6, 4($a0)
/* 0D1D84 80316D84 0C0C5798 */  jal   func_80315E60
/* 0D1D88 80316D88 00000000 */   nop   
/* 0D1D8C 80316D8C 3C108022 */  lui   $s0, %hi(D_80226D90) # $s0, 0x8022
/* 0D1D90 80316D90 3C128022 */  lui   $s2, %hi(D_802212C8) # $s2, 0x8022
/* 0D1D94 80316D94 3C118022 */  lui   $s1, %hi(D_80226D90 + 8) # $s1, 0x8022
/* 0D1D98 80316D98 26316D98 */  addiu $s1, %lo(D_80226D90 + 8) # addiu $s1, $s1, 0x6d98
/* 0D1D9C 80316D9C 265212C8 */  addiu $s2, %lo(D_802212C8) # addiu $s2, $s2, 0x12c8
/* 0D1DA0 80316DA0 26106D90 */  addiu $s0, %lo(D_80226D90) # addiu $s0, $s0, 0x6d90
.L80316DA4:
/* 0D1DA4 80316DA4 8E650000 */  lw    $a1, ($s3)
/* 0D1DA8 80316DA8 02402025 */  move  $a0, $s2
/* 0D1DAC 80316DAC 0005C8C0 */  sll   $t9, $a1, 3
/* 0D1DB0 80316DB0 0C0C5808 */  jal   soundAlloc
/* 0D1DB4 80316DB4 03202825 */   move  $a1, $t9
/* 0D1DB8 80316DB8 26100004 */  addiu $s0, $s0, 4
/* 0D1DBC 80316DBC 1611FFF9 */  bne   $s0, $s1, .L80316DA4
/* 0D1DC0 80316DC0 AE02FFFC */   sw    $v0, -4($s0)
/* 0D1DC4 80316DC4 3C058022 */  lui   $a1, %hi(D_80226D70) # $a1, 0x8022
/* 0D1DC8 80316DC8 8CA56D70 */  lw    $a1, %lo(D_80226D70)($a1)
/* 0D1DCC 80316DCC 02402025 */  move  $a0, $s2
/* 0D1DD0 80316DD0 0005C080 */  sll   $t8, $a1, 2
/* 0D1DD4 80316DD4 0305C023 */  subu  $t8, $t8, $a1
/* 0D1DD8 80316DD8 0C0C5808 */  jal   soundAlloc
/* 0D1DDC 80316DDC 00182980 */   sll   $a1, $t8, 6
/* 0D1DE0 80316DE0 3C018022 */  lui   $at, %hi(D_80222A10) # $at, 0x8022
/* 0D1DE4 80316DE4 0C0C6750 */  jal   func_80319D40
/* 0D1DE8 80316DE8 AC222A10 */   sw    $v0, %lo(D_80222A10)($at)
/* 0D1DEC 80316DEC 0C0C6492 */  jal   func_80319248
/* 0D1DF0 80316DF0 00000000 */   nop   
/* 0D1DF4 80316DF4 8FA2002C */  lw    $v0, 0x2c($sp)
/* 0D1DF8 80316DF8 3C118022 */  lui   $s1, %hi(D_802211B0) # $s1, 0x8022
/* 0D1DFC 80316DFC 263111B0 */  addiu $s1, %lo(D_802211B0) # addiu $s1, $s1, 0x11b0
/* 0D1E00 80316E00 14400005 */  bnez  $v0, .L80316E18
/* 0D1E04 80316E04 240C0008 */   li    $t4, 8
/* 0D1E08 80316E08 3C118022 */  lui   $s1, %hi(D_802211B0) # $s1, 0x8022
/* 0D1E0C 80316E0C 263111B0 */  addiu $s1, %lo(D_802211B0) # addiu $s1, $s1, 0x11b0
/* 0D1E10 80316E10 10000051 */  b     .L80316F58
/* 0D1E14 80316E14 A2200001 */   sb    $zero, 1($s1)
.L80316E18:
/* 0D1E18 80316E18 00028040 */  sll   $s0, $v0, 1
/* 0D1E1C 80316E1C A22C0001 */  sb    $t4, 1($s1)
/* 0D1E20 80316E20 02002825 */  move  $a1, $s0
/* 0D1E24 80316E24 0C0C5808 */  jal   soundAlloc
/* 0D1E28 80316E28 02402025 */   move  $a0, $s2
/* 0D1E2C 80316E2C AE220014 */  sw    $v0, 0x14($s1)
/* 0D1E30 80316E30 02402025 */  move  $a0, $s2
/* 0D1E34 80316E34 0C0C5808 */  jal   soundAlloc
/* 0D1E38 80316E38 02002825 */   move  $a1, $s0
/* 0D1E3C 80316E3C 8FAD002C */  lw    $t5, 0x2c($sp)
/* 0D1E40 80316E40 8FAF0038 */  lw    $t7, 0x38($sp)
/* 0D1E44 80316E44 AE220018 */  sw    $v0, 0x18($s1)
/* 0D1E48 80316E48 AE200008 */  sw    $zero, 8($s1)
/* 0D1E4C 80316E4C AE20000C */  sw    $zero, 0xc($s1)
/* 0D1E50 80316E50 A2200003 */  sb    $zero, 3($s1)
/* 0D1E54 80316E54 AE2D0010 */  sw    $t5, 0x10($s1)
/* 0D1E58 80316E58 95EE0008 */  lhu   $t6, 8($t7)
/* 0D1E5C 80316E5C 24190002 */  li    $t9, 2
/* 0D1E60 80316E60 A2390002 */  sb    $t9, 2($s1)
/* 0D1E64 80316E64 3C038022 */  lui   $v1, %hi(D_802212A2) # $v1, 0x8022
/* 0D1E68 80316E68 A62E0004 */  sh    $t6, 4($s1)
/* 0D1E6C 80316E6C 806312A2 */  lb    $v1, %lo(D_802212A2)($v1)
/* 0D1E70 80316E70 24010001 */  li    $at, 1
/* 0D1E74 80316E74 24180001 */  li    $t8, 1
/* 0D1E78 80316E78 10610037 */  beq   $v1, $at, .L80316F58
/* 0D1E7C 80316E7C 340C8000 */   li    $t4, 32768
/* 0D1E80 80316E80 0183001A */  div   $zero, $t4, $v1
/* 0D1E84 80316E84 00006812 */  mflo  $t5
/* 0D1E88 80316E88 A2380000 */  sb    $t8, ($s1)
/* 0D1E8C 80316E8C 14600002 */  bnez  $v1, .L80316E98
/* 0D1E90 80316E90 00000000 */   nop   
/* 0D1E94 80316E94 0007000D */  break 7
.L80316E98:
/* 0D1E98 80316E98 2401FFFF */  li    $at, -1
/* 0D1E9C 80316E9C 14610004 */  bne   $v1, $at, .L80316EB0
/* 0D1EA0 80316EA0 3C018000 */   lui   $at, 0x8000
/* 0D1EA4 80316EA4 15810002 */  bne   $t4, $at, .L80316EB0
/* 0D1EA8 80316EA8 00000000 */   nop   
/* 0D1EAC 80316EAC 0006000D */  break 6
.L80316EB0:
/* 0D1EB0 80316EB0 A62D0006 */  sh    $t5, 6($s1)
/* 0D1EB4 80316EB4 02402025 */  move  $a0, $s2
/* 0D1EB8 80316EB8 24050020 */  li    $a1, 32
/* 0D1EBC 80316EBC 0C0C5808 */  jal   soundAlloc
/* 0D1EC0 80316EC0 00008025 */   move  $s0, $zero
/* 0D1EC4 80316EC4 AE22001C */  sw    $v0, 0x1c($s1)
/* 0D1EC8 80316EC8 02402025 */  move  $a0, $s2
/* 0D1ECC 80316ECC 0C0C5808 */  jal   soundAlloc
/* 0D1ED0 80316ED0 24050020 */   li    $a1, 32
/* 0D1ED4 80316ED4 AE220020 */  sw    $v0, 0x20($s1)
/* 0D1ED8 80316ED8 02402025 */  move  $a0, $s2
/* 0D1EDC 80316EDC 0C0C5808 */  jal   soundAlloc
/* 0D1EE0 80316EE0 24050020 */   li    $a1, 32
/* 0D1EE4 80316EE4 AE220024 */  sw    $v0, 0x24($s1)
/* 0D1EE8 80316EE8 02402025 */  move  $a0, $s2
/* 0D1EEC 80316EEC 0C0C5808 */  jal   soundAlloc
/* 0D1EF0 80316EF0 24050020 */   li    $a1, 32
/* 0D1EF4 80316EF4 AE220028 */  sw    $v0, 0x28($s1)
/* 0D1EF8 80316EF8 3C0F8022 */  lui   $t7, %hi(D_80226D7E) # $t7, 0x8022
/* 0D1EFC 80316EFC 81EF6D7E */  lb    $t7, %lo(D_80226D7E)($t7)
/* 0D1F00 80316F00 3C118022 */  lui   $s1, %hi(D_802211B0) # $s1, 0x8022
/* 0D1F04 80316F04 263111B0 */  addiu $s1, %lo(D_802211B0) # addiu $s1, $s1, 0x11b0
/* 0D1F08 80316F08 19E00013 */  blez  $t7, .L80316F58
/* 0D1F0C 80316F0C 02402025 */   move  $a0, $s2
.L80316F10:
/* 0D1F10 80316F10 0C0C5808 */  jal   soundAlloc
/* 0D1F14 80316F14 24050280 */   li    $a1, 640
/* 0D1F18 80316F18 244E0140 */  addiu $t6, $v0, 0x140
/* 0D1F1C 80316F1C AE220030 */  sw    $v0, 0x30($s1)
/* 0D1F20 80316F20 AE2E0034 */  sw    $t6, 0x34($s1)
/* 0D1F24 80316F24 02402025 */  move  $a0, $s2
/* 0D1F28 80316F28 0C0C5808 */  jal   soundAlloc
/* 0D1F2C 80316F2C 24050280 */   li    $a1, 640
/* 0D1F30 80316F30 24590140 */  addiu $t9, $v0, 0x140
/* 0D1F34 80316F34 3C188022 */  lui   $t8, %hi(D_80226D7E) # $t8, 0x8022
/* 0D1F38 80316F38 AE220080 */  sw    $v0, 0x80($s1)
/* 0D1F3C 80316F3C AE390084 */  sw    $t9, 0x84($s1)
/* 0D1F40 80316F40 83186D7E */  lb    $t8, %lo(D_80226D7E)($t8)
/* 0D1F44 80316F44 26100001 */  addiu $s0, $s0, 1
/* 0D1F48 80316F48 26310014 */  addiu $s1, $s1, 0x14
/* 0D1F4C 80316F4C 0218082A */  slt   $at, $s0, $t8
/* 0D1F50 80316F50 5420FFEF */  bnezl $at, .L80316F10
/* 0D1F54 80316F54 02402025 */   move  $a0, $s2
.L80316F58:
/* 0D1F58 80316F58 3C048022 */  lui   $a0, %hi(D_80226D70) # $a0, 0x8022
/* 0D1F5C 80316F5C 0C0C5D63 */  jal   func_8031758C
/* 0D1F60 80316F60 8C846D70 */   lw    $a0, %lo(D_80226D70)($a0)
/* 0D1F64 80316F64 0C0C8804 */  jal   osWritebackDCacheAll
/* 0D1F68 80316F68 00000000 */   nop   
/* 0D1F6C 80316F6C 3C0C8033 */  lui   $t4, %hi(D_80333EF4) # $t4, 0x8033
/* 0D1F70 80316F70 258C3EF4 */  addiu $t4, %lo(D_80333EF4) # addiu $t4, $t4, 0x3ef4
/* 0D1F74 80316F74 8D8D0000 */  lw    $t5, ($t4)
/* 0D1F78 80316F78 3C0F7655 */  lui   $t7, (0x76557364 >> 16) # lui $t7, 0x7655
/* 0D1F7C 80316F7C 35EF7364 */  ori   $t7, (0x76557364 & 0xFFFF) # ori $t7, $t7, 0x7364
/* 0D1F80 80316F80 51A00003 */  beql  $t5, $zero, .L80316F90
/* 0D1F84 80316F84 8FBF0024 */   lw    $ra, 0x24($sp)
/* 0D1F88 80316F88 AD8F0000 */  sw    $t7, ($t4)
/* 0D1F8C 80316F8C 8FBF0024 */  lw    $ra, 0x24($sp)
.L80316F90:
/* 0D1F90 80316F90 8FB00014 */  lw    $s0, 0x14($sp)
/* 0D1F94 80316F94 8FB10018 */  lw    $s1, 0x18($sp)
/* 0D1F98 80316F98 8FB2001C */  lw    $s2, 0x1c($sp)
/* 0D1F9C 80316F9C 8FB30020 */  lw    $s3, 0x20($sp)
/* 0D1FA0 80316FA0 03E00008 */  jr    $ra
/* 0D1FA4 80316FA4 27BD0038 */   addiu $sp, $sp, 0x38
)
#else
GLOBAL_ASM(
.late_rodata
glabel jtbl_80337BE0
    .word L80317BF0
    .word L80317BFC
    .word L80317C3C
    .word L80317C0C
    .word L80317C3C
    .word L80317C3C
    .word L80317C3C
    .word L80317C1C
    .word L80317C3C
    .word L80317C3C
    .word L80317C3C
    .word L80317C3C
    .word L80317C3C
    .word L80317C3C
    .word L80317C3C
    .word L80317C2C

glabel D_U_80338E00
    .word 0x4A2FC800 /* 2880000.0f */

glabel D_U_80338E04
    .word 0x4185B439 /* 16.713f */

.text
glabel func_80316928
/* 0D2948 80317948 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0D294C 8031794C 3C0E8033 */  lui   $t6, %hi(D_80333EF4) # $t6, 0x8033
/* 0D2950 80317950 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0D2954 80317954 AFB30020 */  sw    $s3, 0x20($sp)
/* 0D2958 80317958 AFB2001C */  sw    $s2, 0x1c($sp)
/* 0D295C 8031795C AFB10018 */  sw    $s1, 0x18($sp)
/* 0D2960 80317960 AFB00014 */  sw    $s0, 0x14($sp)
/* 0D2964 80317964 AFA40038 */  sw    $a0, 0x38($sp)
/* 0D2968 80317968 25CE5004 */  addiu $t6, %lo(D_80333EF4) # addiu $t6, $t6, 0x5004
/* 0D296C 8031796C 8DCF0000 */  lw    $t7, ($t6)
/* 0D2970 80317970 51E0007A */  beql  $t7, $zero, .L80317B5C
/* 0D2974 80317974 8FB80038 */   lw    $t8, 0x38($sp)
/* 0D2978 80317978 0C0C5E3B */  jal   func_803168CC
/* 0D297C 8031797C 00000000 */   nop   
/* 0D2980 80317980 3C038022 */  lui   $v1, %hi(D_80226D70) # $v1, 0x8022
/* 0D2984 80317984 8C636B70 */  lw    $v1, %lo(D_80226D70)($v1)
/* 0D2988 80317988 00008025 */  move  $s0, $zero
/* 0D298C 8031798C 00002025 */  move  $a0, $zero
/* 0D2990 80317990 18600027 */  blez  $v1, .L80317A30
/* 0D2994 80317994 00008825 */   move  $s1, $zero
/* 0D2998 80317998 3C068022 */  lui   $a2, %hi(D_80226D7E) # $a2, 0x8022
/* 0D299C 8031799C 3C058022 */  lui   $a1, %hi(D_80222A10) # $a1, 0x8022
/* 0D29A0 803179A0 24A52610 */  addiu $a1, %lo(D_80222A10) # addiu $a1, $a1, 0x2610
/* 0D29A4 803179A4 24C66B7E */  addiu $a2, %lo(D_80226D7E) # addiu $a2, $a2, 0x6b7e
.L803179A8:
/* 0D29A8 803179A8 8CB80000 */  lw    $t8, ($a1)
/* 0D29AC 803179AC 26100001 */  addiu $s0, $s0, 1
/* 0D29B0 803179B0 03041021 */  addu  $v0, $t8, $a0
/* 0D29B4 803179B4 8C590000 */  lw    $t9, ($v0)
/* 0D29B8 803179B8 001967C2 */  srl   $t4, $t9, 0x1f
/* 0D29BC 803179BC 5180001A */  beql  $t4, $zero, .L80317A28
/* 0D29C0 803179C0 0203082A */   slt   $at, $s0, $v1
/* 0D29C4 803179C4 904D0055 */  lbu   $t5, 0x55($v0)
/* 0D29C8 803179C8 51A00017 */  beql  $t5, $zero, .L80317A28
/* 0D29CC 803179CC 0203082A */   slt   $at, $s0, $v1
/* 0D29D0 803179D0 80CE0000 */  lb    $t6, ($a2)
/* 0D29D4 803179D4 340F8000 */  li    $t7, 32768
/* 0D29D8 803179D8 3C038022 */  lui   $v1, %hi(D_80226D70) # $v1, 0x8022
/* 0D29DC 803179DC 01EE001A */  div   $zero, $t7, $t6
/* 0D29E0 803179E0 0000C012 */  mflo  $t8
/* 0D29E4 803179E4 A4580062 */  sh    $t8, 0x62($v0)
/* 0D29E8 803179E8 8CB90000 */  lw    $t9, ($a1)
/* 0D29EC 803179EC 15C00002 */  bnez  $t6, .L803179F8
/* 0D29F0 803179F0 00000000 */   nop   
/* 0D29F4 803179F4 0007000D */  break 7
.L803179F8:
/* 0D29F8 803179F8 2401FFFF */  li    $at, -1
/* 0D29FC 803179FC 15C10004 */  bne   $t6, $at, .L80317A10
/* 0D2A00 80317A00 3C018000 */   lui   $at, 0x8000
/* 0D2A04 80317A04 15E10002 */  bne   $t7, $at, .L80317A10
/* 0D2A08 80317A08 00000000 */   nop   
/* 0D2A0C 80317A0C 0006000D */  break 6
.L80317A10:
/* 0D2A10 80317A10 03241021 */  addu  $v0, $t9, $a0
/* 0D2A14 80317A14 904C0054 */  lbu   $t4, 0x54($v0)
/* 0D2A18 80317A18 358D0010 */  ori   $t5, $t4, 0x10
/* 0D2A1C 80317A1C A04D0054 */  sb    $t5, 0x54($v0)
/* 0D2A20 80317A20 8C636B70 */  lw    $v1, %lo(D_80226D70)($v1)
/* 0D2A24 80317A24 0203082A */  slt   $at, $s0, $v1
.L80317A28:
/* 0D2A28 80317A28 1420FFDF */  bnez  $at, .L803179A8
/* 0D2A2C 80317A2C 248400C0 */   addiu $a0, $a0, 0xc0
.L80317A30:
/* 0D2A30 80317A30 0C0C5E45 */  jal   func_803168F4
/* 0D2A34 80317A34 24040001 */   li    $a0, 1
/* 0D2A38 80317A38 26310001 */  addiu $s1, $s1, 1
/* 0D2A3C 80317A3C 2A2100F1 */  slti  $at, $s1, 0xf1
/* 0D2A40 80317A40 10200013 */  beqz  $at, .L80317A90
/* 0D2A44 80317A44 3C038022 */   lui   $v1, %hi(D_80226D70) # $v1, 0x8022
/* 0D2A48 80317A48 8C636B70 */  lw    $v1, %lo(D_80226D70)($v1)
/* 0D2A4C 80317A4C 00008025 */  move  $s0, $zero
/* 0D2A50 80317A50 3C028022 */  lui   $v0, %hi(D_80222A10) # $v0, 0x8022
/* 0D2A54 80317A54 1860000A */  blez  $v1, .L80317A80
/* 0D2A58 80317A58 00000000 */   nop   
/* 0D2A5C 80317A5C 8C422610 */  lw    $v0, %lo(D_80222A10)($v0)
.L80317A60:
/* 0D2A60 80317A60 8C4F0000 */  lw    $t7, ($v0)
/* 0D2A64 80317A64 000F77C2 */  srl   $t6, $t7, 0x1f
/* 0D2A68 80317A68 15C00005 */  bnez  $t6, .L80317A80
/* 0D2A6C 80317A6C 00000000 */   nop   
/* 0D2A70 80317A70 26100001 */  addiu $s0, $s0, 1
/* 0D2A74 80317A74 0203082A */  slt   $at, $s0, $v1
/* 0D2A78 80317A78 1420FFF9 */  bnez  $at, .L80317A60
/* 0D2A7C 80317A7C 244200C0 */   addiu $v0, $v0, 0xc0
.L80317A80:
/* 0D2A80 80317A80 12030003 */  beq   $s0, $v1, .L80317A90
/* 0D2A84 80317A84 00000000 */   nop   
/* 0D2A88 80317A88 1000FFE9 */  b     .L80317A30
/* 0D2A8C 80317A8C 00000000 */   nop   
.L80317A90:
/* 0D2A90 80317A90 0C0C5E3B */  jal   func_803168CC
/* 0D2A94 80317A94 00000000 */   nop   
/* 0D2A98 80317A98 0C0C5E45 */  jal   func_803168F4
/* 0D2A9C 80317A9C 24040003 */   li    $a0, 3
/* 0D2AA0 80317AA0 3C181971 */  lui   $t8, (0x19710515 >> 16) # lui $t8, 0x1971
/* 0D2AA4 80317AA4 3C198033 */  lui   $t9, %hi(D_80333EF4) # $t9, 0x8033
/* 0D2AA8 80317AA8 27395004 */  addiu $t9, %lo(D_80333EF4) # addiu $t9, $t9, 0x5004
/* 0D2AAC 80317AAC 37180515 */  ori   $t8, (0x19710515 & 0xFFFF) # ori $t8, $t8, 0x515
/* 0D2AB0 80317AB0 AF380000 */  sw    $t8, ($t9)
/* 0D2AB4 80317AB4 0C0C5E45 */  jal   func_803168F4
/* 0D2AB8 80317AB8 24040003 */   li    $a0, 3
/* 0D2ABC 80317ABC 3C138022 */  lui   $s3, %hi(D_80226D84) # $s3, 0x8022
/* 0D2AC0 80317AC0 26736B84 */  addiu $s3, %lo(D_80226D84) # addiu $s3, $s3, 0x6b84
/* 0D2AC4 80317AC4 8E710000 */  lw    $s1, ($s3)
/* 0D2AC8 80317AC8 3C128022 */  lui   $s2, %hi(D_80225EE8) # $s2, 0x8022
/* 0D2ACC 80317ACC 26525CE8 */  addiu $s2, %lo(D_80225EE8) # addiu $s2, $s2, 0x5ce8
/* 0D2AD0 80317AD0 1A200012 */  blez  $s1, .L80317B1C
/* 0D2AD4 80317AD4 00000000 */   nop   
/* 0D2AD8 80317AD8 8E6C0000 */  lw    $t4, ($s3)
.L80317ADC:
/* 0D2ADC 80317ADC 00008025 */  move  $s0, $zero
/* 0D2AE0 80317AE0 1980000C */  blez  $t4, .L80317B14
/* 0D2AE4 80317AE4 02402025 */   move  $a0, $s2
.L80317AE8:
/* 0D2AE8 80317AE8 00002825 */  move  $a1, $zero
/* 0D2AEC 80317AEC 0C0C8A00 */  jal   osRecvMesg
/* 0D2AF0 80317AF0 00003025 */   move  $a2, $zero
/* 0D2AF4 80317AF4 54400003 */  bnezl $v0, .L80317B04
/* 0D2AF8 80317AF8 8E6D0000 */   lw    $t5, ($s3)
/* 0D2AFC 80317AFC 2631FFFF */  addiu $s1, $s1, -1
/* 0D2B00 80317B00 8E6D0000 */  lw    $t5, ($s3)
.L80317B04:
/* 0D2B04 80317B04 26100001 */  addiu $s0, $s0, 1
/* 0D2B08 80317B08 020D082A */  slt   $at, $s0, $t5
/* 0D2B0C 80317B0C 5420FFF6 */  bnezl $at, .L80317AE8
/* 0D2B10 80317B10 02402025 */   move  $a0, $s2
.L80317B14:
/* 0D2B14 80317B14 5E20FFF1 */  bgtzl $s1, .L80317ADC
/* 0D2B18 80317B18 8E6C0000 */   lw    $t4, ($s3)
.L80317B1C:
/* 0D2B1C 80317B1C 3C038022 */  lui   $v1, %hi(D_80226E40) # $v1, 0x8022
/* 0D2B20 80317B20 3C068022 */  lui   $a2, %hi(D_80226E40 + 0xC) # $a2, 0x8022
/* 0D2B24 80317B24 AE600000 */  sw    $zero, ($s3)
/* 0D2B28 80317B28 24C66C4C */  addiu $a2, %lo(D_80226E40 + 0xC) # addiu $a2, $a2, 0x6c4c
/* 0D2B2C 80317B2C 24636C40 */  addiu $v1, %lo(D_80226E40) # addiu $v1, $v1, 0x6c40
/* 0D2B30 80317B30 24040A00 */  li    $a0, 2560
/* 0D2B34 80317B34 00001025 */  move  $v0, $zero
.L80317B38:
/* 0D2B38 80317B38 8C6F0000 */  lw    $t7, ($v1)
/* 0D2B3C 80317B3C 01E27021 */  addu  $t6, $t7, $v0
/* 0D2B40 80317B40 24420002 */  addiu $v0, $v0, 2
/* 0D2B44 80317B44 1444FFFC */  bne   $v0, $a0, .L80317B38
/* 0D2B48 80317B48 A5C00000 */   sh    $zero, ($t6)
/* 0D2B4C 80317B4C 24630004 */  addiu $v1, $v1, 4
/* 0D2B50 80317B50 5466FFF9 */  bnel  $v1, $a2, .L80317B38
/* 0D2B54 80317B54 00001025 */   move  $v0, $zero
/* 0D2B58 80317B58 8FB80038 */  lw    $t8, 0x38($sp)
.L80317B5C:
/* 0D2B5C 80317B5C 3C018022 */  lui   $at, %hi(D_80226B38) # $at, 0x8022
/* 0D2B60 80317B60 AC206938 */  sw    $zero, %lo(D_80226B38)($at)
/* 0D2B64 80317B64 97190006 */  lhu   $t9, 6($t8)
/* 0D2B68 80317B68 AFB9002C */  sw    $t9, 0x2c($sp)
/* 0D2B6C 80317B6C 0C0C965C */  jal   osAiSetFrequency
/* 0D2B70 80317B70 8F040000 */   lw    $a0, ($t8)
/* 0D2B74 80317B74 2401003C */  li    $at, 60
/* 0D2B78 80317B78 0041001A */  div   $zero, $v0, $at
/* 0D2B7C 80317B7C 8FA80038 */  lw    $t0, 0x38($sp)
/* 0D2B80 80317B80 3C038022 */  lui   $v1, %hi(D_80226D64) # $v1, 0x8022
/* 0D2B84 80317B84 24636B64 */  addiu $v1, %lo(D_80226D64) # addiu $v1, $v1, 0x6b64
/* 0D2B88 80317B88 AC620000 */  sw    $v0, ($v1)
/* 0D2B8C 80317B8C 910C0004 */  lbu   $t4, 4($t0)
/* 0D2B90 80317B90 00007812 */  mflo  $t7
/* 0D2B94 80317B94 3C0A8022 */  lui   $t2, %hi(D_80226D74) # $t2, 0x8022
/* 0D2B98 80317B98 3C0B8022 */  lui   $t3, %hi(D_80226D70) # $t3, 0x8022
/* 0D2B9C 80317B9C 25EE000F */  addiu $t6, $t7, 0xf
/* 0D2BA0 80317BA0 2401FFF0 */  li    $at, -16
/* 0D2BA4 80317BA4 256B6B70 */  addiu $t3, %lo(D_80226D70) # addiu $t3, $t3, 0x6b70
/* 0D2BA8 80317BA8 254A6B74 */  addiu $t2, %lo(D_80226D74) # addiu $t2, $t2, 0x6b74
/* 0D2BAC 80317BAC 01C1C824 */  and   $t9, $t6, $at
/* 0D2BB0 80317BB0 AD590000 */  sw    $t9, ($t2)
/* 0D2BB4 80317BB4 AD6C0000 */  sw    $t4, ($t3)
/* 0D2BB8 80317BB8 91180005 */  lbu   $t8, 5($t0)
/* 0D2BBC 80317BBC 3C098022 */  lui   $t1, %hi(D_802212A2) # $t1, 0x8022
/* 0D2BC0 80317BC0 25290EA2 */  addiu $t1, %lo(D_802212A2) # addiu $t1, $t1, 0xea2
/* 0D2BC4 80317BC4 A1380000 */  sb    $t8, ($t1)
/* 0D2BC8 80317BC8 812C0000 */  lb    $t4, ($t1)
/* 0D2BCC 80317BCC 258DFFFF */  addiu $t5, $t4, -1
/* 0D2BD0 80317BD0 2DA10010 */  sltiu $at, $t5, 0x10
/* 0D2BD4 80317BD4 10200019 */  beqz  $at, .L80317C3C
/* 0D2BD8 80317BD8 000D6880 */   sll   $t5, $t5, 2
/* 0D2BDC 80317BDC 3C018034 */  lui   $at, %hi(jtbl_80337BE0)
/* 0D2BE0 80317BE0 002D0821 */  addu  $at, $at, $t5
/* 0D2BE4 80317BE4 8C2D8DC0 */  lw    $t5, %lo(jtbl_80337BE0)($at)
/* 0D2BE8 80317BE8 01A00008 */  jr    $t5
/* 0D2BEC 80317BEC 00000000 */   nop   
glabel L80317BF0
/* 0D2BF0 80317BF0 3C018022 */  lui   $at, %hi(D_802212A3) # $at, 0x8022
/* 0D2BF4 80317BF4 10000013 */  b     .L80317C44
/* 0D2BF8 80317BF8 A0200EA3 */   sb    $zero, %lo(D_802212A3)($at)
glabel L80317BFC
/* 0D2BFC 80317BFC 240F0001 */  li    $t7, 1
/* 0D2C00 80317C00 3C018022 */  lui   $at, %hi(D_802212A3) # $at, 0x8022
/* 0D2C04 80317C04 1000000F */  b     .L80317C44
/* 0D2C08 80317C08 A02F0EA3 */   sb    $t7, %lo(D_802212A3)($at)
glabel L80317C0C
/* 0D2C0C 80317C0C 240E0002 */  li    $t6, 2
/* 0D2C10 80317C10 3C018022 */  lui   $at, %hi(D_802212A3) # $at, 0x8022
/* 0D2C14 80317C14 1000000B */  b     .L80317C44
/* 0D2C18 80317C18 A02E0EA3 */   sb    $t6, %lo(D_802212A3)($at)
glabel L80317C1C
/* 0D2C1C 80317C1C 24190003 */  li    $t9, 3
/* 0D2C20 80317C20 3C018022 */  lui   $at, %hi(D_802212A3) # $at, 0x8022
/* 0D2C24 80317C24 10000007 */  b     .L80317C44
/* 0D2C28 80317C28 A0390EA3 */   sb    $t9, %lo(D_802212A3)($at)
glabel L80317C2C
/* 0D2C2C 80317C2C 24180004 */  li    $t8, 4
/* 0D2C30 80317C30 3C018022 */  lui   $at, %hi(D_802212A3) # $at, 0x8022
/* 0D2C34 80317C34 10000003 */  b     .L80317C44
/* 0D2C38 80317C38 A0380EA3 */   sb    $t8, %lo(D_802212A3)($at)
glabel L80317C3C
.L80317C3C:
/* 0D2C3C 80317C3C 3C018022 */  lui   $at, %hi(D_802212A3) # $at, 0x8022
/* 0D2C40 80317C40 A0200EA3 */  sb    $zero, %lo(D_802212A3)($at)
.L80317C44:
/* 0D2C44 80317C44 910C0005 */  lbu   $t4, 5($t0)
/* 0D2C48 80317C48 3C018022 */  lui   $at, %hi(D_802212A0) # $at, 0x8022
/* 0D2C4C 80317C4C 3C198033 */  lui   $t9, %hi(D_80333EE4) # $t9, 0x8033
/* 0D2C50 80317C50 A12C0000 */  sb    $t4, ($t1)
/* 0D2C54 80317C54 950D000A */  lhu   $t5, 0xa($t0)
/* 0D2C58 80317C58 87394FF4 */  lh    $t9, %lo(D_80333EE4)($t9)
/* 0D2C5C 80317C5C 240C0001 */  li    $t4, 1
/* 0D2C60 80317C60 A42D0EA0 */  sh    $t5, %lo(D_802212A0)($at)
/* 0D2C64 80317C64 8D420000 */  lw    $v0, ($t2)
/* 0D2C68 80317C68 3C018022 */  lui   $at, %hi(D_80226D78) # $at, 0x8022
/* 0D2C6C 80317C6C 44998000 */  mtc1  $t9, $f16
/* 0D2C70 80317C70 244FFFF0 */  addiu $t7, $v0, -0x10
/* 0D2C74 80317C74 AC2F6B78 */  sw    $t7, %lo(D_80226D78)($at)
/* 0D2C78 80317C78 240100A0 */  li    $at, 160
/* 0D2C7C 80317C7C 0041001A */  div   $zero, $v0, $at
/* 0D2C80 80317C80 00001812 */  mflo  $v1
/* 0D2C84 80317C84 24630001 */  addiu $v1, $v1, 1
/* 0D2C88 80317C88 00032E00 */  sll   $a1, $v1, 0x18
/* 0D2C8C 80317C8C 00057603 */  sra   $t6, $a1, 0x18
/* 0D2C90 80317C90 01C02825 */  move  $a1, $t6
/* 0D2C94 80317C94 44852000 */  mtc1  $a1, $f4
/* 0D2C98 80317C98 3C018022 */  lui   $at, %hi(D_80226D7E) # $at, 0x8022
/* 0D2C9C 80317C9C A0236B7E */  sb    $v1, %lo(D_80226D7E)($at)
/* 0D2CA0 80317CA0 468021A0 */  cvt.s.w $f6, $f4
/* 0D2CA4 80317CA4 3C018034 */  lui   $at, %hi(D_U_80338E00) # $at, 0x8034
/* 0D2CA8 80317CA8 C4288E00 */  lwc1  $f8, %lo(D_U_80338E00)($at)
/* 0D2CAC 80317CAC 3C018034 */  lui   $at, %hi(D_U_80338E04) # $at, 0x8034
/* 0D2CB0 80317CB0 3C048022 */  lui   $a0, %hi(D_80221898) # $a0, 0x8022
/* 0D2CB4 80317CB4 468084A0 */  cvt.s.w $f18, $f16
/* 0D2CB8 80317CB8 46083282 */  mul.s $f10, $f6, $f8
/* 0D2CBC 80317CBC C4268E04 */  lwc1  $f6, %lo(D_U_80338E04)($at)
/* 0D2CC0 80317CC0 3C138022 */  lui   $s3, %hi(D_80226D6C) # $s3, 0x8022
/* 0D2CC4 80317CC4 26736B6C */  addiu $s3, %lo(D_80226D6C) # addiu $s3, $s3, 0x6b6c
/* 0D2CC8 80317CC8 24841498 */  addiu $a0, %lo(D_80221898) # addiu $a0, $a0, 0x1498
/* 0D2CCC 80317CCC 46125103 */  div.s $f4, $f10, $f18
/* 0D2CD0 80317CD0 46062203 */  div.s $f8, $f4, $f6
/* 0D2CD4 80317CD4 4458F800 */  cfc1  $t8, $31
/* 0D2CD8 80317CD8 44CCF800 */  ctc1  $t4, $31
/* 0D2CDC 80317CDC 00000000 */  nop   
/* 0D2CE0 80317CE0 46004424 */  cvt.w.s $f16, $f8
/* 0D2CE4 80317CE4 444CF800 */  cfc1  $t4, $31
/* 0D2CE8 80317CE8 00000000 */  nop   
/* 0D2CEC 80317CEC 318C0078 */  andi  $t4, $t4, 0x78
/* 0D2CF0 80317CF0 11800012 */  beqz  $t4, .L80317D3C
/* 0D2CF4 80317CF4 3C014F00 */   li    $at, 0x4F000000 # 2147483648.000000
/* 0D2CF8 80317CF8 44818000 */  mtc1  $at, $f16
/* 0D2CFC 80317CFC 240C0001 */  li    $t4, 1
/* 0D2D00 80317D00 46104401 */  sub.s $f16, $f8, $f16
/* 0D2D04 80317D04 44CCF800 */  ctc1  $t4, $31
/* 0D2D08 80317D08 00000000 */  nop   
/* 0D2D0C 80317D0C 46008424 */  cvt.w.s $f16, $f16
/* 0D2D10 80317D10 444CF800 */  cfc1  $t4, $31
/* 0D2D14 80317D14 00000000 */  nop   
/* 0D2D18 80317D18 318C0078 */  andi  $t4, $t4, 0x78
/* 0D2D1C 80317D1C 15800005 */  bnez  $t4, .L80317D34
/* 0D2D20 80317D20 00000000 */   nop   
/* 0D2D24 80317D24 440C8000 */  mfc1  $t4, $f16
/* 0D2D28 80317D28 3C018000 */  lui   $at, 0x8000
/* 0D2D2C 80317D2C 10000007 */  b     .L80317D4C
/* 0D2D30 80317D30 01816025 */   or    $t4, $t4, $at
.L80317D34:
/* 0D2D34 80317D34 10000005 */  b     .L80317D4C
/* 0D2D38 80317D38 240CFFFF */   li    $t4, -1
.L80317D3C:
/* 0D2D3C 80317D3C 440C8000 */  mfc1  $t4, $f16
/* 0D2D40 80317D40 00000000 */  nop   
/* 0D2D44 80317D44 0580FFFB */  bltz  $t4, .L80317D34
/* 0D2D48 80317D48 00000000 */   nop   
.L80317D4C:
/* 0D2D4C 80317D4C 3C018022 */  lui   $at, %hi(D_80226D7C) # $at, 0x8022
/* 0D2D50 80317D50 A42C6B7C */  sh    $t4, %lo(D_80226D7C)($at)
/* 0D2D54 80317D54 8D6D0000 */  lw    $t5, ($t3)
/* 0D2D58 80317D58 44D8F800 */  ctc1  $t8, $31
/* 0D2D5C 80317D5C 000D7880 */  sll   $t7, $t5, 2
/* 0D2D60 80317D60 01ED7821 */  addu  $t7, $t7, $t5
/* 0D2D64 80317D64 000F7880 */  sll   $t7, $t7, 2
/* 0D2D68 80317D68 01E50019 */  multu $t7, $a1
/* 0D2D6C 80317D6C 00007012 */  mflo  $t6
/* 0D2D70 80317D70 25D90140 */  addiu $t9, $t6, 0x140
/* 0D2D74 80317D74 AE790000 */  sw    $t9, ($s3)
/* 0D2D78 80317D78 8D0C000C */  lw    $t4, 0xc($t0)
/* 0D2D7C 80317D7C 8D180010 */  lw    $t8, 0x10($t0)
/* 0D2D80 80317D80 8D0F0014 */  lw    $t7, 0x14($t0)
/* 0D2D84 80317D84 8D0D0018 */  lw    $t5, 0x18($t0)
/* 0D2D88 80317D88 3C0E8022 */  lui   $t6, %hi(D_802212A8 + 8) # $t6, 0x8022
/* 0D2D8C 80317D8C 8DCE0EB0 */  lw    $t6, %lo(D_802212A8 + 8)($t6)
/* 0D2D90 80317D90 030C8021 */  addu  $s0, $t8, $t4
/* 0D2D94 80317D94 01AF8821 */  addu  $s1, $t5, $t7
/* 0D2D98 80317D98 02113021 */  addu  $a2, $s0, $s1
/* 0D2D9C 80317D9C 01C63823 */  subu  $a3, $t6, $a2
/* 0D2DA0 80317DA0 24E7FF00 */  addiu $a3, $a3, -0x100
/* 0D2DA4 80317DA4 AC870000 */  sw    $a3, ($a0)
/* 0D2DA8 80317DA8 0C0C5C61 */  jal   func_80316164
/* 0D2DAC 80317DAC AC86000C */   sw    $a2, 0xc($a0)
/* 0D2DB0 80317DB0 3C048022 */  lui   $a0, %hi(D_802218A8) # $a0, 0x8022
/* 0D2DB4 80317DB4 248414A8 */  addiu $a0, %lo(D_802218A8) # addiu $a0, $a0, 0x14a8
/* 0D2DB8 80317DB8 AC900000 */  sw    $s0, ($a0)
/* 0D2DBC 80317DBC 0C0C5C80 */  jal   func_803161E0
/* 0D2DC0 80317DC0 AC910004 */   sw    $s1, 4($a0)
/* 0D2DC4 80317DC4 8FA20038 */  lw    $v0, 0x38($sp)
/* 0D2DC8 80317DC8 3C048022 */  lui   $a0, %hi(D_802218B0) # $a0, 0x8022
/* 0D2DCC 80317DCC 248414B0 */  addiu $a0, %lo(D_802218B0) # addiu $a0, $a0, 0x14b0
/* 0D2DD0 80317DD0 8C59000C */  lw    $t9, 0xc($v0)
/* 0D2DD4 80317DD4 AC990000 */  sw    $t9, ($a0)
/* 0D2DD8 80317DD8 8C580010 */  lw    $t8, 0x10($v0)
/* 0D2DDC 80317DDC AC800008 */  sw    $zero, 8($a0)
/* 0D2DE0 80317DE0 0C0C5C9F */  jal   func_8031625C
/* 0D2DE4 80317DE4 AC980004 */   sw    $t8, 4($a0)
/* 0D2DE8 80317DE8 8FAC0038 */  lw    $t4, 0x38($sp)
/* 0D2DEC 80317DEC 8FAF0038 */  lw    $t7, 0x38($sp)
/* 0D2DF0 80317DF0 3C048022 */  lui   $a0, %hi(D_802218C0) # $a0, 0x8022
/* 0D2DF4 80317DF4 8D8D0014 */  lw    $t5, 0x14($t4)
/* 0D2DF8 80317DF8 248414C0 */  addiu $a0, %lo(D_802218C0) # addiu $a0, $a0, 0x14c0
/* 0D2DFC 80317DFC AC8D0000 */  sw    $t5, ($a0)
/* 0D2E00 80317E00 8DEE0018 */  lw    $t6, 0x18($t7)
/* 0D2E04 80317E04 AC800008 */  sw    $zero, 8($a0)
/* 0D2E08 80317E08 0C0C5CCE */  jal   func_80316318
/* 0D2E0C 80317E0C AC8E0004 */   sw    $t6, 4($a0)
/* 0D2E10 80317E10 0C0C5BA0 */  jal   func_80315E60
/* 0D2E14 80317E14 00000000 */   nop   
/* 0D2E18 80317E18 3C108022 */  lui   $s0, %hi(D_80226D90) # $s0, 0x8022
/* 0D2E1C 80317E1C 3C128022 */  lui   $s2, %hi(D_802212C8) # $s2, 0x8022
/* 0D2E20 80317E20 3C118022 */  lui   $s1, %hi(D_80226D90 + 8) # $s1, 0x8022
/* 0D2E24 80317E24 26316B98 */  addiu $s1, %lo(D_80226D90 + 8) # addiu $s1, $s1, 0x6b98
/* 0D2E28 80317E28 26520EC8 */  addiu $s2, %lo(D_802212C8) # addiu $s2, $s2, 0xec8
/* 0D2E2C 80317E2C 26106B90 */  addiu $s0, %lo(D_80226D90) # addiu $s0, $s0, 0x6b90
.L80317E30:
/* 0D2E30 80317E30 8E650000 */  lw    $a1, ($s3)
/* 0D2E34 80317E34 02402025 */  move  $a0, $s2
/* 0D2E38 80317E38 0005C8C0 */  sll   $t9, $a1, 3
/* 0D2E3C 80317E3C 0C0C5C10 */  jal   soundAlloc
/* 0D2E40 80317E40 03202825 */   move  $a1, $t9
/* 0D2E44 80317E44 26100004 */  addiu $s0, $s0, 4
/* 0D2E48 80317E48 1611FFF9 */  bne   $s0, $s1, .L80317E30
/* 0D2E4C 80317E4C AE02FFFC */   sw    $v0, -4($s0)
/* 0D2E50 80317E50 3C058022 */  lui   $a1, %hi(D_80226D70) # $a1, 0x8022
/* 0D2E54 80317E54 8CA56B70 */  lw    $a1, %lo(D_80226D70)($a1)
/* 0D2E58 80317E58 02402025 */  move  $a0, $s2
/* 0D2E5C 80317E5C 0005C080 */  sll   $t8, $a1, 2
/* 0D2E60 80317E60 0305C023 */  subu  $t8, $t8, $a1
/* 0D2E64 80317E64 0C0C5C10 */  jal   soundAlloc
/* 0D2E68 80317E68 00182980 */   sll   $a1, $t8, 6
/* 0D2E6C 80317E6C 3C018022 */  lui   $at, %hi(D_80222A10) # $at, 0x8022
/* 0D2E70 80317E70 0C0C6B6B */  jal   func_80319D40
/* 0D2E74 80317E74 AC222610 */   sw    $v0, %lo(D_80222A10)($at)
/* 0D2E78 80317E78 0C0C68AD */  jal   func_80319248
/* 0D2E7C 80317E7C 00000000 */   nop   
/* 0D2E80 80317E80 8FA2002C */  lw    $v0, 0x2c($sp)
/* 0D2E84 80317E84 3C118022 */  lui   $s1, %hi(D_802211B0) # $s1, 0x8022
/* 0D2E88 80317E88 26310DB0 */  addiu $s1, %lo(D_802211B0) # addiu $s1, $s1, 0xdb0
/* 0D2E8C 80317E8C 14400005 */  bnez  $v0, .L80317EA4
/* 0D2E90 80317E90 240C0008 */   li    $t4, 8
/* 0D2E94 80317E94 3C118022 */  lui   $s1, %hi(D_802211B0) # $s1, 0x8022
/* 0D2E98 80317E98 26310DB0 */  addiu $s1, %lo(D_802211B0) # addiu $s1, $s1, 0xdb0
/* 0D2E9C 80317E9C 10000051 */  b     .L80317FE4
/* 0D2EA0 80317EA0 A2200001 */   sb    $zero, 1($s1)
.L80317EA4:
/* 0D2EA4 80317EA4 00028040 */  sll   $s0, $v0, 1
/* 0D2EA8 80317EA8 A22C0001 */  sb    $t4, 1($s1)
/* 0D2EAC 80317EAC 02002825 */  move  $a1, $s0
/* 0D2EB0 80317EB0 0C0C5C10 */  jal   soundAlloc
/* 0D2EB4 80317EB4 02402025 */   move  $a0, $s2
/* 0D2EB8 80317EB8 AE220014 */  sw    $v0, 0x14($s1)
/* 0D2EBC 80317EBC 02402025 */  move  $a0, $s2
/* 0D2EC0 80317EC0 0C0C5C10 */  jal   soundAlloc
/* 0D2EC4 80317EC4 02002825 */   move  $a1, $s0
/* 0D2EC8 80317EC8 8FAD002C */  lw    $t5, 0x2c($sp)
/* 0D2ECC 80317ECC 8FAF0038 */  lw    $t7, 0x38($sp)
/* 0D2ED0 80317ED0 AE220018 */  sw    $v0, 0x18($s1)
/* 0D2ED4 80317ED4 AE200008 */  sw    $zero, 8($s1)
/* 0D2ED8 80317ED8 AE20000C */  sw    $zero, 0xc($s1)
/* 0D2EDC 80317EDC A2200003 */  sb    $zero, 3($s1)
/* 0D2EE0 80317EE0 AE2D0010 */  sw    $t5, 0x10($s1)
/* 0D2EE4 80317EE4 95EE0008 */  lhu   $t6, 8($t7)
/* 0D2EE8 80317EE8 24190002 */  li    $t9, 2
/* 0D2EEC 80317EEC A2390002 */  sb    $t9, 2($s1)
/* 0D2EF0 80317EF0 3C038022 */  lui   $v1, %hi(D_802212A2) # $v1, 0x8022
/* 0D2EF4 80317EF4 A62E0004 */  sh    $t6, 4($s1)
/* 0D2EF8 80317EF8 80630EA2 */  lb    $v1, %lo(D_802212A2)($v1)
/* 0D2EFC 80317EFC 24010001 */  li    $at, 1
/* 0D2F00 80317F00 24180001 */  li    $t8, 1
/* 0D2F04 80317F04 10610037 */  beq   $v1, $at, .L80317FE4
/* 0D2F08 80317F08 340C8000 */   li    $t4, 32768
/* 0D2F0C 80317F0C 0183001A */  div   $zero, $t4, $v1
/* 0D2F10 80317F10 00006812 */  mflo  $t5
/* 0D2F14 80317F14 A2380000 */  sb    $t8, ($s1)
/* 0D2F18 80317F18 14600002 */  bnez  $v1, .L80317F24
/* 0D2F1C 80317F1C 00000000 */   nop   
/* 0D2F20 80317F20 0007000D */  break 7
.L80317F24:
/* 0D2F24 80317F24 2401FFFF */  li    $at, -1
/* 0D2F28 80317F28 14610004 */  bne   $v1, $at, .L80317F3C
/* 0D2F2C 80317F2C 3C018000 */   lui   $at, 0x8000
/* 0D2F30 80317F30 15810002 */  bne   $t4, $at, .L80317F3C
/* 0D2F34 80317F34 00000000 */   nop   
/* 0D2F38 80317F38 0006000D */  break 6
.L80317F3C:
/* 0D2F3C 80317F3C A62D0006 */  sh    $t5, 6($s1)
/* 0D2F40 80317F40 02402025 */  move  $a0, $s2
/* 0D2F44 80317F44 24050020 */  li    $a1, 32
/* 0D2F48 80317F48 0C0C5C10 */  jal   soundAlloc
/* 0D2F4C 80317F4C 00008025 */   move  $s0, $zero
/* 0D2F50 80317F50 AE22001C */  sw    $v0, 0x1c($s1)
/* 0D2F54 80317F54 02402025 */  move  $a0, $s2
/* 0D2F58 80317F58 0C0C5C10 */  jal   soundAlloc
/* 0D2F5C 80317F5C 24050020 */   li    $a1, 32
/* 0D2F60 80317F60 AE220020 */  sw    $v0, 0x20($s1)
/* 0D2F64 80317F64 02402025 */  move  $a0, $s2
/* 0D2F68 80317F68 0C0C5C10 */  jal   soundAlloc
/* 0D2F6C 80317F6C 24050020 */   li    $a1, 32
/* 0D2F70 80317F70 AE220024 */  sw    $v0, 0x24($s1)
/* 0D2F74 80317F74 02402025 */  move  $a0, $s2
/* 0D2F78 80317F78 0C0C5C10 */  jal   soundAlloc
/* 0D2F7C 80317F7C 24050020 */   li    $a1, 32
/* 0D2F80 80317F80 AE220028 */  sw    $v0, 0x28($s1)
/* 0D2F84 80317F84 3C0F8022 */  lui   $t7, %hi(D_80226D7E) # $t7, 0x8022
/* 0D2F88 80317F88 81EF6B7E */  lb    $t7, %lo(D_80226D7E)($t7)
/* 0D2F8C 80317F8C 3C118022 */  lui   $s1, %hi(D_802211B0) # $s1, 0x8022
/* 0D2F90 80317F90 26310DB0 */  addiu $s1, %lo(D_802211B0) # addiu $s1, $s1, 0xdb0
/* 0D2F94 80317F94 19E00013 */  blez  $t7, .L80317FE4
/* 0D2F98 80317F98 02402025 */   move  $a0, $s2
.L80317F9C:
/* 0D2F9C 80317F9C 0C0C5C10 */  jal   soundAlloc
/* 0D2FA0 80317FA0 24050280 */   li    $a1, 640
/* 0D2FA4 80317FA4 244E0140 */  addiu $t6, $v0, 0x140
/* 0D2FA8 80317FA8 AE220030 */  sw    $v0, 0x30($s1)
/* 0D2FAC 80317FAC AE2E0034 */  sw    $t6, 0x34($s1)
/* 0D2FB0 80317FB0 02402025 */  move  $a0, $s2
/* 0D2FB4 80317FB4 0C0C5C10 */  jal   soundAlloc
/* 0D2FB8 80317FB8 24050280 */   li    $a1, 640
/* 0D2FBC 80317FBC 24590140 */  addiu $t9, $v0, 0x140
/* 0D2FC0 80317FC0 3C188022 */  lui   $t8, %hi(D_80226D7E) # $t8, 0x8022
/* 0D2FC4 80317FC4 AE220080 */  sw    $v0, 0x80($s1)
/* 0D2FC8 80317FC8 AE390084 */  sw    $t9, 0x84($s1)
/* 0D2FCC 80317FCC 83186B7E */  lb    $t8, %lo(D_80226D7E)($t8)
/* 0D2FD0 80317FD0 26100001 */  addiu $s0, $s0, 1
/* 0D2FD4 80317FD4 26310014 */  addiu $s1, $s1, 0x14
/* 0D2FD8 80317FD8 0218082A */  slt   $at, $s0, $t8
/* 0D2FDC 80317FDC 5420FFEF */  bnezl $at, .L80317F9C
/* 0D2FE0 80317FE0 02402025 */   move  $a0, $s2
.L80317FE4:
/* 0D2FE4 80317FE4 3C048022 */  lui   $a0, %hi(D_80226D70) # $a0, 0x8022
/* 0D2FE8 80317FE8 0C0C618D */  jal   func_8031758C
/* 0D2FEC 80317FEC 8C846B70 */   lw    $a0, %lo(D_80226D70)($a0)
/* 0D2FF0 80317FF0 0C0C8BD0 */  jal   osWritebackDCacheAll
/* 0D2FF4 80317FF4 00000000 */   nop   
/* 0D2FF8 80317FF8 3C0C8033 */  lui   $t4, %hi(D_80333EF4) # $t4, 0x8033
/* 0D2FFC 80317FFC 258C5004 */  addiu $t4, %lo(D_80333EF4) # addiu $t4, $t4, 0x5004
/* 0D3000 80318000 8D8D0000 */  lw    $t5, ($t4)
/* 0D3004 80318004 3C0F7655 */  lui   $t7, (0x76557364 >> 16) # lui $t7, 0x7655
/* 0D3008 80318008 35EF7364 */  ori   $t7, (0x76557364 & 0xFFFF) # ori $t7, $t7, 0x7364
/* 0D300C 8031800C 51A00003 */  beql  $t5, $zero, .L8031801C
/* 0D3010 80318010 8FBF0024 */   lw    $ra, 0x24($sp)
/* 0D3014 80318014 AD8F0000 */  sw    $t7, ($t4)
/* 0D3018 80318018 8FBF0024 */  lw    $ra, 0x24($sp)
.L8031801C:
/* 0D301C 8031801C 8FB00014 */  lw    $s0, 0x14($sp)
/* 0D3020 80318020 8FB10018 */  lw    $s1, 0x18($sp)
/* 0D3024 80318024 8FB2001C */  lw    $s2, 0x1c($sp)
/* 0D3028 80318028 8FB30020 */  lw    $s3, 0x20($sp)
/* 0D302C 8031802C 03E00008 */  jr    $ra
/* 0D3030 80318030 27BD0038 */   addiu $sp, $sp, 0x38
)
#endif
