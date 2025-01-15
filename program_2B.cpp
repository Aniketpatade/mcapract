#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList {
public:
    Node* head;
    SinglyLinkedList() {
        head = NULL;
    }

    void create() {
        int n;
        cout << "Enter number of elements: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            int value;
            cout << "Enter value: ";
            cin >> value;
            insert(value);
        }
    }

    void insert(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void reverse() {
        Node* prev = NULL;
        Node* current = head;
        Node* next = NULL;
        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        cout << "List reversed successfully." << endl;
    }

    void search(int value) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == value) {
                cout << "Element " << value << " found in the list." << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Element " << value << " not found in the list." << endl;
    }

    void count() {
        int count = 0;
        Node* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        cout << "Number of elements in the list: " << count << endl;
    }

    void display() {
        Node* temp = head;
        if (temp == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        cout << "List: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    SinglyLinkedList list;
    int choice;
    do {
        cout << "\nMenu: \n";
        cout << "1. Create\n";
        cout << "2. Reverse\n";
        cout << "3. Search\n";
        cout << "4. Count\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                list.create();
                break;
            case 2:
                list.reverse();
                break;
            case 3:
                int searchValue;
                cout << "Enter value to search: ";
                cin >> searchValue;
                list.search(searchValue);
                break;
            case 4:
                list.count();
                break;
            case 5:
                list.display();
                break;
            case 6:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
