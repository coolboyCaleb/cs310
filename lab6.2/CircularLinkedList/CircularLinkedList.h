#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node *head;
    int length = 0;
public: 
    void insertHead(Node*& head, int val);
    void insertTail(Node*& head, int val);
    void deleteHead(Node*& head);
    void deleteTail(Node*& head);
    int josephus(Node*& head, int k);
    pair<Node*, Node*> split(Node*& head);
    int cycleLength(Node*& head);
    void sortedInsert(Node*& head, int val);
};

#endif
