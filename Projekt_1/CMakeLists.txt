cmake_minimum_required(VERSION 3.28)
project(Projekt_1)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(Projekt_1
        main.cpp
        Fork.cpp
        Fork.h
        Philosopher.cpp
        Philosopher.h)
