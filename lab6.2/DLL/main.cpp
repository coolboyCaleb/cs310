#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

int main() {
    DoublyLinkedList dll;
    cout << "Testing Doubly Linked List" << endl;

    // Test insertHead
    cout << "Testing insertHead..." << endl;
    dll.insertHead(10);
    dll.insertHead(20);
    dll.insertHead(30);
    
    // Test insertTail
    cout << "Testing insertTail..." << endl;
    dll.insertTail(5);
    dll.insertTail(1);
    
    // Test findMiddle
    cout << "Testing findMiddle..." << endl;
    Node* middle = dll.findMiddle(nullptr);  // Pass appropriate head

    // Test hasCycle
    cout << "Testing hasCycle..." << endl;
    bool cycle = dll.hasCycle(nullptr);  // Pass appropriate head
    cout << "Has cycle: " << (cycle ? "Yes" : "No") << "" << endl;
    
    // Test deleteHead
    cout << "Testing deleteHead..." << endl;
    // dll.deleteHead(head, tail, val);
    
    // Test deleteTail
    cout << "Testing deleteTail..." << endl;
    // dll.deleteTail(head, tail, val);
    
    cout << "All tests completed" << endl;
    
    return 0;
}
