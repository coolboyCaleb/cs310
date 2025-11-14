#include <iostream>
#include "ArrayQueue.h"

int main() {
    std::cout << "=== Testing Array-Based Queue ===\n\n";
    
    Queue q;
    
    // Test enqueue
    std::cout << "Testing enqueue...\n";
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    
    // Test getFront
    std::cout << "Testing getFront...\n";
    std::cout << "Front element: " << q.getFront() << "\n";
    
    // Test dequeue
    std::cout << "Testing dequeue...\n";
    int val = q.dequeue();
    std::cout << "Dequeued: " << val << "\n";
    
    // Test isEmpty
    std::cout << "Testing isEmpty...\n";
    std::cout << "Is empty: " << (q.isEmpty() ? "Yes" : "No") << "\n";
    
    // Test isFull
    std::cout << "Testing isFull...\n";
    std::cout << "Is full: " << (q.isFull() ? "Yes" : "No") << "\n";
    
    // Test reverseK
    std::cout << "Testing reverseK...\n";
    q.reverseK(q, 2);
    
    // Test generateBinary
    std::cout << "Testing generateBinary...\n";
    q.generateBinary(5);
    
    // Test StackFromQueue
    std::cout << "Testing StackFromQueue...\n";
    StackFromQueue sq;
    sq.push(1);
    sq.push(2);
    sq.push(3);
    std::cout << "Pop from stack (using queues): " << sq.pop() << "\n";
    
    // Test interleave
    std::cout << "Testing interleave...\n";
    Queue q2;
    for(int i = 1; i <= 8; i++) q2.enqueue(i);
    interleave(q2);
    
    // Test sliding window maximum
    std::cout << "Testing slidingWindowMax...\n";
    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int out[6];
    slidingWindowMax(arr, 8, 3, out);
    std::cout << "Window maxes: ";
    for(int i = 0; i < 6; i++) std::cout << out[i] << " ";
    std::cout << "\n";
    
    std::cout << "\n=== All tests completed ===\n";
    
    return 0;
}
