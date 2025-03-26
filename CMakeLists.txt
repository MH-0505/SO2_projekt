cmake_minimum_required(VERSION 3.28)
project(Projekt_1)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(Projekt_1
        main.cpp
        Fork.cpp
        Fork.h
        Philosopher.cpp
        Philosopher.h)
