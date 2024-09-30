//Noran Askar - 900213522 - section 1

#include <iostream>
#include "DEQ.h"
#include "Simulation.h"

using namespace std;

int main() {
    // Create a DEQ of integers
    // This will initialize an empty DEQ that can store integers.
    DEQ<int> deq;

    // Check if DEQ is empty
    // Before adding any elements, let's check if the DEQ is initially empty.
    if (deq.DEQisEmpty()) {
        cout << "DEQ is initially empty." << endl;
    }

    // Add elements to the front and rear
    // We will add elements to both the front and rear of the DEQ to test its functionality.
    deq.Add_Front(10);  // Adding 10 to the front of the DEQ
    deq.Add_Rear(20);   // Adding 20 to the rear of the DEQ
    deq.Add_Front(5);   // Adding 5 to the front of the DEQ
    deq.Add_Rear(25);   // Adding 25 to the rear of the DEQ

    // Display current length
    // Let's check the length of the DEQ after adding the elements.
    cout << "DEQ length after adding elements: " << deq.DEQ_Length() << endl;

    // View front and rear elements
    // We will now view the front and rear elements without removing them.
    cout << "Front element: " << deq.View_Front() << endl;  // Should show 5
    cout << "Rear element: " << deq.View_Rear() << endl;    // Should show 25

    // Remove elements from front and rear
    // Now, we'll remove the elements from both the front and rear of the DEQ.
    deq.Remove_Front();  // Remove the front element (should remove 5)
    deq.Remove_Rear();   // Remove the rear element (should remove 25)

    // View front and rear elements again
    // Let's check the front and rear elements after the removal operations.
    cout << "Front element after removal: " << deq.View_Front() << endl;  // Should show 10
    cout << "Rear element after removal: " << deq.View_Rear() << endl;    // Should show 20

    // Final DEQ length
    // Check the DEQ length after removing some elements.
    cout << "DEQ length after removals: " << deq.DEQ_Length() << endl;  // Should show 2

    // Remove all remaining elements
    // Remove the remaining two elements (10 and 20) to make the DEQ empty.
    deq.Remove_Front();  // Remove the front element (10)
    deq.Remove_Rear();   // Remove the rear element (20)

    // Check if DEQ is empty again
    // After removing all elements, the DEQ should be empty.
    if (deq.DEQisEmpty()) {
        cout << "DEQ is empty after removing all elements." << endl;
    }

    /* ----------------------------------------------------------------- */

    // Initialize the simulation with the following parameters:
    // Tmax = 360 minutes (6 hours of simulation time)
    // Ts = 10 minutes (each plane takes 10 minutes to land)
    // DeltaT = 6 minutes (average time between plane arrivals)
    const int Tmax = 360;  // Simulation time of 6 hours (360 minutes)
    const int Ts = 10;     // Service time of 10 minutes for a plane to land
    const int DeltaT = 6;  // Average time between plane arrivals is 6 minutes

    // Create and run the simulation
    // Initialize the Simulation class with the above parameters and run it.
    Simulation simulation(Tmax, Ts, DeltaT);  // Initialize the simulation
    simulation.run();  // Run the simulation

    return 0;
}