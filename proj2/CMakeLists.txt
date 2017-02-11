cmake_minimum_required(VERSION 3.6)
project(flip)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp card.cpp deck.cpp d_node.h LinkedList.cpp LinkedList.h)
add_executable(flip ${SOURCE_FILES})