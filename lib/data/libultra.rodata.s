.include "macros.inc"

.section .rodata

glabel D_80338750
	.incbin "bin/rodata.bin", 0x3CE0, 0x800

glabel D_80338F50
	.incbin "bin/rodata.bin", 0x44E0, 0x2C0
glabel audio_data_end
