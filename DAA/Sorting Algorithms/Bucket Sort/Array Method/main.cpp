#include <iostream>
#define INTERVAL 10
using namespace std;
#include "bucketSort.h"
int main(){
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int array[size];
    cout << "Enter the elements of the array: ";
    for(int & i: array)
        cin >> i;

    cout << "Original array: ";
    for(int i: array)
        cout << i << " ";

    bucketSort(array, size);

    cout << "\nSorted array: ";
    for(int i: array)
        cout << i << " ";
    return 0;
}