cmake_minimum_required(VERSION 3.28.1)
project(Algorithms)

set(CMAKE_CXX_STANDARD 26)

add_subdirectory("Radix Sort")

add_subdirectory("Bucket Sort")

add_executable(Shell_Sort
        "Shell Sort/shellSort.h"
        "Shell Sort/main.cpp"
)

add_executable(Selection_Sort
        "Selection Sort/selectionSort.h"
        "Selection Sort/main.cpp"
)

add_executable(Quick_Sort
        "Quick Sort/quickSort.h"
        "Quick Sort/main.cpp"
)

add_executable(Merge_Sort
        "Merge Sort/mergeSort.h"
        "Merge Sort/main.cpp"
)

add_executable(Insertion_Sort
        "Insertion Sort/main.cpp"
        "Insertion Sort/insertionSort.h"
)

add_executable(Heap_Sort
        "Heap Sort/main.cpp"
        "Heap Sort/heapSort.h"
)

add_executable(Counting_Sort
        "Counting Sort/main.cpp"
        "Counting Sort/countingSort.h"
)

add_executable(Bubble_Sort
        "Bubble Sort/main.cpp"
        "Bubble Sort/bubbleSort.h"
)