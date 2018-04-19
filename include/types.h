#ifndef _TYPES_H_
#define _TYPES_H_

// This file contains various data types used in Super Mario 64 that don't yet
// have an appropriate header.

struct Controller 
{
  /*0x00*/ s16 rawStickX;       //
  /*0x02*/ s16 rawStickY;       //
  /*0x04*/ float stickX;        // [-64, 64] positive is right
  /*0x08*/ float stickY;        // [-64, 64] positive is up
  /*0x0C*/ float stickMag;      // distance from center [0, 64]
  /*0x10*/ u16 buttonDown;
  /*0x12*/ u16 buttonPressed;
  /*0x14*/ OSContStatus* statusData;
  /*0x18*/ OSContPad *controllerData;
};

struct DemoInput
{ // TODO: see if timer matches with s8
 /*0x00*/ u8 timer; // until next input: if this value 
                    // is 0 proceeding on the demo input, it 
                    // means the demo is over.
 /*0x01*/ s8 rawStickX;
 /*0x02*/ s8 rawStickY;
 /*0x03*/ u8 button;
};

struct Demo {
    u32 demoId;
    // this area is where the inputs are allocated. take the header and add 1 word
    // to get the input list pointer.
    struct DemoInput demoInputs[50]; // arbitrary size for struct definition convenience
};

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
    u8 filler0[0x40];
    s16 unk40;
    u8 filler42[0x12];
    u32 unk54;
    u8 filler58[0x48];
    Vec3f pos; // 0xA0
    Vec3f vel; // 0xAC
    u8 fillerB8[0x18];
    Vec3i faceAngle; // 0xD0
    u8 fillerDC[0xF4-0xDC];
    u32 unkF4;
    u32 unkF8;
    u8 fillerFC[0x108-0xFC];
    float unk108;
    u8 filler10C[0x114-0x10C];
    Vec3i platformRotation; // 0x114
    u8 filler120[0xF4];
    struct Object *platform; // 0x214
};

struct Area
{
    s8 index;
    u8 v01;
    u16 v02;
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
    u16 unk00; // 0x00
    u16 input; // 0x02
    u32 flags; // 0x04
    u32 unk08; // 0x08
    u32 action; // 0x0C
    u32 prevAction; // 0x10
    u32 unk14; // 0x14
    u16 unk18; // 0x18
    u16 actionTimer; // 0x1A
    u32 actionArg; // 0x1C
    f32 intendedMag; // 0x20
    s16 intendedYaw; // 0x24
    s16 invincTimer; // 0x26
    u8 framesSinceA; // 0x28
    u8 framesSinceB; // 0x29
    u8 wallKickTimer; // 0x2A
    u8 doubleJumpTimer; // 0x2B
    Vec3s faceAngle; // 0x2C
    Vec3s angleVel; // 0x32
    s16 slideYaw; // 0x38
    s16 twirlYaw; // 0x3A
    Vec3f pos; // 0x3C
    Vec3f vel; // 0x48
    f32 forwardVel; // 0x54
    f32 slideVelX; // 0x58
    f32 slideVelZ; // 0x5C
    struct Surface *wall; // 0x60
    struct Surface *ceil; // 0x64
    struct Surface *floor; //0x68
    f32 ceilHeight; // 0x6C
    f32 floorHeight; // 0x70
    s16 floorAngle; // 0x74
    s16 waterLevel; // 0x76
    struct Object *interactObj; // 0x78
    struct Object *heldObj; // 0x7C
    struct Object *usedObj; // 0x80
    struct Object *riddenObj; // 0x84
    struct Object *marioObj; // 0x88
    u32 level; // 0x8C
    struct Area *area; // 0x90
    u32 unk94; // 0x94
    u32 unk98; // 0x98
    struct Controller *controller; // 0x9C
    u32 animation; // 0xA0
    u32 collidedObjInteractTypes; // 0xA4
    s16 numCoins; // 0xA8
    s16 numStars; // 0xAA
    u8 unkAC; // 0xAC
    s8 numLives; // 0xAD
    s16 health; // 0xAE
    s16 unkB0; // 0xB0
    u8 hurtCounter; // 0xB2
    u8 healCounter; // 0xB3
    u8 squishTimer; // 0xB4
    u8 unkB5; // 0xB5
    u16 capTimer; // 0xB6
    s16 unkB8; // 0xB8
    f32 peakHeight; // 0xBC
    f32 quicksandDepth; // 0xC0
    f32 unkC4; // 0xC4
};

#endif
