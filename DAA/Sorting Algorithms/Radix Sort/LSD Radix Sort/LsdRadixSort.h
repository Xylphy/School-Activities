#ifndef ALGORITHMS_LSDRADIXSORT_H
#define ALGORITHMS_LSDRADIXSORT_H

int getMax(const vector<int>& arr) {
    int max = arr[0];
    for (int i = 1; i < arr.size(); i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

int getMin(const vector<int>& arr){
    int minimum = 0;
    for(int i: arr)
        if(minimum > i)
            minimum = i;
    return minimum;
}

void radixSortLSD(vector<int>& arr) {
    int min = getMin(arr);
    if(min < 0)
        for (int & i: arr)
            i -= min;
    int max = getMax(arr);
    for (int exp = 1; max / exp > 0; exp *= 10) {
        vector<int> output(arr.size());
        vector<int> count(10, 0);
        for (int i : arr)
            count[(i / exp) % 10]++;
        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];
        for (int i = (int) arr.size() - 1; i >= 0; i--)
            output[--count[(arr[i] / exp) % 10]] = arr[i];
        arr = output;
    }
    if(min < 0)
        for(int & i: arr)
            i += min;
}
void printVector(const vector<int>& arr) {
    for (int i : arr)
        cout << i << " ";
    cout << endl;
}

#endif //ALGORITHMS_LSDRADIXSORT_H
