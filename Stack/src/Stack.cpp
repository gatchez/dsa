#include "Stack.h"
#include <iostream>
#include <stdexcept>

namespace dsa {
    template<typename T>
    Stack<T>::Stack() : topIndex(-1) {
        // stack is default constructed
    };

    template<typename T>
    void Stack<T>::push(T value) {
        /*
        Algorithm to push element to a stack:
            -> call stack.push()
            -> update the top index by calling stack.getSize() - 1
        */
       stack.push(value);
       topIndex = stack.getSize() - 1;
    };

    template<typename T>
    T Stack<T>::pop() {
        /*
        Algorithm to pop element from stack:
        -> check if stack is empty
            -> if empty, throw an exception    
        -> store the result of stack.pop() in a variable
        -> update the top index by calling stack.getSize() - 1
        -> return the stored variable
            
        */
       if (isEmpty()) {
        std::cout << "Stack Underflow: Cannot pop from an empty stack." << std::endl;
        throw std::out_of_range("The stack is empty");
       }
       T val = stack.pop();
       topIndex = stack.getSize() - 1;
       return val;
    };

    template<typename T>
    T Stack<T>::top() { 
        if (isEmpty()) {
            throw std::out_of_range("The stack is empty");
        }
        return stack.get(topIndex); 
    };

    template<typename T>
    int Stack<T>::size() { return stack.getSize(); };

    template<typename T>
    bool Stack<T>::isEmpty() { return topIndex == -1; };

    template<typename T>
    void Stack<T>::print() {
        std::cout << "Stack [size: " << size() << "]: ";
        for (int i = size() - 1; i >= 0; i--) {
            std::cout << stack.get(i) << " ";
        }
        std::cout << std::endl;
    };
}

// Explicit template instantiation for common types
template class dsa::Stack<int>;
template class dsa::Stack<float>;
template class dsa::Stack<double>;
template class dsa::Stack<char>;
template class dsa::Stack<std::string>;