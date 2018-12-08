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
