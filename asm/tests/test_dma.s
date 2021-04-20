.set noat
.set noreorder

.include "macros.inc"

glabel test_dma_d0
	lui $t0, 0x8020
	b test_dma
	li $t1, 0x00000000
glabel test_dma_d1
	lui $t0, 0x8020
	b test_dma
	li $t1, 0xFFFFFFFF
glabel test_dma_e0
	lui $t0, 0x8030
	b test_dma
	li $t1, 0x00000000
glabel test_dma_e1
	lui $t0, 0x8030
	b test_dma
	li $t1, 0xFFFFFFFF
test_dma:
	addiu $sp, $sp, -0x40
	sw $ra, 0x40($sp)
	sw $s0, 0x3c($sp)
	sw $s1, 0x38($sp)
	sw $s2, 0x34($sp)
	sw $s3, 0x30($sp)
	sw $s4, 0x2c($sp)
	sw $s5, 0x28($sp)
	sw $a0, 0x24($sp)
	sw $a1, 0x20($sp)
	sw $a2, 0x1c($sp)
	move $s0, $t0
	move $s1, $t1
	move $s4, $s1
	move $s5, $s1
	li $s3, DMA_TEST_REPS - 1
	beqz $t1, h
	lui $s2, %hi(_onesSegmentRomStart)
	b loop_start
	addiu $s2, $s2, %lo(_onesSegmentRomStart)
h:
	lui $s2, %hi(_zeroesSegmentRomStart)
	addiu $s2, $s2, %lo(_zeroesSegmentRomStart)
loop_start:
	move $a0, $s0
	move $a1, $s2
	lui $a2, 0x0010
	jal dma_read
	addu $a2, $s2, $a2
	lui $t1, 0x0010
mem_check_start:
	addiu $t1, $t1, -4
	bltz $t1, mem_check_end
	addu $t0, $s0, $t1
	lw $t2, ($t0)
	or $s4, $s4, $t2
	b mem_check_start
	and $s5, $s5, $t2
mem_check_end:
	bnez $s3, loop_start
	addiu $s3, $s3, -1
	li $t0, 25
	lw $a2, 0x1c($sp)
	lw $a1, 0x20($sp)
	lw $a0, 0x24($sp)
	beqz $s1, zero
	sw $t0, ($a2)
	beq $s1, $s5, pass
	nop
	b fail
	nop
zero:
	bne $s1, $s4, fail
	nop
pass:
	b end
	li $t0, 1
fail:
	li $t0, 0
end:
	lw $t1, ($a0)
	srl $t2, $t1, 2
	andi $t3, $t1, 3
	sll $t3, $t3, 1
	sllv $t0, $t0, $t3
	addu $t2, $a1, $t2
	lb $t4, ($t2)
	or $t4, $t4, $t0
	sb $t4, ($t2)
	addiu $t1, $t1, 1
	sw $t1, ($a0)
	li $t2, 100
	sltu $v0, $t2, $t1
	lw $s5, 0x28($sp)
	lw $s4, 0x2c($sp)
	lw $s3, 0x30($sp)
	lw $s2, 0x34($sp)
	lw $s1, 0x38($sp)
	lw $s0, 0x3c($sp)
	lw $ra, 0x40($sp)
	jr $ra
	addiu $sp, $sp, 0x40
