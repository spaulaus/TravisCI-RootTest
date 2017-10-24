#!/bin/bash
set -ex

SRC_DIR=$(dirname "$0")

export CC=gcc-5 && export CXX=g++-5 && export FC=gfortran-5
sudo apt-get -qq update --install-suggests
mkdir -p /opt
git clone https://github.com/unittest-cpp/unittest-cpp.git && cd unittest-cpp/builds/
cmake ../ && sudo make -j4 install && cd ../../
git clone https://github.com/spaulaus/xia-api.git && cd xia-api
mkdir build && cd build && cmake ../ -DCMAKE_INSTALL_PREFIX=/opt && make install && cd ../../
ln -s /opt/xia/api /opt/xia/current
git clone https://github.com/spaulaus/paass-laughing-conqueror.git && cd paass-laughing-conqueror
git checkout dev
mkdir paass-build && cd paass-build
cmake ../ -DPAASS_BUILD_SCAN_UTILITIES=ON -DPAASS_BUILD_ACQ=ON -DPAASS_BUILD_TESTS=ON -DPAASS_BUILD_UTKSCAN=ON -DPAASS_USE_ROOT=ON
make -j8 install
for test in ../install/bin/unittests/*; do ./$test; if [ $? != 0 ]; then false; exit; fi; done
