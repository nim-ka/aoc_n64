#ifndef _SPAWN_OBJECT_H
#define _SPAWN_OBJECT_H

#include "types.h"

// extern ? Unknown802C8CF0(?);
// extern ? Unknown802C8D60(?);
// extern ? func_802C8DC4(?);
// extern ? Unknown802C8E70(?);
// extern ? func_802C8EA4(?);
extern void init_free_obj_list(void);
extern void clear_object_lists(struct ObjectNode *);
// extern ? UnknownRecursive802C8FF8(?);
extern void unload_obj(struct Object *);
// extern ? func_802C9120(?);
// extern ? func_802C937C(?);
extern struct Object *create_object(u32 *a);
extern void hide_object(struct Object *);

#endif /* _SPAWN_OBJECT_H */
