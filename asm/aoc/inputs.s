.include "macros.inc"

.section .rodata

.macro aoc_input num
	glabel aoc_input_day\num\()
		.incbin "asm/aoc/inputs/\num\().txt"
		.space 0x1000
.endm

aoc_input 1
aoc_input 2
aoc_input 3
aoc_input 4
aoc_input 5
aoc_input 6
aoc_input 7
aoc_input 8
aoc_input 9
aoc_input 10
aoc_input 11
aoc_input 12
aoc_input 13
aoc_input 14
aoc_input 15
aoc_input 16
aoc_input 17
aoc_input 18
aoc_input 19
aoc_input 20
aoc_input 21
aoc_input 22
aoc_input 23
aoc_input 24
aoc_input 25
