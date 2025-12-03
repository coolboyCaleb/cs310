#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H
struct CNode
{
   int data;
   CNode *next;
   CNode(int val) : data(val), next(nullptr) {}
};
class CircularLinkedList
{
public:
   CNode *head;
   CircularLinkedList() : head(nullptr) {}
   void insert(int val); // Iterative insert, makes circular
   void print();         // For debugging, handles cycle
   
   // Recursive problem functions
   int cycleLength(CNode* head);
   CNode* sortedInsert(CNode* head, int val);
   void deleteNodeWithoutHead(CNode* node);
   CNode* recursiveSplit(CNode* head, int& count);
   int josephus(int n, int k);
};
#endif