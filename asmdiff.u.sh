#!/bin/bash

OBJDUMP="${MIPS_BINUTILS_PREFIX}objdump -D -z -bbinary -mmips -EB"
OPTIONS="--start-address=$(($1)) --stop-address=$(($1 + $2))"
$OBJDUMP $OPTIONS baserom.u.z64 > baserom.dump
$OBJDUMP $OPTIONS build/us/sm64.u.z64 > sm64.u.dump
diff baserom.dump sm64.u.dump
