#include "DoublyLinkedList.h"
#include <iostream>
#include <stdexcept>

DoublyLinkedList::DoublyLinkedList()
{
    head = nullptr;
    tail = nullptr;
    length = 0;
}

void DoublyLinkedList::insertHead(int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
        newNode->next = nullptr;
        newNode->prev = nullptr;
    }
    else
    {
        newNode->next = head;
        newNode->prev = nullptr;
        head->prev = newNode;
        head = newNode;
    }
    length++;
}

void DoublyLinkedList::insertTail(int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
        newNode->next = nullptr;
        newNode->prev = nullptr;
    }
    else
    {
        newNode->prev = tail;
        newNode->next = nullptr;
        tail->next = newNode;
        tail = newNode;
    }
    length++;
}

void DoublyLinkedList::deleteHead(Node *&head, Node *&tail, int val)
{
    if (head == nullptr)
    {
        throw std::underflow_error("List is empty.");
    }

    if (head->data != val)
    {
        throw std::out_of_range("Item is not in list.");
    }

    Node *temp = head;

    if (head == tail)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        head = head->next;
        head->prev = nullptr;
    }

    delete temp;
    length--;
}

void DoublyLinkedList::deleteTail(Node *&head, Node *&tail, int val)
{
    if (tail == nullptr)
    {
        throw std::underflow_error("List is empty.");
    }

    if (tail->data != val)
    {
        throw std::out_of_range("Item is not in list.");
    }

    Node *temp = tail;

    if (head == tail)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        tail = tail->prev;
        tail->next = nullptr;
    }

    delete temp;
    length--;
}

void DoublyLinkedList::insertAfter(Node *node, int val)
{
    if (node == nullptr)
    {
        throw std::invalid_argument("Cannot insert after null node.");
    }

    Node *current = head;
    while (current != nullptr && current != node)
    {
        current = current->next;
    }

    if (current == nullptr)
    {
        throw std::out_of_range("Node not found in list.");
    }

    Node *newNode = new Node(val);
    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != nullptr)
    {
        current->next->prev = newNode;
    }
    else
    {
        tail = newNode;
    }

    current->next = newNode;
    length++;
}

void DoublyLinkedList::deleteNode(Node *node)
{
    if (node == nullptr)
    {
        throw std::invalid_argument("Cannot delete null node.");
    }

    Node *current = head;
    while (current != nullptr && current != node)
    {
        current = current->next;
    }

    if (current == nullptr)
    {
        throw std::out_of_range("Node not found in list.");
    }

    if (current == head)
    {
        deleteHead(head, tail, current->data);
        return;
    }

    if (current == tail)
    {
        deleteTail(head, tail, current->data);
        return;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;

    delete current;
    length--;
}

void DoublyLinkedList::reverse(Node *&head, Node *&tail)
{
    if(head == nullptr || head == tail){
        return;
    }
    Node *current = head;
    Node *temp = head;
    Node *nextNode;
    while (current != nullptr)
    {
       nextNode = current->next;
       current->next = current->prev;
       current->prev = nextNode;
       current = nextNode;
    }
    head = tail;
    tail = temp;
}

Node *DoublyLinkedList::findMiddle(Node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

bool DoublyLinkedList::hasCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;      
        fast = fast->next->next;
        if (slow == fast){
            return true;}
    }
    return false;
}
