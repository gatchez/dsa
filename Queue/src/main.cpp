#include "Queue.h"
#include <iostream>
#include <string>

using namespace dsa;
using namespace std;

void testIntQueue() {
    cout << "=== Testing Queue<int> ===" << endl;
    Queue<int> q;

    // Test empty queue
    cout << "Initial size: " << q.size() << ", isEmpty: " << (q.isEmpty() ? "true" : "false") << endl;

    // Enqueue elements
    cout << "Enqueueing: 10, 20, 30, 40" << endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.print();
    cout << "Size: " << q.size() << ", Front: " << q.front() << ", Rear: " << q.rear() << endl;

    // Dequeue
    cout << "Dequeue: " << q.dequeue() << endl;
    q.print();
    cout << "Size: " << q.size() << ", Front: " << q.front() << ", Rear: " << q.rear() << endl;

    // Dequeue more
    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Dequeue: " << q.dequeue() << endl;
    q.print();
    cout << "Size: " << q.size() << ", Front: " << q.front() << ", Rear: " << q.rear() << endl;

    // Dequeue last
    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Size: " << q.size() << ", isEmpty: " << (q.isEmpty() ? "true" : "false") << endl;

    // Try dequeue empty
    try {
        q.dequeue();
    } catch (const out_of_range& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    cout << endl;
}

void testStringQueue() {
    cout << "=== Testing Queue<string> ===" << endl;
    Queue<string> q;

    q.enqueue("Hello");
    q.enqueue("World");
    q.enqueue("DSA");
    q.print();
    cout << "Front: " << q.front() << ", Rear: " << q.rear() << endl;

    cout << "Dequeue: " << q.dequeue() << endl;
    q.print();

    cout << endl;
}

void testCharQueue() {
    cout << "=== Testing Queue<char> ===" << endl;
    Queue<char> q;

    q.enqueue('A');
    q.enqueue('B');
    q.enqueue('C');
    q.print();

    cout << "Dequeue: " << q.dequeue() << endl;
    q.print();

    cout << endl;
}

int main() {
    testIntQueue();
    testStringQueue();
    testCharQueue();

    cout << "All tests completed successfully!" << endl;
    return 0;
}