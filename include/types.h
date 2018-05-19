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

struct Struct802D1F94
{
    s16 unk0;
    s8 unk2;
    s8 unk3;
    s8 unk4;
    s8 unk5;
    s8 unk6;
    s8 unk7;
    float unk8;
    float unkC;
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
    float unk20;
    float unk24;
    float unk28;
    float unk2C;
    float unk30;
    float unk34;
    float unk38;
    float unk3C;
    float unk40;
    float unk44;
    float unk48;
    float unk4C;
    float unk50;
    float unk54;
    void *unk58;
    void *unk5C;
    void *unk60;
    s16 unk64;
    s16 unk66;
    void *unk68;
    s8 unk6C;
    u8 unk6D;
    s8 unk6E;
    s8 unk6F;
    s8 unk70;
    u8 filler71[3];
    float unk74;
};

typedef float Vec2f[2];
typedef float Vec3f[3];
typedef s16 Vec3s[3];
typedef s32 Vec3i[3];
typedef float Vec4f[4];
typedef s16 Vec4s[4];

typedef float Mat4[4][4];
typedef f32 (*Mat4p)[4];

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

// NOTE: Since GfxNode is the first member of Object, it is difficult to determine
// whether some of these pointers point to GfxNode or Object.

struct UnknownStruct5 {
    /*0x00*/ s16 unk00; // flags
    /*0x02*/ s16 unk02;
    /*0x04*/ s16 unk04;
    /*0x06*/ s16 unk06;
    /*0x08*/ s16 unk08;
    /*0x0C*/ void *unk0C;
    /*0x10*/ void *unk10;
};

struct GfxNode
{
    u8 filler0[2];
    /*0x002*/ s16 graphFlags;
    u8 filler4[0x8-0x4];
    /*0x008*/ struct Object *unk8;
    u8 fillerC[4];
    /*0x010*/ struct Object *unk10;
    /*0x014*/ void *geoLayout;
    /*0x018*/ u8 unk18;
    /*0x019*/ u8 unk19;
    /*0x01A*/ Vec3s unk1A;
    /*0x020*/ Vec3f unk20;
    /*0x02C*/ Vec3f scale;
    /*0x038*/ s16 unk38;
    /*0x03A*/ u16 unk3A;
    /*0x03C*/ struct UnknownStruct5 *unk3C;
    /*0x040*/ s16 unk40;
    u8 filler42[0x50-0x42];
    /*0x050*/ void *unk50;
    /*0x054*/ u32 unk54;
    u8 filler58[0x60-0x58];
    /*0x060*/ struct GfxNode *prev;
    /*0x064*/ struct GfxNode *next;
};

struct Object
{
    /*0x000*/ struct GfxNode gfx;
    /*0x068*/ struct Object *unk68;
    /*0x06C*/ struct Object *unk6C;
    /*0x070*/ u32 collidedObjInteractTypes;
    /*0x074*/ s16 active;
    /*0x076*/ s16 numCollidedObjs;
    /*0x078*/ struct Object *collidedObjs[4];
    u32 unk88[1];  // unknown length
    /*0x08C*/ u32 objFlags;
    u8 filler90[0x9C-0x90];
    /*0x09C*/ s32 unk9C;
    /*0x0A0*/ Vec3f pos;
    /*0x0AC*/ Vec3f vel;
    /*0x0B8*/ f32 forwardVel;
    u8 fillerBC[0xC4-0xBC];
    /*0x0C4*/ Vec3i angle;
    /*0x0D0*/ Vec3i faceAngle;
    /*0x0DC*/ f32 unkDC;
    /*0x0E0*/ u32 unkE0;
    /*0x0E4*/ f32 unkE4;
    /*0x0E8*/ float unkE8;
    /*0x0EC*/ u32 unkEC;
    u8 fillerF0[0x4];
    /*0x0F4*/ u32 unkF4;
    /*0x0F8*/ u32 unkF8;
    u8 fillerFC[0xC];
    /*0x108*/ f32 unk108;
    /*0x10C*/ s32 unk10C;
    /*0x110*/ s32 unk110;
    /*0x114*/ Vec3i platformRotation;
    /*0x120*/ u32 *animations;
    /*0x124*/ u32 unk124;
    /*0x128*/ f32 unk128;
    /*0x12C*/ f32 unk12C;
    /*0x130*/ u32 interactType;
    /*0x134*/ u32 interactStatus;
    u8 filler138[0xC];
    /*0x144*/ u32 behParam;
    u8 filler148[0x4];
    /*0x14C*/ u32 action;
    /*0x150*/ u32 unk150;
    /*0x154*/ s32 timer;
    /*0x158*/ f32 unk158;
    /*0x15C*/ f32 distanceFromMario;
    /*0x160*/ u32 unk160;
    /*0x164*/ Vec3f unk164;
    /*0x170*/ f32 unk170;
    /*0x174*/ f32 unk174;
    /*0x178*/ s32 unk178;
    u8 filler17C[0x180-0x17C];
    /*0x180*/ s32 unk180;
    /*0x184*/ u32 unk184;
    /*0x188*/ s32 unk188;
    /*0x18C*/ u32 previousAction;
    /*0x190*/ u32 unk190;
    /*0x194*/ f32 collisionDistance;
    /*0x198*/ u32 unk198;
    /*0x19C*/ f32 drawingDistance;
    /*0x1A0*/ u32 unk1A0;
    u8 filler1A4[0x1A8-0x1A4];
    /*0x1A8*/ u32 unk1A8;
    u8 filler1AC[0x1C8-0x1AC];
    /*0x1C8*/ u32 unk1C8;
    /*0x1CC*/ u32 *behScript;
    /*0x1D0*/ u32 stackIndex;
    /*0x1D4*/ u32 stack[8];
    /*0x1F4*/ s16 unk1F4;
    /*0x1F6*/ u16 unk1F6;
    /*0x1F8*/ f32 hitboxRadius;
    /*0x1FC*/ f32 hitboxHeight;
    /*0x200*/ f32 unk200;
    /*0x204*/ f32 unk204;
    /*0x208*/ f32 unk208;
    /*0x20C*/ void *behavior;
    /*0x210*/ u32 unk210;
    /*0x214*/ struct Object *platform;
    /*0x218*/ void *collisionData;
    /*0x21C*/ float unk21C[4][4];
    /*0x25C*/ u32 unk25C;
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
    /*0x20*/ struct Object *unk20;
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
    /*0x0E*/ u8 filler0E[2];
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
    /*0x08*/ u32 particleFlags;
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
    /*0xAC*/ s8 numKeys; // Unused key mechanic
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



struct Struct80278464
{
    s32 unk0;
    s32 unk4;  
    u8 *unk8;
    u8 *unkC;
};

struct StructGeo802D2360
{
    s32 unk0;
    s32 *unk4;
};

struct MarioAnimDmaRelatedThing
{
    u32 unk0;
    u32 unk4;
};

struct MarioAnimation
{
    struct MarioAnimDmaRelatedThing *animDmaTable;
    u32 currentDma;
    void *targetAnim;
    u8 padding[4];
};

#endif
