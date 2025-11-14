#include "LinkedQueue.h"
#include <iostream>

void LinkedQueue::enqueue(int v) {
    Node *newNode = new Node(v);
    newNode->next = nullptr;

    if (front == nullptr) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    size++;
}

int LinkedQueue::dequeue() {
    if (isEmpty()) {
        return -1;
    }

    int info = front->val;
    Node *temp = front;
    front = front->next;
    delete temp;

    if (front == nullptr) {
        rear = nullptr;
    }

    size--;
    return info;
}

int LinkedQueue::getFront() const {
    if(!isEmpty()){
        return front->val;
    }
    return -1;
}

bool LinkedQueue::isEmpty() const {
    if(front == nullptr){
        return true;
    }
    return false;
}

void LinkedQueue::reverse(LinkedQueue &q) {
    Node *prev = nullptr;
    Node *current = q.front;
    Node *oldFront = q.front;

    while (current != nullptr) {
        Node *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    q.front = prev;
    q.rear = oldFront;

    q.size = 0;
    Node *cursor = q.front;
    while (cursor != nullptr) {
        ++q.size;
        if (cursor->next == nullptr) {
            q.rear = cursor;
        }
        cursor = cursor->next;
    }
}

LinkedQueue LinkedQueue::merge(const LinkedQueue &a, const LinkedQueue &b) {
    LinkedQueue result;

    Node dummy(0);
    Node *tail = &dummy;

    Node *pa = a.front;
    Node *pb = b.front;

    while (pa != nullptr && pb != nullptr) {
        if (pa->val <= pb->val) {
            tail->next = new Node(pa->val);
            pa = pa->next;
        } else {
            tail->next = new Node(pb->val);
            pb = pb->next;
        }
        tail = tail->next;
    }

    while (pa != nullptr) {
        tail->next = new Node(pa->val);
        tail = tail->next;
        pa = pa->next;
    }

    while (pb != nullptr) {
        tail->next = new Node(pb->val);
        tail = tail->next;
        pb = pb->next;
    }

    result.front = dummy.next;
    result.rear = nullptr;
    result.size = 0;

    Node *cursor = result.front;
    while (cursor != nullptr) {
        ++result.size;
        if (cursor->next == nullptr) {
            result.rear = cursor;
        }
        cursor = cursor->next;
    }

    return result;
}

void LinkedQueue::removeDuplicates(LinkedQueue &q) {
    Node *current = q.front;

    while (current != nullptr) {
        Node *runner = current;
        while (runner->next != nullptr && runner->next->val == current->val) {
            Node *duplicate = runner->next;
            runner->next = duplicate->next;
            delete duplicate;
        }
        current = current->next;
    }

    q.rear = nullptr;
    q.size = 0;
    Node *cursor = q.front;
    while (cursor != nullptr) {
        ++q.size;
        if (cursor->next == nullptr) {
            q.rear = cursor;
        }
        cursor = cursor->next;
    }
}

int LinkedQueue::middle(const LinkedQueue &q) {
    if (q.front == nullptr) {
        return -1;
    }

    Node *slow = q.front;
    Node *fast = q.front;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return (slow != nullptr) ? slow->val : -1;
}

void LinkedQueue::rotateK(LinkedQueue &q, int k) {
    if (q.front == nullptr || k <= 0) {
        return;
    }

    int length = 0;
    Node *tail = q.front;
    while (tail->next != nullptr) {
        tail = tail->next;
        ++length;
    }
    ++length; // include last node

    int effective = k % length;
    if (effective == 0) {
        q.size = length;
        q.rear = tail;
        return;
    }

    Node *current = q.front;
    Node *prev = nullptr;
    for (int i = 0; i < effective; ++i) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        return;
    }

    tail->next = q.front;
    q.front = current;
    prev->next = nullptr;
    q.rear = prev;

    q.size = length;
}
