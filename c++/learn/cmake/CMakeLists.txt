cmake_minimum_required (VERSION 2.8)

project (demo)
find_package(OpenCV 4.9.0 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(./include)
add_executable(main main.cpp add.cpp)
target_link_libraries(main ${OpenCV_LIBS})

# ament_target_dependencies(main OpenCV)

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})
