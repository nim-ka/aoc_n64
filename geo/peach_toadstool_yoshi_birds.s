.include "macros.inc"
.include "geo_commands.inc"

.section .geo, "a"

glabel peach_X_geo_000000 # 0x0C000000
   geo_shadow SHADOW_CIRCLE_UNK1, 0x96, 100
      geo_open_node
         geo_scale 0x00, 16384
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0
            geo_open_node
               geo_dl_translated 0x01, 0, 0, 0, peach_X_seg5_dl_05000670
               geo_open_node
                  geo_dl_translated 0x01, 1, -12, 37
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0, peach_X_seg5_dl_05000528
                  geo_close_node
                  geo_dl_translated 0x01, 1, -12, -37
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0, peach_X_seg5_dl_05000600
                  geo_close_node
               geo_close_node
               geo_dl_translated 0x01, 0, 0, 0, peach_X_seg5_dl_05000598
            geo_close_node
         geo_close_node
      geo_close_node
   geo_end

glabel peach_X_geo_000098 # 0x0C000098
   geo_node_start
   geo_open_node
      geo_dl_translated 0x01, 0, 0, 0
      geo_open_node
         geo_dl_translated 0x01, 0, 0, 0, peach_X_seg5_dl_05007230
         geo_open_node
            geo_dl_translated 0x01, 78, 0, 0, peach_X_seg5_dl_05006A18
            geo_open_node
               geo_dl_translated 0x01, 132, 0, 0
               geo_open_node
                  geo_switch_case 8, GeoSwitchCase80257198
                  geo_open_node
                     geo_display_list 0x01, peach_X_seg5_dl_05005CE0
                     geo_display_list 0x01, peach_X_seg5_dl_05005D38
                     geo_display_list 0x01, peach_X_seg5_dl_05005D90
                     geo_display_list 0x01, peach_X_seg5_dl_05005DE8
                     geo_display_list 0x01, peach_X_seg5_dl_05005E40
                     geo_display_list 0x01, peach_X_seg5_dl_05005E98
                     geo_display_list 0x01, peach_X_seg5_dl_05005EF0
                     geo_display_list 0x01, peach_X_seg5_dl_05005F48
                  geo_close_node
                  geo_dl_translated 0x01, 38, -78, 0
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0, peach_X_seg5_dl_05007AB8
                  geo_close_node
               geo_close_node
               geo_dl_translated 0x01, 132, 0, 0, peach_X_seg5_dl_05009148
               geo_dl_translated 0x01, 132, 0, 0, peach_X_seg5_dl_05008F20
               geo_dl_translated 0x01, 63, 0, 84
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, peach_X_seg5_dl_05007E58
                  geo_open_node
                     geo_dl_translated 0x01, 104, 0, 0, peach_X_seg5_dl_050087A8
                     geo_open_node
                        geo_dl_translated 0x01, 87, 0, 0, peach_X_seg5_dl_05009500
                     geo_close_node
                  geo_close_node
                  geo_dl_translated 0x01, 0, 0, 0, peach_X_seg5_dl_05008560
               geo_close_node
               geo_dl_translated 0x01, 63, 0, -84
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, peach_X_seg5_dl_05008228
                  geo_open_node
                     geo_dl_translated 0x01, 104, 0, 0, peach_X_seg5_dl_05008CF8
                     geo_open_node
                        geo_dl_translated 0x01, 87, 0, 0, peach_X_seg5_dl_05009940
                     geo_close_node
                  geo_close_node
                  geo_dl_translated 0x01, 0, 0, 0, peach_X_seg5_dl_05008AB0
               geo_close_node
            geo_close_node
            geo_dl_translated 0x01, 78, 0, 0, peach_X_seg5_dl_050060E0
            geo_dl_translated 0x01, -23, -1, 0
            geo_open_node
               geo_dl_translated 0x01, 0, 0, 0, peach_X_seg5_dl_0500A0A8
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
geo_return

glabel peach_X_geo_000254 # 0x0C000254
   geo_node_start
   geo_open_node
      geo_dl_translated 0x05, 0, 0, 0
      geo_open_node
         geo_dl_translated 0x05, 0, 0, 0, peach_X_seg5_dl_05007230
         geo_open_node
            geo_dl_translated 0x05, 78, 0, 0, peach_X_seg5_dl_05006A18
            geo_open_node
               geo_dl_translated 0x05, 132, 0, 0
               geo_open_node
                  geo_switch_case 8, GeoSwitchCase80257198
                  geo_open_node
                     geo_display_list 0x05, peach_X_seg5_dl_05005CE0
                     geo_display_list 0x05, peach_X_seg5_dl_05005D38
                     geo_display_list 0x05, peach_X_seg5_dl_05005D90
                     geo_display_list 0x05, peach_X_seg5_dl_05005DE8
                     geo_display_list 0x05, peach_X_seg5_dl_05005E40
                     geo_display_list 0x05, peach_X_seg5_dl_05005E98
                     geo_display_list 0x05, peach_X_seg5_dl_05005EF0
                     geo_display_list 0x05, peach_X_seg5_dl_05005F48
                  geo_close_node
                  geo_dl_translated 0x05, 38, -78, 0
                  geo_open_node
                     geo_dl_translated 0x05, 0, 0, 0, peach_X_seg5_dl_05007AB8
                  geo_close_node
               geo_close_node
               geo_dl_translated 0x05, 132, 0, 0, peach_X_seg5_dl_05009148
               geo_dl_translated 0x05, 132, 0, 0, peach_X_seg5_dl_05008F20
               geo_dl_translated 0x05, 63, 0, 84
               geo_open_node
                  geo_dl_translated 0x05, 0, 0, 0, peach_X_seg5_dl_05007E58
                  geo_open_node
                     geo_dl_translated 0x05, 104, 0, 0, peach_X_seg5_dl_050087A8
                     geo_open_node
                        geo_dl_translated 0x05, 87, 0, 0, peach_X_seg5_dl_05009500
                     geo_close_node
                  geo_close_node
                  geo_dl_translated 0x05, 0, 0, 0, peach_X_seg5_dl_05008560
               geo_close_node
               geo_dl_translated 0x05, 63, 0, -84
               geo_open_node
                  geo_dl_translated 0x05, 0, 0, 0, peach_X_seg5_dl_05008228
                  geo_open_node
                     geo_dl_translated 0x05, 104, 0, 0, peach_X_seg5_dl_05008CF8
                     geo_open_node
                        geo_dl_translated 0x05, 87, 0, 0, peach_X_seg5_dl_05009940
                     geo_close_node
                  geo_close_node
                  geo_dl_translated 0x05, 0, 0, 0, peach_X_seg5_dl_05008AB0
               geo_close_node
            geo_close_node
            geo_dl_translated 0x05, 78, 0, 0, peach_X_seg5_dl_050060E0
            geo_dl_translated 0x05, -23, -1, 0
            geo_open_node
               geo_dl_translated 0x05, 0, 0, 0, peach_X_seg5_dl_0500A0A8
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
geo_return

geo_shadow SHADOW_CIRCLE_UNK0, 0x96, 100
   geo_open_node
      geo_scale 0x00, 16384
      geo_open_node
         geo_asm 10, Geo18_8029D924
         geo_switch_case 2, GeoSwitchCase8029DB48
         geo_open_node
            geo_branch 1, peach_X_geo_000098
            geo_branch 1, peach_X_geo_000254
         geo_close_node
      geo_close_node
   geo_close_node
geo_end

.word 0x0
.word 0x0
.word 0x0

glabel peach_X_geo_000468 # 0x0C000468
   geo_shadow SHADOW_CIRCLE_UNK1, 0xC8, 100
      geo_open_node
         geo_scale 0x00, 16384
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0
            geo_open_node
               geo_dl_translated 0x01, 0, 0, 0, peach_X_seg5_dl_05022608
               geo_open_node
                  geo_dl_translated 0x01, 100, 0, 0, peach_X_seg5_dl_05022408
                  geo_open_node
                     geo_dl_translated 0x01, 222, 0, 0
                     geo_open_node
                        geo_switch_case 2, GeoSwitchCase8029DB48
                        geo_open_node
                           geo_display_list 0x01, peach_X_seg5_dl_0501D970
                           geo_display_list 0x01, peach_X_seg5_dl_0501D998
                        geo_close_node
                     geo_close_node
                     geo_open_node
                        geo_dl_translated 0x01, 76, 49, 0
                        geo_open_node
                           geo_dl_translated 0x01, 0, 0, 0, peach_X_seg5_dl_050212B0
                        geo_close_node
                     geo_close_node
                     geo_dl_translated 0x01, 51, 55, 97
                     geo_open_node
                        geo_dl_translated 0x01, 0, 0, 0, peach_X_seg5_dl_05021678
                        geo_open_node
                           geo_dl_translated 0x01, 74, 0, 0, peach_X_seg5_dl_050215D8
                           geo_open_node
                              geo_dl_translated 0x01, 69, 0, 0, peach_X_seg5_dl_05021490
                           geo_close_node
                        geo_close_node
                     geo_close_node
                     geo_dl_translated 0x01, 51, 55, -97
                     geo_open_node
                        geo_dl_translated 0x01, 0, 0, 0, peach_X_seg5_dl_05021900
                        geo_open_node
                           geo_dl_translated 0x01, 74, 0, 0, peach_X_seg5_dl_05021860
                           geo_open_node
                              geo_dl_translated 0x01, 69, 0, 0, peach_X_seg5_dl_05021718
                           geo_close_node
                        geo_close_node
                     geo_close_node
                  geo_close_node
                  geo_dl_translated 0x01, -1, 27, 95
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0, peach_X_seg5_dl_05021CD8
                     geo_open_node
                        geo_dl_translated 0x01, 100, 0, 0, peach_X_seg5_dl_05021B90
                        geo_open_node
                           geo_dl_translated 0x01, 95, 0, 0, peach_X_seg5_dl_050219A0
                        geo_close_node
                     geo_close_node
                  geo_close_node
                  geo_dl_translated 0x01, -89, -62, 0
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0, peach_X_seg5_dl_05021E38
                  geo_close_node
                  geo_dl_translated 0x01, -1, 27, -95
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0, peach_X_seg5_dl_050222A8
                     geo_open_node
                        geo_dl_translated 0x01, 100, 0, 0, peach_X_seg5_dl_05022160
                        geo_open_node
                           geo_dl_translated 0x01, 95, 0, 0, peach_X_seg5_dl_05021F70
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
