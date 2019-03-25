#ifndef _MARIO_ACTIONS_CUTSCENE_H
#define _MARIO_ACTIONS_CUTSCENE_H

#include "types.h"

extern void print_displaying_credits_entry(void);
extern void BehEndPeachLoop(void);
extern void BehEndToadLoop(void);
extern s32 GeoSwitchCase80257198(s32, struct Object *, s32);
extern s32 mario_ready_to_speak(void);
extern s32 set_mario_npc_dialogue(s32);
extern s32 mario_execute_cutscene_action(struct MarioState *);

#endif /* _MARIO_ACTIONS_CUTSCENE_H */