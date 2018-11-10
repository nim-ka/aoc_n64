#ifndef _MATRIX_FUNCTIONS_H_
#define _MATRIX_FUNCTIONS_H_

#include <types.h>
#include "gd_types.h"

// extern ? gd_sqrt_f(?);
// extern ? func_80193B68(?);
extern void func_8019415C(Mat4*, struct MyVec3f*);
extern void func_80194220(Mat4*, struct MyVec3f*);
extern void func_801942E4(Mat4*, struct MyVec3f*);
extern void func_80194358(Mat4*, struct MyVec3f*, float);
extern f32 func_80194728(f32, f32);     /* min(f1, +/-f2)? */
extern void func_80194770(struct MyVec3f*, f32);
extern void func_80194880(f32, f32*, f32*);
// extern ? Unknown8019498C(?);
extern void func_80194A54(Mat4*, s32, f32);
extern f32 rss_vec3f(struct MyVec3f*);  // sqrt of sum of squares of vec<x,y,z>
extern s32 func_80194BF4();     //s32 func_80194BF4(struct MyVec3f*); into_unit_vec ?
extern void func_80194D14(struct MyVec3f*, struct MyVec3f*, struct MyVec3f*);
extern float func_80194DB8(); //extern float func_80194DB8(struct MyVec3f *, struct MyVec3f *);
// extern ? Unknown80194DFC(?);
extern void func_80194E7C(Mat4*, Mat4*);
// extern ? func_80194F90(?);
// extern ? func_80195578(?);
// extern ? func_80195844(?);
// extern ? func_8019590C(?);
// extern ? Unknown80195950(?);
// extern ? Unknown801959E0(?);
// extern ? Unknown80195B04(?);
// extern ? func_80195C78(?);
// extern ? Unknown80195D98(?);
// extern ? func_80195FD4(?);
extern void func_801961F4(Mat4*, struct MyVec3f*, f32);
extern void set_identity_mat4(void *);      //Mat4*; something sort of matrix4x4_init?
extern void mat4_cpy(Mat4*, Mat4*);
extern void func_80196430(struct MyVec3f *, void *);    // (struct MyVec3f*, Mat4*)
extern void func_80196540(struct MyVec3f*, Mat4*);
extern void func_80196614(Mat4*, Mat4*, Mat4*);
extern void gd_print_vec(const char *, struct MyVec3f *);
extern void gd_print_plane(const char *, struct GdPlaneF *);
extern void gd_print_mtx(const char *, Mat4 *);
// extern ? Unknown80197068(?);
// extern ? Unknown801970F0(?);

#endif /* _MATRIX_FUNCTIONS_H_ */
