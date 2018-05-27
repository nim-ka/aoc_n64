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

extern struct Struct8032C620 *D_8032C620;
extern struct Struct8032C620 *D_8032C624;
extern struct Struct8032C630 *D_8032C628;
extern struct Struct8032C630 *D_8032C62C;
extern struct Struct8032C630 *D_8032C630;
extern OSMesg D_8032C634;
extern OSMesg D_8032C638;
extern s8 D_8032C63C;
extern u32 D_8032C640;
extern s8 gResetTimer;
extern s8 D_8032C648;
extern s8 gDebugLevelSelect;
extern s8 D_8032C650;
extern s8 gShowResourceMeter;
extern s8 gShowDebugText;

extern u8 D_80200A00[];
extern u8 D_80203200[];
extern u8 D_80205200[];
extern u8 D_80201200[];

extern void func_80246B14(int a, struct Struct8032C620 *b, OSMesgQueue *queue, OSMesg *msg);
extern void func_80246BB4(OSMesg *msg);
extern void SendDisplayList(struct Struct8032C630 *a);
extern void Main(void);

#endif
