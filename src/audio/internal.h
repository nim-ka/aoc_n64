#ifndef _AUDIO_INTERNAL_H
#define _AUDIO_INTERNAL_H

#include <ultra64.h>

#include "types.h"

#define SEQUENCE_PLAYERS 3
#define CHANNELS_MAX     16

#define NO_LAYER ((struct SequenceChannelLayer *)(-1))
#define IS_SEQUENCE_CHANNEL_VALID(ptr) ((u32)(ptr) != (u32)&gSequenceChannelNone)

#define MUTE_BEHAVIOR_80 0x80
#define MUTE_BEHAVIOR_40 0x40
#define MUTE_BEHAVIOR_20 0x20

#define SEQUENCE_PLAYER_STATE_0 0
#define SEQUENCE_PLAYER_STATE_FADE_OUT 1
#define SEQUENCE_PLAYER_STATE_2 2
#define SEQUENCE_PLAYER_STATE_3 3
#define SEQUENCE_PLAYER_STATE_4 4

#define TATUMS_PER_BEAT 48

#ifdef VERSION_JP
#define TEMPO_SCALE 1
#else
#define TEMPO_SCALE TATUMS_PER_BEAT
#endif

#ifdef VERSION_JP
#define US_FLOAT(x) x
#else
#define US_FLOAT(x) x ## f
#endif

// Convert u8 or u16 to f32. On JP, this uses a u32->f32 conversion,
// resulting in more bloated codegen, while on US it goes through s32.
// Since u8 and u16 fit losslessly in both, behavior is the same.
#ifdef VERSION_JP
#define FLOAT_CAST(x) (f32) (x)
#else
#define FLOAT_CAST(x) (f32) (s32) (x)
#endif

struct NoteListItem
{
    // A node in a circularly linked list. Each node is either a head or an item:
    // - Items can be either detached (prev = NULL), or attached to a list.
    //   'value' or 'value2' points to something of interest.
    // - List heads are always attached; if a list is empty, its head points
    //   to itself. 'count' contains the size of the list.
    // unkC records information related to the list itself; for the D_80225EA8
    // lists it points to that array of lists; for gLayerFreeList it is NULL.
    struct NoteListItem *prev;
    struct NoteListItem *next;
    union {
        struct Note *value; // TODO: void*
        struct SequenceChannelLayer *value2;
        s32 count;
    } u;
    struct NoteListItem *head;
}; // size = 0x10

struct VibratoState {
    struct SequenceChannel *seqChannel;
    u32 time;
    s8 *curve;
    u8 active;
    u16 rate;
    u16 extent;
    u16 rateChangeTimer;
    u16 extentChangeTimer;
    u16 delay;
}; // size = 0x18

// Pitch sliding by up to one octave in the positive direction. Negative
// direction is "supported" by setting extent to be negative. The code
// exterpolates exponentially in the wrong direction in that case, but that
// doesn't prevent seqplayer from doing it, AFAICT.
struct Portamento {
    u8 mode; // bit 0x80 denotes something; the rest are an index 0-5
    f32 cur;
    f32 speed;
    f32 extent;
}; // size = 0x10

struct AdsrEnvelope {
    s16 delay;
    s16 arg;
}; // size = 0x4

struct AudioBankSample
{
    u8 unused;
    u8 loaded;
    u8 *sampleAddr;
    ALADPCMloop *loop;
    ALADPCMBook *book;
    // u32 samplesize;
};

struct AudioBankSound
{
    struct AudioBankSample *sample;
    f32 tuning; // frequency scale factor
}; // size = 0x8

struct Instrument
{
    /*0x00*/ u8 loaded;
    /*0x01*/ u8 normalRangeLo;
    /*0x02*/ u8 normalRangeHi;
    /*0x03*/ u8 releaseRate;
    /*0x04*/ struct AdsrEnvelope *envelope;
    /*0x08*/ struct AudioBankSound lowNotesSound;
    /*0x10*/ struct AudioBankSound normalNotesSound;
    /*0x18*/ struct AudioBankSound highNotesSound;
}; // size = 0x20

struct Drum
{
    u8 releaseRate;
    u8 unk1;
    u8 loaded;
    struct AudioBankSound sound;
    struct AdsrEnvelope *envelope;
};

struct AudioBank
{
    struct Drum **drums;
    struct Instrument *instruments[1];
}; // dynamic size

struct CtlEntry
{
    u8 unused;
    u8 numInstruments;
    u8 numDrums;
    struct Instrument **instruments;
    struct Drum **drums;
}; // size = 0xC

struct M64ScriptState {
    u8 *pc;
    u8 *stack[4];
    u8 remLoopIters[4];
    u8 depth;
}; // size = 0x1C

struct SequencePlayer
{
    /*0x000*/ volatile u8 enabled : 1;
    /*0x000*/ u8 unk0b40 : 1;
    /*0x000*/ u8 muted : 1;
    /*0x000*/ u8 seqDmaInProgress : 1;
    /*0x000*/ u8 bankDmaInProgress : 1;
    /*0x001*/ s8 unk1;
    /*0x002*/ u8 state;
    /*0x003*/ u8 someMask;
    /*0x004*/ u8 muteBehavior;
    /*0x005*/ u8 seqId;
    /*0x006*/ u8 anyBank[1]; // must be an array to get a comparison
    // to match; other u8's might also be part of that array
    /*0x007*/ u8 loadingBankId;
    /*0x008*/ u8 loadingBankNumInstruments;
    /*0x009*/ u8 loadingBankNumDrums;
    /*0x00A*/ u16 tempo; // beats per minute in JP, tatums per minute in US
    /*0x00C*/ u16 tempoAcc;
    /*0x00E*/ u16 fadeTimer;
    /*0x010*/ s16 unk10;
    /*0x012*/ u16 delay;
    /*0x014*/ u8 *seqData; // buffer of some sort
    /*0x018*/ f32 fadeVolume; // set to 1.0f
    /*0x01C*/ f32 fadeVelocity; // set to 0.0f
    /*0x020*/ f32 volume; // set to 0.0f
    /*0x024*/ f32 muteVolumeScale; // set to 0.5f
    /*     */ u8 pad1[4];
    /*0x02C*/ struct SequenceChannel *channels[CHANNELS_MAX]; // TODO: or tracks?
    /*0x06C*/ struct M64ScriptState scriptState;
    /*0x088*/ u8 *shortNoteVelocityTable;
    /*0x08C*/ u8 *shortNoteDurationTable;
    /*0x090*/ struct NoteListItem unk90[4]; // heads
    /*0x0D0*/ OSMesgQueue seqDmaMesgQueue;
    /*0x0E8*/ OSMesg seqDmaMesg;
    /*0x0EC*/ OSIoMesg seqDmaIoMesg;
    /*0x100*/ OSMesgQueue bankDmaMesgQueue;
    /*0x118*/ OSMesg bankDmaMesg;
    /*0x11C*/ OSIoMesg bankDmaIoMesg;
    /*0x130*/ u8 *bankDmaCurrMemAddr;
    /*0x134*/ struct AudioBank *loadingBank;
    /*0x138*/ u32 bankDmaCurrDevAddr;
    /*0x13C*/ s32 bankDmaRemaining;
}; // size = 0x140

struct AdsrSettings
{
    u8 releaseRate;
    u16 sustain; // sustain level, 2^16 = max
    struct AdsrEnvelope *envelope;
}; // size = 0x8

struct SequenceChannel
{
    /*0x00*/ u8 enabled : 1;
    /*0x00*/ u8 disabledByChannel : 1;
    /*0x00*/ u8 stopScript : 1;
    /*0x00*/ u8 unk0b10 : 1;
    /*0x00*/ u8 hasInstrument : 1;
    /*0x00*/ u8 soundModeSomething : 1;
    /*0x00*/ u8 largeNotes : 1; // notes specify duration and velocity
    /*0x00*/ u8 unk0b1 : 1;
    /*0x01*/ u8 someMask;
    /*0x02*/ u8 muteBehavior;
    /*0x03*/ u8 reverb; // or dry/wet mix
    /*0x03*/ u8 unk4; // set to 3
    /*0x05*/ u8 bankId;
    /*0x06*/ u8 updatesPerFrameUnused; // never read
    /*0x08*/ u16 vibratoRateStart; // initially 0x800
    /*0x0A*/ u16 vibratoExtentStart;
    /*0x0C*/ u16 vibratoRateTarget; // initially 0x800
    /*0x0E*/ u16 vibratoExtentTarget;
    /*0x10*/ u16 vibratoRateChangeDelay;
    /*0x12*/ u16 vibratoExtentChangeDelay;
    /*0x14*/ u16 vibratoDelay;
    /*0x16*/ u16 delay;
    /*0x18*/ s16 instOrWave; // either 0 (none), instrument index + 1, or
    // 0x80..0x83 for sawtooth/triangle/sine/square waves.
    /*0x1A*/ s16 transposition;
    /*0x1C*/ f32 volumeScale;
    /*0x20*/ f32 volume;
    /*0x24*/ f32 pan;
    /*0x28*/ f32 panChannelWeight; // proportion of pan that comes from the channel (0..1)
    /*0x2C*/ f32 freqScale;
    /*0x30*/ u8 (*dynTable)[][2];
    /*0x34*/ struct Note *unk34;
    /*0x38*/ struct SequenceChannelLayer *unk38;
    /*0x3C*/ struct Instrument *instrument;
    /*0x40*/ struct SequencePlayer *seqPlayer;
    /*0x44*/ struct SequenceChannelLayer *layers[4];
    /*0x54*/ s8 soundScriptIO[8]; // bridge between sound script and audio lib. For player 2,
    // [0] contains enabled, [4] contains sound ID, [5] contains reverb adjustment
    /*0x5C*/ struct M64ScriptState scriptState;
    /*0x78*/ struct AdsrSettings adsr;
    /*0x80*/ struct NoteListItem unk80[4]; // heads
}; // size = 0xC0

struct SequenceChannelLayer // Maybe SequenceTrack?
{
    /*0x00*/ u8 enabled : 1;
    /*0x00*/ u8 finished : 1;
    /*0x00*/ u8 unk0b20 : 1;
    /*0x00*/ u8 unk0b10 : 1;
    /*0x01*/ u8 unk1;
    /*0x02*/ u8 noteDuration; // set to 0x80
    /*0x03*/ u8 unk3;
    /*0x04*/ struct Portamento portamento;
    /*0x14*/ struct AdsrSettings adsr;
    /*0x1C*/ u16 portamentoTime;
    /*0x1E*/ s16 transposition; // #semitones added to play commands
    // (m64 instruction encoding only allows referring to the limited range
    // 0..0x3f; this makes 0x40..0x7f accessible as well)
    /*0x20*/ f32 freqScale;
    /*0x24*/ f32 velocitySquare;
    /*0x28*/ f32 pan;
    /*0x2C*/ f32 noteVelocity;
    /*0x30*/ f32 notePan;
    /*0x34*/ f32 noteFreqScale;
    /*0x38*/ s16 shortNoteDefaultPlayPercentage;
    /*0x3A*/ s16 playPercentage; // it's not really a percentage...
    /*0x3C*/ s16 delay;
    /*0x3E*/ s16 duration;
    /*0x40*/ s16 delayUnused; // set to 'delay', never read
    /*0x44*/ struct Note *note;
    /*0x48*/ struct Instrument *instrument;
    /*0x4C*/ struct AudioBankSound *sound;
    /*0x50*/ struct SequenceChannel *seqChannel;
    /*0x54*/ struct M64ScriptState scriptState;
    /*0x70*/ struct NoteListItem noteItem;
}; // size = 0x80

struct SequenceChannelLayer_2
{
    s8 reverb;
    f32 freqScale;
    f32 velocity;
    f32 pan;
}; // size = 0x10

struct AdsrState {
    u8 action;
    u8 state;
    s16 initial; // always 0
    s16 target;
    s16 current;
    s16 envIndex;
    s16 delay;
    s16 sustain;
    s16 fadeOutVel;
    s32 velocity;
    s32 currentHiRes;
    s16 *volOut; // points to note->unk8
    struct AdsrEnvelope *envelope;
}; // size = 0x20

struct Note
{
    /*0x00*/ u8 enabled : 1;
    /*0x00*/ u8 unk0b40 : 1;
    /*0x00*/ u8 unk0b20 : 1;
    /*0x00*/ u8 unk0b10 : 1;
    /*0x00*/ u8 unk0b8 : 1;
    /*0x00*/ u8 unk0b4 : 1;
    /*0x00*/ u8 unk0b2 : 1;
    /*0x00*/ u8 soundModeSomething : 1;
    /*0x01*/ u8 unk1;
    /*0x02*/ u8 unk2;
    /*0x03*/ u8 unk3;
    /*0x04*/ u8 unk4;
    /*0x05*/ u8 sampleCount; // 0, 8, 16, 32 or 64
    /*0x06*/ u8 instOrWave;
    /*0x07*/ u8 bankId;
    /*0x08*/ s16 unk8;
    /*    */ u8 pad1[2];
    /*0x0C*/ u16 panRight;
    /*0x0E*/ u16 panLeft;
    /*0x10*/ u16 unk10;
    /*0x12*/ u16 unk12;
    /*0x14*/ s32 unk14;
    /*0x18*/ f32 portamentoFreqScale;
    /*0x1C*/ f32 vibratoFreqScale;
    /*0x20*/ u16 unk20;
    /*0x24*/ struct AudioBankSound *sound;
    /*0x28*/ struct SequenceChannelLayer *unk28;
    /*0x2C*/ struct SequenceChannelLayer *parentLayer; // ?
    /*0x30*/ struct SequenceChannelLayer *unk30;
    /*0x34*/ struct SubStruct_func_80318F04 *unk34; // or s16*
    /*0x38*/ f32 frequency;
    /*0x3C*/ u16 targetVolLeft;
    /*0x3E*/ u16 targetVolRight;
    /*0x40*/ u8 reverb;
    /*0x41*/ u8 unk41;
    /*0x44*/ struct SequenceChannelLayer_2 unk44;
    /*0x54*/ struct AdsrState adsr;
    /*0x74*/ struct Portamento portamento;
    /*0x84*/ struct VibratoState vibratoState;
    /*0x9C*/ s16 curVolLeft;
    /*0x9E*/ s16 curVolRight;
    /*0xA0*/ s16 reverbVol;
    /*0xA2*/ s16 unused; // never read, set to 0
    /*0xA4*/ struct NoteListItem noteListItem;
    /*    */ u8 pad2[0xc];
}; // size = 0xC0

//this is probably just an array with a bunch of indexes
struct SubStruct_func_80318F04
{
    s16 unk00[0x10];
    s16 unk20[0x10];
    s16 unk40[0x28];
    s16 unk90[0x10];
    s16 unkb0[0x10];
    s16 unkd0[0x10];
    s16 unkf0[0x10];
    s16 samples[0x40];
};

struct Struct80332190
{
    /*0x00*/ u32 frequency; // 32000, 27000
    /*0x04*/ u8 noteCount; // stored in gNoteCount, 16 (mostly), 20, 14, 12, 10, 8
    /*0x05*/ u8 unk5; // stored in D_802212A2, always 1
    /*0x06*/ u16 size; // sent as param to soundAlloc
    /*0x08*/ u16 unk8; // unknown, stored to D_802211B0.4
    /*0x0A*/ u16 unkA; // stored in D_802212A0
    /*0x0C*/ u32 unkC; // added with unk10
    /*0x10*/ u32 unk10;
    /*0x14*/ u32 unk14; // added with unk18
    /*0x18*/ u32 unk18;
}; // size = 0x1C

extern struct Note *gNotes; // points to an array

// Music in SM64 is played using 3 players:
// gSequencePlayers[0] is level background music
// gSequencePlayers[1] is misc music, like the puzzle jingle
// gSequencePlayers[2] is sound
extern struct SequencePlayer gSequencePlayers[SEQUENCE_PLAYERS];

extern struct SequenceChannel gSequenceChannels[32];

#ifdef VERSION_JP
extern struct SequenceChannelLayer D_802245D8[48];
#else
extern struct SequenceChannelLayer D_802245D8[52];
#endif

// Some sort of default, used when gSequenceChannels is full.
extern struct SequenceChannel gSequenceChannelNone;

// List of struct SequenceChannelLayer's
extern struct NoteListItem gLayerFreeList;      // head

// Lists of struct Note's
extern struct NoteListItem D_80225EA8[4];   // four heads

#endif /* _AUDIO_INTERNAL_H */