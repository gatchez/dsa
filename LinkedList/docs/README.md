# LinkedList Data Structure

A C++ implementation of a singly linked list data structure with core operations, searching, sorting, and utilities.

## Features

- **Core Operations**: Insert at beginning, insert at end, insert at index, set value, get value.
- **Deletion**: Remove first, remove last, remove at index.
- **Searching**: Linear search.
- **Sorting**: Bubble sort.
- **Utilities**: Get size, check if empty, reverse list, print list.

## Usage

```cpp
#include "LinkedList.h"

dsa::LinkedList<int> list;
list.insertAtBeginning(10);
list.insert(1, 20);
list.print();  // Outputs: 10 20
```

## Building

From the LinkedList directory:

```bash
mkdir build
cd build
cmake ..
make
```

## Testing

If test files are added (e.g., `tests/test_LinkedList.cpp`), run:

```bash
ctest
```

## API Reference

See `include/LinkedList.h` for full method signatures and documentation.