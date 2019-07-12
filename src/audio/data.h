#ifndef _AUDIO_DATA_H
#define _AUDIO_DATA_H

#include "internal.h"

#define AUDIO_LOCK_UNINITIALIZED 0
#define AUDIO_LOCK_NOT_LOADING 0x76557364
#define AUDIO_LOCK_LOADING 0x19710515

extern struct Struct80332190 D_80332190[18];
extern u16 D_80332388[128]; // unused

extern f32 gPitchBendFrequencyScale[255];
extern f32 gNoteFrequencies[128];

extern u8 gDefaultShortNoteVelocityTable[16];
extern u8 gDefaultShortNoteDurationTable[16];
extern s8 gVibratoCurve[16];
extern struct AdsrEnvelope gDefaultEnvelope[3];

extern s16 *gWaveSamples[4];

extern u16 gPanQuantization[10];
extern f32 D_80332CE4[128];
extern f32 D_80332EE4[128];
extern f32 D_803330E4[128];

extern f32 D_803332E4[128];
extern f32 D_803334E4[128];
extern f32 D_803336E4[128];
extern f32 D_803338E4[128];
extern f32 D_80333AE4[128];
extern f32 D_80333CE4[128];

extern s16 gTatumsPerBeat;
extern s8 D_80333EE8;
extern s32 D_80333EEC;
extern s32 D_80333EF0;
extern volatile s32 gAudioLoadLock;

#endif /* _AUDIO_DATA_H */
