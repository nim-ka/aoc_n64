#ifndef _GD_DATA_801A8050_H_
#define _GD_DATA_801A8050_H_

#include "gd_types.h"

/* Header for all of the weird data types in rodata_801A8050.s. They are used
** across goddard's files, and they are not all rodata... */

extern s32 D_801A805C;
/* These are probably not vectors, as strings in the ROM 
** refer to them as "colours"; but for now, leaving as the common 
** three float array type, instead of declaring a custom type */
extern Vec3f D_801A8070;
extern Vec3f D_801A807C;
extern Vec3f D_801A8088;
extern Vec3f D_801A8094;
extern Vec3f D_801A80A0;
extern Vec3f D_801A80AC;
extern Vec3f D_801A80B8;
extern Vec3f D_801A80C4;
extern Vec3f D_801A80D0;
extern Vec3f D_801A80DC;
extern Vec3f D_801A80E8;
extern struct ObjCamera *D_801A80F8;
extern struct MyVec3f *D_801A80F4;
extern s32 D_801A8100;
extern struct MyVec3f *D_801A8104[];    // "GdColour" pointers
extern struct MyVec3f *D_801A8118[];    // "GdColour" pointers (white, black)
extern s32 D_801A81A0;
extern f32 D_801A81C0;
extern f32 D_801A81C4;
extern s32 D_801A81D4[25];
extern s32 D_801A8238[6];
extern struct DynObjInfo *gGdDynObjList; // @ 801A8250; info for all loaded/made dynobjs
extern struct ObjHeader *gDynListCurObj; // @ 801A8254
extern struct GdPlaneF gGdNullPlaneF;    // @ 801A8258
extern s32 gGdDynObjIdIsInt;             // @ 801A8270; str (0) or int (1) for Dyn Obj ID

// profiler_utils.c
extern s32 gNumRoutinesInStack;   // @ 801A8280
extern s32 D_801A8284[7];         // TODO: what is this array?
extern s32 gNumActiveMemTrackers; // @ 801A82A0
extern u32 gGdPrimarySeed;        // @ 801A82A4
extern u32 gGdSecondarySeed;      // @ 801A82A8
extern char gGdHexNumerals[16];   // @ 801A82AC
extern s32 gGdPadNumPrint;        // @ 801A82C0

// half_6.c
extern struct ObjGroup* D_801A82E0; //returned by load_dynlist
extern struct ObjShape *D_801A82E4;
extern void* D_801A82E8;  // same type as what load_dynlist returns
extern void* D_801A82EC;  //probably a pointer
extern void* D_801A82F0;  // same type as what load_dynlist returns

// head_6 ? or 04004F90.c dynlist
extern struct ObjShape *D_801A82F4;
extern struct ObjShape *D_801A82F8;

extern f64 D_801A8668;
extern s32 D_801A86B0;

#endif /* _GD_DATA_801A8050_H_ */
