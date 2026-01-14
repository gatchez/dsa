#include "Queue.h"
#include <iostream>
#include <stdexcept>

namespace dsa {
    template<typename T>
    Queue<T>::Queue() : frontIndex(0), rearIndex(-1) {};

    template<typename T>
    void Queue<T>::enqueue(T value) {
        /*
        Algorithm to enqueue an element:
            1. call queue.push(value) to add element at the end
            2. update rearIndex to point to the new rear (queue.getSize() - 1)
        */
       queue.push(value);
       rearIndex = queue.getSize() - 1;
    }

    template<typename T>
    T Queue<T>::dequeue() {
        /*
        Algorithm to dequeue an element:
            1. check if the queue is empty:
                -> if empty, throw an exception
            2. call queue.remove(frontIndex) to remove the front element and store it in a variable
            3. update rearIndex to point to the new rear (queue.getSize() - 1)
            4. return the stored variable
        */
        if (isEmpty()) {
            throw std::out_of_range("Queue underflow. Cannot dequeue.");
        }
        T frontElement = queue.remove(frontIndex);
        rearIndex = queue.getSize() - 1;
        return frontElement;
    }

    template<typename T>
    T Queue<T>::front() {
        /*
        Algorithm to return the front element:
            1. check if the queue is empty:
                -> if empty, throw an exception
            2. return queue.get(frontIndex)
        */
       if (isEmpty()) {
           throw std::out_of_range("Queue is empty. No front element.");
       }
       return queue.get(frontIndex);
    }

    template<typename T>
    T Queue<T>::rear() {
        /*
        Algorithm to return the rear element:
            1. check if the queue is empty:
                -> if empty, throw an exception
            2. return queue.get(rearIndex)
        */
       if (isEmpty()) {
            throw std::out_of_range("Queue is empty. No rear element.");
       }
       return queue.get(rearIndex);
    }

    template<typename T>
    int Queue<T>::size() {
        /*
        Algorithm to return the size of the queue:
            1. return queue.getSize()
        */
       return queue.getSize();
    }

    template<typename T>
    bool Queue<T>::isEmpty() { return rearIndex == -1; };

    template<typename T>
    void Queue<T>::print() {
        std::cout << "Queue [size: " << size() << "]: ";
        for (int i = frontIndex; i <= rearIndex; i++) {
            std::cout << queue.get(i) << " ";
        }
        std::cout << std::endl;
    }
}

// Explicit template instantiation for common types
template class dsa::Queue<int>;
template class dsa::Queue<float>;
template class dsa::Queue<double>;
template class dsa::Queue<char>;
template class dsa::Queue<std::string>;