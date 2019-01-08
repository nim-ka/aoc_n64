# Assembly Macros

.set NULL, 0
.set FALSE, 0
.set TRUE, 1

.macro glabel label
    .global \label
    \label:
.endm

# F3D vertex
.macro vertex x, y, z, u, v, r=0xFF, g=0xFF, b=0xFF, a=0xFF
    .hword \x, \y, \z, 0, \u, \v
    .byte \r, \g, \b, \a
.endm

# Beginning of trajectory
.macro trajectory_init
    .set TRAJ_ID, 0
.endm

# Entry in trajectory
.macro trajectory_pos x, y, z
    .hword TRAJ_ID, \x, \y, \z
	.set TRAJ_ID, TRAJ_ID + 1
.endm

# Skips an ID (used for CCM)
.macro trajectory_skip
    .set TRAJ_ID, TRAJ_ID + 1
.endm

# End of trajectory
.macro trajectory_end
    .hword -1
.endm

.macro macro_object preset, yaw, x, y, z, bparam=0
    .hword ((\yaw * 0x10 / 45) << 9) | (\preset + 0x1F), \x, \y, \z, \bparam
.endm

# Actor include
.macro actor name
.include "actors/\name\()/actor.s"
.endm

# Actor geo include
.macro actorgeo name
.include "actors/\name\()/geo.s"
.endm

.macro initbinid
.set BINID, 0
.endm

.macro binid
.dword BINID
.set BINID, BINID + 1
.endm
