#include <ultra64.h>

#include "sm64.h"
#include "level_functions.h"

/*static*/ extern struct Object D_8035FB18;

s16 func_802E1190(s16 a0)
{
    u16 sp06 = ((u16) (a0 & 0xFF));
    sp06 <<= 8;

    if (sp06 == 0x3F00)
        sp06 = 0x4000;
    
    if (sp06 == 0x7F00)
        sp06 = 0x8000;
    
    if (sp06 == 0xBF00)
        sp06 = 0xC000;
    
    if (sp06 == 0xFF00)
        sp06 = 0x0000;
    
    return (s16) sp06;
}

/* a1 seems to be a segment address */
void func_802E1224(u32 a0, void* a1, s16 a2, s16 a3, s16 a4, s16 a5, s16 a6)
{
    if (a1 != NULL)
    {
        struct Object *sp3C = func_8029E230(&D_8035FB18, 0, a0, a1, a2, a3, a4, 0, func_802E1190(a5), 0);
        sp3C->unk188 = ((u32) a6) << 16;        
    }
}

/* a1 seems to be a segment address */
void func_802E12CC(u32 a0, void* a1, s16 a2, s16 a3, s16 a4, s16 a5, s16 a6)
{
    if (a1 != NULL)
    {
        struct Object *sp3C = func_8029E230(&D_8035FB18, 0, a0, a1, a2, a3, a4, 0, func_802E1190(a5), 0);
        sp3C->unk188 = ((u32) a6) << 24;        
    }
}

/* a1 seems to be a segment address */
void func_802E1374(u32 a0, void* a1, s16 a2, s16 a3, s16 a4, s16 a5, s16 a6, s16 a7)
{
    struct Object *sp34 = func_8029E230(&D_8035FB18, 0, a0, a1, a2, a3, a4, 0, 0, 0);


    sp34->unk108 = (f32) a5;
    // TODO: Fix hack
    *(f32 *) &sp34->unk10C = (f32) a6;
    *(f32 *) &sp34->unk110 = (f32) a7;
}

/* a0 seems to be a segment address */
void Unknown802E142C(void* a0, s16 a1[])
{    
    struct Object *sp3C;
    s16 sp3A;
        
    sp3A = &D_1300091C == a0 ? 116 : 0;
    
    sp3C = func_8029E230(&D_8035FB18, 0, sp3A, a0, a1[1], a1[2], a1[3], 0, func_802E1190(a1[0]), 0);

    sp3C->unk1A8 = a1[4];
    sp3C->unk188 = (a1[4] & 0xFF) >> 16;    // good C
}

/*static*/ extern s8 D_8035FB30;
/*static*/ extern s8 D_8035FB31;

struct Struct803306D0
{
    void* segAddr;
    s16   unk4;
    s16   unk6;
};

/*static*/ extern struct Struct803306D0 D_803306D0[];

void func_802E1504(s16 a0, s16* a1)
{
    UNUSED u32 pad5C;
    s32 offset;
    s16 sp4C[5];
    struct Object * sp48;
    struct Struct803306D0 sp40;

    D_8035FB30 = (s8) a0;
    D_8035FB31 = (s8) a0;

    while (TRUE)
    {
        if (*a1 == -1)
            break;

        offset = (*a1 & 0x1FF) - 0x1F;

        if (offset < 0)
            break;

        sp4C[0] = ((*a1++ >> 9) & 0x7F) << 1;
        sp4C[1] = *a1++;
        sp4C[2] = *a1++;
        sp4C[3] = *a1++;
        sp4C[4] = *a1++;

        sp40.unk6    = D_803306D0[offset].unk4; 
        sp40.segAddr = D_803306D0[offset].segAddr;
        sp40.unk4    = D_803306D0[offset].unk6;

        if (sp40.unk4 != 0)
            sp4C[4] = (sp4C[4] & 0xFF00) + (sp40.unk4 & 0x00FF); 

        if (((sp4C[4] >> 8) & 0x00FF) != 0xFF)
        {
            sp48 = func_8029E230(&D_8035FB18, 0, sp40.unk6, sp40.segAddr, sp4C[1], sp4C[2], sp4C[3], 0, func_802E1190(sp4C[0]), 0);

            sp48->unk1A8   = sp4C[4];
            sp48->unk188   = ((sp4C[4] & 0x00FF) << 16) + (sp4C[4] & 0xFF00);
            sp48->behParam = sp4C[4] & 0x00FF;
            sp48->unk1F6   = 2;
            sp48->unk25C   = (u32) a1 - 2;
            sp48->unk68    = sp48;
        }
    }
}


