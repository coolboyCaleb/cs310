#ifndef MINHEAP_H
#define MINHEAP_H

#include <vector>
#include "Task.h"

class MinHeap {
private:
    std::vector<Task> heap;   // array representation

    // index helpers
    int parent(int i) const { return (i - 1) / 2; }
    int left(int i)   const { return 2 * i + 1; }
    int right(int i)  const { return 2 * i + 2; }

    // internal re‑balancing
    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    MinHeap() = default;

    // functions
    bool isEmpty() const;
    void insert(const Task& t);   // when user adds a task
    Task extractMin();            // extract the highest priority task
    const Task& peekMin() const;  // look at the highest priority task

    // for "change priority" menu option
    void changePriority(int index, int newPriority);

    // for debugging + screenshots
    void printHeap() const;
};

#endif // MINHEAP_H
