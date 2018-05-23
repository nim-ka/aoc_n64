#include <ultra64.h>

#include "sm64.h"
#include "behavior_script.h"
#include "level_functions.h"
#include "audio_interface_2.h"
#include "print.h"
#include "surface_collision.h"
#include "mario.h"
#include "game.h"
#include "main.h"

extern int D_8033BEF0;
extern int D_8033BEF4;
extern int D_8033BEFC;
extern s16 D_8033BF04;
extern s16 D_8033BF06;
extern s16 D_8033BF08;
extern s16 D_8033BF10[][8];
extern s16 D_8033C010[][8];

extern s16 D_8035FEE2;
extern s16 D_8035FEE4;
extern s16 D_8035FEE8;
extern s16 D_8035FF20[];
extern s16 D_8035FF30[];

extern u8 beh_koopa_shell[];
extern u8 beh_jumping_box[];
extern u8 beh_koopa_shell_underwater[];

const char *D_8032FEE0[] =
{
    "  a0 %d",
    "  a1 %d",
    "  a2 %d",
    "  a3 %d",
    "  a4 %d",
    "  a5 %d",
    "  a6 %d",
    "  a7 %d",
    "A"
};

const char *D_8032FF04[] =
{
    "  b0 %d",
    "  b1 %d",
    "  b2 %d",
    "  b3 %d",
    "  b4 %d",
    "  b5 %d",
    "  b6 %d",
    "  b7 %d",
    "B"
};

int D_8032FF28 = 0;
int D_8032FF2C = 0;
s8 D_8032FF30 = 0;
s8 D_8032FF34 = 0;
s8 D_8032FF38 = 0;
s8 D_8032FF3C = 0;
s8 D_8032FF40 = 0;
s8 D_8032FF44 = 0;
s16 D_8032FF48[] = {8, 2, 4, 1, -1, 0, 0, 0, 0, 0, 0, 0};

void Stub802C9890(void)
{}

void Stub802C98A0(void)
{}

void Stub802C98B0(void)
{}

void Stub802C98C0(void)
{}

u64 func_802C98D0(void)
{
    u64 wtf = 0;

    return wtf;
}

u64 func_802C9900(UNUSED u64 arg0)
{
    u64 wtf = 0;

    return wtf;
}

void func_802C9938(s16 *unkArray, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5)
{
    unkArray[0] = 0;
    unkArray[1] = arg1;
    unkArray[2] = arg2;
    unkArray[3] = arg3;
    unkArray[4] = arg4;
    unkArray[5] = arg5;
}

void func_802C9980(s16 *unkArray, const char *str, int arg2)
{
    if(!unkArray[0])
    {
        if((unkArray[2] < unkArray[3]) || (unkArray[4] < unkArray[2]))
        {
            print_text(unkArray[1], unkArray[2], "DPRINT OVER");
            unkArray[0] += 1;
        }
        else
        {
            print_text_fmt_int(unkArray[1], unkArray[2], str, arg2);
            unkArray[2] += unkArray[5];
        }
    }
}

void func_802C9A3C(int arg0, int arg1)
{
    s16 *otherArr = D_8035FF20;

    otherArr[1] += arg0;
    otherArr[2] = arg1 * otherArr[5] + otherArr[2];
}

void func_802C9A88(const char *str, int arg1)
{
    if(D_8033BEF0 & 0x00000001)
        func_802C9980(D_8035FF30, str, arg1);
}

void func_802C9AD8(const char *str, int arg1)
{
    if((D_8033BEF0 & 0x00000001) && D_8032FF34 == 0)
        func_802C9980(D_8035FF20, str, arg1);
}

void AnotherPrint(const char *str, int arg1)
{
    if(D_8032FF38)
        return;

    if(D_8033BEF0 & 0x00000001)
        func_802C9980(D_8035FF20, str, arg1);
}

void func_802C9BA0(const char *str, int arg1)
{
    if(D_8033BEF0 & 0x00000001)
        func_802C9980(D_8035FF20, str, arg1);
}

void func_802C9BF0(void)
{
    struct Surface *pfloor;
    f32 sp28;
    f32 sp24;
    int sp20;
    int sp1C;

    sp1C = gCurrentObject->angle[1] / 182.044000;
    sp20  = ((int)gCurrentObject->pos[0] + 0x2000) / 1024
          + ((int)gCurrentObject->pos[2] + 0x2000) / 1024 * 16;

    sp28 = func_80381900(gCurrentObject->pos[0], gCurrentObject->pos[1], gCurrentObject->pos[2], &pfloor);
    sp24 = func_80381BA0(gCurrentObject->pos[0], gCurrentObject->pos[2]);

    func_802C9BA0("mapinfo", 0);
    AnotherPrint("area %x", sp20);
    AnotherPrint("wx   %d", gCurrentObject->pos[0]);
    AnotherPrint("wy\t  %d", gCurrentObject->pos[1]); //! Fat finger: programmer hit tab instead of space. Japanese
                                                      // thumb shift keyboards had the tab key next to the spacebar,
                                                      // so this was likely the reason.
    AnotherPrint("wz   %d", gCurrentObject->pos[2]);
    AnotherPrint("bgY  %d", sp28);
    AnotherPrint("angY %d", sp1C);

    if(pfloor) // not null
    {
        AnotherPrint("bgcode   %d", pfloor->type);
        AnotherPrint("bgstatus %d", pfloor->flags);
        AnotherPrint("bgarea   %d", pfloor->unk05);
    }

    if(gCurrentObject->pos[1] < sp24)
        AnotherPrint("water %d", sp24);
}

void func_802C9E08(void)
{
    func_802C9BA0("checkinfo", 0);
}

void func_802C9E38(void)
{
    func_80381F08(gMarioObject->pos[0], gMarioObject->pos[2]);
}

void func_802C9E6C(void)
{
    func_802C9BA0("stageinfo", 0);
    func_802C9BA0("stage param %d", D_8035FEE8);
}

void func_802C9EB0(const char **strArr)
{
    int i;

    if(D_8032FF3C == 0)
    {
        D_8032FF3C += 1;
        for(i = 0; i < 8; i++)
        {
            AnotherPrint(strArr[i], D_8033BF10[D_8032FF34][i]);
        }
        func_802C9A3C(0, -8 - -D_8032FF40);
        AnotherPrint(strArr[8], 0);
        func_802C9A3C(0, 7 - D_8032FF40);
    }
}

void func_802C9F8C(void)
{
    func_802C9BA0("effectinfo", 0);
    func_802C9EB0(D_8032FEE0);
}

void func_802C9FC8(void)
{
    func_802C9BA0("enemyinfo", 0);
    func_802C9EB0(D_8032FF04);
}

void func_802CA004(void)
{
    int dPadMask = gPlayer1Controller->buttonDown & (U_JPAD | D_JPAD | L_JPAD | R_JPAD);

    if(!dPadMask)
    {
        D_8032FF2C = 0;
        D_8032FF28 = 0;
    }
    else
    {
        if(D_8032FF2C == 0)
        {
            D_8032FF28 = dPadMask;
        }
        else if(D_8032FF2C == 6)
        {
            D_8032FF28 = dPadMask;
        }
        else
        {
            D_8032FF28 = 0;
        }
        D_8032FF2C += 1;
        if(D_8032FF2C >= 8)
        {
            D_8032FF2C = 6;
        }
    }
}

void func_802CA0CC(void)
{
    if(!D_8032FF30)
    {
        D_8032FF30 += 1;

        if(!gDebugLevelSelect)
            D_8033BEF0 = 0;
        else
            D_8033BEF0 = 2;

        D_8033BF04 = 0;
        D_8033BF06 = 0;
        D_8033BF08 = 0;
    }
}

void func_802CA140(void)
{
    D_8033BEF4 = 0;
    D_8033BEFC = 0;
    gUpdatedObjectCount = 0;
    D_8032FF3C = 0;
    D_8035FEE2 = 0;
    D_8035FEE4 = 0;

    func_802C9938(D_8035FF20, 20, 185, 40, 200, -15);
    func_802C9938(D_8035FF30, 180, 30, 0,  150,  15);
    func_802CA004();
}

void Unknown802CA1E8(void)
{
    s16 *sp4;
    s16 sp2;
    
    sp4 = D_8032FF48;

    if(!(gPlayer1Controller->buttonDown & L_TRIG))
        D_8032FF44 = 0;
    else
    {
        if((s16)(sp2 = (gPlayer1Controller->buttonPressed & 0xF)))
        {
            if(sp4[D_8032FF44] == sp2)
            {
                D_8032FF44 += 1;
                if(sp4[D_8032FF44] == -1)
                {
                    if(D_8033BEF0 == 255)
                    {
                        D_8033BEF0 = 2;
                    }
                    else
                    {
                        D_8033BEF0 = 255;
                    }
                }
            }
            else
            {
                D_8032FF44 = 0;
            }
        }
    }
}

void Unknown802CA2E8(void)
{
    if(D_8033BEF0 & 0x00000001)
    {
        if((gPlayer1Controller->buttonPressed &  L_JPAD) 
        && (gPlayer1Controller->buttonDown    & (L_TRIG | R_TRIG)))
        {
            D_8032FF34 += 1;
        }
        if((gPlayer1Controller->buttonPressed & R_JPAD)
        && (gPlayer1Controller->buttonDown    & (L_TRIG | R_TRIG)))
        {
            D_8032FF34 -= 1;
        }
        if(D_8032FF34 >= 6)
        {
            D_8032FF34 = 0;
        }
        if(D_8032FF34 < 0)
        {
            D_8032FF34 = 5;
        }
    }
}

void Unknown802CA3BC(void)
{
    int sp4;

    if(gPlayer1Controller->buttonPressed & Z_TRIG)
    {
        D_8032FF38 ^= 1;
    }
    if(!(gPlayer1Controller->buttonDown & (L_TRIG | R_TRIG)) && D_8032FF38 == 0)
    {
        sp4 = 1;
        if(gPlayer1Controller->buttonDown & B_BUTTON)
            sp4 = 100;

        if(D_8032FF28 & 0x800)
        {
            D_8032FF40 -= 1;
            if(D_8032FF40 < 0)
                D_8032FF40 = 0;
        }

        if(D_8032FF28 & 0x400)
        {
            D_8032FF40 += 1;
            if(D_8032FF40 >= 8)
                D_8032FF40 = 7;
        }

        if(D_8032FF28 & 0x200)
        {
            if(gPlayer1Controller->buttonDown & A_BUTTON)
                D_8033BF10[D_8032FF34][D_8032FF40] = D_8033C010[D_8032FF34][D_8032FF40];
            else
                D_8033BF10[D_8032FF34][D_8032FF40] = D_8033BF10[D_8032FF34][D_8032FF40] - sp4;
        }

        if(D_8032FF28 & 0x100)
        {
            D_8033BF10[D_8032FF34][D_8032FF40] = D_8033BF10[D_8032FF34][D_8032FF40] + sp4;
        }
    }
}

void func_802CA5D0(void)
{}

void func_802CA5E0(void)
{
    if(gMarioObject != NULL)
    {
        switch(D_8032FF34)
        {
            case 1:
                func_802C9E38();
                break;
            case 4:
                func_802C9F8C();
                break;
            case 5:
                func_802C9FC8();
                break;
            default:
                break;
        }
    }

    AnotherPrint("obj  %d", gUpdatedObjectCount);

    if(D_8033BEF4)
        func_802C9A88("NULLBG %d", D_8033BEF4);

    if(D_8033BEFC)
        func_802C9A88("WALL   %d", D_8033BEFC);
}

void BehMarioLoop1(void)
{
    switch(D_8032FF34)
    {
        case 0:
            break;
        case 1:
            func_802C9E08();
            break;
        case 2:
            func_802C9BF0();
            break;
        case 3:
            func_802C9E6C();
            break;
        default:
            break;
    }
}

void BehMarioLoop3(void)
{
    UNUSED int unused;

    if(D_8032FF34 == 3 && D_8033BF10[5][7] == 1)
    {
        if(gPlayer1Controller->buttonPressed & R_JPAD)
            SpawnObjAdv(0, 0, 100, 200, gCurrentObject, 190, beh_koopa_shell);
        if(gPlayer1Controller->buttonPressed & L_JPAD)
            SpawnObjAdv(0, 0, 100, 200, gCurrentObject, 130, beh_jumping_box);
        if(gPlayer1Controller->buttonPressed & D_JPAD)
            SpawnObjAdv(0, 0, 100, 200, gCurrentObject, 190, beh_koopa_shell_underwater);
    }
}

void Unknown802CA8B4(void)
{
    if(gCurrentObject->unkEC & 0x00000001)
        func_802C9AD8("BOUND   %x", gCurrentObject->unkEC);
    if(gCurrentObject->unkEC & 0x00000002)
        func_802C9AD8("TOUCH   %x", gCurrentObject->unkEC);
    if(gCurrentObject->unkEC & 0x00000004)
        func_802C9AD8("TAKEOFF %x", gCurrentObject->unkEC);
    if(gCurrentObject->unkEC & 0x00000008)
        func_802C9AD8("DIVE    %x", gCurrentObject->unkEC);
    if(gCurrentObject->unkEC & 0x00000010)
        func_802C9AD8("S WATER %x", gCurrentObject->unkEC);
    if(gCurrentObject->unkEC & 0x00000020)
        func_802C9AD8("U WATER %x", gCurrentObject->unkEC);
    if(gCurrentObject->unkEC & 0x00000040)
        func_802C9AD8("B WATER %x", gCurrentObject->unkEC);
    if(gCurrentObject->unkEC & 0x00000080)
        func_802C9AD8("SKY     %x", gCurrentObject->unkEC);
    if(gCurrentObject->unkEC & 0x00000100)
        func_802C9AD8("OUT SCOPE %x", gCurrentObject->unkEC);
}

// unused
void Unknown802CAA84(s16 *unkArray)
{
    unkArray[4] = D_8033BF10[5][1];
    unkArray[5] = D_8033BF10[5][2];
    unkArray[6] = D_8033BF10[5][3];
    unkArray[7] = D_8033BF10[5][4];
}
