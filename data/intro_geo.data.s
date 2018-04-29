.include "macros.inc"
.include "globals.inc"

.section .data

# 0x801A76F0

# Unknown region 255EC0-268020 [12160]

#intro geo (all data)
glabel D_801A7B30
	.incbin "bin/sm64.j.255EC0.bin", 0x440, 0x10

glabel D_801A7B40
	.incbin "bin/sm64.j.255EC0.bin", 0x450, 0x30

glabel D_801A7B70
	.incbin "bin/sm64.j.255EC0.bin", 0x480, 0x30

glabel D_801A7BA0
	.incbin "bin/sm64.j.255EC0.bin", 0x4B0, 0x8

glabel D_801A7BA8
	.incbin "bin/sm64.j.255EC0.bin", 0x4B8, 0xC

glabel D_801A7BB4
	.word D_801A7BA8

glabel D_801A7BB8
	.incbin "bin/sm64.j.255EC0.bin", 0x4C8, 0xC

glabel D_801A7BC4
	.incbin "bin/sm64.j.255EC0.bin", 0x4D4, 0xC
