cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(cppproperties VERSION 1.0.0)

option(ENABLE_TEST "Build all tests." OFF)

add_library(cppproperties
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Properties.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/PropertiesParser.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/PropertiesUtils.cpp)

target_include_directories(cppproperties
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_BINARY_DIR})

target_compile_options(cppproperties
    PRIVATE
        $<$<CXX_COMPILER_ID:GNU>:-Wall;-pedantic;-Wextra>)

target_compile_definitions(cppproperties
    PRIVATE
        $<$<CONFIG:Debug>:DEBUG;_DEBUG;_DEBUG_>
        $<$<BOOL:${WIN32}>:NOMINMAX>)

set_target_properties(cppproperties PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    POSITION_INDEPENDENT_CODE ON
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS NO)

# Add uninstall target
configure_file(cmake/CMakeUninstall.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/CMakeUninstall.cmake IMMEDIATE @ONLY)

add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/CMakeUninstall.cmake)

# Export the package for use from the build tree
export(TARGETS cppproperties FILE cmake/cpppropertiesTargets.cmake)
export(PACKAGE cppproperties)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    cmake/cpppropertiesConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion)

configure_package_config_file(
    cmake/cpppropertiesConfig.cmake.in
    cmake/cpppropertiesConfig.cmake
    INSTALL_DESTINATION lib/cmake/cppproperties/)

include(GenerateExportHeader)
generate_export_header(cppproperties)

install(TARGETS cppproperties
    EXPORT cpppropertiesTargets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include)
install(DIRECTORY include/ DESTINATION include)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/cppproperties_export.h DESTINATION include)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/cmake/cpppropertiesConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/cmake/cpppropertiesConfigVersion.cmake
    DESTINATION lib/cmake/cppproperties/)

install(EXPORT cpppropertiesTargets
    DESTINATION lib/cmake/cppproperties/)

if(ENABLE_TEST)
    enable_testing()

    add_executable(cppproperties_unittests
        ${CMAKE_CURRENT_SOURCE_DIR}/test/PropertiesTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/PropertiesParserTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/test/PropertiesUtilsTest.cpp)
    target_link_libraries(cppproperties_unittests PRIVATE cppproperties)

    find_package(GTest 1.7.0)
    if(GTEST_FOUND)
        target_include_directories(cppproperties_unittests PUBLIC ${GTEST_INCLUDE_DIRS})
        target_link_libraries(cppproperties_unittests PRIVATE ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES})
    else()
        add_subdirectory(lib/gtest-1.7.0)
        target_include_directories(cppproperties_unittests PUBLIC ${gtest_SOURCE_DIR}/include)
        target_link_libraries(cppproperties_unittests PRIVATE gtest gtest_main)
    endif()

    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/test/properties
         DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/test/)

    add_test(NAME cppproperties_unittests COMMAND cppproperties_unittests)
endif()
