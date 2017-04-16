cmake_minimum_required(VERSION 3.6)
project(proj5)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp graph.h maze.h)
add_executable(proj5 ${SOURCE_FILES})