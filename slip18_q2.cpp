// Write a C++ program to read student information such as rollno, name and percentage of n
// students. Write the student information using file handling.
#include <iostream>
#include <fstream>
using namespace std;

int main(void) {
    int n, rollno;
    string name;
    double percentage;
    ofstream file("students.txt");

    if (!file.is_open()) {
        cout << "Error: Could not open file.\n";
        return 1;
    }

    cout << "Enter the number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter student " << i + 1 << " details:\n";
        cout << "Roll No.: ";
        cin >> rollno;
        cout << "Name: ";
        cin >> name;
        cout << "Percentage: ";
        cin >> percentage;

        file << rollno << "\t" << name << "\t" << percentage << "\n";
    }

    file.close();
    cout << "\nStudent information saved to file.\n";
}