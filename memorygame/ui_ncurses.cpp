#include "MemoryGame.h"
#include <ncurses.h>

void MemoryGame::displayTerminalNcurses()
{
   initscr();
   cbreak();
   noecho();
   keypad(stdscr, TRUE);
   curs_set(0);

   const int rows = getRows();
   const int cols = getCols();

   if (has_colors())
   {
      start_color();
      init_pair(1, COLOR_WHITE, COLOR_BLUE);  // hidden
      init_pair(2, COLOR_BLACK, COLOR_WHITE); // face-up
      init_pair(3, COLOR_GREEN, COLOR_BLACK); // matched
   }

   int curR = 0, curC = 0;

   auto draw = [&]()
   {
      clear();
      for (int r = 0; r < rows; ++r)
      {
         for (int c = 0; c < cols; ++c)
         {
            int idx = r * cols + c;
            Card &card = cards.getAt(idx);
            bool matched = card.isMatched;
            bool faceUp = card.isFaceUp;
            char v = card.value;

            if (r == curR && c == curC)
               attron(A_BOLD | A_REVERSE);

            if (matched)
            {
               if (has_colors())
                  attron(COLOR_PAIR(3));
               mvprintw(r * 2, c * 4, "[ ]");
               if (has_colors())
                  attroff(COLOR_PAIR(3));
            }
            else if (faceUp)
            {
               if (has_colors())
                  attron(COLOR_PAIR(2));
               mvprintw(r * 2, c * 4, "[%c]", v);
               if (has_colors())
                  attroff(COLOR_PAIR(2));
            }
            else
            {
               if (has_colors())
                  attron(COLOR_PAIR(1));
               mvprintw(r * 2, c * 4, "[*]");
               if (has_colors())
                  attroff(COLOR_PAIR(1));
            }

            if (r == curR && c == curC)
               attroff(A_BOLD | A_REVERSE);
         }
      }
      mvprintw(rows * 2 + 1, 0, "Arrows move • Enter/Space flip • q quit");
      refresh();
   };

   draw();
   int ch;
   while (!allMatched() && (ch = getch()) != 'q' && ch != 'Q')
   {
      if (ch == KEY_UP)
         curR = (curR + rows - 1) % rows;
      if (ch == KEY_DOWN)
         curR = (curR + 1) % rows;
      if (ch == KEY_LEFT)
         curC = (curC + cols - 1) % cols;
      if (ch == KEY_RIGHT)
         curC = (curC + 1) % cols;

      if (ch == '\n' || ch == ' ')
      {
         bool second = flipCard(curR, curC);
         draw(); // show the second card immediately
         if (second)
         {
            napms(700);   // brief reveal on mismatches
            checkMatch(); // resolves pair and flips back if needed
         }
      }
      draw();
   }

   clear();
   mvprintw(rows, (cols * 4) / 2 - 4, "You Win!");
   refresh();
   getch();
   endwin();
}