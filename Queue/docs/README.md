# Queue Data Structure

[![License](https://img.shields.io/badge/License-MIT-blue.svg)](../../LICENSE)

A FIFO (First-In-First-Out) queue implementation in C++ using a dynamic array, providing efficient enqueue and dequeue operations with automatic memory management.

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

The Queue is a linear data structure that follows the FIFO (First-In-First-Out) principle. Elements are added to the rear (enqueue) and removed from the front (dequeue). This implementation uses a dynamic array as the underlying data structure, providing automatic resizing and efficient operations.

This Queue is part of the DSA (Data Structures and Algorithms) library, built on top of the Array data structure for memory management and resizing capabilities.

## Features

- **FIFO Operations**: Standard enqueue (add to rear) and dequeue (remove from front)
- **Dynamic Resizing**: Automatic capacity expansion through the underlying Array
- **Type Safety**: Template-based implementation supporting any data type
- **Exception Safety**: Proper error handling for empty queue operations
- **Rich API**: Comprehensive set of operations for queue manipulation
- **Memory Efficient**: Leverages Array's optimal space usage
- **Thread-Unsafe**: Designed for single-threaded use

## Time Complexity

| Operation | Time Complexity | Description |
|-----------|-----------------|-------------|
| `enqueue(T value)` | O(1) amortized | Add element to rear (may trigger resize) |
| `dequeue()` | O(n) | Remove and return front element (due to array shifting) |
| `front()` | O(1) | Access front element |
| `rear()` | O(1) | Access rear element |
| `size()` | O(1) | Get number of elements |
| `isEmpty()` | O(1) | Check if queue is empty |
| `print()` | O(n) | Display all elements |

**Note**: The O(n) dequeue complexity is due to the underlying Array's shifting behavior. For O(1) dequeue, consider a circular queue implementation.

## Installation

### Prerequisites
- C++17 compliant compiler
- CMake 3.20 or later
- The Array data structure (automatically included)

### Building
```bash
# From the project root
mkdir build
cd build
cmake ..
cmake --build .
```

### Including in Your Project
```cpp
#include "Queue.h"

// For namespace usage
using namespace dsa;
```

## Usage

### Basic Operations
```cpp
#include "Queue.h"
#include <iostream>

using namespace dsa;

int main() {
    Queue<int> queue;

    // Enqueue elements
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    // Display queue
    queue.print();  // Output: Queue [size: 3]: 10 20 30

    // Access operations
    std::cout << "Front: " << queue.front() << std::endl;  // 10
    std::cout << "Rear: " << queue.rear() << std::endl;    // 30
    std::cout << "Size: " << queue.size() << std::endl;    // 3

    // Dequeue
    int front = queue.dequeue();  // Removes and returns 10
    std::cout << "Dequeued: " << front << std::endl;

    queue.print();  // Output: Queue [size: 2]: 20 30

    return 0;
}
```

### Working with Different Types
```cpp
// String queue
Queue<std::string> stringQueue;
stringQueue.enqueue("Hello");
stringQueue.enqueue("World");

// Character queue
Queue<char> charQueue;
charQueue.enqueue('A');
charQueue.enqueue('B');
```

### Error Handling
```cpp
Queue<int> queue;

// Attempting to dequeue from empty queue
try {
    int value = queue.dequeue();
} catch (const std::out_of_range& e) {
    std::cout << "Error: " << e.what() << std::endl;
}

// Safe operations
if (!queue.isEmpty()) {
    int front = queue.front();
    int rear = queue.rear();
}
```

## API Reference

### Constructor
```cpp
Queue<T>()  // Creates an empty queue
```

### Core Operations
```cpp
void enqueue(T value)     // Add element to rear
T dequeue()               // Remove and return front element
T front()                 // Return front element (without removal)
T rear()                  // Return rear element (without removal)
```

### Utility Operations
```cpp
int size()                // Return number of elements
bool isEmpty()            // Check if queue is empty
void print()              // Display queue contents
```

### Template Parameter
- `T`: The data type stored in the queue (must be copyable and assignable)

### Exceptions
- `std::out_of_range`: Thrown when attempting to dequeue or access elements from an empty queue

## Testing

Run the demo program:
```bash
./bin/queue_demo
```

This will execute comprehensive tests including:
- Basic enqueue/dequeue operations
- Edge cases (empty queue operations)
- Different data types (int, string, char)
- Exception handling

## Dependencies

- **Array**: The underlying dynamic array implementation
- **C++ Standard Library**: For exceptions and I/O operations

## Contributing

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Add tests for new functionality
5. Ensure all tests pass
6. Submit a pull request

### Development Guidelines
- Follow the existing code style
- Add comprehensive documentation
- Include unit tests for new features
- Update this README for API changes

## License

This project is licensed under the MIT License - see the [LICENSE](../../LICENSE) file for details.

## Related Data Structures

- **[Array](../Array/docs/README.md)**: The underlying dynamic array
- **[Stack](../Stack/docs/README.md)**: LIFO counterpart using the same Array base
- **[LinkedList](../LinkedList/docs/README.md)**: Alternative implementation using linked nodes