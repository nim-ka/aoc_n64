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

// Not used, probably
/*
struct Demo {
    u32 demoId;
    // this area is where the inputs are allocated. take the header and add 1 word
    // to get the input list pointer.
    struct DemoInput demoInputs[50]; // arbitrary size for struct definition convenience
};
*/

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

typedef float Vec2f[2];
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

struct SceneGraphNode
{
    /*0x00*/ s16 type;
    /*0x00*/ s16 unk02; 
    /*0x04*/ struct SceneGraphNode *unk04;
    /*0x08*/ struct SceneGraphNode *unk08;
    /*0x0C*/ struct SceneGraphNode *unk0C;
    /*0x10*/ struct SceneGraphNode *unk10;
};

struct SceneGraphDListNode
{
    /*0x00*/ struct SceneGraphNode node;
    /*0x14*/ void *gfx; // Gfx* segptr
};

struct SceneGraphScreenAreaNode
{
    // node.type = 0x01
    /*0x00*/ struct SceneGraphNode node;
    u8 filler14[(0x1E)-0x14];
    /*0x1E*/ s16 unk1E;
    /*0x20*/ struct SceneGraphNode **unk20; // TODO: check type
};

struct SceneGraphNode_x29
{
    // node.type = 0x29
    /*0x00*/ struct SceneGraphNode node;
    /*0x14*/ struct SceneGraphNode *unk14;
};

// NOTE: Since GfxNode is the first member of Object, it is difficult to determine
// whether some of these pointers point to GfxNode or Object.

struct GfxNode
{
    u8 filler0[2];
    /*0x002*/ s16 graphFlags;
    u8 filler4[0x8-0x4];
    /*0x008*/ struct Object *unk8;
    u8 fillerC[4];
    /*0x010*/ struct Object *unk10;
    /*0x014*/ void *geoLayout;
    u8 filler18[2];
    /*0x01A*/ Vec3s unk1A;
    /*0x020*/ Vec3f unk20;
    /*0x02C*/ Vec3f scale;
    /*0x038*/ s16 unk38;
    /*0x03A*/ u16 unk3A;
    /*0x03C*/ struct UnknownStruct5 *unk3C;
    /*0x040*/ s16 unk40;
    u8 filler42[0x50-0x42];
    /*0x050*/ u32 unk50;
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
    u8 fillerE0[0x4];
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
    u8 filler178[0x180-0x178];
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
    /*0x20C*/ void *unk20C;
    /*0x210*/ u32 unk210;
    /*0x214*/ struct Object *platform;
    /*0x218*/ void *collisionData;
    /*0x21C*/ float unk21C[4][4];
    /*0x25C*/ u32 unk25C;
};

struct UnknownArea1C {
    /*0x00*/ u8 unk00;
    /*0x01*/ u8 unk01;
    /*0x02*/ Vec3s displacement;
};

struct UnknownArea24 { // Camera or camera related
    /*0x00*/ u8 unk00;
    /*0x01*/ u8 unk01;
    /*0x02*/ s16 unk02;
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
    /*0x18*/ struct WarpNode *paintingWarpNodes;
    /*0x1C*/ struct UnknownArea1C *unk1C;
    /*0x20*/ u32 unk20;
    /*0x24*/ struct UnknownArea24 *unk24;
    /*0x28*/ u32 unk28;
    /*0x2C*/ u32 unk2C;
    /*0x30*/ u32 unk30;
    /*0x34*/ u8 unk34[1]; // Unknown size
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

struct Struct8032D000
{
    u32 unk0;
    Vec3f unk4;
    Vec3s unk10;
    s16 unk16;
    s16 unk18;
    u8 filler1A[0x1E - 0x1A];
    s16 unk1E;
};

struct Struct80280550
{
    u8 unk0;
    u8 filler1[1];
    u16 unk2;
    Vec3f unk4;
    Vec3f unk10;
    u8 filler1C[0x28-0x1C];
    float unk28;
    float unk2C;
    u8 filler30[0xA];
    s16 unk3A;
};

struct Struct8033B470
{
    s16 unk0;
    u8 filler2[2];
    Vec3f unk4;
    float unk10;
    float unk14;
};

struct BullyCollisionData {
  /*0x00*/ f32 conversionRatio;
  /*0x04*/ f32 radius;
  /*0x08*/ f32 posX;
  /*0x0C*/ f32 posZ;
  /*0x10*/ f32 velX;
  /*0x14*/ f32 velZ;
};

struct Struct80278464
{
    s32 unk0;
    s32 unk4;  
    u8 *unk8;
    u8 *unkC;
};

struct MemBlock
{
    struct MemBlock *next;
    u32 size;
};

struct UnknownMemoryStruct2
{
    u32 unk0;
    u32 unk4;
    struct MemBlock *unk8;
};

struct UnknownMemoryStruct3
{
    u32 unk0;
    void *unk4;
    void *unkC;
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

struct StructGeo802D2360
{
    s32 unk0;
    s32 *unk4;
};

// Maybe Object? I don't know...
struct Struct8032CFD0
{
    u8 filler0[0x124];
    u32 unk124;
};

struct Struct8033A140 // Level, I think
{
    /*0x00*/ Vec3s marioStartPos;
    /*0x06*/ Vec3s marioStartAngle;
    /*0x0C*/ s8 areaIndex[1];
    /*0x0D*/ s8 unk0D;
    /*0x10*/ u32 unk10;
    /*0x14*/ u32 unk14;
    /*0x18*/ u32 unk18;
    /*0x1C*/ u32 unk1C;
};

struct WarpNode
{
    /*00*/ u8 id;
    /*01*/ u8 destLevel;
    /*02*/ u8 destArea;
    /*03*/ u8 destNode;
};

struct ObjectWarpNode
{
    /*00*/ struct WarpNode node;
    /*04*/ struct Object *object;
};

struct CreditsEntry
{
    /*0x00*/ u8 levelNum;
    /*0x01*/ u8 areaIndex;
    /*0x02*/ u8 unk02;
    /*0x03*/ s8 marioAngle;
    /*0x04*/ Vec3s marioPos;
    /*0x0C*/ const char **unk0C;
};

struct Struct8033B418_sub
{
    float unk0;
    float unk4;
    float unk8;
    u8 fillerC[0x18 - 0xC];
    float unk18;
    s16 unk1C;
    s16 unk1E;
};

struct Struct8033B418
{
    u8 filler0[4];
    s16 unk4;
    s16 unk6;
    struct Struct8033B418_sub unk8[2];  // unknown length
};

#endif
