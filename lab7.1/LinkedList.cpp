#include "LinkedList.h"
#include <iostream>

// Recursive problem functions
// Time Complexity: O(n) where n is the number of nodes
// Space Complexity: O(n) due to recursion stack
Node* LinkedList::reverseRecursive(Node* head) {
    // BASE CASE
    if (head == nullptr || head->next == nullptr)
        return head;

    // 1. Reverse everything after this head
    Node *newHead = reverseRecursive(head->next);

    // 2. Fix links so that head->next now points back to head
    head->next->next = head; // the head after "head" points BACK to "head"
    head->next = nullptr;    // "head" becomes the new tail of that partial list

    // 3. Return the head of the reversed list (which never changes now)
    return newHead;
}

// Time Complexity: O(n) where n is the number of nodes
// Space Complexity: O(1) - iterative two-pointer approach
Node* findMiddleRecursive(Node *slow, Node *fast)
{
    // If fast has reached the end, slow is at the middle
    if (fast == nullptr || fast->next == nullptr)
        return slow;

    // Move slow by one, fast by two, and recurse
    return findMiddleRecursive(slow->next, fast->next->next);
}
Node* LinkedList::findMiddle(Node *node)
{
    // Base case: empty list or single node
    if (node == nullptr || node->next == nullptr)
        return node;
    // Helper function
    return findMiddleRecursive(head, head);
}

// Time Complexity: O(n) where n is the number of nodes (Floyd's cycle detection)
// Space Complexity: O(1) - only uses two pointers
bool LinkedList::detectCycle(Node* head) {
    // Helper function for cycle detection using two pointers
    if (head == nullptr || head->next == nullptr)
        return false;
    
    Node* slow = head;
    Node* fast = head;
    
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    
    return false;
}

// Time Complexity: O(n + m) where n and m are lengths of the two lists
// Space Complexity: O(n + m) due to recursion stack
Node* LinkedList::mergeSortedLists(Node* l1, Node* l2) {
    // Base cases
    if (l1 == nullptr)
        return l2;
    if (l2 == nullptr)
        return l1;
    
    // Recursive case: choose the smaller value and recurse
    if (l1->data <= l2->data) {
        l1->next = mergeSortedLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeSortedLists(l1, l2->next);
        return l2;
    }
}

// Time Complexity: O(n) where n is the number of nodes
// Space Complexity: O(n) due to recursion stack
Node* LinkedList::removeDuplicates(Node* head) {
    // Base case
    if (head == nullptr || head->next == nullptr)
        return head;
    
    // Recursively remove duplicates from the rest of the list
    head->next = removeDuplicates(head->next);
    
    // If current node's data equals next node's data, skip current node
    if (head->data == head->next->data) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    return head;
}

// Time Complexity: O(n^2) worst case where n is the number of nodes
// Space Complexity: O(n) due to recursion stack
// Note: Worst case occurs when all nodes >= x, requiring traversal for each node
Node* LinkedList::partitionAroundValue(Node* head, int x) {
    // Base case
    if (head == nullptr || head->next == nullptr)
        return head;
    
    // Recursively partition the rest of the list
    Node* rest = partitionAroundValue(head->next, x);
    
    // If current node is less than x, it should be at the front
    if (head->data < x) {
        head->next = rest;
        return head;
    } else {
        // Find the last node in the "less than x" part
        Node* temp = rest;
        if (temp != nullptr && temp->data < x) {
            while (temp->next != nullptr && temp->next->data < x) {
                temp = temp->next;
            }
            head->next = temp->next;
            temp->next = head;
            return rest;
        } else {
            // All remaining nodes are >= x
            head->next = rest;
            return head;
        }
    }
}
