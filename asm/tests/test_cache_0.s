.set noat
.set noreorder

.include "macros.inc"

glabel test_cache_l0
	lui $t1, 0x8020
	b test_cache_0
	move $t2, $zero
glabel test_cache_m0
	lui $t1, 0x8030
	b test_cache_0
	move $t2, $zero
glabel test_cache_u0
	lui $t1, 0x8020
	b test_cache_0
	li $t2, 0x100
glabel test_cache_v0
	lui $t1, 0x8030
	b test_cache_0
	li $t2, 0x100
test_cache_0:
	li $t0, 32
	sw $t0, ($a2)
	lw $t0, ($a0)
	addu $t2, $t2, $t0
	sll $t2, $t2, 4
	or $t1, $t1, $t2
	li $t6, 0xFFFFFFFF
	move $t2, $zero
	sw $t6, 0x0($t1)
	sw $t6, 0x4($t1)
	sw $t6, 0x8($t1)
	sw $t6, 0xC($t1)
	cache 1, ($t1)
	li $t9, CACHE_TEST_REPS - 1
loop_start:
	sw $zero, 0x0($t1)
	sw $zero, 0x4($t1)
	sw $zero, 0x8($t1)
	sw $zero, 0xC($t1)
	lw $t3, 0x0($t1)
	lw $t4, 0x4($t1)
	lw $t5, 0x8($t1)
	lw $t7, 0xC($t1)
	or $t2, $t2, $t3
	or $t2, $t2, $t4
	or $t2, $t2, $t5
	or $t2, $t2, $t7
	bnez $t9, loop_start
	addiu $t9, $t9, -1
	bnez $t2, c0fail
	nop
	b c0ret
	li $t3, 1
c0fail:
	li $t3, 0
c0ret:
	srl $t1, $t0, 3
	addu $t2, $a1, $t1
	andi $t1, $t0, 7
	sllv $t3, $t3, $t1
	lb $t1, ($t2)
	or $t1, $t1, $t3
	sb $t1, ($t2)
	sltiu $t1, $t0, 0xFF
	beqzl $t1, c0ret2
	li $v0, 1
	li $v0, 0
c0ret2:
	addiu $t0, $t0, 1
	jr $ra
	sw $t0, ($a0)
