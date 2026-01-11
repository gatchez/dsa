# Data Structures and Algorithms (DSA) in C++

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C++](https://img.shields.io/badge/C%2B%2B-17-blue.svg)](https://isocpp.org/)
[![CMake](https://img.shields.io/badge/CMake-3.20-green.svg)](https://cmake.org/)

A comprehensive, educational collection of fundamental Data Structures and Algorithms implemented in modern C++. Each data structure is organized as an independent module with complete documentation, testing, and examples.

## Table of Contents

- [Overview](#overview)
- [Project Structure](#project-structure)
- [Implemented Data Structures](#implemented-data-structures)
- [Requirements](#requirements)
- [Installation](#installation)
- [Building](#building)
- [Usage](#usage)
- [Testing](#testing)
- [Contributing](#contributing)
- [License](#license)
- [Acknowledgments](#acknowledgments)

## Overview

This repository provides clean, efficient, and well-documented implementations of essential data structures and algorithms in C++. The project is designed with the following principles:

- **Educational Focus**: Clear, readable code with comprehensive documentation
- **Modular Design**: Each data structure is a self-contained module
- **Modern C++**: Utilizes C++17 features and best practices
- **Cross-Platform**: Compatible with major compilers and operating systems
- **Thorough Testing**: Extensive test suites covering edge cases and performance

## Project Structure

```
dsa/
├── Array/                    # Dynamic Array implementation
│   ├── include/              # Header files
│   ├── src/                  # Implementation files
│   ├── tests/                # Unit tests
│   ├── docs/                 # Documentation
│   └── CMakeLists.txt        # Build configuration
├── LinkedList/               # Singly Linked List
│   ├── include/
│   ├── src/
│   ├── tests/
│   ├── docs/
│   └── CMakeLists.txt
├── Stack/                    # Stack (LIFO) using Array
│   ├── include/
│   ├── src/
│   ├── tests/
│   ├── docs/
│   └── CMakeLists.txt
├── CMakeLists.txt            # Root build configuration
├── README.md                 # Project documentation
├── LICENSE                   # MIT License
└── .gitignore                # Git ignore rules
```

## Implemented Data Structures

### ✅ Completed

- **[Array](Array/docs/README.md)**: Dynamic array with automatic resizing
- **[LinkedList](LinkedList/docs/README.md)**: Singly linked list implementation
- **[Stack](Stack/docs/README.md)**: LIFO stack using dynamic array

### 🚧 In Progress

- [ ] Queue: FIFO queue implementation
- [ ] Tree: Binary search tree and variants
- [ ] Graph: Graph representations and algorithms
- [ ] Hash Table: Hash-based dictionary

### 📋 Planned

- [ ] Priority Queue (Heap)
- [ ] Trie
- [ ] Disjoint Set Union
- [ ] Segment Tree

## Requirements

### System Requirements

- **Operating System**: Windows, macOS, or Linux
- **Compiler**: C++17 compliant compiler
  - GCC 7.0+ or Clang 5.0+ or MSVC 2017+
- **Build System**: CMake 3.20 or later
- **Memory**: Minimal requirements for compilation and testing

### Dependencies

- **Standard Library**: C++17 standard library
- **CMake**: For build configuration
- **Git**: For version control

## Installation

1. **Clone the repository**:
   ```bash
   git clone https://github.com/yourusername/dsa.git
   cd dsa
   ```

2. **Initialize submodules** (if any):
   ```bash
   git submodule update --init --recursive
   ```

## Building

### Quick Start

```bash
# Create build directory
mkdir build && cd build

# Configure with CMake
cmake ..

# Build all modules
make

# Optional: Install (system-wide)
make install
```

### Build Options

- **Debug Build**:
  ```bash
  cmake -DCMAKE_BUILD_TYPE=Debug ..
  ```

- **Release Build**:
  ```bash
  cmake -DCMAKE_BUILD_TYPE=Release ..
  ```

- **Custom Compiler**:
  ```bash
  cmake -DCMAKE_CXX_COMPILER=clang++ ..
  ```

### Platform-Specific Instructions

#### Windows (MSVC)
```bash
# Using Visual Studio Developer Command Prompt
mkdir build
cd build
cmake -G "Visual Studio 16 2019" ..
cmake --build . --config Release
```

#### macOS (Xcode)
```bash
mkdir build
cd build
cmake -G Xcode ..
cmake --build . --config Release
```

## Usage

Each data structure is designed as a standalone module. Include the appropriate headers and link against the built libraries.

### Example: Using the Stack

```cpp
#include "Stack/include/Stack.h"
#include <iostream>

using namespace dsa;

int main() {
    Stack<int> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top: " << stack.top() << std::endl;     // 30
    std::cout << "Size: " << stack.size() << std::endl;   // 3

    while (!stack.isEmpty()) {
        std::cout << stack.pop() << " ";  // 30 20 10
    }

    return 0;
}
```

For detailed usage examples, see the documentation for each data structure:
- [Array Usage](Array/docs/README.md#usage)
- [LinkedList Usage](LinkedList/docs/README.md#usage)
- [Stack Usage](Stack/docs/README.md#usage)

## Testing

The project includes comprehensive test suites for each data structure.

### Running Tests

```bash
cd build

# Run all tests
ctest

# Run specific test
ctest -R stack

# Run tests with verbose output
ctest -V
```

### Test Coverage

- **Unit Tests**: Individual component testing
- **Integration Tests**: Module interaction testing
- **Edge Cases**: Boundary condition testing
- **Performance Tests**: Time complexity validation
- **Memory Tests**: Leak detection and memory usage

## Contributing

We welcome contributions! Please see our [Contributing Guide](CONTRIBUTING.md) for details.

### Development Workflow

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Make your changes
4. Add tests for new functionality
5. Ensure all tests pass
6. Update documentation
7. Submit a pull request

### Code Standards

- Follow C++17 best practices
- Use consistent naming conventions
- Include comprehensive documentation
- Write clear, readable code
- Add unit tests for all new features

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Inspired by various open-source data structure implementations
- Thanks to the C++ community for continuous improvement of the language
- Educational resources from computer science curricula worldwide

---

**Note**: This is an educational project. While the implementations are thoroughly tested, they may not be optimized for production use in high-performance applications.
