#include "Array.h"
#include <iostream>
#include <string>

namespace dsa {
    template<typename T>
    Array<T>::Array() {
        capacity = 10; // initial capacity
        size = 0; // number of elements
        data = new T[capacity]; // allocate heap memory
    };

    template<typename T>
    Array<T>::~Array() {
        delete[] data; // free heap memory
    };

    template<typename T>
    void Array<T>::resize() {
        /*
        Algorithm to resize the array:
            1. double the capacity
            2. allocate larger heap memory
            3. copy old elements to new memory
            4. free old memory
            5. point data to new memory
        */
       capacity *= 2;
       T* newData = new T[capacity];

       for (int i = 0; i < size; i++)
       {
        newData[i] = data[i];
       }
       delete[] data;
       data = newData;
    };

    template<typename T>
    void Array<T>::shiftRight(int index) {
        /*
        Algorithm to shift elements right from index:
            1. iterate from size-1 down to index
            2. move each element one position to the right
        */
         for (int i = size - 1; i >= index; i--)
         {
            data[i + 1] = data[i];
         }
    };

    template<typename T>
    void Array<T>::shiftLeft(int index) {
        /*
        Algorithm to shift elements left from index:
            1. iterate from index to size-1
            2. move each element one position to the left
        */
        for (int i = index; i < size - 1; i++)
        {
            data[i] = data[i + 1];
        }
    };

    template<typename T>
    void Array<T>::push(T value) {
        /*
        Algorithm to add an element at the end:
            1. check if size == capacity
            2. if full, call resize()
            3. add element at data[size]
            4. increment size
        */
       if (size == capacity)
       {
        resize();
       } 
       data[size++] = value;
    };

    template<typename T>
    T Array<T>::pop() {
        /*
        Algorithm to remove and return the last element:
            1. check if array is empty
            2. decrement size
            3. return data[size]
        */
       if(isEmpty()) {
            throw std::out_of_range("Cannot pop from empty array");
       }
       return data[--size];
    };

    template<typename T>
    void Array<T>::insert(int index, T value) {
        /*
        Algorithm to insert an element at index:
            1. check if size == capacity
            2. if full, call resize()
            3. shift elements right from index
            4. set data[index] = value
            5. increment size
        */
       if (index < 0 || index > size) {
        throw std::out_of_range("Invalid index");
       }
       if (size == capacity) {
        resize();
       }
       shiftRight(index);
       data[index] = value;
        size++;
    };

    template<typename T>
    T Array<T>::remove(int index) {
        /*
        Algorithm to remove and return element at index:
            1. store data[index] in temp
            2. shift elements left from index
            3. decrement size
            4. return temp
        */
        if (index < 0 || index >= size) {
            throw std::out_of_range("Invalid index");
        }
       T temp = data[index];
       shiftLeft(index);
        size--;
        return temp;
    };

    template<typename T>
    T Array<T>::get(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Invalid index");
        }
        return data[index];
    };

    template<typename T>
    void Array<T>::set(int index, T value) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Invalid index");
        }
        data[index] = value;
    };

    template<typename T>
    int Array<T>::linearSearch(T value) {
        /*
        Algorithm for linear search:
            1. iterate through each element
            2. if element matches value, return index
            3. if not found, return -1
        */
       for (int i = 0; i < size; i++) {
            if (data[i] == value) { return i;}
       }
        return -1;
    };

    template<typename T>
    int Array<T>::binarySearch(T value) {
        /*
        Algorithm for binary search (array must be sorted):
            1. set low = 0, high = size - 1
            2. while low <= high:
                a. mid = (low + high) / 2
                b. if data[mid] == value, return mid (found)
                c. if data[mid] < value, set low = mid + 1 (search right half)
                d. else set high = mid - 1 (search left half)
            3. if not found, return -1
        */
       int low = 0;
       int high = size - 1;
       while (low <= high)
       {
            int mid = (low + high) / 2;
            if (data[mid] == value) {
                return mid;
            }
            else if (data[mid] < value)
            {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
       }
       return -1;
    };

    template<typename T>
    void Array<T>::bubbleSort() {
        /*
        Algorithm for bubble sort:
            1. iterate through the array multiple times
            2. in each pass, compare adjacent elements
            3. if left > right, swap them
            4. repeat until no swaps are needed
        */
       for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (data[j] > data[j + 1]) {
                    T temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
    };

    template<typename T>
    void Array<T>::insertionSort() {
        /*
        Algorithm for insertion sort:
            1. iterate from second element to end
            2. for each element, compare with elements before it
            3. shift larger elements right
            4. insert the element at correct position
        */
        for (int i = 1; i < size; i++) {
        T key = data[i];
        int j = i - 1;
        // shift elements right
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key; // insert at correct position
        }
    };

    template<typename T>
    int Array<T>::partition(int low, int high) {
        /*
        Algorithm to partition the array for quick sort:
            1. choose pivot (here we choose last element)
            2. set i = low - 1
            3. iterate j from low to high - 1:
                a. if data[j] < pivot:
                    i. increment i
                    ii. swap data[i] and data[j]
            4. swap data[i + 1] and data[high] (place pivot correctly)
            5. return i + 1 (pivot index)
        */
       T pivot = data[high];
       int i = low - 1; // pointer for smaller element

       // Rearrange: put < pivot on left, >= pivot on right
       for (int j = low; j < high; j++) {
            if (data[j] < pivot)
            {
                i++;
                // swap data[i] and data[j]
                T temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }  
       }
        // place pivot at correct position
        T temp = data[i + 1];
        data[i + 1] = data[high];
        data[high] = temp;

        return i + 1; // Return pivot index
    };

    template<typename T>
    void Array<T>::quickSortHelper(int low, int high) {
        if (low < high) 
        {
            int pi = partition(low, high);  // Get pivot position
            
            quickSortHelper(low, pi - 1);    // Sort left partition
            quickSortHelper(pi + 1, high);   // Sort right partition
        }
        
    };

    template<typename T>
    void Array<T>::quickSort() {
        /*
        Algorithm for quick sort:
            1. choose a pivot element (usually first, middle, or last)
            2. partition the array into elements < pivot and > pivot
            3. recursively apply quick sort to partitions
        */
        if (size > 1) {
            quickSortHelper(0, size - 1);
        }
    };

    template<typename T>
    void Array<T>::reverse() {
        /*
        Algorithm to reverse the array in place:
            1. set left = 0, right = size - 1
            2. while left < right:
                a. swap data[left] and data[right]
                b. increment left, decrement right
        */
       int left = 0;
       int right = size - 1;
       while (left < right) {
        T temp = data[left];
        data[left] = data[right];
        data[right] = temp;
        left++;
        right--;
       }
    };

    template<typename T>
    int Array<T>::getSize() {
        return size;
    };

    template<typename T>
    int Array<T>::getCapacity() {
        return capacity;
    };

    template<typename T>
    bool Array<T>::isEmpty() {
        return size == 0;
    };

    template<typename T>
    void Array<T>::print() {
        std::cout << "Array [size: " << size << ", capacity: " << capacity << "]: ";
        for (int i = 0; i < size; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    };
}

// Explicit template instantiation for common types
template class dsa::Array<int>;
template class dsa::Array<float>;
template class dsa::Array<double>;
template class dsa::Array<char>;
template class dsa::Array<std::string>;