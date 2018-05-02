.include "macros.inc"
.include "globals.inc"

.section .data

#skybox (might be the incorrect start)
glabel D_8032FF80
	.incbin "bin/sm64.j.0EADAC.bin", 0x1D4, 0x4

glabel D_8032FF84
	.incbin "bin/sm64.j.0EADAC.bin", 0x1D8, 0x4

glabel D_8032FF88
	.incbin "bin/sm64.j.0EADAC.bin", 0x1DC, 0x18

glabel D_8032FFA0
	.incbin "bin/sm64.j.0EADAC.bin", 0x1F4, 0x28

glabel gSkyboxColors
	.incbin "bin/sm64.j.0EADAC.bin", 0x21C, 0x8
