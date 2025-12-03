#include "LinkedList.h"
#include "DoublyLinkedList.h"
#include "CircularLinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "SortedLinkedList.h"
#include <iostream>

using namespace std;

void testLinkedList()
{
    cout << "\n========== LINKED LIST TESTS ==========\n"
         << endl;

    LinkedList ll;

    // Test insert and print
    cout << "Testing insert and print:" << endl;
    ll.insert(1);
    ll.insert(2);
    ll.insert(3);
    ll.insert(4);
    ll.insert(5);
    cout << "List: ";
    ll.print();

    // Test recursiveReverse
    cout << "\nTesting recursiveReverse:" << endl;
    ll.head = ll.recursiveReverse(ll.head);
    cout << "Reversed list: ";
    ll.print();

    // Test findMiddle
    cout << "\nTesting findMiddle:" << endl;
    Node *middle = ll.findMiddle(ll.head);
    if (middle)
    {
        cout << "Middle element: " << middle->data << endl;
    }

    // Test detectCycle
    cout << "\nTesting detectCycle:" << endl;
    cout << "Has cycle: " << (ll.detectCycle(ll.head) ? "Yes" : "No") << endl;

    // Test mergeSortedLists
    cout << "\nTesting mergeSortedLists:" << endl;
    LinkedList l1, l2;
    l1.insert(1);
    l1.insert(3);
    l1.insert(5);
    l2.insert(2);
    l2.insert(4);
    l2.insert(6);
    cout << "List 1: ";
    l1.print();
    cout << "List 2: ";
    l2.print();
    Node *merged = l1.mergeSortedLists(l1.head, l2.head);
    cout << "Merged: ";
    LinkedList mergedList;
    mergedList.head = merged;
    mergedList.print();

    // Test removeDuplicates
    cout << "\nTesting removeDuplicates:" << endl;
    LinkedList dupList;
    dupList.insert(1);
    dupList.insert(2);
    dupList.insert(2);
    dupList.insert(3);
    dupList.insert(3);
    dupList.insert(4);
    cout << "List with duplicates: ";
    dupList.print();
    dupList.head = dupList.removeDuplicates(dupList.head);
    cout << "After removing duplicates: ";
    dupList.print();

    // Test partitionAroundValue
    cout << "\nTesting partitionAroundValue:" << endl;
    LinkedList partList;
    partList.insert(3);
    partList.insert(5);
    partList.insert(8);
    partList.insert(5);
    partList.insert(10);
    partList.insert(2);
    partList.insert(1);
    cout << "Original list: ";
    partList.print();
    partList.head = partList.partitionAroundValue(partList.head, 5);
    cout << "After partitioning around 5: ";
    partList.print();
}

void testDoublyLinkedList()
{
    cout << "\n========== DOUBLY LINKED LIST TESTS ==========\n"
         << endl;

    DoublyLinkedList dll;

    // Test insert and print
    cout << "Testing insert and print:" << endl;
    dll.insert(1);
    dll.insert(2);
    dll.insert(3);
    dll.insert(4);
    dll.insert(5);
    cout << "List: ";
    dll.print();

    // Test recursiveReverse
    cout << "\nTesting recursiveReverse:" << endl;
    dll.head = dll.recursiveReverse(dll.head);
    cout << "Reversed list: ";
    dll.print();

    // Test sortedInsert
    cout << "\nTesting sortedInsert:" << endl;
    DoublyLinkedList sortedDll;
    sortedDll.insert(1);
    sortedDll.insert(3);
    sortedDll.insert(5);
    sortedDll.insert(7);
    cout << "Sorted list: ";
    sortedDll.print();
    sortedDll.head = sortedDll.sortedInsert(sortedDll.head, 4);
    cout << "After inserting 4: ";
    sortedDll.print();

    // Test deleteByValue
    cout << "\nTesting deleteByValue:" << endl;
    DoublyLinkedList delList;
    delList.insert(1);
    delList.insert(2);
    delList.insert(3);
    delList.insert(4);
    delList.insert(5);
    cout << "Original list: ";
    delList.print();
    delList.head = delList.deleteByValue(delList.head, 3);
    cout << "After deleting 3: ";
    delList.print();

    // Test pairSumCheck
    cout << "\nTesting pairSumCheck:" << endl;
    DoublyLinkedList pairList;
    pairList.insert(1);
    pairList.insert(2);
    pairList.insert(3);
    pairList.insert(4);
    pairList.insert(5);
    cout << "List: ";
    pairList.print();
    cout << "Has pair with sum 7: " << (pairList.pairSumCheck(pairList.head, 7) ? "Yes" : "No") << endl;
    cout << "Has pair with sum 20: " << (pairList.pairSumCheck(pairList.head, 20) ? "Yes" : "No") << endl;

    // Test rotateByK
    cout << "\nTesting rotateByK:" << endl;
    DoublyLinkedList rotList;
    rotList.insert(1);
    rotList.insert(2);
    rotList.insert(3);
    rotList.insert(4);
    rotList.insert(5);
    cout << "Original list: ";
    rotList.print();
    rotList.head = rotList.rotateByK(rotList.head, 2);
    cout << "After rotating by 2: ";
    rotList.print();
}

void testCircularLinkedList()
{
    cout << "\n========== CIRCULAR LINKED LIST TESTS ==========\n"
         << endl;

    CircularLinkedList cll;

    // Test insert and print
    cout << "Testing insert and print:" << endl;
    cll.insert(1);
    cll.insert(2);
    cll.insert(3);
    cll.insert(4);
    cll.insert(5);
    cout << "List: ";
    cll.print();

    // Test cycleLength
    cout << "\nTesting cycleLength:" << endl;
    cout << "Cycle length: " << cll.cycleLength(cll.head) << endl;

    // Test sortedInsert
    cout << "\nTesting sortedInsert:" << endl;
    CircularLinkedList sortedCll;
    sortedCll.insert(1);
    sortedCll.insert(3);
    sortedCll.insert(5);
    sortedCll.insert(7);
    cout << "Sorted circular list: ";
    sortedCll.print();
    sortedCll.head = sortedCll.sortedInsert(sortedCll.head, 4);
    cout << "After inserting 4: ";
    sortedCll.print();

    // Test josephus
    cout << "\nTesting josephus problem:" << endl;
    cout << "Josephus(7, 3): " << cll.josephus(7, 3) << endl;
    cout << "Josephus(10, 2): " << cll.josephus(10, 2) << endl;
}

void testStack()
{
    cout << "\n========== STACK TESTS ==========\n"
         << endl;

    Stack stack;

    // Test push, pop, isEmpty
    cout << "Testing push, pop, isEmpty:" << endl;
    cout << "Is empty: " << (stack.isEmpty() ? "Yes" : "No") << endl;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    cout << "Pushed: 10, 20, 30, 40" << endl;
    cout << "Popped: " << stack.pop() << endl;
    cout << "Popped: " << stack.pop() << endl;
    cout << "Is empty: " << (stack.isEmpty() ? "Yes" : "No") << endl;

    // Test recursiveSort
    cout << "\nTesting recursiveSort:" << endl;
    Stack sortStack;
    sortStack.push(5);
    sortStack.push(1);
    sortStack.push(4);
    sortStack.push(2);
    sortStack.push(3);
    cout << "Before sort (top to bottom): 3, 2, 4, 1, 5" << endl;
    sortStack.recursiveSort();
    cout << "After sort - popping all elements:" << endl;
    while (!sortStack.isEmpty())
    {
        cout << sortStack.pop() << " ";
    }
    cout << endl;

    // Test recursiveReverse
    cout << "\nTesting recursiveReverse:" << endl;
    Stack revStack;
    revStack.push(1);
    revStack.push(2);
    revStack.push(3);
    revStack.push(4);
    cout << "Before reverse (top to bottom): 4, 3, 2, 1" << endl;
    revStack.recursiveReverse();
    cout << "After reverse - popping all elements:" << endl;
    while (!revStack.isEmpty())
    {
        cout << revStack.pop() << " ";
    }
    cout << endl;

    // Test checkParentheses
    cout << "\nTesting checkParentheses:" << endl;
    Stack parenStack;
    cout << "Expression: ((()))" << endl;
    cout << "Balanced: " << (parenStack.checkParentheses("((()))") ? "Yes" : "No") << endl;
    cout << "Expression: ((())" << endl;
    cout << "Balanced: " << (parenStack.checkParentheses("((())") ? "Yes" : "No") << endl;

    // Test postfixEval
    cout << "\nTesting postfixEval:" << endl;
    Stack postfixStack;
    cout << "Expression: 53+82-*" << endl;
    cout << "Result: " << postfixStack.postfixEval("53+82-*") << endl;
}

void testQueue()
{
    cout << "\n========== QUEUE TESTS ==========\n"
         << endl;

    Queue queue;

    // Test enqueue, dequeue, isEmpty
    cout << "Testing enqueue, dequeue, isEmpty:" << endl;
    cout << "Is empty: " << (queue.isEmpty() ? "Yes" : "No") << endl;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    cout << "Enqueued: 10, 20, 30, 40" << endl;
    cout << "Dequeued: " << queue.dequeue() << endl;
    cout << "Dequeued: " << queue.dequeue() << endl;
    cout << "Is empty: " << (queue.isEmpty() ? "Yes" : "No") << endl;

    // Test recursiveReverse
    cout << "\nTesting recursiveReverse:" << endl;
    Queue revQueue;
    revQueue.enqueue(1);
    revQueue.enqueue(2);
    revQueue.enqueue(3);
    revQueue.enqueue(4);
    cout << "Before reverse (front to rear): 1, 2, 3, 4" << endl;
    revQueue.recursiveReverse();
    cout << "After reverse - dequeuing all:" << endl;
    while (!revQueue.isEmpty())
    {
        cout << revQueue.dequeue() << " ";
    }
    cout << endl;

    // Test recursiveEnqueue and recursiveDequeue
    cout << "\nTesting recursiveEnqueue and recursiveDequeue:" << endl;
    Queue recQueue;
    recQueue.recursiveEnqueue(5);
    recQueue.recursiveEnqueue(10);
    recQueue.recursiveEnqueue(15);
    cout << "Recursively enqueued: 5, 10, 15" << endl;
    cout << "Recursively dequeued: " << recQueue.recursiveDequeue() << endl;

    // Test interleaveHalves
    cout << "\nTesting interleaveHalves:" << endl;
    Queue interQueue;
    interQueue.enqueue(1);
    interQueue.enqueue(2);
    interQueue.enqueue(3);
    interQueue.enqueue(4);
    interQueue.enqueue(5);
    interQueue.enqueue(6);
    cout << "Before interleave: 1, 2, 3, 4, 5, 6" << endl;
    interQueue.interleaveHalves();
    cout << "After interleave - dequeuing all:" << endl;
    while (!interQueue.isEmpty())
    {
        cout << interQueue.dequeue() << " ";
    }
    cout << endl;

    // Test generateBinaryNumbers
    cout << "\nTesting generateBinaryNumbers:" << endl;
    Queue binQueue;
    cout << "Generating binary numbers from 1 to 10:" << endl;
    binQueue.generateBinaryNumbers(10);
}

void testSortedLinkedList()
{
    cout << "\n========== SORTED LINKED LIST TESTS ==========\n"
         << endl;

    SortedLinkedList sll;

    // Test insertSorted
    cout << "Testing insertSorted:" << endl;
    sll.insertSorted(5);
    sll.insertSorted(2);
    sll.insertSorted(8);
    sll.insertSorted(1);
    sll.insertSorted(4);
    cout << "Sorted list: ";
    sll.print();

    // Test recursiveBinarySearch
    cout << "\nTesting recursiveBinarySearch:" << endl;
    cout << "Searching for 4: " << (sll.recursiveBinarySearch(sll.head, 4, 5) ? "Found" : "Not found") << endl;
    cout << "Searching for 7: " << (sll.recursiveBinarySearch(sll.head, 7, 5) ? "Found" : "Not found") << endl;

    // Test mergeSort
    cout << "\nTesting mergeSort:" << endl;
    LinkedList unsorted;
    unsorted.insert(5);
    unsorted.insert(2);
    unsorted.insert(8);
    unsorted.insert(1);
    unsorted.insert(9);
    unsorted.insert(3);
    cout << "Unsorted list: ";
    unsorted.print();
    SortedLinkedList sortedMerge;
    sortedMerge.head = sortedMerge.mergeSort(unsorted.head);
    cout << "After merge sort: ";
    sortedMerge.print();

    // Test quickSort
    cout << "\nTesting quickSort:" << endl;
    LinkedList unsorted2;
    unsorted2.insert(7);
    unsorted2.insert(3);
    unsorted2.insert(9);
    unsorted2.insert(2);
    unsorted2.insert(5);
    cout << "Unsorted list: ";
    unsorted2.print();
    SortedLinkedList sortedQuick;
    sortedQuick.head = sortedQuick.quickSort(unsorted2.head);
    cout << "After quick sort: ";
    sortedQuick.print();

    // Test insertionSort
    cout << "\nTesting insertionSort:" << endl;
    LinkedList unsorted3;
    unsorted3.insert(4);
    unsorted3.insert(1);
    unsorted3.insert(7);
    unsorted3.insert(3);
    unsorted3.insert(2);
    cout << "Unsorted list: ";
    unsorted3.print();
    SortedLinkedList sortedInsertion;
    sortedInsertion.head = sortedInsertion.insertionSort(unsorted3.head);
    cout << "After insertion sort: ";
    sortedInsertion.print();
}

int main()
{
    cout << "\n===============================================" << endl;
    cout << "    DATA STRUCTURES TEST SUITE" << endl;
    cout << "===============================================" << endl;

    // Run everything once, no menu
    testLinkedList();
    testDoublyLinkedList();
    testCircularLinkedList();
    testStack();
    testQueue();
    testSortedLinkedList();

    cout << "\nAll tests complete." << endl;
    return 0;
}