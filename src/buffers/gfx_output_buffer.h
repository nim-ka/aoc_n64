#ifndef GFX_OUTPUT_BUFFER_H
#define GFX_OUTPUT_BUFFER_H

#ifdef VERSION_EU
extern u64 gGfxSPTaskOutputBuffer[0x2fc0];
#else
extern u64 gGfxSPTaskOutputBuffer[0x3e00];
#endif

#endif
