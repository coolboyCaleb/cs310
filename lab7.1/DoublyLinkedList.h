#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
struct DNode
{
   int data;
   DNode *next;
   DNode *prev;
   DNode(int val) : data(val), next(nullptr), prev(nullptr) {}
};
class DoublyLinkedList
{
public:
   DNode *head;
   DoublyLinkedList() : head(nullptr) {}
   void insert(int val); // Iterative insert for setup
   void print();         // For debugging
   
   // Recursive problem functions
   DNode* recursiveReverse(DNode* node);
   DNode* sortedInsert(DNode* head, int val);
   DNode* deleteByValue(DNode* head, int val);
   bool pairSumCheck(DNode* head, int target);
   DNode* multilevelFlatten(DNode* head);
   DNode* rotateByK(DNode* head, int k);
};
#endif