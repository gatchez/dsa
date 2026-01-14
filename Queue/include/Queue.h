#pragma once
#include "../../Array/include/Array.h"

namespace dsa {
    template<typename T>
    class Queue {
        private:
            Array<T> queue;
            int frontIndex; // Points to the front element in the queue
            int rearIndex; // Points to the rear element in the queue
        
        public:
            Queue(); // Constructor
            void enqueue(T value); // Add element at the rear of the queue
            T dequeue(); // Returns the removed element from the front of the queue
            T front(); // Returns the front element of the queue
            T rear(); // Returns the rear element of the queue
            int size(); // Returns the number of elements in the queue
            bool isEmpty(); // Returns true if queue is empty, false otherwise
            void print(); // Outputs all the elements in the queue
    };
}