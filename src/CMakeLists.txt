project(cpp-properties)
include_directories(../include)
add_library(cppproperties SHARED
    Properties.cpp
    PropertiesParser.cpp)
add_library(cppproperties STATIC
    Properties.cpp
    PropertiesParser.cpp)
