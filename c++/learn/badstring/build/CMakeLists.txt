cmake_minimum_required (VERSION 2.8)

project(badstring)
include_directories(./)
add_executable(main main.cpp stringbad.cpp)

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})
