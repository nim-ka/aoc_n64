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
    union
    {
        struct Struct_func_80318870 *value;
        s32 count;
    } u;
    struct PlaybackListItem *unkC; // points to container of four heads
};

struct SubSubStruct_func_80318870
{
    u8 pad1;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
    u8 pad3[0x3a];
    struct
    {
        u32 pad0 : 2;
        u32 unk0b20 : 1;
        u8 pad[0x8c];
        struct PlaybackListItem unk90[4]; // heads
    } *unk40; // points to a SubStruct_func_80318870?
    u8 pad4[0x34];
    u8 unk78;
    u16 unk7A;
    u32 unk7C;
    struct PlaybackListItem unk80[4]; // heads
};

struct SubStruct_func_80318870
{
    u8 unk0 : 1;
    u8 unk1;
    u8 pad1[0x12];
    u8 unk14;
    u32 unk18;
    u8 pad2[0x10];
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    u8 pad3[0xC];
    struct Struct_func_80318870 *unk44;
    u8 pad4[0x8];
    struct SubSubStruct_func_80318870 *unk50;
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

struct Struct_func_80318870
{
    u8 unk0b80 : 1;
    u8 pad0b : 4;
    u8 unk0b4 : 1;
    u8 unk0b2 : 1;
    u8 unk0b1 : 1;
    u8 unk1;
    u8 pad0[0x2];
    u8 unk4;
    u8 unk5;
    u8 unk6;
    s16 unk8;
    u8 pad2[0x1e];
    struct SubStruct_func_80318870 *unk28;
    struct SubStruct_func_80318870 *unk2C;
    struct SubStruct_func_80318870 *unk30;
    void *unk34;
    f32 unk38;
    u16 unk3C;
    u16 unk3E;
    u8 unk40;
    u8 unk41;
    struct SubStruct_func_80318870_2 unk44;
    u8 unk54;
    u8 unk55;
    u8 pad3[0x4];
    s16 unk5A;
    u8 pad4[0x4];
    s16 unk60;
    s16 unk62;
    u8 pad5[0x14];
    f32 unk78;
    f32 unk7C;
    u8 pad6[0x10];
    u8 unk90;
    u8 pad7[0x13];
    struct PlaybackListItem unkA4; // item, not head
    u8 pad8[0x0c];
}; // size = 0xC0

struct SubStruct_func_80318F04
{
    u8 pad[0x110];
    s16 unk110[1];
};

struct Struct_func_80318F04
{
    u8 pad1[5];
    u8 unk5; // 8, 16, 32 or 64
    u8 unk6;
    u8 pad2[13];
    s32 unk14;
    u8 pad3[0x1c];
    struct SubStruct_func_80318F04 *unk34;
};

struct SubStruct2_func_80318F04
{
    u8 pad[0x18];
    s16 unk18;
};

struct Struct2_func_80318F04
{
    u8 pad1[0x20];
    f32 unk20;
    u8 pad2[0x2c];
    struct SubStruct2_func_80318F04 *unk50;
};

extern struct Struct_func_80318870 *D_80222A10; // points to an array
extern struct PlaybackListItem D_80225E98; // head, maybe part of the next array
extern struct PlaybackListItem D_80225EA8[4]; // four heads
// extern ? D_80225EAC;
extern s16 *D_80332CC0[];

extern void func_803159C0(struct Struct_func_80318870 *arg0);
extern void func_80315D94(struct Struct_func_80318870 *arg0);
extern void func_8031A564(u8 *arg0, u32 arg1, s16 *arg2);
extern void func_80315DE0(u32 arg0);
extern struct Struct_func_80318870 *func_8031AF34(void *arg0);
extern void func_8031AEF4(struct PlaybackListItem *head, struct PlaybackListItem *item);
extern void func_8031AA10(struct SubStruct_func_80318870 *arg0);
extern void func_8031AAD0(struct SubSubStruct_func_80318870 *arg0);

void func_80318870(struct Struct_func_80318870 *arg0);
void func_803188E8(u32 arg0);
// extern ? func_80318908(?);
void func_80318D18(struct SubStruct_func_80318870 *arg0, s32 arg1);
void func_80318EC4(struct SubStruct_func_80318870 *arg0);
void func_80318EE4(struct SubStruct_func_80318870 *arg0);
void func_80318F04(struct Struct_func_80318F04 *arg0, struct Struct2_func_80318F04 *arg1);
void func_80319164(struct Struct_func_80318F04 *arg0, struct Struct2_func_80318F04 *arg1);
void func_803191E8(struct PlaybackListItem *head);
void func_803191F8(struct PlaybackListItem *headList);
void func_80319248(void);
void func_803192FC(struct PlaybackListItem *headList);
void func_80319428(struct PlaybackListItem *headList, s32 count);
void func_80319564(struct PlaybackListItem *head, struct PlaybackListItem *item);
void func_803195A4(struct PlaybackListItem *item);
struct Struct_func_80318870 *func_803195D0(struct PlaybackListItem *head, s32 arg1);
extern s32 func_80319660(struct Struct_func_80318870 *arg0, struct SubStruct_func_80318870 *arg1);
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
// extern ? func_8031A418(?);
// extern ? func_8031A478(?);
// extern ? func_8031A564(?);
// extern ? func_8031A584(?);

#endif /* _AUDIO_PLAYBACK_H */
