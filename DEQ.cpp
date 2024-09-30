//Noran Askar - 900213522 - section 1

#include "DEQ.h"
#include "Plane.h"
#include <stdexcept>

using namespace std;

// Student Task: Implement the DEQ constructor
// Constructor: initializes an empty DEQ
// In this constructor, you need to initialize the DEQ to be empty.
// This means both the `front` and `rear` pointers should be set to `nullptr`
// and the `length` should be set to 0.
template <typename T>
DEQ<T>::DEQ() : front(nullptr), rear(nullptr), length(0) {
    // Student Task: Implement the DEQ constructor
    // TODO: leave it empty as it is.
}

// Student Task: Implement the DEQ destructor
// Destructor: destroys the DEQ and frees the memory
// This destructor should loop through the entire DEQ and delete all nodes
// to free the memory. Use `Remove_Front` in a loop until the DEQ is empty.
template <typename T>
DEQ<T>::~DEQ() {
    // Student Task: Implement the DEQ destructor
    // TODO: Use a loop to keep calling `Remove_Front()` until the DEQ is empty.
    while(!DEQisEmpty()) {
        Remove_Front();
    }
}

// Student Task: Implement the DEQisEmpty function
// DEQisEmpty: returns true if the DEQ is empty, false otherwise.
// Simply check if the `front` pointer is `nullptr`.
// If `front` is `nullptr`, the DEQ is empty; otherwise, it's not.
template <typename T>
bool DEQ<T>::DEQisEmpty() const {
    // Student Task: Implement the DEQisEmpty function
    // TODO: Return true if `front` is `nullptr`, indicating an empty DEQ.
    return (front == nullptr && rear == nullptr);
}

// Student Task: Implement the Add_Front function
// Add_Front: Adds an element to the front of the DEQ
// 1. Create a new node with the given `value`.
// 2. If the DEQ is empty, set both `front` and `rear` to point to the new node.
// 3. If the DEQ is not empty, adjust pointers so that the new node becomes the new `front`
//    and properly links to the old front node.
// 4. Don't forget to increment the `length` after adding the element.
template <typename T>
void DEQ<T>::Add_Front(const T& value) {
    // Student Task: Implement the Add_Front function
    // TODO: 1. Create a new node for the `value`.
    // TODO: 2. If the DEQ is empty, set `front` and `rear` to the new node.
    // TODO: 3. If the DEQ is not empty, adjust the `front` pointer and link the new node to the old front node.
    // TODO: 4. Increment the `length` of the DEQ.
    Node* newNode = new Node(value);
    if(DEQisEmpty()) {
        front = newNode;
        rear = newNode;
    }
    else {
        newNode -> next = front;
        front -> prev = newNode;
        front = newNode;
    }
    length++;
}

// Student Task: Implement the Add_Rear function
// Add_Rear: Adds an element to the rear of the DEQ
// 1. Create a new node with the given `value`.
// 2. If the DEQ is empty, set both `front` and `rear` to point to the new node.
// 3. If the DEQ is not empty, adjust pointers so that the new node becomes the new `rear`
//    and properly links to the old rear node.
// 4. Don't forget to increment the `length` after adding the element.
template <typename T>
void DEQ<T>::Add_Rear(const T& value) {
    // Student Task: Implement the Add_Rear function
    // TODO: 1. Create a new node for the `value`.
    // TODO: 2. If the DEQ is empty, set `front` and `rear` to the new node.
    // TODO: 3. If the DEQ is not empty, adjust the `rear` pointer and link the new node to the old rear node.
    // TODO: 4. Increment the `length` of the DEQ.
    Node* newNode = new Node(value);
    if(DEQisEmpty()) {
        front = newNode;
        rear = newNode;
    }
    else {
        rear -> next = newNode;
        newNode -> prev = rear;
        rear = newNode;
    }
    length++;
}

// Student Task: Implement the Remove_Front function
// Remove_Front: Removes the front element from the DEQ and returns its value.
// 1. If the DEQ is empty, throw a `runtime_error` indicating that you cannot remove from an empty DEQ.
// 2. Store the value of the `front` node in a temporary variable.
// 3. Adjust the `front` pointer to point to the next node in the list.
// 4. If the DEQ only had one element (i.e., `front == rear`), set both `front` and `rear` to `nullptr`.
// 5. Delete the old front node, decrement the `length`, and return the stored value.
template <typename T>
T DEQ<T>::Remove_Front() {
    // Student Task: Implement the Remove_Front function
    // TODO: 1. If the DEQ is empty, throw a `runtime_error`.
    // TODO: 2. Store the value from the `front` node in a variable.
    // TODO: 3. Adjust the `front` pointer to point to the next node.
    // TODO: 4. If the DEQ only had one element, set `front` and `rear` to `nullptr`.
    // TODO: 5. Delete the old `front` node, decrement `length`, and return the stored value.
    if(DEQisEmpty()) {
        throw runtime_error("The DEQ is empty!");
    }
    Node* tempNode = front;
    T temp = front->data;
    if(front == rear) {
        front = nullptr;
        rear = nullptr;
    }
    else {
        front = front -> next;
        front->prev = nullptr;
    }
    delete tempNode;
    length--;
    return temp;
}

// Student Task: Implement the Remove_Rear function
// Remove_Rear: Removes the rear element from the DEQ and returns its value.
// 1. If the DEQ is empty, throw a `runtime_error` indicating that you cannot remove from an empty DEQ.
// 2. Store the value of the `rear` node in a temporary variable.
// 3. Adjust the `rear` pointer to point to the previous node in the list.
// 4. If the DEQ only had one element (i.e., `front == rear`), set both `front` and `rear` to `nullptr`.
// 5. Delete the old rear node, decrement the `length`, and return the stored value.
template <typename T>
T DEQ<T>::Remove_Rear() {
    // Student Task: Implement the Remove_Rear function
    // TODO: 1. If the DEQ is empty, throw a `runtime_error`.
    // TODO: 2. Store the value from the `rear` node in a variable.
    // TODO: 3. Adjust the `rear` pointer to point to the previous node.
    // TODO: 4. If the DEQ only had one element, set `front` and `rear` to `nullptr`.
    // TODO: 5. Delete the old `rear` node, decrement `length`, and return the stored value.
    if(DEQisEmpty()) {
        throw runtime_error("The DEQ is empty!");
    }
    Node* tempNode = rear;
    T temp = rear -> data;
    if(front == rear) {
        front = nullptr;
        rear = nullptr;
    }
    else {
        rear = rear -> prev;
        rear -> next = nullptr;
    }

    delete tempNode;
    length--;
    return temp;
}

// Student Task: Implement the View_Front function
// View_Front: Retrieves the front element without removing it.
// 1. If the DEQ is empty, throw an `out_of_range` exception to indicate that there is no front element to view.
// 2. Return the value of the `front` node.
template <typename T>
T DEQ<T>::View_Front() const {
    // Student Task: Implement the View_Front function
    // TODO: 1. If the DEQ is empty, throw an `out_of_range` exception.
    // TODO: 2. Return the data from the `front` node without removing it.
    if(DEQisEmpty()) {
        throw out_of_range("The DEQ is empty!");
    }
    return front->data;
}

// Student Task: Implement the View_Rear function
// View_Rear: Retrieves the rear element without removing it.
// 1. If the DEQ is empty, throw an `out_of_range` exception to indicate that there is no rear element to view.
// 2. Return the value of the `rear` node.
template <typename T>
T DEQ<T>::View_Rear() const {
    // Student Task: Implement the View_Rear function
    // TODO: 1. If the DEQ is empty, throw an `out_of_range` exception.
    // TODO: 2. Return the data from the `rear` node without removing it.
    if(DEQisEmpty()) {
        throw out_of_range("The DEQ is empty!");
    }
    return rear->data;
}

// Student Task: Implement the DEQ_Length function
// DEQ_Length: Returns the number of elements in the DEQ.
// Simply return the value of the `length` variable, which tracks the number of elements in the DEQ.
template <typename T>
int DEQ<T>::DEQ_Length() const {
    // Student Task: Implement the DEQ_Length function
    // TODO: Return the `length` of the DEQ.
    return length;
}

// Explicit template instantiation for int and Plane types
template class DEQ<int>;
template class DEQ<Plane>;