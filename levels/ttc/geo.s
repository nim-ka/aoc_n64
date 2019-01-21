glabel ttc_geo_000240 # 0x0E000240
   geo_start_distance 410
   geo_open_node
      geo_display_list 0x01, ttc_seg7_dl_0700ECB8
   geo_close_node
   geo_end

glabel ttc_geo_000258 # 0x0E000258
   geo_start_distance 410
   geo_open_node
      geo_display_list 0x01, ttc_seg7_dl_0700EFE0
   geo_close_node
   geo_end

glabel ttc_geo_000270 # 0x0E000270
   geo_start_distance 1100
   geo_open_node
      geo_display_list 0x01, ttc_seg7_dl_0700F760
   geo_close_node
   geo_end

glabel ttc_geo_000288 # 0x0E000288
   geo_start_distance 720
   geo_open_node
      geo_display_list 0x01, ttc_seg7_dl_0700FBB8
      geo_asm 5120, Geo18_802D1E48
   geo_close_node
   geo_end

glabel ttc_geo_0002A8 # 0x0E0002A8
   geo_start_distance 520
   geo_open_node
      geo_display_list 0x01, ttc_seg7_dl_0700FFE8
      geo_asm 5121, Geo18_802D1E48
   geo_close_node
   geo_end

glabel ttc_geo_0002C8 # 0x0E0002C8
   geo_start_distance 500
   geo_open_node
      geo_display_list 0x01, ttc_seg7_dl_070102B8
   geo_close_node
   geo_end

glabel ttc_geo_0002E0 # 0x0E0002E0
   geo_start_distance 400
   geo_open_node
      geo_display_list 0x01, ttc_seg7_dl_07010868
   geo_close_node
   geo_end

glabel ttc_geo_0002F8 # 0x0E0002F8
   geo_start_distance 520
   geo_open_node
      geo_display_list 0x01, ttc_seg7_dl_07010D38
   geo_close_node
   geo_end

glabel ttc_geo_000310 # 0x0E000310
   geo_start_distance 250
   geo_open_node
      geo_display_list 0x01, ttc_seg7_dl_07011040
   geo_close_node
   geo_end

glabel ttc_geo_000328 # 0x0E000328
   geo_start_distance 250
   geo_open_node
      geo_display_list 0x01, ttc_seg7_dl_07011360
   geo_close_node
   geo_end

glabel ttc_geo_000340 # 0x0E000340
   geo_start_distance 380
   geo_open_node
      geo_display_list 0x01, ttc_seg7_dl_070116A8
   geo_close_node
   geo_end

glabel ttc_geo_000358 # 0x0E000358
   geo_start_distance 1700
   geo_open_node
      geo_display_list 0x01, ttc_seg7_dl_07011B38
   geo_close_node
   geo_end

glabel ttc_geo_000370 # 0x0E000370
   geo_start_distance 500
   geo_open_node
      geo_display_list 0x01, ttc_seg7_dl_07012028
   geo_close_node
   geo_end

glabel ttc_geo_000388 # 0x0E000388
   geo_start_distance 200
   geo_open_node
      geo_display_list 0x04, ttc_seg7_dl_07012148
   geo_close_node
   geo_end

glabel ttc_geo_0003A0 # 0x0E0003A0
   geo_start_distance 300
   geo_open_node
      geo_display_list 0x04, ttc_seg7_dl_07012278
   geo_close_node
   geo_end

glabel ttc_geo_0003B8 # 0x0E0003B8
   geo_node_screen_area 10, 160, 120, 160, 120
   geo_open_node
      geo_zbuffer 0
      geo_open_node
         geo_todo_09 100
         geo_open_node
            geo_background 0xC7FF
         geo_close_node
      geo_close_node
      geo_zbuffer 1
      geo_open_node
         geo_camera_frustum 45, 100, 12800, Geo0A_8029AA3C
         geo_open_node
            geo_todo_0F 2, 0, 2000, 6000, 0, 0, 0, Geo0F_80287D30
            geo_open_node
               geo_asm    0, Geo18_802D01E0
               geo_asm 5120, Geo18_802D2108
               geo_asm 5121, Geo18_802D2108
               geo_display_list 0x01, ttc_seg7_dl_0700AD38
               geo_display_list 0x05, ttc_seg7_dl_0700B1D8
               geo_display_list 0x04, ttc_seg7_dl_0700E878
               geo_todo_17
               geo_asm    0, Geo18_802761D0
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
   geo_end

.word 0x0
.word 0x0
