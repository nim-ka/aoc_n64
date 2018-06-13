#ifndef _RESOURCE_METER_H
#define _RESOURCE_METER_H

#include "types.h"

extern s16 D_8032CFB0;
extern s16 D_8032CFB4;
// extern ? D_8033B020;
extern s16 D_8032CFB8;
extern u64 osClockRate;

void func_8027DE30(int arg0);
void func_8027DEE0(void);
void func_8027DF70(int arg0);
void func_8027E01C(void);
void draw_meter_bar(s64 arg0, s64 arg1, s64 arg2, s16 arg3, u16 color);
void draw_reference_meter_bars(void);
void func_8027E61C(void);
void func_8027E8FC(void);
void draw_resource_meter(void);

#endif /* _RESOURCE_METER_H */
