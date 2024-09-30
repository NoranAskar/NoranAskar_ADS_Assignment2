//Noran Askar - 900213522 - section 1

#include "Plane.h"

using namespace std;

// This is a ready implementation of the Plane class.
// You do not need to modify this file.

Plane::Plane(int arrivalTime, int priority)
        : arrivalTime(arrivalTime), priority(priority) {
    // empty constructor body
}

ostream& operator<<(ostream& os, const Plane& plane) {
    os << "The plane with priority " << plane.priority << " has arrived at " << plane.arrivalTime;
    return os;
}