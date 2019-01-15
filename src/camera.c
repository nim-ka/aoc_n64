#include <ultra64.h>

#include "sm64.h"
#include "audio/interface_2.h"
#include "castle_message_behaviors.h"
#include "game.h"
#include "hud_print.h"
#include "math_util.h"
#include "area.h"
#include "surface_collision.h"
#include "behavior_script.h"
#include "level_update.h"
#include "ingame_menu.h"
#include "mario_actions_cutscene.h"
#include "camera.h"
#include "save_file.h"
#include "room.h"

#define CBUTTON_MASK (U_CBUTTONS | D_CBUTTONS | L_CBUTTONS | R_CBUTTONS)

struct Struct8033B250
{
    s16 unk0;
    s16 unk2;
    f32 unk4;
    s16 unk8;
    s16 unkA;
    f32 unkC;
    s32 unk10;
    Vec3f unk14;
};

extern float D_8033B438;
extern float D_8033B3CC;
extern float D_8033B3D4;
extern s16 D_8033B41C;
extern s16 D_8033B41E;
extern u8 D_8033B364;
extern s16 D_8033B3A2;
extern u32 D_8033B3E0;
extern struct Struct8033B250 D_8033B250;
extern u8 D_8033B365;
extern float D_80336074;
extern s16 D_8033B308;
extern s16 D_8033B3DC;
extern s16 D_8033B3A4;
extern s16 D_8033B3A6;
extern u8 D_8032CFFC;
extern u8 D_8032CFF8;
extern u8 D_8032CFF4;
extern struct Struct8032D000 *D_8032D004;  // unknown type
extern u32 D_8033B23C;
extern s16 D_8033B6EC;
extern s16 D_8033B6EA;
extern u32 D_8033B85C;
extern struct Object *D_8032CFC4;
extern u32 D_8032CFC8;
extern u32 D_8032CFCC;
extern s16 D_8033B316;
extern s16 D_8033B31A;
extern float D_8033B3FC;
extern float D_8033B234;
extern float D_8033B238;
extern float D_8033B240;
extern s16 D_8033B244;
extern u8 D_8032CFF0;
extern u32 D_8033B30C;
extern u32 D_8033B310;
extern s16 D_8033B224;
extern s16 D_8033B226;
extern u32 D_8032CFDC;
extern u8 D_8033B228;
extern float D_8033B6E4;
extern s16 D_8033B6E8;
extern float D_8033B300;
extern float D_8033B2FC;
extern s16 D_8033B3E4;
extern s16 D_8033B6E0;
extern s16 D_8033B2F8;
extern s16 D_8033B304;
extern s16 D_8033B306;
extern u8 D_8032E910[];
extern s8 D_8033B4E0[][8];
extern s8 D_8033B5E0[][8];

struct Struct8033B2B8
{
    s8 unk0;
    u8 filler1[7];
    Vec3s unk8;
    u8 fillerE[2];
};

extern struct Struct8033B2B8 D_8033B2B8[];
extern Vec3f D_8033B1F8;
extern Vec3f D_8033B208;
extern float D_8033B3D8;
extern float D_8033B3D0;
extern Vec3f D_8033B218;

extern float D_803361D0;
extern float D_803361D4;
extern float D_803361D8;
extern float D_803361DC;
extern float D_803361E0;
extern float D_803361E4;
extern float D_803361E8;
extern float D_803361EC;
extern float D_803361F0;
extern float D_803361F4;
extern float D_803361F8;
extern float D_803361FC;
extern float D_80336200;
extern float D_80336204;
extern float D_80336208;
extern float D_8033620C;
extern float D_80336210;
extern float D_80336214;
extern float D_80336218;
extern float D_8033621C;
extern float D_80336220;
extern float D_80336224;
extern float D_80336228;
extern s16 D_8033B320;
extern struct Struct8033B470 D_8032D0F0;
extern struct Struct8033B4B8 D_8033B4B8;
extern float D_8033B4D0;
extern float D_8033B4D4;

extern struct Struct8032CA78 *TableLevelCinematicCamera[];

void func_8027EFE0(s16 a)
{
    switch (a)
    {
    case 1:
        D_8033B3CC = 0;
        D_8033B3D4 = 0;
        break;
    case 9:
        func_8028A908(96, 3, -32768);
        func_8028AA24(96, 3, -32768);
        break;
    case 2:
        func_8028A908(96, 12, -32768);
        break;
    case 3:
        if (D_8032D000->unk0 & 0x6000)
        {
            func_8028A964(512, 16, 4096);
            func_8028AA24(1024, 32, 4096);
            func_80299C98(256, 48, -32768);
        }
        else
        {
            func_8028A964(128, 8, 16384);
            func_8028AA24(128, 8, 16384);
            func_80299C98(256, 48, -32768);
        }
        D_8033B3CC = 0;
        D_8033B3D4 = 0;
        break;
    case 4:
        if (D_8032D000->unk0 & 0x6000)
        {
            func_8028A964(1024, 32, 4096);
            func_8028AA24(1536, 48, 4096);
            func_80299C98(384, 64, -32768);
        }
        else
        {
            func_8028A964(256, 16, 16384);
            func_8028AA24(256, 16, 16384);
            func_80299C98(384, 64, -32768);
        }
        D_8033B3CC = 0;
        D_8033B3D4 = 0;
        break;
    case 5:
        if (D_8032D000->unk0 & 0x6000)
        {
            func_8028A964(1536, 48, 4096);
            func_8028AA24(2048, 64, 4096);
            func_80299C98(512, 80, -32768);
        }
        else
        {
            func_8028A964(384, 32, 16384);
            func_8028AA24(512, 32, 16384);
            func_80299C98(512, 80, -32768);
        }
        D_8033B3CC = 0;
        D_8033B3D4 = 0;
        break;
    case 8:
        D_8033B3CC = 0.07;
        D_8033B3D4 = 0.07;
        break;
    case 10:
        func_8028A908(RandomFloat() * 64.f, 8, -32768);
        func_8028A964(RandomFloat() * 64.f, 8, -32768);
        break;
    }
}

void func_8027F308(s16 a)
{
    switch (a)
    {
    case 1:
        func_8028A908(96, 8, 16384);
        break;
    case 2:
        func_8028A908(192, 8, 16384);
        break;
    case 3:
        func_8028A908(256, 8, 12288);
        break;
    case 6:
        func_8028AA24(128, 16, 12288);
        break;
    case 7:
        func_8028A908(32, 8, -32768);
        break;
    case 8:
        func_8028A908(64, 8, -32768);
        break;
    case 9:
        func_8028A908(32, 8, -32768);
        func_8028AA24(1024, 16, 256);
        break;
    case 10:
        func_8028A908(64, 2, -32768);
        break;
    case 5:
        func_8028A964(-512, 128, 512);
        break;
    }
}

void func_8027F440(s16 a, float b, float c, float d)
{
    switch (a)
    {
    case 4:
        func_8028AA80(40, 8, 16384, 2000.f, b, c, d);
        break;
    case 1:
        func_8028AA80(128, 8, 16384, 4000.f, b, c, d);
        func_8029A514(1, b, c, d);
        break;
    case 2:
        func_8028AA80(192, 8, 16384, 6000.f, b, c, d);
        func_8029A514(3, b, c, d);
        break;
    case 3:
        func_8028AA80(256, 8, 12288, 8000.f, b, c, d);
        func_8029A514(4, b, c, d);
        break;
    }
}

static void unused_8027F5C4(s16 a)
{
    switch (a)
    {
    case 1:
        func_8028A908(96, 8, 16384);
        break;
    case 2:
        func_8028A908(192, 8, 16384);
        break;
    case 3:
        func_8028A908(256, 8, 12288);
        break;
    }
}

static void func_8027F668(float *a, float b, float c, float *d, float e, float f)
{
    float sp24 = D_8033B278.unk4;
    float sp20;
    UNUSED int filler;

    if (!(D_8032D000->unk0 & 0x4000))
    {
        if (sp24 < (sp20 = find_water_level(D_8032D000->unk4[0], D_8032D000->unk4[2])))
            sp24 = sp20;
    }

    if (D_8032D000->unk0 & 0x100000)
    {
        if (D_8033B278.unk4 >= gMarioStates[0].usedObj->oPosY
         && D_8032D000->unk4[1] < 0.7f * gMarioStates[0].usedObj->hitboxHeight + gMarioStates[0].usedObj->oPosY)
            c = 1200;
    }

    *a = (sp24 - D_8032D000->unk4[1]) * b;
    if (*a > c)
        *a = c;
    if (*a < -c)
        *a = -c;

    *d = (sp24 - D_8032D000->unk4[1]) * e;
    if (*d > f)
        *d = f;
    if (*d < -f)
        *d = -f;
}

static void func_8027F870(Vec3f a, Vec3f b, float c, float d, float e, s16 f, s16 g)
{
    Vec3f sp24;

    sp24[0] = D_8032D000->unk4[0];
    sp24[1] = D_8032D000->unk4[1] + c;
    sp24[2] = D_8032D000->unk4[2];

    vec3f_set_dist_and_angle(sp24, b, e, f + D_8033B3F0, g);

    a[0] = D_8032D000->unk4[0];
    a[1] = D_8032D000->unk4[1] + d;
    a[2] = D_8032D000->unk4[2];
}

static void unused_8027F950(Vec3f a, Vec3f b, float c, float d, float e, s16 f, s16 g)
{
    Vec3f sp34;
    float sp30;
    float sp2C;
    s16 sp2A;
    s16 sp28;
    s16 sp26;
    s16 sp24;

    vec3f_copy(sp34, D_8032D000->unk4);
    sp34[1] += c;

    vec3f_set_dist_and_angle(sp34, b, e, f + D_8033B3F0, g);
    vec3f_get_dist_and_angle(b, D_8032D000->unk4, &sp30, &sp2A, &sp28);
    vec3f_get_dist_and_angle(b, a, &sp2C, &sp26, &sp24);
    vec3f_set_dist_and_angle(b, a, sp2C, sp26, sp24);

    a[1] = D_8032D000->unk4[1] + d;
}

#define ABS(x) ((x) > 0.f ? (x) : -(x))
#define ABS2(x) ((x) >= 0.f ? (x) : -(x))

static void func_8027FA48(struct Struct80280550 *a, float b)
{
    struct Surface *sp44;
    float sp40;
    float sp3C;
    float sp38;
    UNUSED u8 filler[8];
    UNUSED s16 sp2E = D_8032D000->unk0;
    float sp28 = 125.f;
    float sp24 = find_ceil(a->unk10[0], D_8033B328.unk0[3][1] - 50.f, a->unk10[2], &sp44);

    if (D_8032D000->unk0 & 0x200000)
    {
        sp3C = D_8033B278.unk14;
        sp40 = D_8033B278.unk4;
        if (sp40 < sp3C - 400.f)
            sp40 = sp3C - 400.f;
        b = sp40 + (sp3C - sp40) * 0.4f;
        if (D_8032D000->unk4[1] - 400.f > b)
            b = D_8032D000->unk4[1] - 400.f;
        func_8028C2F0(a, b, 5.f);
    }
    else
    {
        sp38 = find_floor(a->unk10[0], a->unk10[1] + 100.f, a->unk10[2], &sp44) + sp28;
        sp40 = sp28 + D_8033B278.unk4;
        if (sp38 < sp40)
            sp38 = sp40;
        if (b < sp38)
        {
            b = sp38;
            a->unk10[1] = b;
        }
        if (D_8032D000->unk0 == 0x2033B || D_8032D000->unk0 == 0x2033A || D_8032D000->unk0 == 0x2033C)
        {
            if (ABS(a->unk10[1] - b) > 1000.f)
                a->unk10[1] = b;
        }
        func_8028C2F0(a, b, 20.f);
        if (sp24 != 20000.f)
        {
            sp24 -= sp28;
            if ((a->unk10[1] > sp24 && D_8033B278.unk4 + sp28 < sp24)
              || (D_8033B278.unk14 != 20000.f && D_8033B278.unk14 > sp24 && a->unk10[1] > sp24))
                a->unk10[1] = sp24;
        }
    }
}

static int func_8027FDB8(u16 a)
{
    struct Surface *sp44;
    float sp40;
    s16 sp3E = 1456;
    float sp38 = D_8032D000->unk4[0] + gSineTable[(u16)(a) >> 4] * 40.f;
    float sp34 = D_8032D000->unk4[2] + gCosineTable[(u16)(a) >> 4] * 40.f;

    sp40 = find_floor(sp38, D_8032D000->unk4[1], sp34, &sp44) - D_8032D000->unk4[1];

    if (sp44 != NULL)
    {
        if (sp44->type != 40 && sp40 > 0.f)
        {
            if (sp44->normal[2] == 0.f && sp40 < 100.f)
                sp3E = 1456;
            else
                sp3E += atan2s(40.f, sp40);
        }
    }
    return sp3E;
}

static void func_8027FF44(struct Struct80280550 *a)
{
    float sp34;
    s16 sp32;
    s16 sp30;
    Vec3f sp24 = {0, 0, 0};

    vec3f_get_dist_and_angle(a->unk10, D_8032D000->unk4, &sp34, &sp32, &sp30);

    sp24[2] = gSineTable[0xC0] * sp34;

    func_8028A764(sp24, sp24, D_8032D000->unk10[1]);
    sp30 = -sp30;
    func_8028A764(sp24, sp24, sp30);
    sp24[2] = 0.f;

    if (D_8032D000->unk0 == 0x03000888
     || (D_8032D000->unk0 != 0x100345 && (D_8032D000->unk0 & 0x100000)))
        sp24[0] = -sp24[0];
    if (D_8033B4DA & 0x40)
        func_80288E0C(&D_8033B40C, 0, 0.025f);
    else
        func_80288E0C(&D_8033B40C, sp24[0], 0.025f);
    sp24[0] = D_8033B40C;
    sp30 = -sp30;
    func_8028A764(sp24, sp24, sp30);
    vec3f_add(a->unk4, sp24);
}

static int func_802800F4(Vec3f a, Vec3f b, s16 c)
{
    switch (D_8032CFD8)
    {
    case 177:
        c = func_802899A0(a, b, 4508.f, -3739.f, 4508.f, -3739.f);
        break;
    case 145:
        c = func_802899A0(a, b, 8000.f, -8000.f, 7050.f, -8000.f);
        break;
    case 209:
        c = func_802899A0(a, b, 8192.f, -8192.f, 8192.f, -8192.f);
        break;
    case 210:
        c = func_802899A0(a, b, 2458.f, -2458.f, 2458.f, -2458.f);
        break;
    }
    return c;
}

int CameraChange01(struct Struct80280550 *a, Vec3f b, Vec3f c)
{
    float sp4C = D_8032D000->unk4[0] - a->unk28;
    float sp48 = D_8032D000->unk4[2] - a->unk2C;
    s16 sp46 = atan2s(sp48, sp4C) + D_8033B402;
    s16 sp44 = func_8027FDB8(sp46);
    UNUSED int unused1;
    float sp3C;
    float sp38;
    UNUSED int unused2;
    UNUSED int unused3;
    float sp2C = 125.f;
    float sp28 = 1000.f;

    D_8033B3EA = sp46 - D_8033B402;
    func_8027F668(&sp3C, 1.f, 200.f, &sp38, 0.9f, 200.f);
    func_8027F870(b, c, sp3C + sp2C, sp38 + sp2C, D_8033B3EE + sp28, sp44, sp46);
    sp46 = func_802800F4(c, b, sp46);

    return sp46;
}

int CameraChange0E(struct Struct80280550 *a, Vec3f b, Vec3f c)
{
    UNUSED float sp4C = D_8032D000->unk4[0] - a->unk28;
    UNUSED float sp48 = D_8032D000->unk4[2] - a->unk2C;
    s16 sp46 = D_8033B406 + D_8033B408;
    s16 sp44 = func_8027FDB8(sp46);
    float sp40;
    float sp3C;
    UNUSED int unused1;
    UNUSED int unused2;
    UNUSED int unused3;
    float sp2C = 125.f;
    float sp28 = 1000.f;

    D_8033B3EA = sp46;
    func_8027F668(&sp40, 1.f, 200.f, &sp3C, 0.9f, 200.f);
    func_8027F870(b, c, sp40 + sp2C, sp3C + sp2C, D_8033B3EE + sp28, sp44, sp46);
    func_8027FF44(a);
    if (D_8032CFD8 == 370)
        sp46 = func_802899A0(c, b, 6839.f, 995.f, 5994.f, -3945.f);

    return sp46;
}

static void func_80280550(struct Struct80280550 *a)
{
    s16 sp46 = 10922;
    s16 sp44 = -10922;
    s16 sp42 = 4096;
    s16 sp40;
    int sp3C;
    UNUSED s16 sp3A = 0;
    UNUSED int sp34 = 0;
    float sp30 = D_8032D000->unk4[0] - a->unk28;
    float sp2C = D_8032D000->unk4[2] - a->unk2C;
    UNUSED int filler;
    s16 sp26 = func_8028A4F0(D_8032D000->unk4, a->unk10) - atan2s(sp2C, sp30);

    if (sp26 > sp46)
        sp26 = sp46;
    if (sp26 < sp44)
        sp26 = sp44;

    if (!(D_8033B4D8 & 0xD))
    {
        if (D_8033B278.unk8 == 110 && D_8033B278.unk20 != 110)
            D_8033B4D8 |= 0x11;
        if (D_8033B278.unk8 == 111 && D_8033B278.unk20 != 111)
            D_8033B4D8 |= 0x14;
        if (D_8033B278.unk8 == 112 && D_8033B278.unk20 != 112)
            D_8033B4D8 |= 0x18;
    }

    if (D_8033B4D8 & 0x10)
        sp42 = 512;

    if (a->unk0 == 2)
    {
        sp30 = -sp30;
        sp2C = -sp2C;
    }

    sp3C = func_8028F2F0(a, a->unk10, &sp40, 1024);
    if (sp3C == 3)
    {
        if (sp40 - atan2s(sp2C, sp30) + 0x4000 < 0)
            sp40 += 32768;
        sp40 -= atan2s(sp2C, sp30);
        if (sp40 >= 0x4AAB)
            sp40 = 19114;
        if (sp40 <= -0x4AAB)
            sp40 = -19114;
    }

    if (D_8033B4D8 & 1)
    {
        if (func_80289184(&D_8033B402, 0, sp42) == 0)
            D_8033B4D8 &= ~1;
    }
    else
    {
        if ((D_8033B4D8 & 4) && sp3C == 3 && sp40 + 16 < D_8033B402)
        {
            D_8033B402 = sp40;
            D_8033B4D8 &= ~0x14;
        }
        if ((D_8033B4D8 & 8) && sp3C == 3 && sp40 - 16 > D_8033B402)
        {
            D_8033B402 = sp40;
            D_8033B4D8 &= ~0x18;
        }
        if (!(D_8033B318 & 4) && (D_8033B4D8 & 4) && func_80289184(&D_8033B402, sp46, sp42) == 0)
            D_8033B4D8 &= ~0x14;
        if (!(D_8033B318 & 8) && (D_8033B4D8 & 8) && func_80289184(&D_8033B402, sp44, sp42) == 0)
            D_8033B4D8 &= ~0x18;
        if ((D_8033B318 & 4) && (D_8033B4D8 & 4) && func_80289184(&D_8033B402, 19114, sp42) == 0)
        {
            D_8033B4D8 &= ~0x14;
            D_8033B318 &= ~4;
        }
        if ((D_8033B318 & 8) && (D_8033B4D8 & 8) && func_80289184(&D_8033B402, -19114, sp42) == 0)
        {
            D_8033B4D8 &= ~0x18;
            D_8033B318 &= ~8;
        }
    }
    if (!(D_8033B4D8 & 0xD))
    {
        if (sp3C == 3)
        {
            func_80288ECC(&D_8033B402, sp40, 10);
        }
        else
        {
            if (a->unk0 == 1)
            {
                sp42 = gMarioStates[0].forwardVel / 32.f * 128.f;
                func_80289184(&D_8033B402, sp26, sp42);
            }
            if (a->unk0 == 2)
                D_8033B402 = func_8028AF24(a, atan2s(sp2C, sp30));
        }
    }

    if (D_8033B402 >= 0x5555)
        D_8033B402 = 21844;
    if (D_8033B402 < -0x5554)
        D_8033B402 = -21844;
}

static void func_80280BD8(float a, s16 b)
{
    if (D_8033B3EE < 0)
    {
        if ((D_8033B3EE += 30) > 0)
            D_8033B3EE = 0;
    }
    else if (a < D_8033B3EE)
    {
        if ((D_8033B3EE -= 30) < a)
            D_8033B3EE = a;
    }
    else if (D_8033B4D8 & 2)
    {
        if ((D_8033B3EE += 30) > a)
            D_8033B3EE = a;
    }
    else
    {
        if ((D_8033B3EE -= 30) < 0)
            D_8033B3EE = 0;
    }

    if (D_8032CFD8 == 130 && D_8033B860->unk0 == 2)
        b /= 2;

    if (D_8033B4D8 & 2)
    {
        if ((D_8033B3F0 += b / 13) > b)
            D_8033B3F0 = b;
    }
    else
    {
        if ((D_8033B3F0 -= b / 13) < 0)
            D_8033B3F0 = 0;
    }
}

static void func_80280E0C(struct Struct80280550 *a)
{
    func_8028B3DC(a, 0.f);
}

static void func_80280E3C(UNUSED struct Struct80280550 *a)
{
    float sp4 = 1000.f;

    D_8033B402 = D_8033B43E - D_8033B3EA;
    D_8033B3EE = D_8033B438 - sp4;
    D_8033B4D8 &= ~0x100;
}

static void func_80280EBC(struct Struct80280550 *a)
{
    Vec3f sp2C;
    UNUSED u8 unused1[8];
    s16 sp22 = D_8033B3EA;
    UNUSED u8 unused2[4];

    if (D_8033B4D8 & 0x100)
        func_80280E3C(a);
    func_80280E0C(a);
    func_80280550(a);
    if (a->unk0 == 1)
        func_80280BD8(400.f, 2304);
    a->unk3A = CameraChange01(a, a->unk4, sp2C);
    a->unk10[0] = sp2C[0];
    a->unk10[2] = sp2C[2];
    D_8033B3EC = D_8033B3EA - sp22;
    if (D_8032D000->unk0 == 1192)
        sp2C[1] += 500.f;
    func_8027FA48(a, sp2C[1]);
    func_8027FF44(a);
}

static void func_80280FD8(struct Struct80280550 *a)
{
    Vec3f sp24;
    UNUSED u8 unused[8];
    s16 sp1A = D_8033B3EA;

    func_8028B3DC(a, 0.f);

    if (gPlayer1Controller->buttonPressed & R_CBUTTONS)
    {
        D_8033B408 += 0x2000;
        func_8028B2D0();
    }
    if (gPlayer1Controller->buttonPressed & L_CBUTTONS)
    {
        D_8033B408 -= 0x2000;
        func_8028B2D0();
    }

    func_80280BD8(400.f, 2304);
    a->unk3A = CameraChange0E(a, a->unk4, sp24);
    a->unk10[0] = sp24[0];
    a->unk10[2] = sp24[2];
    D_8033B3EC = D_8033B3EA - sp1A;
    func_8027FA48(a, sp24[1]);
}

int CameraChange02(struct Struct80280550 *a, Vec3f b, Vec3f c)
{
    float sp44 = D_8032D000->unk4[0] - a->unk28;
    float sp40 = D_8032D000->unk4[2] - a->unk2C;
    s16 sp3E = atan2s(sp40, sp44) + D_8033B402 + 32768;
    s16 sp3C = func_8027FDB8(sp3E);
    float sp38 = 1000.f;
    float sp34 = 125.f;
    float sp30;
    float sp2C;

    D_8033B3EA = sp3E - D_8033B402 - 32768;
    func_8027F668(&sp30, 1.f, 200.f, &sp2C, 0.9f, 200.f);
    func_8027F870(b, c, sp30 + sp34, sp2C + sp34, D_8033B3EE + sp38, sp3C, sp3E);

    return sp3E;
}

static void func_8028124C(struct Struct80280550 *a)
{
    Vec3f sp1C;
    s16 sp1A = D_8033B3EA;

    if (D_8033B4D8 & 0x100)
        func_80280E3C(a);
    func_80280E0C(a);
    func_80280550(a);
    func_80280BD8(400.f, 2304);
    a->unk3A = CameraChange02(a, a->unk4, sp1C);
    a->unk10[0] = sp1C[0];
    a->unk10[2] = sp1C[2];
    D_8033B3EC = D_8033B3EA - sp1A;
    if (D_8032D000->unk0 == 1192)
        sp1C[1] += 500.f;
    func_8027FA48(a, sp1C[1]);
    func_8027FF44(a);
}

int CameraChange0C(struct Struct80280550 *a, Vec3f b, Vec3f c)
{
    Vec3f spE8[2];
    Vec3f spDC;
    Vec3f spD0;
    Vec3f spC4;
    Vec3f spB8;
    s16 spB6;
    s16 spB4;
    UNUSED u8 filler[4];
    float spAC;
    float spA8;
    float spA4;
    UNUSED u8 filler2[8];
    float sp98;
    UNUSED u8 filler3[8];
    UNUSED float sp8C = 0.5f;
    float sp88 = 0.5f;
    float sp84;
    Vec3f sp78;
    UNUSED u8 filler4[12];
    UNUSED Vec3f sp60;
    Vec3s sp58;
    Vec3f sp4C;
    Vec3f sp40;
    Vec3f sp34;
    float sp30;
    float sp2C;
    s16 sp2A;
    s16 sp28;
    s16 sp26;
    s16 sp24;

    sp60[0] = 0.f;
    sp60[1] = 0.f;
    sp60[2] = 0.f;
    vec3f_copy(sp4C, c);
    vec3f_copy(spE8[0], D_8033B470[D_8033B46C].unk4);
    vec3f_copy(spE8[1], D_8033B470[D_8033B46C + 1].unk4);
    spAC = D_8033B470[D_8033B46C].unk10;
    spA8 = D_8033B470[D_8033B46C].unk14;
    func_8027F668(&sp84, 1.f, 200.f, &sp84, 0.9f, 200.f);
    sp78[0] = D_8032D000->unk4[0];
    sp78[1] = D_8032D000->unk4[1] + 150.f + sp84;
    sp78[2] = D_8032D000->unk4[2];
    spDC[0] = spE8[0][0] + (spE8[1][0] - spE8[0][0]) * sp88;
    spDC[1] = spE8[0][1] + (spE8[1][1] - spE8[0][1]) * sp88;
    spDC[2] = spE8[0][2] + (spE8[1][2] - spE8[0][2]) * sp88;
    vec3f_get_dist_and_angle(spE8[0], spE8[1], &sp98, &spB6, &spB4);
    spD0[0] = sp78[0] - spDC[0];
    spD0[1] = sp78[1] - spDC[1];
    spD0[2] = sp78[2] - spDC[2];
    spB4 = -spB4;
    func_8028A764(spD0, spD0, spB4);
    spB4 = -spB4;
    spB6 = -spB6;
    func_8028A834(spD0, spD0, spB6);
    spB6 = -spB6;
    vec3f_copy(spB8, spD0);
    spB8[0] = -spB8[0] * 0.f;
    spB8[1] = spB8[1] * 0.f;
    spC4[0] = c[0] - spDC[0];
    spC4[1] = c[1] - spDC[1];
    spC4[2] = c[2] - spDC[2];
    spB4 = -spB4;
    func_8028A764(spC4, spC4, spB4);
    spB4 = -spB4;
    spB6 = -spB6;
    func_8028A834(spC4, spC4, spB6);
    spB6 = -spB6;

    if (spD0[2] > spC4[2])
    {
        if (spD0[2] - spC4[2] > spAC)
            spC4[2] = spD0[2] - spAC;
    }
    else
    {
        if (spD0[2] - spC4[2] < -spAC)
            spC4[2] = spD0[2] + spAC;
    }

    spD0[0] = -spD0[0] * spA8;
    spD0[1] = spD0[1] * spA8;
    spD0[2] = spC4[2];
    spB8[0] *= 0.3f;
    spB8[1] *= 0.3f;
    sp58[0] = spB6;
    sp58[1] = spB4;
    spD0[2] = sp98 / 2.f - spD0[2];
    sp58[1] = spB4 + 32768;
    sp58[2] = 0;
    func_8028C5F0(c, spE8[0], spD0, sp58);
    vec3f_get_dist_and_angle(spE8[0], a->unk10, &spA4, &spB6, &spB4);
    spB8[2] = sp98 / 2.f - spB8[2];
    func_8028C5F0(a->unk4, spE8[0], spB8, sp58);

    if (D_8033B4DA & 8)
    {
        D_8033B4DA &= ~8;
        D_8033B478[0] = sp4C[0] - a->unk10[0];
        D_8033B478[1] = sp4C[1] - a->unk10[1];
        D_8033B478[2] = sp4C[2] - a->unk10[2];
    }
    func_80288E0C(&D_8033B478[0], 0.f, 0.025f);
    func_80288E0C(&D_8033B478[1], 0.f, 0.025f);
    func_80288E0C(&D_8033B478[2], 0.f, 0.025f);
    vec3f_add(a->unk10, D_8033B478);

    if (D_8033B470[D_8033B46C + 1].unk0 != 0)
    {
        func_8028A578(D_8033B470[D_8033B46C + 1].unk4, D_8033B470[D_8033B46C + 2].unk4, &sp28, &sp24);
        vec3f_set_dist_and_angle(D_8033B470[D_8033B46C + 1].unk4, sp34, 400.f, sp28, sp24);
        sp2C = func_8028A640(sp78, sp34);
        func_8028A578(D_8033B470[D_8033B46C + 1].unk4, D_8033B470[D_8033B46C].unk4, &sp2A, &sp26);
        vec3f_set_dist_and_angle(D_8033B470[D_8033B46C + 1].unk4, sp40, 400.f, sp2A, sp26);
        sp30 = func_8028A640(sp78, sp40);
        if (sp2C < sp30)
        {
            D_8033B46C++;
            D_8033B4DA |= 8;
        }
    }

    if (D_8033B46C != 0)
    {
        func_8028A578(D_8033B470[D_8033B46C].unk4, D_8033B470[D_8033B46C + 1].unk4, &sp28, &sp24);
        vec3f_set_dist_and_angle(D_8033B470[D_8033B46C].unk4, sp34, 700.f, sp28, sp24);
        sp2C = func_8028A640(sp78, sp34);
        func_8028A578(D_8033B470[D_8033B46C].unk4, D_8033B470[D_8033B46C - 1].unk4, &sp2A, &sp26);
        vec3f_set_dist_and_angle(D_8033B470[D_8033B46C].unk4, sp40, 700.f, sp2A, sp26);
        sp30 = func_8028A640(sp78, sp40);
        if (sp2C > sp30)
        {
            D_8033B46C--;
            D_8033B4DA |= 8;
        }
    }

    vec3f_copy(b, sp78);
    vec3f_get_dist_and_angle(b, c, &spA4, &spB6, &spB4);

    return spB4;
}

int CameraChange0D(struct Struct80280550 *a, Vec3f b, UNUSED Vec3f c)
{
    float sp74;
    float sp70;
    float sp6C;
    float sp68;
    float sp64;
    UNUSED u8 filler2[8];
    float sp58 = 0.5f;
    s16 sp56;
    s16 sp54;
    Vec3s sp4C;
    struct Surface *sp48;
    Vec3f sp3C;
    UNUSED u8 filler[16];

    func_8028B21C();

    switch (D_8032CFD8)
    {
    case 241:
        sp58 = 0.f;
        sp68 = 0.f;
        break;
    case 97:
        sp58 = 0.3f;
        sp68 = 0.f;
        break;
    case 65:
        sp58 = 0.f;
        sp68 = 0.f;
        break;
    }
    func_8028B7A4(a);
    func_8028B19C();
    func_8027F668(&sp74, 1.f, 200.f, &sp74, 0.9f, 200.f);
    vec3f_copy(b, D_8032D000->unk4);
    b[1] += sp74 + 125.f;
    vec3f_get_dist_and_angle(b, a->unk10, &sp64, &sp4C[0], &sp4C[1]);
    sp4C[2] = 0;
    vec3f_copy(sp3C, D_8032D00C);
    vec3f_add(sp3C, D_8033B460);

    if (D_8033B278.unk8 != 10 && D_8033B278.unk4 != -11000.f)
        sp70 = D_8033B278.unk4 + sp3C[1] + sp68;
    else
        sp70 = D_8033B328.unk0[3][1];
    if (300 > sp64)
        sp70 += 300 - sp64;

    sp6C = find_ceil(a->unk10[0], sp70 - 100.f, a->unk10[2], &sp48);
    if (sp6C != 20000.f)
    {
        if (sp70 > (sp6C -= 125.f))
            sp70 = sp6C;
    }

    if (D_8033B4DA & 1)
    {
        func_802893E4(&a->unk10[1], sp70, 15.f);
    }
    else
    {
        if (sp70 < D_8032D000->unk4[1] - 500.f)
            sp70 = D_8032D000->unk4[1] - 500.f;
        a->unk10[1] = sp70;
    }

    a->unk10[0] = sp3C[0] + (D_8032D000->unk4[0] - sp3C[0]) * sp58;
    a->unk10[2] = sp3C[2] + (D_8032D000->unk4[2] - sp3C[2]) * sp58;

    if (sp58 != 0.f)
    {
        vec3f_get_dist_and_angle(a->unk4, a->unk10, &sp64, &sp56, &sp54);
        if (sp64 > 1000.f)
        {
            sp64 = 1000.f;
            vec3f_set_dist_and_angle(a->unk4, a->unk10, sp64, sp56, sp54);
        }
    }

    return sp4C[1];
}

int CameraChange0B(struct Struct80280550 *a, Vec3f b, Vec3f c)
{
    struct Object *sp8C;
    UNUSED u8 filler2[12];
    float sp7C;
    UNUSED u8 filler3[4];
    float sp74;
    float sp70;
    float sp6C;
    float sp68;
    UNUSED u8 filler4[4];
    UNUSED s16 sp62;
    s16 sp60;
    s16 sp5E;
    struct Surface *sp58;
    UNUSED u8 filler[20];
    Vec3f sp38;
    Vec3f sp2C = {0.f, -150.f, -125.f};

    func_8028B7A4(a);

    if (D_8032D000->unk1E == 7)
    {
        func_8027F308(3);
        D_8032D000->unk1E = 0;
    }
    if (D_8032D000->unk1E == 8)
    {
        func_8027F308(2);
        D_8032D000->unk1E = 0;
    }

    sp60 = D_8033B402 + 0x2000;
    if ((sp8C = D_8032CFD0) != NULL)
    {
        // FIXME: object
        object_pos_to_vec3f(sp38, sp8C);
        sp5E = sp8C->oHeldState;
    }
    else
    {
        sp38[0] = a->unk28;
        sp38[1] = D_8032D000->unk4[1];
        sp38[2] = a->unk2C;
        sp5E = 0;
    }

    sp7C = func_8028A640(D_8032D000->unk4, sp38) * 1.6f;
    if (sp7C < 800.f)
        sp7C = 800.f;
    if (sp7C > 5000.f)
        sp7C = 5000.f;

    if (sp5E == 1)
        func_8028C5F0(sp38, D_8032D000->unk4, sp2C, D_8032D000->unk10);

    b[0] = (D_8032D000->unk4[0] + sp38[0]) / 2.f;
    b[1] = (D_8032D000->unk4[1] + sp38[1]) / 2.f + 125.f;
    b[2] = (D_8032D000->unk4[2] + sp38[2]) / 2.f;

    vec3f_set_dist_and_angle(b, c, sp7C, 4096, sp60);
    c[1] = find_floor(a->unk28, 20000.f, a->unk2C, &sp58);
    if (sp58 != NULL)
    {
        sp74 = sp58->normal[0];
        sp70 = sp58->normal[1];
        sp6C = sp58->normal[2];
        sp68 = sp58->originOffset;
        c[1] = 300.f - (sp74 * c[0] + sp6C * c[2] + sp68) / sp70;
        switch (D_8032CFD8)
        {
        case 145:
            c[1] += 125.f;
            // fall through
        case 385:
            c[1] += 125.f;
        }
    }

    if (gCurrLevelNum == 4)
        c[1] = 2047.f;

    if (D_8033B3F8 < 0)
    {
        D_8033B402 += 0x200;
        if ((D_8033B3F8 += 0x100) > 0)
            D_8033B3F8 = 0;
    }
    if (D_8033B3F8 > 0)
    {
        D_8033B402 -= 0x200;
        if ((D_8033B3F8 -= 0x100) < 0)
            D_8033B3F8 = 0;
    }

    b[1] = (D_8032D000->unk4[1] + sp38[1]) / 2.f + 100.f;
    if (sp5E == 1)
        b[1] += 300.f * sins((gMarioStates[0].angleVel[1] > 0.f) ? gMarioStates[0].angleVel[1] : -gMarioStates[0].angleVel[1]);

    if (sp7C < 400.f)
        sp7C = 400.f;
    func_80280BD8(sp7C, 6144);
    vec3f_set_dist_and_angle(c, c, D_8033B3EE, D_8033B3F0 + 0x1000, sp60);

    return sp60;
}

void CameraChange05(UNUSED struct Struct80280550 *a, UNUSED Vec3f b, UNUSED Vec3f c)
{
}

static void unused_80282678(UNUSED int unused)
{
}

static void func_8028268C(struct Struct80280550 *a)
{
    a->unk3A = CameraChange0B(a, a->unk4, a->unk10);
}

static void func_802826CC(struct Struct80280550 *a)
{
    s16 dummy;

    func_8028B3DC(a, 0.f);
    func_8029A478(2);
    a->unk3A = CameraChange0C(a, a->unk4, a->unk10);
    func_80289184(&dummy, 0, 1024);
}

static void func_80282730(struct Struct80280550 *a)
{
    UNUSED u8 unused[8];

    if (gCurrLevelNum == 4)
        func_8029A478(7);
    else
        func_8029A478(4);
    a->unk3A = CameraChange0D(a, a->unk4, a->unk10);
    a->unk2 = a->unk3A;
    func_8027FF44(a);
    vec3f_set(D_8033B460, 0.f, 0.f, 0.f);
}

int CameraChange03(struct Struct80280550 *a, Vec3f b, Vec3f c)
{
    UNUSED u8 unused2[12];
    float sp48;
    UNUSED u8 unused3[4];
    s16 sp42;
    s16 sp40;
    s16 sp3E;
    s16 sp3C = -D_8032D000->unk10[0];
    s16 sp3A = D_8032D000->unk10[1] + 32768;
    s16 sp38 = 0;
    s16 sp36;
    s16 sp34 = 32;
    UNUSED u8 unused[12];
    float sp24 = 800.f;
    float sp20 = 125.f;

    if (D_8033B314 & 1)
    {
        sp24 = 350.f;
        sp20 = 120.f;
    }
    if (!(D_8032D000->unk0 & 0x6000))
        sp34 = 128;
    vec3f_copy(b, D_8032D000->unk4);
    a->unk4[1] += sp20;
    sp48 = func_8028A640(b, c);
    sp40 = func_8028A440(b, c);
    vec3f_get_dist_and_angle(b, c, &sp48, &sp40, &sp3E);
    if (sp48 > sp24)
        sp48 = sp24;
    if ((sp42 = sp40) < 0)
        sp42 = -sp42;
    sp36 = 32 - sp42 / 0x200;
    if (sp36 < 1)
        sp36 = 1;
    if (sp36 > 32)
        sp36 = 32;

    if (D_8033B3F8 != 0)
    {
        func_80289184(&D_8033B3F8, 0, 1);
        sp36 = 8;
    }
    if (D_8033B3FA != 0)
    {
        sp3C = 0;
        func_80289184(&D_8033B3FA, 0, 1);
        sp34 = 2048;
    }

    if (D_8033B3FA == 28)
    {
        if (D_8033B3F8 < 5 || D_8033B3F8 > 28)
            func_8028B268();
    }
    if (D_8033B3F8 == 28)
    {
        if (D_8033B3FA < 5 || D_8033B3FA > 28)
            func_8028B268();
    }

    if (D_8033B31E & 2)
    {
        if (gPlayer1Controller->buttonPressed & L_CBUTTONS)
            func_8028B2D0();
        if (sp48 < sp24)
            func_802893E4(&sp48, sp24, 5.f);
        sp38 = -16376;
        D_8033B3F8 = 30;
        sp36 = 2;
    }
    if (D_8033B31E & 1)
    {
        if (gPlayer1Controller->buttonPressed & R_CBUTTONS)
            func_8028B2D0();
        if (sp48 < sp24)
            func_802893E4(&sp48, sp24, 5.f);
        sp38 = 16376;
        D_8033B3F8 = 30;
        sp36 = 2;
    }
    if (D_8033B31E & 4)
    {
        if (gPlayer1Controller->buttonPressed & (U_CBUTTONS | D_CBUTTONS))
            func_8028B2D0();
        if (sp48 < sp24)
            func_802893E4(&sp48, sp24, 5.f);
        sp3C = -12288;
        D_8033B3FA = 30;
        sp34 = 2048;
    }
    if (D_8033B31E & 8)
    {
        if (gPlayer1Controller->buttonPressed & (U_CBUTTONS | D_CBUTTONS))
            func_8028B2D0();
        if (sp48 < sp24)
            func_802893E4(&sp48, sp24, 5.f);
        sp3C = 12288;
        D_8033B3FA = 30;
        sp34 = 2048;
    }

    func_80288ECC(&sp3E, sp3A + sp38, sp36);
    func_80289184(&sp40, sp3C, sp34);
    if (sp48 < 300.f)
        sp48 = 300.f;
    vec3f_set_dist_and_angle(b, c, sp48, sp40, sp3E);
    if (D_8032CFD8 == 177)
        sp3E = func_802899A0(c, b, 4508.f, -3739.f, 4508.f, -3739.f);
    if (D_8032CFD8 == 209)
        sp3E = func_802899A0(c, b, 8192.f, -8192.f, 8192.f, -8192.f);
    if (D_8032CFD8 == 210)
        sp3E = func_802899A0(c, b, 2458.f, -2458.f, 2458.f, -2458.f);

    return sp3E;
}

static int func_80282D90(struct Struct80280550 *a)
{
    struct MarioState *sp54 = &gMarioStates[0];
    struct Surface *sp50;
    Vec3f sp44;
    Vec3f sp38;
    float sp34;
    float sp30;
    float sp2C;
    s16 sp2A;
    s16 sp28;
    s16 sp26;

    vec3f_copy(sp38, a->unk10);
    D_8033B4D8 &= ~0x100;
    vec3f_copy(sp44, a->unk10);
    sp26 = CameraChange03(a, a->unk4, sp44);
    a->unk10[0] = sp44[0];
    a->unk10[2] = sp44[2];
    if (a->unk0 == 8)
    {
        sp30 = find_floor(a->unk10[0], a->unk10[1], a->unk10[2], &sp50);
        sp44[1] = sp54->waterLevel + 0x78;
        if (sp44[1] < (sp30 += 120.f))
            sp44[1] = sp30;
    }
    func_8028C2F0(a, sp44[1], 50.f);
    sp34 = find_water_level(a->unk10[0], a->unk10[2]) + 100.f;
    if (a->unk10[1] <= sp34)
        D_8033B4D8 |= 0x4000;
    else
        D_8033B4D8 &= ~0x4000;
    func_8028F04C(a->unk10, sp38);
    vec3f_get_dist_and_angle(a->unk4, a->unk10, &sp2C, &sp2A, &sp28);
    if (sp2C > 800.f)
    {
        sp2C = 800.f;
        vec3f_set_dist_and_angle(a->unk4, a->unk10, sp2C, sp2A, sp28);
    }
    func_8027FF44(a);

    return sp26;
}

static int func_80282FC8(struct Struct80280550 *a)
{
    struct Surface *sp4C;
    float sp48;
    Vec3f sp3C;
    float sp38;
    float sp34;
    float sp30;
    s16 sp2E;
    s16 sp2C;
    UNUSED struct MarioState *sp28 = &gMarioStates[0];
    s16 sp26 = 5461;
    s16 sp24 = D_8032D000->unk10[1] + 32768;

    if (D_8033B4DA & 0x10)
        D_8033B3EE = approach_f32(D_8033B3EE, -600.f, 20.f, 20.f);
    else
        D_8033B3EE = approach_f32(D_8033B3EE, 0.f, 20.f, 20.f);

    func_8028B1DC();
    vec3f_copy(a->unk4, D_8032D000->unk4);
    a->unk4[1] += 50.f;
    vec3f_get_dist_and_angle(a->unk4, a->unk10, &sp38, &sp2E, &sp2C);
    sp34 = 800.f;
    if (D_8032D000->unk0 == 1192)
    {
        sp34 = 1000.f;
        sp26 = 10240;
        func_80289184(&sp2C, sp24, 256);
    }
    else
    {
        func_80289184(&sp2C, sp24, 128);
    }
    func_80289184(&sp2E, sp26, 256);
    if (D_8032D000->unk0 != 1192 && D_8033B278.unk8 == 10)
    {
        vec3f_set_dist_and_angle(a->unk4, sp3C, sp34 + D_8033B3EE, sp2E, sp2C);
        a->unk10[0] = sp3C[0];
        a->unk10[2] = sp3C[2];
        func_802893E4(&a->unk10[1], a->unk4[1], 30.f);
        vec3f_get_dist_and_angle(a->unk10, a->unk4, &sp38, &sp2E, &sp2C);
        sp30 = (sp38 - sp34 + D_8033B3EE) / 10000.f;
        if (sp30 > 1.f)
            sp30 = 1.f;
        sp2E += 4096.f * sp30;
        vec3f_set_dist_and_angle(a->unk10, a->unk4, sp38, sp2E, sp2C);
    }
    else
    {
        vec3f_set_dist_and_angle(a->unk4, a->unk10, sp34 + D_8033B3EE, sp2E, sp2C);
        D_8033B4DA |= 2;
        sp48 = find_floor(a->unk10[0], a->unk10[1] + 200.f, a->unk10[2], &sp4C) + 125.f;
        if (a->unk10[1] < sp48)
            a->unk10[1] = sp48;
        vec3f_get_dist_and_angle(a->unk4, a->unk10, &sp38, &sp2E, &sp2C);
        if (sp38 > sp34 + D_8033B3EE)
        {
            sp38 = sp34 + D_8033B3EE;
            vec3f_set_dist_and_angle(a->unk4, a->unk10, sp38, sp2E, sp2C);
        }
    }

    sp2C = func_8028A4F0(a->unk4, a->unk10);
    return sp2C;
}

static void func_80283434(struct Struct80280550 *a)
{
    a->unk3A = func_80282D90(a);
}

void CameraChange08(UNUSED struct Struct80280550 *a, UNUSED Vec3f b, UNUSED Vec3f c)
{
}

static void func_80283484(struct Struct80280550 *a)
{
    a->unk3A = func_80282D90(a);
}

int CameraChange040710(UNUSED struct Struct80280550 *a, Vec3f b, Vec3f c)
{
    s16 sp2E = D_8032D000->unk10[1] + D_8033B402 + 32768;

    func_8027F870(b, c, 125.f, 125.f, D_8032CFEC, 1456, sp2E);
    return D_8032D000->unk10[1];
}

extern float D_8033B3F4;
extern float D_80336070;

static int func_80283548(struct Struct80280550 *a)
{
    Vec3f spBC;
    Vec3f spB0;
    UNUSED u8 unused1[12];
    struct Surface *spA0;
    struct Surface *sp9C;
    struct Surface *sp98;
    struct Surface *sp94;
    float sp90;
    float sp8C;
    float sp88;
    UNUSED u8 unused2[4];
    float sp80;
    float sp7C;
    float sp78;
    float sp74;
    s16 sp72;
    s16 sp70;
    s16 sp6E;
    s16 sp6C = D_8032D000->unk10[1] + 32768;
    float sp68;
    float sp64;
    float sp60;
    s16 sp5E;
    s16 sp5C;
    float sp58;
    UNUSED u8 unused4[4];
    s16 sp52;
    s16 sp50 = 0;
    float sp4C;
    int sp48 = 0;
    int sp44 = 0;
    float sp40 = find_ceil(D_8033B328.unk0[3][0], D_8033B328.unk0[3][1], D_8033B328.unk0[3][2], &sp94);
    s16 sp3E;

    func_8028B7A4(a);
    vec3f_get_dist_and_angle(D_8032D000->unk4, a->unk10, &sp80, &sp70, &sp6E);

    if (D_8033B4D8 & 2)
    {
        if (func_80288130(0) == 1)
            sp7C = D_8032CFEC + 1050.f;
        else
            sp7C = D_8032CFEC + 400.f;
    }
    else
    {
        sp7C = D_8032CFEC;
    }

    if ((D_8032D000->unk0 & 0x200000) || D_8032D000->unk0 == 1192)
    {
        sp7C *= 0.8f;
        func_802882A0(3);
    }

    if (D_8033B3F4 == 0.f)
    {
        if (sp80 > sp7C)
        {
            if ((sp80 -= 50.f) < sp7C)
                sp80 = sp7C;
        }
    }
    else
    {
        if ((D_8033B3F4 -= 30.f) < 0.f)
            D_8033B3F4 = 0;
        if (sp80 > sp7C)
        {
            if ((sp80 -= 30.f) < sp7C)
                sp80 = sp7C;
        }
        if (sp80 < sp7C)
        {
            if ((sp80 += 30.f) > sp7C)
                sp80 = sp7C;
        }
    }
    if (D_8033B3F8 == 0)
    {
        if (a->unk0 == 16)
            sp52 = 192;
        else
            sp52 = 256;
        if ((gPlayer1Controller->stickX != 0.f || gPlayer1Controller->stickY != 0.f) != 0)
            sp52 = 32;
    }
    else
    {
        if (D_8033B3F8 < 0)
            sp6E += 0x200;
        if (D_8033B3F8 > 0)
            sp6E -= 0x200;
        func_80289184(&D_8033B3F8, 0, 256);
        sp52 = 0;
    }
    D_8032CFD4 = 1024;
    sp58 = func_8028A6E4(D_8032D000->unk4, a->unk10);

    if (D_8033B4DA & 0x8000)
    {
        if (sp58 >= 250.f)
            D_8033B4DA &= ~0x8000;
        if (ABS((D_8032D000->unk10[1] - sp6E) / 2) < 0x1800)
        {
            D_8033B4DA &= ~0x8000;
            sp6E = D_8033B2B0 + 32768;
            sp80 = 800.f;
            D_8033B4DA |= 2;
        }
    }
    else if (sp58 < 250.f)
    {
        a->unk10[0] += (250.f - sp58) * sins(sp6E);
        a->unk10[2] += (250.f - sp58) * coss(sp6E);
        if (D_8033B3F8 == 0)
        {
            sp52 = 4096;
            D_8032CFD4 = 0;
            vec3f_get_dist_and_angle(D_8032D000->unk4, a->unk10, &sp80, &sp70, &sp6E);
        }
        sp44 |= 1;
    }

    if (-16.f < gPlayer1Controller->stickY)
        a->unk2 = sp6E;

    func_8027F668(&sp68, 1.f, 200.f, &sp64, 0.9f, 200.f);
    vec3f_copy(spB0, a->unk10);
    sp48 = func_8028F2F0(a, spB0, &sp72, 1536);
    if (sp48 == 3)
    {
        D_8033B2AC = sp72;
        D_8033B2AE = sp6E;
        D_8033B4DA |= 0x200;
        vec3f_get_dist_and_angle(D_8032D000->unk4, spB0, &sp58, &sp5E, &sp5C);
        func_80288ECC(&sp6E, sp72, 10);
        vec3f_set_dist_and_angle(D_8032D000->unk4, spB0, sp58, sp5E, sp5C);
        D_8033B2AE = (D_8033B2AE - sp6E) / 256;
    }
    else
    {
        if (gMarioStates[0].forwardVel == 0.f)
        {
            if (D_8033B4DA & 0x200)
            {
                if ((sp6C - sp6E) / 256 >= 0)
                    sp3E = -1;
                else
                    sp3E = 1;
                if ((D_8033B2AE > 0 && sp3E > 0) || (D_8033B2AE < 0 && sp3E < 0))
                    sp50 = sp52;
            }
            else
            {
                sp50 = sp52;
            }
        }
        else
        {
            if (sp52 == 4096)
                sp50 = sp52;
            D_8033B4DA &= ~0x200;
        }
        if (sp48 != 0)
            sp50 += sp50;
        if ((sp44 & 1) && sp48 != 0)
            sp50 = 0;
        if (sp50 != 0 && get_dialog_id() == -1)
            func_80289184(&sp6E, sp6C, sp50);
    }
    if (sp48 == 0 && !(D_8033B4DA & 0x200))
        func_80288E0C(&sp80, sp7C - 100.f, 0.05f);
    vec3f_set_dist_and_angle(D_8032D000->unk4, spB0, sp80, sp70, sp6E);
    spB0[1] += sp68 + 125.f;
    if (func_80288974(spB0, 10.f, 80.f) != 0)
        D_8033B4DA |= 0x200;
    a->unk4[0] = D_8032D000->unk4[0];
    a->unk4[1] = D_8032D000->unk4[1] + 125.f + sp64;
    a->unk4[2] = D_8032D000->unk4[2];
    sp88 = 125.f + D_8033B278.unk4;
    spA0 = D_8033B278.unk0;
    sp90 = find_floor(spB0[0], spB0[1] + 50.f, spB0[2], &sp9C) + 125.f;
    for (sp4C = 0.1f; sp4C < 1.f; sp4C += 0.2f)
    {
        func_8028A24C(spBC, spB0, D_8032D000->unk4, sp4C);
        sp8C = find_floor(spBC[0], spBC[1], spBC[2], &sp98) + 125.f;
        if (sp98 != NULL && sp8C > sp88)
        {
            sp88 = sp8C;
            spA0 = sp98;
        }
    }
    if (D_8033B314 & 1)
    {
        sp88 -= 35.f;
        sp90 -= 35.f;
        a->unk4[1] -= 25.f;
    }
    sp78 = find_water_level(spB0[0], spB0[2]);
    if (sp78 != -11000.f)
    {
        sp78 += 125.f;
        sp60 = sp78 - sp88;
        if (!(D_8033B4D8 & 0x20))
        {
            if (sp60 > 800.f && (D_8032D000->unk0 & 0x4000))
                D_8033B4D8 |= 0x20;
        }
        else
        {
            if (sp60 < 400.f || !(D_8032D000->unk0 & 0x4000))
                D_8033B4D8 &= ~0x20;
        }
        if (!(D_8033B4D8 & 0x20) && sp90 < sp78)
            sp90 = sp78;
    }
    else
    {
        D_8033B4D8 &= ~0x20;
    }

    spB0[1] = sp90;
    vec3f_copy(spBC, spB0);
    spBC[1] -= 125.f;
    if (spA0 != NULL && sp90 <= sp88)
    {
        sp48 = func_8028A0D4(a->unk4, spBC, spA0, 0, -1);
        if (sp48 != 1 && sp40 > sp88)
            sp90 = sp88;
    }
    sp68 = 0.f;
    if (a->unk0 == 16)
    {
        if (D_8033B4D8 & 2)
        {
            sp68 = 375.f;
            if (D_8032CFD8 == 130)
                sp68 /= 2.f;
        }
        else
        {
            sp68 = 100.f;
        }
    }
    if ((D_8033B4D8 & 2) && (D_8033B314 & 1))
    {
        sp68 = 610.f;
        if (D_8032CFD8 == 130 || gCurrLevelNum == 6)
            sp68 /= 2.f;
    }
    sp74 = func_80381D3C(spB0[0], spB0[2]);
    if (sp74 != -11000.f)
    {
        if ((sp74 += 130.f) > a->unk10[1])
            a->unk10[1] = sp74;
    }
    if ((D_8032D000->unk0 & 0x200000) || D_8032D000->unk0 == 1192)
    {
        sp90 = D_8032D000->unk4[1] + 400.f;
        if (a->unk0 == 16)
            sp90 -= 100.f;
        sp40 = 20000.f;
        vec3f_copy(a->unk4, D_8032D000->unk4);
    }
    if (D_8032D000->unk0 & 0x100000)
    {
        sp90 = gMarioStates[0].usedObj->oPosY + 125.f;
        if (D_8032D000->unk4[1] - 100.f > sp90)
            sp90 = D_8032D000->unk4[1] - 100.f;
        sp40 = 20000.f;
        vec3f_copy(a->unk4, D_8032D000->unk4);
    }
    if (sp90 != -11000.f)
    {
        sp90 += sp68;
        func_8028C2F0(a, sp90, 20.f);
    }
    a->unk10[0] = spB0[0];
    a->unk10[2] = spB0[2];
    spB0[0] = D_8033B328.unk0[3][0];
    spB0[1] = a->unk10[1];
    spB0[2] = D_8033B328.unk0[3][2];
    vec3f_get_dist_and_angle(spB0, a->unk10, &sp80, &sp5E, &sp5C);
    if (sp80 > 50.f)
    {
        sp80 = 50.f;
        vec3f_set_dist_and_angle(spB0, a->unk10, sp80, sp5E, sp5C);
    }
    if (D_8033B278.unk8 != 10)
    {
        vec3f_get_dist_and_angle(a->unk4, a->unk10, &sp80, &sp5E, &sp5C);
        if (sp80 > sp7C)
        {
            sp80 = sp7C;
            vec3f_set_dist_and_angle(a->unk4, a->unk10, sp80, sp5E, sp5C);
        }
    }
    if (sp40 != 20000.f)
    {
        if (a->unk10[1] > (sp40 -= 150.f) && (sp48 = func_8028A0D4(a->unk10, D_8032D000->unk4, sp94, 0, -1)) == 1)
            a->unk10[1] = sp40;
    }
    if (D_8032CFD8 == 178)
    {
        sp6E = func_802899A0(a->unk10, a->unk4, 2254.f, -3789.f, 3790.f, -2253.f);
    }
    return sp6E;
}

static void func_80284708(struct Struct80280550 *a)
{
    func_8029A478(2);
    a->unk3A = func_80283548(a);
    func_8027FF44(a);
}

static void func_8028474C(struct Struct80280550 *a)
{
    D_8032CFEC = 800.f;
    func_80284708(a);
}

static void func_80284788(struct Struct80280550 *a)
{
    D_8032CFEC = 350.f;
    func_80284708(a);
}

int CameraChange11(struct Struct80280550 *a, Vec3f b, Vec3f c)
{
    UNUSED s16 unused1;
    s16 sp5C;
    s16 sp5A;
    s16 sp58;
    s16 sp56;
    s16 sp54;
    UNUSED int unused2;
    Vec3f sp44;
    Vec3f sp38;
    struct Surface *sp34;
    float sp30;
    float sp2C;
    float sp28;
    float sp24;

    func_8028B7A4(a);
    vec3f_set(D_8032D00C, -1280.f, 614.f, 1740.f);
    func_8027F668(&sp2C, 1.f, 200.f, &sp2C, 0.9f, 200.f);
    b[0] = D_8032D000->unk4[0];
    sp24 = D_8032D000->unk4[1] + 125.f + sp2C;
    b[2] = D_8032D000->unk4[2];
    vec3f_copy(sp44, c);
    vec3f_get_dist_and_angle(D_8032D00C, b, &sp30, &sp5A, &sp58);
    vec3f_get_dist_and_angle(D_8032D00C, sp44, &sp30, &sp56, &sp54);
    D_8033B404 = sp54 - sp58;
    if (D_8033B404 < -0x4000)
        D_8033B404 = -0x4000;
    if (D_8033B404 > 0x4000)
        D_8033B404 = 0x4000;
    sp58 += D_8033B404;
    sp54 = sp58;
    func_80289184(&sp54, sp58, 4096);
    vec3f_set_dist_and_angle(D_8032D00C, sp44, 300.f, 0, sp54);
    sp38[0] = b[0] + (sp44[0] - b[0]) * 0.7f;
    sp38[1] = b[1] + (sp44[1] - b[1]) * 0.7f + 300.f;
    sp38[2] = b[2] + (sp44[2] - b[2]) * 0.7f;
    sp28 = find_floor(sp38[0], sp38[1] + 50.f, sp38[2], &sp34);

    if (sp28 != -11000.f)
    {
        if (sp28 < D_8033B278.unk4)
            sp28 = D_8033B278.unk4;
        c[1] = approach_f32(c[1], (sp28 += 125.f), 30.f, 30.f);
    }

    func_802893E4(&b[1], sp24, 30.f);
    c[0] = sp44[0];
    c[2] = sp44[2];
    sp5C = func_8028A4F0(b, c);

    return sp5C;
}

static void func_80284AFC(struct Struct80280550 *a)
{
    a->unk3A = CameraChange11(a, a->unk4, a->unk10);
}

int CameraChange090F(UNUSED struct Struct80280550 *a, Vec3f b, Vec3f c)
{
    s16 sp2E = D_8032D000->unk10[1] + D_8033B402 + 32768;

    func_8027F870(b, c, 125.f, 125.f, 800.f, 5461, sp2E);
    return D_8032D000->unk10[1];
}

static void unused_80284BCC(struct Struct80280550 *a)
{
    if (gPlayer1Controller->buttonPressed & U_CBUTTONS)
        D_8033B4D8 |= 0x2000;
    a->unk3A = func_80282FC8(a);
}

static void func_80284C2C(struct Struct80280550 *a)
{
    if (D_8033B278.unk8 == 11 || D_8033B278.unk8 == 121)
    {
        func_8028474C(a);
    }
    else
    {
        if (gPlayer1Controller->buttonPressed & U_CBUTTONS)
            D_8033B4D8 |= 0x2000;
        a->unk3A = func_80282FC8(a);
    }
}

static void func_80284CBC(struct Struct80280550 *a)
{
    vec3f_copy(D_8033B498[0], a->unk10);
    vec3f_sub(D_8033B498[0], D_8032D000->unk4);
    vec3f_set(D_8033B498[1], 0.f, a->unk4[1] - D_8032D000->unk4[1], 0.f);
}

static int func_80284D44(struct Struct80280550 *a)
{
    if (!(D_8033B4D8 & 0x2000))
    {
        D_8033B4D8 |= 0x2000;
        func_80284CBC(a);
        D_8033B31C &= ~1;
        return 1;
    }
    return 0;
}

static int func_80284DC0(struct Struct80280550 *a)
{
    struct Surface *sp74;
    Vec3f sp68;
    Vec3f sp5C;
    int sp58 = 0;
    int sp54;
    float sp50;
    float sp4C;
    float sp48;
    float sp44;
    s16 sp42;
    s16 sp40;
    s16 sp3E = 0;
    Vec3f sp30;
    Vec3f sp24;

    if ((D_8033B4D8 & 0x2000) && !(D_8033B4D8 & 0x200))
    {
        vec3f_copy(sp30, D_8033B498[0]);
        vec3f_add(sp30, D_8032D000->unk4);
        vec3f_copy(sp24, D_8033B498[1]);
        vec3f_add(sp24, D_8032D000->unk4);
        vec3f_copy(sp68, a->unk4);
        sp68[0] = D_8032D000->unk4[0];
        sp68[2] = D_8032D000->unk4[2];
        vec3f_get_dist_and_angle(sp68, a->unk10, &sp48, &sp42, &sp40);
        vec3f_copy(sp5C, a->unk10);
        sp48 = 80.f;
        if (D_8033B418.unk2 == 17 || D_8033B418.unk2 == 4 || D_8033B418.unk2 == 16)
        {
            sp58 = 1;
            for (sp54 = 0; sp54 < 16 && sp58 == 1; sp54++)
            {
                vec3f_set_dist_and_angle(sp68, sp5C, sp48, 0, sp40 + sp3E);
                if (resolve_wall_collisions(&sp5C[0], &sp5C[1], &sp5C[2], 20.f, 50.f) == 0)
                {
                    for (sp44 = sp48; sp44 < D_8032CFEC; sp44 += 20.f)
                    {
                        vec3f_set_dist_and_angle(sp68, sp5C, sp44, 0, sp40 + sp3E);
                        sp50 = find_ceil(sp5C[0], sp5C[1] - 150.f, sp5C[2], &sp74) + -10.f;
                        if (sp74 != NULL && sp50 < sp5C[1])
                            break;
                        sp4C = find_floor(sp5C[0], sp5C[1] + 150.f, sp5C[2], &sp74) + 10.f;
                        if (sp74 != NULL && sp4C > sp5C[1])
                            break;
                        if (resolve_wall_collisions(&sp5C[0], &sp5C[1], &sp5C[2], 20.f, 50.f) == 1)
                            break;
                    }
                    if (sp44 >= D_8032CFEC)
                        sp58 = 0;
                }
                if (sp58 == 1)
                {
                    sp3E = -sp3E;
                    if (sp3E < 0)
                        sp3E -= 0x1000;
                    else
                        sp3E += 0x1000;
                }
            }
            if (sp58 == 0)
            {
                vec3f_set_dist_and_angle(sp68, D_8033B498[0], D_8032CFEC, 0, sp40 + sp3E);
                vec3f_copy(D_8033B498[1], sp68);
                vec3f_sub(D_8033B498[0], D_8032D000->unk4);
                vec3f_sub(D_8033B498[1], D_8032D000->unk4);
            }
            D_8033B4D8 |= 0x200;
            func_80285A8C(a, 15);
        }
        else
        {
            D_8033B4D8 &= ~0x2200;
            vec3f_set_dist_and_angle(sp68, a->unk10, sp48, sp42, sp40 + sp3E);
        }
        func_8028B29C();
    }
    return 0;
}

int CameraChange06(UNUSED struct Struct80280550 *a, Vec3f b, Vec3f c)
{
    s16 sp2E = D_8033B400;
    s16 sp2C = D_8032D000->unk10[1] + D_8033B402 + 32768;

    func_8027F870(b, c, 125.f, 125.f, 250.f, sp2E, sp2C);
    return D_8032D000->unk10[1];
}

void func_802852F4(UNUSED struct Struct80280550 *a)
{
    UNUSED s16 sp6 = D_8033B400;
    UNUSED s16 sp4 = D_8033B402;

    D_8033B400 += (s16)(gPlayer1Controller->stickY * 10.f);
    D_8033B402 -= (s16)(gPlayer1Controller->stickX * 10.f);

    if (D_8033B400 > 14563)
        D_8033B400 = 14563;
    if (D_8033B400 < -8192)
        D_8033B400 = -8192;
    if (D_8033B402 > 21845)
        D_8033B402 = 21845;
    if (D_8033B402 < -21845)
        D_8033B402 = -21845;

    D_8032D000->unk16 = D_8033B400 * 3 / 4;
    D_8032D000->unk18 = D_8033B402 * 3 / 4;
}

static void func_8028547C(struct Struct80280550 *a)
{
    struct Struct8033B418_sub *sp2C = &D_8033B418.unk8[0];
    struct Struct8033B418_sub *sp28 = &D_8033B418.unk8[1];
    float sp24 = sp28->unk18 - sp2C->unk18;
    s16 sp22 = sp28->unk1C - sp2C->unk1C;
    s16 sp20 = sp28->unk1E - sp2C->unk1E;

    sp24 = sp2C->unk18 + sp24 * D_8033B418.unk6 / D_8033B418.unk4;
    sp22 = sp2C->unk1C + sp22 * D_8033B418.unk6 / D_8033B418.unk4;
    sp20 = sp2C->unk1E + sp20 * D_8033B418.unk6 / D_8033B418.unk4;
    a->unk4[0] = sp2C->unk0[0] + (sp28->unk0[0] - sp2C->unk0[0]) * D_8033B418.unk6 / D_8033B418.unk4;
    a->unk4[1] = sp2C->unk0[1] + (sp28->unk0[1] - sp2C->unk0[1]) * D_8033B418.unk6 / D_8033B418.unk4;
    a->unk4[2] = sp2C->unk0[2] + (sp28->unk0[2] - sp2C->unk0[2]) * D_8033B418.unk6 / D_8033B418.unk4;
    vec3f_add(a->unk4, D_8032D000->unk4);
    vec3f_set_dist_and_angle(a->unk4, a->unk10, sp24, sp22, sp20);
    D_8032D000->unk16 = 0;
    D_8032D000->unk18 = 0;
    if (++D_8033B418.unk6 == D_8033B418.unk4)
        D_8033B4D8 &= ~0x100;
}

static int func_80285770(struct Struct80280550 *a)
{
    UNUSED u8 unused[16];

    if (!(D_8033B31C & 1))
    {
        func_8028B268();
        D_8033B31C |= 1;
    }
    if (D_8033B4D8 & 0x100)
    {
        D_8033B4D8 |= 0x2000;
        func_8028547C(a);
        return 1;
    }
    if (!(D_8033B4D8 & 0x200))
    {
        func_802852F4(a);
        CameraChange06(a, a->unk4, a->unk10);
    }
    else
    {
        if (D_8033B4DA & 0x800)
        {
            vec3f_copy(a->unk10, D_8033B498[0]);
            vec3f_add(a->unk10, D_8032D000->unk4);
            vec3f_copy(a->unk4, D_8033B498[1]);
            vec3f_add(a->unk4, D_8032D000->unk4);
            func_80289184(&D_8032D000->unk16, 0, 1024);
            func_80289184(&D_8032D000->unk18, 0, 1024);
        }
        else
        {
            D_8033B4D8 &= ~0x2200;
        }
    }
    D_8033B40C = 0.f;
    if (gPlayer1Controller->buttonPressed & (A_BUTTON | B_BUTTON | D_CBUTTONS | L_CBUTTONS | R_CBUTTONS))
        func_80284DC0(a);
    return 0;
}

extern float D_8033B410;

int CameraChange0A(UNUSED struct Struct80280550 *a, Vec3f b, Vec3f c)
{
    func_8027F870(c, b, 125.f + D_8033B410, 125.f, 800.f,
        D_8032D000->unk10[0], D_8032D000->unk10[1]);
    return D_8032D000->unk10[1];
}

static void func_802859B0(struct Struct80280550 *a)
{
    UNUSED u8 unused[24];

    D_8033B3F0 = 0;
    D_8033B4D8 &= ~0x100;
    a->unk3A = CameraChange0A(a, a->unk4, a->unk10);
    if (gPlayer1Controller->buttonPressed & A_BUTTON)
    {
        func_80285BD8(a, 3, 1);
        D_8033B40C = 0;
        D_8033B410 = 0;
        D_8033B4DA &= ~0x2;
    }
    else
    {
        D_8033B410 = approach_f32(D_8033B410, 0.f, 100.f, 100.f);
    }
}

extern int D_8033B260;

void func_80285A8C(UNUSED struct Struct80280550 *a, s16 b)
{
    if (!(D_8033B4DA & 4))
    {
        D_8033B4DA |= 0xC00;
        D_8033B260 = b;
    }
}

static void func_80285AD8(struct Struct80280550 *a, s16 b, s16 c)
{
    if (a->unk0 != b)
    {
        D_8033B418.unk0 = (b != -1) ? b : D_8033B418.unk2;
        D_8033B418.unk2 = a->unk0;
        a->unk0 = D_8033B418.unk0;
        D_8033B4D8 &= 0xFF02;
        if (!(D_8033B4DA & 4))
        {
            func_80285A8C(a, c);
            D_8033B400 = 0;
            D_8033B402 = 0;
            D_8033B3EE = 0;
            D_8033B3F0 = 0;
            D_8033B3EC = 0;
            D_8033B40C = 0.f;
            D_8033B410 = 0.f;
        }
    }
}

extern int (*TableCameraTransitions[])(struct Struct80280550 *, Vec3f, Vec3f);

void func_80285BD8(struct Struct80280550 *a, s16 b, s16 c)
{
    struct Struct8033B418_sub *sp24 = &D_8033B418.unk8[0];
    struct Struct8033B418_sub *sp20 = &D_8033B418.unk8[1];

    if (b == 8 && D_8032CFD8 == 577)
    {
    }
    else
    {
        D_8033B4D8 &= 0xFF02;
        D_8033B4D8 |= 0x100;
        if (b == 0)
            b = 4;
        D_8033B400 = 0;
        D_8033B402 = 0;
        D_8033B3EE = 0;
        D_8033B3F0 = 0;
        D_8033B3EC = 0;
        D_8033B418.unk0 = (b != -1) ? b : D_8033B418.unk2;
        D_8033B418.unk2 = a->unk0;
        D_8033B41C = c;
        D_8033B41E = 1;
        a->unk0 = D_8033B418.unk0;
        D_8033B364 = a->unk0;
        vec3f_copy(sp20->unk0, a->unk4);
        vec3f_sub(sp20->unk0, D_8032D000->unk4);
        vec3f_copy(sp20->unkC, a->unk10);
        vec3f_sub(sp20->unkC, D_8032D000->unk4);
        D_8033B3EA = TableCameraTransitions[D_8033B418.unk0](a, sp20->unk0, sp20->unkC);
        vec3f_sub(sp20->unk0, D_8032D000->unk4);
        vec3f_sub(sp20->unkC, D_8032D000->unk4);
        vec3f_copy(sp24->unk0, D_8033B328.unk0[0]);
        vec3f_sub(sp24->unk0, D_8032D000->unk4);
        vec3f_copy(sp24->unkC, D_8033B328.unk0[1]);
        vec3f_sub(sp24->unkC, D_8032D000->unk4);
        vec3f_get_dist_and_angle(sp24->unk0, sp24->unkC, &sp24->unk18, &sp24->unk1C, &sp24->unk1E);
        vec3f_get_dist_and_angle(sp20->unk0, sp20->unkC, &sp20->unk18, &sp20->unk1C, &sp20->unk1E);
    }
}

static void func_80285E70(struct Struct80280550 *a)
{
    struct Surface *sp5C = NULL;
    Vec3f sp50;
    Vec3f sp44;
    UNUSED u8 unused1[12];
    float sp34;
    s16 sp32;
    UNUSED u8 unused2[4];

    if (D_8033B4D8 & 0x8000)
    {
    }
    else
    {
        if (a->unk30 != 0)
        {
        }
        sp32 = func_8028C824(sp50, sp44, a->unk10, a->unk4,
            D_8033B1F8, D_8033B208, a->unk3A);
        func_80289354(&a->unk2, sp32, D_8032CFD4);
        if (1)
        {
            D_8033B4DA &= ~0x4000;
        }
        else
        {
            //! dead code
            vec3f_copy(sp50, a->unk10);
            vec3f_copy(sp44, a->unk4);
        }
        vec3f_copy(D_8033B1F8, sp50);
        vec3f_copy(D_8033B208, sp44);
        D_8033B3A4 = a->unk2;
        D_8033B3A6 = a->unk3A;
        vec3f_copy(D_8033B328.unk0[3], a->unk10);
        vec3f_copy(D_8033B328.unk0[2], a->unk4);
        func_8028909C(D_8033B328.unk0[1], sp50, D_8033B3D4, D_8033B3D8, D_8033B3D4);
        func_8028909C(D_8033B328.unk0[0], sp44, D_8033B3CC, D_8033B3D0, D_8033B3CC);
        func_80288D74(&D_8033B328.unkA4, 0.8f, 0.05f);
        func_80288D74(&D_8033B328.unkA8, 0.3f, 0.05f);
        func_80288D74(&D_8033B328.unkAC, 0.3f, 0.05f);
        func_80288D74(&D_8033B328.unkB0, 0.3f, 0.05f);
        if (D_8033B4DA & 2)
            D_8033B4DA &= ~2;
        else
            D_8033B4DA |= 1;
        vec3f_copy(D_8033B328.unk8C, D_8033B328.unk0[1]);
        vec3f_copy(D_8033B328.unk80, D_8033B328.unk0[0]);
        if (a->unk30 != 0)
        {
            vec3f_add(D_8033B328.unk80, D_8033B218);
            vec3f_set(D_8033B218, 0.f, 0.f, 0.f);
        }
        vec3f_get_dist_and_angle(D_8033B328.unk8C, D_8033B328.unk80,
            &D_8033B328.unk48, &D_8033B328.unk4C, &D_8033B328.unk4E);
        D_8033B3A2 = 0;
        func_8028AC30(D_8033B328.unk8C, D_8033B328.unk80);
        func_8028AD44(D_8033B328.unk8C, D_8033B328.unk80);
        func_8028AE50(&D_8033B328.unk7A);
        func_802883C8(D_8033B328.unk8C, D_8033B328.unk80);
        if (D_8032D000->unk0 == 0x0188088A && D_8033B3E0 != 0x0188088A)
            func_8027EFE0(8);
        D_8033B3A2 += D_8033B308;
        D_8033B3A2 += D_8033B3DC;
        if (a->unk0 != 6 && a->unk30 == 0)
        {
            D_8035FE10 = 1;
            sp34 = find_floor(
                D_8033B328.unk8C[0],
                D_8033B328.unk8C[1] + 20.f,
                D_8033B328.unk8C[2],
                &sp5C);
            if (sp34 != -11000.f)
            {
                if (D_8033B328.unk8C[1] < (sp34 += 100.f))
                    D_8033B328.unk8C[1] = sp34;
                else
                    D_8035FE10 = 0;
            }
        }
        vec3f_copy(D_8033B250.unk14, D_8032D000->unk4);
    }
    func_80288C2C(D_8033B328.unk8C, D_8033B328.unk80, 15872, -15872);
    D_8033B364 = a->unk0;
    D_8033B365 = a->unk1;
}

void func_80286348(struct Struct80280550 *a)
{
    UNUSED u8 unused[24];

    D_8033B860 = a;
    update_camera_status(a);
    if (a->unk30 == 0)
    {
        if (func_8028803C(0) == 1)
        {
            if (gPlayer1Controller->buttonPressed & R_TRIG)
            {
                if (func_80288130(0) == 2)
                    func_80288130(1);
                else
                    func_80288130(2);
            }
        }
        func_8028B36C();
    }
    D_8033B4DA &= ~4;
    if (D_8033B4D8 & 0x800)
    {
        func_80286C9C(a);
        D_8033B4D8 &= ~0x800;
        D_8033B4DA |= 4;
    }
    D_8033B278.unk1C = D_8033B278.unk4;
    D_8033B278.unk28 = D_8033B278.unk14;
    D_8033B278.unk18 = D_8033B278.unk0;
    D_8033B278.unk24 = D_8033B278.unkC;
    D_8033B278.unk20 = D_8033B278.unk8;
    D_8033B278.unk2C = D_8033B278.unk10;
    func_8028F678(&D_8033B278);
    D_8035FE10 = 1;
    vec3f_copy(a->unk10, D_8033B328.unk0[3]);
    vec3f_copy(a->unk4, D_8033B328.unk0[2]);
    a->unk2 = D_8033B3A4;
    a->unk3A = D_8033B3A6;
    a->unk0 = D_8033B364;
    a->unk1 = D_8033B365;
    func_8028E88C(a);
    dummy_802877EC(a);
    D_8033B31E = func_802886FC(D_8033B31E, gPlayer1Controller->buttonPressed, gPlayer1Controller->buttonDown);
    if (a->unk30 != 0)
    {
        D_8032CFD4 = 0;
        func_80298DCC(a);
        D_8032CFF8 = 0;
    }
    else
    {
        if (D_8032CFF4 != 0 && D_8032CFF8 < 8)
        {
            D_8032CFF8++;
            if (D_8032CFF8 >= 8)
            {
                D_8032CFF4 = 0;
                D_8032CFF8 = 0;
            }
        }
    }
    if (a->unk30 == 0)
    {
        D_8032CFD4 = 0x400;
        if (D_8033B314 & 1)
        {
            switch (a->unk0)
            {
            case 3:
                func_80283434(a);
                break;
            case 6:
                func_80285770(a);
                break;
            case 8:
                func_80283484(a);
                break;
            case 10:
                func_802859B0(a);
                break;
            default:
                func_80284788(a);
            }
        }
        else
        {
            switch (a->unk0 - 1)
            {
            case 2:
                func_80283434(a);
                break;
            case 5:
                func_80285770(a);
                break;
            case 7:
                func_80283484(a);
                break;
            case 9:
                func_802859B0(a);
                break;
            case 13:
                func_80280FD8(a);
                break;
            case 0:
                func_80280EBC(a);
                break;
            case 1:
                func_8028124C(a);
                break;
            case 3:
                func_8028474C(a);
                break;
            case 15:
                func_8028474C(a);
                break;
            case 10:
                func_8028268C(a);
                break;
            case 11:
                func_802826CC(a);
                break;
            case 8:
                func_80284C2C(a);
                break;
            case 12:
                func_80282730(a);
                break;
            case 16:
                func_80284AFC(a);
                break;
            }
        }
    }
    func_8028BB3C(a, func_8028BCC8(a));
    dummy_802877D8(a);
    D_8035FE10 = 0;
    if (gCurrLevelNum != 6)
    {
        if ((a->unk30 == 0 && (gPlayer1Controller->buttonDown & R_TRIG) && func_8028803C(0) == 2)
         || (D_8033B4D8 & 0x40) || (D_8032D000->unk0) == 0x010208B8)
        {
            if (a->unk30 == 0 && (gPlayer1Controller->buttonPressed & R_TRIG) && func_8028803C(0) == 2)
            {
                D_8033B31C |= 0x20;
                func_8028B338();
            }
            D_8033B3D4 = 0.f;
            D_8033B3D8 = 0.f;
            a->unk3A = func_8028A4F0(D_8033B328.unk80, D_8033B328.unk8C);
            a->unk2 = a->unk3A;
            D_8033B4D8 &= ~0x40;
        }
        else
        {
            if (D_8033B31C & 0x20)
            {
                func_8028B338();
                D_8033B31C &= ~0x20;
            }
        }
    }
    else
    {
        if ((gPlayer1Controller->buttonPressed & R_TRIG) && func_8028803C(0) == 2)
            func_8028B304();
    }
    func_80285E70(a);
    D_8033B3E0 = D_8032D000->unk0;
}

void func_802869B8(struct Struct80280550 *a)
{
    UNUSED int sp34 = 0;
    UNUSED u8 unused[16];
    UNUSED struct Struct8033B418_sub *sp20 = &D_8033B418.unk8[0];
    UNUSED struct Struct8033B418_sub *sp1C = &D_8033B418.unk8[1];

    D_8033B860 = a;
    D_8033B4D8 = 0;
    D_8033B318 = 0;
    D_8033B4DA = 0;
    D_8033B6EC = 0;
    D_8033B6EA = 0;
    D_8033B85C = 0;
    D_8033B858 = 0;
    D_8032CFC4 = NULL;
    D_8032CFC8 = 0;
    D_8032CFCC = 0;
    D_8032CFD0 = NULL;
    D_8033B31E = 0;
    vec3f_copy(D_8033B250.unk14, D_8032D000->unk4);
    D_8033B260 = 0;
    D_8032CFCC = -1;
    D_8032CFC8 = -1;
    D_8033B4D8 = 0;
    D_8033B4D8 |= 0x800;
    D_8033B316 = 0;
    D_8033B4DA = 0;
    D_8033B31A = 0;
    D_8033B31C = 0;
    D_8033B400 = 0;
    D_8033B402 = 0;
    D_8033B404 = 0;
    D_8033B3EE = 0;
    D_8033B3F0 = 0;
    D_8033B3EA = 0;
    D_8033B3EC = 0.f;
    D_8033B40C = 0.f;
    D_8033B410 = 0.f;
    D_8033B3F4 = 0.f;
    D_8033B3FC = 0.f;
    D_8033B3FA = 0;
    D_8033B3F8 = 0;
    D_8033B406 = 0;
    D_8033B408 = 0;
    a->unk64 = 0;
    D_8032D000->unk16 = 0;
    D_8032D000->unk18 = 0;
    D_8032D004->unk16 = 0;
    D_8032D004->unk18 = 0;
    D_8032D000->unk1E = 0;
    D_8032D000->unk20 = 0;
    D_8033B328.unk52[0] = 0;
    D_8033B328.unk52[1] = 0;
    D_8033B328.unk52[2] = 0;
    D_8033B328.unk6C[0] = 0;
    D_8033B328.unk6C[1] = 0;
    D_8033B328.unk6C[2] = 0;
    D_8033B328.unk60[0] = 0.f;
    D_8033B328.unk60[1] = 0.f;
    D_8033B328.unk60[2] = 0.f;
    D_8033B3E0 = 0;
    func_8029A478(2);
    D_8033B234 = 45.f;
    D_8033B238 = 0.f;
    D_8033B23C = 0;
    D_8033B240 = 0.f;
    D_8033B244 = 0;
    D_8032CFF0 = 0;
    D_8032CFF4 = 0;
    D_8033B30C = 0;
    D_8033B310 = 0;
}

void func_80286C9C(struct Struct80280550 *a)
{
    struct Surface *sp34 = 0;
    Vec3f sp28;
    int sp24;

    D_8033B224 = 0;
    D_8033B226 = 0;
    D_8032CFDC = D_8032CFD8 / 16;
    D_8032CFD8 = gCurrLevelNum * 16 + gCurrentArea->index;
    D_8033B314 &= 4;
    D_8033B228 = 0;
    D_8033B364 = a->unk0;
    D_8033B365 = a->unk1;
    D_8033B3D4 = 0.3f;
    D_8033B3D8 = 0.3f;
    D_8033B3CC = 0.8f;
    D_8033B3CC = 0.3f;
    D_8033B3A2 = 0;
    D_8033B3DC = 0;
    D_8033B3E4 = 0;
    D_8033B4DA &= ~1;
    vec3f_set(D_8033B460, 0.f, 0.f, 0.f);
    vec3f_set(D_8033B218, 0.f, 0.f, 0.f);
    func_8028F678(&D_8033B278);
    D_8033B278.unk1C = D_8033B278.unk4;
    D_8033B278.unk28 = D_8033B278.unk14;
    D_8033B278.unk18 = D_8033B278.unk0;
    D_8033B278.unk24 = D_8033B278.unkC;
    D_8033B278.unk20 = D_8033B278.unk8;
    D_8033B278.unk2C = D_8033B278.unk10;
    for (sp24 = 0; sp24 < 32; sp24++)
    {
        D_8033B4E0[sp24][0] = -1;
        D_8033B5E0[sp24][0] = -1;
    }
    D_8033B6E0 = 0;
    D_8033B6E4 = 0.f;
    D_8033B6E8 = 0;
    D_8033B300 = 0.f;
    D_8033B2FC = 0.f;
    D_8033B2F8 = 0;
    for (sp24 = 0; sp24 < 4; sp24++)
        D_8033B2B8[sp24].unk0 = -1;
    D_8033B304 = 0;
    D_8033B306 = 0;
    D_8033B308 = 0;
    a->unk30 = 0;
    sp28[0] = 0.f;
    sp28[1] = 125.f;
    sp28[2] = 400.f;
    switch (gCurrLevelNum - 6)
    {
    case 24:
#if VERSION_US
        if (gCurrDemoInput == NULL)
            func_8028BB3C(a, 144);
        else if (D_8032CFD0 != NULL)
            D_8032CFD0->OBJECT_FIELD_U32(0x00) = 2;
#else
        func_8028BB3C(a, 144);
#endif
        break;
    case 27:
        func_8028BB3C(a, 144);
        break;
    case 28:
        func_8028BB3C(a, 144);
        break;
    case 10:
        if (func_80288CF0(-1328.f, 260.f, 4664.f) != 1)
        {
            sp28[0] = -400.f;
            sp28[2] = -800.f;
        }
        if (func_80288CF0(-6901.f, 2376.f, -6509.f) == 1)
            func_8028BB3C(a, 179);
        if (func_80288CF0(5408.f, 4500.f, 3637.f) == 1)
            func_8028BB3C(a, 180);
        D_8033B364 = 16;
        break;
    case 14:
        sp28[2] = 200.f;
        break;
    case 20:
        sp28[2] = -300.f;
        break;
    case 16:
        D_8033B4D8 |= 2;
        break;
    case 0:
        sp28[2] = 150.f;
        break;
    case 9:
        vec3f_set(D_8032D00C, -2985.f, 478.f, -5568.f);
        break;
    }
    if (a->unk0 == 14)
        D_8033B4D8 |= 2;
    switch (D_8032CFD8)
    {
    case 131:
        vec3f_set(sp28, 0.f, 500.f, -100.f);
        break;
    case 82:
        sp28[2] = -300.f;
        break;
    case 211:
        sp28[2] = -300.f;
        break;
    case 162:
        sp28[2] = -300.f;
        break;
    case 161:
        if (func_80288CF0(257.f, 2150.f, 1399.f) == 1)
            sp28[2] = -300.f;
        break;
    case 81:
        D_8033B4D8 |= 2;
        break;
    case 577:
        D_8033B364 = 1;
        break;
    }
    func_8028C5F0(a->unk10, D_8032D000->unk4, sp28, D_8032D000->unk10);
    if (a->unk0 != 3)
        a->unk10[1] = find_floor(D_8032D000->unk4[0], D_8032D000->unk4[1] + 100.f, D_8032D000->unk4[2], &sp34) + 125.f;
    vec3f_copy(a->unk4, D_8032D000->unk4);
    vec3f_copy(D_8033B328.unk0[1], a->unk10);
    vec3f_copy(D_8033B328.unk0[0], a->unk4);
    vec3f_copy(D_8033B328.unk0[3], a->unk10);
    vec3f_copy(D_8033B328.unk0[2], a->unk4);
    vec3f_copy(D_8033B328.unk8C, a->unk10);
    vec3f_copy(D_8033B328.unk80, a->unk4);
    if (a->unk0 == 13)
        func_8028D288(a->unk0);
    func_80284CBC(a);
    D_8033B3A4 = func_8028A4F0(a->unk4, a->unk10);
    D_8033B3A6 = D_8033B3A4;
    a->unk2 = D_8033B3A4;
    a->unk3A = D_8033B3A4;
}

static void func_80287404(struct Struct80287404 *a)
{
    UNUSED u8 unused1[8];
    float sp34;
    s16 sp32;
    s16 sp30;
    UNUSED u8 unused2[4];
    int sp28 = D_8032CFD8 / 32;
    int sp24 = 1 << (((D_8032CFD8 & 0x10) / 4) + (((D_8032CFD8 & 0xF) - 1) & 3));

    if (sp28 >= 0x13)
    {
        sp28 = 0;
        sp24 = 0;
    }
    if (D_8033B4D8 & 0x8000)
    {
        if (D_8033B228 >= 2)
        {
            if (D_8032E910[sp28] & sp24)
            {
                a->unk28[0] = D_8033B860->unk28;
                a->unk28[1] = (D_8032D000->unk4[1] + D_8033B860->unk68) / 2.f;
                a->unk28[2] = D_8033B860->unk2C;
                vec3f_get_dist_and_angle(a->unk28, D_8032D000->unk4, &sp34, &sp32, &sp30);
                vec3f_set_dist_and_angle(D_8032D000->unk4, a->unk1C, 6000.f, 4096, sp30);
                if (gCurrLevelNum != 13)
                    func_802800F4(a->unk1C, a->unk28, 0);
            }
        }
        else
        {
            D_8033B228++;
        }
    }
    else
    {
        D_8033B228 = 0;
    }
}

void func_802875DC(void)
{
    D_8033B314 = 4;
}

static void func_802875F8(struct Struct80287404 *a, struct AllocOnlyPool *b)
{
    s16 sp1E = a->unk18;
    struct Struct80280550 *sp18 = alloc_only_pool_alloc(b, 108);

    a->unk18 = (s32)sp18;
    sp18->unk0 = sp1E;
    sp18->unk1 = sp1E;
    sp18->unk30 = 0;
    sp18->unk64 = 0;
    sp18->unk28 = a->unk28[0];
    sp18->unk68 = a->unk28[1];
    sp18->unk2C = a->unk28[2];
    sp18->unk2 = 0;
    vec3f_copy(sp18->unk10, a->unk1C);
    vec3f_copy(sp18->unk4, a->unk28);
}

static void func_802876D0(struct Struct80287404 *a)
{
    UNUSED u8 unused[8];
    UNUSED int sp1C = a->unk18;

    a->unk3A = D_8033B3A2;
    vec3f_copy(a->unk1C, D_8033B328.unk8C);
    vec3f_copy(a->unk28, D_8033B328.unk80);
    func_80287404(a);
}

int Geo0F_80287D30(int a, struct Struct80287404 *b, struct AllocOnlyPool *c)
{
    struct Struct80287404 *sp2C = b;
    UNUSED struct AllocOnlyPool *sp28 = c;

    switch (a)
    {
    case 0:
        func_802875F8(sp2C, c);
        break;
    case 1:
        func_802876D0(sp2C);
        break;
    }
    return 0;
}

void dummy_802877D8(UNUSED struct Struct80280550 *a)
{
}

void dummy_802877EC(UNUSED struct Struct80280550 *a)
{
}

void vec3f_sub(Vec3f dst, Vec3f src)
{
    dst[0] -= src[0];
    dst[1] -= src[1];
    dst[2] -= src[2];
}

void object_pos_to_vec3f(Vec3f dst, struct Object *src)
{
    dst[0] = src->oPosX;
    dst[1] = src->oPosY;
    dst[2] = src->oPosZ;
}

void vec3f_to_object_pos(struct Object *dst, Vec3f src)
{
    dst->oPosX = src[0];
    dst->oPosY = src[1];
    dst->oPosZ = src[2];
}


static void unused_object_angle_to_vec3s(Vec3s dst, struct Object *src)
{
    dst[0] = src->oMoveAnglePitch;
    dst[1] = src->oMoveAngleYaw;
    dst[2] = src->oMoveAngleRoll;
}

extern float D_80336160;

extern s16 D_8033B2B2;
extern s16 D_8033B2B4;

static void func_802878B8(float a, Vec3f b, Vec3f c, Vec3f d, Vec3f e, Vec3f f)
{
    float sp40[4];
    float sp3C;
    float sp38;
    float sp34;
    UNUSED u8 unused[16];

    if (a > 1.f)
        a = 1.f;
    sp40[0] = (1.f - a) * (1.f - a) * (1.f - a) / 6.f;
    sp40[1] = a * a * a / 2.f - a * a + 0.6666667f;
    sp40[2] = -a * a * a / 2.f + a * a / 2.f + a / 2.f + 0.16666667f;
    sp40[3] = a * a * a / 6.f;
    b[0] = sp40[0] * c[0] + sp40[1] * d[0] + sp40[2] * e[0] + sp40[3] * f[0];
    b[1] = sp40[0] * c[1] + sp40[1] * d[1] + sp40[2] * e[1] + sp40[3] * f[1];
    b[2] = sp40[0] * c[2] + sp40[1] * d[2] + sp40[2] * e[2] + sp40[3] * f[2];
    sp40[0] = -0.5f * a * a + a - 0.33333333f;
    sp40[1] = 1.5f * a * a - 2.f * a - 0.5f;
    sp40[2] = -1.5f * a * a + a + 1.f;
    sp40[3] = 0.5f * a * a - 0.16666667f /*D_80336160*/;
    sp3C = sp40[0] * c[0] + sp40[1] * d[0] + sp40[2] * e[0] + sp40[3] * f[0];
    sp38 = sp40[0] * c[1] + sp40[1] * d[1] + sp40[2] * e[1] + sp40[3] * f[1];
    sp34 = sp40[0] * c[2] + sp40[1] * d[2] + sp40[2] * e[2] + sp40[3] * f[2];
    D_8033B2B2 = atan2s(sqrtf(sp3C * sp3C + sp34 * sp34), sp38);
    D_8033B2B4 = atan2s(sp34, sp3C);
}

int func_80287CFC(Vec3f a, struct Struct8032E040 *b, s16 *c, float *d)
{
    int sp6C = 0;
    Vec3f sp3C[4];
    int sp38 = 0;
    float sp34 = *d;
    UNUSED float sp30;
    float sp2C = 0.f;
    float sp28 = 0.f;
    int sp24 = *c;

    if (*c < 0)
    {
        sp24 = 0;
        sp34 = 0;
    }
    if (b[sp24].unk0 == -1 || b[sp24 + 1].unk0 == -1 || b[sp24 + 2].unk0 == -1)
        return 1;
    for (sp38 = 0; sp38 < 4; sp38++)
    {
        sp3C[sp38][0] = b[sp24 + sp38].unk2[0];
        sp3C[sp38][1] = b[sp24 + sp38].unk2[1];
        sp3C[sp38][2] = b[sp24 + sp38].unk2[2];
    }
    func_802878B8(sp34, a, sp3C[0], sp3C[1], sp3C[2], sp3C[3]);
    if (b[*c + 1].unk1 != 0)
        sp2C = 1.f / b[*c + 1].unk1;
    if (b[*c + 2].unk1 != 0)
        sp28 = 1.f / b[*c + 2].unk1;
    sp30 = (sp28 - sp2C) * *d + sp2C;
    if (1.f <= (*d += sp30))
    {
        (*c)++;
        if (b[*c + 3].unk0 == -1)
        {
            *c = 0;
            sp6C = 1;
        }
        *d -= 1.f;
    }
    return sp6C;
}

int func_8028803C(int a)
{
    int sp1C = 2;

    if (a == 1)
    {
        if (!(D_8033B314 & 4))
            D_8033B314 |= 4;
        D_8033B31C |= 8;
    }
    if (a == 2 && (D_8033B314 & 4))
    {
        func_80288130(2);
        D_8033B314 &= ~4;
        D_8033B31C |= 0x10;
    }
    if (D_8033B314 & 4)
        sp1C = 1;
    return sp1C;
}

int func_80288130(int a)
{
    int sp4 = 2;

    if (a == 1 && !(D_8033B314 & 1))
    {
        D_8033B314 |= 1;
        if (D_8033B4D8 & 2)
        {
            D_8033B314 |= 2;
            D_8033B4D8 &= ~2;
        }
        D_8033B31C |= 2;
    }
    if (a == 2 && (D_8033B314 & 1))
    {
        D_8033B314 &= ~1;
        if (D_8033B314 & 2)
        {
            D_8033B314 &= ~2;
            D_8033B4D8 |= 2;
        }
        else
        {
            D_8033B4D8 &= ~2;
        }
        D_8033B31C |= 4;
    }
    if (D_8033B314 & 1)
        sp4 = 1;
    return sp4;
}

void func_802882A0(u8 a)
{
    switch (a)
    {
    case 1:
        D_8033B2F8 = 1536;
        D_8033B300 = 0.04f;
        break;
    case 6:
        D_8033B2F8 = 768;
        D_8033B300 = 0.06f;
        break;
    case 4:
        D_8033B2F8 = 4096;
        D_8033B300 = 0.1f;
        break;
    case 2:
        D_8033B2F8 = 1536;
        D_8033B300 = 0.07f;
        break;
    case 3:
        D_8033B2F8 = 1536;
        D_8033B300 = 0.07f;
        break;
    case 5:
        D_8033B2F8 = 1024;
        D_8033B300 = 0.07f;
        break;
    default:
        D_8033B2F8 = 0;
        D_8033B300 = 0.f;
    }
}

extern s16 D_8033B2C0[][8];

void func_802883C8(Vec3f a, Vec3f b)
{
    int sp6C;
    Vec3f sp60;
    Vec3f sp30[4];
    float sp2C;
    s16 sp2A;
    s16 sp28;
    UNUSED u8 unused[8];

    if (D_8033B2F8 == 0)
    {
        vec3f_set(sp60, 0.f, 0.f, 0.f);
    }
    else
    {
        for (sp6C = 0; sp6C < 4; sp6C++)
        {
            sp30[sp6C][0] = D_8033B2C0[sp6C][0];
            sp30[sp6C][1] = D_8033B2C0[sp6C][1];
            sp30[sp6C][2] = D_8033B2C0[sp6C][2];
        }
        func_802878B8(D_8033B2FC, sp60, sp30[0], sp30[1], sp30[2], sp30[3]);
        if (1.f <= (D_8033B2FC += D_8033B300))
        {
            for (sp6C = 0; sp6C < 3; sp6C++)
                vec3s_copy(D_8033B2B8[sp6C].unk8, D_8033B2B8[sp6C + 1].unk8);
            func_80289618(D_8033B2B8[3].unk8, D_8033B2F8, D_8033B2F8, D_8033B2F8 / 2);
            D_8033B2FC -= 1.f;
            D_8033B300 = RandomFloat() * 0.5f;
            if (D_8033B300 < 0.02f)
                D_8033B300 = 0.02f;
        }
    }
    func_80288ECC(&D_8033B304, sp60[0], 8);
    func_80288ECC(&D_8033B306, sp60[1], 8);
    func_80288ECC(&D_8033B308, sp60[2], 8);
    if (D_8033B304 | D_8033B306)
    {
        vec3f_get_dist_and_angle(a, b, &sp2C, &sp2A, &sp28);
        sp2A += D_8033B304;
        sp28 += D_8033B306;
        vec3f_set_dist_and_angle(a, b, sp2C, sp2A, sp28);
    }
    D_8033B2F8 = 0;
    D_8033B300 = 0.f;
}

int func_802886FC(u16 a, u16 buttonsPressed, u16 buttonsDown)
{
    buttonsPressed &= CBUTTON_MASK;
    buttonsDown &= CBUTTON_MASK;

    if (buttonsPressed & L_CBUTTONS)
    {
        a |= 2;
        a &= ~1;
    }
    if (!(buttonsDown & L_CBUTTONS))
        a &= ~2;

    if (buttonsPressed & R_CBUTTONS)
    {
        a |= 1;
        a &= ~2;
    }
    if (!(buttonsDown & R_CBUTTONS))
        a &= ~1;

    if (buttonsPressed & U_CBUTTONS)
    {
        a |= 8;
        a &= ~4;
    }
    if (!(buttonsDown & U_CBUTTONS))
        a &= ~8;

    if (buttonsPressed & D_CBUTTONS)
    {
        a |= 4;
        a &= ~8;
    }
    if (!(buttonsDown & D_CBUTTONS))
        a &= ~4;

    return a;
}

int update_camera_status(struct Struct80280550 *a)
{
    s16 sp1E = 0;

    if (a->unk30 != 0 || ((gPlayer1Controller->buttonDown & R_TRIG) && func_8028803C(0) == 2))
        sp1E |= 4;
    else if (func_80288130(0) == 1)
        sp1E |= 1;
    else
        sp1E |= 2;
    if (D_8033B4D8 & 2)
        sp1E |= 8;
    if (D_8033B4D8 & 0x2000)
        sp1E |= 0x10;
    set_camera_status(sp1E);
    return sp1E;
}

int func_80288974(Vec3f pos, float offsetY, float radius)
{
    struct WallCollisionData collisionData;
    struct Surface *wall = NULL;
    float sp68;
    float sp64;
    float sp60;
    float sp5C;
    float sp58;
    float sp54;
    Vec3f sp24[4];
    int sp20;
    int sp1C = 0;

    collisionData.x = pos[0];
    collisionData.y = pos[1];
    collisionData.z = pos[2];
    collisionData.radius = radius;
    collisionData.offsetY = offsetY;
    sp1C = find_wall_collisions(&collisionData);
    if (sp1C != 0)
    {
        for (sp20 = 0; sp20 < collisionData.numWalls; sp20++)
        {
            wall = collisionData.walls[collisionData.numWalls - 1];
            vec3f_copy(sp24[sp20], pos);
            sp68 = wall->normal[0];
            sp64 = wall->normal[1];
            sp60 = wall->normal[2];
            sp5C = wall->originOffset;
            sp58 = sp68 * sp24[sp20][0] + sp64 * sp24[sp20][1] + sp60 * sp24[sp20][2] + sp5C;
            sp54 = ABS2(sp58);
            if (sp54 < radius)
            {
                sp24[sp20][0] += sp68 * (radius - sp58);
                sp24[sp20][2] += sp60 * (radius - sp58);
                vec3f_copy(pos, sp24[sp20]);
            }
        }
    }
    return sp1C;
}

static int func_80288BB0(Vec3f a, float b, float c, float d)
{
    int equal = FALSE;

    if (a[0] == b && a[1] == c && a[2] == d)
        equal = TRUE;
    return equal;
}

int func_80288C2C(Vec3f a, Vec3f b, s16 c, s16 d)
{
    int sp2C = 0;
    s16 sp2A;
    s16 sp28;
    float sp24;

    vec3f_get_dist_and_angle(a, b, &sp24, &sp2A, &sp28);
    if (sp2A > c)
    {
        sp2A = c;
        sp2C++;
    }
    if (sp2A < d)
    {
        sp2A = d;
        sp2C++;
    }
    vec3f_set_dist_and_angle(a, b, sp24, sp2A, sp28);
    return sp2C;
}

int func_80288CF0(float a, float b, float c)
{
    int sp24 = 0;
    Vec3f sp18;

    vec3f_set(sp18, a, b, c);
    if (func_8028A640(D_8032D000->unk4, sp18) < 100.f)
        sp24 = 1;
    return sp24;
}

int func_80288D74(float *a, float b, float c)
{
    if (D_8033B4DA & 1)
        func_80288E0C(a, b, c);
    else
        *a = b;
    if (*a == b)
        return 0;
    else
        return 1;
}

int func_80288E0C(float *a, float b, float c)
{
    if (c > 1.f)
        c = 1.f;
    *a = *a + (b - *a) * c;
    if (*a == b)
        return 0;
    else
        return 1;
}

float func_80288EA0(float a, float b, float c)
{
    a = a + (b - a) * c;
    return a;
}

int func_80288ECC(s16 *a, s16 b, s16 c)
{
    s16 sp6 = *a;

    if (c == 0)
    {
        *a = b;
    }
    else
    {
        sp6 -= b;
        sp6 -= sp6 / c;
        sp6 += b;
        *a = sp6;
    }
    if (*a == b)
        return 0;
    else
        return 1;
}

int func_80288F84(s16 a, s16 b, s16 c)
{
    s16 sp6 = a;

    if (c == 0)
    {
        a = b;
    }
    else
    {
        sp6 -= b;
        sp6 -= sp6 / c;
        sp6 += b;
        a = sp6;
    }
    return a;
}

void func_80289028(Vec3f a, Vec3f b, float c, float d, float e)
{
    func_80288E0C(&a[0], b[0], c);
    func_80288E0C(&a[1], b[1], d);
    func_80288E0C(&a[2], b[2], e);
}

void func_8028909C(Vec3f a, Vec3f b, float c, float d, float e)
{
    func_80288D74(&a[0], b[0], c);
    func_80288D74(&a[1], b[1], d);
    func_80288D74(&a[2], b[2], e);
}

void func_80289110(Vec3s a, Vec3s b, s16 c, s16 d, s16 e)
{
    func_80288ECC(&a[0], b[0], c);
    func_80288ECC(&a[1], b[1], d);
    func_80288ECC(&a[2], b[2], e);
}

int func_80289184(s16 *a, s16 b, s16 c)
{
    s16 sp6 = b - *a;

    if (c < 0)
        c = -1 * c;
    if (sp6 > 0)
    {
        sp6 -= c;
        if (sp6 >= 0)
            *a = b - sp6;
        else
            *a = b;
    }
    else
    {
        sp6 += c;
        if (sp6 <= 0)
            *a = b - sp6;
        else
            *a = b;
    }
    if (*a == b)
        return 0;
    else
        return 1;
}

int func_80289264(s16 a, s16 b, s16 c)
{
    s16 sp6 = b - a;

    if (c < 0)
        c = -1 * c;
    if (sp6 > 0)
    {
        sp6 -= c;
        if (sp6 >= 0)
            a = b - sp6;
        else
            a = b;
    }
    else
    {
        sp6 += c;
        if (sp6 <= 0)
            a = b - sp6;
        else
            a = b;
    }
    return a;
}

int func_80289354(s16 *a, s16 b, s16 c)
{
    if (D_8033B4DA & 1)
        func_80289184(a, b, c);
    else
        *a = b;
    if (*a == b)
        return 0;
    else
        return 1;
}

int func_802893E4(float *a, float b, float c)
{
    float sp10 = b - *a;

    if (c < 0)
        c = -1 * c;
    if (sp10 > 0)
    {
        sp10 -= c;
        if (sp10 > 0)
            *a = b - sp10;
        else
            *a = b;
    }
    else
    {
        sp10 += c;
        if (sp10 < 0)
            *a = b - sp10;
        else
            *a = b;
    }
    if (*a == b)
        return 0;
    else
        return 1;
}

float func_80289524(float a, float b, float c)
{
    float sp10 = b - a;

    if (c < 0)
        c = -1 * c;
    if (sp10 > 0)
    {
        sp10 -= c;
        if (sp10 > 0)
            a = b - sp10;
        else
            a = b;
    }
    else
    {
        sp10 += c;
        if (sp10 < 0)
            a = b - sp10;
        else
            a = b;
    }
    return a;
}

void func_80289618(Vec3s a, s16 b, s16 c, s16 d)
{
    float sp2C;
    UNUSED u8 unused[4];
    float sp24;
    float sp20;
    float sp1C;

    sp2C = RandomFloat();
    sp24 = b;
    a[0] = sp2C * sp24 - sp24 / 2.f;

    sp2C = RandomFloat();
    sp20 = c;
    a[1] = sp2C * sp20 - sp20 / 2.f;

    sp2C = RandomFloat();
    sp1C = d;
    a[2] = sp2C * sp1C - sp1C / 2.f;
}

int func_80289738(s16 a, float b, float c, float d, float e)
{
    Vec3f sp3C;
    float sp38;
    s16 sp36;
    s16 sp34;
    s16 sp32;
    s16 sp30;
    s16 sp2E = 0;
    float sp28 = D_8033B328.unk0[3][0] - c;
    float sp24 = D_8033B328.unk0[3][1] - d;
    float sp20 = D_8033B328.unk0[3][2] - e;

    sp38 = sqrtf(sp28 * sp28 + sp24 * sp24 + sp20 * sp20);
    if (b > sp38)
    {
        sp3C[0] = c;
        sp3C[1] = d;
        sp3C[2] = e;
        vec3f_get_dist_and_angle(D_8033B328.unk0[3], sp3C, &sp38, &sp36, &sp34);
        if (sp38 < b)
        {
            func_8028A578(D_8033B328.unk0[3], D_8033B328.unk0[2], &sp32, &sp30);
            sp36 -= sp32;
            sp34 -= sp30;
            sp38 -= 2000.f;
            if (sp38 < 0.f)
                sp38 = 0.f;
            b -= 2000.f;
            if (b < 2000.f)
                b = 2000.f;
            sp2E = a * (1.f - sp38 / b);
            if (sp36 < -0x1800 || sp36 > 0x400 || sp34 < -0x1800 || sp34 > 0x1800)
                sp2E /= 2;
        }
    }
    return sp2E;
}

int func_802899A0(Vec3f a, Vec3f b, float c, float d, float e, float f)
{
    s16 sp1E = D_8033B860->unk3A;

    if (a[0] >= c)
        a[0] = c;
    if (a[0] <= d)
        a[0] = d;
    if (a[2] >= e)
        a[2] = e;
    if (a[2] <= f)
        a[2] = f;
    sp1E = func_8028A4F0(b, a);
    return sp1E;
}

int func_80289A98(s16 a, s16 b)
{
    s16 sp2E;
    UNUSED u8 unused[34];
    UNUSED int sp8 = 0;
    UNUSED int sp4 = 0;

    sp2E = b - a + 0x4000;
    if (sp2E < 0)
        a = b;
    else
        a = b + 32768;
    return a;
}

int func_80289B0C(struct Surface *a, float b, float c, float d)
{
    Vec3s sp38;
    Vec3s sp30;
    Vec3s sp28;
    s16 sp26 = 0;
    s16 sp24 = 0;
    s16 sp22 = 0;
    float sp1C;
    float sp18;
    float sp14;
    UNUSED u8 unused[4];
    int spC;
    int sp8;
    int sp4 = 0;

    sp38[0] = a->vertex1[0];
    sp38[1] = a->vertex2[0];
    sp38[2] = a->vertex3[0];
    sp30[0] = a->vertex1[1];
    sp30[1] = a->vertex2[1];
    sp30[2] = a->vertex3[1];
    sp28[0] = a->vertex1[2];
    sp28[1] = a->vertex2[2];
    sp28[2] = a->vertex3[2];
    for (spC = 0; spC < 3; spC++)
    {
        sp8 = spC + 1;
        if (sp8 >= 3)
            sp8 = 0;
        sp1C = ABS(sp38[spC] - sp38[sp8]);
        if (sp1C > sp26)
            sp26 = sp1C;
        sp18 = ABS(sp30[spC] - sp30[sp8]);
        if (sp18 > sp24)
            sp24 = sp18;
        sp14 = ABS(sp28[spC] - sp28[sp8]);
        if (sp14 > sp22)
            sp22 = sp14;
    }
    if (c != -1.f)
    {
        if (sp24 < c)
            sp4 = 1;
    }
    if (b != -1.f && d != -1.f)
    {
        if (sp26 < b && sp22 < d)
            sp4 = 1;
    }
    return sp4;
}

int func_80289F04(Vec3f a, struct Surface *b)
{
    int sp1C = 0;
    float sp18 = (b->vertex2[1] - b->vertex1[1]) * (b->vertex3[2] - b->vertex2[2]) - (b->vertex3[1] - b->vertex2[1]) * (b->vertex2[2] - b->vertex1[2]);
    float sp14 = (b->vertex2[2] - b->vertex1[2]) * (b->vertex3[0] - b->vertex2[0]) - (b->vertex3[2] - b->vertex2[2]) * (b->vertex2[0] - b->vertex1[0]);
    float sp10 = (b->vertex2[0] - b->vertex1[0]) * (b->vertex3[1] - b->vertex2[1]) - (b->vertex3[0] - b->vertex2[0]) * (b->vertex2[1] - b->vertex1[1]);
    float spC = b->vertex1[0] - a[0];
    float sp8 = b->vertex1[1] - a[1];
    float sp4 = b->vertex1[2] - a[2];

    if (spC * sp18 + sp8 * sp14 + sp4 * sp10 < 0)
        sp1C = 1;
    return sp1C;
}

int func_8028A0D4(Vec3f a, Vec3f b, struct Surface *c, s16 d, s16 e)
{
    int sp54 = 1;
    int sp50 = 0;
    int sp4C = 0;
    UNUSED u8 unused[20];
    float sp34;
    s16 sp32;
    s16 sp30;
    Vec3f sp24;

    if (c != NULL)
    {
        if (e == -1 || c->type != e)
        {
            if (d == 0)
            {
                sp54 = func_80289F04(b, c);
            }
            else
            {
                vec3f_get_dist_and_angle(a, b, &sp34, &sp32, &sp30);
                vec3f_set_dist_and_angle(a, sp24, sp34, sp32, sp30 + d);
                sp50 = func_80289F04(sp24, c);
                vec3f_set_dist_and_angle(a, sp24, sp34, sp32, sp30 - d);
                sp4C = func_80289F04(sp24, c);
                sp54 = sp50 * sp4C;
            }
        }
    }
    return sp54;
}

int func_8028A204(UNUSED int a, struct Surface *b)
{
    int sp1C = func_80289F04(D_8032D000->unk4, b);

    return sp1C;
}

void func_8028A24C(Vec3f a, Vec3f b, Vec3f c, float d)
{
    Vec3f sp1C;

    sp1C[0] = (c[0] - b[0]) * d + b[0];
    sp1C[1] = (c[1] - b[1]) * d + b[1];
    sp1C[2] = (c[2] - b[2]) * d + b[2];
    vec3f_copy(a, sp1C);
}

int func_8028A300(Vec3f a, Vec3f b, Vec3f c, s16 d)
{
    int sp24 = 0;
    Vec3f sp18;

    sp18[0] = b[0] - a[0];
    sp18[1] = b[1] - a[1];
    sp18[2] = b[2] - a[2];
    func_8028A764(sp18, sp18, d);
    if (-c[0] < sp18[0] && sp18[0] < c[0]
     && -c[1] < sp18[1] && sp18[1] < c[1]
     && -c[2] < sp18[2] && sp18[2] < c[2])
        sp24 = 1;
    return sp24;
}

int func_8028A440(Vec3f a, Vec3f b)
{
    float sp34 = b[0] - a[0];
    float sp30 = b[1] - a[1];
    float sp2C = b[2] - a[2];
    s16 sp2A = atan2s(sqrtf(sp34 * sp34 + sp2C * sp2C), sp30);

    return sp2A;
}

s16 func_8028A4F0(Vec3f a, Vec3f b)
{
    float sp24 = b[0] - a[0];
    UNUSED float sp20 = b[1] - a[1];
    float sp1C = b[2] - a[2];
    s16 sp1A = atan2s(sp1C, sp24);

    return sp1A;
}

void func_8028A578(Vec3f a, Vec3f b, s16 *c, s16 *d)
{
    float sp2C = b[0] - a[0];
    float sp28 = b[1] - a[1];
    float sp24 = b[2] - a[2];

    *c = atan2s(sqrtf(sp2C * sp2C + sp24 * sp24), sp28);
    *d = atan2s(sp24, sp2C);
}

float func_8028A640(Vec3f a, Vec3f b)
{
    float sp24 = b[0] - a[0];
    float sp20 = b[1] - a[1];
    float sp1C = b[2] - a[2];
    float sp18 = sqrtf(sp24 * sp24 + sp20 * sp20 + sp1C * sp1C);

    return sp18;
}

float func_8028A6E4(Vec3f a, Vec3f b)
{
    float sp24 = b[0] - a[0];
    float sp20 = b[2] - a[2];
    float sp1C = sqrtf(sp24 * sp24 + sp20 * sp20);

    return sp1C;
}

void func_8028A764(Vec3f a, Vec3f b, u16 c)
{
    Vec3f sp1C;

    vec3f_copy(sp1C, b);
    a[0] = sp1C[2] * sins(c) + sp1C[0] * coss(c);
    a[1] = sp1C[1];
    a[2] = sp1C[2] * coss(c) - sp1C[0] * sins(c);
}

void func_8028A834(Vec3f a, Vec3f b, u16 c)
{
    Vec3f sp1C;

    vec3f_copy(sp1C, b);
    a[2] = -(sp1C[2] * coss(c) - sp1C[1] * sins(c));
    a[1] = sp1C[2] * sins(c) + sp1C[1] * coss(c);
    a[0] = sp1C[0];
}

void func_8028A908(s16 a, s16 b, s16 c)
{
    if (D_8033B328.unk52[0] < a)
    {
        D_8033B328.unk52[0] = a;
        D_8033B328.unk5C = b;
        D_8033B328.unk5A = c;
    }
}

void func_8028A964(s16 a, s16 b, s16 c)
{
    if (ABS(a) > ABS(D_8033B328.unk52[1]))
    {
        D_8033B328.unk52[1] = a;
        D_8033B328.unkA2 = b;
        D_8033B328.unkA0 = c;
    }
}

void func_8028AA24(s16 a, s16 b, s16 c)
{
    if (D_8033B328.unk52[2] < a)
    {
        D_8033B328.unk52[2] = a;
        D_8033B328.unk9C = b;
        D_8033B328.unk9A = c;
    }
}

void func_8028AA80(s16 a, s16 b, s16 c, float d, float e, float f, float g)
{
    Vec3f sp2C;
    float sp28;
    s16 sp26;
    s16 sp24;

    sp2C[0] = e;
    sp2C[1] = f;
    sp2C[2] = g;
    vec3f_get_dist_and_angle(D_8033B328.unk0[3], sp2C, &sp28, &sp26, &sp24);
    a = func_80289738(a, d, e, f, g);
    if (a != 0)
        func_8028A908(a, b, c);
}

void Unknown8028AB34(s16 a, s16 b, s16 c, float d, float e, float f, float g)
{
    Vec3f sp2C;
    float sp28;
    s16 sp26;
    s16 sp24;

    sp2C[0] = e;
    sp2C[1] = f;
    sp2C[2] = g;
    vec3f_get_dist_and_angle(D_8033B328.unk0[3], sp2C, &sp28, &sp26, &sp24);
    a = func_80289738(a, d, e, f, g);
    if (a != 0)
        func_8028A964(a, b, c);
}

void func_8028ABE8(s16 *a, s16 b)
{
    if (b == -32768)
        *a = (*a & 0x8000) + 49152;
    else
        *a += b;
}

void func_8028AC30(Vec3f a, Vec3f b)
{
    float sp24;
    s16 sp22;
    s16 sp20;

    if (D_8033B328.unk52[0] | D_8033B328.unk52[1])
    {
        vec3f_get_dist_and_angle(a, b, &sp24, &sp22, &sp20);
        sp22 += D_8033B328.unk52[0] * sins(D_8033B328.unk58);
        vec3f_set_dist_and_angle(a, b, sp24, sp22, sp20);
        func_8028ABE8(&D_8033B328.unk58, D_8033B328.unk5A);
        if (func_80289184(&D_8033B328.unk52[0], 0, D_8033B328.unk5C) == 0)
            D_8033B328.unk58 = 0;
    }
}

void func_8028AD44(Vec3f a, Vec3f b)
{
    float sp24;
    s16 sp22;
    s16 sp20;

    if (D_8033B328.unk52[1] != 0)
    {
        vec3f_get_dist_and_angle(a, b, &sp24, &sp22, &sp20);
        sp20 += D_8033B328.unk52[1] * sins(D_8033B328.unk9E);
        vec3f_set_dist_and_angle(a, b, sp24, sp22, sp20);
        func_8028ABE8(&D_8033B328.unk9E, D_8033B328.unkA0);
        if (func_80289184(&D_8033B328.unk52[1], 0, D_8033B328.unkA2) == 0)
            D_8033B328.unk9E = 0;
    }
}

void func_8028AE50(s16 *a)
{
    UNUSED u8 unused[8];

    if (D_8033B328.unk52[2] != 0)
    {
        func_8028ABE8(&D_8033B328.unk98, D_8033B328.unk9A);
        *a += D_8033B328.unk52[2] * sins(D_8033B328.unk98);
        if (func_80289184(&D_8033B328.unk52[2], 0, D_8033B328.unk9C) == 0)
            D_8033B328.unk98 = 0;
    }
}

int func_8028AF24(struct Struct80280550 *a, s16 b)
{
    s16 sp3E = 10922;
    s16 sp3C = D_8033B402;
    float sp38;
    Vec3f sp2C;
    s16 sp2A;

    switch (D_8032CFD8)
    {
    case 225:
        sp2C[0] = a->unk28;
        sp2C[1] = D_8032D000->unk4[1];
        sp2C[2] = a->unk2C;
        sp38 = func_8028A640(sp2C, D_8032D000->unk4);
        if (800.f > sp38)
            sp3E = 14336;
        break;
    case 130:
        sp3E = (b & 0xC000) - b + 0x2000;
        if (sp3E < 0)
            sp3E = -sp3E;
        sp3E = sp3E / 32 * 48;
        break;
    case 353:
        sp3E = 0;
        break;
    }
    sp2A = gMarioStates[0].forwardVel / 32.f * 128.f;
    if (D_8033B3EC < 0)
        func_80289184(&sp3C, -sp3E, sp2A);
    if (D_8033B3EC > 0)
        func_80289184(&sp3C, sp3E, sp2A);
    if (sp3C < -0x2AAA)
        func_80289184(&sp3C, -sp3E, 512);
    if (sp3C > 0x2AAA)
        func_80289184(&sp3C, sp3E, 512);
    return sp3C;
}

void func_8028B13C(void)
{
    func_80320AE8(0, 1053, 0);
}

void func_8028B16C(void)
{
    func_80320AE8(0, 3870, 0);
}

void func_8028B19C(void)
{
    if (gPlayer1Controller->buttonPressed & D_CBUTTONS)
        func_8028B304();
}

void func_8028B1DC(void)
{
    if (gPlayer1Controller->buttonPressed & CBUTTON_MASK)
        func_8028B304();
}

void func_8028B21C(void)
{
    if ((gPlayer1Controller->buttonPressed & L_CBUTTONS) || (gPlayer1Controller->buttonPressed & R_CBUTTONS))
        func_8028B304();
}

void func_8028B268(void)
{
    SetSound(0x70060081, D_803320E0);
}

void func_8028B29C(void)
{
    SetSound(0x70070081, D_803320E0);
}

void func_8028B2D0(void)
{
    SetSound(0x700F0081, D_803320E0);
}

void func_8028B304(void)
{
    SetSound(0x700E0081, D_803320E0);
}

void func_8028B338(void)
{
    SetSound(0x701A8081, D_803320E0);
}

void func_8028B36C(void)
{
    if (D_8033B31C & 2)
        func_8028B338();
    if (D_8033B31C & 4)
        func_8028B338();
    D_8033B31C &= ~6;
}

int func_8028B3DC(struct Struct80280550 *a, UNUSED float b)
{
    s16 sp1E;

    if ((D_8033B4D8 & 0x10) || !(D_8033B4D8 & 0xD))
    {
        if (gPlayer1Controller->buttonPressed & (L_CBUTTONS | R_CBUTTONS))
            D_8033B4D8 &= ~0x10;
        if (gPlayer1Controller->buttonPressed & R_CBUTTONS)
        {
            if (D_8033B402 > -0x800)
            {
                if (!(D_8033B4D8 & 4))
                    D_8033B4D8 |= 4;
                if (a->unk0 == 1)
                {
                    if (D_8033B402 > 0x22AA)
                        D_8033B318 |= 4;
                    if (D_8033B402 == 19114)
                        func_8028B304();
                    else
                        func_8028B2D0();
                }
                else
                {
                    if (D_8033B402 == 10922)
                        func_8028B304();
                    else
                        func_8028B2D0();
                }
            }
            else
            {
                D_8033B4D8 |= 1;
                func_8028B268();
            }
        }
        if (gPlayer1Controller->buttonPressed & L_CBUTTONS)
        {
            if (D_8033B402 < 0x800)
            {
                if (!(D_8033B4D8 & 8))
                    D_8033B4D8 |= 8;
                if (a->unk0 == 1)
                {
                    if (D_8033B402 < -0x22AA)
                        D_8033B318 |= 8;
                    if (D_8033B402 == -19114)
                        func_8028B304();
                    else
                        func_8028B2D0();
                }
                else
                {
                    if (D_8033B402 == -10922)
                        func_8028B304();
                    else
                        func_8028B2D0();
                }
            }
            else
            {
                D_8033B4D8 |= 1;
                func_8028B268();
            }
        }
    }
    if (gPlayer1Controller->buttonPressed & U_CBUTTONS)
    {
        if (D_8033B4D8 & 2)
        {
            D_8033B4D8 &= ~2;
            func_8028B268();
        }
        else
        {
            func_80284D44(a);
        }
    }
    if (gPlayer1Controller->buttonPressed & D_CBUTTONS)
    {
        if (D_8033B4D8 & 2)
        {
            D_8033B4D8 |= 0x1000;
#if VERSION_US
            func_8028B19C();
#endif
        }
        else
        {
            D_8033B4D8 |= 2;
            func_8028B29C();
        }
    }

    //! returning uninitialized variable
    return sp1E;
}

int StopMario(int a)
{
    int sp1C = 0;
    UNUSED struct Struct80280550 *sp18 = D_8033B860;

    if (a == 1)
        func_8028F834(171);
    if (a == 2) {}
    return sp1C;
}

void func_8028B7A4(struct Struct80280550 *a)
{
    s16 sp1E;

    if (gPlayer1Controller->buttonPressed & U_CBUTTONS)
    {
        if (a->unk0 != 13 && (D_8033B4D8 & 2))
        {
            D_8033B4D8 &= ~2;
            func_8028B268();
        }
        else
        {
            func_80284D44(a);
            if (D_8033B3FC > D_8032CFEC)
                D_8033B3F4 = -D_8032CFEC;
            else
                D_8033B3F4 = D_8032CFEC;
        }
    }
    if (a->unk0 != 13)
    {
        if (gPlayer1Controller->buttonPressed & D_CBUTTONS)
        {
            if (D_8033B4D8 & 2)
            {
                D_8033B4D8 |= 0x1000;
                D_8033B3F4 = D_8032CFEC + 400.f;
#if VERSION_US
                func_8028B19C();
#endif
            }
            else
            {
                D_8033B4D8 |= 2;
                D_8033B3F4 = D_8032CFEC + 400.f;
                func_8028B29C();
            }
        }
        sp1E = 4096;
        if (gPlayer1Controller->buttonPressed & R_CBUTTONS)
        {
            if (D_8033B4D8 & 8)
            {
                D_8033B4D8 &= ~8;
            }
            else
            {
                D_8033B4D8 |= 4;
                if (D_8033B3F8 == 0)
                    func_8028B2D0();
                D_8033B3F8 = -sp1E;
            }
        }
        if (gPlayer1Controller->buttonPressed & L_CBUTTONS)
        {
            if (D_8033B4D8 & 4)
            {
                D_8033B4D8 &= ~4;
            }
            else
            {
                D_8033B4D8 |= 8;
                if (D_8033B3F8 == 0)
                    func_8028B2D0();
                D_8033B3F8 = sp1E;
            }
        }
    }
}

void func_8028BA38(UNUSED struct Struct80280550 *a)
{
    int sp1C;

    for (sp1C = 0; sp1C < 10; sp1C++)
    {
        D_8033B6F0[sp1C].unk0 = 0;
        vec3f_set(D_8033B6F0[sp1C].unk4, 0.f, 0.f, 0.f);
        vec3f_set(D_8033B6F0[sp1C].unk10, 0.f, 0.f, 0.f);
        vec3s_set(D_8033B6F0[sp1C].unk1C, 0, 0, 0);
        D_8033B6F0[sp1C].unk22 = 0;
    }
}

void func_8028BB3C(struct Struct80280550 *a, u8 b)
{
    if (a->unk30 != b)
    {
        a->unk30 = b;
        func_8028BA38(a);
    }
}

extern u8 D_8032D0B8[];
extern u8 D_8032E8A4[][4];

int func_8028BB8C(UNUSED struct Struct80280550 *a)
{
    u8 sp7 = 0;
    u8 sp6 = 0;
    u8 sp5 = (D_8032CE24 - 1) / 2;
    u8 sp4 = gCurrCourseNum;

    if (sp5 >= 4)
        sp5 = 0;
    if (sp4 >= 26)
        sp4 = 0;
    sp6 = D_8032E8A4[sp4][sp5];
    if (D_8032CE24 & 1)
        sp6 &= 0xF;
    else
        sp6 = sp6 >> 4;
    sp7 = D_8032D0B8[sp6];
    return sp7;
}

u8 func_8028BC6C(u8 a, u8 b)
{
    u16 sp6;

    if (D_8032D000->unk0 == 4896)
        sp6 = a;
    if (D_8032D000->unk0 == 4897)
        sp6 = b;
    return sp6;
}

u8 func_8028BCC8(struct Struct80280550 *a)
{
    UNUSED u8 unused1[4];
    u8 sp33 = a->unk30;
    UNUSED u8 unused2[12];

    if (sp33 == 0)
    {
        sp33 = D_8032CFF0;
        D_8032CFF0 = 0;
        if (D_8032D000->unk1E == 6)
        {
            switch (D_8032CFD8)
            {
            case 97:
                if (a->unk0 == 17 || a->unk0 == 4 || a->unk64 == 2)
                    sp33 = func_8028BC6C(140, 141);
                else
                    sp33 = func_8028BC6C(130, 131);
                break;
            case 65:
                if (a->unk64 == 1)
                    sp33 = func_8028BC6C(130, 131);
                else
                    sp33 = func_8028BC6C(140, 141);
                break;
            default:
                sp33 = func_8028BC6C(130, 131);
                break;
            }
        }
        if (D_8032D000->unk1E == 5)
            sp33 = 139;
        if (D_8032D000->unk1E == 1)
            sp33 = 133;
        if (D_8033B278.unk8 >= 0xD3 && D_8033B278.unk8 < 0xFD)
            sp33 = 134;
        switch (D_8032D000->unk0)
        {
        case 6440:
            sp33 = 135;
            break;
        case 6438:
            sp33 = 160;
            break;
        case 6443:
            if (D_8032CFDC == 30 || D_8032CFDC == 33 || D_8032CFDC == 34)
                sp33 = 157;
            else
                sp33 = 169;
            break;
        case 6444:
            if (D_8032CFDC == 30 || D_8032CFDC == 33 || D_8032CFDC == 34)
                sp33 = 158;
            else
                sp33 = 170;
            break;
        case 4913:
            if (a->unk64 == 0)
                sp33 = 149;
            else
                sp33 = 140;
            break;
        case 4910:
            sp33 = 151;
            break;
        case 0x300032C7:
            sp33 = 159;
            break;
        case 0x21316:
            sp33 = 154;
            break;
        case 0x21315:
            sp33 = 153;
            break;
        case 0x21311:
            sp33 = 152;
            break;
        case 0x21314:
            sp33 = 156;
            break;
        case 0x21312:
            sp33 = 155;
            break;
        case 0x21313:
            sp33 = 152;
            break;
        case 4866:
            sp33 = func_8028BB8C(a);
            break;
        case 4867:
            sp33 = func_8028BB8C(a);
            break;
        case 4871:
            sp33 = 175;
            break;
        }
        switch (D_8032D000->unk1E)
        {
        case 9:
            sp33 = 142;
            break;
        case 10:
            sp33 = 174;
            break;
        case 11:
            sp33 = 172;
            break;
        case 12:
            sp33 = 177;
            break;
        case 13:
            sp33 = 178;
            break;
        }
    }
    a->unk64 = 0;
    return sp33;
}

void func_8028C1A0(float a, float b, float c)
{
    Vec3f sp24;
    struct MarioState *sp20 = &gMarioStates[0];
    struct Struct8033B418_sub *sp1C = &D_8033B418.unk8[0];
    struct Struct8033B418_sub *sp28 = &D_8033B418.unk8[1];

    D_8032CFD8 = gCurrLevelNum * 16 + gCurrentArea->index;
    sp24[0] = a;
    sp24[1] = b;
    sp24[2] = c;
    vec3f_add(D_8033B328.unk0[1], sp24);
    vec3f_add(D_8033B328.unk0[0], sp24);
    vec3f_add(D_8033B328.unk0[3], sp24);
    vec3f_add(D_8033B328.unk0[2], sp24);
    sp20->waterLevel += b;
    vec3f_add(sp1C->unk0, sp24);
    vec3f_add(sp1C->unkC, sp24);
    vec3f_add(sp28->unk0, sp24);
    vec3f_add(sp28->unkC, sp24);
}

void func_8028C2F0(struct Struct80280550 *a, float b, float c)
{
    if (D_8033B4DA & 1)
    {
        if (a->unk10[1] < b)
        {
            if ((a->unk10[1] += c) > b)
                a->unk10[1] = b;
        }
        else
        {
            if ((a->unk10[1] -= c) < b)
                a->unk10[1] = b;
        }
    }
    else
    {
        a->unk10[1] = b;
    }
}

void Unknown8028C3AC(UNUSED int a, UNUSED int b, UNUSED int c, UNUSED int d)
{
}

void func_8028C3CC(float a[] /*unknown type*/, float b, float c, float d, s16 e)
{
    u16 sp26;
    UNUSED u8 unused[2];
    float sp20;

    func_8027F668(&sp20, 1.f, 200.f, &sp20, 0.9f, 200.f);
    sp26 = D_8032D000->unk10[1] + e;
    a[3] = D_8032D000->unk4[2] + d * coss(sp26) - b * sins(sp26);
    a[1] = D_8032D000->unk4[0] + d * sins(sp26) + b * coss(sp26);
    a[2] = D_8032D000->unk4[1] + c + sp20;
}

void Unknown8028C508(float a[] /*unknown type*/, float b, float c, float d, s16 e)
{
    u16 sp6 = D_8032D000->unk10[1] + e;

    a[4] = D_8032D000->unk4[0] + d * sins(sp6) + b * coss(sp6);
    a[5] = D_8032D000->unk4[1] + c;
    a[6] = D_8032D000->unk4[2] + d * coss(sp6) - b * sins(sp6);
}

void func_8028C5F0(Vec3f a, Vec3f b, Vec3f c, Vec3s d)
{
    Vec3f sp24;
    Vec3f sp18;

    vec3f_copy(sp24, b);
    sp18[2] = -(c[2] * coss(d[0]) - c[1] * sins(d[0]));
    sp18[1] = c[2] * sins(d[0]) + c[1] * coss(d[0]);
    sp18[0] = c[0];
    a[0] = b[0] + sp18[2] * sins(d[1]) + sp18[0] * coss(d[1]);
    a[1] = b[1] + sp18[1];
    a[2] = b[2] + sp18[2] * coss(d[1]) - sp18[0] * sins(d[1]);
}

void func_8028C794(Vec3f a, Vec3f b, Vec3s c, float d, float e, float f)
{
    Vec3f sp1C;

    vec3f_set(sp1C, d, e, f);
    func_8028C5F0(a, b, sp1C, c);
}

void func_8028C7EC(s16 *a)
{
    if (D_8032D000->unk0 == 4896)
        *a = 0;
    else
        *a = -32768;
}

extern float D_8033B264[];

int func_8028C824(Vec3f a, Vec3f b, Vec3f c, Vec3f d, Vec3f e, Vec3f f, s16 g)
{
    s16 sp96;
    s16 sp94;
    float sp90;
    float sp8C;
    UNUSED u8 unused1[4];
    s16 sp86;
    s16 sp84;
    UNUSED u8 unused2[4];
    float sp7C = D_8033B260;
    s16 sp7A = D_8033B260;
    UNUSED s16 sp78 = 0;
    Vec3f sp6C;
    Vec3f sp60;
    Vec3f sp54;
    Vec3f sp48;
    int sp44;
    float sp40;
    struct Surface *sp3C;

    vec3f_copy(a, c);
    vec3f_copy(b, d);
    if (D_8033B4DA & 0x400)
    {
        for (sp44 = 0; sp44 < 3; sp44++)
        {
            sp54[sp44] = e[sp44] + D_8032D000->unk4[sp44] - D_8033B264[sp44];
            sp48[sp44] = f[sp44] + D_8032D000->unk4[sp44] - D_8033B264[sp44];
        }
        vec3f_get_dist_and_angle(d, sp48, &D_8033B250.unkC, &D_8033B250.unk8, &D_8033B250.unkA);
        vec3f_get_dist_and_angle(d, sp54, &D_8033B250.unk4, &D_8033B250.unk0, &D_8033B250.unk2);
        D_8033B4DA &= ~1024;
    }
    if (D_8033B260 > 0)
    {
        sp78 = 1;
        vec3f_get_dist_and_angle(d, c, &sp8C, &sp86, &sp84);
        sp90 = ABS(sp8C - D_8033B250.unk4) / sp7C;
        sp94 = ABS(sp86 - D_8033B250.unk0) / sp7A;
        sp96 = ABS(sp84 - D_8033B250.unk2) / sp7A;
        func_802893E4(&D_8033B250.unk4, sp8C, sp90);
        func_80289184(&D_8033B250.unk2, sp84, sp96);
        func_80289184(&D_8033B250.unk0, sp86, sp94);
        vec3f_set_dist_and_angle(d, sp6C, D_8033B250.unk4, D_8033B250.unk0, D_8033B250.unk2);
        vec3f_get_dist_and_angle(c, d, &sp8C, &sp86, &sp84);
        sp94 = D_8033B250.unk8 / (s16)D_8033B250.unk10;
        sp96 = D_8033B250.unkA / (s16)D_8033B250.unk10;
        sp90 = D_8033B250.unkC / D_8033B250.unk10;
        func_80289184(&D_8033B250.unk8, sp86, sp94);
        func_80289184(&D_8033B250.unkA, sp84, sp96);
        func_802893E4(&D_8033B250.unkC, 0, sp90);
        vec3f_set_dist_and_angle(d, sp60, D_8033B250.unkC, D_8033B250.unk8, D_8033B250.unkA);
        vec3f_copy(b, sp60);
        vec3f_copy(a, sp6C);
        if (D_8033B860->unk30 != 0 || !(D_8033B4D8 & 0x2000))
        {
            sp40 = find_floor(a[0], a[1], a[2], &sp3C);
            if (sp40 != -11000.f)
            {
                if ((sp40 += 125.f) > a[1])
                    a[1] = sp40;
            }
            resolve_wall_collisions(&a[0], &a[1], &a[2], 0.f, 100.f);
        }
        D_8033B260--;
        g = func_8028A4F0(b, a);
    }
    else
    {
        D_8033B250.unk4 = 0.f;
        D_8033B250.unk0 = 0;
        D_8033B250.unk2 = 0;
        D_8033B4DA &= ~2048;
    }
    vec3f_copy(D_8033B250.unk14, D_8032D000->unk4);
    return g;
}

void Unknown8028CE1C(void)
{
    D_8033B4DA &= ~3072;
    D_8033B260 = 0;
}

int func_8028CE4C(struct Struct80280550 *a, s16 b, s16 c, s16 d)
{
    int sp24 = 0;
    float sp20 = b;
    float sp1C = c;
    float sp18 = d;

    if (D_8032D00C[0] != sp20 || D_8032D00C[1] != sp1C || D_8032D00C[2] != sp18)
    {
        sp24 = 1;
        D_8033B4DA &= ~1;
    }
    vec3f_set(D_8032D00C, sp20, sp1C, sp18);
    if (a->unk0 != 13)
    {
        D_8033B4DA &= ~1;
        a->unk0 = 13;
        vec3f_set(a->unk10, D_8032D00C[0], D_8032D000->unk4[1], D_8032D00C[2]);
    }
    return sp24;
}

void func_8028CFAC(struct Struct80280550 *a)
{
    if (a->unk0 != 14)
    {
        a->unk0 = 14;
        D_8033B4DA &= ~1;
        D_8033B406 = 0;
        D_8033B408 = 0;
    }
}

void func_8028CFFC(struct Struct80280550 *a)
{
    if (a->unk0 != 11)
    {
        func_80285AD8(a, 11, 15);
        D_8033B402 = a->unk3A - 0x2000;
    }
}

void func_8028D058(u8 *a)
{
    if (*a != 4)
    {
        D_8033B4DA &= ~1;
        *a = 4;
    }
}

void func_8028D098(struct Struct80280550 *a, s16 b)
{
    Vec3f sp24;
    s16 sp22;

    sp24[0] = a->unk28;
    sp24[1] = D_8032D000->unk4[1];
    sp24[2] = a->unk2C;
    if (a->unk0 != 1)
    {
        sp22 = func_8028A4F0(sp24, D_8032D000->unk4) - func_8028A4F0(a->unk4, a->unk10) + 0x4000;
        if (sp22 > 0)
        {
            func_80285AD8(a, 1, b);
        }
        else
        {
            a->unk0 = 1;
            D_8033B4DA &= ~1;
        }
        D_8033B402 = 0;
    }
}

void func_8028D19C(struct Struct80280550 *a, struct Struct8033B470 *b)
{
    if (a->unk0 != 12)
    {
        D_8033B470 = b;
        D_8033B46C = 0;
        D_8033B478[0] = 0.f;
        D_8033B478[1] = 0.f;
        D_8033B478[2] = 0.f;
        a->unk10[0] = (D_8033B470[0].unk4[0] + D_8033B470[1].unk4[0]) / 2.f;
        a->unk10[1] = (D_8033B470[0].unk4[1] + D_8033B470[1].unk4[1]) / 2.f;
        a->unk10[2] = (D_8033B470[0].unk4[2] + D_8033B470[1].unk4[2]) / 2.f;
        D_8033B4DA &= ~1;
        a->unk0 = 12;
    }
}

void func_8028D288(UNUSED int a)
{
    switch (D_8032CFD8)
    {
    case 321:
        vec3f_set(D_8032D00C, 646.f, 143.f, -1513.f);
        break;
    case 97:
        vec3f_set(D_8032D00C, -577.f, 143.f, 1443.f);
        break;
    }
}

void func_8028D32C(u8 *a)
{
    if ((D_8032D000->unk0 & 0x4000) || *a == 3 || *a == 8)
        D_8033B4DA |= 0x1000;
    if (gCurrLevelNum == 23 || gCurrLevelNum == 11 || gCurrLevelNum == 28)
        D_8033B4DA &= ~4096;
    if ((*a == 3 && !(D_8032D000->unk0 & 0x6000)) || *a == 10)
        D_8033B4DA |= 0x1000;
}

void CameraRR00(struct Struct80280550 *a)
{
    func_8028CFAC(a);
    D_8033B406 = 16384;
}

void CameraRR04(struct Struct80280550 *a)
{
    func_8028CFAC(a);
    if (a->unk10[1] < D_803361D0)
    {
        a->unk10[1] = D_803361D4;
        D_8033B328.unk0[3][1] = a->unk10[1];
        D_8033B328.unk0[1][1] = a->unk10[1];
        D_8033B4DA &= ~1;
    }
}

void CameraRR02(struct Struct80280550 *a)
{
    if (a->unk0 != 13)
        func_8028CE4C(a, -2974, 478, -3975);
}

void CameraRR0305(struct Struct80280550 *a)
{
    if (a->unk0 != 13)
        func_8028CE4C(a, -2953, 798, -3943);
    if (a->unk10[1] > D_803361D8)
        a->unk10[1] = D_803361DC;
}

void CameraRR01(struct Struct80280550 *a)
{
    if (a->unk0 != 13)
    {
        D_8033B4DA &= ~1;
        a->unk0 = 13;
    }
}

void CameraMetal00(UNUSED struct Struct80280550 *a)
{
    D_8033B4D8 |= 0x40;
}

void CameraSL00(struct Struct80280550 *a)
{
    D_8033B4DA |= 0x1000;
    func_80285AD8(a, 14, 60);
    D_8033B406 = 7463;
}

void CameraSL01(struct Struct80280550 *a)
{
    func_80285AD8(a, 16, 60);
}

static void func_8028D6A4(struct Struct80280550 *a, f32 b)
{
    UNUSED f32 pad;
    if ((D_8033B278.unk4 < b - 100.f) && (D_8033B278.unk1C > D_8033B278.unk4))
    {
        a->unk10[1] = b - 400.f;
        D_8033B328.unk0[1][1] = b - 400.f;
        D_8033B328.unk0[3][1] = b - 400.f;
    }
}

void CameraHMC00(struct Struct80280550 *a)
{
    s16 sp26;
    s16 sp24;
    f32 sp20;
    if (a->unk10[1] > -102.f)
    {
        vec3f_get_dist_and_angle(a->unk4, D_8033B328.unk0[3], &sp20, &sp26, &sp24);
        vec3f_set_dist_and_angle(a->unk4, D_8033B328.unk0[3], 300.f, sp26, sp24);
        D_8033B328.unk0[3][1] = -800.f;
#ifdef VERSION_US
        a->unk10[1] = D_8033B328.unk0[3][1];
        D_8033B328.unk0[1][1] = D_8033B328.unk0[3][1];
#endif
        D_8033B4DA &= ~1;
    }
}

void CameraHMC02(struct Struct80280550 *a)
{
    func_8028D6A4(a, 1536.f);
}

void CameraHMC03(struct Struct80280550 *a)
{
    func_8028D6A4(a, 2355.f);
}

void CameraHMC04(struct Struct80280550 *a)
{
    func_8028D6A4(a, 1843.f);
}

void CameraHMC05(struct Struct80280550 *a)
{
    func_8028D6A4(a, 1843.f);
}

void CameraSSL00(UNUSED struct Struct80280550 *a)
{
    func_8028F834(164);
}

void CameraSSL0102(struct Struct80280550 *a)
{
    D_8033B4DA |= 0x1000;
    func_80285AD8(a, 4, 90);
}

void CameraSSL03(struct Struct80280550 *a)
{
    D_8033B4DA |= 0x1000;
    func_80285AD8(a, 2, 90);
}

void CameraTHI00(UNUSED struct Struct80280550 *a)
{
    if (D_8033B402 < 10922)
        D_8033B402 = 10922;
}

void CameraTHI01(UNUSED struct Struct80280550 *a)
{
    if (D_8033B402 > 15018)
        D_8033B402 = 15018;
}

void CameraRR07(struct Struct80280550 *a)
{
    D_8033B4DA |= 0x1000;
    func_80285AD8(a, 1, 90);
}

void CameraRR08(struct Struct80280550 *a)
{
    func_80285AD8(a, 16, 90);
}

void CameraHMC01(struct Struct80280550 *a)
{
    if ((D_8032D000->unk0 != 6444) && (D_8032D000->unk0 != 6443))
        func_8028BB3C(a, 181);
}

void CameraInside20(UNUSED struct Struct80280550 *a)
{
    vec3f_set(D_8033B460, D_803361E0 - D_8032D00C[0], 378.f - D_8032D00C[1], D_803361E4 - D_8032D00C[2]);
}

void CameraInside1E(struct Struct80280550 *a)
{
    struct Surface *sp1C;
    f32 sp18 = find_floor(a->unk10[0], a->unk10[1], a->unk10[2], &sp1C);
    
    if ((D_8033B278.unk4 > D_803361E8) && (sp18 < D_803361EC) && (D_8033B3F8 == 0))
        vec3f_set(a->unk10, -227.f, 1425.f, 1533.f);
}

void CameraInside1F(struct Struct80280550 *a)
{
    struct Surface *sp1C;
    f32 sp18 = find_floor(a->unk10[0], a->unk10[1], a->unk10[2], &sp1C);
    
    if ((sp18 > -110.f) && (D_8033B3F8 == 0))
        vec3f_set(a->unk10, -980.f, 249.f, -1398.f);
}

void CameraInside01(struct Struct80280550 *a)
{
    if (a->unk0 != 13)
    {
        D_8033B4DA &= ~1;
        func_8028D288(a->unk0);
        a->unk0 = 13;
    }
}

void CameraInside1213(struct Struct80280550 *a)
{
    func_80285AD8(a, 17, 20);
}

void CameraUnused(struct Struct80280550 *a)
{
    if (a->unk0 == 17)
        func_80285AD8(a, 4, 30);
    else
        func_8028D058(&a->unk0);
}

void CameraInside00(struct Struct80280550 *a)
{
    func_8028D058(&a->unk0);
}

void CameraInside0E(struct Struct80280550 *a)
{
    CameraInside00(a);
    a->unk64 = 2;
}

void CameraInside0F(struct Struct80280550 *a)
{
    CameraInside01(a);
}

void CameraBBH2B2C(struct Struct80280550 *a)
{
    func_8028D19C(a, &D_8032D0F0);
}

void CameraBBH24(struct Struct80280550 *a)
{
    func_8028D058(&a->unk0);
}

void CameraBBH2E2F(struct Struct80280550 *a)
{
    Vec3f sp1C;
    func_8028D058(&a->unk0);
    vec3f_set(sp1C, 0.f, 0.f, 300.f);
    func_8028C5F0(D_8033B328.unk0[3], D_8032D000->unk4, sp1C, D_8032D000->unk10);
    D_8033B328.unk0[3][1] = D_803361F0;
    vec3f_copy(a->unk10, D_8033B328.unk0[3]);
    D_8033B4DA &= ~1;
}

void CameraBBH020C(struct Struct80280550 *a)
{
    func_8028CE4C(a, 956, 440, 1994);
}

void CameraBBH01(struct Struct80280550 *a)
{
    a->unk64 = 1;
    CameraBBH020C(a);
}

void CameraBBH0D0F(struct Struct80280550 *a)
{
    func_8028CE4C(a, 2591, 400, 1284);
}

void CameraBBH1011(struct Struct80280550 *a)
{
    func_8028CE4C(a, 3529, 340, -1384);
}

void CameraBBH12(struct Struct80280550 *a)
{
    func_8028CE4C(a, -500, 740, -1306);
}

void CameraBBH1314(struct Struct80280550 *a)
{
    func_8028CE4C(a, -2172, 200, 675);
}

void CameraBBH15(struct Struct80280550 *a)
{
    if (func_8028CE4C(a, -2172, 200, 675) == 1)
        func_80285A8C(a, 20);
}

void CameraBBH16(struct Struct80280550 *a)
{
    if (func_8028CE4C(a, -1542, 320, -307) == 1)
        func_80285A8C(a, 20);
}

void CameraBBH17(struct Struct80280550 *a)
{
    a->unk64 = 1;
    func_8028CE4C(a, -1542, 320, -307);
}

void CameraBBH18(struct Struct80280550 *a)
{
    func_8028CE4C(a, -1893, 320, 2327);
}

void CameraBBH28(struct Struct80280550 *a)
{
    func_8028CE4C(a, 1371, 360, -1302);
}

void CameraBBH29(struct Struct80280550 *a)
{
    if (func_8028CE4C(a, 1371, 360, -1302) == 1)
        func_80285A8C(a, 20);
}

void CameraBBH2A(struct Struct80280550 *a)
{
    if (func_8028CE4C(a, 2115, 260, -772) == 1)
        func_80285A8C(a, 20);
}

void CameraBBH3033(struct Struct80280550 *a)
{
    a->unk64 = 1;
    func_8028D058(&a->unk0);
}

void CameraBBH34(struct Struct80280550 *a)
{
    func_8028D058(&a->unk0);
}

void CameraBBH38(struct Struct80280550 *a)
{
    if (a->unk0 == 13)
    {
        func_8028D058(&a->unk0);
        a->unk10[1] = D_803361F4;
        D_8033B328.unk0[3][1] = D_803361F8;
    }
}

void CameraBBH393A(struct Struct80280550 *a)
{
    a->unk64 = 1;
    func_8028CE4C(a, -2932, 296, 4429);
}

void CameraBBH00(struct Struct80280550 *a)
{
    func_8028D058(&a->unk0);
}

void CameraBBH1A1B(struct Struct80280550 *a)
{
    func_8028CE4C(a, 3493, 440, 617);
}

void CameraBBH1C(struct Struct80280550 *a)
{
    if (func_8028CE4C(a, 3493, 440, 617) == 1)
        func_80285A8C(a, 20);
}

void CameraBBH1E(struct Struct80280550 *a)
{
    func_8028CE4C(a, 3502, 440, 1217);
}

void CameraBBH1D(struct Struct80280550 *a)
{
    if (func_8028CE4C(a, 3502, 440, 1217) == 1)
        func_80285A8C(a, 20);
}

void CameraBBH1F20(struct Struct80280550 *a)
{
    func_8028CE4C(a, -670, 460, 372);
}

void CameraBBH21(struct Struct80280550 *a)
{
    if (func_8028CE4C(a, -670, 460, 372) == 1)
        func_80285A8C(a, 20);
}

void CameraBBH22(struct Struct80280550 *a)
{
    if (func_8028CE4C(a, 131, 380, -263) == 1)
        func_80285A8C(a, 20);
}

void CameraBBH23(struct Struct80280550 *a)
{
    func_8028CE4C(a, 210, 420, 3109);
}

void CameraBBH3536(struct Struct80280550 *a)
{
    a->unk64 = 1;
    func_8028CE4C(a, -204, 807, 204);
}

void CameraCCM00(UNUSED struct Struct80280550 *a)
{
    D_8033B4DA |= 0x10;
}

void CameraCCM01(UNUSED struct Struct80280550 *a)
{
    D_8033B4DA &= ~0x10;
}

u32 func_8028E634(struct Struct80280550 *a)
{
    u32 sp24 = 0;
    
    switch (D_8033B278.unk8)
    {
    case 11:
        func_80285AD8(a, 4, 90);
        sp24 += 1;
        break;
        
    case 102:
        func_80285AD8(a, 16, 90);
        sp24 += 1;
        break;
        
    case 121:
        func_80285AD8(a, 4, 90);
        sp24 += 1;
        break;
    }
    return sp24;
}

u32 func_8028E70C(struct Struct80280550 *a, u8 b)
{
    u32 sp1C = 0;
    sp1C = func_8028E634(a);
    
    if ((sp1C == 0) && (b != 0))
        func_80285AD8(a, b, 90);
    
    return sp1C;
}

void func_8028E774(struct Struct80280550 *a)
{
    switch (D_8033B278.unk8)
    {
    case 11:
        if (a->unk0 != 4)
            func_80285AD8(a, 16, 90);
        break;
        
    case 102:
        if (a->unk0 != 4)
            func_80285AD8(a, 16, 90);
        break;
        
    case 121:
        if (a->unk0 != 4)
            func_80285AD8(a, 16, 90);
        break;
        
    case 105:
        func_80285AD8(a, 14, 90);
        break;
        
    default:
        func_80285AD8(a, 1, 90);
    }
}

s16 func_8028E88C(struct Struct80280550 *a)
{
    s16 currLevelNum = gCurrLevelNum;
    s16 sp64;
    s8 sp63 = gCurrentArea->index;
    u32 sp5C;
    Vec3f sp50;
    Vec3f sp44;
    u32 sp40 = 0;
    UNUSED struct Struct8032CA78 filler;
    u8 sp27 = a->unk0;
    
    if (a->unk0 == 6)
        a->unk0 = (u8)D_8033B418.unk2;
    func_8028D32C(&a->unk0);
    if (currLevelNum > 40)
        currLevelNum = 40;
    
    if (TableLevelCinematicCamera[currLevelNum] != 0)
    {
        sp5C = 0;

        while ((TableLevelCinematicCamera[currLevelNum])[sp5C].unk4 != 0)
        {
            if ((TableLevelCinematicCamera[currLevelNum])[sp5C].unk0 == sp63)
            {
                vec3f_set(sp50, (TableLevelCinematicCamera[currLevelNum])[sp5C].unk8,
                                (TableLevelCinematicCamera[currLevelNum])[sp5C].unkA,
                                (TableLevelCinematicCamera[currLevelNum])[sp5C].unkC);
                vec3f_set(sp44, (TableLevelCinematicCamera[currLevelNum])[sp5C].unkE,
                                (TableLevelCinematicCamera[currLevelNum])[sp5C].unk10,
                                (TableLevelCinematicCamera[currLevelNum])[sp5C].unk12);

                if (func_8028A300(D_8032D000->unk4, sp50, sp44, (TableLevelCinematicCamera[currLevelNum])[sp5C].unk14) == 1)
                {
                    if ((D_8033B4DA & 0x1000) == 0)
                    {
                        ((TableLevelCinematicCamera[currLevelNum])[sp5C].unk4)(a);
                        sp40 = 1;
                    }
                }
            }
            
            if ((TableLevelCinematicCamera[currLevelNum])[sp5C].unk0 == -1)
            {
                if (sp40 == 0)
                {
                    if ((D_8033B4DA & 0x1000) == 0)
                        ((TableLevelCinematicCamera[currLevelNum])[sp5C].unk4)(a);
                }
            }
            
            sp5C += 1;
        }
    }
    
    if ((D_8033B4DA & 0x1000) == 0)
    {
        switch (D_8032CFD8)
        {
        case 385:
            if (D_8032D000->unk0 == 1192)
                func_80285AD8(a, 9, 60);
            
            else
            {
                switch (D_8033B278.unk8)
                {
                case 105:
                    func_80285AD8(a, 14, 90);
                    D_8033B406 = 0x4000;
                    break;
                    
                case 101:
                    if (D_8033A758 == 1)
                        func_8028CFFC(a);
                    else
                        func_8028D098(a, 60);
                    break;
                default:
                    func_8028D098(a, 60);
                }
            }
            break;
            
        case 65:
            if (func_80288BB0(D_8032D00C, 210.f, 420.f, 3109.f) == 1) // same position as CameraBBH23, but as floats
            {
                if (D_8032D000->unk4[1] < 1800.f)
                    func_80285AD8(a, 4, 30);
            }
            break;
            
        case 130:
            func_8028E70C(a, 2);
            break;
            
        case 129:
            func_8028E70C(a, 1);
            break;
            
        case 209:
            break;
            
        case 210:
            func_8028E774(a);
            break;
            
        case 225:
            func_8028E70C(a, 2);
            break;
            
        case 145:
            if (func_8028E70C(a, 0) == 0)
            {
                if (D_8033B278.unk8 == 101)
                    func_8028CFFC(a);
                else
                {
                    if (a->unk0 == 4)
                        func_80285AD8(a, 1, 60);
                    else
                        func_8028D098(a, 60);
                }
            }
            break;
            
        case 177:
            if (D_8033B278.unk8 == 27)
            {
                if (0) {}
                a->unk1 = 1;
                if (0) {}
            }
            break;
            
        case 178:
            if (D_8033B278.unk8 == 28)
            {
                if (0) {}
                a->unk1 = 4;
                if (0) {}
            }
            break;
            
        case 369:
            D_8033B365 = 2;
            break;
            
        case 370:
            if ((a->unk0 != 3) && (a->unk0 != 8))
            {
                if (((D_8032D000->unk0 & 0x00100000) != 0) || (D_8033B278.unk4 > 800.f))
                    func_80285AD8(a, 14, 60);
                
                else
                {
                    if (D_8032D000->unk4[1] < 800.f)
                        func_80285AD8(a, 16, 60);
                }
            }
            D_8033B365 = 16;
            break;
        }
    }
    
    D_8033B4DA &= ~0x1000;
    if (sp27 == 6)
    {
        D_8033B418.unk2 = a->unk0;
        a->unk0 = sp27;
    }
    sp64 = a->unk0;
    return sp64;
}

void func_8028F04C(Vec3f a, UNUSED Vec3f b)
{
    f32 ceilY;
    f32 floorY;
    struct Surface *sp24;
    resolve_wall_collisions(&a[0], &a[1], &a[2], 0.f, 100.f);
    floorY = find_floor(a[0], a[1] + 50.f, a[2], &sp24);
    ceilY =  find_ceil(a[0], a[1] - 50.f, a[2], &sp24);
    
    if ((D_803361FC != floorY) && (D_80336200 == ceilY))
    {
        if (a[1] < (floorY += 125.f))
            a[1] = floorY;
    }
    
    if ((D_80336204 == floorY) && (D_80336208 != ceilY))
    {
        if (a[1] > (ceilY -= 125.f))
            a[1] = ceilY;
    }
    
    if ((D_8033620C != floorY) && (D_80336210 != ceilY))
    {
        floorY += 125.f;
        ceilY -= 125.f;
        
        if ((a[1] <= floorY) && (a[1] < ceilY))
            a[1] = floorY;
        if ((a[1] > floorY) && (a[1] >= ceilY))
            a[1] = ceilY;
        if ((a[1] <= floorY) && (a[1] >= ceilY))
            a[1] = (floorY + ceilY) * 0.5f;
    }
}
    
s32 func_8028F2F0(struct Struct80280550 *a, Vec3f b, s16 *c, s16 d)
{
    UNUSED f32 sp84;
    struct WallCollisionData sp5C;
    struct Surface *sp58;
    UNUSED Vec3f sp4C;
    f32 sp48;
    f32 sp44;
    UNUSED f32 sp40;
    f32 sp3C;
    f32 sp38;
    s16 sp36;
    s16 sp34;
    UNUSED s16 sp32;
    s16 sp30;
    s16 sp2E;
    UNUSED s16 sp2C;
    s32 sp28 = 0;
    s32 sp24 = 0;
    UNUSED s32 sp20;
    
    vec3f_get_dist_and_angle(D_8032D000->unk4, b, &sp48, &sp30, &sp2E);
    D_8033B4DA &= ~0x20;
    sp5C.offsetY = 100.f;
    sp44 = 0.f;
    sp3C = 150.f;
    sp38 = 100.f;
    
    for (sp24 = 0; sp24 < 8; sp24++)
    {
        sp5C.x = D_8032D000->unk4[0] + ((b[0] - D_8032D000->unk4[0]) * sp44);
        sp5C.y = D_8032D000->unk4[1] + ((b[1] - D_8032D000->unk4[1]) * sp44);
        sp5C.z = D_8032D000->unk4[2] + ((b[2] - D_8032D000->unk4[2]) * sp44);
        sp5C.radius = sp3C;
        func_802893E4(&sp3C, 250.f, 30.f);
        
        if (find_wall_collisions(&sp5C) != 0)
        {
            sp58 = sp5C.walls[sp5C.numWalls - 1];
            if (sp24 >= 5)
            {
                D_8033B4DA |= 0x20;
                if (sp28 <= 0)
                {
                    sp28 = 1;
                    sp58 = sp5C.walls[sp5C.numWalls - 1];
                    sp36 = atan2s(sp58->normal[2], sp58->normal[0]) + 0x4000;
                    *c = func_80289A98(sp2E, sp36) + 0x8000;
                }
            }
            
            sp5C.x = D_8032D000->unk4[0] + ((b[0] - D_8032D000->unk4[0]) * sp44);
            sp5C.y = D_8032D000->unk4[1] + ((b[1] - D_8032D000->unk4[1]) * sp44);
            sp5C.z = D_8032D000->unk4[2] + ((b[2] - D_8032D000->unk4[2]) * sp44);
            sp5C.radius = sp38;
            func_802893E4(&sp38, 200.f, 20.f);
            
            if (find_wall_collisions(&sp5C) != 0)
            {
                sp58 = sp5C.walls[sp5C.numWalls - 1];
                sp34 = atan2s(sp58->normal[2], sp58->normal[0]);
                sp36 = sp34 + 0x4000;
                if ((func_8028A0D4(D_8032D000->unk4, b, sp58, d, 40) == 0)
                    && (func_8028A204((u32)a, sp58) == 1)
                    && (func_80289B0C(sp58, -1.f, 150.f, -1.f) == 0))
                {
                        *c = func_80289A98(sp2E, sp36) + 0x8000;
                        func_80289184(c, sp34, d);
                        sp28 = 3;
                        sp24 = 8;
                }
            }
        }
        sp44 += 0.125f;
    }
    return sp28;
}

void func_8028F678(struct Struct8033B278 *a)
{
    struct Surface *sp1C;
    s16 sp1A = D_8035FE10;
    D_8035FE10 = 1;
    
    if (find_floor(D_8032D000->unk4[0], D_8032D000->unk4[1] + 10.f, D_8032D000->unk4[2], &sp1C) != D_80336214)
        a->unk8 = sp1C->type;
    else
        a->unk8 = 0;
    
    if (find_ceil(D_8032D000->unk4[0], D_8032D000->unk4[1] - 10.f, D_8032D000->unk4[2], &sp1C) != D_80336218)
        a->unk10 = sp1C->type;
    else
        a->unk10 = 0;
    
    D_8035FE10 = 0;
    a->unk4 = find_floor(D_8032D000->unk4[0], D_8032D000->unk4[1] + 10.f, D_8032D000->unk4[2], &a->unk0);
    a->unk14 = find_ceil(D_8032D000->unk4[0], D_8032D000->unk4[1] - 10.f, D_8032D000->unk4[2], &a->unkC);
    a->unk30 = find_water_level(D_8032D000->unk4[0], D_8032D000->unk4[2]);
    D_8035FE10 = sp1A;
}

void func_8028F800(u8 a, struct Object *b)
{
    D_8032CFF0 = a;
    D_8032CFF4 = 0;
    D_8032CFC4 = b;
    D_8033B858 = 0;
}

u8 func_8028F834(u8 a)
{
    D_8032CFF0 = a;
    D_8032CFFC = 0;
    return 0;
}

static u8 unused_8028F860(u8 a)
{
    if ((D_8033B860->unk30 == 0) && (D_8032CFF0 == 0))
        D_8032CFF0 = a;
    
    if ((D_8033B860->unk30 == a) && (D_8032CFFC != 0))
        return D_8032CFFC;
    else
        return 0;
}

s16 func_8028F8E0(u8 a, struct Object *b, s16 c)
{
    s16 sp1E = 0;
    
    if ((D_8033B860->unk30 == 0) && (D_8032CFF0 == 0))
    {
        if (D_8032CFF4 != a)
        {
            func_8028F800(a, b);
            if (c != -1)
                D_8033B320 = c;
            else
                D_8033B320 = 1;
        }
        else
            sp1E = D_8032CFFC;
        
        D_8032CFF4 = 0;
    }
    return sp1E;
}

s16 func_8028F9A4(u8 a, struct Object *b)
{
    s16 sp1E = func_8028F8E0(a, b, -1);
    return sp1E;
}

s16 func_8028F9E8(u8 a, struct Object *b)
{
    s16 sp1E = 0;
    
    if ((D_8033B860->unk30 == 0) && (D_8032CFF0 == 0))
    {
        if (D_8032CFF4 != a)
        {
            func_8028F800(a, b);
            sp1E = 1;
        }
        else
        {
            sp1E = -1;
        }
    }
    return sp1E;
}

void func_8028FA74(struct Struct80280550 *a)
{
    a->unk3A = func_8028A4F0(a->unk4, a->unk10);
    a->unk2 = a->unk3A;
}

void func_8028FABC(void)
{
    D_8033B6E0 = 0;
    D_8033B6E4 = 0;
}

void func_8028FAE0(struct Struct80280550 *a)
{
    D_8033B6EC = 0x8000;
    a->unk30 = 0;
    vec3f_copy(a->unk4, D_8033B4B8.unkC);
    vec3f_copy(a->unk10, D_8033B4B8.unk0);
}

void func_8028FB44(s16 dummy)
{
    UNUSED s16 sp1E = dummy;
    save_file_do_save(gCurrSaveFileNum - 1);
}

void func_8028FB80(struct StructUnknown1 *a, s8 b, u8 c, Vec3s d)
{
    a->unk0 = b;
    a->unk1 = c;
    vec3s_copy(a->unk2, d);
}

void func_8028FBD8(struct StructUnknown1 a[], struct StructUnknown1 b[])
{
    s32 sp24 = 0;
    s32 sp20 = 0;
    UNUSED u32 filler[2];
    func_8028FB80(&a[sp20], b[sp24].unk0, b[sp24].unk1, b[sp24].unk2);
    sp20 += 1;
    
    do
    {
        do
        {
            func_8028FB80(&a[sp20], b[sp24].unk0, b[sp24].unk1, b[sp24].unk2);
            sp20 += 1;
            sp24 += 1;
        }
        while ((b[sp24].unk0 != -1) && (b[sp24].unk0 != -1)); //! what the fuck
    }
    while (sp24 > 16);
    
    func_8028FB80(&a[sp20], 0, b[sp24].unk1, b[sp24].unk2);
    func_8028FB80(&a[sp20 + 1], 0, 0, b[sp24].unk2);
    func_8028FB80(&a[sp20 + 2], 0, 0, b[sp24].unk2);
    func_8028FB80(&a[sp20 + 3], -1, 0, b[sp24].unk2);
}

s16 func_8028FD94(s32 a)
{
    s16 sp1E = D_8033B6EC;
    if (func_802573C8(a) == 2)
        sp1E = 0x7FFF;
    return sp1E;
}

static void unused_8028FDE8(UNUSED struct Struct80280550 *a)
{
    D_8033B6EC = func_8028FD94(3);
}

void Cutscene26Todo_0(UNUSED struct Struct80280550 *a)
{
    D_8033B6EC = func_8028FD94(1);
}

static void unused_8028FE50(UNUSED struct Struct80280550 *a)
{
    D_8033B6EC = func_8028FD94(2);
}

void CutsceneIntroPeach8028FE84(UNUSED struct Struct80280550 *a)
{
#ifdef VERSION_US
    func_8031FFB4(0, 60, 40);
#endif
    func_8028B13C();
}

void CutsceneIntroPeach8028FEB0(UNUSED struct Struct80280550 *a)
{
#ifdef VERSION_US
    func_80320040(0, 60);
#endif
    func_8028B16C();
}

void func_8028FEDC(UNUSED struct Struct80280550 *a)
{
    D_8033B40C = 0.f;
}

void func_8028FEFC(struct Struct80280550 *a, s16 b, s16 c, s16 d, s16 e)
{
    f32 sp2C;
    s16 sp2A;
    s16 sp28;
    s16 sp26;

    func_80288ECC(&D_8033B226, -(s16)(gPlayer2Controller->stickX * 250.f), 4);
    func_80288ECC(&D_8033B224, -(s16)(gPlayer2Controller->stickY * D_8033621C), 4);
    vec3f_get_dist_and_angle(a->unk10, a->unk4, &sp2C, &sp2A, &sp28);
    
    sp26 = 0x3800 - sp2A;
    if (sp26 < 0)
        sp26 = 0;
    if (c > sp26)
        c = sp26;
    
    sp26 = -0x3800 - sp2A;
    if (sp26 > 0)
        sp26 = 0;
    if (b < sp26)
        b = sp26;
    
    if (D_8033B224 > c)
        D_8033B224 = c;
    if (D_8033B224 < b)
        D_8033B224 = b;
    
    if (D_8033B226 > e)
        D_8033B226 = e;
    if (D_8033B226 < d)
        D_8033B226 = d;
    
    sp2A += D_8033B224;
    sp28 += D_8033B226;
    vec3f_set_dist_and_angle(a->unk10, D_8033B218, sp2C, sp2A, sp28);
    vec3f_sub(D_8033B218, a->unk4);
}

void func_80290144(struct Struct80280550 *a)
{
    vec3f_copy(D_8033B4B8.unk0, a->unk10);
    vec3f_copy(D_8033B4B8.unkC, a->unk4);
    D_8033B4D0 = D_8033B40C;
    D_8033B4D4 = D_8033B410;
}

void func_802901B4(struct Struct80280550 *a)
{
    vec3f_copy(a->unk10, D_8033B4B8.unk0);
    vec3f_copy(a->unk4, D_8033B4B8.unkC);
    D_8033B40C = D_8033B4D0;
    D_8033B410 = D_8033B4D4;
}

void func_80290224(struct Struct80280550 *a)
{
    func_8028FEDC(a);
    vec3f_copy(D_8033B4B8.unk0, a->unk10);
    D_8033B4B8.unkC[0] = D_8032D000->unk4[0];
    D_8033B4B8.unkC[1] = a->unk4[1];
    D_8033B4B8.unkC[2] = D_8032D000->unk4[2];
}

void func_802902A8(struct Struct80280550 *a)
{
    vec3f_copy(a->unk10, D_8033B4B8.unk0);
    vec3f_copy(a->unk4, D_8033B4B8.unkC);
}

static void unused_vec3s_to_vec3f(Vec3f dst, Vec3s src)
{
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

static void unused_vec3f_to_vec3s(Vec3s dst, Vec3f src)
{
    // note: unlike vec3f_to_vec3s(), this function doesn't round the numbers and instead simply truncates them
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

void func_80290390(struct Struct80280550 *a, s16 b, s16 c)
{
	UNUSED Vec3f sp2C;
	f32 sp28;
	s16 sp26;
	s16 sp24;
	UNUSED u32 sp20;
	
	vec3f_get_dist_and_angle(a->unk10, a->unk4, &sp28, &sp26, &sp24);
	sp26 += b;
	sp24 += c;
	vec3f_set_dist_and_angle(a->unk10, a->unk4, sp28, sp26, sp24);
}

void CutsceneEnterSomething8029041C(UNUSED struct Struct80280550 *a)
{
	func_8027F308(1);
	func_8029A494(1);
}

static void unused_80290450(UNUSED struct Struct80280550 *a)
{
	func_8027F308(2);
}

void func_8029047C(Vec3f a, Vec3f b, f32 c, s16 d, s16 e)
{
	f32 sp24;
	s16 sp22;
	s16 sp20;
	
	vec3f_get_dist_and_angle(b, a, &sp24, &sp22, &sp20);
	sp22 += d;
	sp20 += e;
	sp24 += c;
	vec3f_set_dist_and_angle(b, a, sp24, sp22, sp20);
}

void func_80290514(struct Struct80280550 *a)
{
	D_8033B4DA |= 0x8000;
	D_8033B2B0 = func_8028A4F0(a->unk4, a->unk10);
}

void func_80290564(UNUSED struct Struct80280550 *a)
{
	func_8031FFB4(0, 60, 40);
}

void func_80290598(UNUSED struct Struct80280550 *a)
{
	func_80320040(0, 60);
}

static void unused_802905C8(UNUSED struct Struct80280550 *a)
{
}

void Cutscene0FTodo_0(UNUSED struct Struct80280550 *a)
{
}

void Cutscene0FTodo_1(UNUSED struct Struct80280550 *a)
{
}

static void CutscenePeachEnd0_1(struct Struct80280550 *a)
{
	vec3f_set(a->unk4, -26.f, 0.f, -137.f);
	vec3f_set(a->unk10, 165.f, 4725.f, 324.f);
}

static void CutscenePeachEnd0_2(struct Struct80280550 *a)
{
	Vec3f sp24;
	vec3f_set(sp24, 0.f, 80.f, 0.f);
	
	sp24[2] = ABS(D_8032D000->unk4[1] - a->unk10[1]) * D_80336220;
	if (sp24[2] > -100.f)
		sp24[2] = -100.f;
	
	func_8028C5F0(a->unk4, D_8032D000->unk4, sp24, D_8032D000->unk10);
}

void CutscenePeachEnd0(struct Struct80280550 *a)
{
	func_80299BDC(CutscenePeachEnd0_1, a, 0, 0);
	func_80299BDC(CutscenePeachEnd0_2, a, 0, -1);
	func_8028FEFC(a, -0x2000, 0x2000, -0x2000, 0x2000);
}

void CutscenePeachEnd2(struct Struct80280550 *a)
{
	vec3f_set(a->unk4, 85.f, 826.f, 250.f);
	vec3f_set(a->unk10, -51.f, 988.f, -202.f);
	func_8028FEFC(a, -0x2000, 0x2000, -0x2000, 0x2000);
}

void CutscenePeachEnd367_1(UNUSED struct Struct80280550 *a) // static
{
	D_8033B6F0[9].unk4[0] = 0.f;
	func_8028FABC();
}

static void CutscenePeachEnd3_2(struct Struct80280550 *a)
{
	func_80287CFC(a->unk10, &D_8032E040, &D_8033B6E0, &D_8033B6E4);
	func_80287CFC(a->unk4, &D_8032E090, &D_8033B6E0, &D_8033B6E4);
}

void CutscenePeachEnd3(struct Struct80280550 *a)
{
	func_80299BDC(CutscenePeachEnd367_1, a, 0, 0);
	func_80299BDC(CutscenePeachEnd3_2, a, 0, -1);
	func_8028FEFC(a, -0x2000, 0x2000, -0x2000, 0x2000);
}

void CutscenePeachEnd1(struct Struct80280550 *a)
{
	vec3f_set(a->unk4, D_8032E090.unk2[0], D_8032E090.unk2[1] + 80.f, D_8032E090.unk2[2]);
	vec3f_set(a->unk10, D_8032E040.unk2[0], D_8032E040.unk2[1], D_8032E040.unk2[2] + 150.f);
	func_8028FEFC(a, -0x800, 0x2000, -0x2000, 0x2000);
}

static void CutscenePeachEnd4_1(struct Struct80280550 *a)
{
	vec3f_set(a->unk10, 179.f, 2463.f, -1216.f);
	a->unk10[1] = D_8032CFC4->oPosY + 35.f;
	vec3f_set(a->unk4, D_8032CFC4->oPosX, D_8032CFC4->oPosY + 125.f, D_8032CFC4->oPosZ);
}

void CutscenePeachEnd4(struct Struct80280550 *a)
{
	func_80299BDC(CutscenePeachEnd4_1, a, 0, 0);
	func_80288E0C(&a->unk10[1], D_8032CFC4->oPosY + 35.f, 0.02f);
	func_80288E0C(&a->unk4[1], D_8032CFC4->oPosY + 125.f, 0.15f);
	func_8028FEFC(a, -0x2000, 0x2000, -0x2000, 0x2000);
}

static void CutscenePeachEnd5_1(UNUSED struct Struct80280550 *a)
{
	func_8028FABC();
	D_8033B6F0[2].unk4[1] = 150.f;
}

static void CutscenePeachEnd5_2(struct Struct80280550 *a)
{
	func_80287CFC(a->unk10, &D_8032E0E8, &D_8033B6E0, &D_8033B6E4);
	a->unk10[1] += D_8032CFC4->oPosY + D_8033B6F0[3].unk4[1];
}

static void CutscenePeachEnd5_3(UNUSED struct Struct80280550 *a)
{
	func_802893E4(&(D_8033B6F0[2].unk4[1]), 90.f, 0.5f);
}

static void CutscenePeachEnd5_4(struct Struct80280550 *a)
{
	Vec3f sp1C;
	
	func_80287CFC(sp1C, &D_8032E0E8, &D_8033B6E0, &D_8033B6E4);
	a->unk10[0] = sp1C[0];
	a->unk10[2] = sp1C[2];
	func_80288E0C(&a->unk10[1], (sp1C[1] += D_8032CFC4->oPosY), 0.07f);
}

void CutscenePeachEnd5(struct Struct80280550 *a)
{
	func_80299BDC(CutscenePeachEnd5_1, a, 0, 0);
	func_80299BDC(CutscenePeachEnd5_2, a, 0, 299);
	func_80299BDC(CutscenePeachEnd5_4, a, 300, -1);
	func_80299BDC(CutscenePeachEnd5_3, a, 300, -1);
	vec3f_set(a->unk4, D_8032CFC4->oPosX, D_8033B6F0[2].unk4[1] + D_8032CFC4->oPosY, D_8032CFC4->oPosZ);
	func_8028FEFC(a, -0x2000, 0x2000, -0x2000, 0x2000);
}

void CutscenePeachEnd6(struct Struct80280550 *a)
{
	func_80299BDC(CutscenePeachEnd367_1, a, 0, 0);
	func_80287CFC(a->unk10, &D_8032E188, &D_8033B6E0, &D_8033B6E4);
	func_80287CFC(a->unk4, &D_8032E1D0, &D_8033B6E0, &D_8033B6E4);
	func_8028FEFC(a, -0x2000, 0x2000, -0x2000, 0x2000);
}

static void CutscenePeachEnd7_2(UNUSED struct Struct80280550 *a)
{
	func_80287CFC(a->unk4, &D_8032E218, &D_8033B6E0, &D_8033B6E4);
}

void CutscenePeachEnd7(struct Struct80280550 *a)
{
	func_80299BDC(CutscenePeachEnd367_1, a, 0, 0);
	func_80299BDC(CutscenePeachEnd7_2, a, 0, 0);
	func_80299BDC(CutscenePeachEnd7_2, a, 250, -1);
	func_80299C60(7, 300);
	func_80299C60(9, 340);
	vec3f_set(a->unk10, -163.f, 978.f, -1082.f);
	func_8028FEFC(a, -0x800, 0x2000, -0x2000, 0x2000);
}

void CutscenePeachEnd8(struct Struct80280550 *a)
{
	vec3f_set(a->unk4, 11.f, 983.f, -1273.f);
	vec3f_set(a->unk10, -473.f, 970.f, -1152.f);
	func_8028FEFC(a, -0x800, 0x2000, -0x2000, 0x2000);
}

static void CutscenePeachEnd9_1(struct Struct80280550 *a)
{
	func_8029A478(13);
	vec3f_set(a->unk4, 350.f, 1034.f, -1216.f);
	vec3f_set(a->unk10, -149.f, 1021.f, -1216.f);
}

static void CutscenePeachEnd9_2(struct Struct80280550 *a)
{
	Vec3f sp2C;
	Vec3f sp20;
	
	func_8029A478(2);
	vec3f_set(sp20, 233.f, 1068.f, -1298.f);
	vec3f_set(sp2C, -250.f, 966.f, -1111.f);
	func_80289028(a->unk10, sp2C, 0.2f, 0.1f, D_80336224);
	func_80289028(a->unk4, sp20, 0.2f, 0.1f, D_80336228);
}

void CutscenePeachEnd9(struct Struct80280550 *a)
{
	func_80299BDC(CutscenePeachEnd9_1, a, 0, 0);
	func_80299BDC(CutscenePeachEnd9_2, a, 155, -1);
	func_8028FEFC(a, -0x800, 0x2000, -0x2000, 0x2000);
}

void CutscenePeachEnd802911A4(struct Struct80280550 *a) // static
{
	func_80287CFC(a->unk4, &D_8032E258, &D_8033B6E0, &D_8033B6E4);
	vec3f_set(a->unk10, 699.f, 1680.f, -703.f);
}

void CutscenePeachEnd8029120C(UNUSED struct Struct80280550 *a) // static
{
	D_8033B234 = 37.f;
}

u8 unused8032D0A8[8] = {0x00, 0x0E, 0x00, 0x01, 0x00, 0x02, 0x00, 0x04};
