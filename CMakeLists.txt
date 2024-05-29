cmake_minimum_required(VERSION 3.28)
project(kolokvij2)

set(CMAKE_CXX_STANDARD 17)

add_executable(kolokvij2 main.cpp
        Date.h
        UnparseableDateException.h
        FileNotFoundException.h
        Fuel.h)
