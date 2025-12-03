#ifndef STACK_H
#define STACK_H
#include "LinkedList.h" // Reuses Node
class Stack
{
public:
   Node *top;
   Stack() : top(nullptr) {}
   void push(int val);
   int pop();
   bool isEmpty();
   
   // Recursive problem functions
   void recursiveSort();
   void recursiveReverse();
   int postfixEval(const char* expr);
   bool checkParentheses(const char* expr);
};
#endif