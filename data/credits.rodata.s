.include "macros.inc"
.include "globals.inc"

.section .rodata

# 0x80334A70

# Unknown region 0EFA50-0F4210 [47C0]

#credits
glabel CreditsList
	.incbin "bin/rodata.bin", 0x20, 0x3BC

glabel jtbl_80334E4C
	.incbin "bin/rodata.bin", 0x3DC, 0x94

glabel jtbl_80334EE0
	.incbin "bin/rodata.bin", 0x470, 0x9C

glabel jtbl_80334F7C
	.incbin "bin/rodata.bin", 0x50C, 0x64

glabel jtbl_80334FE0
	.incbin "bin/rodata.bin", 0x570, 0x14

glabel jtbl_80334FF4
	.incbin "bin/rodata.bin", 0x584, 0x1C
