#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H
#include "LinkedList.h" // Extends LinkedList
class SortedLinkedList : public LinkedList
{
public:
   // Inserts while maintaining order
   void insertSorted(int val);
   
   // Recursive problem functions
   bool recursiveBinarySearch(Node* head, int val, int size);
   Node* quickSort(Node* head);
   Node* mergeSort(Node* head);
   Node* heapStyleSimulation(Node* head);
   Node* insertionSort(Node* head);
};
#endif