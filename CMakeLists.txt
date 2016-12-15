cmake_minimum_required(VERSION 3.2)
project(FH)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread -fpermissive")

set(SOURCE_FILES Aufgabe11/MyQueue.h Aufgabe11/Aufgabe11.1.cpp)
add_executable(FH ${SOURCE_FILES})