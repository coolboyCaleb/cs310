// Implementation file for Unsorted.h

#include "unsorted.h"
#include <fstream>
#include <iostream>
#include <stdexcept>

using namespace std;

UnsortedType::UnsortedType()
{
  length = 0;
}
bool UnsortedType::IsFull() const
{
  return (length == MAX_ITEMS);
}
int UnsortedType::GetLength() const
{
  return length;
}

ItemType UnsortedType::GetItem(ItemType item, bool &found)
// Pre:  Key member(s) of item is initialized.
// Post: If found, item's key matches an element's key in the
//       list and a copy of that element has been returned;
//       otherwise, item is returned.
{
  bool moreToSearch;
  int location = 0;
  found = false;

  moreToSearch = (location < length);

  while (moreToSearch && !found)
  {
    switch (item.ComparedTo(info[location]))
    {
    case LESS:
    case GREATER:
      location++;
      moreToSearch = (location < length);
      break;
    case EQUAL:
      found = true;
      item = info[location];
      break;
    }
  }
  return item;
}
void UnsortedType::MakeEmpty()
// Post: list is empty.
{
  length = 0;
}
void UnsortedType::PutItem(ItemType item)
// Post: item is in the list.
{
  info[length] = item;
  length++;
}
void UnsortedType::DeleteItem(ItemType item)
// Pre:  item's key has been initialized.
//       An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{
  int location = 0;

  while (item.ComparedTo(info[location]) != EQUAL)
    location++;

  info[location] = info[length - 1];
  length--;
}
void UnsortedType::ResetList()
// Post: currentPos has been initialized.
{
  currentPos = -1;
}

ItemType UnsortedType::GetNextItem()
// Pre:  ResetList was called to initialized iteration.
//       No transformer has been executed since last call.
//       currentPos is defined.
// Post: item is current item.
//       Current position has been updated.
{
  currentPos++;
  return info[currentPos];
}
ItemType UnsortedType::GetHead()
{
  // time complexity = O(1)
  if (length == 0)
  {
    throw out_of_range("List Empty.");
  }
    return info[0];
}
ItemType UnsortedType::GetTail()
{
  // time complexity = O(1)
  if (length == 0)
  {
    throw out_of_range("List Empty.");
  }
    return info[length - 1];
}
void UnsortedType::PrintHeadTail()
{
  try
  {
    // printing head
    ItemType head = GetHead();
    cout << "Current head: ";
    head.Print(cout);
    cout << endl;
  }
  catch (const out_of_range &e)
  {
    cerr << "Error retrieving head: " << e.what() << endl;
  }
  try
  {
    // printing tail
    ItemType tail = GetTail();
    cout << "Current tail: ";
    tail.Print(cout);
    cout << endl;
  }
  catch (const out_of_range &e)
  {
    cerr << "Error retrieving tail: " << e.what() << endl;
  }
}
void UnsortedType::PrintList(std::ostream &dataFile)
// Pre:  list has been initialized.
//       dataFile is open for writing.
// Post: Each component in list has been written to dataFile.
//       dataFile is still open.
{
  int length;
  ItemType item;

  ResetList();
  length = GetLength();
  for (int counter = 1; counter <= length; counter++)
  {
    item = GetNextItem();
    item.Print(dataFile);
    dataFile << " ";
  }
  dataFile << std::endl;
}
