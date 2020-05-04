.rsp

.include "rsp/rsp_defs.inc"

// This file assumes CODE_FILE is set on the command line
.create CODE_FILE, 0x04001000

.ifndef VERSION_EU
    ori   at, at, 0x0001
.endif
    j     boot_04001068
     addi  at, zero, OSTask_addr
boot_load_ucode:
    lw    v0, OSTask_ucode(at)
    addi  v1, zero, 0x0f7f    // hard-coded length = 0xF80
    addi  a3, zero, 0x1080    // hard-coded address = 0x1080
    mtc0  a3, SP_MEM_ADDR
    mtc0  v0, SP_DRAM_ADDR
    mtc0  v1, SP_RD_LEN
boot_ucode_dma_busy:
    mfc0  a0, SP_DMA_BUSY
    bne   a0, zero, boot_ucode_dma_busy
     nop
    jal   check_yielded
     nop
    jr    a3                  // jump to the loaded ucode
     mtc0  zero, SP_SEMAPHORE // clear semaphore

check_yielded:
    mfc0  t0, SP_STATUS
    andi  t0, t0, 0x0080      // yield signal is set
    bne   t0, zero, boot_04001054
     nop
    jr    ra
boot_04001054:
     mtc0  zero, SP_SEMAPHORE // clear semaphore
    ori   t0, zero, 0x5200    // clear yield, set yielded, set taskdone?
    mtc0  t0, SP_STATUS
    break                     // halt RSP and set SP_STATUS_BROKE
    nop

boot_04001068:
    lw    v0, OSTask_flags(at)
    andi  v0, v0, OS_TASK_DP_WAIT
    beq   v0, zero, boot_load_data
     nop
    jal   check_yielded
     nop
    mfc0  v0, DPC_STATUS
    andi  v0, v0, DPC_STATUS_DMA_BUSY
    bgtz  v0, check_yielded
     nop
boot_load_data:
    lw    v0, OSTask_ucode_data(at)
    lw    v1, OSTask_ucode_data_size(at)
    addi  v1, v1, -1
boot_dma_not_full:
    mfc0  s8, SP_DMA_FULL
    bne   s8, zero, boot_dma_not_full
     nop
    mtc0  zero, SP_MEM_ADDR   // ucode_data store at base of DMEM
    mtc0  v0, SP_DRAM_ADDR
    mtc0  v1, SP_RD_LEN
boot_data_dma_busy:
    mfc0  a0, SP_DMA_BUSY
    bne   a0, zero, boot_data_dma_busy
     nop
    jal   check_yielded
     nop
    j     boot_load_ucode
     nop

.close // CODE_FILE
