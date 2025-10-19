cmake_minimum_required(VERSION 3.29)
project(KLib)

set(CMAKE_CXX_STANDARD 20)

add_executable(LibTest LibTest.cpp Library.cpp Library.h)

add_library(KLib STATIC Library.cpp Library.h)
