#include <iostream>
#include <stdexcept>
#include "LinkedList.h"

using namespace std;

void LinkedList::insert(Card card)
{
   Node *newNode = new Node(card);
   if (!head)
   {
      head = newNode;
   }
   else
   {
      Node *temp = head;
      while (temp->next)
         temp = temp->next;
      temp->next = newNode;
   }
   length++;
}
Card &LinkedList::getAt(int index)
{
   if (index < 0 || index >= length)
      throw std::out_of_range("Invalid index");
   Node *temp = head;
   for (int i = 0; i < index; i++)
      temp = temp->next;
   return temp->data;
}

const Card &LinkedList::getAt(int index) const
{
   if (index < 0 || index >= length)
      throw std::out_of_range("Invalid index");
   Node *temp = head;
   for (int i = 0; i < index; i++)
      temp = temp->next;
   return temp->data;
}
void LinkedList::removeAt(int index)
{
   if (index < 0 || index >= length)
      return;
   if (index == 0)
   {
      Node *temp = head;
      head = head->next;
      delete temp;
   }
   else
   {
      Node *prev = head;
      for (int i = 0; i < index - 1; i++)
         prev = prev->next;
      Node *temp = prev->next;
      prev->next = temp->next;
      delete temp;
   }
   length--;
}
int LinkedList::size() const { return length; }
