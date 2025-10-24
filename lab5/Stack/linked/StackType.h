// linked/StackType.h
#ifndef StackType_H
#define StackType_H

#include "ItemType.h"

class FullStack
{
};
class EmptyStack
{
};

struct NodeType
{
   ItemType info;
   NodeType *next;
};

class StackType
{
private:
   NodeType *topPtr;

public:
   StackType();
   ~StackType();

   bool IsFull() const;
   bool IsEmpty() const;

   void Push(ItemType newItem);
   void Pop();
   ItemType Top();
};

#endif // StackType_H