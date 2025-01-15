#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() : head(NULL) {}

    void insertAtBeginning(int value) {
        Node* newNode = new Node{value, NULL, head};
        if (head != NULL) head->prev = newNode;
        head = newNode;
        cout << "Inserted " << value << " at the beginning.\n";
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node{value, NULL, NULL};
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        cout << "Inserted " << value << " at the end.\n";
    }

    void deleteNode(int value) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        while (temp != NULL && temp->data != value) temp = temp->next;
        if (temp == NULL) {
            cout << "Node with value " << value << " not found.\n";
            return;
        }
        if (temp->prev != NULL) temp->prev->next = temp->next;
        else head = temp->next;  // Deleting the head node
        if (temp->next != NULL) temp->next->prev = temp->prev;
        delete temp;
        cout << "Deleted node with value " << value << ".\n";
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "List contents: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    DoublyLinkedList list;
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Delete Node\n4. Display List\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            list.insertAtBeginning(value);
            break;
        case 2:
            cout << "Enter value to insert: ";
            cin >> value;
            list.insertAtEnd(value);
            break;
        case 3:
            cout << "Enter value to delete: ";
            cin >> value;
            list.deleteNode(value);
            break;
        case 4:
            list.display();
            break;
        case 5:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
