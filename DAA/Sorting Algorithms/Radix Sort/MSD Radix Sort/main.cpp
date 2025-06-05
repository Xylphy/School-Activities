#include "MSDRadixSort.h"

int main() {
    vector<int> sortedArray;
    auto* msdRadixSort = new MSDRadixSort();
    int size, c;
    cout << "Enter the size of the array: ";
    cin >> size;

    cout << "Enter the elements of the array: ";
    for(int b = 0; b < size; b++) {
        cin >> c;
        msdRadixSort->insert(c);
    }

    cout << "Original array:\n";
    msdRadixSort->print();

    msdRadixSort->sort();

    cout << "\nSorted array:\n";
    msdRadixSort->print();

    return 0;
}