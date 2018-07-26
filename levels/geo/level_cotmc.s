.include "geo_commands.inc"

glabel cotmc_geo_0001A0 # 0x0E0001A0
   geo_node_screen_area 10, 160, 120, 160, 120
   geo_open_node
      geo_zbuffer 0
      geo_open_node
         geo_todo_09 100
         geo_open_node
            geo_background 0x0001
         geo_close_node
      geo_close_node
      geo_zbuffer 1
      geo_open_node
         geo_camera_frustum 45, 100, 12800, Geo0A_8029AA3C
         geo_open_node
            geo_todo_0F 16, 0, 2000, 6000, 0, 0, 0, Geo0F_80287D30
            geo_open_node
               geo_display_list 0x01, cotmc_seg7_dl_07007D48
               geo_display_list 0x01, cotmc_seg7_dl_0700A160
               geo_asm     0, Geo18_802D01E0
               geo_asm 10241, Geo18_802D1B70
               geo_display_list 0x05, cotmc_seg7_dl_0700A4B8
               geo_todo_17
               geo_asm 0, Geo18_802761D0
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
   geo_end

.word 0x0
.word 0x0
