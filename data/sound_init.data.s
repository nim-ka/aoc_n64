
.include "macros.inc"
.include "globals.inc"

.section .data

# sound_init
glabel D_8032C6C0
	.incbin "bin/sm64.j.0E7000.bin", 0x6C0, 0x4

glabel D_8032C6C4
	.incbin "bin/sm64.j.0E7000.bin", 0x6C4, 0x4

glabel D_8032C6C8
	.incbin "bin/sm64.j.0E7000.bin", 0x6C8, 0x4

glabel D_8032C6CC
	.incbin "bin/sm64.j.0E7000.bin", 0x6CC, 0x4

glabel D_8032C6D0
	.incbin "bin/sm64.j.0E7000.bin", 0x6D0, 0x4

glabel D_8032C6D4
	.incbin "bin/sm64.j.0E7000.bin", 0x6D4, 0x14

glabel D_8032C6E8
	.incbin "bin/sm64.j.0E7000.bin", 0x6E8, 0x8

glabel D_8032C6F0
	.incbin "bin/sm64.j.0E7000.bin", 0x6F0, 0x90

glabel D_8032C780
	.incbin "bin/sm64.j.0E7000.bin", 0x780, 0x10
