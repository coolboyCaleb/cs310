#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

class Node {
public:
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

class LinkedQueue {
private:
    Node *front;
    Node *rear;
    int size;

public:
    LinkedQueue() : front(nullptr), rear(nullptr) {}

    void enqueue(int v);
    int dequeue();
    int getFront() const;
    bool isEmpty() const;
    void reverse(LinkedQueue &q);
    LinkedQueue merge(const LinkedQueue &a, const LinkedQueue &b);
    void removeDuplicates(LinkedQueue &q);
    int middle(const LinkedQueue &q);
    void rotateK(LinkedQueue &q, int k);
};

#endif
