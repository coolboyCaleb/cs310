#ifndef CIRCULARLINKEDSTACK_H
#define CIRCULARLINKEDSTACK_H

#include <stdexcept>

template <typename T>
class CircularLinkedStack
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node(T val) : data(val), next(nullptr) {}
    };
    Node *topNode;
    int count;

public:
    CircularLinkedStack() : topNode(nullptr), count(0) {}
    
    void push(T item) {
        Node *newNode = new Node(item);
        if (topNode == nullptr) {
            topNode = newNode;
            topNode->next = topNode; // Point to itself
        } else {
            newNode->next = topNode;
            // Find the last node to maintain circularity
            Node *current = topNode;
            while (current->next != topNode) {
                current = current->next;
            }
            topNode = newNode;
            current->next = topNode; // Update last node's next
        }
        count++;
    }
    
    T pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }
        T data = topNode->data;
        if (count == 1) {
            delete topNode;
            topNode = nullptr;
        } else {
            // Find the last node
            Node *current = topNode;
            while (current->next != topNode) {
                current = current->next;
            }
            Node *temp = topNode;
            topNode = topNode->next;
            current->next = topNode; // Update last node's next
            delete temp;
        }
        count--;
        return data;
    }
    
    T top() const {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }
        return topNode->data;
    }
    
    bool isEmpty() const { return count == 0; }
    int size() const { return count; }
    
    ~CircularLinkedStack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

#endif