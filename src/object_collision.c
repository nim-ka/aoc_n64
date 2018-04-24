#include <ultra64.h>

#include "sm64.h"

struct Object *Unknown802C8460(struct Object *a)
{
    struct Object *sp24;
    UNUSED int unused;
    int i;

    for (i = 0; i < a->unk76; i++)
    {
        func_802C9AD8(D_80336C50, 0);
        sp24 = a->unk78[i];
        if (sp24 != gMarioObject)
            return sp24;
    }
    return NULL;
}

int func_802C8504(struct Object *a, struct Object *b)
{
    float sp3C = a->pos[1] - a->unk208;
    float sp38 = b->pos[1] - b->unk208;
    float dx = a->pos[0] - b->pos[0];
    UNUSED float sp30 = sp3C - sp38;
    float dz = a->pos[2] - b->pos[2];
    float collisionRadius = b->collisionSphere[0] + a->collisionSphere[0];
    float distance = sqrtf(dx * dx + dz * dz);

    if (collisionRadius > distance)
    {
        float sp20 = a->collisionSphere[1] + sp3C;
        float sp1C = b->collisionSphere[1] + sp38;

        if (sp3C > sp1C)
            return 0;
        if (sp20 < sp38)
            return 0;
        if (a->unk76 >= 4)
            return 0;
        if (b->unk76 >= 4)
            return 0;
        a->unk78[a->unk76] = b;
        b->unk78[b->unk76] = a;
        a->unk70 |= b->interaction;
        b->unk70 |= a->interaction;
        a->unk76++;
        b->unk76++;
        return 1;
    }

    //! no return value
}

int func_802C870C(struct Object *a, struct Object *b)
{
    float sp3C = a->pos[1] - a->unk208;
    float sp38 = b->pos[1] - b->unk208;
    float sp34 = a->pos[0] - b->pos[0];
    UNUSED float sp30 = sp3C - sp38;
    float sp2C = a->pos[2] - b->pos[2];
    float sp28 = a->unk200 + b->unk200;
    float sp24 = sqrtf(sp34 * sp34 + sp2C * sp2C);

    if (a == gMarioObject)
        b->unk190 |= 2;

    if (sp28 > sp24)
    {
        float sp20 = a->collisionSphere[1] + sp3C;
        float sp1C = b->unk204 + sp38;

        if (sp3C > sp1C)
            return 0;
        if (sp20 < sp38)
            return 0;
        if (a == gMarioObject)
            b->unk190 &= ~2;
        return 1;
    }

    //! no return value
}

void func_802C88A8(struct Object *a)
{
    struct Object *sp4 = (struct Object *)a->gfx.prev;

    while (sp4 != a)
    {
        sp4->unk76 = 0;
        sp4->unk70 = 0;
        if (sp4->unk9C > 0)
            sp4->unk9C--;
        sp4 = (struct Object *)sp4->gfx.prev;
    }
}

void func_802C8918(struct Object *a, struct Object *b, struct Object *c)
{
    if (a->unk9C == 0)
    {
        while (b != c)
        {
            if (b->unk9C == 0)
            {
                if (func_802C8504(a, b) && b->unk200 != 0.0f)
                    func_802C870C(a, b);
            }
            b = (struct Object *)b->gfx.prev;
        }
    }
}

void func_802C89CC(void)
{
    struct Object *sp1C = (struct Object *)&D_8035FD78[0];
    struct Object *sp18 = (struct Object *)sp1C->gfx.prev;

    while (sp18 != sp1C)
    {
        func_802C8918(sp18, (struct Object *)sp18->gfx.prev, sp1C);
        func_802C8918(sp18, (struct Object *)D_8035FD78[10].prev, (struct Object *)&D_8035FD78[10]);
        func_802C8918(sp18, (struct Object *)D_8035FD78[6].prev, (struct Object *)&D_8035FD78[6]);
        func_802C8918(sp18, (struct Object *)D_8035FD78[4].prev, (struct Object *)&D_8035FD78[4]);
        func_802C8918(sp18, (struct Object *)D_8035FD78[5].prev, (struct Object *)&D_8035FD78[5]);
        func_802C8918(sp18, (struct Object *)D_8035FD78[9].prev, (struct Object *)&D_8035FD78[9]);
        func_802C8918(sp18, (struct Object *)D_8035FD78[2].prev, (struct Object *)&D_8035FD78[2]);
        sp18 = (struct Object *)sp18->gfx.prev;
    }
}

void func_802C8AD4(void)
{
    struct Object *sp1C = (struct Object *)&D_8035FD78[5];
    struct Object *sp18 = (struct Object *)sp1C->gfx.prev;

    while (sp18 != sp1C)
    {
        func_802C8918(sp18, (struct Object *)sp18->gfx.prev, sp1C);
        sp18 = (struct Object *)sp18->gfx.prev;
    }
}

void func_802C8B50(void)
{
    struct Object *sp1C = (struct Object *)&D_8035FD78[2];
    struct Object *sp18 = (struct Object *)sp1C->gfx.prev;

    while (sp18 != sp1C)
    {
        if (sp18->distanceFromMario < 2000.0f && !(sp18->active & 0x200))
        {
            func_802C8918(sp18, (struct Object *)sp18->gfx.prev, sp1C);
            func_802C8918(sp18, (struct Object *)D_8035FD78[4].prev, (struct Object *)&D_8035FD78[4]);
            func_802C8918(sp18, (struct Object *)D_8035FD78[5].prev, (struct Object *)&D_8035FD78[5]);
            func_802C8918(sp18, (struct Object *)D_8035FD78[9].prev, (struct Object *)&D_8035FD78[9]);
        }
        sp18 = (struct Object *)sp18->gfx.prev;
    }
}

void func_802C8C44(void)
{
    func_802C88A8((struct Object *)&D_8035FD78[10]);
    func_802C88A8((struct Object *)&D_8035FD78[0]);
    func_802C88A8((struct Object *)&D_8035FD78[5]);
    func_802C88A8((struct Object *)&D_8035FD78[4]);
    func_802C88A8((struct Object *)&D_8035FD78[6]);
    func_802C88A8((struct Object *)&D_8035FD78[9]);
    func_802C88A8((struct Object *)&D_8035FD78[2]);
    func_802C89CC();
    func_802C8B50();
    func_802C8AD4();
}
