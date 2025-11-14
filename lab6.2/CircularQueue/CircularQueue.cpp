#include "CircularQueue.h"
#include <iostream>

bool CircularQueue::enqueue(int val) {
    arr[rear] = val;
    rear = (rear + 1) % MAX;
    size++;

    return true;
}

int CircularQueue::dequeue() {
    if (rear == -1) {
        return rear;
    }

    int val = arr[front];
    front = (front + 1) % MAX;
    size--;

    return val;
}

void CircularQueue::firstNegative(int arr[], int n, int k) {
    if (arr == nullptr || n <= 0 || k <= 0 || k > n) {
        std::cout << "\n";
        return;
    }

    int *indices = new int[n];
    int frontIndex = 0;
    int rearIndex = 0;

    for (int i = 0; i < n; ++i) {
        while (frontIndex < rearIndex && indices[frontIndex] <= i - k) {
            ++frontIndex;
        }

        if (arr[i] < 0) {
            indices[rearIndex++] = i;
        }

        if (i >= k - 1) {
            if (frontIndex < rearIndex) {
                std::cout << arr[indices[frontIndex]];
            } else {
                std::cout << "0";
            }

            if (i != n - 1) {
                std::cout << " ";
            }
        }
    }

    delete[] indices;
    std::cout << "\n";
}

int CircularQueue::circularTour(int petrol[], int dist[], int n) {
    if (petrol == nullptr || dist == nullptr || n <= 0) {
        return -1;
    }

    int start = 0;
    int deficit = 0;
    int balance = 0;

    for (int i = 0; i < n; ++i) {
        balance += petrol[i] - dist[i];
        if (balance < 0) {
            start = i + 1;
            deficit += balance;
            balance = 0;
        }
    }

    return (balance + deficit >= 0) ? start % n : -1;
}

void CircularQueue::rotate(CircularQueue &q, int k) {
    if (q.size <= 0) {
        return;
    }

    int count = q.size;
    int effective = k % count;
    if (effective < 0) {
        effective += count;
    }

    if (effective == 0) {
        return;
    }

    int *snapshot = new int[count];
    for (int i = 0; i < count; ++i) {
        snapshot[i] = q.arr[(q.front + i) % MAX];
    }

    int *rotated = new int[count];
    for (int i = 0; i < count; ++i) {
        rotated[i] = snapshot[(i + effective) % count];
    }

    for (int i = 0; i < count; ++i) {
        q.arr[(q.front + i) % MAX] = rotated[i];
    }

    delete[] snapshot;
    delete[] rotated;
}

bool CircularQueue::isPalindrome(const char *s) {
    if (s == nullptr) {
        return false;
    }

    int left = 0;
    int right = 0;
    while (s[right] != '\0') {
        ++right;
    }

    if (right == 0) {
        return true;
    }
    --right;

    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        ++left;
        --right;
    }

    return true;
}

void CircularQueue::printReverse(CircularQueue &q) {
    if (q.size <= 0) {
        std::cout << "\n";
        return;
    }

    int count = q.size;
    int *elements = new int[count];
    for (int i = 0; i < count; ++i) {
        elements[i] = q.arr[(q.front + i) % MAX];
    }

    for (int i = count - 1; i >= 0; --i) {
        std::cout << elements[i];
        if (i != 0) {
            std::cout << " ";
        }
    }

    delete[] elements;
    std::cout << "\n";
}
