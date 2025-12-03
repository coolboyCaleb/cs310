#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

#include <stdexcept>
#include <iostream>

template <typename T>
class CircularLinkedList
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node(T val) : data(val), next(nullptr) {}
    };
    Node *head;
    int count;

public:
    CircularLinkedList() : head(nullptr), count(0) {}
    
    void insertFront(T item) {
        Node *newNode = new Node(item);
        if (head == nullptr) {
            head = newNode;
            head->next = head; // Point to itself
        } else {
            Node *current = head;
            // Find the last node
            while (current->next != head) {
                current = current->next;
            }
            newNode->next = head;
            head = newNode;
            current->next = head; // Update last node's next
        }
        count++;
    }
    
    void insertRear(T item) {
        Node *newNode = new Node(item);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
        } else {
            Node *current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head;
        }
        count++;
    }
    
    void deleteFront() {
        if (isEmpty()) {
            throw std::runtime_error("Cannot delete from empty list");
        }
        if (count == 1) {
            delete head;
            head = nullptr;
        } else {
            Node *current = head;
            while (current->next != head) {
                current = current->next;
            }
            Node *temp = head;
            head = head->next;
            current->next = head;
            delete temp;
        }
        count--;
    }
    
    void deleteRear() {
        if (isEmpty()) {
            throw std::runtime_error("Cannot delete from empty list");
        }
        if (count == 1) {
            delete head;
            head = nullptr;
        } else {
            Node *current = head;
            while (current->next->next != head) {
                current = current->next;
            }
            delete current->next;
            current->next = head;
        }
        count--;
    }
    
    void display() const {
        if (isEmpty()) {
            std::cout << "List is empty" << std::endl;
            return;
        }
        Node *current = head;
        do {
            std::cout << current->data;
            if (current->next != head) {
                std::cout << " -> ";
            }
            current = current->next;
        } while (current != head);
        std::cout << std::endl;
    }
    
    bool isEmpty() const { return count == 0; }
    int size() const { return count; }
    
    ~CircularLinkedList() {
        while (!isEmpty()) {
            deleteFront();
        }
    }
};
#endif