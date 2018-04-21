#include <ultra64.h>

#include "sm64.h"
#include "math_util.h"

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
         && D_8032D000->unk4[1] < 0.7f * gMarioStates[0].usedObj->unk1FC + gMarioStates[0].usedObj->pos[1])
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

    Vec3f_Copy(sp34, D_8032D000->unk4);
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

    func_8028A764(sp24, sp24, D_8032D000->unk12);
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
    Vec3f_Add(a->unk4, sp24);
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

Vec3f D_8032D09C = {0, -150, -125};
u8 unknown[8] = {0x00, 0x0E, 0x00, 0x01, 0x00, 0x02, 0x00, 0x04};

extern float D_80335FD0;
extern float D_80335FD4;
extern float D_80335FD8;
extern float D_80335FDC;

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
    func_8027F668(&sp40, 1.0f, 200.0f, &sp3C, D_80335FD0, 200.0f);
    func_8027F870(b, c, sp40 + sp2C, sp3C + sp2C, D_8033B3EE + sp28, sp44, sp46);
    func_8027FF44(a);
    if (D_8032CFD8 == 370)
        sp46 = func_802899A0(c, b, 6839.0f, 995.0f, D_80335FD4, D_80335FD8);

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
    func_8027F668(&sp30, 1.0f, 200.0f, &sp2C, D_80335FDC, 200.0f);
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

extern float D_80335FE0;
extern float D_80335FE4;
extern float D_80335FE8;

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
    Vec3f_Copy(sp4C, c);
    Vec3f_Copy(spE8[0], D_8033B470[D_8033B46C].unk4);
    Vec3f_Copy(spE8[1], D_8033B470[D_8033B46C + 1].unk4);
    spAC = D_8033B470[D_8033B46C].unk10;
    spA8 = D_8033B470[D_8033B46C].unk14;
    func_8027F668(&sp84, 1.0f, 200.0f, &sp84, D_80335FE0, 200.0f);
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
    Vec3f_Copy(spB8, spD0);
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
    spB8[0] *= D_80335FE4;
    spB8[1] *= D_80335FE8;
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
    Vec3f_Add(a->unk10, D_8033B478);

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

    Vec3f_Copy(b, sp78);
    func_8037A69C(b, c, &spA4, &spB6, &spB4);

    return spB4;
}
