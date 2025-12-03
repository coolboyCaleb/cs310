#ifndef HEAPMASTER_HPP
#define HEAPMASTER_HPP

#include "HeapMaster.h"

// ========================= heapmaster member functions =========================

// heapifyup: move element at index i up until heap property is restored
template<typename T, int MAX_SIZE, typename Compare>
void HeapMaster<T, MAX_SIZE, Compare>::heapifyUp(int i) {
    while (i > 0) {
        int p = parent(i);
        // If parent is "worse" than child according to comparator, swap
        if (comp(data[p], data[i])) {
            std::swap(data[p], data[i]);
            i = p;
        } else {
            break;
        }
    }
}

// heapifydown: move element at index i down until heap property is restored
template<typename T, int MAX_SIZE, typename Compare>
void HeapMaster<T, MAX_SIZE, Compare>::heapifyDown(int i) {
    while (true) {
        int l = left(i);
        int r = right(i);
        int best = i;

        if (l < sz && comp(data[best], data[l])) {
            best = l;
        }
        if (r < sz && comp(data[best], data[r])) {
            best = r;
        }
        if (best == i) {
            break;
        }
        std::swap(data[i], data[best]);
        i = best;
    }
}

// challenge 2: top()
template<typename T, int MAX_SIZE, typename Compare>
const T& HeapMaster<T, MAX_SIZE, Compare>::top() const {
    // Precondition: heap is not empty
    return data[0];
}

// challenge 2: pop()
template<typename T, int MAX_SIZE, typename Compare>
void HeapMaster<T, MAX_SIZE, Compare>::pop() {
    if (sz == 0) return;
    // Move last element to root and shrink
    data[0] = data[sz - 1];
    --sz;
    if (sz > 0) {
        heapifyDown(0);
    }
}

// challenge 1: push()
template<typename T, int MAX_SIZE, typename Compare>
void HeapMaster<T, MAX_SIZE, Compare>::push(const T& val) {
    if (sz >= MAX_SIZE) {
        // Ignore push if heap is full
        return;
    }
    int i = sz;
    data[sz] = val;
    ++sz;
    heapifyUp(i);
}

// challenge 8: decreasekey
template<typename T, int MAX_SIZE, typename Compare>
bool HeapMaster<T, MAX_SIZE, Compare>::decreaseKey(int index, const T& newVal) {
    if (index < 0 || index >= sz) return false;

    data[index] = newVal;
    // After changing the key, decide whether to move it up or down
    if (index > 0 && comp(data[parent(index)], data[index])) {
        heapifyUp(index);
    } else {
        heapifyDown(index);
    }
    return true;
}

// challenge 8: increasekey
template<typename T, int MAX_SIZE, typename Compare>
bool HeapMaster<T, MAX_SIZE, Compare>::increaseKey(int index, const T& newVal) {
    if (index < 0 || index >= sz) return false;

    data[index] = newVal;
    // Same logic as decreaseKey: restore heap property from this index
    if (index > 0 && comp(data[parent(index)], data[index])) {
        heapifyUp(index);
    } else {
        heapifyDown(index);
    }
    return true;
}

// challenge 5: pretty print as a tree (level-order)
template<typename T, int MAX_SIZE, typename Compare>
void HeapMaster<T, MAX_SIZE, Compare>::printHeap() const {
    if (sz == 0) {
        std::cout << "[empty heap]\n";
        return;
    }

    int level = 0;
    int levelStart = 0;
    for (int i = 0; i < sz; ++i) {
        if (i == levelStart) {
            if (i != 0) std::cout << "\n";
            std::cout << "Level " << level << ": ";
            ++level;
            levelStart = (1 << level) - 1;  // index where next level starts
        }
        std::cout << data[i] << " ";
    }
    std::cout << "\n";
}

// helper: raw array view of heap
template<typename T, int MAX_SIZE, typename Compare>
void HeapMaster<T, MAX_SIZE, Compare>::printArray() const {
    std::cout << "[";
    for (int i = 0; i < sz; ++i) {
        if (i > 0) std::cout << ", ";
        std::cout << data[i];
    }
    std::cout << "]\n";
}

// ===================== Standalone functions (heapsort & buildheap) =====================

// challenge 4: heapsort using heapifydown (no extra array)
template<typename T, typename Compare>
void heapSort(T arr[], int n, Compare comp) {
    if (n <= 1) return;

    // Build heap (bottom-up)
    buildHeap<T, Compare>(arr, n, comp);

    // Repeatedly move max/min to the end and shrink heap
    for (int end = n - 1; end > 0; --end) {
        std::swap(arr[0], arr[end]);

        // Restore heap property on the reduced heap [0..end-1]
        int i = 0;
        int sz = end;
        while (true) {
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            int best = i;

            if (l < sz && comp(arr[best], arr[l])) {
                best = l;
            }
            if (r < sz && comp(arr[best], arr[r])) {
                best = r;
            }
            if (best == i) break;
            std::swap(arr[i], arr[best]);
            i = best;
        }
    }
}

// challenge 9: build-heap optimization (bottom-up o(n) build)
template<typename T, typename Compare>
void buildHeap(T arr[], int n, Compare comp) {
    if (n <= 1) return;
    // Start from last internal node and heapifyDown each
    for (int i = n / 2 - 1; i >= 0; --i) {
        int idx = i;
        while (true) {
            int l = 2 * idx + 1;
            int r = 2 * idx + 2;
            int best = idx;

            if (l < n && comp(arr[best], arr[l])) {
                best = l;
            }
            if (r < n && comp(arr[best], arr[r])) {
                best = r;
            }
            if (best == idx) break;
            std::swap(arr[idx], arr[best]);
            idx = best;
        }
    }
}

#endif // HEAPMASTER_HPP