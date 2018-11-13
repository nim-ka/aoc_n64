.include "macros.inc"
.include "geo_commands.inc"

.section .geo, "a"

glabel klepto_geo # 0x0C000000
   geo_shadow SHADOW_CIRCLE_UNK1, 0x96, 250
   geo_open_node
      geo_scale 0x00, 65536
      geo_open_node
         geo_dl_translated 0x01, 0, 0, 0
         geo_open_node
            geo_dl_translated 0x04, 0, 0, 0, klepto_seg5_dl_050041E8
            geo_open_node
               geo_dl_translated 0x01, 62, 0, 0, klepto_seg5_dl_05003F20
               geo_open_node
                  geo_dl_translated 0x01, 44, 0, 0, klepto_seg5_dl_05003D80
                  geo_open_node
                     geo_dl_translated 0x01, 58, 0, 0, klepto_seg5_dl_05003BD0
                  geo_close_node
               geo_close_node
               geo_dl_translated 0x01, -3, 17, 17
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, klepto_seg5_dl_05004330
                  geo_open_node
                     geo_dl_translated 0x01, 68, 0, 0, klepto_seg5_dl_050047C8
                     geo_dl_translated 0x01, 0, 0, 0
                     geo_dl_translated 0x01, 0, 0, 0
                     geo_dl_translated 0x01, 0, 0, 0
                     geo_open_node
                        geo_switch_case 4, GeoSwitchCase8029DB48
                        geo_open_node
                           geo_node_start
                           geo_node_start
                           geo_open_node
                              geo_scale 0x00, 16384
                              geo_open_node
                                 geo_asm 0, Geo18_802A45E4
                                 geo_translate_rotate 1, 0, 100, 0, 180, 270, 0, marios_cap_seg3_dl_03022F48
                              geo_close_node
                           geo_close_node
                           geo_node_start
                           geo_open_node
                              geo_scale 0x00, 16384
                              geo_open_node
                                 geo_asm 0, Geo18_802A45E4
                                 geo_translate_rotate 1, 0, 100, 0, 180, 270, 0, star_seg3_dl_0302B870
                                 geo_asm 0, Geo18_802A45E4
                                 geo_translate_rotate 4, 0, 100, 0, 180, 270, 0, star_seg3_dl_0302BA18
                              geo_close_node
                           geo_close_node
                           geo_node_start
                           geo_open_node
                              geo_scale 0x00, 16384
                              geo_open_node
                                 geo_asm 0, Geo18_802A45E4
                                 geo_translate_rotate 1, 0, 100, 0, 180, 270, 0, transparent_star_seg3_dl_0302C620
                              geo_close_node
                           geo_close_node
                        geo_close_node
                     geo_close_node
                  geo_close_node
               geo_close_node
               geo_dl_translated 0x01, -3, 17, -17
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, klepto_seg5_dl_05004438
                  geo_open_node
                     geo_dl_translated 0x01, 68, 0, 0, klepto_seg5_dl_05004B58
                     geo_dl_translated 0x01, 0, 0, 0
                     geo_dl_translated 0x01, 0, 0, 0
                     geo_dl_translated 0x01, 0, 0, 0
                  geo_close_node
               geo_close_node
               geo_dl_translated 0x01, 49, -9, -17
               geo_open_node
                  geo_dl_translated 0x04, 0, 0, 0, klepto_seg5_dl_05004D38
                  geo_open_node
                     geo_dl_translated 0x04, 34, 0, 0, klepto_seg5_dl_05004F58
                     geo_open_node
                        geo_dl_translated 0x04, 79, 0, 0, klepto_seg5_dl_05005178
                     geo_close_node
                  geo_close_node
               geo_close_node
               geo_dl_translated 0x01, 49, -9, 17
               geo_open_node
                  geo_dl_translated 0x04, 0, 0, 0, klepto_seg5_dl_05004C28
                  geo_open_node
                     geo_dl_translated 0x04, 34, 0, 0, klepto_seg5_dl_05004E48
                     geo_open_node
                        geo_dl_translated 0x04, 79, 0, 0, klepto_seg5_dl_05005068
                     geo_close_node
                  geo_close_node
               geo_close_node
            geo_close_node
            geo_dl_translated 0x01, 0, 0, 0, klepto_seg5_dl_05004118
         geo_close_node
      geo_close_node
   geo_close_node
   geo_end

glabel eyerok_geo_0002AC # 0x0C0002AC
   geo_dl_translated 0x01, 0, 0, 0
   geo_open_node
      geo_dl_translated 0x01, 0, 0, 0
      geo_open_node
         geo_dl_translated 0x01, 447, 0, 0
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0, eyerok_seg5_dl_0500C640
            geo_dl_translated 0x01, 281, 5, -419
            geo_open_node
               geo_dl_translated 0x01, 0, 0, 0
               geo_open_node
                  geo_dl_translated 0x01, 400, 0, 0
                  geo_open_node
                     geo_dl_translated 0x01, 401, 0, 0
                     geo_open_node
                        geo_dl_translated 0x01, 0, 0, 0, eyerok_seg5_dl_0500BF00
                     geo_close_node
                     geo_dl_translated 0x01, 0, 0, 0, eyerok_seg5_dl_0500C100
                  geo_close_node
                  geo_dl_translated 0x01, 0, 0, 0, eyerok_seg5_dl_0500C378
               geo_close_node
            geo_close_node
            geo_dl_translated 0x01, 281, 5, -218
            geo_open_node
               geo_dl_translated 0x01, 0, 0, 0
               geo_open_node
                  geo_dl_translated 0x01, 400, 0, 0
                  geo_open_node
                     geo_dl_translated 0x01, 401, 0, 0
                     geo_open_node
                        geo_dl_translated 0x01, 0, 0, 0, eyerok_seg5_dl_0500BF00
                     geo_close_node
                     geo_dl_translated 0x01, 0, 0, 0, eyerok_seg5_dl_0500C100
                  geo_close_node
                  geo_dl_translated 0x01, 0, 0, 0, eyerok_seg5_dl_0500C378
               geo_close_node
            geo_close_node
            geo_dl_translated 0x01, 281, 5, -18
            geo_open_node
               geo_dl_translated 0x01, 0, 0, 0
               geo_open_node
                  geo_dl_translated 0x01, 400, 0, 0
                  geo_open_node
                     geo_dl_translated 0x01, 401, 0, 0
                     geo_open_node
                        geo_dl_translated 0x01, 0, 0, 0, eyerok_seg5_dl_0500BF00
                     geo_close_node
                     geo_dl_translated 0x01, 0, 0, 0, eyerok_seg5_dl_0500C100
                  geo_close_node
                  geo_dl_translated 0x01, 0, 0, 0, eyerok_seg5_dl_0500C378
               geo_close_node
            geo_close_node
            geo_dl_translated 0x01, 281, 5, 180
            geo_open_node
               geo_dl_translated 0x01, 0, 0, 0
               geo_open_node
                  geo_dl_translated 0x01, 400, 0, 0
                  geo_open_node
                     geo_dl_translated 0x01, 401, 0, 0
                     geo_open_node
                        geo_dl_translated 0x01, 0, 0, 0, eyerok_seg5_dl_0500BF00
                     geo_close_node
                     geo_dl_translated 0x01, 0, 0, 0, eyerok_seg5_dl_0500C100
                  geo_close_node
                  geo_dl_translated 0x01, 0, 0, 0, eyerok_seg5_dl_0500C378
               geo_close_node
            geo_close_node
         geo_close_node
         geo_dl_translated 0x01, 0, 0, 0, eyerok_seg5_dl_0500C908
         geo_open_node
            geo_switch_case 4, GeoSwitchCase8029DB48
            geo_open_node
               geo_display_list 0x04, eyerok_seg5_dl_0500C9B8
               geo_display_list 0x04, eyerok_seg5_dl_0500CA50
               geo_display_list 0x04, eyerok_seg5_dl_0500CAE8
               geo_display_list 0x04, eyerok_seg5_dl_0500CB80
            geo_close_node
         geo_close_node
         geo_dl_translated 0x01, 181, 89, 80
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0
            geo_open_node
               geo_dl_translated 0x01, 199, 0, 0
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, eyerok_seg5_dl_0500BC88
                  geo_dl_translated 0x01, 200, 199, 199
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0
                     geo_open_node
                        geo_dl_translated 0x01, 336, 0, 0
                        geo_open_node
                           geo_dl_translated 0x01, 0, 0, 0, eyerok_seg5_dl_0500B748
                        geo_close_node
                        geo_dl_translated 0x01, 0, 0, 0, eyerok_seg5_dl_0500B9C0
                     geo_close_node
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
   geo_return

glabel eyerok_geo # 0x0C0005A8
   geo_shadow SHADOW_SQUARE_SCALABLE, 0xB4, 300
   geo_open_node
      geo_scale 0x00, 16384
      geo_open_node
         geo_display_list 0x01, eyerok_seg5_dl_0500CC18
         geo_branch 1, eyerok_geo_0002AC
         geo_display_list 0x01, eyerok_seg5_dl_0500CC30
      geo_close_node
   geo_close_node
   geo_end

glabel eyerok2_geo # 0x0C0005E4
   geo_shadow SHADOW_SQUARE_SCALABLE, 0xB4, 300
   geo_open_node
      geo_scale 0x00, 16384
      geo_open_node
         geo_branch 1, eyerok_geo_0002AC
      geo_close_node
   geo_close_node
   geo_end

glabel pokey_head_geo # 0x0C000610
   geo_shadow SHADOW_CIRCLE_UNK1, 0x96, 50
   geo_open_node
      geo_switch_case 2, GeoSwitchCase8029DB48
      geo_open_node
         geo_display_list 0x04, pokey_seg5_dl_050127D8
         geo_display_list 0x04, pokey_seg5_dl_05012808
      geo_close_node
   geo_close_node
   geo_end

glabel pokey_body_part_geo # 0x0C000644
   geo_shadow SHADOW_CIRCLE_UNK1, 0x96, 50
   geo_open_node
      geo_display_list 0x04, pokey_seg5_dl_050130B0
   geo_close_node
   geo_end
