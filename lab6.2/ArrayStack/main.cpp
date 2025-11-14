#include <iostream>
#include "ArrayStack.h"

int main() {
    std::cout << "=== Testing Array-Based Stack ===\n\n";
    
    Stack s;
    
    // Test push
    std::cout << "Testing push...\n";
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(5);
    
    // Test pop
    std::cout << "Testing pop...\n";
    int val = s.pop();
    std::cout << "Popped: " << val << "\n";
    
    // Test balanced parentheses
    std::cout << "Testing balanced...\n";
    bool bal = s.balanced("({[]})");
    std::cout << "Balanced: " << (bal ? "Yes" : "No") << "\n";
    
    // Test next greater element
    std::cout << "Testing nextGreater...\n";
    int arr[] = {4, 5, 2, 10, 8};
    int out[5];
    s.nextGreater(arr, 5, out);
    std::cout << "Next greater elements: ";
    for(int i = 0; i < 5; i++) std::cout << out[i] << " ";
    std::cout << "\n";
    
    // Test infix to postfix
    std::cout << "Testing infixToPostfix...\n";
    char postfix[100];
    s.infixToPostfix("a+b*c", postfix);
    std::cout << "Postfix: " << postfix << "\n";
    
    // Test evaluate postfix
    std::cout << "Testing evaluatePostfix...\n";
    int result = s.evaluatePostfix("23*5+");
    std::cout << "Result: " << result << "\n";
    
    // Test stock span
    std::cout << "Testing stackSpan...\n";
    int prices[] = {100, 80, 60, 70, 60, 75, 85};
    int spans[7];
    s.stackSpan(prices, 7, spans);
    std::cout << "Spans: ";
    for(int i = 0; i < 7; i++) std::cout << spans[i] << " ";
    std::cout << "\n";
    
    // Test MinStack
    std::cout << "Testing MinStack...\n";
    MinStack ms;
    ms.push(5);
    ms.push(3);
    ms.push(7);
    std::cout << "Min element: " << ms.getMin() << "\n";
    
    std::cout << "\n=== All tests completed ===\n";
    
    return 0;
}
