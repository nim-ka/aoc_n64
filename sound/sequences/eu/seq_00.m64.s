.include "seq_macros.inc"
.section .rodata
.align 0
sequence_start:

seq_setmutebhv 0x60
seq_setmutescale 0
seq_setvol 127
seq_settempo 120
seq_initchannels 0x3ff
seq_startchannel 0, .chan_2F
seq_startchannel 1, .chan_9C
seq_startchannel 2, .chan_41
seq_startchannel 3, .chan_53
seq_startchannel 4, .chan_B0
seq_startchannel 5, .chan_65
seq_startchannel 6, .chan_C4
seq_startchannel 7, .chan_F8
seq_startchannel 8, .chan_53
seq_startchannel 9, .chan_65
.seq_29:
seq_delay 0x4e20
seq_jump .seq_29

.chan_2F:
chan_largenoteson
chan_setinstr 0
chan_setpanmix 127
chan_setnotepriority 14
chan_setval 0
chan_iowriteval 5
chan_stereoheadseteffects 1
chan_setdyntable .table_154
chan_jump .chan_77

.chan_41:
chan_largenoteson
chan_setinstr 0
chan_setpanmix 127
chan_setnotepriority 14
chan_setval 0
chan_iowriteval 5
chan_stereoheadseteffects 1
chan_setdyntable .table_BBC
chan_jump .chan_77

.chan_53:
chan_largenoteson
chan_setinstr 0
chan_setpanmix 127
chan_setnotepriority 14
chan_setval 0
chan_iowriteval 5
chan_stereoheadseteffects 1
chan_setdyntable .table_FA5
chan_jump .chan_77

.chan_65:
chan_largenoteson
chan_setinstr 0
chan_setpanmix 127
chan_setnotepriority 14
chan_setval 0
chan_iowriteval 5
chan_stereoheadseteffects 1
chan_setdyntable .table_1E67
chan_jump .chan_77
.chan_77:
chan_delay1
chan_ioreadval 0
chan_bltz .chan_77
.chan_7C:
chan_freelayer 0
chan_freelayer 1
chan_freelayer 2
chan_setval 0
chan_iowriteval 5
chan_ioreadval 4
chan_dyncall
.chan_84:
chan_delay1
chan_ioreadval 0
chan_bltz .chan_8F
chan_beqz .chan_96
chan_jump .chan_7C
.chan_8F:
chan_testlayerfinished 0
chan_beqz .chan_84
chan_jump .chan_77
.chan_96:
chan_freelayer 0
chan_freelayer 1
chan_freelayer 2
chan_jump .chan_77

.chan_9C:
chan_largenoteson
chan_setinstr 0
chan_setpanmix 127
chan_setnotepriority 14
chan_setval 0
chan_iowriteval 5
chan_setmutebhv 0x20
chan_stereoheadseteffects 1
chan_setdyntable .table_8FE
chan_jump .chan_D8

.chan_B0:
chan_largenoteson
chan_setinstr 0
chan_setpanmix 127
chan_setnotepriority 14
chan_setval 0
chan_iowriteval 5
chan_setmutebhv 0x20
chan_stereoheadseteffects 1
chan_setdyntable .table_1B0C
chan_jump .chan_D8

.chan_C4:
chan_largenoteson
chan_setinstr 0
chan_setpanmix 127
chan_setnotepriority 14
chan_setval 0
chan_iowriteval 5
chan_setmutebhv 0x20
chan_stereoheadseteffects 1
chan_setdyntable .table_298A
chan_jump .chan_D8
.chan_D8:
chan_delay1
chan_ioreadval 0
chan_bltz .chan_D8
.chan_DD:
chan_freelayer 0
chan_freelayer 1
chan_freelayer 2
chan_setvolscale 127
chan_setval 0
chan_iowriteval 5
chan_ioreadval 4
chan_dyncall
.chan_E7:
chan_delay1
chan_ioreadval 0
chan_bltz .chan_E7
chan_beqz .chan_F2
chan_jump .chan_DD
.chan_F2:
chan_freelayer 0
chan_freelayer 1
chan_freelayer 2
chan_jump .chan_D8

.chan_F8:
chan_largenoteson
chan_setinstr 0
chan_setnotepriority 14
chan_setval 0
chan_iowriteval 5
chan_stereoheadseteffects 1
chan_setdyntable .table_2B36
.chan_105:
chan_delay1
chan_ioreadval 0
chan_bltz .chan_105
.chan_10A:
chan_freelayer 0
chan_freelayer 1
chan_freelayer 2
chan_setval 0
chan_iowriteval 5
chan_setreverb 0
chan_setpan 64
chan_setpanmix 127
chan_ioreadval 4
chan_dyncall
.chan_118:
chan_delay1
chan_ioreadval 0
chan_bltz .chan_124
chan_beqz .chan_12C
chan_unreservenotes
chan_jump .chan_10A
.chan_124:
chan_testlayerfinished 0
chan_beqz .chan_118
chan_unreservenotes
chan_jump .chan_105
.chan_12C:
chan_freelayer 0
chan_freelayer 1
chan_freelayer 2
chan_unreservenotes
chan_jump .chan_105

.chan_fn_133:
chan_writeseq_nextinstr 0, 1
chan_loop 20
chan_delay1
chan_ioreadval 0
chan_iowriteval 1
chan_bgez .chan_141
chan_loopend
chan_end
.chan_141:
chan_setpanmix 127
chan_setvolscale 127
chan_setvibratoextent 0
chan_ioreadval 1
chan_iowriteval 0
chan_break
chan_break
chan_end

.chan_fn_14C:
chan_writeseq_nextinstr 0, 1
chan_setreverb 10
chan_iowriteval 5
chan_end

.table_154:
sound_ref .chan_234
sound_ref .chan_243
sound_ref .chan_252
sound_ref .chan_261
sound_ref .chan_270
sound_ref .chan_27F
sound_ref .chan_28E
sound_ref .chan_29D
sound_ref .chan_2AE
sound_ref .chan_2BD
sound_ref .chan_2CC
sound_ref .chan_2DB
sound_ref .chan_2EA
sound_ref .chan_2F9
sound_ref .chan_308
sound_ref .chan_317
sound_ref .chan_328
sound_ref .chan_334
sound_ref .chan_340
sound_ref .chan_34C
sound_ref .chan_358
sound_ref .chan_364
sound_ref .chan_370
sound_ref .chan_37C
sound_ref .chan_388
sound_ref .chan_397
sound_ref .chan_3A6
sound_ref .chan_3B5
sound_ref .chan_3C4
sound_ref .chan_3D3
sound_ref .chan_3E2
sound_ref .chan_3F1
sound_ref .chan_402
sound_ref .chan_40E
sound_ref .chan_41A
sound_ref .chan_426
sound_ref .chan_432
sound_ref .chan_43E
sound_ref .chan_44A
sound_ref .chan_456
sound_ref .chan_462
sound_ref .chan_471
sound_ref .chan_480
sound_ref .chan_490
sound_ref .chan_49F
sound_ref .chan_4B1
sound_ref .chan_4CD
sound_ref .chan_4DD
sound_ref .chan_4ED
sound_ref .chan_4F9
sound_ref .chan_505
sound_ref .chan_51A
sound_ref .chan_52A
sound_ref .chan_536
sound_ref .chan_548
sound_ref .chan_554
sound_ref .chan_554
sound_ref .chan_554
sound_ref .chan_566
sound_ref .chan_579
sound_ref .chan_58A
sound_ref .chan_599
sound_ref .chan_5AB
sound_ref .chan_5BD
sound_ref .chan_5C9
sound_ref .chan_5DB
sound_ref .chan_5F1
sound_ref .chan_600
sound_ref .chan_60C
sound_ref .chan_659
sound_ref .chan_66C
sound_ref .chan_6B1
sound_ref .chan_6D1
sound_ref .chan_6D1
sound_ref .chan_6D1
sound_ref .chan_6D1
sound_ref .chan_6D1
sound_ref .chan_6E4
sound_ref .chan_6F3
sound_ref .chan_6F3
sound_ref .chan_702
sound_ref .chan_714
sound_ref .chan_726
sound_ref .chan_739
sound_ref .chan_74B
sound_ref .chan_75E
sound_ref .chan_76E
sound_ref .chan_78A
sound_ref .chan_7AD
sound_ref .chan_7CD
sound_ref .chan_7F5
sound_ref .chan_809
sound_ref .chan_818
sound_ref .chan_830
sound_ref .chan_853
sound_ref .chan_86B
sound_ref .chan_87E
sound_ref .chan_88E
sound_ref .chan_89E
sound_ref .chan_8AE
sound_ref .chan_8BE
sound_ref .chan_8CE
sound_ref .chan_8DE
sound_ref .chan_8EE
sound_ref .chan_234
sound_ref .chan_234
sound_ref .chan_234
sound_ref .chan_234
sound_ref .chan_234
sound_ref .chan_234
sound_ref .chan_234
sound_ref .chan_234

.chan_234:
chan_setbank 1
chan_setinstr 0
chan_setlayer 0, .layer_23C
chan_end

.layer_23C:
layer_note1 41, 0xc, 117
layer_note1 46, 0x18, 117
layer_end

.chan_243:
chan_setbank 1
chan_setinstr 1
chan_setlayer 0, .layer_24B
chan_end

.layer_24B:
layer_note1 41, 0xc, 120
layer_note1 50, 0x18, 120
layer_end

.chan_252:
chan_setbank 2
chan_setinstr 1
chan_setlayer 0, .layer_25A
chan_end

.layer_25A:
layer_note1 41, 0x6, 80
layer_note1 50, 0x18, 80
layer_end

.chan_261:
chan_setbank 1
chan_setinstr 3
chan_setlayer 0, .layer_269
chan_end

.layer_269:
layer_note1 41, 0xc, 127
layer_note1 50, 0x18, 127
layer_end

.chan_270:
chan_setbank 1
chan_setinstr 4
chan_setlayer 0, .layer_278
chan_end

.layer_278:
layer_note1 41, 0xc, 90
layer_note1 50, 0x18, 90
layer_end

.chan_27F:
chan_setbank 1
chan_setinstr 5
chan_setlayer 0, .layer_287
chan_end

.layer_287:
layer_note1 41, 0xc, 80
layer_note1 50, 0x18, 80
layer_end

.chan_28E:
chan_setbank 1
chan_setinstr 6
chan_setlayer 0, .layer_296
chan_end

.layer_296:
layer_note1 29, 0xc, 127
layer_note1 38, 0x18, 127
layer_end

.chan_29D:
chan_setbank 1
chan_setinstr 8
chan_setlayer 0, .layer_2A5
chan_end

.layer_2A5:
layer_note0 34, 0xc, 100, 127
layer_note0 43, 0x24, 100, 127
layer_end

.chan_2AE:
chan_setbank 1
chan_setinstr 0
chan_setlayer 0, .layer_2B6
chan_end

.layer_2B6:
layer_note1 46, 0xc, 117
layer_note1 41, 0x18, 117
layer_end

.chan_2BD:
chan_setbank 1
chan_setinstr 1
chan_setlayer 0, .layer_2C5
chan_end

.layer_2C5:
layer_note1 50, 0xc, 120
layer_note1 41, 0x18, 120
layer_end

.chan_2CC:
chan_setbank 2
chan_setinstr 1
chan_setlayer 0, .layer_2D4
chan_end

.layer_2D4:
layer_note1 50, 0xc, 80
layer_note1 41, 0x18, 80
layer_end

.chan_2DB:
chan_setbank 1
chan_setinstr 3
chan_setlayer 0, .layer_2E3
chan_end

.layer_2E3:
layer_note1 50, 0xc, 127
layer_note1 41, 0x18, 127
layer_end

.chan_2EA:
chan_setbank 1
chan_setinstr 4
chan_setlayer 0, .layer_2F2
chan_end

.layer_2F2:
layer_note1 50, 0xc, 90
layer_note1 41, 0x18, 90
layer_end

.chan_2F9:
chan_setbank 1
chan_setinstr 5
chan_setlayer 0, .layer_301
chan_end

.layer_301:
layer_note1 50, 0xc, 80
layer_note1 41, 0x18, 80
layer_end

.chan_308:
chan_setbank 1
chan_setinstr 6
chan_setlayer 0, .layer_310
chan_end

.layer_310:
layer_note1 38, 0xc, 127
layer_note1 29, 0x18, 127
layer_end

.chan_317:
chan_setbank 1
chan_setinstr 8
chan_setlayer 0, .layer_31F
chan_end

.layer_31F:
layer_note0 43, 0xc, 100, 127
layer_note0 34, 0x24, 100, 127
layer_end

.chan_328:
chan_setbank 1
chan_setinstr 0
chan_setlayer 0, .layer_330
chan_end

.layer_330:
layer_note1 39, 0x18, 85
layer_end

.chan_334:
chan_setbank 1
chan_setinstr 1
chan_setlayer 0, .layer_33C
chan_end

.layer_33C:
layer_note1 39, 0x18, 100
layer_end

.chan_340:
chan_setbank 2
chan_setinstr 1
chan_setlayer 0, .layer_348
chan_end

.layer_348:
layer_note1 43, 0x18, 63
layer_end

.chan_34C:
chan_setbank 1
chan_setinstr 3
chan_setlayer 0, .layer_354
chan_end

.layer_354:
layer_note1 39, 0x18, 77
layer_end

.chan_358:
chan_setbank 1
chan_setinstr 4
chan_setlayer 0, .layer_360
chan_end

.layer_360:
layer_note1 39, 0x18, 70
layer_end

.chan_364:
chan_setbank 1
chan_setinstr 5
chan_setlayer 0, .layer_36C
chan_end

.layer_36C:
layer_note1 39, 0x18, 68
layer_end

.chan_370:
chan_setbank 1
chan_setinstr 6
chan_setlayer 0, .layer_378
chan_end

.layer_378:
layer_note1 39, 0x18, 100
layer_end

.chan_37C:
chan_setbank 1
chan_setinstr 8
chan_setlayer 0, .layer_384
chan_end

.layer_384:
layer_note1 39, 0x18, 70
layer_end

.chan_388:
chan_setbank 1
chan_setinstr 0
chan_setlayer 0, .layer_390
chan_end

.layer_390:
layer_note1 17, 0xc, 117
layer_note1 19, 0x18, 117
layer_end

.chan_397:
chan_setbank 1
chan_setinstr 1
chan_setlayer 0, .layer_39F
chan_end

.layer_39F:
layer_note1 29, 0xc, 120
layer_note1 31, 0x18, 120
layer_end

.chan_3A6:
chan_setbank 2
chan_setinstr 1
chan_setlayer 0, .layer_3AE
chan_end

.layer_3AE:
layer_note1 34, 0xc, 80
layer_note1 39, 0x18, 80
layer_end

.chan_3B5:
chan_setbank 1
chan_setinstr 3
chan_setlayer 0, .layer_3BD
chan_end

.layer_3BD:
layer_note1 29, 0xc, 115
layer_note1 31, 0xc, 115
layer_end

.chan_3C4:
chan_setbank 1
chan_setinstr 4
chan_setlayer 0, .layer_3CC
chan_end

.layer_3CC:
layer_note1 29, 0xc, 90
layer_note1 31, 0x18, 90
layer_end

.chan_3D3:
chan_setbank 1
chan_setinstr 5
chan_setlayer 0, .layer_3DB
chan_end

.layer_3DB:
layer_note1 34, 0xc, 80
layer_note1 36, 0x18, 80
layer_end

.chan_3E2:
chan_setbank 1
chan_setinstr 6
chan_setlayer 0, .layer_3EA
chan_end

.layer_3EA:
layer_note1 29, 0xc, 127
layer_note1 31, 0x18, 127
layer_end

.chan_3F1:
chan_setbank 1
chan_setinstr 8
chan_setlayer 0, .layer_3F9
chan_end

.layer_3F9:
layer_note0 31, 0xc, 100, 127
layer_note0 32, 0x24, 100, 127
layer_end

.chan_402:
chan_setbank 1
chan_setinstr 0
chan_setlayer 0, .layer_40A
chan_end

.layer_40A:
layer_note1 37, 0x18, 63
layer_end

.chan_40E:
chan_setbank 1
chan_setinstr 1
chan_setlayer 0, .layer_416
chan_end

.layer_416:
layer_note1 37, 0x18, 57
layer_end

.chan_41A:
chan_setbank 2
chan_setinstr 1
chan_setlayer 0, .layer_422
chan_end

.layer_422:
layer_note1 39, 0x18, 39
layer_end

.chan_426:
chan_setbank 1
chan_setinstr 3
chan_setlayer 0, .layer_42E
chan_end

.layer_42E:
layer_note1 37, 0x18, 49
layer_end

.chan_432:
chan_setbank 1
chan_setinstr 4
chan_setlayer 0, .layer_43A
chan_end

.layer_43A:
layer_note1 37, 0x18, 39
layer_end

.chan_43E:
chan_setbank 1
chan_setinstr 5
chan_setlayer 0, .layer_446
chan_end

.layer_446:
layer_note1 37, 0x18, 39
layer_end

.chan_44A:
chan_setbank 1
chan_setinstr 6
chan_setlayer 0, .layer_452
chan_end

.layer_452:
layer_note1 37, 0x18, 70
layer_end

.chan_456:
chan_setbank 1
chan_setinstr 8
chan_setlayer 0, .layer_45E
chan_end

.layer_45E:
layer_note1 35, 0x18, 49
layer_end

.chan_462:
chan_setbank 1
chan_setinstr 7
chan_setlayer 0, .layer_46A
chan_end

.layer_46A:
layer_note1 29, 0xc, 100
layer_note1 38, 0x12, 100
layer_end

.chan_471:
chan_setbank 1
chan_setinstr 7
chan_setlayer 0, .layer_479
chan_end

.layer_479:
layer_note1 38, 0xc, 100
layer_note1 29, 0x18, 100
layer_end

.chan_480:
chan_setbank 1
chan_setinstr 7
chan_setlayer 0, .layer_488
chan_end

.layer_488:
layer_portamento 0x85, 27, 255
layer_note1 31, 0x10, 100
layer_end

.chan_490:
chan_setbank 1
chan_setinstr 7
chan_setlayer 0, .layer_498
chan_end

.layer_498:
layer_note1 20, 0xc, 100
layer_note1 24, 0x18, 100
layer_end

.chan_49F:
chan_setbank 3
chan_setinstr 6
chan_setenvelope .envelope_3334
chan_setlayer 0, .layer_4AA
chan_end

.layer_4AA:
layer_note1 62, 0x6, 90
layer_note1 58, 0x7, 90
layer_end

.chan_4B1:
chan_setbank 0
chan_setinstr 2
chan_setlayer 0, .layer_4C5
chan_setval 1
chan_call .chan_fn_133
chan_setbank 3
chan_setinstr 1
chan_setenvelope .envelope_3304
chan_end

.layer_4C5:
layer_note1 62, 0x4, 127
layer_note0 56, 0x3, 127, 80
layer_end

.chan_4CD:
chan_setbank 1
chan_setinstr 8
chan_setlayer 0, .layer_4D5
chan_end

.layer_4D5:
layer_portamento 0x1, 29, 0x12
layer_note1 24, 0x12, 115
layer_end

.chan_4DD:
chan_setbank 1
chan_setinstr 7
chan_setlayer 0, .layer_4E5
chan_end

.layer_4E5:
layer_portamento 0x85, 25, 255
layer_note1 29, 0x10, 70
layer_end

.chan_4ED:
chan_setbank 2
chan_setinstr 0
chan_setlayer 0, .layer_4F5
chan_end

.layer_4F5:
layer_note1 39, 0x7f, 100
layer_end

.chan_4F9:
chan_setbank 2
chan_setinstr 1
chan_setlayer 0, .layer_501
chan_end

.layer_501:
layer_note1 36, 0x64, 90
layer_end

.chan_505:
chan_setbank 2
chan_setlayer 0, .layer_50B
chan_end

.layer_50B:
layer_setinstr 2
layer_note1 36, 0xa, 80
layer_setinstr 0
layer_portamento 0x81, 36, 255
layer_note1 50, 0x32, 80
layer_end

.chan_51A:
chan_setbank 2
chan_setinstr 2
chan_setlayer 0, .layer_522
chan_end

.layer_522:
layer_portamento 0x81, 35, 255
layer_note1 30, 0x3c, 110
layer_end

.chan_52A:
chan_setbank 2
chan_setinstr 2
chan_setlayer 0, .layer_532
chan_end

.layer_532:
layer_note1 39, 0x7f, 115
layer_end

.chan_536:
chan_setbank 0
chan_setinstr 0
chan_setlayer 0, .layer_540
chan_end

.layer_53E:
layer_transpose 1

.layer_540:
layer_portamento 0x81, 46, 255
layer_note1 31, 0xf, 100
layer_end

.chan_548:
chan_setbank 0
chan_setinstr 0
chan_setlayer 0, .layer_550
chan_end

.layer_550:
layer_note1 39, 0x12, 100
layer_end

.chan_554:
chan_setbank 0
chan_setinstr 0
chan_setdecayrelease 30
chan_setlayer 0, .layer_55E
chan_end

.layer_55E:
layer_portamento 0x81, 34, 255
layer_note1 41, 0xc, 127
layer_end

.chan_566:
chan_setbank 0
chan_setinstr 1
chan_setlayer 0, .layer_56E
chan_end

.layer_56E:
layer_note1 37, 0xa, 105
layer_portamento 0x81, 42, 255
layer_note1 37, 0x1e, 105
layer_end

.chan_579:
chan_setbank 0
chan_setinstr 1
chan_setlayer 0, .layer_581
chan_end

.layer_581:
layer_portamento 0x81, 44, 255
layer_note1 40, 0xb4, 100
layer_end

.chan_58A:
chan_setbank 0
chan_setinstr 2
chan_setlayer 0, .layer_592
chan_end

.layer_592:
layer_note1 39, 0x4, 127
layer_note1 41, 0x12, 127
layer_end

.chan_599:
chan_setbank 1
chan_setinstr 1
chan_setenvelope .envelope_32F4
chan_setlayer 0, .layer_5A4
chan_end

.layer_5A4:
layer_note1 38, 0x6, 127
layer_note1 41, 0x6, 127
layer_end

.chan_5AB:
chan_setbank 1
chan_setinstr 1
chan_setenvelope .envelope_32F4
chan_setlayer 0, .layer_5B6
chan_end

.layer_5B6:
layer_note1 41, 0x6, 127
layer_note1 38, 0x6, 127
layer_end

.chan_5BD:
chan_setbank 0
chan_setinstr 2
chan_setlayer 0, .layer_5C5
chan_end

.layer_5C5:
layer_note1 32, 0xa, 127
layer_end

.chan_5C9:
chan_setbank 0
chan_setinstr 1
chan_setenvelope .envelope_32F4
chan_setlayer 0, .layer_5D4
chan_end

.layer_5D4:
layer_note1 39, 0x8, 90
layer_note1 41, 0x8, 90
layer_end

.chan_5DB:
chan_setbank 3
chan_setinstr 1
chan_setenvelope .envelope_3314
chan_setlayer 0, .layer_5E6
chan_end

.layer_5E6:
layer_portamento 0x85, 53, 255
layer_note1 55, 0xc, 127
layer_note1 53, 0x18, 127
layer_end

.chan_5F1:
chan_setbank 1
chan_setinstr 7
chan_setlayer 0, .layer_5F9
chan_end

.layer_5F9:
layer_note1 39, 0x7, 100
layer_note1 20, 0x18, 115
layer_end

.chan_600:
chan_setbank 0
chan_setinstr 4
chan_setlayer 0, .layer_608
chan_end

.layer_608:
layer_note1 37, 0x48, 127
layer_end

.chan_60C:
chan_setbank 7
chan_setinstr 3
chan_setlayer 0, .layer_620
chan_setval 1
chan_call .chan_fn_133
chan_setbank 6
chan_setinstr 10
chan_setenvelope .envelope_3344
chan_end

.layer_620:
layer_portamento 0x81, 27, 255
layer_note1 46, 0xb, 127
.layer_627:
layer_somethingon
layer_portamento 0x85, 32, 255
layer_note1 44, 0x5, 100
layer_call .layer_fn_652
layer_transpose 1
layer_call .layer_fn_652
layer_transpose 3
layer_call .layer_fn_652
layer_transpose 4
layer_call .layer_fn_652
layer_transpose 6
layer_call .layer_fn_652
layer_transpose 7
layer_call .layer_fn_652
layer_transpose 9
layer_call .layer_fn_652
layer_transpose 10

.layer_fn_652:
layer_note1 20, 0x5, 115
layer_note1 32, 0x5, 115
layer_end

.chan_659:
chan_setbank 7
chan_setinstr 3
chan_setlayer 0, .layer_661
chan_end

.layer_661:
layer_portamento 0x82, 19, 255
layer_note1 34, 0x5, 110
layer_note1 39, 0x2, 110
layer_end

.chan_66C:
chan_setbank 3
chan_setinstr 3
chan_setval 50
chan_call .chan_fn_14C
chan_setenvelope .envelope_3354
chan_setlayer 0, .layer_697
chan_delay 0x1
chan_setlayer 1, .layer_6A9
chan_setbank 9
chan_setinstr 1
chan_setenvelope .envelope_3304
chan_setdecayrelease 20
chan_delay 0x1
chan_setlayer 2, .layer_6A1
chan_setbank 4
chan_setinstr 14
chan_setdecayrelease 12
chan_setvibratoextent 10
chan_end

.layer_697:
layer_transpose 36
layer_portamento 0x81, 62, 255
layer_note1 38, 0x7f, 127
layer_end

.layer_6A1:
layer_portamento 0x81, 39, 255
layer_note1 15, 0x7f, 127
layer_end

.layer_6A9:
layer_portamento 0x81, 62, 255
layer_note1 38, 0x7f, 100
layer_end

.chan_6B1:
chan_setbank 2
chan_setinstr 2
chan_setval 20
chan_call .chan_fn_14C
chan_setlayer 0, .layer_6C9
chan_setlayer 1, .layer_6C1
chan_end

.layer_6C1:
layer_portamento 0x81, 23, 255
layer_note1 59, 0x30, 120
layer_end

.layer_6C9:
layer_portamento 0x81, 35, 255
layer_note1 42, 0x3c, 110
layer_end

.chan_6D1:
chan_setbank 1
chan_setinstr 0
chan_setlayer 0, .layer_6D9
chan_end

.layer_6D9:
layer_note1 17, 0x6, 127
layer_portamento 0x81, 31, 255
layer_note1 7, 0xc, 127
layer_end

.chan_6E4:
chan_setbank 1
chan_setinstr 5
chan_setlayer 0, .layer_6EC
chan_end

.layer_6EC:
layer_note1 23, 0x6, 127
layer_note1 25, 0xc, 127
layer_end

.chan_6F3:
chan_setbank 1
chan_setinstr 8
chan_setlayer 0, .layer_6FB
chan_end

.layer_6FB:
layer_note1 17, 0x6, 127
layer_note1 19, 0xc, 127
layer_end

.chan_702:
chan_setbank 1
chan_setinstr 7
chan_setenvelope .envelope_3344
chan_setlayer 0, .layer_70D
chan_end

.layer_70D:
layer_note1 20, 0xf, 90
layer_note1 29, 0x17, 90
layer_end

.chan_714:
chan_setbank 1
chan_setinstr 7
chan_setenvelope .envelope_3344
chan_setlayer 0, .layer_71F
chan_end

.layer_71F:
layer_note1 29, 0xf, 90
layer_note1 20, 0x1f, 90
layer_end

.chan_726:
chan_setbank 1
chan_setinstr 7
chan_setenvelope .envelope_3344
chan_setlayer 0, .layer_731
chan_end

.layer_731:
layer_portamento 0x85, 18, 255
layer_note1 22, 0x15, 90
layer_end

.chan_739:
chan_setbank 1
chan_setinstr 7
chan_setenvelope .envelope_3344
chan_setlayer 0, .layer_744
chan_end

.layer_744:
layer_note1 11, 0xf, 90
layer_note1 15, 0x1f, 90
layer_end

.chan_74B:
chan_setbank 1
chan_setinstr 7
chan_setenvelope .envelope_3344
chan_setlayer 0, .layer_756
chan_end

.layer_756:
layer_portamento 0x85, 18, 255
layer_note1 22, 0x10, 90
layer_end

.chan_75E:
chan_setbank 6
chan_setinstr 10
chan_setenvelope .envelope_3344
chan_setlayer 0, .layer_769
chan_end

.layer_769:
layer_transpose 8
layer_jump .layer_627

.chan_76E:
chan_setbank 5
chan_setinstr 6
chan_setenvelope .envelope_33DC
chan_setlayer 0, .layer_77C
chan_setlayer 1, .layer_77E
chan_end

.layer_77C:
layer_transpose 12

.layer_77E:
layer_somethingon
layer_portamento 0x85, 27, 255
layer_note1 51, 0x14, 127
layer_note1 36, 0x5a, 127
layer_end

.chan_78A:
chan_setbank 9
chan_setinstr 3
chan_setvibratoextent 60
chan_setvibratorate 60
chan_setenvelope .envelope_3314
chan_setlayer 0, .layer_7A5
chan_setlayer 1, .layer_7A3
chan_setval 36
chan_call .chan_fn_133
chan_setvibratoextent 0
chan_end

.layer_7A3:
layer_transpose 1

.layer_7A5:
layer_portamento 0x81, 20, 100
layer_note1 27, 0x30, 127
layer_end

.chan_7AD:
chan_setbank 1
chan_setinstr 7
chan_setenvelope .envelope_3374
chan_setlayer 0, .layer_7C1
chan_setval 4
chan_call .chan_fn_133
chan_setbank 9
chan_setinstr 3
chan_end

.layer_7C1:
layer_note1 43, 0x3, 115
layer_note1 48, 0x5, 115
layer_transpose 12
layer_note1 55, 0x6, 80
layer_end

.chan_7CD:
chan_setbank 7
chan_setinstr 3
chan_setlayer 0, .layer_7E1
chan_setval 1
chan_call .chan_fn_133
chan_setbank 6
chan_setinstr 10
chan_setenvelope .envelope_3344
chan_end

.layer_7E1:
layer_portamento 0x81, 27, 255
layer_note1 41, 0xb, 127
layer_somethingon
layer_transpose 252
layer_portamento 0x85, 32, 255
layer_note1 44, 0x5, 100
layer_jump .layer_fn_652

.chan_7F5:
chan_setbank 0
chan_setinstr 3
chan_setdecayrelease 30
chan_setlayer 0, .layer_7FF
chan_end

.layer_7FF:
layer_setinstr 0
layer_portamento 0x81, 32, 255
layer_note1 39, 0x24, 127
layer_end

.chan_809:
chan_jump .chan_2DFA

.chan_fn_80C:
chan_setbank 0
chan_setinstr 5
chan_setlayer 0, .layer_814
chan_end

.layer_814:
layer_note1 41, 0x3c, 127
layer_end

.chan_818:
chan_setbank 1
chan_setinstr 1
chan_setenvelope .envelope_32F4
chan_setlayer 0, .layer_823
chan_end

.layer_823:
layer_note1 38, 0x8, 127
layer_note1 41, 0x9, 127
layer_note1 39, 0xa, 127
layer_note1 42, 0x8, 127
layer_end

.chan_830:
chan_setbank 7
chan_setinstr 3
chan_setlayer 0, .layer_844
chan_setval 1
chan_call .chan_fn_133
chan_setbank 6
chan_setinstr 10
chan_setenvelope .envelope_3344
chan_end

.layer_844:
layer_portamento 0x81, 27, 255
layer_note1 46, 0x7, 127
layer_portamento 0x85, 3, 255
layer_note1 39, 0xf, 100
layer_end

.chan_853:
chan_setbank 5
chan_setinstr 6
chan_setenvelope .envelope_33DC
chan_setlayer 0, .layer_861
chan_setlayer 1, .layer_863
chan_end

.layer_861:
layer_transpose 12

.layer_863:
layer_portamento 0x85, 26, 240
layer_note1 51, 0x53, 127
layer_end

.chan_86B:
chan_setbank 5
chan_setinstr 6
chan_setenvelope .envelope_33DC
chan_setlayer 0, .layer_879
chan_setlayer 1, .layer_77E
chan_end

.layer_879:
layer_transpose 8
layer_jump .layer_77E

.chan_87E:
chan_call .chan_fn_80C
chan_setval 1
chan_call .chan_fn_133
chan_setbank 1
chan_setinstr 0
chan_setlayer 1, .layer_390
chan_end

.chan_88E:
chan_call .chan_fn_80C
chan_setval 1
chan_call .chan_fn_133
chan_setbank 1
chan_setinstr 1
chan_setlayer 1, .layer_39F
chan_end

.chan_89E:
chan_call .chan_fn_80C
chan_setval 1
chan_call .chan_fn_133
chan_setbank 2
chan_setinstr 1
chan_setlayer 1, .layer_3AE
chan_end

.chan_8AE:
chan_call .chan_fn_80C
chan_setval 1
chan_call .chan_fn_133
chan_setbank 1
chan_setinstr 3
chan_setlayer 1, .layer_3BD
chan_end

.chan_8BE:
chan_call .chan_fn_80C
chan_setval 1
chan_call .chan_fn_133
chan_setbank 1
chan_setinstr 4
chan_setlayer 1, .layer_3CC
chan_end

.chan_8CE:
chan_call .chan_fn_80C
chan_setval 1
chan_call .chan_fn_133
chan_setbank 1
chan_setinstr 5
chan_setlayer 1, .layer_3DB
chan_end

.chan_8DE:
chan_call .chan_fn_80C
chan_setval 1
chan_call .chan_fn_133
chan_setbank 1
chan_setinstr 6
chan_setlayer 1, .layer_3EA
chan_end

.chan_8EE:
chan_call .chan_fn_80C
chan_setval 1
chan_call .chan_fn_133
chan_setbank 1
chan_setinstr 8
chan_setlayer 1, .layer_3F9
chan_end

.table_8FE:
sound_ref .chan_96E
sound_ref .chan_97F
sound_ref .chan_99C
sound_ref .chan_9C3
sound_ref .chan_9D4
sound_ref .chan_9F1
sound_ref .chan_A02
sound_ref .chan_A13
sound_ref .chan_96E
sound_ref .chan_97F
sound_ref .chan_99C
sound_ref .chan_9C3
sound_ref .chan_9D4
sound_ref .chan_9F1
sound_ref .chan_A02
sound_ref .chan_A13
sound_ref .chan_A30
sound_ref .chan_A41
sound_ref .chan_A55
sound_ref .chan_11E7
sound_ref .chan_A6A
sound_ref .chan_11E7
sound_ref .chan_A7F
sound_ref .chan_A94
sound_ref .chan_AAB
sound_ref .chan_AC8
sound_ref .chan_ACB
sound_ref .chan_9C3
sound_ref .chan_9D4
sound_ref .chan_9F1
sound_ref .chan_A02
sound_ref .chan_A13
sound_ref .chan_AF2
sound_ref .chan_AFF
sound_ref .chan_B15
sound_ref .chan_B33
sound_ref .chan_B40
sound_ref .chan_B56
sound_ref .chan_B63
sound_ref .chan_B70
sound_ref .chan_B86
sound_ref .chan_AFF
sound_ref .chan_B15
sound_ref .chan_B33
sound_ref .chan_B40
sound_ref .chan_B56
sound_ref .chan_B63
sound_ref .chan_B70
sound_ref .chan_AF2
sound_ref .chan_AFF
sound_ref .chan_B15
sound_ref .chan_B33
sound_ref .chan_B40
sound_ref .chan_B56
sound_ref .chan_B63
sound_ref .chan_B70

.chan_96E:
chan_setbank 3
chan_setinstr 0
chan_setlayer 0, .layer_976
chan_end

.layer_976:
layer_somethingon
.layer_977:
layer_note1 39, 0x12c, 80
layer_jump .layer_977
layer_end

.chan_97F:
chan_setbank 1
chan_setinstr 1
chan_setlayer 0, .layer_990
chan_setval 1
chan_call .chan_fn_133
chan_setbank 3
chan_setinstr 1
chan_end

.layer_990:
layer_note1 41, 0x8, 105
layer_somethingon
.layer_994:
layer_note1 39, 0x12c, 70
layer_jump .layer_994
layer_end

.chan_99C:
chan_setbank 2
chan_setinstr 1
chan_setlayer 0, .layer_9B0
chan_setlayer 1, .layer_9BB
chan_setval 1
chan_call .chan_fn_133
chan_setbank 3
chan_setinstr 2
chan_end

.layer_9B0:
layer_delay 0x1
layer_somethingon
.layer_9B3:
layer_note1 39, 0x12c, 88
layer_jump .layer_9B3
layer_end

.layer_9BB:
layer_portamento 0x81, 39, 255
layer_note1 48, 0x32, 80
layer_end

.chan_9C3:
chan_setbank 3
chan_setinstr 3
chan_setlayer 0, .layer_9CB
chan_end

.layer_9CB:
layer_somethingon
.layer_9CC:
layer_note1 39, 0x12c, 68
layer_jump .layer_9CC
layer_end

.chan_9D4:
chan_setbank 1
chan_setinstr 4
chan_setlayer 0, .layer_9E5
chan_setval 1
chan_call .chan_fn_133
chan_setbank 3
chan_setinstr 4
chan_end

.layer_9E5:
layer_note1 42, 0xc, 75
layer_somethingon
.layer_9E9:
layer_note1 39, 0x12c, 76
layer_jump .layer_9E9
layer_end

.chan_9F1:
chan_setbank 3
chan_setinstr 5
chan_setlayer 0, .layer_9F9
chan_end

.layer_9F9:
layer_somethingon
.layer_9FA:
layer_note1 39, 0x12c, 80
layer_jump .layer_9FA
layer_end

.chan_A02:
chan_setbank 3
chan_setinstr 6
chan_setlayer 0, .layer_A0A
chan_end

.layer_A0A:
layer_somethingon
.layer_A0B:
layer_note1 39, 0x12c, 100
layer_jump .layer_A0B
layer_end

.chan_A13:
chan_setbank 1
chan_setinstr 8
chan_setlayer 0, .layer_A24
chan_setval 1
chan_call .chan_fn_133
chan_setbank 3
chan_setinstr 7
chan_end

.layer_A24:
layer_note1 42, 0xc, 100
layer_somethingon
.layer_A28:
layer_note1 39, 0x12c, 81
layer_jump .layer_A28
layer_end

.chan_A30:
chan_setbank 3
chan_setinstr 8
chan_setlayer 0, .layer_A38
chan_end

.layer_A38:
layer_somethingon
.layer_A39:
layer_note1 39, 0x12c, 120
layer_jump .layer_A39
layer_end

.chan_A41:
chan_setbank 3
chan_setinstr 1
chan_setenvelope .envelope_3304
chan_setlayer 0, .layer_A4C
chan_end

.layer_A4C:
layer_somethingon
.layer_A4D:
layer_note1 43, 0x12c, 80
layer_jump .layer_A4D
layer_end

.chan_A55:
chan_setbank 0
chan_setinstr 1
chan_setlayer 0, .layer_A5D
chan_end

.layer_A5D:
layer_portamento 0x81, 44, 255
.layer_A61:
layer_somethingon
layer_note1 40, 0xb4, 100
layer_jump .layer_A61
layer_end

.chan_A6A:
chan_setbank 3
chan_setinstr 7
chan_setlayer 0, .layer_A72
chan_end

.layer_A72:
layer_somethingon
layer_portamento 0x85, 37, 255
.layer_A77:
layer_note1 34, 0xc8, 127
layer_jump .layer_A77
layer_end

.chan_A7F:
chan_setbank 3
chan_setinstr 9
chan_setlayer 0, .layer_A8C
chan_setlayer 1, .layer_A8A
chan_end

.layer_A8A:
layer_transpose 24

.layer_A8C:
layer_note1_long 43, 0x6, 127
layer_jump .layer_A8C
layer_end

.chan_A94:
chan_setbank 5
chan_setinstr 6
chan_setlayer 0, .layer_AA3
chan_setlayer 1, .layer_A9F
chan_end

.layer_A9F:
layer_setinstr 13
layer_transpose 244

.layer_AA3:
layer_somethingon
.layer_AA4:
layer_note1 43, 0x12c, 105
layer_jump .layer_AA4

.chan_AAB:
chan_setbank 9
chan_setinstr 3
chan_setval 40
chan_call .chan_fn_14C
chan_setenvelope .envelope_3374
chan_setlayer 0, .layer_ABB
chan_end

.layer_ABB:
layer_transpose 12
.layer_ABD:
layer_note0 60, 0xc, 100, 127
layer_note0 60, 0x30, 100, 127
layer_jump .layer_ABD

.chan_AC8:
chan_jump .chan_29DB

.chan_ACB:
chan_setbank 9
chan_setinstr 3
chan_setenvelope .envelope_3398
chan_setlayer 0, .layer_AE0
chan_setlayer 1, .layer_ADE
chan_setlayer 2, .layer_ADC
chan_end

.layer_ADC:
layer_delay 0x4

.layer_ADE:
layer_delay 0x4

.layer_AE0:
layer_transpose 24
.layer_AE2:
layer_portamento 0x85, 32, 40
layer_note1 39, 0x9, 100
layer_note1 44, 0x6, 50
layer_note1 51, 0x3, 20
layer_jump .layer_AE2

.chan_AF2:
chan_setbank 3
chan_setinstr 0
chan_setlayer 0, .layer_AFA
chan_end

.layer_AFA:
layer_transpose 4
layer_jump .layer_976

.chan_AFF:
chan_setbank 1
chan_setinstr 1
chan_setlayer 0, .layer_B10
chan_setval 1
chan_call .chan_fn_133
chan_setbank 3
chan_setinstr 1
chan_end

.layer_B10:
layer_transpose 4
layer_jump .layer_990

.chan_B15:
chan_setbank 2
chan_setinstr 1
chan_setlayer 0, .layer_B29
chan_setlayer 1, .layer_B2E
chan_setval 1
chan_call .chan_fn_133
chan_setbank 3
chan_setinstr 2
chan_end

.layer_B29:
layer_transpose 4
layer_jump .layer_9B0

.layer_B2E:
layer_transpose 4
layer_jump .layer_9BB

.chan_B33:
chan_setbank 3
chan_setinstr 3
chan_setlayer 0, .layer_B3B
chan_end

.layer_B3B:
layer_transpose 4
layer_jump .layer_9CB

.chan_B40:
chan_setbank 1
chan_setinstr 4
chan_setlayer 0, .layer_B51
chan_setval 1
chan_call .chan_fn_133
chan_setbank 3
chan_setinstr 4
chan_end

.layer_B51:
layer_transpose 4
layer_jump .layer_9E5

.chan_B56:
chan_setbank 3
chan_setinstr 5
chan_setlayer 0, .layer_B5E
chan_end

.layer_B5E:
layer_transpose 4
layer_jump .layer_9F9

.chan_B63:
chan_setbank 3
chan_setinstr 6
chan_setlayer 0, .layer_B6B
chan_end

.layer_B6B:
layer_transpose 4
layer_jump .layer_A0A

.chan_B70:
chan_setbank 1
chan_setinstr 8
chan_setlayer 0, .layer_B81
chan_setval 1
chan_call .chan_fn_133
chan_setbank 3
chan_setinstr 7
chan_end

.layer_B81:
layer_transpose 4
layer_jump .layer_A24

.chan_B86:
chan_setlayer 0, .layer_BA7
chan_setlayer 1, .layer_BB0
.chan_B8C:
chan_setbank 3
chan_setinstr 2
chan_setval 1
chan_call .chan_fn_133
chan_setdecayrelease 30
chan_setbank 2
chan_setinstr 1
chan_setenvelope .envelope_3364
chan_setval 1
chan_call .chan_fn_133
chan_jump .chan_B8C
chan_end

.layer_BA7:
layer_somethingon
.layer_BA8:
layer_note1 42, 0x12c, 88
layer_jump .layer_BA8
layer_end

.layer_BB0:
layer_delay 0x1
.layer_BB2:
layer_portamento 0x81, 41, 255
layer_note1 56, 0xa, 127
layer_jump .layer_BB2

.table_BBC:
sound_ref .chan_C5C
sound_ref .chan_C4E
sound_ref .chan_C3C
sound_ref .chan_C6E
sound_ref .chan_C80
sound_ref .chan_C96
sound_ref .chan_CA8
sound_ref .chan_CB6
sound_ref .chan_CC4
sound_ref .chan_CD2
sound_ref .chan_CE0
sound_ref .chan_CEE
sound_ref .chan_CFC
sound_ref .chan_D0D
sound_ref .chan_D1B
sound_ref .chan_D29
sound_ref .chan_D37
sound_ref .chan_D46
sound_ref .chan_D92
sound_ref .chan_D54
sound_ref .chan_D62
sound_ref .chan_D71
sound_ref .chan_D80
sound_ref .chan_DE0
sound_ref .chan_D92
sound_ref .chan_DA0
sound_ref .chan_DB0
sound_ref .chan_DC0
sound_ref .chan_DCE
sound_ref .chan_DE0
sound_ref .chan_DF6
sound_ref .chan_E0F
sound_ref .chan_E2D
sound_ref .chan_E3E
sound_ref .chan_E4A
sound_ref .chan_E4D
sound_ref .chan_E5A
sound_ref .chan_C96
sound_ref .chan_CA8
sound_ref .chan_CB6
sound_ref .chan_E73
sound_ref .chan_C3C
sound_ref .chan_C3C
sound_ref .chan_C80
sound_ref .chan_C80
sound_ref .chan_C80
sound_ref .chan_E80
sound_ref .chan_E8C
sound_ref .chan_E98
sound_ref .chan_EA4
sound_ref .chan_EB0
sound_ref .chan_EBC
sound_ref .chan_EC9
sound_ref .chan_ED5
sound_ref .chan_EF8
sound_ref .chan_F0C
sound_ref .chan_F19
sound_ref .chan_F28
sound_ref .chan_F38
sound_ref .chan_F48
sound_ref .chan_F57
sound_ref .chan_F67
sound_ref .chan_F77
sound_ref .chan_F86

.chan_C3C:
chan_setbank 8
chan_setinstr 0
chan_setlayer 0, .layer_C44
chan_end

.layer_C44:
layer_transpose 2
layer_portamento 0x82, 41, 127
layer_note1 37, 0x14, 127
layer_end

.chan_C4E:
chan_setbank 8
chan_setinstr 1
chan_setlayer 0, .layer_C56
chan_end

.layer_C56:
layer_transpose 254
.layer_C58:
layer_note1 38, 0x18, 127
layer_end

.chan_C5C:
chan_setbank 10
chan_setinstr 9
chan_setlayer 0, .layer_C64
chan_end

.layer_C64:
layer_transpose 254
.layer_C66:
layer_portamento 0x82, 39, 200
layer_note1 38, 0x24, 120
layer_end

.chan_C6E:
chan_setbank 10
chan_setinstr 1
chan_setlayer 0, .layer_C76
chan_end

.layer_C76:
layer_transpose 1
layer_portamento 0x82, 44, 200
layer_note1 39, 0x30, 127
layer_end

.chan_C80:
chan_setbank 8
chan_setinstr 4
chan_setlayer 0, .layer_C88
chan_end

.layer_C88:
layer_transpose 254
layer_somethingon
layer_portamento 0x85, 39, 255
layer_note1 42, 0x1e, 110
layer_note1 39, 0x41, 110
layer_end

.chan_C96:
chan_setbank 8
chan_setinstr 5
chan_setlayer 0, .layer_C9E
chan_end

.layer_C9E:
layer_transpose 254
layer_portamento 0x81, 41, 255
layer_note1 38, 0x2b, 115
layer_end

.chan_CA8:
chan_setbank 8
chan_setinstr 6
chan_setlayer 0, .layer_CB0
chan_end

.layer_CB0:
layer_transpose 254
layer_note1 44, 0x1e, 110
layer_end

.chan_CB6:
chan_setbank 8
chan_setinstr 7
chan_setlayer 0, .layer_CBE
chan_end

.layer_CBE:
layer_transpose 253
layer_note1 39, 0x1c, 127
layer_end

.chan_CC4:
chan_setbank 8
chan_setinstr 8
chan_setlayer 0, .layer_CCC
chan_end

.layer_CCC:
layer_transpose 254
layer_note1 40, 0x30, 110
layer_end

.chan_CD2:
chan_setbank 8
chan_setinstr 9
chan_setlayer 0, .layer_CDA
chan_end

.layer_CDA:
layer_transpose 254
layer_note1 40, 0x44, 105
layer_end

.chan_CE0:
chan_setbank 8
chan_setinstr 10
chan_setlayer 0, .layer_CE8
chan_end

.layer_CE8:
layer_transpose 254
layer_note1 41, 0x30, 120
layer_end

.chan_CEE:
chan_setbank 8
chan_setinstr 11
chan_setlayer 0, .layer_CF6
chan_end

.layer_CF6:
layer_transpose 254
layer_note1 38, 0x30, 127
layer_end

.chan_CFC:
chan_setbank 8
chan_setinstr 12
chan_setlayer 0, .layer_D04
chan_end

.layer_D04:
layer_portamento 0x81, 38, 200
layer_note1 41, 0x85, 127
layer_end

.chan_D0D:
chan_setbank 8
chan_setinstr 13
chan_setlayer 0, .layer_D15
chan_end

.layer_D15:
layer_transpose 254
layer_note1 39, 0x7f, 105
layer_end

.chan_D1B:
chan_setbank 8
chan_setinstr 14
chan_setlayer 0, .layer_D23
chan_end

.layer_D23:
layer_transpose 254
layer_note1 39, 0x60, 64
layer_end

.chan_D29:
chan_setbank 8
chan_setinstr 15
chan_setlayer 0, .layer_D31
chan_end

.layer_D31:
layer_transpose 254
layer_note1 39, 0x5c, 52
layer_end

.chan_D37:
chan_setbank 10
chan_setinstr 0
chan_setlayer 0, .layer_D3F
chan_end

.layer_D3F:
layer_transpose 254
layer_note1 39, 0xaa, 127
layer_end

.chan_D46:
chan_setbank 8
chan_setinstr 3
chan_setlayer 0, .layer_D4E
chan_end

.layer_D4E:
layer_transpose 255
layer_note1 39, 0x4d, 120
layer_end

.chan_D54:
chan_setbank 10
chan_setinstr 6
chan_setlayer 0, .layer_D5C
chan_end

.layer_D5C:
layer_transpose 254
layer_note1 43, 0x1e, 105
layer_end

.chan_D62:
chan_setbank 10
chan_setinstr 5
chan_setlayer 0, .layer_D6A
chan_end

.layer_D6A:
layer_transpose 254
layer_note1 39, 0xc8, 127
layer_end

.chan_D71:
chan_setbank 10
chan_setinstr 4
chan_setlayer 0, .layer_D79
chan_end

.layer_D79:
layer_transpose 254
layer_note1 39, 0x8c, 110
layer_end

.chan_D80:
chan_setbank 10
chan_setinstr 2
chan_setlayer 0, .layer_D88
chan_end

.layer_D88:
layer_transpose 254
layer_portamento 0x82, 35, 255
layer_note1 38, 0x30, 127
layer_end

.chan_D92:
chan_setbank 10
chan_setinstr 2
chan_setlayer 0, .layer_D9A
chan_end

.layer_D9A:
layer_transpose 254
layer_note1 39, 0x3c, 100
layer_end

.chan_DA0:
chan_setbank 10
chan_setinstr 2
chan_setlayer 0, .layer_DA8
chan_end

.layer_DA8:
layer_transpose 254
layer_delay 0x4
layer_note1 38, 0x3c, 100
layer_end

.chan_DB0:
chan_setbank 10
chan_setinstr 2
chan_setlayer 0, .layer_DB8
chan_end

.layer_DB8:
layer_transpose 254
layer_delay 0x8
layer_note1 40, 0x3c, 100
layer_end

.chan_DC0:
chan_setbank 10
chan_setinstr 7
chan_setlayer 0, .layer_DC8
chan_end

.layer_DC8:
layer_transpose 254
layer_note1 39, 0x10, 115
layer_end

.chan_DCE:
chan_setbank 10
chan_setinstr 7
chan_setlayer 0, .layer_DD6
chan_end

.layer_DD6:
layer_transpose 254
layer_portamento 0x81, 38, 255
layer_note1 41, 0x18, 115
layer_end

.chan_DE0:
chan_setbank 10
chan_setinstr 7
chan_setlayer 0, .layer_DE8
chan_end

.layer_DE8:
layer_transpose 254
layer_somethingon
layer_portamento 0x85, 38, 255
layer_note1 41, 0xc, 115
layer_note1 35, 0x12, 115
layer_end

.chan_DF6:
chan_setbank 10
chan_setinstr 9
chan_setlayer 0, .layer_E0A
chan_setval 1
chan_call .chan_fn_133
chan_setbank 0
chan_setinstr 0
chan_setlayer 1, .layer_540
chan_end

.layer_E0A:
layer_transpose 254
layer_jump .layer_C66

.chan_E0F:
chan_setbank 10
chan_setinstr 10
chan_setlayer 0, .layer_E23
chan_setval 1
chan_call .chan_fn_133
chan_setbank 0
chan_setinstr 0
chan_setlayer 1, .layer_550
chan_end

.layer_E23:
layer_transpose 254
layer_portamento 0x81, 42, 255
layer_note1 38, 0x30, 115
layer_end

.chan_E2D:
chan_setbank 10
chan_setinstr 11
chan_setlayer 0, .layer_E35
chan_end

.layer_E35:
layer_portamento 0x81, 38, 255
layer_note1 36, 0x8c, 115
layer_end

.chan_E3E:
chan_setbank 10
chan_setinstr 12
chan_setlayer 0, .layer_E46
chan_end

.layer_E46:
layer_note1 39, 0x60, 115
layer_end

.chan_E4A:
chan_jump .chan_CB6

.chan_E4D:
chan_setbank 10
chan_setinstr 13
chan_setlayer 0, .layer_E55
chan_end

.layer_E55:
layer_note1 38, 0x91, 127
layer_end

.chan_E5A:
chan_setbank 8
chan_setinstr 1
chan_setlayer 0, .layer_E6E
chan_setval 1
chan_call .chan_fn_133
chan_setbank 0
chan_setinstr 0
chan_setlayer 1, .layer_53E
chan_end

.layer_E6E:
layer_transpose 255
layer_jump .layer_C58

.chan_E73:
chan_setbank 10
chan_setinstr 15
chan_setlayer 0, .layer_E7B
chan_end

.layer_E7B:
layer_note1 39, 0x2bc, 127
layer_end

.chan_E80:
chan_setbank 8
chan_setinstr 24
chan_setlayer 0, .layer_E88
chan_end

.layer_E88:
layer_note1 39, 0x5a, 127
layer_end

.chan_E8C:
chan_setbank 8
chan_setinstr 25
chan_setlayer 0, .layer_E94
chan_end

.layer_E94:
layer_note1 39, 0x5a, 97
layer_end

.chan_E98:
chan_setbank 8
chan_setinstr 16
chan_setlayer 0, .layer_EA0
chan_end

.layer_EA0:
layer_note1 41, 0x46, 127
layer_end

.chan_EA4:
chan_setbank 8
chan_setinstr 17
chan_setlayer 0, .layer_EAC
chan_end

.layer_EAC:
layer_note1 39, 0x55, 110
layer_end

.chan_EB0:
chan_setbank 8
chan_setinstr 18
chan_setlayer 0, .layer_EB8
chan_end

.layer_EB8:
layer_note1 39, 0x46, 127
layer_end

.chan_EBC:
chan_setbank 8
chan_setinstr 19
chan_setlayer 0, .layer_EC4
chan_end

.layer_EC4:
layer_note1 39, 0x12c, 127
layer_end

.chan_EC9:
chan_setbank 8
chan_setinstr 20
chan_setlayer 0, .layer_ED1
chan_end

.layer_ED1:
layer_note1 39, 0x30, 127
layer_end

.chan_ED5:
chan_setbank 8
chan_setlayer 0, .layer_EDB
chan_end

.layer_EDB:
layer_delay 0x4e
.layer_EDD:
layer_loop 50
layer_call .layer_fn_EED
layer_loopend
layer_setinstr 21
layer_note1 39, 0x44c, 127
layer_jump .layer_EDD
layer_end

.layer_fn_EED:
layer_setinstr 21
layer_note1 37, 0x53, 127
layer_setinstr 15
layer_note1 37, 0x4e, 64
layer_end

.chan_EF8:
chan_setbank 8
chan_setinstr 22
chan_setlayer 0, .layer_F03
chan_setlayer 1, .layer_F03
chan_end

.layer_F03:
layer_portamento 0x82, 42, 200
layer_note1 39, 0xc8, 110
layer_end

.chan_F0C:
chan_setbank 8
chan_setinstr 23
chan_setlayer 0, .layer_F14
chan_end

.layer_F14:
layer_note1 39, 0x96, 110
layer_end

.chan_F19:
chan_setbank 10
chan_setinstr 16
chan_setlayer 0, .layer_F24
chan_setlayer 1, .layer_F24
chan_end

.layer_F24:
layer_note1 39, 0x46, 127
layer_end

.chan_F28:
chan_setbank 10
chan_setinstr 17
chan_setlayer 0, .layer_F33
chan_setlayer 1, .layer_F33
chan_end

.layer_F33:
layer_note1 39, 0x15e, 127
layer_end

.chan_F38:
chan_setbank 10
chan_setinstr 18
chan_setlayer 0, .layer_F43
chan_setlayer 1, .layer_F43
chan_end

.layer_F43:
layer_note1 39, 0xb4, 127
layer_end

.chan_F48:
chan_setbank 10
chan_setinstr 19
chan_setlayer 0, .layer_F53
chan_setlayer 1, .layer_F53
chan_end

.layer_F53:
layer_note1 39, 0x64, 127
layer_end

.chan_F57:
chan_setbank 10
chan_setinstr 20
chan_setlayer 0, .layer_F62
chan_setlayer 1, .layer_F62
chan_end

.layer_F62:
layer_note1 39, 0xdc, 127
layer_end

.chan_F67:
chan_setbank 10
chan_setinstr 21
chan_setlayer 0, .layer_F72
chan_setlayer 1, .layer_F72
chan_end

.layer_F72:
layer_note1 39, 0x190, 127
layer_end

.chan_F77:
chan_setbank 10
chan_setinstr 22
chan_setlayer 0, .layer_F82
chan_setlayer 1, .layer_F82
chan_end

.layer_F82:
layer_note1 39, 0x50, 127
layer_end

.chan_F86:
chan_setbank 10
chan_setinstr 23
chan_setval 20
chan_call .chan_fn_14C
chan_setlayer 0, .layer_F96
chan_setlayer 1, .layer_F96
chan_end

.layer_F96:
layer_note1 39, 0x50, 127
layer_end

.chan_unused_F9A:
chan_setbank 8
chan_setinstr 0
chan_setlayer 0, .layer_FA2
chan_end

.layer_FA2:
layer_delay 0x5
layer_end

.table_FA5:
sound_ref .chan_10A5
sound_ref .chan_10BE
sound_ref .chan_10BE
sound_ref .chan_10CA
sound_ref .chan_10E1
sound_ref .chan_10F2
sound_ref .chan_1101
sound_ref .chan_1127
sound_ref .chan_1133
sound_ref .chan_1147
sound_ref .chan_1F67
sound_ref .chan_1164
sound_ref .chan_1170
sound_ref .chan_1184
sound_ref .chan_1194
sound_ref .chan_11A0
sound_ref .chan_11E7
sound_ref .chan_11E7
sound_ref .chan_120A
sound_ref .chan_120A
sound_ref .chan_120A
sound_ref .chan_120A
sound_ref .chan_1271
sound_ref .chan_1286
sound_ref .chan_1295
sound_ref .chan_1295
sound_ref .chan_12A1
sound_ref .chan_12A1
sound_ref .chan_12A1
sound_ref .chan_12A1
sound_ref .chan_12A1
sound_ref .chan_12A1
sound_ref .chan_12AD
sound_ref .chan_12AD
sound_ref .chan_12D6
sound_ref .chan_12D6
sound_ref .chan_12EB
sound_ref .chan_1302
sound_ref .chan_131A
sound_ref .chan_132D
sound_ref .chan_1347
sound_ref .chan_1347
sound_ref .chan_1347
sound_ref .chan_1347
sound_ref .chan_1353
sound_ref .chan_135F
sound_ref .chan_1380
sound_ref .chan_139C
sound_ref .chan_13BC
sound_ref .chan_13D1
sound_ref .chan_13EB
sound_ref .chan_11E7
sound_ref .chan_1404
sound_ref .chan_1414
sound_ref .chan_1424
sound_ref .chan_1440
sound_ref .chan_1462
sound_ref .chan_1488
sound_ref .chan_14B5
sound_ref .chan_1501
sound_ref .chan_1515
sound_ref .chan_1530
sound_ref .chan_1546
sound_ref .chan_1562
sound_ref .chan_1578
sound_ref .chan_158E
sound_ref .chan_15A8
sound_ref .chan_15B9
sound_ref .chan_15D0
sound_ref .chan_15E4
sound_ref .chan_15F1
sound_ref .chan_1609
sound_ref .chan_1616
sound_ref .chan_162A
sound_ref .chan_1652
sound_ref .chan_1664
sound_ref .chan_16A2
sound_ref .chan_16D2
sound_ref .chan_16EF
sound_ref .chan_1702
sound_ref .chan_31D5
sound_ref .chan_320D
sound_ref .chan_3243
sound_ref .chan_3277
sound_ref .chan_32C1
sound_ref .chan_32BC
sound_ref .chan_1715
sound_ref .chan_1729
sound_ref .chan_1739
sound_ref .chan_1760
sound_ref .chan_1778
sound_ref .chan_1787
sound_ref .chan_179A
sound_ref .chan_17AD
sound_ref .chan_17C2
sound_ref .chan_17CE
sound_ref .chan_17E8
sound_ref .chan_1838
sound_ref .chan_1866
sound_ref .chan_1879
sound_ref .chan_1892
sound_ref .chan_18BE
sound_ref .chan_18D7
sound_ref .chan_18EE
sound_ref .chan_190A
sound_ref .chan_1943
sound_ref .chan_19E3
sound_ref .chan_1A03
sound_ref .chan_1A20
sound_ref .chan_1A30
sound_ref .chan_1A40
sound_ref .chan_1A43
sound_ref .chan_1A46
sound_ref .chan_1A52
sound_ref .chan_1A6F
sound_ref .chan_1A87
sound_ref .chan_1AA0
sound_ref .chan_1ACD
sound_ref .chan_1AE9
sound_ref .chan_10BE
sound_ref .chan_190A
sound_ref .chan_1943
sound_ref .chan_19E3
sound_ref .chan_1A03
sound_ref .chan_1A20
sound_ref .chan_1A30
sound_ref .chan_1A40
sound_ref .chan_1A43

.chan_10A5:
chan_setbank 5
chan_setinstr 7
chan_setlayer 0, .layer_10B6
chan_delay 0x1
chan_setbank 4
chan_setinstr 9
chan_setlayer 1, .layer_154E
chan_end

.layer_10B6:
layer_portamento 0x1, 27, 0x28
layer_note1 37, 0x7f, 120
layer_end

.chan_10BE:
chan_setbank 4
chan_setinstr 0
chan_setlayer 0, .layer_10C6
chan_end

.layer_10C6:
layer_note1 39, 0x30, 85
layer_end

.chan_10CA:
chan_setbank 3
chan_setinstr 8
chan_setenvelope .envelope_3344
chan_setlayer 0, .layer_10D5
chan_end

.layer_10D5:
layer_somethingon
layer_portamento 0x85, 34, 255
layer_note1 43, 0x8, 127
layer_note1 27, 0x7f, 127
layer_end

.chan_10E1:
chan_setbank 4
chan_setinstr 1
chan_setlayer 0, .layer_10E9
chan_end

.layer_10E9:
layer_note1 39, 0x18, 100
layer_setinstr 2
layer_note1 39, 0x48, 60
layer_end

.chan_10F2:
chan_setbank 4
chan_setinstr 1
chan_setlayer 0, .layer_10FA
chan_end

.layer_10FA:
layer_note1 37, 0x6, 100
layer_note1 34, 0x18, 100
layer_end

.chan_1101:
chan_setbank 4
chan_setinstr 4
chan_setlayer 0, .layer_1115
chan_setlayer 1, .layer_111F
chan_setval 6
chan_call .chan_fn_133
chan_setbank 4
chan_setinstr 3
chan_end

.layer_1115:
layer_delay 0xf
layer_portamento 0x81, 39, 255
layer_note1 44, 0x38, 115
layer_end

.layer_111F:
layer_portamento 0x81, 44, 255
layer_note1 34, 0x2c, 85
layer_end

.chan_1127:
chan_setbank 4
chan_setinstr 4
chan_setlayer 0, .layer_112F
chan_end

.layer_112F:
layer_note1 39, 0x30, 115
layer_end

.chan_1133:
chan_setbank 4
chan_setinstr 6
chan_setlayer 0, .layer_113B
chan_end

.layer_113B:
layer_transpose 24
layer_note1 39, 0xa, 65
layer_note1 39, 0x9, 70
layer_note1 39, 0x8, 75
layer_end

.chan_1147:
chan_setbank 4
chan_setinstr 5
chan_setlayer 0, .layer_114F
chan_end

.layer_114F:
layer_note1 39, 0x91, 127
layer_end

.chan_1154:
chan_setbank 4
chan_setinstr 5
chan_setlayer 0, .layer_115C
chan_end

.layer_115C:
layer_portamento 0x81, 27, 255
layer_note1 32, 0x60, 127
layer_end

.chan_1164:
chan_setbank 4
chan_setinstr 6
chan_setlayer 0, .layer_116C
chan_end

.layer_116C:
layer_note1 39, 0x14, 70
layer_end

.chan_1170:
chan_setbank 4
chan_setinstr 15
chan_setlayer 0, .layer_1178
chan_end

.layer_1178:
layer_note1 32, 0x18, 127
layer_portamento 0x81, 41, 255
layer_note1 27, 0x96, 127
layer_end

.chan_1184:
chan_setbank 4
chan_setinstr 6
chan_setlayer 0, .layer_118C
chan_end

.layer_118C:
layer_portamento 0x81, 34, 255
layer_note1 37, 0x18, 80
layer_end

.chan_1194:
chan_setbank 4
chan_setinstr 8
chan_setlayer 0, .layer_119C
chan_end

.layer_119C:
layer_note1 39, 0x40, 120
layer_end

.chan_11A0:
chan_setbank 5
chan_setinstr 7
chan_setlayer 0, .layer_10B6
chan_setval 1
chan_call .chan_fn_133
chan_setbank 4
chan_setinstr 9
chan_setlayer 1, .layer_11B4
chan_end

.layer_11B4:
layer_transpose 244

.layer_fn_11B6:
layer_portamento 0x83, 27, 255
layer_note0 55, 0x4, 127, 64
layer_note0 51, 0x5, 127, 64
layer_note0 48, 0x4, 127, 64
layer_note0 44, 0x6, 127, 64
layer_note0 41, 0x9, 127, 64
layer_note0 39, 0x6, 127, 64
.layer_11D2:
layer_note0 37, 0x7, 127, 64
layer_note0 34, 0x5, 127, 64
layer_note0 31, 0x8, 127, 64
layer_note0 29, 0x9, 127, 64
layer_note0 24, 0x8, 127, 64
layer_end

.chan_11E7:
chan_setbank 9
chan_setinstr 3
chan_setenvelope .envelope_3388
chan_setvibratoextent 3
chan_setvibratorate 60
chan_setval 25
chan_call .chan_fn_14C
chan_setlayer 0, .layer_11FB
chan_end

.layer_11FB:
layer_transpose 24

.layer_fn_11FD:
layer_note1 25, 0x2, 40
layer_note1 37, 0x7, 85
layer_note1 30, 0x5, 40
layer_note1 42, 0x37, 85
layer_end

.chan_120A:
chan_setbank 9
chan_setinstr 3
chan_setenvelope .envelope_3388
chan_setvibratoextent 12
chan_setval 25
chan_call .chan_fn_14C
chan_setlayer 0, .layer_1259
chan_setlayer 1, .layer_126B
chan_setval 1
chan_call .chan_fn_133
chan_setbank 4
chan_setinstr 6
chan_setval 1
chan_call .chan_fn_133
chan_setbank 9
chan_setinstr 3
chan_setenvelope .envelope_3388
chan_setval 9
chan_call .chan_fn_133
chan_setbank 4
chan_setinstr 6
chan_setval 3
chan_call .chan_fn_133
chan_setbank 9
chan_setinstr 3
chan_setenvelope .envelope_3388
chan_setval 6
chan_call .chan_fn_133
chan_setbank 4
chan_setinstr 6
chan_setval 49
chan_call .chan_fn_133
chan_setvibratoextent 0
chan_end

.layer_1259:
layer_delay 0x1
layer_setinstr 6
layer_transpose 22
layer_note1 39, 0xa, 55
layer_note1 39, 0x9, 60
layer_note1 39, 0x8, 65
layer_delay 0x29
layer_end

.layer_126B:
layer_transpose 23
layer_call .layer_fn_11FD
layer_end

.chan_1271:
chan_setbank 4
chan_setinstr 14
chan_setenvelope .envelope_342C
chan_setlayer 0, .layer_127C
chan_end

.layer_127C:
layer_portamento 0x81, 34, 127
layer_note1 38, 0x30, 127
layer_delay 0x30
layer_end

.chan_1286:
chan_setbank 4
chan_setinstr 9
chan_setlayer 0, .layer_128E
chan_end

.layer_128E:
layer_note1 37, 0xa, 100
layer_note1 26, 0x12, 120
layer_end

.chan_1295:
chan_setbank 4
chan_setinstr 10
chan_setlayer 0, .layer_129D
chan_end

.layer_129D:
layer_note1 39, 0xf, 120
layer_end

.chan_12A1:
chan_setbank 4
chan_setinstr 10
chan_setlayer 0, .layer_12A9
chan_end

.layer_12A9:
layer_note1 37, 0x12, 120
layer_end

.chan_12AD:
chan_setbank 7
chan_setinstr 1
chan_setval 25
chan_call .chan_fn_14C
chan_setlayer 0, .layer_12C6
chan_setlayer 1, .layer_12C6
chan_setval 6
chan_call .chan_fn_133
chan_setbank 4
chan_setinstr 4
chan_end

.layer_12C6:
layer_note1 43, 0x5, 127
layer_note1 62, 0x9, 127
layer_setinstr 2
layer_portamento 0x81, 27, 255
layer_note1 25, 0x5a, 108
layer_end

.chan_12D6:
chan_setbank 4
chan_setinstr 11
chan_setlayer 0, .layer_12DE
chan_end

.layer_12DE:
layer_note1 24, 0xa, 110
.layer_12E1:
layer_setinstr 5
layer_portamento 0x82, 27, 255
layer_note1 32, 0x73, 127
layer_end

.chan_12EB:
chan_setbank 4
chan_setinstr 1
chan_setenvelope .envelope_33FC
chan_setlayer 0, .layer_12F6
chan_end

.layer_12F6:
layer_somethingon
layer_note1 39, 0x4, 127
layer_portamento 0x82, 36, 255
layer_note1 27, 0x9, 115
layer_end

.chan_1302:
chan_setbank 4
chan_setinstr 2
chan_setenvelope .envelope_3484
chan_setlayer 0, .layer_1310
chan_setlayer 1, .layer_1312
chan_end

.layer_1310:
layer_transpose 3

.layer_1312:
layer_portamento 0x2, 17, 0x28
layer_note1 5, 0x60, 127
layer_end

.chan_131A:
chan_setbank 4
chan_setinstr 11
chan_setlayer 0, .layer_1322
chan_end

.layer_1322:
layer_note1 19, 0x6, 110
layer_note1 31, 0x6, 110
layer_transpose 8
layer_jump .layer_12E1

.chan_132D:
chan_setbank 4
chan_setinstr 5
chan_setlayer 0, .layer_1335
chan_end

.layer_1335:
layer_setinstr 11
layer_note1 31, 0x6, 127
layer_note1 19, 0x6, 127
layer_setinstr 5
layer_portamento 0x82, 20, 255
layer_note1 32, 0x5a, 127
layer_end

.chan_1347:
chan_setbank 4
chan_setinstr 13
chan_setlayer 0, .layer_134F
chan_end

.layer_134F:
layer_note1 39, 0x73, 95
layer_end

.chan_1353:
chan_setbank 4
chan_setinstr 14
chan_setlayer 0, .layer_135B
chan_end

.layer_135B:
layer_note1 39, 0x7f, 115
layer_end

.chan_135F:
chan_setbank 4
chan_setinstr 15
chan_setlayer 0, .layer_1367
chan_end

.layer_1367:
layer_note0 36, 0xd, 115, 20
layer_note0 34, 0xe, 115, 20
layer_note0 32, 0xd, 115, 20
layer_note0 31, 0xa, 115, 20
layer_note0 30, 0x7, 115, 20
layer_note0 29, 0x60, 115, 20
layer_end

.chan_1380:
chan_setbank 4
chan_setinstr 15
chan_setenvelope .envelope_341C
chan_setlayer 0, .layer_1392
chan_setlayer 1, .layer_138E
chan_end

.layer_138E:
layer_note1 15, 0x7f, 127
layer_end

.layer_1392:
layer_note1 55, 0x6, 115
layer_note1 43, 0xc, 115
layer_note1 34, 0x7f, 127
layer_end

.chan_139C:
chan_setbank 4
chan_setinstr 15
chan_setlayer 0, .layer_13AC
chan_setlayer 1, .layer_13B7
chan_setlayer 2, .layer_13AA
chan_end

.layer_13AA:
layer_transpose 6

.layer_13AC:
layer_note1 44, 0x7, 127
layer_note1 39, 0x8, 127
layer_note1 36, 0x96, 127
layer_end

.layer_13B7:
layer_note1 22, 0x96, 127
layer_end

.chan_13BC:
chan_setbank 9
chan_setinstr 3
chan_setval 20
chan_call .chan_fn_14C
chan_setlayer 0, .layer_13C9
chan_end

.layer_13C9:
layer_portamento 0x81, 36, 255
layer_note1 48, 0x6, 80
layer_end

.chan_13D1:
chan_setbank 4
chan_setinstr 15
chan_setenvelope .envelope_341C
chan_setlayer 0, .layer_13DF
chan_setlayer 1, .layer_13E7
chan_end

.layer_13DF:
layer_portamento 0x81, 56, 255
layer_note1 20, 0x78, 80
layer_end

.layer_13E7:
layer_note1 15, 0x78, 127
layer_end

.chan_13EB:
chan_setbank 4
chan_setinstr 6
chan_setlayer 0, .layer_13F3
chan_end

.layer_13F3:
layer_portamento 0x81, 37, 255
layer_note1 39, 0x8, 127
layer_setinstr 5
layer_portamento 0x81, 20, 255
layer_note1 25, 0x60, 127
layer_end

.chan_1404:
chan_setbank 4
chan_setinstr 2
chan_setlayer 0, .layer_140C
chan_end

.layer_140C:
layer_portamento 0x81, 12, 255
layer_note1 13, 0x6e, 127
layer_end

.chan_1414:
chan_setbank 4
chan_setinstr 2
chan_setlayer 0, .layer_141C
chan_end

.layer_141C:
layer_portamento 0x81, 15, 255
layer_note1 11, 0x6e, 127
layer_end

.chan_1424:
chan_setbank 9
chan_setinstr 3
chan_setval 40
chan_call .chan_fn_14C
chan_setlayer 0, .layer_1431
chan_end

.layer_1431:
layer_transpose 24
layer_note1 39, 0x4, 90
layer_note1 51, 0xc, 90
layer_note1 39, 0x4, 50
layer_note1 51, 0xc, 50
layer_end

.chan_1440:
chan_setbank 9
chan_setinstr 3
chan_setval 40
chan_call .chan_fn_14C
chan_setlayer 0, .layer_144D
chan_end

.layer_144D:
layer_transpose 12
layer_note1 39, 0x3, 90
layer_note1 51, 0x3, 90
layer_note1 27, 0xa, 115
layer_note1 39, 0x3, 50
layer_note1 51, 0x3, 50
layer_note1 27, 0xa, 75
layer_end

.chan_1462:
chan_setbank 4
chan_setinstr 9
chan_setval 50
chan_call .chan_fn_14C
chan_setlayer 0, .layer_147A
chan_setval 13
chan_call .chan_fn_133
chan_setdecayrelease 30
chan_setbank 4
chan_setinstr 2
chan_end

.layer_147A:
layer_note1 33, 0xc, 100
layer_note1 25, 0x28, 120
layer_portamento 0x81, 22, 255
layer_note1 15, 0x48, 80
layer_end

.chan_1488:
chan_setbank 1
chan_setinstr 1
chan_setval 15
chan_call .chan_fn_14C
chan_setlayer 0, .layer_14A1
chan_setval 1
chan_call .chan_fn_133
chan_setbank 1
chan_setinstr 7
chan_setenvelope .envelope_3398
chan_end

.layer_14A1:
layer_note1 29, 0xc, 120
layer_transpose 12
layer_portamento 0x81, 51, 255
layer_note1 53, 0x6, 118
layer_portamento 0x81, 52, 255
layer_note1 54, 0x9, 118
layer_end

.chan_14B5:
chan_setbank 7
chan_setinstr 14
chan_setval 15
chan_call .chan_fn_14C
chan_setlayer 0, .layer_14DD
chan_setlayer 1, .layer_14FA
chan_setlayer 2, .layer_14FA
chan_setval 1
chan_call .chan_fn_133
chan_setenvelope .envelope_3398
chan_setbank 1
chan_setinstr 7
chan_setval 13
chan_call .chan_fn_133
chan_setbank 7
chan_setinstr 14
chan_end

.layer_14DD:
layer_delay 0x1
layer_transpose 12
layer_portamento 0x81, 54, 255
layer_note0 55, 0x6, 118, 127
layer_portamento 0x81, 55, 255
layer_note0 56, 0x5, 118, 127
layer_portamento 0x81, 57, 255
layer_note0 58, 0xc, 118, 127
layer_end

.layer_14FA:
layer_loop 2
layer_note1 34, 0x19, 100
layer_loopend
layer_end

.chan_1501:
chan_setbank 4
chan_setinstr 9
chan_setlayer 0, .layer_1509
chan_end

.layer_1509:
layer_note0 31, 0x12, 80, 80
layer_portamento 0x82, 53, 255
layer_note1 44, 0x7, 88
layer_end

.chan_1515:
chan_setbank 3
chan_setinstr 5
chan_setenvelope .envelope_3304
chan_setval 10
chan_call .chan_fn_14C
chan_setlayer 0, .layer_1525
chan_end

.layer_1525:
layer_note1 41, 0x4, 100
layer_note0 34, 0x14, 100, 100
layer_note1 29, 0x6, 115
layer_end

.chan_1530:
chan_setval 10
chan_call .chan_fn_14C
chan_setlayer 0, .layer_1542
chan_setlayer 1, .layer_1540
chan_setbank 4
chan_setinstr 1
chan_end

.layer_1540:
layer_transpose 1

.layer_1542:
layer_note1 15, 0x2c, 127
layer_end

.chan_1546:
chan_setbank 4
chan_setinstr 9
chan_setlayer 0, .layer_1550
chan_end

.layer_154E:
layer_transpose 253

.layer_1550:
layer_note1 39, 0x6, 120
layer_portamento 0x81, 15, 255
layer_note1 8, 0xc, 120
layer_portamento 0x81, 27, 255
layer_note1 3, 0x18, 120
layer_end

.chan_1562:
chan_setbank 4
chan_setinstr 3
chan_setval 30
chan_call .chan_fn_14C
chan_setlayer 0, .layer_156F
chan_end

.layer_156F:
layer_portamento 0x81, 19, 40
layer_note1 22, 0xb4, 115
layer_end

.chan_1578:
chan_setbank 5
chan_setinstr 5
chan_setenvelope .envelope_3374
chan_setval 20
chan_call .chan_fn_14C
chan_setlayer 0, .layer_1588
chan_end

.layer_1588:
layer_note1 14, 0x34, 110
layer_delay 0x14
layer_end

.chan_158E:
chan_setbank 5
chan_setinstr 7
chan_setlayer 0, .layer_1599
chan_setlayer 1, .layer_1599
chan_end

.layer_1599:
layer_somethingon
layer_portamento 0x85, 39, 255
layer_note1 36, 0x14, 110
layer_note1 38, 0x10, 110
layer_note1 27, 0x64, 110
layer_end

.chan_15A8:
chan_setbank 4
chan_setinstr 9
chan_setlayer 0, .layer_15B0
chan_end

.layer_15B0:
layer_note0 36, 0xa, 80, 80
layer_note0 24, 0xa, 80, 80
layer_end

.chan_15B9:
chan_setbank 6
chan_setinstr 15
chan_setlayer 0, .layer_15C1
chan_end

.layer_15C1:
layer_somethingon
layer_portamento 0x85, 35, 255
layer_note1 34, 0x60, 127
layer_note1 32, 0x60, 127
layer_note1 32, 0x30, 127
layer_end

.chan_15D0:
chan_setbank 6
chan_setinstr 1
chan_setval 55
chan_call .chan_fn_14C
chan_setlayer 0, .layer_15DD
chan_end

.layer_15DD:
layer_note1 32, 0xc, 127
layer_note1 27, 0x30, 127
layer_end

.chan_15E4:
chan_setbank 6
chan_setinstr 15
chan_setlayer 0, .layer_15EC
chan_end

.layer_15EC:
layer_note1 31, 0xc0, 127
layer_end

.chan_15F1:
chan_setbank 7
chan_setinstr 1
chan_setlayer 0, .layer_1602
chan_setval 1
chan_call .chan_fn_133
chan_setbank 5
chan_setinstr 5
chan_end

.layer_1602:
layer_note1 24, 0xc, 127
layer_note1 22, 0x48, 127
layer_end

.chan_1609:
chan_setbank 6
chan_setinstr 10
chan_setlayer 0, .layer_1611
chan_end

.layer_1611:
layer_note1 44, 0xfa, 127
layer_end

.chan_1616:
chan_setbank 6
chan_setinstr 1
chan_setval 25
chan_call .chan_fn_14C
chan_setlayer 0, .layer_1623
chan_end

.layer_1623:
layer_note1 29, 0xc, 120
layer_note1 24, 0x24, 120
layer_end

.chan_162A:
chan_setbank 3
chan_setinstr 5
chan_setenvelope .envelope_3388
chan_setlayer 0, .layer_1644
chan_setlayer 1, .layer_164E
chan_setval 1
chan_call .chan_fn_133
chan_setbank 4
chan_setinstr 15
chan_setenvelope .envelope_3388
chan_end

.layer_1644:
layer_delay 0x1
layer_note1 36, 0xc, 127
layer_note1 32, 0x96, 127
layer_end

.layer_164E:
layer_note1 24, 0x60, 127
layer_end

.chan_1652:
chan_setbank 6
chan_setinstr 15
chan_setenvelope .envelope_3334
chan_setlayer 0, .layer_165D
chan_end

.layer_165D:
layer_note1 31, 0xa, 127
layer_note1 43, 0x10, 127
layer_end

.chan_1664:
chan_setbank 4
chan_setinstr 15
chan_setval 30
chan_call .chan_fn_14C
chan_setlayer 0, .layer_1677
chan_setlayer 1, .layer_1680
chan_setlayer 2, .layer_167C
chan_end

.layer_1677:
layer_note1 20, 0x226, 0
layer_end

.layer_167C:
layer_delay 0x4
layer_transpose 244

.layer_1680:
layer_note1 27, 0x4f, 93
layer_note1 28, 0x41, 99
layer_note1 29, 0x36, 101
layer_note1 30, 0x31, 109
layer_note1 36, 0xe, 113
layer_note1 38, 0x3b, 123
layer_note1 32, 0x27, 105
layer_note1 35, 0x60, 92
layer_note1 32, 0xe, 100
layer_note1 36, 0xb, 105
layer_note1 39, 0x31, 116
layer_end

.chan_16A2:
chan_setbank 4
chan_setinstr 15
chan_setval 30
chan_call .chan_fn_14C
chan_setenvelope .envelope_33BC
chan_setlayer 0, .layer_16B8
chan_setlayer 1, .layer_16C1
chan_setlayer 2, .layer_16BD
chan_end

.layer_16B8:
layer_note1 24, 0x12c, 127
layer_end

.layer_16BD:
layer_delay 0x4
layer_transpose 244

.layer_16C1:
layer_note1 46, 0xe, 116
layer_note1 44, 0xb, 121
layer_note1 48, 0x12, 101
layer_note1 41, 0xf, 109
layer_note1 43, 0xfa, 113
layer_end

.chan_16D2:
chan_setbank 5
chan_setinstr 0
chan_setval 127
chan_call .chan_fn_14C
chan_setlayer 0, .layer_16E5
chan_setlayer 1, .layer_16E5
chan_setlayer 2, .layer_16E9
chan_end

.layer_16E5:
layer_note1 49, 0x3a, 127
layer_end

.layer_16E9:
layer_delay 0xa
layer_note1 48, 0x30, 85
layer_end

.chan_16EF:
chan_setbank 6
chan_setinstr 10
chan_setenvelope .envelope_3304
chan_setlayer 0, .layer_16FA
chan_end

.layer_16FA:
layer_portamento 0x81, 51, 96
layer_note1 58, 0x40, 100
layer_end

.chan_1702:
chan_setbank 6
chan_setinstr 10
chan_setenvelope .envelope_3304
chan_setlayer 0, .layer_170D
chan_end

.layer_170D:
layer_portamento 0x82, 51, 96
layer_note1 58, 0x40, 100
layer_end

.chan_1715:
chan_setbank 6
chan_setinstr 1
chan_setval 55
chan_call .chan_fn_14C
chan_setlayer 0, .layer_1722
chan_end

.layer_1722:
layer_note1 27, 0x7, 127
layer_note1 15, 0x12, 127
layer_end

.chan_1729:
chan_setbank 4
chan_setinstr 14
chan_setlayer 0, .layer_1731
chan_end

.layer_1731:
layer_portamento 0x81, 43, 127
layer_note1 31, 0x7f, 115
layer_end

.chan_1739:
chan_setbank 9
chan_setinstr 3
chan_setenvelope .envelope_3388
chan_setlayer 0, .layer_174B
chan_setdecayrelease 50
chan_setlayer 1, .layer_1749
chan_end

.layer_1749:
layer_delay 0x4

.layer_174B:
layer_transpose 24
layer_note1 31, 0xc, 100
layer_note1 34, 0xc, 100
layer_note1 43, 0xc, 100
layer_note1 39, 0xc, 100
layer_note1 41, 0xc, 100
layer_note1 46, 0x18, 100
layer_end

.chan_1760:
chan_setbank 4
chan_setinstr 9
chan_setlayer 0, .layer_1768
chan_end

.layer_1768:
layer_call .layer_fn_176D
layer_transpose 252

.layer_fn_176D:
layer_note1 27, 0x5, 105
layer_portamento 0x81, 15, 255
layer_note1 8, 0xa, 100
layer_end

.chan_1778:
chan_setbank 4
chan_setinstr 9
chan_setlayer 0, .layer_1780
chan_end

.layer_1780:
layer_note1 8, 0x5, 127
layer_note1 18, 0x12, 127
layer_end

.chan_1787:
chan_setbank 4
chan_setinstr 9
chan_setenvelope .envelope_33EC
chan_setlayer 0, .layer_1792
chan_end

.layer_1792:
layer_portamento 0x82, 5, 255
layer_note1 8, 0xa, 127
layer_end

.chan_179A:
chan_setbank 0
chan_setinstr 0
chan_setlayer 0, .layer_17A2
chan_end

.layer_17A2:
layer_note1 44, 0x6, 100
layer_portamento 0x81, 44, 255
layer_note1 32, 0x12, 100
layer_end

.chan_17AD:
chan_setbank 9
chan_setinstr 3
chan_setenvelope .envelope_3458
chan_setlayer 0, .layer_17B8
chan_end

.layer_17B8:
layer_transpose 12
layer_portamento 0x85, 62, 255
layer_note1 38, 0x78, 93
layer_end

.chan_17C2:
chan_setbank 1
chan_setinstr 1
chan_setlayer 0, .layer_17CA
chan_end

.layer_17CA:
layer_note1 29, 0xc, 127
layer_end

.chan_17CE:
chan_setbank 4
chan_setinstr 1
chan_setlayer 0, .layer_17DB
chan_setlayer 1, .layer_17D9
chan_end

.layer_17D9:
layer_delay 0x1

.layer_17DB:
layer_note1 34, 0x6, 127
layer_note1 33, 0x7, 127
layer_note1 33, 0x6, 127
layer_note1 34, 0x6, 127
layer_end

.chan_17E8:
chan_setbank 6
chan_setenvelope .envelope_3304
chan_setlayer 0, .layer_17FF
chan_setval 1
chan_call .chan_fn_133
chan_setenvelope .envelope_3304
chan_setlayer 1, .layer_180A
chan_setlayer 2, .layer_1806
chan_end

.layer_17FF:
layer_setinstr 10
layer_transpose 24
layer_jump .layer_180C

.layer_1806:
layer_delay 0x2
layer_transpose 12

.layer_180A:
layer_setinstr 0
.layer_180C:
layer_portamento 0x83, 3, 255
layer_note1 15, 0x30, 100
layer_note1 17, 0x2c, 100
layer_note1 19, 0x28, 100
layer_note1 20, 0x24, 100
layer_note1 22, 0x20, 100
layer_note1 24, 0x1c, 100
layer_note1 26, 0x18, 100
layer_note1 27, 0x14, 100
layer_note1 29, 0x11, 100
layer_note1 31, 0xe, 100
layer_note1 32, 0xc, 100
.layer_1831:
layer_note1 34, 0xa, 100
layer_jump .layer_1831
layer_end

.chan_1838:
chan_setbank 4
chan_setinstr 14
chan_setlayer 0, .layer_1731
chan_setval 1
chan_call .chan_fn_133
chan_setbank 4
chan_setinstr 15
chan_setenvelope .envelope_341C
chan_setlayer 1, .layer_1392
chan_setval 100
chan_call .chan_fn_133
chan_setbank 4
chan_setinstr 14
chan_setlayer 0, .layer_185B
chan_end

.layer_185B:
layer_transpose 250
layer_portamento 0x81, 43, 127
layer_note1 31, 0xfa, 115
layer_end

.chan_1866:
chan_setbank 4
chan_setinstr 15
chan_setlayer 0, .layer_1873
chan_setlayer 1, .layer_1871
chan_end

.layer_1871:
layer_transpose 2

.layer_1873:
layer_note1 39, 0xc, 127
layer_jump .layer_1367

.chan_1879:
chan_setbank 4
chan_setinstr 14
chan_setlayer 0, .layer_1881
chan_end

.layer_1881:
layer_portamento 0x83, 39, 128
layer_note1 42, 0x2d, 115
layer_note1 42, 0x2d, 115
layer_note1 42, 0x2d, 115
layer_note1 44, 0x7f, 115
layer_end

.chan_1892:
chan_setbank 9
chan_setinstr 3
chan_setval 30
chan_call .chan_fn_14C
chan_setlayer 0, .layer_189F
chan_end

.layer_189F:
layer_transpose 12
layer_portamento 0x83, 3, 255
layer_note1 27, 0xa, 85
layer_note1 32, 0xa, 85
layer_note1 39, 0xa, 85
layer_note1 44, 0xa, 85
layer_note1 51, 0xa, 85
layer_note1 56, 0xa, 85
layer_note1 51, 0xa, 45
layer_note1 56, 0xa, 35
layer_end

.chan_18BE:
chan_setbank 5
chan_setinstr 7
chan_setlayer 0, .layer_18CF
chan_delay 0x1
chan_setbank 4
chan_setinstr 9
chan_setlayer 1, .layer_154E
chan_end

.layer_18CF:
layer_portamento 0x1, 27, 0x28
layer_note1 32, 0x32, 120
layer_end

.chan_18D7:
chan_setbank 6
chan_setinstr 11
chan_setlayer 0, .layer_2DE9
chan_setval 9
chan_call .chan_fn_133
chan_setbank 9
chan_setinstr 3
chan_setenvelope .envelope_3484
chan_setlayer 0, .layer_2D4B
chan_end

.chan_18EE:
chan_setbank 4
chan_setinstr 9
chan_setlayer 0, .layer_1550
chan_setval 12
chan_call .chan_fn_133
chan_setbank 6
chan_setinstr 1
chan_setlayer 0, .layer_1902
chan_end

.layer_1902:
layer_portamento 0x82, 15, 255
layer_note1 31, 0x14, 127
layer_end

.chan_190A:
chan_setbank 9
chan_setinstr 3
chan_setenvelope .envelope_33A8
chan_setlayer 0, .layer_1920
chan_setlayer 1, .layer_191B
chan_setlayer 2, .layer_1922
chan_end

.layer_191B:
layer_transpose 7
layer_jump .layer_1924

.layer_1920:
layer_delay 0x6

.layer_1922:
layer_transpose 12
.layer_1924:
layer_note0 46, 0xc, 90, 20
layer_note0 45, 0xc, 90, 20
layer_note0 46, 0xc, 90, 20
layer_note0 58, 0x10, 100, 80
layer_note0 58, 0x10, 60, 80
layer_note0 58, 0x10, 40, 80
layer_note0 58, 0x10, 25, 80
layer_delay 0xa
layer_end

.chan_1943:
chan_setbank 5
chan_setinstr 13
chan_setenvelope .envelope_340C
chan_setval 20
chan_call .chan_fn_14C
chan_setval 127
chan_iowriteval 7
chan_setlayer 0, .layer_1978
chan_setlayer 1, .layer_199F
chan_setlayer 2, .layer_199B
.chan_195B:
chan_setval 4
chan_call .chan_fn_133
chan_ioreadval 7
chan_subtract 1
chan_beqz .chan_1970
chan_iowriteval 7
chan_writeseq_nextinstr 0, 1
chan_setvolscale 127
chan_jump .chan_195B
.chan_1970:
chan_setval 127
chan_call .chan_fn_133
chan_jump .chan_1970

.layer_1978:
layer_setinstr 9
layer_note1 40, 0x6, 122
layer_note1 41, 0x4, 112
layer_note1 43, 0x5, 109
layer_note1 44, 0x6, 124
layer_note1 44, 0x4, 116
layer_note1 45, 0x7, 114
layer_delay 0x19
.layer_198E:
layer_note1 43, 0x7f, 122
layer_note1 43, 0xa, 127
layer_note1 43, 0x64, 114
layer_jump .layer_198E
layer_end

.layer_199B:
layer_transpose 4
layer_delay 0x2

.layer_199F:
layer_portamento 0x83, 39, 255
layer_loop 2
layer_note1 55, 0x6, 120
layer_note1 60, 0x9, 112
layer_delay 0x4
layer_loopend
layer_note1 56, 0x5, 125
layer_note1 62, 0xa, 109
layer_delay 0x5
layer_note1 56, 0x6, 123
layer_note1 62, 0x7, 119
layer_delay 0x8
.layer_19BE:
layer_loop 10
layer_note1 57, 0x5, 120
layer_note1 62, 0x8, 120
layer_delay 0x5
layer_loopend
layer_loop 10
layer_note1 59, 0x7, 115
layer_note1 60, 0x7, 113
layer_delay 0x2
layer_loopend
layer_loop 10
layer_note1 55, 0x8, 115
layer_note1 58, 0x6, 113
layer_delay 0x5
layer_loopend
layer_jump .layer_19BE
layer_end

.chan_19E3:
chan_setbank 9
chan_setinstr 3
chan_setval 40
chan_call .chan_fn_14C
chan_setenvelope .envelope_3374
chan_setlayer 0, .layer_19F3
chan_end

.layer_19F3:
layer_loop 2
layer_note1 62, 0x6, 110
layer_note1 62, 0x2, 45
layer_note1 58, 0x6, 110
layer_note1 58, 0x2, 45
layer_loopend
layer_end

.chan_1A03:
chan_setbank 7
chan_setinstr 1
chan_setlayer 0, .layer_1A19
chan_setlayer 1, .layer_1A17
chan_setval 1
chan_call .chan_fn_133
chan_setbank 5
chan_setinstr 5
chan_end

.layer_1A17:
layer_transpose 250

.layer_1A19:
layer_note1 15, 0xc, 127
layer_note1 17, 0x3a, 127
layer_end

.chan_1A20:
chan_setbank 5
chan_setinstr 14
chan_setlayer 0, .layer_1A28
chan_end

.layer_1A28:
layer_portamento 0x82, 40, 127
layer_note1 38, 0x28, 100
layer_end

.chan_1A30:
chan_setbank 5
chan_setinstr 14
chan_setlayer 0, .layer_1A38
chan_end

.layer_1A38:
layer_portamento 0x82, 43, 127
layer_note1 39, 0x36, 100
layer_end

.chan_1A40:
chan_jump .chan_23AA

.chan_1A43:
chan_jump .chan_2318

.chan_1A46:
chan_setbank 0
chan_setinstr 3
chan_setlayer 0, .layer_1A4E
chan_end

.layer_1A4E:
layer_note1 39, 0x32, 127
layer_end

.chan_1A52:
chan_setbank 6
chan_setinstr 2
chan_setlayer 0, .layer_1A5D
chan_setlayer 1, .layer_1A5D
chan_end

.layer_1A5D:
layer_transpose 7
layer_call .layer_fn_1A64
layer_transpose 254

.layer_fn_1A64:
layer_portamento 0x83, 31, 255
layer_note1 51, 0x6, 127
layer_note1 56, 0xc, 127
layer_end

.chan_1A6F:
chan_setbank 9
chan_setinstr 6
chan_setval 10
chan_call .chan_fn_14C
chan_setlayer 0, .layer_1A7F
chan_setlayer 1, .layer_1A7F
chan_end

.layer_1A7F:
layer_portamento 0x82, 39, 255
layer_note1 31, 0x60, 100
layer_end

.chan_1A87:
chan_setbank 4
chan_setinstr 14
chan_setlayer 0, .layer_1A92
chan_setlayer 1, .layer_1A96
chan_end

.layer_1A92:
layer_transpose 3
layer_delay 0x5

.layer_1A96:
layer_somethingon
layer_portamento 0x85, 31, 255
layer_note1 34, 0x12c, 127
layer_end

.chan_1AA0:
chan_setbank 4
chan_setinstr 14
chan_setenvelope .envelope_3388
chan_setlayer 0, .layer_1AB9
chan_setval 1
chan_call .chan_fn_133
chan_setenvelope .envelope_3388
chan_setlayer 1, .layer_1AC3
chan_setlayer 2, .layer_1AC1
chan_end

.layer_1AB9:
layer_portamento 0x81, 32, 64
layer_note1 38, 0x46, 127
layer_end

.layer_1AC1:
layer_delay 0x4

.layer_1AC3:
layer_delay 0x4
layer_portamento 0x81, 36, 40
layer_note1 41, 0xc, 127
layer_end

.chan_1ACD:
chan_setbank 4
chan_setinstr 2
chan_setlayer 0, .layer_1ADA
chan_setlayer 1, .layer_1AD8
chan_end

.layer_1AD8:
layer_transpose 12

.layer_1ADA:
layer_portamento 0x81, 7, 255
layer_note1 15, 0x3c, 127
layer_portamento 0x81, 20, 200
layer_note1 7, 0x5a, 127
layer_end

.chan_1AE9:
chan_setbank 9
chan_setinstr 3
chan_setvibratoextent 70
chan_setvibratorate 70
chan_setenvelope .envelope_3314
chan_setlayer 0, .layer_1B04
chan_setlayer 1, .layer_1B02
chan_setval 35
chan_call .chan_fn_133
chan_setvibratoextent 0
chan_end

.layer_1B02:
layer_transpose 1

.layer_1B04:
layer_portamento 0x81, 19, 255
layer_note1 31, 0x32, 115
layer_end

.table_1B0C:
sound_ref .chan_1B5C
sound_ref .chan_1B5C
sound_ref .chan_1B76
sound_ref .chan_1B86
sound_ref .chan_1B86
sound_ref .chan_1B96
sound_ref .chan_1BE6
sound_ref .chan_1BFE
sound_ref .chan_1C18
sound_ref .chan_1C28
sound_ref .chan_1C5F
sound_ref .chan_1C78
sound_ref .chan_1C8B
sound_ref .chan_1CD4
sound_ref .chan_1CE6
sound_ref .chan_1D03
sound_ref .chan_1D1D
sound_ref .chan_2A30
sound_ref .chan_1D5B
sound_ref .chan_1D73
sound_ref .chan_1D88
sound_ref .chan_1D9A
sound_ref .chan_1DD1
sound_ref .chan_1E18
sound_ref .chan_1E33
sound_ref .chan_1E4E
sound_ref .chan_1B76
sound_ref .chan_1B86
sound_ref .chan_1B5C
sound_ref .chan_1B5C
sound_ref .chan_1B5C
sound_ref .chan_1B5C
sound_ref .chan_10BE
sound_ref .chan_1787
sound_ref .chan_1B76
sound_ref .chan_1B86
sound_ref .chan_1B5C
sound_ref .chan_1B5C
sound_ref .chan_1B5C
sound_ref .chan_1B5C

.chan_1B5C:
chan_setbank 5
chan_setinstr 1
chan_setval 25
chan_call .chan_fn_14C
chan_setenvelope .envelope_32F4
chan_setlayer 0, .layer_1B6C
chan_end

.layer_1B6C:
layer_somethingon
layer_delay 0x4
.layer_1B6F:
layer_note1 41, 0x12c, 95
layer_jump .layer_1B6F

.chan_1B76:
chan_setbank 5
chan_setinstr 2
chan_setlayer 0, .layer_1B7E
chan_end

.layer_1B7E:
layer_somethingon
.layer_1B7F:
layer_note1 39, 0x12c, 90
layer_jump .layer_1B7F

.chan_1B86:
chan_setbank 5
chan_setinstr 3
chan_setlayer 0, .layer_1B8E
chan_end

.layer_1B8E:
layer_somethingon
.layer_1B8F:
layer_note1 44, 0x12c, 105
layer_jump .layer_1B8F

.chan_1B96:
chan_setbank 5
chan_setinstr 6
chan_setdecayrelease 13
chan_setlayer 0, .layer_1BA3
chan_setlayer 1, .layer_1BA5
chan_end

.layer_1BA3:
layer_transpose 244

.layer_1BA5:
layer_somethingon
layer_portamento 0x85, 39, 255
.layer_1BAA:
layer_note1 44, 0x18, 110
layer_note1 38, 0x3c, 110
layer_note1 47, 0xa, 110
layer_note1 49, 0x32, 110
layer_note1 40, 0x4b, 110
layer_note1 37, 0x14, 110
layer_note1 46, 0xc, 110
layer_note1 48, 0x1f, 110
layer_note1 55, 0x18, 110
layer_note1 46, 0x40, 110
layer_note1 36, 0xc, 110
layer_note1 39, 0xa, 110
layer_note1 36, 0xe, 110
layer_note1 39, 0xc, 110
layer_note1 32, 0x54, 110
layer_note1 39, 0xa, 110
layer_note1 36, 0x2b, 110
layer_note1 41, 0x60, 110
layer_note1 39, 0x22, 110
layer_jump .layer_1BAA

.chan_1BE6:
chan_setbank 3
chan_setinstr 2
chan_setlayer 0, .layer_1BEE
chan_end

.layer_1BEE:
layer_somethingon
layer_portamento 0x85, 36, 255
.layer_1BF3:
layer_note1 34, 0x12c, 95
layer_note1 36, 0x12c, 95
layer_jump .layer_1BF3

.chan_1BFE:
chan_setbank 6
chan_setinstr 15
chan_setlayer 0, .layer_1C06
chan_end

.layer_1C06:
layer_somethingon
layer_note1 43, 0xc, 127
layer_portamento 0x81, 44, 255
layer_note1 43, 0x50, 127
.layer_1C11:
layer_note1 43, 0x12c, 127
layer_jump .layer_1C11

.chan_1C18:
chan_setbank 5
chan_setinstr 2
chan_setlayer 0, .layer_1C20
chan_end

.layer_1C20:
layer_somethingon
.layer_1C21:
layer_note1 27, 0x12c, 100
layer_jump .layer_1C21

.chan_1C28:
chan_setbank 4
chan_setinstr 5
chan_setenvelope .envelope_3314
chan_setdecayrelease 25
chan_setlayer 0, .layer_1C35
chan_end

.layer_1C35:
layer_transpose 6
layer_portamento 0x85, 39, 255
.layer_1C3B:
layer_note1 39, 0x18, 127
layer_note1 31, 0x36, 127
layer_note1 43, 0xc, 127
layer_note1 36, 0x32, 127
layer_note1 27, 0x50, 127
layer_note1 36, 0x37, 127
layer_note1 34, 0x40, 127
layer_note1 32, 0x3d, 127
layer_note1 29, 0x4a, 127
layer_note1 32, 0x31, 127
layer_note1 38, 0x1f, 127
layer_jump .layer_1C3B

.chan_1C5F:
chan_setbank 6
chan_setinstr 15
chan_setlayer 0, .layer_1C67
chan_end

.layer_1C67:
layer_somethingon
layer_portamento 0x85, 39, 255
layer_note1 42, 0x3c, 127
.layer_1C6F:
layer_note1 41, 0x3c, 127
layer_note1 42, 0x3c, 127
layer_jump .layer_1C6F

.chan_1C78:
chan_setbank 4
chan_setinstr 2
chan_setdecayrelease 30
chan_setlayer 0, .layer_1C82
chan_end

.layer_1C82:
layer_portamento 0x81, 15, 255
layer_note1 11, 0x1f4, 127
layer_end

.chan_1C8B:
chan_setbank 5
chan_setinstr 5
chan_setenvelope .envelope_3398
chan_setval 45
chan_call .chan_fn_14C
chan_setlayer 0, .layer_1C9B
chan_end

.layer_1C9B:
layer_call .layer_fn_1CBC
layer_delay 0xb
layer_call .layer_fn_1CBC
layer_delay 0x9
layer_call .layer_fn_1CBC
layer_delay 0x8
layer_call .layer_fn_1CBC
layer_delay 0x6
layer_call .layer_fn_1CBC
layer_delay 0x5
.layer_1CB4:
layer_call .layer_fn_1CBC
layer_delay 0x3
layer_jump .layer_1CB4

.layer_fn_1CBC:
layer_transpose 0
layer_setinstr 4
layer_note1 22, 0x6, 127
layer_transpose 36
layer_setinstr 5
layer_somethingon
layer_portamento 0x85, 51, 255
layer_note1 41, 0x5, 77
layer_delay 0x4
layer_disableportamento
layer_somethingoff
layer_end

.chan_1CD4:
chan_setbank 4
chan_setinstr 2
chan_setlayer 0, .layer_1CDC
chan_end

.layer_1CDC:
layer_portamento 0x81, 19, 10
layer_note1 8, 0x9, 127
layer_jump .layer_1CDC

.chan_1CE6:
chan_setbank 3
chan_setinstr 7
chan_setdecayrelease 5
chan_setlayer 0, .layer_1CFB
chan_setlayer 1, .layer_1CF3
chan_end

.layer_1CF3:
layer_somethingon
.layer_1CF4:
layer_note1 47, 0x1f4, 90
layer_jump .layer_1CF4

.layer_1CFB:
layer_somethingon
.layer_1CFC:
layer_note1 46, 0x1f4, 90
layer_jump .layer_1CFC

.chan_1D03:
chan_setbank 4
chan_setinstr 2
chan_setdecayrelease 30
chan_setlayer 0, .layer_1D12
chan_setlayer 1, .layer_1D10
chan_end

.layer_1D10:
layer_transpose 6

.layer_1D12:
layer_portamento 0x85, 7, 255
layer_note1_long 13, 0x46, 120
layer_jump .layer_1D12

.chan_1D1D:
chan_setbank 5
chan_setinstr 6
chan_setdecayrelease 13
chan_setlayer 0, .layer_1D2A
chan_setlayer 1, .layer_1D2C
chan_end

.layer_1D2A:
layer_transpose 250

.layer_1D2C:
layer_somethingon
layer_portamento 0x85, 34, 255
.layer_1D31:
layer_note1 51, 0x18, 110
layer_note1 43, 0x63, 110
layer_note1 47, 0xa, 110
layer_note1 49, 0x32, 110
layer_note1 41, 0x4b, 110
layer_note1 46, 0xc, 110
layer_note1 48, 0x1f, 110
layer_note1 55, 0x7f, 110
layer_note1 46, 0x63, 110
layer_note1 43, 0xa, 110
layer_note1 39, 0xc, 110
layer_note1 41, 0x60, 110
layer_note1 39, 0x22, 110
layer_jump .layer_1D31

.chan_1D5B:
chan_setbank 4
chan_setinstr 2
chan_setbank 6
chan_setenvelope .envelope_3344
chan_setdecayrelease 200
chan_setlayer 0, .layer_1D6A
chan_end

.layer_1D6A:
layer_transpose 3
.layer_1D6C:
layer_note0 62, 0x2, 127, 127
layer_jump .layer_1D6C

.chan_1D73:
chan_setbank 3
chan_setinstr 1
chan_setenvelope .envelope_3314
chan_setdecayrelease 15
chan_setlayer 0, .layer_1D80
chan_end

.layer_1D80:
layer_somethingon
.layer_1D81:
layer_note1 44, 0x12c, 95
layer_jump .layer_1D81

.chan_1D88:
chan_setbank 4
chan_setinstr 14
chan_setlayer 0, .layer_1D90
chan_end

.layer_1D90:
layer_portamento 0x81, 38, 127
layer_note1 39, 0x9, 127
layer_jump .layer_1D90

.chan_1D9A:
chan_setval 50
chan_call .chan_fn_14C
chan_setbank 4
chan_setinstr 15
chan_setlayer 0, .layer_1DBE
chan_setval 1
chan_call .chan_fn_133
chan_setbank 6
chan_setinstr 15
chan_setlayer 1, .layer_1DC6
chan_setval 1
chan_call .chan_fn_133
chan_setbank 4
chan_setinstr 15
chan_setdecayrelease 10
chan_end

.layer_1DBE:
layer_note1 21, 0xc, 127
layer_note1 18, 0x226, 127
layer_end

.layer_1DC6:
layer_transpose 24
layer_portamento 0x82, 19, 255
layer_note1 20, 0x1f4, 127
layer_end

.chan_1DD1:
chan_setbank 3
chan_setinstr 2
chan_setenvelope .envelope_3314
chan_setlayer 0, .layer_1DED
chan_setval 1
chan_call .chan_fn_133
chan_setbank 4
chan_setinstr 5
chan_setdecayrelease 20
chan_setlayer 1, .layer_1DFD
chan_setlayer 2, .layer_1DFB
chan_end

.layer_1DED:
layer_transpose 244
layer_somethingon
layer_portamento 0x82, 39, 255
.layer_1DF4:
layer_note1 46, 0x2710, 80
layer_jump .layer_1DF4

.layer_1DFB:
layer_transpose 6

.layer_1DFD:
layer_portamento 0x83, 20, 255
layer_note1 15, 0x5a, 127
layer_note1 32, 0x2d, 127
layer_note1 29, 0x46, 127
layer_note1 24, 0x78, 127
layer_note1 32, 0x44, 127
layer_note1 24, 0x74, 127
layer_transpose 7
layer_jump .layer_1DFD

.chan_1E18:
chan_setbank 6
chan_setinstr 1
chan_setlayer 0, .layer_1E25
chan_setlayer 1, .layer_1E2B
chan_setdecayrelease 127
chan_end

.layer_1E25:
layer_note1 24, 0xc, 85
layer_jump .layer_1E25

.layer_1E2B:
layer_setinstr 15
.layer_1E2D:
layer_note1 39, 0x10, 115
layer_jump .layer_1E2D

.chan_1E33:
chan_setbank 3
chan_setinstr 6
chan_setenvelope .envelope_3314
chan_setlayer 0, .layer_1E41
chan_setlayer 1, .layer_1E41
chan_end

.layer_1E41:
layer_portamento 0x81, 38, 80
layer_somethingon
.layer_1E46:
layer_note1 35, 0x12c, 100
layer_jump .layer_1E46
layer_end

.chan_1E4E:
chan_setbank 5
chan_setinstr 15
chan_setenvelope .envelope_3314
chan_setdecayrelease 8
chan_setlayer 0, .layer_1E5B
chan_end

.layer_1E5B:
layer_somethingon
layer_portamento 0x82, 20, 255
.layer_1E60:
layer_note1 43, 0x1b58, 63
layer_jump .layer_1E60

.table_1E67:
sound_ref .chan_1154
sound_ref .chan_1F7A
sound_ref .chan_1F96
sound_ref .chan_1FA6
sound_ref .chan_1FC5
sound_ref .chan_1FDD
sound_ref .chan_1FF9
sound_ref .chan_200B
sound_ref .chan_2017
sound_ref .chan_2023
sound_ref .chan_2033
sound_ref .chan_203F
sound_ref .chan_204E
sound_ref .chan_2072
sound_ref .chan_207F
sound_ref .chan_208C
sound_ref .chan_2098
sound_ref .chan_20B3
sound_ref .chan_20BF
sound_ref .chan_20CB
sound_ref .chan_20D7
sound_ref .chan_20E3
sound_ref .chan_20F5
sound_ref .chan_2114
sound_ref .chan_2120
sound_ref .chan_2147
sound_ref .chan_2153
sound_ref .chan_215F
sound_ref .chan_2171
sound_ref .chan_2190
sound_ref .chan_21A7
sound_ref .chan_21BA
sound_ref .chan_21D1
sound_ref .chan_21EF
sound_ref .chan_21FD
sound_ref .chan_2218
sound_ref .chan_222A
sound_ref .chan_223D
sound_ref .chan_224E
sound_ref .chan_2261
sound_ref .chan_2279
sound_ref .chan_2290
sound_ref .chan_22AC
sound_ref .chan_22BE
sound_ref .chan_22D0
sound_ref .chan_22EB
sound_ref .chan_22FF
sound_ref .chan_2318
sound_ref .chan_233A
sound_ref .chan_2356
sound_ref .chan_237A
sound_ref .chan_2397
sound_ref .chan_23AA
sound_ref .chan_23BB
sound_ref .chan_23C9
sound_ref .chan_23D9
sound_ref .chan_23F8
sound_ref .chan_2411
sound_ref .chan_2421
sound_ref .chan_2438
sound_ref .chan_2448
sound_ref .chan_245A
sound_ref .chan_2472
sound_ref .chan_2487
sound_ref .chan_249B
sound_ref .chan_24AB
sound_ref .chan_24D3
sound_ref .chan_24ED
sound_ref .chan_24FB
sound_ref .chan_250B
sound_ref .chan_2521
sound_ref .chan_2531
sound_ref .chan_254A
sound_ref .chan_255B
sound_ref .chan_256B
sound_ref .chan_2589
sound_ref .chan_2599
sound_ref .chan_25C0
sound_ref .chan_25D4
sound_ref .chan_25F4
sound_ref .chan_31D5
sound_ref .chan_320D
sound_ref .chan_3243
sound_ref .chan_3277
sound_ref .chan_2617
sound_ref .chan_262A
sound_ref .chan_263D
sound_ref .chan_2676
sound_ref .chan_268A
sound_ref .chan_26C2
sound_ref .chan_26D5
sound_ref .chan_26E8
sound_ref .chan_26F8
sound_ref .chan_2713
sound_ref .chan_278A
sound_ref .chan_2723
sound_ref .chan_273F
sound_ref .chan_274F
sound_ref .chan_276A
sound_ref .chan_277A
sound_ref .chan_279A
sound_ref .chan_27A1
sound_ref .chan_27B5
sound_ref .chan_27D4
sound_ref .chan_27F5
sound_ref .chan_2802
sound_ref .chan_2815
sound_ref .chan_2829
sound_ref .chan_2840
sound_ref .chan_285F
sound_ref .chan_287E
sound_ref .chan_28A9
sound_ref .chan_28E0
sound_ref .chan_28FC
sound_ref .chan_2917
sound_ref .chan_293B
sound_ref .chan_295B
sound_ref .chan_1FDD
sound_ref .chan_1FF9
sound_ref .chan_200B
sound_ref .chan_249B
sound_ref .chan_24AB
sound_ref .chan_1F96
sound_ref .chan_1FA6
sound_ref .chan_1FC5
sound_ref .chan_1FDD
sound_ref .chan_1FF9
sound_ref .chan_200B

.chan_1F67:
chan_setbank 6
chan_setinstr 5
chan_setlayer 0, .layer_1F6F
chan_end

.layer_1F6F:
layer_note1 27, 0x8, 90
layer_portamento 0x81, 43, 255
layer_note1 27, 0x21, 90
layer_end

.chan_1F7A:
chan_setbank 7
chan_setinstr 3
chan_setlayer 0, .layer_1F8B
chan_setval 1
chan_call .chan_fn_133
chan_setbank 6
chan_setinstr 0
chan_end

.layer_1F8B:
layer_note1 43, 0xf, 90
layer_portamento 0x82, 27, 255
layer_note1 36, 0xb, 90
layer_end

.chan_1F96:
chan_setbank 6
chan_setinstr 7
chan_setlayer 0, .layer_1F9E
chan_end

.layer_1F9E:
layer_portamento 0x81, 43, 255
layer_note1 48, 0x30, 110
layer_end

.chan_1FA6:
chan_setbank 6
chan_setinstr 1
chan_setval 60
chan_call .chan_fn_14C
chan_setlayer 0, .layer_1FB6
chan_setlayer 1, .layer_1FBF
chan_end

.layer_1FB6:
layer_note1 36, 0x8, 120
layer_note1 35, 0x28, 120
layer_delay 0x30
layer_end

.layer_1FBF:
layer_delay 0x18
layer_note1 0, 0x1e, 95
layer_end

.chan_1FC5:
chan_setbank 6
chan_setinstr 2
chan_setval 10
chan_call .chan_fn_14C
chan_setlayer 0, .layer_1FD9
chan_setlayer 1, .layer_1FD5
chan_end

.layer_1FD5:
layer_delay 0x3
layer_transpose 5

.layer_1FD9:
layer_note1 39, 0x7f, 127
layer_end

.chan_1FDD:
chan_setbank 6
chan_setinstr 2
chan_setval 10
chan_call .chan_fn_14C
chan_setlayer 0, .layer_1FF1
chan_setlayer 1, .layer_1FED
chan_end

.layer_1FED:
layer_delay 0x3
layer_transpose 5

.layer_1FF1:
layer_portamento 0x81, 45, 255
layer_note1 33, 0x30, 127
layer_end

.chan_1FF9:
chan_setbank 6
chan_setinstr 4
chan_setval 10
chan_call .chan_fn_14C
chan_setlayer 0, .layer_2006
chan_end

.layer_2006:
layer_note1 32, 0x104, 127
layer_end

.chan_200B:
chan_setbank 6
chan_setinstr 5
chan_setlayer 0, .layer_2013
chan_end

.layer_2013:
layer_note1 32, 0x28, 127
layer_end

.chan_2017:
chan_setbank 6
chan_setinstr 6
chan_setlayer 0, .layer_201F
chan_end

.layer_201F:
layer_note1 36, 0x5a, 127
layer_end

.chan_2023:
chan_setbank 6
chan_setinstr 7
chan_setlayer 0, .layer_202B
chan_end

.layer_202B:
layer_portamento 0x81, 39, 255
layer_note1 36, 0x26, 100
layer_end

.chan_2033:
chan_setbank 6
chan_setinstr 8
chan_setlayer 0, .layer_203B
chan_end

.layer_203B:
layer_note1 39, 0x18, 127
layer_end

.chan_203F:
chan_setbank 6
chan_setinstr 9
chan_setlayer 0, .layer_2047
chan_end

.layer_2047:
layer_note1 50, 0xa, 127
layer_note1 55, 0xa, 127
layer_end

.chan_204E:
chan_setbank 7
chan_setinstr 12
chan_setval 55
chan_call .chan_fn_14C
chan_setlayer 0, .layer_206E
chan_setval 1
chan_call .chan_fn_133
chan_setbank 6
chan_setinstr 1
chan_setlayer 1, .layer_2067
chan_end

.layer_2067:
layer_note1 37, 0xc, 127
layer_note1 31, 0x1e, 127
layer_end

.layer_206E:
layer_note1 31, 0x2a, 127
layer_end

.chan_2072:
chan_setbank 6
chan_setinstr 10
chan_setlayer 0, .layer_207A
chan_end

.layer_207A:
layer_note1 39, 0xd2, 127
layer_end

.chan_207F:
chan_setbank 6
chan_setinstr 11
chan_setlayer 0, .layer_2087
chan_end

.layer_2087:
layer_note1 39, 0xd2, 127
layer_end

.chan_208C:
chan_setbank 6
chan_setinstr 12
chan_setlayer 0, .layer_2094
chan_end

.layer_2094:
layer_note1 39, 0x24, 127
layer_end

.chan_2098:
chan_setbank 6
chan_setinstr 11
chan_setlayer 0, .layer_20A0
chan_end

.layer_20A0:
layer_portamento 0x81, 33, 255
layer_note1 57, 0x4, 127
layer_transpose 252
layer_portamento 0x81, 57, 255
layer_note1 33, 0x6, 127
layer_delay 0x14
layer_end

.chan_20B3:
chan_setbank 6
chan_setinstr 14
chan_setlayer 0, .layer_20BB
chan_end

.layer_20BB:
layer_note1 39, 0x48, 110
layer_end

.chan_20BF:
chan_setbank 4
chan_setinstr 5
chan_setlayer 0, .layer_20C7
chan_end

.layer_20C7:
layer_note1 59, 0x24, 105
layer_end

.chan_20CB:
chan_setbank 6
chan_setinstr 15
chan_setlayer 0, .layer_20D3
chan_end

.layer_20D3:
layer_note1 39, 0x4c, 127
layer_end

.chan_20D7:
chan_setbank 7
chan_setinstr 0
chan_setlayer 0, .layer_20DF
chan_end

.layer_20DF:
layer_note1 39, 0x18, 105
layer_end

.chan_20E3:
chan_setbank 6
chan_setinstr 1
chan_setlayer 0, .layer_20EB
chan_end

.layer_20EB:
layer_portamento 0x81, 44, 255
layer_note1 36, 0x18, 115
layer_delay 0x32
layer_end

.chan_20F5:
chan_setbank 7
chan_setinstr 12
chan_setlayer 0, .layer_2109
chan_setval 1
chan_call .chan_fn_133
chan_setbank 6
chan_setinstr 1
chan_setlayer 1, .layer_210D
chan_end

.layer_2109:
layer_note1 31, 0x26, 127
layer_end

.layer_210D:
layer_note1 38, 0x8, 127
layer_note1 33, 0x1e, 127
layer_end

.chan_2114:
chan_setbank 7
chan_setinstr 1
chan_setlayer 0, .layer_211C
chan_end

.layer_211C:
layer_note1 39, 0x24, 120
layer_end

.chan_2120:
chan_setbank 4
chan_setinstr 15
chan_setenvelope .envelope_341C
chan_setlayer 0, .layer_2135
chan_setlayer 1, .layer_213F
chan_setlayer 2, .layer_213D
chan_setval 1
chan_setdecayrelease 10
chan_end

.layer_2135:
layer_portamento 0x81, 51, 255
layer_note1 20, 0x2e, 115
layer_end

.layer_213D:
layer_transpose 3

.layer_213F:
layer_setinstr 5
layer_delay 0xa
layer_note1 48, 0x23, 127
layer_end

.chan_2147:
chan_setbank 7
chan_setinstr 2
chan_setlayer 0, .layer_214F
chan_end

.layer_214F:
layer_note1 39, 0xc, 105
layer_end

.chan_2153:
chan_setbank 7
chan_setinstr 3
chan_setlayer 0, .layer_215B
chan_end

.layer_215B:
layer_note1 39, 0x68, 127
layer_end

.chan_215F:
chan_setbank 7
chan_setinstr 3
chan_setlayer 0, .layer_2167
chan_end

.layer_2167:
layer_portamento 0x82, 38, 127
layer_note1 51, 0x4, 80
layer_delay 0x1e
layer_end

.chan_2171:
chan_setbank 7
chan_setinstr 12
chan_setlayer 0, .layer_2179
chan_end

.layer_2179:
layer_portamento 0x83, 33, 255
layer_note0 40, 0xf, 127, 127
layer_note1 26, 0x20, 127
layer_end

.layer_unused_2185:
layer_portamento 0x83, 27, 255
layer_note1 22, 0x9, 127
layer_note1 24, 0x1c, 127
layer_end

.chan_2190:
chan_setbank 7
chan_setinstr 3
chan_setlayer 0, .layer_2198
chan_end

.layer_2198:
layer_portamento 0x81, 27, 255
layer_note1 48, 0x9, 100
layer_portamento 0x81, 27, 255
layer_note1 48, 0x5, 100
layer_end

.chan_21A7:
chan_setbank 6
chan_setinstr 5
chan_setlayer 0, .layer_21AF
chan_end

.layer_21AF:
layer_note1 36, 0x8, 90
layer_portamento 0x81, 43, 255
layer_note1 27, 0x14, 90
layer_end

.chan_21BA:
chan_setbank 6
chan_setinstr 7
chan_setlayer 0, .layer_21C2
chan_end

.layer_21C2:
layer_portamento 0x81, 39, 255
layer_note1 44, 0xc, 110
layer_portamento 0x81, 46, 255
layer_note1 58, 0x30, 110
layer_end

.chan_21D1:
chan_setbank 6
chan_setinstr 12
chan_setlayer 0, .layer_21E2
chan_setval 1
chan_call .chan_fn_133
chan_setbank 0
chan_setinstr 4
chan_end

.layer_21E2:
layer_portamento 0x82, 24, 255
layer_note1 12, 0x4, 100
layer_note1 51, 0x8, 80
layer_delay 0x1e
layer_end

.chan_21EF:
chan_setbank 7
chan_setinstr 7
chan_setdecayrelease 15
chan_setlayer 0, .layer_21F9
chan_end

.layer_21F9:
layer_note1 39, 0x30, 127
layer_end

.chan_21FD:
chan_setbank 9
chan_setinstr 3
chan_setenvelope .envelope_3458
chan_setval 10
chan_call .chan_fn_14C
chan_setlayer 0, .layer_220D
chan_end

.layer_220D:
layer_portamento 0x85, 48, 255
layer_note1 60, 0x7, 115
layer_note1 39, 0x23, 115
layer_end

.chan_2218:
chan_setbank 4
chan_setinstr 13
chan_setlayer 0, .layer_2220
chan_end

.layer_2220:
layer_portamento 0x81, 27, 255
layer_note1 3, 0x14, 115
layer_delay 0x1e
layer_end

.chan_222A:
chan_setbank 7
chan_setinstr 0
chan_setlayer 0, .layer_2232
chan_end

.layer_2232:
layer_note1 43, 0x6, 105
layer_portamento 0x81, 32, 255
layer_note1 44, 0x18, 105
layer_end

.chan_223D:
chan_setbank 7
chan_setinstr 3
chan_setval 15
chan_call .chan_fn_14C
chan_setlayer 0, .layer_224A
chan_end

.layer_224A:
layer_note1 48, 0x55, 127
layer_end

.chan_224E:
chan_setbank 7
chan_setinstr 8
chan_setlayer 0, .layer_2256
chan_end

.layer_2256:
layer_note1 44, 0xc, 100
layer_portamento 0x81, 44, 255
layer_note1 32, 0x18, 105
layer_end

.chan_2261:
chan_setbank 9
chan_setinstr 1
chan_setenvelope .envelope_3304
chan_setlayer 0, .layer_226C
chan_end

.layer_226C:
layer_portamento 0x83, 46, 255
layer_note1 27, 0x5, 127
layer_note1 32, 0x3, 127
layer_delay 0x22
layer_end

.chan_2279:
chan_setbank 9
chan_setinstr 3
chan_setenvelope .envelope_3458
chan_setlayer 0, .layer_2284
chan_end

.layer_2284:
layer_somethingon
layer_portamento 0x85, 62, 255
layer_note1 50, 0x24, 93
layer_note1 26, 0x3c, 93
layer_end

.chan_2290:
chan_setbank 4
chan_setinstr 5
chan_setlayer 0, .layer_22A1
chan_setval 1
chan_call .chan_fn_133
chan_setbank 2
chan_setinstr 0
chan_end

.layer_22A1:
layer_note1 62, 0x4, 105
layer_portamento 0x81, 43, 200
layer_note1 36, 0x4e, 127
layer_end

.chan_22AC:
chan_setbank 3
chan_setinstr 5
chan_setenvelope .envelope_3304
chan_setlayer 0, .layer_22B7
chan_end

.layer_22B7:
layer_note1 41, 0x6, 100
layer_note1 24, 0x1c, 100
layer_end

.chan_22BE:
chan_setbank 3
chan_setinstr 5
chan_setenvelope .envelope_3304
chan_setlayer 0, .layer_22C9
chan_end

.layer_22C9:
layer_note1 36, 0x5, 100
layer_note1 44, 0x18, 100
layer_end

.chan_22D0:
chan_setbank 0
chan_setinstr 4
chan_setenvelope .envelope_3304
chan_setval 25
chan_call .chan_fn_14C
chan_setlayer 0, .layer_22E0
chan_end

.layer_22E0:
layer_somethingon
layer_portamento 0x81, 39, 255
layer_note1 62, 0x1b, 107
layer_delay 0x12
layer_end

.chan_22EB:
chan_setbank 7
chan_setinstr 10
chan_setlayer 0, .layer_22F3
chan_end

.layer_22F3:
layer_somethingon
layer_portamento 0x85, 41, 255
layer_note1 45, 0x28, 127
layer_note1 41, 0xf, 127
layer_end

.chan_22FF:
chan_setbank 7
chan_setinstr 11
chan_setenvelope .envelope_3304
chan_setlayer 0, .layer_230C
chan_end

.layer_unused_230A:
layer_transpose 244

.layer_230C:
layer_somethingon
layer_portamento 0x85, 39, 255
layer_note1 32, 0xc, 127
layer_note1 39, 0x60, 127
layer_end

.chan_2318:
chan_setbank 9
chan_setinstr 3
chan_setval 20
chan_call .chan_fn_14C
chan_setenvelope .envelope_341C
chan_setlayer 0, .layer_2328
chan_end

.layer_2328:
layer_transpose 232
layer_somethingon
layer_portamento 0x85, 25, 255
layer_note1 3, 0xf, 85
layer_transpose 0
layer_note1 51, 0x1c, 85
layer_delay 0x19
layer_end

.chan_233A:
chan_setbank 9
chan_setinstr 3
chan_setenvelope .envelope_3458
chan_setlayer 0, .layer_2345
chan_end

.layer_2345:
layer_transpose 253
layer_somethingon
layer_portamento 0x85, 24, 255
layer_note1 17, 0xa, 100
layer_note1 32, 0xa, 100
layer_note1 27, 0x6, 100
layer_end

.chan_2356:
chan_setbank 6
chan_setinstr 5
chan_setenvelope .envelope_3304
chan_setlayer 0, .layer_2361
chan_end

.layer_2361:
layer_transpose 10
layer_call .layer_fn_236C
layer_call .layer_fn_236C
layer_delay 0x14
layer_end

.layer_fn_236C:
layer_portamento 0x85, 52, 255
layer_note1 48, 0x4, 115
layer_note1 52, 0x2, 115
layer_delay 0x2
layer_disableportamento
layer_end

.chan_237A:
chan_setbank 2
chan_setlayer 0, .layer_2383
chan_setlayer 1, .layer_238D
chan_end

.layer_2383:
layer_setinstr 0
layer_portamento 0x82, 44, 255
layer_note1 43, 0x54, 100
layer_end

.layer_238D:
layer_setinstr 1
layer_portamento 0x82, 32, 255
layer_note1 31, 0x54, 100
layer_end

.chan_2397:
chan_setbank 3
chan_setinstr 0
chan_setenvelope .envelope_3354
chan_setlayer 0, .layer_23A2
chan_end

.layer_23A2:
layer_portamento 0x81, 62, 255
layer_note1 38, 0x7f, 117
layer_end

.chan_23AA:
chan_setbank 7
chan_setinstr 3
chan_setlayer 0, .layer_23B2
chan_end

.layer_23B2:
layer_note1 27, 0x6, 100
layer_note1 29, 0x3, 70
layer_delay 0x1e
layer_end

.chan_23BB:
chan_setbank 7
chan_setinstr 3
chan_setlayer 0, .layer_23C3
chan_end

.layer_23C3:
layer_note1 20, 0x4, 100
layer_delay 0x1e
layer_end

.chan_23C9:
chan_setbank 7
chan_setinstr 3
chan_setlayer 0, .layer_23D1
chan_end

.layer_23D1:
layer_portamento 0x82, 29, 255
layer_note1 46, 0xc, 80
layer_end

.chan_23D9:
chan_setbank 6
chan_setinstr 4
chan_setenvelope .envelope_3324
chan_setlayer 0, .layer_23E6
chan_end

.layer_unused_23E4:
layer_transpose 12

.layer_23E6:
layer_somethingon
layer_portamento 0x85, 36, 255
layer_note1 48, 0x8, 100
layer_note1 45, 0x4, 100
layer_note1 48, 0xa, 100
layer_note1 41, 0x48, 100
layer_end

.chan_23F8:
chan_setbank 6
chan_setinstr 9
chan_setval 25
chan_call .chan_fn_14C
chan_setlayer 0, .layer_2408
chan_setlayer 1, .layer_2408
chan_end

.layer_2408:
layer_portamento 0x81, 20, 255
layer_note1 26, 0x12c, 127
layer_end

.chan_2411:
chan_setbank 7
chan_setinstr 7
chan_setlayer 0, .layer_2419
chan_end

.layer_2419:
layer_portamento 0x81, 32, 221
layer_note1 34, 0xa, 115
layer_end

.chan_2421:
chan_setbank 7
chan_setinstr 7
chan_setlayer 0, .layer_2429
chan_end

.layer_2429:
layer_portamento 0x81, 34, 221
layer_note1 38, 0xc, 127
layer_portamento 0x82, 34, 221
layer_note1 39, 0x12, 127
layer_end

.chan_2438:
chan_setbank 1
chan_setinstr 1
chan_setlayer 0, .layer_2440
chan_end

.layer_2440:
layer_portamento 0x81, 58, 255
layer_note1 52, 0x6, 105
layer_end

.chan_2448:
chan_setbank 0
chan_setinstr 1
chan_setenvelope .envelope_3304
chan_setlayer 0, .layer_2453
chan_end

.layer_2453:
layer_note1 43, 0x6, 90
layer_note1 44, 0x6, 90
layer_end

.chan_245A:
chan_setbank 7
chan_setinstr 8
chan_setlayer 0, .layer_2462
chan_end

.layer_2462:
layer_transpose 248
layer_call .layer_fn_2467

.layer_fn_2467:
layer_portamento 0x85, 44, 255
layer_note1 51, 0x9, 100
layer_note1 39, 0xc, 100
layer_end

.chan_2472:
chan_setbank 7
chan_setinstr 8
chan_setlayer 0, .layer_247A
chan_end

.layer_247A:
layer_transpose 10
layer_portamento 0x83, 32, 255
layer_note1 39, 0x6, 105
layer_note1 27, 0x12, 105
layer_end

.chan_2487:
chan_setbank 7
chan_setinstr 9
chan_setlayer 0, .layer_248F
chan_end

.layer_248F:
layer_somethingon
layer_portamento 0x83, 39, 255
layer_note1 41, 0x6, 127
layer_note1 37, 0x24, 127
layer_end

.chan_249B:
chan_setbank 7
chan_setinstr 9
chan_setlayer 0, .layer_24A3
chan_end

.layer_24A3:
layer_portamento 0x81, 48, 255
layer_note1 40, 0x24, 127
layer_end

.chan_24AB:
chan_setbank 7
chan_setinstr 9
chan_setval 20
chan_call .chan_fn_14C
chan_setlayer 0, .layer_24B8
chan_end

.layer_24B8:
layer_transpose 251
layer_call .layer_fn_24C8
layer_delay 0xb
layer_transpose 248
layer_call .layer_fn_24C8
layer_delay 0xa
layer_transpose 246

.layer_fn_24C8:
layer_portamento 0x85, 29, 255
layer_note1 24, 0x2, 127
layer_note1 41, 0x10, 127
layer_end

.chan_24D3:
chan_setbank 7
chan_setinstr 9
chan_setval 20
chan_call .chan_fn_14C
chan_setlayer 0, .layer_24E0
chan_end

.layer_24E0:
layer_transpose 244
layer_portamento 0x85, 25, 255
layer_note1 39, 0x4, 127
layer_note1 29, 0x30, 127
layer_end

.chan_24ED:
chan_setbank 7
chan_setinstr 2
chan_setlayer 0, .layer_24F5
chan_end

.layer_24F5:
layer_note1 44, 0x4, 127
layer_delay 0x14
layer_end

.chan_24FB:
chan_setbank 9
chan_setinstr 3
chan_setlayer 0, .layer_2503
chan_end

.layer_2503:
layer_portamento 0x81, 24, 255
layer_note1 53, 0x12, 80
layer_end

.chan_250B:
chan_setbank 7
chan_setinstr 10
chan_setenvelope .envelope_3374
chan_setlayer 0, .layer_2516
chan_end

.layer_2516:
layer_note1 50, 0x8, 105
layer_portamento 0x82, 46, 255
layer_note1 50, 0x30, 105
layer_end

.chan_2521:
chan_setbank 6
chan_setinstr 1
chan_setlayer 0, .layer_2529
chan_end

.layer_2529:
layer_portamento 0x81, 27, 255
layer_note1 43, 0x1e, 127
layer_end

.chan_2531:
chan_setbank 5
chan_setinstr 7
chan_setlayer 0, .layer_2545
chan_setval 1
chan_call .chan_fn_133
chan_setbank 7
chan_setinstr 12
chan_setlayer 1, .layer_26F0
chan_end

.layer_2545:
layer_note1 34, 0xaf, 127
layer_end

.chan_254A:
chan_setbank 6
chan_setinstr 9
chan_setval 25
chan_call .chan_fn_14C
chan_setlayer 0, .layer_2557
chan_end

.layer_2557:
layer_note1 55, 0x32, 127
layer_end

.chan_255B:
chan_setbank 7
chan_setinstr 7
chan_setlayer 0, .layer_2563
chan_end

.layer_2563:
layer_portamento 0x82, 51, 127
layer_note1 48, 0x6, 127
layer_end

.chan_256B:
chan_setbank 6
chan_setinstr 2
chan_setval 25
chan_call .chan_fn_14C
chan_setlayer 0, .layer_257D
chan_setlayer 1, .layer_257B
chan_end

.layer_257B:
layer_delay 0x4

.layer_257D:
layer_somethingon
layer_portamento 0x85, 31, 255
layer_note1 34, 0x18, 127
layer_note1 17, 0x48, 127
layer_end

.chan_2589:
chan_setbank 4
chan_setinstr 15
chan_setlayer 0, .layer_2596
chan_setlayer 1, .layer_2594
chan_end

.layer_2594:
layer_transpose 4

.layer_2596:
layer_jump .layer_11D2

.chan_2599:
chan_setbank 9
chan_setinstr 3
chan_setval 24
chan_call .chan_fn_14C
chan_setenvelope .envelope_3458
chan_setvibratoextent 80
chan_setvibratorate 60
chan_setlayer 0, .layer_25B4
chan_setval 30
chan_call .chan_fn_133
chan_setvibratoextent 0
chan_end

.layer_25B4:
layer_somethingon
layer_portamento 0x85, 15, 255
layer_note1 3, 0x7, 100
layer_note1 36, 0x18, 100
layer_end

.chan_25C0:
chan_setbank 6
chan_setinstr 0
chan_setenvelope .envelope_3304
chan_setlayer 0, .layer_25CB
chan_end

.layer_25CB:
layer_somethingon
layer_portamento 0x81, 44, 255
layer_note1 51, 0x8, 118
layer_end

.chan_25D4:
chan_setbank 6
chan_setinstr 7
chan_setlayer 0, .layer_25E5
chan_setval 1
chan_call .chan_fn_133
chan_setbank 7
chan_setinstr 2
chan_end

.layer_25E5:
layer_portamento 0x81, 3, 255
layer_note1 39, 0x5, 127
layer_portamento 0x81, 27, 255
layer_note1 49, 0x6, 127
layer_end

.chan_25F4:
chan_setbank 6
chan_setinstr 7
chan_setlayer 0, .layer_2605
chan_setval 1
chan_call .chan_fn_133
chan_setbank 2
chan_setinstr 1
chan_end

.layer_2605:
layer_portamento 0x81, 3, 255
layer_note1 39, 0x5, 127
layer_portamento 0x83, 36, 255
layer_note1 48, 0x6, 92
layer_note1 55, 0x30, 92
layer_end

.chan_2617:
chan_setbank 3
chan_setinstr 0
chan_setenvelope .envelope_3354
chan_setlayer 0, .layer_2622
chan_end

.layer_2622:
layer_portamento 0x82, 62, 255
layer_note1 38, 0x60, 117
layer_end

.chan_262A:
chan_setbank 7
chan_setinstr 5
chan_setenvelope .envelope_3324
chan_setlayer 0, .layer_2635
chan_end

.layer_2635:
layer_portamento 0x85, 41, 255
layer_note1 36, 0x18, 127
layer_end

.chan_263D:
chan_call .chan_2098
chan_setval 1
chan_call .chan_fn_133
chan_setbank 7
chan_setinstr 13
chan_setlayer 1, .layer_266E
chan_setlayer 2, .layer_2672
chan_setval 11
chan_call .chan_fn_133
chan_call .chan_1787
chan_setval 20
chan_call .chan_fn_133
chan_setbank 1
chan_setinstr 4
chan_setlayer 0, .layer_2664
chan_end

.layer_2664:
layer_note1 37, 0x8, 96
layer_note1 41, 0x6, 96
layer_note1 32, 0x18, 96
layer_end

.layer_266E:
layer_note1 46, 0x32, 127
layer_end

.layer_2672:
layer_note1 39, 0x32, 127
layer_end

.chan_2676:
chan_setbank 7
chan_setinstr 12
chan_setlayer 0, .layer_267E
chan_end

.layer_267E:
layer_portamento 0x83, 27, 255
layer_note0 34, 0x12, 127, 127
layer_note1 20, 0x28, 127
layer_end

.chan_268A:
chan_setbank 8
chan_setinstr 12
chan_setvibratoextent 80
chan_setvibratorate 5
chan_setlayer 0, .layer_269D
chan_setval 88
chan_call .chan_fn_133
chan_setvibratoextent 0
chan_end

.layer_269D:
layer_portamento 0x83, 44, 200
layer_note0 49, 0xc, 127, 127
layer_note0 40, 0x12, 127, 155
layer_note0 39, 0xb, 127, 127
layer_portamento 0x83, 41, 200
layer_note0 51, 0xa, 127, 127
layer_note0 48, 0x12, 127, 80
layer_note0 46, 0xa, 127, 127
layer_note0 48, 0xb, 127, 127
layer_end

.chan_26C2:
chan_setbank 9
chan_setinstr 3
chan_setlayer 0, .layer_26CA
chan_end

.layer_26CA:
layer_portamento 0x85, 31, 255
layer_note1 8, 0x6, 100
layer_note1 32, 0xc, 100
layer_end

.chan_26D5:
chan_setbank 7
chan_setinstr 12
chan_setlayer 0, .layer_26E0
chan_setlayer 1, .layer_26E0
chan_end

.layer_26E0:
layer_portamento 0x81, 32, 255
layer_note1 22, 0x24, 110
layer_end

.chan_26E8:
chan_setbank 7
chan_setinstr 12
chan_setlayer 0, .layer_26F0
chan_end

.layer_26F0:
layer_portamento 0x81, 26, 255
layer_note1 19, 0x60, 127
layer_end

.chan_26F8:
chan_setbank 6
chan_setinstr 7
chan_setlayer 0, .layer_2700
chan_end

.layer_2700:
layer_transpose 3
layer_note0 31, 0x8, 127, 70
layer_note0 30, 0x9, 127, 70
layer_note0 29, 0x8, 127, 70
layer_note0 28, 0x9, 127, 70
layer_end

.chan_2713:
chan_setbank 6
chan_setinstr 11
chan_setlayer 0, .layer_271B
chan_end

.layer_271B:
layer_portamento 0x81, 12, 255
layer_note1 51, 0x24, 127
layer_end

.chan_2723:
chan_setbank 6
chan_setinstr 9
chan_setval 25
chan_call .chan_fn_14C
chan_setlayer 0, .layer_2733
chan_setlayer 1, .layer_2733
chan_end

.layer_2733:
layer_delay 0xdc

.layer_2736:
layer_portamento 0x81, 20, 255
layer_note1 26, 0xc8, 110
layer_end

.chan_273F:
chan_call .chan_22D0
chan_setval 1
chan_call .chan_fn_133
chan_setbank 7
chan_setinstr 8
chan_setlayer 1, .layer_2256
chan_end

.chan_274F:
chan_call .chan_22D0
chan_setval 1
chan_call .chan_fn_133
chan_setbank 7
chan_setinstr 8
chan_setlayer 1, .layer_275F
chan_end

.layer_275F:
layer_note1 39, 0xe, 100
layer_portamento 0x81, 39, 255
layer_note1 27, 0x1c, 105
layer_end

.chan_276A:
chan_call .chan_22D0
chan_setval 1
chan_call .chan_fn_133
chan_setbank 7
chan_setinstr 7
chan_setlayer 1, .layer_2563
chan_end

.chan_277A:
chan_call .chan_22D0
chan_setval 1
chan_call .chan_fn_133
chan_setbank 7
chan_setinstr 8
chan_setlayer 1, .layer_247A
chan_end

.chan_278A:
chan_call .chan_22D0
chan_setval 1
chan_call .chan_fn_133
chan_setbank 7
chan_setinstr 0
chan_setlayer 1, .layer_2232
chan_end

.chan_279A:
chan_call .chan_22FF
chan_setlayer 1, .layer_230C
chan_end

.chan_27A1:
chan_call .chan_162A
chan_setval 12
chan_call .chan_fn_133
chan_setbank 6
chan_setinstr 1
chan_setlayer 2, .layer_27B1
chan_end

.layer_27B1:
layer_note1 24, 0x46, 127
layer_end

.chan_27B5:
chan_setbank 9
chan_setinstr 3
chan_setvibratoextent 80
chan_setvibratorate 60
chan_setenvelope .envelope_3314
chan_setlayer 0, .layer_27D0
chan_setlayer 1, .layer_27CE
chan_setval 56
chan_call .chan_fn_133
chan_setvibratoextent 0
chan_end

.layer_27CE:
layer_transpose 1

.layer_27D0:
layer_note1 15, 0x48, 127
layer_end

.chan_27D4:
chan_setbank 4
chan_setinstr 15
chan_setval 40
chan_call .chan_fn_14C
chan_setenvelope .envelope_33EC
chan_setlayer 0, .layer_27E4
chan_end

.layer_27E4:
layer_portamento 0x84, 3, 255
layer_note1 39, 0x7, 127
layer_note1 44, 0x8, 127
layer_note1 51, 0x7, 127
layer_note1 56, 0x8, 127
layer_end

.chan_27F5:
chan_setbank 6
chan_setinstr 1
chan_setval 55
chan_call .chan_fn_14C
chan_setlayer 0, .layer_2067
chan_end

.chan_2802:
chan_setbank 7
chan_setinstr 12
chan_setlayer 0, .layer_280A
chan_end

.layer_280A:
layer_note1 29, 0x7, 127
layer_note0 31, 0x18, 127, 127
layer_note1 27, 0x26, 127
layer_end

.chan_2815:
chan_setbank 6
chan_setinstr 0
chan_setlayer 0, .layer_281D
chan_end

.layer_281D:
layer_somethingon
layer_portamento 0x85, 32, 255
layer_note1 46, 0x9, 80
layer_note1 36, 0xa, 90
layer_end

.chan_2829:
chan_setbank 6
chan_setinstr 11
chan_setenvelope .envelope_3334
chan_setlayer 0, .layer_2834
chan_end

.layer_2834:
layer_somethingon
layer_portamento 0x85, 19, 255
layer_note1 31, 0xe, 127
layer_note1 62, 0x8, 127
layer_end

.chan_2840:
chan_setbank 2
chan_setinstr 1
chan_setenvelope .envelope_32F4
chan_setlayer 0, .layer_2857
chan_setval 1
chan_call .chan_fn_133
chan_setbank 6
chan_setinstr 0
chan_setlayer 1, .layer_281D
chan_end

.layer_2857:
layer_portamento 0x81, 47, 255
layer_note1 50, 0x18, 115
layer_end

.chan_285F:
chan_setbank 4
chan_setinstr 9
chan_setenvelope .envelope_32F4
chan_setlayer 0, .layer_286D
chan_setlayer 1, .layer_286F
chan_end

.layer_286D:
layer_setinstr 15

.layer_286F:
layer_transpose 6
layer_call .layer_fn_11B6
layer_transpose 247
layer_call .layer_fn_11B6
layer_transpose 236
layer_jump .layer_fn_11B6

.chan_287E:
chan_call .chan_2531
chan_setlayer 1, .layer_28A4
chan_setval 2
chan_call .chan_fn_133
chan_setbank 8
chan_setinstr 10
chan_setlayer 2, .layer_2891
chan_end

.layer_2891:
layer_portamento 0x83, 43, 255
layer_note1 46, 0x9, 115
layer_somethingon
layer_portamento 0x85, 48, 255
layer_note1 50, 0x8, 127
layer_note1 44, 0x1e, 127
layer_end

.layer_28A4:
layer_transpose 2
layer_jump .layer_2545

.chan_28A9:
chan_setbank 7
chan_setinstr 10
chan_setenvelope .envelope_3374
chan_setlayer 0, .layer_28B4
chan_end

.layer_28B4:
layer_transpose 3
layer_portamento 0x81, 46, 255
layer_note1 55, 0xa, 105
layer_call .layer_fn_28D8
layer_delay 0xf
layer_portamento 0x81, 44, 255
layer_note0 53, 0xf, 105, 127
layer_portamento 0x81, 43, 255
layer_note1 51, 0xc, 105
layer_portamento 0x81, 46, 255
layer_note1 43, 0xe, 105

.layer_fn_28D8:
layer_portamento 0x81, 43, 255
layer_note1 51, 0xc, 105
layer_end

.chan_28E0:
chan_setbank 7
chan_setinstr 10
chan_setenvelope .envelope_3374
chan_setlayer 0, .layer_28EB
chan_end

.layer_28EB:
layer_transpose 6
layer_portamento 0x83, 53, 255
layer_note1 48, 0x8, 105
layer_note0 60, 0x9, 105, 100
layer_note1 39, 0xb, 105
layer_end

.chan_28FC:
chan_setbank 6
chan_setinstr 7
chan_setlayer 0, .layer_2904
chan_end

.layer_2904:
layer_transpose 254
layer_note0 31, 0xa, 127, 70
layer_note0 30, 0xb, 127, 70
layer_note0 29, 0xa, 127, 70
layer_note0 28, 0xc, 127, 70
layer_end

.chan_2917:
chan_call .chan_22D0
chan_setval 1
chan_call .chan_fn_133
chan_setbank 7
chan_setinstr 10
chan_setenvelope .envelope_3374
chan_setlayer 1, .layer_292A
chan_end

.layer_292A:
layer_transpose 12
layer_portamento 0x83, 53, 255
layer_note1 48, 0x8, 105
layer_note0 60, 0x9, 105, 100
layer_note1 39, 0x14, 105
layer_end

.chan_293B:
chan_call .chan_2098
chan_setval 10
chan_call .chan_fn_133
chan_setbank 9
chan_setinstr 0
chan_setenvelope .envelope_343C
chan_setlayer 0, .layer_294E
chan_end

.layer_294E:
layer_transpose 6
layer_portamento 0x85, 12, 255
layer_note1 0, 0x12, 127
layer_note1 10, 0x14, 127
layer_end

.chan_295B:
chan_setbank 7
chan_setinstr 0
chan_setlayer 0, .layer_296A
chan_setlayer 1, .layer_2966
chan_end

.layer_2966:
layer_transpose 5
layer_delay 0x3

.layer_296A:
layer_note1 43, 0x6, 105
layer_portamento 0x81, 32, 255
layer_note1 44, 0x8, 105
layer_portamento 0x81, 29, 255
layer_note1 41, 0xa, 105
layer_portamento 0x81, 26, 255
layer_note1 38, 0xd, 105
layer_portamento 0x81, 22, 255
layer_note1 34, 0x10, 105
layer_end

.table_298A:
sound_ref .chan_29CA
sound_ref .chan_29DB
sound_ref .chan_29EC
sound_ref .chan_2A08
sound_ref .chan_2A1C
sound_ref .chan_2A30
sound_ref .chan_2A44
sound_ref .chan_2A56
sound_ref .chan_2A69
sound_ref .chan_2A9A
sound_ref .chan_2B1D
sound_ref .chan_1E4E
sound_ref .chan_29CA
sound_ref .chan_29CA
sound_ref .chan_29CA
sound_ref .chan_29CA
sound_ref .chan_3277
sound_ref .chan_29DB
sound_ref .chan_29CA
sound_ref .chan_29CA
sound_ref .chan_29CA
sound_ref .chan_29CA
sound_ref .chan_29CA
sound_ref .chan_29CA
sound_ref .chan_29CA
sound_ref .chan_29DB
sound_ref .chan_29CA
sound_ref .chan_29CA
sound_ref .chan_29CA
sound_ref .chan_29CA
sound_ref .chan_29CA
sound_ref .chan_29CA

.chan_29CA:
chan_setbank 7
chan_setinstr 5
chan_setlayer 0, .layer_29D2
chan_end

.layer_29D2:
layer_somethingon
.layer_29D3:
layer_note1 39, 0x12c, 127
layer_jump .layer_29D3
layer_end

.chan_29DB:
chan_setbank 7
chan_setinstr 6
chan_setlayer 0, .layer_29E3
chan_end

.layer_29E3:
layer_somethingon
.layer_29E4:
layer_note1 39, 0x12c, 90
layer_jump .layer_29E4
layer_end

.chan_29EC:
chan_setbank 9
chan_setinstr 3
chan_setenvelope .envelope_3314
chan_setlayer 0, .layer_29F7
chan_end

.layer_29F7:
layer_transpose 12
layer_somethingon
layer_portamento 0x85, 27, 255
.layer_29FE:
layer_note1 51, 0x16, 50
layer_note1 27, 0x16, 50
layer_jump .layer_29FE
layer_end

.chan_2A08:
chan_setbank 3
chan_setinstr 9
chan_setenvelope .envelope_3314
chan_setlayer 0, .layer_2A13
chan_end

.layer_2A13:
layer_somethingon
.layer_2A14:
layer_note1 46, 0xc8, 92
layer_jump .layer_2A14
layer_end

.chan_2A1C:
chan_setbank 7
chan_setinstr 5
chan_setenvelope .envelope_3314
chan_setlayer 0, .layer_2A27
chan_end

.layer_2A27:
layer_somethingon
.layer_2A28:
layer_note1 44, 0x12c, 127
layer_jump .layer_2A28
layer_end

.chan_2A30:
chan_setbank 3
chan_setinstr 6
chan_setenvelope .envelope_3314
chan_setlayer 0, .layer_2A3B
chan_end

.layer_2A3B:
layer_somethingon
.layer_2A3C:
layer_note1 35, 0x12c, 127
layer_jump .layer_2A3C
layer_end

.chan_2A44:
chan_setbank 5
chan_setinstr 5
chan_setlayer 0, .layer_2A4C
chan_end

.layer_2A4C:
layer_note1 56, 0x4, 62
layer_note1 32, 0x3, 62
layer_jump .layer_2A4C
layer_end

.chan_2A56:
chan_setbank 9
chan_setinstr 3
chan_setlayer 0, .layer_2A5E
chan_end

.layer_2A5E:
layer_portamento 0x81, 24, 255
layer_note1 56, 0x10, 55
layer_jump .layer_2A5E
layer_end

.chan_2A69:
chan_setbank 3
chan_setinstr 5
chan_setlayer 0, .layer_2A7A
chan_setval 1
chan_call .chan_fn_133
chan_setbank 3
chan_setinstr 8
chan_end

.layer_2A7A:
layer_note1 48, 0x6, 100
layer_somethingon
.layer_2A7E:
layer_note1 44, 0x12c, 127
layer_jump .layer_2A7E
layer_end

.chan_unused_2A86:
chan_setbank 3
chan_setinstr 6
chan_setenvelope .envelope_3314
chan_setlayer 0, .layer_2A91
chan_end

.layer_2A91:
layer_somethingon
layer_note1 35, 0x12c, 100
layer_jump .layer_2A3C
layer_end

.chan_2A9A:
chan_setlayer 0, .layer_2AC0
chan_setlayer 1, .layer_2AD0
chan_setpanmix 0
.chan_2AA2:
chan_setbank 5
chan_setinstr 6
chan_setdecayrelease 3
chan_setval 1
chan_call .chan_fn_133
chan_setbank 6
chan_setinstr 9
chan_setdecayrelease 3
chan_setval 199
chan_call .chan_fn_133
chan_setval 100
chan_call .chan_fn_133
chan_jump .chan_2AA2

.layer_2AC0:
layer_somethingon
layer_portamento 0x85, 38, 255
.layer_2AC5:
layer_note1 41, 0x12c, 127
layer_note1 38, 0x12c, 127
layer_jump .layer_2AC5

.layer_2AD0:
layer_delay 0x1
layer_setpan 30
layer_note1 56, 0xc, 10
layer_delay 0x6c
layer_setpan 90
layer_note1 55, 0x1e, 35
layer_delay 0x3b
layer_setpan 55
layer_note1 56, 0x2e, 68
layer_delay 0x2d
layer_note1 58, 0x25, 34
layer_delay 0x2b
layer_setpan 91
layer_note1 53, 0x6, 55
layer_note1 55, 0x18, 70
layer_delay 0x2b
layer_setpan 21
layer_note1 56, 0x28, 52
layer_delay 0x1b
layer_note1 57, 0x18, 65
layer_delay 0x38
layer_setpan 75
layer_note1 53, 0x22, 67
layer_delay 0x4c
layer_setpan 105
layer_note1 53, 0x3, 54
layer_note1 55, 0x17, 61
layer_delay 0x43
layer_setpan 64
layer_note1 52, 0x28, 45
layer_delay 0x38
layer_jump .layer_2AD0

.chan_2B1D:
chan_setbank 5
chan_setinstr 5
chan_setenvelope .envelope_32F4
chan_setlayer 0, .layer_2B28
chan_end

.layer_2B28:
layer_portamento 0x81, 56, 255
layer_note1 44, 0x3, 85
layer_note1 20, 0x2, 85
layer_jump .layer_2B28
layer_end

.table_2B36:
sound_ref .chan_2BB6
sound_ref .chan_2BDF
sound_ref .chan_2C0E
sound_ref .chan_2C0E
sound_ref .chan_2C4D
sound_ref .chan_2C5F
sound_ref .chan_2C92
sound_ref .chan_2C74
sound_ref .chan_2CB0
sound_ref .chan_2CCD
sound_ref .chan_2D07
sound_ref .chan_2D21
sound_ref .chan_2D3C
sound_ref .chan_2D65
sound_ref .chan_2DA2
sound_ref .chan_2DB2
sound_ref .chan_2DD0
sound_ref .chan_2DDD
sound_ref .chan_2DFA
sound_ref .chan_2E1C
sound_ref .chan_2E2F
sound_ref .chan_2E78
sound_ref .chan_2EAE
sound_ref .chan_2F03
sound_ref .chan_2F80
sound_ref .chan_10BE
sound_ref .chan_2F90
sound_ref .chan_2F9C
sound_ref .chan_2FB7
sound_ref .chan_2FD1
sound_ref .chan_1353
sound_ref .chan_30CB
sound_ref .chan_30E2
sound_ref .chan_30F7
sound_ref .chan_310C
sound_ref .chan_3122
sound_ref .chan_3136
sound_ref .chan_2E78
sound_ref .chan_2EAE
sound_ref .chan_2F03
sound_ref .chan_314F
sound_ref .chan_314F
sound_ref .chan_314F
sound_ref .chan_314F
sound_ref .chan_314F
sound_ref .chan_314F
sound_ref .chan_314F
sound_ref .chan_314F
sound_ref .chan_31B9
sound_ref .chan_31B9
sound_ref .chan_31B9
sound_ref .chan_31B9
sound_ref .chan_31B9
sound_ref .chan_31B9
sound_ref .chan_31B9
sound_ref .chan_31B9
sound_ref .chan_2CB0
sound_ref .chan_2CCD
sound_ref .chan_2D07
sound_ref .chan_2D21
sound_ref .chan_2D3C
sound_ref .chan_2D65
sound_ref .chan_2DA2
sound_ref .chan_2DB2

.chan_2BB6:
chan_setbank 9
chan_setinstr 1
chan_setmutebhv 0x0
chan_setnotepriority 14
chan_setpanmix 0
chan_setenvelope .envelope_343C
chan_setlayer 0, .layer_2BCA
chan_setlayer 1, .layer_2BD7
chan_end

.layer_2BCA:
layer_portamento 0x1, 35, 0xa
layer_note1 41, 0xa, 80
layer_setpan 0
layer_note1 41, 0xa, 80
layer_end

.layer_2BD7:
layer_setpan 127
layer_delay 0xc
layer_note1 41, 0xa, 80
layer_end

.chan_2BDF:
chan_setbank 9
chan_setinstr 1
chan_setmutebhv 0x0
chan_setnotepriority 14
chan_setpanmix 0
chan_setlayer 0, .layer_2BF0
chan_setlayer 1, .layer_2C07
chan_end

.layer_2BF0:
layer_setpan 34
.layer_2BF2:
layer_note0 45, 0xc, 80, 63
layer_note0 41, 0xc, 80, 63
layer_note0 48, 0xc, 80, 63
layer_note0 41, 0xc, 38, 63
layer_note0 48, 0xc, 38, 63
layer_end

.layer_2C07:
layer_setpan 94
layer_delay 0x2
layer_jump .layer_2BF2

.chan_2C0E:
chan_setbank 9
chan_setinstr 1
chan_setmutebhv 0x0
chan_setnotepriority 14
chan_setpanmix 0
chan_setlayer 0, .layer_2C1F
chan_setlayer 1, .layer_2C2C
chan_end

.layer_2C1F:
layer_note1 43, 0x9, 95
layer_note1 39, 0x9, 90
layer_note1 43, 0x9, 95
layer_note1 39, 0x9, 90
layer_end

.layer_2C2C:
layer_delay 0x8
layer_setpan 40
layer_note1 43, 0x9, 35
layer_setpan 88
layer_note1 39, 0x9, 35
layer_setpan 36
layer_note1 43, 0x9, 30
layer_setpan 92
layer_note1 39, 0x9, 30
layer_setpan 28
layer_note1 43, 0x9, 25
layer_setpan 100
layer_note1 39, 0x9, 25
layer_end

.chan_2C4D:
chan_setbank 9
chan_setnotepriority 14
chan_setinstr 2
chan_setlayer 0, .layer_2C57
chan_end

.layer_2C57:
layer_portamento 0x1, 32, 0x7f
layer_note1 56, 0x1e, 102
layer_end

.chan_2C5F:
chan_setnotepriority 14
chan_setbank 9
chan_setinstr 0
chan_setenvelope .envelope_3468
chan_setlayer 0, .layer_2C6C
chan_end

.layer_2C6C:
layer_portamento 0x1, 32, 0x7f
layer_note1 53, 0x1e, 78
layer_end

.chan_2C74:
chan_setmutebhv 0x0
chan_setnotepriority 14
chan_setbank 9
chan_setinstr 3
chan_setenvelope .envelope_344C
chan_setlayer 0, .layer_2C83
chan_end

.layer_2C83:
layer_portamento 0x1, 32, 0x8
layer_note1 27, 0x8, 127
layer_portamento 0x81, 39, 255
layer_note1 20, 0x28, 127
layer_end

.chan_2C92:
chan_setmutebhv 0x0
chan_setnotepriority 14
chan_setbank 9
chan_setinstr 3
chan_setenvelope .envelope_3458
chan_setlayer 0, .layer_2CA1
chan_end

.layer_2CA1:
layer_portamento 0x1, 27, 0x8
layer_note1 32, 0x8, 93
layer_portamento 0x81, 20, 255
layer_note1 39, 0x28, 93
layer_end

.chan_2CB0:
chan_setbank 9
chan_setnotepriority 14
chan_setinstr 1
chan_setenvelope .envelope_3474
chan_setvibratorate 1
chan_setvibratoextent 100
chan_setlayer 0, .layer_2CC1
chan_end

.layer_2CC1:
layer_somethingon
layer_portamento 0x85, 27, 255
layer_note1 15, 0x6, 127
layer_note1 34, 0xc, 127
layer_end

.chan_2CCD:
chan_setbank 9
chan_setnotepriority 14
chan_setinstr 1
chan_setenvelope .envelope_3484
chan_setvibratorate 25
chan_setvibratoextent 80
chan_setlayer 0, .layer_2CFC
chan_setlayer 1, .layer_2CF8
chan_setval 5
chan_call .chan_fn_133
chan_setvibratorate 35
chan_setvibratoextent 115
chan_setval 55
chan_call .chan_fn_133
chan_setvibratoextent 80
chan_setval 67
chan_call .chan_fn_133
chan_setvibratoextent 0
chan_end

.layer_2CF8:
layer_transpose 12
layer_delay 0x3

.layer_2CFC:
layer_portamento 0x85, 24, 255
layer_note1 28, 0x5, 110
layer_note1 28, 0x78, 110
layer_end

.chan_2D07:
chan_setbank 9
chan_setnotepriority 14
chan_setinstr 3
chan_setlayer 0, .layer_2D16
chan_setlayer 1, .layer_2D14
chan_end

.layer_2D14:
layer_delay 0x2

.layer_2D16:
layer_portamento 0x85, 47, 255
layer_note1 35, 0x8, 90
layer_note1 47, 0x10, 90
layer_end

.chan_2D21:
chan_setbank 9
chan_setnotepriority 14
chan_setinstr 3
chan_setlayer 0, .layer_2D30
chan_setlayer 1, .layer_2D2E
chan_end

.layer_2D2E:
layer_delay 0x2

.layer_2D30:
layer_portamento 0x85, 35, 255
layer_note1 47, 0x8, 90
layer_note1 35, 0x10, 90
layer_disableportamento
layer_end

.chan_2D3C:
chan_setbank 9
chan_setnotepriority 14
chan_setpanmix 0
chan_setinstr 3
chan_setenvelope .envelope_3484
chan_setlayer 0, .layer_2D4B
chan_end

.layer_2D4B:
layer_note1 45, 0x6, 100
layer_note1 57, 0x6, 100
layer_note1 57, 0xc, 100
layer_setpan 10
layer_note1 57, 0x6, 57
layer_note1 57, 0xc, 57
layer_setpan 117
layer_note1 57, 0x6, 38
layer_note1 57, 0xc, 38
layer_end

.chan_2D65:
chan_setbank 9
chan_setnotepriority 14
chan_setpanmix 0
chan_setinstr 3
chan_setenvelope .envelope_3484
chan_setval 25
chan_call .chan_fn_14C
chan_setlayer 0, .layer_2D79
chan_end

.layer_2D79:
layer_setpan 30
layer_note1 44, 0x5, 105
layer_setpan 50
layer_note1 47, 0x5, 105
layer_setpan 77
layer_note1 52, 0x5, 105
layer_setpan 97
layer_note1 56, 0xa, 105
layer_setpan 30
layer_note1 52, 0x5, 45
layer_setpan 97
layer_note1 56, 0xa, 45
layer_setpan 30
layer_note1 52, 0x5, 32
layer_setpan 97
layer_note1 56, 0xa, 32
layer_end

.chan_2DA2:
chan_setmutebhv 0x0
chan_setnotepriority 14
chan_setbank 9
chan_setinstr 4
chan_setlayer 0, .layer_2DAE
chan_end

.layer_2DAE:
layer_note1 39, 0x18, 105
layer_end

.chan_2DB2:
chan_setmutebhv 0x0
chan_setnotepriority 14
chan_setbank 9
chan_setinstr 3
chan_setenvelope .envelope_3458
chan_setlayer 0, .layer_2DC1
chan_end

.layer_2DC1:
layer_portamento 0x81, 23, 255
layer_note1 35, 0x9, 96
layer_portamento 0x81, 36, 255
layer_note1 43, 0x44, 100
layer_end

.chan_2DD0:
chan_setnotepriority 14
chan_setbank 9
chan_setinstr 3
chan_setlayer 0, .layer_2DDA
chan_end

.layer_2DDA:
layer_delay 0x1
layer_end

.chan_2DDD:
chan_setmutebhv 0x0
chan_setnotepriority 14
chan_setbank 6
chan_setinstr 11
chan_setlayer 0, .layer_2DE9
chan_end

.layer_2DE9:
layer_portamento 0x81, 32, 255
layer_note0 39, 0x5, 115, 255
layer_portamento 0x81, 44, 255
layer_note0 51, 0x3, 115, 255
layer_end

.chan_2DFA:
chan_setmutebhv 0x0
chan_setbank 9
chan_setinstr 1
chan_setval 60
chan_call .chan_fn_14C
chan_setlayer 0, .layer_2E09
chan_end

.layer_2E09:
layer_note1 46, 0x3, 90
layer_note1 46, 0x3, 30
layer_note1 58, 0x3, 90
layer_note1 58, 0x3, 30
layer_note1 46, 0x3, 90
layer_note1 46, 0x3, 30
layer_end

.chan_2E1C:
chan_setbank 9
chan_setinstr 0
chan_setenvelope .envelope_32F4
chan_setlayer 0, .layer_2E27
chan_end

.layer_2E27:
layer_portamento 0x81, 15, 255
layer_note1 51, 0x5, 73
layer_end

.chan_2E2F:
chan_setbank 9
chan_setinstr 3
chan_setenvelope .envelope_3388
chan_setvibratoextent 3
chan_setvibratorate 60
chan_setval 25
chan_call .chan_fn_14C
chan_setlayer 0, .layer_2E52
chan_setlayer 1, .layer_2E67
chan_setlayer 2, .layer_2E5E
chan_setval 70
chan_call .chan_fn_133
chan_setbank 10
chan_setinstr 8
chan_end

.layer_2E52:
layer_call .layer_11FB
layer_delay 0x12
layer_transpose 0
layer_note1 39, 0xc8, 120
layer_end

.layer_2E5E:
layer_delay 0x6e
layer_transpose 0
layer_note1 39, 0xc8, 31
layer_end

.layer_2E67:
layer_transpose 24
layer_delay 0x1e
layer_note1 25, 0x2, 18
layer_note1 37, 0x7, 36
layer_note1 30, 0x5, 18
layer_note1 42, 0x37, 36
layer_end

.chan_2E78:
chan_setbank 9
chan_setnotepriority 14
chan_setpanmix 0
chan_setinstr 3
chan_setenvelope .envelope_3484
chan_setval 25
chan_call .chan_fn_14C
chan_setpanmix 0
chan_stereoheadseteffects 1
chan_setlayer 0, .layer_2E90
chan_end

.layer_2E90:
layer_note1 46, 0x5, 105
layer_note1 53, 0x5, 105
layer_note1 58, 0x5, 105
layer_setpan 30
layer_note1 53, 0x5, 50
layer_setpan 98
layer_note1 58, 0x5, 50
layer_setpan 20
layer_note1 53, 0x5, 20
layer_setpan 108
layer_note1 58, 0x5, 20
layer_end

.chan_2EAE:
chan_reservenotes 4
chan_setbank 9
chan_setinstr 2
chan_setpanmix 0
chan_stereoheadseteffects 1
chan_setval 30
chan_call .chan_fn_14C
chan_setenvelope .envelope_33EC
chan_setdecayrelease 220
chan_setlayer 0, .layer_2ECE
chan_setlayer 1, .layer_2EC9
chan_end

.layer_2EC9:
layer_transpose 244
layer_jump .layer_2ED0

.layer_2ECE:
layer_transpose 232
.layer_2ED0:
layer_call .layer_fn_2ED6
layer_call .layer_fn_2ED6

.layer_fn_2ED6:
layer_portamento 0x85, 60, 192
layer_setpan 117
layer_note1 60, 0x3, 126
layer_setpan 105
layer_note1 58, 0x3, 126
layer_setpan 93
layer_note1 55, 0x3, 126
layer_setpan 81
layer_note1 51, 0x3, 126
layer_setpan 46
layer_note1 50, 0x3, 126
layer_setpan 34
layer_note1 46, 0x3, 126
layer_setpan 22
layer_note1 44, 0x3, 126
layer_setpan 10
layer_note1 41, 0x3, 126
layer_end

.chan_2F03:
chan_reservenotes 4
chan_setbank 9
chan_setinstr 2
chan_setval 30
chan_call .chan_fn_14C
chan_setenvelope .envelope_3494
chan_setdecayrelease 220
chan_setlayer 0, .layer_2F1F
chan_setlayer 1, .layer_2F1A
chan_end

.layer_2F1A:
layer_transpose 24
layer_jump .layer_2F21

.layer_2F1F:
layer_transpose 12
.layer_2F21:
layer_portamento 0x85, 15, 128
layer_note1 15, 0x3, 126
layer_note1 19, 0x3, 126
layer_note1 22, 0x3, 126
layer_note1 27, 0x3, 126
layer_note1 22, 0x3, 126
layer_note1 27, 0x3, 126
layer_note1 31, 0x3, 126
layer_note1 34, 0x3, 126
layer_note1 39, 0x3, 126
layer_note1 34, 0x3, 126
layer_note1 23, 0x3, 126
layer_note1 27, 0x3, 126
layer_note1 30, 0x3, 126
layer_note1 35, 0x3, 126
layer_note1 30, 0x3, 126
layer_note1 35, 0x3, 126
layer_note1 39, 0x3, 126
layer_note1 42, 0x3, 126
layer_note1 47, 0x3, 126
layer_note1 42, 0x3, 126
layer_note1 25, 0x3, 126
layer_note1 29, 0x3, 126
layer_note1 32, 0x3, 126
layer_note1 37, 0x3, 126
layer_note1 32, 0x3, 126
layer_note1 37, 0x3, 126
layer_note1 41, 0x3, 126
layer_note1 44, 0x3, 126
layer_note1 49, 0x3, 126
layer_note1 44, 0x3, 126
layer_end

.chan_2F80:
chan_setbank 6
chan_setinstr 9
chan_setval 25
chan_call .chan_fn_14C
chan_setlayer 0, .layer_2736
chan_setlayer 1, .layer_2736
chan_end

.chan_2F90:
chan_setbank 9
chan_setinstr 5
chan_setlayer 0, .layer_2F98
chan_end

.layer_2F98:
layer_note1 39, 0x30, 127
layer_end

.chan_2F9C:
chan_setbank 9
chan_setinstr 3
chan_setenvelope .envelope_3304
chan_setlayer 0, .layer_2FA7
chan_end

.layer_2FA7:
layer_transpose 244
layer_portamento 0x83, 3, 255
layer_note1 15, 0xa, 127
layer_somethingon
layer_transpose 0
layer_note1 46, 0x64, 127
layer_end

.chan_2FB7:
chan_setbank 9
chan_setinstr 3
chan_setlayer 0, .layer_2FC2
chan_setenvelope .envelope_3304
chan_end

.layer_2FC2:
layer_portamento 0x81, 3, 255
layer_note1 15, 0xc, 127
layer_portamento 0x81, 39, 255
layer_note1 3, 0x64, 127
layer_end

.chan_2FD1:
chan_setbank 9
chan_setnotepriority 14
chan_setpanmix 0
chan_setinstr 3
chan_setenvelope .envelope_343C
chan_setreverb 30
chan_setlayer 0, .layer_305E
chan_setlayer 1, .layer_2FE5
chan_end

.layer_2FE5:
layer_transpose 232
layer_setpan 24
layer_call .layer_fn_3039
layer_transpose 244
layer_setpan 44
layer_call .layer_fn_3039
layer_transpose 0

.layer_2FF5:
layer_setpan 64
layer_call .layer_fn_3039
layer_transpose 12
layer_setpan 84
layer_call .layer_fn_3039
layer_transpose 24
layer_setpan 104
layer_call .layer_fn_3039
layer_setpan 24
layer_note1 56, 0x2, 100
layer_note1 56, 0x1, 50
layer_setpan 104
layer_note1 60, 0x14, 70
layer_note1 60, 0xa, 30
layer_setpan 24
layer_note1 56, 0x2, 50
layer_note1 56, 0x1, 20
layer_setpan 104
layer_note1 60, 0x14, 30
layer_note1 60, 0xa, 10
layer_setpan 24
layer_note1 56, 0x2, 30
layer_note1 56, 0x1, 10
layer_setpan 104
layer_note1 60, 0x14, 20
layer_note1 60, 0xa, 7
layer_end

.layer_fn_3039:
layer_note1 51, 0x2, 50
layer_note1 39, 0x1, 40
layer_note1 39, 0x2, 20
layer_note1 55, 0x2, 50
layer_note1 43, 0x1, 40
layer_note1 43, 0x2, 20
layer_note1 56, 0x2, 50
layer_note1 44, 0x1, 40
layer_note1 44, 0x2, 20
layer_note1 60, 0x2, 50
layer_note1 48, 0x1, 40
layer_note1 48, 0x2, 20
layer_end

.layer_305E:
layer_transpose 232
layer_call .layer_fn_309E
layer_transpose 244
layer_call .layer_fn_309E
layer_transpose 0
layer_call .layer_fn_309E

.layer_306D:
layer_transpose 12
layer_call .layer_fn_309E
layer_transpose 24
layer_call .layer_fn_309E
layer_setpan 64
layer_note1 44, 0x1, 100
layer_note1 56, 0x2, 50
layer_note1 48, 0xa, 70
layer_note1 60, 0x14, 30
layer_note1 44, 0x1, 50
layer_note1 56, 0x2, 20
layer_note1 48, 0xa, 30
layer_note1 60, 0x14, 10
layer_note1 44, 0x1, 30
layer_note1 56, 0x2, 10
layer_note1 48, 0xa, 20
layer_note1 60, 0x14, 7
layer_end

.layer_fn_309E:
layer_setpan 54
layer_note1 39, 0x3, 100
layer_note1 51, 0x1, 50
layer_note1 51, 0x1, 20
layer_setpan 74
layer_note1 43, 0x3, 100
layer_note1 55, 0x1, 50
layer_note1 55, 0x1, 20
layer_setpan 54
layer_note1 44, 0x3, 100
layer_note1 56, 0x1, 50
layer_note1 56, 0x1, 20
layer_setpan 74
layer_note1 48, 0x3, 100
layer_note1 60, 0x1, 50
layer_note1 60, 0x1, 20
layer_end

.chan_30CB:
chan_setbank 10
chan_setinstr 14
chan_setlayer 0, .layer_30D6
chan_setlayer 1, .layer_30DB
chan_end

.layer_30D6:
layer_note1 39, 0xfa, 127
layer_end

.layer_30DB:
layer_delay 0x9
layer_note1 39, 0xf1, 45
layer_end

.chan_30E2:
chan_setbank 9
chan_setinstr 1
chan_setlayer 0, .layer_30EA
chan_end

.layer_30EA:
layer_note1 46, 0x3, 90
layer_note1 46, 0x3, 30
layer_note1 58, 0x3, 90
layer_note1 58, 0x3, 30
layer_end

.chan_30F7:
chan_setbank 9
chan_setinstr 1
chan_setlayer 0, .layer_30FF
chan_end

.layer_30FF:
layer_note1 58, 0x3, 90
layer_note1 58, 0x3, 30
layer_note1 46, 0x3, 90
layer_note1 46, 0x3, 30
layer_end

.chan_310C:
chan_reservenotes 6
chan_setbank 9
chan_setnotepriority 14
chan_setpanmix 0
chan_setinstr 3
chan_setenvelope .envelope_343C
chan_setreverb 30
chan_setlayer 0, .layer_306D
chan_setlayer 1, .layer_2FF5
chan_end

.chan_3122:
chan_setbank 4
chan_setinstr 14
chan_setlayer 0, .layer_135B
chan_setval 1
chan_call .chan_fn_133
chan_setbank 10
chan_setinstr 12
chan_setlayer 1, .layer_E46
chan_end

.chan_3136:
chan_setbank 8
chan_setinstr 26
chan_setlayer 0, .layer_314A
chan_setval 1
chan_call .chan_fn_133
chan_setbank 4
chan_setinstr 14
chan_setlayer 1, .layer_135B
chan_end

.layer_314A:
layer_note1 39, 0xb4, 127
layer_end

.chan_314F:
chan_setinstr 128
chan_setnotepriority 14
chan_setpanmix 0
chan_setenvelope .envelope_33A8
chan_ioreadval 4
chan_subtract 40
chan_readseq .addr_316C
chan_writeseq 0, .layer_fn_31B6, 1
chan_setlayer 0, .layer_3174
chan_setlayer 1, .layer_3196
chan_setlayer 2, .layer_3176
chan_end

.addr_316C:
.byte 0x0
.byte 0x2
.byte 0x4
.byte 0x5
.byte 0x7
.byte 0x9
.byte 0xb
.byte 0xc

.layer_3174:
layer_delay 0x6

.layer_3176:
layer_call .layer_fn_31B6
layer_note0 46, 0xc, 75, 20
layer_note0 45, 0xc, 75, 20
layer_note0 46, 0xc, 75, 20
layer_note0 58, 0x10, 80, 80
layer_note0 58, 0x10, 45, 80
layer_note0 58, 0x10, 20, 80
layer_note0 58, 0x10, 15, 80
layer_end

.layer_3196:
layer_call .layer_fn_31B6
layer_note0 41, 0xc, 75, 20
layer_note0 40, 0xc, 75, 20
layer_note0 41, 0xc, 75, 20
layer_note0 53, 0x10, 80, 80
layer_note0 53, 0x10, 45, 80
layer_note0 53, 0x10, 20, 80
layer_note0 53, 0x10, 15, 80
layer_end

.layer_fn_31B6:
layer_transpose 0
layer_end

.chan_31B9:
chan_setbank 4
chan_setinstr 14
chan_setnotepriority 14
chan_setpanmix 0
chan_ioreadval 4
chan_subtract 48
chan_readseq .addr_316C
chan_writeseq 0, .layer_31CF, 1
chan_setlayer 0, .layer_31CF
chan_end

.layer_31CF:
layer_transpose 0
layer_note1 32, 0x7f, 115
layer_end

.chan_31D5:
chan_setbank 5
chan_setinstr 9
chan_setval 40
chan_call .chan_fn_14C
chan_setlayer 0, .layer_31E2
chan_end

.layer_31E2:
layer_delay 0x4b
layer_note0 39, 0xf5, 100, 127
layer_note0 39, 0xa, 85, 127
layer_note0 40, 0x123, 98, 127
layer_note0 39, 0x91, 75, 127
layer_note0 41, 0xbd, 84, 127
layer_note0 39, 0x4b, 73, 127
layer_note0 39, 0x96, 94, 127
layer_note0 36, 0x74, 78, 127
layer_jump .layer_31E2
layer_end

.chan_320D:
chan_setbank 5
chan_setinstr 10
chan_setval 60
chan_call .chan_fn_14C
chan_setlayer 0, .layer_321A
chan_end

.layer_321A:
layer_delay 0x14
layer_note1 39, 0x71, 70
layer_note1 37, 0xd3, 62
layer_note1 39, 0x48, 84
layer_note1 40, 0x71, 49
layer_note1 39, 0xa8, 65
layer_note1 41, 0x86, 59
layer_note1 41, 0x31, 54
layer_note1 38, 0x6f, 51
layer_note1 39, 0xc7, 79
layer_note1 35, 0xe9, 74
layer_jump .layer_321A
layer_end

.chan_3243:
chan_setbank 5
chan_setinstr 12
chan_setval 30
chan_call .chan_fn_14C
chan_setlayer 0, .layer_3250
chan_end

.layer_3250:
layer_delay 0x32
layer_note1 41, 0x31, 66
layer_delay 0x9f
layer_note1 39, 0x31, 51
layer_delay 0xf9
layer_note1 38, 0x1d, 60
layer_note1 41, 0x4c, 77
layer_delay_long 0x64
layer_note1 42, 0x31, 59
layer_delay 0x159
layer_note1 36, 0x4f, 61
layer_delay 0xc6
layer_jump .layer_3250
layer_end

.chan_3277:
chan_setbank 5
chan_setval 15
chan_call .chan_fn_14C
chan_setlayer 0, .layer_3288
chan_setlayer 1, .layer_32AE
chan_setlayer 2, .layer_32B0
chan_end

.layer_3288:
layer_setinstr 8
layer_delay 0x18
layer_note1 41, 0x9, 26
layer_note1 37, 0xbc, 22
layer_note1 39, 0x71, 33
layer_note1 40, 0xd7, 33
layer_note1 39, 0x54, 39
layer_note1 39, 0x6f, 31
layer_note1 43, 0xa8, 26
layer_note1 40, 0xe1, 22
layer_note1 38, 0x74, 31
layer_jump .layer_3288

.layer_32AE:
layer_transpose 12

.layer_32B0:
layer_setinstr 13
layer_somethingon
layer_delay 0xf
.layer_32B5:
layer_note1 39, 0x12c, 25
layer_jump .layer_32B5

.chan_32BC:
chan_setval 18
chan_jump .chan_32C3

.chan_32C1:
chan_setval 42
.chan_32C3:
chan_writeseq 0, .layer_32EE, 1
chan_reservenotes 4
chan_setbank 4
chan_setinstr 2
chan_setenvelope .envelope_3344
chan_setdecayrelease 15
chan_setlayer 0, .layer_32E6
chan_setlayer 1, .layer_32E2
.chan_32D8:
chan_delay1
chan_ioreadval 0
chan_iowriteval 0
chan_subtract 255
chan_beqz .chan_32D8
chan_unreservenotes
chan_end

.layer_32E2:
layer_setinstr 9
layer_transpose 12

.layer_32E6:
layer_note0 50, 0x3, 127, 127
layer_note0 38, 0x3, 127, 127
.layer_32EE:
layer_delay 0x2a
layer_jump .layer_32E6

# padding
.byte 0

.envelope_32F4:
envelope_line 7 20000
envelope_line 6 32700
envelope_line 32700 32700
envelope_goto 2

.envelope_3304:
envelope_line 9 15000
envelope_line 7 32700
envelope_line 32700 32700
envelope_goto 2

.envelope_3314:
envelope_line 10 10000
envelope_line 100 32700
envelope_line 32700 32700
envelope_goto 2

.envelope_3324:
envelope_line 35 32700
envelope_line 10 32700
envelope_line 300 0
envelope_goto 2

.envelope_3334:
envelope_line 15 20000
envelope_line 5 32700
envelope_line 32700 32700
envelope_goto 2

.envelope_3344:
envelope_line 8 32700
envelope_line 50 32700
envelope_line 300 0
envelope_goto 2

.envelope_3354:
envelope_line 100 25000
envelope_line 35 32700
envelope_line 300 5000
envelope_goto 2

.envelope_3364:
envelope_line 25 32700
envelope_line 4 22500
envelope_line 35 32700
envelope_goto 2

.envelope_3374:
envelope_line 1 32700
envelope_line 10 30000
envelope_line 50 30000
envelope_line 100 0
envelope_goto 3

.envelope_3388:
envelope_line 4 32700
envelope_line 100 15000
envelope_line 1000 0
envelope_goto 2

.envelope_3398:
envelope_line 10 32700
envelope_line 1 32700
envelope_line 10 0
envelope_goto 2

.envelope_33A8:
envelope_line 3 32700
envelope_line 10 30000
envelope_line 10 10000
envelope_line 100 0
envelope_goto 3

.envelope_33BC:
envelope_line 1 32700
envelope_line 20 32700
envelope_line 600 6000
envelope_goto 2

.envelope_unused_33CC:
envelope_line 1 32700
envelope_line 20 32700
envelope_line 100 18000
envelope_goto 2

.envelope_33DC:
envelope_line 1 32700
envelope_line 20 32700
envelope_line 300 6000
envelope_goto 2

.envelope_33EC:
envelope_line 7 18000
envelope_line 4 32760
envelope_line 30 0
envelope_goto 2

.envelope_33FC:
envelope_line 19 32700
envelope_line 5 32700
envelope_line 15 0
envelope_goto 2

.envelope_340C:
envelope_line 25 32700
envelope_line 9 32700
envelope_line 9 0
envelope_goto 2

.envelope_341C:
envelope_line 1 32700
envelope_line 100 32760
envelope_line 300 0
envelope_goto 2

.envelope_342C:
envelope_line 22 32700
envelope_line 50 32760
envelope_line 70 0
envelope_goto 2

.envelope_343C:
envelope_line 5 32760
envelope_line 192 0
envelope_line 1000 1000
envelope_goto 2

.envelope_344C:
envelope_line 25 32760
envelope_line 60 10000
envelope_goto 2

.envelope_3458:
envelope_line 1 10000
envelope_line 1 10000
envelope_line 40 32760
envelope_goto 2

.envelope_3468:
envelope_line 23 32760
envelope_line 80 15000
envelope_goto 2

.envelope_3474:
envelope_line 22 32760
envelope_line 50 32760
envelope_line 100 25000
envelope_goto 2

.envelope_3484:
envelope_line 13 32760
envelope_line 50 32760
envelope_line 200 0
envelope_goto 2

.envelope_3494:
envelope_line 6 12000
envelope_line 4 32760
envelope_line 50 32760
envelope_line 200 0
envelope_goto 2

.envelope_unused_34A8:
envelope_line 1 32700
envelope_line 1000 32700
envelope_line 10 16000
envelope_line 200 32760
envelope_goto 3
