#ifndef TEXTEDITORBUFFER_H
#define TEXTEDITORBUFFER_H

#include "CircularLinkedStack.h"
#include "CircularLinkedQueue.h"
#include "CircularLinkedList.h"
#include <iostream>
#include <string>

template <typename T>
class TextEditorBuffer
{
private:
    CircularLinkedStack<T> buffer;
    CircularLinkedQueue<T> redoQueue;
    CircularLinkedList<std::string> history; // Optional
    
public:
    void type(T item) {
        buffer.push(item);
        // Clear redo queue when new action is performed
        while (!redoQueue.isEmpty()) {
            redoQueue.dequeue();
        }
    }
    
    void undo() {
        if (!buffer.isEmpty()) {
            T item = buffer.pop();
            redoQueue.enqueue(item);
        }
    }
    
    void redo() {
        if (!redoQueue.isEmpty()) {
            T item = redoQueue.dequeue();
            buffer.push(item);
        }
    }
    
    void displayBuffer() const {
        if (buffer.isEmpty()) {
            std::cout << "Buffer is empty" << std::endl;
            return;
        }
        
        // To display stack in correct order (oldest to newest), we need to:
        // 1. Pop all elements into a temp stack (reverses order)
        // 2. Pop from temp stack to display (reverses again = original order)
        // 3. Push all back to restore buffer in original order
        CircularLinkedStack<T> tempStack;
        CircularLinkedStack<T> restoreStack;
        
        // Use const_cast to temporarily modify for display, then restore
        CircularLinkedStack<T>& mutableBuffer = const_cast<CircularLinkedStack<T>&>(buffer);
        
        // Step 1: Pop all from buffer to tempStack (first reversal)
        while (!mutableBuffer.isEmpty()) {
            tempStack.push(mutableBuffer.pop());
        }
        
        // Step 2: Pop from tempStack to display and save to restoreStack (second reversal = original order)
        while (!tempStack.isEmpty()) {
            T item = tempStack.pop();
            std::cout << item;
            restoreStack.push(item);
        }
        std::cout << std::endl;
        
        // Step 3: Restore buffer by pushing all back in reverse order
        // We need to reverse restoreStack to get original buffer order
        while (!restoreStack.isEmpty()) {
            tempStack.push(restoreStack.pop());
        }
        while (!tempStack.isEmpty()) {
            mutableBuffer.push(tempStack.pop());
        }
    }
    
    void displayHistory() const {
        if (history.isEmpty()) {
            std::cout << "History is empty" << std::endl;
            return;
        }
        history.display();
    }
};

#endif