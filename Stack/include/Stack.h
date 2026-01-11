#pragma once
#include "../../Array/include/Array.h"

namespace dsa {
    template<typename T>
    class Stack {
        private:
            Array<T> stack;
            int topIndex; // Points to the top element in the stack

        public:
            Stack(); // Constructor
            void push(T value); // Add element at the top of the stack
            T pop(); // Returns the removed element
            T top(); // Returns the top element of the stack
            int size(); // Returns the number of elements in the stack
            bool isEmpty(); // Returns true if the stack is empty, false otherwise
            void print(); // Outputs all the elements in the stack
    };
}