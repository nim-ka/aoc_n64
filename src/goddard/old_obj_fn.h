#ifndef _GD_OLD_OBJ_FN_H_
#define _GD_OLD_OBJ_FN_H_

#include "types.h"
#include "gd_types.h"

/* This file was hidden at the end of mario_head_4. It seems to deal with 
** GD Object types that are no longer used in the final game */

extern void get_objvalue(union ObjVarVal *, enum ValPtrType, void *, s32);
extern struct ObjGadget *make_gadget(s32, s32);
extern void reset_gadget(struct ObjGadget*);
extern void reset_gadgets_in_grp(struct ObjGroup*);

#ifndef _BAD_GD_DECLARATIONS_H_
/* have to erase type as it is called with <struct ObjValPtrs *, char *, s32, int, int, int> in dynlist code */
extern struct ObjLabel *make_label(struct ObjValPtrs *, char *, s32, f32, f32, f32);
#endif

#endif /* _GD_OLD_OBJ_FN_H_ */
