.include "macros.inc"

# see include/object_lists.h for comments

# TODO: Use C preprocessor define instead of redefining the lists seperately.
.set OBJ_LIST_PLAYER,         0
.set OBJ_LIST_UNK1,           1
.set OBJ_LIST_DESTRUCTIVE,    2
.set OBJ_LIST_UNK3,           3
.set OBJ_LIST_GENACTOR,       4
.set OBJ_LIST_PUSHABLE,       5
.set OBJ_LIST_LEVEL,          6
.set OBJ_LIST_UNK7,           7
.set OBJ_LIST_DEFAULT,        8
.set OBJ_LIST_SURFACE,        9
.set OBJ_LIST_POLELIKE,       10
.set OBJ_LIST_SPAWNER,        11
.set OBJ_LIST_UNIMPORTANT,    12

# TODO: Use C preprocessor define instead of redefining the lists seperately. (object_constants.h)
.set OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE,         (1 <<  0) # 0x0001
.set OBJ_FLAG_MOVE_XZ_USING_FVEL,               (1 <<  1) # 0x0002
.set OBJ_FLAG_MOVE_Y_WITH_TERMINAL_VEL,         (1 <<  2) # 0x0004
.set OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW,         (1 <<  3) # 0x0008
.set OBJ_FLAG_0010,                             (1 <<  4) # 0x0010
.set OBJ_FLAG_0020,                             (1 <<  5) # 0x0020
.set OBJ_FLAG_COMPUTE_DIST_TO_MARIO,            (1 <<  6) # 0x0040
.set OBJ_FLAG_ACTIVE_FROM_AFAR,                 (1 <<  7) # 0x0080
.set OBJ_FLAG_0100,                             (1 <<  8) # 0x0100
.set OBJ_FLAG_TRANSFORM_RELATIVE_TO_PARENT,     (1 <<  9) # 0x0200
.set OBJ_FLAG_HOLDABLE,                         (1 << 10) # 0x0400
.set OBJ_FLAG_0800,                             (1 << 11) # 0x0800
.set OBJ_FLAG_1000,                             (1 << 12) # 0x1000
.set OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO,           (1 << 13) # 0x2000
.set OBJ_FLAG_4000,                             (1 << 14) # 0x4000
.set OBJ_FLAG_8000,                             (1 << 15) # 0x8000

# TODO: Use C preprocessor define instead of redefining the lists seperately. (object_fields.h)
.set objUnk88, 0x00
.set objFlags, 0x01
.set objDialogueResponse, 0x02
.set objUnk94, 0x03
.set objUnk98, 0x04
.set objIntangibleTimer, 0x05
.set objPosX, 0x06
.set objPosY, 0x07
.set objPosZ, 0x08
.set objVelX, 0x09
.set objVelY, 0x0A
.set objVelZ, 0x0B
.set objForwardVel, 0x0C
.set objUnkBC, 0x0D
.set objUnkC0, 0x0E
.set objMoveAnglePitch, 0x0F
.set objMoveAngleYaw, 0x10
.set objMoveAngleRoll, 0x11
.set objFaceAnglePitch, 0x12
.set objFaceAngleYaw, 0x13
.set objFaceAngleRoll, 0x14
.set objGraphYOffset, 0x15
.set objUnkE0, 0x16
.set objGravity, 0x17
.set objFloorHeight, 0x18
.set objMoveFlags, 0x19
.set objAnimState, 0x1A
# object-specific fields
.set objVarF4, 0x1B
.set objVarF8, 0x1C
.set objVarFC, 0x1D
.set objVar100, 0x1E
.set objVar104, 0x1F
.set objVar108, 0x20
.set objVar10C, 0x21
.set objVar110, 0x22
#
.set objAngleVelPitch, 0x23
.set objAngleVelYaw, 0x24
.set objAngleVelRoll, 0x25
.set objAnimations, 0x26
.set objHeldState, 0x27
.set objWallHitboxRadius, 0x28
.set objDragStrength, 0x29
.set objInteractType, 0x2A
.set objInteractStatus, 0x2B
.set objParentRelativePosX, 0x2C
.set objParentRelativePosY, 0x2D
.set objParentRelativePosZ, 0x2E
.set objBehParams2ndByte, 0x2F
.set objUnk148, 0x30
.set objAction, 0x31
.set objSubAction, 0x32
.set objTimer, 0x33
.set objBounce, 0x34
.set objDistanceToMario, 0x35
.set objAngleToMario, 0x36
.set objHomeX, 0x37
.set objHomeY, 0x38
.set objHomeZ, 0x39
.set objFriction, 0x3A
.set objBuoyancy, 0x3B
.set objSoundStateID, 0x3C
.set objOpacity, 0x3D
.set objDamageOrCoinValue, 0x3E
.set objHealth, 0x3F
.set objBehParams, 0x40
.set objPrevAction, 0x41
.set objUnk190, 0x42
.set objCollisionDistance, 0x43
.set objNumLootCoins, 0x44
.set objDrawingDistance, 0x45
.set objRoom, 0x46
.set objUnk1A4, 0x47
.set objUnk1A8, 0x48
.set objUnk1AC, 0x49
.set objUnk1B0, 0x4A
.set objWallAngle, 0x4B
.set objFloorType, 0x4C
.set objUnk1BC, 0x4D
.set objFloor, 0x4E
.set objDeathSound, 0x4F


.macro begin arg1
    .word (0x00 << 24) | (\arg1 << 16)
.endm

.macro delay frames
    .word (0x01 << 24) | (\frames & 0xFFFF)
.endm

.macro call addr
    .word (0x02 << 24)
    .word \addr
.endm

.macro return
    .word (0x03 << 24)
.endm

.macro goto addr
    .word (0x04 << 24)
    .word \addr
.endm

.macro begin_repeat times
    .word (0x05 << 24) | (\times & 0xFFFF)
.endm

.macro end_repeat
    .word (0x06 << 24)
.endm

.macro end_repeat_nobreak
    .word (0x07 << 24)
.endm

.macro begin_loop
    .word (0x08 << 24)
.endm

.macro end_loop
    .word (0x09 << 24)
.endm

.macro break
    .word (0x0A << 24)
.endm

.macro callnative addr
    .word (0x0C << 24)
    .word \addr
.endm

.macro obj_add_float field, value
    .word (0x0D << 24) | (\field << 16) | (\value & 0xFFFF)
.endm

.macro obj_set_float field, value
    .word (0x0E << 24) | (\field << 16) | (\value & 0xFFFF)
.endm

.macro obj_add_int field, value
    .word (0x0F << 24) | (\field << 16) | (\value & 0xFFFF)
.endm

.macro obj_set_int field, value
    .word (0x10 << 24) | (\field << 16) | (\value & 0xFFFF)
.endm

.macro obj_or_int field, value
    .word (0x11 << 24) | (\field << 16) | (\value & 0xFFFF)
.endm

.macro obj_bit_clear_int field, value
    .word (0x12 << 24) | (\field << 16) | (\value & 0xFFFF)
.endm

.macro obj_set_int_rand_rshift field, min, rshift
    .word (0x13 << 24) | (\field << 16) | (\min & 0xFFFF)
    .word ((\rshift & 0xFFFF) << 16)
.endm

.macro obj_set_float_rand field, min, max
    .word (0x14 << 24) | (\field << 16) | (\min & 0xFFFF)
    .word ((\max & 0xFFFF) << 16)
.endm

.macro obj_set_int_rand field, min, max
    .word (0x15 << 24) | (\field << 16) | (\min & 0xFFFF)
    .word ((\max & 0xFFFF) << 16)
.endm

.macro obj_add_float_rand field, min, max
    .word (0x16 << 24) | (\field << 16) | (\min & 0xFFFF)
    .word ((\max & 0xFFFF) << 16)
.endm

.macro obj_add_int_rand_rshift field, min, rshift
    .word (0x17 << 24) | (\field << 16) | (\min & 0xFFFF)
    .word ((\rshift & 0xFFFF) << 16)
.endm

.macro geo_layout index
    .word (0x1B << 24) | (\index & 0xFFFF)
.endm

.macro unknown_1C arg1, arg2
    .word (0x1C << 24)
    .word \arg1
    .word \arg2
.endm

.macro deactivate
    .word (0x1D << 24)
.endm

.macro unknown_1E
    .word (0x1E << 24)
.endm

.macro obj_sum_float fieldDest, fieldSrc1, fieldSrc2
    .word (0x1F << 24) | (\fieldDest << 16) | (\fieldSrc1 << 8) | \fieldSrc2
.endm

.macro obj_sum_int fieldDest, fieldSrc1, fieldSrc2
    .word (0x20 << 24) | (\fieldDest << 16) | (\fieldSrc1 << 8) | \fieldSrc2
.endm

.macro billboard
    .word (0x21 << 24)
.endm

.macro unhide
    .word (0x22 << 24)
.endm

.macro set_hitbox radius, height
    .word (0x23 << 24)
    .word ((\radius & 0xFFFF) << 16) | (\height & 0xFFFF)
.endm

.macro delay_var field
    .word (0x25 << 24) | (\field << 16)
.endm

.macro obj_set_int32 field, value
    .word (0x27 << 24) | (\field << 16)
    .word \value
.endm

.macro unknown_28 animIndex
    .word (0x28 << 24) | ((\animIndex & 0xFF) << 16)
.endm

.macro unknown_29 behParam, arg2, arg3
    .word (0x29 << 24) | (\behParam & 0xFFFF)
    .word \arg2
    .word \arg3
.endm

.macro collision_data addr
    .word (0x2A << 24)
    .word \addr
.endm

.macro unknown_2B radius, height, arg3
    .word (0x2B << 24)
    .word ((\radius & 0xFFFF) << 16) | (\height & 0xFFFF)
    .word ((\arg3 & 0xFFFF) << 16)
.endm

.macro unknown_2C arg1, arg2
    .word (0x2C << 24)
    .word \arg1
    .word \arg2
.endm

.macro unknown_2D
    .word (0x2D << 24)
.endm

.macro unknown_2E arg1, arg2
    .word (0x2E << 24)
    .word ((\arg1 & 0xFFFF) << 16) | (\arg2 & 0xFFFF)
.endm

.macro interact_type type
    .word (0x2F << 24)
    .word \type
.endm

.macro unknown_30 arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8
    .word (0x30 << 24)
    .word ((\arg1 & 0xFFFF) << 16) | (\arg2 & 0xFFFF)
    .word ((\arg3 & 0xFFFF) << 16) | (\arg4 & 0xFFFF)
    .word ((\arg5 & 0xFFFF) << 16) | (\arg6 & 0xFFFF)
    .word ((\arg7 & 0xFFFF) << 16) | (\arg8 & 0xFFFF)
.endm

.macro scale percent
    .word (0x32 << 24) | (\percent & 0xFFFF)
.endm

.macro obj_bit_clear_int32 field, value
    .word (0x33 << 24) | (\field << 16)
    .word \value
.endm

.macro unknown_34 field, arg2
    .word (0x34 << 24) | (\field << 16) | (\arg2 & 0xFFFF)
.endm

.macro unknown_35
    .word (0x35 << 24)
.endm

.macro unknown_37 arg1
    .word (0x37 << 24)
    .word \arg1
.endm

.section .behavior, "a"


glabel behavior_data
glabel beh_star_door # 0000
    begin OBJ_LIST_SURFACE
    obj_set_int objInteractType, 4
    collision_data inside_castle_seg7_collision_star_door
    obj_set_int objUnk190, 32
    obj_or_int objFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    set_hitbox 80, 100
    unknown_2D
    obj_set_float objDrawingDistance, 20000
    callnative BehDoorInit
    obj_set_int objIntangibleTimer, 0
    begin_loop
        callnative BehStarDoorLoop
        callnative BehStarDoorLoop2
        callnative load_object_collision_model
    end_loop

glabel beh_mr_i # 0054
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_2D
    unknown_1C 0x00000066, beh_mr_i_body
    geo_layout 0x0067
    billboard
    callnative bhv_init_room
    begin_loop
        callnative BehMrILoop
    end_loop

glabel beh_mr_i_body # 008C
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    callnative bhv_init_room
    begin_loop
        callnative BehMrIBodyLoop
    end_loop

glabel beh_mr_i_particle # 00AC
    begin OBJ_LIST_LEVEL
    billboard
    obj_or_int objFlags, (OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int objIntangibleTimer, 0
    set_hitbox 50, 50
    obj_set_int objDamageOrCoinValue, 1
    obj_set_int objInteractType, 8
    unknown_30 0x001E, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
    callnative bhv_init_room
    begin_loop
        callnative BehMrIParticleLoop
    end_loop

glabel beh_giant_piranha_particle # 00F8
    begin OBJ_LIST_UNIMPORTANT
    billboard
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    begin_repeat 10
        callnative BehPiranhaParticleLoop
    end_repeat
    deactivate

glabel beh_giant_pole # 0118
    begin OBJ_LIST_POLELIKE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_set_int objInteractType, 0x40
    set_hitbox 0x0050, 0x0834
    unknown_2D
    obj_set_int objIntangibleTimer, 0
    begin_loop
        callnative BehGiantPoleLoop
    end_loop

glabel beh_pole_grabbing # 0144
    begin OBJ_LIST_POLELIKE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_set_int objInteractType, 0x40
    set_hitbox 0x0050, 0x05DC
    callnative BehPoleInit
    obj_set_int objIntangibleTimer, 0
    begin_loop
        callnative BehClimbDetectLoop
    end_loop

glabel beh_thi_top_trap # 0174
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    collision_data thi_seg7_collision_top_trap
    begin_loop
        callnative BehThiTopTrapLoop
    end_loop

glabel beh_thi_tiny_top # 0194
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    begin_loop
        callnative BehThiTinyTopLoop
    end_loop

glabel beh_cap_switch_collision_child # 01AC
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    collision_data capswitch_collision_05003448
    begin_loop
        callnative load_object_collision_model
    end_loop

glabel beh_activate_cap_switch # 01CC
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    collision_data capswitch_collision_050033D0
    begin_loop
        callnative BehActivateCapSwitchLoop
        callnative load_object_collision_model
    end_loop

glabel beh_king_bobomb # 01F4
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int32 objAnimations, king_bobomb_seg5_anims_0500FE30
    obj_set_int objInteractType, 0x02
    set_hitbox 0x0064, 0x0064
    unknown_30 0x001E, 0xFE70, 0xFFCE, 0x03E8, 0x03E8, 0x00C8, 0x0000, 0x0000
    obj_set_int objIntangibleTimer, 0
    unknown_1E
    unknown_2D
    unknown_2C 0x00000000, beh_bobomb_anchor_mario
    obj_set_int objHealth, 0x0003
    obj_set_int objDamageOrCoinValue, 1
    begin_loop
        callnative BehKingBobombLoop
    end_loop

glabel beh_bobomb_anchor_mario # 0254
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    billboard
    obj_set_float objParentRelativePosX, 0x0064
    obj_set_float objParentRelativePosZ, 0x0096
    begin_loop
        callnative BehBobombAnchorMarioLoop
    end_loop

glabel beh_beta_chest # 0278
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_1E
    callnative BehBetaChestInit
    begin_loop
        callnative BehBetaChestLoop
    end_loop

glabel beh_beta_chest_upper # 029C
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_2D
    begin_loop
        callnative BehBetaChestUpperLoop
    end_loop

glabel beh_bubble_mario # 02B8
    begin OBJ_LIST_DEFAULT
    unknown_35
    obj_set_int_rand objVarF4, 0x0002, 0x0009
    delay_var objVarF4
    unknown_1C 0x000000A8, beh_small_water_wave
    obj_bit_clear_int32 objUnkE0, 0x00000020
    deactivate

glabel beh_bubble_maybe # 02E4
    begin OBJ_LIST_UNIMPORTANT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    billboard
    callnative BehBubbleWaveInit
    obj_set_float_rand objVarF4, 0xFFB5, 0x0096
    obj_set_float_rand objVarF8, 0xFFB5, 0x0096
    obj_set_float_rand objVarFC, 0xFFB5, 0x0096
    obj_sum_float objPosX, objPosX, objVarF4
    obj_sum_float objPosZ, objPosZ, objVarF8
    obj_sum_float objPosY, objPosY, objVarFC
    obj_set_int objAnimState, -1
    begin_repeat 60
        obj_add_int objAnimState, 1
        callnative BehBubbleMaybeLoop
    end_repeat
    deactivate

glabel beh_small_water_wave # 0338
    begin OBJ_LIST_UNIMPORTANT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    billboard
    callnative BehBubbleWaveInit
    obj_set_float_rand objVarF4, 0xFFCE, 0x0064
    obj_set_float_rand objVarF8, 0xFFCE, 0x0064
    obj_sum_float objPosX, objPosX, objVarF4
    obj_sum_float objPosZ, objPosZ, objVarF8
    obj_set_float_rand objVarFC, 0x0000, 0x0032
    obj_sum_float objPosY, objPosY, objVarFC
    obj_set_int objAnimState, -1
    call beh_small_water_wave_398
    begin_repeat 60
        call beh_small_water_wave_398
        callnative BehSmallWaterWaveLoop
    end_repeat
    deactivate

glabel beh_small_water_wave_398 # 0398
    obj_add_int objAnimState, 1
    obj_add_float objPosY, 7
    obj_set_float_rand objVarF4, -2, 5
    obj_set_float_rand objVarF8, -2, 5
    obj_sum_float objPosX, objPosX, objVarF4
    obj_sum_float objPosZ, objPosZ, objVarF8
    return

glabel beh_water_air_bubble # 03BC
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    billboard
    unknown_2B 0x0190, 0x0096, 0xFF6A
    obj_set_int objIntangibleTimer, 0
    interact_type 0x00010000
    obj_set_int objDamageOrCoinValue, 5
    callnative BehWaterAirBubbleInit
    obj_set_int objAnimState, -1
    begin_loop
        callnative BehWaterAirBubbleLoop
    end_loop

glabel beh_small_particle # 0400
    begin OBJ_LIST_UNIMPORTANT
    billboard
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    callnative BehParticleInit
    begin_repeat 70
        callnative BehParticleLoop
    end_repeat
    deactivate

glabel beh_water_waves # 0428
    begin OBJ_LIST_DEFAULT
    obj_bit_clear_int32 objUnkE0, 0x00000200
    unknown_35
    callnative BehWaterWavesInit
    deactivate

glabel beh_small_particle_snow # 0444
    begin OBJ_LIST_UNIMPORTANT
    billboard
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    callnative BehParticleInit
    begin_repeat 30
        callnative BehParticleLoop
    end_repeat
    deactivate

glabel beh_small_particle_bubbles # 046C
    begin OBJ_LIST_UNIMPORTANT
    billboard
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    callnative BehParticleInit
    begin_repeat 70
        callnative BehSmallBubblesLoop
    end_repeat
    deactivate

glabel beh_fish_group # 0494
    begin OBJ_LIST_DEFAULT
    begin_loop
        callnative BehFishGroupLoop
    end_loop

glabel beh_cannon_base # 04A8
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_1C 0x0000007F, beh_cannon_barrel
    obj_set_int objInteractType, 0x4000
    obj_add_float objPosY, -340
    unknown_2D
    set_hitbox 0x0096, 0x0096
    obj_set_int objIntangibleTimer, 0
    begin_loop
        callnative BehCannonBaseLoop
    end_loop

glabel beh_cannon_barrel # 04E4
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_1E
    begin_loop
        callnative BehCannonBarrelLoop
    end_loop

glabel beh_cannon_base_unused # 0500
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    billboard
    obj_set_int objAnimState, -1
    begin_repeat 8
        callnative BehCannonBaseUnusedLoop
        obj_add_int objAnimState, 1
    end_repeat
    deactivate

glabel beh_chuckya # 0528
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_HOLDABLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int32 objAnimations, chuckya_seg8_anims_0800C070
    unknown_28 0x05
    obj_set_int objInteractType, 0x02
    set_hitbox 0x0096, 0x0064
    unknown_30 0x001E, 0xFE70, 0xFFCE, 0x03E8, 0x03E8, 0x00C8, 0x0000, 0x0000
    unknown_2C 0x00000000, beh_chuckya_anchor_mario
    obj_set_int objNumLootCoins, 5
    obj_set_int objIntangibleTimer, 0
    unknown_2D
    begin_loop
        callnative BehChuckyaLoop
    end_loop

glabel beh_chuckya_anchor_mario # 0584
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    billboard
    obj_set_float objParentRelativePosY, 0xFFC4
    obj_set_float objParentRelativePosZ, 0x0096
    begin_loop
        callnative BehChuckyaAnchorMarioLoop
    end_loop

glabel beh_unused_05A8 # 05A8
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    break

glabel beh_rotating_platform # 05B4
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    unknown_2D
    begin_loop
        callnative BehRotatingPlatformLoop
        callnative load_object_collision_model
    end_loop

glabel beh_tower # 05D8
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    collision_data wf_seg7_collision_tower
    obj_set_float objCollisionDistance, 0x0BB8
    obj_set_float objDrawingDistance, 0x4E20
    begin_loop
        callnative load_object_collision_model
    end_loop

glabel beh_bullet_bill_cannon # 0600
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    collision_data wf_seg7_collision_bullet_bill_cannon
    obj_set_float objCollisionDistance, 0x012C
    begin_loop
        callnative load_object_collision_model
    end_loop

glabel beh_breakable_wall # 0624
    begin OBJ_LIST_SURFACE
    collision_data wf_seg7_collision_breakable_wall
    goto .L13000644
	
glabel beh_breakable_wall_2 # 0638
    begin OBJ_LIST_SURFACE
    collision_data wf_seg7_collision_breakable_wall_2
.L13000644: # 0644
    obj_or_int objFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    set_hitbox 0x012C, 0x0190
    obj_set_int objIntangibleTimer, 0
    begin_loop
        callnative BehBreakableWallLoop
        callnative load_object_collision_model
    end_loop

glabel beh_kickable_board # 066C
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    collision_data wf_seg7_collision_kickable_board
    set_hitbox 0x0064, 0x04B0
    unknown_2E 0x0001, 0x0001
    obj_set_float objCollisionDistance, 0x05DC
    obj_set_int objIntangibleTimer, 0
    begin_loop
        callnative BehKickableBoardLoop
    end_loop

glabel beh_tower_door # 06A4
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    collision_data wf_seg7_collision_tower_door
    set_hitbox 0x0064, 0x0064
    obj_set_int objIntangibleTimer, 0
    begin_loop
        callnative BehTowerDoorLoop
        callnative load_object_collision_model
    end_loop

glabel beh_rotating_counter_clockwise # 06D8
    begin OBJ_LIST_DEFAULT
    break

glabel beh_clocklike_rotation # 06E0
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    collision_data wf_seg7_collision_clocklike_rotation
    begin_loop
        callnative BehClocklikeRotationLoop
        callnative load_object_collision_model
    end_loop

glabel beh_koopa_shell_underwater # 0708
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_HOLDABLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO  | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    begin_loop
        callnative BehKoopaShellUnderwaterLoop
    end_loop

glabel beh_exit_podium_warp # 0720
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int objInteractType, 0x2000
    unknown_1E
    obj_set_float objCollisionDistance, 0x1F40
    collision_data ttm_seg7_collision_podium_warp
    obj_set_int objIntangibleTimer, 0
    set_hitbox 0x0032, 0x0032
    begin_loop
        callnative load_object_collision_model
        obj_set_int objInteractStatus, 0
    end_loop

glabel beh_fading_warp # 075C
    begin OBJ_LIST_LEVEL
    obj_set_int objUnk190, 0x0001
    obj_or_int objFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int objInteractType, 0x2000
    obj_set_int objIntangibleTimer, 0
    begin_loop
        callnative BehFadingWarpLoop
    end_loop

glabel beh_warp # 0780
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int objInteractType, 0x2000
    obj_set_int objIntangibleTimer, 0
    begin_loop
        callnative BehWarpLoop
    end_loop

glabel beh_warp_pipe # 07A0
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int objInteractType, 0x2000
    collision_data warp_pipe_seg3_collision_03009AC8
    obj_set_float objDrawingDistance, 0x3E80
    obj_set_int objIntangibleTimer, 0
    set_hitbox 0x0046, 0x0032
    begin_loop
        callnative BehWarpLoop
        callnative load_object_collision_model
    end_loop

glabel beh_white_puff_explosion # 07DC
    begin OBJ_LIST_UNIMPORTANT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    billboard
    begin_loop
        callnative BehWhitePuffExplosingLoop
    end_loop

glabel beh_spawned_star # 07F8
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_set_int objBehParams2ndByte, 1
    goto .L13000814
	
glabel beh_unused_080C # 080C
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
.L13000814: # 0814
    unknown_2D
    callnative BehUnused080CInit
    begin_loop
        callnative BehUnused080CLoop
    end_loop

glabel beh_mr_i_blue_coin # 0830
    begin OBJ_LIST_LEVEL
    obj_set_int objInteractType, 0x10
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    billboard
    obj_set_int objIntangibleTimer, 0
    obj_set_float objVar110, 0x0014
    obj_set_int objAnimState, -1
    unknown_30 0x001E, 0xFE70, 0xFFBA, 0x03E8, 0x03E8, 0x00C8, 0x0000, 0x0000
    callnative BehCoinInit
    obj_set_int objDamageOrCoinValue, 0x0005
    set_hitbox 0x0078, 0x0040
    begin_loop
        callnative BehCoinLoop
        obj_add_int objAnimState, 1
    end_loop

glabel beh_coin_inside_boo # 0888
    begin OBJ_LIST_LEVEL
    set_hitbox 0x0064, 0x0040
    obj_set_int objInteractType, 0x10
    obj_or_int objFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_30 0x001E, 0xFE70, 0xFFBA, 0x03E8, 0x03E8, 0x00C8, 0x0000, 0x0000
    billboard
    callnative bhv_init_room
    begin_loop
        callnative BehCoinInsideBooLoop
        obj_add_int objAnimState, 1
    end_loop

glabel beh_coin_formation_spawn # 08D0
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    billboard
    begin_loop
        callnative BehCoinFormationSpawnLoop
    end_loop

glabel beh_coin_formation # 08EC
    begin OBJ_LIST_SPAWNER
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    callnative BehCoinFormationInit
    begin_loop
        callnative BehCoinFormationLoop
    end_loop

glabel beh_one_coin # 090C
    begin OBJ_LIST_LEVEL
    obj_set_int objBehParams2ndByte, 1
    goto .L13000920
	
glabel beh_collectable_coin # 091C
    begin OBJ_LIST_LEVEL
.L13000920: # 0920
    billboard
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    callnative BehTempCoinInit
    begin_loop
        callnative BehCollectableCoinLoop
    end_loop

glabel beh_temporary_coin # 0940
    begin OBJ_LIST_LEVEL
    billboard
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    callnative BehTempCoinInit
    begin_loop
        callnative BehTempCoingLoop
    end_loop

glabel beh_three_coins_spawn # 0964
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    begin_repeat 3
        unknown_1C 0x00000074, beh_single_coin_gets_spawned
    end_repeat
    deactivate

glabel beh_ten_coins_spawn # 0984
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    begin_repeat 10
        unknown_1C 0x00000074, beh_single_coin_gets_spawned
    end_repeat
    deactivate

glabel beh_single_coin_gets_spawned # 09A4
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    billboard
    callnative BehCoinInit
    unknown_30 0x001E, 0xFE70, 0xFFBA, 0x03E8, 0x03E8, 0x00C8, 0x0000, 0x0000
    begin_loop
        callnative BehCoinLoop
        obj_add_int objAnimState, 1
    end_loop

glabel beh_coin_sparkles # 09E0
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    billboard
    obj_set_float objGraphYOffset, 25
    obj_set_int objAnimState, -1
    begin_repeat 8
        obj_add_int objAnimState, 1
    end_repeat
    begin_repeat 2
        callnative BehCoinSparklesLoop
    end_repeat
    deactivate

glabel beh_golden_coin_sparkles # 0A14
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    unknown_35
    begin_repeat 3
        callnative BehGoldenCoinSparklesLoop
    end_repeat
    deactivate

glabel beh_wall_tiny_star_particle # 0A34
    begin OBJ_LIST_UNIMPORTANT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    billboard
    begin_repeat 10
        callnative BehWallTinyStarParticleLoop
    end_repeat
    deactivate

glabel beh_wall_tiny_star_particle_spawn # 0A54
    begin OBJ_LIST_DEFAULT
    unknown_35
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_bit_clear_int32 objUnkE0, 0x00040000
    callnative BehTinyStarParticlesInit
    delay 1
    deactivate

glabel beh_pound_tiny_star_particle # 0A78
    begin OBJ_LIST_UNIMPORTANT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    billboard
    begin_repeat 10
        callnative BehPoundTinyStarParticleLoop
    end_repeat
    deactivate

glabel beh_pound_tiny_star_particle_spawn # 0A98
    begin OBJ_LIST_DEFAULT
    unknown_35
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_bit_clear_int32 objUnkE0, 0x00000010
    callnative BehPoundTinyStarParticleInit
    delay 1
    deactivate

glabel beh_punch_tiny_triangle # 0ABC
    begin OBJ_LIST_UNIMPORTANT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    billboard
    begin_loop
        callnative BehPunchTinyTriangleLoop
    end_loop

glabel beh_punch_tiny_triangle_spawn # 0AD8
    begin OBJ_LIST_DEFAULT
    unknown_35
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_bit_clear_int32 objUnkE0, 0x00080000
    callnative BehPunchTinyTriangleInit
    delay 1
    deactivate

glabel beh_door_warp # 0AFC
    begin OBJ_LIST_SURFACE
    obj_set_int objInteractType, 0x800
    goto .L13000B14
	
glabel beh_door # 0B0C
    begin OBJ_LIST_SURFACE
    obj_set_int objInteractType, 0x04
.L13000B14: # 0B14
    obj_or_int objFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int32 objAnimations, door_seg3_anim_030156C0
    unknown_28 0x00
    collision_data door_seg3_collision_0301CE78
    set_hitbox 0x0050, 0x0064
    obj_set_int objIntangibleTimer, 0
    obj_set_float objCollisionDistance, 0x03E8
    unknown_2D
    callnative BehDoorInit
    begin_loop
        callnative BehDoorLoop
    end_loop

glabel beh_grindel # 0B58
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    collision_data ssl_seg7_collision_grindel
    unknown_1E
    obj_add_float objPosY, 1
    unknown_2D
    begin_loop
        callnative BehGrindelThwompLoop
        callnative load_object_collision_model
    end_loop

glabel beh_thwomp_2 # 0B8C
    begin OBJ_LIST_SURFACE
    collision_data thwomp_seg5_collision_0500B92C
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_1E
    obj_add_float objPosY, 1
    unknown_2D
    scale 140
    obj_set_float objDrawingDistance, 0x0FA0
    begin_loop
        callnative BehGrindelThwompLoop
        callnative load_object_collision_model
    end_loop

glabel beh_thwomp # 0BC8
    begin OBJ_LIST_SURFACE
    collision_data thwomp_seg5_collision_0500B7D0
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_1E
    obj_add_float objPosY, 1
    scale 140
    unknown_2D
    obj_set_float objDrawingDistance, 0x0FA0
    begin_loop
        callnative BehGrindelThwompLoop
        callnative load_object_collision_model
    end_loop

glabel beh_tumbling_bridge_platform # 0C04
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_float objCollisionDistance, 0x012C
    begin_loop
        callnative BehTumblingBridgePlatformLoop
        callnative load_object_collision_model
    end_loop

glabel beh_wf_tumbling_bridge # 0C28
    begin OBJ_LIST_SPAWNER
    obj_or_int objFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_2D
    begin_loop
        callnative BehTumblingBridgeLoop
    end_loop

glabel beh_bbh_tumbling_platform_group # 0C44
    begin OBJ_LIST_SPAWNER
    obj_or_int objFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_2D
    obj_set_int objBehParams2ndByte, 1
    begin_loop
        callnative BehTumblingBridgeLoop
    end_loop

glabel beh_tumbling_platform # 0C64
    begin OBJ_LIST_SPAWNER
    obj_or_int objFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_2D
    obj_set_int objBehParams2ndByte, 2
    begin_loop
        callnative BehTumblingBridgeLoop
    end_loop

glabel beh_burning # 0C84
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    billboard
    unknown_2D
    scale 700
    interact_type 0x00040000
    unknown_2B 0x0032, 0x0019, 0x0019
    obj_set_int objIntangibleTimer, 0
    callnative bhv_init_room
    begin_loop
        obj_set_int objInteractStatus, 0
        unknown_34 objAnimState, 0x0002
    end_loop

glabel beh_another_elavator # 0CC8
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    collision_data hmc_seg7_collision_elevator
    unknown_2D
    callnative BehElevatorInit
    begin_loop
        callnative BehElevatorLoop
        callnative load_object_collision_model
    end_loop

glabel beh_rr_elevator_platform # 0CFC
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    collision_data rr_seg7_collision_elevator_platform
    unknown_2D
    callnative BehElevatorInit
    begin_loop
        callnative BehElevatorLoop
        callnative load_object_collision_model
    end_loop

glabel beh_hmc_elevator_platform # 0D30
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    collision_data hmc_seg7_collision_elevator
    unknown_2D
    callnative BehElevatorInit
    callnative bhv_init_room
    begin_loop
        callnative BehElevatorLoop
        callnative load_object_collision_model
    end_loop

glabel beh_water_mist # 0D6C
    begin OBJ_LIST_UNIMPORTANT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    billboard
    obj_set_int objOpacity, 0xFE
    obj_set_float objForwardVel, 0x0014
    obj_set_float objVelY, 0xFFF8
    obj_add_float objPosY, 62
    begin_loop
        callnative BehWaterMistLoop
    end_loop

glabel beh_water_mist_spawn # 0D98
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    begin_repeat 8
        callnative BehWaterMistSpawnLoop
    end_repeat
    deactivate

glabel beh_break_box_triangle # 0DB4
    begin OBJ_LIST_UNIMPORTANT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    begin_repeat 18
        callnative obj_rotate_face_angle_using_vel
        callnative obj_move_using_fvel_and_gravity
    end_repeat
    deactivate

glabel beh_water_mist2 # 0DD8
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_2D
    obj_set_int objFaceAnglePitch, 0xC000
    scale 2100
    begin_loop
        callnative BehWaterMist2Loop
    end_loop

glabel beh_unused_0DFC # 0DFC
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_set_int objAnimState, -1
    obj_set_float objFaceAnglePitch, 0
    obj_set_float objFaceAngleYaw, 0
    obj_set_float objFaceAngleRoll, 0
    begin_repeat 6
        obj_add_int objAnimState, 1
    end_repeat
    deactivate

glabel beh_pound_white_puffs # 0E24
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    callnative BehPoundWhitePuffsInit
    delay 1
    deactivate

glabel beh_ground_sand # 0E3C
    begin OBJ_LIST_DEFAULT
glabel beh_unused_0E40 # 0E40
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    callnative BehUnused0E40Init
    delay 1
    deactivate

glabel beh_ground_snow # 0E58
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    callnative BehGroundSnowInit
    delay 1
    deactivate

glabel beh_wind # 0E70
    begin OBJ_LIST_UNIMPORTANT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    begin_loop
        callnative BehWindLoop
    end_loop

glabel beh_end_toad # 0E88
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_set_int32 objAnimations, toad_seg6_anims_0600FB58
    unknown_28 0x00
    begin_loop
        callnative BehEndToadLoop
    end_loop

glabel beh_end_peach # 0EAC
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_set_int32 objAnimations, peach_seg5_anims_0501C41C
    unknown_28 0x00
    begin_loop
        callnative BehEndPeachLoop
    end_loop

glabel beh_piranha_particles_spawn # 0ED0
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    unknown_30 0x001E, 0xFE70, 0xFFCE, 0x03E8, 0x03E8, 0x00C8, 0x0000, 0x0000
    obj_set_int objIntangibleTimer, 0
    set_hitbox 0x0028, 0x0028
    begin_loop
        callnative BehPiranhaParticlesSpawnLoop
    end_loop

glabel beh_ukiki # 0F08
    begin OBJ_LIST_GENACTOR
    goto .L13001CB4
glabel beh_unused_0F14 # 0F14
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_set_float objPosX, 0x0A00
    obj_set_float objPosY, 0x05B1
    obj_set_float objPosZ, 0x076A
    break

glabel beh_little_cage2 # 0F2C
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    unknown_2D
    begin_loop
        callnative BehLittleCage2Loop
    end_loop

glabel beh_little_cage # 0F48
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_2D
    collision_data ttm_seg7_collision_little_cage
    unknown_1C 0x0000007A, beh_little_cage2
    unknown_1C 0x00000000, beh_unused_0F14
    obj_set_float objCollisionDistance, 0x4E20
    unknown_30 0x001E, 0xFE70, 0xFFCE, 0x03E8, 0x03E8, 0x00C8, 0x0000, 0x0000
    begin_loop
        callnative BehLittleCageLoop
    end_loop

glabel beh_bifs_sinking_platforms # 0F9C
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    collision_data bitfs_seg7_collision_sinking_platform
    unknown_2D
    begin_loop
        callnative BehBifsSinkingPlatformLoop
        callnative load_object_collision_model
    end_loop

glabel beh_bifs_sinking_cage_platform # 0FC8
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    collision_data bitfs_seg7_collision_sinking_cage_platform
    unknown_2D
    unknown_1C 0x00000039, beh_ddd_moving_pole
    begin_loop
        callnative BehBifsSinkingCagePlatformLoop
        callnative load_object_collision_model
    end_loop

glabel beh_ddd_moving_pole # 1000
    begin OBJ_LIST_POLELIKE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_set_int objInteractType, 0x40
    set_hitbox 0x0050, 0x02C6
    obj_set_int objIntangibleTimer, 0
    begin_loop
        callnative BehDddMovingPoleLoop
        callnative BehClimbDetectLoop
    end_loop

glabel beh_tilting_inverted_pyramid # 1030
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    collision_data bitfs_seg7_collision_inverted_pyramid
    unknown_2D
    callnative BehTiltingPlatformInit
    begin_loop
        callnative BehTiltingPlatformLoop
        callnative load_object_collision_model
    end_loop

glabel beh_squishable_platform # 1064
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    collision_data bitfs_seg7_collision_squishable_platform
    obj_set_float objCollisionDistance, 0x2710
    callnative BehTiltingPlatformInit
    begin_loop
        callnative BehSquishablePlatformLoop
        callnative load_object_collision_model
    end_loop

glabel beh_cut_out_object # 1098
    begin OBJ_LIST_GENACTOR
    unknown_35
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    break

glabel beh_beta_moving_flames_spawn # 10A8
    begin_loop
        callnative BehBetaMovingFlamesSpawnLoop
    end_loop

glabel beh_beta_moving_flames # 10B8
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    billboard
    begin_loop
        callnative BehBetaMovingFlamesLoop
        obj_add_int objAnimState, 1
    end_loop

glabel beh_rr_rotating_platform_with_fire # 10D8
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    collision_data rr_seg7_collision_rotating_platform_with_fire
    obj_set_float objCollisionDistance, 0x05DC
    unknown_2D
    begin_loop
        callnative BehRrRotatingPlatformFireLoop
        callnative load_object_collision_model
    end_loop

glabel beh_flamethrower # 1108
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_2D
    begin_loop
        callnative BehFlamethrowerLoop
    end_loop

glabel beh_flamethrower_flame # 1124
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    interact_type 0x00040000
    unknown_2B 0x0032, 0x0019, 0x0019
    billboard
    unknown_2D
    obj_set_int objIntangibleTimer, 0
    callnative bhv_init_room
    begin_loop
        callnative BehFlamethrowerFlameLoop
        obj_add_int objAnimState, 1
    end_loop

glabel beh_bouncing_fireball # 1168
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_35
    begin_loop
        callnative BehBouncingFireballLoop
    end_loop

glabel beh_bouncing_fireball_flame # 1184
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    interact_type 0x00040000
    obj_set_float objGraphYOffset, 30
    unknown_2B 0x0032, 0x0019, 0x0019
    unknown_30 0x001E, 0xFE70, 0xFFBA, 0x03E8, 0x03E8, 0x00C8, 0x0000, 0x0000
    billboard
    begin_loop
        callnative BehBouncingFireballFlameLoop
        obj_add_int objAnimState, 1
    end_loop

glabel beh_bowser_shock_wave # 11D0
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int objOpacity, 0x00FF
    begin_loop
        callnative BehBowserShockWave
    end_loop

glabel beh_flame_mario # 11EC
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    billboard
    obj_set_float objGraphYOffset, 0x0046
    obj_set_int objAnimState, -1
    begin_loop
        obj_add_int objAnimState, 1
        callnative BehFlameMarioLoop
    end_loop

glabel beh_black_smoke_mario # 1214
    begin OBJ_LIST_UNIMPORTANT
    obj_or_int objFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    billboard
    obj_set_int objAnimState, 0x0004
    obj_set_float objGraphYOffset, 0x0032
    begin_repeat 8
        callnative BehBlackSmokeMarioLoop
        delay 1
        callnative BehBlackSmokeMarioLoop
        delay 1
        callnative BehBlackSmokeMarioLoop
    end_repeat
    deactivate

glabel beh_black_smoke_bowser # 1254
    begin OBJ_LIST_UNIMPORTANT
    obj_or_int objFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    billboard
    obj_set_float objGraphYOffset, 0x0000
    begin_repeat 8
        callnative BehBlackSmokeBowserLoop
        unknown_34 objAnimState, 0x0004
    end_repeat
    deactivate

glabel beh_black_smoke_upward # 127C
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    begin_repeat 4
        callnative BehBlackSmokeUpwardLoop
    end_repeat
    deactivate

glabel beh_multiple_coins # 1298
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_35
    begin_loop
        callnative BehMultipleCoinsLoop
    end_loop

glabel beh_spindrift # 12B4
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int32 objAnimations, spindrift_seg5_anims_05002D68
    unknown_28 0x00
    unknown_30 0x001E, 0xFE70, 0x0000, 0x0000, 0x0000, 0x00C8, 0x0000, 0x0000
    unknown_2D
    obj_set_int objUnk190, 0x0080
    begin_loop
        callnative BehSpindriftLoop
    end_loop

glabel beh_tower_platform_group # 12F4
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    unknown_35
    obj_add_float objPosY, 300
    unknown_2D
    begin_loop
        callnative BehTowerPlatformGroupLoop
    end_loop

glabel beh_wf_sliding_platform # 1318
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    collision_data wf_seg7_collision_platform
    begin_loop
        callnative BehWfSlidingPlatformLoop
        callnative load_object_collision_model
    end_loop

glabel beh_wf_elevator_platform # 1340
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    collision_data wf_seg7_collision_platform
    begin_loop
        callnative BehWfElevatorPlatformLoop
        callnative load_object_collision_model
    end_loop

glabel beh_wf_solid_platform # 1368
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    collision_data wf_seg7_collision_platform
    begin_loop
        callnative BehWfSolidPlatformLoop
        callnative load_object_collision_model
    end_loop

glabel beh_snow_leaf_particle_spawn # 1390
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    callnative BehSnowLeafParticleSpawnInit
    delay 1
    deactivate

glabel beh_tree_snow # 13A8
    begin OBJ_LIST_UNIMPORTANT
    obj_or_int objFlags, (OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    billboard
    begin_loop
        callnative BehTreeSnowOrLeafLoop
    end_loop

glabel beh_tree_leaf # 13C4
    begin OBJ_LIST_UNIMPORTANT
    obj_or_int objFlags, (OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    begin_loop
        callnative BehTreeSnowOrLeafLoop
    end_loop

glabel beh_another_tilting_platform # 13DC
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_2D
    callnative BehTiltingPlatformInit
    begin_loop
        callnative BehTiltingPlatformLoop
        callnative load_object_collision_model
    end_loop

glabel beh_squarish_path_moving # 1408
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    collision_data bitdw_seg7_collision_moving_pyramid
    unknown_2D
    begin_loop
        callnative BehSquarishPathMovingLoop
    end_loop

glabel beh_piranha_plant_bubble # 142C
    begin OBJ_LIST_UNIMPORTANT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    billboard
    begin_loop
        callnative BehPiranhaPlantBubbleLoop
    end_loop

glabel beh_piranha_plant_waking_bubbles # 1448
    begin OBJ_LIST_UNIMPORTANT
    billboard
    obj_or_int objFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    begin_repeat 10
        callnative BehPiranhaPlantWakingBubblesLoop
    end_repeat
    deactivate

glabel beh_purple_switch_staircase # 1468
    begin OBJ_LIST_SURFACE
    obj_set_int objBehParams2ndByte, 1
    goto .Lbeh_floor_switch_1488
glabel beh_floor_switch_grills # 1478
    begin OBJ_LIST_SURFACE
    goto .Lbeh_floor_switch_1488
glabel beh_floor_switch_hardcoded_model # 1484
    begin OBJ_LIST_SURFACE
.Lbeh_floor_switch_1488: # 1488
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    collision_data purple_switch_seg8_collision_0800C7A8
    begin_loop
        callnative BehFloorSwitchLoop
        callnative load_object_collision_model
    end_loop

glabel beh_floor_switch_hidden_objects # 14AC
    begin OBJ_LIST_SURFACE
    obj_set_int objBehParams2ndByte, 2
    goto .Lbeh_floor_switch_1488
glabel beh_hidden_object # 14BC
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    collision_data breakable_box_seg8_collision_08012D70
    obj_set_float objCollisionDistance, 0x012C
    begin_loop
        callnative BehHiddenObjectLoop
    end_loop

glabel beh_breakable_box # 14E0
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    collision_data breakable_box_seg8_collision_08012D70
    obj_set_float objCollisionDistance, 0x01F4
    callnative bhv_init_room
    begin_loop
        callnative BehBreakableBoxLoop
        callnative load_object_collision_model
    end_loop
    break

glabel beh_pushable # 1518
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    collision_data metal_box_seg8_collision_08024C28
    obj_set_float objCollisionDistance, 0x01F4
    unknown_2D
    begin_loop
        callnative BehPushableLoop
        callnative load_object_collision_model
    end_loop

glabel beh_heave_ho # 1548
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_HOLDABLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int32 objAnimations, heave_ho_seg5_anims_0501534C
    unknown_28 0x00
    unknown_30 0x00C8, 0xFE70, 0xFFCE, 0x03E8, 0x03E8, 0x0258, 0x0000, 0x0000
    unknown_2C 0x00000000, beh_heave_ho_throw_mario
    obj_set_int objInteractType, 0x02
    obj_set_int objUnk190, 0x0204
    set_hitbox 0x0078, 0x0064
    unknown_2D
    obj_set_int objIntangibleTimer, 0
    begin_loop
        callnative BehHeaveHoLoop
    end_loop

glabel beh_heave_ho_throw_mario # 15A4
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    billboard
    begin_loop
        callnative BehHeaveHoThrowMarioLoop
    end_loop

glabel beh_ccm_touched_star_spawn # 15C0
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, (OBJ_FLAG_4000 | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    set_hitbox 0x01F4, 0x01F4
    obj_set_int objIntangibleTimer, 0
    begin_loop
        callnative BehCcmTouchedStarSpawnLoop
    end_loop

glabel beh_pound_explodes # 15E4
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    collision_data sl_seg7_collision_pound_explodes
    unknown_2D
    begin_loop
        callnative BehPoundExplodesLoop
    end_loop

glabel beh_beta_trampoline # 1608
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    collision_data springboard_collision_05001A28
    unknown_2D
    begin_loop
        callnative BehBetaTrampolineLoop
        callnative load_object_collision_model
    end_loop

glabel beh_beta_trampoline_spawn # 1634
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    unknown_2D
    begin_loop
        callnative BehBetaTrampolineSpawnLoop
    end_loop

glabel beh_jumping_box # 1650
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_HOLDABLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO  | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_30 0x001E, 0xFE70, 0xFFCE, 0x03E8, 0x03E8, 0x0258, 0x0000, 0x0000
    begin_loop
        callnative BehJumpingBoxLoop
    end_loop

glabel beh_boo_cage # 167C
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_float objGraphYOffset, 0x000A
    unknown_30 0x001E, 0xFE70, 0xFFCE, 0x0000, 0x0000, 0x00C8, 0x0000, 0x0000
    begin_loop
        callnative BehBooCageLoop
    end_loop

glabel beh_stub # 16AC
    begin OBJ_LIST_DEFAULT
    unknown_35
    break

glabel beh_igloo # 16B8
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    interact_type 0x40000000
    set_hitbox 0x0064, 0x00C8
    obj_set_int objIntangibleTimer, 0
    unknown_2D
    begin_loop
        obj_set_int objInteractStatus, 0
    end_loop

glabel beh_bowser_key_2 # 16E4
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    unknown_2D
    unknown_30 0x001E, 0xFE70, 0xFFBA, 0x03E8, 0x03E8, 0x00C8, 0x0000, 0x0000
    begin_loop
        callnative BehBowserKey2Loop
    end_loop

glabel beh_grand_star # 1714
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    interact_type 0x00001000
    obj_set_int objUnk190, 0x0800
    set_hitbox 0x00A0, 0x0064
    unknown_2D
    begin_loop
        callnative BehGrandStarLoop
    end_loop

glabel beh_beta_boo_key_inside # 1744
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    set_hitbox 0x0020, 0x0040
    unknown_30 0x001E, 0xFE70, 0xFFBA, 0x03E8, 0x03E8, 0x00C8, 0x0000, 0x0000
    begin_loop
        callnative BehBetaBooKeyInsideLoop
    end_loop

glabel beh_beta_boo_key_outside # 1778
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    set_hitbox 0x0020, 0x0040
    obj_set_int objIntangibleTimer, 0
    begin_loop
        callnative BehBetaBooKeyOutsideLoop
    end_loop

glabel beh_bullet_bill # 179C
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_2D
    unknown_2B 0x0032, 0x0032, 0x0032
    interact_type 0x00000008
    obj_set_int objDamageOrCoinValue, 3
    scale 40
    obj_set_int objIntangibleTimer, 0
    unknown_30 0x001E, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
    callnative BehBulletBillInit
    begin_loop
        callnative BehBulletBillLoop
    end_loop

glabel beh_white_puff_smoke # 17F4
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    billboard
    obj_add_float objPosY, -100
    callnative BehWhitePuffSmokeInit
    obj_set_int objAnimState, -1
    begin_repeat 10
        obj_add_int objAnimState, 1
    end_repeat
    deactivate

glabel beh_unused_1820 # 1820
    begin OBJ_LIST_DEFAULT
    break

glabel beh_bowser_tail_anchor # 1828
    begin OBJ_LIST_GENACTOR
    unknown_2B 0x0064, 0x0032, 0xFFCE
    obj_set_int objIntangibleTimer, 0
    unknown_35
    begin_loop
        callnative BehBowserTailAnchorLoop
    end_loop

glabel beh_bowser # 1850
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_HOLDABLE | OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int objInteractType, 0x02
    set_hitbox 0x0190, 0x0190
    unknown_1E
    unknown_2D
    obj_set_int32 objAnimations, bowser_seg6_anims_06057690
    unknown_1C 0x00000000, beh_bowser_body_anchor
    unknown_1C 0x00000065, beh_bowser_flame_spawn
    unknown_2C 0x00000000, beh_bowser_tail_anchor
    obj_set_int objNumLootCoins, 0x0032
    unknown_30 0x0000, 0xFE70, 0xFFBA, 0x03E8, 0x03E8, 0x00C8, 0x0000, 0x0000
    unknown_2D
    callnative BehBowserInit
    begin_loop
        callnative BehBowserLoop
    end_loop

glabel beh_bowser_body_anchor # 18CC
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    set_hitbox 0x0064, 0x012C
    interact_type 0x00000008
    obj_set_int objUnk190, 0x0008
    unknown_35
    obj_set_int objDamageOrCoinValue, 2
    obj_set_int objIntangibleTimer, 0
    begin_loop
        callnative BehBowserBodyAnchorLoop
    end_loop

glabel beh_bowser_flame_spawn # 1904
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    geo_layout 0x0000
    begin_loop
        callnative BehBowserFlameSpawnLoop
    end_loop

glabel beh_tilting_bowser_lava_platform # 1920
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    collision_data bowser_2_seg7_collision_tilting_platform
    obj_set_float objDrawingDistance, 0x4E20
    obj_set_float objCollisionDistance, 0x4E20
    obj_set_int objFaceAngleYaw, 0x0000
    unknown_2D
    begin_loop
        callnative obj_rotate_face_angle_using_vel
        callnative load_object_collision_model
    end_loop

glabel beh_falling_bowser_platform # 1958
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_set_float objDrawingDistance, 0x4E20
    obj_set_float objCollisionDistance, 0x4E20
    unknown_2D
    begin_loop
        callnative BehFallingBowserPlatformLoop
        callnative load_object_collision_model
    end_loop

glabel beh_blue_bowser_flame # 1984
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    interact_type 0x00040000
    billboard
    unknown_30 0x0000, 0xFE70, 0xFFBA, 0x03E8, 0x03E8, 0x00C8, 0x0000, 0x0000
    callnative BehBlueBowserFlameInit
    begin_loop
        callnative BehBlueBowserFlameLoop
        unknown_34 objAnimState, 0x0002
    end_loop

glabel beh_flame_floating_landing # 19C8
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    interact_type 0x00040000
    billboard
    unknown_30 0x0000, 0xFE70, 0xFFBA, 0x03E8, 0x03E8, 0x00C8, 0x0000, 0x0000
    callnative BehFlameFloatingLandingInit
    begin_loop
        callnative BehFlameFloatingLandingLoop
        unknown_34 objAnimState, 0x0002
    end_loop

glabel beh_blue_flames_group # 1A0C
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    interact_type 0x00040000
    billboard
    begin_loop
        callnative BehBlueFlamesGroupLoop
    end_loop

glabel beh_flame_bouncing # 1A30
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    interact_type 0x00040000
    billboard
    callnative BehFlameBouncingInit
    unknown_30 0x0000, 0xFE70, 0xFFBA, 0x0000, 0x0000, 0x00C8, 0x0000, 0x0000
    begin_loop
        callnative BehFlameBouncingLoop
        unknown_34 objAnimState, 0x0002
    end_loop

glabel beh_flame_moving_forward_growing # 1A74
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    interact_type 0x00040000
    billboard
    callnative BehFlameMovingForwardGrowingInit
    begin_loop
        callnative BehFlameMovingForwardGrowingLoop
        unknown_34 objAnimState, 0x0002
    end_loop

glabel beh_flame_bowser # 1AA4
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    interact_type 0x00040000
    billboard
    callnative BehFlameBowserInit
    unknown_30 0x0000, 0xFE70, 0xFFBA, 0x03E8, 0x03E8, 0x00C8, 0x0000, 0x0000
    begin_loop
        callnative BehFlameBowserLoop
        unknown_34 objAnimState, 0x0002
    end_loop

glabel beh_flame_large_burning_out # 1AE8
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    interact_type 0x00040000
    billboard
    callnative BehFlameLargeBurningOutInit
    unknown_30 0x0000, 0xFE70, 0xFFBA, 0x03E8, 0x03E8, 0x00C8, 0x0000, 0x0000
    begin_loop
        callnative BehFlameBowserLoop
        unknown_34 objAnimState, 0x0002
    end_loop

glabel beh_blue_fish # 1B2C
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_2D
    obj_set_int32 objAnimations, blue_fish_seg3_anims_0301C2B0
    unknown_28 0x00
    begin_loop
        callnative BehBlueFishLoop
    end_loop

glabel beh_tank_fish_groups # 1B54
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    unknown_2D
    begin_loop
        callnative BehTankFishGroupsLoop
    end_loop

glabel beh_checkerboard_elevator_group # 1B70
    begin OBJ_LIST_SPAWNER
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    callnative BehCheckerboardElevatorGroupInit
    delay 1
    deactivate

glabel beh_checkerboard_platform_sub # 1B88
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    collision_data checkerboard_platform_seg8_collision_0800D710
    callnative BehCheckerboardPlatformInit
    unknown_2D
    begin_loop
        callnative BehCheckerboardPlatformLoop
    end_loop

glabel beh_door_key1 # 1BB4
    begin OBJ_LIST_DEFAULT
    obj_set_int32 objAnimations, bowser_key_seg3_anims_030172D0
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    begin_loop
        callnative BehDoorKey1Loop
    end_loop

glabel beh_door_key2 # 1BD4
    begin OBJ_LIST_DEFAULT
    obj_set_int32 objAnimations, bowser_key_seg3_anims_030172D0
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    begin_loop
        callnative BehDoorKey2Loop
    end_loop

glabel beh_invisible_objects_under_bridge # 1BF4
    begin OBJ_LIST_DEFAULT
    callnative BehInvisibleObjUnderBridge
    break

glabel beh_water_level_pillar # 1C04
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    collision_data inside_castle_seg7_collision_water_level_pillar
    callnative BehWaterLevelPillarInit
    begin_loop
        callnative BehWaterLevelPillarLoop
        callnative load_object_collision_model
    end_loop

glabel beh_ddd_warp # 1C34
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_set_float objCollisionDistance, 0x7530
    begin_loop
        callnative BehDddWarpLoop
        callnative load_object_collision_model
    end_loop

glabel beh_moat_grills # 1C58
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    collision_data castle_grounds_seg7_collision_moat_grills
    obj_set_float objCollisionDistance, 0x7530
    begin_loop
        callnative BehMoatGrillsLoop
    end_loop

glabel beh_clock_big_arm # 1C7C
    begin OBJ_LIST_DEFAULT
    obj_set_int objAngleVelRoll, 0xFE80
    goto .L13001C94
glabel beh_rotating_small_clock_arm # 1C8C
    begin OBJ_LIST_DEFAULT
    obj_set_int objAngleVelRoll, 0xFFE0
.L13001C94: # 1C94
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    callnative bhv_init_room
    begin_loop
        callnative BehRotatingClockArmLoop
    end_loop

glabel beh_ukiki_open_cage # 1CB0
    begin OBJ_LIST_GENACTOR
.L13001CB4: # 1CB4
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_HOLDABLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int objInteractType, 0x02
    obj_set_int objUnk190, 0x0010
    set_hitbox 0x0028, 0x0028
    obj_set_int objIntangibleTimer, 0
    unknown_1E
    obj_set_int32 objAnimations, ukiki_seg5_anims_05015784
    unknown_28 0x00
    unknown_30 0x001E, 0xFE70, 0xFFCE, 0x0000, 0x0000, 0x00C8, 0x0000, 0x0000
    unknown_2D
    callnative BehUkikiOpenCageInit
    begin_loop
        callnative BehUkikiOpenCageLoop
    end_loop

glabel beh_stub_1D0C # 1D0C
    begin OBJ_LIST_DEFAULT
    deactivate

glabel beh_lll_rotating_ccw # 1D14
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    collision_data lll_seg7_collision_hexagonal_platform
    unknown_2D
    begin_loop
        obj_set_int objAngleVelYaw, 0x0100
        obj_add_int objMoveAngleYaw, 0x100
        callnative load_object_collision_model
    end_loop

glabel beh_sinks_when_stepped_on # 1D40
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    collision_data lll_seg7_collision_floating_block
    obj_add_float objPosY, -50
    unknown_2D
    begin_loop
        callnative BehSinkWhenSteppedOnLoop
        callnative load_object_collision_model
    end_loop

glabel beh_stub_1D70 # 1D70
    begin OBJ_LIST_DEFAULT
    break

glabel beh_horizontal_movement # 1D78
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_add_float objPosY, -50
    collision_data lll_seg7_collision_octagonal_moving_platform
    begin_loop
        callnative BehHorizontalMovementLoop
        callnative load_object_collision_model
    end_loop

glabel beh_snow_ball # 1DA4
    break

glabel beh_rotating_cw_with_fire_bars # 1DA8
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    collision_data lll_seg7_collision_rotating_fire_bars
    obj_set_float objCollisionDistance, 0x0FA0
    begin_loop
        callnative BehRotatingCwFireBarsLoop
    end_loop

glabel beh_lll_rotating_hex_flame # 1DCC
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    interact_type 0x00040000
    unknown_2B 0x0032, 0x0064, 0x0032
    obj_set_int objIntangibleTimer, 0
    billboard
    begin_loop
        callnative BehLllRotatingHexFlameLoop
        obj_add_int objAnimState, 1
    end_loop

glabel beh_lll_wood_piece # 1E04
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    collision_data lll_seg7_collision_wood_piece
    unknown_2D
    begin_loop
        callnative BehLllWoodPieceLoop
        callnative load_object_collision_model
    end_loop

glabel beh_floating_wood_bridge # 1E30
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    geo_layout 0x0000
    begin_loop
        callnative BehFloatingWoodBridgeLoop
    end_loop

glabel beh_volcano_flames # 1E4C
    begin OBJ_LIST_UNIMPORTANT
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    billboard
    begin_loop
        obj_add_int objAnimState, 1
        callnative BehVolcanoFlamesLoop
    end_loop

glabel beh_lll_rotating_platform # 1E6C
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    collision_data lll_seg7_collision_rotating_platform
    begin_loop
        callnative BehLllRotatingPlatformLoop
        callnative load_object_collision_model
    end_loop

glabel beh_lll_slow_tilting_movement # 1E94
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    collision_data lll_seg7_collision_slow_tilting_platform
    obj_set_float objCollisionDistance, 0x07D0
    unknown_2D
    begin_loop
        callnative BehLllSlowTiltingMovementLoop
        callnative load_object_collision_model
    end_loop

glabel beh_lll_slow_up_down_movement # 1EC4
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    collision_data lll_seg7_collision_sinking_pyramids
    obj_add_float objPosY, 5
    obj_set_float objCollisionDistance, 0x07D0
    unknown_2D
    begin_loop
        callnative BehLllSlowUpDownMovementLoop
        callnative load_object_collision_model
    end_loop

glabel beh_tilting_inverted_pyramid2 # 1EF8
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    collision_data lll_seg7_collision_inverted_pyramid
    obj_add_float objPosY, 5
    unknown_2D
    callnative BehTiltingPlatformInit
    begin_loop
        callnative BehTiltingPlatformLoop
        callnative load_object_collision_model
    end_loop

glabel beh_unused_1F30 # 1F30
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    break

glabel beh_koopa_shell # 1F3C
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    unknown_30 0x001E, 0xFE70, 0xFFCE, 0x03E8, 0x03E8, 0x00C8, 0x0000, 0x0000
    begin_loop
        callnative BehKoopaShellLoop
    end_loop

glabel beh_koopa_shell_flame # 1F68
    begin OBJ_LIST_UNIMPORTANT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    interact_type 0x00040000
    billboard
    begin_loop
        callnative BehKoopaShellFlameLoop
        unknown_34 objAnimState, 0x0002
    end_loop

glabel beh_tox_box # 1F90
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    collision_data ssl_seg7_collision_tox_box
    obj_add_float objPosY, 256
    obj_set_float objDrawingDistance, 0x1F40
    unknown_2D
    begin_loop
        callnative BehToxBoxLoop
    end_loop

glabel beh_piranha_plant_2 # 1FBC
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int32 objAnimations, piranha_plant_seg6_anims_0601C31C
    unknown_28 0x00
    interact_type 0x00000008
    set_hitbox 0x0064, 0x00C8
    unknown_2E 0x0032, 0x00C8
    obj_set_int objIntangibleTimer, 0
    obj_set_int objDamageOrCoinValue, 3
    obj_set_int objNumLootCoins, 5
    unknown_1C 0x000000A8, beh_piranha_plant_bubble
    obj_set_float objDrawingDistance, 0x07D0
    unknown_2D
    begin_loop
        callnative BehPiranhaPlant2Loop
    end_loop

glabel beh_lll_hexagonal_mesh # 2018
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    collision_data lll_hexagonal_mesh_seg3_collision_0301CECC
    begin_loop
        callnative load_object_collision_model
    end_loop

glabel beh_bowser_puzzle_piece # 2038
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    collision_data lll_seg7_collision_puzzle_piece
    unknown_2D
    obj_set_float objCollisionDistance, 0x0BB8
    begin_loop
        callnative BehBowserPuzzlePieceLoop
        callnative load_object_collision_model
    end_loop

glabel beh_bowser_puzzle # 2068
    begin OBJ_LIST_SPAWNER
    unknown_35
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_add_float objPosZ, -50
    begin_loop
        callnative BehBowserPuzzleLoop
    end_loop

glabel beh_tuxies_mother # 2088
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int32 objAnimations, penguin_seg5_anims_05008B74
    unknown_28 0x03
    unknown_30 0x001E, 0xFE70, 0xFFCE, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
    unknown_2D
    interact_type 0x00800000
    set_hitbox 0x00C8, 0x012C
    obj_set_int objIntangibleTimer, 0
    begin_loop
        callnative BehTuxiesMotherLoop
    end_loop

glabel beh_penguin_baby # 20D8
    begin OBJ_LIST_GENACTOR
    break

glabel beh_unused_20E0 # 20E0
    begin OBJ_LIST_GENACTOR
    break

glabel beh_small_penguin # 20E8
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_HOLDABLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_1E
    obj_set_int32 objAnimations, penguin_seg5_anims_05008B74
    unknown_28 0x00
    unknown_30 0x001E, 0xFE70, 0xFFCE, 0x0000, 0x0000, 0x00C8, 0x0000, 0x0000
    obj_set_int objInteractType, 0x02
    obj_set_int objUnk190, 0x0010
    obj_set_int objIntangibleTimer, 0
    set_hitbox 0x0028, 0x0028
    unknown_2D
    begin_loop
        callnative BehSmallPenguinLoop
    end_loop

glabel beh_fish_2 # 213C
    begin OBJ_LIST_DEFAULT
    obj_set_int objBehParams2ndByte, 0x0000
    goto beh_fish_common
glabel beh_fish_3 # 214C
    begin OBJ_LIST_DEFAULT
    obj_set_int objBehParams2ndByte, 1
    goto beh_fish_common
glabel beh_large_fish_group # 215C
    begin OBJ_LIST_DEFAULT
glabel beh_fish_common # 2160
    unknown_35
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    begin_loop
        callnative BehFishLoop
    end_loop

glabel beh_fish_group2 # 2178
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_2D
    begin_loop
        callnative BehFishGroup2Loop
    end_loop

glabel beh_wdw_express_elevator # 2194
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    collision_data wdw_seg7_collision_express_elevator_platform
    unknown_2D
    begin_loop
        callnative BehWdwExpressElevatorLoop
        callnative load_object_collision_model
    end_loop

glabel beh_wdw_express_elevator_platform # 21C0
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    collision_data wdw_seg7_collision_express_elevator_platform
    unknown_2D
    begin_loop
        callnative load_object_collision_model
    end_loop

glabel beh_chirp_chirp # 21E4
    begin OBJ_LIST_DEFAULT
    obj_set_int objVarF4, 1
    goto .Lbeh_chirp_chirp_21F4
.Lbeh_chirp_chirp_21F4: # 21F4
    unknown_35
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    begin_loop
        callnative BehBirdChirpChirpLoop
    end_loop

glabel beh_bub # 220C
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int32 objAnimations, bub_seg6_anims_06012354
    unknown_28 0x00
    unknown_2B 0x0014, 0x000A, 0x000A
    interact_type 0x00000008
    obj_set_int objDamageOrCoinValue, 1
    unknown_2D
    obj_set_int objIntangibleTimer, 0
    begin_loop
        callnative BehCheepCheepLoop
    end_loop

glabel beh_exclamation_box # 2250
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    collision_data exclamation_box_outline_seg8_collision_08025F78
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_set_float objCollisionDistance, 0x012C
    unknown_2D
    begin_loop
        callnative BehExclamationBoxLoop
    end_loop

glabel beh_rotating_exclamation_mark # 227C
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    scale 200
    begin_loop
        callnative BehRotatinExclamationBoxLoop
        obj_add_int objMoveAngleYaw, 0x800
    end_loop

glabel beh_sound_spawner # 229C
    begin OBJ_LIST_UNIMPORTANT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    delay 3
    callnative BehPlaySound
    delay 30
    deactivate

glabel beh_rock_solid # 22B8
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    collision_data jrb_seg7_collision_rock_solid
    begin_loop
        callnative load_object_collision_model
    end_loop

glabel beh_bowser_sub_door # 22D8
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    collision_data ddd_seg7_collision_bowser_sub_door
    obj_set_float objDrawingDistance, 0x4E20
    obj_set_float objCollisionDistance, 0x4E20
    begin_loop
        callnative BehBowsersSubLoop
        callnative load_object_collision_model
    end_loop

glabel beh_bowsers_sub # 2308
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_float objDrawingDistance, 0x4E20
    obj_set_float objCollisionDistance, 0x4E20
    collision_data ddd_seg7_collision_submarine
    begin_loop
        callnative BehBowsersSubLoop
        callnative load_object_collision_model
    end_loop

glabel beh_sushi_shark # 2338
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int32 objAnimations, sushi_seg5_anims_0500AE54
    unknown_2C 0x00000000, beh_sushi_shark_collision_child
    unknown_2B 0x0064, 0x0032, 0x0032
    interact_type 0x00000008
    obj_set_int objDamageOrCoinValue, 3
    unknown_2D
    unknown_28 0x00
    obj_set_int objIntangibleTimer, 0
    begin_loop
        callnative BehSushiSharkLoop
    end_loop

glabel beh_sushi_shark_collision_child # 2388
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    unknown_35
    begin_loop
        callnative BehSushiSharkCollisionLoop
    end_loop

glabel beh_jrb_sliding_box # 23A4
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    collision_data jrb_seg7_collision_floating_box
    unknown_2D
    begin_loop
        callnative BehJrbSlidingBox
        callnative load_object_collision_model
    end_loop

glabel beh_ship_part_3 # 23D0
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    unknown_2D
    begin_loop
        callnative BehShipPart3Loop
    end_loop

glabel beh_in_sunken_ship_3 # 23EC
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    collision_data jrb_seg7_collision_in_sunken_ship_3
    unknown_2D
    obj_set_float objCollisionDistance, 0x0FA0
    begin_loop
        callnative BehShipPart3Loop
        callnative load_object_collision_model
    end_loop

glabel beh_sunken_ship_part # 241C
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    scale 50
    unknown_2D
    begin_loop
        callnative BehSunkenShipPartLoop
    end_loop

glabel beh_unused_243C # 243C
    obj_set_int objFaceAnglePitch, 0xE958
    obj_set_int objFaceAngleYaw, 0xEE6C
    obj_set_int objFaceAngleRoll, 0x0C80
    return
glabel beh_sunken_ship_part_2 # 244C
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    scale 100
    obj_set_float objDrawingDistance, 0x1770
    unknown_2D
    call beh_unused_243C
    break

glabel beh_in_sunken_ship # 246C
    begin OBJ_LIST_SURFACE
    collision_data jrb_seg7_collision_in_sunken_ship
    goto .Lbeh_in_sunken_ship_248C
glabel beh_in_sunken_ship_2 # 2480
    begin OBJ_LIST_SURFACE
    collision_data jrb_seg7_collision_in_sunken_ship_2
.Lbeh_in_sunken_ship_248C: # 248C
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_set_float objCollisionDistance, 0x0FA0
    call beh_unused_243C
    begin_loop
        callnative load_object_collision_model
    end_loop

glabel beh_mario_dust_generator # 24AC
    begin OBJ_LIST_DEFAULT
    obj_bit_clear_int32 objUnkE0, 0x00000001
    unknown_35
    unknown_1C 0x0000008E, beh_white_puff1
    unknown_1C 0x00000096, beh_white_puff2
    delay 1
    deactivate

glabel beh_white_puff1 # 24DC
    begin OBJ_LIST_DEFAULT
    obj_bit_clear_int32 objUnkE0, 0x00000001
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    billboard
    begin_loop
        callnative BehWhitePuff1Loop
    end_loop

glabel beh_white_puff2 # 2500
    begin OBJ_LIST_UNIMPORTANT
    obj_or_int objFlags, (OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    billboard
    obj_set_int objAnimState, -1
    begin_repeat 7
        callnative BehWhitePuff2Loop
        obj_add_int objAnimState, 1
    end_repeat
    deactivate

glabel beh_white_puff_smoke2 # 2528
    begin OBJ_LIST_UNIMPORTANT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    billboard
    obj_set_int objAnimState, -1
    begin_repeat 7
        callnative BehWhitePuff2Loop
        callnative obj_move_using_fvel_and_gravity
        obj_add_int objAnimState, 1
    end_repeat
    deactivate

glabel beh_purple_switch_hidden_boxes # 2558
    begin OBJ_LIST_SURFACE
    obj_set_int objBehParams2ndByte, 2
    goto .Lbeh_floor_switch_1488
glabel beh_blue_coin_switch # 2568
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    collision_data blue_coin_switch_seg8_collision_08000E98
    begin_loop
        callnative BehBlueCoinSwitchLoop
    end_loop

glabel beh_hidden_blue_coin # 2588
    begin OBJ_LIST_LEVEL
    obj_set_int objInteractType, 0x10
    obj_or_int objFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    billboard
    set_hitbox 0x0064, 0x0040
    obj_set_int objDamageOrCoinValue, 0x0005
    obj_set_int objIntangibleTimer, 0
    obj_set_int objAnimState, -1
    begin_loop
        callnative BehHiddenBlueCoinsLoop
        obj_add_int objAnimState, 1
    end_loop

glabel beh_bob_hmc_cage_door # 25C0
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    begin_loop
        callnative BehBobHmcCageDoorLoop
        callnative load_object_collision_model
    end_loop

glabel beh_openable_grill # 25E0
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    begin_loop
        callnative BehOpenableGrillLoop
    end_loop

glabel beh_water_level_trigger # 25F8
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    set_hitbox 0x0046, 0x001E
    obj_set_float objCollisionDistance, 0x00C8
    obj_set_int objIntangibleTimer, 0
    begin_loop
        callnative BehWaterLevelTriggerLoop
    end_loop

glabel beh_initialize_water_level_trigger # 2620
    begin OBJ_LIST_DEFAULT
    begin_loop
        callnative BehInitWaterLevelTriggerLoop
    end_loop

glabel beh_tornado_sand_particle # 2634
    begin OBJ_LIST_UNIMPORTANT
    obj_or_int objFlags, (OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    billboard
    begin_loop
        callnative BehTweesterSandParticleLoop
    end_loop

glabel beh_tornado # 2650
    begin OBJ_LIST_POLELIKE
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_30 0x001E, 0xFE70, 0x0000, 0x0000, 0x0000, 0x00C8, 0x0000, 0x0000
    unknown_1E
    unknown_2D
    begin_loop
        callnative BehTweesterLoop
    end_loop

glabel beh_spawn_big_boo # 2684
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    begin_loop
        callnative BehSpawnBigBooLoop
    end_loop

glabel beh_animated_texture # 269C
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    unknown_30 0x001E, 0xFE70, 0xFFBA, 0x03E8, 0x03E8, 0x00C8, 0x0000, 0x0000
    billboard
    begin_loop
        callnative BehAnimatedTextureLoop
        obj_add_int objAnimState, 1
        unknown_34 objAnimState, 0x0002
    end_loop

glabel beh_boo_in_castle # 26D4
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_2D
    obj_set_float objGraphYOffset, 0x003C
    unknown_30 0x001E, 0x0000, 0xFFCE, 0x03E8, 0x03E8, 0x00C8, 0x0000, 0x0000
    callnative bhv_init_room
    begin_loop
        callnative BehBooInCastleLoop
    end_loop

glabel beh_boo_with_cage # 2710
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_2D
    obj_set_int objDamageOrCoinValue, 3
    unknown_2E 0x0050, 0x0078
    set_hitbox 0x00B4, 0x008C
    obj_set_float objGraphYOffset, 0x003C
    unknown_30 0x001E, 0x0000, 0xFFCE, 0x03E8, 0x03E8, 0x00C8, 0x0000, 0x0000
    callnative BehBooWithCageInit
    callnative bhv_init_room
    begin_loop
        callnative BehBooWithCageLoop
    end_loop

glabel beh_patrolling_boo # 2768
    begin OBJ_LIST_GENACTOR
    obj_set_int objBehParams2ndByte, 2
    obj_set_int objUnk1AC, 10
    goto .Lbeh_boo_2794
glabel beh_spawned_boo # 277C
    begin OBJ_LIST_GENACTOR
    obj_set_int objBehParams2ndByte, 1
    obj_set_int objUnk1AC, 10
    goto .Lbeh_boo_2794
glabel beh_boo_giving_star # 2790
    begin OBJ_LIST_GENACTOR
.Lbeh_boo_2794: # 2794
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_2D
    unknown_30 0x001E, 0x0000, 0xFFCE, 0x03E8, 0x03E8, 0x00C8, 0x0000, 0x0000
    callnative bhv_init_room
    callnative BehBooInit
    begin_loop
        callnative BehBooGivingStarLoop
    end_loop

glabel beh_boo_group # 27D0
    begin OBJ_LIST_DEFAULT
    unknown_35
    callnative BehBooGroupInit
    deactivate

glabel beh_boo_3 # 27E4
    begin OBJ_LIST_GENACTOR
    obj_set_int objBehParams2ndByte, 1
    goto .Lbeh_boo_2808
glabel beh_spawned_boo_2 # 27F4
    begin OBJ_LIST_GENACTOR
    obj_set_int objBehParams2ndByte, 2
    goto .Lbeh_boo_2808
glabel beh_boo_2 # 2804
    begin OBJ_LIST_GENACTOR
.Lbeh_boo_2808: # 2808
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int objIntangibleTimer, 0
    unknown_2D
    obj_set_int objDamageOrCoinValue, 2
    set_hitbox 0x008C, 0x0050
    unknown_2E 0x0028, 0x003C
    obj_set_float objGraphYOffset, 30
    callnative bhv_init_room
    unknown_1C 0x00000074, beh_coin_inside_boo
    unknown_30 0x001E, 0x0000, 0xFFCE, 0x03E8, 0x03E8, 0x00C8, 0x0000, 0x0000
    callnative BehBooInit
    begin_loop
        callnative BehBooLoop
    end_loop

glabel beh_hidden_staircase_step # 286C
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    collision_data bbh_seg7_collision_staircase_step
    obj_set_int objRoom, 0x0001
    obj_set_float objCollisionDistance, 0x03E8
    unknown_2D
    begin_loop
        callnative load_object_collision_model
    end_loop

glabel beh_boo_boss_spawned_bridge # 2898
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    collision_data bbh_seg7_collision_staircase_step
    obj_set_int objRoom, 0x0001
    obj_set_float objCollisionDistance, 0x03E8
    unknown_2D
    begin_loop
        callnative BehBooBossSpawnedBridgeLoop
        callnative load_object_collision_model
    end_loop

glabel beh_bbh_tilt_floor_platforms # 28CC
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    collision_data bbh_seg7_collision_tilt_floor_platform
    unknown_2D
    obj_set_int objRoom, 0x0002
    begin_loop
        callnative BehBbhTiltFloorPlatformLoop
        callnative load_object_collision_model
    end_loop

glabel beh_tumbling_bookshelf # 28FC
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    collision_data bbh_seg7_collision_tumbling_bookshelf
    unknown_2D
    obj_set_int objRoom, 0x0006
    begin_loop
        callnative BehTumblingBookshelfLoop
        callnative load_object_collision_model
    end_loop

glabel beh_mesh_elevator # 292C
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    collision_data bbh_seg7_collision_mesh_elevator
    unknown_2D
    obj_set_int objRoom, 0x000C
    obj_set_int objBehParams2ndByte, 0x0004
    callnative BehElevatorInit
    begin_loop
        callnative BehElevatorLoop
        callnative load_object_collision_model
    end_loop

glabel beh_rotating_merry_go_round # 2968
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    collision_data bbh_seg7_collision_rotating_merry_go_round
    obj_set_float objCollisionDistance, 0x07D0
    obj_set_int objRoom, 0x000A
    begin_loop
        callnative BehRotatingMerryGoRoundLoop
        callnative load_object_collision_model
    end_loop

.ifdef VERSION_US
glabel beh_plays_music_track_when_touched # 2998
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    begin_loop
        callnative BehPlayMusicTrackWhenTouchedLoop
    end_loop
.endif

glabel beh_inside_cannon # 2998
    break

glabel beh_bait_coin # 299C
    begin OBJ_LIST_DESTRUCTIVE
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    billboard
    unknown_2D
    set_hitbox 0x0064, 0x012C
    obj_set_int objIntangibleTimer, 0
    begin_loop
        obj_add_int objAnimState, 1
        callnative BehInsideCannonLoop
    end_loop

glabel beh_static_checkered_platform # 29CC
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    collision_data checkerboard_platform_seg8_collision_0800D710
    unknown_2D
    begin_loop
        callnative BehStaticCheckeredPlatformLoop
        callnative load_object_collision_model
    end_loop

glabel beh_unused_2A10 # 29F8
    begin OBJ_LIST_DEFAULT
    billboard
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    break

glabel beh_star # 2A08
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    begin_loop
        obj_add_int objFaceAnglePitch, 256
        obj_add_int objFaceAngleYaw, 256
    end_loop

# What is this?
    break
    break
    break
    break

glabel beh_static_object # 2A30
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    break

glabel beh_unused_2A54 # 2A3C
    begin OBJ_LIST_DEFAULT
    break

glabel beh_castle_floor_trap # 2A44
    begin OBJ_LIST_DEFAULT
    unknown_35
    callnative BehCastleFloorTrapInit
    begin_loop
        callnative BehCastleFloorTrapLoop
    end_loop

glabel beh_floor_trap_in_castle # 2A64
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    collision_data inside_castle_seg7_collision_floor_trap
    begin_loop
        callnative BehFloorTrapInCastleLoop
        callnative load_object_collision_model
    end_loop

glabel beh_tree # 2A8C
    begin OBJ_LIST_POLELIKE
    billboard
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_set_int objInteractType, 0x40
    set_hitbox 0x0050, 0x01F4
    obj_set_int objIntangibleTimer, 0
    begin_loop
        callnative BehClimbDetectLoop
    end_loop

glabel beh_powerup_sparkles1 # 2AB8
    begin OBJ_LIST_UNIMPORTANT
    billboard
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_set_int objAnimState, -1
    begin_repeat 9
        obj_add_int objAnimState, 1
    end_repeat
    deactivate

glabel beh_powerup_sparkles2 # 2AD8
    begin OBJ_LIST_UNIMPORTANT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    begin_loop
        callnative BehPowerupSparklesLoop
    end_loop

glabel beh_special_triple_jump_sparkles # 2AF0
    begin OBJ_LIST_DEFAULT
    obj_bit_clear_int32 objUnkE0, 0x00000008
glabel beh_some_gfx # 2AFC
    begin OBJ_LIST_UNIMPORTANT
    billboard
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_set_float objGraphYOffset, 25
    obj_set_float_rand objVarF4, 0xFFCE, 0x0064
    obj_sum_float objPosX, objPosX, objVarF4
    obj_set_float_rand objVarF4, 0xFFCE, 0x0064
    obj_sum_float objPosZ, objPosZ, objVarF4
    obj_set_float_rand objVarF4, 0xFFCE, 0x0064
    obj_sum_float objPosY, objPosY, objVarF4
    obj_set_int objAnimState, -1
    begin_repeat 12
        obj_add_int objAnimState, 1
    end_repeat
    deactivate

glabel beh_scuttlebug # 2B44
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int32 objAnimations, scuttlebug_seg6_anims_06015064
    unknown_28 0x00
    unknown_30 0x0050, 0xFE70, 0xFFCE, 0x0000, 0x0000, 0x00C8, 0x0000, 0x0000
    unknown_2D
    callnative bhv_init_room
    begin_loop
        callnative BehScuttlebugLoop
    end_loop

glabel beh_scuttlebug_spawn # 2B88
    begin OBJ_LIST_SPAWNER
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    begin_loop
        callnative BehScuttlebugSpawnLoop
    end_loop

glabel beh_whomp_king_boss # 2BA0
    begin OBJ_LIST_SURFACE
    obj_set_int objBehParams2ndByte, 1
    obj_set_int objHealth, 0x0003
    goto .Lbeh_whomp_2BD4
glabel beh_small_whomp # 2BB4
    begin OBJ_LIST_SURFACE
    obj_set_int objNumLootCoins, 5
.Lbeh_whomp_2BD4: # 2BBC
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int32 objAnimations, whomp_seg6_anims_06020A04
    collision_data whomp_seg6_collision_06020A0C
    unknown_28 0x00
    unknown_30 0x0000, 0xFE70, 0xFFCE, 0x0000, 0x0000, 0x00C8, 0x0000, 0x0000
    unknown_2D
    begin_loop
        callnative BehWhompLoop
    end_loop

glabel beh_water_splash # 2BFC
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    billboard
    obj_set_int objAnimState, -1
    begin_repeat 3
        obj_add_int objAnimState, 1
        callnative BehWaterSplashLoop
        delay 1
        callnative BehWaterSplashLoop
    end_repeat
    begin_repeat 5
        obj_add_int objAnimState, 1
        delay 1
    end_repeat
    obj_bit_clear_int32 objUnkE0, 0x00000040
    deactivate

glabel beh_water_drops # 2C48
    begin OBJ_LIST_UNIMPORTANT
    obj_or_int objFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    billboard
    begin_loop
        callnative BehWaterDropsLoop
    end_loop

glabel beh_water_surface_white_wave # 2C64
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
.ifdef VERSION_US
    obj_set_int objFaceAnglePitch, 0
    obj_set_int objFaceAngleYaw, 0
    obj_set_int objFaceAngleRoll, 0
.endif
    callnative BehWaterSurfaceWhiteWaveInit
    obj_add_float objPosY, 5
    obj_set_int objAnimState, -1
    begin_repeat 6
        obj_add_int objAnimState, 1
    end_repeat
    deactivate

glabel beh_object_bubble_ripples # 2C8C
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
.ifdef VERSION_JP
    obj_set_float objFaceAnglePitch, 0
    obj_set_float objFaceAngleYaw, 0
    obj_set_float objFaceAngleRoll, 0
.endif
.ifdef VERSION_US
    obj_set_int objFaceAnglePitch, 0
    obj_set_int objFaceAngleYaw, 0
    obj_set_int objFaceAngleRoll, 0
.endif
    obj_set_int objAnimState, -1
    callnative BehObjectBubbleRipplesInit
    begin_repeat 6
        obj_add_int objAnimState, 1
    end_repeat
    deactivate

glabel beh_surface_waves # 2CBC
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
.ifdef VERSION_JP
    obj_set_float objFaceAnglePitch, 0
    obj_set_float objFaceAngleYaw, 0
    obj_set_float objFaceAngleRoll, 0
.endif
.ifdef VERSION_US
    obj_set_int objFaceAnglePitch, 0
    obj_set_int objFaceAngleYaw, 0
    obj_set_int objFaceAngleRoll, 0
.endif
    obj_set_int objAnimState, -1
    obj_add_int objAnimState, 1
    begin_loop
        callnative BehSurfaceWavesLoop
        obj_add_int objAnimState, 1
        begin_repeat 6
            callnative BehSurfaceWavesLoop
        end_repeat
        callnative BehSurfaceWavesLoop
    end_loop

glabel beh_water_surface_white_wave_2 # 2D04
    begin OBJ_LIST_UNIMPORTANT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
.ifdef VERSION_JP
    obj_set_float objFaceAnglePitch, 0
    obj_set_float objFaceAngleYaw, 0
    obj_set_float objFaceAngleRoll, 0
.endif
.ifdef VERSION_US
    obj_set_int objFaceAnglePitch, 0
    obj_set_int objFaceAngleYaw, 0
    obj_set_int objFaceAngleRoll, 0
.endif
    obj_set_int objAnimState, -1
    begin_repeat 6
        obj_add_int objAnimState, 1
    end_repeat
    deactivate

glabel beh_waves_generator # 2D2C
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    unknown_35
    begin_repeat 5
        unknown_37 D_8032FE18
    end_repeat_nobreak
    delay 1
    obj_bit_clear_int32 objUnkE0, 0x00000100
    deactivate

glabel beh_surface_wave_shrinking # 2D58
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    unknown_35
    begin_repeat 18
        unknown_37 D_8032FDD0
    end_repeat_nobreak
    callnative BehSurfaceWaveShrinkingInit
    delay 1
    obj_bit_clear_int32 objUnkE0, 0x00001000
    deactivate

glabel beh_water_type # 2D8C
    begin OBJ_LIST_UNIMPORTANT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    goto .Lbeh_wave_trail_2DD0
glabel beh_wave_trail_on_surface # 2D9C
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_bit_clear_int32 objUnkE0, 0x00000400
.Lbeh_wave_trail_2DD0: # 2DAC
    obj_set_float objFaceAnglePitch, 0
    obj_set_float objFaceAngleYaw, 0
    obj_set_float objFaceAngleRoll, 0
    obj_set_int objAnimState, -1
    begin_repeat 8
        obj_add_int objAnimState, 1
        callnative BehWaveTrailLoop
        delay 1
        callnative BehWaveTrailLoop
    end_repeat
    deactivate

glabel beh_tiny_white_wind_particle # 2DE0
    begin OBJ_LIST_UNIMPORTANT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    billboard
    begin_loop
        callnative BehWhiteWindParticleLoop
    end_loop

glabel beh_wind_particle # 2DFC
    begin OBJ_LIST_POLELIKE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    billboard
    begin_loop
        callnative BehWhiteWindParticleLoop
    end_loop

glabel beh_snowman_wind_blowing # 2E18
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_2D
    begin_loop
        callnative BehSnowmanWindBlowingLoop
    end_loop

glabel beh_walking_penguin # 2E34
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    collision_data penguin_seg5_collision_05008B88
    obj_set_int32 objAnimations, penguin_seg5_anims_05008B74
    unknown_28 0x00
    unknown_30 0x0000, 0xFE70, 0xFFCE, 0x0000, 0x0000, 0x00C8, 0x0000, 0x0000
    scale 600
    unknown_2D
    begin_loop
        callnative BehWalkingPenguinLoop
        callnative load_object_collision_model
    end_loop

glabel beh_yellow_ball # 2E84
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    billboard
    break

    .align 4
glabel beh_mario # 2EA0
    begin OBJ_LIST_PLAYER
    obj_set_int objIntangibleTimer, 0
    obj_or_int objFlags, OBJ_FLAG_0100
    obj_or_int objUnk94, 0x0001
    set_hitbox 0x0025, 0x00A0
    begin_loop
        callnative try_print_debug_mario_level_info
        callnative BehMarioLoop2
        callnative try_do_mario_debug_object_spawn
    end_loop

glabel beh_toad_message # 2ED8
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_4000 | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int32 objAnimations, toad_seg6_anims_0600FB58
    unknown_28 0x06
    interact_type 0x00800000
    set_hitbox 0x0050, 0x0064
    obj_set_int objIntangibleTimer, 0
    callnative bhv_init_room
    callnative beh_toad_message_init
    begin_loop
        callnative beh_toad_message_loop
    end_loop

glabel beh_unlock_door_star # 2F20
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    callnative beh_unlock_door_star_init
    begin_loop
        callnative beh_unlock_door_star_loop
    end_loop

glabel beh_warps_60 # 2F40
    break
glabel beh_warps_64 # 2F44
    break
glabel beh_warps_68 # 2F48
    break
glabel beh_warps_6C # 2F4C
    break
glabel beh_warps_70 # 2F50
    break
glabel beh_warps_74 # 2F54
    break
glabel beh_warps_78 # 2F58
    break
glabel beh_warps_7C # 2F5C
    break
glabel beh_warps_80 # 2F60
    break
glabel beh_warps_84 # 2F64
    break
glabel beh_warps_88 # 2F68
    break
glabel beh_warps_8C # 2F6C
    break
glabel beh_warps_90 # 2F70
    break
glabel beh_warps_94 # 2F74
    break

    .align 4
glabel beh_random_animated_texture # 2F80
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_set_float objGraphYOffset, 0xFFF0
    billboard
    obj_set_int objAnimState, -1
    begin_loop
        obj_add_int objAnimState, 1
    end_loop

glabel beh_yellow_background_in_menu # 2FA0
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    callnative beh_yellow_background_menu_init
    begin_loop
        obj_set_int objIntangibleTimer, 0
        callnative beh_yellow_background_menu_loop
    end_loop

glabel beh_menu_button # 2FC4
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    callnative beh_menu_button_init
    begin_loop
        obj_set_int objIntangibleTimer, 0
        callnative beh_menu_button_loop
    end_loop

glabel beh_menu_button_manager # 2FE8
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, (OBJ_FLAG_0800 | OBJ_FLAG_0020 | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    callnative beh_menu_button_manager_init
    begin_loop
        obj_set_int objIntangibleTimer, 0
        callnative beh_menu_button_manager_loop
    end_loop

glabel beh_star_in_act_selector # 300C
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    unknown_2D
    begin_loop
        callnative BehStarActSelectorLoop
    end_loop

glabel beh_act_selector # 3028
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    callnative BehActSelectorInit
    begin_loop
        callnative BehActSelectorLoop
    end_loop

glabel beh_moving_yellow_coin # 3048
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    billboard
    set_hitbox 0x0064, 0x0040
    obj_set_int objInteractType, 0x10
    obj_set_int objIntangibleTimer, 0
    obj_set_int objAnimState, -1
    callnative BehMovingYellowCoinInit
    begin_loop
        callnative BehMovingYellowCoinLoop
        obj_add_int objAnimState, 1
    end_loop

glabel beh_moving_blue_coin # 3084
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    billboard
    obj_set_int objIntangibleTimer, 0
    obj_set_int objAnimState, -1
    callnative BehMovingBlueCoinInit
    begin_loop
        callnative BehMovingBlueCoinLoop
        obj_add_int objAnimState, 1
    end_loop

glabel beh_blue_coin_sliding # 30B4
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    billboard
    obj_set_int objIntangibleTimer, 0
    obj_set_int objAnimState, -1
    callnative BehBlueCoinSlidingJumpingInit
    begin_loop
        callnative BehBlueCoinSlidingLoop
        obj_add_int objAnimState, 1
    end_loop

glabel beh_blue_coin_jumping # 30E4
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    billboard
    obj_set_int objIntangibleTimer, 0
    obj_set_int objAnimState, -1
    callnative BehBlueCoinSlidingJumpingInit
    begin_loop
        callnative BehBlueCoinJumpingLoop
        obj_add_int objAnimState, 1
    end_loop

glabel beh_seaweed # 3114
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_set_int32 objAnimations, seaweed_seg6_anims_0600A4D4
    unknown_28 0x00
    callnative BehSeaweedInit
    begin_loop
    end_loop

glabel beh_seaweed_bundle # 3138
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    unknown_1E
    callnative BehSeaweedBundleInit
    begin_loop
    end_loop

glabel beh_bobomb # 3154
    begin OBJ_LIST_DESTRUCTIVE
    obj_or_int objFlags, (OBJ_FLAG_4000 | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_HOLDABLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int32 objAnimations, bobomb_seg8_anims_0802396C
    unknown_1E
    unknown_28 0x00
    obj_set_int objIntangibleTimer, 0
    unknown_2D
    callnative BehBobombInit
    begin_loop
        callnative BehBobombLoop
    end_loop

glabel beh_bobomb_fuse_smoke # 318C
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    billboard
    obj_set_int objAnimState, -1
    callnative BehBobombFuseSmokeInit
    delay 1
    begin_loop
        callnative BehDustSmokeLoop
        obj_add_int objAnimState, 1
    end_loop

glabel beh_bobomb_buddy_advice_role # 31BC
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_HOLDABLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int32 objAnimations, bobomb_seg8_anims_0802396C
    interact_type 0x00800000
    unknown_1E
    set_hitbox 0x0064, 0x003C
    unknown_28 0x00
    obj_set_int objVarFC, 0x0000
    unknown_2D
    callnative BehBobombBuddyInit
    begin_loop
        obj_set_int objIntangibleTimer, 0
        callnative BehBobombBuddyLoop
    end_loop

glabel beh_bobomb_buddy_cannon_role # 3208
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_4000 | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_HOLDABLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int32 objAnimations, bobomb_seg8_anims_0802396C
    interact_type 0x00800000
    unknown_1E
    set_hitbox 0x0064, 0x003C
    unknown_28 0x00
    obj_set_int objVarFC, 0x0001
    unknown_2D
    callnative BehBobombBuddyInit
    begin_loop
        obj_set_int objIntangibleTimer, 0
        callnative BehBobombBuddyLoop
    end_loop

glabel beh_cannon_trap_door # 3254
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_4000 | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    collision_data cannon_lid_seg8_collision_08004950
    unknown_2D
    callnative BehCannonTrapDoorInit
    begin_loop
        callnative BehCannonTrapDoorLoop
        callnative load_object_collision_model
    end_loop

glabel beh_whirlpool # 3288
    begin OBJ_LIST_POLELIKE
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    callnative BehWhirlpoolInit
    begin_loop
        callnative BehWhirlpoolLoop
    end_loop

glabel beh_jet_stream # 32A8
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    begin_loop
        callnative BehJetStreamLoop
    end_loop

glabel beh_message_panel # 32C0
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    collision_data wooden_signpost_seg3_collision_0302DD80
    interact_type 0x00800000
    obj_set_int objUnk190, 0x1000
    unknown_1E
    set_hitbox 0x0096, 0x0050
    obj_set_int objVarF4, 0
    begin_loop
        obj_set_int objIntangibleTimer, 0
        callnative load_object_collision_model
        obj_set_int objInteractStatus, 0
    end_loop

glabel beh_sign_on_wall # 3304
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    interact_type 0x00800000
    obj_set_int objUnk190, 0x1000
    set_hitbox 0x0096, 0x0050
    obj_set_int objVarF4, 0
    begin_loop
        obj_set_int objIntangibleTimer, 0
        obj_set_int objInteractStatus, 0
    end_loop

glabel beh_amp_homing # 3334
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int32 objAnimations, amp_seg8_anims_08004034
    unknown_28 0x00
    obj_set_float objGraphYOffset, 0x0028
    obj_set_int objIntangibleTimer, 0
    callnative BehAmpHomingInit
    begin_loop
        callnative BehAmpHomingLoop
    end_loop

glabel beh_amp # 3368
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int32 objAnimations, amp_seg8_anims_08004034
    unknown_28 0x00
    obj_set_float objGraphYOffset, 0x0028
    obj_set_int objIntangibleTimer, 0
    callnative BehAmpInit
    begin_loop
        callnative BehAmpLoop
    end_loop

glabel beh_butterfly # 339C
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int32 objAnimations, butterfly_seg3_anims_030056B0
    unknown_1E
    obj_set_float objGraphYOffset, 0x0005
    callnative BehButterflyInit
    begin_loop
        callnative BehButterflyLoop
    end_loop

glabel beh_hoot # 33CC
    begin OBJ_LIST_POLELIKE
    obj_or_int objFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int32 objAnimations, hoot_seg5_anims_05005768
    obj_set_int objInteractType, 0x01
    set_hitbox 0x004B, 0x004B
    callnative BehHootInit
    begin_loop
        callnative BehHootLoop
    end_loop

glabel beh_beta_green_shell # 3400
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_HOLDABLE | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int objInteractType, 0x02
    unknown_1E
    set_hitbox 0x0028, 0x0032
    callnative BehBetaGreenShellInit
    begin_loop
        obj_set_int objIntangibleTimer, 0
        callnative BehBetaGreenShellLoop
    end_loop

glabel beh_carry_something1 # 3434
    begin OBJ_LIST_DEFAULT
    break
glabel beh_carry_something2 # 343C
    begin OBJ_LIST_DEFAULT
    break
glabel beh_carry_something3 # 3444
    begin OBJ_LIST_DEFAULT
    break
glabel beh_carry_something4 # 344C
    begin OBJ_LIST_DEFAULT
    break
glabel beh_carry_something5 # 3454
    begin OBJ_LIST_DEFAULT
    break
glabel beh_carry_something6 # 345C
    begin OBJ_LIST_DEFAULT
    break

glabel beh_object_bubble # 3464
    begin OBJ_LIST_UNIMPORTANT
    obj_or_int objFlags, (OBJ_FLAG_MOVE_Y_WITH_TERMINAL_VEL | OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    billboard
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_set_int objAnimState, -1
    callnative BehObjectBubbleInit
    obj_set_float_rand objVelY, 0x0003, 0x0006
    obj_set_int_rand_rshift objMoveAngleYaw, 0x0000, 0x0000
    delay 1
    begin_loop
        callnative BehObjectBubbleLoop
    end_loop

glabel beh_object_water_wave # 34A4
    begin OBJ_LIST_UNIMPORTANT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_set_float objFaceAnglePitch, 0
    obj_set_float objFaceAngleYaw, 0
    obj_set_float objFaceAngleRoll, 0
    obj_set_int objAnimState, -1
    callnative BehObjectWaterWaveInit
    obj_add_int objAnimState, 1
    delay 6
    begin_loop
        callnative BehObjectWaterWaveLoop
        obj_add_int objAnimState, 1
    begin_repeat 6
        callnative BehObjectWaterWaveLoop
    end_repeat
    end_loop

glabel beh_explosion # 34F0
    begin OBJ_LIST_DESTRUCTIVE
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    billboard
    interact_type 0x00000008
    obj_set_int objDamageOrCoinValue, 2
    obj_set_int objIntangibleTimer, 0
    unknown_2B 0x0096, 0x0096, 0x0096
    obj_set_int objAnimState, -1
    callnative BehExplosionInit
    begin_loop
        callnative BehExplosionLoop
        obj_add_int objAnimState, 1
    end_loop

glabel beh_bobomb_bully_death_smoke # 3538
    begin OBJ_LIST_UNIMPORTANT
    obj_or_int objFlags, (OBJ_FLAG_MOVE_Y_WITH_TERMINAL_VEL | OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    billboard
    obj_set_int objAnimState, -1
    callnative BehBobombBullyDeathSmokeInit
    delay 1
    begin_loop
        callnative BehDustSmokeLoop
        obj_add_int objAnimState, 1
    end_loop

glabel beh_smoke # 3568
    begin OBJ_LIST_UNIMPORTANT
    obj_or_int objFlags, (OBJ_FLAG_MOVE_Y_WITH_TERMINAL_VEL | OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    billboard
    obj_set_int objAnimState, -1
    delay 1
    begin_loop
        callnative BehDustSmokeLoop
        obj_add_int objAnimState, 1
    end_loop

glabel beh_bobomb_explosion_bubble # 3590
    begin OBJ_LIST_DEFAULT
    billboard
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    callnative BehBobombExplosionBubbleInit
    obj_add_float_rand objPosX, -50, 100
    obj_add_float_rand objPosY, -50, 100
    obj_add_float_rand objPosZ, -50, 100
    call beh_bobomb_explosion_bubble_3600
    delay 1
    begin_loop
        call beh_bobomb_explosion_bubble_3600
        callnative BehBobombExplosionBubbleLoop
    end_loop

glabel beh_bobomb_explosion_bubble_3600 # 35E0
    obj_add_float_rand objPosX, -2, 4
    obj_add_float_rand objPosZ, -2, 4
    return

glabel beh_bobomb_cork_box_respawner # 35F4
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    begin_loop
        callnative BehBobombCorkBoxRespawnerLoop
    end_loop

glabel beh_small_bully # 360C
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int32 objAnimations, bully_seg5_anims_0500470C
    unknown_1E
    unknown_2D
    callnative BehSmallBullyInit
    begin_loop
        obj_set_int objIntangibleTimer, 0
        callnative BehBullyLoop
    end_loop

glabel beh_big_bully # 3640
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int32 objAnimations, bully_seg5_anims_0500470C
    unknown_1E
    unknown_2D
    callnative BehBigBullyInit
    begin_loop
        obj_set_int objIntangibleTimer, 0
        callnative BehBullyLoop
    end_loop

glabel beh_big_bully_with_minions # 3674
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int32 objAnimations, bully_seg5_anims_0500470C
    unknown_2D
    callnative BehBigBullyInit
    callnative BehBigBullyWithMinionsInit
    begin_loop
        callnative BehBigBullyWithMinionsLoop
    end_loop

glabel beh_small_chill_bully # 36A8
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int32 objAnimations, chilly_chief_seg6_anims_06003994
    unknown_1E
    unknown_2D
    obj_set_int objVarF4, 0x0010
    callnative BehSmallBullyInit
    begin_loop
        obj_set_int objIntangibleTimer, 0
        callnative BehBullyLoop
    end_loop

glabel beh_big_chill_bully # 36E0
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int32 objAnimations, chilly_chief_seg6_anims_06003994
    unknown_1E
    unknown_2D
    obj_set_int objVarF4, 0x0010
    callnative BehBigBullyInit
    begin_loop
        obj_set_int objIntangibleTimer, 0
        callnative BehBullyLoop
    end_loop

glabel beh_jet_stream_ring_spawner # 3718
    begin OBJ_LIST_DEFAULT
    unhide
    begin_loop
        callnative BehJetStreamRingSpawnerLoop
    end_loop

glabel beh_jet_stream_water_ring # 3730
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_set_int32 objAnimations, water_ring_seg6_anims_06013F7C
    unknown_2B 0x004B, 0x0014, 0x0014
    interact_type 0x00010000
    obj_set_int objDamageOrCoinValue, 2
    obj_set_int objIntangibleTimer, 0
    callnative BehJetStreamWaterRingInit
    begin_loop
        obj_set_int objIntangibleTimer, 0
        callnative BehJetStreamWaterRingLoop
    end_loop

glabel beh_manta_ray_water_ring # 3778
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_set_int32 objAnimations, water_ring_seg6_anims_06013F7C
    unknown_2B 0x004B, 0x0014, 0x0014
    interact_type 0x00010000
    obj_set_int objDamageOrCoinValue, 2
    obj_set_int objIntangibleTimer, 0
    callnative BehMantaRayWaterRingInit
    begin_loop
        obj_set_int objIntangibleTimer, 0
        callnative BehMantaRayWaterRingLoop
    end_loop

glabel beh_manta_ray_ring_manager # 37C0
    begin OBJ_LIST_DEFAULT
    begin_loop
    end_loop

glabel beh_bowser_mine # 37CC
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_set_int objIntangibleTimer, 0
    unknown_2B 0x0028, 0x0028, 0x0028
    delay 1
    begin_loop
        obj_set_int objIntangibleTimer, 0
        callnative BehBowserMineLoop
    end_loop

glabel beh_bowser_mine_explosion # 37FC
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    billboard
    obj_set_float objGraphYOffset, 0xFEE0
    obj_set_int objAnimState, -1
    begin_loop
        callnative BehBowserMineExplosionLoop
    end_loop

glabel beh_bowser_mine_smoke # 3820
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    billboard
    obj_set_float objGraphYOffset, 0xFEE0
    obj_set_int objOpacity, 0x00FF
    obj_set_int objAnimState, -1
    begin_loop
        callnative BehBowserMineSmokeLoop
    end_loop

glabel beh_celebration_star # 3848
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    callnative BehCelebrationStarInit
    begin_loop
        callnative BehCelebrationStarLoop
    end_loop

glabel beh_celebration_star_sparkle # 3868
    begin OBJ_LIST_UNIMPORTANT
    billboard
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_set_float objGraphYOffset, 25
    obj_set_int objAnimState, -1
    begin_loop
        obj_add_int objAnimState, 1
        callnative BehCelebrationStarSparkleLoop
    end_loop

glabel beh_star_key_collection_puff_spawner # 3890
    begin OBJ_LIST_DEFAULT
    billboard
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_set_int objAnimState, -1
    begin_loop
        callnative BehStarKeyCollectionPuffSpawnerLoop
    end_loop

glabel beh_lll_drawbridge_spawner # 38B0
    begin OBJ_LIST_DEFAULT
    unhide
    begin_loop
        callnative BehLLLDrawbridgeSpawnerLoop
    end_loop

glabel beh_lll_drawbridge # 38C8
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    collision_data lll_seg7_collision_drawbridge
    begin_loop
        callnative BehLLLDrawbridgeLoop
        callnative load_object_collision_model
    end_loop

glabel beh_small_bomp # 38F0
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    collision_data wf_seg7_collision_small_bomp
    callnative BehSmallBompInit
    begin_loop
        callnative BehSmallBompLoop
        callnative load_object_collision_model
    end_loop

glabel beh_large_bomp # 3920
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    collision_data wf_seg7_collision_large_bomp
    callnative BehLargeBompInit
    begin_loop
        callnative BehLargeBompLoop
        callnative load_object_collision_model
    end_loop

glabel beh_wf_sliding_brick_platform # 3950
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    collision_data wf_seg7_collision_sliding_brick_platform
    callnative BehWFSlidingBrickPlatformInit
    begin_loop
        callnative BehWFSlidingBrickPlatformLoop
        callnative load_object_collision_model
    end_loop

glabel beh_moneybag # 3980
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int32 objAnimations, moneybag_seg6_anims_06005E5C
    unknown_1E
    unknown_2D
    obj_set_int objIntangibleTimer, -1
    callnative BehMoneybagInit
    begin_loop
        callnative BehMoneybagLoop
    end_loop

glabel beh_fake_moneybag_coin # 39B4
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_set_float objGraphYOffset, 0x001B
    billboard
    set_hitbox 0x006E, 0x0064
    obj_set_int objIntangibleTimer, 0
    obj_set_int objAnimState, -1
    begin_loop
        obj_add_int objAnimState, 1
        callnative BehFakeMoneybagCoinLoop
    end_loop

glabel beh_bob_pit_bowling_ball # 39E8
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    billboard
    obj_set_float objGraphYOffset, 130
    callnative BehBOBPitBowlingBallInit
    begin_loop
        callnative BehBOBPitBowlingBallLoop
    end_loop

glabel beh_free_bowling_ball # 3A10
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    billboard
    obj_set_float objGraphYOffset, 130
    callnative BehFreeBowlingBallInit
    begin_loop
        callnative BehFreeBowlingBallLoop
    end_loop

glabel beh_bowling_ball # 3A38
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    billboard
    obj_set_float objGraphYOffset, 130
    callnative BehBowlingBallInit
    begin_loop
        callnative BehBowlingBallLoop
    end_loop

glabel beh_ttm_bowling_ball_spawner # 3A60
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_set_int objVarFC, 0x003F
    callnative BehGenericBowlingBallSpawnerInit
    begin_loop
        callnative BehGenericBowlingBallSpawnerLoop
    end_loop

glabel beh_bob_bowling_ball_spawner # 3A84
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_set_int objVarFC, 0x007F
    callnative BehGenericBowlingBallSpawnerInit
    begin_loop
        callnative BehGenericBowlingBallSpawnerLoop
    end_loop

glabel beh_thi_bowling_ball_spawner # 3AA8
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    begin_loop
        callnative BehTHIBowlingBallSpawnerLoop
    end_loop

glabel beh_rr_cruiser_wing # 3AC0
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    callnative BehRRCruiserWingInit
    begin_loop
        callnative BehRRCruiserWingLoop
    end_loop

glabel beh_spindel # 3AE0
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_0010 | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    collision_data ssl_seg7_collision_spindel
    callnative BehSpindelInit
    begin_loop
        callnative BehSpindelLoop
        callnative load_object_collision_model
    end_loop

glabel beh_moving_up_and_down # 3B10
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_0010 | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    collision_data ssl_seg7_collision_0702808C
    callnative BehMovingUpAndDownInit
    begin_loop
        callnative BehMovingUpAndDownLoop
        callnative load_object_collision_model
    end_loop

glabel beh_pyramid_elevator # 3B40
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    collision_data ssl_seg7_collision_pyramid_elevator
    unknown_2D
    obj_set_float objCollisionDistance, 0x4E20
    callnative BehPyramidElevatorInit
    begin_loop
        callnative BehPyramidElevatorLoop
        callnative load_object_collision_model
    end_loop

glabel beh_pyramid_elevator_metal_balls # 3B78
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    billboard
    begin_loop
        callnative BehPyramidElevatorMetalBallsLoop
    end_loop

glabel beh_pyramid_top # 3B94
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    collision_data ssl_seg7_collision_pyramid_top
    unknown_2D
    obj_set_float objCollisionDistance, 0x4E20
    callnative BehPyramidTopInit
    begin_loop
        callnative BehPyramidTopLoop
        callnative load_object_collision_model
    end_loop

glabel beh_pyramid_top_explosion # 3BCC
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    callnative BehPyramidTopExplosionInit
    begin_loop
        callnative BehPyramidTopExplosionLoop
    end_loop

glabel beh_collision_box_subbehavior # 3BEC
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    set_hitbox 0x0032, 0x0032
    obj_set_int objIntangibleTimer, 0
    begin_loop
        callnative BehCollisionBoxSubBehaviorLoop
    end_loop

glabel beh_waterfall_sound_loop # 3C10
    begin OBJ_LIST_DEFAULT
    begin_loop
        callnative BehWaterfallSoundLoop
    end_loop

glabel beh_volcano_sound_loop # 3C24
    begin OBJ_LIST_DEFAULT
    begin_loop
        callnative BehVolcanoSoundLoop
    end_loop

glabel beh_castle_flag_waving # 3C38
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_set_int32 objAnimations, castle_grounds_seg7_anim_flags
    unknown_28 0x00
    callnative BehCastleFlagWavingInit
    begin_loop
    end_loop

glabel beh_birds_sound_loop # 3C5C
    begin OBJ_LIST_DEFAULT
    begin_loop
        callnative BehBirdsSoundLoop
    end_loop

glabel beh_ambiant_sounds # 3C70
    begin OBJ_LIST_DEFAULT
    callnative BehAmbiantSoundsInit
    begin_loop
    end_loop

glabel beh_sand_sound_loop # 3C84
    begin OBJ_LIST_DEFAULT
    begin_loop
        callnative BehSandSoundLoop
    end_loop

glabel beh_hidden_at_120_stars # 3C98
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    collision_data castle_grounds_seg7_collision_cannon_grill
    obj_set_float objCollisionDistance, 0x0FA0
    callnative BehHiddenAt120StarsInit
    begin_loop
        callnative load_object_collision_model
    end_loop

glabel beh_snowmans_bottom # 3CC4
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_1E
    obj_set_int objIntangibleTimer, 0
    callnative BehSnowmansBottomInit
    begin_loop
        callnative BehSnowmansBottomLoop
    end_loop

glabel beh_snowmans_head # 3CEC
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_1E
    obj_set_float objGraphYOffset, 0x006E
    callnative BehSnowmansHeadInit
    begin_loop
        callnative BehSnowmansHeadLoop
    end_loop

glabel beh_snowmans_body_checkpoint # 3D14
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    begin_loop
        callnative BehSnowmansBodyCheckpointLoop
    end_loop

glabel beh_big_snowman_whole # 3D2C
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_set_float objGraphYOffset, 0x00B4
    interact_type 0x00800000
    set_hitbox 0x00D2, 0x0226
    begin_loop
        obj_set_int objIntangibleTimer, 0
    end_loop

glabel beh_big_boulder # 3D54
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_float objGraphYOffset, 0x00B4
    callnative BehBigBoulderInit
    obj_set_float objCollisionDistance, 0x4E20
    begin_loop
        obj_set_int objIntangibleTimer, 0
        callnative BehBigBoulderLoop
    end_loop

glabel beh_big_boulder_generator # 3D80
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    begin_loop
        callnative BehBigBoulderGeneratorLoop
    end_loop

glabel beh_wing_cap # 3D98
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    callnative BehWingCapInit
    begin_loop
        callnative BehWingVanishCapLoop
    end_loop

glabel beh_metal_cap # 3DB8
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    callnative BehMetalCapInit
    begin_loop
        callnative BehMetalCapLoop
    end_loop

glabel beh_normal_cap # 3DD8
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    callnative BehNormalCapInit
    begin_loop
        obj_set_int objIntangibleTimer, 0
        callnative BehNormalCapLoop
    end_loop

glabel beh_vanish_cap # 3DFC
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    callnative BehVanishCapInit
    begin_loop
        callnative BehWingVanishCapLoop
    end_loop

glabel beh_collect_star # 3E1C
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    callnative bhv_init_room
    callnative BehCollectStarInit
    begin_loop
        callnative BehCollectStarLoop
    end_loop

glabel beh_star_spawn_coordinates # 3E44
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    callnative BehCollectStarInit
    callnative BehStarSpawnInit
    begin_loop
        callnative BehStarSpawnLoop
    end_loop

glabel beh_hidden_red_coin_star # 3E6C
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, (OBJ_FLAG_4000 | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    callnative BehHiddenRedCoinStarInit
    begin_loop
        callnative BehHiddenRedCoinStarLoop
    end_loop

glabel beh_red_coin # 3E8C
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    billboard
    obj_set_int objIntangibleTimer, 0
    obj_set_int objAnimState, -1
    callnative bhv_init_room
    callnative BehRedCoinInit
    begin_loop
        callnative BehRedCoinLoop
        obj_add_int objAnimState, 1
    end_loop

glabel beh_bowser_course_red_coin_star # 3EC4
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, (OBJ_FLAG_4000 | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    begin_loop
        callnative BehBowserCourseRedCoinStarLoop
    end_loop

glabel beh_hidden_star # 3EDC
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, (OBJ_FLAG_4000 | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    callnative BehHiddenStarInit
    begin_loop
        callnative BehHiddenStarLoop
    end_loop

glabel beh_checkpoint # 3EFC
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    set_hitbox 0x0064, 0x0064
    obj_set_int objIntangibleTimer, 0
    begin_loop
        callnative BehCheckpointLoop
    end_loop

glabel beh_pitoune_2 # 3F20
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    collision_data ttm_seg7_collision_pitoune_2
    unknown_2D
    obj_set_float objCollisionDistance, 0x07D0
    callnative BehPitoune2Init
    begin_loop
        callnative BehPitouneLoop
        callnative load_object_collision_model
    end_loop

glabel beh_falling_when_mario_is_near # 3F58
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    collision_data lll_seg7_collision_falling_wall
    unknown_2D
    begin_loop
        callnative BehFallingWhenMarioNearLoop
        callnative load_object_collision_model
    end_loop

glabel beh_pitoune # 3F84
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    collision_data lll_seg7_collision_pitoune
    unknown_2D
    obj_set_float objCollisionDistance, 0x07D0
    callnative BehPitouneInit
    begin_loop
        callnative BehPitouneLoop
        callnative load_object_collision_model
    end_loop

glabel beh_1up_walking # 3FBC
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    billboard
    unknown_2B 0x001E, 0x001E, 0x0000
    obj_set_float objGraphYOffset, 30
    callnative Beh1UpCommonInit
    begin_loop
        callnative Beh1UpWalkingLoop
    end_loop

glabel beh_1up_running_away # 3FF0
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    billboard
    unknown_2B 0x001E, 0x001E, 0x0000
    obj_set_float objGraphYOffset, 30
    callnative Beh1UpCommonInit
    begin_loop
        callnative Beh1UpRunningAwayLoop
    end_loop

glabel beh_1up_sliding # 4024
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    billboard
    unknown_2B 0x001E, 0x001E, 0x0000
    obj_set_float objGraphYOffset, 30
    callnative Beh1UpCommonInit
    begin_loop
        obj_set_int objIntangibleTimer, 0
        callnative Beh1UpSlidingLoop
    end_loop

glabel beh_1up # 405C
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    billboard
    unknown_2B 0x001E, 0x001E, 0x0000
    obj_set_float objGraphYOffset, 30
    callnative Beh1UpInit
    begin_loop
        obj_set_int objIntangibleTimer, 0
        callnative Beh1UpLoop
    end_loop

glabel beh_1up_jump_on_approach # 4094
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    billboard
    unknown_2B 0x001E, 0x001E, 0x0000
    obj_set_float objGraphYOffset, 30
    callnative Beh1UpCommonInit
    begin_loop
        obj_set_int objIntangibleTimer, 0
        callnative Beh1UpJumpOnApproachLoop
    end_loop

glabel beh_1up_hidden # 40CC
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    billboard
    unknown_2B 0x001E, 0x001E, 0x0000
    obj_set_float objGraphYOffset, 30
    callnative Beh1UpCommonInit
    begin_loop
        obj_set_int objIntangibleTimer, 0
        callnative Beh1UpHiddenLoop
    end_loop

glabel beh_1up_hidden_trigger # 4104
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    set_hitbox 0x0064, 0x0064
    obj_set_int objIntangibleTimer, 0
    begin_loop
        callnative Beh1UpHiddenTriggerLoop
    end_loop

glabel beh_1up_hidden_tree_pole # 4128
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    billboard
    unknown_2B 0x001E, 0x001E, 0x0000
    obj_set_float objGraphYOffset, 30
    callnative Beh1UpCommonInit
    begin_loop
        obj_set_int objIntangibleTimer, 0
        callnative Beh1UpHiddenTreePoleLoop
    end_loop

glabel beh_1up_hidden_tree_pole_trigger # 4160
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    set_hitbox 0x0064, 0x0064
    obj_set_int objIntangibleTimer, 0
    begin_loop
        callnative Beh1UpHiddenTreePoleTriggerLoop
    end_loop

glabel beh_1up_hidden_in_tree # 4184
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    begin_loop
        callnative Beh1UpHiddenInTreeLoop
    end_loop

glabel beh_controllable_platform # 419C
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_0800 | OBJ_FLAG_0020 | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    collision_data hmc_seg7_collision_controllable_platform
    unknown_2D
    callnative BehControllablePlatformInit
    begin_loop
        callnative BehControllablePlatformLoop
        callnative load_object_collision_model
    end_loop

glabel beh_controllable_platform_sub # 41D0
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    collision_data hmc_seg7_collision_controllable_platform_sub
    begin_loop
        callnative BehControllablePlatformSubLoop
        callnative load_object_collision_model
    end_loop

glabel beh_breakable_box2 # 41F8
    begin OBJ_LIST_DESTRUCTIVE
    obj_or_int objFlags, (OBJ_FLAG_HOLDABLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_1E
    unknown_2D
    callnative BehBreakableBox2Init
    begin_loop
        obj_set_int objIntangibleTimer, 0
        callnative BehBreakableBox2Loop
    end_loop

glabel beh_sliding_snow_mound # 4224
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    collision_data sl_seg7_collision_sliding_snow_mound
    unknown_2D
    begin_loop
        callnative BehSlidingSnowMoundLoop
        callnative load_object_collision_model
    end_loop

glabel beh_snow_mound_spawn # 4250
    begin OBJ_LIST_DEFAULT
    begin_loop
        callnative BehSnowMoundSpawnLoop
    end_loop

glabel beh_square_floating_platform # 4264
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    collision_data wdw_seg7_collision_square_floating_platform
    obj_set_float objVarFC, 0x0040
    unknown_2D
    begin_loop
        callnative BehFloatingPlatformLoop
        callnative load_object_collision_model
    end_loop

glabel beh_rect_floating_platform # 4294
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    collision_data wdw_seg7_collision_rect_floating_platform
    obj_set_float objVarFC, 0x0040
    unknown_2D
    begin_loop
        callnative BehFloatingPlatformLoop
        callnative load_object_collision_model
    end_loop

glabel beh_jrb_floating_platform # 42C4
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    collision_data jrb_seg7_collision_floating_platform
    obj_set_float objVarFC, 0x0040
    unknown_2D
    begin_loop
        callnative BehFloatingPlatformLoop
        callnative load_object_collision_model
    end_loop

glabel beh_arrow_lift # 42F4
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    collision_data wdw_seg7_collision_arrow_lift
    obj_set_int_rand_rshift objVar100, 0x0001, 0x0020
    unknown_2D
    begin_loop
        callnative BehArrowLiftLoop
        callnative load_object_collision_model
    end_loop

glabel beh_orange_number # 4328
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    billboard
    unknown_2D
    callnative BehOrangeNumberInit
    begin_loop
        callnative BehOrangeNumberLoop
    end_loop

glabel beh_manta_ray # 4350
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_0010 | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int32 objAnimations, manta_seg5_anims_05008EB4
    unknown_28 0x00
    callnative BehMantaRayInit
    begin_loop
        obj_set_int objIntangibleTimer, 0
        callnative BehMantaRayLoop
    end_loop

glabel beh_falling_pillar # 4380
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_2D
    callnative BehFallingPillarInit
    begin_loop
        callnative BehFallingPillarLoop
    end_loop

glabel beh_some_subojbject_of_falling_pillar # 43A4
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    unknown_2D
    begin_loop
        callnative BehSomeSubobjectFallingPillarLoop
    end_loop

glabel beh_pillar_base # 43C0
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    collision_data jrb_seg7_collision_pillar_base
    begin_loop
        callnative load_object_collision_model
    end_loop

glabel beh_jrb_floating_box # 43E0
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    collision_data jrb_seg7_collision_floating_box
    unknown_2D
    begin_loop
        callnative BehJrbFloatingBoxLoop
        callnative load_object_collision_model
    end_loop

glabel beh_oscillating_pendulum # 440C
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    callnative BehOscillatingPendulumInit
    begin_loop
        callnative BehOscillatingPendulumLoop
    end_loop

glabel beh_treasure_chests_ship # 442C
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    unknown_1E
    callnative BehTreasureChestShipInit
    begin_loop
        callnative BehTreasureChestShipLoop
    end_loop

glabel beh_treasure_chests_jrb # 4450
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    unknown_1E
    callnative BehTreasureChestJrbInit
    begin_loop
        callnative BehTreasureChestJrbLoop
    end_loop

glabel beh_treasure_chests # 4474
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    unknown_1E
    callnative BehTreasureChestInit
    begin_loop
        callnative BehTreasureChestLoop
    end_loop

glabel beh_treasure_chest_bottom # 4498
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    unknown_1E
    callnative BehTreasureChestBottomInit
    obj_set_int objIntangibleTimer, -1
    begin_loop
        callnative BehTreasureChestBottomLoop
    end_loop

glabel beh_treasure_chest_top # 44C0
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    unknown_2D
    begin_loop
        callnative BehTreasureChestTopLoop
    end_loop

glabel beh_mips # 44DC
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_HOLDABLE | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int32 objAnimations, mips_seg6_anims_06015634
    obj_set_int objInteractType, 0x02
    unknown_1E
    set_hitbox 0x0032, 0x004B
    obj_set_int objIntangibleTimer, 0
    callnative BehMipsInit
    begin_loop
        callnative BehMipsLoop
    end_loop

glabel beh_yoshi # 4518
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int32 objAnimations, yoshi_seg5_anims_05024100
    interact_type 0x00800000
    unknown_1E
    set_hitbox 0x00A0, 0x0096
    unknown_28 0x00
    unknown_2D
    callnative BehYoshiInit
    begin_loop
        obj_set_int objIntangibleTimer, 0
        callnative BehYoshiLoop
    end_loop

glabel bKoopa # 4560
    begin OBJ_LIST_PUSHABLE
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_1E
    obj_set_int32 objAnimations, koopa_seg6_anims_06011364
    unknown_28 0x09
    unknown_2D
    unknown_30 0x0032, 0xFE70, 0x0000, 0x0000, 0x03E8, 0x00C8, 0x0000, 0x0000
    scale 150
    obj_set_float objVarF4, 1
    callnative bhv_koopa_init
    begin_loop
        callnative bhv_koopa_update
    end_loop

glabel bKoopaRaceEndpoint # 45B0
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_1E
    unknown_29 0x0000, 0x0000006A, bKoopaFlag
    begin_loop
        callnative bhv_koopa_race_endpoint_update
    end_loop

glabel bKoopaFlag # 45D8
    begin OBJ_LIST_POLELIKE
    interact_type 0x00000040
    set_hitbox 0x0050, 0x02BC
    obj_set_int objIntangibleTimer, 0
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    unknown_1E
    obj_set_int32 objAnimations, koopa_flag_seg6_anims_06001028
    unknown_28 0x00
    begin_loop
        callnative BehClimbDetectLoop
    end_loop

glabel bPokey # 4614
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_1E
    unknown_2D
    unknown_30 0x003C, 0xFE70, 0x0000, 0x03E8, 0x03E8, 0x00C8, 0x0000, 0x0000
    begin_loop
        callnative bhv_pokey_update
    end_loop

glabel bPokeyBodyPart # 4648
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_30 0x003C, 0xFE70, 0x0000, 0x03E8, 0x03E8, 0x00C8, 0x0000, 0x0000
    billboard
    begin_loop
        callnative bhv_pokey_body_part_update
    end_loop

glabel bSwoop # 4678
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int32 objAnimations, swoop_seg6_anims_060070D0
    unknown_2D
    unknown_30 0x0032, 0x0000, 0xFFCE, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
    callnative bhv_init_room
    scale 0
    begin_loop
        callnative bhv_swoop_update
    end_loop

glabel bFlyGuy # 46BC
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int32 objAnimations, flyguy_seg8_anims_08011A64
    unknown_28 0x00
    unknown_2D
    unknown_30 0x0032, 0x0000, 0x0000, 0x0000, 0x03E8, 0x0258, 0x0000, 0x0000
    callnative bhv_init_room
    obj_set_int objUnk190, 0x0080
    obj_set_float objGraphYOffset, 30
    scale 150
    begin_loop
        callnative bhv_fly_guy_update
    end_loop

glabel bGoomba # 470C
    begin OBJ_LIST_PUSHABLE
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_1E
    obj_set_int32 objAnimations, goomba_seg8_anims_0801DA4C
    unknown_2D
    unknown_30 0x0028, 0xFE70, 0xFFCE, 0x03E8, 0x03E8, 0x0000, 0x0000, 0x0000
    callnative bhv_goomba_init
    begin_loop
        callnative bhv_goomba_update
    end_loop

glabel bGoombaTripletSpawner # 4750
    begin OBJ_LIST_PUSHABLE
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_1E
    begin_loop
        callnative bhv_goomba_triplet_spawner_update
    end_loop

glabel bChainChomp # 476C
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_1E
    obj_set_int32 objAnimations, chain_chomp_seg6_anims_06025178
    unknown_28 0x00
    unknown_30 0x0000, 0xFE70, 0xFFCE, 0x0000, 0x03E8, 0x00C8, 0x0000, 0x0000
    unhide
    unknown_2D
    obj_set_float objGraphYOffset, 0x00F0
    scale 200
    unknown_29 0x0000, 0x0000006B, bWoodenPost
    begin_loop
        callnative bhv_chain_chomp_update
    end_loop

glabel bChainChompChainPart # 47C4
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    billboard
    unknown_30 0x0000, 0xFE70, 0xFFCE, 0x03E8, 0x03E8, 0x00C8, 0x0000, 0x0000
    obj_set_float objGraphYOffset, 0x0028
    scale 200
    begin_loop
        callnative bhv_chain_chomp_chain_part_update
    end_loop

glabel bWoodenPost # 47FC
    begin OBJ_LIST_SURFACE
    collision_data poundable_pole_collision_06002490
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_30 0x0000, 0xFE70, 0xFFCE, 0x03E8, 0x03E8, 0x00C8, 0x0000, 0x0000
    obj_set_int objNumLootCoins, 5
    unknown_1E
    unknown_2D
    scale 50
    begin_loop
        callnative bhv_wooden_post_update
        callnative load_object_collision_model
    end_loop

glabel bChainChompGate # 4848
    begin OBJ_LIST_SURFACE
    collision_data bob_seg7_collision_chain_chomp_gate
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    callnative bhv_chain_chomp_gate_init
    begin_loop
        callnative bhv_chain_chomp_gate_update
        callnative load_object_collision_model
    end_loop

glabel bWiggler # 4878
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_1E
    obj_set_int32 objAnimations, wiggler_seg5_anims_0500EC8C
    unknown_2D
    unknown_30 0x003C, 0xFE70, 0x0000, 0x03E8, 0x03E8, 0x00C8, 0x0000, 0x0000
    unhide
    scale 400
    obj_set_float objVarF4, 5000
    begin_loop
        callnative bhv_wiggler_update
    end_loop

glabel bWigglerBodyPart # 48C0
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_set_int32 objAnimations, wiggler_seg5_anims_0500C874
    unknown_30 0x0000, 0xFE70, 0x0000, 0x03E8, 0x03E8, 0x00C8, 0x0000, 0x0000
    scale 400
    begin_loop
        callnative bhv_wiggler_body_part_update
    end_loop

glabel bEnemyLakitu # 48F8
    begin OBJ_LIST_PUSHABLE
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int32 objAnimations, lakitu_enemy_seg5_anims_050144D4
    unknown_28 0x00
    unknown_2D
    unknown_30 0x0028, 0x0000, 0xFFCE, 0x0000, 0x0000, 0x00C8, 0x0000, 0x0000
    begin_loop
        callnative bhv_enemy_lakitu_update
    end_loop

glabel bCameraLakitu # 4934
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int32 objAnimations, lakitu_seg6_anims_060058F8
    unknown_28 0x00
    callnative bhv_init_room
    callnative bhv_camera_lakitu_init
    begin_loop
        callnative bhv_camera_lakitu_update
    end_loop

glabel bCloud # 4968
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    billboard
    unknown_2D
    obj_set_int objOpacity, 0x00F0
    begin_loop
        callnative bhv_cloud_update
    end_loop

glabel bCloudPart # 498C
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_set_int objOpacity, 0x00F0
    begin_loop
        callnative bhv_cloud_part_update
    end_loop

glabel bSpiny # 49A8
    begin OBJ_LIST_PUSHABLE
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int32 objAnimations, spiny_seg5_anims_05016EAC
    unknown_28 0x00
    unknown_30 0x0028, 0xFE70, 0xFFCE, 0x03E8, 0x03E8, 0x00C8, 0x0000, 0x0000
    begin_loop
        callnative bhv_spiny_update
    end_loop

glabel bMontyMole # 49E0
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_1E
    obj_set_int32 objAnimations, monty_mole_seg5_anims_05007248
    unknown_28 0x03
    unknown_30 0x001E, 0x0000, 0xFFCE, 0x03E8, 0x03E8, 0x00C8, 0x0000, 0x0000
    unhide
    obj_set_int objIntangibleTimer, -1
    obj_set_float objGraphYOffset, 0xFFC4
    scale 150
    delay 1
    callnative bhv_monty_mole_init
    begin_loop
        callnative bhv_monty_mole_update
    end_loop

glabel bMontyMoleHole # 4A38
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_1E
    scale 150
    begin_loop
        callnative bhv_monty_mole_hole_update
    end_loop

glabel bMontyMoleRock # 4A58
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    billboard
    unknown_30 0x001E, 0xFE70, 0xFFCE, 0x03E8, 0x03E8, 0x00C8, 0x0000, 0x0000
    obj_set_float objGraphYOffset, 0x000A
    scale 200
    begin_loop
        callnative bhv_monty_mole_rock_update
    end_loop

glabel bPlatformOnTrack # 4A90
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_30 0x0032, 0xFF9C, 0xFFCE, 0x0064, 0x03E8, 0x00C8, 0x0000, 0x0000
    callnative bhv_init_room
    callnative bhv_platform_on_track_init
    begin_loop
        callnative bhv_platform_on_track_update
        callnative load_object_collision_model
    end_loop

glabel bTrackBall # 4AD4
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    billboard
    callnative bhv_init_room
    scale 15
    begin_loop
        callnative bhv_track_ball_update
    end_loop

glabel bSeesawPlatform # 4AFC
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    callnative bhv_seesaw_platform_init
    begin_loop
        callnative bhv_seesaw_platform_update
        callnative load_object_collision_model
    end_loop

glabel bFerrisWheelAxle # 4B24
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_add_int objMoveAngleYaw, 0x4000
    callnative bhv_ferris_wheel_axle_init
    begin_loop
        obj_add_int objFaceAngleRoll, 400
        callnative load_object_collision_model
    end_loop

glabel bFerrisWheelPlatform # 4B4C
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    begin_loop
        callnative bhv_ferris_wheel_platform_update
        callnative load_object_collision_model
    end_loop

glabel bWaterBombSpawner # 4B6C
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_1E
    begin_loop
        callnative bhv_water_bomb_spawner_update
    end_loop

glabel bWaterBomb # 4B88
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_30 0x0078, 0xFE70, 0x0000, 0x03E8, 0x03E8, 0x00C8, 0x0000, 0x0000
    begin_loop
        callnative bhv_water_bomb_update
    end_loop

glabel bWaterBombShadow # 4BB4
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    scale 150
    begin_loop
        callnative bhv_water_bomb_shadow_update
    end_loop

glabel bTTCRotatingSolid # 4BD0
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_2D
    obj_set_float objCollisionDistance, 0x01C2
    callnative bhv_ttc_rotating_solid_init
    obj_set_int objVarF4, 1
    begin_loop
        callnative bhv_ttc_rotating_solid_update
        callnative load_object_collision_model
    end_loop

glabel bTTCPendulum # 4C04
    begin OBJ_LIST_SURFACE
    collision_data ttc_seg7_collision_clock_pendulum
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_float objCollisionDistance, 0x05DC
    callnative bhv_ttc_pendulum_init
    obj_set_float objVarF4, 1
    begin_loop
        callnative bhv_ttc_pendulum_update
        callnative load_object_collision_model
    end_loop

glabel bTTCTreadmill # 4C3C
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_float objCollisionDistance, 0x02EE
    callnative bhv_ttc_treadmill_init
    delay 1
    begin_loop
        callnative bhv_ttc_treadmill_update
        callnative obj_compute_vel_xz
        callnative load_object_collision_model
    end_loop

glabel bTTCMovingBar # 4C74
    begin OBJ_LIST_SURFACE
    collision_data ttc_seg7_collision_sliding_surface
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_2D
    obj_set_float objCollisionDistance, 0x0226
    callnative bhv_ttc_moving_bar_init
    begin_loop
        callnative bhv_ttc_moving_bar_update
        callnative load_object_collision_model
    end_loop

glabel bTTCCog # 4CAC
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_float objCollisionDistance, 0x0190
    callnative bhv_ttc_cog_init
    begin_loop
        callnative bhv_ttc_cog_update
        callnative load_object_collision_model
    end_loop

glabel bTTCPitBlock # 4CD8
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_2D
    obj_set_float objCollisionDistance, 0x015E
    callnative bhv_ttc_pit_block_init
    begin_loop
        callnative bhv_ttc_pit_block_update
        callnative load_object_collision_model
    end_loop

glabel bTTCElevator # 4D08
    begin OBJ_LIST_SURFACE
    collision_data ttc_seg7_collision_clock_platform
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_2D
    obj_set_float objCollisionDistance, 0x0190
    callnative bhv_ttc_elevator_init
    obj_set_float objVarF4, 1
    begin_loop
        callnative bhv_ttc_elevator_update
        callnative load_object_collision_model
    end_loop

glabel bTTC2DRotator # 4D44
    begin OBJ_LIST_SURFACE
    collision_data ttc_seg7_collision_clock_main_rotation
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_set_float objCollisionDistance, 0x0708
    callnative bhv_ttc_2d_rotator_init
    begin_loop
        callnative bhv_ttc_2d_rotator_update
    end_loop

glabel bTTCSpinner # 4D70
    begin OBJ_LIST_SURFACE
    collision_data ttc_seg7_collision_rotating_clock_platform2
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_set_float objCollisionDistance, 0x01C2
    begin_loop
        callnative bhv_ttc_spinner_update
        callnative load_object_collision_model
    end_loop

glabel bMrBlizzard # 4D9C
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_1E
    obj_set_int32 objAnimations, snowman_seg5_anims_0500D118
    unknown_28 0x00
    unknown_2D
    unknown_30 0x001E, 0xFE70, 0x0000, 0x03E8, 0x03E8, 0x00C8, 0x0000, 0x0000
    callnative bhv_mr_blizzard_init
    obj_set_float objVarF4, 1
    begin_loop
        callnative bhv_mr_blizzard_update
    end_loop

glabel bMrBlizzardSnowball # 4DE8
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    billboard
    unknown_30 0x001E, 0xFED4, 0xFFCE, 0x03E8, 0x03E8, 0x00C8, 0x0000, 0x0000
    scale 200
    obj_add_int objMoveAngleYaw, -0x5B58
    obj_set_float objForwardVel, 5
    obj_set_float objVelY, -1
    obj_set_float objGraphYOffset, 10
    begin_loop
        callnative bhv_mr_blizzard_snowball
    end_loop

glabel beh_sliding_platform2 # 4E2C
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_2D
    callnative BehSlidingPlatform2Init
    begin_loop
        callnative BehSlidingPlatform2Loop
        callnative load_object_collision_model
    end_loop

glabel beh_octagonal_platform_rotating # 4E58
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    callnative BehOctagonalPlatformRotatingInit
    begin_loop
        callnative BehOctagonalPlatformRotatingLoop
        callnative load_object_collision_model
    end_loop

glabel beh_floor_switch_press_animation # 4E80
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_float objCollisionDistance, 0x1F40
    callnative BehFloorSwitchPressAnimationInit
    begin_loop
        callnative BehFloorSwitchPressAnimationLoop
        callnative load_object_collision_model
    end_loop

glabel bActivatedBackAndForthPlatform # 4EAC
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_2D
    callnative bhv_activated_back_and_forth_platform_init
    begin_loop
        callnative bhv_activated_back_and_forth_platform_update
        callnative load_object_collision_model
    end_loop

glabel bSpinningHeart # 4ED8
    begin OBJ_LIST_LEVEL
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    begin_loop
        callnative bhv_spinning_heart_update
    end_loop

glabel beh_cannon # 4EF0
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    begin_loop
        callnative BehCannonLoop
    end_loop

glabel beh_cannon_barrel_bubbles # 4F08
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    begin_loop
        callnative BehCannonBarrelBubblesLoop
    end_loop

glabel beh_unagi # 4F20
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int32 objAnimations, unagi_seg5_anims_05012824
    unknown_28 0x06
    unknown_2D
    scale 300
    obj_set_float objDrawingDistance, 0x1770
    callnative BehUnagiInit
    begin_loop
        callnative BehUnagiLoop
    end_loop

glabel beh_unagi_subobject # 4F58
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    begin_loop
        callnative BehUnagiSubobjectLoop
    end_loop

glabel bDorrie # 4F70
    begin OBJ_LIST_SURFACE
    collision_data dorrie_seg6_collision_0600F644
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int32 objAnimations, dorrie_seg6_anims_0600F638
    unknown_2D
    obj_set_float objCollisionDistance, 0x7530
    obj_add_float objPosX, 2000
    callnative bhv_init_room
    begin_loop
        callnative bhv_dorrie_update
        callnative load_object_collision_model
    end_loop

glabel beh_haunted_chair # 4FB4
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_1E
    obj_set_int32 objAnimations, chair_seg5_anims_05005784
    unknown_28 0x00
    unknown_30 0x0028, 0x0000, 0xFFCE, 0x03E8, 0x03E8, 0x00C8, 0x0000, 0x0000
    unknown_2D
    callnative bhv_init_room
    callnative BehHauntedChairInit
    begin_loop
        callnative BehHauntedChairLoop
    end_loop

glabel bMadPiano # 5004
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_1E
    obj_set_int32 objAnimations, mad_piano_seg5_anims_05009B14
    unknown_30 0x0028, 0x0000, 0xFFCE, 0x03E8, 0x03E8, 0x00C8, 0x0000, 0x0000
    unknown_2D
    obj_add_int objMoveAngleYaw, 0x4000
    callnative bhv_init_room
    begin_loop
        callnative bhv_mad_piano_update
    end_loop

glabel beh_flying_bookend # 504C
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int32 objAnimations, bookend_seg5_anims_05002540
    unknown_28 0x00
    unknown_30 0x003C, 0x0000, 0xFFCE, 0x03E8, 0x03E8, 0x00C8, 0x0000, 0x0000
    obj_set_int objMoveFlags, 0
    scale 70
    callnative bhv_init_room
    begin_loop
        callnative BehFlyingBookendLoop
    end_loop

glabel beh_bookend_spawn # 5094
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    callnative bhv_init_room
    begin_loop
        callnative BehBookendSpawnLoop
    end_loop

glabel beh_bookshelf_thing # 50B4
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    callnative bhv_init_room
    begin_loop
        callnative BehBookshelfThingLoop
    end_loop

glabel beh_book_switch # 50D4
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_2D
    obj_set_float objGraphYOffset, 30
    obj_add_int objMoveAngleYaw, 0x4000
    callnative bhv_init_room
    begin_loop
        callnative BehBookSwitchLoop
    end_loop

glabel bFirePiranhaPlant # 5100
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_1E
    obj_set_int32 objAnimations, piranha_plant_seg6_anims_0601C31C
    unknown_28 0x00
    unknown_2D
    unhide
    callnative bhv_fire_piranha_plant_init
    begin_loop
        callnative bhv_fire_piranha_plant_update
    end_loop

glabel beh_small_piranha_flame # 5138
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    billboard
    unknown_30 0x001E, 0x0000, 0xFFCE, 0x03E8, 0x03E8, 0x00C8, 0x0000, 0x0000
    begin_loop
        callnative BehSmallPiranhaFlameLoop
        obj_add_int objAnimState, 1
    end_loop

glabel bFireSpitter # 516C
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    billboard
    scale 40
    begin_loop
        callnative bhv_fire_spitter_update
    end_loop

glabel beh_flyguy_flame # 518C
    begin OBJ_LIST_UNIMPORTANT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    billboard
    unknown_30 0x0000, 0x00C8, 0x0000, 0x03E8, 0x03E8, 0x00C8, 0x0000, 0x0000
    begin_loop
        callnative BehFlyGuyFlameLoop
        obj_add_int objAnimState, 1
    end_loop

glabel beh_snufit # 51C0
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_2D
    unknown_30 0x001E, 0x0000, 0xFFCE, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
    callnative bhv_init_room
    begin_loop
        obj_set_int objVarF4, 0
        callnative BehSnufitLoop
    end_loop

glabel beh_snufit_balls # 51FC
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    billboard
    unknown_30 0x000A, 0x0000, 0xFFCE, 0x03E8, 0x03E8, 0x00C8, 0x0000, 0x0000
    callnative bhv_init_room
    obj_set_float objGraphYOffset, 0x000A
    scale 10
    begin_loop
        callnative BehSnufitBallsLoop
    end_loop

glabel bHorizontalGrindel # 523C
    begin OBJ_LIST_SURFACE
    collision_data ssl_seg7_collision_grindel
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    unknown_1E
    unknown_2D
    unknown_30 0x0028, 0xFE70, 0x0000, 0x03E8, 0x03E8, 0x00C8, 0x0000, 0x0000
    scale 90
    callnative bhv_horizontal_grindel_init
    begin_loop
        callnative obj_update_floor_and_walls
        callnative bhv_horizontal_grindel_update
        callnative load_object_collision_model
    end_loop

glabel beh_eyerok_boss # 5294
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_2D
    begin_loop
        callnative BehEyerokBossLoop
    end_loop

glabel beh_eyerok_hand # 52B0
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int32 objAnimations, eyerok_seg5_anims_050116E4
    unknown_28 0x06
    unknown_30 0x0096, 0x0000, 0x0000, 0x0000, 0x03E8, 0x00C8, 0x0000, 0x0000
    unknown_2D
    obj_set_int objAnimState, 3
    begin_loop
        callnative BehEyerokHandLoop
    end_loop

glabel bKlepto # 52F0
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int32 objAnimations, klepto_seg5_anims_05008CFC
    unknown_28 0x00
    unknown_30 0x0064, 0x0000, 0xFFEC, 0x03E8, 0x03E8, 0x00C8, 0x0000, 0x0000
    unknown_2D
    callnative bhv_klepto_init
    begin_loop
        callnative bhv_klepto_update
    end_loop

glabel bBird # 5334
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int32 objAnimations, birds_seg5_anims_050009E8
    unknown_28 0x00
    unhide
    scale 70
    begin_loop
        callnative bhv_bird_update
    end_loop

glabel bRacingPenguin # 5360
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int32 objAnimations, penguin_seg5_anims_05008B74
    unknown_28 0x03
    unknown_30 0x012C, 0xFCE0, 0xFFFB, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
    scale 400
    callnative bhv_racing_penguin_init
    begin_loop
        callnative bhv_racing_penguin_update
    end_loop

glabel bPenguinRaceFinishLine # 53A4
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    begin_loop
        callnative bhv_penguin_race_finish_line_update
    end_loop

glabel bPenguinRaceShortcutCheck # 53BC
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    begin_loop
        callnative bhv_penguin_race_shortcut_check_update
    end_loop

glabel beh_haunted_room_check # 53D4
    begin OBJ_LIST_SURFACE
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    callnative bhv_init_room
    begin_loop
        callnative BehHauntedRoomCheckLoop
    end_loop

glabel beh_haunted_room_check_subobject # 53F4
    begin OBJ_LIST_SURFACE
    collision_data bbh_seg7_collision_coffin
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_2D
    callnative bhv_init_room
    begin_loop
        callnative BehHauntedRoomCheckSubobjectLoop
    end_loop

glabel beh_clam_shell # 5420
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_1E
    obj_set_int32 objAnimations, clam_shell_seg5_anims_05001744
    obj_set_float objGraphYOffset, 0x000A
    begin_loop
        callnative BehClamShellLoop
    end_loop

glabel bSkeeter # 5448
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int32 objAnimations, skeeter_seg6_anims_06007DE0
    unknown_2D
    unknown_30 0x00B4, 0xFE70, 0xFFCE, 0x03E8, 0x03E8, 0x04B0, 0x0000, 0x0000
    begin_loop
        callnative bhv_skeeter_update
    end_loop

glabel bSkeeterWave # 5480
    begin OBJ_LIST_UNIMPORTANT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    begin_loop
        callnative bhv_skeeter_wave_update
    end_loop

glabel bSwingPlatform # 5498
    begin OBJ_LIST_SURFACE
    collision_data rr_seg7_collision_pendulum
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_set_float objCollisionDistance, 0x07D0
    callnative bhv_swing_platform_init
    begin_loop
        callnative bhv_swing_platform_update
        callnative load_object_collision_model
    end_loop

glabel bDonutPlatformSpawner # 54CC
    begin OBJ_LIST_SPAWNER
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    begin_loop
        callnative bhv_donut_platform_spawner_update
    end_loop

glabel bDonutPlatform # 54E4
    begin OBJ_LIST_SURFACE
    collision_data rr_seg7_collision_donut_platform
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_2D
    begin_loop
        callnative bhv_donut_platform_update
    end_loop

glabel bDDDPole # 5508
    begin OBJ_LIST_POLELIKE
    interact_type 0x00000040
    set_hitbox 0x0050, 0x0320
    obj_set_int objIntangibleTimer, 0
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    unknown_2D
    callnative bhv_ddd_pole_init
    obj_set_float objVarF4, 10
    begin_loop
        callnative bhv_ddd_pole_update
        callnative BehClimbDetectLoop
    end_loop

glabel bRedCoinStarMarker # 554C
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    unknown_1E
    scale 150
    obj_set_int objFaceAnglePitch, 0x4000
    obj_add_float objPosY, 60
    callnative bhv_red_coin_star_marker_init
    begin_loop
        obj_add_int objFaceAngleYaw, 0x100
    end_loop

glabel bTripletButterfly # 5578
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int32 objAnimations, butterfly_seg3_anims_030056B0
    unknown_28 0x00
    unhide
    unknown_2D
    unknown_30 0x0000, 0x0000, 0x0000, 0x0000, 0x03E8, 0x00C8, 0x0000, 0x0000
    obj_set_float objVarF4, 1
    begin_loop
        callnative bhv_triplet_butterfly_update
    end_loop

glabel beh_bubba # 55BC
    begin OBJ_LIST_GENACTOR
    obj_or_int objFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    unknown_2D
    unknown_30 0x00C8, 0xFE70, 0xFFCE, 0x03E8, 0x03E8, 0x0000, 0x0000, 0x0000
    scale 50
    begin_loop
        callnative BehBubbaLoop
    end_loop

glabel beh_beginning_lakitu # 55F0
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_set_int32 objAnimations, lakitu_seg6_anims_060058F8
    unknown_28 0x00
    obj_set_float objOpacity, 0x0000
    begin_loop
        callnative BehBeginningLakituLoop
    end_loop

glabel beh_beginning_peach # 5618
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_set_int32 objAnimations, peach_seg5_anims_0501C41C
    unknown_28 0x00
    begin_loop
        callnative BehBeginningPeachLoop
    end_loop

glabel beh_end_birds_1 # 563C
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, (OBJ_FLAG_0010 | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int32 objAnimations, birds_seg5_anims_050009E8
    unknown_28 0x00
    begin_loop
        callnative BehEndBirds1Loop
    end_loop

glabel beh_end_birds_2 # 5660
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, (OBJ_FLAG_0010 | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj_set_int32 objAnimations, birds_seg5_anims_050009E8
    unknown_28 0x00
    begin_loop
        callnative BehEndBirds2Loop
    end_loop

glabel beh_intro_scene # 5684
    begin OBJ_LIST_DEFAULT
    obj_or_int objFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    begin_loop
        callnative BehIntroSceneLoop
    end_loop

    .align 4
glabel behavior_data_end

