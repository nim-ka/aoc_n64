#ifndef _ULTRA64_MESSAGE_H_
#define _ULTRA64_MESSAGE_H_

/* Types */

typedef u32 OSEvent;

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
void osSetEventMesg(OSEvent, OSMesgQueue *, OSMesg);
void osViSetEvent(OSMesgQueue *mq, OSMesg msg, u32 retraceCount);
s32 osContStartReadData(OSMesgQueue *);

#endif
