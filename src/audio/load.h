#ifndef _AUDIO_LOAD_H
#define _AUDIO_LOAD_H

#include "internal.h"

#define NUMAIBUFFERS 3
#define PRELOAD_BANKS 2
#define PRELOAD_SEQUENCE 1

struct Struct80226538
{
    u8 *unk0; // virtual address
    u32 unk4; // device address
    u16 unk8; // dma transfer size
    u16 unkA; // also dma transfer size?
    u8 unkC;
    u8 unkD; // index into D_80226C48
    u8 unkE; // counter, gets decremented
}; // size = 0x10

extern u64 D_802211A0; // audio .stack data start marker
extern OSMesgQueue D_80225EE8;
extern OSMesg D_80225F00[0x40];
extern OSIoMesg gActiveAudioDmasMesgBuf[0x40];
extern OSMesgQueue gAudioDmaMesgQueue;
extern OSMesg gAudioDmaMesg;
extern OSIoMesg gAudioDmaIoMesg;
extern struct Struct80226538 D_80226538[96];
extern u32 D_80226B3C;
extern u32 D_80226B40;
extern u8 D_80226B48[256];
extern u8 D_80226C48[256];
extern u8 D_80226D48;
extern u8 D_80226D49;
extern u8 D_80226D4A;
extern u8 D_80226D4B;
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
// volatile according to create_next_audio_frame_task, but not to audio_init.
// Maybe incorrectly extern'd in dma.c?
extern struct SPTask *gAudioTask;
extern struct SPTask gAudioTasks[2];
extern u16 *gAiBuffers[NUMAIBUFFERS];
extern s16 gAiBufferLengths[NUMAIBUFFERS];
extern u16 D_80226E52[];
extern u32 D_80226E58[];
extern u16 D_80226E98[];
extern u64 D_80226EC0; // audio .stack data end marker

extern s8 D_80333EE8;
extern s32 D_80333EF0; // amount of heap designated to gSoundPool, 0x2500

extern u8 gMusicData[]; // music_data.sbk
extern u8 gSoundDataADSR[]; // sound_data.ctl
extern u8 gSoundDataRaw[]; // sound_data.tbl
extern u8 gBankSetsData[]; // bank_sets.s

void audio_dma_partial_copy_async(u32 *devAddr, u8 **vAddr, s32 *remaining, OSMesgQueue *queue, OSIoMesg *mesg);
void func_8031715C(void);
void *func_80317270(u8 *arg0, u32 arg1, s32 arg2, u8 *arg3);
void func_8031758C(s32 arg0);
void func_8031784C(struct AudioBank *arg0, u8 *offset, u32 arg2, u32 arg3);
void preload_sequence(u32 seqId, u8 preloadMask);
void load_sequence(u32 player, u32 seqId, s32 loadAsync);

#endif /* _AUDIO_LOAD_H */
