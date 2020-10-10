cmake_minimum_required(VERSION 3.15)
project(discrete C)

set(CMAKE_C_STANDARD 99)

add_executable(discrete src/main.c src/fileIO.c src/fileIO.h src/set.c src/set.h src/operations.c src/operations.h src/validation.c src/validation.h src/global.h)