#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include "unsorted.h"


using namespace std;


int main()
{
   srand((unsigned)time(nullptr)); // seed random number generator

   UnsortedType list; // initialize list
   
   // printing head and tail while list is empty
   list.PrintHeadTail();
   cout << endl;

   // initializing random length in list to print
   int randomLength = rand() % 49;

   // adding 50 random values
   for (int i = 0; i < 50; i++)
   {
      ItemType *item = new ItemType;
      item->Initialize((rand() % 100) + 1);
      list.PutItem(*item);
      delete item;
      if(i == randomLength){
         list.PrintHeadTail();
         cout << endl;
      }
   }
   // printing at 50 integers
   list.PrintHeadTail();
   cout << endl;

   // print whole list of values
   cout << "List: ";
   list.PrintList(cout);
   return 0;
}