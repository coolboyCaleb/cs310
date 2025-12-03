#include "SortedLinkedList.h"
#include <iostream>

// Recursive problem functions
// Time Complexity: O(log n) where n is the size of the list
// Space Complexity: O(log n) due to recursion stack
bool SortedLinkedList::recursiveBinarySearch(Node* head, int val, int size) {
    // Base case
    if (head == nullptr || size == 0)
        return false;
    
    // Find middle element
    int mid = size / 2;
    Node* current = head;
    for (int i = 0; i < mid; i++) {
        current = current->next;
    }
    
    // Check if found
    if (current->data == val)
        return true;
    else if (current->data > val)
        // Search in left half
        return recursiveBinarySearch(head, val, mid);
    else
        // Search in right half
        return recursiveBinarySearch(current->next, val, size - mid - 1);
}

// Time Complexity: O(n^2) worst case, O(n log n) average case where n is the number of nodes
// Space Complexity: O(n) due to recursion stack (worst case)
Node* SortedLinkedList::quickSort(Node* head) {
    // Base case
    if (head == nullptr || head->next == nullptr)
        return head;
    
    // Partition around first element
    Node* pivot = head;
    Node* smaller = nullptr;
    Node* larger = nullptr;
    Node* equal = nullptr;
    
    Node* current = head->next;
    while (current != nullptr) {
        Node* next = current->next;
        if (current->data < pivot->data) {
            current->next = smaller;
            smaller = current;
        } else if (current->data > pivot->data) {
            current->next = larger;
            larger = current;
        } else {
            current->next = equal;
            equal = current;
        }
        current = next;
    }
    
    // Recursively sort smaller and larger parts
    smaller = quickSort(smaller);
    larger = quickSort(larger);
    
    // Connect: smaller -> equal -> pivot -> larger
    pivot->next = larger;
    if (equal != nullptr) {
        Node* temp = equal;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = pivot;
        if (smaller != nullptr) {
            temp = smaller;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = equal;
            return smaller;
        }
        return equal;
    }
    
    if (smaller != nullptr) {
        Node* temp = smaller;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = pivot;
        return smaller;
    }
    
    return pivot;
}

// Helper function to merge two sorted lists
// Time Complexity: O(n + m) where n and m are lengths of the two lists
// Space Complexity: O(n + m) due to recursion stack
static Node* merge(Node* left, Node* right) {
    if (left == nullptr)
        return right;
    if (right == nullptr)
        return left;
    
    if (left->data <= right->data) {
        left->next = merge(left->next, right);
        return left;
    } else {
        right->next = merge(left, right->next);
        return right;
    }
}

// Helper function to split list into two halves
// Time Complexity: O(n) where n is the number of nodes
// Space Complexity: O(1) - iterative approach
static void splitList(Node* head, Node*& left, Node*& right) {
    if (head == nullptr || head->next == nullptr) {
        left = head;
        right = nullptr;
        return;
    }
    
    Node* slow = head;
    Node* fast = head->next;
    
    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    
    left = head;
    right = slow->next;
    slow->next = nullptr;
}

// Time Complexity: O(n log n) where n is the number of nodes
// Space Complexity: O(log n) due to recursion stack
Node* SortedLinkedList::mergeSort(Node* head) {
    // Base case
    if (head == nullptr || head->next == nullptr)
        return head;
    
    // Split the list into two halves
    Node* left = nullptr;
    Node* right = nullptr;
    splitList(head, left, right);
    
    // Recursively sort both halves
    left = mergeSort(left);
    right = mergeSort(right);
    
    // Merge the sorted halves
    return merge(left, right);
}

// Time Complexity: O(n log n) where n is the number of nodes (uses mergeSort)
// Space Complexity: O(log n) due to recursion stack
Node* SortedLinkedList::heapStyleSimulation(Node* head) {
    // This simulates heap operations on a linked list
    // For simplicity, we'll just return the list sorted (heap would maintain max/min heap property)
    // This is a placeholder - actual heap simulation would be more complex
    return mergeSort(head);
}

// Time Complexity: O(n^2) where n is the number of nodes
// Space Complexity: O(n) due to recursion stack
Node* SortedLinkedList::insertionSort(Node* head) {
    // Base case
    if (head == nullptr || head->next == nullptr)
        return head;
    
    // Recursively sort the rest of the list
    head->next = insertionSort(head->next);
    
    // Insert current node in sorted position
    if (head->data > head->next->data) {
        Node* current = head;
        head = head->next;
        current->next = nullptr;
        
        // Find the correct position to insert
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data < current->data) {
            temp = temp->next;
        }
        current->next = temp->next;
        temp->next = current;
    }
    
    return head;
}
