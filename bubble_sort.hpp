#include <thread>
#include <mutex>

template <typename T> void bubbleSort_singleThread(T [], unsigned int);

void increment_iteration(unsigned int &);

void increment_index(unsigned int &);

void reset_index(unsigned int &index);

template <typename T> T get_element(T [], unsigned int);

template <typename T> void swap_elements(T [], unsigned int, unsigned int);

template <typename T> void bubble_iteration(T [], unsigned int);

template <typename T> void bubbleSort_multiThread(T [], unsigned int);

template <typename T> void bubbleSort_singleThread(T arr[] , unsigned int size) {
    bool swapped = false;
    for (unsigned int iteration = 1; iteration < size; iteration++) {
        swapped = false;
        for (unsigned int index = 0; index < size - iteration; ++index) {
            if (arr[index] > arr[index+1]) {
                int temp = arr[index];
                arr[index] = arr[index+1];
                arr[index+1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
};

std::mutex iteration_mutex, index_mutex, element_mutex;

void increment_iteration(unsigned int &variable) {
    iteration_mutex.lock();
    variable++;
    iteration_mutex.unlock();
};

void increment_index(unsigned int &index) {
    index_mutex.lock();
    index++;
    index_mutex.unlock();
};

void reset_index(unsigned int &index) {
    index_mutex.lock();
    index = 0;
    index_mutex.unlock();
};

template <typename T> T get_element(T arr[], unsigned int index) {
    element_mutex.lock();
    T temp = arr[index];
    element_mutex.unlock();
    return temp;
};

template <typename T> void swap_elements(T arr[], unsigned int i1, unsigned int i2) {
    element_mutex.lock();
    T temp = arr[i1];
    arr[i1] = arr[i2];
    arr[i2] = temp;
    element_mutex.unlock();
};

template <typename T> void bubble_iteration(T arr[], unsigned int size) {
    bool swapped = false;
    unsigned int iteration = 1;
    unsigned int index = 0;
    while (iteration < size) {
        reset_index(index);
        while(index < size - iteration) {
            if (get_element(arr, index) > get_element(arr, index+1)) {
                swap_elements(arr, index, index+1);
                swapped = true;
            }
            increment_index(index);
        }
        if (!swapped) break;
        increment_iteration(iteration);
    }
};

template <typename T> void bubbleSort_multiThread(T arr[], unsigned int size) {
    unsigned int thread_count = std::thread::hardware_concurrency();
    static const unsigned int s = size;
    std::thread threads[thread_count];
    for (unsigned int i = 0; i < thread_count; i++) {
        threads[i] = std::thread(bubble_iteration<T>, &arr[0], size);
    }
    for (unsigned int i = 0; i < thread_count; i++) {
        threads[i].join();
    }
};