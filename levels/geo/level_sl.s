.include "geo_commands.inc"

glabel sl_geo_000360 # 0x0E000360
   geo_node_start
   geo_open_node
      geo_display_list 0x05, sl_seg7_dl_0700A890
   geo_close_node
   geo_end

glabel sl_geo_000378 # 0x0E000378
   geo_node_start
   geo_open_node
      geo_display_list 0x05, sl_seg7_dl_0700A980
   geo_close_node
   geo_end

glabel sl_geo_000390 # 0x0E000390
   geo_start_distance 350
   geo_open_node
      geo_display_list 0x01, sl_seg7_dl_0700A780
   geo_close_node
   geo_end

glabel sl_geo_0003A8 # 0x0E0003A8
   geo_node_screen_area 10, 160, 120, 160, 120
   geo_open_node
      geo_zbuffer 0
      geo_open_node
         geo_todo_09 100
         geo_open_node
            geo_background 4, Geo19_802763D4
         geo_close_node
      geo_close_node
      geo_zbuffer 1
      geo_open_node
         geo_camera_frustum 45, 100, 20000, Geo0A_8029AA3C
         geo_open_node
            geo_todo_0F 16, 0, 2000, 6000, 0, 4400, 0, Geo0F_80287D30
            geo_open_node
               geo_display_list 0x01, sl_seg7_dl_07005478
               geo_display_list 0x05, sl_seg7_dl_070056B0
               geo_display_list 0x01, sl_seg7_dl_070073D0
               geo_display_list 0x04, sl_seg7_dl_07007880
               geo_display_list 0x05, sl_seg7_dl_070088B0
               geo_display_list 0x06, sl_seg7_dl_07008D58
               geo_display_list 0x01, sl_seg7_dl_0700A5A0
               geo_asm    0, Geo18_802D01E0
               geo_asm 4097, Geo18_802D104C
               geo_todo_17
               geo_asm    1, Geo18_802761D0
            geo_close_node
         geo_close_node
      geo_close_node
      geo_zbuffer 0
      geo_open_node
         geo_asm 0, Geo18_802CD1E8
      geo_close_node
   geo_close_node
   geo_end

glabel sl_geo_000484 # 0x0E000484
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
            geo_todo_0F 4, 0, 2000, 6000, 0, 0, 0, Geo0F_80287D30
            geo_open_node
               geo_display_list 0x01, sl_seg7_dl_0700BAE8
               geo_display_list 0x01, sl_seg7_dl_0700BCF8
               geo_display_list 0x05, sl_seg7_dl_0700C9E8
               geo_display_list 0x05, sl_seg7_dl_0700CB58
               geo_todo_17
               geo_asm 0, Geo18_802761D0
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
   geo_end

.word 0x0
.word 0x0
.word 0x0
