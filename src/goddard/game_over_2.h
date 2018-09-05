#ifndef _GAME_OVER_2_H
#define _GAME_OVER_2_H

#include "gd_types.h"

// this is unused, but it's need to be declared before D_801B9BB8
extern u8 gdUnused801B9B30[0x88];
extern struct ObjGroup *D_801B9BB8;  // ObjGroup* of ObjLights

extern void Proc80178900(struct ObjLight *);
extern void draw_material(struct ObjMaterial *);
extern Vec3f *func_80178D98(int);
extern void draw_face(struct ObjFace *);
extern void Proc80179350(struct ObjLabel *);
extern void Proc80179628(struct ObjNet *);
extern void Proc8017976C(struct ObjGadget *);
extern void draw_camera(struct ObjCamera *);
extern void func_80179B9C(struct MyVec3f *, struct ObjCamera *, struct ObjView *);
extern void nop_obj_draw(struct ObjHeader *);
extern void Proc8017A30C(struct ObjHeader *);
extern void Proc8017A550(struct ObjHeader *);
extern void Proc8017A6A4(struct ObjHeader *);
extern void draw_group(struct ObjGroup *);
extern void Proc8017A818(struct ObjHeader *);
extern void apply_obj_draw_fn(struct ObjHeader *);
extern void func_8017B028(struct ObjGroup *);
extern void func_8017B064(struct ObjGroup *, struct ObjGroup *);
extern void map_vertices(struct ObjGroup *, struct ObjGroup *);
extern void update_view(struct ObjView *);

#endif /* _GAME_OVER_2_H */
