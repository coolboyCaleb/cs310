#ifndef MEMORYGAME_H
#define MEMORYGAME_H

#include "LinkedList.h"

class MemoryGame
{
private:
   LinkedList cards;
   int rows, cols;
   int firstFlipIndex, secondFlipIndex = -1;
   void initializeDeck(); // push two of each value
   void shuffle();        // copy -> shuffle -> rebuild list

public:
   MemoryGame()
       : rows(4), cols(4), firstFlipIndex(-1), secondFlipIndex(-1)
   {
      initializeDeck();
      shuffle();
   }
   // actions
   bool flipCard(int row, int col); // returns true when second flip occurs
   bool checkMatch();               // resolves the two flips; returns allMatched()

   // queries
   bool allMatched() const;
   int getRows() const { return rows; }
   int getCols() const { return cols; }
   int size() const { return rows * cols; }

   //display functions
   void displayTerminal();
   void displaySFML();
   void displayTerminalNcurses();
};

#endif