cmake_minimum_required(VERSION 3.20)

# Queue data structure project
project(Queue VERSION 1.0.0 LANGUAGES CXX)

# Source files
set(QUEUE_SOURCES
    src/Queue.cpp
    src/main.cpp
    ../Array/src/Array.cpp
)

# Heade files
set(QUEUE_HEADERS
    include/Queue.h
)

# Create executable
add_executable(queue_demo ${QUEUE_SOURCES} ${QUEUE_HEADERS})

# Add include directories
target_include_directories(queue_demo PRIVATE include)
target_include_directories(queue_demo PRIVATE ../Array/include)

# Set compiler flags for this target
target_compile_features(queue_demo PRIVATE cxx_std_17)

# Test executable (if test exists)
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/test_Queue.cpp")
    add_executable(test_Queue 
        tests/test_Queue.cpp
    )
    target_include_directories(test_Queue PRIVATE include)
    target_compile_features(test_Queue PRIVATE cxx_std_17)

    # Add test to CTest
    add_test(NAME QueueTests COMMAND test_Queue)
endif()

message(STATUS "Queue project configured")