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

/* Bob-omb */
    /* oBehParam */
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
    /* oBehParam */
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
    /* oBehParam */
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
    /* oBehParam */
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
    /* oBehParam */
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
    /* oBehParam */
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
    
#endif
