#ifndef _AUDIO_PLAYBACK_H
#define _AUDIO_PLAYBACK_H

#include "types.h"

#define MINUS_ONE ((struct SubStruct_func_80318870 *)(-1))
#define INSTRUMENT_SENTINEL ((struct InstrumentSomething *)(1))

struct PlaybackListItem
{
    // A node in a circularly linked list. Each node is either a head or an item:
    // - Items can be either detached (prev = NULL), or attached to a list.
    //   'value' or 'value2' points to something of interest.
    // - List heads are always attached; if a list is empty, its head points
    //   to itself. 'count' contains the size of the list.
    // unkC records information related to the list itself; for the D_80225EA8
    // lists it points to that array of lists; for D_80225E98 it is NULL.
    struct PlaybackListItem *prev;
    struct PlaybackListItem *next;
    union {
        struct Struct_func_80318870 *value; // TODO: void*
        struct SubStruct_func_80318870 *value2;
        s32 count;
    } u;
    struct PlaybackListItem *unkC;
};

// Mainly used in interface_2, but declared here to reduce header dependencies
// (This file has become sort of a dumping group for structs. Which is pretty
// convenient, but really we should have a separate header for that.)
struct Struct80222A18
{
    /*0x000*/ volatile u8 unk0b80 : 1;
    /*0x000*/ u8 unk0b40 : 1;
    /*0x000*/ u8 unk0b20 : 1;
    /*0x000*/ u8 unk0b10 : 1;
    /*0x000*/ u8 unk0b8 : 1;
    /*0x001*/ u8 unk1; // s8 according to func_8031D4B8, set to -1
    /*0x002*/ u8 unk2;
    /*0x003*/ u8 unk3;
    /*0x004*/ u8 unk4; // set to 0xe0
    /*0x005*/ u8 unk5; // index into D_80221910
    /*0x006*/ u8 unk6[1]; // index into D_802218D0 (must be an array to get a
    // comparison to match; other u8's might also be part of that array)
    /*0x007*/ u8 unk7;
    /*0x008*/ u8 unk8;
    /*0x009*/ u8 unk9;
    /*0x00A*/ u16 unkA; // set to 0x78 on JP, 0x1680 on US
    /*0x00C*/ u16 unkC;
    /*0x00E*/ u16 unkE;
    /*0x010*/ u16 unk10;
    /*0x012*/ u16 unk12;
    /*0x014*/ void *unk14;
    /*0x018*/ f32 unk18; // set to 1.0f
    /*0x01C*/ f32 unk1C; // set to 0.0f
    /*0x020*/ f32 unk20; // set to 0.0f
    /*0x024*/ f32 unk24; // set to 0.5f
    /*     */ u8 pad3[4];
    /*0x02C*/ struct Struct80225DD8 *unk2C[16];
    /*0x06C*/ void *unk6C;
    /*     */ u8 pad4[0x14];
    /*0x084*/ u8 unk84;
    /*0x088*/ u8 *unk88; // set to &D_80332A84, some sort of curve
    /*0x08C*/ u8 *unk8C; // set to &D_80332A94, some sort of curve
    /*0x090*/ struct PlaybackListItem unk90[4]; // heads
    /*0x0D0*/ OSMesgQueue mesgQueue1;
    /*0x0E8*/ OSMesg mesg1;
    /*0x0EC*/ OSIoMesg ioMesg1;
    /*0x100*/ OSMesgQueue mesgQueue2;
    /*0x118*/ OSMesg mesg2;
    /*0x11C*/ OSIoMesg ioMesg2;
    /*0x130*/ u8 *currentMemAddr;
    /*0x134*/ void *mem;
    /*0x138*/ u32 currentDevAddr;
    /*0x13C*/ s32 size;
}; // size = 0x140

struct Substruct80225DD8
{
    u8 unk0; // set to 0x20
    u16 unk2;
    u16 *unk4; // set to &D_80332AB4, might be a struct*
};

struct InstrumentSomething
{
    u8 pad[3];
    u8 unk3;
    u16 *unk4;
};

struct Struct80225DD8
{
    /*0x00*/ u8 unk0b80 : 1;
    /*0x00*/ u8 unk0b40 : 1;
    /*0x00*/ u8 unk0b20 : 1;
    /*0x00*/ u8 unk0b10 : 1;
    /*0x00*/ u8 unk0b8 : 1;
    /*0x00*/ u8 unk0b4 : 1;
    /*0x00*/ u8 unk0b2 : 1;
    /*0x00*/ u8 unk0b1 : 1;
    /*0x01*/ u8 unk1; // set to Struct80222A18.unk3
    /*0x02*/ u8 unk2; // set to Struct80222A18.unk4
    /*0x03*/ u8 unk3;
    /*0x03*/ u8 unk4; // set to 3
    /*0x05*/ u8 unk5; // set to Struct80222A18.unk6
    /*0x06*/ u8 unk6;
    /*0x08*/ s16 unk8; // set to 0x800
    /*0x0A*/ s16 unkA;
    /*0x0C*/ s16 unkC; // set to 0x800
    /*0x0E*/ s16 unkE;
    /*0x10*/ s16 unk10;
    /*0x12*/ s16 unk12;
    /*0x14*/ s16 unk14;
    /*0x16*/ s16 unk16;
    /*0x18*/ s16 unk18; // this - 0x80 defines which wave to use (0,1,2,3) (sawtooth, triangle, sine, square), set by SetInstrument. Sometimes 0 or return value of func_8031BEB0
    /*0x1A*/ s16 unk1A;
    /*0x1C*/ f32 unk1C;
    /*0x20*/ f32 unk20;
    /*0x24*/ f32 unk24;
    /*0x28*/ f32 unk28;
    /*0x2C*/ f32 unk2C;
    /*    */ u8 pad4[4];
    /*0x34*/ struct Struct_func_80318870 *unk34;
    /*0x38*/ struct SubStruct_func_80318870 *unk38;
    /*0x3C*/ struct InstrumentSomething *unk3C;
    /*0x40*/ struct Struct80222A18 *unk40;
    /*0x44*/ struct SubStruct_func_80318870 *unk44[4];
    /*0x54*/ u8 unk54[8]; // func_8031A810 claims s8 (sets values to -1), func_8031ED70 u8
    /*0x5C*/ void *unk5C; // unknown type, same as Struct80222A18.unk14
    /*    */ u8 pad8[0x74 - 0x60];
    /*0x74*/ u8 unk74;
    /*0x78*/ struct Substruct80225DD8 unk78;
    /*0x80*/ struct PlaybackListItem unk80[4]; // heads
}; // size = 0xC0

struct SubStruct_func_80318870
{
    u8 unk0b80 : 1;
    u8 unk0b40 : 1;
    u8 unk0b20 : 1;
    u8 unk0b10 : 1;
    u8 unk1;
    u8 unk2; // set to 0x80
    u8 pad1[1];
    u8 unk4;
    u8 pad2[2];
    u8 unk7;
    u8 pad3[0xC];
    struct Substruct80225DD8 unk14;
    u8 pad4[2];
    u16 unk1E;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    u8 pad5[4];
    u16 unk3C;
    u16 unk3E;
    u16 unk40;
    struct Struct_func_80318870 *unk44;
    void *unk48;
    struct SubStruct_func_80318870_3 *unk4C; // unknown type
    struct Struct80225DD8 *unk50;
    u8 pad6[0x18];
    u8 unk6C;
    struct PlaybackListItem unk70;
}; // size = 0x80

struct SubStruct_func_80318870_2
{
    s8 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

struct SubsubsubStruct_func_80318870_3
{
    s32 unk0;
    s32 unk4;
    s32 unk8; // compared against 0
};

struct SubsubStruct_func_80318870_3
{
    u32 pad0;
    u32 unk4;
    struct SubsubsubStruct_func_80318870_3 *unk8;
};

struct SubStruct_func_80318870_3
{
    struct SubsubStruct_func_80318870_3 *unk0;
    u32 pad1;
    s16 *unk8; // unknown type
    u32 *unkC; //probably struct*?
    //starts with 2 u32 and then a pointer (probably s16, since most of the audio stuff is s16)
};

struct Struct_func_80318870
{
    u8 unk0b80 : 1;
    u8 unk0b40 : 1;
    u8 unk0b20 : 1;
    u8 unk0b10 : 1;
    u8 unk0b8 : 1;
    u8 unk0b4 : 1;
    u8 unk0b2 : 1;
    u8 unk0b1 : 1;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5; // 0, 8, 16, 32 or 64
    u8 unk6;
    u8 unk7;
    s16 unk8;
    u8 pad1[0x2];
    u16 unkC;
    u16 unkE;
    u16 unk10;
    u16 unk12;
    s32 unk14;
    f32 unk18;
    f32 unk1C;
    u16 unk20;
    struct SubStruct_func_80318870_3 *unk24; // unknown type, pointer
    struct SubStruct_func_80318870 *unk28;
    struct SubStruct_func_80318870 *unk2C;
    struct SubStruct_func_80318870 *unk30;
    struct SubStruct_func_80318F04 *unk34; // or s16*
    f32 unk38;
    u16 unk3C;
    u16 unk3E;
    u8 unk40;
    u8 unk41;
    struct SubStruct_func_80318870_2 unk44;
    // struct {
    u8 unk54;
    u8 unk55;
    u8 pad3[0x4];
    s16 unk5A;
    u8 pad4[0x4];
    s16 unk60;
    s16 unk62;
    u8 pad5[0xc];
    // }; ?
    struct PlaybackListItem *unk70;
    u8 pad6[4];
    f32 unk78;
    f32 unk7C;
    u8 pad7[0x10];
    u8 unk90;
    u8 pad8[0xb];
    s16 unk9C;
    s16 unk9E;
    s16 unkA0;
    s16 unkA2;
    struct PlaybackListItem unkA4; // item, not head
    u8 pad10[0x0c];
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
    s16 unk110[0x40];
};

extern struct Struct_func_80318870 *D_80222A10; // points to an array

extern struct Struct80222A18 D_80222A18[3];

extern struct Struct80225DD8 D_80222DD8[32];

// not certain about type, but size and part of layout matches
#ifdef VERSION_JP
extern struct SubStruct_func_80318870 D_802245D8[48];
#else
extern struct SubStruct_func_80318870 D_802245D8[52];
#endif

// Some sort of default, used when D_80222DD8 is full.
extern struct Struct80225DD8 D_80225DD8;

// List of struct SubStruct_func_80318870's
extern struct PlaybackListItem D_80225E98;      // head

// Lists of struct Struct_func_80318870's
extern struct PlaybackListItem D_80225EA8[4];   // four heads

void func_80318870(struct Struct_func_80318870 *arg0);
void func_803188E8(struct Struct_func_80318870 *arg0);
void func_80318908(void);
void func_80318D18(struct SubStruct_func_80318870 *arg0, s32 arg1);
void func_80318EC4(struct SubStruct_func_80318870 *arg0);
void func_80318EE4(struct SubStruct_func_80318870 *arg0);
void func_80318F04(struct Struct_func_80318870 *arg0, struct SubStruct_func_80318870 *arg1);
void func_80319164(struct Struct_func_80318870 *arg0, struct SubStruct_func_80318870 *arg1);
void func_803191E8(struct PlaybackListItem *head);
void func_803191F8(struct PlaybackListItem *headList);
void func_80319248(void);
void func_803192FC(struct PlaybackListItem *headList);
void func_80319428(struct PlaybackListItem *headList, s32 count);
void func_80319564(struct PlaybackListItem *head, struct PlaybackListItem *item);
void func_803195A4(struct PlaybackListItem *item);
struct Struct_func_80318870 *func_803195D0(struct PlaybackListItem *head, s32 arg1);
s32 func_80319660(struct Struct_func_80318870 *arg0, struct SubStruct_func_80318870 *arg1);
void func_80319728(struct Struct_func_80318870 *arg0, struct SubStruct_func_80318870 *arg1);
void func_8031975C(struct Struct_func_80318870 *arg0, struct SubStruct_func_80318870 *arg1);
struct Struct_func_80318870 *func_803197B4(struct PlaybackListItem *headList, struct SubStruct_func_80318870 *arg1);
struct Struct_func_80318870 *func_80319830(struct PlaybackListItem *headList, struct SubStruct_func_80318870 *arg1);
struct Struct_func_80318870 *func_80319884(struct PlaybackListItem *headList, struct SubStruct_func_80318870 *arg1);
struct Struct_func_80318870 *func_803198E0(struct SubStruct_func_80318870 *arg0);
void func_80319BC8(void);
void func_80319D40(void);

// from playback_2
extern void func_80319E78(struct Struct80222A18 *arg0);
extern void func_8031A418(struct Struct_func_80318870 *arg0);
extern void func_8031A478(struct Struct_func_80318870 *arg0);
extern void func_8031A564(u8 *arg0, u16 *arg1, s16 *arg2);
extern void func_8031A584(u8 *arg0);

#endif /* _AUDIO_PLAYBACK_H */
