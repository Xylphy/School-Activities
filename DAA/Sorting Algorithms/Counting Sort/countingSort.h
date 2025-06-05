#ifndef ALGORITHMS_COUNTINGSORT_H
#define ALGORITHMS_COUNTINGSORT_H

void printVector(const vector<int>& array){
    for(int i: array)
        cout << i << ' ';
    cout << '\n';
}

int maxElement(const vector<int>& array){
    int max = array[0];
    for(int i = 1; i < array.size(); i++)
        if(array[i] > max)
            max = array[i];
    return max;
}

void countingSort(vector<int>& array){
    int max = maxElement(array);
    vector<int> countArray(max + 1, 0);
    vector<int> duplicateArray(array.size());

    for(int i: array)
        countArray[i]++;
    for(int i = 1; i < max + 1; i++)
        countArray[i] += countArray[i - 1];
    for(int i = (int)array.size() - 1; i >= 0; i--)
        duplicateArray[--countArray[array[i]]] = array[i];

    array = duplicateArray;
}

#endif //ALGORITHMS_COUNTINGSORT_H
