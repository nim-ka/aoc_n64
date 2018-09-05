#ifndef _DISPLAY_H
#define _DISPLAY_H

#include "types.h"

#define GFX_POOL_SIZE 6400

struct GfxPool {
    Gfx buffer[GFX_POOL_SIZE];
    struct SPTask spTask;
};

extern u16 D_8032C69C;
extern u8 gGfxSPTaskStack[];
extern u8 gGfxSPTaskOutputBuffer[];
extern u8 gGfxSPTaskYieldBuffer[];
extern struct GfxPool gGfxPools[2];
extern u32 gGlobalTimer;

// extern ? myRdpInit(?);
// extern ? myRspInit(?);
// extern ? ClearZBuffer(?);
// extern ? DisplayFrameBuffer(?);
extern void ClearFrameBuffer(int);
extern void DisplayInit(Vp *, int);
// extern ? func_8024781C(?);
void func_8024798C(Vp *viewport);
extern void func_80247C9C(void);
extern void CleanupDisplayList(void);
extern void func_80247D84(void);
extern void func_80247ED8(void);
extern void func_80247FAC(void);
extern void display_and_vsync(void);

#endif /* _DISPLAY_H */
