#pragma once

namespace dsa {
    template<typename T>
    class Array {
        private:
            T* data; // pointer to heap memory
            int size; // number of elements in the array
            int capacity; // total capacity of the array

            void resize(); // resize the array when capacity is reached
            void shiftRight(int index); // helper to shift elements right from index
            void shiftLeft(int index); // helper to shift elements left from index
            int partition(int low, int high); // helper for quick sort
            void quickSortHelper(int low, int high); // recursive quick sort helper

        public:
        // constructor and destructor
            Array();
            ~Array();

            // core array operations
            void push(T value);
            T pop();
            void insert(int index, T value);
            T remove(int index);
            T get(int index);
            void set(int index, T value);

            // Search algorithms -> returns index of the found element or -1 if not found
            int linearSearch(T value);
            int binarySearch(T value);

            // Sorting algorithms -> sorts array in place
            void bubbleSort(); 
            void insertionSort();
            void quickSort();

            // utility methods
            int getSize();
            int getCapacity();
            bool isEmpty();
            void reverse(); // reverses the array in place
            void print();
    };
}