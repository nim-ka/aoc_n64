.include "macros.inc"

.section .data

.macro seq_table name
    .word (\name - gMusicData), (\name\()_end - \name)
.endm

glabel gMusicData # region 745F80 (US: 7B0860)
.hword 3 # current segment
.hword (music_sequence_table_end - music_sequence_table) / 8 # number of entries

music_sequence_table:
seq_table seq_00
seq_table seq_01
seq_table seq_02
seq_table seq_03
seq_table seq_04
seq_table seq_05
seq_table seq_06
seq_table seq_07
seq_table seq_08
seq_table seq_09
seq_table seq_0A
seq_table seq_0B
seq_table seq_0C
seq_table seq_0D
seq_table seq_0E
seq_table seq_0F
seq_table seq_10
seq_table seq_11
seq_table seq_12
seq_table seq_13
seq_table seq_14
seq_table seq_15
seq_table seq_16
seq_table seq_17
seq_table seq_18
seq_table seq_19
seq_table seq_1A
seq_table seq_1B
seq_table seq_1C
seq_table seq_1D
seq_table seq_1E
seq_table seq_1F
seq_table seq_20
seq_table seq_21
.ifndef VERSION_JP
seq_table seq_22
.endif
music_sequence_table_end:

.ifdef VERSION_JP
.word 0, 0, 0
.else
.word 0
.endif

.macro sequence name
\name:
.ifdef VERSION_JP
.incbin "assets/music/jp/\name\().m64"
.endif
.ifndef VERSION_JP
.incbin "assets/music/us/\name\().m64"
.endif
\name\()_end:
.endm

sequence seq_00
sequence seq_01
sequence seq_02
sequence seq_03
sequence seq_04
sequence seq_05
sequence seq_06
sequence seq_07
sequence seq_08
sequence seq_09
sequence seq_0A
sequence seq_0B
sequence seq_0C
sequence seq_0D
sequence seq_0E
sequence seq_0F
sequence seq_10
sequence seq_11
sequence seq_12
sequence seq_13
sequence seq_14
sequence seq_15
sequence seq_16
sequence seq_17
sequence seq_18
sequence seq_19
sequence seq_1A
sequence seq_1B
sequence seq_1C
sequence seq_1D
sequence seq_1E
sequence seq_1F
sequence seq_20
sequence seq_21
.ifndef VERSION_JP
sequence seq_22
.endif

.ifdef VERSION_JP # for some reason only the JP version has this padding.
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.endif
