#include <iostream>
#include "CircularQueue.h"

int main() {
    std::cout << "=== Testing Circular Queue ===\n\n";
    
    CircularQueue cq;
    
    // Test enqueue
    std::cout << "Testing enqueue...\n";
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    
    // Test dequeue
    std::cout << "Testing dequeue...\n";
    int val = cq.dequeue();
    std::cout << "Dequeued: " << val << "\n";
    
    // Test first negative in window
    std::cout << "Testing firstNegative...\n";
    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    cq.firstNegative(arr, 8, 3);
    
    // Test circular tour (petrol pump)
    std::cout << "Testing circularTour...\n";
    int petrol[] = {4, 6, 7, 4};
    int dist[] = {6, 5, 3, 5};
    int start = cq.circularTour(petrol, dist, 4);
    std::cout << "Starting petrol pump: " << start << "\n";
    
    // Test rotate
    std::cout << "Testing rotate...\n";
    CircularQueue cq2;
    for(int i = 1; i <= 5; i++) cq2.enqueue(i);
    cq2.rotate(cq2, 2);
    
    // Test isPalindrome
    std::cout << "Testing isPalindrome...\n";
    bool pal = cq.isPalindrome("racecar");
    std::cout << "Is palindrome: " << (pal ? "Yes" : "No") << "\n";
    
    // Test printReverse
    std::cout << "Testing printReverse...\n";
    CircularQueue cq3;
    for(int i = 1; i <= 5; i++) cq3.enqueue(i);
    cq.printReverse(cq3);
    
    std::cout << "\n=== All tests completed ===\n";
    
    return 0;
}
