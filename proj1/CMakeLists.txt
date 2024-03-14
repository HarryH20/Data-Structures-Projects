cmake_minimum_required(VERSION 3.24)
project(proj1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-static")

add_executable(proj1 main.cpp location-proj1.h location-proj1.cpp driver-proj1.cpp maze-proj1.h maze-proj1.cpp stack-proj1.h stack-proj1.cpp mainmaze.cpp)
