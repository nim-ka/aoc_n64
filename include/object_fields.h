#ifndef _OBJECT_FIELDS_H
#define _OBJECT_FIELDS_H


/**
 * The array [0x88, 0x1C8) in struct Object consists of fields that can vary by
 * object type. These macros provide access to these fields.
 */


#define OBJECT_FIELD_U32(index) rawData.asU32[index]
#define OBJECT_FIELD_S32(index) rawData.asS32[index]
#define OBJECT_FIELD_S16(index, subIndex) rawData.asS16[index][subIndex]
#define OBJECT_FIELD_F32(index) rawData.asF32[index]
#define OBJECT_FIELD_ANIMS(index) rawData.asAnims[index]
#define OBJECT_FIELD_SURFACE(index) rawData.asSurface[index]
#define OBJECT_FIELD_VPTR(index) rawData.asVoidPtr[index]


/* Common fields */
#define /*0x088*/ oUnk88 OBJECT_FIELD_S32(0x00)
#define /*0x08C*/ oFlags OBJECT_FIELD_U32(0x01)
#define /*0x090*/ oUnk90 OBJECT_FIELD_S16(0x02, 0)
#define /*0x092*/ oUnk92 OBJECT_FIELD_S16(0x02, 1)
#define /*0x09C*/ oCollectable OBJECT_FIELD_S32(0x05)
#define /*0x0A0*/ oPosX OBJECT_FIELD_F32(0x06)
#define /*0x0A4*/ oPosY OBJECT_FIELD_F32(0x07)
#define /*0x0A8*/ oPosZ OBJECT_FIELD_F32(0x08)
#define /*0x0AC*/ oVelX OBJECT_FIELD_F32(0x09)
#define /*0x0B0*/ oVelY OBJECT_FIELD_F32(0x0A)
#define /*0x0B4*/ oVelZ OBJECT_FIELD_F32(0x0B)
#define /*0x0B8*/ oForwardVel OBJECT_FIELD_F32(0x0C)
#define /*0x0BC*/ oUnkBC OBJECT_FIELD_F32(0x0D)
#define /*0x0C0*/ oUnkC0 OBJECT_FIELD_F32(0x0E)
#define /*0x0C4*/ oAnglePitch OBJECT_FIELD_S32(0x0F)
#define /*0x0C8*/ oAngleYaw OBJECT_FIELD_S32(0x10)
#define /*0x0CC*/ oAngleRoll OBJECT_FIELD_S32(0x11)
#define /*0x0D0*/ oFaceAnglePitch OBJECT_FIELD_S32(0x12)
#define /*0x0D4*/ oFaceAngleYaw OBJECT_FIELD_S32(0x13)
#define /*0x0D8*/ oFaceAngleRoll OBJECT_FIELD_S32(0x14)
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
#define /*0x128*/ oUnk128 OBJECT_FIELD_F32(0x28)
#define /*0x12C*/ oUnk12C OBJECT_FIELD_F32(0x29)
#define /*0x130*/ oInteractType OBJECT_FIELD_U32(0x2A)
#define /*0x134*/ oInteractStatus OBJECT_FIELD_U32(0x2B)
#define /*0x138*/ oUnk138 OBJECT_FIELD_F32(0x2C)
#define /*0x13C*/ oUnk13C OBJECT_FIELD_F32(0x2D)
#define /*0x140*/ oUnk140 OBJECT_FIELD_F32(0x2E)
#define /*0x144*/ oBehParam OBJECT_FIELD_U32(0x2F)
#define /*0x14C*/ oAction OBJECT_FIELD_S32(0x31)
#define /*0x150*/ oUnk150 OBJECT_FIELD_U32(0x32)
#define /*0x154*/ oTimer OBJECT_FIELD_S32(0x33)
#define /*0x158*/ oUnk158 OBJECT_FIELD_F32(0x34)
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
#define /*0x184*/ oUnk184 OBJECT_FIELD_U32(0x3F)
#define /*0x188*/ oUnk188 OBJECT_FIELD_S32(0x40)
#define /*0x18C*/ oPrevAction OBJECT_FIELD_S32(0x41)
#define /*0x190*/ oUnk190 OBJECT_FIELD_U32(0x42)
#define /*0x194*/ oCollisionDistance OBJECT_FIELD_F32(0x43)
#define /*0x198*/ oUnk198 OBJECT_FIELD_S32(0x44)
#define /*0x19C*/ oDrawingDistance OBJECT_FIELD_F32(0x45)
#define /*0x1A0*/ oUnk1A0 OBJECT_FIELD_S32(0x46)
#define /*0x1A8*/ oUnk1A8 OBJECT_FIELD_U32(0x48)
#define /*0x1AC*/ oUnk1AC OBJECT_FIELD_VPTR(0x49)
#define /*0x1B0*/ oUnk1B0 OBJECT_FIELD_S32(0x4A)
#define /*0x1B4*/ oUnk1B4 OBJECT_FIELD_U32(0x4B)
#define /*0x1B8*/ oUnk1B8 OBJECT_FIELD_S16(0x4C, 0)
#define /*0x1BA*/ oUnk1BA OBJECT_FIELD_S16(0x4C, 1)
#define /*0x1C0*/ oUnk1C0 OBJECT_FIELD_SURFACE(0x4E)

/* All uses of these should be removed as soon as object type is known */
#define /*0x0F4*/ oUnknownUnkF4_S32 OBJECT_FIELD_S32(0x1B)
#define /*0x0FC*/ oUnknownUnkFC_VPtr OBJECT_FIELD_VPTR(0x1D)
#define /*0x100*/ oUnknownUnk100_VPtr OBJECT_FIELD_VPTR(0x1E)
#define /*0x104*/ oUnknownUnk104_S32 OBJECT_FIELD_S32(0x1F)
#define /*0x108*/ oUnknownUnk108_S32 OBJECT_FIELD_S32(0x20)
#define /*0x108*/ oUnknownUnk108_F32 OBJECT_FIELD_F32(0x20)
#define /*0x10C*/ oUnknownUnk10C_S32 OBJECT_FIELD_S32(0x21)
#define /*0x10C*/ oUnknownUnk10C_F32 OBJECT_FIELD_F32(0x21)
#define /*0x110*/ oUnknownUnk110_F32 OBJECT_FIELD_F32(0x22)

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
#define /*0x0F4*/ oStarSelectorUnkF4 OBJECT_FIELD_S32(0x1B)
#define /*0x0F8*/ oStarSelectorUnkF8 OBJECT_FIELD_S32(0x1C)
#define /*0x108*/ oStarSelectorSize OBJECT_FIELD_F32(0x20)

/* Star select icon */
#define /*0x0F4*/ oStarSelectIconUnkF4 OBJECT_FIELD_S32(0x1B)
#define /*0x108*/ oStarSelectIconUnk108 OBJECT_FIELD_F32(0x20)

/* Sound effect */
#define /*0x0F4*/ oSoundEffectUnkF4 OBJECT_FIELD_S32(0x1B)

/* Main menu button */
#define /*0x0F4*/ oMainMenuButtonUnkF4 OBJECT_FIELD_S32(0x1B)
#define /*0x0F8*/ oMainMenuButtonUnkF8 OBJECT_FIELD_S32(0x1C)
#define /*0x0FC*/ oMainMenuButtonUnkFC OBJECT_FIELD_F32(0x1D)
#define /*0x100*/ oMainMenuButtonUnk100 OBJECT_FIELD_F32(0x1E)
#define /*0x104*/ oMainMenuButtonUnk104 OBJECT_FIELD_F32(0x1F)
#define /*0x108*/ oMainMenuButtonUnk108 OBJECT_FIELD_F32(0x20)
#define /*0x10C*/ oMainMenuButtonUnk10C OBJECT_FIELD_S32(0x21)

/* Toad message */
#define /*0x108*/ oToadMessageUnk108 OBJECT_FIELD_U32(0x20)
#define /*0x10C*/ oToadMessageUnk10C OBJECT_FIELD_S32(0x21)
#define /*0x110*/ oToadMessageUnk110 OBJECT_FIELD_S32(0x22)

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

#endif
