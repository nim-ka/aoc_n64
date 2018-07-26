.include "geo_commands.inc"

glabel jrb_geo_000900 # 0x0E000900
   geo_start_distance 1600
   geo_open_node
      geo_display_list 0x01, jrb_seg7_dl_0700AE48
   geo_close_node
   geo_end

glabel jrb_geo_000918 # 0x0E000918
   geo_start_distance 300
   geo_open_node
      geo_display_list 0x01, jrb_seg7_dl_0700AFB0
   geo_close_node
   geo_end

glabel jrb_geo_000930 # 0x0E000930
   geo_start_distance 1100
   geo_open_node
      geo_display_list 0x01, jrb_seg7_dl_07007AC8
   geo_close_node
   geo_end

glabel jrb_geo_000948 # 0x0E000948
   geo_start_distance 900
   geo_open_node
      geo_display_list 0x01, jrb_seg7_dl_07007DC8
   geo_close_node
   geo_end

glabel jrb_geo_000960 # 0x0E000960
   geo_start_distance 300
   geo_open_node
      geo_display_list 0x01, jrb_seg7_dl_070080F8
   geo_close_node
   geo_end

glabel jrb_geo_000978 # 0x0E000978
   geo_start_distance 5000
   geo_open_node
      geo_display_list 0x01, jrb_seg7_dl_07008FD8
   geo_close_node
   geo_end

glabel jrb_geo_000990 # 0x0E000990
   geo_start_distance 5000
   geo_open_node
      geo_asm 0, Geo18_8029D924
      geo_display_list 0x05, jrb_seg7_dl_070090B0
   geo_close_node
   geo_end

glabel jrb_geo_0009B0 # 0x0E0009B0
   geo_start_distance 5000
   geo_open_node
      geo_display_list 0x01, jrb_seg7_dl_07009A58
   geo_close_node
   geo_end

glabel jrb_geo_0009C8 # 0x0E0009C8
   geo_start_distance 5000
   geo_open_node
      geo_asm 0, Geo18_8029D924
      geo_display_list 0x05, jrb_seg7_dl_07009B30
   geo_close_node
   geo_end

glabel jrb_geo_0009E8 # 0x0E0009E8
   geo_start_distance 5000
   geo_open_node
      geo_display_list 0x01, jrb_seg7_dl_0700A608
   geo_close_node
   geo_end

glabel jrb_geo_000A00 # 0x0E000A00
   geo_start_distance 5000
   geo_open_node
      geo_display_list 0x01, jrb_seg7_dl_0700AC68
   geo_close_node
   geo_end

glabel jrb_geo_000A18 # 0x0E000A18
   geo_node_screen_area 10, 160, 120, 160, 120
   geo_open_node
      geo_zbuffer 0
      geo_open_node
         geo_todo_09 100
         geo_open_node
            geo_background 8, Geo19_802763D4
         geo_close_node
      geo_close_node
      geo_zbuffer 1
      geo_open_node
         geo_camera_frustum 45, 100, 25000, Geo0A_8029AA3C
         geo_open_node
            geo_todo_0F 16, 0, 2000, 6000, 0, 0, 0, Geo0F_80287D30
            geo_open_node
               geo_display_list 0x04, jrb_seg7_dl_07002FD0
               geo_display_list 0x01, jrb_seg7_dl_07004940
               geo_display_list 0x01, jrb_seg7_dl_07004C78
               geo_display_list 0x01, jrb_seg7_dl_070058C8
               geo_display_list 0x01, jrb_seg7_dl_070069B0
               geo_display_list 0x01, jrb_seg7_dl_07007570
               geo_display_list 0x04, jrb_seg7_dl_07007718
               geo_asm    0, Geo18_802D01E0
               geo_asm 4609, Geo18_802D104C
               geo_asm 4613, Geo18_802D104C
               geo_todo_17
               geo_asm   14, Geo18_802761D0
            geo_close_node
         geo_close_node
      geo_close_node
      geo_zbuffer 0
      geo_open_node
         geo_asm 0, Geo18_802CD1E8
      geo_close_node
   geo_close_node
   geo_end

glabel jrb_geo_000AFC # 0x0E000AFC
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
         geo_camera_frustum 45, 100, 10000, Geo0A_8029AA3C
         geo_open_node
            geo_todo_0F 16, 0, 2000, 6000, 0, 0, 0, Geo0F_80287D30
            geo_open_node
               geo_display_list 0x01, jrb_seg7_dl_0700EF00
               geo_display_list 0x04, jrb_seg7_dl_0700FE48
               geo_display_list 0x01, jrb_seg7_dl_07010548
               geo_asm    0, Geo18_802D01E0
               geo_asm 4610, Geo18_802D104C
               geo_todo_17
               geo_asm    2, Geo18_802761D0
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
   geo_end

.word 0x0
.word 0x0
.word 0x0
