# LinkedList Data Structure

[![License](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)

A comprehensive singly linked list implementation in C++ providing efficient insertions and deletions with dynamic memory management.

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Time Complexity](#time-complexity)
- [Installation](#installation)
- [Usage](#usage)
- [API Reference](#api-reference)
- [Testing](#testing)
- [Dependencies](#dependencies)
- [Contributing](#contributing)
- [License](#license)

## Overview

The LinkedList is a dynamic data structure consisting of nodes where each node contains data and a reference to the next node. This singly linked list implementation provides efficient operations for insertion and deletion at any position, making it ideal for scenarios requiring frequent modifications.

This LinkedList is part of the DSA (Data Structures and Algorithms) library, offering a flexible alternative to array-based structures.

## Features

- **Dynamic Memory**: No fixed size limitations
- **Efficient Insertions/Deletions**: O(1) at known positions
- **Sequential Access**: Natural for iteration
- **Memory Efficient**: Only allocates memory as needed
- **Type Safety**: Template-based implementation supporting any data type
- **Rich Operations**: Comprehensive set of manipulation methods
- **Sorting Capability**: Built-in bubble sort
- **Search Operations**: Linear search functionality

## Time Complexity

| Operation | Time Complexity | Description |
|-----------|-----------------|-------------|
| `insertAtBeginning(T value)` | O(1) | Insert at head |
| `insertAtEnd(T value)` | O(n) | Insert at tail (requires traversal) |
| `insert(int index, T value)` | O(n) | Insert at specific index |
| `removeFirst()` | O(1) | Remove head element |
| `removeLast()` | O(n) | Remove tail element (requires traversal) |
| `remove(int index)` | O(n) | Remove at specific index |
| `get(int index)` | O(n) | Access element by index |
| `set(int index, T value)` | O(n) | Update element at index |
| `linearSearch(T value)` | O(n) | Find element using linear search |
| `bubbleSort()` | O(n²) | Sort list using bubble sort |
| `reverse()` | O(n) | Reverse the list |
| `getSize()` | O(1) | Get current size |
| `isEmpty()` | O(1) | Check if list is empty |

## Installation

### Prerequisites

- C++11 or later
- CMake 3.20 or higher
- A C++ compiler (GCC, Clang, or MSVC)

### Building

1. Cloning the repository:
   ```bash
   git clone https://github.com/gatchez/dsa.git
   cd dsa
   ```

2. Create build directory:
   ```bash
   mkdir build && cd build
   ```

3. Configure with CMake:
   ```bash
   cmake ..
   ```

4. Build the LinkedList library:
   ```bash
   make
   ```

## Usage

### Basic Example

```cpp
#include "LinkedList.h"
#include <iostream>

using namespace dsa;

int main() {
    LinkedList<int> list;

    // Add elements
    list.insertAtBeginning(10);  // List: 10
    list.insertAtEnd(20);        // List: 10 -> 20
    list.insertAtEnd(30);        // List: 10 -> 20 -> 30

    // Insert at specific position
    list.insert(1, 15);          // List: 10 -> 15 -> 20 -> 30

    // Access elements
    std::cout << "Element at index 2: " << list.get(2) << std::endl;  // Output: 20

    // Modify elements
    list.set(2, 25);             // List: 10 -> 15 -> 25 -> 30

    // Remove elements
    list.removeFirst();           // List: 15 -> 25 -> 30
    list.remove(1);               // List: 15 -> 30

    // Print all elements
    list.print();  // Output: LinkedList [size: 2]: 15 30

    return 0;
}
```

### Search and Sort Example

```cpp
#include "LinkedList.h"
#include <iostream>

using namespace dsa;

int main() {
    LinkedList<int> list;
    list.insertAtEnd(64);
    list.insertAtEnd(34);
    list.insertAtEnd(25);
    list.insertAtEnd(12);
    list.insertAtEnd(22);

    std::cout << "Original: ";
    list.print();

    // Search for element
    int index = list.linearSearch(25);
    std::cout << "Index of 25: " << index << std::endl;

    // Sort the list
    list.bubbleSort();
    std::cout << "Sorted: ";
    list.print();

    return 0;
}
```

### Working with Custom Types

```cpp
#include "LinkedList.h"
#include <string>

using namespace dsa;

int main() {
    LinkedList<std::string> list;

    list.insertAtEnd("Hello");
    list.insertAtEnd("Linked");
    list.insertAtEnd("List");

    list.print();  // Output: LinkedList [size: 3]: Hello Linked List

    return 0;
}
```

## API Reference

### Constructor

```cpp
LinkedList<T>();
```
Creates an empty linked list.

### Insertion Operations

#### `void insertAtBeginning(T value)`
Inserts an element at the beginning of the list.

**Parameters:**
- `value`: The element to insert

**Time Complexity:** O(1)

#### `void insertAtEnd(T value)`
Inserts an element at the end of the list.

**Parameters:**
- `value`: The element to insert

**Time Complexity:** O(n)

#### `void insert(int index, T value)`
Inserts an element at the specified index.

**Parameters:**
- `index`: Position to insert (0-based)
- `value`: The element to insert

**Throws:** `std::out_of_range` if index is invalid

**Time Complexity:** O(n)

### Deletion Operations

#### `void removeFirst()`
Removes the first element from the list.

**Throws:** `std::out_of_range` if list is empty

**Time Complexity:** O(1)

#### `void removeLast()`
Removes the last element from the list.

**Throws:** `std::out_of_range` if list is empty

**Time Complexity:** O(n)

#### `void remove(int index)`
Removes the element at the specified index.

**Parameters:**
- `index`: Position to remove (0-based)

**Throws:** `std::out_of_range` if index is invalid

**Time Complexity:** O(n)

### Access Operations

#### `T get(int index)`
Returns the element at the specified index.

**Parameters:**
- `index`: Position to access (0-based)

**Returns:** The element at the index

**Throws:** `std::out_of_range` if index is invalid

**Time Complexity:** O(n)

#### `void set(int index, T value)`
Updates the element at the specified index.

**Parameters:**
- `index`: Position to update (0-based)
- `value`: New value

**Throws:** `std::out_of_range` if index is invalid

**Time Complexity:** O(n)

### Search Operations

#### `int linearSearch(T value)`
Performs linear search for the specified value.

**Parameters:**
- `value`: The value to search for

**Returns:** Index of the element if found, -1 otherwise

**Time Complexity:** O(n)

### Sorting Operations

#### `void bubbleSort()`
Sorts the list using bubble sort algorithm.

**Time Complexity:** O(n²)

### Utility Operations

#### `int getSize()`
Returns the number of elements in the list.

**Returns:** Current size

**Time Complexity:** O(1)

#### `bool isEmpty()`
Checks if the list is empty.

**Returns:** `true` if empty, `false` otherwise

**Time Complexity:** O(1)

#### `void reverse()`
Reverses the order of elements in the list.

**Time Complexity:** O(n)

#### `void print()`
Prints all elements to standard output.

**Time Complexity:** O(n)

## Testing

The LinkedList implementation includes comprehensive tests covering:

- Basic operations (insert, remove, access)
- Edge cases (empty list, single element, invalid indices)
- Sorting algorithms
- Search operations
- Memory management
- Custom data types

### Execution

To run the LinkedList demo:

```bash
# From the project root
cd build
make LinkedList_demo
./bin/LinkedList_demo.exe
```

The executable is located at `dsa/build/bin/LinkedList_demo.exe`

## Dependencies

- **Standard Library**: `<iostream>`, `<stdexcept>`

## Contributing

1. Fork the repository
2. Create a feature branch
3. Make your changes with tests
4. Ensure all tests pass
5. Update documentation
6. Submit a pull request

## License

This project is licensed under the MIT License - see the [LICENSE](../../LICENSE) file for details.