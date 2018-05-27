#ifndef _DISPLAY_H
#define _DISPLAY_H

#include "types.h"

extern u16 D_8032C69C;
extern u8 D_80207D00[];
extern u8 D_80227000[];
extern u8 D_80207200[];
extern Gfx D_80208100[];
extern u32 D_8032C694;

// extern ? myRdpInit(?);
// extern ? myRspInit(?);
// extern ? ClearZBuffer(?);
// extern ? DisplayFrameBuffer(?);
extern void ClearFrameBuffer(int);
extern void DisplayInit(Vp *, int);
// extern ? func_8024781C(?);
void func_8024798C(Vp *viewport);
// extern ? CreateTaskStructure(?);
extern void func_80247C9C(void);
extern void CleanupDisplayList(void);
extern void func_80247D84(void);
extern void func_80247ED8(void);
extern void func_80247FAC(void);
extern void func_80248060(void);

#endif /* _DISPLAY_H */
