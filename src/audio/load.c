#include <ultra64.h>
#include <macros.h>

#include "load.h"
#include "memory.h"
#include "data.h"
#include "seqplayer.h"
#include "external.h"

#define ALIGN16(val) (((val) + 0xF) & ~0xF)

/**
 * Performs an immediate DMA copy
 */
void audio_dma_copy_immediate(u32 devAddr, void *vAddr, u32 nbytes)
{
    osInvalDCache(vAddr, (s32)nbytes);
    osPiStartDma(&gAudioDmaIoMesg, OS_MESG_PRI_HIGH, OS_READ, devAddr, vAddr, nbytes, &gAudioDmaMesgQueue);
    osRecvMesg(&gAudioDmaMesgQueue, NULL, OS_MESG_BLOCK);
}

/**
 * Performs an asynchronus (normal priority) DMA copy
 */
void audio_dma_copy_async(u32 devAddr, void *vAddr, u32 nbytes, OSMesgQueue *queue, OSIoMesg *mesg)
{
    osInvalDCache(vAddr, (s32)nbytes);
    osPiStartDma(mesg, OS_MESG_PRI_NORMAL, OS_READ, devAddr, vAddr, nbytes, queue);
}

/**
 * Performs a partial asynchronous (normal priority) DMA copy. This is limited
 * to 0x1000 bytes transfer at once.
 */
void audio_dma_partial_copy_async(u32 *devAddr, u8 **vAddr, s32 *remaining, OSMesgQueue *queue, OSIoMesg *mesg)
{
    s32 transfer = (*remaining < 0x1000 ? *remaining : 0x1000);
    *remaining -= transfer;
    osInvalDCache(*vAddr, transfer);
    osPiStartDma(mesg, OS_MESG_PRI_NORMAL, OS_READ, *devAddr, *vAddr, transfer, queue);
    *devAddr += transfer;
    *vAddr += transfer;
}

void func_8031715C()
{
    u32 i;

    for (i = 0; i < D_80226B3C; i++)
    {
        struct Struct80226538 *temp = D_80226538 + i;
        if (temp->unkE != 0)
        {
            temp->unkE--;
            if (temp->unkE == 0)
            {
                temp->unkD = D_80226D4A;
                D_80226B48[D_80226D4A++] = (u8)i;
            }
        }
    }

    for (i = D_80226B3C; i < D_80226B38; i++)
    {
        struct Struct80226538 *temp = D_80226538 + i;
        if (temp->unkE != 0)
        {
            temp->unkE--;
            if (temp->unkE == 0)
            {
                temp->unkD = D_80226D4B;
                D_80226C48[D_80226D4B++] = (u8)i;
            }
        }
    }

    D_80226B40 = 0;
}

#ifdef NON_MATCHING

void *func_80317270(u8 *arg0, u32 arg1, s32 arg2, u8 *arg3)
{
    struct Struct80226538 *temp; // v1
    struct Struct80226538 *dma; // sp58, t0
    u32 transfer; // v0
    u32 devAddr; // s0
    u32 i; // a0
    u32 dmaIndex; // sp48, t2
    s32 hasDma = 0; // t4

    if (arg2 != 0 || *arg3 >= D_80226B3C)
    {
        for (i = D_80226B3C; i < D_80226B38; i++)
        {
            temp = D_80226538 + i;
            transfer = (u32) arg0 - temp->unk4;
            if ((s32)transfer >= 0 && temp->unkA - arg1 >= transfer)
            {
                if (temp->unkE == 0 && D_80226D4B != D_80226D49)
                {
                    if (temp->unkD != D_80226D49)
                    {
                        D_80226C48[temp->unkD] = D_80226C48[D_80226D49];
                        D_80226538[D_80226C48[D_80226D49]].unkD = temp->unkD;
                    }
                    D_80226D49++;
                }
                temp->unkE = 60;
                *arg3 = (u8)i;
                transfer = (u32) arg0 - temp->unk4;
                return temp->unk0 + transfer;
            }
            dma = temp;
        }

        if (D_80226D4B != D_80226D49 && arg2 != 0)
        {
            dmaIndex = D_80226C48[D_80226D49++];
            dma = &D_80226538[dmaIndex];
            hasDma = 1;
        }
    }
    else
    {
        dma = &D_80226538[*arg3];
        transfer = (u32) arg0 - dma->unk4;
        if ((s32)transfer >= 0 && dma->unkA - arg1 >= transfer)
        {
            if (dma->unkE == 0)
            {
                if (dma->unkD != D_80226D48)
                {
                    D_80226B48[dma->unkD] = D_80226B48[D_80226D48];
                    D_80226538[D_80226B48[D_80226D48]].unkD = dma->unkD;
                }
                D_80226D48++;
                transfer = (u32) arg0 - dma->unk4;
            }
            dma->unkE = 2;
            return dma->unk0 + transfer;
        }
    }

    if (!hasDma)
    {
        dmaIndex = D_80226B48[D_80226D48++];
        dma = &D_80226538[dmaIndex];
        hasDma = 1;
    }

    transfer = dma->unkA;
    devAddr = (u32) arg0 & ~0xF;
    dma->unkE = 2;
    dma->unk4 = devAddr;
    dma->unk8 = transfer;
#ifndef VERSION_JP
    osInvalDCache(dma->unk0, transfer);
#endif
    gActiveAudioDmasCount++;
    osPiStartDma(&gActiveAudioDmasMesgBuf[gActiveAudioDmasCount - 1], OS_MESG_PRI_NORMAL, OS_READ,
            devAddr, dma->unk0, transfer, &D_80225EE8);
    *arg3 = dmaIndex;
    return dma->unk0 + (u32) arg0 - devAddr;
}

#elif defined(VERSION_JP)
GLOBAL_ASM("asm/non_matchings/func_80317270_jp.s")
#else
GLOBAL_ASM("asm/non_matchings/func_80317270_us.s")
#endif

void func_8031758C(UNUSED s32 arg0)
{
    s32 i;
    s32 j;

    D_80226D68 = 0x510;
    for (i = 0; i < gNoteCount * 3; i++)
    {
        D_80226538[D_80226B38].unk0 = soundAlloc(&D_802212C8, D_80226D68);
        if (D_80226538[D_80226B38].unk0 == NULL)
        {
            goto out1;
        }
        D_80226538[D_80226B38].unk4 = 0;
        D_80226538[D_80226B38].unk8 = 0;
        D_80226538[D_80226B38].unkC = 0;
        D_80226538[D_80226B38].unkE = 0;
        D_80226538[D_80226B38].unkA = D_80226D68;
        D_80226B38++;
    }
out1:

    for (i = 0; (u32) i < D_80226B38; i++)
    {
        D_80226B48[i] = (u8) i;
        D_80226538[i].unkD = (u8) i;
    }

    for (j = D_80226B38; j < 0x100; j++)
    {
        D_80226B48[j] = 0;
    }

    D_80226D48 = 0;
    D_80226D4A = (u8) D_80226B38;
    D_80226B3C = D_80226B38;
    D_80226D68 = 0x5a0;

    for (i = 0; i < gNoteCount; i++)
    {
        D_80226538[D_80226B38].unk0 = soundAlloc(&D_802212C8, D_80226D68);
        if (D_80226538[D_80226B38].unk0 == NULL)
        {
            goto out2;
        }
        D_80226538[D_80226B38].unk4 = 0;
        D_80226538[D_80226B38].unk8 = 0;
        D_80226538[D_80226B38].unkC = 0;
        D_80226538[D_80226B38].unkE = 0;
        D_80226538[D_80226B38].unkA = D_80226D68;
        D_80226B38++;
    }
out2:

    for (i = D_80226B3C; (u32) i < D_80226B38; i++)
    {
        D_80226C48[i - D_80226B3C] = (u8) i;
        D_80226538[i].unkD = (u8) (i - D_80226B3C);
    }

    for (j = D_80226B38; j < 0x100; j++)
    {
        D_80226C48[j] = D_80226B3C;
    }

    D_80226D49 = 0;
    D_80226D4B = D_80226B38 - D_80226B3C;
}

#ifndef static
static void unused_80317844(void)
{
    // With -O2 -framepointer, this never-invoked static function gets *almost*
    // optimized out, regardless of contents, leaving only "jr $ra, nop".
    // If not declared as static, it unnecessarily moves the stack pointer up
    // and down by 8.
}
#else
// Keep supporting the good old "#define static" hack.
#undef static
static void unused_80317844(void) {}
#define static
#endif

#ifdef NON_MATCHING
void func_8031784C(struct AudioBank *mem, u8 *offset, u32 numInstruments, u32 numDrums)
{
    // Make pointers into real pointers rather than indices
    struct Instrument *instrument;
    struct Instrument **itInstrs;
    u32 i;
    u32 memBase = (u32)mem;
    u32 offsetBase = (u32)offset;

#define INIT_SOUND(sound) \
    { \
        struct AudioBankSample **itSample = &sound.sample; \
        if ((*itSample) != 0) \
        { \
            /* Making these volatile gives correct codegen further down; it makes
             * lw/addiu/sw's happen in source order, and uses two registers...
             * It looks odd, though, so maybe they should not be volatile.
             * It might also be causing the extra register use.
             * Presumably sample and sample2 ought to have different types,
             * but that doesn't matter for codegen. */ \
            volatile struct AudioBankSample *sample, *sample2; \
            *itSample = (void *)(memBase + (u32)(*itSample)); \
            sample = *itSample; \
            sample2 = *itSample; \
            if (sample2->loaded == FALSE) \
            { \
                void *a = sample2->sampleAddr; \
                void *b = sample->loop; \
                void *c = sample->book; \
                sample->sampleAddr = (void *) (offsetBase + (u32)a); \
                sample->loop = (void *) (memBase + (u32)b); \
                sample->book = (void *) (memBase + (u32)c); \
                sample->loaded = TRUE; \
            } \
        } \
    }

    if (mem->drums != NULL)
    {
        if (numDrums != 0)
        {
            mem->drums = (struct Drum **)(memBase + (u32)mem->drums);
            if (numDrums != 0)
            {
                for (i = 0; i < numDrums; i++)
                {
#if 0
                    // This doesn't work: Taking the address to mem->drums[i]
                    // does an sll to figure out the lower loop limit.
                    volatile struct Drum *drum, *drum2;
                    struct Drum **h = &mem->drums[i];
                    if (*h == 0) continue;
                    {
                        *h = (void *)(memBase + (u32)*h);
                        drum = *h;
                        drum2 = *h;
                        if (drum2->loaded == FALSE)
                        {
                            void *d;
                            INIT_SOUND(((struct Drum *)drum2)->sound);
                            d = drum2->envelope;
                            drum->loaded = TRUE;
                            drum->envelope = (void *) (memBase + (u32)d);
                        }
                    }
#else
                    // Neither does this: Using mem->drums[i] directly
                    // deduplicates it -- drum and drum2 end up in the same
                    // register.
                    struct Drum **drums = mem->drums;
                    u32 h = (u32)drums[i];
                    if (h != 0)
                    {
                        volatile struct Drum *drum, *drum2;
                        drums[i] = (struct Drum *)(memBase + h);
                        drum = drums[i];
                        drum2 = drums[i];
                        if (drum->loaded == FALSE)
                        {
                            void *d;
                            INIT_SOUND(((struct Drum *)drum)->sound);
                            d = drum->envelope;
                            drum2->loaded = TRUE;
                            drum2->envelope = (void *) (memBase + (u32)d);
                        }
                    }
#endif
                }
            }
        }
    }

    if ((numInstruments >= 1) && (numInstruments >= 1) != 0)
    {
        itInstrs = mem->instruments;
        do
        {
            if (*itInstrs)
            {
                *itInstrs = (void *)(memBase + (u32)*itInstrs);
                instrument = *itInstrs;

                if (instrument->loaded == FALSE)
                {
                    INIT_SOUND(instrument->lowNotesSound);
                    INIT_SOUND(instrument->normalNotesSound);
                    INIT_SOUND(instrument->highNotesSound);

                    instrument->loaded = TRUE;
                    instrument->envelope = (void *) (memBase + (u32)instrument->envelope);
                }
            }
            itInstrs++;
        }
        while (itInstrs != &mem->instruments[numInstruments]);
    }
#undef INIT_SOUND
}

#else
GLOBAL_ASM("asm/non_matchings/func_8031784C.s")
#endif

struct AudioBank *bank_load_immediate(s32 bankId, s32 arg1)
{
    UNUSED u32 pad1[4];
    u32 buf[4];
    u32 numInstruments, numDrums;
    struct AudioBank *ret;
    u8 *ctlData;
    s32 alloc;

    alloc = gAlCtlHeader->seqArray[bankId].len + 0xf;
    alloc = ALIGN16(alloc);
    alloc -= 0x10;
    ctlData = gAlCtlHeader->seqArray[bankId].offset;
    ret = alloc_bank_or_seq(&gSoundLoadedPool, 1, alloc, arg1, bankId);
    if (ret == NULL)
    {
        return NULL;
    }

    audio_dma_copy_immediate((u32)ctlData, buf, 0x10);
    numInstruments = buf[0];
    numDrums = buf[1];
    audio_dma_copy_immediate((u32)(ctlData + 0x10), ret, alloc);
    func_8031784C(ret, gAlTbl->seqArray[bankId].offset, numInstruments, numDrums);
    gCtlEntries[bankId].numInstruments = (u8)numInstruments;
    gCtlEntries[bankId].numDrums = (u8)numDrums;
    gCtlEntries[bankId].instruments = ret->instruments;
    gCtlEntries[bankId].drums = ret->drums;
    gBankLoadStatus[bankId] = SOUND_LOAD_STATUS_COMPLETE;
    return ret;
}

struct AudioBank *bank_load_async(s32 bankId, s32 arg1, struct SequencePlayer *seqPlayer)
{
    u32 numInstruments, numDrums;
    UNUSED u32 pad1[2];
    u32 buf[4];
    UNUSED u32 pad2;
    s32 alloc;
    struct AudioBank *ret;
    u8 *ctlData;
    OSMesgQueue *mesgQueue;

    alloc = gAlCtlHeader->seqArray[bankId].len + 0xf;
    alloc = ALIGN16(alloc);
    alloc -= 0x10;
    ctlData = gAlCtlHeader->seqArray[bankId].offset;
    ret = alloc_bank_or_seq(&gSoundLoadedPool, 1, alloc, arg1, bankId);
    if (ret == NULL)
    {
        return NULL;
    }

    audio_dma_copy_immediate((u32)ctlData, buf, 0x10);
    numInstruments = buf[0];
    numDrums = buf[1];
    seqPlayer->loadingBankId = (u8)bankId;
    seqPlayer->loadingBankNumInstruments = numInstruments;
    seqPlayer->loadingBankNumDrums = numDrums;
    seqPlayer->bankDmaCurrMemAddr = (u8 *) ret;
    seqPlayer->loadingBank = ret;
    seqPlayer->bankDmaCurrDevAddr = (u32)(ctlData + 0x10);
    seqPlayer->bankDmaRemaining = alloc;
    mesgQueue = &seqPlayer->bankDmaMesgQueue;
    osCreateMesgQueue(mesgQueue, &seqPlayer->bankDmaMesg, 1);
    seqPlayer->bankDmaMesg = NULL;
    seqPlayer->bankDmaInProgress = TRUE;
    audio_dma_partial_copy_async(&seqPlayer->bankDmaCurrDevAddr,
            &seqPlayer->bankDmaCurrMemAddr, &seqPlayer->bankDmaRemaining,
            mesgQueue, &seqPlayer->bankDmaIoMesg);
    gBankLoadStatus[bankId] = SOUND_LOAD_STATUS_IN_PROGRESS;
    return ret;
}

void *sequence_dma_immediate(s32 seqId, s32 arg1)
{
    s32 seqLength;
    void *ptr;
    u8 *seqData;

    seqLength = gSeqFileHeader->seqArray[seqId].len + 0xf;
    seqLength = ALIGN16(seqLength);
    seqData = gSeqFileHeader->seqArray[seqId].offset;
    ptr = alloc_bank_or_seq(&gSeqLoadedPool, 1, seqLength, arg1, seqId);
    if (ptr == NULL)
        return NULL;

    audio_dma_copy_immediate((u32)seqData, ptr, seqLength);
    gSeqLoadStatus[seqId] = SOUND_LOAD_STATUS_COMPLETE;
    return ptr;
}

void *sequence_dma_async(s32 seqId, s32 arg1, struct SequencePlayer *seqPlayer)
{
    s32 seqLength;
    void *ptr;
    u8 *seqData;
    OSMesgQueue *mesgQueue;

    seqLength = gSeqFileHeader->seqArray[seqId].len + 0xf;
    seqLength = ALIGN16(seqLength);
    seqData = gSeqFileHeader->seqArray[seqId].offset;
    ptr = alloc_bank_or_seq(&gSeqLoadedPool, 1, seqLength, arg1, seqId);
    if (ptr == NULL)
    {
        return NULL;
    }

    if (seqLength <= 0x40)
    {
        // Immediately load short sequenece
        audio_dma_copy_immediate((u32)seqData, ptr, seqLength);
        gSeqLoadStatus[seqId] = SOUND_LOAD_STATUS_COMPLETE;
    }
    else
    {
        audio_dma_copy_immediate((u32)seqData, ptr, 0x40);
        mesgQueue = &seqPlayer->seqDmaMesgQueue;
        osCreateMesgQueue(mesgQueue, &seqPlayer->seqDmaMesg, 1);
        seqPlayer->seqDmaMesg = NULL;
        seqPlayer->seqDmaInProgress = TRUE;
        audio_dma_copy_async((u32) (seqData + 0x40), (u8*)ptr + 0x40, seqLength - 0x40,
                mesgQueue, &seqPlayer->seqDmaIoMesg);
        gSeqLoadStatus[seqId] = SOUND_LOAD_STATUS_IN_PROGRESS;
    }
    return ptr;
}

u8 get_missing_bank(u32 seqId, s32 *nonNullCount, s32 *nullCount)
{
    void *temp;
    u32 bankId;
    u16 offset;
    u8 i;
    u8 ret;

    *nullCount = 0;
    *nonNullCount = 0;
    offset = ((u16 *)gAlBankSets)[seqId] + 1;
    for (i = gAlBankSets[offset - 1], ret = 0; i != 0; i--)
    {
        offset++;
        bankId = gAlBankSets[offset - 1];

        if (IS_BANK_LOAD_COMPLETE(bankId) == TRUE)
        {
            temp = get_bank_or_seq(&gSoundLoadedPool, 2, gAlBankSets[offset - 1]);
        }
        else
        {
            temp = NULL;
        }

        if (temp == NULL)
        {
            (*nullCount)++;
            ret = bankId;
        }
        else
        {
            (*nonNullCount)++;
        }
    }

    return ret;
}

struct AudioBank *load_banks_immediate(s32 seqId, u8 *arg1)
{
    void *ret;
    u32 bankId;
    u16 offset;
    u8 i;

    offset = ((u16 *)gAlBankSets)[seqId] + 1;
    for (i = gAlBankSets[offset - 1]; i != 0; i--)
    {
        offset++;
        bankId = gAlBankSets[offset - 1];

        if (IS_BANK_LOAD_COMPLETE(bankId) == TRUE)
        {
            ret = get_bank_or_seq(&gSoundLoadedPool, 2, gAlBankSets[offset - 1]);
        }
        else
        {
            ret = NULL;
        }

        if (ret == NULL)
        {
            ret = bank_load_immediate(bankId, 2);
        }
    }
    *arg1 = bankId;
    return ret;
}

void preload_sequence(u32 seqId, u8 preloadMask)
{
    void *sequenceData;
    u8 temp;

    if (seqId >= gSequenceCount)
    {
        return;
    }

    gAudioLoadLock = AUDIO_LOCK_LOADING;
    if (preloadMask & PRELOAD_BANKS)
    {
        load_banks_immediate(seqId, &temp);
    }

    if (preloadMask & PRELOAD_SEQUENCE)
    {
        // @bug should be IS_SEQ_LOAD_COMPLETE
        if (IS_BANK_LOAD_COMPLETE(seqId) == TRUE)
        {
            sequenceData = get_bank_or_seq(&gSeqLoadedPool, 2, seqId);
        }
        else
        {
            sequenceData = NULL;
        }

        if (sequenceData == NULL && sequence_dma_immediate(seqId, 2) == NULL)
        {
            gAudioLoadLock = AUDIO_LOCK_NOT_LOADING;
            return;
        }
    }

    gAudioLoadLock = AUDIO_LOCK_NOT_LOADING;
}

void load_sequence_internal(u32 player, u32 seqId, s32 loadAsync);

void load_sequence(u32 player, u32 seqId, s32 loadAsync)
{
    if (!loadAsync)
    {
        gAudioLoadLock = AUDIO_LOCK_LOADING;
    }
    load_sequence_internal(player, seqId, loadAsync);
    if (!loadAsync)
    {
        gAudioLoadLock = AUDIO_LOCK_NOT_LOADING;
    }
}

void load_sequence_internal(u32 player, u32 seqId, s32 loadAsync)
{
    void *sequenceData;
    struct SequencePlayer *seqPlayer = &gSequencePlayers[player];
    UNUSED u32 padding[2];

    if (seqId >= gSequenceCount)
    {
        return;
    }

    sequence_player_disable(seqPlayer);
    if (loadAsync)
    {
        s32 numMissingBanks = 0;
        s32 dummy = 0;
        s32 bankId = get_missing_bank(seqId, &dummy, &numMissingBanks);
        if (numMissingBanks == 1)
        {
            if (bank_load_async(bankId, 2, seqPlayer) == NULL)
            {
                return;
            }
            seqPlayer->anyBank[0] = bankId;
        }
        else if (load_banks_immediate(seqId, &seqPlayer->anyBank[0]) == NULL)
        {
            return;
        }
    }
    else if (load_banks_immediate(seqId, &seqPlayer->anyBank[0]) == NULL)
    {
        return;
    }

    seqPlayer->seqId = seqId;
    sequenceData = get_bank_or_seq(&gSeqLoadedPool, 2, seqId);
    if (sequenceData == NULL)
    {
        if (seqPlayer->seqDmaInProgress)
            return;

        if (loadAsync)
            sequenceData = sequence_dma_async(seqId, 2, seqPlayer);
        else
            sequenceData = sequence_dma_immediate(seqId, 2);

        if (sequenceData == NULL)
            return;
    }

    init_sequence_player(player);
    seqPlayer->scriptState.depth = 0;
    seqPlayer->delay = 0;
    seqPlayer->enabled = TRUE;
    seqPlayer->seqData = sequenceData;
    seqPlayer->scriptState.pc = sequenceData;
}

void audio_init()
{
    UNUSED s8 pad[32];
    u8 buf[0x10];
    s32 i, j, k;
    s32 lim1, lim2, lim3;
    u32 size;
    u64 *ptr64;
    void *data;
    UNUSED s32 pad2;

    gAudioLoadLock = AUDIO_LOCK_UNINITIALIZED;

    lim1 = D_80333EE8;
    for (i = 0; i < lim1; i++)
    {
        D_80226E58[i] = 0;
        D_80226E98[i] = 0;
    }

    lim2 = D_80333EEC;
    for (i = 0; i <= lim2 / 8 - 1; i++)
    {
        ((u64 *) gAudioHeap)[i] = 0;
    }

    i = 0;
    lim3 = ((u32) &D_80226EC0 - (u32) &D_802211A0) / 8;
    ptr64 = &D_802211A0 - 1;
    for (k = lim3; k >= 0; k--)
    {
        i++;
        ptr64[i] = 0;
    }

    for (i = 0; i < NUMAIBUFFERS; i++)
    {
        gAiBufferLengths[i] = 0x00a0;
    }

    gActiveAudioFrames = 0;
    gAudioTaskIndex = 0;
    gCurrAiBufferIndex = 0;
    gSoundMode = 0;
    gAudioTask = NULL;
    gAudioTasks[0].task.t.data_size = 0;
    gAudioTasks[1].task.t.data_size = 0;
    osCreateMesgQueue(&gAudioDmaMesgQueue, &gAudioDmaMesg, 1);
    osCreateMesgQueue(&D_80225EE8, D_80225F00, ARRAY_COUNT(D_80225F00));
    gActiveAudioDmasCount = 0;
    D_80226B38 = 0;

    func_80316108(D_80333EF0);

    for (i = 0; i < NUMAIBUFFERS; i++)
    {
        gAiBuffers[i] = soundAlloc(&gSoundPool, 0xa00);

        for (j = 0; j < 0x500; j++)
        {
            gAiBuffers[i][j] = 0;
        }
    }

    func_80316928(&D_80332190[0]);

    // Load header for sequence data (assets/music_data.sbk.s)
    gSeqFileHeader = (ALSeqFile*)buf;
    data = gMusicData;
    audio_dma_copy_immediate((u32)data, gSeqFileHeader, 0x10);
    gSequenceCount = gSeqFileHeader->seqCount;
    size = ALIGN16(gSequenceCount * sizeof(ALSeqData) + 4);
    gSeqFileHeader = soundAlloc(&gSoundPool, size);
    audio_dma_copy_immediate((u32)data, gSeqFileHeader, size);
    alSeqFileNew(gSeqFileHeader, data);

    // Load header for CTL (assets/sound_data.ctl.s, i.e. ADSR)
    gAlCtlHeader = (ALSeqFile*)buf;
    data = gSoundDataADSR;
    audio_dma_copy_immediate((u32)data, gAlCtlHeader, 0x10);
    size = gAlCtlHeader->seqCount * sizeof(ALSeqData) + 4;
    size = ALIGN16(size);
    gCtlEntries = soundAlloc(&gSoundPool, gAlCtlHeader->seqCount * sizeof(struct CtlEntry));
    gAlCtlHeader = soundAlloc(&gSoundPool, size);
    audio_dma_copy_immediate((u32)data, gAlCtlHeader, size);
    alSeqFileNew(gAlCtlHeader, data);

    // Load header for TBL (assets/sound_data.tbl.s, i.e. raw data)
    gAlTbl = (ALSeqFile*)buf;
    audio_dma_copy_immediate((u32)data, gAlTbl, 0x10);
    size = gAlTbl->seqCount * sizeof(ALSeqData) + 4;
    size = ALIGN16(size);
    gAlTbl = soundAlloc(&gSoundPool, size);
    audio_dma_copy_immediate((u32)gSoundDataRaw, gAlTbl, size);
    alSeqFileNew(gAlTbl, gSoundDataRaw);

    // Load bank sets for each sequence (assets/bank_sets.s)
    gAlBankSets = soundAlloc(&gSoundPool, 0x100);
    audio_dma_copy_immediate((u32)gBankSetsData, gAlBankSets, 0x100);

    func_8031D4B8();
    gAudioLoadLock = AUDIO_LOCK_NOT_LOADING;
}
