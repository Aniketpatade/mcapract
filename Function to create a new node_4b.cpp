#include <iostream>
#include <cmath>
using namespace std;

struct Node {
    int coeff;
    int exp;
    Node* next;
};

// Function to create a new node
Node* createNode(int coeff, int exp) {
    Node* newNode = new Node();
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = newNode; // Points to itself
    return newNode;
}

// Insert node in the polynomial list
void insertNode(Node*& poly, int coeff, int exp) {
    Node* newNode = createNode(coeff, exp);
    if (!poly) {
        poly = newNode;
    } else {
        Node* temp = poly;
        while (temp->next != poly)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = poly;
    }
}

// Display the polynomial
void displayPoly(Node* poly) {
    Node* temp = poly;
    do {
        cout << temp->coeff << "x^" << temp->exp;
        temp = temp->next;
        if (temp != poly) cout << " + ";
    } while (temp != poly);
    cout << endl;
}

// Add two polynomials
Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node* temp1 = poly1, *temp2 = poly2;
    do {
        if (temp1->exp == temp2->exp) {
            insertNode(result, temp1->coeff + temp2->coeff, temp1->exp);
            temp1 = temp1->next;
            temp2 = temp2->next;
        } else if (temp1->exp > temp2->exp) {
            insertNode(result, temp1->coeff, temp1->exp);
            temp1 = temp1->next;
        } else {
            insertNode(result, temp2->coeff, temp2->exp);
            temp2 = temp2->next;
        }
    } while (temp1 != poly1 && temp2 != poly2);
    while (temp1 != poly1) {
        insertNode(result, temp1->coeff, temp1->exp);
        temp1 = temp1->next;
    }
    while (temp2 != poly2) {
        insertNode(result, temp2->coeff, temp2->exp);
        temp2 = temp2->next;
    }
    return result;
}

// Evaluate the polynomial
int evaluatePoly(Node* poly, int x) {
    int result = 0;
    Node* temp = poly;
    do {
        result += temp->coeff * pow(x, temp->exp);
        temp = temp->next;
    } while (temp != poly);
    return result;
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;
    Node* result = NULL;

    // Example polynomials
    insertNode(poly1, 3, 2);
    insertNode(poly1, 5, 1);
    insertNode(poly1, 6, 0);

    insertNode(poly2, 4, 1);
    insertNode(poly2, 2, 0);

    cout << "Polynomial 1: ";
    displayPoly(poly1);

    cout << "Polynomial 2: ";
    displayPoly(poly2);

    result = addPolynomials(poly1, poly2);
    cout << "Added Polynomial: ";
    displayPoly(result);

    int x = 2;
    cout << "Value of Polynomial 1 at x = " << x << ": " << evaluatePoly(poly1, x) << endl;

    return 0;
}
