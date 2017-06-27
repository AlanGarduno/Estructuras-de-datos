cmake_minimum_required(VERSION 3.5)
project(arbolCasiCompleto)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(arbolCasiCompleto ${SOURCE_FILES})