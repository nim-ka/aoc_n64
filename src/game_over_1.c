#include <ultra64.h>

#include "sm64.h"

void func_801780A0()
{
    D_801B9B24 = 0;
    D_801B9B20 = 0;
}

u32 func_801780C0()
{
    return ~D_801B9B24 & D_801B9B20;
}

void func_801780EC()
{
    D_801B9B24 = D_801B9B20;
    D_801B9B20 = 0;
}

void func_80178114(u32 a0)
{
    D_801B9B20 |= a0;
}
