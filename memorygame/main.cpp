#include <iostream>
#include "MemoryGame.cpp"
#include "LinkedList.cpp"

using namespace std;

int main(){
   MemoryGame game;

   // Terminal version:
   while (!game.allMatched())
   {
      game.displayTerminal();
      int row, col;
      cout << "Enter row col: ";
      cin >> row >> col;
      if (game.flipCard(row, col))
         game.checkMatch();
   }
   cout << "You win!\n";

   // game.displaySFML();

   // game.displayTerminalNcurses();

   return 0;
}