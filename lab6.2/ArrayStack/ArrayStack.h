#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

class Stack {
protected:
    static const int MAX = 100;
    int arr[MAX];
    int top;

public:
    Stack() : top(-1) {};
    
    bool push(int val);
    int pop();
    int peek() const;
    bool isEmpty() const;
    bool isFull() const;
    void nextGreater(int arr[], int n, int out[]);
    bool balanced(const char* s);
    void infixToPostfix(const char* infix, char* postfix);
    int evaluatePostfix(const char* postfix);
    void sortStack(Stack& s);
    void stackSpan(int price[], int n, int span[]);
};

class MinStack
{
private:
    Stack data;
    Stack min;

public:
    MinStack();

    bool push(int val);
    int pop();
    int top() const;
    bool isEmpty() const;
    int getMin() const;
};

#endif