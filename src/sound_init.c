#include <ultra64.h>

#include "sm64.h"

void func_80248C10(void)
{
    D_8032C6C0 = 0;
}

void func_80248C28(int a)
{
    switch (a)
    {
    case 1:
        func_80320248(1);
        break;
    case 2:
        func_8031FFB4(0, 60, 40);
        break;
    }
    D_8032C6C0 |= a;
}

void func_80248CB8(int a)
{
    switch (a)
    {
    case 1:
        func_80320248(0);
        break;
    case 2:
        func_80320040(0, 60);
        break;
    }
    D_8032C6C0 &= ~a;
}

void func_80248D48(void)
{
    if (D_8032C6C4 == 0)
    {
        D_8032C6C4 = 1;
        func_803208C0(2, 890);
    }
}

void func_80248D90(void)
{
    if (D_8032C6C4 == 1)
    {
        D_8032C6C4 = 0;
        func_80320980(2, 890);
    }
}

void func_80248DD8(u16 a)
{
    if (a < 3)
        func_80321434(D_8032C6E8[a]);
}

void func_80248E24(s16 a)
{
    if (a & 0x1)
        SetSound(0x700A0081, D_803320E0);
    else if (a & 0x2)
        SetSound(0x700B0081, D_803320E0);
    else if (a & 0x4)
        SetSound(0x700C0081, D_803320E0);
    else if (a & 0x8)
        SetSound(0x70080081, D_803320E0);
    else if (a & 0x10)
        SetSound(0x70080081, D_803320E0);
    else if (a & 0x20)
        SetSound(0x70090081, D_803320E0);
    else if (a & 0x40)
        SetSound(0x70060081, D_803320E0);
    else if (a & 0x80)
        SetSound(0x70070081, D_803320E0);
    
    if (a & 0x100)
        func_80249464(20, NULL);
}

void func_80248FBC(void)
{
    if (D_8035FFA8 != NULL && D_8035FFA8->unk7 == 2)
    {
        if (D_8032C780 == 0)
            SetSound(0x38280081, D_80339E00[0].unk88->unk54);
        D_8032C780 = 1;
    }
    else
    {
        D_8032C780 = 0;
    }
}

void func_80249040(void)
{
    u8 sp1f = FALSE;
    
    if (D_8032CE98 == 6 && D_8033A75A == 2
     && D_8032C9D8->unkAA < 0x46)
    {
        if (D_8032C9D8->unk68 != NULL && D_8032C9D8->unk68->unk5 == 6)
        {
            if (D_8032C9D8->unk44 < D_80334A80)
                sp1f = TRUE;
        }
    }

    if (D_8032C6D4 ^ sp1f)
    {
        D_8032C6D4 = sp1f;
        if (sp1f)
            func_80320F84(24, 0, 255, 1000);
        else
            func_80321080(500);
    }
}

void func_80249148(u16 a, u16 b, s16 c)
{
    if (D_8032C644 == 0 && b != D_8032C6C8)
    {
        if (D_8032CE70 != 0)
            func_80321368(7);
        else
            func_80321368(a);
        
        if (D_80339EFE == 0 || b != 4)
        {
            func_80320AE8(0, b, c);
            D_8032C6C8 = b;
        }
    }
}

void func_802491FC(s16 a)
{
    func_803210D4(a);
    D_8032C6C8 = 0xFFFF;
    D_8032C6CC = 0xFFFF;
    D_8032C6D0 = 0xFFFF;
}

void func_8024924C(s16 a)
{
    func_8031F7CC(0, a);
    D_8032C6C8 = 0xFFFF;
    D_8032C6CC = 0xFFFF;
    D_8032C6D0 = 0xFFFF;
}

void func_802492A0(u16 a)
{
    func_80320AE8(0, a, 0);
    D_8032C6C8 = a;
}

void func_802492E0(void)
{
    func_80320AE8(0, 1166, 0);
    D_8032C6CC = 1166;
}

void func_8024931C(void)
{
    if (D_8032C6CC != 0xFFFF)
    {
        func_80320CE8(D_8032C6CC);
        D_8032C6CC = 0xFFFF;
    }
}

void func_80249368(u16 a)
{
    func_80320AE8(0, a, 0);
    if (D_8032C6D0 != 0xFFFF && D_8032C6D0 != a)
        func_80320CE8(D_8032C6D0);
    D_8032C6D0 = a;
}

void func_802493D4(void)
{
    if (D_8032C6D0 != 0xFFFF)
        func_80320E20(D_8032C6D0, 600);
}

void func_80249418(void)
{
    if (D_8032C6D0 != 0xFFFF)
    {
        func_80320CE8(D_8032C6D0);
        D_8032C6D0 = 0xFFFF;
    }
}

void func_80249464(int a, void *b)
{
    SetSound(D_8032C6F0[a], b);
}

void func_802494A8(void)
{
    func_8031EED0();
}

void Thread4(UNUSED void *arg)
{
    InitAudioSystem();
    func_803202A0();
    Copy32BitTriple(&D_80339DC0, &D_80385FD0);
    osCreateMesgQueue(&D_80339DD0, &D_80339DE8, 1);
    func_80246B14(1, D_80339DF0, &D_80339DD0, 512);
    
    while (1)
    {
        OSMesg msg;

        osRecvMesg(&D_80339DD0, &msg, 1);
        if (D_8032C644 < 25)
        {
            int sp18;
            
            func_8027DEE0();
            sp18 = func_8031D924();
            if (sp18 != 0)
                func_80246BB4(sp18);
            func_8027DEE0();
        }
    }
}
