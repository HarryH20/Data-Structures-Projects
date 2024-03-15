cmake_minimum_required(VERSION 3.24)
project(proj5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-static")
add_executable(proj5 main.cpp process-proj5.h arrayheap-prof-proj5.h arrayheap-student-proj5.h process-proj5.cpp driver-proj5.cpp)
