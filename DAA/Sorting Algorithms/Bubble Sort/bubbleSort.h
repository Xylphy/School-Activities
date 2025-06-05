#ifndef ALGORITHMS_BUBBLESORT_H
#define ALGORITHMS_BUBBLESORT_H


void bubbleSort(int array[], int size){
    for(int i = 0; i < size; i++)
        for(int j = 1; j < size - i; j++)
            if(array[j - 1] > array[j])
                swap(array[j], array[j - 1]);
}

#endif //ALGORITHMS_BUBBLESORT_H
