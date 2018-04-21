
.include "macros.inc"
.include "globals.inc"

.section .data

#mario_actions_submerged
glabel D_8032CDD0
	.incbin "bin/sm64.j.0E7AE8.bin", 0x2E8, 0x4

glabel D_8032CDD4
	.incbin "bin/sm64.j.0E7AE8.bin", 0x2EC, 0x4

glabel D_8032CDD8
	.incbin "bin/sm64.j.0E7AE8.bin", 0x2F0, 0x8
