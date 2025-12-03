#ifndef LINKEDLIST_H
#define LINKEDLIST_H
struct Node
{
   int data;
   Node *next;
   Node(int val) : data(val), next(nullptr) {}
};
class LinkedList
{
public:
   Node *head;
   LinkedList() : head(nullptr) {}
   void insert(int val); // Iterative insert for setup
   void print();         // For debugging
   
  // Recursive problem functions
  Node* reverseRecursive(Node* head);
  Node* recursiveReverse(Node* head) { return reverseRecursive(head); } // Alias for main.cpp
  Node *findMiddle(Node *node);
   bool detectCycle(Node* head);
   Node* mergeSortedLists(Node* l1, Node* l2);
   Node* removeDuplicates(Node* head);
   Node* partitionAroundValue(Node* head, int x);
};
#endif