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
            Array(); // Constructor
            ~Array(); // Destructor

            // core array operations
            void push(T value); // Adds element at the end of the array
            T pop(); // Removes and returns the last element of the array
            void insert(int index, T value); // Inserts element at specified index
            T remove(int index); // Removes and returns element at specified index
            T get(int index); // Returns element at specified index
            void set(int index, T value); // Modifies element at specified index

            // Search algorithms -> returns index of the found element or -1 if not found
            int linearSearch(T value); // Returns index of the found element or -1 if not found
            int binarySearch(T value); // Returns index of the found element or -1 if not found

            // Sorting algorithms -> sorts array in place
            void bubbleSort(); 
            void insertionSort();
            void quickSort();

            // utility methods
            int getSize(); // Returns the current number of elements in the array
            int getCapacity(); // Returns the current capacity of the array
            bool isEmpty(); // Returns true if array is empty, false otherwise
            void reverse(); // reverses the array in place
            void print(); // Outputs all the elements in the array
    };
}