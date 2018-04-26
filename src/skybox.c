#include <ultra64.h>

#include "sm64.h"
#include "save_file.h"

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
extern u8 D_8032FFC8[][3];
extern u32 D_8032FFA0[];

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
    int sp1C = func_802D17E4(sp20);
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

void *func_802CED24(int a, s8 b)
{
    void *sp3C = alloc_display_list(64);
    s16 sp3A = a % 10 * 160;
    s16 sp38 = 960 - a / 10 * 120;

    if (sp3C != NULL)
    {
        func_802D1730(sp3C, 0, sp3A, sp38, -1, 0, 0,
            D_8032FFC8[b][0],
            D_8032FFC8[b][1],
            D_8032FFC8[b][2],
            255);
        func_802D1730(sp3C, 1, sp3A, sp38 - 0x78, -1, 0, 992,
            D_8032FFC8[b][0],
            D_8032FFC8[b][1],
            D_8032FFC8[b][2],
            255);
        func_802D1730(sp3C, 2, sp3A + 160, sp38 - 0x78, -1, 992, 992,
            D_8032FFC8[b][0],
            D_8032FFC8[b][1],
            D_8032FFC8[b][2],
            255);
        func_802D1730(sp3C, 3, sp3A + 160, sp38, -1, 992, 0,
            D_8032FFC8[b][0],
            D_8032FFC8[b][1],
            D_8032FFC8[b][2],
            255);
    }
    else
    {
    }
    return sp3C;
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
            u32 sp48 = ((struct Hack802CEF4C *)SegmentedToVirtual((void *)D_8032FFA0[b]))->arr[sp4C];
            void *vertices = func_802CED24(sp4C, d);

            // Why is the width 1 here?
            gDPSetTextureImage((*dlist)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, sp48);
            gDPTileSync((*dlist)++);
            gDPSetTile((*dlist)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
            gDPLoadSync((*dlist)++);
            gDPLoadBlock((*dlist)++, 7, 0, 0, 1023, 256);

            // gSPVertex
            {
                Gfx *g = (*dlist)++;
                g->words.w0 = 0x04300040;
                g->words.w1 = (u32)vertices & 0x1FFFFFFF;
            }

            gSPDisplayList((*dlist)++, D_020144F0);
        }
    }
}

void *func_802CF188(s8 a)
{
    float sp3C = D_8035FF50[a].unk4;
    float sp38 = D_8035FF50[a].unk4 + 0x140;
    float sp34 = D_8035FF50[a].unk8 - 0xF0;
    float sp30 = D_8035FF50[a].unk8;
    void *sp2C = alloc_display_list(64);

    if (sp2C != NULL)
    {
        guFrustum(sp2C, sp3C, sp38, sp34, sp30, 0.0f, 3.0f, 1.0f);
    }
    else
    {
    }

    return sp2C;
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
        void *sp30 = func_802CF188(a);

        gSPDisplayList(dlist++, D_02014708);

        {
            Gfx *g = dlist++;
            g->words.w0 = 0x01010040;
            g->words.w1 = (u32)sp30 & 0x1FFFFFFF;
        }

        gSPDisplayList(dlist++, D_02014738);

        func_802CEF4C(&dlist, b, a, c);

        gSPDisplayList(dlist++, D_02014768);
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

    if (b == 8 && !(save_file_get_obtained_stars(gCurrSaveFileNum - 1, 2) & 1))
        sp2B = 0;

    c = 90.0f;
    D_8035FF50[a].unk0 = func_8037A9A8(sp2C, sp34);
    D_8035FF50[a].unk2 = func_8037A9A8(sqrtf(sp34 * sp34 + sp2C * sp2C), sp30);
    D_8035FF50[a].unk4 = func_802CEAD0(a, c);
    D_8035FF50[a].unk8 = func_802CEBBC(a, c);
    D_8035FF50[a].unkC = func_802CEC9C(a);

    return func_802CF2A8(a, b, sp2B);
}
