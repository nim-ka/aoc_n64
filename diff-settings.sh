#!/usr/bin/env bash

BASEROM=baseromus
LANG=us
LANG_SHORT=u

POSITIONAL=()
while [[ $# -gt 0 ]]; do
case "$1" in
    -j)
        BASEROM=baserom
        LANG=jp
        LANG_SHORT=j
        shift
        ;;
    -u)
        BASEROM=baseromus
        LANG=us
        LANG_SHORT=u
        shift
        ;;
    -e)
        BASEROM=baseromeu
        LANG=eu
        LANG_SHORT=eu
        shift
        ;;
    *)
        POSITIONAL+=("$1")
        shift
        ;;
esac
done
set -- "${POSITIONAL[@]}"

MAPFILE="build/$LANG/sm64.map"
MYDUMP=sm64.$LANG_SHORT.dump
MYIMG=build/$LANG/sm64.$LANG_SHORT.z64
BASEDUMP=$BASEROM.dump
BASEIMG=$BASEROM.z64
MAKEFLAGS="VERSION=$LANG"
