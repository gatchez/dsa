#include <iostream>
#include "LinkedList.h"

int main() {
    dsa::LinkedList<int> list;

    // Test insertAtBeginning
    std::cout << "Inserting at beginning: 10, 20, 30" << std::endl;
    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtBeginning(30);
    list.print();
    std::cout << std::endl;

    // Test insertAtEnd
    std::cout << "Inserting at end: 40, 50" << std::endl;
    list.insertAtEnd(40);
    list.insertAtEnd(50);
    list.print();
    std::cout << std::endl;

    // Test insertAt
    std::cout << "Inserting 25 at index 2" << std::endl;
    list.insertAt(2, 25);
    list.print();
    std::cout << std::endl;

    // Test get
    std::cout << "Element at index 2: " << list.get(2) << std::endl;

    // Test set
    std::cout << "Setting index 2 to 35" << std::endl;
    list.set(2, 35);
    list.print();
    std::cout << std::endl;

    // Test linearSearch
    std::cout << "Searching for 35: index " << list.linearSearch(35) << std::endl;
    std::cout << "Searching for 100: index " << list.linearSearch(100) << std::endl;

    // Test removeFirst
    std::cout << "Removing first: " << list.removeFirst() << std::endl;
    list.print();
    std::cout << std::endl;

    // Test removeLast
    std::cout << "Removing last: " << list.removeLast() << std::endl;
    list.print();
    std::cout << std::endl;

    // Test removeAt
    std::cout << "Removing at index 1: " << list.removeAt(1) << std::endl;
    list.print();
    std::cout << std::endl;

    // Test bubbleSort
    std::cout << "Before sorting: ";
    list.print();
    std::cout << std::endl;
    list.bubbleSort();
    std::cout << "After sorting: ";
    list.print();
    std::cout << std::endl;

    // Test reverse
    std::cout << "Reversing: ";
    list.reverse();
    list.print();
    std::cout << std::endl;

    // Test size and isEmpty
    std::cout << "Size: " << list.getSize() << std::endl;
    std::cout << "Is empty: " << (list.isEmpty() ? "Yes" : "No") << std::endl;

    // Test edge cases
    try {
        list.get(10); // Out of bounds
    } catch (const std::out_of_range& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    // Clear the list
    while (!list.isEmpty()) {
        list.removeFirst();
    }
    std::cout << "After clearing, size: " << list.getSize() << std::endl;

    return 0;
}