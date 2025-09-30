#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Card.h"

struct Node
{
   Card data;
   Node *next;
   Node(Card c) : data(c), next(nullptr) {}
};

class LinkedList
{
private:

   Node *head; // start of list
   int length; // number of cards currently in the list

public:
   // Basic state
   int size() const;
   bool empty() const;
   void clear();

   LinkedList() : head(nullptr), length(0) {}
   ~LinkedList()
   {
      Node *current = head;
      while (current)
      {
         Node *temp = current;
         current = current->next;
         delete temp;
      }
   }
   void insert(Card c); // append a card to the end

   // Index access
   Card &getAt(int index);
   const Card &getAt(int index) const;
   void removeAt(int index);
};

#endif