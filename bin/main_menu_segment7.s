.section .rodata

.include "macros.inc"

mm7_light_000000: # 0x07000000
.byte 0x3F, 0x3F, 0x3F, 0x00, 0x3F, 0x3F, 0x3F, 0x00

mm7_light_000008: # 0x07000008
.byte 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

mm7_texture_000018: # 0x07000018
.incbin "bin/main_menu_segment7/main_menu_segment7.00018.rgba16"
mm7_texture_000818: # 0x07000818
.incbin "bin/main_menu_segment7/main_menu_segment7.00818.rgba16"
mm7_texture_001018: # 0x07001018
.incbin "bin/main_menu_segment7/main_menu_segment7.01018.rgba16"
mm7_texture_002018: # 0x07002018
.incbin "bin/main_menu_segment7/main_menu_segment7.02018.rgba16"

mm7_vertices_003018: # 0x07003018
vertex -163, -122,    0,    0,  990,  0x00, 0xB6, 0x66, 0xFF
vertex  163, -122,    0,  990,  990,  0x00, 0xB6, 0x66, 0xFF
vertex -122,  -81,   30,   96,  820,  0x00, 0xB6, 0x66, 0xFF
vertex  122,  -81,   30,  862,  820,  0x00, 0xB6, 0x66, 0xFF
vertex -163, -122,    0,    0,  990,  0xB6, 0x00, 0x66, 0xFF
vertex -122,  -81,   30,   96,  820,  0xB6, 0x00, 0x66, 0xFF
vertex -163,  122,    0,    0,    0,  0xB6, 0x00, 0x66, 0xFF
vertex -122,   81,   30,   96,  138,  0xB6, 0x00, 0x66, 0xFF
vertex -122,   81,   30,   96,  138,  0x00, 0x4A, 0x66, 0xFF
vertex  122,   81,   30,  862,  138,  0x00, 0x4A, 0x66, 0xFF
vertex  163,  122,    0,  990,    0,  0x00, 0x4A, 0x66, 0xFF
vertex -163,  122,    0,    0,    0,  0x00, 0x4A, 0x66, 0xFF
vertex  122,   81,   30,  862,  138,  0x4A, 0x00, 0x66, 0xFF
vertex  122,  -81,   30,  862,  820,  0x4A, 0x00, 0x66, 0xFF
vertex  163, -122,    0,  990,  990,  0x4A, 0x00, 0x66, 0xFF
vertex  163,  122,    0,  990,    0,  0x4A, 0x00, 0x66, 0xFF

mm7_vertices_003118: # 0x07003118
vertex  122,   81,   30, 2012,    0,  0x00, 0x00, 0x7F, 0xFF
vertex -122,   81,   30,    0,    0,  0x00, 0x00, 0x7F, 0xFF
vertex  122,  -81,   30, 2012,  990,  0x00, 0x00, 0x7F, 0xFF
vertex -122,  -81,   30,    0,  990,  0x00, 0x00, 0x7F, 0xFF

mm7_f3d_003158: # 0x07003158
.word 0xE7000000, 0x00000000
.word 0xFC127E24, 0xFFFFF9FC
.word 0xB6000000, 0x00000200
.word 0xF5100000, 0x07000000
.word 0xBB000001, 0xFFFFFFFF
.word 0xE8000000, 0x00000000
.word 0xF5101000, 0x00014050
.word 0xF2000000, 0x0007C07C
.word 0xB8000000, 0x00000000

mm7_f3d_0031A0: # 0x070031A0
.word 0x03860010, mm7_light_000008
.word 0x03880010, mm7_light_000000
.word 0x04F00100, mm7_vertices_003018
.word 0xBF000000, 0x00000A14
.word 0xBF000000, 0x000A1E14
.word 0xBF000000, 0x0028323C
.word 0xBF000000, 0x0032463C
.word 0xBF000000, 0x00505A64
.word 0xBF000000, 0x006E5064
.word 0xBF000000, 0x0078828C
.word 0xBF000000, 0x0096788C
.word 0xE8000000, 0x00000000
.word 0xF5102000, 0x00014060
.word 0xF2000000, 0x000FC07C
.word 0xB8000000, 0x00000000

mm7_f3d_003218: # 0x07003218
.word 0x04300040, mm7_vertices_003118
.word 0xBF000000, 0x00000A14
.word 0xBF000000, 0x000A1E14
.word 0xBB000000, 0xFFFFFFFF
.word 0xE7000000, 0x00000000
.word 0xFCFFFFFF, 0xFFFE793C
.word 0xB7000000, 0x00000200
.word 0xB8000000, 0x00000000

mm7_vertices_003258: # 0x07003258
vertex  163, -122,    0,    0,  990,  0x00, 0x00, 0x81, 0xFF
vertex -163, -122,    0,  990,  990,  0x00, 0x00, 0x81, 0xFF
vertex  163,  122,    0,    0,    0,  0x00, 0x00, 0x81, 0xFF
vertex -163,  122,    0,  990,    0,  0x00, 0x00, 0x81, 0xFF

mm7_f3d_003298: # 0x07003298
.word 0xE7000000, 0x00000000
.word 0xFC127E24, 0xFFFFF9FC
.word 0xB6000000, 0x00000200
.word 0xF5100000, 0x07000000
.word 0xBB000001, 0xFFFFFFFF
.word 0xE8000000, 0x00000000
.word 0xF5101000, 0x00014050
.word 0xF2000000, 0x0007C07C
.word 0xB8000000, 0x00000000

mm7_f3d_0032E0: # 0x070032E0
.word 0x03860010, mm7_light_000008
.word 0x03880010, mm7_light_000000
.word 0x04300040, mm7_vertices_003258
.word 0xBF000000, 0x00000A14
.word 0xBF000000, 0x000A1E14
.word 0xBB000000, 0xFFFFFFFF
.word 0xE7000000, 0x00000000
.word 0xFCFFFFFF, 0xFFFE793C
.word 0xB7000000, 0x00000200
.word 0xB8000000, 0x00000000

glabel mm7_f3d_003330 # 0x07003330
.word 0x06000000, mm7_f3d_003158
.word 0xFD100000, mm7_texture_000018
.word 0xE6000000, 0x00000000
.word 0xF3000000, 0x073FF100
.word 0x06000000, mm7_f3d_0031A0
.word 0xFD100000, mm7_texture_001018
.word 0xE6000000, 0x00000000
.word 0xF3000000, 0x077FF080
.word 0x06000000, mm7_f3d_003218
.word 0xB8000000, 0x00000000

glabel mm7_f3d_003380 # 0x07003380
.word 0x06000000, mm7_f3d_003158
.word 0xFD100000, mm7_texture_000018
.word 0xE6000000, 0x00000000
.word 0xF3000000, 0x073FF100
.word 0x06000000, mm7_f3d_0031A0
.word 0xFD100000, mm7_texture_002018
.word 0xE6000000, 0x00000000
.word 0xF3000000, 0x077FF080
.word 0x06000000, mm7_f3d_003218
.word 0xB8000000, 0x00000000

glabel mm7_f3d_0033D0 # 0x070033D0
.word 0x06000000, mm7_f3d_003298
.word 0xFD100000, mm7_texture_000818
.word 0xE6000000, 0x00000000
.word 0xF3000000, 0x073FF100
.word 0x06000000, mm7_f3d_0032E0
.word 0xB8000000, 0x00000000

glabel mm7_f3d_003400 # 0x07003400
.word 0xE7000000, 0x00000000
.word 0xB6000000, 0x00000200
.word 0x03860010, mm7_light_000008
.word 0x03880010, mm7_light_000000
.word 0x04300040, mm7_vertices_003258
.word 0xBF000000, 0x00000A14
.word 0xBF000000, 0x000A1E14
.word 0xE7000000, 0x00000000
.word 0xB7000000, 0x00000200
.word 0xB8000000, 0x00000000

mm7_light_003450: # 07003450
.byte 0x3F, 0x3F, 0x3F, 0x00, 0x3F, 0x3F, 0x3F, 0x00

mm7_light_003458: # 07003458
.byte 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0x00
.byte 0x28, 0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00

mm7_texture_003468: # 0x07003468
.incbin "bin/main_menu_segment7/main_menu_segment7.03468.rgba16"
mm7_texture_003C68: # 0x07003C68
.incbin "bin/main_menu_segment7/main_menu_segment7.03C68.rgba16"
mm7_texture_004468: # 0x07004468
.incbin "bin/main_menu_segment7/main_menu_segment7.04468.rgba16"
mm7_texture_004C68: # 0x07004C68
.incbin "bin/main_menu_segment7/main_menu_segment7.04C68.rgba16"
mm7_texture_005468: # 0x07005468
.incbin "bin/main_menu_segment7/main_menu_segment7.05468.rgba16"

mm7_vertices_005C68: # 0x07005C68
vertex -163, -122,    0,  990,    0,  0xB6, 0x00, 0x66, 0xFF
vertex -122,  -81,   30,  862,  138,  0xB6, 0x00, 0x66, 0xFF
vertex -163,  122,    0,  990,  990,  0xB6, 0x00, 0x66, 0xFF
vertex -143,  102,    0,  926,  904,  0x59, 0x00, 0xA7, 0xFF
vertex -133,   92,   10,  894,  862,  0x59, 0x00, 0xA7, 0xFF
vertex -133,  -92,   10,  894,   96,  0x59, 0x00, 0xA7, 0xFF
vertex -133,   92,   10,  894,  862,  0x00, 0x00, 0x81, 0xFF
vertex  133,  -92,   10,   64,   96,  0x00, 0x00, 0x81, 0xFF
vertex -133,  -92,   10,  894,   96,  0x00, 0x00, 0x81, 0xFF
vertex  133,   92,   10,   64,  862,  0x00, 0x00, 0x81, 0xFF
vertex  133,   92,   10,   64,  862,  0x00, 0xA7, 0xA7, 0xFF
vertex -133,   92,   10,  894,  862,  0x00, 0xA7, 0xA7, 0xFF
vertex -143,  102,    0,  926,  904,  0x00, 0xA7, 0xA7, 0xFF
vertex  143, -102,    0,   32,   54,  0xA7, 0x00, 0xA7, 0xFF
vertex  133,   92,   10,   64,  862,  0xA7, 0x00, 0xA7, 0xFF
vertex  143,  102,    0,   32,  904,  0xA7, 0x00, 0xA7, 0xFF

mm7_vertices_005D68: # 0x07005D68
vertex  143, -102,    0,   32,   54,  0xA7, 0x00, 0xA7, 0xFF
vertex  133,  -92,   10,   64,   96,  0xA7, 0x00, 0xA7, 0xFF
vertex  133,   92,   10,   64,  862,  0xA7, 0x00, 0xA7, 0xFF
vertex  133,   92,   10,   64,  862,  0x00, 0xA7, 0xA7, 0xFF
vertex -143,  102,    0,  926,  904,  0x00, 0xA7, 0xA7, 0xFF
vertex  143,  102,    0,   32,  904,  0x00, 0xA7, 0xA7, 0xFF
vertex -143, -102,    0,  926,   54,  0x00, 0x59, 0xA7, 0xFF
vertex  133,  -92,   10,   64,   96,  0x00, 0x59, 0xA7, 0xFF
vertex  143, -102,    0,   32,   54,  0x00, 0x59, 0xA7, 0xFF
vertex -133,  -92,   10,  894,   96,  0x00, 0x59, 0xA7, 0xFF
vertex -143,  102,    0,  926,  904,  0x59, 0x00, 0xA7, 0xFF
vertex -133,  -92,   10,  894,   96,  0x59, 0x00, 0xA7, 0xFF
vertex -143, -102,    0,  926,   54,  0x59, 0x00, 0xA7, 0xFF
vertex  163,  122,    0,    0,  990,  0x00, 0x00, 0x81, 0xFF
vertex -143,  102,    0,  926,  904,  0x00, 0x00, 0x81, 0xFF
vertex -163,  122,    0,  990,  990,  0x00, 0x00, 0x81, 0xFF

mm7_vertices_005E68: # 0x07005E68
vertex  163,  122,    0,    0,  990,  0x00, 0x00, 0x81, 0xFF
vertex  143,  102,    0,   32,  904,  0x00, 0x00, 0x81, 0xFF
vertex -143,  102,    0,  926,  904,  0x00, 0x00, 0x81, 0xFF
vertex  143, -102,    0,   32,   54,  0x00, 0x00, 0x81, 0xFF
vertex  163, -122,    0,    0,    0,  0x00, 0x00, 0x81, 0xFF
vertex -163,  122,    0,  990,  990,  0x00, 0x00, 0x81, 0xFF
vertex -143, -102,    0,  926,   54,  0x00, 0x00, 0x81, 0xFF
vertex -163, -122,    0,  990,    0,  0x00, 0x00, 0x81, 0xFF
vertex  163, -122,    0,    0,    0,  0x00, 0xB6, 0x66, 0xFF
vertex  122,  -81,   30,   96,  138,  0x00, 0xB6, 0x66, 0xFF
vertex -122,  -81,   30,  862,  138,  0x00, 0xB6, 0x66, 0xFF
vertex -122,  -81,   30,  862,  138,  0xB6, 0x00, 0x66, 0xFF
vertex -122,   81,   30,  862,  820,  0xB6, 0x00, 0x66, 0xFF
vertex -163,  122,    0,  990,  990,  0xB6, 0x00, 0x66, 0xFF

mm7_vertices_005F48: # 0x07005F48
vertex -122,   81,   30,  862,  820,  0x00, 0x00, 0x7F, 0xFF
vertex -122,  -81,   30,  862,  138,  0x00, 0x00, 0x7F, 0xFF
vertex  122,  -81,   30,   96,  138,  0x00, 0x00, 0x7F, 0xFF
vertex -163, -122,    0,  990,    0,  0x00, 0xB6, 0x66, 0xFF
vertex  163, -122,    0,    0,    0,  0x00, 0xB6, 0x66, 0xFF
vertex -122,  -81,   30,  862,  138,  0x00, 0xB6, 0x66, 0xFF
vertex -122,   81,   30,  862,  820,  0x00, 0x4A, 0x66, 0xFF
vertex  122,   81,   30,   96,  820,  0x00, 0x4A, 0x66, 0xFF
vertex  163,  122,    0,    0,  990,  0x00, 0x4A, 0x66, 0xFF
vertex -163,  122,    0,  990,  990,  0x00, 0x4A, 0x66, 0xFF
vertex  122,   81,   30,   96,  820,  0x00, 0x00, 0x7F, 0xFF
vertex  163,  122,    0,    0,  990,  0x4A, 0x00, 0x66, 0xFF
vertex  122,   81,   30,   96,  820,  0x4A, 0x00, 0x66, 0xFF
vertex  163, -122,    0,    0,    0,  0x4A, 0x00, 0x66, 0xFF
vertex  122,  -81,   30,   96,  138,  0x4A, 0x00, 0x66, 0xFF

mm7_f3d_006038: # 0x07006038
.word 0x03860010, mm7_light_003458
.word 0x03880010, mm7_light_003450
.word 0x04F00100, mm7_vertices_005C68
.word 0xBF000000, 0x00000A14
.word 0xBF000000, 0x001E2832
.word 0xBF000000, 0x003C4650
.word 0xBF000000, 0x003C5A46
.word 0xBF000000, 0x00646E78
.word 0xBF000000, 0x00828C96
.word 0x04F00100, mm7_vertices_005D68
.word 0xBF000000, 0x00000A14
.word 0xBF000000, 0x001E2832
.word 0xBF000000, 0x003C4650
.word 0xBF000000, 0x003C5A46
.word 0xBF000000, 0x00646E78
.word 0xBF000000, 0x00828C96
.word 0x04D000E0, mm7_vertices_005E68
.word 0xBF000000, 0x00000A14
.word 0xBF000000, 0x00001E0A
.word 0xBF000000, 0x0000281E
.word 0xBF000000, 0x0032143C
.word 0xBF000000, 0x00323C46
.word 0xBF000000, 0x003C1E28
.word 0xBF000000, 0x003C2846
.word 0xBF000000, 0x00505A64
.word 0xBF000000, 0x006E7882
.word 0x04E000F0, mm7_vertices_005F48
.word 0xBF000000, 0x00000A14
.word 0xBF000000, 0x001E2832
.word 0xBF000000, 0x003C4650
.word 0xBF000000, 0x005A3C50
.word 0xBF000000, 0x00640014
.word 0xBF000000, 0x006E7882
.word 0xBF000000, 0x00788C82
.word 0xB8000000, 0x00000000

mm7_f3d_006150: # 0x07006150
.word 0xE7000000, 0x00000000
.word 0xFC127E24, 0xFFFFF9FC
.word 0xB6000000, 0x00000200
.word 0xF5100000, 0x07000000
.word 0xBB000001, 0xFFFFFFFF
.word 0xE8000000, 0x00000000
.word 0xF5101000, 0x00014050
.word 0xF2000000, 0x0007C07C
.word 0xB8000000, 0x00000000

mm7_f3d_006198: # 0x07006198
.word 0x06000000, mm7_f3d_006038
.word 0xBB000000, 0xFFFFFFFF
.word 0xE7000000, 0x00000000
.word 0xFCFFFFFF, 0xFFFE793C
.word 0xB7000000, 0x00000200
.word 0xB8000000, 0x00000000

glabel mm7_f3d_0061C8 # 0x070061C8
.word 0x06000000, mm7_f3d_006150
.word 0xFD100000, mm7_texture_003468
.word 0xE6000000, 0x00000000
.word 0xF3000000, 0x073FF100
.word 0x06000000, mm7_f3d_006198
.word 0xB8000000, 0x00000000

glabel mm7_f3d_0061F8 # 0x070061F8
.word 0x06000000, 0x07006150
.word 0xFD100000, mm7_texture_003C68
.word 0xE6000000, 0x00000000
.word 0xF3000000, 0x073FF100
.word 0x06000000, mm7_f3d_006198
.word 0xB8000000, 0x00000000

glabel mm7_f3d_006228 # 0x07006228
.word 0x06000000, 0x07006150
.word 0xFD100000, mm7_texture_004468
.word 0xE6000000, 0x00000000
.word 0xF3000000, 0x073FF100
.word 0x06000000, mm7_f3d_006198
.word 0xB8000000, 0x00000000

glabel mm7_f3d_006258 # 0x07006258
.word 0x06000000, 0x07006150
.word 0xFD100000, mm7_texture_004C68
.word 0xE6000000, 0x00000000
.word 0xF3000000, 0x073FF100
.word 0x06000000, mm7_f3d_006198
.word 0xB8000000, 0x00000000

glabel mm7_f3d_006288 # 0x07006288
.word 0x06000000, 0x07006150
.word 0xFD100000, mm7_texture_005468
.word 0xE6000000, 0x00000000
.word 0xF3000000, 0x073FF100
.word 0x06000000, mm7_f3d_006198
.word 0xB8000000, 0x00000000

glabel mm7_f3d_0062B8 # 0x070062B8
.word 0x06000000, 0x07006150
.word 0xFD100000, mm7_texture_000018
.word 0xE6000000, 0x00000000
.word 0xF3000000, 0x073FF100
.word 0x06000000, mm7_f3d_006198
.word 0xB8000000, 0x00000000

mm7_vertices_0062E8: # 0x070062E8
vertex    0,    0,    0,    0, 1984,  0x00, 0x00, 0x7F, 0xFF
vertex   32,    0,    0, 1984, 1984,  0x00, 0x00, 0x7F, 0xFF
vertex   32,   32,    0, 1984,    0,  0x00, 0x00, 0x7F, 0xFF
vertex    0,   32,    0,    0,    0,  0x00, 0x00, 0x7F, 0xFF

mm7_texture_006328: # 0x07006328
.incbin "bin/main_menu_segment7/main_menu_segment7.06328.rgba16"
mm7_texture_006B28: # 0x07006B28
.incbin "bin/main_menu_segment7/main_menu_segment7.06B28.rgba16"
mm7_texture_0073D0: # 0x070073D0
.incbin "bin/main_menu_segment7/main_menu_segment7.073D0.rgba16"
mm7_texture_0075D0: # 0x070075D0
.incbin "bin/main_menu_segment7/main_menu_segment7.075D0.rgba16"
mm7_texture_0077D0: # 0x070077D0
.incbin "bin/main_menu_segment7/main_menu_segment7.077D0.rgba16"
mm7_texture_0079D0: # 0x070079D0
.incbin "bin/main_menu_segment7/main_menu_segment7.079D0.rgba16"
mm7_texture_007BD0: # 0x07007BD0
.incbin "bin/main_menu_segment7/main_menu_segment7.07BD0.rgba16"
mm7_texture_007DD0: # 0x07007DD0
.incbin "bin/main_menu_segment7/main_menu_segment7.07DD0.rgba16"
mm7_texture_007FD0: # 0x07007FD0
.incbin "bin/main_menu_segment7/main_menu_segment7.07FD0.rgba16"
mm7_texture_0081D0: # 0x070081D0
.incbin "bin/main_menu_segment7/main_menu_segment7.081D0.rgba16"
mm7_texture_0083D0: # 0x070083D0
.incbin "bin/main_menu_segment7/main_menu_segment7.083D0.rgba16"
mm7_texture_0085D0: # 0x070085D0
.incbin "bin/main_menu_segment7/main_menu_segment7.085D0.rgba16"
mm7_texture_0087D0: # 0x070087D0
.incbin "bin/main_menu_segment7/main_menu_segment7.087D0.rgba16"
mm7_texture_0089D0: # 0x070089D0
.incbin "bin/main_menu_segment7/main_menu_segment7.089D0.rgba16"
mm7_texture_008BD0: # 0x07008BD0
.incbin "bin/main_menu_segment7/main_menu_segment7.08BD0.rgba16"
mm7_texture_008DD0: # 0x07008DD0
.incbin "bin/main_menu_segment7/main_menu_segment7.08DD0.rgba16"
mm7_texture_008FD0: # 0x07008FD0
.incbin "bin/main_menu_segment7/main_menu_segment7.08FD0.rgba16"
mm7_texture_0091D0: # 0x070091D0
.incbin "bin/main_menu_segment7/main_menu_segment7.091D0.rgba16"
mm7_texture_0093D0: # 0x070093D0
.incbin "bin/main_menu_segment7/main_menu_segment7.093D0.rgba16"
mm7_texture_0095D0: # 0x070095D0
.incbin "bin/main_menu_segment7/main_menu_segment7.095D0.rgba16"
mm7_texture_0097D0: # 0x070097D0
.incbin "bin/main_menu_segment7/main_menu_segment7.097D0.rgba16"
mm7_texture_0099D0: # 0x070099D0
.incbin "bin/main_menu_segment7/main_menu_segment7.099D0.rgba16"
mm7_texture_009BD0: # 0x07009BD0
.incbin "bin/main_menu_segment7/main_menu_segment7.09BD0.rgba16"
mm7_texture_009DD0: # 0x07009DD0
.incbin "bin/main_menu_segment7/main_menu_segment7.09DD0.rgba16"
mm7_texture_009FD0: # 0x07009FD0
.incbin "bin/main_menu_segment7/main_menu_segment7.09FD0.rgba16"
mm7_texture_00A1D0: # 0x0700A1D0
.incbin "bin/main_menu_segment7/main_menu_segment7.0A1D0.rgba16"
mm7_texture_00A3D0: # 0x0700A3D0
.incbin "bin/main_menu_segment7/main_menu_segment7.0A3D0.rgba16"
mm7_texture_00A5D0: # 0x0700A5D0
.incbin "bin/main_menu_segment7/main_menu_segment7.0A5D0.rgba16"
mm7_texture_00A7D0: # 0x0700A7D0
.incbin "bin/main_menu_segment7/main_menu_segment7.0A7D0.rgba16"
mm7_texture_00A9D0: # 0x0700A9D0
.incbin "bin/main_menu_segment7/main_menu_segment7.0A9D0.rgba16"

table_00ABD0: # 0x0700ABD0
.word mm7_texture_0073D0, mm7_texture_0075D0, mm7_texture_0077D0, mm7_texture_0079D0
.word mm7_texture_007BD0, mm7_texture_007DD0, mm7_texture_007FD0, mm7_texture_0081D0
.word mm7_texture_0083D0, mm7_texture_0085D0, mm7_texture_0087D0, mm7_texture_0089D0
.word mm7_texture_008BD0, mm7_texture_008DD0, mm7_texture_008FD0, mm7_texture_0091D0
.word mm7_texture_0093D0, mm7_texture_0095D0, mm7_texture_0097D0, mm7_texture_0099D0
.word mm7_texture_009BD0, mm7_texture_009DD0, mm7_texture_009FD0, mm7_texture_00A1D0
.word mm7_texture_00A3D0, mm7_texture_00A5D0, mm7_texture_00A7D0, mm7_texture_00A9D0
.word 0x00000000, 0x00000000

mm7_texture_00AC48: # 0x0700AC48
.incbin "bin/main_menu_segment7/main_menu_segment7.0AC48.ia8"
mm7_texture_00AC88: # 0x0700AC88
.incbin "bin/main_menu_segment7/main_menu_segment7.0AC88.ia8"
mm7_texture_00ACC8: # 0x0700ACC8
.incbin "bin/main_menu_segment7/main_menu_segment7.0ACC8.ia8"
mm7_texture_00AD08: # 0x0700AD08
.incbin "bin/main_menu_segment7/main_menu_segment7.0AD08.ia8"
mm7_texture_00AD48: # 0x0700AD48
.incbin "bin/main_menu_segment7/main_menu_segment7.0AD48.ia8"
mm7_texture_00AD88: # 0x0700AD88
.incbin "bin/main_menu_segment7/main_menu_segment7.0AD88.ia8"
mm7_texture_00ADC8: # 0x0700ADC8
.incbin "bin/main_menu_segment7/main_menu_segment7.0ADC8.ia8"
mm7_texture_00AE08: # 0x0700AE08
.incbin "bin/main_menu_segment7/main_menu_segment7.0AE08.ia8"
mm7_texture_00AE48: # 0x0700AE48
.incbin "bin/main_menu_segment7/main_menu_segment7.0AE48.ia8"
mm7_texture_00AE88: # 0x0700AE88
.incbin "bin/main_menu_segment7/main_menu_segment7.0AE88.ia8"
mm7_texture_00AEC8: # 0x0700AEC8
.incbin "bin/main_menu_segment7/main_menu_segment7.0AEC8.ia8"
mm7_texture_00AF08: # 0x0700AF08
.incbin "bin/main_menu_segment7/main_menu_segment7.0AF08.ia8"
mm7_texture_00AF48: # 0x0700AF48
.incbin "bin/main_menu_segment7/main_menu_segment7.0AF48.ia8"
mm7_texture_00AF88: # 0x0700AF88
.incbin "bin/main_menu_segment7/main_menu_segment7.0AF88.ia8"
mm7_texture_00AFC8: # 0x0700AFC8
.incbin "bin/main_menu_segment7/main_menu_segment7.0AFC8.ia8"
mm7_texture_00B008: # 0x0700B008
.incbin "bin/main_menu_segment7/main_menu_segment7.0B008.ia8"
mm7_texture_00B048: # 0x0700B048
.incbin "bin/main_menu_segment7/main_menu_segment7.0B048.ia8"
mm7_texture_00B088: # 0x0700B088
.incbin "bin/main_menu_segment7/main_menu_segment7.0B088.ia8"
mm7_texture_00B0C8: # 0x0700B0C8
.incbin "bin/main_menu_segment7/main_menu_segment7.0B0C8.ia8"
mm7_texture_00B108: # 0x0700B108
.incbin "bin/main_menu_segment7/main_menu_segment7.0B108.ia8"
mm7_texture_00B148: # 0x0700B148
.incbin "bin/main_menu_segment7/main_menu_segment7.0B148.ia8"
mm7_texture_00B188: # 0x0700B188
.incbin "bin/main_menu_segment7/main_menu_segment7.0B188.ia8"
mm7_texture_00B1C8: # 0x0700B1C8
.incbin "bin/main_menu_segment7/main_menu_segment7.0B1C8.ia8"
mm7_texture_00B208: # 0x0700B208
.incbin "bin/main_menu_segment7/main_menu_segment7.0B208.ia8"
mm7_texture_00B248: # 0x0700B248
.incbin "bin/main_menu_segment7/main_menu_segment7.0B248.ia8"
mm7_texture_00B288: # 0x0700B288
.incbin "bin/main_menu_segment7/main_menu_segment7.0B288.ia8"
mm7_texture_00B2C8: # 0x0700B2C8
.incbin "bin/main_menu_segment7/main_menu_segment7.0B2C8.ia8"
mm7_texture_00B308: # 0x0700B308
.incbin "bin/main_menu_segment7/main_menu_segment7.0B308.ia8"
mm7_texture_00B348: # 0x0700B348
.incbin "bin/main_menu_segment7/main_menu_segment7.0B348.ia8"
mm7_texture_00B388: # 0x0700B388
.incbin "bin/main_menu_segment7/main_menu_segment7.0B388.ia8"
mm7_texture_00B3C8: # 0x0700B3C8
.incbin "bin/main_menu_segment7/main_menu_segment7.0B3C8.ia8"
mm7_texture_00B408: # 0x0700B408
.incbin "bin/main_menu_segment7/main_menu_segment7.0B408.ia8"
mm7_texture_00B448: # 0x0700B448
.incbin "bin/main_menu_segment7/main_menu_segment7.0B448.ia8"
mm7_texture_00B488: # 0x0700B488
.incbin "bin/main_menu_segment7/main_menu_segment7.0B488.ia8"
mm7_texture_00B4C8: # 0x0700B4C8
.incbin "bin/main_menu_segment7/main_menu_segment7.0B4C8.ia8"
mm7_texture_00B508: # 0x0700B508
.incbin "bin/main_menu_segment7/main_menu_segment7.0B508.ia8"
mm7_texture_00B548: # 0x0700B548
.incbin "bin/main_menu_segment7/main_menu_segment7.0B548.ia8"
mm7_texture_00B588: # 0x0700B588
.incbin "bin/main_menu_segment7/main_menu_segment7.0B588.ia8"
mm7_texture_00B5C8: # 0x0700B5C8
.incbin "bin/main_menu_segment7/main_menu_segment7.0B5C8.ia8"
mm7_texture_00B608: # 0x0700B608
.incbin "bin/main_menu_segment7/main_menu_segment7.0B608.ia8"
mm7_texture_00B648: # 0x0700B648
.incbin "bin/main_menu_segment7/main_menu_segment7.0B648.ia8"
mm7_texture_00B688: # 0x0700B688
.incbin "bin/main_menu_segment7/main_menu_segment7.0B688.ia8"
mm7_texture_00B6C8: # 0x0700B6C8
.incbin "bin/main_menu_segment7/main_menu_segment7.0B6C8.ia8"
mm7_texture_00B708: # 0x0700B708
.incbin "bin/main_menu_segment7/main_menu_segment7.0B708.ia8"
mm7_texture_00B748: # 0x0700B748
.incbin "bin/main_menu_segment7/main_menu_segment7.0B748.ia8"
mm7_texture_00B788: # 0x0700B788
.incbin "bin/main_menu_segment7/main_menu_segment7.0B788.ia8"
mm7_texture_00B7C8: # 0x0700B7C8
.incbin "bin/main_menu_segment7/main_menu_segment7.0B7C8.ia8"
mm7_texture_00B808: # 0x0700B808
.incbin "bin/main_menu_segment7/main_menu_segment7.0B808.ia8"
mm7_texture_00B848: # 0x0700B848
.incbin "bin/main_menu_segment7/main_menu_segment7.0B848.ia8"
mm7_texture_00B888: # 0x0700B888
.incbin "bin/main_menu_segment7/main_menu_segment7.0B888.ia8"
mm7_texture_00B8C8: # 0x0700B8C8
.incbin "bin/main_menu_segment7/main_menu_segment7.0B8C8.ia8"
mm7_texture_00B908: # 0x0700B908
.incbin "bin/main_menu_segment7/main_menu_segment7.0B908.ia8"
mm7_texture_00B948: # 0x0700B948
.incbin "bin/main_menu_segment7/main_menu_segment7.0B948.ia8"
mm7_texture_00B988: # 0x0700B988
.incbin "bin/main_menu_segment7/main_menu_segment7.0B988.ia8"
mm7_texture_00B9C8: # 0x0700B9C8
.incbin "bin/main_menu_segment7/main_menu_segment7.0B9C8.ia8"
mm7_texture_00BA08: # 0x0700BA08
.incbin "bin/main_menu_segment7/main_menu_segment7.0BA08.ia8"
mm7_texture_00BA48: # 0x0700BA48
.incbin "bin/main_menu_segment7/main_menu_segment7.0BA48.ia8"
mm7_texture_00BA88: # 0x0700BA88
.incbin "bin/main_menu_segment7/main_menu_segment7.0BA88.ia8"
mm7_texture_00BAC8: # 0x0700BAC8
.incbin "bin/main_menu_segment7/main_menu_segment7.0BAC8.ia8"
mm7_texture_00BB08: # 0x0700BB08
.incbin "bin/main_menu_segment7/main_menu_segment7.0BB08.ia8"
mm7_texture_00BB48: # 0x0700BB48
.incbin "bin/main_menu_segment7/main_menu_segment7.0BB48.ia8"
mm7_texture_00BB88: # 0x0700BB88
.incbin "bin/main_menu_segment7/main_menu_segment7.0BB88.ia8"
mm7_texture_00BBC8: # 0x0700BBC8
.incbin "bin/main_menu_segment7/main_menu_segment7.0BBC8.ia8"
mm7_texture_00BC08: # 0x0700BC08
.incbin "bin/main_menu_segment7/main_menu_segment7.0BC08.ia8"
mm7_texture_00BC48: # 0x0700BC48
.incbin "bin/main_menu_segment7/main_menu_segment7.0BC48.ia8"
mm7_texture_00BC88: # 0x0700BC88
.incbin "bin/main_menu_segment7/main_menu_segment7.0BC88.ia8"
mm7_texture_00BCC8: # 0x0700BCC8
.incbin "bin/main_menu_segment7/main_menu_segment7.0BCC8.ia8"
mm7_texture_00BD08: # 0x0700BD08
.incbin "bin/main_menu_segment7/main_menu_segment7.0BD08.ia8"
mm7_texture_00BD48: # 0x0700BD48
.incbin "bin/main_menu_segment7/main_menu_segment7.0BD48.ia8"
mm7_texture_00BD88: # 0x0700BD88
.incbin "bin/main_menu_segment7/main_menu_segment7.0BD88.ia8"
mm7_texture_00BDC8: # 0x0700BDC8
.incbin "bin/main_menu_segment7/main_menu_segment7.0BDC8.ia8"
mm7_texture_00BE08: # 0x0700BE08
.incbin "bin/main_menu_segment7/main_menu_segment7.0BE08.ia8"
mm7_texture_00BE48: # 0x0700BE48
.incbin "bin/main_menu_segment7/main_menu_segment7.0BE48.ia8"
mm7_texture_00BE88: # 0x0700BE88
.incbin "bin/main_menu_segment7/main_menu_segment7.0BE88.ia8"
mm7_texture_00BEC8: # 0x0700BEC8
.incbin "bin/main_menu_segment7/main_menu_segment7.0BEC8.ia8"
mm7_texture_00BF08: # 0x0700BF08
.incbin "bin/main_menu_segment7/main_menu_segment7.0BF08.ia8"
mm7_texture_00BF48: # 0x0700BF48
.incbin "bin/main_menu_segment7/main_menu_segment7.0BF48.ia8"
mm7_texture_00BF88: # 0x0700BF88
.incbin "bin/main_menu_segment7/main_menu_segment7.0BF88.ia8"
mm7_texture_00BFC8: # 0x0700BFC8
.incbin "bin/main_menu_segment7/main_menu_segment7.0BFC8.ia8"
mm7_texture_00C008: # 0x0700C008
.incbin "bin/main_menu_segment7/main_menu_segment7.0C008.ia8"
mm7_texture_00C048: # 0x0700C048
.incbin "bin/main_menu_segment7/main_menu_segment7.0C048.ia8"
mm7_texture_00C088: # 0x0700C088
.incbin "bin/main_menu_segment7/main_menu_segment7.0C088.ia8"
mm7_texture_00C0C8: # 0x0700C0C8
.incbin "bin/main_menu_segment7/main_menu_segment7.0C0C8.ia8"
mm7_texture_00C108: # 0x0700C108
.incbin "bin/main_menu_segment7/main_menu_segment7.0C108.ia8"
mm7_texture_00C148: # 0x0700C148
.incbin "bin/main_menu_segment7/main_menu_segment7.0C148.ia8"
mm7_texture_00C188: # 0x0700C188
.incbin "bin/main_menu_segment7/main_menu_segment7.0C188.ia8"
mm7_texture_00C1C8: # 0x0700C1C8
.incbin "bin/main_menu_segment7/main_menu_segment7.0C1C8.ia8"
mm7_texture_00C208: # 0x0700C208
.incbin "bin/main_menu_segment7/main_menu_segment7.0C208.ia8"
mm7_texture_00C248: # 0x0700C248
.incbin "bin/main_menu_segment7/main_menu_segment7.0C248.ia8"
mm7_texture_00C288: # 0x0700C288
.incbin "bin/main_menu_segment7/main_menu_segment7.0C288.ia8"
mm7_texture_00C2C8: # 0x0700C2C8
.incbin "bin/main_menu_segment7/main_menu_segment7.0C2C8.ia8"
mm7_texture_00C308: # 0x0700C308
.incbin "bin/main_menu_segment7/main_menu_segment7.0C308.ia8"
mm7_texture_00C348: # 0x0700C348
.incbin "bin/main_menu_segment7/main_menu_segment7.0C348.ia8"
mm7_texture_00C388: # 0x0700C388
.incbin "bin/main_menu_segment7/main_menu_segment7.0C388.ia8"
mm7_texture_00C3C8: # 0x0700C3C8
.incbin "bin/main_menu_segment7/main_menu_segment7.0C3C8.ia8"
mm7_texture_00C408: # 0x0700C408
.incbin "bin/main_menu_segment7/main_menu_segment7.0C408.ia8"
mm7_texture_00C448: # 0x0700C448
.incbin "bin/main_menu_segment7/main_menu_segment7.0C448.ia8"
mm7_texture_00C488: # 0x0700C488
.incbin "bin/main_menu_segment7/main_menu_segment7.0C488.ia8"
mm7_texture_00C4C8: # 0x0700C4C8
.incbin "bin/main_menu_segment7/main_menu_segment7.0C4C8.ia8"
mm7_texture_00C508: # 0x0700C508
.incbin "bin/main_menu_segment7/main_menu_segment7.0C508.ia8"
mm7_texture_00C548: # 0x0700C548
.incbin "bin/main_menu_segment7/main_menu_segment7.0C548.ia8"
mm7_texture_00C588: # 0x0700C588
.incbin "bin/main_menu_segment7/main_menu_segment7.0C588.ia8"
mm7_texture_00C5C8: # 0x0700C5C8
.incbin "bin/main_menu_segment7/main_menu_segment7.0C5C8.ia8"
mm7_texture_00C608: # 0x0700C608
.incbin "bin/main_menu_segment7/main_menu_segment7.0C608.ia8"
mm7_texture_00C648: # 0x0700C648
.incbin "bin/main_menu_segment7/main_menu_segment7.0C648.ia8"
mm7_texture_00C688: # 0x0700C688
.incbin "bin/main_menu_segment7/main_menu_segment7.0C688.ia8"
mm7_texture_00C6C8: # 0x0700C6C8
.incbin "bin/main_menu_segment7/main_menu_segment7.0C6C8.ia8"
mm7_texture_00C708: # 0x0700C708
.incbin "bin/main_menu_segment7/main_menu_segment7.0C708.ia8"
mm7_texture_00C748: # 0x0700C748
.incbin "bin/main_menu_segment7/main_menu_segment7.0C748.ia8"
mm7_texture_00C788: # 0x0700C788
.incbin "bin/main_menu_segment7/main_menu_segment7.0C788.ia8"
mm7_texture_00C7C8: # 0x0700C7C8
.incbin "bin/main_menu_segment7/main_menu_segment7.0C7C8.ia8"
mm7_texture_00C808: # 0x0700C808
.incbin "bin/main_menu_segment7/main_menu_segment7.0C808.ia8"
mm7_texture_00C848: # 0x0700C848
.incbin "bin/main_menu_segment7/main_menu_segment7.0C848.ia8"
mm7_texture_00C888: # 0x0700C888
.incbin "bin/main_menu_segment7/main_menu_segment7.0C888.ia8"
mm7_texture_00C8C8: # 0x0700C8C8
.incbin "bin/main_menu_segment7/main_menu_segment7.0C8C8.ia8"
mm7_texture_00C908: # 0x0700C908
.incbin "bin/main_menu_segment7/main_menu_segment7.0C908.ia8"
mm7_texture_00C948: # 0x0700C948
.incbin "bin/main_menu_segment7/main_menu_segment7.0C948.ia8"
mm7_texture_00C988: # 0x0700C988
.incbin "bin/main_menu_segment7/main_menu_segment7.0C988.ia8"
mm7_texture_00C9C8: # 0x0700C9C8
.incbin "bin/main_menu_segment7/main_menu_segment7.0C9C8.ia8"
mm7_texture_00CA08: # 0x0700CA08
.incbin "bin/main_menu_segment7/main_menu_segment7.0CA08.ia8"
mm7_texture_00CA48: # 0x0700CA48
.incbin "bin/main_menu_segment7/main_menu_segment7.0CA48.ia8"
mm7_texture_00CA88: # 0x0700CA88
.incbin "bin/main_menu_segment7/main_menu_segment7.0CA88.ia8"
mm7_texture_00CAC8: # 0x0700CAC8
.incbin "bin/main_menu_segment7/main_menu_segment7.0CAC8.ia8"
mm7_texture_00CB08: # 0x0700CB08
.incbin "bin/main_menu_segment7/main_menu_segment7.0CB08.ia8"
mm7_texture_00CB48: # 0x0700CB48
.incbin "bin/main_menu_segment7/main_menu_segment7.0CB48.ia8"
mm7_texture_00CB88: # 0x0700CB88
.incbin "bin/main_menu_segment7/main_menu_segment7.0CB88.ia8"
mm7_texture_00CBC8: # 0x0700CBC8
.incbin "bin/main_menu_segment7/main_menu_segment7.0CBC8.ia8"
mm7_texture_00CC08: # 0x0700CC08
.incbin "bin/main_menu_segment7/main_menu_segment7.0CC08.ia8"
mm7_texture_00CC48: # 0x0700CC48
.incbin "bin/main_menu_segment7/main_menu_segment7.0CC48.ia8"
mm7_texture_00CC88: # 0x0700CC88
.incbin "bin/main_menu_segment7/main_menu_segment7.0CC88.ia8"
mm7_texture_00CCC8: # 0x0700CCC8
.incbin "bin/main_menu_segment7/main_menu_segment7.0CCC8.ia8"

glabel mm7_table_00CD08 # 0x0700CD08
.word mm7_texture_00AC48, mm7_texture_00AC88, mm7_texture_00ACC8, mm7_texture_00AD08
.word mm7_texture_00AD48, mm7_texture_00AD88, mm7_texture_00ADC8, mm7_texture_00AE08
.word mm7_texture_00AE48, mm7_texture_00AE88, mm7_texture_00CB08, mm7_texture_00CB48
.word mm7_texture_00CB88, mm7_texture_00CBC8, 0x00000000,         0x00000000
.word 0x00000000,         0x00000000,         0x00000000,         0x00000000
.word 0x00000000,         0x00000000,         0x00000000,         0x00000000
.word 0x00000000,         0x00000000,         0x00000000,         0x00000000
.word 0x00000000,         0x00000000,         0x00000000,         0x00000000
.word 0x00000000,         0x00000000,         0x00000000,         0x00000000
.word 0x00000000,         0x00000000,         0x00000000,         0x00000000
.word 0x00000000,         0x00000000,         0x00000000,         0x00000000
.word 0x00000000,         0x00000000,         0x00000000,         0x00000000
.word 0x00000000,         0x00000000,         0x00000000,         0x00000000
.word 0x00000000,         0x00000000,         0x00000000,         0x00000000
.word 0x00000000,         0x00000000,         0x00000000,         0x00000000
.word 0x00000000,         0x00000000,         0x00000000,         0x00000000
.word mm7_texture_00AEC8, mm7_texture_00AF08, mm7_texture_00AF48, mm7_texture_00AF88
.word mm7_texture_00AFC8, mm7_texture_00B008, mm7_texture_00B048, mm7_texture_00B088
.word mm7_texture_00B0C8, mm7_texture_00B108, mm7_texture_00B148, mm7_texture_00B188
.word mm7_texture_00B1C8, mm7_texture_00B208, mm7_texture_00B248, mm7_texture_00B288
.word mm7_texture_00B2C8, mm7_texture_00B308, mm7_texture_00B348, mm7_texture_00B388
.word mm7_texture_00B3C8, mm7_texture_00B408, mm7_texture_00B448, mm7_texture_00B488
.word mm7_texture_00B4C8, mm7_texture_00B508, mm7_texture_00B548, mm7_texture_00B588
.word mm7_texture_00B5C8, mm7_texture_00B608, mm7_texture_00B648, mm7_texture_00B688
.word mm7_texture_00B6C8, mm7_texture_00B708, mm7_texture_00B748, mm7_texture_00B788
.word mm7_texture_00B7C8, mm7_texture_00B808, mm7_texture_00B848, mm7_texture_00B888
.word mm7_texture_00B8C8, mm7_texture_00B908, mm7_texture_00B948, mm7_texture_00B988
.word mm7_texture_00B9C8, mm7_texture_00BA08, 0x00000000,         0x00000000
.word mm7_texture_00BD48, mm7_texture_00BD88, mm7_texture_00BDC8, mm7_texture_00BE08
.word mm7_texture_00BE48, mm7_texture_00BE88, mm7_texture_00BEC8, mm7_texture_00BF08
.word mm7_texture_00BF48, mm7_texture_00BF88, mm7_texture_00BFC8, mm7_texture_00C008
.word mm7_texture_00C048, mm7_texture_00C088, mm7_texture_00C0C8, mm7_texture_00C108
.word mm7_texture_00C148, mm7_texture_00C188, mm7_texture_00C1C8, mm7_texture_00C208
.word mm7_texture_00C248, mm7_texture_00C288, mm7_texture_00C2C8, mm7_texture_00C308
.word mm7_texture_00C348, mm7_texture_00C388, mm7_texture_00C3C8, mm7_texture_00C408
.word mm7_texture_00C448, mm7_texture_00C488, mm7_texture_00C4C8, mm7_texture_00C508
.word mm7_texture_00C548, mm7_texture_00C588, mm7_texture_00C5C8, mm7_texture_00C608
.word mm7_texture_00C648, mm7_texture_00C688, mm7_texture_00C6C8, mm7_texture_00C708
.word mm7_texture_00C748, mm7_texture_00C788, mm7_texture_00C7C8, mm7_texture_00C808
.word mm7_texture_00C848, mm7_texture_00C888, 0x00000000,         mm7_texture_00BD08
.word mm7_texture_00BB08, mm7_texture_00BC48, mm7_texture_00BB88, mm7_texture_00BBC8
.word mm7_texture_00BC08, mm7_texture_00BA48, mm7_texture_00BA88, mm7_texture_00BAC8
.word mm7_texture_00BB48, 0x00000000,         0x00000000,         0x00000000
.word 0x00000000,         0x00000000,         0x00000000,         0x00000000
.word 0x00000000,         0x00000000,         0x00000000,         0x00000000
.word 0x00000000,         0x00000000,         0x00000000,         0x00000000
.word 0x00000000,         0x00000000,         0x00000000,         0x00000000
.word 0x00000000,         0x00000000,         0x00000000,         0x00000000
.word 0x00000000,         0x00000000,         0x00000000,         0x00000000
.word 0x00000000,         0x00000000,         0x00000000,         0x00000000
.word 0x00000000,         0x00000000,         0x00000000,         0x00000000
.word 0x00000000,         0x00000000,         0x00000000,         0x00000000
.word mm7_texture_00C988, mm7_texture_00CAC8, mm7_texture_00CA08, mm7_texture_00CA48
.word mm7_texture_00CA88, mm7_texture_00C8C8, mm7_texture_00C908, mm7_texture_00C948
.word mm7_texture_00C9C8, 0x00000000,         0x00000000,         0x00000000
.word 0x00000000,         0x00000000,         0x00000000,         0x00000000
.word 0x00000000,         0x00000000,         0x00000000,         0x00000000
.word 0x00000000,         0x00000000,         0x00000000,         0x00000000
.word 0x00000000,         0x00000000,         0x00000000,         0x00000000
.word 0x00000000,         0x00000000,         0x00000000,         0x00000000
.word mm7_texture_00BCC8, mm7_texture_00BC88, mm7_texture_00CCC8, 0x00000000
.word 0x00000000,         0x00000000,         0x00000000,         0x00000000
.word 0x00000000,         mm7_texture_00CC08, mm7_texture_00CC48, mm7_texture_00CC88
.word 0x00000000,         0x00000000,         0x00000000,         0x00000000

glabel mm7_f3d_00D108 # 0x0700D108
.word 0xE7000000, 0x00000000
.word 0xBA001301, 0x00000000
.word 0xFC129A25, 0xFF37FFFF
.word 0xFB000000, 0xFFFFFFFF
.word 0xB900031D, 0x005041C8
.word 0xBA000C02, 0x00000000
.word 0xF5680000, 0x07000000
.word 0xE8000000, 0x00000000
.word 0xF5680200, 0x0008C230
.word 0xF2000000, 0x0001C01C
.word 0xB8000000, 0x00000000

glabel mm7_f3d_00D160 # 0x0700D160
.word 0xE7000000, 0x00000000
.word 0xBA001301, 0x00080000
.word 0xB900031D, 0x00552078
.word 0xFCFFFFFF, 0xFFFE793C
.word 0xFB000000, 0xFFFFFFFF
.word 0xBB000000, 0xFFFFFFFF
.word 0xBA000C02, 0x00002000
.word 0xB8000000, 0x00000000
.word 0x00000000, 0x00000000

mm7_texture_00D1A8: # 0x0700D1A8
.incbin "bin/main_menu_segment7/main_menu_segment7.0D1A8.rgba16"

mm7_texture_00E1A8: # 0x0700E1A8
.incbin "bin/main_menu_segment7/main_menu_segment7.0E1A8.rgba16"

mm7_vertices_00F1A8: # 0x0700F1A8
vertex  -32,    0,    0,    0, 1984,  0x00, 0x00, 0x7F, 0x00
vertex   32,    0,    0, 4032, 1984,  0x00, 0x00, 0x7F, 0x00
vertex   32,   32,    0, 4032,    0,  0x00, 0x00, 0x7F, 0x00
vertex  -32,   32,    0,    0,    0,  0x00, 0x00, 0x7F, 0x00

mm7_vertices_00F1E8: # 0x0700F1E8
vertex  -32,  -32,    0,    0, 1984,  0x00, 0x00, 0x7F, 0x00
vertex   32,  -32,    0, 4032, 1984,  0x00, 0x00, 0x7F, 0x00
vertex   32,    0,    0, 4032,    0,  0x00, 0x00, 0x7F, 0x00
vertex  -32,    0,    0,    0,    0,  0x00, 0x00, 0x7F, 0x00

glabel mm7_f3d_00F228 # 0x0700F228
.word 0xE7000000, 0x00000000
.word 0xFCFFFFFF, 0xFFFCF279
.word 0xBB000001, 0x80008000
.word 0xB900031D, 0x00553048
.word 0xFD100000, mm7_texture_00D1A8
.word 0xF5100000, 0x07000000
.word 0xE6000000, 0x00000000
.word 0xF3000000, 0x077FF080
.word 0xF5102000, 0x00000000
.word 0xF2000000, 0x000FC07C
.word 0x04300040, mm7_vertices_00F1A8
.word 0xBF000000, 0x00000A14
.word 0xBF000000, 0x0000141E
.word 0xFD100000, mm7_texture_00E1A8
.word 0xF5100000, 0x07000000
.word 0xE6000000, 0x00000000
.word 0xF3000000, 0x077FF080
.word 0xF5102000, 0x00000000
.word 0xF2000000, 0x000FC07C
.word 0x04300040, mm7_vertices_00F1E8
.word 0xBF000000, 0x00000A14
.word 0xBF000000, 0x0000141E
.word 0xB900031D, 0x00552078
.word 0xBB000000, 0x00010001
.word 0xFCFFFFFF, 0xFFFE793C
.word 0xB8000000, 0x00000000

glabel mm7_collision_00F2F8 # 0x0700F2F8
.incbin "bin/main_menu_segment7/main_menu_segment7.0F2F8.collision"
