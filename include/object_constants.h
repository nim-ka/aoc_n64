#ifndef _OBJECT_CONSTANTS_H
#define _OBJECT_CONSTANTS_H

// This file contains macros that provide descriptive names for
// field-specific and object-specific constants, e.g. actions.

/* oHeldState */
#define HELD_FREE 0
#define HELD_HELD 1
#define HELD_THROWN 2
#define HELD_DROPPED 3

/* oAction */
#define OBJ_ACT_LAVA_DEATH 100
#define OBJ_ACT_DEATH_PLANE_DEATH 101

/* oMoveFlags */
#define OBJ_MOV_0       (1 << 0) // 0x0001
#define OBJ_MOV_GROUND  (1 << 1) // 0x0002
#define OBJ_MOV_2       (1 << 2) // 0x0004
#define OBJ_MOV_3       (1 << 3) // 0x0008
#define OBJ_MOV_4       (1 << 4) // 0x0010
#define OBJ_MOV_5       (1 << 5) // 0x0020
#define OBJ_MOV_6       (1 << 6) // 0x0040
#define OBJ_MOV_7       (1 << 7) // 0x0080
#define OBJ_MOV_8       (1 << 8) // 0x0100

/* Bob-omb */
    /* oBehParams2ndByte */
    #define BOBOMB_BP_STYPE_GENERIC 0
    #define BOBOMB_BP_STYPE_STATIONARY 1
    /* oAction */
    #define BOBOMB_ACT_PATROL 0
    #define BOBOMB_ACT_LAUNCHED 1
    #define BOBOMB_ACT_CHASE_MARIO 2
    #define BOBOMB_ACT_EXPLODE 3
    #define BOBOMB_ACT_LAVA_DEATH 100
    #define BOBOMB_ACT_DEATH_PLANE_DEATH 101
    
/* Moving Blue Coin */
    /* oAction */
    #define MOV_BCOIN_ACT_STILL 0
    #define MOV_BCOIN_ACT_MOVING 1

/* Moving Yellow Coin */
    /* oAction */
    #define MOV_YCOIN_ACT_IDLE 0
    #define MOV_YCOIN_ACT_BLINKING 1
    #define MOV_YCOIN_ACT_LAVA_DEATH 100
    #define MOV_YCOIN_ACT_DEATH_PLANE_DEATH 101
    
/* Bob-omb Buddy */
    /* oBehParams2ndByte */
    #define BOBOMB_BUDDY_BP_STYPE_GENERIC 0
    #define BOBOMB_BUDDY_BP_STYPE_BOB_GRASS_KBB 1
    #define BOBOMB_BUDDY_BP_STYPE_BOB_CANNON_KBB 2
    #define BOBOMB_BUDDY_BP_STYPE_BOB_GRASS 3
    /* oAction */
    #define BOBOMB_BUDDY_ACT_IDLE 0
    #define BOBOMB_BUDDY_ACT_TURN_TO_TALK 2
    #define BOBOMB_BUDDY_ACT_TALK 3
    /* oBobombBuddyRole */
    #define BOBOMB_BUDDY_ROLE_ADVICE 0
    #define BOBOMB_BUDDY_ROLE_CANNON 1
    /* oBobombBuddyCannonStatus */
    #define BOBOMB_BUDDY_CANNON_UNOPENED 0
    #define BOBOMB_BUDDY_CANNON_OPENING 1
    #define BOBOMB_BUDDY_CANNON_OPENED 2
    #define BOBOMB_BUDDY_CANNON_STOP_TALKING 3
    /* oBobombBuddyHasTalkedToMario */
    #define BOBOMB_BUDDY_HAS_NOT_TALKED 0
    #define BOBOMB_BUDDY_HAS_TALKED 2
    
/* Cannon Trap Door */
    /* oAction */
    #define CANNON_TRAP_DOOR_ACT_CLOSED 0
    #define CANNON_TRAP_DOOR_ACT_CAM_ZOOM 1
    #define CANNON_TRAP_DOOR_ACT_OPENING 2
    #define CANNON_TRAP_DOOR_ACT_OPEN 3
    
/* Homing Amp */
    /* oAction */
    #define AMP_HOMING_ACT_INACTIVE 0
    #define AMP_HOMING_ACT_APPEAR 1
    #define AMP_HOMING_ACT_CHASE 2
    #define AMP_HOMING_ACT_GIVE_UP 3
    #define AMP_HOMING_ACT_ATTACK_COOLDOWN 4
    
/* Amp */
    /* oBehParams2ndByte */
    #define AMP_BP_ROT_RADIUS_200 0
    #define AMP_BP_ROT_RADIUS_300 1
    #define AMP_BP_ROT_RADIUS_400 2
    #define AMP_BP_ROT_RADIUS_0 3
    /* oAction */
    #define AMP_ACT_IDLE 2
    #define AMP_ATTACK_COOLDOWN 4
    
/* Butterfly */
    /* oAction */
    #define BUTTERFLY_ACT_RESTING 0
    #define BUTTERFLY_ACT_FOLLOW_MARIO 1
    #define BUTTERFLY_ACT_RETURN_HOME 2

/* Hoot */
    /* oHootAvailability */
    #define HOOT_AVAIL_ASLEEP_IN_TREE 0
    #define HOOT_AVAIL_WANTS_TO_TALK 1
    #define HOOT_AVAIL_READY_TO_FLY 2
    /* oAction */
    #define HOOT_ACT_ASCENT 0
    #define HOOT_ACT_CARRY 1
    #define HOOT_ACT_TIRED 2
    
/* Bully (all variants) */
    /* oBehParams2ndByte */
    #define BULLY_BP_SIZE_SMALL 0
    #define BULLY_BP_SIZE_BIG 1
    /* oAction */
    #define BULLY_ACT_PATROL 0
    #define BULLY_ACT_CHASE_MARIO 1
    #define BULLY_ACT_KNOCKBACK 2
    #define BULLY_ACT_BACK_UP 3
    #define BULLY_ACT_INACTIVE 4
    #define BULLY_ACT_ACTIVATE_AND_FALL 5
    #define BULLY_ACT_LAVA_DEATH 100
    #define BULLY_ACT_DEATH_PLANE_DEATH 101
    /* oBullySubtype */
    #define BULLY_STYPE_GENERIC 0
    #define BULLY_STYPE_MINION 1
    #define BULLY_STYPE_CHILL 16
    
/* Water Ring (all variants */
    /* oAction */
    #define WATER_RING_ACT_NOT_COLLECTED 0
    #define WATER_RING_ACT_COLLECTED 1
    
/* Jet Stream Water Ring Spawner */
    /* oAction */
    #define JS_RING_SPAWNER_ACT_ACTIVE 0
    #define JS_RING_SPAWNER_ACT_INACTIVE 1
    
/* Celebration Star */
    /* oAction */
    #define CELEB_STAR_ACT_SPIN_AROUND_MARIO 0
    #define CELEB_STAR_ACT_FACE_CAMERA 1
    
/* LLL Drawbridge */
    /* oAction */
    #define LLL_DRAWBRIDGE_ACT_LOWER 0
    #define LLL_DRAWBRIDGE_ACT_RAISE 1
    
/* Bomp (both variants) */
    /* oAction */
    #define BOMP_ACT_WAIT 0
    #define BOMP_ACT_POKE_OUT 1
    #define BOMP_ACT_EXTEND 2
    #define BOMP_ACT_RETRACT 3
    
/* WF Sliding Brick Platform */
    /* oBehParams2ndByte */
    #define WF_SLID_BRICK_PTFM_BP_MOV_VEL_10 1
    #define WF_SLID_BRICK_PTFM_BP_MOV_VEL_15 2
    #define WF_SLID_BRICK_PTFM_BP_MOV_VEL_20 3
    /* oAction */
    #define WF_SLID_BRICK_PTFM_ACT_WAIT 0
    #define WF_SLID_BRICK_PTFM_ACT_EXTEND 1
    #define WF_SLID_BRICK_PTFM_ACT_RETRACT 2
    
/* Fake Moneybag Coin */
    /* oAction */
    #define FAKE_MONEYBAG_COIN_ACT_IDLE 0
    #define FAKE_MONEYBAG_COIN_ACT_TRANSFORM 1
    
/* Moneybag */
    /* oAction */
    #define MONEYBAG_ACT_APPEAR 0
    #define MONEYBAG_ACT_UNUSED_APPEAR 1
    #define MONEYBAG_ACT_MOVE_AROUND 2
    #define MONEYBAG_ACT_RETURN_HOME 3
    #define MONEYBAG_ACT_DISAPPEAR 4
    #define MONEYBAG_ACT_DEATH 5
    /* oMoneybagJumpState */
    #define MONEYBAG_JUMP_LANDING 0
    #define MONEYBAG_JUMP_PREPARE 1
    #define MONEYBAG_JUMP_JUMP 2
    #define MONEYBAG_JUMP_JUMP_AND_BOUNCE 3
    #define MONEYBAG_JUMP_WALK_AROUND 4
    #define MONEYBAG_JUMP_WALK_HOME 5
    
/* Bowling Ball */
    /* oAction */
    #define BBALL_ACT_INITIALIZE 0
    #define BBALL_ACT_ROLL 1
    
/* Bowling Ball + Bowling Ball Spawner (all variants) */
    /* oBehParams2ndByte */
    #define BBALL_BP_STYPE_BOB_UPPER 0
    #define BBALL_BP_STYPE_TTM 1
    #define BBALL_BP_STYPE_BOB_LOWER 2
    #define BBALL_BP_STYPE_THI_LARGE 3
    #define BBALL_BP_STYPE_THI_SMALL 4
    
/* Bowling Ball (Free) */
    /* oAction */
    #define FREE_BBALL_ACT_IDLE 0
    #define FREE_BBALL_ACT_ROLL 1
    #define FREE_BBALL_ACT_RESET 2

/* Koopa */
    /* oAction */
    #define KOOPA_UNSHELLED_ACT_RUNNING 0
    #define KOOPA_UNSHELLED_ACT_DIVING 1
    #define KOOPA_UNSHELLED_ACT_LYING 2
    #define KOOPA_UNSHELLED_ACT_UNKNOWN_3 3
    #define KOOPA_SHELLED_ACT_STOPPED 0
    #define KOOPA_SHELLED_ACT_WALKING 1
    #define KOOPA_SHELLED_ACT_RUNNING 2
    #define KOOPA_SHELLED_ACT_LYING 3
    #define KOOPA_SHELLED_ACT_UNK4 4
    #define KOOPA_THE_QUICK_ACT_WAIT_BEFORE_RACE 0
    #define KOOPA_THE_QUICK_ACT_UNK1 1
    #define KOOPA_THE_QUICK_ACT_UNK2 2
    #define KOOPA_THE_QUICK_ACT_UNK3 3
    #define KOOPA_THE_QUICK_ACT_UNK4 4
    #define KOOPA_THE_QUICK_ACT_UNK5 5
    #define KOOPA_THE_QUICK_ACT_UNK6 6

    /* oBehParams2ndByte */
    #define KOOPA_BP_UNSHELLED 0
    #define KOOPA_BP_NORMAL 1
    #define KOOPA_BP_KOOPA_THE_QUICK_BASE 2
    #define KOOPA_BP_KOOPA_THE_QUICK_BOB 2
    #define KOOPA_BP_KOOPA_THE_QUICK_THI 3
    #define KOOPA_BF_SMALL 4

/* Pokey */
    /* oAction */
    #define POKEY_ACT_UNINITIALIZED 0
    #define POKEY_ACT_WANDER 1
    #define POKEY_ACT_UNK2 2

/* Swoop */
    /* oAction */
    #define SWOOP_ACT_IDLE 0
    #define SWOOP_ACT_MOVE 1

/* Fly guy */
    /* oAction */
    #define FLY_GUY_ACT_IDLE 0
    #define FLY_GUY_ACT_APPROACH_MARIO 1
    #define FLY_GUY_ACT_LUNGE 2
    #define FLY_GUY_ACT_SHOOT_FIRE 3

/* Goomba triplet spawner */
    /* oBehParams2ndByte */
    #define GOOMBA_TRIPLET_SPAWNER_BP_SIZE_MASK 0x00000003
    #define GOOMBA_TRIPLET_SPAWNER_BP_EXTRA_GOOMBAS_MASK 0x000000FC
    /* oAction */
    #define GOOMBA_TRIPLET_SPAWNER_ACT_UNLOADED 0
    #define GOOMBA_TRIPLET_SPAWNER_ACT_LOADED 1

/* Goomba */
    /* oBehParams2ndByte */
    #define GOOMBA_BP_SIZE_MASK 0x00000003
    #define GOOMBA_SIZE_REGULAR 0
    #define GOOMBA_SIZE_HUGE 1
    #define GOOMBA_SIZE_TINY 2
    #define GOOMBA_BP_TRIPLET_FLAG_MASK 0x000000FC
    /* oAction */
    #define GOOMBA_ACT_WALK 0
    #define GOOMBA_ACT_SOFT_ATTACKED 1
    #define GOOMBA_ACT_JUMP 2

/* Chain chomp */
    /* oAction */
    #define CHAIN_CHOMP_ACT_UNINITIALIZED 0
    #define CHAIN_CHOMP_ACT_MOVE 1
    #define CHAIN_CHOMP_ACT_UNLOAD_CHAIN 2

    /* oUnk150 */
    #define CHAIN_CHOMP_PHASE_TURNING 0
    #define CHAIN_CHOMP_PHASE_LUNGING 1

/* Wiggler */
    /* oAction */
    #define WIGGLER_ACT_UNINITIALIZED 0
    #define WIGGLER_ACT_WALK 1
    #define WIGGLER_ACT_KNOCKBACK 2
    #define WIGGLER_ACT_JUMPED_ON 3
    #define WIGGLER_ACT_SHRINK 4
    #define WIGGLER_ACT_FALL_THROUGH_FLOOR 5

/* Spiny */
    /* oAction */
    #define SPINY_ACT_WALK 0
    #define SPINY_ACT_HELD_BY_LAKITU 1
    #define SPINY_ACT_THROWN_BY_LAKITU 2
    #define SPINY_ACT_UNK3 3

/* Platform on tracks */
    /* oAction */
    #define PLATFORM_ON_TRACK_ACT_UNK0 0
    #define PLATFORM_ON_TRACK_ACT_UNK1 1
    #define PLATFORM_ON_TRACK_ACT_UNK2 2
    #define PLATFORM_ON_TRACK_ACT_UNK3 3
    #define PLATFORM_ON_TRACK_ACT_UNK4 4

/* Water bomb */
    /* oAction */
    #define WATER_BOMB_ACT_UNK0 0
    #define WATER_BOMB_ACT_INIT 1
    #define WATER_BOMB_ACT_DROP 2
    #define WATER_BOMB_ACT_DEACTIVATE 3

/* TTC rotating solid */
    /* oBehParams2ndByte */
    #define TTC_ROTATING_SOLID_BP_CUBE 0
    #define TTC_ROTATING_SOLID_BP_TRIANGULAR_PRISM 1

/* TTC moving bar */
    /* oAction */
    #define TTC_MOVING_BAR_ACT_WAIT 0
    #define TTC_MOVING_BAR_ACT_PULL_BACK 1
    #define TTC_MOVING_BAR_ACT_EXTEND 2
    #define TTC_MOVING_BAR_ACT_RETRACT 3

/* TTC cog */
    /* oBehParams2ndByte */
    #define TTC_COG_BP_SHAPE_MASK 0x00000002
    #define TTC_COG_BP_SHAPE_HEXAGON (0 << 1)
    #define TTC_COG_BP_SHAPE_TRIANGLE (1 << 1)
    #define TTC_COG_BP_DIR_MASK 0x00000001
    #define TTC_COG_BP_DIR_CCW (0 << 0) // TODO: Check these
    #define TTC_COG_BP_DIR_CW (1 << 0)

/* Dorrie */
    /* oAction */
    #define DORRIE_ACT_MOVE 0
    #define DORRIE_ACT_LOWER_HEAD 1
    #define DORRIE_ACT_RAISE_HEAD 2

/* Mad piano */
    /* oAction */
    #define MAD_PIANO_ACT_WAIT 0
    #define MAD_PIANO_ACT_ATTACK 1

/* Fire piranha plant */
    /* oAction */
    #define FIRE_PIRANHA_PLANT_ACT_HIDE 0
    #define FIRE_PIRANHA_PLANT_ACT_GROW 1

/* Fire spitter */
    /* oAction */
    #define FIRE_SPITTER_ACT_IDLE 0
    #define FIRE_SPITTER_ACT_SPIT_FIRE 1

/* Eyerok boss */
    /* oAction */
    #define EYEROK_BOSS_ACT_SLEEP 0
    #define EYEROK_BOSS_ACT_WAKE_UP 1
    #define EYEROK_BOSS_ACT_SHOW_INTRO_TEXT 2
    #define EYEROK_BOSS_ACT_FIGHT 3
    #define EYEROK_BOSS_ACT_DIE 4

/* Eyerok hand */
    /* oAction */
    #define EYEROK_HAND_ACT_SLEEP 0
    #define EYEROK_HAND_ACT_IDLE 1
    #define EYEROK_HAND_ACT_OPEN 2
    #define EYEROK_HAND_ACT_SHOW_EYE 3
    #define EYEROK_HAND_ACT_CLOSE 4
    #define EYEROK_HAND_ACT_RETREAT 5
    #define EYEROK_HAND_ACT_TARGET_MARIO 6
    #define EYEROK_HAND_ACT_SMASH 7
    #define EYEROK_HAND_ACT_FIST_PUSH 8
    #define EYEROK_HAND_ACT_FIST_SWEEP 9
    #define EYEROK_HAND_ACT_BEGIN_DOUBLE_POUND 10 // raising for double smash
    #define EYEROK_HAND_ACT_DOUBLE_POUND 11 // double smashing
    #define EYEROK_HAND_ACT_ATTACKED 12
    #define EYEROK_HAND_ACT_RECOVER 13
    #define EYEROK_HAND_ACT_BECOME_ACTIVE 14
    #define EYEROK_HAND_ACT_DIE 15

/* Klepto */
    /* oAction */
    #define KLEPTO_ACT_CIRCLE_TARGET_HOLDING 0
    #define KLEPTO_ACT_APPROACH_TARGET_HOLDING 1
    #define KLEPTO_ACT_WAIT_FOR_MARIO 2
    #define KLEPTO_ACT_TURN_TOWARD_MARIO 3
    #define KLEPTO_ACT_DIVE_AT_MARIO 4
    #define KLEPTO_ACT_RESET_POSITION 5
    #define KLEPTO_ACT_STRUCK_BY_MARIO 6
    #define KLEPTO_ACT_RETREAT 7

    /* oAnimState */
    #define KLEPTO_ANIM_STATE_HOLDING_NOTHING 0
    #define KLEPTO_ANIM_STATE_HOLDING_CAP 1
    #define KLEPTO_ANIM_STATE_HOLDING_STAR 2

/* Bird */
    /* oAction */
    #define BIRD_ACT_INIT 0
    #define BIRD_ACT_FLY 1

    /* oBehParams2ndByte */
    #define BIRD_BP_SPAWNED 0
    #define BIRD_BP_SPAWNER 1

/* Racing penguin */
    /* oAction */
    #define RACING_PENGUIN_ACT_WAIT_FOR_MARIO 0
    #define RACING_PENGUIN_ACT_SHOW_INIT_TEXT 1
    #define RACING_PENGUIN_ACT_PREPARE_FOR_RACE 2
    #define RACING_PENGUIN_ACT_RACE 3
    #define RACING_PENGUIN_ACT_FINISH_RACE 4
    #define RACING_PENGUIN_ACT_SHOW_FINAL_TEXT 5

/* Skeeter */
    /* oAction */
    #define SKEETER_ACT_IDLE 0
    #define SKEETER_ACT_LUNGE 1
    #define SKEETER_ACT_WALK 2

/* Triplet butterfly */
    /* oAction */
    #define TRIPLET_BUTTERFLY_ACT_INIT 0
    #define TRIPLET_BUTTERFLY_ACT_WANDER 1
    #define TRIPLET_BUTTERFLY_ACT_ACTIVATE 2
    #define TRIPLET_BUTTERFLY_ACT_EXPLODE 3

    /* oBehParams2ndByte */
    #define TRIPLET_BUTTERFLY_BP_BUTTERFLY_NUM 0x00000003
    #define TRIPLET_BUTTERFLY_BP_NO_BOMBS 0x00000004

    /* oTripletButterflyType */
    #define TRIPLET_BUTTERFLY_TYPE_NORMAL -1
    #define TRIPLET_BUTTERFLY_TYPE_EXPLODES 0
    #define TRIPLET_BUTTERFLY_TYPE_SPAWN_1UP 1

#endif
