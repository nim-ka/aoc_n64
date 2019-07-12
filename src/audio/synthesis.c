#include <ultra64.h>
#include <macros.h>

#include "synthesis.h"
#include "memory.h"
#include "data.h"
#include "load.h"
#include "seqplayer.h"
#include "external.h"

#define aSetLoadBufferPair(pkt, c, off)                  \
    aSetBuffer(pkt, 0, c + 0x740, 0, 320 - c);           \
    aLoadBuffer(pkt, FIX(&D_802211B0.unk14.unk00[off])); \
    aSetBuffer(pkt, 0, c + 0x880, 0, 320 - c);           \
    aLoadBuffer(pkt, FIX(&D_802211B0.unk14.unk04[off]));

#define ALIGN(val, amnt) (((val) + (1 << amnt) - 1) & ~((1 << amnt) - 1))
#define FIX(a) (u16 *)((u8 *)(a) + 0x80000000U)

struct VolumeChange
{
    u16 sourceLeft;
    u16 sourceRight;
    u16 targetLeft;
    u16 targetRight;
};

u64 *func_80313E54(u16 *aiBuf, s32 bufLen, u64 *cmd, u32 updateIndex);
u64 *func_80314480(u16 *aiBuf, s32 arg1, u64 *cmd);
u64 *func_80314F08(u64 *cmd, struct Note *note, s32 arg2);
u64 *func_80314FD4(u64 *cmd, struct Note *note, s32 arg2, u16 arg3, u16 arg4, u32 arg5);
u64 *func_80315030(u64 *cmd, struct Note *note, s32 arg2, u16 arg3, s32 arg4, u32 arg5);
u64 *func_80315094(u64 *cmd, struct Note *note, s32 arg2, u16 arg3, s32 arg4, struct VolumeChange *vol);
u64 *func_803155F4(u64 *cmd, struct Note *note, s32 arg2, s32 arg3, s32 arg4);

void func_80313920(s32 arg0, u32 updateIndex)
{
    struct struct_3920_sp1c *sp1c;
    s32 a1;
    s32 v1;
    s32 v0;
    s32 v1_2;
    s32 a0;
    if (D_802212A2 != 1)
    {
        if (D_802211B0.unk2 == 0)
        {
            sp1c = &D_802211B0.unk2C[D_802211B0.unk3][updateIndex];
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
    sp1c = &D_802211B0.unk2C[D_802211B0.unk3][updateIndex];

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

s32 get_volume_ramping(u16 sourceVol, u16 targetVol, s32 arg2)
{
    f32 ret;
    switch (arg2)
    {
    default:
        ret = D_803332E4[targetVol >> 8] * D_803334E4[sourceVol >> 8];
        break;
    case 128:
        ret = D_80333AE4[targetVol >> 8] * D_80333CE4[sourceVol >> 8];
        break;
    case 136:
        ret = D_803332E4[targetVol >> 8] * D_803334E4[sourceVol >> 8];
        break;
    case 144:
        ret = D_803336E4[targetVol >> 8] * D_803338E4[sourceVol >> 8];
        break;
    }
    return ret;
}

// bufLen will be divisible by 16
u64 *func_80313CD4(u64 *cmdBuf, s32 *writtenCmds, u16 *aiBuf, s32 bufLen)
{
    s32 chunkLen;
    s32 i;
    s32 remaining = bufLen;
    u32 *aiBufPtr = (u32 *)aiBuf;
    u64 *cmd = cmdBuf;
    s32 v0;

    aSegment(cmd++, 0, 0);

    for (i = gAudioUpdatesPerFrame; i > 0; i--)
    {
        if (i == 1)
        {
            // 'remaining' will automatically be divisible by 8, no need to round
            chunkLen = remaining;
        }
        else
        {
            v0 = remaining / i;
            // chunkLen = v0 rounded to nearest multiple of 8
            chunkLen = v0 - (v0 & 7);

            if ((v0 & 7) >= 4)
                chunkLen += 8;
        }
        process_sequences(i - 1);
        if (D_802211B0.unk1 != 0)
        {
            func_80313920(chunkLen, gAudioUpdatesPerFrame - i);
        }
        cmd = func_80313E54((u16 *)aiBufPtr, chunkLen, cmd, gAudioUpdatesPerFrame - i);
        remaining -= chunkLen;
        aiBufPtr += chunkLen;
    }
    if (D_802211B0.unk2 != 0)
        D_802211B0.unk2--;
    D_802211B0.unk3 ^= 1;
    *writtenCmds = cmd - cmdBuf;
    return cmd;
}

u64 *func_80313E54(u16 *aiBuf, s32 bufLen, u64 *cmd, u32 updateIndex)
{
    UNUSED s32 pad1[1];
    s16 ra;
    s16 t4;
    UNUSED s32 pad[2];
    struct struct_3920_sp1c *v1;
    UNUSED s32 pad2[2];

    v1 = &D_802211B0.unk2C[D_802211B0.unk3][updateIndex];

    if (D_802211B0.unk1 == 0)
    {

        aClearBuffer(cmd++, 0x4c0, 640);
        cmd = func_80314480(aiBuf, bufLen, cmd);
    }
    else
    {
        if (D_802212A2 == 1)
        {
            aSetLoadBufferPair(cmd++, 0, v1->unkC);
            if (v1->unk12 != 0)
            {
                aSetLoadBufferPair(cmd++, v1->unk10, 0);
            }
            aDMEMMove(cmd++, 0x740, 0x4c0, 0x280);
            aSetBuffer(cmd++, 0, 0, 0, 640);
            aMix(cmd++, 0, /*gain*/ D_802211B0.unk4 + 0x8000, /*in*/ 0x740, /*out*/ 0x740);
        }
        else
        {
            t4 = (s16)((v1->unkC & 7) * 2);
            ra = (s16)ALIGN(v1->unk10 + t4, 4);
            aSetLoadBufferPair(cmd++, 0, v1->unkC - t4 / 2);
            if (v1->unk12 != 0)
            {
                aSetLoadBufferPair(cmd++, ra, 0);
            }
            aSetBuffer(cmd++, 0, t4 + 0x740, 0x4c0, bufLen << 1);
            aResample(cmd++, D_802211B0.unk0, (u16)D_802211B0.unk6, FIX(D_802211B0.unk1C));
            aSetBuffer(cmd++, 0, t4 + 0x880, 0x600, bufLen << 1);
            aResample(cmd++, D_802211B0.unk0, (u16)D_802211B0.unk6, FIX(D_802211B0.unk20));
            aSetBuffer(cmd++, 0, 0, 0, 640);
            aMix(cmd++, 0, /*gain*/ D_802211B0.unk4 + 32768, /*in*/ 0x4c0, /*out*/ 0x4c0);
            aDMEMMove(cmd++, 0x4c0, 0x740, 0x280);
        }
        cmd = func_80314480(aiBuf, bufLen, cmd);
        if (D_802212A2 == 1)
        {
            //maybe also macro?
            aSetBuffer(cmd++, 0, 0, 0x740, v1->unk10);
            aSaveBuffer(cmd++, FIX(&D_802211B0.unk14.unk00[v1->unkC]));
            aSetBuffer(cmd++, 0, 0, 0x880, v1->unk10);
            aSaveBuffer(cmd++, FIX(&D_802211B0.unk14.unk04[v1->unkC]));
            if (v1->unk12 != 0)
            {
                aSetBuffer2(cmd++, 0, 0, v1->unk10 + 0x740, v1->unk12);
                aSaveBuffer(cmd++, FIX(D_802211B0.unk14.unk00));
                aSetBuffer2(cmd++, 0, 0, v1->unk10 + 0x880, v1->unk12);
                aSaveBuffer(cmd++, FIX(D_802211B0.unk14.unk04));
            }
        }
        else
        {
            aSetBuffer(cmd++, 0, 0, 0x740, 0x280);
            aSaveBuffer(cmd++, FIX(D_802211B0.unk2C[D_802211B0.unk3][updateIndex].unk4));
            D_802211B0.unk0 = 0;
        }
    }
    return cmd;
}

#ifdef NON_MATCHING
u64 *func_80314480(u16 *aiBuf, s32 bufLen, u64 *cmd)
{
    s32 sp174;
    struct Note *s7;
    struct AudioBankSample *sp164;
    ALADPCMloop *sp160;
    s16 *sp15C;
    s32 t2; //150
    s32 t3; //14c
    s32 sp148; //audio flags?
    UNUSED u8 pad8[0x14];
    s32 sp130;
    UNUSED u8 pad7[0xC];
    u8 *sp120;
    u32 t5; //108, definitely unsigned
    //UNUSED u8 pad6[4];
    s32 sp110;
    s32 a0; // 10c
    //UNUSED u8 pad5[0x10c - 0xe8 - 4];
    s32 spE8;
    s32 spE4;
    u32 fp; //probably unsigned
    s32 t0;
    s32 spD8;
    u16 spD6;

    // sp6c is a temporary!

    u16 sp5c;
    s32 sp58;
    s32 sp54;
    s32 s6;
    s32 s6_2;
    s32 s2;

    s32 s0;
    s32 s3;
    s32 s5;
    //s32 v0;
    u32 v1_1;
    s32 v1_2;
    u32 a3;
    s32 t9;
    u8 *v0_2;

    f32 f12;
    UNUSED s32 temp;

    for (sp174 = 0, sp15C = NULL; sp174 < gNoteCount; sp174++)
    {
        s7 = &gNotes[sp174];
        if (IS_BANK_LOAD_COMPLETE(s7->bankId) == FALSE)
        {
            gAudioErrorFlags = (s7->bankId << 8) + sp174 + 0x1000000;
        }
        else if (s7->enabled)
        {
            // This matches much much better if enabled is volatile... but that
            // breaks other functions (e.g. func_80315D94). Can we achieve the
            // volatile effect in some other way?
            sp148 = 0;

            if (s7->unk0b40 == 1)
            {
                sp148 = 1;
                s7->unk14 = 0;
                s7->unk20 = 0;
            }

            if (s7->frequency < US_FLOAT(2.0))
            {
                spE8 = 1;
                if (s7->frequency > US_FLOAT(1.99996))
                {
                    s7->frequency = US_FLOAT(1.99996);
                }
                f12 = s7->frequency;
            }
            else
            {
                spE8 = 2;
                if (s7->frequency >= US_FLOAT(3.99993))
                {
                    s7->frequency = US_FLOAT(3.99993);
                }
                f12 = s7->frequency * US_FLOAT(.5);
            }

            sp5c = (u16)(s32)(f12 * 32768.0f);
            v1_1 = s7->unk20 + (sp5c * bufLen) * 2;
            s7->unk20 = v1_1; // 16-bit store, can't reuse

            if (s7->sound == NULL)
            {
                // v1_1 >> 0x10 stored in s0
                cmd = func_80314F08(cmd, s7, v1_1 >> 0x10);
                spD6 = s7->unk14 * 2 + 0x180;
                s7->unk14 += (v1_1 >> 0x10);
                sp148 = 0;
            }
            else
            {
                sp164 = s7->sound->sample;

                // sp58 is a low-numbered register, so possibly a temporary.
                // Should it be used for v1_1 >> 0x10 above as well? But then
                // the asm matches worse. This variable seems to highly involved
                // in causing this function not to match...
                sp58 = v1_1 >> 0x10; // v0

                sp160 = sp164->loop;
                sp110 = sp160->end;
                sp120 = sp164->sampleAddr;

                sp54 = (spE8 == 1);

                spD8 = 0;
                for (spE4 = 0; spE4 < spE8; spE4++)
                {
                    fp = 0;
                    s5 = 0;

                    // This whole if-else if chain is weird. First it uses sp54
                    // instead of spE8 == 1, and it needs a weird if to not
                    // induce non-matchings all over the rest of the function.
                    // Then it induces a bunch of stack-relative loads that
                    // shouldn't be there. Finally, it relates to sp58, which
                    // behaves very oddly...
                    if (sp54) // spE8 == 1
                    {
                        if (1) // shouldn't be here, but it makes things line up better...
                            t5 = sp58;
                    }
                    else if (sp58 & 1)
                    {
                        t5 = (sp58 & ~1) + (spE4 * 2);
                    }
                    else
                    {
                        t5 = sp58;
                    }

                    if (sp15C != sp164->book->book)
                    {
                        u32 v1;
                        sp15C = sp164->book->book;
                        v1 = sp164->book->order * sp164->book->npredictors;
                        aLoadADPCM(cmd++, v1 * 16, FIX(sp15C));
                    }

                    while (fp != t5)
                    {
                        s32 v1;
                        s32 s0;
                        // sp58 = sp58; here, doesn't happen
                        t2 = 0;
                        t3 = 0;
                        a0 = t5 - fp;
                        s2 = s7->unk14 & 0xf;
                        v1 = sp110 - s7->unk14;

                        if (s2 == 0 && !s7->unk0b20)
                        {
                            s2 = 16;
                        }
                        s6 = 16 - s2; // a1

                        if (a0 < v1)
                        {
                            t0 = (a0 - s6 + 0xf) / 16;
                            s0 = t0 * 16;
                            s3 = s6 + s0 - a0;
                        }
                        else
                        {
                            s0 = v1 + s2 - 0x10;
                            s3 = 0;
                            if (s0 <= 0)
                            {
                                s0 = 0;
                                s6 = v1;
                            }
                            t0 = (s0 + 0xf) / 16;
                            if (sp160->count != 0)
                            {
                                t3 = 1;
                            }
                            else
                            {
                                t2 = 1;
                            }
                        }

                        // Improve regalloc for saved registers. Probably
                        // shouldn't be here, but it gives nicer diffs for now.
                        s6_2 = s6;

                        if (t0 != 0)
                        {
                            // maybe keep a var for t0 * 9?
                            v0_2 = func_80317270(sp120 + (s7->unk14 - s2 + 0x10) / 16 * 9,
                                    t0 * 9, sp148, &s7->unk3);
                            a3 = (u32)v0_2 & 0xf;
                            aSetBuffer(cmd++, 0, 0x3f0, 0, t0 * 9 + a3);
                            aLoadBuffer(cmd++, FIX(v0_2 - a3));
                        }
                        else
                        {
                            s0 = 0;
                            a3 = 0;
                        }

                        if (s7->unk0b20 != 0)
                        {
                            aSetLoop(cmd++, FIX(sp164->loop + 8));
                            sp148 = A_LOOP; // = 2
                            s7->unk0b20 = 0;
                        }

                        if (fp == 0)
                        {
                            aSetBuffer(cmd++, 0, a3 + 0x3f0, 0x180, s0 * 2);
                            aADPCMdec(cmd++, sp148, FIX(s7->unk34->unk00));
                            sp130 = s2 * 2;
                        }
                        else
                        {
                            aSetBuffer(cmd++, 0, a3 + 0x3f0, ALIGN(s5, 5) + 0x180, s0 * 2);
                            aADPCMdec(cmd++, sp148, FIX(s7->unk34->unk00));
                            aDMEMMove(cmd++, ALIGN(s5, 5) + (s2 * 2) + 0x180, s5 + 0x180, (s0 + s6_2 - s3) * 2);
                        }

                        fp = fp + s0 + s6_2 - s3;
                        v1_2 = s0 + s6_2 - s3;
                        switch (sp148)
                        {
                        case 1: // A_INIT?
                            sp130 = 0;
                            s5 += s0 * 2;
                            break;

                        case A_LOOP: // = 2
                            s5 += v1_2 * 2;
                            break;

                        default:
                            if (s5 != 0)
                            {
                                s5 += v1_2 * 2;
                            }
                            else
                            {
                                s5 = (v1_2 + s2) * 2;
                            }
                            break;
                        }
                        sp148 = 0;

                        if (t2)
                        {
                            aClearBuffer(cmd++, s5 + 0x180, (t5 - fp) * 2);
                            s7->unk14 = 0;
                            s7->unk0b10 = 1;
                            s7->enabled = 0;
                            break; // goto? doesn't matter, though
                        }
                        if (t3)
                        {
                            s7->unk0b20 = 1;
                            s7->unk14 = sp160->start;
                        }
                        else
                        {
                            s7->unk14 += a0;
                        }
                    }

                    switch (spE8)
                    {
                    case 1:
                        spD6 = sp130 + 0x180;
                        break;

                    case 2:
                        switch (spE4)
                        {
                        case 0:
                            aSetBuffer(cmd++, 0, sp130 + 0x180, 0x20, t5 + 4);
                            aResample(cmd++, 0x1, 0xff60, FIX(s7->unk34->unkf0));
                            spD8 = t5 + 4;
                            spD6 = 36;
                            if (s7->unk0b10 != 0)
                            {
                                aClearBuffer(cmd++, t5 + 0x24, t5 + 0x10);
                            }
                            break;

                        case 1:
                            aSetBuffer(cmd++, 0, sp130 + 0x180, 0x160, t5 + 8);
                            aResample(cmd++, 0x1, 0xff60, FIX(s7->unk34->unkf0));
                            aDMEMMove(cmd++, 0x164, spD8 + 0x20, t5 + 4);
                            break;
                        }
                    }

                    if (s7->unk0b10 != 0)
                    {
                        // ("break;" doesn't match)
                        sp148 = 0;
                        goto out;
                    }
                }

                sp148 = 0;
            }
out:

            if (s7->unk0b40 == 1)
            {
                sp148 = 1;
                s7->unk0b40 = 0;
            }

            cmd = func_80314FD4(cmd, s7, bufLen * 2, sp5c, spD6, sp148);

            if (s7->panRight != 0 || s7->unk10 != 0)
            {
                s0 = 1;
            }
            else if (s7->panLeft != 0 || s7->unk12 != 0)
            {
                s0 = 2;
            }
            else
            {
                s0 = 0;
            }

            cmd = func_80315030(cmd, s7, bufLen, 0, s0, sp148);
            if (s7->unk1)
            {
                cmd = func_803155F4(cmd, s7, bufLen * 2, sp148, s0);
            }
        }
    }

    t9 = bufLen * 2;
    aSetBuffer(cmd++, 0, 0, 0, t9);
    aInterleave(cmd++, 0x4c0, 0x600);
    t9 *= 2;
    aSetBuffer(cmd++, 0, 0, 0, t9);
    aSaveBuffer(cmd++, FIX(aiBuf));
    return cmd;
}

#elif defined(VERSION_JP)
GLOBAL_ASM("asm/non_matchings/func_80314480_jp.s")
#else
GLOBAL_ASM("asm/non_matchings/func_80314480_us.s")
#endif

u64 *func_80314F08(u64 *cmd, struct Note *note, s32 arg2)
{
    s32 a3;
    s32 i;
    aSetBuffer(cmd++, /*flags*/ 0, /*dmemin*/ 0x180, /*dmemout*/ 0,
            /*count*/ sizeof(note->unk34->samples)); //interesting that it's 128...
    aLoadBuffer(cmd++, FIX(note->unk34->samples));
    note->unk14 = (note->sampleCount - 1) & note->unk14;
    a3 = 64 - note->unk14;
    if (a3 < arg2)
    {
        for (i = 0; i <= (arg2 - a3 + 63) / 64 - 1; i++)
        {
            aDMEMMove(cmd++,
                    /*dmemin*/ 0x180,
                    /*dmemout*/ 512 + i * sizeof(note->unk34->samples),
                    /*count*/ sizeof(note->unk34->samples))
        }
    }
    return cmd;
}

u64 *func_80314FD4(u64 *cmd, struct Note *note, s32 arg2, u16 arg3, u16 arg4, u32 arg5)
{
    aSetBuffer(cmd++, 0, arg4, 0, arg2);
    aResample(cmd++, arg5, arg3, FIX(note->unk34->unk20));
    return cmd;
}

u64 *func_80315030(u64 *cmd, struct Note *note, s32 arg2, u16 arg3, s32 arg4, UNUSED u32 arg5)
{
    UNUSED u8 pad[16];
    struct VolumeChange vol;
    vol.sourceLeft = note->curVolLeft;
    vol.sourceRight = note->curVolRight;
    vol.targetLeft = note->targetVolLeft;
    vol.targetRight = note->targetVolRight;
    note->curVolLeft = vol.targetLeft;
    note->curVolRight = vol.targetRight;
    return func_80315094(cmd, note, arg2, arg3, arg4, &vol);
}

u64 *func_80315094(u64 *cmd, struct Note *note, s32 arg2, u16 arg3, s32 arg4, struct VolumeChange *vol)
{
    UNUSED u8 pad[3];
    u8 mixerFlags;
    UNUSED u8 pad2[8];
    s32 rampLeft, rampRight;
    if (note->unk1)
    {
        aClearBuffer(cmd++, 0x200, 320);

        switch (arg4)
        {
        case 1:
            aSetBuffer(cmd++, 0, arg3, 0x200, arg2 * 2);
            aSetBuffer(cmd++, 8, 0x600, 0x740, 0x880);
            break;
        case 2:
            aSetBuffer(cmd++, 0, arg3, 0x4c0, arg2 * 2);
            aSetBuffer(cmd++, 8, 0x200, 0x740, 0x880);
            break;
        default:
            aSetBuffer(cmd++, 0, arg3, 0x4c0, arg2 * 2);
            aSetBuffer(cmd++, 8, 0x600, 0x740, 0x880);
            break;
        }
    }
    else
    {
        if (note->unk0b4)
        {
            aClearBuffer(cmd++, 0x200, 640);
            aSetBuffer(cmd++, 0, arg3, 0x200, arg2 * 2);
            aSetBuffer(cmd++, 8, 0x600, 0x340, 0x880);
        }
        else if (note->unk0b2)
        {
            aClearBuffer(cmd++, 0x200, 640);
            aSetBuffer(cmd++, 0, arg3, 0x4c0, arg2 * 2);
            aSetBuffer(cmd++, 8, 0x200, 0x740, 0x340);
        }
        else
        {
            aSetBuffer(cmd++, 0, arg3, 0x4c0, arg2 * 2);
            aSetBuffer(cmd++, 8, 0x600, 0x740, 0x880);
        }
    }

    if (vol->sourceLeft == vol->targetLeft && vol->sourceRight == vol->targetRight && !note->unk0b8)
    {
        mixerFlags = A_CONTINUE;
    }
    else
    {
        mixerFlags = A_INIT;
        rampLeft = get_volume_ramping(vol->sourceLeft, vol->targetLeft, arg2);
        rampRight = get_volume_ramping(vol->sourceRight, vol->targetRight, arg2);

        aSetVolume(cmd++, A_VOL | A_LEFT, vol->sourceLeft, 0, 0);
        aSetVolume(cmd++, A_VOL | A_RIGHT, vol->sourceRight, 0, 0);
        aSetVolume32(cmd++, A_RATE | A_LEFT, vol->targetLeft, rampLeft);
        aSetVolume32(cmd++, A_RATE | A_RIGHT, vol->targetRight, rampRight);
        aSetVolume(cmd++, A_AUX, D_802212A0, 0, note->reverbVol);
    }
    if (D_802211B0.unk1 && note->reverb)
    {
        aEnvMixer(cmd++, mixerFlags | A_AUX, FIX(note->unk34->unk40));
        if (note->unk0b4)
        {
            aSetBuffer(cmd++, 0, 0, 0, arg2 * 2);
            aMix(cmd++, 0, /*gain*/ 0x8000, /*in*/ 0x200, /*out*/ 0x4c0);
            aMix(cmd++, 0, /*gain*/ 0x8000, /*in*/ 0x340, /*out*/ 0x740);
        }
        else if (note->unk0b2)
        {
            aSetBuffer(cmd++, 0, 0, 0, arg2 * 2);
            aMix(cmd++, 0, /*gain*/ 0x8000, /*in*/ 0x200, /*out*/ 0x600);
            aMix(cmd++, 0, /*gain*/ 0x8000, /*in*/ 0x340, /*out*/ 0x880);
        }
    }
    else
    {
        aEnvMixer(cmd++, mixerFlags, FIX(note->unk34->unk40));
        if (note->unk0b4)
        {
            aSetBuffer(cmd++, 0, 0, 0, arg2 * 2);
            aMix(cmd++, 0, /*gain*/ 0x8000, /*in*/ 0x200, /*out*/ 0x4c0);
        }
        else if (note->unk0b2)
        {
            aSetBuffer(cmd++, 0, 0, 0, arg2 * 2);
            aMix(cmd++, 0, /*gain*/ 0x8000, /*in*/ 0x200, /*out*/ 0x600);
        }
    }
    return cmd;
}

u64 *func_803155F4(u64 *cmd, struct Note *note, s32 arg2, s32 arg3, s32 leftRight)
{
    u16 t0;
    u16 a3;
    u16 panVolume;
    u16 pitch; // t2
    UNUSED s32 padding[11];

    switch (leftRight)
    {
    case 1:
        t0 = 0x4c0;
        note->unk12 = 0;
        panVolume = note->panRight;
        a3 = note->unk10;
        note->unk10 = panVolume;
        break;
    case 2:
        t0 = 0x600;
        note->unk10 = 0;
        panVolume = note->panLeft;
        a3 = note->unk12;
        note->unk12 = panVolume;
        break;
    default:
        return cmd;
    }

    if (arg3 != 1) //A_INIT?
    {
        if (a3 == 0)
        {
            aDMEMMove(cmd++, 0x200, 0, 8);
            aClearBuffer(cmd++, 8, 8);
            aDMEMMove(cmd++, 0x200, 0x10, 0x10);
            aSetBuffer(cmd++, 0, 0, 0, 32);
            aSaveBuffer(cmd++, FIX(note->unk34->unk90));
            pitch = (arg2 << 0xf) / (panVolume + arg2 - a3 + 8);
            aSetBuffer(cmd++, 0, 0x208, 0, panVolume + arg2 - a3);
            aResample(cmd++, 0, pitch, FIX(note->unk34->unk90));
        }
        else
        {
            pitch = (panVolume == 0) ?
                (arg2 << 0xf) / (arg2 - a3 - 4) :
                (arg2 << 0xf) / (arg2 + panVolume - a3);
            aSetBuffer(cmd++, 0, 0x200, 0, panVolume + arg2 - a3);
            aResample(cmd++, 0, pitch, FIX(note->unk34->unk90));
        }

        if (a3 != 0)
        {
            aSetBuffer(cmd++, 0, 0x200, 0, a3);
            aLoadBuffer(cmd++, FIX(note->unk34->unkb0));
            aDMEMMove(cmd++, 0, a3 + 0x200, panVolume + arg2 - a3);
        }
        else
        {
            aDMEMMove(cmd++, 0, 0x200, panVolume + arg2 - a3);
        }
    }
    else
    {
        aDMEMMove(cmd++, 0x200, 0, arg2);
        aDMEMMove(cmd++, 0, panVolume + 0x200, arg2);
        aClearBuffer(cmd++, 0x200, panVolume);
    }

    if (panVolume)
    {
        aSetBuffer(cmd++, 0, 0, arg2 + 0x200, panVolume);
        aSaveBuffer(cmd++, FIX(note->unk34->unkb0));
    }

    aSetBuffer(cmd++, 0, 0, 0, arg2);
    aMix(cmd++, 0, /*gain*/ 0x7fff, /*in*/ 0x200, /*out*/ t0);

    return cmd;
}

void note_init(struct Note *note) // This is wrong. It only partially updates the note
{
    note->targetVolLeft = 0;
    note->targetVolRight = 0;
    note->reverb = 0;
    note->reverbVol = 0;
    note->unused = 0;
    note->curVolLeft = 1;
    note->curVolRight = 1;
    note->frequency = 0.0f;
}

void func_803159EC(struct Note *note, f32 velocity, f32 pan, u8 reverb)
{
    s32 v0;
    f32 f0;
    f32 f2;
#ifdef VERSION_JP
    v0 = MIN((s32)(pan * 127.5), 127);
#endif
    if (note->soundModeSomething && gSoundMode == SOUND_MODE_HEADSET)
    {
        s8 panIndex;
        panIndex = MIN((s8)(pan * 10.0f), 9);
        note->panLeft = gPanQuantization[panIndex];
        note->panRight = gPanQuantization[9 - panIndex];
        note->unk0b4 = 0;
        note->unk0b2 = 0;
        note->unk1 = 1;
#ifndef VERSION_JP
        v0 = (s32)(pan * 127.5f) & 127;
#endif
        f0 = D_80332CE4[v0];
        f2 = D_80332CE4[127 - v0];
    }
    else if (note->soundModeSomething && gSoundMode == SOUND_MODE_STEREO)
    {
        u8 v1 = 0;
        u8 a1 = 0;
        note->panLeft = 0;
        note->panRight = 0;
        note->unk1 = 0;
#ifndef VERSION_JP
        v0 = (s32)(pan * 127.5f) & 127;
#endif
        f0 = D_80332EE4[v0];
        f2 = D_80332EE4[127 - v0];
        if (v0 < 0x20)
        {
            v1 = 1;
        }
        else if (v0 > 0x60)
        {
            a1 = 1;
        }
        note->unk0b4 = a1;
        note->unk0b2 = v1;
    }
    else if (gSoundMode == SOUND_MODE_MONO)
    {
        f0 = .707f;
        f2 = .707f;
    }
    else
    {
#ifndef VERSION_JP
        v0 = (s32)(pan * 127.5f) & 127;
#endif
        f0 = D_803330E4[v0];
        f2 = D_803330E4[127 - v0];
    }

    velocity = MAX(velocity, 0);
#ifdef VERSION_JP
    note->targetVolLeft = (u16)(velocity * f0) & ~0x80FF; // 0x7F00, but that doesn't match
    note->targetVolRight = (u16)(velocity * f2) & ~0x80FF;
#else
    note->targetVolLeft = (u16)(s32)(velocity * f0) & ~0x80FF;
    note->targetVolRight = (u16)(s32)(velocity * f2) & ~0x80FF;
#endif
    if (note->targetVolLeft == 0)
    {
        note->targetVolLeft++;
    }
    if (note->targetVolRight == 0)
    {
        note->targetVolRight++;
    }
    if (note->reverb != reverb)
    {
        note->reverb = reverb;
        note->reverbVol = reverb << 8;
        note->unk0b8 = 1;
        return;
    }
    if (note->unk0b40)
    {
        note->unk0b8 = 1;
        return;
    }
    note->unk0b8 = 0;
    return;
}

void note_set_frequency(struct Note *note, f32 frequency)
{
    note->frequency = frequency;
}

// init something?
void func_80315D94(struct Note *note)
{
    note->unk1 = 0;
    note->panLeft = 0;
    note->enabled = TRUE;
    note->unk0b40 = TRUE;
    note->unk0b20 = FALSE;
    note->unk0b10 = FALSE;
    note->unk0b4 = FALSE;
    note->unk0b2 = FALSE;
    note->panRight = 0;
    note->unk10 = 0;
    note->unk12 = 0;
}

void func_80315DE0(struct Note *note)
{
    if (note->unk0b40 == 1)
    {
        note->unk0b40 = 0;
    }
    else
    {
        func_803159EC(note, 0, .5, 0);
    }
    note->unk4 = 0;
    note->enabled = FALSE;
    note->unk0b10 = FALSE;
    note->parentLayer = NO_LAYER;
    note->unk28 = NO_LAYER;
}
