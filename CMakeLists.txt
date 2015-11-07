cmake_minimum_required(VERSION 3.2)
project(RayTracer)

#Environment Setup,  add C++11, debugging symbols, all warnings
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall -fno-strict-aliasing ")

add_subdirectory(src)
add_subdirectory(app)
add_subdirectory(test)

