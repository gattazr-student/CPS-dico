#!/bin/bash
# need to be sourced (source setenv.sh)
export DYLD_LIBRARY_PATH=$(pwd)/lib/libmacos64:$DYLD_LIBRARY_PATH
echo DYLD_LIBRARY_PATH=$DYLD_LIBRARY_PATH
