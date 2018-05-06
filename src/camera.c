#include <ultra64.h>

#include "sm64.h"
#include "game.h"
#include "math_util.h"

extern float D_8033B438;
extern float D_8033B3CC;
extern float D_8033B3D4;
extern float D_8033B28C;
extern float D_8033B27C;

void func_8027EFE0(s16 a)
{
    switch (a - 1)
    {
    case 0:
        D_8033B3CC = 0;
        D_8033B3D4 = 0;
        break;
    case 8:
        func_8028A908(96, 3, -32768);
        func_8028AA24(96, 3, -32768);
        break;
    case 1:
        func_8028A908(96, 12, -32768);
        break;
    case 2:
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
    case 3:
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
    case 4:
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
    case 7:
        D_8033B3CC = 0.07;
        D_8033B3D4 = 0.07;
        break;
    case 9:
        func_8028A908(RandomFloat() * 64.0f, 8, -32768);
        func_8028A964(RandomFloat() * 64.0f, 8, -32768);
        break;
    }
}

void func_8027F308(s16 a)
{
    switch (a - 1)
    {
    case 0:
        func_8028A908(96, 8, 16384);
        break;
    case 1:
        func_8028A908(192, 8, 16384);
        break;
    case 2:
        func_8028A908(256, 8, 12288);
        break;
    case 5:
        func_8028AA24(128, 16, 12288);
        break;
    case 6:
        func_8028A908(32, 8, -32768);
        break;
    case 7:
        func_8028A908(64, 8, -32768);
        break;
    case 8:
        func_8028A908(32, 8, -32768);
        func_8028AA24(1024, 16, 256);
        break;
    case 9:
        func_8028A908(64, 2, -32768);
        break;
    case 4:
        func_8028A964(-512, 128, 512);
        break;
    }
}

void func_8027F440(s16 a, float b, float c, float d)
{
    switch (a)
    {
    case 4:
        func_8028AA80(40, 8, 16384, 0x44FA0000, b, c, d);
        break;
    case 1:
        func_8028AA80(128, 8, 16384, 0x457A0000, b, c, d);
        func_8029A514(1, b, c, d);
        break;
    case 2:
        func_8028AA80(192, 8, 16384, 0x45BB8000, b, c, d);
        func_8029A514(3, b, c, d);
        break;
    case 3:
        func_8028AA80(256, 8, 12288, 0x45FA0000, b, c, d);
        func_8029A514(4, b, c, d);
        break;
    }
}

void Unknown8027F5C4(s16 a)
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

void func_8027F668(float *a, float b, float c, float *d, float e, float f)
{
    float sp24 = D_8033B27C;
    float sp20;
    UNUSED int filler;

    if (!(D_8032D000->unk0 & 0x4000))
    {
        if (sp24 < (sp20 = func_80381BA0(D_8032D000->unk4[0], D_8032D000->unk4[2])))
            sp24 = sp20;
    }

    if (D_8032D000->unk0 & 0x100000)
    {
        if (D_8033B27C >= gMarioStates[0].usedObj->pos[1]
         && D_8032D000->unk4[1] < 0.7f * gMarioStates[0].usedObj->hitboxHeight + gMarioStates[0].usedObj->pos[1])
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

void func_8027F870(Vec3f a, Vec3f b, float c, float d, float e, s16 f, s16 g)
{
    Vec3f sp24;

    sp24[0] = D_8032D000->unk4[0];
    sp24[1] = D_8032D000->unk4[1] + c;
    sp24[2] = D_8032D000->unk4[2];

    func_8037A788(sp24, b, e, f + D_8033B3F0, g);

    a[0] = D_8032D000->unk4[0];
    a[1] = D_8032D000->unk4[1] + d;
    a[2] = D_8032D000->unk4[2];
}

void Unknown8027F950(Vec3f a, Vec3f b, float c, float d, float e, s16 f, s16 g)
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

    func_8037A788(sp34, b, e, f + D_8033B3F0, g);
    func_8037A69C(b, D_8032D000->unk4, &sp30, &sp2A, &sp28);
    func_8037A69C(b, a, &sp2C, &sp26, &sp24);
    func_8037A788(b, a, sp2C, sp26, sp24);

    a[1] = D_8032D000->unk4[1] + d;
}

#define ABS(x) ((x) > 0.0f ? (x) : -(x))

void func_8027FA48(struct Struct80280550 *a, float b)
{
    struct Surface *sp44;
    float sp40;
    float sp3C;
    float sp38;
    UNUSED u8 filler[8];
    UNUSED s16 sp2E = D_8032D000->unk0;
    float sp28 = 125.0f;
    float sp24 = func_80381264(a->unk10[0], D_8033B328[10] - 50.0f, a->unk10[2], &sp44);

    if (D_8032D000->unk0 & 0x200000)
    {
        sp3C = D_8033B28C;
        sp40 = D_8033B27C;
        if (sp40 < sp3C - 400.0f)
            sp40 = sp3C - 400.0f;
        b = sp40 + (sp3C - sp40) * 0.4f;
        if (D_8032D000->unk4[1] - 400.0f > b)
            b = D_8032D000->unk4[1] - 400.0f;
        func_8028C2F0(a, b, 5.0f);
    }
    else
    {
        sp38 = func_80381900(a->unk10[0], a->unk10[1] + 100.0f, a->unk10[2], &sp44) + sp28;
        sp40 = sp28 + D_8033B27C;
        if (sp38 < sp40)
            sp38 = sp40;
        if (b < sp38)
        {
            b = sp38;
            a->unk10[1] = b;
        }
        if (D_8032D000->unk0 == 0x2033B || D_8032D000->unk0 == 0x2033A || D_8032D000->unk0 == 0x2033C)
        {
            if (ABS(a->unk10[1] - b) > 1000.0f)
                a->unk10[1] = b;
        }
        func_8028C2F0(a, b, 20.0f);
        if (sp24 != 20000.0f)
        {
            sp24 -= sp28;
            if ((a->unk10[1] > sp24 && D_8033B27C + sp28 < sp24)
              || (D_8033B28C != 20000.0f && D_8033B28C > sp24 && a->unk10[1] > sp24))
                a->unk10[1] = sp24;
        }
    }
}

int func_8027FDB8(u16 a)
{
    struct Surface *sp44;
    float sp40;
    s16 sp3E = 1456;
    float sp38 = D_8032D000->unk4[0] + D_80386000[(u16)(a) >> 4] * 40.0f;
    float sp34 = D_8032D000->unk4[2] + D_80387000[(u16)(a) >> 4] * 40.0f;

    sp40 = func_80381900(sp38, D_8032D000->unk4[1], sp34, &sp44) - D_8032D000->unk4[1];

    if (sp44 != NULL)
    {
        if (sp44->type != 40 && sp40 > 0.0f)
        {
            if (sp44->normal[2] == 0.0f && sp40 < 100.0f)
                sp3E = 1456;
            else
                sp3E += func_8037A9A8(40.0f, sp40);
        }
    }
    return sp3E;
}

void func_8027FF44(struct Struct80280550 *a)
{
    float sp34;
    s16 sp32;
    s16 sp30;
    Vec3f sp24 = {0, 0, 0};

    func_8037A69C(a->unk10, D_8032D000->unk4, &sp34, &sp32, &sp30);

    sp24[2] = D_80386000[0xC0] * sp34;

    func_8028A764(sp24, sp24, D_8032D000->unk10[1]);
    sp30 = -sp30;
    func_8028A764(sp24, sp24, sp30);
    sp24[2] = 0.0f;

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

int func_802800F4(Vec3f a, Vec3f b, s16 c)
{
    switch (D_8032CFD8)
    {
    case 177:
        c = func_802899A0(a, b, 4508.0f, -3739.0f, 4508.0f, -3739.0f);
        break;
    case 145:
        c = func_802899A0(a, b, 8000.0f, -8000.0f, 7050.0f, -8000.0f);
        break;
    case 209:
        c = func_802899A0(a, b, 8192.0f, -8192.0f, 8192.0f, -8192.0f);
        break;
    case 210:
        c = func_802899A0(a, b, 2458.0f, -2458.0f, 2458.0f, -2458.0f);
        break;
    }
    return c;
}

int CameraChange01(struct Struct80280550 *a, Vec3f b, Vec3f c)
{
    float sp4C = D_8032D000->unk4[0] - a->unk28;
    float sp48 = D_8032D000->unk4[2] - a->unk2C;
    s16 sp46 = func_8037A9A8(sp48, sp4C) + D_8033B402;
    s16 sp44 = func_8027FDB8(sp46);
    UNUSED int unused1;
    float sp3C;
    float sp38;
    UNUSED int unused2;
    UNUSED int unused3;
    float sp2C = 125.0f;
    float sp28 = 1000.0f;

    D_8033B3EA = sp46 - D_8033B402;
    func_8027F668(&sp3C, 1.0f, 200.0f, &sp38, 0.9f, 200.0f);
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
    float sp2C = 125.0f;
    float sp28 = 1000.0f;

    D_8033B3EA = sp46;
    func_8027F668(&sp40, 1.0f, 200.0f, &sp3C, 0.9f, 200.0f);
    func_8027F870(b, c, sp40 + sp2C, sp3C + sp2C, D_8033B3EE + sp28, sp44, sp46);
    func_8027FF44(a);
    if (D_8032CFD8 == 370)
        sp46 = func_802899A0(c, b, 6839.0f, 995.0f, 5994.0f, -3945.0f);

    return sp46;
}

void func_80280550(struct Struct80280550 *a)
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
    s16 sp26 = func_8028A4F0(D_8032D000->unk4, a->unk10) - func_8037A9A8(sp2C, sp30);

    if (sp26 > sp46)
        sp26 = sp46;
    if (sp26 < sp44)
        sp26 = sp44;

    if (!(D_8033B4D8 & 0xD))
    {
        if (D_8033B280 == 110 && D_8033B298 != 110)
            D_8033B4D8 |= 0x11;
        if (D_8033B280 == 111 && D_8033B298 != 111)
            D_8033B4D8 |= 0x14;
        if (D_8033B280 == 112 && D_8033B298 != 112)
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
        if (sp40 - func_8037A9A8(sp2C, sp30) + 0x4000 < 0)
            sp40 += 32768;
        sp40 -= func_8037A9A8(sp2C, sp30);
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
                sp42 = gMarioStates[0].forwardVel / 32.0f * 128.0f;
                func_80289184(&D_8033B402, sp26, sp42);
            }
            if (a->unk0 == 2)
                D_8033B402 = func_8028AF24(a, func_8037A9A8(sp2C, sp30));
        }
    }

    if (D_8033B402 >= 0x5555)
        D_8033B402 = 21844;
    if (D_8033B402 < -0x5554)
        D_8033B402 = -21844;
}

void func_80280BD8(float a, s16 b)
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

    if (D_8032CFD8 == 130 && *D_8033B860 == 2)
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

void func_80280E0C(struct Struct80280550 *a)
{
    func_8028B3DC(a, 0.0f);
}

void func_80280E3C(UNUSED struct Struct80280550 *a)
{
    float sp4 = 1000.0f;

    D_8033B402 = D_8033B43E - D_8033B3EA;
    D_8033B3EE = D_8033B438 - sp4;
    D_8033B4D8 &= ~0x100;
}

void func_80280EBC(struct Struct80280550 *a)
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
        func_80280BD8(400.0f, 2304);
    a->unk3A = CameraChange01(a, a->unk4, sp2C);
    a->unk10[0] = sp2C[0];
    a->unk10[2] = sp2C[2];
    D_8033B3EC = D_8033B3EA - sp22;
    if (D_8032D000->unk0 == 1192)
        sp2C[1] += 500.0f;
    func_8027FA48(a, sp2C[1]);
    func_8027FF44(a);
}

void func_80280FD8(struct Struct80280550 *a)
{
    Vec3f sp24;
    UNUSED u8 unused[8];
    s16 sp1A = D_8033B3EA;

    func_8028B3DC(a, 0.0f);

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

    func_80280BD8(400.0f, 2304);
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
    s16 sp3E = func_8037A9A8(sp40, sp44) + D_8033B402 + 32768;
    s16 sp3C = func_8027FDB8(sp3E);
    float sp38 = 1000.0f;
    float sp34 = 125.0f;
    float sp30;
    float sp2C;

    D_8033B3EA = sp3E - D_8033B402 - 32768;
    func_8027F668(&sp30, 1.0f, 200.0f, &sp2C, 0.9f, 200.0f);
    func_8027F870(b, c, sp30 + sp34, sp2C + sp34, D_8033B3EE + sp38, sp3C, sp3E);

    return sp3E;
}

void func_8028124C(struct Struct80280550 *a)
{
    Vec3f sp1C;
    s16 sp1A = D_8033B3EA;

    if (D_8033B4D8 & 0x100)
        func_80280E3C(a);
    func_80280E0C(a);
    func_80280550(a);
    func_80280BD8(400.0f, 2304);
    a->unk3A = CameraChange02(a, a->unk4, sp1C);
    a->unk10[0] = sp1C[0];
    a->unk10[2] = sp1C[2];
    D_8033B3EC = D_8033B3EA - sp1A;
    if (D_8032D000->unk0 == 1192)
        sp1C[1] += 500.0f;
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

    sp60[0] = 0.0f;
    sp60[1] = 0.0f;
    sp60[2] = 0.0f;
    vec3f_copy(sp4C, c);
    vec3f_copy(spE8[0], D_8033B470[D_8033B46C].unk4);
    vec3f_copy(spE8[1], D_8033B470[D_8033B46C + 1].unk4);
    spAC = D_8033B470[D_8033B46C].unk10;
    spA8 = D_8033B470[D_8033B46C].unk14;
    func_8027F668(&sp84, 1.0f, 200.0f, &sp84, 0.9f, 200.0f);
    sp78[0] = D_8032D000->unk4[0];
    sp78[1] = D_8032D000->unk4[1] + 150.0f + sp84;
    sp78[2] = D_8032D000->unk4[2];
    spDC[0] = spE8[0][0] + (spE8[1][0] - spE8[0][0]) * sp88;
    spDC[1] = spE8[0][1] + (spE8[1][1] - spE8[0][1]) * sp88;
    spDC[2] = spE8[0][2] + (spE8[1][2] - spE8[0][2]) * sp88;
    func_8037A69C(spE8[0], spE8[1], &sp98, &spB6, &spB4);
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
    spB8[0] = -spB8[0] * 0.0f;
    spB8[1] = spB8[1] * 0.0f;
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
    spD0[2] = sp98 / 2.0f - spD0[2];
    sp58[1] = spB4 + 32768;
    sp58[2] = 0;
    func_8028C5F0(c, spE8[0], spD0, sp58);
    func_8037A69C(spE8[0], a->unk10, &spA4, &spB6, &spB4);
    spB8[2] = sp98 / 2.0f - spB8[2];
    func_8028C5F0(a->unk4, spE8[0], spB8, sp58);

    if (D_8033B4DA & 8)
    {
        D_8033B4DA &= ~8;
        D_8033B478[0] = sp4C[0] - a->unk10[0];
        D_8033B478[1] = sp4C[1] - a->unk10[1];
        D_8033B478[2] = sp4C[2] - a->unk10[2];
    }
    func_80288E0C(&D_8033B478[0], 0.0f, 0.025f);
    func_80288E0C(&D_8033B478[1], 0.0f, 0.025f);
    func_80288E0C(&D_8033B478[2], 0.0f, 0.025f);
    vec3f_add(a->unk10, D_8033B478);

    if (D_8033B470[D_8033B46C + 1].unk0 != 0)
    {
        func_8028A578(D_8033B470[D_8033B46C + 1].unk4, D_8033B470[D_8033B46C + 2].unk4, &sp28, &sp24);
        func_8037A788(D_8033B470[D_8033B46C + 1].unk4, sp34, 400.0f, sp28, sp24);
        sp2C = func_8028A640(sp78, sp34);
        func_8028A578(D_8033B470[D_8033B46C + 1].unk4, D_8033B470[D_8033B46C].unk4, &sp2A, &sp26);
        func_8037A788(D_8033B470[D_8033B46C + 1].unk4, sp40, 400.0f, sp2A, sp26);
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
        func_8037A788(D_8033B470[D_8033B46C].unk4, sp34, 700.0f, sp28, sp24);
        sp2C = func_8028A640(sp78, sp34);
        func_8028A578(D_8033B470[D_8033B46C].unk4, D_8033B470[D_8033B46C - 1].unk4, &sp2A, &sp26);
        func_8037A788(D_8033B470[D_8033B46C].unk4, sp40, 700.0f, sp2A, sp26);
        sp30 = func_8028A640(sp78, sp40);
        if (sp2C > sp30)
        {
            D_8033B46C--;
            D_8033B4DA |= 8;
        }
    }

    vec3f_copy(b, sp78);
    func_8037A69C(b, c, &spA4, &spB6, &spB4);

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
        sp58 = 0.0f;
        sp68 = 0.0f;
        break;
    case 97:
        sp58 = 0.3f;
        sp68 = 0.0f;
        break;
    case 65:
        sp58 = 0.0f;
        sp68 = 0.0f;
        break;
    }
    func_8028B7A4(a);
    func_8028B19C();
    func_8027F668(&sp74, 1.0f, 200.0f, &sp74, 0.9f, 200.0f);
    vec3f_copy(b, D_8032D000->unk4);
    b[1] += sp74 + 125.0f;
    func_8037A69C(b, a->unk10, &sp64, &sp4C[0], &sp4C[1]);
    sp4C[2] = 0;
    vec3f_copy(sp3C, D_8032D00C);
    vec3f_add(sp3C, D_8033B460);

    if (D_8033B280 != 10 && D_8033B27C != -11000.0f)
        sp70 = D_8033B27C + sp3C[1] + sp68;
    else
        sp70 = D_8033B328[10];
    if (300.0f > sp64)
        sp70 += 300.f - sp64;

    sp6C = func_80381264(a->unk10[0], sp70 - 100.0f, a->unk10[2], &sp48);
    if (sp6C != 20000.0f)
    {
        if (sp70 > (sp6C -= 125.0f))
            sp70 = sp6C;
    }

    if (D_8033B4DA & 1)
    {
        func_802893E4(&a->unk10[1], sp70, 15.0f);
    }
    else
    {
        if (sp70 < D_8032D000->unk4[1] - 500.0f)
            sp70 = D_8032D000->unk4[1] - 500.0f;
        a->unk10[1] = sp70;
    }

    a->unk10[0] = sp3C[0] + (D_8032D000->unk4[0] - sp3C[0]) * sp58;
    a->unk10[2] = sp3C[2] + (D_8032D000->unk4[2] - sp3C[2]) * sp58;

    if (sp58 != 0.0f)
    {
        func_8037A69C(a->unk4, a->unk10, &sp64, &sp56, &sp54);
        if (sp64 > 1000.0f)
        {
            sp64 = 1000.0f;
            func_8037A788(a->unk4, a->unk10, sp64, sp56, sp54);
        }
    }

    return sp4C[1];
}

int CameraChange0B(struct Struct80280550 *a, Vec3f b, Vec3f c)
{
    struct Struct8032CFD0 *sp8C;
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
    Vec3f sp2C = {0.0f, -150.0f, -125.0f};

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
        func_80287840(sp38, sp8C);
        sp5E = sp8C->unk124;
    }
    else
    {
        sp38[0] = a->unk28;
        sp38[1] = D_8032D000->unk4[1];
        sp38[2] = a->unk2C;
        sp5E = 0;
    }

    sp7C = func_8028A640(D_8032D000->unk4, sp38) * 1.6f;
    if (sp7C < 800.0f)
        sp7C = 800.0f;
    if (sp7C > 5000.0f)
        sp7C = 5000.0f;

    if (sp5E == 1)
        func_8028C5F0(sp38, D_8032D000->unk4, sp2C, D_8032D000->unk10);

    b[0] = (D_8032D000->unk4[0] + sp38[0]) / 2.0f;
    b[1] = (D_8032D000->unk4[1] + sp38[1]) / 2.0f + 125.0f;
    b[2] = (D_8032D000->unk4[2] + sp38[2]) / 2.0f;

    func_8037A788(b, c, sp7C, 4096, sp60);
    c[1] = func_80381900(a->unk28, 20000.0f, a->unk2C, &sp58);
    if (sp58 != NULL)
    {
        sp74 = sp58->normal[0];
        sp70 = sp58->normal[1];
        sp6C = sp58->normal[2];
        sp68 = sp58->originOffset;
        c[1] = 300.0f - (sp74 * c[0] + sp6C * c[2] + sp68) / sp70;
        switch (D_8032CFD8)
        {
        case 145:
            c[1] += 125.0f;
            // fall through
        case 385:
            c[1] += 125.0f;
        }
    }

    if (gCurrLevelNum == 4)
        c[1] = 2047.0f;

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

    b[1] = (D_8032D000->unk4[1] + sp38[1]) / 2.0f + 100.0f;
    if (sp5E == 1)
        b[1] += 300.0f * sins((gMarioStates[0].angleVel[1] > 0.0f) ? gMarioStates[0].angleVel[1] : -gMarioStates[0].angleVel[1]);

    if (sp7C < 400.0f)
        sp7C = 400.0f;
    func_80280BD8(sp7C, 6144);
    func_8037A788(c, c, D_8033B3EE, D_8033B3F0 + 0x1000, sp60);

    return sp60;
}

void CameraChange05(UNUSED struct Struct80280550 *a, UNUSED Vec3f b, UNUSED Vec3f c)
{
}

void Unknown80282678(UNUSED int unused)
{
}

void func_8028268C(struct Struct80280550 *a)
{
    a->unk3A = CameraChange0B(a, a->unk4, a->unk10);
}

void func_802826CC(struct Struct80280550 *a)
{
    u16 dummy;

    func_8028B3DC(a, 0.0f);
    func_8029A478(2);
    a->unk3A = CameraChange0C(a, a->unk4, a->unk10);
    func_80289184(&dummy, 0, 1024);
}

void func_80282730(struct Struct80280550 *a)
{
    UNUSED u8 unused[8];

    if (gCurrLevelNum == 4)
        func_8029A478(7);
    else
        func_8029A478(4);
    a->unk3A = CameraChange0D(a, a->unk4, a->unk10);
    a->unk2 = a->unk3A;
    func_8027FF44(a);
    vec3f_set(D_8033B460, 0.0f, 0.0f, 0.0f);
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
    float sp24 = 800.0f;
    float sp20 = 125.0f;

    if (D_8033B314 & 1)
    {
        sp24 = 350.0f;
        sp20 = 120.0f;
    }
    if (!(D_8032D000->unk0 & 0x6000))
        sp34 = 128;
    vec3f_copy(b, D_8032D000->unk4);
    a->unk4[1] += sp20;
    sp48 = func_8028A640(b, c);
    sp40 = func_8028A440(b, c);
    func_8037A69C(b, c, &sp48, &sp40, &sp3E);
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
            func_802893E4(&sp48, sp24, 5.0f);
        sp38 = -16376;
        D_8033B3F8 = 30;
        sp36 = 2;
    }
    if (D_8033B31E & 1)
    {
        if (gPlayer1Controller->buttonPressed & R_CBUTTONS)
            func_8028B2D0();
        if (sp48 < sp24)
            func_802893E4(&sp48, sp24, 5.0f);
        sp38 = 16376;
        D_8033B3F8 = 30;
        sp36 = 2;
    }
    if (D_8033B31E & 4)
    {
        if (gPlayer1Controller->buttonPressed & (U_CBUTTONS | D_CBUTTONS))
            func_8028B2D0();
        if (sp48 < sp24)
            func_802893E4(&sp48, sp24, 5.0f);
        sp3C = -12288;
        D_8033B3FA = 30;
        sp34 = 2048;
    }
    if (D_8033B31E & 8)
    {
        if (gPlayer1Controller->buttonPressed & (U_CBUTTONS | D_CBUTTONS))
            func_8028B2D0();
        if (sp48 < sp24)
            func_802893E4(&sp48, sp24, 5.0f);
        sp3C = 12288;
        D_8033B3FA = 30;
        sp34 = 2048;
    }

    func_80288ECC(&sp3E, sp3A + sp38, sp36);
    func_80289184(&sp40, sp3C, sp34);
    if (sp48 < 300.0f)
        sp48 = 300.0f;
    func_8037A788(b, c, sp48, sp40, sp3E);
    if (D_8032CFD8 == 177)
        sp3E = func_802899A0(c, b, 4508.0f, -3739.0f, 4508.0f, -3739.0f);
    if (D_8032CFD8 == 209)
        sp3E = func_802899A0(c, b, 8192.0f, -8192.0f, 8192.0f, -8192.0f);
    if (D_8032CFD8 == 210)
        sp3E = func_802899A0(c, b, 2458.0f, -2458.0f, 2458.0f, -2458.0f);

    return sp3E;
}

int func_80282D90(struct Struct80280550 *a)
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
        sp30 = func_80381900(a->unk10[0], a->unk10[1], a->unk10[2], &sp50);
        sp44[1] = sp54->waterLevel + 0x78;
        if (sp44[1] < (sp30 += 120.0f))
            sp44[1] = sp30;
    }
    func_8028C2F0(a, sp44[1], 50.0f);
    sp34 = func_80381BA0(a->unk10[0], a->unk10[2]) + 100.0f;
    if (a->unk10[1] <= sp34)
        D_8033B4D8 |= 0x4000;
    else
        D_8033B4D8 &= ~0x4000;
    func_8028F04C(a->unk10, sp38);
    func_8037A69C(a->unk4, a->unk10, &sp2C, &sp2A, &sp28);
    if (sp2C > 800.0f)
    {
        sp2C = 800.0f;
        func_8037A788(a->unk4, a->unk10, sp2C, sp2A, sp28);
    }
    func_8027FF44(a);

    return sp26;
}

int func_80282FC8(struct Struct80280550 *a)
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
        D_8033B3EE = approach_f32(D_8033B3EE, -600.0f, 20.0f, 20.0f);
    else
        D_8033B3EE = approach_f32(D_8033B3EE, 0.0f, 20.0f, 20.0f);

    func_8028B1DC();
    vec3f_copy(a->unk4, D_8032D000->unk4);
    a->unk4[1] += 50.0f;
    func_8037A69C(a->unk4, a->unk10, &sp38, &sp2E, &sp2C);
    sp34 = 800.0f;
    if (D_8032D000->unk0 == 1192)
    {
        sp34 = 1000.0f;
        sp26 = 10240;
        func_80289184(&sp2C, sp24, 256);
    }
    else
    {
        func_80289184(&sp2C, sp24, 128);
    }
    func_80289184(&sp2E, sp26, 256);
    if (D_8032D000->unk0 != 1192 && D_8033B280 == 10)
    {
        func_8037A788(a->unk4, sp3C, sp34 + D_8033B3EE, sp2E, sp2C);
        a->unk10[0] = sp3C[0];
        a->unk10[2] = sp3C[2];
        func_802893E4(&a->unk10[1], a->unk4[1], 30.0f);
        func_8037A69C(a->unk10, a->unk4, &sp38, &sp2E, &sp2C);
        sp30 = (sp38 - sp34 + D_8033B3EE) / 10000.0f;
        if (sp30 > 1.0f)
            sp30 = 1.0f;
        sp2E += 4096.0f * sp30;
        func_8037A788(a->unk10, a->unk4, sp38, sp2E, sp2C);
    }
    else
    {
        func_8037A788(a->unk4, a->unk10, sp34 + D_8033B3EE, sp2E, sp2C);
        D_8033B4DA |= 2;
        sp48 = func_80381900(a->unk10[0], a->unk10[1] + 200.0f, a->unk10[2], &sp4C) + 125.0f;
        if (a->unk10[1] < sp48)
            a->unk10[1] = sp48;
        func_8037A69C(a->unk4, a->unk10, &sp38, &sp2E, &sp2C);
        if (sp38 > sp34 + D_8033B3EE)
        {
            sp38 = sp34 + D_8033B3EE;
            func_8037A788(a->unk4, a->unk10, sp38, sp2E, sp2C);
        }
    }

    sp2C = func_8028A4F0(a->unk4, a->unk10);
    return sp2C;
}

void func_80283434(struct Struct80280550 *a)
{
    a->unk3A = func_80282D90(a);
}

void CameraChange08(UNUSED struct Struct80280550 *a, UNUSED Vec3f b, UNUSED Vec3f c)
{
}

void func_80283484(struct Struct80280550 *a)
{
    a->unk3A = func_80282D90(a);
}

int CameraChange040710(UNUSED struct Struct80280550 *a, Vec3f b, Vec3f c)
{
    s16 sp2E = D_8032D000->unk10[1] + D_8033B402 + 32768;

    func_8027F870(b, c, 125.0f, 125.0f, D_8032CFEC, 1456, sp2E);
    return D_8032D000->unk10[1];
}

extern float D_8033B3F4;
extern float D_80336070;

int func_80283548(struct Struct80280550 *a)
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
    float sp40 = func_80381264(D_8033B328[9], D_8033B328[10], D_8033B328[11], &sp94);
    s16 sp3E;

    func_8028B7A4(a);
    func_8037A69C(D_8032D000->unk4, a->unk10, &sp80, &sp70, &sp6E);

    if (D_8033B4D8 & 2)
    {
        if (func_80288130(0) == 1)
            sp7C = D_8032CFEC + 1050.0f;
        else
            sp7C = D_8032CFEC + 400.0f;
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

    if (D_8033B3F4 == 0.0f)
    {
        if (sp80 > sp7C)
        {
            if ((sp80 -= 50.0f) < sp7C)
                sp80 = sp7C;
        }
    }
    else
    {
        if ((D_8033B3F4 -= 30.0f) < 0.0f)
            D_8033B3F4 = 0;
        if (sp80 > sp7C)
        {
            if ((sp80 -= 30.0f) < sp7C)
                sp80 = sp7C;
        }
        if (sp80 < sp7C)
        {
            if ((sp80 += 30.0f) > sp7C)
                sp80 = sp7C;
        }
    }
    if (D_8033B3F8 == 0)
    {
        if (a->unk0 == 16)
            sp52 = 192;
        else
            sp52 = 256;
        if ((gPlayer1Controller->stickX != 0.0f || gPlayer1Controller->stickY != 0.0f) != 0)
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
        if (sp58 >= 250.0f)
            D_8033B4DA &= ~0x8000;
        if (ABS((D_8032D000->unk10[1] - sp6E) / 2) < 0x1800)
        {
            D_8033B4DA &= ~0x8000;
            sp6E = D_8033B2B0 + 32768;
            sp80 = 800.0f;
            D_8033B4DA |= 2;
        }
    }
    else if (sp58 < 250.0f)
    {
        a->unk10[0] += (250.0f - sp58) * sins(sp6E);
        a->unk10[2] += (250.0f - sp58) * coss(sp6E);
        if (D_8033B3F8 == 0)
        {
            sp52 = 4096;
            D_8032CFD4 = 0;
            func_8037A69C(D_8032D000->unk4, a->unk10, &sp80, &sp70, &sp6E);
        }
        sp44 |= 1;
    }

    if (-16.0f < gPlayer1Controller->stickY)
        a->unk2 = sp6E;

    func_8027F668(&sp68, 1.0f, 200.0f, &sp64, 0.9f, 200.0f);
    vec3f_copy(spB0, a->unk10);
    sp48 = func_8028F2F0(a, spB0, &sp72, 1536);
    if (sp48 == 3)
    {
        D_8033B2AC = sp72;
        D_8033B2AE = sp6E;
        D_8033B4DA |= 0x200;
        func_8037A69C(D_8032D000->unk4, spB0, &sp58, &sp5E, &sp5C);
        func_80288ECC(&sp6E, sp72, 10);
        func_8037A788(D_8032D000->unk4, spB0, sp58, sp5E, sp5C);
        D_8033B2AE = (D_8033B2AE - sp6E) / 256;
    }
    else
    {
        if (gMarioStates[0].forwardVel == 0.0f)
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
        if (sp50 != 0 && func_802D7F74() == -1)
            func_80289184(&sp6E, sp6C, sp50);
    }
    if (sp48 == 0 && !(D_8033B4DA & 0x200))
        func_80288E0C(&sp80, sp7C - 100.0f, 0.05f);
    func_8037A788(D_8032D000->unk4, spB0, sp80, sp70, sp6E);
    spB0[1] += sp68 + 125.0f;
    if (func_80288974(spB0, 10.0f, 80.0f) != 0)
        D_8033B4DA |= 0x200;
    a->unk4[0] = D_8032D000->unk4[0];
    a->unk4[1] = D_8032D000->unk4[1] + 125.0f + sp64;
    a->unk4[2] = D_8032D000->unk4[2];
    sp88 = 125.0f + D_8033B27C;
    spA0 = D_8033B278;
    sp90 = func_80381900(spB0[0], spB0[1] + 50.0f, spB0[2], &sp9C) + 125.0f;
    for (sp4C = 0.1f; sp4C < 1.0f; sp4C += 0.2f)
    {
        func_8028A24C(spBC, spB0, D_8032D000->unk4, sp4C);
        sp8C = func_80381900(spBC[0], spBC[1], spBC[2], &sp98) + 125.0f;
        if (sp98 != NULL && sp8C > sp88)
        {
            sp88 = sp8C;
            spA0 = sp98;
        }
    }
    if (D_8033B314 & 1)
    {
        sp88 -= 35.0f;
        sp90 -= 35.0f;
        a->unk4[1] -= 25.0f;
    }
    sp78 = func_80381BA0(spB0[0], spB0[2]);
    if (sp78 != -11000.0f)
    {
        sp78 += 125.0f;
        sp60 = sp78 - sp88;
        if (!(D_8033B4D8 & 0x20))
        {
            if (sp60 > 800.0f && (D_8032D000->unk0 & 0x4000))
                D_8033B4D8 |= 0x20;
        }
        else
        {
            if (sp60 < 400.0f || !(D_8032D000->unk0 & 0x4000))
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
    spBC[1] -= 125.0f;
    if (spA0 != NULL && sp90 <= sp88)
    {
        sp48 = func_8028A0D4(a->unk4, spBC, spA0, 0, -1);
        if (sp48 != 1 && sp40 > sp88)
            sp90 = sp88;
    }
    sp68 = 0.0f;
    if (a->unk0 == 16)
    {
        if (D_8033B4D8 & 2)
        {
            sp68 = 375.0f;
            if (D_8032CFD8 == 130)
                sp68 /= 2.0f;
        }
        else
        {
            sp68 = 100.0f;
        }
    }
    if ((D_8033B4D8 & 2) && (D_8033B314 & 1))
    {
        sp68 = 610.0f;
        if (D_8032CFD8 == 130 || gCurrLevelNum == 6)
            sp68 /= 2.0f;
    }
    sp74 = func_80381D3C(spB0[0], spB0[2]);
    if (sp74 != -11000.0f)
    {
        if ((sp74 += 130.0f) > a->unk10[1])
            a->unk10[1] = sp74;
    }
    if ((D_8032D000->unk0 & 0x200000) || D_8032D000->unk0 == 1192)
    {
        sp90 = D_8032D000->unk4[1] + 400.0f;
        if (a->unk0 == 16)
            sp90 -= 100.0f;
        sp40 = 20000.0f;
        vec3f_copy(a->unk4, D_8032D000->unk4);
    }
    if (D_8032D000->unk0 & 0x100000)
    {
        sp90 = gMarioStates[0].usedObj->pos[1] + 125.0f;
        if (D_8032D000->unk4[1] - 100.0f > sp90)
            sp90 = D_8032D000->unk4[1] - 100.0f;
        sp40 = 20000.0f;
        vec3f_copy(a->unk4, D_8032D000->unk4);
    }
    if (sp90 != -11000.0f)
    {
        sp90 += sp68;
        func_8028C2F0(a, sp90, 20.0f);
    }
    a->unk10[0] = spB0[0];
    a->unk10[2] = spB0[2];
    spB0[0] = D_8033B328[9];
    spB0[1] = a->unk10[1];
    spB0[2] = D_8033B328[11];
    func_8037A69C(spB0, a->unk10, &sp80, &sp5E, &sp5C);
    if (sp80 > 50.0f)
    {
        sp80 = 50.0f;
        func_8037A788(spB0, a->unk10, sp80, sp5E, sp5C);
    }
    if (D_8033B280 != 10)
    {
        func_8037A69C(a->unk4, a->unk10, &sp80, &sp5E, &sp5C);
        if (sp80 > sp7C)
        {
            sp80 = sp7C;
            func_8037A788(a->unk4, a->unk10, sp80, sp5E, sp5C);
        }
    }
    if (sp40 != 20000.0f)
    {
        if (a->unk10[1] > (sp40 -= 150.0f) && (sp48 = func_8028A0D4(a->unk10, D_8032D000->unk4, sp94, 0, -1)) == 1)
            a->unk10[1] = sp40;
    }
    if (D_8032CFD8 == 178)
    {
        sp6E = func_802899A0(a->unk10, a->unk4, 2254.0f, -3789.0f, 3790.0f, -2253.0f);
    }
    return sp6E;
}

void func_80284708(struct Struct80280550 *a)
{
    func_8029A478(2);
    a->unk3A = func_80283548(a);
    func_8027FF44(a);
}

void func_8028474C(struct Struct80280550 *a)
{
    D_8032CFEC = 800.0f;
    func_80284708(a);
}

void func_80284788(struct Struct80280550 *a)
{
    D_8032CFEC = 350.0f;
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
    vec3f_set(D_8032D00C, -1280.0f, 614.0f, 1740.0f);
    func_8027F668(&sp2C, 1.0f, 200.0f, &sp2C, 0.9f, 200.0f);
    b[0] = D_8032D000->unk4[0];
    sp24 = D_8032D000->unk4[1] + 125.0f + sp2C;
    b[2] = D_8032D000->unk4[2];
    vec3f_copy(sp44, c);
    func_8037A69C(D_8032D00C, b, &sp30, &sp5A, &sp58);
    func_8037A69C(D_8032D00C, sp44, &sp30, &sp56, &sp54);
    D_8033B404 = sp54 - sp58;
    if (D_8033B404 < -0x4000)
        D_8033B404 = -0x4000;
    if (D_8033B404 > 0x4000)
        D_8033B404 = 0x4000;
    sp58 += D_8033B404;
    sp54 = sp58;
    func_80289184(&sp54, sp58, 4096);
    func_8037A788(D_8032D00C, sp44, 300.0f, 0, sp54);
    sp38[0] = b[0] + (sp44[0] - b[0]) * 0.7f;
    sp38[1] = b[1] + (sp44[1] - b[1]) * 0.7f + 300.0f;
    sp38[2] = b[2] + (sp44[2] - b[2]) * 0.7f;
    sp28 = func_80381900(sp38[0], sp38[1] + 50.0f, sp38[2], &sp34);

    if (sp28 != D_80336070)
    {
        if (sp28 < D_8033B27C)
            sp28 = D_8033B27C;
        c[1] = approach_f32(c[1], (sp28 += 125.0f), 30.0f, 30.0f);
    }

    func_802893E4(&b[1], sp24, 30.0f);
    c[0] = sp44[0];
    c[2] = sp44[2];
    sp5C = func_8028A4F0(b, c);

    return sp5C;
}

void func_80284AFC(struct Struct80280550 *a)
{
    a->unk3A = CameraChange11(a, a->unk4, a->unk10);
}

int CameraChange090F(UNUSED struct Struct80280550 *a, Vec3f b, Vec3f c)
{
    s16 sp2E = D_8032D000->unk10[1] + D_8033B402 + 32768;

    func_8027F870(b, c, 125.0f, 125.0f, 800.0f, 5461, sp2E);
    return D_8032D000->unk10[1];
}

void Unknown80284BCC(struct Struct80280550 *a)
{
    if (gPlayer1Controller->buttonPressed & U_CBUTTONS)
        D_8033B4D8 |= 0x2000;
    a->unk3A = func_80282FC8(a);
}

void func_80284C2C(struct Struct80280550 *a)
{
    if (D_8033B280 == 11 || D_8033B280 == 121)
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

void func_80284CBC(struct Struct80280550 *a)
{
    vec3f_copy(D_8033B498[0], a->unk10);
    func_80287800(D_8033B498[0], D_8032D000->unk4);
    vec3f_set(D_8033B498[1], 0.0f, a->unk4[1] - D_8032D000->unk4[1], 0.0f);
}

int func_80284D44(struct Struct80280550 *a)
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

int func_80284DC0(struct Struct80280550 *a)
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
        func_8037A69C(sp68, a->unk10, &sp48, &sp42, &sp40);
        vec3f_copy(sp5C, a->unk10);
        sp48 = 80.0f;
        if (D_8033B41A == 17 || D_8033B41A == 4 || D_8033B41A == 16)
        {
            sp58 = 1;
            for (sp54 = 0; sp54 < 16 && sp58 == 1; sp54++)
            {
                func_8037A788(sp68, sp5C, sp48, 0, sp40 + sp3E);
                if (func_80380DE8(&sp5C[0], &sp5C[1], &sp5C[2], 20.0f, 50.0f) == 0)
                {
                    for (sp44 = sp48; sp44 < D_8032CFEC; sp44 += 20.0f)
                    {
                        func_8037A788(sp68, sp5C, sp44, 0, sp40 + sp3E);
                        sp50 = func_80381264(sp5C[0], sp5C[1] - 150.0f, sp5C[2], &sp74) + -10.0f;
                        if (sp74 != NULL && sp50 < sp5C[1])
                            break;
                        sp4C = func_80381900(sp5C[0], sp5C[1] + 150.0f, sp5C[2], &sp74) + 10.0f;
                        if (sp74 != NULL && sp4C > sp5C[1])
                            break;
                        if (func_80380DE8(&sp5C[0], &sp5C[1], &sp5C[2], 20.0f, 50.0f) == 1)
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
                func_8037A788(sp68, D_8033B498[0], D_8032CFEC, 0, sp40 + sp3E);
                vec3f_copy(D_8033B498[1], sp68);
                func_80287800(D_8033B498[0], D_8032D000->unk4);
                func_80287800(D_8033B498[1], D_8032D000->unk4);
            }
            D_8033B4D8 |= 0x200;
            func_80285A8C(a, 15);
        }
        else
        {
            D_8033B4D8 &= ~0x2200;
            func_8037A788(sp68, a->unk10, sp48, sp42, sp40 + sp3E);
        }
        func_8028B29C();
    }
    return 0;
}

int CameraChange06(UNUSED struct Struct80280550 *a, Vec3f b, Vec3f c)
{
    s16 sp2E = D_8033B400;
    s16 sp2C = D_8032D000->unk10[1] + D_8033B402 + 32768;
    
    func_8027F870(b, c, 125.0f, 125.0f, 250.0f, sp2E, sp2C);
    return D_8032D000->unk10[1];
}

void func_802852F4(UNUSED struct Struct80280550 *a)
{
    UNUSED s16 sp6 = D_8033B400;
    UNUSED s16 sp4 = D_8033B402;
    
    D_8033B400 += (s16)(gPlayer1Controller->stickY * 10.0f);
    D_8033B402 -= (s16)(gPlayer1Controller->stickX * 10.0f);
    
    if (D_8033B400 >= 0x38E4)
        D_8033B400 = 14563;
    if (D_8033B400 < -0x2000)
        D_8033B400 = -8192;
    if (D_8033B402 >= 0x5556)
        D_8033B402 = 21845;
    if (D_8033B402 < -0x5555)
        D_8033B402 = -21845;

    D_8032D000->unk16 = D_8033B400 * 3 / 4;
    D_8032D000->unk18 = D_8033B402 * 3 / 4;
}

void func_8028547C(struct Struct80280550 *a)
{
    struct Struct8033B418_sub *sp2C = &D_8033B418.unk8[0];
    struct Struct8033B418_sub *sp28 = &D_8033B418.unk8[1];
    float sp24 = sp28->unk18 - sp2C->unk18;
    s16 sp22 = sp28->unk1C - sp2C->unk1C;
    s16 sp20 = sp28->unk1E - sp2C->unk1E;
    
    sp24 = sp2C->unk18 + sp24 * D_8033B418.unk6 / D_8033B418.unk4;
    sp22 = sp2C->unk1C + sp22 * D_8033B418.unk6 / D_8033B418.unk4;
    sp20 = sp2C->unk1E + sp20 * D_8033B418.unk6 / D_8033B418.unk4;
    a->unk4[0] = (sp28->unk0 - sp2C->unk0) * D_8033B418.unk6 / D_8033B418.unk4 + sp2C->unk0;
    a->unk4[1] = (sp28->unk4 - sp2C->unk4) * D_8033B418.unk6 / D_8033B418.unk4 + sp2C->unk4;
    a->unk4[2] = (sp28->unk8 - sp2C->unk8) * D_8033B418.unk6 / D_8033B418.unk4 + sp2C->unk8;
    vec3f_add(a->unk4, D_8032D000->unk4);
    func_8037A788(a->unk4, a->unk10, sp24, sp22, sp20);
    D_8032D000->unk16 = 0;
    D_8032D000->unk18 = 0;
    if (++D_8033B418.unk6 == D_8033B418.unk4)
        D_8033B4D8 &= ~0x100;
}

u8 unknown8032D0A8[8] = {0x00, 0x0E, 0x00, 0x01, 0x00, 0x02, 0x00, 0x04};
