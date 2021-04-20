.set noat
.set noreorder

.include "macros.inc"

glabel gRngSeed
	.word 0x00000000

glabel rng
	li $v0, 0x43FD43FD
	lui $at, %hi(gRngSeed)
	lh $at, %lo(gRngSeed)($at)
	multu $v0, $at
	nop
	nop
	mflo $v0
	li $at, 0xC39EC3
	addu $v0, $v0, $at
	andi $v0, $v0, 0xFFFF
	lui $at, %hi(gRngSeed)
	jr $ra
	sh $v0, %lo(gRngSeed)($at)

glabel test_cpu_mulmul
	addiu $sp, $sp, -0x10
	sw $ra, 0x10($sp)
	sw $s0, 0x0C($sp)
	li $t1, 25
	sw $t1, ($a2)
	lw $t0, ($a0)
	sltiu $t1, $t0, 200
	addiu $t0, $t0, 1
	sw $t0, ($a0)
	beqz $t1, ret
	li $v0, 1
	li $t3, 1
	li $s0, CPU_TEST_REPS - 1
loop_start:
	jal rng
	mtc1 $zero, $f4
	jal rng
	mtc1 $v0, $f6
	jal rng
	move $t8, $v0
	move $t9, $v0
	cvt.s.w $f6, $f6
	mul.s $f8, $f4, $f6
	multu $t8, $t9
	nop
	nop
	mflo $t5
	nop
	nop
	multu $t8, $t9
	nop
	nop
	mflo $t6
	nop
	nop
	beq $t5, $t6, pass
	nop
	li $t3, 0
pass:
	bnez $s0, loop_start
	addiu $s0, $s0, -1
	lw $t0, ($a0)
	addiu $t0, $t0, -1
	srl $t1, $t0, 3
	andi $t2, $t0, 7
	addu $t1, $a1, $t1
	sllv $t3, $t3, $t2
	lb $t4, ($t1)
	or $t4, $t3, $t4
	sb $t4, ($t1)
	li $v0, 0
ret:
	lw $s0, 0x0C($sp)
	lw $ra, 0x10($sp)
	jr $ra
	addiu $sp, $sp, 0x10
