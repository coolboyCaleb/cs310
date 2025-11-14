#include <iostream>
#include "LinkedQueue.h"

int main() {
    std::cout << "=== Testing Linked-List Queue ===\n\n";
    
    LinkedQueue lq;
    
    // Test enqueue
    std::cout << "Testing enqueue...\n";
    lq.enqueue(10);
    lq.enqueue(20);
    lq.enqueue(30);
    lq.enqueue(40);
    
    // Test getFront
    std::cout << "Testing getFront...\n";
    std::cout << "Front element: " << lq.getFront() << "\n";
    
    // Test dequeue
    std::cout << "Testing dequeue...\n";
    int val = lq.dequeue();
    std::cout << "Dequeued: " << val << "\n";
    
    // Test isEmpty
    std::cout << "Testing isEmpty...\n";
    std::cout << "Is empty: " << (lq.isEmpty() ? "Yes" : "No") << "\n";
    
    // Test middle
    std::cout << "Testing middle...\n";
    int mid = lq.middle(lq);
    std::cout << "Middle element: " << mid << "\n";
    
    // Test reverse
    std::cout << "Testing reverse...\n";
    lq.reverse(lq);
    
    // Test merge
    std::cout << "Testing merge...\n";
    LinkedQueue q1, q2;
    q1.enqueue(1);
    q1.enqueue(3);
    q1.enqueue(5);
    q2.enqueue(2);
    q2.enqueue(4);
    q2.enqueue(6);
    LinkedQueue merged = lq.merge(q1, q2);
    
    // Test removeDuplicates
    std::cout << "Testing removeDuplicates...\n";
    LinkedQueue q3;
    q3.enqueue(1);
    q3.enqueue(2);
    q3.enqueue(2);
    q3.enqueue(3);
    q3.enqueue(3);
    lq.removeDuplicates(q3);
    
    // Test rotateK
    std::cout << "Testing rotateK...\n";
    LinkedQueue q4;
    for(int i = 1; i <= 5; i++) q4.enqueue(i);
    lq.rotateK(q4, 2);
    
    std::cout << "\n=== All tests completed ===\n";
    
    return 0;
}
