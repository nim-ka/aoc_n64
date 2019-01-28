#include <ultra64.h>

#include "sm64.h"
#include "display.h"
#include "memory.h"
#include "ingame_menu_2.h"
#include "ingame_menu.h"
#include "surface_collision.h"
#include "math_util.h"
#include "behavior_script.h"
#include "audio/interface_2.h"
#include "obj_behaviors.h"
extern struct MemoryPool *D_8033A124;
s16 D_803600B0[10];
Gfx *D_803600C4;
s32 D_803600C8;
s32 D_803600CC;

UNUSED s32 D_80330690 = 0;
UNUSED s32 D_80330694 = 0;
Vtx_t D_80330698[3] = 
{
    {
        {0, 0, 0},
        0,
        {1544, 964},
        {0xFF, 0xFF, 0xFF, 0xFF}
    },
    {
        {0, 0, 0},
        0,
        {522, -568},
        {0xFF, 0xFF, 0xFF, 0xFF}
    },
    {
        {0, 0, 0},
        0,
        {-498, 964},
        {0xFF, 0xFF, 0xFF, 0xFF}
    },
};

extern void *flower_bubbles_textures_ptr_0B002008;
extern void *lava_bubble_ptr_0B006020;
extern void *bubble_ptr_0B006848;
extern void *tiny_bubble_dl_0B006AB0;
extern void *tiny_bubble_dl_0B006D38;
extern void *tiny_bubble_dl_0B006D68;

s32 func_802DEE40(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 sp4 = (D_80360090 + a0)->unk04;
    s32 sp0 = (D_80360090 + a0)->unk0C;

    if (sqr(sp4 - a1) + sqr(sp0 - a2) > sqr(a3)) 
        return 0;
    
    return 1;
}

s32 func_802DEEF0() {
    s32 sp1C = RandomFloat() * 2000.0f - 1000.0f;
    if (sp1C < 0 )
        sp1C -= 1000;
    else
        sp1C += 1000;

    return sp1C;
}

void func_802DEF70(Vec3s sp30) {
    s32 sp2C;
    f32 *sp28;
    s32 sp24 = gGlobalTimer;
    UNUSED s16 sp22, sp20, sp1E;

    sp22 = sp30[0];
    sp20 = sp30[1];
    sp1E = sp30[2];

    for (sp2C = 0; sp2C < D_803600CC; sp2C++) {
        (D_80360090 + sp2C)->unk00 = func_802DEE40(sp2C, sp22, sp1E, 3000);
        if ((D_80360090 + sp2C)->unk00 == 0)  {
            (D_80360090 + sp2C)->unk04 = func_802DEEF0() + sp22;
            (D_80360090 + sp2C)->unk0C = func_802DEEF0() + sp1E;
            (D_80360090 + sp2C)->unk08 = func_803814B8((D_80360090 + sp2C)->unk04, 10000.0f, (D_80360090 + sp2C)->unk0C, &sp28);
            (D_80360090 + sp2C)->unk00 = 1;
            (D_80360090 + sp2C)->unk02 = RandomFloat() * 5.0f;
        } else if ((sp24 & 0x03) == 0) {
            (D_80360090 + sp2C)->unk02 += 1;
            if ((D_80360090 + sp2C)->unk02 > 5)
                (D_80360090 + sp2C)->unk02 = 0;
        }
    }
}

void func_802DF210(s32 sp28, Vec3s sp2C) {
    struct Surface *sp24;
    s16 sp22;
    s16 sp20, sp1E, sp1C;

    sp20 = sp2C[0];
    sp1E = sp2C[1];
    sp1C = sp2C[2];

    (D_80360090 + sp28)->unk04 = RandomFloat() * 6000.0f - 3000.0f + sp20;
    (D_80360090 + sp28)->unk0C = RandomFloat() * 6000.0f - 3000.0f + sp1C;
    
    if ((D_80360090 + sp28)->unk04 > 8000) 
        (D_80360090 + sp28)->unk04 = 16000 - (D_80360090 + sp28)->unk04;
    if ((D_80360090 + sp28)->unk04 < -8000) 
        (D_80360090 + sp28)->unk04 = -16000 - (D_80360090 + sp28)->unk04;

    if ((D_80360090 + sp28)->unk0C > 8000) 
        (D_80360090 + sp28)->unk0C = 16000 - (D_80360090 + sp28)->unk0C;
    if ((D_80360090 + sp28)->unk0C < -8000) 
        (D_80360090 + sp28)->unk0C = -16000 - (D_80360090 + sp28)->unk0C;

    sp22 = find_floor((D_80360090 + sp28)->unk04, sp1E + 500, (D_80360090 + sp28)->unk0C, &sp24);
    if (sp24 == NULL) {
        (D_80360090 + sp28)->unk08 = -10000;
        return;
    }
    
    if (sp24->type == SURFACE_LAVA) {
        (D_80360090 + sp28)->unk08 = sp22;
    }
    else {
        (D_80360090 + sp28)->unk08 = -10000;
    }
}

void func_802DF57C(Vec3s sp28) {
    s32 sp24;
    s32 sp20 = gGlobalTimer;
    s8 sp1F;
    UNUSED s16 sp1C, sp1A, sp18;

    sp1C = sp28[0];
    sp1A = sp28[1];
    sp18 = sp28[2];

    for (sp24 = 0; sp24 < D_803600CC; sp24++) {
        if ((D_80360090 + sp24)->unk00 == 0) {
            func_802DF210(sp24, sp28);
            (D_80360090 + sp24)->unk00 = 1;
        } 
        else if ((sp20 & 0x01) == 0) {
            (D_80360090 + sp24)->unk02 += 1;
            if ((D_80360090 + sp24)->unk02 > 8) {
                (D_80360090 + sp24)->unk00 = 0;
                (D_80360090 + sp24)->unk02 = 0;
            }
        }
    }

    if ((sp1F = (s32)(RandomFloat() * 16.0f)) == 8)
        SetSound(0x300D0081, D_803320E0);
}

void func_802DF74C(s32 *a0, s32 *a1, s32 *a2) {
    s32 sp24 = *a0 - D_803600B0[4];
    s32 sp20 = *a1 - D_803600B0[5];
    s32 sp1C = *a2 - D_803600B0[6];
    f32 sp18 = coss(D_803600B0[8]);
    f32 sp14 = sins(D_803600B0[8]);
    f32 sp10 = coss(-D_803600B0[9]);
    f32 spC = sins(-D_803600B0[9]);

    f32 sp8 = sp24 * sp10 - spC * sp18 * sp20 - sp14 * spC * sp1C;
    f32 sp4 = sp24 * spC  + sp18 * sp10 * sp20 - sp14 * sp10 * sp1C;
    f32 sp0 = sp20 * sp14 + sp18 * sp1C;

    *a0 = D_803600B0[4] + (s32)sp8;
    *a1 = D_803600B0[5] + (s32)sp4;
    *a2 = D_803600B0[6] + (s32)sp0;
}

s32 func_802DF998(s32 a0) {
    s32 UNUSED sp4;

    if ((D_80360090 + a0)->unk1C < D_803600B0[5] - 100)
        return 0;

    if ((D_80360090 + a0)->unk10[1] < 10)
        return 0;

    return 1;
}

void func_802DFA24(void) {
    s32 sp1C;

    for (sp1C = 0; sp1C < D_803600CC; sp1C++) {
        (D_80360090 + sp1C)->unk00 = func_802DF998(sp1C);
        if ((D_80360090 + sp1C)->unk00 == 0) {
            (D_80360090 + sp1C)->unk10[1] = RandomFloat() * 1000.0f;
            (D_80360090 + sp1C)->unk10[0] = RandomFloat() * 65536.0f;
            (D_80360090 + sp1C)->unk04 = D_803600B0[1] + sins((D_80360090 + sp1C)->unk10[0]) * (D_80360090 + sp1C)->unk10[1];
            (D_80360090 + sp1C)->unk0C = D_803600B0[3] + coss((D_80360090 + sp1C)->unk10[0]) * (D_80360090 + sp1C)->unk10[1];
            (D_80360090 + sp1C)->unk1C = D_803600B0[2] + (RandomFloat() * 100.0f - 50.0f);
            (D_80360090 + sp1C)->unk08 = (sp1C + D_80360090)->unk1C;
            (D_80360090 + sp1C)->unk18 = 0;
            (D_80360090 + sp1C)->unk00 = 1;

            func_802DF74C(&(D_80360090 + sp1C)->unk04, &(D_80360090 + sp1C)->unk08, &(D_80360090 + sp1C)->unk0C);
        }
        else {
            (D_80360090 + sp1C)->unk10[1] -= 0x28; 
            (D_80360090 + sp1C)->unk10[0] += (s16) (3000 - (D_80360090 + sp1C)->unk10[1] * 2) + 0x400;
            (D_80360090 + sp1C)->unk04 = D_803600B0[1] + sins((D_80360090 + sp1C)->unk10[0]) * (D_80360090 + sp1C)->unk10[1];
            (D_80360090 + sp1C)->unk0C = D_803600B0[3] + coss((D_80360090 + sp1C)->unk10[0]) * (D_80360090 + sp1C)->unk10[1];
            (D_80360090 + sp1C)->unk1C -= -((s16)(D_80360090 + sp1C)->unk10[1] / 100) + 0x28;
            (D_80360090 + sp1C)->unk08 = (sp1C + D_80360090)->unk1C;

            func_802DF74C(&(D_80360090 + sp1C)->unk04, &(D_80360090 + sp1C)->unk08, &(D_80360090 + sp1C)->unk0C);
        }
    }
}

s32 func_802DFF14(s32 sp20) {
    UNUSED s32 unk;

    if (!func_802DEE40(sp20, D_803600B0[1], D_803600B0[3], 1000) 
        || D_803600B0[2] + 1500 < (D_80360090 + sp20)->unk08) 
        return 0;

    return 1;
}

void func_802DFFA8(void) {
    s32 sp1C;

    for (sp1C = 0; sp1C < D_803600CC; sp1C++) {
        (D_80360090 + sp1C)->unk00 = func_802DFF14(sp1C);
        if ((D_80360090 + sp1C)->unk00 == 0) {
            (D_80360090 + sp1C)->unk10[1] = RandomFloat() * 300.0f;
            (D_80360090 + sp1C)->unk10[0] = RandomU16();
            (D_80360090 + sp1C)->unk04 = D_803600B0[1] + sins((D_80360090 + sp1C)->unk10[0]) * (D_80360090 + sp1C)->unk10[1];
            (D_80360090 + sp1C)->unk0C = D_803600B0[3] + coss((D_80360090 + sp1C)->unk10[0]) * (D_80360090 + sp1C)->unk10[1];
            (D_80360090 + sp1C)->unk08 = D_803600B0[2] + (RandomFloat() * 400.0f - 200.0f);
        }
        else {
            (D_80360090 + sp1C)->unk10[1] += 10; 
            (D_80360090 + sp1C)->unk04 += sins((D_80360090 + sp1C)->unk10[0]) * 10.0f;
            (D_80360090 + sp1C)->unk0C += coss((D_80360090 + sp1C)->unk10[0]) * 10.0f;
            (D_80360090 + sp1C)->unk08 -= ((D_80360090 + sp1C)->unk10[1] / 30) - 50;
        }
    }
}

s32 func_802E0328(s32 sp20) {
    s32 sp1C;

    switch (sp20) {
        case 0: 
            return 0;

        case 11:
            D_803600C8 = 30;
            D_803600CC = 30;
            break;

        case 12:
            D_803600C8 = 15;
            D_803600CC = 15;
            break;

        case 13:
            D_803600C8 = 60;
            break;

        case 14:
            D_803600C8 = 60;
            break;
    }

    D_80360090 = (struct struct802DCEE0 *)mem_pool_alloc(D_8033A124, D_803600C8 * sizeof(struct struct802DCEE0));
    if (!D_80360090)
        return 0;

    bzero(D_80360090, D_803600C8 * sizeof(struct struct802DCEE0));
    bzero(D_803600B0, sizeof(D_803600B0));

    if (sp20 == 12) {
        if (0) { }
        
        for (sp1C = 0; sp1C < D_803600C8; sp1C++) {
            (D_80360090 + sp1C)->unk02 = RandomFloat() * 7.0f; 
        }


        if (0) { }
            }

    D_80330640 = sp20;
    return 1;
}

void func_802E0504(s32 sp28, Vec3s sp2C, Vec3s sp30, Vec3s sp34, Vec3s sp38) {
    switch(sp28) {
        case 11:
            func_802DEF70(sp2C);
            sp30[0] = 50;
            sp30[1] = 0;
            sp30[2] = 0;
            sp34[0] = 0;
            sp34[1] = 75;
            sp34[2] = 0;
            sp38[0] = -50;
            sp38[1] = 0;
            sp38[2] = 0;
            break;

        case 12:
            func_802DF57C(sp2C);
            sp30[0] = 100;
            sp30[1] = 0;
            sp30[2] = 0;
            sp34[0] = 0;
            sp34[1] = 150;
            sp34[2] = 0;
            sp38[0] = -100;
            sp38[1] = 0;
            sp38[2] = 0;
            break;

        case 13:
            func_802DFA24();
            sp30[0] = 40;
            sp30[1] = 0;
            sp30[2] = 0;
            sp34[0] = 0;
            sp34[1] = 60;
            sp34[2] = 0;
            sp38[0] = -40;
            sp38[1] = 0;
            sp38[2] = 0;
            break;

        case 14:
            func_802DFFA8();
            sp30[0] = 40;
            sp30[1] = 0;
            sp30[2] = 0;
            sp34[0] = 0;
            sp34[1] = 60;
            sp34[2] = 0;
            sp38[0] = -40;
            sp38[1] = 0;
            sp38[2] = 0;
            break;
    }
}

void func_802E0708(Gfx *sp28, s32 sp2C, Vec3s sp30, Vec3s sp34, Vec3s sp38, Vtx *sp3C) {
    s32 sp24 = 0;
    Vtx *sp20 = (Vtx *)alloc_display_list(15 * sizeof(Vtx));

    if (sp20 == NULL)
        return;

    for (sp24 = 0; sp24 < 15; sp24 += 3) {
        sp20[sp24] = sp3C[0];
        sp20[sp24].v.ob[0] = sp30[0] + (D_80360090 + (sp2C + sp24 / 3))->unk04;
        sp20[sp24].v.ob[1] = sp30[1] + (D_80360090 + (sp2C + sp24 / 3))->unk08;
        sp20[sp24].v.ob[2] = sp30[2] + (D_80360090 + (sp2C + sp24 / 3))->unk0C;

        sp20[sp24 + 1] = sp3C[1];
        sp20[sp24 + 1].v.ob[0] = sp34[0] + (D_80360090 + (sp2C + sp24 / 3))->unk04;
        sp20[sp24 + 1].v.ob[1] = sp34[1] + (D_80360090 + (sp2C + sp24 / 3))->unk08;
        sp20[sp24 + 1].v.ob[2] = sp34[2] + (D_80360090 + (sp2C + sp24 / 3))->unk0C;
        
        sp20[sp24 + 2] = sp3C[2];
        sp20[sp24 + 2].v.ob[0] = sp38[0] + (D_80360090 + (sp2C + sp24 / 3))->unk04;
        sp20[sp24 + 2].v.ob[1] = sp38[1] + (D_80360090 + (sp2C + sp24 / 3))->unk08;
        sp20[sp24 + 2].v.ob[2] = sp38[2] + (D_80360090 + (sp2C + sp24 / 3))->unk0C;
    }

    gSPVertex(sp28, VIRTUAL_TO_PHYSICAL(sp20), 15, 0);
}

void func_802E0B10(s32 sp38, s16 sp3E) {
    void **sp34;
    s16 sp32 = (D_80360090 + sp3E)->unk02;

    switch(sp38) {
        case 11:
            sp34 = (void **)segmented_to_virtual(&flower_bubbles_textures_ptr_0B002008);
            sp32 = (D_80360090 + sp3E)->unk02;
            break;

        case 12:
            sp34 = (void **)segmented_to_virtual(&lava_bubble_ptr_0B006020);
            sp32 = (D_80360090 + sp3E)->unk02;
            break;

        case 13:
        case 14:
            sp34 = (void **)segmented_to_virtual(&bubble_ptr_0B006848);
            sp32 = 0;
            break;
    }

    gDPSetTextureImage(D_803600C4++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, *(sp34 + sp32));
    gSPDisplayList(D_803600C4++, &tiny_bubble_dl_0B006D68);
}

Gfx *func_802E0CA8(s32 sp68, UNUSED Vec3s sp6C, Vec3s sp70, Vec3s sp74) {
    s32 sp64;
    s16 sp62, sp60, sp5E;
    UNUSED s16 sp5C;
    UNUSED s16 sp5A;
    s16 sp58;
    UNUSED s32 sp54;
    UNUSED s16 sp52;
    s16 sp50;
    UNUSED s32 sp4C;
    UNUSED s16 sp4A;
    s16 sp48;
    Gfx *sp44;
    
    sp44 = (Gfx *)alloc_display_list(((D_803600CC / 5) * 10 + D_803600CC + 3) * sizeof(Gfx));
    if (sp44 == NULL)
        return NULL;

    D_803600C4 = sp44;

    func_802DD204(sp74, sp70, &sp62, &sp60, &sp5E);
    func_802E0504(sp68, sp74, &sp58, &sp50, &sp48);
    func_802DE01C(&sp58, &sp50, &sp48, sp60, sp5E);

    gSPDisplayList(D_803600C4++, &tiny_bubble_dl_0B006D38);

    for (sp64 = 0; sp64 < D_803600CC; sp64 += 5) {
        gDPPipeSync(D_803600C4++);
        func_802E0B10(sp68, sp64);
        func_802E0708(D_803600C4++, sp64, &sp58, &sp50, &sp48, (Vtx *)D_80330698);
        gSP1Triangle(D_803600C4++, 0, 1, 2, 0);
        gSP1Triangle(D_803600C4++, 3, 4, 5, 0);
        gSP1Triangle(D_803600C4++, 6, 7, 8, 0);
        gSP1Triangle(D_803600C4++, 9, 10, 11, 0);
        gSP1Triangle(D_803600C4++, 12, 13, 14, 0);
    }

    gSPDisplayList(D_803600C4++, &tiny_bubble_dl_0B006AB0);
    gSPEndDisplayList(D_803600C4++);

    return sp44;
}

void func_802E0FC8(s32 a0) {
    switch (a0) {
        case 13:
            D_803600CC = D_803600B0[7];
            break;
        case 14:
            D_803600CC = D_803600B0[7];
            break;
    }
}

Gfx *func_802E1038(s32 sp28, Vec3s sp2C, Vec3s sp30, Vec3s sp34) {
    Gfx *sp24;

    if (D_80330640 == 0 && !func_802E0328(sp28))
        return NULL;

    func_802E0FC8(sp28);

    if (D_803600CC == 0)
        return NULL;

    switch (sp28) {
        case 11:
            sp24 = func_802E0CA8(11, sp2C, sp34, sp30);
            break;

        case 12:
            sp24 = func_802E0CA8(12, sp2C, sp34, sp30);
            break;

        case 13:
            sp24 = func_802E0CA8(13, sp2C, sp34, sp30);
            break;

        case 14:
            sp24 = func_802E0CA8(14, sp2C, sp34, sp30);
            break;

        default: 
            return NULL;
    }

    return sp24;
}
