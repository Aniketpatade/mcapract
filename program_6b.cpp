#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Queue class
class LinkedQueue {
private:
    Node* front;
    Node* rear;

public:
    // Constructor
    LinkedQueue() {
        front = rear = nullptr;
    }

    // Enqueue operation
    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (rear == nullptr) { // Queue is empty
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << value << " enqueued into the queue.\n";
    }

    // Dequeue operation
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty. Dequeue operation cannot be performed.\n";
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == nullptr) // Queue becomes empty
            rear = nullptr;

        cout << "Dequeued: " << temp->data << "\n";
        delete temp;
    }

    // Display operation
    void display() {
        if (front == nullptr) {
            cout << "Queue is empty.\n";
            return;
        }

        Node* temp = front;
        cout << "Queue: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor
    ~LinkedQueue() {
        while (front != nullptr) {
            dequeue();
        }
    }
};

// Main function
int main() {
    LinkedQueue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    queue.display();

    queue.dequeue();
    queue.display();

    return 0;
}