#ifndef ALGORITHMS_QUICKSORT_H
#define ALGORITHMS_QUICKSORT_H

int partition(int array[], int left, int right){
    int pivot = array[right], low = left;

    for(int i = left; i <= right; i++)
        if(pivot > array[i])
            swap(array[i], array[low++]);

    swap(array[right], array[low]);
    return low;
}

void quickSort(int array[], int left, int right){
    if(left < right){
        int partitionIndex = partition(array, left, right);

        quickSort(array, left, partitionIndex - 1);
        quickSort(array, partitionIndex + 1, right);
    }
}

#endif //ALGORITHMS_QUICKSORT_H
