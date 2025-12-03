Min-Heap Task Scheduler – Final Project

CSC 310 – Data Structures and Algorithms

Authors: Caleb Kaalund & Landen Harley

⸻

Project Overview

This project implements a Task Scheduler using a Min-Heap data structure. Tasks are organized by priority, where the task with the lowest priority value is processed first. The implementation includes custom heap logic, a Task class, and a driver program that demonstrates heap behavior.

The project includes the following files:
	•	Task.h — Task struct and comparison operators
	•	MinHeap.h — MinHeap class interface
	•	MinHeap.cpp — MinHeap class implementation
	•	main.cpp — Demonstration program

This README explains how the system works and how to build and run the program.

⸻

Included Files

Task.h

Defines a simple Task type:
	•	Task name (string)
	•	Priority (int)
	•	Overloaded comparison operators used by the Min-Heap

MinHeap.h

Declares all public MinHeap operations:
	•	Constructor and destructor
	•	insert(Task)
	•	deleteMin(Task&)
	•	isEmpty() and isFull()
	•	Internal helpers: reheapUp() and reheapDown()

MinHeap.cpp

Implements the MinHeap logic:
	•	Array-based complete binary tree
	•	Parent and child index calculations
	•	ReheapUp after insertion
	•	ReheapDown after deletion
	•	Ensures Min-Heap order is always maintained

main.cpp

Demonstrates:
	•	Creating a heap instance
	•	Inserting multiple tasks
	•	Deleting tasks in correct priority order
	•	Printing the output

⸻

How the Min-Heap Works

Array Representation

The heap is stored in an array. Node relationships follow:

parent(i) = (i - 1) / 2
left(i)   = 2*i + 1
right(i)  = 2*i + 2

This structure guarantees the shape property of a complete binary tree.

Order Property (Min-Heap)

Each node’s priority must be less than or equal to its children’s priorities.

To maintain this property:
	•	Insertions use ReheapUp
	•	Deletions use ReheapDown

Both operations run in O(log n) time.

⸻

Insertion Process (Reheap Up)
	1.	Insert the new Task at the next available index.
	2.	Compare the task with its parent.
	3.	Swap upward until the Min-Heap property is satisfied.

⸻

Deletion Process (Reheap Down)
	1.	Remove the root (minimum-priority Task).
	2.	Move the last element in the heap to the root.
	3.	Compare with children.
	4.	Swap downward with the smaller child until the heap is corrected.

⸻

How to Compile

Use a C++ compiler such as g++.

Basic compilation:

g++ main.cpp MinHeap.cpp -o scheduler

If needed:

g++ -std=c++11 main.cpp MinHeap.cpp -o scheduler


⸻

How to Run

After compiling, run:

./scheduler

The program will display:
	•	Task insertions
	•	Heap restructuring
	•	Tasks being removed in ascending priority order

⸻

Example Output (Will Vary)

Inserting tasks...
Inserted Task("A", 2)
Inserted Task("B", 5)
Inserted Task("C", 1)

Processing tasks in order:
C (priority 1)
A (priority 2)
B (priority 5)


⸻

Core Components

Task

Represents an individual scheduled job.
	•	Name
	•	Priority
	•	Comparison operators for heap ordering

MinHeap

Implements the min-heap structure.
	•	Insert
	•	DeleteMin
	•	Empty/full checks
	•	ReheapUp and ReheapDown

main.cpp

Demonstrates usage of the MinHeap with sample tasks.

⸻

Potential Extensions

Possible improvements:
	•	Dynamic resizing of the heap array
	•	File-based input/output
	•	Task categories or sub-priorities
	•	Max-Heap variant
	•	Visual diagrams of heap structure

⸻

End of README

Authors: Caleb Kaalund & Landen Harley

⸻

