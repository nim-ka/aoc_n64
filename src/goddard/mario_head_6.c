#include <ultra64.h>

#include "sm64.h"
#include "mario_head_6.h"
#include "profiler_utils.h"
#include "../libultra.h"

extern u32 D_801BB010;
extern f32 D_801A8694;
extern const char D_801B8CA0[];
extern const char D_801B8CA4[];
extern const char D_801B8CD4[];
extern const char D_801B8CE8[];
extern const char D_801B8CFC[];
extern const char D_801B8D10[];

struct StructTest {
    /*0x00*/  u8 unk0[72];
};

struct StructTest2 {
    /*0x00*/  u8 unk0[64];
};

struct StructTest3 {
    /*0x00*/  u8 unk0[16];
};

struct StructTest4 {
    /*0x00*/  u8 unk0[8];
};

struct Struct801A86FC {
    /*0x00*/ s32 unk0;
    /*0x04*/ s32 unk4;
    /*0x08*/ struct StructTest3 *unk8;
    /*0x0C*/ s32 unkC;
    /*0x10*/ s32 unk10;
    /*0x14*/ struct StructTest2 *unk14;
    /*0x18*/ s32 unk18;
    /*0x1C*/ s32 unk1C;  
    /*0x20*/ struct StructTest *unk20; 
    /*0x24*/ s32 unk24;
    /*0x28*/ s32 unk28;
    /*0x2C*/ struct StructTest4 *unk2C;
    /*0x30*/ u8 pad30[0x10];
    /*0x40*/ u32 unk40;
};

extern struct Struct801A86FC *D_801A86FC;

u32 func_8019AF20(void)
{
    return D_801BB010;
}

s32 func_8019AF40(void)
{
    return osGetTime();
}

f32 func_8019AF70(void)
{
    return D_801A8694;
}

void dumpDispList(void)
{
    printf(D_801B8CA0, D_801A86FC->unk40);
    printf(D_801B8CA4, D_801A86FC->unk0, D_801A86FC->unk4, D_801A86FC->unkC, D_801A86FC->unk10, D_801A86FC->unk18, D_801A86FC->unk1C, D_801A86FC->unk24, D_801A86FC->unk28);
}

struct StructTest4* nextDisplayList()
{
    if(D_801A86FC->unk24 >= D_801A86FC->unk28)
    {
        dumpDispList();
        fatal_printf(D_801B8CD4);
    }

    return &D_801A86FC->unk2C[D_801A86FC->unk24++];
}

struct StructTest* nextLightList()
{
    if(D_801A86FC->unk18 >= D_801A86FC->unk1C)
    {
        dumpDispList();
        fatal_printf(D_801B8CE8);
    }

    return &D_801A86FC->unk20[D_801A86FC->unk18++];
}

struct StructTest2* nextMtxList()
{
    if(D_801A86FC->unkC >= D_801A86FC->unk10)
    {
        dumpDispList();
        fatal_printf(D_801B8CFC);
    }

    return &D_801A86FC->unk14[D_801A86FC->unkC++];
}

struct StructTest3* nextVtxList()
{
    if (D_801A86FC->unk0 >= D_801A86FC->unk4)
    {
        dumpDispList();
        fatal_printf(D_801B8D10);
    }

    return &D_801A86FC->unk8[D_801A86FC->unk0++];
}

