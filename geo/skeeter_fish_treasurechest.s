.include "macros.inc"
.include "geo_commands.inc"

.section .geo, "a"

glabel skeeter_geo # 0x0D000000
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
                  geo_display_list 0x04, skeeter_seg6_dl_06000A08
               geo_close_node
            geo_close_node
            geo_open_node
               geo_dl_translated 0x01, 100, -75, -105
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, skeeter_seg6_dl_06004070
                  geo_open_node
                     geo_dl_translated 0x01, 405, 0, 0, skeeter_seg6_dl_06004040
                     geo_open_node
                        geo_dl_translated 0x01, 540, 0, 0, skeeter_seg6_dl_06000EC0
                     geo_close_node
                  geo_close_node
               geo_close_node
               geo_dl_translated 0x01, -40, -75, -125
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, skeeter_seg6_dl_06004120
                  geo_open_node
                     geo_dl_translated 0x01, 405, 0, 0, skeeter_seg6_dl_060040F0
                     geo_open_node
                        geo_dl_translated 0x01, 540, 0, 0, skeeter_seg6_dl_06000EC0
                     geo_close_node
                  geo_close_node
               geo_close_node
               geo_dl_translated 0x01, -40, -75, 125
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, skeeter_seg6_dl_060041D0
                  geo_open_node
                     geo_dl_translated 0x01, 405, 0, 0, skeeter_seg6_dl_060041A0
                     geo_open_node
                        geo_dl_translated 0x01, 540, 0, 0, skeeter_seg6_dl_06000EC0
                     geo_close_node
                  geo_close_node
               geo_close_node
               geo_dl_translated 0x01, -150, -87, 111
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0
                  geo_open_node
                     geo_billboard
                     geo_open_node
                        geo_display_list 0x04, skeeter_seg6_dl_06000BD8
                     geo_close_node
                  geo_close_node
                  geo_dl_translated 0x04, 0, 0, 0, skeeter_seg6_dl_06000CA8
               geo_close_node
               geo_dl_translated 0x01, -150, -87, -111
               geo_open_node
                  geo_dl_translated 0x04, 0, 0, 0, skeeter_seg6_dl_06000D78
                  geo_dl_translated 0x01, 0, 0, 0
                  geo_open_node
                     geo_billboard
                     geo_open_node
                        geo_display_list 0x04, skeeter_seg6_dl_06000BD8
                     geo_close_node
                  geo_close_node
               geo_close_node
               geo_dl_translated 0x01, 100, -75, 95
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, skeeter_seg6_dl_06004648
                  geo_open_node
                     geo_dl_translated 0x01, 405, 0, 0, skeeter_seg6_dl_06004618
                     geo_open_node
                        geo_dl_translated 0x01, 540, 0, 0, skeeter_seg6_dl_06000EC0
                     geo_close_node
                  geo_close_node
               geo_close_node
               geo_dl_translated 0x01, 147, 84, 0
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, skeeter_seg6_dl_06005328
                  geo_open_node
                     geo_dl_translated 0x01, 216, 0, 0
                     geo_open_node
                        geo_billboard
                        geo_open_node
                           geo_display_list 0x04, skeeter_seg6_dl_06000AF0
                        geo_close_node
                     geo_close_node
                     geo_dl_translated 0x01, 216, 0, 0
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
   geo_end

glabel seaweed_geo # 0x0D000284
   geo_scale 0x00, 16384
   geo_open_node
      geo_dl_translated 0x01, 0, 0, 0
      geo_open_node
         geo_dl_translated 0x04, 0, 0, 0, seaweed_seg6_dl_0600A180
         geo_open_node
            geo_dl_translated 0x04, 238, 0, 0, seaweed_seg6_dl_0600A088
            geo_open_node
               geo_dl_translated 0x04, 317, 0, 0, seaweed_seg6_dl_06009F90
               geo_open_node
                  geo_dl_translated 0x04, 314, 0, 0, seaweed_seg6_dl_06009E98
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
   geo_end

glabel water_mine_geo # 0x0D0002F4
   geo_node_start
   geo_open_node
      geo_display_list 0x01, water_mine_seg6_dl_0600D3F8
      geo_billboard
      geo_open_node
         geo_display_list 0x04, water_mine_seg6_dl_0600D268
      geo_close_node
   geo_close_node
   geo_end

glabel fish3_geo # 0x0D000324
   geo_scale 0x00, 16384
   geo_open_node
      geo_dl_translated 0x01, 0, 0, 0
      geo_open_node
         geo_dl_translated 0x01, 0, 0, 0, fish3_seg6_dl_0600DDD8
         geo_open_node
            geo_dl_translated 0x01, 160, 0, 0, fish3_seg6_dl_0600E038
            geo_dl_translated 0x01, 32, 112, 0
            geo_open_node
               geo_dl_translated 0x01, 0, 0, 0, fish3_seg6_dl_0600DED8
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
   geo_end

glabel chirp_chirp_geo # 0x0D00038C
   geo_scale 0x00, 16384
   geo_open_node
      geo_dl_translated 0x01, -13, 0, 0
      geo_open_node
         geo_dl_translated 0x01, 0, 0, 0, chirp_chirp_seg6_dl_06011B28
         geo_open_node
            geo_dl_translated 0x01, 135, 0, 0, chirp_chirp_seg6_dl_06011CF0
            geo_dl_translated 0x01, -33, -86, -35
            geo_open_node
               geo_dl_translated 0x01, 0, 0, 0, chirp_chirp_seg6_dl_06011E48
            geo_close_node
            geo_dl_translated 0x01, -34, 71, -36
            geo_open_node
               geo_dl_translated 0x01, 0, 0, 0, chirp_chirp_seg6_dl_06011FA0
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
   geo_end

glabel manta_ring_geo # 0x0D000414
   geo_scale 0x00, 32768
   geo_open_node
      geo_dl_translated 0x01, 0, 0, 0
      geo_open_node
         geo_asm 0, Geo18_8029D924
         geo_dl_translated 0x05, 0, 0, 0, manta_ring_seg6_dl_06013AC0
      geo_close_node
   geo_close_node
   geo_end

glabel treasure_chest_bottom_geo # 0x0D000450
   geo_node_start
   geo_open_node
      geo_display_list 0x01, treasure_chest_bottom_seg6_dl_06016F90
   geo_close_node
   geo_end

glabel treasure_chest_lid_geo # 0x0D000468
   geo_node_start
   geo_open_node
      geo_display_list 0x01, treasure_chest_lid_seg6_dl_060178C0
   geo_close_node
   geo_end
