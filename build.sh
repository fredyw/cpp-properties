#!/bin/bash

set -e

BUILD_DIR=build

rm -rf $BUILD_DIR || true
mkdir $BUILD_DIR
cd $BUILD_DIR
cmake -Dtest=ON ..
make
cd ..
$BUILD_DIR/cppproperties_unittests
