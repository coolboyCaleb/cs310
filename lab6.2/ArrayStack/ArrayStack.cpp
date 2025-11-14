#include "ArrayStack.h"
#include <iostream>
#include <stdexcept>

bool Stack::push(int val)
{
    if (isFull())
    {
        throw std::overflow_error("Stack is full.");
    }
    else
    {
        arr[++top] = val;
        return true;
    }
    return false;
}

int Stack::pop()
{
    if (isEmpty())
    {
        throw std::underflow_error("Stack is empty.");
    }
    else
    {
        int item = arr[top--];
        return item;
    }
    return -1;
}

int Stack::peek() const
{
    return arr[top];
}

bool Stack::isEmpty() const
{
    if (top == -1)
    {
        return true;
    }
    return false;
}

bool Stack::isFull() const
{
    if (top == MAX)
    {
        return true;
    }
    return false;
}

void Stack::nextGreater(int arr[], int n, int out[])
{
    Stack s;
    for (int i = n - 1; i >= 0; --i)
    {
        while (!s.isEmpty() && arr[s.peek()] <= arr[i])
        {
            s.pop();
        }
        if (s.isEmpty())
        {
            out[i] = -1;
        }
        else
        {
            out[i] = arr[s.peek()];
        }
        s.push(i);
    }
}

bool Stack::balanced(const char *s)
{
    Stack balance;
    for (int i = 0; s[i] != '\0'; ++i)
    {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[')
        {
            balance.push(c);
        }
        else if (c == ')' || c == '}' || c == ']')
        {
            if (balance.isEmpty())
            {
                return false;
            }
            char t = static_cast<char>(balance.pop());
            if ((c == ')' && t != '(') ||
                (c == '}' && t != '{') ||
                (c == ']' && t != '['))
            {
                return false;
            }
        }
    }
    return balance.isEmpty();
}

void Stack::infixToPostfix(const char *infix, char *postfix)
{
    Stack ops;
    int j = 0;

    for (int i = 0; infix[i] != '\0'; ++i)
    {
        char c = infix[i];

        if (std::isalnum(static_cast<unsigned char>(c)))
        {
            postfix[j++] = c;
        }
        else if (c == '(')
        {
            ops.push(c);
        }
        else if (c == ')')
        {
            while (!ops.isEmpty() && static_cast<char>(ops.peek()) != '(')
            {
                postfix[j++] = static_cast<char>(ops.pop());
            }
            if (!ops.isEmpty() && static_cast<char>(ops.peek()) == '(')
            {
                ops.pop();
            }
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            while (!ops.isEmpty())
            {
                char t = static_cast<char>(ops.peek());
                bool isOp = (t == '+' || t == '-' || t == '*' || t == '/');

                bool higherOrEqual =
                    (t == '*' || t == '/') || // *,/ always beat new op
                    ((t == '+' || t == '-') && (c == '+' || c == '-'));

                if (!isOp || !higherOrEqual)
                {
                    break;
                }

                postfix[j++] = static_cast<char>(ops.pop());
            }
            ops.push(c);
        }
    }

    while (!ops.isEmpty())
    {
        postfix[j++] = static_cast<char>(ops.pop());
    }

    postfix[j] = '\0';
}

int Stack::evaluatePostfix(const char *postfix)
{
    Stack post;
    for (int i = 0; postfix[i] != '\0'; ++i)
    {
        char c = postfix[i];
        if (std::isdigit(static_cast<unsigned char>(c)))
        {
            post.push(c - '0');
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            int b = post.pop();
            int a = post.pop();
            int result = 0;
            switch (c)
            {
            case '+':
                result = a + b;
                break;
            case '-':
                result = a - b;
                break;
            case '*':
                result = a * b;
                break;
            case '/':
                result = a / b;
                break;
            }
            post.push(result);
        }
    }
    return post.pop();
}

void Stack::sortStack(Stack &s)
{
    Stack temp;
    while (!s.isEmpty())
    {
        int t = s.pop();
        while (!temp.isEmpty() && temp.peek() > t)
        {
            s.push(temp.pop());
        }
        temp.push(t);
    }
    while (!temp.isEmpty())
    {
        s.push(temp.pop());
    }
}

void Stack::stackSpan(int price[], int n, int span[])
{
    Stack sp;
    for (int i = 0; i < n; ++i)
    {
        while (!sp.isEmpty() && price[sp.peek()] <= price[i])
        {
            sp.pop();
        }
        if (sp.isEmpty())
        {
            span[i] = i + 1;
        }
        else
        {
            span[i] = i - sp.peek();
        }
        sp.push(i);
    }
}

MinStack::MinStack()
{
}

bool MinStack::push(int val)
{
    data.push(val);
    if (min.isEmpty() || val <= min.peek())
    {
        min.push(val);
    }
    return true;
}

int MinStack::pop()
{
    if (data.isEmpty())
    {
        throw std::underflow_error("Stack is empty.");
    }

    int v = data.pop();
    if (!min.isEmpty() && v == min.peek())
    {
        min.pop();
    }
    return v;
}

int MinStack::top() const
{
    if (data.isEmpty())
    {
        throw std::underflow_error("Stack is empty.");
    }
    return data.peek();
}

bool MinStack::isEmpty() const
{
    return data.isEmpty();
}

int MinStack::getMin() const
{
    if (min.isEmpty())
    {
        throw std::underflow_error("Stack is empty.");
    }
    return min.peek();
}