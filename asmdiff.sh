#!/bin/bash

OBJDUMP="mips-linux-gnu-objdump -D -z -bbinary -mmips -EB"
OPTIONS="--start-address=$(($1)) --stop-address=$(($1 + $2))"
$OBJDUMP $OPTIONS baserom.z64 > baserom.dump
$OBJDUMP $OPTIONS build/sm64.j.z64 > sm64.j.dump
diff baserom.dump sm64.j.dump
