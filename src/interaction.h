#ifndef _INTERACTION_H
#define _INTERACTION_H

#include "types.h"

struct BullyCollisionData {
  /*0x00*/ f32 conversionRatio;
  /*0x04*/ f32 radius;
  /*0x08*/ f32 posX;
  /*0x0C*/ f32 posZ;
  /*0x10*/ f32 velX;
  /*0x14*/ f32 velZ;
};

extern u8 beh_normal_cap[];
extern u8 beh_metal_cap[];
extern u8 beh_wing_cap[];
extern u8 beh_vanish_cap[];
extern u8 beh_carry_something3[];
extern u8 beh_koopa_shell_underwater[];
extern u8 beh_carry_something4[];
extern u8 beh_carry_something5[];
extern u8 beh_bowser[];
extern s16 D_80339F02;
extern u8 beh_some_white_puff[];
extern u8 D_03009AC8[];
extern u8 D_80339F00;

extern s16 mario_angle_to_object(struct MarioState *, struct Object *);
extern void mario_stop_riding_object(struct MarioState *);
extern void mario_grab_used_object(struct MarioState *);
extern void mario_drop_held_object(struct MarioState *);
extern void mario_throw_held_object(struct MarioState *);
extern void mario_stop_riding_and_holding(struct MarioState *);
extern u32 func_8024C75C(struct MarioState *);
extern void mario_blow_off_cap(struct MarioState *, f32);
extern u32 mario_lose_cap_to_enemy(u32);
extern void mario_retrieve_cap(void);
extern struct Object *mario_get_collided_object(struct MarioState *, u32);
extern u32 mario_check_object_grab(struct MarioState *);
extern u32 get_door_save_file_flag(struct Object *);
extern void mario_process_interactions(struct MarioState *);
extern void mario_handle_special_floors(struct MarioState *);
extern void init_bully_collision_data(
    struct BullyCollisionData *data,
    f32 posX,
    f32 posZ,
    f32 forwardVel,
    s16 yaw,
    f32 conversionRatio,
    f32 radius);
extern void transfer_bully_speed(struct BullyCollisionData *, struct BullyCollisionData *);

#endif /* _INTERACTION_H */
