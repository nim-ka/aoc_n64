#ifndef _AUDIO_PLAYBACK_H
#define _AUDIO_PLAYBACK_H

#include "types.h"

#define MINUS_ONE ((struct SubStruct_func_80318870 *)(-1))

struct PlaybackListItem
{
    // A node in a circularly linked list. Each node is either a head or an item:
    // - Items can be either detached (prev = NULL), or attached to a list.
    //   'value' points to something of interest.
    // - List heads are always attached; if a list is empty, its head points
    //   to itself. 'count' contains the size of the list.
    struct PlaybackListItem *prev;
    struct PlaybackListItem *next;
    union {
        struct Struct_func_80318870 *value;
        s32 count;
    } u;
    struct PlaybackListItem *unkC; // points to container of four heads
};

struct Unk50
{
    u8 pad0b : 5;
    u8 unk0b4 : 1;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
    u8 pad1[0x12];
    s16 unk18; //this - 0x80 defines which wave to use (0,1,2,3) (sawtooth, triangle, sine, square)
    u8 pad2[0x1a];
    struct Struct_func_80318870 *unk34;
    struct SubStruct_func_80318870 *unk38;
    u8 pad3[0x4];
    struct
    {
        u32 pad0 : 2;
        u32 unk0b20 : 1;
        u8 pad[0x8c];
        struct PlaybackListItem unk90[4]; // heads
    } * unk40;                            // points to a SubStruct_func_80318870?
    u8 pad4[0x34];
    u8 unk78;
    u16 unk7A;
    u32 unk7C;
    struct PlaybackListItem unk80[4]; // heads
};

struct SubStruct_func_80318870
{
    u8 unk0b80 : 1;
    u8 unk0b40 : 1;
    u8 unk1;
    u8 pad0[0x5];
    u8 unk7;
    u8 pad6[0xC];
    u8 unk14;
    u32 unk18;
    u8 pad1[0x4];
    f32 unk20;
    u8 pad2[0x8];
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    u8 pad3[0xC];
    struct Struct_func_80318870 *unk44;
    u8 pad4[0x4];
    struct SubStruct_func_80318870_3 *unk4C; // unknown type
    struct Unk50 *unk50;
    u8 pad5[0x1c];
    struct PlaybackListItem unk70;
};

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
    //u8 pad2[0x04];
    struct SubStruct_func_80318870_3 *unk24; // unknown type, pointer
    struct SubStruct_func_80318870 *unk28;
    struct SubStruct_func_80318870 *unk2C;
    struct SubStruct_func_80318870 *unk30;
    struct SubStruct_func_80318F04 *unk34;
    //s16 *unk34;
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
    u8 pad5[0x14];
    // }; ?
    f32 unk78;
    f32 unk7C;
    u8 pad6[0x10];
    u8 unk90;
    u8 pad7[0xb];
    s16 unk9C;
    s16 unk9E;
    s16 unkA0;
    s16 unkA2;
    struct PlaybackListItem unkA4; // item, not head
    u8 pad9[0x0c];
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
extern struct PlaybackListItem D_80225E98;      // head, maybe part of the next array
extern struct PlaybackListItem D_80225EA8[4];   // four heads

extern void func_8031A564(u8 *arg0, u32 arg1, s16 *arg2);
extern struct Struct_func_80318870 *func_8031AF34(void *arg0);
extern void func_8031AEF4(struct PlaybackListItem *head, struct PlaybackListItem *item);
extern void func_8031AA10(struct SubStruct_func_80318870 *arg0);
extern void func_8031AAD0(struct Unk50 *arg0);

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

// extern ? func_80319E78(?);
// extern ? func_8031A078(?);
// extern ? func_8031A17C(?);
// extern ? func_8031A204(?);
extern void func_8031A418(struct Struct_func_80318870 *arg0);
extern void func_8031A478(struct Struct_func_80318870 *arg0);
// extern ? func_8031A564(?);
extern void func_8031A584(u8 *arg0);

#endif /* _AUDIO_PLAYBACK_H */
