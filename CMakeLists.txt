cmake_minimum_required(VERSION 3.29)
project(KLib)

set(CMAKE_CXX_STANDARD 20)

add_executable(LibFormat LibFormat.cpp)
add_executable(LibTest LibTest.cpp)

add_library(KLib STATIC LibFormat.cpp)