#ifndef ALGORITHMS_BUCKETSORT_H
#define ALGORITHMS_BUCKETSORT_H
#include <vector>
#include <cmath>
#include "LinkedList.h"
int findMin(vector<int>& arr){
    int minimum = arr[0];
    for(const int i: arr)
        if(minimum > i)
            minimum = i;
    return minimum;
}

int findMax(vector<int> & arr){
    int maximum = arr[0];
    for(const int i: arr)
        if(maximum < i)
            maximum = i;
    return maximum;
}

void bucketSort(vector<int>& arr){
    int minimum = findMin(arr);
    vector<int> out;

    if(minimum < 0)
        for(int & i: arr)
            i -= minimum;

    int maximum = findMax(arr), range = (int)ceil((double) maximum / INTERVAL) + 1;
    LinkedList** lists = new LinkedList*[range];

    for(int i = 0; i < range; i++)
        lists[i] = new LinkedList();

    for(int i: arr)
        lists[i / INTERVAL]->insertNum(i);

    for(int i = 0; i < range; i++)
        while(!lists[i]->isEmpty())
            out.push_back(lists[i]->removeHead());

    if(minimum < 0)
        for(int & i: out)
            i += minimum;

    arr = out;

    for(int i = 0; i < range; i++)
        delete lists[i];
    delete[] lists;
}

void printVector(const vector<int>& arr){
    for(const int i: arr)
        cout << i << " ";
    cout << '\n';
}

#endif //ALGORITHMS_BUCKETSORT_H
