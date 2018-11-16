
.include "macros.inc"


.section .data

glabel D_8032B800
	.incbin "bin/sm64.j.0E6800.rsp.audio.bin"

# Unknown region 0E7000-0E79F0 [9F0]
	.incbin "bin/sm64.j.0E7000.bin", 0x0, 0x620
