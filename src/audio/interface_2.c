#include <ultra64.h>

#include "sm64.h"
#include "interface_1.h"
#include "interface_2.h"
#include "playback.h"
#include "dma.h"
#include "dac.h"
#include "../mario.h"
#include "../level_update.h"
#include "../area.h"
#include "../room.h"

#ifdef VERSION_JP
#define US_FLOAT(x) x
#define IF_US(jp, us) jp
#else
#define US_FLOAT(x) x ## f
#define IF_US(jp, us) us
#endif

struct Sound
{
    s32 unk0;
    f32 *unk4;
}; // size = 8

struct Struct80360928
{
    f32 unk0;
    u8 unk4;
    f32 unk8;
    u16 unkC;
}; // size = 0x10

struct Struct80360C48
{
    f32 *unk0;
    f32 *unk4;
    f32 *unk8;
    f32 unkC;
    u32 unk10; // priority?
    u32 unk14; // packed bits, same as first arg to SetSound
    u8 unk18; // 0, 1, or 2-15
    u8 unk19; // sometimes set to 10
    u8 unk1A; // prev
    u8 unk1B; // next (or vice versa)
}; // size = 0x1C

struct Struct80363818
{
    u8 unk0;
    u8 unk1;
}; // size = 2

struct Struct80331F50
{
    s16 unk0;
    u8 unk2;
    u8 unk3;
    s16 unk4;
    s16 unk6;
    u8 unk8;
    u8 unk9;
    s16 unkA;
}; // size = 0xC

// data
s32 D_80331D40 = 0;
s32 D_80331D44 = 0;

// Dialog sounds
// The US difference is the sound for Dialog037 ("I win! You lose! Ha ha ha ha!
// You're no slouch, but I'm a better sledder! Better luck next time!")
#define _ 0xff
u8 D_80331D48[170] = {
//     0  1  2  3  4  5  6  7  8  9
/* 0*/ _, 6, 6, 6, 6, 3, 3, 3, _, 3,
/* 1*/ _, _, _, _, _, _, _, 4, _, _,
/* 2*/ _, 2, 2, 2, 2, 2, 2, 2, 2, 2,
/* 3*/ _, _, _, _, _, _, _, IF_US(3, 1), _, _,
/* 4*/ _, 3, _, _, _, _, _, 6, _, _,
/* 5*/ _, _, _, _, _, 1, 1, 1, 1, 1,
/* 6*/ _, _, _, _, _, _, _, 7, _, _,
/* 7*/ _, _, _, _, _, _, _, _, _, 0,
/* 8*/ 0, _, _, _, _, 5, _, _, _, _,
/* 9*/ 7, _, 7, 7, _, _, _, _, 5, 5,
/*10*/ 0, 0, _, _, _, 6, 6, 5, 5, _,
/*11*/ _, _, _, _, 8, 8, 4, 8, 8, _,
/*12*/ _, _, _, _, _, _, _, _, 4, _,
/*13*/ _, _, 1, _, _, _, _, _, _, _,
/*14*/ _, _, _, _, _, _, _, _, _, _,
/*15*/ 9, 9, 9, _, _, _, _, _, _, _,
/*16*/ _, 10, _, _, _, _, _, _, 9, _
};
#undef _

s32 D_80331DF4[15] = {
    0x50210081, 0x502d0081, 0x505f8091, 0x503da081,
    0x50410081, 0x50480081, 0x50584081, 0x50388081,
    0x90694081, 0x506f0081, 0x30703081, 0x00000000,
    0x00000000, 0x00000000, 0x00000000
};

u8 D_80331E30 = 0;
u8 D_80331E34 = 0;

// Format:
// - only play if D_80331EB0 equals this number
// - repeated until mask == 0:
//   - mask << 8 | index, where index points into D_80331F50
//   - one number for each bit set in mask
s16 D_80331E38[] = // BBH
{10,
    0x01 << 8 | 6, 13,
    0x01 << 8 | 6, 10,
    5};
s16 D_80331E44[] = // DDD
{5,
    0x12 << 8 | 0, -800, 1,
    0x52 << 8 | 0, -2000, 470, 1,
    0x42 << 8 | 2, 100, 2,
    1};
s16 D_80331E5C[] = // JRB
{5,
    0x50 << 8 | 0, 945, -5260,
    0x02 << 8 | 0, 2,
    0x40 << 8 | 0, 1000,
    0x44 << 8 | 2, -3100, -900,
    1, 5};
s16 D_80331E78[] = // WDW
{12,
    0x0a << 8 | 4, -670, 1,
    0x02 << 8 | 4, 2,
    3};
s16 D_80331E88[] = // HMC
{12,
    0x88 << 8 | 4, 0, -203,
    0x18 << 8 | 4, 0, -2400,
    3};
s16 D_80331E98[] = // LEVEL_UNKNOWN_38
{12,
    0x02 << 8 | 3, 1,
    0x02 << 8 | 4, 2,
    0x02 << 8 | 7, 3,
    0};
s16 D_80331EA8[] = {0, 0};

u8 D_80331EAC = 0xff; // current music?
u8 D_80331EB0 = 0xff;

#define _ D_80331EA8
s16 *D_80331EB4[LEVEL_MAX+1] = {
    _, _, _, _, D_80331E38, _, _, D_80331E88, _, _, _, D_80331E78, D_80331E5C,
    _, _, _, _, _, _, _, _, _, _, D_80331E44, _, _, _, _, _, _, _, _, _, _, _,
    _, _, _, D_80331E98
};
#undef _

struct Struct80331F50 D_80331F50[8] = {
    {0,      0, 0x7f, 100, 0xe43, 0, 0, 100},
    {3,      0, 0x7f, 100, 0xe40, 0, 0, 100},
    {0xe43,  0, 0x7f, 200, 0,     0, 0, 200},
    {0x2ff,  0, 0x7f, 100, 0x100, 0, 0, 100},
    {0x3f7,  0, 0x7f, 100, 8,     0, 0, 100},
    {0x70,   0, 0x7f, 10,  0,     0, 0, 100},
    {0,      0, 0x7f, 100, 0x70,  0, 0, 10},
    {0xffff, 0, 0x7f, 100, 0,     0, 0, 100}
};

u8 D_80331FB0[40][3] = {
    {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00},
    {0x28, 0x28, 0x28},
    {0x10, 0x38, 0x38},
    {0x20, 0x20, 0x30},
    {0x28, 0x28, 0x28},
    {0x08, 0x30, 0x30},
    {0x08, 0x08, 0x08},
    {0x10, 0x28, 0x28},
    {0x10, 0x18, 0x18},
    {0x10, 0x18, 0x18},
    {0x0c, 0x0c, 0x20},
    {0x18, 0x18, 0x18},
    {0x20, 0x20, 0x20},
    {0x08, 0x08, 0x08},
    {0x28, 0x28, 0x28},
    {0x28, 0x28, 0x28},
    {0x28, 0x28, 0x28},
    {0x10, 0x10, 0x10},
    {0x28, 0x28, 0x28},
    {0x08, 0x30, 0x30},
    {0x10, 0x20, 0x20},
    {0x08, 0x08, 0x08},
    {0x00, 0x00, 0x00},
    {0x08, 0x08, 0x08},
    {0x28, 0x28, 0x28},
    {0x28, 0x28, 0x28},
    {0x20, 0x20, 0x20},
    {0x40, 0x40, 0x40},
    {0x28, 0x28, 0x28},
    {0x70, 0x00, 0x00},
    {0x40, 0x40, 0x40},
    {0x40, 0x40, 0x40},
    {0x00, 0x00, 0x00},
    {0x08, 0x08, 0x08},
    {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00}
};

u16 D_80332028[LEVEL_MAX+1] = {
    20000, 20000, 20000, 20000, 28000, 17000, 20000, 16000,
    15000, 15000, 14000, 17000, 20000, 20000, 18000, 20000,
    25000, 16000, 30000, 16000, 20000, 16000, 22000, 17000,
    13000, 20000, 20000, 20000, 18000, 20000, IF_US(25000, 60000),
    20000, 20000, IF_US(25000, 60000), IF_US(25000, 60000),
    20000, 15000, 20000, 20000
};

u8 D_80332078[36] = {
    127, 80, 80, 75, 70, 75, 75, 75, 70, 65, 80, 65, 85, 75, 65, 70, 65, 70,
    70, 65, 80, 70, 85, 75, 75, 85, 70, 80, 80, 70, 75, 80, 70, 65, 0, 0
};

u8 D_8033209C = 0xff;
u8 D_803320A0 = 0;
u8 D_803320A4[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // pointers to head of list
u8 D_803320B0[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; // pointers to head of list
u8 D_803320BC[10] = {0};
u8 D_803320C8[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; // sizes of D_80360C38
u8 D_803320D4[10] = {0x70, 0x30, IF_US(0x30, 0x40), 0x80, 0x20,
                     0x80, 0x20, IF_US(0x30, 0x40), 0x80, 0x80};
f32 D_803320E0[6] = {0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f}; // exported
u8 D_803320F8[16] = {0}; // (size 10 + file split/unused var?)
u8 D_80332108 = 0;
u8 D_8033210C = 0;
u16 D_80332110 = 0;
u8 D_80332114 = 0;
u16 D_80332118 = 0;
u8 D_8033211C = 0;
u8 D_80332120 = 0;
u8 D_80332124 = 0;
u8 D_80332128 = 0;
#ifndef VERSION_JP
u8 D_U_8033323C = 0;
#endif

// bss
u16 *D_80360120;
struct Sound D_80360128[0x100];
struct Struct80360928 D_80360928[3][16];
u8 D_80360C28[10];
u8 D_80360C38[10][1];
struct Struct80360C48 D_80360C48[10][40]; // list item memory for D_803320A4 and D_803320B0
u8 D_80363808[10];
u8 D_80363812;
u8 D_80363813;
struct Struct80363818 D_80363818[6];

#ifdef VERSION_JP
typedef u16 Arg1T;
typedef u8 Arg2T;
#else
typedef s32 Arg1T;
typedef s32 Arg2T;
#endif

// Local functions that should be static but are defined in/called from GLOBAL_ASM blocks:
void func_8031DFE8(u8 listIndex, u8 item);
void func_8031E0E4(u8 listIndex, u8 item);
void func_8031E16C(u8 arg0);
f32 func_8031E97C(f32 arg0, f32 arg1);
f32 func_8031EB24(u8 listIndex, u8 item, f32 arg2);
f32 func_8031EC7C(u8 listIndex, u8 item);
u8 func_8031ED70(u8 arg0, u8 arg1, u8 arg2);
void func_8031EEF8(void);
void SetMusic(u8 arg0, u8 arg1, u16 arg2);
void func_8031F888(u8 arg0, u8 arg1, u8 arg2, u16 arg3);
void func_8031F96C(u8 arg0);
void func_8031FA4C(void);
u8 func_803200E4(u16 arg0);
void func_80320ED8(void);

#ifdef VERSION_US
void unused_8031E4F0(void)
{
    // This is some debug function which is almost entirely optimized away,
    // except for loops, string literals (the original source likely did
    // "#define printf /* nothing */"), and a read of a volatile variable.
    s32 i;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-value"
    "AUTOSEQ ";
    "%2x %2x <%5x : %5x / %5x>\n";
    "AUTOBNK ";
    "%2x %3x <%5x : %5x / %5x>\n";
    "STAYSEQ ";
    "[%2x] <%5x / %5x>\n";
    "%2x ";
    "\n";
    "STAYBNK ";
    "[%2x] <%5x / %5x>\n";
    "%2x ";
    "\n\n";
    "    0123456789ABCDEF0123456789ABCDEF01234567\n";
    "--------------------------------------------\n";
    "SEQ ";
    "%1x";
    "\n";
    "BNK ";
    "%1x";
    "\n";
    "FIXHEAP ";
    "%4x / %4x\n";
    "DRVHEAP ";
    "%5x / %5x\n";
    "DMACACHE  %4d Blocks\n";
    "CHANNELS  %2d / MAX %3d \n";
    "TEMPOMAX  %d\n";
    "TEMPO G0  %d\n";
    "TEMPO G1  %d\n";
    "TEMPO G2  %d\n";
    "DEBUGFLAG  %8x\n";
    "COUNT %8d\n";
#pragma GCC diagnostic pop

    for (i = 0; (u32)i < D_80221328.first.unk0; i++) {}
    for (i = 0; (u32)i < D_802214F8.first.unk0; i++) {}
    for (i = 0; i < 40; i++) {}
    for (i = 0; i < 40; i += 4) {}
}

void unused_8031E568(void)
{
    D_80226D80;
}
#endif

static void func_8031D630(s32 arg0, Arg1T arg1)
{
    struct Struct80222A18 *temp = &D_80222A18[arg0];
#ifndef VERSION_JP
    if (arg1 == 0)
    {
        arg1++;
    }
#endif

    temp->unk1C = -(temp->unk18 / arg1);
    temp->unk2 = 1;
    temp->unkE = arg1;
}

static void func_8031D690(s32 arg0, Arg1T arg1)
{
    struct Struct80222A18 *temp = &D_80222A18[arg0];

    // TODO: move this to the correct function of this file (it matches
    // regardless of where it is placed).
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-value"
    "DAC:Lost 1 Frame.\n";
    "DMA: Request queue over.( %d )\n";
#pragma GCC diagnostic pop

    if (arg1 == 0 || temp->unk2 == 1)
    {
        return;
    }

    temp->unk2 = 2;
    temp->unkE = arg1;
    temp->unk18 = 0.0f;
    temp->unk1C = 0.0f;
}

static void func_8031D6E4(s32 arg0, Arg1T arg1, u8 arg2)
{
    struct Struct80222A18 *temp = &D_80222A18[arg0];
    Arg2T arg2i = arg2;
    f32 f0;

    if (temp->unk2 == 1)
    {
        return;
    }

    f0 = ((f32) arg2i / 100.0 * temp->unk18);
    temp->unk20 = temp->unk18;
    temp->unkE = 0;
    if (arg1 == 0)
    {
        temp->unk18 = f0;
        return;
    }
    temp->unk1C = (f0 - temp->unk18) / arg1;
    temp->unk2 = 4;
    temp->unkE = arg1;
}

static void func_8031D7B0(s32 arg0, Arg1T arg1)
{
    struct Struct80222A18 *temp = &D_80222A18[arg0];

    if (temp->unk2 == 1)
    {
        return;
    }

    temp->unkE = 0;
    if (arg1 == 0)
    {
        temp->unk18 = temp->unk20;
        return;
    }
    temp->unk1C = (temp->unk20 - temp->unk18) / arg1;
    temp->unk2 = 2;
    temp->unkE = arg1;
}

static void func_8031D838(s32 arg0, Arg1T arg1, u8 arg2)
{
    struct Struct80222A18 *temp = &D_80222A18[arg0];
    Arg2T arg2i = arg2;

    if (temp->unk2 == 1)
    {
        return;
    }

    temp->unkE = 0;
    if (arg1 == 0)
    {
        temp->unk18 = ((f32) arg2i / 127.0);
        return;
    }
    temp->unk1C = (((f32) ((f32) arg2i / 127.0) - temp->unk18) / (f32) arg1);
    temp->unk2 = 4;
    temp->unkE = arg1;
}

#ifdef NON_MATCHING

struct SPTask *func_8031D924(void)
{
    s32 sp40;
    s32 sp3C;
    u32 t2;
    s32 v0;
    s32 old;
    UNUSED s32 dummy;
    s32 dataIndex;
    OSTask_t *task;

    D_80226D80++;
    if (D_80333EF4 != 0x76557364)
    {
        return 0;
    }

    D_80226D88 ^= 1;
    D_80226D8C++;
    D_80226D8C %= 3;
    sp3C = (D_80226D8C + 1) % 3;
    t2 = osAiGetLength() >> 2;
    if (D_80226E4C[sp3C] != 0)
    {
        osAiSetNextBuffer(D_80226E40[sp3C], D_80226E4C[sp3C] * 4);
    }

    // there is a pointless volatile load here, that loads into a temporary
    // register rather than a zero one...
    D_80226D84; D_80226D84 = 0;
    // dummy = D_80226D84; D_80226D84 = dummy & 0;
    // dummy = D_80226D84; D_80226D84 = dummy * 0;
    D_80226D9C = &D_80226DA0[D_80226D88];
    D_80226D98 = D_80226D90[D_80226D88];

    old = D_80226D8C;
    D_80360120 = D_80226E40[old];
    D_80226E4C[old] = (((D_80226D74 - t2) + 0x40) & 0xfff0) + 0x10;
    v0 = D_80226D74 + 0x10;
    if (D_80226E4C[old] < D_80226D78)
    {
        D_80226E4C[old] = D_80226D78;
    }
    if (D_80226E4C[old] > v0)
    {
        D_80226E4C[old] = v0;
    }

    if (D_80331D44 != 0)
    {
        func_8031EEF8();
        D_80331D44 = 0;
    }

    D_80226D98 = func_80313CD4(D_80226D98, &sp40, D_80360120, D_80226E4C[old]);
    D_80226EB8 = ((D_80226D80 + D_80226EB8) * D_80226D80);

    dataIndex = D_80226D88;
    D_80226D9C->msgqueue = NULL;
    D_80226D9C->msg = NULL;

    task = &D_80226D9C->task.t;
    task->type = M_AUDTASK;
    task->flags = 0;
    task->ucode_boot = rspF3DBootStart;
    task->ucode_boot_size = (u32) rspF3DBootEnd - (u32) rspF3DBootStart;
    task->ucode = rspF3DAudioStart;
    task->ucode_size = 0x800;
    task->ucode_data = rspF3DAudioDataStart;
    task->ucode_data_size = (rspF3DAudioDataEnd - rspF3DAudioDataStart) * sizeof(u64);
    task->dram_stack = NULL;
    task->dram_stack_size = 0;
    task->output_buff = NULL;
    task->output_buff_size = NULL;
    task->data_ptr = D_80226D90[dataIndex];
    task->data_size = sp40 * 8;
#ifdef VERSION_JP
    task->yield_data_ptr = gAudioSPTaskYieldBuffer;
    task->yield_data_size = 0x400;
#else
    task->yield_data_ptr = NULL;
    task->yield_data_size = 0;
#endif

    func_8031715C();
    return D_80226D9C;
}

#elif defined(VERSION_JP)
GLOBAL_ASM(
glabel func_8031D924
/* 0D8924 8031D924 3C048022 */  lui   $a0, %hi(D_80226D80) # $a0, 0x8022
/* 0D8928 8031D928 24846D80 */  addiu $a0, %lo(D_80226D80) # addiu $a0, $a0, 0x6d80
/* 0D892C 8031D92C 8C820000 */  lw    $v0, ($a0)
/* 0D8930 8031D930 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 0D8934 8031D934 3C0F8033 */  lui   $t7, %hi(D_80333EF4) # $t7, 0x8033
/* 0D8938 8031D938 244E0001 */  addiu $t6, $v0, 1
/* 0D893C 8031D93C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0D8940 8031D940 AC8E0000 */  sw    $t6, ($a0)
/* 0D8944 8031D944 25EF3EF4 */  addiu $t7, %lo(D_80333EF4) # addiu $t7, $t7, 0x3ef4
/* 0D8948 8031D948 8DF80000 */  lw    $t8, ($t7)
/* 0D894C 8031D94C 3C017655 */  lui   $at, (0x76557364 >> 16) # lui $at, 0x7655
/* 0D8950 8031D950 34217364 */  ori   $at, (0x76557364 & 0xFFFF) # ori $at, $at, 0x7364
/* 0D8954 8031D954 13010003 */  beq   $t8, $at, .L8031D964
/* 0D8958 8031D958 24020003 */   li    $v0, 3
/* 0D895C 8031D95C 100000C2 */  b     .L8031DC68
/* 0D8960 8031D960 00001025 */   move  $v0, $zero
.L8031D964:
/* 0D8964 8031D964 3C078022 */  lui   $a3, %hi(D_80226D8C) # $a3, 0x8022
/* 0D8968 8031D968 24E76D8C */  addiu $a3, %lo(D_80226D8C) # addiu $a3, $a3, 0x6d8c
/* 0D896C 8031D96C 8CED0000 */  lw    $t5, ($a3)
/* 0D8970 8031D970 3C038022 */  lui   $v1, %hi(D_80226D88) # $v1, 0x8022
/* 0D8974 8031D974 24636D88 */  addiu $v1, %lo(D_80226D88) # addiu $v1, $v1, 0x6d88
/* 0D8978 8031D978 25AE0001 */  addiu $t6, $t5, 1
/* 0D897C 8031D97C 01C2001A */  div   $zero, $t6, $v0
/* 0D8980 8031D980 8C790000 */  lw    $t9, ($v1)
/* 0D8984 8031D984 0000C010 */  mfhi  $t8
/* 0D8988 8031D988 01C07825 */  move  $t7, $t6
/* 0D898C 8031D98C 3B2C0001 */  xori  $t4, $t9, 1
/* 0D8990 8031D990 AC6C0000 */  sw    $t4, ($v1)
/* 0D8994 8031D994 270C0001 */  addiu $t4, $t8, 1
/* 0D8998 8031D998 0182001A */  div   $zero, $t4, $v0
/* 0D899C 8031D99C ACEE0000 */  sw    $t6, ($a3)
/* 0D89A0 8031D9A0 14400002 */  bnez  $v0, .L8031D9AC
/* 0D89A4 8031D9A4 00000000 */   nop   
/* 0D89A8 8031D9A8 0007000D */  break 7
.L8031D9AC:
/* 0D89AC 8031D9AC 2401FFFF */  li    $at, -1
/* 0D89B0 8031D9B0 14410004 */  bne   $v0, $at, .L8031D9C4
/* 0D89B4 8031D9B4 3C018000 */   lui   $at, 0x8000
/* 0D89B8 8031D9B8 15E10002 */  bne   $t7, $at, .L8031D9C4
/* 0D89BC 8031D9BC 00000000 */   nop   
/* 0D89C0 8031D9C0 0006000D */  break 6
.L8031D9C4:
/* 0D89C4 8031D9C4 00003010 */  mfhi  $a2
/* 0D89C8 8031D9C8 ACF80000 */  sw    $t8, ($a3)
/* 0D89CC 8031D9CC 0300C825 */  move  $t9, $t8
/* 0D89D0 8031D9D0 14400002 */  bnez  $v0, .L8031D9DC
/* 0D89D4 8031D9D4 00000000 */   nop   
/* 0D89D8 8031D9D8 0007000D */  break 7
.L8031D9DC:
/* 0D89DC 8031D9DC 2401FFFF */  li    $at, -1
/* 0D89E0 8031D9E0 14410004 */  bne   $v0, $at, .L8031D9F4
/* 0D89E4 8031D9E4 3C018000 */   lui   $at, 0x8000
/* 0D89E8 8031D9E8 15810002 */  bne   $t4, $at, .L8031D9F4
/* 0D89EC 8031D9EC 00000000 */   nop   
/* 0D89F0 8031D9F0 0006000D */  break 6
.L8031D9F4:
/* 0D89F4 8031D9F4 AFA6003C */  sw    $a2, 0x3c($sp)
/* 0D89F8 8031D9F8 0C0C939C */  jal   osAiGetLength
/* 0D89FC 8031D9FC 00000000 */   nop   
/* 0D8A00 8031DA00 8FA6003C */  lw    $a2, 0x3c($sp)
/* 0D8A04 8031DA04 3C038022 */  lui   $v1, %hi(D_80226E4C)
/* 0D8A08 8031DA08 3C078022 */  lui   $a3, %hi(D_80226D8C) # $a3, 0x8022
/* 0D8A0C 8031DA0C 00066840 */  sll   $t5, $a2, 1
/* 0D8A10 8031DA10 006D1821 */  addu  $v1, $v1, $t5
/* 0D8A14 8031DA14 84636E4C */  lh    $v1, %lo(D_80226E4C)($v1)
/* 0D8A18 8031DA18 24E76D8C */  addiu $a3, %lo(D_80226D8C) # addiu $a3, $a3, 0x6d8c
/* 0D8A1C 8031DA1C 00025082 */  srl   $t2, $v0, 2
/* 0D8A20 8031DA20 1060000A */  beqz  $v1, .L8031DA4C
/* 0D8A24 8031DA24 00067080 */   sll   $t6, $a2, 2
/* 0D8A28 8031DA28 3C048022 */  lui   $a0, %hi(D_80226E40)
/* 0D8A2C 8031DA2C 008E2021 */  addu  $a0, $a0, $t6
/* 0D8A30 8031DA30 8C846E40 */  lw    $a0, %lo(D_80226E40)($a0)
/* 0D8A34 8031DA34 00032880 */  sll   $a1, $v1, 2
/* 0D8A38 8031DA38 0C0C93A0 */  jal   osAiSetNextBuffer
/* 0D8A3C 8031DA3C AFAA0044 */   sw    $t2, 0x44($sp)
/* 0D8A40 8031DA40 3C078022 */  lui   $a3, %hi(D_80226D8C) # $a3, 0x8022
/* 0D8A44 8031DA44 24E76D8C */  addiu $a3, %lo(D_80226D8C) # addiu $a3, $a3, 0x6d8c
/* 0D8A48 8031DA48 8FAA0044 */  lw    $t2, 0x44($sp)
.L8031DA4C:
/* 0D8A4C 8031DA4C 3C0B8022 */  lui   $t3, %hi(D_80226D84) # $t3, 0x8022
/* 0D8A50 8031DA50 256B6D84 */  addiu $t3, %lo(D_80226D84) # addiu $t3, $t3, 0x6d84
/* 0D8A54 8031DA54 8D620000 */  lw    $v0, ($t3)
/* 0D8A58 8031DA58 AD600000 */  sw    $zero, ($t3)
/* 0D8A5C 8031DA5C 3C028022 */  lui   $v0, %hi(D_80226D88) # $v0, 0x8022
/* 0D8A60 8031DA60 8C426D88 */  lw    $v0, %lo(D_80226D88)($v0)
/* 0D8A64 8031DA64 3C188022 */  lui   $t8, %hi(D_80226DA0) # $t8, 0x8022
/* 0D8A68 8031DA68 3C098022 */  lui   $t1, %hi(D_80226D9C) # $t1, 0x8022
/* 0D8A6C 8031DA6C 00027880 */  sll   $t7, $v0, 2
/* 0D8A70 8031DA70 01E27821 */  addu  $t7, $t7, $v0
/* 0D8A74 8031DA74 000F7900 */  sll   $t7, $t7, 4
/* 0D8A78 8031DA78 27186DA0 */  addiu $t8, %lo(D_80226DA0) # addiu $t8, $t8, 0x6da0
/* 0D8A7C 8031DA7C 25296D9C */  addiu $t1, %lo(D_80226D9C) # addiu $t1, $t1, 0x6d9c
/* 0D8A80 8031DA80 01F8C821 */  addu  $t9, $t7, $t8
/* 0D8A84 8031DA84 3C0D8022 */  lui   $t5, %hi(D_80226D90)
/* 0D8A88 8031DA88 00026080 */  sll   $t4, $v0, 2
/* 0D8A8C 8031DA8C AD390000 */  sw    $t9, ($t1)
/* 0D8A90 8031DA90 01AC6821 */  addu  $t5, $t5, $t4
/* 0D8A94 8031DA94 8DAD6D90 */  lw    $t5, %lo(D_80226D90)($t5)
/* 0D8A98 8031DA98 3C018022 */  lui   $at, %hi(D_80226D98) # $at, 0x8022
/* 0D8A9C 8031DA9C 3C048022 */  lui   $a0, %hi(D_80226D74) # $a0, 0x8022
/* 0D8AA0 8031DAA0 AC2D6D98 */  sw    $t5, %lo(D_80226D98)($at)
/* 0D8AA4 8031DAA4 8CE60000 */  lw    $a2, ($a3)
/* 0D8AA8 8031DAA8 8C846D74 */  lw    $a0, %lo(D_80226D74)($a0)
/* 0D8AAC 8031DAAC 3C0F8022 */  lui   $t7, %hi(D_80226E40)
/* 0D8AB0 8031DAB0 00067080 */  sll   $t6, $a2, 2
/* 0D8AB4 8031DAB4 01EE7821 */  addu  $t7, $t7, $t6
/* 0D8AB8 8031DAB8 8DEF6E40 */  lw    $t7, %lo(D_80226E40)($t7)
/* 0D8ABC 8031DABC 008A6023 */  subu  $t4, $a0, $t2
/* 0D8AC0 8031DAC0 3C018036 */  lui   $at, %hi(D_80360120) # $at, 0x8036
/* 0D8AC4 8031DAC4 258D0040 */  addiu $t5, $t4, 0x40
/* 0D8AC8 8031DAC8 3C198022 */  lui   $t9, %hi(D_80226E4C) # $t9, 0x8022
/* 0D8ACC 8031DACC 27396E4C */  addiu $t9, %lo(D_80226E4C) # addiu $t9, $t9, 0x6e4c
/* 0D8AD0 8031DAD0 31AEFFF0 */  andi  $t6, $t5, 0xfff0
/* 0D8AD4 8031DAD4 0006C040 */  sll   $t8, $a2, 1
/* 0D8AD8 8031DAD8 AC2F0120 */  sw    $t7, %lo(D_80360120)($at)
/* 0D8ADC 8031DADC 25CF0010 */  addiu $t7, $t6, 0x10
/* 0D8AE0 8031DAE0 03194021 */  addu  $t0, $t8, $t9
/* 0D8AE4 8031DAE4 A50F0000 */  sh    $t7, ($t0)
/* 0D8AE8 8031DAE8 3C058022 */  lui   $a1, %hi(D_80226D78) # $a1, 0x8022
/* 0D8AEC 8031DAEC 8CA56D78 */  lw    $a1, %lo(D_80226D78)($a1)
/* 0D8AF0 8031DAF0 85030000 */  lh    $v1, ($t0)
/* 0D8AF4 8031DAF4 3C188033 */  lui   $t8, %hi(D_80331D44) # $t8, 0x8033
/* 0D8AF8 8031DAF8 24820010 */  addiu $v0, $a0, 0x10
/* 0D8AFC 8031DAFC 0065082A */  slt   $at, $v1, $a1
/* 0D8B00 8031DB00 50200004 */  beql  $at, $zero, .L8031DB14
/* 0D8B04 8031DB04 0043082A */   slt   $at, $v0, $v1
/* 0D8B08 8031DB08 A5050000 */  sh    $a1, ($t0)
/* 0D8B0C 8031DB0C 85030000 */  lh    $v1, ($t0)
/* 0D8B10 8031DB10 0043082A */  slt   $at, $v0, $v1
.L8031DB14:
/* 0D8B14 8031DB14 10200002 */  beqz  $at, .L8031DB20
/* 0D8B18 8031DB18 00000000 */   nop   
/* 0D8B1C 8031DB1C A5020000 */  sh    $v0, ($t0)
.L8031DB20:
/* 0D8B20 8031DB20 8F181D44 */  lw    $t8, %lo(D_80331D44)($t8)
/* 0D8B24 8031DB24 13000006 */  beqz  $t8, .L8031DB40
/* 0D8B28 8031DB28 00000000 */   nop   
/* 0D8B2C 8031DB2C 0C0C7BBE */  jal   func_8031EEF8
/* 0D8B30 8031DB30 AFA80028 */   sw    $t0, 0x28($sp)
/* 0D8B34 8031DB34 3C018033 */  lui   $at, %hi(D_80331D44) # $at, 0x8033
/* 0D8B38 8031DB38 8FA80028 */  lw    $t0, 0x28($sp)
/* 0D8B3C 8031DB3C AC201D44 */  sw    $zero, %lo(D_80331D44)($at)
.L8031DB40:
/* 0D8B40 8031DB40 3C048022 */  lui   $a0, %hi(D_80226D98) # $a0, 0x8022
/* 0D8B44 8031DB44 3C068036 */  lui   $a2, %hi(D_80360120) # $a2, 0x8036
/* 0D8B48 8031DB48 8CC60120 */  lw    $a2, %lo(D_80360120)($a2)
/* 0D8B4C 8031DB4C 8C846D98 */  lw    $a0, %lo(D_80226D98)($a0)
/* 0D8B50 8031DB50 27A50040 */  addiu $a1, $sp, 0x40
/* 0D8B54 8031DB54 0C0C4F35 */  jal   func_80313CD4
/* 0D8B58 8031DB58 85070000 */   lh    $a3, ($t0)
/* 0D8B5C 8031DB5C 3C088022 */  lui   $t0, %hi(D_80226D80) # $t0, 0x8022
/* 0D8B60 8031DB60 3C018022 */  lui   $at, %hi(D_80226D98) # $at, 0x8022
/* 0D8B64 8031DB64 AC226D98 */  sw    $v0, %lo(D_80226D98)($at)
/* 0D8B68 8031DB68 25086D80 */  addiu $t0, %lo(D_80226D80) # addiu $t0, $t0, 0x6d80
/* 0D8B6C 8031DB6C 3C048022 */  lui   $a0, %hi(D_80226EB8) # $a0, 0x8022
/* 0D8B70 8031DB70 8D190000 */  lw    $t9, ($t0)
/* 0D8B74 8031DB74 24846EB8 */  addiu $a0, %lo(D_80226EB8) # addiu $a0, $a0, 0x6eb8
/* 0D8B78 8031DB78 8C8C0000 */  lw    $t4, ($a0)
/* 0D8B7C 8031DB7C 8D0E0000 */  lw    $t6, ($t0)
/* 0D8B80 8031DB80 3C098022 */  lui   $t1, %hi(D_80226D9C) # $t1, 0x8022
/* 0D8B84 8031DB84 032C6821 */  addu  $t5, $t9, $t4
/* 0D8B88 8031DB88 01AE0019 */  multu $t5, $t6
/* 0D8B8C 8031DB8C 25296D9C */  addiu $t1, %lo(D_80226D9C) # addiu $t1, $t1, 0x6d9c
/* 0D8B90 8031DB90 8D380000 */  lw    $t8, ($t1)
/* 0D8B94 8031DB94 3C068022 */  lui   $a2, %hi(D_80226D88) # $a2, 0x8022
/* 0D8B98 8031DB98 3C058033 */  lui   $a1, %hi(rspF3DBootStart) # $a1, 0x8033
/* 0D8B9C 8031DB9C 3C0D8033 */  lui   $t5, %hi(rspF3DBootEnd) # $t5, 0x8033
/* 0D8BA0 8031DBA0 24A5A320 */  addiu $a1, %lo(rspF3DBootStart) # addiu $a1, $a1, -0x5ce0
/* 0D8BA4 8031DBA4 3C078034 */  lui   $a3, %hi(rspF3DAudioDataStart) # $a3, 0x8034
/* 0D8BA8 8031DBA8 240C0002 */  li    $t4, 2
/* 0D8BAC 8031DBAC 25ADA3F0 */  addiu $t5, %lo(rspF3DBootEnd) # addiu $t5, $t5, -0x5c10
/* 0D8BB0 8031DBB0 00007812 */  mflo  $t7
/* 0D8BB4 8031DBB4 AC8F0000 */  sw    $t7, ($a0)
/* 0D8BB8 8031DBB8 8CC66D88 */  lw    $a2, %lo(D_80226D88)($a2)
/* 0D8BBC 8031DBBC AF000040 */  sw    $zero, 0x40($t8)
/* 0D8BC0 8031DBC0 8D390000 */  lw    $t9, ($t1)
/* 0D8BC4 8031DBC4 24E78F50 */  addiu $a3, %lo(rspF3DAudioDataStart) # addiu $a3, $a3, -0x70b0
/* 0D8BC8 8031DBC8 01A57023 */  subu  $t6, $t5, $a1
/* 0D8BCC 8031DBCC AF200044 */  sw    $zero, 0x44($t9)
/* 0D8BD0 8031DBD0 8D230000 */  lw    $v1, ($t1)
/* 0D8BD4 8031DBD4 3C198034 */  lui   $t9, %hi(rspF3DAudioDataEnd) # $t9, 0x8034
/* 0D8BD8 8031DBD8 3C0F8033 */  lui   $t7, %hi(rspF3DAudioStart) # $t7, 0x8033
/* 0D8BDC 8031DBDC 27399210 */  addiu $t9, %lo(rspF3DAudioDataEnd) # addiu $t9, $t9, -0x6df0
/* 0D8BE0 8031DBE0 AC6C0000 */  sw    $t4, ($v1)
/* 0D8BE4 8031DBE4 25EFB800 */  addiu $t7, %lo(rspF3DAudioStart) # addiu $t7, $t7, -0x4800
/* 0D8BE8 8031DBE8 24180800 */  li    $t8, 2048
/* 0D8BEC 8031DBEC 03276023 */  subu  $t4, $t9, $a3
/* 0D8BF0 8031DBF0 000C68C3 */  sra   $t5, $t4, 3
/* 0D8BF4 8031DBF4 AC6E000C */  sw    $t6, 0xc($v1)
/* 0D8BF8 8031DBF8 AC6F0010 */  sw    $t7, 0x10($v1)
/* 0D8BFC 8031DBFC AC780014 */  sw    $t8, 0x14($v1)
/* 0D8C00 8031DC00 000D70C0 */  sll   $t6, $t5, 3
/* 0D8C04 8031DC04 3C188022 */  lui   $t8, %hi(D_80226D90)
/* 0D8C08 8031DC08 00067880 */  sll   $t7, $a2, 2
/* 0D8C0C 8031DC0C 030FC021 */  addu  $t8, $t8, $t7
/* 0D8C10 8031DC10 AC600004 */  sw    $zero, 4($v1)
/* 0D8C14 8031DC14 AC650008 */  sw    $a1, 8($v1)
/* 0D8C18 8031DC18 AC670018 */  sw    $a3, 0x18($v1)
/* 0D8C1C 8031DC1C AC6E001C */  sw    $t6, 0x1c($v1)
/* 0D8C20 8031DC20 AC600020 */  sw    $zero, 0x20($v1)
/* 0D8C24 8031DC24 AC600024 */  sw    $zero, 0x24($v1)
/* 0D8C28 8031DC28 AC600028 */  sw    $zero, 0x28($v1)
/* 0D8C2C 8031DC2C AC60002C */  sw    $zero, 0x2c($v1)
/* 0D8C30 8031DC30 8F186D90 */  lw    $t8, %lo(D_80226D90)($t8)
/* 0D8C34 8031DC34 3C0D8020 */  lui   $t5, %hi(gAudioSPTaskYieldBuffer) # $t5, 0x8020
/* 0D8C38 8031DC38 25ADF200 */  addiu $t5, %lo(gAudioSPTaskYieldBuffer) # addiu $t5, $t5, -0xe00
/* 0D8C3C 8031DC3C AC780030 */  sw    $t8, 0x30($v1)
/* 0D8C40 8031DC40 8FB90040 */  lw    $t9, 0x40($sp)
/* 0D8C44 8031DC44 240E0400 */  li    $t6, 1024
/* 0D8C48 8031DC48 AC6D0038 */  sw    $t5, 0x38($v1)
/* 0D8C4C 8031DC4C 001960C0 */  sll   $t4, $t9, 3
/* 0D8C50 8031DC50 AC6C0034 */  sw    $t4, 0x34($v1)
/* 0D8C54 8031DC54 0C0C5C57 */  jal   func_8031715C
/* 0D8C58 8031DC58 AC6E003C */   sw    $t6, 0x3c($v1)
/* 0D8C5C 8031DC5C 3C098022 */  lui   $t1, %hi(D_80226D9C) # $t1, 0x8022
/* 0D8C60 8031DC60 25296D9C */  addiu $t1, %lo(D_80226D9C) # addiu $t1, $t1, 0x6d9c
/* 0D8C64 8031DC64 8D220000 */  lw    $v0, ($t1)
.L8031DC68:
/* 0D8C68 8031DC68 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0D8C6C 8031DC6C 27BD0048 */  addiu $sp, $sp, 0x48
/* 0D8C70 8031DC70 03E00008 */  jr    $ra
/* 0D8C74 8031DC74 00000000 */   nop   
)
#else
GLOBAL_ASM(
glabel func_8031D924
/* 0D97B8 8031E7B8 3C048022 */  lui   $a0, %hi(D_80226D80) # $a0, 0x8022
/* 0D97BC 8031E7BC 24846B80 */  addiu $a0, %lo(D_80226D80) # addiu $a0, $a0, 0x6b80
/* 0D97C0 8031E7C0 8C820000 */  lw    $v0, ($a0)
/* 0D97C4 8031E7C4 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 0D97C8 8031E7C8 3C0F8033 */  lui   $t7, %hi(D_80333EF4) # $t7, 0x8033
/* 0D97CC 8031E7CC 244E0001 */  addiu $t6, $v0, 1
/* 0D97D0 8031E7D0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0D97D4 8031E7D4 AC8E0000 */  sw    $t6, ($a0)
/* 0D97D8 8031E7D8 25EF5004 */  addiu $t7, %lo(D_80333EF4) # addiu $t7, $t7, 0x5004
/* 0D97DC 8031E7DC 8DF80000 */  lw    $t8, ($t7)
/* 0D97E0 8031E7E0 3C017655 */  lui   $at, (0x76557364 >> 16) # lui $at, 0x7655
/* 0D97E4 8031E7E4 34217364 */  ori   $at, (0x76557364 & 0xFFFF) # ori $at, $at, 0x7364
/* 0D97E8 8031E7E8 13010003 */  beq   $t8, $at, .L_U_8031E7F8
/* 0D97EC 8031E7EC 24020003 */   li    $v0, 3
/* 0D97F0 8031E7F0 100000BF */  b     .L_U_8031EAF0
/* 0D97F4 8031E7F4 00001025 */   move  $v0, $zero
.L_U_8031E7F8:
/* 0D97F8 8031E7F8 3C078022 */  lui   $a3, %hi(D_80226D8C) # $a3, 0x8022
/* 0D97FC 8031E7FC 24E76B8C */  addiu $a3, %lo(D_80226D8C) # addiu $a3, $a3, 0x6b8c
/* 0D9800 8031E800 8CED0000 */  lw    $t5, ($a3)
/* 0D9804 8031E804 3C038022 */  lui   $v1, %hi(D_80226D88) # $v1, 0x8022
/* 0D9808 8031E808 24636B88 */  addiu $v1, %lo(D_80226D88) # addiu $v1, $v1, 0x6b88
/* 0D980C 8031E80C 25AE0001 */  addiu $t6, $t5, 1
/* 0D9810 8031E810 01C2001A */  div   $zero, $t6, $v0
/* 0D9814 8031E814 8C790000 */  lw    $t9, ($v1)
/* 0D9818 8031E818 0000C010 */  mfhi  $t8
/* 0D981C 8031E81C 01C07825 */  move  $t7, $t6
/* 0D9820 8031E820 3B2C0001 */  xori  $t4, $t9, 1
/* 0D9824 8031E824 AC6C0000 */  sw    $t4, ($v1)
/* 0D9828 8031E828 270C0001 */  addiu $t4, $t8, 1
/* 0D982C 8031E82C 0182001A */  div   $zero, $t4, $v0
/* 0D9830 8031E830 ACEE0000 */  sw    $t6, ($a3)
/* 0D9834 8031E834 14400002 */  bnez  $v0, .L_U_8031E840
/* 0D9838 8031E838 00000000 */   nop   
/* 0D983C 8031E83C 0007000D */  break 7
.L_U_8031E840:
/* 0D9840 8031E840 2401FFFF */  li    $at, -1
/* 0D9844 8031E844 14410004 */  bne   $v0, $at, .L_U_8031E858
/* 0D9848 8031E848 3C018000 */   lui   $at, 0x8000
/* 0D984C 8031E84C 15E10002 */  bne   $t7, $at, .L_U_8031E858
/* 0D9850 8031E850 00000000 */   nop   
/* 0D9854 8031E854 0006000D */  break 6
.L_U_8031E858:
/* 0D9858 8031E858 00003010 */  mfhi  $a2
/* 0D985C 8031E85C ACF80000 */  sw    $t8, ($a3)
/* 0D9860 8031E860 0300C825 */  move  $t9, $t8
/* 0D9864 8031E864 14400002 */  bnez  $v0, .L_U_8031E870
/* 0D9868 8031E868 00000000 */   nop   
/* 0D986C 8031E86C 0007000D */  break 7
.L_U_8031E870:
/* 0D9870 8031E870 2401FFFF */  li    $at, -1
/* 0D9874 8031E874 14410004 */  bne   $v0, $at, .L_U_8031E888
/* 0D9878 8031E878 3C018000 */   lui   $at, 0x8000
/* 0D987C 8031E87C 15810002 */  bne   $t4, $at, .L_U_8031E888
/* 0D9880 8031E880 00000000 */   nop   
/* 0D9884 8031E884 0006000D */  break 6
.L_U_8031E888:
/* 0D9888 8031E888 AFA6003C */  sw    $a2, 0x3c($sp)
/* 0D988C 8031E88C 0C0C9768 */  jal   osAiGetLength
/* 0D9890 8031E890 00000000 */   nop   
/* 0D9894 8031E894 8FA6003C */  lw    $a2, 0x3c($sp)
/* 0D9898 8031E898 3C038022 */  lui   $v1, %hi(D_80226E4C)
/* 0D989C 8031E89C 3C078022 */  lui   $a3, %hi(D_80226D8C) # $a3, 0x8022
/* 0D98A0 8031E8A0 00066840 */  sll   $t5, $a2, 1
/* 0D98A4 8031E8A4 006D1821 */  addu  $v1, $v1, $t5
/* 0D98A8 8031E8A8 84636C4C */  lh    $v1, %lo(D_80226E4C)($v1)
/* 0D98AC 8031E8AC 24E76B8C */  addiu $a3, %lo(D_80226D8C) # addiu $a3, $a3, 0x6b8c
/* 0D98B0 8031E8B0 00025082 */  srl   $t2, $v0, 2
/* 0D98B4 8031E8B4 1060000A */  beqz  $v1, .L_U_8031E8E0
/* 0D98B8 8031E8B8 00067080 */   sll   $t6, $a2, 2
/* 0D98BC 8031E8BC 3C048022 */  lui   $a0, %hi(D_80226E40)
/* 0D98C0 8031E8C0 008E2021 */  addu  $a0, $a0, $t6
/* 0D98C4 8031E8C4 8C846C40 */  lw    $a0, %lo(D_80226E40)($a0)
/* 0D98C8 8031E8C8 00032880 */  sll   $a1, $v1, 2
/* 0D98CC 8031E8CC 0C0C976C */  jal   osAiSetNextBuffer
/* 0D98D0 8031E8D0 AFAA0044 */   sw    $t2, 0x44($sp)
/* 0D98D4 8031E8D4 3C078022 */  lui   $a3, %hi(D_80226D8C) # $a3, 0x8022
/* 0D98D8 8031E8D8 24E76B8C */  addiu $a3, %lo(D_80226D8C) # addiu $a3, $a3, 0x6b8c
/* 0D98DC 8031E8DC 8FAA0044 */  lw    $t2, 0x44($sp)
.L_U_8031E8E0:
/* 0D98E0 8031E8E0 3C0B8022 */  lui   $t3, %hi(D_80226D84) # $t3, 0x8022
/* 0D98E4 8031E8E4 256B6B84 */  addiu $t3, %lo(D_80226D84) # addiu $t3, $t3, 0x6b84
/* 0D98E8 8031E8E8 8D620000 */  lw    $v0, ($t3)
/* 0D98EC 8031E8EC AD600000 */  sw    $zero, ($t3)
/* 0D98F0 8031E8F0 3C028022 */  lui   $v0, %hi(D_80226D88) # $v0, 0x8022
/* 0D98F4 8031E8F4 8C426B88 */  lw    $v0, %lo(D_80226D88)($v0)
/* 0D98F8 8031E8F8 3C188022 */  lui   $t8, %hi(D_80226DA0) # $t8, 0x8022
/* 0D98FC 8031E8FC 3C098022 */  lui   $t1, %hi(D_80226D9C) # $t1, 0x8022
/* 0D9900 8031E900 00027880 */  sll   $t7, $v0, 2
/* 0D9904 8031E904 01E27821 */  addu  $t7, $t7, $v0
/* 0D9908 8031E908 000F7900 */  sll   $t7, $t7, 4
/* 0D990C 8031E90C 27186BA0 */  addiu $t8, %lo(D_80226DA0) # addiu $t8, $t8, 0x6ba0
/* 0D9910 8031E910 25296B9C */  addiu $t1, %lo(D_80226D9C) # addiu $t1, $t1, 0x6b9c
/* 0D9914 8031E914 01F8C821 */  addu  $t9, $t7, $t8
/* 0D9918 8031E918 3C0D8022 */  lui   $t5, %hi(D_80226D90)
/* 0D991C 8031E91C 00026080 */  sll   $t4, $v0, 2
/* 0D9920 8031E920 AD390000 */  sw    $t9, ($t1)
/* 0D9924 8031E924 01AC6821 */  addu  $t5, $t5, $t4
/* 0D9928 8031E928 8DAD6B90 */  lw    $t5, %lo(D_80226D90)($t5)
/* 0D992C 8031E92C 3C018022 */  lui   $at, %hi(D_80226D98) # $at, 0x8022
/* 0D9930 8031E930 3C048022 */  lui   $a0, %hi(D_80226D74) # $a0, 0x8022
/* 0D9934 8031E934 AC2D6B98 */  sw    $t5, %lo(D_80226D98)($at)
/* 0D9938 8031E938 8CE60000 */  lw    $a2, ($a3)
/* 0D993C 8031E93C 8C846B74 */  lw    $a0, %lo(D_80226D74)($a0)
/* 0D9940 8031E940 3C0F8022 */  lui   $t7, %hi(D_80226E40)
/* 0D9944 8031E944 00067080 */  sll   $t6, $a2, 2
/* 0D9948 8031E948 01EE7821 */  addu  $t7, $t7, $t6
/* 0D994C 8031E94C 8DEF6C40 */  lw    $t7, %lo(D_80226E40)($t7)
/* 0D9950 8031E950 008A6023 */  subu  $t4, $a0, $t2
/* 0D9954 8031E954 3C018036 */  lui   $at, %hi(D_80360120) # $at, 0x8036
/* 0D9958 8031E958 258D0040 */  addiu $t5, $t4, 0x40
/* 0D995C 8031E95C 3C198022 */  lui   $t9, %hi(D_80226E4C) # $t9, 0x8022
/* 0D9960 8031E960 27396C4C */  addiu $t9, %lo(D_80226E4C) # addiu $t9, $t9, 0x6c4c
/* 0D9964 8031E964 31AEFFF0 */  andi  $t6, $t5, 0xfff0
/* 0D9968 8031E968 0006C040 */  sll   $t8, $a2, 1
/* 0D996C 8031E96C AC2F1490 */  sw    $t7, %lo(D_80360120)($at)
/* 0D9970 8031E970 25CF0010 */  addiu $t7, $t6, 0x10
/* 0D9974 8031E974 03194021 */  addu  $t0, $t8, $t9
/* 0D9978 8031E978 A50F0000 */  sh    $t7, ($t0)
/* 0D997C 8031E97C 3C058022 */  lui   $a1, %hi(D_80226D78) # $a1, 0x8022
/* 0D9980 8031E980 8CA56B78 */  lw    $a1, %lo(D_80226D78)($a1)
/* 0D9984 8031E984 85030000 */  lh    $v1, ($t0)
/* 0D9988 8031E988 3C188033 */  lui   $t8, %hi(D_80331D44) # $t8, 0x8033
/* 0D998C 8031E98C 24820010 */  addiu $v0, $a0, 0x10
/* 0D9990 8031E990 0065082A */  slt   $at, $v1, $a1
/* 0D9994 8031E994 50200004 */  beql  $at, $zero, .L_U_8031E9A8
/* 0D9998 8031E998 0043082A */   slt   $at, $v0, $v1
/* 0D999C 8031E99C A5050000 */  sh    $a1, ($t0)
/* 0D99A0 8031E9A0 85030000 */  lh    $v1, ($t0)
/* 0D99A4 8031E9A4 0043082A */  slt   $at, $v0, $v1
.L_U_8031E9A8:
/* 0D99A8 8031E9A8 10200002 */  beqz  $at, .L_U_8031E9B4
/* 0D99AC 8031E9AC 00000000 */   nop   
/* 0D99B0 8031E9B0 A5020000 */  sh    $v0, ($t0)
.L_U_8031E9B4:
/* 0D99B4 8031E9B4 8F182E54 */  lw    $t8, %lo(D_80331D44)($t8)
/* 0D99B8 8031E9B8 13000006 */  beqz  $t8, .L_U_8031E9D4
/* 0D99BC 8031E9BC 00000000 */   nop   
/* 0D99C0 8031E9C0 0C0C7F6B */  jal   func_8031EEF8
/* 0D99C4 8031E9C4 AFA80028 */   sw    $t0, 0x28($sp)
/* 0D99C8 8031E9C8 3C018033 */  lui   $at, %hi(D_80331D44) # $at, 0x8033
/* 0D99CC 8031E9CC 8FA80028 */  lw    $t0, 0x28($sp)
/* 0D99D0 8031E9D0 AC202E54 */  sw    $zero, %lo(D_80331D44)($at)
.L_U_8031E9D4:
/* 0D99D4 8031E9D4 3C048022 */  lui   $a0, %hi(D_80226D98) # $a0, 0x8022
/* 0D99D8 8031E9D8 3C068036 */  lui   $a2, %hi(D_80360120) # $a2, 0x8036
/* 0D99DC 8031E9DC 8CC61490 */  lw    $a2, %lo(D_80360120)($a2)
/* 0D99E0 8031E9E0 8C846B98 */  lw    $a0, %lo(D_80226D98)($a0)
/* 0D99E4 8031E9E4 27A50040 */  addiu $a1, $sp, 0x40
/* 0D99E8 8031E9E8 0C0C5379 */  jal   func_80313CD4
/* 0D99EC 8031E9EC 85070000 */   lh    $a3, ($t0)
/* 0D99F0 8031E9F0 3C088022 */  lui   $t0, %hi(D_80226D80) # $t0, 0x8022
/* 0D99F4 8031E9F4 3C018022 */  lui   $at, %hi(D_80226D98) # $at, 0x8022
/* 0D99F8 8031E9F8 AC226B98 */  sw    $v0, %lo(D_80226D98)($at)
/* 0D99FC 8031E9FC 25086B80 */  addiu $t0, %lo(D_80226D80) # addiu $t0, $t0, 0x6b80
/* 0D9A00 8031EA00 3C048022 */  lui   $a0, %hi(D_80226EB8) # $a0, 0x8022
/* 0D9A04 8031EA04 8D190000 */  lw    $t9, ($t0)
/* 0D9A08 8031EA08 24846CB8 */  addiu $a0, %lo(D_80226EB8) # addiu $a0, $a0, 0x6cb8
/* 0D9A0C 8031EA0C 8C8C0000 */  lw    $t4, ($a0)
/* 0D9A10 8031EA10 8D0E0000 */  lw    $t6, ($t0)
/* 0D9A14 8031EA14 3C098022 */  lui   $t1, %hi(D_80226D9C) # $t1, 0x8022
/* 0D9A18 8031EA18 032C6821 */  addu  $t5, $t9, $t4
/* 0D9A1C 8031EA1C 01AE0019 */  multu $t5, $t6
/* 0D9A20 8031EA20 25296B9C */  addiu $t1, %lo(D_80226D9C) # addiu $t1, $t1, 0x6b9c
/* 0D9A24 8031EA24 8D380000 */  lw    $t8, ($t1)
/* 0D9A28 8031EA28 3C068022 */  lui   $a2, %hi(D_80226D88) # $a2, 0x8022
/* 0D9A2C 8031EA2C 3C058033 */  lui   $a1, %hi(rspF3DBootStart) # $a1, 0x8033
/* 0D9A30 8031EA30 3C0D8033 */  lui   $t5, %hi(rspF3DBootEnd) # $t5, 0x8033
/* 0D9A34 8031EA34 24A5B260 */  addiu $a1, %lo(rspF3DBootStart) # addiu $a1, $a1, -0x4da0
/* 0D9A38 8031EA38 3C078034 */  lui   $a3, %hi(rspF3DAudioDataStart) # $a3, 0x8034
/* 0D9A3C 8031EA3C 240C0002 */  li    $t4, 2
/* 0D9A40 8031EA40 25ADB330 */  addiu $t5, %lo(rspF3DBootEnd) # addiu $t5, $t5, -0x4cd0
/* 0D9A44 8031EA44 00007812 */  mflo  $t7
/* 0D9A48 8031EA48 AC8F0000 */  sw    $t7, ($a0)
/* 0D9A4C 8031EA4C 8CC66B88 */  lw    $a2, %lo(D_80226D88)($a2)
/* 0D9A50 8031EA50 AF000040 */  sw    $zero, 0x40($t8)
/* 0D9A54 8031EA54 8D390000 */  lw    $t9, ($t1)
/* 0D9A58 8031EA58 24E7A2C0 */  addiu $a3, %lo(rspF3DAudioDataStart) # addiu $a3, $a3, -0x5d40
/* 0D9A5C 8031EA5C 01A57023 */  subu  $t6, $t5, $a1
/* 0D9A60 8031EA60 AF200044 */  sw    $zero, 0x44($t9)
/* 0D9A64 8031EA64 8D230000 */  lw    $v1, ($t1)
/* 0D9A68 8031EA68 3C198034 */  lui   $t9, %hi(rspF3DAudioDataEnd) # $t9, 0x8034
/* 0D9A6C 8031EA6C 3C0F8033 */  lui   $t7, %hi(rspF3DAudioStart) # $t7, 0x8033
/* 0D9A70 8031EA70 2739A580 */  addiu $t9, %lo(rspF3DAudioDataEnd) # addiu $t9, $t9, -0x5a80
/* 0D9A74 8031EA74 AC6C0000 */  sw    $t4, ($v1)
/* 0D9A78 8031EA78 25EFC740 */  addiu $t7, %lo(rspF3DAudioStart) # addiu $t7, $t7, -0x38c0
/* 0D9A7C 8031EA7C 24180800 */  li    $t8, 2048
/* 0D9A80 8031EA80 03276023 */  subu  $t4, $t9, $a3
/* 0D9A84 8031EA84 000C68C3 */  sra   $t5, $t4, 3
/* 0D9A88 8031EA88 AC6E000C */  sw    $t6, 0xc($v1)
/* 0D9A8C 8031EA8C AC6F0010 */  sw    $t7, 0x10($v1)
/* 0D9A90 8031EA90 AC780014 */  sw    $t8, 0x14($v1)
/* 0D9A94 8031EA94 000D70C0 */  sll   $t6, $t5, 3
/* 0D9A98 8031EA98 3C188022 */  lui   $t8, %hi(D_80226D90)
/* 0D9A9C 8031EA9C 00067880 */  sll   $t7, $a2, 2
/* 0D9AA0 8031EAA0 030FC021 */  addu  $t8, $t8, $t7
/* 0D9AA4 8031EAA4 AC600004 */  sw    $zero, 4($v1)
/* 0D9AA8 8031EAA8 AC650008 */  sw    $a1, 8($v1)
/* 0D9AAC 8031EAAC AC670018 */  sw    $a3, 0x18($v1)
/* 0D9AB0 8031EAB0 AC6E001C */  sw    $t6, 0x1c($v1)
/* 0D9AB4 8031EAB4 AC600020 */  sw    $zero, 0x20($v1)
/* 0D9AB8 8031EAB8 AC600024 */  sw    $zero, 0x24($v1)
/* 0D9ABC 8031EABC AC600028 */  sw    $zero, 0x28($v1)
/* 0D9AC0 8031EAC0 AC60002C */  sw    $zero, 0x2c($v1)
/* 0D9AC4 8031EAC4 8F186B90 */  lw    $t8, %lo(D_80226D90)($t8)
/* 0D9AC8 8031EAC8 AC780030 */  sw    $t8, 0x30($v1)
/* 0D9ACC 8031EACC 8FB90040 */  lw    $t9, 0x40($sp)
/* 0D9AD0 8031EAD0 AC600038 */  sw    $zero, 0x38($v1)
/* 0D9AD4 8031EAD4 AC60003C */  sw    $zero, 0x3c($v1)
/* 0D9AD8 8031EAD8 001960C0 */  sll   $t4, $t9, 3
/* 0D9ADC 8031EADC 0C0C607B */  jal   func_8031715C
/* 0D9AE0 8031EAE0 AC6C0034 */   sw    $t4, 0x34($v1)
/* 0D9AE4 8031EAE4 3C098022 */  lui   $t1, %hi(D_80226D9C) # $t1, 0x8022
/* 0D9AE8 8031EAE8 25296B9C */  addiu $t1, %lo(D_80226D9C) # addiu $t1, $t1, 0x6b9c
/* 0D9AEC 8031EAEC 8D220000 */  lw    $v0, ($t1)
.L_U_8031EAF0:
/* 0D9AF0 8031EAF0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0D9AF4 8031EAF4 27BD0048 */  addiu $sp, $sp, 0x48
/* 0D9AF8 8031EAF8 03E00008 */  jr    $ra
/* 0D9AFC 8031EAFC 00000000 */   nop   
)
#endif

void SetSound(s32 arg0, f32 *arg1)
{
    D_80360128[D_80331E34].unk0 = arg0;
    D_80360128[D_80331E34].unk4 = arg1;
    D_80331E34++;
}

static void func_8031DCA8(u32 arg0, f32 *arg1)
{
    u8 listIndex;
    u8 index;
    u8 counter = 0;
    f32 dist;
    const f32 one = 1.0f;

    listIndex = (arg0 & 0xf0000000) >> 0x1c;
    if ((u8)((arg0 & 0xff0000) >> 0x10) >= D_803320D4[listIndex] ||
            D_803320F8[listIndex] != 0)
    {
        return;
    }

    index = D_80360C48[listIndex][0].unk1B;
    while (index != 0xff && index != 0)
    {
        if (D_80360C48[listIndex][index].unk0 == arg1)
        {
            if ((D_80360C48[listIndex][index].unk14 & 0xff00) <= (arg0 & 0xff00))
            {
                if ((D_80360C48[listIndex][index].unk14 & 0x80) != 0 ||
                        (arg0 & 0xff0000) != (D_80360C48[listIndex][index].unk14 & 0xff0000))
                {
                    func_8031E0E4(listIndex, index);
                    D_80360C48[listIndex][index].unk14 = arg0;
                    D_80360C48[listIndex][index].unk18 = arg0 & 0xf;
                }
                D_80360C48[listIndex][index].unk19 = 10;
            }
            index = 0;
        }
        else
        {
            index = D_80360C48[listIndex][index].unk1B;
        }
        counter++;
    }

    if (counter == 0)
    {
        D_80363808[listIndex] = 32;
    }

    if (D_80360C48[listIndex][D_803320B0[listIndex]].unk1B != 0xff && index != 0)
    {
        index = D_803320B0[listIndex];
        dist = sqrtf(arg1[0]*arg1[0] + arg1[1]*arg1[1] + arg1[2]*arg1[2]) * one;
        D_80360C48[listIndex][index].unk0 = &arg1[0];
        D_80360C48[listIndex][index].unk4 = &arg1[1];
        D_80360C48[listIndex][index].unk8 = &arg1[2];
        D_80360C48[listIndex][index].unkC = dist;
        D_80360C48[listIndex][index].unk14 = arg0;
        D_80360C48[listIndex][index].unk18 = arg0 & 0xf;
        D_80360C48[listIndex][index].unk19 = 10;
        D_80360C48[listIndex][index].unk1A = D_803320A4[listIndex];
        D_80360C48[listIndex][D_803320A4[listIndex]].unk1B = D_803320B0[listIndex];
        D_803320A4[listIndex] = D_803320B0[listIndex];
        D_803320B0[listIndex] = D_80360C48[listIndex][D_803320B0[listIndex]].unk1B;
        D_80360C48[listIndex][D_803320B0[listIndex]].unk1A = 0xff;
        D_80360C48[listIndex][index].unk1B = 0xff;
    }
}

void func_8031DF64(void)
{
    struct Sound *temp;

    while (D_80331E34 != D_80331E30)
    {
        temp = &D_80360128[D_80331E30];
        func_8031DCA8(temp->unk0, temp->unk4);
        D_80331E30++;
    }
}

void func_8031DFE8(u8 listIndex, u8 item)
{
    // move item from list D_803320A4 to list D_803320B0
    if (D_803320A4[listIndex] == item)
    {
        D_803320A4[listIndex] = D_80360C48[listIndex][item].unk1A;
    }
    else
    {
        D_80360C48[listIndex][D_80360C48[listIndex][item].unk1B].unk1A =
            D_80360C48[listIndex][item].unk1A;
    }

    D_80360C48[listIndex][D_80360C48[listIndex][item].unk1A].unk1B =
        D_80360C48[listIndex][item].unk1B;
    D_80360C48[listIndex][item].unk1B = D_803320B0[listIndex];
    D_80360C48[listIndex][item].unk1A = -1;
    D_80360C48[listIndex][D_803320B0[listIndex]].unk1A = item;
    D_803320B0[listIndex] = item;
}

void func_8031E0E4(u8 listIndex, u8 item)
{
    if (D_80360C48[listIndex][item].unk14 & 0x10)
    {
        D_80332110 &= (1 << listIndex) ^ 0xffff;
        func_803200E4(50);
    }
}

void func_8031E16C(u8 listIndex)
{
    u32 val2;
    u8 spDB;
    u8 i;
    u8 j;
    u8 index;
    u32 sp98[16] = {
        0x10000000, 0x10000000, 0x10000000, 0x10000000,
        0x10000000, 0x10000000, 0x10000000, 0x10000000,
        0x10000000, 0x10000000, 0x10000000, 0x10000000,
        0x10000000, 0x10000000, 0x10000000, 0x10000000
    };
    u8 sp88[16] = {
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
    };
    u8 sp78[16] = {
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
    };
    u8 sp77 = 0;
    u8 val;

    index = D_80360C48[listIndex][0].unk1B;
    while (index != 0xff)
    {
        spDB = index;

        if ((D_80360C48[listIndex][index].unk14 & 0x8f) == 0x81)
        {
            if (!D_80360C48[listIndex][index].unk19--)
            {
                D_80360C48[listIndex][index].unk14 = 0;
            }
        }
        else if ((D_80360C48[listIndex][index].unk14 & 0x80) == 0)
        {
            if (D_80360C48[listIndex][index].unk19-- == 8)
            {
                func_8031E0E4(listIndex, index);
                D_80360C48[listIndex][index].unk14 = 0;
            }
        }

        if (D_80360C48[listIndex][index].unk14 == 0 && D_80360C48[listIndex][index].unk18 == 1)
        {
            spDB = D_80360C48[listIndex][index].unk1A;
            D_80360C48[listIndex][index].unk18 = 0;
            func_8031DFE8(listIndex, index);
        }

        if (D_80360C48[listIndex][index].unk18 != 0 && index == spDB)
        {
            D_80360C48[listIndex][index].unkC = sqrtf(
                    (*D_80360C48[listIndex][index].unk0 * *D_80360C48[listIndex][index].unk0) +
                    (*D_80360C48[listIndex][index].unk4 * *D_80360C48[listIndex][index].unk4) +
                    (*D_80360C48[listIndex][index].unk8 * *D_80360C48[listIndex][index].unk8)) * 1;

            val = (D_80360C48[listIndex][index].unk14 & 0xff00) >> 8;
            if (D_80360C48[listIndex][index].unk14 & 0x4000000)
            {
                D_80360C48[listIndex][index].unk10 =
                    0x4c * (0xff - val);
            }
            else if (*D_80360C48[listIndex][index].unk8 > 0.0f)
            {
                D_80360C48[listIndex][index].unk10 =
                    (u32) D_80360C48[listIndex][index].unkC +
                    (u32) (*D_80360C48[listIndex][index].unk8 / US_FLOAT(6.0)) +
                    0x4c * (0xff - val);
            }
            else
            {
                D_80360C48[listIndex][index].unk10 =
                    (u32) D_80360C48[listIndex][index].unkC +
                    0x4c * (0xff - val);
            }

            for (i = 0; i < D_803320C8[listIndex]; i++)
            {
                if (sp98[i] >= D_80360C48[listIndex][index].unk10)
                {
                    for (j = D_803320C8[listIndex] - 1; j > i; j--)
                    {
                        sp98[j] = sp98[j-1];
                        sp88[j] = sp88[j-1];
                        sp78[j] = sp78[j-1];
                    }
                    sp98[i] = D_80360C48[listIndex][index].unk10;
                    sp88[i] = index;
                    sp78[i] = D_80360C48[listIndex][index].unk18;
                    i = D_803320C8[listIndex];
                }
            }
            sp77++;
        }
        index = D_80360C48[listIndex][spDB].unk1B;
    }

    D_803320BC[listIndex] = sp77;
    D_80360C28[listIndex] = D_803320C8[listIndex];

    for (i = 0; i < D_80360C28[listIndex]; i++)
    {
        for (index = 0; index < D_80360C28[listIndex]; index++)
        {
            if (sp88[index] != 0xff && D_80360C38[listIndex][i] == sp88[index])
            {
                sp88[index] = 0xff;
                index = 0xfe;
            }
        }

        if (index != 0xff)
        {
            if (D_80360C38[listIndex][i] != 0xff)
            {
                if (D_80360C48[listIndex][D_80360C38[listIndex][i]].unk14 == 0)
                {
                    if (D_80360C48[listIndex][D_80360C38[listIndex][i]].unk18 == 2)
                    {
                        D_80360C48[listIndex][D_80360C38[listIndex][i]].unk18 = 0;
                        func_8031DFE8(listIndex, D_80360C38[listIndex][i]);
                    }
                }
                val2 = D_80360C48[listIndex][D_80360C38[listIndex][i]].unk14 & 0x8f;
                if (val2 >= 130 && D_80360C48[listIndex][D_80360C38[listIndex][i]].unk18 != 0)
                {
#ifndef VERSION_JP
                    func_8031E0E4(listIndex, D_80360C38[listIndex][i]);
#endif
                    D_80360C48[listIndex][D_80360C38[listIndex][i]].unk14 = 0;
                    D_80360C48[listIndex][D_80360C38[listIndex][i]].unk18 = 0;
                    func_8031DFE8(listIndex, D_80360C38[listIndex][i]);
                }
                else
                {
                    if (val2 == 2 && D_80360C48[listIndex][D_80360C38[listIndex][i]].unk18 != 0)
                    {
                        D_80360C48[listIndex][D_80360C38[listIndex][i]].unk18 = 1;
                    }
                }
            }
            D_80360C38[listIndex][i] = 0xff;
        }
    }

    for (index = 0; index < D_80360C28[listIndex]; index++)
    {
        if (sp88[index] != 0xff)
        {
            for (i = 0; i < D_80360C28[listIndex]; i++)
            {
                if (D_80360C38[listIndex][i] == 0xff)
                {
                    D_80360C38[listIndex][i] = sp88[index];
                    D_80360C48[listIndex][sp88[index]].unk14 =
                        (D_80360C48[listIndex][sp88[index]].unk14 & ~0xF) + 1;
                    sp88[i] = 0xff;
                    i = 0xfe;
                }
            }
        }
    }
}

f32 func_8031E97C(f32 arg0, f32 arg1)
{
    f32 abs0;
    f32 abs1;
    f32 ret;

    abs0 = (arg0 < 0 ? -arg0 : arg0);

    if (abs0 > US_FLOAT(22000.0))
    {
        abs0 = US_FLOAT(22000.0);
    }

    abs1 = (arg1 < 0 ? -arg1 : arg1);

    if (abs1 > US_FLOAT(22000.0))
    {
        abs1 = US_FLOAT(22000.0);
    }

    if (arg0 == US_FLOAT(0.0) && arg1 == US_FLOAT(0.0))
    {
        ret = US_FLOAT(0.5);
    }
    else if (US_FLOAT(0.0) <= arg0 && abs1 <= abs0)
    {
        ret = US_FLOAT(1.0) -
            (US_FLOAT(44000.0) - abs0) /
            (US_FLOAT(3.0) * (US_FLOAT(44000.0) - abs1));
    }
    else if (arg0 < 0 && abs1 < abs0)
    {
        ret = (US_FLOAT(44000.0) - abs0) /
            (US_FLOAT(3.0) * (US_FLOAT(44000.0) - abs1));
    }
    else
    {
        ret = 0.5 + arg0 / (US_FLOAT(6.0) * abs1);
    }

    return ret;
}

f32 func_8031EB24(u8 listIndex, u8 item, f32 arg2)
{
    f32 f0;
    f32 f12;
#ifndef VERSION_JP
    s32 div = listIndex < 3 ? 2 : 3;
#endif

    if (!(D_80360C48[listIndex][item].unk14 & 0x1000000))
    {
#ifdef VERSION_JP
        f0 = D_80332028[gCurrLevelNum];
        if (f0 < D_80360C48[listIndex][item].unkC)
        {
            f12 = 0.0f;
        }
        else
        {
            f12 = 1.0 - D_80360C48[listIndex][item].unkC / f0;
        }
#else
        if (D_80360C48[listIndex][item].unkC > 22000.0f)
        {
            f12 = 0.0f;
        }
        else
        {
            f0 = D_80332028[gCurrLevelNum] / div;
            if (f0 < D_80360C48[listIndex][item].unkC)
            {
                f12 = ((22000.0f - D_80360C48[listIndex][item].unkC) / (22000.0f - f0)) * (1.0f - arg2);
            }
            else
            {
                f12 = 1.0f - D_80360C48[listIndex][item].unkC / f0 * arg2;
            }
        }
#endif

        if (D_80360C48[listIndex][item].unk14 & 0x2000000)
        {
#ifdef VERSION_JP
            if (f12 != 0.0)
            {
                f12 -= (f32) (D_80226EB8 & 0xf) / 192.0;
            }
#else
            if (f12 >= 0.08f)
            {
                f12 -= (f32) (D_80226EB8 & 0xf) / 192.0f;
            }
#endif
        }
    }
    else
    {
        f12 = 1.0f;
    }

    return arg2 * f12 * f12 + 1.0f - arg2;
}

f32 func_8031EC7C(u8 listIndex, u8 item)
{
    f32 f2;

    if (!(D_80360C48[listIndex][item].unk14 & 0x8000000))
    {
        f2 = D_80360C48[listIndex][item].unkC / US_FLOAT(22000.0);
        if (D_80360C48[listIndex][item].unk14 & 0x2000000)
        {
            f2 += (f32) (D_80226EB8 & 0xff) * US_FLOAT(0.015625);
        }
    }
    else
    {
        f2 = 0.0f;
    }
    return f2 / US_FLOAT(15.0) + US_FLOAT(1.0);
}

u8 func_8031ED70(UNUSED u8 listIndex, UNUSED u8 item, u8 arg2)
{
    u8 area;
    u8 level;
    u8 ret;

#ifndef VERSION_JP
    if (D_80360C48[listIndex][item].unk14 & 0x20)
    {
        level = 0;
        area = 0;
    }
    else
    {
#endif
        level = (gCurrLevelNum > LEVEL_MAX ? LEVEL_MAX : gCurrLevelNum);
        area = gCurrAreaIndex - 1;
        if (area > 2)
            area = 2;
#ifndef VERSION_JP
    }
#endif

    ret = (u8) (D_80222A18[2].unk2C[arg2]->unk59 + D_80331FB0[level][area] +
            (US_FLOAT(1.0) - D_80222A18[2].unk2C[arg2]->unk20) * IF_US(48.0, 40.0f));

    if (ret > 0x7f)
    {
        ret = 0x7f;
    }
    return ret;
}

static void func_8031EEC8(void)
{
}

void func_8031EED0(void)
{
    D_80331D44 = 1;
    func_8031EEC8();
}

void func_8031EEF8(void)
{
    u8 unk18;
    u8 unk58;
    u8 listIndex;
    u8 j;
    u8 k;
    u8 index;
    f32 ret;

    k = 0;
    func_8031DF64();
    func_8031FA4C();
    if (D_80222A18[2].unk2C[0] == (void *)&D_80225DD8)
    {
        return;
    }

    for (listIndex = 0; listIndex < 10; listIndex++)
    {
        func_8031E16C(listIndex);
        for (j = 0; j < 1; j++)
        {
            index = D_80360C38[listIndex][j];
            if (index < 0xff && D_80360C48[listIndex][index].unk18 != 0)
            {
                unk18 = D_80360C48[listIndex][index].unk14 & 0xf;
                unk58 = (D_80360C48[listIndex][index].unk14 >> 0x10);
                D_80360C48[listIndex][index].unk18 = unk18;
                if (unk18 == 1)
                {
                    if (D_80360C48[listIndex][index].unk14 & 0x10)
                    {
                        D_80332110 |= 1 << listIndex;
                        func_803200E4(50);
                    }

                    D_80360C48[listIndex][index].unk14++;
                    D_80360C48[listIndex][index].unk18 = 2;
                    D_80222A18[2].unk2C[k]->unk58 = unk58;
                    D_80222A18[2].unk2C[k]->unk54 = 1;

                    switch (listIndex)
                    {
                    case 1:
                        if (!(D_80360C48[listIndex][index].unk14 & 0x8000000))
                        {
                            if (D_80363808[listIndex] >= 9)
                            {
                                ret = func_8031EB24(listIndex, index, IF_US(0.8f, 0.9f));
                                D_80222A18[2].unk2C[k]->unk20 = ret;
                            }
                            else
                            {
                                ret = func_8031EB24(listIndex, index, IF_US(0.8f, 0.9f));
                                D_80222A18[2].unk2C[k]->unk20 =
                                    (D_80363808[listIndex] + 8.0f) / 16 * ret;
                            }
                            D_80222A18[2].unk2C[k]->unk24 = func_8031E97C(
                                        *D_80360C48[listIndex][index].unk0,
                                        *D_80360C48[listIndex][index].unk8);

                            if ((D_80360C48[listIndex][index].unk14 & 0xff0000) == 0x170000)
                            {
                                ret = func_8031EC7C(listIndex, index);
                                D_80222A18[2].unk2C[k]->unk2C =
                                    ((f32) D_80363808[listIndex] / US_FLOAT(80.0)) + ret;
                            }
                            else
                            {
                                ret = func_8031EC7C(listIndex, index);
                                D_80222A18[2].unk2C[k]->unk2C =
                                    ((f32) D_80363808[listIndex] / US_FLOAT(400.0)) + ret;
                            }
                            D_80222A18[2].unk2C[k]->unk3 =
                                func_8031ED70(listIndex, index, k);

                            break;
                        }
                    // fallthrough
                    case 7:
                        D_80222A18[2].unk2C[k]->unk20 = 1.0f;
                        D_80222A18[2].unk2C[k]->unk24 = 0.5f;
                        D_80222A18[2].unk2C[k]->unk2C = 1.0f;
                        break;
                    case 0:
                    case 2:
                        D_80222A18[2].unk2C[k]->unk20 =
                            func_8031EB24(listIndex, index, IF_US(0.8f, 0.9f));
                        D_80222A18[2].unk2C[k]->unk24 = func_8031E97C(
                            *D_80360C48[listIndex][index].unk0,
                            *D_80360C48[listIndex][index].unk8);
                        D_80222A18[2].unk2C[k]->unk2C = func_8031EC7C(listIndex, index);
                        D_80222A18[2].unk2C[k]->unk3 = func_8031ED70(listIndex, index, k);
                        break;
                    case 3:
                    case 4:
                    case 5:
                    case 6:
                    case 8:
                    case 9:
                        D_80222A18[2].unk2C[k]->unk3 =
                            func_8031ED70(listIndex, index, k);
                        D_80222A18[2].unk2C[k]->unk20 =
                            func_8031EB24(listIndex, index, IF_US(1.0f, 0.8f));
                        D_80222A18[2].unk2C[k]->unk24 = func_8031E97C(
                                *D_80360C48[listIndex][index].unk0,
                                *D_80360C48[listIndex][index].unk8);
                        D_80222A18[2].unk2C[k]->unk2C =
                            func_8031EC7C(listIndex, index);
                        break;
                    }
                }
#ifdef VERSION_JP
                else if (unk18 == 0)
                {
                    func_8031E0E4(listIndex, index);
                    D_80222A18[2].unk2C[k]->unk54 = 0;
                    func_8031DFE8(listIndex, index);
                }
#else
                else if (D_80222A18[2].unk2C[k]->unk44 == 0)
                {
                    func_8031E0E4(listIndex, index);
                    D_80360C48[listIndex][index].unk18 = 0;
                    func_8031DFE8(listIndex, index);
                }
                else if (unk18 == 0 && D_80222A18[2].unk2C[k]->unk44->unk0b40 == 0)
                {
                    func_8031E0E4(listIndex, index);
                    D_80222A18[2].unk2C[k]->unk54 = 0;
                    func_8031DFE8(listIndex, index);
                }
#endif
                else if (D_80222A18[2].unk2C[k]->unk44->unk0b80 == 0)
                {
                    func_8031E0E4(listIndex, index);
                    D_80360C48[listIndex][index].unk18 = 0;
                    func_8031DFE8(listIndex, index);
                }
                else
                {
                    // Exactly the same code as before. Unfortunately we can't
                    // make a macro out of this, because then everything ends up
                    // on the same line after preprocessing, and the compiler,
                    // somehow caring about line numbers, makes it not match (it
                    // computes function arguments in the wrong order).
                    switch (listIndex)
                    {
                    case 1:
                        if (!(D_80360C48[listIndex][index].unk14 & 0x8000000))
                        {
                            if (D_80363808[listIndex] >= 9)
                            {
                                ret = func_8031EB24(listIndex, index, IF_US(0.8f, 0.9f));
                                D_80222A18[2].unk2C[k]->unk20 = ret;
                            }
                            else
                            {
                                ret = func_8031EB24(listIndex, index, IF_US(0.8f, 0.9f));
                                D_80222A18[2].unk2C[k]->unk20 =
                                    (D_80363808[listIndex] + 8.0f) / 16 * ret;
                            }
                            D_80222A18[2].unk2C[k]->unk24 = func_8031E97C(
                                        *D_80360C48[listIndex][index].unk0,
                                        *D_80360C48[listIndex][index].unk8);

                            if ((D_80360C48[listIndex][index].unk14 & 0xff0000) == 0x170000)
                            {
                                ret = func_8031EC7C(listIndex, index);
                                D_80222A18[2].unk2C[k]->unk2C =
                                    ((f32) D_80363808[listIndex] / US_FLOAT(80.0)) + ret;
                            }
                            else
                            {
                                ret = func_8031EC7C(listIndex, index);
                                D_80222A18[2].unk2C[k]->unk2C =
                                    ((f32) D_80363808[listIndex] / US_FLOAT(400.0)) + ret;
                            }
                            D_80222A18[2].unk2C[k]->unk3 =
                                func_8031ED70(listIndex, index, k);

                            break;
                        }
                    // fallthrough
                    case 7:
                        D_80222A18[2].unk2C[k]->unk20 = 1.0f;
                        D_80222A18[2].unk2C[k]->unk24 = 0.5f;
                        D_80222A18[2].unk2C[k]->unk2C = 1.0f;
                        break;
                    case 0:
                    case 2:
                        D_80222A18[2].unk2C[k]->unk20 =
                            func_8031EB24(listIndex, index, IF_US(0.8f, 0.9f));
                        D_80222A18[2].unk2C[k]->unk24 = func_8031E97C(
                            *D_80360C48[listIndex][index].unk0,
                            *D_80360C48[listIndex][index].unk8);
                        D_80222A18[2].unk2C[k]->unk2C = func_8031EC7C(listIndex, index);
                        D_80222A18[2].unk2C[k]->unk3 = func_8031ED70(listIndex, index, k);
                        break;
                    case 3:
                    case 4:
                    case 5:
                    case 6:
                    case 8:
                    case 9:
                        D_80222A18[2].unk2C[k]->unk3 =
                            func_8031ED70(listIndex, index, k);
                        D_80222A18[2].unk2C[k]->unk20 =
                            func_8031EB24(listIndex, index, IF_US(1.0f, 0.8f));
                        D_80222A18[2].unk2C[k]->unk24 = func_8031E97C(
                                *D_80360C48[listIndex][index].unk0,
                                *D_80360C48[listIndex][index].unk8);
                        D_80222A18[2].unk2C[k]->unk2C =
                            func_8031EC7C(listIndex, index);
                        break;
                    }
                }
            }
            k++;
        }

        k += D_803320C8[listIndex] - D_80360C28[listIndex];
    }
}

void SetMusic(u8 arg0, u8 arg1, u16 arg2)
{
    u8 temp_ret;
    u8 i;

    if (arg0 == 0)
    {
        D_8033209C = arg1 & 0x7f;
        D_80331EB0 = 0xff;
        D_80331EAC = 0xff;
        D_803320A0 = 2;
    }

    for (i = 0; i < 0x10; i++)
    {
        D_80360928[arg0][i].unkC = 0;
    }

    D_80222A18[arg0].unk1 = arg1 & 0x80;
    func_80318280(arg0, arg1 & 0x7f, 0);
    if (arg0 == 0)
    {
        temp_ret = func_803200E4(0);
        if (temp_ret != 0xff)
        {
            D_80222A18[0].unk2 = 4;
            D_80222A18[0].unk18 = (f32) temp_ret / US_FLOAT(127.0);
        }
    }
    else
    {
        func_8031D690(arg0, arg2);
    }
}

void func_8031F7CC(u8 arg0, u16 arg1)
{
    if (arg0 == 0)
    {
        D_8033209C = 0xff;
    }
    func_8031D630(arg0, arg1);
}

void func_8031F810(u8 arg0, u8 arg1, u16 arg2)
{
    u8 i;
    for (i = 0; i < 0x10; i++)
    {
        func_8031F888(arg0, i, arg1, arg2);
    }
}

void func_8031F888(u8 arg0, u8 arg1, u8 arg2, u16 arg3)
{
    struct Struct80360928 *temp;

    if (D_80222A18[arg0].unk2C[arg1] != (void *)&D_80225DD8)
    {
        temp = &D_80360928[arg0][arg1];
        temp->unkC = arg3;
        temp->unk0 = ((f32) (arg2 / US_FLOAT(127.0)) - D_80222A18[arg0].unk2C[arg1]->unk1C) / arg3;
        temp->unk4 = arg2;
        temp->unk8 = D_80222A18[arg0].unk2C[arg1]->unk1C;
    }
}

void func_8031F96C(u8 arg0)
{
    u8 i;

    for (i = 0; i < 16; i++)
    {
        if (D_80222A18[arg0].unk2C[i] != (void *)&D_80225DD8 && D_80360928[arg0][i].unkC != 0)
        {
            D_80360928[arg0][i].unk8 += D_80360928[arg0][i].unk0;
            D_80222A18[arg0].unk2C[i]->unk1C = D_80360928[arg0][i].unk8;
            D_80360928[arg0][i].unkC--;
            if (D_80360928[arg0][i].unkC == 0)
            {
                D_80222A18[arg0].unk2C[i]->unk1C = D_80360928[arg0][i].unk4 / 127.0f;
            }
        }
    }
}

#ifdef NON_MATCHING

void func_8031FA4C(void)
{
    u8 music; // sp57
    s16 conditionValues[8]; // sp44
    u8 conditionTypes[8]; // sp3C
    s16 sp3A;
    s16 sp38;
    u32 conditionBits; // s0
    u32 tempBits; // v1
    s32 numConditions; // v1
    u16 bit; // a1
    u8 condIndex; // a0 (same as numConditions?)
    u8 i; // s1
    u8 j; // v0
    u16 bit2; // s0, v1

    func_8031F96C(0);
    func_8031F96C(2);
    func_80320ED8();
    if (D_803320A0 != 0)
    {
        D_803320A0--;
    }
    else
    {
        D_80331EB0 = D_8033209C;
    }

    if (D_80331EB0 != D_80331EB4[gCurrLevelNum][0])
    {
        return;
    }

    conditionBits = D_80331EB4[gCurrLevelNum][1] & 0xff00;
    music = D_80331EB4[gCurrLevelNum][1] & 0xff;
    i = 2;
    while (conditionBits & 0xff00)
    {
        condIndex = 0;
        for (j = 0, bit = 0x8000; j < 8; j++, bit = bit >> 1)
        {
            if (conditionBits & bit)
            {
                s16 val = D_80331EB4[gCurrLevelNum][i];
                conditionValues[condIndex] = val;
                i++;
                conditionTypes[condIndex] = j;
                condIndex++;
            }
        }

        numConditions = condIndex;
        for (j = 0; j < numConditions; j++)
        {
            // (having all 'temp' share a single variable affects regalloc)
            UNUSED s16 temp;
            switch (conditionTypes[j])
            {
            case 0: {
                s16 temp = gMarioStates[0].pos[0];
                if (temp < conditionValues[j])
                    j = numConditions + 1;
                break;
            }
            case 1: {
                s16 temp = gMarioStates[0].pos[1];
                if (temp < conditionValues[j])
                    j = numConditions + 1;
                break;
            }
            case 2: {
                s16 temp = gMarioStates[0].pos[2];
                if (temp < conditionValues[j])
                    j = numConditions + 1;
                break;
            }
            case 3: {
                s16 temp = gMarioStates[0].pos[0];
                if (temp >= conditionValues[j])
                    j = numConditions + 1;
                break;
            }
            case 4: {
                s16 temp = gMarioStates[0].pos[1];
                if (temp >= conditionValues[j])
                    j = numConditions + 1;
                break;
            }
            case 5: {
                s16 temp = gMarioStates[0].pos[2];
                if (temp >= conditionValues[j])
                    j = numConditions + 1;
                break;
            }
            case 6: {
                s16 temp = gCurrAreaIndex;
                if (temp != conditionValues[j])
                    j = numConditions + 1;
                break;
            }
            case 7: {
                s16 temp = gMarioCurrentRoom;
                if (temp != conditionValues[j])
                    j = numConditions + 1;
                break;
            }
            }
        }

        if (j == numConditions)
        {
            // The area matches. Break out of the loop.
            tempBits = 0;
        }
        else
        {
            tempBits = D_80331EB4[gCurrLevelNum][i++];
            music = tempBits & 0xff,
            tempBits &= 0xff00;
        }

        conditionBits = tempBits;
    }

    if (music != D_80331EAC)
    {
        bit2 = 1;
        if (D_80331EAC == 0xff)
        {
            sp3A = 1;
            sp38 = 1;
        }
        else
        {
            sp3A = D_80331F50[music].unk4;
            sp38 = D_80331F50[music].unkA;
        }

        for (i = 0; i < 16; i++)
        {
            if (D_80331F50[music].unk0 & bit2)
            {
                func_8031F888(0, i, D_80331F50[music].unk3, sp3A);
            }
            if (D_80331F50[music].unk6 & bit2)
            {
                func_8031F888(0, i, D_80331F50[music].unk9, sp38);
            }
            bit2 <<= 1;
        }

        D_80331EAC = music;
    }
}

#else

GLOBAL_ASM(
.late_rodata
glabel jtbl_80338418
    .word L8031FBAC
    .word L8031FBEC
    .word L8031FC2C
    .word L8031FC6C
    .word L8031FCAC
    .word L8031FCEC
    .word L8031FD2C
    .word L8031FD54

.text
glabel func_8031FA4C # US: 803208EC
/* 0DAA4C 8031FA4C 27BDFFA0 */  addiu $sp, $sp, -0x60
/* 0DAA50 8031FA50 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0DAA54 8031FA54 AFB20020 */  sw    $s2, 0x20($sp)
/* 0DAA58 8031FA58 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0DAA5C 8031FA5C AFB00018 */  sw    $s0, 0x18($sp)
/* 0DAA60 8031FA60 0C0C7E5B */  jal   func_8031F96C
/* 0DAA64 8031FA64 00002025 */   move  $a0, $zero
/* 0DAA68 8031FA68 0C0C7E5B */  jal   func_8031F96C
/* 0DAA6C 8031FA6C 24040002 */   li    $a0, 2
/* 0DAA70 8031FA70 0C0C83B6 */  jal   func_80320ED8
/* 0DAA74 8031FA74 00000000 */   nop   
/* 0DAA78 8031FA78 3C038033 */  lui   $v1, %hi(D_803320A0) # $v1, 0x8033
/* 0DAA7C 8031FA7C 246320A0 */  addiu $v1, %lo(D_803320A0) # addiu $v1, $v1, 0x20a0
/* 0DAA80 8031FA80 90620000 */  lbu   $v0, ($v1)
/* 0DAA84 8031FA84 10400003 */  beqz  $v0, .L8031FA94
/* 0DAA88 8031FA88 244EFFFF */   addiu $t6, $v0, -1
/* 0DAA8C 8031FA8C 10000005 */  b     .L8031FAA4
/* 0DAA90 8031FA90 A06E0000 */   sb    $t6, ($v1)
.L8031FA94:
/* 0DAA94 8031FA94 3C0F8033 */  lui   $t7, %hi(D_8033209C) # $t7, 0x8033
/* 0DAA98 8031FA98 91EF209C */  lbu   $t7, %lo(D_8033209C)($t7)
/* 0DAA9C 8031FA9C 3C018033 */  lui   $at, %hi(D_80331EB0) # $at, 0x8033
/* 0DAAA0 8031FAA0 A02F1EB0 */  sb    $t7, %lo(D_80331EB0)($at)
.L8031FAA4:
/* 0DAAA4 8031FAA4 3C188033 */  lui   $t8, %hi(gCurrLevelNum) # $t8, 0x8033
/* 0DAAA8 8031FAA8 8718CE98 */  lh    $t8, %lo(gCurrLevelNum)($t8)
/* 0DAAAC 8031FAAC 3C098033 */  lui   $t1, %hi(D_80331EB4)
/* 0DAAB0 8031FAB0 3C0C8033 */  lui   $t4, %hi(D_80331EB0) # $t4, 0x8033
/* 0DAAB4 8031FAB4 0018C880 */  sll   $t9, $t8, 2
/* 0DAAB8 8031FAB8 01394821 */  addu  $t1, $t1, $t9
/* 0DAABC 8031FABC 8D291EB4 */  lw    $t1, %lo(D_80331EB4)($t1)
/* 0DAAC0 8031FAC0 918C1EB0 */  lbu   $t4, %lo(D_80331EB0)($t4)
/* 0DAAC4 8031FAC4 852D0000 */  lh    $t5, ($t1)
/* 0DAAC8 8031FAC8 558D00FC */  bnel  $t4, $t5, .L8031FEBC
/* 0DAACC 8031FACC 8FBF0024 */   lw    $ra, 0x24($sp)
/* 0DAAD0 8031FAD0 852F0002 */  lh    $t7, 2($t1)
/* 0DAAD4 8031FAD4 24110002 */  li    $s1, 2
/* 0DAAD8 8031FAD8 3C0B8034 */  lui   $t3, %hi(gCurrAreaIndex) # $t3, 0x8034
/* 0DAADC 8031FADC 31F0FF00 */  andi  $s0, $t7, 0xff00
/* 0DAAE0 8031FAE0 3218FF00 */  andi  $t8, $s0, 0xff00
/* 0DAAE4 8031FAE4 130000B9 */  beqz  $t8, .L8031FDCC
/* 0DAAE8 8031FAE8 A3AF0057 */   sb    $t7, 0x57($sp)
/* 0DAAEC 8031FAEC 3C0A8036 */  lui   $t2, %hi(gMarioCurrentRoom) # $t2, 0x8036
/* 0DAAF0 8031FAF0 3C078034 */  lui   $a3, %hi(gMarioStates) # $a3, 0x8034
/* 0DAAF4 8031FAF4 24E79E00 */  addiu $a3, %lo(gMarioStates) # addiu $a3, $a3, -0x6200
/* 0DAAF8 8031FAF8 254AFEE0 */  addiu $t2, %lo(gMarioCurrentRoom) # addiu $t2, $t2, -0x120
/* 0DAAFC 8031FAFC 256BA75A */  addiu $t3, %lo(gCurrAreaIndex) # addiu $t3, $t3, -0x58a6
/* 0DAB00 8031FB00 27A8003C */  addiu $t0, $sp, 0x3c
/* 0DAB04 8031FB04 27A60044 */  addiu $a2, $sp, 0x44
.L8031FB08:
/* 0DAB08 8031FB08 00001025 */  move  $v0, $zero
/* 0DAB0C 8031FB0C 00002025 */  move  $a0, $zero
/* 0DAB10 8031FB10 34058000 */  li    $a1, 32768
.L8031FB14:
/* 0DAB14 8031FB14 00B0C824 */  and   $t9, $a1, $s0
/* 0DAB18 8031FB18 1320000F */  beqz  $t9, .L8031FB58
/* 0DAB1C 8031FB1C 00A01825 */   move  $v1, $a1
/* 0DAB20 8031FB20 00116040 */  sll   $t4, $s1, 1
/* 0DAB24 8031FB24 012C6821 */  addu  $t5, $t1, $t4
/* 0DAB28 8031FB28 85AE0000 */  lh    $t6, ($t5)
/* 0DAB2C 8031FB2C 00047840 */  sll   $t7, $a0, 1
/* 0DAB30 8031FB30 01046021 */  addu  $t4, $t0, $a0
/* 0DAB34 8031FB34 00CFC021 */  addu  $t8, $a2, $t7
/* 0DAB38 8031FB38 26310001 */  addiu $s1, $s1, 1
/* 0DAB3C 8031FB3C 24840001 */  addiu $a0, $a0, 1
/* 0DAB40 8031FB40 323900FF */  andi  $t9, $s1, 0xff
/* 0DAB44 8031FB44 308D00FF */  andi  $t5, $a0, 0xff
/* 0DAB48 8031FB48 A70E0000 */  sh    $t6, ($t8)
/* 0DAB4C 8031FB4C 03208825 */  move  $s1, $t9
/* 0DAB50 8031FB50 A1820000 */  sb    $v0, ($t4)
/* 0DAB54 8031FB54 01A02025 */  move  $a0, $t5
.L8031FB58:
/* 0DAB58 8031FB58 24420001 */  addiu $v0, $v0, 1
/* 0DAB5C 8031FB5C 304F00FF */  andi  $t7, $v0, 0xff
/* 0DAB60 8031FB60 00032843 */  sra   $a1, $v1, 1
/* 0DAB64 8031FB64 30AEFFFF */  andi  $t6, $a1, 0xffff
/* 0DAB68 8031FB68 29E10008 */  slti  $at, $t7, 8
/* 0DAB6C 8031FB6C 01E01025 */  move  $v0, $t7
/* 0DAB70 8031FB70 1420FFE8 */  bnez  $at, .L8031FB14
/* 0DAB74 8031FB74 01C02825 */   move  $a1, $t6
/* 0DAB78 8031FB78 00001025 */  move  $v0, $zero
/* 0DAB7C 8031FB7C 18800083 */  blez  $a0, .L8031FD8C
/* 0DAB80 8031FB80 00801825 */   move  $v1, $a0
.L8031FB84:
/* 0DAB84 8031FB84 0102C021 */  addu  $t8, $t0, $v0
/* 0DAB88 8031FB88 93190000 */  lbu   $t9, ($t8)
/* 0DAB8C 8031FB8C 2F210008 */  sltiu $at, $t9, 8
/* 0DAB90 8031FB90 10200079 */  beqz  $at, .L8031FD78
/* 0DAB94 8031FB94 0019C880 */   sll   $t9, $t9, 2
/* 0DAB98 8031FB98 3C018034 */  lui   $at, %hi(jtbl_80338418)
/* 0DAB9C 8031FB9C 00390821 */  addu  $at, $at, $t9
/* 0DABA0 8031FBA0 8C398418 */  lw    $t9, %lo(jtbl_80338418)($at)
/* 0DABA4 8031FBA4 03200008 */  jr    $t9
/* 0DABA8 8031FBA8 00000000 */   nop   
glabel L8031FBAC
/* 0DABAC 8031FBAC C4E4003C */  lwc1  $f4, 0x3c($a3)
/* 0DABB0 8031FBB0 0002C040 */  sll   $t8, $v0, 1
/* 0DABB4 8031FBB4 00D8C821 */  addu  $t9, $a2, $t8
/* 0DABB8 8031FBB8 4600218D */  trunc.w.s $f6, $f4
/* 0DABBC 8031FBBC 872C0000 */  lh    $t4, ($t9)
/* 0DABC0 8031FBC0 440D3000 */  mfc1  $t5, $f6
/* 0DABC4 8031FBC4 00000000 */  nop   
/* 0DABC8 8031FBC8 000D7C00 */  sll   $t7, $t5, 0x10
/* 0DABCC 8031FBCC 000F7403 */  sra   $t6, $t7, 0x10
/* 0DABD0 8031FBD0 01CC082A */  slt   $at, $t6, $t4
/* 0DABD4 8031FBD4 50200069 */  beql  $at, $zero, .L8031FD7C
/* 0DABD8 8031FBD8 24420001 */   addiu $v0, $v0, 1
/* 0DABDC 8031FBDC 24620001 */  addiu $v0, $v1, 1
/* 0DABE0 8031FBE0 304D00FF */  andi  $t5, $v0, 0xff
/* 0DABE4 8031FBE4 10000064 */  b     .L8031FD78
/* 0DABE8 8031FBE8 01A01025 */   move  $v0, $t5
glabel L8031FBEC
/* 0DABEC 8031FBEC C4E80040 */  lwc1  $f8, 0x40($a3)
/* 0DABF0 8031FBF0 00026040 */  sll   $t4, $v0, 1
/* 0DABF4 8031FBF4 00CC6821 */  addu  $t5, $a2, $t4
/* 0DABF8 8031FBF8 4600428D */  trunc.w.s $f10, $f8
/* 0DABFC 8031FBFC 85AF0000 */  lh    $t7, ($t5)
/* 0DAC00 8031FC00 44185000 */  mfc1  $t8, $f10
/* 0DAC04 8031FC04 00000000 */  nop   
/* 0DAC08 8031FC08 0018CC00 */  sll   $t9, $t8, 0x10
/* 0DAC0C 8031FC0C 00197403 */  sra   $t6, $t9, 0x10
/* 0DAC10 8031FC10 01CF082A */  slt   $at, $t6, $t7
/* 0DAC14 8031FC14 50200059 */  beql  $at, $zero, .L8031FD7C
/* 0DAC18 8031FC18 24420001 */   addiu $v0, $v0, 1
/* 0DAC1C 8031FC1C 24620001 */  addiu $v0, $v1, 1
/* 0DAC20 8031FC20 305800FF */  andi  $t8, $v0, 0xff
/* 0DAC24 8031FC24 10000054 */  b     .L8031FD78
/* 0DAC28 8031FC28 03001025 */   move  $v0, $t8
glabel L8031FC2C
/* 0DAC2C 8031FC2C C4F00044 */  lwc1  $f16, 0x44($a3)
/* 0DAC30 8031FC30 00027840 */  sll   $t7, $v0, 1
/* 0DAC34 8031FC34 00CFC021 */  addu  $t8, $a2, $t7
/* 0DAC38 8031FC38 4600848D */  trunc.w.s $f18, $f16
/* 0DAC3C 8031FC3C 87190000 */  lh    $t9, ($t8)
/* 0DAC40 8031FC40 440C9000 */  mfc1  $t4, $f18
/* 0DAC44 8031FC44 00000000 */  nop   
/* 0DAC48 8031FC48 000C6C00 */  sll   $t5, $t4, 0x10
/* 0DAC4C 8031FC4C 000D7403 */  sra   $t6, $t5, 0x10
/* 0DAC50 8031FC50 01D9082A */  slt   $at, $t6, $t9
/* 0DAC54 8031FC54 50200049 */  beql  $at, $zero, .L8031FD7C
/* 0DAC58 8031FC58 24420001 */   addiu $v0, $v0, 1
/* 0DAC5C 8031FC5C 24620001 */  addiu $v0, $v1, 1
/* 0DAC60 8031FC60 304C00FF */  andi  $t4, $v0, 0xff
/* 0DAC64 8031FC64 10000044 */  b     .L8031FD78
/* 0DAC68 8031FC68 01801025 */   move  $v0, $t4
glabel L8031FC6C
/* 0DAC6C 8031FC6C C4E4003C */  lwc1  $f4, 0x3c($a3)
/* 0DAC70 8031FC70 0002C840 */  sll   $t9, $v0, 1
/* 0DAC74 8031FC74 00D96021 */  addu  $t4, $a2, $t9
/* 0DAC78 8031FC78 4600218D */  trunc.w.s $f6, $f4
/* 0DAC7C 8031FC7C 858D0000 */  lh    $t5, ($t4)
/* 0DAC80 8031FC80 440F3000 */  mfc1  $t7, $f6
/* 0DAC84 8031FC84 00000000 */  nop   
/* 0DAC88 8031FC88 000FC400 */  sll   $t8, $t7, 0x10
/* 0DAC8C 8031FC8C 00187403 */  sra   $t6, $t8, 0x10
/* 0DAC90 8031FC90 01CD082A */  slt   $at, $t6, $t5
/* 0DAC94 8031FC94 54200039 */  bnezl $at, .L8031FD7C
/* 0DAC98 8031FC98 24420001 */   addiu $v0, $v0, 1
/* 0DAC9C 8031FC9C 24620001 */  addiu $v0, $v1, 1
/* 0DACA0 8031FCA0 304F00FF */  andi  $t7, $v0, 0xff
/* 0DACA4 8031FCA4 10000034 */  b     .L8031FD78
/* 0DACA8 8031FCA8 01E01025 */   move  $v0, $t7
glabel L8031FCAC
/* 0DACAC 8031FCAC C4E80040 */  lwc1  $f8, 0x40($a3)
/* 0DACB0 8031FCB0 00026840 */  sll   $t5, $v0, 1
/* 0DACB4 8031FCB4 00CD7821 */  addu  $t7, $a2, $t5
/* 0DACB8 8031FCB8 4600428D */  trunc.w.s $f10, $f8
/* 0DACBC 8031FCBC 85F80000 */  lh    $t8, ($t7)
/* 0DACC0 8031FCC0 44195000 */  mfc1  $t9, $f10
/* 0DACC4 8031FCC4 00000000 */  nop   
/* 0DACC8 8031FCC8 00196400 */  sll   $t4, $t9, 0x10
/* 0DACCC 8031FCCC 000C7403 */  sra   $t6, $t4, 0x10
/* 0DACD0 8031FCD0 01D8082A */  slt   $at, $t6, $t8
/* 0DACD4 8031FCD4 54200029 */  bnezl $at, .L8031FD7C
/* 0DACD8 8031FCD8 24420001 */   addiu $v0, $v0, 1
/* 0DACDC 8031FCDC 24620001 */  addiu $v0, $v1, 1
/* 0DACE0 8031FCE0 305900FF */  andi  $t9, $v0, 0xff
/* 0DACE4 8031FCE4 10000024 */  b     .L8031FD78
/* 0DACE8 8031FCE8 03201025 */   move  $v0, $t9
glabel L8031FCEC
/* 0DACEC 8031FCEC C4F00044 */  lwc1  $f16, 0x44($a3)
/* 0DACF0 8031FCF0 0002C040 */  sll   $t8, $v0, 1
/* 0DACF4 8031FCF4 00D8C821 */  addu  $t9, $a2, $t8
/* 0DACF8 8031FCF8 4600848D */  trunc.w.s $f18, $f16
/* 0DACFC 8031FCFC 872C0000 */  lh    $t4, ($t9)
/* 0DAD00 8031FD00 440D9000 */  mfc1  $t5, $f18
/* 0DAD04 8031FD04 00000000 */  nop   
/* 0DAD08 8031FD08 000D7C00 */  sll   $t7, $t5, 0x10
/* 0DAD0C 8031FD0C 000F7403 */  sra   $t6, $t7, 0x10
/* 0DAD10 8031FD10 01CC082A */  slt   $at, $t6, $t4
/* 0DAD14 8031FD14 54200019 */  bnezl $at, .L8031FD7C
/* 0DAD18 8031FD18 24420001 */   addiu $v0, $v0, 1
/* 0DAD1C 8031FD1C 24620001 */  addiu $v0, $v1, 1
/* 0DAD20 8031FD20 304D00FF */  andi  $t5, $v0, 0xff
/* 0DAD24 8031FD24 10000014 */  b     .L8031FD78
/* 0DAD28 8031FD28 01A01025 */   move  $v0, $t5
glabel L8031FD2C
/* 0DAD2C 8031FD2C 0002C040 */  sll   $t8, $v0, 1
/* 0DAD30 8031FD30 00D8C821 */  addu  $t9, $a2, $t8
/* 0DAD34 8031FD34 872E0000 */  lh    $t6, ($t9)
/* 0DAD38 8031FD38 856F0000 */  lh    $t7, ($t3)
/* 0DAD3C 8031FD3C 51EE000F */  beql  $t7, $t6, .L8031FD7C
/* 0DAD40 8031FD40 24420001 */   addiu $v0, $v0, 1
/* 0DAD44 8031FD44 24620001 */  addiu $v0, $v1, 1
/* 0DAD48 8031FD48 304C00FF */  andi  $t4, $v0, 0xff
/* 0DAD4C 8031FD4C 1000000A */  b     .L8031FD78
/* 0DAD50 8031FD50 01801025 */   move  $v0, $t4
glabel L8031FD54
/* 0DAD54 8031FD54 0002C040 */  sll   $t8, $v0, 1
/* 0DAD58 8031FD58 00D8C821 */  addu  $t9, $a2, $t8
/* 0DAD5C 8031FD5C 872F0000 */  lh    $t7, ($t9)
/* 0DAD60 8031FD60 854D0000 */  lh    $t5, ($t2)
/* 0DAD64 8031FD64 51AF0005 */  beql  $t5, $t7, .L8031FD7C
/* 0DAD68 8031FD68 24420001 */   addiu $v0, $v0, 1
/* 0DAD6C 8031FD6C 24620001 */  addiu $v0, $v1, 1
/* 0DAD70 8031FD70 304E00FF */  andi  $t6, $v0, 0xff
/* 0DAD74 8031FD74 01C01025 */  move  $v0, $t6
.L8031FD78:
/* 0DAD78 8031FD78 24420001 */  addiu $v0, $v0, 1
.L8031FD7C:
/* 0DAD7C 8031FD7C 304C00FF */  andi  $t4, $v0, 0xff
/* 0DAD80 8031FD80 0183082A */  slt   $at, $t4, $v1
/* 0DAD84 8031FD84 1420FF7F */  bnez  $at, .L8031FB84
/* 0DAD88 8031FD88 01801025 */   move  $v0, $t4
.L8031FD8C:
/* 0DAD8C 8031FD8C 14620003 */  bne   $v1, $v0, .L8031FD9C
/* 0DAD90 8031FD90 0011C040 */   sll   $t8, $s1, 1
/* 0DAD94 8031FD94 1000000A */  b     .L8031FDC0
/* 0DAD98 8031FD98 00001825 */   move  $v1, $zero
.L8031FD9C:
/* 0DAD9C 8031FD9C 0138C821 */  addu  $t9, $t1, $t8
/* 0DADA0 8031FDA0 872F0000 */  lh    $t7, ($t9)
/* 0DADA4 8031FDA4 26310001 */  addiu $s1, $s1, 1
/* 0DADA8 8031FDA8 322E00FF */  andi  $t6, $s1, 0xff
/* 0DADAC 8031FDAC 01E01825 */  move  $v1, $t7
/* 0DADB0 8031FDB0 306DFF00 */  andi  $t5, $v1, 0xff00
/* 0DADB4 8031FDB4 01A01825 */  move  $v1, $t5
/* 0DADB8 8031FDB8 01C08825 */  move  $s1, $t6
/* 0DADBC 8031FDBC A3AF0057 */  sb    $t7, 0x57($sp)
.L8031FDC0:
/* 0DADC0 8031FDC0 306CFF00 */  andi  $t4, $v1, 0xff00
/* 0DADC4 8031FDC4 1580FF50 */  bnez  $t4, .L8031FB08
/* 0DADC8 8031FDC8 00608025 */   move  $s0, $v1
.L8031FDCC:
/* 0DADCC 8031FDCC 3C028033 */  lui   $v0, %hi(D_80331EAC) # $v0, 0x8033
/* 0DADD0 8031FDD0 90421EAC */  lbu   $v0, %lo(D_80331EAC)($v0)
/* 0DADD4 8031FDD4 93B80057 */  lbu   $t8, 0x57($sp)
/* 0DADD8 8031FDD8 240100FF */  li    $at, 255
/* 0DADDC 8031FDDC 00008825 */  move  $s1, $zero
/* 0DADE0 8031FDE0 53020036 */  beql  $t8, $v0, .L8031FEBC
/* 0DADE4 8031FDE4 8FBF0024 */   lw    $ra, 0x24($sp)
/* 0DADE8 8031FDE8 1441000C */  bne   $v0, $at, .L8031FE1C
/* 0DADEC 8031FDEC 24030001 */   li    $v1, 1
/* 0DADF0 8031FDF0 00187880 */  sll   $t7, $t8, 2
/* 0DADF4 8031FDF4 01F87823 */  subu  $t7, $t7, $t8
/* 0DADF8 8031FDF8 3C0E8033 */  lui   $t6, %hi(D_80331F50) # $t6, 0x8033
/* 0DADFC 8031FDFC 24190001 */  li    $t9, 1
/* 0DAE00 8031FE00 25CE1F50 */  addiu $t6, %lo(D_80331F50) # addiu $t6, $t6, 0x1f50
/* 0DAE04 8031FE04 000F7880 */  sll   $t7, $t7, 2
/* 0DAE08 8031FE08 240D0001 */  li    $t5, 1
/* 0DAE0C 8031FE0C A7B9003A */  sh    $t9, 0x3a($sp)
/* 0DAE10 8031FE10 A7AD0038 */  sh    $t5, 0x38($sp)
/* 0DAE14 8031FE14 1000000C */  b     .L8031FE48
/* 0DAE18 8031FE18 01EE9021 */   addu  $s2, $t7, $t6
.L8031FE1C:
/* 0DAE1C 8031FE1C 93AC0057 */  lbu   $t4, 0x57($sp)
/* 0DAE20 8031FE20 3C0D8033 */  lui   $t5, %hi(D_80331F50) # $t5, 0x8033
/* 0DAE24 8031FE24 25AD1F50 */  addiu $t5, %lo(D_80331F50) # addiu $t5, $t5, 0x1f50
/* 0DAE28 8031FE28 000CC880 */  sll   $t9, $t4, 2
/* 0DAE2C 8031FE2C 032CC823 */  subu  $t9, $t9, $t4
/* 0DAE30 8031FE30 0019C880 */  sll   $t9, $t9, 2
/* 0DAE34 8031FE34 032D9021 */  addu  $s2, $t9, $t5
/* 0DAE38 8031FE38 86580004 */  lh    $t8, 4($s2)
/* 0DAE3C 8031FE3C 864F000A */  lh    $t7, 0xa($s2)
/* 0DAE40 8031FE40 A7B8003A */  sh    $t8, 0x3a($sp)
/* 0DAE44 8031FE44 A7AF0038 */  sh    $t7, 0x38($sp)
.L8031FE48:
/* 0DAE48 8031FE48 864E0000 */  lh    $t6, ($s2)
/* 0DAE4C 8031FE4C 00608025 */  move  $s0, $v1
/* 0DAE50 8031FE50 00002025 */  move  $a0, $zero
/* 0DAE54 8031FE54 01C36024 */  and   $t4, $t6, $v1
/* 0DAE58 8031FE58 11800004 */  beqz  $t4, .L8031FE6C
/* 0DAE5C 8031FE5C 322500FF */   andi  $a1, $s1, 0xff
/* 0DAE60 8031FE60 92460003 */  lbu   $a2, 3($s2)
/* 0DAE64 8031FE64 0C0C7E22 */  jal   func_8031F888
/* 0DAE68 8031FE68 97A7003A */   lhu   $a3, 0x3a($sp)
.L8031FE6C:
/* 0DAE6C 8031FE6C 86590006 */  lh    $t9, 6($s2)
/* 0DAE70 8031FE70 00002025 */  move  $a0, $zero
/* 0DAE74 8031FE74 322500FF */  andi  $a1, $s1, 0xff
/* 0DAE78 8031FE78 03306824 */  and   $t5, $t9, $s0
/* 0DAE7C 8031FE7C 11A00003 */  beqz  $t5, .L8031FE8C
/* 0DAE80 8031FE80 97A70038 */   lhu   $a3, 0x38($sp)
/* 0DAE84 8031FE84 0C0C7E22 */  jal   func_8031F888
/* 0DAE88 8031FE88 92460009 */   lbu   $a2, 9($s2)
.L8031FE8C:
/* 0DAE8C 8031FE8C 26310001 */  addiu $s1, $s1, 1
/* 0DAE90 8031FE90 322F00FF */  andi  $t7, $s1, 0xff
/* 0DAE94 8031FE94 00101840 */  sll   $v1, $s0, 1
/* 0DAE98 8031FE98 29E10010 */  slti  $at, $t7, 0x10
/* 0DAE9C 8031FE9C 3078FFFF */  andi  $t8, $v1, 0xffff
/* 0DAEA0 8031FEA0 01E08825 */  move  $s1, $t7
/* 0DAEA4 8031FEA4 1420FFE8 */  bnez  $at, .L8031FE48
/* 0DAEA8 8031FEA8 03001825 */   move  $v1, $t8
/* 0DAEAC 8031FEAC 93AE0057 */  lbu   $t6, 0x57($sp)
/* 0DAEB0 8031FEB0 3C018033 */  lui   $at, %hi(D_80331EAC) # $at, 0x8033
/* 0DAEB4 8031FEB4 A02E1EAC */  sb    $t6, %lo(D_80331EAC)($at)
/* 0DAEB8 8031FEB8 8FBF0024 */  lw    $ra, 0x24($sp)
.L8031FEBC:
/* 0DAEBC 8031FEBC 8FB00018 */  lw    $s0, 0x18($sp)
/* 0DAEC0 8031FEC0 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0DAEC4 8031FEC4 8FB20020 */  lw    $s2, 0x20($sp)
/* 0DAEC8 8031FEC8 03E00008 */  jr    $ra
/* 0DAECC 8031FECC 27BD0060 */   addiu $sp, $sp, 0x60
)

#endif

void Unknown8031FED0(u8 arg0, u32 arg1, s8 arg2)
{
    u8 i;

    if (arg2 < 0)
    {
        arg2 = -arg2;
    }

    for (i = 0; i < 16; i++)
    {
        if (D_80222A18[arg0].unk2C[i] != (void *)&D_80225DD8)
        {
            if ((arg1 & 3) == 0)
            {
                D_80222A18[arg0].unk2C[i]->unk1C = 1.0f;
            }
            else if ((arg1 & 1) != 0)
            {
                D_80222A18[arg0].unk2C[i]->unk1C = (f32) arg2 / US_FLOAT(127.0);
            }
            else
            {
                D_80222A18[arg0].unk2C[i]->unk1C = US_FLOAT(1.0) - (f32) arg2 / US_FLOAT(127.0);
            }
        }
        arg1 >>= 2;
    }
}

void func_8031FFB4(u8 arg0, u16 arg1, u8 arg2)
{
    if (arg0 == 0)
    {
        D_80363813 = 1;
        func_803200E4(arg1);
    }
    else if (D_80222A18[arg0].unk0b80 == 1)
    {
        func_8031D6E4(arg0, arg1, arg2);
    }
}

void func_80320040(u8 arg0, u16 arg1)
{
    D_80363813 = 0;
    if (arg0 == 0)
    {
        if (D_80222A18[arg0].unk2 != 1)
        {
            func_803200E4(arg1);
        }
    }
    else
    {
        if (D_80222A18[arg0].unk0b80 == 1)
        {
            func_8031D7B0(arg0, arg1);
        }
    }
}

u8 func_803200E4(u16 arg0)
{
    u8 a2 = 0xff;
    u8 temp;

    if (D_8033209C == 0xff || D_8033209C == 0x1a)
    {
        return 0xff;
    }

    if (D_80222A18[0].unk20 == 0.0f && arg0)
    {
        D_80222A18[0].unk20 = D_80222A18[0].unk18;
    }

    if (D_80363812 != 0)
    {
        a2 = (D_80363812 & 0x7f);
    }

    if (D_8033211C != 0)
    {
        temp = (D_8033211C & 0x7f);
        if (temp < a2)
        {
            a2 = temp;
        }
    }

    if (D_80363813 != 0 && 40 < a2)
    {
        a2 = 40;
    }

    if (D_80332110 != 0 && 20 < a2)
    {
        a2 = 20;
    }

    if (D_80222A18[0].unk0b80 == 1)
    {
        if (a2 != 0xff)
        {
            func_8031D838(0, arg0, a2);
        }
        else
        {
            D_80222A18[0].unk20 = D_80332078[D_8033209C] / 127.0f;
            func_8031D7B0(0, arg0);
        }
    }
    return a2;
}

void func_80320248(u8 arg0)
{
    u8 i;

    for (i = 0; i < 3; i++)
    {
        D_80222A18[i].unk0b20 = arg0;
    }
}

void func_803202A0(void)
{
    u8 i;
    u8 j;

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 40; j++)
        {
            D_80360C48[i][j].unk18 = 0;
        }

        for (j = 0; j < 1; j++)
        {
            D_80360C38[i][j] = 0xff;
        }

        D_803320A4[i] = 0;
        D_803320B0[i] = 1;
        D_803320BC[i] = 0;
    }

    for (i = 0; i < 10; i++)
    {
        D_80360C48[i][0].unk1A = 0xff;
        D_80360C48[i][0].unk1B = 0xff;

        for (j = 1; j < 40 - 1; j++)
        {
            D_80360C48[i][j].unk1A = j - 1;
            D_80360C48[i][j].unk1B = j + 1;
        }

        D_80360C48[i][j].unk1A = j - 1;
        D_80360C48[i][j].unk1B = 0xff;
    }

    for (j = 0; j < 3; j++)
    {
        for (i = 0; i < 16; i++)
        {
            D_80360928[j][i].unkC = 0;
        }
    }

    for (i = 0; i < 6; i++)
    {
        D_80363818[i].unk1 = 0;
    }

    func_80320980(2, 0xffff);
    D_80332118 = 0;
    D_80363812 = 0;
    D_80363813 = 0;
    D_80332110 = 0;
    D_80332114 = 0;
    D_8033209C = 0xff;
    D_80226D7F = 0;
    D_80332128 = 0;
    D_8033211C = 0;
    D_80332120 = 0;
    D_80332124 = 0;
    D_80331E30 = 0;
    D_80331E34 = 0;
}

void Unknown8032050C(u8 arg0, u8 *arg1, u8 *arg2, u8 *arg3)
{
    u8 i;
    u8 counter = 0;

    for (i = 0; i < D_803320C8[arg0]; i++)
    {
        if (D_80360C38[arg0][i] != 0xff)
        {
            counter++;
        }
    }

    *arg1 = counter;
    *arg2 = D_803320BC[arg0];
    if (D_80360C38[arg0][0] != 0xff)
    {
        *arg3 = (u8)(D_80360C48[arg0][D_80360C38[arg0][0]].unk14 >> 0x10);
    }
    else
    {
        *arg3 = 0xff;
    }
}

void func_803205E8(u32 arg0, f32 *arg1)
{
    u8 listIndex;
    u8 item;

    listIndex = (arg0 & 0xf0000000) >> 0x1c;
    item = D_80360C48[listIndex][0].unk1B;
    while (item != 0xff)
    {
        if ((u16)(arg0 >> 0x10) == (u16)(D_80360C48[listIndex][item].unk14 >> 0x10) &&
                D_80360C48[listIndex][item].unk0 == arg1)
        {
            func_8031E0E4(listIndex, item);
            D_80360C48[listIndex][item].unk14 = 0;
            item = 0xff;
        }
        else
        {
            item = D_80360C48[listIndex][item].unk1B;
        }
    }
}

void func_803206F8(f32 *arg0)
{
    u8 listIndex;
    u8 item;

    for (listIndex = 0; listIndex < 10; listIndex++)
    {
        item = D_80360C48[listIndex][0].unk1B;
        while (item != 0xff)
        {
            if (D_80360C48[listIndex][item].unk0 == arg0)
            {
                func_8031E0E4(listIndex, item);
                D_80360C48[listIndex][item].unk14 = 0;
            }
            item = D_80360C48[listIndex][item].unk1B;
        }
    }
}

static void func_803207DC(u8 listIndex)
{
    u8 item = D_80360C48[listIndex][0].unk1B;

    while (item != 0xff)
    {
        func_8031E0E4(listIndex, item);
        D_80360C48[listIndex][item].unk14 = 0;
        item = D_80360C48[listIndex][item].unk1B;
    }
}

void func_80320890(void)
{
    func_803207DC(1);
    func_803207DC(4);
    func_803207DC(6);
}

void func_803208C0(UNUSED u8 arg0, u16 arg1)
{
    u8 i;

    for (i = 0; i < 10; i++)
    {
        if (arg1 & 1)
        {
            D_803320F8[i] = 1;
        }
        arg1 = arg1 >> 1;
    }
}

static void func_8032091C(void)
{
    u8 i;

    for (i = 0; i < 3; i++)
    {
        func_8031AE24(&D_80222A18[i]);
    }
}

void func_80320980(UNUSED u8 arg0, u16 arg1)
{
    u8 i;

    for (i = 0; i < 10; i++)
    {
        if (arg1 & 1)
        {
            D_803320F8[i] = 0;
        }
        arg1 = arg1 >> 1;
    }
}

u8 Unknown803209D8(u8 arg0, u8 arg1, u8 arg2)
{
    u8 ret = 0;
    if (D_80222A18[arg0].unk2C[arg1] != (void *)&D_80225DD8)
    {
        D_80222A18[arg0].unk2C[arg1]->unk0b10 = arg2;
        ret = arg2;
    }
    return ret;
}

void func_80320A4C(u8 arg0, u8 arg1)
{
    D_80363808[arg0] = arg1;
}

void func_80320A68(u8 dialogId)
{
    u8 soundId;

    if (dialogId >= 170)
    {
        dialogId = 0;
    }

    soundId = D_80331D48[dialogId];
    if (soundId != 0xff)
    {
        SetSound(D_80331DF4[soundId], D_803320E0);
        if (soundId == 2)
        {
            SetMusic(1, 0x10, 0);
        }
    }

#ifndef VERSION_JP
    // "You've stepped on the (Wing|Metal|Vanish) Cap Switch"
    if (dialogId == 10 || dialogId == 11 || dialogId == 12)
    {
        func_80321228();
    }
#endif
}

void func_80320AE8(u8 arg0, u16 arg1, s16 arg2)
{
    u8 loBits = arg1 & 0xff;
    u8 hiBits = arg1 >> 8;
    u8 i;
    u8 foundIndex = 0;

    if (arg0 != 0)
    {
        SetMusic(arg0, loBits, arg2);
        return;
    }

    if (D_80332128 == 6)
    {
        return;
    }

    for (i = 0; i < D_80332128; i++)
    {
        if (D_80363818[i].unk0 == loBits)
        {
            if (i == 0)
            {
                SetMusic(0, loBits, arg2);
            }
            else if (!D_80222A18[0].unk0b80)
            {
                func_80320CE8(D_80363818[0].unk0);
            }
            return;
        }
    }

    for (i = 0; i < D_80332128; i++)
    {
        if (D_80363818[i].unk1 <= hiBits)
        {
            foundIndex = i;
            i = D_80332128;
        }
    }

    if (foundIndex == 0)
    {
        SetMusic(0, loBits, arg2);
        D_80332128++;
    }

    for (i = D_80332128 - 1; i > foundIndex; i--)
    {
        D_80363818[i].unk1 = D_80363818[i - 1].unk1;
        D_80363818[i].unk0 = D_80363818[i - 1].unk0;
    }

    D_80363818[foundIndex].unk1 = hiBits;
    D_80363818[foundIndex].unk0 = loBits;
}

void func_80320CE8(u16 arg0)
{
    u8 foundIndex;
    u8 i;

    if (D_80332128 == 0)
    {
        return;
    }

    foundIndex = D_80332128;

    for (i = 0; i < D_80332128; i++)
    {
        if (D_80363818[i].unk0 == (u8)(arg0 & 0xff))
        {
            D_80332128--;
            if (i == 0)
            {
                if (D_80332128 != 0)
                {
                    SetMusic(0, D_80363818[1].unk0, 0);
                }
                else
                {
                    func_8031F7CC(0, 0x14);
                }
            }
            foundIndex = i;
            i = D_80332128;
        }
    }

    for (i = foundIndex; i < D_80332128; i++)
    {
        D_80363818[i].unk1 = D_80363818[i+1].unk1;
        D_80363818[i].unk0 = D_80363818[i+1].unk0;
    }
    D_80363818[i].unk1 = 0;
}

void func_80320E20(u16 arg0, u16 arg1)
{
    if (D_80332128 != 0 && D_80363818[0].unk0 == (u8)(arg0 & 0xff))
    {
        func_8031F7CC(0, arg1);
    }
}

void func_80320E74(void)
{
    if (D_80332128 != 0)
    {
        D_80332128 = 1;
    }
}

u16 func_80320E98(void)
{
    if (D_80332128 != 0)
    {
        return (D_80363818[0].unk1 << 8) + D_80363818[0].unk0;
    }
    return -1;
}

void func_80320ED8(void)
{
    if (D_80222A18[1].unk0b80 || D_8033211C == 0)
    {
        return;
    }

    D_8033211C = 0;
    func_803200E4(50);

    if (D_80363812 != 0 && (D_80332120 == 0x13 || D_80332120 == 0xb))
    {
        SetMusic(1, D_80332120, 1);
        if (D_80332124 != 0xff)
        {
            func_8031D838(1, 1, D_80332124);
        }
    }
}

void func_80320F84(u8 arg0, u8 arg1, u8 arg2, u16 arg3)
{
    UNUSED u32 dummy;

    D_80332118 = 0;
    if (D_8033209C == 0xff || D_8033209C == 2)
    {
        return;
    }

    if (D_80363812 == 0)
    {
        D_80363812 = arg1 + 0x80;
        func_803200E4(arg3);
        SetMusic(1, arg0, arg3 >> 1);
        if (arg2 < 0x80)
        {
            func_8031D838(1, arg3, arg2);
        }
        D_80332124 = arg2;
        D_80332120 = arg0;
    }
    else if (arg2 != 0xff)
    {
        D_80363812 = arg1 + 0x80;
        func_803200E4(arg3);
        func_8031D838(1, arg3, arg2);
        D_80332124 = arg2;
    }
}

void func_80321080(u16 arg0)
{
    if (D_80363812 != 0)
    {
        D_80363812 = 0;
        D_80332120 = 0;
        D_80332124 = 0;
        func_803200E4(arg0);
        func_8031F7CC(1, arg0);
    }
}

void func_803210D4(u16 arg0)
{
    u8 i;

    if (D_8033210C != 0)
    {
        return;
    }

    if (D_80222A18[0].unk0b80 == 1)
    {
        func_8031D630(0, arg0);
    }
    if (D_80222A18[1].unk0b80 == 1)
    {
        func_8031D630(1, arg0);
    }

    for (i = 0; i < 10; i++)
    {
        if (i != 7)
        {
            func_8031F888(2, i, 0, arg0 / 16);
        }
    }
    D_8033210C = 1;
}

void func_803211B0(void)
{
    SetMusic(1, 1, 0);
    D_8033211C = 0x80;
    func_803200E4(50);
}

void func_803211EC(void)
{
    SetMusic(1, 0x1d, 0);
    D_8033211C = 0x80;
    func_803200E4(50);
}

void func_80321228(void)
{
    SetMusic(1, 0x1b, 0);
    D_8033211C = 0x94;
    func_803200E4(50);
}

void func_80321264(void)
{
    SetMusic(1, 0x12, 0);
    D_8033211C = 0x94;
    func_803200E4(50);
}

void func_803212A0(u8 arg0)
{
    if (arg0 == 0)
    {
        D_80363812 = 0;
    }
    SetMusic(1, 0x15, 0);
    D_8033211C = 0x94;
    func_803200E4(50);
}

void func_803212F0(void)
{
    SetMusic(1, 0x14, 0);
    D_8033211C = 0x94;
    func_803200E4(50);
}

void func_8032132C(void)
{
    SetMusic(1, 0x1c, 0);
    D_8033211C = 0x94;
    func_803200E4(50);
}

void func_80321368(u8 arg0)
{
#ifndef VERSION_JP
    if (arg0 >= 8)
    {
        arg0 = 0;
        D_U_8033323C = 0;
    }
#endif
    D_80331D44 = 0;
    func_8032091C();
    func_803202A0();
    func_80316928(&D_80332190[arg0]);
    osWritebackDCacheAll();
    if (arg0 != 7)
    {
        func_80318178(0x1b, 3);
        func_80318178(0x1d, 3);
        func_80318178(0x15, 3);
    }
    SetMusic(2, 0, 0);
    D_80332108 = (D_80332108 & 0xf0) + arg0;
    D_80226D7F = D_80332108 >> 4;
    D_8033210C = 0;
}

void func_80321434(u16 arg0)
{
    D_80332108 = (D_80332108 & 0xf) + (arg0 << 4);
    D_80226D7F = arg0;
}

void Unknown80321460(UNUSED s32 arg0, UNUSED s32 arg1, UNUSED s32 arg2, UNUSED s32 arg3)
{
}

void Unknown80321474(UNUSED s32 arg0)
{
}
