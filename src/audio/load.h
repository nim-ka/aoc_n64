#ifndef _AUDIO_LOAD_H
#define _AUDIO_LOAD_H

#include "internal.h"

#define NUMAIBUFFERS 3
#define PRELOAD_BANKS 2
#define PRELOAD_SEQUENCE 1

struct SharedDma
{
    /*0x0*/ u8 *buffer; // target, points to pre-allocated buffer
    /*0x4*/ u32 source; // device address
    /*0x8*/ u16 sizeUnused; // set to bufSize, never read
    /*0xA*/ u16 bufSize;
    /*0xC*/ u8 unused2; // set to 0, never read
    /*0xD*/ u8 reuseIndex; // position in sSampleDmaReuseQueue1/2, if ttl == 0
    /*0xE*/ u8 ttl; // duration after which the DMA can be discarded
}; // size = 0x10

extern u64 D_802211A0; // audio .stack data start marker
extern OSMesgQueue gCurrAudioFrameDmaQueue;
extern OSMesg gCurrAudioFrameDmaMesgBufs[0x40];
extern OSIoMesg gCurrAudioFrameDmaIoMesgBufs[0x40];
extern OSMesgQueue gAudioDmaMesgQueue;
extern OSMesg gAudioDmaMesg;
extern OSIoMesg gAudioDmaIoMesg;
extern struct SharedDma sSampleDmas[0x60];
extern u32 sSampleDmaListSize1;
extern u32 sUnused80226B40; // set to 0, never read

// Circular buffer of DMAs with ttl = 0. tail <= head, wrapping around mod 256.
extern u8 sSampleDmaReuseQueue1[256];
extern u8 sSampleDmaReuseQueue2[256];
extern u8 sSampleDmaReuseQueueTail1;
extern u8 sSampleDmaReuseQueueTail2;
extern u8 sSampleDmaReuseQueueHead1;
extern u8 sSampleDmaReuseQueueHead2;

extern ALSeqFile *gSeqFileHeader;
extern ALSeqFile *gAlCtlHeader;
extern ALSeqFile *gAlTbl;
extern u8 *gAlBankSets;
extern u16 gSequenceCount;
extern struct CtlEntry *gCtlEntries; // array of size gAlCtlHeader->seqCount
extern u32 D_80226D68;
extern volatile s32 gActiveAudioFrames;
extern s32 gAudioTaskIndex;
extern s32 gCurrAiBufferIndex;
extern struct SPTask *gAudioTask;
extern struct SPTask gAudioTasks[2];
extern u16 *gAiBuffers[NUMAIBUFFERS];
extern s16 gAiBufferLengths[NUMAIBUFFERS];
extern u16 D_80226E52[];
extern u32 sUnused80226E58[];
extern u16 sUnused80226E98[];
extern u64 D_80226EC0; // audio .stack data end marker

extern s8 gUnusedCount80333EE8;
extern s32 D_80333EF0; // amount of heap designated to gSoundPool, 0x2500

extern u8 gMusicData[]; // music_data.sbk
extern u8 gSoundDataADSR[]; // sound_data.ctl
extern u8 gSoundDataRaw[]; // sound_data.tbl
extern u8 gBankSetsData[]; // bank_sets.s

void audio_dma_partial_copy_async(u32 *devAddr, u8 **vAddr, s32 *remaining, OSMesgQueue *queue, OSIoMesg *mesg);
void decrease_sample_dma_ttls(void);
void *dma_sample_data(u8 *arg0, u32 arg1, s32 arg2, u8 *arg3);
void func_8031758C(s32 arg0);
void func_8031784C(struct AudioBank *arg0, u8 *offset, u32 arg2, u32 arg3);
void preload_sequence(u32 seqId, u8 preloadMask);
void load_sequence(u32 player, u32 seqId, s32 loadAsync);

#endif /* _AUDIO_LOAD_H */
