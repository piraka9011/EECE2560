cmake_minimum_required(VERSION 3.6)
project(algo_ws)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/main.cpp src/code.cpp include/code.h)
add_executable(algo_ws ${SOURCE_FILES})