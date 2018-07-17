.include "macros.inc"
.include "geo_commands.inc"

.section .geo, "a"

glabel lakitu_X_geo_000000 # 0x0D000000
   geo_shadow SHADOW_CIRCLE_UNK1, 0x96, 100
      geo_open_node
         geo_scale 0x00, 16384
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0
            geo_open_node
               geo_dl_translated 0x01, 0, 0, 0, lakitu_X_seg6_dl_06003E30
               geo_open_node
                  geo_dl_translated 0x01, 132, 0, 0, lakitu_X_seg6_dl_06004680
                  geo_open_node
                     geo_switch_case 2, GeoSwitchCase8029DB48
                     geo_open_node
                        geo_display_list 0x04, lakitu_X_seg6_dl_06004C60
                        geo_display_list 0x04, lakitu_X_seg6_dl_06004C88
                     geo_close_node
                  geo_close_node
                  geo_dl_translated 0x01, 87, 18, 72
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0, lakitu_X_seg6_dl_060047E8
                  geo_close_node
                  geo_dl_translated 0x01, 87, 18, -72
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0, lakitu_X_seg6_dl_060049E0
                     geo_open_node
                        geo_dl_translated 0x01, 334, -214, -50
                        geo_open_node
                           geo_dl_translated 0x01, 0, 0, 0, lakitu_X_seg6_dl_06005610
                           geo_open_node
                              geo_dl_translated 0x01, 191, 0, 0, lakitu_X_seg6_dl_06005360
                           geo_close_node
                           geo_dl_translated 0x01, 0, 0, 0, lakitu_X_seg6_dl_060055E8
                        geo_close_node
                     geo_close_node
                     geo_dl_translated 0x01, 0, 0, 0, lakitu_X_seg6_dl_06005598
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_end

glabel lakitu_X_geo_000114 # 0x0D000114
   geo_node_start
   geo_open_node
      geo_dl_translated 0x01, 0, 0, 0
      geo_open_node
         geo_dl_translated 0x01, 0, 0, 0
         geo_open_node
            geo_dl_translated 0x01, 83, 0, 0
            geo_open_node
               geo_dl_translated 0x01, 126, -37, 0, lakitu_X_seg6_dl_06007710
            geo_close_node
            geo_dl_translated 0x01, 25, 8, 0, lakitu_X_seg6_dl_06007A48
            geo_dl_translated 0x01, 34, 8, 0, lakitu_X_seg6_dl_06007EB0
            geo_dl_translated 0x01, 4, 7, 38
            geo_open_node
               geo_dl_translated 0x01, 0, 0, 0
               geo_open_node
                  geo_dl_translated 0x01, 37, 0, 0
                  geo_open_node
                     geo_dl_translated 0x01, 9, -25, 3, lakitu_X_seg6_dl_06008890
                  geo_close_node
               geo_close_node
            geo_close_node
            geo_dl_translated 0x01, 4, 7, -38
            geo_open_node
               geo_dl_translated 0x01, 0, 0, 0
               geo_open_node
                  geo_dl_translated 0x01, 37, 0, 0
                  geo_open_node
                     geo_dl_translated 0x01, 9, -25, -3, lakitu_X_seg6_dl_06008BD8
                  geo_close_node
               geo_close_node
            geo_close_node
            geo_dl_translated 0x01, 61, -3, 52
            geo_open_node
               geo_dl_translated 0x01, 0, 0, 0
               geo_open_node
                  geo_dl_translated 0x01, 17, 0, 4, lakitu_X_seg6_dl_060081F8
               geo_close_node
            geo_close_node
            geo_dl_translated 0x01, 61, -3, -52
            geo_open_node
               geo_dl_translated 0x01, 0, 0, 0
               geo_open_node
                  geo_dl_translated 0x01, 17, 0, -4, lakitu_X_seg6_dl_06008520
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
geo_return

glabel lakitu_X_geo_00027C # 0x0D00027C
   geo_node_start
   geo_open_node
      geo_dl_translated 0x05, 0, 0, 0
      geo_open_node
         geo_dl_translated 0x05, 0, 0, 0
         geo_open_node
            geo_dl_translated 0x05, 83, 0, 0
            geo_open_node
               geo_dl_translated 0x05, 126, -37, 0, lakitu_X_seg6_dl_06007710
            geo_close_node
            geo_dl_translated 0x05, 25, 8, 0, lakitu_X_seg6_dl_06007A48
            geo_dl_translated 0x05, 34, 8, 0, lakitu_X_seg6_dl_06007EB0
            geo_dl_translated 0x05, 4, 7, 38
            geo_open_node
               geo_dl_translated 0x05, 0, 0, 0
               geo_open_node
                  geo_dl_translated 0x05, 37, 0, 0
                  geo_open_node
                     geo_dl_translated 0x05, 9, -25, 3, lakitu_X_seg6_dl_06008890
                  geo_close_node
               geo_close_node
            geo_close_node
            geo_dl_translated 0x05, 4, 7, -38
            geo_open_node
               geo_dl_translated 0x05, 0, 0, 0
               geo_open_node
                  geo_dl_translated 0x05, 37, 0, 0
                  geo_open_node
                     geo_dl_translated 0x05, 9, -25, -3, lakitu_X_seg6_dl_06008BD8
                  geo_close_node
               geo_close_node
            geo_close_node
            geo_dl_translated 0x05, 61, -3, 52
            geo_open_node
               geo_dl_translated 0x05, 0, 0, 0
               geo_open_node
                  geo_dl_translated 0x05, 17, 0, 4, lakitu_X_seg6_dl_060081F8
               geo_close_node
            geo_close_node
            geo_dl_translated 0x05, 61, -3, -52
            geo_open_node
               geo_dl_translated 0x05, 0, 0, 0
               geo_open_node
                  geo_dl_translated 0x05, 17, 0, -4, lakitu_X_seg6_dl_06008520
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
geo_return

glabel lakitu_X_geo_0003E4 # 0x0D0003E4
   geo_start_distance 1000
   geo_open_node
      geo_shadow SHADOW_CIRCLE_UNK0, 0x96, 100
         geo_open_node
            geo_scale 0x00, 16384
            geo_open_node
               geo_asm 10, Geo18_8029D924
               geo_switch_case 2, GeoSwitchCase8029DB48
               geo_open_node
                  geo_branch 1, lakitu_X_geo_000114
                  geo_branch 1, lakitu_X_geo_00027C
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_end

.word 0x0
.word 0x0
.word 0x0

glabel lakitu_X_geo_000448 # 0x0D000448
   geo_shadow SHADOW_CIRCLE_UNK1, 0x96, 100
      geo_open_node
         geo_scale 0x00, 16384
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0
            geo_open_node
               geo_dl_translated 0x01, 0, 0, 0, lakitu_X_seg6_dl_06010C40
               geo_open_node
                  geo_dl_translated 0x01, 64, 0, 0, lakitu_X_seg6_dl_060107B8
                  geo_open_node
                     geo_dl_translated 0x01, 52, -24, -32
                     geo_open_node
                        geo_dl_translated 0x01, 0, 0, 0, lakitu_X_seg6_dl_06011DB0
                        geo_open_node
                           geo_dl_translated 0x01, 79, 0, 0, lakitu_X_seg6_dl_06011BB0
                        geo_close_node
                     geo_close_node
                     geo_dl_translated 0x01, 52, -24, 32
                     geo_open_node
                        geo_dl_translated 0x01, 0, 0, 0, lakitu_X_seg6_dl_060110B0
                        geo_open_node
                           geo_dl_translated 0x01, 79, 0, 0, lakitu_X_seg6_dl_06010E60
                        geo_close_node
                     geo_close_node
                  geo_close_node
                  geo_dl_translated 0x01, -31, 4, -39
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0, lakitu_X_seg6_dl_06011FC0
                     geo_open_node
                        geo_dl_translated 0x01, 45, 0, 0, lakitu_X_seg6_dl_06011990
                        geo_open_node
                           geo_dl_translated 0x01, 52, 0, 0, lakitu_X_seg6_dl_06011780
                        geo_close_node
                     geo_close_node
                  geo_close_node
                  geo_dl_translated 0x01, -31, 4, 40
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0, lakitu_X_seg6_dl_06011ED8
                     geo_open_node
                        geo_dl_translated 0x01, 45, 0, 0, lakitu_X_seg6_dl_06011520
                        geo_open_node
                           geo_dl_translated 0x01, 52, 0, 0, lakitu_X_seg6_dl_06011310
                        geo_close_node
                     geo_close_node
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
geo_end

.word 0x0
.word 0x0
.word 0x0

glabel lakitu_X_geo_0005B0 # 0x0D0005B0
   geo_shadow SHADOW_CIRCLE_UNK1, 0x96, 70
      geo_open_node
         geo_scale 0x00, 26214
         geo_open_node
            geo_asm 0, Geo18_8029D924
            geo_switch_case 2, GeoSwitchCase8029DB48
            geo_open_node
               geo_display_list 0x01, lakitu_X_seg6_dl_06017CE0
               geo_display_list 0x05, lakitu_X_seg6_dl_06017CE0
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
geo_end
