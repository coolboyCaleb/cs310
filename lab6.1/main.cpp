#include <iostream>
#include <stdexcept>
#include "Stack.h"
#include "CircularLinkedStack.h"
#include "Queue.h"
#include "CircularLinkedQueue.h"
#include "CircularLinkedList.h"
#include "TextEditorBuffer.h"

using namespace std;

int main()
{
    // Test Stack
    Stack<char> stack;
    stack.push('A');
    stack.push('B');
    cout << "Stack top: " << stack.top() << endl;
    // Test TextEditorBuffer
    TextEditorBuffer<char> editor;
    editor.type('H');
    editor.type('i');
    editor.type('!');
    editor.displayBuffer(); // Should show: Hi!
    editor.undo();
    editor.displayBuffer(); // Should show: Hi
    editor.redo();
    editor.displayBuffer(); // Should show: Hi!
    return 0;
}
