#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    string classDivision;
    string dob;
    string bloodGroup;
    string contactAddress;
    string telephoneNumber;
    string drivingLicenseNumber;

public:
    // Constructor to initialize the student details
    Student() {
        name = "";
        rollNumber = 0;
        classDivision = "";
        dob = "";
        bloodGroup = "";
        contactAddress = "";
        telephoneNumber = "";
        drivingLicenseNumber = "";
    }

    // Function to input student details
    void inputDetails() {
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cin.ignore();  // To consume the newline character
        cout << "Enter Class and Division: ";
        getline(cin, classDivision);
        cout << "Enter Date of Birth (DD/MM/YYYY): ";
        getline(cin, dob);
        cout << "Enter Blood Group: ";
        getline(cin, bloodGroup);
        cout << "Enter Contact Address: ";
        getline(cin, contactAddress);
        cout << "Enter Telephone Number: ";
        getline(cin, telephoneNumber);
        cout << "Enter Driving License Number: ";
        getline(cin, drivingLicenseNumber);
    }

    // Function to display student details
    void displayDetails() const {
        cout << "\nName: " << name;
        cout << "\nRoll Number: " << rollNumber;
        cout << "\nClass and Division: " << classDivision;
        cout << "\nDate of Birth: " << dob;
        cout << "\nBlood Group: " << bloodGroup;
        cout << "\nContact Address: " << contactAddress;
        cout << "\nTelephone Number: " << telephoneNumber;
        cout << "\nDriving License Number: " << drivingLicenseNumber << endl;
    }

    // Destructor
    ~Student() {
        cout << "\nDestructor called for " << name << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;
    cin.ignore();  // To consume the newline character

    // Create an array of student objects dynamically
    Student *students = new Student[n];

    for (int i = 0; i < n; ++i) {
        cout << "\nEnter details of student " << i + 1 << ":\n";
        students[i].inputDetails();
    }

    cout << "\nDisplaying Student Records:\n";
    for (int i = 0; i < n; ++i) {
        cout << "\nStudent " << i + 1 << ":";
        students[i].displayDetails();
    }

    // Deallocate memory
    delete[] students;

    return 0;
}