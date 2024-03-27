// Write a C++ program to create a class Department which contains data members as
// Dept_Id, Dept_Name, H.O.D., Number_Of_staff. Write necessary member functions to
// a. Accept details from user for ‘n’ departments and write it in a file “Dept.txt”.
// b. Display details of department from a file.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Department {
private:
    string Dept_Id;
    string Dept_Name;
    string HOD;
    int Number_Of_Staff;

public:
    // Constructor
    Department() {}

    // Getters and setters
    string getDeptId() {
        return Dept_Id;
    }

    void setDeptId(string id) {
        Dept_Id = id;
    }

    string getDeptName() {
        return Dept_Name;
    }

    void setDeptName(string name) {
        Dept_Name = name;
    }

    string getHOD() {
        return HOD;
    }

    void setHOD(string hod) {
        HOD = hod;
    }

    int getNumOfStaff() {
        return Number_Of_Staff;
    }

    void setNumOfStaff(int num) {
        Number_Of_Staff = num;
    }

    // Member functions
    void acceptDetails() {
        cout << "Enter department ID: ";
        cin >> Dept_Id;
        cout << "Enter department name: ";
        cin >> Dept_Name;
        cout << "Enter H.O.D.: ";
        cin >> HOD;
        cout << "Enter number of staff: ";
        cin >> Number_Of_Staff;
    }

    void displayDetails() {
        cout << "Department ID: " << Dept_Id << endl;
        cout << "Department name: " << Dept_Name << endl;
        cout << "H.O.D.: " << HOD << endl;
        cout << "Number of staff: " << Number_Of_Staff << endl;
    }

    void writeToFile(ofstream &file) {
        file << Dept_Id << "," << Dept_Name << "," << HOD << "," << Number_Of_Staff << endl;
    }

    void readFromFile(ifstream &file) {
        getline(file, Dept_Id, ',');
        getline(file, Dept_Name, ',');
        getline(file, HOD, ',');
        file >> Number_Of_Staff;
        file.ignore();
    }
};

int main() {
    int n;
    cout << "Enter number of departments: ";
    cin >> n;

    // Accept details from user and write to file
    ofstream outfile("Dept.txt");
    for (int i = 0; i < n; i++) {
        Department dept;
        dept.acceptDetails();
        dept.writeToFile(outfile);
    }
    outfile.close();

    // Read details from file and display
    ifstream infile("Dept.txt");
    while (!infile.eof()) {
        Department dept;
        dept.readFromFile(infile);
        dept.displayDetails();
        cout << endl;
    }
    infile.close();

    return 0;
}
