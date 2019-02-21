#include <ultra64.h>
#include "interface_2.h"
#include "something.h"

void func_80313920(s32 arg0, u32 arg1)
{
    struct struct_3920_sp1c *sp1c; //a2
    s32 a1;
    s32 v1;
    s32 v0;
    s32 v1_2;
    s32 a0;
    if (D_802212A2 != 1)
    {
        if (D_802211B0.unk2 == 0)
        {
            sp1c = &D_802211B0.unk2C[D_802211B0.unk3][arg1];
            osInvalDCache(sp1c->unk4, 640);
            for (a1 = 0, v1 = 0; v1 < sp1c->unk10 / 2; a1 += D_802212A2, v1++)
            {
                D_802211B0.unk14.unk00[v1 + sp1c->unkC] = sp1c->unk4[a1];
                D_802211B0.unk14.unk04[v1 + sp1c->unkC] = sp1c->unk8[a1];
            }
            for (v1 = 0; v1 < sp1c->unk12 / 2; a1 += D_802212A2, v1++)
            {
                D_802211B0.unk14.unk00[v1] = sp1c->unk4[a1];
                D_802211B0.unk14.unk04[v1] = sp1c->unk8[a1];
            }
        }
    }
    sp1c = &D_802211B0.unk2C[D_802211B0.unk3][arg1];

    v1_2 = v0 = arg0 / D_802212A2;
    if (((v0 + D_802211B0.unk8) - D_802211B0.unk10) < 0)
    {
        sp1c->unk10 = v0 * 2;
        sp1c->unk12 = 0;
        sp1c->unkC = (s32)D_802211B0.unk8;
        D_802211B0.unk8 += v0;
    }
    else
    {
        a0 = (v0 + D_802211B0.unk8) - D_802211B0.unk10;
        v0 = v1_2 - a0;
        sp1c->unk10 = (v0)*2;
        sp1c->unk12 = a0 * 2;
        sp1c->unkC = D_802211B0.unk8;
        D_802211B0.unk8 = a0;
    }
    sp1c->unk00 = v1_2;
    sp1c->unk02 = arg0;
}
