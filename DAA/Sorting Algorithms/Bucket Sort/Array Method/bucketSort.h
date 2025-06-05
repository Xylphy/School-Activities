#ifndef ALGORITHMS_BUCKETSORT_H
#define ALGORITHMS_BUCKETSORT_H
#include <cmath>
#include <vector>
#include <deque>
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

void bucketSort(int array[], int size) {
    int minimum = findMin(array, size);
    if (minimum < 0)
        for (int i = 0; i < size; ++i)
            array[i] -= minimum;

    int maximum = findMax(array, size), range = (int) ceil((double) maximum / INTERVAL) + 1, index = 0;
    vector <deque<int>> buckets(range);

    for (int i = 0; i < size; ++i)
        buckets[array[i] / INTERVAL].push_back(array[i]);

    for (deque<int> &v: buckets) {
        heapSort(v, v.size());
        while (!v.empty()) {
            array[index++] = v.front();
            v.pop_front();
        }
    }

    if(minimum < 0)
        for (int i = 0; i < size; ++i)
            array[i] += minimum;
}
#endif //ALGORITHMS_BUCKETSORT_H