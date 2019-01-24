#ifndef _MARIO_HEAD_6_H_
#define _MARIO_HEAD_6_H_

#include "types.h"
#include "gd_types.h"

// data
extern s32 gGdFrameBuf;

// functions
extern u32 get_alloc_mem_amt(void);
extern s32 gd_get_ostime(void);
extern f32 get_time_scale(void);
extern f64 gd_sin_d(f64);
extern f64 gd_cos_d(f64);
extern f64 gd_sqrt_d(f64);
extern void gd_printf(const char *, ...);
extern void gd_exit(s32);
extern void gd_free(void *);
extern void *gd_allocblock(u32);
extern void *gd_malloc(u32, u8);
extern void *gd_malloc_perm(u32);
extern void *gd_malloc_temp(u32);
extern void func_8019BD0C(s32, s32);
extern void gd_add_to_heap(void *, u32);
extern void gdm_init(void *, u32);
extern void gdm_setup(void);
extern void gdm_maketestdl(s32);
extern void gd_vblank(void);
extern void gd_copy_p1_contpad(OSContPad *);
extern s32 gd_sfx_to_play(void);
extern void *gdm_gettestdl(s32);
extern void gd_draw_rect(f32, f32, f32, f32);
extern void gd_draw_border_rect(f32, f32, f32, f32);
extern void gd_set_fill(struct GdColour *);
extern void stash_current_gddl(void);
extern void pop_gddl_stash(void);
extern s32 gd_startdisplist(s32);
extern s32 gd_end_dl();
extern void add_mat4_load_to_dl(Mat4 *);
extern void push_idn_mtx_cur_gddl(void);
extern void pop_mtx_gddl(void);
extern void translate_mtx_gddl(f32, f32, f32);
extern void translate_load_mtx_gddl(f32, f32, f32);
extern void func_8019F258(f32, f32, f32);
extern void func_8019F2C4(f32, s8);
extern void func_8019F318(struct ObjCamera *a, f32, f32, f32, f32, f32, f32, f32);
extern void func_8019F9D8(s32);
extern void *func_8019FA60(f32, f32, f32, f32);
extern void func_8019FEF0(void);
extern void func_8019FF54(f32, f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_801A0038(void);
extern void func_801A0070(void);
extern void func_801A02B8(f32);
extern void func_801A0324(s32);
extern void func_801A033C(s32);
extern s32 func_801A0354(s32);
extern void func_801A0448(s32);
extern void func_801A0478(s32, struct ObjCamera *, struct MyVec3f *, struct MyVec3f *, struct MyVec3f *, struct GdColour *);
extern s32 func_801A086C(s32, struct GdColour *, s32);
extern void func_801A15E8(struct MyVec3f *);
extern void func_801A16C4(struct MyVec3f *);
extern void set_gd_mtx_parameters(s32);
extern void gd_set_one_cycle(void);
extern void func_801A2374(s32);
extern void func_801A2448(struct ObjView *);
extern void func_801A34E0(void);
extern void gd_shading(s32);
extern s32 gd_getproperty(s32, void *);
extern void gd_setproperty(s32, f32, f32, f32);
extern void func_801A3AF0(f32, f32, f32, f32, f32, f32);
extern void func_801A3C8C(f32, f32, f32, f32);
extern s32 func_801A3E5C(const char *, struct ObjView *, s32, s32, s32, s32);
extern void gd_init_controllers(void);
extern void Proc801A43DC(struct ObjHeader *); //apply to OBJ_TYPE_VIEWS
extern void *func_801A43F0(const char *, ...);   // TUI code..? query_user? doesn't actually return anything... maybe it returned a "menu *"?
extern void Proc801A4410(void *);  // function looks like it got various controller/input attributes..?
extern void Proc801A4424(void *);  // TUI stuff?
extern void func_801A4438(f32, f32, f32);
extern void func_801A48C4(u32);
extern void func_801A48D8(char *);
extern void func_801A48F0(struct ObjView *);
extern void func_801A520C(void);
extern void gd_init(void);
extern void func_801A5998(s8 *);    /* convert LE bytes to BE word? */ 
extern void func_801A59AC(void *);
extern void func_801A59C0(s8 *);    /* convert LE bytes to BE f32? */ 
extern void func_801A59D4(s16 *, s32);
extern void func_801A5A04(s16);
extern s32 func_801A5A4C(s16 *);
extern void func_801A5B58(f32, f32);
extern struct ObjHeader *load_dynlist(struct DynList *);

#endif /* _MARIO_HEAD_6_H_ */
