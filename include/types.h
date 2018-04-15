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
typedef s32 Vec3i[3];
typedef float Vec4f[4];
typedef s16 Vec4s[4];

struct Object
{
    u8 filler0[0xA0];
    Vec3f pos; // 0xA0
    Vec3f vel; // 0xAC
    u8 fillerB8[0x18];
    Vec3i faceAngle; // 0xD0
    u8 fillerDC[0x38];
    Vec3i platformRotation; // 0x114
    u8 filler120[0xF4];
    struct Object *platform; // 0x214
};

struct Surface
{
    s16 type; // 0x00
    s16 unk02; // 0x02
    s8 flags; // 0x04
    s8 unk05; // 0x05
    s16 lowerY; // 0x06
    s16 upperY; // 0x08
    Vec3s vertex1; // 0x0A
    Vec3s vertex2; // 0x10
    Vec3s vertex3; // 0x16
    Vec3f normal; // 0x1C
    f32 originOffset; // 0x28
    struct Object *object; // 0x2C
};

struct MarioState
{
    u8 filler0[0x2C];
    Vec3s faceAngle; // 0x2C
    u8 filler32[0xA];
    Vec3f pos; // 0x3C
    u8 filler48[0x40];
    struct UnknownStruct2 *unk88; // 0x88
};

#endif
