#include <ultra64.h>

#include "sm64.h"
#include "math_util.h"
#include "rendering.h"
#include "geo_layout.h"
#include "graph_node.h"
#include "level_functions.h"
#include "behavior_script.h"
#include "surface_collision.h"
#include "audio_interface_2.h"
#include "level_update.h"
#include "spawn_object.h"

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

struct Object *func_802C8DC4(struct GfxNode *a, struct GfxNode *b)
{
    struct GfxNode *sp1C;

    if ((sp1C = b->prev) != NULL)
    {
        b->prev = sp1C->prev;
        sp1C->next = a->next;
        sp1C->prev = a;
        a->next->prev = sp1C;
        a->next = sp1C;
    }
    else
        return NULL;

    // FIXME: What types do these functions actually take?
    func_8037C0BC((struct GraphNode *)sp1C);
    func_8037C044(&D_8038BD88, (struct GraphNode *)sp1C);
    return (struct Object *)sp1C;
}

void Unknown802C8E70(struct LinkedList *a, struct LinkedList *b)
{
    b->prev->next = b->next;
    b->next->prev = b->prev;
    b->prev = a->prev;
    a->prev = b;
}

void func_802C8EA4(struct GfxNode *a, struct GfxNode *b)
{
    b->prev->next = b->next;
    b->next->prev = b->prev;
    b->prev = a->prev;
    a->prev = b;
}

void func_802C8ED8(void)
{
    int spC;
    int sp8 = 240;
    struct Object *sp4 = &D_8033C118[0];

    D_8035FDE0 = sp4;
    for (spC = 0; spC < sp8 - 1; spC++)
    {
        sp4->gfx.prev = &sp4[1].gfx;
        sp4++;
    }
    sp4->gfx.prev = NULL;
}

void func_802C8F5C(struct GfxNode *a)
{
    int sp4;

    for (sp4 = 0; sp4 < 13; sp4++)
    {
        a[sp4].prev = &a[sp4];
        a[sp4].next = &a[sp4];
    }
}

void UnknownRecursive802C8FF8(struct Object *a)
{
    struct Object *sp24;
    struct Object *sp20;
    struct Object *sp1C = a;

    if ((sp24 = a->gfx.unk10) != NULL)
        UnknownRecursive802C8FF8(sp24);
    else
        func_802C9548(a);

    while ((sp20 = a->gfx.unk8) == sp1C)
    {
        UnknownRecursive802C8FF8(sp20);
        a = sp20->gfx.unk8;
    }
}

void func_802C9088(struct Object *a)
{
    a->active = 0;
    a->unk6C = 0;
    a->gfx.unk50 = 0;
    func_803206F8(&a->gfx.unk54);
    func_8037C0BC((struct GraphNode *)a);
    func_8037C044(&D_8038BD88, (struct GraphNode *) a);
    a->gfx.graphFlags &= ~4;
    a->gfx.graphFlags &= ~1;
    func_802C8EA4(&D_8035FD80, &a->gfx);
}

struct Object *func_802C9120(struct GfxNode *a)
{
    int i;
    struct Object *sp20 = func_802C8DC4(a, &D_8035FD80);
    struct Object *sp1C;

    if (sp20 == NULL)
    {
        sp1C = func_8029F3A0();

        if (sp1C == NULL)
        {
            // Endless loop?
            while (1)
                ;
        }
        else
        {
            func_802C9088(sp1C);
            sp20 = func_802C8DC4(a, &D_8035FD80);
            if (gCurrentObject == sp20)
            {
            }
        }
    }

    sp20->active = 257;
    sp20->unk68 = sp20;
    sp20->unk6C = 0;
    sp20->collidedObjInteractTypes = 0;
    sp20->numCollidedObjs = 0;

    // hmm...
    for (i = 0; i < 80; i++)
        sp20->unk88[i] = 0;

    sp20->unk1C8 = 0;
    sp20->stackIndex = 0;
    sp20->unk1F4 = 0;
    sp20->hitboxRadius = 50.0f;
    sp20->hitboxHeight = 100.0f;
    sp20->unk200 = 0.0f;
    sp20->unk204 = 0.0f;
    sp20->unk208 = 0.0f;
    sp20->unk210 = 0;
    sp20->platform = NULL;
    sp20->collisionData = NULL;
    sp20->unk9C = -1;
    sp20->unk180 = 0;
    sp20->unk184 = 2048;
    sp20->collisionDistance = 1000.0f;
    if (gCurrLevelNum == 14)
        sp20->drawingDistance = 2000.0f;
    else
        sp20->drawingDistance = 4000.0f;
    mtxf_identity(sp20->unk21C);
    sp20->unk1F6 = 0;
    sp20->unk25C = 0;
    sp20->distanceFromMario = 19000.0f;
    sp20->unk1A0 = -1;

    sp20->gfx.graphFlags &= ~0x10;
    sp20->gfx.unk20[0] = -10000.0f;
    sp20->gfx.unk20[1] = -10000.0f;
    sp20->gfx.unk20[2] = -10000.0f;
    sp20->gfx.unk50 = 0;

    return sp20;
}

void func_802C937C(struct Object *a)
{
    struct Surface *surface;

    a->unkE8 = func_80381900(a->pos[0], a->pos[1], a->pos[2], &surface);
    if (a->unkE8 + 2.0f > a->pos[1] && a->pos[1] > a->unkE8 - 10.0f)
    {
        a->pos[1] = a->unkE8;
        a->unkEC |= 2;
    }
}

struct Object *func_802C9424(u32 *a)
{
    int sp34;
    struct Object *sp30;
    struct GfxNode *sp2C;
    u32 *sp28 = a;

    if ((*a >> 24) == 0)
        sp34 = (*a >> 16) & 0xFFFF;
    else
        sp34 = 8;

    sp2C = &D_8035FD78[sp34];
    sp30 = func_802C9120(sp2C);
    sp30->behScript = a;
    sp30->behavior = sp28;
    if (sp34 == 12)
        sp30->active |= 0x10;
    switch (sp34)
    {
    case 4:
    case 5:
    case 10:
        func_802C937C(sp30);
        break;
    default:
        break;
    }
    return sp30;
}

void func_802C9548(struct Object *obj)
{
    obj->active = 0;
}
