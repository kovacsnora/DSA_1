cmake_minimum_required(VERSION 3.26)
project(lab_07 C)

set(CMAKE_C_STANDARD 23)

include_directories(headers)

add_executable(lab_07 main.c
        sources/labda_tomb.c
        headers/labda_tomb.h
        ../lab-01/headers/labda_circular.h
        ../lab-01/sources/labda_circular.c

)
