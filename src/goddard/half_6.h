#ifndef _HALF_6_H_
#define _HALF_6_H_

#include "types.h"
#include "gd_types.h"

extern void calc_face_normal(struct ObjFace*);
extern struct ObjVertex* gd_make_vertex(f32, f32, f32);
extern void add_3_vtx_to_face(struct ObjFace*, struct ObjVertex*, struct ObjVertex*, struct ObjVertex*);
extern struct ObjShape* make_shape(s32, char*);
extern void func_8019834C(struct ObjShape*, f32, f32, f32);
extern struct ObjNet* make_netfromshape(struct ObjShape*);
extern void Proc80199FA0(struct ObjAnimator*);
extern void Proc8019A068(struct ObjAnimator*);
extern s32 func_8019A378(void (*aniFn)(struct ObjAnimator*));
extern void load_shapes2(void);

#ifndef _BAD_GD_DECLARATIONS_H_
/* have to erase type as it is called with f64, f64, f64 in dynlist code */
extern struct ObjFace* make_face_1(f32, f32, f32);
#endif

#endif /* _HALF_6_H_ */
