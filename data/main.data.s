
.include "macros.inc"
.include "globals.inc"

.section .data

# main
glabel D_8032C620
	.incbin "bin/sm64.j.0E7000.bin", 0x620, 0x4

glabel D_8032C624
	.incbin "bin/sm64.j.0E7000.bin", 0x624, 0x4

glabel D_8032C628
	.incbin "bin/sm64.j.0E7000.bin", 0x628, 0x4

glabel D_8032C62C
	.incbin "bin/sm64.j.0E7000.bin", 0x62C, 0x4

glabel D_8032C630
	.incbin "bin/sm64.j.0E7000.bin", 0x630, 0x4

glabel D_8032C634
	.incbin "bin/sm64.j.0E7000.bin", 0x634, 0x4

glabel D_8032C638
	.incbin "bin/sm64.j.0E7000.bin", 0x638, 0x4

glabel D_8032C63C
	.incbin "bin/sm64.j.0E7000.bin", 0x63C, 0x4

glabel D_8032C640
	.incbin "bin/sm64.j.0E7000.bin", 0x640, 0x4

glabel gResetTimer
	.incbin "bin/sm64.j.0E7000.bin", 0x644, 0x4

glabel D_8032C648
	.incbin "bin/sm64.j.0E7000.bin", 0x648, 0x4

glabel D_8032C64C
	.incbin "bin/sm64.j.0E7000.bin", 0x64C, 0x4

glabel D_8032C650
	.incbin "bin/sm64.j.0E7000.bin", 0x650, 0x4

glabel D_8032C654
	.incbin "bin/sm64.j.0E7000.bin", 0x654, 0x4

glabel gPrintDebugInfo
	.incbin "bin/sm64.j.0E7000.bin", 0x658, 0x4

glabel D_8032C65C
	.incbin "bin/sm64.j.0E7000.bin", 0x65C, 0x10

glabel D_8032C66C
	.incbin "bin/sm64.j.0E7000.bin", 0x66C, 0x10

glabel D_8032C67C
	.incbin "bin/sm64.j.0E7000.bin", 0x67C, 0x4

glabel D_8032C680
	.incbin "bin/sm64.j.0E7000.bin", 0x680, 0x10
