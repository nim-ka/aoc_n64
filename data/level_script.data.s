.include "macros.inc"


.section .data

# level script
glabel D_8038B8B0 # scriptStack
	.word D_8038BDA0

glabel D_8038B8B4 # pushStack
	.word NULL

glabel LevelScriptJumpTable
	.word LevelScript00
	.word LevelScript01
	.word LevelScript02
	.word LevelScript03
	.word LevelScript04
	.word LevelScript05
	.word LevelScript06
	.word LevelScript07
	.word LevelScript08
	.word LevelScript09
	.word LevelScript0A
	.word LevelScript0B
	.word LevelScript0C
	.word LevelScript0D
	.word LevelScript0E
	.word LevelScript0F
	.word LevelScript10
	.word LevelScript11
	.word LevelScript12
	.word LevelScript13
	.word LevelScript14
	.word LevelScript15
	.word LevelScript16
	.word LevelScript17
	.word LevelScript18
	.word LevelScript19
	.word LevelScript1A
	.word LevelScript1B
	.word LevelScript1C
	.word LevelScript1D
	.word LevelScript1E
	.word LevelScript1F
	.word LevelScript20
	.word LevelScript21
	.word LevelScript22
	.word LevelScript23
	.word LevelScript24
	.word LevelScript25
	.word LevelScript26
	.word LevelScript27
	.word LevelScript28
	.word LevelScript29
	.word LevelScript2A
	.word LevelScript2B
	.word LevelScript2C
	.word LevelScript2D
	.word LevelScript2E
	.word LevelScript2F
	.word LevelScript30
	.word LevelScript31
	.word LevelScript32
	.word LevelScript33
	.word LevelScript34
	.word LevelScript35
	.word LevelScript36
	.word LevelScript37
	.word LevelScript38
	.word LevelScript39
	.word LevelScript3A
	.word LevelScript3B
	.word LevelScript3C
	.word 0x0

