#include <ultra64.h>

#include "sm64.h"
#include "libultra.h"
#include "display.h"
#include "game.h"
#include "level_update.h"
#include "camera.h"
#include "print.h"
#include "ingame_menu.h"
#include "hud_print.h"
#include "segment2.h"

/* The hidden second half of hud.s
 * This file seems to draw the in-game HUD
**/

/* External Declarations */
/*obj_behaviors_1.rodata.s*/ extern f64 D_803371E0;
/*obj_behaviors_1.rodata.s*/ extern f64 D_803371E8;
//TODO: match unkXX nomenclature
struct HUD803314E0 {
    s8  d_E0;
    s16 d_E2;
    s16 d_E4;
    f32 u_E8;
    s32 d_EC;
    u32 u_F0;
    u16 u_F4;
    u16 u_F6;
    s16 d_F8;
};

// some sort of store for shown health wedges (0-8); maybe from previous frame/update?
static s16 D_803600D0;

static struct HUD803314E0 hudStruct = {
    0x00, 140, 166, 1.0, 0x00000000,
    0x00000000, 0x000A, 0x0000, 0x0000
};

void render_hud_camera(s32 x, s32 y, u8 texture[])
{
    gDPPipeSync(gDisplayListHead++);
    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, (u32) texture);
    gSPDisplayList(gDisplayListHead++, &seg2_f3d_00EC98);
    gSPTextureRectangle(gDisplayListHead++, x << 2, y << 2, (x + 15) << 2, (y + 15) << 2, G_TX_RENDERTILE, 0, 0, 0x1000, 0x400);
}

void render_hud_c_buttons(s32 x, s32 y, u8 texture[])
{
    gDPSetTile(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, (G_TX_NOMIRROR | G_TX_WRAP), G_TX_NOMASK, G_TX_NOLOD, (G_TX_NOMIRROR | G_TX_WRAP), G_TX_NOMASK, G_TX_NOLOD);
    gDPTileSync(gDisplayListHead++);
    gDPSetTile(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 2, 0, G_TX_RENDERTILE, 0, (G_TX_NOMIRROR | G_TX_CLAMP), 3, G_TX_NOLOD, (G_TX_NOMIRROR | G_TX_CLAMP), 3, G_TX_NOLOD);
    gDPSetTileSize(gDisplayListHead++, G_TX_RENDERTILE, 0, 0, 28, 28);
    gDPPipeSync(gDisplayListHead++);
    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, (u32) texture);
    gDPLoadSync(gDisplayListHead++);
    gDPLoadBlock(gDisplayListHead++, G_TX_LOADTILE, 0, 0, 63, 1024);
    gSPTextureRectangle(gDisplayListHead++, x << 2, y << 2, (x + 7) << 2, (y + 7) << 2, G_TX_RENDERTILE, 0, 0, 0x1000, 0x400);
}

void func_802E21A4(s16 numHealthWedges)
{
    u8* (*sp34)[];

    sp34 = segmented_to_virtual(&D_030293E0);
    
    gDPPipeSync(gDisplayListHead++);
    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, (*sp34)[numHealthWedges - 1]);
    gDPLoadSync(gDisplayListHead++);
    gDPLoadBlock(gDisplayListHead++, G_TX_LOADTILE, 0, 0, 1023, 256);
    gSP1Triangle(gDisplayListHead++, 0, 1, 2, 0);
    gSP1Triangle(gDisplayListHead++, 0, 2, 3, 0);
}

void func_802E2304(s16 numHealthWedges)
{
    Mtx * sp2C;

    sp2C = alloc_display_list(0x40);

    if (sp2C == NULL)
        return;

    guTranslate(sp2C, (f32) hudStruct.d_E2, (f32) hudStruct.d_E4, 0);

    gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(sp2C++), (G_MTX_MODELVIEW|G_MTX_MUL|G_MTX_PUSH));
    gSPDisplayList(gDisplayListHead++, &D_03029480);

    if (numHealthWedges != 0)
    {
        gSPDisplayList(gDisplayListHead++, &D_03029570);
        func_802E21A4(numHealthWedges);
        gSPDisplayList(gDisplayListHead++, &D_030295A0);
    }

    gSPPopMatrix(gDisplayListHead++, 0);
}


void func_802E24A8(void)
{
    s16 hudDisplayFlags;
    hudDisplayFlags = gHudDisplayFlags;

    if (!(hudDisplayFlags & 0x8000))    //0x8000 = gMarioState->hurtCounter > 0 flag
    {
        if ( (f64) hudStruct.d_EC == D_803371E0 )
            hudStruct.d_E0 = 2;
    } else {
        hudStruct.d_EC = 0;
    }
}

void func_802E2520(void)
{
    s16 sp6 = 5;
    
    if (hudStruct.d_E4 >= 0xB5)
        sp6 = 3;
    
    if (hudStruct.d_E4 >= 0xBF)
        sp6 = 2;
    
    if (hudStruct.d_E4 >= 0xC4)
        sp6 = 1;
    
    hudStruct.d_E4 += sp6;

    if (hudStruct.d_E4 >= 0xC9)
    {
        hudStruct.d_E4 = 0xC8;
        hudStruct.d_E0 = 4;
    }
}

void func_802E25D4(void)
{
    hudStruct.d_E4 += 0x14;
    if (hudStruct.d_E4 >= 0x12D)
    {
        hudStruct.d_E0 = 0;
        hudStruct.d_EC = 0;
    }
}

void func_802E261C(s16 numHealthWedges)
{
    if (numHealthWedges < 8 && D_803600D0 == 8 && hudStruct.d_E0 == 0)
    {
        hudStruct.d_E0 = 1;
        hudStruct.d_E4 = 0xA6;
    }

    if (numHealthWedges == 8 && D_803600D0 == 7)
        hudStruct.d_EC = 0;
    
    if (numHealthWedges == 8 && (f64) hudStruct.d_EC > D_803371E8)
        hudStruct.d_E0 = 3;
    
    D_803600D0 = numHealthWedges;

    if (D_8033B1B0[0] & 0x2000)
    {
        if (hudStruct.d_E0 == 0 || hudStruct.d_E0 == 1)
        {
            hudStruct.d_E0 = 2;
            hudStruct.d_E4 = 0xA6;
        }
        hudStruct.d_EC = 0;
    }
}

void render_hud_hp(void)
{
    s16 shownHealthWedges = gDisplayedHealthWedges;

    if (hudStruct.d_E0 != 3)
        func_802E261C(shownHealthWedges);
    
    if (hudStruct.d_E0 == 0)
        return;

    switch (hudStruct.d_E0)
    {
        case 1:
            func_802E24A8();
            break;
        case 2:
            func_802E2520();
            break;
        case 3:
            func_802E25D4();
            break;
        default:
            break;
    }

    func_802E2304(shownHealthWedges);

    hudStruct.d_EC += 1;
}

void render_hud_mario_lives(void)
{
    print_text(22, 210, ",");   // 'Mario Head' glyph
    print_text(38, 210, "*");   // 'X' glyph
    print_text_fmt_int(54, 210, "%d", gDisplayedLives);
}

void render_hud_coins(void)
{
    print_text(168, 210, "+");  // 'Coin' glyph
    print_text(184, 210, "*");  // 'X' glyph
    print_text_fmt_int(198, 210, "%d", gDisplayedCoins);
}

void render_hud_stars(void)
{
    s8 showX = 0;

    if (D_803305CC == 1 && D_8032C694 & 0x00000008)
        return;
    
    if (gDisplayedStars < 100)
        showX = 1;
    
    print_text(247, 210, "-");                  // 'Star' glyph
    if (showX == 1) print_text(263, 210, "*");  // 'X' glyph
    print_text_fmt_int(((showX * 14) + 263), 210, "%d", gDisplayedStars);
}

void func_802E29D4()
{
    s16 i;

    for (i = 0; i < gDisplayedKeys; i++)
        print_text((i * 16) + 220, 142, "/");     // unused glyph (originally for a key?)
}

void render_hud_timer(void)
{
    u8* (*hudPrintLUT)[58];
    u16 timerValFrames;
    u16 timerMins;
    u16 timerSecs;
    u16 timerFracSecs;

    hudPrintLUT = segmented_to_virtual(&seg2_hud_lut);
    timerValFrames = gTimerValueInFrames;
    timerMins = timerValFrames / (30 * 60);
    timerSecs = (timerValFrames - (timerMins * 1800)) / 30;

    timerFracSecs = ((timerValFrames - (timerMins * 1800) - (timerSecs * 30)) & 0xFFFF) / 3;

    print_text(170, 185, "TIME");
    print_text_fmt_int(229, 185,  "%0d", timerMins);
    print_text_fmt_int(249, 185, "%02d", timerSecs);
    print_text_fmt_int(283, 185,   "%d", timerFracSecs);
    gSPDisplayList(gDisplayListHead++, seg2_f3d_00EC60);
    render_hud_camera(239, 32, (*hudPrintLUT)[56]);
    render_hud_camera(274, 32, (*hudPrintLUT)[57]);
    gSPDisplayList(gDisplayListHead++, seg2_f3d_00ECC8);
}

void set_camera_status(s16 a0)
{
    hudStruct.d_F8 = a0;
}

void show_camera_status(void)
{
    u8* (*cameraLUT)[6];
    s32 x;
    s32 y;

    cameraLUT = segmented_to_virtual(&seg2_hud_camera_lut);
    x = 266;
    y = 205;

    if (hudStruct.d_F8 == 0)
        return;
    
    gSPDisplayList(gDisplayListHead++, seg2_f3d_00EC60);
    render_hud_camera(x, y, (*cameraLUT)[0]);

    switch (hudStruct.d_F8 & 0x07)
    {
        case 1 << 0:    // 1
            render_hud_camera(x + 16, y, (*cameraLUT)[1]);
            break;
        case 1 << 1:    // 2
            render_hud_camera(x + 16, y, (*cameraLUT)[2]);
            break;
        case 1 << 2:    // 4
            render_hud_camera(x + 16, y, (*cameraLUT)[3]);
            break;
    }

    switch (hudStruct.d_F8 & 0x18)
    {
        case 1 << 3:    // 8
            render_hud_c_buttons(x + 4, y + 16, (*cameraLUT)[5]);
            break;
        case 1 << 4:    // 16
            render_hud_c_buttons(x + 4, y - 8, (*cameraLUT)[4]);
            break;
    }

    gSPDisplayList(gDisplayListHead++, seg2_f3d_00ECC8);
}

void render_hud(void)
{
    s16 hudDisplayFlags;

    hudDisplayFlags = gHudDisplayFlags;

    if (hudDisplayFlags == 0)
    {
        hudStruct.d_E0 = 0;
        D_803600D0 = 8;
        hudStruct.d_EC = 0;
    } else {
        func_802D68A4();

        if (D_8032CE6C != NULL && D_8032CE6C->unk24->unk0 == 10)
            RenderHudCannonReticle();
        
        if (hudDisplayFlags & (1 << 0))    // 0x01
            render_hud_mario_lives();
        
        if (hudDisplayFlags & (1 << 1))    // 0x02
            render_hud_coins();
        
        if (hudDisplayFlags & (1 << 2))    // 0x04
            render_hud_stars();
        
        if (hudDisplayFlags & (1 << 4))    // 0x10
            func_802E29D4();
        
        if (hudDisplayFlags & (1 << 3))    // 0x08
        {
            render_hud_hp();
            show_camera_status();
        }

        if (hudDisplayFlags & (1 << 6))    // 0x40
            render_hud_timer();
    }
}
