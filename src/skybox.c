#include <ultra64.h>

#include "sm64.h"
#include "math_util.h"
#include "memory.h"
#include "area.h"
#include "save_file.h"
#include "segment2.h"
#include "level_update.h"
#include "transparent_texture.h"

struct Struct8035FF50
{
    u16 unk0;
    s16 unk2;
    int unk4;
    int unk8;
    int unkC;
};

struct Struct8032FFC8
{
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 filler3[1];
};

// TODO: These should be defined here
extern struct Struct8035FF50 D_8035FF50[];
u32 D_8032FFA0[10] = 
{ 
    0x0A020000, 0x0A018800, 0x0A020000, 0x0A020000, 
    0x0A020000, 0x0A020000, 0x0A014800, 0x0A020000,
    0x0A014800, 0x0A020000,
};
u8 gSkyboxColors[][3] = 
{
    { 0x50, 0x64, 0x5A },
    { 0xFF, 0xFF, 0xFF },
};

//! double literals are used instead of floats

int func_802CEAD0(s8 a, float b)
{
    float spC = D_8035FF50[a].unk0;
    float sp8 = (115200.0 * spC) / (b * 65536.0);
    int sp4 = sp8 + 0.5;

    if (sp4 > 1280)
        sp4 -= sp4 / 1280 * 1280;
    return 1280 - sp4;
}

int func_802CEBBC(s8 a, UNUSED float b)
{
    float sp24 = (float)D_8035FF50[a].unk2 * 360.0 / 65535.0;
    float sp20 = 360.0f * sp24 / 90.0;
    int sp1C = round_float(sp20);
    int sp18 = sp1C + 0x258;

    if (sp18 > 960)
        sp18 = 960;
    if (sp18 < 240)
        sp18 = 240;
    return sp18;
}

int func_802CEC9C(s8 a)
{
    int sp4 = D_8035FF50[a].unk4 / 160;
    int sp0 = (960 - D_8035FF50[a].unk8) / 120;

    return sp0 * 10 + sp4;
}

// generates vertices for some rectangle
Vtx *make_skybox_rect(int a, s8 b)
{
    Vtx *verts = alloc_display_list(4 * sizeof(*verts));
    s16 x = a % 10 * 160;
    s16 y = 960 - a / 10 * 120;

    if (verts != NULL)
    {
        make_vertex(verts, 0,
            x, y, -1,
            0, 0,
            gSkyboxColors[b][0],
            gSkyboxColors[b][1],
            gSkyboxColors[b][2],
            255);
        make_vertex(verts, 1,
            x, y - 0x78, -1,
            0, 992,
            gSkyboxColors[b][0],
            gSkyboxColors[b][1],
            gSkyboxColors[b][2],
            255);
        make_vertex(verts, 2,
            x + 160, y - 0x78, -1,
            992, 992,
            gSkyboxColors[b][0],
            gSkyboxColors[b][1],
            gSkyboxColors[b][2],
            255);
        make_vertex(verts, 3,
            x + 160, y, -1,
            992, 0,
            gSkyboxColors[b][0],
            gSkyboxColors[b][1],
            gSkyboxColors[b][2],
            255);
    }
    else
    {
    }
    return verts;
}

struct Hack802CEF4C
{
    u32 arr[1];  // unknown length
};

void func_802CEF4C(Gfx **dlist, s8 b, s8 c, s8 d)
{
    int sp54;
    int sp50;

    for (sp54 = 0; sp54 < 3; sp54++)
    {
        for (sp50 = 0; sp50 < 3; sp50++)
        {
            int sp4C = D_8035FF50[c].unkC + sp54 * 10 + sp50;
            u32 sp48 = ((struct Hack802CEF4C *)segmented_to_virtual((void *)D_8032FFA0[b]))->arr[sp4C];
            Vtx *vertices = make_skybox_rect(sp4C, d);

            // Why is the width 1 here?
            gDPSetTextureImage((*dlist)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, sp48);
            gDPTileSync((*dlist)++);
            gDPSetTile((*dlist)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
            gDPLoadSync((*dlist)++);
            gDPLoadBlock((*dlist)++, 7, 0, 0, 1023, 256);
            gSPVertex((*dlist)++, VIRTUAL_TO_PHYSICAL(vertices), 4, 0);
            gSPDisplayList((*dlist)++, seg2_f3d_0144F0);
        }
    }
}

void *func_802CF188(s8 a)
{
    float left = D_8035FF50[a].unk4;
    float right = D_8035FF50[a].unk4 + 0x140;
    float bottom = D_8035FF50[a].unk8 - 0xF0;
    float top = D_8035FF50[a].unk8;
    Mtx *mtx = alloc_display_list(sizeof(*mtx));

    if (mtx != NULL)
    {
        guOrtho(mtx, left, right, bottom, top, 0.0f, 3.0f, 1.0f);
    }
    else
    {
    }

    return mtx;
}

Gfx *func_802CF2A8(s8 a, s8 b, s8 c)
{
    int sp3C = 68;
    void *sp38 = alloc_display_list(sp3C * 8);
    Gfx *dlist = sp38;

    if (sp38 == NULL)
    {
        return NULL;
    }
    else
    {
        Mtx *mtx = func_802CF188(a);

        gSPDisplayList(dlist++, seg2_f3d_014708);
        gSPMatrix(dlist++, VIRTUAL_TO_PHYSICAL(mtx), G_MTX_PROJECTION | G_MTX_MUL);
        gSPDisplayList(dlist++, seg2_f3d_014738);
        func_802CEF4C(&dlist, b, a, c);
        gSPDisplayList(dlist++, seg2_f3d_014768);
        gSPEndDisplayList(dlist);
    }
    return sp38;
}

Gfx *func_802CF414(s8 a, s8 b, float c, float d, float e, float f, float g,
    float h, float i)
{
    float sp34 = g - d;
    float sp30 = h - e;
    float sp2C = i - f;
    s8 sp2B = 1;

    if (b == 8 && !(save_file_get_star_flags(gCurrSaveFileNum - 1, 2) & 1))
        sp2B = 0;

    c = 90.0f;
    D_8035FF50[a].unk0 = atan2s(sp2C, sp34);
    D_8035FF50[a].unk2 = atan2s(sqrtf(sp34 * sp34 + sp2C * sp2C), sp30);
    D_8035FF50[a].unk4 = func_802CEAD0(a, c);
    D_8035FF50[a].unk8 = func_802CEBBC(a, c);
    D_8035FF50[a].unkC = func_802CEC9C(a);

    return func_802CF2A8(a, b, sp2B);
}
