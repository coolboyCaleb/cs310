// Caleb Kaalund and Landen Harley - DSA Final Project
#include <iostream>
#include <string>
#include "Task.h"
#include "MinHeap.h"

using namespace std;

int main() {
    MinHeap scheduler;
    int choice = 0;

    while (true) {
        cout << endl;
        cout << "Task Scheduler Menu" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Process Next Task" << endl;
        cout << "3. Change Task Priority" << endl;
        cout << "4. View Heap" << endl;
        cout << "5. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;
        cout << endl;
        
        if (choice == 1) {
            // Add a new task
            string desc;
            int pr;

            cout << "Enter task description: ";
            cin.ignore();                // clear leftover newline
            getline(cin, desc);          // read full description

            cout << "Enter priority (lower = sooner): ";
            cin >> pr;

            scheduler.insert(Task(desc, pr));
            cout << "Task added!" << endl;
        }

        else if (choice == 2) {
            if (scheduler.isEmpty()) {
                cout << "No tasks to process." << endl;
            } else {
                Task t = scheduler.extractMin();
                cout << "Processing task: \"" << t.description
                     << "\" (priority " << t.priority << ")" << endl;
            }
        }

        else if (choice == 3) {
            if (scheduler.isEmpty()) {
                cout << "The heap is empty. Nothing to update." << endl;
            } else {
                scheduler.printHeap();

                int index, newPr;
                cout << "Enter the index of the task to update: ";
                cin >> index;

                cout << "Enter the new priority: ";
                cin >> newPr;

                scheduler.changePriority(index, newPr);
                cout << "Priority updated." << endl;
            }
        }

        else if (choice == 4) {
            scheduler.printHeap();
        }

        else if (choice == 5) {
            cout << "Exiting program..." << endl;
            break;
        }

        else {
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
