#ifndef _OBJECT_LIST_DEFINES_H
#define _OBJECT_LIST_DEFINES_H

#define OBJ_LIST_PLAYER         0   // mario & possibly luigi
#define OBJ_LIST_UNK1           1   // (unused. luigi? right after player)
#define OBJ_LIST_DESTRUCTIVE    2   // held objects
#define OBJ_LIST_UNK3           3   // (unused)
#define OBJ_LIST_GENACTOR       4   // general actors. most normal 'enemies' or actors are
                                    // on this list. (MIPS, bullet bill, bully, etc)
#define OBJ_LIST_PUSHABLE       5   // pushable actors. This is a group of objects which
                                    // can push each other around as well as their parent
                                    // objects. (goombas, koopas, spinies)
#define OBJ_LIST_LEVEL          6   // level objects. general level objects such as heart, star
#define OBJ_LIST_UNK7           7   // (unused)
#define OBJ_LIST_DEFAULT        8   // default objects. objects that didnt start with a 00
                                    // command are put here, so this is treated as a default.
#define OBJ_LIST_SURFACE        9   // surface objects. objects that specifically have surface
                                    // collision and not object collision. (thwomp, whomp, etc)
#define OBJ_LIST_POLELIKE       10  // polelike objects. objects that attract or otherwise
                                    // "cling" mario similar to a pole action. (hoot,
                                    // whirlpool, trees/poles, etc)
#define OBJ_LIST_SPAWNER        11  // spawners
#define OBJ_LIST_UNIMPORTANT    12  // unimportant objects. objects that will not load
                                    // if there are not enough object slots: they will also
                                    // be manually unloaded to make room for slots if the list
                                    // gets exhausted.

#endif /* _OBJECT_LIST_DEFINES_H */
