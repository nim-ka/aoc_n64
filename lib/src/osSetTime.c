#include <ultra64.h>
extern OSTime _osCurrentTime;
void osSetTime(OSTime time)
{
    _osCurrentTime = time;
}
