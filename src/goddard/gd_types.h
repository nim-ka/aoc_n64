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

/* based on fields set in gd_fopen; func_8019BC18(84) for size */
struct GdFile {
    /* 0x00 */ u8  pad00[4];
    /* 0x04 */ u32 unk04;
    /* 0x08 */ u32 unk08;
    /* 0x0C */ u32 unk0C;   /* some sort of bit field */
    /* 0x10 */ u8  pad10[0x50-0x10];
    /* 0x50 */ u32 unk50;
}; /* sizeof() = 0x54 */

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
    /* 0x2C */ s32 debugPrint;
    /* 0x30 */ s32 unk30;
    /* 0x34 */ char name[0x40]; // possibly, old code only
    /* 0x74 */ s32 id;
}; /* sizeof = 0x78 */

struct ObjBone {
    /* 0x000 */ struct ObjHeader header;
    /* 0x014 */ struct MyVec3f unk14;   // from dead code in Proc8017A550
    /* 0x020 */ struct ObjBone* prev;   //maybe, based on make_bone
    /* 0x024 */ struct ObjBone* next;   //maybe, based on make_bone 
    /* 0x028 */ struct MyVec3f unk28;   // from dead code in Proc8017A550
    /* 0x034 */ u8  pad34[0x70-0x34];
    /* 0x070 */ Mat4 unk70;
    /* 0x0B0 */ u8  padB0[0xf0-0xb0];
    /* 0x0F0 */ struct ObjShape* unkF0; // from dead code in Proc8017A550
    /* 0x0F4 */ u8  padF4[4];
    /* 0x0F8 */ f32 unkF8;              // from dead code in Proc8017A550
    /* 0x0FC */ u8  padFC[4];
    /* 0x100 */ s32 unk100;             // from dead code in Proc8017A550
    /* 0x104 */ u8  pad104[4];
    /* 0x108 */ s32 id;
    /* 0x10C */ struct ObjGroup* unk10C;
    /* 0x110 */ u8  pad110[0x14];
}; /* sizeof = 0x124 */

struct ObjJoint {
    /* 0x000 */ struct ObjHeader header;
    /* 0x014 */ u8  pad14[0x20-0x14];
    /* 0x020 */ struct ObjShape* unk20;
    /* 0x024 */ u8  pad24[0x2C-0x24];
    /* 0x02C */ void (*fn2C)(struct ObjJoint*);
    /* 0x030 */ u8  pad30[0x74-0x30];
    /* 0x074 */ struct MyVec3f unk74;
    /* 0x080 */ struct MyVec3f unk80;
    /* 0x08C */ u8  pad8C[0x18];
    /* 0x0A4 */ struct MyVec3f unkA4;   // possible, only in func_8017E9EC
    /* 0x0B0 */ struct MyVec3f unkB0;
    /* 0x0BC */ u8  padBC[0x2C];
    /* 0x0E8 */ Mat4 matE8;     //matrix4x4
    /* 0x128 */ Mat4 mat128;    // "r matrix"
    /* 0x168 */ Mat4 mat168;    // "i matrix"
    /* 0x1A8 */ u8  pad1a8[0x1b4-0x1a8];
    /* 0x1B4 */ s32 id;
    /* 0x1B8 */ u8  pad1B8[0xC];
    /* 0x1C4 */ struct ObjGroup* unk1C4;
    /* 0x1C8 */ s32 unk1C8;
    /* 0x1CC */ u8  pad1CC[4];
    /* 0x1D0 */ struct ObjAnimator* unk1D0;
    /* 0x1D4 */ u8  pad1D4[0x1f4-0x1d4];
    /* 0x1F4 */ struct ObjGroup* unk1F4;   //Group of ObjWeights, only?
    /* 0x1F8 */ struct ObjGroup* unk1F8;
    /* 0x1FC */ u8  pad1F8[0x22c-0x1FC];
}; /* sizeof = 0x22C */

struct ObjParticle {
    /* 0x00 */ struct ObjHeader header;
    /* 0x14 */ u8 pad14[0x1C-0x14];
    /* 0x1C */ struct ObjShape* unk1C;     // looks like a shape...
    /* 0x20 */ f32 unk20;   //vec?
    /* 0x24 */ f32 unk24;
    /* 0x28 */ f32 unk28;   //vec?
    /* 0x2C */ u8 pad2C[0x30-0x2C];
    /* 0x30 */ f32 unk30;
    /* 0x34 */ u8 pad34[0x38-0x34];
    /* 0x38 */ struct MyVec3f unk38;
    /* 0x44 */ f32 unk44; //not vec?
    /* 0x48 */ f32 unk48; //not vec?
    /* 0x4C */ u8 pad4C[0x50-0x4C];
    /* 0x50 */ s32 id;
    /* 0x54 */ u32 unk54;
    /* 0x58 */ s32 unk58;
    /* 0x5C */ s32 unk5C;
    /* 0x60 */ s32 unk60;   //flag?
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
    /* 0xB4 */ struct ObjGroup* unkB4;  // unused group of particles
    /* 0xB8 */ u8 padB8[4];
    /* 0xBC */ struct ObjCamera* unkBC; //maybe? looks like can be a Light or Camera
}; /* sizeof = 0xC0 */

struct ObjShape {
    /* 0x00 */ struct ObjHeader header;
    /* 0x14 */ struct ObjShape* prevShape;
    /* 0x18 */ struct ObjShape* nextShape;
    /* 0x1C */ struct ObjGroup* faceGroup;  /* face group; based on get_3DG1_shape */
    /* 0x20 */ struct ObjGroup* vtxGroup;  /* vtx group; based on get_3DG1_shape */
    /* 0x24 */ u8  pad24[0x2c-0x24];
    /* 0x2C */ struct ObjGroup* mtlGroup;  /* what does this group do? materials? */
    /* 0x30 */ s32 unk30;
    /* 0x34 */ s32 faceCount;   /* face count? based on get_3DG1_shape */
    /* 0x38 */ s32 vtxCount;   /* vtx count? based on get_3DG1_shape */
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ u32 id;
    /* 0x44 */ s32 unk44; //group?, no a flag!?
    /* 0x48 */ s32 unk48[3];
    /* 0x54 */ u8  pad54[0x58-0x54]; // part of above array??
    /* 0x58 */ f32 unk58;
    /* 0x5C */ char name[0x9c-0x5c];
}; /* sizeof = 0x9C */

struct ObjNet {
    /* 0x000 */ struct ObjHeader header;
    /* 0x014 */ u8  pad14[0x38-0x14];
    /* 0x038 */ u32 unk38;      // some sort of id? from Unknown8019359C
    /* 0x03C */ s32 unk3C;      // state flags?
    /* 0x040 */ s32 unk40;
    /* 0x044 */ u8  pad44[0xBC-0x44];
    /* 0x0BC */ struct GdPlaneF unkBC;
    /* 0x0D4 */ u8  padD4[0xe8-0xd4];
    /* 0x0E8 */ Mat4 matE8;
    /* 0x128 */ Mat4 mat128;
    /* 0x168 */ Mat4 mat168;    // "r matrix"
    /* 0x1A8 */ struct ObjHeader *unk1A8;    // variable pointer based on netType...?
    /* 0x1AC */ u8  pad1ac[0x1c0-0x1ac];
    /* 0x1C0 */ struct ObjGroup *unk1C0;
    /* 0x1C4 */ struct ObjGroup *skinGrp;    // SkinGroup (from reset_weight) 
    /* 0x1C8 */ struct ObjGroup *unk1C8;    // based on make_net call in func_8019A378; Particle group (only type 1?)
    /* 0x1CC */ struct ObjGroup *unk1CC;    // plane group (only type 1?)
    /* 0x1D0 */ u8  pad1d0[0x1ec-0x1d0];
    /* 0x1EC */ s32 netType;    // from Unknown8019359C
    /* 0x1F0 */ u8  pad1f0[0x220-0x1f0];
}; /* sizeof = 0x220 */
/* Net Types (+0x1ec) -> (ptr type at 0x1a8): (from Unknown8019359C)
    1: shape -> ObjShape (info from: make_netfromshape "make_netfromshape")
    2: skin -> move_skin
    3: joint? -> ObjJoint (info from: func_8019A378->make_net call)
    4: bone -> ObjBone (info from: func_80192C5C)
    5: ?
    6: ?
    7: ?
*/

struct ObjPlane {
    /* 0x00 */ struct ObjHeader header;
    /* 0x14 */ u32 id;
    /* 0x18 */ void* unk18;     // maybe?
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ struct GdPlaneF plane28;
    /* 0x40 */ struct ObjFace* unk40;
}; /* sizeof = 0x44*/

struct ObjVertex {
    /* 0x00 */ struct ObjHeader header;
    /* 0x14 */ struct MyVec3f vec14;
    /* 0x20 */ struct MyVec3f vec20;
    /* 0x2C */ struct MyVec3f vec2C;
    /* 0x38 */ s16 unk38;
    /* 0x3A */ u8  pad3A[2];
    /* 0x3C */ f32 unk3C;
    /* 0x40 */ f32 unk40;
    /* 0x44 */ s32 unk44;
}; /* sizeof = 0x48 */

struct ObjFace {
    /* 0x00 */ struct ObjHeader header;
    /* 0x14 */ struct MyVec3f vec14;
    /* 0x20 */ u8  pad20[0x24-0x20];
    /* 0x24 */ struct MyVec3f vec24;    //normal?
    /* 0x30 */ s32 vtxCount;
    /* 0x34 */ struct ObjVertex* vertices[4];   // these can also be s32 indices? which are then replaced by `find_thisface_verts`
    /* 0x44 */ s32 unk44; // initialize to -1
    /* 0x48 */ struct ObjMaterial* unk48; // initialize to NULL
}; /* sizeof = 0x4C */

struct ObjCamera {
    /* 0x000 */ struct ObjHeader header;
    /* 0x014 */ struct MyVec3f unk14;
    /* 0x020 */ struct ObjCamera* prev;
    /* 0x024 */ struct ObjCamera* next;
    /* 0x028 */ s32 id;
    /* 0x02C */ s32 unk2C;   // flag of some sort
    /* 0x030 */ struct ObjHeader* unk30;   // pointer to some type of object
    /* 0x034 */ struct MyVec3f unk34;
    /* 0x040 */ struct MyVec3f unk40;
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
    /* 0x140 */ struct MyVec3f unk140;
    /* 0x14C */ u8  pad14C[0x170 - 0x14C];
    /* 0x170 */ s32 unk170;
    /* 0x174 */ s32 unk174;
    /* 0x178 */ f32 unk178;
    /* 0x17C */ f32 unk17C;
    /* 0x180 */ struct MyVec3f unk180;
    /* 0x18C */ struct ObjView* unk18C;
}; /* sizeof = 0x190 */

struct ObjMaterial {
    /* 0x00 */ struct ObjHeader header;
    /* 0x14 */ u8  pad14[8];
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ char name[8];
    /* 0x28 */ s32 unk28;
    /* 0x2C */ u8  pad2C[0x3C-0x2C];
    /* 0x3C */ struct MyVec3f vec3C;    // normal?
    /* 0x48 */ u8  pad48[0x5C-0x48];
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
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ u8 pad1C[4];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ u8 pad2C[4];
    /* 0x30 */ union ObjVarVal varval; //retype and rename varval30
    /* 0x38 */ f32 unk38;   //range left?
    /* 0x3C */ f32 unk3C;   //range right?
    /* 0x40 */ f32 unk40;
    /* 0x44 */ f32 unk44;
    /* 0x48 */ f32 unk48;
    /* 0x4C */ struct ObjGroup *unk4C; //group->link->obj = valptr for var30 ?
    /* 0x50 */ u8 pad50[0x5c-0x50];
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
    /* 0x3C */ f32 unk3C;
    /* 0x40 */ f32 unk40;
    /* 0x44 */ u8  pad44[0x4];
    /* 0x48 */ f32 unk48;
    /* 0x4C */ f32 unk4C;
    /* 0x50 */ u8  pad50[0x4];
    /* 0x54 */ f32 unk54;       // is this a vec3f?
    /* 0x58 */ f32 unk58;
    /* 0x5C */ u8  pad5C[0x4];
    /* 0x60 */ struct MyVec3f unk60;
    /* 0x6C */ s32 unk6C;
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
    /* 0x18 */ struct SubAnim1* unk18;  //animation data?
    /* 0x1C */ u8  pad1C[0x4];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ u8  pad2C[0x18];
    /* 0x44 */ struct ObjAnimator* unk44;   //maybe
    /* 0x48 */ void (*fn48) (struct ObjAnimator*);
    /* 0x4C */ s32 unk4C;   //state enum? 
    /* 0x50 */ s32 unk50;
    /* 0x54 */ s32 unk54;
}; /* sizeof = 0x58 */

struct SubAnim1 {
    /* 0x00 */ u8 pad[0x1C];
    /* 0x1C */ struct SubAnim2* unk1C;
};

struct SubAnim2 {
    s32 unk00;  //prev??
    s32 unk04;  //next??
    struct SubAnim3* unk08; //ptr to array of data structs
};

struct SubAnim3 {
    s32 unk00;
    s32 type;   // types are "sort of" listed in "move_animator"
    void* data; // probably multiple of these structs, based on the data packet
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
    /* 0x20 */ s32 unk20;       // obj type ptr enum?
}; /* sizeof = 0x24 */

struct ObjLight {
    /* 0x00 */ struct ObjHeader header;
    /* 0x14 */ u8  pad0[0x8];
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ char name[8];
    /* 0x28 */ u8  pad28[4];
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ f32 unk30;
    /* 0x34 */ u8  pad34[4];
    /* 0x38 */ f32 unk38;
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ s32 unk40;
    /* 0x44 */ u8  pad3[0x8];
    /* 0x4C */ s32 unk4C;
    /* 0x50 */ struct MyVec3f unk50;    // 0x50 to 0x90 -> Matrix?
    /* 0x5C */ struct MyVec3f unk5C;
    /* 0x68 */ struct MyVec3f unk68;
    /* 0x74 */ struct MyVec3f unk74;
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

struct DebugCounters {
    u32 ctr0;
    u32 ctr1;
};

#endif /* _GD_TYPES_H */
