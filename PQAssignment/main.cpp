#include "HeapMaster.h"
#include <functional>
#include <string>

using namespace std;

// comparator for task based on priority (higher priority wins)
struct TaskPriorityLess {
    bool operator()(const Task& a, const Task& b) const {
        return a.priority < b.priority;
    }
};

// comparator for task based on earliest deadline (smaller deadline wins)
struct TaskDeadlineGreater {
    bool operator()(const Task& a, const Task& b) const {
        return a.deadline > b.deadline;
    }
};

int main() {
    cout << "HeapMaster Lab - Challenge 1 & 2 Test" << endl;

    // challenge 1 & 2: push, then pop 10 times and keep heap valid (max-heap)
    HeapMaster<int, 100, less<int>> h;

    // insert 1..20 in a fixed "shuffled" order
    int vals[20] = {
        5, 1, 9, 2, 20, 7, 3, 18, 4, 10,
        6, 15, 8, 12, 13, 11, 14, 16, 19, 17
    };

    for (int i = 0; i < 20; ++i) {
        h.push(vals[i]);
    }

    // expect: size after inserting 1..20 should be 20
    cout << "Size after inserting 1..20: " << h.size() << endl;

    // print heap as array after inserts
    // expect: array represents a valid max-heap (every parent >= its children)
    cout << "Heap as array after inserts:" << endl;
    h.printArray();

    // show the pop order from a copy of the heap before any removals
    // expect: numbers printed in non-increasing order (max to min)
    HeapMaster<int, 100, less<int>> copyBefore = h;
    cout << "pop sequence before any pops: ";
    while (!copyBefore.empty()) {
        int x = copyBefore.top();
        cout << x << " ";
        copyBefore.pop();
    }
    cout << endl;

    // perform 10 pops on the original heap
    for (int i = 0; i < 10 && !h.empty(); ++i) {
        h.pop();
    }

    // expect: size should now be 10
    cout << "Size after 10 pops: " << h.size() << endl;

    // print heap as array after 10 pops
    // expect: still a valid max-heap over the remaining 10 elements
    cout << "Heap as array after 10 pops:" << endl;
    h.printArray();

    // show the pop order from a copy of the heap after the 10 pops
    // expect: numbers printed in non-increasing order (max to min of remaining elements)
    HeapMaster<int, 100, less<int>> copyAfter = h;
    cout << "Pop sequence after 10 pops: ";
    while (!copyAfter.empty()) {
        int x = copyAfter.top();
        cout << x << " ";
        copyAfter.pop();
    }
    cout << endl;
    
    // challenge 3: min vs max kingdom (same code as min-heap with greater)
    HeapMaster<int, 100, greater<int> > h3;

    // reuse same values so behavior matches max-heap test
    for (int i = 0; i < 20; ++i) {
        h3.push(vals[i]);
    }

    // expect: popping everything should give a non-decreasing sequence (min to max)
    cout << "challenge 3 - min-heap pop sequence: ";
    while (!h3.empty()) {
        int x = h3.top();
        cout << x << " ";
        h3.pop();
    }
    cout << endl;

    // challenge 4: heapsort conquest (large arrays ascending and descending)
    const int n4 = 100000; // for quick visual testing you can change to a smaller number

    int* arrAsc = new int[n4];
    int* arrDesc = new int[n4];

    // fill arrAsc with descending values so heapsort with less should sort ascending
    for (int i = 0; i < n4; ++i) {
        arrAsc[i] = n4 - 1 - i; // n-1, n-2, ..., 0
    }

    // fill arrDesc with ascending values so heapsort with greater should sort descending
    for (int i = 0; i < n4; ++i) {
        arrDesc[i] = i; // 0, 1, 2, ...
    }

    heapSort<int>(arrAsc, n4, less<int>());
    heapSort<int>(arrDesc, n4, greater<int>());

    // expect: arrAsc[0] should be 0, arrAsc[n4-1] should be n4-1
    cout << "challenge 4 - ascending heapsort first element: " << arrAsc[0] << endl;
    cout << "challenge 4 - ascending heapsort last element: " << arrAsc[n4 - 1] << endl;

    // expect: arrDesc[0] should be n4-1, arrDesc[n4-1] should be 0
    cout << "challenge 4 - descending heapsort first element: " << arrDesc[0] << endl;
    cout << "challenge 4 - descending heapsort last element: " << arrDesc[n4 - 1] << endl;

    delete[] arrAsc;
    delete[] arrDesc;
    

    // challenge 5: tree vision (pretty print heap)
    HeapMaster<int, 100, less<int> > h5;

    for (int i = 0; i < 20; ++i) {
        h5.push(vals[i]);
    }

    // expect: printarray shows underlying array, printheap shows tree-style levels
    cout << "challenge 5 - heap as array:" << endl;
    h5.printArray();

    cout << "challenge 5 - heap as tree:" << endl;
    h5.printHeap();


    // challenge 6: task scheduler - fixed priority
    HeapMaster<Task, 200, TaskPriorityLess> h6;

    // create 100 tasks with increasing priority
    for (int i = 0; i < 100; ++i) {
        Task t;
        t.id = i;
        t.priority = i;       // higher i = higher priority
        t.arrivalTime = i;
        t.burstTime = 10;
        t.deadline = 100 + i;
        h6.push(t);
    }

    // expect: top task should have highest priority (99)
    Task topPriorityTask = h6.top();
    cout << "challenge 6 - top task priority (expect 99): " << topPriorityTask.priority << endl;

    // pop all tasks and print priorities
    // expect: priorities printed in non-increasing order from 99 down to 0
    cout << "challenge 6 - pop priorities: ";
    while (!h6.empty()) {
        Task t = h6.top();
        cout << t.priority << " ";
        h6.pop();
    }
    cout << endl;

    // challenge 7: earliest deadline first (edf)
    HeapMaster<Task, 100, TaskDeadlineGreater> h7;

    Task t1;
    t1.id = 1; t1.priority = 5; t1.arrivalTime = 0; t1.burstTime = 10; t1.deadline = 40;

    Task t2;
    t2.id = 2; t2.priority = 10; t2.arrivalTime = 1; t2.burstTime = 5; t2.deadline = 10;

    Task t3;
    t3.id = 3; t3.priority = 1; t3.arrivalTime = 2; t3.burstTime = 7; t3.deadline = 30;

    Task t4;
    t4.id = 4; t4.priority = 7; t4.arrivalTime = 3; t4.burstTime = 6; t4.deadline = 20;

    h7.push(t1);
    h7.push(t2);
    h7.push(t3);
    h7.push(t4);

    // expect: popping tasks should give deadlines in non-decreasing order: 10, 20, 30, 40
    cout << "challenge 7 - pop deadlines: ";
    while (!h7.empty()) {
        Task t = h7.top();
        cout << t.deadline << " ";
        h7.pop();
    }
    cout << endl;

    // challenge 8: dynamic priority change (increasekey / decreasekey)
    // use min-heap on ints where smaller value = shorter remaining time
    HeapMaster<int, 100, greater<int> > h8;

    h8.push(8);   // task a: remaining time 8
    h8.push(4);   // task b: remaining time 4
    h8.push(12);  // task c: remaining time 12
    h8.push(6);   // task d: remaining time 6

    // expect: current top should be smallest value before changes
    cout << "challenge 8 - initial top (expect 4): " << h8.top() << endl;

    // simulate remaining time dropping on some job (index 1 here)
    h8.decreaseKey(1, 1);

    // expect: top after decreasekey should be 1
    cout << "challenge 8 - top after decreasekey to 1 (expect 1): " << h8.top() << endl;

    // now simulate current job becoming very long
    h8.increaseKey(0, 50);

    // expect: top after increasekey should not be 50 (some shorter job should be on top)
    cout << "challenge 8 - top after increasekey to 50 (expect not 50): " << h8.top() << endl;


    // challenge 9: build-heap optimization
    const int n9 = 100000; // for full challenge; can reduce for visual testing
    int* arr9 = new int[n9];

    // fill with increasing values so initial array is not a max-heap
    for (int i = 0; i < n9; ++i) {
        arr9[i] = i;
    }

    buildHeap<int>(arr9, n9, less<int>());

    // expect: after buildheap with less, arr9[0] should be the maximum value
    cout << "challenge 9 - value at arr9[0] after buildheap (expect " << (n9 - 1) << "): "
         << arr9[0] << endl;

    delete[] arr9;
    

    return 0;
}