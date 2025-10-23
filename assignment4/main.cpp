#include <iostream>
#include <string>
#include "array/Stack.h"
#include "linked/Stack.h"
#include "PostfixEval.cpp"
using namespace std;

int main()
{
   // assignment 1
   Stack s1;
   cout << "Stack 1, Assignment 1 (Array)" << endl;
   s1.push(51);               // LIFO: 51 is pushed to end
   s1.push(93);               //  LIFO: 82 is pushed to end
   cout << s1.pop() << endl;  // LIFO: Last pushed (93) is first popped
   s1.push(12);               // LIFO: 12 is pushed to end
   s1.push(15);               // LIFO: 15 is pushed to end
   cout << s1.pop() << endl;  // LIFO: Last pushed (15) is first popped
   s1.push(76);               // LIFO: 76 is pushed to end
   cout << s1.peek() << endl; // returns top element
   cout << s1.isEmpty() << endl;

   // assignment 2
   cout << "Stack 2, Assignment 2 (Array)" << endl;
   Stack s2;

   // pushing 10 elements
   for (int i = 1; i <= 10; i++)
   {
      s2.push(i);
   }

   // popping and printing 5 elements
   cout << s2.pop() << " ";
   cout << s2.pop() << " ";
   cout << s2.pop() << " ";
   cout << s2.pop() << " ";
   cout << s2.pop() << " ";
   cout << endl;
   // edge cases
   // popping on empty list
   try
   {
      for (int i = 0; i < 6; i++)
      {
         cout << s2.pop() << endl;
      }
   }
   catch (const exception &e)
   {
      cerr << "Error: " << e.what() << endl;
   }
   // pushing on full list
   try
   {
      for (int i = 1; i <= 100; i++)
      {
         s2.push(i);
      }
      s2.push(101);
   }
   catch (const exception &e)
   {
      cerr << "Error: " << e.what() << endl;
   }
   // memory deallocation
   try
   {
      s2.makeEmpty();
      cout << s2.peek() << endl;
      cout << s2.pop() << endl;
   }
   catch (const exception &e)
   {
      cerr << "Error: " << e.what() << endl;
   }

   // assignment 3
   cout << "Stack 3, Assignment 3 (Linked)" << endl;
   Stack s3;
   for (int i = 1; i <= 100; i++)
   {
      s3.push(i);
   }
   for (int i = 0; i < 100; i++)
   {
      cout << s3.pop() << " ";
   }
   cout << endl;
   // edge cases
   // push/pop on empty list;
   cout << s3.pop() << endl;
   s3.push(16);
   cout << s3.peek() << endl;
   // memory deallocation
   s3.makeEmpty();
   cout << s3.peek() << endl;
   // assignment 4
   cout << "Assignment 4: Postfix" << endl;
   Stack postFix;
   try
   {
      cout << evaluatePostfix("23+", postFix);
      cout << endl;
      cout << evaluatePostfix("231*+4-", postFix);
      cout << endl;
      cout << evaluatePostfix("2++", postFix);
   }
   catch (...)
   {
      cerr << "Error";
   }
   cout << endl;

   return 0;
}