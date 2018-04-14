#ifndef _TYPES_H_
#define _TYPES_H_

// This file contains various data types used in Super Mario 64 that don't yet
// have an appropriate header.

struct UnknownStruct8035FFA8
{
    u8 filler0[7];
    s8 unk7;
};

struct UnknownStruct2
{
    u8 filler0[0x54];
    u8 unk54[100];
};

struct UnknownStruct3
{
    u8 filler0[5];
    s8 unk5;
};

struct Struct8032C9D8
{
    u8 filler0[0x44];
    float unk44;
    u8 filler48[0x68-0x48];
    struct UnknownStruct3 *unk68;
    u8 filler6C[0xAA-0x6C];
    s16 unkAA;
};

struct UnknownStruct80339E00
{
    u8 filler0[0x88];
    struct UnknownStruct2 *unk88;
};

struct Struct8032C6AC
{
    u8 filler0[0x12];
    u16 unk12;
};

struct Struct8032C630
{
    OSTask task;
    OSMesgQueue *msgqueue;
    OSMesg *msg;
    u32 unk48;
};

struct Struct8032C620
{
    OSMesgQueue *queue;
    OSMesg *msg;
};

struct Struct80333F00
{
    u8 filler0[0xA0];
    OSViMode viMode;
};

typedef float Vec3f[3];
typedef s16 Vec3s[3];

#endif
