#ifndef _MEMORY_H_
#define _MEMORY_H_

struct MemBlock
{
    struct MemBlock *next;
    u32 size;
};


struct UnknownMemoryStruct2
{
    u32 unk0;
    u32 unk4;
    struct MemBlock *unk8;
};

extern u32 gMemPoolStart;
extern u32 gMemPoolEnd;
extern u32 gPoolSize;
//extern u32 gPoolListHeadL;
//extern u32 gPoolListHeadR;
extern u8 D_801C1000[];
extern u8 _engineSegmentRomStart[];
extern u8 _engineSegmentRomEnd[];

extern int set_segment_base_addr(int segment, void *addr);
extern int get_segment_base_addr(int segment);
extern void *segmented_to_virtual(void *addr);
extern void *virtual_to_segmented(u32 segment, void *addr);
extern void MovePtrTbl2Dmem(void);
extern void InitMemPool(u32 start, u32 end);
extern void *_pool_alloc(u32 size, int b);
extern u32 _pool_free(void *ptr);
extern void *_pool_realloc(void *ptr, u32 size);
extern u32 PoolAvailable(void);
extern u32 PushPoolState(void);
extern u32 PopPoolState(void);
extern void *load_from_rom(u32 segment, u8 *srcStart, u8 *srcEnd, u32 allocSize);
void *FixedCopy(u32 a, u8 *srcStart, u8 *srcEnd);
void *load_from_rom_decompress(int segment, u8 *srcStart, u8 *srcEnd);
void *func_80278304(u32 segment, u8 *srcStart, u8 *srcEnd);
void CopyScriptInterpreter(void);
struct Struct80278464 *func_80278464(u32 a, u32 b);
void *SimpleAllocate(struct Struct80278464 *a, s32 size);
struct Struct80278464 *func_80278578(struct Struct80278464 *a, u32 size);
struct Struct80278464 *func_802785E8(u32 size, u32 b);
struct MemBlock *subPrint(struct MemBlock *a, u32 size);
void func_802787C4(struct UnknownMemoryStruct2 *a, struct MemBlock *b);
void *alloc_display_list(u32 size);
void *dobjCopy(u8 *a);
void DynamicObjectCopy(struct MarioAnimation *a, void *b, void *c);
int SetMarioAnimation(struct MarioAnimation *a, u32 b);

#endif
