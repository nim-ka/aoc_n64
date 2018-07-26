.include "geo_commands.inc"

glabel pss_geo_000100 # 0x0E000100
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
            geo_todo_0F 9, 0, 2000, 6000, 0, 0, 0, Geo0F_80287D30
            geo_open_node
               geo_display_list 0x01, pss_seg7_dl_0700A7C0
               geo_display_list 0x01, pss_seg7_dl_0700AFA8
               geo_display_list 0x01, pss_seg7_dl_0700B3F0
               geo_display_list 0x01, pss_seg7_dl_0700D338
               geo_display_list 0x05, pss_seg7_dl_0700DAD8
               geo_display_list 0x01, pss_seg7_dl_0700E2B0
               geo_display_list 0x02, pss_seg7_dl_0700E3E8
               geo_todo_17
               geo_asm 0, Geo18_802761D0
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
   geo_end
