#ifndef _GD_TYPES_H
#define _GD_TYPES_H

#include "types.h"
/* Vector Types */
struct GdPlaneF {
    struct MyVec3f vec0;
    struct MyVec3f vec1;
};

struct GdTriangleF {
    struct MyVec3f vec0;
    struct MyVec3f vec1;
    struct MyVec3f vec2;
};

struct GdColour {
    f32 r, g, b;
};

/* Goddard Code Object Structs */
/* Object Type Flags */
enum ObjTypeFlag {
    OBJ_TYPE_GROUPS    = 0x00000001,
    OBJ_TYPE_BONES     = 0x00000002,
    OBJ_TYPE_JOINTS    = 0x00000004,
    OBJ_TYPE_PARTICLES = 0x00000008,
    OBJ_TYPE_SHAPES    = 0x00000010,
    OBJ_TYPE_NETS      = 0x00000020,
    OBJ_TYPE_PLANES    = 0x00000040,
    OBJ_TYPE_FACES     = 0x00000080,
    OBJ_TYPE_VERTICES  = 0x00000100,
    OBJ_TYPE_CAMERAS   = 0x00000200,
    // 0x400 was not used
    OBJ_TYPE_MATERIALS = 0x00000800,
    OBJ_TYPE_WEIGHTS   = 0x00001000,
    OBJ_TYPE_GADGETS   = 0x00002000,
    OBJ_TYPE_VIEWS     = 0x00004000,
    OBJ_TYPE_LABELS    = 0x00008000,
    OBJ_TYPE_ANIMATORS = 0x00010000,
    OBJ_TYPE_VALPTRS   = 0x00020000,
    // 0x40000 was not used
    OBJ_TYPE_LIGHTS    = 0x00080000,
    OBJ_TYPE_ZONES     = 0x00100000,
    OBJ_TYPE_UNK200000 = 0x00200000
};
/* This constant seems to be used to indicate the type of any or all objects */
#define OBJ_TYPE_ALL 0x00FFFFFF

/* This is a header sub-struct that is embeded into the other object structs
** It can be used as a "generic object" to cast into the other object types  */
struct ObjHeader {
    /* 0x00 */ struct ObjHeader* prev;
    /* 0x04 */ struct ObjHeader* next;
    /* 0x08 */ void (*objDrawFn)(void *);
    /* 0x0C */ enum ObjTypeFlag type;
    /* 0x10 */ s16 number;
    /* 0x12 */ u16 unk12;   /* flag? */
    /* 0x14 Specific object data starts here  */
};

struct Links {
    /* 0x00 */ struct Links* prev;
    /* 0x04 */ struct Links* next;
    /* 0x08 */ struct ObjHeader* obj;
};

struct ObjGroup {
    /* 0x00 */ struct ObjHeader header;
    /* 0x14 */ struct ObjGroup* prev;
    /* 0x18 */ struct ObjGroup* next;
    /* 0x1C */ struct Links* link1C;
    /* 0x20 */ struct Links* link20;
    /* 0x24 */ s32 groupObjTypes;   // OR'd collection of type flags for all objects in this group?
    /* 0x28 */ s32 objCount;
    /* 0x2C */ s32 debugPrint;  // might also be a type?
    /* 0x30 */ s32 unk30;   //some sort of generic flag for type of Link..?
    /* 0x34 */ char name[0x40]; // possibly, old code only
    /* 0x74 */ s32 id;
}; /* sizeof = 0x78 */

struct ObjBone {
    /* 0x000 */ struct ObjHeader header;
    /* 0x014 */ struct MyVec3f unk14;   // from dead code in Proc8017A550
    /* 0x020 */ struct ObjBone* prev;   //maybe, based on make_bone
    /* 0x024 */ struct ObjBone* next;   //maybe, based on make_bone 
    /* 0x028 */ struct MyVec3f unk28;   // from dead code in Proc8017A550
    /* 0x034 */ u8  pad34[0x40-0x34];
    /* 0x040 */ struct MyVec3f unk40;
    /* 0x04C */ u8  pad4C[0x58-0x4C];
    /* 0x058 */ struct MyVec3f unk58;
    /* 0x064 */ struct MyVec3f unk64;
    /* 0x070 */ Mat4 mat70;
    /* 0x0B0 */ Mat4 matB0;
    /* 0x0F0 */ struct ObjShape* unkF0; // from dead code in Proc8017A550
    /* 0x0F4 */ f32 unkF4;
    /* 0x0F8 */ f32 unkF8;              // from dead code in Proc8017A550
    /* 0x0FC */ f32 unkFC;
    /* 0x100 */ s32 unk100;             // from dead code in Proc8017A550
    /* 0x104 */ s32 unk104;             // "flags"
    /* 0x108 */ s32 id;
    /* 0x10C */ struct ObjGroup* unk10C; // group of joints?
    /* 0x110 */ f32 unk110;     // "spring"
    /* 0x114 */ f32 unk114;
    /* 0x118 */ f32 unk118;
    /* 0x11C */ u8  pad11C[0x124-0x11C];
}; /* sizeof = 0x124 */

struct ObjJoint {
    /* 0x000 */ struct ObjHeader header;
    /* 0x014 */ struct MyVec3f unk14;    //position? based on d_set_initpos
    /* 0x020 */ struct ObjShape* unk20;
    /* 0x024 */ struct ObjJoint *prevjoint; // prev joint? linked joint?
    /* 0x028 */ struct ObjJoint *nextjoint;
    /* 0x02C */ void (*fn2C)(struct ObjJoint*);
    /* 0x030 */ struct MyVec3f unk30;   // huge array of vecs? another matrix?
    /* 0x03C */ struct MyVec3f unk3C;   // relative position?
    /* 0x048 */ struct MyVec3f unk48;
    /* 0x054 */ struct MyVec3f unk54;   // attached offset (with +200 as well)
    /* 0x060 */ u8  pad60[0x6C-0x60];
    /* 0x06C */ struct MyVec3f unk6C;   // initial rotation vec
    /* 0x078 */ struct MyVec3f unk78;
    /* 0x084 */ struct MyVec3f unk84;
    /* 0x090 */ struct MyVec3f unk90;
    /* 0x09C */ struct MyVec3f unk9C;   // scale vec?
    /* 0x0A8 */ struct MyVec3f unkA8;
    /* 0x0B4 */ struct MyVec3f unkB4;
    /* 0x0C0 */ struct MyVec3f unkC0;   // "shape offset"
    /* 0x0CC */ struct MyVec3f unkCC;
    /* 0x0D8 */ u8  padD8[4];
    /* 0x0DC */ struct MyVec3f unkDC;   // "friction"
    /* 0x0E8 */ Mat4 matE8;     //matrix4x4
    /* 0x128 */ Mat4 mat128;    // "rot matrix"
    /* 0x168 */ Mat4 mat168;    // "id matrix"
    /* 0x1A8 */ struct MyVec3f unk1A8;
    /* 0x1B4 */ s32 id;
    /* 0x1B8 */ u8  pad1B8[4];
    /* 0x1BC */ s32 unk1BC;     // "flags"
    /* 0x1C0 */ s32 unk1C0;
    /* 0x1C4 */ struct ObjGroup* unk1C4;    // bone group?
    /* 0x1C8 */ s32 unk1C8;     // "colour"
    /* 0x1CC */ s32 unk1CC;     // "type"
    /* 0x1D0 */ struct ObjAnimator* unk1D0;
    /* 0x1D4 */ u8  pad1D4[0x1f4-0x1d4];
    /* 0x1F4 */ struct ObjGroup* unk1F4;    //Group of ObjWeights, only?
    /* 0x1F8 */ struct ObjGroup* unk1F8;    //attach group
    /* 0x1FC */ s32 unk1FC;                 //d_attach_to arg 0; "AttFlag"
    /* 0x200 */ struct MyVec3f unk200;      //attached offset?
    /* 0x20C */ struct ObjHeader *unk20C;   //attached object?
    /* 0x210 */ u8  pad210[0x228-0x210];
    /* 0x228 */ f32 unk228;
}; /* sizeof = 0x22C */

struct ObjParticle {
    /* 0x00 */ struct ObjHeader header;
    /* 0x14 */ u8 pad14[0x1C-0x14];
    /* 0x1C */ struct ObjShape* unk1C;     // looks like a shape...
    /* 0x20 */ struct MyVec3f unk20;    // position vec?
    /* 0x2C */ u8 pad2C[0x30-0x2C];
    /* 0x30 */ f32 unk30;
    /* 0x34 */ u8 pad34[0x38-0x34];
    /* 0x38 */ struct MyVec3f unk38;
    /* 0x44 */ f32 unk44; //not vec?
    /* 0x48 */ f32 unk48; //not vec?
    /* 0x4C */ u8 pad4C[0x50-0x4C];
    /* 0x50 */ s32 id;
    /* 0x54 */ u32 unk54;   // "dflags"?
    /* 0x58 */ s32 unk58;   // "colour"
    /* 0x5C */ s32 unk5C;
    /* 0x60 */ s32 unk60;   //flag? type?
    /* 0x64 */ s32 unk64;   //flag?
    /* 0x68 */ u8 pad68[0x6C-0x68];
    /* 0x6C */ struct ObjGroup* unk6C;   // group of other Particles ?
    /* 0x70 */ u8 pad70[4];
    /* 0x74 */ s32 unk74;
    /* 0x78 */ u8 unk78[4];
    /* 0x7C */ struct ObjAnimator* unk7C;   // guessing on type; doesn't seem to be used in final code
    /* 0x80 */ struct ObjLight* unk80;  // could be a Net or Light; not seen as non-null in running code
    /* 0x84 */ u8 pad84[0xB0-0x84];
    /* 0xB0 */ s32 unkB0;   //state?
    /* 0xB4 */ struct ObjGroup* unkB4;  // attach group? unused group of particles
    /* 0xB8 */ s32 unkB8;   //attached arg0; "AttFlag"
    /* 0xBC */ struct ObjHeader *unkBC; //attached obj? looks like can be a Light or Camera
}; /* sizeof = 0xC0 */

struct ObjShape {
    /* 0x00 */ struct ObjHeader header;
    /* 0x14 */ struct ObjShape* prevShape;
    /* 0x18 */ struct ObjShape* nextShape;
    /* 0x1C */ struct ObjGroup* faceGroup;  /* face group; based on get_3DG1_shape */
    /* 0x20 */ struct ObjGroup* vtxGroup;  /* vtx group; based on get_3DG1_shape */
    /* 0x24 */ struct ObjGroup* unk24; /* group for type 2 shapenets only ? */
    /* 0x28 */ u8 pad28[4];
    /* 0x2C */ struct ObjGroup* mtlGroup;  /* what does this group do? materials? */
    /* 0x30 */ s32 unk30;
    /* 0x34 */ s32 faceCount;   /* face count? based on get_3DG1_shape */
    /* 0x38 */ s32 vtxCount;   /* vtx count? based on get_3DG1_shape */
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ u32 id;
    /* 0x44 */ s32 unk44;       //group?, no a flag!?
    /* 0x48 */ s32 unk48[3];
    /* 0x54 */ u8  pad54[0x58-0x54]; // part of above array??
    /* 0x58 */ f32 unk58;       // paramF?
    /* 0x5C */ char name[0x9c-0x5c];
}; /* sizeof = 0x9C */

/* These are the "objects" pointed to by Links in the faceGroup and vtxGroup */
struct GdFaceData {
    u32 count;
    s32 type;
    u16 (*data)[4]; //(unk, vtx ids[3])
};

struct GdVtxData {
    u32 count;
    s32 type;
    s16 (*data)[3]; //vtx points
};

struct ObjNet {
    /* 0x000 */ struct ObjHeader header;
    /* 0x014 */ struct MyVec3f unk14;   // position? d_set_initpos + d_set_world_pos; print_net says world
    /* 0x020 */ struct MyVec3f unk20;   // position? d_set_initpos? attached offset? dynamic? scratch?
    /* 0x02C */ u8  pad2c[0x34-0x2C];
    /* 0x034 */ s32 unk34;       // "dflags"?
    /* 0x038 */ u32 unk38;      // some sort of id? from move_net
    /* 0x03C */ s32 unk3C;      // state flags?
    /* 0x040 */ s32 unk40;      // "colour"
    /* 0x044 */ struct MyVec3f unk44;   // "force"
    /* 0x050 */ struct MyVec3f unk50;   // velocity
    /* 0x05C */ struct MyVec3f unk5C;   // rotation
    /* 0x068 */ struct MyVec3f unk68;   //initial rotation?
    /* 0x074 */ struct MyVec3f unk74;   // "collDisp"
    /* 0x080 */ struct MyVec3f unk80;   // "collTorque"
    /* 0x08C */ struct MyVec3f unk8C;   // "CollTorqueL"
    /* 0x098 */ struct MyVec3f unk98;   // "CollTorqueD"
    /* 0x0A4 */ struct MyVec3f unkA4;   // torque
    /* 0x0B0 */ struct MyVec3f unkB0;   // "CofG" center of gravity?
    /* 0x0BC */ struct GdPlaneF unkBC;  // bounding box
    /* 0x0D4 */ struct MyVec3f unkD4;   // "CollDispOff"
    /* 0x0E0 */ f32 unkE0;              // "CollMaxD"
    /* 0x0E4 */ f32 unkE4;              // "MaxRadius"
    /* 0x0E8 */ Mat4 matE8;
    /* 0x128 */ Mat4 mat128;
    /* 0x168 */ Mat4 mat168;             // "rotation matrix"
    /* 0x1A8 */ struct ObjShape *unk1A8; // "ShapePtr"
    /* 0x1AC */ struct MyVec3f unk1AC;   // scale
    /* 0x1B8 */ f32 unk1B8;              // "Mass"
    /* 0x1BC */ s32 unk1BC;              // "NumModes"
    /* 0x1C0 */ struct ObjGroup *unk1C0;
    /* 0x1C4 */ struct ObjGroup *skinGrp;   // SkinGroup (from reset_weight) (joints and bones)
    /* 0x1C8 */ struct ObjGroup *unk1C8;    // "node group"
    /* 0x1CC */ struct ObjGroup *unk1CC;    // plane group (only type 1?)
    /* 0x1D0 */ struct ObjGroup *unk1D0;    // vertex group
    /* 0x1D4 */ struct ObjGroup *unk1D4;    // attach group?
    /* 0x1D8 */ struct MyVec3f unk1D8;      // attached offset
    /* 0x1E4 */ s32 unk1E4;                 // d_attach_to arg 0; "AttFlag"
    /* 0x1E8 */ struct ObjHeader *unk1E8;   // attached obj?
    /* 0x1EC */ s32 netType;    // from move_net
    /* 0x1F0 */ struct ObjNet *unk1F0;  // or joint. guess from Unknown80192AD0
    /* 0x1F4 */ struct MyVec3f unk1F4;
    /* 0x200 */ struct MyVec3f unk200;
    /* 0x20C */ struct ObjGroup *unk20C;
    /* 0x210 */ s32 unk210;     // "control type"
    /* 0x214 */ u8  pad214[0x21C-0x214];
    /* 0x21C */ s32 transform;
}; /* sizeof = 0x220 */

struct ObjPlane {
    /* 0x00 */ struct ObjHeader header;
    /* 0x14 */ u32 id;
    /* 0x18 */ void* unk18;     // maybe?
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ struct GdPlaneF plane28; //position plane?
    /* 0x40 */ struct ObjFace* unk40;
}; /* sizeof = 0x44*/

struct ObjVertex {
    /* 0x00 */ struct ObjHeader header;
    /* 0x14 */ struct MyVec3f vec14;    //position? 
    /* 0x20 */ struct MyVec3f vec20;    // rel position? world pos?
    /* 0x2C */ struct MyVec3f vec2C;    // normal?
    /* 0x38 */ s16 unk38;   // id
    /* 0x3A */ u8  pad3A[2];
    /* 0x3C */ f32 unk3C;
    /* 0x40 */ f32 unk40;
    /* 0x44 */ struct VtxLink *unk44;
}; /* sizeof = 0x48 */

struct VtxLink {
    struct VtxLink *prev;
    struct VtxLink *next;
    struct VtxLinkData *data;
};

struct VtxLinkData {
    s16 unk00[6]; 
    // s16 vec[3]; ?
    // s16 norm[3]; ?
    u8 unkC; // sub struct?
    u8 unkD;
    u8 unkE;
    u8 unkF;
};

struct ObjFace {
    /* 0x00 */ struct ObjHeader header;
    /* 0x14 */ struct MyVec3f vec14;    // rgb color?
    /* 0x20 */ s32 unk20;   // "colour" index
    /* 0x24 */ struct MyVec3f vec24;    //normal?
    /* 0x30 */ s32 vtxCount;
    /* 0x34 */ struct ObjVertex* vertices[4];   // these can also be s32 indices? which are then replaced by `find_thisface_verts`
    /* 0x44 */ s32 unk44; // material? initialize to -1
    /* 0x48 */ struct ObjMaterial* unk48; // initialize to NULL
}; /* sizeof = 0x4C */

struct ObjCamera {
    /* 0x000 */ struct ObjHeader header;
    /* 0x014 */ struct MyVec3f unk14;   // position vec? from d_set_initpos
    /* 0x020 */ struct ObjCamera* prev;
    /* 0x024 */ struct ObjCamera* next;
    /* 0x028 */ s32 id;
    /* 0x02C */ s32 unk2C;   // flag of some sort
    /* 0x030 */ struct ObjHeader* unk30;   // pointer to some type of object
    /* 0x034 */ struct MyVec3f unk34;
    /* 0x040 */ struct MyVec3f unk40;   // relative position related?
    /* 0x04C */ struct MyVec3f unk4C;
    /* 0x058 */ f32 unk58;      // MyVec3f ?
    /* 0x05C */ u8  pad5C[0x4];
    /* 0x060 */ f32 unk60;
    /* 0x064 */ Mat4 unk64;    //matrix4x4
    /* 0x0A4 */ f32 unkA4;
    /* 0x0A8 */ Mat4 unkA8;    //matrix4x4
    /* 0x0E8 */ Mat4 unkE8;
    /* 0x128 */ struct MyVec3f unk128;  //possibly
    /* 0x134 */ struct MyVec3f unk134;
    /* 0x140 */ struct MyVec3f unk140;  // another rel position related vec?
    /* 0x14C */ struct MyVec3f unk14C;  // another rel position related vec (*1.5)?
    /* 0x158 */ struct MyVec3f unk158;  // another rel position related vec (*2.0)?
    /* 0x164 */ u8  pad164[0x170 - 0x164];
    /* 0x170 */ s32 unk170; // type flag maybe?
    /* 0x174 */ s32 unk174;
    /* 0x178 */ f32 unk178;
    /* 0x17C */ f32 unk17C;
    /* 0x180 */ struct MyVec3f unk180;
    /* 0x18C */ struct ObjView* unk18C;
}; /* sizeof = 0x190 */

struct ObjMaterial {
    /* 0x00 */ struct ObjHeader header;
    /* 0x14 */ u8  pad14[0x1c-0x14];
    /* 0x1C */ s32 unk1C;   // id
    /* 0x20 */ char name[8];
    /* 0x28 */ s32 unk28;   // type
    /* 0x2C */ u8  pad2C[4];
    /* 0x30 */ struct MyVec3f unk30;    // ambient color (Ka)?
    /* 0x3C */ struct GdColour Kd;      // diffuse color (Kd)?
    /* 0x48 */ u8  pad48[0x58-0x48];
    /* 0x58 */ void *unk58; //set by d_usetexture; never seems to be non-null though.
    /* 0x5C */ s32 unk5C;
}; /* sizeof = 0x60 */

struct ObjWeight {
    /* 0x00 */ struct ObjHeader header;
    /* 0x14 */ u8  pad14[0x8];
    /* 0x1C */ s32 id;   //id
    /* 0x20 */ struct MyVec3f vec20;    //based on func_80181894? maybe a GdPlaneF?
    /* 0x2C */ u8  pad2C[0x38-0x2c];
    /* 0x38 */ f32 unk38;
    /* 0x3C */ struct ObjVertex* unk3C;
}; /* sizeof = 0x40 */

/* This union is used in ObjGadget for a variable typed field.
** The type can be found by checking group unk4C */
union ObjVarVal {
    s32 i;
    f32 f;
    u64 l;
};

struct ObjGadget {
    /* 0x00 */ struct ObjHeader header;
    /* 0x14 */ struct MyVec3f unk14;    // "world" position vec?
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;   // type?
    /* 0x28 */ f32 unk28;
    /* 0x2C */ u8 pad2C[4];
    /* 0x30 */ union ObjVarVal varval; //retype and rename varval30
    /* 0x38 */ f32 unk38;   //range left?
    /* 0x3C */ f32 unk3C;   //range right?
    /* 0x40 */ struct MyVec3f unk40;   // scale?
    /* 0x4C */ struct ObjGroup *unk4C; //gfroup->link->obj = valptr for var30 ?
    /* 0x50 */ struct ObjShape *unk50;
    /* 0x54 */ struct ObjGroup *unk54;  //node group?
    /* 0x58 */ u8 pad58[4];
    /* 0x5C */ s32 unk5C;
}; /* sizeof = 0x60 */

struct ObjView {
    /* 0x00 */ struct ObjHeader header;
    /* 0x14 */ u8  pad14[0x8];
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ struct ObjCamera* unk24;
    /* 0x28 */ struct ObjGroup* unk28;     // camera group?
    /* 0x2C */ struct ObjGroup* unk2C;
    /* 0x30 */ struct ObjJoint* unk30;    // seems to be an ObjJoint?
    /* 0x34 */ s32 unk34;   // state flags?
    /* 0x38 */ s32 unk38;
    /* 0x3C */ struct MyVec3f unk3C;    // position vec? d_set_world_pos
    /* 0x48 */ f32 unk48;
    /* 0x4C */ f32 unk4C;
    /* 0x50 */ u8  pad50[0x4];
    /* 0x54 */ struct MyVec3f unk54;    // scale?
    /* 0x60 */ struct MyVec3f unk60;
    /* 0x6C */ char *unk6C;
    /* 0x70 */ s32 unk70;   // gd_startdisplist id?
    /* 0x74 */ u8  pad74[4];
    /* 0x78 */ s32 unk78;
    /* 0x7C */ struct MyVec3f unk7C;
    /* 0x88 */ u8  pad88[0x10];
    /* 0x98 */ void (*unk98)(struct ObjView *);   // Never non-null in game...?
    /* 0x9C */ s32 unk9C;
}; /* sizeof = 0xA0 */

struct ObjLabel {
    /* 0x00 */ struct ObjHeader header;
    /* 0x14 */ struct MyVec3f vec14;
    /* 0x20 */ char *fmtstr;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ struct ObjValPtrs *valptr;
    /* 0x2C */ void (*valfn)(union ObjVarVal *, union ObjVarVal);
    /* 0x30 */ s32 unk30;       // state or type?
}; /* sizeof = 0x34 */

struct ObjAnimator {
    /* 0x00 */ struct ObjHeader header;
    /* 0x14 */ struct ObjGroup* unk14;
    /* 0x18 */ struct ObjGroup* animdata;  //animation data? a group, but the link points to something weird..
    /* 0x1C */ u8  pad1C[0x4];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ u8  pad2C[4];
    /* 0x30 */ struct ObjGroup* unk30;  //attached group?
    /* 0x34 */ s32 unk34;   //attach arg0
    /* 0x38 */ u8  pad38[0x44-0x38];
    /* 0x44 */ struct ObjHeader* unk44;   //attached object? Normally another Objanimator?
    /* 0x48 */ void (*fn48) (struct ObjAnimator*);
    /* 0x4C */ s32 unk4C;   //state enum? 
    /* 0x50 */ s32 unk50;
    /* 0x54 */ s32 unk54;
}; /* sizeof = 0x58 */

/* Animation Data Types */
enum GdAnimations {
    GD_ANIM_EMPTY     = 0,  // Listed types are how the data are arranged in memory; maybe not be exact type
    GD_ANIM_MATRIX    = 1,  // f32[4][4]
    GD_ANIM_TRI_F_2   = 2,  // f32[3][3]
    GD_ANIM_9H        = 3,  // s16[9]
    GD_ANIM_TRI_F_4   = 4,  // f32[3][3]
    GD_ANIM_STUB      = 5,  
    GD_ANIM_3H_SCALED = 6,  // s16[3]
    GD_ANIM_3H        = 7,  // s16[3]
    GD_ANIM_6H_SCALED = 8,  // s16[6]
    GD_ANIM_MTX_VEC   = 9,  // {f32 mtx[4][4]; f32 vec[3];}
    GD_ANIM_CAMERA    = 11  // s16[6]
};
/* This struct is pointed to by the `obj` field in Links struct in the `animdata` ObjGroup */
struct AnimDataInfo {
    s32 count;  // count or -1 for end of array of AnimDataInfo structures
    enum GdAnimations type;  // types are used in "move_animator"
    void* data; // points to an array of `type` data
};
/* GD_ANIM_MTX_VEC (9) type */
struct AnimMtxVec {
    /* 0x00 */ Mat4 matrix;
    /* 0x40 */ struct MyVec3f vec;  // seems to be a scale vec
};

enum ValPtrType {
    OBJ_VALUE_INT   = 1,
    OBJ_VALUE_FLOAT = 2
};

struct ObjValPtrs {
    /* 0x00 */ struct ObjHeader header;
    /* 0x14 */ struct ObjHeader *obj;   // maybe just a void *?
    /* 0x18 */ s32 offset;
    /* 0x1C */ enum ValPtrType datatype;
    /* 0x20 */ s32 unk20;       // obj type ptr enum? Might be OBJ_TYPES flags?
}; /* sizeof = 0x24 */

struct ObjLight {
    /* 0x00 */ struct ObjHeader header;
    /* 0x14 */ u8  pad0[0x8];
    /* 0x1C */ s32 unk1C;       // id
    /* 0x20 */ char name[8];
    /* 0x28 */ u8  pad28[4];
    /* 0x2C */ s32 unk2C;       // "dflags"?
    /* 0x30 */ f32 unk30;
    /* 0x34 */ u8  pad34[4];
    /* 0x38 */ f32 unk38;
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ s32 unk40;
    /* 0x44 */ u8  pad3[0x8];
    /* 0x4C */ s32 unk4C;
    /* 0x50 */ struct MyVec3f unk50;    // 0x50 to 0x90 -> Matrix?  diffuse color (Kd)?
    /* 0x5C */ struct MyVec3f unk5C;
    /* 0x68 */ struct MyVec3f unk68;
    /* 0x74 */ struct MyVec3f unk74;    // world position?
    /* 0x80 */ struct MyVec3f unk80;
    /* 0x8C */ struct MyVec3f unk8C;
    /* 0x98 */ s32 unk98;
    /* 0x9C */ struct ObjShape* unk9C;
}; /* sizeof = 0xA0 */

struct ObjZone {
    /* 0x00 */ struct ObjHeader header;
    /* 0x14 */ struct GdPlaneF unk14;
    /* 0x2C */ struct ObjGroup *unk2C;   // plane group?
    /* 0x30 */ struct ObjGroup *unk30;   // guess based on Unknown801781DC; might have to change later
    /* 0x34 */ u8  pad[4];
}; /* sizeof = 0x38*/

struct ObjUnk200000 {
    /* 0x00 */ struct ObjHeader header;
    /* 0x14 */ u8  pad14[0x30-0x14];
    /* 0x30 */ struct ObjVertex *unk30; //not sure; guessing for Unknown801781DC; 30 and 34 could switch with ObjZone
    /* 0x34 */ struct ObjFace *unk34;   //not sure; guessing for Unknown801781DC
}; /* sizeof = 0x38*/

#endif /* _GD_TYPES_H */
