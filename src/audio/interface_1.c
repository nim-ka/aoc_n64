#include <ultra64.h>

#include "sm64.h"
#include "dac.h"
#include "dma.h"
#include "interface_1.h"
#include "interface_2.h"
#include "playback.h"
#include "playback2.h"

#ifdef VERSION_JP
#define US_FLOAT(x) x
#else
#define US_FLOAT(x) x ## f
#endif

// Convert u8 or u16 to float. On JP, this uses a u32->f32 conversion,
// resulting in more bloated codegen, while on US it goes through s32.
// Since u8 and u16 fit losslessly in both, behavior is the same.
#ifdef VERSION_JP
#define FLOAT_CAST(x) (f32) (x)
#else
#define FLOAT_CAST(x) (f32) (s32) (x)
#endif

void func_8031B0A4(struct SubStruct_func_80318870 *arg0);
void func_8031C104(struct Struct80225DD8 *arg0);
void func_8031CAD4(struct Struct80222A18 *arg0);

void func_8031A810(struct Struct80225DD8 *arg0)
{
    s32 i;

    arg0->unk0b80 = 0;
    arg0->unk0b40 = 0;
    arg0->unk0b20 = 0;
    arg0->unk0b10 = 0;
    arg0->unk0b8 = 0;
    arg0->unk0b4 = 0;
    arg0->unk1A = 0;
    arg0->unk0b2 = 0;
    arg0->unk5C.unk18 = 0;
    arg0->unk20 = 1.0f;
    arg0->unk1C = 1.0f;
    arg0->unk2C = 1.0f;
    arg0->unk24 = 0.5f;
    arg0->unk28 = 1.0f;
    arg0->unk34 = 0;
    arg0->unk3 = 0;
    arg0->unk4 = 3;
    arg0->unk16 = 0;
    arg0->unk78.unk4 = D_80332AB4;
    arg0->unk78.unk0 = 0x20;
    arg0->unk78.unk2 = 0;
    arg0->unk6 = D_80226D7E;
    arg0->unkC = 0x800;
    arg0->unk8 = 0x800;
    arg0->unkE = 0;
    arg0->unkA = 0;
    arg0->unk10 = 0;
    arg0->unk12 = 0;
    arg0->unk14 = 0;

    for (i = 0; i < 8; i++)
    {
        arg0->unk54[i] = -1;
    }

    arg0->unk0b1 = 0;
    func_803191F8(arg0->unk80);
}

s32 func_8031A920(struct Struct80225DD8 *arg0, s32 arg1)
{
    struct SubStruct_func_80318870 *sub;

    if (arg0->unk44[arg1] == NULL)
    {
        sub = func_8031AF34(&D_80225E98);
        arg0->unk44[arg1] = sub;
        if (sub == NULL)
        {
            arg0->unk44[arg1] = NULL;
            return -1;
        }
    }
    else
    {
        func_80318EC4(arg0->unk44[arg1]);
    }

    sub = arg0->unk44[arg1];
    sub->unk50 = arg0;
    sub->unk14 = arg0->unk78;
    sub->unk14.unk0 = 0;
    sub->unk0b80 = 1;
    sub->unk0b20 = 0;
    sub->unk0b10 = 0;
    sub->unk0b40 = 0;
    sub->unk04.unk00 = 0;
    sub->unk6C = 0;
    sub->unk1 = 0;
    sub->unk2 = 0x80;
    sub->unk1E = 0;
    sub->unk3C = 0;
    sub->unk3E = 0;
    sub->unk40 = 0;
    sub->unk44 = NULL;
    sub->unk48 = NULL;
    sub->unk24 = 0.0f;
    sub->unk28 = 0.5f;
    return 0;
}

void func_8031AA10(struct SubStruct_func_80318870 *arg0)
{
    if (arg0 != NULL)
    {
        func_80318EC4(arg0);
        arg0->unk0b80 = 0;
        arg0->unk0b40 = 1;
    }
}

void func_8031AA4C(struct Struct80225DD8 *arg0, s32 arg1)
{
    struct SubStruct_func_80318870 *unk44 = arg0->unk44[arg1];
    struct PlaybackListItem *item;

    if (unk44 != NULL)
    {
        // push to end of list
        item = &unk44->unk70;
        if (item->prev == NULL)
        {
            D_80225E98.prev->next = item;
            item->prev = D_80225E98.prev;
            item->next = &D_80225E98;
            D_80225E98.prev = item;
            D_80225E98.u.count++;
            item->unkC = D_80225E98.unkC;
        }
        func_8031AA10(unk44);
        arg0->unk44[arg1] = NULL;
    }
}

void func_8031AAD0(struct Struct80225DD8 *arg0)
{
    s32 i;
    for (i = 0; i < 4; i++)
    {
        func_8031AA4C(arg0, i);
    }

    func_803192FC(arg0->unk80);
    arg0->unk0b80 = 0;
    arg0->unk0b40 = 1;
}

struct Struct80225DD8 *func_8031AB3C(void)
{
    s32 i;
    for (i = 0; i < ARRAY_COUNT(D_80222DD8); i++)
    {
        if (D_80222DD8[i].unk40 == NULL)
        {
            return D_80222DD8 + i;
        }
    }
    return &D_80225DD8;
}

void func_8031AB84(struct Struct80222A18 *arg0, u16 bits)
{
    struct Struct80225DD8 *temp;
    s32 i;

    for (i = 0; i < 0x10; i++)
    {
        if (bits & 1)
        {
            temp = arg0->unk2C[i];
            if (IS_SPECIAL(temp) == 1 && temp->unk40 == arg0)
            {
                func_8031AAD0(temp);
                temp->unk40 = 0;
            }
            temp = func_8031AB3C();
            if (IS_SPECIAL(temp) == 0)
            {
                D_80331D40 = i + 0x10000;
                arg0->unk2C[i] = temp;
            }
            else
            {
                func_8031A810(temp);
                arg0->unk2C[i] = temp;
                temp->unk40 = arg0;
                temp->unk5 = arg0->unk6[0];
                temp->unk2 = arg0->unk4;
                temp->unk1 = arg0->unk3;
            }
        }
        bits >>= 1;
    }
}

void func_8031ACB0(struct Struct80222A18 *arg0, u16 bits)
{
    struct Struct80225DD8 *temp;
    s32 i;

    for (i = 0; i < 0x10; i++)
    {
        if (bits & 1)
        {
            temp = arg0->unk2C[i];
            if (IS_SPECIAL(temp) == 1)
            {
                if (temp->unk40 == arg0)
                {
                    func_8031AAD0(temp);
                    temp->unk40 = 0;
                }
                arg0->unk2C[i] = &D_80225DD8;
            }
        }
        bits >>= 1;
    }
}

void func_8031AD80(struct Struct80222A18 *arg0, u8 arg1, void *arg2)
{
    struct Struct80225DD8 *temp = arg0->unk2C[arg1];
    s32 i;

    if (IS_SPECIAL(temp) != 0)
    {
        temp->unk0b80 = 1;
        temp->unk0b40 = 0;
        temp->unk5C.unk18 = 0;
        temp->unk5C.unk0 = arg2;
        temp->unk16 = 0;
        for (i = 0; i < 4; i++)
        {
            if (temp->unk44[i] != 0)
            {
                func_8031AA4C(temp, i);
            }
        }
    }
}

void func_8031AE24(struct Struct80222A18 *arg0)
{
    func_8031ACB0(arg0, 0xffff);
    func_803192FC(arg0->unk90);
    arg0->unk0b40 = 1;
    arg0->unk0b80 = 0;

    if (D_80221910[arg0->unk5] >= 2)
    {
        D_80221910[arg0->unk5] = 3;
    }

    if (D_802218D0[arg0->unk6[0]] >= 2)
    {
        D_802218D0[arg0->unk6[0]] = 3;
    }

    if (D_802214F8.second.arr[0].unk8 == arg0->unk6[0])
    {
        D_802214F8.second.unk0 = 1;
    }
    else if (D_802214F8.second.arr[1].unk8 == arg0->unk6[0])
    {
        D_802214F8.second.unk0 = 0;
    }
}

void func_8031AEF4(struct PlaybackListItem *head, struct PlaybackListItem *item)
{
    // add 'item' to the end of the list given by 'head', if it's not in any list
    if (item->prev == NULL)
    {
        head->prev->next = item;
        item->prev = head->prev;
        item->next = head;
        head->prev = item;
        head->u.count++;
        item->unkC = head->unkC;
    }
}

void *func_8031AF34(struct PlaybackListItem *head)
{
    // remove the last item from a list, and return it (or NULL if empty)
    struct PlaybackListItem *item = head->prev;
    if (item == head)
    {
        return NULL;
    }
    item->prev->next = head;
    head->prev = item->prev;
    item->prev = NULL;
    head->u.count--;
    return item->u.value;
}

void func_8031AF74(void)
{
    s32 i;

    D_80225E98.prev = &D_80225E98;
    D_80225E98.next = &D_80225E98;
    D_80225E98.u.count = 0;
    D_80225E98.unkC = NULL;

    for (i = 0; i < ARRAY_COUNT(D_802245D8); i++)
    {
        D_802245D8[i].unk70.u.value2 = D_802245D8 + i;
        D_802245D8[i].unk70.prev = NULL;
        func_8031AEF4(&D_80225E98, &D_802245D8[i].unk70);
    }
}

u8 func_8031B01C(struct Interface1Buffer *arg0)
{
    u8 *old = arg0->unk0++;
    return *old;
}

s16 func_8031B030(struct Interface1Buffer *arg0)
{
    s16 ret = *(arg0->unk0++) << 8;
    ret = *(arg0->unk0++) | ret;
    return ret;
}

u16 func_8031B060(struct Interface1Buffer *arg0)
{
    u16 ret = *(arg0->unk0++);
    if (ret & 0x80)
    {
        ret = (ret << 8) & 0x7f00;
        ret = *(arg0->unk0++) | ret;
    }
    return ret;
}

#ifdef VERSION_JP
GLOBAL_ASM(
.late_rodata
glabel jtbl_80337C90
	.word L8031B2C0
	.word L8031B27C
	.word L8031B690
	.word L8031B690
	.word L8031B30C
	.word L8031B220
	.word L8031B690
	.word L8031B690
	.word L8031B1E4

glabel jtbl_80337CB4
	.word L8031B350
	.word L8031B3A8
	.word L8031B444
	.word L8031B3D4
	.word L8031B3D4
	.word L8031B494
	.word L8031B5B8
	.word L8031B688
	.word L8031B3A8
	.word L8031B350

glabel jtbl_80337CDC
	.word L8031BBE8
	.word L8031BBF4
	.word L8031BBE8
	.word L8031BBF4
	.word L8031BBE8

glabel D_80337CF0
	.double 32512.0

glabel D_80337CF8
	.double 127.0

.text
glabel func_8031B0A4
/* 0D60A4 8031B0A4 27BDFFA0 */  addiu $sp, $sp, -0x60
/* 0D60A8 8031B0A8 240E0001 */  li    $t6, 1
/* 0D60AC 8031B0AC AFBF001C */  sw    $ra, 0x1c($sp)
/* 0D60B0 8031B0B0 AFB00018 */  sw    $s0, 0x18($sp)
/* 0D60B4 8031B0B4 A3AE003F */  sb    $t6, 0x3f($sp)
/* 0D60B8 8031B0B8 8C820000 */  lw    $v0, ($a0)
/* 0D60BC 8031B0BC 00808025 */  move  $s0, $a0
/* 0D60C0 8031B0C0 00027FC2 */  srl   $t7, $v0, 0x1f
/* 0D60C4 8031B0C4 51E00376 */  beql  $t7, $zero, .L8031BEA0
/* 0D60C8 8031B0C8 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0D60CC 8031B0CC 8483003C */  lh    $v1, 0x3c($a0)
/* 0D60D0 8031B0D0 00027080 */  sll   $t6, $v0, 2
/* 0D60D4 8031B0D4 0002C8C0 */  sll   $t9, $v0, 3
/* 0D60D8 8031B0D8 28610002 */  slti  $at, $v1, 2
/* 0D60DC 8031B0DC 1420000E */  bnez  $at, .L8031B118
/* 0D60E0 8031B0E0 2478FFFF */   addiu $t8, $v1, -1
/* 0D60E4 8031B0E4 05C0036D */  bltz  $t6, .L8031BE9C
/* 0D60E8 8031B0E8 A498003C */   sh    $t8, 0x3c($a0)
/* 0D60EC 8031B0EC 848F003E */  lh    $t7, 0x3e($a0)
/* 0D60F0 8031B0F0 8498003C */  lh    $t8, 0x3c($a0)
/* 0D60F4 8031B0F4 01F8082A */  slt   $at, $t7, $t8
/* 0D60F8 8031B0F8 54200369 */  bnezl $at, .L8031BEA0
/* 0D60FC 8031B0FC 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0D6100 8031B100 0C0C63B1 */  jal   func_80318EC4
/* 0D6104 8031B104 00000000 */   nop   
/* 0D6108 8031B108 920E0000 */  lbu   $t6, ($s0)
/* 0D610C 8031B10C 35CF0020 */  ori   $t7, $t6, 0x20
/* 0D6110 8031B110 10000362 */  b     .L8031BE9C
/* 0D6114 8031B114 A20F0000 */   sb    $t7, ($s0)
.L8031B118:
/* 0D6118 8031B118 07220004 */  bltzl $t9, .L8031B12C
/* 0D611C 8031B11C 92020004 */   lbu   $v0, 4($s0)
/* 0D6120 8031B120 0C0C63B1 */  jal   func_80318EC4
/* 0D6124 8031B124 02002025 */   move  $a0, $s0
/* 0D6128 8031B128 92020004 */  lbu   $v0, 4($s0)
.L8031B12C:
/* 0D612C 8031B12C 2401FF7F */  li    $at, -129
/* 0D6130 8031B130 44800000 */  mtc1  $zero, $f0
/* 0D6134 8031B134 00417024 */  and   $t6, $v0, $at
/* 0D6138 8031B138 24010001 */  li    $at, 1
/* 0D613C 8031B13C 11C10004 */  beq   $t6, $at, .L8031B150
/* 0D6140 8031B140 3C1F8022 */   lui   $ra, %hi(D_80226D60) # $ra, 0x8022
/* 0D6144 8031B144 24010002 */  li    $at, 2
/* 0D6148 8031B148 55C10003 */  bnel  $t6, $at, .L8031B158
/* 0D614C 8031B14C 8E0D0050 */   lw    $t5, 0x50($s0)
.L8031B150:
/* 0D6150 8031B150 A2000004 */  sb    $zero, 4($s0)
/* 0D6154 8031B154 8E0D0050 */  lw    $t5, 0x50($s0)
.L8031B158:
/* 0D6158 8031B158 3C013F80 */  lui   $at, 0x3f80
/* 0D615C 8031B15C 3C0B8022 */  lui   $t3, %hi(D_802214F8) 
/* 0D6160 8031B160 44810800 */  mtc1  $at, $f1
/* 0D6164 8031B164 256B14F8 */  addiu $t3, $t3, %lo(D_802214F8)
/* 0D6168 8031B168 27FF6D60 */  addiu $ra, %lo(D_80226D60) # addiu $ra, $ra, 0x6d60
/* 0D616C 8031B16C 97AA003A */  lhu   $t2, 0x3a($sp)
/* 0D6170 8031B170 240900FF */  li    $t1, 255
/* 0D6174 8031B174 8DAC0040 */  lw    $t4, 0x40($t5)
.L8031B178:
/* 0D6178 8031B178 8E020054 */  lw    $v0, 0x54($s0)
.L8031B17C:
/* 0D617C 8031B17C 244F0001 */  addiu $t7, $v0, 1
/* 0D6180 8031B180 AE0F0054 */  sw    $t7, 0x54($s0)
/* 0D6184 8031B184 90440000 */  lbu   $a0, ($v0)
/* 0D6188 8031B188 288100C1 */  slti  $at, $a0, 0xc1
/* 0D618C 8031B18C 14200159 */  bnez  $at, .L8031B6F4
/* 0D6190 8031B190 00802825 */   move  $a1, $a0
/* 0D6194 8031B194 288100CB */  slti  $at, $a0, 0xcb
/* 0D6198 8031B198 1420000A */  bnez  $at, .L8031B1C4
/* 0D619C 8031B19C 24B9FF3F */   addiu $t9, $a1, -0xc1
/* 0D61A0 8031B1A0 2498FF09 */  addiu $t8, $a0, -0xf7
/* 0D61A4 8031B1A4 2F010009 */  sltiu $at, $t8, 9
/* 0D61A8 8031B1A8 10200139 */  beqz  $at, .L8031B690
/* 0D61AC 8031B1AC 0018C080 */   sll   $t8, $t8, 2
/* 0D61B0 8031B1B0 3C018033 */  lui   $at, %hi(jtbl_80337C90)
/* 0D61B4 8031B1B4 00380821 */  addu  $at, $at, $t8
/* 0D61B8 8031B1B8 8C387C90 */  lw    $t8, %lo(jtbl_80337C90)($at)
/* 0D61BC 8031B1BC 03000008 */  jr    $t8
/* 0D61C0 8031B1C0 00000000 */   nop   
.L8031B1C4:
/* 0D61C4 8031B1C4 2F21000A */  sltiu $at, $t9, 0xa
/* 0D61C8 8031B1C8 10200131 */  beqz  $at, .L8031B690
/* 0D61CC 8031B1CC 0019C880 */   sll   $t9, $t9, 2
/* 0D61D0 8031B1D0 3C018033 */  lui   $at, %hi(jtbl_80337CB4)
/* 0D61D4 8031B1D4 00390821 */  addu  $at, $at, $t9
/* 0D61D8 8031B1D8 8C397CB4 */  lw    $t9, %lo(jtbl_80337CB4)($at)
/* 0D61DC 8031B1DC 03200008 */  jr    $t9
/* 0D61E0 8031B1E0 00000000 */   nop   
glabel L8031B1E4
/* 0D61E4 8031B1E4 26020054 */  addiu $v0, $s0, 0x54
/* 0D61E8 8031B1E8 90430018 */  lbu   $v1, 0x18($v0)
/* 0D61EC 8031B1EC 14600005 */  bnez  $v1, .L8031B204
/* 0D61F0 8031B1F0 246EFFFF */   addiu $t6, $v1, -1
/* 0D61F4 8031B1F4 0C0C6A84 */  jal   func_8031AA10
/* 0D61F8 8031B1F8 02002025 */   move  $a0, $s0
/* 0D61FC 8031B1FC 10000328 */  b     .L8031BEA0
/* 0D6200 8031B200 8FBF001C */   lw    $ra, 0x1c($sp)
.L8031B204:
/* 0D6204 8031B204 31CF00FF */  andi  $t7, $t6, 0xff
/* 0D6208 8031B208 000FC080 */  sll   $t8, $t7, 2
/* 0D620C 8031B20C 0058C821 */  addu  $t9, $v0, $t8
/* 0D6210 8031B210 A04E0018 */  sb    $t6, 0x18($v0)
/* 0D6214 8031B214 8F2E0004 */  lw    $t6, 4($t9)
/* 0D6218 8031B218 1000FFD7 */  b     .L8031B178
/* 0D621C 8031B21C AC4E0000 */   sw    $t6, ($v0)
glabel L8031B220
/* 0D6220 8031B220 26020054 */  addiu $v0, $s0, 0x54
/* 0D6224 8031B224 8C430000 */  lw    $v1, ($v0)
/* 0D6228 8031B228 90640000 */  lbu   $a0, ($v1)
/* 0D622C 8031B22C 246E0001 */  addiu $t6, $v1, 1
/* 0D6230 8031B230 AC4E0000 */  sw    $t6, ($v0)
/* 0D6234 8031B234 91CF0000 */  lbu   $t7, ($t6)
/* 0D6238 8031B238 0004CA00 */  sll   $t9, $a0, 8
/* 0D623C 8031B23C 01F92825 */  or    $a1, $t7, $t9
/* 0D6240 8031B240 904F0018 */  lbu   $t7, 0x18($v0)
/* 0D6244 8031B244 25D90001 */  addiu $t9, $t6, 1
/* 0D6248 8031B248 AC590000 */  sw    $t9, ($v0)
/* 0D624C 8031B24C 25F80001 */  addiu $t8, $t7, 1
/* 0D6250 8031B250 330E00FF */  andi  $t6, $t8, 0xff
/* 0D6254 8031B254 000E7880 */  sll   $t7, $t6, 2
/* 0D6258 8031B258 A0580018 */  sb    $t8, 0x18($v0)
/* 0D625C 8031B25C 004FC021 */  addu  $t8, $v0, $t7
/* 0D6260 8031B260 AF190000 */  sw    $t9, ($t8)
/* 0D6264 8031B264 8D8E0014 */  lw    $t6, 0x14($t4)
/* 0D6268 8031B268 30AFFFFF */  andi  $t7, $a1, 0xffff
/* 0D626C 8031B26C 30AAFFFF */  andi  $t2, $a1, 0xffff
/* 0D6270 8031B270 01CFC821 */  addu  $t9, $t6, $t7
/* 0D6274 8031B274 1000FFC0 */  b     .L8031B178
/* 0D6278 8031B278 AC590000 */   sw    $t9, ($v0)
glabel L8031B27C
/* 0D627C 8031B27C 26020054 */  addiu $v0, $s0, 0x54
/* 0D6280 8031B280 8C430000 */  lw    $v1, ($v0)
/* 0D6284 8031B284 904E0018 */  lbu   $t6, 0x18($v0)
/* 0D6288 8031B288 24780001 */  addiu $t8, $v1, 1
/* 0D628C 8031B28C AC580000 */  sw    $t8, ($v0)
/* 0D6290 8031B290 90650000 */  lbu   $a1, ($v1)
/* 0D6294 8031B294 004E7821 */  addu  $t7, $v0, $t6
/* 0D6298 8031B298 A1E50014 */  sb    $a1, 0x14($t7)
/* 0D629C 8031B29C 90590018 */  lbu   $t9, 0x18($v0)
/* 0D62A0 8031B2A0 8C4E0000 */  lw    $t6, ($v0)
/* 0D62A4 8031B2A4 27380001 */  addiu $t8, $t9, 1
/* 0D62A8 8031B2A8 330F00FF */  andi  $t7, $t8, 0xff
/* 0D62AC 8031B2AC 000FC880 */  sll   $t9, $t7, 2
/* 0D62B0 8031B2B0 A0580018 */  sb    $t8, 0x18($v0)
/* 0D62B4 8031B2B4 0059C021 */  addu  $t8, $v0, $t9
/* 0D62B8 8031B2B8 1000FFAF */  b     .L8031B178
/* 0D62BC 8031B2BC AF0E0000 */   sw    $t6, ($t8)
glabel L8031B2C0
/* 0D62C0 8031B2C0 26020054 */  addiu $v0, $s0, 0x54
/* 0D62C4 8031B2C4 904F0018 */  lbu   $t7, 0x18($v0)
/* 0D62C8 8031B2C8 004F2021 */  addu  $a0, $v0, $t7
/* 0D62CC 8031B2CC 90990013 */  lbu   $t9, 0x13($a0)
/* 0D62D0 8031B2D0 272EFFFF */  addiu $t6, $t9, -1
/* 0D62D4 8031B2D4 A08E0013 */  sb    $t6, 0x13($a0)
/* 0D62D8 8031B2D8 90430018 */  lbu   $v1, 0x18($v0)
/* 0D62DC 8031B2DC 0043C021 */  addu  $t8, $v0, $v1
/* 0D62E0 8031B2E0 930F0013 */  lbu   $t7, 0x13($t8)
/* 0D62E4 8031B2E4 00602825 */  move  $a1, $v1
/* 0D62E8 8031B2E8 0005C880 */  sll   $t9, $a1, 2
/* 0D62EC 8031B2EC 11E00004 */  beqz  $t7, .L8031B300
/* 0D62F0 8031B2F0 00597021 */   addu  $t6, $v0, $t9
/* 0D62F4 8031B2F4 8DD80000 */  lw    $t8, ($t6)
/* 0D62F8 8031B2F8 1000FF9F */  b     .L8031B178
/* 0D62FC 8031B2FC AC580000 */   sw    $t8, ($v0)
.L8031B300:
/* 0D6300 8031B300 246FFFFF */  addiu $t7, $v1, -1
/* 0D6304 8031B304 1000FF9C */  b     .L8031B178
/* 0D6308 8031B308 A04F0018 */   sb    $t7, 0x18($v0)
glabel L8031B30C
/* 0D630C 8031B30C 26020054 */  addiu $v0, $s0, 0x54
/* 0D6310 8031B310 8C430000 */  lw    $v1, ($v0)
/* 0D6314 8031B314 90640000 */  lbu   $a0, ($v1)
/* 0D6318 8031B318 246F0001 */  addiu $t7, $v1, 1
/* 0D631C 8031B31C AC4F0000 */  sw    $t7, ($v0)
/* 0D6320 8031B320 91F90000 */  lbu   $t9, ($t7)
/* 0D6324 8031B324 0004C200 */  sll   $t8, $a0, 8
/* 0D6328 8031B328 25EF0001 */  addiu $t7, $t7, 1
/* 0D632C 8031B32C 03387025 */  or    $t6, $t9, $t8
/* 0D6330 8031B330 AC4F0000 */  sw    $t7, ($v0)
/* 0D6334 8031B334 8D990014 */  lw    $t9, 0x14($t4)
/* 0D6338 8031B338 01C0C025 */  move  $t8, $t6
/* 0D633C 8031B33C 330AFFFF */  andi  $t2, $t8, 0xffff
/* 0D6340 8031B340 330EFFFF */  andi  $t6, $t8, 0xffff
/* 0D6344 8031B344 032EC021 */  addu  $t8, $t9, $t6
/* 0D6348 8031B348 1000FF8B */  b     .L8031B178
/* 0D634C 8031B34C AC580000 */   sw    $t8, ($v0)
glabel L8031B350
/* 0D6350 8031B350 26020054 */  addiu $v0, $s0, 0x54
/* 0D6354 8031B354 8C430000 */  lw    $v1, ($v0)
/* 0D6358 8031B358 240100C1 */  li    $at, 193
/* 0D635C 8031B35C 90640000 */  lbu   $a0, ($v1)
/* 0D6360 8031B360 246F0001 */  addiu $t7, $v1, 1
/* 0D6364 8031B364 14A10008 */  bne   $a1, $at, .L8031B388
/* 0D6368 8031B368 AC4F0000 */   sw    $t7, ($v0)
/* 0D636C 8031B36C 00840019 */  multu $a0, $a0
/* 0D6370 8031B370 0000C812 */  mflo  $t9
/* 0D6374 8031B374 44992000 */  mtc1  $t9, $f4
/* 0D6378 8031B378 00000000 */  nop   
/* 0D637C 8031B37C 468021A0 */  cvt.s.w $f6, $f4
/* 0D6380 8031B380 1000FF7D */  b     .L8031B178
/* 0D6384 8031B384 E6060024 */   swc1  $f6, 0x24($s0)
.L8031B388:
/* 0D6388 8031B388 44844000 */  mtc1  $a0, $f8
/* 0D638C 8031B38C 00000000 */  nop   
/* 0D6390 8031B390 468042A0 */  cvt.s.w $f10, $f8
/* 0D6394 8031B394 46005421 */  cvt.d.s $f16, $f10
/* 0D6398 8031B398 46208482 */  mul.d $f18, $f16, $f0
/* 0D639C 8031B39C 46209120 */  cvt.s.d $f4, $f18
/* 0D63A0 8031B3A0 1000FF75 */  b     .L8031B178
/* 0D63A4 8031B3A4 E6040028 */   swc1  $f4, 0x28($s0)
glabel L8031B3A8
/* 0D63A8 8031B3A8 26020054 */  addiu $v0, $s0, 0x54
/* 0D63AC 8031B3AC 8C430000 */  lw    $v1, ($v0)
/* 0D63B0 8031B3B0 240100C9 */  li    $at, 201
/* 0D63B4 8031B3B4 90640000 */  lbu   $a0, ($v1)
/* 0D63B8 8031B3B8 246E0001 */  addiu $t6, $v1, 1
/* 0D63BC 8031B3BC 14A10003 */  bne   $a1, $at, .L8031B3CC
/* 0D63C0 8031B3C0 AC4E0000 */   sw    $t6, ($v0)
/* 0D63C4 8031B3C4 1000FF6C */  b     .L8031B178
/* 0D63C8 8031B3C8 A2040002 */   sb    $a0, 2($s0)
.L8031B3CC:
/* 0D63CC 8031B3CC 1000FF6A */  b     .L8031B178
/* 0D63D0 8031B3D0 A604001E */   sh    $a0, 0x1e($s0)
glabel L8031B3D4
/* 0D63D4 8031B3D4 240100C4 */  li    $at, 196
/* 0D63D8 8031B3D8 14A10003 */  bne   $a1, $at, .L8031B3E8
/* 0D63DC 8031B3DC 02002025 */   move  $a0, $s0
/* 0D63E0 8031B3E0 10000002 */  b     .L8031B3EC
/* 0D63E4 8031B3E4 24020001 */   li    $v0, 1
.L8031B3E8:
/* 0D63E8 8031B3E8 00001025 */  move  $v0, $zero
.L8031B3EC:
/* 0D63EC 8031B3EC 920E0000 */  lbu   $t6, ($s0)
/* 0D63F0 8031B3F0 00027900 */  sll   $t7, $v0, 4
/* 0D63F4 8031B3F4 31F90010 */  andi  $t9, $t7, 0x10
/* 0D63F8 8031B3F8 31D8FFEF */  andi  $t8, $t6, 0xffef
/* 0D63FC 8031B3FC 03387825 */  or    $t7, $t9, $t8
/* 0D6400 8031B400 A20F0000 */  sb    $t7, ($s0)
/* 0D6404 8031B404 AFAD0058 */  sw    $t5, 0x58($sp)
/* 0D6408 8031B408 AFAC005C */  sw    $t4, 0x5c($sp)
/* 0D640C 8031B40C 0C0C63B1 */  jal   func_80318EC4
/* 0D6410 8031B410 A7AA003A */   sh    $t2, 0x3a($sp)
/* 0D6414 8031B414 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0D6418 8031B418 44810800 */  mtc1  $at, $f1
/* 0D641C 8031B41C 3C0B8022 */  lui   $t3, %hi(D_802214F8) # $t3, 0x8022
/* 0D6420 8031B420 3C1F8022 */  lui   $ra, %hi(D_80226D60) 
/* 0D6424 8031B424 44800000 */  mtc1  $zero, $f0
/* 0D6428 8031B428 27FF6D60 */  addiu $ra, $ra, %lo(D_80226D60)
/* 0D642C 8031B42C 256B14F8 */  addiu $t3, %lo(D_802214F8) # addiu $t3, $t3, 0x14f8
/* 0D6430 8031B430 240900FF */  li    $t1, 255
/* 0D6434 8031B434 97AA003A */  lhu   $t2, 0x3a($sp)
/* 0D6438 8031B438 8FAC005C */  lw    $t4, 0x5c($sp)
/* 0D643C 8031B43C 1000FF4E */  b     .L8031B178
/* 0D6440 8031B440 8FAD0058 */   lw    $t5, 0x58($sp)
glabel L8031B444
/* 0D6444 8031B444 26020054 */  addiu $v0, $s0, 0x54
/* 0D6448 8031B448 8C430000 */  lw    $v1, ($v0)
/* 0D644C 8031B44C 90640000 */  lbu   $a0, ($v1)
/* 0D6450 8031B450 246E0001 */  addiu $t6, $v1, 1
/* 0D6454 8031B454 AC4E0000 */  sw    $t6, ($v0)
/* 0D6458 8031B458 30990080 */  andi  $t9, $a0, 0x80
/* 0D645C 8031B45C 1320000A */  beqz  $t9, .L8031B488
/* 0D6460 8031B460 00802825 */   move  $a1, $a0
/* 0D6464 8031B464 01C01825 */  move  $v1, $t6
/* 0D6468 8031B468 91CE0000 */  lbu   $t6, ($t6)
/* 0D646C 8031B46C 00052200 */  sll   $a0, $a1, 8
/* 0D6470 8031B470 308F7F00 */  andi  $t7, $a0, 0x7f00
/* 0D6474 8031B474 01CF2025 */  or    $a0, $t6, $t7
/* 0D6478 8031B478 3085FFFF */  andi  $a1, $a0, 0xffff
/* 0D647C 8031B47C 24780001 */  addiu $t8, $v1, 1
/* 0D6480 8031B480 AC580000 */  sw    $t8, ($v0)
/* 0D6484 8031B484 00A02025 */  move  $a0, $a1
.L8031B488:
/* 0D6488 8031B488 308AFFFF */  andi  $t2, $a0, 0xffff
/* 0D648C 8031B48C 1000FF3A */  b     .L8031B178
/* 0D6490 8031B490 A6050038 */   sh    $a1, 0x38($s0)
glabel L8031B494
/* 0D6494 8031B494 26020054 */  addiu $v0, $s0, 0x54
/* 0D6498 8031B498 8C430000 */  lw    $v1, ($v0)
/* 0D649C 8031B49C 246F0001 */  addiu $t7, $v1, 1
/* 0D64A0 8031B4A0 AC4F0000 */  sw    $t7, ($v0)
/* 0D64A4 8031B4A4 90650000 */  lbu   $a1, ($v1)
/* 0D64A8 8031B4A8 28A1007F */  slti  $at, $a1, 0x7f
/* 0D64AC 8031B4AC 5020FF33 */  beql  $at, $zero, .L8031B17C
/* 0D64B0 8031B4B0 8E020054 */   lw    $v0, 0x54($s0)
/* 0D64B4 8031B4B4 91B90005 */  lbu   $t9, 5($t5)
/* 0D64B8 8031B4B8 8FEE0000 */  lw    $t6, ($ra)
/* 0D64BC 8031B4BC 30A200FF */  andi  $v0, $a1, 0xff
/* 0D64C0 8031B4C0 0019C080 */  sll   $t8, $t9, 2
/* 0D64C4 8031B4C4 0319C023 */  subu  $t8, $t8, $t9
/* 0D64C8 8031B4C8 0018C080 */  sll   $t8, $t8, 2
/* 0D64CC 8031B4CC 01D83821 */  addu  $a3, $t6, $t8
/* 0D64D0 8031B4D0 90E30001 */  lbu   $v1, 1($a3)
/* 0D64D4 8031B4D4 00A3082A */  slt   $at, $a1, $v1
/* 0D64D8 8031B4D8 54200008 */  bnezl $at, .L8031B4FC
/* 0D64DC 8031B4DC 8CE30004 */   lw    $v1, 4($a3)
/* 0D64E0 8031B4E0 306200FF */  andi  $v0, $v1, 0xff
/* 0D64E4 8031B4E4 5040FF25 */  beql  $v0, $zero, .L8031B17C
/* 0D64E8 8031B4E8 8E020054 */   lw    $v0, 0x54($s0)
/* 0D64EC 8031B4EC 2442FFFF */  addiu $v0, $v0, -1
/* 0D64F0 8031B4F0 304F00FF */  andi  $t7, $v0, 0xff
/* 0D64F4 8031B4F4 01E01025 */  move  $v0, $t7
/* 0D64F8 8031B4F8 8CE30004 */  lw    $v1, 4($a3)
.L8031B4FC:
/* 0D64FC 8031B4FC 0002C880 */  sll   $t9, $v0, 2
/* 0D6500 8031B500 26050048 */  addiu $a1, $s0, 0x48
/* 0D6504 8031B504 00797021 */  addu  $t6, $v1, $t9
/* 0D6508 8031B508 8DC40000 */  lw    $a0, ($t6)
/* 0D650C 8031B50C 5480000C */  bnezl $a0, .L8031B540
/* 0D6510 8031B510 8D630004 */   lw    $v1, 4($t3)
/* 0D6514 8031B514 11220009 */  beq   $t1, $v0, .L8031B53C
.L8031B518:
/* 0D6518 8031B518 0002C080 */   sll   $t8, $v0, 2
/* 0D651C 8031B51C 00787821 */  addu  $t7, $v1, $t8
/* 0D6520 8031B520 8DE40000 */  lw    $a0, ($t7)
/* 0D6524 8031B524 54800006 */  bnezl $a0, .L8031B540
/* 0D6528 8031B528 8D630004 */   lw    $v1, 4($t3)
/* 0D652C 8031B52C 2442FFFF */  addiu $v0, $v0, -1
/* 0D6530 8031B530 305900FF */  andi  $t9, $v0, 0xff
/* 0D6534 8031B534 1539FFF8 */  bne   $t1, $t9, .L8031B518
/* 0D6538 8031B538 03201025 */   move  $v0, $t9
.L8031B53C:
/* 0D653C 8031B53C 8D630004 */  lw    $v1, 4($t3)
.L8031B540:
/* 0D6540 8031B540 0083082B */  sltu  $at, $a0, $v1
/* 0D6544 8031B544 54200007 */  bnezl $at, .L8031B564
/* 0D6548 8031B548 8D630198 */   lw    $v1, 0x198($t3)
/* 0D654C 8031B54C 8D6E000C */  lw    $t6, 0xc($t3)
/* 0D6550 8031B550 006EC021 */  addu  $t8, $v1, $t6
/* 0D6554 8031B554 0304082B */  sltu  $at, $t8, $a0
/* 0D6558 8031B558 5020000B */  beql  $at, $zero, .L8031B588
/* 0D655C 8031B55C 8C8E0004 */   lw    $t6, 4($a0)
/* 0D6560 8031B560 8D630198 */  lw    $v1, 0x198($t3)
.L8031B564:
/* 0D6564 8031B564 0083082B */  sltu  $at, $a0, $v1
/* 0D6568 8031B568 5420000E */  bnezl $at, .L8031B5A4
/* 0D656C 8031B56C 3C010002 */   lui   $at, 2
/* 0D6570 8031B570 8D6F01A0 */  lw    $t7, 0x1a0($t3)
/* 0D6574 8031B574 006FC821 */  addu  $t9, $v1, $t7
/* 0D6578 8031B578 0324082B */  sltu  $at, $t9, $a0
/* 0D657C 8031B57C 54200009 */  bnezl $at, .L8031B5A4
/* 0D6580 8031B580 3C010002 */   lui   $at, 2
/* 0D6584 8031B584 8C8E0004 */  lw    $t6, 4($a0)
.L8031B588:
/* 0D6588 8031B588 26020014 */  addiu $v0, $s0, 0x14
/* 0D658C 8031B58C AC4E0004 */  sw    $t6, 4($v0)
/* 0D6590 8031B590 90980003 */  lbu   $t8, 3($a0)
/* 0D6594 8031B594 A0580000 */  sb    $t8, ($v0)
/* 0D6598 8031B598 1000FEF7 */  b     .L8031B178
/* 0D659C 8031B59C ACA40000 */   sw    $a0, ($a1)
/* 0D65A0 8031B5A0 3C010002 */  lui   $at, 2
.L8031B5A4:
/* 0D65A4 8031B5A4 00417821 */  addu  $t7, $v0, $at
/* 0D65A8 8031B5A8 3C018033 */  lui   $at, %hi(D_80331D40) # $at, 0x8033
/* 0D65AC 8031B5AC AC2F1D40 */  sw    $t7, %lo(D_80331D40)($at)
/* 0D65B0 8031B5B0 1000FEF1 */  b     .L8031B178
/* 0D65B4 8031B5B4 ACA00000 */   sw    $zero, ($a1)
glabel L8031B5B8
/* 0D65B8 8031B5B8 26020054 */  addiu $v0, $s0, 0x54
/* 0D65BC 8031B5BC 8C430000 */  lw    $v1, ($v0)
/* 0D65C0 8031B5C0 24790001 */  addiu $t9, $v1, 1
/* 0D65C4 8031B5C4 AC590000 */  sw    $t9, ($v0)
/* 0D65C8 8031B5C8 90650000 */  lbu   $a1, ($v1)
/* 0D65CC 8031B5CC A2050004 */  sb    $a1, 4($s0)
/* 0D65D0 8031B5D0 8C430000 */  lw    $v1, ($v0)
/* 0D65D4 8031B5D4 246E0001 */  addiu $t6, $v1, 1
/* 0D65D8 8031B5D8 AC4E0000 */  sw    $t6, ($v0)
/* 0D65DC 8031B5DC 85B8001A */  lh    $t8, 0x1a($t5)
/* 0D65E0 8031B5E0 90670000 */  lbu   $a3, ($v1)
/* 0D65E4 8031B5E4 8619001E */  lh    $t9, 0x1e($s0)
/* 0D65E8 8031B5E8 03077821 */  addu  $t7, $t8, $a3
/* 0D65EC 8031B5EC 85980010 */  lh    $t8, 0x10($t4)
/* 0D65F0 8031B5F0 01F97021 */  addu  $t6, $t7, $t9
/* 0D65F4 8031B5F4 01D84021 */  addu  $t0, $t6, $t8
/* 0D65F8 8031B5F8 310F00FF */  andi  $t7, $t0, 0xff
/* 0D65FC 8031B5FC 29E10080 */  slti  $at, $t7, 0x80
/* 0D6600 8031B600 14200002 */  bnez  $at, .L8031B60C
/* 0D6604 8031B604 01E04025 */   move  $t0, $t7
/* 0D6608 8031B608 00004025 */  move  $t0, $zero
.L8031B60C:
/* 0D660C 8031B60C 92190004 */  lbu   $t9, 4($s0)
/* 0D6610 8031B610 A2080003 */  sb    $t0, 3($s0)
/* 0D6614 8031B614 332E0080 */  andi  $t6, $t9, 0x80
/* 0D6618 8031B618 51C00009 */  beql  $t6, $zero, .L8031B640
/* 0D661C 8031B61C 8C430000 */   lw    $v1, ($v0)
/* 0D6620 8031B620 8C580000 */  lw    $t8, ($v0)
/* 0D6624 8031B624 930F0000 */  lbu   $t7, ($t8)
/* 0D6628 8031B628 A60F001C */  sh    $t7, 0x1c($s0)
/* 0D662C 8031B62C 8C590000 */  lw    $t9, ($v0)
/* 0D6630 8031B630 272E0001 */  addiu $t6, $t9, 1
/* 0D6634 8031B634 1000FED0 */  b     .L8031B178
/* 0D6638 8031B638 AC4E0000 */   sw    $t6, ($v0)
/* 0D663C 8031B63C 8C430000 */  lw    $v1, ($v0)
.L8031B640:
/* 0D6640 8031B640 90640000 */  lbu   $a0, ($v1)
/* 0D6644 8031B644 24780001 */  addiu $t8, $v1, 1
/* 0D6648 8031B648 AC580000 */  sw    $t8, ($v0)
/* 0D664C 8031B64C 308F0080 */  andi  $t7, $a0, 0x80
/* 0D6650 8031B650 11E0000A */  beqz  $t7, .L8031B67C
/* 0D6654 8031B654 00802825 */   move  $a1, $a0
/* 0D6658 8031B658 03001825 */  move  $v1, $t8
/* 0D665C 8031B65C 93180000 */  lbu   $t8, ($t8)
/* 0D6660 8031B660 00052200 */  sll   $a0, $a1, 8
/* 0D6664 8031B664 308E7F00 */  andi  $t6, $a0, 0x7f00
/* 0D6668 8031B668 030E2025 */  or    $a0, $t8, $t6
/* 0D666C 8031B66C 308FFFFF */  andi  $t7, $a0, 0xffff
/* 0D6670 8031B670 24790001 */  addiu $t9, $v1, 1
/* 0D6674 8031B674 AC590000 */  sw    $t9, ($v0)
/* 0D6678 8031B678 01E02025 */  move  $a0, $t7
.L8031B67C:
/* 0D667C 8031B67C 308AFFFF */  andi  $t2, $a0, 0xffff
/* 0D6680 8031B680 1000FEBD */  b     .L8031B178
/* 0D6684 8031B684 A604001C */   sh    $a0, 0x1c($s0)
glabel L8031B688
/* 0D6688 8031B688 1000FEBB */  b     .L8031B178
/* 0D668C 8031B68C A2000004 */   sb    $zero, 4($s0)
.L8031B690:
glabel L8031B690
/* 0D6690 8031B690 30A200F0 */  andi  $v0, $a1, 0xf0
/* 0D6694 8031B694 240100D0 */  li    $at, 208
/* 0D6698 8031B698 10410005 */  beq   $v0, $at, .L8031B6B0
/* 0D669C 8031B69C 240100E0 */   li    $at, 224
/* 0D66A0 8031B6A0 5041000F */  beql  $v0, $at, .L8031B6E0
/* 0D66A4 8031B6A4 8D8E008C */   lw    $t6, 0x8c($t4)
/* 0D66A8 8031B6A8 1000FEB4 */  b     .L8031B17C
/* 0D66AC 8031B6AC 8E020054 */   lw    $v0, 0x54($s0)
.L8031B6B0:
/* 0D66B0 8031B6B0 8D8E0088 */  lw    $t6, 0x88($t4)
/* 0D66B4 8031B6B4 30B8000F */  andi  $t8, $a1, 0xf
/* 0D66B8 8031B6B8 01D87821 */  addu  $t7, $t6, $t8
/* 0D66BC 8031B6BC 91EA0000 */  lbu   $t2, ($t7)
/* 0D66C0 8031B6C0 014A0019 */  multu $t2, $t2
/* 0D66C4 8031B6C4 0000C812 */  mflo  $t9
/* 0D66C8 8031B6C8 44993000 */  mtc1  $t9, $f6
/* 0D66CC 8031B6CC 00000000 */  nop   
/* 0D66D0 8031B6D0 46803220 */  cvt.s.w $f8, $f6
/* 0D66D4 8031B6D4 1000FEA8 */  b     .L8031B178
/* 0D66D8 8031B6D8 E6080024 */   swc1  $f8, 0x24($s0)
/* 0D66DC 8031B6DC 8D8E008C */  lw    $t6, 0x8c($t4)
.L8031B6E0:
/* 0D66E0 8031B6E0 30B8000F */  andi  $t8, $a1, 0xf
/* 0D66E4 8031B6E4 01D87821 */  addu  $t7, $t6, $t8
/* 0D66E8 8031B6E8 91F90000 */  lbu   $t9, ($t7)
/* 0D66EC 8031B6EC 1000FEA2 */  b     .L8031B178
/* 0D66F0 8031B6F0 A2190002 */   sb    $t9, 2($s0)
.L8031B6F4:
/* 0D66F4 8031B6F4 240100C0 */  li    $at, 192
/* 0D66F8 8031B6F8 14A10015 */  bne   $a1, $at, .L8031B750
/* 0D66FC 8031B6FC 26020054 */   addiu $v0, $s0, 0x54
/* 0D6700 8031B700 8C430000 */  lw    $v1, ($v0)
/* 0D6704 8031B704 90640000 */  lbu   $a0, ($v1)
/* 0D6708 8031B708 246E0001 */  addiu $t6, $v1, 1
/* 0D670C 8031B70C AC4E0000 */  sw    $t6, ($v0)
/* 0D6710 8031B710 30980080 */  andi  $t8, $a0, 0x80
/* 0D6714 8031B714 13000009 */  beqz  $t8, .L8031B73C
/* 0D6718 8031B718 00802825 */   move  $a1, $a0
/* 0D671C 8031B71C 01C01825 */  move  $v1, $t6
/* 0D6720 8031B720 91CE0000 */  lbu   $t6, ($t6)
/* 0D6724 8031B724 00042200 */  sll   $a0, $a0, 8
/* 0D6728 8031B728 30997F00 */  andi  $t9, $a0, 0x7f00
/* 0D672C 8031B72C 246F0001 */  addiu $t7, $v1, 1
/* 0D6730 8031B730 01D92025 */  or    $a0, $t6, $t9
/* 0D6734 8031B734 3085FFFF */  andi  $a1, $a0, 0xffff
/* 0D6738 8031B738 AC4F0000 */  sw    $t7, ($v0)
.L8031B73C:
/* 0D673C 8031B73C 920E0000 */  lbu   $t6, ($s0)
/* 0D6740 8031B740 A605003C */  sh    $a1, 0x3c($s0)
/* 0D6744 8031B744 35D80020 */  ori   $t8, $t6, 0x20
/* 0D6748 8031B748 1000019C */  b     .L8031BDBC
/* 0D674C 8031B74C A2180000 */   sb    $t8, ($s0)
.L8031B750:
/* 0D6750 8031B750 920F0000 */  lbu   $t7, ($s0)
/* 0D6754 8031B754 24010001 */  li    $at, 1
/* 0D6758 8031B758 30A900C0 */  andi  $t1, $a1, 0xc0
/* 0D675C 8031B75C 31F9FFDF */  andi  $t9, $t7, 0xffdf
/* 0D6760 8031B760 A2190000 */  sb    $t9, ($s0)
/* 0D6764 8031B764 8DAE0000 */  lw    $t6, ($t5)
/* 0D6768 8031B768 000EC180 */  sll   $t8, $t6, 6
/* 0D676C 8031B76C 00187FC2 */  srl   $t7, $t8, 0x1f
/* 0D6770 8031B770 15E10057 */  bne   $t7, $at, .L8031B8D0
/* 0D6774 8031B774 00000000 */   nop   
/* 0D6778 8031B778 30A900C0 */  andi  $t1, $a1, 0xc0
/* 0D677C 8031B77C 11200009 */  beqz  $t1, .L8031B7A4
/* 0D6780 8031B780 26020054 */   addiu $v0, $s0, 0x54
/* 0D6784 8031B784 24010040 */  li    $at, 64
/* 0D6788 8031B788 11210023 */  beq   $t1, $at, .L8031B818
/* 0D678C 8031B78C 26020054 */   addiu $v0, $s0, 0x54
/* 0D6790 8031B790 24010080 */  li    $at, 128
/* 0D6794 8031B794 11210039 */  beq   $t1, $at, .L8031B87C
/* 0D6798 8031B798 26020054 */   addiu $v0, $s0, 0x54
/* 0D679C 8031B79C 10000043 */  b     .L8031B8AC
/* 0D67A0 8031B7A0 01402025 */   move  $a0, $t2
.L8031B7A4:
/* 0D67A4 8031B7A4 8C430000 */  lw    $v1, ($v0)
/* 0D67A8 8031B7A8 90660000 */  lbu   $a2, ($v1)
/* 0D67AC 8031B7AC 24790001 */  addiu $t9, $v1, 1
/* 0D67B0 8031B7B0 AC590000 */  sw    $t9, ($v0)
/* 0D67B4 8031B7B4 30CE0080 */  andi  $t6, $a2, 0x80
/* 0D67B8 8031B7B8 11C0000A */  beqz  $t6, .L8031B7E4
/* 0D67BC 8031B7BC 00C03825 */  or $a3, $a2, $zero
/* 0D67C0 8031B7C0 03201825 */  move  $v1, $t9
/* 0D67C4 8031B7C4 93390000 */  lbu   $t9, ($t9)
/* 0D67C8 8031B7C8 00073200 */  sll   $a2, $a3, 8
/* 0D67CC 8031B7CC 30CF7F00 */  andi  $t7, $a2, 0x7f00
/* 0D67D0 8031B7D0 032F3025 */  or    $a2, $t9, $t7
/* 0D67D4 8031B7D4 30C7FFFF */  andi  $a3, $a2, 0xffff
/* 0D67D8 8031B7D8 24780001 */  addiu $t8, $v1, 1
/* 0D67DC 8031B7DC AC580000 */  sw    $t8, ($v0)
/* 0D67E0 8031B7E0 00E03025 */  move  $a2, $a3
.L8031B7E4:
/* 0D67E4 8031B7E4 8C430000 */  lw    $v1, ($v0)
/* 0D67E8 8031B7E8 30CAFFFF */  andi  $t2, $a2, 0xffff
/* 0D67EC 8031B7EC 01402025 */  move  $a0, $t2
/* 0D67F0 8031B7F0 906B0000 */  lbu   $t3, ($v1)
/* 0D67F4 8031B7F4 246F0001 */  addiu $t7, $v1, 1
/* 0D67F8 8031B7F8 AC4F0000 */  sw    $t7, ($v0)
/* 0D67FC 8031B7FC 91EE0000 */  lbu   $t6, ($t7)
/* 0D6800 8031B800 A20E0002 */  sb    $t6, 2($s0)
/* 0D6804 8031B804 8C580000 */  lw    $t8, ($v0)
/* 0D6808 8031B808 270F0001 */  addiu $t7, $t8, 1
/* 0D680C 8031B80C AC4F0000 */  sw    $t7, ($v0)
/* 0D6810 8031B810 10000027 */  b     .L8031B8B0
/* 0D6814 8031B814 A607003A */   sh    $a3, 0x3a($s0)
.L8031B818:
/* 0D6818 8031B818 8C430000 */  lw    $v1, ($v0)
/* 0D681C 8031B81C 90660000 */  lbu   $a2, ($v1)
/* 0D6820 8031B820 24790001 */  addiu $t9, $v1, 1
/* 0D6824 8031B824 AC590000 */  sw    $t9, ($v0)
/* 0D6828 8031B828 30CE0080 */  andi  $t6, $a2, 0x80
/* 0D682C 8031B82C 11C0000A */  beqz  $t6, .L8031B858
/* 0D6830 8031B830 00C03825 */  or $a3, $a2, $zero
/* 0D6834 8031B834 03201825 */  move  $v1, $t9
/* 0D6838 8031B838 93390000 */  lbu   $t9, ($t9)
/* 0D683C 8031B83C 00073200 */  sll   $a2, $a3, 8
/* 0D6840 8031B840 30CF7F00 */  andi  $t7, $a2, 0x7f00
/* 0D6844 8031B844 032F3025 */  or    $a2, $t9, $t7
/* 0D6848 8031B848 30C7FFFF */  andi  $a3, $a2, 0xffff
/* 0D684C 8031B84C 24780001 */  addiu $t8, $v1, 1
/* 0D6850 8031B850 AC580000 */  sw    $t8, ($v0)
/* 0D6854 8031B854 00E03025 */  move  $a2, $a3
.L8031B858:
/* 0D6858 8031B858 8C430000 */  lw    $v1, ($v0)
/* 0D685C 8031B85C 30CAFFFF */  andi  $t2, $a2, 0xffff
/* 0D6860 8031B860 01402025 */  move  $a0, $t2
/* 0D6864 8031B864 906B0000 */  lbu   $t3, ($v1)
/* 0D6868 8031B868 246F0001 */  addiu $t7, $v1, 1
/* 0D686C 8031B86C AC4F0000 */  sw    $t7, ($v0)
/* 0D6870 8031B870 A2000002 */  sb    $zero, 2($s0)
/* 0D6874 8031B874 1000000E */  b     .L8031B8B0
/* 0D6878 8031B878 A607003A */   sh    $a3, 0x3a($s0)
.L8031B87C:
/* 0D687C 8031B87C 8C430000 */  lw    $v1, ($v0)
/* 0D6880 8031B880 960A003A */  lhu   $t2, 0x3a($s0)
/* 0D6884 8031B884 906B0000 */  lbu   $t3, ($v1)
/* 0D6888 8031B888 24790001 */  addiu $t9, $v1, 1
/* 0D688C 8031B88C AC590000 */  sw    $t9, ($v0)
/* 0D6890 8031B890 93380000 */  lbu   $t8, ($t9)
/* 0D6894 8031B894 01402025 */  move  $a0, $t2
/* 0D6898 8031B898 A2180002 */  sb    $t8, 2($s0)
/* 0D689C 8031B89C 8C4F0000 */  lw    $t7, ($v0)
/* 0D68A0 8031B8A0 25F90001 */  addiu $t9, $t7, 1
/* 0D68A4 8031B8A4 10000002 */  b     .L8031B8B0
/* 0D68A8 8031B8A8 AC590000 */   sw    $t9, ($v0)
.L8031B8AC:
/* 0D68AC 8031B8AC 8FAB0030 */  lw    $t3, 0x30($sp)
.L8031B8B0:
/* 0D68B0 8031B8B0 016B0019 */  multu $t3, $t3
/* 0D68B4 8031B8B4 00A91823 */  subu  $v1, $a1, $t1
/* 0D68B8 8031B8B8 00007012 */  mflo  $t6
/* 0D68BC 8031B8BC 448E5000 */  mtc1  $t6, $f10
/* 0D68C0 8031B8C0 00000000 */  nop   
/* 0D68C4 8031B8C4 46805420 */  cvt.s.w $f16, $f10
/* 0D68C8 8031B8C8 10000024 */  b     .L8031B95C
/* 0D68CC 8031B8CC E6100024 */   swc1  $f16, 0x24($s0)
.L8031B8D0:
/* 0D68D0 8031B8D0 11200008 */  beqz  $t1, .L8031B8F4
/* 0D68D4 8031B8D4 26020054 */   addiu $v0, $s0, 0x54
/* 0D68D8 8031B8D8 24010040 */  li    $at, 64
/* 0D68DC 8031B8DC 11210019 */  beq   $t1, $at, .L8031B944
/* 0D68E0 8031B8E0 24010080 */   li    $at, 128
/* 0D68E4 8031B8E4 5121001B */  beql  $t1, $at, .L8031B954
/* 0D68E8 8031B8E8 960A003A */   lhu   $t2, 0x3a($s0)
/* 0D68EC 8031B8EC 1000001A */  b     .L8031B958
/* 0D68F0 8031B8F0 01402025 */   move  $a0, $t2
.L8031B8F4:
/* 0D68F4 8031B8F4 8C430000 */  lw    $v1, ($v0)
/* 0D68F8 8031B8F8 90660000 */  lbu   $a2, ($v1)
/* 0D68FC 8031B8FC 24780001 */  addiu $t8, $v1, 1
/* 0D6900 8031B900 AC580000 */  sw    $t8, ($v0)
/* 0D6904 8031B904 30CF0080 */  andi  $t7, $a2, 0x80
/* 0D6908 8031B908 11E0000A */  beqz  $t7, .L8031B934
/* 0D690C 8031B90C 00C03825 */  or $a3, $a2, $zero
/* 0D6910 8031B910 03001825 */  move  $v1, $t8
/* 0D6914 8031B914 93180000 */  lbu   $t8, ($t8)
/* 0D6918 8031B918 00073200 */  sll   $a2, $a3, 8
/* 0D691C 8031B91C 30CE7F00 */  andi  $t6, $a2, 0x7f00
/* 0D6920 8031B920 030E3025 */  or    $a2, $t8, $t6
/* 0D6924 8031B924 30C7FFFF */  andi  $a3, $a2, 0xffff
/* 0D6928 8031B928 24790001 */  addiu $t9, $v1, 1
/* 0D692C 8031B92C AC590000 */  sw    $t9, ($v0)
/* 0D6930 8031B930 00E03025 */  move  $a2, $a3
.L8031B934:
/* 0D6934 8031B934 30CAFFFF */  andi  $t2, $a2, 0xffff
/* 0D6938 8031B938 A607003A */  sh    $a3, 0x3a($s0)
/* 0D693C 8031B93C 10000006 */  b     .L8031B958
/* 0D6940 8031B940 01402025 */   move  $a0, $t2
.L8031B944:
/* 0D6944 8031B944 960A0038 */  lhu   $t2, 0x38($s0)
/* 0D6948 8031B948 10000003 */  b     .L8031B958
/* 0D694C 8031B94C 01402025 */   move  $a0, $t2
/* 0D6950 8031B950 960A003A */  lhu   $t2, 0x3a($s0)
.L8031B954:
/* 0D6954 8031B954 01402025 */  move  $a0, $t2
.L8031B958:
/* 0D6958 8031B958 00A91823 */  subu  $v1, $a1, $t1
.L8031B95C:
/* 0D695C 8031B95C 920E0002 */  lbu   $t6, 2($s0)
/* 0D6960 8031B960 A604003C */  sh    $a0, 0x3c($s0)
/* 0D6964 8031B964 01C40019 */  multu $t6, $a0
/* 0D6968 8031B968 0000C012 */  mflo  $t8
/* 0D696C 8031B96C 07010003 */  bgez  $t8, .L8031B97C
/* 0D6970 8031B970 00187A03 */   sra   $t7, $t8, 8
/* 0D6974 8031B974 270100FF */  addiu $at, $t8, 0xff
/* 0D6978 8031B978 00017A03 */  sra   $t7, $at, 8
.L8031B97C:
/* 0D697C 8031B97C A60F003E */  sh    $t7, 0x3e($s0)
/* 0D6980 8031B980 8D990000 */  lw    $t9, ($t4)
/* 0D6984 8031B984 0019C080 */  sll   $t8, $t9, 2
/* 0D6988 8031B988 07030006 */  bgezl $t8, .L8031B9A4
/* 0D698C 8031B98C 8DA20000 */   lw    $v0, ($t5)
/* 0D6990 8031B990 91AF0002 */  lbu   $t7, 2($t5)
/* 0D6994 8031B994 31F90040 */  andi  $t9, $t7, 0x40
/* 0D6998 8031B998 57200008 */  bnezl $t9, .L8031B9BC
/* 0D699C 8031B99C 92180000 */   lbu   $t8, ($s0)
/* 0D69A0 8031B9A0 8DA20000 */  lw    $v0, ($t5)
.L8031B9A4:
/* 0D69A4 8031B9A4 0002C0C0 */  sll   $t8, $v0, 3
/* 0D69A8 8031B9A8 07000003 */  bltz  $t8, .L8031B9B8
/* 0D69AC 8031B9AC 0002C900 */   sll   $t9, $v0, 4
/* 0D69B0 8031B9B0 07220006 */  bltzl $t9, .L8031B9CC
/* 0D69B4 8031B9B4 85B90018 */   lh    $t9, 0x18($t5)
.L8031B9B8:
/* 0D69B8 8031B9B8 92180000 */  lbu   $t8, ($s0)
.L8031B9BC:
/* 0D69BC 8031B9BC 370F0020 */  ori   $t7, $t8, 0x20
/* 0D69C0 8031B9C0 100000FE */  b     .L8031BDBC
/* 0D69C4 8031B9C4 A20F0000 */   sb    $t7, ($s0)
/* 0D69C8 8031B9C8 85B90018 */  lh    $t9, 0x18($t5)
.L8031B9CC:
/* 0D69CC 8031B9CC 5720003B */  bnezl $t9, .L8031BABC
/* 0D69D0 8031B9D0 85980010 */   lh    $t8, 0x10($t4)
/* 0D69D4 8031B9D4 85B8001A */  lh    $t8, 0x1a($t5)
/* 0D69D8 8031B9D8 8619001E */  lh    $t9, 0x1e($s0)
/* 0D69DC 8031B9DC 00787821 */  addu  $t7, $v1, $t8
/* 0D69E0 8031B9E0 01F94021 */  addu  $t0, $t7, $t9
/* 0D69E4 8031B9E4 91AF0005 */  lbu   $t7, 5($t5)
/* 0D69E8 8031B9E8 8FF80000 */  lw    $t8, ($ra)
/* 0D69EC 8031B9EC 310E00FF */  andi  $t6, $t0, 0xff
/* 0D69F0 8031B9F0 000FC880 */  sll   $t9, $t7, 2
/* 0D69F4 8031B9F4 032FC823 */  subu  $t9, $t9, $t7
/* 0D69F8 8031B9F8 0019C880 */  sll   $t9, $t9, 2
/* 0D69FC 8031B9FC 03193821 */  addu  $a3, $t8, $t9
/* 0D6A00 8031BA00 90E20002 */  lbu   $v0, 2($a3)
/* 0D6A04 8031BA04 01C04025 */  move  $t0, $t6
/* 0D6A08 8031BA08 01C2082A */  slt   $at, $t6, $v0
/* 0D6A0C 8031BA0C 5420000C */  bnezl $at, .L8031BA40
/* 0D6A10 8031BA10 8CEE0008 */   lw    $t6, 8($a3)
/* 0D6A14 8031BA14 304800FF */  andi  $t0, $v0, 0xff
/* 0D6A18 8031BA18 55000006 */  bnezl $t0, .L8031BA34
/* 0D6A1C 8031BA1C 2508FFFF */   addiu $t0, $t0, -1
/* 0D6A20 8031BA20 920F0000 */  lbu   $t7, ($s0)
/* 0D6A24 8031BA24 35F80020 */  ori   $t8, $t7, 0x20
/* 0D6A28 8031BA28 100000E2 */  b     .L8031BDB4
/* 0D6A2C 8031BA2C A2180000 */   sb    $t8, ($s0)
/* 0D6A30 8031BA30 2508FFFF */  addiu $t0, $t0, -1
.L8031BA34:
/* 0D6A34 8031BA34 311900FF */  andi  $t9, $t0, 0xff
/* 0D6A38 8031BA38 03204025 */  move  $t0, $t9
/* 0D6A3C 8031BA3C 8CEE0008 */  lw    $t6, 8($a3)
.L8031BA40:
/* 0D6A40 8031BA40 00087880 */  sll   $t7, $t0, 2
/* 0D6A44 8031BA44 01CFC021 */  addu  $t8, $t6, $t7
/* 0D6A48 8031BA48 8F020000 */  lw    $v0, ($t8)
/* 0D6A4C 8031BA4C 54400006 */  bnezl $v0, .L8031BA68
/* 0D6A50 8031BA50 8C58000C */   lw    $t8, 0xc($v0)
/* 0D6A54 8031BA54 920E0000 */  lbu   $t6, ($s0)
/* 0D6A58 8031BA58 35CF0020 */  ori   $t7, $t6, 0x20
/* 0D6A5C 8031BA5C 100000D5 */  b     .L8031BDB4
/* 0D6A60 8031BA60 A20F0000 */   sb    $t7, ($s0)
/* 0D6A64 8031BA64 8C58000C */  lw    $t8, 0xc($v0)
.L8031BA68:
/* 0D6A68 8031BA68 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D6A6C 8031BA6C AE180018 */  sw    $t8, 0x18($s0)
/* 0D6A70 8031BA70 90590000 */  lbu   $t9, ($v0)
/* 0D6A74 8031BA74 A2190014 */  sb    $t9, 0x14($s0)
/* 0D6A78 8031BA78 904E0001 */  lbu   $t6, 1($v0)
/* 0D6A7C 8031BA7C 448E9000 */  mtc1  $t6, $f18
/* 0D6A80 8031BA80 05C10004 */  bgez  $t6, .L8031BA94
/* 0D6A84 8031BA84 46809120 */   cvt.s.w $f4, $f18
/* 0D6A88 8031BA88 44813000 */  mtc1  $at, $f6
/* 0D6A8C 8031BA8C 00000000 */  nop   
/* 0D6A90 8031BA90 46062100 */  add.s $f4, $f4, $f6
.L8031BA94:
/* 0D6A94 8031BA94 46002221 */  cvt.d.s $f8, $f4
/* 0D6A98 8031BA98 24430004 */  addiu $v1, $v0, 4
/* 0D6A9C 8031BA9C 46204282 */  mul.d $f10, $f8, $f0
/* 0D6AA0 8031BAA0 AE03004C */  sw    $v1, 0x4c($s0)
/* 0D6AA4 8031BAA4 46205420 */  cvt.s.d $f16, $f10
/* 0D6AA8 8031BAA8 E6100028 */  swc1  $f16, 0x28($s0)
/* 0D6AAC 8031BAAC C4720004 */  lwc1  $f18, 4($v1)
/* 0D6AB0 8031BAB0 100000C0 */  b     .L8031BDB4
/* 0D6AB4 8031BAB4 E6120020 */   swc1  $f18, 0x20($s0)
/* 0D6AB8 8031BAB8 85980010 */  lh    $t8, 0x10($t4)
.L8031BABC:
/* 0D6ABC 8031BABC 85AE001A */  lh    $t6, 0x1a($t5)
/* 0D6AC0 8031BAC0 0078C821 */  addu  $t9, $v1, $t8
/* 0D6AC4 8031BAC4 8618001E */  lh    $t8, 0x1e($s0)
/* 0D6AC8 8031BAC8 032E7821 */  addu  $t7, $t9, $t6
/* 0D6ACC 8031BACC 01F84021 */  addu  $t0, $t7, $t8
/* 0D6AD0 8031BAD0 310200FF */  andi  $v0, $t0, 0xff
/* 0D6AD4 8031BAD4 28410080 */  slti  $at, $v0, 0x80
/* 0D6AD8 8031BAD8 14200005 */  bnez  $at, .L8031BAF0
/* 0D6ADC 8031BADC 00404025 */   move  $t0, $v0
/* 0D6AE0 8031BAE0 920F0000 */  lbu   $t7, ($s0)
/* 0D6AE4 8031BAE4 35F80020 */  ori   $t8, $t7, 0x20
/* 0D6AE8 8031BAE8 100000B2 */  b     .L8031BDB4
/* 0D6AEC 8031BAEC A2180000 */   sb    $t8, ($s0)
.L8031BAF0:
/* 0D6AF0 8031BAF0 8E030048 */  lw    $v1, 0x48($s0)
/* 0D6AF4 8031BAF4 54600003 */  bnezl $v1, .L8031BB04
/* 0D6AF8 8031BAF8 92190004 */   lbu   $t9, 4($s0)
/* 0D6AFC 8031BAFC 8DA3003C */  lw    $v1, 0x3c($t5)
/* 0D6B00 8031BB00 92190004 */  lbu   $t9, 4($s0)
.L8031BB04:
/* 0D6B04 8031BB04 13200088 */  beqz  $t9, .L8031BD28
/* 0D6B08 8031BB08 00000000 */   nop   
/* 0D6B0C 8031BB0C 92040003 */  lbu   $a0, 3($s0)
/* 0D6B10 8031BB10 0082082A */  slt   $at, $a0, $v0
/* 0D6B14 8031BB14 10200003 */  beqz  $at, .L8031BB24
/* 0D6B18 8031BB18 00802825 */   move  $a1, $a0
/* 0D6B1C 8031BB1C 10000001 */  b     .L8031BB24
/* 0D6B20 8031BB20 00402825 */   move  $a1, $v0
.L8031BB24:
/* 0D6B24 8031BB24 10600017 */  beqz  $v1, .L8031BB84
/* 0D6B28 8031BB28 3C013F80 */   li    $at, 0x3F800000 # 1.000000
/* 0D6B2C 8031BB2C 906E0001 */  lbu   $t6, 1($v1)
/* 0D6B30 8031BB30 30A200FF */  andi  $v0, $a1, 0xff
/* 0D6B34 8031BB34 004E082A */  slt   $at, $v0, $t6
/* 0D6B38 8031BB38 50200004 */  beql  $at, $zero, .L8031BB4C
/* 0D6B3C 8031BB3C 906F0002 */   lbu   $t7, 2($v1)
/* 0D6B40 8031BB40 10000009 */  b     .L8031BB68
/* 0D6B44 8031BB44 24620008 */   addiu $v0, $v1, 8
/* 0D6B48 8031BB48 906F0002 */  lbu   $t7, 2($v1)
.L8031BB4C:
/* 0D6B4C 8031BB4C 24640018 */  addiu $a0, $v1, 0x18
/* 0D6B50 8031BB50 01E2082A */  slt   $at, $t7, $v0
/* 0D6B54 8031BB54 14200003 */  bnez  $at, .L8031BB64
/* 0D6B58 8031BB58 00000000 */   nop   
/* 0D6B5C 8031BB5C 10000001 */  b     .L8031BB64
/* 0D6B60 8031BB60 24640010 */   addiu $a0, $v1, 0x10
.L8031BB64:
/* 0D6B64 8031BB64 00801025 */  move  $v0, $a0
.L8031BB68:
/* 0D6B68 8031BB68 8E18004C */  lw    $t8, 0x4c($s0)
/* 0D6B6C 8031BB6C 0058C826 */  xor   $t9, $v0, $t8
/* 0D6B70 8031BB70 2F390001 */  sltiu $t9, $t9, 1
/* 0D6B74 8031BB74 A3B9003F */  sb    $t9, 0x3f($sp)
/* 0D6B78 8031BB78 AE02004C */  sw    $v0, 0x4c($s0)
/* 0D6B7C 8031BB7C 10000003 */  b     .L8031BB8C
/* 0D6B80 8031BB80 C4400004 */   lwc1  $f0, 4($v0)
.L8031BB84:
/* 0D6B84 8031BB84 44810000 */  mtc1  $at, $f0
/* 0D6B88 8031BB88 AE00004C */  sw    $zero, 0x4c($s0)
.L8031BB8C:
/* 0D6B8C 8031BB8C 3C038033 */  lui   $v1, %hi(D_80332884) 
/* 0D6B90 8031BB90 24632884 */  addiu $v1, %lo(D_80332884) # addiu $v1, $v1, 0x2884
/* 0D6B94 8031BB94 00087080 */  sll   $t6, $t0, 2
/* 0D6B98 8031BB98 92180003 */  lbu   $t8, 3($s0)
/* 0D6B9C 8031BB9C 006E7821 */  addu  $t7, $v1, $t6
/* 0D6BA0 8031BBA0 C5E60000 */  lwc1  $f6, ($t7)
/* 0D6BA4 8031BBA4 920F0004 */  lbu   $t7, 4($s0)
/* 0D6BA8 8031BBA8 0018C880 */  sll   $t9, $t8, 2
/* 0D6BAC 8031BBAC 00797021 */  addu  $t6, $v1, $t9
/* 0D6BB0 8031BBB0 C5C40000 */  lwc1  $f4, ($t6)
/* 0D6BB4 8031BBB4 46003082 */  mul.s $f2, $f6, $f0
/* 0D6BB8 8031BBB8 2401FF7F */  li    $at, -129
/* 0D6BBC 8031BBBC 01E1C024 */  and   $t8, $t7, $at
/* 0D6BC0 8031BBC0 2719FFFF */  addiu $t9, $t8, -1
/* 0D6BC4 8031BBC4 2F210005 */  sltiu $at, $t9, 5
/* 0D6BC8 8031BBC8 46002302 */  mul.s $f12, $f4, $f0
/* 0D6BCC 8031BBCC 1020000C */  beqz  $at, .L8031BC00
/* 0D6BD0 8031BBD0 0019C880 */   sll   $t9, $t9, 2
/* 0D6BD4 8031BBD4 3C018033 */  lui   $at, %hi(jtbl_80337CDC)
/* 0D6BD8 8031BBD8 00390821 */  addu  $at, $at, $t9
/* 0D6BDC 8031BBDC 8C397CDC */  lw    $t9, %lo(jtbl_80337CDC)($at)
/* 0D6BE0 8031BBE0 03200008 */  jr    $t9
/* 0D6BE4 8031BBE4 00000000 */   nop   
glabel L8031BBE8
/* 0D6BE8 8031BBE8 E7A20024 */  swc1  $f2, 0x24($sp)
/* 0D6BEC 8031BBEC 10000005 */  b     .L8031BC04
/* 0D6BF0 8031BBF0 46006006 */   mov.s $f0, $f12
glabel L8031BBF4
/* 0D6BF4 8031BBF4 46001006 */  mov.s $f0, $f2
/* 0D6BF8 8031BBF8 10000002 */  b     .L8031BC04
/* 0D6BFC 8031BBFC E7AC0024 */   swc1  $f12, 0x24($sp)
.L8031BC00:
/* 0D6C00 8031BC00 C7A00028 */  lwc1  $f0, 0x28($sp)
.L8031BC04:
/* 0D6C04 8031BC04 C7A80024 */  lwc1  $f8, 0x24($sp)
/* 0D6C08 8031BC08 3C013FF0 */  li    $at, 0x3FF00000 # 1.875000
/* 0D6C0C 8031BC0C 44819800 */  mtc1  $at, $f19
/* 0D6C10 8031BC10 46004283 */  div.s $f10, $f8, $f0
/* 0D6C14 8031BC14 44809000 */  mtc1  $zero, $f18
/* 0D6C18 8031BC18 26020004 */  addiu $v0, $s0, 4
/* 0D6C1C 8031BC1C 46005421 */  cvt.d.s $f16, $f10
/* 0D6C20 8031BC20 46328181 */  sub.d $f6, $f16, $f18
/* 0D6C24 8031BC24 46203120 */  cvt.s.d $f4, $f6
/* 0D6C28 8031BC28 E444000C */  swc1  $f4, 0xc($v0)
/* 0D6C2C 8031BC2C 920E0004 */  lbu   $t6, 4($s0)
/* 0D6C30 8031BC30 31CF0080 */  andi  $t7, $t6, 0x80
/* 0D6C34 8031BC34 11E00023 */  beqz  $t7, .L8031BCC4
/* 0D6C38 8031BC38 3C0E8022 */   lui   $t6, %hi(D_80226D7C) 
/* 0D6C3C 8031BC3C 9598000A */  lhu   $t8, 0xa($t4)
/* 0D6C40 8031BC40 3C018033 */  lui   $at, %hi(D_80337CF0)
/* 0D6C44 8031BC44 D4287CF0 */  ldc1  $f8, %lo(D_80337CF0)($at)
/* 0D6C48 8031BC48 44985000 */  mtc1  $t8, $f10
/* 0D6C4C 8031BC4C 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D6C50 8031BC50 07010004 */  bgez  $t8, .L8031BC64
/* 0D6C54 8031BC54 46805420 */   cvt.s.w $f16, $f10
/* 0D6C58 8031BC58 44819000 */  mtc1  $at, $f18
/* 0D6C5C 8031BC5C 00000000 */  nop   
/* 0D6C60 8031BC60 46128400 */  add.s $f16, $f16, $f18
.L8031BC64:
/* 0D6C64 8031BC64 8619003C */  lh    $t9, 0x3c($s0)
/* 0D6C68 8031BC68 85CE6D7C */  lh    $t6, %lo(D_80226D7C)($t6)
/* 0D6C6C 8031BC6C 460081A1 */  cvt.d.s $f6, $f16
/* 0D6C70 8031BC70 44995000 */  mtc1  $t9, $f10
/* 0D6C74 8031BC74 448E8000 */  mtc1  $t6, $f16
/* 0D6C78 8031BC78 46264102 */  mul.d $f4, $f8, $f6
/* 0D6C7C 8031BC7C 960F001C */  lhu   $t7, 0x1c($s0)
/* 0D6C80 8031BC80 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D6C84 8031BC84 468054A0 */  cvt.s.w $f18, $f10
/* 0D6C88 8031BC88 448F5000 */  mtc1  $t7, $f10
/* 0D6C8C 8031BC8C 46808220 */  cvt.s.w $f8, $f16
/* 0D6C90 8031BC90 46805420 */  cvt.s.w $f16, $f10
/* 0D6C94 8031BC94 46089182 */  mul.s $f6, $f18, $f8
/* 0D6C98 8031BC98 05E10004 */  bgez  $t7, .L8031BCAC
/* 0D6C9C 8031BC9C 00000000 */   nop   
/* 0D6CA0 8031BCA0 44819000 */  mtc1  $at, $f18
/* 0D6CA4 8031BCA4 00000000 */  nop   
/* 0D6CA8 8031BCA8 46128400 */  add.s $f16, $f16, $f18
.L8031BCAC:
/* 0D6CAC 8031BCAC 46068202 */  mul.s $f8, $f16, $f6
/* 0D6CB0 8031BCB0 460042A1 */  cvt.d.s $f10, $f8
/* 0D6CB4 8031BCB4 462A2483 */  div.d $f18, $f4, $f10
/* 0D6CB8 8031BCB8 46209420 */  cvt.s.d $f16, $f18
/* 0D6CBC 8031BCBC 1000000F */  b     .L8031BCFC
/* 0D6CC0 8031BCC0 E4500008 */   swc1  $f16, 8($v0)
.L8031BCC4:
/* 0D6CC4 8031BCC4 9618001C */  lhu   $t8, 0x1c($s0)
/* 0D6CC8 8031BCC8 3C018033 */  lui   $at, %hi(D_80337CF8)
/* 0D6CCC 8031BCCC D4267CF8 */  ldc1  $f6, %lo(D_80337CF8)($at)
/* 0D6CD0 8031BCD0 44984000 */  mtc1  $t8, $f8
/* 0D6CD4 8031BCD4 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D6CD8 8031BCD8 07010004 */  bgez  $t8, .L8031BCEC
/* 0D6CDC 8031BCDC 46804120 */   cvt.s.w $f4, $f8
/* 0D6CE0 8031BCE0 44815000 */  mtc1  $at, $f10
/* 0D6CE4 8031BCE4 00000000 */  nop   
/* 0D6CE8 8031BCE8 460A2100 */  add.s $f4, $f4, $f10
.L8031BCEC:
/* 0D6CEC 8031BCEC 460024A1 */  cvt.d.s $f18, $f4
/* 0D6CF0 8031BCF0 46323403 */  div.d $f16, $f6, $f18
/* 0D6CF4 8031BCF4 46208220 */  cvt.s.d $f8, $f16
/* 0D6CF8 8031BCF8 E4480008 */  swc1  $f8, 8($v0)
.L8031BCFC:
/* 0D6CFC 8031BCFC 44805000 */  mtc1  $zero, $f10
/* 0D6D00 8031BD00 2401FF7F */  li    $at, -129
/* 0D6D04 8031BD04 E44A0004 */  swc1  $f10, 4($v0)
/* 0D6D08 8031BD08 92190004 */  lbu   $t9, 4($s0)
/* 0D6D0C 8031BD0C E6000020 */  swc1  $f0, 0x20($s0)
/* 0D6D10 8031BD10 03217024 */  and   $t6, $t9, $at
/* 0D6D14 8031BD14 24010005 */  li    $at, 5
/* 0D6D18 8031BD18 55C10027 */  bnel  $t6, $at, .L8031BDB8
/* 0D6D1C 8031BD1C 860F003C */   lh    $t7, 0x3c($s0)
/* 0D6D20 8031BD20 10000024 */  b     .L8031BDB4
/* 0D6D24 8031BD24 A2080003 */   sb    $t0, 3($s0)
.L8031BD28:
/* 0D6D28 8031BD28 1060001C */  beqz  $v1, .L8031BD9C
/* 0D6D2C 8031BD2C 0008C880 */   sll   $t9, $t0, 2
/* 0D6D30 8031BD30 906F0001 */  lbu   $t7, 1($v1)
/* 0D6D34 8031BD34 004F082A */  slt   $at, $v0, $t7
/* 0D6D38 8031BD38 10200003 */  beqz  $at, .L8031BD48
/* 0D6D3C 8031BD3C 00087880 */   sll   $t7, $t0, 2
/* 0D6D40 8031BD40 10000009 */  b     .L8031BD68
/* 0D6D44 8031BD44 24620008 */   addiu $v0, $v1, 8
.L8031BD48:
/* 0D6D48 8031BD48 90780002 */  lbu   $t8, 2($v1)
/* 0D6D4C 8031BD4C 24640018 */  addiu $a0, $v1, 0x18
/* 0D6D50 8031BD50 0302082A */  slt   $at, $t8, $v0
/* 0D6D54 8031BD54 14200003 */  bnez  $at, .L8031BD64
/* 0D6D58 8031BD58 00000000 */   nop   
/* 0D6D5C 8031BD5C 10000001 */  b     .L8031BD64
/* 0D6D60 8031BD60 24640010 */   addiu $a0, $v1, 0x10
.L8031BD64:
/* 0D6D64 8031BD64 00801025 */  move  $v0, $a0
.L8031BD68:
/* 0D6D68 8031BD68 8E19004C */  lw    $t9, 0x4c($s0)
/* 0D6D6C 8031BD6C 3C038033 */  lui   $v1, %hi(D_80332884) # $v1, 0x8033
/* 0D6D70 8031BD70 24632884 */  addiu $v1, %lo(D_80332884) # addiu $v1, $v1, 0x2884
/* 0D6D74 8031BD74 00597026 */  xor   $t6, $v0, $t9
/* 0D6D78 8031BD78 2DCE0001 */  sltiu $t6, $t6, 1
/* 0D6D7C 8031BD7C A3AE003F */  sb    $t6, 0x3f($sp)
/* 0D6D80 8031BD80 AE02004C */  sw    $v0, 0x4c($s0)
/* 0D6D84 8031BD84 006FC021 */  addu  $t8, $v1, $t7
/* 0D6D88 8031BD88 C7060000 */  lwc1  $f6, ($t8)
/* 0D6D8C 8031BD8C C4440004 */  lwc1  $f4, 4($v0)
/* 0D6D90 8031BD90 46062482 */  mul.s $f18, $f4, $f6
/* 0D6D94 8031BD94 10000007 */  b     .L8031BDB4
/* 0D6D98 8031BD98 E6120020 */   swc1  $f18, 0x20($s0)
.L8031BD9C:
/* 0D6D9C 8031BD9C 3C038033 */  lui   $v1, %hi(D_80332884) # $v1, 0x8033
/* 0D6DA0 8031BDA0 24632884 */  addiu $v1, %lo(D_80332884) # addiu $v1, $v1, 0x2884
/* 0D6DA4 8031BDA4 AE00004C */  sw    $zero, 0x4c($s0)
/* 0D6DA8 8031BDA8 00797021 */  addu  $t6, $v1, $t9
/* 0D6DAC 8031BDAC C5D00000 */  lwc1  $f16, ($t6)
/* 0D6DB0 8031BDB0 E6100020 */  swc1  $f16, 0x20($s0)
.L8031BDB4:
/* 0D6DB4 8031BDB4 860F003C */  lh    $t7, 0x3c($s0)
.L8031BDB8:
/* 0D6DB8 8031BDB8 A60F0040 */  sh    $t7, 0x40($s0)
.L8031BDBC:
/* 0D6DBC 8031BDBC 8E020000 */  lw    $v0, ($s0)
/* 0D6DC0 8031BDC0 24010001 */  li    $at, 1
/* 0D6DC4 8031BDC4 0002C080 */  sll   $t8, $v0, 2
/* 0D6DC8 8031BDC8 0018CFC2 */  srl   $t9, $t8, 0x1f
/* 0D6DCC 8031BDCC 5721000C */  bnel  $t9, $at, .L8031BE00
/* 0D6DD0 8031BDD0 000270C0 */   sll   $t6, $v0, 3
/* 0D6DD4 8031BDD4 8E0E0044 */  lw    $t6, 0x44($s0)
/* 0D6DD8 8031BDD8 0002C0C0 */  sll   $t8, $v0, 3
/* 0D6DDC 8031BDDC 15C00003 */  bnez  $t6, .L8031BDEC
/* 0D6DE0 8031BDE0 00000000 */   nop   
/* 0D6DE4 8031BDE4 0703002E */  bgezl $t8, .L8031BEA0
/* 0D6DE8 8031BDE8 8FBF001C */   lw    $ra, 0x1c($sp)
.L8031BDEC:
/* 0D6DEC 8031BDEC 0C0C63B1 */  jal   func_80318EC4
/* 0D6DF0 8031BDF0 02002025 */   move  $a0, $s0
/* 0D6DF4 8031BDF4 1000002A */  b     .L8031BEA0
/* 0D6DF8 8031BDF8 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0D6DFC 8031BDFC 000270C0 */  sll   $t6, $v0, 3
.L8031BE00:
/* 0D6E00 8031BE00 05C00003 */  bltz  $t6, .L8031BE10
/* 0D6E04 8031BE04 00004025 */   move  $t0, $zero
/* 0D6E08 8031BE08 10000017 */  b     .L8031BE68
/* 0D6E0C 8031BE0C 24080001 */   li    $t0, 1
.L8031BE10:
/* 0D6E10 8031BE10 8E040044 */  lw    $a0, 0x44($s0)
/* 0D6E14 8031BE14 10800005 */  beqz  $a0, .L8031BE2C
/* 0D6E18 8031BE18 00000000 */   nop   
/* 0D6E1C 8031BE1C 920F0001 */  lbu   $t7, 1($s0)
/* 0D6E20 8031BE20 93B8003F */  lbu   $t8, 0x3f($sp)
/* 0D6E24 8031BE24 15E00003 */  bnez  $t7, .L8031BE34
/* 0D6E28 8031BE28 00000000 */   nop   
.L8031BE2C:
/* 0D6E2C 8031BE2C 1000000E */  b     .L8031BE68
/* 0D6E30 8031BE30 24080001 */   li    $t0, 1
.L8031BE34:
/* 0D6E34 8031BE34 57000006 */  bnezl $t8, .L8031BE50
/* 0D6E38 8031BE38 8E19004C */   lw    $t9, 0x4c($s0)
/* 0D6E3C 8031BE3C 0C0C63B1 */  jal   func_80318EC4
/* 0D6E40 8031BE40 02002025 */   move  $a0, $s0
/* 0D6E44 8031BE44 10000008 */  b     .L8031BE68
/* 0D6E48 8031BE48 24080001 */   li    $t0, 1
/* 0D6E4C 8031BE4C 8E19004C */  lw    $t9, 0x4c($s0)
.L8031BE50:
/* 0D6E50 8031BE50 02002825 */  move  $a1, $s0
/* 0D6E54 8031BE54 17200004 */  bnez  $t9, .L8031BE68
/* 0D6E58 8031BE58 00000000 */   nop   
/* 0D6E5C 8031BE5C 0C0C6459 */  jal   func_80319164
/* 0D6E60 8031BE60 A3A8003D */   sb    $t0, 0x3d($sp)
/* 0D6E64 8031BE64 93A8003D */  lbu   $t0, 0x3d($sp)
.L8031BE68:
/* 0D6E68 8031BE68 51000005 */  beql  $t0, $zero, .L8031BE80
/* 0D6E6C 8031BE6C 8E040044 */   lw    $a0, 0x44($s0)
/* 0D6E70 8031BE70 0C0C6638 */  jal   func_803198E0
/* 0D6E74 8031BE74 02002025 */   move  $a0, $s0
/* 0D6E78 8031BE78 AE020044 */  sw    $v0, 0x44($s0)
/* 0D6E7C 8031BE7C 8E040044 */  lw    $a0, 0x44($s0)
.L8031BE80:
/* 0D6E80 8031BE80 50800007 */  beql  $a0, $zero, .L8031BEA0
/* 0D6E84 8031BE84 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0D6E88 8031BE88 8C8E002C */  lw    $t6, 0x2c($a0)
/* 0D6E8C 8031BE8C 560E0004 */  bnel  $s0, $t6, .L8031BEA0
/* 0D6E90 8031BE90 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0D6E94 8031BE94 0C0C691E */  jal   func_8031A478
/* 0D6E98 8031BE98 00000000 */   nop   
.L8031BE9C:
/* 0D6E9C 8031BE9C 8FBF001C */  lw    $ra, 0x1c($sp)
.L8031BEA0:
/* 0D6EA0 8031BEA0 8FB00018 */  lw    $s0, 0x18($sp)
/* 0D6EA4 8031BEA4 27BD0060 */  addiu $sp, $sp, 0x60
/* 0D6EA8 8031BEA8 03E00008 */  jr    $ra
/* 0D6EAC 8031BEAC 00000000 */   nop   
)
#else
GLOBAL_ASM(
.late_rodata
glabel jtbl_80337C90
	.word L_U_8031C2DC
	.word L_U_8031C298
	.word L_U_8031C6A0
	.word L_U_8031C6A0
	.word L_U_8031C328
	.word L_U_8031C23C
	.word L_U_8031C6A0
	.word L_U_8031C6A0
	.word L_U_8031C200

glabel jtbl_80337CB4
	.word L_U_8031C36C
	.word L_U_8031C3BC
	.word L_U_8031C454
	.word L_U_8031C3E8
	.word L_U_8031C3E8
	.word L_U_8031C4A4
	.word L_U_8031C5C8
	.word L_U_8031C698
	.word L_U_8031C3BC
	.word L_U_8031C36C

glabel jtbl_80337CDC
	.word L_U_8031CBE0
	.word L_U_8031CBEC
	.word L_U_8031CBE0
	.word L_U_8031CBEC
	.word L_U_8031CBE0

.text
glabel func_8031B0A4
/* 0D70C4 8031C0C4 27BDFFA0 */  addiu $sp, $sp, -0x60
/* 0D70C8 8031C0C8 240E0001 */  li    $t6, 1
/* 0D70CC 8031C0CC AFBF001C */  sw    $ra, 0x1c($sp)
/* 0D70D0 8031C0D0 AFB00018 */  sw    $s0, 0x18($sp)
/* 0D70D4 8031C0D4 A3AE003F */  sb    $t6, 0x3f($sp)
/* 0D70D8 8031C0D8 8C820000 */  lw    $v0, ($a0)
/* 0D70DC 8031C0DC 00808025 */  move  $s0, $a0
/* 0D70E0 8031C0E0 00027FC2 */  srl   $t7, $v0, 0x1f
/* 0D70E4 8031C0E4 51E00357 */  beql  $t7, $zero, .L8031CE44
/* 0D70E8 8031C0E8 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0D70EC 8031C0EC 8483003C */  lh    $v1, 0x3c($a0)
/* 0D70F0 8031C0F0 00027080 */  sll   $t6, $v0, 2
/* 0D70F4 8031C0F4 0002C8C0 */  sll   $t9, $v0, 3
/* 0D70F8 8031C0F8 28610002 */  slti  $at, $v1, 2
/* 0D70FC 8031C0FC 1420000E */  bnez  $at, .L8031C138
/* 0D7100 8031C100 2478FFFF */   addiu $t8, $v1, -1
/* 0D7104 8031C104 05C0034E */  bltz  $t6, .L8031CE40
/* 0D7108 8031C108 A498003C */   sh    $t8, 0x3c($a0)
/* 0D710C 8031C10C 848F003E */  lh    $t7, 0x3e($a0)
/* 0D7110 8031C110 8498003C */  lh    $t8, 0x3c($a0)
/* 0D7114 8031C114 01F8082A */  slt   $at, $t7, $t8
/* 0D7118 8031C118 5420034A */  bnezl $at, .L8031CE44
/* 0D711C 8031C11C 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0D7120 8031C120 0C0C67D9 */  jal   func_80318EC4
/* 0D7124 8031C124 00000000 */   nop   
/* 0D7128 8031C128 920E0000 */  lbu   $t6, ($s0)
/* 0D712C 8031C12C 35CF0020 */  ori   $t7, $t6, 0x20
/* 0D7130 8031C130 10000343 */  b     .L8031CE40
/* 0D7134 8031C134 A20F0000 */   sb    $t7, ($s0)
.L8031C138:
/* 0D7138 8031C138 07220004 */  bltzl $t9, .L8031C14C_2
/* 0D713C 8031C13C 92020004 */   lbu   $v0, 4($s0)
/* 0D7140 8031C140 0C0C67D9 */  jal   func_80318EC4
/* 0D7144 8031C144 02002025 */   move  $a0, $s0
/* 0D7148 8031C148 92020004 */  lbu   $v0, 4($s0)
.L8031C14C_2:
/* 0D714C 8031C14C 2401FF7F */  li    $at, -129
/* 0D7150 8031C150 3C1F8022 */  lui   $ra, %hi(D_80226D60) # $ra, 0x8022
/* 0D7154 8031C154 00417024 */  and   $t6, $v0, $at
/* 0D7158 8031C158 24010001 */  li    $at, 1
/* 0D715C 8031C15C 11C10004 */  beq   $t6, $at, .L8031C170
/* 0D7160 8031C160 27FF6B60 */   addiu $ra, %lo(D_80226D60) # addiu $ra, $ra, 0x6b60
/* 0D7164 8031C164 24010002 */  li    $at, 2
/* 0D7168 8031C168 55C10003 */  bnel  $t6, $at, .L8031C178
/* 0D716C 8031C16C 8E0D0050 */   lw    $t5, 0x50($s0)
.L8031C170:
/* 0D7170 8031C170 A2000004 */  sb    $zero, 4($s0)
/* 0D7174 8031C174 8E0D0050 */  lw    $t5, 0x50($s0)
.L8031C178:
/* 0D7178 8031C178 3C013C00 */  li    $at, 0x3C000000 # 0.007812
/* 0D717C 8031C17C 3C0B8022 */  lui   $t3, %hi(D_802214F8) # $t3, 0x8022
/* 0D7180 8031C180 44810000 */  mtc1  $at, $f0
/* 0D7184 8031C184 256B10F8 */  addiu $t3, %lo(D_802214F8) # addiu $t3, $t3, 0x10f8
/* 0D7188 8031C188 97AA003A */  lhu   $t2, 0x3a($sp)
/* 0D718C 8031C18C 240900FF */  li    $t1, 255
/* 0D7190 8031C190 8DAC0040 */  lw    $t4, 0x40($t5)
.L8031C194:
/* 0D7194 8031C194 8E020054 */  lw    $v0, 0x54($s0)
.L8031C198:
/* 0D7198 8031C198 244F0001 */  addiu $t7, $v0, 1
/* 0D719C 8031C19C AE0F0054 */  sw    $t7, 0x54($s0)
/* 0D71A0 8031C1A0 90440000 */  lbu   $a0, ($v0)
/* 0D71A4 8031C1A4 288100C1 */  slti  $at, $a0, 0xc1
/* 0D71A8 8031C1A8 14200156 */  bnez  $at, .L8031C704
/* 0D71AC 8031C1AC 00802825 */   move  $a1, $a0
/* 0D71B0 8031C1B0 288100CB */  slti  $at, $a0, 0xcb
/* 0D71B4 8031C1B4 1420000A */  bnez  $at, .L8031C1E0
/* 0D71B8 8031C1B8 24B9FF3F */   addiu $t9, $a1, -0xc1
/* 0D71BC 8031C1BC 2498FF09 */  addiu $t8, $a0, -0xf7
/* 0D71C0 8031C1C0 2F010009 */  sltiu $at, $t8, 9
/* 0D71C4 8031C1C4 10200136 */  beqz  $at, .L8031C6A0
/* 0D71C8 8031C1C8 0018C080 */   sll   $t8, $t8, 2
/* 0D71CC 8031C1CC 3C018034 */  lui   $at, %hi(jtbl_80337C90)
/* 0D71D0 8031C1D0 00380821 */  addu  $at, $at, $t8
/* 0D71D4 8031C1D4 8C388E60 */  lw    $t8, %lo(jtbl_80337C90)($at)
/* 0D71D8 8031C1D8 03000008 */  jr    $t8
/* 0D71DC 8031C1DC 00000000 */   nop   
.L8031C1E0:
/* 0D71E0 8031C1E0 2F21000A */  sltiu $at, $t9, 0xa
/* 0D71E4 8031C1E4 1020012E */  beqz  $at, .L8031C6A0
/* 0D71E8 8031C1E8 0019C880 */   sll   $t9, $t9, 2
/* 0D71EC 8031C1EC 3C018034 */  lui   $at, %hi(jtbl_80337CB4)
/* 0D71F0 8031C1F0 00390821 */  addu  $at, $at, $t9
/* 0D71F4 8031C1F4 8C398E84 */  lw    $t9, %lo(jtbl_80337CB4)($at)
/* 0D71F8 8031C1F8 03200008 */  jr    $t9
/* 0D71FC 8031C1FC 00000000 */   nop   
glabel L_U_8031C200
/* 0D7200 8031C200 26020054 */  addiu $v0, $s0, 0x54
/* 0D7204 8031C204 90430018 */  lbu   $v1, 0x18($v0)
/* 0D7208 8031C208 14600005 */  bnez  $v1, .L8031C220
/* 0D720C 8031C20C 246EFFFF */   addiu $t6, $v1, -1
/* 0D7210 8031C210 0C0C6E8C */  jal   func_8031AA10
/* 0D7214 8031C214 02002025 */   move  $a0, $s0
/* 0D7218 8031C218 1000030A */  b     .L8031CE44
/* 0D721C 8031C21C 8FBF001C */   lw    $ra, 0x1c($sp)
.L8031C220:
/* 0D7220 8031C220 31CF00FF */  andi  $t7, $t6, 0xff
/* 0D7224 8031C224 000FC080 */  sll   $t8, $t7, 2
/* 0D7228 8031C228 0058C821 */  addu  $t9, $v0, $t8
/* 0D722C 8031C22C A04E0018 */  sb    $t6, 0x18($v0)
/* 0D7230 8031C230 8F2E0004 */  lw    $t6, 4($t9)
/* 0D7234 8031C234 1000FFD7 */  b     .L8031C194
/* 0D7238 8031C238 AC4E0000 */   sw    $t6, ($v0)
glabel L_U_8031C23C
/* 0D723C 8031C23C 26020054 */  addiu $v0, $s0, 0x54
/* 0D7240 8031C240 8C430000 */  lw    $v1, ($v0)
/* 0D7244 8031C244 90640000 */  lbu   $a0, ($v1)
/* 0D7248 8031C248 246E0001 */  addiu $t6, $v1, 1
/* 0D724C 8031C24C AC4E0000 */  sw    $t6, ($v0)
/* 0D7250 8031C250 91CF0000 */  lbu   $t7, ($t6)
/* 0D7254 8031C254 0004CA00 */  sll   $t9, $a0, 8
/* 0D7258 8031C258 01F92825 */  or    $a1, $t7, $t9
/* 0D725C 8031C25C 904F0018 */  lbu   $t7, 0x18($v0)
/* 0D7260 8031C260 25D90001 */  addiu $t9, $t6, 1
/* 0D7264 8031C264 AC590000 */  sw    $t9, ($v0)
/* 0D7268 8031C268 25F80001 */  addiu $t8, $t7, 1
/* 0D726C 8031C26C 330E00FF */  andi  $t6, $t8, 0xff
/* 0D7270 8031C270 000E7880 */  sll   $t7, $t6, 2
/* 0D7274 8031C274 A0580018 */  sb    $t8, 0x18($v0)
/* 0D7278 8031C278 004FC021 */  addu  $t8, $v0, $t7
/* 0D727C 8031C27C AF190000 */  sw    $t9, ($t8)
/* 0D7280 8031C280 8D8E0014 */  lw    $t6, 0x14($t4)
/* 0D7284 8031C284 30AFFFFF */  andi  $t7, $a1, 0xffff
/* 0D7288 8031C288 30AAFFFF */  andi  $t2, $a1, 0xffff
/* 0D728C 8031C28C 01CFC821 */  addu  $t9, $t6, $t7
/* 0D7290 8031C290 1000FFC0 */  b     .L8031C194
/* 0D7294 8031C294 AC590000 */   sw    $t9, ($v0)
glabel L_U_8031C298
/* 0D7298 8031C298 26020054 */  addiu $v0, $s0, 0x54
/* 0D729C 8031C29C 8C430000 */  lw    $v1, ($v0)
/* 0D72A0 8031C2A0 904E0018 */  lbu   $t6, 0x18($v0)
/* 0D72A4 8031C2A4 24780001 */  addiu $t8, $v1, 1
/* 0D72A8 8031C2A8 AC580000 */  sw    $t8, ($v0)
/* 0D72AC 8031C2AC 90650000 */  lbu   $a1, ($v1)
/* 0D72B0 8031C2B0 004E7821 */  addu  $t7, $v0, $t6
/* 0D72B4 8031C2B4 A1E50014 */  sb    $a1, 0x14($t7)
/* 0D72B8 8031C2B8 90590018 */  lbu   $t9, 0x18($v0)
/* 0D72BC 8031C2BC 8C4E0000 */  lw    $t6, ($v0)
/* 0D72C0 8031C2C0 27380001 */  addiu $t8, $t9, 1
/* 0D72C4 8031C2C4 330F00FF */  andi  $t7, $t8, 0xff
/* 0D72C8 8031C2C8 000FC880 */  sll   $t9, $t7, 2
/* 0D72CC 8031C2CC A0580018 */  sb    $t8, 0x18($v0)
/* 0D72D0 8031C2D0 0059C021 */  addu  $t8, $v0, $t9
/* 0D72D4 8031C2D4 1000FFAF */  b     .L8031C194
/* 0D72D8 8031C2D8 AF0E0000 */   sw    $t6, ($t8)
glabel L_U_8031C2DC
/* 0D72DC 8031C2DC 26020054 */  addiu $v0, $s0, 0x54
/* 0D72E0 8031C2E0 904F0018 */  lbu   $t7, 0x18($v0)
/* 0D72E4 8031C2E4 004F2021 */  addu  $a0, $v0, $t7
/* 0D72E8 8031C2E8 90990013 */  lbu   $t9, 0x13($a0)
/* 0D72EC 8031C2EC 272EFFFF */  addiu $t6, $t9, -1
/* 0D72F0 8031C2F0 A08E0013 */  sb    $t6, 0x13($a0)
/* 0D72F4 8031C2F4 90430018 */  lbu   $v1, 0x18($v0)
/* 0D72F8 8031C2F8 0043C021 */  addu  $t8, $v0, $v1
/* 0D72FC 8031C2FC 930F0013 */  lbu   $t7, 0x13($t8)
/* 0D7300 8031C300 00602825 */  move  $a1, $v1
/* 0D7304 8031C304 0005C880 */  sll   $t9, $a1, 2
/* 0D7308 8031C308 11E00004 */  beqz  $t7, .L8031C31C
/* 0D730C 8031C30C 00597021 */   addu  $t6, $v0, $t9
/* 0D7310 8031C310 8DD80000 */  lw    $t8, ($t6)
/* 0D7314 8031C314 1000FF9F */  b     .L8031C194
/* 0D7318 8031C318 AC580000 */   sw    $t8, ($v0)
.L8031C31C:
/* 0D731C 8031C31C 246FFFFF */  addiu $t7, $v1, -1
/* 0D7320 8031C320 1000FF9C */  b     .L8031C194
/* 0D7324 8031C324 A04F0018 */   sb    $t7, 0x18($v0)
glabel L_U_8031C328
/* 0D7328 8031C328 26020054 */  addiu $v0, $s0, 0x54
/* 0D732C 8031C32C 8C430000 */  lw    $v1, ($v0)
/* 0D7330 8031C330 90640000 */  lbu   $a0, ($v1)
/* 0D7334 8031C334 246F0001 */  addiu $t7, $v1, 1
/* 0D7338 8031C338 AC4F0000 */  sw    $t7, ($v0)
/* 0D733C 8031C33C 91F90000 */  lbu   $t9, ($t7)
/* 0D7340 8031C340 0004C200 */  sll   $t8, $a0, 8
/* 0D7344 8031C344 25EF0001 */  addiu $t7, $t7, 1
/* 0D7348 8031C348 03387025 */  or    $t6, $t9, $t8
/* 0D734C 8031C34C AC4F0000 */  sw    $t7, ($v0)
/* 0D7350 8031C350 8D990014 */  lw    $t9, 0x14($t4)
/* 0D7354 8031C354 01C0C025 */  move  $t8, $t6
/* 0D7358 8031C358 330AFFFF */  andi  $t2, $t8, 0xffff
/* 0D735C 8031C35C 330EFFFF */  andi  $t6, $t8, 0xffff
/* 0D7360 8031C360 032EC021 */  addu  $t8, $t9, $t6
/* 0D7364 8031C364 1000FF8B */  b     .L8031C194
/* 0D7368 8031C368 AC580000 */   sw    $t8, ($v0)
glabel L_U_8031C36C
/* 0D736C 8031C36C 26020054 */  addiu $v0, $s0, 0x54
/* 0D7370 8031C370 8C430000 */  lw    $v1, ($v0)
/* 0D7374 8031C374 240100C1 */  li    $at, 193
/* 0D7378 8031C378 90640000 */  lbu   $a0, ($v1)
/* 0D737C 8031C37C 246F0001 */  addiu $t7, $v1, 1
/* 0D7380 8031C380 14A10008 */  bne   $a1, $at, .L8031C3A4
/* 0D7384 8031C384 AC4F0000 */   sw    $t7, ($v0)
/* 0D7388 8031C388 00840019 */  multu $a0, $a0
/* 0D738C 8031C38C 0000C812 */  mflo  $t9
/* 0D7390 8031C390 44992000 */  mtc1  $t9, $f4
/* 0D7394 8031C394 00000000 */  nop   
/* 0D7398 8031C398 468021A0 */  cvt.s.w $f6, $f4
/* 0D739C 8031C39C 1000FF7D */  b     .L8031C194
/* 0D73A0 8031C3A0 E6060024 */   swc1  $f6, 0x24($s0)
.L8031C3A4:
/* 0D73A4 8031C3A4 44844000 */  mtc1  $a0, $f8
/* 0D73A8 8031C3A8 00000000 */  nop   
/* 0D73AC 8031C3AC 468042A0 */  cvt.s.w $f10, $f8
/* 0D73B0 8031C3B0 46005402 */  mul.s $f16, $f10, $f0
/* 0D73B4 8031C3B4 1000FF77 */  b     .L8031C194
/* 0D73B8 8031C3B8 E6100028 */   swc1  $f16, 0x28($s0)
glabel L_U_8031C3BC
/* 0D73BC 8031C3BC 26020054 */  addiu $v0, $s0, 0x54
/* 0D73C0 8031C3C0 8C430000 */  lw    $v1, ($v0)
/* 0D73C4 8031C3C4 240100C9 */  li    $at, 201
/* 0D73C8 8031C3C8 90640000 */  lbu   $a0, ($v1)
/* 0D73CC 8031C3CC 246E0001 */  addiu $t6, $v1, 1
/* 0D73D0 8031C3D0 14A10003 */  bne   $a1, $at, .L8031C3E0
/* 0D73D4 8031C3D4 AC4E0000 */   sw    $t6, ($v0)
/* 0D73D8 8031C3D8 1000FF6E */  b     .L8031C194
/* 0D73DC 8031C3DC A2040002 */   sb    $a0, 2($s0)
.L8031C3E0:
/* 0D73E0 8031C3E0 1000FF6C */  b     .L8031C194
/* 0D73E4 8031C3E4 A604001E */   sh    $a0, 0x1e($s0)
glabel L_U_8031C3E8
/* 0D73E8 8031C3E8 240100C4 */  li    $at, 196
/* 0D73EC 8031C3EC 14A10003 */  bne   $a1, $at, .L8031C3FC
/* 0D73F0 8031C3F0 02002025 */   move  $a0, $s0
/* 0D73F4 8031C3F4 10000002 */  b     .L8031C400
/* 0D73F8 8031C3F8 24020001 */   li    $v0, 1
.L8031C3FC:
/* 0D73FC 8031C3FC 00001025 */  move  $v0, $zero
.L8031C400:
/* 0D7400 8031C400 920E0000 */  lbu   $t6, ($s0)
/* 0D7404 8031C404 00027900 */  sll   $t7, $v0, 4
/* 0D7408 8031C408 31F90010 */  andi  $t9, $t7, 0x10
/* 0D740C 8031C40C 31D8FFEF */  andi  $t8, $t6, 0xffef
/* 0D7410 8031C410 03387825 */  or    $t7, $t9, $t8
/* 0D7414 8031C414 A20F0000 */  sb    $t7, ($s0)
/* 0D7418 8031C418 AFAD0058 */  sw    $t5, 0x58($sp)
/* 0D741C 8031C41C AFAC005C */  sw    $t4, 0x5c($sp)
/* 0D7420 8031C420 0C0C67D9 */  jal   func_80318EC4
/* 0D7424 8031C424 A7AA003A */   sh    $t2, 0x3a($sp)
/* 0D7428 8031C428 3C013C00 */  li    $at, 0x3C000000 # 0.007812
/* 0D742C 8031C42C 44810000 */  mtc1  $at, $f0
/* 0D7430 8031C430 3C0B8022 */  lui   $t3, %hi(D_802214F8) # $t3, 0x8022
/* 0D7434 8031C434 3C1F8022 */  lui   $ra, %hi(D_80226D60) # $ra, 0x8022
/* 0D7438 8031C438 27FF6B60 */  addiu $ra, %lo(D_80226D60) # addiu $ra, $ra, 0x6b60
/* 0D743C 8031C43C 256B10F8 */  addiu $t3, %lo(D_802214F8) # addiu $t3, $t3, 0x10f8
/* 0D7440 8031C440 240900FF */  li    $t1, 255
/* 0D7444 8031C444 97AA003A */  lhu   $t2, 0x3a($sp)
/* 0D7448 8031C448 8FAC005C */  lw    $t4, 0x5c($sp)
/* 0D744C 8031C44C 1000FF51 */  b     .L8031C194
/* 0D7450 8031C450 8FAD0058 */   lw    $t5, 0x58($sp)
glabel L_U_8031C454
/* 0D7454 8031C454 26020054 */  addiu $v0, $s0, 0x54
/* 0D7458 8031C458 8C430000 */  lw    $v1, ($v0)
/* 0D745C 8031C45C 90640000 */  lbu   $a0, ($v1)
/* 0D7460 8031C460 246E0001 */  addiu $t6, $v1, 1
/* 0D7464 8031C464 AC4E0000 */  sw    $t6, ($v0)
/* 0D7468 8031C468 30990080 */  andi  $t9, $a0, 0x80
/* 0D746C 8031C46C 1320000A */  beqz  $t9, .L8031C498
/* 0D7470 8031C470 00802825 */   move  $a1, $a0
/* 0D7474 8031C474 01C01825 */  move  $v1, $t6
/* 0D7478 8031C478 91CE0000 */  lbu   $t6, ($t6)
/* 0D747C 8031C47C 00052200 */  sll   $a0, $a1, 8
/* 0D7480 8031C480 308F7F00 */  andi  $t7, $a0, 0x7f00
/* 0D7484 8031C484 01CF2025 */  or    $a0, $t6, $t7
/* 0D7488 8031C488 3085FFFF */  andi  $a1, $a0, 0xffff
/* 0D748C 8031C48C 24780001 */  addiu $t8, $v1, 1
/* 0D7490 8031C490 AC580000 */  sw    $t8, ($v0)
/* 0D7494 8031C494 00A02025 */  move  $a0, $a1
.L8031C498:
/* 0D7498 8031C498 308AFFFF */  andi  $t2, $a0, 0xffff
/* 0D749C 8031C49C 1000FF3D */  b     .L8031C194
/* 0D74A0 8031C4A0 A6050038 */   sh    $a1, 0x38($s0)
glabel L_U_8031C4A4
/* 0D74A4 8031C4A4 26020054 */  addiu $v0, $s0, 0x54
/* 0D74A8 8031C4A8 8C430000 */  lw    $v1, ($v0)
/* 0D74AC 8031C4AC 246F0001 */  addiu $t7, $v1, 1
/* 0D74B0 8031C4B0 AC4F0000 */  sw    $t7, ($v0)
/* 0D74B4 8031C4B4 90650000 */  lbu   $a1, ($v1)
/* 0D74B8 8031C4B8 28A1007F */  slti  $at, $a1, 0x7f
/* 0D74BC 8031C4BC 5020FF36 */  beql  $at, $zero, .L8031C198
/* 0D74C0 8031C4C0 8E020054 */   lw    $v0, 0x54($s0)
/* 0D74C4 8031C4C4 91B90005 */  lbu   $t9, 5($t5)
/* 0D74C8 8031C4C8 8FEE0000 */  lw    $t6, ($ra)
/* 0D74CC 8031C4CC 30A200FF */  andi  $v0, $a1, 0xff
/* 0D74D0 8031C4D0 0019C080 */  sll   $t8, $t9, 2
/* 0D74D4 8031C4D4 0319C023 */  subu  $t8, $t8, $t9
/* 0D74D8 8031C4D8 0018C080 */  sll   $t8, $t8, 2
/* 0D74DC 8031C4DC 01D83821 */  addu  $a3, $t6, $t8
/* 0D74E0 8031C4E0 90E30001 */  lbu   $v1, 1($a3)
/* 0D74E4 8031C4E4 00A3082A */  slt   $at, $a1, $v1
/* 0D74E8 8031C4E8 54200008 */  bnezl $at, .L8031C50C
/* 0D74EC 8031C4EC 8CE30004 */   lw    $v1, 4($a3)
/* 0D74F0 8031C4F0 306200FF */  andi  $v0, $v1, 0xff
/* 0D74F4 8031C4F4 5040FF28 */  beql  $v0, $zero, .L8031C198
/* 0D74F8 8031C4F8 8E020054 */   lw    $v0, 0x54($s0)
/* 0D74FC 8031C4FC 2442FFFF */  addiu $v0, $v0, -1
/* 0D7500 8031C500 304F00FF */  andi  $t7, $v0, 0xff
/* 0D7504 8031C504 01E01025 */  move  $v0, $t7
/* 0D7508 8031C508 8CE30004 */  lw    $v1, 4($a3)
.L8031C50C:
/* 0D750C 8031C50C 0002C880 */  sll   $t9, $v0, 2
/* 0D7510 8031C510 26050048 */  addiu $a1, $s0, 0x48
/* 0D7514 8031C514 00797021 */  addu  $t6, $v1, $t9
/* 0D7518 8031C518 8DC40000 */  lw    $a0, ($t6)
/* 0D751C 8031C51C 5480000C */  bnezl $a0, .L8031C550
/* 0D7520 8031C520 8D630004 */   lw    $v1, 4($t3)
/* 0D7524 8031C524 11220009 */  beq   $t1, $v0, .L8031C54C
.L8031C528:
/* 0D7528 8031C528 0002C080 */   sll   $t8, $v0, 2
/* 0D752C 8031C52C 00787821 */  addu  $t7, $v1, $t8
/* 0D7530 8031C530 8DE40000 */  lw    $a0, ($t7)
/* 0D7534 8031C534 54800006 */  bnezl $a0, .L8031C550
/* 0D7538 8031C538 8D630004 */   lw    $v1, 4($t3)
/* 0D753C 8031C53C 2442FFFF */  addiu $v0, $v0, -1
/* 0D7540 8031C540 305900FF */  andi  $t9, $v0, 0xff
/* 0D7544 8031C544 1539FFF8 */  bne   $t1, $t9, .L8031C528
/* 0D7548 8031C548 03201025 */   move  $v0, $t9
.L8031C54C:
/* 0D754C 8031C54C 8D630004 */  lw    $v1, 4($t3)
.L8031C550:
/* 0D7550 8031C550 0083082B */  sltu  $at, $a0, $v1
/* 0D7554 8031C554 54200007 */  bnezl $at, .L8031C574
/* 0D7558 8031C558 8D630198 */   lw    $v1, 0x198($t3)
/* 0D755C 8031C55C 8D6E000C */  lw    $t6, 0xc($t3)
/* 0D7560 8031C560 006EC021 */  addu  $t8, $v1, $t6
/* 0D7564 8031C564 0304082B */  sltu  $at, $t8, $a0
/* 0D7568 8031C568 5020000B */  beql  $at, $zero, .L8031C598
/* 0D756C 8031C56C 8C8E0004 */   lw    $t6, 4($a0)
/* 0D7570 8031C570 8D630198 */  lw    $v1, 0x198($t3)
.L8031C574:
/* 0D7574 8031C574 0083082B */  sltu  $at, $a0, $v1
/* 0D7578 8031C578 5420000E */  bnezl $at, .L8031C5B4
/* 0D757C 8031C57C 3C010002 */   lui   $at, 2
/* 0D7580 8031C580 8D6F01A0 */  lw    $t7, 0x1a0($t3)
/* 0D7584 8031C584 006FC821 */  addu  $t9, $v1, $t7
/* 0D7588 8031C588 0324082B */  sltu  $at, $t9, $a0
/* 0D758C 8031C58C 54200009 */  bnezl $at, .L8031C5B4
/* 0D7590 8031C590 3C010002 */   lui   $at, 2
/* 0D7594 8031C594 8C8E0004 */  lw    $t6, 4($a0)
.L8031C598:
/* 0D7598 8031C598 26020014 */  addiu $v0, $s0, 0x14
/* 0D759C 8031C59C AC4E0004 */  sw    $t6, 4($v0)
/* 0D75A0 8031C5A0 90980003 */  lbu   $t8, 3($a0)
/* 0D75A4 8031C5A4 A0580000 */  sb    $t8, ($v0)
/* 0D75A8 8031C5A8 1000FEFA */  b     .L8031C194
/* 0D75AC 8031C5AC ACA40000 */   sw    $a0, ($a1)
/* 0D75B0 8031C5B0 3C010002 */  lui   $at, 2
.L8031C5B4:
/* 0D75B4 8031C5B4 00417821 */  addu  $t7, $v0, $at
/* 0D75B8 8031C5B8 3C018033 */  lui   $at, %hi(D_80331D40) # $at, 0x8033
/* 0D75BC 8031C5BC AC2F2E50 */  sw    $t7, %lo(D_80331D40)($at)
/* 0D75C0 8031C5C0 1000FEF4 */  b     .L8031C194
/* 0D75C4 8031C5C4 ACA00000 */   sw    $zero, ($a1)
glabel L_U_8031C5C8
/* 0D75C8 8031C5C8 26020054 */  addiu $v0, $s0, 0x54
/* 0D75CC 8031C5CC 8C430000 */  lw    $v1, ($v0)
/* 0D75D0 8031C5D0 24790001 */  addiu $t9, $v1, 1
/* 0D75D4 8031C5D4 AC590000 */  sw    $t9, ($v0)
/* 0D75D8 8031C5D8 90650000 */  lbu   $a1, ($v1)
/* 0D75DC 8031C5DC A2050004 */  sb    $a1, 4($s0)
/* 0D75E0 8031C5E0 8C430000 */  lw    $v1, ($v0)
/* 0D75E4 8031C5E4 246E0001 */  addiu $t6, $v1, 1
/* 0D75E8 8031C5E8 AC4E0000 */  sw    $t6, ($v0)
/* 0D75EC 8031C5EC 85B8001A */  lh    $t8, 0x1a($t5)
/* 0D75F0 8031C5F0 90670000 */  lbu   $a3, ($v1)
/* 0D75F4 8031C5F4 8619001E */  lh    $t9, 0x1e($s0)
/* 0D75F8 8031C5F8 03077821 */  addu  $t7, $t8, $a3
/* 0D75FC 8031C5FC 85980010 */  lh    $t8, 0x10($t4)
/* 0D7600 8031C600 01F97021 */  addu  $t6, $t7, $t9
/* 0D7604 8031C604 01D84021 */  addu  $t0, $t6, $t8
/* 0D7608 8031C608 310F00FF */  andi  $t7, $t0, 0xff
/* 0D760C 8031C60C 29E10080 */  slti  $at, $t7, 0x80
/* 0D7610 8031C610 14200002 */  bnez  $at, .L8031C61C
/* 0D7614 8031C614 01E04025 */   move  $t0, $t7
/* 0D7618 8031C618 00004025 */  move  $t0, $zero
.L8031C61C:
/* 0D761C 8031C61C 92190004 */  lbu   $t9, 4($s0)
/* 0D7620 8031C620 A2080003 */  sb    $t0, 3($s0)
/* 0D7624 8031C624 332E0080 */  andi  $t6, $t9, 0x80
/* 0D7628 8031C628 51C00009 */  beql  $t6, $zero, .L8031C650
/* 0D762C 8031C62C 8C430000 */   lw    $v1, ($v0)
/* 0D7630 8031C630 8C580000 */  lw    $t8, ($v0)
/* 0D7634 8031C634 930F0000 */  lbu   $t7, ($t8)
/* 0D7638 8031C638 A60F001C */  sh    $t7, 0x1c($s0)
/* 0D763C 8031C63C 8C590000 */  lw    $t9, ($v0)
/* 0D7640 8031C640 272E0001 */  addiu $t6, $t9, 1
/* 0D7644 8031C644 1000FED3 */  b     .L8031C194
/* 0D7648 8031C648 AC4E0000 */   sw    $t6, ($v0)
/* 0D764C 8031C64C 8C430000 */  lw    $v1, ($v0)
.L8031C650:
/* 0D7650 8031C650 90640000 */  lbu   $a0, ($v1)
/* 0D7654 8031C654 24780001 */  addiu $t8, $v1, 1
/* 0D7658 8031C658 AC580000 */  sw    $t8, ($v0)
/* 0D765C 8031C65C 308F0080 */  andi  $t7, $a0, 0x80
/* 0D7660 8031C660 11E0000A */  beqz  $t7, .L8031C68C
/* 0D7664 8031C664 00802825 */   move  $a1, $a0
/* 0D7668 8031C668 03001825 */  move  $v1, $t8
/* 0D766C 8031C66C 93180000 */  lbu   $t8, ($t8)
/* 0D7670 8031C670 00052200 */  sll   $a0, $a1, 8
/* 0D7674 8031C674 308E7F00 */  andi  $t6, $a0, 0x7f00
/* 0D7678 8031C678 030E2025 */  or    $a0, $t8, $t6
/* 0D767C 8031C67C 308FFFFF */  andi  $t7, $a0, 0xffff
/* 0D7680 8031C680 24790001 */  addiu $t9, $v1, 1
/* 0D7684 8031C684 AC590000 */  sw    $t9, ($v0)
/* 0D7688 8031C688 01E02025 */  move  $a0, $t7
.L8031C68C:
/* 0D768C 8031C68C 308AFFFF */  andi  $t2, $a0, 0xffff
/* 0D7690 8031C690 1000FEC0 */  b     .L8031C194
/* 0D7694 8031C694 A604001C */   sh    $a0, 0x1c($s0)
glabel L_U_8031C698
/* 0D7698 8031C698 1000FEBE */  b     .L8031C194
/* 0D769C 8031C69C A2000004 */   sb    $zero, 4($s0)
glabel L_U_8031C6A0
.L8031C6A0:
/* 0D76A0 8031C6A0 30A200F0 */  andi  $v0, $a1, 0xf0
/* 0D76A4 8031C6A4 240100D0 */  li    $at, 208
/* 0D76A8 8031C6A8 10410005 */  beq   $v0, $at, .L8031C6C0
/* 0D76AC 8031C6AC 240100E0 */   li    $at, 224
/* 0D76B0 8031C6B0 5041000F */  beql  $v0, $at, .L8031C6F0
/* 0D76B4 8031C6B4 8D8E008C */   lw    $t6, 0x8c($t4)
/* 0D76B8 8031C6B8 1000FEB7 */  b     .L8031C198
/* 0D76BC 8031C6BC 8E020054 */   lw    $v0, 0x54($s0)
.L8031C6C0:
/* 0D76C0 8031C6C0 8D8E0088 */  lw    $t6, 0x88($t4)
/* 0D76C4 8031C6C4 30B8000F */  andi  $t8, $a1, 0xf
/* 0D76C8 8031C6C8 01D87821 */  addu  $t7, $t6, $t8
/* 0D76CC 8031C6CC 91EA0000 */  lbu   $t2, ($t7)
/* 0D76D0 8031C6D0 014A0019 */  multu $t2, $t2
/* 0D76D4 8031C6D4 0000C812 */  mflo  $t9
/* 0D76D8 8031C6D8 44999000 */  mtc1  $t9, $f18
/* 0D76DC 8031C6DC 00000000 */  nop   
/* 0D76E0 8031C6E0 46809120 */  cvt.s.w $f4, $f18
/* 0D76E4 8031C6E4 1000FEAB */  b     .L8031C194
/* 0D76E8 8031C6E8 E6040024 */   swc1  $f4, 0x24($s0)
/* 0D76EC 8031C6EC 8D8E008C */  lw    $t6, 0x8c($t4)
.L8031C6F0:
/* 0D76F0 8031C6F0 30B8000F */  andi  $t8, $a1, 0xf
/* 0D76F4 8031C6F4 01D87821 */  addu  $t7, $t6, $t8
/* 0D76F8 8031C6F8 91F90000 */  lbu   $t9, ($t7)
/* 0D76FC 8031C6FC 1000FEA5 */  b     .L8031C194
/* 0D7700 8031C700 A2190002 */   sb    $t9, 2($s0)
.L8031C704:
/* 0D7704 8031C704 240100C0 */  li    $at, 192
/* 0D7708 8031C708 14A10015 */  bne   $a1, $at, .L8031C760
/* 0D770C 8031C70C 26020054 */   addiu $v0, $s0, 0x54
/* 0D7710 8031C710 8C430000 */  lw    $v1, ($v0)
/* 0D7714 8031C714 90640000 */  lbu   $a0, ($v1)
/* 0D7718 8031C718 246E0001 */  addiu $t6, $v1, 1
/* 0D771C 8031C71C AC4E0000 */  sw    $t6, ($v0)
/* 0D7720 8031C720 30980080 */  andi  $t8, $a0, 0x80
/* 0D7724 8031C724 13000009 */  beqz  $t8, .L8031C74C
/* 0D7728 8031C728 00802825 */   move  $a1, $a0
/* 0D772C 8031C72C 01C01825 */  move  $v1, $t6
/* 0D7730 8031C730 91CE0000 */  lbu   $t6, ($t6)
/* 0D7734 8031C734 00042200 */  sll   $a0, $a0, 8
/* 0D7738 8031C738 30997F00 */  andi  $t9, $a0, 0x7f00
/* 0D773C 8031C73C 246F0001 */  addiu $t7, $v1, 1
/* 0D7740 8031C740 01D92025 */  or    $a0, $t6, $t9
/* 0D7744 8031C744 3085FFFF */  andi  $a1, $a0, 0xffff
/* 0D7748 8031C748 AC4F0000 */  sw    $t7, ($v0)
.L8031C74C:
/* 0D774C 8031C74C 920E0000 */  lbu   $t6, ($s0)
/* 0D7750 8031C750 A605003C */  sh    $a1, 0x3c($s0)
/* 0D7754 8031C754 35D80020 */  ori   $t8, $t6, 0x20
/* 0D7758 8031C758 10000181 */  b     .L8031CD60
/* 0D775C 8031C75C A2180000 */   sb    $t8, ($s0)
.L8031C760:
/* 0D7760 8031C760 920F0000 */  lbu   $t7, ($s0)
/* 0D7764 8031C764 24010001 */  li    $at, 1
/* 0D7768 8031C768 30A900C0 */  andi  $t1, $a1, 0xc0
/* 0D776C 8031C76C 31F9FFDF */  andi  $t9, $t7, 0xffdf
/* 0D7770 8031C770 A2190000 */  sb    $t9, ($s0)
/* 0D7774 8031C774 8DAE0000 */  lw    $t6, ($t5)
/* 0D7778 8031C778 000EC180 */  sll   $t8, $t6, 6
/* 0D777C 8031C77C 00187FC2 */  srl   $t7, $t8, 0x1f
/* 0D7780 8031C780 15E10057 */  bne   $t7, $at, .L8031C8E0
/* 0D7784 8031C784 00000000 */   nop   
/* 0D7788 8031C788 30A900C0 */  andi  $t1, $a1, 0xc0
/* 0D778C 8031C78C 11200009 */  beqz  $t1, .L8031C7B4
/* 0D7790 8031C790 26020054 */   addiu $v0, $s0, 0x54
/* 0D7794 8031C794 24010040 */  li    $at, 64
/* 0D7798 8031C798 11210023 */  beq   $t1, $at, .L8031C828
/* 0D779C 8031C79C 26020054 */   addiu $v0, $s0, 0x54
/* 0D77A0 8031C7A0 24010080 */  li    $at, 128
/* 0D77A4 8031C7A4 11210039 */  beq   $t1, $at, .L8031C88C
/* 0D77A8 8031C7A8 26020054 */   addiu $v0, $s0, 0x54
/* 0D77AC 8031C7AC 10000043 */  b     .L8031C8BC
/* 0D77B0 8031C7B0 01402025 */   move  $a0, $t2
.L8031C7B4:
/* 0D77B4 8031C7B4 8C430000 */  lw    $v1, ($v0)
/* 0D77B8 8031C7B8 90660000 */  lbu   $a2, ($v1)
/* 0D77BC 8031C7BC 24790001 */  addiu $t9, $v1, 1
/* 0D77C0 8031C7C0 AC590000 */  sw    $t9, ($v0)
/* 0D77C4 8031C7C4 30CE0080 */  andi  $t6, $a2, 0x80
/* 0D77C8 8031C7C8 11C0000A */  beqz  $t6, .L8031C7F4
/* 0D77CC 8031C7CC 00C03825 */   move  $a3, $a2
/* 0D77D0 8031C7D0 03201825 */  move  $v1, $t9
/* 0D77D4 8031C7D4 93390000 */  lbu   $t9, ($t9)
/* 0D77D8 8031C7D8 00073200 */  sll   $a2, $a3, 8
/* 0D77DC 8031C7DC 30CF7F00 */  andi  $t7, $a2, 0x7f00
/* 0D77E0 8031C7E0 032F3025 */  or    $a2, $t9, $t7
/* 0D77E4 8031C7E4 30C7FFFF */  andi  $a3, $a2, 0xffff
/* 0D77E8 8031C7E8 24780001 */  addiu $t8, $v1, 1
/* 0D77EC 8031C7EC AC580000 */  sw    $t8, ($v0)
/* 0D77F0 8031C7F0 00E03025 */  move  $a2, $a3
.L8031C7F4:
/* 0D77F4 8031C7F4 8C430000 */  lw    $v1, ($v0)
/* 0D77F8 8031C7F8 30CAFFFF */  andi  $t2, $a2, 0xffff
/* 0D77FC 8031C7FC 01402025 */  move  $a0, $t2
/* 0D7800 8031C800 906B0000 */  lbu   $t3, ($v1)
/* 0D7804 8031C804 246F0001 */  addiu $t7, $v1, 1
/* 0D7808 8031C808 AC4F0000 */  sw    $t7, ($v0)
/* 0D780C 8031C80C 91EE0000 */  lbu   $t6, ($t7)
/* 0D7810 8031C810 A20E0002 */  sb    $t6, 2($s0)
/* 0D7814 8031C814 8C580000 */  lw    $t8, ($v0)
/* 0D7818 8031C818 270F0001 */  addiu $t7, $t8, 1
/* 0D781C 8031C81C AC4F0000 */  sw    $t7, ($v0)
/* 0D7820 8031C820 10000027 */  b     .L8031C8C0
/* 0D7824 8031C824 A607003A */   sh    $a3, 0x3a($s0)
.L8031C828:
/* 0D7828 8031C828 8C430000 */  lw    $v1, ($v0)
/* 0D782C 8031C82C 90660000 */  lbu   $a2, ($v1)
/* 0D7830 8031C830 24790001 */  addiu $t9, $v1, 1
/* 0D7834 8031C834 AC590000 */  sw    $t9, ($v0)
/* 0D7838 8031C838 30CE0080 */  andi  $t6, $a2, 0x80
/* 0D783C 8031C83C 11C0000A */  beqz  $t6, .L8031C868
/* 0D7840 8031C840 00C03825 */   move  $a3, $a2
/* 0D7844 8031C844 03201825 */  move  $v1, $t9
/* 0D7848 8031C848 93390000 */  lbu   $t9, ($t9)
/* 0D784C 8031C84C 00073200 */  sll   $a2, $a3, 8
/* 0D7850 8031C850 30CF7F00 */  andi  $t7, $a2, 0x7f00
/* 0D7854 8031C854 032F3025 */  or    $a2, $t9, $t7
/* 0D7858 8031C858 30C7FFFF */  andi  $a3, $a2, 0xffff
/* 0D785C 8031C85C 24780001 */  addiu $t8, $v1, 1
/* 0D7860 8031C860 AC580000 */  sw    $t8, ($v0)
/* 0D7864 8031C864 00E03025 */  move  $a2, $a3
.L8031C868:
/* 0D7868 8031C868 8C430000 */  lw    $v1, ($v0)
/* 0D786C 8031C86C 30CAFFFF */  andi  $t2, $a2, 0xffff
/* 0D7870 8031C870 01402025 */  move  $a0, $t2
/* 0D7874 8031C874 906B0000 */  lbu   $t3, ($v1)
/* 0D7878 8031C878 246F0001 */  addiu $t7, $v1, 1
/* 0D787C 8031C87C AC4F0000 */  sw    $t7, ($v0)
/* 0D7880 8031C880 A2000002 */  sb    $zero, 2($s0)
/* 0D7884 8031C884 1000000E */  b     .L8031C8C0
/* 0D7888 8031C888 A607003A */   sh    $a3, 0x3a($s0)
.L8031C88C:
/* 0D788C 8031C88C 8C430000 */  lw    $v1, ($v0)
/* 0D7890 8031C890 960A003A */  lhu   $t2, 0x3a($s0)
/* 0D7894 8031C894 906B0000 */  lbu   $t3, ($v1)
/* 0D7898 8031C898 24790001 */  addiu $t9, $v1, 1
/* 0D789C 8031C89C AC590000 */  sw    $t9, ($v0)
/* 0D78A0 8031C8A0 93380000 */  lbu   $t8, ($t9)
/* 0D78A4 8031C8A4 01402025 */  move  $a0, $t2
/* 0D78A8 8031C8A8 A2180002 */  sb    $t8, 2($s0)
/* 0D78AC 8031C8AC 8C4F0000 */  lw    $t7, ($v0)
/* 0D78B0 8031C8B0 25F90001 */  addiu $t9, $t7, 1
/* 0D78B4 8031C8B4 10000002 */  b     .L8031C8C0
/* 0D78B8 8031C8B8 AC590000 */   sw    $t9, ($v0)
.L8031C8BC:
/* 0D78BC 8031C8BC 8FAB0030 */  lw    $t3, 0x30($sp)
.L8031C8C0:
/* 0D78C0 8031C8C0 016B0019 */  multu $t3, $t3
/* 0D78C4 8031C8C4 00A91823 */  subu  $v1, $a1, $t1
/* 0D78C8 8031C8C8 00007012 */  mflo  $t6
/* 0D78CC 8031C8CC 448E3000 */  mtc1  $t6, $f6
/* 0D78D0 8031C8D0 00000000 */  nop   
/* 0D78D4 8031C8D4 46803220 */  cvt.s.w $f8, $f6
/* 0D78D8 8031C8D8 10000024 */  b     .L8031C96C
/* 0D78DC 8031C8DC E6080024 */   swc1  $f8, 0x24($s0)
.L8031C8E0:
/* 0D78E0 8031C8E0 11200008 */  beqz  $t1, .L8031C904
/* 0D78E4 8031C8E4 26020054 */   addiu $v0, $s0, 0x54
/* 0D78E8 8031C8E8 24010040 */  li    $at, 64
/* 0D78EC 8031C8EC 11210019 */  beq   $t1, $at, .L8031C954
/* 0D78F0 8031C8F0 24010080 */   li    $at, 128
/* 0D78F4 8031C8F4 5121001B */  beql  $t1, $at, .L8031C964
/* 0D78F8 8031C8F8 960A003A */   lhu   $t2, 0x3a($s0)
/* 0D78FC 8031C8FC 1000001A */  b     .L8031C968
/* 0D7900 8031C900 01402025 */   move  $a0, $t2
.L8031C904:
/* 0D7904 8031C904 8C430000 */  lw    $v1, ($v0)
/* 0D7908 8031C908 90660000 */  lbu   $a2, ($v1)
/* 0D790C 8031C90C 24780001 */  addiu $t8, $v1, 1
/* 0D7910 8031C910 AC580000 */  sw    $t8, ($v0)
/* 0D7914 8031C914 30CF0080 */  andi  $t7, $a2, 0x80
/* 0D7918 8031C918 11E0000A */  beqz  $t7, .L8031C944
/* 0D791C 8031C91C 00C03825 */   move  $a3, $a2
/* 0D7920 8031C920 03001825 */  move  $v1, $t8
/* 0D7924 8031C924 93180000 */  lbu   $t8, ($t8)
/* 0D7928 8031C928 00073200 */  sll   $a2, $a3, 8
/* 0D792C 8031C92C 30CE7F00 */  andi  $t6, $a2, 0x7f00
/* 0D7930 8031C930 030E3025 */  or    $a2, $t8, $t6
/* 0D7934 8031C934 30C7FFFF */  andi  $a3, $a2, 0xffff
/* 0D7938 8031C938 24790001 */  addiu $t9, $v1, 1
/* 0D793C 8031C93C AC590000 */  sw    $t9, ($v0)
/* 0D7940 8031C940 00E03025 */  move  $a2, $a3
.L8031C944:
/* 0D7944 8031C944 30CAFFFF */  andi  $t2, $a2, 0xffff
/* 0D7948 8031C948 A607003A */  sh    $a3, 0x3a($s0)
/* 0D794C 8031C94C 10000006 */  b     .L8031C968
/* 0D7950 8031C950 01402025 */   move  $a0, $t2
.L8031C954:
/* 0D7954 8031C954 960A0038 */  lhu   $t2, 0x38($s0)
/* 0D7958 8031C958 10000003 */  b     .L8031C968
/* 0D795C 8031C95C 01402025 */   move  $a0, $t2
/* 0D7960 8031C960 960A003A */  lhu   $t2, 0x3a($s0)
.L8031C964:
/* 0D7964 8031C964 01402025 */  move  $a0, $t2
.L8031C968:
/* 0D7968 8031C968 00A91823 */  subu  $v1, $a1, $t1
.L8031C96C:
/* 0D796C 8031C96C 920E0002 */  lbu   $t6, 2($s0)
/* 0D7970 8031C970 A604003C */  sh    $a0, 0x3c($s0)
/* 0D7974 8031C974 01C40019 */  multu $t6, $a0
/* 0D7978 8031C978 0000C012 */  mflo  $t8
/* 0D797C 8031C97C 07010003 */  bgez  $t8, .L8031C98C
/* 0D7980 8031C980 00187A03 */   sra   $t7, $t8, 8
/* 0D7984 8031C984 270100FF */  addiu $at, $t8, 0xff
/* 0D7988 8031C988 00017A03 */  sra   $t7, $at, 8
.L8031C98C:
/* 0D798C 8031C98C A60F003E */  sh    $t7, 0x3e($s0)
/* 0D7990 8031C990 8D990000 */  lw    $t9, ($t4)
/* 0D7994 8031C994 0019C080 */  sll   $t8, $t9, 2
/* 0D7998 8031C998 07030006 */  bgezl $t8, .L8031C9B4
/* 0D799C 8031C99C 8DA20000 */   lw    $v0, ($t5)
/* 0D79A0 8031C9A0 91AF0002 */  lbu   $t7, 2($t5)
/* 0D79A4 8031C9A4 31F90040 */  andi  $t9, $t7, 0x40
/* 0D79A8 8031C9A8 57200008 */  bnezl $t9, .L8031C9CC
/* 0D79AC 8031C9AC 92180000 */   lbu   $t8, ($s0)
/* 0D79B0 8031C9B0 8DA20000 */  lw    $v0, ($t5)
.L8031C9B4:
/* 0D79B4 8031C9B4 0002C0C0 */  sll   $t8, $v0, 3
/* 0D79B8 8031C9B8 07000003 */  bltz  $t8, .L8031C9C8
/* 0D79BC 8031C9BC 0002C900 */   sll   $t9, $v0, 4
/* 0D79C0 8031C9C0 07220006 */  bltzl $t9, .L8031C9DC
/* 0D79C4 8031C9C4 85B90018 */   lh    $t9, 0x18($t5)
.L8031C9C8:
/* 0D79C8 8031C9C8 92180000 */  lbu   $t8, ($s0)
.L8031C9CC:
/* 0D79CC 8031C9CC 370F0020 */  ori   $t7, $t8, 0x20
/* 0D79D0 8031C9D0 100000E3 */  b     .L8031CD60
/* 0D79D4 8031C9D4 A20F0000 */   sb    $t7, ($s0)
/* 0D79D8 8031C9D8 85B90018 */  lh    $t9, 0x18($t5)
.L8031C9DC:
/* 0D79DC 8031C9DC 57200035 */  bnezl $t9, .L8031CAB4
/* 0D79E0 8031C9E0 85980010 */   lh    $t8, 0x10($t4)
/* 0D79E4 8031C9E4 85B8001A */  lh    $t8, 0x1a($t5)
/* 0D79E8 8031C9E8 8619001E */  lh    $t9, 0x1e($s0)
/* 0D79EC 8031C9EC 00787821 */  addu  $t7, $v1, $t8
/* 0D79F0 8031C9F0 01F94021 */  addu  $t0, $t7, $t9
/* 0D79F4 8031C9F4 91AF0005 */  lbu   $t7, 5($t5)
/* 0D79F8 8031C9F8 8FF80000 */  lw    $t8, ($ra)
/* 0D79FC 8031C9FC 310E00FF */  andi  $t6, $t0, 0xff
/* 0D7A00 8031CA00 000FC880 */  sll   $t9, $t7, 2
/* 0D7A04 8031CA04 032FC823 */  subu  $t9, $t9, $t7
/* 0D7A08 8031CA08 0019C880 */  sll   $t9, $t9, 2
/* 0D7A0C 8031CA0C 03193821 */  addu  $a3, $t8, $t9
/* 0D7A10 8031CA10 90E20002 */  lbu   $v0, 2($a3)
/* 0D7A14 8031CA14 01C04025 */  move  $t0, $t6
/* 0D7A18 8031CA18 01C2082A */  slt   $at, $t6, $v0
/* 0D7A1C 8031CA1C 5420000C */  bnezl $at, .L8031CA50
/* 0D7A20 8031CA20 8CEE0008 */   lw    $t6, 8($a3)
/* 0D7A24 8031CA24 304800FF */  andi  $t0, $v0, 0xff
/* 0D7A28 8031CA28 55000006 */  bnezl $t0, .L8031CA44
/* 0D7A2C 8031CA2C 2508FFFF */   addiu $t0, $t0, -1
/* 0D7A30 8031CA30 920F0000 */  lbu   $t7, ($s0)
/* 0D7A34 8031CA34 35F80020 */  ori   $t8, $t7, 0x20
/* 0D7A38 8031CA38 100000C7 */  b     .L8031CD58
/* 0D7A3C 8031CA3C A2180000 */   sb    $t8, ($s0)
/* 0D7A40 8031CA40 2508FFFF */  addiu $t0, $t0, -1
.L8031CA44:
/* 0D7A44 8031CA44 311900FF */  andi  $t9, $t0, 0xff
/* 0D7A48 8031CA48 03204025 */  move  $t0, $t9
/* 0D7A4C 8031CA4C 8CEE0008 */  lw    $t6, 8($a3)
.L8031CA50:
/* 0D7A50 8031CA50 00087880 */  sll   $t7, $t0, 2
/* 0D7A54 8031CA54 01CFC021 */  addu  $t8, $t6, $t7
/* 0D7A58 8031CA58 8F020000 */  lw    $v0, ($t8)
/* 0D7A5C 8031CA5C 54400006 */  bnezl $v0, .L8031CA78
/* 0D7A60 8031CA60 8C58000C */   lw    $t8, 0xc($v0)
/* 0D7A64 8031CA64 920E0000 */  lbu   $t6, ($s0)
/* 0D7A68 8031CA68 35CF0020 */  ori   $t7, $t6, 0x20
/* 0D7A6C 8031CA6C 100000BA */  b     .L8031CD58
/* 0D7A70 8031CA70 A20F0000 */   sb    $t7, ($s0)
/* 0D7A74 8031CA74 8C58000C */  lw    $t8, 0xc($v0)
.L8031CA78:
/* 0D7A78 8031CA78 24430004 */  addiu $v1, $v0, 4
/* 0D7A7C 8031CA7C AE180018 */  sw    $t8, 0x18($s0)
/* 0D7A80 8031CA80 90590000 */  lbu   $t9, ($v0)
/* 0D7A84 8031CA84 A2190014 */  sb    $t9, 0x14($s0)
/* 0D7A88 8031CA88 904E0001 */  lbu   $t6, 1($v0)
/* 0D7A8C 8031CA8C AE03004C */  sw    $v1, 0x4c($s0)
/* 0D7A90 8031CA90 448E5000 */  mtc1  $t6, $f10
/* 0D7A94 8031CA94 00000000 */  nop   
/* 0D7A98 8031CA98 46805420 */  cvt.s.w $f16, $f10
/* 0D7A9C 8031CA9C 46008482 */  mul.s $f18, $f16, $f0
/* 0D7AA0 8031CAA0 E6120028 */  swc1  $f18, 0x28($s0)
/* 0D7AA4 8031CAA4 C4640004 */  lwc1  $f4, 4($v1)
/* 0D7AA8 8031CAA8 100000AB */  b     .L8031CD58
/* 0D7AAC 8031CAAC E6040020 */   swc1  $f4, 0x20($s0)
/* 0D7AB0 8031CAB0 85980010 */  lh    $t8, 0x10($t4)
.L8031CAB4:
/* 0D7AB4 8031CAB4 85AE001A */  lh    $t6, 0x1a($t5)
/* 0D7AB8 8031CAB8 0078C821 */  addu  $t9, $v1, $t8
/* 0D7ABC 8031CABC 8618001E */  lh    $t8, 0x1e($s0)
/* 0D7AC0 8031CAC0 032E7821 */  addu  $t7, $t9, $t6
/* 0D7AC4 8031CAC4 01F84021 */  addu  $t0, $t7, $t8
/* 0D7AC8 8031CAC8 310200FF */  andi  $v0, $t0, 0xff
/* 0D7ACC 8031CACC 28410080 */  slti  $at, $v0, 0x80
/* 0D7AD0 8031CAD0 14200005 */  bnez  $at, .L8031CAE8
/* 0D7AD4 8031CAD4 00404025 */   move  $t0, $v0
/* 0D7AD8 8031CAD8 920F0000 */  lbu   $t7, ($s0)
/* 0D7ADC 8031CADC 35F80020 */  ori   $t8, $t7, 0x20
/* 0D7AE0 8031CAE0 1000009D */  b     .L8031CD58
/* 0D7AE4 8031CAE4 A2180000 */   sb    $t8, ($s0)
.L8031CAE8:
/* 0D7AE8 8031CAE8 8E030048 */  lw    $v1, 0x48($s0)
/* 0D7AEC 8031CAEC 54600003 */  bnezl $v1, .L8031CAFC
/* 0D7AF0 8031CAF0 92190004 */   lbu   $t9, 4($s0)
/* 0D7AF4 8031CAF4 8DA3003C */  lw    $v1, 0x3c($t5)
/* 0D7AF8 8031CAF8 92190004 */  lbu   $t9, 4($s0)
.L8031CAFC:
/* 0D7AFC 8031CAFC 13200073 */  beqz  $t9, .L8031CCCC
/* 0D7B00 8031CB00 00000000 */   nop   
/* 0D7B04 8031CB04 92040003 */  lbu   $a0, 3($s0)
/* 0D7B08 8031CB08 0082082A */  slt   $at, $a0, $v0
/* 0D7B0C 8031CB0C 10200003 */  beqz  $at, .L8031CB1C
/* 0D7B10 8031CB10 00802825 */   move  $a1, $a0
/* 0D7B14 8031CB14 10000001 */  b     .L8031CB1C
/* 0D7B18 8031CB18 00402825 */   move  $a1, $v0
.L8031CB1C:
/* 0D7B1C 8031CB1C 10600017 */  beqz  $v1, .L8031CB7C
/* 0D7B20 8031CB20 3C013F80 */   li    $at, 0x3F800000 # 1.000000
/* 0D7B24 8031CB24 906E0001 */  lbu   $t6, 1($v1)
/* 0D7B28 8031CB28 30A200FF */  andi  $v0, $a1, 0xff
/* 0D7B2C 8031CB2C 004E082A */  slt   $at, $v0, $t6
/* 0D7B30 8031CB30 50200004 */  beql  $at, $zero, .L8031CB44
/* 0D7B34 8031CB34 906F0002 */   lbu   $t7, 2($v1)
/* 0D7B38 8031CB38 10000009 */  b     .L8031CB60
/* 0D7B3C 8031CB3C 24620008 */   addiu $v0, $v1, 8
/* 0D7B40 8031CB40 906F0002 */  lbu   $t7, 2($v1)
.L8031CB44:
/* 0D7B44 8031CB44 24640018 */  addiu $a0, $v1, 0x18
/* 0D7B48 8031CB48 01E2082A */  slt   $at, $t7, $v0
/* 0D7B4C 8031CB4C 14200003 */  bnez  $at, .L8031CB5C
/* 0D7B50 8031CB50 00000000 */   nop   
/* 0D7B54 8031CB54 10000001 */  b     .L8031CB5C
/* 0D7B58 8031CB58 24640010 */   addiu $a0, $v1, 0x10
.L8031CB5C:
/* 0D7B5C 8031CB5C 00801025 */  move  $v0, $a0
.L8031CB60:
/* 0D7B60 8031CB60 8E18004C */  lw    $t8, 0x4c($s0)
/* 0D7B64 8031CB64 0058C826 */  xor   $t9, $v0, $t8
/* 0D7B68 8031CB68 2F390001 */  sltiu $t9, $t9, 1
/* 0D7B6C 8031CB6C A3B9003F */  sb    $t9, 0x3f($sp)
/* 0D7B70 8031CB70 AE02004C */  sw    $v0, 0x4c($s0)
/* 0D7B74 8031CB74 10000003 */  b     .L8031CB84
/* 0D7B78 8031CB78 C4400004 */   lwc1  $f0, 4($v0)
.L8031CB7C:
/* 0D7B7C 8031CB7C 44810000 */  mtc1  $at, $f0
/* 0D7B80 8031CB80 AE00004C */  sw    $zero, 0x4c($s0)
.L8031CB84:
/* 0D7B84 8031CB84 3C038033 */  lui   $v1, %hi(D_80332884) # $v1, 0x8033
/* 0D7B88 8031CB88 24633994 */  addiu $v1, %lo(D_80332884) # addiu $v1, $v1, 0x3994
/* 0D7B8C 8031CB8C 00087080 */  sll   $t6, $t0, 2
/* 0D7B90 8031CB90 92180003 */  lbu   $t8, 3($s0)
/* 0D7B94 8031CB94 006E7821 */  addu  $t7, $v1, $t6
/* 0D7B98 8031CB98 C5E60000 */  lwc1  $f6, ($t7)
/* 0D7B9C 8031CB9C 920F0004 */  lbu   $t7, 4($s0)
/* 0D7BA0 8031CBA0 0018C880 */  sll   $t9, $t8, 2
/* 0D7BA4 8031CBA4 00797021 */  addu  $t6, $v1, $t9
/* 0D7BA8 8031CBA8 C5C80000 */  lwc1  $f8, ($t6)
/* 0D7BAC 8031CBAC 46003082 */  mul.s $f2, $f6, $f0
/* 0D7BB0 8031CBB0 2401FF7F */  li    $at, -129
/* 0D7BB4 8031CBB4 01E1C024 */  and   $t8, $t7, $at
/* 0D7BB8 8031CBB8 2719FFFF */  addiu $t9, $t8, -1
/* 0D7BBC 8031CBBC 2F210005 */  sltiu $at, $t9, 5
/* 0D7BC0 8031CBC0 46004302 */  mul.s $f12, $f8, $f0
/* 0D7BC4 8031CBC4 1020000C */  beqz  $at, .L8031CBF8
/* 0D7BC8 8031CBC8 0019C880 */   sll   $t9, $t9, 2
/* 0D7BCC 8031CBCC 3C018034 */  lui   $at, %hi(jtbl_80337CDC)
/* 0D7BD0 8031CBD0 00390821 */  addu  $at, $at, $t9
/* 0D7BD4 8031CBD4 8C398EAC */  lw    $t9, %lo(jtbl_80337CDC)($at)
/* 0D7BD8 8031CBD8 03200008 */  jr    $t9
/* 0D7BDC 8031CBDC 00000000 */   nop   
glabel L_U_8031CBE0
/* 0D7BE0 8031CBE0 E7A20024 */  swc1  $f2, 0x24($sp)
/* 0D7BE4 8031CBE4 10000005 */  b     .L8031CBFC
/* 0D7BE8 8031CBE8 46006006 */   mov.s $f0, $f12
glabel L_U_8031CBEC
/* 0D7BEC 8031CBEC 46001006 */  mov.s $f0, $f2
/* 0D7BF0 8031CBF0 10000002 */  b     .L8031CBFC
/* 0D7BF4 8031CBF4 E7AC0024 */   swc1  $f12, 0x24($sp)
.L8031CBF8:
/* 0D7BF8 8031CBF8 C7A00028 */  lwc1  $f0, 0x28($sp)
.L8031CBFC:
/* 0D7BFC 8031CBFC C7AA0024 */  lwc1  $f10, 0x24($sp)
/* 0D7C00 8031CC00 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0D7C04 8031CC04 44819000 */  mtc1  $at, $f18
/* 0D7C08 8031CC08 46005403 */  div.s $f16, $f10, $f0
/* 0D7C0C 8031CC0C 26020004 */  addiu $v0, $s0, 4
/* 0D7C10 8031CC10 3C0146FE */  li    $at, 0x46FE0000 # 32512.000000
/* 0D7C14 8031CC14 46128101 */  sub.s $f4, $f16, $f18
/* 0D7C18 8031CC18 E444000C */  swc1  $f4, 0xc($v0)
/* 0D7C1C 8031CC1C 920E0004 */  lbu   $t6, 4($s0)
/* 0D7C20 8031CC20 31CF0080 */  andi  $t7, $t6, 0x80
/* 0D7C24 8031CC24 51E00017 */  beql  $t7, $zero, .L8031CC84
/* 0D7C28 8031CC28 9618001C */   lhu   $t8, 0x1c($s0)
/* 0D7C2C 8031CC2C 9598000A */  lhu   $t8, 0xa($t4)
/* 0D7C30 8031CC30 3C0E8022 */  lui   $t6, %hi(D_80226D7C) # $t6, 0x8022
/* 0D7C34 8031CC34 85CE6B7C */  lh    $t6, %lo(D_80226D7C)($t6)
/* 0D7C38 8031CC38 44984000 */  mtc1  $t8, $f8
/* 0D7C3C 8031CC3C 8619003C */  lh    $t9, 0x3c($s0)
/* 0D7C40 8031CC40 44813000 */  mtc1  $at, $f6
/* 0D7C44 8031CC44 468042A0 */  cvt.s.w $f10, $f8
/* 0D7C48 8031CC48 448E4000 */  mtc1  $t6, $f8
/* 0D7C4C 8031CC4C 44999000 */  mtc1  $t9, $f18
/* 0D7C50 8031CC50 960F001C */  lhu   $t7, 0x1c($s0)
/* 0D7C54 8031CC54 46809120 */  cvt.s.w $f4, $f18
/* 0D7C58 8031CC58 460A3402 */  mul.s $f16, $f6, $f10
/* 0D7C5C 8031CC5C 448F9000 */  mtc1  $t7, $f18
/* 0D7C60 8031CC60 468041A0 */  cvt.s.w $f6, $f8
/* 0D7C64 8031CC64 46809220 */  cvt.s.w $f8, $f18
/* 0D7C68 8031CC68 46062282 */  mul.s $f10, $f4, $f6
/* 0D7C6C 8031CC6C 00000000 */  nop   
/* 0D7C70 8031CC70 460A4102 */  mul.s $f4, $f8, $f10
/* 0D7C74 8031CC74 46048183 */  div.s $f6, $f16, $f4
/* 0D7C78 8031CC78 10000009 */  b     .L8031CCA0
/* 0D7C7C 8031CC7C E4460008 */   swc1  $f6, 8($v0)
/* 0D7C80 8031CC80 9618001C */  lhu   $t8, 0x1c($s0)
.L8031CC84:
/* 0D7C84 8031CC84 3C0142FE */  li    $at, 0x42FE0000 # 127.000000
/* 0D7C88 8031CC88 44819000 */  mtc1  $at, $f18
/* 0D7C8C 8031CC8C 44984000 */  mtc1  $t8, $f8
/* 0D7C90 8031CC90 00000000 */  nop   
/* 0D7C94 8031CC94 468042A0 */  cvt.s.w $f10, $f8
/* 0D7C98 8031CC98 460A9403 */  div.s $f16, $f18, $f10
/* 0D7C9C 8031CC9C E4500008 */  swc1  $f16, 8($v0)
.L8031CCA0:
/* 0D7CA0 8031CCA0 44802000 */  mtc1  $zero, $f4
/* 0D7CA4 8031CCA4 2401FF7F */  li    $at, -129
/* 0D7CA8 8031CCA8 E4440004 */  swc1  $f4, 4($v0)
/* 0D7CAC 8031CCAC 92190004 */  lbu   $t9, 4($s0)
/* 0D7CB0 8031CCB0 E6000020 */  swc1  $f0, 0x20($s0)
/* 0D7CB4 8031CCB4 03217024 */  and   $t6, $t9, $at
/* 0D7CB8 8031CCB8 24010005 */  li    $at, 5
/* 0D7CBC 8031CCBC 55C10027 */  bnel  $t6, $at, .L8031CD5C
/* 0D7CC0 8031CCC0 860F003C */   lh    $t7, 0x3c($s0)
/* 0D7CC4 8031CCC4 10000024 */  b     .L8031CD58
/* 0D7CC8 8031CCC8 A2080003 */   sb    $t0, 3($s0)
.L8031CCCC:
/* 0D7CCC 8031CCCC 1060001C */  beqz  $v1, .L8031CD40
/* 0D7CD0 8031CCD0 0008C880 */   sll   $t9, $t0, 2
/* 0D7CD4 8031CCD4 906F0001 */  lbu   $t7, 1($v1)
/* 0D7CD8 8031CCD8 004F082A */  slt   $at, $v0, $t7
/* 0D7CDC 8031CCDC 10200003 */  beqz  $at, .L8031CCEC
/* 0D7CE0 8031CCE0 00087880 */   sll   $t7, $t0, 2
/* 0D7CE4 8031CCE4 10000009 */  b     .L8031CD0C
/* 0D7CE8 8031CCE8 24620008 */   addiu $v0, $v1, 8
.L8031CCEC:
/* 0D7CEC 8031CCEC 90780002 */  lbu   $t8, 2($v1)
/* 0D7CF0 8031CCF0 24640018 */  addiu $a0, $v1, 0x18
/* 0D7CF4 8031CCF4 0302082A */  slt   $at, $t8, $v0
/* 0D7CF8 8031CCF8 14200003 */  bnez  $at, .L8031CD08
/* 0D7CFC 8031CCFC 00000000 */   nop   
/* 0D7D00 8031CD00 10000001 */  b     .L8031CD08
/* 0D7D04 8031CD04 24640010 */   addiu $a0, $v1, 0x10
.L8031CD08:
/* 0D7D08 8031CD08 00801025 */  move  $v0, $a0
.L8031CD0C:
/* 0D7D0C 8031CD0C 8E19004C */  lw    $t9, 0x4c($s0)
/* 0D7D10 8031CD10 3C038033 */  lui   $v1, %hi(D_80332884) # $v1, 0x8033
/* 0D7D14 8031CD14 24633994 */  addiu $v1, %lo(D_80332884) # addiu $v1, $v1, 0x3994
/* 0D7D18 8031CD18 00597026 */  xor   $t6, $v0, $t9
/* 0D7D1C 8031CD1C 2DCE0001 */  sltiu $t6, $t6, 1
/* 0D7D20 8031CD20 A3AE003F */  sb    $t6, 0x3f($sp)
/* 0D7D24 8031CD24 AE02004C */  sw    $v0, 0x4c($s0)
/* 0D7D28 8031CD28 006FC021 */  addu  $t8, $v1, $t7
/* 0D7D2C 8031CD2C C7080000 */  lwc1  $f8, ($t8)
/* 0D7D30 8031CD30 C4460004 */  lwc1  $f6, 4($v0)
/* 0D7D34 8031CD34 46083482 */  mul.s $f18, $f6, $f8
/* 0D7D38 8031CD38 10000007 */  b     .L8031CD58
/* 0D7D3C 8031CD3C E6120020 */   swc1  $f18, 0x20($s0)
.L8031CD40:
/* 0D7D40 8031CD40 3C038033 */  lui   $v1, %hi(D_80332884) # $v1, 0x8033
/* 0D7D44 8031CD44 24633994 */  addiu $v1, %lo(D_80332884) # addiu $v1, $v1, 0x3994
/* 0D7D48 8031CD48 AE00004C */  sw    $zero, 0x4c($s0)
/* 0D7D4C 8031CD4C 00797021 */  addu  $t6, $v1, $t9
/* 0D7D50 8031CD50 C5CA0000 */  lwc1  $f10, ($t6)
/* 0D7D54 8031CD54 E60A0020 */  swc1  $f10, 0x20($s0)
.L8031CD58:
/* 0D7D58 8031CD58 860F003C */  lh    $t7, 0x3c($s0)
.L8031CD5C:
/* 0D7D5C 8031CD5C A60F0040 */  sh    $t7, 0x40($s0)
.L8031CD60:
/* 0D7D60 8031CD60 8E020000 */  lw    $v0, ($s0)
/* 0D7D64 8031CD64 24010001 */  li    $at, 1
/* 0D7D68 8031CD68 0002C080 */  sll   $t8, $v0, 2
/* 0D7D6C 8031CD6C 0018CFC2 */  srl   $t9, $t8, 0x1f
/* 0D7D70 8031CD70 5721000C */  bnel  $t9, $at, .L8031CDA4
/* 0D7D74 8031CD74 000270C0 */   sll   $t6, $v0, 3
/* 0D7D78 8031CD78 8E0E0044 */  lw    $t6, 0x44($s0)
/* 0D7D7C 8031CD7C 0002C0C0 */  sll   $t8, $v0, 3
/* 0D7D80 8031CD80 15C00003 */  bnez  $t6, .L8031CD90
/* 0D7D84 8031CD84 00000000 */   nop   
/* 0D7D88 8031CD88 0703002E */  bgezl $t8, .L8031CE44
/* 0D7D8C 8031CD8C 8FBF001C */   lw    $ra, 0x1c($sp)
.L8031CD90:
/* 0D7D90 8031CD90 0C0C67D9 */  jal   func_80318EC4
/* 0D7D94 8031CD94 02002025 */   move  $a0, $s0
/* 0D7D98 8031CD98 1000002A */  b     .L8031CE44
/* 0D7D9C 8031CD9C 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0D7DA0 8031CDA0 000270C0 */  sll   $t6, $v0, 3
.L8031CDA4:
/* 0D7DA4 8031CDA4 05C00003 */  bltz  $t6, .L8031CDB4
/* 0D7DA8 8031CDA8 00004025 */   move  $t0, $zero
/* 0D7DAC 8031CDAC 10000017 */  b     .L8031CE0C
/* 0D7DB0 8031CDB0 24080001 */   li    $t0, 1
.L8031CDB4:
/* 0D7DB4 8031CDB4 8E040044 */  lw    $a0, 0x44($s0)
/* 0D7DB8 8031CDB8 10800005 */  beqz  $a0, .L8031CDD0
/* 0D7DBC 8031CDBC 00000000 */   nop   
/* 0D7DC0 8031CDC0 920F0001 */  lbu   $t7, 1($s0)
/* 0D7DC4 8031CDC4 93B8003F */  lbu   $t8, 0x3f($sp)
/* 0D7DC8 8031CDC8 15E00003 */  bnez  $t7, .L8031CDD8
/* 0D7DCC 8031CDCC 00000000 */   nop   
.L8031CDD0:
/* 0D7DD0 8031CDD0 1000000E */  b     .L8031CE0C
/* 0D7DD4 8031CDD4 24080001 */   li    $t0, 1
.L8031CDD8:
/* 0D7DD8 8031CDD8 57000006 */  bnezl $t8, .L8031CDF4
/* 0D7DDC 8031CDDC 8E19004C */   lw    $t9, 0x4c($s0)
/* 0D7DE0 8031CDE0 0C0C67D9 */  jal   func_80318EC4
/* 0D7DE4 8031CDE4 02002025 */   move  $a0, $s0
/* 0D7DE8 8031CDE8 10000008 */  b     .L8031CE0C
/* 0D7DEC 8031CDEC 24080001 */   li    $t0, 1
/* 0D7DF0 8031CDF0 8E19004C */  lw    $t9, 0x4c($s0)
.L8031CDF4:
/* 0D7DF4 8031CDF4 02002825 */  move  $a1, $s0
/* 0D7DF8 8031CDF8 17200004 */  bnez  $t9, .L8031CE0C
/* 0D7DFC 8031CDFC 00000000 */   nop   
/* 0D7E00 8031CE00 0C0C6874 */  jal   func_80319164
/* 0D7E04 8031CE04 A3A8003D */   sb    $t0, 0x3d($sp)
/* 0D7E08 8031CE08 93A8003D */  lbu   $t0, 0x3d($sp)
.L8031CE0C:
/* 0D7E0C 8031CE0C 51000005 */  beql  $t0, $zero, .L8031CE24
/* 0D7E10 8031CE10 8E040044 */   lw    $a0, 0x44($s0)
/* 0D7E14 8031CE14 0C0C6A53 */  jal   func_803198E0
/* 0D7E18 8031CE18 02002025 */   move  $a0, $s0
/* 0D7E1C 8031CE1C AE020044 */  sw    $v0, 0x44($s0)
/* 0D7E20 8031CE20 8E040044 */  lw    $a0, 0x44($s0)
.L8031CE24:
/* 0D7E24 8031CE24 50800007 */  beql  $a0, $zero, .L8031CE44
/* 0D7E28 8031CE28 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0D7E2C 8031CE2C 8C8E002C */  lw    $t6, 0x2c($a0)
/* 0D7E30 8031CE30 560E0004 */  bnel  $s0, $t6, .L8031CE44
/* 0D7E34 8031CE34 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0D7E38 8031CE38 0C0C6D28 */  jal   func_8031A478
/* 0D7E3C 8031CE3C 00000000 */   nop   
.L8031CE40:
/* 0D7E40 8031CE40 8FBF001C */  lw    $ra, 0x1c($sp)
.L8031CE44:
/* 0D7E44 8031CE44 8FB00018 */  lw    $s0, 0x18($sp)
/* 0D7E48 8031CE48 27BD0060 */  addiu $sp, $sp, 0x60
/* 0D7E4C 8031CE4C 03E00008 */  jr    $ra
/* 0D7E50 8031CE50 00000000 */   nop   
)
#endif

u8 func_8031BEB0(struct Struct80225DD8 *arg0, u8 arg1, struct InstrumentSomething **arg2, struct Substruct80225DD8 *arg3)
{
    struct InstrumentSomething *a2;
    UNUSED u32 pad;

    if (arg1 >= D_80226D60[arg0->unk5].unk1)
    {
        arg1 = D_80226D60[arg0->unk5].unk1;
        if (arg1 == 0)
        {
            return 0;
        }
        arg1--;
    }

    a2 = D_80226D60[arg0->unk5].unk4[arg1];
    if (a2 == NULL)
    {
        struct Struct80225DD8 sp10 = *arg0;

        while (arg1 != 0xff)
        {
            a2 = D_80226D60[sp10.unk5].unk4[arg1];
            if (a2 != NULL)
                break;
            arg1--;
        }
    }

    if (((u32)D_802214F8.first.pool.unk0 <= (u32)a2 &&
            (u32)a2 <= (u32)(D_802214F8.first.pool.unk0 + D_802214F8.first.pool.unk8)) ||
        ((u32)D_802214F8.second.pool.unk0 <= (u32)a2 &&
            (u32)a2 <= (u32)(D_802214F8.second.pool.unk0 + D_802214F8.second.pool.unk8)))
    {
        arg3->unk4 = a2->unk4;
        arg3->unk0 = a2->unk3;
        *arg2 = a2;
        arg1++;
        return arg1;
    }

    D_80331D40 = arg1 + 0x20000;
    *arg2 = NULL;
    return 0;
}

void SetInstrument(struct Struct80225DD8 *arg0, u8 arg1)
{
    if (arg1 >= 0x80)
    {
        arg0->unk18 = arg1;
        arg0->unk3C = NULL;
    }
    else if (arg1 == 0x7f)
    {
        arg0->unk18 = 0;
        arg0->unk3C = INSTRUMENT_SENTINEL;
    }
    else
    {
        arg0->unk18 = func_8031BEB0(arg0, arg1, &arg0->unk3C, &arg0->unk78);
        if (arg0->unk18 == 0)
        {
            arg0->unk0b8 = 0;
            return;
        }
    }
    arg0->unk0b8 = 1;
}

void func_8031C0C4(struct Struct80225DD8 *arg0, u8 arg1)
{
    arg0->unk20 = FLOAT_CAST(arg1) / US_FLOAT(127.0);
}

#ifdef NON_MATCHING

void func_8031C104(struct Struct80225DD8 *arg0)
{
    u16 sp5A;
    s8 value; // sp53
    u8 sp38;
    u8 instr; // v1, s1
    u8 loBits; // t0, a0
    struct Interface1Buffer *buf;
    struct Struct80222A18 *unk40;
    u8 temp;
    s8 tempSigned;
    s32 temp32;
    s32 i;
    u8 temp2;

    if (!arg0->unk0b80)
    {
        return;
    }

    if (arg0->unk0b20)
    {
        for (i = 0; i < 4; i++)
        {
            if (arg0->unk44[i] != 0)
            {
                func_8031B0A4(arg0->unk44[i]);
            }
        }
        return;
    }

    unk40 = arg0->unk40;
    if (unk40->unk0b20 && (arg0->unk2 & 0x80) != 0)
    {
        return;
    }

    if (arg0->unk16 != 0)
    {
        arg0->unk16--;
    }

    buf = &arg0->unk5C;
    if (arg0->unk16 == 0)
    {
        for (;;)
        {
            instr = func_8031B01C(buf);
            if (instr == 0xff)
            {
                // This fixes a reordering in 'case 0x90', somehow
                sp5A = buf->unk18;
                if (sp5A == 0)
                {
                    func_8031AAD0(arg0);
                    break;
                }
                buf->unk18--,
                buf->unk0 = buf->unk4[buf->unk18];
            }
            if (instr == 0xfe)
            {
                break;
            }
            if (instr == 0xfd)
            {
                arg0->unk16 = func_8031B060(buf);
                break;
            }
            if (instr == 0xf3)
            {
                arg0->unk0b20 = 1;
                break;
            }

            // (new_var = instr fixes order of s1/s2, but causes a reordering
            // towards the bottom of the function)
            if (instr > 0xc0)
            {
                switch (instr)
                {
                case 0xfc:
                    sp5A = func_8031B030(buf);
                    buf->unk18++,
                    buf->unk4[buf->unk18 - 1] = buf->unk0;
                    buf->unk0 = unk40->unk14 + sp5A;
                    break;
                case 0xf8:
                    buf->unk14[buf->unk18] = func_8031B01C(buf);
                    buf->unk18++,
                    buf->unk4[buf->unk18 - 1] = buf->unk0;
                    break;
                case 0xf7:
                    buf->unk14[buf->unk18 - 1]--;
                    if (buf->unk14[buf->unk18 - 1] != 0)
                    {
                        buf->unk0 = buf->unk4[buf->unk18 - 1];
                    }
                    else
                    {
                        buf->unk18--;
                    }
                    break;
                case 0xf6:
                    buf->unk18--;
                    break;
                case 0xf5:
                case 0xf9:
                case 0xfa:
                case 0xfb:
                    sp5A = func_8031B030(buf);
                    if (instr == 0xfa && value != 0) break;
                    if (instr == 0xf9 && value >= 0) break;
                    if (instr == 0xf5 && value < 0) break;
                    buf->unk0 = unk40->unk14 + sp5A;
                    break;
                case 0xf2:
                    // arg0->unk80 should live in a saved register
                    func_803192FC(arg0->unk80);
                    temp = func_8031B01C(buf);
                    func_80319428(arg0->unk80, temp);
                    break;
                case 0xf1:
                    func_803192FC(arg0->unk80);
                    break;
                case 0xc2:
                    sp5A = func_8031B030(buf);
                    arg0->unk30 = (void *)(unk40->unk14 + sp5A);
                    break;
                case 0xc5:
                    if (value != -1)
                    {
                        sp5A = (*arg0->unk30)[value][1] + ((*arg0->unk30)[value][0] << 8);
                        arg0->unk30 = (void *)(unk40->unk14 + sp5A);
                    }
                    break;
                case 0xc1:
                    SetInstrument(arg0, func_8031B01C(buf));
                    break;
                case 0xc3:
                    arg0->unk0b2 = 0;
                    break;
                case 0xc4:
                    arg0->unk0b2 = 1;
                    break;
                case 0xdf:
                    func_8031C0C4(arg0, func_8031B01C(buf));
                    break;
                case 0xe0:
                    arg0->unk1C = FLOAT_CAST(func_8031B01C(buf)) / US_FLOAT(128.0);
                    break;
                case 0xde:
                    sp5A = func_8031B030(buf);
                    arg0->unk2C = FLOAT_CAST(sp5A) / US_FLOAT(32768.0);
                    break;
                case 0xd3:
                    temp = func_8031B01C(buf) + 0x7f;
                    arg0->unk2C = D_80332488[temp];
                    break;
                case 0xdd:
                    arg0->unk24 = FLOAT_CAST(func_8031B01C(buf)) / US_FLOAT(128.0);
                    break;
                case 0xdc:
                    arg0->unk28 = FLOAT_CAST(func_8031B01C(buf)) / US_FLOAT(128.0);
                    break;
                case 0xdb:
                    tempSigned = *buf->unk0;
                    buf->unk0++;
                    arg0->unk1A = tempSigned;
                    break;
                case 0xda:
                    sp5A = func_8031B030(buf);
                    arg0->unk78.unk4 = (struct SubstructInstrumentSomething *)
                        (unk40->unk14 + sp5A);
                    break;
                case 0xd9:
                    arg0->unk78.unk0 = func_8031B01C(buf);
                    break;
                case 0xd8:
                    arg0->unkE = func_8031B01C(buf) * 8;
                    arg0->unkA = 0;
                    arg0->unk12 = 0;
                    break;
                case 0xd7:
                    arg0->unk8 = arg0->unkC = func_8031B01C(buf) * 32;
                    arg0->unk10 = 0;
                    break;
                case 0xe2:
                    arg0->unkA = func_8031B01C(buf) * 8;
                    arg0->unkE = func_8031B01C(buf) * 8;
                    arg0->unk12 = func_8031B01C(buf) * 16;
                    break;
                case 0xe1:
                    arg0->unk8 = func_8031B01C(buf) * 32;
                    arg0->unkC = func_8031B01C(buf) * 32;
                    arg0->unk10 = func_8031B01C(buf) * 16;
                    break;
                case 0xe3:
                    arg0->unk14 = func_8031B01C(buf) * 16;
                    break;
                case 0xd6:
                    temp = func_8031B01C(buf);
                    if (temp == 0)
                    {
                        temp = D_80226D7E;
                    }
                    arg0->unk6 = temp;
                    break;
                case 0xd4:
                    arg0->unk3 = func_8031B01C(buf);
                    break;
                case 0xc6:
                    temp = func_8031B01C(buf);
                    temp32 = ((u16 *)D_80226D58)[unk40->unk5];
                    temp = D_80226D58[temp32 + D_80226D58[temp32] - temp];
                    // temp should be in a saved register across this call
                    if (func_8031680C(&D_802214F8, 2, temp) != 0)
                    {
                        arg0->unk5 = temp;
                    }
                    break;
                case 0xc7:
                    // sp38 doesn't go on the stack
                    sp38 = value;
                    temp2 = func_8031B01C(buf);
                    sp5A = func_8031B030(buf);
                    unk40->unk14[sp5A] = sp38 + temp2;
                    break;
                case 0xc8:
                case 0xc9:
                case 0xcc:
                    temp = func_8031B01C(buf);
                    if (instr == 0xc8)
                    {
                        value -= temp;
                    }
                    else if (instr == 0xcc)
                    {
                        value = temp;
                    }
                    else
                    {
                        value &= temp;
                    }
                    break;
                case 0xca:
                    arg0->unk2 = func_8031B01C(buf);
                    break;
                case 0xcb:
                    sp5A = func_8031B030(buf);
                    value = unk40->unk14[sp5A + value];
                    break;
                case 0xd0:
                    arg0->unk0b4 = func_8031B01C(buf);
                    break;
                case 0xd1:
                    arg0->unk1 = func_8031B01C(buf);
                    break;
                case 0xd2:
                    arg0->unk78.unk2 = func_8031B01C(buf) << 8;
                    break;
                case 0xe4:
                    if (value != -1)
                    {
                        u8 (*thingy)[2] = *arg0->unk30;
                        buf->unk18++,
                        buf->unk4[buf->unk18 - 1] = buf->unk0;
                        sp5A = thingy[value][1] + (thingy[value][0] << 8);
                        buf->unk0 = unk40->unk14 + sp5A;
                    }
                    break;
                }
            }
            else
            {
                // loBits is recomputed a lot
                loBits = instr & 0xf;
                // #define loBits (instr & 0xf)
                switch (instr & 0xf0)
                {
                case 0x00:
                    if (arg0->unk44[loBits] != 0)
                    {
                        value = arg0->unk44[loBits]->unk0b40;
                    }
                    break;
                case 0x70:
                    arg0->unk54[loBits] = value;
                    break;
                case 0x80:
                    value = arg0->unk54[loBits];
                    if (loBits < 4)
                    {
                        arg0->unk54[loBits] = -1;
                    }
                    break;
                case 0x50:
                    value -= arg0->unk54[loBits];
                    break;
                case 0x90:
                    sp5A = func_8031B030(buf);
                    if (func_8031A920(arg0, loBits) == 0)
                    {
                        arg0->unk44[loBits]->unk54 = unk40->unk14 + sp5A;
                    }
                    break;
                case 0xa0:
                    func_8031AA4C(arg0, loBits);
                    break;
                case 0xb0:
                    if (value != -1 && func_8031A920(arg0, loBits) != -1)
                    {
                        temp = (*arg0->unk30)[value][0] + ((*arg0->unk30)[value][1] << 8);
                        arg0->unk44[loBits]->unk54 = unk40->unk14 + temp;
                    }
                    break;
                case 0x60:
                    arg0->unk4 = loBits;
                    break;
                case 0x10:
                    sp5A = func_8031B030(buf);
                    func_8031AD80(unk40, loBits, unk40->unk14 + sp5A);
                    break;
                case 0x20:
                    func_8031AAD0(unk40->unk2C[loBits]);
                    break;
                case 0x30:
                    unk40->unk2C[loBits]->unk54[func_8031B01C(buf)] = value;
                    break;
                case 0x40:
                    value = unk40->unk2C[loBits]->unk54[func_8031B01C(buf)];
                    break;
                }
            }
        }
    }

    for (i = 0; i < 4; i++)
    {
        if (arg0->unk44[i] != 0)
        {
            func_8031B0A4(arg0->unk44[i]);
        }
    }
}

#elif defined(VERSION_JP)
GLOBAL_ASM(
.late_rodata
.late_rodata_alignment 8
glabel jtbl_80337D08 # US: 80338EC0
	.word L8031C430
	.word L8031C3DC
	.word L8031C44C
	.word L8031C45C
	.word L8031C3F8
	.word L8031C6C8
	.word L8031C724
	.word L8031C75C
	.word L8031C75C
	.word L8031C7A8
	.word L8031C7B8
	.word L8031C75C
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C7D8
	.word L8031C7FC
	.word L8031C80C
	.word L8031C508
	.word L8031C6B8
	.word L8031C1CC
	.word L8031C698
	.word L8031C600
	.word L8031C5E4
	.word L8031C5D4
	.word L8031C5B8
	.word L8031C5A0
	.word L8031C568
	.word L8031C530
	.word L8031C4C0
	.word L8031C46C
	.word L8031C488
	.word L8031C650
	.word L8031C61C
	.word L8031C684
	.word L8031C820
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C3CC
	.word L8031C3A4
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C34C
	.word L8031C33C
	.word L8031C2F4
	.word L8031C2BC
	.word L8031C34C
	.word L8031C34C
	.word L8031C34C
	.word L8031C280
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC

glabel jtbl_80337E04 # US: 80338FBC
	.word L8031C89C
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C9E4
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031CA14
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031CA30
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031CA58
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C8F8
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C9DC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C8CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C8DC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C914
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C960
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C1CC
	.word L8031C97C

.text
glabel func_8031C104
/* 0D7104 8031C104 27BDFF98 */  addiu $sp, $sp, -0x68
/* 0D7108 8031C108 AFBF0034 */  sw    $ra, 0x34($sp)
/* 0D710C 8031C10C AFB50030 */  sw    $s5, 0x30($sp)
/* 0D7110 8031C110 AFB4002C */  sw    $s4, 0x2c($sp)
/* 0D7114 8031C114 AFB30028 */  sw    $s3, 0x28($sp)
/* 0D7118 8031C118 AFB20024 */  sw    $s2, 0x24($sp)
/* 0D711C 8031C11C AFB10020 */  sw    $s1, 0x20($sp)
/* 0D7120 8031C120 AFB0001C */  sw    $s0, 0x1c($sp)
/* 0D7124 8031C124 F7B40010 */  sdc1  $f20, 0x10($sp)
/* 0D7128 8031C128 8C820000 */  lw    $v0, ($a0)
/* 0D712C 8031C12C 00809025 */  move  $s2, $a0
/* 0D7130 8031C130 000277C2 */  srl   $t6, $v0, 0x1f
/* 0D7134 8031C134 11C0025D */  beqz  $t6, .L8031CAAC
/* 0D7138 8031C138 0002C080 */   sll   $t8, $v0, 2
/* 0D713C 8031C13C 0701000D */  bgez  $t8, .L8031C174
/* 0D7140 8031C140 00008025 */   move  $s0, $zero
/* 0D7144 8031C144 00808825 */  move  $s1, $a0
/* 0D7148 8031C148 24120010 */  li    $s2, 16
.L8031C14C:
/* 0D714C 8031C14C 8E240044 */  lw    $a0, 0x44($s1)
/* 0D7150 8031C150 50800004 */  beql  $a0, $zero, .L8031C164
/* 0D7154 8031C154 26100004 */   addiu $s0, $s0, 4
/* 0D7158 8031C158 0C0C6C29 */  jal   func_8031B0A4
/* 0D715C 8031C15C 00000000 */   nop   
/* 0D7160 8031C160 26100004 */  addiu $s0, $s0, 4
.L8031C164:
/* 0D7164 8031C164 1612FFF9 */  bne   $s0, $s2, .L8031C14C
/* 0D7168 8031C168 26310004 */   addiu $s1, $s1, 4
/* 0D716C 8031C16C 10000250 */  b     .L8031CAB0
/* 0D7170 8031C170 8FBF0034 */   lw    $ra, 0x34($sp)
.L8031C174:
/* 0D7174 8031C174 8E540040 */  lw    $s4, 0x40($s2)
/* 0D7178 8031C178 8E990000 */  lw    $t9, ($s4)
/* 0D717C 8031C17C 00195080 */  sll   $t2, $t9, 2
/* 0D7180 8031C180 05430006 */  bgezl $t2, .L8031C19C
/* 0D7184 8031C184 96430016 */   lhu   $v1, 0x16($s2)
/* 0D7188 8031C188 924B0002 */  lbu   $t3, 2($s2)
/* 0D718C 8031C18C 316C0080 */  andi  $t4, $t3, 0x80
/* 0D7190 8031C190 55800247 */  bnezl $t4, .L8031CAB0
/* 0D7194 8031C194 8FBF0034 */   lw    $ra, 0x34($sp)
/* 0D7198 8031C198 96430016 */  lhu   $v1, 0x16($s2)
.L8031C19C:
/* 0D719C 8031C19C 2650005C */  addiu $s0, $s2, 0x5c
/* 0D71A0 8031C1A0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0D71A4 8031C1A4 10600004 */  beqz  $v1, .L8031C1B8
/* 0D71A8 8031C1A8 00601025 */   move  $v0, $v1
/* 0D71AC 8031C1AC 246DFFFF */  addiu $t5, $v1, -1
/* 0D71B0 8031C1B0 A64D0016 */  sh    $t5, 0x16($s2)
/* 0D71B4 8031C1B4 31A2FFFF */  andi  $v0, $t5, 0xffff
.L8031C1B8:
/* 0D71B8 8031C1B8 14400231 */  bnez  $v0, .L8031CA80
/* 0D71BC 8031C1BC 2415FFFF */   li    $s5, -1
/* 0D71C0 8031C1C0 4481A800 */  mtc1  $at, $f21
/* 0D71C4 8031C1C4 4480A000 */  mtc1  $zero, $f20
/* 0D71C8 8031C1C8 83B30053 */  lb    $s3, 0x53($sp)
.L8031C1CC:
glabel L8031C1CC
/* 0D71CC 8031C1CC 0C0C6C07 */  jal   func_8031B01C
/* 0D71D0 8031C1D0 02002025 */   move  $a0, $s0
/* 0D71D4 8031C1D4 240100FF */  li    $at, 255
/* 0D71D8 8031C1D8 305100FF */  andi  $s1, $v0, 0xff
/* 0D71DC 8031C1DC 1441000E */  bne   $v0, $at, .L8031C218
/* 0D71E0 8031C1E0 00401825 */   move  $v1, $v0
/* 0D71E4 8031C1E4 92040018 */  lbu   $a0, 0x18($s0)
/* 0D71E8 8031C1E8 14800005 */  bnez  $a0, .L8031C200
/* 0D71EC 8031C1EC 248EFFFF */   addiu $t6, $a0, -1
/* 0D71F0 8031C1F0 0C0C6AB4 */  jal   func_8031AAD0
/* 0D71F4 8031C1F4 02402025 */   move  $a0, $s2
/* 0D71F8 8031C1F8 10000222 */  b     .L8031CA84
/* 0D71FC 8031C1FC 02408825 */   move  $s1, $s2
.L8031C200:
/* 0D7200 8031C200 31CF00FF */  andi  $t7, $t6, 0xff
/* 0D7204 8031C204 000FC080 */  sll   $t8, $t7, 2
/* 0D7208 8031C208 0218C821 */  addu  $t9, $s0, $t8
/* 0D720C 8031C20C A20E0018 */  sb    $t6, 0x18($s0)
/* 0D7210 8031C210 8F290004 */  lw    $t1, 4($t9)
/* 0D7214 8031C214 AE090000 */  sw    $t1, ($s0)
.L8031C218:
/* 0D7218 8031C218 240100FE */  li    $at, 254
/* 0D721C 8031C21C 10610218 */  beq   $v1, $at, .L8031CA80
/* 0D7220 8031C220 240100FD */   li    $at, 253
/* 0D7224 8031C224 14610005 */  bne   $v1, $at, .L8031C23C
/* 0D7228 8031C228 307900F0 */   andi  $t9, $v1, 0xf0
/* 0D722C 8031C22C 0C0C6C18 */  jal   func_8031B060
/* 0D7230 8031C230 02002025 */   move  $a0, $s0
/* 0D7234 8031C234 10000212 */  b     .L8031CA80
/* 0D7238 8031C238 A6420016 */   sh    $v0, 0x16($s2)
.L8031C23C:
/* 0D723C 8031C23C 240100F3 */  li    $at, 243
/* 0D7240 8031C240 14610005 */  bne   $v1, $at, .L8031C258
/* 0D7244 8031C244 246DFF3F */   addiu $t5, $v1, -0xc1
/* 0D7248 8031C248 924B0000 */  lbu   $t3, ($s2)
/* 0D724C 8031C24C 356C0020 */  ori   $t4, $t3, 0x20
/* 0D7250 8031C250 1000020B */  b     .L8031CA80
/* 0D7254 8031C254 A24C0000 */   sb    $t4, ($s2)
.L8031C258:
/* 0D7258 8031C258 286100C1 */  slti  $at, $v1, 0xc1
/* 0D725C 8031C25C 14200185 */  bnez  $at, .L8031C874
/* 0D7260 8031C260 2DA1003F */   sltiu $at, $t5, 0x3f
/* 0D7264 8031C264 1020FFD9 */  beqz  $at, .L8031C1CC
/* 0D7268 8031C268 000D6880 */   sll   $t5, $t5, 2
/* 0D726C 8031C26C 3C018033 */  lui   $at, %hi(jtbl_80337D08)
/* 0D7270 8031C270 002D0821 */  addu  $at, $at, $t5
/* 0D7274 8031C274 8C2D7D08 */  lw    $t5, %lo(jtbl_80337D08)($at)
/* 0D7278 8031C278 01A00008 */  jr    $t5
/* 0D727C 8031C27C 00000000 */   nop   
glabel L8031C280
/* 0D7280 8031C280 0C0C6C0C */  jal   func_8031B030
/* 0D7284 8031C284 02002025 */   move  $a0, $s0
/* 0D7288 8031C288 920E0018 */  lbu   $t6, 0x18($s0)
/* 0D728C 8031C28C 8E180000 */  lw    $t8, ($s0)
/* 0D7290 8031C290 304CFFFF */  andi  $t4, $v0, 0xffff
/* 0D7294 8031C294 25CF0001 */  addiu $t7, $t6, 1
/* 0D7298 8031C298 31F900FF */  andi  $t9, $t7, 0xff
/* 0D729C 8031C29C 00194880 */  sll   $t1, $t9, 2
/* 0D72A0 8031C2A0 02095021 */  addu  $t2, $s0, $t1
/* 0D72A4 8031C2A4 A20F0018 */  sb    $t7, 0x18($s0)
/* 0D72A8 8031C2A8 AD580000 */  sw    $t8, ($t2)
/* 0D72AC 8031C2AC 8E8B0014 */  lw    $t3, 0x14($s4)
/* 0D72B0 8031C2B0 016C6821 */  addu  $t5, $t3, $t4
/* 0D72B4 8031C2B4 1000FFC5 */  b     .L8031C1CC
/* 0D72B8 8031C2B8 AE0D0000 */   sw    $t5, ($s0)
glabel L8031C2BC
/* 0D72BC 8031C2BC 0C0C6C07 */  jal   func_8031B01C
/* 0D72C0 8031C2C0 02002025 */   move  $a0, $s0
/* 0D72C4 8031C2C4 920E0018 */  lbu   $t6, 0x18($s0)
/* 0D72C8 8031C2C8 020E7821 */  addu  $t7, $s0, $t6
/* 0D72CC 8031C2CC A1E20014 */  sb    $v0, 0x14($t7)
/* 0D72D0 8031C2D0 92190018 */  lbu   $t9, 0x18($s0)
/* 0D72D4 8031C2D4 8E180000 */  lw    $t8, ($s0)
/* 0D72D8 8031C2D8 27290001 */  addiu $t1, $t9, 1
/* 0D72DC 8031C2DC 312A00FF */  andi  $t2, $t1, 0xff
/* 0D72E0 8031C2E0 000A5880 */  sll   $t3, $t2, 2
/* 0D72E4 8031C2E4 020B6021 */  addu  $t4, $s0, $t3
/* 0D72E8 8031C2E8 A2090018 */  sb    $t1, 0x18($s0)
/* 0D72EC 8031C2EC 1000FFB7 */  b     .L8031C1CC
/* 0D72F0 8031C2F0 AD980000 */   sw    $t8, ($t4)
glabel L8031C2F4
/* 0D72F4 8031C2F4 920D0018 */  lbu   $t5, 0x18($s0)
/* 0D72F8 8031C2F8 020D1021 */  addu  $v0, $s0, $t5
/* 0D72FC 8031C2FC 904E0013 */  lbu   $t6, 0x13($v0)
/* 0D7300 8031C300 25CFFFFF */  addiu $t7, $t6, -1
/* 0D7304 8031C304 A04F0013 */  sb    $t7, 0x13($v0)
/* 0D7308 8031C308 92040018 */  lbu   $a0, 0x18($s0)
/* 0D730C 8031C30C 0204C821 */  addu  $t9, $s0, $a0
/* 0D7310 8031C310 93290013 */  lbu   $t1, 0x13($t9)
/* 0D7314 8031C314 00801825 */  move  $v1, $a0
/* 0D7318 8031C318 00035080 */  sll   $t2, $v1, 2
/* 0D731C 8031C31C 11200005 */  beqz  $t1, .L8031C334
/* 0D7320 8031C320 248CFFFF */   addiu $t4, $a0, -1
/* 0D7324 8031C324 020A5821 */  addu  $t3, $s0, $t2
/* 0D7328 8031C328 8D780000 */  lw    $t8, ($t3)
/* 0D732C 8031C32C 1000FFA7 */  b     .L8031C1CC
/* 0D7330 8031C330 AE180000 */   sw    $t8, ($s0)
.L8031C334:
/* 0D7334 8031C334 1000FFA5 */  b     .L8031C1CC
/* 0D7338 8031C338 A20C0018 */   sb    $t4, 0x18($s0)
glabel L8031C33C
/* 0D733C 8031C33C 920D0018 */  lbu   $t5, 0x18($s0)
/* 0D7340 8031C340 25AEFFFF */  addiu $t6, $t5, -1
/* 0D7344 8031C344 1000FFA1 */  b     .L8031C1CC
/* 0D7348 8031C348 A20E0018 */   sb    $t6, 0x18($s0)
glabel L8031C34C
/* 0D734C 8031C34C 0C0C6C0C */  jal   func_8031B030
/* 0D7350 8031C350 02002025 */   move  $a0, $s0
/* 0D7354 8031C354 240100FA */  li    $at, 250
/* 0D7358 8031C358 16210003 */  bne   $s1, $at, .L8031C368
/* 0D735C 8031C35C 02201825 */   move  $v1, $s1
/* 0D7360 8031C360 1660FF9A */  bnez  $s3, .L8031C1CC
/* 0D7364 8031C364 00000000 */   nop   
.L8031C368:
/* 0D7368 8031C368 240100F9 */  li    $at, 249
/* 0D736C 8031C36C 54610004 */  bnel  $v1, $at, .L8031C380
/* 0D7370 8031C370 240100F5 */   li    $at, 245
/* 0D7374 8031C374 0661FF95 */  bgez  $s3, .L8031C1CC
/* 0D7378 8031C378 00000000 */   nop   
/* 0D737C 8031C37C 240100F5 */  li    $at, 245
.L8031C380:
/* 0D7380 8031C380 54610004 */  bnel  $v1, $at, .L8031C394
/* 0D7384 8031C384 8E8F0014 */   lw    $t7, 0x14($s4)
/* 0D7388 8031C388 0660FF90 */  bltz  $s3, .L8031C1CC
/* 0D738C 8031C38C 00000000 */   nop   
/* 0D7390 8031C390 8E8F0014 */  lw    $t7, 0x14($s4)
.L8031C394:
/* 0D7394 8031C394 3059FFFF */  andi  $t9, $v0, 0xffff
/* 0D7398 8031C398 01F94821 */  addu  $t1, $t7, $t9
/* 0D739C 8031C39C 1000FF8B */  b     .L8031C1CC
/* 0D73A0 8031C3A0 AE090000 */   sw    $t1, ($s0)
glabel L8031C3A4
/* 0D73A4 8031C3A4 26510080 */  addiu $s1, $s2, 0x80
/* 0D73A8 8031C3A8 0C0C64BF */  jal   func_803192FC
/* 0D73AC 8031C3AC 02202025 */   move  $a0, $s1
/* 0D73B0 8031C3B0 0C0C6C07 */  jal   func_8031B01C
/* 0D73B4 8031C3B4 02002025 */   move  $a0, $s0
/* 0D73B8 8031C3B8 02202025 */  move  $a0, $s1
/* 0D73BC 8031C3BC 0C0C650A */  jal   func_80319428
/* 0D73C0 8031C3C0 00402825 */   move  $a1, $v0
/* 0D73C4 8031C3C4 1000FF81 */  b     .L8031C1CC
/* 0D73C8 8031C3C8 00000000 */   nop   
glabel L8031C3CC
/* 0D73CC 8031C3CC 0C0C64BF */  jal   func_803192FC
/* 0D73D0 8031C3D0 26440080 */   addiu $a0, $s2, 0x80
/* 0D73D4 8031C3D4 1000FF7D */  b     .L8031C1CC
/* 0D73D8 8031C3D8 00000000 */   nop   
glabel L8031C3DC
/* 0D73DC 8031C3DC 0C0C6C0C */  jal   func_8031B030
/* 0D73E0 8031C3E0 02002025 */   move  $a0, $s0
/* 0D73E4 8031C3E4 8E8A0014 */  lw    $t2, 0x14($s4)
/* 0D73E8 8031C3E8 304BFFFF */  andi  $t3, $v0, 0xffff
/* 0D73EC 8031C3EC 014BC021 */  addu  $t8, $t2, $t3
/* 0D73F0 8031C3F0 1000FF76 */  b     .L8031C1CC
/* 0D73F4 8031C3F4 AE580030 */   sw    $t8, 0x30($s2)
glabel L8031C3F8
/* 0D73F8 8031C3F8 1275FF74 */  beq   $s3, $s5, .L8031C1CC
/* 0D73FC 8031C3FC 00000000 */   nop   
/* 0D7400 8031C400 8E4C0030 */  lw    $t4, 0x30($s2)
/* 0D7404 8031C404 00136840 */  sll   $t5, $s3, 1
/* 0D7408 8031C408 8E8A0014 */  lw    $t2, 0x14($s4)
/* 0D740C 8031C40C 018D1021 */  addu  $v0, $t4, $t5
/* 0D7410 8031C410 904F0000 */  lbu   $t7, ($v0)
/* 0D7414 8031C414 904E0001 */  lbu   $t6, 1($v0)
/* 0D7418 8031C418 000FCA00 */  sll   $t9, $t7, 8
/* 0D741C 8031C41C 01D93821 */  addu  $a3, $t6, $t9
/* 0D7420 8031C420 30E9FFFF */  andi  $t1, $a3, 0xffff
/* 0D7424 8031C424 01495821 */  addu  $t3, $t2, $t1
/* 0D7428 8031C428 1000FF68 */  b     .L8031C1CC
/* 0D742C 8031C42C AE4B0030 */   sw    $t3, 0x30($s2)
glabel L8031C430
/* 0D7430 8031C430 0C0C6C07 */  jal   func_8031B01C
/* 0D7434 8031C434 02002025 */   move  $a0, $s0
/* 0D7438 8031C438 02402025 */  move  $a0, $s2
/* 0D743C 8031C43C 0C0C700C */  jal   SetInstrument
/* 0D7440 8031C440 304500FF */   andi  $a1, $v0, 0xff
/* 0D7444 8031C444 1000FF61 */  b     .L8031C1CC
/* 0D7448 8031C448 00000000 */   nop   
glabel L8031C44C
/* 0D744C 8031C44C 92580000 */  lbu   $t8, ($s2)
/* 0D7450 8031C450 330CFFFD */  andi  $t4, $t8, 0xfffd
/* 0D7454 8031C454 1000FF5D */  b     .L8031C1CC
/* 0D7458 8031C458 A24C0000 */   sb    $t4, ($s2)
glabel L8031C45C
/* 0D745C 8031C45C 924F0000 */  lbu   $t7, ($s2)
/* 0D7460 8031C460 35EE0002 */  ori   $t6, $t7, 2
/* 0D7464 8031C464 1000FF59 */  b     .L8031C1CC
/* 0D7468 8031C468 A24E0000 */   sb    $t6, ($s2)
glabel L8031C46C
/* 0D746C 8031C46C 0C0C6C07 */  jal   func_8031B01C
/* 0D7470 8031C470 02002025 */   move  $a0, $s0
/* 0D7474 8031C474 02402025 */  move  $a0, $s2
/* 0D7478 8031C478 0C0C7031 */  jal   func_8031C0C4
/* 0D747C 8031C47C 304500FF */   andi  $a1, $v0, 0xff
/* 0D7480 8031C480 1000FF52 */  b     .L8031C1CC
/* 0D7484 8031C484 00000000 */   nop   
glabel L8031C488
/* 0D7488 8031C488 0C0C6C07 */  jal   func_8031B01C
/* 0D748C 8031C48C 02002025 */   move  $a0, $s0
/* 0D7490 8031C490 44822000 */  mtc1  $v0, $f4
/* 0D7494 8031C494 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D7498 8031C498 04410004 */  bgez  $v0, .L8031C4AC
/* 0D749C 8031C49C 468021A0 */   cvt.s.w $f6, $f4
/* 0D74A0 8031C4A0 44814000 */  mtc1  $at, $f8
/* 0D74A4 8031C4A4 00000000 */  nop   
/* 0D74A8 8031C4A8 46083180 */  add.s $f6, $f6, $f8
.L8031C4AC:
/* 0D74AC 8031C4AC 460032A1 */  cvt.d.s $f10, $f6
/* 0D74B0 8031C4B0 46345402 */  mul.d $f16, $f10, $f20
/* 0D74B4 8031C4B4 462084A0 */  cvt.s.d $f18, $f16
/* 0D74B8 8031C4B8 1000FF44 */  b     .L8031C1CC
/* 0D74BC 8031C4BC E652001C */   swc1  $f18, 0x1c($s2)
glabel L8031C4C0
/* 0D74C0 8031C4C0 0C0C6C0C */  jal   func_8031B030
/* 0D74C4 8031C4C4 02002025 */   move  $a0, $s0
/* 0D74C8 8031C4C8 3059FFFF */  andi  $t9, $v0, 0xffff
/* 0D74CC 8031C4CC 44992000 */  mtc1  $t9, $f4
/* 0D74D0 8031C4D0 44808000 */  mtc1  $zero, $f16
/* 0D74D4 8031C4D4 07210005 */  bgez  $t9, .L8031C4EC
/* 0D74D8 8031C4D8 46802220 */   cvt.s.w $f8, $f4
/* 0D74DC 8031C4DC 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D74E0 8031C4E0 44813000 */  mtc1  $at, $f6
/* 0D74E4 8031C4E4 00000000 */  nop   
/* 0D74E8 8031C4E8 46064200 */  add.s $f8, $f8, $f6
.L8031C4EC:
/* 0D74EC 8031C4EC 3C0140E0 */  li    $at, 0x40E00000 # 7.000000
/* 0D74F0 8031C4F0 44818800 */  mtc1  $at, $f17
/* 0D74F4 8031C4F4 460042A1 */  cvt.d.s $f10, $f8
/* 0D74F8 8031C4F8 46305483 */  div.d $f18, $f10, $f16
/* 0D74FC 8031C4FC 46209120 */  cvt.s.d $f4, $f18
/* 0D7500 8031C500 1000FF32 */  b     .L8031C1CC
/* 0D7504 8031C504 E644002C */   swc1  $f4, 0x2c($s2)
glabel L8031C508
/* 0D7508 8031C508 0C0C6C07 */  jal   func_8031B01C
/* 0D750C 8031C50C 02002025 */   move  $a0, $s0
/* 0D7510 8031C510 2449007F */  addiu $t1, $v0, 0x7f
/* 0D7514 8031C514 312A00FF */  andi  $t2, $t1, 0xff
/* 0D7518 8031C518 000A5880 */  sll   $t3, $t2, 2
/* 0D751C 8031C51C 3C018033 */  lui   $at, %hi(D_80332488)
/* 0D7520 8031C520 002B0821 */  addu  $at, $at, $t3
/* 0D7524 8031C524 C4262488 */  lwc1  $f6, %lo(D_80332488)($at)
/* 0D7528 8031C528 1000FF28 */  b     .L8031C1CC
/* 0D752C 8031C52C E646002C */   swc1  $f6, 0x2c($s2)
glabel L8031C530
/* 0D7530 8031C530 0C0C6C07 */  jal   func_8031B01C
/* 0D7534 8031C534 02002025 */   move  $a0, $s0
/* 0D7538 8031C538 44824000 */  mtc1  $v0, $f8
/* 0D753C 8031C53C 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D7540 8031C540 04410004 */  bgez  $v0, .L8031C554
/* 0D7544 8031C544 468042A0 */   cvt.s.w $f10, $f8
/* 0D7548 8031C548 44818000 */  mtc1  $at, $f16
/* 0D754C 8031C54C 00000000 */  nop   
/* 0D7550 8031C550 46105280 */  add.s $f10, $f10, $f16
.L8031C554:
/* 0D7554 8031C554 460054A1 */  cvt.d.s $f18, $f10
/* 0D7558 8031C558 46349102 */  mul.d $f4, $f18, $f20
/* 0D755C 8031C55C 462021A0 */  cvt.s.d $f6, $f4
/* 0D7560 8031C560 1000FF1A */  b     .L8031C1CC
/* 0D7564 8031C564 E6460024 */   swc1  $f6, 0x24($s2)
glabel L8031C568
/* 0D7568 8031C568 0C0C6C07 */  jal   func_8031B01C
/* 0D756C 8031C56C 02002025 */   move  $a0, $s0
/* 0D7570 8031C570 44824000 */  mtc1  $v0, $f8
/* 0D7574 8031C574 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D7578 8031C578 04410004 */  bgez  $v0, .L8031C58C
/* 0D757C 8031C57C 46804420 */   cvt.s.w $f16, $f8
/* 0D7580 8031C580 44815000 */  mtc1  $at, $f10
/* 0D7584 8031C584 00000000 */  nop   
/* 0D7588 8031C588 460A8400 */  add.s $f16, $f16, $f10
.L8031C58C:
/* 0D758C 8031C58C 460084A1 */  cvt.d.s $f18, $f16
/* 0D7590 8031C590 46349102 */  mul.d $f4, $f18, $f20
/* 0D7594 8031C594 462021A0 */  cvt.s.d $f6, $f4
/* 0D7598 8031C598 1000FF0C */  b     .L8031C1CC
/* 0D759C 8031C59C E6460028 */   swc1  $f6, 0x28($s2)
glabel L8031C5A0
/* 0D75A0 8031C5A0 8E020000 */  lw    $v0, ($s0)
/* 0D75A4 8031C5A4 80430000 */  lb    $v1, ($v0)
/* 0D75A8 8031C5A8 24580001 */  addiu $t8, $v0, 1
/* 0D75AC 8031C5AC AE180000 */  sw    $t8, ($s0)
/* 0D75B0 8031C5B0 1000FF06 */  b     .L8031C1CC
/* 0D75B4 8031C5B4 A643001A */   sh    $v1, 0x1a($s2)
glabel L8031C5B8
/* 0D75B8 8031C5B8 0C0C6C0C */  jal   func_8031B030
/* 0D75BC 8031C5BC 02002025 */   move  $a0, $s0
/* 0D75C0 8031C5C0 8E8C0014 */  lw    $t4, 0x14($s4)
/* 0D75C4 8031C5C4 304DFFFF */  andi  $t5, $v0, 0xffff
/* 0D75C8 8031C5C8 018D7821 */  addu  $t7, $t4, $t5
/* 0D75CC 8031C5CC 1000FEFF */  b     .L8031C1CC
/* 0D75D0 8031C5D0 AE4F007C */   sw    $t7, 0x7c($s2)
glabel L8031C5D4
/* 0D75D4 8031C5D4 0C0C6C07 */  jal   func_8031B01C
/* 0D75D8 8031C5D8 02002025 */   move  $a0, $s0
/* 0D75DC 8031C5DC 1000FEFB */  b     .L8031C1CC
/* 0D75E0 8031C5E0 A2420078 */   sb    $v0, 0x78($s2)
glabel L8031C5E4
/* 0D75E4 8031C5E4 0C0C6C07 */  jal   func_8031B01C
/* 0D75E8 8031C5E8 02002025 */   move  $a0, $s0
/* 0D75EC 8031C5EC 000270C0 */  sll   $t6, $v0, 3
/* 0D75F0 8031C5F0 A64E000E */  sh    $t6, 0xe($s2)
/* 0D75F4 8031C5F4 A640000A */  sh    $zero, 0xa($s2)
/* 0D75F8 8031C5F8 1000FEF4 */  b     .L8031C1CC
/* 0D75FC 8031C5FC A6400012 */   sh    $zero, 0x12($s2)
glabel L8031C600
/* 0D7600 8031C600 0C0C6C07 */  jal   func_8031B01C
/* 0D7604 8031C604 02002025 */   move  $a0, $s0
/* 0D7608 8031C608 00021940 */  sll   $v1, $v0, 5
/* 0D760C 8031C60C A643000C */  sh    $v1, 0xc($s2)
/* 0D7610 8031C610 A6430008 */  sh    $v1, 8($s2)
/* 0D7614 8031C614 1000FEED */  b     .L8031C1CC
/* 0D7618 8031C618 A6400010 */   sh    $zero, 0x10($s2)
glabel L8031C61C
/* 0D761C 8031C61C 0C0C6C07 */  jal   func_8031B01C
/* 0D7620 8031C620 02002025 */   move  $a0, $s0
/* 0D7624 8031C624 0002C8C0 */  sll   $t9, $v0, 3
/* 0D7628 8031C628 A659000A */  sh    $t9, 0xa($s2)
/* 0D762C 8031C62C 0C0C6C07 */  jal   func_8031B01C
/* 0D7630 8031C630 02002025 */   move  $a0, $s0
/* 0D7634 8031C634 000248C0 */  sll   $t1, $v0, 3
/* 0D7638 8031C638 A649000E */  sh    $t1, 0xe($s2)
/* 0D763C 8031C63C 0C0C6C07 */  jal   func_8031B01C
/* 0D7640 8031C640 02002025 */   move  $a0, $s0
/* 0D7644 8031C644 00025100 */  sll   $t2, $v0, 4
/* 0D7648 8031C648 1000FEE0 */  b     .L8031C1CC
/* 0D764C 8031C64C A64A0012 */   sh    $t2, 0x12($s2)
glabel L8031C650
/* 0D7650 8031C650 0C0C6C07 */  jal   func_8031B01C
/* 0D7654 8031C654 02002025 */   move  $a0, $s0
/* 0D7658 8031C658 00025940 */  sll   $t3, $v0, 5
/* 0D765C 8031C65C A64B0008 */  sh    $t3, 8($s2)
/* 0D7660 8031C660 0C0C6C07 */  jal   func_8031B01C
/* 0D7664 8031C664 02002025 */   move  $a0, $s0
/* 0D7668 8031C668 0002C140 */  sll   $t8, $v0, 5
/* 0D766C 8031C66C A658000C */  sh    $t8, 0xc($s2)
/* 0D7670 8031C670 0C0C6C07 */  jal   func_8031B01C
/* 0D7674 8031C674 02002025 */   move  $a0, $s0
/* 0D7678 8031C678 00026100 */  sll   $t4, $v0, 4
/* 0D767C 8031C67C 1000FED3 */  b     .L8031C1CC
/* 0D7680 8031C680 A64C0010 */   sh    $t4, 0x10($s2)
glabel L8031C684
/* 0D7684 8031C684 0C0C6C07 */  jal   func_8031B01C
/* 0D7688 8031C688 02002025 */   move  $a0, $s0
/* 0D768C 8031C68C 00026900 */  sll   $t5, $v0, 4
/* 0D7690 8031C690 1000FECE */  b     .L8031C1CC
/* 0D7694 8031C694 A64D0014 */   sh    $t5, 0x14($s2)
glabel L8031C698
/* 0D7698 8031C698 0C0C6C07 */  jal   func_8031B01C
/* 0D769C 8031C69C 02002025 */   move  $a0, $s0
/* 0D76A0 8031C6A0 14400003 */  bnez  $v0, .L8031C6B0
/* 0D76A4 8031C6A4 305100FF */   andi  $s1, $v0, 0xff
/* 0D76A8 8031C6A8 3C118022 */  lui   $s1, %hi(D_80226D7E) # $s1, 0x8022
/* 0D76AC 8031C6AC 92316D7E */  lbu   $s1, %lo(D_80226D7E)($s1)
.L8031C6B0:
/* 0D76B0 8031C6B0 1000FEC6 */  b     .L8031C1CC
/* 0D76B4 8031C6B4 A2510006 */   sb    $s1, 6($s2)
glabel L8031C6B8
/* 0D76B8 8031C6B8 0C0C6C07 */  jal   func_8031B01C
/* 0D76BC 8031C6BC 02002025 */   move  $a0, $s0
/* 0D76C0 8031C6C0 1000FEC2 */  b     .L8031C1CC
/* 0D76C4 8031C6C4 A2420003 */   sb    $v0, 3($s2)
glabel L8031C6C8
/* 0D76C8 8031C6C8 0C0C6C07 */  jal   func_8031B01C
/* 0D76CC 8031C6CC 02002025 */   move  $a0, $s0
/* 0D76D0 8031C6D0 928F0005 */  lbu   $t7, 5($s4)
/* 0D76D4 8031C6D4 3C038022 */  lui   $v1, %hi(D_80226D58) # $v1, 0x8022
/* 0D76D8 8031C6D8 8C636D58 */  lw    $v1, %lo(D_80226D58)($v1)
/* 0D76DC 8031C6DC 000F7040 */  sll   $t6, $t7, 1
/* 0D76E0 8031C6E0 3C048022 */  lui   $a0, %hi(D_802214F8) # $a0, 0x8022
/* 0D76E4 8031C6E4 006EC821 */  addu  $t9, $v1, $t6
/* 0D76E8 8031C6E8 97270000 */  lhu   $a3, ($t9)
/* 0D76EC 8031C6EC 248414F8 */  addiu $a0, %lo(D_802214F8) # addiu $a0, $a0, 0x14f8
/* 0D76F0 8031C6F0 24050002 */  li    $a1, 2
/* 0D76F4 8031C6F4 00E34821 */  addu  $t1, $a3, $v1
/* 0D76F8 8031C6F8 91280000 */  lbu   $t0, ($t1)
/* 0D76FC 8031C6FC 00E85021 */  addu  $t2, $a3, $t0
/* 0D7700 8031C700 01425823 */  subu  $t3, $t2, $v0
/* 0D7704 8031C704 0163C021 */  addu  $t8, $t3, $v1
/* 0D7708 8031C708 93110000 */  lbu   $s1, ($t8)
/* 0D770C 8031C70C 0C0C5A03 */  jal   func_8031680C
/* 0D7710 8031C710 02203025 */   move  $a2, $s1
/* 0D7714 8031C714 1040FEAD */  beqz  $v0, .L8031C1CC
/* 0D7718 8031C718 00000000 */   nop   
/* 0D771C 8031C71C 1000FEAB */  b     .L8031C1CC
/* 0D7720 8031C720 A2510005 */   sb    $s1, 5($s2)
glabel L8031C724
/* 0D7724 8031C724 326C00FF */  andi  $t4, $s3, 0xff
/* 0D7728 8031C728 AFAC0038 */  sw    $t4, 0x38($sp)
/* 0D772C 8031C72C 0C0C6C07 */  jal   func_8031B01C
/* 0D7730 8031C730 02002025 */   move  $a0, $s0
/* 0D7734 8031C734 305100FF */  andi  $s1, $v0, 0xff
/* 0D7738 8031C738 0C0C6C0C */  jal   func_8031B030
/* 0D773C 8031C73C 02002025 */   move  $a0, $s0
/* 0D7740 8031C740 8E8D0014 */  lw    $t5, 0x14($s4)
/* 0D7744 8031C744 8FAE0038 */  lw    $t6, 0x38($sp)
/* 0D7748 8031C748 304FFFFF */  andi  $t7, $v0, 0xffff
/* 0D774C 8031C74C 01AF1821 */  addu  $v1, $t5, $t7
/* 0D7750 8031C750 01D1C821 */  addu  $t9, $t6, $s1
/* 0D7754 8031C754 1000FE9D */  b     .L8031C1CC
/* 0D7758 8031C758 A0790000 */   sb    $t9, ($v1)
glabel L8031C75C
/* 0D775C 8031C75C 0C0C6C07 */  jal   func_8031B01C
/* 0D7760 8031C760 02002025 */   move  $a0, $s0
/* 0D7764 8031C764 240100C8 */  li    $at, 200
/* 0D7768 8031C768 16210005 */  bne   $s1, $at, .L8031C780
/* 0D776C 8031C76C 02201825 */   move  $v1, $s1
/* 0D7770 8031C770 02629823 */  subu  $s3, $s3, $v0
/* 0D7774 8031C774 00135E00 */  sll   $t3, $s3, 0x18
/* 0D7778 8031C778 1000FE94 */  b     .L8031C1CC
/* 0D777C 8031C77C 000B9E03 */   sra   $s3, $t3, 0x18
.L8031C780:
/* 0D7780 8031C780 240100CC */  li    $at, 204
/* 0D7784 8031C784 14610005 */  bne   $v1, $at, .L8031C79C
/* 0D7788 8031C788 02629824 */   and   $s3, $s3, $v0
/* 0D778C 8031C78C 00029E00 */  sll   $s3, $v0, 0x18
/* 0D7790 8031C790 00136603 */  sra   $t4, $s3, 0x18
/* 0D7794 8031C794 1000FE8D */  b     .L8031C1CC
/* 0D7798 8031C798 01809825 */   move  $s3, $t4
.L8031C79C:
/* 0D779C 8031C79C 00137600 */  sll   $t6, $s3, 0x18
/* 0D77A0 8031C7A0 1000FE8A */  b     .L8031C1CC
/* 0D77A4 8031C7A4 000E9E03 */   sra   $s3, $t6, 0x18
glabel L8031C7A8
/* 0D77A8 8031C7A8 0C0C6C07 */  jal   func_8031B01C
/* 0D77AC 8031C7AC 02002025 */   move  $a0, $s0
/* 0D77B0 8031C7B0 1000FE86 */  b     .L8031C1CC
/* 0D77B4 8031C7B4 A2420002 */   sb    $v0, 2($s2)
glabel L8031C7B8
/* 0D77B8 8031C7B8 0C0C6C0C */  jal   func_8031B030
/* 0D77BC 8031C7BC 02002025 */   move  $a0, $s0
/* 0D77C0 8031C7C0 8E890014 */  lw    $t1, 0x14($s4)
/* 0D77C4 8031C7C4 304AFFFF */  andi  $t2, $v0, 0xffff
/* 0D77C8 8031C7C8 01535821 */  addu  $t3, $t2, $s3
/* 0D77CC 8031C7CC 012BC021 */  addu  $t8, $t1, $t3
/* 0D77D0 8031C7D0 1000FE7E */  b     .L8031C1CC
/* 0D77D4 8031C7D4 83130000 */   lb    $s3, ($t8)
glabel L8031C7D8
/* 0D77D8 8031C7D8 0C0C6C07 */  jal   func_8031B01C
/* 0D77DC 8031C7DC 02002025 */   move  $a0, $s0
/* 0D77E0 8031C7E0 924E0000 */  lbu   $t6, ($s2)
/* 0D77E4 8031C7E4 00026880 */  sll   $t5, $v0, 2
/* 0D77E8 8031C7E8 31AF0004 */  andi  $t7, $t5, 4
/* 0D77EC 8031C7EC 31D9FFFB */  andi  $t9, $t6, 0xfffb
/* 0D77F0 8031C7F0 01F95025 */  or    $t2, $t7, $t9
/* 0D77F4 8031C7F4 1000FE75 */  b     .L8031C1CC
/* 0D77F8 8031C7F8 A24A0000 */   sb    $t2, ($s2)
glabel L8031C7FC
/* 0D77FC 8031C7FC 0C0C6C07 */  jal   func_8031B01C
/* 0D7800 8031C800 02002025 */   move  $a0, $s0
/* 0D7804 8031C804 1000FE71 */  b     .L8031C1CC
/* 0D7808 8031C808 A2420001 */   sb    $v0, 1($s2)
glabel L8031C80C
/* 0D780C 8031C80C 0C0C6C07 */  jal   func_8031B01C
/* 0D7810 8031C810 02002025 */   move  $a0, $s0
/* 0D7814 8031C814 00024A00 */  sll   $t1, $v0, 8
/* 0D7818 8031C818 1000FE6C */  b     .L8031C1CC
/* 0D781C 8031C81C A649007A */   sh    $t1, 0x7a($s2)
glabel L8031C820
/* 0D7820 8031C820 1275FE6A */  beq   $s3, $s5, .L8031C1CC
/* 0D7824 8031C824 0013C040 */   sll   $t8, $s3, 1
/* 0D7828 8031C828 920C0018 */  lbu   $t4, 0x18($s0)
/* 0D782C 8031C82C 8E4B0030 */  lw    $t3, 0x30($s2)
/* 0D7830 8031C830 8E0E0000 */  lw    $t6, ($s0)
/* 0D7834 8031C834 258D0001 */  addiu $t5, $t4, 1
/* 0D7838 8031C838 31AF00FF */  andi  $t7, $t5, 0xff
/* 0D783C 8031C83C 000FC880 */  sll   $t9, $t7, 2
/* 0D7840 8031C840 02195021 */  addu  $t2, $s0, $t9
/* 0D7844 8031C844 A20D0018 */  sb    $t5, 0x18($s0)
/* 0D7848 8031C848 01781021 */  addu  $v0, $t3, $t8
/* 0D784C 8031C84C AD4E0000 */  sw    $t6, ($t2)
/* 0D7850 8031C850 904B0000 */  lbu   $t3, ($v0)
/* 0D7854 8031C854 90490001 */  lbu   $t1, 1($v0)
/* 0D7858 8031C858 8E8D0014 */  lw    $t5, 0x14($s4)
/* 0D785C 8031C85C 000BC200 */  sll   $t8, $t3, 8
/* 0D7860 8031C860 01383821 */  addu  $a3, $t1, $t8
/* 0D7864 8031C864 30ECFFFF */  andi  $t4, $a3, 0xffff
/* 0D7868 8031C868 01AC7821 */  addu  $t7, $t5, $t4
/* 0D786C 8031C86C 1000FE57 */  b     .L8031C1CC
/* 0D7870 8031C870 AE0F0000 */   sw    $t7, ($s0)
.L8031C874:
/* 0D7874 8031C874 3064000F */  andi  $a0, $v1, 0xf
/* 0D7878 8031C878 2F2100B1 */  sltiu $at, $t9, 0xb1
/* 0D787C 8031C87C 1020FE53 */  beqz  $at, .L8031C1CC
/* 0D7880 8031C880 308800FF */   andi  $t0, $a0, 0xff
/* 0D7884 8031C884 0019C880 */  sll   $t9, $t9, 2
/* 0D7888 8031C888 3C018033 */  lui   $at, %hi(jtbl_80337E04)
/* 0D788C 8031C88C 00390821 */  addu  $at, $at, $t9
/* 0D7890 8031C890 8C397E04 */  lw    $t9, %lo(jtbl_80337E04)($at)
/* 0D7894 8031C894 03200008 */  jr    $t9
/* 0D7898 8031C898 00000000 */   nop   
glabel L8031C89C
/* 0D789C 8031C89C 308E00FF */  andi  $t6, $a0, 0xff
/* 0D78A0 8031C8A0 000E5080 */  sll   $t2, $t6, 2
/* 0D78A4 8031C8A4 024A5821 */  addu  $t3, $s2, $t2
/* 0D78A8 8031C8A8 8D630044 */  lw    $v1, 0x44($t3)
/* 0D78AC 8031C8AC 1060FE47 */  beqz  $v1, .L8031C1CC
/* 0D78B0 8031C8B0 00000000 */   nop   
/* 0D78B4 8031C8B4 8C730000 */  lw    $s3, ($v1)
/* 0D78B8 8031C8B8 00134840 */  sll   $t1, $s3, 1
/* 0D78BC 8031C8BC 0009C7C2 */  srl   $t8, $t1, 0x1f
/* 0D78C0 8031C8C0 00186600 */  sll   $t4, $t8, 0x18
/* 0D78C4 8031C8C4 1000FE41 */  b     .L8031C1CC
/* 0D78C8 8031C8C8 000C9E03 */   sra   $s3, $t4, 0x18
glabel L8031C8CC
/* 0D78CC 8031C8CC 308F00FF */  andi  $t7, $a0, 0xff
/* 0D78D0 8031C8D0 024FC821 */  addu  $t9, $s2, $t7
/* 0D78D4 8031C8D4 1000FE3D */  b     .L8031C1CC
/* 0D78D8 8031C8D8 A3330054 */   sb    $s3, 0x54($t9)
glabel L8031C8DC
/* 0D78DC 8031C8DC 308300FF */  andi  $v1, $a0, 0xff
/* 0D78E0 8031C8E0 02432821 */  addu  $a1, $s2, $v1
/* 0D78E4 8031C8E4 28610004 */  slti  $at, $v1, 4
/* 0D78E8 8031C8E8 1020FE38 */  beqz  $at, .L8031C1CC
/* 0D78EC 8031C8EC 80B30054 */   lb    $s3, 0x54($a1)
/* 0D78F0 8031C8F0 1000FE36 */  b     .L8031C1CC
/* 0D78F4 8031C8F4 A0B50054 */   sb    $s5, 0x54($a1)
glabel L8031C8F8
/* 0D78F8 8031C8F8 308E00FF */  andi  $t6, $a0, 0xff
/* 0D78FC 8031C8FC 024E5021 */  addu  $t2, $s2, $t6
/* 0D7900 8031C900 814B0054 */  lb    $t3, 0x54($t2)
/* 0D7904 8031C904 026B9823 */  subu  $s3, $s3, $t3
/* 0D7908 8031C908 00134E00 */  sll   $t1, $s3, 0x18
/* 0D790C 8031C90C 1000FE2F */  b     .L8031C1CC
/* 0D7910 8031C910 00099E03 */   sra   $s3, $t1, 0x18
glabel L8031C914
/* 0D7914 8031C914 0C0C6C0C */  jal   func_8031B030
/* 0D7918 8031C918 02002025 */   move  $a0, $s0
/* 0D791C 8031C91C 02201825 */  move  $v1, $s1
/* 0D7920 8031C920 3065000F */  andi  $a1, $v1, 0xf
/* 0D7924 8031C924 00A01825 */  move  $v1, $a1
/* 0D7928 8031C928 AFA50038 */  sw    $a1, 0x38($sp)
/* 0D792C 8031C92C 02402025 */  move  $a0, $s2
/* 0D7930 8031C930 0C0C6A48 */  jal   func_8031A920
/* 0D7934 8031C934 A7A2005A */   sh    $v0, 0x5a($sp)
/* 0D7938 8031C938 8FA30038 */  lw    $v1, 0x38($sp)
/* 0D793C 8031C93C 1440FE23 */  bnez  $v0, .L8031C1CC
/* 0D7940 8031C940 97A7005A */   lhu   $a3, 0x5a($sp)
/* 0D7944 8031C944 8E8D0014 */  lw    $t5, 0x14($s4)
/* 0D7948 8031C948 0003C880 */  sll   $t9, $v1, 2
/* 0D794C 8031C94C 02597021 */  addu  $t6, $s2, $t9
/* 0D7950 8031C950 8DCA0044 */  lw    $t2, 0x44($t6)
/* 0D7954 8031C954 01A77821 */  addu  $t7, $t5, $a3
/* 0D7958 8031C958 1000FE1C */  b     .L8031C1CC
/* 0D795C 8031C95C AD4F0054 */   sw    $t7, 0x54($t2)
glabel L8031C960
/* 0D7960 8031C960 02202825 */  move  $a1, $s1
/* 0D7964 8031C964 30AB000F */  andi  $t3, $a1, 0xf
/* 0D7968 8031C968 01602825 */  move  $a1, $t3
/* 0D796C 8031C96C 0C0C6A93 */  jal   func_8031AA4C
/* 0D7970 8031C970 02402025 */   move  $a0, $s2
/* 0D7974 8031C974 1000FE15 */  b     .L8031C1CC
/* 0D7978 8031C978 00000000 */   nop   
glabel L8031C97C
/* 0D797C 8031C97C 1275FE13 */  beq   $s3, $s5, .L8031C1CC
/* 0D7980 8031C980 02402025 */   move  $a0, $s2
/* 0D7984 8031C984 02201825 */  move  $v1, $s1
/* 0D7988 8031C988 3065000F */  andi  $a1, $v1, 0xf
/* 0D798C 8031C98C 00A01825 */  move  $v1, $a1
/* 0D7990 8031C990 0C0C6A48 */  jal   func_8031A920
/* 0D7994 8031C994 AFA50038 */   sw    $a1, 0x38($sp)
/* 0D7998 8031C998 1055FE0C */  beq   $v0, $s5, .L8031C1CC
/* 0D799C 8031C99C 8FA30038 */   lw    $v1, 0x38($sp)
/* 0D79A0 8031C9A0 8E580030 */  lw    $t8, 0x30($s2)
/* 0D79A4 8031C9A4 00136040 */  sll   $t4, $s3, 1
/* 0D79A8 8031C9A8 8E8A0014 */  lw    $t2, 0x14($s4)
/* 0D79AC 8031C9AC 030C1021 */  addu  $v0, $t8, $t4
/* 0D79B0 8031C9B0 90590000 */  lbu   $t9, ($v0)
/* 0D79B4 8031C9B4 904D0001 */  lbu   $t5, 1($v0)
/* 0D79B8 8031C9B8 00034880 */  sll   $t1, $v1, 2
/* 0D79BC 8031C9BC 00197200 */  sll   $t6, $t9, 8
/* 0D79C0 8031C9C0 0249C021 */  addu  $t8, $s2, $t1
/* 0D79C4 8031C9C4 01AE3821 */  addu  $a3, $t5, $t6
/* 0D79C8 8031C9C8 8F0C0044 */  lw    $t4, 0x44($t8)
/* 0D79CC 8031C9CC 30EFFFFF */  andi  $t7, $a3, 0xffff
/* 0D79D0 8031C9D0 014F5821 */  addu  $t3, $t2, $t7
/* 0D79D4 8031C9D4 1000FDFD */  b     .L8031C1CC
/* 0D79D8 8031C9D8 AD8B0054 */   sw    $t3, 0x54($t4)
glabel L8031C9DC
/* 0D79DC 8031C9DC 1000FDFB */  b     .L8031C1CC
/* 0D79E0 8031C9E0 A2440004 */   sb    $a0, 4($s2)
glabel L8031C9E4
/* 0D79E4 8031C9E4 0C0C6C0C */  jal   func_8031B030
/* 0D79E8 8031C9E8 02002025 */   move  $a0, $s0
/* 0D79EC 8031C9EC 8E8D0014 */  lw    $t5, 0x14($s4)
/* 0D79F0 8031C9F0 02202825 */  move  $a1, $s1
/* 0D79F4 8031C9F4 30B9000F */  andi  $t9, $a1, 0xf
/* 0D79F8 8031C9F8 304EFFFF */  andi  $t6, $v0, 0xffff
/* 0D79FC 8031C9FC 03202825 */  move  $a1, $t9
/* 0D7A00 8031CA00 02802025 */  move  $a0, $s4
/* 0D7A04 8031CA04 0C0C6B60 */  jal   func_8031AD80
/* 0D7A08 8031CA08 01AE3021 */   addu  $a2, $t5, $t6
/* 0D7A0C 8031CA0C 1000FDEF */  b     .L8031C1CC
/* 0D7A10 8031CA10 00000000 */   nop   
glabel L8031CA14
/* 0D7A14 8031CA14 322A000F */  andi  $t2, $s1, 0xf
/* 0D7A18 8031CA18 000A4880 */  sll   $t1, $t2, 2
/* 0D7A1C 8031CA1C 0289C021 */  addu  $t8, $s4, $t1
/* 0D7A20 8031CA20 0C0C6AB4 */  jal   func_8031AAD0
/* 0D7A24 8031CA24 8F04002C */   lw    $a0, 0x2c($t8)
/* 0D7A28 8031CA28 1000FDE8 */  b     .L8031C1CC
/* 0D7A2C 8031CA2C 00000000 */   nop   
glabel L8031CA30
/* 0D7A30 8031CA30 02002025 */  move  $a0, $s0
/* 0D7A34 8031CA34 0C0C6C07 */  jal   func_8031B01C
/* 0D7A38 8031CA38 A3A8005D */   sb    $t0, 0x5d($sp)
/* 0D7A3C 8031CA3C 93A8005D */  lbu   $t0, 0x5d($sp)
/* 0D7A40 8031CA40 00085880 */  sll   $t3, $t0, 2
/* 0D7A44 8031CA44 028B6021 */  addu  $t4, $s4, $t3
/* 0D7A48 8031CA48 8D99002C */  lw    $t9, 0x2c($t4)
/* 0D7A4C 8031CA4C 03226821 */  addu  $t5, $t9, $v0
/* 0D7A50 8031CA50 1000FDDE */  b     .L8031C1CC
/* 0D7A54 8031CA54 A1B30054 */   sb    $s3, 0x54($t5)
glabel L8031CA58
/* 0D7A58 8031CA58 02002025 */  move  $a0, $s0
/* 0D7A5C 8031CA5C 0C0C6C07 */  jal   func_8031B01C
/* 0D7A60 8031CA60 A3A8005D */   sb    $t0, 0x5d($sp)
/* 0D7A64 8031CA64 93A8005D */  lbu   $t0, 0x5d($sp)
/* 0D7A68 8031CA68 00087080 */  sll   $t6, $t0, 2
/* 0D7A6C 8031CA6C 028E7821 */  addu  $t7, $s4, $t6
/* 0D7A70 8031CA70 8DEA002C */  lw    $t2, 0x2c($t7)
/* 0D7A74 8031CA74 01424821 */  addu  $t1, $t2, $v0
/* 0D7A78 8031CA78 1000FDD4 */  b     .L8031C1CC
/* 0D7A7C 8031CA7C 81330054 */   lb    $s3, 0x54($t1)
.L8031CA80:
/* 0D7A80 8031CA80 02408825 */  move  $s1, $s2
.L8031CA84:
/* 0D7A84 8031CA84 24120010 */  li    $s2, 16
/* 0D7A88 8031CA88 00008025 */  move  $s0, $zero
.L8031CA8C:
/* 0D7A8C 8031CA8C 8E240044 */  lw    $a0, 0x44($s1)
/* 0D7A90 8031CA90 50800004 */  beql  $a0, $zero, .L8031CAA4
/* 0D7A94 8031CA94 26100004 */   addiu $s0, $s0, 4
/* 0D7A98 8031CA98 0C0C6C29 */  jal   func_8031B0A4
/* 0D7A9C 8031CA9C 00000000 */   nop   
/* 0D7AA0 8031CAA0 26100004 */  addiu $s0, $s0, 4
.L8031CAA4:
/* 0D7AA4 8031CAA4 1612FFF9 */  bne   $s0, $s2, .L8031CA8C
/* 0D7AA8 8031CAA8 26310004 */   addiu $s1, $s1, 4
.L8031CAAC:
/* 0D7AAC 8031CAAC 8FBF0034 */  lw    $ra, 0x34($sp)
.L8031CAB0:
/* 0D7AB0 8031CAB0 D7B40010 */  ldc1  $f20, 0x10($sp)
/* 0D7AB4 8031CAB4 8FB0001C */  lw    $s0, 0x1c($sp)
/* 0D7AB8 8031CAB8 8FB10020 */  lw    $s1, 0x20($sp)
/* 0D7ABC 8031CABC 8FB20024 */  lw    $s2, 0x24($sp)
/* 0D7AC0 8031CAC0 8FB30028 */  lw    $s3, 0x28($sp)
/* 0D7AC4 8031CAC4 8FB4002C */  lw    $s4, 0x2c($sp)
/* 0D7AC8 8031CAC8 8FB50030 */  lw    $s5, 0x30($sp)
/* 0D7ACC 8031CACC 03E00008 */  jr    $ra
/* 0D7AD0 8031CAD0 27BD0068 */   addiu $sp, $sp, 0x68
)
#else
GLOBAL_ASM(
.late_rodata
.late_rodata_alignment 8
glabel jtbl_80337D08 # US: 80338EC0
	.word L_U_8031D3A8
	.word L_U_8031D354
	.word L_U_8031D3C4
	.word L_U_8031D3D4
	.word L_U_8031D370
	.word L_U_8031D5E4
	.word L_U_8031D640
	.word L_U_8031D678
	.word L_U_8031D678
	.word L_U_8031D6C4
	.word L_U_8031D6D4
	.word L_U_8031D678
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D6F4
	.word L_U_8031D718
	.word L_U_8031D728
	.word L_U_8031D44C
	.word L_U_8031D5D4
	.word L_U_8031D144
	.word L_U_8031D5B4
	.word L_U_8031D51C
	.word L_U_8031D500
	.word L_U_8031D4F0
	.word L_U_8031D4D4
	.word L_U_8031D4BC
	.word L_U_8031D498
	.word L_U_8031D474
	.word L_U_8031D424
	.word L_U_8031D3E4
	.word L_U_8031D400
	.word L_U_8031D56C
	.word L_U_8031D538
	.word L_U_8031D5A0
	.word L_U_8031D73C
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D344
	.word L_U_8031D31C
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D2C4
	.word L_U_8031D2B4
	.word L_U_8031D26C
	.word L_U_8031D234
	.word L_U_8031D2C4
	.word L_U_8031D2C4
	.word L_U_8031D2C4
	.word L_U_8031D1F8
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144

glabel jtbl_80337E04 # US: 80338FBC
	.word L_U_8031D7B8
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D900
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D930
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D94C
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D974
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D814
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D8F8
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D7E8
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D7F8
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D830
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D87C
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D144
	.word L_U_8031D898

.text
glabel func_8031C104
/* 0D808C 8031D08C 27BDFFA0 */  addiu $sp, $sp, -0x60
/* 0D8090 8031D090 AFBF002C */  sw    $ra, 0x2c($sp)
/* 0D8094 8031D094 AFB50028 */  sw    $s5, 0x28($sp)
/* 0D8098 8031D098 AFB40024 */  sw    $s4, 0x24($sp)
/* 0D809C 8031D09C AFB30020 */  sw    $s3, 0x20($sp)
/* 0D80A0 8031D0A0 AFB2001C */  sw    $s2, 0x1c($sp)
/* 0D80A4 8031D0A4 AFB10018 */  sw    $s1, 0x18($sp)
/* 0D80A8 8031D0A8 AFB00014 */  sw    $s0, 0x14($sp)
/* 0D80AC 8031D0AC 8C820000 */  lw    $v0, ($a0)
/* 0D80B0 8031D0B0 00809025 */  move  $s2, $a0
/* 0D80B4 8031D0B4 000277C2 */  srl   $t6, $v0, 0x1f
/* 0D80B8 8031D0B8 11C00243 */  beqz  $t6, .L8031D9C8
/* 0D80BC 8031D0BC 0002C080 */   sll   $t8, $v0, 2
/* 0D80C0 8031D0C0 0701000D */  bgez  $t8, .L8031D0F8
/* 0D80C4 8031D0C4 00008025 */   move  $s0, $zero
/* 0D80C8 8031D0C8 00808825 */  move  $s1, $a0
/* 0D80CC 8031D0CC 24120010 */  li    $s2, 16
.L8031D0D0:
/* 0D80D0 8031D0D0 8E240044 */  lw    $a0, 0x44($s1)
/* 0D80D4 8031D0D4 50800004 */  beql  $a0, $zero, .L8031D0E8
/* 0D80D8 8031D0D8 26100004 */   addiu $s0, $s0, 4
/* 0D80DC 8031D0DC 0C0C7031 */  jal   func_8031B0A4
/* 0D80E0 8031D0E0 00000000 */   nop   
/* 0D80E4 8031D0E4 26100004 */  addiu $s0, $s0, 4
.L8031D0E8:
/* 0D80E8 8031D0E8 1612FFF9 */  bne   $s0, $s2, .L8031D0D0
/* 0D80EC 8031D0EC 26310004 */   addiu $s1, $s1, 4
/* 0D80F0 8031D0F0 10000236 */  b     .L8031D9CC
/* 0D80F4 8031D0F4 8FBF002C */   lw    $ra, 0x2c($sp)
.L8031D0F8:
/* 0D80F8 8031D0F8 8E540040 */  lw    $s4, 0x40($s2)
/* 0D80FC 8031D0FC 8E990000 */  lw    $t9, ($s4)
/* 0D8100 8031D100 00195080 */  sll   $t2, $t9, 2
/* 0D8104 8031D104 05430006 */  bgezl $t2, .L8031D120
/* 0D8108 8031D108 96430016 */   lhu   $v1, 0x16($s2)
/* 0D810C 8031D10C 924B0002 */  lbu   $t3, 2($s2)
/* 0D8110 8031D110 316C0080 */  andi  $t4, $t3, 0x80
/* 0D8114 8031D114 5580022D */  bnezl $t4, .L8031D9CC
/* 0D8118 8031D118 8FBF002C */   lw    $ra, 0x2c($sp)
/* 0D811C 8031D11C 96430016 */  lhu   $v1, 0x16($s2)
.L8031D120:
/* 0D8120 8031D120 2650005C */  addiu $s0, $s2, 0x5c
/* 0D8124 8031D124 2415FFFF */  li    $s5, -1
/* 0D8128 8031D128 10600004 */  beqz  $v1, .L8031D13C
/* 0D812C 8031D12C 00601025 */   move  $v0, $v1
/* 0D8130 8031D130 246DFFFF */  addiu $t5, $v1, -1
/* 0D8134 8031D134 A64D0016 */  sh    $t5, 0x16($s2)
/* 0D8138 8031D138 31A2FFFF */  andi  $v0, $t5, 0xffff
.L8031D13C:
/* 0D813C 8031D13C 14400217 */  bnez  $v0, .L8031D99C
/* 0D8140 8031D140 83B3004B */   lb    $s3, 0x4b($sp)
glabel L_U_8031D144
.L8031D144:
/* 0D8144 8031D144 0C0C700F */  jal   func_8031B01C
/* 0D8148 8031D148 02002025 */   move  $a0, $s0
/* 0D814C 8031D14C 240100FF */  li    $at, 255
/* 0D8150 8031D150 305100FF */  andi  $s1, $v0, 0xff
/* 0D8154 8031D154 1441000E */  bne   $v0, $at, .L8031D190
/* 0D8158 8031D158 00401825 */   move  $v1, $v0
/* 0D815C 8031D15C 92040018 */  lbu   $a0, 0x18($s0)
/* 0D8160 8031D160 14800005 */  bnez  $a0, .L8031D178
/* 0D8164 8031D164 248EFFFF */   addiu $t6, $a0, -1
/* 0D8168 8031D168 0C0C6EBC */  jal   func_8031AAD0
/* 0D816C 8031D16C 02402025 */   move  $a0, $s2
/* 0D8170 8031D170 1000020B */  b     .L8031D9A0
/* 0D8174 8031D174 02408825 */   move  $s1, $s2
.L8031D178:
/* 0D8178 8031D178 31CF00FF */  andi  $t7, $t6, 0xff
/* 0D817C 8031D17C 000FC080 */  sll   $t8, $t7, 2
/* 0D8180 8031D180 0218C821 */  addu  $t9, $s0, $t8
/* 0D8184 8031D184 A20E0018 */  sb    $t6, 0x18($s0)
/* 0D8188 8031D188 8F290004 */  lw    $t1, 4($t9)
/* 0D818C 8031D18C AE090000 */  sw    $t1, ($s0)
.L8031D190:
/* 0D8190 8031D190 240100FE */  li    $at, 254
/* 0D8194 8031D194 10610201 */  beq   $v1, $at, .L8031D99C
/* 0D8198 8031D198 240100FD */   li    $at, 253
/* 0D819C 8031D19C 14610005 */  bne   $v1, $at, .L8031D1B4
/* 0D81A0 8031D1A0 307900F0 */   andi  $t9, $v1, 0xf0
/* 0D81A4 8031D1A4 0C0C7020 */  jal   func_8031B060
/* 0D81A8 8031D1A8 02002025 */   move  $a0, $s0
/* 0D81AC 8031D1AC 100001FB */  b     .L8031D99C
/* 0D81B0 8031D1B0 A6420016 */   sh    $v0, 0x16($s2)
.L8031D1B4:
/* 0D81B4 8031D1B4 240100F3 */  li    $at, 243
/* 0D81B8 8031D1B8 14610005 */  bne   $v1, $at, .L8031D1D0
/* 0D81BC 8031D1BC 246DFF3F */   addiu $t5, $v1, -0xc1
/* 0D81C0 8031D1C0 924B0000 */  lbu   $t3, ($s2)
/* 0D81C4 8031D1C4 356C0020 */  ori   $t4, $t3, 0x20
/* 0D81C8 8031D1C8 100001F4 */  b     .L8031D99C
/* 0D81CC 8031D1CC A24C0000 */   sb    $t4, ($s2)
.L8031D1D0:
/* 0D81D0 8031D1D0 286100C1 */  slti  $at, $v1, 0xc1
/* 0D81D4 8031D1D4 1420016E */  bnez  $at, .L8031D790
/* 0D81D8 8031D1D8 2DA1003F */   sltiu $at, $t5, 0x3f
/* 0D81DC 8031D1DC 1020FFD9 */  beqz  $at, .L8031D144
/* 0D81E0 8031D1E0 000D6880 */   sll   $t5, $t5, 2
/* 0D81E4 8031D1E4 3C018034 */  lui   $at, %hi(jtbl_80337D08)
/* 0D81E8 8031D1E8 002D0821 */  addu  $at, $at, $t5
/* 0D81EC 8031D1EC 8C2D8EC0 */  lw    $t5, %lo(jtbl_80337D08)($at)
/* 0D81F0 8031D1F0 01A00008 */  jr    $t5
/* 0D81F4 8031D1F4 00000000 */   nop   
glabel L_U_8031D1F8
/* 0D81F8 8031D1F8 0C0C7014 */  jal   func_8031B030
/* 0D81FC 8031D1FC 02002025 */   move  $a0, $s0
/* 0D8200 8031D200 920E0018 */  lbu   $t6, 0x18($s0)
/* 0D8204 8031D204 8E180000 */  lw    $t8, ($s0)
/* 0D8208 8031D208 304CFFFF */  andi  $t4, $v0, 0xffff
/* 0D820C 8031D20C 25CF0001 */  addiu $t7, $t6, 1
/* 0D8210 8031D210 31F900FF */  andi  $t9, $t7, 0xff
/* 0D8214 8031D214 00194880 */  sll   $t1, $t9, 2
/* 0D8218 8031D218 02095021 */  addu  $t2, $s0, $t1
/* 0D821C 8031D21C A20F0018 */  sb    $t7, 0x18($s0)
/* 0D8220 8031D220 AD580000 */  sw    $t8, ($t2)
/* 0D8224 8031D224 8E8B0014 */  lw    $t3, 0x14($s4)
/* 0D8228 8031D228 016C6821 */  addu  $t5, $t3, $t4
/* 0D822C 8031D22C 1000FFC5 */  b     .L8031D144
/* 0D8230 8031D230 AE0D0000 */   sw    $t5, ($s0)
glabel L_U_8031D234
/* 0D8234 8031D234 0C0C700F */  jal   func_8031B01C
/* 0D8238 8031D238 02002025 */   move  $a0, $s0
/* 0D823C 8031D23C 920E0018 */  lbu   $t6, 0x18($s0)
/* 0D8240 8031D240 020E7821 */  addu  $t7, $s0, $t6
/* 0D8244 8031D244 A1E20014 */  sb    $v0, 0x14($t7)
/* 0D8248 8031D248 92190018 */  lbu   $t9, 0x18($s0)
/* 0D824C 8031D24C 8E180000 */  lw    $t8, ($s0)
/* 0D8250 8031D250 27290001 */  addiu $t1, $t9, 1
/* 0D8254 8031D254 312A00FF */  andi  $t2, $t1, 0xff
/* 0D8258 8031D258 000A5880 */  sll   $t3, $t2, 2
/* 0D825C 8031D25C 020B6021 */  addu  $t4, $s0, $t3
/* 0D8260 8031D260 A2090018 */  sb    $t1, 0x18($s0)
/* 0D8264 8031D264 1000FFB7 */  b     .L8031D144
/* 0D8268 8031D268 AD980000 */   sw    $t8, ($t4)
glabel L_U_8031D26C
/* 0D826C 8031D26C 920D0018 */  lbu   $t5, 0x18($s0)
/* 0D8270 8031D270 020D1021 */  addu  $v0, $s0, $t5
/* 0D8274 8031D274 904E0013 */  lbu   $t6, 0x13($v0)
/* 0D8278 8031D278 25CFFFFF */  addiu $t7, $t6, -1
/* 0D827C 8031D27C A04F0013 */  sb    $t7, 0x13($v0)
/* 0D8280 8031D280 92040018 */  lbu   $a0, 0x18($s0)
/* 0D8284 8031D284 0204C821 */  addu  $t9, $s0, $a0
/* 0D8288 8031D288 93290013 */  lbu   $t1, 0x13($t9)
/* 0D828C 8031D28C 00801825 */  move  $v1, $a0
/* 0D8290 8031D290 00035080 */  sll   $t2, $v1, 2
/* 0D8294 8031D294 11200005 */  beqz  $t1, .L8031D2AC
/* 0D8298 8031D298 248CFFFF */   addiu $t4, $a0, -1
/* 0D829C 8031D29C 020A5821 */  addu  $t3, $s0, $t2
/* 0D82A0 8031D2A0 8D780000 */  lw    $t8, ($t3)
/* 0D82A4 8031D2A4 1000FFA7 */  b     .L8031D144
/* 0D82A8 8031D2A8 AE180000 */   sw    $t8, ($s0)
.L8031D2AC:
/* 0D82AC 8031D2AC 1000FFA5 */  b     .L8031D144
/* 0D82B0 8031D2B0 A20C0018 */   sb    $t4, 0x18($s0)
glabel L_U_8031D2B4
/* 0D82B4 8031D2B4 920D0018 */  lbu   $t5, 0x18($s0)
/* 0D82B8 8031D2B8 25AEFFFF */  addiu $t6, $t5, -1
/* 0D82BC 8031D2BC 1000FFA1 */  b     .L8031D144
/* 0D82C0 8031D2C0 A20E0018 */   sb    $t6, 0x18($s0)
glabel L_U_8031D2C4
/* 0D82C4 8031D2C4 0C0C7014 */  jal   func_8031B030
/* 0D82C8 8031D2C8 02002025 */   move  $a0, $s0
/* 0D82CC 8031D2CC 240100FA */  li    $at, 250
/* 0D82D0 8031D2D0 16210003 */  bne   $s1, $at, .L8031D2E0
/* 0D82D4 8031D2D4 02201825 */   move  $v1, $s1
/* 0D82D8 8031D2D8 1660FF9A */  bnez  $s3, .L8031D144
/* 0D82DC 8031D2DC 00000000 */   nop   
.L8031D2E0:
/* 0D82E0 8031D2E0 240100F9 */  li    $at, 249
/* 0D82E4 8031D2E4 54610004 */  bnel  $v1, $at, .L8031D2F8
/* 0D82E8 8031D2E8 240100F5 */   li    $at, 245
/* 0D82EC 8031D2EC 0661FF95 */  bgez  $s3, .L8031D144
/* 0D82F0 8031D2F0 00000000 */   nop   
/* 0D82F4 8031D2F4 240100F5 */  li    $at, 245
.L8031D2F8:
/* 0D82F8 8031D2F8 54610004 */  bnel  $v1, $at, .L8031D30C
/* 0D82FC 8031D2FC 8E8F0014 */   lw    $t7, 0x14($s4)
/* 0D8300 8031D300 0660FF90 */  bltz  $s3, .L8031D144
/* 0D8304 8031D304 00000000 */   nop   
/* 0D8308 8031D308 8E8F0014 */  lw    $t7, 0x14($s4)
.L8031D30C:
/* 0D830C 8031D30C 3059FFFF */  andi  $t9, $v0, 0xffff
/* 0D8310 8031D310 01F94821 */  addu  $t1, $t7, $t9
/* 0D8314 8031D314 1000FF8B */  b     .L8031D144
/* 0D8318 8031D318 AE090000 */   sw    $t1, ($s0)
glabel L_U_8031D31C
/* 0D831C 8031D31C 26510080 */  addiu $s1, $s2, 0x80
/* 0D8320 8031D320 0C0C68DA */  jal   func_803192FC
/* 0D8324 8031D324 02202025 */   move  $a0, $s1
/* 0D8328 8031D328 0C0C700F */  jal   func_8031B01C
/* 0D832C 8031D32C 02002025 */   move  $a0, $s0
/* 0D8330 8031D330 02202025 */  move  $a0, $s1
/* 0D8334 8031D334 0C0C6925 */  jal   func_80319428
/* 0D8338 8031D338 00402825 */   move  $a1, $v0
/* 0D833C 8031D33C 1000FF81 */  b     .L8031D144
/* 0D8340 8031D340 00000000 */   nop   
glabel L_U_8031D344
/* 0D8344 8031D344 0C0C68DA */  jal   func_803192FC
/* 0D8348 8031D348 26440080 */   addiu $a0, $s2, 0x80
/* 0D834C 8031D34C 1000FF7D */  b     .L8031D144
/* 0D8350 8031D350 00000000 */   nop   
glabel L_U_8031D354
/* 0D8354 8031D354 0C0C7014 */  jal   func_8031B030
/* 0D8358 8031D358 02002025 */   move  $a0, $s0
/* 0D835C 8031D35C 8E8A0014 */  lw    $t2, 0x14($s4)
/* 0D8360 8031D360 304BFFFF */  andi  $t3, $v0, 0xffff
/* 0D8364 8031D364 014BC021 */  addu  $t8, $t2, $t3
/* 0D8368 8031D368 1000FF76 */  b     .L8031D144
/* 0D836C 8031D36C AE580030 */   sw    $t8, 0x30($s2)
glabel L_U_8031D370
/* 0D8370 8031D370 1275FF74 */  beq   $s3, $s5, .L8031D144
/* 0D8374 8031D374 00000000 */   nop   
/* 0D8378 8031D378 8E4C0030 */  lw    $t4, 0x30($s2)
/* 0D837C 8031D37C 00136840 */  sll   $t5, $s3, 1
/* 0D8380 8031D380 8E8A0014 */  lw    $t2, 0x14($s4)
/* 0D8384 8031D384 018D1021 */  addu  $v0, $t4, $t5
/* 0D8388 8031D388 904F0000 */  lbu   $t7, ($v0)
/* 0D838C 8031D38C 904E0001 */  lbu   $t6, 1($v0)
/* 0D8390 8031D390 000FCA00 */  sll   $t9, $t7, 8
/* 0D8394 8031D394 01D93821 */  addu  $a3, $t6, $t9
/* 0D8398 8031D398 30E9FFFF */  andi  $t1, $a3, 0xffff
/* 0D839C 8031D39C 01495821 */  addu  $t3, $t2, $t1
/* 0D83A0 8031D3A0 1000FF68 */  b     .L8031D144
/* 0D83A4 8031D3A4 AE4B0030 */   sw    $t3, 0x30($s2)
glabel L_U_8031D3A8
/* 0D83A8 8031D3A8 0C0C700F */  jal   func_8031B01C
/* 0D83AC 8031D3AC 02002025 */   move  $a0, $s0
/* 0D83B0 8031D3B0 02402025 */  move  $a0, $s2
/* 0D83B4 8031D3B4 0C0C73F5 */  jal   SetInstrument
/* 0D83B8 8031D3B8 304500FF */   andi  $a1, $v0, 0xff
/* 0D83BC 8031D3BC 1000FF61 */  b     .L8031D144
/* 0D83C0 8031D3C0 00000000 */   nop   
glabel L_U_8031D3C4
/* 0D83C4 8031D3C4 92580000 */  lbu   $t8, ($s2)
/* 0D83C8 8031D3C8 330CFFFD */  andi  $t4, $t8, 0xfffd
/* 0D83CC 8031D3CC 1000FF5D */  b     .L8031D144
/* 0D83D0 8031D3D0 A24C0000 */   sb    $t4, ($s2)
glabel L_U_8031D3D4
/* 0D83D4 8031D3D4 924F0000 */  lbu   $t7, ($s2)
/* 0D83D8 8031D3D8 35EE0002 */  ori   $t6, $t7, 2
/* 0D83DC 8031D3DC 1000FF59 */  b     .L8031D144
/* 0D83E0 8031D3E0 A24E0000 */   sb    $t6, ($s2)
glabel L_U_8031D3E4
/* 0D83E4 8031D3E4 0C0C700F */  jal   func_8031B01C
/* 0D83E8 8031D3E8 02002025 */   move  $a0, $s0
/* 0D83EC 8031D3EC 02402025 */  move  $a0, $s2
/* 0D83F0 8031D3F0 0C0C741A */  jal   func_8031C0C4
/* 0D83F4 8031D3F4 304500FF */   andi  $a1, $v0, 0xff
/* 0D83F8 8031D3F8 1000FF52 */  b     .L8031D144
/* 0D83FC 8031D3FC 00000000 */   nop   
glabel L_U_8031D400
/* 0D8400 8031D400 0C0C700F */  jal   func_8031B01C
/* 0D8404 8031D404 02002025 */   move  $a0, $s0
/* 0D8408 8031D408 44822000 */  mtc1  $v0, $f4
/* 0D840C 8031D40C 3C013C00 */  li    $at, 0x3C000000 # 0.007812
/* 0D8410 8031D410 44814000 */  mtc1  $at, $f8
/* 0D8414 8031D414 468021A0 */  cvt.s.w $f6, $f4
/* 0D8418 8031D418 46083282 */  mul.s $f10, $f6, $f8
/* 0D841C 8031D41C 1000FF49 */  b     .L8031D144
/* 0D8420 8031D420 E64A001C */   swc1  $f10, 0x1c($s2)
glabel L_U_8031D424
/* 0D8424 8031D424 0C0C7014 */  jal   func_8031B030
/* 0D8428 8031D428 02002025 */   move  $a0, $s0
/* 0D842C 8031D42C 3059FFFF */  andi  $t9, $v0, 0xffff
/* 0D8430 8031D430 44998000 */  mtc1  $t9, $f16
/* 0D8434 8031D434 3C014700 */  li    $at, 0x47000000 # 32768.000000
/* 0D8438 8031D438 44812000 */  mtc1  $at, $f4
/* 0D843C 8031D43C 468084A0 */  cvt.s.w $f18, $f16
/* 0D8440 8031D440 46049183 */  div.s $f6, $f18, $f4
/* 0D8444 8031D444 1000FF3F */  b     .L8031D144
/* 0D8448 8031D448 E646002C */   swc1  $f6, 0x2c($s2)
glabel L_U_8031D44C
/* 0D844C 8031D44C 0C0C700F */  jal   func_8031B01C
/* 0D8450 8031D450 02002025 */   move  $a0, $s0
/* 0D8454 8031D454 2449007F */  addiu $t1, $v0, 0x7f
/* 0D8458 8031D458 312A00FF */  andi  $t2, $t1, 0xff
/* 0D845C 8031D45C 000A5880 */  sll   $t3, $t2, 2
/* 0D8460 8031D460 3C018033 */  lui   $at, %hi(D_80332488)
/* 0D8464 8031D464 002B0821 */  addu  $at, $at, $t3
/* 0D8468 8031D468 C4283598 */  lwc1  $f8, %lo(D_80332488)($at)
/* 0D846C 8031D46C 1000FF35 */  b     .L8031D144
/* 0D8470 8031D470 E648002C */   swc1  $f8, 0x2c($s2)
glabel L_U_8031D474
/* 0D8474 8031D474 0C0C700F */  jal   func_8031B01C
/* 0D8478 8031D478 02002025 */   move  $a0, $s0
/* 0D847C 8031D47C 44825000 */  mtc1  $v0, $f10
/* 0D8480 8031D480 3C013C00 */  li    $at, 0x3C000000 # 0.007812
/* 0D8484 8031D484 44819000 */  mtc1  $at, $f18
/* 0D8488 8031D488 46805420 */  cvt.s.w $f16, $f10
/* 0D848C 8031D48C 46128102 */  mul.s $f4, $f16, $f18
/* 0D8490 8031D490 1000FF2C */  b     .L8031D144
/* 0D8494 8031D494 E6440024 */   swc1  $f4, 0x24($s2)
glabel L_U_8031D498
/* 0D8498 8031D498 0C0C700F */  jal   func_8031B01C
/* 0D849C 8031D49C 02002025 */   move  $a0, $s0
/* 0D84A0 8031D4A0 44823000 */  mtc1  $v0, $f6
/* 0D84A4 8031D4A4 3C013C00 */  li    $at, 0x3C000000 # 0.007812
/* 0D84A8 8031D4A8 44815000 */  mtc1  $at, $f10
/* 0D84AC 8031D4AC 46803220 */  cvt.s.w $f8, $f6
/* 0D84B0 8031D4B0 460A4402 */  mul.s $f16, $f8, $f10
/* 0D84B4 8031D4B4 1000FF23 */  b     .L8031D144
/* 0D84B8 8031D4B8 E6500028 */   swc1  $f16, 0x28($s2)
glabel L_U_8031D4BC
/* 0D84BC 8031D4BC 8E020000 */  lw    $v0, ($s0)
/* 0D84C0 8031D4C0 80430000 */  lb    $v1, ($v0)
/* 0D84C4 8031D4C4 24580001 */  addiu $t8, $v0, 1
/* 0D84C8 8031D4C8 AE180000 */  sw    $t8, ($s0)
/* 0D84CC 8031D4CC 1000FF1D */  b     .L8031D144
/* 0D84D0 8031D4D0 A643001A */   sh    $v1, 0x1a($s2)
glabel L_U_8031D4D4
/* 0D84D4 8031D4D4 0C0C7014 */  jal   func_8031B030
/* 0D84D8 8031D4D8 02002025 */   move  $a0, $s0
/* 0D84DC 8031D4DC 8E8C0014 */  lw    $t4, 0x14($s4)
/* 0D84E0 8031D4E0 304DFFFF */  andi  $t5, $v0, 0xffff
/* 0D84E4 8031D4E4 018D7821 */  addu  $t7, $t4, $t5
/* 0D84E8 8031D4E8 1000FF16 */  b     .L8031D144
/* 0D84EC 8031D4EC AE4F007C */   sw    $t7, 0x7c($s2)
glabel L_U_8031D4F0
/* 0D84F0 8031D4F0 0C0C700F */  jal   func_8031B01C
/* 0D84F4 8031D4F4 02002025 */   move  $a0, $s0
/* 0D84F8 8031D4F8 1000FF12 */  b     .L8031D144
/* 0D84FC 8031D4FC A2420078 */   sb    $v0, 0x78($s2)
glabel L_U_8031D500
/* 0D8500 8031D500 0C0C700F */  jal   func_8031B01C
/* 0D8504 8031D504 02002025 */   move  $a0, $s0
/* 0D8508 8031D508 000270C0 */  sll   $t6, $v0, 3
/* 0D850C 8031D50C A64E000E */  sh    $t6, 0xe($s2)
/* 0D8510 8031D510 A640000A */  sh    $zero, 0xa($s2)
/* 0D8514 8031D514 1000FF0B */  b     .L8031D144
/* 0D8518 8031D518 A6400012 */   sh    $zero, 0x12($s2)
glabel L_U_8031D51C
/* 0D851C 8031D51C 0C0C700F */  jal   func_8031B01C
/* 0D8520 8031D520 02002025 */   move  $a0, $s0
/* 0D8524 8031D524 00021940 */  sll   $v1, $v0, 5
/* 0D8528 8031D528 A643000C */  sh    $v1, 0xc($s2)
/* 0D852C 8031D52C A6430008 */  sh    $v1, 8($s2)
/* 0D8530 8031D530 1000FF04 */  b     .L8031D144
/* 0D8534 8031D534 A6400010 */   sh    $zero, 0x10($s2)
glabel L_U_8031D538
/* 0D8538 8031D538 0C0C700F */  jal   func_8031B01C
/* 0D853C 8031D53C 02002025 */   move  $a0, $s0
/* 0D8540 8031D540 0002C8C0 */  sll   $t9, $v0, 3
/* 0D8544 8031D544 A659000A */  sh    $t9, 0xa($s2)
/* 0D8548 8031D548 0C0C700F */  jal   func_8031B01C
/* 0D854C 8031D54C 02002025 */   move  $a0, $s0
/* 0D8550 8031D550 000248C0 */  sll   $t1, $v0, 3
/* 0D8554 8031D554 A649000E */  sh    $t1, 0xe($s2)
/* 0D8558 8031D558 0C0C700F */  jal   func_8031B01C
/* 0D855C 8031D55C 02002025 */   move  $a0, $s0
/* 0D8560 8031D560 00025100 */  sll   $t2, $v0, 4
/* 0D8564 8031D564 1000FEF7 */  b     .L8031D144
/* 0D8568 8031D568 A64A0012 */   sh    $t2, 0x12($s2)
glabel L_U_8031D56C
/* 0D856C 8031D56C 0C0C700F */  jal   func_8031B01C
/* 0D8570 8031D570 02002025 */   move  $a0, $s0
/* 0D8574 8031D574 00025940 */  sll   $t3, $v0, 5
/* 0D8578 8031D578 A64B0008 */  sh    $t3, 8($s2)
/* 0D857C 8031D57C 0C0C700F */  jal   func_8031B01C
/* 0D8580 8031D580 02002025 */   move  $a0, $s0
/* 0D8584 8031D584 0002C140 */  sll   $t8, $v0, 5
/* 0D8588 8031D588 A658000C */  sh    $t8, 0xc($s2)
/* 0D858C 8031D58C 0C0C700F */  jal   func_8031B01C
/* 0D8590 8031D590 02002025 */   move  $a0, $s0
/* 0D8594 8031D594 00026100 */  sll   $t4, $v0, 4
/* 0D8598 8031D598 1000FEEA */  b     .L8031D144
/* 0D859C 8031D59C A64C0010 */   sh    $t4, 0x10($s2)
glabel L_U_8031D5A0
/* 0D85A0 8031D5A0 0C0C700F */  jal   func_8031B01C
/* 0D85A4 8031D5A4 02002025 */   move  $a0, $s0
/* 0D85A8 8031D5A8 00026900 */  sll   $t5, $v0, 4
/* 0D85AC 8031D5AC 1000FEE5 */  b     .L8031D144
/* 0D85B0 8031D5B0 A64D0014 */   sh    $t5, 0x14($s2)
glabel L_U_8031D5B4
/* 0D85B4 8031D5B4 0C0C700F */  jal   func_8031B01C
/* 0D85B8 8031D5B8 02002025 */   move  $a0, $s0
/* 0D85BC 8031D5BC 14400003 */  bnez  $v0, .L8031D5CC
/* 0D85C0 8031D5C0 305100FF */   andi  $s1, $v0, 0xff
/* 0D85C4 8031D5C4 3C118022 */  lui   $s1, %hi(D_80226D7E) # $s1, 0x8022
/* 0D85C8 8031D5C8 92316B7E */  lbu   $s1, %lo(D_80226D7E)($s1)
.L8031D5CC:
/* 0D85CC 8031D5CC 1000FEDD */  b     .L8031D144
/* 0D85D0 8031D5D0 A2510006 */   sb    $s1, 6($s2)
glabel L_U_8031D5D4
/* 0D85D4 8031D5D4 0C0C700F */  jal   func_8031B01C
/* 0D85D8 8031D5D8 02002025 */   move  $a0, $s0
/* 0D85DC 8031D5DC 1000FED9 */  b     .L8031D144
/* 0D85E0 8031D5E0 A2420003 */   sb    $v0, 3($s2)
glabel L_U_8031D5E4
/* 0D85E4 8031D5E4 0C0C700F */  jal   func_8031B01C
/* 0D85E8 8031D5E8 02002025 */   move  $a0, $s0
/* 0D85EC 8031D5EC 928F0005 */  lbu   $t7, 5($s4)
/* 0D85F0 8031D5F0 3C038022 */  lui   $v1, %hi(D_80226D58) # $v1, 0x8022
/* 0D85F4 8031D5F4 8C636B58 */  lw    $v1, %lo(D_80226D58)($v1)
/* 0D85F8 8031D5F8 000F7040 */  sll   $t6, $t7, 1
/* 0D85FC 8031D5FC 3C048022 */  lui   $a0, %hi(D_802214F8) # $a0, 0x8022
/* 0D8600 8031D600 006EC821 */  addu  $t9, $v1, $t6
/* 0D8604 8031D604 97270000 */  lhu   $a3, ($t9)
/* 0D8608 8031D608 248410F8 */  addiu $a0, %lo(D_802214F8) # addiu $a0, $a0, 0x10f8
/* 0D860C 8031D60C 24050002 */  li    $a1, 2
/* 0D8610 8031D610 00E34821 */  addu  $t1, $a3, $v1
/* 0D8614 8031D614 91280000 */  lbu   $t0, ($t1)
/* 0D8618 8031D618 00E85021 */  addu  $t2, $a3, $t0
/* 0D861C 8031D61C 01425823 */  subu  $t3, $t2, $v0
/* 0D8620 8031D620 0163C021 */  addu  $t8, $t3, $v1
/* 0D8624 8031D624 93110000 */  lbu   $s1, ($t8)
/* 0D8628 8031D628 0C0C5E0B */  jal   func_8031680C
/* 0D862C 8031D62C 02203025 */   move  $a2, $s1
/* 0D8630 8031D630 1040FEC4 */  beqz  $v0, .L8031D144
/* 0D8634 8031D634 00000000 */   nop   
/* 0D8638 8031D638 1000FEC2 */  b     .L8031D144
/* 0D863C 8031D63C A2510005 */   sb    $s1, 5($s2)
glabel L_U_8031D640
/* 0D8640 8031D640 326C00FF */  andi  $t4, $s3, 0xff
/* 0D8644 8031D644 AFAC0030 */  sw    $t4, 0x30($sp)
/* 0D8648 8031D648 0C0C700F */  jal   func_8031B01C
/* 0D864C 8031D64C 02002025 */   move  $a0, $s0
/* 0D8650 8031D650 305100FF */  andi  $s1, $v0, 0xff
/* 0D8654 8031D654 0C0C7014 */  jal   func_8031B030
/* 0D8658 8031D658 02002025 */   move  $a0, $s0
/* 0D865C 8031D65C 8E8D0014 */  lw    $t5, 0x14($s4)
/* 0D8660 8031D660 8FAE0030 */  lw    $t6, 0x30($sp)
/* 0D8664 8031D664 304FFFFF */  andi  $t7, $v0, 0xffff
/* 0D8668 8031D668 01AF1821 */  addu  $v1, $t5, $t7
/* 0D866C 8031D66C 01D1C821 */  addu  $t9, $t6, $s1
/* 0D8670 8031D670 1000FEB4 */  b     .L8031D144
/* 0D8674 8031D674 A0790000 */   sb    $t9, ($v1)
glabel L_U_8031D678
/* 0D8678 8031D678 0C0C700F */  jal   func_8031B01C
/* 0D867C 8031D67C 02002025 */   move  $a0, $s0
/* 0D8680 8031D680 240100C8 */  li    $at, 200
/* 0D8684 8031D684 16210005 */  bne   $s1, $at, .L8031D69C
/* 0D8688 8031D688 02201825 */   move  $v1, $s1
/* 0D868C 8031D68C 02629823 */  subu  $s3, $s3, $v0
/* 0D8690 8031D690 00135E00 */  sll   $t3, $s3, 0x18
/* 0D8694 8031D694 1000FEAB */  b     .L8031D144
/* 0D8698 8031D698 000B9E03 */   sra   $s3, $t3, 0x18
.L8031D69C:
/* 0D869C 8031D69C 240100CC */  li    $at, 204
/* 0D86A0 8031D6A0 14610005 */  bne   $v1, $at, .L8031D6B8
/* 0D86A4 8031D6A4 02629824 */   and   $s3, $s3, $v0
/* 0D86A8 8031D6A8 00029E00 */  sll   $s3, $v0, 0x18
/* 0D86AC 8031D6AC 00136603 */  sra   $t4, $s3, 0x18
/* 0D86B0 8031D6B0 1000FEA4 */  b     .L8031D144
/* 0D86B4 8031D6B4 01809825 */   move  $s3, $t4
.L8031D6B8:
/* 0D86B8 8031D6B8 00137600 */  sll   $t6, $s3, 0x18
/* 0D86BC 8031D6BC 1000FEA1 */  b     .L8031D144
/* 0D86C0 8031D6C0 000E9E03 */   sra   $s3, $t6, 0x18
glabel L_U_8031D6C4
/* 0D86C4 8031D6C4 0C0C700F */  jal   func_8031B01C
/* 0D86C8 8031D6C8 02002025 */   move  $a0, $s0
/* 0D86CC 8031D6CC 1000FE9D */  b     .L8031D144
/* 0D86D0 8031D6D0 A2420002 */   sb    $v0, 2($s2)
glabel L_U_8031D6D4
/* 0D86D4 8031D6D4 0C0C7014 */  jal   func_8031B030
/* 0D86D8 8031D6D8 02002025 */   move  $a0, $s0
/* 0D86DC 8031D6DC 8E890014 */  lw    $t1, 0x14($s4)
/* 0D86E0 8031D6E0 304AFFFF */  andi  $t2, $v0, 0xffff
/* 0D86E4 8031D6E4 01535821 */  addu  $t3, $t2, $s3
/* 0D86E8 8031D6E8 012BC021 */  addu  $t8, $t1, $t3
/* 0D86EC 8031D6EC 1000FE95 */  b     .L8031D144
/* 0D86F0 8031D6F0 83130000 */   lb    $s3, ($t8)
glabel L_U_8031D6F4
/* 0D86F4 8031D6F4 0C0C700F */  jal   func_8031B01C
/* 0D86F8 8031D6F8 02002025 */   move  $a0, $s0
/* 0D86FC 8031D6FC 924E0000 */  lbu   $t6, ($s2)
/* 0D8700 8031D700 00026880 */  sll   $t5, $v0, 2
/* 0D8704 8031D704 31AF0004 */  andi  $t7, $t5, 4
/* 0D8708 8031D708 31D9FFFB */  andi  $t9, $t6, 0xfffb
/* 0D870C 8031D70C 01F95025 */  or    $t2, $t7, $t9
/* 0D8710 8031D710 1000FE8C */  b     .L8031D144
/* 0D8714 8031D714 A24A0000 */   sb    $t2, ($s2)
glabel L_U_8031D718
/* 0D8718 8031D718 0C0C700F */  jal   func_8031B01C
/* 0D871C 8031D71C 02002025 */   move  $a0, $s0
/* 0D8720 8031D720 1000FE88 */  b     .L8031D144
/* 0D8724 8031D724 A2420001 */   sb    $v0, 1($s2)
glabel L_U_8031D728
/* 0D8728 8031D728 0C0C700F */  jal   func_8031B01C
/* 0D872C 8031D72C 02002025 */   move  $a0, $s0
/* 0D8730 8031D730 00024A00 */  sll   $t1, $v0, 8
/* 0D8734 8031D734 1000FE83 */  b     .L8031D144
/* 0D8738 8031D738 A649007A */   sh    $t1, 0x7a($s2)
glabel L_U_8031D73C
/* 0D873C 8031D73C 1275FE81 */  beq   $s3, $s5, .L8031D144
/* 0D8740 8031D740 0013C040 */   sll   $t8, $s3, 1
/* 0D8744 8031D744 920C0018 */  lbu   $t4, 0x18($s0)
/* 0D8748 8031D748 8E4B0030 */  lw    $t3, 0x30($s2)
/* 0D874C 8031D74C 8E0E0000 */  lw    $t6, ($s0)
/* 0D8750 8031D750 258D0001 */  addiu $t5, $t4, 1
/* 0D8754 8031D754 31AF00FF */  andi  $t7, $t5, 0xff
/* 0D8758 8031D758 000FC880 */  sll   $t9, $t7, 2
/* 0D875C 8031D75C 02195021 */  addu  $t2, $s0, $t9
/* 0D8760 8031D760 A20D0018 */  sb    $t5, 0x18($s0)
/* 0D8764 8031D764 01781021 */  addu  $v0, $t3, $t8
/* 0D8768 8031D768 AD4E0000 */  sw    $t6, ($t2)
/* 0D876C 8031D76C 904B0000 */  lbu   $t3, ($v0)
/* 0D8770 8031D770 90490001 */  lbu   $t1, 1($v0)
/* 0D8774 8031D774 8E8D0014 */  lw    $t5, 0x14($s4)
/* 0D8778 8031D778 000BC200 */  sll   $t8, $t3, 8
/* 0D877C 8031D77C 01383821 */  addu  $a3, $t1, $t8
/* 0D8780 8031D780 30ECFFFF */  andi  $t4, $a3, 0xffff
/* 0D8784 8031D784 01AC7821 */  addu  $t7, $t5, $t4
/* 0D8788 8031D788 1000FE6E */  b     .L8031D144
/* 0D878C 8031D78C AE0F0000 */   sw    $t7, ($s0)
.L8031D790:
/* 0D8790 8031D790 3064000F */  andi  $a0, $v1, 0xf
/* 0D8794 8031D794 2F2100B1 */  sltiu $at, $t9, 0xb1
/* 0D8798 8031D798 1020FE6A */  beqz  $at, .L8031D144
/* 0D879C 8031D79C 308800FF */   andi  $t0, $a0, 0xff
/* 0D87A0 8031D7A0 0019C880 */  sll   $t9, $t9, 2
/* 0D87A4 8031D7A4 3C018034 */  lui   $at, %hi(jtbl_80337E04)
/* 0D87A8 8031D7A8 00390821 */  addu  $at, $at, $t9
/* 0D87AC 8031D7AC 8C398FBC */  lw    $t9, %lo(jtbl_80337E04)($at)
/* 0D87B0 8031D7B0 03200008 */  jr    $t9
/* 0D87B4 8031D7B4 00000000 */   nop   
glabel L_U_8031D7B8
/* 0D87B8 8031D7B8 308E00FF */  andi  $t6, $a0, 0xff
/* 0D87BC 8031D7BC 000E5080 */  sll   $t2, $t6, 2
/* 0D87C0 8031D7C0 024A5821 */  addu  $t3, $s2, $t2
/* 0D87C4 8031D7C4 8D630044 */  lw    $v1, 0x44($t3)
/* 0D87C8 8031D7C8 1060FE5E */  beqz  $v1, .L8031D144
/* 0D87CC 8031D7CC 00000000 */   nop   
/* 0D87D0 8031D7D0 8C730000 */  lw    $s3, ($v1)
/* 0D87D4 8031D7D4 00134840 */  sll   $t1, $s3, 1
/* 0D87D8 8031D7D8 0009C7C2 */  srl   $t8, $t1, 0x1f
/* 0D87DC 8031D7DC 00186600 */  sll   $t4, $t8, 0x18
/* 0D87E0 8031D7E0 1000FE58 */  b     .L8031D144
/* 0D87E4 8031D7E4 000C9E03 */   sra   $s3, $t4, 0x18
glabel L_U_8031D7E8
/* 0D87E8 8031D7E8 308F00FF */  andi  $t7, $a0, 0xff
/* 0D87EC 8031D7EC 024FC821 */  addu  $t9, $s2, $t7
/* 0D87F0 8031D7F0 1000FE54 */  b     .L8031D144
/* 0D87F4 8031D7F4 A3330054 */   sb    $s3, 0x54($t9)
glabel L_U_8031D7F8
/* 0D87F8 8031D7F8 308300FF */  andi  $v1, $a0, 0xff
/* 0D87FC 8031D7FC 02432821 */  addu  $a1, $s2, $v1
/* 0D8800 8031D800 28610004 */  slti  $at, $v1, 4
/* 0D8804 8031D804 1020FE4F */  beqz  $at, .L8031D144
/* 0D8808 8031D808 80B30054 */   lb    $s3, 0x54($a1)
/* 0D880C 8031D80C 1000FE4D */  b     .L8031D144
/* 0D8810 8031D810 A0B50054 */   sb    $s5, 0x54($a1)
glabel L_U_8031D814
/* 0D8814 8031D814 308E00FF */  andi  $t6, $a0, 0xff
/* 0D8818 8031D818 024E5021 */  addu  $t2, $s2, $t6
/* 0D881C 8031D81C 814B0054 */  lb    $t3, 0x54($t2)
/* 0D8820 8031D820 026B9823 */  subu  $s3, $s3, $t3
/* 0D8824 8031D824 00134E00 */  sll   $t1, $s3, 0x18
/* 0D8828 8031D828 1000FE46 */  b     .L8031D144
/* 0D882C 8031D82C 00099E03 */   sra   $s3, $t1, 0x18
glabel L_U_8031D830
/* 0D8830 8031D830 0C0C7014 */  jal   func_8031B030
/* 0D8834 8031D834 02002025 */   move  $a0, $s0
/* 0D8838 8031D838 02201825 */  move  $v1, $s1
/* 0D883C 8031D83C 3065000F */  andi  $a1, $v1, 0xf
/* 0D8840 8031D840 00A01825 */  move  $v1, $a1
/* 0D8844 8031D844 AFA50030 */  sw    $a1, 0x30($sp)
/* 0D8848 8031D848 02402025 */  move  $a0, $s2
/* 0D884C 8031D84C 0C0C6E50 */  jal   func_8031A920
/* 0D8850 8031D850 A7A20052 */   sh    $v0, 0x52($sp)
/* 0D8854 8031D854 8FA30030 */  lw    $v1, 0x30($sp)
/* 0D8858 8031D858 1440FE3A */  bnez  $v0, .L8031D144
/* 0D885C 8031D85C 97A70052 */   lhu   $a3, 0x52($sp)
/* 0D8860 8031D860 8E8D0014 */  lw    $t5, 0x14($s4)
/* 0D8864 8031D864 0003C880 */  sll   $t9, $v1, 2
/* 0D8868 8031D868 02597021 */  addu  $t6, $s2, $t9
/* 0D886C 8031D86C 8DCA0044 */  lw    $t2, 0x44($t6)
/* 0D8870 8031D870 01A77821 */  addu  $t7, $t5, $a3
/* 0D8874 8031D874 1000FE33 */  b     .L8031D144
/* 0D8878 8031D878 AD4F0054 */   sw    $t7, 0x54($t2)
glabel L_U_8031D87C
/* 0D887C 8031D87C 02202825 */  move  $a1, $s1
/* 0D8880 8031D880 30AB000F */  andi  $t3, $a1, 0xf
/* 0D8884 8031D884 01602825 */  move  $a1, $t3
/* 0D8888 8031D888 0C0C6E9B */  jal   func_8031AA4C
/* 0D888C 8031D88C 02402025 */   move  $a0, $s2
/* 0D8890 8031D890 1000FE2C */  b     .L8031D144
/* 0D8894 8031D894 00000000 */   nop   
glabel L_U_8031D898
/* 0D8898 8031D898 1275FE2A */  beq   $s3, $s5, .L8031D144
/* 0D889C 8031D89C 02402025 */   move  $a0, $s2
/* 0D88A0 8031D8A0 02201825 */  move  $v1, $s1
/* 0D88A4 8031D8A4 3065000F */  andi  $a1, $v1, 0xf
/* 0D88A8 8031D8A8 00A01825 */  move  $v1, $a1
/* 0D88AC 8031D8AC 0C0C6E50 */  jal   func_8031A920
/* 0D88B0 8031D8B0 AFA50030 */   sw    $a1, 0x30($sp)
/* 0D88B4 8031D8B4 1055FE23 */  beq   $v0, $s5, .L8031D144
/* 0D88B8 8031D8B8 8FA30030 */   lw    $v1, 0x30($sp)
/* 0D88BC 8031D8BC 8E580030 */  lw    $t8, 0x30($s2)
/* 0D88C0 8031D8C0 00136040 */  sll   $t4, $s3, 1
/* 0D88C4 8031D8C4 8E8A0014 */  lw    $t2, 0x14($s4)
/* 0D88C8 8031D8C8 030C1021 */  addu  $v0, $t8, $t4
/* 0D88CC 8031D8CC 90590000 */  lbu   $t9, ($v0)
/* 0D88D0 8031D8D0 904D0001 */  lbu   $t5, 1($v0)
/* 0D88D4 8031D8D4 00034880 */  sll   $t1, $v1, 2
/* 0D88D8 8031D8D8 00197200 */  sll   $t6, $t9, 8
/* 0D88DC 8031D8DC 0249C021 */  addu  $t8, $s2, $t1
/* 0D88E0 8031D8E0 01AE3821 */  addu  $a3, $t5, $t6
/* 0D88E4 8031D8E4 8F0C0044 */  lw    $t4, 0x44($t8)
/* 0D88E8 8031D8E8 30EFFFFF */  andi  $t7, $a3, 0xffff
/* 0D88EC 8031D8EC 014F5821 */  addu  $t3, $t2, $t7
/* 0D88F0 8031D8F0 1000FE14 */  b     .L8031D144
/* 0D88F4 8031D8F4 AD8B0054 */   sw    $t3, 0x54($t4)
glabel L_U_8031D8F8
/* 0D88F8 8031D8F8 1000FE12 */  b     .L8031D144
/* 0D88FC 8031D8FC A2440004 */   sb    $a0, 4($s2)
glabel L_U_8031D900
/* 0D8900 8031D900 0C0C7014 */  jal   func_8031B030
/* 0D8904 8031D904 02002025 */   move  $a0, $s0
/* 0D8908 8031D908 8E8D0014 */  lw    $t5, 0x14($s4)
/* 0D890C 8031D90C 02202825 */  move  $a1, $s1
/* 0D8910 8031D910 30B9000F */  andi  $t9, $a1, 0xf
/* 0D8914 8031D914 304EFFFF */  andi  $t6, $v0, 0xffff
/* 0D8918 8031D918 03202825 */  move  $a1, $t9
/* 0D891C 8031D91C 02802025 */  move  $a0, $s4
/* 0D8920 8031D920 0C0C6F68 */  jal   func_8031AD80
/* 0D8924 8031D924 01AE3021 */   addu  $a2, $t5, $t6
/* 0D8928 8031D928 1000FE06 */  b     .L8031D144
/* 0D892C 8031D92C 00000000 */   nop   
glabel L_U_8031D930
/* 0D8930 8031D930 322A000F */  andi  $t2, $s1, 0xf
/* 0D8934 8031D934 000A4880 */  sll   $t1, $t2, 2
/* 0D8938 8031D938 0289C021 */  addu  $t8, $s4, $t1
/* 0D893C 8031D93C 0C0C6EBC */  jal   func_8031AAD0
/* 0D8940 8031D940 8F04002C */   lw    $a0, 0x2c($t8)
/* 0D8944 8031D944 1000FDFF */  b     .L8031D144
/* 0D8948 8031D948 00000000 */   nop   
glabel L_U_8031D94C
/* 0D894C 8031D94C 02002025 */  move  $a0, $s0
/* 0D8950 8031D950 0C0C700F */  jal   func_8031B01C
/* 0D8954 8031D954 A3A80055 */   sb    $t0, 0x55($sp)
/* 0D8958 8031D958 93A80055 */  lbu   $t0, 0x55($sp)
/* 0D895C 8031D95C 00085880 */  sll   $t3, $t0, 2
/* 0D8960 8031D960 028B6021 */  addu  $t4, $s4, $t3
/* 0D8964 8031D964 8D99002C */  lw    $t9, 0x2c($t4)
/* 0D8968 8031D968 03226821 */  addu  $t5, $t9, $v0
/* 0D896C 8031D96C 1000FDF5 */  b     .L8031D144
/* 0D8970 8031D970 A1B30054 */   sb    $s3, 0x54($t5)
glabel L_U_8031D974
/* 0D8974 8031D974 02002025 */  move  $a0, $s0
/* 0D8978 8031D978 0C0C700F */  jal   func_8031B01C
/* 0D897C 8031D97C A3A80055 */   sb    $t0, 0x55($sp)
/* 0D8980 8031D980 93A80055 */  lbu   $t0, 0x55($sp)
/* 0D8984 8031D984 00087080 */  sll   $t6, $t0, 2
/* 0D8988 8031D988 028E7821 */  addu  $t7, $s4, $t6
/* 0D898C 8031D98C 8DEA002C */  lw    $t2, 0x2c($t7)
/* 0D8990 8031D990 01424821 */  addu  $t1, $t2, $v0
/* 0D8994 8031D994 1000FDEB */  b     .L8031D144
/* 0D8998 8031D998 81330054 */   lb    $s3, 0x54($t1)
.L8031D99C:
/* 0D899C 8031D99C 02408825 */  move  $s1, $s2
.L8031D9A0:
/* 0D89A0 8031D9A0 24120010 */  li    $s2, 16
/* 0D89A4 8031D9A4 00008025 */  move  $s0, $zero
.L8031D9A8:
/* 0D89A8 8031D9A8 8E240044 */  lw    $a0, 0x44($s1)
/* 0D89AC 8031D9AC 50800004 */  beql  $a0, $zero, .L8031D9C0
/* 0D89B0 8031D9B0 26100004 */   addiu $s0, $s0, 4
/* 0D89B4 8031D9B4 0C0C7031 */  jal   func_8031B0A4
/* 0D89B8 8031D9B8 00000000 */   nop   
/* 0D89BC 8031D9BC 26100004 */  addiu $s0, $s0, 4
.L8031D9C0:
/* 0D89C0 8031D9C0 1612FFF9 */  bne   $s0, $s2, .L8031D9A8
/* 0D89C4 8031D9C4 26310004 */   addiu $s1, $s1, 4
.L8031D9C8:
/* 0D89C8 8031D9C8 8FBF002C */  lw    $ra, 0x2c($sp)
.L8031D9CC:
/* 0D89CC 8031D9CC 8FB00014 */  lw    $s0, 0x14($sp)
/* 0D89D0 8031D9D0 8FB10018 */  lw    $s1, 0x18($sp)
/* 0D89D4 8031D9D4 8FB2001C */  lw    $s2, 0x1c($sp)
/* 0D89D8 8031D9D8 8FB30020 */  lw    $s3, 0x20($sp)
/* 0D89DC 8031D9DC 8FB40024 */  lw    $s4, 0x24($sp)
/* 0D89E0 8031D9E0 8FB50028 */  lw    $s5, 0x28($sp)
/* 0D89E4 8031D9E4 03E00008 */  jr    $ra
/* 0D89E8 8031D9E8 27BD0060 */   addiu $sp, $sp, 0x60
)
#endif

void func_8031CAD4(struct Struct80222A18 *arg0)
{
    u8 instr;
    u8 loBits;
    u8 temp;
    s8 tempSigned;
    s32 value;
    s32 i;
    u16 u16v;
    u8 *tempPtr;
    struct Interface1Buffer *buf;

    if (arg0->unk0b80 == 0)
    {
        return;
    }

    if (arg0->unk0b8 == 1)
    {
        if (arg0->mesg2 == NULL)
        {
            return;
        }
        if (arg0->size == 0)
        {
            arg0->unk0b8 = 0;
            func_8031784C(arg0->mem, D_80226D54->seqArray[arg0->unk7].offset, arg0->unk8, arg0->unk9);
            D_80226D60[arg0->unk7].unk1 = arg0->unk8;
            D_80226D60[arg0->unk7].unk2 = arg0->unk9;
            D_80226D60[arg0->unk7].unk4 = arg0->mem->subB;
            D_80226D60[arg0->unk7].unk8 = arg0->mem->header;
            D_802218D0[arg0->unk7] = 2;
        }
        else
        {
            osCreateMesgQueue(&arg0->mesgQueue2, &arg0->mesg2, 1);
            arg0->mesg2 = NULL;
            func_803170A0(&arg0->currentDevAddr, &arg0->currentMemAddr, &arg0->size, &arg0->mesgQueue2, &arg0->ioMesg2);
        }
        return;
    }

    if (arg0->unk0b10 == 1)
    {
        if (arg0->mesg1 == NULL)
        {
            return;
        }
        arg0->unk0b10 = 0;
        D_80221910[arg0->unk5] = 2;
    }

    if ((D_80221910[arg0->unk5] < 2) != 0 || (D_802218D0[arg0->unk6[0]] < 2) != 0)
    {
        func_8031AE24(arg0);
        return;
    }

    D_80221910[arg0->unk5] = 2;
    D_802218D0[arg0->unk6[0]] = 2;
    if (arg0->unk0b20 && (arg0->unk4 & 0x80) != 0)
    {
        return;
    }

    arg0->unkC += arg0->unkA;
    if (arg0->unkC < D_80226D7C)
    {
        return;
    }
    arg0->unkC -= (u16) D_80226D7C;

    buf = &arg0->unk6C;
    if (arg0->unk12 >= 2)
    {
        arg0->unk12--;
    }
    else
    {
        for (;;)
        {
            instr = func_8031B01C(buf);
            if (instr == 0xff)
            {
                if (buf->unk18 == 0)
                {
                    func_8031AE24(arg0);
                    break;
                }
                buf->unk18--,
                buf->unk0 = buf->unk4[buf->unk18];
            }

            if (instr == 0xfd)
            {
                arg0->unk12 = func_8031B060(buf);
                break;
            }

            if (instr == 0xfe)
            {
                arg0->unk12 = 1;
                break;
            }

            if (instr >= 0xc0)
            {
                switch (instr)
                {
                case 0xff:
                    break;

                case 0xfc:
                    u16v = func_8031B030(buf);
                    buf->unk18++,
                    buf->unk4[buf->unk18 - 1] = buf->unk0;
                    buf->unk0 = arg0->unk14 + u16v;
                    break;

                case 0xf8:
                    buf->unk14[buf->unk18] = func_8031B01C(buf);
                    buf->unk18++,
                    buf->unk4[buf->unk18 - 1] = buf->unk0;
                    break;

                case 0xf7:
                    buf->unk14[buf->unk18 - 1]--;
                    if (buf->unk14[buf->unk18 - 1] != 0)
                    {
                        buf->unk0 = buf->unk4[buf->unk18 -  1];
                    }
                    else
                    {
                        buf->unk18--;
                    }
                    break;

                case 0xf5:
                case 0xf9:
                case 0xfa:
                case 0xfb:
                    u16v = func_8031B030(buf);
                    if (instr == 0xfa && value != 0) break;
                    if (instr == 0xf9 && value >= 0) break;
                    if (instr == 0xf5 && value < 0) break;
                    buf->unk0 = arg0->unk14 + u16v;
                    break;

                case 0xf2:
                    func_803192FC(arg0->unk90);
                    func_80319428(arg0->unk90, func_8031B01C(buf));
                    break;

                case 0xf1:
                    func_803192FC(arg0->unk90);
                    break;

                case 0xdf:
                    arg0->unk10 = 0;
                    // fallthrough

                case 0xde:
                    arg0->unk10 += (s8) func_8031B01C(buf);
                    break;

                case 0xdd:
                case 0xdc:
                    temp = func_8031B01C(buf);
                    if (instr == 0xdd)
                    {
#ifdef VERSION_JP
                        arg0->unkA = temp;
#else
                        arg0->unkA = temp * 0x30;
#endif
                    }
                    else
                    {
#ifdef VERSION_JP
                        arg0->unkA += (s8) temp;
#else
                        arg0->unkA += (s8) temp * 0x30;
#endif
                    }

                    if (arg0->unkA > D_80226D7C)
                    {
                        arg0->unkA = D_80226D7C;
                    }

                    if ((s16) arg0->unkA <= 0)
                    {
                        arg0->unkA = 1;
                    }
                    break;

                case 0xdb:
                    temp = func_8031B01C(buf);
                    switch (arg0->unk2)
                    {
                    case 2:
                        if (arg0->unkE != 0)
                        {
                            f32 scaled = FLOAT_CAST(temp) / US_FLOAT(127.0);
                            arg0->unk1C = (scaled - arg0->unk18) / FLOAT_CAST(arg0->unkE);
                            break;
                        }
                        // fallthrough
                    case 0:
                        arg0->unk18 = FLOAT_CAST(temp) / US_FLOAT(127.0);
                        break;
                    case 1:
                    case 4:
                        arg0->unk20 = FLOAT_CAST(temp) / US_FLOAT(127.0);
                        break;
                    }
                    break;

                case 0xda:
                    tempSigned = func_8031B01C(buf);
                    arg0->unk18 = arg0->unk18 + (f32) tempSigned / US_FLOAT(127.0);
                    break;

                case 0xd7:
                    u16v = func_8031B030(buf);
                    func_8031AB84(arg0, u16v);
                    break;

                case 0xd6:
                    u16v = func_8031B030(buf);
                    func_8031ACB0(arg0, u16v);
                    break;

                case 0xd5:
                    tempSigned = func_8031B01C(buf);
                    arg0->unk24 = (f32) tempSigned / US_FLOAT(127.0);
                    break;

                case 0xd4:
                    arg0->unk0b20 = 1;
                    break;

                case 0xd3:
                    arg0->unk4 = func_8031B01C(buf);
                    break;

                case 0xd2:
                case 0xd1:
                    u16v = func_8031B030(buf);
                    tempPtr = arg0->unk14 + u16v;
                    if (instr == 0xd2)
                    {
                        arg0->unk88 = tempPtr;
                    }
                    else
                    {
                        arg0->unk8C = tempPtr;
                    }
                    break;

                case 0xd0:
                    arg0->unk3 = func_8031B01C(buf);
                    break;

                case 0xcc:
                    value = func_8031B01C(buf);
                    break;

                case 0xc9:
                    value = func_8031B01C(buf) & value;
                    break;

                case 0xc8:
                    value = value - func_8031B01C(buf);
                    break;
                }
            }
            else
            {
                loBits = instr & 0xf;
                switch (instr & 0xf0)
                {
                case 0x00: {
                    if (IS_SPECIAL(arg0->unk2C[loBits]) == 1)
                    {
                        value = arg0->unk2C[loBits]->unk0b40;
                    }
                    break;
                }
                case 0x10:
                    break;
                case 0x20:
                    break;
                case 0x40:
                    break;
                case 0x50:
                    value -= arg0->unk1;
                    break;
                case 0x60:
                    break;
                case 0x70:
                    arg0->unk1 = value;
                    break;
                case 0x80:
                    value = arg0->unk1;
                    break;
                case 0x90:
                    u16v = func_8031B030(buf);
                    func_8031AD80(arg0, loBits, arg0->unk14 + u16v);
                    break;
                case 0xa0:
                    break;
                case 0xd8: // (this makes no sense)
                    break;
                case 0xd9:
                    break;
                }
            }
        }
    }

    for (i = 0; i < 0x10; i++)
    {
        if (arg0->unk2C[i] != &D_80225DD8)
        {
            func_8031C104(arg0->unk2C[i]);
        }
    }
}

void func_8031D384(UNUSED s32 arg0)
{
    s32 i;
    for (i = 0; i < 3; i++)
    {
        if (D_80222A18[i].unk0b80 == 1)
        {
            func_8031CAD4(D_80222A18 + i);
            func_80319E78(D_80222A18 + i);
        }
    }
    func_80319BC8();
    func_80318908();
}

void func_8031D42C(u32 arg0)
{
    struct Struct80222A18 *temp = &D_80222A18[arg0];
    temp->unk0b20 = 0;
    temp->unk12 = 0;
    temp->unk2 = 0;
    temp->unkE = 0;
    temp->unkC = 0;
#ifdef VERSION_JP
    temp->unkA = 0x78;
#else
    temp->unkA = 0x1680;
#endif
    temp->unk10 = 0;
    temp->unk4 = 0xe0;
    temp->unk3 = 0;
    temp->unk88 = D_80332A84;
    temp->unk8C = D_80332A94;
    temp->unk18 = 1.0f;
    temp->unk1C = 0.0f;
    temp->unk20 = 0.0f;
    temp->unk24 = 0.5f;
}

void func_8031D4B8(void)
{
    // Initialization function, called from InitAudioSystem
    s32 i, j;

    for (i = 0; i < 32; i++)
    {
        D_80222DD8[i].unk40 = 0;
        D_80222DD8[i].unk0b80 = 0;
    }

    for (i = 0; i < 32; i++)
    {
        //! Size of wrong array. Zeroes out second half of D_80222DD8[0],
        // all of D_80222DD8[1..31], and part of D_802245D8[0].
        // However, this is only called at startup, so it's pretty harmless.
        for (j = 0; j < ARRAY_COUNT(D_802245D8); j++)
        {
            D_80222DD8[i].unk44[j] = NULL;
        }
    }

    func_8031AF74();

    for (i = 0; i < ARRAY_COUNT(D_802245D8); i++)
    {
        D_802245D8[i].unk50 = 0;
        D_802245D8[i].unk0b80 = 0;
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 0x10; j++)
        {
            D_80222A18[i].unk2C[j] = &D_80225DD8;
        }

        D_80222A18[i].unk1 = -1;
        D_80222A18[i].unk0b8 = 0;
        D_80222A18[i].unk0b10 = 0;
        func_803191F8(D_80222A18[i].unk90);
        func_8031D42C(i);
    }
}
