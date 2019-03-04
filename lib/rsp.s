.include "macros.inc"
.set UCODE_SIZE, 0x800

.section .text

.balign 16
glabel rspF3DBootStart
    .incbin "lib/ucode/boot/F3D_boot.bin"
glabel rspF3DBootEnd

# Both of these ucode bins are 0x1000/0x800 respectively as defined in their
# ucode initializations, but there's extra data afterwards. However, it's not the
# RSP data as that is pointed to below in the rodata section. TODO: What are these
# extra bins?

.ifndef F3DEX_GBI
.balign 16
glabel rspF3DStart /* Use regular Fast3D bins (default) */
    .incbin "lib/ucode/f3d/F3D.bin"
    .incbin "lib/ucode/f3d/F3D_unk.bin"
glabel rspF3DEnd
.else /* Default to Fast3DEX bin when F3DEX_GBI is defined */
.balign 16
glabel rspF3DStart
    .incbin "lib/ucode/f3dex/F3DEX.bin"
glabel rspF3DEnd
.endif

/* Audio Bins */

.balign 16
glabel rspF3DAudioStart
    .incbin "lib/ucode/audio/F3D_audio.bin"
    .incbin "lib/ucode/audio/F3D_audio_unk.bin"
glabel rspF3DAudioEnd

/*
 * LESS COMMON MICROCODES
 * These are setup to be loaded by G_LOAD_UCODE
 */

/* Fast3DEX NoN Text */

.ifdef F3DEX_NON_GBI
glabel rspF3DEXNoNStart
    .incbin "lib/ucode/f3dex/F3DEX_NoN.bin"
glabel rspF3DEXNoNEnd
.endif

/* Fast3DLX Text */

.ifdef F3DLX_GBI
glabel rspF3DLXStart
    .incbin "lib/ucode/f3dex/F3DLX.bin"
glabel rspF3DLXEnd
.endif

/* Fast3DLX NoN Text */

.ifdef F3DLX_NON_GBI
glabel rspF3DLXNoNStart
    .incbin "lib/ucode/f3dex/F3DLX_NoN.bin"
glabel rspF3DLXNoNEnd
.endif

/* Fast3DLX Rej Text */

.ifdef F3DLX_REJ_GBI
glabel rspF3DLXRejStart
    .incbin "lib/ucode/f3dex/F3DLX_Rej.bin"
glabel rspF3DLXRejEnd
.endif

/* Line3DEX Text */

.ifdef L3DEX_GBI
glabel rspL3DEXStart
    .incbin "lib/ucode/f3dex/L3DEX.bin"
glabel rspL3DEXEnd
.endif

.section .rodata

.ifndef F3DEX_GBI /* Use regular Fast3D data (default) */
.balign 16
glabel rspF3DDataStart
    .incbin "lib/ucode/f3d/F3D_data.bin"
glabel rspF3DDataEnd
.else /* Default to Fast3DEX data when F3DEX_GBI (or any other F3DEX GBI) is defined */
glabel rspF3DDataStart
    .incbin "lib/ucode/f3dex/F3DEX_data.bin"
glabel rspF3DDataEnd
.endif

/* Audio Data */

.balign 16
glabel rspF3DAudioDataStart
    .incbin "lib/ucode/audio/F3D_audio_data.bin"
glabel rspF3DAudioDataEnd

/*
 * LESS COMMON MICROCODES
 */

/* Fast3DEX NoN Data */

.ifdef F3DEX_NON_GBI
glabel rspF3DEXNoNDataStart
    .incbin "lib/ucode/f3dex/F3DEX_NoN_data.bin"
glabel rspF3DEXNoNDataEnd
.endif

/* Fast3DLX Data */

.ifdef F3DLX_GBI
glabel rspF3DLXDataStart
    .incbin "lib/ucode/f3dex/F3DLX_data.bin"
glabel rspF3DLXDataEnd
.endif

/* Fast3DLX NoN Data */

.ifdef F3DLX_NON_GBI
glabel rspF3DLXNoNDataStart
    .incbin "lib/ucode/f3dex/F3DLX_NoN_data.bin"
glabel rspF3DLXNoNDataEnd
.endif

/* Fast3DLX Rej Data */

.ifdef F3DLX_REJ_GBI
glabel rspF3DLXRejDataStart
    .incbin "lib/ucode/f3dex/F3DLX_Rej_data.bin"
glabel rspF3DLXRejDataEnd
.endif

/* Line3DEX Data */

.ifdef L3DEX_GBI
glabel rspL3DEXDataStart
    .incbin "lib/ucode/f3dex/L3DEX_data.bin"
glabel rspL3DEXDataEnd
.endif
