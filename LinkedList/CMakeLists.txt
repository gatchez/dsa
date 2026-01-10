cmake_minimum_required(VERSION 3.20)

# LinkedList Data Structure Project
project(LinkedList VERSION 1.0.0 LANGUAGES CXX)

# Source files
set(LINKEDLIST_SOURCES
    src/LinkedList.cpp
    src/main.cpp
)

# Header files
set(LINKEDLIST_HEADERS
    include/LinkedList.h
)

# Create executable
add_executable(LinkedList_demo ${LINKEDLIST_SOURCES} ${LINKEDLIST_HEADERS})

# Add include directories
target_include_directories(LinkedList_demo PRIVATE include)

# Set compiler flags for this target
target_compile_features(LinkedList_demo PRIVATE cxx_std_17)

# Test exucutable (if tests exist)
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/test_LinkedList.cpp")
    add_executable(test_LinkedList 
        tests/test_LinkedList.cpp
    )
    target_include_directories(test_LinkedList PRIVATE include)
    target_compile_features(test_LinkedList PRIVATE cxx_std_17)
    
    # Add test to CTest
    add_test(NAME LinkedListTests COMMAND test_LinkedList)
endif()

message(STATUS "LinkedList project configured")