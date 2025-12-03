#include <iostream>
#include <random>
#include <string>
#include "QueType.h"

using namespace std;

int main()
{
   const int MAX_QUE_LENGTH = 10;
   const int NUM_ITERATIONS = 100;

   QueType bankQue(MAX_QUE_LENGTH);

   int servedCustomers = 0;
   int customersLeft = 0; // customers that couldn't be served due to full queue
   int idleTeller = 0;    // ticks where the queue is empty (teller idle)

   std::random_device rd;
   std::mt19937 generator(rd());
   std::uniform_int_distribution<int> arrivalsDist(0, 9); // 0–9 arrivals per iteration

   for (int i = 1; i <= NUM_ITERATIONS; ++i)
   { // time/space complexity: O(N^2)
      int arrivals = arrivalsDist(generator);
      for (int j = 0; j < arrivals; ++j)
      {
         string nextCustomer = "Customer " + to_string(i);
         if (!bankQue.IsFull())
         {
            bankQue.Enqueue(nextCustomer);
         }
         else
         {
            customersLeft++; // queue full, customer leaves
         }
      }

      // idle teller tracking (no one to serve this iteration)
      if (bankQue.IsEmpty())
      {
         idleTeller++;
      }

      // service this iteration
      int toBeServed = arrivals / 2;
      for (int s = 0; s < toBeServed; ++s)
      {
         if (!bankQue.IsEmpty())
         {
            string servedName;
            bankQue.Dequeue(servedName);
            servedCustomers++;
         }
         else
         {
            break;
         }
      }
   }

   // count how many remain in the queue at the end
   int remaining = 0;
   while (!bankQue.IsEmpty())
   {
      string temp;
      bankQue.Dequeue(temp);
      remaining++;
   }
   // output
   cout << "Simulation complete for " << NUM_ITERATIONS << " iterations." << endl;
   cout << "Served customers: " << servedCustomers << endl;
   cout << "Customers turned away (queue full): " << customersLeft << endl;
   cout << "Idle ticks (teller idle): " << idleTeller << endl;
   cout << "Customers still waiting at end: " << remaining << endl;

   return 0;
}
