.include "macros.inc"
.include "globals.inc"

.section .rodata

#ingame menu
glabel D_80336FA0
	.incbin "bin/rodata.bin", 0x2530, 0x78

glabel jtbl_80337018
	.incbin "bin/rodata.bin", 0x25A8, 0xCC

glabel D_803370E4
	.incbin "bin/rodata.bin", 0x2674, 0x8

glabel D_803370EC
	.incbin "bin/rodata.bin", 0x267C, 0x8

glabel jtbl_803370F4
	.incbin "bin/rodata.bin", 0x2684, 0x3C
