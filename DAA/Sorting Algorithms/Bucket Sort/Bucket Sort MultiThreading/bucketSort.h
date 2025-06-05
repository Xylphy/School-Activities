#ifndef ALGORITHMS_BUCKETSORT_H
#define ALGORITHMS_BUCKETSORT_H
#include <cmath>
#include <thread>
#include <functional>
#include "heapSort.h"

int findMax(const int array[], int size){
    int maximum = array[0];
    for (int i = 1; i < size; ++i)
        if(maximum < array[i])
            maximum = array[i];
    return maximum;
}

int findMin(const int array[], int size){
    int minimum = array[0];
    for(int i = 1; i < size; i++)
        if(minimum > array[i])
            minimum = array[i];
    return minimum;
}

void worker(vector<deque<int>> &arr, int start, int end) {
    for(; start <= end; start++)
        if (!arr[start].empty())
            heapSort(arr[start], arr[start].size());
}

void bucketSort(int array[], int size, int & threads) {

    int minimum = findMin(array, size);
    if (minimum < 0)
        for (int i = 0; i < size; ++i)
            array[i] -= minimum;

    int maximum = findMax(array, size), range = (maximum + INTERVAL) / INTERVAL, index = 0;

    vector <deque<int>> buckets(range);
    for (int i = 0; i < size; ++i)
        buckets[array[i] / INTERVAL].push_back(array[i]);


    int interval = (range + threads - 1) / threads;
    thread thrd[threads];
    for(int i = 0; i < threads; i++) {
        int start = interval * i, end = min(start + interval - 1, range - 1);
        thrd[i] = thread([&buckets, start, end] {
            return worker(buckets, start, end);
        });
    }

    for(int i = 0; i < threads; i++)
        thrd[i].join();

    for(deque<int> d: buckets){
        while(!d.empty()){
            array[index++] = d.front();
            d.pop_front();
        }
    }
    if(minimum < 0)
        for (int i = 0; i < size; ++i)
            array[i] += minimum;
}


#endif //ALGORITHMS_BUCKETSORT_H