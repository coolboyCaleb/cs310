#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

class Queue {
private:
    static const int MAX = 1000; 
    int arr[MAX];
    int front, rear;

public:
    Queue() : front(0), rear(-1) {};
    
    bool enqueue(int val);
    int dequeue();
    int getFront() const;
    bool isEmpty() const;
    bool isFull() const;
    void reverseK(Queue &q, int k);
    void generateBinary(int n);


};
class StackFromQueue{
    Queue q1, q2;
    public: 
        void push(int x);
        int pop();
};
struct TreeNode {int val; TreeNode *left, *right;};
void levelOrder(TreeNode *root);
void slidingWindowMax(int arr[], int n, int k, int out[]);
void interleave(Queue &q);

#endif
