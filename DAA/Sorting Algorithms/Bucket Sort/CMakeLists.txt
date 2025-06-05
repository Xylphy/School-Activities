
cmake_minimum_required(VERSION 3.28.1)
project(Algorithms)

set(CMAKE_CXX_STANDARD 26)


add_executable(Bucket_Sort_Tree
        "Tree Method/RedBlackTree.h"
        "Tree Method/Node.h"
        "Tree Method/RedBlackTree.cpp"
        "Tree Method/bucketSort.h"
        "Tree Method/main.cpp"
)

add_executable(Bucket_Sort_SLL
        "SLL Method/BucketSort.h"
        "SLL Method/main.cpp"
        "SLL Method/LinkedList.cpp"
        "SLL Method/LinkedList.h"
        "SLL Method/Node.h"
)

add_executable(Bucket_Sort_DLL
        "DLL Method/BucketSort.h"
        "DLL Method/main.cpp"
        "DLL Method/LinkedList.h"
        "DLL Method/Node.h"
        "DLL Method/LinkedList.cpp"
)

add_executable(Bucket_Sort_MultiThreading
        "Bucket Sort MultiThreading/main.cpp"
        "Bucket Sort MultiThreading/heapSort.h"
        "Bucket Sort MultiThreading/bucketSort.h"
)

add_executable(Bucket_Sort_Array
        "Array Method/bucketSort.h"
        "Array Method/main.cpp"
        "Array Method/heapSort.h"
)