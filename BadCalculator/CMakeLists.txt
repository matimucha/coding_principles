cmake_minimum_required(VERSION 3.0)
project(BadCalculator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES stringtonumberconverterfactory.h stringtonumberconverterfactory.cpp complex.h complex.cpp number.h number.cpp int_add.h int_add.cpp main.cpp)
add_executable(BadCalculator ${SOURCE_FILES})
