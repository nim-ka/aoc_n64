#ifndef _ULTRA64_VI_H_
#define _ULTRA64_VI_H_

/* Ultra64 Video Interface */

/* Types */

typedef struct
{
    u32 ctrl;
    u32 width;
    u32 burst;
    u32 vSync;
    u32 hSync;
    u32 leap;
    u32 hStart;
    u32 xScale;
    u32 vCurrent;
} OSViCommonRegs;

typedef struct
{
    u32 origin;
    u32 yScale;
    u32 vStart; 
    u32 vBurst;
    u32 vIntr;
} OSViFieldRegs;

typedef struct
{
    u8 type;
    OSViCommonRegs comRegs;
    OSViFieldRegs fldRegs[2];
} OSViMode;


/* Functions */

void osCreateViManager(OSPri pri);
void osViSetMode(OSViMode *mode);
void osViBlack(u8 active);
void osViSetSpecialFeatures(u32 func);
void osViSwapBuffer(void *vaddr);

#endif
