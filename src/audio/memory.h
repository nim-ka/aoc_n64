#ifndef _AUDIO_MEMORY_H
#define _AUDIO_MEMORY_H

#include "internal.h"

#define SOUND_LOAD_STATUS_NOT_LOADED     0
#define SOUND_LOAD_STATUS_IN_PROGRESS    1
#define SOUND_LOAD_STATUS_COMPLETE       2
#define SOUND_LOAD_STATUS_DISCARDABLE    3

#define IS_BANK_LOAD_COMPLETE(bankId) (gBankLoadStatus[bankId] >= SOUND_LOAD_STATUS_COMPLETE)
#define IS_SEQ_LOAD_COMPLETE(seqId) (gSeqLoadStatus[seqId] >= SOUND_LOAD_STATUS_COMPLETE)

struct SoundAllocPool
{
    u8 *start;
    u8 *cur;
    u32 size;
    s32 unkC; // (never read, always zero)
}; // size = 0x10

struct MultiPoolSub {
    u8 *ptr;
    u32 size; // (never read)
    s32 id; // seqId or bankId
}; // size = 0xC

struct SoundPoolHolder
{
    u32 unk0;
    struct SoundAllocPool pool;
}; // size = 0x14

struct SoundPoolHolder2
{
    /*0x00*/ u32 side;
    /*0x04*/ struct SoundAllocPool pool;
    /*0x14*/ struct MultiPoolSub arr[2];
    /*0x2C*/ u32 pad2[4];
}; // size = 0x3C

struct SoundMultiPool
{
    /*0x000*/ struct SoundPoolHolder first;
    /*0x014*/ struct MultiPoolSub arr[32];
    /*0x194*/ struct SoundPoolHolder2 second;
}; // size = 0x1D0

extern u8 gAudioHeap[];
extern s16 D_802212A0;
extern s8 D_802212A2;
extern u8 D_802212A3;
extern struct SoundAllocPool gSoundPool;
extern struct SoundAllocPool D_802212C8;
extern struct SoundMultiPool gSeqLoadedPool;
extern struct SoundMultiPool gSoundLoadedPool;
extern u8 gBankLoadStatus[64];
extern u8 gSeqLoadStatus[256];
extern u32 D_80226B38;
extern s32 gAiFrequency;
extern s32 gNoteCount;
extern s32 D_80226D74;
extern s32 gMinAiBufferLength;
extern s16 gTempoInternalToExternal;
extern s8 gAudioUpdatesPerFrame; // = 4
extern s8 gSoundMode;
extern volatile s32 gActiveAudioDmasCount; // counter of some sort
extern u64 *gAudioCmdBuffers[2];
extern u64 *gAudioCmd; // audio ucode data
extern s32 D_80333EEC; // size of audio heap

extern void *soundAlloc(struct SoundAllocPool *pool, u32 size);
extern void func_80316108(s32 arg0);
extern void *alloc_bank_or_seq(struct SoundMultiPool *arg0, s32 arg1, s32 size, s32 arg3, s32 id);
extern void *get_bank_or_seq(struct SoundMultiPool *arg0, s32 arg1, s32 arg2);
extern void func_80316928(struct Struct80332190 *arg0);

#endif /* _AUDIO_MEMORY_H */
