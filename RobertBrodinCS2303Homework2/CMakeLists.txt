cmake_minimum_required(VERSION 3.15)
project(RobertBrodinCS2303Homework2 C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(RobertBrodinCS2303Homework2
        src/2020HW2starter.c
        src/LinkedList.c
        src/LinkedList.h
        src/marker.c
        src/marker.h
        src/production.c
        src/production.h
        src/space.c
        src/space.h
        src/tests.c
        src/tests.h
        src/TMSName.h src/matrix.c src/matrix.h src/RobLinkedListClass.c src/RobLinkedListClass.h)
