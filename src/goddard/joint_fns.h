#ifndef _JOINT_FUNCTIONS_H_
#define _JOINT_FUNCTIONS_H_

#include <types.h>
#include "gd_types.h"

// extern ? func_8018E3A0(?);
extern s32 func_8018E3D8(char*, u32, struct GdFile*);   /* gd_read_file? gd_fgets? */
// extern ? Proc8018E520(?);
extern void Proc8018EBE8(struct ObjJoint*);
// extern ? Unknown8018EE5C(?);
// extern ? func_8018EF78(?);
extern struct ObjJoint *make_joint(s32, f32, f32, f32);
extern struct ObjJoint* func_8018F248(void*, s32, f32, f32, f32);
// extern ? func_8018F328(?);
// extern ? Unknown8018F4CC(?);
// extern ? func_8018F520(?);
// extern ? func_8018F89C(?);
// extern ? Unknown8018FA68(?);
extern s32 func_8018FAC8(struct ObjJoint *, s32, struct ObjVertex *, f32);
// extern ? func_8018FB58(?);
extern void add_joint2bone(struct ObjBone *, struct ObjJoint *);
extern struct ObjJoint *make_bone(s32, struct ObjHeader *, struct ObjHeader *, s32);
// extern ? Unknown8018FF14(?);
// extern ? Unknown8018FF28(?);
// extern ? Unknown8018FF88(?);
// extern ? func_8018FFE8(?);
// extern ? func_80190168(?);
// extern ? func_801903E8(?);
// extern ? func_80190574(?);
// extern ? func_801909B4(?);
// extern ? Unknown80190A20(?);
// extern ? func_80190B54(?);
// extern ? Unknown80190E68(?);
// extern ? func_80190F3C(?);
// extern ? Unknown801911A8(?);
// extern ? Unknown80191220(?);
// extern ? Unknown801913C0(?);
// extern ? Unknown801913F0(?);
// extern ? Unknown801914F8(?);
// extern ? Unknown8019150C(?);
extern void func_80191604(struct ObjHeader*);   // maybe a ObjJoint
// extern ? Unknown80191824(?);
// extern ? Unknown801918F4(?);
// extern ? Unknown80191A1C(?);
// extern ? Unknown80191BF8(?);
// extern ? Unknown80191D60(?);
// extern ? Unknown80191E54(?);
// extern ? func_80191E88(?);
extern void func_80191EE8(void);

#endif /* _JOINT_FUNCTIONS_H_ */
