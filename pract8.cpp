#include <iostream>
#include <string>
#include<stdexcept>
using namespace std;

// Base Class: Publication
class Publication {
protected:
    string title;
    float price;

public:
    Publication() : title(""), price(0.0) {}

    virtual void getData() {
        try {
            cout << "Enter title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter price: ";
            cin >> price;
            if (price <= 0) {
                throw invalid_argument("Price must be positive.");
            }
        } catch (invalid_argument &e) {
            cout << "Invalid input: " << e.what() << endl;
            title = "";
            price = 0.0;
        }
    }

    virtual void display() const {
        cout << "Title: " << title << ", Price: " << price << endl;
    }
};

// Derived Class: Book
class Book : public Publication {
private:
    int pageCount;

public:
    Book() : Publication(), pageCount(0) {}

    void getData() override {
        Publication::getData();
        try {
            cout << "Enter page count: ";
            cin >> pageCount;
            if (pageCount <= 0) {
                throw invalid_argument("Page count must be positive.");
            }
        } catch (invalid_argument &e) {
            cout << "Invalid input: " << e.what() << endl;
            pageCount = 0;
        }
    }

    void display() const override {
        Publication::display();
        cout << "Page Count: " << pageCount << endl;
    }
};

// Derived Class: Type
class Type : public Publication {
private:
    float playingTime;

public:
    Type() : Publication(), playingTime(0.0) {}

    void getData() override {
        Publication::getData();
        try {
            cout << "Enter playing time (in minutes): ";
            cin >> playingTime;
            if (playingTime <= 0) {
                throw invalid_argument("Playing time must be positive.");
            }
        } catch (invalid_argument &e) {
            cout << "Invalid input: " << e.what() << endl;
            playingTime = 0.0;
        }
    }

    void display() const override {
        Publication::display();
        cout << "Playing Time: " << playingTime << " minutes" << endl;
    }
};

int main() {
    Book book;
    Type type;

    cout << "Enter data for Book:\n";
    book.getData();

    cout << "\nEnter data for Audio Type:\n";
    type.getData();

    cout << "\nDisplaying Book Data:\n";
    book.display();

    cout << "\nDisplaying Audio Type Data:\n";
    type.display();

    return 0;
}
