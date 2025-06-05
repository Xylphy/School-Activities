#ifndef ALGORITHMS_HEAPSORT_H
#define ALGORITHMS_HEAPSORT_H

typedef long long int ll;

void heapify(deque<int> & arr, ll & n, ll i) {
    ll largest = i, left = 2 * i + 1, right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(deque<int> & arr, ll & n) {
    for (ll i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

}
void heapSort(deque<int> & arr, ll n) {
    buildHeap(arr, n);
    for (ll i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}


#endif //ALGORITHMS_HEAPSORT_H
