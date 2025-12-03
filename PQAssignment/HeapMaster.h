#ifndef HEAPMASTER_H
#define HEAPMASTER_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include <functional>   // std::less, std::greater

// ====================== TASK STRUCT (for challenges 6–10) ======================
struct Task {
    int id;
    int priority;      // higher number = higher priority (for fixed-priority mode)
    int arrivalTime;
    int burstTime;
    int deadline;

    void print() const {
        std::cout << "Task#" << id
                  << " pri=" << priority
                  << " arrive=" << arrivalTime
                  << " burst=" << burstTime
                  << " dead=" << deadline;
    }
};

// ============================= HEAP MASTER CLASS =============================
template<typename T, int MAX_SIZE = 1000005, typename Compare = std::less<T>>
class HeapMaster {
private:
    T data[MAX_SIZE];
    int sz;                    // current size
    Compare comp;              // comparator (less = max-heap, greater = min-heap)

    int parent(int i) const { return (i - 1) / 2; }
    int left(int i)   const { return 2 * i + 1; }
    int right(int i)  const { return 2 * i + 2; }

    void heapifyUp(int i);     // used by push / increaseKey
    void heapifyDown(int i);   // used by pop / decreaseKey / buildHeap / heapSort

public:
    HeapMaster() : sz(0) {}

    bool empty() const { return sz == 0; }
    int  size()  const { return sz; }

    // Challenge 2: top() and pop()
    const T& top() const;
    void pop();

    // Challenge 1: push() + heapifyUp()
    void push(const T& val);

    void clear() { sz = 0; }

    // Challenge 8 – Dynamic Priority Change (decreaseKey / increaseKey)
    // Note: which one you use depends on whether you're running a min-heap or max-heap.
    bool decreaseKey(int index, const T& newVal);
    bool increaseKey(int index, const T& newVal);

    // Challenge 5 – pretty print as a tree
    void printHeap() const;

    // Helper: raw array view of heap (for debugging / verification)
    void printArray() const;
};

// ===================== Standalone Functions (Challenges 4 & 9) =====================

// Challenge 4: HeapSort using heapifyDown (no extra array)
// Sorts arr[0..n-1] in-place using a heap defined by Compare.
template<typename T, typename Compare = std::less<T>>
void heapSort(T arr[], int n, Compare comp = Compare());

// Challenge 9: Build-Heap optimization (bottom-up O(n) build)
template<typename T, typename Compare = std::less<T>>
void buildHeap(T arr[], int n, Compare comp = Compare());

#include "HeapMaster.hpp"   // template implementations

#endif // HEAPMASTER_H