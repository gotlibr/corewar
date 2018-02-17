cmake_minimum_required(VERSION 3.9)
project(corewar C)

set(CMAKE_C_STANDARD 99)

add_executable(corewar src/main.c includes/func.h)
