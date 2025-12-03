#include "Stack.h"
#include <iostream>
#include <cstring>

// Recursive problem functions

// Helper function to insert element in sorted order
// Time Complexity: O(n) where n is the number of elements in stack
// Space Complexity: O(n) due to recursion stack
void insertSortedHelper(Node *&top, int val)
{
    if (top == nullptr || val >= top->data)
    {
        Node *newNode = new Node(val);
        newNode->next = top;
        top = newNode;
        return;
    }

    // Recursively insert in the rest
    insertSortedHelper(top->next, val);
}

// Time Complexity: O(n^2) where n is the number of elements
// Space Complexity: O(n) due to recursion stack
// Note: Each element requires O(n) insertion in worst case
void Stack::recursiveSort()
{
    // Base case: stack is empty or has one element
    if (isEmpty() || top->next == nullptr)
        return;

    // Pop the top element
    int temp = pop();

    // Recursively sort the remaining stack
    recursiveSort();

    // Insert the popped element in sorted order
    insertSortedHelper(top, temp);
}

// Helper function to reverse stack recursively
// Time Complexity: O(n) where n is the number of elements
// Space Complexity: O(n) due to recursion stack
void reverseHelper(Node *&top, Node *prev)
{
    if (top == nullptr)
    {
        top = prev;
        return;
    }
    Node *next = top->next;
    top->next = prev;
    reverseHelper(next, top);
}

void Stack::recursiveReverse()
{
    reverseHelper(top, nullptr);
}

// Helper function for recursive postfix evaluation (reads from right to left)
// Time Complexity: O(n) where n is the length of the expression
// Space Complexity: O(n) due to recursion stack
int postfixEvalHelper(const char *expr, int &index)
{
    // Skip spaces
    while (index >= 0 && expr[index] == ' ')
        index--;

    if (index < 0)
        return 0;

    // If it's a digit, parse the number
    if (expr[index] >= '0' && expr[index] <= '9')
    {
        int num = 0;
        int multiplier = 1;
        while (index >= 0 && expr[index] >= '0' && expr[index] <= '9')
        {
            num = num + (expr[index] - '0') * multiplier;
            multiplier *= 10;
            index--;
        }
        return num;
    }

    // It's an operator - read operands first (right to left)
    char op = expr[index--];
    int left = postfixEvalHelper(expr, index);
    int right = postfixEvalHelper(expr, index);

    switch (op)
    {
    case '+':
        return left + right;
        break;
    case '-':
        return left - right;
        break;
    case '*':
        return left * right;
        break;
    case '/':
        return left / right;
        break;
    default:
        return 0;
    }
}

int Stack::postfixEval(const char *expr)
{
    if (expr == nullptr || *expr == '\0')
        return 0;

    int len = strlen(expr);
    int index = len - 1; // Start from the end

    return postfixEvalHelper(expr, index);
}

// Helper function for recursive parentheses checking
// Time Complexity: O(n) where n is the length of the expression
// Space Complexity: O(n) due to recursion stack
static bool checkParenthesesHelper(const char *expr, int &index, int &openCount)
{
    if (expr[index] == '\0')
    {
        return openCount == 0;
    }

    if (expr[index] == '(')
    {
        openCount++;
        index++;
        return checkParenthesesHelper(expr, index, openCount);
    }
    else if (expr[index] == ')')
    {
        if (openCount <= 0)
            return false;
        openCount--;
        index++;
        return checkParenthesesHelper(expr, index, openCount);
    }
    else
    {
        index++;
        return checkParenthesesHelper(expr, index, openCount);
    }
}

bool Stack::checkParentheses(const char *expr)
{
    if (expr == nullptr)
        return true;

    int index = 0;
    int openCount = 0;
    return checkParenthesesHelper(expr, index, openCount);
}
