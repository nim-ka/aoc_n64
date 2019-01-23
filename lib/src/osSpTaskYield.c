#include <ultra64.h>

s32 osSpTaskYield(void)
{
    return __osSpSetStatus(SPSTATUS_SET_SIGNAL0);
}
