#ifndef _DEBUG_MEMORY_H
#define _DEBUG_MEMORY_H

#include "types.h"

struct GMemBlock {
    /* 0x00 */ union {
        void* ptr;
        u32 addr;   //! assumes 32bit pointers; use uintptr_t
    } data;
    /* 0x04 */ u32 size;
    /* 0x08 */ u8 blockType;
    /* 0x09 */ u8 permFlag;     /* Permanent (upper nibble bits set) or Temporary (lower nibble) */
    /* 0x0A    u8 fieldAlginment[2]; */
    /* 0x0C */ struct GMemBlock* next;
    /* 0x10 */ struct GMemBlock* prev;
};
/* Block Type Defines */
#define FREE_G_MEM_BLOCK 1
#define USED_G_MEM_BLOCK 2

/****** functions ******/
extern u32 free_mem_block(void*);
extern void* request_mem_block(u32, u8);
extern struct GMemBlock* make_free_mem_block(u32, u32, u8);
extern void init_mem_block_lists(void);
extern void mem_stats(void);

#endif /* _DEBUG_MEMORY_H */
