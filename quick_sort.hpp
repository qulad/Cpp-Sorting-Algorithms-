#include <algorithm>

template <typename T> void quickSort_SingleThread(T [], int, int);
template <typename T> int partition(T [], int, int);

template <typename T> void quickSort_SingleThread(T arr[], int start, int end) {
    if (start < end) {
        int pivot_index = partition(arr, start, end);

        quickSort_SingleThread(arr, start, pivot_index-1);
        quickSort_SingleThread(arr, pivot_index+1, end);
    }
};

template <typename T> int partition(T arr[], int start, int end) {
    T pivot = arr[end];
    int i = start-1;
    for (int j = start; j < end; j++) {
        if (arr[j] <= pivot) {
            i++;
            T temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    T temp = arr[i+1];
    arr[i+1] = arr[end];
    arr[end] = temp;
    return i + 1;
};

