#include "ArrayQueue.h"
#include <iostream>

bool Queue::enqueue(int val) {
    if (isFull()) {
        return false;
    }

    if (isEmpty()) {
        front = 0;
        rear = 0;
        arr[rear] = val;
    } else {
        arr[++rear] = val;
    }

    return true;
}

int Queue::dequeue() {
    if(!isEmpty()){
        int val = arr[rear];
        return val;
    }
    return -1;
}

int Queue::getFront() const {
    if(!isEmpty()){
        return arr[front];
    }
    return -1;
}

bool Queue::isEmpty() const {
    return front > rear;
}

bool Queue::isFull() const {
    return rear == MAX - 1;
}

void Queue::reverseK(Queue &q, int k) {
    if (k <= 0) {
        return;
    }

    if (q.rear < q.front) {
        return;
    }

    int total = q.rear - q.front + 1;
    if (total <= 1) {
        return;
    }

    if (k > total) {
        k = total;
    }

    for (int i = 0; i < k / 2; ++i) {
        int leftIndex = q.front + i;
        int rightIndex = q.front + k - 1 - i;
        int temp = q.arr[leftIndex];
        q.arr[leftIndex] = q.arr[rightIndex];
        q.arr[rightIndex] = temp;
    }
}

void Queue::generateBinary(int n) {
    if (n <= 0)
    {
        std::cout << "\n";
        return;
    }

    Queue q;
    q.enqueue(1);

    for (int i = 0; i < n; ++i)
    {
        int x = q.dequeue();
        if (i > 0)
        {
            std::cout << " ";
        }
        std::cout << x;

        q.enqueue(x * 10);
        q.enqueue(x * 10 + 1);
    }

    std::cout << "\n";
}

void StackFromQueue::push(int x) {
    q2.enqueue(x);

    while (!q1.isEmpty()) {
        q2.enqueue(q1.dequeue());
    }

    while (!q2.isEmpty()) {
        q1.enqueue(q2.dequeue());
    }
}

int StackFromQueue::pop() {
    if (q1.isEmpty()) {
        return -1;
    }

    return q1.dequeue();
}

void levelOrder(TreeNode *root) {
    if (root == nullptr) {
        return;
    }

    int capacity = 64;
    TreeNode **buffer = new TreeNode *[capacity];
    int frontIndex = 0;
    int rearIndex = 0;

    buffer[rearIndex++] = root;

    while (frontIndex < rearIndex) {
        TreeNode *current = buffer[frontIndex++];
        std::cout << current->val << " ";

        if (current->left != nullptr) {
            if (rearIndex >= capacity) {
                int newCapacity = capacity * 2;
                TreeNode **newBuffer = new TreeNode *[newCapacity];
                int j = 0;
                for (int i = frontIndex; i < rearIndex; ++i) {
                    newBuffer[j++] = buffer[i];
                }
                delete[] buffer;
                buffer = newBuffer;
                capacity = newCapacity;
                rearIndex = j;
                frontIndex = 0;
            }
            buffer[rearIndex++] = current->left;
        }

        if (current->right != nullptr) {
            if (rearIndex >= capacity) {
                int newCapacity = capacity * 2;
                TreeNode **newBuffer = new TreeNode *[newCapacity];
                int j = 0;
                for (int i = frontIndex; i < rearIndex; ++i) {
                    newBuffer[j++] = buffer[i];
                }
                delete[] buffer;
                buffer = newBuffer;
                capacity = newCapacity;
                rearIndex = j;
                frontIndex = 0;
            }
            buffer[rearIndex++] = current->right;
        }
    }

    delete[] buffer;
    std::cout << "\n";
}

void slidingWindowMax(int arr[], int n, int k, int out[]) {
    if (arr == nullptr || out == nullptr || n <= 0 || k <= 0 || k > n) {
        return;
    }

    for (int i = 0; i <= n - k; ++i) {
        int currentMax = arr[i];
        for (int j = 1; j < k; ++j) {
            if (arr[i + j] > currentMax) {
                currentMax = arr[i + j];
            }
        }
        out[i] = currentMax;
    }
}

void interleave(Queue &q) {
    if (q.isEmpty()) {
        return;
    }

    Queue temp;
    Queue result;

    int n = 0;

    while (!q.isEmpty()) {
        temp.enqueue(q.dequeue());
        n++;
    }

    int half = n / 2;

    for (int i = 0; i < half; ++i) {
        q.enqueue(temp.dequeue());
    }

    while (!temp.isEmpty()) {
    }

    while (!q.isEmpty() && !temp.isEmpty()) {
        result.enqueue(q.dequeue());
        result.enqueue(temp.dequeue());
    }

    while (!q.isEmpty()) {
        result.enqueue(q.dequeue());
    }

    while (!temp.isEmpty()) {
        result.enqueue(temp.dequeue());
    }

    while (!result.isEmpty()) {
        q.enqueue(result.dequeue());
    }
}
