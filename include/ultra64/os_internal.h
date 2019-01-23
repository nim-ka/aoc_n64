#ifndef _ULTRA64_OS_INTERNAL_H_
#define _ULTRA64_OS_INTERNAL_H_

/* Internal functions used by the operating system */
/* Do not include this header in application code */

typedef struct
{
    u32 initialized; //probably something like initialized?
    OSThread *mgrThread;
    OSMesgQueue *unk08;
    OSMesgQueue *unk0c;
    OSMesgQueue *unk10;
    s32 (*dma_func)(s32,u32,void*,u32);
    u64 force_align;
} OSMgrArgs;

/* Variables */

//extern u64 osClockRate;

/* Functions */

/*u32 __osProbeTLB(void *);
u32 __osDisableInt(void);
void __osRestoreInt(u32);*/
s32 osEepromProbe(OSMesgQueue *mq);

#endif
