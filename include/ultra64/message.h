#ifndef _ULTRA64_MESSAGE_H_
#define _ULTRA64_MESSAGE_H_

/* Events */
#define OS_EVENT_SW1           0
#define OS_EVENT_SW2           1
#define OS_EVENT_CART          2
#define OS_EVENT_COUNTER       3
#define OS_EVENT_SP            4
#define OS_EVENT_SI            5
#define OS_EVENT_AI            6
#define OS_EVENT_VI            7
#define OS_EVENT_PI            8
#define OS_EVENT_DP            9
#define OS_EVENT_CPU_BREAK    10
#define OS_EVENT_SP_BREAK     11
#define OS_EVENT_FAULT        12
#define OS_EVENT_THREADSTATUS 13
#define OS_EVENT_PRENMI       14


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
