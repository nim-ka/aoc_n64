#ifndef _ULTRA64_TLB_H_
#define _ULTRA64_TLB_H_

/* Types */

typedef u32 OSPageMask;

/* Functions */

void osMapTLB(s32 index, OSPageMask pm, void *vaddr, u32 evenpaddr, 
    u32 oddpaddr, s32 asid);
void osMapTLBRdb(void);
void osUnmapTLB(s32 index);
void osUnmapTLBAll(void);
void osSetTLBASID(s32 asid);

#endif
