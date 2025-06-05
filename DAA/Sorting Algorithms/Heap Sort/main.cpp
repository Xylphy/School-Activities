#include <iostream>
using namespace std;
#include "heapSort.h"


int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int array[size];
    cout << "Enter the elements of the array: ";
    for(int a = 0; a < size; a++)
        cin >> array[a];
    heapSort(array, size);
    for(int i: array){
        cout << i << " ";
    }
    return 0;
}