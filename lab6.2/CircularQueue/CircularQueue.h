#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

class CircularQueue {
private:
    static const int MAX = 1000;
    int arr[MAX];
    int front, rear, size;

public:
    CircularQueue() : front(0), rear(-1), size(0){};
    
    bool enqueue(int x); // modulo
    int dequeue();
    void firstNegative(int arr[], int n, int k);
    int circularTour(int petrol[], int dist[], int n); // petrol pump
    void rotate(CircularQueue &q, int k);
    bool isPalindrome(const char *s);
    void printReverse(CircularQueue &q);
};

class LRU{}; // use circular queue + map or array

#endif
