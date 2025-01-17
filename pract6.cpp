#include <iostream>
using namespace std;

// Class template for a generic vector
template <class T>
class Vector {
private:
    T* arr;
    int size;

public:
    // Constructor to create the vector
    void create(int n) {
        size = n;
        arr = new T[size];
        for (int i = 0; i < size; i++) {
            cout << "Enter element " << i + 1 << ": ";
            cin >> arr[i];
        }
    }

    // Function to modify a given element
    void modify(int index, T newValue) {
        if (index >= 0 && index < size) {
            arr[index] = newValue;
        } else {
            cout << "Invalid index!" << endl;
        }
    }

    // Function to multiply all elements by a scalar
    void scalar_multiply(T scalar) {
        for (int i = 0; i < size; i++) {
            arr[i] *= scalar;
        }
    }

    // Function to display the vector elements
    void display() {
        cout << "Vector elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Destructor to free memory
    ~Vector() {
        delete[] arr;
    }
};

// Main function
int main() {
    Vector<int> v;
    int n, index, newValue, scalar;

    cout << "Enter the size of the vector: ";
    cin >> n;

    // Create the vector
    v.create(n);

    // Display the vector
    v.display();

    // Modify a specific element
    cout << "Enter the index to modify: ";
    cin >> index;
    cout << "Enter the new value: ";
    cin >> newValue;
    v.modify(index, newValue);

    // Display after modification
    v.display();

    // Multiply by a scalar
    cout << "Enter a scalar value to multiply the vector: ";
    cin >> scalar;
    v.scalar_multiply(scalar);

    // Display the final vector
    v.display();

    return 0;
}