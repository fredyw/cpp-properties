#!/bin/bash

# CMake Eclipse generator doesn't really work with out-of-source build
if [[ $1 == "--clean" ]]; then
    rm -rf .project
    rm -rf .cproject
    rm -rf CMakeCache.txt
    rm -rf CMakeFiles
    rm -rf cmake_install.cmake
    rm -rf cppproperties_unittests
    rm -rf CTestTestfile.cmake
    rm -rf libcppproperties.so
    rm -rf Makefile
    rm -rf Testing
else
    cmake -G "Eclipse CDT4 - Unix Makefiles" -Dtest=ON
    make
    make test
fi
