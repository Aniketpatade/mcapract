#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // Default constructor
    Complex() : real(0), imag(0) {}

    // Parameterized constructor (optional, for initialization)
    Complex(double r, double i) : real(r), imag(i) {}

    // Overload + operator to add two complex numbers
    Complex operator+(const Complex &other) {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload * operator to multiply two complex numbers
    Complex operator*(const Complex &other) {
        return Complex((real * other.real - imag * other.imag),
                       (real * other.imag + imag * other.real));
    }

    // Overload >> operator for input
    friend istream &operator>>(istream &in, Complex &c) {
        cout << "Enter real part: ";
        in >> c.real;
        cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }

    // Overload << operator for output
    friend ostream &operator<<(ostream &out, const Complex &c) {
        out << c.real << " + " << c.imag << "i";
        return out;
    }
};

int main() {
    Complex c1, c2, sum, product;

    // Input two complex numbers
    cout << "Enter first complex number:" << endl;
    cin >> c1;
    cout << "Enter second complex number:" << endl;
    cin >> c2;

    // Perform addition and multiplication
    sum = c1 + c2;
    product = c1 * c2;

    // Display the results
    cout << "\nFirst Complex Number: " << c1 << endl;
    cout << "Second Complex Number: " << c2 << endl;
    cout << "Sum: " << sum << endl;
    cout << "Product: " << product << endl;

    return 0;
}