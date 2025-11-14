#include <iostream>
#include "CircularLinkedList.h"

int main() {
    std::cout << "=== Testing Circular Linked List ===\n\n";
    
    CircularLinkedList cll;
    Node* head = nullptr;
    
    // Test insertHead
    std::cout << "Testing insertHead...\n";
    cll.insertHead(head, 10);
    cll.insertHead(head, 20);
    cll.insertHead(head, 30);
    
    // Test insertTail
    std::cout << "Testing insertTail...\n";
    cll.insertTail(head, 5);
    cll.insertTail(head, 1);
    
    // Test cycleLength
    std::cout << "Testing cycleLength...\n";
    int len = cll.cycleLength(head);
    std::cout << "Cycle length: " << len << "\n";
    
    // Test sortedInsert
    std::cout << "Testing sortedInsert...\n";
    cll.sortedInsert(head, 15);
    
    // Test Josephus problem
    std::cout << "Testing josephus...\n";
    int survivor = cll.josephus(head, 3);
    std::cout << "Josephus survivor: " << survivor << "\n";
    
    // Test split
    std::cout << "Testing split...\n";
    auto [h1, h2] = cll.split(head);
    
    // Test deleteHead
    std::cout << "Testing deleteHead...\n";
    cll.deleteHead(head);
    
    // Test deleteTail
    std::cout << "Testing deleteTail...\n";
    cll.deleteTail(head);
    
    std::cout << "\n=== All tests completed ===\n";
    
    return 0;
}
