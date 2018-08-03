#include <ultra64.h>

#include "sm64.h"
#include "math_util.h"
#include "area.h"
#include "geo_layout.h"
#include "graph_node.h"
#include "object_helpers.h"
#include "behavior_script.h"
#include "surface_collision.h"
#include "audio_interface_2.h"
#include "level_update.h"
#include "spawn_object.h"
#include "object_list_processor.h"

struct LinkedList
{
    struct LinkedList *prev;
    struct LinkedList *next;
};

void Unknown802C8CF0(struct LinkedList *a, struct LinkedList **head, struct LinkedList *c, int size, int count)
{
    int i;
    struct LinkedList *addr = c;

    a->prev = a;
    a->next = a;
    *head = c;

    for (i = 0; i < count - 1; i++)
    {
        addr = (struct LinkedList *)((u8 *)addr + size);
        c->prev = addr;
        c = addr;
    }
    c->prev = NULL;
}

struct LinkedList *Unknown802C8D60(struct LinkedList *a, struct LinkedList *b)
{
    struct LinkedList *sp4 = b->prev;

    if (sp4 != NULL)
    {
        b->prev = sp4->prev;
        sp4->next = a->next;
        sp4->prev = a;
        a->next->prev = sp4;
        a->next = sp4;
    }
    return sp4;
}

struct Object *try_get_next_obj(struct ObjectNode *objList, struct ObjectNode *b)
{
    struct ObjectNode *nextObj;

    // if the next pointer isnt NULL, we are not at the end of the list.
    // Set and nest the nextObj pointer.
    if ((nextObj = b->next) != NULL)
    {
        b->next = nextObj->next;
        nextObj->prev = objList->prev;
        nextObj->next = objList;
        objList->prev->next = nextObj;
        objList->prev = nextObj;
    }
    else
        return NULL; // we are at the end of the list. There is nothing to allocate.

    // FIXME: What types do these functions actually take?
    func_8037C0BC((struct GraphNode *)nextObj);
    func_8037C044(&D_8038BD88, (struct GraphNode *)nextObj);
    return (struct Object *)nextObj;
}

void Unknown802C8E70(struct LinkedList *a, struct LinkedList *b)
{
    b->prev->next = b->next;
    b->next->prev = b->prev;
    b->prev = a->prev;
    a->prev = b;
}

void func_802C8EA4(struct ObjectNode *a, struct ObjectNode *b)
{
    b->next->prev = b->prev;
    b->prev->next = b->next;
    b->next = a->next;
    a->next = b;
}

void init_free_obj_list(void)
{
    int i;
    int objLimit = OBJECT_ARRAY_SIZE;
    struct Object *obj = &gObjectPool[0];

    D_8035FD80.next = (struct ObjectNode *)obj;

    for (i = 0; i < objLimit - 1; i++)
    {
        obj->header.next = &obj[1].header;
        obj++;
    }
    obj->header.next = NULL;
}

void clear_object_lists(struct ObjectNode *obj)
{
    int i;

    for (i = 0; i < 13; i++)
    {
        obj[i].next = &obj[i];
        obj[i].prev = &obj[i];
    }
}

void UnknownRecursive802C8FF8(struct Object *a)
{
    struct Object *sp24;
    struct Object *sp20;
    struct Object *sp1C = a;

    if ((sp24 = (struct Object *)a->header.gfx.node.children) != NULL)
        UnknownRecursive802C8FF8(sp24);
    else
        hide_object(a);

    while ((sp20 = (struct Object *)a->header.gfx.node.next) == sp1C)
    {
        UnknownRecursive802C8FF8(sp20);
        a = (struct Object *)sp20->header.gfx.node.next;
    }
}

void unload_obj(struct Object *obj)
{
    obj->active = 0;
    obj->prevObj = 0;
    obj->header.gfx.throwMatrix = NULL;
    func_803206F8(&obj->header.gfx.unk54);
    func_8037C0BC((struct GraphNode *)obj);
    func_8037C044(&D_8038BD88, (struct GraphNode *) obj);
    obj->header.gfx.node.flags &= ~4;
    obj->header.gfx.node.flags &= ~1;
    func_802C8EA4(&D_8035FD80, &obj->header);
}

struct Object *try_init_object(struct ObjectNode *objList)
{
    int i;
    struct Object *obj = try_get_next_obj(objList, &D_8035FD80);
    struct Object *unloadObj;

    // The object list is full if the newly created pointer is NULL.
    // If this happens, we first attempt to unload unimportant objects
    // in order to finish allocating the object.
    if (obj == NULL)
    {
        unloadObj = get_next_unimportant_obj(); // try to get the pointer to the next unimportant obj.

        // if the retrieved slot is NULL, it is because the object list is
        // completely exhausted with important objects. This behavior if left
        // unchecked quickly becomes erroneous, so hang the game forever if
        // the object list gets full with important objects.
        if (unloadObj == NULL)
        {
            while (1)
                ;
        }
        else
        {
            // unload the unimportant object and load the new object in.
            unload_obj(unloadObj);
            obj = try_get_next_obj(objList, &D_8035FD80);
            if (gCurrentObject == obj) // hmm...
            {
            }
        }
    }

    // we have gotten a good pointer to an object. initialize the
    // object contents below.
    obj->active = 257;
    obj->parentObj = obj;
    obj->prevObj = NULL;
    obj->collidedObjInteractTypes = 0;
    obj->numCollidedObjs = 0;

    for (i = 0; i < 0x50; i++)
        obj->rawData.asU32[i] = 0;

    obj->unk1C8 = 0;
    obj->stackIndex = 0;
    obj->unk1F4 = 0;
    obj->hitboxRadius = 50.0f;
    obj->hitboxHeight = 100.0f;
    obj->unk200 = 0.0f;
    obj->unk204 = 0.0f;
    obj->unk208 = 0.0f;
    obj->unk210 = 0;
    obj->platform = NULL;
    obj->collisionData = NULL;
    obj->oCollectable = -1;
    obj->oUnk180 = 0;
    obj->oUnk184 = 2048;
    obj->oCollisionDistance = 1000.0f;
    if (gCurrLevelNum == 14)
        obj->oDrawingDistance = 2000.0f;
    else
        obj->oDrawingDistance = 4000.0f;
    mtxf_identity(obj->unk21C);
    obj->unk1F6 = 0;
    obj->unk25C = 0;
    obj->oDistanceToMario = 19000.0f;
    obj->oUnk1A0 = -1;

    obj->header.gfx.node.flags &= ~0x10;
    obj->header.gfx.pos[0] = -10000.0f;
    obj->header.gfx.pos[1] = -10000.0f;
    obj->header.gfx.pos[2] = -10000.0f;
    obj->header.gfx.throwMatrix = NULL;

    return obj;
}

void put_obj_on_floor(struct Object *obj)
{
    struct Surface *surface;

    obj->oFloorHeight = find_floor(obj->oPosX, obj->oPosY, obj->oPosZ, &surface);
    if (obj->oFloorHeight + 2.0f > obj->oPosY && obj->oPosY > obj->oFloorHeight - 10.0f)
    {
        obj->oPosY = obj->oFloorHeight;
        obj->oMoveFlags |= OBJ_MOV_GROUND;
    }
}

struct Object *create_object(u32 *behScript)
{
    int listIndex;
    struct Object *obj;
    struct ObjectNode *objList;
    u32 *behavior = behScript;

    if ((*behScript >> 24) == 0)
        listIndex = (*behScript >> 16) & 0xFFFF;
    else
        listIndex = 8;

    objList = &gObjectLists[listIndex];
    obj = try_init_object(objList);
    obj->behScript = behScript;
    obj->behavior = behavior;
    if (listIndex == OBJ_LIST_UNIMPORTANT)
        obj->active |= 0x10;
    switch (listIndex)
    {
    // these types of objects should spawn on the ground, so where they are created,
    // place them on the ground.
    case OBJ_LIST_GENACTOR:
    case OBJ_LIST_PUSHABLE:
    case OBJ_LIST_POLELIKE:
        put_obj_on_floor(obj);
        break;
    default:
        break;
    }
    return obj;
}

void hide_object(struct Object *obj)
{
    obj->active = 0;
}
