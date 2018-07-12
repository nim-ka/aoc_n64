#ifndef _INTERACTION_H
#define _INTERACTION_H

#include "types.h"

#define INTERACT_HOOT           /* 0x00000001 */ (1 <<  0)
#define INTERACT_GRABBABLE      /* 0x00000002 */ (1 <<  1)
#define INTERACT_DOOR           /* 0x00000004 */ (1 <<  2)
#define INTERACT_DAMAGE         /* 0x00000008 */ (1 <<  3)
#define INTERACT_COIN           /* 0x00000010 */ (1 <<  4)
#define INTERACT_CAP            /* 0x00000020 */ (1 <<  5)
#define INTERACT_POLE           /* 0x00000040 */ (1 <<  6)
#define INTERACT_KOOPA          /* 0x00000080 */ (1 <<  7)
#define INTERACT_UNKNOWN_08     /* 0x00000100 */ (1 <<  8)
#define INTERACT_BREAKABLE      /* 0x00000200 */ (1 <<  9)
#define INTERACT_WIND           /* 0x00000400 */ (1 << 10)
#define INTERACT_WARP_DOOR      /* 0x00000800 */ (1 << 11)
#define INTERACT_STAR_OR_KEY    /* 0x00001000 */ (1 << 12)
#define INTERACT_WARP           /* 0x00002000 */ (1 << 13)
#define INTERACT_CANNON_BASE    /* 0x00004000 */ (1 << 14)
#define INTERACT_BOUNCE_TOP     /* 0x00008000 */ (1 << 15)
#define INTERACT_WATER_RING     /* 0x00010000 */ (1 << 16)
#define INTERACT_BULLY          /* 0x00020000 */ (1 << 17)
#define INTERACT_FLAME          /* 0x00040000 */ (1 << 18)
#define INTERACT_KOOPA_SHELL    /* 0x00080000 */ (1 << 19)
#define INTERACT_UNKNOWN_20     /* 0x00100000 */ (1 << 20)
#define INTERACT_MR_BLIZZARD    /* 0x00200000 */ (1 << 21)
#define INTERACT_HIT_FROM_BELOW /* 0x00400000 */ (1 << 22)
#define INTERACT_TEXT           /* 0x00800000 */ (1 << 23)
#define INTERACT_TORNADO        /* 0x01000000 */ (1 << 24)
#define INTERACT_WHIRLPOOL      /* 0x02000000 */ (1 << 25)
#define INTERACT_CLAM_OR_BUBBA  /* 0x04000000 */ (1 << 26)
#define INTERACT_BBH_ENTRANCE   /* 0x08000000 */ (1 << 27)
#define INTERACT_SNUFIT_BULLET  /* 0x10000000 */ (1 << 28)
#define INTERACT_SHOCK          /* 0x20000000 */ (1 << 29)
#define INTERACT_IGLOO_BARRIER  /* 0x40000000 */ (1 << 30)
#define INTERACT_UNKNOWN_31     /* 0x80000000 */ (1 << 31)

struct BullyCollisionData {
  /*0x00*/ f32 conversionRatio;
  /*0x04*/ f32 radius;
  /*0x08*/ f32 posX;
  /*0x0C*/ f32 posZ;
  /*0x10*/ f32 velX;
  /*0x14*/ f32 velZ;
};

extern u8 D_03009AC8[];

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
