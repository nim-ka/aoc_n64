#ifndef _ULTRA64_MESSAGE_H_
#define _ULTRA64_MESSAGE_H_

/* Types */

typedef void *OSMesg;

typedef struct OSMesgQueue_s
{
    OSThread *mtqueue;
    OSThread *fullqueue;
    s32 validCount;
    s32 first;
    s32 msgCount;
    OSMesg *msg;
} OSMesgQueue;


/* Functions */

void osCreateMesgQueue(OSMesgQueue *, OSMesg *, s32);
s32 osSendMesg(OSMesgQueue *, OSMesg, s32);
s32 osJamMesg(OSMesgQueue *, OSMesg, s32);
s32 osRecvMesg(OSMesgQueue *, OSMesg *, s32);

#endif
