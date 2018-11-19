#ifndef OBJECT_HELPERS2_H
#define OBJECT_HELPERS2_H

#include "types.h"

#define WAYPOINT_FLAGS_END -1
#define WAYPOINT_FLAGS_INITIALIZED 0x8000
#define WAYPOINT_MASK_00FF 0x00FF

#define PATH_NONE 0
#define PATH_REACHED_END -1
#define PATH_REACHED_WAYPOINT 1

struct GraphNode_802A45E4 {
    /*0x00*/ s8 filler0[0x18 - 0x00];
    /*0x18*/ s16 unk18;
    /*0x1A*/ s16 unk1A;
    /*0x1C*/ s16 unk1C;
    /*0x1E*/ s16 unk1E;
    /*0x20*/ s16 unk20;
    /*0x22*/ s16 unk22;
};

struct Struct802A2CFC {
    s32 unk0;
    u8 unk4;
    s8 unk5;
    s8 unk6;
    s8 unk7;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
};

extern void set_object_hitbox(struct Object* obj, struct ObjectHitbox *arg1);
// extern ? signum_positive(?);
extern f32 absf(f32);
extern s32 absi(s32 a0);
s32 func_802A2EFC(s32 a0, s32 a1);
s32 obj_is_mario_ground_pounding_platform(void);
extern void func_802A3004(void);
extern void func_802A3034(s32 sp18);
// extern ? obj_push_mario_away(?);
void obj_push_mario_away_from_cylinder(f32 sp20, f32 sp24);
// extern ? BehDustSmokeLoop(?);
// extern ? func_802A32A4(?);
// extern ? func_802A32E0(?);
// extern ? nop_802A3380(?);
// extern ? func_802A3398(?);
// extern ? func_802A3470(?);
// extern ? obj_is_mario_on_platform(?);
// extern ? obj_shake_y_until(?);
// extern ? func_802A362C(?);
// extern ? obj_call_action_function(?);
// extern ? func_802A36D8(?);
// extern ? Unknown802A3750(?);
// extern ? func_802A377C(?);
s32 obj_mario_far_away(void);
// extern ? obj_is_mario_moving_fast_or_in_air(?);
// extern ? item_in_array(?);
extern void bhv_init_room(void); // 802A3978
extern void obj_enable_rendering_if_mario_in_room(void);
// extern ? obj_set_hitbox_and_die_if_attacked(?);
void func_802A3C98(f32 sp18, s32 sp1C);
// extern ? set_object_collision_data(?);
// extern ? obj_if_hit_wall_bounce_away(?);
// extern ? obj_hide_if_mario_far_away_y(?);
// extern ? Geo18_802A45E4(?);
// extern ? Unknown802A3E84(?);
// extern ? obj_is_hidden(?);
// extern ? enable_time_stop(?);
// extern ? disable_time_stop(?);
void set_time_stop_flag(s32);
void clear_time_stop_flag(s32);
// extern ? func_802A3FF8(?);
extern s32 obj_is_mario_in_range_and_ready_to_speak(f32 sp18, f32 sp1C);
// extern ? obj_end_dialogue(?);
// extern ? obj_update_dialogue_unk1(?);
extern int obj_update_dialogue_unk2();
// extern ? obj_has_model(?);
extern void obj_align_gfx_with_floor(void);
// extern ? mario_is_within_rectangle(?);
// extern ? ShakeScreen(?);
extern s32 attack_collided_non_mario_object(struct Object *obj);
// extern ? obj_was_attacked_or_ground_pounded(?);
// extern ? copy_object_behavior_params(?);
// extern ? func_802A4A70(?);
// extern ? func_802A4AB0(?);
// extern ? func_802A4AEC(?);
// extern ? obj_check_grabbed_mario(?);
// extern ? player_performed_grab_release_action(?);
// extern ? obj_unused_play_footstep_sound(?);
// extern ? enable_time_stop_including_mario(?);
extern void disable_time_stop_including_mario(void);
// extern ? obj_check_interacted(?);
// extern ? obj_spawn_loot_blue_coin(?);

#ifdef VERSION_US
void obj_spawn_star_at_y_offset(float f12, float f14, float a2, float a3);
#endif

#endif /* OBJECT_HELPERS2_H */
