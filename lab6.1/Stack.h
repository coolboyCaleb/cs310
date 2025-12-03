#ifndef STACK_H
#define STACK_H

#include <stdexcept>



template <typename T>
class Stack {
private:
    T* arr;
    int capacity;
    int topIndex;

public:
    Stack() : capacity(100), topIndex(-1) {
        arr = new T[capacity];
    }

    ~Stack() { delete[] arr; }

    void push(T item) {
        if (topIndex == capacity) throw std::overflow_error("Stack overflow");
        arr[++topIndex] = item;
    }

    T pop() {
        if (isEmpty()) throw std::underflow_error("Stack underflow");
        return arr[topIndex--];
    }

    T top() const {
        if (isEmpty()) throw std::underflow_error("Stack is empty");
        return arr[topIndex];
    }

    bool isEmpty() const { return topIndex == -1; }
    bool isFull()  const { return topIndex + 1 == capacity; }
    int  size()    const { return topIndex + 1; }
};

#endif