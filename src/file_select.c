#include <ultra64.h>

#include "sm64.h"
#include "audio_interface_2.h"
#include "behavior_data.h"
#include "behavior_script.h"
#include "game.h"
#include "ingame_menu.h"
#include "object_helpers.h"
#include "math_util.h"
#include "area.h"
#include "save_file.h"
#include "spawn_object.h"

#include "text_strings.h"

enum
{
    MENU_BUTTON_NONE = -1,  // no button selected (on main menu screen)

    // Main Menu (SELECT FILE)
    MENU_BUTTON_PLAY_FILE_A,
    MENU_BUTTON_PLAY_FILE_B,
    MENU_BUTTON_PLAY_FILE_C,
    MENU_BUTTON_PLAY_FILE_D,
    MENU_BUTTON_SCORE,
    MENU_BUTTON_COPY,
    MENU_BUTTON_ERASE,

    // Score Menu (CHECK FILE)
    MENU_BUTTON_SCORE_FILE_A,
    MENU_BUTTON_SCORE_FILE_B,
    MENU_BUTTON_SCORE_FILE_C,
    MENU_BUTTON_SCORE_FILE_D,
    MENU_BUTTON_SCORE_RETURN,
    MENU_BUTTON_SCORE_COPY_FILE,
    MENU_BUTTON_SCORE_ERASE_FILE,

    // Copy Menu (COPY FILE)
    MENU_BUTTON_COPY_FILE_A,
    MENU_BUTTON_COPY_FILE_B,
    MENU_BUTTON_COPY_FILE_C,
    MENU_BUTTON_COPY_FILE_D,
    MENU_BUTTON_COPY_RETURN,
    MENU_BUTTON_COPY_CHECK_SCORE,
    MENU_BUTTON_COPY_ERASE_FILE,

    // Erase Menu (ERASE FILE)
    MENU_BUTTON_ERASE_FILE_A,
    MENU_BUTTON_ERASE_FILE_B,
    MENU_BUTTON_ERASE_FILE_C,
    MENU_BUTTON_ERASE_FILE_D,
    MENU_BUTTON_ERASE_RETURN,
    MENU_BUTTON_ERASE_CHECK_SCORE,
    MENU_BUTTON_ERASE_COPY_FILE,

    // Sound Mode Menu (SOUND SELECT)
    MENU_BUTTON_SOUND_MODE,
    MENU_BUTTON_STEREO,
    MENU_BUTTON_MONO,
    MENU_BUTTON_HEADSET
};

extern Gfx main_menu_seg7_dl_070073A0[];
extern Gfx D_070073B8[];
extern Gfx seg2_dl_0200ED00[];
extern Gfx seg2_dl_0200ED68[];
extern Gfx seg2_dl_0200EE68[];
extern Gfx seg2_dl_0200EEF0[];
extern Gfx main_menu_seg7_dl_0700D108[];
extern Gfx main_menu_seg7_dl_0700D160[];
extern u8 seg2_level_name_table[];

extern u32 gGlobalTimer;

struct Object *sMainMenuButtons[32];
u8 sYesNoColor[2];

static s8 sSelectedButtonId = -1;
static s8 D_801A7BD4 = 1;
static u8 sTextColorAlpha = 0;
static float sCursorPos[] = {0, 0};
static s16 D_801A7BE4 = 0;
s16 sClickPos[] = {-10000, -10000};
static s8 sSelectedFile = -1;
static s8 sFadeOutText = 0;
static s8 sStatusMessageId = 0;
static u8 sTextTransparency = 0;
static s16 D_801A7BFC = 0;
static s8 sSoundMode = 0;
static s8 D_801A7C04 = 0;
static s8 sAllFilesExist = 0;
static s8 D_801A7C0C = 0;
static s8 D_801A7C10 = 0;

// TODO: convert these strings

static unsigned char textReturn[] = {TEXT_RETURN};
static unsigned char textViewScore[] = {TEXT_CHECK_SCORE};
static unsigned char textFileCopy[] = {TEXT_COPY_FILE};
static unsigned char textFileDelete[] = {TEXT_FILE_DELETE};
static unsigned char textSoundModes[][8] = {
    {TEXT_STEREO},
    {TEXT_MONO},
    {TEXT_HEADSET}
};
static unsigned char textMarioA[] = {TEXT_MARIO_A};
static unsigned char textMarioB[] = {TEXT_MARIO_B};
static unsigned char textMarioC[] = {TEXT_MARIO_C};
static unsigned char textMarioD[] = {TEXT_MARIO_D};
static unsigned char textNew[] = {TEXT_NEW};
static unsigned char D_801A7C74[] = {0x35, 0xff};
static unsigned char D_801A7C78[] = {0x32, 0xff};
static unsigned char D_801A7C7C[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0xff};
static unsigned char textScore[] = {TEXT_SCORE};
static unsigned char textCopy[] = {TEXT_COPY};
static unsigned char textErase[] = {TEXT_ERASE};
static unsigned char D_801A7C98[] = {0x15, 0x16, 0x12, 0x09, 0x13, 0x08, 0x14, 0x0d, 0x17, 0xff};
static unsigned char textNoSavedDataExists[] = {TEXT_NO_SAVED_DATA_EXISTS};
static unsigned char D_801A7CB8[] = {0x00, 0x01, 0x02, 0x03, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0xff};
static unsigned char textCopyItToWhere[] = {TEXT_COPY_IT_TO_WHERE};
static unsigned char textNoSavedDataExists2[] = {TEXT_NO_SAVED_DATA_EXISTS};
static unsigned char textCopyFinished[] = {TEXT_COPYING_COMPLETED};
static unsigned char textSavedDataExists[] = {TEXT_SAVED_DATA_EXISTS};
static unsigned char textNoFileToCopyFrom[] = {TEXT_NO_FILE_TO_COPY_FROM};
static unsigned char textYes[] = {TEXT_YES};
static unsigned char textNo[] = {TEXT_NO};

void BehYellowBackgroundMenuInit(void)
{
    gCurrentObject->oFaceAngleYaw = 0x8000;
    gCurrentObject->oMainMenuButtonUnk108 = 9.0f;
}

void BehYellowBackgroundMenuLoop(void)
{
    ScaleObject(9.0f);
}

static int button_hittest(s16 x, s16 y, float c)
{
    float sp14 = 52.4213;
    float sp10 = ((float)x * 160.0) / (sp14 * c);
    float spC = ((float)y * 120.0) / (sp14 * 3.0f / 4.0f * c);
    s16 maxX = sp10 + 25.0f;
    s16 minX = sp10 - 25.0f;
    s16 maxY = spC + 21.0f;
    s16 minY = spC - 21.0f;

    if (sClickPos[0] < maxX && minX < sClickPos[0]
     && sClickPos[1] < maxY && minY < sClickPos[1])
        return TRUE;

    return FALSE;
}

static void func_801703E8(struct Object *a)
{
    if (a->oMainMenuButtonUnkF8 < 16)
        a->oFaceAngleYaw += 0x800;
    if (a->oMainMenuButtonUnkF8 < 8)
        a->oFaceAnglePitch += 0x800;
    if (a->oMainMenuButtonUnkF8 >= 8 && a->oMainMenuButtonUnkF8 < 16)
        a->oFaceAnglePitch -= 0x800;
    a->oUnk138 -= a->oMainMenuButtonUnkFC / 16.0;
    a->oUnk13C -= a->oMainMenuButtonUnk100 / 16.0;
    if (a->oPosZ < a->oMainMenuButtonUnk104 + 17800.0)
        a->oUnk140 += 1112.5;
    a->oMainMenuButtonUnkF8++;
    if (a->oMainMenuButtonUnkF8 == 16)
    {
        a->oUnk138 = 0.0f;
        a->oUnk13C = 0.0f;
        a->oMainMenuButtonUnkF4 = 2;
        a->oMainMenuButtonUnkF8 = 0;
    }
}

static void func_8017053C(struct Object *a)
{
    if (a->oMainMenuButtonUnkF8 < 16)
        a->oFaceAngleYaw -= 0x800;
    if (a->oMainMenuButtonUnkF8 < 8)
        a->oFaceAnglePitch -= 0x800;
    if (a->oMainMenuButtonUnkF8 >= 8 && a->oMainMenuButtonUnkF8 < 16)
        a->oFaceAnglePitch += 0x800;
    a->oUnk138 += a->oMainMenuButtonUnkFC / 16.0;
    a->oUnk13C += a->oMainMenuButtonUnk100 / 16.0;
    if (a->oPosZ > a->oMainMenuButtonUnk104)
        a->oUnk140 -= 1112.5;
    a->oMainMenuButtonUnkF8++;
    if (a->oMainMenuButtonUnkF8 == 16)
    {
        a->oUnk138 = a->oMainMenuButtonUnkFC;
        a->oUnk13C = a->oMainMenuButtonUnk100;
        a->oMainMenuButtonUnkF4 = 0;
        a->oMainMenuButtonUnkF8 = 0;
    }
}

static void func_80170670(struct Object *a)
{
    if (a->oMainMenuButtonUnkF8 < 16)
        a->oFaceAngleYaw += 0x800;
    if (a->oMainMenuButtonUnkF8 < 8)
        a->oFaceAnglePitch += 0x800;
    if (a->oMainMenuButtonUnkF8 >= 8 && a->oMainMenuButtonUnkF8 < 16)
        a->oFaceAnglePitch -= 0x800;
    a->oUnk138 -= a->oMainMenuButtonUnkFC / 16.0;
    a->oUnk13C -= a->oMainMenuButtonUnk100 / 16.0;
    a->oUnk140 -= 116.25;
    a->oMainMenuButtonUnkF8++;
    if (a->oMainMenuButtonUnkF8 == 16)
    {
        a->oUnk138 = 0.0f;
        a->oUnk13C = 0.0f;
        a->oMainMenuButtonUnkF4 = 2;
        a->oMainMenuButtonUnkF8 = 0;
    }
}

static void func_80170798(struct Object *a)
{
    if (a->oMainMenuButtonUnkF8 < 16)
        a->oFaceAngleYaw -= 0x800;
    if (a->oMainMenuButtonUnkF8 < 8)
        a->oFaceAnglePitch -= 0x800;
    if (a->oMainMenuButtonUnkF8 >= 8 && a->oMainMenuButtonUnkF8 < 16)
        a->oFaceAnglePitch += 0x800;
    a->oUnk138 += a->oMainMenuButtonUnkFC / 16.0;
    a->oUnk13C += a->oMainMenuButtonUnk100 / 16.0;
    if (a->oPosZ > a->oMainMenuButtonUnk104)
        a->oUnk140 += 116.25;
    a->oMainMenuButtonUnkF8++;
    if (a->oMainMenuButtonUnkF8 == 16)
    {
        a->oUnk138 = a->oMainMenuButtonUnkFC;
        a->oUnk13C = a->oMainMenuButtonUnk100;
        a->oMainMenuButtonUnkF4 = 0;
        a->oMainMenuButtonUnkF8 = 0;
    }
}

static void func_801708CC(struct Object *a)
{
    if (D_801A7BD4 == 1)
    {
        if (a->oMainMenuButtonUnkF8 < 4)
            a->oUnk140 -= 20.0f;
        if (a->oMainMenuButtonUnkF8 >= 4)
            a->oUnk140 += 20.0f;
    }
    else
    {
        if (a->oMainMenuButtonUnkF8 < 4)
            a->oUnk140 += 20.0f;
        if (a->oMainMenuButtonUnkF8 >= 4)
            a->oUnk140 -= 20.0f;
    }
    a->oMainMenuButtonUnkF8++;
    if (a->oMainMenuButtonUnkF8 == 8)
    {
        a->oMainMenuButtonUnkF4 = 0;
        a->oMainMenuButtonUnkF8 = 0;
    }
}

static void func_801709AC(struct Object *a)
{
    a->oMainMenuButtonUnk108 += 0.0022;
    a->oMainMenuButtonUnkF8++;
    if (a->oMainMenuButtonUnkF8 == 10)
    {
        a->oMainMenuButtonUnkF4 = 0;
        a->oMainMenuButtonUnkF8 = 0;
    }
}

static void func_801709FC(struct Object *a)
{
    a->oMainMenuButtonUnk108 -= 0.0022;
    a->oMainMenuButtonUnkF8++;
    if (a->oMainMenuButtonUnkF8 == 10)
    {
        a->oMainMenuButtonUnkF4 = 0;
        a->oMainMenuButtonUnkF8 = 0;
    }
}

void BehMenuGrowingButtonInit(void)
{
    gCurrentObject->oMainMenuButtonUnkFC = gCurrentObject->oUnk138;
    gCurrentObject->oMainMenuButtonUnk100 = gCurrentObject->oUnk13C;
}

void BehMenuGrowingButtonLoop(void)
{
    switch (gCurrentObject->oMainMenuButtonUnkF4)
    {
    case 0:
        gCurrentObject->oMainMenuButtonUnk104 = gCurrentObject->oPosZ;
        break;
    case 1:
        if (D_801A7BD4 == 1)
            func_801703E8(gCurrentObject);
        if (D_801A7BD4 == 2)
            func_80170670(gCurrentObject);
        sTextColorAlpha = 0;
        D_801A7BE4 = 4;
        break;
    case 2:
        break;
    case 3:
        if (D_801A7BD4 == 1)
            func_8017053C(gCurrentObject);
        if (D_801A7BD4 == 2)
            func_80170798(gCurrentObject);
        sTextColorAlpha = 0;
        D_801A7BE4 = 4;
        break;
    case 4:
        func_801708CC(gCurrentObject);
        D_801A7BE4 = 4;
        break;
    case 5:
        func_801709AC(gCurrentObject);
        D_801A7BE4 = 4;
        break;
    case 6:
        func_801709FC(gCurrentObject);
        D_801A7BE4 = 4;
        break;
    }
    ScaleObject(gCurrentObject->oMainMenuButtonUnk108);
}

static void func_80170C14(struct Object *a, s8 buttonId)
{
    if (a->oMainMenuButtonUnkF4 == 2 && D_801A7BE4 == 2)
    {
        SetSound(SOUND_MENU_CAMERAZOOMOUT, D_803320E0);
        a->oMainMenuButtonUnkF4 = 3;
    }
    if (a->oMainMenuButtonUnkF4 == 0)
    {
        sSelectedButtonId = buttonId;
        if (D_801A7BD4 == 2)
            D_801A7BD4 = 1;
    }
}

static void score_menu_create_buttons(struct Object *a)
{
    if (save_file_exists(0) == TRUE)
    {
        sMainMenuButtons[MENU_BUTTON_SCORE_FILE_A] = func_8029E2A8(a, 3, beh_menu_growing_button, 711, 311,
            -100, 0, -0x8000, 0);
    }
    else
    {
        sMainMenuButtons[MENU_BUTTON_SCORE_FILE_A] = func_8029E2A8(a, 9, beh_menu_growing_button, 711, 311,
            -100, 0, -0x8000, 0);
    }
    sMainMenuButtons[MENU_BUTTON_SCORE_FILE_A]->oMainMenuButtonUnk108 = 0.11111111f;

    if (save_file_exists(1) == TRUE)
    {
        sMainMenuButtons[MENU_BUTTON_SCORE_FILE_B] = func_8029E2A8(a, 3, beh_menu_growing_button, -166, 311,
            -100, 0, -0x8000, 0);
    }
    else
    {
        sMainMenuButtons[MENU_BUTTON_SCORE_FILE_B] = func_8029E2A8(a, 9, beh_menu_growing_button, -166, 311,
            -100, 0, -0x8000, 0);
    }
    sMainMenuButtons[MENU_BUTTON_SCORE_FILE_B]->oMainMenuButtonUnk108 = 0.11111111f;

    if (save_file_exists(2) == TRUE)
    {
        sMainMenuButtons[MENU_BUTTON_SCORE_FILE_C] = func_8029E2A8(a, 3, beh_menu_growing_button, 711, 0,
            -100, 0, -0x8000, 0);
    }
    else
    {
        sMainMenuButtons[MENU_BUTTON_SCORE_FILE_C] = func_8029E2A8(a, 9, beh_menu_growing_button, 711, 0,
            -100, 0, -0x8000, 0);
    }
    sMainMenuButtons[MENU_BUTTON_SCORE_FILE_C]->oMainMenuButtonUnk108 = 0.11111111f;

    if (save_file_exists(3) == TRUE)
    {
        sMainMenuButtons[MENU_BUTTON_SCORE_FILE_D] = func_8029E2A8(a, 3, beh_menu_growing_button, -166, 0,
            -100, 0, -0x8000, 0);
    }
    else
    {
        sMainMenuButtons[MENU_BUTTON_SCORE_FILE_D] = func_8029E2A8(a, 9, beh_menu_growing_button, -166, 0,
            -100, 0, -0x8000, 0);
    }
    sMainMenuButtons[MENU_BUTTON_SCORE_FILE_D]->oMainMenuButtonUnk108 = 0.11111111f;

    sMainMenuButtons[MENU_BUTTON_SCORE_RETURN] = func_8029E2A8(a, 6, beh_menu_growing_button, 711, -388,
        -100, 0, -0x8000, 0);
    sMainMenuButtons[MENU_BUTTON_SCORE_RETURN]->oMainMenuButtonUnk108 = 0.11111111f;

    sMainMenuButtons[MENU_BUTTON_SCORE_COPY_FILE] = func_8029E2A8(a, 5, beh_menu_growing_button, 0, -388,
        -100, 0, -0x8000, 0);
    sMainMenuButtons[MENU_BUTTON_SCORE_COPY_FILE]->oMainMenuButtonUnk108 = 0.11111111f;

    sMainMenuButtons[MENU_BUTTON_SCORE_ERASE_FILE] = func_8029E2A8(a, 4, beh_menu_growing_button, -711, -388,
        -100, 0, -0x8000, 0);
    sMainMenuButtons[MENU_BUTTON_SCORE_ERASE_FILE]->oMainMenuButtonUnk108 = 0.11111111f;
}

static void score_menu_handle_click(struct Object *a)
{
    if (a->oMainMenuButtonUnkF4 == 2)
    {
        int buttonId;

        for (buttonId = 7; buttonId < 14; buttonId++)
        {
            s16 buttonX = sMainMenuButtons[buttonId]->oPosX;
            s16 buttonY = sMainMenuButtons[buttonId]->oPosY;

            if (button_hittest(buttonX, buttonY, 22.0f) == TRUE && D_801A7BFC >= 31)
            {
                if (buttonId == MENU_BUTTON_SCORE_RETURN
                 || buttonId == MENU_BUTTON_SCORE_COPY_FILE
                 || buttonId == MENU_BUTTON_SCORE_ERASE_FILE)
                {
                    SetSound(SOUND_MENU_CLICKFILESELECT, D_803320E0);
                    sMainMenuButtons[buttonId]->oMainMenuButtonUnkF4 = 4;
                    sSelectedButtonId = buttonId;
                }
                else
                {
                    if (D_801A7BFC >= 31)
                    {
                        if (save_file_exists(buttonId - 7) == TRUE)
                        {
                            SetSound(SOUND_MENU_CAMERAZOOMIN, D_803320E0);
                            sMainMenuButtons[buttonId]->oMainMenuButtonUnkF4 = 1;
                            sSelectedButtonId = buttonId;
                        }
                        else
                        {
                            SetSound(SOUND_MENU_CAMERABUZZ, D_803320E0);
                            sMainMenuButtons[buttonId]->oMainMenuButtonUnkF4 = 4;
                            if (D_801A7BFC >= 31)
                            {
                                sFadeOutText = 1;
                                D_801A7BFC = 0;
                            }
                        }
                    }
                }
                D_801A7BD4 = 2;
                break;
            }
        }
    }
}

static void copy_menu_create_buttons(struct Object * a)
{
    if (save_file_exists(0) == TRUE)
    {
        sMainMenuButtons[MENU_BUTTON_COPY_FILE_A] = func_8029E2A8(a, 3, beh_menu_growing_button, 711, 311,
            -100, 0, -0x8000, 0);
    }
    else
    {
        sMainMenuButtons[MENU_BUTTON_COPY_FILE_A] = func_8029E2A8(a, 9, beh_menu_growing_button, 711, 311,
            -100, 0, -0x8000, 0);
    }
    sMainMenuButtons[MENU_BUTTON_COPY_FILE_A]->oMainMenuButtonUnk108 = 0.11111111f;

    if (save_file_exists(1) == TRUE)
    {
        sMainMenuButtons[MENU_BUTTON_COPY_FILE_B] = func_8029E2A8(a, 3, beh_menu_growing_button, -166, 311,
            -100, 0, -0x8000, 0);
    }
    else
    {
        sMainMenuButtons[MENU_BUTTON_COPY_FILE_B] = func_8029E2A8(a, 9, beh_menu_growing_button, -166, 311,
            -100, 0, -0x8000, 0);
    }
    sMainMenuButtons[MENU_BUTTON_COPY_FILE_B]->oMainMenuButtonUnk108 = 0.11111111f;

    if (save_file_exists(2) == TRUE)
    {
        sMainMenuButtons[MENU_BUTTON_COPY_FILE_C] = func_8029E2A8(a, 3, beh_menu_growing_button, 711, 0,
            -100, 0, -0x8000, 0);
    }
    else
    {
        sMainMenuButtons[MENU_BUTTON_COPY_FILE_C] = func_8029E2A8(a, 9, beh_menu_growing_button, 711, 0,
            -100, 0, -0x8000, 0);
    }
    sMainMenuButtons[MENU_BUTTON_COPY_FILE_C]->oMainMenuButtonUnk108 = 0.11111111f;

    if (save_file_exists(3) == TRUE)
    {
        sMainMenuButtons[MENU_BUTTON_COPY_FILE_D] = func_8029E2A8(a, 3, beh_menu_growing_button, -166, 0,
            -100, 0, -0x8000, 0);
    }
    else
    {
        sMainMenuButtons[MENU_BUTTON_COPY_FILE_D] = func_8029E2A8(a, 9, beh_menu_growing_button, -166, 0,
            -100, 0, -0x8000, 0);
    }
    sMainMenuButtons[MENU_BUTTON_COPY_FILE_D]->oMainMenuButtonUnk108 = 0.11111111f;

    sMainMenuButtons[MENU_BUTTON_COPY_RETURN] = func_8029E2A8(a, 6, beh_menu_growing_button, 711, -388,
        -100, 0, -0x8000, 0);
    sMainMenuButtons[MENU_BUTTON_COPY_RETURN]->oMainMenuButtonUnk108 = 0.11111111f;

    sMainMenuButtons[MENU_BUTTON_COPY_CHECK_SCORE] = func_8029E2A8(a, 7, beh_menu_growing_button, 0, -388,
        -100, 0, -0x8000, 0);
    sMainMenuButtons[MENU_BUTTON_COPY_CHECK_SCORE]->oMainMenuButtonUnk108 = 0.11111111f;

    sMainMenuButtons[MENU_BUTTON_COPY_ERASE_FILE] = func_8029E2A8(a, 4, beh_menu_growing_button, -711, -388,
        -100, 0, -0x8000, 0);
    sMainMenuButtons[MENU_BUTTON_COPY_ERASE_FILE]->oMainMenuButtonUnk108 = 0.11111111f;
}

static void func_801716E4(struct Object *a, int buttonId)
{
    switch (a->oMainMenuButtonUnk10C)
    {
    case 0:
        if (sAllFilesExist == TRUE)
            return;
        if (save_file_exists(buttonId - 14) == TRUE)
        {
            SetSound(SOUND_MENU_CLICKFILESELECT, D_803320E0);
            sMainMenuButtons[buttonId]->oMainMenuButtonUnkF4 = 5;
            sSelectedFile = buttonId - 14;
            a->oMainMenuButtonUnk10C = 1;
            sFadeOutText = 1;
            D_801A7BFC = 0;
        }
        else
        {
            SetSound(SOUND_MENU_CAMERABUZZ, D_803320E0);
            sMainMenuButtons[buttonId]->oMainMenuButtonUnkF4 = 4;
            if (D_801A7BFC >= 21)
            {
                sFadeOutText = 1;
                D_801A7BFC = 0;
            }
        }
        break;
    case 1:
        sMainMenuButtons[buttonId]->oMainMenuButtonUnkF4 = 4;
        if (save_file_exists(buttonId - 14) == FALSE)
        {
            SetSound(SOUND_MENU_STARSOUND, D_803320E0);
            a->oMainMenuButtonUnk10C = 2;
            sFadeOutText = 1;
            D_801A7BFC = 0;
            save_file_copy(sSelectedFile, buttonId - 14);
            sMainMenuButtons[buttonId]->header.gfx.asGraphNode = gLoadedGraphNodes[8];
            sMainMenuButtons[buttonId - 14]->header.gfx.asGraphNode = gLoadedGraphNodes[8];
        }
        else
        {
            if (MENU_BUTTON_COPY_FILE_A + sSelectedFile == buttonId)
            {
                SetSound(SOUND_MENU_CAMERABUZZ, D_803320E0);
                sMainMenuButtons[MENU_BUTTON_COPY_FILE_A + sSelectedFile]->oMainMenuButtonUnkF4 = 6;
                a->oMainMenuButtonUnk10C = 0;
                sFadeOutText = 1;
                return;
            }
            if (D_801A7BFC >= 21)
            {
                sFadeOutText = 1;
                D_801A7BFC = 0;
            }
        }
        break;
    }
}

static void copy_menu_handle_click(struct Object *a)
{
    if (a->oMainMenuButtonUnkF4 == 2)
    {
        int buttonId;

        for (buttonId = 14; buttonId < 21; buttonId++)
        {
            s16 buttonX = sMainMenuButtons[buttonId]->oPosX;
            s16 buttonY = sMainMenuButtons[buttonId]->oPosY;

            if (button_hittest(buttonX, buttonY, 22.0f) == TRUE)
            {
                if (buttonId == MENU_BUTTON_COPY_RETURN
                 || buttonId == MENU_BUTTON_COPY_CHECK_SCORE
                 || buttonId == MENU_BUTTON_COPY_ERASE_FILE)
                {
                    if (a->oMainMenuButtonUnk10C == 0)
                    {
                        SetSound(SOUND_MENU_CLICKFILESELECT, D_803320E0);
                        sMainMenuButtons[buttonId]->oMainMenuButtonUnkF4 = 4;
                        sSelectedButtonId = buttonId;
                    }
                }
                else
                {
                    if (sMainMenuButtons[buttonId]->oMainMenuButtonUnkF4 == 0 && D_801A7BFC >= 31)
                        func_801716E4(a, buttonId);
                }
                D_801A7BD4 = 2;
                break;
            }
        }
        if (a->oMainMenuButtonUnk10C == 2 && D_801A7BFC >= 31)
        {
            a->oMainMenuButtonUnk10C = 0;
            sMainMenuButtons[MENU_BUTTON_COPY_FILE_A + sSelectedFile]->oMainMenuButtonUnkF4 = 6;
        }
    }
}

static void erase_menu_create_buttons(struct Object *a)
{
    if (save_file_exists(0) == TRUE)
    {
        sMainMenuButtons[MENU_BUTTON_ERASE_FILE_A] = func_8029E2A8(a, 3, beh_menu_growing_button, 711, 311,
            -100, 0, -0x8000, 0);
    }
    else
    {
        sMainMenuButtons[MENU_BUTTON_ERASE_FILE_A] = func_8029E2A8(a, 9, beh_menu_growing_button, 711, 311,
            -100, 0, -0x8000, 0);
    }
    sMainMenuButtons[MENU_BUTTON_ERASE_FILE_A]->oMainMenuButtonUnk108 = 0.11111111f;

    if (save_file_exists(1) == TRUE)
    {
        sMainMenuButtons[MENU_BUTTON_ERASE_FILE_B] = func_8029E2A8(a, 3, beh_menu_growing_button, -166, 311,
            -100, 0, -0x8000, 0);
    }
    else
    {
        sMainMenuButtons[MENU_BUTTON_ERASE_FILE_B] = func_8029E2A8(a, 9, beh_menu_growing_button, -166, 311,
            -100, 0, -0x8000, 0);
    }
    sMainMenuButtons[MENU_BUTTON_ERASE_FILE_B]->oMainMenuButtonUnk108 = 0.11111111f;

    if (save_file_exists(2) == TRUE)
    {
        sMainMenuButtons[MENU_BUTTON_ERASE_FILE_C] = func_8029E2A8(a, 3, beh_menu_growing_button, 711, 0,
            -100, 0, -0x8000, 0);
    }
    else
    {
        sMainMenuButtons[MENU_BUTTON_ERASE_FILE_C] = func_8029E2A8(a, 9, beh_menu_growing_button, 711, 0,
            -100, 0, -0x8000, 0);
    }
    sMainMenuButtons[MENU_BUTTON_ERASE_FILE_C]->oMainMenuButtonUnk108 = 0.11111111f;

    if (save_file_exists(3) == TRUE)
    {
        sMainMenuButtons[MENU_BUTTON_ERASE_FILE_D] = func_8029E2A8(a, 3, beh_menu_growing_button, -166, 0,
            -100, 0, -0x8000, 0);
    }
    else
    {
        sMainMenuButtons[MENU_BUTTON_ERASE_FILE_D] = func_8029E2A8(a, 9, beh_menu_growing_button, -166, 0,
            -100, 0, -0x8000, 0);
    }
    sMainMenuButtons[MENU_BUTTON_ERASE_FILE_D]->oMainMenuButtonUnk108 = 0.11111111f;

    sMainMenuButtons[MENU_BUTTON_ERASE_RETURN] = func_8029E2A8(a, 6, beh_menu_growing_button, 711, -388,
        -100, 0, -0x8000, 0);
    sMainMenuButtons[MENU_BUTTON_ERASE_RETURN]->oMainMenuButtonUnk108 = 0.11111111f;

    sMainMenuButtons[MENU_BUTTON_ERASE_CHECK_SCORE] = func_8029E2A8(a, 7, beh_menu_growing_button, 0, -388,
        -100, 0, -0x8000, 0);
    sMainMenuButtons[MENU_BUTTON_ERASE_CHECK_SCORE]->oMainMenuButtonUnk108 = 0.11111111f;

    sMainMenuButtons[MENU_BUTTON_ERASE_COPY_FILE] = func_8029E2A8(a, 5, beh_menu_growing_button, -711, -388,
        -100, 0, -0x8000, 0);
    sMainMenuButtons[MENU_BUTTON_ERASE_COPY_FILE]->oMainMenuButtonUnk108 = 0.11111111f;
}

static void func_80171F74(struct Object *a, int buttonId)
{
    switch (a->oMainMenuButtonUnk10C)
    {
    case 0:
        if (save_file_exists(buttonId - MENU_BUTTON_ERASE_FILE_A) == TRUE)
        {
            SetSound(SOUND_MENU_CLICKFILESELECT, D_803320E0);
            sMainMenuButtons[buttonId]->oMainMenuButtonUnkF4 = 5;
            sSelectedFile = buttonId - MENU_BUTTON_ERASE_FILE_A;
            a->oMainMenuButtonUnk10C = 1;
            sFadeOutText = 1;
            D_801A7BFC = 0;
        }
        else
        {
            SetSound(SOUND_MENU_CAMERABUZZ, D_803320E0);
            sMainMenuButtons[buttonId]->oMainMenuButtonUnkF4 = 4;
            if (D_801A7BFC >= 21)
            {
                sFadeOutText = 1;
                D_801A7BFC = 0;
            }
        }
        break;
    case 1:
        if (MENU_BUTTON_ERASE_FILE_A + sSelectedFile == buttonId)
        {
            SetSound(SOUND_MENU_CLICKFILESELECT, D_803320E0);
            sMainMenuButtons[MENU_BUTTON_ERASE_FILE_A + sSelectedFile]->oMainMenuButtonUnkF4 = 6;
            a->oMainMenuButtonUnk10C = 0;
            sFadeOutText = 1;
        }
        break;
    }
}

static void erase_menu_handle_click(struct Object *a)
{
    if (a->oMainMenuButtonUnkF4 == 2)
    {
        int buttonId;

        for (buttonId = 21; buttonId < 28; buttonId++)
        {
            s16 buttonX = sMainMenuButtons[buttonId]->oPosX;
            s16 buttonY = sMainMenuButtons[buttonId]->oPosY;

            if (button_hittest(buttonX, buttonY, 22.0f) == TRUE)
            {
                if (buttonId == MENU_BUTTON_ERASE_RETURN
                 || buttonId == MENU_BUTTON_ERASE_CHECK_SCORE
                 || buttonId == MENU_BUTTON_ERASE_COPY_FILE)
                {
                    if (a->oMainMenuButtonUnk10C == 0)
                    {
                        SetSound(SOUND_MENU_CLICKFILESELECT, D_803320E0);
                        sMainMenuButtons[buttonId]->oMainMenuButtonUnkF4 = 4;
                        sSelectedButtonId = buttonId;
                    }
                }
                else
                {
                    if (D_801A7BFC >= 31)
                        func_80171F74(a, buttonId);
                }
                D_801A7BD4 = 2;
                break;
            }
        }
        if (a->oMainMenuButtonUnk10C == 2 && D_801A7BFC >= 31)
        {
            a->oMainMenuButtonUnk10C = 0;
            sMainMenuButtons[MENU_BUTTON_ERASE_FILE_A + sSelectedFile]->oMainMenuButtonUnkF4 = 6;
        }
    }
}

static void sound_select_menu_create_buttons(struct Object *a)
{
    sMainMenuButtons[MENU_BUTTON_STEREO] = func_8029E2A8(a, 12, beh_menu_growing_button, 533, 0,
        -100, 0, -0x8000, 0);
    sMainMenuButtons[MENU_BUTTON_STEREO]->oMainMenuButtonUnk108 = 0.11111111f;

    sMainMenuButtons[MENU_BUTTON_MONO] = func_8029E2A8(a, 12, beh_menu_growing_button, 0, 0,
        -100, 0, -0x8000, 0);
    sMainMenuButtons[MENU_BUTTON_MONO]->oMainMenuButtonUnk108 = 0.11111111f;

    sMainMenuButtons[MENU_BUTTON_HEADSET] = func_8029E2A8(a, 12, beh_menu_growing_button, -533, 0,
        -100, 0, -0x8000, 0);
    sMainMenuButtons[MENU_BUTTON_HEADSET]->oMainMenuButtonUnk108 = 0.11111111f;

    sMainMenuButtons[29 + sSoundMode]->oMainMenuButtonUnkF4 = 5;
}

static void sound_select_menu_handle_click(struct Object *a)
{
    if (a->oMainMenuButtonUnkF4 == 2)
    {
        int buttonId;

        for (buttonId = 29; buttonId < 32; buttonId++)
        {
            s16 buttonX = sMainMenuButtons[buttonId]->oPosX;
            s16 buttonY = sMainMenuButtons[buttonId]->oPosY;

            if (button_hittest(buttonX, buttonY, 22.0f) == TRUE)
            {
                if (buttonId == MENU_BUTTON_STEREO
                 || buttonId == MENU_BUTTON_MONO
                 || buttonId == MENU_BUTTON_HEADSET)
                {
                    if (a->oMainMenuButtonUnk10C == 0)
                    {
                        SetSound(SOUND_MENU_CLICKFILESELECT, D_803320E0);
                        sMainMenuButtons[buttonId]->oMainMenuButtonUnkF4 = 4;
                        sSelectedButtonId = buttonId;
                        sSoundMode = buttonId - 29;
                        save_file_set_sound_mode(sSoundMode);
                    }
                }
                D_801A7BD4 = 2;
                break;
            }
        }
    }
}

static void func_8017257C(struct Object *a, int b)
{
    if (a->oMainMenuButtonUnkF4 == 2)
        D_801A7C0C = b;
}

static void main_menu_init(s16 buttonId, struct Object *b)
{
    int sp1C;

    if (b->oMainMenuButtonUnkF4 == 0 && sMainMenuButtons[buttonId]->oMainMenuButtonUnkF4 == 2)
    {
        SetSound(SOUND_MENU_CAMERAZOOMOUT, D_803320E0);
        sMainMenuButtons[buttonId]->oMainMenuButtonUnkF4 = 3;
        D_801A7BD4 = 1;
    }
    if (sMainMenuButtons[buttonId]->oMainMenuButtonUnkF4 == 0)
    {
        sSelectedButtonId = -1;
        if (buttonId == MENU_BUTTON_SCORE)
        {
            for (sp1C = 7; sp1C < 14; sp1C++)
                hide_object(sMainMenuButtons[sp1C]);
        }
        if (buttonId == MENU_BUTTON_COPY)
        {
            for (sp1C = 14; sp1C < 21; sp1C++)
                hide_object(sMainMenuButtons[sp1C]);
        }
        if (buttonId == MENU_BUTTON_ERASE)
        {
            for (sp1C = 21; sp1C < 28; sp1C++)
                hide_object(sMainMenuButtons[sp1C]);
        }
        if (buttonId == MENU_BUTTON_SOUND_MODE)
        {
            for (sp1C = 29; sp1C < 32; sp1C++)
                hide_object(sMainMenuButtons[sp1C]);
        }
    }
}

static void score_menu_init(s16 buttonId, struct Object *b)
{
    int sp1C;

    if (b->oMainMenuButtonUnkF4 == 0 && sMainMenuButtons[buttonId]->oMainMenuButtonUnkF4 == 2)
    {
        SetSound(SOUND_MENU_CAMERAZOOMOUT, D_803320E0);
        sMainMenuButtons[buttonId]->oMainMenuButtonUnkF4 = 3;
        D_801A7BD4 = 1;
    }
    if (sMainMenuButtons[buttonId]->oMainMenuButtonUnkF4 == 0)
    {
        if (buttonId == MENU_BUTTON_SCORE)
        {
            for (sp1C = 7; sp1C < 14; sp1C++)
                hide_object(sMainMenuButtons[sp1C]);
        }
        if (buttonId == MENU_BUTTON_COPY)
        {
            for (sp1C = 14; sp1C < 21; sp1C++)
                hide_object(sMainMenuButtons[sp1C]);
        }
        if (buttonId == MENU_BUTTON_ERASE)
        {
            for (sp1C = 21; sp1C < 28; sp1C++)
                hide_object(sMainMenuButtons[sp1C]);
        }
        sSelectedButtonId = MENU_BUTTON_SCORE;
        SetSound(SOUND_MENU_CAMERAZOOMIN, D_803320E0);
        sMainMenuButtons[MENU_BUTTON_SCORE]->oMainMenuButtonUnkF4 = 1;
        score_menu_create_buttons(sMainMenuButtons[MENU_BUTTON_SCORE]);
    }
}

static void copy_menu_init(s16 buttonId, struct Object *b)
{
    int sp1C;

    if (b->oMainMenuButtonUnkF4 == 0 && sMainMenuButtons[buttonId]->oMainMenuButtonUnkF4 == 2)
    {
        SetSound(SOUND_MENU_CAMERAZOOMOUT, D_803320E0);
        sMainMenuButtons[buttonId]->oMainMenuButtonUnkF4 = 3;
        D_801A7BD4 = 1;
    }
    if (sMainMenuButtons[buttonId]->oMainMenuButtonUnkF4 == 0)
    {
        if (buttonId == MENU_BUTTON_SCORE)
        {
            for (sp1C = 7; sp1C < 14; sp1C++)
                hide_object(sMainMenuButtons[sp1C]);
        }
        if (buttonId == MENU_BUTTON_COPY)
        {
            for (sp1C = 14; sp1C < 21; sp1C++)
                hide_object(sMainMenuButtons[sp1C]);
        }
        if (buttonId == MENU_BUTTON_ERASE)
        {
            for (sp1C = 21; sp1C < 28; sp1C++)
                hide_object(sMainMenuButtons[sp1C]);
        }
        sSelectedButtonId = MENU_BUTTON_COPY;
        SetSound(SOUND_MENU_CAMERAZOOMIN, D_803320E0);
        sMainMenuButtons[MENU_BUTTON_COPY]->oMainMenuButtonUnkF4 = 1;
        copy_menu_create_buttons(sMainMenuButtons[MENU_BUTTON_COPY]);
    }
}

static void erase_menu_init(s16 buttonId, struct Object *b)
{
    int sp1C;

    if (b->oMainMenuButtonUnkF4 == 0 && sMainMenuButtons[buttonId]->oMainMenuButtonUnkF4 == 2)
    {
        SetSound(SOUND_MENU_CAMERAZOOMOUT, D_803320E0);
        sMainMenuButtons[buttonId]->oMainMenuButtonUnkF4 = 3;
        D_801A7BD4 = 1;
    }
    if (sMainMenuButtons[buttonId]->oMainMenuButtonUnkF4 == 0)
    {
        if (buttonId == MENU_BUTTON_SCORE)
        {
            for (sp1C = 7; sp1C < 14; sp1C++)
                hide_object(sMainMenuButtons[sp1C]);
        }
        if (buttonId == MENU_BUTTON_COPY)
        {
            for (sp1C = 14; sp1C < 21; sp1C++)
                hide_object(sMainMenuButtons[sp1C]);
        }
        if (buttonId == MENU_BUTTON_ERASE)
        {
            for (sp1C = 21; sp1C < 28; sp1C++)
                hide_object(sMainMenuButtons[sp1C]);
        }
        sSelectedButtonId = MENU_BUTTON_ERASE;
        SetSound(SOUND_MENU_CAMERAZOOMIN, D_803320E0);
        sMainMenuButtons[MENU_BUTTON_ERASE]->oMainMenuButtonUnkF4 = 1;
        erase_menu_create_buttons(sMainMenuButtons[MENU_BUTTON_ERASE]);
    }
}

void BehGreyButtonInit(void)
{
    if (save_file_exists(0) == TRUE)
    {
        sMainMenuButtons[MENU_BUTTON_PLAY_FILE_A] = func_8029E2A8(gCurrentObject, 8, beh_menu_growing_button,
            -6400, 2800, 0, 0, 0, 0);
    }
    else
    {
        sMainMenuButtons[MENU_BUTTON_PLAY_FILE_A] = func_8029E2A8(gCurrentObject, 10, beh_menu_growing_button,
            -6400, 2800, 0, 0, 0, 0);
    }
    sMainMenuButtons[MENU_BUTTON_PLAY_FILE_A]->oMainMenuButtonUnk108 = 1.0f;

    if (save_file_exists(1) == TRUE)
    {
        sMainMenuButtons[MENU_BUTTON_PLAY_FILE_B] = func_8029E2A8(gCurrentObject, 8, beh_menu_growing_button,
            1500, 2800, 0, 0, 0, 0);
    }
    else
    {
        sMainMenuButtons[MENU_BUTTON_PLAY_FILE_B] = func_8029E2A8(gCurrentObject, 10, beh_menu_growing_button,
            1500, 2800, 0, 0, 0, 0);
    }
    sMainMenuButtons[MENU_BUTTON_PLAY_FILE_B]->oMainMenuButtonUnk108 = 1.0f;

    if (save_file_exists(2) == TRUE)
    {
        sMainMenuButtons[MENU_BUTTON_PLAY_FILE_C] = func_8029E2A8(gCurrentObject, 8, beh_menu_growing_button,
            -6400, 0, 0, 0, 0, 0);
    }
    else
    {
        sMainMenuButtons[MENU_BUTTON_PLAY_FILE_C] = func_8029E2A8(gCurrentObject, 10, beh_menu_growing_button,
            -6400, 0, 0, 0, 0, 0);
    }
    sMainMenuButtons[MENU_BUTTON_PLAY_FILE_C]->oMainMenuButtonUnk108 = 1.0f;

    if (save_file_exists(3) == TRUE)
    {
        sMainMenuButtons[MENU_BUTTON_PLAY_FILE_D] = func_8029E2A8(gCurrentObject, 8, beh_menu_growing_button,
            1500, 0, 0, 0, 0, 0);
    }
    else
    {
        sMainMenuButtons[MENU_BUTTON_PLAY_FILE_D] = func_8029E2A8(gCurrentObject, 10, beh_menu_growing_button,
            1500, 0, 0, 0, 0, 0);
    }
    sMainMenuButtons[MENU_BUTTON_PLAY_FILE_D]->oMainMenuButtonUnk108 = 1.0f;

    sMainMenuButtons[MENU_BUTTON_SCORE] = func_8029E2A8(gCurrentObject, 7, beh_menu_growing_button,
        -6400, -3500, 0, 0, 0, 0);
    sMainMenuButtons[MENU_BUTTON_SCORE]->oMainMenuButtonUnk108 = 1.0f;

    sMainMenuButtons[MENU_BUTTON_COPY] = func_8029E2A8(gCurrentObject, 5, beh_menu_growing_button,
        -2134, -3500, 0, 0, 0, 0);
    sMainMenuButtons[MENU_BUTTON_COPY]->oMainMenuButtonUnk108 = 1.0f;

    sMainMenuButtons[MENU_BUTTON_ERASE] = func_8029E2A8(gCurrentObject, 4, beh_menu_growing_button,
        2134, -3500, 0, 0, 0, 0);
    sMainMenuButtons[MENU_BUTTON_ERASE]->oMainMenuButtonUnk108 = 1.0f;

    sMainMenuButtons[MENU_BUTTON_SOUND_MODE] = func_8029E2A8(gCurrentObject, 11, beh_menu_growing_button,
        6400, -3500, 0, 0, 0, 0);
    sMainMenuButtons[MENU_BUTTON_SOUND_MODE]->oMainMenuButtonUnk108 = 1.0f;

    sTextColorAlpha = 0;
}

static void main_menu_handle_click(void)
{
    if (button_hittest(
        sMainMenuButtons[MENU_BUTTON_SOUND_MODE]->oPosX,
        sMainMenuButtons[MENU_BUTTON_SOUND_MODE]->oPosY, 200.0f) == TRUE)
    {
        sMainMenuButtons[MENU_BUTTON_SOUND_MODE]->oMainMenuButtonUnkF4 = 1;
        sSelectedButtonId = MENU_BUTTON_SOUND_MODE;
    }
    else
    {
        s8 buttonId;

        for (buttonId = 0; buttonId < 7; buttonId++)
        {
            s16 buttonX = sMainMenuButtons[buttonId]->oPosX;
            s16 buttonY = sMainMenuButtons[buttonId]->oPosY;

            if (button_hittest(buttonX, buttonY, 200.0f) == TRUE)
            {
                sMainMenuButtons[buttonId]->oMainMenuButtonUnkF4 = 1;
                sSelectedButtonId = buttonId;
                break;
            }
        }
    }

    switch (sSelectedButtonId)
    {
    case MENU_BUTTON_PLAY_FILE_A:
        SetSound(SOUND_MENU_STARSOUND, D_803320E0);
        break;
    case MENU_BUTTON_PLAY_FILE_B:
        SetSound(SOUND_MENU_STARSOUND, D_803320E0);
        break;
    case MENU_BUTTON_PLAY_FILE_C:
        SetSound(SOUND_MENU_STARSOUND, D_803320E0);
        break;
    case MENU_BUTTON_PLAY_FILE_D:
        SetSound(SOUND_MENU_STARSOUND, D_803320E0);
        break;
    case 4:
        SetSound(SOUND_MENU_CAMERAZOOMIN, D_803320E0);
        score_menu_create_buttons(sMainMenuButtons[MENU_BUTTON_SCORE]);
        break;
    case 5:
        SetSound(SOUND_MENU_CAMERAZOOMIN, D_803320E0);
        copy_menu_create_buttons(sMainMenuButtons[MENU_BUTTON_COPY]);
        break;
    case 6:
        SetSound(SOUND_MENU_CAMERAZOOMIN, D_803320E0);
        erase_menu_create_buttons(sMainMenuButtons[MENU_BUTTON_ERASE]);
        break;
    case MENU_BUTTON_SOUND_MODE:
        SetSound(SOUND_MENU_CAMERAZOOMIN, D_803320E0);
        sound_select_menu_create_buttons(sMainMenuButtons[MENU_BUTTON_SOUND_MODE]);
        break;
    }
}

void BehGreyButtonLoop(void)
{
    switch (sSelectedButtonId)
    {
    case -1:
        main_menu_handle_click();
        break;
    case MENU_BUTTON_PLAY_FILE_A:
        func_8017257C(sMainMenuButtons[MENU_BUTTON_PLAY_FILE_A], 1);
        break;
    case MENU_BUTTON_PLAY_FILE_B:
        func_8017257C(sMainMenuButtons[MENU_BUTTON_PLAY_FILE_B], 2);
        break;
    case MENU_BUTTON_PLAY_FILE_C:
        func_8017257C(sMainMenuButtons[MENU_BUTTON_PLAY_FILE_C], 3);
        break;
    case MENU_BUTTON_PLAY_FILE_D:
        func_8017257C(sMainMenuButtons[MENU_BUTTON_PLAY_FILE_D], 4);
        break;
    case MENU_BUTTON_SCORE:
        score_menu_handle_click(sMainMenuButtons[MENU_BUTTON_SCORE]);
        break;
    case MENU_BUTTON_COPY:
        copy_menu_handle_click(sMainMenuButtons[MENU_BUTTON_COPY]);
        break;
    case MENU_BUTTON_ERASE:
        erase_menu_handle_click(sMainMenuButtons[MENU_BUTTON_ERASE]);
        break;

    case MENU_BUTTON_SCORE_FILE_A:
        func_80170C14(sMainMenuButtons[MENU_BUTTON_SCORE_FILE_A], MENU_BUTTON_SCORE);
        break;
    case MENU_BUTTON_SCORE_FILE_B:
        func_80170C14(sMainMenuButtons[MENU_BUTTON_SCORE_FILE_B], MENU_BUTTON_SCORE);
        break;
    case MENU_BUTTON_SCORE_FILE_C:
        func_80170C14(sMainMenuButtons[MENU_BUTTON_SCORE_FILE_C], MENU_BUTTON_SCORE);
        break;
    case MENU_BUTTON_SCORE_FILE_D:
        func_80170C14(sMainMenuButtons[MENU_BUTTON_SCORE_FILE_D], MENU_BUTTON_SCORE);
        break;
    case MENU_BUTTON_SCORE_RETURN:
        main_menu_init(MENU_BUTTON_SCORE, sMainMenuButtons[MENU_BUTTON_SCORE_RETURN]);
        break;
    case MENU_BUTTON_SCORE_COPY_FILE:
        copy_menu_init(MENU_BUTTON_SCORE, sMainMenuButtons[MENU_BUTTON_SCORE_COPY_FILE]);
        break;
    case MENU_BUTTON_SCORE_ERASE_FILE:
        erase_menu_init(MENU_BUTTON_SCORE, sMainMenuButtons[MENU_BUTTON_SCORE_ERASE_FILE]);
        break;

    case MENU_BUTTON_COPY_FILE_A:
        break;
    case MENU_BUTTON_COPY_FILE_B:
        break;
    case MENU_BUTTON_COPY_FILE_C:
        break;
    case MENU_BUTTON_COPY_FILE_D:
        break;
    case MENU_BUTTON_COPY_RETURN:
        main_menu_init(MENU_BUTTON_COPY, sMainMenuButtons[MENU_BUTTON_COPY_RETURN]);
        break;
    case MENU_BUTTON_COPY_CHECK_SCORE:
        score_menu_init(MENU_BUTTON_COPY, sMainMenuButtons[MENU_BUTTON_COPY_CHECK_SCORE]);
        break;
    case MENU_BUTTON_COPY_ERASE_FILE:
        erase_menu_init(MENU_BUTTON_COPY, sMainMenuButtons[MENU_BUTTON_COPY_ERASE_FILE]);
        break;

    case MENU_BUTTON_ERASE_FILE_A:
        break;
    case MENU_BUTTON_ERASE_FILE_B:
        break;
    case MENU_BUTTON_ERASE_FILE_C:
        break;
    case MENU_BUTTON_ERASE_FILE_D:
        break;
    case MENU_BUTTON_ERASE_RETURN:
        main_menu_init(MENU_BUTTON_ERASE, sMainMenuButtons[MENU_BUTTON_ERASE_RETURN]);
        break;
    case MENU_BUTTON_ERASE_CHECK_SCORE:
        score_menu_init(MENU_BUTTON_ERASE, sMainMenuButtons[MENU_BUTTON_ERASE_CHECK_SCORE]);
        break;
    case MENU_BUTTON_ERASE_COPY_FILE:
        copy_menu_init(MENU_BUTTON_ERASE, sMainMenuButtons[MENU_BUTTON_ERASE_COPY_FILE]);
        break;

    case MENU_BUTTON_SOUND_MODE:
        sound_select_menu_handle_click(sMainMenuButtons[MENU_BUTTON_SOUND_MODE]);
        break;
    case MENU_BUTTON_STEREO:
        main_menu_init(MENU_BUTTON_SOUND_MODE, sMainMenuButtons[MENU_BUTTON_STEREO]);
        break;
    case MENU_BUTTON_MONO:
        main_menu_init(MENU_BUTTON_SOUND_MODE, sMainMenuButtons[MENU_BUTTON_MONO]);
        break;
    case MENU_BUTTON_HEADSET:
        main_menu_init(MENU_BUTTON_SOUND_MODE, sMainMenuButtons[MENU_BUTTON_HEADSET]);
        break;
    }

    sClickPos[0] = -10000;
    sClickPos[1] = -10000;
}

static void handle_button_presses(void)
{
    if (sSelectedButtonId == MENU_BUTTON_SCORE_FILE_A
     || sSelectedButtonId == MENU_BUTTON_SCORE_FILE_B
     || sSelectedButtonId == MENU_BUTTON_SCORE_FILE_C
     || sSelectedButtonId == MENU_BUTTON_SCORE_FILE_D)
    {
        if (gPlayer3Controller->buttonPressed & (B_BUTTON | START_BUTTON))
        {
            sClickPos[0] = sCursorPos[0];
            sClickPos[1] = sCursorPos[1];
            D_801A7BE4 = 1;
        }
        else if (gPlayer3Controller->buttonPressed & A_BUTTON)
        {
            D_801A7C10 = 1 - D_801A7C10;
            SetSound(SOUND_MENU_CLICKFILESELECT, D_803320E0);
        }
    }
    else
    {
        if (gPlayer3Controller->buttonPressed & (A_BUTTON | B_BUTTON | START_BUTTON))
        {
            sClickPos[0] = sCursorPos[0];
            sClickPos[1] = sCursorPos[1];
            D_801A7BE4 = 1;
        }
    }
}

static void handle_controller_input(void)
{
    s16 rawStickX = gPlayer3Controller->rawStickX;
    s16 rawStickY = gPlayer3Controller->rawStickY;

    if (rawStickY > -2 && rawStickY < 2)
        rawStickY = 0;
    if (rawStickX > -2 && rawStickX < 2)
        rawStickX = 0;

    sCursorPos[0] += rawStickX / 8;
    sCursorPos[1] += rawStickY / 8;

    if (sCursorPos[0] > 132.0f)
        sCursorPos[0] = 132.0f;
    if (sCursorPos[0] < -132.0f)
        sCursorPos[0] = -132.0f;

    if (sCursorPos[1] > 90.0f)
        sCursorPos[1] = 90.0f;
    if (sCursorPos[1] < -90.0f)
        sCursorPos[1] = -90.0f;

    if (D_801A7BE4 == 0)
        handle_button_presses();
}

static void func_80173A40(void)
{
    handle_controller_input();
    func_802D6590(1, sCursorPos[0] + 160.0f - 5.0, sCursorPos[1] + 120.0f - 25.0, 0.0f);
    if (D_801A7BE4 == 0)
        gSPDisplayList(gDisplayListHead++, main_menu_seg7_dl_070073A0);
    if (D_801A7BE4 != 0)
        gSPDisplayList(gDisplayListHead++, D_070073B8);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
    if (D_801A7BE4 != 0)
    {
        D_801A7BE4++;
        if (D_801A7BE4 == 5)
            D_801A7BE4 = 0;
    }
}

static void PutString1(s8 a, s16 b, s16 c, const unsigned char *d)
{
    gSPDisplayList(gDisplayListHead++, seg2_dl_0200ED00);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sTextColorAlpha - sTextTransparency);
    PutString(a, b, c, d);
    gSPDisplayList(gDisplayListHead++, seg2_dl_0200ED68);
}

static void PutString2(s16 x, s16 y, const unsigned char *text)
{
    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EE68);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sTextColorAlpha - sTextTransparency);
    PrintGenericText(x, y, text);
    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EEF0);
}

static int update_text_fade(void)
{
    if (sFadeOutText == 1)
    {
        sTextTransparency += 50;
        if (sTextTransparency == 250)
        {
            sFadeOutText = 0;
            return TRUE;
        }
    }
    else
    {
        if (sTextTransparency > 0)
            sTextTransparency -= 50;
    }
    return FALSE;
}

static void draw_file_button_label(s8 file, s16 x, s16 y)
{
    u8 buffer[4];  // unknown length
    s8 sp1B = 0;
    s16 starCount;

    if (save_file_exists(file) == TRUE)
    {
        starCount = save_file_get_total_star_count(file, 0, 24);
        PutString(2, x, y, D_801A7C74);
        if (starCount < 100)
        {
            PutString(2, x + 16, y, D_801A7C78);
            sp1B = 16;
        }
        Int2Str(starCount, buffer);
        PutString(2, x + sp1B + 16, y, buffer);
    }
    else
    {
        PutString(2, x, y, textNew);
    }
}

static void draw_main_menu(void)
{
    gSPDisplayList(gDisplayListHead++, seg2_dl_0200ED00);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sTextColorAlpha);
    PutString(1, 96, 35, D_801A7C7C);
    draw_file_button_label(0, 92, 78);
    draw_file_button_label(1, 209, 78);
    draw_file_button_label(2, 92, 118);
    draw_file_button_label(3, 209, 118);
    gSPDisplayList(gDisplayListHead++, seg2_dl_0200ED68);
    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EE68);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sTextColorAlpha);
    PrintGenericText(50, 39, textScore);
    PrintGenericText(115, 39, textCopy);
    PrintGenericText(180, 39, textErase);
    PrintGenericText(235, 39, textSoundModes[sSoundMode]);
    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EEF0);
    gSPDisplayList(gDisplayListHead++, main_menu_seg7_dl_0700D108);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sTextColorAlpha);
    PrintRegularText(92, 65, textMarioA);
    PrintRegularText(207, 65, textMarioB);
    PrintRegularText(92, 105, textMarioC);
    PrintRegularText(207, 105, textMarioD);
    gSPDisplayList(gDisplayListHead++, main_menu_seg7_dl_0700D160);
}

static void print_file_score_message(s8 a)
{
    switch (a)
    {
    case 0:
        PutString1(1, 90, 35, D_801A7C98);
        break;
    case 1:
        PutString2(90, 190, textNoSavedDataExists);
        break;
    }
}

static void draw_score_menu(void)
{
    if (D_801A7BFC == 20)
        sFadeOutText = 1;
    if (update_text_fade() == TRUE)
    {
        if (sStatusMessageId == 0)
            sStatusMessageId = 1;
        else
            sStatusMessageId = 0;
    }
    print_file_score_message(sStatusMessageId);
    gSPDisplayList(gDisplayListHead++, seg2_dl_0200ED00);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sTextColorAlpha);
    draw_file_button_label(0, 90, 76);
    draw_file_button_label(1, 211, 76);
    draw_file_button_label(2, 90, 119);
    draw_file_button_label(3, 211, 119);
    gSPDisplayList(gDisplayListHead++, seg2_dl_0200ED68);
    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EE68);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sTextColorAlpha);
    PrintGenericText(45, 35, textReturn);
    PrintGenericText(128, 35, textFileCopy);
    PrintGenericText(228, 35, textFileDelete);
    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EEF0);
    gSPDisplayList(gDisplayListHead++, main_menu_seg7_dl_0700D108);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sTextColorAlpha);
    PrintRegularText(89, 62, textMarioA);
    PrintRegularText(211, 62, textMarioB);
    PrintRegularText(89, 105, textMarioC);
    PrintRegularText(211, 105, textMarioD);
    gSPDisplayList(gDisplayListHead++, main_menu_seg7_dl_0700D160);
}

static void copy_menu_print_message(s8 messageId)
{
    switch (messageId)
    {
    case 0:
        if (sAllFilesExist == TRUE)
            PutString2(90, 190, textNoFileToCopyFrom);
        else
            PutString1(1, 90, 35, D_801A7CB8);
        break;
    case 1:
        PutString2(90, 190, textCopyItToWhere);
        break;
    case 2:
        PutString2(90, 190, textNoSavedDataExists2);
        break;
    case 3:
        PutString2(90, 190, textCopyFinished);
        break;
    case 4:
        PutString2(90, 190, textSavedDataExists);
        break;
    }
}

static void copy_menu_update_message(void)
{
    switch (sMainMenuButtons[MENU_BUTTON_COPY]->oMainMenuButtonUnk10C)
    {
    case 0:
        if (D_801A7BFC == 20)
            sFadeOutText = 1;
        if (update_text_fade() == TRUE)
        {
            if (sStatusMessageId == 0)
                sStatusMessageId = 2;
            else
                sStatusMessageId = 0;
        }
        break;
    case 1:
        if (D_801A7BFC == 20 && sStatusMessageId == 4)
            sFadeOutText = 1;
        if (update_text_fade() == TRUE)
        {
            if (sStatusMessageId != 1)
                sStatusMessageId = 1;
            else
                sStatusMessageId = 4;
        }
        break;
    case 2:
        if (D_801A7BFC == 20)
            sFadeOutText = 1;
        if (update_text_fade() == TRUE)
        {
            if (sStatusMessageId != 3)
                sStatusMessageId = 3;
            else
                sStatusMessageId = 0;
        }
        break;
    }
}

static void draw_copy_menu(void)
{
    copy_menu_update_message();
    copy_menu_print_message(sStatusMessageId);

    gSPDisplayList(gDisplayListHead++, seg2_dl_0200ED00);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sTextColorAlpha);
    draw_file_button_label(0, 90, 76);
    draw_file_button_label(1, 211, 76);
    draw_file_button_label(2, 90, 119);
    draw_file_button_label(3, 211, 119);
    gSPDisplayList(gDisplayListHead++, seg2_dl_0200ED68);
    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EE68);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sTextColorAlpha);
    PrintGenericText(45, 35, textReturn);
    PrintGenericText(133, 35, textViewScore);
    PrintGenericText(220, 35, textFileDelete);
    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EEF0);
    gSPDisplayList(gDisplayListHead++, main_menu_seg7_dl_0700D108);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sTextColorAlpha);
    PrintRegularText(89, 62, textMarioA);
    PrintRegularText(211, 62, textMarioB);
    PrintRegularText(89, 105, textMarioC);
    PrintRegularText(211, 105, textMarioD);
    gSPDisplayList(gDisplayListHead++, main_menu_seg7_dl_0700D160);
}

static void erase_yes_no_prompt(s16 x, s16 y)
{
    s16 sp2E = gGlobalTimer << 12;
    s16 sp2C = sCursorPos[0] + 160.0f;
    s16 sp2A = sCursorPos[1] + 120.0f;

    if (sp2C < 0xA4 && sp2C >= 0x91 && sp2A < 0xD2 && sp2A >= 0xBF)
    {
        sYesNoColor[0] = sins(sp2E) * 50.0f + 205.0f;
        sYesNoColor[1] = 150;
        D_801A7C04 = 1;
    }
    else if (sp2C < 0xDA && sp2C >= 0xBD && sp2A < 0xD2 && sp2A >= 0xBF)
    {
        sYesNoColor[0] = 150;
        sYesNoColor[1] = sins(sp2E) * 50.0f + 205.0f;
        D_801A7C04 = 2;
    }
    else
    {
        sYesNoColor[0] = 150;
        sYesNoColor[1] = 150;
        D_801A7C04 = 0;
    }
    if (D_801A7BE4 == 2)
    {
        if (D_801A7C04 == 1)
        {
            SetSound(SOUND_MARIO_WAAAOOOW, D_803320E0);
            sMainMenuButtons[MENU_BUTTON_ERASE]->oMainMenuButtonUnk10C = 2;
            sFadeOutText = 1;
            D_801A7BFC = 0;
            save_file_erase(sSelectedFile);
            sMainMenuButtons[MENU_BUTTON_ERASE_FILE_A + sSelectedFile]->header.gfx.asGraphNode = gLoadedGraphNodes[10];
            sMainMenuButtons[sSelectedFile]->header.gfx.asGraphNode = gLoadedGraphNodes[10];
            D_801A7C04 = 0;
        }
        else if (D_801A7C04 == 2)
        {
            SetSound(SOUND_MENU_CLICKFILESELECT, D_803320E0);
            sMainMenuButtons[MENU_BUTTON_ERASE_FILE_A + sSelectedFile]->oMainMenuButtonUnkF4 = 6;
            sMainMenuButtons[MENU_BUTTON_ERASE]->oMainMenuButtonUnk10C = 0;
            sFadeOutText = 1;
            D_801A7BFC = 0;
            D_801A7C04 = 0;
        }
    }
    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EE68);
    gDPSetEnvColor(gDisplayListHead++, sYesNoColor[0], sYesNoColor[0], sYesNoColor[0], sTextColorAlpha);
    PrintGenericText(x + 56, y, textYes);
    gDPSetEnvColor(gDisplayListHead++, sYesNoColor[1], sYesNoColor[1], sYesNoColor[1], sTextColorAlpha);
    PrintGenericText(x + 98, y, textNo);
    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EEF0);
}

static void erase_menu_print_message(s8 messageId)
{
    unsigned char sp58[] = {0x00, 0x01, 0x02, 0x03, 0x0E, 0x0C, 0xFF};
    unsigned char textSure[] = {TEXT_SURE};
    unsigned char textNoSavedDataExists[] = {TEXT_NO_SAVED_DATA_EXISTS};
    unsigned char textMarioAJustErased[] = {TEXT_MARIO_A_JUST_ERASED};
    unsigned char textSavedDataExists[] = {TEXT_SAVED_DATA_EXISTS};

    switch (messageId)
    {
    case 0:
        PutString1(1, 96, 35, sp58);
        break;
    case 1:
        PutString2(90, 190, textSure);
        erase_yes_no_prompt(90, 190);
        break;
    case 2:
        PutString2(90, 190, textNoSavedDataExists);
        break;
    case 3:
        textMarioAJustErased[3] = sSelectedFile + 10;
        PutString2(90, 190, textMarioAJustErased);
        break;
    case 4:
        PutString2(90, 190, textSavedDataExists);
        break;
    }
}

static void erase_menu_update_message(void)
{
    switch (sMainMenuButtons[MENU_BUTTON_ERASE]->oMainMenuButtonUnk10C)
    {
    case 0:
        if (D_801A7BFC == 20 && sStatusMessageId == 2)
            sFadeOutText = 1;
        if (update_text_fade() == TRUE)
        {
            if (sStatusMessageId == 0)
                sStatusMessageId = 2;
            else
                sStatusMessageId = 0;
        }
        break;
    case 1:
        if (update_text_fade() == TRUE)
        {
            if (sStatusMessageId != 1)
                sStatusMessageId = 1;
            sCursorPos[0] = 43.0f;
            sCursorPos[1] = 80.0f;
        }
        break;
    case 2:
        if (D_801A7BFC == 20)
            sFadeOutText = 1;
        if (update_text_fade() == TRUE)
        {
            if (sStatusMessageId != 3)
                sStatusMessageId = 3;
            else
                sStatusMessageId = 0;
        }
        break;
    }
}

static void draw_erase_menu(void)
{
    erase_menu_update_message();
    erase_menu_print_message(sStatusMessageId);

    gSPDisplayList(gDisplayListHead++, seg2_dl_0200ED00);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sTextColorAlpha);
    draw_file_button_label(0, 90, 76);
    draw_file_button_label(1, 211, 76);
    draw_file_button_label(2, 90, 119);
    draw_file_button_label(3, 211, 119);
    gSPDisplayList(gDisplayListHead++, seg2_dl_0200ED68);
    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EE68);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sTextColorAlpha);
    PrintGenericText(45, 35, textReturn);
    PrintGenericText(133, 35, textViewScore);
    PrintGenericText(223, 35, textFileCopy);
    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EEF0);
    gSPDisplayList(gDisplayListHead++, main_menu_seg7_dl_0700D108);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sTextColorAlpha);
    PrintRegularText(89, 62, textMarioA);
    PrintRegularText(211, 62, textMarioB);
    PrintRegularText(89, 105, textMarioC);
    PrintRegularText(211, 105, textMarioD);
    gSPDisplayList(gDisplayListHead++, main_menu_seg7_dl_0700D160);
}

static void draw_sound_mode_menu(void)
{
    int mode;
    unsigned char sp38[] = {0x18, 0x19, 0x1A, 0x1B, 0x04, 0x05, 0x06, 0x07, 0xFF};

    gSPDisplayList(gDisplayListHead++, seg2_dl_0200ED00);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sTextColorAlpha);
    PutString(1, 96, 35, sp38);
    gSPDisplayList(gDisplayListHead++, seg2_dl_0200ED68);
    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EE68);
    for (mode = 0; mode < 3; mode++)
    {
        if (mode == sSoundMode)
        {
            gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sTextColorAlpha);
        }
        else
        {
            gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, sTextColorAlpha);
        }
        PrintGenericText(mode * 74 + 67, 87, textSoundModes[mode]);
    }
    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EEF0);
}

static unsigned char D_801A7D70[] = {0xFA, 0xFB, 0xFF};

static void func_801759F0(s8 file, s16 x, s16 y)
{
    unsigned char buffer[20];  // unknown length

    PrintRegularText(x, y, D_801A7D70);
    Int2Str(save_file_get_total_star_count(file, 15, 24), buffer);
    PrintRegularText(x + 16, y, buffer);
}

static void print_course_coin_score(s8 file, s16 course, s16 x, s16 y)
{
    unsigned char buffer[20];  // unknown length
    u8 stars = save_file_get_star_flags(file, course);
    unsigned char sp48[] = {0xF9, 0xFB, 0xFF};
    unsigned char sp44[] = {0xFA, 0xFF};
    unsigned char fileNames[][5] = {
        {TEXT_4DASHES},
        {TEXT_MARIO_A},
        {TEXT_MARIO_B},
        {TEXT_MARIO_C},
        {TEXT_MARIO_D}
    };

    if (D_801A7C10 == 0)
    {
        PrintRegularText(x + 25, y, sp48);
        Int2Str(save_file_get_course_coin_score(file, course), buffer);
        PrintRegularText(x + 41, y, buffer);
        if (stars & 0x40)
            PrintRegularText(x + 70, y, sp44);
    }
    else
    {
        PrintRegularText(x, y, sp48);
        Int2Str((u16)save_file_get_max_coin_score(course) & 0xFFFF, buffer);
        PrintRegularText(x + 16, y, buffer);
        PrintRegularText(x + 45, y, fileNames[(save_file_get_max_coin_score(course) >> 16) & 0xFFFF]);
    }
}

static void print_course_star_score(s8 file, s16 course, s16 x, s16 y)
{
    s16 i = 0;
    unsigned char buffer[20];  // unknown length
    u8 stars = save_file_get_star_flags(file, course);
    s8 starCount = save_file_get_course_star_count(file, course);

    if (stars & 0x40)
        starCount--;
    for (i = 0; i < starCount; i++)
        buffer[i] = 0xFA;
    buffer[i] = 0xFF;
    PrintRegularText(x, y, buffer);
}

static void draw_file_scores_menu(s8 file)
{
    unsigned char sp54[] = {0x0F, 0x10, 0x11, 0xFF};
    unsigned char sp50[] = {TEXT_0};
    void **levelNameTable = segmented_to_virtual(seg2_level_name_table);
    unsigned char textHiScore[] = {TEXT_HISCORE};
    unsigned char textMyScore[] = {TEXT_MYSCORE};

    sp50[0] = file + 10;
    gSPDisplayList(gDisplayListHead++, seg2_dl_0200ED00);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sTextColorAlpha);
    PutString(1, 28, 15, sp54);
    PutString(2, 86, 15, sp50);
    draw_file_button_label(file, 124, 15);
    gSPDisplayList(gDisplayListHead++, seg2_dl_0200ED68);
    gSPDisplayList(gDisplayListHead++, main_menu_seg7_dl_0700D108);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sTextColorAlpha);

    //! for loops exist for a reason

#define PRINT_COURSE_SCORES(course) \
    PrintRegularText(23, 35 + 12 * course, segmented_to_virtual(levelNameTable[course])); \
    print_course_star_score(file, course, 152, 35 + 12 * course); \
    print_course_coin_score(file, course, 213, 35 + 12 * course);

    PRINT_COURSE_SCORES(0)
    PRINT_COURSE_SCORES(1)
    PRINT_COURSE_SCORES(2)
    PRINT_COURSE_SCORES(3)
    PRINT_COURSE_SCORES(4)
    PRINT_COURSE_SCORES(5)
    PRINT_COURSE_SCORES(6)
    PRINT_COURSE_SCORES(7)
    PRINT_COURSE_SCORES(8)
    PRINT_COURSE_SCORES(9)
    PRINT_COURSE_SCORES(10)
    PRINT_COURSE_SCORES(11)
    PRINT_COURSE_SCORES(12)
    PRINT_COURSE_SCORES(13)
    PRINT_COURSE_SCORES(14)

#undef PRINT_COURSE_SCORES

    // castle secret stars
    PrintRegularText(23, 215, segmented_to_virtual(levelNameTable[25]));
    func_801759F0(file, 152, 215);
    if (D_801A7C10 == 0)
        PrintRegularText(237, 24, textMyScore);
    else
        PrintRegularText(237, 24, textHiScore);

    gSPDisplayList(gDisplayListHead++, main_menu_seg7_dl_0700D160);
}

static void draw_current_menu(void)
{
    UNUSED int unused1;
    UNUSED int unused2;

    func_802D68A4();
    switch (sSelectedButtonId)
    {
    case MENU_BUTTON_NONE:
        draw_main_menu();
        break;
    case MENU_BUTTON_SCORE:
        draw_score_menu();
        D_801A7C10 = 0;
        break;
    case MENU_BUTTON_COPY:
        draw_copy_menu();
        break;
    case MENU_BUTTON_ERASE:
        draw_erase_menu();
        break;
    case MENU_BUTTON_SCORE_FILE_A:
        draw_file_scores_menu(0);
        break;
    case MENU_BUTTON_SCORE_FILE_B:
        draw_file_scores_menu(1);
        break;
    case MENU_BUTTON_SCORE_FILE_C:
        draw_file_scores_menu(2);
        break;
    case MENU_BUTTON_SCORE_FILE_D:
        draw_file_scores_menu(3);
        break;
    case MENU_BUTTON_SOUND_MODE:
        draw_sound_mode_menu();
        break;
    }
    if (save_file_exists(0) == TRUE
     && save_file_exists(1) == TRUE
     && save_file_exists(2) == TRUE
     && save_file_exists(3) == TRUE)
        sAllFilesExist = TRUE;
    else
        sAllFilesExist = FALSE;
    if (sTextColorAlpha < 0xFA)
        sTextColorAlpha += 10;
    if (D_801A7BFC < 0x3E8)
        D_801A7BFC += 1;
}

int Geo18_80176688(int a, UNUSED int b, UNUSED int c)
{
    if (a == 1)
    {
        draw_current_menu();
        func_80173A40();
    }
    return 0;
}

void LevelProc_801766DC(UNUSED int a, UNUSED int b)
{
    sSelectedButtonId = -1;
    D_801A7BD4 = 1;
    sTextColorAlpha = 0;

    switch (gCurrSaveFileNum)
    {
    case 1:
        sCursorPos[0] = -94.0f;
        sCursorPos[1] = 46.0f;
        break;
    case 2:
        sCursorPos[0] = 24.0f;
        sCursorPos[1] = 46.0f;
        break;
    case 3:
        sCursorPos[0] = -94.0f;
        sCursorPos[1] = 5.0f;
        break;
    case 4:
        sCursorPos[0] = 24.0f;
        sCursorPos[1] = 5.0f;
        break;
    }
    sClickPos[0] = -10000;
    sClickPos[1] = -10000;
    D_801A7BE4 = 0;
    D_801A7C0C = 0;
    sSelectedFile = -1;
    sFadeOutText = 0;
    sStatusMessageId = 0;
    sTextTransparency = 0;
    D_801A7BFC = 0;
    D_801A7C04 = 0;
    sSoundMode = save_file_get_sound_mode();
}

int LevelProc_801768A0(UNUSED int a, UNUSED int b)
{
    area_update_objects();
    return D_801A7C0C;
}
