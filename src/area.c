#include <ultra64.h>

#include "sm64.h"
#include "behavior_data.h"
#include "game.h"
#include "display.h"
#include "object_list_processor.h"
#include "surface_load.h"
#include "ingame_menu.h"
#include "screen_transition.h"
#include "mario.h"
#include "mario_actions_cutscene.h"
#include "print.h"
#include "hud_print.h"
#include "audio_interface_2.h"
#include "area.h"
#include "rendering_graph_node.h"
#include "level_update.h"

extern struct Object *D_8038BD98;


extern struct SpawnInfo gPlayerSpawnInfos[1];
extern struct GraphNode *D_8033A160[0x100];
extern struct Area gAreaData[8];

extern u8 D_8033A740;
extern u8 D_8033A741;
extern u8 D_8033A742;
extern u8 D_8033A743;
extern s8 D_8033A744;
extern s8 D_8033A745;
extern s8 D_8033A746;
extern s16 D_8033A748;
extern s16 D_8033A74A;
extern s16 D_8033A74C;
extern s16 D_8033A74E;
extern s16 D_8033A750;
extern s16 D_8033A752;
extern s16 D_8033A754;
extern s16 gCurrCourseNum;
extern s16 D_8033A758;
extern s16 gCurrAreaIndex;
extern s16 D_8033A75C;
extern s16 D_8033A75E;
extern s16 D_8033A760;

struct SpawnInfo *gMarioSpawnInfo = &gPlayerSpawnInfos[0];
struct GraphNode **gLoadedGraphNodes = D_8033A160;
struct Area *gAreas = gAreaData;
struct Area *gCurrentArea = NULL;
struct CreditsEntry *gCurrCreditsEntry = NULL;
Vp *D_8032CE74 = NULL;
Vp *D_8032CE78 = NULL;
s16 D_8032CE7C = 0;
u32 D_8032CE80 = 0;
u32 D_8032CE84 = 0;
u8 D_8032CE88 = 0;
u8 D_8032CE8C = 0;
u8 D_8032CE90 = 0;
s16 gCurrSaveFileNum = 1;
s16 gCurrLevelNum = 1;

static void *D_8032CE9C[] =
{
    beh_door_warp,
    beh_collect_star,
    beh_exit_podium_warp,
    beh_warp,
    beh_warp_pipe,
    beh_fading_warp,
    beh_warps_60,
    beh_warps_64,
    beh_warps_68,
    beh_warps_6C,
    beh_warps_70,
    beh_warps_74,
    beh_warps_78,
    beh_warps_94,
    beh_warps_7C,
    beh_warps_80,
    beh_warps_88,
    beh_warps_84,
    beh_warps_8C,
    beh_warps_90,
};

static u8 D_8032CEEC[] =
{
    MARIO_SPAWN_UNKNOWN_01,
    MARIO_SPAWN_UNKNOWN_02,
    MARIO_SPAWN_UNKNOWN_03,
    MARIO_SPAWN_UNKNOWN_03,
    MARIO_SPAWN_UNKNOWN_03,
    MARIO_SPAWN_UNKNOWN_04,
    MARIO_SPAWN_UNKNOWN_10,
    MARIO_SPAWN_UNKNOWN_12,
    MARIO_SPAWN_UNKNOWN_13,
    MARIO_SPAWN_UNKNOWN_14,
    MARIO_SPAWN_UNKNOWN_15,
    MARIO_SPAWN_UNKNOWN_16,
    MARIO_SPAWN_UNKNOWN_17,
    MARIO_SPAWN_UNKNOWN_11,
    MARIO_SPAWN_UNKNOWN_20,
    MARIO_SPAWN_UNKNOWN_21,
    MARIO_SPAWN_UNKNOWN_22,
    MARIO_SPAWN_UNKNOWN_23,
    MARIO_SPAWN_UNKNOWN_24,
    MARIO_SPAWN_UNKNOWN_25,
};

static Vp D_8032CF00 =
{{
    {640, 480, 511, 0},
    {640, 480, 511, 0},
}};


void func_8027A220(Vp *a, Vp *b, u8 c, u8 d, u8 e)
{
    u16 sp6 = ((c >> 3) << 11) | ((d >> 3) << 6) | ((e >> 3) << 1) | 1;

    D_8032CE80 = (sp6 << 16) | sp6;
    D_8032CE74 = a;
    D_8032CE78 = b;
}

static void func_8027A28C(u8 a, u8 b, u8 c)
{
    u16 sp6 = ((a >> 3) << 11) | ((b >> 3) << 6) | ((c >> 3) << 1) | 1;

    D_8032CE84 = (sp6 << 16) | sp6;
    D_8032CE88 = a;
    D_8032CE8C = b;
    D_8032CE90 = c;
}

void print_intro_text(void)
{
    if ((gGlobalTimer & 0x1F) < 20)
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

u32 get_mario_spawn_type(struct Object *o)
{
    s32 i;
    void *behavior = virtual_to_segmented(0x13, o->behavior);

    for (i = 0; i < 20; i++)
    {
        if (D_8032CE9C[i] == behavior)
            return D_8032CEEC[i];
    }
    return 0;
}

struct ObjectWarpNode *area_get_warp_node(u8 id)
{
    struct ObjectWarpNode *node = NULL;

    for (node = gCurrentArea->warpNodes; node != NULL; node = node->next)
    {
        if (node->node.id == id)
            break;
    }
    return node;
}

static struct ObjectWarpNode *func_8027A478(struct Object *o)
{
    u8 sp1F = (o->oUnk188 & 0x00FF0000) >> 16;

    return area_get_warp_node(sp1F);
}

static void func_8027A4C4(void)
{
    struct ObjectWarpNode *sp24;
    struct Object *sp20 = D_8038BD98;

    do
    {
        struct Object *sp1C = sp20;

        if (sp1C->active && get_mario_spawn_type(sp1C) != 0)
        {
            sp24 = func_8027A478(sp1C);
            if (sp24 != NULL)
                sp24->object = sp1C;
        }
    }
    while ((sp20 = (struct Object *)sp20->header.gfx.node.next) != D_8038BD98);
}

void clear_areas(void)
{
    s32 i;

    gCurrentArea = NULL;
    D_8033A740 = 0;
    D_8033A743 = 0;
    gMarioSpawnInfo->areaIndex = -1;
    
    for (i = 0; i < 8; i++)
    {
        gAreaData[i].index = i;
        gAreaData[i].unk01 = 0;
        gAreaData[i].unk02 = 0;
        gAreaData[i].unk04 = NULL;
        gAreaData[i].terrainData = 0;
        gAreaData[i].surfaceRooms = 0;
        gAreaData[i].unk10 = 0;
        gAreaData[i].warpNodes = NULL;
        gAreaData[i].paintingWarpNodes = NULL;
        gAreaData[i].instantWarps = NULL;
        gAreaData[i].objectSpawnInfos = NULL;
        gAreaData[i].unk24 = 0;
        gAreaData[i].unk28 = 0;
        gAreaData[i].whirlpools[0] = NULL;
        gAreaData[i].whirlpools[1] = NULL;
        gAreaData[i].unk34[0] = 255;
        gAreaData[i].unk35 = 255;
        gAreaData[i].unk36 = 0;
        gAreaData[i].unk38 = 0;
    }
}

void func_8027A7C4(void)
{
    s32 i;

    if (gCurrentArea != NULL)
    {
        func_8037C360(gCurrentArea->unk04, 2);
        gCurrentArea = NULL;
        D_8033A740 = 0;
    }

    for (i = 0; i < 8; i++)
    {
        if (gAreaData[i].unk04 != NULL)
        {
            func_8037C360(gAreaData[i].unk04, 4);
            gAreaData[i].unk04 = NULL;
        }
    }
}

void load_area(s32 index)
{
    if (gCurrentArea == NULL && gAreaData[index].unk04 != NULL)
    {
        gCurrentArea = &gAreaData[index];
        gCurrAreaIndex = gCurrentArea->index;
        
        if (gCurrentArea->terrainData != NULL)
        {
            load_area_terrain(
                index,
                gCurrentArea->terrainData,
                gCurrentArea->surfaceRooms,
                gCurrentArea->unk10);
        }
        
        if (gCurrentArea->objectSpawnInfos != NULL)
            spawn_objects_from_info(0, gCurrentArea->objectSpawnInfos);
        
        func_8027A4C4();
        func_8037C360(gCurrentArea->unk04, 3);
    }
}

void func_8027A998(void)
{
    if (gCurrentArea != NULL)
    {
        func_8029C75C(0, gCurrentArea->index);
        func_8037C360(gCurrentArea->unk04, 2);

        gCurrentArea->unk01 = 0;
        gCurrentArea = NULL;
        D_8033A740 = 0;
    }
}

void load_mario_area(void)
{
    func_80320890();
    load_area(gMarioSpawnInfo->areaIndex);
    
    if (gCurrentArea->index == gMarioSpawnInfo->areaIndex)
    {
        gCurrentArea->unk01 |= 0x01;
        spawn_objects_from_info(0, gMarioSpawnInfo);
    }
}

void func_8027AA88(void)
{
    if (gCurrentArea != NULL && (gCurrentArea->unk01 & 0x01))
    {
        func_8029C75C(0, gMarioSpawnInfo->unk0D);

        gCurrentArea->unk01 &= ~0x01;
        if (gCurrentArea->unk01 == 0)
            func_8027A998();
    }
}

void change_area(s32 index)
{
    s32 areaFlags = gCurrentArea->unk01;

    if (gCurrAreaIndex != index)
    {
        func_8027A998();
        load_area(index);
        
        gCurrentArea->unk01 = areaFlags;
        gMarioObject->oUnkE0 = 0;
    }

    if (areaFlags & 0x01)
    {
        gMarioObject->header.gfx.unk18 = index, gMarioSpawnInfo->areaIndex = index;
    }
}

void area_update_objects(void)
{
    gAreaUpdateCounter++;
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
        else
        {
            if (a >= 14)
                D_8033A748 = 16;
            else
                D_8033A748 = 0;
            D_8033A74A = 320;
        }
    }
}

void func_8027ADAC(s16 a, s16 b, u8 c, u8 d, u8 e, s16 f)
{
    D_8032CE7C = f;
    func_8027ABF0(a, b, c, d, e);
}

void render_game(void)
{
    if (gCurrentArea != NULL && D_8033A743 == 0)
    {
        func_8027DB80(gCurrentArea->unk04, D_8032CE74, D_8032CE78, D_8032CE80);
        
        gSPViewport(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(&D_8032CF00));
        
        gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, 8, 320, 232);
        render_hud();
        
        gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, 0, 320, 240);
        func_802D61A8();
        do_cutscene_handler();
        func_80256CA8();
        gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, 8, 320, 232);
        D_8033A75E = func_802DCD98();
        
        if (D_8033A75E != 0)
            D_8033A760 = D_8033A75E;
        
        if (D_8032CE78 != NULL)
            func_8024798C(D_8032CE78);
        else
            gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, 8, 320, 232);
        
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
            }
            else
            {
                D_8032CE7C--;
            }
        }
    }
    else
    {
        func_802D61A8();
        if (D_8032CE78 != 0)
            DisplayInit(D_8032CE78, D_8032CE84);
        else
            ClearFrameBuffer(D_8032CE84);
    }

    D_8032CE74 = NULL;
    D_8032CE78 = 0;
}
