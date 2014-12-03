cmake_minimum_required(VERSION 2.8)
project(cpp-properties)
include_directories(${cpp-properties_SOURCE_DIR}/include)
add_library(cppproperties SHARED
    ${cpp-properties_SOURCE_DIR}/src/Properties.cpp
    ${cpp-properties_SOURCE_DIR}/src/PropertiesParser.cpp
    ${cpp-properties_SOURCE_DIR}/src/PropertiesUtils.cpp)

add_subdirectory(lib/gtest-1.7.0)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include)
add_executable(cppproperties_unittests
    ${cpp-properties_SOURCE_DIR}/test/PropertiesTest.cpp
    ${cpp-properties_SOURCE_DIR}/test/PropertiesParserTest.cpp
    ${cpp-properties_SOURCE_DIR}/test/PropertiesUtilsTest.cpp)
target_link_libraries(cppproperties_unittests gtest gtest_main)
target_link_libraries(cppproperties_unittests cppproperties)
add_test(NAME cppproperties_unittests COMMAND cppproperties_unittests)
