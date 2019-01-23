#include <ultra64.h>
extern OSMgrArgs piMgrArgs;

OSMesgQueue *osPiGetCmdQueue(void)
{
    if (!piMgrArgs.initialized)
        return NULL;
    return piMgrArgs.unk08;
}
