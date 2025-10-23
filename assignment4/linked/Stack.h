#ifndef STACK_H
#define STACK_H

typedef int ItemType;

// for linked/assignment 3
struct Node
{
   ItemType data;
   Node *next;
   Node(ItemType item) : data(item), next(nullptr) {}
};

class Stack{
   private:
      Node *top;
   public:
      Stack(); // constructor
      ~Stack(); // destructor
      bool isEmpty(); // returns true if empty
      bool isFull(); // returns true if full
      void push(ItemType item); // pushes/adds item to stack
      ItemType pop(); // pops/removes item from stack, returns top
      ItemType peek(); // returns top w/o removing
      void makeEmpty(); // making the list/array empty
};

#endif