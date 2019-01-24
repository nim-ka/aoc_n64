#ifndef _DYNLIST_PROCESSOR_
#define _DYNLIST_PROCESSOR_

#include <ultra64.h>
#include "gd_types.h"

// types
/* Unfortunately, goddard didn't use a union to encode the DynObj Id.
** So, the best I can come up with is this typedef and accessor macros 
** As the "actual type" is `void *`, the type is NULL-able and is used as such */
typedef void *DynId;
#define DynIdAsStr(id) ((char *)(id))
#define DynIdAsInt(id) ((u32)(id))
#define AsDynId(unk)   ((DynId)(unk))
// parameters for `d_set_parm_ptr`
enum DParmPtr {
    PARM_PTR_OBJ_VTX = 1,
    PARM_PTR_CHAR    = 5
};
// d_makeobj types
enum DObjTypes {
    D_CAR_DYNAMICS  = 0,
    D_NET           = 1,
    D_JOINT         = 2,
    D_ANOTHER_JOINT = 3,
    D_CAMERA        = 4,
    D_VERTEX        = 5,
    D_FACE          = 6,
    D_PLANE         = 7,
    D_BONE          = 8,
    D_MATERIAL      = 9,
    D_SHAPE         = 10,
    D_GADGET        = 11,
    D_LABEL         = 12,
    D_VIEW          = 13,
    D_ANIMATOR      = 14,
    D_DATA_GRP      = 15,
    D_PARTICLE      = 16,
    D_LIGHT         = 17,
    D_GROUP         = 18
};

// functions
extern void push_dynobj_stash(void);
extern void pop_dynobj_stash(void);
extern void reset_dynlist(void);
extern struct ObjHeader *proc_dynlist(struct DynList *dylist);
extern void d_copystr_to_idbuf(char *);
extern struct ObjHeader *d_makeobj(enum DObjTypes type, DynId id);
extern void d_set_shapeptrptr(struct ObjShape **);
extern struct ObjHeader *d_use_obj(DynId);
extern void set_cur_dynobj();        //set_cur_dynobj(struct ObjHeader *);
extern void d_start_group(DynId);
extern void d_end_group(DynId);
extern void dynid_is_int(s32);
extern void d_set_init_pos(f32, f32, f32);
extern void d_get_init_pos(struct MyVec3f*);
extern void d_get_init_rot(struct MyVec3f*);
extern void d_set_rel_pos(f32, f32, f32);
extern void d_get_rel_pos(struct MyVec3f*);
extern struct ObjGroup* d_get_att_objgroup(void);
extern void d_get_scale(struct MyVec3f*);
extern void d_set_world_pos(f32, f32, f32);
extern void d_get_world_pos(struct MyVec3f *);
extern void d_set_scale(f32, f32, f32);
extern void d_add_valptr(DynId, u32, s32, u32);
extern void d_add_valproc(union ObjVarVal * (*)(union ObjVarVal *, union ObjVarVal));
extern void d_set_flags(s32);
extern void d_set_parm_f(s32, f32);
extern void d_set_parm_ptr(enum DParmPtr, void *);
extern void d_set_objheader_flag(s32);
extern void d_set_type(s32);
extern void d_set_colour_num(s32);
extern void d_set_diffuse(f32, f32, f32);
extern struct GdPlaneF* d_get_plane(void);
extern void d_get_matrix(Mat4*);
extern Mat4* d_get_rot_mtx_ptr(void);
extern void d_set_idn_mtx(Mat4*);
extern Mat4* d_get_matrix_ptr(void);
extern Mat4* d_get_idn_mtx_ptr(void);
extern float d_calc_world_dist_btwn();  //d_calc_world_dist_btwn(struct ObjHeader *, struct ObjHeader *)

#endif /* _DYNLIST_PROCESSOR_ */
