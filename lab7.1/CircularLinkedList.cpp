#include "CircularLinkedList.h"
#include <iostream>

// Recursive problem functions
// Time Complexity: O(n) where n is the number of nodes in the cycle
// Space Complexity: O(1) - iterative approach
int CircularLinkedList::cycleLength(CNode* head) {
    // Helper function to count cycle length
    if (head == nullptr)
        return 0;
    
    int length = 1;
    CNode* current = head->next;
    
    while (current != head) {
        length++;
        current = current->next;
    }
    
    return length;
}

// Time Complexity: O(n) where n is the number of nodes (worst case inserts at end)
// Space Complexity: O(1) - iterative approach
CNode* CircularLinkedList::sortedInsert(CNode* head, int val) {
    CNode* newNode = new CNode(val);
    
    // Case 1: Empty list
    if (head == nullptr) {
        newNode->next = newNode;
        return newNode;
    }
    
    // Case 2: Insert at the beginning
    if (val <= head->data) {
        // Find the last node
        CNode* last = head;
        while (last->next != head) {
            last = last->next;
        }
        newNode->next = head;
        last->next = newNode;
        return newNode;
    }
    
    // Case 3: Insert in the middle or end
    CNode* current = head;
    while (current->next != head && current->next->data < val) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    
    return head;
}

// Time Complexity: O(1) - constant time operation
// Space Complexity: O(1) - no extra space needed
void CircularLinkedList::deleteNodeWithoutHead(CNode* node) {
    // Copy data from next node to current node
    if (node == nullptr || node->next == node) {
        // Can't delete if it's the only node or null
        return;
    }
    
    CNode* nextNode = node->next;
    node->data = nextNode->data;
    node->next = nextNode->next;
    delete nextNode;
}

// Time Complexity: O(n) where n is the number of nodes
// Space Complexity: O(1) - iterative approach using two pointers
CNode* CircularLinkedList::recursiveSplit(CNode* head, int& count) {
    // Base case: empty or single node
    if (head == nullptr || head->next == head) {
        count = (head != nullptr) ? 1 : 0;
        return nullptr;
    }
    
    // Use two pointers to find the middle
    CNode* slow = head;
    CNode* fast = head;
    
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Split the list
    CNode* secondHalf = slow->next;
    slow->next = head; // First half remains circular
    
    // Make second half circular
    CNode* temp = secondHalf;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = secondHalf;
    
    // Count nodes in first half
    count = 0;
    CNode* current = head;
    do {
        count++;
        current = current->next;
    } while (current != head);
    
    return secondHalf;
}

// Time Complexity: O(n) where n is the number of people
// Space Complexity: O(n) due to recursion stack
int CircularLinkedList::josephus(int n, int k) {
    // Base case: if only one person remains
    if (n == 1)
        return 1;
    
    // Recursive case: position after elimination is (josephus(n-1, k) + k - 1) % n + 1
    return (josephus(n - 1, k) + k - 1) % n + 1;
}
