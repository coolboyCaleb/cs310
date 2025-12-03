#include <iostream>

#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// customer type definition
struct Customer {
    string firstName;
    string lastName;
    int ticketNumber;
    int priority;
    int waitTime;
    
    // constructor
    Customer(string first = "", string last = "", int ticket = 0) {
        firstName = first;
        lastName = last;
        ticketNumber = ticket;
        priority = firstName.length() + lastName.length();
        waitTime = 0;
    }
};

// use int (priority) as ItemType for the heap
typedef int ItemType;
#include "PQType.h"

int main() {
    // seed random number generator
    srand(time(0));
    
    // read roster.txt
    ifstream rosterFile("roster.txt");
    if (!rosterFile.is_open()) {
        cerr << "Error: Could not open roster.txt" << endl;
        return 1;
    }
    
    string roster[30];
    int rosterCount = 0;
    string line;
    while (getline(rosterFile, line) && rosterCount < 30) {
        if (!line.empty()) {
            roster[rosterCount] = line;
            rosterCount++;
        }
    }
    rosterFile.close();
    
    if (rosterCount < 30) {
        cerr << "Warning: Only " << rosterCount << " names found in roster.txt" << endl;
    }
    
    // create priority queue (stores priority values as int)
    PQType<int> queue(1000);
    
    // parallel arrays to store customer data indexed by ticket number
    Customer customerData[10000];
    bool inQueue[10000] = {false};
    
    // array to store served customers (max 200)
    Customer servedCustomers[200];
    int servedCount = 0;
    int ticketCounter = 1;
    int initialCustomersEnqueued = 0;
    
    // simulation loop: enqueue initial 10 customers, then continue until 200 customers have been served
    while (servedCount < 200) {
        // first, enqueue 10 initial customers before store opens
        if (initialCustomersEnqueued < 10) {
            int randomIndex = rand() % rosterCount;
            string fullName = roster[randomIndex];
            size_t spacePos = fullName.find(' ');
            string firstName = fullName.substr(0, spacePos);
            string lastName = fullName.substr(spacePos + 1);
            Customer customer(firstName, lastName, ticketCounter);
            customerData[ticketCounter] = customer;
            inQueue[ticketCounter] = true;
            try {
                queue.Enqueue(customer.priority);
                ticketCounter++;
                initialCustomersEnqueued++;
            } catch (FullPQ) {
                cerr << "Error: Queue is full during initial setup" << endl;
                return 1;
            }
        } else {
            // normal simulation: 60% new arrival, 40% serve
            int randomValue = rand() % 100;
            
            if (randomValue < 60) {
                // 60% probability: new customer arrives
                int randomIndex = rand() % rosterCount;
                string fullName = roster[randomIndex];
                size_t spacePos = fullName.find(' ');
                string firstName = fullName.substr(0, spacePos);
                string lastName = fullName.substr(spacePos + 1);
                Customer customer(firstName, lastName, ticketCounter);
                customerData[ticketCounter] = customer;
                inQueue[ticketCounter] = true;
                try {
                    queue.Enqueue(customer.priority);
                    ticketCounter++;
                } catch (FullPQ) {
                    // queue is full, skip this arrival
                    cerr << "Warning: Queue is full, skipping customer arrival" << endl;
                }
            } else {
                // 40% probability: serve customer (if queue is not empty)
                if (!queue.IsEmpty()) {
                    try {
                        int priority;
                        queue.Dequeue(priority);
                        // find customer with this priority that's still in queue
                        bool found = false;
                        for (int t = 1; t < ticketCounter && !found; t++) {
                            if (inQueue[t] && customerData[t].priority == priority) {
                                customerData[t].waitTime = ticketCounter - customerData[t].ticketNumber;
                                servedCustomers[servedCount] = customerData[t];
                                inQueue[t] = false;
                                servedCount++;
                                found = true;
                            }
                        }
                        if (!found) {
                            cerr << "Warning: Could not find customer with priority " << priority << endl;
                        }
                    } catch (EmptyPQ) {
                        // queue is empty, nothing to serve
                    }
                }
            }
        }
    }
    
    // print all results to console
    cout << "Simulation complete. 200 customers served." << endl;
    cout << endl << "Served customers (in order served):" << endl;
    for (int i = 0; i < servedCount; i++) {
        cout << servedCustomers[i].firstName << " " 
             << servedCustomers[i].lastName << " " 
             << servedCustomers[i].waitTime << endl;
    }
    
    // sort by wait time (ascending) and print
    Customer sortedCustomers[200];
    for (int i = 0; i < servedCount; i++) {
        sortedCustomers[i] = servedCustomers[i];
    }
    
    // simple selection sort
    for (int i = 0; i < servedCount; i++) {
        int minIndex = i;
        for (int j = i + 1; j < servedCount; j++) {
            if (sortedCustomers[j].waitTime < sortedCustomers[minIndex].waitTime) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            Customer temp = sortedCustomers[i];
            sortedCustomers[i] = sortedCustomers[minIndex];
            sortedCustomers[minIndex] = temp;
        }
    }
    
    cout << endl << "Served customers (sorted by wait time, fastest to slowest):" << endl;
    for (int i = 0; i < servedCount; i++) {
        cout << sortedCustomers[i].firstName << " " 
             << sortedCustomers[i].lastName << " " 
             << sortedCustomers[i].waitTime << endl;
    }
    
    return 0;
}
