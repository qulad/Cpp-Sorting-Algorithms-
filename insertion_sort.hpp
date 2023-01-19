
template <typename T> void insertionSort_SingleThread(T [], unsigned int);

template <typename T> void insertionSort_SingleThread(T arr[], unsigned int size) {
    for (unsigned int i=1; i < size; i++) {
        for (unsigned int j=i; j > 0; j--) {
            if (arr[j-1] > arr[j]) {
                T temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
            else break;
        }
    }
};
