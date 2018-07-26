.include "geo_commands.inc"

glabel castle_courtyard_geo_000200 # 0x0E000200
   geo_start_distance 2600
   geo_open_node
      geo_display_list 0x01, castle_courtyard_seg7_dl_07005078
   geo_close_node
   geo_end

glabel castle_courtyard_geo_000218 # 0x0E000218
   geo_node_screen_area 10, 160, 120, 160, 120
   geo_open_node
      geo_zbuffer 0
      geo_open_node
         geo_todo_09 100
         geo_open_node
            geo_background 0, Geo19_802763D4
         geo_close_node
      geo_close_node
      geo_zbuffer 1
      geo_open_node
         geo_camera_frustum 45, 100, 12800, Geo0A_8029AA3C
         geo_open_node
            geo_todo_0F 16, 0, 2000, 6000, 0, 0, 0, Geo0F_80287D30
            geo_open_node
               geo_display_list 0x01, castle_courtyard_seg7_dl_070048B8
               geo_display_list 0x06, castle_courtyard_seg7_dl_07005698
               geo_display_list 0x04, castle_courtyard_seg7_dl_07005938
               geo_asm    0, Geo18_802D01E0
               geo_asm 9729, Geo18_802D104C
               geo_todo_17
               geo_asm 0, Geo18_802761D0
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
   geo_end
