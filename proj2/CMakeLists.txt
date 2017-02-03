cmake_minimum_required(VERSION 3.6)
project(flip)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp card.cpp deck.cpp)
add_executable(flip ${SOURCE_FILES})