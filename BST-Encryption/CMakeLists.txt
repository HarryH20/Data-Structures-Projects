cmake_minimum_required(VERSION 3.24)
project(proj3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-static")
add_executable(proj3 driver-proj3.cpp bst-prof-proj3.h bst-student-proj3.h)
