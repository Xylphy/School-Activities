#include <iostream>
#include "RedBlackTree.h"
#include <vector>
#include <cmath>
#define INTERVAL 10
using namespace std;
#include "bucketSort.h"


int main(){
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    vector<int> arr(size);
    cout << "Enter the elements of the array: ";
    for(int & i: arr)
        cin >> i;
    cout << "Original array: ";
    printVector(arr);
    bucketSort(arr);
    cout << "Sorted array: ";
    printVector(arr);
    return 0;
}