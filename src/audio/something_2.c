#include <ultra64.h>
#include "something.h"
#include "unused.h"

// Like aSetBuffer, expect that the order of operands to the w1 bitor is
// swapped. This is needed for the code to match... (In fact, it's almost
// fine to redefine aSetBuffer itself this way, but there's a single function
// whose bitor then get its order of operands messed up.)
#define aSetBuffer2(pkt, f, i, o, c)                                    \
    {                                                                   \
        Acmd *_a = (Acmd *)pkt;                                         \
                                                                        \
        _a->words.w0 = (_SHIFTL(A_SETBUFF, 24, 8) | _SHIFTL(f, 16, 8) | \
                        _SHIFTL(i, 0, 16));                             \
        _a->words.w1 =  _SHIFTL(c, 0, 16) | _SHIFTL(o, 16, 16);         \
    }

//volume related
s32 func_80313BB0(u16 arg0, u16 arg1, s32 arg2)
{
    f32 ret;
    switch (arg2)
    {
    default:
        ret = D_803332E4[arg1 >> 8] * D_803334E4[arg0 >> 8];
        break;
    case 128:
        ret = D_80333AE4[arg1 >> 8] * D_80333CE4[arg0 >> 8];
        break;
    case 136:
        ret = D_803332E4[arg1 >> 8] * D_803334E4[arg0 >> 8];
        break;
    case 144:
        ret = D_803336E4[arg1 >> 8] * D_803338E4[arg0 >> 8];
        break;
    }
    return ret;
}

u64 *func_80313CD4(u64 *arg0, s32 *arg1, u16 *arg2, s32 arg3)
{
    s32 s0;
    s32 i;
    s32 s2 = arg3;
    s32 s3;
    u32 *s4 = (u32 *)arg2;
    u64 *s6 = arg0;
    s32 v0;

    aSegment(s6++, 0, 0);

    for (i = D_80226D7E; i > 0; i--)
    {
        s3 = i - 1;
        if (i == 1)
        {
            s0 = s2;
        }
        else
        {
            v0 = s2 / i;
            s0 = v0 - (v0 & 7);

            if ((v0 & 7) >= 4)
                s0 += 8;
        }
        func_8031D384(s3);
        if (D_802211B0.unk1 != 0)
        {
            func_80313920(s0, D_80226D7E - i);
        }
        s6 = func_80313E54((u16 *)s4, s0, s6, D_80226D7E - i);
        s2 -= s0;
        s4 += s0;
    }
    if (D_802211B0.unk2 != 0)
        D_802211B0.unk2--;
    D_802211B0.unk3 ^= 1;
    arg1[0] = s6 - arg0;
    return s6;
}

u64 *func_80313E54(u16 *arg0, s32 arg1, u64 *arg2, u32 arg3)
{
    UNUSED s32 pad1[1];
    s16 ra;
    s16 t4;
    UNUSED s32 pad[2];
    struct struct_3920_sp1c *v1;
    UNUSED s32 pad2[2];

    v1 = &D_802211B0.unk2C[D_802211B0.unk3][arg3];

    if (D_802211B0.unk1 == 0)
    {

        aClearBuffer(arg2++, 0x4c0, 640);
        arg2 = func_80314480(arg0, arg1, arg2);
    }
    else
    {
        if (D_802212A2 == 1)
        {
            aSetLoadBufferPair(arg2, 0, v1->unkC);
            if (v1->unk12 != 0)
            {
                aSetLoadBufferPair(arg2, v1->unk10, 0);
            }
            aDMEMMove(arg2++, 0x740, 0x4c0, 0x280);
            aSetBuffer(arg2++, 0, 0, 0, 640);
            aMix(arg2++, 0, D_802211B0.unk4 + 0x8000, 0x740, 0x740);
        }
        else
        {
            t4 = (s16)((v1->unkC & 7) * 2);
            ra = (s16)ALIGN(v1->unk10 + t4, 4);
            aSetLoadBufferPair(arg2, 0, v1->unkC - t4 / 2);
            if (v1->unk12 != 0)
            {
                aSetLoadBufferPair(arg2, ra, 0);
            }
            aSetBuffer(arg2++, 0, t4 + 0x740, 0x4c0, arg1 << 1);
            aResample(arg2++, D_802211B0.unk0, (u16)D_802211B0.unk6, FIX(D_802211B0.unk1C));
            aSetBuffer(arg2++, 0, t4 + 0x880, 0x600, arg1 << 1);
            aResample(arg2++, D_802211B0.unk0, (u16)D_802211B0.unk6, FIX(D_802211B0.unk20));
            aSetBuffer(arg2++, 0, 0, 0, 640);
            aMix(arg2++, 0, D_802211B0.unk4 + 32768, 0x4c0, 0x4c0);
            aDMEMMove(arg2++, 0x4c0, 0x740, 0x280);
        }
        arg2 = func_80314480(arg0, arg1, arg2);
        if (D_802212A2 == 1)
        {
            //maybe also macro?
            aSetBuffer(arg2++, 0, 0, 0x740, v1->unk10);
            aSaveBuffer(arg2++, FIX(&D_802211B0.unk14.unk00[v1->unkC]));
            aSetBuffer(arg2++, 0, 0, 0x880, v1->unk10);
            aSaveBuffer(arg2++, FIX(&D_802211B0.unk14.unk04[v1->unkC]));
            if (v1->unk12 != 0)
            {
                aSetBuffer2(arg2++, 0, 0, v1->unk10 + 0x740, v1->unk12);
                aSaveBuffer(arg2++, FIX(D_802211B0.unk14.unk00));
                aSetBuffer2(arg2++, 0, 0, v1->unk10 + 0x880, v1->unk12);
                aSaveBuffer(arg2++, FIX(D_802211B0.unk14.unk04));
            }
        }
        else
        {
            aSetBuffer(arg2++, 0, 0, 0x740, 0x280);
            aSaveBuffer(arg2++, FIX(D_802211B0.unk2C[D_802211B0.unk3][arg3].unk4));
            D_802211B0.unk0 = 0;
        }
    }
    return arg2;
}
