.include "macros.inc"

.ifdef VERSION_US
.set DEMO_LIST_COUNT, 7
.else
.set DEMO_LIST_COUNT, 6
.endif

demo_inputs:
glabel gDemoInputs

.hword 0 # current segment
.hword DEMO_LIST_COUNT # number of entries
.word 0 # ok...

.ifdef VERSION_US
.word (demo_6 - demo_inputs), (demo_6_end - demo_6) # Bowser in the Dark World
.endif
.word (demo_4 - demo_inputs), ((demo_4_end + 0x170) - demo_4) # Whomp's Fortress (the size is too large, but the demo ends before it can use the PSS demo inputs.)
.word (demo_1 - demo_inputs), (demo_1_end - demo_1) # Cool Cool Mountain
.word (demo_0 - demo_inputs), (demo_0_end - demo_0) # Big Boo's Haunt
.word (demo_3 - demo_inputs), (demo_3_end - demo_3) # Jolly Rodger's Bay
.word (demo_2 - demo_inputs), (demo_2_end - demo_2) # Hazy Maze Cave
.word (demo_5 - demo_inputs), (demo_5_end - demo_5) # Princess Secret Slide

demo_0:
.incbin "demos/bbh.bin"
demo_0_end:

demo_1:
.incbin "demos/ccm.bin"
demo_1_end:

demo_2:
.incbin "demos/hmc.bin"
demo_2_end:

demo_3:
.incbin "demos/jrb.bin"
demo_3_end:

demo_4:
.incbin "demos/wf.bin"
demo_4_end:

demo_5:
.incbin "demos/pss.bin"
demo_5_end:

unused_demo: # might be an unused demo, but it doesn't define a header, so it cant be normally called.
.incbin "demos/unused.bin" # TODO: Identify me
unused_demo_end:

.ifdef VERSION_US
demo_6:
.incbin "demos/bitdw.bin"
demo_6_end:
.endif

.align 4, 0x00

.demo_inputs_end:
