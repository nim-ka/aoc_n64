.include "macros.inc"
.include "geo_commands.inc"

.section .geo, "a"

glabel spindrift_X_geo_000000 # 0x0C000000
   geo_shadow SHADOW_CIRCLE_UNK1, 0x96, 100
      geo_open_node
         geo_scale 0x00, 32768
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0
            geo_open_node
               geo_dl_translated 0x04, 0, 0, 0, spindrift_X_seg5_dl_05002900
               geo_open_node
                  geo_dl_translated 0x01, 100, 0, 0, spindrift_X_seg5_dl_05000328
                  geo_dl_translated 0x04, 100, 0, 0, spindrift_X_seg5_dl_05002A20
                  geo_dl_translated 0x04, 100, 0, 0, spindrift_X_seg5_dl_05002B30
                  geo_dl_translated 0x01, -88, -32, 0
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0, spindrift_X_seg5_dl_050002A0
                     geo_dl_translated 0x04, 0, 0, 0, spindrift_X_seg5_dl_05002D08
                     geo_dl_translated 0x01, 0, 0, 0
                     geo_dl_translated 0x01, 0, 0, 0
                     geo_dl_translated 0x01, 0, 0, 0
                     geo_dl_translated 0x01, 0, 0, 0
                  geo_close_node
               geo_close_node
               geo_dl_translated 0x01, 0, 0, 0
               geo_open_node
                  geo_billboard
                  geo_open_node
                     geo_display_list 0x04, spindrift_X_seg5_dl_05002748
                  geo_close_node
               geo_close_node
               geo_dl_translated 0x04, 0, 0, 0, spindrift_X_seg5_dl_05002830
            geo_close_node
         geo_close_node
      geo_close_node
   geo_end

glabel spindrift_X_geo_000104 # 0x0C000104
   geo_shadow SHADOW_CIRCLE_UNK1, 0x96, 100
      geo_open_node
         geo_scale 0x00, 16384
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 40, spindrift_X_seg5_dl_05007540
            geo_open_node
               geo_dl_translated 0x01, -51, 84, -13
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, spindrift_X_seg5_dl_05007198
               geo_close_node
               geo_dl_translated 0x01, 51, 84, -13
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, spindrift_X_seg5_dl_050071E8
               geo_close_node
               geo_dl_translated 0x01, -38, -54, -13
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, spindrift_X_seg5_dl_05007238
               geo_close_node
               geo_dl_translated 0x01, 38, -54, -13
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, spindrift_X_seg5_dl_050072C8
               geo_close_node
               geo_dl_translated 0x01, 0, 111, -19
               geo_open_node
                  geo_switch_case 5, GeoSwitchCase802BFBAC
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0, spindrift_X_seg5_dl_05006428
                     geo_dl_translated 0x01, 0, 0, 0, spindrift_X_seg5_dl_05006458
                     geo_dl_translated 0x01, 0, 0, 0, spindrift_X_seg5_dl_05006488
                     geo_dl_translated 0x01, 0, 0, 0, spindrift_X_seg5_dl_050064B8
                     geo_dl_translated 0x01, 0, 0, 0, spindrift_X_seg5_dl_050064E8
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_end

glabel spindrift_X_geo_00021C # 0x0C00021C
   geo_scale 0x00, 16384
   geo_open_node
      geo_dl_translated 0x01, 0, 0, 0
      geo_open_node
         geo_dl_translated 0x01, 0, 0, 0
         geo_open_node
            geo_billboard
            geo_open_node
               geo_display_list 0x04, spindrift_X_seg5_dl_0500C620
            geo_close_node
         geo_close_node
         geo_open_node
            geo_dl_translated 0x01, 356, 0, 0
            geo_open_node
               geo_billboard
               geo_open_node
                  geo_display_list 0x04, spindrift_X_seg5_dl_0500CBF8
               geo_close_node
            geo_close_node
            geo_dl_translated 0x04, 356, 0, 0, spindrift_X_seg5_dl_0500CCE8
            geo_dl_translated 0x04, 356, 0, 0, spindrift_X_seg5_dl_0500C760
            geo_switch_case 2, GeoSwitchCase8029DB48
            geo_open_node
               geo_node_start
               geo_node_start
               geo_open_node
                  geo_scale 0x00, 65536
                  geo_open_node
                     geo_translate_rotate 1, 490, 14, 43, 305, 0, 248, coins_X_seg3_dl_03022F48
                  geo_close_node
               geo_close_node
            geo_close_node
            geo_dl_translated 0x01, 89, 0, -229
            geo_open_node
               geo_dl_translated 0x01, 0, 0, 0, spindrift_X_seg5_dl_0500C500
               geo_open_node
                  geo_dl_translated 0x01, 68, 0, 0, spindrift_X_seg5_dl_0500CAA8
                  geo_asm 0, Geo18_8029D890
               geo_close_node
            geo_close_node
            geo_dl_translated 0x01, 356, 0, 0
         geo_close_node
      geo_close_node
   geo_close_node
geo_end

glabel spindrift_X_geo_000348 # 0x0C000348
   geo_shadow SHADOW_CIRCLE_UNK1, 0xB4, 160
      geo_open_node
         geo_branch_and_link spindrift_X_geo_00021C
      geo_close_node
   geo_end

.word 0x0
.word 0x0
.word 0x0
