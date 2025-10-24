#ifndef StackType_H
#define StackType_H

#include "ItemType.h"

class FullStack
{
};
class EmptyStack
{
};

class StackType
{
private:
   int top;
   int maxStack;
   ItemType *items;

public:
   StackType();
   StackType(int max);
   ~StackType();

   bool IsEmpty() const;
   bool IsFull() const;

   void Push(ItemType newItem);
   void Pop();
   ItemType Top();
};

#endif // StackType_H