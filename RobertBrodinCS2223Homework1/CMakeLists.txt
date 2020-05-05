cmake_minimum_required(VERSION 3.15)
project(2020HW1starter_3)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(2020HW1starter_3
        Debug/src/2020HW1starter.o
        Debug/src/HW1.o
        Debug/src/production.o
        Debug/src/tests.o
        Debug/2020HW1starter.exe
        src/2020HW1starter.c
        src/HW1.c
        src/production.c
        src/production.h
        src/tests.c
        src/tests.h
        src/house.c src/house.h src/layout.c src/layout.h src/search.c src/search.h)
