#include <iostream>
using namespace std;

class Capturing {
private:
    int a[10];  // Array to store elements
    int b[10];  // Array for storing the exchanged array
    int n;      // Number of elements

public:
    // Function prototypes
    void get();
    void print();
    void sort();
    void range();
    void exchange();
    int size();
};

// Function to get array input from the user
void Capturing::get() {
    cout << "Enter the limit of array: ";
    cin >> n;

    if (n > 10) {
        cout << "Limit exceeds maximum size (10). Setting limit to 10." << endl;
        n = 10;
    }

    cout << "\nEnter the array elements" << endl;
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "]=";
        cin >> a[i];
    }
}

// Function to print the entered array
void Capturing::print() {
    cout << "\nThe entered array is" << endl;
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "]=" << a[i] << endl;
    }
}

// Function to sort the array in ascending order
void Capturing::sort() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                // Swap a[j] and a[j + 1]
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    cout << "\nThe sorted array is" << endl;
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "]=" << a[i] << endl;
    }
}

// Function to display the range (min and max) of the array
void Capturing::range() {
    int min = a[0], max = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] < min)
            min = a[i];
        if (a[i] > max)
            max = a[i];
    }

    cout << "\nThe range of array is from " << min << " to " << max << endl;
}

// Function to copy elements to array b and display the exchanged array
void Capturing::exchange() {
    for (int i = 0; i < n; i++) {
        b[i] = a[i];
    }

    cout << "The exchanged array is" << endl;
    for (int i = 0; i < n; i++) {
        cout << "b[" << i << "]=" << b[i] << endl;
    }
}

// Function to return the size of the array
int Capturing::size() {
    return n;
}

// Main function to demonstrate the functionalities
int main() {
    Capturing obj;
    obj.get();       // Input array elements
    obj.print();     // Display the entered array

    obj.range();     // Display the range of the array
    obj.exchange();  // Copy and display the exchanged array
    obj.sort();      // Sort and display the array

    cout << "\nSize of the array: " << obj.size() << endl;

    return 0;
}