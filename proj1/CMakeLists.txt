cmake_minimum_required(VERSION 3.6)
project(mastermind)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES src/main.cpp src/code.cpp src/mastermind.cpp src/response.cpp)
add_executable(mastermind ${SOURCE_FILES})