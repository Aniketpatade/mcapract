#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Head pointer for the linked list
Node* head = NULL;

// Function to create/insert a new node at the end
void create(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode; // If list is empty, set head to new node
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next; // Traverse to the end of the list
        }
        temp->next = newNode; // Append new node
    }
    cout << "Node with value " << value << " created successfully.\n";
}

// Function to insert a node at a specific position
void insert(int value, int position) {
    Node* newNode = new Node();
    newNode->data = value;

    if (position == 1) {
        newNode->next = head;
        head = newNode; // Insert at the beginning
    } else {
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp != NULL; i++) {
            temp = temp->next; // Traverse to the desired position
        }
        if (temp != NULL) {
            newNode->next = temp->next;
            temp->next = newNode; // Insert the node at the specified position
        } else {
            cout << "Invalid position!\n";
            delete newNode;
            return;
        }
    }
    cout << "Node with value " << value << " inserted at position " << position << ".\n";
}

// Function to delete a node at a specific position
void deleteNode(int position) {
    if (head == NULL) {
        cout << "The list is empty. Deletion not possible.\n";
        return;
    }

    Node* temp = head;

    if (position == 1) {
        head = head->next; // Delete the head node
        delete temp;
    } else {
        Node* prev = NULL;
        for (int i = 1; i < position && temp != NULL; i++) {
            prev = temp;
            temp = temp->next; // Traverse to the node to be deleted
        }
        if (temp != NULL) {
            prev->next = temp->next; // Unlink the node
            delete temp;
        } else {
            cout << "Invalid position!\n";
            return;
        }
    }
    cout << "Node at position " << position << " deleted successfully.\n";
}

// Function to display the linked list
void display() {
    if (head == NULL) {
        cout << "The list is empty.\n";
        return;
    }

    Node* temp = head;
    cout << "Singly Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int choice, value, position;

    do {
        cout << "\nMenu:\n";
        cout << "1. Create (Add Node at End)\n";
        cout << "2. Insert at Specific Position\n";
        cout << "3. Delete Node\n";
        cout << "4. Display List\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to create: ";
                cin >> value;
                create(value);
                break;
            case 2:
                cout << "Enter value and position to insert: ";
                cin >> value >> position;
                insert(value, position);
                break;
            case 3:
                cout << "Enter position to delete: ";
                cin >> position;
                deleteNode(position);
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
