# Data Structures and Algorithms (DSA) in C++

A comprehensive collection of Data Structures and Algorithms implemented in C++. This project is organized with each data structure as a separate sub-project.

## Project Structure

```
dsa/
├── Array/                    # Array data structure project
│   ├── src/                  # Source files
│   ├── include/              # Header files
│   ├── tests/                # Unit tests
│   ├── docs/                 # Documentation
│   ├── build/                # Build output
│   └── CMakeLists.txt
├── LinkedList/               # LinkedList data structure project
│   ├── src/                  # Source files
│   ├── include/              # Header files
│   ├── docs/                 # Documentation
│   └── CMakeLists.txt
├── CMakeLists.txt            # Root CMake configuration
├── README.md                 # This file
├── LICENSE                   # MIT License
└── .gitignore                # Git ignore rules
```

## Requirements

- C++17 or later
- CMake 3.20 or later
- A C++ compiler (g++, clang, or MSVC)

## Building the Project

### Using CMake (Recommended)

```bash
# Clone the repository
git clone https://github.com/gatchez/dsa.git
cd dsa

# Create build directory and configure
mkdir build
cd build
cmake ..

# Build all projects
make

# Run tests
ctest
```

## Data Structures

- [x] Array
- [x] Linked List
- [ ] Stack
- [ ] Queue
- [ ] Tree
- [ ] Graph
- [ ] Hash Table

## License

MIT License - see LICENSE file for details

## Contributing

Feel free to submit issues and enhancement requests!
