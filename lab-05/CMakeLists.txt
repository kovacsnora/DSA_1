cmake_minimum_required(VERSION 3.26)
project(lab_05 C)

set(CMAKE_C_STANDARD 23)

include_directories(headers)

add_executable(lab_05 main.c
        headers/stack.h
        sources/stack.c)
