.include "macros.inc"
.include "geo_commands.inc"

.section .geo, "a"

glabel blue_coin_switch_geo # 0x0F000000
   geo_start_distance 300
      geo_open_node
         geo_open_node
            geo_display_list 0x01, blue_coin_switch_seg8_dl_08000E08
         geo_close_node
      geo_close_node
   geo_end

.word 0x0
.word 0x0

glabel amp_geo # 0x0F000028
   geo_shadow SHADOW_CIRCLE_UNK1, 0xC8, 100
      geo_open_node
         geo_scale 0x00, 16384
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0
            geo_open_node
               geo_dl_translated 0x04, 0, 0, 0, amp_seg8_dl_08002C88
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0
                  geo_open_node
                     geo_switch_case 2, GeoSwitchCase8029DB48
                     geo_open_node
                        geo_dl_translated 0x01, 0, 0, 0
                        geo_dl_translated 0x04, 0, 0, 0, amp_seg8_dl_08002BA0
                     geo_close_node
                  geo_close_node
                  geo_dl_translated 0x01, 0, 0, 0
                  geo_open_node
                     geo_switch_case 2, GeoSwitchCase8029DB48
                     geo_open_node
                        geo_dl_translated 0x01, 0, 0, 0
                        geo_dl_translated 0x04, 0, 0, 0, amp_seg8_dl_08002BA0
                     geo_close_node
                  geo_close_node
                  geo_dl_translated 0x01, 0, 0, 0
                  geo_open_node
                     geo_switch_case 2, GeoSwitchCase8029DB48
                     geo_open_node
                        geo_dl_translated 0x01, 0, 0, 0
                        geo_dl_translated 0x04, 0, 0, 0, amp_seg8_dl_08002BA0
                     geo_close_node
                  geo_close_node
                  geo_dl_translated 0x01, 0, 0, 0
                  geo_open_node
                     geo_switch_case 2, GeoSwitchCase8029DB48
                     geo_open_node
                        geo_dl_translated 0x01, 0, 0, 0
                        geo_dl_translated 0x04, 0, 0, 0, amp_seg8_dl_08002BA0
                     geo_close_node
                  geo_close_node
               geo_close_node
               geo_dl_translated 0x04, 0, 0, 0, amp_seg8_dl_08002D70
               geo_dl_translated 0x01, 0, 0, 0
               geo_open_node
                  geo_billboard
                  geo_open_node
                     geo_display_list 0x04, amp_seg8_dl_08002E58
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_end

.word 0x0
.word 0x0
.word 0x0

glabel cannon_base_geo # 0x0F0001A8
   geo_node_start
      geo_open_node
         geo_display_list 0x01, cannon_base_seg8_dl_080057F8
      geo_close_node
   geo_end

glabel cannon_barrel_geo # 0x0F0001C0
   geo_node_start
      geo_open_node
         geo_display_list 0x01, cannon_barrel_seg8_dl_08006660
      geo_close_node
   geo_end

glabel chuckya_geo # 0x0F0001D8
   geo_shadow SHADOW_CIRCLE_UNK1, 0x96, 100
      geo_open_node
         geo_scale 0x00, 16384
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0
            geo_open_node
               geo_dl_translated 0x01, 0, 0, 0
               geo_open_node
                  geo_dl_translated 0x01, 281, 0, 0
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0
                     geo_open_node
                        geo_dl_translated 0x01, 0, 0, 0, chuckya_seg8_dl_0800ABE8
                        geo_dl_translated 0x01, 113, -152, 0
                        geo_open_node
                           geo_dl_translated 0x01, 0, 0, 0
                           geo_open_node
                              geo_dl_translated 0x01, 74, 0, 0
                              geo_open_node
                                 geo_dl_translated 0x01, 96, 0, 0
                                 geo_open_node
                                    geo_dl_translated 0x01, 0, 0, 0
                                    geo_open_node
                                       geo_billboard
                                       geo_open_node
                                          geo_display_list 0x04, chuckya_seg8_dl_0800A5F8
                                       geo_close_node
                                    geo_close_node
                                 geo_close_node
                              geo_close_node
                              geo_dl_translated 0x01, 0, 0, 0, chuckya_seg8_dl_0800A998
                           geo_close_node
                        geo_close_node
                        geo_dl_translated 0x04, 0, 0, 0, chuckya_seg8_dl_0800A758
                        geo_dl_translated 0x01, 0, 0, 0
                        geo_open_node
                           geo_billboard
                           geo_open_node
                              geo_display_list 0x04, chuckya_seg8_dl_0800A068
                           geo_close_node
                        geo_close_node
                        geo_dl_translated 0x01, 1, 0, 0
                        geo_open_node
                           geo_dl_translated 0x01, 0, 0, 0
                           geo_open_node
                              geo_dl_translated 0x01, 209, 0, 0
                              geo_open_node
                                 geo_dl_translated 0x01, 0, 0, 0
                                 geo_open_node
                                    geo_billboard
                                    geo_open_node
                                       geo_display_list 0x04, chuckya_seg8_dl_0800A1D0
                                    geo_close_node
                                 geo_close_node
                                 geo_dl_translated 0x01, 0, 0, 0
                                 geo_open_node
                                    geo_dl_translated 0x01, 0, 0, 0
                                    geo_open_node
                                       geo_dl_translated 0x01, 95, 0, 0
                                       geo_open_node
                                          geo_dl_translated 0x01, 0, 0, 0
                                          geo_open_node
                                             geo_billboard
                                             geo_open_node
                                                geo_display_list 0x04, chuckya_seg8_dl_0800A428
                                             geo_close_node
                                          geo_close_node
                                       geo_close_node
                                    geo_close_node
                                 geo_close_node
                              geo_close_node
                           geo_close_node
                        geo_close_node
                        geo_dl_translated 0x01, 1, 0, 0
                        geo_open_node
                           geo_dl_translated 0x01, 0, 0, 0
                           geo_open_node
                              geo_dl_translated 0x01, 209, 0, 0
                              geo_open_node
                                 geo_dl_translated 0x01, 0, 0, 0
                                 geo_open_node
                                    geo_billboard
                                    geo_open_node
                                       geo_display_list 0x04, chuckya_seg8_dl_0800A338
                                    geo_close_node
                                 geo_close_node
                                 geo_dl_translated 0x01, 0, 0, 0
                                 geo_open_node
                                    geo_dl_translated 0x01, 0, 0, 0
                                    geo_open_node
                                       geo_dl_translated 0x01, 95, 0, 0
                                       geo_open_node
                                          geo_dl_translated 0x01, 0, 0, 0
                                          geo_open_node
                                             geo_billboard
                                             geo_open_node
                                                geo_display_list 0x04, chuckya_seg8_dl_0800A510
                                             geo_close_node
                                          geo_close_node
                                          geo_asm 0, Geo18_802A719C
                                       geo_close_node
                                    geo_close_node
                                 geo_close_node
                              geo_close_node
                           geo_close_node
                        geo_close_node
                     geo_close_node
                  geo_close_node
                  geo_dl_translated 0x01, 0, 0, 0, chuckya_seg8_dl_0800A8D0
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_end

glabel purple_switch_geo # 0x0F0004CC
   geo_start_distance 300
      geo_open_node
         geo_display_list 0x01, purple_switch_seg8_dl_0800C718
      geo_close_node
   geo_end

glabel checkerboard_platform_geo # 0x0F0004E4
   geo_start_distance 400
      geo_open_node
         geo_display_list 0x01, checkerboard_platform_seg8_dl_0800D680
      geo_close_node
   geo_end

glabel heart_geo # 0x0F0004FC
   geo_shadow SHADOW_CIRCLE_UNK1, 0x64, 100
      geo_open_node
         geo_display_list 0x05, heart_seg8_dl_0800DFE0
      geo_close_node
   geo_end

glabel shyguy_geo # 0x0F000518
   geo_shadow SHADOW_CIRCLE_UNK1, 0x96, 100
      geo_open_node
         geo_scale 0x00, 16384
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0
            geo_open_node
               geo_dl_translated 0x01, 0, 0, 0, shyguy_seg8_dl_08011710
               geo_open_node
                  geo_dl_translated 0x01, -45, -20, -55
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0, shyguy_seg8_dl_08010840
                  geo_close_node
                  geo_dl_translated 0x01, -45, -20, 55
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0, shyguy_seg8_dl_08010968
                  geo_close_node
                  geo_dl_translated 0x01, 250, 0, 0
                  geo_open_node
                     geo_dl_translated 0x05, 0, 0, 0, shyguy_seg8_dl_08010B80
                     geo_dl_translated 0x01, 0, 0, 0
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_end

glabel breakable_box_geo # 0x0F0005D2
   geo_start_distance 500
      geo_open_node
         geo_shadow SHADOW_SQUARE_PERMANENT, 0xB4, 240
            geo_open_node
               geo_switch_case 2, GeoSwitchCase8029DB48
               geo_open_node
                  geo_display_list 0x01, breakable_box_face_seg8_dl_08012D20
                  geo_display_list 0x01, breakable_box_seg8_dl_08012D48
               geo_close_node
            geo_close_node
         geo_close_node
      geo_end

glabel breakable_box2_geo # 0x0F000610
   geo_start_distance 500
      geo_open_node
         geo_switch_case 2, GeoSwitchCase8029DB48
         geo_open_node
            geo_display_list 0x01, breakable_box_face_seg8_dl_08012D20
            geo_display_list 0x01, breakable_box_seg8_dl_08012D48
         geo_close_node
      geo_close_node
   geo_end

glabel bowling_ball_geo # 0x0F000640
   geo_shadow SHADOW_CIRCLE_UNK1, 0xC8, 280
      geo_open_node
         geo_scale 0x00, 170393
         geo_open_node
            geo_display_list 0x04, black_ball_seg8_dl_08022D08
         geo_close_node
      geo_close_node
   geo_end

glabel bowling_ball2_geo # 0x0F00066C
   geo_node_start
      geo_open_node
         geo_scale 0x00, 170393
         geo_open_node
            geo_display_list 0x04, black_ball_seg8_dl_08022D08
         geo_close_node
      geo_close_node
   geo_end

glabel exclamation_box_geo # 0x0F000694
   geo_start_distance 300
      geo_open_node
         geo_shadow SHADOW_SQUARE_PERMANENT, 0xB4, 70
            geo_open_node
               geo_switch_case 4, GeoSwitchCase8029DB48
               geo_open_node
                  geo_display_list 0x01, exclamation_box_seg8_dl_08019318
                  geo_display_list 0x01, exclamation_box_seg8_dl_08019378
                  geo_display_list 0x01, exclamation_box_seg8_dl_080193D8
                  geo_display_list 0x01, exclamation_box_seg8_dl_08019438
               geo_close_node
            geo_close_node
         geo_close_node
      geo_end

glabel goomba_geo # 0x0F0006E4
   geo_shadow SHADOW_CIRCLE_UNK1, 0x96, 100
      geo_open_node
         geo_scale 0x00, 16384
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0, goomba_seg8_dl_0801D760
            geo_open_node
               geo_dl_translated 0x01, 0, 0, 0
               geo_open_node
                  geo_billboard
                  geo_open_node
                     geo_display_list 0x04, goomba_seg8_dl_0801B690
                  geo_close_node
               geo_close_node
               geo_open_node
                  geo_switch_case 2, GeoSwitchCase8029DB48
                  geo_open_node
                     geo_dl_translated 0x01, 48, 0, 0, goomba_seg8_dl_0801B5C8
                     geo_dl_translated 0x01, 48, 0, 0, goomba_seg8_dl_0801B5F0
                  geo_close_node
                  geo_dl_translated 0x01, -60, -16, 45
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0, goomba_seg8_dl_0801CE20
                  geo_close_node
                  geo_dl_translated 0x01, -60, -16, -45
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0, goomba_seg8_dl_0801CF78
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_end

glabel black_bobomb_geo # 0x0F0007B8
   geo_shadow SHADOW_CIRCLE_UNK1, 0xC8, 70
      geo_open_node
         geo_scale 0x00, 24576
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0
            geo_open_node
               geo_dl_translated 0x01, 0, 0, 0
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0
                  geo_open_node
                     geo_billboard
                     geo_open_node
                        geo_display_list 0x04, black_ball_seg8_dl_08022D08
                     geo_close_node
                  geo_close_node
                  geo_dl_translated 0x01, 0, 57, -60
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0
                     geo_open_node
                        geo_dl_translated 0x01, 91, 0, 0
                        geo_open_node
                           geo_dl_translated 0x01, 0, 0, 0, bobomb_seg8_dl_08023270
                        geo_close_node
                     geo_close_node
                  geo_close_node
                  geo_dl_translated 0x01, 0, 55, 62
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0
                     geo_open_node
                        geo_dl_translated 0x01, 91, 0, 0
                        geo_open_node
                           geo_dl_translated 0x01, 0, 0, 0, bobomb_seg8_dl_08023378
                        geo_close_node
                     geo_close_node
                  geo_close_node
                  geo_dl_translated 0x01, 0, 0, 0, bobomb_seg8_dl_08023480
                  geo_switch_case 2, GeoSwitchCase8029DB48
                  geo_open_node
                     geo_dl_translated 0x04, 0, 0, 0, bobomb_seg8_dl_08022B58
                     geo_dl_translated 0x04, 0, 0, 0, bobomb_seg8_dl_08022B88
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_end

glabel pink_bobomb_geo # 0x0F0008F4
   geo_shadow SHADOW_CIRCLE_UNK1, 0xC8, 70
      geo_open_node
         geo_scale 0x00, 24576
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0
            geo_open_node
               geo_dl_translated 0x01, 0, 0, 0
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0
                  geo_open_node
                     geo_billboard
                     geo_open_node
                        geo_display_list 0x04, pink_ball_seg8_dl_08022D78
                     geo_close_node
                  geo_close_node
                  geo_dl_translated 0x01, 0, 57, -60
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0
                     geo_open_node
                        geo_dl_translated 0x01, 91, 0, 0
                        geo_open_node
                           geo_dl_translated 0x01, 0, 0, 0, bobomb_seg8_dl_08023270
                        geo_close_node
                     geo_close_node
                  geo_close_node
                  geo_dl_translated 0x01, 0, 55, 62
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0
                     geo_open_node
                        geo_dl_translated 0x01, 91, 0, 0
                        geo_open_node
                           geo_dl_translated 0x01, 0, 0, 0, bobomb_seg8_dl_08023378
                        geo_close_node
                     geo_close_node
                  geo_close_node
                  geo_dl_translated 0x01, 0, 0, 0, bobomb_seg8_dl_08023480
                  geo_switch_case 2, GeoSwitchCase8029DB48
                  geo_open_node
                     geo_dl_translated 0x04, 0, 0, 0, bobomb_seg8_dl_08022B58
                     geo_dl_translated 0x04, 0, 0, 0, bobomb_seg8_dl_08022B88
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_end

glabel metal_box_geo # 0x0F000A30
   geo_start_distance 500
      geo_open_node
         geo_shadow SHADOW_SQUARE_PERMANENT, 0xB4, 70
            geo_open_node
               geo_display_list 0x01, metal_box_seg8_dl_08024BB8
            geo_close_node
         geo_close_node
      geo_end

glabel exclamation_box_outline_geo # 0x0F000A5A
   geo_start_distance 300
      geo_open_node
         geo_shadow SHADOW_SQUARE_PERMANENT, 0xB4, 70
            geo_open_node
               geo_switch_case 4, GeoSwitchCase8029DB48
               geo_open_node
                  geo_display_list 0x05, exclamation_box_seg8_dl_08024F88
                  geo_display_list 0x05, exclamation_box_seg8_dl_08024FA8
                  geo_display_list 0x05, exclamation_box_seg8_dl_08024FC8
                  geo_display_list 0x05, exclamation_box_seg8_dl_08024FE8
               geo_close_node
               geo_display_list 0x04, exclamation_box_outline_seg8_dl_080259F8
            geo_close_node
         geo_close_node
      geo_end

glabel koopa_shell_geo # 0x0F000AB0
   geo_shadow SHADOW_CIRCLE_UNK1, 0xC8, 70
      geo_open_node
         geo_scale 0x00, 65536
         geo_open_node
            geo_display_list 0x01, koopa_shell_seg8_dl_08028B78
         geo_close_node
      geo_close_node
   geo_end

glabel koopa_shell2_geo # 0x0F000ADC
   geo_shadow SHADOW_CIRCLE_UNK1, 0xC8, 70
      geo_open_node
         geo_scale 0x00, 16384
         geo_open_node
            geo_display_list 0x01, koopa_shell_seg8_dl_08027420
         geo_close_node
      geo_close_node
   geo_end

glabel koopa_shell3_geo # 0x0F000B08
   geo_shadow SHADOW_CIRCLE_UNK1, 0xC8, 70
      geo_open_node
         geo_scale 0x00, 16384
         geo_open_node
            geo_display_list 0x01, koopa_shell_seg8_dl_080273C8
         geo_close_node
      geo_close_node
   geo_end

.word 0x0
.word 0x0
.word 0x0
