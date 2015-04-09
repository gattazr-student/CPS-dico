#!/bin/bash
# need to be sourced (source setenv.sh)
export DYLD_LIBRARY_PATH=$(pwd)/lib/libmacos64:$DYLD_LIBRARY_PATH
export LD_LIBRARY_PATH=$(pwd)/lib/liblinux64:$LD_LIBRARY_PATH
