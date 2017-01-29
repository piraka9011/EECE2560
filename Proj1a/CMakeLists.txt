cmake_minimum_required(VERSION 3.6)
project(Proj1a)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/main.cpp src/code.cpp src/mastermind.cpp src/response.cpp include/response.h)
add_executable(Proj1a ${SOURCE_FILES})