# music sequence table
music_sequence_table_header:
# region 745F80
.hword 3, 34
music_sequence_table:
.word (seq_00 - music_sequence_table_header), (seq_00_end - seq_00) # 0x00120, 0x3200
.word (seq_01 - music_sequence_table_header), (seq_01_end - seq_01) # 0x03320, 0x0280
.word (seq_02 - music_sequence_table_header), (seq_02_end - seq_02) # 0x035A0, 0x2060
.word (seq_03 - music_sequence_table_header), (seq_03_end - seq_03) # 0x05600, 0x1410
.word (seq_04 - music_sequence_table_header), (seq_04_end - seq_04) # 0x06A10, 0x09D0
.word (seq_05 - music_sequence_table_header), (seq_05_end - seq_05) # 0x073E0, 0x12D0
.word (seq_06 - music_sequence_table_header), (seq_06_end - seq_06) # 0x086B0, 0x09A0
.word (seq_07 - music_sequence_table_header), (seq_07_end - seq_07) # 0x09050, 0x0D70
.word (seq_08 - music_sequence_table_header), (seq_08_end - seq_08) # 0x09DC0, 0x1FE0
.word (seq_09 - music_sequence_table_header), (seq_09_end - seq_09) # 0x0BDA0, 0x1D20
.word (seq_0A - music_sequence_table_header), (seq_0A_end - seq_0A) # 0x0DAC0, 0x1640
.word (seq_0B - music_sequence_table_header), (seq_0B_end - seq_0B) # 0x0F100, 0x0580
.word (seq_0C - music_sequence_table_header), (seq_0C_end - seq_0C) # 0x0F680, 0x1330
.word (seq_0D - music_sequence_table_header), (seq_0D_end - seq_0D) # 0x109B0, 0x0090
.word (seq_0E - music_sequence_table_header), (seq_0E_end - seq_0E) # 0x10A40, 0x0C50
.word (seq_0F - music_sequence_table_header), (seq_0F_end - seq_0F) # 0x11690, 0x0AF0
.word (seq_10 - music_sequence_table_header), (seq_10_end - seq_10) # 0x12180, 0x0240
.word (seq_11 - music_sequence_table_header), (seq_11_end - seq_11) # 0x123C0, 0x12A0
.word (seq_12 - music_sequence_table_header), (seq_12_end - seq_12) # 0x13660, 0x0120
.word (seq_13 - music_sequence_table_header), (seq_13_end - seq_13) # 0x13780, 0x0680
.word (seq_14 - music_sequence_table_header), (seq_14_end - seq_14) # 0x13E00, 0x00D0
.word (seq_15 - music_sequence_table_header), (seq_15_end - seq_15) # 0x13ED0, 0x0290
.word (seq_16 - music_sequence_table_header), (seq_16_end - seq_16) # 0x14160, 0x0D80
.word (seq_17 - music_sequence_table_header), (seq_17_end - seq_17) # 0x14EE0, 0x02B0
.word (seq_18 - music_sequence_table_header), (seq_18_end - seq_18) # 0x15190, 0x0700
.word (seq_19 - music_sequence_table_header), (seq_19_end - seq_19) # 0x15890, 0x0DD0
.word (seq_1A - music_sequence_table_header), (seq_1A_end - seq_1A) # 0x16660, 0x3810
.word (seq_1B - music_sequence_table_header), (seq_1B_end - seq_1B) # 0x19E70, 0x00E0
.word (seq_1C - music_sequence_table_header), (seq_1C_end - seq_1C) # 0x19F50, 0x00E0
.word (seq_1D - music_sequence_table_header), (seq_1D_end - seq_1D) # 0x1A030, 0x01C0
.word (seq_1E - music_sequence_table_header), (seq_1E_end - seq_1E) # 0x1A1F0, 0x06F0
.word (seq_1F - music_sequence_table_header), (seq_1F_end - seq_1F) # 0x1A8E0, 0x0820
.word (seq_20 - music_sequence_table_header), (seq_20_end - seq_20) # 0x1B100, 0x0770
.word (seq_21 - music_sequence_table_header), (seq_21_end - seq_21) # 0x1B870, 0x0320
music_sequence_table_end:

.align 4, 0x00

seq_00:
.incbin "music/seq_00.m64"
seq_00_end:

seq_01:
.incbin "music/seq_01.m64"
seq_01_end:

seq_02:
.incbin "music/seq_02.m64"
seq_02_end:

seq_03:
.incbin "music/seq_03.m64"
seq_03_end:

seq_04:
.incbin "music/seq_04.m64"
seq_04_end:

seq_05:
.incbin "music/seq_05.m64"
seq_05_end:

seq_06:
.incbin "music/seq_06.m64"
seq_06_end:

seq_07:
.incbin "music/seq_07.m64"
seq_07_end:

seq_08:
.incbin "music/seq_08.m64"
seq_08_end:

seq_09:
.incbin "music/seq_09.m64"
seq_09_end:

seq_0A:
.incbin "music/seq_0A.m64"
seq_0A_end:

seq_0B:
.incbin "music/seq_0B.m64"
seq_0B_end:

seq_0C:
.incbin "music/seq_0C.m64"
seq_0C_end:

seq_0D:
.incbin "music/seq_0D.m64"
seq_0D_end:

seq_0E:
.incbin "music/seq_0E.m64"
seq_0E_end:

seq_0F:
.incbin "music/seq_0F.m64"
seq_0F_end:

seq_10:
.incbin "music/seq_10.m64"
seq_10_end:

seq_11:
.incbin "music/seq_11.m64"
seq_11_end:

seq_12:
.incbin "music/seq_12.m64"
seq_12_end:

seq_13:
.incbin "music/seq_13.m64"
seq_13_end:

seq_14:
.incbin "music/seq_14.m64"
seq_14_end:

seq_15:
.incbin "music/seq_15.m64"
seq_15_end:

seq_16:
.incbin "music/seq_16.m64"
seq_16_end:

seq_17:
.incbin "music/seq_17.m64"
seq_17_end:

seq_18:
.incbin "music/seq_18.m64"
seq_18_end:

seq_19:
.incbin "music/seq_19.m64"
seq_19_end:

seq_1A:
.incbin "music/seq_1A.m64"
seq_1A_end:

seq_1B:
.incbin "music/seq_1B.m64"
seq_1B_end:

seq_1C:
.incbin "music/seq_1C.m64"
seq_1C_end:

seq_1D:
.incbin "music/seq_1D.m64"
seq_1D_end:

seq_1E:
.incbin "music/seq_1E.m64"
seq_1E_end:

seq_1F:
.incbin "music/seq_1F.m64"
seq_1F_end:

seq_20:
.incbin "music/seq_20.m64"
seq_20_end:

seq_21:
.incbin "music/seq_21.m64"
seq_21_end:
# Unknown region 761B10-761B40 [30]
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00


instrument_sets:
.hword instrument_set_00 - instrument_sets # 0x0044
.hword instrument_set_01 - instrument_sets # 0x0050
.hword instrument_set_02 - instrument_sets # 0x0052
.hword instrument_set_03 - instrument_sets # 0x0054
.hword instrument_set_04 - instrument_sets # 0x0056
.hword instrument_set_05 - instrument_sets # 0x0058
.hword instrument_set_06 - instrument_sets # 0x005A
.hword instrument_set_07 - instrument_sets # 0x005C
.hword instrument_set_08 - instrument_sets # 0x005E
.hword instrument_set_09 - instrument_sets # 0x0060
.hword instrument_set_0A - instrument_sets # 0x0062
.hword instrument_set_0B - instrument_sets # 0x0065
.hword instrument_set_0C - instrument_sets # 0x0067
.hword instrument_set_0D - instrument_sets # 0x0069
.hword instrument_set_0E - instrument_sets # 0x006B
.hword instrument_set_0F - instrument_sets # 0x006D
.hword instrument_set_10 - instrument_sets # 0x006F
.hword instrument_set_11 - instrument_sets # 0x0071
.hword instrument_set_12 - instrument_sets # 0x0073
.hword instrument_set_13 - instrument_sets # 0x0075
.hword instrument_set_14 - instrument_sets # 0x0077
.hword instrument_set_15 - instrument_sets # 0x0079
.hword instrument_set_16 - instrument_sets # 0x007B
.hword instrument_set_17 - instrument_sets # 0x007D
.hword instrument_set_18 - instrument_sets # 0x007F
.hword instrument_set_19 - instrument_sets # 0x0081
.hword instrument_set_1A - instrument_sets # 0x0083
.hword instrument_set_1B - instrument_sets # 0x0085
.hword instrument_set_1C - instrument_sets # 0x0087
.hword instrument_set_1D - instrument_sets # 0x0089
.hword instrument_set_1E - instrument_sets # 0x008B
.hword instrument_set_1F - instrument_sets # 0x008D
.hword instrument_set_20 - instrument_sets # 0x008F
.hword instrument_set_21 - instrument_sets # 0x0091

instrument_set_00:
.byte 0x0B, 0x0A, 0x09, 0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00
instrument_set_01:
.byte 0x01, 0x22
instrument_set_02:
.byte 0x01, 0x11
instrument_set_03:
.byte 0x01, 0x22
instrument_set_04:
.byte 0x01, 0x0E
instrument_set_05:
.byte 0x01, 0x13
instrument_set_06:
.byte 0x01, 0x0F
instrument_set_07:
.byte 0x01, 0x12
instrument_set_08:
.byte 0x01, 0x0B
instrument_set_09:
.byte 0x01, 0x0D
instrument_set_0A:
.byte 0x02, 0x21, 0x10
instrument_set_0B:
.byte 0x01, 0x14
instrument_set_0C:
.byte 0x01, 0x15
instrument_set_0D:
.byte 0x01, 0x16
instrument_set_0E:
.byte 0x01, 0x17
instrument_set_0F:
.byte 0x01, 0x18
instrument_set_10:
.byte 0x01, 0x12
instrument_set_11:
.byte 0x01, 0x19
instrument_set_12:
.byte 0x01, 0x1F
instrument_set_13:
.byte 0x01, 0x21
instrument_set_14:
.byte 0x01, 0x1A
instrument_set_15:
.byte 0x01, 0x0E
instrument_set_16:
.byte 0x01, 0x1B
instrument_set_17:
.byte 0x01, 0x1A
instrument_set_18:
.byte 0x01, 0x1C
instrument_set_19:
.byte 0x01, 0x1D
instrument_set_1A:
.byte 0x01, 0x25
instrument_set_1B:
.byte 0x01, 0x14
instrument_set_1C:
.byte 0x01, 0x20
instrument_set_1D:
.byte 0x01, 0x1E
instrument_set_1E:
.byte 0x01, 0x1B
instrument_set_1F:
.byte 0x01, 0x1A
instrument_set_20:
.byte 0x01, 0x23
instrument_set_21:
.byte 0x01, 0x24
instrument_sets_end:

