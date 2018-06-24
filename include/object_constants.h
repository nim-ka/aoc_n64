#ifndef _OBJECT_CONSTANTS_H
#define _OBJECT_CONSTANTS_H

// This file contsins macros that provide descriptive names for
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
    #define BOBOMB_BP_TYPE_STATIONARY 1
    /* oAction */
    #define BOBOMB_ACT_PATROL 0
    #define BOBOMB_ACT_THROWN 1
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
    
#endif
