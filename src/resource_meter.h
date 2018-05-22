#ifndef _RESOURCE_METER_H
#define _RESOURCE_METER_H

#include "types.h"

// extern ? D_8032CFB4;
// extern ? D_8033B020;
// extern ? D_8032CFB8;
extern u64 osClockRate;
// extern ? D_8032CFB0;

extern void func_8027DE30(int);
extern void func_8027DEE0(void);
void func_8027DF70();
extern void func_8027E01C(void);
// extern ? func_8027E0AC(?);
// extern ? func_8027E3A8(?);
// extern ? func_8027E61C(?);
// extern ? func_8027E8FC(?);
extern void draw_resource_meter(void);

#endif /* _RESOURCE_METER_H */
