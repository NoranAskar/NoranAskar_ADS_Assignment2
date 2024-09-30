//Noran Askar - 900213522 - section 1

#ifndef PLANE_H
#define PLANE_H

#include <iostream>

using namespace std;
class Plane {
public:
    int arrivalTime;  // The time the plane arrives in the queue
    int priority;     // Priority of the plane (0 = low, 1 = medium, 2 = high)

    Plane(int arrivalTime, int priority);

    // Overload << operator to easily print a plane's information
    friend ostream& operator<<(ostream& os, const Plane& plane);
};

#endif