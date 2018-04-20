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

struct UnknownStruct5 {
    u8 filler0[0x8];
    /*0x08*/ s16 unk08;
    /*0x0C*/ u32 unk0C;
    /*0x10*/ u32 unk10;
};

struct Object
{
    u8 filler0[0x1A];
    /*0x01A*/ Vec3s unk1A;
    /*0x020*/ Vec3f unk20;
    u8 filler2C[0xC];
    /*0x038*/ s16 unk38;
    /*0x03C*/ struct UnknownStruct5 *unk3C;
    /*0x040*/ s16 unk40;
    u8 filler42[0x12];
    /*0x054*/ u32 unk54;
    u8 filler58[0x48];
    /*0x0A0*/ Vec3f pos;
    /*0x0AC*/ Vec3f vel;
    u8 fillerB8[0xC];
    /*0x0C4*/ Vec3i angle;
    /*0x0D0*/ Vec3i faceAngle;
    u8 fillerDC[0x18];
    /*0x0F4*/ u32 unkF4;
    /*0x0F8*/ u32 unkF8;
    u8 fillerFC[0xC];
    /*0x108*/ f32 unk108;
    u8 filler10C[0x110-0x10C];
    /*0x110*/ s32 unk110;
    /*0x114*/ Vec3i platformRotation;
    u8 filler120[0x14];
    /*0x134*/ u32 interactStatus;
    u8 filler138[0x58];
    /*0x190*/ u32 unk190;
    u8 filler194[0x80];
    /*0x214*/ struct Object *platform;
};

struct Area
{
    /*0x00*/ s8 index;
    /*0x01*/ u8 unk01;
    /*0x02*/ u16 unk02;
    /*0x04*/ u32 unk04;
    /*0x08*/ s16 *unk08;
    /*0x0C*/ u32 unk0C;
    /*0x10*/ s16 *unk10;
    /*0x14*/ u32 unk14;
    /*0x18*/ u32 unk18;
    /*0x1C*/ u32 unk1C;
    /*0x20*/ u32 unk20;
    /*0x24*/ u8 *unk24;
    /*0x28*/ u32 unk28;
    /*0x2C*/ u32 unk2C;
    /*0x30*/ u32 unk30;
    /*0x34*/ s8 unk34;
    /*0x35*/ s8 unk35;
    /*0x36*/ u16 unk36;
    /*0x38*/ u16 unk38;
};

struct Surface
{
    /*0x00*/ s16 type;
    /*0x02*/ s16 unk02;
    /*0x04*/ s8 flags;
    /*0x05*/ s8 unk05;
    /*0x06*/ s16 lowerY;
    /*0x08*/ s16 upperY;
    /*0x0A*/ Vec3s vertex1;
    /*0x10*/ Vec3s vertex2;
    /*0x16*/ Vec3s vertex3;
    /*0x1C*/ Vec3f normal;
    /*0x28*/ f32 originOffset;
    /*0x2C*/ struct Object *object;
};

struct UnknownStruct6 {
    /*0x00*/ u32 unk00;
    /*0x04*/ Vec3f unk04;
    /*0x10*/ Vec3s unk10;
    /*0x16*/ s16 unk16;
    /*0x18*/ s16 unk18;
    u8 filler1A[4];
    /*0x1E*/ u16 unk1E;
};

struct UnknownStruct4
{
    /*0x00*/ u32 unk00;
    /*0x04*/ u8 unk04;
    /*0x05*/ u8 unk05;
    /*0x06*/ u8 unk06;
    /*0x07*/ u8 unk07;
    /*0x08*/ u16 unk08;
    /*0x0A*/ u8 unk0A;
    /*0x0B*/ u8 unk0B;
    /*0x0C*/ s16 unk0C;
    /*0x10*/ s16 unk10;
    /*0x12*/ s16 unk12;
    /*0x14*/ u16 unk14;
    /*0x16*/ u16 unk16;
    /*0x18*/ Vec3f unk18;
};

struct MarioState
{
    /*0x00*/ u16 unk00;
    /*0x02*/ u16 input;
    /*0x04*/ u32 flags;
    /*0x08*/ u32 unk08;
    /*0x0C*/ u32 action;
    /*0x10*/ u32 prevAction;
    /*0x14*/ u32 unk14;
    /*0x18*/ u16 actionState;
    /*0x1A*/ u16 actionTimer;
    /*0x1C*/ u32 actionArg;
    /*0x20*/ f32 intendedMag;
    /*0x24*/ s16 intendedYaw;
    /*0x26*/ s16 invincTimer;
    /*0x28*/ u8 framesSinceA;
    /*0x29*/ u8 framesSinceB;
    /*0x2A*/ u8 wallKickTimer;
    /*0x2B*/ u8 doubleJumpTimer;
    /*0x2C*/ Vec3s faceAngle;
    /*0x32*/ Vec3s angleVel;
    /*0x38*/ s16 slideYaw;
    /*0x3A*/ s16 twirlYaw;
    /*0x3C*/ Vec3f pos;
    /*0x48*/ Vec3f vel;
    /*0x54*/ f32 forwardVel;
    /*0x58*/ f32 slideVelX;
    /*0x5C*/ f32 slideVelZ;
    /*0x60*/ struct Surface *wall;
    /*0x64*/ struct Surface *ceil;
    /*0x68*/ struct Surface *floor;
    /*0x6C*/ f32 ceilHeight;
    /*0x70*/ f32 floorHeight;
    /*0x74*/ s16 floorAngle;
    /*0x76*/ s16 waterLevel;
    /*0x78*/ struct Object *interactObj;
    /*0x7C*/ struct Object *heldObj;
    /*0x80*/ struct Object *usedObj;
    /*0x84*/ struct Object *riddenObj;
    /*0x88*/ struct Object *marioObj;
    /*0x8C*/ u32 level;
    /*0x90*/ struct Area *area;
    /*0x94*/ struct UnknownStruct6 *unk94;
    /*0x98*/ struct UnknownStruct4 *unk98;
    /*0x9C*/ struct Controller *controller;
    /*0xA0*/ u32 animation;
    /*0xA4*/ u32 collidedObjInteractTypes;
    /*0xA8*/ s16 numCoins;
    /*0xAA*/ s16 numStars;
    /*0xAC*/ u8 unkAC;
    /*0xAD*/ s8 numLives;
    /*0xAE*/ s16 health;
    /*0xB0*/ s16 unkB0;
    /*0xB2*/ u8 hurtCounter;
    /*0xB3*/ u8 healCounter;
    /*0xB4*/ u8 squishTimer;
    /*0xB5*/ u8 unkB5;
    /*0xB6*/ u16 capTimer;
    /*0xB8*/ s16 unkB8;
    /*0xBC*/ f32 peakHeight;
    /*0xC0*/ f32 quicksandDepth;
    /*0xC4*/ f32 unkC4;
};

#endif
