//Noran Askar - 900213522 - section 1

#ifndef SIMULATION_H
#define SIMULATION_H

#include "DEQ.h"
#include "Plane.h"
#include <vector>

using namespace std;

class Simulation {
private:
    int Tmax;     // Total simulation time
    int Ts;       // Service time (time for a plane to land)
    int DeltaT;   // Average inter-arrival time
    DEQ<Plane> queue;  // DEQ to hold planes waiting to land
    vector<int> waitTimes;  // Stores wait times for planes

public:
    Simulation(int Tmax, int Ts, int DeltaT);

    // Run the simulation
    void run();

    // Enqueue a plane into the queue based on its priority
    void enqueuePlane(const Plane& plane);

    // Simulate landing of planes
    void processLanding(int currentTime);

    // Calculate and print the average wait time
    void printAverageWaitTime() const;

private:
    // Generates a random priority (0 = low, 1 = medium, 2 = high)
    int generateRandomPriority();

    // Generates the time for the next plane's arrival
    int generateNextArrivalTime();
};

#endif