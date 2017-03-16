cmake_minimum_required(VERSION 3.6)
project(proj3)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Dictionary.cpp Dictionary.h Grid.cpp Grid.h Heap.cpp Heap.h)
add_executable(proj3 ${SOURCE_FILES})