
.include "macros.inc"
.include "globals.inc"

.section .data

#interaction
glabel TableInteractions
.word 0x00000010, InteractionCoin
.word 0x00010000, InteractionHealth
.word 0x00001000, InteractionStar
.word 0x08000000, InteractionWarpShrink
.word 0x00002000, InteractionWarpHole
.word 0x00000800, InteractionWarpDoor
.word 0x00000004, InteractionDoor
.word 0x00004000, InteractionCannon
.word 0x40000000, InteractionNormal
.word 0x01000000, InteractionSpin
.word 0x02000000, InteractionFall
.word 0x00000400, InteractionBlowsAway
.word 0x00040000, InteractionFlame
.word 0x10000000, InteractionDamage10000000
.word 0x04000000, InteractionDamage04000000
.word 0x00020000, InteractionBully
.word 0x20000000, InteractionElectrocute
.word 0x00100000, InteractionDamage
.word 0x00200000, InteractionDamage00200000
.word 0x00400000, InteractionDamage00400000
.word 0x00008000, InteractionDamage
.word 0x00000008, InteractionDamageNormal
.word 0x00000040, InteractionPole
.word 0x00000001, InteractionCanHang
.word 0x00000200, InteractionCanBePunched
.word 0x00000080, InteractionDamage
.word 0x00080000, InteractionKoopaShell
.word 0x00000100, InteractionDamage00000100
.word 0x00000020, InteractionNothing
.word 0x00000002, InteractionCanBePickedUp
.word 0x00800000, InteractionMessage

# Unknown region 0E7AE8-0E8048 [560]
glabel D_8032CAE8
	.incbin "bin/sm64.j.0E7AE8.bin", 0x0, 0x24

glabel D_8032CB0C
	.incbin "bin/sm64.j.0E7AE8.bin", 0x24, 0x24

glabel D_8032CB30
	.incbin "bin/sm64.j.0E7AE8.bin", 0x48, 0x4

glabel D_8032CB34
	.incbin "bin/sm64.j.0E7AE8.bin", 0x4C, 0x4

glabel D_8032CB38
	.incbin "bin/sm64.j.0E7AE8.bin", 0x50, 0x8
