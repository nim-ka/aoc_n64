#include <ultra64.h>

#include "sm64.h"
#include "display.h"
#include "memory.h"
#include "ingame_menu.h"
#include "ingame_menu_2.h"
#include "ingame_menu_3.h"
#include "surface_collision.h"
#include "math_util.h"
#include "behavior_script.h"
#include "audio/interface_2.h"
#include "obj_behaviors.h"
extern struct MemoryPool *D_8033A124;
struct struct802DE838 {
    s16 unk00;
    s16 unk02;
    s16 unk04;
};

struct struct802DCEE0 *D_80360090;
Vec3i D_80360098;
s16 D_803600A4;
s16 D_803600A6;


/* DATA */
s8 D_80330640 = 0;
UNUSED s32 D_80330644 = 0;
Vtx_t D_80330648[3] = 
{
    {
        {-5, 5, 0},
        0,
        {0, 0},
        {0x7F, 0x7F, 0x7F, 0xFF}
    },
    {
        {-5, -5, 0},
        0,
        {0, 960},
        {0x7F, 0x7F, 0x7F, 0xFF}
    },
    {
        {5, 5, 0},
        0,
        {960, 0},
        {0x7F, 0x7F, 0x7F, 0xFF}
    },
};
struct struct802DE838 D_80330678 = {-5, 5, 0};
struct struct802DE838 D_80330680 = {-5, -5, 0};
struct struct802DE838 D_80330688 = {5, 5, 0};

extern void *tiny_bubble_dl_0B006AB0;
extern void *tiny_bubble_dl_0B006A50;
extern void *tiny_bubble_dl_0B006CD8;

s32 func_802DCEE0(s32 sp28) {
    switch (sp28) {
        case 0:
            return 0;

        case 1:
            D_803600A6 = 140;
            D_803600A4 = 5;
            break;

        case 2:
            D_803600A6 = 30;
            D_803600A4 = 30;
            break;

        case 3:
            D_803600A6 = 140;
            D_803600A4 = 140;
            break;
    }

    D_80360090 = (struct struct802DCEE0 *)mem_pool_alloc(D_8033A124, D_803600A6 * sizeof(struct struct802DCEE0));
    if (!D_80360090)
        return 0;

    bzero(D_80360090, D_803600A6 * sizeof(struct struct802DCEE0));

    D_80330640 = sp28;
    return 1;
}

void func_802DD028(s32 sp30, Vec3s sp34) {
    s32 sp2C = gGlobalTimer;
    f32 sp28;
    switch (sp30) {
        case 1:
            if (D_803600A6 > D_803600A4) {
                if ((sp2C & 0x3F) == 0)
                    D_803600A4 += 5;
            }
            break;

        case 2:
            sp28 = find_water_level(sp34[0], sp34[2]);
            
            D_803600A4 = (((s32)((sp28 - 400.f - (f32)sp34[1]) * 1.0e-3) << 0x10) >> 0x10) * 5;

            if (D_803600A4 < 0)
                D_803600A4 = 0;

            if (D_803600A4 > D_803600A6)
                D_803600A4 = D_803600A6;

            break;

        case 3:
            break;

    }
}

void func_802DD1AC(void *sp18) {
    if (D_80330640) {
        if (sp18) {
            mem_pool_free(D_8033A124, sp18);
        }
        D_80330640 = 0;
    }
}

void func_802DD204(Vec3s sp30, Vec3s sp34, s16 *sp38, s16 *sp3C, s16 *sp40) {
    f32 sp2C = sp34[0] - sp30[0];
    f32 sp28 = sp34[1] - sp30[1];  
    f32 sp24 = sp34[2] - sp30[2];  

    *sp38 = (s16)sqrtf(sp2C * sp2C + sp28 * sp28 + sp24 * sp24);
    *sp3C = atan2s(sqrtf(sp2C * sp2C + sp24 * sp24), sp28);
    *sp40 = atan2s(sp24, sp2C);
}

void func_802DD32C(Vec3s a0, Vec3s a1, s16 a2, s16 a3, s16 sp12) {
    a1[0] = a0[0] + a2 * coss(a3) * sins(sp12);
    a1[1] = a0[1] + a2 * sins(a3);
    a1[2] = a0[2] + a2 * coss(a3) * coss(sp12);
}

s32 func_802DD450(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 spC = (D_80360090 + a0)->unk04;
    s32 sp8 = (D_80360090 + a0)->unk08;
    s32 sp4 = (D_80360090 + a0)->unk0C;

    if ((spC - a1) * (spC - a1) 
        + (sp4 - a3) * (sp4 - a3) >= 0x00015F91)
        return 0;

    if ((sp8 < a2 - 0xC9) || (a2 + 0xC9 < sp8))
        return 0;
    
    return 1;
}

void func_802DD548(s32 sp38, s32 sp3C, s32 sp40) {
    s32 sp34;
    s32 sp30 = sp38 - D_80360098[0];
    s32 sp2C = sp3C - D_80360098[1];
    s32 sp28 = sp40 - D_80360098[2];

    for (sp34 = 0; sp34 < D_803600A4; sp34++) {
        (D_80360090 + sp34)->unk00 = func_802DD450(sp34, sp38, sp3C, sp40);
        if ((D_80360090 + sp34)->unk00 == 0)  {
            (D_80360090 + sp34)->unk04 = 400.0f * RandomFloat() - 200.0f + sp38 + (s16)(sp30 * 2);
            (D_80360090 + sp34)->unk0C = 400.0f * RandomFloat() - 200.0f + sp40 + (s16)(sp28 * 2);
            (D_80360090 + sp34)->unk08 = 200.0f * RandomFloat() + sp3C;
            (D_80360090 + sp34)->unk00 = 1;   
        } else {
            (D_80360090 + sp34)->unk04 += RandomFloat() * 2.0f - 1.0f + (s16)(sp30 / 1.2);
            (D_80360090 + sp34)->unk08 -= -(s16)(sp2C * 0.8) + 2;
            (D_80360090 + sp34)->unk0C += RandomFloat() * 2.0f - 1.0f + (s16)(sp28 / 1.2); 
        }
    }

    D_80360098[0] = sp38;
    D_80360098[1] = sp3C;
    D_80360098[2] = sp40;
}

void func_802DD978(s32 sp38, s32 sp3C, s32 sp40) {
    s32 sp34;
    s32 sp30 = sp38 - D_80360098[0];
    s32 sp2C = sp3C - D_80360098[1];
    s32 sp28 = sp40 - D_80360098[2];

    for (sp34 = 0; sp34 < D_803600A4; sp34++) {
        (D_80360090 + sp34)->unk00 = func_802DD450(sp34, sp38, sp3C, sp40);
        if ((D_80360090 + sp34)->unk00 == 0)  {
            (D_80360090 + sp34)->unk04 = 400.0f * RandomFloat() - 200.0f + sp38 + (s16)(sp30 * 2);
            (D_80360090 + sp34)->unk0C = 400.0f * RandomFloat() - 200.0f + sp40 + (s16)(sp28 * 2);
            (D_80360090 + sp34)->unk08 = 400.0f * RandomFloat() - 200.0f + sp3C;
            (D_80360090 + sp34)->unk00 = 1;   
        } else {
            (D_80360090 + sp34)->unk04 += RandomFloat() * 2.0f - 1.0f + (s16)(sp30 / 1.2) + 20.0f;
            (D_80360090 + sp34)->unk08 -= -(s16)(sp2C * 0.8) + 5;
            (D_80360090 + sp34)->unk0C += RandomFloat() * 2.0f - 1.0f + (s16)(sp28 / 1.2);           
        }
    }

    D_80360098[0] = sp38;
    D_80360098[1] = sp3C;
    D_80360098[2] = sp40;
}

s32 Unknown802DDDC4(s32 a0, UNUSED s32 sp4, s32 a2) {
    if (sqr(a0 - 3380) + sqr(a2 + 520) < 0x00895440) 
        return 1;
    
    return 0;
}

void func_802DDE28(s32 sp20, s32 sp24, s32 sp28) {
    s32 sp1C;

    for (sp1C = 0; sp1C < D_803600A4; sp1C++) {
        (D_80360090 + sp1C)->unk00 = func_802DD450(sp1C, sp20, sp24, sp28);
        if ((D_80360090 + sp1C)->unk00 == 0)  {
            (D_80360090 + sp1C)->unk04 = 400.0f * RandomFloat() - 200.0f + sp20;
            (D_80360090 + sp1C)->unk0C = 400.0f * RandomFloat() - 200.0f + sp28;
            (D_80360090 + sp1C)->unk08 = 400.0f * RandomFloat() - 200.0f + sp24;
            (D_80360090 + sp1C)->unk00 = 1;   
        }
    }
}

void func_802DE01C(Vec3s a0, Vec3s a1, Vec3s a2, s16 a3, s16 sp48) {
    f32 sp34 = coss(a3);
    f32 sp30 = sins(a3);
    f32 sp2C = coss(-sp48);
    f32 sp28 = sins(-sp48);

    Vec3f sp1C, sp10, sp4;

    sp1C[0] = a0[0];
    sp1C[1] = a0[1];
    sp1C[2] = a0[2];

    sp10[0] = a1[0];
    sp10[1] = a1[1];
    sp10[2] = a1[2];

    sp4[0] = a2[0];
    sp4[1] = a2[1];
    sp4[2] = a2[2];

    a0[0] = sp1C[0] * sp2C + sp1C[1] * (sp30 * sp28) + sp1C[2] * (-sp28 * sp34);
    a0[1] = sp1C[1] * sp34 + sp1C[2] * sp30; 
    a0[2] = sp1C[0] * sp28 + sp1C[1] * (-sp30 * sp2C) + sp1C[2] * (sp34 * sp2C);

    a1[0] = sp10[0] * sp2C + sp10[1] * (sp30 * sp28) + sp10[2] * (-sp28 * sp34);
    a1[1] = sp10[1] * sp34 + sp10[2] * sp30; 
    a1[2] = sp10[0] * sp28 + sp10[1] * (-sp30 * sp2C) + sp10[2] * (sp34 * sp2C);

    a2[0] = sp4[0] * sp2C + sp4[1] * (sp30 * sp28) + sp4[2] * (-sp28 * sp34);
    a2[1] = sp4[1] * sp34 + sp4[2] * sp30; 
    a2[2] = sp4[0] * sp28 + sp4[1] * (-sp30 * sp2C) + sp4[2] * (sp34 * sp2C);
}

void func_802DE424(Gfx *sp28, s32 sp2C, Vec3s sp30, Vec3s sp34, Vec3s sp38) {
    s32 sp24 = 0;
    Vtx *sp20 = (Vtx *)alloc_display_list(15 * sizeof(Vtx));

    if (sp20 == NULL)
        return;

    sp24 = 0;
    do {
        sp20[sp24] = ((Vtx *)D_80330648)[0];
        sp20[sp24].v.ob[0] = sp30[0] + (D_80360090 + (sp2C + sp24 / 3))->unk04;
        sp20[sp24].v.ob[1] = sp30[1] + (D_80360090 + (sp2C + sp24 / 3))->unk08;
        sp20[sp24].v.ob[2] = sp30[2] + (D_80360090 + (sp2C + sp24 / 3))->unk0C;

        sp20[sp24 + 1] = ((Vtx *)D_80330648)[1];
        sp20[sp24 + 1].v.ob[0] = sp34[0] + (D_80360090 + (sp2C + sp24 / 3))->unk04;
        sp20[sp24 + 1].v.ob[1] = sp34[1] + (D_80360090 + (sp2C + sp24 / 3))->unk08;
        sp20[sp24 + 1].v.ob[2] = sp34[2] + (D_80360090 + (sp2C + sp24 / 3))->unk0C;
        
        sp20[sp24 + 2] = ((Vtx *)D_80330648)[2];
        sp20[sp24 + 2].v.ob[0] = sp38[0] + (D_80360090 + (sp2C + sp24 / 3))->unk04;
        sp20[sp24 + 2].v.ob[1] = sp38[1] + (D_80360090 + (sp2C + sp24 / 3))->unk08;
        sp20[sp24 + 2].v.ob[2] = sp38[2] + (D_80360090 + (sp2C + sp24 / 3))->unk0C;
    }
    while ((sp24 += 3) < 15);

    gSPVertex(sp28, VIRTUAL_TO_PHYSICAL(sp20), 15, 0);
}

Gfx *func_802DE838(s32 sp80, Vec3s sp84, Vec3s sp88, Vec3s sp8C) {
    s32 sp7C;
    s16 sp7A, sp78, sp76;
    Vec3s sp70;
    struct struct802DE838 sp68, sp60, sp58;
    Gfx *sp54;
    Gfx *sp50;

    sp68 = D_80330678;
    sp60 = D_80330680;
    sp58 = D_80330688;

    sp54 = (Gfx *)alloc_display_list((D_803600A4 * 6 + 3) * sizeof(Gfx));   
    sp50 = sp54;

    if (sp54 == NULL)
        return NULL;

    func_802DD028(sp80, sp84);
    func_802DD204(sp8C, sp88, &sp7A, &sp78, &sp76);

    switch (sp80) {
        case 1:
            if (sp7A > 250) 
                sp7A -= 250;
            else
                sp7A = 1;

            func_802DD32C(sp8C, sp70, sp7A, sp78, sp76);
            func_802DD548(sp70[0], sp70[1], sp70[2]);
            break;

        case 2:
            if (sp7A > 500) 
                sp7A -= 500;
            else
                sp7A = 1;

            func_802DD32C(sp8C, sp70, sp7A, sp78, sp76);
            func_802DDE28(sp70[0], sp70[1], sp70[2]);
            break;
        case 3:            
            if (sp7A > 250) 
                sp7A -= 250;
            else
                sp7A = 1;

            func_802DD32C(sp8C, sp70, sp7A, sp78, sp76);
            func_802DD978(sp70[0], sp70[1], sp70[2]);
            break;
    }

    func_802DE01C((s16 *) &sp68, (s16 *) &sp60, (s16 *) &sp58, sp78, sp76);

    if (sp80 == 1 || sp80 == 3) {
        gSPDisplayList(sp50++, &tiny_bubble_dl_0B006A50);
        do {} while (0);
    } else if (sp80 == 2) {
        gSPDisplayList(sp50++, &tiny_bubble_dl_0B006CD8);  
    }

    for (sp7C = 0; sp7C < D_803600A4; sp7C += 5) {
        func_802DE424(sp50++, sp7C, (s16 *)&sp68, (s16 *) &sp60, (s16 *)&sp58);

        gSP1Triangle(sp50++, 0, 1, 2, 0);
        gSP1Triangle(sp50++, 3, 4, 5, 0);
        gSP1Triangle(sp50++, 6, 7, 8, 0);
        gSP1Triangle(sp50++, 9, 10, 11, 0);
        gSP1Triangle(sp50++, 12, 13, 14, 0);        
    }

    gSPDisplayList(sp50++, &tiny_bubble_dl_0B006AB0)
    gSPEndDisplayList(sp50++);

    return sp54;
}

void *func_802DECB8(int sp28, Vec3s sp2C, Vec3s sp30, Vec3s sp34) {
    Gfx *sp24;

    if (get_dialog_id() != -1)
        return NULL;

    if (D_80330640 != 0 && sp28 != D_80330640)
        sp28 = 0;

    if (sp28 >= 0xA) {
        sp24 = func_802E1038(sp28, sp2C, sp30, sp34);
        return sp24;
    }

    if (D_80330640 == 0 && func_802DCEE0(sp28) == 0)
        return NULL;

    switch (sp28) {
        case 0:
            func_802DD1AC(D_80360090);
            return NULL;

        case 1:
            sp24 = func_802DE838(1, sp2C, sp34, sp30);
            break;
        
        case 2:
            sp24 = func_802DE838(2, sp2C, sp34, sp30);
            break;

        case 3:
            sp24 = func_802DE838(3, sp2C, sp34, sp30);
            break;

        default:
            return NULL;
    }

    return sp24;
}
