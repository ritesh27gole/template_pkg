cmake_minimum_required(VERSION 3.0.2)
project(your_pkg_name)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS roscpp std_msgs)

catkin_package()

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(controller src/main.cpp)
target_link_libraries(controller ${catkin_LIBRARIES})

