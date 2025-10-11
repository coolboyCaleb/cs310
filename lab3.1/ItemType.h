#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include <iostream>

class ItemType
{
public:
    virtual ~ItemType() = default;
    virtual bool CompareTo(const ItemType &other) const = 0; // Equality comparision
    virtual bool LessThan(const ItemType &other) const = 0;  // For sorting
    virtual void Print(std::ostream &out) const = 0;
};

#endif