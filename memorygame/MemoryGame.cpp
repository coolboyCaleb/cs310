#include "MemoryGame.h"
#include "Card.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std; 

void MemoryGame::initializeDeck()
{
   int pairs = (rows * cols) / 2;
   for (int i = 0; i < pairs; ++i)
   {
      char v = static_cast<char>('A' + i);
      cards.insert(Card(v));
      cards.insert(Card(v));
   }
}

void MemoryGame::shuffle()
{
   vector<Card> temp;
   temp.reserve(cards.size());
   for (int i = 0; i < cards.size(); ++i)
   {
      temp.push_back(cards.getAt(i)); // assumes getAt returns Card by value or ref convertible
   }

   random_device rd;
   std::mt19937 g(rd());
   std::shuffle(temp.begin(), temp.end(), g);

   // Clear list (manually, since no clear method)
   while (cards.size() > 0){
      cards.removeAt(0);
   }
   for (const auto &c : temp){
      cards.insert(c);
   }
}

bool MemoryGame::flipCard(int row, int col)
{
   int index = row * cols + col;
   if (index < 0 || index >= cards.size())
      return false;

   Card &c = cards.getAt(index);
   if (c.isFaceUp || c.isMatched)
      return false;

   // if two are already flipped and not checked yet, block
   if (firstFlipIndex != -1 && secondFlipIndex != -1)
      return false;

   c.isFaceUp = true;
   if (firstFlipIndex == -1)
   {
      firstFlipIndex = index;
      return false; // only first flip
   }
   else
   {
      secondFlipIndex = index;
      return true; // second flip done
   }
}

bool MemoryGame::checkMatch()
{
   if (firstFlipIndex == -1 || secondFlipIndex == -1)
      return false;

   Card &a = cards.getAt(firstFlipIndex);
   Card &b = cards.getAt(secondFlipIndex);

   if (a.value == b.value)
   {
      a.isMatched = true;
      b.isMatched = true; // keep them face-up
   }
   else
   {
      a.isFaceUp = false;
      b.isFaceUp = false; // flip back if incorrect
   }

   firstFlipIndex = -1;
   secondFlipIndex = -1;
   return allMatched();
}

bool MemoryGame::allMatched() const
{
   for (int i = 0; i < cards.size(); ++i)
   {
      if (!cards.getAt(i).isMatched)
         return false;
   }
   return true;
}
void MemoryGame::displayTerminal()
{
   std::cout << "Memory Game Grid:\n";
   for (int r = 0; r < rows; r++)
   {
      for (int c = 0; c < cols; c++)
      {
         int idx = r * cols + c;
         Card &card = cards.getAt(idx);
         if (card.isMatched)
         {
            std::cout << "[ ] ";
         }
         else if (card.isFaceUp)
         {
            std::cout << "[" << card.value << "] ";
         }
         else
         {
            std::cout << "[*] ";
         }
      }
      std::cout << "\n";
   }
}