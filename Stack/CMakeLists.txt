cmake_minimum_required(VERSION 3.20)

# Stack data structure project
project(Stack VERSION 1.0.0 LANGUAGES CXX)

# Source files
set(STACK_SOURCES
    src/Stack.cpp
    src/main.cpp
    ../Array/src/Array.cpp # Include Array implementation
)

# Header files
set(STACK_HEADERS
    include/Stack.h
)

# Create executable
add_executable(stack_demo ${STACK_SOURCES} ${STACK_HEADERS})

# Add include directories
target_include_directories(stack_demo PRIVATE include)
target_include_directories(stack_demo PRIVATE ../Array/include)

# Set compiler flags for this target
target_compile_features(stack_demo PRIVATE cxx_std_17)

# Test executable (if test exists)
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/test_Stack.cpp")
    add_executable(test_Stack 
        tests/test_Stack.cpp
    )
    target_include_directories(test_Stack PRIVATE include)
    target_compile_features(test_Stack PRIVATE cxx_std_17)
    
    # Add test to CTest
    add_test(NAME StackTests COMMAND test_Stack)
endif()

message(STATUS "Stack project configured")