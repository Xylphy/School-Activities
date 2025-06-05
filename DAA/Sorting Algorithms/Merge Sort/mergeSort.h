#ifndef ALGORITHMS_MERGESORT_H
#define ALGORITHMS_MERGESORT_H


void printArray(int array[], int size){
    for(int i = 0; i < size; i++)
        cout << array[i] << ' ';
    cout << '\n';
}

void mergeArrays(int array[], int left, int mid, int right){
    int leftSize = mid - left + 1, rightSize = right - mid, leftArray[leftSize], rightArray[rightSize],
            leftIndex = 0, rightIndex = 0, arrayIndex = left;

    for(int i = 0; i < leftSize; i++)
        leftArray[i] = array[left + i];
    for(int i = 0; i < rightSize; i++)
        rightArray[i] = array[mid + 1 + i];

    while(leftIndex < leftSize && rightIndex < rightSize){
        if(leftArray[leftIndex] <= rightArray[rightIndex])
            array[arrayIndex++] = leftArray[leftIndex++];
        else
            array[arrayIndex++] = rightArray[rightIndex++];
    }

    while(leftIndex < leftSize)
        array[arrayIndex++] = leftArray[leftIndex++];
    while(rightIndex < rightSize)
        array[arrayIndex++] = rightArray[rightIndex++];
}

void mergeSort(int array[], int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);

        mergeArrays(array, left, mid, right);
    }
}


#endif //ALGORITHMS_MERGESORT_H
