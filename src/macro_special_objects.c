#include <ultra64.h>

#include "sm64.h"
#include "object_helpers.h"
#include "macro_special_objects.h"
#include "object_list_processor.h"

#include "behavior_data.h"

#include "macro_presets.h"

#include "special_presets.h"

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

void func_802E1224(u32 a0, u32 (*a1)[], s16 a2, s16 a3, s16 a4, s16 a5, s16 a6)
{
    if (a1 != NULL)
    {
        struct Object *sp3C = func_8029E230(&D_8035FB18, 0, a0, a1, a2, a3, a4, 0, func_802E1190(a5), 0);
        sp3C->oBehParams = ((u32) a6) << 16;
    }
}

void func_802E12CC(u32 a0, u8 (*a1)[], s16 a2, s16 a3, s16 a4, s16 a5, s16 a6)
{
    if (a1 != NULL)
    {
        struct Object *sp3C = func_8029E230(&D_8035FB18, 0, a0, a1, a2, a3, a4, 0, func_802E1190(a5), 0);
        sp3C->oBehParams = ((u32) a6) << 24;
    }
}

void func_802E1374(u32 a0, u8 (*a1)[], s16 a2, s16 a3, s16 a4, s16 a5, s16 a6, s16 a7)
{
    struct Object *sp34 = func_8029E230(&D_8035FB18, 0, a0, a1, a2, a3, a4, 0, 0, 0);


    sp34->oUnknownUnk108_F32 = (f32) a5;
    sp34->oUnknownUnk10C_F32 = (f32) a6;
    sp34->oUnknownUnk110_F32 = (f32) a7;
}

void Unknown802E142C(u32 (*a0)[], s16 a1[])
{    
    struct Object *sp3C;
    s16 sp3A;
        
    sp3A = &beh_yellow_coin == a0 ? 116 : 0;
    
    sp3C = func_8029E230(&D_8035FB18, 0, sp3A, a0, a1[1], a1[2], a1[3], 0, func_802E1190(a1[0]), 0);

    sp3C->oUnk1A8 = a1[4];
    sp3C->oBehParams = (a1[4] & 0xFF) >> 16;
}

struct LoadedPreset {
    /*0x00*/ u32 *beh;
    /*0x04*/ s16 param; // huh? why does the below function swap these.. just use the struct..
    /*0x06*/ s16 model;
};

void func_802E1504(s16 a0, s16* a1)
{
    UNUSED u32 pad5C;
    s32 offset;
    s16 sp4C[5];
    struct Object * sp48;
    struct LoadedPreset preset;

    D_8035FB18.header.gfx.unk18 = a0;
    D_8035FB18.header.gfx.unk19 = a0;

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

        preset.model = MacroObjectPresets[offset].model; 
        preset.beh  = MacroObjectPresets[offset].beh;
        preset.param = MacroObjectPresets[offset].param;

        if (preset.param != 0)
            sp4C[4] = (sp4C[4] & 0xFF00) + (preset.param & 0x00FF); 

        if (((sp4C[4] >> 8) & 0x00FF) != 0xFF)
        {
            sp48 = func_8029E230(&D_8035FB18, 0, preset.model, preset.beh, sp4C[1], sp4C[2], sp4C[3], 0, func_802E1190(sp4C[0]), 0);

            sp48->oUnk1A8   = sp4C[4];
            sp48->oBehParams   = ((sp4C[4] & 0x00FF) << 16) + (sp4C[4] & 0xFF00);
            sp48->oBehParams2ndByte = sp4C[4] & 0x00FF;
            sp48->unk1F6   = 2;
            sp48->unk25C   = a1 - 1;
            sp48->parentObj    = sp48;
        }
    }
}

void func_802E1780(s16 a0, s16* a1)
{
    UNUSED u8 pad[8];
    s16 sp3E;
    s16 sp3C;
    s16 sp3A;
    s16 sp38;
    s16 sp36;
    UNUSED u8 pad2[10];

    D_8035FB18.header.gfx.unk18 = a0;
    D_8035FB18.header.gfx.unk19 = a0;

    while (TRUE)
    {
        sp38 = *a1++;

        if (sp38 < 0)
            break;
        
        sp3E = *a1++;
        sp3C = *a1++;
        sp3A = *a1++;
        sp36 = *a1++;

        switch (sp38)
        {
            case 0x00:
                func_802E1224(0, &beh_boo_boss_spawned_bridge, sp3E, sp3C, sp3A, sp36, 0);
                break;
            case 0x01:
                func_802E1224(54, &beh_bbh_tilt_floor_platforms, sp3E, sp3C, sp3A, sp36, 0);
                break;
            case 0x02:
                func_802E1224(55, &beh_bbh_tumbling_platform_group, sp3E, sp3C, sp3A, sp36, 0);
                break;
            case 0x03:
                func_802E1224(57, &beh_tumbling_bookshelf, sp3E, sp3C, sp3A, sp36, 0);
                break;
            case 0x04:
                func_802E1224(58, &beh_mesh_elevator, sp3E, sp3C, sp3A, sp36, 0);
                break;
            case 0x14:
                func_802E1224(116, &beh_yellow_coin, sp3E, sp3C, sp3A, sp36, 0);
                break;
            case 0x15:
                func_802E1224(116, &beh_yellow_coin, sp3E, sp3C, sp3A, sp36, 0);
                break;
            default:
                break;
        }
    }   
}

void func_802E19DC(s16 a0, s16** a1)
{
    s32 sp4C;
    int i;          //sp48
    u32 offset;     //sp44
    s16 sp42;
    s16 sp40;
    s16 sp3E;
    s16 sp34[5];
    u8  sp33;
    u8  sp32;
    s8  sp31;
    u8  sp30;
    void* sp2C;

    sp4C = **a1;
    (*a1)++;

    D_8035FB18.header.gfx.unk18 = a0;
    D_8035FB18.header.gfx.unk19 = a0;

    for (i = 0; i < sp4C; i++)
    {
        sp31 = (s8) **a1;
        (*a1)++;
        sp42 = **a1;
        (*a1)++;
        sp40 = **a1;
        (*a1)++;
        sp3E = **a1;
        (*a1)++;

        offset = 0;
        while (TRUE)
        {
            if (SpecialObjectPresets[offset].preset_id == (u8) sp31)
                break;

            if (SpecialObjectPresets[offset].preset_id == 0xFF) { }

            offset++;
        }

        sp33 = SpecialObjectPresets[offset].model;
        sp2C = SpecialObjectPresets[offset].beh;
        sp32 = SpecialObjectPresets[offset].param1;
        sp30 = SpecialObjectPresets[offset].param2;

        switch (sp32)
        {
            case 0:
                func_802E1224(sp33, sp2C, sp42, sp40, sp3E, 0, 0);
                break;
            case 1:
                sp34[0] = **a1;
                (*a1)++;
                func_802E1224(sp33, sp2C, sp42, sp40, sp3E, sp34[0], 0);
                break;
            case 2:
                sp34[0] = **a1;
                (*a1)++;
                sp34[1] = **a1;
                (*a1)++;
                func_802E1224(sp33, sp2C, sp42, sp40, sp3E, sp34[0], sp34[1]);
                break;
            case 3:
                sp34[0] = **a1;
                (*a1)++;
                sp34[1] = **a1;
                (*a1)++;
                sp34[2] = **a1;
                (*a1)++;
                func_802E1374(sp33, sp2C, sp42, sp40, sp3E, sp34[0], sp34[1], sp34[2]);
                break;
            case 4:
                sp34[0] = **a1;
                (*a1)++;
                func_802E12CC(sp33, sp2C, sp42, sp40, sp3E, sp34[0], sp30);
                break;
            default:
                break;
        }

    }
}
