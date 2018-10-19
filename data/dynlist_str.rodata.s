.include "macros.inc"

.section .rodata

# These final four addresses are only referenced in "rodata_801A8050.s" 
# They look like residue from the compiler, so parts of that file were probably in C...
glabel gStr_simpleg_1 # D_801B88D0
	.asciiz "simpleg"
	.balign 4, 0

glabel gStr_simple	# D_801B88D8
	.asciiz "simple"
	.balign 4, 0

glabel gStr_simpleg_2	# D_801B88E0
	.asciiz "simpleg"
	.balign 4, 0

glabel gStr_simpleg_3	# D_801B88E8
	.asciiz "simpleg"
	.balign 4, 0

# 801B88F0
