#include <ultra64.h>

#include "sm64.h"
#include "behavior_script.h"
#include "object_helpers.h"
#include "audio_interface_2.h"
#include "print.h"
#include "surface_collision.h"
#include "mario.h"
#include "game.h"
#include "main.h"

extern int gDebugInfoFlags; // (1 = mapinfo, 2 = unused but set)

#define DEBUG_INFO_NOFLAGS      (0 << 0)
#define DEBUG_INFO_FLAG_DPRINT  (1 << 0)
#define DEBUG_INFO_FLAG_LSELECT (1 << 1)
#define DEBUG_INFO_FLAG_ALL     0xFF

extern int gNumFindFloorMisses;
extern int gUnknownWallCount;
extern s16 gNumFindFloorCalls;
extern s16 gNumFindCeilCalls;
extern s16 gNumFindWallCalls;

// these were 2d grids that probably functioned as
// recording debug information for all debug info
// systems. however, the only used ones are [4]
// and [5] (effectinfo and enemyinfo). The first
// 4 rows are effectively unused, despite being
// modifyable by the debug control function.
extern s16 gDebugInfo[][8];
extern s16 gDebugInfoOverwrite[][8]; // most likely used to manually copy in
                                     // preset controls, since it is never set

extern s16 D_8035FEE2;
extern s16 D_8035FEE4;
extern s16 gStageParam;

extern s16 gDebugPrintState1[]; // prints top-down?
extern s16 gDebugPrintState2[]; // prints bottom-up?

enum DebugPrintStateInfo {
    DEBUG_PSTATE_DISABLED,
    DEBUG_PSTATE_X_CURSOR,
    DEBUG_PSTATE_Y_CURSOR,
    DEBUG_PSTATE_MIN_Y_CURSOR,
    DEBUG_PSTATE_MAX_X_CURSOR,
    DEBUG_PSTATE_LINE_Y_OFFSET
};

extern u8 beh_koopa_shell[];
extern u8 beh_jumping_box[];
extern u8 beh_koopa_shell_underwater[];

// DEBUG_SYS_EFFECTINFO
static const char *sDebugEffectStringInfo[] =
{
    "  a0 %d",
    "  a1 %d",
    "  a2 %d",
    "  a3 %d",
    "  a4 %d",
    "  a5 %d",
    "  a6 %d",
    "  a7 %d",
    "A" // cursor
};

// DEBUG_SYS_ENEMYINFO
static const char *sDebugEnemyStringInfo[] =
{
    "  b0 %d",
    "  b1 %d",
    "  b2 %d",
    "  b3 %d",
    "  b4 %d",
    "  b5 %d",
    "  b6 %d",
    "  b7 %d",
    "B" // cursor
};

static int sDebugInfoDPadMask = 0;
static int sDebugInfoDPadUpdID = 0;
static s8 sDebugLvSelectCheckFlag = FALSE;

enum DebugPage {
    DEBUG_PAGE_OBJECTINFO,       // 0: objectinfo
    DEBUG_PAGE_CHECKSURFACEINFO, // 1: checkinfo/surfaceinfo
    DEBUG_PAGE_MAPINFO,          // 2: mapinfo
    DEBUG_PAGE_STAGEINFO,        // 3: stageinfo
    DEBUG_PAGE_EFFECTINFO,       // 4: effectinfo
    DEBUG_PAGE_ENEMYINFO         // 5: enemyinfo
};

#define DEBUG_PAGE_MIN DEBUG_PAGE_OBJECTINFO
#define DEBUG_PAGE_MAX DEBUG_PAGE_ENEMYINFO

static s8 sDebugPage = DEBUG_PAGE_MIN;
static s8 sNoExtraDebug = FALSE;
static s8 sDebugStringArrPrinted = FALSE;
static s8 sDebugSysCursor = 0;
static s8 sDebugInfoButtonSeqID = 0;
static s16 sDebugInfoButtonSeq[] = {U_CBUTTONS, L_CBUTTONS, D_CBUTTONS, R_CBUTTONS, -1};

// most likely present in an ifdef DEBUG build. TODO: check DD version?
static void Stub802C9890(void)
{}

static void Stub802C98A0(void)
{}

static void Stub802C98B0(void)
{}

static void Stub802C98C0(void)
{}

/*
 * These 2 functions are called from the object list processor in regards to cycle
 * counts. They likely have stubbed out code that calculated the clock count and
 * its difference for consecutive calls.
 */
s64 get_current_clock(void)
{
    u64 wtf = 0;

    return wtf;
}

s64 get_clock_difference(UNUSED u64 arg0)
{
    u64 wtf = 0;

    return wtf;
}

/*
 * Set the print state info given a pointer to a print state and the relevent
 * information. Note the reset of the printing boolean. For all intenses and
 * purposes this creates/formats a new print state.
 */
static void set_print_state_info(s16 *printState, s16 xCursor, s16 yCursor, s16 minYCursor, s16 maxXCursor, s16 lineYOffset)
{
    printState[DEBUG_PSTATE_DISABLED]      = FALSE;
    printState[DEBUG_PSTATE_X_CURSOR]      = xCursor;
    printState[DEBUG_PSTATE_Y_CURSOR]      = yCursor;
    printState[DEBUG_PSTATE_MIN_Y_CURSOR]  = minYCursor;
    printState[DEBUG_PSTATE_MAX_X_CURSOR]  = maxXCursor;
    printState[DEBUG_PSTATE_LINE_Y_OFFSET] = lineYOffset;
}

/*
 * Take a print state array, string, and the number to print, and use its information to print
 * the next entry in the list. If the current print state array is too far down the list, this
 * will print "DPRINT OVER" instead, signaling that the print state overflowed.
 */
static void print_text_array_info(s16 *printState, const char *str, int number)
{
    if(!printState[DEBUG_PSTATE_DISABLED])
    {
        if((printState[DEBUG_PSTATE_Y_CURSOR] < printState[DEBUG_PSTATE_MIN_Y_CURSOR]) 
        || (printState[DEBUG_PSTATE_MAX_X_CURSOR] < printState[DEBUG_PSTATE_Y_CURSOR]))
        {
            print_text(printState[DEBUG_PSTATE_X_CURSOR], printState[DEBUG_PSTATE_Y_CURSOR], "DPRINT OVER");
            printState[DEBUG_PSTATE_DISABLED] += 1; // why not just = TRUE...
        }
        else
        {
            print_text_fmt_int(printState[DEBUG_PSTATE_X_CURSOR], printState[DEBUG_PSTATE_Y_CURSOR], str, number);
            printState[DEBUG_PSTATE_Y_CURSOR] += printState[DEBUG_PSTATE_LINE_Y_OFFSET];
        }
    }
}

void set_text_array_x_y(s32 xOffset, s32 yOffset)
{
    s16 *printState = gDebugPrintState1;

    printState[DEBUG_PSTATE_X_CURSOR] += xOffset;
    printState[DEBUG_PSTATE_Y_CURSOR] = yOffset * printState[DEBUG_PSTATE_LINE_Y_OFFSET] + printState[DEBUG_PSTATE_Y_CURSOR];
}

/*
 * These series of dprint functions print methods depending on the context of the
 * current debug mode as well as the printer array (down to up vs up to down).
 */
void print_debug_bottom_up(const char *str, int number)
{
    if(gDebugInfoFlags & DEBUG_INFO_FLAG_DPRINT)
        print_text_array_info(gDebugPrintState2, str, number);
}

void print_debug_top_down_objectinfo(const char *str, int number)
{
    if((gDebugInfoFlags & DEBUG_INFO_FLAG_DPRINT) && sDebugPage == DEBUG_PAGE_OBJECTINFO)
        print_text_array_info(gDebugPrintState1, str, number);
}

void print_debug_top_down_mapinfo(const char *str, int number)
{
    if(sNoExtraDebug) // how come this is the only instance of the sNoExtraDebug check?
        return;

    if(gDebugInfoFlags & DEBUG_INFO_FLAG_DPRINT)
        print_text_array_info(gDebugPrintState1, str, number);
}

static void print_debug_top_down_normal(const char *str, int number)
{
    if(gDebugInfoFlags & DEBUG_INFO_FLAG_DPRINT)
        print_text_array_info(gDebugPrintState1, str, number);
}

static void print_mapinfo(void)
{
    struct Surface *pfloor;
    f32 bgY;
    f32 water;
    int area;
    int angY;

    angY = gCurrentObject->oAngleYaw / 182.044000;
    area  = ((int)gCurrentObject->oPosX + 0x2000) / 1024
          + ((int)gCurrentObject->oPosZ + 0x2000) / 1024 * 16;

    bgY = find_floor(gCurrentObject->oPosX, gCurrentObject->oPosY, gCurrentObject->oPosZ, &pfloor);
    water = find_water_level(gCurrentObject->oPosX, gCurrentObject->oPosZ);

    print_debug_top_down_normal("mapinfo", 0);
    print_debug_top_down_mapinfo("area %x", area);
    print_debug_top_down_mapinfo("wx   %d", gCurrentObject->oPosX);
    //! Fat finger: programmer hit tab instead of space. Japanese
    // thumb shift keyboards had the tab key next to the spacebar,
    // so this was likely the reason.
    print_debug_top_down_mapinfo("wy\t  %d", gCurrentObject->oPosY);
    print_debug_top_down_mapinfo("wz   %d", gCurrentObject->oPosZ);
    print_debug_top_down_mapinfo("bgY  %d", bgY);
    print_debug_top_down_mapinfo("angY %d", angY);

    if(pfloor) // not null
    {
        print_debug_top_down_mapinfo("bgcode   %d", pfloor->type);
        print_debug_top_down_mapinfo("bgstatus %d", pfloor->flags);
        print_debug_top_down_mapinfo("bgarea   %d", pfloor->room);
    }

    if(gCurrentObject->oPosY < water)
        print_debug_top_down_mapinfo("water %d", water);
}

static void print_checkinfo(void)
{
    print_debug_top_down_normal("checkinfo", 0);
}

static void print_surfaceinfo(void)
{
    debug_surface_list_info(gMarioObject->oPosX, gMarioObject->oPosZ);
}

static void print_stageinfo(void)
{
    print_debug_top_down_normal("stageinfo", 0);
    print_debug_top_down_normal("stage param %d", gStageParam);
}

/*
 * Common printer function for effectinfo and enemyinfo. This function
 * also prints the cursor functionality intended to be used with modifying
 * gDebugInfo to set enemy/effect behaviors.
 */
static void print_string_array_info(const char **strArr)
{
    int i;

    if(sDebugStringArrPrinted == FALSE)
    {
        sDebugStringArrPrinted += 1; // again, why not = TRUE...
        for(i = 0; i < 8; i++)
        {
            // sDebugPage is assumed to be 4 or 5 here.
            print_debug_top_down_mapinfo(strArr[i], gDebugInfo[sDebugPage][i]);
        }
        // modify the cursor position so the cursor prints at the correct location.
        set_text_array_x_y(0, -8 - -sDebugSysCursor);
        print_debug_top_down_mapinfo(strArr[8], 0); // print the cursor
        set_text_array_x_y(0, 7 - sDebugSysCursor);
    }
}

static void print_effectinfo(void)
{
    print_debug_top_down_normal("effectinfo", 0);
    print_string_array_info(sDebugEffectStringInfo);
}

static void print_enemyinfo(void)
{
    print_debug_top_down_normal("enemyinfo", 0);
    print_string_array_info(sDebugEnemyStringInfo);
}

static void update_debug_dpadmask(void)
{
    int dPadMask = gPlayer1Controller->buttonDown & (U_JPAD | D_JPAD | L_JPAD | R_JPAD);

    if(!dPadMask)
    {
        sDebugInfoDPadUpdID = 0;
        sDebugInfoDPadMask = 0;
    }
    else
    {
        // to prevent stuttering of mask updates, the first time is updated 6
        // frames from start, and then every 2 frames when held down.
        if(sDebugInfoDPadUpdID == 0)
        {
            sDebugInfoDPadMask = dPadMask;
        }
        else if(sDebugInfoDPadUpdID == 6)
        {
            sDebugInfoDPadMask = dPadMask;
        }
        else
        {
            sDebugInfoDPadMask = 0;
        }
        sDebugInfoDPadUpdID += 1;
        if(sDebugInfoDPadUpdID >= 8)
        {
            sDebugInfoDPadUpdID = 6; // rapidly set to 6 from 8 as long as dPadMask is being set.
        }
    }
}

void debug_unknown_level_select_check(void)
{
    if(!sDebugLvSelectCheckFlag)
    {
        sDebugLvSelectCheckFlag += 1; // again, just do = TRUE...

        if(!gDebugLevelSelect)
            gDebugInfoFlags = DEBUG_INFO_NOFLAGS;
        else
            gDebugInfoFlags = DEBUG_INFO_FLAG_LSELECT;

        gNumFindFloorCalls = 0;
        gNumFindCeilCalls = 0;
        gNumFindWallCalls = 0;
    }
}

void reset_debug_objectinfo(void)
{
    gNumFindFloorMisses = 0;
    gUnknownWallCount = 0;
    gUpdatedObjectCount = 0;
    sDebugStringArrPrinted = FALSE;
    D_8035FEE2 = 0;
    D_8035FEE4 = 0;

    set_print_state_info(gDebugPrintState1, 20, 185, 40, 200, -15);
    set_print_state_info(gDebugPrintState2, 180, 30, 0,  150,  15);
    update_debug_dpadmask();
}

/*
 * This function checks for a button sequence (C Up, C Left, C Down,
 * C Right) and then toggles the debug flags from FF to 2; 2 is unused,
 * despite so this has no effect, being called. (unused)
 */
static void check_debug_button_seq(void)
{
    s16 *buttonArr;
    s16 cButtonMask;
    
    buttonArr = sDebugInfoButtonSeq;

    if(!(gPlayer1Controller->buttonDown & L_TRIG))
        sDebugInfoButtonSeqID = 0;
    else
    {
        if((s16)(cButtonMask = (gPlayer1Controller->buttonPressed & C_BUTTONS)))
        {
            if(buttonArr[sDebugInfoButtonSeqID] == cButtonMask)
            {
                sDebugInfoButtonSeqID += 1;
                if(buttonArr[sDebugInfoButtonSeqID] == -1)
                {
                    if(gDebugInfoFlags == DEBUG_INFO_FLAG_ALL)
                    {
                        gDebugInfoFlags = DEBUG_INFO_FLAG_LSELECT;
                    }
                    else
                    {
                        gDebugInfoFlags = DEBUG_INFO_FLAG_ALL;
                    }
                }
            }
            else
            {
                sDebugInfoButtonSeqID = 0;
            }
        }
    }
}

/*
 * Poll the debug info flags and controller for appropriate presses that
 * control sDebugPage's range. (unused)
 */
static void try_change_debug_page(void)
{
    if(gDebugInfoFlags & DEBUG_INFO_FLAG_DPRINT)
    {
        if((gPlayer1Controller->buttonPressed &  L_JPAD) 
        && (gPlayer1Controller->buttonDown    & (L_TRIG | R_TRIG)))
        {
            sDebugPage += 1;
        }
        if((gPlayer1Controller->buttonPressed & R_JPAD)
        && (gPlayer1Controller->buttonDown    & (L_TRIG | R_TRIG)))
        {
            sDebugPage -= 1;
        }
        if(sDebugPage >= (DEBUG_PAGE_MAX + 1))
        {
            sDebugPage = DEBUG_PAGE_MIN;
        }
        if(sDebugPage < DEBUG_PAGE_MIN)
        {
            sDebugPage = DEBUG_PAGE_MAX;
        }
    }
}

/*
 * Use the controller to modify gDebugInfo and the sys cursor while
 * using the DPad. L/R DPad modifies gDebugInfo while U/D modifies
 * sDebugSysCursor. This is used to adjust enemy and effect behaviors
 * on the fly. (unused)
 */
static void try_modify_debug_controls(void)
{
    int sp4;

    if(gPlayer1Controller->buttonPressed & Z_TRIG)
    {
        sNoExtraDebug ^= 1;
    }
    if(!(gPlayer1Controller->buttonDown & (L_TRIG | R_TRIG)) && sNoExtraDebug == FALSE)
    {
        sp4 = 1;
        if(gPlayer1Controller->buttonDown & B_BUTTON)
            sp4 = 100;

        if(sDebugInfoDPadMask & U_JPAD)
        {
            sDebugSysCursor -= 1;
            if(sDebugSysCursor < 0)
                sDebugSysCursor = 0;
        }

        if(sDebugInfoDPadMask & D_JPAD)
        {
            sDebugSysCursor += 1;
            if(sDebugSysCursor >= 8)
                sDebugSysCursor = 7;
        }

        if(sDebugInfoDPadMask & L_JPAD)
        {
            // we allow the player while in this mode to modify the debug controls. This is
            // so the playtester can adjust enemy behavior and parameters on the fly, since
            // various behaviors try to update their behaviors from gDebugInfo[4] and [5].
            if(gPlayer1Controller->buttonDown & A_BUTTON)
                gDebugInfo[sDebugPage][sDebugSysCursor] = gDebugInfoOverwrite[sDebugPage][sDebugSysCursor];
            else
                gDebugInfo[sDebugPage][sDebugSysCursor] = gDebugInfo[sDebugPage][sDebugSysCursor] - sp4;
        }

        if(sDebugInfoDPadMask & R_JPAD)
        {
            gDebugInfo[sDebugPage][sDebugSysCursor] = gDebugInfo[sDebugPage][sDebugSysCursor] + sp4;
        }
    }
}

// possibly a removed debug control (TODO: check DD)
void stub_802CA5D0(void)
{}

/*
 * If Mario's object exists, this function tries to print available object debug
 * information depending on the debug sys ID. Additional information (updated obj
 * count, floor misses, and an unknown wall counter) is also printed.
 */
void try_print_debug_mario_object_info(void)
{
    if(gMarioObject != NULL)
    {
        switch(sDebugPage)
        {
            case DEBUG_PAGE_CHECKSURFACEINFO:
                print_surfaceinfo();
                break;
            case DEBUG_PAGE_EFFECTINFO:
                print_effectinfo();
                break;
            case DEBUG_PAGE_ENEMYINFO:
                print_enemyinfo();
                break;
            default:
                break;
        }
    }

    print_debug_top_down_mapinfo("obj  %d", gUpdatedObjectCount);

    if(gNumFindFloorMisses)
        print_debug_bottom_up("NULLBG %d", gNumFindFloorMisses);

    if(gUnknownWallCount)
        print_debug_bottom_up("WALL   %d", gUnknownWallCount);
}

/*
 * Similar to above, but with level information. (checkinfo, mapinfo,
 * stageinfo)
 */
void try_print_debug_mario_level_info(void)
{
    switch(sDebugPage)
    {
        case DEBUG_PAGE_OBJECTINFO:
            break; // no info list is printed for obj info.
        case DEBUG_PAGE_CHECKSURFACEINFO:
            print_checkinfo();
            break;
        case DEBUG_PAGE_MAPINFO:
            print_mapinfo();
            break;
        case DEBUG_PAGE_STAGEINFO:
            print_stageinfo();
            break;
        default:
            break;
    }
}

/*
 * One of the only remaining debug controls activatable from the
 * debug control array. This function lets you spawn 1 of 3
 * objects: A koopa shell, a jumping box, and an underwater koopa
 * shell. This can be reactivated by turning on modifying
 * debug controls with try_modify_debug_controls and setting
 * [5][7] (b7 in the string array) to 1 to enable debug spawn.
 */
void try_do_mario_debug_object_spawn(void)
{
    UNUSED int unused;

    if(sDebugPage == DEBUG_PAGE_STAGEINFO && gDebugInfo[DEBUG_PAGE_ENEMYINFO][7] == 1)
    {
        if(gPlayer1Controller->buttonPressed & R_JPAD)
            spawn_obj_adv(0, 0, 100, 200, gCurrentObject, 190, beh_koopa_shell);
        if(gPlayer1Controller->buttonPressed & L_JPAD)
            spawn_obj_adv(0, 0, 100, 200, gCurrentObject, 130, beh_jumping_box);
        if(gPlayer1Controller->buttonPressed & D_JPAD)
            spawn_obj_adv(0, 0, 100, 200, gCurrentObject, 190, beh_koopa_shell_underwater);
    }
}

// TODO: figure out what this is
static void Unknown802CA8B4(void)
{
    if(gCurrentObject->oMoveFlags & OBJ_MOV_0)
        print_debug_top_down_objectinfo("BOUND   %x", gCurrentObject->oMoveFlags);
    if(gCurrentObject->oMoveFlags & OBJ_MOV_GROUND)
        print_debug_top_down_objectinfo("TOUCH   %x", gCurrentObject->oMoveFlags);
    if(gCurrentObject->oMoveFlags & OBJ_MOV_2)
        print_debug_top_down_objectinfo("TAKEOFF %x", gCurrentObject->oMoveFlags);
    if(gCurrentObject->oMoveFlags & OBJ_MOV_3)
        print_debug_top_down_objectinfo("DIVE    %x", gCurrentObject->oMoveFlags);
    if(gCurrentObject->oMoveFlags & OBJ_MOV_4)
        print_debug_top_down_objectinfo("S WATER %x", gCurrentObject->oMoveFlags);
    if(gCurrentObject->oMoveFlags & OBJ_MOV_5)
        print_debug_top_down_objectinfo("U WATER %x", gCurrentObject->oMoveFlags);
    if(gCurrentObject->oMoveFlags & OBJ_MOV_6)
        print_debug_top_down_objectinfo("B WATER %x", gCurrentObject->oMoveFlags);
    if(gCurrentObject->oMoveFlags & OBJ_MOV_7)
        print_debug_top_down_objectinfo("SKY     %x", gCurrentObject->oMoveFlags);
    if(gCurrentObject->oMoveFlags & OBJ_MOV_8)
        print_debug_top_down_objectinfo("OUT SCOPE %x", gCurrentObject->oMoveFlags);
}

// unused, what is this?
static void Unknown802CAA84(s16 *enemyArr)
{
    // copy b1-b4 over to an unknown s16 array
    enemyArr[4] = gDebugInfo[DEBUG_PAGE_ENEMYINFO][1];
    enemyArr[5] = gDebugInfo[DEBUG_PAGE_ENEMYINFO][2];
    enemyArr[6] = gDebugInfo[DEBUG_PAGE_ENEMYINFO][3];
    enemyArr[7] = gDebugInfo[DEBUG_PAGE_ENEMYINFO][4];
}
