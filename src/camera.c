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

void func_8027FA48(float *a, float b)
{
    struct Surface *sp44;
    float sp40;
    float sp3C;
    float sp38;
    UNUSED u8 filler[8];
    UNUSED s16 sp2E = D_8032D000->unk0;
    float sp28 = 125.0f;
    float sp24 = func_80381264(a[4], D_8033B328[10] - 50.0f, a[6], &sp44);

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
        sp38 = func_80381900(a[4], a[5] + 100.0f, a[6], &sp44) + sp28;
        sp40 = sp28 + D_8033B27C;
        if (sp38 < sp40)
            sp38 = sp40;
        if (b < sp38)
        {
            b = sp38;
            a[5] = b;
        }
        if (D_8032D000->unk0 == 0x2033B || D_8032D000->unk0 == 0x2033A || D_8032D000->unk0 == 0x2033C)
        {
            if (ABS(a[5] - b) > 1000.0f)
                a[5] = b;
        }
        func_8028C2F0(a, b, 20.0f);
        if (sp24 != 20000.0f)
        {
            sp24 -= sp28;
            if ((a[5] > sp24 && D_8033B27C + sp28 < sp24)
              || (D_8033B28C != 20000.0f && D_8033B28C > sp24 && a[5] > sp24))
                a[5] = sp24;
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

void func_8027FF44(float *a)
{
    float sp34;
    s16 sp32;
    s16 sp30;
    Vec3f sp24 = {0, 0, 0};

    func_8037A69C(a + 4, D_8032D000->unk4, &sp34, &sp32, &sp30);
    
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
    Vec3f_Add(a + 1, sp24);
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

int CameraChange01(float *a, Vec3f b, Vec3f c)
{
    float sp4C = D_8032D000->unk4[0] - a[10];
    float sp48 = D_8032D000->unk4[2] - a[11];
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
