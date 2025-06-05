#define INTERVAL 10
#include "BucketSort.h"
int main(){
    int size, element;
    cout << "Enter the size of the array: ";
    cin >> size;
    cout << "Enter the elements of the array: ";
    vector<int> arr(size);
    for(int & i: arr)
        cin >> i;
    cout << "Original array: ";
    printVector(arr);
    bucketSort(arr);
    cout << "Sorted array: ";
    printVector(arr);
    return 0;
}