
template <typename T> void selectionSort_SingleThread(T [], unsigned int);

template <typename T> void selectionSort_SingleThread(T arr[], unsigned int size) {
    for (unsigned int iteration = 0; iteration < size-1; iteration++) {
        unsigned int minimum_index = iteration;
        for (unsigned int index = minimum_index+1; index < size; index++) {
            if (arr[index] < arr[minimum_index]) {
                T temp = arr[index];
                arr[index] = arr[minimum_index];
                arr[minimum_index] = temp;
            }
        }
    }
}