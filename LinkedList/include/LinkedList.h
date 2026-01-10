#pragma once

namespace dsa {
    template<typename T>
    class LinkedList {
        private:
            struct Node {
                T data;
                Node* next;
                Node(T value) : data(value), next(nullptr) {}
            };

            Node* head; // The first node in linked list
            Node* tail; // The last node in linked list
            int count; // Number of nodes in linked list

        public:
            // Constructor and destructor
            LinkedList(); // Constructor
            ~LinkedList(); // Destructor

            // Core operations
            void insertAtBeginning(T value); // Inserts element at the beginning of the linked list
            void insertAtEnd(T value); // Inserts element at the end of linked list
            void insertAt(int index, T value); // Inserts element at a specified index
            void set(int index, T value); // Modifies the element at the the specified index
            T get(int index); // Returns the value at the specified index

            // Deletion
            T removeFirst(); // Returns the deleted value of the head or error for empty linked list
            T removeLast(); // Returns the deleted value of the tail or error for empty linked list
            T removeAt(int index); // Returns the deleted value of node at the specified index or error for empty linked list

            // Searching
            int linearSearch(T value); // Returns the index of the found element or -1 if not found

            // Sorting
            void bubbleSort(); // Sorts the elements in ascending order

            // Utilities
            int getSize(); // Returns the total number of elements in linked list
            bool isEmpty(); // Checks whether linked list is empty
            void reverse(); // Reverses the linked list in place
            void print(); // Outputs all the elements in linked list
    };
}