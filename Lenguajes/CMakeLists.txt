cmake_minimum_required(VERSION 3.6)
project(Lenguajes)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Lenguajes ${SOURCE_FILES})