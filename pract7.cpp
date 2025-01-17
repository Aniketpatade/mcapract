#include <iostream>
#include <algorithm>  // For std::gcd
using namespace std;

class Rational {
private:
    int numerator;
    int denominator;

    void simplify() {
        int gcd = __gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    // Constructor
    Rational(int num, int den) {
        if (den == 0) {
            cerr << "Error: Denominator cannot be zero!" << endl;
            exit(EXIT_FAILURE);
        }
        numerator = num;
        denominator = den;
        simplify();
    }

    // Overload addition operator
    Rational operator+(const Rational& other) {
        return Rational(numerator * other.denominator + other.numerator * denominator,
                        denominator * other.denominator);
    }

    // Overload subtraction operator
    Rational operator-(const Rational& other) {
        return Rational(numerator * other.denominator - other.numerator * denominator,
                        denominator * other.denominator);
    }

    // Overload multiplication operator
    Rational operator*(const Rational& other) {
        return Rational(numerator * other.numerator, denominator * other.denominator);
    }

    // Overload division operator
    Rational operator/(const Rational& other) {
        return Rational(numerator * other.denominator, denominator * other.numerator);
    }

    // Overload equality operator
    bool operator==(const Rational& other) {
        return (numerator == other.numerator) && (denominator == other.denominator);
    }

    // Display function
    void display() const {
        cout << numerator << "/" << denominator << endl;
    }
};

int main() {
    Rational r1(3, 4);
    Rational r2(5, 6);

    cout << "First Fraction: ";
    r1.display();
    cout << "Second Fraction: ";
    r2.display();

    Rational sum = r1 + r2;
    cout << "Sum: ";
    sum.display();

    Rational diff = r1 - r2;
    cout << "Difference: ";
    diff.display();

    Rational prod = r1 * r2;
    cout << "Product: ";
    prod.display();

    Rational quot = r1 / r2;
    cout << "Quotient: ";
    quot.display();

    return 0;
}
