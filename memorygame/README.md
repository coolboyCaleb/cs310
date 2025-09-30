Project: Memory Game with Linked List

Overview

This project implements a Memory Matching Game using a singly linked list to store cards.
The game has three user interfaces:
	1.	Console version (text-based output, no external libs)
	2.	SFML version (graphical UI using rectangles and text)
	3.	ncurses version (terminal-based UI with arrow keys and live updates)

Compilation Instructions

Console

g++ main.cpp MemoryGame.cpp LinkedList.cpp -o mem_console

Run with:

./mem_console

SFML

g++ main.cpp ui_sfml.cpp MemoryGame.cpp LinkedList.cpp \
  -o mem_sfml -lsfml-graphics -lsfml-window -lsfml-system

Run with:

./mem_sfml

ncurses

Make sure you have libncurses5-dev installed:

sudo apt-get install libncurses5-dev libncursesw5-dev

Then compile:

g++ main.cpp ui_ncurses.cpp MemoryGame.cpp LinkedList.cpp \
  -o mem_ncurses -lncurses

Run with:

./mem_ncurses


Controls

Console version
	•	Type row and column numbers to flip a card.
	•	Two flips → auto-checks for a match.
	•	Game ends with a “You Win!” message.

SFML version
	•	Click on a card with the mouse to flip.
	•	Two flips → resolves immediately.
	•	On win, “You Win!” message is displayed.

ncurses version
	•	Arrow keys → move cursor
	•	Enter/Space → flip a card
	•	q → quit
	•	On win, “You Win!” message is displayed in the terminal.

Files
	•	MemoryGame.h / MemoryGame.cpp → Game logic (deck setup, flip, checkMatch, win condition).
	•	LinkedList.h / LinkedList.cpp → Linked list implementation for storing Card objects.
	•	Card.h → Simple struct representing a card.
	•	ui_sfml.cpp → SFML graphical UI.
	•	ui_ncurses.cpp → ncurses terminal UI.
	•	main.cpp → Entry point; choose which display to run.

⸻

Reflection

Data structure choice:
We used a singly linked list (unsorted) to represent the deck. While an array/vector might be simpler for random access, the assignment required a linked list. Implementing getAt(index) emphasized how sequential access works versus constant-time array indexing.

Challenges faced:
	•	Getting SFML and ncurses to compile and link correctly (library setup was trickier than logic).
	•	Deciding between helper methods (isFaceUpAt) vs. direct access to Card fields. Ended up using direct access in member functions for simplicity.
	•	Debugging mismatched flips required ensuring indices were converted correctly from (row, col) to a linear index.

Learning outcomes:
	•	Practiced implementing a classic game using a custom data structure rather than STL containers.
	•	Gained experience integrating external libraries (SFML for graphics, ncurses for terminal UI).
	•	Understood the tradeoffs of linked lists (sequential traversal cost) in a practical context.
	•	Learned to separate game logic from user interface by keeping MemoryGame independent of SFML/ncurses specifics.

Future improvements:
	•	Add score tracking and number of moves.
	•	Allow different grid sizes (not just 4x4).
	•	Improve UI (card flipping animations in SFML, colors in ncurses).
