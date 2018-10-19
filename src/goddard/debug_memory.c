#include <ultra64.h>

#include "sm64.h"
#include "debug_memory.h"
#include "profiler_utils.h"
#include "../mario_head_6.h"

// This dummy struct seems to be needed for the bss variables to
// come in correct order, apparently...
struct DummyStruct { int dummy; };

/* bss */
static struct GMemBlock* sFreeBlockListHead;
static struct GMemBlock* sUsedBlockListHead;
static struct GMemBlock* sEmptyBlockListHead;

/* Forward Declarations */
void empty_mem_block(struct GMemBlock*);
struct GMemBlock* into_free_mem_block(struct GMemBlock* oldBlock);
struct GMemBlock* make_mem_block(u32, u8);
u32 print_list_stats(struct GMemBlock*, s32, s32);

/* @ 225EB0 for 0x104; orig name: func_801776E0 */
void empty_mem_block(struct GMemBlock* block)
{
    if (block->next != NULL)
        block->next->prev = block->prev;

    if (block->prev != NULL)
        block->prev->next = block->next;

    switch (block->blockType)
    {
        case FREE_G_MEM_BLOCK:
            if (block->prev == NULL)
                sFreeBlockListHead = block->next;
            break;
        case USED_G_MEM_BLOCK:
            if (block->prev == NULL)
                sUsedBlockListHead = block->next;
            break;
    }

    block->next = sEmptyBlockListHead;
    if (block->next != NULL)
        sEmptyBlockListHead->prev = block;
    
    sEmptyBlockListHead = block;
    block->prev = NULL;
    block->data.ptr = NULL;
    block->size = 0;
}

/* @ 225FB4 for 0xB8; orig name: func_801777E4 */
struct GMemBlock* into_free_mem_block(struct GMemBlock* oldBlock)
{
    struct GMemBlock* newBlock;
    void* data_ptr;
    u8 permanence;
    u32 space;

    data_ptr = oldBlock->data.ptr;
    space = oldBlock->size;
    permanence = oldBlock->permFlag;

    empty_mem_block(oldBlock);
    newBlock = make_mem_block(FREE_G_MEM_BLOCK, permanence);
    newBlock->data.ptr = data_ptr;
    newBlock->size = space;
    newBlock->permFlag = permanence;

    return newBlock;
}

/* @ 22606C for 0x1DC; orig name: MakeMemBlock */
struct GMemBlock* make_mem_block(u32 blockType, u8 permFlag)
{
    struct GMemBlock* newMemBlock;

    if (sEmptyBlockListHead == NULL)
    {
        sEmptyBlockListHead = (struct GMemBlock*) gd_allocblock(sizeof(struct GMemBlock));
        //! missing early return
        if (sEmptyBlockListHead == NULL)
            myPrintf("MakeMemBlock() unable to allocate");

        sEmptyBlockListHead->next = NULL;
        sEmptyBlockListHead->prev = NULL;
    }

    newMemBlock = sEmptyBlockListHead;
    if ((sEmptyBlockListHead = newMemBlock->next) != NULL)
        newMemBlock->next->prev = NULL;

    switch (blockType)
    {
        case FREE_G_MEM_BLOCK:
            newMemBlock->next = sFreeBlockListHead;
            if (newMemBlock->next != NULL) 
               sFreeBlockListHead->prev = newMemBlock;
            sFreeBlockListHead = newMemBlock;
            break;
        case USED_G_MEM_BLOCK:
            newMemBlock->next = sUsedBlockListHead;
            if (newMemBlock->next != NULL)
                sUsedBlockListHead->prev = newMemBlock;
            sUsedBlockListHead = newMemBlock;
            break;
        default:
            myPrintf("unkown memblock type");
    }
    newMemBlock->prev = NULL;
    newMemBlock->blockType = (u8) blockType;
    newMemBlock->permFlag = permFlag;

    return newMemBlock;
}

/* @ 226248 for 0xA0; orig name: Free */
u32 free_mem_block(void* data)
{
    register struct GMemBlock* curBlock;
    u32 bytesFreed;
    register void* targetBlock; /* use as an int type instead of comparing pointer types? */

    targetBlock = data;

    for (curBlock = sUsedBlockListHead; curBlock != NULL; curBlock = curBlock->next)
    {
        if (targetBlock == curBlock->data.ptr)
        {
            bytesFreed = curBlock->size;
            into_free_mem_block(curBlock);
            return bytesFreed;
        }
    }

    myPrintf("Free() Not a valid memory block");
    return 0;
}

/* @ 2262E8 for 0x224; orig name: func_80177B18 */
void* request_mem_block(u32 size, u8 permanence)
{
    struct GMemBlock* foundBlock = NULL;
    struct GMemBlock* curBlock;
    struct GMemBlock* newBlock;

    newBlock = make_mem_block(USED_G_MEM_BLOCK, permanence);
    curBlock = sFreeBlockListHead;

    while (curBlock != NULL)
    {
        if (curBlock->permFlag & permanence)
        {
            if (curBlock->size == size)
            {
                foundBlock = curBlock;
                break;
            } else {
                if (curBlock->size > size)
                {
                    if (foundBlock != NULL) 
                    {   /* find closest sized block */
                        if (curBlock->size < foundBlock->size) 
                            foundBlock = curBlock;
                    } else {
                        foundBlock = curBlock;
                    }
                }
            }
        }
        curBlock = curBlock->next;
    }

    if (foundBlock == NULL)
        return NULL;

    if (foundBlock->size > size)
    {   /* split free block */
        newBlock->data.ptr = foundBlock->data.ptr;
        newBlock->size = size;

        foundBlock->size -= size;
        foundBlock->data.addr += size;
    } 
    else if (foundBlock->size == size) 
    {   /* recycle whole free block */
        newBlock->data.ptr = foundBlock->data.ptr;
        newBlock->size = size;
        empty_mem_block(foundBlock);
    }

    return newBlock->data.ptr;
}

/* @ 22650C for 0x90; orig name: func_80177D3C */
struct GMemBlock* make_free_mem_block(u32 size, u32 addr, u8 permanence)
{
    struct GMemBlock* newBlock;
    /* eight-byte align the new block's data stats */ 
    size = (size - 8) & ~7;
    addr = (addr + 8) & ~7;

    newBlock = make_mem_block(FREE_G_MEM_BLOCK, permanence);
    newBlock->data.addr = addr;
    newBlock->size = size;

    return newBlock;
}

/* @ 22659C for 0x28; orig name: func_80177DCC*/
void init_mem_block_lists(void)
{
    sFreeBlockListHead = NULL;
    sUsedBlockListHead = NULL;
    sEmptyBlockListHead = NULL;
}

/* @ 2265C4 for 0x17C; orig name: func_80177DF4 */
u32 print_list_stats(struct GMemBlock* block, s32 printBlockInfo, s32 permanence)
{
    u32 entries = 0;
    u32 totalSize = 0;

    while (block != NULL)
    {
        if (block->permFlag & permanence)
        {
            entries++;
            if (printBlockInfo)
                printf("     %6.2fk (%d bytes)\n", 
                       (f32) block->size / 1024.0,  //! 1024.0f
                       block->size
                    );
            totalSize += block->size;
        }
        block = block->next;
    }
    
    printf("Total %6.2fk (%d bytes) in %d entries\n", 
           (f32) totalSize / 1024.0,    //! 1024.0f
           totalSize, 
           entries
        );

    return entries;
}

/* @ 226740 for 0x12C; orig name: MemStats*/
void mem_stats(void)
{
    struct GMemBlock* list;

    printf("Perm Used blocks:\n");
    list = sUsedBlockListHead;
    print_list_stats(list, FALSE, 0xF0);
    printf("\n");

    printf("Perm Free blocks:\n");
    list = sFreeBlockListHead;
    print_list_stats(list, FALSE, 0xF0);
    printf("\n");

    printf("Temp Used blocks:\n");
    list = sUsedBlockListHead;
    print_list_stats(list, FALSE, 0x0F);
    printf("\n");

    printf("Temp Free blocks:\n");
    list = sFreeBlockListHead;
    print_list_stats(list, FALSE, 0x0F);
    printf("\n");

    printf("Empty blocks:\n");
    list = sEmptyBlockListHead;
    print_list_stats(list, FALSE, 0xFF);
}

/*
                          ::::::
            MMMMMMMMMM    ::::::
          MMMMMMMMMMMMMMMMMM::::
          SSSSSS::::SS::  SSSSSS
        SS::SS::::::SS::::::SSSS
        SS::SSSS::::::SS::::::SS
        SSSS::::::::SSSSSSSSSS
            ::::::::::::::SS
    SSSSSSSSSSMMSSSSSSMMSS
  SSSSSSSSSSSSSSMMSSSSSSMM    SS
::::SSSSSSSSSSSSMMMMMMMMMM    SS
::::::    MMSSMMMMMM::MM::MMSSSS
  ::  SS  MMMMMMMMMMMMMMMMMMSSSS
    SSSSSSMMMMMMMMMMMMMMMMMMSSSS
  SSSSSSMMMMMMMMMMMMMM
  SS    MMMMMMMM
*/
