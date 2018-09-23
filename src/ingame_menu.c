#include <ultra64.h>

#include "sm64.h"
#include "memory.h"
#include "types.h"
#include "audio_interface_2.h"
#include "game.h"
#include "save_file.h"
#include "level_update.h"
#include "camera.h"
#include "text_strings.h"
#include "segment2.h"
#include "segment7.h"
#include "ingame_menu.h"
#include "math_util.h"

extern Gfx *gDisplayListHead;
extern s32 gGlobalTimer;
extern s16 gCurrCourseNum;
extern s16 gCurrSaveFileNum;

extern Gfx red_coin_seg3_dl_03007940[];
extern Gfx red_coin_seg3_dl_03007968[];
extern Gfx red_coin_seg3_dl_03007990[];
extern Gfx red_coin_seg3_dl_030079B8[];

extern u8 main_menu_seg7_table_0700ABD0[];
extern Gfx castle_grounds_seg7_dl_0700EA58[];

extern u16 D_80360080;
extern s8 D_80360082;
extern s32 D_80360084;
extern u16 D_80360088;
extern s16 D_8036008A;
extern s16 D_8036008C;
extern s8 D_8036008E;

extern u8 D_8032CE20;
extern u8 D_8032CE24;

extern int func_8028803C(int);

s8 D_80330410 = 0;
f32 D_80330414 = 90.0f;
f32 D_80330418 = 19.0f;
s16 D_8033041C = 0;
s8 D_80330420 = 0;
s16 D_80330424 = -1;
s16 D_80330428 = 0;
s16 D_8033042C = 0;
s8 D_80330430 = 1;
s8 D_80330434 = 0;
u8 D_80330438 = 0;
u8 D_8033043C = 0;
s32 D_80330440 = 0;

#ifdef VERSION_JP
#define MAX_STRING_WIDTH 18
#else
#define MAX_STRING_WIDTH 16
#endif

// dl_add_new_identity_matrix?
void func_802D6440(void)
{
    Mtx *matrix = (Mtx *) alloc_display_list(sizeof(Mtx));

    if(matrix == NULL)
        return;

    matrix->m[0][0] = 0x00010000;
    matrix->m[1][0] = 0x00000000;
    matrix->m[2][0] = 0x00000000;
    matrix->m[3][0] = 0x00000000;
    
    matrix->m[0][1] = 0x00000000;
    matrix->m[1][1] = 0x00010000;
    matrix->m[2][1] = 0x00000000;
    matrix->m[3][1] = 0x00000000;
    
    matrix->m[0][2] = 0x00000001;
    matrix->m[1][2] = 0x00000000;
    matrix->m[2][2] = 0x00000000;
    matrix->m[3][2] = 0x00000000;
    
    matrix->m[0][3] = 0x00000000;
    matrix->m[1][3] = 0x00000001;
    matrix->m[2][3] = 0x00000000;
    matrix->m[3][3] = 0x00000000;

    gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_LOAD);
    gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_LOAD | G_MTX_PROJECTION);
}

// dl_add_new_translation_matrix
void func_802D6590(s8 pushOp, f32 x, f32 y, f32 z)
{
    Mtx *matrix = (Mtx *) alloc_display_list(sizeof(Mtx));

    if(matrix == NULL)
        return;

    guTranslate(matrix, x, y, z);

    if(pushOp == MENU_MTX_PUSH)
        gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_PUSH);

    if(pushOp == MENU_MTX_NOPUSH)
        gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_NOPUSH);
}

// dl_add_new_rotation_matrix
void func_802D6694(s8 pushOp, f32 a, f32 x, f32 y, f32 z)
{
    Mtx *matrix = (Mtx *) alloc_display_list(sizeof(Mtx));

    if(matrix == NULL)
        return;

    guRotate(matrix, a, x, y, z);

    if(pushOp == MENU_MTX_PUSH)
        gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_PUSH);

    if(pushOp == MENU_MTX_NOPUSH)
        gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_NOPUSH);
}

// dl_add_new_scale_matrix
void func_802D67A0(s8 pushOp, f32 x, f32 y, f32 z)
{
    Mtx *matrix = (Mtx *) alloc_display_list(sizeof(Mtx));

    if(matrix == NULL)
        return;

    guScale(matrix, x, y, z);

    if(pushOp == MENU_MTX_PUSH)
        gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_PUSH);

    if(pushOp == MENU_MTX_NOPUSH)
        gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_NOPUSH);
}

// dl_add_new_ortho_matrix
void func_802D68A4(void)
{
    Mtx *matrix = (Mtx *) alloc_display_list(sizeof(Mtx));

    if(matrix == NULL)
        return;

    func_802D6440();

    guOrtho(matrix, 0.0f, 320.0f, 0.0f, 240.0f, -10.0f, 10.0f, 1.0f); 

    // G_RDPHALF_1
    {
        Gfx *_g = (Gfx *)(gDisplayListHead++);
        _g->words.w0 = 0xB4000000;
        _g->words.w1 = 0x0000FFFF;
    }

    gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_PROJECTION)
}

// dl_add_new_ia8_tex_from_i1
u8* func_802D69A0(u16* in, s16 width, s16 height)
{
    s32 inPos;
    u16 bitMask;
    u8 *out;
    s16 outPos;
    
    outPos = 0;
    out = alloc_display_list(width * height);

    if(out == NULL)
        return NULL;

    for(inPos = 0; inPos < (width * height) / 16; inPos++)
    {
        bitMask = 0x8000;

        while(bitMask != 0)
        {
            if(in[inPos] & bitMask)
                out[outPos] = 0xFF;
            else
                out[outPos] = 0x00;

            bitMask /= 2;
            outPos++;
        }
    }

    return out;
}

// render_generic_char
void func_802D6AFC(u8 c)
{
    void **smallFontLUT;
    void *packedTexture;
    void *unpackedTexture;

    smallFontLUT = segmented_to_virtual(seg2_small_font_lut);
    packedTexture = segmented_to_virtual(smallFontLUT[c]);

#ifdef VERSION_JP
    unpackedTexture = func_802D69A0(packedTexture, 8, 16);

    gDPPipeSync(gDisplayListHead++);
    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_IA, G_IM_SIZ_8b, 1, VIRTUAL_TO_PHYSICAL(unpackedTexture));
    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EEA8);
#else
    gDPPipeSync(gDisplayListHead++);
    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, VIRTUAL_TO_PHYSICAL(packedTexture));
    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EEA8);
#endif
}

extern u8 D_U_80331370[256]; // length table (US only) TODO: Make into definition

#ifdef VERSION_US
enum MutliStringIDs {
    STRING_THE,
    STRING_YOU
};

/*
 * Place the multi-text string according to the ID passed. (US only)
 * 0: 'the'
 * 1: 'you'
 */
void put_multi_text_string(s8 multiTextID) // US: 802D76C8
{
    s8 i;
    u8 textLengths[10] = {
        7,7,7,7,7, // 'the'
        7,7,7,7,7  // 'you'
    };

    for (i = 0; i < textLengths[multiTextID * 5]; i++)
    {
        func_802D6AFC(textLengths[5 * multiTextID + 1 + i]);
        func_802D6590(2, (f32)(D_U_80331370[textLengths[5 * multiTextID + 1 + i]]), 0.0f, 0.0f);
    }
};
#endif

void PrintGenericText(s16 x, s16 y, const u8 *str)
{
    s8 mark = DLG_MARK_NONE;
    s32 strPos = 0;
    u8 lineNum = 1;

    // create_new_translation_matrix
    func_802D6590(MENU_MTX_PUSH, x, y, 0.0f);

    while(str[strPos] != 0xFF)
    {
        switch(str[strPos])
        {
        case 0xF0: // kana with dakuten
            mark = DLG_MARK_DAKUTEN;
            break;
        case 0xF1: // kana with handakuten
            mark = DLG_MARK_HANDAKUTEN;
            break;
        case 0xFE: // newline
            gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
            func_802D6590(MENU_MTX_PUSH, x, y - (lineNum * MAX_STRING_WIDTH), 0.0f);
            lineNum++;
            break;
        case 0x6E: // handakuten mark
            func_802D6590(MENU_MTX_PUSH, -2.0f, -5.0f, 0.0f);
            func_802D6AFC(0xF1);
            gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
            break;
#ifdef VERSION_US
        case 0xD0: // '/'
            func_802D6590(MENU_MTX_NOPUSH, (f32)(D_U_80331370[0x9E] * 2), 0.0f, 0.0f);
            break;
        case 0xD1: // 'the'
            put_multi_text_string(STRING_THE);
            break;
        case 0xD2: // 'you'
            put_multi_text_string(STRING_YOU);
            break;
#endif
        case 0x9E: // space
#ifdef VERSION_JP
            func_802D6590(MENU_MTX_NOPUSH, 5.0f, 0.0f, 0.0f);
#else
            func_802D6590(MENU_MTX_NOPUSH, (f32)(D_U_80331370[0x9E]), 0.0f, 0.0f);
#endif
            break;
            break; // ? needed to match
        default:
            func_802D6AFC(str[strPos]);

            if(mark != DLG_MARK_NONE)
            {
                func_802D6590(MENU_MTX_PUSH, 5.0f, 5.0f, 0.0f);
                func_802D6AFC(mark + 0xEF);
                gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
                mark = DLG_MARK_NONE;
            }

#ifdef VERSION_JP
            func_802D6590(MENU_MTX_NOPUSH, 10.0f, 0.0f, 0.0f);
#else
            func_802D6590(MENU_MTX_NOPUSH, (f32)(D_U_80331370[str[strPos]]), 0.0f, 0.0f);
            break; // what an odd difference. US added a useless break here.
#endif
        }

        strPos++;
    }

    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

void PutString(s8 font, s16 x, s16 y, const u8 *str)
{
    s32 strPos = 0;
    void **fontLUT1 = segmented_to_virtual(main_menu_seg7_table_0700ABD0);
    void **fontLUT2 = segmented_to_virtual(seg2_hud_lut);
    s32 curX = x;
    s32 curY = y;

    s32 xStride;

    if(font == 1)
        xStride = 16;
    else
        xStride = 14;

    while(str[strPos] != 0xFF)
    {
        gDPPipeSync(gDisplayListHead++);

        if(font == 1)
            gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, fontLUT1[str[strPos]]);

        if(font == 2)
            gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, fontLUT2[str[strPos]]);

        gSPDisplayList(gDisplayListHead++, seg2_dl_0200ED38);
        gSPTextureRectangle(gDisplayListHead++, curX<<2, curY<<2,
            (curX+16)<<2, (curY+16)<<2, 0, 0, 0, 0x400, 0x400);

        curX += xStride;
        strPos++;
    }
}

void PrintRegularText(s16 x, s16 y, const u8 *str)
{
    s8 mark = DLG_MARK_NONE;
    s32 strPos = 0;
    s32 curX = x;
    s32 curY = y;
    void **fontLUT = segmented_to_virtual(main_menu_seg7_table_0700CD08);

    while(str[strPos] != 0xFF)
    {
        switch(str[strPos])
        {
        case 0xF0:
            mark = DLG_MARK_DAKUTEN;
            break;
        case 0xF1:
            mark = DLG_MARK_HANDAKUTEN;
            break;
        case 0x9E:
            curX += 4;
            break;
        default:
            gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_IA, G_IM_SIZ_8b, 1, fontLUT[str[strPos]]);
            gDPLoadSync(gDisplayListHead++);
            gDPLoadBlock(gDisplayListHead++, 7, 0, 0, (0x40-1), 0x800);
            gSPTextureRectangle(gDisplayListHead++, curX<<2, curY<<2,
                (curX+8)<<2, (curY+8)<<2, 0, 0, 0, 0x400, 0x400);

            if(mark != DLG_MARK_NONE)
            {
                gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_IA, G_IM_SIZ_8b, 1, fontLUT[mark + 0xEF]);
                gDPLoadSync(gDisplayListHead++);
                gDPLoadBlock(gDisplayListHead++, 7, 0, 0, (0x40-1), 0x800);
                gSPTextureRectangle(gDisplayListHead++, (curX+6)<<2, (curY-7)<<2,
                    (curX+14)<<2, (curY+1)<<2, 0, 0, 0, 0x400, 0x400);

                mark = DLG_MARK_NONE;
            }

            curX += 9;
        }

        strPos++;
    }
}

void PutMiniString(s16 x, s16 y, const u8 *str)
{
    s32 strPos = 0;
    void **fontLUT = segmented_to_virtual(seg2_credits_font_lut);
    s32 curX = x;
    s32 curY = y;

    gDPSetTile(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0);
    gDPTileSync(gDisplayListHead++)
    gDPSetTile(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 2, 0, 0, 0, 2, 3, 0, 2, 3, 0);
    gDPSetTileSize(gDisplayListHead++, 0, 0, 0, (8-1)<<2, (8-1)<<2);

    while(str[strPos] != 0xFF)
    {
        switch(str[strPos])
        {
        case 0x9E:
            curX += 4;
            break;
        default:
            gDPPipeSync(gDisplayListHead++);
            gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, fontLUT[str[strPos]]);
            gDPLoadSync(gDisplayListHead++);
            gDPLoadBlock(gDisplayListHead++, 7, 0, 0, (0x40-1), 0x400);
            gSPTextureRectangle(gDisplayListHead++, curX<<2, curY<<2,
                (curX+8)<<2, (curY+8)<<2, 0, 0, 0, 0x400, 0x400);
            curX += 7;
            break;
        }
        strPos++;
    }
}

void func_802D7924(s8 sp23, s8 *sp24, s8 sp2b, s8 sp2f)
{
    u8 sp1f = 0;

    if(sp23 == 1)
    {
        if(gPlayer3Controller->rawStickY > 60)
            sp1f++;

        if(gPlayer3Controller->rawStickY < -60)
            sp1f += 2;
    }
    else if(sp23 == 2)
    {
        if(gPlayer3Controller->rawStickX > 60)
            sp1f += 2;

        if(gPlayer3Controller->rawStickX < -60)
            sp1f++;
    }

    if(((sp1f ^ D_80330438) & sp1f) == 2)
    {
        if(sp24[0] == sp2f)
        {
            sp24[0] = sp2f; // wut
        }
        else
        {
            SetSound(0x7000F881, D_803320E0);
            sp24[0]++;
        }
    }

    if(((sp1f ^ D_80330438) & sp1f) == 1)
    {
        if(sp24[0] == sp2b)
        {
            // empty
        }
        else
        {
            SetSound(0x7000F881, D_803320E0);
            sp24[0]--;
        }
    }

    if(D_8033043C == 10)
    {
        D_8033043C = 8;
        D_80330438 = 0;
    }
    else
    {
        D_8033043C++;
        D_80330438 = sp1f;
    }

    if((sp1f & 3) == 0)
    {
        D_8033043C = 0;
    }
}

s16 func_802D7B3C(s16 a0, u8 *str, f32 sp18)
{
    // calculate center?

    s16 strPos = 0;
    f32 charsWidth = 0.0f;
    f32 spacesWidth = 0.0f;

    while(str[strPos] != 0xFF)
    {
        if(str[strPos] == 0x9E)
            spacesWidth += 1.0;
        else if(str[strPos] != 0xF0 && str[strPos] != 0xF1)
            charsWidth += 1.0;

        strPos++;
    }

    return (f32)a0 - (sp18 * (charsWidth / 2.0)) - ((sp18 / 2.0) * (spacesWidth / 2.0));
}

u8 D_80330444[] = {TEXT_UNK33};
u8 D_80330448[] = {TEXT_UNK32};

void ShowCoins(s32 useCourseCoinScore, s8 sp27, s8 sp2b, s16 x, s16 y)
{
    u8 strNumCoins[4];
    s16 numCoins;
    
    if(!useCourseCoinScore)
        numCoins = (u16)(save_file_get_max_coin_score(sp2b) & 0xFFFF);
    else
        numCoins = save_file_get_course_coin_score(sp27, sp2b);

    if(numCoins != 0)
    {
        PutString(2, x, y, D_80330444);
        PutString(2, x + 16, y, D_80330448);
        Int2Str(numCoins, strNumCoins);
        PutString(2, x + 32, y, strNumCoins);
    }
}

void ShowStars(s8 sp2b, s8 sp2f, s16 x, s16 y)
{
    u8 strStarCount[4];
    s16 starCount;
    u8 sp20[] = {TEXT_UNK35}; // D_8033044C star symbol?
    UNUSED u16 unused;
    u8 sp1c[] = {TEXT_UNK32}; // D_80330450 x symbol? 
    
    starCount = save_file_get_course_star_count(sp2b, sp2f);

    if(starCount != 0)
    {
        PutString(2, x, y, sp20);
        PutString(2, x + 16, y, sp1c);
        Int2Str(starCount, strStarCount);
        PutString(2, x + 32, y, strStarCount);
    }
}

void Int2Str(s32 num, u8 *dst)
{
    s32 digit1;
    s32 digit2;
    s32 digit3;

    s8 pos = 0;

    if(num > 999)
    {
        dst[0] = 0x00;
        dst[1] = 0xFF;
        return;
    }

    digit1 = num / 100;
    digit2 = (num - digit1 * 100) / 10;
    digit3 = (num - digit1 * 100) - (digit2 * 10);

    if(digit1 != 0)
        dst[pos++] = digit1;

    if(digit2 != 0 || digit1 != 0)
        dst[pos++] = digit2;

    dst[pos++] = digit3;
    dst[pos] = 0xFF;
}

s16 func_802D7F74(void)
{
    return D_80330424;
}

void func_802D7F90(s16 a0)
{
    if(D_80330424 == -1)
    {
        D_80330424 = a0;
        D_80330420 = 0;
    }
}

void func_802D7FCC(s16 a0, s32 a1)
{
    if(D_80330424 == -1)
    {
        D_80330424 = a0;
        D_80360084 = a1;
        D_80330420 = 0;
    }
}

void CreateTextBox(s16 a0)
{
    if(D_80330424 == -1)
    {
        D_80330424 = a0;
        D_80330420 = 1;
    }
}

void func_802D8050(s16 a0)
{
    if(D_80330424 == -1)
    {
        D_80330424 = a0;
        D_80330420 = 0;
        D_80330434 = 1;
    }
}

void func_802D8098(void)
{
    level_set_transition(0, 0);

    if(D_80330420 == 1)
        StopMario(2);

    D_80330418 = 19.0f;
    D_80330414 = 90.0f;
    D_80330410 = 0;
    D_80330424 = -1;
    D_8033042C = 0;
    D_80330434 = 0;
    D_80330428 = 0;
    D_80330440 = 0;
}

void func_802D8134(struct Struct802D8980 *sp40, s8 sp47)
{
    UNUSED s32 unused;

    func_802D6590(2, sp40->unk06, sp40->unk08, 0);

    switch(D_80330420)
    {
    case 0:
        if(D_80330410 == 0 || D_80330410 == 3)
        {
            func_802D67A0(2, 1.0 / D_80330418, 1.0 / D_80330418, 1.0f);
            func_802D6694(2, D_80330414 * 4.0f, 0, 0, 1.0f);
        }
        gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, 0x96);
        break;
    case 1:
        if(D_80330410 == 0 || D_80330410 == 3)
        {                
            func_802D6590(2, 65.0 - (65.0 / D_80330418),
                (40.0 / D_80330418) - 40.0, 0);
            func_802D67A0(2, 1.0 / D_80330418, 1.0 / D_80330418, 1.0f);
        }
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 0x96);
        break;
    }

    func_802D6590(1, -5.0f, 2.0, 0);
    func_802D67A0(2, 1.1f, ((f32)sp47 / 4.0f) + 0.1, 1.0f);

    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EDE8);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

void func_802D8450(s8 a0, s8 a1)
{
    u8 sp17;

    if(a0 == 1)
    {
        if(a1 == 1)
        {
            gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
        }
        else
        {
            if(a1 == D_80330430)
            {
                sp17 = (gSineTable[D_80360080 >> 4] * 50.0f) + 200.0f;
                gDPSetEnvColor(gDisplayListHead++, sp17, sp17, sp17, 255);
            }
            else
            {
                gDPSetEnvColor(gDisplayListHead++, 200, 200, 200, 255);
            }
        }
    }
    else
    {
        switch(D_80330420)
        {
        case 0:
            break;
        case 1:
            gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, 255);
            break;
        }
    }
}

void func_802D8690(s8 sp23, s8 sp27, s8 *sp28, s8 *sp2c, s16 *sp30)
{
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    if(sp23 == sp27)
    {
        sp28[0] = 1;
        return;
    }

    func_802D6590(1, 5.0f, 2 - (sp23 * 20), 0);
    sp30[0] = 0;
    sp2c[0] = 1;
}

void func_802D875C(s8 *sp20, s16 *sp24)
{
    if(sp24[0] != 0)
        func_802D6590(2, sp20[0] * 10, 0, 0);

    func_802D6590(1, -2.0f, -5.0f, 0);
    func_802D6AFC(0xF1);

    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    sp24[0]++;
    sp20[0] = 1;
}

void func_802D8830(s8 *sp20, s16 *sp24)
{
    s8 sp1f = D_80360084 / 10;
    s8 sp1e = D_80360084 - (sp1f * 10); // remainder

    if(sp1f != 0)
    {
        func_802D6590(2, sp20[0] * 10, 0, 0);
        func_802D6AFC(sp1f);
    }
    else
    {
        sp20[0]++;
    }

    func_802D6590(2, sp20[0] * 10, 0, 0);
    func_802D6AFC(sp1e);

    sp24[0]++;
    sp20[0] = 1;
}

u32 func_802D8954(s16 a0)
{
    if(a0 < 0)
        a0 = 0;

    return a0;
}

void func_802D8980(s8 sp63, struct Struct802D8980 *sp64)
{
    UNUSED s32 u0, u1;

    u8 sp57;

    u8 *sp50 = (u8 *) segmented_to_virtual(sp64->unk0C);
    s8 sp4f = 1;

    s8 sp4e;

    s8 sp4d = 0;
    s8 sp4c = 0;
    s8 sp4b = 1;
    s8 sp4a = sp64->unk04;

    s16 sp48;
    s16 sp46;

    sp46 = 0;

    if(D_80330410 == 2)
        sp4e = (sp4a * 2) + 1;
    else
        sp4e = sp4a + 1;

    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EE68);
    sp48 = D_8033042C;

    if(D_80330410 == 2)
        func_802D6590(2, 0, (f32)D_8033041C, 0);

    func_802D6590(1, 5.0f, 2 - sp4f * 20, 0);

    while(sp4d == 0)
    {
        func_802D8450(sp63, sp4f);
        sp57 = sp50[sp48];

        switch(sp57)
        {
        case 0xFF:
            sp4d = 2;
            gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
            break;
        case 0xFE:
            sp4f++;
            func_802D8690(sp4f, sp4e, &sp4d, &sp4b, &sp46);
            break;
        case 0xF0:
            sp4c = 1;
            break;
        case 0xF1:
            sp4c = 2;
            break;
        case 0x9E: // [space] L802D8BC4
            if(sp46 != 0)
                sp4b++;

            sp46++;
            break;
        case 0x6E: // handakuten
            func_802D875C(&sp4b, &sp46);
            break;
        case 0xE0:
            func_802D8830(&sp4b, &sp46);
            break;
        default:
            if(sp46 != 0)
                func_802D6590(2, sp4b * 10, 0, 0);

            func_802D6AFC(sp57);
            sp4b = 1;
            sp46++;

            if(sp4c != 0)
            {
                func_802D6590(1, 5.0f, 7.0f, 0);
                func_802D6AFC(sp4c + 0xEF);
                gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
                sp4c = 0;
            }
        }

        if(sp46 == 12)
        {
            if(sp50[sp48+1] == 0x6E) // handakuten
            {
                func_802D875C(&sp4b, &sp46);
                sp48++;
            }

            if(sp50[sp48+1] == 0x6F) // comma
            {
                func_802D6590(2, sp4b * 10, 0, 0);
                func_802D6AFC(0x6F);
                sp48++;
            }

            if(sp50[sp48+1] == 0xFE) // newline
                sp48++;

            if(sp50[sp48+1] == 0xFF) // terminator
            {
                sp4d = 2;
                gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
                break; // exit loop
            }
            else
            {
                sp4f++;
                func_802D8690(sp4f, sp4e, &sp4d, &sp4b, &sp46);
            }
        }

        sp48++;
    }

    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EEF0);

    if(D_80330410 == 1)
    {
        if(sp4d == 2)
            D_80330428 = -1;
        else
            D_80330428 = sp48;
    }

    D_80360082 = sp4f;
}

void func_802D8ED4(void)
{
    if(D_80330410 == 1)
        func_802D7924(2, &D_80330430, 1, 2);

    func_802D6590(2, (D_80330430 * 50) - 25, 1 - (D_80360082 * 20), 0);

    if(D_80330420 == 0)
    {
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
    }
    else
    {
        gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, 255);
    }

    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EF60);
}

void func_802D9030(s8 sp3b)
{
    s32 sp34 = gGlobalTimer;

    if(sp34 & 0x08)
        return;

    func_802D6590(1, 123.0f, (sp3b * -20) + 2, 0);
    func_802D67A0(2, 0.8f, 0.8f, 1.0f);
    func_802D6694(2, -90.0f, 0, 0, 1.0f);

    if(D_80330420 == 0)
    {
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
    }
    else
    {
        gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, 255);
    }

    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EF60);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

void func_802D91C0(s16 sp4a)
{
    s16 sp3c[] = { 0x0011, 0x0072, 0x0080, 0x0075, 0x0096 }; // D_80330454
    s16 sp34[] = { 0x0005, 0x0009, 0x0037, 0x00A4 }; // D_80330460
    s16 sp28[] = { 0x000A, 0x000B, 0x000C, 0x000D, 0x000E }; // D_80330468
    s16 sp20[] = { 0x0011, 0x0073, 0x0076, 0x0098 }; // D_80330474

    s16 i;

    for(i = 0; i < (s16) ARRAY_COUNT(sp3c); i++)
    {
        if(sp3c[i] == sp4a)
        {
            func_80320040(0, 60);
            func_80320AE8(0, 1046, 0);
            return;
        }
    }

    for(i = 0; i < (s16) ARRAY_COUNT(sp34); i++)
    {
        if(sp34[i] == sp4a && D_80330430 == 1)
        {
            func_803212F0();
            return;
        }
    }

    for(i = 0; i < (s16) ARRAY_COUNT(sp28); i++)
    {
        if(sp28[i] == sp4a && D_80330430 == 1)
        {
            SetSound(0x701EFF81, D_803320E0);
            return;
        }
    }

    for(i = 0; i < (s16) ARRAY_COUNT(sp20); i++)
    {
        if(sp20[i] == sp4a)
        {
            func_8031F7CC(0, 1);
            return;
        }
    }
}

s16 D_8033047C = -1;

u8 D_80330480[] = {TEXT_MARIO_EXCLAMATION};
u8 D_80330488[] = {TEXT_POWER_STARS_RESTORED};
u8 D_8033049C[] = {TEXT_THANKS_TO_YOU};
u8 D_803304B0[] = {TEXT_THANK_YOU_MARIO};
u8 D_803304BC[] = {TEXT_SOMETHING_SPECIAL};
u8 D_803304CC[] = {TEXT_COME_ON_EVERYBODY};
u8 D_803304D4[] = {TEXT_LETS_HAVE_CAKE};
u8 D_803304E4[] = {TEXT_FOR_MARIO};
u8 D_803304F0[] = {TEXT_MARIO_QUESTION};

u8 *D_803304F8[] = {
    D_80330480,
    D_80330488,
    D_8033049C,
    D_803304B0,
    D_803304BC,
    D_803304CC,
    D_803304D4,
    D_803304E4,
    D_803304F0,
    NULL
};

u16 D_80330520 = 0;
s16 D_80330524 = -1;
s16 D_80330528 = -1;
s16 D_8033052C = 0;
s8 D_80330530 = 1;
s8 D_80330534 = 1;

void func_802D93E0(void)
{
    void **sp34 = segmented_to_virtual(seg2_dialog_table);
    struct Struct802D8980 *sp30 = segmented_to_virtual(sp34[D_80330424]);

    if(segmented_to_virtual(NULL) == sp30)
    {
        D_80330424 = -1;
        return;
    }

    switch(D_80330410)
    {
    case 0:
        if(D_80330414 == 90.0f)
        {
            func_80320A68(D_80330424);
            SetSound(0x70040081, D_803320E0);
        }

        if(D_80330420 == 0)
        {
            D_80330414 -= 7.5;
            D_80330418 -= 1.5;
        }
        else
        {
            D_80330414 -= 10.0;
            D_80330418 -= 2.0;
        }

        if(D_80330414 == 0.0f)
        {
            D_80330410 = 1;
            D_80330430 = 1;
        }
        break;
    case 1:
        D_80330414 = 0.0f;

        if((gPlayer3Controller->buttonPressed & 0x8000) ||
           (gPlayer3Controller->buttonPressed & 0x4000))
        {
            if(D_80330428 == -1)
            {
                func_802D91C0(D_80330424);
                D_80330410 = 3;
            }
            else
            {
                D_80330410 = 2;
                SetSound(0x70130081, D_803320E0);
            }
        }
        break;
    case 2:
        D_8033041C += sp30->unk04 * 2;

        if(D_8033041C >= sp30->unk04 * 20)
        {
            D_8033042C = D_80330428;
            D_80330410 = 1;
            D_8033041C = 0;
        }
        break;
    case 3:
        if(D_80330414 == 20.0f)
        {
            level_set_transition(0, 0);
            SetSound(0x70050081, D_803320E0);
            
            if(D_80330420 == 1)
                StopMario(2);

            D_80330440 = D_80330430;
        }

        D_80330414 = D_80330414 + 10.0f;
        D_80330418 = D_80330418 + 2.0f;

        if(D_80330414 == 90.0f)
        {
            D_80330410 = 0;
            D_80330424 = -1;
            D_8033042C = 0;
            D_80330434 = 0;
            D_80330428 = 0;
            D_80330440 = 0;
        }
        break;
    }

    func_802D8134(sp30, sp30->unk04);

    gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE,
        func_802D8954(sp30->unk06),
        func_802D8954(240 - sp30->unk08),
        func_802D8954(130 + sp30->unk06),
        func_802D8954(240 + ((sp30->unk04*80)/4) - sp30->unk08));

    func_802D8980(0, sp30);

    if(D_80330428 == -1 && D_80330434 == 1)
        func_802D8ED4();

    gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 2, 2, 316, 236);

    if(D_80330428 != -1 && D_80330410 == 1)
        func_802D9030(sp30->unk04);
}

void func_802D9A14(s16 a0)
{
    if(D_8033047C == -1)
        D_8033047C = a0;
}

void func_802D9A48(void)
{
    D_80330520 = 0;
}

void func_802D9A60(void)
{
    gSPDisplayList(gDisplayListHead++, seg2_dl_0200ED00);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, D_80330520);
}

void func_802D9AE8(void)
{
    gSPDisplayList(gDisplayListHead++, seg2_dl_0200ED68);

    if(D_80330520 < 250)
        D_80330520 += 25;
    else
        D_80330520 = 255;
}

// ascii_to_credits_char
u8 func_802D9B68(u8 c)
{
    if(c >= 'A' && c <= 'Z')
        return (c - 0x37);

    if(c >= 'a' && c <= 'z')
        return (c - 0x57);

    if(c == ' ') return 0x9E;
    if(c == '.') return 0x24;
    if(c == '3') return 0x03;
    if(c == '4') return 0x04;
    if(c == '6') return 0x06;

    return 0x9E;
}

void func_802D9C38(s16 x, s16 y, char *str)
{
    s32 pos = 0;
    u8 c = str[pos];
    u8 creditStr[100];

    while(c != 0)
    {
        creditStr[pos++] = func_802D9B68(c);
        c = str[pos];
    }

    creditStr[pos] = 0xFF;

    PutMiniString(x, y, creditStr);
}

void func_802D9CE8(s16 a0, s16 a1, s16 a2, s16 a3)
{
    if(D_80330524 == -1)
    {
        D_80330524 = a2;
        D_80330528 = a3;
        D_8033052C = 0;
        D_8036008A = a0;
        D_8036008C = a1;
        D_80330520 = 0;
    }
}

void func_802D9D5C(void)
{
    s16 sp26;

    if(D_80330524 == -1)
        return;

    func_802D68A4();

    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EE68);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, D_80330520);

    sp26 = func_802D7B3C(D_8036008A, D_803304F8[D_80330524], 10.0f);

    PrintGenericText(sp26, 240 - D_8036008C, D_803304F8[D_80330524]);

    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EEF0);

    if(D_8033052C < 5)
        D_80330520 += 50;

    if(D_80330528 + 5 < D_8033052C)
        D_80330520 -= 50;

    if(D_80330528 + 10 < D_8033052C)
    {
        D_80330524 = -1;
        D_80330520 = 0;
        D_8033052C = 0;
        return;
    }

    D_8033052C++;
}

void func_802D9F58(void)
{
    void **sp3c = segmented_to_virtual(seg2_dialog_table);
    struct Struct802D8980 *sp38 = segmented_to_virtual(sp3c[D_80330424]);

    u8 *sp34 = segmented_to_virtual(sp38->unk0C);

    func_802D6590(1, 97.0f, 118.0f, 0);

    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, D_80330520);
    gSPDisplayList(gDisplayListHead++, castle_grounds_seg7_dl_0700EA58);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EE68);
    gDPSetEnvColor(gDisplayListHead++, 20, 20, 20, D_80330520);

    PrintGenericText(53, 136, sp34);

    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EEF0);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);

    if(D_8033052C == 0)
        D_80330520 = 0;

    if(D_8033052C < 20)
        D_80330520 += 10;

    if(D_8033052C >= 0xAB)
        D_80330520 -= 10;

    if(D_8033052C >= 0xBF)
    {
        D_80330524 = -1;
        D_80330520 = 0;
        D_80330424 = -1;
        D_8033052C = 0;
        return;
    }

    D_8033052C++;
}

void RenderHudCannonReticle(void)
{
    func_802D6590(1, 160.0f, 120.0f, 0);

    gDPSetEnvColor(gDisplayListHead++, 50, 50, 50, 180);
    func_802D6590(1, -20.0f, -8.0f, 0);
    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EF60);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    func_802D6590(1, 20.0f, 8.0f, 0);
    func_802D6694(2, 180.0f, 0, 0, 1.0f);
    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EF60);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    func_802D6590(1, 8.0f, -20.0f, 0);
    func_802D6694(2, 90.0f, 0, 0, 1.0f);
    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EF60);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    func_802D6590(1, -8.0f, 20.0f, 0);
    func_802D6694(2, -90.0f, 0, 0, 1.0f);
    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EF60);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

void func_802DA4DC(void)
{
    D_8036008E = 0;
}

void func_802DA4F4(void)
{
    if(func_8028803C(0) == 1)
        D_80330530 = 1;
    else
        D_80330530 = 2;
}

void ShadeScreen(void)
{
    func_802D6590(1, 0, 240.0f, 0);
    func_802D67A0(2, 2.6f, 3.4f, 1.0f);
    gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, 110);
    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EDE8);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

void PrintAnimatedRedCoin(s16 sp4a, s16 sp4e)
{
    s32 timer = gGlobalTimer;

    func_802D6590(1, sp4a, sp4e, 0);
    func_802D67A0(2, 0.2f, 0.2f, 1.0f);
    gSPSetOtherMode(gDisplayListHead++, G_SET_OTHER_MODE_L, 3, 0x1E, 0x0F0A7008);

    switch(timer & 6)
    {
        case 0:
            gSPDisplayList(gDisplayListHead++, red_coin_seg3_dl_03007940);
            break;
        case 2:
            gSPDisplayList(gDisplayListHead++, red_coin_seg3_dl_03007968);
            break;
        case 4:
            gSPDisplayList(gDisplayListHead++, red_coin_seg3_dl_03007990);
            break;
        case 6:
            gSPDisplayList(gDisplayListHead++, red_coin_seg3_dl_030079B8);
            break;
    }

    gSPSetOtherMode(gDisplayListHead++, G_SET_OTHER_MODE_L, 3, 0x1E, 0x00552078);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

void func_802DA874(void)
{
    s8 sp1f;

    for(sp1f = 0; sp1f < D_8036008E; sp1f++)
    {
        PrintAnimatedRedCoin(290 - sp1f * 20,  16);
    }
}

void func_802DA8EC(void)
{
    u8 sp64[] = {TEXT_COURSE}; //D_80330538;
    u8 sp5c[] = {TEXT_MY_SCORE}; //D_8033053C;
    u8 sp58[] = {TEXT_STAR}; //D_80330544;
    u8 sp54[] = {TEXT_UNFILLED_STAR}; //D_80330548;

    u8 strCourseNum[4];

    void **levelNameTbl = segmented_to_virtual(seg2_level_name_table);
    u8 *levelName;

    void **actNameTbl = segmented_to_virtual(seg2_act_name_table);
    u8 *actName;

    u8 courseIndex = gCurrCourseNum - 1;
    u8 starFlags = save_file_get_star_flags(gCurrSaveFileNum - 1, gCurrCourseNum - 1);

    gSPDisplayList(gDisplayListHead++, seg2_dl_0200ED00);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, D_80360088);

    if(courseIndex < 15)
    {
        ShowCoins(1, gCurrSaveFileNum - 1, courseIndex, 178, 103);
        ShowStars(gCurrSaveFileNum - 1, courseIndex, 118, 103);
    }

    gSPDisplayList(gDisplayListHead++, seg2_dl_0200ED68);
    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EE68);

    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, D_80360088);

    if(courseIndex < 15 &&
        save_file_get_course_star_count(gCurrSaveFileNum - 1, courseIndex) != 0)
    {
        PrintGenericText(62, 121, sp5c);
    }

    levelName = segmented_to_virtual(levelNameTbl[courseIndex]);

    if(courseIndex < 15)
    {
        PrintGenericText(63, 157, sp64);
        Int2Str(gCurrCourseNum, strCourseNum);
        PrintGenericText(93, 157, strCourseNum);

        actName = segmented_to_virtual(actNameTbl[gCurrCourseNum * 6 + D_80330534 - 7]);

        if(starFlags & (1 << (D_80330534 + 31)))
            PrintGenericText(98, 140, sp58);
        else
            PrintGenericText(98, 140, sp54);

        PrintGenericText(116, 140, actName);
    }

    PrintGenericText(117, 157, &levelName[3]);

    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EEF0);
}

void PauseScreenCameraMenu(s16 sp72, s16 sp76, s8 *sp78, s16 sp7e)
{
    u8 sp64[] = {TEXT_LAKITU_MARIO}; //D_8033054C;
    u8 sp54[] = {TEXT_LAKITU_STOP}; //D_80330558;
    u8 sp48[] = {TEXT_NORMAL_UPCLOSE}; //D_80330568;
    u8 sp3c[] = {TEXT_NORMAL_FIXED}; //D_80330574;

    func_802D7924(2, sp78, 1, 2);

    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EE68);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, D_80360088);

    PrintGenericText(sp72+14, sp76+2, sp64);
    PrintGenericText(sp72+4, sp76-13, sp48);
    PrintGenericText(sp72+124, sp76+2, sp54);
    PrintGenericText(sp72+116, sp76-13, sp3c);

    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EEF0);
    func_802D6590(1, ((sp78[0] - 1) * sp7e) + sp72, sp76, 0);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, D_80360088);
    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EF60);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    switch(sp78[0])
    {
    case 1: func_8028803C(1); break;
    case 2: func_8028803C(2); break;
    }
}

void PauseScreen2(s16 sp62, s16 sp66, s8 *sp68, s16 sp6e)
{
    u8 sp50[] = {TEXT_CONTINUE}; //D_80330580;
    u8 sp44[] = {TEXT_EXIT_COURSE}; //D_80330590;
    u8 sp34[] = {TEXT_CAMERA_ANGLE_R}; //D_8033059C;

    func_802D7924(1, sp68, 1, 3);

    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EE68);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, D_80360088);

    PrintGenericText(sp62+10, sp66-2, sp50);
    PrintGenericText(sp62+10, sp66-17, sp44);

    if(sp68[0] != 3)
    {
        PrintGenericText(sp62+10, sp66-33, sp34);
        gSPDisplayList(gDisplayListHead++, seg2_dl_0200EEF0);

        func_802D6590(1, sp62, (sp66 - ((sp68[0] - 1) * sp6e)) - 4, 0);

        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, D_80360088);
        gSPDisplayList(gDisplayListHead++, seg2_dl_0200EF60);
        gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
    }

    if(sp68[0] == 3)
    {
        PauseScreenCameraMenu(sp62-42, sp66-42, &D_80330530, 110);
    }
}

void PauseCastleMenuBox(s16 sp42, s16 sp46)
{
    func_802D6590(1, sp42-78, sp46-32, 0);
    func_802D67A0(2, 1.2f, 0.8f, 1.0f);
    gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, 105);
    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EDE8);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    func_802D6590(1, sp42+6, sp46-28, 0);
    func_802D6694(2, 90.0f, 0, 0, 1.0f);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, D_80360088);
    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EF60);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
    
    func_802D6590(1, sp42-9, sp46-101, 0);
    func_802D6694(2, 270.0f, 0, 0, 1.0f);
    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EF60);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

void func_802DB540(void)
{
    u8 sp07;

    if(D_8032CE20 == 0)
    {
        sp07 = 0;
    }
    else
    {
        sp07 = D_8032CE20 - 1;

        if(sp07 >= 15)
            sp07 = 15;
    }

    D_80330430 = sp07;
}

void PauseScreen1(void)
{
    u8 sp28[] = {TEXT_PAUSE_ENG}; //D_803305AC;

    gSPDisplayList(gDisplayListHead++, seg2_dl_0200ED00);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, D_80360088);

    PutString(2, 123, 81, sp28);

    gSPDisplayList(gDisplayListHead++, seg2_dl_0200ED68);
}

void func_802DB698(s16 sp4a, s16 sp4e, s16 sp52, s16 sp56)
{
    s16 sp46 = 0;
    
    UNUSED u8 sp28[30];

    u8 sp24[] = {TEXT_STAR}; //D_803305B4;

    u8 sp23 = save_file_get_star_flags(sp52, sp56);
    u16 sp20 = save_file_get_course_star_count(sp52, sp56);

    u16 sp1e = 0;

    if(sp23 & 0x40)
    {
        sp20--;
        PrintGenericText(sp4a+89, sp4e-5, sp24);
    }

    while(sp46 != sp20)
    {
        if(sp23 & (1 << sp1e))
        {
            sp28[sp1e*2] = 250;
            sp46++;
        }
        else
        {
            sp28[sp1e*2] = 253;
        }

        sp28[sp1e*2+1] = 158;
        sp1e++;
    }

    if(sp20 == sp1e && sp20 != 6)
    {
        sp28[sp1e*2] = 253;
        sp28[sp1e*2+1] = 158;
        sp1e++;
    }

    sp28[sp1e*2] = 0xFF;

    PrintGenericText(sp4a+14, sp4e+13, sp28);
}

void func_802DB840(s16 sp52, s16 sp56)
{
    void **sp4c = segmented_to_virtual(seg2_level_name_table);

    u8 sp48[] = {TEXT_COIN_X}; //D_803305B8;

    void *sp44;

    u8 sp3c[8];
    s16 sp3a = D_80330430;

    func_802D7924(1, &D_80330430, -1, 16);

    if(D_80330430 == 16)
        D_80330430 = 0;

    if(D_80330430 == -1)
        D_80330430 = 15;

    if(D_80330430 != 15)
    {
        while(save_file_get_course_star_count(gCurrSaveFileNum-1, D_80330430) == 0)
        {
            if(D_80330430 >= sp3a)
                D_80330430++;
            else
                D_80330430--;
            
            if(D_80330430 == 15 || D_80330430 == -1)
            {
                D_80330430 = 15;
                break;
            }
        }
    }

    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EE68);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, D_80360088);

    if(D_80330430 < 15)
    {
        sp44 = segmented_to_virtual(sp4c[D_80330430]);
        func_802DB698(sp52, sp56, gCurrSaveFileNum-1, D_80330430);
        PrintGenericText(sp52+34, sp56-5, sp48);
        Int2Str(save_file_get_course_coin_score(gCurrSaveFileNum-1, D_80330430), sp3c);
        PrintGenericText(sp52+54, sp56-5, sp3c);
    }
    else
    {
        u8 sp2c[] = {TEXT_STAR_X}; // D_803305BC
        sp44 = segmented_to_virtual(sp4c[25]);
        PrintGenericText(sp52+40, sp56+13, sp2c);
        Int2Str(save_file_get_total_star_count(gCurrSaveFileNum-1, 15, 24), sp3c);
        PrintGenericText(sp52+60, sp56+13, sp3c);
    }

    PrintGenericText(sp52-9, sp56+30, sp44);

    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EEF0);
}

s8 D_803305C0 = 0;
s32 D_803305C4 = 0;
s32 D_803305C8 = 0; // gCourseCompleteMenuCoins
s8 D_803305CC = 0;

s16 func_802DBBB0(void)
{
    s16 sp26;

    switch(D_80330410)
    {
    case 0:
        D_80330430 = 1;
        D_80360088 = 0;
        level_set_transition(-1, 0);
        SetSound(0x7002F081, D_803320E0);

        if(gCurrCourseNum > 0 && gCurrCourseNum < 26)
        {
            func_802DA4F4();
            D_80330410 = 1;
        }
        else
        {
            func_802DB540();
            D_80330410 = 2;
        }
        break;
    case 1:
        ShadeScreen();
        func_802DA8EC();
        func_802DA874();

        if(gMarioStates[0].action & ACT_FLAG_PAUSE_EXIT)
            PauseScreen2(99, 93, &D_80330430, 15);

        if(gPlayer3Controller->buttonPressed & A_BUTTON ||
           gPlayer3Controller->buttonPressed & START_BUTTON)
        {
            level_set_transition(0, 0);
            SetSound(0x7003FF81, D_803320E0);
            D_80330410 = 0;
            D_8033047C = -1;

            if(D_80330430 == 2)
            {
                sp26 = D_80330430;
            }
            else
            {
                sp26 = 1;
            }

            return sp26;
        }
        break;
    case 2:
        ShadeScreen();
        PauseScreen1();
        PauseCastleMenuBox(160, 143);
        func_802DB840(104, 60);

        if(gPlayer3Controller->buttonPressed & A_BUTTON ||
           gPlayer3Controller->buttonPressed & START_BUTTON)
        {
            level_set_transition(0, 0);
            SetSound(0x7003FF81, D_803320E0);
            D_8033047C = -1;
            D_80330410 = 0;

            return 1;
        }
        break;
    }

    if(D_80360088 < 250)
        D_80360088 += 25;

    return 0;
}

void func_802DBE2C(s8 sp43)
{
    u8 sp38[] = {TEXT_HISCORE_ENG}; //D_803305D0;
    u8 sp28[] = {TEXT_CONGRATULATIONS_ENG}; //D_803305D8;

    u8 sp27 = (gSineTable[D_80360080 >> 4] * 50.0f) + 200.0f;

    gSPDisplayList(gDisplayListHead++, seg2_dl_0200ED00);
    gDPSetEnvColor(gDisplayListHead++, sp27, sp27, sp27, 255);

    if(sp43 == 0)
        PutString(2, 112, 48, sp38);
    else
        PutString(2, 60, 67, sp28);

    gSPDisplayList(gDisplayListHead++, seg2_dl_0200ED68);
}

void func_802DC050(s16 sp32, s16 sp36)
{
    u8 sp2c[4];
    u8 sp28[] = {TEXT_UNK33};// D_803305E8;
    u8 sp24[] = {TEXT_UNK32};// D_803305EC;

    gSPDisplayList(gDisplayListHead++, seg2_dl_0200ED00);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);

    PutString(2, sp32, sp36, sp28);
    PutString(2, sp32 + 16, sp36, sp24);

    Int2Str(D_803305C8, sp2c);
    PutString(2, sp32 + 32, sp36, sp2c);

    gSPDisplayList(gDisplayListHead++, seg2_dl_0200ED68);

    if(D_803305C8 >= gDisplayedCoins)
    {
        D_803305C0 = 1;
        D_803305C8 = gDisplayedCoins;

        if(D_8032CE2C != 0)
        {
            func_802DBE2C(0);
        }
    }
    else
    {
        if((D_803305C4 & 1) || gDisplayedCoins > 70)
        {
            D_803305C8++;
            SetSound(0x70150081, D_803320E0);

            if(D_803305C8 ==  50 || D_803305C8 == 100 || D_803305C8 == 150)
            {
                SetSound(0x3058FF81, D_803320E0);
                gMarioState[0].numLives++;
            }
        }

        if(gDisplayedCoins == D_803305C8 && D_8032CE2C != 0)
            SetSound(0x70222081, D_803320E0);
    }
}

void func_802DC2B4(s32 sp18, u8 sp1f)
{
    if(gDisplayedCoins == D_803305C8 &&
       (D_8032CE30 & sp1f) == 0 &&
       D_803305CC == 0)
    {
        func_80321264();
        D_803305CC = sp18;
    }
}

void func_802DC330(void)
{
    u8 sp7c[] = {TEXT_UNK35}; //D_803305F0;
    u8 sp78[] = {TEXT_COURSE};//D_803305F4;
    u8 sp70[] = {TEXT_CATCH};//D_803305F8;
    u8 sp68[] = {TEXT_CLEAR};//D_80330600;

    u8 **sp64 = segmented_to_virtual(seg2_act_name_table);
    u8 **sp60 = segmented_to_virtual(seg2_level_name_table);
    u8 *sp5c;

    u8 sp58[4];

    if(D_8032CE20 < 16)
    {
        func_802DC050(118, 103);
        func_802DC2B4(1, 1 << (D_8032CE24 + 31));

        if(D_8032CE24 == 7)
        {
            sp5c = segmented_to_virtual(sp64[91]);
        }
        else
        {
            sp5c = segmented_to_virtual(sp64[(D_8032CE20*6 + D_8032CE24) - 7]);
        }

        gSPDisplayList(gDisplayListHead++, seg2_dl_0200EE68);
        Int2Str(D_8032CE20, sp58);
        gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, D_80360088);
        PrintGenericText(65, 165, sp78);
        PrintGenericText(95, 165, sp58);
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, D_80360088);
        PrintGenericText(63, 167, sp78);
        PrintGenericText(93, 167, sp58);
        gSPDisplayList(gDisplayListHead++, seg2_dl_0200EEF0);
    }
    else if(D_8032CE20 == 16 || D_8032CE20 == 17)
    {
        sp5c = segmented_to_virtual(sp60[D_8032CE20-1]);
        gSPDisplayList(gDisplayListHead++, seg2_dl_0200EE68);
        gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, D_80360088);
        PrintGenericText(71, 130, sp5c);
        PrintGenericText(205, 130, sp68);
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, D_80360088);
        PrintGenericText(69, 132, sp5c);
        PrintGenericText(203, 132, sp68);
        gSPDisplayList(gDisplayListHead++, seg2_dl_0200EEF0);
        func_802DBE2C(1);
        func_802DC050(118, 111);
        func_802DC2B4(2, 0);
        return;
    }
    else
    {
        sp5c = segmented_to_virtual(sp64[90]);
        func_802DC050(118, 103);
        func_802DC2B4(1, 1 << (D_8032CE24 + 31));
    }

    gSPDisplayList(gDisplayListHead++, seg2_dl_0200ED00);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, D_80360088);
    PutString(2, 55, 77, sp7c);
    gSPDisplayList(gDisplayListHead++, seg2_dl_0200ED68);
    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EE68);
    gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, D_80360088);
    PrintGenericText(76, 145, sp5c);
    PrintGenericText(220, 145, sp70);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, D_80360088);
    PrintGenericText(74, 147, sp5c);
    PrintGenericText(218, 147, sp70);
    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EEF0);
}

void Save(s16 sp62, s16 sp66, s8 *sp68, s16 sp6e)
{
    u8 sp50[] = {TEXT_SAVE_AND_CONTINUE}; //D_80330608;
    u8 sp44[] = {TEXT_SAVE_AND_QUIT}; //D_80330618;
    u8 sp34[] = {TEXT_CONTINUE_WITHOUT_SAVING}; //D_80330624;

    func_802D7924(1, sp68, 1, 3);

    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EE68);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, D_80360088);

    PrintGenericText(sp62 + 10, sp66 + 2, sp50);
    PrintGenericText(sp62 + 10, sp66 - 18, sp44);
    PrintGenericText(sp62 + 10, sp66 - 38, sp34);

    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EEF0);

    func_802D6590(1, sp62, sp66 - ((sp68[0] - 1) * sp6e), 0);

    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, D_80360088);
    gSPDisplayList(gDisplayListHead++, seg2_dl_0200EF60);

    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

s16 func_802DCBD4(void)
{
    s16 sp26;

    switch(D_80330410)
    {
    case 0:
        func_802DC330();
        if(D_803305C4 > 100 && D_803305C0 == 1)
        {
            D_80330410 = 1;
            level_set_transition(-1, 0);
            D_80360088 = 0;
            D_80330430 = 1;
        }
        break;
    case 1:
        ShadeScreen();
        func_802DC330();
        Save(100, 86, &D_80330430, 20);

        if(D_803305C4 > 110 &&
           (gPlayer3Controller->buttonPressed & A_BUTTON ||
            gPlayer3Controller->buttonPressed & START_BUTTON))
        {
            level_set_transition(0, 0);
            SetSound(0x701EFF81, D_803320E0);
            D_80330410 = 0;
            D_8033047C = -1;
            sp26 = D_80330430;
            D_803305C4 = 0;
            D_803305C8 = 0;
            D_803305C0 = 0;
            D_803305CC = 0;

            return sp26;
        }
        break;
    }

    if(D_80360088 < 250)
    {
        D_80360088 += 25;
    }

    D_803305C4++;

    return 0;
}

s16 func_802DCD98()
{
    s16 sp26 = 0;

    func_802D68A4();

    if(D_8033047C != -1)
    {
        switch(D_8033047C)
        {
            case 0:
                sp26 = func_802DBBB0();
                break;
            case 1:
                sp26 = func_802DBBB0();
                break;
            case 2:
                sp26 = func_802DCBD4();
                break;
            case 3:
                sp26 = func_802DCBD4();
                break;
        }

        D_80360080 = (s16)D_80360080 + 0x1000;
    }
    else if(D_80330424 != -1)
    {
        if(D_80330424 == 20)
        {
            func_802D9F58();
            return sp26;
        }

        func_802D93E0();
        D_80360080 = (s16)D_80360080 + 0x1000;
    }

    return sp26;
}
