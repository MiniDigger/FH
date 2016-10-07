cmake_minimum_required(VERSION 3.2)
project(FH)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Aufgabe2/Aufgabe2.3.cpp)
add_executable(FH ${SOURCE_FILES})