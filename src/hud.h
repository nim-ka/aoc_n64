#ifndef _HUD_H
#define _HUD_H

#include "types.h"

// extern ? D_8035FB18;
// extern ? D_8035FB30;
// extern ? D_8035FB31;
// extern ? beh_bbh_tilt_floor_platforms;
// extern ? beh_bbh_tumbling_platform_group;
// extern ? beh_tumbling_bookshelf;
// extern ? beh_mesh_elevator;
// extern ? D_030293E0;
// extern ? D_803314E2;
// extern ? D_803314E4;
// extern ? D_03029480;
// extern ? D_03029570;
// extern ? D_030295A0;
// extern ? D_803314EC;
// extern ? D_803314E0;
// extern ? D_803600D0;
// extern ? D_803371A0;
// extern ? D_803371A4;
// extern ? D_803371A8;
// extern ? D_803371AC;
// extern ? D_803371B0;
// extern ? D_803371B4;
// extern ? D_803371B8;
// extern ? D_803371BC;
// extern ? D_803371C0;
// extern ? D_803371C4;
// extern ? D_803371C8;
// extern ? D_803371D0;
// extern ? D_803371D4;
// extern ? D_803371DC;
// extern ? D_803314F8;
// extern ? seg2_hud_camera_lut;

extern void func_802E1504(s16, s16 *);
extern void func_802E1780(s16, s16 *);
extern void func_802E19DC(s16, s16 **);
extern s16 func_802E1190(s16);
extern void func_802E1224(u32, void *, s16, s16, s16, s16, s16);
extern void func_802E12CC(u32, void *, s16, s16, s16, s16, s16);
extern void func_802E1374(u32, void *, s16, s16, s16, s16, s16, s16);
extern void Unknown802E142C(void *, s16[]);
// extern ? RenderHudCamera(?);
// extern ? RenderHudCButtons(?);
// extern ? func_802E21A4(?);
// extern ? func_802E2304(?);
// extern ? func_802E24A8(?);
// extern ? func_802E2520(?);
// extern ? func_802E25D4(?);
// extern ? func_802E261C(?);
// extern ? RenderHudHp(?);
// extern ? RenderHudMarioLives(?);
// extern ? RenderHudCoins(?);
// extern ? RenderHudStars(?);
// extern ? func_802E29D4(?);
// extern ? RenderHudTimer(?);
// extern ? SetCameraStatus(?);
// extern ? ShowCameraStatus(?);
extern void RenderHud();

#endif /* _HUD_H */
