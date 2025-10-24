#include <iostream>
#include <fstream>
#include <string>
#include "StackType.h"

using namespace std;

bool RemoveTopTwo(StackType &s, ItemType &second) {
    if (s.IsEmpty()) return false;
    ItemType firstTop = s.Top();
    s.Pop();
    if (s.IsEmpty()) {
        s.Push(firstTop);
        return false;
    }
    second = s.Top();
    s.Pop();
    return true;
}

bool GetBottomEmpty(StackType &s, ItemType &bottom) {
    if (s.IsEmpty()) return false;
    while (!s.IsEmpty()) { bottom = s.Top(); s.Pop(); }
    return true;
}

bool GetBottomPreserve(StackType &s, ItemType &bottom) {
    if (s.IsEmpty()) return false;
    StackType newStack;
    while (!s.IsEmpty()) { bottom = s.Top(); s.Pop(); newStack.Push(bottom); }
    while (!newStack.IsEmpty()) { ItemType x = newStack.Top(); newStack.Pop(); s.Push(x); }
    return true;
}

void CopyStack(StackType &s1, StackType &s2) {
    StackType newStack;
    while (!s1.IsEmpty()) { ItemType x = s1.Top(); s1.Pop(); newStack.Push(x); }
    while (!newStack.IsEmpty())   { ItemType x = newStack.Top();  newStack.Pop();  s1.Push(x); s2.Push(x); }
}

int main() {
  ifstream inFile;
  ofstream outFile;
  string inFileName;
  string outFileName;
  string outputLabel;
  string command;

  ItemType item;
  StackType stack;
  int numCommands;

  cout << "Enter name of input command file; press return." << endl;
  cin  >> inFileName;
  inFile.open(inFileName.c_str());

  cout << "Enter name of output file; press return." << endl;
  cin  >> outFileName;
  outFile.open(outFileName.c_str());

  cout << "Enter name of test run; press return." << endl;
  cin  >> outputLabel;
  outFile << outputLabel << endl;

  inFile >> command;

  numCommands = 0;
  while (command != "Quit") {
    try {
      if (command == "Push") {
        inFile >> item;
        stack.Push(item);
      }
      else if (command == "Pop")
        stack.Pop();
      else if (command == "Top") {
        item = stack.Top();
        outFile << "Top element is " << item << endl;
      }
      else if (command == "IsEmpty")
        outFile << (stack.IsEmpty() ? "Stack is empty." : "Stack is not empty.") << endl;
      else if (command == "IsFull")
        outFile << (stack.IsFull() ? "Stack is full." : "Stack is not full.") << endl;
      else if (command == "Second") {
        ItemType second;
        if (RemoveTopTwo(stack, second))
          outFile << "Second element (original 2nd-from-top) is " << second << endl;
        else
          outFile << "Second operation failed (need at least two items)." << endl;
      }
      else if (command == "BottomEmpty") {
        ItemType bottom;
        if (GetBottomEmpty(stack, bottom))
          outFile << "Bottom (stack now empty) is " << bottom << endl;
        else
          outFile << "BottomEmpty operation failed (stack was empty)." << endl;
      }
      else if (command == "BottomPreserve") {
        ItemType bottom;
        if (GetBottomPreserve(stack, bottom))
          outFile << "Bottom (stack preserved) is " << bottom << endl;
        else
          outFile << "BottomPreserve operation failed (stack was empty)." << endl;
      }
      else if (command == "Copy") {
        StackType copy;
        CopyStack(stack, copy);
        if (copy.IsEmpty())
          outFile << "Copy created (empty)." << endl;
        else
          outFile << "Copy created; top of copy is " << copy.Top() << endl;
      }
      else
        outFile << command << " not found" << endl;
    }
    catch (FullStack) {
      outFile << "FullStack exception thrown." << endl;
    }
    catch (EmptyStack) {
      outFile << "EmptyStack exception thrown." << endl;
    }
    numCommands++;
    cout << " Command number " << numCommands << " completed." << endl;
    inFile >> command;
  };

  cout << "Testing completed." << endl;
  inFile.close();
  outFile.close();
  return 0;
}