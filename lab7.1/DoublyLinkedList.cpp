#include "DoublyLinkedList.h"
#include <iostream>

// Recursive problem functions
// Time Complexity: O(n) where n is the number of nodes
// Space Complexity: O(n) due to recursion stack
DNode* DoublyLinkedList::recursiveReverse(DNode* node) {
    // Base case
    if (node == nullptr || node->next == nullptr)
        return node;
    
    // Recursively reverse the rest of the list
    DNode* newHead = recursiveReverse(node->next);
    
    // Reverse the links for current node
    node->next->next = node;
    node->prev = node->next;
    node->next = nullptr;
    
    // Update prev pointer of newHead
    newHead->prev = nullptr;
    
    return newHead;
}

// Time Complexity: O(n) where n is the number of nodes (worst case inserts at end)
// Space Complexity: O(n) due to recursion stack
DNode* DoublyLinkedList::sortedInsert(DNode* head, int val) {
    // Base case: insert at the beginning or empty list
    if (head == nullptr || head->data >= val) {
        DNode* newNode = new DNode(val);
        newNode->next = head;
        if (head != nullptr)
            head->prev = newNode;
        return newNode;
    }
    
    // Recursively insert in the rest of the list
    head->next = sortedInsert(head->next, val);
    if (head->next != nullptr)
        head->next->prev = head;
    
    return head;
}

// Time Complexity: O(n) where n is the number of nodes (worst case element at end)
// Space Complexity: O(n) due to recursion stack
DNode* DoublyLinkedList::deleteByValue(DNode* head, int val) {
    // Base case
    if (head == nullptr)
        return nullptr;
    
    // If current node is the one to delete
    if (head->data == val) {
        DNode* temp = head->next;
        if (temp != nullptr)
            temp->prev = nullptr;
        delete head;
        return temp;
    }
    
    // Recursively delete from the rest of the list
    head->next = deleteByValue(head->next, val);
    if (head->next != nullptr)
        head->next->prev = head;
    
    return head;
}

// Time Complexity: O(n) where n is the number of nodes
// Space Complexity: O(1) - uses two pointers, no recursion
bool DoublyLinkedList::pairSumCheck(DNode* head, int target) {
    // Helper function to find pair sum using two pointers
    if (head == nullptr || head->next == nullptr)
        return false;
    
    // Find the tail of the list
    DNode* tail = head;
    while (tail->next != nullptr)
        tail = tail->next;
    
    // Use two pointers from both ends
    DNode* left = head;
    DNode* right = tail;
    
    while (left != right && right->next != left) {
        int sum = left->data + right->data;
        if (sum == target)
            return true;
        else if (sum < target)
            left = left->next;
        else
            right = right->prev;
    }
    
    return false;
}

// Time Complexity: O(n) where n is the number of nodes
// Space Complexity: O(n) due to recursion stack
DNode* DoublyLinkedList::multilevelFlatten(DNode* head) {
    // Base case
    if (head == nullptr)
        return head;
    
    // Recursively process the rest
    head->next = multilevelFlatten(head->next);
    if (head->next != nullptr)
        head->next->prev = head;
    
    return head;
}

// Time Complexity: O(n) where n is the number of nodes
// Space Complexity: O(1) - iterative approach, no recursion
DNode* DoublyLinkedList::rotateByK(DNode* head, int k) {
    // Base case
    if (head == nullptr || k == 0)
        return head;
    
    // Find the length of the list
    int length = 0;
    DNode* current = head;
    while (current != nullptr) {
        length++;
        current = current->next;
    }
    
    // Normalize k
    k = k % length;
    if (k == 0)
        return head;
    
    // Find the (length - k)th node
    current = head;
    for (int i = 1; i < length - k; i++) {
        current = current->next;
    }
    
    // current now points to the new tail
    DNode* newHead = current->next;
    current->next = nullptr;
    newHead->prev = nullptr;
    
    // Find the end of the second part and connect
    DNode* temp = newHead;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = head;
    head->prev = temp;
    
    return newHead;
}
