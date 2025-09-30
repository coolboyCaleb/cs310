#ifndef CARD_H
#define CARD_H

struct Card
{
   char value;     // e.g., 'A' through 'H' (8 pairs in a 4x4 grid)
   bool isFaceUp;  // true if currently flipped face-up
   bool isMatched; // true if permanently matched/removed from play

   Card() : value('?'), isFaceUp(false), isMatched(false) {}
   Card(char v) : value(v), isFaceUp(false), isMatched(false) {}
};

#endif