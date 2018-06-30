#!/bin/bash

set -euo pipefail

NAME=cpp-properties
BUILD_DIR=build

rm -rf ${BUILD_DIR} || true
mkdir ${BUILD_DIR}
pushd ${BUILD_DIR}
cmake -DCMAKE_INSTALL_PREFIX:PATH=/${NAME} ..
cmake -DENABLE_TEST=ON ..
make
./cppproperties_unittests
make DESTDIR=. install
tar czf ${NAME}.tar.gz ${NAME}/
popd
