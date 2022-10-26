cmake_minimum_required(VERSION 3.23)
project(bgsh)

set(CMAKE_CXX_STANDARD 23)

add_executable(bgsh src/main.cpp src/bgsh.cpp src/bgsh.h)
