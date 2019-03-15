#include <ultra64.h>

#define INCLUDED_FROM_CAMERA_C

#include "sm64.h"
#include "camera.h"
#include "audio/interface_2.h"
#include "castle_message_behaviors.h"
#include "game.h"
#include "hud.h"
#include "math_util.h"
#include "area.h"
#include "surface_collision.h"
#include "behavior_script.h"
#include "level_update.h"
#include "ingame_menu.h"
#include "mario_actions_cutscene.h"
#include "save_file.h"
#include "room.h"
#include "object_helpers.h"
#include "object_helpers2.h"
#include "print.h"
#include "spawn_sound.h"
#include "behavior_actions.h"
#include "behavior_data.h"
#include "object_list_processor.h"

#define CBUTTON_MASK (U_CBUTTONS | D_CBUTTONS | L_CBUTTONS | R_CBUTTONS)

// BSS
struct Struct8033B1B0 D_8033B1B0[2];
Vec3f D_8033B1F8;
Vec3f D_8033B208;
Vec3f D_8033B218;
s16 D_8033B224;
s16 D_8033B226;
u8 D_8033B228;
struct Struct8033B230 D_8033B230;
struct Struct8033B250 D_8033B250;
struct Struct8033B278 D_8033B278;
s16 D_8033B2AC;
s16 D_8033B2AE;
s16 D_8033B2B0;
s16 D_8033B2B2;
s16 D_8033B2B4;
struct Struct8033B2B8 D_8033B2B8[4];
s16 D_8033B2F8;
f32 D_8033B2FC;
f32 D_8033B300;
s16 D_8033B304;
s16 D_8033B306;
s16 D_8033B308;
u32 D_8033B30C;
u32 D_8033B310;
s16 D_8033B314;
s16 D_8033B316;
s16 D_8033B318;
s16 D_8033B31A;
s16 D_8033B31C;
u16 D_8033B31E;
s16 D_8033B320;
struct Struct8033B328 D_8033B328;
s16 D_8033B3DC;
u32 D_8033B3E0;
s16 D_8033B3E4;
s16 D_8033B3E6;
s16 D_8033B3E8;
s16 D_8033B3EA;
s16 D_8033B3EC;
s16 D_8033B3EE;
s16 D_8033B3F0;
f32 D_8033B3F4;
s16 D_8033B3F8;
s16 D_8033B3FA;
f32 D_8033B3FC;
s16 D_8033B400;
s16 D_8033B402;
s16 D_8033B404;
s16 D_8033B406;
s16 D_8033B408;
f32 D_8033B40C;
f32 D_8033B410;
struct Struct8033B418 D_8033B418;
Vec3f D_8033B460;
u32 D_8033B46C;
struct Struct8033B470 *D_8033B470;
struct Struct8033B4B8 D_8033B478;
struct Struct8033B4B8 D_8033B498;
struct Struct8033B4B8 D_8033B4B8;
s16 D_8033B4D8;
s16 D_8033B4DA;
struct Struct8032E040 D_8033B4E0[32];
struct Struct8032E040 D_8033B5E0[32];
s16 D_8033B6E0;
f32 D_8033B6E4;
s16 D_8033B6E8;
s16 D_8033B6EA;
s16 gCutsceneTimer;
struct Struct8033B6F0 D_8033B6F0[10];
s32 D_8033B858;
u32 D_8033B85C;
struct LevelCamera *gCurrLevelCamera;

// first iteration of data
u32 D_8032CFC0 = 0; // unused
struct Object *D_8032CFC4 = NULL;
u32 D_8032CFC8 = 0;
u32 D_8032CFCC = 0;
struct Object *D_8032CFD0 = NULL;
s16 D_8032CFD4 = 1024;
s32 D_8032CFD8 = 0;
u32 D_8032CFDC = 0;
f32 D_8032CFE0 = 1000.0f; // unused
f32 D_8032CFE4 = 800.0f; // unused
u32 D_8032CFE8 = 0; // unused
f32 gCameraZoomDist = 800.0f;
u8 D_8032CFF0 = 0;
u8 D_8032CFF4 = 0;
u8 D_8032CFF8 = 0;
u8 D_8032CFFC = 0;
struct Struct8033B1B0 *D_8032D000 = &D_8033B1B0[0];
struct Struct8033B1B0 *D_8032D004 = &D_8033B1B0[1];
u32 D_8032D008 = 0; // unused
Vec3f D_8032D00C = {646.0f, 143.0f, -1513.0f};
Vec3f D_8032D00C_2 = {646.0f, 143.0f, -1513.0f}; // unused
Vec3f D_8032D00C_3 = {646.0f, 143.0f, -1513.0f}; // unused
Vec3f D_8032D00C_4 = {646.0f, 143.0f, -1513.0f}; // unused
Vec3f D_8032D00C_5 = {646.0f, 143.0f, -1513.0f}; // unused

s32 CameraChange01(struct LevelCamera *, Vec3f, Vec3f);
s32 CameraChange02(struct LevelCamera *, Vec3f, Vec3f);
s32 CameraChange03(struct LevelCamera *, Vec3f, Vec3f);
s32 CameraChange040710(struct LevelCamera *, Vec3f, Vec3f);
s32 CameraChange05(struct LevelCamera *, Vec3f, Vec3f);
s32 CameraChange06(struct LevelCamera *, Vec3f, Vec3f);
s32 CameraChange040710(struct LevelCamera *, Vec3f, Vec3f);
s32 CameraChange08(struct LevelCamera *, Vec3f, Vec3f);
s32 CameraChange090F(struct LevelCamera *, Vec3f, Vec3f);
s32 CameraChange0A(struct LevelCamera *, Vec3f, Vec3f);
s32 CameraChange0B(struct LevelCamera *, Vec3f, Vec3f);
s32 CameraChange0C(struct LevelCamera *, Vec3f, Vec3f);
s32 CameraChange0D(struct LevelCamera *, Vec3f, Vec3f);
s32 CameraChange0E(struct LevelCamera *, Vec3f, Vec3f);
s32 CameraChange090F(struct LevelCamera *, Vec3f, Vec3f);
s32 CameraChange040710(struct LevelCamera *, Vec3f, Vec3f);
s32 CameraChange11(struct LevelCamera *, Vec3f, Vec3f);

s32 (*TableCameraTransitions[])(struct LevelCamera *, Vec3f, Vec3f) = {
    NULL,
    CameraChange01,
    CameraChange02,
    CameraChange03,
    CameraChange040710,
    CameraChange05,
    CameraChange06,
    CameraChange040710,
    CameraChange08,
    CameraChange090F,
    CameraChange0A,
    CameraChange0B,
    CameraChange0C,
    CameraChange0D,
    CameraChange0E,
    CameraChange090F,
    CameraChange040710,
    CameraChange11
};

extern s32 gDialogueResponse;
extern f32 D_8033B3CC;
extern f32 D_8033B3D4;
extern s16 D_8033B3A2;
extern f32 D_80336074;
extern s16 D_8033B3A4;
extern s16 D_8033B3A6;

extern u32 D_8032CFDC;

extern f32 D_8033B3D8;
extern f32 D_8033B3D0;

extern f32 D_803365D0;
extern f32 D_803365D4;
extern f32 D_803365D8;
extern f32 D_803365DC;

void func_8027EFE0(s16 a)
{
    switch (a)
    {
    case 1:
        D_8033B328.unkA4 = 0;
        D_8033B328.unkAC = 0;
        break;
    case 9:
        func_8028A908(0x60, 0x3, 0x8000);
        func_8028AA24(0x60, 0x3, 0x8000);
        break;
    case 2:
        func_8028A908(0x60, 0xC, 0x8000);
        break;
    case 3:
        if (D_8032D000->unk0 & 0x6000)
        {
            func_8028A964(0x200, 0x10, 0x1000);
            func_8028AA24(0x400, 0x20, 0x1000);
            func_80299C98(0x100, 0x30, -0x8000);
        }
        else
        {
            func_8028A964(0x80, 0x8, 0x4000);
            func_8028AA24(0x80, 0x8, 0x4000);
            func_80299C98(0x100, 0x30, -0x8000);
        }
        D_8033B328.unkA4 = 0;
        D_8033B328.unkAC = 0;
        break;
    case 4:
        if (D_8032D000->unk0 & 0x6000)
        {
            func_8028A964(0x400, 0x20, 0x1000);
            func_8028AA24(0x600, 0x30, 0x1000);
            func_80299C98(0x180, 0x40, -0x8000);
        }
        else
        {
            func_8028A964(0x100, 0x10, 0x4000);
            func_8028AA24(0x100, 0x10, 0x4000);
            func_80299C98(0x180, 0x40, -0x8000);
        }
        D_8033B328.unkA4 = 0;
        D_8033B328.unkAC = 0;
        break;
    case 5:
        if (D_8032D000->unk0 & 0x6000)
        {
            func_8028A964(0x600, 0x30, 0x1000);
            func_8028AA24(0x800, 0x40, 0x1000);
            func_80299C98(0x200, 0x50, -0x8000);
        }
        else
        {
            func_8028A964(0x180, 0x20, 0x4000);
            func_8028AA24(0x200, 0x20, 0x4000);
            func_80299C98(0x200, 0x50, -0x8000);
        }
        D_8033B328.unkA4 = 0;
        D_8033B328.unkAC = 0;
        break;
    case 8:
        D_8033B328.unkA4 = 0.07;
        D_8033B328.unkAC = 0.07;
        break;
    case 10:
        func_8028A908(RandomFloat() * 64.f, 0x8, 0x8000);
        func_8028A964(RandomFloat() * 64.f, 0x8, 0x8000);
        break;
    }
}

void func_8027F308(s16 a)
{
    switch (a)
    {
    case 1:
        func_8028A908(0x60, 0x8, 0x4000);
        break;
    case 2:
        func_8028A908(0xC0, 0x8, 0x4000);
        break;
    case 3:
        func_8028A908(0x100, 0x8, 0x3000);
        break;
    case 6:
        func_8028AA24(0x80, 0x10, 0x3000);
        break;
    case 7:
        func_8028A908(0x20, 0x8, 0x8000);
        break;
    case 8:
        func_8028A908(0x40, 0x8, 0x8000);
        break;
    case 9:
        func_8028A908(0x20, 0x8, 0x8000);
        func_8028AA24(0x400, 0x10, 0x100);
        break;
    case 10:
        func_8028A908(64, 0x2, 0x8000);
        break;
    case 5:
        func_8028A964(-0x200, 0x80, 0x200);
        break;
    }
}

void func_8027F440(s16 a, f32 b, f32 c, f32 d)
{
    switch (a)
    {
    case 4:
        func_8028AA80(0x28, 0x8, 0x4000, 2000.f, b, c, d);
        break;
    case 1:
        func_8028AA80(0x80, 0x8, 0x4000, 4000.f, b, c, d);
        func_8029A514(1, b, c, d);
        break;
    case 2:
        func_8028AA80(0xC0, 0x8, 0x4000, 6000.f, b, c, d);
        func_8029A514(3, b, c, d);
        break;
    case 3:
        func_8028AA80(0x100, 0x8, 0x3000, 8000.f, b, c, d);
        func_8029A514(4, b, c, d);
        break;
    }
}

static void unused_8027F5C4(s16 a)
{
    switch (a)
    {
    case 1:
        func_8028A908(0x60, 0x8, 0x4000);
        break;
    case 2:
        func_8028A908(0xC0, 0x8, 0x4000);
        break;
    case 3:
        func_8028A908(0x100, 0x8, 0x3000);
        break;
    }
}

void func_8027F668(f32 *a, f32 b, f32 c, f32 *d, f32 e, f32 f)
{
    f32 sp24 = D_8033B278.unk4;
    f32 sp20;
    UNUSED s32 filler;

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

void func_8027F870(Vec3f a, Vec3f b, f32 c, f32 d, f32 e, s16 f, s16 g)
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

static void unused_8027F950(Vec3f a, Vec3f b, f32 c, f32 d, f32 e, s16 f, s16 g)
{
    Vec3f sp34;
    f32 sp30;
    f32 sp2C;
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

void func_8027FA48(struct LevelCamera *a, f32 b)
{
    struct Surface *sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    UNUSED u8 filler[8];
    UNUSED s16 sp2E = D_8032D000->unk0;
    f32 sp28 = 125.f;
    f32 sp24 = find_ceil(a->unk10[0], D_8033B328.unk0[3][1] - 50.f, a->unk10[2], &sp44);

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

s32 func_8027FDB8(u16 a)
{
    struct Surface *sp44;
    f32 sp40;
    s16 sp3E = 1456;
    f32 sp38 = D_8032D000->unk4[0] + sins(a) * 40.f;
    f32 sp34 = D_8032D000->unk4[2] + coss(a) * 40.f;

    sp40 = find_floor(sp38, D_8032D000->unk4[1], sp34, &sp44) - D_8032D000->unk4[1];

    if (sp44 != NULL)
    {
        if (sp44->type != 40 && sp40 > 0.f)
        {
            if (sp44->normal.z == 0.f && sp40 < 100.f)
                sp3E = 1456;
            else
                sp3E += atan2s(40.f, sp40);
        }
    }
    return sp3E;
}

void func_8027FF44(struct LevelCamera *a)
{
    f32 sp34;
    s16 sp32;
    s16 sp30;
    Vec3f sp24 = {0, 0, 0};

    vec3f_get_dist_and_angle(a->unk10, D_8032D000->unk4, &sp34, &sp32, &sp30);

    sp24[2] = sins(0xC00) * sp34;

    func_8028A764(sp24, sp24, D_8032D000->unk10[1]);
    sp30 = -sp30;
    func_8028A764(sp24, sp24, sp30);
    sp24[2] = 0.f;

    if (D_8032D000->unk0 == 0x03000888
     || (D_8032D000->unk0 != 0x100345 && (D_8032D000->unk0 & 0x100000)))
        sp24[0] = -sp24[0];
    if (D_8033B4DA & 0x40)
        approach_f32_exponential(&D_8033B40C, 0, 0.025f);
    else
        approach_f32_exponential(&D_8033B40C, sp24[0], 0.025f);
    sp24[0] = D_8033B40C;
    sp30 = -sp30;
    func_8028A764(sp24, sp24, sp30);
    vec3f_add(a->unk4, sp24);
}

s32 func_802800F4(Vec3f a, Vec3f b, s16 c)
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

s32 CameraChange01(struct LevelCamera *a, Vec3f b, Vec3f c)
{
    f32 sp4C = D_8032D000->unk4[0] - a->unk28;
    f32 sp48 = D_8032D000->unk4[2] - a->unk2C;
    s16 sp46 = atan2s(sp48, sp4C) + D_8033B402;
    s16 sp44 = func_8027FDB8(sp46);
    UNUSED s32 unused1;
    f32 sp3C;
    f32 sp38;
    UNUSED s32 unused2;
    UNUSED s32 unused3;
    f32 sp2C = 125.f;
    f32 sp28 = 1000.f;

    D_8033B3EA = sp46 - D_8033B402;
    func_8027F668(&sp3C, 1.f, 200.f, &sp38, 0.9f, 200.f);
    func_8027F870(b, c, sp3C + sp2C, sp38 + sp2C, D_8033B3EE + sp28, sp44, sp46);
    sp46 = func_802800F4(c, b, sp46);

    return sp46;
}

s32 CameraChange0E(struct LevelCamera *a, Vec3f b, Vec3f c)
{
    UNUSED f32 sp4C = D_8032D000->unk4[0] - a->unk28;
    UNUSED f32 sp48 = D_8032D000->unk4[2] - a->unk2C;
    s16 sp46 = D_8033B406 + D_8033B408;
    s16 sp44 = func_8027FDB8(sp46);
    f32 sp40;
    f32 sp3C;
    UNUSED s32 unused1;
    UNUSED s32 unused2;
    UNUSED s32 unused3;
    f32 sp2C = 125.f;
    f32 sp28 = 1000.f;

    D_8033B3EA = sp46;
    func_8027F668(&sp40, 1.f, 200.f, &sp3C, 0.9f, 200.f);
    func_8027F870(b, c, sp40 + sp2C, sp3C + sp2C, D_8033B3EE + sp28, sp44, sp46);
    func_8027FF44(a);
    if (D_8032CFD8 == 370)
        sp46 = func_802899A0(c, b, 6839.f, 995.f, 5994.f, -3945.f);

    return sp46;
}

void func_80280550(struct LevelCamera *a)
{
    s16 sp46 = 10922;
    s16 sp44 = -10922;
    s16 sp42 = 4096;
    s16 sp40;
    s32 sp3C;
    UNUSED s16 sp3A = 0;
    UNUSED s32 sp34 = 0;
    f32 sp30 = D_8032D000->unk4[0] - a->unk28;
    f32 sp2C = D_8032D000->unk4[2] - a->unk2C;
    UNUSED s32 filler;
    s16 sp26 = func_8028A4F0(D_8032D000->unk4, a->unk10) - atan2s(sp2C, sp30);

    if (sp26 > sp46)
        sp26 = sp46;
    if (sp26 < sp44)
        sp26 = sp44;

    if (!(D_8033B4D8 & 0xD))
    {
        if (D_8033B278.unk8 == SURFACE_006E && D_8033B278.unk20 != SURFACE_006E)
            D_8033B4D8 |= 0x11;
        if (D_8033B278.unk8 == SURFACE_006F && D_8033B278.unk20 != SURFACE_006F)
            D_8033B4D8 |= 0x14;
        if (D_8033B278.unk8 == SURFACE_0070 && D_8033B278.unk20 != SURFACE_0070)
            D_8033B4D8 |= 0x18;
    }

    if (D_8033B4D8 & 0x10)
        sp42 = 512;

    if (a->preset == CAMERA_PRESET_TICK_TOCK_CLOCK)
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
            approach_s16_exponential(&D_8033B402, sp40, 10);
        }
        else
        {
            if (a->preset == CAMERA_PRESET_OPEN_CAMERA)
            {
                sp42 = gMarioStates[0].forwardVel / 32.f * 128.f;
                func_80289184(&D_8033B402, sp26, sp42);
            }
            if (a->preset == CAMERA_PRESET_TICK_TOCK_CLOCK)
                D_8033B402 = func_8028AF24(a, atan2s(sp2C, sp30));
        }
    }

    if (D_8033B402 >= 0x5555)
        D_8033B402 = 21844;
    if (D_8033B402 < -0x5554)
        D_8033B402 = -21844;
}

void func_80280BD8(f32 a, s16 b)
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

    if (D_8032CFD8 == 130 && gCurrLevelCamera->preset == CAMERA_PRESET_TICK_TOCK_CLOCK)
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

void func_80280E0C(struct LevelCamera *a)
{
    func_8028B3DC(a, 0.f);
}

void func_80280E3C(UNUSED struct LevelCamera *a)
{
    f32 sp4 = 1000.f;

    D_8033B402 = D_8033B418.unk8.unk1E - D_8033B3EA;
    D_8033B3EE = D_8033B418.unk8.unk18 - sp4;
    D_8033B4D8 &= ~0x100;
}

void func_80280EBC(struct LevelCamera *a)
{
    Vec3f sp2C;
    UNUSED u8 unused1[8];
    s16 sp22 = D_8033B3EA;
    UNUSED u8 unused2[4];

    if (D_8033B4D8 & 0x100)
        func_80280E3C(a);
    func_80280E0C(a);
    func_80280550(a);
    if (a->preset == CAMERA_PRESET_OPEN_CAMERA)
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

void func_80280FD8(struct LevelCamera *a)
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

s32 CameraChange02(struct LevelCamera *a, Vec3f b, Vec3f c)
{
    f32 sp44 = D_8032D000->unk4[0] - a->unk28;
    f32 sp40 = D_8032D000->unk4[2] - a->unk2C;
    s16 sp3E = atan2s(sp40, sp44) + D_8033B402 + 32768;
    s16 sp3C = func_8027FDB8(sp3E);
    f32 sp38 = 1000.f;
    f32 sp34 = 125.f;
    f32 sp30;
    f32 sp2C;

    D_8033B3EA = sp3E - D_8033B402 - 32768;
    func_8027F668(&sp30, 1.f, 200.f, &sp2C, 0.9f, 200.f);
    func_8027F870(b, c, sp30 + sp34, sp2C + sp34, D_8033B3EE + sp38, sp3C, sp3E);

    return sp3E;
}

void func_8028124C(struct LevelCamera *a)
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

s32 CameraChange0C(struct LevelCamera *a, Vec3f b, Vec3f c)
{
    Vec3f spE8[2];
    Vec3f spDC;
    Vec3f spD0;
    Vec3f spC4;
    Vec3f spB8;
    s16 spB6;
    s16 spB4;
    UNUSED u8 filler[4];
    f32 spAC;
    f32 spA8;
    f32 spA4;
    UNUSED u8 filler2[8];
    f32 sp98;
    UNUSED u8 filler3[8];
    UNUSED f32 sp8C = 0.5f;
    f32 sp88 = 0.5f;
    f32 sp84;
    Vec3f sp78;
    UNUSED u8 filler4[12];
    UNUSED Vec3f sp60;
    Vec3s sp58;
    Vec3f sp4C;
    Vec3f sp40;
    Vec3f sp34;
    f32 sp30;
    f32 sp2C;
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
        D_8033B478.unk0[0] = sp4C[0] - a->unk10[0];
        D_8033B478.unk0[1] = sp4C[1] - a->unk10[1];
        D_8033B478.unk0[2] = sp4C[2] - a->unk10[2];
    }
    approach_f32_exponential(&D_8033B478.unk0[0], 0.f, 0.025f);
    approach_f32_exponential(&D_8033B478.unk0[1], 0.f, 0.025f);
    approach_f32_exponential(&D_8033B478.unk0[2], 0.f, 0.025f);
    vec3f_add(a->unk10, D_8033B478.unk0);

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

s32 CameraChange0D(struct LevelCamera *a, Vec3f b, UNUSED Vec3f c)
{
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    UNUSED u8 filler2[8];
    f32 sp58 = 0.5f;
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

    if (D_8033B278.unk8 != SURFACE_DEATH_PLANE && D_8033B278.unk4 != -11000.f)
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

s32 CameraChange0B(struct LevelCamera *a, Vec3f b, Vec3f c)
{
    struct Object *sp8C;
    UNUSED u8 filler2[12];
    f32 sp7C;
    UNUSED u8 filler3[4];
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    UNUSED u8 filler4[4];
    UNUSED s16 sp62;
    s16 sp60;
    s16 sp5E;
    struct Surface *sp58;
    UNUSED u8 filler[20];
    Vec3f sp38;
    Vec3f sp2C = {0.f, -150.f, -125.f};

    func_8028B7A4(a);

    if (D_8032D000->unk1C[1] == 7)
    {
        func_8027F308(3);
        D_8032D000->unk1C[1] = 0;
    }
    if (D_8032D000->unk1C[1] == 8)
    {
        func_8027F308(2);
        D_8032D000->unk1C[1] = 0;
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
        sp74 = sp58->normal.x;
        sp70 = sp58->normal.y;
        sp6C = sp58->normal.z;
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

    if (gCurrLevelNum == LEVEL_BBH)
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

// 2nd iteration of data
s16 D_8032D0A8[] = {14, 1, 2, 4};
s16 D_8032D0B0[] = {16, 9, 17, 0};
u8 D_8032D0B8[] = {0xA5, 0x8F, 0xA6, 0xA7, 0xAF, 0, 0, 0, 0, 1, 0, 0, 0xC5, 0x3D, 0x20, 0, 0x44, 0x64, 0, 0, 0xC5, 6, 0x40, 0, 0x44, 0x16, 0, 0, 0x3E, 0x99, 0x99, 0x9A, 0, 0, 0, 0, 0xC5, 0x92, 0x20, 0, 0x44, 0x65, 0x40, 0, 0xC5, 0x6D, 0xA0, 0, 0x44, 0x16, 0, 0, 0x3E, 0x99, 0x99, 0x9A};

struct Struct8033B470 D_8032D0F0[3] = {
    {1,{ -929.0f, 1619.0f, -1490.0f},50.0f,0.0f},
    {0,{-2118.0f, 1619.0f, -1490.0f},50.0f,0.0f},
    {0,{    0.0f,    0.0f,     0.0f}, 0.0f,0.0f},
};

s32 CameraChange05(UNUSED struct LevelCamera *a, UNUSED Vec3f b, UNUSED Vec3f c)
{
}

static void unused_80282678(UNUSED s32 unused)
{
}

void func_8028268C(struct LevelCamera *a)
{
    a->unk3A = CameraChange0B(a, a->unk4, a->unk10);
}

void func_802826CC(struct LevelCamera *a)
{
    s16 dummy;

    func_8028B3DC(a, 0.f);
    func_8029A478(2);
    a->unk3A = CameraChange0C(a, a->unk4, a->unk10);
    func_80289184(&dummy, 0, 1024);
}

void func_80282730(struct LevelCamera *a)
{
    UNUSED u8 unused[8];

    if (gCurrLevelNum == LEVEL_BBH)
        func_8029A478(7);
    else
        func_8029A478(4);
    a->unk3A = CameraChange0D(a, a->unk4, a->unk10);
    a->angle = a->unk3A;
    func_8027FF44(a);
    vec3f_set(D_8033B460, 0.f, 0.f, 0.f);
}

s32 CameraChange03(struct LevelCamera *a, Vec3f b, Vec3f c)
{
    UNUSED u8 unused2[12];
    f32 sp48;
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
    f32 sp24 = 800.f;
    f32 sp20 = 125.f;

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

    approach_s16_exponential(&sp3E, sp3A + sp38, sp36);
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

s32 func_80282D90(struct LevelCamera *a)
{
    struct MarioState *sp54 = &gMarioStates[0];
    struct Surface *sp50;
    Vec3f sp44;
    Vec3f sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    s16 sp2A;
    s16 sp28;
    s16 sp26;

    vec3f_copy(sp38, a->unk10);
    D_8033B4D8 &= ~0x100;
    vec3f_copy(sp44, a->unk10);
    sp26 = CameraChange03(a, a->unk4, sp44);
    a->unk10[0] = sp44[0];
    a->unk10[2] = sp44[2];
    if (a->preset == CAMERA_PRESET_UNDERWATER)
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

s32 func_80282FC8(struct LevelCamera *a)
{
    struct Surface *sp4C;
    f32 sp48;
    Vec3f sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
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
    if (D_8032D000->unk0 != 1192 && D_8033B278.unk8 == SURFACE_DEATH_PLANE)
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

void func_80283434(struct LevelCamera *a)
{
    a->unk3A = func_80282D90(a);
}

s32 CameraChange08(UNUSED struct LevelCamera *a, UNUSED Vec3f b, UNUSED Vec3f c)
{
}

void func_80283484(struct LevelCamera *a)
{
    a->unk3A = func_80282D90(a);
}

s32 CameraChange040710(UNUSED struct LevelCamera *a, Vec3f b, Vec3f c)
{
    s16 sp2E = D_8032D000->unk10[1] + D_8033B402 + 32768;

    func_8027F870(b, c, 125.f, 125.f, gCameraZoomDist, 1456, sp2E);
    return D_8032D000->unk10[1];
}
extern f32 D_80336070;

s32 func_80283548(struct LevelCamera *a)
{
    Vec3f spBC;
    Vec3f spB0;
    UNUSED u8 unused1[12];
    struct Surface *spA0;
    struct Surface *sp9C;
    struct Surface *sp98;
    struct Surface *sp94;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    UNUSED u8 unused2[4];
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    s16 sp72;
    s16 sp70;
    s16 sp6E;
    s16 sp6C = D_8032D000->unk10[1] + 32768;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    s16 sp5E;
    s16 sp5C;
    f32 sp58;
    UNUSED u8 unused4[4];
    s16 sp52;
    s16 sp50 = 0;
    f32 sp4C;
    s32 sp48 = 0;
    s32 sp44 = 0;
    f32 sp40 = find_ceil(D_8033B328.unk0[3][0], D_8033B328.unk0[3][1], D_8033B328.unk0[3][2], &sp94);
    s16 sp3E;

    func_8028B7A4(a);
    vec3f_get_dist_and_angle(D_8032D000->unk4, a->unk10, &sp80, &sp70, &sp6E);

    if (D_8033B4D8 & 2)
    {
        if (func_80288130(0) == 1)
            sp7C = gCameraZoomDist + 1050.f;
        else
            sp7C = gCameraZoomDist + 400.f;
    }
    else
    {
        sp7C = gCameraZoomDist;
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
        if (a->preset == CAMERA_PRESET_FREE_ROAM)
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
        a->angle = sp6E;

    func_8027F668(&sp68, 1.f, 200.f, &sp64, 0.9f, 200.f);
    vec3f_copy(spB0, a->unk10);
    sp48 = func_8028F2F0(a, spB0, &sp72, 1536);
    if (sp48 == 3)
    {
        D_8033B2AC = sp72;
        D_8033B2AE = sp6E;
        D_8033B4DA |= 0x200;
        vec3f_get_dist_and_angle(D_8032D000->unk4, spB0, &sp58, &sp5E, &sp5C);
        approach_s16_exponential(&sp6E, sp72, 10);
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
        approach_f32_exponential(&sp80, sp7C - 100.f, 0.05f);
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
    if (a->preset == CAMERA_PRESET_FREE_ROAM)
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
        if (D_8032CFD8 == 130 || gCurrLevelNum == LEVEL_CASTLE)
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
        if (a->preset == CAMERA_PRESET_FREE_ROAM)
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
    if (D_8033B278.unk8 != SURFACE_DEATH_PLANE)
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

void func_80284708(struct LevelCamera *a)
{
    func_8029A478(2);
    a->unk3A = func_80283548(a);
    func_8027FF44(a);
}

void camera_lakitu_zoom_distance(struct LevelCamera *a)
{
    gCameraZoomDist = 800.f;
    func_80284708(a);
}

void camera_mario_zoom_distance(struct LevelCamera *a)
{
    gCameraZoomDist = 350.f;
    func_80284708(a);
}

s32 CameraChange11(struct LevelCamera *a, Vec3f b, Vec3f c)
{
    UNUSED s16 unused1;
    s16 sp5C;
    s16 sp5A;
    s16 sp58;
    s16 sp56;
    s16 sp54;
    UNUSED s32 unused2;
    Vec3f sp44;
    Vec3f sp38;
    struct Surface *sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;

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

void func_80284AFC(struct LevelCamera *a)
{
    a->unk3A = CameraChange11(a, a->unk4, a->unk10);
}

s32 CameraChange090F(UNUSED struct LevelCamera *a, Vec3f b, Vec3f c)
{
    s16 sp2E = D_8032D000->unk10[1] + D_8033B402 + 32768;

    func_8027F870(b, c, 125.f, 125.f, 800.f, 5461, sp2E);
    return D_8032D000->unk10[1];
}

static void unused_80284BCC(struct LevelCamera *a)
{
    if (gPlayer1Controller->buttonPressed & U_CBUTTONS)
        D_8033B4D8 |= 0x2000;
    a->unk3A = func_80282FC8(a);
}

void func_80284C2C(struct LevelCamera *a)
{
    if (D_8033B278.unk8 == SURFACE_000B || D_8033B278.unk8 == SURFACE_0079)
    {
        camera_lakitu_zoom_distance(a);
    }
    else
    {
        if (gPlayer1Controller->buttonPressed & U_CBUTTONS)
            D_8033B4D8 |= 0x2000;
        a->unk3A = func_80282FC8(a);
    }
}

void func_80284CBC(struct LevelCamera *a)
{
    vec3f_copy(D_8033B498.unk0, a->unk10);
    vec3f_sub(D_8033B498.unk0, D_8032D000->unk4);
    vec3f_set(D_8033B498.unkC, 0.f, a->unk4[1] - D_8032D000->unk4[1], 0.f);
}

s32 func_80284D44(struct LevelCamera *a)
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

s32 func_80284DC0(struct LevelCamera *a)
{
    struct Surface *sp74;
    Vec3f sp68;
    Vec3f sp5C;
    s32 sp58 = 0;
    s32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    s16 sp42;
    s16 sp40;
    s16 sp3E = 0;
    Vec3f sp30;
    Vec3f sp24;

    if ((D_8033B4D8 & 0x2000) && !(D_8033B4D8 & 0x200))
    {
        vec3f_copy(sp30, D_8033B498.unk0);
        vec3f_add(sp30, D_8032D000->unk4);
        vec3f_copy(sp24, D_8033B498.unkC);
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
                    for (sp44 = sp48; sp44 < gCameraZoomDist; sp44 += 20.f)
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
                    if (sp44 >= gCameraZoomDist)
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
                vec3f_set_dist_and_angle(sp68, D_8033B498.unk0, gCameraZoomDist, 0, sp40 + sp3E);
                vec3f_copy(D_8033B498.unkC, sp68);
                vec3f_sub(D_8033B498.unk0, D_8032D000->unk4);
                vec3f_sub(D_8033B498.unkC, D_8032D000->unk4);
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

s32 CameraChange06(UNUSED struct LevelCamera *a, Vec3f b, Vec3f c)
{
    s16 sp2E = D_8033B400;
    s16 sp2C = D_8032D000->unk10[1] + D_8033B402 + 32768;

    func_8027F870(b, c, 125.f, 125.f, 250.f, sp2E, sp2C);
    return D_8032D000->unk10[1];
}

void func_802852F4(UNUSED struct LevelCamera *a)
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

    D_8032D000->unk16[0] = D_8033B400 * 3 / 4;
    D_8032D000->unk16[1] = D_8033B402 * 3 / 4;
}

void func_8028547C(struct LevelCamera *a)
{
    struct Struct8033B418_sub *sp2C = &D_8033B418.unk8;
    struct Struct8033B418_sub *sp28 = &D_8033B418.unk28;
    f32 sp24 = sp28->unk18 - sp2C->unk18;
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
    D_8032D000->unk16[0] = 0;
    D_8032D000->unk16[1] = 0;
    if (++D_8033B418.unk6 == D_8033B418.unk4)
        D_8033B4D8 &= ~0x100;
}

s32 func_80285770(struct LevelCamera *a)
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
            vec3f_copy(a->unk10, D_8033B498.unk0);
            vec3f_add(a->unk10, D_8032D000->unk4);
            vec3f_copy(a->unk4, D_8033B498.unkC);
            vec3f_add(a->unk4, D_8032D000->unk4);
            func_80289184(&D_8032D000->unk16[0], 0, 1024);
            func_80289184(&D_8032D000->unk16[1], 0, 1024);
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

s32 CameraChange0A(UNUSED struct LevelCamera *a, Vec3f b, Vec3f c)
{
    func_8027F870(c, b, 125.f + D_8033B410, 125.f, 800.f,
        D_8032D000->unk10[0], D_8032D000->unk10[1]);
    return D_8032D000->unk10[1];
}

void func_802859B0(struct LevelCamera *a)
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

void func_80285A8C(UNUSED struct LevelCamera *a, s16 b)
{
    if (!(D_8033B4DA & 4))
    {
        D_8033B4DA |= 0xC00;
        D_8033B250.unk10 = b;
    }
}

void func_80285AD8(struct LevelCamera *a, s16 b, s16 c)
{
    if (a->preset != b)
    {
        D_8033B418.unk0 = (b != -1) ? b : D_8033B418.unk2;
        D_8033B418.unk2 = a->preset;
        a->preset = D_8033B418.unk0;
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

void func_80285BD8(struct LevelCamera *a, s16 b, s16 c)
{
    struct Struct8033B418_sub *sp24 = &D_8033B418.unk8;
    struct Struct8033B418_sub *sp20 = &D_8033B418.unk28;

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
        D_8033B418.unk2 = a->preset;
        D_8033B418.unk4 = c;
        D_8033B418.unk6 = 1;
        a->preset = D_8033B418.unk0;
        D_8033B328.unk3C = a->preset;
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

void func_80285E70(struct LevelCamera *a)
{
    struct Surface *sp5C = NULL;
    Vec3f sp50;
    Vec3f sp44;
    UNUSED u8 unused1[12];
    f32 sp34;
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
        func_80289354(&a->angle, sp32, D_8032CFD4);
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
        D_8033B328.unk7C = a->angle;
        D_8033B328.unk7E = a->unk3A;
        vec3f_copy(D_8033B328.unk0[3], a->unk10);
        vec3f_copy(D_8033B328.unk0[2], a->unk4);
        func_8028909C(D_8033B328.unk0[1], sp50, D_8033B328.unkAC, D_8033B328.unkB0, D_8033B328.unkAC);
        func_8028909C(D_8033B328.unk0[0], sp44, D_8033B328.unkA4, D_8033B328.unkA8, D_8033B328.unkA4);
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
        D_8033B328.unk7A = 0;
        func_8028AC30(D_8033B328.unk8C, D_8033B328.unk80);
        func_8028AD44(D_8033B328.unk8C, D_8033B328.unk80);
        func_8028AE50(&D_8033B328.unk7A);
        func_802883C8(D_8033B328.unk8C, D_8033B328.unk80);
        if (D_8032D000->unk0 == 0x0188088A && D_8033B3E0 != 0x0188088A)
            func_8027EFE0(8);
        D_8033B328.unk7A += D_8033B308;
        D_8033B328.unk7A += D_8033B3DC;
        if (a->preset != CAMERA_PRESET_C_UP_LOOK && a->unk30 == 0)
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
    D_8033B328.unk3C = a->preset;
    D_8033B328.unk3D = a->unk1;
}

void func_80286348(struct LevelCamera *a)
{
    UNUSED u8 unused[24];

    gCurrLevelCamera = a;
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
    a->angle = D_8033B328.unk7C;
    a->unk3A = D_8033B328.unk7E;
    a->preset = D_8033B328.unk3C;
    a->unk1 = D_8033B328.unk3D;
    func_8028E88C(a);
    dummy_802877EC(a);
    D_8033B31E = func_802886FC(D_8033B31E, gPlayer1Controller->buttonPressed, gPlayer1Controller->buttonDown);
    if (a->unk30 != 0)
    {
        D_8032CFD4 = 0;
        handle_cutscenes(a);
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
            switch (a->preset)
            {
            case CAMERA_PRESET_SECRET_AQUARIUM:
                func_80283434(a);
                break;
            case CAMERA_PRESET_C_UP_LOOK:
                func_80285770(a);
                break;
            case CAMERA_PRESET_UNDERWATER:
                func_80283484(a);
                break;
            case CAMERA_PRESET_INSIDE_CANNON:
                func_802859B0(a);
                break;
            default:
                camera_mario_zoom_distance(a);
            }
        }
        else
        {
            switch (a->preset - 1)
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
                camera_lakitu_zoom_distance(a);
                break;
            case 15:
                camera_lakitu_zoom_distance(a);
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
    if (gCurrLevelNum != LEVEL_CASTLE)
    {
        if ((a->unk30 == 0 && (gPlayer1Controller->buttonDown & R_TRIG) && func_8028803C(0) == 2)
         || (D_8033B4D8 & 0x40) || (D_8032D000->unk0) == 0x010208B8)
        {
            if (a->unk30 == 0 && (gPlayer1Controller->buttonPressed & R_TRIG) && func_8028803C(0) == 2)
            {
                D_8033B31C |= 0x20;
                func_8028B338();
            }
            D_8033B328.unkAC = 0.f;
            D_8033B328.unkB0 = 0.f;
            a->unk3A = func_8028A4F0(D_8033B328.unk80, D_8033B328.unk8C);
            a->angle = a->unk3A;
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

void func_802869B8(struct LevelCamera *a)
{
    UNUSED s32 sp34 = 0;
    UNUSED u8 unused[16];
    UNUSED struct Struct8033B418_sub *sp20 = &D_8033B418.unk8;
    UNUSED struct Struct8033B418_sub *sp1C = &D_8033B418.unk28;

    gCurrLevelCamera = a;
    D_8033B4D8 = 0;
    D_8033B318 = 0;
    D_8033B4DA = 0;
    gCutsceneTimer = 0;
    D_8033B6EA = 0;
    D_8033B85C = 0;
    D_8033B858 = FALSE;
    D_8032CFC4 = NULL;
    D_8032CFC8 = 0;
    D_8032CFCC = 0;
    D_8032CFD0 = NULL;
    D_8033B31E = 0;
    vec3f_copy(D_8033B250.unk14, D_8032D000->unk4);
    D_8033B250.unk10 = 0;
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
    D_8032D000->unk16[0] = 0;
    D_8032D000->unk16[1] = 0;
    D_8032D004->unk16[0] = 0;
    D_8032D004->unk16[1] = 0;
    D_8032D000->unk1C[1] = 0;
    D_8032D000->unk20 = NULL;
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
    D_8033B230.fieldOfView = 45.f;
    D_8033B230.unk8 = 0.f;
    D_8033B230.unkC = 0;
    D_8033B230.unk10 = 0.f;
    D_8033B230.unk14 = 0;
    D_8032CFF0 = 0;
    D_8032CFF4 = 0;
    D_8033B30C = 0;
    D_8033B310 = 0;
}

void func_80286C9C(struct LevelCamera *a)
{
    struct Surface *sp34 = 0;
    Vec3f sp28;
    s32 sp24;

    D_8033B224 = 0;
    D_8033B226 = 0;
    D_8032CFDC = D_8032CFD8 / 16;
    D_8032CFD8 = gCurrLevelNum * 16 + gCurrentArea->index;
    D_8033B314 &= 4;
    D_8033B228 = 0;
    D_8033B328.unk3C = a->preset;
    D_8033B328.unk3D = a->unk1;
    D_8033B328.unkAC = 0.3f;
    D_8033B328.unkB0 = 0.3f;
    D_8033B328.unkA4 = 0.8f;
    D_8033B328.unkA4 = 0.3f;
    D_8033B328.unk7A = 0;
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
        D_8033B4E0[sp24].unk0 = -1;
        D_8033B5E0[sp24].unk0 = -1;
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
    case 24:  //LEVEL_BOWSER_1
#if VERSION_US
        if (gCurrDemoInput == NULL)
            func_8028BB3C(a, 144);
        else if (D_8032CFD0 != NULL)
            D_8032CFD0->OBJECT_FIELD_U32(0x00) = 2;
#else
        func_8028BB3C(a, 144);
#endif
        break;
    case 27:  //LEVEL_BOWSER_2
        func_8028BB3C(a, 144);
        break;
    case 28:  //LEVEL_BOWSER_3
        func_8028BB3C(a, 144);
        break;
    case 10:  //LEVEL_CASTLE_GROUNDS
        if (func_80288CF0(-1328.f, 260.f, 4664.f) != 1)
        {
            sp28[0] = -400.f;
            sp28[2] = -800.f;
        }
        if (func_80288CF0(-6901.f, 2376.f, -6509.f) == 1)
            func_8028BB3C(a, 179);
        if (func_80288CF0(5408.f, 4500.f, 3637.f) == 1)
            func_8028BB3C(a, 180);
        D_8033B328.unk3C = 16;
        break;
    case 14:  //LEVEL_SA
        sp28[2] = 200.f;
        break;
    case 20:  //LEVEL_CASTLE_COURTYARD
        sp28[2] = -300.f;
        break;
    case 16:  //LEVEL_LLL
        D_8033B4D8 |= 2;
        break;
    case 0:  //LEVEL_CASTLE
        sp28[2] = 150.f;
        break;
    case 9:  //LEVEL_RR
        vec3f_set(D_8032D00C, -2985.f, 478.f, -5568.f);
        break;
    }
    if (a->preset == CAMERA_PRESET_BOWSER_LEVEL)
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
        D_8033B328.unk3C = 1;
        break;
    }
    func_8028C5F0(a->unk10, D_8032D000->unk4, sp28, D_8032D000->unk10);
    if (a->preset != CAMERA_PRESET_SECRET_AQUARIUM)
        a->unk10[1] = find_floor(D_8032D000->unk4[0], D_8032D000->unk4[1] + 100.f, D_8032D000->unk4[2], &sp34) + 125.f;
    vec3f_copy(a->unk4, D_8032D000->unk4);
    vec3f_copy(D_8033B328.unk0[1], a->unk10);
    vec3f_copy(D_8033B328.unk0[0], a->unk4);
    vec3f_copy(D_8033B328.unk0[3], a->unk10);
    vec3f_copy(D_8033B328.unk0[2], a->unk4);
    vec3f_copy(D_8033B328.unk8C, a->unk10);
    vec3f_copy(D_8033B328.unk80, a->unk4);
    if (a->preset == CAMERA_PRESET_FIXED_REF_POINT)
        func_8028D288(a->preset);
    func_80284CBC(a);
    D_8033B328.unk7C = func_8028A4F0(a->unk4, a->unk10);
    D_8033B328.unk7E = D_8033B328.unk7C;
    a->angle = D_8033B328.unk7C;
    a->unk3A = D_8033B328.unk7C;
}

extern u8 D_8032E910[20];

void func_80287404(struct Struct80287404 *a)
{
    UNUSED u8 unused1[8];
    f32 sp34;
    s16 sp32;
    s16 sp30;
    UNUSED u8 unused2[4];
    s32 sp28 = D_8032CFD8 / 32;
    s32 sp24 = 1 << (((D_8032CFD8 & 0x10) / 4) + (((D_8032CFD8 & 0xF) - 1) & 3));

    if (sp28 >= ARRAY_COUNT(D_8032E910) - 1)
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
                a->unk28[0] = gCurrLevelCamera->unk28;
                a->unk28[1] = (D_8032D000->unk4[1] + gCurrLevelCamera->unk68) / 2.f;
                a->unk28[2] = gCurrLevelCamera->unk2C;
                vec3f_get_dist_and_angle(a->unk28, D_8032D000->unk4, &sp34, &sp32, &sp30);
                vec3f_set_dist_and_angle(D_8032D000->unk4, a->unk1C, 6000.f, 4096, sp30);
                if (gCurrLevelNum != LEVEL_THI)
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

void func_802875F8(struct Struct80287404 *a, struct AllocOnlyPool *b)
{
    s16 sp1E = a->unk18;
    struct LevelCamera *sp18 = alloc_only_pool_alloc(b, 108);

    a->unk18 = (s32)sp18;
    sp18->preset = sp1E;
    sp18->unk1 = sp1E;
    sp18->unk30 = 0;
    sp18->unk64 = 0;
    sp18->unk28 = a->unk28[0];
    sp18->unk68 = a->unk28[1];
    sp18->unk2C = a->unk28[2];
    sp18->angle = 0;
    vec3f_copy(sp18->unk10, a->unk1C);
    vec3f_copy(sp18->unk4, a->unk28);
}

void func_802876D0(struct Struct80287404 *a)
{
    UNUSED u8 unused[8];
    UNUSED s32 sp1C = a->unk18;

    a->unk3A = D_8033B328.unk7A;
    vec3f_copy(a->unk1C, D_8033B328.unk8C);
    vec3f_copy(a->unk28, D_8033B328.unk80);
    func_80287404(a);
}

s32 Geo0F_80287D30(s32 a, struct Struct80287404 *b, struct AllocOnlyPool *c)
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

void dummy_802877D8(UNUSED struct LevelCamera *a)
{
}

void dummy_802877EC(UNUSED struct LevelCamera *a)
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

extern f32 D_80336160;

void func_802878B8(f32 a, Vec3f b, Vec3f c, Vec3f d, Vec3f e, Vec3f f)
{
    f32 sp40[4];
    f32 sp3C;
    f32 sp38;
    f32 sp34;
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

s32 func_80287CFC(Vec3f a, struct Struct8032E040 b[], s16 *c, f32 *d)
{
    s32 sp6C = 0;
    Vec3f sp3C[4];
    s32 sp38 = 0;
    f32 sp34 = *d;
    UNUSED f32 sp30;
    f32 sp2C = 0.f;
    f32 sp28 = 0.f;
    s32 sp24 = *c;

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

s32 func_8028803C(s32 a)
{
    s32 sp1C = 2;

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

s32 func_80288130(s32 a)
{
    s32 sp4 = 2;

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
    s32 sp6C;
    Vec3f sp60;
    Vec3f sp30[4];
    f32 sp2C;
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
            sp30[sp6C][0] = D_8033B2B8[sp6C].myUnion.unk8[0];
            sp30[sp6C][1] = D_8033B2B8[sp6C].myUnion.unk8[1];
            sp30[sp6C][2] = D_8033B2B8[sp6C].myUnion.unk8[2];
        }
        func_802878B8(D_8033B2FC, sp60, sp30[0], sp30[1], sp30[2], sp30[3]);
        if (1.f <= (D_8033B2FC += D_8033B300))
        {
            for (sp6C = 0; sp6C < 3; sp6C++)
                vec3s_copy(D_8033B2B8[sp6C].myUnion.unk8, D_8033B2B8[sp6C + 1].myUnion.unk8);
            func_80289618(D_8033B2B8[3].myUnion.unk8, D_8033B2F8, D_8033B2F8, D_8033B2F8 / 2);
            D_8033B2FC -= 1.f;
            D_8033B300 = RandomFloat() * 0.5f;
            if (D_8033B300 < 0.02f)
                D_8033B300 = 0.02f;
        }
    }
    approach_s16_exponential(&D_8033B304, sp60[0], 8);
    approach_s16_exponential(&D_8033B306, sp60[1], 8);
    approach_s16_exponential(&D_8033B308, sp60[2], 8);
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

s32 func_802886FC(u16 a, u16 buttonsPressed, u16 buttonsDown)
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

s32 update_camera_status(struct LevelCamera *a)
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

s32 func_80288974(Vec3f pos, f32 offsetY, f32 radius)
{
    struct WallCollisionData collisionData;
    struct Surface *wall = NULL;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    Vec3f sp24[4];
    s32 sp20;
    s32 sp1C = 0;

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
            sp68 = wall->normal.x;
            sp64 = wall->normal.y;
            sp60 = wall->normal.z;
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

s32 func_80288BB0(Vec3f a, f32 b, f32 c, f32 d)
{
    s32 equal = FALSE;

    if (a[0] == b && a[1] == c && a[2] == d)
        equal = TRUE;
    return equal;
}

s32 func_80288C2C(Vec3f a, Vec3f b, s16 c, s16 d)
{
    s32 sp2C = 0;
    s16 sp2A;
    s16 sp28;
    f32 sp24;

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

s32 func_80288CF0(f32 a, f32 b, f32 c)
{
    s32 sp24 = 0;
    Vec3f sp18;

    vec3f_set(sp18, a, b, c);
    if (func_8028A640(D_8032D000->unk4, sp18) < 100.f)
        sp24 = 1;
    return sp24;
}

s32 func_80288D74(f32 *a, f32 b, f32 c)
{
    if (D_8033B4DA & 1)
        approach_f32_exponential(a, b, c);
    else
        *a = b;
    if (*a == b)
        return 0;
    else
        return 1;
}

// approaches an f32 value by taking the difference between the target and current value, and adding a fraction of that to the current value
// edits the current value directly, returns TRUE if the target has been reached, FALSE otherwise.
s32 approach_f32_exponential(f32 *current, f32 target, f32 multiplier)
{
    if (multiplier > 1.f)
        multiplier = 1.f;
    *current = *current + (target - *current) * multiplier;
    if (*current == target)
        return FALSE;
    else
        return TRUE;
}

// same as above function, but doesn't take a pointer, instead simply returns the new value.
f32 approach_f32_exponential_2(f32 current, f32 target, f32 multiplier)
{
    current = current + (target - current) * multiplier;
    return current;
}

// approaches an s16 value in the same fashion as approach_f32_exponential, returns TRUE if target is reached
// note: because this function takes integers as parameters, the last argument is the reciprocal of what it would be in the previous two functions.
s32 approach_s16_exponential(s16 *current, s16 target, s16 divisor)
{
    s16 temp = *current;

    if (divisor == 0)
    {
        *current = target;
    }
    else
    {
        temp -= target;
        temp -= temp / divisor;
        temp += target;
        *current = temp;
    }
    if (*current == target)
        return FALSE;
    else
        return TRUE;
}

// approaches an s16 value in the same fashion as approach_f32_exponential_2, returns the new value
// note: last parameter is the reciprocal of what it would be in the f32 functions
s32 approach_s16_exponential_2(s16 current, s16 target, s16 divisor)
{
    s16 temp = current;

    if (divisor == 0)
    {
        current = target;
    }
    else
    {
        temp -= target;
        temp -= temp / divisor;
        temp += target;
        current = temp;
    }
    return current;
}

void approach_vec3f_exponential(Vec3f current, Vec3f target, f32 x_multiplier, f32 y_multiplier, f32 z_multiplier)
{
    approach_f32_exponential(&current[0], target[0], x_multiplier);
    approach_f32_exponential(&current[1], target[1], y_multiplier);
    approach_f32_exponential(&current[2], target[2], z_multiplier);
}

void func_8028909C(Vec3f a, Vec3f b, f32 c, f32 d, f32 e)
{
    func_80288D74(&a[0], b[0], c);
    func_80288D74(&a[1], b[1], d);
    func_80288D74(&a[2], b[2], e);
}

void approach_vec3s_exponential(Vec3s current, Vec3s target, s16 x_multiplier, s16 y_multiplier, s16 z_multiplier)
{
    approach_s16_exponential(&current[0], target[0], x_multiplier);
    approach_s16_exponential(&current[1], target[1], y_multiplier);
    approach_s16_exponential(&current[2], target[2], z_multiplier);
}

// TODO: Name these functions, they all appear to be variants of "approach_x" functions

s32 func_80289184(s16 *value, s16 target, s16 increment)
{
    s16 dist = target - *value;

    if (increment < 0)
        increment = -1 * increment;
    if (dist > 0)
    {
        dist -= increment;
        if (dist >= 0)
            *value = target - dist;
        else
            *value = target;
    }
    else
    {
        dist += increment;
        if (dist <= 0)
            *value = target - dist;
        else
            *value = target;
    }
    if (*value == target)
        return FALSE;
    else
        return TRUE;
}

s32 func_80289264(s16 value, s16 target, s16 increment)
{
    s16 dist = target - value;

    if (increment < 0)
        increment = -1 * increment;
    if (dist > 0)
    {
        dist -= increment;
        if (dist >= 0)
            value = target - dist;
        else
            value = target;
    }
    else
    {
        dist += increment;
        if (dist <= 0)
            value = target - dist;
        else
            value = target;
    }
    return value;
}

s32 func_80289354(s16 *value, s16 target, s16 increment)
{
    if (D_8033B4DA & 1)
        func_80289184(value, target, increment);
    else
        *value = target;
    if (*value == target)
        return FALSE;
    else
        return TRUE;
}

// This appears to be a really strange way of implementing approach_f32_symmetric from math_util.c?
// It could possibly be an older version of the function
s32 func_802893E4(f32 *value, f32 target, f32 increment)
{
    f32 dist = target - *value;

    if (increment < 0)
        increment = -1 * increment;
    if (dist > 0)
    {
        dist -= increment;
        if (dist > 0)
            *value = target - dist;
        else
            *value = target;
    }
    else
    {
        dist += increment;
        if (dist < 0)
            *value = target - dist;
        else
            *value = target;
    }
    if (*value == target)
        return FALSE;
    else
        return TRUE;
}

f32 func_80289524(f32 value, f32 target, f32 increment)
{
    f32 dist = target - value;

    if (increment < 0)
        increment = -1 * increment;
    if (dist > 0)
    {
        dist -= increment;
        if (dist > 0)
            value = target - dist;
        else
            value = target;
    }
    else
    {
        dist += increment;
        if (dist < 0)
            value = target - dist;
        else
            value = target;
    }
    return value;
}

void func_80289618(Vec3s a, s16 b, s16 c, s16 d)
{
    f32 sp2C;
    UNUSED u8 unused[4];
    f32 sp24;
    f32 sp20;
    f32 sp1C;

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

s32 func_80289738(s16 a, f32 b, f32 c, f32 d, f32 e)
{
    Vec3f sp3C;
    f32 sp38;
    s16 sp36;
    s16 sp34;
    s16 sp32;
    s16 sp30;
    s16 sp2E = 0;
    f32 sp28 = D_8033B328.unk0[3][0] - c;
    f32 sp24 = D_8033B328.unk0[3][1] - d;
    f32 sp20 = D_8033B328.unk0[3][2] - e;

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

s32 func_802899A0(Vec3f a, Vec3f b, f32 c, f32 d, f32 e, f32 f)
{
    s16 sp1E = gCurrLevelCamera->unk3A;

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

s32 func_80289A98(s16 a, s16 b)
{
    s16 sp2E;
    UNUSED u8 unused[34];
    UNUSED s32 sp8 = 0;
    UNUSED s32 sp4 = 0;

    sp2E = b - a + 0x4000;
    if (sp2E < 0)
        a = b;
    else
        a = b + 32768;
    return a;
}

s32 func_80289B0C(struct Surface *a, f32 b, f32 c, f32 d)
{
    Vec3s sp38;
    Vec3s sp30;
    Vec3s sp28;
    s16 sp26 = 0;
    s16 sp24 = 0;
    s16 sp22 = 0;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    UNUSED u8 unused[4];
    s32 spC;
    s32 sp8;
    s32 sp4 = 0;

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

s32 func_80289F04(Vec3f a, struct Surface *b)
{
    s32 sp1C = 0;
    f32 sp18 = (b->vertex2[1] - b->vertex1[1]) * (b->vertex3[2] - b->vertex2[2]) - (b->vertex3[1] - b->vertex2[1]) * (b->vertex2[2] - b->vertex1[2]);
    f32 sp14 = (b->vertex2[2] - b->vertex1[2]) * (b->vertex3[0] - b->vertex2[0]) - (b->vertex3[2] - b->vertex2[2]) * (b->vertex2[0] - b->vertex1[0]);
    f32 sp10 = (b->vertex2[0] - b->vertex1[0]) * (b->vertex3[1] - b->vertex2[1]) - (b->vertex3[0] - b->vertex2[0]) * (b->vertex2[1] - b->vertex1[1]);
    f32 spC = b->vertex1[0] - a[0];
    f32 sp8 = b->vertex1[1] - a[1];
    f32 sp4 = b->vertex1[2] - a[2];

    if (spC * sp18 + sp8 * sp14 + sp4 * sp10 < 0)
        sp1C = 1;
    return sp1C;
}

s32 func_8028A0D4(Vec3f a, Vec3f b, struct Surface *c, s16 d, s16 e)
{
    s32 sp54 = 1;
    s32 sp50 = 0;
    s32 sp4C = 0;
    UNUSED u8 unused[20];
    f32 sp34;
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

s32 func_8028A204(UNUSED s32 a, struct Surface *b)
{
    s32 sp1C = func_80289F04(D_8032D000->unk4, b);

    return sp1C;
}

void func_8028A24C(Vec3f a, Vec3f b, Vec3f c, f32 d)
{
    Vec3f sp1C;

    sp1C[0] = (c[0] - b[0]) * d + b[0];
    sp1C[1] = (c[1] - b[1]) * d + b[1];
    sp1C[2] = (c[2] - b[2]) * d + b[2];
    vec3f_copy(a, sp1C);
}

s32 func_8028A300(Vec3f a, Vec3f b, Vec3f c, s16 d)
{
    s32 sp24 = 0;
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

s16 func_8028A440(Vec3f a, Vec3f b)
{
    f32 sp34 = b[0] - a[0];
    f32 sp30 = b[1] - a[1];
    f32 sp2C = b[2] - a[2];
    s16 sp2A = atan2s(sqrtf(sp34 * sp34 + sp2C * sp2C), sp30);

    return sp2A;
}

s16 func_8028A4F0(Vec3f a, Vec3f b)
{
    f32 sp24 = b[0] - a[0];
    UNUSED f32 sp20 = b[1] - a[1];
    f32 sp1C = b[2] - a[2];
    s16 sp1A = atan2s(sp1C, sp24);

    return sp1A;
}

void func_8028A578(Vec3f a, Vec3f b, s16 *c, s16 *d)
{
    f32 sp2C = b[0] - a[0];
    f32 sp28 = b[1] - a[1];
    f32 sp24 = b[2] - a[2];

    *c = atan2s(sqrtf(sp2C * sp2C + sp24 * sp24), sp28);
    *d = atan2s(sp24, sp2C);
}

f32 func_8028A640(Vec3f a, Vec3f b)
{
    f32 sp24 = b[0] - a[0];
    f32 sp20 = b[1] - a[1];
    f32 sp1C = b[2] - a[2];
    f32 sp18 = sqrtf(sp24 * sp24 + sp20 * sp20 + sp1C * sp1C);

    return sp18;
}

f32 func_8028A6E4(Vec3f a, Vec3f b)
{
    f32 sp24 = b[0] - a[0];
    f32 sp20 = b[2] - a[2];
    f32 sp1C = sqrtf(sp24 * sp24 + sp20 * sp20);

    return sp1C;
}

void func_8028A764(Vec3f a, Vec3f b, s16 c)
{
    Vec3f sp1C;

    vec3f_copy(sp1C, b);
    a[0] = sp1C[2] * sins(c) + sp1C[0] * coss(c);
    a[1] = sp1C[1];
    a[2] = sp1C[2] * coss(c) - sp1C[0] * sins(c);
}

void func_8028A834(Vec3f a, Vec3f b, s16 c)
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

void func_8028AA80(s16 a, s16 b, s16 c, f32 d, f32 e, f32 f, f32 g)
{
    Vec3f sp2C;
    f32 sp28;
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

void Unknown8028AB34(s16 a, s16 b, s16 c, f32 d, f32 e, f32 f, f32 g)
{
    Vec3f sp2C;
    f32 sp28;
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
    f32 sp24;
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
    f32 sp24;
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

s32 func_8028AF24(struct LevelCamera *a, s16 b)
{
    s16 sp3E = 10922;
    s16 sp3C = D_8033B402;
    f32 sp38;
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
    func_80320AE8(0, (4 << 8) | 29, 0);
}

void func_8028B16C(void)
{
    func_80320AE8(0, (15 << 8) | 30, 0);
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

s32 func_8028B3DC(struct LevelCamera *a, UNUSED f32 b)
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
                if (a->preset == CAMERA_PRESET_OPEN_CAMERA)
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
                if (a->preset == CAMERA_PRESET_OPEN_CAMERA)
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

s32 StopMario(s32 a)
{
    s32 sp1C = 0;
    UNUSED struct LevelCamera *sp18 = gCurrLevelCamera;

    if (a == 1)
        func_8028F834(171);
    if (a == 2) {}
    return sp1C;
}

void func_8028B7A4(struct LevelCamera *a)
{
    s16 sp1E;

    if (gPlayer1Controller->buttonPressed & U_CBUTTONS)
    {
        if (a->preset != CAMERA_PRESET_FIXED_REF_POINT && (D_8033B4D8 & 2))
        {
            D_8033B4D8 &= ~2;
            func_8028B268();
        }
        else
        {
            func_80284D44(a);
            if (D_8033B3FC > gCameraZoomDist)
                D_8033B3F4 = -gCameraZoomDist;
            else
                D_8033B3F4 = gCameraZoomDist;
        }
    }
    if (a->preset != CAMERA_PRESET_FIXED_REF_POINT)
    {
        if (gPlayer1Controller->buttonPressed & D_CBUTTONS)
        {
            if (D_8033B4D8 & 2)
            {
                D_8033B4D8 |= 0x1000;
                D_8033B3F4 = gCameraZoomDist + 400.f;
#if VERSION_US
                func_8028B19C();
#endif
            }
            else
            {
                D_8033B4D8 |= 2;
                D_8033B3F4 = gCameraZoomDist + 400.f;
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

void func_8028BA38(UNUSED struct LevelCamera *a)
{
    s32 sp1C;

    for (sp1C = 0; sp1C < 10; sp1C++)
    {
        D_8033B6F0[sp1C].unk0 = 0;
        vec3f_set(D_8033B6F0[sp1C].unk4, 0.f, 0.f, 0.f);
        vec3f_set(D_8033B6F0[sp1C].unk10, 0.f, 0.f, 0.f);
        vec3s_set(D_8033B6F0[sp1C].unk1C, 0, 0, 0);
        D_8033B6F0[sp1C].unk22 = 0;
    }
}

void func_8028BB3C(struct LevelCamera *a, u8 b)
{
    if (a->unk30 != b)
    {
        a->unk30 = b;
        func_8028BA38(a);
    }
}

extern u8 D_8032E8A4[27][4];

s32 func_8028BB8C(UNUSED struct LevelCamera *a)
{
    u8 sp7 = 0;
    u8 sp6 = 0;
    u8 sp5 = (D_8032CE24 - 1) / 2;
    u8 sp4 = gCurrCourseNum;

    if (sp5 > 3)
        sp5 = 0;
    if (sp4 > COURSE_MAX)
        sp4 = COURSE_NONE;
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

u8 func_8028BCC8(struct LevelCamera *a)
{
    UNUSED u8 unused1[4];
    u8 sp33 = a->unk30;
    UNUSED u8 unused2[12];

    if (sp33 == 0)
    {
        sp33 = D_8032CFF0;
        D_8032CFF0 = 0;
        if (D_8032D000->unk1C[1] == 6)
        {
            switch (D_8032CFD8)
            {
            case 97:
                if (a->preset == CAMERA_PRESET_UNKNOWN_11 || a->preset == CAMERA_PRESET_CLOSE || a->unk64 == 2)
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
        if (D_8032D000->unk1C[1] == 5)
            sp33 = 139;
        if (D_8032D000->unk1C[1] == 1)
            sp33 = 133;
        if (SURFACE_IS_PAINTING_WARP(D_8033B278.unk8))
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
            if (D_8032CFDC == LEVEL_BOWSER_1 || D_8032CFDC == LEVEL_BOWSER_2 || D_8032CFDC == LEVEL_BOWSER_3)
                sp33 = 157;
            else
                sp33 = 169;
            break;
        case 6444:
            if (D_8032CFDC == LEVEL_BOWSER_1 || D_8032CFDC == LEVEL_BOWSER_2 || D_8032CFDC == LEVEL_BOWSER_3)
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
        switch (D_8032D000->unk1C[1])
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

void func_8028C1A0(f32 a, f32 b, f32 c)
{
    Vec3f sp24;
    struct MarioState *sp20 = &gMarioStates[0];
    struct Struct8033B418_sub *sp1C = &D_8033B418.unk8;
    struct Struct8033B418_sub *sp28 = &D_8033B418.unk28;

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

void func_8028C2F0(struct LevelCamera *a, f32 b, f32 c)
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

void Unknown8028C3AC(UNUSED s32 a, UNUSED s32 b, UNUSED s32 c, UNUSED s32 d)
{
}

void func_8028C3CC(struct LevelCamera *a, f32 b, f32 c, f32 d, s16 e)
{
    u16 sp26;
    UNUSED u8 unused[2];
    f32 sp20;

    func_8027F668(&sp20, 1.f, 200.f, &sp20, 0.9f, 200.f);
    sp26 = D_8032D000->unk10[1] + e;
    a->unk4[2] = D_8032D000->unk4[2] + d * coss(sp26) - b * sins(sp26);
    a->unk4[0] = D_8032D000->unk4[0] + d * sins(sp26) + b * coss(sp26);
    a->unk4[1] = D_8032D000->unk4[1] + c + sp20;
}

static void unused_8028C508(struct LevelCamera *a, f32 b, f32 c, f32 d, s16 e)
{
    u16 sp6 = D_8032D000->unk10[1] + e;

    a->unk10[0] = D_8032D000->unk4[0] + d * sins(sp6) + b * coss(sp6);
    a->unk10[1] = D_8032D000->unk4[1] + c;
    a->unk10[2] = D_8032D000->unk4[2] + d * coss(sp6) - b * sins(sp6);
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

void func_8028C794(Vec3f a, Vec3f b, Vec3s c, f32 d, f32 e, f32 f)
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

s32 func_8028C824(Vec3f a, Vec3f b, Vec3f c, Vec3f d, Vec3f e, Vec3f f, s16 g)
{
    s16 sp96;
    s16 sp94;
    f32 sp90;
    f32 sp8C;
    UNUSED u8 unused1[4];
    s16 sp86;
    s16 sp84;
    UNUSED u8 unused2[4];
    f32 sp7C = D_8033B250.unk10;
    s16 sp7A = D_8033B250.unk10;
    UNUSED s16 sp78 = 0;
    Vec3f sp6C;
    Vec3f sp60;
    Vec3f sp54;
    Vec3f sp48;
    s32 sp44;
    f32 sp40;
    struct Surface *sp3C;

    vec3f_copy(a, c);
    vec3f_copy(b, d);
    if (D_8033B4DA & 0x400)
    {
        for (sp44 = 0; sp44 < 3; sp44++)
        {
            sp54[sp44] = e[sp44] + D_8032D000->unk4[sp44] - D_8033B250.unk14[sp44];
            sp48[sp44] = f[sp44] + D_8032D000->unk4[sp44] - D_8033B250.unk14[sp44];
        }
        vec3f_get_dist_and_angle(d, sp48, &D_8033B250.unkC, &D_8033B250.unk8, &D_8033B250.unkA);
        vec3f_get_dist_and_angle(d, sp54, &D_8033B250.unk4, &D_8033B250.unk0, &D_8033B250.unk2);
        D_8033B4DA &= ~1024;
    }
    if (D_8033B250.unk10 > 0)
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
        if (gCurrLevelCamera->unk30 != 0 || !(D_8033B4D8 & 0x2000))
        {
            sp40 = find_floor(a[0], a[1], a[2], &sp3C);
            if (sp40 != -11000.f)
            {
                if ((sp40 += 125.f) > a[1])
                    a[1] = sp40;
            }
            resolve_wall_collisions(&a[0], &a[1], &a[2], 0.f, 100.f);
        }
        D_8033B250.unk10--;
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
    D_8033B250.unk10 = 0;
}

s32 func_8028CE4C(struct LevelCamera *a, s16 b, s16 c, s16 d)
{
    s32 sp24 = 0;
    f32 sp20 = b;
    f32 sp1C = c;
    f32 sp18 = d;

    if (D_8032D00C[0] != sp20 || D_8032D00C[1] != sp1C || D_8032D00C[2] != sp18)
    {
        sp24 = 1;
        D_8033B4DA &= ~1;
    }
    vec3f_set(D_8032D00C, sp20, sp1C, sp18);
    if (a->preset != CAMERA_PRESET_FIXED_REF_POINT)
    {
        D_8033B4DA &= ~1;
        a->preset = CAMERA_PRESET_FIXED_REF_POINT;
        vec3f_set(a->unk10, D_8032D00C[0], D_8032D000->unk4[1], D_8032D00C[2]);
    }
    return sp24;
}

void func_8028CFAC(struct LevelCamera *a)
{
    if (a->preset != CAMERA_PRESET_BOWSER_LEVEL)
    {
        a->preset = CAMERA_PRESET_BOWSER_LEVEL;
        D_8033B4DA &= ~1;
        D_8033B406 = 0;
        D_8033B408 = 0;
    }
}

void func_8028CFFC(struct LevelCamera *a)
{
    if (a->preset != CAMERA_PRESET_BOWSER_FIGHT)
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

void func_8028D098(struct LevelCamera *a, s16 b)
{
    Vec3f sp24;
    s16 sp22;

    sp24[0] = a->unk28;
    sp24[1] = D_8032D000->unk4[1];
    sp24[2] = a->unk2C;
    if (a->preset != CAMERA_PRESET_OPEN_CAMERA)
    {
        sp22 = func_8028A4F0(sp24, D_8032D000->unk4) - func_8028A4F0(a->unk4, a->unk10) + 0x4000;
        if (sp22 > 0)
        {
            func_80285AD8(a, 1, b);
        }
        else
        {
            a->preset = CAMERA_PRESET_OPEN_CAMERA;
            D_8033B4DA &= ~1;
        }
        D_8033B402 = 0;
    }
}

void func_8028D19C(struct LevelCamera *a, struct Struct8033B470 *b)
{
    if (a->preset != CAMERA_PRESET_UNKNOWN_0C)
    {
        D_8033B470 = b;
        D_8033B46C = 0;
        D_8033B478.unk0[0] = 0.f;
        D_8033B478.unk0[1] = 0.f;
        D_8033B478.unk0[2] = 0.f;
        a->unk10[0] = (D_8033B470[0].unk4[0] + D_8033B470[1].unk4[0]) / 2.f;
        a->unk10[1] = (D_8033B470[0].unk4[1] + D_8033B470[1].unk4[1]) / 2.f;
        a->unk10[2] = (D_8033B470[0].unk4[2] + D_8033B470[1].unk4[2]) / 2.f;
        D_8033B4DA &= ~1;
        a->preset = CAMERA_PRESET_UNKNOWN_0C;
    }
}

void func_8028D288(UNUSED s32 a)
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
    if (gCurrLevelNum == LEVEL_DDD || gCurrLevelNum == LEVEL_WDW || gCurrLevelNum == LEVEL_COTMC)
        D_8033B4DA &= ~4096;
    if ((*a == 3 && !(D_8032D000->unk0 & 0x6000)) || *a == 10)
        D_8033B4DA |= 0x1000;
}

void CameraRR00(struct LevelCamera *a)
{
    func_8028CFAC(a);
    D_8033B406 = 16384;
}

void CameraRR04(struct LevelCamera *a)
{
    func_8028CFAC(a);
    if (a->unk10[1] < 6343.f)
    {
        a->unk10[1] = 7543.f;
        D_8033B328.unk0[3][1] = a->unk10[1];
        D_8033B328.unk0[1][1] = a->unk10[1];
        D_8033B4DA &= ~1;
    }
}

void CameraRR02(struct LevelCamera *a)
{
    if (a->preset != CAMERA_PRESET_FIXED_REF_POINT)
        func_8028CE4C(a, -2974, 478, -3975);
}

void CameraRR0305(struct LevelCamera *a)
{
    if (a->preset != CAMERA_PRESET_FIXED_REF_POINT)
        func_8028CE4C(a, -2953, 798, -3943);
    if (a->unk10[1] > 6043.f)
        a->unk10[1] = 6043.f;
}

void CameraRR01(struct LevelCamera *a)
{
    if (a->preset != CAMERA_PRESET_FIXED_REF_POINT)
    {
        D_8033B4DA &= ~1;
        a->preset = CAMERA_PRESET_FIXED_REF_POINT;
    }
}

void CameraMetal00(UNUSED struct LevelCamera *a)
{
    D_8033B4D8 |= 0x40;
}

void CameraSL00(struct LevelCamera *a)
{
    D_8033B4DA |= 0x1000;
    func_80285AD8(a, 14, 60);
    D_8033B406 = 7463;
}

void CameraSL01(struct LevelCamera *a)
{
    func_80285AD8(a, 16, 60);
}

void func_8028D6A4(struct LevelCamera *a, f32 b)
{
    UNUSED f32 pad;
    
    if ((D_8033B278.unk4 < b - 100.f) && (D_8033B278.unk1C > D_8033B278.unk4))
    {
        a->unk10[1] = b - 400.f;
        D_8033B328.unk0[1][1] = b - 400.f;
        D_8033B328.unk0[3][1] = b - 400.f;
    }
}

void CameraHMC00(struct LevelCamera *a)
{
    s16 sp26, sp24;
    f32 sp20;
    
    if (a->unk10[1] > -102.f)
    {
        vec3f_get_dist_and_angle(a->unk4, D_8033B328.unk0[3], &sp20, &sp26, &sp24);
        vec3f_set_dist_and_angle(a->unk4, D_8033B328.unk0[3], 300.f, sp26, sp24);
        D_8033B328.unk0[3][1] = -800.f;
#if VERSION_US
        a->unk10[1] = D_8033B328.unk0[3][1];
        D_8033B328.unk0[1][1] = D_8033B328.unk0[3][1];
#endif
        D_8033B4DA &= ~1;
    }
}

void CameraHMC02(struct LevelCamera *a)
{
    func_8028D6A4(a, 1536.f);
}

void CameraHMC03(struct LevelCamera *a)
{
    func_8028D6A4(a, 2355.f);
}

void CameraHMC04(struct LevelCamera *a)
{
    func_8028D6A4(a, 1843.f);
}

void CameraHMC05(struct LevelCamera *a)
{
    func_8028D6A4(a, 1843.f);
}

void CameraSSL00(UNUSED struct LevelCamera *a)
{
    func_8028F834(164);
}

void CameraSSL0102(struct LevelCamera *a)
{
    D_8033B4DA |= 0x1000;
    func_80285AD8(a, 4, 90);
}

void CameraSSL03(struct LevelCamera *a)
{
    D_8033B4DA |= 0x1000;
    func_80285AD8(a, 2, 90);
}

void CameraTHI00(UNUSED struct LevelCamera *a)
{
    if (D_8033B402 < 10922)
        D_8033B402 = 10922;
}

void CameraTHI01(UNUSED struct LevelCamera *a)
{
    if (D_8033B402 > 15018)
        D_8033B402 = 15018;
}

void CameraRR07(struct LevelCamera *a)
{
    D_8033B4DA |= 0x1000;
    func_80285AD8(a, 1, 90);
}

void CameraRR08(struct LevelCamera *a)
{
    func_80285AD8(a, 16, 90);
}

void CameraHMC01(struct LevelCamera *a)
{
    if ((D_8032D000->unk0 != 6444) && (D_8032D000->unk0 != 6443))
        func_8028BB3C(a, 181);
}

void CameraInside20(UNUSED struct LevelCamera *a)
{
    vec3f_set(D_8033B460, -813.f - D_8032D00C[0], 378.f - D_8032D00C[1], 1103.f - D_8032D00C[2]);
}

void CameraInside1E(struct LevelCamera *a)
{
    struct Surface *sp1C;
    f32 sp18 = find_floor(a->unk10[0], a->unk10[1], a->unk10[2], &sp1C);
    
    if ((D_8033B278.unk4 > 1229.f) && (sp18 < 1229.f) && (D_8033B3F8 == 0))
        vec3f_set(a->unk10, -227.f, 1425.f, 1533.f);
}

void CameraInside1F(struct LevelCamera *a)
{
    struct Surface *sp1C;
    f32 sp18 = find_floor(a->unk10[0], a->unk10[1], a->unk10[2], &sp1C);
    
    if ((sp18 > -110.f) && (D_8033B3F8 == 0))
        vec3f_set(a->unk10, -980.f, 249.f, -1398.f);
}

void CameraInside01(struct LevelCamera *a)
{
    if (a->preset != CAMERA_PRESET_FIXED_REF_POINT)
    {
        D_8033B4DA &= ~1;
        func_8028D288(a->preset);
        a->preset = CAMERA_PRESET_FIXED_REF_POINT;
    }
}

void CameraInside1213(struct LevelCamera *a)
{
    func_80285AD8(a, 17, 20);
}

void CameraUnused(struct LevelCamera *a)
{
    if (a->preset == CAMERA_PRESET_UNKNOWN_11)
        func_80285AD8(a, 4, 30);
    else
        func_8028D058(&a->preset);
}

void CameraInside00(struct LevelCamera *a)
{
    func_8028D058(&a->preset);
}

void CameraInside0E(struct LevelCamera *a)
{
    CameraInside00(a);
    a->unk64 = 2;
}

void CameraInside0F(struct LevelCamera *a)
{
    CameraInside01(a);
}

void CameraBBH2B2C(struct LevelCamera *a)
{
    func_8028D19C(a, D_8032D0F0);
}

void CameraBBH24(struct LevelCamera *a)
{
    func_8028D058(&a->preset);
}

void CameraBBH2E2F(struct LevelCamera *a)
{
    Vec3f sp1C;
    func_8028D058(&a->preset);
    vec3f_set(sp1C, 0.f, 0.f, 300.f);
    func_8028C5F0(D_8033B328.unk0[3], D_8032D000->unk4, sp1C, D_8032D000->unk10);
    D_8033B328.unk0[3][1] = -2300.f;
    vec3f_copy(a->unk10, D_8033B328.unk0[3]);
    D_8033B4DA &= ~1;
}

void CameraBBH020C(struct LevelCamera *a)
{
    func_8028CE4C(a, 956, 440, 1994);
}

void CameraBBH01(struct LevelCamera *a)
{
    a->unk64 = 1;
    CameraBBH020C(a);
}

void CameraBBH0D0F(struct LevelCamera *a)
{
    func_8028CE4C(a, 2591, 400, 1284);
}

void CameraBBH1011(struct LevelCamera *a)
{
    func_8028CE4C(a, 3529, 340, -1384);
}

void CameraBBH12(struct LevelCamera *a)
{
    func_8028CE4C(a, -500, 740, -1306);
}

void CameraBBH1314(struct LevelCamera *a)
{
    func_8028CE4C(a, -2172, 200, 675);
}

void CameraBBH15(struct LevelCamera *a)
{
    if (func_8028CE4C(a, -2172, 200, 675) == 1)
        func_80285A8C(a, 20);
}

void CameraBBH16(struct LevelCamera *a)
{
    if (func_8028CE4C(a, -1542, 320, -307) == 1)
        func_80285A8C(a, 20);
}

void CameraBBH17(struct LevelCamera *a)
{
    a->unk64 = 1;
    func_8028CE4C(a, -1542, 320, -307);
}

void CameraBBH18(struct LevelCamera *a)
{
    func_8028CE4C(a, -1893, 320, 2327);
}

void CameraBBH28(struct LevelCamera *a)
{
    func_8028CE4C(a, 1371, 360, -1302);
}

void CameraBBH29(struct LevelCamera *a)
{
    if (func_8028CE4C(a, 1371, 360, -1302) == 1)
        func_80285A8C(a, 20);
}

void CameraBBH2A(struct LevelCamera *a)
{
    if (func_8028CE4C(a, 2115, 260, -772) == 1)
        func_80285A8C(a, 20);
}

void CameraBBH3033(struct LevelCamera *a)
{
    a->unk64 = 1;
    func_8028D058(&a->preset);
}

void CameraBBH34(struct LevelCamera *a)
{
    func_8028D058(&a->preset);
}

void CameraBBH38(struct LevelCamera *a)
{
    if (a->preset == CAMERA_PRESET_FIXED_REF_POINT)
    {
        func_8028D058(&a->preset);
        a->unk10[1] = -405.f;
        D_8033B328.unk0[3][1] = -405.f;
    }
}

void CameraBBH393A(struct LevelCamera *a)
{
    a->unk64 = 1;
    func_8028CE4C(a, -2932, 296, 4429);
}

void CameraBBH00(struct LevelCamera *a)
{
    func_8028D058(&a->preset);
}

void CameraBBH1A1B(struct LevelCamera *a)
{
    func_8028CE4C(a, 3493, 440, 617);
}

void CameraBBH1C(struct LevelCamera *a)
{
    if (func_8028CE4C(a, 3493, 440, 617) == 1)
        func_80285A8C(a, 20);
}

void CameraBBH1E(struct LevelCamera *a)
{
    func_8028CE4C(a, 3502, 440, 1217);
}

void CameraBBH1D(struct LevelCamera *a)
{
    if (func_8028CE4C(a, 3502, 440, 1217) == 1)
        func_80285A8C(a, 20);
}

void CameraBBH1F20(struct LevelCamera *a)
{
    func_8028CE4C(a, -670, 460, 372);
}

void CameraBBH21(struct LevelCamera *a)
{
    if (func_8028CE4C(a, -670, 460, 372) == 1)
        func_80285A8C(a, 20);
}

void CameraBBH22(struct LevelCamera *a)
{
    if (func_8028CE4C(a, 131, 380, -263) == 1)
        func_80285A8C(a, 20);
}

void CameraBBH23(struct LevelCamera *a)
{
    func_8028CE4C(a, 210, 420, 3109);
}

void CameraBBH3536(struct LevelCamera *a)
{
    a->unk64 = 1;
    func_8028CE4C(a, -204, 807, 204);
}

void CameraCCM00(UNUSED struct LevelCamera *a)
{
    D_8033B4DA |= 0x10;
}

void CameraCCM01(UNUSED struct LevelCamera *a)
{
    D_8033B4DA &= ~0x10;
}

u32 func_8028E634(struct LevelCamera *a)
{
    u32 sp24 = 0;
    
    switch (D_8033B278.unk8)
    {
    case SURFACE_000B:
        func_80285AD8(a, 4, 90);
        sp24 += 1;
        break;
        
    case SURFACE_0066:
        func_80285AD8(a, 16, 90);
        sp24 += 1;
        break;
        
    case SURFACE_0079:
        func_80285AD8(a, 4, 90);
        sp24 += 1;
        break;
    }
    return sp24;
}

u32 func_8028E70C(struct LevelCamera *a, u8 b)
{
    u32 sp1C = 0;
    sp1C = func_8028E634(a);
    
    if ((sp1C == 0) && (b != 0))
        func_80285AD8(a, b, 90);
    
    return sp1C;
}

void func_8028E774(struct LevelCamera *a)
{
    switch (D_8033B278.unk8)
    {
    case SURFACE_000B:
        if (a->preset != CAMERA_PRESET_CLOSE)
            func_80285AD8(a, 16, 90);
        break;
        
    case SURFACE_0066:
        if (a->preset != CAMERA_PRESET_CLOSE)
            func_80285AD8(a, 16, 90);
        break;
        
    case SURFACE_0079:
        if (a->preset != CAMERA_PRESET_CLOSE)
            func_80285AD8(a, 16, 90);
        break;
        
    case SURFACE_0069:
        func_80285AD8(a, 14, 90);
        break;
        
    default:
        func_80285AD8(a, 1, 90);
    }
}

#define TABLE_EMPTY {0, NULL, 0, 0, 0, 0, 0, 0, 0}

struct Struct8032CA78 TableCameraSL[3] = {
    { 1, CameraSL00,    1119,  3584,  1125,  1177,   358,   358, -7463},
    { 1, CameraSL01,    1119,  3584,  1125,  4096,  4096,  4096, -7463},
    TABLE_EMPTY
};

struct Struct8032CA78 TableCameraTHI[3] = {
    { 1, CameraTHI00,  -4609, -2969,  6448,   100,   300,   300,     0},
    { 1, CameraTHI01,  -4809, -2969,  6448,   100,   300,   300,     0},
    TABLE_EMPTY
};

struct Struct8032CA78 TableCameraHMC[7] = {
    { 1, CameraHMC00,   1996,   102,     0,   205,   100,   205,     0},
    { 1, CameraHMC01,   3350, -4689,  4800,   600,    50,   600,     0},
    { 1, CameraHMC02,  -3278,  1236,  1379,   358,   200,   358,     0},
    { 1, CameraHMC03,  -2816,  2055, -2560,   358,   200,   358,     0},
    { 1, CameraHMC04,  -3532,  1543, -7040,   358,   200,   358,     0},
    { 1, CameraHMC05,   -972,  1543, -7347,   358,   200,   358,     0},
    TABLE_EMPTY
};

struct Struct8032CA78 TableCameraSSL[5] = {
    { 1, CameraSSL00,   -2048,  1080, -1024,   150,   150,   150,     0},
    { 2, CameraSSL0102,     0,  -104,  -104,  1248,  1536,  2950,     0},
    { 2, CameraSSL0102,     0,  2500,   256,   515,  5000,   515,     0},
    { 3, CameraSSL03,       0, -1534, -2040,  1000,   800,  1000,     0},
    TABLE_EMPTY
};

struct Struct8032CA78 TableCameraRR[10] = {
    { 1, CameraRR00,   -4197,  3819, -3087,  1769,  1490,   342,     0},
    { 1, CameraRR01,   -4197,  3819, -3771,   769,   490,   342,     0},
    { 1, CameraRR02,   -5603,  4834, -5209,   300,   600,   591,     0},
    { 1, CameraRR0305, -2609,  3730, -5463,   300,   650,   577,     0},
    { 1, CameraRR04,   -4196,  7343, -5155,  4500,  1000,  4500,     0},
    { 1, CameraRR0305, -4196,  6043, -5155,   500,   300,   500,     0},
    TABLE_EMPTY,
    { 1, CameraRR07,    2468,  2720, -4608,  3263,  1696,  3072,     0},
    {-1, CameraRR08,       0,     0,     0,     0,     0,     0,     0},
    TABLE_EMPTY
};

struct Struct8032CA78 TableCameraMetal[2] = {
    { 1, CameraMetal00,     0,  1500,  3500,   550, 10000,  1500,     0},
    TABLE_EMPTY
};

struct Struct8032CA78 TableCameraCCM[3] = {
    { 2, CameraCCM00, -4846,  2061,    27,  1229,  1342,   396,     0},
    { 2, CameraCCM01, -6412, -3917, -6246,   307,   185,   132,     0},
    TABLE_EMPTY
};

struct Struct8032CA78 TableCameraInside[35] = {
    { 1, CameraInside00,    -1100,    657,  -1346,    300,    150,    300,      0},
    { 1, CameraInside01,    -1099,    657,   -803,    300,    150,    300,      0},
    { 1, CameraInside00,    -2304,   -264,  -4072,    140,    150,    140,      0},
    { 1, CameraInside00,    -2304,    145,  -1344,    140,    150,    140,      0},
    { 1, CameraInside01,    -2304,    145,   -802,    140,    150,    140,      0},
    { 1, CameraInside00,     2816,   1200,   -256,    100,    100,    100,      0},
    { 1, CameraInside00,      256,   -161,  -4226,    140,    150,    140,      0},
    { 1, CameraInside00,      256,    145,  -1344,    140,    150,    140,      0},
    { 1, CameraInside01,      256,    145,   -802,    140,    150,    140,      0},
    { 1, CameraInside00,    -1023,     44,  -4870,    140,    150,    140,      0},
    { 1, CameraInside00,     -459,    145,  -1020,    140,    150,    140,  24576},
    { 1, CameraInside01,      -85,    145,   -627,    140,    150,    140,      0},
    { 1, CameraInside00,    -1589,    145,  -1020,    140,    150,    140, -24576},
    { 1, CameraInside01,    -1963,    145,   -627,    140,    150,    140,      0},
    { 1, CameraInside0E,    -2838,    657,  -1659,    200,    150,    150,   8192},
    { 1, CameraInside0F,    -2319,    512,  -1266,    300,    150,    300,   8192},
    { 1, CameraInside00,      844,    759,  -1657,     40,    150,     40,  -8192},
    { 1, CameraInside01,      442,    759,  -1292,    140,    150,    140,  -8192},
    { 2, CameraInside1213,  -1000,    657,   1740,    200,    300,    200,      0},
    { 2, CameraInside1213,   -996,   1348,   1814,    200,    300,    200,      0},
    { 2, CameraInside00,     -946,    657,   2721,     50,    150,     50,      0},
    { 2, CameraInside00,     -996,   1348,    907,     50,    150,     50,      0},
    { 2, CameraInside00,     -997,   1348,   1450,    140,    150,    140,      0},
    { 1, CameraInside00,    -4942,    452,   -461,    140,    150,    140,  16384},
    { 1, CameraInside00,    -3393,    350,   -793,    140,    150,    140,  16384},
    { 1, CameraInside01,    -2851,    350,   -792,    140,    150,    140,  16384},
    { 1, CameraInside01,      803,    350,   -228,    140,    150,    140, -16384},
    { 1, CameraInside01,      803,    350,   -228,    140,    150,    140, -16384},
    { 1, CameraInside00,     1345,    350,   -229,    140,    150,    140,  16384},
    { 1, CameraInside00,     -946,   -929,    622,    300,    150,    300,      0},
    { 2, CameraInside1E,     -205,   1456,   2508,    210,    928,    718,      0},
    { 1, CameraInside1F,    -1027,   -587,   -718,    318,    486,    577,      0},
    { 1, CameraInside20,    -1023,    376,   1830,    300,    400,    300,      0},
    { 3, CameraHMC01,        2485,  -1689,  -2659,    600,     50,    600,      0},
    TABLE_EMPTY
};

struct Struct8032CA78 TableCameraBBH[61] = {
    { 1, CameraBBH00,      742,      0,   2369,    200,    200,    200,      0},
    { 1, CameraBBH01,      741,      0,   1827,    200,    200,    200,      0},
    { 1, CameraBBH020C,    222,      0,   1458,    200,    200,    200,      0},
    { 1, CameraBBH020C,    222,      0,    639,    200,    200,    200,      0},
    { 1, CameraBBH020C,    435,      0,    222,    200,    200,    200,      0},
    { 1, CameraBBH020C,   1613,      0,    222,    200,    200,    200,      0},
    { 1, CameraBBH020C,   1827,      0,   1459,    200,    200,    200,      0},
    { 1, CameraBBH020C,   -495,    819,   1407,    200,    200,    200,      0},
    { 1, CameraBBH020C,   -495,    819,    640,    250,    200,    200,      0},
    { 1, CameraBBH020C,    179,    819,    222,    200,    200,    200,      0},
    { 1, CameraBBH020C,   1613,    819,    222,    200,    200,    200,      0},
    { 1, CameraBBH020C,   1827,    819,    486,    200,    200,    200,      0},
    { 1, CameraBBH020C,   1827,    819,   1818,    200,    200,    200,      0},
    { 1, CameraBBH0D0F,   2369,      0,   1459,    200,    200,    200,      0},
    { 1, CameraBBH0D0F,   3354,      0,   1347,    200,    200,    200,      0},
    { 1, CameraBBH0D0F,   2867,    514,   1843,    512,    102,    409,      0},
    { 1, CameraBBH1011,   3354,      0,    804,    200,    200,    200,      0},
    { 1, CameraBBH1011,   1613,      0,   -320,    200,    200,    200,      0},
    { 1, CameraBBH12,      435,      0,   -320,    200,    200,    200,      0},
    { 1, CameraBBH1314,  -2021,      0,    803,    200,    200,    200,      0},
    { 1, CameraBBH1314,   -320,      0,    640,    200,    200,    200,      0},
    { 1, CameraBBH15,    -1536,    358,   -254,    716,    363,    102,      0},
    { 1, CameraBBH16,    -1536,    358,   -459,    716,    363,    102,      0},
    { 1, CameraBBH17,    -1560,      0,  -1314,    200,    200,    200,      0},
    { 1, CameraBBH18,     -320,      0,   1459,    200,    200,    200,      0},
    { 1, CameraBBH18,    -2021,      0,   1345,    200,    200,    200,      0},
    { 1, CameraBBH1A1B,   2369,    819,    486,    200,    200,    200,      0},
    { 1, CameraBBH1A1B,   2369,   1741,    486,    200,    200,    200,      0},
    { 1, CameraBBH1C,     2867,   1228,   1174,    716,    414,    102,      0},
    { 1, CameraBBH1D,     2867,   1228,   1378,    716,    414,    102,      0},
    { 1, CameraBBH1E,     2369,    819,   1818,    200,    200,    200,      0},
    { 1, CameraBBH1F20,   1829,   1741,    486,    200,    200,    200,      0},
    { 1, CameraBBH1F20,    741,   1741,   1587,    200,    200,    200,      0},
    { 1, CameraBBH21,      102,   2048,   -191,    100,    310,    307,      0},
    { 1, CameraBBH22,      409,   2048,   -191,    100,    310,    307,      0},
    { 1, CameraBBH23,      742,   1922,   2164,    200,    200,    200,      0},
    { 1, CameraBBH24,      587,   1322,   2677,   1000,    400,    600,      0},
    { 1, CameraBBH18,    -1037,    819,   1408,    200,    200,    200,      0},
    { 1, CameraBBH18,    -1970,   1024,   1345,    200,    200,    200,      0},
    { 1, CameraBBH12,      179,    819,   -320,    200,    200,    200,      0},
    { 1, CameraBBH28,     1613,    819,   -320,    200,    200,    200,      0},
    { 1, CameraBBH29,     2099,   1228,   -819,    102,    414,    716,      0},
    { 1, CameraBBH2A,     2304,   1228,   -819,    102,    414,    716,      0},
    { 1, CameraBBH2B2C,  -1037,    819,    640,    200,    200,    200,      0},
    { 1, CameraBBH2B2C,  -1970,   1024,    803,    200,    200,    200,      0},
    { 1, CameraBBH020C,   1827,    819,   1818,    200,    200,    200,      0},
    { 1, CameraBBH2E2F,   2355,  -1112,   -193,   1228,    500,   1343,      0},
    { 1, CameraBBH2E2F,   2355,  -1727,   1410,   1228,    500,    705,      0},
    { 1, CameraBBH3033,      0,  -2457,   1827,    250,    200,    250,      0},
    { 1, CameraBBH3033,      0,  -2457,   2369,    250,    200,    250,      0},
    { 1, CameraBBH3033,      0,  -2457,   4929,    250,    200,    250,      0},
    { 1, CameraBBH3033,      0,  -2457,   4387,    250,    200,    250,      0},
    { 1, CameraBBH34,     1887,  -2457,    204,    250,    200,    250,      0},
    { 1, CameraBBH3536,   1272,  -2457,    204,    250,    200,    250,      0},
    { 1, CameraBBH3536,  -1681,  -2457,    204,    250,    200,    250,      0},
    { 1, CameraBBH34,    -2296,  -2457,    204,    250,    200,    250,      0},
    { 1, CameraBBH38,    -2939,   -605,   5367,    800,    100,    800,      0},
    { 1, CameraBBH393A,  -2939,   -205,   5367,    300,    100,    300,      0},
    { 1, CameraBBH393A,  -2332,   -204,   4714,    250,    200,    250,  24576},
    { 1, CameraBBH34,    -1939,   -204,   4340,    250,    200,    250,  24576},
    TABLE_EMPTY
};

struct Struct8032CA78 *TableLevelCinematicCamera[40] = {
    NULL,
    NULL,
    NULL,
    NULL,
    TableCameraBBH,
    TableCameraCCM,
    TableCameraInside,
    TableCameraHMC,
    TableCameraSSL,
    NULL,
    TableCameraSL,
    NULL,
    NULL,
    TableCameraTHI,
    NULL,
    TableCameraRR,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    TableCameraMetal,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

struct Struct8032E040 D_8032DDF0[23] = {
    {  0,   0, {  2122,   8762,   9114}},
    {  0,   0, {  2122,   8762,   9114}},
    {  1,   0, {  2122,   7916,   9114}},
    {  1,   0, {  2122,   7916,   9114}},
    {  2,   0, {   957,   5166,   8613}},
    {  3,   0, {   589,   4338,   7727}},
    {  4,   0, {   690,   3366,   6267}},
    {  5,   0, { -1600,   2151,   4955}},
    {  6,   0, { -1557,    232,   1283}},
    {  7,   0, { -6962,   -295,   2729}},
    {  8,   0, { -6979,    131,   3246}},
    {  9,   0, { -6360,   -283,   4044}},
    {  0,   0, { -5695,   -334,   5264}},
    {  1,   0, { -5568,   -319,   7933}},
    {  2,   0, { -3848,   -200,   6278}},
    {  3,   0, {  -965,   -263,   6092}},
    {  4,   0, {  1607,   2465,   6329}},
    {  5,   0, {  2824,    180,   3548}},
    {  6,   0, {  1236,    136,    945}},
    {  0,   0, {   448,    136,    564}},
    {  0,   0, {   448,    136,    564}},
    {  0,   0, {   448,    136,    564}},
    { -1,   0, {   448,    136,    564}}
};

struct Struct8032E040 D_8032DEA8[23] = {
    {  0,  50, {  1753,  29800,   8999}},
    {  0,  50, {  1753,  29800,   8999}},
    {  1,  50, {  1753,   8580,   8999}},
    {  1, 100, {  1753,   8580,   8999}},
    {  2,  50, {   520,   5400,   8674}},
    {  3,  50, {   122,   4437,   7875}},
    {  4,  50, {   316,   3333,   6538}},
    {  5,  36, { -1526,   2189,   5448}},
    {  6,  50, { -1517,    452,   1731}},
    {  7,  50, { -6659,   -181,   3109}},
    {  8,  17, { -6649,    183,   3618}},
    {  9,  20, { -6009,   -214,   4395}},
    {  0,  50, { -5258,   -175,   5449}},
    {  1,  36, { -5158,   -266,   7651}},
    {  2,  26, { -3351,   -192,   6222}},
    {  3,  25, {  -483,   -137,   6060}},
    {  4, 100, {  1833,   2211,   5962}},
    {  5,  26, {  3022,    207,   3090}},
    {  6,  20, {  1250,    197,    449}},
    {  7,  50, {   248,    191,    227}},
    {  7,   0, {    48,    191,    227}},
    {  7,   0, {    48,    191,    227}},
    { -1,   0, {    48,    191,    227}}
};

struct Struct8032E040 D_8032DF60[14] = {
    {  0,   0, {  -785,    625,   4527}},
    {  1,   0, {  -785,    625,   4527}},
    {  2,   0, { -1286,    644,   4376}},
    {  3,   0, { -1286,    623,   4387}},
    {  4,   0, { -1286,    388,   3963}},
    {  5,   0, { -1286,    358,   4093}},
    {  6,   0, { -1386,    354,   4159}},
    {  7,   0, { -1477,    306,   4223}},
    {  8,   0, { -1540,    299,   4378}},
    {  9,   0, { -1473,    316,   4574}},
    {  0,   0, { -1328,    485,   5017}},
    {  0,   0, { -1328,    485,   5017}},
    {  0,   0, { -1328,    485,   5017}},
    { -1,   0, { -1328,    485,   5017}}
};

struct Struct8032E040 D_8032DFD0[14] = {
    {  0,  20, { -1248,    450,   4596}},
    {  1,  59, { -1258,    485,   4606}},
    {  2,  59, { -1379,    344,   4769}},
    {  3,  20, { -1335,    366,   4815}},
    {  4,  23, { -1315,    370,   4450}},
    {  5,  40, { -1322,    333,   4591}},
    {  6,  25, { -1185,    329,   4616}},
    {  7,  21, { -1059,    380,   4487}},
    {  8,  14, { -1086,    421,   4206}},
    {  9,  21, { -1321,    346,   4098}},
    {  0,   0, { -1328,    385,   4354}},
    {  0,   0, { -1328,    385,   4354}},
    {  0,   0, { -1328,    385,   4354}},
    { -1,   0, { -1328,    385,   4354}}
};

struct Struct8032E040 D_8032E040[10] = {
    {  0,   0, {   -86,    876,    640}},
    {  1,   0, {   -86,    876,    610}},
    {  2,   0, {   -66,    945,    393}},
    {  3,   0, {   -80,    976,    272}},
    {  4,   0, {   -66,   1306,    -36}},
    {  5,   0, {   -70,   1869,   -149}},
    {  6,   0, {   -10,   2093,   -146}},
    {  7,   0, {   -10,   2530,   -248}},
    {  8,   0, {   -10,   2530,   -263}},
    {  9,   0, {   -10,   2530,   -273}}
};

struct Struct8032E040 D_8032E090[11] = {
    {  0,  50, {   -33,    889,     -7}},
    {  1,  35, {   -33,    889,     -7}},
    {  2,  31, {   -17,   1070,   -193}},
    {  3,  25, {   -65,   1182,   -272}},
    {  4,  20, {   -64,   1559,   -542}},
    {  5,  25, {   -68,   2029,   -677}},
    {  6,  25, {    -9,   2204,   -673}},
    {  7,  25, {    -8,   2529,   -772}},
    {  8,   0, {    -8,   2529,   -772}},
    {  9,   0, {    -8,   2529,   -772}},
    { -1,   0, {    -8,   2529,   -772}}
};

struct Struct8032E040 D_8032E0E8[20] = {
    {  0,  50, {     1,    120,  -1150}},
    {  1,  50, {     1,    120,  -1150}},
    {  2,  40, {   118,    121,  -1199}},
    {  3,  40, {   147,     74,  -1306}},
    {  4,  40, {   162,     95,  -1416}},
    {  5,  40, {    25,    111,  -1555}},
    {  6,  40, {  -188,    154,  -1439}},
    {  7,  40, {  -203,    181,  -1242}},
    {  8,  40, {     7,    191,  -1057}},
    {  9,  40, {   262,    273,  -1326}},
    {  0,  40, {    -4,    272,  -1627}},
    {  1,  35, {  -331,    206,  -1287}},
    {  2,  30, {   -65,    219,   -877}},
    {  3,  25, {     6,    216,   -569}},
    {  4,  25, {    -8,    157,     40}},
    {  5,  25, {    -4,    106,    200}},
    {  6,  25, {    -6,     72,    574}},
    {  7,   0, {    -6,     72,    574}},
    {  8,   0, {    -6,     72,    574}},
    { -1,   0, {    -6,     72,    574}}
};

struct Struct8032E040 D_8032E188[9] = {
    {  0,   0, {  -130,   1111,  -1815}},
    {  1,   0, {  -131,   1052,  -1820}},
    {  2,   0, {  -271,   1008,  -1651}},
    {  3,   0, {  -439,   1043,  -1398}},
    {  4,   0, {  -433,   1040,  -1120}},
    {  5,   0, {  -417,   1040,  -1076}},
    {  6,   0, {  -417,   1040,  -1076}},
    {  7,   0, {  -417,   1040,  -1076}},
    { -1,   0, {  -417,   1040,  -1076}}
};

struct Struct8032E040 D_8032E1D0[9] = {
    {  0,  50, {   -37,   1020,  -1332}},
    {  1,  20, {   -36,   1012,  -1330}},
    {  2,  20, {   -24,   1006,  -1215}},
    {  3,  20, {    28,   1002,  -1224}},
    {  4,  24, {    45,   1013,  -1262}},
    {  5,  35, {    34,   1000,  -1287}},
    {  6,   0, {    34,   1000,  -1287}},
    {  7,   0, {    34,   1000,  -1287}},
    { -1,   0, {    34,   1000,  -1287}}
};

struct Struct8032E040 D_8032E218[8] = {
    {  0,  50, {   200,   1066,  -1414}},
    {  0,  50, {   200,   1066,  -1414}},
    {  0,  30, {   198,   1078,  -1412}},
    {  0,  33, {    15,   1231,  -1474}},
    {  0,  39, {   -94,   1381,  -1368}},
    {  0,   0, {   -92,   1374,  -1379}},
    {  0,   0, {   -92,   1374,  -1379}},
    { -1,   0, {   -92,   1374,  -1379}}
};

struct Struct8032E040 D_8032E258[7] = {
    {  0,  50, {   484,   1368,   -888}},
    {  0,  72, {   479,   1372,   -892}},
    {  0,  50, {   351,   1817,   -918}},
    {  0,  50, {   351,   1922,   -598}},
    {  0,   0, {   636,   2027,   -415}},
    {  0,   0, {   636,   2027,   -415}},
    { -1,   0, {   636,   2027,   -415}}
};

s16 func_8028E88C(struct LevelCamera *a)
{
    s16 currLevelNum = gCurrLevelNum;
    s16 sp64;
    s8 sp63 = gCurrentArea->index;
    u32 sp5C;
    Vec3f sp50, sp44;
    u32 sp40 = 0;
    UNUSED struct Struct8032CA78 sp28;
    u8 sp27 = a->preset;
    
    if (a->preset == CAMERA_PRESET_C_UP_LOOK)
        a->preset = (u8)D_8033B418.unk2;
    func_8028D32C(&a->preset);
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
                case SURFACE_0069:
                    func_80285AD8(a, 14, 90);
                    D_8033B406 = 0x4000;
                    break;
                    
                case SURFACE_0065:
                    if (gCurrActNum == 1)
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
                if (D_8033B278.unk8 == SURFACE_0065)
                    func_8028CFFC(a);
                else
                {
                    if (a->preset == CAMERA_PRESET_CLOSE)
                        func_80285AD8(a, 1, 60);
                    else
                        func_8028D098(a, 60);
                }
            }
            break;
            
        case 177:
            if (D_8033B278.unk8 == SURFACE_INSTANT_WARP_0)
            {
                if (0) {}
                a->unk1 = 1;
                if (0) {}
            }
            break;
            
        case 178:
            if (D_8033B278.unk8 == SURFACE_001C)
            {
                if (0) {}
                a->unk1 = 4;
                if (0) {}
            }
            break;
            
        case 369:
            D_8033B328.unk3D = 2;
            break;
            
        case 370:
            if ((a->preset != CAMERA_PRESET_SECRET_AQUARIUM) && (a->preset != CAMERA_PRESET_UNDERWATER))
            {
                if (((D_8032D000->unk0 & 0x00100000) != 0) || (D_8033B278.unk4 > 800.f))
                    func_80285AD8(a, 14, 60);
                
                else
                {
                    if (D_8032D000->unk4[1] < 800.f)
                        func_80285AD8(a, 16, 60);
                }
            }
            D_8033B328.unk3D = 16;
            break;
        }
    }
    
    D_8033B4DA &= ~0x1000;
    if (sp27 == 6)
    {
        D_8033B418.unk2 = a->preset;
        a->preset = sp27;
    }
    sp64 = a->preset;
    return sp64;
}

void func_8028F04C(Vec3f a, UNUSED Vec3f b)
{
    f32 ceilY, floorY;
    struct Surface *sp24;
    
    resolve_wall_collisions(&a[0], &a[1], &a[2], 0.f, 100.f);
    floorY = find_floor(a[0], a[1] + 50.f, a[2], &sp24);
    ceilY =  find_ceil(a[0], a[1] - 50.f, a[2], &sp24);
    
    if ((-11000.f != floorY) && (20000.f == ceilY))
    {
        if (a[1] < (floorY += 125.f))
            a[1] = floorY;
    }
    
    if ((-11000.f == floorY) && (20000.f != ceilY))
    {
        if (a[1] > (ceilY -= 125.f))
            a[1] = ceilY;
    }
    
    if ((-11000.f != floorY) && (20000.f != ceilY))
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
    
s32 func_8028F2F0(struct LevelCamera *a, Vec3f b, s16 *c, s16 d)
{
    UNUSED f32 sp84;
    struct WallCollisionData sp5C;
    struct Surface *sp58;
    UNUSED Vec3f sp4C;
    f32 sp48, sp44;
    UNUSED f32 sp40;
    f32 sp3C, sp38;
    s16 sp36, sp34;
    UNUSED s16 sp32;
    s16 sp30, sp2E;
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
                    sp36 = atan2s(sp58->normal.z, sp58->normal.x) + 0x4000;
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
                sp34 = atan2s(sp58->normal.z, sp58->normal.x);
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
    
    if (find_floor(D_8032D000->unk4[0], D_8032D000->unk4[1] + 10.f, D_8032D000->unk4[2], &sp1C) != -11000.f)
        a->unk8 = sp1C->type;
    else
        a->unk8 = 0;
    
    if (find_ceil(D_8032D000->unk4[0], D_8032D000->unk4[1] - 10.f, D_8032D000->unk4[2], &sp1C) != 20000.f)
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
    D_8033B858 = FALSE;
}

u8 func_8028F834(u8 a)
{
    D_8032CFF0 = a;
    D_8032CFFC = 0;
    return 0;
}

static u8 unused_8028F860(u8 a)
{
    if ((gCurrLevelCamera->unk30 == 0) && (D_8032CFF0 == 0))
        D_8032CFF0 = a;
    
    if ((gCurrLevelCamera->unk30 == a) && (D_8032CFFC != 0))
        return D_8032CFFC;
    else
        return 0;
}

s16 func_8028F8E0(u8 a, struct Object *b, s16 c)
{
    s16 sp1E = 0;
    
    if ((gCurrLevelCamera->unk30 == 0) && (D_8032CFF0 == 0))
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
    
    if ((gCurrLevelCamera->unk30 == 0) && (D_8032CFF0 == 0))
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

void func_8028FA74(struct LevelCamera *a)
{
    a->unk3A = func_8028A4F0(a->unk4, a->unk10);
    a->angle = a->unk3A;
}

void func_8028FABC(void)
{
    D_8033B6E0 = 0;
    D_8033B6E4 = 0;
}

void func_8028FAE0(struct LevelCamera *a)
{
    gCutsceneTimer = 0x8000;
    a->unk30 = 0;
    vec3f_copy(a->unk4, D_8033B4B8.unkC);
    vec3f_copy(a->unk10, D_8033B4B8.unk0);
}

void func_8028FB44(s16 dummy)
{
    UNUSED s16 sp1E = dummy;
    save_file_do_save(gCurrSaveFileNum - 1);
}

void func_8028FB80(struct Struct8032E040 *a, s8 b, u8 c, Vec3s d)
{
    a->unk0 = b;
    a->unk1 = c;
    vec3s_copy(a->unk2, d);
}

void func_8028FBD8(struct Struct8032E040 a[], struct Struct8032E040 b[])
{
    s32 sp24 = 0;
    s32 sp20 = 0;
    UNUSED s32 pad[2];
    
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
    s16 timer = gCutsceneTimer;
    if (set_mario_npc_dialogue(a) == 2)
        timer = 0x7FFF;
    return timer;
}

static void unused_8028FDE8(UNUSED struct LevelCamera *a)
{
    gCutsceneTimer = func_8028FD94(3);
}

void Cutscene26Todo0(UNUSED struct LevelCamera *a)
{
    gCutsceneTimer = func_8028FD94(1);
}

static void unused_8028FE50(UNUSED struct LevelCamera *a)
{
    gCutsceneTimer = func_8028FD94(2);
}

static void CutsceneIntroPeach0_2(UNUSED struct LevelCamera *a)
{
#if VERSION_US
    func_8031FFB4(0, 60, 40);
#endif
    func_8028B13C();
}

static void CutsceneIntroPeach2_1(UNUSED struct LevelCamera *a)
{
#if VERSION_US
    func_80320040(0, 60);
#endif
    func_8028B16C();
}

void func_8028FEDC(UNUSED struct LevelCamera *a)
{
    D_8033B40C = 0.f;
}

void func_8028FEFC(struct LevelCamera *a, s16 b, s16 c, s16 d, s16 e)
{
    f32 sp2C;
    s16 sp2A, sp28, sp26;

    approach_s16_exponential(&D_8033B226, -(s16)(gPlayer2Controller->stickX * 250.f), 4);
    approach_s16_exponential(&D_8033B224, -(s16)(gPlayer2Controller->stickY * 265.f), 4);
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

void func_80290144(struct LevelCamera *a)
{
    vec3f_copy(D_8033B4B8.unk0, a->unk10);
    vec3f_copy(D_8033B4B8.unkC, a->unk4);
    D_8033B4B8.unk18 = D_8033B40C;
    D_8033B4B8.unk1C = D_8033B410;
}

void func_802901B4(struct LevelCamera *a)
{
    vec3f_copy(a->unk10, D_8033B4B8.unk0);
    vec3f_copy(a->unk4, D_8033B4B8.unkC);
    D_8033B40C = D_8033B4B8.unk18;
    D_8033B410 = D_8033B4B8.unk1C;
}

void func_80290224(struct LevelCamera *a)
{
    func_8028FEDC(a);
    vec3f_copy(D_8033B4B8.unk0, a->unk10);
    D_8033B4B8.unkC[0] = D_8032D000->unk4[0];
    D_8033B4B8.unkC[1] = a->unk4[1];
    D_8033B4B8.unkC[2] = D_8032D000->unk4[2];
}

void func_802902A8(struct LevelCamera *a)
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

void func_80290390(struct LevelCamera *a, s16 b, s16 c)
{
    UNUSED Vec3f sp2C;
    f32 sp28;
    s16 sp26, sp24;
    UNUSED f32 sp20;
    
    vec3f_get_dist_and_angle(a->unk10, a->unk4, &sp28, &sp26, &sp24);
    sp26 += b;
    sp24 += c;
    vec3f_set_dist_and_angle(a->unk10, a->unk4, sp28, sp26, sp24);
}

void CutsceneEnterSomething8029041C(UNUSED struct LevelCamera *a)
{
    func_8027F308(1);
    func_8029A494(1);
}

static void unused_80290450(UNUSED struct LevelCamera *a)
{
    func_8027F308(2);
}

void func_8029047C(Vec3f a, Vec3f b, f32 c, s16 d, s16 e)
{
    f32 sp24;
    s16 sp22, sp20;
    
    vec3f_get_dist_and_angle(b, a, &sp24, &sp22, &sp20);
    sp22 += d;
    sp20 += e;
    sp24 += c;
    vec3f_set_dist_and_angle(b, a, sp24, sp22, sp20);
}

void func_80290514(struct LevelCamera *a)
{
    D_8033B4DA |= 0x8000;
    D_8033B2B0 = func_8028A4F0(a->unk4, a->unk10);
}

void func_80290564(UNUSED struct LevelCamera *a)
{
    func_8031FFB4(0, 60, 40);
}

void func_80290598(UNUSED struct LevelCamera *a)
{
    func_80320040(0, 60);
}

static void unused_802905C8(UNUSED struct LevelCamera *a)
{
}

void Cutscene0FTodo0(UNUSED struct LevelCamera *a)
{
}

void Cutscene0FTodo1(UNUSED struct LevelCamera *a)
{
}

static void CutscenePeachEnd0_1(struct LevelCamera *a)
{
    vec3f_set(a->unk4, -26.f, 0.f, -137.f);
    vec3f_set(a->unk10, 165.f, 4725.f, 324.f);
}

static void CutscenePeachEnd0_2(struct LevelCamera *a)
{
    Vec3f sp24;
    vec3f_set(sp24, 0.f, 80.f, 0.f);
    
    sp24[2] = ABS(D_8032D000->unk4[1] - a->unk10[1]) * -0.1f;
    if (sp24[2] > -100.f)
        sp24[2] = -100.f;
    
    func_8028C5F0(a->unk4, D_8032D000->unk4, sp24, D_8032D000->unk10);
}

void CutscenePeachEnd0(struct LevelCamera *a)
{
    call_cutscene_func_in_time_range(CutscenePeachEnd0_1, a, 0, 0);
    call_cutscene_func_in_time_range(CutscenePeachEnd0_2, a, 0, -1);
    func_8028FEFC(a, -0x2000, 0x2000, -0x2000, 0x2000);
}

void CutscenePeachEnd2(struct LevelCamera *a)
{
    vec3f_set(a->unk4, 85.f, 826.f, 250.f);
    vec3f_set(a->unk10, -51.f, 988.f, -202.f);
    func_8028FEFC(a, -0x2000, 0x2000, -0x2000, 0x2000);
}

static void CutscenePeachEndCommon367A(UNUSED struct LevelCamera *a)
{
    D_8033B6F0[9].unk4[0] = 0.f;
    func_8028FABC();
}

static void CutscenePeachEnd3_1(struct LevelCamera *a)
{
    func_80287CFC(a->unk10, D_8032E040, &D_8033B6E0, &D_8033B6E4);
    func_80287CFC(a->unk4, D_8032E090, &D_8033B6E0, &D_8033B6E4);
}

void CutscenePeachEnd3(struct LevelCamera *a)
{
    call_cutscene_func_in_time_range(CutscenePeachEndCommon367A, a, 0, 0);
    call_cutscene_func_in_time_range(CutscenePeachEnd3_1, a, 0, -1);
    func_8028FEFC(a, -0x2000, 0x2000, -0x2000, 0x2000);
}

void CutscenePeachEnd1(struct LevelCamera *a)
{
    vec3f_set(a->unk4, D_8032E090[0].unk2[0], D_8032E090[0].unk2[1] + 80.f, D_8032E090[0].unk2[2]);
    vec3f_set(a->unk10, D_8032E040[0].unk2[0], D_8032E040[0].unk2[1], D_8032E040[0].unk2[2] + 150.f);
    func_8028FEFC(a, -0x800, 0x2000, -0x2000, 0x2000);
}

static void CutscenePeachEnd4_1(struct LevelCamera *a)
{
    vec3f_set(a->unk10, 179.f, 2463.f, -1216.f);
    a->unk10[1] = D_8032CFC4->oPosY + 35.f;
    vec3f_set(a->unk4, D_8032CFC4->oPosX, D_8032CFC4->oPosY + 125.f, D_8032CFC4->oPosZ);
}

void CutscenePeachEnd4(struct LevelCamera *a)
{
    call_cutscene_func_in_time_range(CutscenePeachEnd4_1, a, 0, 0);
    approach_f32_exponential(&a->unk10[1], D_8032CFC4->oPosY + 35.f, 0.02f);
    approach_f32_exponential(&a->unk4[1], D_8032CFC4->oPosY + 125.f, 0.15f);
    func_8028FEFC(a, -0x2000, 0x2000, -0x2000, 0x2000);
}

static void CutscenePeachEnd5_1(UNUSED struct LevelCamera *a)
{
    func_8028FABC();
    D_8033B6F0[2].unk4[1] = 150.f;
}

static void CutscenePeachEnd5_2(struct LevelCamera *a)
{
    func_80287CFC(a->unk10, D_8032E0E8, &D_8033B6E0, &D_8033B6E4);
    a->unk10[1] += D_8032CFC4->oPosY + D_8033B6F0[3].unk4[1];
}

static void CutscenePeachEnd5_3(UNUSED struct LevelCamera *a)
{
    func_802893E4(&(D_8033B6F0[2].unk4[1]), 90.f, 0.5f);
}

static void CutscenePeachEnd5_4(struct LevelCamera *a)
{
    Vec3f sp1C;
    
    func_80287CFC(sp1C, D_8032E0E8, &D_8033B6E0, &D_8033B6E4);
    a->unk10[0] = sp1C[0];
    a->unk10[2] = sp1C[2];
    approach_f32_exponential(&a->unk10[1], (sp1C[1] += D_8032CFC4->oPosY), 0.07f);
}

void CutscenePeachEnd5(struct LevelCamera *a)
{
    call_cutscene_func_in_time_range(CutscenePeachEnd5_1, a, 0, 0);
    call_cutscene_func_in_time_range(CutscenePeachEnd5_2, a, 0, 299);
    call_cutscene_func_in_time_range(CutscenePeachEnd5_4, a, 300, -1);
    call_cutscene_func_in_time_range(CutscenePeachEnd5_3, a, 300, -1);
    vec3f_set(a->unk4, D_8032CFC4->oPosX, D_8033B6F0[2].unk4[1] + D_8032CFC4->oPosY, D_8032CFC4->oPosZ);
    func_8028FEFC(a, -0x2000, 0x2000, -0x2000, 0x2000);
}

void CutscenePeachEnd6(struct LevelCamera *a)
{
    call_cutscene_func_in_time_range(CutscenePeachEndCommon367A, a, 0, 0);
    func_80287CFC(a->unk10, D_8032E188, &D_8033B6E0, &D_8033B6E4);
    func_80287CFC(a->unk4, D_8032E1D0, &D_8033B6E0, &D_8033B6E4);
    func_8028FEFC(a, -0x2000, 0x2000, -0x2000, 0x2000);
}

static void CutscenePeachEnd7_1(UNUSED struct LevelCamera *a)
{
    func_80287CFC(a->unk4, D_8032E218, &D_8033B6E0, &D_8033B6E4);
}

void CutscenePeachEnd7(struct LevelCamera *a)
{
    call_cutscene_func_in_time_range(CutscenePeachEndCommon367A, a, 0, 0);
    call_cutscene_func_in_time_range(CutscenePeachEnd7_1, a, 0, 0);
    call_cutscene_func_in_time_range(CutscenePeachEnd7_1, a, 250, -1);
    func_80299C60(7, 300);
    func_80299C60(9, 340);
    vec3f_set(a->unk10, -163.f, 978.f, -1082.f);
    func_8028FEFC(a, -0x800, 0x2000, -0x2000, 0x2000);
}

void CutscenePeachEnd8(struct LevelCamera *a)
{
    vec3f_set(a->unk4, 11.f, 983.f, -1273.f);
    vec3f_set(a->unk10, -473.f, 970.f, -1152.f);
    func_8028FEFC(a, -0x800, 0x2000, -0x2000, 0x2000);
}

static void CutscenePeachEnd9_1(struct LevelCamera *a)
{
    func_8029A478(13);
    vec3f_set(a->unk4, 350.f, 1034.f, -1216.f);
    vec3f_set(a->unk10, -149.f, 1021.f, -1216.f);
}

static void CutscenePeachEnd9_2(struct LevelCamera *a)
{
    Vec3f sp2C, sp20;
    
    func_8029A478(2);
    vec3f_set(sp20, 233.f, 1068.f, -1298.f);
    vec3f_set(sp2C, -250.f, 966.f, -1111.f);
    approach_vec3f_exponential(a->unk10, sp2C, 0.2f, 0.1f, 0.2f);
    approach_vec3f_exponential(a->unk4, sp20, 0.2f, 0.1f, 0.2f);
}

void CutscenePeachEnd9(struct LevelCamera *a)
{
    call_cutscene_func_in_time_range(CutscenePeachEnd9_1, a, 0, 0);
    call_cutscene_func_in_time_range(CutscenePeachEnd9_2, a, 155, -1);
    func_8028FEFC(a, -0x800, 0x2000, -0x2000, 0x2000);
}

static void CutscenePeachEndA_1(struct LevelCamera *a)
{
    func_80287CFC(a->unk4, D_8032E258, &D_8033B6E0, &D_8033B6E4);
    vec3f_set(a->unk10, 699.f, 1680.f, -703.f);
}

static void CutscenePeachEndA_2(UNUSED struct LevelCamera *a)
{
    D_8033B230.fieldOfView = 37.f;
}

void CutscenePeachEndA(struct LevelCamera *a)
{
    call_cutscene_func_in_time_range(CutscenePeachEndCommon367A, a, 0, 0);
    call_cutscene_func_in_time_range(CutscenePeachEndA_1, a, 0, 0);
    call_cutscene_func_in_time_range(CutscenePeachEndA_2, a, 0, 499);
    call_cutscene_func_in_time_range(CutscenePeachEndA_1, a, 500, -1);
    func_80299C60(8, 600);
    func_80299C60(8, 608);
    func_80299C60(8, 624);
    func_80299C60(8, 710);
}

void CutscenePeachEndB(struct LevelCamera *a)
{
    func_8029A478(1);
    a->unk30 = 0;
    gCutsceneTimer = -0x8000;
}

static void CutsceneGrandStar0_1(UNUSED struct LevelCamera *a)
{
    vec3f_set(D_8033B6F0[0].unk4, 0.f, 150.f, -600.f);
    func_8028C5F0(D_8033B6F0[1].unk4, D_8032D000->unk4, D_8033B6F0[0].unk4, D_8032D000->unk10);
    D_8033B6F0[1].unk4[1] = 457.f;
}

static void CutsceneGrandStar0_2(struct LevelCamera *a)
{
    f32 sp2C;
    s16 sp2A, sp28;
    f32 sp24;
    s16 sp22, sp20;
    
    vec3f_get_dist_and_angle(D_8032D000->unk4, D_8033B6F0[1].unk4, &sp2C, &sp2A, &sp28);
    vec3f_get_dist_and_angle(D_8032D000->unk4, a->unk10, &sp24, &sp22, &sp20);
    approach_f32_exponential(&sp24, sp2C, 0.1f);
    approach_s16_exponential(&sp22, sp2A, 32);
    approach_s16_exponential(&sp20, sp28 + 0x1200, 20);
    vec3f_set_dist_and_angle(D_8032D000->unk4, a->unk10, sp24, sp22, sp20);
}

static void CutsceneGrandStar0_4(UNUSED struct LevelCamera *a)
{
    vec3s_set(D_8033B6F0[0].unk1C, 0, D_8032D000->unk10[1], 0);
    vec3f_set(D_8033B6F0[2].unk4, 0.f, 0.f, 0.f);
}

static void CutsceneGrandStar0_5(UNUSED struct LevelCamera *a)
{
    func_802893E4(&D_8033B6F0[2].unk4[2], -40.f, 2.0f);
    D_8033B6F0[2].unk4[0] = 5.0f;
}

static void CutsceneGrandStar0_6(struct LevelCamera *a)
{
    func_802893E4(&D_8033B6F0[2].unk4[2], 0.f, 2.f);
    D_8033B6F0[2].unk4[0] = 0.f;
    approach_f32_exponential(&a->unk10[0], D_8032D000->unk4[0], 0.01f);
    approach_f32_exponential(&a->unk10[2], D_8032D000->unk4[2], 0.01f);
}

static void CutsceneGrandStar0_7(struct LevelCamera *a)
{
    func_8028C5F0(a->unk10, a->unk10, D_8033B6F0[2].unk4, D_8033B6F0[0].unk1C);
}

static void CutsceneGrandStar0_3(struct LevelCamera *a)
{
    Vec3f sp24;
    
    vec3f_set(sp24, D_8032D000->unk4[0], (D_8032D000->unk4[1] - 307.f) * 0.5f + 407.f, D_8032D000->unk4[2]);
    approach_vec3f_exponential(a->unk4, sp24, 0.5f, 0.8f, 0.5f);
}

void CutsceneGrandStar0(struct LevelCamera *a)
{
    D_8033B4DA |= 1;
    call_cutscene_func_in_time_range(CutsceneGrandStar0_1, a, 0, 0);
    call_cutscene_func_in_time_range(CutsceneGrandStar0_2, a, 0, 109);
    call_cutscene_func_in_time_range(CutsceneGrandStar0_3, a, 0, -1);
    call_cutscene_func_in_time_range(CutsceneGrandStar0_4, a, 110, 110);
    call_cutscene_func_in_time_range(CutsceneGrandStar0_5, a, 110, 159);
    call_cutscene_func_in_time_range(CutsceneGrandStar0_6, a, 160, -1);
    call_cutscene_func_in_time_range(CutsceneGrandStar0_7, a, 110, -1);
}

static void CutsceneGrandStar1_1(struct LevelCamera *a)
{
    vec3f_set(D_8033B6F0[7].unk4, 0.5f, 0.5f, 0.5f);
    vec3f_set(D_8033B6F0[6].unk4, 0.01f, 0.01f, 0.01f);
    vec3f_set(D_8033B6F0[4].unk4, 0.f, 0.f, 0.f);
    vec3f_set(D_8033B6F0[5].unk4, 0.f, a->unk4[1] - D_8032D000->unk4[1], 0.f);
    D_8033B6F0[8].unk4[2] = 0.f;
    D_8033B6F0[8].unk4[0] = 0.f;
}

static void CutsceneGrandStar1_2(UNUSED struct LevelCamera *a)
{
    Vec3f sp24;
    
    vec3f_set(sp24, -600.f, 0.f, -400.f);
    approach_vec3f_exponential(D_8033B6F0[4].unk4, sp24, 0.05f, 0.05f, 0.05f);
    func_802893E4(&D_8033B6F0[5].unk4[1], 0.f, 2.f);
    func_802893E4(&D_8033B6F0[5].unk4[2], -200.f, 6.f);
}

static void CutsceneGrandStar1_3(UNUSED struct LevelCamera *a)
{
    func_802893E4(&D_8033B6F0[8].unk4[0], 15.f, 0.1f);
    
    func_802893E4(&D_8033B6F0[4].unk4[0], -2000.f, D_8033B6F0[8].unk4[0]);
    func_802893E4(&D_8033B6F0[4].unk4[1], 1200.f, D_8033B6F0[8].unk4[0] / 10.f);
    func_802893E4(&D_8033B6F0[4].unk4[2], 1000.f, D_8033B6F0[8].unk4[0] / 10.f);
    
    func_802893E4(&D_8033B6F0[5].unk4[0], 0.f, D_8033B6F0[8].unk4[0]);
    func_802893E4(&D_8033B6F0[5].unk4[1], 1200.f, D_8033B6F0[8].unk4[0] / 2.f);
    func_802893E4(&D_8033B6F0[5].unk4[2], 1000.f, D_8033B6F0[8].unk4[0] / 1.5f);
}

static void CutsceneGrandStar1_4(struct LevelCamera *a)
{
    Vec3f sp34, sp28;
    f32 sp24;
    s16 sp22, sp20;
    
    func_802893E4(&D_8033B6F0[8].unk4[2], 90.f, 2.5f);
    func_8028C5F0(sp34, D_8032D000->unk4, D_8033B6F0[4].unk4, D_8032D000->unk10);
    func_8028C5F0(sp28, D_8032D000->unk4, D_8033B6F0[5].unk4, D_8032D000->unk10);
    
    vec3f_get_dist_and_angle(sp34, a->unk10, &sp24, &sp22, &sp20);
    func_802893E4(&sp24, 0, D_8033B6F0[8].unk4[2]);
    vec3f_set_dist_and_angle(sp34, a->unk10, sp24, sp22, sp20);
    
    approach_vec3f_exponential(a->unk10, sp34, 0.01f, 0.01f, 0.01f);
    approach_vec3f_exponential(a->unk4, sp28, 0.5f, 0.8f, 0.5f);
}

void CutsceneGrandStar1(struct LevelCamera *a)
{
    D_8033B4DA |= 1;
    call_cutscene_func_in_time_range(CutsceneGrandStar1_1, a, 0, 0);
    call_cutscene_func_in_time_range(CutsceneGrandStar1_2, a, 0, 140);
    call_cutscene_func_in_time_range(CutsceneGrandStar1_3, a, 141, -1);
    call_cutscene_func_in_time_range(CutsceneGrandStar1_4, a, 0, -1);
}

void func_80291BBC(struct LevelCamera *a, f32 b, f32 c)
{
    Vec3f sp2C, sp20;
    
    sp20[0] = 0.f;
    sp20[2] = b;
    sp20[1] = 100.f;
    
    func_8028C5F0(sp2C, D_8032D000->unk4, sp20, D_8032D000->unk10);
    approach_vec3f_exponential(a->unk4, sp2C, c, c, c);
}

static void CutsceneDanceCommon(struct LevelCamera *a)
{
    s16 sp26, sp24;
    f32 sp20;
    
    vec3f_get_dist_and_angle(D_8032D000->unk4, a->unk10, &sp20, &sp26, &sp24);
    approach_f32_exponential(&sp20, 600.f, 0.3f);
    approach_s16_exponential(&sp26, 0x1000, 0x10);
    vec3f_set_dist_and_angle(D_8032D000->unk4, a->unk10, sp20, sp26, sp24);
}

static void CutsceneStarDance1_4(struct LevelCamera *a)
{
    func_8029047C(a->unk10, D_8032D000->unk4, 0, 0, 0x200);
}

static void CutsceneStarDance1_5(struct LevelCamera *a)
{
    func_8029047C(a->unk10, D_8032D000->unk4, -15.f, 0, 0);
}

static void CutsceneStarDance1_6(struct LevelCamera *a)
{
    func_8029047C(a->unk10, D_8032D000->unk4, 20.f, 0, 0);
}

static void dummy_80291DC0(UNUSED struct LevelCamera *a)
{
}

static void CutsceneStarDance1_1(struct LevelCamera *a)
{
    func_80291BBC(a, -100.f, 0.2f);
}

static void CutsceneStarDance1_3(struct LevelCamera *a)
{
    func_80291BBC(a, -200.f, 0.03f);
}

static void CutsceneStarDance1_2(UNUSED struct LevelCamera *a)
{
    func_80299C98(0x200, 40, -0x8000);
}

void CutsceneStarDance1(struct LevelCamera *a)
{
    D_8033B4DA |= 1;
    D_8032CFD4 = 0;
    func_8029A478(2);
    call_cutscene_func_in_time_range(CutsceneStarDance1_1, a, 0, 20);
    call_cutscene_func_in_time_range(CutsceneDanceCommon, a, 0, 39);
    call_cutscene_func_in_time_range(CutsceneStarDance1_2, a, 40, 40);
    if (a->unk30 != 175)
    {
        call_cutscene_func_in_time_range(CutsceneStarDance1_3, a, 75, 102);
        call_cutscene_func_in_time_range(CutsceneStarDance1_4, a, 50, -1);
        call_cutscene_func_in_time_range(CutsceneStarDance1_5, a, 50, 80);
        call_cutscene_func_in_time_range(CutsceneStarDance1_6, a, 70, 90);
    }
    else
    {
        if ((D_8032D000->unk0 != ACT_STAR_DANCE_NO_EXIT) && (D_8032D000->unk0 != ACT_STAR_DANCE_WATER) && (D_8032D000->unk0 != ACT_STAR_DANCE_EXIT))
        {
            gCutsceneTimer = 0x8000;
            a->unk30 = 0;
            func_80285A8C(a, 20);
            D_8033B4DA |= 0x4000;
        }
    }
}

void func_80291FE8(struct LevelCamera *a, s16 b, s16 c)
{
    s16 sp2E, sp2C;
    f32 sp28;
    s16 sp26;
    
    vec3f_get_dist_and_angle(D_8032D000->unk4, a->unk10, &sp28, &sp2E, &sp2C);
    sp26 = sp2C - b;
    
    if ((sp26 & 0x8000) != 0)
    {
        sp26 = -sp26;
    }
    if (sp26 > c)
    {
        sp2C = b;
        a->unk3A = sp2C;
        a->angle = sp2C;
    }
}

static void CutsceneStarDance3_1(struct LevelCamera *a)
{
    UNUSED u32 pad[2];
    
    if ((D_8032CE24 == 4) && (gCurrCourseNum == COURSE_JRB))
        func_80291FE8(a, 0, 0x4000);
    if ((D_8032CE24 == 1) && (gCurrCourseNum == COURSE_DDD))
        func_80291FE8(a, 0x8000, 0x5000);
    if ((D_8032CE24 == 5) && (gCurrCourseNum == COURSE_WDW))
        func_80291FE8(a, 0x8000, 0x800);
    
    vec3f_copy(D_8033B6F0[9].unk4, a->unk4);
    D_8033B6F0[8].unk1C[0] = 0x2000;
}

static void CutsceneStarDance3_2(struct LevelCamera *a)
{
    Vec3f sp24;
    
    vec3f_set(sp24, D_8032D000->unk4[0], D_8032D000->unk4[1] + 125.f, D_8032D000->unk4[2]);
    approach_vec3f_exponential(D_8033B6F0[9].unk4, sp24, 0.2f, 0.2f, 0.2f);
    vec3f_copy(a->unk4, D_8033B6F0[9].unk4);
}

static void CutsceneStarDance3_3(struct LevelCamera *a)
{
    s16 sp2E, sp2C;
    f32 sp28;
    s16 sp26 = 0x1800;
    
    if (((D_8032CE24 == 6) && (gCurrCourseNum == COURSE_SL)) || ((D_8032CE24 == 4) && (gCurrCourseNum == COURSE_TTC)))
        sp26 = 0x800;
    
    vec3f_get_dist_and_angle(D_8032D000->unk4, a->unk10, &sp28, &sp2E, &sp2C);
    approach_f32_exponential(&sp28, 800.f, 0.05f);
    approach_s16_exponential(&sp2E, sp26, 16);
    approach_s16_exponential(&sp2C, a->angle, 8);
    vec3f_set_dist_and_angle(D_8032D000->unk4, a->unk10, sp28, sp2E, sp2C);
}

static void CutsceneStarDance3_4(struct LevelCamera *a)
{
    s16 sp26, sp24;
    f32 sp20;
    
    vec3f_get_dist_and_angle(D_8032D000->unk4, a->unk10, &sp20, &sp26, &sp24);
    approach_f32_exponential(&sp20, 240.f, 0.4f);
    approach_s16_exponential(&sp24, a->angle, 8);
    approach_s16_exponential(&sp26, 0x1000, 5);
    vec3f_set_dist_and_angle(D_8032D000->unk4, a->unk10, sp20, sp26, sp24);
}

static void CutsceneStarDance3_5(UNUSED struct LevelCamera *a)
{
    func_8029A478(9);
}

static void CutsceneStarDance3_6(UNUSED struct LevelCamera *a)
{
    func_80299C98(0x300, 48, -0x8000);
}

void CutsceneStarDance3(struct LevelCamera *a)
{
    D_8033B4DA |= 1;
    
    if (D_8032D000->unk0 == ACT_STAR_DANCE_WATER)
    {
        call_cutscene_func_in_time_range(CutsceneStarDance3_1, a, 0, 0);
        call_cutscene_func_in_time_range(CutsceneStarDance3_2, a, 0, -1);
        call_cutscene_func_in_time_range(CutsceneStarDance3_3, a, 0, 62);
        call_cutscene_func_in_time_range(CutsceneStarDance3_4, a, 63, -1);
        call_cutscene_func_in_time_range(CutsceneStarDance3_5, a, 63, 63);
        call_cutscene_func_in_time_range(CutsceneStarDance3_6, a, 70, 70);
    }
    else
    {
        call_cutscene_func_in_time_range(CutsceneStarDance3_1, a, 0, 0);
        call_cutscene_func_in_time_range(CutsceneStarDance3_2, a, 0, -1);
        call_cutscene_func_in_time_range(CutsceneStarDance3_3, a, 0, 32);
        call_cutscene_func_in_time_range(CutsceneStarDance3_4, a, 33, -1);
        call_cutscene_func_in_time_range(CutsceneStarDance3_5, a, 33, 33);
        call_cutscene_func_in_time_range(CutsceneStarDance3_6, a, 40, 40);
    }
    func_802882A0(1);
}

static void CutsceneStarDance2_1(struct LevelCamera *a)
{
    Vec3f sp1C;
    
    vec3f_copy(D_8033B6F0[9].unk4, a->unk4);
    D_8033B6F0[8].unk4[2] = 65.f;
    
    if (a->preset == CAMERA_PRESET_OPEN_CAMERA)
    {
        vec3f_set(sp1C, a->unk28, a->unk68, a->unk2C);
        a->angle = func_8028A4F0(sp1C, a->unk10);
        a->unk3A = a->angle;
    }
    
    if ((D_8032CE24 == 6) && (gCurrCourseNum == COURSE_CCM))
        func_80291FE8(a, 0x5600, 0x800);
    if ((D_8032CE24 == 2) && (gCurrCourseNum == COURSE_TTM))
        func_80291FE8(a, 0, 0x800);
    if ((D_8032CE24 == 1) && (gCurrCourseNum == COURSE_SL))
        func_80291FE8(a, 0x2000, 0x800);
    if ((D_8032CE24 == 3) && (gCurrCourseNum == COURSE_RR))
        func_80291FE8(a, 0, 0x800);
}

static void CutsceneStarDance2_3(struct LevelCamera *a)
{
    s16 sp26, sp24;
    f32 sp20;
    
    vec3f_get_dist_and_angle(D_8032D000->unk4, a->unk10, &sp20, &sp26, &sp24);
    approach_f32_exponential(&sp20, 600.f, 0.3f);
    approach_s16_exponential(&sp26, 0x1000, 16);
    approach_s16_exponential(&sp24, a->angle, 8);
    vec3f_set_dist_and_angle(D_8032D000->unk4, a->unk10, sp20, sp26, sp24);
}

static void CutsceneStarDance2_2(struct LevelCamera *a)
{
    Vec3f sp24;
    
    vec3f_set(sp24, D_8032D000->unk4[0], D_8032D000->unk4[1] + 125.f, D_8032D000->unk4[2]);
    approach_vec3f_exponential(D_8033B6F0[9].unk4, sp24, 0.2f, 0.2f, 0.2f);
    vec3f_copy(a->unk4, D_8033B6F0[9].unk4);
}

void func_80292884(struct LevelCamera *a)
{
    vec3f_copy(a->unk4, D_8033B6F0[9].unk4);
    D_8033B6F0[9].unk1C[0] -= 29;
    D_8033B6F0[9].unk1C[1] += 29;
    func_80290390(a, D_8033B6F0[9].unk1C[0], D_8033B6F0[9].unk1C[1]);
}

static void CutsceneStarDance2_4(struct LevelCamera *a)
{
    func_80292884(a);
    func_8029047C(a->unk10, D_8032D000->unk4, D_8033B6F0[8].unk4[2], 0, 0);
}

static void CutsceneStarDance2_5(struct LevelCamera *a)
{
    func_8029047C(a->unk10, D_8032D000->unk4, 0, 0, 0x80);
}

static void CutsceneStarDance2_6(UNUSED struct LevelCamera *a)
{
    func_80299C98(0x400, 48, -0x8000);
}

void CutsceneStarDance2(struct LevelCamera *a)
{
    D_8033B4DA |= 1;
    call_cutscene_func_in_time_range(CutsceneStarDance2_1, a, 0, 0);
    call_cutscene_func_in_time_range(CutsceneStarDance2_2, a, 0, 30);
    call_cutscene_func_in_time_range(CutsceneStarDance2_3, a, 0, 30);
    call_cutscene_func_in_time_range(CutsceneStarDance2_4, a, 55, 124);
    call_cutscene_func_in_time_range(CutsceneStarDance2_5, a, 55, 124);
    call_cutscene_func_in_time_range(CutsceneStarDance2_6, a, 40, 40);
    func_8029A478(2);
    func_802882A0(5);
}

static void CutsceneKeyDance0_6(struct LevelCamera *a)
{
    func_8028C5F0(a->unk10, D_8032D000->unk4, D_8033B6F0[8].unk4, D_8032D000->unk10);
    func_8028C5F0(a->unk4, D_8032D000->unk4, D_8033B6F0[7].unk4, D_8032D000->unk10);
}

static void CutsceneKeyDance0_2(UNUSED struct LevelCamera *a)
{
    vec3f_set(D_8033B6F0[8].unk4, 38.f, 171.f, -248.f);
    vec3f_set(D_8033B6F0[7].unk4, -57.f, 51.f, 187.f);
}

static void CutsceneKeyDance0_3(UNUSED struct LevelCamera *a)
{
    vec3f_set(D_8033B6F0[8].unk4, -178.f, 62.f, -132.f);
    vec3f_set(D_8033B6F0[7].unk4, 299.f, 91.f, 58.f);
}

static void CutsceneKeyDance0_4(UNUSED struct LevelCamera *a)
{
    D_8033B3DC = 0x2800;
    vec3f_set(D_8033B6F0[8].unk4, 89.f, 373.f, -304.f);
    vec3f_set(D_8033B6F0[7].unk4, 0.f, 127.f, 0.f);
}

static void CutsceneKeyDance0_5(UNUSED struct LevelCamera *a)
{
    D_8033B3DC = 0;
    vec3f_set(D_8033B6F0[8].unk4, 135.f, 158.f, -673.f);
    vec3f_set(D_8033B6F0[7].unk4, -20.f, 135.f, -198.f);
}

static void CutsceneKeyDance0_7(UNUSED struct LevelCamera *a)
{
    func_80299C98(0x180, 48, -0x8000);
}

static void CutsceneKeyDance0_8(UNUSED struct LevelCamera *a)
{
    func_802882A0(1);
}

static void CutsceneKeyDance0_1(struct LevelCamera *a)
{
    func_80291BBC(a, 0, 0.2f);
}

void CutsceneKeyDance0(struct LevelCamera *a)
{
    call_cutscene_func_in_time_range(CutsceneDanceCommon, a, 0, 10);
    call_cutscene_func_in_time_range(CutsceneKeyDance0_1, a, 0, 10);
    call_cutscene_func_in_time_range(CutsceneKeyDance0_2, a, 0, 0);
    call_cutscene_func_in_time_range(CutsceneKeyDance0_3, a, 20, 20);
    call_cutscene_func_in_time_range(CutsceneKeyDance0_4, a, 35, 35);
    call_cutscene_func_in_time_range(CutsceneKeyDance0_5, a, 52, 52);
    call_cutscene_func_in_time_range(CutsceneKeyDance0_6, a, 11, -1);
    call_cutscene_func_in_time_range(CutsceneKeyDance0_7, a, 54, 54);
    call_cutscene_func_in_time_range(CutsceneKeyDance0_8, a, 52, -1);
}

static void CutsceneEnterBowserPlatform0_4(UNUSED struct LevelCamera *a)
{
    func_8029A494(2);
}

static void CutsceneEnterBowserPlatform0_3(UNUSED struct LevelCamera *a)
{
    D_8032CFD0->oUnk88 = 1;
}

static void CutsceneEnterBowserPlatform0_5(struct LevelCamera *a)
{
    vec3f_set_dist_and_angle(D_8033B6F0[2].unk4, a->unk10, D_8033B6F0[3].unk4[2], D_8033B6F0[3].unk1C[0], D_8033B6F0[3].unk1C[1]);
    vec3f_set(D_8033B6F0[2].unk4, D_8032CFD0->oPosX, D_8032CFD0->oPosY, D_8032CFD0->oPosZ);
}

static void CutsceneEnterBowserPlatform0_8(UNUSED struct LevelCamera *a)
{
    f32 sp1C = 150.0f;
    
    sp1C = sins(D_8033B6F0[4].unk1C[1]) * 120.0f + 120.0f;
    D_8033B6F0[4].unk1C[1] -= 0x200;
    approach_f32_exponential(&D_8033B6F0[0].unk4[1], sp1C, 0.5f);
}

static void CutsceneEnterBowserPlatform0_9(struct LevelCamera *a)
{
    func_8028C5F0(a->unk4, D_8033B6F0[2].unk4, D_8033B6F0[0].unk4, D_8033B6F0[2].unk1C);
}

static void CutsceneEnterBowserPlatform0_7(UNUSED struct LevelCamera *a)
{
    approach_s16_exponential(&D_8033B6F0[3].unk1C[0], 1736, 30);
    approach_f32_exponential(&D_8033B6F0[0].unk4[2], -200.f, 0.02f);
    approach_f32_exponential(&D_8033B6F0[3].unk4[2], 550.f, 0.02f);
}

static void CutsceneEnterBowserPlatform0_6(UNUSED struct LevelCamera *a)
{
    approach_f32_exponential(&D_8033B6F0[0].unk4[2], 0.f, 0.05f);
}

static void CutsceneEnterBowserPlatform0_1(UNUSED struct LevelCamera *a)
{
    func_8028FD94(1);
}

void func_802930C8(UNUSED struct LevelCamera *a)
{
    func_8028FD94(0);
}

static void CutsceneEnterBowserPlatform0_2(struct LevelCamera *a)
{
    D_8033B6F0[3].unk4[2] = 430.f;
    D_8033B6F0[3].unk1C[1] = D_8032CFD0->oMoveAngleYaw - 0x2000;
    D_8033B6F0[3].unk1C[0] = 3472;
    
    vec3f_set(D_8033B6F0[0].unk4, 0.f, 120.f, -800.f);
    vec3s_set(D_8033B6F0[2].unk1C, D_8032CFD0->oMoveAnglePitch, D_8032CFD0->oMoveAngleYaw, D_8032CFD0->oMoveAngleRoll);
    
    CutsceneEnterBowserPlatform0_5(a);
    CutsceneEnterBowserPlatform0_9(a);
}

static void CutsceneEnterBowserPlatform1_1(UNUSED struct LevelCamera *a)
{
    s16 sp26;
    
    switch (gCurrLevelNum)
    {
    case LEVEL_BOWSER_1:
        sp26 = 67;
        break;
    case LEVEL_BOWSER_2:
        sp26 = 92;
        break;
    default:
        sp26 = 93;
    }
    
    func_802D7F90(sp26);
}

void CutsceneEnterBowserPlatform1(struct LevelCamera *a)
{
    call_cutscene_func_in_time_range(CutsceneEnterBowserPlatform1_1, a, 0, 0);
    
    if (get_dialog_id() == -1)
        gCutsceneTimer = 0x7FFF;
}

void CutsceneEnterBowserPlatform2(struct LevelCamera *a)
{
    func_802930C8(a);
    a->unk30 = 0;
    func_80285A8C(a, 20);
    D_8033B4DA |= 0x4000;
    D_8033B402 = D_8032D000->unk10[1] + 0x4000;
    D_8032CFD0->oUnk88 = 2;
}

void CutsceneEnterBowserPlatform0(struct LevelCamera *a)
{
    func_80299C60(2, 0);
    
    if (D_8032CFD0 != NULL)
    {
        call_cutscene_func_in_time_range(CutsceneEnterBowserPlatform0_1, a, 0, -1);
        call_cutscene_func_in_time_range(CutsceneEnterBowserPlatform0_2, a, 0, 5);
        call_cutscene_func_in_time_range(CutsceneEnterBowserPlatform0_3, a, 40, 40);
        call_cutscene_func_in_time_range(CutsceneEnterBowserPlatform0_4, a, 145, 145);
        call_cutscene_func_in_time_range(CutsceneEnterBowserPlatform0_5, a, 40, -1);
        call_cutscene_func_in_time_range(CutsceneEnterBowserPlatform0_6, a, 40, 99);
        call_cutscene_func_in_time_range(CutsceneEnterBowserPlatform0_7, a, 100, -1);
        call_cutscene_func_in_time_range(CutsceneEnterBowserPlatform0_8, a, 40, 140);
        call_cutscene_func_in_time_range(CutsceneEnterBowserPlatform0_9, a, 40, -1);
        call_cutscene_func_in_time_range(CutsceneEnterSomething8029041C, a, 60, 60);
        call_cutscene_func_in_time_range(CutsceneEnterSomething8029041C, a, 82, 82);
        call_cutscene_func_in_time_range(CutsceneEnterSomething8029041C, a, 109, 109);
        call_cutscene_func_in_time_range(CutsceneEnterSomething8029041C, a, 127, 127);
    }
}

static void CutsceneStarSpawn0_1(struct LevelCamera *a)
{
    func_80290224(a);
}

static void CutsceneStarSpawn0_2(struct LevelCamera *a)
{
    UNUSED f32 sp34;
    Vec3f sp28;
    UNUSED f32 sp24;
    
    if (D_8032CFC4 != NULL)
    {
        object_pos_to_vec3f(sp28, D_8032CFC4);
        sp28[1] += D_8032CFC4->hitboxHeight;
        approach_vec3f_exponential(a->unk4, sp28, 0.1f, 0.1f, 0.1f);
    }
}

static void CutsceneStarSpawn1_1(struct LevelCamera *a)
{
    Vec3f sp2C, sp20;
    
    CameraChange0B(a, sp20, sp2C);
    approach_vec3f_exponential(a->unk4, sp20, 0.2f, 0.2f, 0.2f);
    approach_vec3f_exponential(a->unk10, sp2C, 0.2f, 0.2f, 0.2f);
}

static void CutsceneStarSpawn1_2(struct LevelCamera *a)
{
    func_802902A8(a);
    func_80285A8C(a, 15);
}

void CutsceneStarSpawn0(struct LevelCamera *a)
{
    call_cutscene_func_in_time_range(CutsceneStarSpawn0_1, a, 0, 0);
    call_cutscene_func_in_time_range(CutsceneStarSpawn0_2, a, 0, -1);
    D_8033B4DA |= 1;

    if (D_8033B858)
        gCutsceneTimer = 0x7FFF;
}

void CutsceneStarSpawn1(struct LevelCamera *a)
{
    if ((a->preset == CAMERA_PRESET_BOWSER_FIGHT) && (func_80288130(0) == 2))
        call_cutscene_func_in_time_range(CutsceneStarSpawn1_1, a, 0, -1);
    else
        call_cutscene_func_in_time_range(CutsceneStarSpawn1_2, a, 0, 0);
    
    D_8033B4DA |= 0x1;
    D_8033B4DA |= 0x4000;
}

void CutsceneStarSpawn2(struct LevelCamera *a)
{
    D_8033B4DA |= 0x1;
    gCutsceneTimer = -0x8000;
    a->unk30 = 0;
}

static void CutsceneExitWaterfall0_1(struct LevelCamera *a)
{
    vec3f_set(a->unk10, -3899.f, 39.f, -5671.f);
}

static void Cutscene80293794(struct LevelCamera *a)
{
    vec3f_copy(a->unk4, D_8032D000->unk4);
    a->unk4[1] = a->unk10[1] + (D_8032D000->unk4[1] + 125.f - a->unk10[1]) * 0.5f;
    approach_vec3f_exponential(a->unk4, D_8032D000->unk4, 0.05f, 0.4f, 0.05f);
}

void CutsceneExitWaterfall0(struct LevelCamera *a)
{
    call_cutscene_func_in_time_range(CutsceneExitWaterfall0_1, a, 0, 0);
    call_cutscene_func_in_time_range(Cutscene80293794, a, 0, -1);
    func_8028FA74(a);
}

void CutsceneFallCommon1(struct LevelCamera *a)
{
    D_8033B4DA |= 1;
    gCutsceneTimer = -0x8000;
    a->unk30 = 0;
    func_8028FA74(a);
}

static void CutsceneFallToCastleGrounds0_1(struct LevelCamera *a)
{
    vec3f_set(a->unk10, 5830.f, 32.f, 3985.f);
}

void CutsceneFallToCastleGrounds0(struct LevelCamera *a)
{
    call_cutscene_func_in_time_range(CutsceneFallToCastleGrounds0_1, a, 0, 0);
    call_cutscene_func_in_time_range(Cutscene80293794, a, 0, -1);
    func_8028FA74(a);
}

static void CutsceneSpecialStarSpawn0_1(struct LevelCamera *a)
{
    object_pos_to_vec3f(D_8033B6F0[1].unk4, D_8032CFC4);
    func_80290224(a);
    D_8033B6F0[2].unk4[2] = D_8033B230.fieldOfView;
}

static void CutsceneSpecialStarSpawn0_3(struct LevelCamera *a)
{
    approach_f32_exponential(&a->unk4[0], D_8032CFC4->oPosX, 0.15f);
    approach_f32_exponential(&a->unk4[2], D_8032CFC4->oPosZ, 0.15f);
}

static void CutsceneSpecialStarSpawn0_4(struct LevelCamera *a)
{
    approach_f32_exponential(&a->unk4[1], D_8032CFC4->oPosY, 0.1f);
}

static void CutsceneSpecialStarSpawn0_5(struct LevelCamera *a)
{
    a->unk4[1] = D_8033B6F0[1].unk4[1] + (D_8032CFC4->oPosY - D_8033B6F0[1].unk4[1]) * 0.8f;
}

static void CutsceneSpecialStarSpawn0_2(struct LevelCamera *a)
{
    f32 sp3C;
    s16 sp3A, sp38, sp36;
    struct Object *sp30 = D_8032CFC4;
    
    vec3f_set(D_8033B6F0[1].unk4, sp30->oHomeX, sp30->oHomeY, sp30->oHomeZ);
    vec3f_get_dist_and_angle(D_8033B6F0[1].unk4, a->unk10, &sp3C, &sp3A, &sp38);
    sp36 = func_8028A4F0(D_8033B6F0[1].unk4, a->unk10);
    sp38 = func_8028A4F0(D_8033B6F0[1].unk4, D_8032D000->unk4);
    
    if (ABS(sp38 - sp36 + 0x4000) < ABS(sp38 - sp36 - 0x4000))
        sp38 += 0x4000;
    else
        sp38 -= 0x4000;
    
    vec3f_set_dist_and_angle(D_8033B6F0[1].unk4, a->unk10, 400.f, 0x1000, sp38);
    D_8033B4DA &= ~1;
}

static void CutsceneSpecialStarSpawn0_6(UNUSED struct LevelCamera *a)
{
    D_8033B230.fieldOfView = 60.f;
}

void CutsceneSpecialStarSpawn0(struct LevelCamera *a)
{
    D_8033B4DA |= 1;
    call_cutscene_func_in_time_range(CutsceneSpecialStarSpawn0_1, a, 0, 0);
    call_cutscene_func_in_time_range(CutsceneSpecialStarSpawn0_2, a, 30, 30);
    call_cutscene_func_in_time_range(CutsceneSpecialStarSpawn0_3, a, 0, -1);
    call_cutscene_func_in_time_range(CutsceneSpecialStarSpawn0_4, a, 0, 29);
    call_cutscene_func_in_time_range(CutsceneSpecialStarSpawn0_5, a, 30, -1);
    call_cutscene_func_in_time_range(CutsceneSpecialStarSpawn0_6, a, 30, -1);
    
    if (D_8033B858)
        gCutsceneTimer = 0x7FFF;
}

void CutsceneSpecialStarSpawn1(struct LevelCamera *a)
{
    func_802902A8(a);
    gCutsceneTimer = -0x8000;
    a->unk30 = 0;
    D_8033B230.fieldOfView = D_8033B6F0[2].unk4[2];
}

void func_80293DE8(struct LevelCamera *a, f32 b, s16 c, s16 d, s16 e)
{
    UNUSED f32 sp44;
    f32 sp40;
    s16 sp3E, sp3C;
    f32 sp38;
    s16 sp36, sp34;
    f32 sp30;
    s16 sp2E, sp2C;
    UNUSED f32 sp28, sp24;
    
    vec3f_get_dist_and_angle(D_8033B6F0[3].unk4, a->unk10, &sp40, &sp3E, &sp3C);
    
    if ((sp40 > 8000.f) && (a->unk30 == 150))
    {
        sp40 = b * 4.f;
        sp3E = c;
        vec3f_copy(D_8033B6F0[0].unk4, D_8033B6F0[3].unk4);
        D_8033B4DA &= ~1;
        
        if (gCurrLevelNum == LEVEL_TTM)
            sp3C = atan2s(D_8033B6F0[3].unk4[2] - a->unk2C, D_8033B6F0[3].unk4[0] - a->unk28);
    }
    else
    {
        if (a->unk30 == 150)
        {
            vec3f_get_dist_and_angle(a->unk10, D_8033B6F0[0].unk4, &sp30, &sp2E, &sp2C);
            vec3f_get_dist_and_angle(a->unk10, D_8033B6F0[3].unk4, &sp38, &sp36, &sp34);
            approach_f32_exponential(&sp30, sp38, 0.1f);
            approach_s16_exponential(&sp2E, sp36, 15);
            approach_s16_exponential(&sp2C, sp34, 15);
            vec3f_set_dist_and_angle(a->unk10, D_8033B6F0[0].unk4, sp30, sp2E, sp2C);
        }
        else
            approach_vec3f_exponential(D_8033B6F0[0].unk4, D_8033B6F0[3].unk4, 0.1f, 0.1f, 0.1f);
    }
    
    approach_f32_exponential(&sp40, b, 0.05f);
    approach_s16_exponential(&sp3E, c, 0x20);
    vec3f_set_dist_and_angle(D_8033B6F0[3].unk4, a->unk10, sp40, sp3E, sp3C);
    vec3f_copy(a->unk4, D_8033B6F0[0].unk4);
    func_80290390(a, d, e);
    vec3f_get_dist_and_angle(a->unk10, a->unk4, &sp40, &sp3E, &sp3C);
    
    if (sp3E < -0x3000)
        sp3E = -0x3000;
    if (sp3E > 0x3000)
        sp3E = 0x3000;
    
    vec3f_set_dist_and_angle(a->unk10, a->unk4, sp40, sp3E, sp3C);
}

static void CutscenePrepareCannon0_1(struct LevelCamera *a)
{
    func_80290144(a);
    vec3f_copy(D_8033B6F0[0].unk4, a->unk4);
    D_8033B6F0[2].unk4[0] = 30.f;
    object_pos_to_vec3f(D_8033B6F0[3].unk4, D_8032CFC4);
    vec3s_set(D_8033B6F0[5].unk1C, 0, 0, 0);
}

static void CutscenePrepareCannon0_2(struct LevelCamera *a)
{
    func_80293DE8(a, 300.f, 0x2000, 0, D_8033B6F0[5].unk1C[1]);
    func_80289184(&D_8033B6F0[5].unk1C[1], 0x400, 17);
    func_802882A0(1);
}

void func_802941CC(f32 *a, f32 b)
{
    f32 sp24 = ABS(b - *a) / D_8033B6F0[2].unk4[0];
    func_802893E4(a, b, sp24);
}

static void CutscenePrepareCannon0_3(struct LevelCamera *a)
{
    f32 sp1C = func_8028A640(a->unk10, D_8033B4B8.unk0);
    
    if (sp1C < 8000.f)
    {
        func_802941CC(&a->unk10[0], D_8033B4B8.unk0[0]);
        func_802941CC(&a->unk10[1], D_8033B4B8.unk0[1]);
        func_802941CC(&a->unk10[2], D_8033B4B8.unk0[2]);
        func_802941CC(&a->unk4[0], D_8033B4B8.unkC[0]);
        func_802941CC(&a->unk4[1], D_8033B4B8.unkC[1]);
        func_802941CC(&a->unk4[2], D_8033B4B8.unkC[2]);
    }
    else
    {
        vec3f_copy(a->unk4, D_8033B4B8.unkC);
        vec3f_copy(a->unk10, D_8033B4B8.unk0);
        D_8033B4DA &= ~1;
    }
    if (D_8033B6F0[2].unk4[0] > 1.f)
        D_8033B6F0[2].unk4[0] -= 1.f;
}

void CutscenePrepareCannon0(struct LevelCamera *a)
{
    D_8033B4DA |= 1;
    call_cutscene_func_in_time_range(CutscenePrepareCannon0_1, a, 0, 0);
    call_cutscene_func_in_time_range(CutscenePrepareCannon0_2, a, 0, 140);
    call_cutscene_func_in_time_range(CutscenePrepareCannon0_3, a, 141, -1);
}

void CutscenePrepareCannon1(struct LevelCamera *a)
{
    gCutsceneTimer = -0x8000;
    a->unk30 = 0;
    func_802901B4(a);
    D_8033B4DA |= 1;
}

static void func_802944A8(struct LevelCamera *a)
{
    f32 sp24;
    s16 sp22, sp20;
    
    vec3f_get_dist_and_angle(D_8032D000->unk4, a->unk10, &sp24, &sp22, &sp20);
    approach_s16_exponential(&sp20, (D_8032D000->unk10[1] - 0x3000), 8);
    vec3f_set_dist_and_angle(D_8032D000->unk4, a->unk10, sp24, sp22, sp20);
}

static void func_80294538(struct LevelCamera *a)
{
    func_80293DE8(a, 400.f, 0x1000, 0x300, 0);
}

static void CutsceneDeath1_1(struct LevelCamera *a)
{
    vec3f_copy(D_8033B6F0[0].unk4, a->unk4);
    vec3f_copy(D_8033B6F0[3].unk4, D_8032D000->unk4);
    D_8033B6F0[3].unk4[1] += 70.f;
}

static void CutsceneDeath1_2(struct LevelCamera *a)
{
    func_80294538(a);
    func_802882A0(4);
}

void CutsceneDeath1(struct LevelCamera *a)
{
    call_cutscene_func_in_time_range(CutsceneDeath1_1, a, 0, 0);
    call_cutscene_func_in_time_range(CutsceneDeath1_2, a, 0, -1);
    D_8033B4DA |= 1;
}

static void CutsceneDeath2_1(struct LevelCamera *a)
{
    Vec3f sp1C = {0, 40.f, -60.f};
    
    func_8028C5F0(D_8033B6F0[3].unk4, D_8032D000->unk4, sp1C, D_8032D000->unk10);
    vec3f_copy(D_8033B6F0[0].unk4, a->unk4);
}

static void CutsceneDeath2_2(struct LevelCamera *a)
{
    func_80293DE8(a, 400.f, 0x1800, 0, -0x400);
}

static void unused_80294748(struct LevelCamera *a)
{
    func_802944A8(a);
}

void CutsceneDeath2(struct LevelCamera *a)
{
    call_cutscene_func_in_time_range(CutsceneDeath2_1, a, 0, 0);
    call_cutscene_func_in_time_range(CutsceneDeath2_2, a, 0, -1);
    D_8033B4DA |= 1;
    func_802882A0(1);
}

static void CutsceneBBHDeath0_1(struct LevelCamera *a)
{
    Vec3f sp1C = {0, 40.f, 60.f};
    
    func_8028C5F0(D_8033B6F0[3].unk4, D_8032D000->unk4, sp1C, D_8032D000->unk10);
    vec3f_copy(D_8033B6F0[0].unk4, a->unk4);
}

static void CutsceneBBHDeath0_2(struct LevelCamera *a)
{
    func_80293DE8(a, 400.f, 0x1800, 0, 0x400);
}

void CutsceneBBHDeath0(struct LevelCamera *a)
{
    call_cutscene_func_in_time_range(CutsceneBBHDeath0_1, a, 0, 0);
    call_cutscene_func_in_time_range(CutsceneBBHDeath0_2, a, 0, -1);
    D_8033B4DA |= 1;
    func_802882A0(1);
}

static void CutsceneQuicksandDeath0_1(struct LevelCamera *a)
{
    vec3f_copy(D_8033B6F0[0].unk4, a->unk4);
}

static void CutsceneQuicksandDeath0_2(struct LevelCamera *a)
{
    func_80293DE8(a, 400.f, 0x2800, 0x200, 0);
    
    if (a->unk30 == 159)
        func_802944A8(a);
}

void CutsceneQuicksandDeath0(struct LevelCamera *a)
{
    D_8033B6F0[3].unk4[0] = D_8032D000->unk4[0];
    D_8033B6F0[3].unk4[1] = D_8032D000->unk4[1] + 20.f;
    D_8033B6F0[3].unk4[2] = D_8032D000->unk4[2];
    
    call_cutscene_func_in_time_range(CutsceneQuicksandDeath0_1, a, 0, 0);
    call_cutscene_func_in_time_range(CutsceneQuicksandDeath0_2, a, 0, -1);
    D_8033B4DA |= 1;
    func_802882A0(4);
}

static void Cutscene1ATodo0_3(UNUSED struct LevelCamera *a)
{
    Vec3f sp2C;
    Vec3f sp20 = {0, 20.f, 120.f};
    
    func_8028C5F0(sp2C, D_8032D000->unk4, sp20, D_8032D000->unk10);
    approach_vec3f_exponential(D_8033B6F0[3].unk4, sp2C, 0.1f, 0.1f, 0.1f);
}

static void Cutscene1ATodo0_2(struct LevelCamera *a)
{
    UNUSED f32 sp34;
    f32 sp30;
    UNUSED f32 sp2C;
    
    func_80293DE8(a, 400.f, 0x2800, 0x200, 0);
    sp30 = func_80381D3C(D_8032D000->unk4[0], D_8032D000->unk4[2]);
    
    if (sp30 != -11000.f)
    {
        if ((sp30 += 130.f) > a->unk10[1])
            a->unk10[1] = sp30;
    }
}

static void Cutscene1ATodo0_1(struct LevelCamera *a)
{
    f32 sp24;
    s16 sp22, sp20;
    
    vec3f_get_dist_and_angle(D_8032D000->unk4, a->unk10, &sp24, &sp22, &sp20);
    sp20 += 0x100;
    vec3f_set_dist_and_angle(D_8032D000->unk4, a->unk10, sp24, sp22, sp20);
}

void Cutscene1ATodo0(struct LevelCamera *a)
{
    call_cutscene_func_in_time_range(CutsceneDeath2_1, a, 0, 0);
    call_cutscene_func_in_time_range(Cutscene1ATodo0_1, a, 0, -1);
    call_cutscene_func_in_time_range(Cutscene1ATodo0_2, a, 0, -1);
    call_cutscene_func_in_time_range(Cutscene1ATodo0_3, a, 50, -1);
    D_8033B4DA |= 1;
    func_802882A0(4);
}

static void CutsceneEnterPool0_1(struct LevelCamera *a)
{
    vec3f_copy(D_8033B6F0[3].unk4, D_8032D000->unk4);
    
    if (gCurrLevelNum == LEVEL_CASTLE) // entering HMC
        vec3f_set(D_8033B6F0[3].unk4, 2485.f, -1589.f, -2659.f);
    if (gCurrLevelNum == LEVEL_HMC) // entering CotMC
        vec3f_set(D_8033B6F0[3].unk4, 3350.f, -4589.f, 4800.f);
    
    vec3f_copy(D_8033B6F0[0].unk4, a->unk4);
}

static void CutsceneEnterPool0_2(struct LevelCamera *a)
{
    UNUSED u32 pad[2];
    
    func_80293DE8(a, 1200.f, 0x2000, 0x200, 0);
}

void CutsceneEnterPool0(struct LevelCamera *a)
{
    call_cutscene_func_in_time_range(CutsceneEnterPool0_1, a, 0, 0);
    call_cutscene_func_in_time_range(CutsceneEnterPool0_2, a, 0, -1);
    D_8033B4DA |= 1;
}

static void Cutscene26Todo1_1(struct LevelCamera *a)
{
    func_8028FEDC(a);
    func_80290144(a);
    
    vec3f_copy(D_8033B6F0[1].unk4, a->unk4);
    vec3f_set(D_8033B6F0[3].unk4, a->unk28, 1280.f, a->unk2C);
}

static void Cutscene26Todo1_5(UNUSED struct LevelCamera *a)
{
    func_8029A478(10);
}

static void Cutscene26Todo1_2(struct LevelCamera *a)
{
    approach_vec3f_exponential(a->unk4, D_8033B6F0[3].unk4, 0.02f, 0.02f, 0.02f);
    D_8033B4DA |= 1;
}

static void Cutscene26Todo1_3(struct LevelCamera *a)
{
    s16 sp26, sp24;
    f32 sp20;
    
    func_8029A478(2);
    D_8033B230.fieldOfView = 45.f;
    
    vec3f_copy(D_8033B6F0[4].unk4, a->unk10);
    vec3f_copy(D_8033B6F0[5].unk4, a->unk4);
    vec3f_copy(a->unk4, D_8033B6F0[3].unk4);
    
    vec3f_get_dist_and_angle(D_8033B6F0[3].unk4, D_8032D000[0].unk4, &sp20, &sp26, &sp24);
    vec3f_set_dist_and_angle(D_8033B6F0[3].unk4, a->unk10, 2000.f, 0, sp24);
    a->unk10[1] += 500.f;
}

static void Cutscene26Todo1_4(struct LevelCamera *a)
{
    s16 sp26, sp24;
    f32 sp20;
    
    vec3f_get_dist_and_angle(D_8033B6F0[3].unk4, a->unk10, &sp20, &sp26, &sp24);
    approach_f32_exponential(&sp20, 2000.f, 0.1f);
    vec3f_set_dist_and_angle(D_8033B6F0[3].unk4, a->unk10, sp20, sp26, sp24);
    
    a->unk4[1] += 4.f;
    a->unk10[1] -= 5.f;
    D_8033B230.fieldOfView = 45.f;
    func_802882A0(1);
}

static void Cutscene26Todo1_7(UNUSED struct LevelCamera *a)
{
    func_8027F308(8);
}

static void Cutscene26Todo1_6(struct LevelCamera *a)
{
    UNUSED u32 pad[2];
    
    vec3f_copy(a->unk10, D_8033B6F0[4].unk4);
    vec3f_copy(a->unk4, D_8033B6F0[5].unk4);
    func_8027F308(3);
}

void Cutscene26Todo1(struct LevelCamera *a)
{
    call_cutscene_func_in_time_range(Cutscene26Todo1_1, a, 0, 0);
    call_cutscene_func_in_time_range(Cutscene26Todo1_2, a, 0, 30);
    call_cutscene_func_in_time_range(Cutscene26Todo1_3, a, 31, 31);
    call_cutscene_func_in_time_range(Cutscene26Todo1_4, a, 31, 139);
    call_cutscene_func_in_time_range(Cutscene26Todo1_5, a, 23, 23);
    call_cutscene_func_in_time_range(Cutscene26Todo1_6, a, 140, 140);
    call_cutscene_func_in_time_range(Cutscene26Todo1_7, a, 31, 139);
}

void Cutscene26Todo2(struct LevelCamera *a)
{
    func_802930C8(a);
    func_8028FAE0(a);
    func_80285A8C(a, 30);
}

static void CutsceneEnterPyramidTop0_1(struct LevelCamera *a)
{
    vec3f_copy(D_8033B6F0[0].unk4, a->unk4);
    vec3f_set(D_8033B6F0[3].unk4, a->unk28, 1280.f, a->unk2C);
}

void CutsceneEnterPyramidTop0(struct LevelCamera *a)
{
    call_cutscene_func_in_time_range(CutsceneEnterPyramidTop0_1, a, 0, 0);
    func_80293DE8(a, 200.f, 0x3000, 0, 0);
    D_8033B4DA |= 1;
    func_802882A0(1);
    
    if (D_8032D000->unk4[1] > 1250.f)
        CutsceneFallCommon1(a);
}

static void unused_8029538C(struct LevelCamera *a)
{
    f32 sp24;
    
    sp24 = func_8028A640(D_8033B6F0[3].unk4, D_8032D000->unk4);
    sp24 = func_8028A640(D_8033B6F0[9].unk4, D_8032D000->unk4) + 200.f;
    func_80293DE8(a, sp24, 0x1000, 0x300, 0);
}

static void CutsceneDialog0_1(struct LevelCamera *a)
{
    UNUSED f32 sp1C;
    UNUSED s16 sp1A;
    s16 sp18;
    
    func_80290564(a);
    set_time_stop_flag(6);
    
#if VERSION_US
    if (a->preset == CAMERA_PRESET_BOWSER_FIGHT)
    {
        vec3f_copy(D_8033B4B8.unkC, a->unk4);
        vec3f_copy(D_8033B4B8.unk0, a->unk10);
    }
    else
#endif
        func_80290224(a);

    
    D_8033B6F0[8].unk1C[0] = 0;
    vec3f_copy(D_8033B6F0[8].unk4, D_8032D000->unk4);
    D_8033B6F0[8].unk4[1] += 125.f;
    object_pos_to_vec3f(D_8033B6F0[9].unk4, D_8032CFC4);
    D_8033B6F0[9].unk4[1] += D_8032CFC4->hitboxHeight + 200.f;
    D_8033B6F0[9].unk1C[1] = func_8028A4F0(D_8033B6F0[8].unk4, D_8033B6F0[9].unk4);
    
    sp18 = func_8028A4F0(D_8032D000->unk4, D_8033B328.unk0[1]);
    if ((sp18 - D_8033B6F0[9].unk1C[1]) & 0x8000)
        D_8033B6F0[9].unk1C[1] -= 0x6000;
    else
        D_8033B6F0[9].unk1C[1] += 0x6000;
}

static void CutsceneDialog0_2(struct LevelCamera *a)
{
    f32 sp4C;
    s16 sp4A, sp48;
    Vec3f sp3C, sp30;
    
    func_8028A24C(sp3C, D_8033B6F0[9].unk4, D_8032D000->unk4, 0.7f);
    vec3f_get_dist_and_angle(a->unk10, sp3C, &sp4C, &sp4A, &sp48);
    sp4A = func_8028A440(a->unk10, D_8033B6F0[9].unk4);
    vec3f_set_dist_and_angle(a->unk10, sp30, sp4C, sp4A, sp48);
    sp3C[1] = sp3C[1] + (D_8033B6F0[9].unk4[1] - sp3C[1]) * 0.1f;
    approach_vec3f_exponential(a->unk4, sp3C, 0.2f, 0.2f, 0.2f);
    vec3f_copy(sp30, a->unk10);
    sp30[1] = D_8033B6F0[8].unk4[1];
    vec3f_get_dist_and_angle(D_8033B6F0[8].unk4, sp30, &sp4C, &sp4A, &sp48);
    approach_s16_exponential(&sp48, D_8033B6F0[9].unk1C[1], 0x10);
    approach_f32_exponential(&sp4C, 180.f, 0.05f);
    vec3f_set_dist_and_angle(D_8033B6F0[8].unk4, sp30, sp4C, sp4A, sp48);
    sp30[1] = D_8033B6F0[8].unk4[1] + sins(func_8028A440(D_8033B6F0[9].unk4, D_8033B6F0[8].unk4)) * 100.f;
    approach_f32_exponential(&a->unk10[1], sp30[1], 0.05f);
    a->unk10[0] = sp30[0];
    a->unk10[2] = sp30[2];
}

static void CutsceneDialog0_3(struct LevelCamera *a)
{
    if (a->unk30 == 163)
        func_802D8050(D_8033B320);
    else
        func_802D7F90(D_8033B320);
    
    D_8033B6F0[8].unk1C[0] = 3;
}

void CutsceneDialog0(struct LevelCamera *a)
{
    call_cutscene_func_in_time_range(CutsceneDialog0_1, a, 0, 0);
    call_cutscene_func_in_time_range(CutsceneDialog0_2, a, 0, -1);
    call_cutscene_func_in_time_range(CutsceneDialog0_3, a, 10, 10);
    D_8033B4DA |= 1;
    
    if (gDialogueResponse != 0)
        D_8032CFFC = gDialogueResponse;
    
    if ((get_dialog_id() == -1) && (D_8033B6F0[8].unk1C[0] != 0))
    {
        if (a->unk30 != 163)
            D_8032CFFC = 3;
        
        gCutsceneTimer = 0x7FFF;
        func_802902A8(a);
        func_80285A8C(a, 15);
        D_8033B4DA |= 0x4000;
        func_80290598(a);
    }
}

void CutsceneDialog1(UNUSED struct LevelCamera *a)
{
    D_8033B4DA |= 0x4000;
}

void CutsceneDialog2(struct LevelCamera *a)
{
    D_8033B4DA |= 0x4000;
    a->unk30 = 0;
    clear_time_stop_flag(6);
}

static void CutsceneReadMessage0_1(struct LevelCamera *a)
{
    func_80290564(a);
    func_80285A8C(a, 30);
    func_8028FEDC(a);
    func_80290224(a);
    
    D_8033B6F0[1].unk1C[0] = D_8033B400;
    D_8033B6F0[1].unk1C[1] = D_8033B402;
    D_8033B400 = -2096;
    D_8033B402 = 0;
    D_8033B6F0[0].unk1C[0] = 0;
}

static void unused_80295A28(struct LevelCamera *a)
{
    Vec3s sp20;
    
    vec3s_set(sp20, 0, D_8032D000->unk10[1], 0);
    func_8028C794(a->unk10, D_8032D000->unk4, sp20, 0, 100.f, 190.f);
    func_8028C794(a->unk4, D_8032D000->unk4, sp20, 0, 70.f, -20.f);
}

void CutsceneReadMessage0(struct LevelCamera *a)
{
    UNUSED u32 pad[2];
    
    call_cutscene_func_in_time_range(CutsceneReadMessage0_1, a, 0, 0);
    D_8033B4DA |= 1;
    
    switch (D_8033B6F0[0].unk1C[0])
    {
    case 0:
        if (get_dialog_id() != -1)
        {
            D_8033B6F0[0].unk1C[0] += 1;
            set_time_stop_flag(6);
        }
        break;
    case 1:
        func_802852F4(a);
        CameraChange06(a, a->unk4, a->unk10);
        
        if (get_dialog_id() == -1)
        {
            gCutsceneTimer = 0x7FFF;
            func_802902A8(a);
            func_80285A8C(a, 15);
            D_8033B4DA |= 0x4000;
            clear_time_stop_flag(6);
            D_8033B400 = D_8033B6F0[1].unk1C[0];
            D_8033B402 = D_8033B6F0[1].unk1C[1];
            func_80290598(a);
        }
    }
    D_8033B4DA |= 0x4000;
}

void CutsceneReadMessage1(UNUSED struct LevelCamera *a)
{
    D_8033B4DA |= 0x4000;
}

void CutsceneReadMessage2(struct LevelCamera *a)
{
    D_8033B4DA |= 0x4000;
    a->unk30 = 0;
}

static void CutsceneExitSuccess1(UNUSED struct LevelCamera *a)
{
    vec3f_copy(D_8033B6F0[7].unk4, D_8032D000->unk4);
    vec3s_copy(D_8033B6F0[7].unk1C, D_8032D000->unk10);
    vec3f_set(D_8033B6F0[6].unk4, 6.f, 363.f, 543.f);
    vec3f_set(D_8033B6F0[5].unk4, 137.f, 226.f, 995.f);
}

static void CutsceneExitSuccess2(struct LevelCamera *a)
{
    UNUSED u32 sp34;
    struct Surface *sp30;
    UNUSED Vec3f sp24;
    
    switch (D_8032CFDC)
    {
    case LEVEL_HMC:
        vec3f_set(a->unk10, 3465.f, -1008.f, -2961.f);
        break;
    case LEVEL_COTMC:
        vec3f_set(a->unk10, 3465.f, -1008.f, -2961.f);
        break;
    case LEVEL_RR:
        vec3f_set(a->unk10, -3741.f, 3151.f, 6065.f);
        break;
    case LEVEL_WMOTR:
        vec3f_set(a->unk10, 1972.f, 3230.f, 5891.f);
        break;
    default:
        func_8028C5F0(a->unk10, D_8033B6F0[7].unk4, D_8033B6F0[5].unk4, D_8033B6F0[7].unk1C);
        a->unk10[1] = find_floor(a->unk10[0], a->unk10[1] + 1000.f, a->unk10[2], &sp30) + 125.f;
        break;
    }
}

static void CutsceneExitSuccess4(struct LevelCamera *a)
{
    func_8028C5F0(a->unk4, D_8033B6F0[7].unk4, D_8033B6F0[6].unk4, D_8033B6F0[7].unk1C);
    
    if ((D_8032CFDC == LEVEL_COTMC) || (D_8032CFDC == LEVEL_HMC) || (D_8032CFDC == LEVEL_RR) || (D_8032CFDC == LEVEL_WMOTR))
    {
        a->unk4[0] = a->unk10[0] + (D_8032D000->unk4[0] - a->unk10[0]) * 0.7f;
        a->unk4[1] = a->unk10[1] + (D_8032D000->unk4[1] - a->unk10[1]) * 0.4f;
        a->unk4[2] = a->unk10[2] + (D_8032D000->unk4[2] - a->unk10[2]) * 0.7f;
    }
    else
        a->unk4[1] = a->unk10[1] + (D_8032D000->unk4[1] - a->unk10[1]) * 0.2f;
}

static void CutsceneExitSuccess3(UNUSED struct LevelCamera *a)
{
    approach_f32_exponential(&D_8033B6F0[6].unk4[0], -24.f, 0.05f);
}

static void CutsceneExitBowserSuccess0_1(struct LevelCamera *a)
{
    if (a->unk30 == 157)
        func_8028A908(0x800, 0x40, 0x800);
}

static void CutsceneExitSuccess5(UNUSED struct LevelCamera *a)
{
    func_8027F308(1);
}

void CutsceneExitBowserSuccess0(struct LevelCamera *a)
{
    call_cutscene_func_in_time_range(CutsceneExitSuccess1, a, 0, 0);
    call_cutscene_func_in_time_range(CutsceneExitSuccess2, a, 0, -1);
    call_cutscene_func_in_time_range(CutsceneExitSuccess3, a, 18, -1);
    call_cutscene_func_in_time_range(CutsceneExitSuccess4, a, 0, -1);
    call_cutscene_func_in_time_range(CutsceneExitBowserSuccess0_1, a, 125, 125);
    call_cutscene_func_in_time_range(CutsceneExitSuccess5, a, 41, 41);
}

void CutsceneExitNonPainting1(struct LevelCamera *a)
{
    a->unk30 = 0;
    
    if (a->unk1 == 4)
        a->preset = CAMERA_PRESET_CLOSE;
    else
        a->preset = CAMERA_PRESET_FREE_ROAM;
    
    D_8033B4DA |= 0x4000;
    D_8033B4DA |= 1;
    func_80285A8C(a, 60);
    func_8028FA74(a);
}

static void CutsceneBBHExitSuccess0_1(UNUSED struct LevelCamera *a)
{
    vec3f_set(D_8033B6F0[5].unk4, 137.f, 246.f, 1115.f);
}

void CutsceneBBHExitSuccess0(struct LevelCamera *a)
{
    call_cutscene_func_in_time_range(CutsceneExitSuccess1, a, 0, 0);
    call_cutscene_func_in_time_range(CutsceneBBHExitSuccess0_1, a, 0, 0);
    call_cutscene_func_in_time_range(CutsceneExitSuccess2, a, 0, -1);
    call_cutscene_func_in_time_range(CutsceneExitSuccess3, a, 18, -1);
    call_cutscene_func_in_time_range(CutsceneExitSuccess4, a, 0, -1);
    call_cutscene_func_in_time_range(CutsceneExitSuccess5, a, 41, 41);
    func_8028FA74(a);
}

static void CutsceneNonPaintingDeath0_1(UNUSED struct LevelCamera *a)
{
    vec3f_copy(D_8033B6F0[7].unk4, D_8032D000->unk4);
    vec3s_copy(D_8033B6F0[7].unk1C, D_8032D000->unk10);
    vec3f_set(D_8033B6F0[6].unk4, -42.f, 350.f, 727.f);
    vec3f_set(D_8033B6F0[5].unk4, 107.f, 226.f, 1187.f);
}

void Cutscene1CTodo_0(struct LevelCamera *a)
{
    call_cutscene_func_in_time_range(CutsceneNonPaintingDeath0_1, a, 0, 0);
    call_cutscene_func_in_time_range(CutsceneExitSuccess2, a, 0, -1);
    call_cutscene_func_in_time_range(CutsceneExitSuccess4, a, 0, -1);
}

static void CutsceneNonPaintingDeath0_2(UNUSED struct LevelCamera *a)
{
    switch (D_8032CFDC)
    {
    case LEVEL_HMC:
        vec3f_set(D_8033B6F0[5].unk4, 187.f, 369.f, -197.f);
        break;
    case LEVEL_COTMC:
        vec3f_set(D_8033B6F0[5].unk4, 187.f, 369.f, -197.f);
        break;
    default:
        vec3f_set(D_8033B6F0[5].unk4, 107.f, 246.f, 1307.f);
        break;
    }
}
    
void CutsceneNonPaintingDeath0(struct LevelCamera *a)
{
    call_cutscene_func_in_time_range(CutsceneNonPaintingDeath0_1, a, 0, 0);
    call_cutscene_func_in_time_range(CutsceneNonPaintingDeath0_2, a, 0, 0);
    call_cutscene_func_in_time_range(CutsceneExitSuccess2, a, 0, -1);
    call_cutscene_func_in_time_range(CutsceneExitSuccess4, a, 0, -1);
    D_8033B4DA |= 0x4000;
}

static void CutsceneCapSwitchPress0_1(struct LevelCamera *a)
{
    UNUSED s16 sp26;
    s16 sp24;
    UNUSED u32 sp1C[2];
    
    func_80290224(a);
    sp24 = func_8028A4F0(D_8032D000->unk4, a->unk10);
    D_8033B6F0[3].unk1C[1] = 0x1200;
    D_8033B6F0[1].unk1C[1] = (sp24 - (D_8032D000->unk10[1] + D_8033B6F0[3].unk1C[1])) & 0xFF00;
    
}

static void CutsceneCapSwitchPress0_4(struct LevelCamera *a)
{
    f32 sp2C;
    s16 sp2A, sp28;
    UNUSED s16 sp26 = D_8032D000->unk10[1] + 0x1000;
    UNUSED s16 sp24;
    UNUSED s32 sp20 = D_8033B6F0[1].unk1C[1];
    
    vec3f_get_dist_and_angle(D_8032D000->unk4, a->unk10, &sp2C, &sp2A, &sp28);
    
    if (D_8033B6F0[3].unk1C[1] != 0x1000)
        D_8033B6F0[3].unk1C[1] += 0x100;
    if (D_8033B6F0[1].unk1C[1] != 0)
        D_8033B6F0[1].unk1C[1] += 0x100;
    
    sp28 = D_8032D000->unk10[1] + D_8033B6F0[3].unk1C[1] + D_8033B6F0[1].unk1C[1];
    vec3f_set_dist_and_angle(D_8032D000->unk4, a->unk10, sp2C, sp2A, sp28);
}

static void CutsceneCapSwitchPress0_5(struct LevelCamera *a)
{
    func_8029047C(a->unk10, D_8032D000->unk4, 0, -0x20, 0);
}


static void CutsceneCapSwitchPress0_2(struct LevelCamera *a)
{
    s16 sp26, sp24;
    f32 sp20;
    
    vec3f_get_dist_and_angle(D_8032D000->unk4, a->unk10, &sp20, &sp26, &sp24);
    approach_f32_exponential(&sp20, 195.f, 0.2f);
    approach_s16_exponential(&sp26, 0, 0x10);
    vec3f_set_dist_and_angle(D_8032D000->unk4, a->unk10, sp20, sp26, sp24);
    
    approach_f32_exponential(&a->unk4[0], D_8032D000->unk4[0], 0.1f);
    approach_f32_exponential(&a->unk4[1], D_8032D000->unk4[1] + 110.f, 0.1f);
    approach_f32_exponential(&a->unk4[2], D_8032D000->unk4[2], 0.1f);
}

static void CutsceneCapSwitchPress0_3(struct LevelCamera *a)
{
    vec3f_copy(a->unk4, D_8032D000->unk4);
    a->unk4[1] += 110.f;
    func_80289184(&D_8033B6F0[0].unk1C[1], 0x800, 0x20);
    func_80290390(a, D_8033B6F0[0].unk1C[0], D_8033B6F0[0].unk1C[1]);
}

static void CutsceneCapSwitchPress0_6(UNUSED struct LevelCamera *a)
{
    func_802D8050(D_8032CFC4->oBehParams2ndByte + 10);
}

static void unused_802968E8(struct LevelCamera *a)
{
    func_802902A8(a);
    func_80285A8C(a, 30);
}

void CutsceneCapSwitchPress0(struct LevelCamera *a)
{
    f32 sp24;
    s16 sp22, sp20;
    
    D_8033B4DA |= 1;
    D_8033B4DA |= 0x4000;
    
    call_cutscene_func_in_time_range(CutsceneCapSwitchPress0_1, a, 0, 0);
    call_cutscene_func_in_time_range(CutsceneCapSwitchPress0_2, a, 0, 30);
    call_cutscene_func_in_time_range(CutsceneCapSwitchPress0_3, a, 0, -1);
    call_cutscene_func_in_time_range(CutsceneCapSwitchPress0_4, a, 30, -1);
    call_cutscene_func_in_time_range(CutsceneCapSwitchPress0_5, a, 10, 70);
    call_cutscene_func_in_time_range(CutsceneCapSwitchPress0_6, a, 10, 10);
    vec3f_get_dist_and_angle(D_8032D000->unk4, a->unk10, &sp24, &sp22, &sp20);
    
    if (gDialogueResponse != 0)
        D_8033B6F0[4].unk1C[0] = gDialogueResponse;
    
    if ((get_dialog_id() == -1) && (D_8033B6F0[4].unk1C[0] != 0))
    {
        D_8032CFFC = D_8033B6F0[4].unk1C[0];
        if (D_8033B6F0[4].unk1C[0] == 1)
            func_8028FB44(D_8032CFC4->oBehParams2ndByte);
        func_8028FAE0(a);
        func_80285A8C(a, 30);
    }
}

static void CutsceneUnlockKeyDoor0_1(struct LevelCamera *a)
{
    Vec3f sp24, sp18;
    
    vec3f_copy(D_8033B6F0[0].unk4, a->unk10);
    vec3f_copy(D_8033B6F0[1].unk4, a->unk4);
    vec3f_set(sp24, -206.f, 108.f, 234.f);
    vec3f_set(sp18, 48.f, 104.f, -193.f);
    func_8028C5F0(D_8033B6F0[2].unk4, D_8032D000->unk4, sp24, D_8032D000->unk10);
    func_8028C5F0(D_8033B6F0[3].unk4, D_8032D000->unk4, sp18, D_8032D000->unk10);
}

static void CutsceneUnlockKeyDoor0_2(struct LevelCamera *a)
{
    approach_vec3f_exponential(a->unk10, D_8033B6F0[2].unk4, 0.1f, 0.1f, 0.1f);
    approach_vec3f_exponential(a->unk4,  D_8033B6F0[3].unk4, 0.1f, 0.1f, 0.1f);
}

static void CutsceneUnlockKeyDoor0_5(UNUSED struct LevelCamera *a)
{
    approach_f32_exponential(&D_8033B6F0[3].unk4[1], D_8032D000->unk4[1] + 140.f, 0.07f);
}

static void CutsceneUnlockKeyDoor0_6(UNUSED struct LevelCamera *a)
{
}

static void CutsceneUnlockKeyDoor0_3(struct LevelCamera *a)
{
    approach_vec3f_exponential(a->unk10, D_8033B6F0[0].unk4, 0.1f, 0.1f, 0.1f);
    approach_vec3f_exponential(a->unk4,  D_8033B6F0[1].unk4, 0.1f, 0.1f, 0.1f);
}

static void CutsceneUnlockKeyDoor0_4(UNUSED struct LevelCamera *a)
{
    func_8029A494(1);
}

void CutsceneUnlockKeyDoor0(UNUSED struct LevelCamera *a)
{
    call_cutscene_func_in_time_range(CutsceneUnlockKeyDoor0_1, a, 0, 0);
    call_cutscene_func_in_time_range(CutsceneUnlockKeyDoor0_2, a, 0, 123);
    call_cutscene_func_in_time_range(CutsceneUnlockKeyDoor0_3, a, 124, -1);
    call_cutscene_func_in_time_range(CutsceneUnlockKeyDoor0_4, a, 79, 79);
    call_cutscene_func_in_time_range(CutsceneUnlockKeyDoor0_5, a, 70, 110);
    call_cutscene_func_in_time_range(CutsceneUnlockKeyDoor0_6, a, 112, 112);
}

s32 func_80296DDC(struct LevelCamera *a, struct Struct8032E040 b[], struct Struct8032E040 c[])
{
    Vec3f sp24;
    s32 sp20 = 0;
    s32 sp1C = 0;
    
    sp20 = func_80287CFC(a->unk10, b, &D_8033B6E0, &D_8033B6E4);
    sp1C = func_80287CFC(a->unk4,  c, &D_8033B6E0, &D_8033B6E4);
    func_8028A764(a->unk4, a->unk4, -0x8000);
    func_8028A764(a->unk10, a->unk10, -0x8000);
    
    vec3f_set(sp24, -1328.f, 260.f, 4664.f);
    vec3f_add(a->unk4, sp24);
    vec3f_add(a->unk10, sp24);
    sp20 += sp1C;
    return sp1C;
}

static void CutsceneIntroPeach0_3(UNUSED struct LevelCamera *a)
{
    func_802D7F90(20);
}

#if VERSION_US
static void CutsceneIntroPeach0_4(UNUSED struct LevelCamera *a)
{
    SetSound(0x2428FF81, D_803320E0);
}
#endif

static void CutsceneIntroPeachCommon(struct LevelCamera *a)
{
    if (func_80296DDC(a, D_8032DDF0, D_8032DEA8) != 0)
    {
        D_8033B4D8 &= ~0x2000;
        gCutsceneTimer = 0x7FFF;
    }
}

void CutsceneIntroPeach4(struct LevelCamera *a)
{
    if (get_dialog_id() == -1)
    {
        vec3f_copy(D_8033B328.unk0[3], a->unk10);
        vec3f_copy(D_8033B328.unk0[2], a->unk4);
        D_8033B4DA |= 0x4001;
        gCutsceneTimer = 0x8000;
        a->unk30 = 0;
    }
}

static void CutsceneIntroPeach3_2(struct LevelCamera *a)
{
    func_80287CFC(a->unk10, D_8032DF60, &D_8033B6E0, &D_8033B6E4);
    func_80287CFC(a->unk4, D_8032DFD0, &D_8033B6E0, &D_8033B6E4);
}

static void CutsceneIntroPeach2_2(UNUSED struct LevelCamera *a)
{
    D_8032D000->unk1C[1] = 0;
}

static void CutsceneIntroPeach0_1(UNUSED struct LevelCamera *a)
{
    D_8033B230.fieldOfView = 8.f;
    func_8029A478(12);
}

static void CutsceneIntroPeach3_1(UNUSED struct LevelCamera *a)
{
    D_8033B6E0 = 0;
    D_8033B6E4 = 0.1f;
    func_802882A0(4);
}

static void CutsceneIntroPeach3_3(UNUSED struct LevelCamera *a)
{
    func_802882A0(0);
}

static void CutsceneIntroPeach3_4(UNUSED struct LevelCamera *a)
{
    func_802D7F90(33);
}

#if VERSION_US
static void CutsceneIntroPeach2_3(UNUSED struct LevelCamera *a)
{
    func_8028B338();
}
#endif

void CutsceneIntroPeach2(struct LevelCamera *a)
{
#if VERSION_US
    call_cutscene_func_in_time_range(CutsceneIntroPeach2_3, a, 818, 818);
#endif
    func_80299C60(6, 1);
    call_cutscene_func_in_time_range(CutsceneIntroPeach2_1, a, 0, 0);
    call_cutscene_func_in_time_range(CutsceneIntroPeachCommon, a, 0, -1);
    call_cutscene_func_in_time_range(CutsceneIntroPeach2_2, a, 717, 717);
    func_80288C2C(a->unk10, a->unk4, 0x3B00, -0x3B00);
    D_8033B6F0[1].unk4[1] = 400.f;
}

void CutsceneIntroPeach3(struct LevelCamera *a)
{
    UNUSED u32 pad[2];
    
    D_8032D000->unk1C[1] = 0;
    call_cutscene_func_in_time_range(CutsceneIntroPeach3_1, a, 0, 0);
    call_cutscene_func_in_time_range(CutsceneIntroPeach3_2, a, 0, -1);
    call_cutscene_func_in_time_range(CutsceneIntroPeach3_3, a, 70, 70);
    call_cutscene_func_in_time_range(CutsceneIntroPeach3_4, a, 250, 250);
    approach_f32_exponential(&D_8033B6F0[1].unk4[1], 80.f + D_8033B278.unk4 + (D_8032D000->unk4[1] - D_8033B278.unk4) * 1.1f, 0.4f);
    
    if (a->unk4[1] < D_8033B6F0[1].unk4[1])
        a->unk4[1] = D_8033B6F0[1].unk4[1];
    
    D_8033B4DA |= 0x4000;
}

void CutsceneIntroPeach1(UNUSED struct LevelCamera *a)
{
    func_8029A478(2);
}
    
void CutsceneIntroPeach0(struct LevelCamera *a)
{
    func_80299C60(5, 0);
    call_cutscene_func_in_time_range(CutsceneIntroPeach0_1, a, 0, 0);
    call_cutscene_func_in_time_range(CutsceneIntroPeach0_2, a, 65, 65);
    call_cutscene_func_in_time_range(CutsceneIntroPeachCommon, a, 0, 0);
    call_cutscene_func_in_time_range(CutsceneIntroPeach0_3, a, 65, 65);
#if VERSION_US
    call_cutscene_func_in_time_range(CutsceneIntroPeach0_4, a, 83, 83);
#endif

    if ((gCutsceneTimer > 120) && (get_dialog_id() == -1))
        gCutsceneTimer = 0x7FFF;
    
    func_80288C2C(a->unk10, a->unk4, 0x3B00, -0x3B00);
}

static void CutsceneEndWaving0_1(UNUSED struct LevelCamera *a)
{
    func_8028FABC();
}

// 3rd part of data
struct Struct8032E040 D_8032E2B4[35] = {
    {  0,  32, {    58,   -250,    346}},
    {  1,  50, {  -159,   -382,    224}},
    {  2,  37, {     0,   -277,    237}},
    {  3,  15, {     1,    -44,    245}},
    {  4,  35, {     0,    -89,    228}},
    {  5,  15, {    28,      3,    259}},
    {  6,  25, {   -38,   -201,    371}},
    {  7,  20, {  -642,    118,    652}},
    {  8,  25, {   103,    -90,    861}},
    {  9,  25, {   294,    145,    579}},
    { 10,  30, {   220,    -42,    500}},
    { 11,  20, {    10,   -134,    200}},
    { 12,  20, {  -143,   -145,    351}},
    { 13,  14, {  -256,    -65,    528}},
    { 14,  20, {  -251,    -52,    459}},
    { 15,  25, {  -382,    520,    395}},
    { 16,  25, {  -341,    240,    653}},
    { 17,   5, {  -262,    700,    143}},
    { 18,  15, {  -760,     32,     27}},
    { 19,  20, {  -756,     -6,    -26}},
    { 20,  20, {  -613,      5,    424}},
    { 21,  20, {   -22,   -100,    312}},
    { 22,  25, {   212,     80,     61}},
    { 23,  20, {   230,    -28,    230}},
    { 24,  35, {   -83,    -51,    303}},
    { 25,  17, {   126,     90,    640}},
    { 26,   9, {   158,     95,    763}},
    { 27,   8, {   113,    -25,   1033}},
    { 28,  20, {    57,    -53,   1291}},
    { 29,  15, {    73,    -34,   1350}},
    { 30,   7, {     0,     96,   1400}},
    { 31,   8, {   -59,    269,   1450}},
    { 32,  15, {    57,   1705,   1500}},
    {  0,  15, {  -227,    511,   1550}},
    { -1,  15, {  -227,    511,   1600}}
};

struct Struct8032E040 D_8032E3CC[35] = {
    {  0,   0, {   -46,     87,    -15}},
    {  1,   0, {   -38,     91,    -11}},
    {  2,   0, {   -31,     93,    -13}},
    {  3,   0, {   -50,     84,    -16}},
    {  4,   0, {   -52,     83,    -17}},
    {  5,   0, {   -10,     99,      3}},
    {  6,   0, {   -54,     83,    -10}},
    {  7,   0, {   -31,     85,    -40}},
    {  8,   0, {   -34,     91,     19}},
    {  9,   0, {    -9,     95,     28}},
    { 10,   0, {    17,     72,     66}},
    { 11,   0, {    88,     -7,     45}},
    { 12,   0, {    96,     -6,    -26}},
    { 13,   0, {    56,     -1,    -82}},
    { 14,   0, {    40,     65,    -63}},
    { 15,   0, {   -26,     -3,    -96}},
    { 16,   0, {    92,     82,     19}},
    { 17,   0, {    92,     32,     19}},
    { 18,   0, {    92,     32,     19}},
    { 19,   0, {    92,    102,     19}},
    { 20,   0, {   -69,     59,    -70}},
    { 21,   0, {   -77,    109,    -61}},
    { 22,   0, {   -87,     59,    -46}},
    { 23,   0, {   -99,     -3,     11}},
    { 24,   0, {   -99,    -11,      5}},
    { 25,   0, {   -97,     -6,     19}},
    { 26,   0, {   -97,     22,     -7}},
    { 27,   0, {   -98,    -11,    -13}},
    { 28,   0, {   -97,    -11,     19}},
    { 29,   0, {   -91,    -11,     38}},
    { 30,   0, {   -76,    -11,     63}},
    { 31,   0, {   -13,     33,     93}},
    { 32,   0, {    51,    -11,     84}},
    { 33,   0, {    51,    -11,     84}},
    { -1,   0, {    51,    -11,     84}}
};

struct Struct8032E040 D_8032E4E4[9] = {
    {  0,   0, {    -5,    975,   -917}},
    {  0,   0, {    -5,    975,   -917}},
    {  0,   0, {    -5,    975,   -917}},
    {  0,   0, {   -76,   1067,    742}},
    {  0,   0, {  -105,   1576,   3240}},
    {  0,   0, {  -177,   1709,   5586}},
    {  0,   0, {  -177,   1709,   5586}},
    {  0,   0, {  -177,   1709,   5586}},
    {  0,   0, {  -177,   1709,   5586}}
};

struct Struct8032E040 D_8032E52C[9] = {
    {  0,  50, {    18,   1013,  -1415}},
    {  0, 100, {    17,   1037,  -1412}},
    {  0, 100, {    16,   1061,  -1408}},
    {  0, 100, {   -54,   1053,    243}},
    {  0, 100, {   -84,   1575,   2740}},
    {  0,  50, {  -156,   1718,   5086}},
    {  0,   0, {  -156,   1718,   5086}},
    {  0,   0, {  -156,   1718,   5086}},
    {  0,   0, {  -156,   1718,   5086}}
};

void CutsceneEndWaving0(struct LevelCamera *a)
{
    call_cutscene_func_in_time_range(CutsceneEndWaving0_1, a, 0, 0);
    func_80287CFC(a->unk10, D_8032E4E4, &D_8033B6E0, &D_8033B6E4);
    func_80287CFC(a->unk4,  D_8032E52C, &D_8033B6E0, &D_8033B6E4);
    func_80299C60(6, 120);
}

static void CutsceneCredits0_1(UNUSED struct LevelCamera *a)
{
    func_8028FABC();
}

extern struct Struct8032E040 D_8032E924[5];
extern struct Struct8032E040 D_8032E94C[5];
extern struct Struct8032E040 D_8032E974[5];
extern struct Struct8032E040 D_8032E99C[5];
extern struct Struct8032E040 D_8032E9C4[5];
extern struct Struct8032E040 D_8032E9EC[5];
extern struct Struct8032E040 D_8032EA14[5];
extern struct Struct8032E040 D_8032EA3C[5];
extern struct Struct8032E040 D_8032EA64[4];
extern struct Struct8032E040 D_8032EA84[4];
extern struct Struct8032E040 D_8032EAA4[5];
extern struct Struct8032E040 D_8032EACC[5];
extern struct Struct8032E040 D_8032EAF4[3];
extern struct Struct8032E040 D_8032EB0C[3];
extern struct Struct8032E040 D_8032EB24[6];
extern struct Struct8032E040 D_8032EB54[6];
extern struct Struct8032E040 D_8032EB84[6];
extern struct Struct8032E040 D_8032EBB4[6];
extern struct Struct8032E040 D_8032EBE4[7];
extern struct Struct8032E040 D_8032EC1C[7];
extern struct Struct8032E040 D_8032EC54[4];
extern struct Struct8032E040 D_8032EC74[4];
extern struct Struct8032E040 D_8032EC94[4];
extern struct Struct8032E040 D_8032ECB4[4];
extern struct Struct8032E040 D_8032ECD4[6];
extern struct Struct8032E040 D_8032ED04[6];
extern struct Struct8032E040 D_8032ED34[7];
extern struct Struct8032E040 D_8032ED6C[7];
extern struct Struct8032E040 D_8032EDA4[4];
extern struct Struct8032E040 D_8032EDC4[4];
extern struct Struct8032E040 D_8032EDE4[4];
extern struct Struct8032E040 D_8032EE04[4];
extern struct Struct8032E040 D_8032EE24[5];
extern struct Struct8032E040 D_8032EE4C[5];
extern struct Struct8032E040 D_8032EE74[5];
extern struct Struct8032E040 D_8032EE9C[5];
extern struct Struct8032E040 D_8032EEC4[5];
extern struct Struct8032E040 D_8032EEEC[5];
extern struct Struct8032E040 D_8032EF14[4];
extern struct Struct8032E040 D_8032EF34[4];

void CutsceneCredits0(struct LevelCamera *a)
{
    struct Struct8032E040 *sp34, *sp30;
    
    call_cutscene_func_in_time_range(CutsceneCredits0_1, a, 0, 0);
    
    #define SET_CREDITS_PRESET(casenum, arg1, arg2) \
        case casenum: \
            sp30 = arg1; \
            sp34 = arg2; \
            break;
    
    switch (D_8032CFD8)
    {
    SET_CREDITS_PRESET(145, D_8032E924, D_8032E94C);
    SET_CREDITS_PRESET(385, D_8032E974, D_8032E99C);
    SET_CREDITS_PRESET(193, D_8032E9C4, D_8032E9EC);
    SET_CREDITS_PRESET(82,  D_8032EA14, D_8032EA3C);
    SET_CREDITS_PRESET(65 , D_8032EA64, D_8032EA84);
    SET_CREDITS_PRESET(113, D_8032EAA4, D_8032EACC);
    SET_CREDITS_PRESET(211, D_8032EAF4, D_8032EB0C);
    SET_CREDITS_PRESET(354, D_8032EB24, D_8032EB54);
    SET_CREDITS_PRESET(129, D_8032EB84, D_8032EBB4);
    SET_CREDITS_PRESET(369, D_8032EBE4, D_8032EC1C);
    SET_CREDITS_PRESET(161, D_8032EC54, D_8032EC74);
    SET_CREDITS_PRESET(177, D_8032EC94, D_8032ECB4);
    SET_CREDITS_PRESET(577, D_8032ECD4, D_8032ED04);
    SET_CREDITS_PRESET(209, D_8032ED34, D_8032ED6C);
    SET_CREDITS_PRESET(225, D_8032EDA4, D_8032EDC4);
    SET_CREDITS_PRESET(241, D_8032EDE4, D_8032EE04);
    SET_CREDITS_PRESET(321, D_8032EE24, D_8032EE4C);
    SET_CREDITS_PRESET(449, D_8032EE74, D_8032EE9C);
    SET_CREDITS_PRESET(370, D_8032EEC4, D_8032EEEC);
    case 81:
        if (save_file_get_star_flags(gCurrSaveFileNum - 1, gCurrCourseNum - 1) & 0x10)
        {
            sp30 = D_8032EF14;
            sp34 = D_8032EF34;
        }
        else
        {
            sp30 = D_8032EF14;
            sp34 = D_8032EF34;
        }
        break;
    default:
        sp30 = D_8032EF14;
        sp34 = D_8032EF34;
    }
    
    #undef SET_CREDITS_PRESET
    
    func_8028FBD8(D_8033B4E0, sp30);
    func_8028FBD8(D_8033B5E0, sp34);
    func_80287CFC(a->unk10, D_8033B4E0, &D_8033B6E0, &D_8033B6E4);
    func_80287CFC(a->unk4, D_8033B5E0, &D_8033B6E0, &D_8033B6E4);
    func_8028FEFC(a, -0x2000, 0x2000, -0x4000, 0x4000);
}

static void CutsceneSlidingDoorsOpen0_1(struct LevelCamera *a)
{
    f32 sp24;
    s16 sp22, sp20;
    
    vec3f_get_dist_and_angle(D_8032D000->unk4, a->unk10, &sp24, &sp22, &sp20);
    
    if (sp24 < 500.f)
    {
        sp24 = 500.f;
        sp20 = D_8032D000->unk10[1] + 0x8800;
        sp22 = 0x800;
    }
    
    vec3f_set_dist_and_angle(D_8032D000->unk4, a->unk10, sp24, sp22, sp20);
}

static void CutsceneSlidingDoorsOpen0_2(UNUSED struct LevelCamera *a)
{
    vec3f_copy(D_8033B6F0[1].unk4, D_8032D000->unk4);
    vec3s_copy(D_8033B6F0[0].unk1C, D_8032D000->unk10);
    vec3f_set(D_8033B6F0[0].unk4, 80.f, 325.f, 200.f);
}

static void CutsceneSlidingDoorsOpen0_3(UNUSED struct LevelCamera *a)
{
    func_802893E4(&D_8033B6F0[0].unk4[1], 75.f, 10.f);
}

static void CutsceneSlidingDoorsOpen0_4(UNUSED struct LevelCamera *a)
{
    func_802893E4(&D_8033B6F0[0].unk4[1], 125.f, 10.f);
}

static void CutsceneSlidingDoorsOpen0_5(struct LevelCamera *a)
{
    Vec3f sp34;
    UNUSED u32 pad[4];
    
    vec3f_copy(sp34, a->unk10);
    D_8033B6F0[1].unk4[0] = D_8032D000->unk4[0];
    D_8033B6F0[1].unk4[2] = D_8032D000->unk4[2];
    approach_f32_exponential(&D_8033B6F0[0].unk4[0], 0, 0.1f);
    func_802893E4(&D_8033B6F0[0].unk4[2], 125.f, 50.f);
    approach_vec3s_exponential(D_8033B6F0[0].unk1C, D_8032D000->unk10, 16, 16, 16);
    func_8028C5F0(sp34, D_8033B6F0[1].unk4, D_8033B6F0[0].unk4, D_8033B6F0[0].unk1C);
    approach_vec3f_exponential(a->unk10, sp34, 0.15f, 0.05f, 0.15f);
    func_8028C3CC(a, 0, 125.f, 0, 0);
}

void CutsceneSlidingDoorsOpen0(struct LevelCamera *a)
{
    UNUSED u32 pad[2];
    
    func_8028FEDC(a);
    call_cutscene_func_in_time_range(CutsceneSlidingDoorsOpen0_1, a, 0, 8);
    call_cutscene_func_in_time_range(CutsceneSlidingDoorsOpen0_2, a, 8, 8);
    call_cutscene_func_in_time_range(CutsceneSlidingDoorsOpen0_3, a, 8, 28);
    call_cutscene_func_in_time_range(CutsceneSlidingDoorsOpen0_4, a, 29, -1);
    call_cutscene_func_in_time_range(CutsceneSlidingDoorsOpen0_5, a, 8, -1);
}

void CutsceneDoubleDoorsOpen1(struct LevelCamera *a)
{
    func_80290514(a);
    a->unk30 = 0;
    D_8033B4DA |= 1;
}

void CutsceneEnterPainting0_1(UNUSED struct LevelCamera *a)
{
}

void CutsceneEnterPainting0(struct LevelCamera *a)
{
    struct Surface *sp54, *sp50;
    Vec3f sp44, sp38, sp2C;
    Vec3s sp24;
    f32 sp20;
    
    call_cutscene_func_in_time_range(CutsceneEnterPainting0_1, a, 0, 0);
    func_8029A478(6);
    D_8033B4DA |= 1;
    
    if (D_8035FFA8 != NULL)
    {
        sp24[0] = 0;
        sp24[1] = (D_8035FFA8->unkC / 360.f) * 65536.f;
        sp24[2] = 0;
        
        sp2C[0] = D_8035FFA8->unk74 / 2.0f;
        sp2C[1] = sp2C[0];
        sp2C[2] = 0;
        
        sp44[0] = D_8035FFA8->unk10;
        sp44[1] = D_8035FFA8->unk14;
        sp44[2] = D_8035FFA8->unk18;
        
        func_8028C5F0(sp38, sp44, sp2C, sp24);
        approach_vec3f_exponential(a->unk4, sp38, 0.1f, 0.1f, 0.1f);
        sp2C[2] = -(((D_8035FFA8->unk74 * 1000.f) / 2.0f) / 307.f);
        func_8028C5F0(sp38, sp44, sp2C, sp24);
        sp20 = find_floor(sp38[0], sp38[1] + 500.f, sp38[2], &sp50) + 125.f;
        
        if (sp38[1] < sp20)
            sp38[1] = sp20;
        
        if (a->unk30 == 134)
            approach_vec3f_exponential(a->unk10, sp38, 0.2f, 0.1f, 0.2f);
        else
            approach_vec3f_exponential(a->unk10, sp38, 0.9f, 0.9f, 0.9f);
        
        find_floor(D_8032D000->unk4[0], D_8032D000->unk4[1] + 50.f, D_8032D000->unk4[2], &sp54);
        
        if ((sp54->type < 166) || (sp54->type > 249))
        {
            a->unk30 = 0;
            gCutsceneTimer = 0x8000;
            D_8033B4DA |= 1;
        }
    }
    a->preset = CAMERA_PRESET_CLOSE;
}

void CutsceneExitPainting80298094(struct LevelCamera *a)
{
    struct Surface *sp1C;
    f32 sp18;
    
    vec3f_set(D_8033B6F0[2].unk4, 258.f, -352.f, 1189.f);
    vec3f_set(D_8033B6F0[1].unk4, 65.f, -155.f, 444.f);
    
    if (D_8032CFDC == LEVEL_TTM)
    {
        D_8033B6F0[1].unk4[1] = 0.f;
        D_8033B6F0[1].unk4[2] = 0.f;
    }
    vec3f_copy(D_8033B6F0[0].unk4, D_8032D000->unk4);
    D_8033B6F0[0].unk1C[0] = 0;
    D_8033B6F0[0].unk1C[1] = D_8032D000->unk10[1];
    D_8033B6F0[0].unk1C[2] = 0;
    func_8028C5F0(a->unk4, D_8033B6F0[0].unk4, D_8033B6F0[1].unk4, D_8033B6F0[0].unk1C);
    func_8028C5F0(a->unk10, D_8033B6F0[0].unk4, D_8033B6F0[2].unk4, D_8033B6F0[0].unk1C);
    sp18 = find_floor(a->unk10[0], a->unk10[1] + 10.f, a->unk10[2], &sp1C);
    
    if (sp18 != -11000.f)
    {
        if (a->unk10[1] < (sp18 += 60.f))
            a->unk10[1] = sp18;
    }
}

void CutsceneExitPainting80298230(struct LevelCamera *a)
{
    Vec3f sp1C;
    
    approach_f32_exponential(&D_8033B6F0[2].unk4[0], 178.f, 0.05f);
    approach_f32_exponential(&D_8033B6F0[2].unk4[2], 889.f, 0.05f);
    func_8028C5F0(sp1C, D_8033B6F0[0].unk4, D_8033B6F0[2].unk4, D_8033B6F0[0].unk1C);
    a->unk10[0] = sp1C[0];
    a->unk10[2] = sp1C[2];
}

void CutsceneExitPainting802982CC(struct LevelCamera *a)
{
    struct Surface *sp2C;
    Vec3f sp20;
    
    vec3f_copy(sp20, D_8032D000->unk4);
    sp20[1] = find_floor(D_8032D000->unk4[0], D_8032D000->unk4[1] + 10.f, D_8032D000->unk4[2], &sp2C);
    
    if (sp2C != NULL)
    {
        sp20[1] = sp20[1] + (D_8032D000->unk4[1] - sp20[1]) * 0.7f + 125.f;
        approach_vec3f_exponential(a->unk4, sp20, 0.2f, 0.2f, 0.2f);
    
        if (sp20[1] < a->unk10[1])
            approach_f32_exponential(&a->unk10[1], sp20[1], 0.05f);
    }
}

void CutsceneExitPainting0(struct LevelCamera *a)
{
    call_cutscene_func_in_time_range(CutsceneExitPainting80298094, a, 0, 0);
    call_cutscene_func_in_time_range(CutsceneExitPainting80298230, a, 5, -1);
    call_cutscene_func_in_time_range(CutsceneExitPainting802982CC, a, 5, -1);
    
    if (D_8032CFDC == LEVEL_TTM)
    {
        vec3f_set(a->unk10, -296.f, 1261.f, 3521.f);
    }
    
    func_8028FA74(a);
}

void Cutscene11Todo_0(struct LevelCamera *a)
{
    UNUSED Vec3f sp3C;
    UNUSED Vec3s sp34;
    Vec3f sp28;
    Vec3s sp20;
    
    vec3f_set(sp28, 200.f, 300.f, 200.f);
    vec3s_set(sp20, 0, D_8032D000->unk10[1], 0);
    func_8028C5F0(a->unk10, D_8032D000->unk4, sp28, sp20);
    func_8028C3CC(a, 0.f, 125.f, 0.f, 0);
}

void Cutscene11Todo_1(struct LevelCamera *a)
{
    Vec3f sp24;
    
    vec3f_set(sp24, D_8032D000->unk4[0], D_8032D000->unk4[1] + 125.f, D_8032D000->unk4[2]);
    func_8028C3CC(a, 0.f, 125.f, 0.f, 0);
    approach_vec3f_exponential(a->unk4, sp24, 0.02f, 0.001f, 0.02f);
    func_8028FA74(a);
}

void CutsceneExitPainting1(struct LevelCamera *a)
{
    a->preset = CAMERA_PRESET_CLOSE;
    a->unk30 = 0;
    gCutsceneTimer = 0x8000;
    D_8033B4DA |= 1;
    D_8033B4DA &= ~2;
    func_8028FA74(a);
}

void CutsceneEnterCannon2(struct LevelCamera *a)
{
    D_8033B4DA &= ~1;
    D_8033B4DA |= 2;
    a->preset = CAMERA_PRESET_INSIDE_CANNON;
    a->unk30 = 0;
    D_8033B410 = 800.f;
}

void CutsceneEnterCannon1(struct LevelCamera *a)
{
    struct Object *sp44;
    UNUSED u32 pad[2];
    f32 sp38;
    struct Surface *sp34;
    Vec3f sp28;
    Vec3s sp20;
    
    call_cutscene_func_in_time_range(CutsceneEnterSomething8029041C, a, 70, 70);
    D_8033B4DA |= 1;
    func_80289184(&D_8033B6F0[1].unk1C[0], 0, 0x80);
    func_80289184(&D_8033B6F0[2].unk1C[0], 0, 0x80);
    vec3f_set_dist_and_angle(D_8033B6F0[0].unk4, a->unk10, D_8033B6F0[1].unk4[2], D_8033B6F0[1].unk1C[0], D_8033B6F0[1].unk1C[1]);
    D_8033B6F0[1].unk4[2] = approach_f32(D_8033B6F0[1].unk4[2], 400.f, 5.f, 5.f);
    D_8033B6F0[1].unk1C[1] += 0x40;
    D_8033B6F0[3].unk4[1] += 2.f;
    a->unk10[1] += D_8033B6F0[3].unk4[1];
    
    if ((sp44 = D_8032D000->unk20) != NULL)
    {
        D_8033B6F0[0].unk4[1] = sp44->oPosY;
        sp20[0] = sp44->oMoveAnglePitch;
        sp20[1] = sp44->oMoveAngleYaw;
        sp20[2] = sp44->oMoveAngleRoll;
        a->unk4[0] = sp44->oPosX;
        a->unk4[1] = sp44->oPosY;
        a->unk4[2] = sp44->oPosZ;
        sp28[0] = 0.f;
        sp28[1] = 100.f;
        sp28[2] = 0.f;
        func_8028C5F0(a->unk4, a->unk4, sp28, sp20);
    }
    
    sp38 = find_floor(a->unk10[0], a->unk10[1] + 500.f, a->unk10[2], &sp34) + 100.f;
    
    if (a->unk10[1] < sp38)
        a->unk10[1] = sp38;
}

void CutsceneEnterCannon0(struct LevelCamera *a)
{
    UNUSED u32 pad[2];
    struct Object *sp24;
    
    D_8033B4DA |= 1;
    D_8032D000->unk1C[1] = 0;
    
    if ((sp24 = D_8032D000->unk20) != NULL)
    {
        D_8033B6F0[0].unk4[0] = sp24->oPosX;
        D_8033B6F0[0].unk4[1] = sp24->oPosY;
        D_8033B6F0[0].unk4[2] = sp24->oPosZ;
        D_8033B6F0[0].unk1C[0] = sp24->oMoveAnglePitch;
        D_8033B6F0[0].unk1C[1] = sp24->oMoveAngleYaw;
        D_8033B6F0[0].unk1C[2] = sp24->oMoveAngleRoll;
    }
    
    vec3f_get_dist_and_angle(D_8033B6F0[0].unk4, a->unk10, &D_8033B6F0[1].unk4[2], &D_8033B6F0[1].unk1C[0], &D_8033B6F0[1].unk1C[1]);
    D_8033B6F0[3].unk4[1] = 0.f;
    D_8033B6F0[4].unk4[1] = 0.f;
}

void CutsceneDoor0(struct LevelCamera *a)
{
    vec3f_copy(D_8033B6F0[0].unk4, a->unk10);
    vec3f_copy(D_8033B6F0[1].unk4, a->unk4);
}

void CutsceneDoor1(struct LevelCamera *a)
{
    vec3f_copy(a->unk10, D_8033B6F0[0].unk4);
    vec3f_copy(a->unk4, D_8033B6F0[1].unk4);
}

void CutsceneDoorWarp1(struct LevelCamera *a)
{
    if ((D_8032D000->unk0 != 0x1320) & (D_8032D000->unk0 != 0x1321)) //! bitwise AND instead of boolean
    {
        gCutsceneTimer = 0x8000;
        a->unk30 = 0;
    }
}

void CutsceneDoor2(struct LevelCamera *a)
{
    Vec3f sp24;
    s16 sp22;
    
    func_8028FEDC(a);
    func_8028C7EC(&sp22);
    func_8028C3CC(a, 0.f, 125.f, 0.f, 0);
    vec3s_set(D_8033B6F0[0].unk1C, 0, D_8032D000->unk10[1] + sp22, 0);
    vec3f_set(sp24, 0.f, 125.f, 250.f);
    
    if (sp22 == 0) //! useless code
        sp24[0] = 0.f;
    else
        sp24[0] = 0.f;
    
    func_8028C5F0(a->unk10, D_8032D000->unk4, sp24, D_8033B6F0[0].unk1C);
}

void CutsceneDoor3(struct LevelCamera *a)
{
    s16 sp26, sp24;
    f32 sp20;
    
    func_8028C3CC(a, 0.f, 125.f, 0.f, 0);
    vec3f_get_dist_and_angle(a->unk4, a->unk10, &sp20, &sp26, &sp24);
    func_802893E4(&sp20, 150.f, 7.f);
    vec3f_set_dist_and_angle(a->unk4, a->unk10, sp20, sp26, sp24);
    func_8028FA74(a);
}

void CutsceneDoor4(struct LevelCamera *a)
{
    if (a->unk1 == 16)
        a->preset = CAMERA_PRESET_FREE_ROAM;
    else
        a->preset = CAMERA_PRESET_CLOSE;
    
    a->unk30 = 0;
    gCutsceneTimer = 0x8000;
    D_8033B4DA |= 1;
    D_8033B4DA &= ~2;
    func_80290514(a);
    func_8028FA74(a);
}

void CutsceneDoorAB_2(struct LevelCamera *a)
{
    UNUSED u32 pad[2];
    
    func_8028FEDC(a);
    func_8028E88C(a);
    
    if (a->preset == CAMERA_PRESET_FIXED_REF_POINT)
        a->unk3A = CameraChange0D(a, a->unk4, a->unk10);
    if (a->preset == CAMERA_PRESET_UNKNOWN_0C)
        a->unk3A = CameraChange0C(a, a->unk4, a->unk10);
    
    a->angle = a->unk3A;
    
    if ((D_8032D000->unk0 != 0x1331) && (D_8032D000->unk0 != 0x1320) && (D_8032D000->unk0 != 0x1321))
    {
        gCutsceneTimer = 0x8000;
        a->unk30 = 0;
    }
}

// Cutscene Tables
struct CutsceneTableEntry TableCutscenePeachEnd[12] = {
    {CutscenePeachEnd0,    170},
    {CutscenePeachEnd1,     70},
    {CutscenePeachEnd2,     75},
    {CutscenePeachEnd3,    386},
    {CutscenePeachEnd4,    139},
    {CutscenePeachEnd5,    590},
    {CutscenePeachEnd6,     95},
    {CutscenePeachEnd7,    425},
    {CutscenePeachEnd8,    236},
    {CutscenePeachEnd9,    245},
    {CutscenePeachEndA,  32767},
    {CutscenePeachEndB,      0}
};

struct CutsceneTableEntry TableCutsceneGrandStar[2] = {
    {CutsceneGrandStar0,   360},
    {CutsceneGrandStar1, 32767}
};

struct CutsceneTableEntry TableCutscene0FTodo[2] = {
    {Cutscene0FTodo0,     1},
    {Cutscene0FTodo1, 32767}
};

struct CutsceneTableEntry TableCutsceneDoorWarp[2] = {
    {CutsceneDoor0,         1},
    {CutsceneDoorWarp1, 32767}
};

struct CutsceneTableEntry TableCutsceneEndWaving[1] = {
    {CutsceneEndWaving0, 32767}
};

struct CutsceneTableEntry TableCutsceneCredits[1] = {
    {CutsceneCredits0, 32767}
};

struct CutsceneTableEntry TableCutsceneDoor00[5] = {
    {CutsceneDoor0,     1},
    {CutsceneDoor1,    30},
    {CutsceneDoor2,     1},
    {CutsceneDoor3,    50},
    {CutsceneDoor4,     0}
};

struct CutsceneTableEntry TableCutsceneDoor01[5] = {
    {CutsceneDoor0,     1},
    {CutsceneDoor1,    20},
    {CutsceneDoor2,     1},
    {CutsceneDoor3,    50},
    {CutsceneDoor4,     0}
};

struct CutsceneTableEntry TableCutsceneDoor0A[3] = {
    {CutsceneDoor0,        1},
    {CutsceneDoor1,       30},
    {CutsceneDoorAB_2, 32767}
};

struct CutsceneTableEntry TableCutsceneDoor0B[3] = {
    {CutsceneDoor0,        1},
    {CutsceneDoor1,       20},
    {CutsceneDoorAB_2, 32767}
};

struct CutsceneTableEntry TableCutsceneEnterCannon[3] = {
    {CutsceneEnterCannon0,   1},
    {CutsceneEnterCannon1, 121},
    {CutsceneEnterCannon2,   0}
};

struct CutsceneTableEntry TableCutsceneStarSpawn[3] = {
    {CutsceneStarSpawn0, 32767},
    {CutsceneStarSpawn1,    15},
    {CutsceneStarSpawn2,     0}
};

struct CutsceneTableEntry TableCutsceneSpecialStarSpawn[2] = {
    {CutsceneSpecialStarSpawn0, 32767},
    {CutsceneSpecialStarSpawn1,     0}
};

struct CutsceneTableEntry TableCutsceneEnterPainting[1] = {
    {CutsceneEnterPainting0, 32767}
};

struct CutsceneTableEntry TableCutsceneExitPaintingDeath[2] = {
    {CutsceneExitPainting0, 118},
    {CutsceneExitPainting1,   0}
};

struct CutsceneTableEntry TableCutsceneExitPaintingSuccess[2] = {
    {CutsceneExitPainting0, 180},
    {CutsceneExitPainting1,   0}
};

struct CutsceneTableEntry TableCutscene11Todo[3] = {
    {Cutscene11Todo_0,       1},
    {Cutscene11Todo_1,      60},
    {CutsceneExitPainting1,  0}
};

struct CutsceneTableEntry TableCutsceneIntroPeach[5] = {
    {CutsceneIntroPeach0, 32767},
    {CutsceneIntroPeach1,    35},
    {CutsceneIntroPeach2,   820},
    {CutsceneIntroPeach3,   270},
    {CutsceneIntroPeach4, 32767}
};

struct CutsceneTableEntry TableCutscenePrepareCannon[2] = {
    {CutscenePrepareCannon0, 170},
    {CutscenePrepareCannon1,   0}
};

struct CutsceneTableEntry TableCutsceneExitWaterfall[2] = {
    {CutsceneExitWaterfall0, 52},
    {CutsceneFallCommon1,     0}
};

struct CutsceneTableEntry TableCutsceneFallToCastleGrounds[2] = {
    {CutsceneFallToCastleGrounds0, 73},
    {CutsceneFallCommon1,           0}
};

struct CutsceneTableEntry TableCutsceneEnterPyramidTop[2] = {
    {CutsceneEnterPyramidTop0, 90},
    {CutsceneFallCommon1,       0}
};

struct CutsceneTableEntry TableCutscene26Todo[3] = {
    {Cutscene26Todo0, 32767},
    {Cutscene26Todo1,   150},
    {Cutscene26Todo2,     0}
};

struct CutsceneTableEntry TableCutsceneDeath1[1] = {
    {CutsceneDeath1, 32767}
};

struct CutsceneTableEntry TableCutsceneEnterPool[2] = {
    {CutsceneEnterPool0,  100},
    {CutsceneFallCommon1,   0}
};

struct CutsceneTableEntry TableCutsceneDeath2[1] = {
    {CutsceneDeath2, 32767}
};

struct CutsceneTableEntry TableCutsceneBBHDeath[1] = {
    {CutsceneBBHDeath0, 32767}
};

struct CutsceneTableEntry TableCutsceneQuicksandDeath[2] = {
    {CutsceneQuicksandDeath0, 32767},
    {CutsceneQuicksandDeath0, 32767}
};

struct CutsceneTableEntry TableCutscene1ATodo[1] = {
    {Cutscene1ATodo0, 32767}
};

struct CutsceneTableEntry TableCutsceneEnterBowserPlatform[3] = {
    {CutsceneEnterBowserPlatform0,   180},
    {CutsceneEnterBowserPlatform1, 32767},
    {CutsceneEnterBowserPlatform2,     0}
};

struct CutsceneTableEntry TableCutsceneStarDance1[1] = {
    {CutsceneStarDance1, 32767}
};

struct CutsceneTableEntry TableCutsceneStarDance2[1] = {
    {CutsceneStarDance2, 32767}
};

struct CutsceneTableEntry TableCutsceneStarDance3[1] = {
    {CutsceneStarDance3, 32767}
};

struct CutsceneTableEntry TableCutsceneKeyDance[1] = {
    {CutsceneKeyDance0, 32767}
};

struct CutsceneTableEntry TableCutsceneCapSwitchPress[1] = {
    {CutsceneCapSwitchPress0, 32767}
};

struct CutsceneTableEntry TableCutsceneSlidingDoorsOpen[2] = {
    {CutsceneSlidingDoorsOpen0, 50},
    {CutsceneDoubleDoorsOpen1,   0}
};

struct CutsceneTableEntry TableCutsceneUnlockKeyDoor[2] = {
    {CutsceneUnlockKeyDoor0,   200},
    {CutsceneDoubleDoorsOpen1,   0}
};

struct CutsceneTableEntry TableCutsceneExitBowserSuccess[2] = {
    {CutsceneExitBowserSuccess0, 190},
    {CutsceneExitNonPainting1,     0}
};

struct CutsceneTableEntry TableCutscene1CTodo[2] = {
    {Cutscene1CTodo_0,         120},
    {CutsceneExitNonPainting1,   0}
};

struct CutsceneTableEntry TableCutsceneBBHExitSuccess[2] = {
    {CutsceneBBHExitSuccess0,  163},
    {CutsceneExitNonPainting1,   0}
};

struct CutsceneTableEntry TableCutsceneNonPaintingDeath[2] = {
    {CutsceneNonPaintingDeath0, 120},
    {CutsceneExitNonPainting1,    0}
};

struct CutsceneTableEntry TableCutsceneDialog[3] = {
    {CutsceneDialog0, 32767},
    {CutsceneDialog1,    12},
    {CutsceneDialog2,     0}
};

struct CutsceneTableEntry TableCutsceneReadMessage[3] = {
    {CutsceneReadMessage0, 32767},
    {CutsceneReadMessage1,    15},
    {CutsceneReadMessage2,     0}
};

u8 D_8032E8A4[27][4] = {
    {0x44, 0x44, 0x44, 0x04},
    {0x00, 0x20, 0x22, 0x04},
    {0x00, 0x00, 0x02, 0x04},
    {0x22, 0x22, 0x22, 0x04},
    {0x00, 0x22, 0x00, 0x04},
    {0x22, 0x22, 0x22, 0x04},
    {0x22, 0x22, 0x22, 0x04},
    {0x12, 0x12, 0x12, 0x04},
    {0x02, 0x22, 0x22, 0x04},
    {0x22, 0x22, 0x22, 0x04},
    {0x20, 0x20, 0x20, 0x04},
    {0x22, 0x01, 0x22, 0x04},
    {0x00, 0x00, 0x00, 0x04},
    {0x11, 0x11, 0x12, 0x04},
    {0x22, 0x22, 0x22, 0x04},
    {0x00, 0x00, 0x00, 0x04},
    {0x43, 0x44, 0x44, 0x04},
    {0x43, 0x44, 0x44, 0x04},
    {0x43, 0x44, 0x44, 0x04},
    {0x42, 0x44, 0x44, 0x04},
    {0x44, 0x44, 0x44, 0x04},
    {0x40, 0x44, 0x44, 0x04},
    {0x42, 0x44, 0x44, 0x04},
    {0x40, 0x44, 0x44, 0x04},
    {0x42, 0x44, 0x44, 0x04},
    {0x44, 0x44, 0x44, 0x04},
    {0x44, 0x44, 0x44, 0x04}
};

u8 D_8032E910[20] = {0x00, 0x00, 0x10, 0x00, 0x11, 0x11, 0x30, 0x10, 0x11, 0x10, 0x10, 0x01, 0x01, 0x00, 0x10, 0x11, 0x10, 0x01, 0x01, 0x00};

struct Struct8032E040 D_8032E924[5] = {
    {  1,   0, {  5984,   3255,   4975}},
    {  2,   0, {  4423,   3315,   1888}},
    {  3,   0, {   776,   2740,  -1825}},
    {  4,   0, {  -146,   3894,  -3167}},
    { -1,   0, {   741,   4387,  -5474}}
};

struct Struct8032E040 D_8032E94C[5] = {
    {  0,  30, {  5817,   3306,   4507}},
    {  0,  40, {  4025,   3378,   1593}},
    {  0,  50, {  1088,   2652,  -2205}},
    {  0,  60, {   205,   3959,  -3517}},
    { -1,  60, {  1231,   4400,  -5649}}
};

struct Struct8032E040 D_8032E974[5] = {
    {  0,   0, {  -301,   1399,   2643}},
    {  0,   0, {  -182,   2374,   4572}},
    {  0,   0, {  4696,   3864,    413}},
    {  0,   0, {  1738,   4891,  -1516}},
    { -1,   0, {  1783,   4891,  -1516}}
};

struct Struct8032E040 D_8032E99C[5] = {
    {  1,  30, {  -249,   1484,   2153}},
    {  2,  40, {  -200,   2470,   4082}},
    {  3,  40, {  4200,   3916,    370}},
    {  4,  40, {  1523,   4976,  -1072}},
    { -1,  40, {  1523,   4976,  -1072}}
};

struct Struct8032E040 D_8032E9C4[5] = {
    {  0,   0, {  5538,  -4272,   2376}},
    {  0,   0, {  5997,  -3303,   2261}},
    {  0,   0, {  6345,  -3255,   2179}},
    {  0,   0, {  6345,  -3255,   2179}},
    { -1,   0, {  6694,  -3203,   2116}}
};

struct Struct8032E040 D_8032E9EC[5] = {
    {  0,  50, {  5261,  -4683,   2443}},
    {  0,  50, {  5726,  -3675,   2456}},
    {  0,  50, {  6268,  -2817,   2409}},
    {  0,  50, {  6596,  -2866,   2369}},
    { -1,  50, {  7186,  -3153,   2041}}
};

struct Struct8032E040 D_8032EA14[5] = {
    {  0,   0, { -6324,   6745,  -5626}},
    {  1,   0, { -6324,   6745,  -5626}},
    {  2,   0, { -6108,   6762,  -5770}},
    {  3,   0, { -5771,   6787,  -5962}},
    { -1,   0, { -5672,   6790,  -5979}}
};

struct Struct8032E040 D_8032EA3C[5] = {
    {  0,  50, { -5911,   6758,  -5908}},
    {  1,  50, { -5911,   6758,  -5908}},
    {  2,  50, { -5652,   6814,  -5968}},
    {  3,  50, { -5277,   6801,  -6043}},
    { -1,  50, { -5179,   6804,  -6060}}
};

struct Struct8032E040 D_8032EA64[4] = {
    {  1,   0, {  1088,    341,   2447}},
    {  2,   0, {  1338,    610,   2808}},
    {  3,   0, {  2267,   1612,   2966}},
    { -1,   0, {  2296,   1913,   2990}}
};

struct Struct8032E040 D_8032EA84[4] = {
    {  1,  50, {  1160,    263,   1958}},
    {  2,  50, {  1034,    472,   2436}},
    {  3,  50, {  1915,   1833,   2688}},
    { -1,  50, {  2134,   2316,   2742}}
};

struct Struct8032E040 D_8032EAA4[5] = {
    {  1,   0, { -5952,   1807,  -5882}},
    {  2,   0, { -5623,   1749,  -4863}},
    {  3,   0, { -5472,   1955,  -2520}},
    {  4,   0, { -5544,   1187,  -1085}},
    { -1,   0, { -5547,    391,   -721}}
};

struct Struct8032E040 D_8032EACC[5] = {
    {  1, 210, { -5952,   1884,  -6376}},
    {  2,  58, { -5891,   1711,  -5283}},
    {  3,  30, { -5595,   1699,  -2108}},
    {  4,  31, { -5546,    794,   -777}},
    { -1,  31, { -5548,    -85,   -572}}
};

struct Struct8032E040 D_8032EAF4[3] = {
    {  1,   0, { -1411,   2474,  -1276}},
    {  2,   0, { -1606,   2479,   -434}},
    { -1,   0, { -1170,   2122,   1337}}
};

struct Struct8032E040 D_8032EB0C[3] = {
    {  1,  50, { -1053,   2512,   -928}},
    {  2,  50, { -1234,   2377,   -114}},
    { -1,  50, {  -758,   2147,   1054}}
};

struct Struct8032E040 D_8032EB24[6] = {
    {  0,   0, { -1445,   1094,   1617}},
    {  0,   0, { -1509,    649,    871}},
    {  0,   0, { -1133,    420,   -248}},
    {  0,   0, {  -778,    359,  -1052}},
    {  0,   0, {  -565,    260,  -1730}},
    { -1,   0, {  1274,    473,   -275}}
};

struct Struct8032E040 D_8032EB54[6] = {
    {  0,  50, { -1500,    757,   1251}},
    {  0,  50, { -1401,    439,    431}},
    {  0,  50, {  -749,    270,   -532}},
    {  0,  50, {  -396,    270,  -1363}},
    {  0,  50, {  -321,    143,  -2151}},
    { -1,  50, {  1002,    460,   -694}}
};

struct Struct8032E040 D_8032EB84[6] = {
    {  0,   0, { -4262,   4658,  -5015}},
    {  0,   0, { -3274,   2963,  -4661}},
    {  0,   0, { -2568,    812,  -6528}},
    {  0,   0, {  -414,    660,  -7232}},
    {  0,   0, {  1466,    660,  -6898}},
    { -1,   0, {  2724,    660,  -6298}}
};

struct Struct8032E040 D_8032EBB4[6] = {
    {  0,  50, { -4083,   4277,  -4745}},
    {  0,  50, { -2975,   2574,  -4759}},
    {  0,  50, { -2343,    736,  -6088}},
    {  0,  50, {  -535,    572,  -6755}},
    {  0,  50, {  1311,    597,  -6427}},
    { -1,  50, {  2448,    612,  -5884}}
};

struct Struct8032E040 D_8032EBE4[7] = {
    {  0,   0, {  -874,  -4933,    366}},
    {  0,   0, { -1463,  -4782,    963}},
    {  0,   0, { -1893,  -4684,   1303}},
    {  0,   0, { -2818,  -4503,   1583}},
    {  0,   0, { -4095,  -2924,    730}},
    {  0,   0, { -4737,  -1594,    -63}},
    { -1,   0, { -4681,  -1084,   -623}}
};

struct Struct8032E040 D_8032EC1C[7] = {
    {  0,  50, { -1276,  -4683,    622}},
    {  0,  50, { -1858,  -4407,   1097}},
    {  0,  50, { -2324,  -4332,   1318}},
    {  0,  50, { -3138,  -4048,   1434}},
    {  0,  50, { -4353,  -2444,    533}},
    {  0,  50, { -4807,  -1169,   -436}},
    { -1,  50, { -4665,   -664,  -1007}}
};

struct Struct8032E040 D_8032EC54[4] = {
    {  0,   0, {   939,   6654,   6196}},
    {  0,   0, {  1873,   5160,   3714}},
    {  0,   0, {  3120,   3564,   1314}},
    { -1,   0, {  2881,   4231,    573}}
};

struct Struct8032E040 D_8032EC74[4] = {
    {  0,  50, {   875,   6411,   5763}},
    {  0,  50, {  1659,   4951,   3313}},
    {  0,  50, {  2630,   3565,   1215}},
    { -1,  50, {  2417,   4056,    639}}
};

struct Struct8032E040 D_8032EC94[4] = {
    {  0,   0, {  3927,   2573,   3685}},
    {  0,   0, {  2389,   2054,   1210}},
    {  0,   0, {  2309,   2069,     22}},
    { -1,   0, {  2122,   2271,   -979}}
};

struct Struct8032E040 D_8032ECB4[4] = {
    {  0,  50, {  3637,   2460,   3294}},
    {  0,  50, {  1984,   2067,    918}},
    {  0,  50, {  1941,   2255,   -261}},
    { -1,  50, {  1779,   2587,  -1158}}
};

struct Struct8032E040 D_8032ECD4[6] = {
    {  0,   0, {   386,   2535,    644}},
    {  0,   0, {  1105,   2576,    918}},
    {  0,   0, {  3565,   2261,   2098}},
    {  0,   0, {  6715,  -2791,   4554}},
    {  0,   0, {  3917,  -3130,   3656}},
    { -1,   0, {  3917,  -3130,   3656}}
};

struct Struct8032E040 D_8032ED04[6] = {
    {  1,  50, {   751,   2434,    318}},
    {  2,  50, {   768,   2382,    603}},
    {  3,  60, {  3115,   2086,   1969}},
    {  4,  30, {  6370,  -3108,   4727}},
    {  5,  50, {  4172,  -3385,   4001}},
    { -1,  50, {  4172,  -3385,   4001}}
};

struct Struct8032E040 D_8032ED34[7] = {
    {  0,   0, {  6990,  -1000,  -4858}},
    {  0,   0, {  7886,  -1055,   2878}},
    {  0,   0, {  1952,  -1481,  10920}},
    {  0,   0, { -1684,   -219,   2819}},
    {  0,   0, { -2427,   -131,   2755}},
    {  0,   0, { -3246,    416,   3286}},
    { -1,   0, { -3246,    416,   3286}}
};

struct Struct8032E040 D_8032ED6C[7] = {
    {  1,  70, {  7022,   -965,  -5356}},
    {  2,  40, {  7799,   -915,   2405}},
    {  3,  60, {  1878,  -1137,  10568}},
    {  4,  50, { -1931,   -308,   2394}},
    {  5,  50, { -2066,   -386,   2521}},
    {  6,  50, { -2875,    182,   3045}},
    { -1,  50, { -2875,    182,   3045}}
};

struct Struct8032E040 D_8032EDA4[4] = {
    {  1,   0, { -1724,    277,   -994}},
    {  2,   0, { -1720,    456,   -995}},
    {  3,   0, { -1655,    810,  -1014}},
    { -1,   0, { -1753,    883,  -1009}}
};

struct Struct8032E040 D_8032EDC4[4] = {
    {  1,  50, { -1554,    742,  -1063}},
    {  2,  50, { -1245,    571,  -1102}},
    {  3,  50, { -1220,    603,  -1151}},
    { -1,  50, { -1412,    520,  -1053}}
};

struct Struct8032E040 D_8032EDE4[4] = {
    {  0,   0, { -1818,   4036,     97}},
    {  0,   0, {  -575,   3460,   -505}},
    {  0,   0, {  1191,   3611,  -1134}},
    { -1,   0, {  2701,   3777,  -3686}}
};

struct Struct8032E040 D_8032EE04[4] = {
    {  0,  50, { -1376,   3885,    -81}},
    {  0,  50, {  -146,   3343,   -734}},
    {  0,  50, {  1570,   3446,  -1415}},
    { -1,  50, {  2794,   3627,  -3218}}
};

struct Struct8032E040 D_8032EE24[5] = {
    {  0,   0, {  -295,   -396,   -585}},
    {  1,   0, {  -295,   -396,   -585}},
    {  2,   0, {  -292,   -856,   -573}},
    {  3,   0, {  -312,   -856,   -541}},
    { -1,   0, {   175,   -856,   -654}}
};

struct Struct8032E040 D_8032EE4C[5] = {
    {  0,  50, {  -175,   -594,   -142}},
    {  1,  50, {  -175,   -594,   -142}},
    {  2,  50, {  -195,   -956,    -92}},
    {  3,  50, {  -572,   -956,   -150}},
    { -1,  50, {  -307,   -956,   -537}}
};

struct Struct8032E040 D_8032EE74[5] = {
    {  0,   0, {  -296,    495,   1607}},
    {  0,   0, {  -430,    541,    654}},
    {  0,   0, {  -466,    601,   -359}},
    {  0,   0, {  -217,    433,  -1549}},
    { -1,   0, {   -95,    366,  -2922}}
};

struct Struct8032E040 D_8032EE9C[5] = {
    {  0,  50, {  -176,    483,   2092}},
    {  0,  50, {  -122,    392,   1019}},
    {  0,  50, {  -268,    450,   -792}},
    {  0,  50, {  -172,    399,  -2046}},
    { -1,  50, {   -51,    355,  -3420}}
};

struct Struct8032E040 D_8032EEC4[5] = {
    {  0,   0, {  4656,   2171,   5028}},
    {  0,   0, {  4548,   1182,   4596}},
    {  0,   0, {  5007,    813,   3257}},
    {  0,   0, {  5681,    648,   1060}},
    { -1,   0, {  4644,    774,    113}}
};

struct Struct8032E040 D_8032EEEC[5] = {
    {  0,  50, {  4512,   2183,   4549}},
    {  0,  50, {  4327,    838,   4308}},
    {  0,  50, {  4774,    749,   2819}},
    {  0,  50, {  5279,    660,    763}},
    { -1,  50, {  4194,    885,    -75}}
};

struct Struct8032E040 D_8032EF14[4] = {
    {  1,   0, {  1427,  -1387,   5409}},
    {  2,   0, { -1646,  -1536,   4526}},
    {  3,   0, { -3852,  -1448,   3913}},
    { -1,   0, { -5199,  -1366,   1886}}
};

struct Struct8032E040 D_8032EF34[4] = {
    {  1,  50, {   958,  -1481,   5262}},
    {  2,  50, { -2123,  -1600,   4391}},
    {  3,  50, { -3957,  -1401,   3426}},
    { -1,  50, { -4730,  -1215,   1795}}
};

void handle_cutscenes(struct LevelCamera *a)
{
    UNUSED u32 pad[3];
    UNUSED s16 sp22;
    s16 sp20;
    u8 sp1F;
    
    sp22 = D_8033B3EA;
    sp1F = a->unk30;
    D_8033B4DA &= ~1;
    D_8033B4D8 &= ~0x100;
    
    #define CUTSCENE_TABLE_JUMP(casenum, table) \
    case casenum: \
        sp20 = table[D_8033B6EA].unk4; \
        (table[D_8033B6EA].unk0)(a); \
        break;
    
    switch (a->unk30)
    {
    CUTSCENE_TABLE_JUMP(173, TableCutsceneStarSpawn)
    CUTSCENE_TABLE_JUMP(176, TableCutsceneSpecialStarSpawn)
    CUTSCENE_TABLE_JUMP(172, TableCutscenePeachEnd)
    CUTSCENE_TABLE_JUMP(174, TableCutsceneGrandStar)
    CUTSCENE_TABLE_JUMP(139, TableCutsceneDoorWarp)
    CUTSCENE_TABLE_JUMP(130, TableCutsceneDoor00)
    CUTSCENE_TABLE_JUMP(131, TableCutsceneDoor01)
    CUTSCENE_TABLE_JUMP(140, TableCutsceneDoor0A)
    CUTSCENE_TABLE_JUMP(141, TableCutsceneDoor0B)
    CUTSCENE_TABLE_JUMP(133, TableCutsceneEnterCannon)
    CUTSCENE_TABLE_JUMP(134, TableCutsceneEnterPainting)
    CUTSCENE_TABLE_JUMP(135, TableCutsceneExitPaintingDeath)
    CUTSCENE_TABLE_JUMP(160, TableCutsceneExitPaintingSuccess)
    CUTSCENE_TABLE_JUMP(147, TableCutscene11Todo)
    CUTSCENE_TABLE_JUMP(142, TableCutsceneIntroPeach)
    CUTSCENE_TABLE_JUMP(144, TableCutsceneEnterBowserPlatform)
    CUTSCENE_TABLE_JUMP(143, TableCutsceneStarDance1)
    CUTSCENE_TABLE_JUMP(175, TableCutsceneStarDance1)
    CUTSCENE_TABLE_JUMP(165, TableCutsceneStarDance2)
    CUTSCENE_TABLE_JUMP(166, TableCutsceneStarDance3)
    CUTSCENE_TABLE_JUMP(167, TableCutsceneKeyDance)
    CUTSCENE_TABLE_JUMP(145, TableCutscene0FTodo)
    CUTSCENE_TABLE_JUMP(177, TableCutsceneEndWaving)
    CUTSCENE_TABLE_JUMP(178, TableCutsceneCredits)
    CUTSCENE_TABLE_JUMP(161, TableCutsceneCapSwitchPress)
    CUTSCENE_TABLE_JUMP(149, TableCutsceneSlidingDoorsOpen)
    CUTSCENE_TABLE_JUMP(150, TableCutscenePrepareCannon)
    CUTSCENE_TABLE_JUMP(151, TableCutsceneUnlockKeyDoor)
    CUTSCENE_TABLE_JUMP(152, TableCutsceneDeath1)
    CUTSCENE_TABLE_JUMP(181, TableCutsceneEnterPool)
    CUTSCENE_TABLE_JUMP(153, TableCutsceneDeath2)
    CUTSCENE_TABLE_JUMP(154, TableCutsceneBBHDeath)
    CUTSCENE_TABLE_JUMP(155, TableCutsceneQuicksandDeath)
    CUTSCENE_TABLE_JUMP(156, TableCutscene1ATodo)
    CUTSCENE_TABLE_JUMP(157, TableCutsceneExitBowserSuccess)
    CUTSCENE_TABLE_JUMP(158, TableCutscene1CTodo)
    CUTSCENE_TABLE_JUMP(169, TableCutsceneBBHExitSuccess)
    CUTSCENE_TABLE_JUMP(179, TableCutsceneExitWaterfall)
    CUTSCENE_TABLE_JUMP(180, TableCutsceneFallToCastleGrounds)
    CUTSCENE_TABLE_JUMP(170, TableCutsceneNonPaintingDeath)
    CUTSCENE_TABLE_JUMP(162, TableCutsceneDialog)
    CUTSCENE_TABLE_JUMP(171, TableCutsceneReadMessage)
    CUTSCENE_TABLE_JUMP(163, TableCutsceneDialog)
    CUTSCENE_TABLE_JUMP(164, TableCutsceneEnterPyramidTop)
    CUTSCENE_TABLE_JUMP(168, TableCutscene26Todo)
    }
    
    #undef CUTSCENE_TABLE_JUMP
    
    if ((sp20 != 0) && ((gCutsceneTimer & 0x8000) == 0))
    {
        if (gCutsceneTimer < 0x3FFF)
            gCutsceneTimer += 1;
        if (gCutsceneTimer == sp20)
        {
            D_8033B6EA += 1;
            gCutsceneTimer = 0;
        }
    }
    else
    {
        D_8032D000->unk1C[1] = 0;
        D_8033B6EA = 0;
        gCutsceneTimer = 0;
    }
    
    D_8033B3EC = 0;
    
    if ((a->unk30 == 0) && (sp1F != 0))
        D_8032CFF4 = sp1F;
}

s32 call_cutscene_func_in_time_range(CameraCommandProc func, struct LevelCamera *a, s16 start, s16 end)
{
    if (start <= gCutsceneTimer)
    {
        if ((end == -1) || (end >= gCutsceneTimer))
            func(a);
    }
    return 0;
}

s32 func_80299C60(s32 a, s16 b)
{
    if (b == gCutsceneTimer)
        D_8033B85C = a;
    return 0;
}

void func_80299C98(s16 a, s16 b, s16 c)
{
    if (a > D_8033B230.unk10)
    {
        D_8033B230.unk10 = a;
        D_8033B230.unk18 = b;
        D_8033B230.unk16 = c;
    }
}

void func_80299D00(s16 a, s16 b, s16 c, f32 d, f32 e, f32 f, f32 g)
{
    a = func_80289738(a, d, e, f, g);
    
    if (a != 0)
    {
        if (a > D_8033B230.unk10) // literally use the function above you silly nintendo, smh
        {
            D_8033B230.unk10 = a;
            D_8033B230.unk18 = b;
            D_8033B230.unk16 = c;
        }
    }
}

void func_80299DB4(struct Struct80287404 *a)
{
    if (D_8033B230.unk10 != 0.f)
    {
        D_8033B230.unk8 = coss(D_8033B230.unk14) * D_8033B230.unk10 / 256.f;
        D_8033B230.unk14 += D_8033B230.unk16;
        func_802893E4(&D_8033B230.unk10, 0, D_8033B230.unk18);
        a->unk1C[0] += D_8033B230.unk8;
    }
    else
        D_8033B230.unk14 = 0;
}

void unused_80299EA0(UNUSED struct MarioState *m)
{
    D_8033B4DA &= ~0x40;
}

void func_80299ECC(UNUSED struct MarioState *m)
{
    D_8033B230.fieldOfView = 30.f;
}

void func_80299EF0(UNUSED struct MarioState *m)
{
    func_802893E4(&D_8033B230.fieldOfView, 20.f, 0.3f);
}

void func_80299F30(UNUSED struct MarioState *m)
{
    D_8033B230.fieldOfView = 45.f;
}

void func_80299F54(UNUSED struct MarioState *m)
{
    D_8033B230.fieldOfView = 29.f;
}

void func_80299F78(UNUSED struct MarioState *m)
{
    // Pretty sure approach_f32_exponential would do a much nicer job here, but you do you, Nintendo.
    func_802893E4(&D_8033B230.fieldOfView, 30.f, (30.f - D_8033B230.fieldOfView) / 60.f);
}

void func_80299FD8(struct MarioState *m)
{
    D_8033B4DA &= ~0x40;
    
    if ((m->action == ACT_SLEEPING) || (m->action == ACT_START_SLEEPING))
    {
        func_802893E4(&D_8033B230.fieldOfView, 30.f, (30.f - D_8033B230.fieldOfView) / 30.f);
        D_8033B4DA |= 0x40;
    }
    else
    {
        func_802893E4(&D_8033B230.fieldOfView, 45.f, (45.f - D_8033B230.fieldOfView) / 30.f);
        D_8033B230.unkC = 0;
    }
    if (m->area->camera->unk30 == 145)
        D_8033B230.fieldOfView = 45.f;
}

void unused_8029A100(UNUSED struct MarioState *m)
{
    func_802893E4(&D_8033B230.fieldOfView, 30.f, 1.f);
}

void func_8029A13C(UNUSED struct MarioState *m)
{
    func_802893E4(&D_8033B230.fieldOfView, 30.f, 1.f);
}

void func_8029A178(UNUSED struct MarioState *m)
{
    func_802893E4(&D_8033B230.fieldOfView, 60.f, 1.f);
}

void func_8029A1B4(struct MarioState *m)
{
    f32 targetFoV = D_8033B230.fieldOfView;
    
    if ((m->area->camera->preset == CAMERA_PRESET_FIXED_REF_POINT) && (m->area->camera->unk30 == 0))
        targetFoV = 45.f;
    else
        targetFoV = 45.f;
    
    D_8033B230.fieldOfView = approach_f32(D_8033B230.fieldOfView, targetFoV, 2.f, 2.f);
}

void func_8029A24C(UNUSED struct MarioState *m)
{
    func_802893E4(&D_8033B230.fieldOfView, 80.f, 3.5f);
}

void func_8029A288(struct MarioState *m)
{
    f32 targetFoV = D_8033B230.fieldOfView;
    
    if ((m->area->camera->preset == CAMERA_PRESET_FIXED_REF_POINT) && (m->area->camera->unk30 == 0)) // nice useless if statement
        targetFoV = 60.f;
    else
        targetFoV = 45.f;
    
    D_8033B230.fieldOfView = approach_f32(D_8033B230.fieldOfView, targetFoV, 2.f, 2.f);
}

s32 Geo0A_8029AA3C(s32 a, struct Struct80287404 *b, UNUSED struct AllocOnlyPool *c)
{
    struct Struct80287404 *sp24 = b;
    struct MarioState *sp20 = &gMarioStates[0];
    u8 sp1F = D_8033B230.unk0;
    
    if (a == 1)
    {
        switch (sp1F)
        {
        case 1:
            func_80299F30(sp20);
            break;
        case 13:
            func_80299F54(sp20);
            break;
        case 12:
            func_80299F78(sp20);
            break;
        case 2:
            func_80299FD8(sp20);
            break;
        case 7:
            func_8029A288(sp20);
            break;
        case 4:
            func_8029A1B4(sp20);
            break;
        case 5:
            func_80299ECC(sp20);
            break;
        case 6:
            func_80299EF0(sp20);
            break;
        case 9:
            func_8029A24C(sp20);
            break;
        case 10:
            func_8029A13C(sp20);
            break;
        case 11:
            func_8029A178(sp20);
            break;
        }
    }
    
    sp24->unk1C[0] = D_8033B230.fieldOfView;
    func_80299DB4(sp24);
    return 0;
}

void func_8029A478(u8 a)
{
    D_8033B230.unk0 = a;
}

void func_8029A494(u8 a)
{
    switch (a)
    {
    case 1:
        func_80299C98(0x100, 0x30, -0x8000);
        break;
    case 2:
        func_80299C98(0x400, 0x20, 0x4000);
        break;
    }
}

void func_8029A514(u8 a, f32 b, f32 c, f32 d)
{
    switch (a)
    {
    case 1:
        func_80299D00(0x100, 0x30, -0x8000, 3000.f, b, c, d);
        break;
    case 3:
        func_80299D00(0x200, 0x30, -0x8000, 4000.f, b, c, d);
        break;
    case 4:
        func_80299D00(0x300, 0x30, -0x8000, 6000.f, b, c, d);
        break;
    case 2:
        func_80299D00(0x800, 0x20, 0x4000, 3000.f, b, c, d);
        break;
    }
}

void unused_8029A664(struct Object *a, f32 b, f32 c, f32 d)
{
    f32 sp1C = RandomFloat();
    
    a->oPosX += (sp1C * b - b / 2.f);
    a->oPosY += (sp1C * c - c / 2.f);
    a->oPosZ += (sp1C * d - d / 2.f);
}

void unused_8029A724(struct Object *a, f32 b, f32 c)
{
    f32 sp1C = RandomFloat();
    
    a->oMoveAnglePitch += (s16)(sp1C * b - b / 2.f);
    a->oMoveAngleYaw   += (s16)(sp1C * c - c / 2.f);
}

void func_8029A7DC(struct Object *a, Vec3f b, s16 c, s16 d, s16 e, s16 f)
{
    f32 sp34;
    s16 sp32, sp30;
    Vec3f sp24;
    
    object_pos_to_vec3f(sp24, a);
    vec3f_get_dist_and_angle(sp24, b, &sp34, &sp32, &sp30);
    a->oMoveAnglePitch = approach_s16_exponential_2(a->oMoveAnglePitch, c - sp32, e);
    a->oMoveAngleYaw   = approach_s16_exponential_2(a->oMoveAngleYaw,   sp30 + d, f);
}

void func_8029A87C(struct Object *a, f32 b, f32 c)
{
    Vec3f sp2C;
    s16 sp2A, sp28;
    f32 sp24, sp20;
    
    vec3f_get_dist_and_angle(D_8033B328.unk8C, D_8033B328.unk80, &sp24, &sp2A, &sp28);
    vec3f_set_dist_and_angle(D_8033B328.unk8C, sp2C, a->oIntroPeachUnk110, a->oIntroPeachUnk10C + sp2A, a->oIntroPeachUnk108 + sp28);
    vec3f_to_object_pos(a, sp2C);
    sp20 = a->oOpacity;
    func_802893E4(&sp20, b, c);
    a->oOpacity = sp20;
}

void BehBeginningPeachLoop(void)
{
    switch (gCurrentObject->oAction)
    {
    case 0:
        gCurrentObject->oAction += 1;
        gCurrentObject->oFaceAnglePitch = 0x400;
        gCurrentObject->oFaceAngleYaw = 0x7500;
        gCurrentObject->oFaceAngleRoll = -0x3700;
        gCurrentObject->oIntroPeachUnk110 = 186.f;
        gCurrentObject->oIntroPeachUnk10C = -9984.f;
        gCurrentObject->oIntroPeachUnk108 = -768.f;
        gCurrentObject->oOpacity = 255;
        gCurrentObject->header.gfx.unk38.animFrame = 100;
        break;
    case 1:
        func_8029A87C(gCurrentObject, 0.f, 0.f);
        
        if (gCurrentObject->oTimer > 20)
            gCurrentObject->oAction += 1;
        break;
    case 2:
        func_8029A87C(gCurrentObject, 255.f, 3.f);
        
        if ((gCurrentObject->oTimer > 100) && (get_dialog_id() == -1))
            gCurrentObject->oAction += 1;
        break;
    case 3:
        func_8029A87C(gCurrentObject, 0.f, 8.f);
        
        if (gCurrentObject->oTimer > 60)
            mark_object_for_deletion(gCurrentObject);
        break;
    }
}

void func_8029AB70(struct Object *a, Vec3f b)
{
    f32 sp2C;
    Vec3s sp24;
    s16 sp22, sp20;
    
    vec3f_add(b, gCurrLevelCamera->unk10);
    vec3f_get_dist_and_angle(gCurrLevelCamera->unk10, gCurrLevelCamera->unk4, &sp2C, &sp24[0], &sp24[1]);
    vec3f_get_dist_and_angle(gCurrLevelCamera->unk10, b, &sp2C, &sp22, &sp20);
    vec3f_set_dist_and_angle(gCurrLevelCamera->unk10, b, sp2C, sp24[0] + sp22, sp24[1] + sp20);
    vec3f_to_object_pos(a, b);
}

void func_8029AC3C(struct Object *a, Vec3f b)
{
    UNUSED Vec3f sp3C;
    Vec3f sp30;
    f32 sp2C;
    s16 sp2A, sp28;
    UNUSED u32 sp24;
    
    vec3f_set(sp30, 0.f, 0.f, 0.f);
    vec3f_get_dist_and_angle(sp30, b, &sp2C, &sp2A, &sp28);
    a->oFaceAnglePitch = sp2A;
    a->oFaceAngleYaw = sp28;
}

s32 func_8029ACAC(struct Object *a, struct Struct8032E040 b[], struct Struct8032E040 c[])
{
    Vec3f sp2C, sp20;
    s32 sp1C = 0;
    s16 sp1A = a->oIntroLakituUnkFC;
    
    if ((func_80287CFC(sp20, b, &sp1A, &(a->oIntroLakituUnkF8)) == 1) || (func_80287CFC(sp2C, c, &sp1A, &(a->oIntroLakituUnkF8)) == 1))
        sp1C += 1;
    
    a->oIntroLakituUnkFC = sp1A;
    func_8029AB70(a, sp2C);
    func_8029AC3C(a, sp20);
    return sp1C;
}

void BehBeginningLakituLoop(void)
{
    Vec3f sp64, sp58, sp4C;
    UNUSED u32 pad[4];
    
    switch (gCurrentObject->oAction)
    {
    case 0:
        obj_disable_rendering();
        gCurrentObject->oIntroLakituUnkFC = 0.f;
        gCurrentObject->oIntroLakituUnkF8 = 0.f;
        gCurrentObject->oUnk1AC_VPTR = spawn_object_relative_with_scale(1, 0, 0, 0, 2.f, gCurrentObject, MODEL_MIST, bCloud);
        if (gCurrLevelCamera->unk30 == 177)
            gCurrentObject->oAction = 100;
        else
            gCurrentObject->oAction += 1;
        break;
        
    case 1:
        obj_enable_rendering();
        if ((gCutsceneTimer > 350) && (gCutsceneTimer < 458))
        {
            gCurrentObject->oPosX = gCurrLevelCamera->unk10[0];
            gCurrentObject->oPosY = gCurrLevelCamera->unk10[1] + 500.f;
            gCurrentObject->oPosZ = gCurrLevelCamera->unk10[2];
        }
        if (gCutsceneTimer > 52)
            PlaySound(0x6002FF01);
        if (func_8029ACAC(gCurrentObject, D_8032E3CC, D_8032E2B4) == 1)
            gCurrentObject->oAction += 1;
        
        switch (gCurrentObject->oTimer)
        {
#if VERSION_US
        case 534:
            PlaySound2(0x04568081);
            break;
        case 581:
            PlaySound2(0x045E8081);
            break;
#endif
        case 73:
            gCurrentObject->oAnimState += 1;
            break;
        case 74:
            gCurrentObject->oAnimState -= 1;
            break;
        case 82:
            gCurrentObject->oAnimState += 1;
            break;
        case 84:
            gCurrentObject->oAnimState -= 1;
            break;
        }
        break;
        
    case 2:
        if (gCutsceneTimer > 720)
        {
            gCurrentObject->oAction += 1;
            gCurrentObject->oIntroLakituUnk100 = 1400.f;
            gCurrentObject->oIntroLakituUnk104 = -4096.f;
            gCurrentObject->oIntroLakituUnk108 = 2048.f;
            gCurrentObject->oIntroLakituUnk10C = -200.f;
            gCurrentObject->oMoveAngleYaw = 0x8000;
            gCurrentObject->oFaceAngleYaw = gCurrentObject->oMoveAngleYaw + 0x4000;
            gCurrentObject->oMoveAnglePitch = 0x800;
        }
        PlaySound(0x6002FF01);
        break;
        
    case 3:
        PlaySound(0x6002FF01);
        vec3f_set(sp58, -1128.f, 560.f, 4664.f);
        gCurrentObject->oMoveAngleYaw += 0x200;
        gCurrentObject->oIntroLakituUnk100 = approach_f32_exponential_2(gCurrentObject->oIntroLakituUnk100, 100.f, 0.03f);
        gCurrentObject->oFaceAnglePitch = atan2s(200.f, gCurrentObject->oPosY - 400.f);
        gCurrentObject->oFaceAngleYaw = approach_s16_exponential_2(gCurrentObject->oFaceAngleYaw, gCurrentObject->oMoveAngleYaw + 0x8000, 4);
        vec3f_set_dist_and_angle(sp58, sp4C, gCurrentObject->oIntroLakituUnk100, 0, gCurrentObject->oMoveAngleYaw);
        sp4C[1] += 150.f * coss((s16)gCurrentObject->oIntroLakituUnk104);
        gCurrentObject->oIntroLakituUnk104 += gCurrentObject->oIntroLakituUnk108;
        gCurrentObject->oIntroLakituUnk108 = approach_f32_exponential_2(gCurrentObject->oIntroLakituUnk108, 512.f, 0.05f);
        sp4C[0] += gCurrentObject->oIntroLakituUnk10C;
        gCurrentObject->oIntroLakituUnk10C = approach_f32_exponential_2(gCurrentObject->oIntroLakituUnk10C, 0.f, 0.05f);
        vec3f_to_object_pos(gCurrentObject, sp4C);
        
        if (gCurrentObject->oTimer == 31)
        {
            gCurrentObject->oPosY -= 158.f;
            func_802ADA94();
            gCurrentObject->oPosY += 158.f;
        }
        if (gCurrentObject->oTimer == 98)
        {
            mark_object_for_deletion(gCurrentObject);
            mark_object_for_deletion(gCurrentObject->oUnk1AC_VPTR);
        }
#if VERSION_US
        if (gCurrentObject->oTimer == 14)
            PlaySound2(0x045F8081);
#endif
        break;
    
    case 100:
        obj_enable_rendering();
        vec3f_set(sp64, -100.f, 100.f, 300.f);
        func_8028C5F0(sp4C, gCurrLevelCamera->unk10, sp64, D_8032D000->unk10);
        vec3f_to_object_pos(gCurrentObject, sp4C);
        gCurrentObject->oMoveAnglePitch = 0x1000;
        gCurrentObject->oMoveAngleYaw = 0x9000;
        gCurrentObject->oFaceAnglePitch = gCurrentObject->oMoveAnglePitch / 2;
        gCurrentObject->oFaceAngleYaw = gCurrentObject->oMoveAngleYaw;
        gCurrentObject->oAction += 1;
        break;
        
    case 101:
        object_pos_to_vec3f(sp4C, gCurrentObject);
        if (gCurrentObject->oTimer > 60)
        {
            gCurrentObject->oForwardVel = approach_f32_exponential_2(gCurrentObject->oForwardVel, -10.f, 0.05f);
            gCurrentObject->oMoveAngleYaw += 0x78;
            gCurrentObject->oMoveAnglePitch += 0x40;
            gCurrentObject->oFaceAngleYaw = func_80289264(gCurrentObject->oFaceAngleYaw, (s16)func_8028A4F0(sp4C, gCurrLevelCamera->unk10), 0x200);
        }
        if (gCurrentObject->oTimer > 105)
        {
            gCurrentObject->oAction += 1;
            gCurrentObject->oMoveAnglePitch = 0xE00;
        }
        gCurrentObject->oFaceAnglePitch = 0;
        func_802A2A38();
        break;
        
    case 102:
        object_pos_to_vec3f(sp4C, gCurrentObject);
        gCurrentObject->oForwardVel = approach_f32_exponential_2(gCurrentObject->oForwardVel, 60.f, 0.05f);
        gCurrentObject->oFaceAngleYaw = func_80289264(gCurrentObject->oFaceAngleYaw, (s16)func_8028A4F0(sp4C, gCurrLevelCamera->unk10), 0x200);
        if (gCurrentObject->oTimer < 62)
            gCurrentObject->oMoveAngleYaw = approach_s16_exponential_2(gCurrentObject->oMoveAngleYaw, 0x1800, 0x1E);
        gCurrentObject->oMoveAnglePitch = func_80289264(gCurrentObject->oMoveAnglePitch, -0x2000, 0x5A);
        gCurrentObject->oFaceAnglePitch = 0;
        func_802A2A38();
        break;
    }
}

void BehEndBirds1Loop(void)
{
    Vec3f sp34;
    UNUSED f32 sp30 = RandomFloat();
    
    switch (gCurrentObject->oAction)
    {
    case 0:
        obj_scale(0.7f);
        gCurrentObject->oIntroLakituUnk110 = -554.f;
        gCurrentObject->oIntroLakituUnk10C = 3044.f;
        gCurrentObject->oIntroLakituUnk108 = -1314.f;
        gCurrentObject->oAction += 1;
        break;
    case 1:
        vec3f_set(sp34, gCurrentObject->oIntroLakituUnk110, gCurrentObject->oIntroLakituUnk10C, gCurrentObject->oIntroLakituUnk108);
        
        if (gCurrentObject->oTimer < 100)
            func_8029A7DC(gCurrentObject, sp34, 0, 0, 0x20, 0x20);
        if ((gCurrentObject->oEndBirdUnk104 == 0.f) && (gCurrentObject->oTimer == 0))
            PlaySound2(0x30690081);
        if (gCutsceneTimer == 0)
            mark_object_for_deletion(gCurrentObject);
        break;
    }
    
    func_802A2A38();
}

void BehEndBirds2Loop(void)
{
    Vec3f sp3C;
    UNUSED f32 sp38;
    f32 sp34;
    s16 sp32, sp30;
    
    sp38 = RandomFloat();
    gCurrentObject->oForwardVel = (RandomFloat() * 10.f) + 25.f;
    
    switch(gCurrentObject->oAction)
    {
    case 0:
        obj_scale(0.7f);
        gCurrentObject->oAction += 1;
        break;
    case 1:
        vec3f_get_dist_and_angle(gCurrLevelCamera->unk10, gCurrLevelCamera->unk4, &sp34, &sp32, &sp30);
        sp30 += 0x1000;
        sp32 += 0; // nice work, Nintendo
        vec3f_set_dist_and_angle(gCurrLevelCamera->unk10, sp3C, 14000.f, sp32, sp30);
        func_8029A7DC(gCurrentObject, sp3C, 0, 0, 8, 8);
        
        if ((gCurrentObject->oEndBirdUnk104 == 0.f) && (gCurrentObject->oTimer == 0))
            PlaySound2(0x30690081);
        break;
    }
    
    func_802A2A38();
}

void func_8029B964(struct Object *parent, 
        s16 xOffset, s16 yOffset, s16 zOffset,
        s16 pitchOffset, s16 yawOffset, s16 rollOffset,
        s16 forwardVel, s32 model, void *behavior)
{
    struct Object* sp1C = spawn_object(parent, model, behavior);
    
    sp1C->header.gfx.unk38.animFrame = RandomFloat() * 6.f;
    sp1C->oEndBirdUnk104 = D_8033B6F0[9].unk4[0];
    D_8033B6F0[9].unk4[0] += 1.f;
    sp1C->oPosX += xOffset;
    sp1C->oPosY += yOffset;
    if (gCutsceneTimer > 700)
        sp1C->oPosY += -150.f;
    sp1C->oPosZ += zOffset;
    sp1C->oMoveAnglePitch += pitchOffset;
    sp1C->oMoveAngleYaw += yawOffset;
    sp1C->oMoveAngleRoll += rollOffset;
    sp1C->oForwardVel = forwardVel;
}

void BehIntroSceneLoop(void)
{
    UNUSED struct Object *sp34;
    
    if (D_8033B85C != 0)
    {
        gCurrentObject->oPosX = gCurrLevelCamera->unk10[0];
        gCurrentObject->oPosY = gCurrLevelCamera->unk10[1];
        gCurrentObject->oPosZ = gCurrLevelCamera->unk10[2];
        gCurrentObject->oMoveAnglePitch = 0;
        gCurrentObject->oMoveAngleYaw = 0;
        
        switch (D_8033B85C)
        {
        case 6:
            sp34 = spawn_object(gCurrentObject, MODEL_LAKITU, beh_beginning_lakitu);
            break;
        case 5:
            sp34 = spawn_object(gCurrentObject, MODEL_PEACH, beh_beginning_peach);
            break;
        case 7:
            func_8029B964(gCurrentObject,    0,  205,   500, 0x1000,  0x6000, -0x1E00, 25, MODEL_BIRDS, beh_end_birds_1);
            func_8029B964(gCurrentObject,    0,  205,   800, 0x1800,  0x6000, -0x1400, 35, MODEL_BIRDS, beh_end_birds_1);
            func_8029B964(gCurrentObject, -100,  300,   500,  0x800,  0x6000,       0, 25, MODEL_BIRDS, beh_end_birds_1);
            func_8029B964(gCurrentObject,  100, -200,   800,      0,  0x4000,  0x1400, 45, MODEL_BIRDS, beh_end_birds_1);
            func_8029B964(gCurrentObject,  -80,  300,   350, 0x1800,  0x5000,   0xA00, 35, MODEL_BIRDS, beh_end_birds_1);
            func_8029B964(gCurrentObject, -300,  300,   500,  0x800,  0x6000,  0x2800, 25, MODEL_BIRDS, beh_end_birds_1);
            func_8029B964(gCurrentObject, -400, -200,   800,      0,  0x4000, -0x1400, 45, MODEL_BIRDS, beh_end_birds_1);
            break;
        case 9:
            func_8029B964(gCurrentObject,   50,  205,   500, 0x1000,  0x6000,       0, 35, MODEL_BIRDS, beh_end_birds_1);
            func_8029B964(gCurrentObject,    0,  285,   800, 0x1800,  0x6000,       0, 35, MODEL_BIRDS, beh_end_birds_1);
            break;
        case 8:
            func_8029B964(gCurrentObject, -100, -100,  -700,      0,       0,  -0xF00, 25, MODEL_BIRDS, beh_end_birds_2);
            func_8029B964(gCurrentObject, -250,  255,  -200,      0,       0, -0x1400, 25, MODEL_BIRDS, beh_end_birds_2);
            func_8029B964(gCurrentObject, -100,  155,  -600,      0,       0,  -0x500, 35, MODEL_BIRDS, beh_end_birds_2);
            func_8029B964(gCurrentObject,  250,  200, -1200,      0,       0,  -0x700, 25, MODEL_BIRDS, beh_end_birds_2);
            func_8029B964(gCurrentObject, -250,  255,  -700,      0,       0,       0, 25, MODEL_BIRDS, beh_end_birds_2);
            break;
        }
        
        D_8033B85C = 0;
    }
}
