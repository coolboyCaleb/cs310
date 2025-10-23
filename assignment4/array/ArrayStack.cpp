#include "Stack.h"
#include <stdexcept>

Stack::Stack()
{
   top = -1;
   stackArray = new int[MAX_STACK];
}

Stack::~Stack()
{
   delete[] stackArray;
}

void Stack::push(ItemType item)
{
   if (isFull())
   {
      throw std::overflow_error("Stack is full.");
   }
   else
   {
      stackArray[++top] = item;
   }
}

ItemType Stack::pop()
{
   if (isEmpty())
   {
      throw std::underflow_error("Stack is empty.");
   }
   else
   {
      return stackArray[top--];
   }
}

ItemType Stack::peek()
{
   return stackArray[top];
}

void Stack::makeEmpty()
{
   top = -1;
}

bool Stack::isEmpty()
{
   return top == -1;
}

bool Stack::isFull()
{
   return top == MAX_STACK - 1;
}