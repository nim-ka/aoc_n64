#ifndef _AUDIO_DMA_H
#define _AUDIO_DMA_H

#include "types.h"

struct Unk16
{
    u8 pad1[13];
    u8 unkD;
    u8 unkE;
    u8 pad2;
};

struct Struct_func_80317BE4
{
    /*0x000*/ u8 pad0 : 4;
    /*0x000*/ u8 unk0b8 : 1;
    /*0x001*/ u8 pad[6];
    /*0x007*/ u8 unk7;
    /*0x008*/ u8 unk8;
    /*0x009*/ u8 unk9;
    /*0x00A*/ u8 pad2[0x0f6];
    /*0x100*/ OSMesgQueue mesgQueue;
    /*0x118*/ OSMesg mesg;
    /*0x11C*/ OSIoMesg ioMesg;
    /*0x134*/ void *mem;
    /*0x138*/ u32 devAddr;
    /*0x13C*/ s32 size;
};

struct Struct_80226D60
{
    u8 unk0;
    u8 unk1;
    u8 unk2;
    void *unk4;
    u32 unk8;
};

struct SubEntry
{
    u8 unk0;
    u8 unk1;
    void *unk4; // points into offset
    void *unk8; // points into mem
    void *unkC; // points into mem
};
struct SubA
{
    u16 pad;
    u8 unk2;
    struct SubEntry *unk4;
    u8 pad2[4];
    void *unkC; // points into mem
};
struct SubB
{
    u8 unk0;
    void *unk4;
    struct SubEntry *unk8;
    u32 pad2;
    struct SubEntry *unk10;
    u32 pad3;
    struct SubEntry *unk18;
};
struct Struct_func_8031784C
{
    struct SubA **header;
    struct SubB *subB[1];
};

struct Struct80332190
{
    u8 pad0[0x1C];
}; // size = 0x1C

// extern ? D_80221198;
extern u64 D_802211A0[];
extern OSMesgQueue D_80225EE8;
extern OSMesg D_80225F00[0x40];
// extern ? D_80226000;
extern OSMesgQueue D_80226500;
extern OSMesg D_80226518[1];
extern OSIoMesg D_80226520;
extern struct Unk16 D_80226538[96];
extern u32 D_80226B3C;
extern u32 D_80226B40;
extern u8 D_80226B48[256];
extern u8 D_80226C48[256];
// extern u8 D_80226D48;
// extern u8 D_80226D49;
extern u8 D_80226D4A;
extern u8 D_80226D4B;
extern ALSeqFile *D_80226D4C;
extern ALSeqFile *D_80226D50;
extern ALSeqFile *D_80226D54;
extern u8 *D_80226D58;
extern u16 D_80226D5C;
extern struct Struct_80226D60 *D_80226D60;
// extern ? D_80226D68;
extern volatile s32 D_80226D80;
extern s32 D_80226D88;
extern s32 D_80226D8C;
extern struct SPTask *volatile D_80226D9C;
extern struct SPTask D_80226DA0[2];
extern u16 *D_80226E40[3];
extern s16 D_80226E4C[3];
extern u16 D_80226E52[];
extern u32 D_80226E58[];
extern u16 D_80226E98[];
extern u64 D_80226EC0[]; // unknown type, some sort of end marker
extern struct Struct80332190 D_80332190[]; // unknown type, [27]?
extern s8 D_80333EE8;
extern s32 D_80333EF0;
extern volatile s32 D_80333EF4;
// extern ? D_00745F80;
// extern ? D_00579140;
// extern ? D_00590200;

extern u8 gMusicData[];
extern u8 gSoundDataADSR[];
extern u8 gSoundDataRaw[];
extern u8 gInstrumentSets[];

void BlockDmaCopy(u32 devAddr, void *vAddr, u32 nbytes);
void func_80317034(u32 devAddr, void *vAddr, u32 nbytes, OSMesgQueue *queue, OSIoMesg *mesg);
void func_803170A0(u32 *devAddr, u8 **vAddr, s32 *size, OSMesgQueue *queue, OSIoMesg *mesg);
void func_8031715C(void);
// extern ? func_80317270(?);
// extern ? func_8031758C(?);
void func_8031784C(struct Struct_func_8031784C *arg0, u8 *offset, u32 arg2, u32 arg3);

void *func_80317A88(s32 arg0, s32 arg1);
void *func_80317BE4(s32 arg0, s32 arg1, struct Struct_func_80317BE4 *arg2);
void *func_80317D1C(s32 arg0, s32 arg1);
// extern ? func_80317DC8(?);
u8 func_80317F04(s32 arg0, s32 *arg1, s32 *arg2);
void *func_8031804C(s32 arg0, u8 *arg1);
void func_80318178(u32 arg0, u8 arg1);
void func_80318280(u32 arg0, s32 arg1, s32 arg2);
extern void func_803182E0(u32 arg0, s32 arg1, s32 arg2);
extern void InitAudioSystem(void);

#endif /* _AUDIO_DMA_H */
