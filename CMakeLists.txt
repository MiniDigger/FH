cmake_minimum_required(VERSION 3.2)
project(FH)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Aufgabe8/meinstringMain.cpp Aufgabe8/meinstring.cpp)
add_executable(FH ${SOURCE_FILES})