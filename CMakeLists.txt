cmake_minimum_required(VERSION 3.2)
project(FH)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

set(SOURCE_FILES Aufgabe10/Aufgabe10.5.cpp)
add_executable(FH ${SOURCE_FILES})