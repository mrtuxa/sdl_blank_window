cmake_minimum_required(VERSION 3.25)
project(sdl2)

set(CMAKE_CXX_STANDARD 98)

find_package(SDL2 REQUIRED)

add_executable(sdl2 src/main.cpp src/include/screen.hpp)
