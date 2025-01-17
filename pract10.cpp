#include <iostream>
using namespace std;

// Base class
class Converter {
protected:
    double val1, val2;
public:
    void getinit(double v) {
        val1 = v;
    }
    double getconv() {
        return val2;
    }
    virtual void convert() = 0; // Pure virtual function
};

// Derived class to convert meters to kilometers
class MetersToKilometers : public Converter {
public:
    void convert() override {
        val2 = val1 / 1000;
    }
};

// Derived class to convert Celsius to Fahrenheit
class CelsiusToFahrenheit : public Converter {
public:
    void convert() override {
        val2 = (val1 * 9 / 5) + 32;
    }
};

int main() {
    Converter* conv;

    // Convert meters to kilometers
    MetersToKilometers mToKm;
    conv = &mToKm;
    conv->getinit(5000);
    conv->convert();
    cout << "Meters to Kilometers: " << conv->getconv() << " km" << endl;

    // Convert Celsius to Fahrenheit
    CelsiusToFahrenheit cToF;
    conv = &cToF;
    conv->getinit(25);
    conv->convert();
    cout << "Celsius to Fahrenheit: " << conv->getconv() << " °F" << endl;

    return 0;
}
