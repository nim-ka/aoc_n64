/*
 * Super Mario 64 ROM header
 * Only the first 0x18 bytes matter to the console.
 */

.byte  0x80, 0x37, 0x12, 0x40   /* PI BSD Domain 1 register */
.word  0x0000000F               /* Clockrate setting*/
.word  entry_point               /* Entrypoint */

.word  0x00001444

.word  0x4EAA3D0E               /* Checksum 1 */
.word  0x74757C24               /* Checksum 2 */
.word  0x00000000               /* Unknown */
.word  0x00000000               /* Unknown */
.ascii "SUPER MARIO 64      "   /* Internal ROM name */
.word  0x00000000               /* Unknown */
.word  0x0000004E               /* Cartridge */
.ascii "SM"                     /* Cartridge ID */

.ascii "E"                  /* NTSC-U (North America) */

.byte  0x00                 /* Version */

