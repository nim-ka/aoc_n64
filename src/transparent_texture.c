#include <ultra64.h>

#include "sm64.h"
#include "types.h"
#include "variables.h"
#include "save_file.h"

void func_802D1730(void *a0, s32 a1, s16 a2, s16 a3, s16 sp12, s16 sp16, s16 sp1A, u8 sp1F, u8 sp23, u8 sp27, u8 sp2B) {
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

s32 func_802D17E4(float f12) {
    if ((double) f12 >= 0.0f) {
        return (s16)((double)(f12 + 0.5));
    }
    else {
        return (s16)((double)f12 - 0.5);
    }
}

struct StructGeo802D2360 *Geo18_802D2360(s32 sp30, short *sp34, UNUSED s32 sp38) {
    s32 sp2C;
    short *sp28;
    struct StructGeo802D2360 *sp24 = NULL;
    struct StructGeo802D2360 *sp20 = NULL;
    struct StructGeo802D2360 *sp1C, *sp18;

    if (sp30 == 1) {
        sp2C = save_file_get_flags();
        if (D_80339EF4 >= 0xa && (sp2C & 0x02) == 0) {
            sp20 = (struct StructGeo802D2360 *)func_8027897C(0x10);
            if (sp20 == NULL) {
                return NULL;
            }
            else {
                sp24 = sp20;
            }

            sp28 = sp34;
            sp28[1] = (sp28[1] & 0xFF) | 0x500;
            sp1C = sp24++;
            sp1C->unk0 = 0x6000000;
            sp1C->unk4 = &D_0702A880;

            sp18 = sp24; 

            sp18->unk0 = 0xb8000000;
            sp18->unk4 = NULL;
    
        }
    }

    return sp20;
}

struct StructGeo802D2360 *Geo18_802D2470(s32 a0, UNUSED void *sp4, UNUSED s32 sp8) {

    if (a0 != 1) {
        D_80330398 = 0;
        D_80330394 = D_8032CFA8 - 1;
        D_80330390 = D_8032CFA8;
        D_8035FF80 = 0;
    }
    else {
        D_80330394 = D_80330390;
        D_80330390 = D_8032CFA8;
        if (D_80330394 != D_80330390) D_80330398 += 0x400;
    }

    return NULL;
}

struct StructGeo802D2360 *Geo18_802D2520(s32 sp80, short *sp84, UNUSED s32 sp88) {
    s16 sp7E, sp7C, sp7A, sp78, sp76, sp74, sp72, sp70;
    void *sp6C;
    short *sp68 = sp84;

    struct StructGeo802D2360 *sp64 = (struct StructGeo802D2360 *)SegmentedToVirtual((u32)&D_07019248);
    struct StructGeo802D2360 *sp60 = NULL, *sp5C = NULL;
    struct Object *sp58;
    struct StructGeo802D2360 *sp54, *sp50, *sp4C, *sp48, *sp44, *sp40, *sp3C;
    

    if (sp80 == 1) {
        sp6C = (struct StructGeo802D2360 *)func_8027897C(0x150);
        sp60 = (struct StructGeo802D2360 *)func_8027897C(0x38);

        sp5C = sp60;

        if (sp6C == NULL || sp60 == NULL) return 0;

        sp68[1] = (sp68[1] & 0xFF) | 0x100;

        sp7E = 0;
        do {
            sp7C = sp7E / 3;
            sp7A = sp7E % 3;

            sp78 = ((s16 *)(u32) sp64 + (sp7E << 2))[0];
            sp76 = func_802D17E4(sins(D_80330398 + (sp7C << 0x0C) + (sp7A << 0x0E)) * 20.0);
            
            sp74 = ((s16 *)(u32) sp64 + (sp7E << 2))[1];
            sp72 = ((s16 *)(u32) sp64 + (sp7E << 2))[2];
            sp70 = ((s16 *)(u32) sp64 + (sp7E << 2))[3];

            func_802D1730(sp6C, sp7E, sp78, sp76, sp74, sp72, sp70, 0, 0x7F, 0, 0xFF);
        }
        while (++sp7E <= 0x14);

        sp54 = sp5C++;
        sp54->unk0 = 0x6000000;
        sp54->unk4 = &D_070192F0;

        sp50 = sp5C++;
        sp50->unk0 = 0x04B000C0;
        sp50->unk4 = sp6C;

        sp4C = sp5C++;
        sp4C->unk0 = 0x6000000;
        sp4C->unk4 = &D_07019360;

        sp48 = sp5C++;
        sp48->unk0 = 0x04B000C0;
        sp48->unk4 = (s32 *)((u32)sp6C + 0x90);

        sp44 = sp5C++;
        sp44->unk0 = 0x6000000;
        sp44->unk4 = &D_07019360;

        sp40 = sp5C++;
        sp40->unk0 = 0x6000000;
        sp40->unk4 = &D_070193C8;

        sp3C = sp5C;
        sp3C->unk0 = 0xb8000000;
        sp3C->unk4 = 0;

        sp58 = D_8032CFA0;
        if (gMarioObject->platform == sp58)
        {
            D_8035FF80 = 2;
        }
        else {
            if (sp58->unkB8 != 0.0)
                D_8035FF80 = 1;
            else
                D_8035FF80 = 0;
        }
    }

    return sp60; 
}

struct StructGeo802D2360 *Geo18_802D28CC(s32 sp30, short *sp34, UNUSED s32 sp38) {
    short *sp2C = sp34;
    struct StructGeo802D2360 *sp28 = NULL;
    struct StructGeo802D2360 *sp24 = NULL;
    struct StructGeo802D2360 *sp20, *sp1C, *sp18;

    if (sp30 == 1) {
        sp28 = (struct StructGeo802D2360 *) func_8027897C(0x18);
        sp24 = sp28;

        sp2C[1] = (sp2C[1] & 0xFF) | 0x100;
        sp20 = sp24++;
        sp20->unk0 = 0x6000000;
        sp20->unk4 = &D_02014660;

        sp1C = sp24++;
        sp1C->unk0 = 0x6000000;
        sp1C->unk4 = &D_07026400;

        sp18 = sp24;
        sp18->unk0 = 0xb8000000;
        sp18->unk4 = NULL;
    }

    return sp28;  
}
