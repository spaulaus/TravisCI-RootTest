#!/bin/bash
set -ex

SRC_DIR=$(dirname "$0")

export CC=gcc-5 && export CXX=g++-5 && export FC=gfortran-5

cmake $SRC_DIR/paass-laughing-conqueror -DPAASS_BUILD_SCAN_UTILITIES=ON -DPAASS_BUILD_ACQ=ON -DPAASS_BUILD_TESTS=ON -DPAASS_BUILD_UTKSCAN=ON -DPAASS_USE_ROOT=ON
make -j8 install
for test in ../install/bin/unittests/*; do ./$test; if [ $? != 0 ]; then false; exit; fi; done
