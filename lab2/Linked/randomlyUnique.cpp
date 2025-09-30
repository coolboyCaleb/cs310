#include <iostream>
#include "unsorted.h" // UnsortedType class

using namespace std;

int main() {
   // initializing variables
    UnsortedType list;
    ItemType item;
    bool found;

    int values[] = {5, 12, 23, 15, 79, 68, 91};
    int size = 7;

    for (int i = 0; i < size; i++) {
        item.Initialize(values[i]);
        list.GetItem(item, found);
        if (!found) {
            list.PutItem(item);
        }
    }

    list.ResetList();
    for (int i = 0; i < list.GetLength(); i++) {
        item = list.GetNextItem();   // GetNextItem returns ItemType and takes no args
        item.Print(cout);  // Print to standard output per ItemType interface
        cout << " ";
    }
    cout << endl;
}
