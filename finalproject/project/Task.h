#ifndef TASK_H
#define TASK_H

#include <string>
using namespace std;

// Task structure used inside the MinHeap.
// Lower priority number = higher priority.
struct Task {
    string description;
    int priority;

    // Default constructor (needed when vectors resize or move objects)
    Task() : description(""), priority(0) {}

    // Main constructor
    Task(const string &desc, int pr)
        : description(desc), priority(pr) {}
};

#endif
