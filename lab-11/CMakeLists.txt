cmake_minimum_required(VERSION 3.26)
project(lab_11 C)

set(CMAKE_C_STANDARD 23)

include_directories()

add_executable(lab_11 main.c
        ../lab-11/headers/barat.h
        ../lab-11/headers/lista.h
        ../lab-11/headers/bin_s_t.h
        ../lab-11/sources/lista.c
        ../lab-11/sources/bin_s_t.c)
