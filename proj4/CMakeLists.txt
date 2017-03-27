cmake_minimum_required(VERSION 3.6)
project(proj4)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Board.cpp)
add_executable(proj4 ${SOURCE_FILES})