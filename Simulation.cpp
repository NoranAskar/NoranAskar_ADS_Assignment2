//Noran Askar - 900213522 - section 1

#include "Simulation.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Student Task: Implement the Simulation constructor
// Constructor: Initializes the simulation with given time parameters (Tmax, Ts, DeltaT).
// Here, DeltaT is the average inter-arrival time between planes, Ts is the time it takes
// for a plane to land, and Tmax is the total time for the simulation.
//
// Task: Set the class variables Tmax, Ts, and DeltaT using the constructor parameters.
// Also, initialize the random number generator using the `srand` function and the current time.
Simulation::Simulation(int Tmax, int Ts, int DeltaT)
        : Tmax(Tmax), Ts(Ts), DeltaT(DeltaT) {
    // Student Task: Implement the constructor
    // TODO: Initialize the random number generator using `srand`.
    // This will ensure random behavior for plane arrival times and priorities.
    // Tip: Use `srand((unsigned) time(0));` to initialize the RNG based on the system clock.
    srand(static_cast<unsigned int>(time(0)));
}

// Student Task: Implement the run function
// Function: run()
// This function is the main driver of the simulation, where you will simulate planes arriving,
// waiting, and landing based on their priority.
//
// Key steps:
// 1. Track the current time in the simulation.
// 2. Generate a random time for the next plane to arrive using the `generateNextArrivalTime()` function.
// 3. At every simulation step (minute), check if a new plane arrives. If yes, generate a plane with
//    a random priority and add it to the queue using `enqueuePlane()`.
// 4. Every `Ts` minutes, process the landing of a plane by calling `processLanding()`.
// 5. When the simulation ends, print the average wait time using `printAverageWaitTime()`.
//
// Task: Implement the simulation loop that processes plane arrivals and landings.
void Simulation::run() {
    // Student Task: Implement the run function
    // TODO: Initialize a variable `currentTime` to track the current time of the simulation.
    // TODO: Use `generateNextArrivalTime()` to determine when the next plane arrives.

    // TODO: Write a loop that runs until `currentTime` reaches `Tmax` (total simulation time).
    // Inside the loop:
    // 1. Check if the current time equals the next plane's arrival time.
    //    If so, generate a plane with a random priority (using `generateRandomPriority()`)
    //    and add it to the queue with `enqueuePlane()`.
    // 2. Every `Ts` minutes (landing interval), check if a plane can land using `processLanding()`.
    // 3. Increment the current time by 1 minute for each loop iteration.

    // TODO: After the loop ends, call `printAverageWaitTime()` to display the average wait time.

    int currentTime = 0;
    int planeTime = generateNextArrivalTime();
    while(currentTime < Tmax) {
        cout << "Arrival Time: " << planeTime << endl;
        cout << "Current time is: " << currentTime << endl;
        if(currentTime == planeTime) {
            cout << "Current time is plane time." << endl;
            int priority = generateRandomPriority();
            cout << "Priority: " << priority << endl;
            Plane plane(planeTime, priority);
            enqueuePlane(plane);
            planeTime = currentTime + generateNextArrivalTime();
        }
        if(currentTime % Ts == 0) {
            cout << "Current time is landing time." << endl;
            processLanding(currentTime);
        }
        currentTime++;
    }
    printAverageWaitTime();
}

// Student Task: Implement the enqueuePlane function
// Function: enqueuePlane(const Plane& plane)
// This function is responsible for adding planes to the queue based on their priority.
// Planes with higher priority (2 being the highest) should be placed closer to the front of the queue.
//
// Key steps:
// 1. If the queue is empty, simply add the plane to the front.
// 2. If the queue is not empty, traverse the queue and find the correct position for the plane
//    based on its priority. Planes with higher priority should come first.
// 3. Insert the plane at the appropriate position and ensure the queue maintains its order.
//
// Task: Implement the logic to correctly enqueue the plane based on its priority.
void Simulation::enqueuePlane(const Plane& plane) {
    // Student Task: Implement the enqueuePlane function
    // TODO: If the queue is empty, add the plane to the front.

    // TODO: If the queue is not empty, traverse through the queue and find the correct spot for
    // the plane based on its priority (higher priorities come first).
    // 1. Use a temporary queue to store planes while finding the right spot.
    // 2. Insert the plane once the correct position is found.
    // 3. Restore the planes in the correct order.
    if(queue.DEQisEmpty()) {
        queue.Add_Front(plane);
    }
    else {
        bool planeAdded = false;
        DEQ<Plane> tempQueue;
        while(!queue.DEQisEmpty()) {
            Plane frontPlane = queue.View_Front();
            queue.Remove_Front();
            if(!planeAdded && plane.priority > frontPlane.priority) {
                tempQueue.Add_Rear(plane);
                planeAdded = true;
            }
            tempQueue.Add_Rear(frontPlane);
        }
        if(!planeAdded) {
            tempQueue.Add_Rear(plane);
        }
        while(!tempQueue.DEQisEmpty()) {
            queue.Add_Rear(tempQueue.View_Front());
            tempQueue.Remove_Front();
        }
    }
}

// Student Task: Implement the processLanding function
// Function: processLanding(int currentTime)
// This function is responsible for simulating the landing of a plane. When a plane lands,
// we need to calculate how long it has waited in the queue.
//
// Key steps:
// 1. Remove the plane at the front of the queue (this will be the plane that has waited the longest).
// 2. Calculate the plane's wait time by subtracting its arrival time from the current time.
// 3. Store the wait time in the `waitTimes` vector for future analysis.
// 4. Print a message showing which plane landed and how long it waited.
//
// Task: Implement the logic to process the landing of a plane and calculate its wait time.
void Simulation::processLanding(int currentTime) {
    // Student Task: Implement the processLanding function
    // TODO: Remove the plane at the front of the queue (using `Remove_Front()`).
    // This will be the plane that has waited the longest.

    // TODO: Calculate the plane's wait time by subtracting the plane's `arrivalTime` from `currentTime`.

    // TODO: Store the calculated wait time in the `waitTimes` vector.

    // TODO: Print a message that the plane has landed and how long it waited in the queue.
    if(queue.DEQisEmpty()) {
        //throw runtime_error("No planes in the queue to land."); I'm leaving this here so that you know that I know how to throw a runtime error and that I *chose* to use a normal message instead, as shown in the next line
        cout << "No planes in the queue to land." << endl;  //I made this as a normal output message instead of an error because at the beginning, there's no planes, so it throws the error message and waits for action. To avoid this problem, I printed it out as a message instead.
        return;
    }
    Plane plane = queue.View_Front();
    queue.Remove_Front();
    int waitTime = currentTime - plane.arrivalTime;
    waitTimes.push_back(waitTime);
    cout << "The plane landed with priority " << plane.priority << ", it has been waiting for " << waitTime << " minutes." << endl;
}

// Student Task: Implement the printAverageWaitTime function
// Function: printAverageWaitTime() const
// This function is responsible for calculating and printing the average wait time of all planes that have landed.
//
// Key steps:
// 1. If no planes have landed, print a message indicating that no planes have landed.
// 2. If planes have landed, calculate the total wait time and divide it by the number of planes to get the average.
// 3. Print the average wait time in minutes.
//
// Task: Implement the logic to calculate and print the average wait time.
void Simulation::printAverageWaitTime() const {
    // Student Task: Implement the printAverageWaitTime function
    // TODO: If no planes have landed, print "No planes landed."

    // TODO: If planes have landed, calculate the total wait time by summing the values in the `waitTimes` vector.
    // Divide the total wait time by the number of planes to get the average.

    // TODO: Print the average wait time in minutes.
    if(waitTimes.empty()) {
        cout << "No planes landed." << endl;
    }
    else {
        int total = 0;
        for(int waitTime : waitTimes) {
            total += waitTime;
        }
        int averageWaitTime = total / waitTimes.size();
        cout << "The average wait time is " << averageWaitTime << " minutes." << endl;
    }
}

// Helper Functions
// These functions have already been implemented for you. Use them in your code above.

int Simulation::generateRandomPriority() {
    return rand() % 3;  // Random priority between 0 (low) and 2 (high)
}

int Simulation::generateNextArrivalTime() {
    return DeltaT + (rand() % 3 - 1);  // Adds some variability to DeltaT
}