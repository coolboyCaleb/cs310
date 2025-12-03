#include "QueType.h"

QueType::QueType(int max){
   maxQue = max;
   items = new ItemType[maxQue];
   front = maxQue - 1;
   rear = maxQue - 1;
   length = 0;
}

QueType::QueType(){
   maxQue = 100;
   items = new ItemType[maxQue];
   front = maxQue - 1;
   rear = maxQue - 1;
   length = 0;
}

QueType::~QueType()
{
   delete[] items;
}

void QueType::MakeEmpty()
{
   front = maxQue - 1;
   rear = maxQue - 1;
   length = 0;
}

bool QueType::IsEmpty() const
{
   return length == 0;
}

bool QueType::IsFull() const
{
   return length == maxQue;
}

void QueType::Enqueue(ItemType newItem)
{
   if(IsFull()){
      throw std::overflow_error("Queue is full");
   }
   rear = (rear + 1) % maxQue;
   items[rear] = newItem;
   length++;
}

void QueType::Dequeue(ItemType& item)
{
  if (IsEmpty())
    throw std::underflow_error("Queue is empty");
  else
  {
    front = (front + 1) % maxQue;
    item = items[front];
    length--;
  }
}