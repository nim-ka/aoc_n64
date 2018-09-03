#ifndef _MAIN_H_
#define _MAIN_H_

extern OSThread D_80339210;
extern OSThread gIdleThread;
extern OSThread gMainThread;
extern OSThread gGameLoopThread;
extern OSThread gSoundThread;
extern OSMesgQueue gPIMesgQueue;
extern OSMesgQueue gIntrMesgQueue;
extern OSMesgQueue gUnknownMesgQueue;
extern OSMesg gDmaMesgBuf[1];
extern OSMesg gPIMesgBuf[32];
extern OSMesg gSIEventMesgBuf[1];
extern OSMesg gIntrMesgBuf[16];
extern OSMesg gUnknownMesgBuf[16];
extern OSIoMesg gDmaIoMesg;
extern OSMesg D_80339BEC;
extern OSMesgQueue gDmaMesgQueue;
extern OSMesgQueue gSIEventMesgQueue;

extern struct VblankHandler *gVblankHandler1;
extern struct VblankHandler *gVblankHandler2;
extern struct SPTask *gCurrentSPTask;
extern struct SPTask *D_8032C62C;
extern struct SPTask *D_8032C630;
extern OSMesg D_8032C634;
extern OSMesg D_8032C638;
extern s8 D_8032C63C;
extern u32 D_8032C640;
extern s8 gResetTimer;
extern s8 D_8032C648;
extern s8 gDebugLevelSelect;
extern s8 D_8032C650;
extern s8 gShowProfiler;
extern s8 gShowDebugText;

extern u8 gIdleThreadStack[];
extern u8 gThread4Stack[];
extern u8 gThread5Stack[];
extern u8 gThread3Stack[];

extern void set_vblank_handler(int a, struct VblankHandler *b, OSMesgQueue *queue, OSMesg *msg);
extern void func_80246BB4(OSMesg *msg);
extern void SendDisplayList(struct SPTask *a);
extern void Main(void);

#endif
