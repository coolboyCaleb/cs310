#include "CircularLinkedList.h"
#include <iostream>
#include <stdexcept>

using namespace std;

void CircularLinkedList::insertHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr)
    {
        head = newNode;
        newNode->next = newNode;
        length = 1;
        return;
    }

    Node *tail = head;
    while (tail->next != head)
    {
        tail = tail->next;
    }

    newNode->next = head;
    head = newNode;
    tail->next = head;
    length++;
}

void CircularLinkedList::insertTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr)
    {
        head = newNode;
        newNode->next = newNode;
        length = 1;
        return;
    }

    Node *tail = head;
    while (tail->next != head)
    {
        tail = tail->next;
    }

    tail->next = newNode;
    newNode->next = head;
    length++;
}

void CircularLinkedList::deleteHead(Node *&head)
{
    if (head == nullptr)
    {
        throw std::underflow_error("Empty list");
    }
    if (head->next == head)
    {
        delete head;
        head = nullptr;
        length = 0;
        return;
    }
    Node *tail = head;
    while (tail->next != head)
    {
        tail = tail->next;
    }

    Node *temp = head;
    head = head->next;
    tail->next = head; 
    delete temp;
    length--;
}

void CircularLinkedList::deleteTail(Node *&head)
{
    if (head == nullptr)
    {
        throw std::underflow_error("Empty list");
    }

    if (head->next == head)
    {
        delete head;
        head = nullptr;
        length = 0;
        return;
    }

    Node *prev = head;
    while (prev->next->next != head)
    {
        prev = prev->next;
    }

    Node *tail = prev->next;
    prev->next = head;
    delete tail;
    length--;
}

int CircularLinkedList::josephus(Node *&head, int k)
{
    if (head == nullptr)
        return -1;
    if (head->next == head)
    {
        int val = head->val;
        delete head;
        head = nullptr;
        return val;
    }
    if (k == 1)
    {
        Node *current = head;
        while (current->next != current)
        {
            Node *temp = current->next;
            current->next = temp->next;
            if (temp == head)
                head = temp->next;
            delete temp;
        }
        int val = current->val;
        delete current;
        head = nullptr;
        return val;
    }
    Node *current = head;
    Node *prev = nullptr;
    while (current->next != current)
    {
        for (int count = 1; count < k; ++count)
        {
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        if (current == head)
        {
            head = current->next;
        }
        delete current;
        current = prev->next;
    }
    int val = current->val;
    delete current;
    head = nullptr;
    return val;
}

pair<Node *, Node *> CircularLinkedList::split(Node *&head)
{
    if (head == nullptr)
    {
        return {nullptr, nullptr};
    }
    if (head->next == head)
    {
        return {head, nullptr};
    }
    Node *slow = head;
    Node *fast = head;
    while (fast->next != head && fast->next->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *head1 = head;
    Node *head2 = slow->next;
    slow->next = head1;
    if (fast->next->next == head)
    {
        fast = fast->next;
    }
    fast->next = head2;
    return {head1, head2};
}

int CircularLinkedList::cycleLength(Node *&head)
{
    if (head == nullptr)
    {
        return 0;
    }

    int count = 1;
    Node *temp = head->next;
    while (temp != head)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

void CircularLinkedList::sortedInsert(Node *&head, int val)
{
    Node *newNode = new Node(val);

    if (head == nullptr)
    {
        head = newNode;
        newNode->next = newNode;
        length = 1;
        return;
    }

    Node *current = head;

    if (val <= head->val)
    {
        Node *tail = head;
        while (tail->next != head)
        {
            tail = tail->next;
        }
        tail->next = newNode;
        newNode->next = head;
        head = newNode;
        length++;
        return;
    }

    while (current->next != head && current->next->val < val)
    {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    length++;
}
