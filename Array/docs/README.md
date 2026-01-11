# Array Data Structure

[![License](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)

A dynamic array implementation in C++ providing efficient random access and automatic memory management with resizing capabilities.

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

The Array is a dynamic, resizable data structure that provides efficient random access to elements. Unlike static arrays, this implementation automatically manages memory allocation and deallocation, growing as needed when elements are added beyond the current capacity.

This Array is part of the DSA (Data Structures and Algorithms) library, serving as the foundation for other data structures like Stack and Queue.

## Features

- **Dynamic Resizing**: Automatic capacity expansion with amortized O(1) insertions
- **Random Access**: O(1) element access by index
- **Memory Efficient**: Optimal space usage with capacity management
- **Type Safety**: Template-based implementation supporting any data type
- **Rich API**: Comprehensive set of operations for manipulation and querying
- **Sorting Algorithms**: Built-in bubble sort, insertion sort, and quicksort
- **Search Operations**: Linear and binary search capabilities

## Time Complexity

| Operation | Average Case | Worst Case | Description |
|-----------|--------------|------------|-------------|
| `push(T value)` | O(1) | O(n) | Add element to end (amortized O(1) due to resizing) |
| `pop()` | O(1) | O(1) | Remove and return last element |
| `insert(int index, T value)` | O(n) | O(n) | Insert element at specific index |
| `remove(int index)` | O(n) | O(n) | Remove element at specific index |
| `get(int index)` | O(1) | O(1) | Access element by index |
| `set(int index, T value)` | O(1) | O(1) | Update element at index |
| `linearSearch(T value)` | O(n) | O(n) | Find element using linear search |
| `binarySearch(T value)` | O(log n) | O(log n) | Find element using binary search (requires sorted array) |
| `bubbleSort()` | O(n²) | O(n²) | Sort array using bubble sort |
| `insertionSort()` | O(n²) | O(n²) | Sort array using insertion sort |
| `quickSort()` | O(n log n) | O(n²) | Sort array using quicksort |

## Installation

### Prerequisites

- C++11 or later
- CMake 3.20 or higher
- A C++ compiler (GCC, Clang, or MSVC)

### Building

1. Clone the repository
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

4. Build the Array library:
   ```bash
   make
   ```

## Usage

### Basic Example

```cpp
#include "Array.h"
#include <iostream>

using namespace dsa;

int main() {
    Array<int> arr;

    // Add elements
    arr.push(10);
    arr.push(20);
    arr.push(30);

    // Access elements
    std::cout << "Element at index 1: " << arr.get(1) << std::endl;  // Output: 20

    // Modify elements
    arr.set(1, 25);
    std::cout << "After modification: " << arr.get(1) << std::endl;  // Output: 25

    // Insert and remove
    arr.insert(1, 15);  // Insert 15 at index 1
    arr.remove(2);       // Remove element at index 2

    // Print all elements
    arr.print();  // Output: Array [size: 3]: 10 15 25

    return 0;
}
```

### Sorting Example

```cpp
#include "/Array.h"
#include <iostream>

using namespace dsa;

int main() {
    Array<int> arr;
    arr.push(64);
    arr.push(34);
    arr.push(25);
    arr.push(12);
    arr.push(22);

    std::cout << "Original: ";
    arr.print();

    arr.bubbleSort();
    std::cout << "Sorted: ";
    arr.print();

    // Binary search on sorted array
    int index = arr.binarySearch(25);
    std::cout << "Index of 25: " << index << std::endl;

    return 0;
}
```

### Working with Custom Types

```cpp
#include "Array.h"
#include <string>

using namespace dsa;

int main() {
    Array<std::string> arr;

    arr.push("Hello");
    arr.push("World");
    arr.push("Array");

    arr.print();  // Output: Array [size: 3]: Hello World Array

    return 0;
}
```

## API Reference

### Constructor

```cpp
Array<T>();
```
Creates an empty array with initial capacity of 10.

### Core Operations

#### `void push(T value)`
Adds an element to the end of the array.

**Parameters:**
- `value`: The element to add

**Time Complexity:** O(1) amortized

#### `T pop()`
Removes and returns the last element.

**Returns:** The removed element

**Throws:** `std::out_of_range` if array is empty

**Time Complexity:** O(1)

#### `void insert(int index, T value)`
Inserts an element at the specified index.

**Parameters:**
- `index`: Position to insert (0-based)
- `value`: The element to insert

**Throws:** `std::out_of_range` if index is invalid

**Time Complexity:** O(n)

#### `T remove(int index)`
Removes and returns the element at the specified index.

**Parameters:**
- `index`: Position to remove (0-based)

**Returns:** The removed element

**Throws:** `std::out_of_range` if index is invalid

**Time Complexity:** O(n)

#### `T get(int index)`
Returns the element at the specified index.

**Parameters:**
- `index`: Position to access (0-based)

**Returns:** The element at the index

**Throws:** `std::out_of_range` if index is invalid

**Time Complexity:** O(1)

#### `void set(int index, T value)`
Updates the element at the specified index.

**Parameters:**
- `index`: Position to update (0-based)
- `value`: New value

**Throws:** `std::out_of_range` if index is invalid

**Time Complexity:** O(1)

### Search Operations

#### `int linearSearch(T value)`
Performs linear search for the specified value.

**Parameters:**
- `value`: The value to search for

**Returns:** Index of the element if found, -1 otherwise

**Time Complexity:** O(n)

#### `int binarySearch(T value)`
Performs binary search for the specified value (requires sorted array).

**Parameters:**
- `value`: The value to search for

**Returns:** Index of the element if found, -1 otherwise

**Time Complexity:** O(log n)

### Sorting Operations

#### `void bubbleSort()`
Sorts the array using bubble sort algorithm.

**Time Complexity:** O(n²)

#### `void insertionSort()`
Sorts the array using insertion sort algorithm.

**Time Complexity:** O(n²)

#### `void quickSort()`
Sorts the array using quicksort algorithm.

**Time Complexity:** O(n log n) average, O(n²) worst case

### Utility Operations

#### `int getSize()`
Returns the number of elements in the array.

**Returns:** Current size

**Time Complexity:** O(1)

#### `int getCapacity()`
Returns the current capacity of the array.

**Returns:** Current capacity

**Time Complexity:** O(1)

#### `bool isEmpty()`
Checks if the array is empty.

**Returns:** `true` if empty, `false` otherwise

**Time Complexity:** O(1)

#### `void reverse()`
Reverses the order of elements in the array.

**Time Complexity:** O(n)

#### `void print()`
Prints all elements to standard output.

**Time Complexity:** O(n)

## Testing

The Array implementation includes comprehensive tests covering:

- Basic operations (push, pop, insert, remove)
- Edge cases (empty array, full capacity, invalid indices)
- Sorting algorithms
- Search operations
- Memory management and resizing
- Custom data types

### Execution

To run the Array demo:

```bash
# From the project root
cd build
make array_demo
./bin/array_demo.exe
```

The executable is located at `dsa/build/bin/array_demo.exe`

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
