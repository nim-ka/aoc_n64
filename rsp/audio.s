.rsp

.include "rsp/rsp_defs.inc"

// This file assumes DATA_FILE and CODE_FILE are set on the command line

.if version() < 110
    .error "armips 0.11 or newer is required"
.endif

.macro jumpTableEntry, addr
  .dh addr & 0xFFFF
.endmacro

// Audio flags
A_INIT     equ 0x01
A_CONTINUE equ 0x00
A_LOOP     equ 0x02
A_OUT      equ 0x02
A_LEFT     equ 0x02
A_RIGHT    equ 0x00
A_VOL      equ 0x04
A_RATE     equ 0x00
A_AUX      equ 0x08
A_NOAUX    equ 0x00
A_MAIN     equ 0x00
A_MIX      equ 0x10

.create DATA_FILE, 0x0000

.dh 0x0000, 0x0001, 0x0002, 0xffff, 0x0020, 0x0800, 0x7fff, 0x4000 // 0x00000000

// 0x10 - 0x1F: command dispatch table
dispatchTable:
  jumpTableEntry cmd_SPNOOP
  jumpTableEntry cmd_ADPCM
  jumpTableEntry cmd_CLEARBUFF
  jumpTableEntry cmd_ENVMIXER
  jumpTableEntry cmd_LOADBUFF
  jumpTableEntry cmd_RESAMPLE
  jumpTableEntry cmd_SAVEBUFF
  jumpTableEntry cmd_SEGMENT
  jumpTableEntry cmd_SETBUFF
  jumpTableEntry cmd_SETVOL
  jumpTableEntry cmd_DMEMMOVE
  jumpTableEntry cmd_LOADADPCM
  jumpTableEntry cmd_MIXER
  jumpTableEntry cmd_INTERLEAVE
  jumpTableEntry cmd_POLEF
  jumpTableEntry cmd_SETLOOP

.dh 0xf000, 0x0f00, 0x00f0, 0x000f, 0x0001, 0x0010, 0x0100, 0x1000 // 0x00000030
data0040:
.dh 0x0002, 0x0004, 0x0006, 0x0008, 0x000a, 0x000c, 0x000e, 0x0010 // 0x00000040
.dh 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001 // 0x00000050
.dh 0x0000, 0x0001, 0x0002, 0x0004, 0x0008, 0x0010, 0x0100, 0x0200 // 0x00000060
.dh 0x0001, 0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000 // 0x00000070
.dh 0x0000, 0x0001, 0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000 // 0x00000080
.dh 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000, 0x0001, 0x0000 // 0x00000090
.dh 0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000, 0x0001 // 0x000000a0
.dh 0x2000, 0x4000, 0x6000, 0x8000, 0xa000, 0xc000, 0xe000, 0xffff // 0x000000b0
.dh 0x0c39, 0x66ad, 0x0d46, 0xffdf, 0x0b39, 0x6696, 0x0e5f, 0xffd8 // 0x000000c0
.dh 0x0a44, 0x6669, 0x0f83, 0xffd0, 0x095a, 0x6626, 0x10b4, 0xffc8 // 0x000000d0
.dh 0x087d, 0x65cd, 0x11f0, 0xffbf, 0x07ab, 0x655e, 0x1338, 0xffb6 // 0x000000e0
.dh 0x06e4, 0x64d9, 0x148c, 0xffac, 0x0628, 0x643f, 0x15eb, 0xffa1 // 0x000000f0
.dh 0x0577, 0x638f, 0x1756, 0xff96, 0x04d1, 0x62cb, 0x18cb, 0xff8a // 0x00000100
.dh 0x0435, 0x61f3, 0x1a4c, 0xff7e, 0x03a4, 0x6106, 0x1bd7, 0xff71 // 0x00000110
.dh 0x031c, 0x6007, 0x1d6c, 0xff64, 0x029f, 0x5ef5, 0x1f0b, 0xff56 // 0x00000120
.dh 0x022a, 0x5dd0, 0x20b3, 0xff48, 0x01be, 0x5c9a, 0x2264, 0xff3a // 0x00000130
.dh 0x015b, 0x5b53, 0x241e, 0xff2c, 0x0101, 0x59fc, 0x25e0, 0xff1e // 0x00000140
.dh 0x00ae, 0x5896, 0x27a9, 0xff10, 0x0063, 0x5720, 0x297a, 0xff02 // 0x00000150
.dh 0x001f, 0x559d, 0x2b50, 0xfef4, 0xffe2, 0x540d, 0x2d2c, 0xfee8 // 0x00000160
.dh 0xffac, 0x5270, 0x2f0d, 0xfedb, 0xff7c, 0x50c7, 0x30f3, 0xfed0 // 0x00000170
.dh 0xff53, 0x4f14, 0x32dc, 0xfec6, 0xff2e, 0x4d57, 0x34c8, 0xfebd // 0x00000180
.dh 0xff0f, 0x4b91, 0x36b6, 0xfeb6, 0xfef5, 0x49c2, 0x38a5, 0xfeb0 // 0x00000190
.dh 0xfedf, 0x47ed, 0x3a95, 0xfeac, 0xfece, 0x4611, 0x3c85, 0xfeab // 0x000001a0
.dh 0xfec0, 0x4430, 0x3e74, 0xfeac, 0xfeb6, 0x424a, 0x4060, 0xfeaf // 0x000001b0
.dh 0xfeaf, 0x4060, 0x424a, 0xfeb6, 0xfeac, 0x3e74, 0x4430, 0xfec0 // 0x000001c0
.dh 0xfeab, 0x3c85, 0x4611, 0xfece, 0xfeac, 0x3a95, 0x47ed, 0xfedf // 0x000001d0
.dh 0xfeb0, 0x38a5, 0x49c2, 0xfef5, 0xfeb6, 0x36b6, 0x4b91, 0xff0f // 0x000001e0
.dh 0xfebd, 0x34c8, 0x4d57, 0xff2e, 0xfec6, 0x32dc, 0x4f14, 0xff53 // 0x000001f0
.dh 0xfed0, 0x30f3, 0x50c7, 0xff7c, 0xfedb, 0x2f0d, 0x5270, 0xffac // 0x00000200
.dh 0xfee8, 0x2d2c, 0x540d, 0xffe2, 0xfef4, 0x2b50, 0x559d, 0x001f // 0x00000210
.dh 0xff02, 0x297a, 0x5720, 0x0063, 0xff10, 0x27a9, 0x5896, 0x00ae // 0x00000220
.dh 0xff1e, 0x25e0, 0x59fc, 0x0101, 0xff2c, 0x241e, 0x5b53, 0x015b // 0x00000230
.dh 0xff3a, 0x2264, 0x5c9a, 0x01be, 0xff48, 0x20b3, 0x5dd0, 0x022a // 0x00000240
.dh 0xff56, 0x1f0b, 0x5ef5, 0x029f, 0xff64, 0x1d6c, 0x6007, 0x031c // 0x00000250
.dh 0xff71, 0x1bd7, 0x6106, 0x03a4, 0xff7e, 0x1a4c, 0x61f3, 0x0435 // 0x00000260
.dh 0xff8a, 0x18cb, 0x62cb, 0x04d1, 0xff96, 0x1756, 0x638f, 0x0577 // 0x00000270
.dh 0xffa1, 0x15eb, 0x643f, 0x0628, 0xffac, 0x148c, 0x64d9, 0x06e4 // 0x00000280
.dh 0xffb6, 0x1338, 0x655e, 0x07ab, 0xffbf, 0x11f0, 0x65cd, 0x087d // 0x00000290
.dh 0xffc8, 0x10b4, 0x6626, 0x095a, 0xffd0, 0x0f83, 0x6669, 0x0a44 // 0x000002a0
.dh 0xffd8, 0x0e5f, 0x6696, 0x0b39, 0xffdf, 0x0d46, 0x66ad, 0x0c39 // 0x000002b0

.definelabel segmentTable, 0x320

.definelabel audioStruct, 0x360
audio_in_buf        equ 0x00 // 0x360
audio_out_buf       equ 0x02 // 0x362
audio_count         equ 0x04 // 0x364
audio_vol_left      equ 0x06 // 0x366
audio_vol_right     equ 0x08 // 0x366
audio_aux_buf0      equ 0x0a // 0x36a
audio_aux_buf1      equ 0x0c // 0x36c
audio_aux_buf2      equ 0x0e // 0x36e
audio_loop_value    equ 0x10 // 0x370 (shared)
audio_target_left   equ 0x10 // 0x370 (shared)
audio_rate_hi_left  equ 0x12 // 0x372 (shared)
audio_rate_lo_left  equ 0x14 // 0x374
audio_target_right  equ 0x16 // 0x376
audio_rate_hi_right equ 0x18 // 0x378
audio_rate_lo_right equ 0x1a // 0x37a
audio_dry_gain      equ 0x1c // 0x37c
audio_wet_gain      equ 0x1e // 0x37e

.definelabel nextTaskEntry, 0x380 // next task entries (0x140 bytes)
.definelabel adpcmTable,    0x4c0 // (16*8 16-bit entries)
.definelabel dmemBase,      0x5c0 // all samples stored that is transferred to DMEM
.definelabel tmpData,       0xF90 // temporary area

.close // DATA_FILE


.create CODE_FILE, 0x04001080

    addi  t8, zero, audioStruct
    addi  s7, zero, tmpData
    lw    gp, 0x30(at)        // task_data
    lw    k1, 0x34(at)        // task_data_size
    mfc0  a1, DPC_STATUS
    andi  a0, a1, DPC_STATUS_XBUS_DMA
    beqz  a0, @@audio_040010b4
     andi  a0, a1, DPC_STATUS_DMA_BUSY
    beqz  a0, @@audio_040010b4
     nop
@@dpc_dma_busy:
    mfc0  a0, DPC_STATUS
    andi  a0, a0, DPC_STATUS_DMA_BUSY
    bgtz  a0, @@dpc_dma_busy
@@audio_040010b4:
     nop
    jal   audio_04001150
     nop
    addi  v0, zero, 0x000f
    addi  at, zero, segmentTable
@@audio_040010c8:
    sw    zero, 0x00(at)
    bgtz  v0, @@audio_040010c8
     addi  v0, v0, -1

dma_busy:
    mfc0  v0, SP_DMA_BUSY
    bnez  v0, dma_busy
     addi  sp, zero, nextTaskEntry
    mtc0  zero, SP_SEMAPHORE  // release semaphore
audio_040010e4:
    lw    k0, 0x00(sp)        // first word of command
    lw    t9, 0x04(sp)        // second word of command
    srl   at, k0, 23          // cmd byte << 1
    andi  at, at, 0x00fe
    addi  gp, gp, 8
    addi  k1, k1, -8
    addi  sp, sp, 8
    addi  s8, s8, -8
    add   v0, zero, at
    lh    v0, (dispatchTable)(v0)
    jr    v0
     nop
    break

cmd_SPNOOP:
    bgtz  s8, audio_040010e4
     nop
    blez  k1, @@audio_04001138
     nop
    jal   audio_04001150
     nop
    j     dma_busy
     nop
@@audio_04001138:
    ori   at, zero, 0x4000
    mtc0  at, SP_STATUS
    break
    nop
@@forever:
    b     @@forever
     nop

audio_04001150:
    addi  a1, ra, 0x0000
    add   v0, zero, gp
    addi  v1, k1, 0x0000
    addi  a0, v1, -0x0140
    blez  a0, @@audio_0400116c
     addi  at, zero, nextTaskEntry
    addi  v1, zero, 0x0140
@@audio_0400116c:
    addi  s8, v1, 0x0000
    jal   dma_read_start
     addi  v1, v1, -1
    addi  sp, zero, nextTaskEntry
    jr    a1
     nop

dma_read_start:
    mfc0  a0, SP_SEMAPHORE
    bnez  a0, dma_read_start
     nop
@@dma_not_full:
    mfc0  a0, SP_DMA_FULL
    bnez  a0, @@dma_not_full
     nop
    mtc0  at, SP_MEM_ADDR
    mtc0  v0, SP_DRAM_ADDR
    mtc0  v1, SP_RD_LEN
    jr    ra
     nop

dma_write_start:
    mfc0  a0, SP_SEMAPHORE
    bnez  a0, dma_write_start
     nop
@@dma_not_full:
    mfc0  a0, SP_DMA_FULL
    bnez  a0, @@dma_not_full
     nop
    mtc0  at, SP_MEM_ADDR
    mtc0  v0, SP_DRAM_ADDR
    mtc0  v1, SP_WR_LEN
    jr    ra
     nop

cmd_CLEARBUFF:
    andi  v1, t9, 0xffff
    beqz  v1, cmd_SPNOOP
     addi  a0, zero, dmemBase
    andi  v0, k0, 0xffff
    add   v0, v0, a0
    vxor  v1, v1, v1
    addi  v1, v1, -0x10
@@audio_040011f8:
    sdv   v1[0], 0x0(v0)
    sdv   v1[0], 0x8(v0)
    addi  v0, v0, 0x10
    bgtz  v1, @@audio_040011f8
     addi  v1, v1, -0x10
    j     cmd_SPNOOP
     nop

cmd_LOADBUFF:
    lhu   v1, (audio_count)(t8)
    beqz  v1, cmd_SPNOOP
     sll   v0, t9, 8
    srl   v0, v0, 8
    srl   a0, t9, 24
    sll   a0, a0, 2
    lw    a1, (segmentTable)(a0)
    add   v0, v0, a1
    lhu   at, (audio_in_buf)(t8)
    jal   dma_read_start
     addi  v1, v1, -1
@@dma_read_busy:
    mfc0  at, SP_DMA_BUSY
    bnez  at, @@dma_read_busy
     nop
    j     cmd_SPNOOP
     mtc0  zero, SP_SEMAPHORE

cmd_SAVEBUFF:
    lhu   v1, (audio_count)(t8)
    beqz  v1, cmd_SPNOOP
     sll   v0, t9, 8
    srl   v0, v0, 8
    srl   a0, t9, 24
    sll   a0, a0, 2
    lw    a1, (segmentTable)(a0)
    add   v0, v0, a1
    lhu   at, (audio_out_buf)(t8)
    jal   dma_write_start
     addi  v1, v1, -1
@@dma_write_busy:
    mfc0  at, SP_DMA_BUSY
    bnez  at, @@dma_write_busy
     nop
    j     cmd_SPNOOP
     mtc0  zero, SP_SEMAPHORE

cmd_LOADADPCM:
    sll   v0, t9, 8
    srl   v0, v0, 8
    srl   a0, t9, 24
    sll   a0, a0, 2
    lw    a1, (segmentTable)(a0)
    add   v0, v0, a1
    addi  at, zero, adpcmTable
    andi  v1, k0, 0xffff
    jal   dma_read_start
     addi  v1, v1, -1
@@dma_read_busy:
    mfc0  at, SP_DMA_BUSY
    bnez  at, @@dma_read_busy
     nop
    j     cmd_SPNOOP
     mtc0  zero, SP_SEMAPHORE

cmd_SEGMENT:
    sll   v1, t9, 8           // Least significant 24-bits offset
    srl   v1, v1, 8
    srl   v0, t9, 24          // Most significant 8-bits segment number
    sll   v0, v0, 2
    add   a0, zero, v0
    j     cmd_SPNOOP
     sw    v1, (segmentTable)(a0)

cmd_SETBUFF:
    addi  at, k0, dmemBase
    srl   v0, t9, 16
    addi  v0, v0, dmemBase
    srl   a0, k0, 16
    andi  a0, a0, A_AUX
    bgtz  a0, @@audio_04001318
     addi  v1, t9, dmemBase
    sh    at, (audio_in_buf)(t8)
    sh    v0, (audio_out_buf)(t8)
    j     cmd_SPNOOP
     sh    t9, (audio_count)(t8)
@@audio_04001318:
    sh    v1, (audio_aux_buf2)(t8)
    sh    at, (audio_aux_buf0)(t8)
    j     cmd_SPNOOP
     sh    v0, (audio_aux_buf1)(t8)

cmd_SETVOL:
    srl   v0, k0, 16
    andi  at, v0, A_AUX
    beqz  at, @@audio_04001344
     andi  at, v0, A_VOL
    sh    k0, (audio_dry_gain)(t8)
    j     cmd_SPNOOP
     sh    t9, (audio_wet_gain)(t8)
@@audio_04001344:
    beqz  at, @@audio_04001364
     andi  at, v0, A_LEFT
    beqz  at, @@audio_0400135c
     nop
    j     cmd_SPNOOP
     sh    k0, (audio_vol_left)(t8)
@@audio_0400135c:
    j     cmd_SPNOOP
     sh    k0, (audio_vol_right)(t8)
@@audio_04001364:
    beqz  at, @@audio_0400137c
     srl   at, t9, 16
    sh    k0, (audio_target_left)(t8)
    sh    at, (audio_rate_hi_left)(t8)
    j     cmd_SPNOOP
     sh    t9, (audio_rate_lo_left)(t8)
@@audio_0400137c:
    sh    k0, (audio_target_right)(t8)
    sh    at, (audio_rate_hi_right)(t8)
    j     cmd_SPNOOP
     sh    t9, (audio_rate_lo_right)(t8)

cmd_INTERLEAVE:
    lhu   at, (audio_count)(t8)
    lhu   a0, (audio_out_buf)(t8)
    beqz  at, cmd_SPNOOP
     andi  v1, t9, 0xffff
    addi  v1, v1, dmemBase
    srl   v0, t9, 16
    addi  v0, v0, dmemBase
@@audio_040013a8:
    lqv   v1[0], 0x00(v0)
    lqv   v2[0], 0x00(v1)
    ssv   v1[0], 0x00(a0)
    ssv   v2[0], 0x02(a0)
    ssv   v1[2], 0x04(a0)
    ssv   v2[2], 0x06(a0)
    ssv   v1[4], 0x08(a0)
    ssv   v2[4], 0x0a(a0)
    ssv   v1[6], 0x0c(a0)
    ssv   v2[6], 0x0e(a0)
    ssv   v1[8], 0x10(a0)
    ssv   v2[8], 0x12(a0)
    ssv   v1[10], 0x14(a0)
    ssv   v2[10], 0x16(a0)
    ssv   v1[12], 0x18(a0)
    ssv   v2[12], 0x1a(a0)
    ssv   v1[14], 0x1c(a0)
    ssv   v2[14], 0x1e(a0)
    addi  at, at, -0x10
    addi  v0, v0, 0x10
    addi  v1, v1, 0x10
    bgtz  at, @@audio_040013a8
     addi  a0, a0, 0x20
    j     cmd_SPNOOP
     nop

cmd_DMEMMOVE:
    andi  at, t9, 0xffff
    beqz  at, cmd_SPNOOP
     andi  v0, k0, 0xffff
    addi  v0, v0, dmemBase
    srl   v1, t9, 16
    addi  v1, v1, dmemBase
@@audio_04001424:
    ldv   v1[0], 0x0(v0)
    ldv   v2[0], 0x8(v0)
    addi  at, at, -0x10
    addi  v0, v0, 0x10
    sdv   v1[0], 0x0(v1)
    sdv   v2[0], 0x8(v1)
    bgtz  at, @@audio_04001424
     addi  v1, v1, 0x10
    j     cmd_SPNOOP
     nop

cmd_SETLOOP:
    sll   at, t9, 8
    srl   at, at, 8
    srl   v1, t9, 24
    sll   v1, v1, 2
    lw    v0, (segmentTable)(v1)
    add   at, at, v0
    sw    at, (audio_loop_value)(t8)
    j     cmd_SPNOOP
     nop

cmd_ADPCM:
    lqv   v31[0], 0x00(zero)
    vxor  v27, v27, v27
    lhu   s5, (audio_in_buf)(t8)
    vxor  v25, v25, v25
    vxor  v24, v24, v24
    addi  s4, s5, 1
    lhu   s3, (audio_out_buf)(t8)
    vxor  v13, v13, v13
    vxor  v14, v14, v14
    lhu   s2, (audio_count)(t8)
    vxor  v15, v15, v15
    lui   at, 0x00ff
    vxor  v16, v16, v16
    ori   at, at, 0xffff
    vxor  v17, v17, v17
    and   s1, t9, at
    vxor  v18, v18, v18
    srl   v0, t9, 24
    vxor  v19, v19, v19
    sll   v0, v0, 2
    lw    v1, (segmentTable)(v0)
    add   s1, s1, v1          // last frame addr
    sqv   v27[0], 0x00(s3)
    sqv   v27[0], 0x10(s3)
    srl   at, k0, 16
    andi  at, at, A_INIT
    bgtz  at, @@audio_0400150c
     srl   at, k0, 16
    andi  at, at, A_LOOP
    beq   zero, at, @@audio_040014f0
     addi  v0, s1, 0x00
    lw    v0, (audio_loop_value)(t8)
@@audio_040014f0:
    addi  at, s3, 0x0000
    jal   dma_read_start
     addi  v1, zero, 0x1f
@@dma_read_busy:
    mfc0  a1, SP_DMA_BUSY
    bnez  a1, @@dma_read_busy
     nop
    mtc0  zero, SP_SEMAPHORE
@@audio_0400150c:
    addi  s0, zero, 0x0030
    addi  t7, zero, adpcmTable
    ldv   v25[0], 0x00(s0)
    ldv   v24[8], 0x00(s0)
    ldv   v23[0], 0x08(s0)
    ldv   v23[8], 0x08(s0)
    lqv   v27[0], 0x10(s3)    // last 8 frames
    addi  s3, s3, 0x20
    beqz  s2, @@audio_040016e8
     ldv   v1[0], 0x00(s4)
    lbu   at, 0x00(s5)
    andi  t3, at, 0x000f
    sll   t3, t3, 5
    vand  v3, v25, v1[0]
    add   t5, t3, t7
    vand  v4, v24, v1[1]
    srl   t6, at, 4
    vand  v5, v25, v1[2]
    addi  v0, zero, 12
    vand  v6, v24, v1[3]
    sub   t6, v0, t6
    addi  v0, t6, -1
    addi  v1, zero, 1
    sll   v1, v1, 15
    srlv  a0, v1, v0
    mtc2  a0, v22[0]
    lqv   v21[0], 0x00(t5)
    lqv   v20[0], 0x10(t5)
    addi  t5, t5, -2
    lrv   v19[0], 0x20(t5)
    addi  t5, t5, -2
    lrv   v18[0], 0x20(t5)
    addi  t5, t5, -2
    lrv   v17[0], 0x20(t5)
    addi  t5, t5, -2
    lrv   v16[0], 0x20(t5)
    addi  t5, t5, -2
    lrv   v15[0], 0x20(t5)
    addi  t5, t5, -2
    lrv   v14[0], 0x20(t5)
    addi  t5, t5, -2
    lrv   v13[0], 0x20(t5)
@@audio_040015b4:
    addi  s4, s4, 9
    vmudn v30, v3, v23
    addi  s5, s5, 9
    vmadn v30, v4, v23
    ldv   v1[0], 0x00(s4)
    vmudn v29, v5, v23
    lbu   at, 0x00(s5)
    vmadn v29, v6, v23
    blez  t6, @@audio_040015e4
     andi  t3, at, 0x000f
    vmudm v30, v30, v22[0]
    vmudm v29, v29, v22[0]
@@audio_040015e4:
    sll   t3, t3, 5
    vand  v3, v25, v1[0]
    add   t5, t3, t7
    vand  v4, v24, v1[1]
    vand  v5, v25, v1[2]
    vand  v6, v24, v1[3]
    srl   t6, at, 4
    vmudh v2, v21, v27[6]
    addi  v0, zero, 12
    vmadh v2, v20, v27[7]
    sub   t6, v0, t6
    vmadh v2, v19, v30[0]
    addi  v0, t6, -1
    vmadh v2, v18, v30[1]
    addi  v1, zero, 1
    vmadh v2, v17, v30[2]
    sll   v1, v1, 15
    vmadh v2, v16, v30[3]
    srlv  a0, v1, v0
    vmadh v28, v15, v30[4]
    mtc2  a0, v22[0]
    vmadh v2, v14, v30[5]
    vmadh v2, v13, v30[6]
    vmadh v2, v30, v31[5]
    vsar  v26, v7, v28[1]
    vsar  v28, v7, v28[0]
    vmudn v2, v26, v31[4]
    vmadh v28, v28, v31[4]
    vmudh v2, v19, v29[0]
    addi  t4, t5, -2
    vmadh v2, v18, v29[1]
    lrv   v19[0], 0x20(t4)
    vmadh v2, v17, v29[2]
    addi  t4, t4, -2
    vmadh v2, v16, v29[3]
    lrv   v18[0], 0x20(t4)
    vmadh v2, v15, v29[4]
    addi  t4, t4, -2
    vmadh v2, v14, v29[5]
    lrv   v17[0], 0x20(t4)
    vmadh v2, v13, v29[6]
    addi  t4, t4, -2
    vmadh v2, v29, v31[5]
    lrv   v16[0], 0x20(t4)
    vmadh v2, v21, v28[6]
    addi  t4, t4, -2
    vmadh v2, v20, v28[7]
    lrv   v15[0], 0x20(t4)
    vsar  v26, v7, v27[1]
    addi  t4, t4, -2
    vsar  v27, v7, v27[0]
    lrv   v14[0], 0x20(t4)
    addi  t4, t4, -2
    lrv   v13[0], 0x20(t4)
    lqv   v21[0], 0x00(t5)
    vmudn v2, v26, v31[4]
    lqv   v20[0], 0x10(t5)
    vmadh v27, v27, v31[4]
    addi  s2, s2, -0x20
    sdv   v28[0], 0x00(s3)
    sdv   v28[8], 0x08(s3)
    sdv   v27[0], 0x10(s3)
    sdv   v27[8], 0x18(s3)
    bgtz  s2, @@audio_040015b4
     addi  s3, s3, 0x20
@@audio_040016e8:
    addi  at, s3, -0x20
    addi  v0, s1, 0x00
    jal   dma_write_start
     addi  v1, zero, 0x1f
@@dma_write_busy:
    mfc0  a1, SP_DMA_BUSY
    bnez  a1, @@dma_write_busy
     nop
    j     cmd_SPNOOP
     mtc0  zero, SP_SEMAPHORE

cmd_POLEF: // unused by SM64
    lqv   v31[0], 0x0000(zero)
    vxor  v28, v28, v28
    lhu   s5, (audio_in_buf)(t8)
    vxor  v17, v17, v17
    lhu   s4, (audio_out_buf)(t8)
    vxor  v18, v18, v18
    lhu   s3, (audio_count)(t8)
    vxor  v19, v19, v19
    beqz  s3, @@audio_04001874
     andi  t6, k0, 0xffff
    mtc2  t6, v31[10]
    sll   t6, t6, 2
    mtc2  t6, v16[0]
    lui   at, 0x00ff
    vxor  v20, v20, v20
    ori   at, at, 0xffff
    vxor  v21, v21, v21
    and   s2, t9, at
    vxor  v22, v22, v22
    srl   v0, t9, 24
    vxor  v23, v23, v23
    sll   v0, v0, 2
    lw    v1, (segmentTable)(v0)
    add   s2, s2, v1
    slv   v28[0], 0x00(s7)
    srl   at, k0, 16
    andi  at, at, 0x0001
    bgtz  at, @@audio_040017a0
     nop
    addi  at, s7, 0x0000
    addi  v0, s2, 0x0000
    jal   dma_read_start
     addi  v1, zero, 7
@@dma_read_busy:
    mfc0  a1, SP_DMA_BUSY
    bnez  a1, @@dma_read_busy
     nop
    mtc0  zero, SP_SEMAPHORE
@@audio_040017a0:
    addi  t5, zero, adpcmTable
    addi  at, zero, 0x0004
    mtc2  at, v14[0]
    lqv   v24[0], 0x0010(t5)
    vmudm v16, v24, v16[0]
    ldv   v28[8], 0x00(s7)
    sqv   v16[0], 0x10(t5)
    lqv   v25[0], 0x00(t5)
    addi  t5, t5, -2
    lrv   v23[0], 0x20(t5)
    addi  t5, t5, -2
    lrv   v22[0], 0x20(t5)
    addi  t5, t5, -2
    lrv   v21[0], 0x20(t5)
    addi  t5, t5, -2
    lrv   v20[0], 0x20(t5)
    addi  t5, t5, -2
    lrv   v19[0], 0x20(t5)
    addi  t5, t5, -2
    lrv   v18[0], 0x20(t5)
    addi  t5, t5, -2
    lrv   v17[0], 0x20(t5)
    ldv   v30[0], 0x00(s5)
    ldv   v30[8], 0x08(s5)
@@audio_04001800:
    vmudh v16, v25, v28[6]
    addi  s5, s5, 0x10
    vmadh v16, v24, v28[7]
    addi  s3, s3, -0x10
    vmadh v16, v23, v30[0]
    vmadh v16, v22, v30[1]
    vmadh v16, v21, v30[2]
    vmadh v16, v20, v30[3]
    vmadh v28, v19, v30[4]
    vmadh v16, v18, v30[5]
    vmadh v16, v17, v30[6]
    vmadh v16, v30, v31[5]
    ldv   v30[0], 0x00(s5)
    vsar  v26, v15, v28[1]
    ldv   v30[8], 0x08(s5)
    vsar  v28, v15, v28[0]
    vmudn v16, v26, v14[0]
    vmadh v28, v28, v14[0]
    sdv   v28[0], 0x00(s4)
    sdv   v28[8], 0x08(s4)
    bgtz  s3, @@audio_04001800
     addi  s4, s4, 0x10
    addi  at, s4, -8
    addi  v0, s2, 0x00
    jal   dma_write_start
     addi  v1, zero, 7
@@dma_write_busy:
    mfc0  a1, SP_DMA_BUSY
    bnez  a1, @@dma_write_busy
     nop
@@audio_04001874:
    j     cmd_SPNOOP
     mtc0  zero, SP_SEMAPHORE

cmd_RESAMPLE:
    lh    t0, (audio_in_buf)(t8)
    lh    s3, (audio_out_buf)(t8)
    lh    s2, (audio_count)(t8)
    lui   a0, 0x00ff
    ori   a0, a0, 0xffff
    and   v0, t9, a0
    srl   a1, t9, 24
    sll   a1, a1, 2
    lw    a2, (segmentTable)(a1)
    add   v0, v0, a2          // physical address of state_addr
    addi  at, s7, 0x0000
    sw    v0, 0x40(s7)        // overwrite TASK_UCODE ptr
    addi  v1, zero, 0x1f
    srl   a3, k0, 16
    andi  t2, a3, A_INIT
    bgtz  t2, @@audio_040018dc
     nop
    jal   dma_read_start
     nop
@@dma_read_busy:
    mfc0  at, SP_DMA_BUSY
    bnez  at, @@dma_read_busy
     nop
    j     @@audio_040018e8
     mtc0  zero, SP_SEMAPHORE
@@audio_040018dc:
    sh    zero, 0x08(s7)
    vxor  v16, v16, v16
    sdv   v16[0], 0x00(s7)
@@audio_040018e8:
    andi  t2, a3, 0x02      // A_LOOP? A_OUT?
    beqz  t2, @@audio_04001908
     nop
    lh    t3, 0x0a(s7)
    lqv   v3[0], 0x10(s7)
    sdv   v3[0], -0x10(t0)
    sdv   v3[8], -0x08(t0)
    sub   t0, t0, t3
@@audio_04001908:
    addi  t0, t0, -8
    lsv   v23[14], 0x08(s7)   // saved pitch_accumulator
    ldv   v16[0], 0x00(s7)    // saved next 4 unprocessed samples
    sdv   v16[0], 0x00(t0)    // store them before the input samples
    mtc2  t0, v18[4]
    addi  t2, zero, 0xc0
    mtc2  t2, v18[6]
    mtc2  k0, v18[8]          // pitch
    addi  t2, zero, 0x40
    mtc2  t2, v18[10]
    addi  t1, zero, data0040
    lqv   v31[0], 0x10(t1)    // 0x50
    lqv   v25[0], 0x00(t1)    // 0x40
    vsub  v25, v25, v31
    lqv   v30[0], 0x20(t1)    // 0x60
    lqv   v29[0], 0x30(t1)    // 0x70
    lqv   v28[0], 0x40(t1)    // 0x80
    lqv   v27[0], 0x50(t1)    // 0x90
    lqv   v26[0], 0x60(t1)    // 0xA0
    vsub  v25, v25, v31
    lqv   v24[0], 0x70(t1)    // 0xB0
    addi  s5, s7, 0x20
    addi  s4, s7, 0x30
    vxor  v22, v22, v22
    vmudm v23, v31, v23[7]    // load pitch_accumulator into every vector element
    vmadm v22, v25, v18[4]    // (accumulate with pitch times index) >> 16
    vmadn v23, v31, v30[0]    // result & 0xffff
    vmudn v21, v31, v18[2]    // load the in address into every vector element
    vmadn v21, v22, v30[2]    // accumulate with 2 * v22
    vmudl v17, v23, v18[5]    // 64 * v23 >> 16
    vmudn v17, v17, v30[4]    // * 8
    vmadn v17, v31, v18[3]    // += 0x00c0 (resample lookup table address)
    lqv   v25[0], 0x00(t1)
    sqv   v21[0], 0x00(s5)
    sqv   v17[0], 0x00(s4)
    ssv   v23[7], 0x08(s7)
    lh    s1, 0x00(s5)
    lh    t1, 0x00(s4)
    lh    t5, 0x08(s5)
    lh    a1, 0x08(s4)
    lh    s0, 0x02(s5)
    lh    t0, 0x02(s4)
    lh    t4, 0x0a(s5)
    lh    a0, 0x0a(s4)
    lh    t7, 0x04(s5)
    lh    a3, 0x04(s4)
    lh    t3, 0x0c(s5)
    lh    v1, 0x0c(s4)
    lh    t6, 0x06(s5)
    lh    a2, 0x06(s4)
    lh    t2, 0x0e(s5)
    lh    v0, 0x0e(s4)
@@audio_040019d8:
    ldv   v16[0], 0x00(s1)
    vmudm v23, v31, v23[7]
    ldv   v15[0], 0x00(t1)
    vmadh v23, v31, v22[7]
    ldv   v16[8], 0x00(t5)
    vmadm v22, v25, v18[4]
    ldv   v15[8], 0x00(a1)
    vmadn v23, v31, v30[0]
    ldv   v14[0], 0x00(s0)
    vmudn v21, v31, v18[2]
    ldv   v13[0], 0x00(t0)
    vmadn v21, v22, v30[2]
    ldv   v14[8], 0x00(t4)
    vmudl v17, v23, v18[5]
    ldv   v13[8], 0x00(a0)
    ldv   v12[0], 0x00(t7)
    ldv   v11[0], 0x00(a3)
    ldv   v12[8], 0x00(t3)
    vmudn v17, v17, v30[4]
    ldv   v11[8], 0x00(v1)
    ldv   v10[0], 0x00(t6)
    ldv   v9[0], 0x00(a2)
    vmadn v17, v31, v18[3]
    ldv   v10[8], 0x00(t2)
    vmulf v8, v16, v15
    ldv   v9[8], 0x00(v0)
    vmulf v7, v14, v13
    sqv   v21[0], 0x00(s5)
    vmulf v6, v12, v11
    sqv   v17[0], 0x00(s4)
    lh    s1, 0x00(s5)
    vmulf v5, v10, v9
    lh    t1, 0x00(s4)
    vadd  v8, v8, v8[1q]
    lh    t5, 0x08(s5)
    vadd  v7, v7, v7[1q]
    lh    a1, 0x08(s4)
    vadd  v6, v6, v6[1q]
    lh    s0, 0x02(s5)
    vadd  v5, v5, v5[1q]
    lh    t0, 0x02(s4)
    vadd  v8, v8, v8[2h]
    lh    t4, 0x0a(s5)
    vadd  v7, v7, v7[2h]
    lh    a0, 0x0a(s4)
    vadd  v6, v6, v6[2h]
    lh    t7, 0x04(s5)
    vadd  v5, v5, v5[2h]
    lh    a3, 0x04(s4)
    vmudn v4, v29, v8[0h]
    lh    t3, 0x0c(s5)
    vmadn v4, v28, v7[0h]
    lh    v1, 0x0c(s4)
    vmadn v4, v27, v6[0h]
    lh    t6, 0x06(s5)
    vmadn v4, v26, v5[0h]
    lh    a2, 0x06(s4)
    lh    t2, 0x0e(s5)
    addi  s2, s2, -0x10
    sqv   v4[0], 0x00(s3)
    blez  s2, @@audio_04001ad8
     lh    v0, 0x0e(s4)
    j     @@audio_040019d8
     addi  s3, s3, 0x0010
@@audio_04001ad8:
    ssv   v23[0], 0x08(s7)
    ldv   v16[0], 0x00(s1)
    sdv   v16[0], 0x00(s7)
    lh    a2, (audio_in_buf)(t8)
    addi  s1, s1, 8
    sub   a1, s1, a2
    andi  a0, a1, 0x000f
    sub   s1, s1, a0
    beqz  a0, @@audio_04001b04
     addi  a3, zero, 0x10
    sub   a0, a3, a0
@@audio_04001b04:
    sh    a0, 0x0a(s7)
    ldv   v3[0], 0x00(s1)
    ldv   v3[8], 0x08(s1)
    sqv   v3[0], 0x10(s7)
    lw    v0, 0x40(s7)
    addi  at, s7, 0x00
    jal   dma_write_start
     addi  v1, zero, 0x1f
@@dma_write_busy:
    mfc0  a1, SP_DMA_BUSY
    bnez  a1, @@dma_write_busy
     nop
    j     cmd_SPNOOP
     mtc0  zero, SP_SEMAPHORE

cmd_ENVMIXER:
    lui   a0, 0x00ff
    ori   a0, a0, 0xffff
    and   v0, t9, a0
    srl   a1, t9, 24
    sll   a1, a1, 2
    lw    a2, (segmentTable)(a1)
    add   v0, v0, a2
    addi  at, s7, 0x00
    addi  v1, zero, 0x4f
    vxor  v0, v0, v0
    addi  t3, zero, 0x40
    lqv   v31[0], 0x10(t3)    // all 0001
    lqv   v10[0], 0x00(zero)  // element 6 is 0x7fff
    srl   t4, k0, 16
    andi  t2, t4, A_INIT
    beqz  t2, @@audio_04001b84
     lqv   v24[0], 0x10(t8)
    j     @@audio_04001bb0
     nop
@@audio_04001b84:
    jal   dma_read_start
     nop
@@dma_read_busy:
    mfc0  a1, SP_DMA_BUSY
    bnez  a1, @@dma_read_busy
     nop
    mtc0  zero, SP_SEMAPHORE
    lqv   v20[0], 0x00(s7)
    lqv   v21[0], 0x10(s7)
    lqv   v18[0], 0x20(s7)
    lqv   v19[0], 0x30(s7)
    lqv   v24[0], 0x40(s7)
@@audio_04001bb0:
    lh    t5, (audio_in_buf)(t8)
    lh    s3, (audio_out_buf)(t8)
    lh    s2, (audio_aux_buf0)(t8)
    lh    s1, (audio_aux_buf1)(t8)
    lh    s0, (audio_aux_buf2)(t8)
    lh    t6, (audio_count)(t8)
    addi  t7, zero, 0x10
    mfc2  s5, v24[2]
    mfc2  s4, v24[8]
    andi  t1, t4, 0x0008
    bgtz  t1, @@audio_04001bec
     nop
    addi  s1, s7, 0x50
    add   s0, zero, s1
    addi  t7, zero, 0
@@audio_04001bec:
    beqz  t2, @@audio_04001cf0
     lqv   v30[0], 0x70(t3)
    lqv   v17[0], 0x00(t5)
    lqv   v29[0], 0x00(s3)
    lqv   v27[0], 0x00(s1)
    vxor  v21, v21, v21
    lsv   v20[14], 0x06(t8)
    vmudm v23, v20, v24[2]
    vmadh v22, v20, v24[1]
    vmadn v23, v31, v0[0]
    vsubc v23, v23, v21
    vsub  v22, v22, v20
    vmudl v23, v30, v23[7]
    vmadn v23, v30, v22[7]
    vmadm v22, v31, v0[0]
    vmadm v21, v31, v21[7]
    vmadh v20, v31, v20[7]
    bgtz  s5, @@audio_04001c44
     vmadn v21, v31, v0[0]
    vge   v20, v20, v24[0]
    j     @@audio_04001c48
     nop
@@audio_04001c44:
    vcl   v20, v20, v24[0]
@@audio_04001c48:
    vmulf v16, v20, v24[6]
    vmulf v15, v20, v24[7]
    vmulf v29, v29, v10[6]
    vmacf v29, v17, v16
    vmulf v27, v27, v10[6]
    vmacf v27, v17, v15
    sqv   v29[0], 0x00(s3)
    sqv   v27[0], 0x00(s1)
    lqv   v28[0], 0x00(s2)
    lqv   v26[0], 0x00(s0)
    vxor  v19, v19, v19
    lsv   v18[14], 0x08(t8)
    vmudm v23, v18, v24[5]
    vmadh v22, v18, v24[4]
    vmadn v23, v31, v0[0]
    vsubc v23, v23, v19
    vsub  v22, v22, v18
    vmudl v23, v30, v23[7]
    vmadn v23, v30, v22[7]
    vmadm v22, v31, v0[0]
    vmadm v19, v31, v19[7]
    vmadh v18, v31, v18[7]
    bgtz  s4, @@audio_04001cb4
     vmadn v19, v31, v0[0]
    vge   v18, v18, v24[3]
    j     @@audio_04001cb8
     nop
@@audio_04001cb4:
    vcl   v18, v18, v24[3]
@@audio_04001cb8:
    vmulf v16, v18, v24[6]
    vmulf v15, v18, v24[7]
    vmulf v28, v28, v10[6]
    vmacf v28, v17, v16
    vmulf v26, v26, v10[6]
    vmacf v26, v17, v15
    sqv   v28[0], 0x00(s2)
    sqv   v26[0], 0x00(s0)
    addi  t6, t6, -0x10
    addi  t5, t5, 0x10
    addi  s3, s3, 0x10
    addi  s2, s2, 0x10
    add   s1, s1, t7
    add   s0, s0, t7
@@audio_04001cf0:
    vmudl v23, v21, v24[2]
    vmadm v23, v20, v24[2]
    vmadn v23, v21, v24[1]
    vmadh v20, v20, v24[1]
    vmadn v21, v31, v0[0]
@@audio_04001d04:
    bgtz  s5, @@audio_04001d30
     lqv   v17[0], 0x00(t5)
    vge   v20, v20, v24[0]
    vmudl v23, v19, v24[5]
    vmadm v23, v18, v24[5]
    vmadn v23, v19, v24[4]
    lqv   v29[0], 0x00(s3)
    vmadh v18, v18, v24[4]
    lqv   v27[0], 0x00(s1)
    j     @@audio_04001d50
     vmadn v19, v31, v0[0]
@@audio_04001d30:
    vcl   v20, v20, v24[0]
    vmudl v23, v19, v24[5]
    vmadm v23, v18, v24[5]
    vmadn v23, v19, v24[4]
    lqv   v29[0], 0x00(s3)
    vmadh v18, v18, v24[4]
    lqv   v27[0], 0x00(s1)
    vmadn v19, v31, v0[0]
@@audio_04001d50:
    vmulf v16, v20, v24[6]
    sqv   v20[0], 0x00(s7)
    vmulf v15, v20, v24[7]
    sqv   v21[0], 0x10(s7)
    vmulf v29, v29, v10[6]
    vmacf v29, v17, v16
    lqv   v28[0], 0x00(s2)
    vmulf v27, v27, v10[6]
    lqv   v26[0], 0x00(s0)
    vmacf v27, v17, v15
    bgtz  s4, @@audio_04001da0
     sqv   v29[0], 0x00(s3)
    vge   v18, v18, v24[3]
    vmudl v23, v21, v24[2]
    sqv   v27[0], 0x00(s1)
    vmadm v23, v20, v24[2]
    vmadn v23, v21, v24[1]
    vmadh v20, v20, v24[1]
    j     @@audio_04001dbc
     vmadn v21, v31, v0[0]
@@audio_04001da0:
    vcl   v18, v18, v24[3]
    vmudl v23, v21, v24[2]
    sqv   v27[0], 0x00(s1)
    vmadm v23, v20, v24[2]
    vmadn v23, v21, v24[1]
    vmadh v20, v20, v24[1]
    vmadn v21, v31, v0[0]
@@audio_04001dbc:
    vmulf v16, v18, v24[6]
    addi  t6, t6, -0x10
    vmulf v15, v18, v24[7]
    addi  s3, s3, 0x10
    vmulf v28, v28, v10[6]
    add   s1, s1, t7
    vmacf v28, v17, v16
    addi  t5, t5, 0x10
    vmulf v26, v26, v10[6]
    vmacf v26, v17, v15
    sqv   v28[0], 0x00(s2)
    addi  s2, s2, 0x10
    blez  t6, @@audio_04001dfc
     sqv   v26[0], 0x00(s0)
    j     @@audio_04001d04
     add   s0, s0, t7
@@audio_04001dfc:
    sqv   v18[0], 0x20(s7)
    sqv   v19[0], 0x30(s7)
    sqv   v24[0], 0x40(s7)
    jal   dma_write_start
     addi  v1, zero, 0x004f
@@dma_write_busy:
    mfc0  a1, SP_DMA_BUSY
    bnez  a1, @@dma_write_busy
     nop
    j     cmd_SPNOOP
     mtc0  zero, SP_SEMAPHORE

cmd_MIXER:
    lqv   v31[0], 0x00(zero)   // element 6 is 0x7fff
    lhu   s2, (audio_count)(t8)
    beqz  s2, @@cmd_mixer_done // skip operation when count is 0
     nop
    andi  s3, t9, 0xffff
    addi  s3, s3, dmemBase     // dmemout + DMEM_BASE
    srl   s4, t9, 16
    addi  s4, s4, dmemBase     // dmemin + DMEM_BASE
    andi  s1, k0, 0xffff
    mtc2  s1, v30[0]
    lqv   v27[0], 0x00(s3)
    lqv   v29[0], 0x00(s4)
    lqv   v26[0], 0x10(s3)
    lqv   v28[0], 0x10(s4)
@@audio_04001e5c:
    vmulf v27, v27, v31[6]
    addi  s2, s2, -0x20
    vmacf v27, v29, v30[0]
    addi  s4, s4, 0x20
    sqv   v27[0], 0x00(s3)
    vmulf v26, v26, v31[6]
    lqv   v29[0], 0x00(s4)
    vmacf v26, v28, v30[0]
    lqv   v28[0], 0x10(s4)
    sqv   v26[0], 0x10(s3)
    addi  s3, s3, 0x20
    lqv   v27[0], 0x00(s3)
    bgtz  s2, @@audio_04001e5c
     lqv   v26[0], 0x10(s3)
@@cmd_mixer_done:
    j     cmd_SPNOOP
     nop
    nop

.close // CODE_FILE
