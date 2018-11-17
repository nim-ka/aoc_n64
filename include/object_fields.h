#ifndef _OBJECT_FIELDS_H
#define _OBJECT_FIELDS_H


/**
 * The array [0x88, 0x1C8) in struct Object consists of fields that can vary by
 * object type. These macros provide access to these fields.
 */


#define OBJECT_FIELD_U32(index) rawData.asU32[index]
#define OBJECT_FIELD_S32(index) rawData.asS32[index]
#define OBJECT_FIELD_S16(index, subIndex) rawData.asS16[index][subIndex]
#define OBJECT_FIELD_U8(index, subIndex) rawData.asU8[index][subIndex]
#define OBJECT_FIELD_F32(index) rawData.asF32[index]
#define OBJECT_FIELD_VOIDP(index) rawData.asVoidP[index]
#define OBJECT_FIELD_S16P(index) rawData.asS16P[index]
#define OBJECT_FIELD_S32P(index) rawData.asS32P[index]
#define OBJECT_FIELD_ANIMS(index) rawData.asAnims[index]
#define OBJECT_FIELD_WAYPOINT(index) rawData.asWaypoint[index]
#define OBJECT_FIELD_CHAIN_SEGMENT(index) rawData.asChainSegment[index]
#define OBJECT_FIELD_OBJECT(index) rawData.asObject[index]
#define OBJECT_FIELD_SURFACE(index) rawData.asSurface[index]
#define OBJECT_FIELD_VPTR(index) rawData.asVoidPtr[index]


/* Common fields */
#define /*0x088*/ oUnk88 OBJECT_FIELD_S32(0x00)
#define /*0x08C*/ oFlags OBJECT_FIELD_U32(0x01)
#define /*0x090*/ oDialogueResponse OBJECT_FIELD_S16(0x02, 0)
#define /*0x092*/ oDialogueState OBJECT_FIELD_S16(0x02, 1)
#define /*0x09C*/ oIntangibleTimer OBJECT_FIELD_S32(0x05)
#define /*0x0A0*/ O_POS_INDEX 0x06
#define /*0x0A0*/ oPosX OBJECT_FIELD_F32(O_POS_INDEX + 0)
#define /*0x0A4*/ oPosY OBJECT_FIELD_F32(O_POS_INDEX + 1)
#define /*0x0A8*/ oPosZ OBJECT_FIELD_F32(O_POS_INDEX + 2)
#define /*0x0AC*/ oVelX OBJECT_FIELD_F32(0x09)
#define /*0x0B0*/ oVelY OBJECT_FIELD_F32(0x0A)
#define /*0x0B4*/ oVelZ OBJECT_FIELD_F32(0x0B)
#define /*0x0B8*/ oForwardVel OBJECT_FIELD_F32(0x0C)
#define /*0x0BC*/ oUnkBC OBJECT_FIELD_F32(0x0D)
#define /*0x0C0*/ oUnkC0 OBJECT_FIELD_F32(0x0E)
#define /*0x0C4*/ O_MOVE_ANGLE_INDEX 0x0F
#define /*0x0C4*/ oMoveAnglePitch OBJECT_FIELD_S32(O_MOVE_ANGLE_INDEX + 0)
#define /*0x0C8*/ oMoveAngleYaw OBJECT_FIELD_S32(O_MOVE_ANGLE_INDEX + 1)
#define /*0x0CC*/ oMoveAngleRoll OBJECT_FIELD_S32(O_MOVE_ANGLE_INDEX + 2)
#define /*0x0D0*/ O_FACE_ANGLE_INDEX 0x12
#define /*0x0D0*/ oFaceAnglePitch OBJECT_FIELD_S32(O_FACE_ANGLE_INDEX + 0)
#define /*0x0D4*/ oFaceAngleYaw OBJECT_FIELD_S32(O_FACE_ANGLE_INDEX + 1)
#define /*0x0D8*/ oFaceAngleRoll OBJECT_FIELD_S32(O_FACE_ANGLE_INDEX + 2)
#define /*0x0DC*/ oGraphYOffset OBJECT_FIELD_F32(0x15)
#define /*0x0E0*/ oUnkE0 OBJECT_FIELD_U32(0x16)
#define /*0x0E4*/ oGravity OBJECT_FIELD_F32(0x17)
#define /*0x0E8*/ oFloorHeight OBJECT_FIELD_F32(0x18)
#define /*0x0EC*/ oMoveFlags OBJECT_FIELD_U32(0x19)
#define /*0x0F0*/ oAnimState OBJECT_FIELD_S32(0x1A)
// 0x0F4-0x110 (0x1B-0x22) are object specific and defined below the common fields.
#define /*0x114*/ oAngleVelPitch OBJECT_FIELD_S32(0x23)
#define /*0x118*/ oAngleVelYaw OBJECT_FIELD_S32(0x24)
#define /*0x11C*/ oAngleVelRoll OBJECT_FIELD_S32(0x25)
#define /*0x120*/ oAnimations OBJECT_FIELD_ANIMS(0x26)
#define /*0x124*/ oHeldState OBJECT_FIELD_U32(0x27)
#define /*0x128*/ oWallHitboxRadius OBJECT_FIELD_F32(0x28)
#define /*0x12C*/ oDragStrength OBJECT_FIELD_F32(0x29)
#define /*0x130*/ oInteractType OBJECT_FIELD_U32(0x2A)
#define /*0x134*/ oInteractStatus OBJECT_FIELD_U32(0x2B)
#define /*0x138*/ O_PARENT_REL_INDEX 0x2C
#define /*0x138*/ oParentRelX OBJECT_FIELD_F32(O_PARENT_REL_INDEX + 0)
#define /*0x13C*/ oParentRelY OBJECT_FIELD_F32(O_PARENT_REL_INDEX + 1)
#define /*0x140*/ oParentRelZ OBJECT_FIELD_F32(O_PARENT_REL_INDEX + 2)
#define /*0x144*/ oBehParams2ndByte OBJECT_FIELD_S32(0x2F)
#define /*0x14C*/ oAction OBJECT_FIELD_S32(0x31)
#define /*0x150*/ oSubAction OBJECT_FIELD_U32(0x32)
#define /*0x154*/ oTimer OBJECT_FIELD_S32(0x33)
#define /*0x158*/ oBounce OBJECT_FIELD_F32(0x34)
#define /*0x15C*/ oDistanceToMario OBJECT_FIELD_F32(0x35)
#define /*0x160*/ oAngleToMario OBJECT_FIELD_S32(0x36)
#define /*0x164*/ oHomeX OBJECT_FIELD_F32(0x37)
#define /*0x168*/ oHomeY OBJECT_FIELD_F32(0x38)
#define /*0x16C*/ oHomeZ OBJECT_FIELD_F32(0x39)
#define /*0x170*/ oFriction OBJECT_FIELD_F32(0x3A)
#define /*0x174*/ oBuoyancy OBJECT_FIELD_F32(0x3B)
#define /*0x178*/ oSoundStateID OBJECT_FIELD_S32(0x3C)
#define /*0x17C*/ oOpacity OBJECT_FIELD_S32(0x3D)
#define /*0x180*/ oUnk180 OBJECT_FIELD_S32(0x3E)
#define /*0x184*/ oHealth OBJECT_FIELD_S32(0x3F)
#define /*0x188*/ oBehParams OBJECT_FIELD_S32(0x40)
#define /*0x18C*/ oPrevAction OBJECT_FIELD_S32(0x41)
#define /*0x190*/ oUnk190 OBJECT_FIELD_U32(0x42)
#define /*0x194*/ oCollisionDistance OBJECT_FIELD_F32(0x43)
#define /*0x198*/ oNumLootCoins OBJECT_FIELD_S32(0x44)
#define /*0x19C*/ oDrawingDistance OBJECT_FIELD_F32(0x45)
#define /*0x1A0*/ oRoom OBJECT_FIELD_S32(0x46)
#define /*0x1A8*/ oUnk1A8 OBJECT_FIELD_U32(0x48)
#define /*0x1AC*/ oUnk1AC OBJECT_FIELD_VPTR(0x49)
#define /*0x1B0*/ oUnk1B0 OBJECT_FIELD_S32(0x4A)
#define /*0x1B4*/ oWallAngle OBJECT_FIELD_U32(0x4B)
#define /*0x1B8*/ oFloorType OBJECT_FIELD_S16(0x4C, 0)
#define /*0x1BA*/ oFloorRoom OBJECT_FIELD_S16(0x4C, 1)
#define /*0x1C0*/ oFloor OBJECT_FIELD_SURFACE(0x4E)
#define /*0x1C4*/ oDeathSound OBJECT_FIELD_S32(0x4F)

/* All uses of these should be removed as soon as object type is known */
#define /*0x0F4*/ oUnknownUnkF4_S32 OBJECT_FIELD_S32(0x1B)
#define /*0x0F8*/ oUnknownUnkF8_S32 OBJECT_FIELD_S32(0x1C)
#define /*0x0FC*/ oUnknownUnkFC_S32 OBJECT_FIELD_S32(0x1D)
#define /*0x100*/ oUnknownUnk100_S32 OBJECT_FIELD_S32(0x1E)
#define /*0x108*/ oUnknownUnk108_F32 OBJECT_FIELD_F32(0x20)
#define /*0x10C*/ oUnknownUnk10C_F32 OBJECT_FIELD_F32(0x21)
#define /*0x110*/ oUnknownUnk110_F32 OBJECT_FIELD_F32(0x22)

/* Pathed (see obj_follow_path) */
#define /*0x0FC*/ oPathedStartWaypoint OBJECT_FIELD_WAYPOINT(0x1D)
#define /*0x100*/ oPathedPrevWaypoint OBJECT_FIELD_WAYPOINT(0x1E)
#define /*0x104*/ oPathedPrevWaypointFlags OBJECT_FIELD_S32(0x1F)
#define /*0x108*/ oPathedTargetPitch OBJECT_FIELD_S32(0x20)
#define /*0x10C*/ oPathedTargetYaw OBJECT_FIELD_S32(0x21)

/* Mario */
#define /*0x0F4*/ oMarioParticleFlags OBJECT_FIELD_S32(0x1B)
#define /*0x108*/ oMarioPoleUnk108 OBJECT_FIELD_S32(0x20)
#define /*0x108*/ oMarioReadingSignDYaw OBJECT_FIELD_S32(0x20)
#define /*0x10C*/ oMarioPoleYawVel OBJECT_FIELD_S32(0x21)
#define /*0x10C*/ oMarioCannonObjectYaw OBJECT_FIELD_S32(0x21)
#define /*0x10C*/ oMarioTornadoYawVel OBJECT_FIELD_S32(0x21)
#define /*0x10C*/ oMarioReadingSignDPosX OBJECT_FIELD_F32(0x21)
#define /*0x110*/ oMarioPolePos OBJECT_FIELD_F32(0x22)
#define /*0x110*/ oMarioCannonInputYaw OBJECT_FIELD_S32(0x22)
#define /*0x110*/ oMarioTornadoPosY OBJECT_FIELD_F32(0x22)
#define /*0x110*/ oMarioReadingSignDPosZ OBJECT_FIELD_F32(0x22)
#define /*0x110*/ oMarioWhirlpoolPosY OBJECT_FIELD_F32(0x22)
#define /*0x110*/ oMarioBurnTimer OBJECT_FIELD_S32(0x22)
#define /*0x110*/ oMarioLongJumpIsSlow OBJECT_FIELD_S32(0x22)
#define /*0x110*/ oMarioSteepJumpYaw OBJECT_FIELD_S32(0x22)
#define /*0x110*/ oMarioWalkingPitch OBJECT_FIELD_S32(0x22)

/* Star selector */
#define /*0x0F4*/ oStarSelectorType OBJECT_FIELD_S32(0x1B)
#define /*0x0F8*/ oStarSelectorTimer OBJECT_FIELD_S32(0x1C)
#define /*0x108*/ oStarSelectorSize OBJECT_FIELD_F32(0x20)

/* Sound effect */
#define /*0x0F4*/ oSoundEffectUnkF4 OBJECT_FIELD_S32(0x1B)

/* Main menu button */
#define /*0x0F4*/ oMenuButtonState OBJECT_FIELD_S32(0x1B)
#define /*0x0F8*/ oMenuButtonTimer OBJECT_FIELD_S32(0x1C)
#define /*0x0FC*/ oMenuButtonOrigPosX OBJECT_FIELD_F32(0x1D)
#define /*0x100*/ oMenuButtonOrigPosY OBJECT_FIELD_F32(0x1E)
#define /*0x104*/ oMenuButtonOrigPosZ OBJECT_FIELD_F32(0x1F)
#define /*0x108*/ oMenuButtonScale OBJECT_FIELD_F32(0x20)
#define /*0x10C*/ oMenuButtonActionPhase OBJECT_FIELD_S32(0x21)

/* Toad message */
#define /*0x108*/ oToadMessageDialogNum OBJECT_FIELD_U32(0x20)
#define /*0x10C*/ oToadMessageRecentlyTalked OBJECT_FIELD_S32(0x21)
#define /*0x110*/ oToadMessageState OBJECT_FIELD_S32(0x22)

/* Sealed door star */
#define /*0x108*/ oSealedDoorStarUnk108 OBJECT_FIELD_U32(0x20)
#define /*0x10C*/ oSealedDoorStarUnk10C OBJECT_FIELD_S32(0x21)
#define /*0x10C*/ oSealedDoorStarUnk110 OBJECT_FIELD_S32(0x22)

/* Bob-omb */
#define /*0x0F4*/ oBobombBlinkTimer OBJECT_FIELD_S32(0x1B)
#define /*0x0F8*/ oBobombFuseLit OBJECT_FIELD_S32(0x1C)
#define /*0x0FC*/ oBobombFuseTimer OBJECT_FIELD_S32(0x1D)

/* Bob-omb Buddy */
#define /*0x0F4*/ oBobombBuddyBlinkTimer OBJECT_FIELD_S32(0x1B)
#define /*0x0F8*/ oBobombBuddyHasTalkedToMario OBJECT_FIELD_S32(0x1C)
#define /*0x0FC*/ oBobombBuddyRole OBJECT_FIELD_S32(0x1D)
#define /*0x100*/ oBobombBuddyCannonStatus OBJECT_FIELD_S32(0x1E)
#define /*0x108*/ oBobombBuddyPosXCopy OBJECT_FIELD_F32(0x20)
#define /*0x10C*/ oBobombBuddyPosYCopy OBJECT_FIELD_F32(0x21)
#define /*0x110*/ oBobombBuddyPosZCopy OBJECT_FIELD_F32(0x22)

/* Whirlpool */
#define /*0x0F4*/ oWhirlpoolInitFacePitch OBJECT_FIELD_S32(0x1B)
#define /*0x0F8*/ oWhirlpoolInitFaceRoll OBJECT_FIELD_S32(0x1C)

/* Homing Amp */
#define /*0x0F4*/ oAmpHomingLockedOn OBJECT_FIELD_S32(0x1B)
#define /*0x0F8*/ oAmpHomingYPhase OBJECT_FIELD_S32(0x1C)
#define /*0x0FC*/ oAmpHomingAvgY OBJECT_FIELD_F32(0x1D)

/* Amp */
#define /*0x0F4*/ oAmpRadiusOfRotation OBJECT_FIELD_F32(0x1B)
#define /*0x0F8*/ oAmpYPhase OBJECT_FIELD_S32(0x1C)

/* Butterfly */
#define /*0x0F4*/ oButterflyYPhase OBJECT_FIELD_S32(0x1B)

/* Hoot */
#define /*0x0F4*/ oHootAvailability OBJECT_FIELD_S32(0x1B)
#define /*0x110*/ oHootMarioReleaseTime OBJECT_FIELD_S32(0x22)

/* Bob-omb Explosion Bubble */
#define /*0x0FC*/ oBobombExpBubGfxScaleFacX OBJECT_FIELD_S32(0x1D)
#define /*0x100*/ oBobombExpBubGfxScaleFacY OBJECT_FIELD_S32(0x1E)
#define /*0x104*/ oBobombExpBubGfxExpRateX OBJECT_FIELD_S32(0x1F)
#define /*0x108*/ oBobombExpBubGfxExpRateY OBJECT_FIELD_S32(0x20)

/* Bob-omb and Cork Box Respawner */
#define /*0x0F4*/ oBreakableBoxBackupUnkF4 OBJECT_FIELD_S32(0x1B)
#define /*0x0F8*/ oBBCBRespawnerMinSpawnDist OBJECT_FIELD_F32(0x1C)
#define /*0x0FC*/ oBBCBRespawnerBehaviorToSpawn OBJECT_FIELD_VPTR(0x1D)

/* Bully (all variants) */
#define /*0x0F4*/ oBullySubtype OBJECT_FIELD_S32(0x1B)
#define /*0x0F8*/ oBullyPrevX OBJECT_FIELD_F32(0x1C)
#define /*0x0FC*/ oBullyPrevY OBJECT_FIELD_F32(0x1D)
#define /*0x100*/ oBullyPrevZ OBJECT_FIELD_F32(0x1E)
#define /*0x104*/ oBullyKBTimerAndMinionKOCounter OBJECT_FIELD_S32(0x1F)
#define /*0x108*/ oBullyMarioCollisionAngle OBJECT_FIELD_S32(0x20)

/* Water Ring (both variants) */
#define /*0x0F4*/ oWaterRingScalePhaseX OBJECT_FIELD_S32(0x1B)
#define /*0x0F8*/ oWaterRingScalePhaseY OBJECT_FIELD_S32(0x1C)
#define /*0x0FC*/ oWaterRingScalePhaseZ OBJECT_FIELD_S32(0x1D)
#define /*0x100*/ oWaterRingNormalX OBJECT_FIELD_F32(0x1E)
#define /*0x104*/ oWaterRingNormalY OBJECT_FIELD_F32(0x1F)
#define /*0x108*/ oWaterRingNormalZ OBJECT_FIELD_F32(0x20)
#define /*0x10C*/ oWaterRingMarioDistInFront OBJECT_FIELD_F32(0x21)
#define /*0x110*/ oWaterRingIndex OBJECT_FIELD_S32(0x22)
#define /*0x1AC*/ oWaterRingAvgScale OBJECT_FIELD_F32(0x49)

/* Water Ring Spawner (Jet Stream Ring Spawner and Manta Ray) */
#define /*0x1AC*/ oWaterRingSpawnerRingsCollected OBJECT_FIELD_S32(0x49)
#define /*0x1AF*/ oUnk1AF OBJECT_FIELD_U8(0x49, 3)

/* Water Ring Manager (Jet Stream Ring Spawner and Manta Ray Ring Manager) */
#define /*0x0F4*/ oWaterRingMgrNextRingIndex OBJECT_FIELD_S32(0x1B)
#define /*0x0F8*/ oWaterRingMgrLastRingCollected OBJECT_FIELD_S32(0x1C)

/* Celebration Star */
#define /*0x108*/ oCelebStarDiameterOfRotation OBJECT_FIELD_S32(0x20)

/* Bomp (small) */
#define /*0x100*/ oSmallBompInitX OBJECT_FIELD_F32(0x1E)

/* WF Sliding Brick Platform */
#define /*0x0F4*/ oWFSlidBrickPtfmMovVel OBJECT_FIELD_F32(0x1B) 

/* Moneybag */
#define /*0x0F4*/ oMoneybagJumpState OBJECT_FIELD_S32(0x1B) 

/* Bowling Ball */
#define /*0x0F4*/ oBowlingBallTargetYaw OBJECT_FIELD_S32(0x1B)
#define /*0x0FC*/ oBowlingBallUnkFC OBJECT_FIELD_VPTR(0x1D)
#define /*0x10C*/ oBowlingBallInitYaw OBJECT_FIELD_S32(0x21)

/* Bowling Ball Spawner (Generic) */
#define /*0x0F4*/ oBBallSpwnrMaxSpawnDist OBJECT_FIELD_F32(0x1B)
#define /*0x0F8*/ oBBallSpwnrSpawnOdds OBJECT_FIELD_F32(0x1C)
#define /*0x0FC*/ oBBallSpwnrPeriodMinus1 OBJECT_FIELD_S32(0x1D)

/* RR Cruiser Wing */
#define /*0x0F4*/ oRRCruiserWingUnkF4 OBJECT_FIELD_S32(0x1B)
#define /*0x0F8*/ oRRCruiserWingUnkF8 OBJECT_FIELD_S32(0x1C)

/* Koopa */
#define /*0x0F4*/ oKoopaUnkF4 OBJECT_FIELD_F32(0x1B)
#define /*0x0F8*/ oKoopaMovementType OBJECT_FIELD_S32(0x1C)
#define /*0x0FC*/ oKoopaTargetYaw OBJECT_FIELD_S32(0x1D)
#define /*0x100*/ oKoopaUnk100 OBJECT_FIELD_S32(0x1E)
#define /*0x104*/ oKoopaTurning OBJECT_FIELD_S32(0x1F)
#define /*0x104*/ oKoopaUnk104_2 OBJECT_FIELD_S32(0x1F)
#define /*0x108*/ oKoopaDistanceToMario OBJECT_FIELD_F32(0x20)
#define /*0x10C*/ oKoopaAngleToMario OBJECT_FIELD_S32(0x21)
#define /*0x110*/ oKoopaBlinkTimer OBJECT_FIELD_S32(0x22)
#define /*0x1AC*/ oKoopaCountdown OBJECT_FIELD_S16(0x49, 0)
#define /*0x1AE*/ oKoopaTheQuickRaceIndex OBJECT_FIELD_S16(0x49, 1)
#define /*0x1B0*/ oKoopaTheQuickInitTextboxCooldown OBJECT_FIELD_S16(0x4A, 0)
// 0x1D-0x21 for koopa the quick reserved for pathing

/* Koopa race endpoint */
#define /*0x0F4*/ oKoopaRaceEndpointUnkF4 OBJECT_FIELD_S32(0x1B)
#define /*0x0F8*/ oKoopaRaceEndpointUnkF8 OBJECT_FIELD_S32(0x1C)
#define /*0x0FC*/ oKoopaRaceEndpointUnkFC OBJECT_FIELD_S32(0x1D)
#define /*0x104*/ oKoopaRaceEndpointUnk104 OBJECT_FIELD_S32(0x1F)

/* Pokey body part */
#define /*0x0F8*/ oPokeyBodyPartUnkF8 OBJECT_FIELD_S32(0x1C)
#define /*0x110*/ oPokeyBodyPartBlinkTimer OBJECT_FIELD_S32(0x22)

/* Pokey */
#define /*0x0F4*/ oPokeyUnkF4 OBJECT_FIELD_U32(0x1B)
#define /*0x0F8*/ oPokeyNumBodyParts OBJECT_FIELD_S32(0x1C)
#define /*0x0FC*/ oPokeyUnkFC OBJECT_FIELD_F32(0x1D)
#define /*0x100*/ oPokeyUnk100 OBJECT_FIELD_S32(0x1E)
#define /*0x104*/ oPokeyTargetYaw OBJECT_FIELD_S32(0x1F)
#define /*0x108*/ oPokeyChangeTargetTimer OBJECT_FIELD_S32(0x20)
#define /*0x10C*/ oPokeyTurning OBJECT_FIELD_S32(0x21)

/* Swoop */
#define /*0x0F4*/ oSwoopTimeUntilTurn OBJECT_FIELD_S32(0x1B)
#define /*0x0F8*/ oSwoopTargetPitch OBJECT_FIELD_S32(0x1C)
#define /*0x0FC*/ oSwoopTargetYaw OBJECT_FIELD_S32(0x1D)

/* Fly guy */
#define /*0x0F4*/ oFlyGuyIdleTimer OBJECT_FIELD_S32(0x1B)
#define /*0x0F8*/ oFlyGuyOscTimer OBJECT_FIELD_S32(0x1C)
#define /*0x0FC*/ oFlyGuyUnkFC OBJECT_FIELD_S32(0x1D)
#define /*0x100*/ oFlyGuyLungeYAccel OBJECT_FIELD_F32(0x1E)
#define /*0x104*/ oFlyGuyLungeTargetPitch OBJECT_FIELD_S32(0x1F)
#define /*0x108*/ oFlyGuyTargetRoll OBJECT_FIELD_S32(0x20)
#define /*0x10C*/ oFlyGuyScaleVel OBJECT_FIELD_F32(0x21)

/* Goomba */
#define /*0x0F4*/ oGoombaSize OBJECT_FIELD_S32(0x1B)
#define /*0x0F8*/ oGoombaBaseSpeed OBJECT_FIELD_F32(0x1C)
#define /*0x0FC*/ oGoombaWalkTimer OBJECT_FIELD_S32(0x1D)
#define /*0x100*/ oGoombaTargetYaw OBJECT_FIELD_S32(0x1E)
#define /*0x104*/ oGoombaBlinkTimer OBJECT_FIELD_S32(0x1F)
#define /*0x108*/ oGoombaTurning OBJECT_FIELD_S32(0x20)
#define /*0x10C*/ oGoombaRelativeSpeed OBJECT_FIELD_F32(0x21)

/* Chain chomp */
#define /*0x0F4*/ oChainChompSegments OBJECT_FIELD_CHAIN_SEGMENT(0x1B)
#define /*0x0F8*/ oChainChompUnkF8 OBJECT_FIELD_F32(0x1C)
#define /*0x0FC*/ oChainChompUnkFC OBJECT_FIELD_F32(0x1D)
#define /*0x100*/ oChainChompUnk100 OBJECT_FIELD_F32(0x1E)
#define /*0x104*/ oChainChompUnk104 OBJECT_FIELD_F32(0x1F)
#define /*0x108*/ oChainChompUnk108 OBJECT_FIELD_S32(0x20)
#define /*0x10C*/ oChainChompTargetPitch OBJECT_FIELD_S32(0x21)
#define /*0x110*/ oChainChompUnk110 OBJECT_FIELD_S32(0x22)
#define /*0x1AC*/ oChainChompUnk1AC OBJECT_FIELD_S32(0x49)
#define /*0x1B0*/ oChainChompUnk1B0 OBJECT_FIELD_S32(0x4A)

/* Wooden post */
#define /*0x0F4*/ oWoodenPostTotalMarioAngle OBJECT_FIELD_S32(0x1B)
#define /*0x0F8*/ oWoodenPostPrevAngleToMario OBJECT_FIELD_S32(0x1C)
#define /*0x0FC*/ oWoodenPostSpeedY OBJECT_FIELD_F32(0x1D)
#define /*0x100*/ oWoodenPostMarioPounding OBJECT_FIELD_S32(0x1E)
#define /*0x104*/ oWoodenPostOffsetY OBJECT_FIELD_F32(0x1F)

/* Wiggler */
#define /*0x0F4*/ oWigglerUnkF4 OBJECT_FIELD_F32(0x1B)
#define /*0x0F8*/ oWigglerSegments OBJECT_FIELD_CHAIN_SEGMENT(0x1C)
#define /*0x0FC*/ oWigglerUnkFC OBJECT_FIELD_F32(0x1D)
#define /*0x104*/ oWigglerSquishSpeed OBJECT_FIELD_F32(0x1F)
#define /*0x108*/ oWigglerTimeUntilRandomTurn OBJECT_FIELD_S32(0x20)
#define /*0x10C*/ oWigglerTargetYaw OBJECT_FIELD_S32(0x21)
#define /*0x110*/ oWigglerWalkStraightTimer OBJECT_FIELD_S32(0x22)
#define /*0x1AC*/ oWigglerUnk1AC OBJECT_FIELD_S16(0x49, 0)
#define /*0x1AE*/ oWigglerUnk1AE OBJECT_FIELD_S16(0x49, + 1)

/* Spiny */
#define /*0x0F4*/ oSpinyTimeUntilTurn OBJECT_FIELD_S32(0x1B)
#define /*0x0F8*/ oSpinyTargetYaw OBJECT_FIELD_S32(0x1C)
#define /*0x100*/ oSpinyTurning OBJECT_FIELD_S32(0x1E)

/* Evil lakitu */
#define /*0x0F4*/ oEvilLakituNumSpinies OBJECT_FIELD_S32(0x1B)
#define /*0x0F8*/ oEvilLakituBlinkTimer OBJECT_FIELD_S32(0x1C)
#define /*0x0FC*/ oEvilLakituUnkFC OBJECT_FIELD_S32(0x1D)
#define /*0x100*/ oEvilLakituUnk100 OBJECT_FIELD_S32(0x1E)

/* Fwoosh spawner */
#define /*0x0F4*/ oFwooshSpawnerUnkF4 OBJECT_FIELD_F32(0x1B)
#define /*0x0F8*/ oFwooshSpawnerUnkF8 OBJECT_FIELD_F32(0x1C)
#define /*0x0FC*/ oFwooshSpawnerUnkFC OBJECT_FIELD_S32(0x1D)
#define /*0x100*/ oFwooshSpawnerUnk100 OBJECT_FIELD_F32(0x1E)
#define /*0x1AC*/ oFwooshSpawnerUnk1AC OBJECT_FIELD_S16(0x49, 0)

/* Nice lakitu */
#define /*0x0F4*/ oNiceLakituBlinkTimer OBJECT_FIELD_S32(0x1B)
#define /*0x0F8*/ oNiceLakituUnkF8 OBJECT_FIELD_F32(0x1C)
#define /*0x0FC*/ oNiceLakituUnkFC OBJECT_FIELD_F32(0x1D)
#define /*0x100*/ oNiceLakituUnk100 OBJECT_FIELD_S32(0x1E)
#ifndef VERSION_JP
#define /*0x104*/ oNiceLakituUnk104 OBJECT_FIELD_S32(0x1F)
#endif
#define /*0x1AC*/ oNiceLakituUnk1AC OBJECT_FIELD_S16(0x49, 0)
#define /*0x1AE*/ oNiceLakituUnk1AE OBJECT_FIELD_S16(0x49, + 1)

/* Monty mole hole */
#define /*0x0F4*/ oMontyMoleHoleUnkF4 OBJECT_FIELD_S32(0x1B)

/* Monty mole */
#define /*0x0F4*/ oMontyMoleUnkF4 OBJECT_FIELD_OBJECT(0x1B)
#define /*0x0F8*/ oMontyMoleUnkF8 OBJECT_FIELD_F32(0x1C)

/* Platform on tracks */
#define /*0x0F4*/ oPlatformOnTrackUnkF4 OBJECT_FIELD_F32(0x1B)
#define /*0x0F8*/ oPlatformOnTrackUnkF8 OBJECT_FIELD_F32(0x1C)
#define /*0x0FC*/ oPlatformOnTrackUnkFC OBJECT_FIELD_S16P(0x1D)
#define /*0x100*/ oPlatformOnTrackUnk100 OBJECT_FIELD_S16P(0x1E)
#define /*0x104*/ oPlatformOnTrackUnk104 OBJECT_FIELD_S32(0x1F)
#define /*0x108*/ oPlatformOnTrackPitch OBJECT_FIELD_S32(0x20)
#define /*0x10C*/ oPlatformOnTrackYaw OBJECT_FIELD_S32(0x21)
#define /*0x110*/ oPlatformOnTrackUnk110 OBJECT_FIELD_F32(0x22)
#define /*0x1AC*/ oPlatformOnTrackUnk1AC OBJECT_FIELD_S16(0x49, 0)
#define /*0x1AE*/ oPlatformOnTrackUnk1AE OBJECT_FIELD_S16(0x49, + 1)
#define /*0x1B0*/ oPlatformOnTrackUnk1B0 OBJECT_FIELD_S16(0x4A, 0)
#define /*0x1B2*/ oPlatformOnTrackUnk1B2 OBJECT_FIELD_S16(0x4A, + 1)

/* Seesaw platform */
#define /*0x0F4*/ oSeesawPlatformPitchVel OBJECT_FIELD_F32(0x1B)

/* Water bomb spawner */
#define /*0x0F4*/ oWaterBombSpawnerBombActive OBJECT_FIELD_S32(0x1B)
#define /*0x0F8*/ oWaterBombSpawnerTimeToSpawn OBJECT_FIELD_S32(0x1C)

/* Water bomb */
#define /*0x0F8*/ oWaterBombVerticalStretch OBJECT_FIELD_F32(0x1C)
#define /*0x0FC*/ oWaterBombUnkFC OBJECT_FIELD_F32(0x1D)
#define /*0x100*/ oWaterBombOnGround OBJECT_FIELD_S32(0x1E)
#define /*0x104*/ oWaterBombNumBounces OBJECT_FIELD_F32(0x1F)

/* TTC rotating solid */
#define /*0x0F4*/ oTTCRotatingSolidPhase OBJECT_FIELD_S32(0x1B)
#define /*0x0F8*/ oTTCRotatingSolidNumSides OBJECT_FIELD_S32(0x1C)
#define /*0x0FC*/ oTTCRotatingSolidTimeUntilRotation OBJECT_FIELD_S32(0x1D)
#define /*0x100*/ oTTCRotatingSolidVelY OBJECT_FIELD_F32(0x1E)
#define /*0x104*/ oTTCRotatingSolidSoundTimer OBJECT_FIELD_S32(0x1F)

/* TTC pendulum */
#define /*0x0F4*/ oTTCPendulumAccelDir OBJECT_FIELD_F32(0x1B)
#define /*0x0F8*/ oTTCPendulumAngle OBJECT_FIELD_F32(0x1C)
#define /*0x0FC*/ oTTCPendulumAngleVel OBJECT_FIELD_F32(0x1D)
#define /*0x100*/ oTTCPendulumAngleAccel OBJECT_FIELD_F32(0x1E)
#define /*0x104*/ oTTCPendulumStoppedTimer OBJECT_FIELD_S32(0x1F)
#define /*0x108*/ oTTCPendulumSoundTimer OBJECT_FIELD_S32(0x20)

/* TTC treadmill */
#define /*0x0F4*/ oTTCTreadmillUnkF4 OBJECT_FIELD_S16P(0x1B)
#define /*0x0F8*/ oTTCTreadmillUnkF8 OBJECT_FIELD_S16P(0x1C)
#define /*0x0FC*/ oTTCTreadmillSpeed OBJECT_FIELD_F32(0x1D)
#define /*0x100*/ oTTCTreadmillTargetSpeed OBJECT_FIELD_F32(0x1E)
#define /*0x104*/ oTTCTotalTimeUntilSwitch OBJECT_FIELD_S32(0x1F)

/* TTC moving bar */
#define /*0x0F4*/ oTTCMovingBarTotalWaitTime OBJECT_FIELD_S32(0x1B)
#define /*0x0F8*/ oTTCMovingBarStoppedTimer OBJECT_FIELD_S32(0x1C)
#define /*0x0FC*/ oTTCMovingBarOffset OBJECT_FIELD_F32(0x1D)
#define /*0x100*/ oTTCMovingBarSpeed OBJECT_FIELD_F32(0x1E)
#define /*0x104*/ oTTCMovingBarStartOffset OBJECT_FIELD_F32(0x1F)

/* TTC cog */
#define /*0x0F4*/ oTTCCogDir OBJECT_FIELD_F32(0x1B)
#define /*0x0F8*/ oTTCCogSpeed OBJECT_FIELD_F32(0x1C)
#define /*0x0FC*/ oTTCCogTargetSpeed OBJECT_FIELD_F32(0x1D)

/* TTC pit block */
#define /*0x0F4*/ oTTCPitBlockPeakY OBJECT_FIELD_F32(0x1B)
#define /*0x0F8*/ oTTCPitBlockDir OBJECT_FIELD_S32(0x1C)
#define /*0x0FC*/ oTTCPitBlockWaitTime OBJECT_FIELD_S32(0x1D)

/* TTC elevator */
#define /*0x0F4*/ oTTCElevatorDir OBJECT_FIELD_F32(0x1B)
#define /*0x0F8*/ oTTCElevatorPeakY OBJECT_FIELD_F32(0x1C)
#define /*0x0FC*/ oTTCElevatorMoveTime OBJECT_FIELD_S32(0x1D)

/* TTC 2D rotator */
#define /*0x0F4*/ oTTC2DRotatorTimeUntilIncrement OBJECT_FIELD_S32(0x1B)
#define /*0x0F8*/ oTTC2DRotatorTargetYaw OBJECT_FIELD_S32(0x1C)
#define /*0x0FC*/ oTTC2DRotatorIncrement OBJECT_FIELD_S32(0x1D)
#define /*0x104*/ oTTC2DRotatorRandomDirTimer OBJECT_FIELD_S32(0x1F)
#define /*0x108*/ oTTC2DRotatorSpeed OBJECT_FIELD_S32(0x20)

/* TTC spinner */
#define /*0x0F4*/ oTTCSpinnerDir OBJECT_FIELD_S32(0x1B)
#define /*0x0F8*/ oTTCChangeDirTimer OBJECT_FIELD_S32(0x1C)

/* Mr. Blizzard */
#define /*0x0F4*/ oMrBlizzardUnkF4 OBJECT_FIELD_F32(0x1B)
#define /*0x0F8*/ oMrBlizzardUnkF8 OBJECT_FIELD_OBJECT(0x1C)
#define /*0x0FC*/ oMrBlizzardUnkFC OBJECT_FIELD_F32(0x1D)
#define /*0x100*/ oMrBlizzardUnk100 OBJECT_FIELD_S32(0x1E)
#define /*0x104*/ oMrBlizzardUnk104 OBJECT_FIELD_F32(0x1F)
#define /*0x108*/ oMrBlizzardUnk108 OBJECT_FIELD_F32(0x20)
#define /*0x10C*/ oMrBlizzardUnk10C OBJECT_FIELD_F32(0x21)
#define /*0x110*/ oMrBlizzardUnk110 OBJECT_FIELD_S32(0x22)
#define /*0x1AC*/ oMrBlizzardUnk1AC OBJECT_FIELD_S32(0x49)

/* Back-and-forth platform */
#define /*0x0F4*/ oBackAndForthPlatformUnkF4 OBJECT_FIELD_F32(0x1B)
#define /*0x0F8*/ oBackAndForthPlatformUnkF8 OBJECT_FIELD_F32(0x1C)
#define /*0x0FC*/ oBackAndForthPlatformUnkFC OBJECT_FIELD_F32(0x1D)
#define /*0x100*/ oBackAndForthPlatformUnk100 OBJECT_FIELD_F32(0x1E)

// rename
/* Floor switch press animation */
#define /*0x0F4*/ oFloorSwitchPressAnimationUnkF4 OBJECT_FIELD_S32(0x1B)
#define /*0x0F8*/ oFloorSwitchPressAnimationUnkF8 OBJECT_FIELD_S32(0x1C)
#define /*0x0FC*/ oFloorSwitchPressAnimationUnkFC OBJECT_FIELD_S32(0x1D)
#define /*0x100*/ oFloorSwitchPressAnimationUnk100 OBJECT_FIELD_S32(0x1E)

/* Activated back and forth platform */
#define /*0x0F4*/ oActivatedBackAndForthPlatformMaxOffset OBJECT_FIELD_F32(0x1B)
#define /*0x0F8*/ oActivatedBackAndForthPlatformOffset OBJECT_FIELD_F32(0x1C)
#define /*0x0FC*/ oActivatedBackAndForthPlatformVel OBJECT_FIELD_F32(0x1D)
#define /*0x100*/ oActivatedBackAndForthPlatformCountdown OBJECT_FIELD_S32(0x1E)
#define /*0x104*/ oActivatedBackAndForthPlatformStartYaw OBJECT_FIELD_S32(0x1F)
#define /*0x108*/ oActivatedBackAndForthPlatformVertical OBJECT_FIELD_S32(0x20)
#define /*0x10C*/ oActivatedBackAndForthPlatformFlipRotation OBJECT_FIELD_S32(0x21)

/* Spinning heart */
#define /*0x0F4*/ oSpinningHeartTotalSpin OBJECT_FIELD_S32(0x1B)
#define /*0x0F8*/ oSpinningHeartPlayedSound OBJECT_FIELD_S32(0x1C)

// check name
/* Cannon barrel bubbles */
#define /*0x0F4*/ oCannonBarrelBubblesUnkF4 OBJECT_FIELD_F32(0x1B)

/* Cannon */
#define /*0x0F4*/ oCannonUnkF4 OBJECT_FIELD_S32(0x1B)
#define /*0x0F8*/ oCannonUnkF8 OBJECT_FIELD_S32(0x1C)
#define /*0x0FC*/ oCannonUnkFC OBJECT_FIELD_S32(0x1D)
#define /*0x100*/ oCannonUnk100 OBJECT_FIELD_S32(0x1E)

/* Eel */
#define /*0x0F4*/ oUnagiUnkF4 OBJECT_FIELD_F32(0x1B)
#define /*0x0F8*/ oUnagiUnkF8 OBJECT_FIELD_F32(0x1C)
#define /*0x0FC*/ oUnagiUnkFC OBJECT_FIELD_S16P(0x1D)
#define /*0x100*/ oUnagiUnk100 OBJECT_FIELD_S16P(0x1E)
#define /*0x104*/ oUnagiUnk104 OBJECT_FIELD_S32(0x1F)
#define /*0x108*/ oUnagiUnk108 OBJECT_FIELD_S32(0x20)
#define /*0x10C*/ oUnagiUnk10C OBJECT_FIELD_S32(0x21)
#define /*0x110*/ oUnagiUnk110 OBJECT_FIELD_F32(0x22)
#define /*0x1B0*/ oUnagiUnk1AC OBJECT_FIELD_F32(0x49)
#define /*0x1B0*/ oUnagiUnk1B0 OBJECT_FIELD_S16(0x4A, 0)
#define /*0x1B2*/ oUnagiUnk1B2 OBJECT_FIELD_S16(0x4A, + 1)

/* Dorrie */
#define /*0x0F4*/ oDorrieDistToHome OBJECT_FIELD_F32(0x1B)
#define /*0x0F8*/ oDorrieOffsetY OBJECT_FIELD_F32(0x1C)
#define /*0x0FC*/ oDorrieVelY OBJECT_FIELD_F32(0x1D)
#define /*0x100*/ oDorrieForwardDistToMario OBJECT_FIELD_F32(0x1E)
#define /*0x104*/ oDorrieYawVel OBJECT_FIELD_S32(0x1F)
#define /*0x10C*/ oDorrieLiftingMario OBJECT_FIELD_S32(0x21)
#define /*0x1AC*/ oDorrieGroundPounded OBJECT_FIELD_S16(0x49, 0)
#define /*0x1AE*/ oDorrieAngleToHome OBJECT_FIELD_S16(0x49, + 1)
#define /*0x1B0*/ oDorrieNeckAngle OBJECT_FIELD_S16(0x4A, 0)
#define /*0x1B2*/ oDorrieHeadRaiseSpeed OBJECT_FIELD_S16(0x4A, + 1)

/* Haunted chair */
#define /*0x0F4*/ oHauntedChairUnkF4 OBJECT_FIELD_S32(0x1B)
#define /*0x0F8*/ oHauntedChairUnkF8 OBJECT_FIELD_F32(0x1C)
#define /*0x0FC*/ oHauntedChairUnkFC OBJECT_FIELD_F32(0x1D)
#define /*0x100*/ oHauntedChairUnk100 OBJECT_FIELD_S32P(0x1E)
#define /*0x104*/ oHauntedChairUnk104 OBJECT_FIELD_S32(0x1F)

/* Bookend */
#define /*0x0F4*/ oBookendUnkF4 OBJECT_FIELD_S32(0x1B)
#define /*0x0F8*/ oBookendUnkF8 OBJECT_FIELD_S32(0x1C)

/* Book switch manager */
#define /*0x0F4*/ oBookSwitchManagerUnkF4 OBJECT_FIELD_S32(0x1B)
#define /*0x0F8*/ oBookSwitchManagerUnkF8 OBJECT_FIELD_S32(0x1C)

/* Book switch */
#define /*0x0F4*/ oBookSwitchUnkF4 OBJECT_FIELD_F32(0x1B)

/* Fire piranha plant */
#define /*0x0F4*/ oFirePiranhaPlantNeutralScale OBJECT_FIELD_F32(0x1B)
#define /*0x0F8*/ oFirePiranhaPlantScale OBJECT_FIELD_F32(0x1C)
#define /*0x0FC*/ oFirePiranhaPlantActive OBJECT_FIELD_S32(0x1D)
#define /*0x100*/ oFirePiranhaPlantDeathSpinTimer OBJECT_FIELD_S32(0x1E)
#define /*0x104*/ oFirePiranhaPlantDeathSpinVel OBJECT_FIELD_F32(0x1F)

// Rename
/* Small piranha flame */
#define /*0x0F4*/ oSmallPiranhaFlameUnkF4 OBJECT_FIELD_F32(0x1B)
#define /*0x0F8*/ oSmallPiranhaFlameUnkF8 OBJECT_FIELD_F32(0x1C)
#define /*0x0FC*/ oSmallPiranhaFlameUnkFC OBJECT_FIELD_S32(0x1D)
#define /*0x100*/ oSmallPiranhaFlameUnk100 OBJECT_FIELD_S32(0x1E)
#define /*0x104*/ oSmallPiranhaFlameUnk104 OBJECT_FIELD_F32(0x1F)

/* Fire spitter */
#define /*0x0F4*/ oFireSpitterScaleVel OBJECT_FIELD_F32(0x1B)

/* Snufit */
#define /*0x0F4*/ oSnufitUnkF4 OBJECT_FIELD_S32(0x1B)
#define /*0x0F8*/ oSnufitUnkF8 OBJECT_FIELD_F32(0x1C)
#define /*0x100*/ oSnufitUnk100 OBJECT_FIELD_S32(0x1E)
#define /*0x104*/ oSnufitUnk104 OBJECT_FIELD_S32(0x1F)
#define /*0x108*/ oSnufitUnk108 OBJECT_FIELD_S32(0x20)
#define /*0x10C*/ oSnufitUnk10C OBJECT_FIELD_S32(0x21)
#define /*0x1AE*/ oSnufitUnk1AE OBJECT_FIELD_S16(0x49, + 1)
#define /*0x1B0*/ oSnufitUnk1B0 OBJECT_FIELD_S16(0x4A, 0)
#define /*0x1B2*/ oSnufitUnk1B2 OBJECT_FIELD_S16(0x4A, + 1)

/* Horizontal grindel */
#define /*0x0F4*/ oHorizontalGrindelTargetYaw OBJECT_FIELD_S32(0x1B)
#define /*0x0F8*/ oHorizontalGrindelDistToHome OBJECT_FIELD_F32(0x1C)
#define /*0x0FC*/ oHorizontalGrindelOnGround OBJECT_FIELD_S32(0x1D)

/* Eyerok boss */
#define /*0x0F8*/ oEyerokBossNumHands OBJECT_FIELD_S32(0x1C)
#define /*0x0FC*/ oEyerokBossUnkFC OBJECT_FIELD_S32(0x1D)
#define /*0x100*/ oEyerokBossActiveHand OBJECT_FIELD_S32(0x1E)
#define /*0x104*/ oEyerokBossUnk104 OBJECT_FIELD_S32(0x1F)
#define /*0x108*/ oEyerokBossUnk108 OBJECT_FIELD_F32(0x20)
#define /*0x10C*/ oEyerokBossUnk10C OBJECT_FIELD_F32(0x21)
#define /*0x110*/ oEyerokBossUnk110 OBJECT_FIELD_F32(0x22)
#define /*0x1AC*/ oEyerokBossUnk1AC OBJECT_FIELD_S32(0x49)

/* Eyerok hand */
#define /*0x0F4*/ oEyerokHandWakeUpTimer OBJECT_FIELD_S32(0x1B)
#define /*0x0F8*/ oEyerokReceivedAttack OBJECT_FIELD_S32(0x1C)
#define /*0x0FC*/ oEyerokHandUnkFC OBJECT_FIELD_S32(0x1D)
#define /*0x100*/ oEyerokHandUnk100 OBJECT_FIELD_S32(0x1E)

/* Klepto */
#define /*0x0F4*/ oKleptoDistanceToTarget OBJECT_FIELD_F32(0x1B)
#define /*0x0F8*/ oKleptoUnkF8 OBJECT_FIELD_F32(0x1C)
#define /*0x0FC*/ oKleptoUnkFC OBJECT_FIELD_F32(0x1D)
#define /*0x100*/ oKleptoSpeed OBJECT_FIELD_F32(0x1E)
#define /*0x104*/ oKleptoStartPosX OBJECT_FIELD_F32(0x1F)
#define /*0x108*/ oKleptoStartPosY OBJECT_FIELD_F32(0x20)
#define /*0x10C*/ oKleptoStartPosZ OBJECT_FIELD_F32(0x21)
#define /*0x110*/ oKleptoTimeUntilTargetChange OBJECT_FIELD_S32(0x22)
#define /*0x1AC*/ oKleptoTargetNumber OBJECT_FIELD_S16(0x49, 0)
#define /*0x1AE*/ oKleptoUnk1AE OBJECT_FIELD_S16(0x49, + 1)
#define /*0x1B0*/ oKleptoUnk1B0 OBJECT_FIELD_S16(0x4A, 0)
#define /*0x1B2*/ oKleptoYawToTarget OBJECT_FIELD_S16(0x4A, + 1)

/* Bird */
#define /*0x0F4*/ oBirdSpeed OBJECT_FIELD_F32(0x1B)
#define /*0x0F8*/ oBirdPitch OBJECT_FIELD_S32(0x1C)
#define /*0x0FC*/ oBirdYaw OBJECT_FIELD_S32(0x1D)

/* Racing penguin */
#define /*0x0F4*/ oRacingPenguinInitTextCooldown OBJECT_FIELD_S32(0x1B)
// 0x1D-0x21 reserved for pathing
#define /*0x110*/ oRacingPenguinWeightedNewTargetSpeed OBJECT_FIELD_F32(0x22)
#define /*0x1AC*/ oRacingPenguinFinalTextbox OBJECT_FIELD_S16(0x49, 0)
#define /*0x1AE*/ oRacingPenguinMarioWon OBJECT_FIELD_S16(0x49, + 1)
#define /*0x1B0*/ oRacingPenguinReachedBottom OBJECT_FIELD_S16(0x4A, 0)
#define /*0x1B2*/ oRacingPenguinMarioCheated OBJECT_FIELD_S16(0x4A, + 1)

/* Clam */
#define /*0x0F4*/ oClamUnkF4 OBJECT_FIELD_S32(0x1B)

/* Skeeter */
#define /*0x0F4*/ oSkeeterTargetAngle OBJECT_FIELD_S32(0x1B)
#define /*0x0F8*/ oSkeeterUnkF8 OBJECT_FIELD_S32(0x1C)
#define /*0x0FC*/ oSkeeterUnkFC OBJECT_FIELD_F32(0x1D)
#define /*0x100*/ oSkeeterWaitTime OBJECT_FIELD_S32(0x1E)
#define /*0x1AC*/ oSkeeterUnk1AC OBJECT_FIELD_S16(0x49, 0)

/* Swing platform */
#define /*0x0F4*/ oSwingPlatformAngle OBJECT_FIELD_F32(0x1B)
#define /*0x0F8*/ oSwingPlatformSpeed OBJECT_FIELD_F32(0x1C)

/* Donut platform spawner */
#define /*0x0F4*/ oDonutPlatformSpawnerSpawnedPlatforms OBJECT_FIELD_S32(0x1B)

/* DDD pole */
#define /*0x0F4*/ oDDDPoleVel OBJECT_FIELD_F32(0x1B)
#define /*0x0F8*/ oDDDPoleMaxOffset OBJECT_FIELD_F32(0x1C)
#define /*0x0FC*/ oDDDPoleOffset OBJECT_FIELD_F32(0x1D)

/* Triplet butterfly */
#define /*0x0F4*/ oTripletButterflyScale OBJECT_FIELD_F32(0x1B)
#define /*0x0F8*/ oTripletButterflySpeed OBJECT_FIELD_F32(0x1C)
#define /*0x0FC*/ oTripletButterflyBaseYaw OBJECT_FIELD_F32(0x1D)
#define /*0x100*/ oTripletButterflyTargetPitch OBJECT_FIELD_S32(0x1E)
#define /*0x104*/ oTripletButterflyTargetYaw OBJECT_FIELD_S32(0x1F)
#define /*0x108*/ oTripletButterflyType OBJECT_FIELD_S32(0x20)
#define /*0x10C*/ oTripletButterflyModel OBJECT_FIELD_S32(0x21)
#define /*0x110*/ oTripletButterflySelectedButterfly OBJECT_FIELD_S32(0x22)
#define /*0x1AC*/ oTripletButterflyScalePhase OBJECT_FIELD_S32(0x49)

/* Bubba */
#define /*0x0F4*/ oBubbaUnkF4 OBJECT_FIELD_F32(0x1B)
#define /*0x0F8*/ oBubbaUnkF8 OBJECT_FIELD_S32(0x1C)
#define /*0x0FC*/ oBubbaUnkFC OBJECT_FIELD_S32(0x1D)
#define /*0x100*/ oBubbaUnk100 OBJECT_FIELD_S32(0x1E)
#define /*0x104*/ oBubbaUnk104 OBJECT_FIELD_S32(0x1F)
#define /*0x108*/ oBubbaUnk108 OBJECT_FIELD_F32(0x20)
#define /*0x10C*/ oBubbaUnk10C OBJECT_FIELD_F32(0x21)
#define /*0x1AC*/ oBubbaUnk1AC OBJECT_FIELD_S16(0x49, 0)
#define /*0x1AE*/ oBubbaUnk1AE OBJECT_FIELD_S16(0x49, + 1)
#define /*0x1B0*/ oBubbaUnk1B0 OBJECT_FIELD_S16(0x4A, 0)
#define /*0x1B2*/ oBubbaUnk1B2 OBJECT_FIELD_S16(0x4A, + 1)

#endif
