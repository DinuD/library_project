cmake_minimum_required(VERSION 3.7)
project(library_project)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp structuri.h operatii.cpp operatii.h)
add_executable(library_project ${SOURCE_FILES})