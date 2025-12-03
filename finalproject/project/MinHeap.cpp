#include "MinHeap.h"
#include <iostream>
#include <stdexcept>

using namespace std;

// check if the heap is empty
bool MinHeap::isEmpty() const {
    return heap.size() == 0;
}

// return the size of the heap
/* int MinHeap::size() const {
    return size; // if the heap was using an array
} */

// insert a new task into the heap
void MinHeap::insert(const Task& t) {
    heap.push_back(t);
    heapifyUp(heap.size() - 1);
}

// peek at the highest priority task without removing it
const Task& MinHeap::peekMin() const {
    if (isEmpty()) {
        throw runtime_error("Cannot peek at empty heap");
    }
    return heap[0];
}

// extract and return the highest priority task (root)
Task MinHeap::extractMin() {
    if (isEmpty()) {
        throw runtime_error("Cannot extract from empty heap");
    }
    
    Task task = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    
    if (!isEmpty()) {
        heapifyDown(0);
    }
    return task;
}

// change the priority of a task at the given index
void MinHeap::changePriority(int index, int newPriority) {
    if (index < 0 || index >= heap.size()) {
        throw out_of_range("Index out of bounds");
    }
    
    int oldPriority = heap[index].priority;
    heap[index].priority = newPriority;
    
    // if priority decreased, bubble up; if increased, bubble down
    if (newPriority < oldPriority) {
        heapifyUp(index);
    } else if (newPriority > oldPriority) {
        heapifyDown(index);
    }
}

// bubble up to maintain heap property (used after insertion)
void MinHeap::heapifyUp(int index) {
    while (index > 0) {
        int parentIndex = parent(index);
        
        // if current node is smaller than parent, swap
        if (heap[index].priority < heap[parentIndex].priority) {
            swap(heap[index], heap[parentIndex]);
            index = parentIndex;
        } else {
            break; // heap property is satisfied
        }
    }
}

// bubble down to maintain heap property (used after extraction)
void MinHeap::heapifyDown(int index) {
    int heapSize = heap.size();
    
    while (true) {
        int smallest = index;
        int leftChild = left(index);
        int rightChild = right(index);
        
        // compare with left child
        if (leftChild < heapSize && heap[leftChild].priority < heap[smallest].priority) {
            smallest = leftChild;
        }
        
        // compare with right child
        if (rightChild < heapSize && heap[rightChild].priority < heap[smallest].priority) {
            smallest = rightChild;
        }
        
        // if smallest is still the current node, heap property is satisfied
        if (smallest == index) {
            break;
        }
        
        // swap with the smaller child
        swap(heap[index], heap[smallest]);
        index = smallest;
    }
}

// print the heap in several useful ways
void MinHeap::printHeap() const {
    if (isEmpty()) {
        cout << "Heap is empty" << endl;
        return;
    }
    
    // printing the tree by level-order, grouped by levels
    cout << "Tree (level-order by levels):" << endl;
    int levelStart = 0;
    int levelSize = 1;
    int level = 0;
    while (levelStart < heap.size()) {
        cout << "Level " << level << ": ";
        int levelEnd = levelStart + levelSize;
        if (levelEnd > heap.size()) levelEnd = heap.size();

        for (int i = levelStart; i < levelEnd; i++) {
            cout << "[" << heap[i].priority << "]";
            if (i + 1 < levelEnd) cout << " | ";
        }
        cout << endl;

        levelStart = levelEnd;
        levelSize  = levelSize * 2;  // each level can have twice as many nodes
        ++level;
    }

    cout << endl;

    // printing the underlying array representation: [ , , , ]
    cout << "Array representation [";
    for (int i = 0; i < heap.size(); i++) {
        cout << heap[i].priority;
        if (i + 1 < heap.size()) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    cout << endl;

    // printing the list of tasks in array order
    cout << "Tasks in array order (index: [priority] description):" << endl;
    for (int i = 0; i < heap.size(); i++) {
        cout << i << ": [" << heap[i].priority << "] " << heap[i].description << endl;
    }
}
