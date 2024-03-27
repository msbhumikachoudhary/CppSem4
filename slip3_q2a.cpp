// Write a C++ program with Student as abstract class and create derive classes Engineering,
// Medicine and Science having data member rollno and name from base class Student. Create
// objects of the derived classes and access them using array of pointer of base class Student.
#include <iostream>
#include <string>
using namespace std;

// Abstract base class
class Student {
public:
    virtual void display() = 0; // pure virtual function
protected:
    int rollno;
    string name;
};

// Derived class Engineering
class Engineering : public Student {
public:
    Engineering(int r, string n) {
        rollno = r;
        name = n;
    }
    void display() {
        cout << "Engineering Student - Roll No: " << rollno << ", Name: " << name << endl;
    }
};

// Derived class Medicine
class Medicine : public Student {
public:
    Medicine(int r, string n) {
        rollno = r;
        name = n;
    }
    void display() {
        cout << "Medicine Student - Roll No: " << rollno << ", Name: " << name << endl;
    }
};

// Derived class Science
class Science : public Student {
public:
    Science(int r, string n) {
        rollno = r;
        name = n;
    }
    void display() {
        cout << "Science Student - Roll No: " << rollno << ", Name: " << name << endl;
    }
};

int main(void) {
    const int numStud = 3;
    Student* students[numStud]; // array of pointers to Student objects
    students[0] = new Engineering(101, "Mahesh");
    students[1] = new Medicine(102, "Akshay");
    students[2] = new Science(103, "Ketan");

    // Display student info using polymorphism
    for (int i = 0; i < numStud; i++) {
        students[i]->display();
    }

    // Free dynamically allocated memory
    for (int i = 0; i < numStud; i++) {
        delete students[i];
    }
}
