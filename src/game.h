#ifndef _GAME_H_
#define _GAME_H_

#include "memory.h"

struct DemoInput
{ // TODO: see if timer matches with s8
 /*0x00*/ u8 timer; // until next input: if this value 
                    // is 0 proceeding on the demo input, it 
                    // means the demo is over.
 /*0x01*/ s8 rawStickX;
 /*0x02*/ s8 rawStickY;
 /*0x03*/ u8 button;
};

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
extern struct SPTask *D_80339CF8;
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

// extern ? init_controllers(?);
// extern ? func_80248934(?);
extern void thread5_game_loop(void *);
extern u16 func_802495B0(u32);

// this area is the demo input + the header. when the demo is loaded in, there is a header the size
// of a single word next to the input list. this word is the current ID count.
extern struct MarioAnimation gDemo; // gDemo
extern struct DemoInput *gDemoInputList;
extern struct MarioAnimation D_80339D10;

extern u8 D_80000400[];
extern u8 D_004E9FA0[];
extern u8 D_00577BC0[];
extern u8 D_10000000[];

#endif
