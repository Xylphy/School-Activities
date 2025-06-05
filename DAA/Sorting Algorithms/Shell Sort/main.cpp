#include <iostream>

using namespace std;
#include "shellSort.h"

int main(){
    int size;
    cout << "Enter size of the array: ";
    cin >> size;
    int array[size];
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < size; i++)
        cin >> array[i];

    shellSort(array, size);

    cout << "Sorted array: ";
    for(int i: array)
        cout << i << ' ';

    return 0;
}
