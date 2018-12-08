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
