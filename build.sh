#!/bin/bash

BUILD_DIR=build

rm -rf $BUILD_DIR
mkdir $BUILD_DIR
cd $BUILD_DIR
cmake -Dtest=ON ..
make
make test
cd ..
$BUILD_DIR/cppproperties_unittests
