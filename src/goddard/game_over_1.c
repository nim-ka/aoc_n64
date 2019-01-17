#include <ultra64.h>

#include "sm64.h"

static u32 D_801B9B20;
static u32 D_801B9B24;

void func_801780A0(void)
{
    D_801B9B24 = 0;
    D_801B9B20 = 0;
}

u32 func_801780C0(void)
{
    return ~D_801B9B24 & D_801B9B20;
}

void func_801780EC(void)
{
    D_801B9B24 = D_801B9B20;
    D_801B9B20 = 0;
}

void func_80178114(u32 a0)
{
    D_801B9B20 |= a0;
}
