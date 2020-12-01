.set noat
.set noreorder

.include "macros.inc"

glabel test_cache_lf
	lui $t1, 0x8020
	b test_cache_f
	move $t2, $zero
glabel test_cache_mf
	lui $t1, 0x8030
	b test_cache_f
	move $t2, $zero
glabel test_cache_uf
	lui $t1, 0x8020
	b test_cache_f
	li $t2, 0x100
glabel test_cache_vf
	lui $t1, 0x8030
	b test_cache_f
	li $t2, 0x100
test_cache_f:
	li $t0, 32
	sw $t0, ($a2)
	lw $t0, ($a0)
	addu $t2, $t2, $t0
	sll $t2, $t2, 4
	or $t1, $t1, $t2
	li $t6, 0xFFFFFFFF
	sw $t6, 0x0($t1)
	sw $t6, 0x4($t1)
	sw $t6, 0x8($t1)
	sw $t6, 0xC($t1)
	cache 1, ($t1)

	sw $zero, 0x0($t1)
	sw $zero, 0x4($t1)
	sw $zero, 0x8($t1)
	sw $zero, 0xC($t1)
	lw $t4, 0x0($t1)
	lw $t5, 0x4($t1)
	lw $t7, 0x8($t1)
	lw $t8, 0xC($t1)
	or $t2, $t4, $t5
	or $t2, $t2, $t7
	or $t2, $t2, $t8
	sw $t6, 0x0($t1)
	sw $t6, 0x4($t1)
	sw $t6, 0x8($t1)
	sw $t6, 0xC($t1)
	lw $t4, 0x0($t1)
	lw $t5, 0x4($t1)
	lw $t7, 0x8($t1)
	lw $t8, 0xC($t1)
	and $t3, $t4, $t5
	and $t3, $t3, $t7
	and $t3, $t3, $t8

	sw $zero, 0x0($t1)
	sw $zero, 0x4($t1)
	sw $zero, 0x8($t1)
	sw $zero, 0xC($t1)
	lw $t4, 0x0($t1)
	lw $t5, 0x4($t1)
	lw $t7, 0x8($t1)
	lw $t8, 0xC($t1)
	or $t2, $t2, $t4
	or $t2, $t2, $t5
	or $t2, $t2, $t7
	or $t2, $t2, $t8
	sw $t6, 0x0($t1)
	sw $t6, 0x4($t1)
	sw $t6, 0x8($t1)
	sw $t6, 0xC($t1)
	lw $t4, 0x0($t1)
	lw $t5, 0x4($t1)
	lw $t7, 0x8($t1)
	lw $t8, 0xC($t1)
	and $t3, $t3, $t4
	and $t3, $t3, $t5
	and $t3, $t3, $t7
	and $t3, $t3, $t8

	sw $zero, 0x0($t1)
	sw $zero, 0x4($t1)
	sw $zero, 0x8($t1)
	sw $zero, 0xC($t1)
	lw $t4, 0x0($t1)
	lw $t5, 0x4($t1)
	lw $t7, 0x8($t1)
	lw $t8, 0xC($t1)
	or $t2, $t2, $t4
	or $t2, $t2, $t5
	or $t2, $t2, $t7
	or $t2, $t2, $t8
	sw $t6, 0x0($t1)
	sw $t6, 0x4($t1)
	sw $t6, 0x8($t1)
	sw $t6, 0xC($t1)
	lw $t4, 0x0($t1)
	lw $t5, 0x4($t1)
	lw $t7, 0x8($t1)
	lw $t8, 0xC($t1)
	and $t3, $t3, $t4
	and $t3, $t3, $t5
	and $t3, $t3, $t7
	and $t3, $t3, $t8

	sw $zero, 0x0($t1)
	sw $zero, 0x4($t1)
	sw $zero, 0x8($t1)
	sw $zero, 0xC($t1)
	lw $t4, 0x0($t1)
	lw $t5, 0x4($t1)
	lw $t7, 0x8($t1)
	lw $t8, 0xC($t1)
	or $t2, $t2, $t4
	or $t2, $t2, $t5
	or $t2, $t2, $t7
	or $t2, $t2, $t8
	sw $t6, 0x0($t1)
	sw $t6, 0x4($t1)
	sw $t6, 0x8($t1)
	sw $t6, 0xC($t1)
	lw $t4, 0x0($t1)
	lw $t5, 0x4($t1)
	lw $t7, 0x8($t1)
	lw $t8, 0xC($t1)
	and $t3, $t3, $t4
	and $t3, $t3, $t5
	and $t3, $t3, $t7
	and $t3, $t3, $t8

	sw $zero, 0x0($t1)
	sw $zero, 0x4($t1)
	sw $zero, 0x8($t1)
	sw $zero, 0xC($t1)
	lw $t4, 0x0($t1)
	lw $t5, 0x4($t1)
	lw $t7, 0x8($t1)
	lw $t8, 0xC($t1)
	or $t2, $t2, $t4
	or $t2, $t2, $t5
	or $t2, $t2, $t7
	or $t2, $t2, $t8
	sw $t6, 0x0($t1)
	sw $t6, 0x4($t1)
	sw $t6, 0x8($t1)
	sw $t6, 0xC($t1)
	lw $t4, 0x0($t1)
	lw $t5, 0x4($t1)
	lw $t7, 0x8($t1)
	lw $t8, 0xC($t1)
	and $t3, $t3, $t4
	and $t3, $t3, $t5
	and $t3, $t3, $t7
	and $t3, $t3, $t8

	sw $zero, 0x0($t1)
	sw $zero, 0x4($t1)
	sw $zero, 0x8($t1)
	sw $zero, 0xC($t1)
	lw $t4, 0x0($t1)
	lw $t5, 0x4($t1)
	lw $t7, 0x8($t1)
	lw $t8, 0xC($t1)
	or $t2, $t2, $t4
	or $t2, $t2, $t5
	or $t2, $t2, $t7
	or $t2, $t2, $t8
	sw $t6, 0x0($t1)
	sw $t6, 0x4($t1)
	sw $t6, 0x8($t1)
	sw $t6, 0xC($t1)
	lw $t4, 0x0($t1)
	lw $t5, 0x4($t1)
	lw $t7, 0x8($t1)
	lw $t8, 0xC($t1)
	and $t3, $t3, $t4
	and $t3, $t3, $t5
	and $t3, $t3, $t7
	and $t3, $t3, $t8

	sw $zero, 0x0($t1)
	sw $zero, 0x4($t1)
	sw $zero, 0x8($t1)
	sw $zero, 0xC($t1)
	lw $t4, 0x0($t1)
	lw $t5, 0x4($t1)
	lw $t7, 0x8($t1)
	lw $t8, 0xC($t1)
	or $t2, $t2, $t4
	or $t2, $t2, $t5
	or $t2, $t2, $t7
	or $t2, $t2, $t8
	sw $t6, 0x0($t1)
	sw $t6, 0x4($t1)
	sw $t6, 0x8($t1)
	sw $t6, 0xC($t1)
	lw $t4, 0x0($t1)
	lw $t5, 0x4($t1)
	lw $t7, 0x8($t1)
	lw $t8, 0xC($t1)
	and $t3, $t3, $t4
	and $t3, $t3, $t5
	and $t3, $t3, $t7
	and $t3, $t3, $t8

	sw $zero, 0x0($t1)
	sw $zero, 0x4($t1)
	sw $zero, 0x8($t1)
	sw $zero, 0xC($t1)
	lw $t4, 0x0($t1)
	lw $t5, 0x4($t1)
	lw $t7, 0x8($t1)
	lw $t8, 0xC($t1)
	or $t2, $t2, $t4
	or $t2, $t2, $t5
	or $t2, $t2, $t7
	or $t2, $t2, $t8
	sw $t6, 0x0($t1)
	sw $t6, 0x4($t1)
	sw $t6, 0x8($t1)
	sw $t6, 0xC($t1)
	lw $t4, 0x0($t1)
	lw $t5, 0x4($t1)
	lw $t7, 0x8($t1)
	lw $t8, 0xC($t1)
	and $t3, $t3, $t4
	and $t3, $t3, $t5
	and $t3, $t3, $t7
	and $t3, $t3, $t8

	sw $zero, 0x0($t1)
	sw $zero, 0x4($t1)
	sw $zero, 0x8($t1)
	sw $zero, 0xC($t1)
	lw $t4, 0x0($t1)
	lw $t5, 0x4($t1)
	lw $t7, 0x8($t1)
	lw $t8, 0xC($t1)
	or $t2, $t2, $t4
	or $t2, $t2, $t5
	or $t2, $t2, $t7
	or $t2, $t2, $t8
	sw $t6, 0x0($t1)
	sw $t6, 0x4($t1)
	sw $t6, 0x8($t1)
	sw $t6, 0xC($t1)
	lw $t4, 0x0($t1)
	lw $t5, 0x4($t1)
	lw $t7, 0x8($t1)
	lw $t8, 0xC($t1)
	and $t3, $t3, $t4
	and $t3, $t3, $t5
	and $t3, $t3, $t7
	and $t3, $t3, $t8

	sw $zero, 0x0($t1)
	sw $zero, 0x4($t1)
	sw $zero, 0x8($t1)
	sw $zero, 0xC($t1)
	lw $t4, 0x0($t1)
	lw $t5, 0x4($t1)
	lw $t7, 0x8($t1)
	lw $t8, 0xC($t1)
	or $t2, $t2, $t4
	or $t2, $t2, $t5
	or $t2, $t2, $t7
	or $t2, $t2, $t8
	sw $t6, 0x0($t1)
	sw $t6, 0x4($t1)
	sw $t6, 0x8($t1)
	sw $t6, 0xC($t1)
	lw $t4, 0x0($t1)
	lw $t5, 0x4($t1)
	lw $t7, 0x8($t1)
	lw $t8, 0xC($t1)
	and $t3, $t3, $t4
	and $t3, $t3, $t5
	and $t3, $t3, $t7
	and $t3, $t3, $t8

	sw $zero, 0x0($t1)
	sw $zero, 0x4($t1)
	sw $zero, 0x8($t1)
	sw $zero, 0xC($t1)
	lw $t4, 0x0($t1)
	lw $t5, 0x4($t1)
	lw $t7, 0x8($t1)
	lw $t8, 0xC($t1)
	or $t2, $t2, $t4
	or $t2, $t2, $t5
	or $t2, $t2, $t7
	or $t2, $t2, $t8
	sw $t6, 0x0($t1)
	sw $t6, 0x4($t1)
	sw $t6, 0x8($t1)
	sw $t6, 0xC($t1)
	lw $t4, 0x0($t1)
	lw $t5, 0x4($t1)
	lw $t7, 0x8($t1)
	lw $t8, 0xC($t1)
	and $t3, $t3, $t4
	and $t3, $t3, $t5
	and $t3, $t3, $t7
	and $t3, $t3, $t8

	sw $zero, 0x0($t1)
	sw $zero, 0x4($t1)
	sw $zero, 0x8($t1)
	sw $zero, 0xC($t1)
	lw $t4, 0x0($t1)
	lw $t5, 0x4($t1)
	lw $t7, 0x8($t1)
	lw $t8, 0xC($t1)
	or $t2, $t2, $t4
	or $t2, $t2, $t5
	or $t2, $t2, $t7
	or $t2, $t2, $t8
	sw $t6, 0x0($t1)
	sw $t6, 0x4($t1)
	sw $t6, 0x8($t1)
	sw $t6, 0xC($t1)
	lw $t4, 0x0($t1)
	lw $t5, 0x4($t1)
	lw $t7, 0x8($t1)
	lw $t8, 0xC($t1)
	and $t3, $t3, $t4
	and $t3, $t3, $t5
	and $t3, $t3, $t7
	and $t3, $t3, $t8

	sw $zero, 0x0($t1)
	sw $zero, 0x4($t1)
	sw $zero, 0x8($t1)
	sw $zero, 0xC($t1)
	lw $t4, 0x0($t1)
	lw $t5, 0x4($t1)
	lw $t7, 0x8($t1)
	lw $t8, 0xC($t1)
	or $t2, $t2, $t4
	or $t2, $t2, $t5
	or $t2, $t2, $t7
	or $t2, $t2, $t8
	sw $t6, 0x0($t1)
	sw $t6, 0x4($t1)
	sw $t6, 0x8($t1)
	sw $t6, 0xC($t1)
	lw $t4, 0x0($t1)
	lw $t5, 0x4($t1)
	lw $t7, 0x8($t1)
	lw $t8, 0xC($t1)
	and $t3, $t3, $t4
	and $t3, $t3, $t5
	and $t3, $t3, $t7
	and $t3, $t3, $t8

	sw $zero, 0x0($t1)
	sw $zero, 0x4($t1)
	sw $zero, 0x8($t1)
	sw $zero, 0xC($t1)
	lw $t4, 0x0($t1)
	lw $t5, 0x4($t1)
	lw $t7, 0x8($t1)
	lw $t8, 0xC($t1)
	or $t2, $t2, $t4
	or $t2, $t2, $t5
	or $t2, $t2, $t7
	or $t2, $t2, $t8
	sw $t6, 0x0($t1)
	sw $t6, 0x4($t1)
	sw $t6, 0x8($t1)
	sw $t6, 0xC($t1)
	lw $t4, 0x0($t1)
	lw $t5, 0x4($t1)
	lw $t7, 0x8($t1)
	lw $t8, 0xC($t1)
	and $t3, $t3, $t4
	and $t3, $t3, $t5
	and $t3, $t3, $t7
	and $t3, $t3, $t8

	sw $zero, 0x0($t1)
	sw $zero, 0x4($t1)
	sw $zero, 0x8($t1)
	sw $zero, 0xC($t1)
	lw $t4, 0x0($t1)
	lw $t5, 0x4($t1)
	lw $t7, 0x8($t1)
	lw $t8, 0xC($t1)
	or $t2, $t2, $t4
	or $t2, $t2, $t5
	or $t2, $t2, $t7
	or $t2, $t2, $t8
	sw $t6, 0x0($t1)
	sw $t6, 0x4($t1)
	sw $t6, 0x8($t1)
	sw $t6, 0xC($t1)
	lw $t4, 0x0($t1)
	lw $t5, 0x4($t1)
	lw $t7, 0x8($t1)
	lw $t8, 0xC($t1)
	and $t3, $t3, $t4
	and $t3, $t3, $t5
	and $t3, $t3, $t7
	and $t3, $t3, $t8

	sw $zero, 0x0($t1)
	sw $zero, 0x4($t1)
	sw $zero, 0x8($t1)
	sw $zero, 0xC($t1)
	lw $t4, 0x0($t1)
	lw $t5, 0x4($t1)
	lw $t7, 0x8($t1)
	lw $t8, 0xC($t1)
	or $t2, $t2, $t4
	or $t2, $t2, $t5
	or $t2, $t2, $t7
	or $t2, $t2, $t8
	sw $t6, 0x0($t1)
	sw $t6, 0x4($t1)
	sw $t6, 0x8($t1)
	sw $t6, 0xC($t1)
	lw $t4, 0x0($t1)
	lw $t5, 0x4($t1)
	lw $t7, 0x8($t1)
	lw $t8, 0xC($t1)
	and $t3, $t3, $t4
	and $t3, $t3, $t5
	and $t3, $t3, $t7
	and $t3, $t3, $t8

	bnez $t2, cffail
	nop
	bne $t3, $t6, cffail
	nop

	b cfret
	li $t3, 1
cffail:
	li $t3, 0
cfret:
	srl $t1, $t0, 3
	addu $t2, $a1, $t1
	andi $t1, $t0, 7
	sllv $t3, $t3, $t1
	lb $t1, ($t2)
	or $t1, $t1, $t3
	sb $t1, ($t2)
	sltiu $t1, $t0, 0xFF
	beqzl $t1, cfret2
	li $v0, 1
	li $v0, 0
cfret2:
	addiu $t0, $t0, 1
	jr $ra
	sw $t0, ($a0)
