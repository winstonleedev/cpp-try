cmake_minimum_required(VERSION 3.10)
project(cpp_try)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SRC_FILES *.cpp)
file(GLOB HDR_FILES *.h)

add_executable(cpp_try
    Try.h
    example.cpp
)