#include "LinkedList.h"
#include "DoublyLinkedList.h"
#include "CircularLinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "SortedLinkedList.h"
#include <iostream>

// LinkedList Basic Functions
void LinkedList::insert(int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void LinkedList::print() {
    Node* temp = head;
    while (temp) {
        std::cout << temp->data;
        if (temp->next) std::cout << " -> ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// DoublyLinkedList Basic Functions
void DoublyLinkedList::insert(int val) {
    DNode* newNode = new DNode(val);
    if (!head) {
        head = newNode;
    } else {
        DNode* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void DoublyLinkedList::print() {
    DNode* temp = head;
    while (temp) {
        std::cout << temp->data;
        if (temp->next) std::cout << " <-> ";
        temp = temp->next;
    }
    std::cout << std::endl;
}


// CircularLinkedList Basic Functions
void CircularLinkedList::insert(int val) {
    CNode* newNode = new CNode(val);
    if (!head) {
        head = newNode;
        newNode->next = head; // Points to itself
    } else {
        CNode* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head; // Make it circular
    }
}

void CircularLinkedList::print() {
    if (!head) {
        std::cout << "Empty" << std::endl;
        return;
    }
    CNode* temp = head;
    do {
        std::cout << temp->data;
        temp = temp->next;
        if (temp != head) std::cout << " -> ";
    } while (temp != head);
    std::cout << " (circular)" << std::endl;
}


// Stack Basic Functions
void Stack::push(int val) {
    Node* newNode = new Node(val);
    newNode->next = top;
    top = newNode;
}

int Stack::pop() {
    if (isEmpty()) {
        std::cerr << "Stack underflow!" << std::endl;
        return -1;
    }
    Node* temp = top;
    int val = temp->data;
    top = top->next;
    delete temp;
    return val;
}

bool Stack::isEmpty() {
    return top == nullptr;
}

// Queue Basic Functions
void Queue::enqueue(int val) {
    Node* newNode = new Node(val);
    if (!rear) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

int Queue::dequeue() {
    if (isEmpty()) {
        std::cerr << "Queue underflow!" << std::endl;
        return -1;
    }
    Node* temp = front;
    int val = temp->data;
    front = front->next;
    if (!front) {
        rear = nullptr;
    }
    delete temp;
    return val;
}

bool Queue::isEmpty() {
    return front == nullptr;
}

// SortedLinkedList Basic Functions
void SortedLinkedList::insertSorted(int val) {
    Node* newNode = new Node(val);
    // If list is empty or new value should be at the beginning
    if (!head || head->data >= val) {
        newNode->next = head;
        head = newNode;
        return;
    }
    // Find the position to insert
    Node* current = head;
    while (current->next && current->next->data < val) {
        current = current->next;
    }
    
    newNode->next = current->next;
    current->next = newNode;
}
