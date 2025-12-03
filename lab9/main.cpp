#include "TreeType.h"
#include <iostream>

using namespace std;

int main()
{
   TreeType t1;
   cout << "Empty tree leaf count: " << t1.LeafCount() << endl;

   TreeType t2;

   char item = 'M';
   t2.PutItem(item);
   cout << "Single-node tree leaf count: " << t2.LeafCount() << endl;

   TreeType t3;
   char vals[] = {'F', 'B', 'G', 'A', 'D', 'I', 'C', 'E', 'H'};
   for (char c : vals){
      t3.PutItem(c);
}
   cout << "Larger tree leaf count: " << t3.LeafCount() << endl;

   return 0;
}