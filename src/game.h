#ifndef _GAME_H_
#define _GAME_H_

extern struct Controller gControllers[3];
extern OSContStatus gControllerStatuses[4];
extern OSContPad gControllerPads[4];
extern OSMesgQueue D_80339CA0;
extern OSMesgQueue D_80339CB8;
extern OSMesg D_80339CD0;
extern OSMesg D_80339CD4;
extern struct Struct8032C620 D_80339CD8;
extern u32 gFrameBuffers[3];
extern u32 D_80339CEC;
extern void *D_80339CF0;
extern void *D_80339CF4;
extern struct Struct8032C630 *D_80339CF8;
extern Gfx *gDisplayListHead;
extern u8 *gGfxPoolEnd;
extern Gfx *D_80339D04;
extern u8 gControllerBits;
extern s8 gEepromProbe;

extern void (*D_8032C6A0)(void);
extern struct Controller *gPlayer1Controller;
extern struct Controller *D_8032C6A8;
extern struct Controller *gPlayer2Controller;
extern struct DemoInput *gCurrDemoInput;
extern u16 gDemoInputListID;
extern struct DemoInput gRecordedDemoInput;

#endif
