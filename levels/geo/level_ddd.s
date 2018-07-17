.include "geo_commands.inc"

glabel ddd_geo_000450 # 0450
   geo_start_distance 700
      geo_open_node
         geo_shadow SHADOW_SQUARE_PERMANENT, 0xB4, 120
            geo_open_node
               geo_display_list 0x01, ddd_seg7_dl_0700D2A0
            geo_close_node
         geo_close_node
      geo_end

glabel ddd_geo_000478 # 0478
   geo_start_distance 10000
      geo_open_node
         geo_display_list 0x05, ddd_seg7_dl_07009030
         geo_display_list 0x01, ddd_seg7_dl_07009120
         geo_display_list 0x05, ddd_seg7_dl_07009208
      geo_close_node
   geo_end

glabel ddd_geo_0004A0 # 04A0
   geo_start_distance 10000
      geo_open_node
         geo_display_list 0x01, ddd_seg7_dl_0700AF10
         geo_display_list 0x04, ddd_seg7_dl_0700B068
      geo_close_node
   geo_end

glabel ddd_geo_0004C0 # 04C0
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
               geo_todo_0F 2, 0, 2000, 6000, 2560, 0, 512, Geo0F_80287D30
               geo_open_node
                  geo_display_list 0x01, ddd_seg7_dl_07004D48
                  geo_display_list 0x01, ddd_seg7_dl_070057E8
                  geo_display_list 0x04, ddd_seg7_dl_07005C40
                  geo_display_list 0x05, ddd_seg7_dl_07005F78
                  geo_asm    0, Geo18_802D01E0
                  geo_asm 8961, Geo18_802D104C
                  geo_todo_17
                  geo_asm   13, Geo18_802761D0
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_end

glabel ddd_geo_000570 # 0570
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
               geo_todo_0F 4, 0, 2000, 6000, 2560, 0, 512, Geo0F_80287D30
               geo_open_node
                  geo_display_list 0x01, ddd_seg7_dl_07007408
                  geo_display_list 0x01, ddd_seg7_dl_07007CB8
                  geo_display_list 0x04, ddd_seg7_dl_07008C48
                  geo_display_list 0x05, ddd_seg7_dl_07008F80
                  geo_display_list 0x04, ddd_seg7_dl_0700BAE0
                  geo_display_list 0x01, ddd_seg7_dl_0700CE48
                  geo_asm    0, Geo18_802D01E0
                  geo_asm 8962, Geo18_802D104C
                  geo_todo_17
                  geo_asm   14, Geo18_802761D0
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_end
