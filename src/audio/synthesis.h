#ifndef _AUDIO_SYNTHESIS_H
#define _AUDIO_SYNTHESIS_H

#include "internal.h"

#define MAX_UPDATES_PER_FRAME 4

struct struct_3920_sp1c
{
    s16 unk00;
    s16 unk02;
    s16 *unk4;
    s16 *unk8;
    s32 unkC;
    s16 unk10;
    s16 unk12;
}; // size = 0x14

struct Struct802211B0
{
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u16 unk4;
    u16 unk6;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    struct
    {
        s16 *unk00;
        s16 *unk04;
    } unk14;
    void *unk1C;
    void *unk20;
    void *unk24;
    void *unk28;
    struct struct_3920_sp1c unk2C[2][MAX_UPDATES_PER_FRAME];
}; // 0xCC <= size <= 0x100
extern struct Struct802211B0 D_802211B0;

u64 *func_80313CD4(u64 *cmdBuf, s32 *writtenCmds, u16 *aiBuf, s32 bufLen);
void note_init(struct Note *note);
void func_803159EC(struct Note *note, f32 velocity, f32 pan, u8 reverb);
void note_set_frequency(struct Note *note, f32 frequency);
void func_80315D94(struct Note *note);
void func_80315DE0(struct Note *note);

#endif /* _AUDIO_SYNTHESIS_H */
