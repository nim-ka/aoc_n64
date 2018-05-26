#ifndef _MARIO_H
#define _MARIO_H

#include "types.h"

extern u32 D_80226EB8;
// extern ? D_80335280;
// extern ? D_80335288;
// extern ? D_80335290;
// extern ? D_8032CB80;
// extern ? D_8032CB84;
// extern ? D_80339F10;
extern struct Object *gMarioObject;

extern u32 func_80250770(struct MarioState *);
extern u32 func_802507AC(struct MarioState *);
extern s16 func_802507E8(struct MarioState *, s16);
extern void func_80250934(struct MarioState *, s16, s32);
extern void func_80250AAC(struct MarioState *, u32);
extern s32 func_80250B68(struct MarioState *, s32);
// extern ? func_80250C84(?);
// extern ? func_80250E50(?);
extern s16 func_80250F0C(struct MarioState *);
extern void func_80250F50(struct MarioState *, u32, u32);
extern void func_80250FBC(struct MarioState *);
extern void func_80251048(struct MarioState *);
// extern ? func_802510E4(?);
// extern ? func_80251218(?);
extern void func_80251280(struct MarioState *, u32);
// extern ? func_802512E4(?);
extern void func_80251348(struct MarioState *, u32);
// extern ? func_802513AC(?);
extern void func_80251410(struct MarioState *, u32, u32);
extern void func_802514DC(struct MarioState *m, f32 speed);
// extern ? func_80251550(?);
extern u32 func_8025167C(struct MarioState *);
extern struct Surface *func_8025181C(Vec3f, f32, f32);
extern f32 func_802518D0(Vec3f, f32, struct Surface **);
// extern ? func_80251928(?);
extern u32 func_802519A8(struct MarioState *);
// extern ? func_80251AD0(?);
// extern ? func_80251BF8(?);
extern float func_80251CF8(struct MarioState *, int, float);
extern s16 func_80251DD4(struct MarioState *, s32);
extern void func_80251F74(struct MarioState *);
// extern ? func_80252070(?);
// extern ? func_8025219C(?);
// extern ? func_80252234(?);
// extern ? func_802527B8(?);
// extern ? func_802529A8(?);
// extern ? func_802529EC(?);
extern u32 set_mario_action(struct MarioState *, u32, u32);
// extern ? func_80252C30(?);
// extern ? func_80252E74(?);
extern s32 drop_and_set_mario_action(struct MarioState *, u32, u32);
// extern ? func_80252F98(?);
extern int func_80252FEC(struct MarioState *);
// extern ? func_802530D4(?);
extern s32 func_802531B8(struct MarioState *);
extern u32 func_8025325C(struct MarioState *);
// extern ? func_8025335C(?);
// extern ? func_802534F4(?);
// extern ? func_8025360C(?);
// extern ? func_80253730(?);
// extern ? func_80253834(?);
// extern ? func_80253B2C(?);
// extern ? func_80253C94(?);
// extern ? func_80253E34(?);
// extern ? func_80254088(?);
// extern ? func_8025410C(?);
// extern ? func_80254164(?);
// extern ? func_802541BC(?);
// extern ? func_8025435C(?);
// extern ? Unknown8025453C(?);
extern s32 func_80254604(struct Object *);
extern void func_802548BC(void);
extern void func_80254CE0(void);

#endif /* _MARIO_H */
