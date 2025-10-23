#ifndef STACK_H
#define STACK_H

//for array/assignment 1-2
const int MAX_STACK = 100;
typedef int ItemType;

class Stack{
   private:
      int top;
      int *stackArray;
   public:
      Stack();        // constructor
      ~Stack();       // destructor
      bool isEmpty(); // returns true if empty
      bool isFull(); // returns true if full
      void push(ItemType item); // pushes/adds item to stack
      ItemType pop(); // pops/removes item from stack, returns top
      ItemType peek(); // returns top w/o removing
      void makeEmpty(); // making the list/array empty
};
#endif