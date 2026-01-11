# Stack Data Structure

[![License](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)

A robust implementation of the Stack data structure in C++, providing Last-In-First-Out (LIFO) operations with dynamic memory management.

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

The Stack is a fundamental data structure that follows the Last-In-First-Out (LIFO) principle. Elements are added and removed from the same end, called the "top" of the stack. This implementation uses the `Array` data structure from this DSA library as the underlying storage, allowing for efficient resizing when capacity is exceeded.

This Stack is part of the DSA (Data Structures and Algorithms) library, designed for educational and practical use in C++ applications.

## Features

- **LIFO Operations**: Strict adherence to Last-In-First-Out principle
- **Dynamic Resizing**: Automatic capacity expansion when needed
- **Type Safety**: Template-based implementation supporting any data type
- **Exception Safety**: Proper error handling for invalid operations
- **Memory Efficient**: Minimal overhead with optimal space usage
- **Comprehensive Testing**: Extensive test suite covering edge cases

## Time Complexity

| Operation | Average Case | Worst Case | Description |
|-----------|--------------|------------|-------------|
| `push(T value)` | O(1) | O(n) | Add element to top (amortized O(1) due to resizing) |
| `pop()` | O(1) | O(1) | Remove and return top element |
| `top()` | O(1) | O(1) | Access top element without removal |
| `size()` | O(1) | O(1) | Get current number of elements |
| `isEmpty()` | O(1) | O(1) | Check if stack is empty |
| `print()` | O(n) | O(n) | Display all elements |

## Installation

### Prerequisites

- C++11 or later
- CMake 3.20 or higher
- A C++ compiler (GCC, Clang, or MSVC)

### Building

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/dsa.git
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

4. Build the project:
   ```bash
   make
   ```

The Stack library will be built as part of the overall DSA project.

## Usage

### Basic Example

```cpp
#include "../include/Stack.h"
#include <iostream>

using namespace dsa;

int main() {
    Stack<int> stack;

    // Push elements
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Access top element
    std::cout << "Top: " << stack.top() << std::endl;  // Output: 30

    // Pop elements
    std::cout << "Popped: " << stack.pop() << std::endl;  // Output: 30

    // Check size
    std::cout << "Size: " << stack.size() << std::endl;  // Output: 2

    // Print all elements
    stack.print();  // Output: Stack [size: 2]: 20 10

    return 0;
}
```

### Working with Custom Types

```cpp
#include "../include/Stack.h"
#include <string>

using namespace dsa;

int main() {
    Stack<std::string> stack;

    stack.push("Hello");
    stack.push("World");

    while (!stack.isEmpty()) {
        std::cout << stack.pop() << " ";
    }
    // Output: World Hello

    return 0;
}
```

### Error Handling

```cpp
#include "../include/Stack.h"
#include <iostream>
#include <stdexcept>

using namespace dsa;

int main() {
    Stack<int> stack;

    try {
        int top = stack.top();  // Throws std::out_of_range
    } catch (const std::out_of_range& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        int popped = stack.pop();  // Throws std::out_of_range
    } catch (const std::out_of_range& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
```

## API Reference

### Constructor

```cpp
Stack<T>();
```
Creates an empty stack.

### Core Operations

#### `void push(T value)`
Adds an element to the top of the stack.

**Parameters:**
- `value`: The element to add

**Time Complexity:** O(1) amortized

#### `T pop()`
Removes and returns the top element from the stack.

**Returns:** The removed element

**Throws:** `std::out_of_range` if stack is empty

**Time Complexity:** O(1)

#### `T top()`
Returns the top element without removing it.

**Returns:** The top element

**Throws:** `std::out_of_range` if stack is empty

**Time Complexity:** O(1)

### Utility Operations

#### `int size()`
Returns the number of elements in the stack.

**Returns:** Current size

**Time Complexity:** O(1)

#### `bool isEmpty()`
Checks if the stack is empty.

**Returns:** `true` if empty, `false` otherwise

**Time Complexity:** O(1)

#### `void print()`
Prints all elements in the stack to standard output.

**Time Complexity:** O(n)

## Testing

The Stack implementation includes comprehensive tests covering:

- Empty stack operations
- Push/pop functionality
- Exception handling
- Large-scale operations (100+ elements)
- Multiple data types (int, string, char)
- Edge cases and boundary conditions

### Running Tests

```bash
cd build
make stack_demo
./bin/stack_demo.exe
```

Expected output includes successful completion of all test cases with proper exception handling.

## Dependencies

- **Array**: Underlying dynamic array implementation
- **Standard Library**: `<iostream>`, `<stdexcept>`

## Contributing

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

### Development Guidelines

- Follow C++ best practices
- Include unit tests for new features
- Update documentation as needed
- Ensure code compiles with C++11 standard

## License

This project is licensed under the MIT License - see the [LICENSE](../../LICENSE) file for details.

## Acknowledgments

- Part of the DSA library for educational purposes
- Inspired by standard stack implementations in various programming languages