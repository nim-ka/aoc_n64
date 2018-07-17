.include "macros.inc"
.include "geo_commands.inc"

.section .geo, "a"

glabel bubba_X_geo_000000 # 0x0C000000
   geo_node_start
      geo_open_node
         geo_switch_case 2, GeoSwitchCase8029DB48
         geo_open_node
            geo_display_list 0x01, bubba_X_seg5_dl_05004E80
            geo_display_list 0x01, bubba_X_seg5_dl_05005978
         geo_close_node
      geo_close_node
   geo_end

glabel bubba_X_geo_000030 # 0x0C000030
   geo_shadow SHADOW_CIRCLE_UNK1, 0x96, 100
      geo_open_node
         geo_scale 0x00, 16384
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0
            geo_open_node
               geo_dl_translated 0x01, 0, 0, 0
               geo_open_node
                  geo_billboard
                  geo_open_node
                     geo_display_list 0x04, bubba_X_seg5_dl_0500C278
                  geo_close_node
               geo_close_node
               geo_open_node
                  geo_dl_translated 0x01, 157, 0, 0
                  geo_open_node
                     geo_billboard
                     geo_open_node
                        geo_display_list 0x04, bubba_X_seg5_dl_0500E678
                     geo_close_node
                  geo_close_node
                  geo_open_node
                     geo_dl_translated 0x01, 143, 0, 0
                     geo_open_node
                        geo_billboard
                        geo_open_node
                           geo_display_list 0x04, bubba_X_seg5_dl_0500E1D8
                        geo_close_node
                     geo_close_node
                     geo_dl_translated 0x01, 143, 0, 0
                  geo_close_node
                  geo_dl_translated 0x04, 157, 0, 0, bubba_X_seg5_dl_0500E518
                  geo_dl_translated 0x04, 157, 0, 0, bubba_X_seg5_dl_0500E430
                  geo_dl_translated 0x04, 157, 0, 0, bubba_X_seg5_dl_0500E2F8
                  geo_dl_translated 0x01, -16, 23, 51
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0, bubba_X_seg5_dl_0500DDF8
                     geo_open_node
                        geo_dl_translated 0x01, 39, 0, 0, bubba_X_seg5_dl_0500DD70
                        geo_open_node
                           geo_dl_translated 0x01, 41, 0, 0, bubba_X_seg5_dl_0500DC18
                        geo_close_node
                     geo_close_node
                  geo_close_node
                  geo_dl_translated 0x01, -16, 23, -49
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0, bubba_X_seg5_dl_0500E060
                     geo_open_node
                        geo_dl_translated 0x01, 39, 0, 0, bubba_X_seg5_dl_0500DFD8
                        geo_open_node
                           geo_dl_translated 0x01, 41, 0, 0, bubba_X_seg5_dl_0500DE80
                        geo_close_node
                     geo_close_node
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_end

glabel bubba_X_geo_0001BC # 0x0C0001BC
   geo_shadow SHADOW_CIRCLE_UNK1, 0x96, 100
      geo_open_node
         geo_scale 0x00, 16384
         geo_open_node
            geo_dl_translated 0x01, 0, 63, -62, bubba_X_seg5_dl_050138B0
            geo_open_node
               geo_dl_translated 0x01, 0, 0, 0, bubba_X_seg5_dl_05012910
               geo_open_node
                  geo_dl_translated 0x01, 132, 0, 0, bubba_X_seg5_dl_05013160
                  geo_open_node
                     geo_switch_case 2, GeoSwitchCase8029DB48
                     geo_open_node
                        geo_display_list 0x04, bubba_X_seg5_dl_05013350
                        geo_display_list 0x04, bubba_X_seg5_dl_05013378
                     geo_close_node
                  geo_close_node
                  geo_dl_translated 0x01, 87, 18, 72
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0, bubba_X_seg5_dl_050136A0
                  geo_close_node
                  geo_dl_translated 0x01, 87, 18, -72
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0, bubba_X_seg5_dl_050134A8
                     geo_asm 0, Geo18_8029D890
                     geo_dl_translated 0x01, 0, 0, 0
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_end

glabel bubba_X_geo_000290 # 0x0C000290
   geo_shadow SHADOW_CIRCLE_UNK1, 0x96, 100
      geo_open_node
         geo_scale 0x00, 16384
         geo_open_node
            geo_dl_translated 0x01, -18, -34, 10, bubba_X_seg5_dl_05015368
            geo_open_node
               geo_dl_translated 0x01, 0, 0, 0, bubba_X_seg5_dl_05015330
               geo_dl_translated 0x01, 0, 0, 0, bubba_X_seg5_dl_050152F8
               geo_dl_translated 0x01, 0, 0, 0, bubba_X_seg5_dl_050152C0
               geo_dl_translated 0x01, 0, 0, 0, bubba_X_seg5_dl_05015288
               geo_dl_translated 0x01, 0, 0, 0, bubba_X_seg5_dl_05015250
               geo_dl_translated 0x01, 0, 0, 0, bubba_X_seg5_dl_05015218
               geo_dl_translated 0x01, 0, 0, 0, bubba_X_seg5_dl_050151E0
               geo_dl_translated 0x01, 0, 0, 0, bubba_X_seg5_dl_050151A8
            geo_close_node
         geo_close_node
      geo_close_node
   geo_end

glabel bubba_X_geo_000328 # 0x0C000328
   geo_shadow SHADOW_CIRCLE_UNK1, 0x96, 100
      geo_open_node
         geo_scale 0x00, 16384
         geo_open_node
            geo_dl_translated 0x01, 0, 72, -7, bubba_X_seg5_dl_05016A48
            geo_open_node
               geo_dl_translated 0x01, 0, 0, 0
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, bubba_X_seg5_dl_05016738
                  geo_dl_translated 0x01, -1, 55, 0
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0
                     geo_open_node
                        geo_dl_translated 0x01, 77, 0, 0
                        geo_open_node
                           geo_dl_translated 0x01, 0, 0, 0, bubba_X_seg5_dl_05016418
                        geo_close_node
                     geo_close_node
                  geo_close_node
                  geo_dl_translated 0x01, 0, -48, 0
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0
                     geo_open_node
                        geo_dl_translated 0x01, 88, 0, 0
                        geo_open_node
                           geo_dl_translated 0x01, 0, 0, 0, bubba_X_seg5_dl_050164E0
                        geo_close_node
                     geo_close_node
                  geo_close_node
                  geo_dl_translated 0x01, -1, 55, 0
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0
                     geo_open_node
                        geo_dl_translated 0x01, 77, 0, 0
                        geo_open_node
                           geo_dl_translated 0x01, 0, 0, 0, bubba_X_seg5_dl_050165A8
                        geo_close_node
                     geo_close_node
                  geo_close_node
                  geo_dl_translated 0x01, 0, -48, 0
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0
                     geo_open_node
                        geo_dl_translated 0x01, 88, 0, 0
                        geo_open_node
                           geo_dl_translated 0x01, 0, 0, 0, bubba_X_seg5_dl_05016670
                        geo_close_node
                     geo_close_node
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_end
