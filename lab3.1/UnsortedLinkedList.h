#include <iostream>
#include <string>

using namespace std;

class ItemType
{
public:
    virtual ~ItemType() = default;
    virtual bool CompareTo(const ItemType &other) const = 0; // Equality comparision
    virtual bool LessThan(const ItemType &other) const = 0;  // For sorting
    virtual void Print(ostream &out) const = 0;
};
struct Node
{
    ItemType *item;
    Node *next;
    Node(ItemType *i) : item(i), next(nullptr) {}
    ~Node() { delete item; }
};
class UnsortedLinkedList
{
protected:
    Node *listData;
    int length;
    Node *currentPos;

public:
    UnsortedLinkedList()
    {
        listData = nullptr;
        length = 0;
        currentPos = nullptr;
    }
    ~UnsortedLinkedList()
    {
        Clear();
    }
    virtual void Clear()
    {
        Node *tempPtr;
        while (listData != nullptr)
        {
            tempPtr = listData;
            listData = listData->next;
            delete tempPtr;
        }
        length = 0;
        currentPos = nullptr;
    }
    virtual void Insert(ItemType *item)
    {
        Node *location = new Node(item);
        location->next = listData;
        listData = location;
        length++;
    }
    virtual void Remove(ItemType &item)
    {
        Node *current = listData;
        Node *prev = nullptr;
        while (current != nullptr)
        {
            if (current->item->CompareTo(item))
            {
                if (prev == nullptr)
                {
                    listData = current->next;
                }
                else
                {
                    prev->next = current->next;
                }
                delete current;
                length--;
                return;
            }
            prev = current;
            current = current->next;
        }
    }
    virtual bool IsPresent(const ItemType &item) const
    {
        Node *current = listData;
        while (current != nullptr)
        {
            if (current->item->CompareTo(item))
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }
    virtual int Length() const
    {
        return length;
    }
    virtual bool IsEmpty() const
    {
        return length == 0;
    }
    virtual void ListItems() const
    {
        Node *current = listData;
        if (current == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }
        while (current != nullptr)
        {
            current->item->Print(cout);
            cout << endl;
            current = current->next;
        }
    }
};