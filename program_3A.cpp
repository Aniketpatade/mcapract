#include <iostream>
using namespace std;

// Define the Node structure for doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;
    
    Node(int val) : data(val), next(NULL), prev(NULL) {}
};

// Function to insert a node at the end of the doubly linked list
void insert(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to print the doubly linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to sort the doubly linked list using pointer manipulation
void sortList(Node*& head) {
    if (!head || !head->next) return; // No need to sort if the list is empty or has one element
    
    bool swapped;
    Node* ptr1;
    Node* ptr2 = NULL;
    
    do {
        swapped = false;
        ptr1 = head;
        
        while (ptr1->next != ptr2) {
            if (ptr1->data > ptr1->next->data) {
                // Swap data
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        ptr2 = ptr1;
    } while (swapped);
}

// Function to merge two sorted doubly linked lists
Node* mergeLists(Node* head1, Node* head2) {
    if (!head1) return head2;
    if (!head2) return head1;
    
    // Start with the smaller node
    if (head1->data < head2->data) {
        head1->next = mergeLists(head1->next, head2);
        head1->next->prev = head1;
        head1->prev = NULL;
        return head1;
    } else {
        head2->next = mergeLists(head1, head2->next);
        head2->next->prev = head2;
        head2->prev = NULL;
        return head2;
    }
}

int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;
    
    // Inserting elements into the first list
    insert(list1, 3);
    insert(list1, 1);
    insert(list1, 4);
    insert(list1, 2);
    
    // Inserting elements into the second list
    insert(list2, 8);
    insert(list2, 6);
    insert(list2, 7);
    insert(list2, 5);
    
    cout << "Original List 1: ";
    printList(list1);
    cout << "Original List 2: ";
    printList(list2);
    
    // Sorting both lists
    sortList(list1);
    sortList(list2);
    
    cout << "Sorted List 1: ";
    printList(list1);
    cout << "Sorted List 2: ";
    printList(list2);
    
    // Merging both sorted lists
    Node* mergedList = mergeLists(list1, list2);
    
    cout << "Merged Sorted List: ";
    printList(mergedList);
    
    return 0;
}
