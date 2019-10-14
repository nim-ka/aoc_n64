#ifndef _BEHAVIOR_ACTIONS_H
#define _BEHAVIOR_ACTIONS_H

extern void func_802AA618(s32,s32,f32);
extern void bhv_spawn_star_objects(u32);
extern void bhv_star_door_loop_2();
extern void spawn_triangle_break_particles(s16,s16,f32,s16);
extern void func_802ADA94(void);
extern void func_802ADBBC(u32);
extern void func_802ADC20(s16,s16);
extern s32 func_802B0C54(f32,f32);
extern s32 func_802B2894(f32*,f32*,f32,f32);
void func_802B8F7C(Vec3f dest,Vec3f src);
extern void func_802BCFC4(f32,f32,s16,s16);
extern void play_penguin_walking_sound(s32);
extern s32 func_802C5A64(s32*);
extern void func_802C76E0(s32, f32, f32, f32, f32);

extern s32 Geo18_802B1BB0(s32 run, UNUSED struct GraphNode *node, Mat4 mtx);

// Bowser
extern Gfx *Geo18_802B7D44(s32 a0, struct GraphNode *node, UNUSED s32 a2);
extern Gfx *Geo18_802B798C(s32 run, UNUSED struct GraphNode *node, Mat4 mtx);
extern s32 geo_switch_bowser_eyes(s32 run, struct GraphNode *node, UNUSED Mat4 *mtx);

// Tuxie
extern s32 geo_switch_tuxie_mother_eyes(s32 run, struct GraphNode *node, UNUSED Mat4 *mtx);

// Cap switch
extern Gfx *Geo18_802A719C(s32 run, UNUSED struct GraphNode *node, Mat4 mtx);

// Snufit
extern Gfx *Geo18_8030D93C(s32 arg0, struct GraphNode *node, UNUSED void *arg2);
extern Gfx *Geo18_8030D9AC(s32 arg0, struct GraphNode *node, UNUSED void *arg2);

// Bowser key cutscene
extern Gfx *Geo18_802BA2B0(s32 run, struct GraphNode *node, UNUSED f32 mtx[4][4]);

#endif // _BEHAVIOR_ACTIONS_H
