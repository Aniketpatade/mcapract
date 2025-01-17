#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void countLinesNotStartingWithA() {
    ifstream file("STORY.TXT");
    if (!file) {
        cerr << "Error opening file!" << endl;
        return;
    }

    string line;
    int count = 0;

    while (getline(file, line)) {
        // Check if the line is non-empty and does not start with 'A' or 'a'
        if (!line.empty() && line[0] != 'A' && line[0] != 'a') {
            count++;
        }
    }

    cout << "Number of lines not starting with 'A' or 'a': " << count << endl;
    file.close();
}

int main() {
    countLinesNotStartingWithA();
    return 0;
}