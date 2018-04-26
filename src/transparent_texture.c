#include <ultra64.h>

#include "sm64.h"
#include "types.h"
#include "variables.h"
#include "save_file.h"

void func_802D1730(void *a0, s32 a1, s16 a2, s16 a3, s16 sp12, s16 sp16, s16 sp1A, u8 sp1F, u8 sp23, u8 sp27, u8 sp2B)
{
    ((u16 *)((u32)a0 + (a1 << 0x04)))[0] = a2;
    ((u16 *)((u32)a0 + (a1 << 0x04)))[1] = a3;
    ((u16 *)((u32)a0 + (a1 << 0x04)))[2] = sp12;
    ((u16 *)((u32)a0 + (a1 << 0x04)))[3] = 0;
    ((u16 *)((u32)a0 + (a1 << 0x04)))[4] = sp16;
    ((u16 *)((u32)a0 + (a1 << 0x04)))[5] = sp1A;
    ((u8 *)((u32)a0 + (a1 << 0x04)))[12] = sp1F;
    ((u8 *)((u32)a0 + (a1 << 0x04)))[13] = sp23;
    ((u8 *)((u32)a0 + (a1 << 0x04)))[14] = sp27;
    ((u8 *)((u32)a0 + (a1 << 0x04)))[15] = sp2B;
}

s32 func_802D17E4(float f12)
{
    //! double literals instead of float literals
    if (f12 >= 0.0)
        return (s16)(f12 + 0.5);
    else
        return (s16)(f12 - 0.5);
}

struct StructGeo802D2360 *Geo18_802D2360(s32 sp30, short *sp34, UNUSED s32 sp38)
{
    s32 flags;
    short *sp28;
    Gfx *dlist = NULL;
    void *sp20 = NULL;

    if (sp30 == 1)
    {
        flags = save_file_get_flags();
        if (D_80339EF4 >= 0xa && (flags & FLAG_HAVE_WING_CAP) == 0)
        {
            sp20 = alloc_display_list(0x10);
            if (sp20 == NULL)
                return NULL;
            else
                dlist = sp20;

            sp28 = sp34;
            sp28[1] = (sp28[1] & 0xFF) | 0x500;
            
            gSPDisplayList(dlist++, D_0702A880);
            gSPEndDisplayList(dlist);
        }
    }

    return sp20;
}

struct StructGeo802D2360 *Geo18_802D2470(s32 a0, UNUSED void *sp4, UNUSED s32 sp8) {

    if (a0 != 1)
    {
        D_80330398 = 0;
        D_80330394 = D_8032CFA8 - 1;
        D_80330390 = D_8032CFA8;
        D_8035FF80 = 0;
    }
    else
    {
        D_80330394 = D_80330390;
        D_80330390 = D_8032CFA8;
        if (D_80330394 != D_80330390) D_80330398 += 0x400;
    }

    return NULL;
}

void *Geo18_802D2520(s32 sp80, short *sp84, UNUSED s32 sp88)
{
    s16 sp7E, sp7C, sp7A, sp78, sp76, sp74, sp72, sp70;
    void *sp6C;
    short *sp68 = sp84;

    Gfx *sp64 = (Gfx *)segmented_to_virtual(&D_07019248);
    Gfx *sp60 = NULL, *sp5C = NULL;
    struct Object *sp58;
    

    if (sp80 == 1)
    {
        sp6C = alloc_display_list(0x150);
        sp60 = alloc_display_list(0x38);

        sp5C = sp60;

        if (sp6C == NULL || sp60 == NULL) return 0;

        sp68[1] = (sp68[1] & 0xFF) | 0x100;

        sp7E = 0;
        do
        {
            sp7C = sp7E / 3;
            sp7A = sp7E % 3;

            sp78 = ((s16 *)(u32) sp64 + (sp7E << 2))[0];
            sp76 = func_802D17E4(sins(D_80330398 + (sp7C << 0x0C) + (sp7A << 0x0E)) * 20.0);
            
            sp74 = ((s16 *)(u32) sp64 + (sp7E << 2))[1];
            sp72 = ((s16 *)(u32) sp64 + (sp7E << 2))[2];
            sp70 = ((s16 *)(u32) sp64 + (sp7E << 2))[3];

            func_802D1730(sp6C, sp7E, sp78, sp76, sp74, sp72, sp70, 0, 0x7F, 0, 0xFF);
        } while (++sp7E <= 0x14);

        gSPDisplayList(sp5C++, D_070192F0);

        {
            Gfx *sp50 = sp5C++;
            sp50->words.w0 = 0x04B000C0;
            sp50->words.w1 = (u32)sp6C;
        }

        gSPDisplayList(sp5C++, D_07019360);

        {
            Gfx *sp48 = sp5C++;
            sp48->words.w0 = 0x04B000C0;
            sp48->words.w1 = (u32)(s32 *)((u32)sp6C + 0x90);
        }

        gSPDisplayList(sp5C++, D_07019360);
        gSPDisplayList(sp5C++, D_070193C8);
        gSPEndDisplayList(sp5C);

        sp58 = D_8032CFA0;
        if (gMarioObject->platform == sp58)
        {
            D_8035FF80 = 2;
        }
        else
        {
            if (sp58->forwardVel != 0.0)
                D_8035FF80 = 1;
            else
                D_8035FF80 = 0;
        }
    }

    return sp60; 
}

Gfx *Geo18_802D28CC(s32 sp30, short *sp34, UNUSED s32 sp38)
{
    short *sp2C = sp34;
    Gfx *sp28 = NULL;
    Gfx *sp24 = NULL;

    if (sp30 == 1)
    {
        sp28 = alloc_display_list(0x18);
        sp24 = sp28;

        sp2C[1] = (sp2C[1] & 0xFF) | 0x100;
        gSPDisplayList(sp24++, D_02014660);
        gSPDisplayList(sp24++, D_07026400);
        gSPEndDisplayList(sp24);
    }

    return sp28;  
}
