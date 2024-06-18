cmake_minimum_required (VERSION 3.0)

project(brass)
include_directories(./)
add_executable(main main.cpp brass.cpp)
add_executable(main2 main2.cpp brass.cpp)

set (EXECUTABLE_OUT_PATH ${PROJECT_SOURCE_DIR})
