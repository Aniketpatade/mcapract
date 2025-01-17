#include <iostream>
using namespace std;

int main() {
    char choice;
    do {
        double num1, num2;
        char op;

        // Input first number, operator, and second number
        cout << "Enter first number, operator (+, -, *, /), and second number: ";
        cin >> num1 >> op >> num2;

        // Perform operation based on operator
        switch (op) {
            case '+':
                cout << "Answer = " << num1 + num2 << endl;
                break;
            case '-':
                cout << "Answer = " << num1 - num2 << endl;
                break;
            case '*':
                cout << "Answer = " << num1 * num2 << endl;
                break;
            case '/':
                if (num2 != 0) {
                    cout << "Answer = " << num1 / num2 << endl;
                } else {
                    cout << "Error: Division by zero is not allowed!" << endl;
                }
                break;
            default:
                cout << "Invalid operator! Please enter +, -, *, or /." << endl;
                break;
        }

        // Ask the user if they want to perform another calculation
        cout << "Do another (Y/N)? ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    return 0;
}