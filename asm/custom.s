.set noat
.set noreorder

.include "macros.inc"

glabel a
	.word 0x00000000

glabel str
	.ascii "0123456789"
	.word 0x00000000

glabel custom_entry
	addiu $sp, $sp, -8
	sw $ra, ($sp)
	lui $t0, %hi(a)
	lw $t1, %lo(a)($t0)
	addiu $t1, $t1, 1
	sw $t1, %lo(a)($t0)
	li $a0, 50
	li $a1, 100
	lui $a2, %hi(str)
	jal fb_print_str
	addiu $a2, $a2, %lo(str)
	lw $ra, ($sp)
	jr $ra
	addiu $sp, $sp, 8
