#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H


struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int length;

public:
    DoublyLinkedList();

    void insertHead(int val);
    void insertTail(int val);
    void deleteHead(Node*& head, Node*& tail, int val);
    void deleteTail(Node*& head, Node*& tail, int val);
    void insertAfter(Node *node, int val);
    void deleteNode(Node *node);
    void reverse(Node*& head, Node*& tail);
    Node* findMiddle(Node* head);
    bool hasCycle(Node* head);
};

#endif
