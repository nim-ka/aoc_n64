
.include "macros.inc"
.include "globals.inc"

.section .data

glabel D_8032C6A0
	.incbin "bin/sm64.j.0E7000.bin", 0x6A0, 0x4

glabel gPlayer1Controller
	.incbin "bin/sm64.j.0E7000.bin", 0x6A4, 0x4

glabel D_8032C6A8
	.incbin "bin/sm64.j.0E7000.bin", 0x6A8, 0x4

glabel gPlayer2Controller
	.incbin "bin/sm64.j.0E7000.bin", 0x6AC, 0x4

glabel gDemoInputs
	.incbin "bin/sm64.j.0E7000.bin", 0x6B0, 0x4

glabel gDemoInputListID
	.incbin "bin/sm64.j.0E7000.bin", 0x6B4, 0x4

glabel gRecordedDemoTimer
	.incbin "bin/sm64.j.0E7000.bin", 0x6B8, 0x1

glabel gRecordedDemoStickX
	.incbin "bin/sm64.j.0E7000.bin", 0x6B9, 0x1

glabel gRecordedDemoStickY
	.incbin "bin/sm64.j.0E7000.bin", 0x6BA, 0x1

glabel gRecordedDemoButton
	.incbin "bin/sm64.j.0E7000.bin", 0x6BB, 0x5
