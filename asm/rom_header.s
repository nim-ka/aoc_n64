# Super Mario 64 (J) ROM Header

.byte  0x80, 0x37, 0x12, 0x40 # PI BSD Domain 1 register
.word  0x0000000F # clock rate setting
.word  EntryPoint # entry point
.word  0x00001444 # release
.word  0x4EAA3D0E # checksum1
.word  0x74757C24 # checksum2
.word  0x00000000 # unknown
.word  0x00000000 # unknown
.ascii "SUPER MARIO 64      " # ROM name: 20 bytes
.word  0x00000000 # unknown
.word  0x0000004E # cartridge
.ascii "SM"       # cartridge ID
.ascii "J"        # country
.byte  0x00       # version
