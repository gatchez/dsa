#include "Stack.h"
#include <iostream>
#include <stdexcept>
#include <string>

using namespace dsa;
using namespace std;

void testIntStack() {
    cout << "=== Testing Stack<int> ===" << endl;
    Stack<int> stack;

    // Test empty stack
    cout << "1. Testing empty stack:" << endl;
    cout << "   Is empty: " << (stack.isEmpty() ? "Yes" : "No") << endl;
    cout << "   Size: " << stack.size() << endl;
    try {
        int top = stack.top();
        cout << "   Top: " << top << endl;
    } catch (const out_of_range& e) {
        cout << "   Top exception: " << e.what() << endl;
    }
    try {
        int popped = stack.pop();
        cout << "   Pop: " << popped << endl;
    } catch (const out_of_range& e) {
        cout << "   Pop exception: " << e.what() << endl;
    }
    stack.print();

    // Test push operations
    cout << "\n2. Pushing elements: 10, 20, 30, 40, 50" << endl;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    cout << "   Is empty: " << (stack.isEmpty() ? "Yes" : "No") << endl;
    cout << "   Size: " << stack.size() << endl;
    cout << "   Top: " << stack.top() << endl;
    stack.print();

    // Test pop operations
    cout << "\n3. Popping elements:" << endl;
    cout << "   Popped: " << stack.pop() << endl;
    cout << "   Size: " << stack.size() << endl;
    cout << "   Top: " << stack.top() << endl;
    stack.print();

    // Test multiple pops
    cout << "\n4. Popping remaining elements:" << endl;
    while (!stack.isEmpty()) {
        cout << "   Popped: " << stack.pop() << ", Size: " << stack.size() << endl;
    }
    cout << "   Is empty: " << (stack.isEmpty() ? "Yes" : "No") << endl;
    stack.print();

    // Test large number of elements
    cout << "\n5. Testing with large number of elements (100):" << endl;
    for (int i = 1; i <= 100; ++i) {
        stack.push(i);
    }
    cout << "   Size: " << stack.size() << endl;
    cout << "   Top: " << stack.top() << endl;
    // Pop some
    for (int i = 0; i < 10; ++i) {
        stack.pop();
    }
    cout << "   After popping 10, Size: " << stack.size() << endl;
    cout << "   Top: " << stack.top() << endl;
    // Clear
    while (!stack.isEmpty()) {
        stack.pop();
    }
    cout << "   After clearing, Size: " << stack.size() << endl;
}

void testStringStack() {
    cout << "\n=== Testing Stack<string> ===" << endl;
    Stack<string> stack;

    // Test with strings
    cout << "1. Pushing strings: 'hello', 'world', 'stack'" << endl;
    stack.push("hello");
    stack.push("world");
    stack.push("stack");
    cout << "   Size: " << stack.size() << endl;
    cout << "   Top: " << stack.top() << endl;
    stack.print();

    // Pop one
    cout << "\n2. Popping one:" << endl;
    cout << "   Popped: " << stack.pop() << endl;
    cout << "   Size: " << stack.size() << endl;
    stack.print();

    // Clear
    while (!stack.isEmpty()) {
        stack.pop();
    }
    cout << "\n3. After clearing:" << endl;
    cout << "   Is empty: " << (stack.isEmpty() ? "Yes" : "No") << endl;
    stack.print();
}

void testCharStack() {
    cout << "\n=== Testing Stack<char> ===" << endl;
    Stack<char> stack;

    // Test with chars
    cout << "1. Pushing chars: 'a', 'b', 'c'" << endl;
    stack.push('a');
    stack.push('b');
    stack.push('c');
    cout << "   Size: " << stack.size() << endl;
    cout << "   Top: " << stack.top() << endl;
    stack.print();

    // Pop all
    cout << "\n2. Popping all:" << endl;
    while (!stack.isEmpty()) {
        cout << "   Popped: " << stack.pop() << endl;
    }
    cout << "   Is empty: " << (stack.isEmpty() ? "Yes" : "No") << endl;
    stack.print();
}

void testEdgeCases() {
    cout << "\n=== Testing Edge Cases ===" << endl;
    Stack<int> stack;

    // Push and pop alternating
    cout << "1. Alternating push/pop:" << endl;
    stack.push(1);
    cout << "   Pushed 1, Size: " << stack.size() << endl;
    stack.push(2);
    cout << "   Pushed 2, Size: " << stack.size() << endl;
    cout << "   Popped: " << stack.pop() << ", Size: " << stack.size() << endl;
    stack.push(3);
    cout << "   Pushed 3, Size: " << stack.size() << endl;
    cout << "   Popped: " << stack.pop() << ", Size: " << stack.size() << endl;
    cout << "   Popped: " << stack.pop() << ", Size: " << stack.size() << endl;
    cout << "   Is empty: " << (stack.isEmpty() ? "Yes" : "No") << endl;

    // Test top without popping
    cout << "\n2. Testing top() repeatedly:" << endl;
    stack.push(100);
    stack.push(200);
    stack.push(300);
    for (int i = 0; i < 3; ++i) {
        cout << "   Top: " << stack.top() << endl;
    }
    stack.print();

    // Clear and test empty operations again
    while (!stack.isEmpty()) {
        stack.pop();
    }
    cout << "\n3. After clearing, testing empty operations:" << endl;
    try {
        stack.top();
    } catch (const out_of_range& e) {
        cout << "   Top exception: " << e.what() << endl;
    }
    try {
        stack.pop();
    } catch (const out_of_range& e) {
        cout << "   Pop exception: " << e.what() << endl;
    }
}

int main() {
    try {
        testIntStack();
        testStringStack();
        testCharStack();
        testEdgeCases();

        cout << "\n=== All tests completed successfully! ===" << endl;
    } catch (const exception& e) {
        cout << "Unexpected exception: " << e.what() << endl;
        return 1;
    }

    return 0;
}