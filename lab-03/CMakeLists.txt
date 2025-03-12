cmake_minimum_required(VERSION 3.26)
project(lab_03 C)

set(CMAKE_C_STANDARD 23)

include_directories(headers)


add_executable(lab_03 main.c
        headers/student.h
        sources/student.c)