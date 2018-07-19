.include "macros.inc"
.include "geo_commands.inc"

.section .geo, "a"

glabel monty_mole_geo # 0x0C000000
   geo_node_start
   geo_open_node
      geo_scale 0x00, 16384
      geo_open_node
         geo_dl_translated 0x01, 0, 0, 0
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0, monty_mole_seg5_dl_050044B0
            geo_open_node
               geo_dl_translated 0x01, 116, 0, 0, monty_mole_seg5_dl_05004C00
               geo_dl_translated 0x04, 116, 0, 0, monty_mole_seg5_dl_05004D30
               geo_dl_translated 0x01, -68, -5, -40
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, monty_mole_seg5_dl_05003C48
               geo_close_node
               geo_dl_translated 0x01, -68, -5, 40
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, monty_mole_seg5_dl_05003518
               geo_close_node
               geo_dl_translated 0x01, 80, 1, 78
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, monty_mole_seg5_dl_050032A0
                  geo_open_node
                     geo_dl_translated 0x01, 80, 0, 0, monty_mole_seg5_dl_05003820
                  geo_close_node
               geo_close_node
               geo_dl_translated 0x01, 80, 1, -78
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, monty_mole_seg5_dl_050039D0
                  geo_open_node
                     geo_dl_translated 0x01, 80, 0, 0, monty_mole_seg5_dl_05003F50
                     geo_asm 0, Geo18_8029D890
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
geo_end

glabel ukiki_geo # 0x0C000110
   geo_shadow SHADOW_CIRCLE_UNK1, 0x96, 80
      geo_open_node
         geo_scale 0x00, 16384
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0, ukiki_seg5_dl_0500B820
            geo_open_node
               geo_dl_translated 0x01, 0, 99, -11
               geo_open_node
                  geo_switch_case 4, GeoSwitchCase8029DB48
                  geo_open_node
                     geo_node_start
                     geo_open_node
                        geo_dl_translated 0x01, 0, 0, 0, ukiki_seg5_dl_0500B2E8
                     geo_close_node
                     geo_node_start
                     geo_open_node
                        geo_dl_translated 0x01, 0, 0, 0, ukiki_seg5_dl_0500B310
                     geo_close_node
                     geo_node_start
                     geo_open_node
                        geo_dl_translated 0x01, 0, 0, 0, ukiki_seg5_dl_0500B2E8
                        geo_open_node
                           geo_translate_rotate 1, 100, 0, 0, -90, -90, 0, marios_cap_seg3_dl_03022F48
                        geo_close_node
                     geo_close_node
                     geo_node_start
                     geo_open_node
                        geo_dl_translated 0x01, 0, 0, 0, ukiki_seg5_dl_0500B310
                        geo_open_node
                           geo_translate_rotate 1, 100, 0, 0, -90, -90, 0, marios_cap_seg3_dl_03022F48
                        geo_close_node
                     geo_close_node
                  geo_close_node
               geo_close_node
               geo_dl_translated 0x01, 71, 69, -9
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, ukiki_seg5_dl_0500B988
                  geo_open_node
                     geo_dl_translated 0x01, 86, 0, 0, ukiki_seg5_dl_0500BB28
                     geo_open_node
                        geo_dl_translated 0x01, 64, 0, 0, ukiki_seg5_dl_0500CF68
                     geo_close_node
                  geo_close_node
               geo_close_node
               geo_dl_translated 0x01, -71, 68, -9
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, ukiki_seg5_dl_0500BC78
                  geo_open_node
                     geo_dl_translated 0x01, 86, 0, 0, ukiki_seg5_dl_0500BE38
                     geo_open_node
                        geo_dl_translated 0x01, 64, 0, 0, ukiki_seg5_dl_0500CFF0
                     geo_close_node
                  geo_close_node
               geo_close_node
               geo_dl_translated 0x01, 43, -22, -1
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, ukiki_seg5_dl_0500BFF8
                  geo_open_node
                     geo_dl_translated 0x01, 46, 0, 0, ukiki_seg5_dl_0500C1B8
                     geo_open_node
                        geo_dl_translated 0x01, 36, 0, 0, ukiki_seg5_dl_0500D078
                     geo_close_node
                  geo_close_node
               geo_close_node
               geo_dl_translated 0x01, -43, -22, -1
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, ukiki_seg5_dl_0500C368
                  geo_open_node
                     geo_dl_translated 0x01, 46, 0, 0, ukiki_seg5_dl_0500C528
                     geo_open_node
                        geo_dl_translated 0x01, 36, 0, 0, ukiki_seg5_dl_0500D108
                     geo_close_node
                  geo_close_node
               geo_close_node
               geo_dl_translated 0x01, 0, -15, -57
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, ukiki_seg5_dl_0500C6E8
                  geo_open_node
                     geo_dl_translated 0x01, 45, 0, 0, ukiki_seg5_dl_0500C898
                     geo_open_node
                        geo_dl_translated 0x01, 46, 0, 0, ukiki_seg5_dl_0500CA48
                     geo_close_node
                  geo_close_node
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_end

glabel fwoosh_geo # 0x0C00036C
   geo_start_distance 200
      geo_open_node
         geo_display_list 0x05, fwoosh_seg5_dl_05016040
      geo_close_node
   geo_end

.word 0x0
.word 0x0
.word 0x0
