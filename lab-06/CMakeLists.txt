cmake_minimum_required(VERSION 3.26)
project(lab_06 C)

set(CMAKE_C_STANDARD 23)

include_directories(headers)

add_executable(lab_06 main.c
        sources/simple_queue.c
        headers/simple_queue.h
        headers/circular_queue.h
        sources/circular_queue.c
        ../lab-07/headers/labda_tomb.h
        ../lab-07/sources/labda_tomb.c
)
