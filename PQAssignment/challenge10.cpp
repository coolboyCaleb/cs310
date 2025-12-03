#include "HeapMaster.h"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// comparator for fixed priority: higher priority value wins
struct TaskPriorityLess {
    bool operator()(const Task& a, const Task& b) const {
        return a.priority < b.priority;
    }
};

// comparator for edf: earlier deadline wins (min-heap behavior)
struct TaskDeadlineGreater {
    bool operator()(const Task& a, const Task& b) const {
        return a.deadline > b.deadline;
    }
};

// comparator for sorting tasks by arrival time
struct TaskArrivalLess {
    bool operator()(const Task& a, const Task& b) const {
        return a.arrivalTime < b.arrivalTime;
    }
};

int main() {
    const int numTasks = 1000;

    // generate a set of tasks
    // id: 0..999
    // arrival time: spread in [0, 99]
    // burst time: in [1, 10]
    // deadline: arrival time + 30 + small offset
    // priority: in [1, 10]
    vector<Task> tasks;
    tasks.reserve(numTasks);

    for (int i = 0; i < numTasks; ++i) {
        Task t;
        t.id = i;
        t.arrivalTime = i % 100;
        t.burstTime = (i % 10) + 1;
        t.priority = (i % 10) + 1;
        t.deadline = t.arrivalTime + 30 + (i % 5);
        tasks.push_back(t);
    }

    // make a copy sorted by arrival time for both schedulers
    vector<Task> tasksSorted = tasks;
    sort(tasksSorted.begin(), tasksSorted.end(), TaskArrivalLess());

    // ================= fixed priority simulation =================
    cout << "Running fixed priority scheduler..." << endl;

    HeapMaster<Task, 5000, TaskPriorityLess> fixedHeap;

    vector<int> remainingFixed(numTasks);
    vector<int> startTimeFixed(numTasks, -1);
    vector<int> completionTimeFixed(numTasks, -1);

    for (int i = 0; i < numTasks; ++i) {
        remainingFixed[i] = tasks[i].burstTime;
    }

    int timeFixed = 0;
    int finishedFixed = 0;
    int nextIndexFixed = 0;
    const int maxTime = 100000;

    // simulate preemptive fixed priority scheduling
    while (finishedFixed < numTasks && timeFixed < maxTime) {
        // add all tasks that have arrived by this time
        while (nextIndexFixed < numTasks &&
               tasksSorted[nextIndexFixed].arrivalTime <= timeFixed) {
            fixedHeap.push(tasksSorted[nextIndexFixed]);
            ++nextIndexFixed;
        }

        if (fixedHeap.empty()) {
            // no task ready, cpu idle
            ++timeFixed;
            continue;
        }

        // pick highest priority task
        Task current = fixedHeap.top();
        fixedHeap.pop();

        int id = current.id;

        if (startTimeFixed[id] == -1) {
            startTimeFixed[id] = timeFixed;
        }

        // run task for one time unit
        remainingFixed[id] = remainingFixed[id] - 1;
        ++timeFixed;

        if (remainingFixed[id] == 0) {
            completionTimeFixed[id] = timeFixed;
            ++finishedFixed;
        } else {
            // update remaining time in task and push back
            current.burstTime = remainingFixed[id];
            fixedHeap.push(current);
        }
    }

    int missedFixed = 0;
    long long totalWaitFixed = 0;

    for (int i = 0; i < numTasks; ++i) {
        if (completionTimeFixed[i] == -1) {
            // task never finished within maxTime, count as missed
            ++missedFixed;
            continue;
        }

        if (completionTimeFixed[i] > tasks[i].deadline) {
            ++missedFixed;
        }

        int wait = startTimeFixed[i] - tasks[i].arrivalTime;
        if (wait < 0) {
            wait = 0;
        }
        totalWaitFixed += wait;
    }

    double avgWaitFixed = 0.0;
    if (numTasks > 0) {
        avgWaitFixed = static_cast<double>(totalWaitFixed) /
                       static_cast<double>(numTasks);
    }

    // expect: fixed priority will usually have some missed deadlines
    // expect: average wait time can be relatively high
    cout << "Fixed priority missed deadlines: " << missedFixed << endl;
    cout << "Fixed priority average wait time: " << avgWaitFixed << endl;

    // ================= edf simulation =================
    cout << endl;
    cout << "Running earliest deadline first (edf) scheduler..." << endl;

    HeapMaster<Task, 5000, TaskDeadlineGreater> edfHeap;

    vector<int> remainingEdf(numTasks);
    vector<int> startTimeEdf(numTasks, -1);
    vector<int> completionTimeEdf(numTasks, -1);

    for (int i = 0; i < numTasks; ++i) {
        remainingEdf[i] = tasks[i].burstTime;
    }

    int timeEdf = 0;
    int finishedEdf = 0;
    int nextIndexEdf = 0;

    // simulate preemptive edf scheduling
    while (finishedEdf < numTasks && timeEdf < maxTime) {
        // add all tasks that have arrived by this time
        while (nextIndexEdf < numTasks &&
               tasksSorted[nextIndexEdf].arrivalTime <= timeEdf) {
            edfHeap.push(tasksSorted[nextIndexEdf]);
            ++nextIndexEdf;
        }

        if (edfHeap.empty()) {
            // no task ready, cpu idle
            ++timeEdf;
            continue;
        }

        // pick task with earliest deadline
        Task current = edfHeap.top();
        edfHeap.pop();

        int id = current.id;

        if (startTimeEdf[id] == -1) {
            startTimeEdf[id] = timeEdf;
        }

        // run task for one time unit
        remainingEdf[id] = remainingEdf[id] - 1;
        ++timeEdf;

        if (remainingEdf[id] == 0) {
            completionTimeEdf[id] = timeEdf;
            ++finishedEdf;
        } else {
            // update remaining time in task and push back
            current.burstTime = remainingEdf[id];
            edfHeap.push(current);
        }
    }

    int missedEdf = 0;
    long long totalWaitEdf = 0;

    for (int i = 0; i < numTasks; ++i) {
        if (completionTimeEdf[i] == -1) {
            // task never finished within maxTime, count as missed
            ++missedEdf;
            continue;
        }

        if (completionTimeEdf[i] > tasks[i].deadline) {
            ++missedEdf;
        }

        int wait = startTimeEdf[i] - tasks[i].arrivalTime;
        if (wait < 0) {
            wait = 0;
        }
        totalWaitEdf += wait;
    }

    double avgWaitEdf = 0.0;
    if (numTasks > 0) {
        avgWaitEdf = static_cast<double>(totalWaitEdf) /
                     static_cast<double>(numTasks);
    }

    // expect: edf should have fewer missed deadlines than fixed priority
    // expect: edf often has lower average wait time than fixed priority
    cout << "edf missed deadlines: " << missedEdf << endl;
    cout << "edf average wait time: " << avgWaitEdf << endl;

    return 0;
}