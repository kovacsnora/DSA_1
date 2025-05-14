cmake_minimum_required(VERSION 3.26)
project(lab_08 C)

set(CMAKE_C_STANDARD 23)

include_directories(headers)

add_executable(lab_08 main.c
        headers/labda_stack.h
        sources/labda_stack.c)
