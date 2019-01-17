#ifndef _MARIO_HEAD_6_H_
#define _MARIO_HEAD_6_H_

#include "types.h"
#include "gd_types.h"

// data
extern s32 gGdFrameBuf;

// function
extern u32 get_alloc_mem_amt(void);
extern s32 gd_get_ostime(void);
extern f32 get_time_scale(void);
// extern ? dump_disp_list(?);
// extern ? next_gfx(?);
// extern ? next_light(?);
// extern ? next_mtx(?);
// extern ? next_vtx(?);
// extern ? next_vp(?);
extern f64 gd_sin_d(f64);
extern f64 gd_cos_d(f64);
extern f64 gd_sqrt_d(f64);  //"sqrt_d_limited" (return 0.0 below 1e-7)
// extern ? Unknown8019B3D4(?);
extern void gd_printf(const char *, ...);
extern void gd_exit(s32);     // TUI stuff? a fatal or exit function?
extern void gd_free(void *);  /* gd_free_mem call, so gd_free? */
extern void *gd_allocblock(u32);
extern void *gd_malloc(u32, u8);
extern void *gd_malloc_perm(u32);
extern void *gd_malloc_temp(u32);
// extern ? Unknown8019BC88(?);
// extern ? Unknown8019BCD4(?);
extern void func_8019BD0C(s32, s32);
// extern ? func_8019BDC8(?);
// extern ? Unknown8019BE40(?);
// extern ? setup_stars(?);
// extern ? setup_timers(?);
// extern ? Unknown8019C270(?);
// extern ? Unknown8019C288(?);
extern void gd_add_to_heap(void *, u32);
extern void gdm_init(void *, u32);
extern void gdm_setup(void);
// extern ? Unknown8019C448(?);
// extern ? print_gdm_stats(?);
// extern ? make_view_withgrp(?);
extern void gdm_maketestdl(s32);
// extern ? set_time_scale(?);
// extern ? Unknown8019C840(?);
extern void Proc8019C734(void);
extern void gd_copy_p1_contpad(OSContPad *);
extern s32 func_8019C888(void);
extern void *gdm_gettestdl(s32);
// extern ? gdm_getpos(?);
// extern ? func_8019CCFC(?);
// extern ? fatal_no_dl_mem(?);
// extern ? alloc_displaylist(?);
// extern ? cpy_remaining_gddl(?);
// extern ? create_child_gdl(?);
// extern ? new_gd_dl(?);
// extern ? gd_init_RSP(?);
// extern ? gd_init_RDP(?);
extern void gd_draw_rect(f32, f32, f32, f32);
extern void gd_draw_border_rect(float, float, float, float);
extern void gd_set_fill(struct GdColour *);
// extern ? gd_set_view_zbuf(?);
// extern ? gd_set_view_framebuf(?);
// extern ? func_8019E75C(?);
// extern ? func_8019E7FC(?);
extern void stash_current_gddl(void);
extern void pop_gddl_stash(void);
extern int gd_startdisplist(int);
// extern ? gd_enddisplist(?);
extern int gd_end_dl();
// extern ? Unknown8019EBCC(?);
// extern ? func_8019EC08(?);
// extern ? Unknown8019EC88(?);
// extern ? mat4_to_Mtx(?);
// extern ? add_mat4_to_dl(?);
extern void add_mat4_load_to_dl(Mat4 *);
// extern ? Unknown8019EFC0(?);
extern void push_idn_mtx_cur_gddl(void);
extern void pop_mtx_gddl(void);
extern void translate_mtx_gddl(float, float, float);
extern void translate_load_mtx_gddl(float, float, float);
extern void func_8019F258(float, float, float);
extern void func_8019F2C4(f32, s8);
extern void func_8019F318(struct ObjCamera *a, float, float, float, float, float, float, float);
extern void func_8019F9D8(int);
extern void *func_8019FA60(float, float, float, float);
extern void func_8019FEF0(void);
extern void func_8019FF54(float, float, float, float, float, float, float, float, float);
extern void func_801A0038(void);
extern void func_801A0070(void);
// extern ? func_801A01EC(?);
// extern ? func_801A025C(?);
extern void func_801A02B8(float);
extern void func_801A0324();
extern void func_801A033C(int);
extern int func_801A0354(int);
extern void func_801A0448();
extern void func_801A0478(int, struct ObjCamera *, struct MyVec3f *, struct MyVec3f *, struct MyVec3f *, struct GdColour *);
extern s32 func_801A086C(s32, struct GdColour *, s32);
extern void func_801A15E8(struct MyVec3f *);
extern void func_801A16C4(struct MyVec3f *);
extern void set_gd_mtx_parameters(int);
// extern ? func_801A180C(?);
// extern ? func_801A1A00(?);
// extern ? Unknown801A1B30(?);
// extern ? Unknown801A1E70(?);
extern void gd_set_one_cycle(void);
// extern ? Unknown801A2360(?);
extern void func_801A2374();
// extern ? func_801A2388(?);
extern void func_801A2448(struct ObjView *);
// extern ? func_801A2844(?);
// extern ? Unknown801A324C(?);
// extern ? Unknown801A32F4(?);
// extern ? func_801A3324(?);
// extern ? func_801A3370(?);
// extern ? Unknown801A33F8(?);
// extern ? Unknown801A347C(?);
extern void func_801A34E0(void);
extern void gd_shading(s32);
extern s32 gd_getproperty(s32, void *);
extern void gd_setproperty(int, float, float, float);
extern void func_801A3AF0(float, float, float, float, float, float);
extern void func_801A3C8C(float, float, float, float);
extern s32 func_801A3E5C(const char *, struct ObjView *, s32, s32, s32, s32);
extern void gd_init_controllers(void);
extern void Proc801A43DC(struct ObjHeader *); //apply to OBJ_TYPE_VIEWS
extern void *func_801A43F0(const char *, ...);   // TUI code..? query_user? doesn't actually return anything... maybe it returned a "menu *"?
extern void Proc801A4410(void *);  // function looks like it got various controller/input attributes..?
extern void Proc801A4424(void *);  // TUI stuff?
extern void func_801A4438(float, float, float);
// extern ? gd_gentexture(?);
// extern ? Unknown801A45E4(?);
// extern ? Unknown801A47B8(?);
// extern ? Unknown801A47F4(?);
// extern ? func_801A4808(?);
// extern ? func_801A4848(?);
// extern ? func_801A48B4(?);
extern void func_801A48C4();
extern void func_801A48D8(char *);
extern void func_801A48F0();
// extern ? func_801A4918(?);
// extern ? Unknown801A4B04(?);
// extern ? func_801A4C0C(?);
// extern ? Unknown801A4F58(?);
// extern ? Proc801A5110(?);
// extern ? func_801A5168(?);
extern void func_801A520C(void);
// extern ? Unknown801A5344(?);
extern void gd_init(void);
// extern ? Unknown801A5910(?);
extern void func_801A5998(s8*);    /* convert LE bytes to BE word? */ 
extern void func_801A59AC(void *);
extern void func_801A59C0(s8*);    /* convert LE bytes to BE float? */ 
extern void func_801A59D4(s16 *, s32);
extern void func_801A5A04(s16);
extern s32 func_801A5A4C(s16 *);
// extern ? Unknown801A5A80(?);
// extern ? Unknown801A5A94(?);
// extern ? Unknown801A5AB8(?);
// extern ? Unknown801A5AE0(?);
extern void func_801A5B58(float, float);
// extern ? func_801A5BE8(?);
// extern ? cvrt_val_to_kb(?);
// extern ? Unknown801A5C80(?);
// extern ? Unknown801A5D90(?);
// extern ? Unknown801A5FF8(?);
// extern ? gd_put_sprite(?);
// extern ? gd_setup_cursor(?);
// extern ? view_proc_print_timers(?);
// extern ? make_timer_gadgets(?);
// extern ? Unknown801A6E30(?);
// extern ? Unknown801A6E44(?);
// extern ? gd_block_dma(?);
extern struct ObjGroup *load_dynlist(struct DynList *);

#endif /* _MARIO_HEAD_6_H_ */
