.include "macros.inc"

.section .stack

/* General stack BSS */

glabel gDecompressionHeap
    .space 0xD000
glabel gAudioHeap
    .space 0x31200
.ifdef VERSION_JP
glabel gAudioSPTaskYieldBuffer
    .space 0x400
.endif
/* Probably Thread 2 stack space. Unreferenced, and stubbed out with f3dex to
 * avoid an overflowing .stack segment. */
.ifndef F3DEX_GBI_SHARED
    .space 0x1400
.endif
glabel gIdleThreadStack
    .space 0x800
glabel gThread3Stack
    .space 0x2000
glabel gThread4Stack
    .space 0x2000
glabel gThread5Stack
    .space 0x2000
glabel gGfxSPTaskYieldBuffer
    .ifndef F3DEX_GBI_SHARED
        .space 0x900
    .else
        .space 0xC00
    .endif
glabel gSaveBuffer
    .space 0x200
glabel gGfxSPTaskStack
    .space 0x400
glabel gGfxPools /* 0xc850 * 2 */
    .space 0x190a0

/* Audio stack .bss */

glabel D_802211A0
    .space 0x10
glabel D_802211B0
    .space 0xF0
glabel D_802212A0
    .space 0x2
glabel D_802212A2
    .space 0x1
glabel D_802212A3
    .space 0x5
glabel D_802212A8
    .space 0x10
glabel gSoundPool
    .space 0x10
glabel D_802212C8
    .space 0x30
glabel D_802212F8
    .space 0x10
glabel D_80221308
    .space 0x10
glabel D_80221318
    .space 0x10
glabel gSeqLoadedPool
    .space 0x1D0
glabel gBankLoadedPool
    .space 0x1D0
glabel gUnusedLoadedPool
    .space 0x1D0
glabel D_80221898
    .space 0x10
glabel D_802218A8
    .space 0x8
glabel D_802218B0
    .space 0x10
glabel D_802218C0
    .space 0x10
glabel gBankLoadStatus
    .space 0x40
glabel gSeqLoadStatus
    .space 0x100
glabel D_80221A10 /* Unused? */
    .space 0x1000
glabel gNotes
    .space 0x8
glabel gSequencePlayers /* size 0x140 * 3 */
    .space 0x3C0
glabel gSequenceChannels /* 0xC0 * 32 */
    .space 0x1800
glabel D_802245D8 /* 0x80 * 48 or 52 (US) */
    .space 0x1800
.ifndef VERSION_JP
    .space 0x200
.endif
glabel gSequenceChannelNone
    .space 0xC0
glabel gLayerFreeList
    .space 0x10
glabel gNoteFreeLists
    .space 0x40
glabel gCurrAudioFrameDmaQueue
    .space 0x18
glabel gCurrAudioFrameDmaMesgBufs
    .space 0x100
glabel gCurrAudioFrameDmaIoMesgBufs
    .space 0x500
glabel gAudioDmaMesgQueue
    .space 0x18
glabel gAudioDmaMesg
    .space 0x8
glabel gAudioDmaIoMesg
    .space 0x18
glabel sSampleDmas
    .space 0x600
glabel sSampleDmaNumListItems
    .space 0x4
glabel sSampleDmaListSize1
    .space 0x4
glabel sUnused80226B40
    .space 0x8
glabel sSampleDmaReuseQueue1
    .space 0x100
glabel sSampleDmaReuseQueue2
    .space 0x100
glabel sSampleDmaReuseQueueTail1
    .space 0x1
glabel sSampleDmaReuseQueueTail2
    .space 0x1
glabel sSampleDmaReuseQueueHead1
    .space 0x1
glabel sSampleDmaReuseQueueHead2
    .space 0x1
glabel gSeqFileHeader
    .space 0x4
glabel gAlCtlHeader
    .space 0x4
glabel gAlTbl
    .space 0x4
glabel gAlBankSets
    .space 0x4
glabel gSequenceCount
    .space 0x4
glabel gCtlEntries
    .space 0x4
glabel gAiFrequency
    .space 0x4
glabel D_80226D68
    .space 0x4
glabel D_80226D6C
    .space 0x4
glabel gMaxSimultaneousNotes
    .space 0x4
glabel D_80226D74
    .space 0x4
glabel gMinAiBufferLength
    .space 0x4
glabel gTempoInternalToExternal
    .space 0x2
glabel gAudioUpdatesPerFrame
    .space 0x1
glabel gSoundMode
    .space 0x1
glabel gActiveAudioFrames
    .space 0x4
glabel gCurrAudioFrameDmaCount
    .space 0x4
glabel gAudioTaskIndex
    .space 0x4
glabel gCurrAiBufferIndex
    .space 0x4
glabel gAudioCmdBuffers
    .space 0x8
glabel gAudioCmd
    .space 0x4
glabel gAudioTask
    .space 0x4
glabel gAudioTasks
    .space 0xA0
glabel gAiBuffers
    .space 0xC
glabel gAiBufferLengths
    .space 0x6
glabel D_80226E52
    .space 0x6
glabel sUnused80226E58
    .space 0x40
glabel sUnused80226E98
    .space 0x20
glabel D_80226EB8
    .space 0x8
glabel D_80226EC0
    .space 0x8

# There's a bunch of unused space here due to the align (~0x100 in JP, ~0x300 in US)
.balign 0x1000
glabel gGfxSPTaskOutputBuffer /* FIFO buffer */
    .space 0x1F000
