cmake_minimum_required(VERSION 3.2)
project(FH)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Aufgabe7/Person.cpp Aufgabe7/Person.h Aufgabe7/Student.cpp Aufgabe7/Student.h Aufgabe7/Professor.cpp Aufgabe7/Professor.h Aufgabe7/Aufgabe7.1.cpp)
add_executable(FH ${SOURCE_FILES})