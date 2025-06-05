#include <iostream>
#include <vector>
using namespace std;
#include "countingSort.h"

int main() {
    vector<int> arr;
    int a, c;
    cout << "Enter the size of the array: ";
    cin >> a;
    cout << "Enter the elements of the array: ";
    for(int b = 1; b <= a; b++){
        cin >> c;
        arr.push_back(c);
    }
    cout << "Original array: ";
    printVector(arr);
    countingSort(arr);
    cout << "Sorted array: ";
    printVector(arr);
    return 0;
}