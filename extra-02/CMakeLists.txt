cmake_minimum_required(VERSION 3.26)
project(extra_02 C)

set(CMAKE_C_STANDARD 23)

include_directories(headers)

add_executable(extra_02 main.c
headers/labda_simple.h
sources/labda_simple.c)
