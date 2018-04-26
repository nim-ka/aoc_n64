#include <ultra64.h>

#include "sm64.h"

// round up to the next multiple
#define ALIGN4(val)  (((val) + 0x3) & ~0x3)
#define ALIGN8(val)  (((val) + 0x7) & ~0x7)
#define ALIGN16(val) (((val) + 0xF) & ~0xF)

extern u32 gSegmentTable[];

int SetSegmentBase(int segment, void *addr)
{
    gSegmentTable[segment] = (u32)addr & 0x1FFFFFFF;
    return gSegmentTable[segment];
}

int GetSegmentBase(int segment)
{
    return gSegmentTable[segment] | 0x80000000;
}

void *SegmentedToVirtual(void *addr)
{
    u32 segment = (u32) addr >> 24;
    u32 offset = (u32) addr & 0x00FFFFFF;

    return (void *) ((gSegmentTable[segment] + offset) | 0x80000000);
}

void *virtual_to_segmented(u32 segment, void *addr)
{
    u32 offset = ((u32)addr & 0x1FFFFFFF) - gSegmentTable[segment];

    return (void *) ((segment << 24) + offset);
}

void MovePtrTbl2Dmem(void)
{
    int i;

    for (i = 0; i < 16; i++)
    {
        {
            Gfx *g = gDisplayListHead++;
            g->words.w0 = 0xBC000000 | (((i << 2) & 0xFFFF) << 8) | 6;
            g->words.w1 = gSegmentTable[i];
        }
    }
}

struct PoolMemBlock
{
    struct PoolMemBlock *prev;
    struct PoolMemBlock *next;
};

extern struct PoolMemBlock *gPoolListHeadL;
extern struct PoolMemBlock *gPoolListHeadR;

void InitMemPool(u32 start, u32 end)
{
    gMemPoolStart = ALIGN16(start) + 16;
    gMemPoolEnd = ALIGN16(end - 15) - 16;
    gPoolSize = gMemPoolEnd - gMemPoolStart;

    gPoolListHeadL = (struct PoolMemBlock *)(gMemPoolStart - 16);
    gPoolListHeadR = (struct PoolMemBlock *)gMemPoolEnd;
    gPoolListHeadL->prev = NULL;
    gPoolListHeadL->next = NULL;
    gPoolListHeadR->prev = NULL;
    gPoolListHeadR->next = NULL;
}

void *_pool_alloc(u32 size, int b)
{
    struct PoolMemBlock *block;
    void *addr = NULL;

    size = ALIGN16(size) + 16;
    if (size != 0 && gPoolSize >= size)
    {
        gPoolSize -= size;
        if (b == 0)
        {
            block = (struct PoolMemBlock *)((u32)gPoolListHeadL + size);
            gPoolListHeadL->next = block;
            block->prev = gPoolListHeadL;
            block->next = NULL;
            addr = (u8 *)gPoolListHeadL + 16;
            gPoolListHeadL = block;
        }
        else
        {
            block = (struct PoolMemBlock *)((u32)gPoolListHeadR - size);
            gPoolListHeadR->prev = block;
            block->next = gPoolListHeadR;
            block->prev = NULL;
            gPoolListHeadR = block;
            addr = (u8 *)gPoolListHeadR + 16;
        }
    }
    return addr;
}

u32 _pool_free(void *ptr)
{
    struct PoolMemBlock *sp4 = (struct PoolMemBlock *)((u8 *)ptr - 16);
    struct PoolMemBlock *sp0 = (struct PoolMemBlock *)((u8 *)ptr - 16);

    if (sp0 < gPoolListHeadL)
    {
        while (sp0->next != NULL)
            sp0 = sp0->next;
        gPoolListHeadL = sp4;
        gPoolListHeadL->next = NULL;
        gPoolSize += (u32)sp0 - (u32)gPoolListHeadL;
    }
    else
    {
        while (sp0->prev != NULL)
            sp0 = sp0->prev;
        gPoolListHeadR = sp4->next;
        gPoolListHeadR->prev = NULL;
        gPoolSize += (u32)gPoolListHeadR - (u32)sp0;
    }
    return gPoolSize;
}

void *_pool_realloc(void *ptr, u32 size)
{
    void *new = NULL;
    struct PoolMemBlock *block = (struct PoolMemBlock *)((u8 *)ptr - 16);

    if (block->next == gPoolListHeadL)
    {
        _pool_free(ptr);
        new = _pool_alloc(size, 0);
    }
    return new;
}

u32 PoolAvailable(void)
{
    return gPoolSize - 16;
}

struct PoolState
{
    u32 poolSize;
    struct PoolMemBlock *listHeadL;
    struct PoolMemBlock *listHeadR;
    void *prev;
};

extern struct PoolState *gPoolState;

u32 PushPoolState(void)
{
    void *prevState = gPoolState;
    u32 poolSize = gPoolSize;
    struct PoolMemBlock *lhead = gPoolListHeadL;
    struct PoolMemBlock *rhead = gPoolListHeadR;

    gPoolState = _pool_alloc(sizeof(*gPoolState), 0);
    gPoolState->poolSize = poolSize;
    gPoolState->listHeadL = lhead;
    gPoolState->listHeadR = rhead;
    gPoolState->prev = prevState;
    return gPoolSize;
}

u32 PopPoolState(void)
{
    gPoolSize = gPoolState->poolSize;
    gPoolListHeadL = gPoolState->listHeadL;
    gPoolListHeadR = gPoolState->listHeadR;
    gPoolState = gPoolState->prev;
    return gPoolSize;
}

void DmaCopy(u8 *dest, u8 *srcStart, u8 *srcEnd)
{
    u32 size = ALIGN16(srcEnd - srcStart);

    osInvalDCache(dest, size);
    while (size != 0)
    {
        u32 copySize = (size >= 0x1000) ? 0x1000 : size;

        osPiStartDma(&D_80339BD8, 0, 0, (u32)srcStart, dest, copySize, &D_80339BF0);
        osRecvMesg(&D_80339BF0, &D_80339BEC, 1);

        dest += copySize;
        srcStart += copySize;
        size -= copySize;
    }
}

void *DynamicCopy(u8 *srcStart, u8 *srcEnd, u32 allocSize)
{
    void *dest;
    u32 size = ALIGN16(srcEnd - srcStart);

    dest = _pool_alloc(size, allocSize);
    if (dest != NULL)
        DmaCopy(dest, srcStart, srcEnd);
    return dest;
}

void *DynamicIndexCopy(u32 segment, u8 *srcStart, u8 *srcEnd, u32 allocSize)
{
    void *ptr = DynamicCopy(srcStart, srcEnd, allocSize);

    if (ptr != NULL)
        SetSegmentBase(segment, ptr);
    return ptr;
}

void *FixedCopy(u32 a, u8 *b, u8 *c)
{
    void *sp24 = NULL;
    u32 sp20 = ALIGN16(c - b);
    u32 sp1C = ALIGN16((u32)gPoolListHeadR - a);

    if (sp20 <= sp1C)
    {
        sp24 = _pool_alloc(sp1C, 1);
        if (sp24 != NULL)
        {
            bzero(sp24, sp1C);
            osWritebackDCacheAll();
            DmaCopy(sp24, b, c);
            osInvalICache(sp24, sp1C);
            osInvalDCache(sp24, sp1C);
        }
    }
    else
    {
    }
    return sp24;
}

void *UncIndexCopy(int a, u8 *b, u8 *c)
{
    void *sp24 = NULL;
    u32 sp20 = ALIGN16(c - b);
    void *sp1C = _pool_alloc(sp20, 1);
    void *sp18 = (u8 *)sp1C + 4;

    if (sp1C != NULL)
    {
        DmaCopy(sp1C, b, c);
        sp24 = _pool_alloc(*(u32 *)sp18, 0);
        if (sp24 != NULL)
        {
            uncompress(sp1C, sp24);
            SetSegmentBase(a, sp24);
            _pool_free(sp1C);
        }
        else
        {
        }
    }
    else
    {
    }
    return sp24;
}

void *func_80278304(u32 a, u8 *b, u8 *c)
{
    UNUSED void *sp24 = NULL;
    u32 sp20 = ALIGN16(c - b);
    void *sp1C = _pool_alloc(sp20, 1);
    UNUSED void *sp18 = (u8 *)sp1C + 4;

    if (sp1C != NULL)
    {
        DmaCopy(sp1C, b, c);
        uncompress(sp1C, D_801C1000);
        SetSegmentBase(a, D_801C1000);
        _pool_free(sp1C);
    }
    else
    {
    }
    return D_801C1000;
}

void CopyScriptInterpreter(void)
{
    void *sp24 = (void *)0x80378800;
    u32 sp20 = 0x17000;
    UNUSED u32 sp1C = ALIGN16(D_001076A0 - D_000F4210);

    bzero(sp24, sp20);
    osWritebackDCacheAll();
    DmaCopy(sp24, D_000F4210, D_001076A0);
    osInvalICache(sp24, sp20);
    osInvalDCache(sp24, sp20);
}

struct Struct80278464 *func_80278464(u32 a, u32 b)
{
    void *sp1C;
    struct Struct80278464 *sp18 = NULL;

    a = ALIGN4(a);
    sp1C = _pool_alloc(a + 16, b);
    if (sp1C != NULL)
    {
        sp18 = sp1C;
        sp18->unk0 = a;
        sp18->unk4 = 0;
        sp18->unk8 = (u8 *)sp1C + 16;
        sp18->unkC = (u8 *)sp1C + 16;
    }
    return sp18;
}

void *SimpleAllocate(struct Struct80278464 *a, s32 size)
{
    void *sp4 = NULL;

    size = ALIGN4(size);
    if (size > 0 && a->unk4 + size <= a->unk0)
    {
        sp4 = a->unkC;
        a->unkC += size;
        a->unk4 += size;
    }
    return sp4;
}

struct Struct80278464 *func_80278578(struct Struct80278464 *a, u32 size)
{
    struct Struct80278464 *sp1C;

    size = ALIGN4(size);
    sp1C = _pool_realloc(a, size + 16);
    if (sp1C != NULL)
        a->unk0 = size;
    return sp1C;
}

struct Struct80278464 *func_802785E8(u32 size, u32 b)
{
    void *sp24;
    struct Struct80278464 *sp20;
    struct Struct80278464 *sp1C = NULL;

    size = ALIGN4(size);
    sp24 = _pool_alloc(size + 16, b);
    if (sp24 != NULL)
    {
        sp1C = sp24;
        sp1C->unk0 = size;
        sp1C->unk4 = (u32)sp24 + 16;
        sp1C->unk8 = (u8 *)sp24 + 16;
        sp20 = (struct Struct80278464 *)sp1C->unk4;
        sp20->unk0 = 0;
        sp20->unk4 = sp1C->unk0;
    }
    return sp1C;
}

struct MemBlock *subPrint(struct MemBlock *a, u32 size)
{
    struct MemBlock *spC = a + 1;
    struct MemBlock *sp8 = NULL;
    struct MemBlock *sp4;

    size = ALIGN4(size) + 8;
    while (spC->next != NULL)
    {
        if (spC->next->size >= size)
        {
            sp8 = spC->next + 1;
            if (spC->next->size - size < 9)
            {
                spC->next = spC->next->next;
            }
            else
            {
                sp4 = (struct MemBlock *)((u8 *)spC->next + size);
                sp4->size = spC->next->size - size;
                sp4->next = spC->next->next;
                spC->next->size = size;
                spC->next = sp4;
            }
            break;
        }
        spC = spC->next;
    }
    return sp8;
}

void func_802787C4(struct UnknownMemoryStruct2 *a, struct MemBlock *b)
{
    struct MemBlock *sp4 = b - 1;
    struct MemBlock *sp0 = a->unk8;

    if (a->unk8 == NULL)
    {
        a->unk8 = sp4;
        sp4->next = NULL;
    }
    else
    {
        if (sp4 < a->unk8)
        {
            if (a->unk8 == (struct MemBlock *)((u8 *)sp4 + sp4->size))
            {
                sp4->size += sp0->size;
                sp4->next = sp0->next;
                a->unk8 = sp4;
            }
            else
            {
                sp4->next = a->unk8;
                a->unk8 = sp4;
            }
        }
        else
        {
            while (sp0->next != NULL)
            {
                if (sp0 < sp4 && sp4 < sp0->next)
                    break;
                sp0 = sp0->next;
            }
            if ((u8 *)sp0 + sp0->size == (u8 *)sp4)
            {
                sp0->size += sp4->size;
                sp4 = sp0;
            }
            else
            {
                sp4->next = sp0->next;
                sp0->next = sp4;
            }
            if (sp4->next != 0 && sp4->next == (struct MemBlock *)((u8 *)sp4 + sp4->size))
            {
                sp4->size = sp4->size + sp4->next->size;
                sp4->next = sp4->next->next;
            }
        }
    }
}

void *alloc_display_list(u32 size)
{
    void *ptr = NULL;

    size = ALIGN8(size);
    if (gGfxPoolEnd - size >= (u8 *)gDisplayListHead)
    {
        gGfxPoolEnd -= size;
        ptr = gGfxPoolEnd;
    }
    else
    {
    }
    return ptr;
}

void *dobjCopy(u8 *a)
{
    struct UnknownMemoryStruct3 *sp1C = DynamicCopy(a, a + 4, 0);
    u32 sp18 = sp1C->unk0 * 8 + 8;
    
    _pool_free(sp1C);
    sp1C = DynamicCopy(a, a + sp18, 0);
    sp1C->unk4 = a;
    return sp1C;
}

void DynamicObjectCopy(struct MarioAnimation *a, void *b, void *c)
{
    if (b != NULL)
        a->animDmaTable = dobjCopy(b);
    a->currentDma = 0;
    a->targetAnim = c;
}

int SetMarioAnimation(struct MarioAnimation *a, u32 b)
{
    int sp24 = 0;
    struct MarioAnimDmaRelatedThing *sp20 = a->animDmaTable;
    u32 sp1C;
    u32 sp18;

    if (b < sp20->unk0)
    {
        sp1C = sp20[0].unk4 + sp20[b + 1].unk0;
        sp18 = sp20[b + 1].unk4;

        if (a->currentDma != sp1C)
        {
            DmaCopy(a->targetAnim, (void *)sp1C, (void *)(sp1C + sp18));
            a->currentDma = sp1C;
            sp24 = 1;
        }
    }
    return sp24;
}
