#include <ultra64.h>

#include "sm64.h"
#include "game.h"
#include "display.h"
#include "object_list_processor.h"
#include "surface_collision.h"
#include "surface_load.h"
#include "ingame_menu.h"
#include "screen_transition.h"
#include "mario.h"
#include "mario_actions_cutscene.h"
#include "print.h"
#include "hud_print.h"
#include "audio_interface_2.h"
#include "rendering.h"

extern u8 D_8033A741;
extern u8 D_8033A742;
extern s8 D_8033A744;
extern s8 D_8033A745;
extern s8 D_8033A746;
extern s16 D_8033A74C;
extern s16 D_8033A748;
extern s16 D_8033A74A;
extern s16 D_8033A74E;
extern s16 D_8033A750;
extern s16 D_8033A752;
extern s16 D_8033A754;

extern void *D_8033A160;

struct SpawnInfo *D_8032CE60 = &gPlayerSpawnInfos[0];
void **gLoadedGeoLayouts = &D_8033A160;
struct Area *D_8032CE68 = D_8033A560;
struct Area *D_8032CE6C = NULL;

extern void *D_8032CE9C[];
extern u8 D_8032CEEC[];

void func_8027A220(Vp *a, Vp *b, u8 c, u8 d, u8 e)
{
    u16 sp6 = ((c >> 3) << 11) | ((d >> 3) << 6) | ((e >> 3) << 1) | 1;

    D_8032CE80 = (sp6 << 16) | sp6;
    D_8032CE74 = a;
    D_8032CE78 = b;
}

void func_8027A28C(u8 a, u8 b, u8 c)
{
    u16 sp6 = ((a >> 3) << 11) | ((b >> 3) << 6) | ((c >> 3) << 1) | 1;

    D_8032CE84 = (sp6 << 16) | sp6;
    D_8032CE88 = a;
    D_8032CE8C = b;
    D_8032CE90 = c;
}

void IntroPrintText(void)
{
    if ((D_8032C694 & 0x1F) < 20)
    {
        if (gControllerBits == 0)
        {
            print_text_centered(160, 20, "NO CONTROLLER");
        }
        else
        {
            print_text_centered(60, 38, "PRESS");
            print_text_centered(60, 20, "START");
        }
    }
}

u32 func_8027A38C(struct Object *o)
{
    int sp1C;
    void *sp18 = virtual_to_segmented(0x13, o->behavior);

    for (sp1C = 0; sp1C < 20; sp1C++)
    {
        if (D_8032CE9C[sp1C] == sp18)
            return D_8032CEEC[sp1C];
    }
    return 0;
}

struct ObjectWarpNode *func_8027A418(u8 a)
{
    struct ObjectWarpNode *sp4 = NULL;

    for (sp4 = D_8032CE6C->unk14; sp4 != NULL; sp4 = sp4->unk8)
    {
        if (sp4->node.id == a)
            break;
    }
    return sp4;
}

struct ObjectWarpNode *func_8027A478(struct Object *o)
{
    u8 sp1F = (o->unk188 & 0xFF0000) >> 16;

    return func_8027A418(sp1F);
}

void func_8027A4C4(void)
{
    struct ObjectWarpNode *sp24;
    struct Object *sp20 = D_8038BD98;

    do
    {
        struct Object *sp1C = sp20;

        if (sp1C->active && func_8027A38C(sp1C) != 0)
        {
            sp24 = func_8027A478(sp1C);
            if (sp24 != NULL)
                sp24->object = sp1C;
        }
    } while ((sp20 = sp20->gfx.unk8) != D_8038BD98);
}

void func_8027A554(void)
{
    int sp4;

    D_8032CE6C = NULL;
    D_8033A740 = 0;
    D_8033A743 = 0;
    D_8032CE60->areaIndex = -1;
    for (sp4 = 0; sp4 < 8; sp4++)
    {
        D_8033A560[sp4].index = sp4;
        D_8033A560[sp4].unk01 = 0;
        D_8033A560[sp4].unk02 = 0;
        D_8033A560[sp4].unk04 = 0;
        D_8033A560[sp4].unk08 = 0;
        D_8033A560[sp4].unk0C = 0;
        D_8033A560[sp4].unk10 = 0;
        D_8033A560[sp4].unk14 = 0;
        D_8033A560[sp4].paintingWarpNodes = NULL;
        D_8033A560[sp4].unk1C = 0;
        D_8033A560[sp4].unk20 = 0;
        D_8033A560[sp4].unk24 = 0;
        D_8033A560[sp4].unk28 = 0;
        D_8033A560[sp4].whirlpools[0] = NULL;
        D_8033A560[sp4].whirlpools[1] = NULL;
        D_8033A560[sp4].unk34[0] = 255;
        D_8033A560[sp4].unk35 = 255;
        D_8033A560[sp4].unk36 = 0;
        D_8033A560[sp4].unk38 = 0;
    }
}

void func_8027A7C4(void)
{
    int sp1C;

    if (D_8032CE6C != NULL)
    {
        func_8037C360(D_8032CE6C->unk04, 2);
        D_8032CE6C = NULL;
        D_8033A740 = 0;
    }
    for (sp1C = 0; sp1C < 8; sp1C++)
    {
        if (D_8033A560[sp1C].unk04 != 0)
        {
            func_8037C360(D_8033A560[sp1C].unk04, 4);
            D_8033A560[sp1C].unk04 = 0;
        }
    }
}

void func_8027A894(int a)
{
    if (D_8032CE6C == NULL && D_8033A560[a].unk04 != 0)
    {
        D_8032CE6C = &D_8033A560[a];
        D_8033A75A = D_8032CE6C->index;
        if (D_8032CE6C->unk08 != 0)
            load_area_terrain(a, D_8032CE6C->unk08, (s8 *) D_8032CE6C->unk0C, D_8032CE6C->unk10);
        if (D_8032CE6C->unk20 != 0)
            spawn_objects_from_info(0, D_8032CE6C->unk20);
        func_8027A4C4();
        func_8037C360(D_8032CE6C->unk04, 3);
    }
}

void func_8027A998(void)
{
    if (D_8032CE6C != NULL)
    {
        func_8029C75C(0, D_8032CE6C->index);
        func_8037C360(D_8032CE6C->unk04, 2);
        D_8032CE6C->unk01 = 0;
        D_8032CE6C = NULL;
        D_8033A740 = 0;
    }
}

void func_8027AA0C(void)
{
    func_80320890();
    func_8027A894(D_8032CE60->areaIndex);
    if (D_8032CE6C->index == D_8032CE60->areaIndex)
    {
        D_8032CE6C->unk01 |= 1;
        spawn_objects_from_info(0, D_8032CE60);
    }
}

void func_8027AA88(void)
{
    if (D_8032CE6C != NULL && (D_8032CE6C->unk01 & 1))
    {
        func_8029C75C(0, D_8032CE60->unk0D);
        D_8032CE6C->unk01 &= ~1;
        if (D_8032CE6C->unk01 == 0)
            func_8027A998();
    }
}

void func_8027AB10(int a)
{
    int sp1C = D_8032CE6C->unk01;

    if (D_8033A75A != a)
    {
        func_8027A998();
        func_8027A894(a);
        D_8032CE6C->unk01 = sp1C;
        gMarioObject->unkE0 = 0;
    }
    if (sp1C & 1)
    {
        gMarioObject->gfx.unk18 = a, D_8032CE60->areaIndex = a;
    }
}

void func_8027ABB4(void)
{
    D_8032CFA8++;
    update_objects(0);
}

void func_8027ABF0(s16 a, s16 b, u8 c, u8 d, u8 e)
{
    D_8033A740 = 1;
    D_8033A741 = a;
    D_8033A742 = b;
    D_8033A743 = 0;

    if (a & 1)
    {
        func_8027A28C(c, d, e);
    }
    else
    {
        c = D_8032CE88, d = D_8032CE8C, e = D_8032CE90;
    }

    if (a < 8)
    {
        D_8033A744 = c;
        D_8033A745 = d;
        D_8033A746 = e;
    }
    else
    {
        D_8033A744 = c;
        D_8033A745 = d;
        D_8033A746 = e;
        D_8033A74C = 160;
        D_8033A74E = 120;
        D_8033A750 = 160;
        D_8033A752 = 120;
        D_8033A754 = 0;
        if (a & 1)
        {
            D_8033A748 = 320;
            if (a >= 15)
                D_8033A74A = 16;
            else
                D_8033A74A = 0;
        }
        //L8027AD60
        else
        {
            if (a >= 14)
                D_8033A748 = 16;
            else
                D_8033A748 = 0;
            D_8033A74A = 320;
        }
    }
    //L8027AD94
}

void func_8027ADAC(s16 a, s16 b, u8 c, u8 d, u8 e, s16 f)
{
    D_8032CE7C = f;
    func_8027ABF0(a, b, c, d, e);
}

void func_8027AE04(void)
{
    if (D_8032CE6C != NULL && D_8033A743 == 0)
    {
        func_8027DB80(D_8032CE6C->unk04, D_8032CE74, D_8032CE78, D_8032CE80);
        {
            Gfx *g = gDisplayListHead++;
            g->words.w0 = 0x03800010;
            g->words.w1 = VIRTUAL_TO_PHYSICAL(D_8032CF00);
        }
        gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, 8, 320, 232);
        render_hud();
        gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, 0, 320, 240);
        func_802D61A8();
        func_802D9D5C();
        func_80256CA8();
        gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, 8, 320, 232);
        D_8033A75E = func_802DCD98();
        if (D_8033A75E != 0)
            D_8033A760 = D_8033A75E;
        //L8027AF90
        if (D_8032CE78 != NULL)
            func_8024798C(D_8032CE78);
        else
            gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, 8, 320, 232);
        //L8027AFEC
        if (D_8033A740 != 0)
        {
            if (D_8032CE7C == 0)
            {
                D_8033A740 = !func_802CC108(0, D_8033A741, D_8033A742, (u8 *)&D_8033A740 + 4);
                if (D_8033A740 == 0)
                {
                    if (D_8033A741 & 1)
                        D_8033A743 = 1;
                    else
                        func_8027A28C(0, 0, 0);
                }
                //L8027B080
            }
            //L8027B088
            else
            {
                D_8032CE7C--;
            }
        }
        //L8027B09C
    }
    //L8027B0A4
    else
    {
        func_802D61A8();
        if (D_8032CE78 != 0)
            DisplayInit(D_8032CE78, D_8032CE84);
        else
            ClearFrameBuffer(D_8032CE84);
    }
    //L8027B0E4
    D_8032CE74 = NULL;
    D_8032CE78 = 0;
}
