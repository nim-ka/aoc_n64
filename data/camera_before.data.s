
.include "macros.inc"
.include "globals.inc"

.section .data

# camera
glabel D_8032CFC0
	.incbin "bin/sm64.j.0E7AE8.bin", 0x4D8, 0x4

glabel D_8032CFC4
	.incbin "bin/sm64.j.0E7AE8.bin", 0x4DC, 0x4

glabel D_8032CFC8
	.incbin "bin/sm64.j.0E7AE8.bin", 0x4E0, 0x4

glabel D_8032CFCC
	.incbin "bin/sm64.j.0E7AE8.bin", 0x4E4, 0x4

glabel D_8032CFD0
	.incbin "bin/sm64.j.0E7AE8.bin", 0x4E8, 0x4

glabel D_8032CFD4
	.incbin "bin/sm64.j.0E7AE8.bin", 0x4EC, 0x4

glabel D_8032CFD8
	.incbin "bin/sm64.j.0E7AE8.bin", 0x4F0, 0x4

glabel D_8032CFDC
	.incbin "bin/sm64.j.0E7AE8.bin", 0x4F4, 0x10

glabel D_8032CFEC
	.incbin "bin/sm64.j.0E7AE8.bin", 0x504, 0x4

glabel D_8032CFF0
	.incbin "bin/sm64.j.0E7AE8.bin", 0x508, 0x4

glabel D_8032CFF4
	.incbin "bin/sm64.j.0E7AE8.bin", 0x50C, 0x4

glabel D_8032CFF8
	.incbin "bin/sm64.j.0E7AE8.bin", 0x510, 0x4

glabel D_8032CFFC
	.incbin "bin/sm64.j.0E7AE8.bin", 0x514, 0x4

glabel D_8032D000
	.word D_8033B1B0

glabel D_8032D004
	.incbin "bin/sm64.j.0E7AE8.bin", 0x51C, 0x8

glabel D_8032D00C
	.incbin "bin/sm64.j.0E7AE8.bin", 0x524, 0x3C

glabel TableCameraTransitions
	.word NULL
	.word CameraChange01
	.word CameraChange02
	.word CameraChange03
	.word CameraChange040710
	.word CameraChange05
	.word CameraChange06
	.word CameraChange040710
	.word CameraChange08
	.word CameraChange090F
	.word CameraChange0A
	.word CameraChange0B
	.word CameraChange0C
	.word CameraChange0D
	.word CameraChange0E
	.word CameraChange090F
	.word CameraChange040710
	.word CameraChange11
