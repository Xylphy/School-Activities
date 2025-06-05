#ifndef ALGORITHMS_SELECTIONSORT_H
#define ALGORITHMS_SELECTIONSORT_H

void selectionSort(int array[], int size){
    for(int i = 0; i < size - 1; i++) {
        int smallest = i;
        for(int j = i + 1; j < size; j++)
            if(array[j] < array[smallest])
                smallest = j;
        if(smallest != i)
            swap(array[i], array[smallest]);
    }

}
#endif //ALGORITHMS_SELECTIONSORT_H
