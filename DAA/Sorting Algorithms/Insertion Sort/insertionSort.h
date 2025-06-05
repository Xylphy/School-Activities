#ifndef ALGORITHMS_INSERTIONSORT_H
#define ALGORITHMS_INSERTIONSORT_H

void insertionSort(int array[], int size){
    for(int i = 1; i < size; i++)
        if(array[i - 1] > array[i]){
            int temp = array[i], j = i - 1;
            for(; j >= 0; j--) {
                if (array[j] > temp)
                    array[j + 1] = array[j];
                else break;
            }
            array[j + 1] = temp;
        }
}

#endif //ALGORITHMS_INSERTIONSORT_H
