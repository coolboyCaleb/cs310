#include "MemoryGame.h"
#include <SFML/Graphics.hpp>
#include <string>

void MemoryGame::displaySFML()
{
   const int cellSize = 100; // 4x4 grid → window 400x400
   sf::RenderWindow window(sf::VideoMode(cols * cellSize, rows * cellSize),
                           "Memory Game (SFML)");

   sf::Font font;
   bool haveFont = font.loadFromFile("arial.ttf"); // if not found, we’ll draw rectangles only

   while (window.isOpen())
   {
      sf::Event event;
      while (window.pollEvent(event))
      {
         if (event.type == sf::Event::Closed)
            window.close();

         if (event.type == sf::Event::MouseButtonPressed &&
             event.mouseButton.button == sf::Mouse::Left)
         {
            int c = event.mouseButton.x / cellSize; // column
            int r = event.mouseButton.y / cellSize; // row
            if (r >= 0 && r < rows && c >= 0 && c < cols)
            {
               if (flipCard(r, c))
               {
                  // second flip done → resolve immediately (simple path)
                  checkMatch();
               }
            }
         }
      }

      window.clear();

      // Draw the board (sample-style)
      for (int r = 0; r < rows; ++r)
      {
         for (int c = 0; c < cols; ++c)
         {
            int idx = r * cols + c;
            Card &card = cards.getAt(idx); // direct access since this is a member function

            sf::RectangleShape rect(sf::Vector2f(90.f, 90.f));
            rect.setPosition(float(c * cellSize + 5), float(r * cellSize + 5));
            rect.setFillColor(
                card.isMatched ? sf::Color(0, 0, 0, 0)               // transparent if matched
                               : (card.isFaceUp ? sf::Color::White   // face-up
                                                : sf::Color::Blue)); // hidden

            if (!card.isMatched)
               window.draw(rect);

            if (card.isFaceUp && !card.isMatched && haveFont)
            {
               sf::Text text(std::string(1, card.value), font, 50);
               text.setFillColor(sf::Color::Black);
               text.setPosition(float(c * cellSize + 30), float(r * cellSize + 20));
               window.draw(text);
            }
         }
      }

      // Win overlay (sample behavior)
      if (allMatched())
      {
         if (haveFont)
         {
            sf::Text winText("You Win!", font, 50);
            winText.setFillColor(sf::Color::White);
            winText.setPosition(100.f, 180.f);
            window.draw(winText);
         }
         window.display();
         sf::sleep(sf::seconds(2.f));
         window.close();
         continue;
      }

      window.display();
   }
}