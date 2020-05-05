cmake_minimum_required(VERSION 3.15)
project(src C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(src
        HW3StarterGetAClue.c
        production.c
        production.h
        Room.c
        Room.h
        tests.c
        tests.h)
