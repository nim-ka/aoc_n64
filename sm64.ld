OUTPUT_ARCH (mips)

/* include/segments.h defines SEG_POOL_START, SEG_POOL_END, SEG_BUFFERS,
 * SEG_GODDARD, SEG_MAIN, SEG_ENGINE, SEG_FRAMEBUFFERS */
#include "segments.h"

#define BEGIN_SEG(name, addr) \
    _##name##SegmentStart = ADDR(.name); \
    _##name##SegmentRomStart = __romPos; \
    .name addr : AT(__romPos)

#define END_SEG(name) \
    _##name##SegmentEnd = ADDR(.name) + SIZEOF(.name); \
    _##name##SegmentRomEnd = __romPos + SIZEOF(.name); \
    __romPos += SIZEOF(.name);

#define BEGIN_NOLOAD(name) \
    _##name##SegmentNoloadStart = ADDR(.name.noload); \
    .name.noload (NOLOAD) :

#define END_NOLOAD(name) \
    _##name##SegmentNoloadEnd = ADDR(.name.noload) + SIZEOF(.name.noload);

#define MIO0_SEG(name, segAddr) \
   BEGIN_SEG(name##_mio0, segAddr) \
   { \
      BUILD_DIR/bin/name.mio0.o(.data); \
      . = ALIGN(0x10); \
   } \
   END_SEG(name##_mio0)

#define MIO0_EU_SEG(name, segAddr) \
   BEGIN_SEG(name##_mio0, segAddr) \
   { \
      BUILD_DIR/bin/eu/name.mio0.o(.data); \
      . = ALIGN(0x10); \
   } \
   END_SEG(name##_mio0)

#define STANDARD_LEVEL(name) \
   BEGIN_SEG(name##_segment_7, 0x07000000) \
   { \
      BUILD_DIR/levels/name/leveldata.mio0.o(.data); \
      . = ALIGN(0x10); \
   } \
   END_SEG(name##_segment_7) \
   BEGIN_SEG(name, 0x0E000000) \
   { \
      BUILD_DIR/levels/name/script.o(.data); \
      BUILD_DIR/levels/name/geo.o(.data); \
   } \
   END_SEG(name)

#define STANDARD_OBJECTS(name, segAddr, geoAddr) \
   BEGIN_SEG(name##_mio0, segAddr) \
   { \
      BUILD_DIR/actors/name.mio0.o(.data); \
      . = ALIGN(0x10); \
   } \
   END_SEG(name##_mio0) \
   BEGIN_SEG(name##_geo, geoAddr) \
   { \
      BUILD_DIR/actors/name##_geo.o(.data); \
   } \
   END_SEG(name##_geo)

SECTIONS
{
   __romPos = 0;

   BEGIN_SEG(boot, 0x04000000)
   {
      BUILD_DIR/asm/rom_header.o(.text);
      BUILD_DIR/asm/boot.o(.text);
   }
   END_SEG(boot)

   . = 0x80000400;
   BEGIN_NOLOAD(zbuffer) {
      BUILD_DIR/src/buffers/zbuffer.o(.bss*);
   }

   . = ALIGN(0x10);

   BEGIN_NOLOAD(buffers)
   {
      BUILD_DIR/src/buffers/buffers.o(.bss*);

      . = ALIGN(0x100000);
      BUILD_DIR/src/buffers/gfx_output_buffer.o(.bss*);
   }
   END_NOLOAD(buffers)

   . = ALIGN(0x10);

   BEGIN_NOLOAD(framebuffers)
   {
      BUILD_DIR/src/buffers/framebuffers.o(.bss*);
   }
   END_NOLOAD(framebuffers)

   . = ALIGN(0x10);

   /* lib/src/__osDevMgrMain.c and lib/src/osCreateViManager.c contain infinite
    * loops compiled without -g, which cause the return statements and the .o
    * files themselves to be aligned to 32-byte boundaries. But the linker
    * Nintendo used did not respect .o file alignment, and aligned the files
    * only to 16 bytes, in some cases misaligning them. We force the same to
    * happen using the SUBALIGN directive. This is harmless; the alignment is
    * just an optimization. */
   BEGIN_SEG(main, ) SUBALIGN(16)
   {
      BUILD_DIR/asm/entry.o(.text);

      BUILD_DIR/src/game*.o(.text);

      BUILD_DIR/libultra.a:parameters.o(.text);
      BUILD_DIR/libultra.a:osSetTime.o(.text);
      BUILD_DIR/libultra.a:osMapTLB.o(.text);
      BUILD_DIR/libultra.a:osUnmapTLBAll.o(.text);
      BUILD_DIR/libultra.a:sprintf.o(.text);
      BUILD_DIR/libultra.a:osCreateMesgQueue.o(.text);
      BUILD_DIR/libultra.a:osSetEventMesg.o(.text);
      BUILD_DIR/libultra.a:osViSetEvent.o(.text);
      BUILD_DIR/libultra.a:osCreateThread.o(.text);
      BUILD_DIR/libultra.a:osRecvMesg.o(.text);
      BUILD_DIR/libultra.a:osSpTaskLoadGo.o(.text);
      BUILD_DIR/libultra.a:osSpTaskYield.o(.text);
      BUILD_DIR/libultra.a:osSendMesg.o(.text);
      BUILD_DIR/libultra.a:osSpTaskYielded.o(.text);
      BUILD_DIR/libultra.a:osStartThread.o(.text);
      BUILD_DIR/libultra.a:osWritebackDCacheAll.o(.text);
      BUILD_DIR/libultra.a:osCreateViManager.o(.text);
      BUILD_DIR/libultra.a:osViSetMode.o(.text);
      BUILD_DIR/libultra.a:osViBlack.o(.text);
      BUILD_DIR/libultra.a:osViSetSpecialFeatures.o(.text);
      BUILD_DIR/libultra.a:osCreatePiManager.o(.text);
      BUILD_DIR/libultra.a:osSetThreadPri.o(.text);
      BUILD_DIR/libultra.a:osInitialize.o(.text);
      BUILD_DIR/libultra.a:osViSwapBuffer.o(.text);
      BUILD_DIR/libultra.a:sqrtf.o(.text);
      BUILD_DIR/libultra.a:osContStartReadData.o(.text);
      BUILD_DIR/libultra.a:osContInit.o(.text);
      BUILD_DIR/libultra.a:osEepromProbe.o(.text);
      BUILD_DIR/libultra.a:llmuldiv.o(.text);
      BUILD_DIR/libultra.a:llmuldiv_gcc.o(.text);
      BUILD_DIR/libultra.a:osInvalDCache.o(.text);
      BUILD_DIR/libultra.a:osPiStartDma.o(.text);
      BUILD_DIR/libultra.a:bzero.o(.text);
      BUILD_DIR/libultra.a:osInvalICache.o(.text);
      BUILD_DIR/libultra.a:osEepromLongRead.o(.text);
      BUILD_DIR/libultra.a:osEepromLongWrite.o(.text);
      BUILD_DIR/libultra.a:bcopy.o(.text);
      BUILD_DIR/libultra.a:guOrthoF.o(.text);
      BUILD_DIR/libultra.a:guPerspectiveF.o(.text);
      BUILD_DIR/libultra.a:osGetTime.o(.text);
      BUILD_DIR/libultra.a:llconv.o(.text);
      BUILD_DIR/libultra.a:cosf.o(.text);
      BUILD_DIR/libultra.a:sinf.o(.text);
      BUILD_DIR/libultra.a:guTranslateF.o(.text);
      BUILD_DIR/libultra.a:guRotateF.o(.text);
      BUILD_DIR/libultra.a:guScaleF.o(.text);
      BUILD_DIR/libultra.a:osAiSetFrequency.o(.text);
      BUILD_DIR/libultra.a:alBnkfNew.o(.text);
      BUILD_DIR/libultra.a:osWritebackDCache.o(.text);
      BUILD_DIR/libultra.a:osAiGetLength.o(.text);
      BUILD_DIR/libultra.a:osAiSetNextBuffer.o(.text);
      BUILD_DIR/libultra.a:osTimer.o(.text);
      BUILD_DIR/libultra.a:_Printf.o(.text);
      BUILD_DIR/libultra.a:string.o(.text);
      BUILD_DIR/libultra.a:__osDequeueThread.o(.text);
      BUILD_DIR/libultra.a:__osDisableInt.o(.text);
      BUILD_DIR/libultra.a:__osRestoreInt.o(.text);
      BUILD_DIR/libultra.a:__osViInit.o(.text);
      BUILD_DIR/libultra.a:__osExceptionPreamble.o(.text);
      BUILD_DIR/libultra.a:osVirtualToPhysical.o(.text);
      BUILD_DIR/libultra.a:__osSpSetStatus.o(.text);
      BUILD_DIR/libultra.a:__osSpSetPc.o(.text);
      BUILD_DIR/libultra.a:__osSpRawStartDma.o(.text);
      BUILD_DIR/libultra.a:__osSpDeviceBusy.o(.text);
      BUILD_DIR/libultra.a:__osSpGetStatus.o(.text);
      BUILD_DIR/libultra.a:osGetThreadPri.o(.text);
      BUILD_DIR/libultra.a:__osViGetCurrentContext.o(.text);
      BUILD_DIR/libultra.a:__osViSwapContext.o(.text);
      BUILD_DIR/libultra.a:osGetCount.o(.text);
      BUILD_DIR/libultra.a:__osPiCreateAccessQueue.o(.text);
      BUILD_DIR/libultra.a:osPiRawStartDma.o(.text);
      BUILD_DIR/libultra.a:__osDevMgrMain.o(.text);
      BUILD_DIR/libultra.a:__osSetSR.o(.text);
      BUILD_DIR/libultra.a:__osGetSR.o(.text);
      BUILD_DIR/libultra.a:__osSetFpcCsr.o(.text);
      BUILD_DIR/libultra.a:__osSiRawReadIo.o(.text);
      BUILD_DIR/libultra.a:__osSiRawWriteIo.o(.text);
      BUILD_DIR/libultra.a:osMapTLBRdb.o(.text);
      BUILD_DIR/libultra.a:osPiRawReadIo.o(.text);
      BUILD_DIR/libultra.a:__osSiCreateAccessQueue.o(.text);
      BUILD_DIR/libultra.a:__osSiRawStartDma.o(.text);
      BUILD_DIR/libultra.a:osSetTimer.o(.text);
      BUILD_DIR/libultra.a:osEepromWrite.o(.text);
      BUILD_DIR/libultra.a:osJamMesg.o(.text);
      BUILD_DIR/libultra.a:osPiGetCmdQueue.o(.text);
      BUILD_DIR/libultra.a:osEepromRead.o(.text);
      BUILD_DIR/libultra.a:guMtxF2L.o(.text);
      BUILD_DIR/libultra.a:guMtxIdentF.o(.text);
      BUILD_DIR/libultra.a:guNormalize.o(.text);
      BUILD_DIR/libultra.a:__osAiDeviceBusy.o(.text);
      BUILD_DIR/libultra.a:__osSetCompare.o(.text);
      BUILD_DIR/libultra.a:_Litob.o(.text);
      BUILD_DIR/libultra.a:_Ldtob.o(.text);
      BUILD_DIR/libultra.a:kdebugserver.o(.text);
      BUILD_DIR/libultra.a:__osSyncPutChars.o(.text);
      BUILD_DIR/libultra.a:osSetIntMask.o(.text);
      BUILD_DIR/libultra.a:osDestroyThread.o(.text);
      BUILD_DIR/libultra.a:__osProbeTLB.o(.text);
      BUILD_DIR/libultra.a:__osSiDeviceBusy.o(.text);
      BUILD_DIR/libultra.a:ldiv.o(.text);
      BUILD_DIR/libultra.a:__osGetCause.o(.text);
      BUILD_DIR/libultra.a:__osAtomicDec.o(.text);
      BUILD_DIR/libultra.a:guLookAtRef.o(.text); /* Fast3DEX2 only */
      BUILD_DIR/lib/rsp.o(.text);

      /* data */
      BUILD_DIR/src/game*.o(.data*);

      BUILD_DIR/libultra.a:osViTable.o(.data*);
      BUILD_DIR/libultra.a:osCreateViManager.o(.data*);
      BUILD_DIR/libultra.a:osCreatePiManager.o(.data*);
      BUILD_DIR/libultra.a:osInitialize.o(.data*);
      BUILD_DIR/libultra.a:osContInit.o(.data*);
      BUILD_DIR/libultra.a:osAiSetNextBuffer.o(.data*);
      BUILD_DIR/libultra.a:osTimer.o(.data*);
      BUILD_DIR/libultra.a:_Printf.o(.data*);
      BUILD_DIR/libultra.a:__osDequeueThread.o(.data*);
      BUILD_DIR/libultra.a:__osViInit.o(.data*);
      BUILD_DIR/libultra.a:__osExceptionPreamble.o(.data*);
      BUILD_DIR/libultra.a:__osPiCreateAccessQueue.o(.data*);
      BUILD_DIR/libultra.a:__osSiCreateAccessQueue.o(.data*);
      BUILD_DIR/libultra.a:_Litob.o(.data*);
      BUILD_DIR/libultra.a:_Ldtob.o(.data*);
      BUILD_DIR/libultra.a:osViData.o(.data*);
      BUILD_DIR/libultra.a:kdebugserver.o(.data*);
      BUILD_DIR/libultra.a:__osSyncPutChars.o(.data*);
      BUILD_DIR/libultra.a:guRotateF.o(.data*);
      BUILD_DIR/libultra.a:*.o(.data*);

      /* rodata */
      BUILD_DIR/src/game*.o(.rodata*);

      BUILD_DIR/libultra.a:guPerspectiveF.o(.rodata*);
      BUILD_DIR/libultra.a:llconv.o(.rodata*);
      BUILD_DIR/libultra.a:cosf.o(.rodata*);
      BUILD_DIR/libultra.a:sinf.o(.rodata*);
      BUILD_DIR/libultra.a:guRotateF.o(.rodata*);

      BUILD_DIR/libultra.a:_Printf.o(.rodata*);
      BUILD_DIR/libultra.a:__osExceptionPreamble.o(.rodata*);
      BUILD_DIR/libultra.a:NaN.o(.rodata*);
      BUILD_DIR/libultra.a:_Litob.o(.rodata*);
      BUILD_DIR/libultra.a:_Ldtob.o(.rodata*);

      BUILD_DIR/libultra.a:osSetIntMask.o(.rodata*);
      BUILD_DIR/libultra.a:guLookAtRef.o(.rodata*); /* Fast3DEX2 only */
      BUILD_DIR/libultra.a:*.o(.rodata*);
      BUILD_DIR/lib/rsp.o(.rodata*);
   }
   END_SEG(main)

   BEGIN_NOLOAD(main)
   {
      BUILD_DIR/src/game*.o(.bss*);

      BUILD_DIR/libultra.a:osSetEventMesg.o(.bss*);
      BUILD_DIR/libultra.a:osSpTaskLoadGo.o(.bss*);
      BUILD_DIR/libultra.a:osCreateViManager.o(.bss*);
      BUILD_DIR/libultra.a:osCreatePiManager.o(.bss*);
      BUILD_DIR/libultra.a:osInitialize.o(.bss*);
      BUILD_DIR/libultra.a:osContStartReadData.o(.bss*);
      BUILD_DIR/libultra.a:osContInit.o(.bss*);
      BUILD_DIR/libultra.a:guRotateF.o(.bss*);
      BUILD_DIR/libultra.a:osTimer.o(.bss*);
      BUILD_DIR/libultra.a:_Printf.o(.bss*);
      BUILD_DIR/libultra.a:__osPiCreateAccessQueue.o(.bss*);
      BUILD_DIR/libultra.a:__osSiCreateAccessQueue.o(.bss*);
      BUILD_DIR/libultra.a:osEepromWrite.o(.bss*);
      BUILD_DIR/libultra.a:unk_stack_data.o(.bss*);
      BUILD_DIR/libultra.a:kdebugserver.o(.bss*);
      BUILD_DIR/libultra.a:*.o(.bss*);

      . = ALIGN(0x8);
   }
   END_NOLOAD(main)
   _mainSegmentNoloadSizeLo = SIZEOF (.main.noload) & 0xffff;
   _mainSegmentNoloadSizeHi = SIZEOF (.main.noload) >> 16;

   BEGIN_SEG(custom, SEG_CUSTOM)
   {
      BUILD_DIR/asm/custom.o(.text);
   }
   END_SEG(custom)

   __expansionRamStart = 0x80400000;
   ASSERT((. <= __expansionRamStart), "Error: RDRAM expanded into Expansion RAM, despite Expansion RAM not being defined.")
}
