cmake_minimum_required(VERSION 3.27.8)
project(Algorithms)

set(CMAKE_CXX_STANDARD 23)

add_executable(MSD_Radix_Sort
        "MSD Radix Sort/node.h"
        "MSD Radix Sort/MSDRadixSort.cpp"
        "MSD Radix Sort/MSDRadixSort.h"
        "MSD Radix Sort/main.cpp"
)

add_executable(LSD_Radix_Sort
        "LSD Radix Sort/main.cpp"
        "LSD Radix Sort/LsdRadixSort.h"
)