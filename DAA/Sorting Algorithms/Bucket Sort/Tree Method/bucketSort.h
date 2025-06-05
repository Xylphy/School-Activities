#ifndef ALGORITHMS_BUCKETSORT_H
#define ALGORITHMS_BUCKETSORT_H

void printVector(const vector<int>& arr){
    for(const int i: arr)
        cout << i << ' ';
    cout << '\n';
}

int minimumNum(vector<int>& arr){
    int minimum = 0;
    for(int i: arr)
        if(i < minimum)
            minimum = i;
    return minimum;
}

int bucketNumber(const vector<int>& arr){
    int max = 0;
    for (const int i: arr) {
        int num = i / INTERVAL;
        if(num > max)
            max = num;
    }
    return max + 1;
}

void bucketSort(vector<int>& arr){
    int minimum = minimumNum(arr);
    if(minimum < 0)
        for(int & i: arr)
            i -= minimum;
    vector<RedBlackTree> buckets(bucketNumber(arr));
    vector<int> output;

    for(int i: arr)
        buckets[i / INTERVAL].insert(i);
    for(RedBlackTree rbt: buckets)
        while (!rbt.isEmpty())
            output.push_back(rbt.minimumValue());

    if(minimum < 0)
        for (int & i: output)
            i += minimum;
    arr = output;
}

#endif //ALGORITHMS_BUCKETSORT_H
