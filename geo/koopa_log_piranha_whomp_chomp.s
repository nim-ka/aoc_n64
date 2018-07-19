.include "macros.inc"
.include "geo_commands.inc"

.section .geo, "a"

glabel koopa_flag_geo # 0x0D000000
   geo_node_start
      geo_open_node
         geo_scale 0x00, 16384
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0
            geo_open_node
               geo_dl_translated 0x01, 0, 0, 0, koopa_flag_seg6_dl_06000A08
               geo_open_node
                  geo_dl_translated 0x01, 2040, 0, 0
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0, koopa_flag_seg6_dl_06000B08
                     geo_open_node
                        geo_dl_translated 0x01, 460, 0, 0, koopa_flag_seg6_dl_06000BF8
                        geo_open_node
                           geo_dl_translated 0x01, 460, 0, 0, koopa_flag_seg6_dl_06000CE0
                           geo_open_node
                              geo_dl_translated 0x01, 344, 0, 0, koopa_flag_seg6_dl_06000DB0
                              geo_open_node
                                 geo_dl_translated 0x01, 288, 0, 0, koopa_flag_seg6_dl_06000E38
                              geo_close_node
                           geo_close_node
                        geo_close_node
                     geo_close_node
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_end

glabel poundable_wooden_log # 0x0D0000B8
   geo_start_distance 450
      geo_open_node
         geo_display_list 0x01, poundable_wooden_log_seg6_dl_06002410
      geo_close_node
   geo_end

glabel koopa_geo # 0x0D0000D0
   geo_shadow SHADOW_CIRCLE_UNK1, 0x9B, 100
      geo_open_node
         geo_scale 0x00, 16384
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0
            geo_open_node
               geo_dl_translated 0x01, 0, 0, 0, koopa_seg6_dl_0600C498
               geo_open_node
                  geo_switch_case 2, GeoSwitchCase8029DB48
                  geo_open_node
                     geo_dl_translated 0x01, 114, 0, 0, koopa_seg6_dl_06007AF8
                     geo_dl_translated 0x01, 114, 0, 0, koopa_seg6_dl_06007B20
                  geo_close_node
                  geo_dl_translated 0x01, -29, 39, 60
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0, koopa_seg6_dl_0600B838
                     geo_open_node
                        geo_dl_translated 0x01, 60, 0, 0, koopa_seg6_dl_060086D0
                     geo_close_node
                  geo_close_node
                  geo_dl_translated 0x01, -29, 39, -60
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0, koopa_seg6_dl_0600BA10
                     geo_open_node
                        geo_dl_translated 0x01, 60, 0, 0, koopa_seg6_dl_06008B50
                     geo_close_node
                  geo_close_node
                  geo_dl_translated 0x01, 55, 25, -73
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0, koopa_seg6_dl_0600BC18
                     geo_open_node
                        geo_dl_translated 0x01, 54, 0, 0, koopa_seg6_dl_0600BA90
                     geo_close_node
                  geo_close_node
                  geo_dl_translated 0x01, 55, 25, 74
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0, koopa_seg6_dl_0600BE10
                     geo_open_node
                        geo_dl_translated 0x01, 54, 0, 0, koopa_seg6_dl_0600BC88
                     geo_close_node
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_end

glabel koopa2_geo # 0x0D000214
   geo_shadow SHADOW_CIRCLE_UNK1, 0x9B, 100
      geo_open_node
         geo_scale 0x00, 16384
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0
            geo_open_node
               geo_dl_translated 0x01, 0, 0, 0, koopa_seg6_dl_06008250
               geo_open_node
                  geo_switch_case 2, GeoSwitchCase8029DB48
                  geo_open_node
                     geo_dl_translated 0x01, 114, 0, 0, koopa_seg6_dl_06007AF8
                     geo_dl_translated 0x01, 114, 0, 0, koopa_seg6_dl_06007B20
                  geo_close_node
                  geo_dl_translated 0x01, -29, 39, 60
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0, koopa_seg6_dl_0600B838
                     geo_open_node
                        geo_dl_translated 0x01, 60, 0, 0, koopa_seg6_dl_060086D0
                     geo_close_node
                  geo_close_node
                  geo_dl_translated 0x01, -29, 39, -60
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0, koopa_seg6_dl_0600BA10
                     geo_open_node
                        geo_dl_translated 0x01, 60, 0, 0, koopa_seg6_dl_06008B50
                     geo_close_node
                  geo_close_node
                  geo_dl_translated 0x01, 55, 25, -73
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0, koopa_seg6_dl_0600BC18
                     geo_open_node
                        geo_dl_translated 0x01, 54, 0, 0, koopa_seg6_dl_0600BA90
                     geo_close_node
                  geo_close_node
                  geo_dl_translated 0x01, 55, 25, 74
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0, koopa_seg6_dl_0600BE10
                     geo_open_node
                        geo_dl_translated 0x01, 54, 0, 0, koopa_seg6_dl_0600BC88
                     geo_close_node
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_end

glabel piranha_plant_geo # 0x0D000358
   geo_shadow SHADOW_CIRCLE_UNK1, 0x9B, 200
      geo_open_node
         geo_scale 0x00, 16384
         geo_open_node
            geo_dl_translated 0x01, 0, 14, 3
            geo_open_node
               geo_dl_translated 0x01, 0, 0, 0, piranha_plant_seg6_dl_06015850
               geo_open_node
                  geo_dl_translated 0x01, 46, 0, 0, piranha_plant_seg6_dl_06016F20
                  geo_open_node
                     geo_dl_translated 0x01, 154, 0, 0, piranha_plant_seg6_dl_06016D98
                     geo_open_node
                        geo_dl_translated 0x01, 153, 0, 0, piranha_plant_seg6_dl_06016C10
                        geo_open_node
                           geo_dl_translated 0x01, 236, 42, 0
                           geo_open_node
                              geo_dl_translated 0x01, 0, 0, 0, piranha_plant_seg6_dl_060160B0
                              geo_open_node
                                 geo_display_list 0x04, piranha_plant_seg6_dl_06016120
                              geo_close_node
                           geo_close_node
                           geo_dl_translated 0x01, 217, -2, 0
                           geo_open_node
                              geo_dl_translated 0x01, 0, 0, 0, piranha_plant_seg6_dl_060169E8
                              geo_open_node
                                 geo_display_list 0x04, piranha_plant_seg6_dl_06016A78
                              geo_close_node
                           geo_close_node
                        geo_close_node
                     geo_close_node
                     geo_dl_translated 0x01, 49, 0, -34
                     geo_open_node
                        geo_dl_translated 0x04, 0, 0, 0, piranha_plant_seg6_dl_06015480
                     geo_close_node
                     geo_dl_translated 0x01, 49, 0, 37
                     geo_open_node
                        geo_dl_translated 0x04, 0, 0, 0, piranha_plant_seg6_dl_06015578
                     geo_close_node
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_end

glabel whomp_geo # 0x0D000480
   geo_start_distance 2000
      geo_open_node
         geo_todo_11 0x00, 0, 0, -50
         geo_open_node
            geo_shadow 0x01 + SHADOW_RECTANGLE_HARDCODED_OFFSET, 0xB4, 0
               geo_open_node
                  geo_scale 0x00, 16384
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0
                     geo_open_node
                        geo_dl_translated 0x01, 0, 0, 0, whomp_seg6_dl_0601F5E0
                        geo_open_node
                           geo_dl_translated 0x01, -12, 490, -5
                           geo_open_node
                              geo_dl_translated 0x01, 0, 0, 0, whomp_seg6_dl_0601FEA8
                           geo_close_node
                           geo_dl_translated 0x01, -18, -479, -5
                           geo_open_node
                              geo_dl_translated 0x01, 0, 0, 0, whomp_seg6_dl_06020038
                           geo_close_node
                           geo_dl_translated 0x01, 1075, 570, 0
                           geo_open_node
                              geo_dl_translated 0x01, 0, 0, 0, whomp_seg6_dl_0601F880
                              geo_open_node
                                 geo_dl_translated 0x04, 400, 0, 0
                                 geo_open_node
                                    geo_billboard
                                    geo_open_node
                                       geo_display_list 0x04, whomp_seg6_dl_0601FBC0
                                    geo_close_node
                                 geo_close_node
                              geo_close_node
                           geo_close_node
                           geo_dl_translated 0x01, 1068, -574, 0
                           geo_open_node
                              geo_dl_translated 0x01, 0, 0, 0, whomp_seg6_dl_0601FAE8
                              geo_open_node
                                 geo_dl_translated 0x04, 400, 0, 0
                                 geo_open_node
                                    geo_billboard
                                    geo_open_node
                                       geo_display_list 0x04, whomp_seg6_dl_0601FCA8
                                    geo_close_node
                                 geo_close_node
                              geo_close_node
                           geo_close_node
                        geo_close_node
                     geo_close_node
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
      geo_end

glabel metallic_ball_geo # 0x0D0005D0
   geo_shadow SHADOW_CIRCLE_UNK1, 0x96, 60
      geo_open_node
         geo_display_list 0x04, metallic_ball_seg6_dl_060212E8
      geo_close_node
   geo_end

glabel chain_chomp # 0x0D0005EC
   geo_shadow SHADOW_CIRCLE_UNK1, 0x96, 200
      geo_open_node
         geo_scale 0x00, 16384
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0
            geo_open_node
               geo_dl_translated 0x01, 0, 0, 0, chain_chomp_seg6_dl_06024940
               geo_dl_translated 0x01, 0, 0, 0, chain_chomp_seg6_dl_06024FC0
            geo_close_node
            geo_dl_translated 0x01, 0, 0, 0
            geo_open_node
               geo_dl_translated 0x01, 0, 0, 0, chain_chomp_seg6_dl_06024240
               geo_dl_translated 0x01, 0, 0, 0, chain_chomp_seg6_dl_06024D60
               geo_dl_translated 0x04, 0, 0, 0, chain_chomp_seg6_dl_06024B00
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
geo_end

.word 0x0
.word 0x0
