#include <iostream>
#include "Array.h"

using namespace dsa;
using namespace std;

int main() {
    cout << "=== 1. Basic Operations ===" << endl;
    Array<int> arr = Array<int>();
    arr.push(5);
    arr.push(3);
    arr.push(8);
    arr.push(1);
    arr.push(12);
    arr.push(11);

    arr.print();

    int size = arr.getSize();
    int capacity = arr.getCapacity();
    cout << "Array size: " << size << endl << "Array capacity: " << capacity << endl;

    cout << "Array empty: " << (arr.isEmpty() ? "Yes" : "No") << endl;

    cout << "=== 2. Accessor Methods ===" << endl;

    cout << "Element at index 2: " << arr.get(2) << endl;

    arr.set(2, 33);
    cout << "After setting index 2 to 10:" << endl;
    arr.print();

    try {
        cout <<  "Getting element at invalid index 11 (should throw exception): " << endl;
        cout << arr.get(11) << endl;
    } catch (const out_of_range& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    try {
        cout << "After setting index 11 (which is out of bound) to 45 (should throw exception): " << endl;
        arr.set(11, 45);
    } catch (const out_of_range& e) {
        cout << "Caught exception: " << e.what() << endl;
    }
    
    cout << "=== 3. Insertion and Removal ===" << endl;

    arr.insert(0, 57);
    cout << "After inserting 57 at index 0 (beginning):" << endl;
    arr.print();

    arr.insert(arr.getSize() / 2, 29);
    cout << "After inserting 29 at the middle:" << endl;
    arr.print();

    arr.insert(arr.getSize() - 1, 99);
    cout << "After inserting 99 at the index " << arr.getSize() - 1 << " (near end): " << endl;
    arr.print();

    cout << "Removing element at the beginning (index 0): " << arr.remove(0) << endl;
    arr.print();

    cout << "Removing element at the middle: " << arr.remove(arr.getSize() / 2) << endl;
    arr.print();

    cout << "Removing element at index " << arr.getSize() - 1 << " (near end): " << arr.remove(arr.getSize() - 1) << endl;
    arr.print();

    try {
    cout << "Removing element at invalid index 15 (should throw exception): " << endl;
    cout << arr.remove(15) << endl;
    } catch (const out_of_range& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    cout << "=== 4. Popping Operation ===" << endl;

    cout << "Popping last element: " << arr.pop() << endl;
    arr.print();

    cout << "Popping last element: " << arr.pop() << endl;
    arr.print();

    cout << "Popping last element: " << arr.pop() << endl;
    arr.print();
    
    Array<int> emptyArr = Array<int>();
    try {
        cout << "Popping from empty array (should throw exception): " << endl;
        cout << emptyArr.pop() << endl;
    } catch (const out_of_range& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    cout << "=== 5. Searching Algorithms ===" << endl;

    cout << "Using LinearSearch to locate index of 5: " << arr.linearSearch(5) << endl;

    cout << "Using LinearSearch to locate index of 100 (not present -> should return -1): " << arr.linearSearch(100) << endl;

    Array<int> sortedArr = Array<int>();
    sortedArr.push(2);
    sortedArr.push(4);
    sortedArr.push(6);
    sortedArr.push(8);
    sortedArr.push(10);

    cout << "Using BinarySearch to locate index of 6 in sorted array: " << sortedArr.binarySearch(6) << endl;
    cout << "Using BinarySearch to locate index of 5 (not present -> should return -1): " << sortedArr.binarySearch(5) << endl;

    cout << "=== 6. Sorting Algorithms ===" << endl;

    arr.bubbleSort();
    cout << "After Bubble Sort:" << endl;
    arr.print();

    arr.insertionSort();
    cout << "After Insertion Sort:" << endl;
    arr.print();

    arr.quickSort();
    cout << "After Quick Sort:" << endl;
    arr.print();

    cout << "=== 7. Reverse ===" << endl;

    arr.reverse();
    cout << "After Reversing the array:" << endl;
    arr.print();

    cout << "Reversing empty array:" << endl;
    emptyArr.reverse();
    emptyArr.print();

    cout << "Reversing single-element array:" << endl;
    Array<int> singleElemArr = Array<int>();
    singleElemArr.push(42);
    singleElemArr.reverse();
    singleElemArr.print();

    cout << "=== 8. Dynamic Resizing ===" << endl;

    arr.push(80);
    arr.push(81);
    arr.push(82);
    arr.push(83);
    arr.push(84);
    arr.push(85);
    arr.push(86);
    arr.push(87);
    arr.push(88);
    arr.push(89);

    cout << "After pushing multiple elements to test dynamic resizing:" << endl;
    arr.print();

    return 0;
}
