.include "macros.inc"
.include "geo_commands.inc"

.section .geo, "a"

# unused
glabel springboard_checkerboard1_geo # 0x0C000000
   geo_start_distance 500
      geo_open_node
         geo_display_list 0x01, springboard_checkerboard_seg5_dl_050016B8
      geo_close_node
   geo_end

# unused
glabel springboard_spring_geo # 0x0C000018
   geo_start_distance 500
      geo_open_node
         geo_display_list 0x01, springboard_spring_seg5_dl_05001800
      geo_close_node
   geo_end

# unused
glabel springboard_checkerboard2_geo # 0x0C000030
   geo_start_distance 500
      geo_open_node
         geo_display_list 0x01, springboard_checkerboard_seg5_dl_05001900
      geo_close_node
   geo_end

glabel cap_switch_geo # 0x0C000048
   geo_start_distance 600
      geo_open_node
         geo_display_list 0x06, cap_switch_seg5_dl_05002E00
         geo_switch_case 4, GeoSwitchCase8029DB48
         geo_open_node
            geo_display_list 0x01, cap_switch_seg5_dl_05003350
            geo_display_list 0x01, cap_switch_seg5_dl_05003370
            geo_display_list 0x01, cap_switch_seg5_dl_05003390
            geo_display_list 0x01, cap_switch_seg5_dl_050033B0
         geo_close_node
      geo_close_node
   geo_end
