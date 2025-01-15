#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = NULL;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void deleteFromBeginning() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        if (head->next == head) {
            delete head;
            head = NULL;
        } else {
            Node* temp = head;
            Node* last = head;
            while (last->next != head)
                last = last->next;
            last->next = head->next;
            head = head->next;
            delete temp;
        }
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);

    cout << "List after insertion: ";
    list.display();

    list.deleteFromBeginning();
    cout << "List after deletion: ";
    list.display();

    return 0;
}
