#include <iostream>
#include <cmath>
using namespace std;

class Quadratic {
private:
    double a, b, c;

public:
    // Default constructor
    Quadratic() : a(0), b(0), c(0) {}

    // Parameterized constructor
    Quadratic(double a, double b, double c) : a(a), b(b), c(c) {}

    // Overload + operator to add two quadratic polynomials
    Quadratic operator+(const Quadratic &q) {
        return Quadratic(a + q.a, b + q.b, c + q.c);
    }

    // Overload >> operator for input
    friend istream &operator>>(istream &in, Quadratic &q) {
        cout << "Enter coefficient of x^2 (a): ";
        in >> q.a;
        cout << "Enter coefficient of x (b): ";
        in >> q.b;
        cout << "Enter constant term (c): ";
        in >> q.c;
        return in;
    }

    // Overload << operator for output
    friend ostream &operator<<(ostream &out, const Quadratic &q) {
        out << q.a << "x^2 + " << q.b << "x + " << q.c;
        return out;
    }

    // Function to evaluate the polynomial for a given value of x
    double eval(double x) {
        return (a * x * x + b * x + c);
    }

    // Function to compute the roots of the polynomial
    void findRoots() {
        if (a == 0) {
            cout << "Not a quadratic equation." << endl;
            return;
        }

        double discriminant = b * b - 4 * a * c;

        if (discriminant > 0) {
            double root1 = (-b + sqrt(discriminant)) / (2 * a);
            double root2 = (-b - sqrt(discriminant)) / (2 * a);
            cout << "Roots are real and distinct: " << root1 << " and " << root2 << endl;
        } else if (discriminant == 0) {
            double root = -b / (2 * a);
            cout << "Roots are real and equal: " << root << endl;
        } else {
            cout << "Roots are complex and imaginary." << endl;
        }
    }
};

int main() {
    Quadratic q1, q2, sum;
    double x;

    // Input two quadratic polynomials
    cout << "Enter first quadratic polynomial:" << endl;
    cin >> q1;
    cout << "Enter second quadratic polynomial:" << endl;
    cin >> q2;

    // Add the polynomials
    sum = q1 + q2;

    // Display the result of addition
    cout << "\nSum of polynomials: " << sum << endl;

    // Evaluate the polynomial for a given value of x
    cout << "\nEnter a value for x: ";
    cin >> x;
    cout << "Value of first polynomial at x = " << x << " is: " << q1.eval(x) << endl;

    // Find roots of the first polynomial
    cout << "\nRoots of the first polynomial:" << endl;
    q1.findRoots();

    return 0;
}