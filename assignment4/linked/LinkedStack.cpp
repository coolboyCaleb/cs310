#include "Stack.h"
#include <stdexcept>

Stack::Stack()
{
   top = nullptr;
}
Stack::~Stack()
{
   makeEmpty();
}

void Stack::push(ItemType item)
{
   Node *newNode = new Node(item);
   newNode->next = top;
   top = newNode;
}

ItemType Stack::pop()
{
   if (isEmpty())
   {
      return -999;
   }
   else
   {
      Node *temp = top;
      ItemType data = temp->data;
      top = temp->next;
      delete temp;
      return data;
   }
}
ItemType Stack::peek()
{
   return top ? top->data : -999;
}

bool Stack::isEmpty()
{
   return top == nullptr;
}
bool Stack::isFull()
{
   return false;
}
void Stack::makeEmpty()
{
   while (top != nullptr)
   {
      Node *temp = top;
      top = top->next;
      delete temp;
   }
}