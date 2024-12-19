cmake_minimum_required(VERSION 3.29)
project(KLib)

set(CMAKE_CXX_STANDARD 20)

add_library(KLib STATIC library.cpp
        install.cpp)
add_executable(format install.cpp)