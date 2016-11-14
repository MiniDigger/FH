cmake_minimum_required(VERSION 3.2)
project(FH)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Aufgabe6/Aufgabe6.2.cpp Aufgabe6/meinstring.cpp Aufgabe6/Teilnehmer.cpp)
add_executable(FH ${SOURCE_FILES})