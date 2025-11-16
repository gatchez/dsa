cmake_minimum_required(VERSION 3.20)

# Array Data Structure Project
project(Array VERSION 1.0.0 LANGUAGES CXX)

# Source files
set(ARRAY_SOURCES
    src/main.cpp
    src/Array.cpp
)

# Header files
set(ARRAY_HEADERS
    include/Array.h
)

# Create executable
add_executable(array_demo ${ARRAY_SOURCES} ${ARRAY_HEADERS})

# Add include directories
target_include_directories(array_demo PRIVATE include)

# Set compiler flags for this target
target_compile_features(array_demo PRIVATE cxx_std_17)

# Test executable (if tests exist)
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/test_array.cpp")
    add_executable(test_array 
        tests/test_array.cpp
    )
    target_include_directories(test_array PRIVATE include)
    target_compile_features(test_array PRIVATE cxx_std_17)
    
    # Add test to CTest
    add_test(NAME ArrayTests COMMAND test_array)
endif()

message(STATUS "Array project configured")
