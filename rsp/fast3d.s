.rsp

.include "rsp/rsp_defs.inc"
.include "rsp/gbi.inc"

// This file assumes DATA_FILE and CODE_FILE are set on the command line

.if version() < 110
    .error "armips 0.11 or newer is required"
.endif

// Overlay table data member offsets
overlay_load equ 0x0000
overlay_len  equ 0x0004
overlay_imem equ 0x0006
.macro OverlayEntry, loadStart, loadEnd, imemAddr
  .dw loadStart
  .dh (loadEnd - loadStart - 1) & 0xFFFF
  .dh (imemAddr) & 0xFFFF
.endmacro

.macro jumpTableEntry, addr
  .dh addr & 0xFFFF
.endmacro

// RSP DMEM
.create DATA_FILE, 0x0000

// 0x0000-0x0027: Overlay Table
overlayInfo0:
  OverlayEntry orga(Overlay0Address), orga(Overlay0End), Overlay0Address
overlayInfo1:
  OverlayEntry orga(Overlay1Address), orga(Overlay1End), Overlay1Address
overlayInfo2:
  OverlayEntry orga(Overlay2Address), orga(Overlay2End), Overlay2Address
overlayInfo3:
  OverlayEntry orga(Overlay3Address), orga(Overlay3End), Overlay3Address
overlayInfo4:
  OverlayEntry orga(Overlay4Address), orga(Overlay4End), Overlay4Address

// 0x0028-0x009F: ??
.dw 0x0FFAF006
.dw 0x7FFF0000
.dw 0x00000001
.dw 0x0002FFFF
.dw 0x40000004
.dw 0x06330200
.dw 0x7FFFFFF8
.dw 0x00080040
.dw 0x00208000
.dw 0x01CCCCCC
.dw 0x0001FFFF
.dw 0x00010001
.dw 0x0001FFFF
.dw 0x00010001
.dw 0x00020002
.dw 0x00020002

// 0x0068
.dw 0x00020002
.dw 0x00020002

data0070:
.dw 0x00010000

// 0x0074
.dh 0x0000
// 0x0076
.dh 0x0001

// 0x0078
.dw 0x00000001
.dw 0x00000001
.dw 0x00010000
.dw 0x0000FFFF
.dw 0x00000001
.dw 0x0000FFFF
.dw 0x00000000
.dw 0x0001FFFF
.dw 0x00000000
.dw 0x00010001

// 0x00A0-0x00A1
lightEntry:
  jumpTableEntry load_lighting

// 0x00A2-0x00A3: ??
.dh 0x7FFF

// 0x00A4-0x00B3: ??
.dw 0x571D3A0C
.dw 0x00010002
.dw 0x01000200
.dw 0x40000040

// 0x00B4
.dh 0x0000

// 0x00B6-0x00B7
taskDoneEntry:
  jumpTableEntry overlay_4_entry

// 0x00B8
lower24Mask:
.dw 0x00FFFFFF

// 0x00BC: Operation Types
operationJumpTable:
  jumpTableEntry dispatch_dma // cmds 0x00-0x3f
spNoopEntry:
  jumpTableEntry SP_NOOP      // cmds 0x40-0x7f
  jumpTableEntry dispatch_imm // cmds 0x80-0xbf
  jumpTableEntry dispatch_rdp // cmds 0xc0-0xff

// 0x00C4: DMA operations
dmaJumpTable:
  jumpTableEntry SP_NOOP       // 0x00
  jumpTableEntry dma_MTX     // 0x01
  jumpTableEntry SP_NOOP       // 0x02
  jumpTableEntry dma_MOVEMEM // 0x03
  jumpTableEntry dma_VTX     // 0x04
  jumpTableEntry SP_NOOP       // 0x05
  jumpTableEntry dma_DL      // 0x06
  jumpTableEntry SP_NOOP       // 0x07
  jumpTableEntry SP_NOOP       // 0x08
  jumpTableEntry SP_NOOP       // 0x09

// 0x00D8: Immediate operations
immediateJumpTableBase equ (immediateJumpTable - ((0xB2 << 1) & 0xFE))
.ifdef F3D_OLD
  jumpTableEntry imm_UNKNOWN
.endif
immediateJumpTable:
  jumpTableEntry imm_RDPHALF_CONT      // 0xB2
  jumpTableEntry imm_RDPHALF_2         // 0xB3
  jumpTableEntry imm_RDPHALF_1         // 0xB4
  jumpTableEntry SP_NOOP               // 0xB5?
  jumpTableEntry imm_CLEARGEOMETRYMODE // 0xB6
  jumpTableEntry imm_SETGEOMETRYMODE   // 0xB7
  jumpTableEntry imm_ENDDL             // 0xB8
  jumpTableEntry imm_SETOTHERMODE_L    // 0xB9
  jumpTableEntry imm_SETOTHERMODE_H    // 0xBA
  jumpTableEntry imm_TEXTURE           // 0xBB
  jumpTableEntry imm_MOVEWORD          // 0xBC
  jumpTableEntry imm_POPMTX            // 0xBD
  jumpTableEntry imm_CULLDL            // 0xBE
  jumpTableEntry imm_TRI1              // 0xBF

// 0x00F6: Label constants
labelLUT:
  jumpTableEntry found_in
foundOutEntry:
  jumpTableEntry found_out
  jumpTableEntry found_first_in
  jumpTableEntry found_first_out
clipDrawEntry:
  jumpTableEntry clip_draw_loop
performClipEntry:
  jumpTableEntry perform_clip
nextClipEntry:
  jumpTableEntry next_clip
DMAWaitEntry:
  jumpTableEntry dma_wait_dl

// 0x0106: ??
data0106:
.dh 0x0000

.ifdef F3D_NEW
.dh 0x0000
.endif

// 0x0108: DRAM pointer
dramPtr:
.dw 0x00000000
.dh 0x0000     // 0x10C: RDPHALF_2

.dh 0x0000

// 0x110: display list stack size
displayListStackSize:
.dh 0x0000
.dh 0xFFFF     // 0x112: RDPHALF_1

.dw 0x00000000 // 0x114: geometrymode (bit 1 is texture ON)
.dw 0xEF080CFF // 0x118: othermode
.dw 0x00000000
.dw 0x00000000 // 0x120: texture max mipmap levels, tile descriptor enable/disable
.dh 0x0000     // 0x124: texture scaling factor S axis (horizontal) U16 fraction
.dh 0x0000     // 0x126: texture scaling factor T axis (vertical)
.dw 0x00000000 // 0x128: some dpc dma address state

numLights:
.dw 0x80000040 // 0x12c: num lights, bit 31 = needs init, bits 11:0 = (num_lights+1)*32
.dw 0x00000000 // 0x130: dram stack pointer 1
.dw 0x00000000 // 0x134: dram stack pointer modelview matrices

data0138:
.dw 0x40004000 // 0x138: txtatt (unused?)

.dw 0x00000000
.dw 0x00000000
.dw 0x00000000
.dw 0x00000000
.dw 0x00000000

.dw 0x00000000 // 0x150: output buffer

.dw 0x00000000 // 0x154: output buffer size

data0158:
.dh 0x0000     // 0x158: ??
.dh 0x0000
.dw 0x00000000 // 0x15c: dram stack end?

// 0x160-0x19f: RSP memory segment table
segmentTable:
.fill 0x40, 0

// 0x1a0: Lights
.dw 0x80000000
.dw 0x80000000
.dw 0x00000000
.dw 0x00000000

lookAtY:       // 0x1b0: lookaty
.dw 0x00800000, 0x00800000, 0x7F000000, 0x00000000
.dw 0x00000000, 0x00000000, 0x00000000, 0x00000000

lookAtX:       // 0x1d0: lookatx
.dw 0x00000000, 0x00000000, 0x007F0000, 0x00000000
.dw 0x00000000, 0x00000000, 0x00000000, 0x00000000

// 0x1f0: L0..L7 light info (32 bytes each)
lightInfo0: // 0x1f0
.dw 0x00000000, 0x00000000, 0x00000000, 0x00000000
.dw 0x00000000, 0x00000000, 0xE0011FFF, 0x00040000

lightInfo1: // 0x210
.dw 0xFF000000, 0xFF000000, 0x00000000, 0x00000000
.dw 0x00000000, 0x00000000, 0x00000000, 0x00000000

lightInfo2: // 0x230
.dw 0x00000000, 0x00000000, 0x00000000, 0x00000000
.dw 0x00000000, 0x00000000, 0x00000000, 0x00000000

lightInfo3: // 0x250
.dw 0x00000000, 0x00000000, 0x00000000, 0x00000000
.dw 0x00000000, 0x00000000, 0x00000000, 0x00000000

lightInfo4: // 0x270

// L4-L7 overlap with version string
.definelabel lightInfo5, lightInfo4 + 0x20 // 0x290
.definelabel lightInfo6, lightInfo5 + 0x20 // 0x2b0
.definelabel lightInfo7, lightInfo6 + 0x20 // 0x2d0

.if defined(F3D_OLD) || defined(VERSION_EU)
  .asciiz "RSP SW Version: 2.0D, 04-01-96"
.elseif defined(F3D_NEW)
  .asciiz "RSP SW Version: 2.0H, 02-12-97"
.endif
.asciiz "SGI U64 GFX SW TEAM: S Anderson, S Carr, H Cheng, K Luster, R Moore, N Pooley, A Srinivasan", 0x0A

.dw 0x00000000

// 0x2f0-0x31f: DMEM table
dmemTableOffset equ (dmemTable - 0x80)
dmemTable:
  .dh viewport,   lookAtY,    lookAtX,      lightInfo0, lightInfo1,    lightInfo2,    lightInfo3,    lightInfo4
  .dh lightInfo5, lightInfo6, lightInfo7,   data0138,   mpMatrix+0x10, mpMatrix+0x20, mpMatrix+0x30, mpMatrix
  .dh numLights,  data0070,   segmentTable, fogFactors, lightInfo0,    pointsBuffer
.ifdef F3D_NEW
  .dh displayListStackSize, 0x0000
.else
  .dh 0x0000, 0x0000
.endif

// 0x320: Viewport (0x010 bytes)
viewport:
.dw 0x00000000, 0x00000000, 0x00000000, 0x00000000

// 0x330: fog factors (three 16-bit integers: mul, add, min)
fogFactors:
.dh 0x0100, 0x0000, 0x00FF

// 0x336: display list stack (return addresses)
displayListStack: // this is not 4-byte aligned
.fill 0x2a, 0

// 0x360-0x39f: Modelview matrix top of stack (0x40 bytes)
modelViewMatrixStack:
.fill 0x40, 0

// 0x3a0-0x3df Projection Matrix top of stack (0x40 bytes)
projectionMatrixStack:
.fill 0x40, 0

// 0x3e0-0x41f: MP matrix (Modelview * Projection)
mpMatrix:
.fill 0x40, 0

// 0x420: Points buffer (0x280 bytes)
pointsBuffer:
.fill 0x280, 0

// 0x6a0-0x7df: input display list buffer
inputDisplayList:
.fill 0x140, 0

// 0x7E0-0x7ff: input data
inputData:
.fill (0x800 - 0x7E0), 0

.close // DATA_FILE

// uninitialized variables
.definelabel setupTemp, 0x08E0
.definelabel data08e4, 0x08E4
.definelabel data08e8, 0x08E8
.definelabel data08ec, 0x08EC
.definelabel data08f0, 0x08F0
.definelabel clipTemp, 0x0940
.definelabel data0942, 0x0942
.definelabel data0944, 0x0944
.definelabel data0946, 0x0946
.definelabel rdpOutput, 0x09E0
.definelabel scratchSpace, 0x0DE0
.definelabel data0DE4, 0x0DE4
.definelabel data0DE8, 0x0DE8

.create CODE_FILE, 0x04001080

// Overlay 0
Overlay0Address:
    j     f3d_04001780
     addi  sp, zero, displayListStackSize
    jal   segmented_to_physical
     add   s3, t8, zero
    add   s4, zero, s6
    jal   dma_read_write
     addi  s1, zero, 0x00

// at = most significant 2 bits of cmd byte << 1
// t9 = first command word
dispatch_task:
    lh    v0, (operationJumpTable)(at)
    jr    v0
     srl   v0, t9, 23        // v0 = MSbyte << 1

SP_NOOP:
    mfc0  v0, SP_STATUS
    andi  v0, v0, 0x0080
    bne   v0, zero, f3d_040010cc
     lh    s5, 0x26(zero)
f3d_040010b8:
    bgtz  gp, read_next_task_entry
     nop
    j     load_display_list_dma
     lh    ra, DMAWaitEntry
f3d_040010c8:
    lh    s5, taskDoneEntry
f3d_040010cc:
    j     load_overlay
     ori   s8, zero, overlayInfo4

load_display_list_dma:
    addi  gp, zero, 0x0140   // size of display list
    add   s5, zero, ra
    addi  s4, zero, inputDisplayList
    add   s3, zero, k0       // TASK_DATA_PTR
    addi  s2, zero, 0x013f
    jal   dma_read_write
     addi  s1, zero, 0x00
    jr    s5
     addi  k1, zero, inputDisplayList // initial pointer

// load overlay into IMEM
// s8 = offset into overlay table
// s5 = return address
load_overlay_fcn:
    add   s5, zero, ra
load_overlay:
    lw    s3, overlay_load(s8)
    lh    s2, overlay_len(s8)
    lh    s4, overlay_imem(s8)
    jal   dma_read_write
     addi  s1, zero, 0x00
    jal   wait_while_dma_busy
     nop
    jr    s5

segmented_to_physical:
     lw    t3, lower24Mask
    srl   t4, s3, 22
    andi  t4, t4, 0x3c
    and   s3, s3, t3
    add   t5, zero, t4
    lw    t4, 0x0160(t5)
    jr    ra
     add   s3, s3, t4

// s4 = SP_MEM address
// s3 = DRAM address
// s2 = length - 1
// s1 = 1:write, 0:read
dma_read_write:
@@dma_full:
    mfc0  t3, SP_DMA_FULL
    bne   t3, zero, @@dma_full
     nop
    mtc0  s4, SP_MEM_ADDR
    bgtz  s1, @@dma_write
     mtc0  s3, SP_DRAM_ADDR
    jr    ra
     mtc0  s2, SP_RD_LEN
@@dma_write:
    jr    ra
     mtc0  s2, SP_WR_LEN

wait_while_dma_busy:
    mfc0  t3, SP_DMA_BUSY
    bne   t3, zero, wait_while_dma_busy
     nop
    jr    ra
     nop

f3d_04001178:                // sends stuff to RDP
    add   s5, zero, ra
    lw    s3, 0x18(sp)
    addi  s2, s7, -0x09e0
    lw    s7, 0x44(sp)
    blez  s2, f3d_040011f4
     add   s4, s3, s2
    sub   s4, s7, s4
    bgez  s4, f3d_040011b8
f3d_04001198:
     mfc0  s4, DPC_STATUS
    andi  s4, s4, DPC_STATUS_START_VALID
    bne   s4, zero, f3d_04001198
f3d_040011a4:
     mfc0  s7, DPC_CURRENT
    lw    s3, 0x40(sp)
    beq   s7, s3, f3d_040011a4
     nop
    mtc0  s3, DPC_START
f3d_040011b8:
    mfc0  s7, DPC_CURRENT
    sub   s4, s3, s7
    bgez  s4, f3d_040011d4
     add   s4, s3, s2
    sub   s4, s4, s7
    bgez  s4, f3d_040011b8
     nop
f3d_040011d4:
    add   s7, s3, s2
    addi  s2, s2, -0x01
    addi  s4, zero, rdpOutput   // output to RDP
    jal   dma_read_write
     addi  s1, zero, 0x01
    jal   wait_while_dma_busy
     sw    s7, 0x18(sp)
    mtc0  s7, DPC_END
f3d_040011f4:
    jr    s5
     addi  s7, zero, rdpOutput

// codes 0x80-0xBF
// v0 = immediate cmd byte << 1
dispatch_imm:
    andi  v0, v0, 0x00fe
    lh    v0, (immediateJumpTableBase)(v0) // data IMM offset
    jr    v0
     lbu   at, -0x01(k1)

imm_TRI1:
    lbu   a1, -0x04(k1)
    lbu   at, -0x03(k1)
    lbu   v0, -0x02(k1)
    lbu   v1, -0x01(k1)
    sll   a1, a1, 2
    sll   at, at, 2
    sll   v0, v0, 2
    sll   v1, v1, 2
    addi  at, at, pointsBuffer
    addi  v0, v0, pointsBuffer
    addi  v1, v1, pointsBuffer
    sw    at, scratchSpace
    sw    v0, data0DE4
    sw    v1, data0DE8
    lw    a0, (scratchSpace)(a1)
    j     f3d_04001998
     lh    s8, spNoopEntry

imm_POPMTX:
.ifdef F3D_NEW
    sbv   v31[6], 0x1c(sp)
.endif
    lw    s3, 0x24(sp)
    lw    v1, 0x4c(sp)
    addi  s4, zero, modelViewMatrixStack
    addi  s2, zero, 0x3f
    sub   v1, v1, s3
    addi  v1, v1, -0x0280
    bgez  v1, SP_NOOP         // stop if stack is empty
     addi  s3, s3, -0x40
    jal   dma_read_write      // read new top from DRAM
     addi  s1, zero, 0x00
    jal   wait_while_dma_busy
     addi  v1, zero, mpMatrix // MP matrix (modelview * projection)
    j     f3d_04001444        // recompute MP matrix
     sw    s3, 0x24(sp)

imm_MOVEWORD:
    lbu   at, -0x05(k1)
    lhu   v0, -0x07(k1)
    lh    a1, 0x030e(at)
    add   a1, a1, v0
    j     SP_NOOP
     sw    t8, 0x00(a1)

imm_TEXTURE:
    sw    t9, 0x10(sp)
    sw    t8, 0x14(sp)
    lh    v0, 0x06(sp)
    andi  v0, v0, 0xfffd
    andi  v1, t9, 0x0001
    sll   v1, v1, 1
    or    v0, v0, v1
    j     SP_NOOP
     sh    v0, 0x06(sp)

imm_SETOTHERMODE_H:
    j     @f3d_040012d0
     addi  a3, sp, 8
imm_SETOTHERMODE_L:
    addi  a3, sp, 0x0c
@f3d_040012d0:
    lw    v1, 0x00(a3)
    addi  t0, zero, -1
    lbu   a1, -0x05(k1)
    lbu   a2, -0x06(k1)
    addi  v0, zero, 1
    sllv  v0, v0, a1
    addi  v0, v0, -1
    sllv  v0, v0, a2
    xor   v0, v0, t0
    and   v0, v0, v1
    or    v1, v0, t8
    sw    v1, 0x00(a3)
    lw    t9, 0x08(sp)
    j     f3d_040013a8
     lw    t8, 0x0c(sp)

imm_CULLDL:
    andi  t9, t9, 0x03ff
.ifdef F3D_OLD
    ori   v0, zero, 0xffff
.else
    ori   v0, zero, 0x7070
.endif
@@f3d_04001314:
    lh    v1, 0x0444(t9)
    addi  t9, t9, 0x28
    bne   t9, t8, @@f3d_04001314
     and   v0, v0, v1
    beq   v0, zero, SP_NOOP

DL_STACK_SIZE_OFFSET equ (defined(F3D_OLD) ? 0x00 : 0x4A)

imm_ENDDL:
     lb    v0, (DL_STACK_SIZE_OFFSET)(sp)
    addi  v0, v0, -4
    bltz  v0, f3d_040010c8
     addi  v1, v0, displayListStack
    lw    k0, 0x00(v1)
    sb    v0, (DL_STACK_SIZE_OFFSET)(sp)
    j     SP_NOOP
     addi  gp, zero, 0

imm_SETGEOMETRYMODE:
    lw    v0, 0x04(sp)
    or    v0, v0, t8
    j     SP_NOOP
     sw    v0, 0x04(sp)

imm_CLEARGEOMETRYMODE:
    lw    v0, 0x04(sp)
    addi  v1, zero, -1
    xor   v1, v1, t8
    and   v0, v0, v1
    j     SP_NOOP
     sw    v0, 0x04(sp)

.ifdef F3D_OLD
imm_RDPHALF_1:
    j     SP_NOOP
     sh    t8, 0x02(sp)
imm_RDPHALF_2:
.else
imm_RDPHALF_1:
.endif
    j     f3d_040010b8
     sw    t8, -0x04(sp)

.ifdef F3D_OLD
imm_UNKNOWN:
.else
imm_RDPHALF_CONT:
.endif
    ori   v0, zero, 0x0000
.ifdef F3D_OLD
imm_RDPHALF_CONT:
.else
imm_RDPHALF_2:
.endif
    j     f3d_040013a8
     lw    t9, -0x04(sp)

// codes 0xC0-0xFF
dispatch_rdp:
    sra   v0, t9, 24
    addi  v0, v0, 3
    bltz  v0, f3d_040013a8
     addi  v0, v0, 0x18
    jal   segmented_to_physical
     add   s3, t8, zero
    add   t8, s3, zero
f3d_040013a8:
    sw    t9, 0x00(s7)
    sw    t8, 0x04(s7)
    jal   f3d_04001178
     addi  s7, s7, 0x08
    bgtz  v0, SP_NOOP
     nop
    j     f3d_040010b8

dispatch_dma:
     andi  v0, v0, 0x01fe
    lh    v0, (dmaJumpTable)(v0)
    jal   wait_while_dma_busy
     lbu   at, -0x07(k1)
    jr    v0
     andi  a2, at, 0x000f

dma_MTX:
    sbv   v31[6], 0x1c(sp)     // lights need re-init
    andi  t0, at, 0x0001       // 1=projection, 0=modelview
    bne   t0, zero, f3d_04001454
     andi  a3, at, 0x0002      // 1=load, 0=multiply
    addi  s4, zero, modelViewMatrixStack
    andi  t0, at, 0x0004       // 1=push, 0=no push
    beq   t0, zero, f3d_04001420
     lqv   v26[0], 0x30(s6)
    lw    s3, 0x24(sp)         // DRAM stack pointer 2
    lw    t0, 0x4c(sp)         // DRAM stack end
    addi  s1, zero, 1
    addi  at, s3, 0x40
    beq   s3, t0, f3d_04001420
     addi  t4, zero, 0x3f      // BUG: wrong register, should be s2
    jal   dma_read_write
     sw    at, 0x24(sp)
    jal   wait_while_dma_busy
f3d_04001420:
     lqv   v28[0], 0x10(s6)
    beq   a3, zero, f3d_04001460
     lqv   v27[0], 0x20(s6)
    sqv   v26[0], 0x30(s4)
    lqv   v29[0], 0x00(s6)
    sqv   v28[0], 0x10(s4)
f3d_04001438:
    addi  v1, zero, mpMatrix
    sqv   v27[0], 0x20(s4)
    sqv   v29[0], 0x00(s4)
f3d_04001444:
    addi  at, zero, modelViewMatrixStack
    addi  v0, zero, projectionMatrixStack
    j     f3d_04001484
     lh    ra, spNoopEntry
f3d_04001454:
    lqv   v26[0], 0x30(s6)
    j     f3d_04001420
     addi  s4, zero, projectionMatrixStack
f3d_04001460:
    addiu v1, zero, scratchSpace
    addu  at, zero, s6         // input matrix from user
    jal   f3d_04001484
     addu  v0, zero, s4        // current P matrix or M top
    sqv   v6[0], 0x30(s4)      // store result to P or M
    sqv   v5[0], 0x10(s4)
    lqv   v27[0], 0x00(v1)
    j     f3d_04001438
     lqv   v29[0], -0x20(v1)
f3d_04001484:
    addi  s3, v1, 0x10
f3d_04001488:
    vmudh v5, v31, v31[0]      // clear accumulator and v5
    addi  s2, at, 8
f3d_04001490:
    ldv   v3[0], 0x00(v0)
    ldv   v4[0], 0x20(v0)
    lqv   v1[0], 0x00(at)
    lqv   v2[0], 0x20(at)
    ldv   v3[8], 0x00(v0)
    ldv   v4[8], 0x20(v0)
    vmadl v6, v4, v2[0h]
    addi  at, at, 2
    vmadm v6, v3, v2[0h]
    addi  v0, v0, 8
    vmadn v6, v4, v1[0h]
    vmadh v5, v3, v1[0h]
    bne   at, s2, f3d_04001490
     vmadn v6, v31, v31[0]
    addi  v0, v0, -0x20
    addi  at, at, 8
    sqv   v5[0], 0x00(v1)
    sqv   v6[0], 0x20(v1)
    bne   v1, s3, f3d_04001488
     addi  v1, v1, 0x10
    jr    ra
     nop
f3d_040014e8:
    addi  t0, zero, viewport
    lqv   v3[0], 0x50(zero)
    lsv   v19[0], 0x02(sp)     // RDPHALF_1, contains persp normalize
    lh    v1, 0x04(sp)         // geometrymode
    ldv   v0[0], 0x00(t0)      // viewport scale
    ldv   v1[0], 0x08(t0)      // viewport translate
    ldv   v0[8], 0x00(t0)
    ldv   v1[8], 0x08(t0)
    jr    ra
     vmudh v0, v0, v3          // negate Y?

load_mp_matrix:
    addi  t0, zero, mpMatrix
    ldv   v11[0], 0x18(t0)     // load into v8-v15, dup lower half and higher half
    ldv   v11[8], 0x18(t0)     // v8-v11 integer parts, v12-v15 frac parts
    ldv   v15[0], 0x38(t0)
    ldv   v15[8], 0x38(t0)
f3d_04001524:
    ldv   v8[0], 0x00(t0)
    ldv   v9[0], 0x08(t0)
    ldv   v10[0], 0x10(t0)
    ldv   v12[0], 0x20(t0)
    ldv   v13[0], 0x28(t0)
    ldv   v14[0], 0x30(t0)
    ldv   v8[8], 0x00(t0)
    ldv   v9[8], 0x08(t0)
    ldv   v10[8], 0x10(t0)
    ldv   v12[8], 0x20(t0)
    ldv   v13[8], 0x28(t0)
    jr    ra
     ldv   v14[8], 0x30(t0)

dma_MOVEMEM:
    lqv   v0[0], 0x00(s6)
    lh    a1, (dmemTableOffset)(at)
    j     SP_NOOP
     sqv   v0[0], 0x00(a1)

dma_VTX:
    lh    t0, spNoopEntry
    sh    t0, data0106
    srl   at, at, 4
    addi  a1, at, 1            // num vertex
    addi  t1, a1, 0
    ldv   v2[0], 0x00(s6)      // input data
    ldv   v2[8], 0x10(s6)      // load 2nd vertex (assuming it exists)
    addi  a3, zero, pointsBuffer
    sll   t0, a2, 5            // dest index
    sll   a2, a2, 3
    add   t0, a2, t0           // 40 bytes per vertex
    jal   f3d_040014e8
     add   a3, a3, t0
    llv   v17[0], 0x14(sp)     // texture scaling
    jal   load_mp_matrix
     llv   v17[8], 0x14(sp)
@f3d_040015a8:
    vmudn v28, v12, v2[0h]     // x * first row frac
    llv   v18[0], 0x08(s6)
    vmadh v28, v8, v2[0h]      // x * first row int
    lw    t7, 0x0c(s6)         // XR, YG, ZB, AA
    vmadn v28, v13, v2[1h]     // y * second row frac
    lw    s0, 0x1c(s6)
    vmadh v28, v9, v2[1h]      // y * second row int
    andi  at, v1, G_LIGHTING_H
    vmadn v28, v14, v2[2h]     // z * third row frac
    vmadh v28, v10, v2[2h]     // z * third row int
    vmadn v28, v15, v31[1]     // 1 * fourth row frac
    llv   v18[8], 0x18(s6)
    vmadh v29, v11, v31[1]     // 1 * fourth row int
    bne   at, zero, load_lighting
     addi  s6, s6, 0x20        // next 2 vertices
@f3d_040015e4:
    vmudm v18, v18, v17        // U *= S scale, V *= T scale (result >> 16)
@f3d_040015e8:
    lsv   v21[0], 0x76(zero)
    vmudn v20, v28, v21[0]
    vmadh v21, v29, v21[0]
    vch   v3, v29, v29[3h]     // do trivial clip rejection
    vcl   v3, v28, v28[3h]     // by comparing xyz with w
    cfc2  t5, vcc
    vch   v3, v29, v21[3h]
    vcl   v3, v28, v20[3h]
    andi  t0, t5, 0x0707       // filter out xyz clip result for 1st vertex
    andi  t5, t5, 0x7070       // filter out xyz clip result for 2nd vertex
    sll   t0, t0, 4
    sll   t5, t5, 16
    or    t5, t5, t0
    cfc2  t6, vcc
    andi  t0, t6, 0x0707
    vadd  v21, v29, v31[0]
    andi  t6, t6, 0x7070
    vadd  v20, v28, v31[0]
    sll   t6, t6, 12
    vmudl v28, v28, v19[0]     // persp normalize, used to improve precision
    or    t0, t0, t6
    vmadm v29, v29, v19[0]
    or    t0, t0, t5
    vmadn v28, v31, v31[0]
    sh    t0, 0x24(a3)
    jal   f3d_04001000         // compute 1/w
     lh    t5, -0x1a(s6)       // t5 unused?
    vge   v6, v27, v31[0]      // 1/w >= 0?
    sdv   v21[0], 0x00(a3)     // store xyzw int
    vmrg  v6, v27, v30[0]
    sdv   v20[0], 0x08(a3)     // store xyzw frac
    vmudl v5, v20, v26[3h]     // mul xyzw with 1/w
    vmadm v5, v21, v26[3h]
    vmadn v5, v20, v6[3h]
    vmadh v4, v21, v6[3h]
    addi  t1, t1, -1           // decrement vertex input count
    vmudl v5, v5, v19[0]       // take away persp normalize factor
    vmadm v4, v4, v19[0]
    vmadn v5, v31, v31[0]
    andi  t4, v1, G_FOG_H
    ldv   v2[0], 0x00(s6)      // pre-load next vertices from input
    vmudh v7, v1, v31[1]       // viewport translate * 0001
    ldv   v2[8], 0x10(s6)
    vmadn v7, v5, v0           // viewport scale
    ldv   v29[0], 0x28(zero)
    vmadh v6, v4, v0
    ldv   v29[8], 0x28(zero)
    vmadn v7, v31, v31[0]      // v6v7 contains vertex results after viewport
    vge   v6, v6, v29[1q]      // some saturating 0FFA-F006
    sw    t7, 0x10(a3)
    beq   t4, zero, @@f3d_040016e0 // skip fog?
     vlt   v6, v6, v29[0q]
    lqv   v3[0], 0x0330(zero)
    vmudn v5, v5, v3[0]        // mul fog factor (default 1)
    vmadh v4, v4, v3[0]
    vadd  v4, v4, v3[1]        // add parameter (default 0)
    vge   v4, v4, v31[0]
    vlt   v4, v4, v3[2]        // min parameter (default 0xff)
    sbv   v4[5], 0x13(a3)      // high z for 1st vertex, store in AA
    sw    s0, 0x18(a3)
    sbv   v4[13], 0x1b(a3)     // high z for 2nd vertex, store in AA
    lw    s0, 0x18(a3)
@@f3d_040016e0:
    slv   v18[0], 0x14(a3)     // texture coordinates, 1st vertex
    sdv   v6[0], 0x18(a3)      // xyz_int after viewport
    ssv   v7[4], 0x1e(a3)      // z_frac after viewport
    ssv   v27[6], 0x20(a3)     // 1/w
    ssv   v26[6], 0x22(a3)
    blez  t1, @@f3d_04001728
     addi  t1, t1, -1          // decrement vertex input counter again
    sdv   v21[8], 0x28(a3)
    sdv   v20[8], 0x30(a3)
    slv   v18[8], 0x3c(a3)     // texture coordinates, 2nd vertex
    sw    s0, 0x38(a3)
    sdv   v6[8], 0x40(a3)
    ssv   v7[12], 0x46(a3)
    ssv   v27[14], 0x48(a3)
    ssv   v26[14], 0x4a(a3)
    sw    t0, 0x4c(a3)         // puts high hword first
    addi  a3, a3, 0x50
    bgtz  t1, @f3d_040015a8
@@f3d_04001728:
     lh    t0, data0106
    jr    t0
     nop

dma_DL:
    bgtz  at, @@f3d_04001754   // 0=store ret addr, 1=end DL after branch
     lb    v0, (DL_STACK_SIZE_OFFSET)(sp)
    addi  a0, v0, -0x24        // DL stack full?
    bgtz  a0, SP_NOOP
     addi  v1, v0, displayListStack
    addi  v0, v0, 4
    sw    k0, 0x00(v1)         // store return address on DL stack
    sb    v0, (DL_STACK_SIZE_OFFSET)(sp)
@@f3d_04001754:
    jal   segmented_to_physical
     add   s3, t8, zero
    add   k0, s3, zero
    j     SP_NOOP
     addi  gp, zero, 0x00

// Overlays 2-4 will overwrite the following code
.org 0x04001768
f3d_04001768:
    ori   s8, zero, overlayInfo2
    b     load_overlay
     lh    s5, performClipEntry

load_lighting:
    ori   s8, zero, overlayInfo3
    b     load_overlay
     lh    s5, lightEntry

f3d_04001780:
    ori   v0, zero, 0x2800     // clear yielded, clear taskdone
    mtc0  v0, SP_STATUS
    lqv   v31[0], 0x30(zero)
    lqv   v30[0], 0x40(zero)
    lw    a0, OSTask_addr + OSTask_flags
    andi  a0, a0, 0x0001
    bne   a0, zero, @@f3d_04001870
     nop
    lw    s7, 0x28(at)         // task output buff
    lw    v1, 0x2c(at)         // task output buff size
    sw    s7, 0x40(sp)
    sw    v1, 0x44(sp)
    mfc0  a0, DPC_STATUS
    andi  a0, a0, DPC_STATUS_XBUS_DMA
    bne   a0, zero, @@f3d_040017e4
     mfc0  a0, DPC_END
    sub   s7, s7, a0
    bgtz  s7, @@f3d_040017e4
     mfc0  a1, DPC_CURRENT
    beq   a1, zero, @@f3d_040017e4
     nop
    beq   a1, a0, @@f3d_040017e4
     nop
    j     @@f3d_04001800
     ori   v1, a0, 0x0000
@@f3d_040017e4:
    mfc0  a0, DPC_STATUS
    andi  a0, a0, DPC_STATUS_START_VALID 
    bne   a0, zero, @@f3d_040017e4
     addi  a0, zero, DPC_STATUS_CLR_XBUS
    mtc0  a0, DPC_STATUS
    mtc0  v1, DPC_START
    mtc0  v1, DPC_END
@@f3d_04001800:
    sw    v1, 0x18(sp)
    addi  s7, zero, rdpOutput
    lw    a1, 0x10(at)         // TASK_UCODE (DRAM address)
    lw    v0, overlayInfo1
    lw    v1, overlayInfo2
    lw    a0, overlayInfo3
    lw    a2, overlayInfo4
    add   v0, v0, a1           // apply DRAM offset
    add   v1, v1, a1
    add   a0, a0, a1
    add   a2, a2, a1
    sw    v0, overlayInfo1     // store back with DRAM offsets
    sw    v1, overlayInfo2
    sw    a0, overlayInfo3
    sw    a2, overlayInfo4
    jal   load_overlay_fcn
     addi  s8, zero, overlayInfo1
    jal   load_display_list_dma
     lw    k0, 0x30(at)        // TASK_DATA_PTR
    lw    v0, 0x20(at)         // TASK_DRAM_STACK
    sw    v0, 0x20(sp)
    sw    v0, 0x24(sp)
    addi  v0, v0, 0x0280       // end of stack?
    sw    v0, 0x4c(sp)
    lw    v0, -0x08(zero)      // TASK_YIELD_DATA_PTR
    sw    v0, dramPtr
    j     dma_wait_dl
     nop
@@f3d_04001870:
    jal   load_overlay_fcn
     addi  s8, zero, overlayInfo1
    lw    s7, data08F0
    lw    gp, data08E4
    lw    k1, data08E8
    j     SP_NOOP
     lw    k0, data08EC

// 0x0400188c-0x04001987: bunch of nops
.fill 0xfc, 0
.ifdef F3D_OLD
  .fill 16, 0
.endif

// from G_TRI1
f3d_04001998:
    lh    t3, 0x24(v1)
    lh    t0, 0x24(v0)
    lh    t1, 0x24(at)
    and   t4, t3, t0
    or    t3, t3, t0
    and   t4, t4, t1
    andi  t4, t4, 0x7070
    bne   t4, zero, SP_NOOP    // all vertices outside screen, return
     or    t3, t3, t1
    andi  t3, t3, 0x4343
    bne   t3, zero, f3d_04001768 // halfway outside, so trigger clipping routine
f3d_040019c4:
     llv   v13[0], 0x18(at)    // xy_int after viewport
    llv   v14[0], 0x18(v0)
    llv   v15[0], 0x18(v1)
    lw    t5, 0x04(sp)         // geometrymode
    addi  t0, zero, setupTemp  // setup temp area
    lsv   v21[0], 0x02(sp)
    lsv   v5[0], 0x06(at)      // w_int p1
    vsub  v10, v14, v13        // p2-p1
    lsv   v6[0], 0x0e(at)      // w_frac p1
    vsub  v9, v15, v13         // p3-p1
    lsv   v5[2], 0x06(v0)
    vsub  v12, v13, v14        // p1-p2
    lsv   v6[2], 0x0e(v0)
    lsv   v5[4], 0x06(v1)
    lsv   v6[4], 0x0e(v1)
    vmudh v16, v9, v10[1]      // (p3-p1)*((p2-p1)_y)
    lh    t1, 0x1a(at)         // y_int after viewport
    vsar  v18, v18, v18[1]     // high into v18
    lh    t2, 0x1a(v0)
    vsar  v17, v17, v17[0]     // bits 47..31 of ACC
    lh    t3, 0x1a(v1)
    vmudh v16, v12, v9[1]      // (p1-p2)*((p3-p1)_y)
    andi  t6, t5, G_CULL_FRONT
    vsar  v20, v20, v20[1]
    andi  t7, t5, G_CULL_BACK
    vsar  v19, v19, v19[0]
    addi  t4, zero, 0          // now sort p1,p2,p3 by y
@@sort_points_loop:
    slt   a3, t2, t1
    blez  a3, @@f3d_04001a58
     add   a3, t2, zero        // y2_int < y1_int (after viewport)
    add   t2, t1, zero         // swap t1/t2 and swap v0/at
    add   t1, a3, zero
    addu  a3, v0, zero
    addu  v0, at, zero
    addu  at, a3, zero
    xori  t4, t4, 0x0001       // xor that we swapped p1 and p2
    nop                        // interesting place for NOP
@@f3d_04001a58:
    vaddc v28, v18, v20
    slt   a3, t3, t2
    vadd  v29, v17, v19
    blez  a3, @@f3d_04001a88
     add   a3, t3, zero        // y3_int < y2_int?
    add   t3, t2, zero         // swap p2, p3
    add   t2, a3, zero
    addu  a3, v1, zero
    addu  v1, v0, zero
    addu  v0, a3, zero
    j     @@sort_points_loop   // go back to test y1 and new y2
     xori  t4, t4, 0x0001      // xor that we swapped p2 and p3
@@f3d_04001a88:
    vlt   v27, v29, v31[0]
    llv   v15[0], 0x18(v1)     // xy_int after viewport for new p3
    vor   v26, v29, v28
    llv   v14[0], 0x18(v0)
    llv   v13[0], 0x18(at)
    blez  t4, @@f3d_04001ab0   // skip if even number of swaps
     vsub  v4, v15, v14        // p3-p2
    vmudn v28, v28, v31[3]
    vmadh v29, v29, v31[3]
    vmadn v28, v31, v31[0]
@@f3d_04001ab0:
    vsub  v10, v14, v13        // p2-p1
    mfc2  s1, v27[0]
    vsub  v9, v15, v13         // p3-p1
    mfc2  s0, v26[0]
    sra   s1, s1, 31
    vmov  v29[3], v29[0]
    and   t7, t7, s1
    vmov  v28[3], v28[0]
    vmov  v4[2], v10[0]
    beq   s0, zero, @@f3d_04001fd0 // skip this triangle?
     xori  s1, s1, 0xffff
    vlt   v27, v29, v31[0]
    and   t6, t6, s1
    vmov  v4[3], v10[1]
    or    s0, t7, t6
    vmov  v4[4], v9[0]
    bgtz  s0, @@f3d_04001fd0
     vmov  v4[5], v9[1]
    mfc2  a3, v27[0]
    jal   f3d_04001000
     addi  a2, zero, 0x80      // left major flag
    bltz  a3, @@f3d_04001b10
     lb    a1, 0x07(sp)        // low byte for geometrymode
    addi  a2, zero, 0
@@f3d_04001b10:
    vmudm v9, v4, v31[4]
    vmadn v10, v31, v31[0]
    vrcp  v8[1], v4[1]
    vrcph v7[1], v31[0]
    ori   a1, a1, 0x00c8       // OR with RDP command code
    lb    a3, 0x12(sp)         // mpmap level and tile ID
    vrcp  v8[3], v4[3]
    vrcph v7[3], v31[0]
    vrcp  v8[5], v4[5]
    vrcph v7[5], v31[0]
    or    a2, a2, a3
    vmudl v8, v8, v30[4]
    sb    a1, 0x00(s7)
    vmadm v7, v7, v30[4]
    sb    a2, 0x01(s7)
    vmadn v8, v31, v31[0]
    vmudh v4, v4, v31[5]
    lsv   v12[0], 0x18(v0)
    vmudl v6, v6, v21[0]
    lsv   v12[4], 0x18(at)
    vmadm v5, v5, v21[0]
    lsv   v12[8], 0x18(at)
    vmadn v6, v31, v31[0]
    sll   a3, t1, 14
    vmudl v1, v8, v10[0q]
    vmadm v1, v7, v10[0q]
    vmadn v1, v8, v9[0q]
    vmadh v0, v7, v9[0q]
    mtc2  a3, v2[0]
    vmadn v1, v31, v31[0]
    sw    v1, 0x00(t0)
    vmudl v8, v8, v31[4]
    vmadm v7, v7, v31[4]
    vmadn v8, v31, v31[0]
    vmudl v1, v1, v31[4]
    vmadm v0, v0, v31[4]
    vmadn v1, v31, v31[0]
    sh    t3, 0x02(s7)         // YL
    vand  v16, v1, v30[1]
    sh    t1, 0x06(s7)         // YH
    vmudm v12, v12, v31[4]
    sw    v0, 0x04(t0)
    vmadn v13, v31, v31[0]
    sw    at, 0x08(t0)
    sh    t2, 0x04(s7)         // YM
    vcr   v0, v0, v30[6]
    ssv   v12[0], 0x08(s7)     // XL
    vmudl v11, v16, v2[0]
    ssv   v13[0], 0x0a(s7)     // XL, frac
    vmadm v10, v0, v2[0]
    ssv   v0[2], 0x0c(s7)      // DxLDy
    vmadn v11, v31, v31[0]
    ssv   v1[2], 0x0e(s7)      // DxLDy, frac
    andi  a3, a1, G_TEXTURE_ENABLE
    addi  t7, t0, 8
    addi  s0, t0, 0x10
    vsubc v3, v13, v11[1q]
    ssv   v0[10], 0x14(s7)     // DxHDy
    vsub  v9, v12, v10[1q]
    ssv   v1[10], 0x16(s7)     // DxHDy, frac
    vsubc v21, v6, v6[1]
    ssv   v0[6], 0x1c(s7)      // DxMDy
    vlt   v19, v5, v5[1]
    ssv   v1[6], 0x1e(s7)      // DxMDy, frac
    vmrg  v20, v6, v6[1]
    ssv   v9[8], 0x10(s7)      // XH
    vsubc v21, v20, v6[2]
    ssv   v3[8], 0x12(s7)      // XH, frac
    vlt   v19, v19, v5[2]
    ssv   v9[4], 0x18(s7)      // XM
    vmrg  v20, v20, v6[2]
    ssv   v3[4], 0x1a(s7)      // XM, frac
    addi  s7, s7, 0x20
    blez  a3, @@f3d_04001cfc   // no texture?
     vmudl v20, v20, v30[5]
    lw    t6, 0x00(t7)
    vmadm v19, v19, v30[5]
    lw    s1, -0x04(t7)
    vmadn v20, v31, v31[0]
    lw    s2, -0x08(t7)
    llv   v9[0], 0x14(t6)
    llv   v9[8], 0x14(s1)
    llv   v22[0], 0x14(s2)
    lsv   v11[0], 0x22(t6)
    lsv   v12[0], 0x20(t6)
    lsv   v11[8], 0x22(s1)
    vmov  v9[2], v30[0]
    lsv   v12[8], 0x20(s1)
    vmov  v9[6], v30[0]
    lsv   v24[0], 0x22(s2)
    vmov  v22[2], v30[0]
    lsv   v25[0], 0x20(s2)
    vmudl v6, v11, v20[0]
    vmadm v6, v12, v20[0]
    ssv   v19[0], 0x44(t0)
    vmadn v6, v11, v19[0]
    ssv   v20[0], 0x4c(t0)
    vmadh v5, v12, v19[0]
    vmudl v16, v24, v20[0]
    vmadm v16, v25, v20[0]
    vmadn v20, v24, v19[0]
    vmadh v19, v25, v19[0]
    vmudm v16, v9, v6[0h]
    vmadh v9, v9, v5[0h]
    vmadn v10, v31, v31[0]
    vmudm v16, v22, v20[0]
    vmadh v22, v22, v19[0]
    vmadn v23, v31, v31[0]
    sdv   v9[8], 0x10(s0)
    sdv   v10[8], 0x18(s0)
    sdv   v9[0], 0x00(s0)
    sdv   v10[0], 0x08(s0)
    sdv   v22[0], 0x20(s0)
    sdv   v23[0], 0x28(s0)
    vabs  v9, v9, v9
    llv   v19[0], 0x10(s0)
    vabs  v22, v22, v22
    llv   v20[0], 0x18(s0)
    vabs  v19, v19, v19
    vge   v17, v9, v22
    vmrg  v18, v10, v23
    vge   v17, v17, v19
    vmrg  v18, v18, v20
@@f3d_04001cfc:
    slv   v17[0], 0x40(t0)
    slv   v18[0], 0x48(t0)
    andi  a3, a1, (G_SHADE | G_TEXTURE_ENABLE | G_ZBUFFER)
    blez  a3, @@f3d_04001fcc   // skip code below if no bits set
     vxor  v18, v31, v31
    luv   v25[0], 0x10(v1)
    vadd  v16, v18, v30[5]
    luv   v15[0], 0x10(at)
    vadd  v24, v18, v30[5]
    andi  a3, t5, 0x0200
    vadd  v5, v18, v30[5]
    bgtz  a3, @@f3d_04001d3c
     luv   v23[0], 0x10(v0)
    luv   v25[0], 0x10(a0)
    luv   v15[0], 0x10(a0)
    luv   v23[0], 0x10(a0)
@@f3d_04001d3c:
    vmudm v25, v25, v31[7]
    vmudm v15, v15, v31[7]
    vmudm v23, v23, v31[7]
    ldv   v16[8], 0x18(t0)
    ldv   v15[8], 0x10(t0)
    ldv   v24[8], 0x28(t0)
    ldv   v23[8], 0x20(t0)
    ldv   v5[8], 0x38(t0)
    ldv   v25[8], 0x30(t0)
    lsv   v16[14], 0x1e(at)
    lsv   v15[14], 0x1c(at)
    lsv   v24[14], 0x1e(v0)
    lsv   v23[14], 0x1c(v0)
    lsv   v5[14], 0x1e(v1)
    lsv   v25[14], 0x1c(v1)
    vsubc v12, v24, v16
    vsub  v11, v23, v15
    vsubc v20, v16, v5
    vsub  v19, v15, v25
    vsubc v10, v5, v16
    vsub  v9, v25, v15
    vsubc v22, v16, v24
    vsub  v21, v15, v23
    vmudn v6, v10, v4[3]
    vmadh v6, v9, v4[3]
    vmadn v6, v22, v4[5]
    vmadh v6, v21, v4[5]
    vsar  v9, v9, v9[0]
    vsar  v10, v10, v10[1]
    vmudn v6, v12, v4[4]
    vmadh v6, v11, v4[4]
    vmadn v6, v20, v4[2]
    vmadh v6, v19, v4[2]
    vsar  v11, v11, v11[0]
    vsar  v12, v12, v12[1]
    vmudl v6, v10, v26[3]
    vmadm v6, v9, v26[3]
    vmadn v10, v10, v27[3]
    vmadh v9, v9, v27[3]
    vmudl v6, v12, v26[3]
    vmadm v6, v11, v26[3]
    vmadn v12, v12, v27[3]
    sdv   v9[0], 0x08(s7)
    vmadh v11, v11, v27[3]
    sdv   v10[0], 0x18(s7)
    vmudn v6, v12, v31[1]
    vmadh v6, v11, v31[1]
    vmadl v6, v10, v1[5]
    vmadm v6, v9, v1[5]
    vmadn v14, v10, v0[5]
    sdv   v11[0], 0x28(s7)
    vmadh v13, v9, v0[5]
    sdv   v12[0], 0x38(s7)
    vmudl v28, v14, v2[0]
    sdv   v13[0], 0x20(s7)
    vmadm v6, v13, v2[0]
    sdv   v14[0], 0x30(s7)
    vmadn v28, v31, v31[0]
    vsubc v18, v16, v28
    vsub  v17, v15, v6
    andi  a3, a1, G_SHADE
    blez  a3, @@f3d_04001e44
     andi  a3, a1, G_TEXTURE_ENABLE
    addi  s7, s7, 0x40
    sdv   v17[0], -0x40(s7)
    sdv   v18[0], -0x30(s7)
@@f3d_04001e44:
    blez  a3, @@f3d_04001f48
     andi  a3, a1, G_ZBUFFER
    addi  s0, zero, 0x0800
    mtc2  s0, v19[0]
    vabs  v24, v9, v9
    ldv   v20[8], 0x40(t0)
    vabs  v25, v11, v11
    ldv   v21[8], 0x48(t0)
    vmudm v24, v24, v19[0]
    vmadn v26, v31, v31[0]
    vmudm v25, v25, v19[0]
    vmadn v27, v31, v31[0]
    vmudl v21, v21, v19[0]
    vmadm v20, v20, v19[0]
    vmadn v21, v31, v31[0]
    vmudn v26, v26, v31[2]
    vmadh v24, v24, v31[2]
    vmadn v26, v31, v31[0]
    vmadn v23, v27, v31[1]
    vmadh v22, v25, v31[1]
    addi  s0, zero, 0x40
    vmadn v6, v21, v31[1]
    mtc2  s0, v19[0]
    vmadh v5, v20, v31[1]
    vsubc v23, v6, v6[5]
    vge   v5, v5, v5[5]
    vmrg  v6, v6, v6[5]
    vsubc v23, v6, v6[6]
    vge   v5, v5, v5[6]
    vmrg  v6, v6, v6[6]
    vmudl v6, v6, v19[0]
    vmadm v5, v5, v19[0]
    vmadn v6, v31, v31[0]
    vrcph v23[0], v5[4]
    vrcpl v6[0], v6[4]
    vrcph v5[0], v31[0]
    vmudn v6, v6, v31[2]
    vmadh v5, v5, v31[2]
    vlt   v5, v5, v31[1]
    vmrg  v6, v6, v31[0]
    vmudl v20, v18, v6[0]
    vmadm v20, v17, v6[0]
    vmadn v20, v18, v5[0]
    vmadh v19, v17, v5[0]
    vmudl v22, v10, v6[0]
    vmadm v22, v9, v6[0]
    vmadn v22, v10, v5[0]
    sdv   v19[8], 0x00(s7)
    vmadh v21, v9, v5[0]
    sdv   v20[8], 0x10(s7)
    vmudl v24, v12, v6[0]
    vmadm v24, v11, v6[0]
    vmadn v24, v12, v5[0]
    sdv   v21[8], 0x08(s7)
    vmadh v23, v11, v5[0]
    sdv   v22[8], 0x18(s7)
    vmudl v26, v14, v6[0]
    vmadm v26, v13, v6[0]
    vmadn v26, v14, v5[0]
    sdv   v23[8], 0x28(s7)
    vmadh v25, v13, v5[0]
    sdv   v24[8], 0x38(s7)
    addi  s7, s7, 0x40
    sdv   v25[8], -0x20(s7)
    sdv   v26[8], -0x10(s7)
@@f3d_04001f48:
    blez  a3, @@f3d_04001fcc
     vmudn v14, v14, v30[4]
    vmadh v13, v13, v30[4]
    vmadn v14, v31, v31[0]
    vmudn v16, v16, v30[4]
    vmadh v15, v15, v30[4]
    vmadn v16, v31, v31[0]
    ssv   v13[14], 0x08(s7)
    vmudn v10, v10, v30[4]
    ssv   v14[14], 0x0a(s7)
    vmadh v9, v9, v30[4]
    vmadn v10, v31, v31[0]
    vmudn v12, v12, v30[4]
    vmadh v11, v11, v30[4]
    vmadn v12, v31, v31[0]
    lbu   a3, 0x11(sp)
    sub   a3, zero, a3
    beq   a3, zero, @@f3d_04001f9c
     mtc2  a3, v6[0]
    vch   v11, v11, v6[0]
    vcl   v12, v12, v31[0]
@@f3d_04001f9c:
    ssv   v9[14], 0x04(s7)
    vmudl v28, v14, v2[0]
    ssv   v10[14], 0x06(s7)
    vmadm v6, v13, v2[0]
    ssv   v11[14], 0x0c(s7)
    vmadn v28, v31, v31[0]
    ssv   v12[14], 0x0e(s7)
    vsubc v18, v16, v28
    vsub  v17, v15, v6
    addi  s7, s7, 0x10
    ssv   v17[14], -0x10(s7)
    ssv   v18[14], -0x0e(s7)
@@f3d_04001fcc:
    jal   f3d_04001178
@@f3d_04001fd0:
     nop
    jr    s8
     nop
    nop
Overlay0End:

// Overlay 1
.headersize 0x04001000 - orga()
.definelabel Overlay1LoadStart, orga()
// reciprocal method, see RSP Programmers Guide page 79
// v29[3]=s_int, v28[3]=s_frac, v29[7]=t_int, v28[7]=t_frac
// out: v27[3,7]=s,t int, v26[3,7]=s,t frac
Overlay1Address:
f3d_04001000:
    vrcph v27[3], v29[3]
    vrcpl v26[3], v28[3]
    vrcph v27[3], v29[7]
    vrcpl v26[7], v28[7]
    vrcph v27[7], v31[0]
    vmudn v26, v26, v31[2] // 0002, << 1 since input is S15.16
    vmadh v27, v27, v31[2]
    vmadn v26, v31, v31[0]
    // v27[3]=sres_int, v26[3]=sres_frac, v27[7]=tres_int, v26[7]=tres_frac
    lqv   v23[0], 0x60(zero)
    vxor  v22, v31, v31    // (1/w)*w
    vmudl v24, v26, v28
    vmadm v24, v27, v28
    vmadn v24, v26, v29
    vmadh v25, v27, v29
    // v24=frac, v25=int, should be very close to 1.0
    vsubc v24, v22, v24    // take 2.0-result (better rounding?)
    vsub  v25, v23, v25
    vmudl v22, v26, v24    // (2.0-(1/w)*w)*(1/w)
    vmadm v23, v27, v24
    vmadn v26, v26, v25
    vmadh v27, v27, v25
    jr    ra
     nop

dma_wait_dl:
    jal   wait_while_dma_busy
     addi  k1, zero, inputDisplayList

read_next_task_entry:
    lw    t9, 0x00(k1)     // first command word
    lw    t8, 0x04(k1)     // second command word
    srl   at, t9, 29
    andi  at, at, 0x0006   // at = (two MSbits) << 1
    addi  k0, k0, 8        // increase next task in DRAM ptr
    addi  k1, k1, 8        // increase next task in DMEM ptr
    addi  gp, gp, -8       // decrease task count left in DMEM
    bgtz  at, dispatch_task
     andi  s2, t9, 0x01ff
    addi  s6, zero, inputData // command that loads data input
Overlay1End:


// Overlay 2
.headersize 0x04001768 - orga()
Overlay2Address:
    b     perform_clip
     sh    ra, data0158
    nop
    nop
    ori   s8, zero, overlayInfo3
    b     load_overlay
     lh    s5, lightEntry

perform_clip:
    sh    v1, clipTemp
    sh    v0, data0942
    sh    at, data0944
    sh    zero, data0946
    ori   a3, zero, 0x0db8
    ori   s8, zero, clipTemp
    ori   a2, zero, 0x000c
next_clip:
    or    a1, s8, s8
    xori  s8, s8, 0x0014
f3d_040017a8:
    beq   a2, zero, @f3d_04001954
     lh    t3, 0xa6(a2)
    addi  a2, a2, -2
    ori   s1, zero, 0x0000
    or    s2, zero, zero

found_in:
    ori   v0, a1, 0x0000

found_out:
    j     f3d_040017d4
     addi  t6, s8, 2
f3d_040017c8:
    and   t0, t0, t3
    beq   t0, s2, f3d_o2_04001804
     addi  v0, v0, 2
f3d_040017d4:
    or    s4, t2, zero
    sh    t2, 0x00(t6)
    addi  t6, t6, 2
f3d_040017e0:
    lh    t2, 0x00(v0)
    bne   t2, zero, f3d_040017c8
     lh    t0, 0x24(t2)
    addi  t0, s1, -2
    bgtz  t0, f3d_040017e0
     ori   v0, a1, 0x0000
    beq   t0, zero, f3d_040017a8
     nop
    j     f3d_04001980
f3d_o2_04001804:
     xor   s2, s2, t3
    lh    t0, lo(labelLUT)(s1)
    addi  s1, s1, 2
    jr    t0
     lh    t0, nextClipEntry

found_first_in:
    mtc2  t2, v13[0]
    or    t2, s4, zero
    mfc2  s4, v13[0]
    ori   t6, s8, 0x0000
    lh    t0, foundOutEntry

found_first_out:
    sh    t0, data0106
    addi  a3, a3, 0x28
    sh    a3, 0x00(t6)
    sh    zero, 0x02(t6)
    ldv   v9[0], 0x00(t2)
    ldv   v10[0], 0x08(t2)
    ldv   v4[0], 0x00(s4)
    ldv   v5[0], 0x08(s4)
    sll   t0, a2, 2
    ldv   v1[0], 0x70(t0)
    vmudh v0, v1, v31[3]
    vmudn v12, v5, v1
    vmadh v11, v4, v1
    vmadn v12, v31, v31[0]
    vmadn v28, v10, v0
    vmadh v29, v9, v0
    vmadn v28, v31, v31[0]
    vaddc v26, v28, v28[0q]
    vadd  v27, v29, v29[0q]
    vaddc v28, v26, v26[1h]
    vadd  v29, v27, v27[1h]
    mfc2  t0, v29[6]
    vrcph v7[3], v29[3]
    vrcpl v3[3], v28[3]
    vrcph v7[3], v31[0]
    vmudn v3, v3, v31[2]
    bgez  t0, f3d_040018a4
     vmadh v7, v7, v31[2]
    vmudn v3, v3, v31[3]
    vmadh v7, v7, v31[3]
f3d_040018a4:
    veq   v7, v7, v31[0]
    vmrg  v3, v3, v31[3]
    vmudl v28, v28, v3[3]
    vmadm v29, v29, v3[3]
    jal   f3d_04001000
     vmadn v28, v31, v31[0]
    vaddc v28, v12, v12[0q]
    vadd  v29, v11, v11[0q]
    vaddc v12, v28, v28[1h]
    vadd  v11, v29, v29[1h]
    vmudl v15, v12, v26
    vmadm v15, v11, v26
    vmadn v15, v12, v27
    vmadh v8, v11, v27
    vmudl v28, v31, v31[5]
    vmadl v15, v15, v3[3]
    vmadm v8, v8, v3[3]
    vmadn v15, v31, v31[0]
    veq   v8, v8, v31[0]
    vmrg  v15, v15, v31[3]
    vne   v15, v15, v31[0]
    vmrg  v15, v15, v31[1]
    vnxor v8, v15, v31[0]
    vaddc v8, v8, v31[1]
    vadd  v29, v29, v29
    vmudl v28, v5, v8[3h]
    vmadm v29, v4, v8[3h]
    vmadl v28, v10, v15[3h]
    vmadm v29, v9, v15[3h]
    vmadn v28, v31, v31[0]
    luv   v12[0], 0x10(t2)
    luv   v11[0], 0x10(s4)
    llv   v12[8], 0x14(t2)
    llv   v11[8], 0x14(s4)
    vmudm v18, v12, v15[3]
    vmadm v18, v11, v8[3]
    suv   v18[0], 0x00(a3)
    sdv   v18[8], 0x08(a3)
    ldv   v18[0], 0x08(a3)
    jal   f3d_040014e8
     lw    t7, 0x00(a3)
    mfc2  t2, v13[0]
    j     @f3d_040015e8
     ori   t1, zero, 0x0001
@f3d_04001954:
    lh    t0, 0x00(a1)
    sh    t0, 0xb4(zero)
    sh    a1, data0106
    lh    s8, clipDrawEntry

clip_draw_loop:
    lh    t0, data0106
    lh    v1, 0xb4(zero)
    lh    v0, 0x02(t0)
    lh    at, 0x04(t0)
    addi  t0, t0, 2
    bne   at, zero, f3d_040019c4
     sh    t0, data0106
f3d_04001980:
    j     SP_NOOP
     nop
Overlay2End:

// Overlay 3
.headersize 0x04001768 - orga()
Overlay3Address:
    ori   s8, zero, overlayInfo2
    b     load_overlay
     lh    s5, performClipEntry
    lw    at, numLights
    sw    t7, 0x00(a3)       // normal vector 1st vertex
    sw    s0, 0x04(a3)       // normal vector 2nd vertex
    bltz  at, @init_lights
     lpv   v4[0], 0x00(a3)
    luv   v7[0], 0x01d0(at)  // ambient RGB
    vxor  v27, v27, v27
@@f3d_04001790:
    vge   v7, v7, v31[0]     // max(0, v7)
    lpv   v5[0], 0x01c0(at)  // calculated light
    vadd  v27, v27, v7
    luv   v7[0], 0x01b0(at)  // light's RGB
    vor   v20, v6, v31[0]
    vmulf v6, v4, v5         // mul normal vector
    vadd  v3, v6, v6[1q]
    vadd  v6, v3, v6[2h]
    vmulf v7, v7, v6[0h]     // v6[0] and v6[4] contain dot product
    bgtz  at, @@f3d_04001790
     addi  at, at, -0x20
    suv   v27[0], 0x00(a3)
    andi  t0, v1, G_TEXTURE_GEN_H
    sb    t7, 0x03(a3)
    sb    s0, 0x07(a3)
    lw    t7, 0x00(a3)
    beq   t0, zero, @f3d_040015e4
     lw    s0, 0x04(a3)
    andi  t0, v1, G_TEXTURE_GEN_LINEAR_H // not used in SM64
    lpv   v7[0], 0x90(sp)
    ldv   v6[0], 0xa0(zero)
    vmadn v20, v7, v20[0h]
    beq   t0, zero, @@f3d_o3_04001804
     vmadm v18, v31, v31[0]
    vmulf v7, v18, v18
    vmulf v7, v7, v18
    vmulf v20, v7, v6[1]
    vmacf v20, v7, v6[3]
    vmacf v18, v18, v6[2]
@@f3d_o3_04001804:
    j     @f3d_040015e4
     vadd  v18, v18, v31[4]

@init_lights:
    andi  at, at, 0x0fff
    sw    at, numLights
    jal   f3d_04001524
     addi  t0, zero, modelViewMatrixStack
    ori   t0, zero, scratchSpace
    stv   v8[2], 0x10(t0)    // transpose
    stv   v8[4], 0x20(t0)
    stv   v8[12], 0x30(t0)
    stv   v8[14], 0x40(t0)
    ltv   v8[14], 0x10(t0)
    ltv   v8[12], 0x20(t0)
    ltv   v8[4], 0x30(t0)
    ltv   v8[2], 0x40(t0)
    sdv   v12[8], 0x10(t0)
    sdv   v13[8], 0x20(t0)
    sdv   v14[8], 0x30(t0)
    ldv   v12[0], 0x10(t0)
    ldv   v13[0], 0x20(t0)
    ldv   v14[0], 0x30(t0)
f3d_04001858:
    lpv   v5[0], 0x01b8(at)  // this light's dir vector
    vmulf v5, v5, v31[4]
    vmudn v6, v12, v5[0h]
    vmadn v6, v13, v5[1h]
    vmadn v6, v14, v5[2h]
    vmadm v3, v31, v31[0]
    vmudm v6, v3, v31[2]
    vmacf v3, v8, v5[0h]
    vmacf v3, v9, v5[1h]
    vmacf v3, v10, v5[2h]
    vmadn v6, v31, v31[0]
    vmudl v5, v6, v6
    vmadm v5, v3, v6
    vmadn v5, v6, v3
    vmadh v26, v3, v3
    vaddc v7, v5, v5[1q]
    vadd  v4, v26, v26[1q]
    vaddc v7, v5, v7[0h]
    vadd  v4, v26, v4[0h]
    vrsqh v11[0], v4[2]      // normalize vector
    vrsql v15[0], v7[2]
    vrsqh v11[0], v31[0]
    vmudl v15, v15, v30[3]
    vmadm v11, v11, v30[3]
    vmadn v15, v31, v31[0]
    vmudl v7, v6, v15[0]
    vmadm v7, v3, v15[0]
    vmadn v7, v6, v11[0]
    vmadh v4, v3, v11[0]
    vmadn v7, v31, v31[0]
    ldv   v2[0], 0xf8(sp)
    vge   v7, v7, v2[0]
    vlt   v7, v7, v2[1]
    vmudn v7, v7, v2[2]
    spv   v7[0], 0x01c0(at)
    lw    t0, 0x01c0(at)
    sw    t0, 0x01c4(at)
    bgtz  at, f3d_04001858
     addi  at, at, -0x20
    j     load_mp_matrix
     lh    ra, lightEntry
    nop
Overlay3End:

// Overlay 4
.headersize 0x04001768 - orga()
Overlay4Address:
    j     f3d_04001788
     nop
overlay_4_entry:
    nop
    jal   wait_while_dma_busy
     ori   v0, zero, 0x4000
    mtc0  v0, SP_STATUS
    break
    nop
f3d_04001788:
    ori   v0, zero, 0x1000
    sw    gp, data08E4
    sw    k1, data08E8
    sw    k0, data08EC
    sw    s7, data08F0
    lw    s3, dramPtr
    ori   s4, zero, 0x0000
    ori   s2, zero, 0x08ff
    jal   dma_read_write
     ori   s1, zero, 0x0001
    jal   wait_while_dma_busy
     nop
    j     f3d_040010c8
     mtc0  v0, SP_STATUS
    nop
    nop
    addiu zero, zero, 0xbeef
    nop
Overlay4End:

.close // CODE_FILE
