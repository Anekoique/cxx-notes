cmake_minimum_required (VERSION 3.0)

project(brass)
include_directories(./)
add_executable(main main.cpp brass.cpp)

set (EXECUTABLE_OUT_PATH ${PROJECT_SOURCE_DIR})
