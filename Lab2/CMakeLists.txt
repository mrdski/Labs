cmake_minimum_required(VERSION 3.21)
project(Lab2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab2 main.cpp cmake-build-debug/Vehicle.cpp cmake-build-debug/Vehicle.h cmake-build-debug/Showroom.cpp cmake-build-debug/Showroom.h cmake-build-debug/Dealership.cpp cmake-build-debug/Dealership.h)
