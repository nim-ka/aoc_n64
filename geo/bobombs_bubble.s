.include "macros.inc"
.include "geo_commands.inc"

.section .geo, "a"

glabel bobombs_X_geo_000000 # 0x0C000000
   geo_shadow SHADOW_CIRCLE_UNK1, 0x96, 300
      geo_open_node
         geo_scale 0x00, 16384
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0
            geo_open_node
               geo_dl_translated 0x01, 0, 0, 0
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0
                  geo_open_node
                     geo_billboard
                     geo_open_node
                        geo_display_list 0x04, bobombs_X_seg5_dl_0500B188
                     geo_close_node
                  geo_close_node
                  geo_dl_translated 0x01, 0, -243, 0
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0
                     geo_open_node
                        geo_dl_translated 0x01, 488, 0, 0
                        geo_open_node
                           geo_dl_translated 0x01, 110, 0, 0
                           geo_open_node
                              geo_dl_translated 0x01, 0, 0, 0, bobombs_X_seg5_dl_0500AD08
                           geo_close_node
                           geo_dl_translated 0x01, 0, 0, 0
                           geo_open_node
                              geo_billboard
                              geo_open_node
                                 geo_display_list 0x04, bobombs_X_seg5_dl_0500A5D8
                              geo_close_node
                           geo_close_node
                        geo_close_node
                     geo_close_node
                  geo_close_node
                  geo_dl_translated 0x04, 0, 0, 0, bobombs_X_seg5_dl_0500B2D0
                  geo_dl_translated 0x01, 0, 0, 0, bobombs_X_seg5_dl_0500B418
                  geo_dl_translated 0x01, 0, 0, 0, bobombs_X_seg5_dl_0500B6C0
                  geo_dl_translated 0x01, 0, 243, 0
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0
                     geo_open_node
                        geo_dl_translated 0x01, 488, 0, 0
                        geo_open_node
                           geo_dl_translated 0x01, 110, 0, 0
                           geo_open_node
                              geo_dl_translated 0x01, 0, 0, 0, bobombs_X_seg5_dl_0500B068
                           geo_close_node
                           geo_dl_translated 0x01, 0, 0, 0
                           geo_open_node
                              geo_billboard
                              geo_open_node
                                 geo_display_list 0x04, bobombs_X_seg5_dl_0500A890
                              geo_close_node
                           geo_close_node
                        geo_close_node
                     geo_close_node
                  geo_close_node
                  geo_dl_translated 0x01, 0, -1, 36
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0
                     geo_open_node
                        geo_dl_translated 0x01, 548, 0, 0
                        geo_open_node
                           geo_dl_translated 0x01, 0, 0, 0
                           geo_open_node
                              geo_billboard
                              geo_open_node
                                 geo_display_list 0x04, bobombs_X_seg5_dl_0500A4F0
                              geo_close_node
                           geo_close_node
                           geo_dl_translated 0x01, 189, 0, 0
                           geo_open_node
                              geo_dl_translated 0x01, 0, 0, 0
                              geo_open_node
                                 geo_billboard
                                 geo_open_node
                                    geo_display_list 0x04, bobombs_X_seg5_dl_0500A6C0
                                 geo_close_node
                              geo_close_node
                              geo_asm 0, Geo18_802A719C
                           geo_close_node
                        geo_close_node
                     geo_close_node
                  geo_close_node
                  geo_dl_translated 0x01, 0, 1, 36
                  geo_open_node
                     geo_dl_translated 0x01, 0, 0, 0
                     geo_open_node
                        geo_dl_translated 0x01, 548, 0, 0
                        geo_open_node
                           geo_dl_translated 0x01, 0, 0, 0
                           geo_open_node
                              geo_billboard
                              geo_open_node
                                 geo_display_list 0x04, bobombs_X_seg5_dl_0500A7A8
                              geo_close_node
                           geo_close_node
                           geo_dl_translated 0x01, 189, 0, 0
                           geo_open_node
                              geo_dl_translated 0x01, 0, 0, 0
                              geo_open_node
                                 geo_billboard
                                 geo_open_node
                                    geo_display_list 0x04, bobombs_X_seg5_dl_0500A978
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
   geo_close_node
geo_end

glabel bobombs_X_geo_000308 # 0x0C000308
   geo_start_distance 150
      geo_open_node
         geo_open_node
            geo_display_list 0x05, bobombs_X_seg5_dl_05011000
         geo_close_node
      geo_close_node
   geo_end

glabel bobombs_X_geo_000328 # 0x0C000328
   geo_start_distance 150
      geo_open_node
         geo_shadow SHADOW_CIRCLE_UNK1, 0x64, 160
         geo_close_node
      geo_end
