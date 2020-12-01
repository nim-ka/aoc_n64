.set noat
.set noreorder

.include "macros.inc"

glabel custom_entry
	addiu $sp, $sp, -0x40
	sw $ra, 0x40($sp)
	jal __osDisableInt
	sw $s0, 0x3c($sp)
	jal run_tests
	move $s0, $v0
	jal __osRestoreInt
	move $a0, $s0
	lw $s0, 0x3c($sp)
	lw $ra, 0x40($sp)
	jr $ra
	addiu $sp, $sp, 0x40
