#ifndef _PRESS_START_HEAD_2_H
#define _PRESS_START_HEAD_2_H

#include "types.h"
#include "gd_types.h"

/****** .bss ******/
extern struct ObjNet* gGdSkinNet;   // D_801BAAF0

/****** Static .bss ******/
// struct ObjWeight* sSkinNetCurWeight; // D_801B9EA0
// Mat4 D_801B9EA8;
// struct ObjJoint* D_801B9EE8;
// s32 sTargetWeightID; // D_801BA960

/****** Possibly Declared Here But Not Used .bss ******/
// extern ? D_801B5D50;
// extern ? D_801B5D7C;

/* Temporary Structures: 
 * The first is probably an Obj type, 
 * and the second is some of Links or DataLink struct 
 */
struct ObjUnkFromNet1A8 {
    /* 0x00 */ struct ObjHeader header;
    /* 0x14 */ u32 pad14;
    /* 0x18 */ u32 pad18;
    /* 0x1C */ struct ObjUnkSub* ptr1C;
    /* 0x20 */ u32 pad20;
    /* 0x24 */ struct ObjUnkFromNet1A8* unk24;  //maybe?
};

/* This is similar to the Links struct from head_1, but the type of ptr at 0x8 is different */
struct ObjUnkSub {
    /* 0x00 */ void* unk00; //prev?
    /* 0x04 */ struct ObjUnkSub* next;
    /* 0x08 */ Mat4* mat08;
}; 

extern void func_80181760(struct ObjUnkFromNet1A8*);
extern void move_skin(struct ObjNet*);
extern void func_80181894(struct ObjJoint*);
extern void Unknown80181B88(struct ObjJoint*);

// extern void Unknown801815E0(Mat4*);
// extern void Unknown801819D0(struct ObjVertex*);
// extern void reset_weight(struct ObjWeight*);

#endif /* _PRESS_START_HEAD_2_H */
