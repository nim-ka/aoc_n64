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
seq_startchannel 1, .chan_98
seq_startchannel 2, .chan_40
seq_startchannel 3, .chan_51
seq_startchannel 4, .chan_AB
seq_startchannel 5, .chan_62
seq_startchannel 6, .chan_BE
seq_startchannel 7, .chan_F1
seq_startchannel 8, .chan_51
seq_startchannel 9, .chan_62
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
chan_setdyntable .table_14C
chan_jump .chan_73

.chan_40:
chan_largenoteson
chan_setinstr 0
chan_setpanmix 127
chan_setnotepriority 14
chan_setval 0
chan_iowriteval 5
chan_stereoheadseteffects 1
chan_setdyntable .table_B66
chan_jump .chan_73

.chan_51:
chan_largenoteson
chan_setinstr 0
chan_setpanmix 127
chan_setnotepriority 14
chan_setval 0
chan_iowriteval 5
chan_stereoheadseteffects 1
chan_setdyntable .table_E09
chan_jump .chan_73

.chan_62:
chan_largenoteson
chan_setinstr 0
chan_setpanmix 127
chan_setnotepriority 14
chan_setval 0
chan_iowriteval 5
chan_stereoheadseteffects 1
chan_setdyntable .table_1CA6
chan_jump .chan_73
.chan_73:
chan_delay1
chan_ioreadval 0
chan_bltz .chan_73
.chan_78:
chan_freelayer 0
chan_freelayer 1
chan_freelayer 2
chan_setval 0
chan_iowriteval 5
chan_ioreadval 4
chan_dyncall
.chan_80:
chan_delay1
chan_ioreadval 0
chan_bltz .chan_8B
chan_beqz .chan_92
chan_jump .chan_78
.chan_8B:
chan_testlayerfinished 0
chan_beqz .chan_80
chan_jump .chan_73
.chan_92:
chan_freelayer 0
chan_freelayer 1
chan_freelayer 2
chan_jump .chan_73

.chan_98:
chan_largenoteson
chan_setinstr 0
chan_setpanmix 127
chan_setnotepriority 14
chan_setval 0
chan_iowriteval 5
chan_setmutebhv 0x20
chan_stereoheadseteffects 1
chan_setdyntable .table_8A8
chan_jump .chan_D1

.chan_AB:
chan_largenoteson
chan_setinstr 0
chan_setpanmix 127
chan_setnotepriority 14
chan_setval 0
chan_iowriteval 5
chan_setmutebhv 0x20
chan_stereoheadseteffects 1
chan_setdyntable .table_194B
chan_jump .chan_D1

.chan_BE:
chan_largenoteson
chan_setinstr 0
chan_setpanmix 127
chan_setnotepriority 14
chan_setval 0
chan_iowriteval 5
chan_setmutebhv 0x20
chan_stereoheadseteffects 1
chan_setdyntable .table_27C9
chan_jump .chan_D1
.chan_D1:
chan_delay1
chan_ioreadval 0
chan_bltz .chan_D1
.chan_D6:
chan_freelayer 0
chan_freelayer 1
chan_freelayer 2
chan_setvolscale 127
chan_setval 0
chan_iowriteval 5
chan_ioreadval 4
chan_dyncall
.chan_E0:
chan_delay1
chan_ioreadval 0
chan_bltz .chan_E0
chan_beqz .chan_EB
chan_jump .chan_D6
.chan_EB:
chan_freelayer 0
chan_freelayer 1
chan_freelayer 2
chan_jump .chan_D1

.chan_F1:
chan_largenoteson
chan_setinstr 0
chan_setnotepriority 14
chan_setval 0
chan_iowriteval 5
chan_stereoheadseteffects 1
chan_setdyntable .table_2975
.chan_FD:
chan_delay1
chan_ioreadval 0
chan_bltz .chan_FD
.chan_102:
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
.chan_110:
chan_delay1
chan_ioreadval 0
chan_bltz .chan_11C
chan_beqz .chan_124
chan_unreservenotes
chan_jump .chan_102
.chan_11C:
chan_testlayerfinished 0
chan_beqz .chan_110
chan_unreservenotes
chan_jump .chan_FD
.chan_124:
chan_freelayer 0
chan_freelayer 1
chan_freelayer 2
chan_unreservenotes
chan_jump .chan_FD

.chan_fn_12B:
chan_writeseq_nextinstr 0, 1
chan_loop 20
chan_delay1
chan_ioreadval 0
chan_iowriteval 1
chan_bgez .chan_139
chan_loopend
chan_end
.chan_139:
chan_setpanmix 127
chan_setvolscale 127
chan_setvibratoextent 0
chan_ioreadval 1
chan_iowriteval 0
chan_break
chan_break
chan_end

.chan_fn_144:
chan_writeseq_nextinstr 0, 1
chan_setreverb 10
chan_iowriteval 5
chan_end

.table_14C:
sound_ref .chan_22C
sound_ref .chan_23B
sound_ref .chan_24A
sound_ref .chan_259
sound_ref .chan_268
sound_ref .chan_277
sound_ref .chan_286
sound_ref .chan_295
sound_ref .chan_2A6
sound_ref .chan_2B5
sound_ref .chan_2C4
sound_ref .chan_2D3
sound_ref .chan_2E2
sound_ref .chan_2F1
sound_ref .chan_300
sound_ref .chan_30F
sound_ref .chan_320
sound_ref .chan_32C
sound_ref .chan_338
sound_ref .chan_344
sound_ref .chan_350
sound_ref .chan_35C
sound_ref .chan_368
sound_ref .chan_374
sound_ref .chan_380
sound_ref .chan_38F
sound_ref .chan_39E
sound_ref .chan_3AD
sound_ref .chan_3BC
sound_ref .chan_3CB
sound_ref .chan_3DA
sound_ref .chan_3E9
sound_ref .chan_3FA
sound_ref .chan_406
sound_ref .chan_412
sound_ref .chan_41E
sound_ref .chan_42A
sound_ref .chan_436
sound_ref .chan_442
sound_ref .chan_44E
sound_ref .chan_45A
sound_ref .chan_469
sound_ref .chan_478
sound_ref .chan_488
sound_ref .chan_497
sound_ref .chan_4A9
sound_ref .chan_4C5
sound_ref .chan_4D5
sound_ref .chan_4E5
sound_ref .chan_4F1
sound_ref .chan_4FD
sound_ref .chan_512
sound_ref .chan_522
sound_ref .chan_52E
sound_ref .chan_540
sound_ref .chan_54C
sound_ref .chan_54C
sound_ref .chan_54C
sound_ref .chan_55E
sound_ref .chan_571
sound_ref .chan_582
sound_ref .chan_591
sound_ref .chan_5A3
sound_ref .chan_5B5
sound_ref .chan_5C1
sound_ref .chan_5D3
sound_ref .chan_5E9
sound_ref .chan_5F8
sound_ref .chan_604
sound_ref .chan_651
sound_ref .chan_664
sound_ref .chan_6A9
sound_ref .chan_6C9
sound_ref .chan_6C9
sound_ref .chan_6C9
sound_ref .chan_6C9
sound_ref .chan_6C9
sound_ref .chan_6DC
sound_ref .chan_6EB
sound_ref .chan_6EB
sound_ref .chan_6FA
sound_ref .chan_70C
sound_ref .chan_71E
sound_ref .chan_731
sound_ref .chan_743
sound_ref .chan_756
sound_ref .chan_766
sound_ref .chan_782
sound_ref .chan_7A5
sound_ref .chan_7C5
sound_ref .chan_7ED
sound_ref .chan_801
sound_ref .chan_810
sound_ref .chan_22C
sound_ref .chan_22C
sound_ref .chan_22C
sound_ref .chan_828
sound_ref .chan_838
sound_ref .chan_848
sound_ref .chan_858
sound_ref .chan_868
sound_ref .chan_878
sound_ref .chan_888
sound_ref .chan_898
sound_ref .chan_22C
sound_ref .chan_22C
sound_ref .chan_22C
sound_ref .chan_22C
sound_ref .chan_22C
sound_ref .chan_22C
sound_ref .chan_22C
sound_ref .chan_22C

.chan_22C:
chan_setbank 1
chan_setinstr 0
chan_setlayer 0, .layer_234
chan_end

.layer_234:
layer_note1 41, 0xc, 117
layer_note1 46, 0x18, 117
layer_end

.chan_23B:
chan_setbank 1
chan_setinstr 1
chan_setlayer 0, .layer_243
chan_end

.layer_243:
layer_note1 41, 0xc, 120
layer_note1 50, 0x18, 120
layer_end

.chan_24A:
chan_setbank 2
chan_setinstr 1
chan_setlayer 0, .layer_252
chan_end

.layer_252:
layer_note1 41, 0x6, 80
layer_note1 50, 0x18, 80
layer_end

.chan_259:
chan_setbank 1
chan_setinstr 3
chan_setlayer 0, .layer_261
chan_end

.layer_261:
layer_note1 41, 0xc, 127
layer_note1 50, 0x18, 127
layer_end

.chan_268:
chan_setbank 1
chan_setinstr 4
chan_setlayer 0, .layer_270
chan_end

.layer_270:
layer_note1 41, 0xc, 90
layer_note1 50, 0x18, 90
layer_end

.chan_277:
chan_setbank 1
chan_setinstr 5
chan_setlayer 0, .layer_27F
chan_end

.layer_27F:
layer_note1 41, 0xc, 80
layer_note1 50, 0x18, 80
layer_end

.chan_286:
chan_setbank 1
chan_setinstr 6
chan_setlayer 0, .layer_28E
chan_end

.layer_28E:
layer_note1 29, 0xc, 127
layer_note1 38, 0x18, 127
layer_end

.chan_295:
chan_setbank 1
chan_setinstr 8
chan_setlayer 0, .layer_29D
chan_end

.layer_29D:
layer_note0 34, 0xc, 100, 127
layer_note0 43, 0x24, 100, 127
layer_end

.chan_2A6:
chan_setbank 1
chan_setinstr 0
chan_setlayer 0, .layer_2AE
chan_end

.layer_2AE:
layer_note1 46, 0xc, 117
layer_note1 41, 0x18, 117
layer_end

.chan_2B5:
chan_setbank 1
chan_setinstr 1
chan_setlayer 0, .layer_2BD
chan_end

.layer_2BD:
layer_note1 50, 0xc, 120
layer_note1 41, 0x18, 120
layer_end

.chan_2C4:
chan_setbank 2
chan_setinstr 1
chan_setlayer 0, .layer_2CC
chan_end

.layer_2CC:
layer_note1 50, 0xc, 80
layer_note1 41, 0x18, 80
layer_end

.chan_2D3:
chan_setbank 1
chan_setinstr 3
chan_setlayer 0, .layer_2DB
chan_end

.layer_2DB:
layer_note1 50, 0xc, 127
layer_note1 41, 0x18, 127
layer_end

.chan_2E2:
chan_setbank 1
chan_setinstr 4
chan_setlayer 0, .layer_2EA
chan_end

.layer_2EA:
layer_note1 50, 0xc, 90
layer_note1 41, 0x18, 90
layer_end

.chan_2F1:
chan_setbank 1
chan_setinstr 5
chan_setlayer 0, .layer_2F9
chan_end

.layer_2F9:
layer_note1 50, 0xc, 80
layer_note1 41, 0x18, 80
layer_end

.chan_300:
chan_setbank 1
chan_setinstr 6
chan_setlayer 0, .layer_308
chan_end

.layer_308:
layer_note1 38, 0xc, 127
layer_note1 29, 0x18, 127
layer_end

.chan_30F:
chan_setbank 1
chan_setinstr 8
chan_setlayer 0, .layer_317
chan_end

.layer_317:
layer_note0 43, 0xc, 100, 127
layer_note0 34, 0x24, 100, 127
layer_end

.chan_320:
chan_setbank 1
chan_setinstr 0
chan_setlayer 0, .layer_328
chan_end

.layer_328:
layer_note1 39, 0x18, 85
layer_end

.chan_32C:
chan_setbank 1
chan_setinstr 1
chan_setlayer 0, .layer_334
chan_end

.layer_334:
layer_note1 39, 0x18, 100
layer_end

.chan_338:
chan_setbank 2
chan_setinstr 1
chan_setlayer 0, .layer_340
chan_end

.layer_340:
layer_note1 43, 0x18, 63
layer_end

.chan_344:
chan_setbank 1
chan_setinstr 3
chan_setlayer 0, .layer_34C
chan_end

.layer_34C:
layer_note1 39, 0x18, 77
layer_end

.chan_350:
chan_setbank 1
chan_setinstr 4
chan_setlayer 0, .layer_358
chan_end

.layer_358:
layer_note1 39, 0x18, 70
layer_end

.chan_35C:
chan_setbank 1
chan_setinstr 5
chan_setlayer 0, .layer_364
chan_end

.layer_364:
layer_note1 39, 0x18, 68
layer_end

.chan_368:
chan_setbank 1
chan_setinstr 6
chan_setlayer 0, .layer_370
chan_end

.layer_370:
layer_note1 39, 0x18, 100
layer_end

.chan_374:
chan_setbank 1
chan_setinstr 8
chan_setlayer 0, .layer_37C
chan_end

.layer_37C:
layer_note1 39, 0x18, 70
layer_end

.chan_380:
chan_setbank 1
chan_setinstr 0
chan_setlayer 0, .layer_388
chan_end

.layer_388:
layer_note1 17, 0xc, 117
layer_note1 19, 0x18, 117
layer_end

.chan_38F:
chan_setbank 1
chan_setinstr 1
chan_setlayer 0, .layer_397
chan_end

.layer_397:
layer_note1 29, 0xc, 120
layer_note1 31, 0x18, 120
layer_end

.chan_39E:
chan_setbank 2
chan_setinstr 1
chan_setlayer 0, .layer_3A6
chan_end

.layer_3A6:
layer_note1 34, 0xc, 80
layer_note1 39, 0x18, 80
layer_end

.chan_3AD:
chan_setbank 1
chan_setinstr 3
chan_setlayer 0, .layer_3B5
chan_end

.layer_3B5:
layer_note1 29, 0xc, 115
layer_note1 31, 0xc, 115
layer_end

.chan_3BC:
chan_setbank 1
chan_setinstr 4
chan_setlayer 0, .layer_3C4
chan_end

.layer_3C4:
layer_note1 29, 0xc, 90
layer_note1 31, 0x18, 90
layer_end

.chan_3CB:
chan_setbank 1
chan_setinstr 5
chan_setlayer 0, .layer_3D3
chan_end

.layer_3D3:
layer_note1 34, 0xc, 80
layer_note1 36, 0x18, 80
layer_end

.chan_3DA:
chan_setbank 1
chan_setinstr 6
chan_setlayer 0, .layer_3E2
chan_end

.layer_3E2:
layer_note1 29, 0xc, 127
layer_note1 31, 0x18, 127
layer_end

.chan_3E9:
chan_setbank 1
chan_setinstr 8
chan_setlayer 0, .layer_3F1
chan_end

.layer_3F1:
layer_note0 31, 0xc, 100, 127
layer_note0 32, 0x24, 100, 127
layer_end

.chan_3FA:
chan_setbank 1
chan_setinstr 0
chan_setlayer 0, .layer_402
chan_end

.layer_402:
layer_note1 37, 0x18, 63
layer_end

.chan_406:
chan_setbank 1
chan_setinstr 1
chan_setlayer 0, .layer_40E
chan_end

.layer_40E:
layer_note1 37, 0x18, 57
layer_end

.chan_412:
chan_setbank 2
chan_setinstr 1
chan_setlayer 0, .layer_41A
chan_end

.layer_41A:
layer_note1 39, 0x18, 39
layer_end

.chan_41E:
chan_setbank 1
chan_setinstr 3
chan_setlayer 0, .layer_426
chan_end

.layer_426:
layer_note1 37, 0x18, 49
layer_end

.chan_42A:
chan_setbank 1
chan_setinstr 4
chan_setlayer 0, .layer_432
chan_end

.layer_432:
layer_note1 37, 0x18, 39
layer_end

.chan_436:
chan_setbank 1
chan_setinstr 5
chan_setlayer 0, .layer_43E
chan_end

.layer_43E:
layer_note1 37, 0x18, 39
layer_end

.chan_442:
chan_setbank 1
chan_setinstr 6
chan_setlayer 0, .layer_44A
chan_end

.layer_44A:
layer_note1 37, 0x18, 70
layer_end

.chan_44E:
chan_setbank 1
chan_setinstr 8
chan_setlayer 0, .layer_456
chan_end

.layer_456:
layer_note1 35, 0x18, 49
layer_end

.chan_45A:
chan_setbank 1
chan_setinstr 7
chan_setlayer 0, .layer_462
chan_end

.layer_462:
layer_note1 29, 0xc, 100
layer_note1 38, 0x12, 100
layer_end

.chan_469:
chan_setbank 1
chan_setinstr 7
chan_setlayer 0, .layer_471
chan_end

.layer_471:
layer_note1 38, 0xc, 100
layer_note1 29, 0x18, 100
layer_end

.chan_478:
chan_setbank 1
chan_setinstr 7
chan_setlayer 0, .layer_480
chan_end

.layer_480:
layer_portamento 0x85, 27, 255
layer_note1 31, 0x10, 100
layer_end

.chan_488:
chan_setbank 1
chan_setinstr 7
chan_setlayer 0, .layer_490
chan_end

.layer_490:
layer_note1 20, 0xc, 100
layer_note1 24, 0x18, 100
layer_end

.chan_497:
chan_setbank 3
chan_setinstr 6
chan_setenvelope .envelope_308C
chan_setlayer 0, .layer_4A2
chan_end

.layer_4A2:
layer_note1 62, 0x6, 90
layer_note1 58, 0x7, 90
layer_end

.chan_4A9:
chan_setbank 0
chan_setinstr 2
chan_setlayer 0, .layer_4BD
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 3
chan_setinstr 1
chan_setenvelope .envelope_305C
chan_end

.layer_4BD:
layer_note1 62, 0x4, 127
layer_note0 56, 0x3, 127, 80
layer_end

.chan_4C5:
chan_setbank 1
chan_setinstr 8
chan_setlayer 0, .layer_4CD
chan_end

.layer_4CD:
layer_portamento 0x1, 29, 0x12
layer_note1 24, 0x12, 115
layer_end

.chan_4D5:
chan_setbank 1
chan_setinstr 7
chan_setlayer 0, .layer_4DD
chan_end

.layer_4DD:
layer_portamento 0x85, 25, 255
layer_note1 29, 0x10, 70
layer_end

.chan_4E5:
chan_setbank 2
chan_setinstr 0
chan_setlayer 0, .layer_4ED
chan_end

.layer_4ED:
layer_note1 39, 0x7f, 100
layer_end

.chan_4F1:
chan_setbank 2
chan_setinstr 1
chan_setlayer 0, .layer_4F9
chan_end

.layer_4F9:
layer_note1 36, 0x64, 90
layer_end

.chan_4FD:
chan_setbank 2
chan_setlayer 0, .layer_503
chan_end

.layer_503:
layer_setinstr 2
layer_note1 36, 0xa, 80
layer_setinstr 0
layer_portamento 0x81, 36, 255
layer_note1 50, 0x32, 80
layer_end

.chan_512:
chan_setbank 2
chan_setinstr 2
chan_setlayer 0, .layer_51A
chan_end

.layer_51A:
layer_portamento 0x81, 35, 255
layer_note1 30, 0x3c, 110
layer_end

.chan_522:
chan_setbank 2
chan_setinstr 2
chan_setlayer 0, .layer_52A
chan_end

.layer_52A:
layer_note1 39, 0x7f, 115
layer_end

.chan_52E:
chan_setbank 0
chan_setinstr 0
chan_setlayer 0, .layer_538
chan_end

.layer_536:
layer_transpose 1

.layer_538:
layer_portamento 0x81, 46, 255
layer_note1 31, 0xf, 100
layer_end

.chan_540:
chan_setbank 0
chan_setinstr 0
chan_setlayer 0, .layer_548
chan_end

.layer_548:
layer_note1 39, 0x12, 100
layer_end

.chan_54C:
chan_setbank 0
chan_setinstr 0
chan_setdecayrelease 30
chan_setlayer 0, .layer_556
chan_end

.layer_556:
layer_portamento 0x81, 34, 255
layer_note1 41, 0xc, 127
layer_end

.chan_55E:
chan_setbank 0
chan_setinstr 1
chan_setlayer 0, .layer_566
chan_end

.layer_566:
layer_note1 37, 0xa, 105
layer_portamento 0x81, 42, 255
layer_note1 37, 0x1e, 105
layer_end

.chan_571:
chan_setbank 0
chan_setinstr 1
chan_setlayer 0, .layer_579
chan_end

.layer_579:
layer_portamento 0x81, 44, 255
layer_note1 40, 0xb4, 100
layer_end

.chan_582:
chan_setbank 0
chan_setinstr 2
chan_setlayer 0, .layer_58A
chan_end

.layer_58A:
layer_note1 39, 0x4, 127
layer_note1 41, 0x12, 127
layer_end

.chan_591:
chan_setbank 1
chan_setinstr 1
chan_setenvelope .envelope_304C
chan_setlayer 0, .layer_59C
chan_end

.layer_59C:
layer_note1 38, 0x6, 127
layer_note1 41, 0x6, 127
layer_end

.chan_5A3:
chan_setbank 1
chan_setinstr 1
chan_setenvelope .envelope_304C
chan_setlayer 0, .layer_5AE
chan_end

.layer_5AE:
layer_note1 41, 0x6, 127
layer_note1 38, 0x6, 127
layer_end

.chan_5B5:
chan_setbank 0
chan_setinstr 2
chan_setlayer 0, .layer_5BD
chan_end

.layer_5BD:
layer_note1 32, 0xa, 127
layer_end

.chan_5C1:
chan_setbank 0
chan_setinstr 1
chan_setenvelope .envelope_304C
chan_setlayer 0, .layer_5CC
chan_end

.layer_5CC:
layer_note1 39, 0x8, 90
layer_note1 41, 0x8, 90
layer_end

.chan_5D3:
chan_setbank 3
chan_setinstr 1
chan_setenvelope .envelope_306C
chan_setlayer 0, .layer_5DE
chan_end

.layer_5DE:
layer_portamento 0x85, 53, 255
layer_note1 55, 0xc, 127
layer_note1 53, 0x18, 127
layer_end

.chan_5E9:
chan_setbank 1
chan_setinstr 7
chan_setlayer 0, .layer_5F1
chan_end

.layer_5F1:
layer_note1 39, 0x7, 100
layer_note1 20, 0x18, 115
layer_end

.chan_5F8:
chan_setbank 0
chan_setinstr 4
chan_setlayer 0, .layer_600
chan_end

.layer_600:
layer_note1 37, 0x48, 127
layer_end

.chan_604:
chan_setbank 7
chan_setinstr 3
chan_setlayer 0, .layer_618
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 6
chan_setinstr 10
chan_setenvelope .envelope_309C
chan_end

.layer_618:
layer_portamento 0x81, 27, 255
layer_note1 46, 0xb, 127
.layer_61F:
layer_somethingon
layer_portamento 0x85, 32, 255
layer_note1 44, 0x5, 100
layer_call .layer_fn_64A
layer_transpose 1
layer_call .layer_fn_64A
layer_transpose 3
layer_call .layer_fn_64A
layer_transpose 4
layer_call .layer_fn_64A
layer_transpose 6
layer_call .layer_fn_64A
layer_transpose 7
layer_call .layer_fn_64A
layer_transpose 9
layer_call .layer_fn_64A
layer_transpose 10

.layer_fn_64A:
layer_note1 20, 0x5, 115
layer_note1 32, 0x5, 115
layer_end

.chan_651:
chan_setbank 7
chan_setinstr 3
chan_setlayer 0, .layer_659
chan_end

.layer_659:
layer_portamento 0x82, 19, 255
layer_note1 34, 0x5, 110
layer_note1 39, 0x2, 110
layer_end

.chan_664:
chan_setbank 3
chan_setinstr 3
chan_setval 50
chan_call .chan_fn_144
chan_setenvelope .envelope_30AC
chan_setlayer 0, .layer_68F
chan_delay 0x1
chan_setlayer 1, .layer_6A1
chan_setbank 9
chan_setinstr 1
chan_setenvelope .envelope_305C
chan_setdecayrelease 20
chan_delay 0x1
chan_setlayer 2, .layer_699
chan_setbank 4
chan_setinstr 14
chan_setdecayrelease 12
chan_setvibratoextent 10
chan_end

.layer_68F:
layer_transpose 36
layer_portamento 0x81, 62, 255
layer_note1 38, 0x7f, 127
layer_end

.layer_699:
layer_portamento 0x81, 39, 255
layer_note1 15, 0x7f, 127
layer_end

.layer_6A1:
layer_portamento 0x81, 62, 255
layer_note1 38, 0x7f, 100
layer_end

.chan_6A9:
chan_setbank 2
chan_setinstr 2
chan_setval 20
chan_call .chan_fn_144
chan_setlayer 0, .layer_6C1
chan_setlayer 1, .layer_6B9
chan_end

.layer_6B9:
layer_portamento 0x81, 23, 255
layer_note1 59, 0x30, 120
layer_end

.layer_6C1:
layer_portamento 0x81, 35, 255
layer_note1 42, 0x3c, 110
layer_end

.chan_6C9:
chan_setbank 1
chan_setinstr 0
chan_setlayer 0, .layer_6D1
chan_end

.layer_6D1:
layer_note1 17, 0x6, 127
layer_portamento 0x81, 31, 255
layer_note1 7, 0xc, 127
layer_end

.chan_6DC:
chan_setbank 1
chan_setinstr 5
chan_setlayer 0, .layer_6E4
chan_end

.layer_6E4:
layer_note1 23, 0x6, 127
layer_note1 25, 0xc, 127
layer_end

.chan_6EB:
chan_setbank 1
chan_setinstr 8
chan_setlayer 0, .layer_6F3
chan_end

.layer_6F3:
layer_note1 17, 0x6, 127
layer_note1 19, 0xc, 127
layer_end

.chan_6FA:
chan_setbank 1
chan_setinstr 7
chan_setenvelope .envelope_309C
chan_setlayer 0, .layer_705
chan_end

.layer_705:
layer_note1 20, 0xf, 90
layer_note1 29, 0x17, 90
layer_end

.chan_70C:
chan_setbank 1
chan_setinstr 7
chan_setenvelope .envelope_309C
chan_setlayer 0, .layer_717
chan_end

.layer_717:
layer_note1 29, 0xf, 90
layer_note1 20, 0x1f, 90
layer_end

.chan_71E:
chan_setbank 1
chan_setinstr 7
chan_setenvelope .envelope_309C
chan_setlayer 0, .layer_729
chan_end

.layer_729:
layer_portamento 0x85, 18, 255
layer_note1 22, 0x15, 90
layer_end

.chan_731:
chan_setbank 1
chan_setinstr 7
chan_setenvelope .envelope_309C
chan_setlayer 0, .layer_73C
chan_end

.layer_73C:
layer_note1 11, 0xf, 90
layer_note1 15, 0x1f, 90
layer_end

.chan_743:
chan_setbank 1
chan_setinstr 7
chan_setenvelope .envelope_309C
chan_setlayer 0, .layer_74E
chan_end

.layer_74E:
layer_portamento 0x85, 18, 255
layer_note1 22, 0x10, 90
layer_end

.chan_756:
chan_setbank 6
chan_setinstr 10
chan_setenvelope .envelope_309C
chan_setlayer 0, .layer_761
chan_end

.layer_761:
layer_transpose 8
layer_jump .layer_61F

.chan_766:
chan_setbank 5
chan_setinstr 6
chan_setenvelope .envelope_3120
chan_setlayer 0, .layer_774
chan_setlayer 1, .layer_776
chan_end

.layer_774:
layer_transpose 12

.layer_776:
layer_somethingon
layer_portamento 0x85, 27, 255
layer_note1 51, 0x14, 127
layer_note1 36, 0x5a, 127
layer_end

.chan_782:
chan_setbank 9
chan_setinstr 3
chan_setvibratoextent 60
chan_setvibratorate 60
chan_setenvelope .envelope_306C
chan_setlayer 0, .layer_79D
chan_setlayer 1, .layer_79B
chan_setval 36
chan_call .chan_fn_12B
chan_setvibratoextent 0
chan_end

.layer_79B:
layer_transpose 1

.layer_79D:
layer_portamento 0x81, 20, 100
layer_note1 27, 0x30, 127
layer_end

.chan_7A5:
chan_setbank 1
chan_setinstr 7
chan_setenvelope .envelope_30CC
chan_setlayer 0, .layer_7B9
chan_setval 4
chan_call .chan_fn_12B
chan_setbank 9
chan_setinstr 3
chan_end

.layer_7B9:
layer_note1 43, 0x3, 115
layer_note1 48, 0x5, 115
layer_transpose 12
layer_note1 55, 0x6, 80
layer_end

.chan_7C5:
chan_setbank 7
chan_setinstr 3
chan_setlayer 0, .layer_7D9
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 6
chan_setinstr 10
chan_setenvelope .envelope_309C
chan_end

.layer_7D9:
layer_portamento 0x81, 27, 255
layer_note1 41, 0xb, 127
layer_somethingon
layer_transpose 252
layer_portamento 0x85, 32, 255
layer_note1 44, 0x5, 100
layer_jump .layer_fn_64A

.chan_7ED:
chan_setbank 0
chan_setinstr 3
chan_setdecayrelease 30
chan_setlayer 0, .layer_7F7
chan_end

.layer_7F7:
layer_setinstr 0
layer_portamento 0x81, 32, 255
layer_note1 39, 0x24, 127
layer_end

.chan_801:
chan_jump .chan_2C08

.chan_fn_804:
chan_setbank 0
chan_setinstr 5
chan_setlayer 0, .layer_80C
chan_end

.layer_80C:
layer_note1 41, 0x3c, 127
layer_end

.chan_810:
chan_setbank 1
chan_setinstr 1
chan_setenvelope .envelope_304C
chan_setlayer 0, .layer_81B
chan_end

.layer_81B:
layer_note1 38, 0x8, 127
layer_note1 41, 0x9, 127
layer_note1 39, 0xa, 127
layer_note1 42, 0x8, 127
layer_end

.chan_828:
chan_call .chan_fn_804
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 1
chan_setinstr 0
chan_setlayer 1, .layer_388
chan_end

.chan_838:
chan_call .chan_fn_804
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 1
chan_setinstr 1
chan_setlayer 1, .layer_397
chan_end

.chan_848:
chan_call .chan_fn_804
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 2
chan_setinstr 1
chan_setlayer 1, .layer_3A6
chan_end

.chan_858:
chan_call .chan_fn_804
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 1
chan_setinstr 3
chan_setlayer 1, .layer_3B5
chan_end

.chan_868:
chan_call .chan_fn_804
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 1
chan_setinstr 4
chan_setlayer 1, .layer_3C4
chan_end

.chan_878:
chan_call .chan_fn_804
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 1
chan_setinstr 5
chan_setlayer 1, .layer_3D3
chan_end

.chan_888:
chan_call .chan_fn_804
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 1
chan_setinstr 6
chan_setlayer 1, .layer_3E2
chan_end

.chan_898:
chan_call .chan_fn_804
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 1
chan_setinstr 8
chan_setlayer 1, .layer_3F1
chan_end

.table_8A8:
sound_ref .chan_918
sound_ref .chan_929
sound_ref .chan_946
sound_ref .chan_96D
sound_ref .chan_97E
sound_ref .chan_99B
sound_ref .chan_9AC
sound_ref .chan_9BD
sound_ref .chan_918
sound_ref .chan_929
sound_ref .chan_946
sound_ref .chan_96D
sound_ref .chan_97E
sound_ref .chan_99B
sound_ref .chan_9AC
sound_ref .chan_9BD
sound_ref .chan_9DA
sound_ref .chan_9EB
sound_ref .chan_9FF
sound_ref .chan_104B
sound_ref .chan_A14
sound_ref .chan_104B
sound_ref .chan_A29
sound_ref .chan_A3E
sound_ref .chan_A55
sound_ref .chan_A72
sound_ref .chan_A75
sound_ref .chan_96D
sound_ref .chan_97E
sound_ref .chan_99B
sound_ref .chan_9AC
sound_ref .chan_9BD
sound_ref .chan_A9C
sound_ref .chan_AA9
sound_ref .chan_ABF
sound_ref .chan_ADD
sound_ref .chan_AEA
sound_ref .chan_B00
sound_ref .chan_B0D
sound_ref .chan_B1A
sound_ref .chan_B30
sound_ref .chan_AA9
sound_ref .chan_ABF
sound_ref .chan_ADD
sound_ref .chan_AEA
sound_ref .chan_B00
sound_ref .chan_B0D
sound_ref .chan_B1A
sound_ref .chan_A9C
sound_ref .chan_AA9
sound_ref .chan_ABF
sound_ref .chan_ADD
sound_ref .chan_AEA
sound_ref .chan_B00
sound_ref .chan_B0D
sound_ref .chan_B1A

.chan_918:
chan_setbank 3
chan_setinstr 0
chan_setlayer 0, .layer_920
chan_end

.layer_920:
layer_somethingon
.layer_921:
layer_note1 39, 0x12c, 80
layer_jump .layer_921
layer_end

.chan_929:
chan_setbank 1
chan_setinstr 1
chan_setlayer 0, .layer_93A
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 3
chan_setinstr 1
chan_end

.layer_93A:
layer_note1 41, 0x8, 105
layer_somethingon
.layer_93E:
layer_note1 39, 0x12c, 70
layer_jump .layer_93E
layer_end

.chan_946:
chan_setbank 2
chan_setinstr 1
chan_setlayer 0, .layer_95A
chan_setlayer 1, .layer_965
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 3
chan_setinstr 2
chan_end

.layer_95A:
layer_delay 0x1
layer_somethingon
.layer_95D:
layer_note1 39, 0x12c, 88
layer_jump .layer_95D
layer_end

.layer_965:
layer_portamento 0x81, 39, 255
layer_note1 48, 0x32, 80
layer_end

.chan_96D:
chan_setbank 3
chan_setinstr 3
chan_setlayer 0, .layer_975
chan_end

.layer_975:
layer_somethingon
.layer_976:
layer_note1 39, 0x12c, 68
layer_jump .layer_976
layer_end

.chan_97E:
chan_setbank 1
chan_setinstr 4
chan_setlayer 0, .layer_98F
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 3
chan_setinstr 4
chan_end

.layer_98F:
layer_note1 42, 0xc, 75
layer_somethingon
.layer_993:
layer_note1 39, 0x12c, 76
layer_jump .layer_993
layer_end

.chan_99B:
chan_setbank 3
chan_setinstr 5
chan_setlayer 0, .layer_9A3
chan_end

.layer_9A3:
layer_somethingon
.layer_9A4:
layer_note1 39, 0x12c, 80
layer_jump .layer_9A4
layer_end

.chan_9AC:
chan_setbank 3
chan_setinstr 6
chan_setlayer 0, .layer_9B4
chan_end

.layer_9B4:
layer_somethingon
.layer_9B5:
layer_note1 39, 0x12c, 100
layer_jump .layer_9B5
layer_end

.chan_9BD:
chan_setbank 1
chan_setinstr 8
chan_setlayer 0, .layer_9CE
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 3
chan_setinstr 7
chan_end

.layer_9CE:
layer_note1 42, 0xc, 100
layer_somethingon
.layer_9D2:
layer_note1 39, 0x12c, 81
layer_jump .layer_9D2
layer_end

.chan_9DA:
chan_setbank 3
chan_setinstr 8
chan_setlayer 0, .layer_9E2
chan_end

.layer_9E2:
layer_somethingon
.layer_9E3:
layer_note1 39, 0x12c, 120
layer_jump .layer_9E3
layer_end

.chan_9EB:
chan_setbank 3
chan_setinstr 1
chan_setenvelope .envelope_305C
chan_setlayer 0, .layer_9F6
chan_end

.layer_9F6:
layer_somethingon
.layer_9F7:
layer_note1 43, 0x12c, 80
layer_jump .layer_9F7
layer_end

.chan_9FF:
chan_setbank 0
chan_setinstr 1
chan_setlayer 0, .layer_A07
chan_end

.layer_A07:
layer_portamento 0x81, 44, 255
.layer_A0B:
layer_somethingon
layer_note1 40, 0xb4, 100
layer_jump .layer_A0B
layer_end

.chan_A14:
chan_setbank 3
chan_setinstr 7
chan_setlayer 0, .layer_A1C
chan_end

.layer_A1C:
layer_somethingon
layer_portamento 0x85, 37, 255
.layer_A21:
layer_note1 34, 0xc8, 127
layer_jump .layer_A21
layer_end

.chan_A29:
chan_setbank 3
chan_setinstr 9
chan_setlayer 0, .layer_A36
chan_setlayer 1, .layer_A34
chan_end

.layer_A34:
layer_transpose 24

.layer_A36:
layer_note1_long 43, 0x6, 127
layer_jump .layer_A36
layer_end

.chan_A3E:
chan_setbank 5
chan_setinstr 6
chan_setlayer 0, .layer_A4D
chan_setlayer 1, .layer_A49
chan_end

.layer_A49:
layer_setinstr 13
layer_transpose 244

.layer_A4D:
layer_somethingon
.layer_A4E:
layer_note1 43, 0x12c, 105
layer_jump .layer_A4E

.chan_A55:
chan_setbank 9
chan_setinstr 3
chan_setval 40
chan_call .chan_fn_144
chan_setenvelope .envelope_30CC
chan_setlayer 0, .layer_A65
chan_end

.layer_A65:
layer_transpose 12
.layer_A67:
layer_note0 60, 0xc, 100, 127
layer_note0 60, 0x30, 100, 127
layer_jump .layer_A67

.chan_A72:
chan_jump .chan_281A

.chan_A75:
chan_setbank 9
chan_setinstr 3
chan_setenvelope .envelope_30F0
chan_setlayer 0, .layer_A8A
chan_setlayer 1, .layer_A88
chan_setlayer 2, .layer_A86
chan_end

.layer_A86:
layer_delay 0x4

.layer_A88:
layer_delay 0x4

.layer_A8A:
layer_transpose 24
.layer_A8C:
layer_portamento 0x85, 32, 40
layer_note1 39, 0x9, 100
layer_note1 44, 0x6, 50
layer_note1 51, 0x3, 20
layer_jump .layer_A8C

.chan_A9C:
chan_setbank 3
chan_setinstr 0
chan_setlayer 0, .layer_AA4
chan_end

.layer_AA4:
layer_transpose 4
layer_jump .layer_920

.chan_AA9:
chan_setbank 1
chan_setinstr 1
chan_setlayer 0, .layer_ABA
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 3
chan_setinstr 1
chan_end

.layer_ABA:
layer_transpose 4
layer_jump .layer_93A

.chan_ABF:
chan_setbank 2
chan_setinstr 1
chan_setlayer 0, .layer_AD3
chan_setlayer 1, .layer_AD8
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 3
chan_setinstr 2
chan_end

.layer_AD3:
layer_transpose 4
layer_jump .layer_95A

.layer_AD8:
layer_transpose 4
layer_jump .layer_965

.chan_ADD:
chan_setbank 3
chan_setinstr 3
chan_setlayer 0, .layer_AE5
chan_end

.layer_AE5:
layer_transpose 4
layer_jump .layer_975

.chan_AEA:
chan_setbank 1
chan_setinstr 4
chan_setlayer 0, .layer_AFB
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 3
chan_setinstr 4
chan_end

.layer_AFB:
layer_transpose 4
layer_jump .layer_98F

.chan_B00:
chan_setbank 3
chan_setinstr 5
chan_setlayer 0, .layer_B08
chan_end

.layer_B08:
layer_transpose 4
layer_jump .layer_9A3

.chan_B0D:
chan_setbank 3
chan_setinstr 6
chan_setlayer 0, .layer_B15
chan_end

.layer_B15:
layer_transpose 4
layer_jump .layer_9B4

.chan_B1A:
chan_setbank 1
chan_setinstr 8
chan_setlayer 0, .layer_B2B
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 3
chan_setinstr 7
chan_end

.layer_B2B:
layer_transpose 4
layer_jump .layer_9CE

.chan_B30:
chan_setlayer 0, .layer_B51
chan_setlayer 1, .layer_B5A
.chan_B36:
chan_setbank 3
chan_setinstr 2
chan_setval 1
chan_call .chan_fn_12B
chan_setdecayrelease 30
chan_setbank 2
chan_setinstr 1
chan_setenvelope .envelope_30BC
chan_setval 1
chan_call .chan_fn_12B
chan_jump .chan_B36
chan_end

.layer_B51:
layer_somethingon
.layer_B52:
layer_note1 42, 0x12c, 88
layer_jump .layer_B52
layer_end

.layer_B5A:
layer_delay 0x1
.layer_B5C:
layer_portamento 0x81, 41, 255
layer_note1 56, 0xa, 127
layer_jump .layer_B5C

.table_B66:
sound_ref .chan_BF4
sound_ref .chan_BE6
sound_ref .chan_BD6
sound_ref .chan_C06
sound_ref .chan_C16
sound_ref .chan_C2C
sound_ref .chan_C3E
sound_ref .chan_C4C
sound_ref .chan_C5A
sound_ref .chan_C68
sound_ref .chan_C76
sound_ref .chan_C84
sound_ref .chan_C92
sound_ref .chan_CA3
sound_ref .chan_CB1
sound_ref .chan_CBF
sound_ref .chan_CCD
sound_ref .chan_CDC
sound_ref .chan_D28
sound_ref .chan_CEA
sound_ref .chan_CF8
sound_ref .chan_D07
sound_ref .chan_D16
sound_ref .chan_D76
sound_ref .chan_D28
sound_ref .chan_D36
sound_ref .chan_D46
sound_ref .chan_D56
sound_ref .chan_D64
sound_ref .chan_D76
sound_ref .chan_D8C
sound_ref .chan_DA5
sound_ref .chan_DC3
sound_ref .chan_DD4
sound_ref .chan_DE0
sound_ref .chan_DE3
sound_ref .chan_DF0
sound_ref .chan_C2C
sound_ref .chan_C3E
sound_ref .chan_C4C
sound_ref .chan_BD6
sound_ref .chan_BD6
sound_ref .chan_BD6
sound_ref .chan_BD6
sound_ref .chan_BD6
sound_ref .chan_BD6
sound_ref .chan_BD6
sound_ref .chan_BD6
sound_ref .chan_BD6
sound_ref .chan_BD6
sound_ref .chan_BD6
sound_ref .chan_BD6
sound_ref .chan_BD6
sound_ref .chan_BD6
sound_ref .chan_BD6
sound_ref .chan_BD6

.chan_BD6:
chan_setbank 8
chan_setinstr 0
chan_setlayer 0, .layer_BDE
chan_end

.layer_BDE:
layer_portamento 0x82, 41, 127
layer_note1 37, 0x14, 127
layer_end

.chan_BE6:
chan_setbank 8
chan_setinstr 1
chan_setlayer 0, .layer_BEE
chan_end

.layer_BEE:
layer_transpose 254
.layer_BF0:
layer_note1 38, 0x18, 127
layer_end

.chan_BF4:
chan_setbank 10
chan_setinstr 9
chan_setlayer 0, .layer_BFC
chan_end

.layer_BFC:
layer_transpose 254
.layer_BFE:
layer_portamento 0x82, 39, 200
layer_note1 38, 0x24, 120
layer_end

.chan_C06:
chan_setbank 10
chan_setinstr 1
chan_setlayer 0, .layer_C0E
chan_end

.layer_C0E:
layer_portamento 0x82, 44, 200
layer_note1 39, 0x30, 127
layer_end

.chan_C16:
chan_setbank 8
chan_setinstr 4
chan_setlayer 0, .layer_C1E
chan_end

.layer_C1E:
layer_transpose 254
layer_somethingon
layer_portamento 0x85, 39, 255
layer_note1 42, 0x1e, 110
layer_note1 39, 0x41, 110
layer_end

.chan_C2C:
chan_setbank 8
chan_setinstr 5
chan_setlayer 0, .layer_C34
chan_end

.layer_C34:
layer_transpose 254
layer_portamento 0x81, 41, 255
layer_note1 38, 0x2b, 115
layer_end

.chan_C3E:
chan_setbank 8
chan_setinstr 6
chan_setlayer 0, .layer_C46
chan_end

.layer_C46:
layer_transpose 254
layer_note1 44, 0x1e, 110
layer_end

.chan_C4C:
chan_setbank 8
chan_setinstr 7
chan_setlayer 0, .layer_C54
chan_end

.layer_C54:
layer_transpose 253
layer_note1 39, 0x1c, 127
layer_end

.chan_C5A:
chan_setbank 8
chan_setinstr 8
chan_setlayer 0, .layer_C62
chan_end

.layer_C62:
layer_transpose 254
layer_note1 40, 0x30, 110
layer_end

.chan_C68:
chan_setbank 8
chan_setinstr 9
chan_setlayer 0, .layer_C70
chan_end

.layer_C70:
layer_transpose 254
layer_note1 40, 0x44, 105
layer_end

.chan_C76:
chan_setbank 8
chan_setinstr 10
chan_setlayer 0, .layer_C7E
chan_end

.layer_C7E:
layer_transpose 254
layer_note1 41, 0x30, 120
layer_end

.chan_C84:
chan_setbank 8
chan_setinstr 11
chan_setlayer 0, .layer_C8C
chan_end

.layer_C8C:
layer_transpose 254
layer_note1 38, 0x30, 127
layer_end

.chan_C92:
chan_setbank 8
chan_setinstr 12
chan_setlayer 0, .layer_C9A
chan_end

.layer_C9A:
layer_portamento 0x81, 38, 200
layer_note1 41, 0x85, 127
layer_end

.chan_CA3:
chan_setbank 8
chan_setinstr 13
chan_setlayer 0, .layer_CAB
chan_end

.layer_CAB:
layer_transpose 254
layer_note1 39, 0x7f, 105
layer_end

.chan_CB1:
chan_setbank 8
chan_setinstr 14
chan_setlayer 0, .layer_CB9
chan_end

.layer_CB9:
layer_transpose 254
layer_note1 39, 0x60, 64
layer_end

.chan_CBF:
chan_setbank 8
chan_setinstr 15
chan_setlayer 0, .layer_CC7
chan_end

.layer_CC7:
layer_transpose 254
layer_note1 39, 0x5c, 52
layer_end

.chan_CCD:
chan_setbank 10
chan_setinstr 0
chan_setlayer 0, .layer_CD5
chan_end

.layer_CD5:
layer_transpose 254
layer_note1 39, 0xaa, 127
layer_end

.chan_CDC:
chan_setbank 8
chan_setinstr 3
chan_setlayer 0, .layer_CE4
chan_end

.layer_CE4:
layer_transpose 255
layer_note1 39, 0x4d, 120
layer_end

.chan_CEA:
chan_setbank 10
chan_setinstr 6
chan_setlayer 0, .layer_CF2
chan_end

.layer_CF2:
layer_transpose 254
layer_note1 43, 0x1e, 105
layer_end

.chan_CF8:
chan_setbank 10
chan_setinstr 5
chan_setlayer 0, .layer_D00
chan_end

.layer_D00:
layer_transpose 254
layer_note1 39, 0xc8, 127
layer_end

.chan_D07:
chan_setbank 10
chan_setinstr 4
chan_setlayer 0, .layer_D0F
chan_end

.layer_D0F:
layer_transpose 254
layer_note1 39, 0x8c, 110
layer_end

.chan_D16:
chan_setbank 10
chan_setinstr 2
chan_setlayer 0, .layer_D1E
chan_end

.layer_D1E:
layer_transpose 254
layer_portamento 0x82, 35, 255
layer_note1 38, 0x30, 127
layer_end

.chan_D28:
chan_setbank 10
chan_setinstr 2
chan_setlayer 0, .layer_D30
chan_end

.layer_D30:
layer_transpose 254
layer_note1 39, 0x3c, 100
layer_end

.chan_D36:
chan_setbank 10
chan_setinstr 2
chan_setlayer 0, .layer_D3E
chan_end

.layer_D3E:
layer_transpose 254
layer_delay 0x4
layer_note1 38, 0x3c, 100
layer_end

.chan_D46:
chan_setbank 10
chan_setinstr 2
chan_setlayer 0, .layer_D4E
chan_end

.layer_D4E:
layer_transpose 254
layer_delay 0x8
layer_note1 40, 0x3c, 100
layer_end

.chan_D56:
chan_setbank 10
chan_setinstr 7
chan_setlayer 0, .layer_D5E
chan_end

.layer_D5E:
layer_transpose 254
layer_note1 39, 0x10, 115
layer_end

.chan_D64:
chan_setbank 10
chan_setinstr 7
chan_setlayer 0, .layer_D6C
chan_end

.layer_D6C:
layer_transpose 254
layer_portamento 0x81, 38, 255
layer_note1 41, 0x18, 115
layer_end

.chan_D76:
chan_setbank 10
chan_setinstr 7
chan_setlayer 0, .layer_D7E
chan_end

.layer_D7E:
layer_transpose 254
layer_somethingon
layer_portamento 0x85, 38, 255
layer_note1 41, 0xc, 115
layer_note1 35, 0x12, 115
layer_end

.chan_D8C:
chan_setbank 10
chan_setinstr 9
chan_setlayer 0, .layer_DA0
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 0
chan_setinstr 0
chan_setlayer 1, .layer_538
chan_end

.layer_DA0:
layer_transpose 254
layer_jump .layer_BFE

.chan_DA5:
chan_setbank 10
chan_setinstr 10
chan_setlayer 0, .layer_DB9
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 0
chan_setinstr 0
chan_setlayer 1, .layer_548
chan_end

.layer_DB9:
layer_transpose 254
layer_portamento 0x81, 42, 255
layer_note1 38, 0x30, 115
layer_end

.chan_DC3:
chan_setbank 10
chan_setinstr 11
chan_setlayer 0, .layer_DCB
chan_end

.layer_DCB:
layer_portamento 0x81, 38, 255
layer_note1 36, 0x8c, 115
layer_end

.chan_DD4:
chan_setbank 10
chan_setinstr 12
chan_setlayer 0, .layer_DDC
chan_end

.layer_DDC:
layer_note1 39, 0x60, 115
layer_end

.chan_DE0:
chan_jump .chan_C4C

.chan_DE3:
chan_setbank 10
chan_setinstr 13
chan_setlayer 0, .layer_DEB
chan_end

.layer_DEB:
layer_note1 38, 0x91, 127
layer_end

.chan_DF0:
chan_setbank 8
chan_setinstr 1
chan_setlayer 0, .layer_E04
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 0
chan_setinstr 0
chan_setlayer 1, .layer_536
chan_end

.layer_E04:
layer_transpose 255
layer_jump .layer_BF0

.table_E09:
sound_ref .chan_F09
sound_ref .chan_F22
sound_ref .chan_F22
sound_ref .chan_F2E
sound_ref .chan_F45
sound_ref .chan_F56
sound_ref .chan_F65
sound_ref .chan_F8B
sound_ref .chan_F97
sound_ref .chan_FAB
sound_ref .chan_1DA6
sound_ref .chan_FC8
sound_ref .chan_FD4
sound_ref .chan_FE8
sound_ref .chan_FF8
sound_ref .chan_1004
sound_ref .chan_104B
sound_ref .chan_104B
sound_ref .chan_106E
sound_ref .chan_106E
sound_ref .chan_106E
sound_ref .chan_106E
sound_ref .chan_10D5
sound_ref .chan_10EA
sound_ref .chan_10F9
sound_ref .chan_10F9
sound_ref .chan_1105
sound_ref .chan_1105
sound_ref .chan_1105
sound_ref .chan_1105
sound_ref .chan_1105
sound_ref .chan_1105
sound_ref .chan_1111
sound_ref .chan_1111
sound_ref .chan_113A
sound_ref .chan_113A
sound_ref .chan_114F
sound_ref .chan_1166
sound_ref .chan_117E
sound_ref .chan_1191
sound_ref .chan_11AB
sound_ref .chan_11AB
sound_ref .chan_11AB
sound_ref .chan_11AB
sound_ref .chan_11B7
sound_ref .chan_11C3
sound_ref .chan_11E4
sound_ref .chan_1200
sound_ref .chan_1220
sound_ref .chan_1235
sound_ref .chan_124F
sound_ref .chan_104B
sound_ref .chan_1268
sound_ref .chan_1278
sound_ref .chan_1288
sound_ref .chan_12A4
sound_ref .chan_12C6
sound_ref .chan_12EC
sound_ref .chan_1319
sound_ref .chan_1366
sound_ref .chan_137A
sound_ref .chan_1395
sound_ref .chan_13AB
sound_ref .chan_13C7
sound_ref .chan_13DD
sound_ref .chan_13F3
sound_ref .chan_140D
sound_ref .chan_141E
sound_ref .chan_1435
sound_ref .chan_1449
sound_ref .chan_1456
sound_ref .chan_146E
sound_ref .chan_147B
sound_ref .chan_148F
sound_ref .chan_14B7
sound_ref .chan_14C9
sound_ref .chan_1507
sound_ref .chan_1537
sound_ref .chan_1554
sound_ref .chan_1567
sound_ref .chan_2F2D
sound_ref .chan_2F65
sound_ref .chan_2F9B
sound_ref .chan_2FCF
sound_ref .chan_3019
sound_ref .chan_3014
sound_ref .chan_157A
sound_ref .chan_158E
sound_ref .chan_159E
sound_ref .chan_15C5
sound_ref .chan_15DD
sound_ref .chan_15EC
sound_ref .chan_15FF
sound_ref .chan_1612
sound_ref .chan_1627
sound_ref .chan_1633
sound_ref .chan_164D
sound_ref .chan_169D
sound_ref .chan_16CB
sound_ref .chan_16DE
sound_ref .chan_16F7
sound_ref .chan_1723
sound_ref .chan_173C
sound_ref .chan_1753
sound_ref .chan_176F
sound_ref .chan_17A5
sound_ref .chan_1845
sound_ref .chan_1865
sound_ref .chan_1882
sound_ref .chan_1892
sound_ref .chan_18A2
sound_ref .chan_18A5
sound_ref .chan_18A8
sound_ref .chan_18B4
sound_ref .chan_18D1
sound_ref .chan_18E9
sound_ref .chan_1902
sound_ref .chan_192F
sound_ref .chan_F22
sound_ref .chan_F22
sound_ref .chan_F22
sound_ref .chan_F45
sound_ref .chan_F56
sound_ref .chan_F65
sound_ref .chan_F8B
sound_ref .chan_F97
sound_ref .chan_F22
sound_ref .chan_F22

.chan_F09:
chan_setbank 5
chan_setinstr 7
chan_setlayer 0, .layer_F1A
chan_delay 0x1
chan_setbank 4
chan_setinstr 9
chan_setlayer 1, .layer_13B3
chan_end

.layer_F1A:
layer_portamento 0x1, 27, 0x28
layer_note1 37, 0x7f, 120
layer_end

.chan_F22:
chan_setbank 4
chan_setinstr 0
chan_setlayer 0, .layer_F2A
chan_end

.layer_F2A:
layer_note1 39, 0x30, 85
layer_end

.chan_F2E:
chan_setbank 3
chan_setinstr 8
chan_setenvelope .envelope_309C
chan_setlayer 0, .layer_F39
chan_end

.layer_F39:
layer_somethingon
layer_portamento 0x85, 34, 255
layer_note1 43, 0x8, 127
layer_note1 27, 0x7f, 127
layer_end

.chan_F45:
chan_setbank 4
chan_setinstr 1
chan_setlayer 0, .layer_F4D
chan_end

.layer_F4D:
layer_note1 39, 0x18, 100
layer_setinstr 2
layer_note1 39, 0x48, 60
layer_end

.chan_F56:
chan_setbank 4
chan_setinstr 1
chan_setlayer 0, .layer_F5E
chan_end

.layer_F5E:
layer_note1 37, 0x6, 100
layer_note1 34, 0x18, 100
layer_end

.chan_F65:
chan_setbank 4
chan_setinstr 4
chan_setlayer 0, .layer_F79
chan_setlayer 1, .layer_F83
chan_setval 6
chan_call .chan_fn_12B
chan_setbank 4
chan_setinstr 3
chan_end

.layer_F79:
layer_delay 0xf
layer_portamento 0x81, 39, 255
layer_note1 44, 0x38, 115
layer_end

.layer_F83:
layer_portamento 0x81, 44, 255
layer_note1 34, 0x2c, 85
layer_end

.chan_F8B:
chan_setbank 4
chan_setinstr 4
chan_setlayer 0, .layer_F93
chan_end

.layer_F93:
layer_note1 39, 0x30, 115
layer_end

.chan_F97:
chan_setbank 4
chan_setinstr 6
chan_setlayer 0, .layer_F9F
chan_end

.layer_F9F:
layer_transpose 24
layer_note1 39, 0xa, 65
layer_note1 39, 0x9, 70
layer_note1 39, 0x8, 75
layer_end

.chan_FAB:
chan_setbank 4
chan_setinstr 5
chan_setlayer 0, .layer_FB3
chan_end

.layer_FB3:
layer_note1 39, 0x91, 127
layer_end

.chan_FB8:
chan_setbank 4
chan_setinstr 5
chan_setlayer 0, .layer_FC0
chan_end

.layer_FC0:
layer_portamento 0x81, 27, 255
layer_note1 32, 0x60, 127
layer_end

.chan_FC8:
chan_setbank 4
chan_setinstr 6
chan_setlayer 0, .layer_FD0
chan_end

.layer_FD0:
layer_note1 39, 0x14, 70
layer_end

.chan_FD4:
chan_setbank 4
chan_setinstr 15
chan_setlayer 0, .layer_FDC
chan_end

.layer_FDC:
layer_note1 32, 0x18, 127
layer_portamento 0x81, 41, 255
layer_note1 27, 0x96, 127
layer_end

.chan_FE8:
chan_setbank 4
chan_setinstr 6
chan_setlayer 0, .layer_FF0
chan_end

.layer_FF0:
layer_portamento 0x81, 34, 255
layer_note1 37, 0x18, 80
layer_end

.chan_FF8:
chan_setbank 4
chan_setinstr 8
chan_setlayer 0, .layer_1000
chan_end

.layer_1000:
layer_note1 39, 0x40, 120
layer_end

.chan_1004:
chan_setbank 5
chan_setinstr 7
chan_setlayer 0, .layer_F1A
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 4
chan_setinstr 9
chan_setlayer 1, .layer_1018
chan_end

.layer_1018:
layer_transpose 244

.layer_fn_101A:
layer_portamento 0x83, 27, 255
layer_note0 55, 0x4, 127, 64
layer_note0 51, 0x5, 127, 64
layer_note0 48, 0x4, 127, 64
layer_note0 44, 0x6, 127, 64
layer_note0 41, 0x9, 127, 64
layer_note0 39, 0x6, 127, 64
.layer_1036:
layer_note0 37, 0x7, 127, 64
layer_note0 34, 0x5, 127, 64
layer_note0 31, 0x8, 127, 64
layer_note0 29, 0x9, 127, 64
layer_note0 24, 0x8, 127, 64
layer_end

.chan_104B:
chan_setbank 9
chan_setinstr 3
chan_setenvelope .envelope_30E0
chan_setvibratoextent 3
chan_setvibratorate 60
chan_setval 25
chan_call .chan_fn_144
chan_setlayer 0, .layer_105F
chan_end

.layer_105F:
layer_transpose 24

.layer_fn_1061:
layer_note1 25, 0x2, 40
layer_note1 37, 0x7, 85
layer_note1 30, 0x5, 40
layer_note1 42, 0x37, 85
layer_end

.chan_106E:
chan_setbank 9
chan_setinstr 3
chan_setenvelope .envelope_30E0
chan_setvibratoextent 12
chan_setval 25
chan_call .chan_fn_144
chan_setlayer 0, .layer_10BD
chan_setlayer 1, .layer_10CF
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 4
chan_setinstr 6
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 9
chan_setinstr 3
chan_setenvelope .envelope_30E0
chan_setval 9
chan_call .chan_fn_12B
chan_setbank 4
chan_setinstr 6
chan_setval 3
chan_call .chan_fn_12B
chan_setbank 9
chan_setinstr 3
chan_setenvelope .envelope_30E0
chan_setval 6
chan_call .chan_fn_12B
chan_setbank 4
chan_setinstr 6
chan_setval 49
chan_call .chan_fn_12B
chan_setvibratoextent 0
chan_end

.layer_10BD:
layer_delay 0x1
layer_setinstr 6
layer_transpose 22
layer_note1 39, 0xa, 55
layer_note1 39, 0x9, 60
layer_note1 39, 0x8, 65
layer_delay 0x29
layer_end

.layer_10CF:
layer_transpose 23
layer_call .layer_fn_1061
layer_end

.chan_10D5:
chan_setbank 4
chan_setinstr 14
chan_setenvelope .envelope_3170
chan_setlayer 0, .layer_10E0
chan_end

.layer_10E0:
layer_portamento 0x81, 34, 127
layer_note1 38, 0x30, 127
layer_delay 0x30
layer_end

.chan_10EA:
chan_setbank 4
chan_setinstr 9
chan_setlayer 0, .layer_10F2
chan_end

.layer_10F2:
layer_note1 37, 0xa, 100
layer_note1 26, 0x12, 120
layer_end

.chan_10F9:
chan_setbank 4
chan_setinstr 10
chan_setlayer 0, .layer_1101
chan_end

.layer_1101:
layer_note1 39, 0xf, 120
layer_end

.chan_1105:
chan_setbank 4
chan_setinstr 10
chan_setlayer 0, .layer_110D
chan_end

.layer_110D:
layer_note1 37, 0x12, 120
layer_end

.chan_1111:
chan_setbank 7
chan_setinstr 1
chan_setval 25
chan_call .chan_fn_144
chan_setlayer 0, .layer_112A
chan_setlayer 1, .layer_112A
chan_setval 6
chan_call .chan_fn_12B
chan_setbank 4
chan_setinstr 4
chan_end

.layer_112A:
layer_note1 43, 0x5, 127
layer_note1 62, 0x9, 127
layer_setinstr 2
layer_portamento 0x81, 27, 255
layer_note1 25, 0x5a, 108
layer_end

.chan_113A:
chan_setbank 4
chan_setinstr 11
chan_setlayer 0, .layer_1142
chan_end

.layer_1142:
layer_note1 24, 0xa, 110
.layer_1145:
layer_setinstr 5
layer_portamento 0x82, 27, 255
layer_note1 32, 0x73, 127
layer_end

.chan_114F:
chan_setbank 4
chan_setinstr 1
chan_setenvelope .envelope_3140
chan_setlayer 0, .layer_115A
chan_end

.layer_115A:
layer_somethingon
layer_note1 39, 0x4, 127
layer_portamento 0x82, 36, 255
layer_note1 27, 0x9, 115
layer_end

.chan_1166:
chan_setbank 4
chan_setinstr 2
chan_setenvelope .envelope_31C8
chan_setlayer 0, .layer_1174
chan_setlayer 1, .layer_1176
chan_end

.layer_1174:
layer_transpose 3

.layer_1176:
layer_portamento 0x2, 17, 0x28
layer_note1 5, 0x60, 127
layer_end

.chan_117E:
chan_setbank 4
chan_setinstr 11
chan_setlayer 0, .layer_1186
chan_end

.layer_1186:
layer_note1 19, 0x6, 110
layer_note1 31, 0x6, 110
layer_transpose 8
layer_jump .layer_1145

.chan_1191:
chan_setbank 4
chan_setinstr 5
chan_setlayer 0, .layer_1199
chan_end

.layer_1199:
layer_setinstr 11
layer_note1 31, 0x6, 127
layer_note1 19, 0x6, 127
layer_setinstr 5
layer_portamento 0x82, 20, 255
layer_note1 32, 0x5a, 127
layer_end

.chan_11AB:
chan_setbank 4
chan_setinstr 13
chan_setlayer 0, .layer_11B3
chan_end

.layer_11B3:
layer_note1 39, 0x73, 95
layer_end

.chan_11B7:
chan_setbank 4
chan_setinstr 14
chan_setlayer 0, .layer_11BF
chan_end

.layer_11BF:
layer_note1 39, 0x7f, 115
layer_end

.chan_11C3:
chan_setbank 4
chan_setinstr 15
chan_setlayer 0, .layer_11CB
chan_end

.layer_11CB:
layer_note0 36, 0xd, 115, 20
layer_note0 34, 0xe, 115, 20
layer_note0 32, 0xd, 115, 20
layer_note0 31, 0xa, 115, 20
layer_note0 30, 0x7, 115, 20
layer_note0 29, 0x60, 115, 20
layer_end

.chan_11E4:
chan_setbank 4
chan_setinstr 15
chan_setenvelope .envelope_3160
chan_setlayer 0, .layer_11F6
chan_setlayer 1, .layer_11F2
chan_end

.layer_11F2:
layer_note1 15, 0x7f, 127
layer_end

.layer_11F6:
layer_note1 55, 0x6, 115
layer_note1 43, 0xc, 115
layer_note1 34, 0x7f, 127
layer_end

.chan_1200:
chan_setbank 4
chan_setinstr 15
chan_setlayer 0, .layer_1210
chan_setlayer 1, .layer_121B
chan_setlayer 2, .layer_120E
chan_end

.layer_120E:
layer_transpose 6

.layer_1210:
layer_note1 44, 0x7, 127
layer_note1 39, 0x8, 127
layer_note1 36, 0x96, 127
layer_end

.layer_121B:
layer_note1 22, 0x96, 127
layer_end

.chan_1220:
chan_setbank 9
chan_setinstr 3
chan_setval 20
chan_call .chan_fn_144
chan_setlayer 0, .layer_122D
chan_end

.layer_122D:
layer_portamento 0x81, 36, 255
layer_note1 48, 0x6, 80
layer_end

.chan_1235:
chan_setbank 4
chan_setinstr 15
chan_setenvelope .envelope_3160
chan_setlayer 0, .layer_1243
chan_setlayer 1, .layer_124B
chan_end

.layer_1243:
layer_portamento 0x81, 56, 255
layer_note1 20, 0x78, 80
layer_end

.layer_124B:
layer_note1 15, 0x78, 127
layer_end

.chan_124F:
chan_setbank 4
chan_setinstr 6
chan_setlayer 0, .layer_1257
chan_end

.layer_1257:
layer_portamento 0x81, 37, 255
layer_note1 39, 0x8, 127
layer_setinstr 5
layer_portamento 0x81, 20, 255
layer_note1 25, 0x60, 127
layer_end

.chan_1268:
chan_setbank 4
chan_setinstr 2
chan_setlayer 0, .layer_1270
chan_end

.layer_1270:
layer_portamento 0x81, 12, 255
layer_note1 13, 0x6e, 127
layer_end

.chan_1278:
chan_setbank 4
chan_setinstr 2
chan_setlayer 0, .layer_1280
chan_end

.layer_1280:
layer_portamento 0x81, 15, 255
layer_note1 11, 0x6e, 127
layer_end

.chan_1288:
chan_setbank 9
chan_setinstr 3
chan_setval 40
chan_call .chan_fn_144
chan_setlayer 0, .layer_1295
chan_end

.layer_1295:
layer_transpose 24
layer_note1 39, 0x4, 90
layer_note1 51, 0xc, 90
layer_note1 39, 0x4, 50
layer_note1 51, 0xc, 50
layer_end

.chan_12A4:
chan_setbank 9
chan_setinstr 3
chan_setval 40
chan_call .chan_fn_144
chan_setlayer 0, .layer_12B1
chan_end

.layer_12B1:
layer_transpose 12
layer_note1 39, 0x3, 90
layer_note1 51, 0x3, 90
layer_note1 27, 0xa, 115
layer_note1 39, 0x3, 50
layer_note1 51, 0x3, 50
layer_note1 27, 0xa, 75
layer_end

.chan_12C6:
chan_setbank 4
chan_setinstr 9
chan_setval 50
chan_call .chan_fn_144
chan_setlayer 0, .layer_12DE
chan_setval 13
chan_call .chan_fn_12B
chan_setdecayrelease 30
chan_setbank 4
chan_setinstr 2
chan_end

.layer_12DE:
layer_note1 33, 0xc, 100
layer_note1 25, 0x28, 120
layer_portamento 0x81, 22, 255
layer_note1 15, 0x48, 80
layer_end

.chan_12EC:
chan_setbank 1
chan_setinstr 1
chan_setval 15
chan_call .chan_fn_144
chan_setlayer 0, .layer_1305
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 1
chan_setinstr 7
chan_setenvelope .envelope_30F0
chan_end

.layer_1305:
layer_note1 29, 0xc, 120
layer_transpose 12
layer_portamento 0x81, 51, 255
layer_note1 53, 0x6, 118
layer_portamento 0x81, 52, 255
layer_note1 54, 0x9, 118
layer_end

.chan_1319:
chan_setbank 7
chan_setinstr 8
chan_setval 15
chan_call .chan_fn_144
chan_setlayer 0, .layer_133E
chan_setlayer 1, .layer_135B
chan_setval 1
chan_call .chan_fn_12B
chan_setenvelope .envelope_30F0
chan_setbank 1
chan_setinstr 7
chan_setval 13
chan_call .chan_fn_12B
chan_setbank 7
chan_setinstr 8
chan_end

.layer_133E:
layer_delay 0x1
layer_transpose 12
layer_portamento 0x81, 54, 255
layer_note0 55, 0x6, 118, 127
layer_portamento 0x81, 55, 255
layer_note0 56, 0x5, 118, 127
layer_portamento 0x81, 57, 255
layer_note0 58, 0xc, 118, 127
layer_end

.layer_135B:
layer_loop 2
layer_portamento 0x81, 36, 255
layer_note1 24, 0x18, 127
layer_loopend
layer_end

.chan_1366:
chan_setbank 4
chan_setinstr 9
chan_setlayer 0, .layer_136E
chan_end

.layer_136E:
layer_note0 31, 0x12, 80, 80
layer_portamento 0x82, 53, 255
layer_note1 44, 0x7, 88
layer_end

.chan_137A:
chan_setbank 3
chan_setinstr 5
chan_setenvelope .envelope_305C
chan_setval 10
chan_call .chan_fn_144
chan_setlayer 0, .layer_138A
chan_end

.layer_138A:
layer_note1 41, 0x4, 100
layer_note0 34, 0x14, 100, 100
layer_note1 29, 0x6, 115
layer_end

.chan_1395:
chan_setval 10
chan_call .chan_fn_144
chan_setlayer 0, .layer_13A7
chan_setlayer 1, .layer_13A5
chan_setbank 4
chan_setinstr 1
chan_end

.layer_13A5:
layer_transpose 1

.layer_13A7:
layer_note1 15, 0x2c, 127
layer_end

.chan_13AB:
chan_setbank 4
chan_setinstr 9
chan_setlayer 0, .layer_13B5
chan_end

.layer_13B3:
layer_transpose 253

.layer_13B5:
layer_note1 39, 0x6, 120
layer_portamento 0x81, 15, 255
layer_note1 8, 0xc, 120
layer_portamento 0x81, 27, 255
layer_note1 3, 0x18, 120
layer_end

.chan_13C7:
chan_setbank 4
chan_setinstr 3
chan_setval 30
chan_call .chan_fn_144
chan_setlayer 0, .layer_13D4
chan_end

.layer_13D4:
layer_portamento 0x81, 19, 40
layer_note1 22, 0xb4, 115
layer_end

.chan_13DD:
chan_setbank 5
chan_setinstr 5
chan_setenvelope .envelope_30CC
chan_setval 20
chan_call .chan_fn_144
chan_setlayer 0, .layer_13ED
chan_end

.layer_13ED:
layer_note1 14, 0x34, 110
layer_delay 0x14
layer_end

.chan_13F3:
chan_setbank 5
chan_setinstr 7
chan_setlayer 0, .layer_13FE
chan_setlayer 1, .layer_13FE
chan_end

.layer_13FE:
layer_somethingon
layer_portamento 0x85, 39, 255
layer_note1 36, 0x14, 110
layer_note1 38, 0x10, 110
layer_note1 27, 0x64, 110
layer_end

.chan_140D:
chan_setbank 4
chan_setinstr 9
chan_setlayer 0, .layer_1415
chan_end

.layer_1415:
layer_note0 36, 0xa, 80, 80
layer_note0 24, 0xa, 80, 80
layer_end

.chan_141E:
chan_setbank 6
chan_setinstr 15
chan_setlayer 0, .layer_1426
chan_end

.layer_1426:
layer_somethingon
layer_portamento 0x85, 35, 255
layer_note1 34, 0x60, 127
layer_note1 32, 0x60, 127
layer_note1 32, 0x30, 127
layer_end

.chan_1435:
chan_setbank 6
chan_setinstr 1
chan_setval 55
chan_call .chan_fn_144
chan_setlayer 0, .layer_1442
chan_end

.layer_1442:
layer_note1 32, 0xc, 127
layer_note1 27, 0x30, 127
layer_end

.chan_1449:
chan_setbank 6
chan_setinstr 15
chan_setlayer 0, .layer_1451
chan_end

.layer_1451:
layer_note1 31, 0xc0, 127
layer_end

.chan_1456:
chan_setbank 7
chan_setinstr 1
chan_setlayer 0, .layer_1467
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 5
chan_setinstr 5
chan_end

.layer_1467:
layer_note1 24, 0xc, 127
layer_note1 22, 0x48, 127
layer_end

.chan_146E:
chan_setbank 6
chan_setinstr 10
chan_setlayer 0, .layer_1476
chan_end

.layer_1476:
layer_note1 44, 0xfa, 127
layer_end

.chan_147B:
chan_setbank 6
chan_setinstr 1
chan_setval 25
chan_call .chan_fn_144
chan_setlayer 0, .layer_1488
chan_end

.layer_1488:
layer_note1 29, 0xc, 120
layer_note1 24, 0x24, 120
layer_end

.chan_148F:
chan_setbank 3
chan_setinstr 5
chan_setenvelope .envelope_30E0
chan_setlayer 0, .layer_14A9
chan_setlayer 1, .layer_14B3
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 4
chan_setinstr 15
chan_setenvelope .envelope_30E0
chan_end

.layer_14A9:
layer_delay 0x1
layer_note1 36, 0xc, 127
layer_note1 32, 0x96, 127
layer_end

.layer_14B3:
layer_note1 24, 0x60, 127
layer_end

.chan_14B7:
chan_setbank 6
chan_setinstr 15
chan_setenvelope .envelope_308C
chan_setlayer 0, .layer_14C2
chan_end

.layer_14C2:
layer_note1 31, 0xa, 127
layer_note1 43, 0x10, 127
layer_end

.chan_14C9:
chan_setbank 4
chan_setinstr 15
chan_setval 30
chan_call .chan_fn_144
chan_setlayer 0, .layer_14DC
chan_setlayer 1, .layer_14E5
chan_setlayer 2, .layer_14E1
chan_end

.layer_14DC:
layer_note1 20, 0x226, 0
layer_end

.layer_14E1:
layer_delay 0x4
layer_transpose 244

.layer_14E5:
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

.chan_1507:
chan_setbank 4
chan_setinstr 15
chan_setval 30
chan_call .chan_fn_144
chan_setenvelope .envelope_3100
chan_setlayer 0, .layer_151D
chan_setlayer 1, .layer_1526
chan_setlayer 2, .layer_1522
chan_end

.layer_151D:
layer_note1 24, 0x12c, 127
layer_end

.layer_1522:
layer_delay 0x4
layer_transpose 244

.layer_1526:
layer_note1 46, 0xe, 116
layer_note1 44, 0xb, 121
layer_note1 48, 0x12, 101
layer_note1 41, 0xf, 109
layer_note1 43, 0xfa, 113
layer_end

.chan_1537:
chan_setbank 5
chan_setinstr 0
chan_setval 127
chan_call .chan_fn_144
chan_setlayer 0, .layer_154A
chan_setlayer 1, .layer_154A
chan_setlayer 2, .layer_154E
chan_end

.layer_154A:
layer_note1 49, 0x3a, 127
layer_end

.layer_154E:
layer_delay 0xa
layer_note1 48, 0x30, 85
layer_end

.chan_1554:
chan_setbank 6
chan_setinstr 10
chan_setenvelope .envelope_305C
chan_setlayer 0, .layer_155F
chan_end

.layer_155F:
layer_portamento 0x81, 51, 96
layer_note1 58, 0x40, 100
layer_end

.chan_1567:
chan_setbank 6
chan_setinstr 10
chan_setenvelope .envelope_305C
chan_setlayer 0, .layer_1572
chan_end

.layer_1572:
layer_portamento 0x82, 51, 96
layer_note1 58, 0x40, 100
layer_end

.chan_157A:
chan_setbank 6
chan_setinstr 1
chan_setval 55
chan_call .chan_fn_144
chan_setlayer 0, .layer_1587
chan_end

.layer_1587:
layer_note1 27, 0x7, 127
layer_note1 15, 0x12, 127
layer_end

.chan_158E:
chan_setbank 4
chan_setinstr 14
chan_setlayer 0, .layer_1596
chan_end

.layer_1596:
layer_portamento 0x81, 43, 127
layer_note1 31, 0x7f, 115
layer_end

.chan_159E:
chan_setbank 9
chan_setinstr 3
chan_setenvelope .envelope_30E0
chan_setlayer 0, .layer_15B0
chan_setdecayrelease 50
chan_setlayer 1, .layer_15AE
chan_end

.layer_15AE:
layer_delay 0x4

.layer_15B0:
layer_transpose 24
layer_note1 31, 0xc, 100
layer_note1 34, 0xc, 100
layer_note1 43, 0xc, 100
layer_note1 39, 0xc, 100
layer_note1 41, 0xc, 100
layer_note1 46, 0x18, 100
layer_end

.chan_15C5:
chan_setbank 4
chan_setinstr 9
chan_setlayer 0, .layer_15CD
chan_end

.layer_15CD:
layer_call .layer_fn_15D2
layer_transpose 252

.layer_fn_15D2:
layer_note1 27, 0x5, 105
layer_portamento 0x81, 15, 255
layer_note1 8, 0xa, 100
layer_end

.chan_15DD:
chan_setbank 4
chan_setinstr 9
chan_setlayer 0, .layer_15E5
chan_end

.layer_15E5:
layer_note1 8, 0x5, 127
layer_note1 18, 0x12, 127
layer_end

.chan_15EC:
chan_setbank 4
chan_setinstr 9
chan_setenvelope .envelope_3130
chan_setlayer 0, .layer_15F7
chan_end

.layer_15F7:
layer_portamento 0x82, 5, 255
layer_note1 8, 0xa, 127
layer_end

.chan_15FF:
chan_setbank 0
chan_setinstr 0
chan_setlayer 0, .layer_1607
chan_end

.layer_1607:
layer_note1 44, 0x6, 100
layer_portamento 0x81, 44, 255
layer_note1 32, 0x12, 100
layer_end

.chan_1612:
chan_setbank 9
chan_setinstr 3
chan_setenvelope .envelope_319C
chan_setlayer 0, .layer_161D
chan_end

.layer_161D:
layer_transpose 12
layer_portamento 0x85, 62, 255
layer_note1 38, 0x78, 93
layer_end

.chan_1627:
chan_setbank 1
chan_setinstr 1
chan_setlayer 0, .layer_162F
chan_end

.layer_162F:
layer_note1 29, 0xc, 127
layer_end

.chan_1633:
chan_setbank 4
chan_setinstr 1
chan_setlayer 0, .layer_1640
chan_setlayer 1, .layer_163E
chan_end

.layer_163E:
layer_delay 0x1

.layer_1640:
layer_note1 34, 0x6, 127
layer_note1 33, 0x7, 127
layer_note1 33, 0x6, 127
layer_note1 34, 0x6, 127
layer_end

.chan_164D:
chan_setbank 6
chan_setenvelope .envelope_305C
chan_setlayer 0, .layer_1664
chan_setval 1
chan_call .chan_fn_12B
chan_setenvelope .envelope_305C
chan_setlayer 1, .layer_166F
chan_setlayer 2, .layer_166B
chan_end

.layer_1664:
layer_setinstr 10
layer_transpose 24
layer_jump .layer_1671

.layer_166B:
layer_delay 0x2
layer_transpose 12

.layer_166F:
layer_setinstr 0
.layer_1671:
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
.layer_1696:
layer_note1 34, 0xa, 100
layer_jump .layer_1696
layer_end

.chan_169D:
chan_setbank 4
chan_setinstr 14
chan_setlayer 0, .layer_1596
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 4
chan_setinstr 15
chan_setenvelope .envelope_3160
chan_setlayer 1, .layer_11F6
chan_setval 100
chan_call .chan_fn_12B
chan_setbank 4
chan_setinstr 14
chan_setlayer 0, .layer_16C0
chan_end

.layer_16C0:
layer_transpose 250
layer_portamento 0x81, 43, 127
layer_note1 31, 0xfa, 115
layer_end

.chan_16CB:
chan_setbank 4
chan_setinstr 15
chan_setlayer 0, .layer_16D8
chan_setlayer 1, .layer_16D6
chan_end

.layer_16D6:
layer_transpose 2

.layer_16D8:
layer_note1 39, 0xc, 127
layer_jump .layer_11CB

.chan_16DE:
chan_setbank 4
chan_setinstr 14
chan_setlayer 0, .layer_16E6
chan_end

.layer_16E6:
layer_portamento 0x83, 39, 128
layer_note1 42, 0x2d, 115
layer_note1 42, 0x2d, 115
layer_note1 42, 0x2d, 115
layer_note1 44, 0x7f, 115
layer_end

.chan_16F7:
chan_setbank 9
chan_setinstr 3
chan_setval 30
chan_call .chan_fn_144
chan_setlayer 0, .layer_1704
chan_end

.layer_1704:
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

.chan_1723:
chan_setbank 5
chan_setinstr 7
chan_setlayer 0, .layer_1734
chan_delay 0x1
chan_setbank 4
chan_setinstr 9
chan_setlayer 1, .layer_13B3
chan_end

.layer_1734:
layer_portamento 0x1, 27, 0x28
layer_note1 32, 0x32, 120
layer_end

.chan_173C:
chan_setbank 6
chan_setinstr 11
chan_setlayer 0, .layer_2BF7
chan_setval 9
chan_call .chan_fn_12B
chan_setbank 9
chan_setinstr 3
chan_setenvelope .envelope_31C8
chan_setlayer 0, .layer_2B5E
chan_end

.chan_1753:
chan_setbank 4
chan_setinstr 9
chan_setlayer 0, .layer_13B5
chan_setval 12
chan_call .chan_fn_12B
chan_setbank 6
chan_setinstr 1
chan_setlayer 0, .layer_1767
chan_end

.layer_1767:
layer_portamento 0x82, 15, 255
layer_note1 31, 0x14, 127
layer_end

.chan_176F:
chan_setbank 9
chan_setinstr 3
chan_setlayer 0, .layer_1784
chan_setlayer 1, .layer_177D
chan_setlayer 2, .layer_1782
chan_end

.layer_177D:
layer_transpose 7
layer_jump .layer_1786

.layer_1782:
layer_delay 0x6

.layer_1784:
layer_transpose 12
.layer_1786:
layer_note0 46, 0xc, 90, 20
layer_note0 45, 0xc, 90, 20
layer_note0 46, 0xc, 90, 20
layer_note0 58, 0x10, 100, 80
layer_note0 58, 0x10, 60, 80
layer_note0 58, 0x10, 40, 80
layer_note0 58, 0x10, 25, 80
layer_delay 0xa
layer_end

.chan_17A5:
chan_setbank 5
chan_setinstr 13
chan_setenvelope .envelope_3150
chan_setval 20
chan_call .chan_fn_144
chan_setval 127
chan_iowriteval 7
chan_setlayer 0, .layer_17DA
chan_setlayer 1, .layer_1801
chan_setlayer 2, .layer_17FD
.chan_17BD:
chan_setval 4
chan_call .chan_fn_12B
chan_ioreadval 7
chan_subtract 1
chan_beqz .chan_17D2
chan_iowriteval 7
chan_writeseq_nextinstr 0, 1
chan_setvolscale 127
chan_jump .chan_17BD
.chan_17D2:
chan_setval 127
chan_call .chan_fn_12B
chan_jump .chan_17D2

.layer_17DA:
layer_setinstr 9
layer_note1 40, 0x6, 122
layer_note1 41, 0x4, 112
layer_note1 43, 0x5, 109
layer_note1 44, 0x6, 124
layer_note1 44, 0x4, 116
layer_note1 45, 0x7, 114
layer_delay 0x19
.layer_17F0:
layer_note1 43, 0x7f, 122
layer_note1 43, 0xa, 127
layer_note1 43, 0x64, 114
layer_jump .layer_17F0
layer_end

.layer_17FD:
layer_transpose 4
layer_delay 0x2

.layer_1801:
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
.layer_1820:
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
layer_jump .layer_1820
layer_end

.chan_1845:
chan_setbank 9
chan_setinstr 3
chan_setval 40
chan_call .chan_fn_144
chan_setenvelope .envelope_30CC
chan_setlayer 0, .layer_1855
chan_end

.layer_1855:
layer_loop 2
layer_note1 62, 0x6, 110
layer_note1 62, 0x2, 45
layer_note1 58, 0x6, 110
layer_note1 58, 0x2, 45
layer_loopend
layer_end

.chan_1865:
chan_setbank 7
chan_setinstr 1
chan_setlayer 0, .layer_187B
chan_setlayer 1, .layer_1879
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 5
chan_setinstr 5
chan_end

.layer_1879:
layer_transpose 250

.layer_187B:
layer_note1 15, 0xc, 127
layer_note1 17, 0x3a, 127
layer_end

.chan_1882:
chan_setbank 5
chan_setinstr 14
chan_setlayer 0, .layer_188A
chan_end

.layer_188A:
layer_portamento 0x82, 40, 127
layer_note1 38, 0x28, 100
layer_end

.chan_1892:
chan_setbank 5
chan_setinstr 14
chan_setlayer 0, .layer_189A
chan_end

.layer_189A:
layer_portamento 0x82, 43, 127
layer_note1 39, 0x36, 100
layer_end

.chan_18A2:
chan_jump .chan_21E9

.chan_18A5:
chan_jump .chan_2157

.chan_18A8:
chan_setbank 0
chan_setinstr 3
chan_setlayer 0, .layer_18B0
chan_end

.layer_18B0:
layer_note1 39, 0x32, 127
layer_end

.chan_18B4:
chan_setbank 6
chan_setinstr 2
chan_setlayer 0, .layer_18BF
chan_setlayer 1, .layer_18BF
chan_end

.layer_18BF:
layer_transpose 7
layer_call .layer_fn_18C6
layer_transpose 254

.layer_fn_18C6:
layer_portamento 0x83, 31, 255
layer_note1 51, 0x6, 127
layer_note1 56, 0xc, 127
layer_end

.chan_18D1:
chan_setbank 9
chan_setinstr 6
chan_setval 10
chan_call .chan_fn_144
chan_setlayer 0, .layer_18E1
chan_setlayer 1, .layer_18E1
chan_end

.layer_18E1:
layer_portamento 0x82, 39, 255
layer_note1 31, 0x60, 100
layer_end

.chan_18E9:
chan_setbank 4
chan_setinstr 14
chan_setlayer 0, .layer_18F4
chan_setlayer 1, .layer_18F8
chan_end

.layer_18F4:
layer_transpose 3
layer_delay 0x5

.layer_18F8:
layer_somethingon
layer_portamento 0x85, 31, 255
layer_note1 34, 0x12c, 127
layer_end

.chan_1902:
chan_setbank 4
chan_setinstr 14
chan_setenvelope .envelope_30E0
chan_setlayer 0, .layer_191B
chan_setval 1
chan_call .chan_fn_12B
chan_setenvelope .envelope_30E0
chan_setlayer 1, .layer_1925
chan_setlayer 2, .layer_1923
chan_end

.layer_191B:
layer_portamento 0x81, 32, 64
layer_note1 38, 0x46, 127
layer_end

.layer_1923:
layer_delay 0x4

.layer_1925:
layer_delay 0x4
layer_portamento 0x81, 36, 40
layer_note1 41, 0xc, 127
layer_end

.chan_192F:
chan_setbank 9
chan_setinstr 0
chan_setenvelope .envelope_31AC
chan_setvibratorate 25
chan_setvibratoextent 110
chan_setlayer 0, .layer_1943
chan_setval 40
chan_call .chan_fn_12B
chan_end

.layer_1943:
layer_portamento 0x1, 32, 0x7f
layer_note1 60, 0x28, 100
layer_end

.table_194B:
sound_ref .chan_199B
sound_ref .chan_199B
sound_ref .chan_19B5
sound_ref .chan_19C5
sound_ref .chan_19C5
sound_ref .chan_19D5
sound_ref .chan_1A25
sound_ref .chan_1A3D
sound_ref .chan_1A57
sound_ref .chan_1A67
sound_ref .chan_1A9E
sound_ref .chan_1AB7
sound_ref .chan_1ACA
sound_ref .chan_1B13
sound_ref .chan_1B25
sound_ref .chan_1B42
sound_ref .chan_1B5C
sound_ref .chan_286F
sound_ref .chan_1B9A
sound_ref .chan_1BB2
sound_ref .chan_1BC7
sound_ref .chan_1BD9
sound_ref .chan_1C10
sound_ref .chan_1C57
sound_ref .chan_1C72
sound_ref .chan_1C8D
sound_ref .chan_19B5
sound_ref .chan_19C5
sound_ref .chan_199B
sound_ref .chan_199B
sound_ref .chan_199B
sound_ref .chan_199B
sound_ref .chan_F22
sound_ref .chan_15EC
sound_ref .chan_19B5
sound_ref .chan_19C5
sound_ref .chan_199B
sound_ref .chan_199B
sound_ref .chan_199B
sound_ref .chan_199B

.chan_199B:
chan_setbank 5
chan_setinstr 1
chan_setval 25
chan_call .chan_fn_144
chan_setenvelope .envelope_306C
chan_setlayer 0, .layer_19AB
chan_end

.layer_19AB:
layer_somethingon
layer_delay 0x6
.layer_19AE:
layer_note1 41, 0x12c, 95
layer_jump .layer_19AE

.chan_19B5:
chan_setbank 5
chan_setinstr 2
chan_setlayer 0, .layer_19BD
chan_end

.layer_19BD:
layer_somethingon
.layer_19BE:
layer_note1 39, 0x12c, 90
layer_jump .layer_19BE

.chan_19C5:
chan_setbank 5
chan_setinstr 3
chan_setlayer 0, .layer_19CD
chan_end

.layer_19CD:
layer_somethingon
.layer_19CE:
layer_note1 44, 0x12c, 105
layer_jump .layer_19CE

.chan_19D5:
chan_setbank 5
chan_setinstr 6
chan_setdecayrelease 13
chan_setlayer 0, .layer_19E2
chan_setlayer 1, .layer_19E4
chan_end

.layer_19E2:
layer_transpose 244

.layer_19E4:
layer_somethingon
layer_portamento 0x85, 39, 255
.layer_19E9:
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
layer_jump .layer_19E9

.chan_1A25:
chan_setbank 3
chan_setinstr 2
chan_setlayer 0, .layer_1A2D
chan_end

.layer_1A2D:
layer_somethingon
layer_portamento 0x85, 36, 255
.layer_1A32:
layer_note1 34, 0x12c, 95
layer_note1 36, 0x12c, 95
layer_jump .layer_1A32

.chan_1A3D:
chan_setbank 6
chan_setinstr 15
chan_setlayer 0, .layer_1A45
chan_end

.layer_1A45:
layer_somethingon
layer_note1 43, 0xc, 127
layer_portamento 0x81, 44, 255
layer_note1 43, 0x50, 127
.layer_1A50:
layer_note1 43, 0x12c, 127
layer_jump .layer_1A50

.chan_1A57:
chan_setbank 5
chan_setinstr 2
chan_setlayer 0, .layer_1A5F
chan_end

.layer_1A5F:
layer_somethingon
.layer_1A60:
layer_note1 27, 0x12c, 100
layer_jump .layer_1A60

.chan_1A67:
chan_setbank 4
chan_setinstr 5
chan_setenvelope .envelope_306C
chan_setdecayrelease 25
chan_setlayer 0, .layer_1A74
chan_end

.layer_1A74:
layer_transpose 6
layer_portamento 0x85, 39, 255
.layer_1A7A:
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
layer_jump .layer_1A7A

.chan_1A9E:
chan_setbank 6
chan_setinstr 15
chan_setlayer 0, .layer_1AA6
chan_end

.layer_1AA6:
layer_somethingon
layer_portamento 0x85, 39, 255
layer_note1 42, 0x3c, 127
.layer_1AAE:
layer_note1 41, 0x3c, 127
layer_note1 42, 0x3c, 127
layer_jump .layer_1AAE

.chan_1AB7:
chan_setbank 4
chan_setinstr 2
chan_setdecayrelease 30
chan_setlayer 0, .layer_1AC1
chan_end

.layer_1AC1:
layer_portamento 0x81, 15, 255
layer_note1 11, 0x1f4, 100
layer_end

.chan_1ACA:
chan_setbank 5
chan_setinstr 5
chan_setenvelope .envelope_30F0
chan_setval 45
chan_call .chan_fn_144
chan_setlayer 0, .layer_1ADA
chan_end

.layer_1ADA:
layer_call .layer_fn_1AFB
layer_delay 0xb
layer_call .layer_fn_1AFB
layer_delay 0x9
layer_call .layer_fn_1AFB
layer_delay 0x8
layer_call .layer_fn_1AFB
layer_delay 0x6
layer_call .layer_fn_1AFB
layer_delay 0x5
.layer_1AF3:
layer_call .layer_fn_1AFB
layer_delay 0x3
layer_jump .layer_1AF3

.layer_fn_1AFB:
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

.chan_1B13:
chan_setbank 4
chan_setinstr 2
chan_setlayer 0, .layer_1B1B
chan_end

.layer_1B1B:
layer_portamento 0x81, 19, 10
layer_note1 8, 0x9, 127
layer_jump .layer_1B1B

.chan_1B25:
chan_setbank 3
chan_setinstr 7
chan_setdecayrelease 5
chan_setlayer 0, .layer_1B3A
chan_setlayer 1, .layer_1B32
chan_end

.layer_1B32:
layer_somethingon
.layer_1B33:
layer_note1 47, 0x1f4, 90
layer_jump .layer_1B33

.layer_1B3A:
layer_somethingon
.layer_1B3B:
layer_note1 46, 0x1f4, 90
layer_jump .layer_1B3B

.chan_1B42:
chan_setbank 4
chan_setinstr 2
chan_setdecayrelease 30
chan_setlayer 0, .layer_1B51
chan_setlayer 1, .layer_1B4F
chan_end

.layer_1B4F:
layer_transpose 6

.layer_1B51:
layer_portamento 0x85, 7, 255
layer_note1_long 13, 0x46, 120
layer_jump .layer_1B51

.chan_1B5C:
chan_setbank 5
chan_setinstr 6
chan_setdecayrelease 13
chan_setlayer 0, .layer_1B69
chan_setlayer 1, .layer_1B6B
chan_end

.layer_1B69:
layer_transpose 250

.layer_1B6B:
layer_somethingon
layer_portamento 0x85, 34, 255
.layer_1B70:
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
layer_jump .layer_1B70

.chan_1B9A:
chan_setbank 4
chan_setinstr 2
chan_setbank 6
chan_setenvelope .envelope_309C
chan_setdecayrelease 200
chan_setlayer 0, .layer_1BA9
chan_end

.layer_1BA9:
layer_transpose 3
.layer_1BAB:
layer_note0 62, 0x2, 127, 127
layer_jump .layer_1BAB

.chan_1BB2:
chan_setbank 3
chan_setinstr 1
chan_setenvelope .envelope_306C
chan_setdecayrelease 15
chan_setlayer 0, .layer_1BBF
chan_end

.layer_1BBF:
layer_somethingon
.layer_1BC0:
layer_note1 44, 0x12c, 95
layer_jump .layer_1BC0

.chan_1BC7:
chan_setbank 4
chan_setinstr 14
chan_setlayer 0, .layer_1BCF
chan_end

.layer_1BCF:
layer_portamento 0x81, 38, 127
layer_note1 39, 0x9, 127
layer_jump .layer_1BCF

.chan_1BD9:
chan_setval 50
chan_call .chan_fn_144
chan_setbank 4
chan_setinstr 15
chan_setlayer 0, .layer_1BFD
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 6
chan_setinstr 15
chan_setlayer 1, .layer_1C05
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 4
chan_setinstr 15
chan_setdecayrelease 10
chan_end

.layer_1BFD:
layer_note1 21, 0xc, 127
layer_note1 18, 0x226, 127
layer_end

.layer_1C05:
layer_transpose 24
layer_portamento 0x82, 19, 255
layer_note1 20, 0x1f4, 127
layer_end

.chan_1C10:
chan_setbank 3
chan_setinstr 2
chan_setenvelope .envelope_306C
chan_setlayer 0, .layer_1C2C
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 4
chan_setinstr 5
chan_setdecayrelease 20
chan_setlayer 1, .layer_1C3C
chan_setlayer 2, .layer_1C3A
chan_end

.layer_1C2C:
layer_transpose 244
layer_somethingon
layer_portamento 0x82, 39, 255
.layer_1C33:
layer_note1 46, 0x2710, 80
layer_jump .layer_1C33

.layer_1C3A:
layer_transpose 6

.layer_1C3C:
layer_portamento 0x83, 20, 255
layer_note1 15, 0x5a, 127
layer_note1 32, 0x2d, 127
layer_note1 29, 0x46, 127
layer_note1 24, 0x78, 127
layer_note1 32, 0x44, 127
layer_note1 24, 0x74, 127
layer_transpose 7
layer_jump .layer_1C3C

.chan_1C57:
chan_setbank 6
chan_setinstr 1
chan_setlayer 0, .layer_1C64
chan_setlayer 1, .layer_1C6A
chan_setdecayrelease 127
chan_end

.layer_1C64:
layer_note1 24, 0xc, 85
layer_jump .layer_1C64

.layer_1C6A:
layer_setinstr 15
.layer_1C6C:
layer_note1 39, 0x10, 115
layer_jump .layer_1C6C

.chan_1C72:
chan_setbank 3
chan_setinstr 6
chan_setenvelope .envelope_306C
chan_setlayer 0, .layer_1C80
chan_setlayer 1, .layer_1C80
chan_end

.layer_1C80:
layer_portamento 0x81, 38, 80
layer_somethingon
.layer_1C85:
layer_note1 35, 0x12c, 100
layer_jump .layer_1C85
layer_end

.chan_1C8D:
chan_setbank 5
chan_setinstr 15
chan_setenvelope .envelope_306C
chan_setdecayrelease 8
chan_setlayer 0, .layer_1C9A
chan_end

.layer_1C9A:
layer_somethingon
layer_portamento 0x82, 20, 255
.layer_1C9F:
layer_note1 43, 0x1b58, 63
layer_jump .layer_1C9F

.table_1CA6:
sound_ref .chan_FB8
sound_ref .chan_1DB9
sound_ref .chan_1DD5
sound_ref .chan_1DE5
sound_ref .chan_1E04
sound_ref .chan_1E1C
sound_ref .chan_1E38
sound_ref .chan_1E4A
sound_ref .chan_1E56
sound_ref .chan_1E62
sound_ref .chan_1E72
sound_ref .chan_1E7E
sound_ref .chan_1E8D
sound_ref .chan_1EB1
sound_ref .chan_1EBE
sound_ref .chan_1ECB
sound_ref .chan_1ED7
sound_ref .chan_1EF2
sound_ref .chan_1EFE
sound_ref .chan_1F0A
sound_ref .chan_1F16
sound_ref .chan_1F22
sound_ref .chan_1F34
sound_ref .chan_1F53
sound_ref .chan_1F5F
sound_ref .chan_1F86
sound_ref .chan_1F92
sound_ref .chan_1F9E
sound_ref .chan_1FB0
sound_ref .chan_1FCF
sound_ref .chan_1FE6
sound_ref .chan_1FF9
sound_ref .chan_2010
sound_ref .chan_202E
sound_ref .chan_203C
sound_ref .chan_2057
sound_ref .chan_2069
sound_ref .chan_207C
sound_ref .chan_208D
sound_ref .chan_20A0
sound_ref .chan_20B8
sound_ref .chan_20CF
sound_ref .chan_20EB
sound_ref .chan_20FD
sound_ref .chan_210F
sound_ref .chan_212A
sound_ref .chan_213E
sound_ref .chan_2157
sound_ref .chan_2179
sound_ref .chan_2195
sound_ref .chan_21B9
sound_ref .chan_21D6
sound_ref .chan_21E9
sound_ref .chan_21FA
sound_ref .chan_2208
sound_ref .chan_2218
sound_ref .chan_2237
sound_ref .chan_2250
sound_ref .chan_2260
sound_ref .chan_2277
sound_ref .chan_2287
sound_ref .chan_2299
sound_ref .chan_22B1
sound_ref .chan_22C6
sound_ref .chan_22DA
sound_ref .chan_22EA
sound_ref .chan_2312
sound_ref .chan_232C
sound_ref .chan_233A
sound_ref .chan_234A
sound_ref .chan_2360
sound_ref .chan_2370
sound_ref .chan_2389
sound_ref .chan_239A
sound_ref .chan_23AA
sound_ref .chan_23C8
sound_ref .chan_23D8
sound_ref .chan_23FF
sound_ref .chan_2413
sound_ref .chan_2433
sound_ref .chan_2F2D
sound_ref .chan_2F65
sound_ref .chan_2F9B
sound_ref .chan_2FCF
sound_ref .chan_2456
sound_ref .chan_2469
sound_ref .chan_247C
sound_ref .chan_24B5
sound_ref .chan_24C9
sound_ref .chan_2501
sound_ref .chan_2514
sound_ref .chan_2527
sound_ref .chan_2537
sound_ref .chan_2552
sound_ref .chan_25C9
sound_ref .chan_2562
sound_ref .chan_257E
sound_ref .chan_258E
sound_ref .chan_25A9
sound_ref .chan_25B9
sound_ref .chan_25D9
sound_ref .chan_25E0
sound_ref .chan_25F4
sound_ref .chan_2613
sound_ref .chan_2634
sound_ref .chan_2641
sound_ref .chan_2654
sound_ref .chan_2668
sound_ref .chan_267F
sound_ref .chan_269E
sound_ref .chan_26BD
sound_ref .chan_26E8
sound_ref .chan_271F
sound_ref .chan_273B
sound_ref .chan_2756
sound_ref .chan_277A
sound_ref .chan_279A
sound_ref .chan_1E1C
sound_ref .chan_1E38
sound_ref .chan_1E4A
sound_ref .chan_22DA
sound_ref .chan_22EA
sound_ref .chan_1DD5
sound_ref .chan_1DE5
sound_ref .chan_1E04
sound_ref .chan_1E1C
sound_ref .chan_1E38
sound_ref .chan_1E4A

.chan_1DA6:
chan_setbank 6
chan_setinstr 5
chan_setlayer 0, .layer_1DAE
chan_end

.layer_1DAE:
layer_note1 27, 0x8, 90
layer_portamento 0x81, 43, 255
layer_note1 27, 0x21, 90
layer_end

.chan_1DB9:
chan_setbank 7
chan_setinstr 3
chan_setlayer 0, .layer_1DCA
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 6
chan_setinstr 0
chan_end

.layer_1DCA:
layer_note1 43, 0xf, 90
layer_portamento 0x82, 27, 255
layer_note1 36, 0xb, 90
layer_end

.chan_1DD5:
chan_setbank 6
chan_setinstr 7
chan_setlayer 0, .layer_1DDD
chan_end

.layer_1DDD:
layer_portamento 0x81, 43, 255
layer_note1 48, 0x30, 110
layer_end

.chan_1DE5:
chan_setbank 6
chan_setinstr 1
chan_setval 60
chan_call .chan_fn_144
chan_setlayer 0, .layer_1DF5
chan_setlayer 1, .layer_1DFE
chan_end

.layer_1DF5:
layer_note1 36, 0x8, 120
layer_note1 35, 0x28, 120
layer_delay 0x30
layer_end

.layer_1DFE:
layer_delay 0x18
layer_note1 0, 0x1e, 95
layer_end

.chan_1E04:
chan_setbank 6
chan_setinstr 2
chan_setval 10
chan_call .chan_fn_144
chan_setlayer 0, .layer_1E18
chan_setlayer 1, .layer_1E14
chan_end

.layer_1E14:
layer_delay 0x3
layer_transpose 5

.layer_1E18:
layer_note1 39, 0x7f, 127
layer_end

.chan_1E1C:
chan_setbank 6
chan_setinstr 2
chan_setval 10
chan_call .chan_fn_144
chan_setlayer 0, .layer_1E30
chan_setlayer 1, .layer_1E2C
chan_end

.layer_1E2C:
layer_delay 0x3
layer_transpose 5

.layer_1E30:
layer_portamento 0x81, 45, 255
layer_note1 33, 0x30, 127
layer_end

.chan_1E38:
chan_setbank 6
chan_setinstr 4
chan_setval 10
chan_call .chan_fn_144
chan_setlayer 0, .layer_1E45
chan_end

.layer_1E45:
layer_note1 32, 0x104, 127
layer_end

.chan_1E4A:
chan_setbank 6
chan_setinstr 5
chan_setlayer 0, .layer_1E52
chan_end

.layer_1E52:
layer_note1 32, 0x28, 127
layer_end

.chan_1E56:
chan_setbank 6
chan_setinstr 6
chan_setlayer 0, .layer_1E5E
chan_end

.layer_1E5E:
layer_note1 36, 0x5a, 127
layer_end

.chan_1E62:
chan_setbank 6
chan_setinstr 7
chan_setlayer 0, .layer_1E6A
chan_end

.layer_1E6A:
layer_portamento 0x81, 39, 255
layer_note1 36, 0x26, 100
layer_end

.chan_1E72:
chan_setbank 6
chan_setinstr 8
chan_setlayer 0, .layer_1E7A
chan_end

.layer_1E7A:
layer_note1 39, 0x18, 127
layer_end

.chan_1E7E:
chan_setbank 6
chan_setinstr 9
chan_setlayer 0, .layer_1E86
chan_end

.layer_1E86:
layer_note1 50, 0xa, 127
layer_note1 55, 0xa, 127
layer_end

.chan_1E8D:
chan_setbank 7
chan_setinstr 12
chan_setval 55
chan_call .chan_fn_144
chan_setlayer 0, .layer_1EAD
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 6
chan_setinstr 1
chan_setlayer 1, .layer_1EA6
chan_end

.layer_1EA6:
layer_note1 37, 0xc, 127
layer_note1 31, 0x1e, 127
layer_end

.layer_1EAD:
layer_note1 31, 0x2a, 127
layer_end

.chan_1EB1:
chan_setbank 6
chan_setinstr 10
chan_setlayer 0, .layer_1EB9
chan_end

.layer_1EB9:
layer_note1 39, 0xd2, 127
layer_end

.chan_1EBE:
chan_setbank 6
chan_setinstr 11
chan_setlayer 0, .layer_1EC6
chan_end

.layer_1EC6:
layer_note1 39, 0xd2, 127
layer_end

.chan_1ECB:
chan_setbank 6
chan_setinstr 12
chan_setlayer 0, .layer_1ED3
chan_end

.layer_1ED3:
layer_note1 39, 0x24, 127
layer_end

.chan_1ED7:
chan_setbank 6
chan_setinstr 11
chan_setlayer 0, .layer_1EDF
chan_end

.layer_1EDF:
layer_portamento 0x81, 33, 255
layer_note1 57, 0x4, 127
layer_transpose 252
layer_portamento 0x81, 57, 255
layer_note1 33, 0x6, 127
layer_delay 0x14
layer_end

.chan_1EF2:
chan_setbank 6
chan_setinstr 14
chan_setlayer 0, .layer_1EFA
chan_end

.layer_1EFA:
layer_note1 39, 0x48, 110
layer_end

.chan_1EFE:
chan_setbank 4
chan_setinstr 5
chan_setlayer 0, .layer_1F06
chan_end

.layer_1F06:
layer_note1 59, 0x24, 105
layer_end

.chan_1F0A:
chan_setbank 6
chan_setinstr 15
chan_setlayer 0, .layer_1F12
chan_end

.layer_1F12:
layer_note1 39, 0x4c, 127
layer_end

.chan_1F16:
chan_setbank 7
chan_setinstr 0
chan_setlayer 0, .layer_1F1E
chan_end

.layer_1F1E:
layer_note1 39, 0x18, 105
layer_end

.chan_1F22:
chan_setbank 6
chan_setinstr 1
chan_setlayer 0, .layer_1F2A
chan_end

.layer_1F2A:
layer_portamento 0x81, 44, 255
layer_note1 36, 0x18, 90
layer_delay 0x32
layer_end

.chan_1F34:
chan_setbank 7
chan_setinstr 12
chan_setlayer 0, .layer_1F48
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 6
chan_setinstr 1
chan_setlayer 1, .layer_1F4C
chan_end

.layer_1F48:
layer_note1 31, 0x26, 127
layer_end

.layer_1F4C:
layer_note1 38, 0x8, 120
layer_note1 33, 0x1e, 120
layer_end

.chan_1F53:
chan_setbank 7
chan_setinstr 1
chan_setlayer 0, .layer_1F5B
chan_end

.layer_1F5B:
layer_note1 39, 0x24, 120
layer_end

.chan_1F5F:
chan_setbank 4
chan_setinstr 15
chan_setenvelope .envelope_3160
chan_setlayer 0, .layer_1F74
chan_setlayer 1, .layer_1F7E
chan_setlayer 2, .layer_1F7C
chan_setval 1
chan_setdecayrelease 10
chan_end

.layer_1F74:
layer_portamento 0x81, 51, 255
layer_note1 20, 0x2e, 115
layer_end

.layer_1F7C:
layer_transpose 3

.layer_1F7E:
layer_setinstr 5
layer_delay 0xa
layer_note1 48, 0x23, 127
layer_end

.chan_1F86:
chan_setbank 7
chan_setinstr 2
chan_setlayer 0, .layer_1F8E
chan_end

.layer_1F8E:
layer_note1 39, 0xc, 105
layer_end

.chan_1F92:
chan_setbank 7
chan_setinstr 3
chan_setlayer 0, .layer_1F9A
chan_end

.layer_1F9A:
layer_note1 39, 0x68, 127
layer_end

.chan_1F9E:
chan_setbank 7
chan_setinstr 3
chan_setlayer 0, .layer_1FA6
chan_end

.layer_1FA6:
layer_portamento 0x82, 38, 127
layer_note1 51, 0x4, 80
layer_delay 0x1e
layer_end

.chan_1FB0:
chan_setbank 7
chan_setinstr 12
chan_setlayer 0, .layer_1FB8
chan_end

.layer_1FB8:
layer_portamento 0x83, 33, 255
layer_note0 40, 0xf, 127, 127
layer_note1 26, 0x20, 127
layer_end

.layer_unused_1FC4:
layer_portamento 0x83, 27, 255
layer_note1 22, 0x9, 127
layer_note1 24, 0x1c, 127
layer_end

.chan_1FCF:
chan_setbank 7
chan_setinstr 3
chan_setlayer 0, .layer_1FD7
chan_end

.layer_1FD7:
layer_portamento 0x81, 27, 255
layer_note1 48, 0x9, 100
layer_portamento 0x81, 27, 255
layer_note1 48, 0x5, 100
layer_end

.chan_1FE6:
chan_setbank 6
chan_setinstr 5
chan_setlayer 0, .layer_1FEE
chan_end

.layer_1FEE:
layer_note1 36, 0x8, 90
layer_portamento 0x81, 43, 255
layer_note1 27, 0x14, 90
layer_end

.chan_1FF9:
chan_setbank 6
chan_setinstr 7
chan_setlayer 0, .layer_2001
chan_end

.layer_2001:
layer_portamento 0x81, 39, 255
layer_note1 44, 0xc, 110
layer_portamento 0x81, 46, 255
layer_note1 58, 0x30, 110
layer_end

.chan_2010:
chan_setbank 6
chan_setinstr 12
chan_setlayer 0, .layer_2021
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 0
chan_setinstr 4
chan_end

.layer_2021:
layer_portamento 0x82, 24, 255
layer_note1 12, 0x4, 100
layer_note1 51, 0x8, 80
layer_delay 0x1e
layer_end

.chan_202E:
chan_setbank 7
chan_setinstr 7
chan_setdecayrelease 15
chan_setlayer 0, .layer_2038
chan_end

.layer_2038:
layer_note1 39, 0x30, 127
layer_end

.chan_203C:
chan_setbank 9
chan_setinstr 3
chan_setenvelope .envelope_319C
chan_setval 10
chan_call .chan_fn_144
chan_setlayer 0, .layer_204C
chan_end

.layer_204C:
layer_portamento 0x85, 48, 255
layer_note1 60, 0x7, 115
layer_note1 39, 0x23, 115
layer_end

.chan_2057:
chan_setbank 4
chan_setinstr 13
chan_setlayer 0, .layer_205F
chan_end

.layer_205F:
layer_portamento 0x81, 27, 255
layer_note1 3, 0x14, 115
layer_delay 0x1e
layer_end

.chan_2069:
chan_setbank 7
chan_setinstr 0
chan_setlayer 0, .layer_2071
chan_end

.layer_2071:
layer_note1 43, 0x6, 105
layer_portamento 0x81, 32, 255
layer_note1 44, 0x18, 105
layer_end

.chan_207C:
chan_setbank 7
chan_setinstr 3
chan_setval 15
chan_call .chan_fn_144
chan_setlayer 0, .layer_2089
chan_end

.layer_2089:
layer_note1 48, 0x55, 127
layer_end

.chan_208D:
chan_setbank 7
chan_setinstr 8
chan_setlayer 0, .layer_2095
chan_end

.layer_2095:
layer_note1 44, 0xc, 100
layer_portamento 0x81, 44, 255
layer_note1 32, 0x18, 105
layer_end

.chan_20A0:
chan_setbank 9
chan_setinstr 1
chan_setenvelope .envelope_305C
chan_setlayer 0, .layer_20AB
chan_end

.layer_20AB:
layer_portamento 0x83, 46, 255
layer_note1 27, 0x5, 127
layer_note1 32, 0x3, 127
layer_delay 0x22
layer_end

.chan_20B8:
chan_setbank 9
chan_setinstr 3
chan_setenvelope .envelope_319C
chan_setlayer 0, .layer_20C3
chan_end

.layer_20C3:
layer_somethingon
layer_portamento 0x85, 62, 255
layer_note1 50, 0x24, 93
layer_note1 26, 0x3c, 93
layer_end

.chan_20CF:
chan_setbank 4
chan_setinstr 5
chan_setlayer 0, .layer_20E0
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 2
chan_setinstr 0
chan_end

.layer_20E0:
layer_note1 62, 0x4, 105
layer_portamento 0x81, 43, 200
layer_note1 36, 0x4e, 127
layer_end

.chan_20EB:
chan_setbank 3
chan_setinstr 5
chan_setenvelope .envelope_305C
chan_setlayer 0, .layer_20F6
chan_end

.layer_20F6:
layer_note1 41, 0x6, 100
layer_note1 24, 0x1c, 100
layer_end

.chan_20FD:
chan_setbank 3
chan_setinstr 5
chan_setenvelope .envelope_305C
chan_setlayer 0, .layer_2108
chan_end

.layer_2108:
layer_note1 36, 0x5, 100
layer_note1 44, 0x18, 100
layer_end

.chan_210F:
chan_setbank 0
chan_setinstr 4
chan_setenvelope .envelope_305C
chan_setval 25
chan_call .chan_fn_144
chan_setlayer 0, .layer_211F
chan_end

.layer_211F:
layer_somethingon
layer_portamento 0x81, 39, 255
layer_note1 62, 0x1b, 107
layer_delay 0x12
layer_end

.chan_212A:
chan_setbank 7
chan_setinstr 10
chan_setlayer 0, .layer_2132
chan_end

.layer_2132:
layer_somethingon
layer_portamento 0x85, 41, 255
layer_note1 45, 0x28, 127
layer_note1 41, 0xf, 127
layer_end

.chan_213E:
chan_setbank 7
chan_setinstr 11
chan_setenvelope .envelope_305C
chan_setlayer 0, .layer_214B
chan_end

.layer_unused_2149:
layer_transpose 244

.layer_214B:
layer_somethingon
layer_portamento 0x85, 39, 255
layer_note1 32, 0xc, 127
layer_note1 39, 0x60, 127
layer_end

.chan_2157:
chan_setbank 9
chan_setinstr 3
chan_setval 20
chan_call .chan_fn_144
chan_setenvelope .envelope_3160
chan_setlayer 0, .layer_2167
chan_end

.layer_2167:
layer_transpose 232
layer_somethingon
layer_portamento 0x85, 25, 255
layer_note1 3, 0xf, 85
layer_transpose 0
layer_note1 51, 0x1c, 85
layer_delay 0x19
layer_end

.chan_2179:
chan_setbank 9
chan_setinstr 3
chan_setenvelope .envelope_319C
chan_setlayer 0, .layer_2184
chan_end

.layer_2184:
layer_transpose 253
layer_somethingon
layer_portamento 0x85, 24, 255
layer_note1 17, 0xa, 100
layer_note1 32, 0xa, 100
layer_note1 27, 0x6, 100
layer_end

.chan_2195:
chan_setbank 6
chan_setinstr 5
chan_setenvelope .envelope_305C
chan_setlayer 0, .layer_21A0
chan_end

.layer_21A0:
layer_transpose 10
layer_call .layer_fn_21AB
layer_call .layer_fn_21AB
layer_delay 0x14
layer_end

.layer_fn_21AB:
layer_portamento 0x85, 52, 255
layer_note1 48, 0x4, 115
layer_note1 52, 0x2, 115
layer_delay 0x2
layer_disableportamento
layer_end

.chan_21B9:
chan_setbank 2
chan_setlayer 0, .layer_21C2
chan_setlayer 1, .layer_21CC
chan_end

.layer_21C2:
layer_setinstr 0
layer_portamento 0x82, 44, 255
layer_note1 43, 0x54, 100
layer_end

.layer_21CC:
layer_setinstr 1
layer_portamento 0x82, 32, 255
layer_note1 31, 0x54, 100
layer_end

.chan_21D6:
chan_setbank 3
chan_setinstr 0
chan_setenvelope .envelope_30AC
chan_setlayer 0, .layer_21E1
chan_end

.layer_21E1:
layer_portamento 0x81, 62, 255
layer_note1 38, 0x7f, 117
layer_end

.chan_21E9:
chan_setbank 7
chan_setinstr 3
chan_setlayer 0, .layer_21F1
chan_end

.layer_21F1:
layer_note1 27, 0x6, 100
layer_note1 29, 0x3, 70
layer_delay 0x1e
layer_end

.chan_21FA:
chan_setbank 7
chan_setinstr 3
chan_setlayer 0, .layer_2202
chan_end

.layer_2202:
layer_note1 20, 0x4, 100
layer_delay 0x1e
layer_end

.chan_2208:
chan_setbank 7
chan_setinstr 3
chan_setlayer 0, .layer_2210
chan_end

.layer_2210:
layer_portamento 0x82, 29, 255
layer_note1 46, 0xc, 80
layer_end

.chan_2218:
chan_setbank 6
chan_setinstr 4
chan_setenvelope .envelope_307C
chan_setlayer 0, .layer_2225
chan_end

.layer_unused_2223:
layer_transpose 12

.layer_2225:
layer_somethingon
layer_portamento 0x85, 36, 255
layer_note1 48, 0x8, 100
layer_note1 45, 0x4, 100
layer_note1 48, 0xa, 100
layer_note1 41, 0x48, 100
layer_end

.chan_2237:
chan_setbank 6
chan_setinstr 9
chan_setval 25
chan_call .chan_fn_144
chan_setlayer 0, .layer_2247
chan_setlayer 1, .layer_2247
chan_end

.layer_2247:
layer_portamento 0x81, 20, 255
layer_note1 26, 0x12c, 127
layer_end

.chan_2250:
chan_setbank 7
chan_setinstr 7
chan_setlayer 0, .layer_2258
chan_end

.layer_2258:
layer_portamento 0x81, 32, 221
layer_note1 34, 0xa, 115
layer_end

.chan_2260:
chan_setbank 7
chan_setinstr 7
chan_setlayer 0, .layer_2268
chan_end

.layer_2268:
layer_portamento 0x81, 34, 221
layer_note1 38, 0xc, 127
layer_portamento 0x82, 34, 221
layer_note1 39, 0x12, 127
layer_end

.chan_2277:
chan_setbank 1
chan_setinstr 1
chan_setlayer 0, .layer_227F
chan_end

.layer_227F:
layer_portamento 0x81, 58, 255
layer_note1 52, 0x6, 105
layer_end

.chan_2287:
chan_setbank 0
chan_setinstr 1
chan_setenvelope .envelope_305C
chan_setlayer 0, .layer_2292
chan_end

.layer_2292:
layer_note1 43, 0x6, 90
layer_note1 44, 0x6, 90
layer_end

.chan_2299:
chan_setbank 7
chan_setinstr 8
chan_setlayer 0, .layer_22A1
chan_end

.layer_22A1:
layer_transpose 248
layer_call .layer_fn_22A6

.layer_fn_22A6:
layer_portamento 0x85, 44, 255
layer_note1 51, 0x9, 100
layer_note1 39, 0xc, 100
layer_end

.chan_22B1:
chan_setbank 7
chan_setinstr 8
chan_setlayer 0, .layer_22B9
chan_end

.layer_22B9:
layer_transpose 10
layer_portamento 0x83, 32, 255
layer_note1 39, 0x6, 105
layer_note1 27, 0x12, 105
layer_end

.chan_22C6:
chan_setbank 7
chan_setinstr 9
chan_setlayer 0, .layer_22CE
chan_end

.layer_22CE:
layer_somethingon
layer_portamento 0x83, 39, 255
layer_note1 41, 0x6, 127
layer_note1 37, 0x24, 127
layer_end

.chan_22DA:
chan_setbank 7
chan_setinstr 9
chan_setlayer 0, .layer_22E2
chan_end

.layer_22E2:
layer_portamento 0x81, 48, 255
layer_note1 40, 0x24, 127
layer_end

.chan_22EA:
chan_setbank 7
chan_setinstr 9
chan_setval 20
chan_call .chan_fn_144
chan_setlayer 0, .layer_22F7
chan_end

.layer_22F7:
layer_transpose 251
layer_call .layer_fn_2307
layer_delay 0xb
layer_transpose 248
layer_call .layer_fn_2307
layer_delay 0xa
layer_transpose 246

.layer_fn_2307:
layer_portamento 0x85, 29, 255
layer_note1 24, 0x2, 127
layer_note1 41, 0x10, 127
layer_end

.chan_2312:
chan_setbank 7
chan_setinstr 9
chan_setval 20
chan_call .chan_fn_144
chan_setlayer 0, .layer_231F
chan_end

.layer_231F:
layer_transpose 244
layer_portamento 0x85, 25, 255
layer_note1 39, 0x4, 127
layer_note1 29, 0x30, 127
layer_end

.chan_232C:
chan_setbank 7
chan_setinstr 2
chan_setlayer 0, .layer_2334
chan_end

.layer_2334:
layer_note1 44, 0x4, 127
layer_delay 0x14
layer_end

.chan_233A:
chan_setbank 9
chan_setinstr 3
chan_setlayer 0, .layer_2342
chan_end

.layer_2342:
layer_portamento 0x81, 24, 255
layer_note1 53, 0x12, 80
layer_end

.chan_234A:
chan_setbank 7
chan_setinstr 10
chan_setenvelope .envelope_30CC
chan_setlayer 0, .layer_2355
chan_end

.layer_2355:
layer_note1 50, 0x8, 105
layer_portamento 0x82, 46, 255
layer_note1 50, 0x30, 105
layer_end

.chan_2360:
chan_setbank 6
chan_setinstr 1
chan_setlayer 0, .layer_2368
chan_end

.layer_2368:
layer_portamento 0x81, 27, 255
layer_note1 43, 0x1e, 127
layer_end

.chan_2370:
chan_setbank 5
chan_setinstr 7
chan_setlayer 0, .layer_2384
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 7
chan_setinstr 12
chan_setlayer 1, .layer_252F
chan_end

.layer_2384:
layer_note1 34, 0xaf, 127
layer_end

.chan_2389:
chan_setbank 6
chan_setinstr 9
chan_setval 25
chan_call .chan_fn_144
chan_setlayer 0, .layer_2396
chan_end

.layer_2396:
layer_note1 55, 0x32, 127
layer_end

.chan_239A:
chan_setbank 7
chan_setinstr 7
chan_setlayer 0, .layer_23A2
chan_end

.layer_23A2:
layer_portamento 0x82, 51, 127
layer_note1 48, 0x6, 127
layer_end

.chan_23AA:
chan_setbank 6
chan_setinstr 2
chan_setval 25
chan_call .chan_fn_144
chan_setlayer 0, .layer_23BC
chan_setlayer 1, .layer_23BA
chan_end

.layer_23BA:
layer_delay 0x4

.layer_23BC:
layer_somethingon
layer_portamento 0x85, 31, 255
layer_note1 34, 0x18, 127
layer_note1 17, 0x48, 127
layer_end

.chan_23C8:
chan_setbank 4
chan_setinstr 15
chan_setlayer 0, .layer_23D5
chan_setlayer 1, .layer_23D3
chan_end

.layer_23D3:
layer_transpose 4

.layer_23D5:
layer_jump .layer_1036

.chan_23D8:
chan_setbank 9
chan_setinstr 3
chan_setval 24
chan_call .chan_fn_144
chan_setenvelope .envelope_319C
chan_setvibratoextent 80
chan_setvibratorate 60
chan_setlayer 0, .layer_23F3
chan_setval 30
chan_call .chan_fn_12B
chan_setvibratoextent 0
chan_end

.layer_23F3:
layer_somethingon
layer_portamento 0x85, 15, 255
layer_note1 3, 0x7, 100
layer_note1 36, 0x18, 100
layer_end

.chan_23FF:
chan_setbank 6
chan_setinstr 0
chan_setenvelope .envelope_305C
chan_setlayer 0, .layer_240A
chan_end

.layer_240A:
layer_somethingon
layer_portamento 0x81, 44, 255
layer_note1 51, 0x8, 118
layer_end

.chan_2413:
chan_setbank 6
chan_setinstr 7
chan_setlayer 0, .layer_2424
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 7
chan_setinstr 2
chan_end

.layer_2424:
layer_portamento 0x81, 3, 255
layer_note1 39, 0x5, 127
layer_portamento 0x81, 27, 255
layer_note1 49, 0x6, 127
layer_end

.chan_2433:
chan_setbank 6
chan_setinstr 7
chan_setlayer 0, .layer_2444
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 2
chan_setinstr 1
chan_end

.layer_2444:
layer_portamento 0x81, 3, 255
layer_note1 39, 0x5, 127
layer_portamento 0x83, 36, 255
layer_note1 48, 0x6, 92
layer_note1 55, 0x30, 92
layer_end

.chan_2456:
chan_setbank 3
chan_setinstr 0
chan_setenvelope .envelope_30AC
chan_setlayer 0, .layer_2461
chan_end

.layer_2461:
layer_portamento 0x82, 62, 255
layer_note1 38, 0x60, 117
layer_end

.chan_2469:
chan_setbank 7
chan_setinstr 5
chan_setenvelope .envelope_307C
chan_setlayer 0, .layer_2474
chan_end

.layer_2474:
layer_portamento 0x85, 41, 255
layer_note1 36, 0x18, 127
layer_end

.chan_247C:
chan_call .chan_1ED7
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 7
chan_setinstr 13
chan_setlayer 1, .layer_24AD
chan_setlayer 2, .layer_24B1
chan_setval 11
chan_call .chan_fn_12B
chan_call .chan_15EC
chan_setval 20
chan_call .chan_fn_12B
chan_setbank 1
chan_setinstr 4
chan_setlayer 0, .layer_24A3
chan_end

.layer_24A3:
layer_note1 37, 0x8, 96
layer_note1 41, 0x6, 96
layer_note1 32, 0x18, 96
layer_end

.layer_24AD:
layer_note1 46, 0x32, 127
layer_end

.layer_24B1:
layer_note1 39, 0x32, 127
layer_end

.chan_24B5:
chan_setbank 7
chan_setinstr 12
chan_setlayer 0, .layer_24BD
chan_end

.layer_24BD:
layer_portamento 0x83, 27, 255
layer_note0 34, 0x12, 127, 127
layer_note1 20, 0x28, 127
layer_end

.chan_24C9:
chan_setbank 8
chan_setinstr 12
chan_setvibratoextent 80
chan_setvibratorate 5
chan_setlayer 0, .layer_24DC
chan_setval 88
chan_call .chan_fn_12B
chan_setvibratoextent 0
chan_end

.layer_24DC:
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

.chan_2501:
chan_setbank 9
chan_setinstr 3
chan_setlayer 0, .layer_2509
chan_end

.layer_2509:
layer_portamento 0x85, 31, 255
layer_note1 8, 0x6, 100
layer_note1 32, 0xc, 100
layer_end

.chan_2514:
chan_setbank 7
chan_setinstr 12
chan_setlayer 0, .layer_251F
chan_setlayer 1, .layer_251F
chan_end

.layer_251F:
layer_portamento 0x81, 32, 255
layer_note1 22, 0x24, 110
layer_end

.chan_2527:
chan_setbank 7
chan_setinstr 12
chan_setlayer 0, .layer_252F
chan_end

.layer_252F:
layer_portamento 0x81, 26, 255
layer_note1 19, 0x60, 127
layer_end

.chan_2537:
chan_setbank 6
chan_setinstr 7
chan_setlayer 0, .layer_253F
chan_end

.layer_253F:
layer_transpose 3
layer_note0 31, 0x8, 127, 70
layer_note0 30, 0x9, 127, 70
layer_note0 29, 0x8, 127, 70
layer_note0 28, 0x9, 127, 70
layer_end

.chan_2552:
chan_setbank 6
chan_setinstr 11
chan_setlayer 0, .layer_255A
chan_end

.layer_255A:
layer_portamento 0x81, 12, 255
layer_note1 51, 0x24, 127
layer_end

.chan_2562:
chan_setbank 6
chan_setinstr 9
chan_setval 25
chan_call .chan_fn_144
chan_setlayer 0, .layer_2572
chan_setlayer 1, .layer_2572
chan_end

.layer_2572:
layer_delay 0xdc

.layer_2575:
layer_portamento 0x81, 20, 255
layer_note1 26, 0xc8, 110
layer_end

.chan_257E:
chan_call .chan_210F
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 7
chan_setinstr 8
chan_setlayer 1, .layer_2095
chan_end

.chan_258E:
chan_call .chan_210F
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 7
chan_setinstr 8
chan_setlayer 1, .layer_259E
chan_end

.layer_259E:
layer_note1 39, 0xe, 100
layer_portamento 0x81, 39, 255
layer_note1 27, 0x1c, 105
layer_end

.chan_25A9:
chan_call .chan_210F
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 7
chan_setinstr 7
chan_setlayer 1, .layer_23A2
chan_end

.chan_25B9:
chan_call .chan_210F
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 7
chan_setinstr 8
chan_setlayer 1, .layer_22B9
chan_end

.chan_25C9:
chan_call .chan_210F
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 7
chan_setinstr 0
chan_setlayer 1, .layer_2071
chan_end

.chan_25D9:
chan_call .chan_213E
chan_setlayer 1, .layer_214B
chan_end

.chan_25E0:
chan_call .chan_148F
chan_setval 12
chan_call .chan_fn_12B
chan_setbank 6
chan_setinstr 1
chan_setlayer 2, .layer_25F0
chan_end

.layer_25F0:
layer_note1 24, 0x46, 127
layer_end

.chan_25F4:
chan_setbank 9
chan_setinstr 3
chan_setvibratoextent 80
chan_setvibratorate 60
chan_setenvelope .envelope_306C
chan_setlayer 0, .layer_260F
chan_setlayer 1, .layer_260D
chan_setval 56
chan_call .chan_fn_12B
chan_setvibratoextent 0
chan_end

.layer_260D:
layer_transpose 1

.layer_260F:
layer_note1 15, 0x48, 127
layer_end

.chan_2613:
chan_setbank 4
chan_setinstr 15
chan_setval 40
chan_call .chan_fn_144
chan_setenvelope .envelope_3130
chan_setlayer 0, .layer_2623
chan_end

.layer_2623:
layer_portamento 0x84, 3, 255
layer_note1 39, 0x7, 127
layer_note1 44, 0x8, 127
layer_note1 51, 0x7, 127
layer_note1 56, 0x8, 127
layer_end

.chan_2634:
chan_setbank 6
chan_setinstr 1
chan_setval 55
chan_call .chan_fn_144
chan_setlayer 0, .layer_1EA6
chan_end

.chan_2641:
chan_setbank 7
chan_setinstr 12
chan_setlayer 0, .layer_2649
chan_end

.layer_2649:
layer_note1 29, 0x7, 127
layer_note0 31, 0x18, 127, 127
layer_note1 27, 0x26, 127
layer_end

.chan_2654:
chan_setbank 6
chan_setinstr 0
chan_setlayer 0, .layer_265C
chan_end

.layer_265C:
layer_somethingon
layer_portamento 0x85, 32, 255
layer_note1 46, 0x9, 80
layer_note1 36, 0xa, 90
layer_end

.chan_2668:
chan_setbank 6
chan_setinstr 11
chan_setenvelope .envelope_308C
chan_setlayer 0, .layer_2673
chan_end

.layer_2673:
layer_somethingon
layer_portamento 0x85, 19, 255
layer_note1 31, 0xe, 127
layer_note1 62, 0x8, 127
layer_end

.chan_267F:
chan_setbank 2
chan_setinstr 1
chan_setenvelope .envelope_304C
chan_setlayer 0, .layer_2696
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 6
chan_setinstr 0
chan_setlayer 1, .layer_265C
chan_end

.layer_2696:
layer_portamento 0x81, 47, 255
layer_note1 50, 0x18, 115
layer_end

.chan_269E:
chan_setbank 4
chan_setinstr 9
chan_setenvelope .envelope_304C
chan_setlayer 0, .layer_26AC
chan_setlayer 1, .layer_26AE
chan_end

.layer_26AC:
layer_setinstr 15

.layer_26AE:
layer_transpose 6
layer_call .layer_fn_101A
layer_transpose 247
layer_call .layer_fn_101A
layer_transpose 236
layer_jump .layer_fn_101A

.chan_26BD:
chan_call .chan_2370
chan_setlayer 1, .layer_26E3
chan_setval 2
chan_call .chan_fn_12B
chan_setbank 8
chan_setinstr 10
chan_setlayer 2, .layer_26D0
chan_end

.layer_26D0:
layer_portamento 0x83, 43, 255
layer_note1 46, 0x9, 115
layer_somethingon
layer_portamento 0x85, 48, 255
layer_note1 50, 0x8, 127
layer_note1 44, 0x1e, 127
layer_end

.layer_26E3:
layer_transpose 2
layer_jump .layer_2384

.chan_26E8:
chan_setbank 7
chan_setinstr 10
chan_setenvelope .envelope_30CC
chan_setlayer 0, .layer_26F3
chan_end

.layer_26F3:
layer_transpose 3
layer_portamento 0x81, 46, 255
layer_note1 55, 0xa, 105
layer_call .layer_fn_2717
layer_delay 0xf
layer_portamento 0x81, 44, 255
layer_note0 53, 0xf, 105, 127
layer_portamento 0x81, 43, 255
layer_note1 51, 0xc, 105
layer_portamento 0x81, 46, 255
layer_note1 43, 0xe, 105

.layer_fn_2717:
layer_portamento 0x81, 43, 255
layer_note1 51, 0xc, 105
layer_end

.chan_271F:
chan_setbank 7
chan_setinstr 10
chan_setenvelope .envelope_30CC
chan_setlayer 0, .layer_272A
chan_end

.layer_272A:
layer_transpose 6
layer_portamento 0x83, 53, 255
layer_note1 48, 0x8, 105
layer_note0 60, 0x9, 105, 100
layer_note1 39, 0xb, 105
layer_end

.chan_273B:
chan_setbank 6
chan_setinstr 7
chan_setlayer 0, .layer_2743
chan_end

.layer_2743:
layer_transpose 254
layer_note0 31, 0xa, 127, 70
layer_note0 30, 0xb, 127, 70
layer_note0 29, 0xa, 127, 70
layer_note0 28, 0xc, 127, 70
layer_end

.chan_2756:
chan_call .chan_210F
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 7
chan_setinstr 10
chan_setenvelope .envelope_30CC
chan_setlayer 1, .layer_2769
chan_end

.layer_2769:
layer_transpose 12
layer_portamento 0x83, 53, 255
layer_note1 48, 0x8, 105
layer_note0 60, 0x9, 105, 100
layer_note1 39, 0x14, 105
layer_end

.chan_277A:
chan_call .chan_1ED7
chan_setval 10
chan_call .chan_fn_12B
chan_setbank 9
chan_setinstr 0
chan_setenvelope .envelope_3180
chan_setlayer 0, .layer_278D
chan_end

.layer_278D:
layer_transpose 6
layer_portamento 0x85, 12, 255
layer_note1 0, 0x12, 127
layer_note1 10, 0x14, 127
layer_end

.chan_279A:
chan_setbank 7
chan_setinstr 0
chan_setlayer 0, .layer_27A9
chan_setlayer 1, .layer_27A5
chan_end

.layer_27A5:
layer_transpose 5
layer_delay 0x3

.layer_27A9:
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

.table_27C9:
sound_ref .chan_2809
sound_ref .chan_281A
sound_ref .chan_282B
sound_ref .chan_2847
sound_ref .chan_285B
sound_ref .chan_286F
sound_ref .chan_2883
sound_ref .chan_2895
sound_ref .chan_28A8
sound_ref .chan_28D9
sound_ref .chan_295C
sound_ref .chan_1C8D
sound_ref .chan_2809
sound_ref .chan_2809
sound_ref .chan_2809
sound_ref .chan_2809
sound_ref .chan_2FCF
sound_ref .chan_281A
sound_ref .chan_2809
sound_ref .chan_2809
sound_ref .chan_2809
sound_ref .chan_2809
sound_ref .chan_2809
sound_ref .chan_2809
sound_ref .chan_2809
sound_ref .chan_281A
sound_ref .chan_2809
sound_ref .chan_2809
sound_ref .chan_2809
sound_ref .chan_2809
sound_ref .chan_2809
sound_ref .chan_2809

.chan_2809:
chan_setbank 7
chan_setinstr 5
chan_setlayer 0, .layer_2811
chan_end

.layer_2811:
layer_somethingon
.layer_2812:
layer_note1 39, 0x12c, 127
layer_jump .layer_2812
layer_end

.chan_281A:
chan_setbank 7
chan_setinstr 6
chan_setlayer 0, .layer_2822
chan_end

.layer_2822:
layer_somethingon
.layer_2823:
layer_note1 39, 0x12c, 90
layer_jump .layer_2823
layer_end

.chan_282B:
chan_setbank 9
chan_setinstr 3
chan_setenvelope .envelope_306C
chan_setlayer 0, .layer_2836
chan_end

.layer_2836:
layer_transpose 12
layer_somethingon
layer_portamento 0x85, 27, 255
.layer_283D:
layer_note1 51, 0x16, 50
layer_note1 27, 0x16, 50
layer_jump .layer_283D
layer_end

.chan_2847:
chan_setbank 3
chan_setinstr 9
chan_setenvelope .envelope_306C
chan_setlayer 0, .layer_2852
chan_end

.layer_2852:
layer_somethingon
.layer_2853:
layer_note1 46, 0xc8, 92
layer_jump .layer_2853
layer_end

.chan_285B:
chan_setbank 7
chan_setinstr 5
chan_setenvelope .envelope_306C
chan_setlayer 0, .layer_2866
chan_end

.layer_2866:
layer_somethingon
.layer_2867:
layer_note1 44, 0x12c, 127
layer_jump .layer_2867
layer_end

.chan_286F:
chan_setbank 3
chan_setinstr 6
chan_setenvelope .envelope_306C
chan_setlayer 0, .layer_287A
chan_end

.layer_287A:
layer_somethingon
.layer_287B:
layer_note1 35, 0x12c, 127
layer_jump .layer_287B
layer_end

.chan_2883:
chan_setbank 5
chan_setinstr 5
chan_setlayer 0, .layer_288B
chan_end

.layer_288B:
layer_note1 56, 0x4, 62
layer_note1 32, 0x3, 62
layer_jump .layer_288B
layer_end

.chan_2895:
chan_setbank 9
chan_setinstr 3
chan_setlayer 0, .layer_289D
chan_end

.layer_289D:
layer_portamento 0x81, 24, 255
layer_note1 56, 0x10, 55
layer_jump .layer_289D
layer_end

.chan_28A8:
chan_setbank 3
chan_setinstr 5
chan_setlayer 0, .layer_28B9
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 3
chan_setinstr 8
chan_end

.layer_28B9:
layer_note1 48, 0x6, 100
layer_somethingon
.layer_28BD:
layer_note1 44, 0x12c, 127
layer_jump .layer_28BD
layer_end

.chan_unused_28C5:
chan_setbank 3
chan_setinstr 6
chan_setenvelope .envelope_306C
chan_setlayer 0, .layer_28D0
chan_end

.layer_28D0:
layer_somethingon
layer_note1 35, 0x12c, 100
layer_jump .layer_287B
layer_end

.chan_28D9:
chan_setlayer 0, .layer_28FF
chan_setlayer 1, .layer_290F
chan_setpanmix 0
.chan_28E1:
chan_setbank 5
chan_setinstr 6
chan_setdecayrelease 3
chan_setval 1
chan_call .chan_fn_12B
chan_setbank 6
chan_setinstr 9
chan_setdecayrelease 3
chan_setval 199
chan_call .chan_fn_12B
chan_setval 100
chan_call .chan_fn_12B
chan_jump .chan_28E1

.layer_28FF:
layer_somethingon
layer_portamento 0x85, 38, 255
.layer_2904:
layer_note1 41, 0x12c, 127
layer_note1 38, 0x12c, 127
layer_jump .layer_2904

.layer_290F:
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
layer_jump .layer_290F

.chan_295C:
chan_setbank 5
chan_setinstr 5
chan_setenvelope .envelope_304C
chan_setlayer 0, .layer_2967
chan_end

.layer_2967:
layer_portamento 0x81, 56, 255
layer_note1 44, 0x3, 85
layer_note1 20, 0x2, 85
layer_jump .layer_2967
layer_end

.table_2975:
sound_ref .chan_29D5
sound_ref .chan_29FD
sound_ref .chan_2A2B
sound_ref .chan_2A2B
sound_ref .chan_2A69
sound_ref .chan_2A7A
sound_ref .chan_2AAB
sound_ref .chan_2A8E
sound_ref .chan_2AC8
sound_ref .chan_2AE4
sound_ref .chan_2B1D
sound_ref .chan_2B36
sound_ref .chan_2B50
sound_ref .chan_2B78
sound_ref .chan_2BB4
sound_ref .chan_2BC3
sound_ref .chan_2BE0
sound_ref .chan_2BEC
sound_ref .chan_2C08
sound_ref .chan_2C2A
sound_ref .chan_2C3D
sound_ref .chan_2C86
sound_ref .chan_2CBB
sound_ref .chan_2D10
sound_ref .chan_2D8D
sound_ref .chan_F22
sound_ref .chan_2D9D
sound_ref .chan_2DA9
sound_ref .chan_2DC4
sound_ref .chan_2DDE
sound_ref .chan_11B7
sound_ref .chan_2ED7
sound_ref .chan_2EEE
sound_ref .chan_2F03
sound_ref .chan_2F18
sound_ref .chan_2C2A
sound_ref .chan_2C3D
sound_ref .chan_2C86
sound_ref .chan_2CBB
sound_ref .chan_2D10
sound_ref .chan_2D8D
sound_ref .chan_F22
sound_ref .chan_2D9D
sound_ref .chan_2DA9
sound_ref .chan_2DC4
sound_ref .chan_2DDE
sound_ref .chan_11B7
sound_ref .chan_29D5

.chan_29D5:
chan_setbank 9
chan_setinstr 1
chan_setmutebhv 0x0
chan_setnotepriority 14
chan_setpanmix 0
chan_setenvelope .envelope_3180
chan_setlayer 0, .layer_29E8
chan_setlayer 1, .layer_29F5
chan_end

.layer_29E8:
layer_portamento 0x1, 35, 0xa
layer_note1 41, 0xa, 80
layer_setpan 0
layer_note1 41, 0xa, 80
layer_end

.layer_29F5:
layer_setpan 127
layer_delay 0xc
layer_note1 41, 0xa, 80
layer_end

.chan_29FD:
chan_setbank 9
chan_setinstr 1
chan_setmutebhv 0x0
chan_setnotepriority 14
chan_setpanmix 0
chan_setlayer 0, .layer_2A0D
chan_setlayer 1, .layer_2A24
chan_end

.layer_2A0D:
layer_setpan 34
.layer_2A0F:
layer_note0 45, 0xc, 80, 63
layer_note0 41, 0xc, 80, 63
layer_note0 48, 0xc, 80, 63
layer_note0 41, 0xc, 38, 63
layer_note0 48, 0xc, 38, 63
layer_end

.layer_2A24:
layer_setpan 94
layer_delay 0x2
layer_jump .layer_2A0F

.chan_2A2B:
chan_setbank 9
chan_setinstr 1
chan_setmutebhv 0x0
chan_setnotepriority 14
chan_setpanmix 0
chan_setlayer 0, .layer_2A3B
chan_setlayer 1, .layer_2A48
chan_end

.layer_2A3B:
layer_note1 43, 0x9, 95
layer_note1 39, 0x9, 90
layer_note1 43, 0x9, 95
layer_note1 39, 0x9, 90
layer_end

.layer_2A48:
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

.chan_2A69:
chan_setbank 9
chan_setnotepriority 14
chan_setinstr 2
chan_setlayer 0, .layer_2A72
chan_end

.layer_2A72:
layer_portamento 0x1, 32, 0x7f
layer_note1 56, 0x1e, 102
layer_end

.chan_2A7A:
chan_setnotepriority 14
chan_setbank 9
chan_setinstr 0
chan_setenvelope .envelope_31AC
chan_setlayer 0, .layer_2A86
chan_end

.layer_2A86:
layer_portamento 0x1, 32, 0x7f
layer_note1 53, 0x1e, 78
layer_end

.chan_2A8E:
chan_setmutebhv 0x0
chan_setnotepriority 14
chan_setbank 9
chan_setinstr 3
chan_setenvelope .envelope_3190
chan_setlayer 0, .layer_2A9C
chan_end

.layer_2A9C:
layer_portamento 0x1, 32, 0x8
layer_note1 27, 0x8, 127
layer_portamento 0x81, 39, 255
layer_note1 20, 0x28, 127
layer_end

.chan_2AAB:
chan_setmutebhv 0x0
chan_setnotepriority 14
chan_setbank 9
chan_setinstr 3
chan_setenvelope .envelope_319C
chan_setlayer 0, .layer_2AB9
chan_end

.layer_2AB9:
layer_portamento 0x1, 27, 0x8
layer_note1 32, 0x8, 93
layer_portamento 0x81, 20, 255
layer_note1 39, 0x28, 93
layer_end

.chan_2AC8:
chan_setbank 9
chan_setnotepriority 14
chan_setinstr 1
chan_setenvelope .envelope_31B8
chan_setvibratorate 1
chan_setvibratoextent 100
chan_setlayer 0, .layer_2AD8
chan_end

.layer_2AD8:
layer_somethingon
layer_portamento 0x85, 27, 255
layer_note1 15, 0x6, 127
layer_note1 34, 0xc, 127
layer_end

.chan_2AE4:
chan_setbank 9
chan_setnotepriority 14
chan_setinstr 1
chan_setenvelope .envelope_31C8
chan_setvibratorate 25
chan_setvibratoextent 80
chan_setlayer 0, .layer_2B12
chan_setlayer 1, .layer_2B0E
chan_setval 5
chan_call .chan_fn_12B
chan_setvibratorate 35
chan_setvibratoextent 115
chan_setval 55
chan_call .chan_fn_12B
chan_setvibratoextent 80
chan_setval 67
chan_call .chan_fn_12B
chan_setvibratoextent 0
chan_end

.layer_2B0E:
layer_transpose 12
layer_delay 0x3

.layer_2B12:
layer_portamento 0x85, 24, 255
layer_note1 28, 0x5, 110
layer_note1 28, 0x78, 110
layer_end

.chan_2B1D:
chan_setbank 9
chan_setnotepriority 14
chan_setinstr 3
chan_setlayer 0, .layer_2B2B
chan_setlayer 1, .layer_2B29
chan_end

.layer_2B29:
layer_delay 0x2

.layer_2B2B:
layer_portamento 0x85, 47, 255
layer_note1 35, 0x8, 90
layer_note1 47, 0x10, 90
layer_end

.chan_2B36:
chan_setbank 9
chan_setnotepriority 14
chan_setinstr 3
chan_setlayer 0, .layer_2B44
chan_setlayer 1, .layer_2B42
chan_end

.layer_2B42:
layer_delay 0x2

.layer_2B44:
layer_portamento 0x85, 35, 255
layer_note1 47, 0x8, 90
layer_note1 35, 0x10, 90
layer_disableportamento
layer_end

.chan_2B50:
chan_setbank 9
chan_setnotepriority 14
chan_setpanmix 0
chan_setinstr 3
chan_setenvelope .envelope_31C8
chan_setlayer 0, .layer_2B5E
chan_end

.layer_2B5E:
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

.chan_2B78:
chan_setbank 9
chan_setnotepriority 14
chan_setpanmix 0
chan_setinstr 3
chan_setenvelope .envelope_31C8
chan_setval 25
chan_call .chan_fn_144
chan_setlayer 0, .layer_2B8B
chan_end

.layer_2B8B:
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

.chan_2BB4:
chan_setmutebhv 0x0
chan_setnotepriority 14
chan_setbank 9
chan_setinstr 4
chan_setlayer 0, .layer_2BBF
chan_end

.layer_2BBF:
layer_note1 39, 0x18, 105
layer_end

.chan_2BC3:
chan_setmutebhv 0x0
chan_setnotepriority 14
chan_setbank 9
chan_setinstr 3
chan_setenvelope .envelope_319C
chan_setlayer 0, .layer_2BD1
chan_end

.layer_2BD1:
layer_portamento 0x81, 23, 255
layer_note1 35, 0x9, 96
layer_portamento 0x81, 36, 255
layer_note1 43, 0x44, 100
layer_end

.chan_2BE0:
chan_setnotepriority 14
chan_setbank 9
chan_setinstr 3
chan_setlayer 0, .layer_2BE9
chan_end

.layer_2BE9:
layer_delay 0x1
layer_end

.chan_2BEC:
chan_setmutebhv 0x0
chan_setnotepriority 14
chan_setbank 6
chan_setinstr 11
chan_setlayer 0, .layer_2BF7
chan_end

.layer_2BF7:
layer_portamento 0x81, 32, 255
layer_note0 39, 0x5, 115, 255
layer_portamento 0x81, 44, 255
layer_note0 51, 0x3, 115, 255
layer_end

.chan_2C08:
chan_setmutebhv 0x0
chan_setbank 9
chan_setinstr 1
chan_setval 60
chan_call .chan_fn_144
chan_setlayer 0, .layer_2C17
chan_end

.layer_2C17:
layer_note1 46, 0x3, 90
layer_note1 46, 0x3, 30
layer_note1 58, 0x3, 90
layer_note1 58, 0x3, 30
layer_note1 46, 0x3, 90
layer_note1 46, 0x3, 30
layer_end

.chan_2C2A:
chan_setbank 9
chan_setinstr 0
chan_setenvelope .envelope_304C
chan_setlayer 0, .layer_2C35
chan_end

.layer_2C35:
layer_portamento 0x81, 15, 255
layer_note1 51, 0x5, 73
layer_end

.chan_2C3D:
chan_setbank 9
chan_setinstr 3
chan_setenvelope .envelope_30E0
chan_setvibratoextent 3
chan_setvibratorate 60
chan_setval 25
chan_call .chan_fn_144
chan_setlayer 0, .layer_2C60
chan_setlayer 1, .layer_2C75
chan_setlayer 2, .layer_2C6C
chan_setval 70
chan_call .chan_fn_12B
chan_setbank 10
chan_setinstr 8
chan_end

.layer_2C60:
layer_call .layer_105F
layer_delay 0x12
layer_transpose 0
layer_note1 39, 0xc8, 120
layer_end

.layer_2C6C:
layer_delay 0x6e
layer_transpose 0
layer_note1 39, 0xc8, 31
layer_end

.layer_2C75:
layer_transpose 24
layer_delay 0x1e
layer_note1 25, 0x2, 18
layer_note1 37, 0x7, 36
layer_note1 30, 0x5, 18
layer_note1 42, 0x37, 36
layer_end

.chan_2C86:
chan_setbank 9
chan_setnotepriority 14
chan_setpanmix 0
chan_setinstr 3
chan_setenvelope .envelope_31C8
chan_setval 25
chan_call .chan_fn_144
chan_setpanmix 0
chan_stereoheadseteffects 1
chan_setlayer 0, .layer_2C9D
chan_end

.layer_2C9D:
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

.chan_2CBB:
chan_reservenotes 4
chan_setbank 9
chan_setinstr 2
chan_setpanmix 0
chan_stereoheadseteffects 1
chan_setval 30
chan_call .chan_fn_144
chan_setenvelope .envelope_3130
chan_setdecayrelease 220
chan_setlayer 0, .layer_2CDB
chan_setlayer 1, .layer_2CD6
chan_end

.layer_2CD6:
layer_transpose 244
layer_jump .layer_2CDD

.layer_2CDB:
layer_transpose 232
.layer_2CDD:
layer_call .layer_fn_2CE3
layer_call .layer_fn_2CE3

.layer_fn_2CE3:
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

.chan_2D10:
chan_reservenotes 4
chan_setbank 9
chan_setinstr 2
chan_setval 30
chan_call .chan_fn_144
chan_setenvelope .envelope_31D8
chan_setdecayrelease 220
chan_setlayer 0, .layer_2D2C
chan_setlayer 1, .layer_2D27
chan_end

.layer_2D27:
layer_transpose 24
layer_jump .layer_2D2E

.layer_2D2C:
layer_transpose 12
.layer_2D2E:
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

.chan_2D8D:
chan_setbank 6
chan_setinstr 9
chan_setval 25
chan_call .chan_fn_144
chan_setlayer 0, .layer_2575
chan_setlayer 1, .layer_2575
chan_end

.chan_2D9D:
chan_setbank 9
chan_setinstr 5
chan_setlayer 0, .layer_2DA5
chan_end

.layer_2DA5:
layer_note1 39, 0x30, 127
layer_end

.chan_2DA9:
chan_setbank 9
chan_setinstr 3
chan_setenvelope .envelope_305C
chan_setlayer 0, .layer_2DB4
chan_end

.layer_2DB4:
layer_transpose 244
layer_portamento 0x83, 3, 255
layer_note1 15, 0xa, 127
layer_somethingon
layer_transpose 0
layer_note1 46, 0x64, 127
layer_end

.chan_2DC4:
chan_setbank 9
chan_setinstr 3
chan_setlayer 0, .layer_2DCF
chan_setenvelope .envelope_305C
chan_end

.layer_2DCF:
layer_portamento 0x81, 3, 255
layer_note1 15, 0xc, 127
layer_portamento 0x81, 39, 255
layer_note1 3, 0x64, 127
layer_end

.chan_2DDE:
chan_setbank 9
chan_setnotepriority 14
chan_setpanmix 0
chan_setinstr 3
chan_setenvelope .envelope_3180
chan_setreverb 30
chan_setlayer 0, .layer_2E6A
chan_setlayer 1, .layer_2DF1
chan_end

.layer_2DF1:
layer_transpose 232
layer_setpan 24
layer_call .layer_fn_2E45
layer_transpose 244
layer_setpan 44
layer_call .layer_fn_2E45
layer_transpose 0

.layer_2E01:
layer_setpan 64
layer_call .layer_fn_2E45
layer_transpose 12
layer_setpan 84
layer_call .layer_fn_2E45
layer_transpose 24
layer_setpan 104
layer_call .layer_fn_2E45
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

.layer_fn_2E45:
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

.layer_2E6A:
layer_transpose 232
layer_call .layer_fn_2EAA
layer_transpose 244
layer_call .layer_fn_2EAA
layer_transpose 0
layer_call .layer_fn_2EAA

.layer_2E79:
layer_transpose 12
layer_call .layer_fn_2EAA
layer_transpose 24
layer_call .layer_fn_2EAA
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

.layer_fn_2EAA:
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

.chan_2ED7:
chan_setbank 10
chan_setinstr 14
chan_setlayer 0, .layer_2EE2
chan_setlayer 1, .layer_2EE7
chan_end

.layer_2EE2:
layer_note1 39, 0xfa, 127
layer_end

.layer_2EE7:
layer_delay 0x9
layer_note1 39, 0xf1, 45
layer_end

.chan_2EEE:
chan_setbank 9
chan_setinstr 1
chan_setlayer 0, .layer_2EF6
chan_end

.layer_2EF6:
layer_note1 46, 0x3, 90
layer_note1 46, 0x3, 30
layer_note1 58, 0x3, 90
layer_note1 58, 0x3, 30
layer_end

.chan_2F03:
chan_setbank 9
chan_setinstr 1
chan_setlayer 0, .layer_2F0B
chan_end

.layer_2F0B:
layer_note1 58, 0x3, 90
layer_note1 58, 0x3, 30
layer_note1 46, 0x3, 90
layer_note1 46, 0x3, 30
layer_end

.chan_2F18:
chan_reservenotes 6
chan_setbank 9
chan_setnotepriority 14
chan_setpanmix 0
chan_setinstr 3
chan_setenvelope .envelope_3180
chan_setreverb 30
chan_setlayer 0, .layer_2E79
chan_setlayer 1, .layer_2E01
chan_end

.chan_2F2D:
chan_setbank 5
chan_setinstr 9
chan_setval 40
chan_call .chan_fn_144
chan_setlayer 0, .layer_2F3A
chan_end

.layer_2F3A:
layer_delay 0x4b
layer_note0 39, 0xf5, 100, 127
layer_note0 39, 0xa, 85, 127
layer_note0 40, 0x123, 98, 127
layer_note0 39, 0x91, 75, 127
layer_note0 41, 0xbd, 84, 127
layer_note0 39, 0x4b, 73, 127
layer_note0 39, 0x96, 94, 127
layer_note0 36, 0x74, 78, 127
layer_jump .layer_2F3A
layer_end

.chan_2F65:
chan_setbank 5
chan_setinstr 10
chan_setval 60
chan_call .chan_fn_144
chan_setlayer 0, .layer_2F72
chan_end

.layer_2F72:
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
layer_jump .layer_2F72
layer_end

.chan_2F9B:
chan_setbank 5
chan_setinstr 12
chan_setval 30
chan_call .chan_fn_144
chan_setlayer 0, .layer_2FA8
chan_end

.layer_2FA8:
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
layer_jump .layer_2FA8
layer_end

.chan_2FCF:
chan_setbank 5
chan_setval 15
chan_call .chan_fn_144
chan_setlayer 0, .layer_2FE0
chan_setlayer 1, .layer_3006
chan_setlayer 2, .layer_3008
chan_end

.layer_2FE0:
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
layer_jump .layer_2FE0

.layer_3006:
layer_transpose 12

.layer_3008:
layer_setinstr 13
layer_somethingon
layer_delay 0xf
.layer_300D:
layer_note1 39, 0x12c, 25
layer_jump .layer_300D

.chan_3014:
chan_setval 18
chan_jump .chan_301B

.chan_3019:
chan_setval 42
.chan_301B:
chan_writeseq 0, .layer_3046, 1
chan_reservenotes 4
chan_setbank 4
chan_setinstr 2
chan_setenvelope .envelope_309C
chan_setdecayrelease 15
chan_setlayer 0, .layer_303E
chan_setlayer 1, .layer_303A
.chan_3030:
chan_delay1
chan_ioreadval 0
chan_iowriteval 0
chan_subtract 255
chan_beqz .chan_3030
chan_unreservenotes
chan_end

.layer_303A:
layer_setinstr 9
layer_transpose 12

.layer_303E:
layer_note0 50, 0x3, 127, 127
layer_note0 38, 0x3, 127, 127
.layer_3046:
layer_delay 0x2a
layer_jump .layer_303E

# padding
.byte 0

.envelope_304C:
envelope_line 7 20000
envelope_line 6 32700
envelope_line 32700 32700
envelope_goto 2

.envelope_305C:
envelope_line 9 15000
envelope_line 7 32700
envelope_line 32700 32700
envelope_goto 2

.envelope_306C:
envelope_line 10 10000
envelope_line 100 32700
envelope_line 32700 32700
envelope_goto 2

.envelope_307C:
envelope_line 35 32700
envelope_line 10 32700
envelope_line 300 0
envelope_goto 2

.envelope_308C:
envelope_line 15 20000
envelope_line 5 32700
envelope_line 32700 32700
envelope_goto 2

.envelope_309C:
envelope_line 8 32700
envelope_line 50 32700
envelope_line 300 0
envelope_goto 2

.envelope_30AC:
envelope_line 100 25000
envelope_line 35 32700
envelope_line 300 5000
envelope_goto 2

.envelope_30BC:
envelope_line 25 32700
envelope_line 4 22500
envelope_line 35 32700
envelope_goto 2

.envelope_30CC:
envelope_line 1 32700
envelope_line 10 30000
envelope_line 50 30000
envelope_line 100 0
envelope_goto 3

.envelope_30E0:
envelope_line 4 32700
envelope_line 100 15000
envelope_line 1000 0
envelope_goto 2

.envelope_30F0:
envelope_line 10 32700
envelope_line 1 32700
envelope_line 10 0
envelope_goto 2

.envelope_3100:
envelope_line 1 32700
envelope_line 20 32700
envelope_line 600 6000
envelope_goto 2

.envelope_unused_3110:
envelope_line 1 32700
envelope_line 20 32700
envelope_line 100 18000
envelope_goto 2

.envelope_3120:
envelope_line 1 32700
envelope_line 20 32700
envelope_line 300 6000
envelope_goto 2

.envelope_3130:
envelope_line 7 18000
envelope_line 4 32760
envelope_line 30 0
envelope_goto 2

.envelope_3140:
envelope_line 19 32700
envelope_line 5 32700
envelope_line 15 0
envelope_goto 2

.envelope_3150:
envelope_line 25 32700
envelope_line 9 32700
envelope_line 9 0
envelope_goto 2

.envelope_3160:
envelope_line 1 32700
envelope_line 100 32760
envelope_line 300 0
envelope_goto 2

.envelope_3170:
envelope_line 22 32700
envelope_line 50 32760
envelope_line 70 0
envelope_goto 2

.envelope_3180:
envelope_line 5 32760
envelope_line 192 0
envelope_line 1000 1000
envelope_goto 2

.envelope_3190:
envelope_line 25 32760
envelope_line 60 10000
envelope_goto 2

.envelope_319C:
envelope_line 1 10000
envelope_line 1 10000
envelope_line 40 32760
envelope_goto 2

.envelope_31AC:
envelope_line 23 32760
envelope_line 80 15000
envelope_goto 2

.envelope_31B8:
envelope_line 22 32760
envelope_line 50 32760
envelope_line 100 25000
envelope_goto 2

.envelope_31C8:
envelope_line 13 32760
envelope_line 50 32760
envelope_line 200 0
envelope_goto 2

.envelope_31D8:
envelope_line 6 12000
envelope_line 4 32760
envelope_line 50 32760
envelope_line 200 0
envelope_goto 2

.envelope_unused_31EC:
envelope_line 1 32700
envelope_line 1000 32700
envelope_line 10 16000
envelope_line 200 32760
envelope_goto 3
