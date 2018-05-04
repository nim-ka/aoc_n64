.include "macros.inc"

# Unknown region 271B20-2A42A0 [32780]
glabel D_00271B20
	.incbin "bin/sm64.j.271B20.bin", 0x0, 0x50E4
	.word D_801A82F8
	.incbin "bin/sm64.j.271B20.bin", 0x50E8, 0x5C
	.word D_801A82F4
	.incbin "bin/sm64.j.271B20.bin", 0x5148, 0x2D638
