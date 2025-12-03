#ifndef QUEUE_H
#define QUEUE_H
#include "LinkedList.h" // Reuses Node
class Queue
{
public:
   Node *front;
   Node *rear;
   Queue() : front(nullptr), rear(nullptr) {}
   void enqueue(int val);
   int dequeue();
   bool isEmpty();
   
   // Recursive problem functions
   void recursiveReverse();
   void recursiveEnqueue(int val);
   int recursiveDequeue();
   void interleaveHalves();
   void generateBinaryNumbers(int n);
};
#endif
