#include <ultra64.h>

#include "sm64.h"
#include "level_update.h"
#include "math_util.h"
#include "save_file.h"


#define PLAY_MODE_NORMAL        0
#define PLAY_MODE_PAUSED        2
#define PLAY_MODE_CHANGE_AREA   3
#define PLAY_MODE_CHANGE_LEVEL  4
#define PLAY_MODE_FRAME_ADVANCE 5

#define WARP_TYPE_NOT_WARPING  0
#define WARP_TYPE_CHANGE_LEVEL 1
#define WARP_TYPE_CHANGE_AREA  2
#define WARP_TYPE_SAME_AREA    3

#define WARP_NODE_F0            0xF0
#define WARP_NODE_DEATH         0xF1
#define WARP_NODE_F2            0xF2
#define WARP_NODE_WARP_FLOOR    0xF3
#define WARP_NODE_CREDITS_START 0xF8
#define WARP_NODE_CREDITS_NEXT  0xF9
#define WARP_NODE_CREDITS_END   0xFA

#define WARP_NODE_CREDITS_MIN 0xF8


static const char *creditsGameDirector[]        = { "1GAME DIRECTOR", "SHIGERU MIYAMOTO" };
static const char *creditsAssistantDirectors[]  = { "2ASSISTANT DIRECTORS", "YOSHIAKI KOIZUMI", "TAKASHI TEZUKA" };
static const char *creditsSystemProgrammers[]   = { "2SYSTEM PROGRAMMERS", "YASUNARI NISHIDA", "YOSHINORI TANIMOTO" };
static const char *creditsProgrammers[]         = { "3PROGRAMMERS", "HAJIME YAJIMA", "DAIKI IWAMOTO", "TOSHIO IWAWAKI" };
static const char *creditsCameraProgrammer[]    = { "1CAMERA PROGRAMMER", "TAKUMI KAWAGOE" };
static const char *creditsMarioFaceProgrammer[] = { "1MARIO FACE PROGRAMMER", "GILES GODDARD" };
static const char *creditsCourseDirectors[]     = { "2COURSE DIRECTORS", "YOICHI YAMADA", "YASUHISA YAMAMURA" };
static const char *creditsCourseDesigners1[]    = { "2COURSE DESIGNERS", "KENTA USUI", "NAOKI MORI" };
static const char *creditsCourseDesigners2[]    = { "3COURSE DESIGNERS", "YOSHIKI HARUHANA", "MAKOTO MIYANAGA", "KATSUHIKO KANNO" };
static const char *creditsSoundComposer[]       = { "1SOUND COMPOSER", "KOJI KONDO" };
static const char *creditsSoundEffects[]        = { "1SOUND EFFECTS", "YOJI INAGAKI" };
static const char *creditsSoundProgrammer[]     = { "1SOUND PROGRAMMER", "HIDEAKI SHIMIZU" };
static const char *credits3dAnimators[]         = { "23D ANIMATORS", "YOSHIAKI KOIZUMI", "SATORU TAKIZAWA" };
static const char *creditsCgDesigner[]          = { "1CG DESIGNER", "MASANAO ARIMOTO" };
static const char *creditsTechnicalSupport1[]   = { "3TECHNICAL SUPPORT", "TAKAO SAWANO", "HIROHITO YOSHIMOTO", "HIROTO YADA" };
static const char *creditsTechnicalSupport2[]   = { "1TECHNICAL SUPPORT", "SGI. 64PROJECT STAFF" };
static const char *creditsProgressManagement[]  = { "2PROGRESS MANAGEMENT", "KIMIYOSHI FUKUI", "KEIZO KATO" };
static const char *creditsSpecialThanksTo[]     = { "3SPECIAL THANKS TO", "JYOHO KAIHATUBU", "ALL NINTENDO", "MARIO CLUB STAFF" };
static const char *creditsProducer[]            = { "1PRODUCER", "SHIGERU MIYAMOTO" };
static const char *creditsExecutiveProducer[]   = { "1EXECUTIVE PRODUCER", "HIROSHI YAMAUCHI" };

static struct CreditsEntry sCreditsSequence[] =
{
    { LEVEL_CASTLE_GROUNDS, 1,    1, -128, {    0,  8000,     0}, NULL                       },
    { LEVEL_BOB,            1,    1,  117, {  713,  3918, -3889}, creditsGameDirector        },
    { LEVEL_WF,             1,   50,   46, {  347,  5376,   326}, creditsAssistantDirectors  },
    { LEVEL_JRB,            1,   18,   22, { 3800, -4840,  2727}, creditsSystemProgrammers   },
    { LEVEL_CCM,            2,   34,   25, {-5464,  6656, -6575}, creditsProgrammers         },
    { LEVEL_BBH,            1,    1,   60, {  257,  1922,  2580}, creditsCameraProgrammer    },
    { LEVEL_HMC,            1,  -15,  123, {-6469,  1616, -6054}, creditsMarioFaceProgrammer },
    { LEVEL_THI,            3,   17,  -32, {  508,  1024,  1942}, creditsCourseDirectors     },
    { LEVEL_LLL,            2,   33,  124, {  -73,    82, -1467}, creditsCourseDesigners1    },
    { LEVEL_SSL,            1,   65,   98, {-5906,  1024, -2576}, creditsCourseDesigners2    },
    { LEVEL_DDD,            1,   50,   47, {-4884, -4607,  -272}, creditsSoundComposer       },
    { LEVEL_SL,             1,   17,  -34, { 1925,  3328,   563}, creditsSoundEffects        },
    { LEVEL_WDW,            1,   33,  105, { -537,  1850,  1818}, creditsSoundProgrammer     },
    { LEVEL_TTM,            1,    2,  -33, { 2613,   313,  1074}, credits3dAnimators         },
    { LEVEL_THI,            1,   51,   54, {-2609,   512,   856}, creditsCgDesigner          },
    { LEVEL_TTC,            1,   17,  -72, {-1304,   -71,  -967}, creditsTechnicalSupport1   },
    { LEVEL_RR,             1,   33,   64, { 1565,  1024,  -148}, creditsTechnicalSupport2   },
    { LEVEL_SA,             1,    1,   24, {-1050, -1330, -1559}, creditsProgressManagement  },
    { LEVEL_COTMC,          1,   49,  -16, { -254,   415, -6045}, creditsSpecialThanksTo     },
    { LEVEL_DDD,            2, -111,  -64, { 3948,  1185,  -104}, creditsProducer            },
    { LEVEL_CCM,            1,   33,   31, { 3169, -4607,  5240}, creditsExecutiveProducer   },
    { LEVEL_CASTLE_GROUNDS, 1,    1, -128, {    0,   906, -1200}, NULL                       },
    { 0,                    0,    1,    0, {    0,     0,     0}, NULL                       },
};

struct MarioState *gMarioState = &gMarioStates[0];

static u8 unused1[4] = {0};

static s8 D_8032C9E0 = 0;

static u8 unused2[8];

static s16 sCurrPlayMode;
static u16 D_80339ECA;

static s16 sTransitionTimer;
static void (*sTransitionUpdate)(s16 *);

static u8 unused3[4];

static u8 sCurrWarpType;
static u8 sDestLevelNum;
static u8 sDestAreaIndex;
static u8 sDestWarpNodeId;
static u32 sWarpArg;
static s16 D_80339EE0;

static s16 sDelayedWarpOp;
static s16 sDelayedWarpTimer;
static s16 sSourceWarpNodeId;
static s32 sDelayedWarpArg;

static u8 unused4[2];

static s8 sTimerRunning;
s16 gDisplayedLives;
s16 gDisplayedCoins;
s16 gDisplayedStars;
s16 gDisplayedHealthWedges;
s16 gDisplayedKeys;
s16 gHudDisplayFlags;
u16 gTimerValueInFrames;
s8 D_80339EFE;


static void basic_update(s16 *arg);


u16 level_control_timer(u32 timerOp)
{
    switch (timerOp)
    {
    case TIMER_CONTROL_SHOW:
        gHudDisplayFlags |= 0x0040;
        sTimerRunning = FALSE;
        gTimerValueInFrames = 0;
        break;

    case TIMER_CONTROL_START:
        sTimerRunning = TRUE;
        break;

    case TIMER_CONTROL_STOP:
        sTimerRunning = FALSE;
        break;

    case TIMER_CONTROL_HIDE:
        gHudDisplayFlags &= ~0x0040;
        sTimerRunning = FALSE;
        gTimerValueInFrames = 0;
        break;
    }

    return gTimerValueInFrames;
}

static u32 pressed_paused(void)
{
    u32 val4 = func_802D7F74() >= 0;
    u32 intangible = (gMarioState->action & ACT_FLAG_INTANGIBLE) != 0;

    if (!intangible && !val4 && !D_8033A740 && sDelayedWarpOp == WARP_OP_NONE &&
        (gPlayer1Controller->buttonPressed & START_BUTTON))
    {
        return TRUE;
    }

    return FALSE;
}

static void set_play_mode(s16 playMode)
{
    sCurrPlayMode = playMode;
    D_80339ECA = 0;
}

static void func_8024975C(s32 arg)
{
    sCurrPlayMode = PLAY_MODE_CHANGE_LEVEL;
    D_80339ECA = 0;
    D_80339EE0 = arg;
}

void func_80249788(u32 arg, u32 color)
{
    if (color != 0)
        color = 0xFF;

    func_802491FC(190);
    func_8027ABF0(0x01, 0x10, color, color, color);
    level_set_transition(30, NULL);

    func_8024975C(arg);
}

static void nop_802497FC(void)
{
}

void func_8024980C(u32 arg)
{
    s32 gotAchievement;
    u32 val8 = D_8032CE6C->unk34[arg];

    switch (val8)
    {
    case 0x81:
        gotAchievement = save_file_get_flags() & SAVE_FLAG_HAVE_VANISH_CAP;
        break;

    case 0x82:
        gotAchievement = save_file_get_flags() & SAVE_FLAG_HAVE_METAL_CAP;
        break;

    case 0x83:
        gotAchievement = save_file_get_flags() & SAVE_FLAG_HAVE_WING_CAP;
        break;
    
    case 0xFF:
        gotAchievement = TRUE;
        break;
    
    default:
        gotAchievement = save_file_get_star_flags(gCurrSaveFileNum - 1, gCurrCourseNum - 1);
        break;
    }

    if (!gotAchievement)
    {
        level_set_transition(-1, NULL);
        func_802D7F90(val8);
    }
}

static void func_8024992C(struct Struct8033A140 *level, u32 arg1)
{
    if (arg1 & 0x00000002)
        level->marioStartAngle[1] += 0x8000;

    level->marioStartPos[0] += 300.0f * sins(level->marioStartAngle[1]);
    level->marioStartPos[2] += 300.0f * coss(level->marioStartAngle[1]);
}

static void set_mario_initial_cap_powerup(struct MarioState *m)
{
    u32 capCourseIndex = gCurrCourseNum - COURSE_CAP_COURSES;

    switch (capCourseIndex)
    {
    case COURSE_COTMC - COURSE_CAP_COURSES:
        m->flags |= MARIO_METAL_CAP | MARIO_CAP_ON_HEAD;
        m->capTimer = 600;
        break;

    case COURSE_TOTWC - COURSE_CAP_COURSES:
        m->flags |= MARIO_WING_CAP | MARIO_CAP_ON_HEAD;
        m->capTimer = 1200;
        break;

    case COURSE_VCUTM - COURSE_CAP_COURSES:
        m->flags |= MARIO_VANISH_CAP | MARIO_CAP_ON_HEAD;
        m->capTimer = 600;
        break;
    }
}

static void set_mario_initial_action(struct MarioState *m, u32 spawnType, u32 actionArg)
{
    switch (spawnType)
    {
    case MARIO_SPAWN_UNKNOWN_01: set_mario_action(m, ACT_UNKNOWN_122, actionArg);  break;
    case MARIO_SPAWN_UNKNOWN_02: set_mario_action(m, ACT_IDLE, 0);                 break;
    case MARIO_SPAWN_UNKNOWN_03: set_mario_action(m, ACT_EMERGE_FROM_PIPE, 0);     break;
    case MARIO_SPAWN_UNKNOWN_04: set_mario_action(m, ACT_TELEPORT_FADE_IN, 0);     break;
    case MARIO_SPAWN_UNKNOWN_10: set_mario_action(m, ACT_IDLE, 0);                 break;
    case MARIO_SPAWN_UNKNOWN_12: set_mario_action(m, ACT_UNKNOWN_132, 0);          break;
    case MARIO_SPAWN_UNKNOWN_13: set_mario_action(m, ACT_HARD_BACKWARD_AIR_KB, 0); break;
    case MARIO_SPAWN_UNKNOWN_14: set_mario_action(m, ACT_UNKNOWN_124, 0);          break;
    case MARIO_SPAWN_UNKNOWN_15: set_mario_action(m, ACT_UNKNOWN_12A, 0);          break;
    case MARIO_SPAWN_UNKNOWN_16: set_mario_action(m, ACT_UNKNOWN_124, 0);          break;
    case MARIO_SPAWN_UNKNOWN_17: set_mario_action(m, ACT_FLYING, 2);               break;
    case MARIO_SPAWN_UNKNOWN_11: set_mario_action(m, ACT_UNKNOWN_0C0, 1);          break;
    case MARIO_SPAWN_UNKNOWN_20: set_mario_action(m, ACT_UNKNOWN_126, 0);          break;
    case MARIO_SPAWN_UNKNOWN_21: set_mario_action(m, ACT_UNKNOWN_128, 0);          break;
    case MARIO_SPAWN_UNKNOWN_22: set_mario_action(m, ACT_UNKNOWN_12D, 0);          break;
    case MARIO_SPAWN_UNKNOWN_23: set_mario_action(m, ACT_UNKNOWN_129, 0);          break;
    case MARIO_SPAWN_UNKNOWN_24: set_mario_action(m, ACT_UNKNOWN_12B, 0);          break;
    case MARIO_SPAWN_UNKNOWN_25: set_mario_action(m, ACT_UNKNOWN_12C, 0);          break;
    }

    set_mario_initial_cap_powerup(m);
}

static void init_mario_after_warp(void)
{
    struct ObjectWarpNode *spawnNode = func_8027A418(sDestWarpNodeId);
    u32 marioSpawnType = func_8027A38C(spawnNode->object);
    
    if (gMarioState->action != ACT_UNINITIALIZED)
    {
        D_8033A140.marioStartPos[0] = (s16) spawnNode->object->pos[0];
        D_8033A140.marioStartPos[1] = (s16) spawnNode->object->pos[1];
        D_8033A140.marioStartPos[2] = (s16) spawnNode->object->pos[2];
        
        D_8033A140.marioStartAngle[0] = 0;
        D_8033A140.marioStartAngle[1] = spawnNode->object->angle[1];
        D_8033A140.marioStartAngle[2] = 0;
        
        if (marioSpawnType == MARIO_SPAWN_UNKNOWN_01)
            func_8024992C(&D_8033A140, sWarpArg);

        if (sCurrWarpType == WARP_TYPE_CHANGE_LEVEL || sCurrWarpType == WARP_TYPE_CHANGE_AREA)
        {
            D_8033A140.areaIndex[0] = sDestAreaIndex;
            func_8027AA0C();
        }

        func_802548BC();
        set_mario_initial_action(gMarioState, marioSpawnType, sWarpArg);

        gMarioState->interactObj = spawnNode->object;
        gMarioState->usedObj = spawnNode->object;
    }

    func_802869B8(D_8032CE6C->unk24);
    sCurrWarpType = WARP_TYPE_NOT_WARPING;
    sDelayedWarpOp = WARP_OP_NONE;

    switch (marioSpawnType)
    {
    case MARIO_SPAWN_UNKNOWN_03: func_8027ABF0(0x08, 0x10, 0x00, 0x00, 0x00); break;
    case MARIO_SPAWN_UNKNOWN_01: func_8027ABF0(0x0A, 0x10, 0x00, 0x00, 0x00); break;
    case MARIO_SPAWN_UNKNOWN_04: func_8027ABF0(0x00, 0x14, 0xFF, 0xFF, 0xFF); break;
    case MARIO_SPAWN_UNKNOWN_16: func_8027ABF0(0x00, 0x1A, 0xFF, 0xFF, 0xFF); break;
    case MARIO_SPAWN_UNKNOWN_14: func_8027ABF0(0x0A, 0x10, 0x00, 0x00, 0x00); break;
    case MARIO_SPAWN_UNKNOWN_27: func_8027ABF0(0x00, 0x10, 0x00, 0x00, 0x00); break;
    default:                     func_8027ABF0(0x08, 0x10, 0x00, 0x00, 0x00); break;
    }

    if (gCurrDemoInput == NULL)
    {
        func_80249148(D_8032CE6C->unk36, D_8032CE6C->unk38, 0);
        
        if (gMarioState->flags & MARIO_METAL_CAP)
            func_80249368(0x0000040F);
        
        if (gMarioState->flags & (MARIO_VANISH_CAP | MARIO_WING_CAP))
            func_80249368(0x0000040E);

        if (sDestLevelNum == LEVEL_CASTLE &&
            sDestAreaIndex == 1 &&
            sDestWarpNodeId == 0x1F)
        {
            SetSound(0x701DB081, D_803320E0);
        }
    }
}

// used for warps inside one level
static void func_8024A02C(void)
{
    if (sCurrWarpType != WARP_TYPE_NOT_WARPING)
    {
        if (sCurrWarpType == WARP_TYPE_CHANGE_AREA)
        {
            level_control_timer(TIMER_CONTROL_HIDE);
            func_8027AA88();
            func_8027A894(sDestAreaIndex);
        }

        init_mario_after_warp();
    }
}

// used for warps between levels
static void func_8024A094(void)
{
    gCurrLevelNum = sDestLevelNum;

    level_control_timer(TIMER_CONTROL_HIDE);
    
    func_8027A894(sDestAreaIndex);
    init_mario_after_warp();
}

static void func_8024A0E0(void)
{
    u32 marioAction;

    switch (sDestWarpNodeId)
    {
    case WARP_NODE_CREDITS_START:
        marioAction = ACT_PEACH_CUTSCENE;
        break;

    case WARP_NODE_CREDITS_NEXT:
        marioAction = ACT_CREDITS;
        break;

    case WARP_NODE_CREDITS_END:
        marioAction = ACT_WAVING;
        break;
    }

    gCurrLevelNum = sDestLevelNum;

    func_8027A894(sDestAreaIndex);

    vec3s_set(
        D_8033A140.marioStartPos,
        gCurrCreditsEntry->marioPos[0],
        gCurrCreditsEntry->marioPos[1],
        gCurrCreditsEntry->marioPos[2]);
    
    vec3s_set(
        D_8033A140.marioStartAngle,
        0,
        0x100 * gCurrCreditsEntry->marioAngle,
        0);

    D_8033A140.areaIndex[0] = sDestAreaIndex;

    func_8027AA0C();
    func_802548BC();

    set_mario_action(gMarioState, marioAction, 0);

    func_802869B8(D_8032CE6C->unk24);

    sCurrWarpType = WARP_TYPE_NOT_WARPING;
    sDelayedWarpOp = WARP_OP_NONE;

    func_8027ABF0(0x00, 0x14, 0x00, 0x00, 0x00);

    if (gCurrCreditsEntry == NULL || gCurrCreditsEntry == sCreditsSequence)
        func_80249148(D_8032CE6C->unk36, D_8032CE6C->unk38, 0);
}

static void check_endless_staircase(void)
{
    s16 cameraAngle;
    struct Surface *floor;

    if (gCurrLevelNum == LEVEL_CASTLE &&
        save_file_get_total_star_count(gCurrSaveFileNum - 1, COURSE_MIN - 1, COURSE_MAX - 1) >= 70)
    {
        return;
    }

    if ((floor = gMarioState->floor) != NULL)
    {
        // I think only index 0 is used in game, but apparently they allow up to
        // four "displacers"
        s32 index = floor->type - SURFACE_001B;
        if (index >= 0 && index < 4 && D_8032CE6C->unk1C != NULL)
        {
            struct UnknownArea1C *ptr = &D_8032CE6C->unk1C[index];

            if (ptr->unk00 != 0)
            {
                gMarioState->pos[0] += ptr->displacement[0];
                gMarioState->pos[1] += ptr->displacement[1];
                gMarioState->pos[2] += ptr->displacement[2];

                gMarioState->marioObj->pos[0] = gMarioState->pos[0];
                gMarioState->marioObj->pos[1] = gMarioState->pos[1];
                gMarioState->marioObj->pos[2] = gMarioState->pos[2];

                cameraAngle = gMarioState->area->unk24->unk02;

                func_8027AB10(ptr->unk01);
                gMarioState->area = D_8032CE6C;

                func_8028C1A0(
                    ptr->displacement[0],
                    ptr->displacement[1],
                    ptr->displacement[2]);

                gMarioState->area->unk24->unk02 = cameraAngle;
            }
        }
    }
}

static s16 func_8024A48C(s16 arg)
{
    struct ObjectWarpNode *warpNode = func_8027A418(arg);
    s16 levelNum = warpNode->node.destLevel & 0x7F;
    
    u16 val8 = D_8032CE68[warpNode->node.destArea].unk36;
    u16 val6 = D_8032CE68[warpNode->node.destArea].unk38;
    
    s16 val4 =
        levelNum == gCurrLevelNum &&
        val8 == D_8032CE6C->unk36 &&
        val6 == D_8032CE6C->unk38;

    if (func_80320E98() != val6)
        val4 = FALSE;
     
    return val4;
}

/**
 * Set the current warp type and destination level/area/node.
 */
static void initiate_warp(s16 destLevel, s16 destArea, s16 destWarpNode, s32 arg3)
{
    if (destWarpNode >= WARP_NODE_CREDITS_MIN)
    {
        sCurrWarpType = WARP_TYPE_CHANGE_LEVEL;
    }
    else if (destLevel != gCurrLevelNum)
    {
        sCurrWarpType = WARP_TYPE_CHANGE_LEVEL;
    }
    else if (destArea != D_8032CE6C->index)
    {
        sCurrWarpType = WARP_TYPE_CHANGE_AREA;
    }
    else
    {
        sCurrWarpType = WARP_TYPE_SAME_AREA;
    }

    sDestLevelNum = destLevel;
    sDestAreaIndex = destArea;
    sDestWarpNodeId = destWarpNode;
    sWarpArg = arg3;
}

/**
 * Check if mario is above and close to a painting warp floor, and return the
 * corresponding warp node.
 */
static struct WarpNode *get_painting_warp_node(void)
{
    struct WarpNode *warpNode = NULL;
    s32 paintingIndex = gMarioState->floor->type - SURFACE_00D3;

    if (paintingIndex >= 0 && paintingIndex < 0x2D)
    {
        if (paintingIndex < 0x2A ||
            gMarioState->pos[1] - gMarioState->floorHeight < 80.0f)
        {
            warpNode = &D_8032CE6C->paintingWarpNodes[paintingIndex];
        }
    }

    return warpNode;
}

/**
 * Check is mario has entered a painting, and if so, initiate a warp.
 */
static void initiate_painting_warp(void)
{
    if (D_8032CE6C->paintingWarpNodes != NULL && gMarioState->floor != NULL)
    {
        struct WarpNode warpNode;
        struct WarpNode *pWarpNode = get_painting_warp_node();

        if (pWarpNode != NULL)
        {
            if (gMarioState->action & ACT_FLAG_INTANGIBLE)
            {
                func_80248FBC();
            }
            else if (pWarpNode->id != 0)
            {
                warpNode = *pWarpNode;

                if (!(warpNode.destLevel & 0x80))
                    D_8032C9E0 = func_8027A168(&warpNode);

                initiate_warp(
                    warpNode.destLevel & 0x7F,
                    warpNode.destArea,
                    warpNode.destNode,
                    0);
                func_8027A100(&warpNode);

                func_8027ADAC(1, 30, 255, 255, 255, 45);
                level_set_transition(74, basic_update);

                set_mario_action(gMarioState, ACT_DISAPPEARED, 0);

                gMarioState->marioObj->gfx.graphFlags &= ~0x0001;

                SetSound(0x701EFF81, D_803320E0);
                func_802491FC(398);
            }
        }
    }
}

/**
 * If there is not already a delayed warp, schedule one. The source node is
 * based on the warp operation and sometimes mario's used object.
 * Return the time left until the delayed warp is initiated.
 */
s16 level_trigger_warp(struct MarioState *m, s32 warpOp)
{
    s32 val04 = TRUE;

    if (sDelayedWarpOp == WARP_OP_NONE)
    {
        m->invincTimer = -1;
        sDelayedWarpArg = 0;
        sDelayedWarpOp = warpOp;

        switch (warpOp)
        {
        case WARP_OP_DEMO_NEXT:
        case WARP_OP_DEMO_END:
            sDelayedWarpTimer = 20;
            sSourceWarpNodeId = WARP_NODE_F0;
            D_8033A75C = 0;
            val04 = FALSE;
            func_8027ABF0(0x09, 0x14, 0x00, 0x00, 0x00);
            break;

        case WARP_OP_CREDITS_END:
            sDelayedWarpTimer = 60;
            sSourceWarpNodeId = WARP_NODE_F0;
            val04 = FALSE;
            D_8033A75C = 0;
            func_8027ABF0(0x01, 0x3C, 0x00, 0x00, 0x00);
            break;

        case WARP_OP_STAR_EXIT:
            sDelayedWarpTimer = 32;
            sSourceWarpNodeId = WARP_NODE_F0;
            D_8033A75C = 0;
            func_8027ABF0(0x11, 0x20, 0x00, 0x00, 0x00);
            break;

        case WARP_OP_DEATH:
            if (m->numLives == 0)
                sDelayedWarpOp = WARP_OP_GAME_OVER;
            sDelayedWarpTimer = 48;
            sSourceWarpNodeId = WARP_NODE_DEATH;
            func_8027ABF0(0x13, 0x30, 0x00, 0x00, 0x00);
            SetSound(0x70188081, D_803320E0);
            break;

        case WARP_OP_WARP_FLOOR:
            sSourceWarpNodeId = WARP_NODE_WARP_FLOOR;
            if (func_8027A418(sSourceWarpNodeId) == NULL)
            {
                if (m->numLives == 0)
                    sDelayedWarpOp = WARP_OP_GAME_OVER;
                else
                    sSourceWarpNodeId = WARP_NODE_DEATH;
            }
            sDelayedWarpTimer = 20;
            func_8027ABF0(0x0B, 0x14, 0x00, 0x00, 0x00);
            break;

        case WARP_OP_UNKNOWN_01: // enter totwc
            sDelayedWarpTimer = 30;
            sSourceWarpNodeId = WARP_NODE_F2;
            func_8027ABF0(0x01, 0x1E, 0xFF, 0xFF, 0xFF);
            break;

        case WARP_OP_UNKNOWN_02: // bbh enter
            sDelayedWarpTimer = 30;
            sSourceWarpNodeId = (m->usedObj->unk188 & 0x00FF0000) >> 16;
            func_8027ABF0(0x01, 0x1E, 0xFF, 0xFF, 0xFF);
            break;

        case WARP_OP_TELEPORT:
            sDelayedWarpTimer = 20;
            sSourceWarpNodeId = (m->usedObj->unk188 & 0x00FF0000) >> 16;
            val04 = !func_8024A48C(sSourceWarpNodeId);
            func_8027ABF0(0x01, 0x14, 0xFF, 0xFF, 0xFF);
            break;

        case WARP_OP_WARP_DOOR:
            sDelayedWarpTimer = 20;
            sDelayedWarpArg = m->actionArg;
            sSourceWarpNodeId = (m->usedObj->unk188 & 0x00FF0000) >> 16;
            val04 = !func_8024A48C(sSourceWarpNodeId);
            func_8027ABF0(0x0B, 0x14, 0x00, 0x00, 0x00);
            break;

        case WARP_OP_WARP_OBJECT:
            sDelayedWarpTimer = 20;
            sSourceWarpNodeId = (m->usedObj->unk188 & 0x00FF0000) >> 16;
            val04 = !func_8024A48C(sSourceWarpNodeId);
            func_8027ABF0(0x09, 0x14, 0x00, 0x00, 0x00);
            break;

        case WARP_OP_CREDITS_START:
            sDelayedWarpTimer = 30;
            func_8027ABF0(0x01, 0x1E, 0x00, 0x00, 0x00);
            break;

        case WARP_OP_CREDITS_NEXT:
            if (gCurrCreditsEntry == &sCreditsSequence[0])
            {
                sDelayedWarpTimer = 60;
                func_8027ABF0(0x01, 0x3C, 0x00, 0x00, 0x00);
            }
            else
            {
                sDelayedWarpTimer = 20;
                func_8027ABF0(0x01, 0x14, 0x00, 0x00, 0x00);
            }
            val04 = FALSE;
            break;
        }

        if (val04 && gCurrDemoInput == NULL)
            func_802491FC((3 * sDelayedWarpTimer / 2) * 8 - 2);
    }

    return sDelayedWarpTimer;
}

/**
 * If a delayed warp is ready, initiate it.
 */
static void initiate_delayed_warp(void)
{
    struct ObjectWarpNode *warpNode;
    s32 destWarpNode;

    if (sDelayedWarpOp != WARP_OP_NONE && --sDelayedWarpTimer == 0)
    {
        func_802D8098();

        if (gDebugLevelSelect && (sDelayedWarpOp & WARP_OP_TRIGGERS_LEVEL_SELECT))
        {
            func_8024975C(-9);
        }
        else if (gCurrDemoInput != NULL)
        {
            if (sDelayedWarpOp == WARP_OP_DEMO_END)
                func_8024975C(-8);
            else
                func_8024975C(-2);
        }
        else
        {
            switch (sDelayedWarpOp)
            {
            case WARP_OP_GAME_OVER:
                save_file_reload();
                func_8024975C(-3);
                break;

            case WARP_OP_CREDITS_END:
                func_8024975C(-1);
                func_80320980(2, 0x3F0);
                break;

            case WARP_OP_DEMO_NEXT:
                func_8024975C(-2);
                break;

            case WARP_OP_CREDITS_START:
                gCurrCreditsEntry = &sCreditsSequence[0];
                initiate_warp(
                    gCurrCreditsEntry->levelNum,
                    gCurrCreditsEntry->areaIndex,
                    WARP_NODE_CREDITS_START,
                    0);
                break;
            
            case WARP_OP_CREDITS_NEXT:
                func_803208C0(2, 0x3FF);

                gCurrCreditsEntry += 1;
                D_8033A758 = gCurrCreditsEntry->unk02 & 0x07;
                if ((gCurrCreditsEntry + 1)->levelNum == 0)
                    destWarpNode = WARP_NODE_CREDITS_END;
                else
                    destWarpNode = WARP_NODE_CREDITS_NEXT;
                
                initiate_warp(
                    gCurrCreditsEntry->levelNum,
                    gCurrCreditsEntry->areaIndex,
                    destWarpNode,
                    0);
                break;

            default:
                warpNode = func_8027A418(sSourceWarpNodeId);
                
                initiate_warp(
                    warpNode->node.destLevel & 0x7F,
                    warpNode->node.destArea,
                    warpNode->node.destNode,
                    sDelayedWarpArg);
                
                func_8027A100(&warpNode->node);
                if (sCurrWarpType != WARP_TYPE_CHANGE_LEVEL)
                    level_set_transition(2, NULL);
                break;
            }
        }
    }
}

static void update_hud_values(void)
{
    if (gCurrCreditsEntry == NULL)
    {
        s16 numHealthWedges = gMarioState->health > 0 ? gMarioState->health >> 8 : 0;
 
        if (gCurrCourseNum > 0)
            gHudDisplayFlags |= 0x0002;
        else
            gHudDisplayFlags &= ~0x0002;

        if (gDisplayedCoins < gMarioState->numCoins)
        {
            if (D_8032C694 & 0x00000001)
            {
                u32 coinSound;
                if (gMarioState->action & (ACT_FLAG_SWIMMING | ACT_FLAG_METAL_WATER))
                    coinSound = 0x38128081;
                else
                    coinSound = 0x38118081;
                
                gDisplayedCoins += 1;
                SetSound(coinSound, &gMarioState->marioObj->gfx.unk54);
            }
        }

        if (gMarioState->numLives > 100)
            gMarioState->numLives = 100;

        if (gMarioState->numCoins > 999)
            gMarioState->numLives = (s8) 999; //! Wrong variable

        gDisplayedStars = gMarioState->numStars;
        gDisplayedLives = gMarioState->numLives;
        gDisplayedKeys = gMarioState->numKeys;

        if (numHealthWedges > gDisplayedHealthWedges)
            SetSound(0x700D0081, D_803320E0);
        gDisplayedHealthWedges = numHealthWedges;

        if (gMarioState->hurtCounter > 0)
            gHudDisplayFlags |= 0x8000;
        else
            gHudDisplayFlags &= ~0x8000;
    }
}

/**
 * Update objects, hud, and camera. This update function excludes things like
 * endless staircase, warps, pausing, etc. This is used when entering a painting,
 * presumably to allow painting and camera updating while avoiding triggering the
 * warp twice.
 */
static void basic_update(UNUSED s16 *arg)
{
    func_8027ABB4();
    update_hud_values();

    if (D_8032CE6C != NULL)
        func_80286348(D_8032CE6C->unk24);
}

static s32 play_mode_normal(void)
{
    if (gCurrDemoInput != NULL)
    {
        IntroPrintText();
        if (gPlayer1Controller->buttonPressed & END_DEMO)
        {
            level_trigger_warp(
                gMarioState,
                gCurrLevelNum == LEVEL_PSS ? WARP_OP_DEMO_END : WARP_OP_DEMO_NEXT);
        }
        else if (!D_8033A740 && sDelayedWarpOp == WARP_OP_NONE &&
            (gPlayer1Controller->buttonPressed & START_BUTTON))
        {
            level_trigger_warp(gMarioState, WARP_OP_DEMO_NEXT);
        }
    }

    func_8024A02C();
    check_endless_staircase();

    if (sTimerRunning && gTimerValueInFrames < 17999)
        gTimerValueInFrames += 1;

    func_8027ABB4();
    update_hud_values();

    if (D_8032CE6C != NULL)
        func_80286348(D_8032CE6C->unk24);

    initiate_painting_warp();
    initiate_delayed_warp();

    // If either initiate_painting_warp or initiate_delayed_warp initiated a
    // warp, change play mode accordingly.
    if (sCurrPlayMode == PLAY_MODE_NORMAL)
    {
        if (sCurrWarpType == WARP_TYPE_CHANGE_LEVEL)
        {
            set_play_mode(PLAY_MODE_CHANGE_LEVEL);
        }
        else if (sTransitionTimer != 0)
        {
            set_play_mode(PLAY_MODE_CHANGE_AREA);
        }
        else if (pressed_paused())
        {
            func_80248C28(1);
            D_8033B4D8 |= 0x8000;
            set_play_mode(PLAY_MODE_PAUSED);
        }
    }

    return 0;
}

static s32 play_mode_paused(void)
{
    if (D_8033A75E == 0)
    {
        func_802D9A14(1);
    }
    else if (D_8033A75E == 1)
    {
        func_80248CB8(1);
        D_8033B4D8 &= ~0x8000;
        set_play_mode(PLAY_MODE_NORMAL);
    }
    else
    {
        // Exit level

        if (gDebugLevelSelect)
        {
            func_80249788(-9, 1);
        }
        else
        {
            initiate_warp(LEVEL_CASTLE, 1, 0x1F, 0);
            func_80249788(0, 0);
            D_8033A75C = 0;
        }

        D_8033B4D8 &= ~0x8000;
    }

    return 0;
}

/**
 * Debug mode that lets you frame advance by pressing D-pad down. Unfortunately
 * it uses the pause camera, making it basically unusable in most levels.
 */
static s32 play_mode_frame_advance(void)
{
    if (gPlayer1Controller->buttonPressed & D_JPAD)
    {
        D_8033B4D8 &= ~0x8000;
        play_mode_normal();
    }
    else if (gPlayer1Controller->buttonPressed & START_BUTTON)
    {
        D_8033B4D8 &= ~0x8000;
        func_80248CB8(1);
        set_play_mode(PLAY_MODE_NORMAL);
    }
    else
    {
        D_8033B4D8 |= 0x8000;
    }

    return 0;
}

/**
 * Set the transition, which is a period of time after the warp is initiated
 * but before it actually occurs. If updateFunction is not NULL, it will be
 * called each frame during the transition.
 */
void level_set_transition(s16 length, void (*updateFunction)(s16 *))
{
    sTransitionTimer = length;
    sTransitionUpdate = updateFunction;
}

/**
 * Play the transition and then return to normal play mode.
 */
static s32 play_mode_change_area(void)
{
    //! This maybe was supposed to be sTransitionTimer == -1? sTransitionUpdate
    // is never set to -1.
    if (sTransitionUpdate == (void (*)(s16 *)) -1)
        func_80286348(D_8032CE6C->unk24);
    else if (sTransitionUpdate != NULL)
        sTransitionUpdate(&sTransitionTimer);

    if (sTransitionTimer > 0)
        sTransitionTimer -= 1;

    //! If sTransitionTimer is -1, this will miss.
    if (sTransitionTimer == 0)
    {
        sTransitionUpdate = NULL;
        set_play_mode(PLAY_MODE_NORMAL);
    }

    return 0;
}

/**
 * Play the transition and then return to normal play mode.
 */
static s32 play_mode_change_level(void)
{
    if (sTransitionUpdate != NULL)
        sTransitionUpdate(&sTransitionTimer);

    //! If sTransitionTimer is -1, this will miss.
    if (--sTransitionTimer == -1)
    {
        gHudDisplayFlags = 0;
        sTransitionTimer = 0;
        sTransitionUpdate = NULL;

        if (sCurrWarpType != WARP_TYPE_NOT_WARPING)
            return sDestLevelNum;
        else
            return D_80339EE0;
    }

    return 0;
}

/**
 * Unused play mode. Doesn't call transition update and doesn't reset transition
 * at the end.
 */
static s32 play_mode_unused(void)
{
    if (--sTransitionTimer == -1)
    {
        gHudDisplayFlags = 0;

        if (sCurrWarpType != WARP_TYPE_NOT_WARPING)
            return sDestLevelNum;
        else
            return D_80339EE0;
    }

    return 0;
}

static s32 update_level(void)
{
    s32 val4;

    switch (sCurrPlayMode)
    {
    case PLAY_MODE_NORMAL:        val4 = play_mode_normal();        break;
    case PLAY_MODE_PAUSED:        val4 = play_mode_paused();        break;
    case PLAY_MODE_CHANGE_AREA:   val4 = play_mode_change_area();   break;
    case PLAY_MODE_CHANGE_LEVEL:  val4 = play_mode_change_level();  break;
    case PLAY_MODE_FRAME_ADVANCE: val4 = play_mode_frame_advance(); break;
    }

    if (val4 != 0)
    {
        func_80248C10();
        func_80248D90();
    }

    return val4;
}

static s32 init_level(void)
{
    s32 val4 = 0;

    set_play_mode(PLAY_MODE_NORMAL);
    
    sDelayedWarpOp = WARP_OP_NONE;
    sTransitionTimer = 0;
    D_80339EE0 = 0;

    if (gCurrCreditsEntry == NULL)
        gHudDisplayFlags = 0x003F;
    else
        gHudDisplayFlags = 0;

    sTimerRunning = 0;

    if (sCurrWarpType != WARP_TYPE_NOT_WARPING)
    {
        if (sDestWarpNodeId >= WARP_NODE_CREDITS_MIN)
            func_8024A0E0();
        else
            func_8024A094();
    }
    else
    {
        if (D_8033A140.areaIndex[0] >= 0)
        {
            func_8027AA0C();
            func_802548BC();
        }

        if (D_8032CE6C != NULL)
        {
            func_802869B8(D_8032CE6C->unk24);

            if (gCurrDemoInput != NULL)
            {
                set_mario_action(gMarioState, ACT_IDLE, 0);
            }
            else if (gDebugLevelSelect == 0)
            {
                if (gMarioState->action != ACT_UNINITIALIZED)
                {
                    if (save_file_exists(gCurrSaveFileNum - 1))
                    {
                        set_mario_action(gMarioState, ACT_IDLE, 0);
                    }
                    else
                    {
                        set_mario_action(gMarioState, ACT_INTRO_CUTSCENE, 0);
                        val4 = 1;
                    }
                }
            }
        }

        if (val4 != 0)
            func_8027ABF0(0x00, 0x5A, 0xFF, 0xFF, 0xFF);
        else
            func_8027ABF0(0x08, 0x10, 0xFF, 0xFF, 0xFF);

        if (gCurrDemoInput == NULL)
        {
            func_80249148(D_8032CE6C->unk36, D_8032CE6C->unk38, 0);;
        }
    }

    if (gMarioState->action == ACT_INTRO_CUTSCENE)
        func_803208C0(2, 0x330);

    return 1;
}

/**
 * Initialize the current level if initOrUpdate is 0, or update the level if it
 * is 1. 
 */
s32 lvl_init_or_update(s16 initOrUpdate, UNUSED s32 arg1)
{
    s32 result = 0;

    switch (initOrUpdate)
    {
    case 0: result = init_level(); break;
    case 1: result = update_level(); break;
    }

    return result;
}

s32 lvl_init_from_save_file(UNUSED s16 arg0, s32 levelNum)
{
    sCurrWarpType = WARP_TYPE_NOT_WARPING;
    sDelayedWarpOp = WARP_OP_NONE;
    D_80339EFE = !save_file_exists(gCurrSaveFileNum - 1);

    gCurrLevelNum = levelNum;
    gCurrCourseNum = COURSE_NONE;
    D_8033A75C = 0;
    gCurrCreditsEntry = NULL;
    D_8032CE34 = 0;

    func_80254CE0();
    func_8027A0E8();
    save_file_move_cap_to_default_location();
    func_802875DC();
    func_802E2F40();

    return levelNum;
}

s32 lvl_set_current_level(UNUSED s16 arg0, s32 levelNum)
{
    s32 val4 = D_8032C9E0;

    D_8032C9E0 = 0;
    gCurrLevelNum = levelNum;
    gCurrCourseNum = D_8032CE37[levelNum];

    if (gCurrDemoInput != NULL ||
        gCurrCreditsEntry != NULL ||
        gCurrCourseNum == COURSE_NONE)
    {
        return 0;
    }

    if (gCurrLevelNum != LEVEL_BOWSER_1 &&
        gCurrLevelNum != LEVEL_BOWSER_2 &&
        gCurrLevelNum != LEVEL_BOWSER_3)
    {
        gMarioState->numCoins = 0;
        gDisplayedCoins = 0;
        D_8032CE30 = save_file_get_star_flags(gCurrSaveFileNum - 1, gCurrCourseNum - 1);
    }

    if (D_8033A75C != gCurrCourseNum)
    {
        D_8033A75C = gCurrCourseNum;
        func_8029BFF0();
        func_8027A0E8();
    }

    if (gCurrCourseNum > COURSE_STAGES_MAX || val4 != 0)
        return 0;

    if (gDebugLevelSelect != 0 && gDebugResourceMeter == 0)
        return 0;

    return 1;
}

/**
 * Play the "thank you so much for playing my game" sound.
 */
s32 lvl_play_the_end_screen_sound(UNUSED s16 arg0, UNUSED s32 arg1)
{
    SetSound(0x701FFF81, D_803320E0);
    return 1;
}
