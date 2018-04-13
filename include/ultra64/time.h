#ifndef _ULTRA64_TIME_H_
#define _ULTRA64_TIME_H_

/* Types */

typedef u64 OSTime;


/* Functions */

OSTime osGetTime(void);
void osSetTime(OSTime time);

#endif
