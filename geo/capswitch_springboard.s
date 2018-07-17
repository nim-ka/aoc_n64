.include "macros.inc"
.include "geo_commands.inc"

.section .geo, "a"

# unused
glabel geo_layout_springboard_checkerboard1 # 0x0C000000
   geo_start_distance 500
      geo_open_node
         geo_display_list 0x01, seg5_dl_050016B8
      geo_close_node
   geo_end

# unused
glabel geo_layout_springboard_spring # 0x0C000018
   geo_start_distance 500
      geo_open_node
         geo_display_list 0x01, seg5_dl_05001800
      geo_close_node
   geo_end

# unused
glabel geo_layout_springboard_checkerboard2 # 0x0C000030
   geo_start_distance 500
      geo_open_node
         geo_display_list 0x01, seg5_dl_05001900
      geo_close_node
   geo_end

glabel geo_layout_cap_switch # 0x0C000048
   geo_start_distance 600
      geo_open_node
         geo_display_list 0x06, seg5_dl_05002E00
         geo_switch_case 4, GeoSwitchCase8029DB48
         geo_open_node
            geo_display_list 0x01, seg5_dl_05003350
            geo_display_list 0x01, seg5_dl_05003370
            geo_display_list 0x01, seg5_dl_05003390
            geo_display_list 0x01, seg5_dl_050033B0
         geo_close_node
      geo_close_node
   geo_end
