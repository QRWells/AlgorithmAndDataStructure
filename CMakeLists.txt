cmake_minimum_required(VERSION 3.16)
project(AlgorithmAndDataStructure C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(src)

add_executable(AlgorithmAndDataStructure
        src/woj_2_4.c)
