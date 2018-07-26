.include "macros.inc"
.include "geo_commands.inc"

.section .geo, "a"

glabel clam_shell_geo # 0x0C000000
   geo_node_start
   geo_open_node
      geo_scale 0x00, 16384
      geo_open_node
         geo_dl_translated 0x01, 0, 0, 0
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0, clam_shell_seg5_dl_05001568
            geo_open_node
               geo_dl_translated 0x01, -520, -6, 0
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, clam_shell_seg5_dl_050012B8
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
   geo_end

glabel sushi_geo # 0x0C000068
   geo_start_distance 800
   geo_open_node
      geo_scale 0x00, 16384
      geo_open_node
         geo_dl_translated 0x01, 0, 0, 0
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0, sushi_seg5_dl_0500A768
            geo_open_node
               geo_asm 0, Geo18_802B798C
            geo_close_node
            geo_open_node
               geo_dl_translated 0x01, 201, 0, 0, sushi_seg5_dl_05009DD0
               geo_open_node
                  geo_dl_translated 0x01, 415, 0, 0, sushi_seg5_dl_0500A008
                  geo_open_node
                     geo_dl_translated 0x01, 486, 0, 0, sushi_seg5_dl_0500A160
                  geo_close_node
               geo_close_node
            geo_close_node
            geo_dl_translated 0x04, 0, 0, 0, sushi_seg5_dl_0500A990
            geo_dl_translated 0x04, 0, 0, 0, sushi_seg5_dl_0500A8A8
         geo_close_node
      geo_close_node
   geo_close_node
   geo_end

glabel unagi_geo # 0x0C00010C
   geo_start_distance 2000
   geo_open_node
      geo_scale 0x00, 16384
      geo_open_node
         geo_dl_translated 0x01, 0, 0, 0
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0, unagi_seg5_dl_0500D268
            geo_open_node
               geo_dl_translated 0x01, 245, 0, 0, unagi_seg5_dl_0500D468
               geo_open_node
                  geo_dl_translated 0x01, 494, 0, 0, unagi_seg5_dl_0500D668
                  geo_open_node
                     geo_dl_translated 0x01, 475, 0, 0, unagi_seg5_dl_0500D828
                     geo_open_node
                        geo_switch_case 2, GeoSwitchCase8029DB48
                        geo_open_node
                           geo_node_start
                           geo_node_start
                           geo_open_node
                              geo_scale 0x00, 16384
                              geo_open_node
                                 geo_translate_rotate 1, 2000, 0, 0, 0, 0, 0, star_seg3_dl_0302B870
                                 geo_translate_rotate 4, 2000, 0, 0, 0, 0, 0, star_seg3_dl_0302BA18
                              geo_close_node
                           geo_close_node
                        geo_close_node
                     geo_close_node
                  geo_close_node
               geo_close_node
               geo_dl_translated 0x01, -254, 0, 0
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, unagi_seg5_dl_0500D050
                  geo_open_node
                     geo_dl_translated 0x04, 527, 0, 0, unagi_seg5_dl_0500DEB8
                     geo_open_node
                        geo_dl_translated 0x01, 226, 65, 0
                        geo_open_node
                           geo_dl_translated 0x04, 0, 0, 0, unagi_seg5_dl_0500E258
                           geo_dl_translated 0x01, 0, 0, 0, unagi_seg5_dl_0500CDD0
                           geo_dl_translated 0x01, 0, 0, 0
                        geo_close_node
                     geo_close_node
                     geo_dl_translated 0x04, 527, 0, 0, unagi_seg5_dl_0500E088
                     geo_dl_translated 0x01, 527, 0, 0, unagi_seg5_dl_0500DD08
                     geo_dl_translated 0x01, 527, 0, 0
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
   geo_end
