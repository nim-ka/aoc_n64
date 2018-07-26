.include "macros.inc"
.include "geo_commands.inc"

.section .geo, "a"

glabel yellow_sphere_geo # 0x0C000000
   geo_node_start
   geo_open_node
      geo_display_list 0x04, yellow_sphere_seg5_dl_050008C8
   geo_close_node
   geo_end

glabel hoot_geo # 0x0C000018
   geo_shadow SHADOW_CIRCLE_UNK1, 0xFF, 100
   geo_open_node
      geo_scale 0x00, 16384
      geo_open_node
         geo_dl_translated 0x01, 0, 147, -5
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0, hoot_seg5_dl_05004D48
            geo_open_node
               geo_dl_translated 0x01, 96, 0, 0, hoot_seg5_dl_05001DF0
               geo_dl_translated 0x01, 34, -35, 31
               geo_open_node
                  geo_dl_translated 0x04, 0, 0, 0, hoot_seg5_dl_05003728
                  geo_open_node
                     geo_dl_translated 0x04, 91, 0, 0, hoot_seg5_dl_050034D8
                     geo_open_node
                        geo_dl_translated 0x04, 121, 0, 0, hoot_seg5_dl_050033B0
                        geo_dl_translated 0x01, 121, 0, 0
                     geo_close_node
                     geo_dl_translated 0x01, 91, 0, 0
                  geo_close_node
                  geo_dl_translated 0x04, 0, 0, 0, hoot_seg5_dl_05003600
                  geo_dl_translated 0x01, 0, 0, 0
                  geo_dl_translated 0x01, 0, 0, 0
               geo_close_node
               geo_dl_translated 0x01, -31, 5, 37
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, hoot_seg5_dl_05004A98
                  geo_open_node
                     geo_dl_translated 0x01, 42, 0, 0, hoot_seg5_dl_05004928
                  geo_close_node
               geo_close_node
               geo_dl_translated 0x01, -31, 5, -37
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, hoot_seg5_dl_05004CA8
                  geo_open_node
                     geo_dl_translated 0x01, 42, 0, 0, hoot_seg5_dl_05004B38
                  geo_close_node
               geo_close_node
               geo_dl_translated 0x01, 34, -35, -31
               geo_open_node
                  geo_dl_translated 0x04, 0, 0, 0, hoot_seg5_dl_05003288
                  geo_open_node
                     geo_dl_translated 0x04, 91, 0, 0, hoot_seg5_dl_05003038
                     geo_open_node
                        geo_dl_translated 0x04, 121, 0, 0, hoot_seg5_dl_05002F10
                        geo_dl_translated 0x01, 121, 0, 0
                     geo_close_node
                     geo_dl_translated 0x01, 91, 0, 0
                  geo_close_node
                  geo_dl_translated 0x04, 0, 0, 0, hoot_seg5_dl_05003160
                  geo_dl_translated 0x01, 0, 0, 0
                  geo_dl_translated 0x01, 0, 0, 0
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
geo_close_node #! more close than open nodes
geo_end

glabel yoshi_egg_geo # 0x0C0001E4
   geo_scale 0x00, 16384
   geo_open_node
      geo_switch_case 8, GeoSwitchCase8029DB48
      geo_open_node
         geo_display_list 0x04, yoshi_egg_seg5_dl_050098C8
         geo_display_list 0x04, yoshi_egg_seg5_dl_050098B0
         geo_display_list 0x04, yoshi_egg_seg5_dl_05009898
         geo_display_list 0x04, yoshi_egg_seg5_dl_05009880
         geo_display_list 0x04, yoshi_egg_seg5_dl_05009868
         geo_display_list 0x04, yoshi_egg_seg5_dl_05009850
         geo_display_list 0x04, yoshi_egg_seg5_dl_05009838
         geo_display_list 0x04, yoshi_egg_seg5_dl_05009820
      geo_close_node
   geo_close_node
   geo_end

glabel thwomp_geo # 0x0C000248
   geo_shadow SHADOW_SQUARE_SCALABLE, 0xB4, 300
   geo_open_node
      geo_display_list 0x01, thwomp_seg5_dl_0500B750
   geo_close_node
   geo_end

glabel bullet_bill_geo # 0x0C000264
   geo_node_start
   geo_open_node
      geo_shadow SHADOW_SQUARE_PERMANENT, 0x96, 400
      geo_open_node
         geo_display_list 0x01, bullet_bill_seg5_dl_0500E8A8
      geo_close_node
   geo_close_node
   geo_end

glabel heave_ho_geo # 0x0C00028C
   geo_shadow SHADOW_CIRCLE_UNK1, 0xC8, 100
   geo_open_node
      geo_scale 0x00, 16384
      geo_open_node
         geo_dl_translated 0x01, 0, 0, 0
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0, heave_ho_seg5_dl_05014D80
            geo_open_node
               geo_dl_translated 0x01, 140, -11, 0
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, heave_ho_seg5_dl_05011EC0
                  geo_open_node
                     geo_dl_translated 0x01, 150, 50, 0
                     geo_open_node
                        geo_dl_translated 0x01, 0, 0, 0, heave_ho_seg5_dl_05014560
                        geo_dl_translated 0x04, 0, 0, 0, heave_ho_seg5_dl_050127F8
                     geo_close_node
                  geo_close_node
               geo_close_node
               geo_dl_translated 0x01, 135, 0, -84
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0
                  geo_open_node
                     geo_billboard
                     geo_open_node
                        geo_display_list 0x04, heave_ho_seg5_dl_050126E8
                     geo_close_node
                  geo_close_node
                  geo_open_node
                     geo_dl_translated 0x01, 168, 0, 0
                     geo_open_node
                        geo_billboard
                        geo_open_node
                           geo_display_list 0x04, heave_ho_seg5_dl_050126E8
                        geo_close_node
                     geo_close_node
                     geo_dl_translated 0x01, 168, 0, 0
                  geo_close_node
               geo_close_node
               geo_dl_translated 0x01, 149, -28, 0
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, heave_ho_seg5_dl_050125F8
                  geo_dl_translated 0x01, 0, 0, 0, heave_ho_seg5_dl_05012148
                  geo_dl_translated 0x01, 0, 0, 0, heave_ho_seg5_dl_050123A8
               geo_close_node
            geo_close_node
            geo_dl_translated 0x01, 0, 0, 0
            geo_open_node
               geo_billboard
               geo_open_node
                  geo_display_list 0x04, heave_ho_seg5_dl_050126E8
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
   geo_end
