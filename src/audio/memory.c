#include <ultra64.h>
#include <macros.h>

#include "memory.h"
#include "data.h"
#include "load.h"
#include "synthesis.h"
#include "seqplayer.h"
#include "external.h"
#include "effects.h"

#define ALIGN16(val) (((val) + 0xF) & ~0xF)

struct Struct803161E0
{
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
}; // size = 0x10

struct U32Pair
{
    u32 first;
    u32 second;
}; // size = 0x8

extern struct SoundAllocPool D_802212A8;
extern struct SoundAllocPool D_802212F8;
extern struct SoundAllocPool D_80221308;
extern struct SoundAllocPool D_80221318;

extern struct SoundMultiPool gUnusedLoadedPool;

extern s32 D_80226D6C;

extern struct Struct803161E0 D_80221898;
extern struct U32Pair D_802218A8;
extern struct Struct803161E0 D_802218B0;
extern struct Struct803161E0 D_802218C0;

void func_80315E60(void)
{
    s32 i;

    for (i = 0; i < 64; i++)
    {
        gBankLoadStatus[i] = SOUND_LOAD_STATUS_NOT_LOADED;
    }

    for (i = 0; i < 256; i++)
    {
        gSeqLoadStatus[i] = SOUND_LOAD_STATUS_NOT_LOADED;
    }
}

void discard_bank(s32 bankId)
{
    s32 i;

    for (i = 0; i < gNoteCount; i++)
    {
        struct Note *note = &gNotes[i];

        if (note->bankId == bankId)
        {
            if (note->unk4 > 1)
            {
                note->parentLayer->enabled = FALSE;
                note->parentLayer->finished = TRUE;
            }
            func_80315DE0(note);
            func_803195A4(&note->noteListItem);
            note_list_item_add(&D_80225EA8[0], &note->noteListItem);
        }
    }
}

void discard_sequence(s32 seqId)
{
    s32 i;

    for (i = 0; i < SEQUENCE_PLAYERS; i++)
    {
        if (gSequencePlayers[i].enabled && gSequencePlayers[i].seqId == seqId)
            sequence_player_disable(gSequencePlayers + i);
    }
}

#ifdef NON_MATCHING
void *soundAlloc(struct SoundAllocPool *pool, u32 size)
{
    // Has a bunch of register swaps: v1 -> a2/a0, a1 -> v1, a2 -> a1
    s32 last; // a2
    s32 i; // a3
    u8 *ret; // a1, v0
    s32 aligned; // t6

    ret = pool->cur;
    aligned = ALIGN16(size);
    if (pool->cur + aligned <= pool->size + pool->start)
    {
        pool->cur += aligned;
        last = pool->cur - ret - 1;
        for (i = 0; i <= last; i++)
        {
            ret[i] = 0;
        }
    }
    else
    {
        return NULL;
    }

    return ret;
}

#else
GLOBAL_ASM("asm/non_matchings/soundAlloc.s")
#endif

void func_80316094(struct SoundAllocPool *pool, void *arg1, u32 arg2)
{
    pool->cur = pool->start = (u8 *)(((u32) arg1 + 0xf) & -0x10);
    pool->size = arg2;
    pool->unkC = 0;
}

void func_803160B4(struct SoundPoolHolder *arg0)
{
    arg0->pool.unkC = 0;
    arg0->unk0 = 0;
    arg0->pool.cur = arg0->pool.start;
}

void func_803160C8(struct SoundPoolHolder2 *arg0)
{
    arg0->pool.unkC = 0;
    arg0->side = 0;
    arg0->arr[1].ptr = arg0->pool.size + arg0->pool.start;
    arg0->arr[0].id = -1;
    arg0->arr[1].id = -1;
    arg0->pool.cur = arg0->pool.start;
    arg0->arr[0].ptr = arg0->pool.start;
}

void unused_803160F8(struct SoundAllocPool *pool)
{
    pool->unkC = 0;
    pool->cur = pool->start;
}

void func_80316108(s32 arg0)
{
    func_80316094(&gSoundPool, gAudioHeap, arg0);
    func_80316094(&D_802212A8, gAudioHeap + arg0, D_80333EEC - arg0);
}

void func_80316164(struct Struct803161E0 *a)
{
    D_802212A8.cur = D_802212A8.start;
    func_80316094(&D_802212C8, soundAlloc(&D_802212A8, a->unk0), a->unk0);
    func_80316094(&D_802212F8, soundAlloc(&D_802212A8, a->unkC), a->unkC);
}

void func_803161E0(struct U32Pair *a)
{
    D_802212F8.cur = D_802212F8.start;
    func_80316094(&D_80221308, soundAlloc(&D_802212F8, a->first), a->first);
    func_80316094(&D_80221318, soundAlloc(&D_802212F8, a->second), a->second);
}

void func_8031625C(struct Struct803161E0 *a)
{
    D_80221308.cur = D_80221308.start;
    func_80316094(&gSeqLoadedPool.first.pool, soundAlloc(&D_80221308, a->unk0), a->unk0);
    func_80316094(&gSoundLoadedPool.first.pool, soundAlloc(&D_80221308, a->unk4), a->unk4);
    func_80316094(&gUnusedLoadedPool.first.pool, soundAlloc(&D_80221308, a->unk8), a->unk8);
    func_803160B4(&gSeqLoadedPool.first);
    func_803160B4(&gSoundLoadedPool.first);
    func_803160B4(&gUnusedLoadedPool.first);
}

void func_80316318(struct Struct803161E0 *a)
{
    D_80221318.cur = D_80221318.start;
    func_80316094(&gSeqLoadedPool.second.pool, soundAlloc(&D_80221318, a->unk0), a->unk0);
    func_80316094(&gSoundLoadedPool.second.pool, soundAlloc(&D_80221318, a->unk4), a->unk4);
    func_80316094(&gUnusedLoadedPool.second.pool, soundAlloc(&D_80221318, a->unk8), a->unk8);
    func_803160C8(&gSeqLoadedPool.second);
    func_803160C8(&gSoundLoadedPool.second);
    func_803160C8(&gUnusedLoadedPool.second);
}

static void unused_803163D4()
{
}

#ifdef NON_MATCHING
void *alloc_bank_or_seq(struct SoundMultiPool *arg0, s32 arg1, s32 size, s32 arg3, s32 id)
{
    // arg3 = 0, 1 or 2?

    u8 *table; // sp5C
    u8 isSound; // sp5B
    struct SoundAllocPool *pool;
    void *ret;
    u32 firstVal;
    u32 secondVal;
    u32 bothDiscardable;
    u32 leftDiscardable, rightDiscardable;
    u32 leftNotLoaded, rightNotLoaded;
    u32 leftAvail, rightAvail;
    UNUSED s32 temp;
    struct SoundPoolHolder2 *v1; // sp30
    struct SoundPoolHolder *first = &arg0->first;

    if (arg3 == 0)
    {
        v1 = &arg0->second;
        if (arg0 == &gSeqLoadedPool)
        {
            table = gSeqLoadStatus;
            isSound = FALSE;
        }
        else if (arg0 == &gSoundLoadedPool)
        {
            table = gBankLoadStatus;
            isSound = TRUE;
        }

        firstVal = (v1->arr[0].id == -1 ? SOUND_LOAD_STATUS_NOT_LOADED :
                table[v1->arr[0].id]); // a3, a2
        secondVal = (v1->arr[1].id == -1 ? SOUND_LOAD_STATUS_NOT_LOADED :
                table[v1->arr[1].id]); // a1
        leftNotLoaded = (firstVal == SOUND_LOAD_STATUS_NOT_LOADED);
        leftDiscardable = (firstVal == SOUND_LOAD_STATUS_DISCARDABLE); // t0
        leftAvail = (firstVal != SOUND_LOAD_STATUS_IN_PROGRESS);
        rightNotLoaded = (secondVal == SOUND_LOAD_STATUS_NOT_LOADED);
        rightDiscardable = (secondVal == SOUND_LOAD_STATUS_DISCARDABLE);
        rightAvail = (secondVal != SOUND_LOAD_STATUS_IN_PROGRESS);
        bothDiscardable = (leftDiscardable && rightDiscardable); // a0

        if (leftNotLoaded)
        {
            v1->side = 0;
        }
        else if (rightNotLoaded)
        {
            v1->side = 1;
        }
        else if (bothDiscardable)
        {
            // Use the opposite side from last time.
        }
        else if (leftDiscardable)
        {
            v1->side = 0;
        }
        else if (rightDiscardable)
        {
            v1->side = 1;
        }
        else if (leftAvail)
        {
            v1->side = 0;
        }
        else if (rightAvail)
        {
            v1->side = 1;
        }
        else
        {
            // Both left and right sides are being loaded into.
            return NULL;
        }

        if (v1->arr[v1->side].id != -1)
        {
            table[v1->arr[v1->side].id] = SOUND_LOAD_STATUS_NOT_LOADED;
            if (isSound == TRUE)
            {
                discard_bank(v1->arr[v1->side].id);
            }
        }

        pool = &arg0->second.pool; // a1
        switch (v1->side)
        {
        case 0:
            v1->arr[0].ptr = pool->start;
            v1->arr[0].id = id;
            v1->arr[0].size = size;

            pool->cur = pool->start + size;

            if (v1->arr[1].ptr < pool->cur)
            {
                // Throw out the entry on the other side if it doesn't fit.
                // (possible @bug: what if it's currently being loaded?)
                table[v1->arr[1].id] = SOUND_LOAD_STATUS_NOT_LOADED;

                switch (isSound)
                {
                case FALSE:
                    discard_sequence(v1->arr[1].id);
                    break;
                case TRUE:
                    discard_bank(v1->arr[1].id);
                    break;
                }

                v1->arr[1].id = -1;
                v1->arr[1].ptr = pool->size + pool->start;
            }

            ret = v1->arr[0].ptr;
            break;

        case 1:
            v1->arr[1].ptr = pool->size + pool->start - size - 0x10;
            v1->arr[1].id = id;
            v1->arr[1].size = size;

            if (v1->arr[1].ptr < pool->cur)
            {
                table[v1->arr[0].id] = SOUND_LOAD_STATUS_NOT_LOADED;

                switch (isSound)
                {
                case FALSE:
                    discard_sequence(v1->arr[0].id);
                    break;
                case TRUE:
                    discard_bank(v1->arr[0].id);
                    break;
                }

                v1->arr[0].id = -1;
                pool->cur = pool->start;
            }

            ret = v1->arr[1].ptr;
            break;

        default:
            return NULL;
        }

        // Switch sides for next time in case both entries are
        // SOUND_LOAD_STATUS_DISCARDABLE.
        v1->side ^= 1;

        return ret;
    }

    arg0->arr[first->unk0].ptr = soundAlloc(&first->pool, arg1 * size);

    if (arg0->arr[first->unk0].ptr == NULL)
    {
        switch (arg3)
        {
        case 2:
            // Prevent tail call optimization.
            ret = alloc_bank_or_seq(arg0, arg1, size, 0, id);
            return ret;
        case 1:
            return NULL;
        }
    }

    // TODO: why is this guaranteed to write <= 32 entries...?
    // Because the buffer is small enough that more don't fit?
    arg0->arr[first->unk0].id = id;
    arg0->arr[first->unk0].size = size;
    first->unk0++; return arg0->arr[first->unk0 - 1].ptr;
}

#else
GLOBAL_ASM("asm/non_matchings/alloc_bank_or_seq.s")
#endif

void *get_bank_or_seq(struct SoundMultiPool *arg0, s32 arg1, s32 id)
{
    u32 i;
    void *ret;
    struct SoundPoolHolder2 *second = &arg0->second;

    if (arg1 == 0)
    {
        // Try not to overwrite sound that we have just accessed, by setting side appropriately.
        if (second->arr[0].id == id)
        {
            second->side = 1;
            return second->arr[0].ptr;
        }
        else if (second->arr[1].id == id)
        {
            second->side = 0;
            return second->arr[1].ptr;
        }
        return NULL;
    }
    else
    {
        struct SoundPoolHolder *first = &arg0->first;
        for (i = 0; i < first->unk0; i++)
        {
            if (id == arg0->arr[i].id)
            {
                return arg0->arr[i].ptr;
            }
        }

        if (arg1 == 2)
        {
            // Prevent tail call optimization by using a temporary.
            // (Did they compile with -Wo,-notail?)
            ret = get_bank_or_seq(arg0, 0, id);
            return ret;
        }
        return NULL;
    }
}

void func_803168CC(void)
{
    D_802211B0.unk4 -= D_802211B0.unk4 / 4;
}

/**
 * Waits until a specified number of audio frames have been created
 */
void wait_for_audio_frames(s32 frames)
{
    gActiveAudioFrames = 0;
    // Sound thread will update gActiveAudioFrames
    while (gActiveAudioFrames < frames) { /* spin */ }
}

#ifdef NON_MATCHING
#define frames s1
void func_80316928(struct Struct80332190 *arg0)
{
    // Wrong regalloc, and a lui which is too far up.
    s32 sp2C;
    s16 *mem;
    s32 i; // s0
    s32 j;
    s32 k;
    s32 sum1;
    s32 sum2;
    s32 sum3;
    s32 sum4;
    s32 s1;
    s8 temp8;
    s32 size;
    UNUSED s32 temp;

    if (gAudioLoadLock != AUDIO_LOCK_UNINITIALIZED)
    {
        func_803168CC();
        for (i = 0; i < gNoteCount; i++)
        {
            if (gNotes[i].enabled && gNotes[i].adsr.state != ADSR_STATE_DISABLED)
            {
                gNotes[i].adsr.fadeOutVel = 0x8000 / gAudioUpdatesPerFrame;
                gNotes[i].adsr.action |= ADSR_ACTION_RELEASE;
            }
        }

        // Wait for all notes to stop playing
        frames = 0;
        for (;;)
        {
            wait_for_audio_frames(1);
            frames++;
            if (frames > 8 * 30)
            {
                // Break after 4 seconds
                break;
            }

            for (i = 0; i < gNoteCount; i++)
            {
                if (gNotes[i].enabled)
                    break;
            }

            if (i == gNoteCount)
            {
                // All zero, break early
                break;
            }
        }

        func_803168CC();
        wait_for_audio_frames(3);
        gAudioLoadLock = AUDIO_LOCK_LOADING;
        wait_for_audio_frames(3);

        s1 = gActiveAudioDmasCount;
        while (s1 > 0)
        {
            for (i = 0; i < gActiveAudioDmasCount; i++)
            {
                if (osRecvMesg(&D_80225EE8, NULL, OS_MESG_NOBLOCK) == 0)
                    s1--;
            }
        }
        gActiveAudioDmasCount = 0;

        for (j = 0; j < NUMAIBUFFERS; j++)
        {
            for (k = 0; k < 0x500; k++)
            {
                gAiBuffers[j][k] = 0;
            }
        }
    }

    D_80226B38 = 0;
    sp2C = arg0->size;
    gAiFrequency = osAiSetFrequency(arg0->frequency);
    gNoteCount = arg0->noteCount;
    size = gAiFrequency / 60;
    D_80226D74 = ALIGN16(size);
    D_802212A2 = arg0->unk5;

    switch (D_802212A2)
    {
    case 1:
        D_802212A3 = 0;
        break;
    case 2:
        D_802212A3 = 1;
        break;
    case 4:
        D_802212A3 = 2;
        break;
    case 8:
        D_802212A3 = 3;
        break;
    case 16:
        D_802212A3 = 4;
        break;
    default:
        D_802212A3 = 0;
    }

    D_802212A2 = arg0->unk5;
    D_802212A0 = arg0->unkA;
    gMinAiBufferLength = D_80226D74 - 0x10;
    temp8 = D_80226D74 / 160 + 1;
    gAudioUpdatesPerFrame = temp8;
    // Compute conversion ratio from the internal unit tatums/tick to the
    // external beats/minute (JP) or tatums/minute (US). In practice this is
    // 300 on JP and 14360 on US.
#ifdef VERSION_JP
    gTempoInternalToExternal = temp8 * 3600 / gTatumsPerBeat;
#else
    gTempoInternalToExternal = (u32) (temp8 * 2880000.0f / gTatumsPerBeat / 16.713f);
#endif
    D_80226D6C = gNoteCount * 20 * temp8 + 320;
    sum1 = arg0->unk10 + arg0->unkC;
    sum2 = arg0->unk18 + arg0->unk14;
    sum3 = sum1 + sum2;
    // (the address of D_802212A8.unk8 is lui'd too far up)
    sum4 = D_802212A8.size - sum3 - 0x100;
    D_80221898.unk0 = sum4;
    D_80221898.unkC = sum3;
    func_80316164(&D_80221898);
    D_802218A8.first = sum1;
    D_802218A8.second = sum2;
    func_803161E0(&D_802218A8);
    D_802218B0.unk0 = arg0->unkC;
    D_802218B0.unk4 = arg0->unk10;
    D_802218B0.unk8 = 0;
    func_8031625C(&D_802218B0);
    D_802218C0.unk0 = arg0->unk14;
    D_802218C0.unk4 = arg0->unk18;
    D_802218C0.unk8 = 0;
    func_80316318(&D_802218C0);
    func_80315E60();

    for (j = 0; j < 2; j++)
    {
        gAudioCmdBuffers[j] = soundAlloc(&D_802212C8, D_80226D6C * 8);
    }

    gNotes = soundAlloc(&D_802212C8,
            gNoteCount * sizeof(struct Note));
    note_init_all();
    func_80319248();

    if (sp2C == 0)
    {
        D_802211B0.unk1 = 0;
    }
    else
    {
        D_802211B0.unk1 = 8;
        D_802211B0.unk14.unk00 = soundAlloc(&D_802212C8, sp2C * 2);
        D_802211B0.unk14.unk04 = soundAlloc(&D_802212C8, sp2C * 2);
        D_802211B0.unk8 = 0;
        D_802211B0.unkC = 0;
        D_802211B0.unk3 = 0;
        D_802211B0.unk10 = sp2C;
        D_802211B0.unk4 = arg0->unk8;
        D_802211B0.unk2 = 2;
        if (D_802212A2 != 1)
        {
            D_802211B0.unk0 = 1;
            D_802211B0.unk6 = 0x8000 / D_802212A2;
            D_802211B0.unk1C = soundAlloc(&D_802212C8, 32);
            D_802211B0.unk20 = soundAlloc(&D_802212C8, 32);
            D_802211B0.unk24 = soundAlloc(&D_802212C8, 32);
            D_802211B0.unk28 = soundAlloc(&D_802212C8, 32);
            for (i = 0; i < gAudioUpdatesPerFrame; i++)
            {
                mem = soundAlloc(&D_802212C8, 0x280);
                D_802211B0.unk2C[0][i].unk4 = mem;
                D_802211B0.unk2C[0][i].unk8 = mem + 0xA0;
                mem = soundAlloc(&D_802212C8, 0x280);
                D_802211B0.unk2C[1][i].unk4 = mem;
                D_802211B0.unk2C[1][i].unk8 = mem + 0xA0;
            }
        }
    }

    func_8031758C(gNoteCount);
    osWritebackDCacheAll();
    if (gAudioLoadLock != AUDIO_LOCK_UNINITIALIZED)
    {
        gAudioLoadLock = AUDIO_LOCK_NOT_LOADING;
    }
}

#elif defined(VERSION_JP)
GLOBAL_ASM("asm/non_matchings/func_80316928_jp.s")
#else
GLOBAL_ASM("asm/non_matchings/func_80316928_us.s")
#endif
