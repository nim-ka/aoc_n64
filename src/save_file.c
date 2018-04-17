#include <ultra64.h>

#include "sm64.h"
#include "math_util.h"

void func_80278BB0(void)
{
    UNUSED int pad;
}

int func_80278BC4(void *buffer, int size)
{
    int result = 0;

    if (gEepromProbe != 0)
    {
        int tries = 4;
        u32 offset = (u32)((u8 *)buffer - (u8 *)&D_80207B00) >> 3;

        do
        {
            tries--;
            result = osEepromLongRead(&D_80339C08, offset, buffer, size);
        } while (tries > 0 && result != 0);
    }
    return result;
}

int func_80278C68(void *buffer, int size)
{
    int result = 1;

    if (gEepromProbe != 0)
    {
        int tries = 4;
        u32 offset = (u32)((u8 *)buffer - (u8 *)&D_80207B00) >> 3;

        do
        {
            tries--;
            result = osEepromLongWrite(&D_80339C08, offset, buffer, size);
        } while (tries > 0 && result != 0);
    }
    return result;
}

int func_80278D10(u8 *a, int b)
{
    u16 ret = 0;

    while (b-- > 2)
        ret += *a++;
    return ret;
}

int func_80278D64(void *buffer, int size, u16 c)
{
    u16 *sp1C = (u16 *)((size - 4) + (u8 *)buffer);

    if (sp1C[0] != c)
        return 0;
    if (sp1C[1] != func_80278D10(buffer, size))
        return 0;
    return 1;
}

void CalcSaveChecksum(void *buffer, int size, u16 c)
{
    u16 *sp1C = (u16 *)((size - 4) + (u8 *)buffer);

    sp1C[0] = c;
    sp1C[1] = func_80278D10(buffer, size);
}

void func_80278E4C(int a)
{
    int sp1C = a ^ 1;

    CalcSaveChecksum(&D_80207B00.unk1C0[a], sizeof(D_80207B00.unk1C0[a]), 18505);
    bcopy(&D_80207B00.unk1C0[a], &D_80207B00.unk1C0[sp1C], sizeof(D_80207B00.unk1C0[sp1C]));
    func_80278C68(&D_80207B00.unk1C0[sp1C], 32);
}

void SaveMenuData(void)
{
    if (D_8033A135 != 0)
    {
        CalcSaveChecksum(&D_80207B00.unk1C0[0], sizeof(D_80207B00.unk1C0[0]), 18505);
        bcopy(&D_80207B00.unk1C0[0], &D_80207B00.unk1C0[1], sizeof(D_80207B00.unk1C0[1]));
        func_80278C68(D_80207B00.unk1C0, sizeof(D_80207B00.unk1C0));
        D_8033A135 = 0;
    }
}

void func_80278F6C(void)
{
    bzero(&D_80207B00.unk1C0[0], sizeof(D_80207B00.unk1C0[0]));
    D_80207B00.unk1C0[0].unk0[0] = 0x3FFFFFFF;
    D_80207B00.unk1C0[0].unk0[1] = 0x2AAAAAAA;
    D_80207B00.unk1C0[0].unk0[2] = 0x15555555;

    D_8033A135 = 1;
    SaveMenuData();
}

int func_80278FF0(int a, int b)
{
    return (D_80207B00.unk1C0[0].unk0[a] >> (b * 2)) & 3;
}

void func_80279024(int a, int b, int c)
{
    int sp4 = 3 << (b * 2);

    D_80207B00.unk1C0[0].unk0[a] &= ~sp4;
    D_80207B00.unk1C0[0].unk0[a] |= c << (b * 2);
}

void func_802790A0(int a, int b)
{
    int i;
    u32 sp20;
    u32 sp1C = func_80278FF0(a, b);

    if (sp1C != 0)
    {
        for (i = 0; i < 4; i++)
        {
            sp20 = func_80278FF0(i, b);
            if (sp20 < sp1C)
                func_80279024(i, b, sp20 + 1);
        }
        func_80279024(a, b, 0);
        D_8033A135 = 1;
    }
}

void func_80279150(int a)
{
    int i;

    for (i = 0; i < 15; i++)
        func_802790A0(a, i);
}

void func_80279198(int a, int b)
{
    int sp1C = b ^ 1;

    CalcSaveChecksum(&D_80207B00.unk0[a][b], sizeof(D_80207B00.unk0[a][b]), 17473);
    bcopy(&D_80207B00.unk0[a][b], &D_80207B00.unk0[a][sp1C], sizeof(D_80207B00.unk0[a][sp1C]));
    func_80278C68(&D_80207B00.unk0[a][sp1C], sizeof(D_80207B00.unk0[a][sp1C]));
}

void SaveFileData(int a)
{
    if (D_8033A136 != 0)
    {
        CalcSaveChecksum(&D_80207B00.unk0[a][0], sizeof(D_80207B00.unk0[a][0]), 17473);
        bcopy(&D_80207B00.unk0[a][0], &D_80207B00.unk0[a][1], sizeof(D_80207B00.unk0[a][1]));
        func_80278C68(D_80207B00.unk0[a], sizeof(D_80207B00.unk0[a]));
        D_8033A136 = 0;
    }
    SaveMenuData();
}

void func_8027934C(int a)
{
    func_80279150(a);
    bzero(&D_80207B00.unk0[a][0], sizeof(D_80207B00.unk0[a][0]));

    D_8033A136 = 1;
    SaveFileData(a);
}

void func_802793B0(int a, int b)
{
    UNUSED int pad;

    func_80279150(b);
    bcopy(&D_80207B00.unk0[a][0], &D_80207B00.unk0[b][0], sizeof(D_80207B00.unk0[b][0]));

    D_8033A136 = 1;
    SaveFileData(b);
}

void CopyFromEeprom(void)
{
    int sp2C;
    int sp28;

    D_8033A135 = 0;
    D_8033A136 = 0;

    bzero(&D_80207B00, sizeof(D_80207B00));
    func_80278BC4(&D_80207B00, sizeof(D_80207B00));

    sp28 = func_80278D64(&D_80207B00.unk1C0[0], sizeof(D_80207B00.unk1C0[0]), 18505);
    sp28 |= func_80278D64(&D_80207B00.unk1C0[1], sizeof(D_80207B00.unk1C0[1]), 18505) << 1;
    switch (sp28)
    {
    case 0:
        func_80278F6C();
        break;
    case 1:
        func_80278E4C(0);
        break;
    case 2:
        func_80278E4C(1);
        break;
    }

    for (sp2C = 0; sp2C < 4; sp2C++)
    {
        sp28 = func_80278D64(&D_80207B00.unk0[sp2C][0], sizeof(D_80207B00.unk0[sp2C][0]), 17473);
        sp28 |= func_80278D64(&D_80207B00.unk0[sp2C][1], sizeof(D_80207B00.unk0[sp2C][1]), 17473) << 1;
        switch (sp28)
        {
        case 0:
            func_8027934C(sp2C);
            break;
        case 1:
            func_80279198(sp2C, 0);
            break;
        case 2:
            func_80279198(sp2C, 1);
            break;
        }
    }

    func_80278BB0();
}

void func_80279618(void)
{
    bcopy(&D_80207B00.unk0[D_8032CE94 - 1][1], &D_80207B00.unk0[D_8032CE94 - 1][0], 56);
    bcopy(&D_80207B00.unk1C0[1], &D_80207B00.unk1C0[0], sizeof(D_80207B00.unk1C0[0]));

    D_8033A135 = 0;
    D_8033A136 = 0;
}

void func_80279694(s16 a, s16 b)
{
    int sp34 = D_8032CE94 - 1;
    int sp30 = D_8033A756 - 1;
    int sp2C = 1 << b;
    UNUSED int sp28 = func_80279BBC();

    D_8032CE20 = sp30 + 1;
    D_8032CE24 = b + 1;
    D_8032CE28 = 0;
    D_8032CE2C = 0;

    if (sp30 >= 0 && sp30 < 15)
    {
        if (a > ((u16)func_802798D0(sp30) & 0xFFFF))
            D_8032CE28 = 1;
        if (func_80279D60(sp34, sp30) < a)
        {
            D_80207B00.unk0[sp34][0].unk25[sp30] = a;
            func_802790A0(sp34, sp30);
            D_8032CE2C = 1;
            D_8033A136 = 1;
        }
    }

    switch (D_8032CE98)
    {
    case 30:
        if (!(func_80279BBC() & 0x50))
            func_80279AF8(16);
        break;
    case 33:
        if (!(func_80279BBC() & 0xA0))
            func_80279AF8(32);
        break;
    case 34:
        break;
    default:
        if (!(get_game_data(sp34, sp30) & sp2C))
            func_80279C8C(sp34, sp30, sp2C);
        break;
    }
}

int func_80279894(int a)
{
    return (D_80207B00.unk0[a][0].unk8 & 1) != 0;
}

int func_802798D0(int a)
{
    int sp3C;
    int sp38 = -1;
    int sp34 = -1;
    int sp30 = 0;

    for (sp3C = 0; sp3C < 4; sp3C++)
    {
        if (get_game_data(sp3C, a) != 0)
        {
            int sp2C = func_80279D60(sp3C, a);
            int sp28 = func_80278FF0(sp3C, a);

            if (sp2C > sp38 || (sp2C == sp38 && sp28 > sp34))
            {
                sp38 = sp2C;
                sp34 = sp28;
                sp30 = sp3C + 1;
            }
        }
    }
    return (sp30 << 16) + max(sp38, 0);
}

int func_802799D0(int a, int b)
{
    int sp24;
    int sp20 = 0;
    u8 sp1F = 1;
    u8 sp1E = get_game_data(a, b);

    for (sp24 = 0; sp24 < 7; sp24++, sp1F <<= 1)
    {
        if (sp1E & sp1F)
            sp20++;
    }
    return sp20;
}

int GetStarCount(int a, int b, int c)
{
    int sp24 = 0;

    for (; b <= c; b++)
        sp24 += func_802799D0(a, b);
    return func_802799D0(a, -1) + sp24;
}

void func_80279AF8(int a)
{
    D_80207B00.unk0[D_8032CE94 - 1][0].unk8 |= (a | 1);
    D_8033A136 = 1;
}

void func_80279B44(int a)
{
    D_80207B00.unk0[D_8032CE94 - 1][0].unk8 &= ~a;
    D_80207B00.unk0[D_8032CE94 - 1][0].unk8 |= 1;
    D_8033A136 = 1;
}

int func_80279BBC(void)
{
    if (D_8032CE70 != 0 || gDemoInputs != NULL)
        return 0;
    return D_80207B00.unk0[D_8032CE94 - 1][0].unk8;
}

int get_game_data(int a, int b)
{
    int ret;

    if (b == -1)
        ret = (D_80207B00.unk0[a][0].unk8 >> 24) & 0x7F;
    else
        ret = D_80207B00.unk0[a][0].unkC[b] & 0x7F;
    return ret;
}

void func_80279C8C(int a, int b, int c)
{
    if (b == -1)
        D_80207B00.unk0[a][0].unk8 |= c << 24;
    else
        D_80207B00.unk0[a][0].unkC[b] |= c;
    D_80207B00.unk0[a][0].unk8 |= 1;
    D_8033A136 = 1;
}

int func_80279D60(int a, int b)
{
    return D_80207B00.unk0[a][0].unk25[b];
}

int func_80279D90(void)
{
    return (D_80207B00.unk0[D_8032CE94 - 1][0].unkC[D_8033A756] & 0x80) != 0;
}

void func_80279DE0(void)
{
    D_80207B00.unk0[D_8032CE94 - 1][0].unkC[D_8033A756] |= 0x80;
    D_80207B00.unk0[D_8032CE94 - 1][0].unk8 |= 1;
    D_8033A136 = 1;
}

void func_80279E68(s16 a, s16 b, s16 c)
{
    struct Struct80207B00_sub2 *sp1C = &D_80207B00.unk0[D_8032CE94 - 1][0];

    sp1C->unk0 = D_8032CE98;
    sp1C->unk1 = D_8033A75A;
    Vec3s_Set(sp1C->unk2, a, b, c);
    func_80279AF8(0x10000);
}

int func_80279EFC(Vec3s a)
{
    struct Struct80207B00_sub2 *sp1C = &D_80207B00.unk0[D_8032CE94 - 1][0];
    int sp18 = func_80279BBC();

    if (sp1C->unk0 == D_8032CE98 && sp1C->unk1 == D_8033A75A && (sp18 & 0x10000))
    {
        Vec3s_Copy(a, sp1C->unk2);
        return 1;
    }
    return 0;
}

void func_80279FB4(u16 a)
{
    func_80248DD8(a);
    D_80207B00.unk1C0[0].unk10 = a;

    D_8033A135 = 1;
    SaveMenuData();
}

u16 func_8027A004(void)
{
    return D_80207B00.unk1C0[0].unk10;
}

void func_8027A024(void)
{
    if (func_80279BBC() & 0x10000)
    {
        switch (D_80207B00.unk0[D_8032CE94 - 1][0].unk0)
        {
        case 8:
            func_80279AF8(0x20000);
            break;
        case 10:
            func_80279AF8(0x80000);
            break;
        case 36:
            func_80279AF8(0x40000);
            break;
        }
        func_80279B44(0x10000);
    }
}

void func_8027A0E8(void)
{
    D_8033A131 = 0;
}

void func_8027A100(u8 *a)
{
    if (a[1] & 0x80)
    {
        D_8033A130 = D_8033A758;
        D_8033A131 = D_8033A756;
        D_8033A132 = a[1] & 0x7F;
        D_8033A133 = a[2];
        D_8033A134 = a[3];
    }
}

int func_8027A168(u8 *a)
{
    s16 sp6 = 0;
    s16 sp4 = D_8032CE37[a[1] & 0x7F];

    if (D_8033A131 != 0 && D_8033A75C == sp4 && D_8033A130 == D_8033A758)
    {
        a[1] = D_8033A132;
        a[2] = D_8033A133;
        a[3] = D_8033A134;
        sp6 = 1;
    }
    else
    {
        D_8033A131 = 0;
    }
    return sp6;
}
