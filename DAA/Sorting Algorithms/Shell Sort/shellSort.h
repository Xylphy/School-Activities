#ifndef ALGORITHMS_SHELLSORT_H
#define ALGORITHMS_SHELLSORT_H

void shellSort(int array[], int size){
    for(int gap = size / 2; gap > 0; gap /= 2)
        for(int i = gap; i < size; i++)
            if(array[i] < array[i - gap]) {
                int j, temp = array[i];
                for (j = i - gap; j >= 0; j -= gap) {
                    if(array[j] > temp)
                        array[j + gap] = array[j];
                    else break;
                }
                array[j + gap] = temp;
            }
}

#endif //ALGORITHMS_SHELLSORT_H
