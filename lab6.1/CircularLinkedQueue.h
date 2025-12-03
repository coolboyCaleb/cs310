#ifndef CIRCULARLINKEDQUEUE_H
#define CIRCULARLINKEDQUEUE_H

#include <stdexcept>

template <typename T>
class CircularLinkedQueue
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node(T val) : data(val), next(nullptr) {}
    };
    Node *rear;
    int count;

public:
    CircularLinkedQueue() : rear(nullptr), count(0) {}
    
    void enqueue(T item) {
        Node *newNode = new Node(item);
        if (rear == nullptr) {
            rear = newNode;
            rear->next = rear; // Point to itself
        } else {
            newNode->next = rear->next; // newNode points to front
            rear->next = newNode; // Update rear's next
            rear = newNode; // Update rear pointer
        }
        count++;
    }
    
    T dequeue() {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }
        Node *front = rear->next; // Front is rear->next in circular queue
        T data = front->data;
        if (count == 1) {
            delete front;
            rear = nullptr;
        } else {
            rear->next = front->next; // Update rear's next to skip front
            delete front;
        }
        count--;
        return data;
    }
    
    T front() const {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }
        return rear->next->data; // Front is rear->next in circular queue
    }
    
    bool isEmpty() const { return count == 0; }
    int size() const { return count; }
    
    ~CircularLinkedQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

#endif