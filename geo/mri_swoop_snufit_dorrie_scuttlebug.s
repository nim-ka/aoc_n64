.include "macros.inc"
.include "geo_commands.inc"

.section .geo, "a"

glabel mri_geo # 0x0D000000
   geo_shadow SHADOW_CIRCLE_UNK1, 0x9B, 200
   geo_open_node
      geo_display_list 0x04, mri_seg6_dl_06002080
   geo_close_node
   geo_end

glabel mri_iris_geo # 0x0D00001C
   geo_node_start
   geo_open_node
      geo_switch_case 20, GeoSwitchCase8029DB48
      geo_open_node
         geo_display_list 0x04, mri_seg6_dl_060041D8
         geo_display_list 0x04, mri_seg6_dl_060041F0
         geo_display_list 0x04, mri_seg6_dl_06004208
         geo_display_list 0x04, mri_seg6_dl_06004220
         geo_display_list 0x04, mri_seg6_dl_06004208
         geo_display_list 0x04, mri_seg6_dl_060041F0
         geo_display_list 0x04, mri_seg6_dl_060041D8
         geo_display_list 0x04, mri_seg6_dl_060041D8
         geo_display_list 0x04, mri_seg6_dl_060041D8
         geo_display_list 0x04, mri_seg6_dl_060041F0
         geo_display_list 0x04, mri_seg6_dl_06004208
         geo_display_list 0x04, mri_seg6_dl_06004220
         geo_display_list 0x04, mri_seg6_dl_06004208
         geo_display_list 0x04, mri_seg6_dl_060041F0
         geo_display_list 0x04, mri_seg6_dl_060041D8
         geo_display_list 0x04, mri_seg6_dl_060041D8
         geo_display_list 0x04, mri_seg6_dl_060041D8
         geo_display_list 0x04, mri_seg6_dl_060041D8
         geo_display_list 0x04, mri_seg6_dl_060041D8
         geo_display_list 0x04, mri_seg6_dl_060041D8
      geo_close_node
   geo_close_node
   geo_end

glabel swoop_geo # 0x0D0000DC
   geo_shadow SHADOW_CIRCLE_UNK1, 0x96, 100
   geo_open_node
      geo_scale 0x00, 16384
      geo_open_node
         geo_dl_translated 0x01, 0, 0, 0
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0
            geo_open_node
               geo_billboard
               geo_open_node
                  geo_display_list 0x04, swoop_seg6_dl_06006880
               geo_close_node
            geo_close_node
            geo_open_node
               geo_dl_translated 0x01, 54, 0, 0, swoop_seg6_dl_06006758
               geo_dl_translated 0x01, 54, 0, 0, swoop_seg6_dl_06006A88
               geo_dl_translated 0x01, 57, -48, 0
               geo_open_node
                  geo_dl_translated 0x04, 0, 0, 0, swoop_seg6_dl_06006BD0
               geo_close_node
               geo_dl_translated 0x01, 57, -48, 0
               geo_open_node
                  geo_dl_translated 0x04, 0, 0, 0, swoop_seg6_dl_06006D00
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
   geo_end

glabel snufit_geo # 0x0D0001A0
   geo_shadow SHADOW_CIRCLE_UNK1, 0x96, 100
   geo_open_node
      geo_scale 0x00, 16384
      geo_open_node
         geo_asm 0, Geo18_8030D93C
         geo_todo_11 0x00, 0, 0, 0
         geo_open_node
            geo_display_list 0x01, snufit_seg6_dl_06009748
         geo_close_node
         geo_display_list 0x01, snufit_seg6_dl_06009498
         geo_display_list 0x01, snufit_seg6_dl_06009938
         geo_display_list 0x01, snufit_seg6_dl_06009B68
         geo_billboard
         geo_open_node
            geo_asm 0, Geo18_8030D9AC
            geo_scale 0x00, 0
            geo_open_node
               geo_display_list 0x04, snufit_seg6_dl_06009A10
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
geo_close_node #! more close than open nodes
geo_end

glabel dorrie_geo # 0x0D000230
   geo_start_distance 5000
   geo_open_node
      geo_scale 0x00, 16384
      geo_open_node
         geo_dl_translated 0x01, 0, 0, 0
         geo_open_node
            geo_dl_translated 0x01, 0, 0, 0, dorrie_seg6_dl_0600CFD0
            geo_open_node
               geo_dl_translated 0x01, 1295, 0, 0, dorrie_seg6_dl_0600C8B8
               geo_open_node
                  geo_dl_translated 0x01, 916, 0, 0, dorrie_seg6_dl_0600C468
                  geo_open_node
                     geo_dl_translated 0x01, 874, 0, 0, dorrie_seg6_dl_0600BAF8
                     geo_open_node
                        geo_display_list 0x04, dorrie_seg6_dl_0600DFA8
                        geo_dl_translated 0x01, 30, 444, -6
                        geo_open_node
                           geo_dl_translated 0x01, 0, 0, 0, dorrie_seg6_dl_0600C030
                        geo_close_node
                     geo_close_node
                  geo_close_node
               geo_close_node
               geo_dl_translated 0x01, -893, -490, -6
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, dorrie_seg6_dl_0600D440
                  geo_open_node
                     geo_dl_translated 0x01, 1300, 0, 0, dorrie_seg6_dl_0600D6D8
                  geo_close_node
               geo_close_node
               geo_dl_translated 0x01, -1086, 91, -700
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, dorrie_seg6_dl_0600DE38
               geo_close_node
               geo_dl_translated 0x01, 902, 700, -785
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, dorrie_seg6_dl_0600DA88
               geo_close_node
               geo_dl_translated 0x01, -1086, 91, 698
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, dorrie_seg6_dl_0600DC60
               geo_close_node
               geo_dl_translated 0x01, 902, 700, 783
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0, dorrie_seg6_dl_0600D8B0
               geo_close_node
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
geo_close_node #! more close than open nodes
geo_end

glabel scuttlebug_geo # 0x0D000394
   geo_shadow SHADOW_CIRCLE_UNK1, 0x96, 100
   geo_open_node
      geo_scale 0x00, 16384
      geo_open_node
         geo_dl_translated 0x01, 0, 0, 0
         geo_open_node
            geo_dl_translated 0x01, 0, -29, 0
            geo_open_node
               geo_dl_translated 0x01, -1, 113, 112
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0
                  geo_open_node
                     geo_dl_translated 0x01, 198, 0, 0
                     geo_open_node
                        geo_dl_translated 0x01, 195, 0, 0
                        geo_open_node
                           geo_dl_translated 0x04, 0, 0, 0, scuttlebug_seg6_dl_06014378
                        geo_close_node
                        geo_dl_translated 0x04, 0, 0, 0, scuttlebug_seg6_dl_06014270
                     geo_close_node
                     geo_dl_translated 0x04, 0, 0, 0, scuttlebug_seg6_dl_06014188
                  geo_close_node
               geo_close_node
               geo_dl_translated 0x01, -1, 109, -116
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0
                  geo_open_node
                     geo_dl_translated 0x01, 198, 0, 0
                     geo_open_node
                        geo_dl_translated 0x01, 195, 0, 0
                        geo_open_node
                           geo_dl_translated 0x04, 0, 0, 0, scuttlebug_seg6_dl_06014378
                        geo_close_node
                        geo_dl_translated 0x04, 0, 0, 0, scuttlebug_seg6_dl_06014270
                     geo_close_node
                     geo_dl_translated 0x04, 0, 0, 0, scuttlebug_seg6_dl_06014188
                  geo_close_node
               geo_close_node
               geo_dl_translated 0x01, 0, 0, 0
               geo_open_node
                  geo_billboard
                  geo_open_node
                     geo_display_list 0x04, scuttlebug_seg6_dl_060139F8
                  geo_close_node
               geo_close_node
               geo_dl_translated 0x01, -29, -57, 28
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0
                  geo_open_node
                     geo_dl_translated 0x01, 158, 0, 0
                     geo_open_node
                        geo_dl_translated 0x01, 0, 0, 0
                        geo_open_node
                           geo_billboard
                           geo_open_node
                              geo_display_list 0x04, scuttlebug_seg6_dl_06013AE8
                           geo_close_node
                        geo_close_node
                        geo_dl_translated 0x04, 0, 0, 0, scuttlebug_seg6_dl_06013CB8
                     geo_close_node
                  geo_close_node
               geo_close_node
               geo_dl_translated 0x01, -29, 55, 28
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0
                  geo_open_node
                     geo_dl_translated 0x01, 157, 0, 0
                     geo_open_node
                        geo_dl_translated 0x01, 0, 0, 0
                        geo_open_node
                           geo_billboard
                           geo_open_node
                              geo_display_list 0x04, scuttlebug_seg6_dl_06013BD0
                           geo_close_node
                        geo_close_node
                        geo_dl_translated 0x04, 0, 0, 0, scuttlebug_seg6_dl_06013DA0
                     geo_close_node
                  geo_close_node
               geo_close_node
               geo_dl_translated 0x01, -1, -116, -111
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0
                  geo_open_node
                     geo_dl_translated 0x01, 198, 0, 0
                     geo_open_node
                        geo_dl_translated 0x01, 195, 0, 0
                        geo_open_node
                           geo_dl_translated 0x04, 0, 0, 0, scuttlebug_seg6_dl_06014378
                        geo_close_node
                        geo_dl_translated 0x04, 0, 0, 0, scuttlebug_seg6_dl_06014270
                     geo_close_node
                     geo_dl_translated 0x04, 0, 0, 0, scuttlebug_seg6_dl_06014188
                  geo_close_node
               geo_close_node
               geo_dl_translated 0x01, -1, -116, 112
               geo_open_node
                  geo_dl_translated 0x01, 0, 0, 0
                  geo_open_node
                     geo_dl_translated 0x01, 195, 0, 0
                     geo_open_node
                        geo_dl_translated 0x01, 199, 0, 0
                        geo_open_node
                           geo_dl_translated 0x04, 0, 0, 0, scuttlebug_seg6_dl_06014378
                        geo_close_node
                        geo_dl_translated 0x04, 0, 0, 0, scuttlebug_seg6_dl_06014270
                     geo_close_node
                     geo_dl_translated 0x04, 0, 0, 0, scuttlebug_seg6_dl_06014188
                  geo_close_node
               geo_close_node
               geo_dl_translated 0x01, 0, 0, 0, scuttlebug_seg6_dl_060140F0
            geo_close_node
         geo_close_node
      geo_close_node
   geo_close_node
   geo_end
