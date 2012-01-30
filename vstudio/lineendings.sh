#!/bin/bash

DIRNAME=$(cd $(dirname $0) && pwd -P)

#echo Dir name is ${DIRNAME}

find "$DIRNAME/.." \( -iname "*.cpp" -o -iname "*.h" \) -exec dos2unix {} \;
