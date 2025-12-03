#include "Queue.h"
#include <iostream>

// Recursive problem functions

// Helper function to reverse queue recursively
// Time Complexity: O(n) where n is the number of elements
// Space Complexity: O(n) due to recursion stack
void reverseQueueHelper(Node*& front, Node*& rear) {
    if (front == nullptr)
        return;
    
    int data = front->data;
    Node* temp = front;
    front = front->next;
    if (front == nullptr)
        rear = nullptr;
    delete temp;
    
    reverseQueueHelper(front, rear);
    
    // Insert at rear
    Node* newNode = new Node(data);
    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}


void Queue::recursiveReverse() {
    reverseQueueHelper(front, rear);
}

// Time Complexity: O(1) - constant time operation
// Space Complexity: O(1) - no recursion used
void Queue::recursiveEnqueue(int val) {
    Node* newNode = new Node(val);
    
    if (rear == nullptr) {
        front = rear = newNode;
        return;
    }
    
    rear->next = newNode;
    rear = newNode;
}

// Time Complexity: O(1) - constant time operation
// Space Complexity: O(1) - no recursion used
int Queue::recursiveDequeue() {
    if (front == nullptr)
        return -1;
    
    int data = front->data;
    Node* temp = front;
    front = front->next;
    if (front == nullptr)
        rear = nullptr;
    delete temp;
    
    return data;
}

// Helper function to interleave
// Time Complexity: O(n) where n is the number of elements
// Space Complexity: O(n) due to recursion stack
void interleaveHelper(Node*& first, Node*& second) {
    if (first == nullptr || second == nullptr)
        return;
    
    Node* firstNext = first->next;
    Node* secondNext = second->next;
    
    first->next = second;
    if (firstNext != nullptr)
        second->next = firstNext;
    
    interleaveHelper(firstNext, secondNext);
}

// Time Complexity: O(n) where n is the number of elements
// Space Complexity: O(n) due to recursion stack
void Queue::interleaveHalves() {
    if (front == nullptr || front->next == nullptr)
        return;
    
    // Find the middle
    Node* slow = front;
    Node* fast = front;
    Node* prev = nullptr;
    
    while (fast != nullptr && fast->next != nullptr) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Split into two halves
    if (prev != nullptr)
        prev->next = nullptr;
    
    Node* secondHalf = slow;
    
    // Interleave using recursion
    interleaveHelper(front, secondHalf);
    
    // Update rear
    Node* temp = front;
    while (temp != nullptr && temp->next != nullptr)
        temp = temp->next;
    rear = temp;
}

// Time Complexity: O(n) where n is the number of binary numbers to generate
// Space Complexity: O(n) for the queue storage
void Queue::generateBinaryNumbers(int n) {
    if (n <= 0)
        return;
    
    // Clear the queue first
    while (!isEmpty()) {
        dequeue();
    }
    
    // Generate binary numbers using BFS approach
    enqueue(1); // Start with "1"
    
    for (int i = 1; i < n; i++) {
        int num = dequeue();
        std::cout << num << " ";
        
        // Generate next two binary numbers
        enqueue(num * 10);      // Append 0
        enqueue(num * 10 + 1);  // Append 1
    }
    
    // Print the last one
    if (!isEmpty()) {
        std::cout << front->data << std::endl;
    }
}
