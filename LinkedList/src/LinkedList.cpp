#include <iostream>
#include "LinkedList.h"
#include <algorithm> // For std::swap
#include <stdexcept> // For std::out_of_range

namespace dsa {
    template<typename T>
    LinkedList<T>::LinkedList() {
        head = tail = nullptr;
        count = 0;
    }

    template<typename T>
    LinkedList<T>::~LinkedList() {
        /*
        Algorithm to implement destructor:
            -> Traverse through the linked list and delete each node to free memory
            -> Set head and tail to nullptr after deletion
            -> Set size to 0
            -> Optionally, print a message indicating successful destruction
            -> Handle edge case where linked list is already empty
            -> Time Complexity: O(n), Space Complexity: O(1)
        */
       Node* current = head;
       Node* nextNode;
       while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
       }
       head = tail = nullptr;
       count = 0;
    }

    template<typename T>
    void LinkedList<T>::insertAtBeginning(T value) {
        /*
        Algorithm to implement insertAtBeginning:
            -> Create a new node with the given value
            -> If the linked list is empty, set head and tail to the new node
            -> Otherwise, set the new node's next to the current head and update head to the new node
            -> Increment the size of the linked list
            -> Time Complexity: O(1), Space Complexity: O(1)
        */
        Node* newNode = new Node(value);

        if (isEmpty()) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        count++;
    }

    template<typename T>
    void LinkedList<T>::insertAtEnd(T value) {
        /*
        Algorithm to insert at the end of the linked list:
            -> Create a new node with the given value
            -> If the linked list is empty, call insertAtBeginning
            -> Otherwise, traverse to the last node and set its next to the new node
            -> Update tail to the new node
            -> Increment the size of the linked list
            -> Time Complexity: O(n) in worst case, Space Complexity: O(1)

            ** Inefficiency fix: use tail pointer to directly access the last node in O(1) time **
                -> If the linked list is empty, call insertAtBeginning
                -> Otherwise, set tail's next to the new node and update tail to the new node
                -> Increment the size of the linked list
                -> Time Complexity: O(1), Space Complexity: O(1)
        */
       if (isEmpty()) {
        insertAtBeginning(value);
        return;
       } else {

        // Node* current = head;
        // while (current->next != nullptr) {
        //     current = current->next;
        // }
        // current->next = newNode;
        // tail = newNode;
        // count++;

        tail->next = new Node(value);
        tail = tail->next;
        count++;
       }       
    }

    template<typename T>
    void LinkedList<T>::insertAt(int index, T value) {
        /*
        Algorithm to implement insert at specified index:
            -> Create a new node with the given value
            -> If index is 0, call insertAtBeginning
            -> Otherwise, traverse the linked list to find the node at (index - 1)
            -> Set the new node's next to the current node's next and update current node's next to the new node
            -> If the new node is inserted at the end, update tail to the new node
            -> Increment the size of the linked list
            -> Handle edge cases such as index out of bounds
            -> Time Complexity: O(n) in worst case, Space Complexity: O(1)
        */
        Node* newNode = new Node(value);
        if (index == 0) {
        insertAtBeginning(value);
        return;
        } else {
        Node* current = head;
        int i = 0;
        while (i < (index - 1) && current != nullptr)
        {
            current = current->next;
            i++;
        }
        if (current == nullptr)
        {
            delete newNode;
            throw std::out_of_range("Index out of bounds");
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
        if (newNode->next == nullptr)
        {
            tail = newNode;
        }
        count++;
       }
    }

    template<typename T>
    void LinkedList<T>::set(int index, T value) {
        /*
        Algorithm to implement set at specified index:
            -> Traverse the linked list to find the node at the specified index
            -> Update the node's data with the given value
            -> Handle edge cases such as index out of bounds
            -> Time Complexity: O(n) in worst case, Space Complexity: O(1)
        */
       Node* current = head;
       int i = 0;
       while (i < index && current != nullptr)
       {
        current = current->next;
        i++;
       }
       if (current == nullptr)
       {
        throw std::out_of_range("Index out of bounds");
        return;
       }
       current->data = value;
    }

    template<typename T>
    T LinkedList<T>::get(int index) {
        /*
        Algorithm to implement get at specified index:
            -> Traverse the linked list to find the node at the specified index
            -> Return the node's data
            -> Handle edge cases such as index out of bounds
            -> Time Complexity: O(n) in worst case, Space Complexity: O(1)
        */
       Node* current = head;
       int i = 0;
       while (i < index && current != nullptr)
       {
        current = current->next;
        i++;
       }
       if (current == nullptr)
       {
        throw std::out_of_range("Index out of range");
       }
       return current->data;
    }

    template<typename T>
    T LinkedList<T>::removeFirst() {
        /*
        Algorithm to implement removeFirst:
            -> Check if the linked list is empty; if so, return an error or throw an exception
            -> Store the data of the head node to return later
            -> Update head to the next node
            -> If head becomes nullptr, update tail to nullptr as well
            -> Decrement the size of the linked list
            -> Delete the old head node to free memory
            -> Return the stored data
            -> Time Complexity: O(1), Space Complexity: O(1)
        */
       Node* temp = head;
       if (isEmpty())
       {
        throw std::out_of_range("Cannot delete from empty linked list");
       } else if (getSize() == 1) {
        T data = temp->data;
        head = tail = nullptr;
        delete temp;
        count--;

        return data;
       } else {
       T data = temp->data;
       head = head->next;
       if (head == nullptr)
       {
        tail = nullptr;
       }
       delete temp;
       count--;

       return data;
       }
    }

    template<typename T>
    T LinkedList<T>::removeLast() {
        /*
        Algorithm to implement removeLast:
            -> Check if the linked list is empty; if so, return an error or throw an exception
            -> If there is only one node, store its data, set head and tail to nullptr, decrement size, delete the node, and return the data
            -> Otherwise, traverse the linked list to find the second last node
            -> Store the data of the tail node to return later
            -> Update the second last node's next to nullptr and update tail to the second last node
            -> Decrement the size of the linked list
            -> Delete the old tail node to free memory
            -> Return the stored data
            -> Time Complexity: O(n) in worst case, Space Complexity: O(1)
        */
       Node* temp = head;
       if (isEmpty()) {
        throw std::out_of_range("Cannot delete from empty linked list");
       } else if (getSize() == 1) {
        T data = temp->data;
        head = tail = nullptr;
        delete temp;
        count--;

        return data;
       } else {
        Node* prev = nullptr;
        while (temp->next != nullptr)
        {
            prev = temp;
            temp = temp->next;
        }
        T data = temp->data;
        prev->next = nullptr;
        tail = prev;
        delete temp;
        count--;

        return data;
       }
    }

    template<typename T>
    T LinkedList<T>::removeAt(int index) {
        /*
        Algorithm to implement remove at specified index:
            -> Check if the linked list is empty; if so, return an error or throw an exception
            -> If index is 0, call removeFirst and return its result
            -> Otherwise, traverse the linked list to find the node at (index - 1)
            -> Store the data of the node to be deleted to return later
            -> Update the (index - 1) node's next to skip the node to be deleted
            -> If the deleted node is the tail, update tail to (index - 1) node
            -> Decrement the size of the linked list
            -> Delete the node to be removed to free memory
            -> Return the stored data
            -> Handle edge cases such as index out of bounds
            -> Time Complexity: O(n) in worst case, Space Complexity: O(1)
        */
       if (isEmpty()) {
        throw std::out_of_range("Cannot delete from empty linked list");
       }
       if (index == 0) {
        return removeFirst();
       } else {
        Node* current = head;
        int i = 0;
        while (i < (index - 1) && current != nullptr) {
            current = current->next;
            i++;
        }
        if (current == nullptr || current->next == nullptr) {
            throw std::out_of_range("Index out of bounds");
        }
        Node* temp = current->next;
        T data = temp->data;
        current->next = temp->next;
        delete temp;
        if (current->next == nullptr) {
            tail = current;
        }
        count--;

        return data;
       }
    }

    template<typename T>
    int LinkedList<T>::linearSearch(T value) {
        /*
        Algorithm to implement linearSearch:
            -> Initialize a current node pointer to head and an index counter to 0
            -> Traverse the linked list:
                -> If current node's data matches the value, return the current index
                -> Move to the next node and increment the index counter
            -> If the end of the list is reached without finding the value, return -1
            -> Time Complexity: O(n), Space Complexity: O(1)
        */
       Node* current = head;
        int index = 0;
        while (current != nullptr) {
            if (current->data == value) {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1;
    }

    template<typename T>
    void LinkedList<T>::bubbleSort() {
        /* Algorithm to implement bubbleSort:
            -> If the linked list is empty or has one element, return (already sorted)
            -> Initialize a boolean flag to track if any swaps were made
            -> Repeat until no swaps are made:
                -> Set the flag to false
                -> Traverse the linked list:
                    -> Compare the current node's data with the next node's data
                    -> If they are out of order, swap their data and set the flag to true
            -> Time Complexity: O(n^2) in worst case, Space Complexity: O(1)
        */
       if (isEmpty() || getSize() == 1) {
        return;
       }
       bool swapped;
       do {
        swapped = false;
        Node* current = head;
        while (current->next != nullptr) {
            if (current->data > current->next->data) {
                std::swap(current->data, current->next->data);
                swapped = true;
            }
            current = current->next;
        }
       } while (swapped);
    }

    template<typename T>
    int LinkedList<T>::getSize() { return count; }

    template<typename T>
    bool LinkedList<T>::isEmpty() { return count == 0; }

    template<typename T>
    void LinkedList<T>::reverse() {
        /* Algorithm to implement reverse:
            -> Initialize three pointers: prev as nullptr, current as head, and next as nullptr
            -> Traverse the linked list:
                -> Store the next node (current->next) in next
                -> Reverse the current node's pointer (current->next = prev)
                -> Move prev and current one step forward (prev = current, current = next)
            -> After the loop, set head to prev (new head of the reversed list)
            -> Time Complexity: O(n), Space Complexity: O(1)
        */
         Node* prev = nullptr;
         Node* current = head;
         Node* next = nullptr;

         while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
         }
         head = prev;
    }

    template<typename T>
    void LinkedList<T>::print() {
        /*
        Algorithm to implement print:
            -> Initialize a current node pointer to head
            -> Traverse the linked list:
                -> Print the current node's data
                -> Move to the next node
            -> Time Complexity: O(n), Space Complexity: O(1)
        */
       Node* current = head;
       while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
       }
    }
}

// Explicit template instantiation for common types
template class dsa::LinkedList<int>;
template class dsa::LinkedList<double>;
template class dsa::LinkedList<float>;
template class dsa::LinkedList<char>;
template class dsa::LinkedList<std::string>;