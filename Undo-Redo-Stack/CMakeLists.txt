cmake_minimum_required(VERSION 3.24)
project(project0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-static")
add_executable(project0 driver-proj0.cpp)
