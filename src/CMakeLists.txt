project(cpp-properties)
include_directories(../include)
add_library(cppproperties SHARED
    Properties.cpp
    PropertiesParser.cpp
    PropertiesUtils.cpp)
