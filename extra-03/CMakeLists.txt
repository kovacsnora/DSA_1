cmake_minimum_required(VERSION 3.26)
project(extra-03 C)

set(CMAKE_C_STANDARD 23)

include_directories(headers)


add_executable(extra-03 main.c
        headers/student.h
        sources/student.c)