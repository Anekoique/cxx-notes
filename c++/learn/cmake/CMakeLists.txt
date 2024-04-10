cmake_minimum_required (VERSION 2.8)

project (demo)

include_directories(./include)
add_executable(main main.cpp add.cpp)

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})
