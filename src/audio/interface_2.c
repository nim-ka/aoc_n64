#include <ultra64.h>

#include "sm64.h"
#include "interface_1.h"
#include "interface_2.h"
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
    u8 pad1[4];
    u32 unk14; // packed bits
    u8 unk18;
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

u32 D_8033212C[16] = {
    0x10000000, 0x10000000, 0x10000000, 0x10000000,
    0x10000000, 0x10000000, 0x10000000, 0x10000000,
    0x10000000, 0x10000000, 0x10000000, 0x10000000,
    0x10000000, 0x10000000, 0x10000000, 0x10000000
};
u8 D_8033216C[16] = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};
u8 D_8033217C[16] = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

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

#ifdef VERSION_JP
GLOBAL_ASM(
glabel func_8031E16C
/* 0D916C 8031E16C 27BDFF20 */  addiu $sp, $sp, -0xe0
/* 0D9170 8031E170 AFB00020 */  sw    $s0, 0x20($sp)
/* 0D9174 8031E174 3C0E8033 */  lui   $t6, %hi(D_8033212C) # $t6, 0x8033
/* 0D9178 8031E178 27B00098 */  addiu $s0, $sp, 0x98
/* 0D917C 8031E17C AFBE0040 */  sw    $fp, 0x40($sp)
/* 0D9180 8031E180 AFB7003C */  sw    $s7, 0x3c($sp)
/* 0D9184 8031E184 AFB3002C */  sw    $s3, 0x2c($sp)
/* 0D9188 8031E188 AFB10024 */  sw    $s1, 0x24($sp)
/* 0D918C 8031E18C 3C0B8036 */  lui   $t3, %hi(D_80360C48) # $t3, 0x8036
/* 0D9190 8031E190 25CE212C */  addiu $t6, %lo(D_8033212C) # addiu $t6, $t6, 0x212c
/* 0D9194 8031E194 256B0C48 */  addiu $t3, %lo(D_80360C48) # addiu $t3, $t3, 0xc48
/* 0D9198 8031E198 27B10078 */  addiu $s1, $sp, 0x78
/* 0D919C 8031E19C 27B30088 */  addiu $s3, $sp, 0x88
/* 0D91A0 8031E1A0 309700FF */  andi  $s7, $a0, 0xff
/* 0D91A4 8031E1A4 241E00FF */  li    $fp, 255
/* 0D91A8 8031E1A8 AFBF0044 */  sw    $ra, 0x44($sp)
/* 0D91AC 8031E1AC AFB60038 */  sw    $s6, 0x38($sp)
/* 0D91B0 8031E1B0 AFB50034 */  sw    $s5, 0x34($sp)
/* 0D91B4 8031E1B4 AFB40030 */  sw    $s4, 0x30($sp)
/* 0D91B8 8031E1B8 AFB20028 */  sw    $s2, 0x28($sp)
/* 0D91BC 8031E1BC F7B40018 */  sdc1  $f20, 0x18($sp)
/* 0D91C0 8031E1C0 AFA400E0 */  sw    $a0, 0xe0($sp)
/* 0D91C4 8031E1C4 25D9003C */  addiu $t9, $t6, 0x3c
/* 0D91C8 8031E1C8 02006825 */  move  $t5, $s0
.L8031E1CC:
/* 0D91CC 8031E1CC 8DC10000 */  lw    $at, ($t6)
/* 0D91D0 8031E1D0 25CE000C */  addiu $t6, $t6, 0xc
/* 0D91D4 8031E1D4 25AD000C */  addiu $t5, $t5, 0xc
/* 0D91D8 8031E1D8 ADA1FFF4 */  sw    $at, -0xc($t5)
/* 0D91DC 8031E1DC 8DC1FFF8 */  lw    $at, -8($t6)
/* 0D91E0 8031E1E0 ADA1FFF8 */  sw    $at, -8($t5)
/* 0D91E4 8031E1E4 8DC1FFFC */  lw    $at, -4($t6)
/* 0D91E8 8031E1E8 15D9FFF8 */  bne   $t6, $t9, .L8031E1CC
/* 0D91EC 8031E1EC ADA1FFFC */   sw    $at, -4($t5)
/* 0D91F0 8031E1F0 8DC10000 */  lw    $at, ($t6)
/* 0D91F4 8031E1F4 3C188033 */  lui   $t8, %hi(D_8033216C) # $t8, 0x8033
/* 0D91F8 8031E1F8 2718216C */  addiu $t8, %lo(D_8033216C) # addiu $t8, $t8, 0x216c
/* 0D91FC 8031E1FC ADA10000 */  sw    $at, ($t5)
/* 0D9200 8031E200 8F010000 */  lw    $at, ($t8)
/* 0D9204 8031E204 3C0D8033 */  lui   $t5, %hi(D_8033217C) 
/* 0D9208 8031E208 25AD217C */  addiu $t5, %lo(D_8033217C) # addiu $t5, $t5, 0x217c
/* 0D920C 8031E20C AE610000 */  sw    $at, ($s3)
/* 0D9210 8031E210 8F0E0004 */  lw    $t6, 4($t8)
/* 0D9214 8031E214 0017C8C0 */  sll   $t9, $s7, 3
/* 0D9218 8031E218 0337C821 */  addu  $t9, $t9, $s7
/* 0D921C 8031E21C AE6E0004 */  sw    $t6, 4($s3)
/* 0D9220 8031E220 8F010008 */  lw    $at, 8($t8)
/* 0D9224 8031E224 0019C880 */  sll   $t9, $t9, 2
/* 0D9228 8031E228 0337C823 */  subu  $t9, $t9, $s7
/* 0D922C 8031E22C AE610008 */  sw    $at, 8($s3)
/* 0D9230 8031E230 8F0E000C */  lw    $t6, 0xc($t8)
/* 0D9234 8031E234 0019C940 */  sll   $t9, $t9, 5
/* 0D9238 8031E238 01796021 */  addu  $t4, $t3, $t9
/* 0D923C 8031E23C AE6E000C */  sw    $t6, 0xc($s3)
/* 0D9240 8031E240 8DA10000 */  lw    $at, ($t5)
/* 0D9244 8031E244 001770C0 */  sll   $t6, $s7, 3
/* 0D9248 8031E248 01D77021 */  addu  $t6, $t6, $s7
/* 0D924C 8031E24C AE210000 */  sw    $at, ($s1)
/* 0D9250 8031E250 8DB80004 */  lw    $t8, 4($t5)
/* 0D9254 8031E254 000E7080 */  sll   $t6, $t6, 2
/* 0D9258 8031E258 01D77023 */  subu  $t6, $t6, $s7
/* 0D925C 8031E25C AE380004 */  sw    $t8, 4($s1)
/* 0D9260 8031E260 8DA10008 */  lw    $at, 8($t5)
/* 0D9264 8031E264 000E7140 */  sll   $t6, $t6, 5
/* 0D9268 8031E268 016E7821 */  addu  $t7, $t3, $t6
/* 0D926C 8031E26C AE210008 */  sw    $at, 8($s1)
/* 0D9270 8031E270 8DB8000C */  lw    $t8, 0xc($t5)
/* 0D9274 8031E274 91F4001B */  lbu   $s4, 0x1b($t7)
/* 0D9278 8031E278 3C014018 */  li    $at, 0x40180000 # 2.375000
/* 0D927C 8031E27C AE38000C */  sw    $t8, 0xc($s1)
/* 0D9280 8031E280 A3A00077 */  sb    $zero, 0x77($sp)
/* 0D9284 8031E284 13D40118 */  beq   $fp, $s4, .L8031E6E8
/* 0D9288 8031E288 02809025 */   move  $s2, $s4
/* 0D928C 8031E28C 4481A800 */  mtc1  $at, $f21
/* 0D9290 8031E290 4480A000 */  mtc1  $zero, $f20
/* 0D9294 8031E294 240A001C */  li    $t2, 28
.L8031E298:
/* 0D9298 8031E298 028A0019 */  multu $s4, $t2
/* 0D929C 8031E29C 24010081 */  li    $at, 129
/* 0D92A0 8031E2A0 A3B400DB */  sb    $s4, 0xdb($sp)
/* 0D92A4 8031E2A4 00006812 */  mflo  $t5
/* 0D92A8 8031E2A8 018DA821 */  addu  $s5, $t4, $t5
/* 0D92AC 8031E2AC 8EA20014 */  lw    $v0, 0x14($s5)
/* 0D92B0 8031E2B0 3058008F */  andi  $t8, $v0, 0x8f
/* 0D92B4 8031E2B4 17010008 */  bne   $t8, $at, .L8031E2D8
/* 0D92B8 8031E2B8 304F0080 */   andi  $t7, $v0, 0x80
/* 0D92BC 8031E2BC 92A20019 */  lbu   $v0, 0x19($s5)
/* 0D92C0 8031E2C0 2C430001 */  sltiu $v1, $v0, 1
/* 0D92C4 8031E2C4 244EFFFF */  addiu $t6, $v0, -1
/* 0D92C8 8031E2C8 10600013 */  beqz  $v1, .L8031E318
/* 0D92CC 8031E2CC A2AE0019 */   sb    $t6, 0x19($s5)
/* 0D92D0 8031E2D0 10000011 */  b     .L8031E318
/* 0D92D4 8031E2D4 AEA00014 */   sw    $zero, 0x14($s5)
.L8031E2D8:
/* 0D92D8 8031E2D8 55E00010 */  bnezl $t7, .L8031E31C
/* 0D92DC 8031E2DC 8EAD0014 */   lw    $t5, 0x14($s5)
/* 0D92E0 8031E2E0 92A20019 */  lbu   $v0, 0x19($s5)
/* 0D92E4 8031E2E4 32E400FF */  andi  $a0, $s7, 0xff
/* 0D92E8 8031E2E8 328500FF */  andi  $a1, $s4, 0xff
/* 0D92EC 8031E2EC 38430008 */  xori  $v1, $v0, 8
/* 0D92F0 8031E2F0 2459FFFF */  addiu $t9, $v0, -1
/* 0D92F4 8031E2F4 14600008 */  bnez  $v1, .L8031E318
/* 0D92F8 8031E2F8 A2B90019 */   sb    $t9, 0x19($s5)
/* 0D92FC 8031E2FC 0C0C7839 */  jal   func_8031E0E4
/* 0D9300 8031E300 AFAC0068 */   sw    $t4, 0x68($sp)
/* 0D9304 8031E304 3C0B8036 */  lui   $t3, %hi(D_80360C48) # $t3, 0x8036
/* 0D9308 8031E308 256B0C48 */  addiu $t3, %lo(D_80360C48) # addiu $t3, $t3, 0xc48
/* 0D930C 8031E30C 240A001C */  li    $t2, 28
/* 0D9310 8031E310 8FAC0068 */  lw    $t4, 0x68($sp)
/* 0D9314 8031E314 AEA00014 */  sw    $zero, 0x14($s5)
.L8031E318:
/* 0D9318 8031E318 8EAD0014 */  lw    $t5, 0x14($s5)
.L8031E31C:
/* 0D931C 8031E31C 55A00010 */  bnezl $t5, .L8031E360
/* 0D9320 8031E320 92AF0018 */   lbu   $t7, 0x18($s5)
/* 0D9324 8031E324 92B80018 */  lbu   $t8, 0x18($s5)
/* 0D9328 8031E328 24010001 */  li    $at, 1
/* 0D932C 8031E32C 32E400FF */  andi  $a0, $s7, 0xff
/* 0D9330 8031E330 1701000A */  bne   $t8, $at, .L8031E35C
/* 0D9334 8031E334 328500FF */   andi  $a1, $s4, 0xff
/* 0D9338 8031E338 92AE001A */  lbu   $t6, 0x1a($s5)
/* 0D933C 8031E33C A2A00018 */  sb    $zero, 0x18($s5)
/* 0D9340 8031E340 AFAC0068 */  sw    $t4, 0x68($sp)
/* 0D9344 8031E344 0C0C77FA */  jal   func_8031DFE8
/* 0D9348 8031E348 A3AE00DB */   sb    $t6, 0xdb($sp)
/* 0D934C 8031E34C 3C0B8036 */  lui   $t3, %hi(D_80360C48) # $t3, 0x8036
/* 0D9350 8031E350 256B0C48 */  addiu $t3, %lo(D_80360C48) # addiu $t3, $t3, 0xc48
/* 0D9354 8031E354 240A001C */  li    $t2, 28
/* 0D9358 8031E358 8FAC0068 */  lw    $t4, 0x68($sp)
.L8031E35C:
/* 0D935C 8031E35C 92AF0018 */  lbu   $t7, 0x18($s5)
.L8031E360:
/* 0D9360 8031E360 93B900DB */  lbu   $t9, 0xdb($sp)
/* 0D9364 8031E364 51E000DA */  beql  $t7, $zero, .L8031E6D0
/* 0D9368 8031E368 93B900DB */   lbu   $t9, 0xdb($sp)
/* 0D936C 8031E36C 573200D8 */  bnel  $t9, $s2, .L8031E6D0
/* 0D9370 8031E370 93B900DB */   lbu   $t9, 0xdb($sp)
/* 0D9374 8031E374 8EB80000 */  lw    $t8, ($s5)
/* 0D9378 8031E378 8EAE0004 */  lw    $t6, 4($s5)
/* 0D937C 8031E37C 8EAD0008 */  lw    $t5, 8($s5)
/* 0D9380 8031E380 C7020000 */  lwc1  $f2, ($t8)
/* 0D9384 8031E384 C5CE0000 */  lwc1  $f14, ($t6)
/* 0D9388 8031E388 C5A00000 */  lwc1  $f0, ($t5)
/* 0D938C 8031E38C 46021102 */  mul.s $f4, $f2, $f2
/* 0D9390 8031E390 3C0F8033 */  lui   $t7, %hi(D_803320C8) 
/* 0D9394 8031E394 25EF20C8 */  addiu $t7, %lo(D_803320C8) # addiu $t7, $t7, 0x20c8
/* 0D9398 8031E398 460E7182 */  mul.s $f6, $f14, $f14
/* 0D939C 8031E39C 02EFB021 */  addu  $s6, $s7, $t7
/* 0D93A0 8031E3A0 AFAC0068 */  sw    $t4, 0x68($sp)
/* 0D93A4 8031E3A4 46000282 */  mul.s $f10, $f0, $f0
/* 0D93A8 8031E3A8 00009025 */  move  $s2, $zero
/* 0D93AC 8031E3AC 46062200 */  add.s $f8, $f4, $f6
/* 0D93B0 8031E3B0 0C0C8AC8 */  jal   sqrtf
/* 0D93B4 8031E3B4 46085300 */   add.s $f12, $f10, $f8
/* 0D93B8 8031E3B8 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0D93BC 8031E3BC 44818000 */  mtc1  $at, $f16
/* 0D93C0 8031E3C0 8EA20014 */  lw    $v0, 0x14($s5)
/* 0D93C4 8031E3C4 3C0B8036 */  lui   $t3, %hi(D_80360C48) 
/* 0D93C8 8031E3C8 46100482 */  mul.s $f18, $f0, $f16
/* 0D93CC 8031E3CC 3043FF00 */  andi  $v1, $v0, 0xff00
/* 0D93D0 8031E3D0 0003CA02 */  srl   $t9, $v1, 8
/* 0D93D4 8031E3D4 332D00FF */  andi  $t5, $t9, 0xff
/* 0D93D8 8031E3D8 0002C140 */  sll   $t8, $v0, 5
/* 0D93DC 8031E3DC 256B0C48 */  addiu $t3, %lo(D_80360C48) # addiu $t3, $t3, 0xc48
/* 0D93E0 8031E3E0 240A001C */  li    $t2, 28
/* 0D93E4 8031E3E4 E6B2000C */  swc1  $f18, 0xc($s5)
/* 0D93E8 8031E3E8 8FAC0068 */  lw    $t4, 0x68($sp)
/* 0D93EC 8031E3EC 07010009 */  bgez  $t8, .L8031E414
/* 0D93F0 8031E3F0 01A01825 */   move  $v1, $t5
/* 0D93F4 8031E3F4 03CD7023 */  subu  $t6, $fp, $t5
/* 0D93F8 8031E3F8 000E7880 */  sll   $t7, $t6, 2
/* 0D93FC 8031E3FC 01EE7821 */  addu  $t7, $t7, $t6
/* 0D9400 8031E400 000F7880 */  sll   $t7, $t7, 2
/* 0D9404 8031E404 01EE7823 */  subu  $t7, $t7, $t6
/* 0D9408 8031E408 000F7880 */  sll   $t7, $t7, 2
/* 0D940C 8031E40C 1000007E */  b     .L8031E608
/* 0D9410 8031E410 AEAF0010 */   sw    $t7, 0x10($s5)
.L8031E414:
/* 0D9414 8031E414 8EB90008 */  lw    $t9, 8($s5)
/* 0D9418 8031E418 44802000 */  mtc1  $zero, $f4
/* 0D941C 8031E41C 240D0001 */  li    $t5, 1
/* 0D9420 8031E420 C7200000 */  lwc1  $f0, ($t9)
/* 0D9424 8031E424 03C3C823 */  subu  $t9, $fp, $v1
/* 0D9428 8031E428 00197080 */  sll   $t6, $t9, 2
/* 0D942C 8031E42C 4600203C */  c.lt.s $f4, $f0
/* 0D9430 8031E430 01D97021 */  addu  $t6, $t6, $t9
/* 0D9434 8031E434 000E7080 */  sll   $t6, $t6, 2
/* 0D9438 8031E438 01D97023 */  subu  $t6, $t6, $t9
/* 0D943C 8031E43C 45000050 */  bc1f  .L8031E580
/* 0D9440 8031E440 000E7080 */   sll   $t6, $t6, 2
/* 0D9444 8031E444 460001A1 */  cvt.d.s $f6, $f0
/* 0D9448 8031E448 24180001 */  li    $t8, 1
/* 0D944C 8031E44C 46343283 */  div.d $f10, $f6, $f20
/* 0D9450 8031E450 3C0141E0 */  li    $at, 0x41E00000 # 28.000000
/* 0D9454 8031E454 444DF800 */  cfc1  $t5, $31
/* 0D9458 8031E458 44D8F800 */  ctc1  $t8, $31
/* 0D945C 8031E45C 00000000 */  nop   
/* 0D9460 8031E460 46205224 */  cvt.w.d $f8, $f10
/* 0D9464 8031E464 4458F800 */  cfc1  $t8, $31
/* 0D9468 8031E468 00000000 */  nop   
/* 0D946C 8031E46C 33180078 */  andi  $t8, $t8, 0x78
/* 0D9470 8031E470 53000014 */  beql  $t8, $zero, .L8031E4C4
/* 0D9474 8031E474 44184000 */   mfc1  $t8, $f8
/* 0D9478 8031E478 44814800 */  mtc1  $at, $f9
/* 0D947C 8031E47C 44804000 */  mtc1  $zero, $f8
/* 0D9480 8031E480 24180001 */  li    $t8, 1
/* 0D9484 8031E484 46285201 */  sub.d $f8, $f10, $f8
/* 0D9488 8031E488 44D8F800 */  ctc1  $t8, $31
/* 0D948C 8031E48C 00000000 */  nop   
/* 0D9490 8031E490 46204224 */  cvt.w.d $f8, $f8
/* 0D9494 8031E494 4458F800 */  cfc1  $t8, $31
/* 0D9498 8031E498 00000000 */  nop   
/* 0D949C 8031E49C 33180078 */  andi  $t8, $t8, 0x78
/* 0D94A0 8031E4A0 17000005 */  bnez  $t8, .L8031E4B8
/* 0D94A4 8031E4A4 00000000 */   nop   
/* 0D94A8 8031E4A8 44184000 */  mfc1  $t8, $f8
/* 0D94AC 8031E4AC 3C018000 */  lui   $at, 0x8000
/* 0D94B0 8031E4B0 10000007 */  b     .L8031E4D0
/* 0D94B4 8031E4B4 0301C025 */   or    $t8, $t8, $at
.L8031E4B8:
/* 0D94B8 8031E4B8 10000005 */  b     .L8031E4D0
/* 0D94BC 8031E4BC 2418FFFF */   li    $t8, -1
/* 0D94C0 8031E4C0 44184000 */  mfc1  $t8, $f8
.L8031E4C4:
/* 0D94C4 8031E4C4 00000000 */  nop   
/* 0D94C8 8031E4C8 0700FFFB */  bltz  $t8, .L8031E4B8
/* 0D94CC 8031E4CC 00000000 */   nop   
.L8031E4D0:
/* 0D94D0 8031E4D0 44CDF800 */  ctc1  $t5, $31
/* 0D94D4 8031E4D4 240F0001 */  li    $t7, 1
/* 0D94D8 8031E4D8 C6B0000C */  lwc1  $f16, 0xc($s5)
/* 0D94DC 8031E4DC 03C36823 */  subu  $t5, $fp, $v1
/* 0D94E0 8031E4E0 444EF800 */  cfc1  $t6, $31
/* 0D94E4 8031E4E4 44CFF800 */  ctc1  $t7, $31
/* 0D94E8 8031E4E8 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0D94EC 8031E4EC 460084A4 */  cvt.w.s $f18, $f16
/* 0D94F0 8031E4F0 444FF800 */  cfc1  $t7, $31
/* 0D94F4 8031E4F4 00000000 */  nop   
/* 0D94F8 8031E4F8 31EF0078 */  andi  $t7, $t7, 0x78
/* 0D94FC 8031E4FC 51E00013 */  beql  $t7, $zero, .L8031E54C
/* 0D9500 8031E500 440F9000 */   mfc1  $t7, $f18
/* 0D9504 8031E504 44819000 */  mtc1  $at, $f18
/* 0D9508 8031E508 240F0001 */  li    $t7, 1
/* 0D950C 8031E50C 46128481 */  sub.s $f18, $f16, $f18
/* 0D9510 8031E510 44CFF800 */  ctc1  $t7, $31
/* 0D9514 8031E514 00000000 */  nop   
/* 0D9518 8031E518 460094A4 */  cvt.w.s $f18, $f18
/* 0D951C 8031E51C 444FF800 */  cfc1  $t7, $31
/* 0D9520 8031E520 00000000 */  nop   
/* 0D9524 8031E524 31EF0078 */  andi  $t7, $t7, 0x78
/* 0D9528 8031E528 15E00005 */  bnez  $t7, .L8031E540
/* 0D952C 8031E52C 00000000 */   nop   
/* 0D9530 8031E530 440F9000 */  mfc1  $t7, $f18
/* 0D9534 8031E534 3C018000 */  lui   $at, 0x8000
/* 0D9538 8031E538 10000007 */  b     .L8031E558
/* 0D953C 8031E53C 01E17825 */   or    $t7, $t7, $at
.L8031E540:
/* 0D9540 8031E540 10000005 */  b     .L8031E558
/* 0D9544 8031E544 240FFFFF */   li    $t7, -1
/* 0D9548 8031E548 440F9000 */  mfc1  $t7, $f18
.L8031E54C:
/* 0D954C 8031E54C 00000000 */  nop   
/* 0D9550 8031E550 05E0FFFB */  bltz  $t7, .L8031E540
/* 0D9554 8031E554 00000000 */   nop   
.L8031E558:
/* 0D9558 8031E558 44CEF800 */  ctc1  $t6, $31
/* 0D955C 8031E55C 000D7080 */  sll   $t6, $t5, 2
/* 0D9560 8031E560 01CD7021 */  addu  $t6, $t6, $t5
/* 0D9564 8031E564 000E7080 */  sll   $t6, $t6, 2
/* 0D9568 8031E568 01CD7023 */  subu  $t6, $t6, $t5
/* 0D956C 8031E56C 000E7080 */  sll   $t6, $t6, 2
/* 0D9570 8031E570 030FC821 */  addu  $t9, $t8, $t7
/* 0D9574 8031E574 032EC021 */  addu  $t8, $t9, $t6
/* 0D9578 8031E578 10000023 */  b     .L8031E608
/* 0D957C 8031E57C AEB80010 */   sw    $t8, 0x10($s5)
.L8031E580:
/* 0D9580 8031E580 444FF800 */  cfc1  $t7, $31
/* 0D9584 8031E584 44CDF800 */  ctc1  $t5, $31
/* 0D9588 8031E588 C6A4000C */  lwc1  $f4, 0xc($s5)
/* 0D958C 8031E58C 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0D9590 8031E590 460021A4 */  cvt.w.s $f6, $f4
/* 0D9594 8031E594 444DF800 */  cfc1  $t5, $31
/* 0D9598 8031E598 00000000 */  nop   
/* 0D959C 8031E59C 31AD0078 */  andi  $t5, $t5, 0x78
/* 0D95A0 8031E5A0 51A00013 */  beql  $t5, $zero, .L8031E5F0
/* 0D95A4 8031E5A4 440D3000 */   mfc1  $t5, $f6
/* 0D95A8 8031E5A8 44813000 */  mtc1  $at, $f6
/* 0D95AC 8031E5AC 240D0001 */  li    $t5, 1
/* 0D95B0 8031E5B0 46062181 */  sub.s $f6, $f4, $f6
/* 0D95B4 8031E5B4 44CDF800 */  ctc1  $t5, $31
/* 0D95B8 8031E5B8 00000000 */  nop   
/* 0D95BC 8031E5BC 460031A4 */  cvt.w.s $f6, $f6
/* 0D95C0 8031E5C0 444DF800 */  cfc1  $t5, $31
/* 0D95C4 8031E5C4 00000000 */  nop   
/* 0D95C8 8031E5C8 31AD0078 */  andi  $t5, $t5, 0x78
/* 0D95CC 8031E5CC 15A00005 */  bnez  $t5, .L8031E5E4
/* 0D95D0 8031E5D0 00000000 */   nop   
/* 0D95D4 8031E5D4 440D3000 */  mfc1  $t5, $f6
/* 0D95D8 8031E5D8 3C018000 */  lui   $at, 0x8000
/* 0D95DC 8031E5DC 10000007 */  b     .L8031E5FC
/* 0D95E0 8031E5E0 01A16825 */   or    $t5, $t5, $at
.L8031E5E4:
/* 0D95E4 8031E5E4 10000005 */  b     .L8031E5FC
/* 0D95E8 8031E5E8 240DFFFF */   li    $t5, -1
/* 0D95EC 8031E5EC 440D3000 */  mfc1  $t5, $f6
.L8031E5F0:
/* 0D95F0 8031E5F0 00000000 */  nop   
/* 0D95F4 8031E5F4 05A0FFFB */  bltz  $t5, .L8031E5E4
/* 0D95F8 8031E5F8 00000000 */   nop   
.L8031E5FC:
/* 0D95FC 8031E5FC 44CFF800 */  ctc1  $t7, $31
/* 0D9600 8031E600 01AEC021 */  addu  $t8, $t5, $t6
/* 0D9604 8031E604 AEB80010 */  sw    $t8, 0x10($s5)
.L8031E608:
/* 0D9608 8031E608 92C90000 */  lbu   $t1, ($s6)
/* 0D960C 8031E60C 1920002C */  blez  $t1, .L8031E6C0
/* 0D9610 8031E610 01203825 */   move  $a3, $t1
/* 0D9614 8031E614 8EA80010 */  lw    $t0, 0x10($s5)
.L8031E618:
/* 0D9618 8031E618 00127880 */  sll   $t7, $s2, 2
/* 0D961C 8031E61C 020F3021 */  addu  $a2, $s0, $t7
/* 0D9620 8031E620 8CD90000 */  lw    $t9, ($a2)
/* 0D9624 8031E624 24E2FFFF */  addiu $v0, $a3, -1
/* 0D9628 8031E628 304300FF */  andi  $v1, $v0, 0xff
/* 0D962C 8031E62C 0328082B */  sltu  $at, $t9, $t0
/* 0D9630 8031E630 1420001E */  bnez  $at, .L8031E6AC
/* 0D9634 8031E634 00601025 */   move  $v0, $v1
/* 0D9638 8031E638 0243082A */  slt   $at, $s2, $v1
/* 0D963C 8031E63C 02402025 */  move  $a0, $s2
/* 0D9640 8031E640 10200014 */  beqz  $at, .L8031E694
/* 0D9644 8031E644 92A50018 */   lbu   $a1, 0x18($s5)
.L8031E648:
/* 0D9648 8031E648 00037080 */  sll   $t6, $v1, 2
/* 0D964C 8031E64C 020EC021 */  addu  $t8, $s0, $t6
/* 0D9650 8031E650 8F0FFFFC */  lw    $t7, -4($t8)
/* 0D9654 8031E654 0002C880 */  sll   $t9, $v0, 2
/* 0D9658 8031E658 02196821 */  addu  $t5, $s0, $t9
/* 0D965C 8031E65C 02637021 */  addu  $t6, $s3, $v1
/* 0D9660 8031E660 ADAF0000 */  sw    $t7, ($t5)
/* 0D9664 8031E664 91D8FFFF */  lbu   $t8, -1($t6)
/* 0D9668 8031E668 0262C821 */  addu  $t9, $s3, $v0
/* 0D966C 8031E66C 02227021 */  addu  $t6, $s1, $v0
/* 0D9670 8031E670 02237821 */  addu  $t7, $s1, $v1
/* 0D9674 8031E674 2442FFFF */  addiu $v0, $v0, -1
/* 0D9678 8031E678 A3380000 */  sb    $t8, ($t9)
/* 0D967C 8031E67C 91EDFFFF */  lbu   $t5, -1($t7)
/* 0D9680 8031E680 304300FF */  andi  $v1, $v0, 0xff
/* 0D9684 8031E684 0083082A */  slt   $at, $a0, $v1
/* 0D9688 8031E688 00601025 */  move  $v0, $v1
/* 0D968C 8031E68C 1420FFEE */  bnez  $at, .L8031E648
/* 0D9690 8031E690 A1CD0000 */   sb    $t5, ($t6)
.L8031E694:
/* 0D9694 8031E694 0272C821 */  addu  $t9, $s3, $s2
/* 0D9698 8031E698 02327821 */  addu  $t7, $s1, $s2
/* 0D969C 8031E69C A3340000 */  sb    $s4, ($t9)
/* 0D96A0 8031E6A0 ACC80000 */  sw    $t0, ($a2)
/* 0D96A4 8031E6A4 A1E50000 */  sb    $a1, ($t7)
/* 0D96A8 8031E6A8 313200FF */  andi  $s2, $t1, 0xff
.L8031E6AC:
/* 0D96AC 8031E6AC 26520001 */  addiu $s2, $s2, 1
/* 0D96B0 8031E6B0 324D00FF */  andi  $t5, $s2, 0xff
/* 0D96B4 8031E6B4 01A7082A */  slt   $at, $t5, $a3
/* 0D96B8 8031E6B8 1420FFD7 */  bnez  $at, .L8031E618
/* 0D96BC 8031E6BC 01A09025 */   move  $s2, $t5
.L8031E6C0:
/* 0D96C0 8031E6C0 93AE0077 */  lbu   $t6, 0x77($sp)
/* 0D96C4 8031E6C4 25D80001 */  addiu $t8, $t6, 1
/* 0D96C8 8031E6C8 A3B80077 */  sb    $t8, 0x77($sp)
/* 0D96CC 8031E6CC 93B900DB */  lbu   $t9, 0xdb($sp)
.L8031E6D0:
/* 0D96D0 8031E6D0 032A0019 */  multu $t9, $t2
/* 0D96D4 8031E6D4 00007812 */  mflo  $t7
/* 0D96D8 8031E6D8 018F6821 */  addu  $t5, $t4, $t7
/* 0D96DC 8031E6DC 91B4001B */  lbu   $s4, 0x1b($t5)
/* 0D96E0 8031E6E0 17D4FEED */  bne   $fp, $s4, .L8031E298
/* 0D96E4 8031E6E4 02809025 */   move  $s2, $s4
.L8031E6E8:
/* 0D96E8 8031E6E8 3C198033 */  lui   $t9, %hi(D_803320C8)
/* 0D96EC 8031E6EC 0337C821 */  addu  $t9, $t9, $s7
/* 0D96F0 8031E6F0 93AE0077 */  lbu   $t6, 0x77($sp)
/* 0D96F4 8031E6F4 933920C8 */  lbu   $t9, %lo(D_803320C8)($t9)
/* 0D96F8 8031E6F8 3C018033 */  lui   $at, %hi(D_803320BC)
/* 0D96FC 8031E6FC 3C188036 */  lui   $t8, %hi(D_80360C28) # $t8, 0x8036
/* 0D9700 8031E700 00370821 */  addu  $at, $at, $s7
/* 0D9704 8031E704 27180C28 */  addiu $t8, %lo(D_80360C28) # addiu $t8, $t8, 0xc28
/* 0D9708 8031E708 02F83021 */  addu  $a2, $s7, $t8
/* 0D970C 8031E70C A02E20BC */  sb    $t6, %lo(D_803320BC)($at)
/* 0D9710 8031E710 332700FF */  andi  $a3, $t9, 0xff
/* 0D9714 8031E714 240A001C */  li    $t2, 28
/* 0D9718 8031E718 00009025 */  move  $s2, $zero
/* 0D971C 8031E71C 18E0005D */  blez  $a3, .L8031E894
/* 0D9720 8031E720 A0D90000 */   sb    $t9, ($a2)
/* 0D9724 8031E724 3C168036 */  lui   $s6, %hi(D_80360C38) # $s6, 0x8036
/* 0D9728 8031E728 26D60C38 */  addiu $s6, %lo(D_80360C38) # addiu $s6, $s6, 0xc38
/* 0D972C 8031E72C 241500FF */  li    $s5, 255
.L8031E730:
/* 0D9730 8031E730 18E00011 */  blez  $a3, .L8031E778
/* 0D9734 8031E734 0000A025 */   move  $s4, $zero
.L8031E738:
/* 0D9738 8031E738 02742021 */  addu  $a0, $s3, $s4
/* 0D973C 8031E73C 90820000 */  lbu   $v0, ($a0)
/* 0D9740 8031E740 02D77821 */  addu  $t7, $s6, $s7
/* 0D9744 8031E744 01F26821 */  addu  $t5, $t7, $s2
/* 0D9748 8031E748 53C20007 */  beql  $fp, $v0, .L8031E768
/* 0D974C 8031E74C 26940001 */   addiu $s4, $s4, 1
/* 0D9750 8031E750 91AE0000 */  lbu   $t6, ($t5)
/* 0D9754 8031E754 55C20004 */  bnel  $t6, $v0, .L8031E768
/* 0D9758 8031E758 26940001 */   addiu $s4, $s4, 1
/* 0D975C 8031E75C A0950000 */  sb    $s5, ($a0)
/* 0D9760 8031E760 241400FE */  li    $s4, 254
/* 0D9764 8031E764 26940001 */  addiu $s4, $s4, 1
.L8031E768:
/* 0D9768 8031E768 329800FF */  andi  $t8, $s4, 0xff
/* 0D976C 8031E76C 0307082A */  slt   $at, $t8, $a3
/* 0D9770 8031E770 1420FFF1 */  bnez  $at, .L8031E738
/* 0D9774 8031E774 0300A025 */   move  $s4, $t8
.L8031E778:
/* 0D9778 8031E778 13D40041 */  beq   $fp, $s4, .L8031E880
/* 0D977C 8031E77C 02D7C821 */   addu  $t9, $s6, $s7
/* 0D9780 8031E780 03328021 */  addu  $s0, $t9, $s2
/* 0D9784 8031E784 92140000 */  lbu   $s4, ($s0)
/* 0D9788 8031E788 53D4003D */  beql  $fp, $s4, .L8031E880
/* 0D978C 8031E78C A2150000 */   sb    $s5, ($s0)
/* 0D9790 8031E790 028A0019 */  multu $s4, $t2
/* 0D9794 8031E794 001778C0 */  sll   $t7, $s7, 3
/* 0D9798 8031E798 01F77821 */  addu  $t7, $t7, $s7
/* 0D979C 8031E79C 000F7880 */  sll   $t7, $t7, 2
/* 0D97A0 8031E7A0 01F77823 */  subu  $t7, $t7, $s7
/* 0D97A4 8031E7A4 000F7940 */  sll   $t7, $t7, 5
/* 0D97A8 8031E7A8 016F6021 */  addu  $t4, $t3, $t7
/* 0D97AC 8031E7AC 00006812 */  mflo  $t5
/* 0D97B0 8031E7B0 018D8821 */  addu  $s1, $t4, $t5
/* 0D97B4 8031E7B4 8E220014 */  lw    $v0, 0x14($s1)
/* 0D97B8 8031E7B8 54400016 */  bnezl $v0, .L8031E814
/* 0D97BC 8031E7BC 3043008F */   andi  $v1, $v0, 0x8f
/* 0D97C0 8031E7C0 922E0018 */  lbu   $t6, 0x18($s1)
/* 0D97C4 8031E7C4 24010002 */  li    $at, 2
/* 0D97C8 8031E7C8 32E400FF */  andi  $a0, $s7, 0xff
/* 0D97CC 8031E7CC 15C10010 */  bne   $t6, $at, .L8031E810
/* 0D97D0 8031E7D0 328500FF */   andi  $a1, $s4, 0xff
/* 0D97D4 8031E7D4 A2200018 */  sb    $zero, 0x18($s1)
/* 0D97D8 8031E7D8 AFA6006C */  sw    $a2, 0x6c($sp)
/* 0D97DC 8031E7DC 0C0C77FA */  jal   func_8031DFE8
/* 0D97E0 8031E7E0 AFAC0068 */   sw    $t4, 0x68($sp)
/* 0D97E4 8031E7E4 92140000 */  lbu   $s4, ($s0)
/* 0D97E8 8031E7E8 8FAC0068 */  lw    $t4, 0x68($sp)
/* 0D97EC 8031E7EC 3C0B8036 */  lui   $t3, %hi(D_80360C48) # $t3, 0x8036
/* 0D97F0 8031E7F0 0014C0C0 */  sll   $t8, $s4, 3
/* 0D97F4 8031E7F4 0314C023 */  subu  $t8, $t8, $s4
/* 0D97F8 8031E7F8 0018C080 */  sll   $t8, $t8, 2
/* 0D97FC 8031E7FC 01988821 */  addu  $s1, $t4, $t8
/* 0D9800 8031E800 8E220014 */  lw    $v0, 0x14($s1)
/* 0D9804 8031E804 256B0C48 */  addiu $t3, %lo(D_80360C48) # addiu $t3, $t3, 0xc48
/* 0D9808 8031E808 8FA6006C */  lw    $a2, 0x6c($sp)
/* 0D980C 8031E80C 240A001C */  li    $t2, 28
.L8031E810:
/* 0D9810 8031E810 3043008F */  andi  $v1, $v0, 0x8f
.L8031E814:
/* 0D9814 8031E814 2C610082 */  sltiu $at, $v1, 0x82
/* 0D9818 8031E818 54200011 */  bnezl $at, .L8031E860
/* 0D981C 8031E81C 24010002 */   li    $at, 2
/* 0D9820 8031E820 92390018 */  lbu   $t9, 0x18($s1)
/* 0D9824 8031E824 32E400FF */  andi  $a0, $s7, 0xff
/* 0D9828 8031E828 328500FF */  andi  $a1, $s4, 0xff
/* 0D982C 8031E82C 5320000C */  beql  $t9, $zero, .L8031E860
/* 0D9830 8031E830 24010002 */   li    $at, 2
/* 0D9834 8031E834 AE200014 */  sw    $zero, 0x14($s1)
/* 0D9838 8031E838 A2200018 */  sb    $zero, 0x18($s1)
/* 0D983C 8031E83C 0C0C77FA */  jal   func_8031DFE8
/* 0D9840 8031E840 AFA6006C */   sw    $a2, 0x6c($sp)
/* 0D9844 8031E844 8FA6006C */  lw    $a2, 0x6c($sp)
/* 0D9848 8031E848 3C0B8036 */  lui   $t3, %hi(D_80360C48) # $t3, 0x8036
/* 0D984C 8031E84C 256B0C48 */  addiu $t3, %lo(D_80360C48) # addiu $t3, $t3, 0xc48
/* 0D9850 8031E850 240A001C */  li    $t2, 28
/* 0D9854 8031E854 10000009 */  b     .L8031E87C
/* 0D9858 8031E858 90C70000 */   lbu   $a3, ($a2)
/* 0D985C 8031E85C 24010002 */  li    $at, 2
.L8031E860:
/* 0D9860 8031E860 14610006 */  bne   $v1, $at, .L8031E87C
/* 0D9864 8031E864 90C70000 */   lbu   $a3, ($a2)
/* 0D9868 8031E868 922F0018 */  lbu   $t7, 0x18($s1)
/* 0D986C 8031E86C 240D0001 */  li    $t5, 1
/* 0D9870 8031E870 51E00003 */  beql  $t7, $zero, .L8031E880
/* 0D9874 8031E874 A2150000 */   sb    $s5, ($s0)
/* 0D9878 8031E878 A22D0018 */  sb    $t5, 0x18($s1)
.L8031E87C:
/* 0D987C 8031E87C A2150000 */  sb    $s5, ($s0)
.L8031E880:
/* 0D9880 8031E880 26520001 */  addiu $s2, $s2, 1
/* 0D9884 8031E884 324E00FF */  andi  $t6, $s2, 0xff
/* 0D9888 8031E888 01C7082A */  slt   $at, $t6, $a3
/* 0D988C 8031E88C 1420FFA8 */  bnez  $at, .L8031E730
/* 0D9890 8031E890 01C09025 */   move  $s2, $t6
.L8031E894:
/* 0D9894 8031E894 241500FF */  li    $s5, 255
/* 0D9898 8031E898 18E0002B */  blez  $a3, .L8031E948
/* 0D989C 8031E89C 0000A025 */   move  $s4, $zero
/* 0D98A0 8031E8A0 2406FFF0 */  li    $a2, -16
.L8031E8A4:
/* 0D98A4 8031E8A4 02742021 */  addu  $a0, $s3, $s4
/* 0D98A8 8031E8A8 90980000 */  lbu   $t8, ($a0)
/* 0D98AC 8031E8AC 26940001 */  addiu $s4, $s4, 1
/* 0D98B0 8031E8B0 53D80022 */  beql  $fp, $t8, .L8031E93C
/* 0D98B4 8031E8B4 329900FF */   andi  $t9, $s4, 0xff
/* 0D98B8 8031E8B8 18E0001F */  blez  $a3, .L8031E938
/* 0D98BC 8031E8BC 00009025 */   move  $s2, $zero
/* 0D98C0 8031E8C0 3C198036 */  lui   $t9, %hi(D_80360C38) # $t9, 0x8036
/* 0D98C4 8031E8C4 27390C38 */  addiu $t9, %lo(D_80360C38) # addiu $t9, $t9, 0xc38
/* 0D98C8 8031E8C8 02F92821 */  addu  $a1, $s7, $t9
.L8031E8CC:
/* 0D98CC 8031E8CC 00B28021 */  addu  $s0, $a1, $s2
/* 0D98D0 8031E8D0 920F0000 */  lbu   $t7, ($s0)
/* 0D98D4 8031E8D4 57CF0014 */  bnel  $fp, $t7, .L8031E928
/* 0D98D8 8031E8D8 26520001 */   addiu $s2, $s2, 1
/* 0D98DC 8031E8DC 90820000 */  lbu   $v0, ($a0)
/* 0D98E0 8031E8E0 001768C0 */  sll   $t5, $s7, 3
/* 0D98E4 8031E8E4 01B76821 */  addu  $t5, $t5, $s7
/* 0D98E8 8031E8E8 004A0019 */  multu $v0, $t2
/* 0D98EC 8031E8EC 000D6880 */  sll   $t5, $t5, 2
/* 0D98F0 8031E8F0 01B76823 */  subu  $t5, $t5, $s7
/* 0D98F4 8031E8F4 000D6940 */  sll   $t5, $t5, 5
/* 0D98F8 8031E8F8 016D7021 */  addu  $t6, $t3, $t5
/* 0D98FC 8031E8FC A2020000 */  sb    $v0, ($s0)
/* 0D9900 8031E900 0000C012 */  mflo  $t8
/* 0D9904 8031E904 01D81821 */  addu  $v1, $t6, $t8
/* 0D9908 8031E908 8C790014 */  lw    $t9, 0x14($v1)
/* 0D990C 8031E90C 02727021 */  addu  $t6, $s3, $s2
/* 0D9910 8031E910 A1D50000 */  sb    $s5, ($t6)
/* 0D9914 8031E914 03267824 */  and   $t7, $t9, $a2
/* 0D9918 8031E918 25ED0001 */  addiu $t5, $t7, 1
/* 0D991C 8031E91C AC6D0014 */  sw    $t5, 0x14($v1)
/* 0D9920 8031E920 241200FE */  li    $s2, 254
/* 0D9924 8031E924 26520001 */  addiu $s2, $s2, 1
.L8031E928:
/* 0D9928 8031E928 325800FF */  andi  $t8, $s2, 0xff
/* 0D992C 8031E92C 0307082A */  slt   $at, $t8, $a3
/* 0D9930 8031E930 1420FFE6 */  bnez  $at, .L8031E8CC
/* 0D9934 8031E934 03009025 */   move  $s2, $t8
.L8031E938:
/* 0D9938 8031E938 329900FF */  andi  $t9, $s4, 0xff
.L8031E93C:
/* 0D993C 8031E93C 0327082A */  slt   $at, $t9, $a3
/* 0D9940 8031E940 1420FFD8 */  bnez  $at, .L8031E8A4
/* 0D9944 8031E944 0320A025 */   move  $s4, $t9
.L8031E948:
/* 0D9948 8031E948 8FBF0044 */  lw    $ra, 0x44($sp)
/* 0D994C 8031E94C D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0D9950 8031E950 8FB00020 */  lw    $s0, 0x20($sp)
/* 0D9954 8031E954 8FB10024 */  lw    $s1, 0x24($sp)
/* 0D9958 8031E958 8FB20028 */  lw    $s2, 0x28($sp)
/* 0D995C 8031E95C 8FB3002C */  lw    $s3, 0x2c($sp)
/* 0D9960 8031E960 8FB40030 */  lw    $s4, 0x30($sp)
/* 0D9964 8031E964 8FB50034 */  lw    $s5, 0x34($sp)
/* 0D9968 8031E968 8FB60038 */  lw    $s6, 0x38($sp)
/* 0D996C 8031E96C 8FB7003C */  lw    $s7, 0x3c($sp)
/* 0D9970 8031E970 8FBE0040 */  lw    $fp, 0x40($sp)
/* 0D9974 8031E974 03E00008 */  jr    $ra
/* 0D9978 8031E978 27BD00E0 */   addiu $sp, $sp, 0xe0
)
#else
GLOBAL_ASM(
glabel func_8031E16C
/* 0D9FF4 8031EFF4 27BDFF28 */  addiu $sp, $sp, -0xd8
/* 0D9FF8 8031EFF8 AFB00018 */  sw    $s0, 0x18($sp)
/* 0D9FFC 8031EFFC 3C0E8033 */  lui   $t6, %hi(D_8033212C) # $t6, 0x8033
/* 0DA000 8031F000 27B00090 */  addiu $s0, $sp, 0x90
/* 0DA004 8031F004 AFBE0038 */  sw    $fp, 0x38($sp)
/* 0DA008 8031F008 AFB70034 */  sw    $s7, 0x34($sp)
/* 0DA00C 8031F00C AFB30024 */  sw    $s3, 0x24($sp)
/* 0DA010 8031F010 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0DA014 8031F014 3C0B8036 */  lui   $t3, %hi(D_80360C48) # $t3, 0x8036
/* 0DA018 8031F018 25CE3240 */  addiu $t6, %lo(D_8033212C) # addiu $t6, $t6, 0x3240
/* 0DA01C 8031F01C 256B1FB8 */  addiu $t3, %lo(D_80360C48) # addiu $t3, $t3, 0x1fb8
/* 0DA020 8031F020 27B10070 */  addiu $s1, $sp, 0x70
/* 0DA024 8031F024 27B30080 */  addiu $s3, $sp, 0x80
/* 0DA028 8031F028 309700FF */  andi  $s7, $a0, 0xff
/* 0DA02C 8031F02C 241E00FF */  li    $fp, 255
/* 0DA030 8031F030 AFBF003C */  sw    $ra, 0x3c($sp)
/* 0DA034 8031F034 AFB60030 */  sw    $s6, 0x30($sp)
/* 0DA038 8031F038 AFB5002C */  sw    $s5, 0x2c($sp)
/* 0DA03C 8031F03C AFB40028 */  sw    $s4, 0x28($sp)
/* 0DA040 8031F040 AFB20020 */  sw    $s2, 0x20($sp)
/* 0DA044 8031F044 AFA400D8 */  sw    $a0, 0xd8($sp)
/* 0DA048 8031F048 25D9003C */  addiu $t9, $t6, 0x3c
/* 0DA04C 8031F04C 02006825 */  move  $t5, $s0
.L_U_8031F050:
/* 0DA050 8031F050 8DC10000 */  lw    $at, ($t6)
/* 0DA054 8031F054 25CE000C */  addiu $t6, $t6, 0xc
/* 0DA058 8031F058 25AD000C */  addiu $t5, $t5, 0xc
/* 0DA05C 8031F05C ADA1FFF4 */  sw    $at, -0xc($t5)
/* 0DA060 8031F060 8DC1FFF8 */  lw    $at, -8($t6)
/* 0DA064 8031F064 ADA1FFF8 */  sw    $at, -8($t5)
/* 0DA068 8031F068 8DC1FFFC */  lw    $at, -4($t6)
/* 0DA06C 8031F06C 15D9FFF8 */  bne   $t6, $t9, .L_U_8031F050
/* 0DA070 8031F070 ADA1FFFC */   sw    $at, -4($t5)
/* 0DA074 8031F074 8DC10000 */  lw    $at, ($t6)
/* 0DA078 8031F078 3C188033 */  lui   $t8, %hi(D_8033216C) # $t8, 0x8033
/* 0DA07C 8031F07C 27183280 */  addiu $t8, %lo(D_8033216C) # addiu $t8, $t8, 0x3280
/* 0DA080 8031F080 ADA10000 */  sw    $at, ($t5)
/* 0DA084 8031F084 8F010000 */  lw    $at, ($t8)
/* 0DA088 8031F088 3C0D8033 */  lui   $t5, %hi(D_8033217C) # $t5, 0x8033
/* 0DA08C 8031F08C 25AD3290 */  addiu $t5, %lo(D_8033217C) # addiu $t5, $t5, 0x3290
/* 0DA090 8031F090 AE610000 */  sw    $at, ($s3)
/* 0DA094 8031F094 8F0E0004 */  lw    $t6, 4($t8)
/* 0DA098 8031F098 0017C8C0 */  sll   $t9, $s7, 3
/* 0DA09C 8031F09C 0337C821 */  addu  $t9, $t9, $s7
/* 0DA0A0 8031F0A0 AE6E0004 */  sw    $t6, 4($s3)
/* 0DA0A4 8031F0A4 8F010008 */  lw    $at, 8($t8)
/* 0DA0A8 8031F0A8 0019C880 */  sll   $t9, $t9, 2
/* 0DA0AC 8031F0AC 0337C823 */  subu  $t9, $t9, $s7
/* 0DA0B0 8031F0B0 AE610008 */  sw    $at, 8($s3)
/* 0DA0B4 8031F0B4 8F0E000C */  lw    $t6, 0xc($t8)
/* 0DA0B8 8031F0B8 0019C940 */  sll   $t9, $t9, 5
/* 0DA0BC 8031F0BC 01796021 */  addu  $t4, $t3, $t9
/* 0DA0C0 8031F0C0 AE6E000C */  sw    $t6, 0xc($s3)
/* 0DA0C4 8031F0C4 8DA10000 */  lw    $at, ($t5)
/* 0DA0C8 8031F0C8 001770C0 */  sll   $t6, $s7, 3
/* 0DA0CC 8031F0CC 01D77021 */  addu  $t6, $t6, $s7
/* 0DA0D0 8031F0D0 AE210000 */  sw    $at, ($s1)
/* 0DA0D4 8031F0D4 8DB80004 */  lw    $t8, 4($t5)
/* 0DA0D8 8031F0D8 000E7080 */  sll   $t6, $t6, 2
/* 0DA0DC 8031F0DC 01D77023 */  subu  $t6, $t6, $s7
/* 0DA0E0 8031F0E0 AE380004 */  sw    $t8, 4($s1)
/* 0DA0E4 8031F0E4 8DA10008 */  lw    $at, 8($t5)
/* 0DA0E8 8031F0E8 000E7140 */  sll   $t6, $t6, 5
/* 0DA0EC 8031F0EC 016E7821 */  addu  $t7, $t3, $t6
/* 0DA0F0 8031F0F0 AE210008 */  sw    $at, 8($s1)
/* 0DA0F4 8031F0F4 8DB8000C */  lw    $t8, 0xc($t5)
/* 0DA0F8 8031F0F8 91F4001B */  lbu   $s4, 0x1b($t7)
/* 0DA0FC 8031F0FC 240A001C */  li    $t2, 28
/* 0DA100 8031F100 AE38000C */  sw    $t8, 0xc($s1)
/* 0DA104 8031F104 A3A0006F */  sb    $zero, 0x6f($sp)
/* 0DA108 8031F108 13D40115 */  beq   $fp, $s4, .L_U_8031F560
/* 0DA10C 8031F10C 02809025 */   move  $s2, $s4
.L_U_8031F110:
/* 0DA110 8031F110 028A0019 */  multu $s4, $t2
/* 0DA114 8031F114 24010081 */  li    $at, 129
/* 0DA118 8031F118 A3B400D3 */  sb    $s4, 0xd3($sp)
/* 0DA11C 8031F11C 00006812 */  mflo  $t5
/* 0DA120 8031F120 018DA821 */  addu  $s5, $t4, $t5
/* 0DA124 8031F124 8EA20014 */  lw    $v0, 0x14($s5)
/* 0DA128 8031F128 3058008F */  andi  $t8, $v0, 0x8f
/* 0DA12C 8031F12C 17010008 */  bne   $t8, $at, .L_U_8031F150
/* 0DA130 8031F130 304F0080 */   andi  $t7, $v0, 0x80
/* 0DA134 8031F134 92A20019 */  lbu   $v0, 0x19($s5)
/* 0DA138 8031F138 2C430001 */  sltiu $v1, $v0, 1
/* 0DA13C 8031F13C 244EFFFF */  addiu $t6, $v0, -1
/* 0DA140 8031F140 10600013 */  beqz  $v1, .L_U_8031F190
/* 0DA144 8031F144 A2AE0019 */   sb    $t6, 0x19($s5)
/* 0DA148 8031F148 10000011 */  b     .L_U_8031F190
/* 0DA14C 8031F14C AEA00014 */   sw    $zero, 0x14($s5)
.L_U_8031F150:
/* 0DA150 8031F150 55E00010 */  bnezl $t7, .L_U_8031F194
/* 0DA154 8031F154 8EAD0014 */   lw    $t5, 0x14($s5)
/* 0DA158 8031F158 92A20019 */  lbu   $v0, 0x19($s5)
/* 0DA15C 8031F15C 32E400FF */  andi  $a0, $s7, 0xff
/* 0DA160 8031F160 328500FF */  andi  $a1, $s4, 0xff
/* 0DA164 8031F164 38430008 */  xori  $v1, $v0, 8
/* 0DA168 8031F168 2459FFFF */  addiu $t9, $v0, -1
/* 0DA16C 8031F16C 14600008 */  bnez  $v1, .L_U_8031F190
/* 0DA170 8031F170 A2B90019 */   sb    $t9, 0x19($s5)
/* 0DA174 8031F174 0C0C7BDB */  jal   func_8031E0E4
/* 0DA178 8031F178 AFAC0060 */   sw    $t4, 0x60($sp)
/* 0DA17C 8031F17C 3C0B8036 */  lui   $t3, %hi(D_80360C48) # $t3, 0x8036
/* 0DA180 8031F180 256B1FB8 */  addiu $t3, %lo(D_80360C48) # addiu $t3, $t3, 0x1fb8
/* 0DA184 8031F184 240A001C */  li    $t2, 28
/* 0DA188 8031F188 8FAC0060 */  lw    $t4, 0x60($sp)
/* 0DA18C 8031F18C AEA00014 */  sw    $zero, 0x14($s5)
.L_U_8031F190:
/* 0DA190 8031F190 8EAD0014 */  lw    $t5, 0x14($s5)
.L_U_8031F194:
/* 0DA194 8031F194 55A00010 */  bnezl $t5, .L_U_8031F1D8
/* 0DA198 8031F198 92AF0018 */   lbu   $t7, 0x18($s5)
/* 0DA19C 8031F19C 92B80018 */  lbu   $t8, 0x18($s5)
/* 0DA1A0 8031F1A0 24010001 */  li    $at, 1
/* 0DA1A4 8031F1A4 32E400FF */  andi  $a0, $s7, 0xff
/* 0DA1A8 8031F1A8 1701000A */  bne   $t8, $at, .L_U_8031F1D4
/* 0DA1AC 8031F1AC 328500FF */   andi  $a1, $s4, 0xff
/* 0DA1B0 8031F1B0 92AE001A */  lbu   $t6, 0x1a($s5)
/* 0DA1B4 8031F1B4 A2A00018 */  sb    $zero, 0x18($s5)
/* 0DA1B8 8031F1B8 AFAC0060 */  sw    $t4, 0x60($sp)
/* 0DA1BC 8031F1BC 0C0C7B9C */  jal   func_8031DFE8
/* 0DA1C0 8031F1C0 A3AE00D3 */   sb    $t6, 0xd3($sp)
/* 0DA1C4 8031F1C4 3C0B8036 */  lui   $t3, %hi(D_80360C48) # $t3, 0x8036
/* 0DA1C8 8031F1C8 256B1FB8 */  addiu $t3, %lo(D_80360C48) # addiu $t3, $t3, 0x1fb8
/* 0DA1CC 8031F1CC 240A001C */  li    $t2, 28
/* 0DA1D0 8031F1D0 8FAC0060 */  lw    $t4, 0x60($sp)
.L_U_8031F1D4:
/* 0DA1D4 8031F1D4 92AF0018 */  lbu   $t7, 0x18($s5)
.L_U_8031F1D8:
/* 0DA1D8 8031F1D8 93B900D3 */  lbu   $t9, 0xd3($sp)
/* 0DA1DC 8031F1DC 51E000DA */  beql  $t7, $zero, .L_U_8031F548
/* 0DA1E0 8031F1E0 93B900D3 */   lbu   $t9, 0xd3($sp)
/* 0DA1E4 8031F1E4 573200D8 */  bnel  $t9, $s2, .L_U_8031F548
/* 0DA1E8 8031F1E8 93B900D3 */   lbu   $t9, 0xd3($sp)
/* 0DA1EC 8031F1EC 8EB80000 */  lw    $t8, ($s5)
/* 0DA1F0 8031F1F0 8EAE0004 */  lw    $t6, 4($s5)
/* 0DA1F4 8031F1F4 8EAD0008 */  lw    $t5, 8($s5)
/* 0DA1F8 8031F1F8 C7020000 */  lwc1  $f2, ($t8)
/* 0DA1FC 8031F1FC C5CE0000 */  lwc1  $f14, ($t6)
/* 0DA200 8031F200 C5A00000 */  lwc1  $f0, ($t5)
/* 0DA204 8031F204 46021102 */  mul.s $f4, $f2, $f2
/* 0DA208 8031F208 3C0F8033 */  lui   $t7, %hi(D_803320C8) # $t7, 0x8033
/* 0DA20C 8031F20C 25EF31D8 */  addiu $t7, %lo(D_803320C8) # addiu $t7, $t7, 0x31d8
/* 0DA210 8031F210 460E7182 */  mul.s $f6, $f14, $f14
/* 0DA214 8031F214 02EFB021 */  addu  $s6, $s7, $t7
/* 0DA218 8031F218 AFAC0060 */  sw    $t4, 0x60($sp)
/* 0DA21C 8031F21C 46000282 */  mul.s $f10, $f0, $f0
/* 0DA220 8031F220 00009025 */  move  $s2, $zero
/* 0DA224 8031F224 46062200 */  add.s $f8, $f4, $f6
/* 0DA228 8031F228 0C0C8E94 */  jal   sqrtf
/* 0DA22C 8031F22C 46085300 */   add.s $f12, $f10, $f8
/* 0DA230 8031F230 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0DA234 8031F234 44818000 */  mtc1  $at, $f16
/* 0DA238 8031F238 8EA20014 */  lw    $v0, 0x14($s5)
/* 0DA23C 8031F23C 3C0B8036 */  lui   $t3, %hi(D_80360C48) # $t3, 0x8036
/* 0DA240 8031F240 46100482 */  mul.s $f18, $f0, $f16
/* 0DA244 8031F244 3043FF00 */  andi  $v1, $v0, 0xff00
/* 0DA248 8031F248 0003CA02 */  srl   $t9, $v1, 8
/* 0DA24C 8031F24C 332D00FF */  andi  $t5, $t9, 0xff
/* 0DA250 8031F250 0002C140 */  sll   $t8, $v0, 5
/* 0DA254 8031F254 256B1FB8 */  addiu $t3, %lo(D_80360C48) # addiu $t3, $t3, 0x1fb8
/* 0DA258 8031F258 240A001C */  li    $t2, 28
/* 0DA25C 8031F25C E6B2000C */  swc1  $f18, 0xc($s5)
/* 0DA260 8031F260 8FAC0060 */  lw    $t4, 0x60($sp)
/* 0DA264 8031F264 07010009 */  bgez  $t8, .L_U_8031F28C
/* 0DA268 8031F268 01A01825 */   move  $v1, $t5
/* 0DA26C 8031F26C 03CD7023 */  subu  $t6, $fp, $t5
/* 0DA270 8031F270 000E7880 */  sll   $t7, $t6, 2
/* 0DA274 8031F274 01EE7821 */  addu  $t7, $t7, $t6
/* 0DA278 8031F278 000F7880 */  sll   $t7, $t7, 2
/* 0DA27C 8031F27C 01EE7823 */  subu  $t7, $t7, $t6
/* 0DA280 8031F280 000F7880 */  sll   $t7, $t7, 2
/* 0DA284 8031F284 1000007E */  b     .L_U_8031F480
/* 0DA288 8031F288 AEAF0010 */   sw    $t7, 0x10($s5)
.L_U_8031F28C:
/* 0DA28C 8031F28C 8EB90008 */  lw    $t9, 8($s5)
/* 0DA290 8031F290 44802000 */  mtc1  $zero, $f4
/* 0DA294 8031F294 240D0001 */  li    $t5, 1
/* 0DA298 8031F298 C7200000 */  lwc1  $f0, ($t9)
/* 0DA29C 8031F29C 03C3C823 */  subu  $t9, $fp, $v1
/* 0DA2A0 8031F2A0 00197080 */  sll   $t6, $t9, 2
/* 0DA2A4 8031F2A4 4600203C */  c.lt.s $f4, $f0
/* 0DA2A8 8031F2A8 01D97021 */  addu  $t6, $t6, $t9
/* 0DA2AC 8031F2AC 000E7080 */  sll   $t6, $t6, 2
/* 0DA2B0 8031F2B0 01D97023 */  subu  $t6, $t6, $t9
/* 0DA2B4 8031F2B4 45000050 */  bc1f  .L_U_8031F3F8
/* 0DA2B8 8031F2B8 000E7080 */   sll   $t6, $t6, 2
/* 0DA2BC 8031F2BC 3C0140C0 */  li    $at, 0x40C00000 # 6.000000
/* 0DA2C0 8031F2C0 44813000 */  mtc1  $at, $f6
/* 0DA2C4 8031F2C4 24180001 */  li    $t8, 1
/* 0DA2C8 8031F2C8 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0DA2CC 8031F2CC 46060283 */  div.s $f10, $f0, $f6
/* 0DA2D0 8031F2D0 444DF800 */  cfc1  $t5, $31
/* 0DA2D4 8031F2D4 44D8F800 */  ctc1  $t8, $31
/* 0DA2D8 8031F2D8 00000000 */  nop   
/* 0DA2DC 8031F2DC 46005224 */  cvt.w.s $f8, $f10
/* 0DA2E0 8031F2E0 4458F800 */  cfc1  $t8, $31
/* 0DA2E4 8031F2E4 00000000 */  nop   
/* 0DA2E8 8031F2E8 33180078 */  andi  $t8, $t8, 0x78
/* 0DA2EC 8031F2EC 53000013 */  beql  $t8, $zero, .L_U_8031F33C
/* 0DA2F0 8031F2F0 44184000 */   mfc1  $t8, $f8
/* 0DA2F4 8031F2F4 44814000 */  mtc1  $at, $f8
/* 0DA2F8 8031F2F8 24180001 */  li    $t8, 1
/* 0DA2FC 8031F2FC 46085201 */  sub.s $f8, $f10, $f8
/* 0DA300 8031F300 44D8F800 */  ctc1  $t8, $31
/* 0DA304 8031F304 00000000 */  nop   
/* 0DA308 8031F308 46004224 */  cvt.w.s $f8, $f8
/* 0DA30C 8031F30C 4458F800 */  cfc1  $t8, $31
/* 0DA310 8031F310 00000000 */  nop   
/* 0DA314 8031F314 33180078 */  andi  $t8, $t8, 0x78
/* 0DA318 8031F318 17000005 */  bnez  $t8, .L_U_8031F330
/* 0DA31C 8031F31C 00000000 */   nop   
/* 0DA320 8031F320 44184000 */  mfc1  $t8, $f8
/* 0DA324 8031F324 3C018000 */  lui   $at, 0x8000
/* 0DA328 8031F328 10000007 */  b     .L_U_8031F348
/* 0DA32C 8031F32C 0301C025 */   or    $t8, $t8, $at
.L_U_8031F330:
/* 0DA330 8031F330 10000005 */  b     .L_U_8031F348
/* 0DA334 8031F334 2418FFFF */   li    $t8, -1
/* 0DA338 8031F338 44184000 */  mfc1  $t8, $f8
.L_U_8031F33C:
/* 0DA33C 8031F33C 00000000 */  nop   
/* 0DA340 8031F340 0700FFFB */  bltz  $t8, .L_U_8031F330
/* 0DA344 8031F344 00000000 */   nop   
.L_U_8031F348:
/* 0DA348 8031F348 44CDF800 */  ctc1  $t5, $31
/* 0DA34C 8031F34C 240F0001 */  li    $t7, 1
/* 0DA350 8031F350 C6B0000C */  lwc1  $f16, 0xc($s5)
/* 0DA354 8031F354 03C36823 */  subu  $t5, $fp, $v1
/* 0DA358 8031F358 444EF800 */  cfc1  $t6, $31
/* 0DA35C 8031F35C 44CFF800 */  ctc1  $t7, $31
/* 0DA360 8031F360 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0DA364 8031F364 460084A4 */  cvt.w.s $f18, $f16
/* 0DA368 8031F368 444FF800 */  cfc1  $t7, $31
/* 0DA36C 8031F36C 00000000 */  nop   
/* 0DA370 8031F370 31EF0078 */  andi  $t7, $t7, 0x78
/* 0DA374 8031F374 51E00013 */  beql  $t7, $zero, .L_U_8031F3C4
/* 0DA378 8031F378 440F9000 */   mfc1  $t7, $f18
/* 0DA37C 8031F37C 44819000 */  mtc1  $at, $f18
/* 0DA380 8031F380 240F0001 */  li    $t7, 1
/* 0DA384 8031F384 46128481 */  sub.s $f18, $f16, $f18
/* 0DA388 8031F388 44CFF800 */  ctc1  $t7, $31
/* 0DA38C 8031F38C 00000000 */  nop   
/* 0DA390 8031F390 460094A4 */  cvt.w.s $f18, $f18
/* 0DA394 8031F394 444FF800 */  cfc1  $t7, $31
/* 0DA398 8031F398 00000000 */  nop   
/* 0DA39C 8031F39C 31EF0078 */  andi  $t7, $t7, 0x78
/* 0DA3A0 8031F3A0 15E00005 */  bnez  $t7, .L_U_8031F3B8
/* 0DA3A4 8031F3A4 00000000 */   nop   
/* 0DA3A8 8031F3A8 440F9000 */  mfc1  $t7, $f18
/* 0DA3AC 8031F3AC 3C018000 */  lui   $at, 0x8000
/* 0DA3B0 8031F3B0 10000007 */  b     .L_U_8031F3D0
/* 0DA3B4 8031F3B4 01E17825 */   or    $t7, $t7, $at
.L_U_8031F3B8:
/* 0DA3B8 8031F3B8 10000005 */  b     .L_U_8031F3D0
/* 0DA3BC 8031F3BC 240FFFFF */   li    $t7, -1
/* 0DA3C0 8031F3C0 440F9000 */  mfc1  $t7, $f18
.L_U_8031F3C4:
/* 0DA3C4 8031F3C4 00000000 */  nop   
/* 0DA3C8 8031F3C8 05E0FFFB */  bltz  $t7, .L_U_8031F3B8
/* 0DA3CC 8031F3CC 00000000 */   nop   
.L_U_8031F3D0:
/* 0DA3D0 8031F3D0 44CEF800 */  ctc1  $t6, $31
/* 0DA3D4 8031F3D4 000D7080 */  sll   $t6, $t5, 2
/* 0DA3D8 8031F3D8 01CD7021 */  addu  $t6, $t6, $t5
/* 0DA3DC 8031F3DC 000E7080 */  sll   $t6, $t6, 2
/* 0DA3E0 8031F3E0 01CD7023 */  subu  $t6, $t6, $t5
/* 0DA3E4 8031F3E4 000E7080 */  sll   $t6, $t6, 2
/* 0DA3E8 8031F3E8 030FC821 */  addu  $t9, $t8, $t7
/* 0DA3EC 8031F3EC 032EC021 */  addu  $t8, $t9, $t6
/* 0DA3F0 8031F3F0 10000023 */  b     .L_U_8031F480
/* 0DA3F4 8031F3F4 AEB80010 */   sw    $t8, 0x10($s5)
.L_U_8031F3F8:
/* 0DA3F8 8031F3F8 444FF800 */  cfc1  $t7, $31
/* 0DA3FC 8031F3FC 44CDF800 */  ctc1  $t5, $31
/* 0DA400 8031F400 C6A4000C */  lwc1  $f4, 0xc($s5)
/* 0DA404 8031F404 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0DA408 8031F408 460021A4 */  cvt.w.s $f6, $f4
/* 0DA40C 8031F40C 444DF800 */  cfc1  $t5, $31
/* 0DA410 8031F410 00000000 */  nop   
/* 0DA414 8031F414 31AD0078 */  andi  $t5, $t5, 0x78
/* 0DA418 8031F418 51A00013 */  beql  $t5, $zero, .L_U_8031F468
/* 0DA41C 8031F41C 440D3000 */   mfc1  $t5, $f6
/* 0DA420 8031F420 44813000 */  mtc1  $at, $f6
/* 0DA424 8031F424 240D0001 */  li    $t5, 1
/* 0DA428 8031F428 46062181 */  sub.s $f6, $f4, $f6
/* 0DA42C 8031F42C 44CDF800 */  ctc1  $t5, $31
/* 0DA430 8031F430 00000000 */  nop   
/* 0DA434 8031F434 460031A4 */  cvt.w.s $f6, $f6
/* 0DA438 8031F438 444DF800 */  cfc1  $t5, $31
/* 0DA43C 8031F43C 00000000 */  nop   
/* 0DA440 8031F440 31AD0078 */  andi  $t5, $t5, 0x78
/* 0DA444 8031F444 15A00005 */  bnez  $t5, .L_U_8031F45C
/* 0DA448 8031F448 00000000 */   nop   
/* 0DA44C 8031F44C 440D3000 */  mfc1  $t5, $f6
/* 0DA450 8031F450 3C018000 */  lui   $at, 0x8000
/* 0DA454 8031F454 10000007 */  b     .L_U_8031F474
/* 0DA458 8031F458 01A16825 */   or    $t5, $t5, $at
.L_U_8031F45C:
/* 0DA45C 8031F45C 10000005 */  b     .L_U_8031F474
/* 0DA460 8031F460 240DFFFF */   li    $t5, -1
/* 0DA464 8031F464 440D3000 */  mfc1  $t5, $f6
.L_U_8031F468:
/* 0DA468 8031F468 00000000 */  nop   
/* 0DA46C 8031F46C 05A0FFFB */  bltz  $t5, .L_U_8031F45C
/* 0DA470 8031F470 00000000 */   nop   
.L_U_8031F474:
/* 0DA474 8031F474 44CFF800 */  ctc1  $t7, $31
/* 0DA478 8031F478 01AEC021 */  addu  $t8, $t5, $t6
/* 0DA47C 8031F47C AEB80010 */  sw    $t8, 0x10($s5)
.L_U_8031F480:
/* 0DA480 8031F480 92C90000 */  lbu   $t1, ($s6)
/* 0DA484 8031F484 1920002C */  blez  $t1, .L_U_8031F538
/* 0DA488 8031F488 01203825 */   move  $a3, $t1
/* 0DA48C 8031F48C 8EA80010 */  lw    $t0, 0x10($s5)
.L_U_8031F490:
/* 0DA490 8031F490 00127880 */  sll   $t7, $s2, 2
/* 0DA494 8031F494 020F3021 */  addu  $a2, $s0, $t7
/* 0DA498 8031F498 8CD90000 */  lw    $t9, ($a2)
/* 0DA49C 8031F49C 24E2FFFF */  addiu $v0, $a3, -1
/* 0DA4A0 8031F4A0 304300FF */  andi  $v1, $v0, 0xff
/* 0DA4A4 8031F4A4 0328082B */  sltu  $at, $t9, $t0
/* 0DA4A8 8031F4A8 1420001E */  bnez  $at, .L_U_8031F524
/* 0DA4AC 8031F4AC 00601025 */   move  $v0, $v1
/* 0DA4B0 8031F4B0 0243082A */  slt   $at, $s2, $v1
/* 0DA4B4 8031F4B4 02402025 */  move  $a0, $s2
/* 0DA4B8 8031F4B8 10200014 */  beqz  $at, .L_U_8031F50C
/* 0DA4BC 8031F4BC 92A50018 */   lbu   $a1, 0x18($s5)
.L_U_8031F4C0:
/* 0DA4C0 8031F4C0 00037080 */  sll   $t6, $v1, 2
/* 0DA4C4 8031F4C4 020EC021 */  addu  $t8, $s0, $t6
/* 0DA4C8 8031F4C8 8F0FFFFC */  lw    $t7, -4($t8)
/* 0DA4CC 8031F4CC 0002C880 */  sll   $t9, $v0, 2
/* 0DA4D0 8031F4D0 02196821 */  addu  $t5, $s0, $t9
/* 0DA4D4 8031F4D4 02637021 */  addu  $t6, $s3, $v1
/* 0DA4D8 8031F4D8 ADAF0000 */  sw    $t7, ($t5)
/* 0DA4DC 8031F4DC 91D8FFFF */  lbu   $t8, -1($t6)
/* 0DA4E0 8031F4E0 0262C821 */  addu  $t9, $s3, $v0
/* 0DA4E4 8031F4E4 02227021 */  addu  $t6, $s1, $v0
/* 0DA4E8 8031F4E8 02237821 */  addu  $t7, $s1, $v1
/* 0DA4EC 8031F4EC 2442FFFF */  addiu $v0, $v0, -1
/* 0DA4F0 8031F4F0 A3380000 */  sb    $t8, ($t9)
/* 0DA4F4 8031F4F4 91EDFFFF */  lbu   $t5, -1($t7)
/* 0DA4F8 8031F4F8 304300FF */  andi  $v1, $v0, 0xff
/* 0DA4FC 8031F4FC 0083082A */  slt   $at, $a0, $v1
/* 0DA500 8031F500 00601025 */  move  $v0, $v1
/* 0DA504 8031F504 1420FFEE */  bnez  $at, .L_U_8031F4C0
/* 0DA508 8031F508 A1CD0000 */   sb    $t5, ($t6)
.L_U_8031F50C:
/* 0DA50C 8031F50C 0272C821 */  addu  $t9, $s3, $s2
/* 0DA510 8031F510 02327821 */  addu  $t7, $s1, $s2
/* 0DA514 8031F514 A3340000 */  sb    $s4, ($t9)
/* 0DA518 8031F518 ACC80000 */  sw    $t0, ($a2)
/* 0DA51C 8031F51C A1E50000 */  sb    $a1, ($t7)
/* 0DA520 8031F520 313200FF */  andi  $s2, $t1, 0xff
.L_U_8031F524:
/* 0DA524 8031F524 26520001 */  addiu $s2, $s2, 1
/* 0DA528 8031F528 324D00FF */  andi  $t5, $s2, 0xff
/* 0DA52C 8031F52C 01A7082A */  slt   $at, $t5, $a3
/* 0DA530 8031F530 1420FFD7 */  bnez  $at, .L_U_8031F490
/* 0DA534 8031F534 01A09025 */   move  $s2, $t5
.L_U_8031F538:
/* 0DA538 8031F538 93AE006F */  lbu   $t6, 0x6f($sp)
/* 0DA53C 8031F53C 25D80001 */  addiu $t8, $t6, 1
/* 0DA540 8031F540 A3B8006F */  sb    $t8, 0x6f($sp)
/* 0DA544 8031F544 93B900D3 */  lbu   $t9, 0xd3($sp)
.L_U_8031F548:
/* 0DA548 8031F548 032A0019 */  multu $t9, $t2
/* 0DA54C 8031F54C 00007812 */  mflo  $t7
/* 0DA550 8031F550 018F6821 */  addu  $t5, $t4, $t7
/* 0DA554 8031F554 91B4001B */  lbu   $s4, 0x1b($t5)
/* 0DA558 8031F558 17D4FEED */  bne   $fp, $s4, .L_U_8031F110
/* 0DA55C 8031F55C 02809025 */   move  $s2, $s4
.L_U_8031F560:
/* 0DA560 8031F560 3C0F8033 */  lui   $t7, %hi(D_803320C8)
/* 0DA564 8031F564 01F77821 */  addu  $t7, $t7, $s7
/* 0DA568 8031F568 93AE006F */  lbu   $t6, 0x6f($sp)
/* 0DA56C 8031F56C 91EF31D8 */  lbu   $t7, %lo(D_803320C8)($t7)
/* 0DA570 8031F570 3C188036 */  lui   $t8, %hi(D_80360C28) # $t8, 0x8036
/* 0DA574 8031F574 3C018033 */  lui   $at, %hi(D_803320BC)
/* 0DA578 8031F578 27181F98 */  addiu $t8, %lo(D_80360C28) # addiu $t8, $t8, 0x1f98
/* 0DA57C 8031F57C 00370821 */  addu  $at, $at, $s7
/* 0DA580 8031F580 02F8C821 */  addu  $t9, $s7, $t8
/* 0DA584 8031F584 AFB90064 */  sw    $t9, 0x64($sp)
/* 0DA588 8031F588 A02E31CC */  sb    $t6, %lo(D_803320BC)($at)
/* 0DA58C 8031F58C 31E700FF */  andi  $a3, $t7, 0xff
/* 0DA590 8031F590 240A001C */  li    $t2, 28
/* 0DA594 8031F594 00009025 */  move  $s2, $zero
/* 0DA598 8031F598 18E00064 */  blez  $a3, .L_U_8031F72C
/* 0DA59C 8031F59C A32F0000 */   sb    $t7, ($t9)
/* 0DA5A0 8031F5A0 3C168036 */  lui   $s6, %hi(D_80360C38) # $s6, 0x8036
/* 0DA5A4 8031F5A4 26D61FA8 */  addiu $s6, %lo(D_80360C38) # addiu $s6, $s6, 0x1fa8
/* 0DA5A8 8031F5A8 241500FF */  li    $s5, 255
.L_U_8031F5AC:
/* 0DA5AC 8031F5AC 18E00011 */  blez  $a3, .L_U_8031F5F4
/* 0DA5B0 8031F5B0 0000A025 */   move  $s4, $zero
.L_U_8031F5B4:
/* 0DA5B4 8031F5B4 02742021 */  addu  $a0, $s3, $s4
/* 0DA5B8 8031F5B8 90820000 */  lbu   $v0, ($a0)
/* 0DA5BC 8031F5BC 02D77021 */  addu  $t6, $s6, $s7
/* 0DA5C0 8031F5C0 01D2C021 */  addu  $t8, $t6, $s2
/* 0DA5C4 8031F5C4 53C20007 */  beql  $fp, $v0, .L_U_8031F5E4
/* 0DA5C8 8031F5C8 26940001 */   addiu $s4, $s4, 1
/* 0DA5CC 8031F5CC 93190000 */  lbu   $t9, ($t8)
/* 0DA5D0 8031F5D0 57220004 */  bnel  $t9, $v0, .L_U_8031F5E4
/* 0DA5D4 8031F5D4 26940001 */   addiu $s4, $s4, 1
/* 0DA5D8 8031F5D8 A0950000 */  sb    $s5, ($a0)
/* 0DA5DC 8031F5DC 241400FE */  li    $s4, 254
/* 0DA5E0 8031F5E0 26940001 */  addiu $s4, $s4, 1
.L_U_8031F5E4:
/* 0DA5E4 8031F5E4 328F00FF */  andi  $t7, $s4, 0xff
/* 0DA5E8 8031F5E8 01E7082A */  slt   $at, $t7, $a3
/* 0DA5EC 8031F5EC 1420FFF1 */  bnez  $at, .L_U_8031F5B4
/* 0DA5F0 8031F5F0 01E0A025 */   move  $s4, $t7
.L_U_8031F5F4:
/* 0DA5F4 8031F5F4 13D40048 */  beq   $fp, $s4, .L_U_8031F718
/* 0DA5F8 8031F5F8 02D76821 */   addu  $t5, $s6, $s7
/* 0DA5FC 8031F5FC 01B28021 */  addu  $s0, $t5, $s2
/* 0DA600 8031F600 92110000 */  lbu   $s1, ($s0)
/* 0DA604 8031F604 53D10044 */  beql  $fp, $s1, .L_U_8031F718
/* 0DA608 8031F608 A2150000 */   sb    $s5, ($s0)
/* 0DA60C 8031F60C 022A0019 */  multu $s1, $t2
/* 0DA610 8031F610 001770C0 */  sll   $t6, $s7, 3
/* 0DA614 8031F614 01D77021 */  addu  $t6, $t6, $s7
/* 0DA618 8031F618 000E7080 */  sll   $t6, $t6, 2
/* 0DA61C 8031F61C 01D77023 */  subu  $t6, $t6, $s7
/* 0DA620 8031F620 000E7140 */  sll   $t6, $t6, 5
/* 0DA624 8031F624 016E6021 */  addu  $t4, $t3, $t6
/* 0DA628 8031F628 0000C012 */  mflo  $t8
/* 0DA62C 8031F62C 0198A021 */  addu  $s4, $t4, $t8
/* 0DA630 8031F630 8E820014 */  lw    $v0, 0x14($s4)
/* 0DA634 8031F634 54400014 */  bnezl $v0, .L_U_8031F688
/* 0DA638 8031F638 3043008F */   andi  $v1, $v0, 0x8f
/* 0DA63C 8031F63C 92990018 */  lbu   $t9, 0x18($s4)
/* 0DA640 8031F640 24010002 */  li    $at, 2
/* 0DA644 8031F644 32E400FF */  andi  $a0, $s7, 0xff
/* 0DA648 8031F648 1721000E */  bne   $t9, $at, .L_U_8031F684
/* 0DA64C 8031F64C 322500FF */   andi  $a1, $s1, 0xff
/* 0DA650 8031F650 A2800018 */  sb    $zero, 0x18($s4)
/* 0DA654 8031F654 0C0C7B9C */  jal   func_8031DFE8
/* 0DA658 8031F658 AFAC0060 */   sw    $t4, 0x60($sp)
/* 0DA65C 8031F65C 92110000 */  lbu   $s1, ($s0)
/* 0DA660 8031F660 8FAC0060 */  lw    $t4, 0x60($sp)
/* 0DA664 8031F664 3C0B8036 */  lui   $t3, %hi(D_80360C48) # $t3, 0x8036
/* 0DA668 8031F668 001178C0 */  sll   $t7, $s1, 3
/* 0DA66C 8031F66C 01F17823 */  subu  $t7, $t7, $s1
/* 0DA670 8031F670 000F7880 */  sll   $t7, $t7, 2
/* 0DA674 8031F674 018FA021 */  addu  $s4, $t4, $t7
/* 0DA678 8031F678 8E820014 */  lw    $v0, 0x14($s4)
/* 0DA67C 8031F67C 256B1FB8 */  addiu $t3, %lo(D_80360C48) # addiu $t3, $t3, 0x1fb8
/* 0DA680 8031F680 240A001C */  li    $t2, 28
.L_U_8031F684:
/* 0DA684 8031F684 3043008F */  andi  $v1, $v0, 0x8f
.L_U_8031F688:
/* 0DA688 8031F688 2C610082 */  sltiu $at, $v1, 0x82
/* 0DA68C 8031F68C 14200019 */  bnez  $at, .L_U_8031F6F4
/* 0DA690 8031F690 8FB90064 */   lw    $t9, 0x64($sp)
/* 0DA694 8031F694 928D0018 */  lbu   $t5, 0x18($s4)
/* 0DA698 8031F698 32E400FF */  andi  $a0, $s7, 0xff
/* 0DA69C 8031F69C 322500FF */  andi  $a1, $s1, 0xff
/* 0DA6A0 8031F6A0 51A00015 */  beql  $t5, $zero, .L_U_8031F6F8
/* 0DA6A4 8031F6A4 24010002 */   li    $at, 2
/* 0DA6A8 8031F6A8 0C0C7BDB */  jal   func_8031E0E4
/* 0DA6AC 8031F6AC AFAC0060 */   sw    $t4, 0x60($sp)
/* 0DA6B0 8031F6B0 92110000 */  lbu   $s1, ($s0)
/* 0DA6B4 8031F6B4 240A001C */  li    $t2, 28
/* 0DA6B8 8031F6B8 8FAC0060 */  lw    $t4, 0x60($sp)
/* 0DA6BC 8031F6BC 022A0019 */  multu $s1, $t2
/* 0DA6C0 8031F6C0 32E400FF */  andi  $a0, $s7, 0xff
/* 0DA6C4 8031F6C4 322500FF */  andi  $a1, $s1, 0xff
/* 0DA6C8 8031F6C8 00007012 */  mflo  $t6
/* 0DA6CC 8031F6CC 018EA021 */  addu  $s4, $t4, $t6
/* 0DA6D0 8031F6D0 AE800014 */  sw    $zero, 0x14($s4)
/* 0DA6D4 8031F6D4 0C0C7B9C */  jal   func_8031DFE8
/* 0DA6D8 8031F6D8 A2800018 */   sb    $zero, 0x18($s4)
/* 0DA6DC 8031F6DC 8FB80064 */  lw    $t8, 0x64($sp)
/* 0DA6E0 8031F6E0 3C0B8036 */  lui   $t3, %hi(D_80360C48) # $t3, 0x8036
/* 0DA6E4 8031F6E4 256B1FB8 */  addiu $t3, %lo(D_80360C48) # addiu $t3, $t3, 0x1fb8
/* 0DA6E8 8031F6E8 240A001C */  li    $t2, 28
/* 0DA6EC 8031F6EC 10000009 */  b     .L_U_8031F714
/* 0DA6F0 8031F6F0 93070000 */   lbu   $a3, ($t8)
.L_U_8031F6F4:
/* 0DA6F4 8031F6F4 24010002 */  li    $at, 2
.L_U_8031F6F8:
/* 0DA6F8 8031F6F8 14610006 */  bne   $v1, $at, .L_U_8031F714
/* 0DA6FC 8031F6FC 93270000 */   lbu   $a3, ($t9)
/* 0DA700 8031F700 928F0018 */  lbu   $t7, 0x18($s4)
/* 0DA704 8031F704 240D0001 */  li    $t5, 1
/* 0DA708 8031F708 51E00003 */  beql  $t7, $zero, .L_U_8031F718
/* 0DA70C 8031F70C A2150000 */   sb    $s5, ($s0)
/* 0DA710 8031F710 A28D0018 */  sb    $t5, 0x18($s4)
.L_U_8031F714:
/* 0DA714 8031F714 A2150000 */  sb    $s5, ($s0)
.L_U_8031F718:
/* 0DA718 8031F718 26520001 */  addiu $s2, $s2, 1
/* 0DA71C 8031F71C 324E00FF */  andi  $t6, $s2, 0xff
/* 0DA720 8031F720 01C7082A */  slt   $at, $t6, $a3
/* 0DA724 8031F724 1420FFA1 */  bnez  $at, .L_U_8031F5AC
/* 0DA728 8031F728 01C09025 */   move  $s2, $t6
.L_U_8031F72C:
/* 0DA72C 8031F72C 241500FF */  li    $s5, 255
/* 0DA730 8031F730 18E0002B */  blez  $a3, .L_U_8031F7E0
/* 0DA734 8031F734 0000A025 */   move  $s4, $zero
/* 0DA738 8031F738 2406FFF0 */  li    $a2, -16
.L_U_8031F73C:
/* 0DA73C 8031F73C 02742021 */  addu  $a0, $s3, $s4
/* 0DA740 8031F740 90980000 */  lbu   $t8, ($a0)
/* 0DA744 8031F744 26940001 */  addiu $s4, $s4, 1
/* 0DA748 8031F748 53D80022 */  beql  $fp, $t8, .L_U_8031F7D4
/* 0DA74C 8031F74C 329900FF */   andi  $t9, $s4, 0xff
/* 0DA750 8031F750 18E0001F */  blez  $a3, .L_U_8031F7D0
/* 0DA754 8031F754 00009025 */   move  $s2, $zero
/* 0DA758 8031F758 3C198036 */  lui   $t9, %hi(D_80360C38) # $t9, 0x8036
/* 0DA75C 8031F75C 27391FA8 */  addiu $t9, %lo(D_80360C38) # addiu $t9, $t9, 0x1fa8
/* 0DA760 8031F760 02F92821 */  addu  $a1, $s7, $t9
.L_U_8031F764:
/* 0DA764 8031F764 00B28021 */  addu  $s0, $a1, $s2
/* 0DA768 8031F768 920F0000 */  lbu   $t7, ($s0)
/* 0DA76C 8031F76C 57CF0014 */  bnel  $fp, $t7, .L_U_8031F7C0
/* 0DA770 8031F770 26520001 */   addiu $s2, $s2, 1
/* 0DA774 8031F774 90820000 */  lbu   $v0, ($a0)
/* 0DA778 8031F778 001768C0 */  sll   $t5, $s7, 3
/* 0DA77C 8031F77C 01B76821 */  addu  $t5, $t5, $s7
/* 0DA780 8031F780 004A0019 */  multu $v0, $t2
/* 0DA784 8031F784 000D6880 */  sll   $t5, $t5, 2
/* 0DA788 8031F788 01B76823 */  subu  $t5, $t5, $s7
/* 0DA78C 8031F78C 000D6940 */  sll   $t5, $t5, 5
/* 0DA790 8031F790 016D7021 */  addu  $t6, $t3, $t5
/* 0DA794 8031F794 A2020000 */  sb    $v0, ($s0)
/* 0DA798 8031F798 0000C012 */  mflo  $t8
/* 0DA79C 8031F79C 01D81821 */  addu  $v1, $t6, $t8
/* 0DA7A0 8031F7A0 8C790014 */  lw    $t9, 0x14($v1)
/* 0DA7A4 8031F7A4 02727021 */  addu  $t6, $s3, $s2
/* 0DA7A8 8031F7A8 A1D50000 */  sb    $s5, ($t6)
/* 0DA7AC 8031F7AC 03267824 */  and   $t7, $t9, $a2
/* 0DA7B0 8031F7B0 25ED0001 */  addiu $t5, $t7, 1
/* 0DA7B4 8031F7B4 AC6D0014 */  sw    $t5, 0x14($v1)
/* 0DA7B8 8031F7B8 241200FE */  li    $s2, 254
/* 0DA7BC 8031F7BC 26520001 */  addiu $s2, $s2, 1
.L_U_8031F7C0:
/* 0DA7C0 8031F7C0 325800FF */  andi  $t8, $s2, 0xff
/* 0DA7C4 8031F7C4 0307082A */  slt   $at, $t8, $a3
/* 0DA7C8 8031F7C8 1420FFE6 */  bnez  $at, .L_U_8031F764
/* 0DA7CC 8031F7CC 03009025 */   move  $s2, $t8
.L_U_8031F7D0:
/* 0DA7D0 8031F7D0 329900FF */  andi  $t9, $s4, 0xff
.L_U_8031F7D4:
/* 0DA7D4 8031F7D4 0327082A */  slt   $at, $t9, $a3
/* 0DA7D8 8031F7D8 1420FFD8 */  bnez  $at, .L_U_8031F73C
/* 0DA7DC 8031F7DC 0320A025 */   move  $s4, $t9
.L_U_8031F7E0:
/* 0DA7E0 8031F7E0 8FBF003C */  lw    $ra, 0x3c($sp)
/* 0DA7E4 8031F7E4 8FB00018 */  lw    $s0, 0x18($sp)
/* 0DA7E8 8031F7E8 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0DA7EC 8031F7EC 8FB20020 */  lw    $s2, 0x20($sp)
/* 0DA7F0 8031F7F0 8FB30024 */  lw    $s3, 0x24($sp)
/* 0DA7F4 8031F7F4 8FB40028 */  lw    $s4, 0x28($sp)
/* 0DA7F8 8031F7F8 8FB5002C */  lw    $s5, 0x2c($sp)
/* 0DA7FC 8031F7FC 8FB60030 */  lw    $s6, 0x30($sp)
/* 0DA800 8031F800 8FB70034 */  lw    $s7, 0x34($sp)
/* 0DA804 8031F804 8FBE0038 */  lw    $fp, 0x38($sp)
/* 0DA808 8031F808 03E00008 */  jr    $ra
/* 0DA80C 8031F80C 27BD00D8 */   addiu $sp, $sp, 0xd8
)
#endif

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

#ifdef VERSION_JP
GLOBAL_ASM(
.late_rodata
glabel D_803383B0
    .incbin "bin/rodata.bin", 0x3940, 0x4

glabel jtbl_803383B4
    .word L8031F244
    .word L8031F0B4
    .word L8031F244
    .word L8031F2A8
    .word L8031F2A8
    .word L8031F2A8
    .word L8031F2A8
    .word L8031F220
    .word L8031F2A8
    .word L8031F2A8

glabel jtbl_803383DC
    .word L8031F52C
    .word L8031F3A4
    .word L8031F52C
    .word L8031F590
    .word L8031F590
    .word L8031F590
    .word L8031F590
    .word L8031F50C
    .word L8031F590
    .word L8031F590

.text
glabel func_8031EEF8 # US: 8031FDAC
/* 0D9EF8 8031EEF8 27BDFF80 */  addiu $sp, $sp, -0x80
/* 0D9EFC 8031EEFC AFBF006C */  sw    $ra, 0x6c($sp)
/* 0D9F00 8031EF00 AFB60060 */  sw    $s6, 0x60($sp)
/* 0D9F04 8031EF04 AFBE0068 */  sw    $fp, 0x68($sp)
/* 0D9F08 8031EF08 AFB70064 */  sw    $s7, 0x64($sp)
/* 0D9F0C 8031EF0C AFB5005C */  sw    $s5, 0x5c($sp)
/* 0D9F10 8031EF10 AFB40058 */  sw    $s4, 0x58($sp)
/* 0D9F14 8031EF14 AFB30054 */  sw    $s3, 0x54($sp)
/* 0D9F18 8031EF18 AFB20050 */  sw    $s2, 0x50($sp)
/* 0D9F1C 8031EF1C AFB1004C */  sw    $s1, 0x4c($sp)
/* 0D9F20 8031EF20 AFB00048 */  sw    $s0, 0x48($sp)
/* 0D9F24 8031EF24 F7BE0040 */  sdc1  $f30, 0x40($sp)
/* 0D9F28 8031EF28 F7BC0038 */  sdc1  $f28, 0x38($sp)
/* 0D9F2C 8031EF2C F7BA0030 */  sdc1  $f26, 0x30($sp)
/* 0D9F30 8031EF30 F7B80028 */  sdc1  $f24, 0x28($sp)
/* 0D9F34 8031EF34 F7B60020 */  sdc1  $f22, 0x20($sp)
/* 0D9F38 8031EF38 F7B40018 */  sdc1  $f20, 0x18($sp)
/* 0D9F3C 8031EF3C 0C0C77D9 */  jal   func_8031DF64
/* 0D9F40 8031EF40 0000B025 */   move  $s6, $zero
/* 0D9F44 8031EF44 0C0C7E93 */  jal   func_8031FA4C
/* 0D9F48 8031EF48 00000000 */   nop   
/* 0D9F4C 8031EF4C 3C1E8022 */  lui   $fp, %hi(D_80222A18) # $fp, 0x8022
/* 0D9F50 8031EF50 27DE2A18 */  addiu $fp, %lo(D_80222A18) # addiu $fp, $fp, 0x2a18
/* 0D9F54 8031EF54 8FCF02AC */  lw    $t7, 0x2ac($fp)
/* 0D9F58 8031EF58 3C0E8022 */  lui   $t6, %hi(D_80225DD8) 
/* 0D9F5C 8031EF5C 25CE5DD8 */  addiu $t6, %lo(D_80225DD8) # addiu $t6, $t6, 0x5dd8
/* 0D9F60 8031EF60 11CF01B9 */  beq   $t6, $t7, .L8031F648
/* 0D9F64 8031EF64 0000A025 */   move  $s4, $zero
/* 0D9F68 8031EF68 3C014180 */  li    $at, 0x41800000 # 16.000000
/* 0D9F6C 8031EF6C 4481F000 */  mtc1  $at, $f30
/* 0D9F70 8031EF70 3C014100 */  li    $at, 0x41000000 # 8.000000
/* 0D9F74 8031EF74 4481E000 */  mtc1  $at, $f28
/* 0D9F78 8031EF78 3C014079 */  li    $at, 0x40790000 # 3.890625
/* 0D9F7C 8031EF7C 4481D800 */  mtc1  $at, $f27
/* 0D9F80 8031EF80 3C014054 */  li    $at, 0x40540000 # 3.312500
/* 0D9F84 8031EF84 4481C800 */  mtc1  $at, $f25
/* 0D9F88 8031EF88 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0D9F8C 8031EF8C 4481B000 */  mtc1  $at, $f22
/* 0D9F90 8031EF90 3C018034 */  lui   $at, %hi(D_803383B0)
/* 0D9F94 8031EF94 4480D000 */  mtc1  $zero, $f26
/* 0D9F98 8031EF98 4480C000 */  mtc1  $zero, $f24
/* 0D9F9C 8031EF9C C43483B0 */  lwc1  $f20, %lo(D_803383B0)($at)
.L8031EFA0:
/* 0D9FA0 8031EFA0 0C0C785B */  jal   func_8031E16C
/* 0D9FA4 8031EFA4 328400FF */   andi  $a0, $s4, 0xff
/* 0D9FA8 8031EFA8 3C188036 */  lui   $t8, %hi(D_80360C38) # $t8, 0x8036
/* 0D9FAC 8031EFAC 27180C38 */  addiu $t8, %lo(D_80360C38) # addiu $t8, $t8, 0xc38
/* 0D9FB0 8031EFB0 0298C821 */  addu  $t9, $s4, $t8
/* 0D9FB4 8031EFB4 AFB90070 */  sw    $t9, 0x70($sp)
/* 0D9FB8 8031EFB8 0000B825 */  move  $s7, $zero
.L8031EFBC:
/* 0D9FBC 8031EFBC 8FA80070 */  lw    $t0, 0x70($sp)
/* 0D9FC0 8031EFC0 001450C0 */  sll   $t2, $s4, 3
/* 0D9FC4 8031EFC4 01545021 */  addu  $t2, $t2, $s4
/* 0D9FC8 8031EFC8 01174821 */  addu  $t1, $t0, $s7
/* 0D9FCC 8031EFCC 91320000 */  lbu   $s2, ($t1)
/* 0D9FD0 8031EFD0 000A5080 */  sll   $t2, $t2, 2
/* 0D9FD4 8031EFD4 01545023 */  subu  $t2, $t2, $s4
/* 0D9FD8 8031EFD8 2A4100FF */  slti  $at, $s2, 0xff
/* 0D9FDC 8031EFDC 10200184 */  beqz  $at, .L8031F5F0
/* 0D9FE0 8031EFE0 000A5140 */   sll   $t2, $t2, 5
/* 0D9FE4 8031EFE4 001258C0 */  sll   $t3, $s2, 3
/* 0D9FE8 8031EFE8 01725823 */  subu  $t3, $t3, $s2
/* 0D9FEC 8031EFEC 000B5880 */  sll   $t3, $t3, 2
/* 0D9FF0 8031EFF0 3C0D8036 */  lui   $t5, %hi(D_80360C48) # $t5, 0x8036
/* 0D9FF4 8031EFF4 25AD0C48 */  addiu $t5, %lo(D_80360C48) # addiu $t5, $t5, 0xc48
/* 0D9FF8 8031EFF8 014B6021 */  addu  $t4, $t2, $t3
/* 0D9FFC 8031EFFC 018D8821 */  addu  $s1, $t4, $t5
/* 0DA000 8031F000 922E0018 */  lbu   $t6, 0x18($s1)
/* 0DA004 8031F004 51C0017B */  beql  $t6, $zero, .L8031F5F4
/* 0DA008 8031F008 26F70001 */   addiu $s7, $s7, 1
/* 0DA00C 8031F00C 8E230014 */  lw    $v1, 0x14($s1)
/* 0DA010 8031F010 24010001 */  li    $at, 1
/* 0DA014 8031F014 00601025 */  move  $v0, $v1
/* 0DA018 8031F018 3044000F */  andi  $a0, $v0, 0xf
/* 0DA01C 8031F01C 0003AC02 */  srl   $s5, $v1, 0x10
/* 0DA020 8031F020 32B800FF */  andi  $t8, $s5, 0xff
/* 0DA024 8031F024 00801025 */  move  $v0, $a0
/* 0DA028 8031F028 0300A825 */  move  $s5, $t8
/* 0DA02C 8031F02C 148100B7 */  bne   $a0, $at, .L8031F30C
/* 0DA030 8031F030 A2240018 */   sb    $a0, 0x18($s1)
/* 0DA034 8031F034 30790010 */  andi  $t9, $v1, 0x10
/* 0DA038 8031F038 1320000B */  beqz  $t9, .L8031F068
/* 0DA03C 8031F03C 02809825 */   move  $s3, $s4
/* 0DA040 8031F040 3C028033 */  lui   $v0, %hi(D_80332110) # $v0, 0x8033
/* 0DA044 8031F044 24422110 */  addiu $v0, %lo(D_80332110) # addiu $v0, $v0, 0x2110
/* 0DA048 8031F048 94480000 */  lhu   $t0, ($v0)
/* 0DA04C 8031F04C 24090001 */  li    $t1, 1
/* 0DA050 8031F050 02695004 */  sllv  $t2, $t1, $s3
/* 0DA054 8031F054 010A5825 */  or    $t3, $t0, $t2
/* 0DA058 8031F058 A44B0000 */  sh    $t3, ($v0)
/* 0DA05C 8031F05C 0C0C8039 */  jal   func_803200E4
/* 0DA060 8031F060 24040032 */   li    $a0, 50
/* 0DA064 8031F064 8E230014 */  lw    $v1, 0x14($s1)
.L8031F068:
/* 0DA068 8031F068 00167080 */  sll   $t6, $s6, 2
/* 0DA06C 8031F06C 03CE8021 */  addu  $s0, $fp, $t6
/* 0DA070 8031F070 8E0F02AC */  lw    $t7, 0x2ac($s0)
/* 0DA074 8031F074 246C0001 */  addiu $t4, $v1, 1
/* 0DA078 8031F078 240D0002 */  li    $t5, 2
/* 0DA07C 8031F07C AE2C0014 */  sw    $t4, 0x14($s1)
/* 0DA080 8031F080 A22D0018 */  sb    $t5, 0x18($s1)
/* 0DA084 8031F084 A1F50058 */  sb    $s5, 0x58($t7)
/* 0DA088 8031F088 8E1902AC */  lw    $t9, 0x2ac($s0)
/* 0DA08C 8031F08C 24180001 */  li    $t8, 1
/* 0DA090 8031F090 2E61000A */  sltiu $at, $s3, 0xa
/* 0DA094 8031F094 10200156 */  beqz  $at, .L8031F5F0
/* 0DA098 8031F098 A3380054 */   sb    $t8, 0x54($t9)
/* 0DA09C 8031F09C 00134880 */  sll   $t1, $s3, 2
/* 0DA0A0 8031F0A0 3C018034 */  lui   $at, %hi(jtbl_803383B4)
/* 0DA0A4 8031F0A4 00290821 */  addu  $at, $at, $t1
/* 0DA0A8 8031F0A8 8C2983B4 */  lw    $t1, %lo(jtbl_803383B4)($at)
/* 0DA0AC 8031F0AC 01200008 */  jr    $t1
/* 0DA0B0 8031F0B0 00000000 */   nop   
glabel L8031F0B4
/* 0DA0B4 8031F0B4 8E280014 */  lw    $t0, 0x14($s1)
/* 0DA0B8 8031F0B8 3C0B8036 */  lui   $t3, %hi(D_80363808) 
/* 0DA0BC 8031F0BC 256B3808 */  addiu $t3, %lo(D_80363808) # addiu $t3, $t3, 0x3808
/* 0DA0C0 8031F0C0 00085100 */  sll   $t2, $t0, 4
/* 0DA0C4 8031F0C4 05400056 */  bltz  $t2, .L8031F220
/* 0DA0C8 8031F0C8 028B9821 */   addu  $s3, $s4, $t3
/* 0DA0CC 8031F0CC 926C0000 */  lbu   $t4, ($s3)
/* 0DA0D0 8031F0D0 324500FF */  andi  $a1, $s2, 0xff
/* 0DA0D4 8031F0D4 328400FF */  andi  $a0, $s4, 0xff
/* 0DA0D8 8031F0D8 29810009 */  slti  $at, $t4, 9
/* 0DA0DC 8031F0DC 54200008 */  bnezl $at, .L8031F100
/* 0DA0E0 8031F0E0 4406A000 */   mfc1  $a2, $f20
/* 0DA0E4 8031F0E4 4406A000 */  mfc1  $a2, $f20
/* 0DA0E8 8031F0E8 0C0C7AC9 */  jal   func_8031EB24
/* 0DA0EC 8031F0EC 328400FF */   andi  $a0, $s4, 0xff
/* 0DA0F0 8031F0F0 8E0D02AC */  lw    $t5, 0x2ac($s0)
/* 0DA0F4 8031F0F4 10000011 */  b     .L8031F13C
/* 0DA0F8 8031F0F8 E5A00020 */   swc1  $f0, 0x20($t5)
/* 0DA0FC 8031F0FC 4406A000 */  mfc1  $a2, $f20
.L8031F100:
/* 0DA100 8031F100 0C0C7AC9 */  jal   func_8031EB24
/* 0DA104 8031F104 324500FF */   andi  $a1, $s2, 0xff
/* 0DA108 8031F108 926E0000 */  lbu   $t6, ($s3)
/* 0DA10C 8031F10C 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0DA110 8031F110 448E2000 */  mtc1  $t6, $f4
/* 0DA114 8031F114 05C10004 */  bgez  $t6, .L8031F128
/* 0DA118 8031F118 468021A0 */   cvt.s.w $f6, $f4
/* 0DA11C 8031F11C 44814000 */  mtc1  $at, $f8
/* 0DA120 8031F120 00000000 */  nop   
/* 0DA124 8031F124 46083180 */  add.s $f6, $f6, $f8
.L8031F128:
/* 0DA128 8031F128 461C3280 */  add.s $f10, $f6, $f28
/* 0DA12C 8031F12C 8E0F02AC */  lw    $t7, 0x2ac($s0)
/* 0DA130 8031F130 461E5403 */  div.s $f16, $f10, $f30
/* 0DA134 8031F134 46008482 */  mul.s $f18, $f16, $f0
/* 0DA138 8031F138 E5F20020 */  swc1  $f18, 0x20($t7)
.L8031F13C:
/* 0DA13C 8031F13C 8E380000 */  lw    $t8, ($s1)
/* 0DA140 8031F140 8E390008 */  lw    $t9, 8($s1)
/* 0DA144 8031F144 C70C0000 */  lwc1  $f12, ($t8)
/* 0DA148 8031F148 0C0C7A5F */  jal   func_8031E97C
/* 0DA14C 8031F14C C72E0000 */   lwc1  $f14, ($t9)
/* 0DA150 8031F150 8E0902AC */  lw    $t1, 0x2ac($s0)
/* 0DA154 8031F154 3C0100FF */  li    $at, 0x00FF0000 
/* 0DA158 8031F158 324500FF */  andi  $a1, $s2, 0xff
/* 0DA15C 8031F15C E5200024 */  swc1  $f0, 0x24($t1)
/* 0DA160 8031F160 8E280014 */  lw    $t0, 0x14($s1)
/* 0DA164 8031F164 328400FF */  andi  $a0, $s4, 0xff
/* 0DA168 8031F168 01015024 */  and   $t2, $t0, $at
/* 0DA16C 8031F16C 3C010017 */  li    $at, 0x00170000 
/* 0DA170 8031F170 15410013 */  bne   $t2, $at, .L8031F1C0
/* 0DA174 8031F174 00000000 */   nop   
/* 0DA178 8031F178 0C0C7B1F */  jal   func_8031EC7C
/* 0DA17C 8031F17C 328400FF */   andi  $a0, $s4, 0xff
/* 0DA180 8031F180 926B0000 */  lbu   $t3, ($s3)
/* 0DA184 8031F184 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0DA188 8031F188 448B2000 */  mtc1  $t3, $f4
/* 0DA18C 8031F18C 05610004 */  bgez  $t3, .L8031F1A0
/* 0DA190 8031F190 46802220 */   cvt.s.w $f8, $f4
/* 0DA194 8031F194 44813000 */  mtc1  $at, $f6
/* 0DA198 8031F198 00000000 */  nop   
/* 0DA19C 8031F19C 46064200 */  add.s $f8, $f8, $f6
.L8031F1A0:
/* 0DA1A0 8031F1A0 460042A1 */  cvt.d.s $f10, $f8
/* 0DA1A4 8031F1A4 460004A1 */  cvt.d.s $f18, $f0
/* 0DA1A8 8031F1A8 46385403 */  div.d $f16, $f10, $f24
/* 0DA1AC 8031F1AC 8E0C02AC */  lw    $t4, 0x2ac($s0)
/* 0DA1B0 8031F1B0 46328100 */  add.d $f4, $f16, $f18
/* 0DA1B4 8031F1B4 462021A0 */  cvt.s.d $f6, $f4
/* 0DA1B8 8031F1B8 10000012 */  b     .L8031F204
/* 0DA1BC 8031F1BC E586002C */   swc1  $f6, 0x2c($t4)
.L8031F1C0:
/* 0DA1C0 8031F1C0 0C0C7B1F */  jal   func_8031EC7C
/* 0DA1C4 8031F1C4 324500FF */   andi  $a1, $s2, 0xff
/* 0DA1C8 8031F1C8 926D0000 */  lbu   $t5, ($s3)
/* 0DA1CC 8031F1CC 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0DA1D0 8031F1D0 448D4000 */  mtc1  $t5, $f8
/* 0DA1D4 8031F1D4 05A10004 */  bgez  $t5, .L8031F1E8
/* 0DA1D8 8031F1D8 468042A0 */   cvt.s.w $f10, $f8
/* 0DA1DC 8031F1DC 44818000 */  mtc1  $at, $f16
/* 0DA1E0 8031F1E0 00000000 */  nop   
/* 0DA1E4 8031F1E4 46105280 */  add.s $f10, $f10, $f16
.L8031F1E8:
/* 0DA1E8 8031F1E8 460054A1 */  cvt.d.s $f18, $f10
/* 0DA1EC 8031F1EC 460001A1 */  cvt.d.s $f6, $f0
/* 0DA1F0 8031F1F0 463A9103 */  div.d $f4, $f18, $f26
/* 0DA1F4 8031F1F4 8E0E02AC */  lw    $t6, 0x2ac($s0)
/* 0DA1F8 8031F1F8 46262200 */  add.d $f8, $f4, $f6
/* 0DA1FC 8031F1FC 46204420 */  cvt.s.d $f16, $f8
/* 0DA200 8031F200 E5D0002C */  swc1  $f16, 0x2c($t6)
.L8031F204:
/* 0DA204 8031F204 328400FF */  andi  $a0, $s4, 0xff
/* 0DA208 8031F208 324500FF */  andi  $a1, $s2, 0xff
/* 0DA20C 8031F20C 0C0C7B5C */  jal   func_8031ED70
/* 0DA210 8031F210 32C600FF */   andi  $a2, $s6, 0xff
/* 0DA214 8031F214 8E0F02AC */  lw    $t7, 0x2ac($s0)
/* 0DA218 8031F218 100000F5 */  b     .L8031F5F0
/* 0DA21C 8031F21C A1E20003 */   sb    $v0, 3($t7)
.L8031F220:
glabel L8031F220
/* 0DA220 8031F220 8E1802AC */  lw    $t8, 0x2ac($s0)
/* 0DA224 8031F224 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0DA228 8031F228 44815000 */  mtc1  $at, $f10
/* 0DA22C 8031F22C E7160020 */  swc1  $f22, 0x20($t8)
/* 0DA230 8031F230 8E1902AC */  lw    $t9, 0x2ac($s0)
/* 0DA234 8031F234 E72A0024 */  swc1  $f10, 0x24($t9)
/* 0DA238 8031F238 8E0902AC */  lw    $t1, 0x2ac($s0)
/* 0DA23C 8031F23C 100000EC */  b     .L8031F5F0
/* 0DA240 8031F240 E536002C */   swc1  $f22, 0x2c($t1)
glabel L8031F244
/* 0DA244 8031F244 4406A000 */  mfc1  $a2, $f20
/* 0DA248 8031F248 328400FF */  andi  $a0, $s4, 0xff
/* 0DA24C 8031F24C 0C0C7AC9 */  jal   func_8031EB24
/* 0DA250 8031F250 324500FF */   andi  $a1, $s2, 0xff
/* 0DA254 8031F254 8E0802AC */  lw    $t0, 0x2ac($s0)
/* 0DA258 8031F258 E5000020 */  swc1  $f0, 0x20($t0)
/* 0DA25C 8031F25C 8E2B0008 */  lw    $t3, 8($s1)
/* 0DA260 8031F260 8E2A0000 */  lw    $t2, ($s1)
/* 0DA264 8031F264 C56E0000 */  lwc1  $f14, ($t3)
/* 0DA268 8031F268 0C0C7A5F */  jal   func_8031E97C
/* 0DA26C 8031F26C C54C0000 */   lwc1  $f12, ($t2)
/* 0DA270 8031F270 8E0C02AC */  lw    $t4, 0x2ac($s0)
/* 0DA274 8031F274 328400FF */  andi  $a0, $s4, 0xff
/* 0DA278 8031F278 324500FF */  andi  $a1, $s2, 0xff
/* 0DA27C 8031F27C 0C0C7B1F */  jal   func_8031EC7C
/* 0DA280 8031F280 E5800024 */   swc1  $f0, 0x24($t4)
/* 0DA284 8031F284 8E0D02AC */  lw    $t5, 0x2ac($s0)
/* 0DA288 8031F288 328400FF */  andi  $a0, $s4, 0xff
/* 0DA28C 8031F28C 324500FF */  andi  $a1, $s2, 0xff
/* 0DA290 8031F290 32C600FF */  andi  $a2, $s6, 0xff
/* 0DA294 8031F294 0C0C7B5C */  jal   func_8031ED70
/* 0DA298 8031F298 E5A0002C */   swc1  $f0, 0x2c($t5)
/* 0DA29C 8031F29C 8E0E02AC */  lw    $t6, 0x2ac($s0)
/* 0DA2A0 8031F2A0 100000D3 */  b     .L8031F5F0
/* 0DA2A4 8031F2A4 A1C20003 */   sb    $v0, 3($t6)
glabel L8031F2A8
/* 0DA2A8 8031F2A8 328400FF */  andi  $a0, $s4, 0xff
/* 0DA2AC 8031F2AC 324500FF */  andi  $a1, $s2, 0xff
/* 0DA2B0 8031F2B0 0C0C7B5C */  jal   func_8031ED70
/* 0DA2B4 8031F2B4 32C600FF */   andi  $a2, $s6, 0xff
/* 0DA2B8 8031F2B8 8E0F02AC */  lw    $t7, 0x2ac($s0)
/* 0DA2BC 8031F2BC 4406B000 */  mfc1  $a2, $f22
/* 0DA2C0 8031F2C0 328400FF */  andi  $a0, $s4, 0xff
/* 0DA2C4 8031F2C4 324500FF */  andi  $a1, $s2, 0xff
/* 0DA2C8 8031F2C8 0C0C7AC9 */  jal   func_8031EB24
/* 0DA2CC 8031F2CC A1E20003 */   sb    $v0, 3($t7)
/* 0DA2D0 8031F2D0 8E1802AC */  lw    $t8, 0x2ac($s0)
/* 0DA2D4 8031F2D4 E7000020 */  swc1  $f0, 0x20($t8)
/* 0DA2D8 8031F2D8 8E290008 */  lw    $t1, 8($s1)
/* 0DA2DC 8031F2DC 8E390000 */  lw    $t9, ($s1)
/* 0DA2E0 8031F2E0 C52E0000 */  lwc1  $f14, ($t1)
/* 0DA2E4 8031F2E4 0C0C7A5F */  jal   func_8031E97C
/* 0DA2E8 8031F2E8 C72C0000 */   lwc1  $f12, ($t9)
/* 0DA2EC 8031F2EC 8E0802AC */  lw    $t0, 0x2ac($s0)
/* 0DA2F0 8031F2F0 328400FF */  andi  $a0, $s4, 0xff
/* 0DA2F4 8031F2F4 324500FF */  andi  $a1, $s2, 0xff
/* 0DA2F8 8031F2F8 0C0C7B1F */  jal   func_8031EC7C
/* 0DA2FC 8031F2FC E5000024 */   swc1  $f0, 0x24($t0)
/* 0DA300 8031F300 8E0A02AC */  lw    $t2, 0x2ac($s0)
/* 0DA304 8031F304 100000BA */  b     .L8031F5F0
/* 0DA308 8031F308 E540002C */   swc1  $f0, 0x2c($t2)
.L8031F30C:
/* 0DA30C 8031F30C 1480000D */  bnez  $a0, .L8031F344
/* 0DA310 8031F310 00167080 */   sll   $t6, $s6, 2
/* 0DA314 8031F314 328400FF */  andi  $a0, $s4, 0xff
/* 0DA318 8031F318 0C0C7839 */  jal   func_8031E0E4
/* 0DA31C 8031F31C 324500FF */   andi  $a1, $s2, 0xff
/* 0DA320 8031F320 00165880 */  sll   $t3, $s6, 2
/* 0DA324 8031F324 03CB6021 */  addu  $t4, $fp, $t3
/* 0DA328 8031F328 8D8D02AC */  lw    $t5, 0x2ac($t4)
/* 0DA32C 8031F32C 328400FF */  andi  $a0, $s4, 0xff
/* 0DA330 8031F330 324500FF */  andi  $a1, $s2, 0xff
/* 0DA334 8031F334 0C0C77FA */  jal   func_8031DFE8
/* 0DA338 8031F338 A1A00054 */   sb    $zero, 0x54($t5)
/* 0DA33C 8031F33C 100000AD */  b     .L8031F5F4
/* 0DA340 8031F340 26F70001 */   addiu $s7, $s7, 1
.L8031F344:
/* 0DA344 8031F344 03CE8021 */  addu  $s0, $fp, $t6
/* 0DA348 8031F348 8E0202AC */  lw    $v0, 0x2ac($s0)
/* 0DA34C 8031F34C 328400FF */  andi  $a0, $s4, 0xff
/* 0DA350 8031F350 2E81000A */  sltiu $at, $s4, 0xa
/* 0DA354 8031F354 8C4F0044 */  lw    $t7, 0x44($v0)
/* 0DA358 8031F358 8DF80000 */  lw    $t8, ($t7)
/* 0DA35C 8031F35C 0018CFC2 */  srl   $t9, $t8, 0x1f
/* 0DA360 8031F360 17200009 */  bnez  $t9, .L8031F388
/* 0DA364 8031F364 00000000 */   nop   
/* 0DA368 8031F368 0C0C7839 */  jal   func_8031E0E4
/* 0DA36C 8031F36C 324500FF */   andi  $a1, $s2, 0xff
/* 0DA370 8031F370 A2200018 */  sb    $zero, 0x18($s1)
/* 0DA374 8031F374 328400FF */  andi  $a0, $s4, 0xff
/* 0DA378 8031F378 0C0C77FA */  jal   func_8031DFE8
/* 0DA37C 8031F37C 324500FF */   andi  $a1, $s2, 0xff
/* 0DA380 8031F380 1000009C */  b     .L8031F5F4
/* 0DA384 8031F384 26F70001 */   addiu $s7, $s7, 1
.L8031F388:
/* 0DA388 8031F388 10200099 */  beqz  $at, .L8031F5F0
/* 0DA38C 8031F38C 00144880 */   sll   $t1, $s4, 2
/* 0DA390 8031F390 3C018034 */  lui   $at, %hi(jtbl_803383DC)
/* 0DA394 8031F394 00290821 */  addu  $at, $at, $t1
/* 0DA398 8031F398 8C2983DC */  lw    $t1, %lo(jtbl_803383DC)($at)
/* 0DA39C 8031F39C 01200008 */  jr    $t1
/* 0DA3A0 8031F3A0 00000000 */   nop   
glabel L8031F3A4
/* 0DA3A4 8031F3A4 00034100 */  sll   $t0, $v1, 4
/* 0DA3A8 8031F3A8 05000058 */  bltz  $t0, .L8031F50C
/* 0DA3AC 8031F3AC 3C0A8036 */   lui    $t2, %hi(D_80363808) 
/* 0DA3B0 8031F3B0 254A3808 */  addiu $t2, %lo(D_80363808) # addiu $t2, $t2, 0x3808
/* 0DA3B4 8031F3B4 028A9821 */  addu  $s3, $s4, $t2
/* 0DA3B8 8031F3B8 926B0000 */  lbu   $t3, ($s3)
/* 0DA3BC 8031F3BC 324500FF */  andi  $a1, $s2, 0xff
/* 0DA3C0 8031F3C0 328400FF */  andi  $a0, $s4, 0xff
/* 0DA3C4 8031F3C4 29610009 */  slti  $at, $t3, 9
/* 0DA3C8 8031F3C8 54200008 */  bnezl $at, .L8031F3EC
/* 0DA3CC 8031F3CC 4406A000 */   mfc1  $a2, $f20
/* 0DA3D0 8031F3D0 4406A000 */  mfc1  $a2, $f20
/* 0DA3D4 8031F3D4 0C0C7AC9 */  jal   func_8031EB24
/* 0DA3D8 8031F3D8 328400FF */   andi  $a0, $s4, 0xff
/* 0DA3DC 8031F3DC 8E0C02AC */  lw    $t4, 0x2ac($s0)
/* 0DA3E0 8031F3E0 10000011 */  b     .L8031F428
/* 0DA3E4 8031F3E4 E5800020 */   swc1  $f0, 0x20($t4)
/* 0DA3E8 8031F3E8 4406A000 */  mfc1  $a2, $f20
.L8031F3EC:
/* 0DA3EC 8031F3EC 0C0C7AC9 */  jal   func_8031EB24
/* 0DA3F0 8031F3F0 324500FF */   andi  $a1, $s2, 0xff
/* 0DA3F4 8031F3F4 926D0000 */  lbu   $t5, ($s3)
/* 0DA3F8 8031F3F8 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0DA3FC 8031F3FC 448D9000 */  mtc1  $t5, $f18
/* 0DA400 8031F400 05A10004 */  bgez  $t5, .L8031F414
/* 0DA404 8031F404 46809120 */   cvt.s.w $f4, $f18
/* 0DA408 8031F408 44813000 */  mtc1  $at, $f6
/* 0DA40C 8031F40C 00000000 */  nop   
/* 0DA410 8031F410 46062100 */  add.s $f4, $f4, $f6
.L8031F414:
/* 0DA414 8031F414 461C2200 */  add.s $f8, $f4, $f28
/* 0DA418 8031F418 8E0E02AC */  lw    $t6, 0x2ac($s0)
/* 0DA41C 8031F41C 461E4403 */  div.s $f16, $f8, $f30
/* 0DA420 8031F420 46008282 */  mul.s $f10, $f16, $f0
/* 0DA424 8031F424 E5CA0020 */  swc1  $f10, 0x20($t6)
.L8031F428:
/* 0DA428 8031F428 8E2F0000 */  lw    $t7, ($s1)
/* 0DA42C 8031F42C 8E380008 */  lw    $t8, 8($s1)
/* 0DA430 8031F430 C5EC0000 */  lwc1  $f12, ($t7)
/* 0DA434 8031F434 0C0C7A5F */  jal   func_8031E97C
/* 0DA438 8031F438 C70E0000 */   lwc1  $f14, ($t8)
/* 0DA43C 8031F43C 8E1902AC */  lw    $t9, 0x2ac($s0)
/* 0DA440 8031F440 3C0100FF */  li    $at, 0x00FF0000 
/* 0DA444 8031F444 324500FF */  andi  $a1, $s2, 0xff
/* 0DA448 8031F448 E7200024 */  swc1  $f0, 0x24($t9)
/* 0DA44C 8031F44C 8E290014 */  lw    $t1, 0x14($s1)
/* 0DA450 8031F450 328400FF */  andi  $a0, $s4, 0xff
/* 0DA454 8031F454 01214024 */  and   $t0, $t1, $at
/* 0DA458 8031F458 3C010017 */  li    $at, 0x00170000 
/* 0DA45C 8031F45C 15010013 */  bne   $t0, $at, .L8031F4AC
/* 0DA460 8031F460 00000000 */   nop   
/* 0DA464 8031F464 0C0C7B1F */  jal   func_8031EC7C
/* 0DA468 8031F468 328400FF */   andi  $a0, $s4, 0xff
/* 0DA46C 8031F46C 926A0000 */  lbu   $t2, ($s3)
/* 0DA470 8031F470 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0DA474 8031F474 448A9000 */  mtc1  $t2, $f18
/* 0DA478 8031F478 05410004 */  bgez  $t2, .L8031F48C
/* 0DA47C 8031F47C 468091A0 */   cvt.s.w $f6, $f18
/* 0DA480 8031F480 44812000 */  mtc1  $at, $f4
/* 0DA484 8031F484 00000000 */  nop   
/* 0DA488 8031F488 46043180 */  add.s $f6, $f6, $f4
.L8031F48C:
/* 0DA48C 8031F48C 46003221 */  cvt.d.s $f8, $f6
/* 0DA490 8031F490 460002A1 */  cvt.d.s $f10, $f0
/* 0DA494 8031F494 46384403 */  div.d $f16, $f8, $f24
/* 0DA498 8031F498 8E0B02AC */  lw    $t3, 0x2ac($s0)
/* 0DA49C 8031F49C 462A8480 */  add.d $f18, $f16, $f10
/* 0DA4A0 8031F4A0 46209120 */  cvt.s.d $f4, $f18
/* 0DA4A4 8031F4A4 10000012 */  b     .L8031F4F0
/* 0DA4A8 8031F4A8 E564002C */   swc1  $f4, 0x2c($t3)
.L8031F4AC:
/* 0DA4AC 8031F4AC 0C0C7B1F */  jal   func_8031EC7C
/* 0DA4B0 8031F4B0 324500FF */   andi  $a1, $s2, 0xff
/* 0DA4B4 8031F4B4 926C0000 */  lbu   $t4, ($s3)
/* 0DA4B8 8031F4B8 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0DA4BC 8031F4BC 448C3000 */  mtc1  $t4, $f6
/* 0DA4C0 8031F4C0 05810004 */  bgez  $t4, .L8031F4D4
/* 0DA4C4 8031F4C4 46803220 */   cvt.s.w $f8, $f6
/* 0DA4C8 8031F4C8 44818000 */  mtc1  $at, $f16
/* 0DA4CC 8031F4CC 00000000 */  nop   
/* 0DA4D0 8031F4D0 46104200 */  add.s $f8, $f8, $f16
.L8031F4D4:
/* 0DA4D4 8031F4D4 460042A1 */  cvt.d.s $f10, $f8
/* 0DA4D8 8031F4D8 46000121 */  cvt.d.s $f4, $f0
/* 0DA4DC 8031F4DC 463A5483 */  div.d $f18, $f10, $f26
/* 0DA4E0 8031F4E0 8E0D02AC */  lw    $t5, 0x2ac($s0)
/* 0DA4E4 8031F4E4 46249180 */  add.d $f6, $f18, $f4
/* 0DA4E8 8031F4E8 46203420 */  cvt.s.d $f16, $f6
/* 0DA4EC 8031F4EC E5B0002C */  swc1  $f16, 0x2c($t5)
.L8031F4F0:
/* 0DA4F0 8031F4F0 328400FF */  andi  $a0, $s4, 0xff
/* 0DA4F4 8031F4F4 324500FF */  andi  $a1, $s2, 0xff
/* 0DA4F8 8031F4F8 0C0C7B5C */  jal   func_8031ED70
/* 0DA4FC 8031F4FC 32C600FF */   andi  $a2, $s6, 0xff
/* 0DA500 8031F500 8E0E02AC */  lw    $t6, 0x2ac($s0)
/* 0DA504 8031F504 1000003A */  b     .L8031F5F0
/* 0DA508 8031F508 A1C20003 */   sb    $v0, 3($t6)
.L8031F50C:
glabel L8031F50C
/* 0DA50C 8031F50C E4560020 */  swc1  $f22, 0x20($v0)
/* 0DA510 8031F510 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0DA514 8031F514 44814000 */  mtc1  $at, $f8
/* 0DA518 8031F518 8E0F02AC */  lw    $t7, 0x2ac($s0)
/* 0DA51C 8031F51C E5E80024 */  swc1  $f8, 0x24($t7)
/* 0DA520 8031F520 8E1802AC */  lw    $t8, 0x2ac($s0)
/* 0DA524 8031F524 10000032 */  b     .L8031F5F0
/* 0DA528 8031F528 E716002C */   swc1  $f22, 0x2c($t8)
glabel L8031F52C
/* 0DA52C 8031F52C 4406A000 */  mfc1  $a2, $f20
/* 0DA530 8031F530 328400FF */  andi  $a0, $s4, 0xff
/* 0DA534 8031F534 0C0C7AC9 */  jal   func_8031EB24
/* 0DA538 8031F538 324500FF */   andi  $a1, $s2, 0xff
/* 0DA53C 8031F53C 8E1902AC */  lw    $t9, 0x2ac($s0)
/* 0DA540 8031F540 E7200020 */  swc1  $f0, 0x20($t9)
/* 0DA544 8031F544 8E280008 */  lw    $t0, 8($s1)
/* 0DA548 8031F548 8E290000 */  lw    $t1, ($s1)
/* 0DA54C 8031F54C C50E0000 */  lwc1  $f14, ($t0)
/* 0DA550 8031F550 0C0C7A5F */  jal   func_8031E97C
/* 0DA554 8031F554 C52C0000 */   lwc1  $f12, ($t1)
/* 0DA558 8031F558 8E0A02AC */  lw    $t2, 0x2ac($s0)
/* 0DA55C 8031F55C 328400FF */  andi  $a0, $s4, 0xff
/* 0DA560 8031F560 324500FF */  andi  $a1, $s2, 0xff
/* 0DA564 8031F564 0C0C7B1F */  jal   func_8031EC7C
/* 0DA568 8031F568 E5400024 */   swc1  $f0, 0x24($t2)
/* 0DA56C 8031F56C 8E0B02AC */  lw    $t3, 0x2ac($s0)
/* 0DA570 8031F570 328400FF */  andi  $a0, $s4, 0xff
/* 0DA574 8031F574 324500FF */  andi  $a1, $s2, 0xff
/* 0DA578 8031F578 32C600FF */  andi  $a2, $s6, 0xff
/* 0DA57C 8031F57C 0C0C7B5C */  jal   func_8031ED70
/* 0DA580 8031F580 E560002C */   swc1  $f0, 0x2c($t3)
/* 0DA584 8031F584 8E0C02AC */  lw    $t4, 0x2ac($s0)
/* 0DA588 8031F588 10000019 */  b     .L8031F5F0
/* 0DA58C 8031F58C A1820003 */   sb    $v0, 3($t4)
glabel L8031F590
/* 0DA590 8031F590 328400FF */  andi  $a0, $s4, 0xff
/* 0DA594 8031F594 324500FF */  andi  $a1, $s2, 0xff
/* 0DA598 8031F598 0C0C7B5C */  jal   func_8031ED70
/* 0DA59C 8031F59C 32C600FF */   andi  $a2, $s6, 0xff
/* 0DA5A0 8031F5A0 8E0D02AC */  lw    $t5, 0x2ac($s0)
/* 0DA5A4 8031F5A4 4406B000 */  mfc1  $a2, $f22
/* 0DA5A8 8031F5A8 328400FF */  andi  $a0, $s4, 0xff
/* 0DA5AC 8031F5AC 324500FF */  andi  $a1, $s2, 0xff
/* 0DA5B0 8031F5B0 0C0C7AC9 */  jal   func_8031EB24
/* 0DA5B4 8031F5B4 A1A20003 */   sb    $v0, 3($t5)
/* 0DA5B8 8031F5B8 8E0E02AC */  lw    $t6, 0x2ac($s0)
/* 0DA5BC 8031F5BC E5C00020 */  swc1  $f0, 0x20($t6)
/* 0DA5C0 8031F5C0 8E380008 */  lw    $t8, 8($s1)
/* 0DA5C4 8031F5C4 8E2F0000 */  lw    $t7, ($s1)
/* 0DA5C8 8031F5C8 C70E0000 */  lwc1  $f14, ($t8)
/* 0DA5CC 8031F5CC 0C0C7A5F */  jal   func_8031E97C
/* 0DA5D0 8031F5D0 C5EC0000 */   lwc1  $f12, ($t7)
/* 0DA5D4 8031F5D4 8E1902AC */  lw    $t9, 0x2ac($s0)
/* 0DA5D8 8031F5D8 328400FF */  andi  $a0, $s4, 0xff
/* 0DA5DC 8031F5DC 324500FF */  andi  $a1, $s2, 0xff
/* 0DA5E0 8031F5E0 0C0C7B1F */  jal   func_8031EC7C
/* 0DA5E4 8031F5E4 E7200024 */   swc1  $f0, 0x24($t9)
/* 0DA5E8 8031F5E8 8E0902AC */  lw    $t1, 0x2ac($s0)
/* 0DA5EC 8031F5EC E520002C */  swc1  $f0, 0x2c($t1)
.L8031F5F0:
/* 0DA5F0 8031F5F0 26F70001 */  addiu $s7, $s7, 1
.L8031F5F4:
/* 0DA5F4 8031F5F4 26D60001 */  addiu $s6, $s6, 1
/* 0DA5F8 8031F5F8 32EA00FF */  andi  $t2, $s7, 0xff
/* 0DA5FC 8031F5FC 32C800FF */  andi  $t0, $s6, 0xff
/* 0DA600 8031F600 0140B825 */  move  $s7, $t2
/* 0DA604 8031F604 1940FE6D */  blez  $t2, .L8031EFBC
/* 0DA608 8031F608 0100B025 */   move  $s6, $t0
/* 0DA60C 8031F60C 3C0B8033 */  lui   $t3, %hi(D_803320C8)
/* 0DA610 8031F610 01745821 */  addu  $t3, $t3, $s4
/* 0DA614 8031F614 3C0D8036 */  lui   $t5, %hi(D_80360C28)
/* 0DA618 8031F618 916B20C8 */  lbu   $t3, %lo(D_803320C8)($t3)
/* 0DA61C 8031F61C 01B46821 */  addu  $t5, $t5, $s4
/* 0DA620 8031F620 91AD0C28 */  lbu   $t5, %lo(D_80360C28)($t5)
/* 0DA624 8031F624 26940001 */  addiu $s4, $s4, 1
/* 0DA628 8031F628 010B6021 */  addu  $t4, $t0, $t3
/* 0DA62C 8031F62C 328F00FF */  andi  $t7, $s4, 0xff
/* 0DA630 8031F630 018DB023 */  subu  $s6, $t4, $t5
/* 0DA634 8031F634 29E1000A */  slti  $at, $t7, 0xa
/* 0DA638 8031F638 32CE00FF */  andi  $t6, $s6, 0xff
/* 0DA63C 8031F63C 01E0A025 */  move  $s4, $t7
/* 0DA640 8031F640 1420FE57 */  bnez  $at, .L8031EFA0
/* 0DA644 8031F644 01C0B025 */   move  $s6, $t6
.L8031F648:
/* 0DA648 8031F648 8FBF006C */  lw    $ra, 0x6c($sp)
/* 0DA64C 8031F64C D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0DA650 8031F650 D7B60020 */  ldc1  $f22, 0x20($sp)
/* 0DA654 8031F654 D7B80028 */  ldc1  $f24, 0x28($sp)
/* 0DA658 8031F658 D7BA0030 */  ldc1  $f26, 0x30($sp)
/* 0DA65C 8031F65C D7BC0038 */  ldc1  $f28, 0x38($sp)
/* 0DA660 8031F660 D7BE0040 */  ldc1  $f30, 0x40($sp)
/* 0DA664 8031F664 8FB00048 */  lw    $s0, 0x48($sp)
/* 0DA668 8031F668 8FB1004C */  lw    $s1, 0x4c($sp)
/* 0DA66C 8031F66C 8FB20050 */  lw    $s2, 0x50($sp)
/* 0DA670 8031F670 8FB30054 */  lw    $s3, 0x54($sp)
/* 0DA674 8031F674 8FB40058 */  lw    $s4, 0x58($sp)
/* 0DA678 8031F678 8FB5005C */  lw    $s5, 0x5c($sp)
/* 0DA67C 8031F67C 8FB60060 */  lw    $s6, 0x60($sp)
/* 0DA680 8031F680 8FB70064 */  lw    $s7, 0x64($sp)
/* 0DA684 8031F684 8FBE0068 */  lw    $fp, 0x68($sp)
/* 0DA688 8031F688 03E00008 */  jr    $ra
/* 0DA68C 8031F68C 27BD0080 */   addiu $sp, $sp, 0x80
)
#else
GLOBAL_ASM(
.late_rodata

glabel D_U_80339738
glabel D_803383B0
    .word 0x3F666666

glabel jtbl_803383B4
    .word L_U_803200D4
    .word L_U_8031FF5C
    .word L_U_803200D4
    .word L_U_80320138
    .word L_U_80320138
    .word L_U_80320138
    .word L_U_80320138
    .word L_U_803200B0
    .word L_U_80320138
    .word L_U_80320138

glabel jtbl_803383DC
    .word L_U_803203DC
    .word L_U_8032026C
    .word L_U_803203DC
    .word L_U_80320440
    .word L_U_80320440
    .word L_U_80320440
    .word L_U_80320440
    .word L_U_803203BC
    .word L_U_80320440
    .word L_U_80320440

.text
glabel func_8031EEF8 # US: 8031FDAC
/* 0DADAC 8031FDAC 27BDFF80 */  addiu $sp, $sp, -0x80
/* 0DADB0 8031FDB0 AFBF006C */  sw    $ra, 0x6c($sp)
/* 0DADB4 8031FDB4 AFB60060 */  sw    $s6, 0x60($sp)
/* 0DADB8 8031FDB8 AFBE0068 */  sw    $fp, 0x68($sp)
/* 0DADBC 8031FDBC AFB70064 */  sw    $s7, 0x64($sp)
/* 0DADC0 8031FDC0 AFB5005C */  sw    $s5, 0x5c($sp)
/* 0DADC4 8031FDC4 AFB40058 */  sw    $s4, 0x58($sp)
/* 0DADC8 8031FDC8 AFB30054 */  sw    $s3, 0x54($sp)
/* 0DADCC 8031FDCC AFB20050 */  sw    $s2, 0x50($sp)
/* 0DADD0 8031FDD0 AFB1004C */  sw    $s1, 0x4c($sp)
/* 0DADD4 8031FDD4 AFB00048 */  sw    $s0, 0x48($sp)
/* 0DADD8 8031FDD8 F7BE0040 */  sdc1  $f30, 0x40($sp)
/* 0DADDC 8031FDDC F7BC0038 */  sdc1  $f28, 0x38($sp)
/* 0DADE0 8031FDE0 F7BA0030 */  sdc1  $f26, 0x30($sp)
/* 0DADE4 8031FDE4 F7B80028 */  sdc1  $f24, 0x28($sp)
/* 0DADE8 8031FDE8 F7B60020 */  sdc1  $f22, 0x20($sp)
/* 0DADEC 8031FDEC F7B40018 */  sdc1  $f20, 0x18($sp)
/* 0DADF0 8031FDF0 0C0C7B7B */  jal   func_8031DF64
/* 0DADF4 8031FDF4 0000B025 */   move  $s6, $zero
/* 0DADF8 8031FDF8 0C0C823B */  jal   func_8031FA4C
/* 0DADFC 8031FDFC 00000000 */   nop   
/* 0DAE00 8031FE00 3C1E8022 */  lui   $fp, %hi(D_80222A18) # $fp, 0x8022
/* 0DAE04 8031FE04 27DE2618 */  addiu $fp, %lo(D_80222A18) # addiu $fp, $fp, 0x2618
/* 0DAE08 8031FE08 8FCF02AC */  lw    $t7, 0x2ac($fp)
/* 0DAE0C 8031FE0C 3C0E8022 */  lui   $t6, %hi(D_80225DD8) # $t6, 0x8022
/* 0DAE10 8031FE10 25CE5BD8 */  addiu $t6, %lo(D_80225DD8) # addiu $t6, $t6, 0x5bd8
/* 0DAE14 8031FE14 11CF01B9 */  beq   $t6, $t7, .L_U_803204FC
/* 0DAE18 8031FE18 0000A025 */   move  $s4, $zero
/* 0DAE1C 8031FE1C 3C014180 */  li    $at, 0x41800000 # 16.000000
/* 0DAE20 8031FE20 4481F000 */  mtc1  $at, $f30
/* 0DAE24 8031FE24 3C014100 */  li    $at, 0x41000000 # 8.000000
/* 0DAE28 8031FE28 4481E000 */  mtc1  $at, $f28
/* 0DAE2C 8031FE2C 3C0143C8 */  li    $at, 0x43C80000 # 400.000000
/* 0DAE30 8031FE30 4481D000 */  mtc1  $at, $f26
/* 0DAE34 8031FE34 3C0142A0 */  li    $at, 0x42A00000 # 80.000000
/* 0DAE38 8031FE38 4481C000 */  mtc1  $at, $f24
/* 0DAE3C 8031FE3C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0DAE40 8031FE40 4481B000 */  mtc1  $at, $f22
/* 0DAE44 8031FE44 3C018034 */  lui   $at, %hi(D_U_80339738) # $at, 0x8034
/* 0DAE48 8031FE48 C4349738 */  lwc1  $f20, %lo(D_U_80339738)($at)
.L_U_8031FE4C:
/* 0DAE4C 8031FE4C 0C0C7BFD */  jal   func_8031E16C
/* 0DAE50 8031FE50 328400FF */   andi  $a0, $s4, 0xff
/* 0DAE54 8031FE54 3C188036 */  lui   $t8, %hi(D_80360C38) # $t8, 0x8036
/* 0DAE58 8031FE58 27181FA8 */  addiu $t8, %lo(D_80360C38) # addiu $t8, $t8, 0x1fa8
/* 0DAE5C 8031FE5C 0298C821 */  addu  $t9, $s4, $t8
/* 0DAE60 8031FE60 AFB90070 */  sw    $t9, 0x70($sp)
/* 0DAE64 8031FE64 0000B825 */  move  $s7, $zero
.L_U_8031FE68:
/* 0DAE68 8031FE68 8FA80070 */  lw    $t0, 0x70($sp)
/* 0DAE6C 8031FE6C 001450C0 */  sll   $t2, $s4, 3
/* 0DAE70 8031FE70 01545021 */  addu  $t2, $t2, $s4
/* 0DAE74 8031FE74 01174821 */  addu  $t1, $t0, $s7
/* 0DAE78 8031FE78 91320000 */  lbu   $s2, ($t1)
/* 0DAE7C 8031FE7C 000A5080 */  sll   $t2, $t2, 2
/* 0DAE80 8031FE80 01545023 */  subu  $t2, $t2, $s4
/* 0DAE84 8031FE84 2A4100FF */  slti  $at, $s2, 0xff
/* 0DAE88 8031FE88 10200186 */  beqz  $at, .L_U_803204A4
/* 0DAE8C 8031FE8C 000A5140 */   sll   $t2, $t2, 5
/* 0DAE90 8031FE90 001258C0 */  sll   $t3, $s2, 3
/* 0DAE94 8031FE94 01725823 */  subu  $t3, $t3, $s2
/* 0DAE98 8031FE98 000B5880 */  sll   $t3, $t3, 2
/* 0DAE9C 8031FE9C 3C0D8036 */  lui   $t5, %hi(D_80360C48) # $t5, 0x8036
/* 0DAEA0 8031FEA0 25AD1FB8 */  addiu $t5, %lo(D_80360C48) # addiu $t5, $t5, 0x1fb8
/* 0DAEA4 8031FEA4 014B6021 */  addu  $t4, $t2, $t3
/* 0DAEA8 8031FEA8 018D8821 */  addu  $s1, $t4, $t5
/* 0DAEAC 8031FEAC 922E0018 */  lbu   $t6, 0x18($s1)
/* 0DAEB0 8031FEB0 51C0017D */  beql  $t6, $zero, .L_U_803204A8
/* 0DAEB4 8031FEB4 26F70001 */   addiu $s7, $s7, 1
/* 0DAEB8 8031FEB8 8E230014 */  lw    $v1, 0x14($s1)
/* 0DAEBC 8031FEBC 24010001 */  li    $at, 1
/* 0DAEC0 8031FEC0 00165880 */  sll   $t3, $s6, 2
/* 0DAEC4 8031FEC4 0003AC02 */  srl   $s5, $v1, 0x10
/* 0DAEC8 8031FEC8 32B800FF */  andi  $t8, $s5, 0xff
/* 0DAECC 8031FECC 3064000F */  andi  $a0, $v1, 0xf
/* 0DAED0 8031FED0 0300A825 */  move  $s5, $t8
/* 0DAED4 8031FED4 148100B2 */  bne   $a0, $at, .L_U_803201A0
/* 0DAED8 8031FED8 A2240018 */   sb    $a0, 0x18($s1)
/* 0DAEDC 8031FEDC 30790010 */  andi  $t9, $v1, 0x10
/* 0DAEE0 8031FEE0 1320000B */  beqz  $t9, .L_U_8031FF10
/* 0DAEE4 8031FEE4 02809825 */   move  $s3, $s4
/* 0DAEE8 8031FEE8 3C028033 */  lui   $v0, %hi(D_80332110) # $v0, 0x8033
/* 0DAEEC 8031FEEC 24423220 */  addiu $v0, %lo(D_80332110) # addiu $v0, $v0, 0x3220
/* 0DAEF0 8031FEF0 94480000 */  lhu   $t0, ($v0)
/* 0DAEF4 8031FEF4 24090001 */  li    $t1, 1
/* 0DAEF8 8031FEF8 02695004 */  sllv  $t2, $t1, $s3
/* 0DAEFC 8031FEFC 010A5825 */  or    $t3, $t0, $t2
/* 0DAF00 8031FF00 A44B0000 */  sh    $t3, ($v0)
/* 0DAF04 8031FF04 0C0C83DA */  jal   func_803200E4
/* 0DAF08 8031FF08 24040032 */   li    $a0, 50
/* 0DAF0C 8031FF0C 8E230014 */  lw    $v1, 0x14($s1)
.L_U_8031FF10:
/* 0DAF10 8031FF10 00167080 */  sll   $t6, $s6, 2
/* 0DAF14 8031FF14 03CE8021 */  addu  $s0, $fp, $t6
/* 0DAF18 8031FF18 8E0F02AC */  lw    $t7, 0x2ac($s0)
/* 0DAF1C 8031FF1C 246C0001 */  addiu $t4, $v1, 1
/* 0DAF20 8031FF20 240D0002 */  li    $t5, 2
/* 0DAF24 8031FF24 AE2C0014 */  sw    $t4, 0x14($s1)
/* 0DAF28 8031FF28 A22D0018 */  sb    $t5, 0x18($s1)
/* 0DAF2C 8031FF2C A1F50058 */  sb    $s5, 0x58($t7)
/* 0DAF30 8031FF30 8E1902AC */  lw    $t9, 0x2ac($s0)
/* 0DAF34 8031FF34 24180001 */  li    $t8, 1
/* 0DAF38 8031FF38 2E61000A */  sltiu $at, $s3, 0xa
/* 0DAF3C 8031FF3C 10200159 */  beqz  $at, .L_U_803204A4
/* 0DAF40 8031FF40 A3380054 */   sb    $t8, 0x54($t9)
/* 0DAF44 8031FF44 00134880 */  sll   $t1, $s3, 2
/* 0DAF48 8031FF48 3C018034 */  lui   $at, %hi(jtbl_803383B4)
/* 0DAF4C 8031FF4C 00290821 */  addu  $at, $at, $t1
/* 0DAF50 8031FF50 8C29973C */  lw    $t1, %lo(jtbl_803383B4)($at)
/* 0DAF54 8031FF54 01200008 */  jr    $t1
/* 0DAF58 8031FF58 00000000 */   nop   
glabel L_U_8031FF5C
/* 0DAF5C 8031FF5C 8E280014 */  lw    $t0, 0x14($s1)
/* 0DAF60 8031FF60 3C0B8036 */  lui   $t3, %hi(D_80363808) # $t3, 0x8036
/* 0DAF64 8031FF64 256B4B78 */  addiu $t3, %lo(D_80363808) # addiu $t3, $t3, 0x4b78
/* 0DAF68 8031FF68 00085100 */  sll   $t2, $t0, 4
/* 0DAF6C 8031FF6C 05400050 */  bltz  $t2, .L_U_803200B0
/* 0DAF70 8031FF70 028B9821 */   addu  $s3, $s4, $t3
/* 0DAF74 8031FF74 926C0000 */  lbu   $t4, ($s3)
/* 0DAF78 8031FF78 324500FF */  andi  $a1, $s2, 0xff
/* 0DAF7C 8031FF7C 328400FF */  andi  $a0, $s4, 0xff
/* 0DAF80 8031FF80 29810009 */  slti  $at, $t4, 9
/* 0DAF84 8031FF84 54200008 */  bnezl $at, .L_U_8031FFA8
/* 0DAF88 8031FF88 4406A000 */   mfc1  $a2, $f20
/* 0DAF8C 8031FF8C 4406A000 */  mfc1  $a2, $f20
/* 0DAF90 8031FF90 0C0C7E5B */  jal   func_8031EB24
/* 0DAF94 8031FF94 328400FF */   andi  $a0, $s4, 0xff
/* 0DAF98 8031FF98 8E0D02AC */  lw    $t5, 0x2ac($s0)
/* 0DAF9C 8031FF9C 10000011 */  b     .L_U_8031FFE4
/* 0DAFA0 8031FFA0 E5A00020 */   swc1  $f0, 0x20($t5)
/* 0DAFA4 8031FFA4 4406A000 */  mfc1  $a2, $f20
.L_U_8031FFA8:
/* 0DAFA8 8031FFA8 0C0C7E5B */  jal   func_8031EB24
/* 0DAFAC 8031FFAC 324500FF */   andi  $a1, $s2, 0xff
/* 0DAFB0 8031FFB0 926E0000 */  lbu   $t6, ($s3)
/* 0DAFB4 8031FFB4 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0DAFB8 8031FFB8 448E2000 */  mtc1  $t6, $f4
/* 0DAFBC 8031FFBC 05C10004 */  bgez  $t6, .L_U_8031FFD0
/* 0DAFC0 8031FFC0 468021A0 */   cvt.s.w $f6, $f4
/* 0DAFC4 8031FFC4 44814000 */  mtc1  $at, $f8
/* 0DAFC8 8031FFC8 00000000 */  nop   
/* 0DAFCC 8031FFCC 46083180 */  add.s $f6, $f6, $f8
.L_U_8031FFD0:
/* 0DAFD0 8031FFD0 461C3280 */  add.s $f10, $f6, $f28
/* 0DAFD4 8031FFD4 8E0F02AC */  lw    $t7, 0x2ac($s0)
/* 0DAFD8 8031FFD8 461E5403 */  div.s $f16, $f10, $f30
/* 0DAFDC 8031FFDC 46008482 */  mul.s $f18, $f16, $f0
/* 0DAFE0 8031FFE0 E5F20020 */  swc1  $f18, 0x20($t7)
.L_U_8031FFE4:
/* 0DAFE4 8031FFE4 8E380000 */  lw    $t8, ($s1)
/* 0DAFE8 8031FFE8 8E390008 */  lw    $t9, 8($s1)
/* 0DAFEC 8031FFEC C70C0000 */  lwc1  $f12, ($t8)
/* 0DAFF0 8031FFF0 0C0C7E04 */  jal   func_8031E97C
/* 0DAFF4 8031FFF4 C72E0000 */   lwc1  $f14, ($t9)
/* 0DAFF8 8031FFF8 8E0902AC */  lw    $t1, 0x2ac($s0)
/* 0DAFFC 8031FFFC 3C0100FF */  lui   $at, 0xff
/* 0DB000 80320000 324500FF */  andi  $a1, $s2, 0xff
/* 0DB004 80320004 E5200024 */  swc1  $f0, 0x24($t1)
/* 0DB008 80320008 8E280014 */  lw    $t0, 0x14($s1)
/* 0DB00C 8032000C 328400FF */  andi  $a0, $s4, 0xff
/* 0DB010 80320010 01015024 */  and   $t2, $t0, $at
/* 0DB014 80320014 3C010017 */  lui   $at, 0x17
/* 0DB018 80320018 15410010 */  bne   $t2, $at, .L_U_8032005C
/* 0DB01C 8032001C 00000000 */   nop   
/* 0DB020 80320020 0C0C7EC8 */  jal   func_8031EC7C
/* 0DB024 80320024 328400FF */   andi  $a0, $s4, 0xff
/* 0DB028 80320028 926B0000 */  lbu   $t3, ($s3)
/* 0DB02C 8032002C 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0DB030 80320030 448B2000 */  mtc1  $t3, $f4
/* 0DB034 80320034 05610004 */  bgez  $t3, .L_U_80320048
/* 0DB038 80320038 46802220 */   cvt.s.w $f8, $f4
/* 0DB03C 8032003C 44813000 */  mtc1  $at, $f6
/* 0DB040 80320040 00000000 */  nop   
/* 0DB044 80320044 46064200 */  add.s $f8, $f8, $f6
.L_U_80320048:
/* 0DB048 80320048 46184283 */  div.s $f10, $f8, $f24
/* 0DB04C 8032004C 8E0C02AC */  lw    $t4, 0x2ac($s0)
/* 0DB050 80320050 46005400 */  add.s $f16, $f10, $f0
/* 0DB054 80320054 1000000F */  b     .L_U_80320094
/* 0DB058 80320058 E590002C */   swc1  $f16, 0x2c($t4)
.L_U_8032005C:
/* 0DB05C 8032005C 0C0C7EC8 */  jal   func_8031EC7C
/* 0DB060 80320060 324500FF */   andi  $a1, $s2, 0xff
/* 0DB064 80320064 926D0000 */  lbu   $t5, ($s3)
/* 0DB068 80320068 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0DB06C 8032006C 448D9000 */  mtc1  $t5, $f18
/* 0DB070 80320070 05A10004 */  bgez  $t5, .L_U_80320084
/* 0DB074 80320074 46809120 */   cvt.s.w $f4, $f18
/* 0DB078 80320078 44813000 */  mtc1  $at, $f6
/* 0DB07C 8032007C 00000000 */  nop   
/* 0DB080 80320080 46062100 */  add.s $f4, $f4, $f6
.L_U_80320084:
/* 0DB084 80320084 461A2203 */  div.s $f8, $f4, $f26
/* 0DB088 80320088 8E0E02AC */  lw    $t6, 0x2ac($s0)
/* 0DB08C 8032008C 46004280 */  add.s $f10, $f8, $f0
/* 0DB090 80320090 E5CA002C */  swc1  $f10, 0x2c($t6)
.L_U_80320094:
/* 0DB094 80320094 328400FF */  andi  $a0, $s4, 0xff
/* 0DB098 80320098 324500FF */  andi  $a1, $s2, 0xff
/* 0DB09C 8032009C 0C0C7EFA */  jal   func_8031ED70
/* 0DB0A0 803200A0 32C600FF */   andi  $a2, $s6, 0xff
/* 0DB0A4 803200A4 8E0F02AC */  lw    $t7, 0x2ac($s0)
/* 0DB0A8 803200A8 100000FE */  b     .L_U_803204A4
/* 0DB0AC 803200AC A1E20003 */   sb    $v0, 3($t7)
glabel L_U_803200B0
.L_U_803200B0:
/* 0DB0B0 803200B0 8E1802AC */  lw    $t8, 0x2ac($s0)
/* 0DB0B4 803200B4 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0DB0B8 803200B8 44818000 */  mtc1  $at, $f16
/* 0DB0BC 803200BC E7160020 */  swc1  $f22, 0x20($t8)
/* 0DB0C0 803200C0 8E1902AC */  lw    $t9, 0x2ac($s0)
/* 0DB0C4 803200C4 E7300024 */  swc1  $f16, 0x24($t9)
/* 0DB0C8 803200C8 8E0902AC */  lw    $t1, 0x2ac($s0)
/* 0DB0CC 803200CC 100000F5 */  b     .L_U_803204A4
/* 0DB0D0 803200D0 E536002C */   swc1  $f22, 0x2c($t1)
glabel L_U_803200D4
/* 0DB0D4 803200D4 4406A000 */  mfc1  $a2, $f20
/* 0DB0D8 803200D8 328400FF */  andi  $a0, $s4, 0xff
/* 0DB0DC 803200DC 0C0C7E5B */  jal   func_8031EB24
/* 0DB0E0 803200E0 324500FF */   andi  $a1, $s2, 0xff
/* 0DB0E4 803200E4 8E0802AC */  lw    $t0, 0x2ac($s0)
/* 0DB0E8 803200E8 E5000020 */  swc1  $f0, 0x20($t0)
/* 0DB0EC 803200EC 8E2B0008 */  lw    $t3, 8($s1)
/* 0DB0F0 803200F0 8E2A0000 */  lw    $t2, ($s1)
/* 0DB0F4 803200F4 C56E0000 */  lwc1  $f14, ($t3)
/* 0DB0F8 803200F8 0C0C7E04 */  jal   func_8031E97C
/* 0DB0FC 803200FC C54C0000 */   lwc1  $f12, ($t2)
/* 0DB100 80320100 8E0C02AC */  lw    $t4, 0x2ac($s0)
/* 0DB104 80320104 328400FF */  andi  $a0, $s4, 0xff
/* 0DB108 80320108 324500FF */  andi  $a1, $s2, 0xff
/* 0DB10C 8032010C 0C0C7EC8 */  jal   func_8031EC7C
/* 0DB110 80320110 E5800024 */   swc1  $f0, 0x24($t4)
/* 0DB114 80320114 8E0D02AC */  lw    $t5, 0x2ac($s0)
/* 0DB118 80320118 328400FF */  andi  $a0, $s4, 0xff
/* 0DB11C 8032011C 324500FF */  andi  $a1, $s2, 0xff
/* 0DB120 80320120 32C600FF */  andi  $a2, $s6, 0xff
/* 0DB124 80320124 0C0C7EFA */  jal   func_8031ED70
/* 0DB128 80320128 E5A0002C */   swc1  $f0, 0x2c($t5)
/* 0DB12C 8032012C 8E0E02AC */  lw    $t6, 0x2ac($s0)
/* 0DB130 80320130 100000DC */  b     .L_U_803204A4
/* 0DB134 80320134 A1C20003 */   sb    $v0, 3($t6)
glabel L_U_80320138
/* 0DB138 80320138 328400FF */  andi  $a0, $s4, 0xff
/* 0DB13C 8032013C 324500FF */  andi  $a1, $s2, 0xff
/* 0DB140 80320140 0C0C7EFA */  jal   func_8031ED70
/* 0DB144 80320144 32C600FF */   andi  $a2, $s6, 0xff
/* 0DB148 80320148 8E0F02AC */  lw    $t7, 0x2ac($s0)
/* 0DB14C 8032014C 3C063F4C */  lui   $a2, (0x3F4CCCCD >> 16) # lui $a2, 0x3f4c
/* 0DB150 80320150 34C6CCCD */  ori   $a2, (0x3F4CCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
/* 0DB154 80320154 328400FF */  andi  $a0, $s4, 0xff
/* 0DB158 80320158 324500FF */  andi  $a1, $s2, 0xff
/* 0DB15C 8032015C 0C0C7E5B */  jal   func_8031EB24
/* 0DB160 80320160 A1E20003 */   sb    $v0, 3($t7)
/* 0DB164 80320164 8E1802AC */  lw    $t8, 0x2ac($s0)
/* 0DB168 80320168 E7000020 */  swc1  $f0, 0x20($t8)
/* 0DB16C 8032016C 8E290008 */  lw    $t1, 8($s1)
/* 0DB170 80320170 8E390000 */  lw    $t9, ($s1)
/* 0DB174 80320174 C52E0000 */  lwc1  $f14, ($t1)
/* 0DB178 80320178 0C0C7E04 */  jal   func_8031E97C
/* 0DB17C 8032017C C72C0000 */   lwc1  $f12, ($t9)
/* 0DB180 80320180 8E0802AC */  lw    $t0, 0x2ac($s0)
/* 0DB184 80320184 328400FF */  andi  $a0, $s4, 0xff
/* 0DB188 80320188 324500FF */  andi  $a1, $s2, 0xff
/* 0DB18C 8032018C 0C0C7EC8 */  jal   func_8031EC7C
/* 0DB190 80320190 E5000024 */   swc1  $f0, 0x24($t0)
/* 0DB194 80320194 8E0A02AC */  lw    $t2, 0x2ac($s0)
/* 0DB198 80320198 100000C2 */  b     .L_U_803204A4
/* 0DB19C 8032019C E540002C */   swc1  $f0, 0x2c($t2)
.L_U_803201A0:
/* 0DB1A0 803201A0 03CB8021 */  addu  $s0, $fp, $t3
/* 0DB1A4 803201A4 8E0502AC */  lw    $a1, 0x2ac($s0)
/* 0DB1A8 803201A8 8CA20044 */  lw    $v0, 0x44($a1)
/* 0DB1AC 803201AC 1440000A */  bnez  $v0, .L_U_803201D8
/* 0DB1B0 803201B0 00000000 */   nop   
/* 0DB1B4 803201B4 328400FF */  andi  $a0, $s4, 0xff
/* 0DB1B8 803201B8 0C0C7BDB */  jal   func_8031E0E4
/* 0DB1BC 803201BC 324500FF */   andi  $a1, $s2, 0xff
/* 0DB1C0 803201C0 A2200018 */  sb    $zero, 0x18($s1)
/* 0DB1C4 803201C4 328400FF */  andi  $a0, $s4, 0xff
/* 0DB1C8 803201C8 0C0C7B9C */  jal   func_8031DFE8
/* 0DB1CC 803201CC 324500FF */   andi  $a1, $s2, 0xff
/* 0DB1D0 803201D0 100000B5 */  b     .L_U_803204A8
/* 0DB1D4 803201D4 26F70001 */   addiu $s7, $s7, 1
.L_U_803201D8:
/* 0DB1D8 803201D8 54800010 */  bnezl $a0, .L_U_8032021C
/* 0DB1DC 803201DC 8C580000 */   lw    $t8, ($v0)
/* 0DB1E0 803201E0 8C4C0000 */  lw    $t4, ($v0)
/* 0DB1E4 803201E4 328400FF */  andi  $a0, $s4, 0xff
/* 0DB1E8 803201E8 000C7040 */  sll   $t6, $t4, 1
/* 0DB1EC 803201EC 05C2000B */  bltzl $t6, .L_U_8032021C
/* 0DB1F0 803201F0 8C580000 */   lw    $t8, ($v0)
/* 0DB1F4 803201F4 0C0C7BDB */  jal   func_8031E0E4
/* 0DB1F8 803201F8 324500FF */   andi  $a1, $s2, 0xff
/* 0DB1FC 803201FC 8E0F02AC */  lw    $t7, 0x2ac($s0)
/* 0DB200 80320200 328400FF */  andi  $a0, $s4, 0xff
/* 0DB204 80320204 324500FF */  andi  $a1, $s2, 0xff
/* 0DB208 80320208 0C0C7B9C */  jal   func_8031DFE8
/* 0DB20C 8032020C A1E00054 */   sb    $zero, 0x54($t7)
/* 0DB210 80320210 100000A5 */  b     .L_U_803204A8
/* 0DB214 80320214 26F70001 */   addiu $s7, $s7, 1
/* 0DB218 80320218 8C580000 */  lw    $t8, ($v0)
.L_U_8032021C:
/* 0DB21C 8032021C 328400FF */  andi  $a0, $s4, 0xff
/* 0DB220 80320220 2E81000A */  sltiu $at, $s4, 0xa
/* 0DB224 80320224 0018CFC2 */  srl   $t9, $t8, 0x1f
/* 0DB228 80320228 17200009 */  bnez  $t9, .L_U_80320250
/* 0DB22C 8032022C 00000000 */   nop   
/* 0DB230 80320230 0C0C7BDB */  jal   func_8031E0E4
/* 0DB234 80320234 324500FF */   andi  $a1, $s2, 0xff
/* 0DB238 80320238 A2200018 */  sb    $zero, 0x18($s1)
/* 0DB23C 8032023C 328400FF */  andi  $a0, $s4, 0xff
/* 0DB240 80320240 0C0C7B9C */  jal   func_8031DFE8
/* 0DB244 80320244 324500FF */   andi  $a1, $s2, 0xff
/* 0DB248 80320248 10000097 */  b     .L_U_803204A8
/* 0DB24C 8032024C 26F70001 */   addiu $s7, $s7, 1
.L_U_80320250:
/* 0DB250 80320250 10200094 */  beqz  $at, .L_U_803204A4
/* 0DB254 80320254 00144880 */   sll   $t1, $s4, 2
/* 0DB258 80320258 3C018034 */  lui   $at, %hi(jtbl_803383DC)
/* 0DB25C 8032025C 00290821 */  addu  $at, $at, $t1
/* 0DB260 80320260 8C299764 */  lw    $t1, %lo(jtbl_803383DC)($at)
/* 0DB264 80320264 01200008 */  jr    $t1
/* 0DB268 80320268 00000000 */   nop   
glabel L_U_8032026C
/* 0DB26C 8032026C 00034100 */  sll   $t0, $v1, 4
/* 0DB270 80320270 05000052 */  bltz  $t0, .L_U_803203BC
/* 0DB274 80320274 3C0A8036 */   lui   $t2, %hi(D_80363808) # $t2, 0x8036
/* 0DB278 80320278 254A4B78 */  addiu $t2, %lo(D_80363808) # addiu $t2, $t2, 0x4b78
/* 0DB27C 8032027C 028A9821 */  addu  $s3, $s4, $t2
/* 0DB280 80320280 926B0000 */  lbu   $t3, ($s3)
/* 0DB284 80320284 324500FF */  andi  $a1, $s2, 0xff
/* 0DB288 80320288 328400FF */  andi  $a0, $s4, 0xff
/* 0DB28C 8032028C 29610009 */  slti  $at, $t3, 9
/* 0DB290 80320290 54200008 */  bnezl $at, .L_U_803202B4
/* 0DB294 80320294 4406A000 */   mfc1  $a2, $f20
/* 0DB298 80320298 4406A000 */  mfc1  $a2, $f20
/* 0DB29C 8032029C 0C0C7E5B */  jal   func_8031EB24
/* 0DB2A0 803202A0 328400FF */   andi  $a0, $s4, 0xff
/* 0DB2A4 803202A4 8E0C02AC */  lw    $t4, 0x2ac($s0)
/* 0DB2A8 803202A8 10000011 */  b     .L_U_803202F0
/* 0DB2AC 803202AC E5800020 */   swc1  $f0, 0x20($t4)
/* 0DB2B0 803202B0 4406A000 */  mfc1  $a2, $f20
.L_U_803202B4:
/* 0DB2B4 803202B4 0C0C7E5B */  jal   func_8031EB24
/* 0DB2B8 803202B8 324500FF */   andi  $a1, $s2, 0xff
/* 0DB2BC 803202BC 926D0000 */  lbu   $t5, ($s3)
/* 0DB2C0 803202C0 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0DB2C4 803202C4 448D9000 */  mtc1  $t5, $f18
/* 0DB2C8 803202C8 05A10004 */  bgez  $t5, .L_U_803202DC
/* 0DB2CC 803202CC 468091A0 */   cvt.s.w $f6, $f18
/* 0DB2D0 803202D0 44812000 */  mtc1  $at, $f4
/* 0DB2D4 803202D4 00000000 */  nop   
/* 0DB2D8 803202D8 46043180 */  add.s $f6, $f6, $f4
.L_U_803202DC:
/* 0DB2DC 803202DC 461C3200 */  add.s $f8, $f6, $f28
/* 0DB2E0 803202E0 8E0E02AC */  lw    $t6, 0x2ac($s0)
/* 0DB2E4 803202E4 461E4283 */  div.s $f10, $f8, $f30
/* 0DB2E8 803202E8 46005402 */  mul.s $f16, $f10, $f0
/* 0DB2EC 803202EC E5D00020 */  swc1  $f16, 0x20($t6)
.L_U_803202F0:
/* 0DB2F0 803202F0 8E2F0000 */  lw    $t7, ($s1)
/* 0DB2F4 803202F4 8E380008 */  lw    $t8, 8($s1)
/* 0DB2F8 803202F8 C5EC0000 */  lwc1  $f12, ($t7)
/* 0DB2FC 803202FC 0C0C7E04 */  jal   func_8031E97C
/* 0DB300 80320300 C70E0000 */   lwc1  $f14, ($t8)
/* 0DB304 80320304 8E1902AC */  lw    $t9, 0x2ac($s0)
/* 0DB308 80320308 3C0100FF */  lui   $at, 0xff
/* 0DB30C 8032030C 324500FF */  andi  $a1, $s2, 0xff
/* 0DB310 80320310 E7200024 */  swc1  $f0, 0x24($t9)
/* 0DB314 80320314 8E290014 */  lw    $t1, 0x14($s1)
/* 0DB318 80320318 328400FF */  andi  $a0, $s4, 0xff
/* 0DB31C 8032031C 01214024 */  and   $t0, $t1, $at
/* 0DB320 80320320 3C010017 */  lui   $at, 0x17
/* 0DB324 80320324 15010010 */  bne   $t0, $at, .L_U_80320368
/* 0DB328 80320328 00000000 */   nop   
/* 0DB32C 8032032C 0C0C7EC8 */  jal   func_8031EC7C
/* 0DB330 80320330 328400FF */   andi  $a0, $s4, 0xff
/* 0DB334 80320334 926A0000 */  lbu   $t2, ($s3)
/* 0DB338 80320338 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0DB33C 8032033C 448A9000 */  mtc1  $t2, $f18
/* 0DB340 80320340 05410004 */  bgez  $t2, .L_U_80320354
/* 0DB344 80320344 46809120 */   cvt.s.w $f4, $f18
/* 0DB348 80320348 44813000 */  mtc1  $at, $f6
/* 0DB34C 8032034C 00000000 */  nop   
/* 0DB350 80320350 46062100 */  add.s $f4, $f4, $f6
.L_U_80320354:
/* 0DB354 80320354 46182203 */  div.s $f8, $f4, $f24
/* 0DB358 80320358 8E0B02AC */  lw    $t3, 0x2ac($s0)
/* 0DB35C 8032035C 46004280 */  add.s $f10, $f8, $f0
/* 0DB360 80320360 1000000F */  b     .L_U_803203A0
/* 0DB364 80320364 E56A002C */   swc1  $f10, 0x2c($t3)
.L_U_80320368:
/* 0DB368 80320368 0C0C7EC8 */  jal   func_8031EC7C
/* 0DB36C 8032036C 324500FF */   andi  $a1, $s2, 0xff
/* 0DB370 80320370 926C0000 */  lbu   $t4, ($s3)
/* 0DB374 80320374 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0DB378 80320378 448C8000 */  mtc1  $t4, $f16
/* 0DB37C 8032037C 05810004 */  bgez  $t4, .L_U_80320390
/* 0DB380 80320380 468084A0 */   cvt.s.w $f18, $f16
/* 0DB384 80320384 44813000 */  mtc1  $at, $f6
/* 0DB388 80320388 00000000 */  nop   
/* 0DB38C 8032038C 46069480 */  add.s $f18, $f18, $f6
.L_U_80320390:
/* 0DB390 80320390 461A9103 */  div.s $f4, $f18, $f26
/* 0DB394 80320394 8E0D02AC */  lw    $t5, 0x2ac($s0)
/* 0DB398 80320398 46002200 */  add.s $f8, $f4, $f0
/* 0DB39C 8032039C E5A8002C */  swc1  $f8, 0x2c($t5)
.L_U_803203A0:
/* 0DB3A0 803203A0 328400FF */  andi  $a0, $s4, 0xff
/* 0DB3A4 803203A4 324500FF */  andi  $a1, $s2, 0xff
/* 0DB3A8 803203A8 0C0C7EFA */  jal   func_8031ED70
/* 0DB3AC 803203AC 32C600FF */   andi  $a2, $s6, 0xff
/* 0DB3B0 803203B0 8E0E02AC */  lw    $t6, 0x2ac($s0)
/* 0DB3B4 803203B4 1000003B */  b     .L_U_803204A4
/* 0DB3B8 803203B8 A1C20003 */   sb    $v0, 3($t6)
glabel L_U_803203BC
.L_U_803203BC:
/* 0DB3BC 803203BC E4B60020 */  swc1  $f22, 0x20($a1)
/* 0DB3C0 803203C0 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0DB3C4 803203C4 44815000 */  mtc1  $at, $f10
/* 0DB3C8 803203C8 8E0F02AC */  lw    $t7, 0x2ac($s0)
/* 0DB3CC 803203CC E5EA0024 */  swc1  $f10, 0x24($t7)
/* 0DB3D0 803203D0 8E1802AC */  lw    $t8, 0x2ac($s0)
/* 0DB3D4 803203D4 10000033 */  b     .L_U_803204A4
/* 0DB3D8 803203D8 E716002C */   swc1  $f22, 0x2c($t8)
glabel L_U_803203DC
/* 0DB3DC 803203DC 4406A000 */  mfc1  $a2, $f20
/* 0DB3E0 803203E0 328400FF */  andi  $a0, $s4, 0xff
/* 0DB3E4 803203E4 0C0C7E5B */  jal   func_8031EB24
/* 0DB3E8 803203E8 324500FF */   andi  $a1, $s2, 0xff
/* 0DB3EC 803203EC 8E1902AC */  lw    $t9, 0x2ac($s0)
/* 0DB3F0 803203F0 E7200020 */  swc1  $f0, 0x20($t9)
/* 0DB3F4 803203F4 8E280008 */  lw    $t0, 8($s1)
/* 0DB3F8 803203F8 8E290000 */  lw    $t1, ($s1)
/* 0DB3FC 803203FC C50E0000 */  lwc1  $f14, ($t0)
/* 0DB400 80320400 0C0C7E04 */  jal   func_8031E97C
/* 0DB404 80320404 C52C0000 */   lwc1  $f12, ($t1)
/* 0DB408 80320408 8E0A02AC */  lw    $t2, 0x2ac($s0)
/* 0DB40C 8032040C 328400FF */  andi  $a0, $s4, 0xff
/* 0DB410 80320410 324500FF */  andi  $a1, $s2, 0xff
/* 0DB414 80320414 0C0C7EC8 */  jal   func_8031EC7C
/* 0DB418 80320418 E5400024 */   swc1  $f0, 0x24($t2)
/* 0DB41C 8032041C 8E0B02AC */  lw    $t3, 0x2ac($s0)
/* 0DB420 80320420 328400FF */  andi  $a0, $s4, 0xff
/* 0DB424 80320424 324500FF */  andi  $a1, $s2, 0xff
/* 0DB428 80320428 32C600FF */  andi  $a2, $s6, 0xff
/* 0DB42C 8032042C 0C0C7EFA */  jal   func_8031ED70
/* 0DB430 80320430 E560002C */   swc1  $f0, 0x2c($t3)
/* 0DB434 80320434 8E0C02AC */  lw    $t4, 0x2ac($s0)
/* 0DB438 80320438 1000001A */  b     .L_U_803204A4
/* 0DB43C 8032043C A1820003 */   sb    $v0, 3($t4)
glabel L_U_80320440
/* 0DB440 80320440 328400FF */  andi  $a0, $s4, 0xff
/* 0DB444 80320444 324500FF */  andi  $a1, $s2, 0xff
/* 0DB448 80320448 0C0C7EFA */  jal   func_8031ED70
/* 0DB44C 8032044C 32C600FF */   andi  $a2, $s6, 0xff
/* 0DB450 80320450 8E0D02AC */  lw    $t5, 0x2ac($s0)
/* 0DB454 80320454 3C063F4C */  lui   $a2, (0x3F4CCCCD >> 16) # lui $a2, 0x3f4c
/* 0DB458 80320458 34C6CCCD */  ori   $a2, (0x3F4CCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
/* 0DB45C 8032045C 328400FF */  andi  $a0, $s4, 0xff
/* 0DB460 80320460 324500FF */  andi  $a1, $s2, 0xff
/* 0DB464 80320464 0C0C7E5B */  jal   func_8031EB24
/* 0DB468 80320468 A1A20003 */   sb    $v0, 3($t5)
/* 0DB46C 8032046C 8E0E02AC */  lw    $t6, 0x2ac($s0)
/* 0DB470 80320470 E5C00020 */  swc1  $f0, 0x20($t6)
/* 0DB474 80320474 8E380008 */  lw    $t8, 8($s1)
/* 0DB478 80320478 8E2F0000 */  lw    $t7, ($s1)
/* 0DB47C 8032047C C70E0000 */  lwc1  $f14, ($t8)
/* 0DB480 80320480 0C0C7E04 */  jal   func_8031E97C
/* 0DB484 80320484 C5EC0000 */   lwc1  $f12, ($t7)
/* 0DB488 80320488 8E1902AC */  lw    $t9, 0x2ac($s0)
/* 0DB48C 8032048C 328400FF */  andi  $a0, $s4, 0xff
/* 0DB490 80320490 324500FF */  andi  $a1, $s2, 0xff
/* 0DB494 80320494 0C0C7EC8 */  jal   func_8031EC7C
/* 0DB498 80320498 E7200024 */   swc1  $f0, 0x24($t9)
/* 0DB49C 8032049C 8E0902AC */  lw    $t1, 0x2ac($s0)
/* 0DB4A0 803204A0 E520002C */  swc1  $f0, 0x2c($t1)
.L_U_803204A4:
/* 0DB4A4 803204A4 26F70001 */  addiu $s7, $s7, 1
.L_U_803204A8:
/* 0DB4A8 803204A8 26D60001 */  addiu $s6, $s6, 1
/* 0DB4AC 803204AC 32EA00FF */  andi  $t2, $s7, 0xff
/* 0DB4B0 803204B0 32C800FF */  andi  $t0, $s6, 0xff
/* 0DB4B4 803204B4 0140B825 */  move  $s7, $t2
/* 0DB4B8 803204B8 1940FE6B */  blez  $t2, .L_U_8031FE68
/* 0DB4BC 803204BC 0100B025 */   move  $s6, $t0
/* 0DB4C0 803204C0 3C0B8033 */  lui   $t3, %hi(D_803320C8)
/* 0DB4C4 803204C4 01745821 */  addu  $t3, $t3, $s4
/* 0DB4C8 803204C8 3C0D8036 */  lui   $t5, %hi(D_80360C28)
/* 0DB4CC 803204CC 916B31D8 */  lbu   $t3, %lo(D_803320C8)($t3)
/* 0DB4D0 803204D0 01B46821 */  addu  $t5, $t5, $s4
/* 0DB4D4 803204D4 91AD1F98 */  lbu   $t5, %lo(D_80360C28)($t5)
/* 0DB4D8 803204D8 26940001 */  addiu $s4, $s4, 1
/* 0DB4DC 803204DC 010B6021 */  addu  $t4, $t0, $t3
/* 0DB4E0 803204E0 328F00FF */  andi  $t7, $s4, 0xff
/* 0DB4E4 803204E4 018DB023 */  subu  $s6, $t4, $t5
/* 0DB4E8 803204E8 29E1000A */  slti  $at, $t7, 0xa
/* 0DB4EC 803204EC 32CE00FF */  andi  $t6, $s6, 0xff
/* 0DB4F0 803204F0 01E0A025 */  move  $s4, $t7
/* 0DB4F4 803204F4 1420FE55 */  bnez  $at, .L_U_8031FE4C
/* 0DB4F8 803204F8 01C0B025 */   move  $s6, $t6
.L_U_803204FC:
/* 0DB4FC 803204FC 8FBF006C */  lw    $ra, 0x6c($sp)
/* 0DB500 80320500 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0DB504 80320504 D7B60020 */  ldc1  $f22, 0x20($sp)
/* 0DB508 80320508 D7B80028 */  ldc1  $f24, 0x28($sp)
/* 0DB50C 8032050C D7BA0030 */  ldc1  $f26, 0x30($sp)
/* 0DB510 80320510 D7BC0038 */  ldc1  $f28, 0x38($sp)
/* 0DB514 80320514 D7BE0040 */  ldc1  $f30, 0x40($sp)
/* 0DB518 80320518 8FB00048 */  lw    $s0, 0x48($sp)
/* 0DB51C 8032051C 8FB1004C */  lw    $s1, 0x4c($sp)
/* 0DB520 80320520 8FB20050 */  lw    $s2, 0x50($sp)
/* 0DB524 80320524 8FB30054 */  lw    $s3, 0x54($sp)
/* 0DB528 80320528 8FB40058 */  lw    $s4, 0x58($sp)
/* 0DB52C 8032052C 8FB5005C */  lw    $s5, 0x5c($sp)
/* 0DB530 80320530 8FB60060 */  lw    $s6, 0x60($sp)
/* 0DB534 80320534 8FB70064 */  lw    $s7, 0x64($sp)
/* 0DB538 80320538 8FBE0068 */  lw    $fp, 0x68($sp)
/* 0DB53C 8032053C 03E00008 */  jr    $ra
/* 0DB540 80320540 27BD0080 */   addiu $sp, $sp, 0x80
)
#endif

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
    u8 val = (D_80332108 & 0xf) + (arg0 << 4);
    D_80332108 = val;
    D_80226D7F = arg0;
}

void Unknown80321460(UNUSED s32 arg0, UNUSED s32 arg1, UNUSED s32 arg2, UNUSED s32 arg3)
{
}

void Unknown80321474(UNUSED s32 arg0)
{
}
