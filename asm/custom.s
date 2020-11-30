.set noat
.set noreorder

.include "macros.inc"

glabel a
	.word 0x00000000

glabel str
	.ascii "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	.word 0x00000000

glabel custom_entry
	addiu $sp, $sp, -16
	sw $ra, 16($sp)
	lui $t0, %hi(a)
	lw $t1, %lo(a)($t0)
	addiu $t1, $t1, 1
	sw $t1, %lo(a)($t0)
	li $t0, 36
	divu $t1, $t0
	nop
	nop
	mfhi $t0
	li $a0, 7
	li $a1, 10
	lui $a2, %hi(str)
	addiu $a2, $a2, %lo(str)
	jal fb_print_str
	addu $a2, $a2, $t0
	li $a0, 7
	li $a1, 11
	lui $a2, %hi(str)
	jal fb_print_str
	addiu $a2, $a2, %lo(str)
	lw $ra, 16($sp)
	jr $ra
	addiu $sp, $sp, 16
