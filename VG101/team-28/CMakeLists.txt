cmake_minimum_required(VERSION 3.20)
project(Tank_War)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-O2")

include_directories(.)

add_executable(tankwar src/main.cpp) # modify this line to include all your source codes
