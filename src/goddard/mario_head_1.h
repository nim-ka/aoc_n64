#ifndef _MARIO_HEAD_1_H_
#define _MARIO_HEAD_1_H_

#include "types.h"
#include "gd_types.h"

/****** RW .rodata? (Probably data) ******/
extern f32 D_801A81C0;
extern f32 D_801A81C4;

/****** .bss ******/
extern struct MyVec3f D_801B9DA0;       /* Are these just one GdPlaneF ? */
extern struct MyVec3f D_801B9DAC;
extern void* D_801B9DB8;
extern struct ObjView* D_801B9DBC;
extern Mat4 D_801B9DC8;
extern struct MyVec3f D_801B9E08;
extern struct ObjGroup* D_801B9E14;
extern s32 D_801B9E44;
extern Mat4* D_801B9E48;
extern struct ObjCamera* D_801B9E4C;    /* cameraHead? */
extern void* D_801B9E50;
extern struct ObjGroup* D_801B9E54;     /* group head? */
extern s32 D_801B9E58;                  /* obj count? */
extern s32 D_801B9E5C;                  /* group count? */
extern s32 D_801B9E60;                  /* PlaneCount? */
extern s32 D_801B9E64;                  /* cameraCount? */
extern struct Unk801B9E68 D_801B9E68;   /* count in first member? */
extern void* D_801B9E80;
extern void* D_801B9E84;
extern void* D_801B9E88;
extern struct ObjHeader* D_801B9E8C;    /* head pointer to list of objects? */
extern struct ObjGroup* D_801B9E90;     /* curGroup? */

/****** Unused but probably original declared here .bss ******/
//D_801B9DC0 (size=4)
//D_801B9DC4 (size=4)
//D_801B9E18 (size=4)
//D_801B9E1C (size=4)
//D_801B9E20 (size=8)
//D_801B9E28 (size=4)
//D_801B9E2C (size=4)
//D_801B9E30 (size=4)
//D_801B9E34 (size=4)
//D_801B9E38 (size=4)
//D_801B9E3C (size=4)
//D_801B9E40 (size=4)

/****** Functions ******/
extern void func_8017BCB0(void);
extern void func_8017BD20(void*);
extern void func_8017BE60(struct GdPlaneF*);
extern void func_8017BED0();
extern const char* get_obj_name_str(enum ObjTypeFlag);
extern struct ObjHeader* make_object(enum ObjTypeFlag);
extern void make_zone(s32, struct GdPlaneF*, s32);
extern struct ObjUnk200000* Unknown8017C7A0(s32, s32);
extern struct Links* make_link_to_obj(struct Links*, struct ObjHeader*);
extern void* make_link_2();   //struct Links* make_link_2(struct Links*, struct ObjHeader*)
extern struct ObjValPtrs* make_valptrs(void*, void*, void*, void*);
extern void reset_plane(struct ObjPlane*);
extern struct ObjPlane* make_plane(void*, struct ObjPlaneSub*);
extern struct ObjCamera* make_camera(s32, struct ObjHeader*);
extern struct ObjMaterial* make_material(UNUSED s32, char*, s32);
extern struct ObjLight* make_light(s32, char*, s32);
extern struct ObjView* make_view(s32, s32, s32, s32, s32, s32, s32, struct ObjGroup*);
extern struct ObjAnimator* make_animator(void);
extern struct ObjWeight* make_weight(UNUSED s32, s32, struct ObjVertex*, f32);
extern struct ObjGroup* make_group_of_type(enum ObjTypeFlag, struct ObjHeader*, struct ObjHeader*);
extern void sprint_obj_id(char*, struct ObjHeader*);
extern struct ObjGroup* make_group();   // arg might be struct passed by value?
extern void addto_group(struct ObjGroup*, struct ObjHeader*);
extern void addto_groupfirst(struct ObjGroup*, struct ObjHeader*);
extern s32 group_contains_obj(struct ObjGroup*, struct ObjHeader*);
extern void show_details(enum ObjTypeFlag);
extern s32 Unknown8017E1E8(void);
extern s32 func_8017E20C(void);
extern void gd_loadtexture(struct ObjHeader*);
extern void func_8017E2B8(void);
extern struct ObjHeader* UnknownRecursive8017E2F0(struct ObjHeader*, enum ObjTypeFlag);
extern s32 apply_to_obj_types_in_group();   //s32 apply_to_obj_types_in_group(s32, void (*)(void *), struct ObjGroup*)
extern void func_8017E584(struct ObjJoint*, struct MyVec3f*, struct MyVec3f*);
extern void func_8017E838(struct ObjJoint*, struct MyVec3f*, struct MyVec3f*);
extern void func_8017E9EC(struct ObjJoint*);
extern s32 Unknown8017EA94(struct MyVec3f*, Mat4);
extern s32 Unknown8017EB24(struct ObjHeader*, struct ObjHeader*);
extern s32 Unknown8017ED00(struct ObjHeader*, struct GdPlaneF*);
extern s32 Unknown8017EDCC(struct MyVec3f*, struct GdPlaneF*);
extern s32 Unknown8017EE5C(struct GdPlaneF*, struct GdPlaneF*);
extern s32 func_8017F054(struct ObjHeader*, struct ObjHeader*);
extern s32 UnknownRecursive8017F210(struct ObjHeader*, struct ObjHeader*);
//extern void Unknown8017F3CC(struct Unk8017F3CC*);
extern void func_8017F404(f32, struct ObjHeader*, struct ObjHeader*);
extern void func_8017F424(struct GdTriangleF*, struct GdTriangleF*, f32);
extern void move_animator(struct ObjAnimator*);
extern void Unknown80180624(struct ObjHeader*);
extern void move_animators(struct ObjGroup* group);
extern void func_80180974();    //void func_80180974(struct ObjGroup*)
extern void Unknown801809B0(struct ObjCamera*);
extern void func_80180FD4(struct ObjGroup*);
extern void Unknown8018100C(struct ObjLight*);
extern void func_80181378(struct ObjGroup*);
extern void func_80181378(struct ObjGroup*);
extern void func_8018145C();    //void func_8018145C(struct ObjView*)
extern void func_801814F4(struct ObjGroup*);    /* applies a function to ObjGadgets in group */
extern void null_obj_lists(void);

#endif /* _MARIO_HEAD_1_H_ */
