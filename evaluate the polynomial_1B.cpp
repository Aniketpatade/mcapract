#include <iostream>
#include <cmath>  // for power function
using namespace std;

// Function to evaluate the polynomial
double evaluatePolynomial(double x, int degree, double coeffs[]) {
    double result = 0.0;
    for (int i = 0; i <= degree; i++) {
        result += coeffs[i] * pow(x, i);  // Calculate term by term
    }
    return result;
}

int main() {
    int degree;
    double x;

    // Ask the user for the degree of the polynomial
    cout << "Enter the degree of the polynomial: ";
    cin >> degree;

    double coeffs[degree + 1];  // Array to hold coefficients

    // Input the value of x for evaluation
    cout << "Enter the value of x: ";
    cin >> x;

    // Input coefficients for the polynomial
    cout << "Enter the coefficients of the polynomial: ";
    for (int i = 0; i <= degree; i++) {
        cin >> coeffs[i];
    }

    // Calculate the result using the evaluatePolynomial function
    double result = evaluatePolynomial(x, degree, coeffs);

    // Display the result
    cout << "The result of the polynomial evaluation is: " << result << endl;

    return 0;
}
