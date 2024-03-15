cmake_minimum_required(VERSION 3.24)
project(proj4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-static")
add_executable(proj4 driver-proj4.cpp avl-tree-prof-proj4.h avl-tree-student-proj4.h)
